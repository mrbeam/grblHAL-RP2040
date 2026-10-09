#!/usr/bin/env python3
"""Copy completed firmware artifacts using the versions compiled into the build."""
import argparse
import hashlib
from pathlib import Path
import re
import shutil


def macro(header, name):
    match = re.search(r'^#define\s+' + re.escape(name) + r'\s+"([0-9A-Za-z_.+-]+)"',
                      header.read_text(), re.MULTILINE)
    if not match:
        raise ValueError(f"Missing or invalid {name} in {header}")
    return match[1]


def publish(source, output):
    content = source.read_bytes()
    output.parent.mkdir(parents=True, exist_ok=True)
    if not output.exists() or output.read_bytes() != content:
        shutil.copyfile(source, output)
    print(output)



def checksums(output_dir):
    artifacts = sorted(path for path in output_dir.iterdir()
                       if path.is_file() and path.suffix in (".elf", ".uf2"))
    sha256_lines, md5_lines = [], []
    for artifact in artifacts:
        sha256 = hashlib.sha256()
        md5 = hashlib.md5(usedforsecurity=False)
        with artifact.open("rb") as stream:
            for chunk in iter(lambda: stream.read(1024 * 1024), b""):
                sha256.update(chunk)
                md5.update(chunk)
        sha256_lines.append(f"{sha256.hexdigest()}  {artifact.name}\n")
        md5_lines.append(f"{md5.hexdigest()}  {artifact.name}\n")
    for name, lines in (("SHA256SUMS", sha256_lines), ("MD5SUMS", md5_lines)):
        output = output_dir / name
        text = "".join(lines)
        if not output.exists() or output.read_text() != text:
            output.write_text(text)
        print(output)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--header", type=Path, required=True)
    parser.add_argument("--core-header", type=Path, required=True)
    parser.add_argument("--elf", type=Path, required=True)
    parser.add_argument("--output-dir", type=Path, required=True)
    parser.add_argument("--factory", type=Path)
    parser.add_argument("--bootloader", type=Path)
    parser.add_argument("--bootloader-header", type=Path)
    args = parser.parse_args()
    try:
        version = macro(args.header, "GRBL_RP2040_VERSION")
        build = macro(args.header, "GRBL_BUILD_COMPILED")
        creation_date, compiled_version = build.split("_", 1)
        if not re.fullmatch(r"[0-9]{8}", creation_date) or compiled_version != version:
            raise ValueError("Build date/version does not match the compiled version")
        protocol = macro(args.core_header, "GRBL_VERSION")
        publish(args.elf, args.output_dir / f"grblHAL_{protocol}_{creation_date}_{version}.elf")
        if args.factory:
            publish(args.factory, args.output_dir / f"grblhal-{version}-factory.uf2")
        if args.bootloader:
            if not args.bootloader_header:
                raise ValueError("Bootloader header is required")
            boot_version = macro(args.bootloader_header, "BL_VERSION")
            publish(args.bootloader, args.output_dir / f"bootloader-{boot_version}.uf2")
        checksums(args.output_dir)
    except (OSError, ValueError) as error:
        parser.exit(1, f"Production artifact error: {error}\n")


if __name__ == "__main__":
    main()
