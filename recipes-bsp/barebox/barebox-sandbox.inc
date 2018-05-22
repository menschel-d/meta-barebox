require recipes-bsp/barebox/barebox-common.inc

SUMMARY = "Versatile Linux-like bootloader for embedded systems (sandbox)"
DESCRIPTION = "The sandbox pseudo-target is a simulator for barebox \
that can be run from userspace. \
It can be used during development to check and debug new features \
which are not related to the target hardware."

SRC_URI += " \
    file://disable_logo.cfg \
"

BAREBOX_ARCH = "sandbox"

EXTRA_OEMAKE_prepend = ' \
    CC="${CC}" \
    CPP="${CPP}" \
'

# Fixes error "do_package_qa: QA Issue: No GNU_HASH in the elf binary"
TARGET_CC_ARCH += "${LDFLAGS}"

do_configure() {
    set -e
    unset CFLAGS CPPFLAGS CXXFLAGS LDFLAGS

    oe_runmake "sandbox_defconfig"
    apply_cfgs
}

do_install() {
    install -m 0755 "${B}/barebox" "${D}${bindir}/barebox-sandbox"
}
do_install[dirs] += "${D}${bindir}"

do_deploy[noexec] = "1"

BBCLASSEXTEND = "native"
