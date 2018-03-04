require barebox-utils.inc

PR = "r2"

SRC_URI += " \
    file://0001-fs-avoid-pathes-with-in-__canonicalize_path.patch \
    file://0002-fs-Don-t-bother-filesystems-without-link-support-wit.patch \
    file://0001-scripts-compiler.h-inline-functions-in-headers-must-.patch \
"

SRCREV = "fbde027fdb1d8725253787dd3416702255e646f7"
