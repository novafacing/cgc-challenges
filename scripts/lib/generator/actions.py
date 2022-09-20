import os
import random
import matplotlib
import sys

if 'matplotlib.backends' not in sys.modules:
    matplotlib.use('Agg')

import matplotlib.pyplot as plt
import matplotlib.ticker
import numpy
import sys
import random
import string
import sys
import argparse
import imp
import os
import random
import yaml
import struct
import zipfile
from xml.etree import ElementTree
from codecs import escape_decode

from Crypto.Cipher import AES


class Graph(object):
    """ Graph -  Throw - Perform the interactions with a CB
    This class implements the graph implementation and traversal functionality
    of generate-poll.
    Usage:
        a = Graph()
        a.add_node('foo', method_that_implements_foo)
        a.add_node('bar', method_that_implements_bar)
        a.add_edge('foo', 'bar')
        a.walk()
    Attributes:
        max_depth: Maximum number of edges to traverse
        start: Which node to start traversal of the graph
    """
    def __init__(self):
        self._depth = 0
        self._neighbors = {}
        self._nodes = {}
        self.max_depth = 0xFFFFF
        self.start = None
        self.finish = None

    def add_node(self, name, node, chance=1.0, continue_chance=1.0):
        """ Add a node to the graph
        If the node name is 'start', it will always be executed first in the
        graph traversal.
        If the node name is 'finish', it will always be executed last in the
        graph traversal.
        Args:
            name: A string that specifies the name of the node
            node: a callable method that implements the function for the node
            chance: A float that specifies the likelyhood that the state
                machine will execute the node.  Values should be greater than
                0.0 and less than or equal to 1.0
            continue_chance: A float that specifies the likelyhood that the
                state machine will continue execution upon completing the
                node's execution.  Values should be greater than 0.0 and less
                than or equal to 1.0
        Returns:
            None
        Raises:
            Exception if name is not a string
            Exception if chance is not a float
            Exception if chance not greater than 0.0 and less than or equal to
                1.0
            Exception if continue_chance is not a float
            Exception if continue_chance not greater than 0.0 and less than or
                equal to 1.0
            Exception if node is not callable
            Exception if node has already been defined in the graph
        """
        assert isinstance(name, str)
        assert isinstance(chance, float)
        assert chance > 0.0 and chance <= 1.0
        assert isinstance(continue_chance, float)
        assert continue_chance > 0.0 and continue_chance <= 1.0
        assert callable(node), '%s is not callable (%s)' % (repr(node), name)
        assert node not in self._nodes

        if name == 'start':
            self.start = node

        if name == 'finish':
            self.finish = node

        self._nodes[node] = {'chance': chance, 'continue': continue_chance,
                             'depth': [], 'seen': 0}

    def add_edge(self, node1, node2, weight=None, before=None, after=None):
        """ Add a weighted edge from one node to another node
        Args:
            node1: The parent node
            node2: The child node
            weight: The weighting of the the edge between node1 and node2
            before: Only enable the node before the specified percentage of polls
            after: Only enable the node after the specified percentage of polls
        Returns:
            None
        Raises:
            Exception if node1 or node2 are not defined nodes
            Exception if weight is not a float or integer
            Exception if an edge from node1 to node2 already exists
        """
        assert node1 in self._nodes
        assert node2 in self._nodes
        if weight is None:
            weight = 1.0
        if before is None:
            before = 1.0
        if after is None:
            after = 0.0

        assert isinstance(weight, (int, float))

        if node1 not in self._neighbors:
            self._neighbors[node1] = {}

        assert node2 not in self._neighbors[node1]
        self._neighbors[node1][node2] = {'weight': weight, 'after': after, 'before': before, 'depth': []}

    def _random_edge(self, node, iteration, total):
        """ Select a random edge to traverse from a given node, based on the
        weighted edges defined during 'add_edge'
        Args:
            node: The node to select edges from
        Returns:
            A random node based on the weighted values
        Raises:
            None
        """
        nodes = list(self._neighbors[node].keys())
        # nodes.sort()

        current_percentage = 0.0
        if iteration is not None and total is not None:
            current_percentage = float(iteration) / float(total)

            current_percentage = min(current_percentage, 1.0)
            current_percentage = max(current_percentage, 0.0)

        for edge_node in nodes:
            if current_percentage > self._neighbors[node][edge_node]['before']:
                nodes.remove(edge_node)

            if current_percentage < self._neighbors[node][edge_node]['after']:
                nodes.remove(edge_node)

        weights = []
        for edge_node in nodes:
            weights.append(self._neighbors[node][edge_node]['weight'])
        value = random.random() * sum(weights)
        for i, weight in enumerate(weights):
            value -= weight
            if value <= 0:
                return nodes[i]

    def walk(self, iteration=None, total=None):
        """ Walk the directed graph
        Starting at a random node, or the 'start' node if specified,
        iteratively walk the directed graph.  At each node, execute it if the
        node's 'chance' value is successful.
        The graph traversal will continue until a node is executed that have no
        edges from it, the method implementing the node returns -1, the node's
        continue value is not successful, or if more than the specified
        max_depth traversals have occured.
        If a 'finish' node is specified, regardless of the current state, the
        finish node will be executed upon completion of the graph traversal.
        If any one of the nodes return -1, the finish node will not execute.
        Args:
            iteration: Current number of walk iteration
            total: Total number of 'walks' that will be executed
            None
        Returns:
            None
        Raises:
            None
        """
        node = self.start
        if node is None:
            node = random.choice(list(self._nodes.keys()))
        assert node in self._nodes

        seen_nodes = []

        prev = None
        while True:
            if random.random() < self._nodes[node]['chance']:
                if prev is not None:
                    self._neighbors[prev][node]['depth'].append(self._depth)

                self._depth += 1

                if node not in seen_nodes:
                    seen_nodes.append(node)

                self._nodes[node]['depth'].append(self._depth)
                response = node()
                if response == -1:
                    break
            
            prev = node

            if random.random() > self._nodes[node]['continue']:
                break

            if node not in self._neighbors:
                break

            if self._depth > self.max_depth:
                break

            node = self._random_edge(node, iteration, total)

        if self.finish is not None:
            self._depth += 1
            self._nodes[self.finish]['depth'].append(self._depth)
            if self.finish not in seen_nodes:
                seen_nodes.append(self.finish)
            self.finish()

        for node in seen_nodes:
            self._nodes[node]['seen'] += 1

        self._depth = 0

    @classmethod
    def _make_plot(cls, title, depths, names, filename):
        """ Create a PNG plot of the graph data
        Args:
            title: title of the plot
            depths: Values to be graphed
            names: Names of each of the bins being graphed
            filename: Full path of the file for the resulting PNG
        Returns:
            None
        Raises:
            None
        """
        plt.figure()
        plt.title(title)
        plt.xlabel('Graph Depth')
        plt.ylabel('Count')
        plt.margins(0.01)
        plt.subplots_adjust(bottom=0.15)
        hist = plt.hist(depths, histtype='bar', label=names, bins=10)
        plt.yscale('log', nonposy='clip')
        plt.gca().yaxis.set_major_formatter(matplotlib.ticker.ScalarFormatter())
        plt.rc('legend', **{'fontsize': 8})
        plt.legend(shadow=True, fancybox=True)
        plt.savefig(filename, format='png')

    @classmethod
    def _make_bar_plot(cls, title, depths, names, filename):
        """ Create a PNG plot of the graph data in simple bar chart form
        Args:
            title: title of the plot
            depths: Values to be graphed
            names: Names of each of the bins being graphed
            filename: Full path of the file for the resulting PNG
        Returns:
            None
        Raises:
            None
        """
        fig = plt.figure()
        plt.title(title)
        width = .35
        ind = numpy.arange(len(depths))
        plt.bar(ind, depths)
        plt.xticks(ind + width / 2, names)
        fig.autofmt_xdate() 
        plt.rc('legend', **{'fontsize': 8})
        plt.savefig(filename, format='png')

    def plot(self, directory):
        """ Create plots of data from the graph traversals that have occured
        thus far.
        Creates a plot showing the execution of nodes per each depth of the
        traversal, and a plot showing the edge traversals per depth of the
        traversal.
        Args:
            directory: Directory to write the resulting plots
        Returns:
            None
        Raises:
            AssertionError if a node was never executed
            AssertionError if an edge was never traversed
        """
        depths = []
        names = []
        for node in self._nodes:
            # assert len(self._nodes[node]['depth']), "node %s was never "\
            #     "executed" % node.func_name
            depths.append(self._nodes[node]['depth'])
            names.append(node.__name__)

        self._make_plot('Node execution per depth', depths, names,
                        os.path.join(directory, 'nodes.png'))

        counts = []
        names = []
        for node in self._nodes:
            counts.append(self._nodes[node]['seen'])
            names.append(node.__name__)

        self._make_bar_plot('Node inclusion count', counts, names,
                        os.path.join(directory, 'counts.png'))

        depths = []
        names = []
        for node in self._neighbors:
            for sub_node in self._neighbors[node]:
                # assert len(self._neighbors[node][sub_node]['depth']), "Edge" \
                #     "%s->%s was not traversed" % (node.func_name,
                #                                   sub_node.func_name)
                depths.append(self._neighbors[node][sub_node]['depth'])
                names.append('%s->%s' % (node.__name__, sub_node.__name__))

        self._make_plot('Edge traversal per depth', depths, names,
                        os.path.join(directory, 'edges.png'))

    def dot(self):
        """ Return the existing graph into DOT format
        Args:
            None
        Returns:
            String containing the graph in DOT format
        Raises:
            None
        """
        text = []
        text.append('digraph G {')
        for node in self._nodes:
            notes = [node.__name__]

            if self._nodes[node]['chance'] != 1.0:
                notes.append('chance=%.2f' % self._nodes[node]['chance'])

            if self._nodes[node]['continue'] != 1.0:
                notes.append('continue=%.2f' % self._nodes[node]['continue'])

            shape = ''
            if self.start == node:
                shape = ', shape=box'
            if node not in self._neighbors:
                shape = ', shape=triangle'
            text.append('    %s [label="%s"%s];' % (node.__name__,
                                                    '\\n'.join(notes), shape))
        for node in self._neighbors:
            for sub_node in self._neighbors[node]:
                sub_text = ''
                if self._neighbors[node][sub_node]['weight'] != 1:
                    label = str(self._neighbors[node][sub_node]['weight'])
                    sub_text = ' [label="%sx"]' % label
                text.append('    %s -> %s%s;' % (node.__name__,
                                                 sub_node.__name__, sub_text))
        text.append('}')
        return '\n'.join(text)

