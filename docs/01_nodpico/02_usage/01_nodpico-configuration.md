---
content_title: Nodpico Configuration
---

The plugin-specific options can be configured using either CLI options or a configuration file, `config.ini`. Nodpico-specific options can only be configured from the command line. All CLI options and `config.ini` options can be found by running `nodpico --help` as shown above.

Each `config.ini` option has a corresponding CLI option. However, not all CLI options are available in `config.ini`. For instance, most plugin-specific options that perform actions are not available in `config.ini`, such as `--delete-state-history` from `state_history_plugin`.

For example, the CLI option `--plugin picoio::chain_api_plugin` can also be set by adding `plugin = picoio::chain_api_plugin` in `config.ini`.

## `config.ini` location

The default `config.ini` can be found in the following folders:
- Mac OS: `~/Library/Application Support/picoio/nodpico/config`
- Linux: `~/.local/share/picoio/nodpico/config`

A custom `config.ini` file can be set by passing the `nodpico` option `--config path/to/config.ini`.

## Nodpico Example

The example below shows a typical usage of `nodpico` when starting a block producing node:

```sh
nodpico \
  -e -p picoio \
  --data-dir /users/mydir/picoio/data     \
  --config-dir /users/mydir/picoio/config \
  --plugin picoio::producer_plugin      \
  --plugin picoio::chain_plugin         \
  --plugin picoio::http_plugin          \
  --plugin picoio::state_history_plugin \
  --contracts-console   \
  --disable-replay-opts \
  --access-control-allow-origin='*' \
  --http-validate-host=false        \
  --verbose-http-errors             \
  --state-history-dir /shpdata \
  --trace-history              \
  --chain-state-history        \
  >> nodpico.log 2>&1 &
```

The above `nodpico` command starts a producing node by:

* enabling block production (`-e`)
* identifying itself as block producer "picoio" (`-p`)
* setting the blockchain data directory (`--data-dir`)
* setting the `config.ini` directory (`--config-dir`)
* loading plugins `producer_plugin`, `chain_plugin`, `http_plugin`, `state_history_plugin` (`--plugin`)
* passing `chain_plugin` options (`--contracts-console`, `--disable-replay-opts`)
* passing `http-plugin` options (`--access-control-allow-origin`, `--http-validate-host`, `--verbose-http-errors`)
* passing `state_history` options (`--state-history-dir`, `--trace-history`, `--chain-state-history`)
* redirecting both `stdout` and `stderr` to the `nodpico.log` file
* returning to the shell by running in the background (&)
