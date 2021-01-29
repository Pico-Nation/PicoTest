---
content_title: Amazon Linux 2
---

This section contains shell commands to manually download, build, install, test, and uninstall PICOIO and dependencies on Amazon Linux 2.

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
yum update -y && yum install -y git
# clone PICOIO repository
git clone https://github.com/PICOIO/pico.git $PICOIO_LOCATION
cd $PICOIO_LOCATION && git submodule update --init --recursive
```

## Install PICOIO Dependencies
These commands install the PICOIO software dependencies. Make sure to [Download the PICOIO Repository](#download-picoio-repository) first and set the PICOIO directories.
```sh
# install dependencies
yum install -y which sudo procps-ng util-linux autoconf automake \
    libtool make bzip2 bzip2-devel openssl-devel gmp-devel libstdc++ libcurl-devel \
    libusbx-devel python3 python3-devel python-devel libedit-devel doxygen \
    graphviz clang patch llvm-devel llvm-static vim-common jq
# build cmake
export PATH=$PICOIO_INSTALL_LOCATION/bin:$PATH
cd $PICOIO_INSTALL_LOCATION && curl -LO https://cmake.org/files/v3.13/cmake-3.13.2.tar.gz && \
    tar -xzf cmake-3.13.2.tar.gz && \
    cd cmake-3.13.2 && \
    ./bootstrap --prefix=$PICOIO_INSTALL_LOCATION && \
    make -j$(nproc) && \
    make install && \
    rm -rf $PICOIO_INSTALL_LOCATION/cmake-3.13.2.tar.gz $PICOIO_INSTALL_LOCATION/cmake-3.13.2
# build boost
cd $PICOIO_INSTALL_LOCATION && curl -LO https://dl.bintray.com/boostorg/release/1.71.0/source/boost_1_71_0.tar.bz2 && \
    tar -xjf boost_1_71_0.tar.bz2 && \
    cd boost_1_71_0 && \
    ./bootstrap.sh --prefix=$PICOIO_INSTALL_LOCATION && \
    ./b2 --with-iostreams --with-date_time --with-filesystem --with-system --with-program_options --with-chrono --with-test -q -j$(nproc) install && \
    rm -rf $PICOIO_INSTALL_LOCATION/boost_1_71_0.tar.bz2 $PICOIO_INSTALL_LOCATION/boost_1_71_0
# build mongodb
cd $PICOIO_INSTALL_LOCATION && curl -LO https://fastdl.mongodb.org/linux/mongodb-linux-x86_64-amazon-3.6.3.tgz && \
    tar -xzf mongodb-linux-x86_64-amazon-3.6.3.tgz && rm -f mongodb-linux-x86_64-amazon-3.6.3.tgz && \
    mv $PICOIO_INSTALL_LOCATION/mongodb-linux-x86_64-amazon-3.6.3/bin/* $PICOIO_INSTALL_LOCATION/bin/ && \
    rm -rf $PICOIO_INSTALL_LOCATION/mongodb-linux-x86_64-amazon-3.6.3
# build mongodb c driver
cd $PICOIO_INSTALL_LOCATION && curl -LO https://github.com/mongodb/mongo-c-driver/releases/download/1.13.0/mongo-c-driver-1.13.0.tar.gz && \
    tar -xzf mongo-c-driver-1.13.0.tar.gz && cd mongo-c-driver-1.13.0 && \
    mkdir -p build && cd build && \
    cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=$PICOIO_INSTALL_LOCATION -DENABLE_BSON=ON -DENABLE_SSL=OPENSSL -DENABLE_AUTOMATIC_INIT_AND_CLEANUP=OFF -DENABLE_STATIC=ON -DENABLE_ICU=OFF -DENABLE_SNAPPY=OFF .. && \
    make -j$(nproc) && \
    make install && \
    rm -rf $PICOIO_INSTALL_LOCATION/mongo-c-driver-1.13.0.tar.gz $PICOIO_INSTALL_LOCATION/mongo-c-driver-1.13.0
# build mongodb cxx driver
cd $PICOIO_INSTALL_LOCATION && curl -L https://github.com/mongodb/mongo-cxx-driver/archive/r3.4.0.tar.gz -o mongo-cxx-driver-r3.4.0.tar.gz && \
    tar -xzf mongo-cxx-driver-r3.4.0.tar.gz && cd mongo-cxx-driver-r3.4.0 && \
    sed -i 's/\"maxAwaitTimeMS\", count/\"maxAwaitTimeMS\", static_cast<int64_t>(count)/' src/mongocxx/options/change_stream.cpp && \
    sed -i 's/add_subdirectory(test)//' src/mongocxx/CMakeLists.txt src/bsoncxx/CMakeLists.txt && \
    mkdir -p build && cd build && \
    cmake -DBUILD_SHARED_LIBS=OFF -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=$PICOIO_INSTALL_LOCATION .. && \
    make -j$(nproc) && \
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
cd $PICOIO_BUILD_LOCATION && $PICOIO_INSTALL_LOCATION/bin/cmake -DCMAKE_BUILD_TYPE='Release' -DCMAKE_CXX_COMPILER='clang++' -DCMAKE_C_COMPILER='clang' -DCMAKE_INSTALL_PREFIX=$PICOIO_INSTALL_LOCATION -DBUILD_MONGO_DB_PLUGIN=true $PICOIO_LOCATION
cd $PICOIO_BUILD_LOCATION && make -j$(nproc)
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
