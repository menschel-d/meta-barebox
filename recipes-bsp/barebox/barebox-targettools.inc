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

do_install() {
    install -d "${D}/${sbindir}"
    install -m 755 "${B}/scripts/bareboxcrc32-target" "${D}/${sbindir}/bareboxcrc32"
    install -m 755 "${B}/scripts/bareboxenv-target" "${D}/${sbindir}/bareboxenv"
    install -m 755 "${B}/scripts/bareboximd-target" "${D}/${sbindir}/bareboximd"
    install -m 755 "${B}/scripts/kernel-install-target" "${D}/${sbindir}/barebox-kernel-install"
}

do_deploy[noexec] = "1"

