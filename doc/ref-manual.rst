===================================
Reference Manual for `meta-barebox`
===================================

:Author: Dennis Menschel <menschel-d@posteo.de>
:Date: 2017-06-11
:Version: Yocto 2.2 (morty)

.. sectnum::

.. contents::


Intro
=====

This document is a reference manual for the `meta-barebox` layer.


Motivation
----------

Why a separate layer for the bootloader barebox?


Interface
=========

.. image:: barebox_recipes.svg
    :alt: Barebox recipe hierarchy



Input
-----

The appropriate value for this option depends on the target hardware.
Therefore it should be set in the machine configuration file inside some
BSP layer.


BAREBOX_CONFIG
    The configuration for the Kconfig build system to use when building barebox.

    Default value: ``""``


BAREBOX_IMAGE_SRC
    This option is intended for configurations that produce multiple images
    for different target variants.
    In that case, an entry must be selected from the contents of the file
    ``barebox-flash-images`` which will be located in the build directory of
    barebox after it has been built once.

    For example, if you choose ``BAREBOX_CONFIG = "am335x_defconfig"``,
    then the contents of the aforementioned file might be as follows::

        $ cd <barebox build directory>
        $ cat barebox-flash-images
        images/barebox-am33xx-afi-gf.img
        images/barebox-am33xx-phytec-phycore.img
        images/barebox-am33xx-phytec-phycore-no-spi.img
        images/barebox-am33xx-phytec-phycore-no-eeprom.img
        images/barebox-am33xx-phytec-phycore-no-spi-no-eeprom.img
        images/barebox-am33xx-phytec-phyflex.img
        images/barebox-am33xx-phytec-phyflex-no-spi.img
        images/barebox-am33xx-phytec-phyflex-no-eeprom.img
        images/barebox-am33xx-phytec-phyflex-no-spi-no-eeprom.img
        images/barebox-am33xx-phytec-phycard.img
        images/barebox-am33xx-beaglebone.img

    Default value: ``"barebox.bin"``


Output
------

All generated output files will be placed in ``${DEPLOYDIR}/${PN}-${PV}``.
Contrary to the current Yocto practice, the files are not put directly in
``${DEPLOYDIR}`` for the following reasons:

- To introduce a hierarchy.
- To avoid possible file name collisions
  (e.g. ``MLO`` can be produced by both ``barebox`` and ``u-boot`` recipes).


BAREBOX_IMAGE
    The full basename of the generated image file (without the file extension).

    Default value: ``"${BAREBOX_IMAGE_BASENAME}-${PV}-${PR}-${MACHINE}-${DATETIME}"``


BAREBOX_IMAGE_BASENAME
    Test2

    Default value: ``"${PN}"``


BAREBOX_IMAGE_SUFFIX
    Test2

    Default value: ``".bin"``


BAREBOX_IMAGE_SUFFIX_ELF
    Test2

    Default value: ``".elf"``


BAREBOX_IMAGE_SUFFIX_PER
    Test2

    Default value: ``".per"``


BAREBOX_IMAGE_SUFFIX_SPI
    Test2

    Default value: ``".spi"``


BAREBOX_IMAGE_SYMLINK
    Test2

    Default value: ``"${BAREBOX_IMAGE_BASENAME}"``


Common tasks
============


Machine configuration
---------------------


Example: Beaglebone
^^^^^^^^^^^^^^^^^^^

::

  MACHINE = "beaglebone"
  BAREBOX_CONFIG_beaglebone = "am335x_defconfig"
  BAREBOX_CONFIG_pn-barebox-pbl_beaglebone = "am335x_mlo_defconfig"
  RDEPENDS_barebox_beaglebone += "barebox-pbl"
  COMPATIBLE_MACHINE_pn-barebox_beaglebone = "beaglebone"


Example: Raspberry Pi 3
^^^^^^^^^^^^^^^^^^^^^^^

::

  MACHINE = "raspberrypi3"
  BAREBOX_CONFIG_raspberrypi3 = "rpi_defconfig"
  COMPATIBLE_MACHINE_pn-barebox_raspberrypi3 = "raspberrypi3"


Barebox configuration
---------------------

- cml1 class, do_menuconfig, do_diffconfig
- configuration fragments


Default environment modification
--------------------------------

- Overlay of barebox environment version 2
- Applying patches, extending do_patch to add or remove files.


Todo
====

- Adapt skeleton README file.
- Add support for sandbox configuration.
- Add clean information.

