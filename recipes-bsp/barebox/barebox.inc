SUMMARY = ""
DESCRIPTION = ""
HOMEPAGE = "http://barebox.org"
SECTION = "bootloaders"

LICENSE = "GPL-2.0"
LIC_FILES_CHKSUM = "file://COPYING;md5=057bf9e50e1ca857d0eb97bfe4ba8e5d"

DEPENDS = ""
PROVIDES = "virtual/bootloader"

SRC_URI = "git://git.pengutronix.de/barebox;branch=master"

S = "${WORKDIR}/git"

inherit cml1 deploy

# Works in most cases, exceptions are ppc instead of powerpc and sandbox
BAREBOX_ARCH ??= "${KARCH}"

# Analogue to UBOOT_MACHINE
BAREBOX_MACHINE ??= "unknown"

