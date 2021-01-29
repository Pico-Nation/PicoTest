---
content_title: MacOS 10.14
---

This section contains shell commands to manually download, build, install, test, and uninstall PICOIO and dependencies on MacOS 10.14.

[[info | Building PICOIO is for Advanced Developers]]
| If you are new to PICOIO, it is recommended that you install the [PICOIO Prebuilt Binaries](../../../00_install-prebuilt-binaries.md) instead of building from source.

Select a task below, then copy/paste the shell commands to a Unix terminal to execute:

* [Download PICOIO Repository](#download-picoio-repository)
* [Install PICOIO Dependencies](#install-picoio-dependencies)
* [Build PICOIO](#build-picoio)
* [Install PICOIO](#install-picoio)
* [Test PICOIO](#test-picoio)
* [Uninstall PICOIO](#uninstall-picoio)

[[info | Building PICOIO on another OS?]]
| Visit the [Build PICOIO from Source](../../index.md) section.

## Download PICOIO Repository
These commands set the PICOIO directories, install git, and clone the PICOIO repository.
```sh
# set PICOIO directories
export PICOIO_LOCATION=~/picoio/pico
export PICOIO_INSTALL_LOCATION=$PICOIO_LOCATION/../install
mkdir -p $PICOIO_INSTALL_LOCATION
# install git
brew update && brew install git
# clone PICOIO repository
git clone https://github.com/PICOIO/pico.git $PICOIO_LOCATION
cd $PICOIO_LOCATION && git submodule update --init --recursive
```

## Install PICOIO Dependencies
These commands install the PICOIO software dependencies. Make sure to [Download the PICOIO Repository](#download-picoio-repository) first and set the PICOIO directories.
```sh
# install dependencies
brew install cmake python libtool libusb graphviz automake wget gmp pkgconfig doxygen openssl@1.1 jq boost || :
export PATH=$PICOIO_INSTALL_LOCATION/bin:$PATH
# install mongodb
mkdir -p $PICOIO_INSTALL_LOCATION/bin
cd $PICOIO_INSTALL_LOCATION && curl -OL https://fastdl.mongodb.org/osx/mongodb-osx-ssl-x86_64-3.6.3.tgz
    tar -xzf mongodb-osx-ssl-x86_64-3.6.3.tgz && rm -f mongodb-osx-ssl-x86_64-3.6.3.tgz && \
    mv $PICOIO_INSTALL_LOCATION/mongodb-osx-x86_64-3.6.3/bin/* $PICOIO_INSTALL_LOCATION/bin/ && \
    rm -rf $PICOIO_INSTALL_LOCATION/mongodb-osx-x86_64-3.6.3 && rm -rf $PICOIO_INSTALL_LOCATION/mongodb-osx-ssl-x86_64-3.6.3.tgz
# install mongo-c-driver from source
cd $PICOIO_INSTALL_LOCATION && curl -LO https://github.com/mongodb/mongo-c-driver/releases/download/1.13.0/mongo-c-driver-1.13.0.tar.gz && \
    tar -xzf mongo-c-driver-1.13.0.tar.gz && cd mongo-c-driver-1.13.0 && \
    mkdir -p cmake-build && cd cmake-build && \
    cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=$PICOIO_INSTALL_LOCATION -DENABLE_BSON=ON -DENABLE_SSL=DARWIN -DENABLE_AUTOMATIC_INIT_AND_CLEANUP=OFF -DENABLE_STATIC=ON -DENABLE_ICU=OFF -DENABLE_SASL=OFF -DENABLE_SNAPPY=OFF .. && \
    make -j $(getconf _NPROCESSORS_ONLN) && \
    make install && \
    rm -rf $PICOIO_INSTALL_LOCATION/mongo-c-driver-1.13.0.tar.gz $PICOIO_INSTALL_LOCATION/mongo-c-driver-1.13.0
# install mongo-cxx-driver from source
cd $PICOIO_INSTALL_LOCATION && curl -L https://github.com/mongodb/mongo-cxx-driver/archive/r3.4.0.tar.gz -o mongo-cxx-driver-r3.4.0.tar.gz && \
    tar -xzf mongo-cxx-driver-r3.4.0.tar.gz && cd mongo-cxx-driver-r3.4.0/build && \
    cmake -DBUILD_SHARED_LIBS=OFF -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=$PICOIO_INSTALL_LOCATION .. && \
    make -j $(getconf _NPROCESSORS_ONLN) VERBOSE=1 && \
    make install && \
    rm -rf $PICOIO_INSTALL_LOCATION/mongo-cxx-driver-r3.4.0.tar.gz $PICOIO_INSTALL_LOCATION/mongo-cxx-driver-r3.4.0
```

## Build PICOIO
These commands build the PICOIO software on the specified OS. Make sure to [Install PICOIO Dependencies](#install-picoio-dependencies) first.

[[caution | `PICOIO_BUILD_LOCATION` environment variable]]
| Do NOT change this variable. It is set for convenience only. It should always be set to the `build` folder within the cloned repository.

```sh
export PICOIO_BUILD_LOCATION=$PICOIO_LOCATION/build
mkdir -p $PICOIO_BUILD_LOCATION
cd $PICOIO_BUILD_LOCATION && cmake -DCMAKE_BUILD_TYPE='Release' -DCMAKE_INSTALL_PREFIX=$PICOIO_INSTALL_LOCATION -DBUILD_MONGO_DB_PLUGIN=true $PICOIO_LOCATION
cd $PICOIO_BUILD_LOCATION && make -j$(getconf _NPROCESSORS_ONLN)
```

## Install PICOIO
This command installs the PICOIO software on the specified OS. Make sure to [Build PICOIO](#build-picoio) first.
```sh
cd $PICOIO_BUILD_LOCATION && make install
```

## Test PICOIO
These commands validate the PICOIO software installation on the specified OS. This task is optional but recommended. Make sure to [Install PICOIO](#install-picoio) first.
```sh
$PICOIO_INSTALL_LOCATION/bin/mongod --fork --logpath $(pwd)/mongod.log --dbpath $(pwd)/mongodata
cd $PICOIO_BUILD_LOCATION && make test
```

## Uninstall PICOIO
These commands uninstall the PICOIO software from the specified OS.
```sh
xargs rm < $PICOIO_BUILD_LOCATION/install_manifest.txt
rm -rf $PICOIO_BUILD_LOCATION
```
