DEPENDS_prepend = "lzop-native "

inherit cml1
inherit deploy
inherit kernel-arch

# As long as barebox and u-boot use the same naming scheme for machine
# architectures, we can re-use UBOOT_ARCH from the kernel-arch class.
BAREBOX_ARCH ?= "${UBOOT_ARCH}"


##############################################################################
#
# Input variables
#
##############################################################################

# Analogue to UBOOT_MACHINE
BAREBOX_CONFIG ??= ""
BAREBOX_CONFIG[doc] = "The configuration for the *kbuild* build system to use when building barebox."

BAREBOX_IMAGE_SRC ??= "barebox.bin"
BAREBOX_IMAGE_SRC[doc] = "This option is intended for configurations that produce multiple images for different target variants. In that case, an entry must be selected from the contents of the file `barebox-flash-images` which will be located in the build directory of barebox after it has been built once."


##############################################################################
#
# Output variables
#
##############################################################################

BAREBOX_IMAGE ??= "${BAREBOX_IMAGE_BASENAME}-${PV}-${PR}-${MACHINE}-${DATETIME}"
BAREBOX_IMAGE[vardepsexclude] += "DATETIME"
BAREBOX_IMAGE[doc] = "The complete file name of the generated image file without any file extension."

BAREBOX_IMAGE_BASENAME ??= "${PN}"
BAREBOX_IMAGE_BASENAME[doc] = "The basename for the bootloader image. It is implicitly used to distinguish between the main bootloader and an optional pre-bootloader. If the ROM bootloader of the target hardware expects a specific file name that is different from the default value, it can be adjusted with this BitBake variable (and the appropriate suffix variable)."

BAREBOX_IMAGE_SUFFIX ??= ".bin"
BAREBOX_IMAGE_SUFFIX[doc] = "The file extension for the bootloader image."

BAREBOX_IMAGE_SUFFIX_ELF ??= ".elf"
BAREBOX_IMAGE_SUFFIX_ELF[doc] = "The file extension for the bootloader image in Executable and Linkable Format (ELF)."

BAREBOX_IMAGE_SUFFIX_PER ??= ".per"
BAREBOX_IMAGE_SUFFIX_PER[doc] = "The file extension for the peripheral bootloader image."

BAREBOX_IMAGE_SUFFIX_SPI ??= ".spi"
BAREBOX_IMAGE_SUFFIX_SPI[doc] = "The file extension for a specific image variant that can boot from SPI. This is of relevance if you build `barebox-pbl` with the config option `CONFIG_OMAP_BUILD_SPI`."

BAREBOX_IMAGE_SYMLINK ??= "${BAREBOX_IMAGE_BASENAME}"
BAREBOX_IMAGE_SYMLINK[doc] = "A symbolic name to the most recent build of the bootloader, without any file extension."


EXTRA_OEMAKE_prepend = ' \
    -C "${S}" \
    KBUILD_OUTPUT="${B}" \
    CROSS_COMPILE="${TARGET_PREFIX}" \
    ARCH="${BAREBOX_ARCH}" \
'

DEPLOYSUBDIR ?= "${DEPLOYDIR}/${PN}-${PV}"
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

barebox_do_configure() {
    set -e
    unset CFLAGS CPPFLAGS CXXFLAGS LDFLAGS

    if [ ! -z "${BAREBOX_CONFIG}" ]
    then
        bbnote "Using default config: ${BAREBOX_CONFIG}"
        oe_runmake "${BAREBOX_CONFIG}"
    fi
    apply_cfgs
}

barebox_do_compile() {
    set -e
    unset CFLAGS CPPFLAGS CXXFLAGS LDFLAGS
    oe_runmake all
}

barebox_do_deploy() {
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
EXPORT_FUNCTIONS do_configure do_compile do_deploy
