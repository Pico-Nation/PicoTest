---
content_title: Nodpico
---

## Introduction

`nodpico` is the core service daemon that runs on every PICOIO node. It can be configured to process smart contracts, validate transactions, produce blocks containing valid transactions, and confirm blocks to record them on the blockchain.

## Installation

`nodpico` is distributed as part of the [PICOIO software suite](https://github.com/PICOIO/pico/blob/master/README.md). To install `nodpico`, visit the [PICOIO Software Installation](../00_install/index.md) section.

## Explore

Navigate the sections below to configure and use `nodpico`.

* [Usage](02_usage/index.md) - Configuring and using `nodpico`, node setups/environments.
* [Plugins](03_plugins/index.md) - Using plugins, plugin options, mandatory vs. optional.
* [Replays](04_replays/index.md) - Replaying the chain from a snapshot or a blocks.log file.
* [RPC APIs](05_rpc_apis/index.md) - Remote Procedure Call API reference for plugin HTTP endpoints.
* [Logging](06_logging/index.md) - Logging config/usage, loggers, appenders, logging levels.
* [Concepts](07_concepts/index.md) - `nodpico` concepts, explainers, implementation aspects.
* [Troubleshooting](08_troubleshooting/index.md) - Common `nodpico` troubleshooting questions.
* [Deprecation Notices](https://github.com/PICOIO/pico/issues/7597) - Lists `nodpico` deprecated functionality.

[[info | Access Node]]
| A local or remote PICOIO access node running `nodpico` is required for a client application or smart contract to interact with the blockchain.
