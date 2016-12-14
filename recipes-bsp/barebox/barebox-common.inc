HOMEPAGE = "http://barebox.org"
SECTION = "bootloaders"

LICENSE = "GPL-2.0"
LIC_FILES_CHKSUM = "file://COPYING;md5=057bf9e50e1ca857d0eb97bfe4ba8e5d"

DEPENDS = "lzop-native"

SRC_URI = "git://git.pengutronix.de/barebox;branch=master"

S = "${WORKDIR}/git"

inherit cml1
inherit deploy
inherit kernel-arch

PACKAGE_ARCH = "${MACHINE_ARCH}"

# As long as barebox and u-boot use the same naming scheme for machine
# architectures, we can re-use UBOOT_ARCH from the kernel-arch class.
BAREBOX_ARCH ?= "${UBOOT_ARCH}"

# Analogue to UBOOT_MACHINE
BAREBOX_MACHINE ??= ""

EXTRA_OEMAKE = ' \
    CROSS_COMPILE="${TARGET_PREFIX}" \
    ARCH="${BAREBOX_ARCH}" \
'

DEPLOYSUBDIR="${DEPLOYDIR}/${PN}-${PV}"
do_deploy[dirs] += "${DEPLOYSUBDIR}"

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

do_deploy() {
    set -e
    for img in `cat "${S}/barebox-flash-images"`
    do
        install -m 644 "${S}/${img}" "${DEPLOYSUBDIR}"
    done
}

addtask deploy before do_build after do_compile

