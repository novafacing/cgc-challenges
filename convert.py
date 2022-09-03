"""
Convert cmake challenges to meson
"""

from os import mkdir
from pathlib import Path

challenges_dir = Path(__file__).with_name("challenges")

for challenge_dir in challenges_dir.iterdir():
    if not challenge_dir.is_dir():
        continue

    print(f"Converting {challenge_dir}")

    src_dir = challenge_dir / "src"
    lib_dir = challenge_dir / "lib"
    include_dir = challenge_dir / "include"

    if not include_dir.exists():
        include_dir.mkdir()

    src_headers = list(filter(lambda x: x.suffix == ".h", src_dir.iterdir()))
    lib_headers = list(filter(lambda x: x.suffix == ".h", lib_dir.iterdir()))

    for src_header in src_headers:
        src_header.rename(include_dir / src_header.name)

    for lib_header in lib_headers:
        lib_header.rename(include_dir / lib_header.name)

    if lib_dir.exists():
        lib_dir.rename(src_dir / lib_dir.name)

    src_list = list(map(lambda s: s.relative_to(challenge_dir), src_dir.rglob("**/*")))
    src_list_text = "\n".join(map(lambda s: f"""    '{s}',""", src_list))

    meson_build = (
        f"# {challenge_dir.name}\n"
        f"{challenge_dir.name}_inc = include_dir('include')\n"
        f"{challenge_dir.name}_src = [\n"
        f"{src_list_text}\n"
        "]\n"
        f"{challenge_dir.name} = executable(\n"
        f"    '{challenge_dir.name}',\n"
        f"    {challenge_dir.name}_src,\n"
        f"    include_directories: {challenge_dir.name}_inc\n"
        ")\n"
    )

    meson_file = challenge_dir / "meson.build"

    meson_file.write_text(meson_build)
