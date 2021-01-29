## Goal

Connect to a specific `nodpico` or `kpicod` host to send COMMAND

`clpico` and `kpicod` can connect to a specific node by using the `--url` or `--wallet-url` optional arguments, respectively, followed by the http address and port number these services are listening to.

[[info | Default address:port]]
| If no optional arguments are used (i.e. `--url` or `--wallet-url`), `clpico` attempts to connect to a local `nodpico` or `kpicod` running at localhost `127.0.0.1` and default port `8888`.

## Before you begin

* Install the currently supported version of `clpico`

## Steps
### Connecting to Nodpico

```sh
clpico -url http://nodpico-host:8888 COMMAND
```

### Connecting to Kpicod

```sh
clpico --wallet-url http://kpicod-host:8888 COMMAND
```
