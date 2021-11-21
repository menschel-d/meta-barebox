HOMEPAGE = "http://barebox.org"
SECTION = "bootloaders"

LICENSE = "GPL-2.0"
LIC_FILES_CHKSUM = " \
    file://COPYING;md5=f5125d13e000b9ca1f0d3364286c4192 \
    file://LICENSES/preferred/GPL-2.0;md5=e89834fa91135e6dd02eeb3d2a2c1a83 \
"

DEPENDS = "bison-native"

PV:append = "+git${SRCPV}"
SRC_URI = "git://git.pengutronix.de/barebox;branch=${SRCBRANCH}"
SRCBRANCH ??= "master"

S = "${WORKDIR}/git"
B = "${WORKDIR}/build"

inherit barebox
