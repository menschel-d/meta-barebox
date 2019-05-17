HOMEPAGE = "http://barebox.org"
SECTION = "bootloaders"

LICENSE = "GPL-2.0 & BSD-3-Clause"
LIC_FILES_CHKSUM = " \
    file://COPYING;md5=f5125d13e000b9ca1f0d3364286c4192 \
    file://LICENSES/preferred/BSD-3-Clause;md5=4e91b9e6ef320f74590c8c7a64a9188a \
    file://LICENSES/preferred/GPL-2.0;md5=ffd0a252df7d147bec41b98c16114f16 \
"

DEPENDS = "bison-native"

PV_append = "+git${SRCPV}"
SRC_URI = "git://git.pengutronix.de/barebox;branch=${SRCBRANCH}"
SRCBRANCH ??= "master"

S = "${WORKDIR}/git"
B = "${WORKDIR}/build"

inherit barebox
