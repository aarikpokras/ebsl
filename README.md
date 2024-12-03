<div align='center'>

# <img src='https://github.com/aarikpokras/ebsl/blob/master/images/ebsl-long.png?raw=true' width="400" />

![Stage](https://img.shields.io/badge/dynamic/toml?url=https%3A%2F%2Fraw.githubusercontent.com%2Faarikpokras%2Febsl%2Frefs%2Fheads%2Fmaster%2Fshields.toml&query=shields.stage&style=for-the-badge&label=stage&color=default)

</div>

![CI Status](https://img.shields.io/github/actions/workflow/status/aarikpokras/ebsl/ci.yml?style=flat-square)
![Code size](https://img.shields.io/github/languages/code-size/aarikpokras/ebsl?style=flat-square)

### [Full documentation](https://github.com/aarikpokras/ebsl/wiki)
Equals-based Serialization Language


# Contents
* [What's next](#whats-next)
* [Compilation](#compilation)
  * [Prep](#prep)
  * [Building](#building)
    * [Meson](#meson-1)
    * [CMake](#cmake)
* [Command usage](#command-usage)
* [Syntax](#syntax)

## What's next?
* Will fix how out delim prints after all values
* Will fix abort trap when key doesn't exist

## Compilation
### Prep
#### Meson
Run:
```console
pip install meson ninja
```
or
```console
pip3 install meson ninja
```
This should work on most systems.
### Building
#### Meson
To write the ninja files, run:
```console
meson build
```
Then
```console
cd build && ninja
```
The executable should be in that directory.
#### CMake
To write the makefiles, run:
```console
cmake -Bbuild
```
Then
```console
cd build && make
```
The executable should be in that directory.
## Command usage
|Arg|Purpose|Type|
|--|--|--|
|file|File to read from|string|
|key|The key whose values to get|string|
|amt|The amount of values to print for the key|integer or max|

File `conf.ebsl`:
```
hello=world
github=git,website
phone=samsung,apple,xiaomi
```
To get the value of `hello`, run:
```console
./ebsl file=conf.ebsl key=hello amt=1
```
To get the values of `github`, run the above command, replacing the key and amount appropriately:
```console
./ebsl file=conf.ebsl key=github amt=2
```
Finally, to get all values for a key (e.g. `phone`), run the following:
```console
./ebsl file=conf.ebsl key=phone amt=max
```

## Syntax
To set a value, use:
```
key=value
```
You can also set multiple values for one key, but you need to specify the amount of values you'd like to read:

```
key=value1,value2
```
