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

inherit cml1
inherit deploy
inherit kernel-arch

# Analogue to UBOOT_MACHINE
BAREBOX_MACHINE ??= ""

EXTRA_OEMAKE = ' \
    CROSS_COMPILE="${TARGET_PREFIX}" \
    ARCH="${UBOOT_ARCH}" \
'

do_configure() {
    set -e
    unset CFLAGS CPPFLAGS CXXFLAGS LDFLAGS

    if [ ! -z "${BAREBOX_MACHINE}" ]
    then
        bbnote "Using default config: ${BAREBOX_MACHINE}"
        oe_runmake "${BAREBOX_MACHINE}"
    fi
}

do_compile() {
    set -e
    unset CFLAGS CPPFLAGS CXXFLAGS LDFLAGS
    oe_runmake all
}