class PRNG(object):
    """
    A python implementation of ANSI X9.31 using AES 128
    Attributes:
        random_data: Currently available block of generated random data
        V: "seed value which is also kept secret"
        DT: "date/time vector updated upon each iteration"
        I: Intermediate value
        aes_ctx: AES state machine context
    """
    BLOCK_SIZE = 16

    def __init__(self, seed=None):
        """
        Seed is V + Key + DT as a string
        """
        if seed is not None:
            assert len(seed) == 48
        else:
            seed = "zaybxcwdveuftgsh" + "0123456789abcdef" + "\x00" * 16

        self.V, key, self.DT = [seed[i:i+PRNG.BLOCK_SIZE] for i in range(0, len(seed), PRNG.BLOCK_SIZE)]
        self.random_data = ''

        self.I = "\x00" * PRNG.BLOCK_SIZE
        self.aes_ctx = AES.new(key, mode=AES.MODE_ECB)

    @staticmethod
    def _xor_string(value_1, value_2):
        """
        value_1 ^ value_2
        Exceptions:
            AssertionError if value_1 and value_2 are not the same length
        """
        assert len(value_1) == len(value_2)
        return ''.join(chr(ord(a) ^ ord(b)) for a, b in zip(value_1, value_2))

    def _get_block(self):
        """
        Get the next block from the PRNG, saving it to self.random_data
        Arguments:
            None
        Returns:
            None
        Exceptions:
            None
        """
        # encrypt the counter value, giving intermediate value I
        self.I = self.aes_ctx.encrypt(self.DT)

        # XOR I with secret vector V, encrypt the result to obtain pseudo
        # random data
        tmp = self._xor_string(self.I, self.V)
        self.random_data = self.aes_ctx.encrypt(tmp)

        # XOR random data with I, and encrypt to get new secret vector V
        tmp = self._xor_string(self.random_data, self.I)
        self.V = self.aes_ctx.encrypt(tmp)

        # update DT value
        i = PRNG.BLOCK_SIZE - 1
        while i >= 0:
            out = (ord(self.DT[i]) + 1) % 256
            self.DT = self.DT[:i] + chr(out) + self.DT[i+1:]
            if out != 0:
                break
            i -= 1

    def get(self, size):
        """
        Get 'size' bytes of random data
        Arguments:
            size: Amount of random data to return
        Returns:
            str of length 'size' of random data
        Exceptions:
            AssertionError if size is not a positive integer
        """
        assert isinstance(size, int)
        assert size > 0

        result = ''
        while len(result) < size:
            need = size - len(result)
            if not len(self.random_data):
                self._get_block()

            result += self.random_data[:need]
            self.random_data = self.random_data[need:]

        return result


