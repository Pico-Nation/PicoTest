---
content_title: Kpicod
---

## Introduction

`kpicod` is a key manager service daemon for storing private keys and signing digital messages. It provides a secure key storage medium for keys to be encrypted at rest in the associated wallet file. `kpicod` also defines a secure enclave for signing transaction created by `clpico` or a third part library.

## Installation

`kpicod` is distributed as part of the [PICOIO software suite](https://github.com/PICOIO/pico/blob/master/README.md). To install `kpicod` just visit the [PICOIO Software Installation](../00_install/index.md) section.

## Operation

When a wallet is unlocked with the corresponding password, `clpico` can request `kpicod` to sign a transaction with the appropriate private keys. Also, `kpicod` provides support for hardware-based wallets such as Secure Encalve and YubiHSM.

[[info | Audience]]
| `kpicod` is intended to be used by PICOIO developers only.
