HOMEPAGE = "http://barebox.org"
SECTION = "bootloaders"

LICENSE = "GPL-2.0"
LIC_FILES_CHKSUM = "file://COPYING;md5=057bf9e50e1ca857d0eb97bfe4ba8e5d"

PV_append = "+git${SRCPV}"
SRC_URI = "git://git.pengutronix.de/barebox;branch=${SRCBRANCH}"
SRCBRANCH ??= "master"

S = "${WORKDIR}/git"
B = "${WORKDIR}/build"

inherit barebox
