---
content_title: Build PICOIO Binaries
---

[[info | Shell Scripts]]
| The build script is one of various automated shell scripts provided in the PICOIO repository for building, installing, and optionally uninstalling the PICOIO software and its dependencies. They are available in the `pico/scripts` folder.

The build script first installs all dependencies and then builds PICOIO. The script supports these [Operating Systems](../../index.md#supported-operating-systems). To run it, first change to the `~/picoio/pico` folder, then launch the script:

```sh
cd ~/picoio/pico
./scripts/picoio_build.sh
```

The build process writes temporary content to the `pico/build` folder. After building, the program binaries can be found at `pico/build/programs`.

[[info | What's Next?]]
| [Installing PICOIO](03_install-picoio-binaries.md) is strongly recommended after building from source as it makes local development significantly more friendly.
