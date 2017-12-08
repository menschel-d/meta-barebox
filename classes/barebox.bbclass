inherit cml1
inherit deploy
inherit kernel-arch

# As long as barebox and u-boot use the same naming scheme for machine
# architectures, we can re-use UBOOT_ARCH from the kernel-arch class.
BAREBOX_ARCH ?= "${UBOOT_ARCH}"

# Analogue to UBOOT_MACHINE
BAREBOX_CONFIG ??= ""

BAREBOX_IMAGE_SRC ??= "barebox.bin"

BAREBOX_IMAGE_BASENAME ??= "${PN}"
BAREBOX_IMAGE ??= "${BAREBOX_IMAGE_BASENAME}-${PV}-${PR}-${MACHINE}-${DATETIME}"
BAREBOX_IMAGE[vardepsexclude] = "DATETIME"
BAREBOX_IMAGE_SYMLINK ??= "${BAREBOX_IMAGE_BASENAME}"
BAREBOX_IMAGE_SUFFIX ??= ".bin"

BAREBOX_IMAGE_SUFFIX_ELF ??= ".elf"
BAREBOX_IMAGE_SUFFIX_SPI ??= ".spi"
BAREBOX_IMAGE_SUFFIX_PER ??= ".per"

EXTRA_OEMAKE = ' \
    -C "${S}" \
    O="${B}" \
    CROSS_COMPILE="${TARGET_PREFIX}" \
    ARCH="${BAREBOX_ARCH}" \
'

DEPLOYSUBDIR = "${DEPLOYDIR}/${PN}-${PV}"
do_deploy[dirs] += "${DEPLOYSUBDIR}"

def find_cfgs(d):
    """Return all configuration fragments from SRC_URI.
    """
    sources = src_patches(d, True)
    result = []
    for s in sources:
        root, ext = os.path.splitext(s)
        if ext in [".cfg"]:
            result.append(s)
    return result

def find_dtss(d):
    """Return all device tree source files from SRC_URI.
    """
    sources = src_patches(d, True)
    result = []
    for s in sources:
        root, ext = os.path.splitext(s)
        if ext in [".dts", ".dtsi"]:
            result.append(s)
    return result

apply_cfgs() {
    fragments=${@" ".join(find_cfgs(d))}
    if [ -n "${fragments}" ]
    then
        bbnote "Applying configuration fragments."
        "${S}/scripts/kconfig/merge_config.sh" -m -O "${B}" .config ${fragments}
    fi
}

do_configure() {
    set -e
    unset CFLAGS CPPFLAGS CXXFLAGS LDFLAGS

    if [ ! -z "${BAREBOX_CONFIG}" ]
    then
        bbnote "Using default config: ${BAREBOX_CONFIG}"
        oe_runmake "${BAREBOX_CONFIG}"
    fi
    apply_cfgs
}

do_compile() {
    set -e
    unset CFLAGS CPPFLAGS CXXFLAGS LDFLAGS
    oe_runmake all
}

do_deploy() {
    set -e

    # Deploy main image.
    install -m 644 "${B}/${BAREBOX_IMAGE_SRC}" \
        "${DEPLOYSUBDIR}/${BAREBOX_IMAGE}${BAREBOX_IMAGE_SUFFIX}"
    ln -sfr "${DEPLOYSUBDIR}/${BAREBOX_IMAGE}${BAREBOX_IMAGE_SUFFIX}" \
        "${DEPLOYSUBDIR}/${BAREBOX_IMAGE_SYMLINK}${BAREBOX_IMAGE_SUFFIX}"

    # Deploy configuration file.
    install -m 644 "${B}/.config" "${DEPLOYSUBDIR}/${BAREBOX_IMAGE}.config"
    ln -sfr "${DEPLOYSUBDIR}/${BAREBOX_IMAGE}.config" \
        "${DEPLOYSUBDIR}/${BAREBOX_IMAGE_SYMLINK}.config"

    # Make a symlink for the output directory.
    ln -sfr "${DEPLOYSUBDIR}" "${DEPLOYDIR}/${PN}"
}

addtask deploy before do_build after do_compile
