require barebox-common.inc

SUMMARY = ""
DESCRIPTION = ""

BAREBOX_IMAGE_SUFFIX ??= ""
BAREBOX_IMAGE_BASENAME ??= "MLO"

COMPATIBLE_MACHINE = "${COMPATIBLE_MACHINE_pn-barebox}"

def get_extra_image_name(d):
    path = d.getVar("BAREBOX_IMAGE_SRC", True)
    dirname, basename = os.path.split(path)
    basename = basename.replace('-', '_').replace('barebox', 'start').replace('mlo', 'sram').replace('.img', '')
    result = os.path.join(dirname, basename)
    return result

BAREBOX_IMAGE_SRC_EXTRA ??= "${@get_extra_image_name(d)}"

do_deploy_append() {
    install -m 644 "${B}/${BAREBOX_IMAGE_SRC_EXTRA}.pbl" \
        "${DEPLOYSUBDIR}/${BAREBOX_IMAGE}${BAREBOX_IMAGE_SUFFIX_ELF}"
    ln -sfr "${DEPLOYSUBDIR}/${BAREBOX_IMAGE}${BAREBOX_IMAGE_SUFFIX_ELF}" \
        "${DEPLOYSUBDIR}/${BAREBOX_IMAGE_SYMLINK}${BAREBOX_IMAGE_SUFFIX_ELF}"

    install -m 644 "${B}/${BAREBOX_IMAGE_SRC_EXTRA}.pblx" \
        "${DEPLOYSUBDIR}/${BAREBOX_IMAGE}${BAREBOX_IMAGE_SUFFIX_PER}"
    ln -sfr "${DEPLOYSUBDIR}/${BAREBOX_IMAGE}${BAREBOX_IMAGE_SUFFIX_PER}" \
        "${DEPLOYSUBDIR}/${BAREBOX_IMAGE_SYMLINK}${BAREBOX_IMAGE_SUFFIX_PER}"
}

