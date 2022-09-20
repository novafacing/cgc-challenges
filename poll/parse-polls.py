import argparse
import os
from xml.etree import ElementTree
from codecs import escape_decode


def parse(input_dir, output_dir, number):
    """
    Parse the input xml polls into the output directory as raw files
    """

    # Iterate over files in input dir
    polls = []
    for filename in os.listdir(input_dir):
        if len(polls) >= number:
            break
        if filename.endswith(".xml"):
            with open(os.path.join(input_dir, filename), "r") as f:
                polls.append(f.read())

    for i, xml in enumerate(polls):
        filename = "GEN_%05d_%05d.raw" % (1, i)

        tree = ElementTree.ElementTree(ElementTree.fromstring(xml))

        try:
            writes = list([w.find("data").text for w in tree.iter(tag="write")])
            raw_contents = ""
            for w in writes:
                raw_contents += escape_decode(w)[0]

            with open(os.path.join(output_dir, filename), "w") as xml_fh:
                xml_fh.write(raw_contents)
        except Exception as e:
            pass


def main():
    parser = argparse.ArgumentParser(prog="parse-polls")
    parser.add_argument(
        "--number",
        "-n",
        type=int,
        default=20,
        help="Maximum number of existing seeds to use.",
    )
    parser.add_argument(
        "input_dir", type=str, help="Directory containing the poll files."
    )
    parser.add_argument("output_dir", type=str, help="Output directory.")
    args = parser.parse_args()
    parse(args.input_dir, args.output_dir, args.number)


if __name__ == "__main__":
    main()
