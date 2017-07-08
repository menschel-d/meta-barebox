This `README.md` file contains information on the contents of the
barebox layer.

Please see the corresponding sections below for details.


Dependencies
============

This layer depends on:

    URI: git://git.openembedded.org/bitbake
    branch: master

    URI: git://git.openembedded.org/openembedded-core
    layers: meta
    branch: master


Patches
=======

Please submit any patches against the barebox layer to the
maintainer:


Maintainers
-----------

- Dennis Menschel <menschel-d@posteo.de>


Table of Contents
=================

 1. [Adding the barebox layer to your build](#adding-the-barebox-layer-to-your-build)
 2. [Additional documentation](#additional-documentation)


Adding the barebox layer to your build
======================================

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


Additional documentation
========================

The barebox layer has its own [reference manual](doc/ref-manual.md) with
detailed information about its interface and how to use it.
