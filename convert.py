"""
Convert cmake challenges to meson
"""

from os import mkdir
from pathlib import Path
from shutil import copytree, rmtree

from string import ascii_letters

challenges_dir = Path(__file__).with_name("challenges")

for challenge_dir in challenges_dir.iterdir():

    challenge_name = "challenge_" + challenge_dir.name.replace("-", "_").replace(
        ".", "_"
    )

    challenge_exec_name = challenge_dir.name

    if not challenge_dir.is_dir():
        continue

    print(f"Converting {challenge_dir}")

    src_dir = challenge_dir / "src"

    if not src_dir.is_dir():
        print(f"{challenge_dir} has no src directory")
        continue

    lib_dir = challenge_dir / "lib"
    include_dir = challenge_dir / "include"

    if not include_dir.exists():
        include_dir.mkdir()

    src_headers = list(filter(lambda x: x.suffix == ".h", src_dir.iterdir()))

    if lib_dir.is_dir():
        lib_headers = list(filter(lambda x: x.suffix == ".h", lib_dir.iterdir()))
    else:
        lib_headers = []

    for src_header in src_headers:
        src_header.rename(include_dir / src_header.name)

    for lib_header in lib_headers:
        lib_header.rename(include_dir / lib_header.name)

    if lib_dir.exists():
        copytree(lib_dir, src_dir / lib_dir.name)
        rmtree(lib_dir)

    src_list = list(
        map(
            lambda s: s.relative_to(challenge_dir),
            filter(lambda s: s.is_file(), src_dir.rglob("**/*")),
        ),
    )
    src_list_text = "\n".join(map(lambda s: f"""    '{s}',""", src_list))

    meson_build = (
        f"# {challenge_name}\n"
        f"{challenge_name}_inc = include_directories('include')\n"
        f"{challenge_name}_src = [\n"
        f"{src_list_text}\n"
        "]\n"
        f"{challenge_name} = executable(\n"
        f"    '{challenge_exec_name}',\n"
        f"    {challenge_name}_src,\n"
        f"    include_directories: [{challenge_name}_inc, libcgc_inc],\n"
        "    link_with: [libcgc]\n"
        ")\n"
    )

    meson_file = challenge_dir / "meson.build"

    meson_file.write_text(meson_build)