def encode(data):
    """Encodes a string to the 'cstring' encoding supported by the replay DTD.
    Args:
        data: string value to be encoded
    Returns:
        String containing the encoded value
    Raises:
        None
    """
    chars = string.letters + string.digits + " ?!:."
    return "".join([x if x in chars else "\\x%02x" % ord(x) for x in data])


class Variable(object):
    def __init__(self, name):
        assert name.isalnum()

        self._name = name
        self._method = None
        self._begin = None
        self._end = None
        self._re = None
        self._value = None

    def set_value(self, value):
        """Sets the 'Variable' value, useful for Actions.set().
        Args:
            value: Specify data that should be set in the 'var' instance,
                as specified by the DTD.
        Returns:
           None
        Raises:
            Exception if value is not a string
        """
        assert isinstance(value, str)
        self._value = value
        self._method = "value"

    def set_re(self, value, group=None):
        """Sets the 'Variable' value to be a regular expression
        Args:
            value: Specify the regular expression used in an 'assign' instance,
                as specified by the DTD.
        Returns:
           None
        Raises:
            Exception if value is not a string
            Exception if value is empty
        """
        assert isinstance(value, str)
        assert len(value)
        if group is not None:
            assert isinstance(group, int)
        else:
            group = 0
        self._re = value
        self._re_group = group
        self._method = "re"

    def set_slice(self, begin, end=None):
        """Sets the 'Variable' value to be a slice
        Args:
            value: Specify the slice used in an 'assign' instance, as specified
            by the DTD.
        Returns:
           None
        Raises:
            Exception if begin is not an integer
            Exception if end is not None or an integer
        """
        assert isinstance(begin, int)
        assert isinstance(end, (type(None), int))
        self._method = "slice"

        self._begin = begin
        self._end = end

    def get_read(self):
        """Get the 'assign' XML element
        Args:
            None
        Returns:
            String defining the '<assign>' XML element
        Raises:
            Exception if the method has not been defined as 're' or 'slice'
        """
        # <assign> <var>foo</var> <slice begin="1" end="10" /> </assign>
        # <assign> <var>bar</var> <pcre>(.*)</pcre> </assign>
        assert self._method in ["re", "slice"]

        xml = ""
        if self._method == "slice":
            if self._end is None:
                xml = '<slice begin="%d" />' % (self._begin)
            else:
                xml = '<slice begin="%d" end="%d" />' % (self._begin, self._end)
        elif self._method == "re":
            if self._re_group != 0:
                xml = '<pcre group="%d">%s</pcre>' % (self._re_group, self._re)
            else:
                xml = "<pcre>%s</pcre>" % (self._re)

        return "<assign> <var>%s</var> %s </assign>" % (self._name, xml)

    def get_set(self):
        """Get the 'decl' XML element
        Args:
            None
        Returns:
            String defining the '<decl>' XML element
        Raises:
            Exception if the method has not been defined as 'value'
        """
        assert self._method == "value"
        return "<decl> <var>%s</var> <value> <data>%s</data> " "</value> </decl>" % (
            self._name,
            encode(self._value),
        )

    def get_write(self):
        """Get the XML element that defines writing the variable
        Args:
            None
        Returns:
            String defining the '<var>' XML element
        Raises:
            None
        """
        assert self._method is not None
        return "<var>%s</var>" % (self._name)


