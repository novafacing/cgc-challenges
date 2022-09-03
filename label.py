"""
Label cb-multios challenges
"""
from pathlib import Path
from pylcs import lcs_string_length


challenges = Path(__file__).with_name("challenges")

# Change to your clone of https://github.com/CyberGrandChallenge/samples
orig_samples = Path("../cgc-samples/cqe-challenges/")

orig_readmes = {}

for sample in orig_samples.iterdir():
    if sample.is_dir():
        readme = sample / "README.md"
        if readme.exists():
            orig_readmes[sample.name] = readme

cur_readmes = {}

for challenge in challenges.iterdir():
    if challenge.is_dir():
        readme = challenge / "README.md"
        if readme.exists():
            cur_readmes[challenge.name] = readme

orig_readmes_lst = list(orig_readmes.items())
orig_names_lst = list(map(lambda x: x[0], orig_readmes_lst))
orig_readme_text_lsg = list(map(lambda x: x[1].read_text(), cur_readmes.items()))

for curname, curreadme in cur_readmes.items():
    mx = -1
    midx = -1

    currtext = curreadme.read_text()

    for i, text in enumerate(orig_readme_text_lsg):
        length = lcs_string_length(currtext, text)

        if length > mx:
            mx = length
            midx = i

    if mx > 0 and midx < len(orig_names_lst) and midx >= 0:

        maxlcs_name = orig_names_lst[midx]
        print(curname, maxlcs_name, mx)
    else:
        print(curname, "no match")
