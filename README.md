# ebsl
Equals-based Serialization Language

## Compilation
### Prep
<!-- Add info about command usage -->
You need Meson to build.

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
To write the ninja files, run:
```console
meson build
```
Then
```console
cd build && ninja
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
./ebsl file=conf.ebsl key=phone amt=auto
```
**Notice how in conf.ebsl, the line with `phone` ends in `,`. This is required to use the `auto` option.**
## Syntax
To set a value, use:
```
key=value
```
You can also set multiple values for one key, but you need to specify the amount of values you'd like to read:
```
key=value1,value2
```