class Actions(object):
    """Actions - Define the interactions for a CB
    This class implements the basic methods to interact with a CB, in terms of
    XML generation for use with 'cb-replay'.
    Usage:
        a = Actions():
        a.write('foo')
        a.read(delim='\n')
        a.xml()
    Attributes:
        state: Dict of state values, to be reset upon each iteration.
        used_magic_page: Has the magic page been used
    """

    def __init__(self):
        self._actions = []
        self.state = {}

        self._seed = None
        self._magic_page = None
        self.used_magic_page = False
        self._matched = False
        self._sent = False
        self._recv = False

    @property
    def magic_page(self):
        if not self.used_magic_page:
            self.used_magic_page = True
            self._seed = self.random_buffer(48)
            prng = PRNG(self._seed)
            self._magic_page = prng.get(0x1000)
        return self._magic_page

    @classmethod
    def chance(cls, value=0.5):
        """Randomly return True or False, with the likelyhood defined by
        specifying a percentage argument.
        Args:
            value: A float between 0.0 and 1.0
        Returns:
            True or False
        Raises:
            Exception: if 'value' is not a float between 0.0 and 1.0
        """
        assert isinstance(value, float)
        assert value > 0.0 and value < 1.0
        return random.random() < value

    @staticmethod
    def random_buffer(size, chars=None):
        """Create a buffer of random data of a length specified by the the
        size argument.
        Args:
            size: Size of buffer to create
            chars: Optional sequence of characters (If none is provided, all characters are used)
        Raises:
            None
        """

        if chars is None:
            chars = "".join([chr(x) for x in range(256)])

        return "".join(random.choice(chars) for _ in range(size))

    def reset(self):
        """Re-initialize the instance of the class
        Args:
            None
        Returns:
           None
        Raises:
            None
        """
        self.__init__()

    def xml(self, store_seed=None):
        """Returns the XML of the existing actions following the replay.dtd
        spec
        Args:
            store_xml: Should the seed be stored in the XML
        Returns:
           String containing XML of the existing actions
        Raises:
            None
        """
        lines = [
            '<?xml version="1.0" standalone="no" ?>',
            '<!DOCTYPE pov SYSTEM "/usr/share/cgc-docs/replay.dtd">',
        ]
        out = "\n"
        actions = "\n    " + "\n    ".join(self._actions) + "\n"
        out += self._wrap("cbid", "service") + "\n"
        # assert self._matched, 'polls must match or assign content from the server'
        # assert self._sent, 'polls must send data to the server'
        # assert self._recv, 'polls must recv data from the server'
        if store_seed:
            seed = self._seed
            if seed is None:
                seed = self.random_buffer(48)
            out += self._wrap("seed", seed.encode("hex")) + "\n"
        out += self._wrap("replay", actions) + "\n"
        lines.append(self._wrap("pov", out))
        return "\n".join(lines)

    @classmethod
    def _wrap(cls, tag, value, **options):
        """Creates an XML eliment
        Args:
            tag: The tag name
            value: The value of the tag
            **options: arbitrary named arguments, used as attributes for the
                tag
        Returns:
           String containing XML element
        Raises:
            None
        """
        opt_string = ""

        if len(options):
            opts = []
            for key in options:
                opts.append('%s="%s"' % (key, options[key]))
            opt_string = " " + " ".join(opts)
        return "<%s%s>%s</%s>" % (tag, opt_string, value, tag)

    def read(
        self,
        delim=None,
        length=None,
        expect=None,
        expect_format=None,
        timeout=None,
        assign=None,
    ):
        """Create a 'read' interaction for a challenge binary as supported by
        the replay DTD.
        Args:
            delim: Specify data should be read until the string has been
                received from the CB
            length: Specify the amount of data to be read from the CB.
            expect: Specify the expected value that should be returned from the
                CB
            expect_format: Specify the format of the 'expect' value, allowed
                values are 'pcre', 'asciic', or 'variable'.  Unless a value is
                specified, the default format is 'asciic'.
            assign: An optional 'Variable' instance used to specify XML
                'assign' arguments.
        Returns:
           None
        Raises:
            Exception if delim AND length are specified
            Exception if expect_format is specified and expect is not specified
            Exception if expect_format is not 'pcre' or 'asciic'
            Exception if timeout is not an integer
            Exception if length is not an integer
            Exception if the delimiter is not a string
            Exception if the delimiter is an empty string
            Exception if assign is set and is not a 'Variable' instance
        """
        assert length is not None or delim is not None
        if expect_format is not None:
            assert expect is not None
            assert expect_format in ["pcre", "asciic", "variable"]

        xml = ""

        if timeout is not None:
            assert isinstance(timeout, int)
            xml += self._wrap("timeout", str(timeout))

        if length is not None:
            assert isinstance(length, int)
            assert length > 0
            xml += self._wrap("length", str(length))

        if delim is not None:
            assert isinstance(delim, str)
            assert len(delim) > 0
            delim = encode(delim)
            xml += self._wrap("delim", delim)

        if expect is not None:
            match = None
            if expect_format == "variable":
                assert isinstance(expect, Variable)
                match = expect.get_write()
            elif expect_format == "pcre":
                match = self._wrap("pcre", expect)
            else:
                match = self._wrap("data", encode(expect))
            xml += self._wrap("match", match)
            self._matched = True

        if assign is not None:
            assert isinstance(assign, Variable)
            xml += assign.get_read()
            self._matched = True

        self._recv = True
        xml = self._wrap("read", xml)
        self._actions.append(xml)

    def comment(self, msg, *args):
        """Create an XML comment of 'msg % args'
        Args:
            msg: Message to be logged
            args: Arguments to be interpreted via str formatting
        Returns
            None
        Raises:
            None
        """
        data = "<!-- %s -->" % encode(msg % args)
        self._actions.append(data)

    def delay(self, value):
        """Create a 'delay' element, to cause a sleep in the interaction with
        the challenge binary, as supported by the replay DTD.
        Args:
            value: An integer to specify how much to sleep
        Returns
            None
        Raises:
            Exception: if value is not a number greater than zero
        """

        assert isinstance(value, int)
        assert value >= 0

        self._actions.append(self._wrap("delay", "%d" % value))

    def set(self, value):
        """Declare a variable as supported by the replay DTD.
        Args:
            value: A Variable instance
        Returns
            None
        Raises:
            Exception: if value is not an instance of Variable
        """

        assert isinstance(value, Variable)
        self._actions.append(value.get_set())

    def write(self, *values):
        """Create a 'write' interaction for a challenge binary as supported by
        the replay DTD.
        Args:
            values: Specify the data that should be sent to the CB.
        Returns
            None
        Raises:
            None
        """

        xml = []
        for value in values:
            if isinstance(value, Variable):
                xml.append(value.get_write())
            else:
                xml.append(self._wrap("data", encode(value)))
        self._sent = True
        self._actions.append(self._wrap("write", "".join(xml)))

