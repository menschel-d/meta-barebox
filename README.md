# `meta-barebox`

`meta-barebox` is a software layer for the [Yocto Project][] and
[OpenEmbedded][] build system which provides Support for the
[barebox][] bootloader.

[Yocto Project]:
<https://www.yoctoproject.org>

[OpenEmbedded]:
<http://www.openembedded.org>

[barebox]:
<http://barebox.org>


This `README.md` file contains information on the contents of the
barebox layer.

Please see the corresponding sections below for details.


## Table of contents

1. [Dependencies](#dependencies)
2. [Contributing](#contributing)
   1. [Maintainers](#maintainers)
3. [Adding the barebox layer to your build](#adding-the-barebox-layer-to-your-build)
4. [Additional documentation](#additional-documentation)


## Dependencies

This layer depends on:

```
URI: git://git.openembedded.org/bitbake
branch: master

URI: git://git.openembedded.org/openembedded-core
layers: meta
branch: master
```


## Contributing

Please use the infrastructure provided by GitHub to submit [pull requests][]
or [report issues][issue tracker].

If you don't have a GitHub account, you can alternatively send your patches
to the maintainers listed below.

[issue tracker]:
<https://github.com/menschel-d/meta-barebox/issues>

[pull requests]:
<https://github.com/menschel-d/meta-barebox/pulls>


### Maintainers

- Dennis Menschel <<menschel-d@posteo.de>>


## Adding the barebox layer to your build

In order to use this layer, you need to make the build system aware of
it.

Assuming the barebox layer exists at the top-level of your
yocto build tree, you can add it to the build system by adding the
location of the barebox layer to bblayers.conf, along with any
other layers needed. e.g.:

```BitBake
BBLAYERS ?= " \
    /path/to/yocto/meta \
    /path/to/yocto/meta-poky \
    /path/to/yocto/meta-yocto-bsp \
    /path/to/yocto/meta-barebox \
"
```


## Additional documentation

The barebox layer has its own [reference manual](doc/ref-manual.md) with
detailed information about its interface and how to use it.
