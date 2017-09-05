require barebox.inc

PR = "r1"

SRC_URI += " \
    file://0001-fs-avoid-pathes-with-in-__canonicalize_path.patch \
    file://0002-fs-Don-t-bother-filesystems-without-link-support-wit.patch \
"

SRCREV = "fbde027fdb1d8725253787dd3416702255e646f7"
