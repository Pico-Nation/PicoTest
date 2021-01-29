---
content_title: Download PICOIO Source
---

To download the PICOIO source code, clone the `pico` repo and its submodules. It is adviced to create a home `picoio` folder first and download all the PICOIO related software there:

```sh
mkdir -p ~/picoio && cd ~/picoio
git clone --recursive https://github.com/PICOIO/pico
```

## Update Submodules

If a repository is cloned without the `--recursive` flag, the submodules *must* be updated before starting the build process:

```sh
cd ~/picoio/pico
git submodule update --init --recursive
```

## Pull Changes

When pulling changes, especially after switching branches, the submodules *must* also be updated. This can be achieved with the `git submodule` command as above, or using `git pull` directly:

```sh
[git checkout <branch>]  (optional)
git pull --recurse-submodules
```

[[info | What's Next?]]
| [Build PICOIO binaries](02_build-picoio-binaries.md)
