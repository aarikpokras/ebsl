# EBSL
### [Full documentation](https://github.com/aarikpokras/ebsl/wiki)
Equals-based Serialization Language


# Contents
* [Compilation](#compilation)
  * [Prep](#prep)
  * [Building](#building)
    * [Meson](#meson-1)
    * [CMake](#cmake)
* [Command usage](#command-usage)
* [Syntax](#syntax)

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
|amt|The amount of values to print for the key|integer or auto|

File `conf.ebsl`:
```
hello=world
github=git,website
phone=samsung,apple,xiaomi,
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
**Notice how in conf.ebsl, the line with `phone` ends in `,`. This is required to use the `max` option.**
## Syntax
To set a value, use:
```
key=value
```
You can also set multiple values for one key, but you need to specify the amount of values you'd like to read:
```
key=value1,value2
```
In order to use the `max` value for the `amt` argument, the line must end in `,`.
```
key=value1,value2,value3,value4,
```

Sometimes, you might want to insert comments in your EBSL file, which can be done by writing `//` at the start of each line. Note that if a line starts with `//` the whole line will be seen as a comment, and comments are ignored by the EBSL interpreter. Example:
```
// this is a comment
key=value
```
