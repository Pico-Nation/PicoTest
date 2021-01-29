# Bios Boot Tutorial

The `bios-boot-tutorial.py` script simulates the PICOIO bios boot sequence.

``Prerequisites``:

1. Python 3.x
2. CMake
3. git
4. g++
5. build-essentials
6. pip3
7. openssl
8. curl
9. jq
10. psmisc


``Steps``:

1. Install picoio binaries by following the steps outlined in below tutorial
[Install picoio binaries](https://github.com/PICOIO/pico/tree/release/2.0.x#mac-os-x-brew-install).

2. Install picoio.cdt version 1.6.3 binaries by following the steps outlined in below tutorial
[Install picoio.cdt binaries](https://github.com/PICOIO/picoio.cdt/tree/release/1.6.x#binary-releases).

3. Compile `picoio.contracts` version 1.8.x.

```bash
$ cd ~
$ git clone https://github.com/PICOIO/picoio.contracts.git picoio.contracts-1.8.x
$ cd ./picoio.contracts-1.8.x/
$ git checkout release/1.8.x
$ ./build.sh
$ cd ./build/contracts/
$ pwd

```

4. Make note of the directory where the contracts were compiled. 
The last command in the previous step printed on the bash console the contracts' directory, make note of it, we'll reference it from now on as `PICOIO_OLD_CONTRACTS_DIRECTORY`.

5. Install picoio.cdt version 1.7.0 binaries by following the steps outlined in below tutorial, make sure you uninstall the previous one first.
[Install picoio.cdt binaries](https://github.com/PICOIO/picoio.cdt/tree/release/1.7.x#binary-releases)

6. Compile `picoio.contracts` sources version 1.9.0

```bash
$ cd ~
$ git clone https://github.com/PICOIO/picoio.contracts.git
$ cd ./picoio.contracts/
$ git checkout release/1.9.x
$ ./build.sh
$ cd ./build/contracts/
$ pwd

```

7. Make note of the directory where the contracts were compiled
The last command in the previous step printed on the bash console the contracts' directory, make note of it, we'll reference it from now on as `PICOIO_CONTRACTS_DIRECTORY`


8. Launch the `bios-boot-tutorial.py` script. 
The command line to launch the script, make sure you replace `PICOIO_OLD_CONTRACTS_DIRECTORY` and `PICOIO_CONTRACTS_DIRECTORY` with actual directory paths.

```bash
$ cd ~
$ git clone https://github.com/PICOIO/pico.git
$ cd ./pico/tutorials/bios-boot-tutorial/
$ python3 bios-boot-tutorial.py --clpico="clpico --wallet-url http://127.0.0.1:6666 " --nodpico=nodpico --kpicod=kpicod --contracts-dir="PICOIO_CONTRACTS_DIRECTORY" --old-contracts-dir="PICOIO_OLD_CONTRACTS_DIRECTORY" -w -a
```

6. At this point, when the script has finished running without error, you have a functional PICOIO based blockchain running locally with an latest version of `picoio.system` contract, 31 block producers out of which 21 active, `picoio` account resigned, 200k+ accounts with staked tokens, and votes allocated to each block producer. Enjoy exploring your freshly booted blockchain.

See [PICOIO Documentation Wiki: Tutorial - Bios Boot](https://github.com/PICOIO/pico/wiki/Tutorial-Bios-Boot-Sequence) for additional information.