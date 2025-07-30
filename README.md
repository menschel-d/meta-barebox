# `meta-barebox`

> **Deprecation notice:**
> `meta-barebox` was a software layer for the Yocto Project and OpenEmbedded
> build system which provided support for the barebox bootloader.
> The layer was under active development from 2016 until 2024.
> The supported Yocto versions range from 2.3 (pyro) up to 5.1 (styhead).
> With the release of Yocto version 5.2 (walnascar), barebox is now officially
> supported by
> [openembedded-core](https://layers.openembedded.org/layerindex/recipe/450508/).
>
> That means `meta-barebox` has fulfilled its purpose and is now obsolete.
> This layer has been renamed from `meta-barebox` to `meta-barebox-legacy` in
> order to free up the original name in the OpenEmbedded layer index, in case
> anybody wants to start a new layer that is related to barebox.
> The layer's Git repository has not been renamed so legacy users won't be
> disrupted.


`meta-barebox` is a software layer for the [Yocto Project][] and
[OpenEmbedded][] build system which provides support for the
[barebox][] bootloader.

[Yocto Project]:
<https://www.yoctoproject.org>

[OpenEmbedded]:
<http://www.openembedded.org>

[barebox]:
<http://barebox.org>


This `README.md` file contains information on the contents of the
`meta-barebox` layer.

Please see the corresponding sections below for details.


## Table of contents

1. [Dependencies](#dependencies)
2. [Contributing](#contributing)
   1. [Maintainers](#maintainers)
3. [Adding meta-barebox to your build](#adding-meta-barebox-to-your-build)
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

When sending patches or pull requests, please adhere to some common practices
when writing your commit messages:

- Please limit the line lenght in the commit message to 80 characters where
  possible (If you use vim, then [`gq`][vim gq] is your friend).
- Please add a *Signed-off-by* statement (`git commit -s`,
  see also [Developer Certificate of Origin][]).

[vim gq]:
<https://vim.fandom.com/wiki/Automatic_word_wrapping>

[Developer Certificate of Origin]:
<https://developercertificate.org>


### Maintainers

- Dennis Menschel <<menschel-d@posteo.de>>


## Adding `meta-barebox` to your build

In order to use this layer, you need to make the build system aware of
it.

Assuming the `meta-barebox` layer exists at the top-level of your
yocto build tree, you can add it to the build system by adding the
location of the `meta-barebox` layer to `bblayers.conf`, along with any
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