def get_attribute(item, name, default=None):
    if name in item:
        return item[name]
    if default is None:
        raise Exception('No value for %s')
    return default


def verify_node(node):
    assert isinstance(node, dict)
    assert 'name' in node
    assert set(node.keys()).issubset(set(['name', 'chance', 'continue']))
    assert node['name'] not in ['weight', 'before', 'after', 'chance', 'name', 'continue']


def get_graph(machine, filename):
    with open(filename, 'r') as graph_fh:
        states = yaml.load(graph_fh, Loader=yaml.loader.FullLoader)

    assert len(states) == 2
    assert 'nodes' in states
    assert 'edges' in states

    graph = Graph()
    for node in states['nodes']:
        verify_node(node)

        assert hasattr(machine, node['name']), "the state machine (%s) does "\
                       "not have a method named %s" % (
                       machine.__class__.__name__, node['name'])

        chance = get_attribute(node, 'chance', 1.0)
        continue_chance = get_attribute(node, 'continue', 1.0)

        node_ptr = getattr(machine, node['name'])
        graph.add_node(node['name'], node_ptr, chance=chance,
                       continue_chance=continue_chance)

    for edge in states['edges']:
        assert len(edge) <= 3
        weight = get_attribute(edge, 'weight', 1.0)
        before = get_attribute(edge, 'before', 1.0)
        after = get_attribute(edge, 'after', 0.0)
        for node in list(edge.keys()):
            if node == 'weight':
                continue
            if node == 'after':
                continue
            assert hasattr(machine, node), "%s does not have the attribute %s" % (machine.__class__.__name__, node)
            assert hasattr(machine, edge[node]), "%s does not have the edge method for %s" % (machine.__class__.__name__, edge[node])
            graph.add_edge(getattr(machine, node),
                           getattr(machine, edge[node]),
                           weight=weight,
                           before=before,
                           after=after)

    return graph

def get_dups(total_count, duplicate, repeat):
    dup_counts = []
    dup_total = 0

    for i in range(duplicate):
        repeat_count = random.randint(1, repeat)
        dup_total += repeat_count
        dup_counts.append(repeat_count)
   
    values = list(range(total_count - dup_total))
    
    dups = []
    for i in dup_counts:
        value = random.choice(values)
        values.remove(value)
        dups += [value] * i
    
    return dups

def get_state_machine(filename):
    module = imp.load_source('state_machine', filename)
    for name in dir(module):
        obj = getattr(module, name)
        try:
            print(obj, obj.__mro__)
        except:
            continue
        if Actions in obj.__mro__[1:]:
            print("Found obj: ", obj)
            return obj()
    raise Exception('No state machine defined in %s' % filename)

def get_package(directory, filename, round_id):
    zip_fh = zipfile.ZipFile(os.path.join(directory, "%d-%s" % (round_id, filename)),
                             'w', zipfile.ZIP_DEFLATED)
    return zip_fh
