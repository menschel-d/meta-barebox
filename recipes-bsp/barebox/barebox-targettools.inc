require barebox-common.inc

SUMMARY = ""
DESCRIPTION = ""

DEPENDS += "virtual/libc"

FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI += " \
    file://target-tools.cfg \
"

PACKAGE_ARCH="${TUNE_PKGARCH}"

export TARGETCFLAGS="${TARGET_CC_ARCH} ${TOOLCHAIN_OPTIONS} ${CFLAGS} ${LDFLAGS}"

do_deploy[noexec] = "1"

