#!/usr/bin/env python

import os
from generator.actions import Actions
import random
import subprocess


class RPN(Actions):
    def start(self):
        ops = "-+*/|^~!"
        num_elems = random.randint(0, 49)
        self.string = ""
        for i in xrange(num_elems):
            if random.randint(0, 1) % 2 == 0:
                self.string += random.choice(ops) + " "
            else:
                if random.randint(0, 1) % 2 == 0:
                    self.string += "-"
                if random.randint(0, 1) % 2 == 0:
                    self.string += "0x%08x " % random.randint(0, 2147483647)
                else:
                    self.string += "%d " % random.randint(0, 2147483647)
        self.string = self.string[:-1]
        self.string += "\n"

    def doit(self):
        root = os.getenv("CORPUS_ROOT", None)

        if root is None:
            raise Exception("CORPUS_ROOT environment variable not set")

        binary = os.path.join(root, "RRPN")

        process = subprocess.Popen(
            ["RRPN"],
            cwd=binary,
            env={"LD_LIBRARY_PATH": binary},
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
        )
        process.stdin.write(self.string)
        exp_out = process.communicate()[0]
        self.state["divide_by_zero"] = len(exp_out) <= 2

        self.read(length=2, expect="> ")
        self.write(self.string)
        if not self.state["divide_by_zero"]:
            self.read(delim="\n", expect=exp_out[2:-2])

    def quit(self):
        if not self.state["divide_by_zero"]:
            self.write("quit\n")
            self.read(delim="\n", expect="> QUIT\n")
