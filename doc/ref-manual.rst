===================================
Reference Manual for `meta-barebox`
===================================

:Author: Dennis Menschel
:Date: 2016-12-17
:Status: work in progress

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

- IMAGE_BOOT_FILES


Input
-----

- BAREBOX_ARCH
- BAREBOX_MACHINE

- BAREBOX_SUFFIX
- BAREBOX_IMAGE
- BAREBOX_SYMLINK

- BAREBOX_PBL_SUFFIX
- BAREBOX_PBL_IMAGE
- BAREBOX_PBL_SYMLINK


- ELF (derivable)
- SPI (derivable)
- PER (derivable)
- BIN/MLO

- BAREBOX_CONFIG
- BAREBOX_IMAGE
- BAREBOX_SYMLINK

- BAREBOX_PBL_CONFIG
- BAREBOX_PBL_IMAGE
- BAREBOX_PBL_SYMLINK


BAREBOX_CONFIG
BAREBOX_IMAGE_SRC
BAREBOX_IMAGE
BAREBOX_IMAGE_SYMLINK
BAREBOX_IMAGE_SUFFIX_ELF
BAREBOX_IMAGE_SUFFIX_SPI
BAREBOX_IMAGE_SUFFIX_PER


Output
------


Common tasks
============


Machine configuration
---------------------


Example: Beaglebone
^^^^^^^^^^^^^^^^^^^

::

  MACHINE = "beaglebone"
  BAREBOX_MACHINE_beaglebone = "am335x_defconfig"
  BAREBOX_MACHINE_pn-barebox-pbl_beaglebone = "am335x_mlo_defconfig"
  RDEPENDS_barebox_beaglebone += "barebox-pbl"
  COMPATIBLE_MACHINE_pn-barebox_beaglebone = "beaglebone"


Example: Raspberry Pi 3
^^^^^^^^^^^^^^^^^^^^^^^

::

  MACHINE = "raspberrypi3"
  BAREBOX_MACHINE_raspberrypi3 = "rpi_defconfig"
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

- Link to most recent output in deploy directory.
- Adapt skeleton README file.
- Add summary and description to recipes.
- Add support for sandbox configuration.
- Add clean information.
- Add install task.

