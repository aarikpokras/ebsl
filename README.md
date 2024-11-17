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

## Syntax
To set a value, use:
```
key=value
```
You can also set multiple values for one key, but you need to specify the amount of values you'd like to read:
```
key=value1,value2
```
