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
from lib.generator.actions import *

from Crypto.Cipher import AES


def main():
    parser = argparse.ArgumentParser(description='Generate CGC Polls')
    parser.add_argument('--name', required=True, type=str, help="Name of the outputs")
    parser.add_argument('--count', required=False, type=str, help='How many iterations to generate per round')
    parser.add_argument('--depth', required=False, type=int, default=0xFFFFF,
                        help='Maximum number of state transitions per '
                        'iteration')
    parser.add_argument('--seed', required=False, type=str,
                        help='Set random seed')
    parser.add_argument('machine', metavar='machine', type=str,
                        help='Python module with Actions state machine')
    parser.add_argument('state', metavar='state_graph', type=str,
                        help='YAML file specifying state transitions')
    parser.add_argument('output', metavar='output', type=str,
                        help='Output directory')
    parser.add_argument('--rounds', required=False, type=int, default=1,
                        help='Number of rounds the polls should be divided into')
    parser.add_argument('--store_seed', required=False, action='store_true',
                        default=False, help='Store the PRNG seed into the XML')
    parser.add_argument('--package', required=False, type=str,
                        help='Packaged poll results')
    args = parser.parse_args()
    
    if args.seed:
        random.seed(args.seed)

    if not os.path.exists(args.state):
        raise Exception('State graph file %s does not exist' % args.state)

    if not os.path.exists(args.machine):
        raise Exception('Machine file %s does not exist' % args.machine)

    machine = get_state_machine(args.machine)
    graph = get_graph(machine, args.state)

    graph.max_depth = args.depth

    if args.count is not None:
        if ':' in args.count:
            min_count, max_count = [int(x) for x in args.count.split(':')]
        else:
            min_count = max_count = int(args.count)
    else:
        min_count = max_count = 1000

    if max_count == 0 or min_count == 0:
        print("Not generating polls")

    args.repeat = 0
    args.duplicate = 0

    if len(args.output):
        if not os.path.exists(args.output):
            os.makedirs(args.output)
        elif not os.path.isdir(args.output):
            raise Exception('output directory is not a directory: %s' %
                            args.output)

    round_id = 0
    package_fh = None
    if args.package is not None:
        package_fh = get_package(args.output, args.package, round_id)

    package_fh = None

    current_id = 0
    round_counts = []
    round_counts.append(random.randint(min_count, max_count))
    total = sum(round_counts)

    round_id = 0
    round_start = current_id
    if args.package is not None:
        if package_fh is not None:
            package_fh.close()

        package_fh = get_package(args.output, args.package, round_id)

    polls = []

    count = round_counts[round_id]
    dups = get_dups(count, args.duplicate, args.repeat)
    for i in range(count - len(dups)):
        machine.reset()

        graph.walk(current_id, total)
        xml = machine.xml(args.store_seed)
        polls.append(xml)

        # only duplicate the polls that do not use the magic page
        if machine.used_magic_page is False:
            while i in dups:
                dups.remove(i)
                # print "DUP %d of round %d" % (i, round_id)
                xml = machine.xml(args.store_seed)
                polls.append(xml)

        current_id += 1

    random.shuffle(polls)

    # Generate new polls to account for all those that were selected to be
    # dup'd but could not be because the magic page was used.
    for i in range(len(polls), count):
        machine.reset()

        graph.walk(current_id, (args.rounds * count))
        xml = machine.xml(args.store_seed)
        polls.append(xml)
        current_id += 1

    for i, xml in enumerate(polls):
        filename = 'POLL_%s_%d.raw' % (args.name, i)

        tree = ElementTree.ElementTree(ElementTree.fromstring(xml))

        try:

            writes = list([w.find("data").text for w in tree.iter(tag="write")])
            raw_contents = ""
            for w in writes:
                raw_contents += escape_decode(w)[0]


            with open(os.path.join(args.output, filename), 'w') as xml_fh:
                xml_fh.write(raw_contents)
        except Exception as e:
            pass

    if package_fh is not None:
        package_fh.close()

    graph.plot(args.output)

if __name__ == '__main__':
    main()
