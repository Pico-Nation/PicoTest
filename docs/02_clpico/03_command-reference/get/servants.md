## Description
Retrieve accounts which are servants of a given account 

## Info

**Command**

```sh
clpico get servants
```
**Output**

```console
Usage: clpico get servants account

Positionals:
  account TEXT                The name of the controlling account
```

## Command

```sh
clpico get servants inita
```

## Output

```json
{
  "controlled_accounts": [
    "tester"
  ]
}
```
