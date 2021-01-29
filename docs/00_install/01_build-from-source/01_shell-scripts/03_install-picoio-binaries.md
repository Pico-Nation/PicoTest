---
content_title: Install PICOIO Binaries
---

## PICOIO install script

For ease of contract development, content can be installed at the `/usr/local` folder using the `picoio_install.sh` script within the `pico/scripts` folder. Adequate permission is required to install on system folders:

```sh
cd ~/picoio/pico
./scripts/picoio_install.sh
```

## PICOIO manual install

In lieu of the `picoio_install.sh` script, you can install the PICOIO binaries directly by invoking `make install` within the `pico/build` folder. Again, adequate permission is required to install on system folders:

```sh
cd ~/picoio/pico/build
make install
```

[[info | What's Next?]]
| Configure and use [Nodpico](../../../01_nodpico/index.md), or optionally [Test the PICOIO binaries](04_test-picoio-binaries.md).
