SUMMARY = ""
DESCRIPTION = ""
HOMEPAGE = "http://barebox.org"
SECTION = "bootloaders"

LICENSE = "GPL-2.0"
LIC_FILES_CHKSUM = "file://COPYING;sha1=8634fb356469824a183b36d91b2f3966abc725ef"

DEPENDS = ""
PROVIDES = "virtual/bootloader"

SRC_URI = "git://git.pengutronix.de/barebox;branch=master"

S = "${WORKDIR}/git"

inherit cml1 deploy

