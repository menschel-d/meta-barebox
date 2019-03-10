require recipes-bsp/barebox/barebox-common.inc

SUMMARY = "Versatile Linux-like bootloader for embedded systems (pre-bootloader)"
DESCRIPTION = "The pre-bootloader is a minimalistic version of barebox. \
It is used on embedded systems with restricted resources to prepare the \
hardware before loading the full barebox bootloader. \
Depending on the context, the pre-bootloader is also referred to as \
SPL (Secondary Program Loader) or MLO (Memory LOader)."

BAREBOX_IMAGE_SUFFIX ??= ""
BAREBOX_IMAGE_BASENAME ??= "MLO"

def get_extra_image_name(d):
    path = d.getVar("BAREBOX_IMAGE_SRC", True)
    dirname, basename = os.path.split(path)
    basename = basename.replace('-', '_').replace('barebox', 'start').replace('mlo', 'sram').replace('.img', '')
    result = os.path.join(dirname, basename)
    return result

BAREBOX_IMAGE_SRC_EXTRA ??= "${@get_extra_image_name(d)}"

do_deploy_append() {
    image_src_spi="$(echo ${BAREBOX_IMAGE_SRC%.img}.spi.img)"
    if [ -f "${B}/${image_src_spi}" ]
    then
        install -m 644 "${B}/${image_src_spi}" \
            "${DEPLOYSUBDIR}/${BAREBOX_IMAGE}${BAREBOX_IMAGE_SUFFIX_SPI}"
        ln -sfr "${DEPLOYSUBDIR}/${BAREBOX_IMAGE}${BAREBOX_IMAGE_SUFFIX_SPI}" \
            "${DEPLOYSUBDIR}/${BAREBOX_IMAGE_SYMLINK}${BAREBOX_IMAGE_SUFFIX_SPI}"
    fi

    install -m 644 "${B}/${BAREBOX_IMAGE_SRC_EXTRA}.pbl" \
        "${DEPLOYSUBDIR}/${BAREBOX_IMAGE}${BAREBOX_IMAGE_SUFFIX_ELF}"
    ln -sfr "${DEPLOYSUBDIR}/${BAREBOX_IMAGE}${BAREBOX_IMAGE_SUFFIX_ELF}" \
        "${DEPLOYSUBDIR}/${BAREBOX_IMAGE_SYMLINK}${BAREBOX_IMAGE_SUFFIX_ELF}"

    install -m 644 "${B}/${BAREBOX_IMAGE_SRC_EXTRA}.pblb" \
        "${DEPLOYSUBDIR}/${BAREBOX_IMAGE}${BAREBOX_IMAGE_SUFFIX_PER}"
    ln -sfr "${DEPLOYSUBDIR}/${BAREBOX_IMAGE}${BAREBOX_IMAGE_SUFFIX_PER}" \
        "${DEPLOYSUBDIR}/${BAREBOX_IMAGE_SYMLINK}${BAREBOX_IMAGE_SUFFIX_PER}"
}

PACKAGE_ARCH = "${MACHINE_ARCH}"

COMPATIBLE_MACHINE = "(^$)"
