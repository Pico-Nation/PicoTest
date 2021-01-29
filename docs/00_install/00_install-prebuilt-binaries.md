---
content_title: Install Prebuilt Binaries
---

[[info | Previous Builds]]
| If you have previously installed PICOIO from source using shell scripts, you must first run the [Uninstall Script](01_build-from-source/01_shell-scripts/05_uninstall-picoio.md) before installing any prebuilt binaries on the same OS.

## Prebuilt Binaries

Prebuilt PICOIO software packages are available for the operating systems below. Find and follow the instructions for your OS:

### Mac OS X:

#### Mac OS X Brew Install
```sh
brew tap picoio/picoio
brew install picoio
```
#### Mac OS X Brew Uninstall
```sh
brew remove picoio
```

### Ubuntu Linux:

#### Ubuntu 18.04 Package Install
```sh
wget https://github.com/picoio/pico/releases/download/v2.0.9/picoio_2.0.9-1-ubuntu-18.04_amd64.deb
sudo apt install ./picoio_2.0.9-1-ubuntu-18.04_amd64.deb
```
#### Ubuntu 16.04 Package Install
```sh
wget https://github.com/picoio/pico/releases/download/v2.0.9/picoio_2.0.9-1-ubuntu-16.04_amd64.deb
sudo apt install ./picoio_2.0.9-1-ubuntu-16.04_amd64.deb
```
#### Ubuntu Package Uninstall
```sh
sudo apt remove picoio
```

### RPM-based (CentOS, Amazon Linux, etc.):

#### RPM Package Install
```sh
wget https://github.com/picoio/pico/releases/download/v2.0.9/picoio-2.0.9-1.el7.x86_64.rpm
sudo yum install ./picoio-2.0.9-1.el7.x86_64.rpm
```
#### RPM Package Uninstall
```sh
sudo yum remove picoio
```

## Location of PICOIO binaries

After installing the prebuilt packages, the actual PICOIO binaries will be located under:
* `/usr/opt/picoio/<version-string>/bin` (Linux-based); or
* `/usr/local/Cellar/picoio/<version-string>/bin` (MacOS)

where `version-string` is the PICOIO version that was installed.

Also, soft links for each PICOIO program (`nodpico`, `clpico`, `kpicod`, etc.) will be created under `usr/bin` or `usr/local/bin` to allow them to be executed from any directory.

## Previous Versions

To install previous versions of the PICOIO prebuilt binaries:

1. Browse to https://github.com/PICOIO/pico/tags and select the actual version of the PICOIO software you need to install.

2. Scroll down past the `Release Notes` and download the package or archive that you need for your OS.

3. Follow the instructions on the first paragraph above to install the selected prebuilt binaries on the given OS.
