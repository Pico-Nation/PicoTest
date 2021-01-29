## Description

The `producer_api_plugin` exposes a number of endpoints for the [`producer_plugin`](../producer_plugin/index.md) to the RPC API interface managed by the [`http_plugin`](../http_plugin/index.md).

## Usage

```console
# config.ini
plugin = picoio::producer_api_plugin
```
```sh
# nodpico startup params
nodpico ... --plugin picoio::producer_api_plugin
```

## Options

None

## Dependencies

* [`producer_plugin`](../producer_plugin/index.md)
* [`chain_plugin`](../chain_plugin/index.md)
* [`http_plugin`](../http_plugin/index.md)

### Load Dependency Examples

```console
# config.ini
plugin = picoio::producer_plugin
[options]
plugin = picoio::chain_plugin
[options]
plugin = picoio::http_plugin
[options]
```
```sh
# command-line
nodpico ... --plugin picoio::producer_plugin [options]  \
           --plugin picoio::chain_plugin [operations] [options]  \
           --plugin picoio::http_plugin [options]
```
