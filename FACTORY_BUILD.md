# Mr Beam factory firmware

Initialize the pinned sources, then build both images:

```sh
git submodule update --init --recursive
mkdir -p build
cd build
cmake ..
make -j16
```

Set `PICO_SDK_PATH` to your Pico SDK directory if needed.

Outputs in the top-level build directory:

- `bootloader-<version>.uf2`: pure serial bootloader, with its compiled version in the filename (e.g. `bootloader-v1.1.1.uf2`).
- `grblHAL.elf`: application-only ELF linked at 0x10009000, compatible with the serial bootloader and the UART serial-flash tool.
- `grblhal-factory.uf2`: serial bootloader plus CRC header and application, for initial provisioning through native RP2040 USB BOOTSEL (RPI-RP2).

Internal ELF/BIN/header files remain build intermediates. The application-only UF2 is not generated. Older artifacts in an existing build directory are not automatically removed.

The top-level CMake build includes the bootloader submodule and uses its `bootloader_build_standalone()` and `bootloader_build_combined()` helpers. Application sources are compiled into a shared static library and linked into the application-only and combined images. The bootloader's `gen_imghdr.py` generates the application CRC header; picotool converts the header-patched combined ELF into UF2.

The factory target is included in the default build. Build the packaged outputs explicitly with `make mrblhal_factory_image`, or disable them with `-DMRBEAM_FACTORY_IMAGE=OFF` for an application-only build.

Factory packaging does not initialize or erase the settings NVS. Existing settings on a previously programmed device remain subject to the firmware's normal settings restore behavior.
