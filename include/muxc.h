/* ----------------------------------------------------------------------------
   -- IOMUXC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOMUXC_Peripheral_Access_Layer IOMUXC Peripheral Access Layer
 * @{
 */

/** IOMUXC - Register Layout Typedef *///
typedef struct {
       uint8_t RESERVED_0[68];
  __IO uint32_t SW_MUX_CTL_PAD[112];               /**< SW_MUX_CTL_PAD_JTAG_MOD SW MUX Control Register..SW_MUX_CTL_PAD_CSI_DATA07 SW MUX Control Register, array offset: 0x44, array step: 0x4 */
  __IO uint32_t SW_PAD_CTL_PAD_DDR[34];            /**< SW_PAD_CTL_PAD_DRAM_ADDR00 SW PAD Control Register..SW_PAD_CTL_PAD_DRAM_RESET SW PAD Control Register, array offset: 0x204, array step: 0x4 */
       uint8_t RESERVED_1[68];
  __IO uint32_t SW_PAD_CTL_PAD[112];               /**< SW_PAD_CTL_PAD_JTAG_MOD SW PAD Control Register..SW_PAD_CTL_PAD_CSI_DATA07 SW PAD Control Register, array offset: 0x2D0, array step: 0x4 */
  __IO uint32_t SW_PAD_CTL_GRP[10];                /**< SW_PAD_CTL_GRP_ADDDS SW GRP Register..SW_PAD_CTL_GRP_DDR_TYPE SW GRP Register, array offset: 0x490, array step: 0x4 */
  __IO uint32_t SELECT_INPUT[122];                 /**< USB_OTG1_ID_SELECT_INPUT DAISY Register..USDHC2_WP_SELECT_INPUT DAISY Register, array offset: 0x4B8, array step: 0x4 */
} IOMUXC_Type;

/* ----------------------------------------------------------------------------
   -- IOMUXC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOMUXC_Register_Masks IOMUXC Register Masks
 * @{
 */

/*! @name SW_MUX_CTL_PAD - SW_MUX_CTL_PAD_JTAG_MOD SW MUX Control Register..SW_MUX_CTL_PAD_CSI_DATA07 SW MUX Control Register */
#define IOMUXC_SW_MUX_CTL_PAD_MUX_MODE_MASK      (0xFU)  /* Merged from fields with different position or width, of widths (3, 4), largest definition used */
#define IOMUXC_SW_MUX_CTL_PAD_MUX_MODE_SHIFT     (0U)
#define IOMUXC_SW_MUX_CTL_PAD_MUX_MODE(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_MUX_CTL_PAD_MUX_MODE_SHIFT)) & IOMUXC_SW_MUX_CTL_PAD_MUX_MODE_MASK)  /* Merged from fields with different position or width, of widths (3, 4), largest definition used */
#define IOMUXC_SW_MUX_CTL_PAD_SION_MASK          (0x10U)
#define IOMUXC_SW_MUX_CTL_PAD_SION_SHIFT         (4U)
#define IOMUXC_SW_MUX_CTL_PAD_SION(x)            (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_MUX_CTL_PAD_SION_SHIFT)) & IOMUXC_SW_MUX_CTL_PAD_SION_MASK)

/* The count of IOMUXC_SW_MUX_CTL_PAD */
#define IOMUXC_SW_MUX_CTL_PAD_COUNT              (112U)

/*! @name SW_PAD_CTL_PAD_DDR - SW_PAD_CTL_PAD_DRAM_ADDR00 SW PAD Control Register..SW_PAD_CTL_PAD_DRAM_RESET SW PAD Control Register */
#define IOMUXC_SW_PAD_CTL_PAD_DDR_DSE_MASK       (0x38U)
#define IOMUXC_SW_PAD_CTL_PAD_DDR_DSE_SHIFT      (3U)
#define IOMUXC_SW_PAD_CTL_PAD_DDR_DSE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_DDR_DSE_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_DDR_DSE_MASK)
#define IOMUXC_SW_PAD_CTL_PAD_DDR_ODT_MASK       (0x700U)
#define IOMUXC_SW_PAD_CTL_PAD_DDR_ODT_SHIFT      (8U)
#define IOMUXC_SW_PAD_CTL_PAD_DDR_ODT(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_DDR_ODT_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_DDR_ODT_MASK)
#define IOMUXC_SW_PAD_CTL_PAD_DDR_PKE_MASK       (0x1000U)
#define IOMUXC_SW_PAD_CTL_PAD_DDR_PKE_SHIFT      (12U)
#define IOMUXC_SW_PAD_CTL_PAD_DDR_PKE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_DDR_PKE_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_DDR_PKE_MASK)
#define IOMUXC_SW_PAD_CTL_PAD_DDR_PUE_MASK       (0x2000U)
#define IOMUXC_SW_PAD_CTL_PAD_DDR_PUE_SHIFT      (13U)
#define IOMUXC_SW_PAD_CTL_PAD_DDR_PUE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_DDR_PUE_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_DDR_PUE_MASK)
#define IOMUXC_SW_PAD_CTL_PAD_DDR_PUS_MASK       (0xC000U)
#define IOMUXC_SW_PAD_CTL_PAD_DDR_PUS_SHIFT      (14U)
#define IOMUXC_SW_PAD_CTL_PAD_DDR_PUS(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_DDR_PUS_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_DDR_PUS_MASK)
#define IOMUXC_SW_PAD_CTL_PAD_DDR_HYS_MASK       (0x10000U)
#define IOMUXC_SW_PAD_CTL_PAD_DDR_HYS_SHIFT      (16U)
#define IOMUXC_SW_PAD_CTL_PAD_DDR_HYS(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_DDR_HYS_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_DDR_HYS_MASK)
#define IOMUXC_SW_PAD_CTL_PAD_DDR_DDR_INPUT_MASK (0x20000U)
#define IOMUXC_SW_PAD_CTL_PAD_DDR_DDR_INPUT_SHIFT (17U)
#define IOMUXC_SW_PAD_CTL_PAD_DDR_DDR_INPUT(x)   (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_DDR_DDR_INPUT_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_DDR_DDR_INPUT_MASK)
#define IOMUXC_SW_PAD_CTL_PAD_DDR_DDR_SEL_MASK   (0xC0000U)
#define IOMUXC_SW_PAD_CTL_PAD_DDR_DDR_SEL_SHIFT  (18U)
#define IOMUXC_SW_PAD_CTL_PAD_DDR_DDR_SEL(x)     (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_DDR_DDR_SEL_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_DDR_DDR_SEL_MASK)
#define IOMUXC_SW_PAD_CTL_PAD_DDR_DO_TRIM_MASK   (0x300000U)
#define IOMUXC_SW_PAD_CTL_PAD_DDR_DO_TRIM_SHIFT  (20U)
#define IOMUXC_SW_PAD_CTL_PAD_DDR_DO_TRIM(x)     (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_DDR_DO_TRIM_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_DDR_DO_TRIM_MASK)
#define IOMUXC_SW_PAD_CTL_PAD_DDR_DO_TRIM_PADN_MASK (0x3000000U)
#define IOMUXC_SW_PAD_CTL_PAD_DDR_DO_TRIM_PADN_SHIFT (24U)
#define IOMUXC_SW_PAD_CTL_PAD_DDR_DO_TRIM_PADN(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_DDR_DO_TRIM_PADN_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_DDR_DO_TRIM_PADN_MASK)

/* The count of IOMUXC_SW_PAD_CTL_PAD_DDR */
#define IOMUXC_SW_PAD_CTL_PAD_DDR_COUNT          (34U)

/*! @name SW_PAD_CTL_PAD - SW_PAD_CTL_PAD_JTAG_MOD SW PAD Control Register..SW_PAD_CTL_PAD_CSI_DATA07 SW PAD Control Register */
#define IOMUXC_SW_PAD_CTL_PAD_SRE_MASK           (0x1U)
#define IOMUXC_SW_PAD_CTL_PAD_SRE_SHIFT          (0U)
#define IOMUXC_SW_PAD_CTL_PAD_SRE(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_SRE_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_SRE_MASK)
#define IOMUXC_SW_PAD_CTL_PAD_DSE_MASK           (0x38U)
#define IOMUXC_SW_PAD_CTL_PAD_DSE_SHIFT          (3U)
#define IOMUXC_SW_PAD_CTL_PAD_DSE(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_DSE_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_DSE_MASK)
#define IOMUXC_SW_PAD_CTL_PAD_SPEED_MASK         (0xC0U)
#define IOMUXC_SW_PAD_CTL_PAD_SPEED_SHIFT        (6U)
#define IOMUXC_SW_PAD_CTL_PAD_SPEED(x)           (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_SPEED_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_SPEED_MASK)
#define IOMUXC_SW_PAD_CTL_PAD_ODE_MASK           (0x800U)
#define IOMUXC_SW_PAD_CTL_PAD_ODE_SHIFT          (11U)
#define IOMUXC_SW_PAD_CTL_PAD_ODE(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_ODE_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_ODE_MASK)
#define IOMUXC_SW_PAD_CTL_PAD_PKE_MASK           (0x1000U)
#define IOMUXC_SW_PAD_CTL_PAD_PKE_SHIFT          (12U)
#define IOMUXC_SW_PAD_CTL_PAD_PKE(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_PKE_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_PKE_MASK)
#define IOMUXC_SW_PAD_CTL_PAD_PUE_MASK           (0x2000U)
#define IOMUXC_SW_PAD_CTL_PAD_PUE_SHIFT          (13U)
#define IOMUXC_SW_PAD_CTL_PAD_PUE(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_PUE_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_PUE_MASK)
#define IOMUXC_SW_PAD_CTL_PAD_PUS_MASK           (0xC000U)
#define IOMUXC_SW_PAD_CTL_PAD_PUS_SHIFT          (14U)
#define IOMUXC_SW_PAD_CTL_PAD_PUS(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_PUS_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_PUS_MASK)
#define IOMUXC_SW_PAD_CTL_PAD_HYS_MASK           (0x10000U)
#define IOMUXC_SW_PAD_CTL_PAD_HYS_SHIFT          (16U)
#define IOMUXC_SW_PAD_CTL_PAD_HYS(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_HYS_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_HYS_MASK)

/* The count of IOMUXC_SW_PAD_CTL_PAD */
#define IOMUXC_SW_PAD_CTL_PAD_COUNT              (112U)

/*! @name SW_PAD_CTL_GRP - SW_PAD_CTL_GRP_ADDDS SW GRP Register..SW_PAD_CTL_GRP_DDR_TYPE SW GRP Register */
#define IOMUXC_SW_PAD_CTL_GRP_DSE_MASK           (0x38U)
#define IOMUXC_SW_PAD_CTL_GRP_DSE_SHIFT          (3U)
#define IOMUXC_SW_PAD_CTL_GRP_DSE(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_GRP_DSE_SHIFT)) & IOMUXC_SW_PAD_CTL_GRP_DSE_MASK)
#define IOMUXC_SW_PAD_CTL_GRP_PKE_MASK           (0x1000U)
#define IOMUXC_SW_PAD_CTL_GRP_PKE_SHIFT          (12U)
#define IOMUXC_SW_PAD_CTL_GRP_PKE(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_GRP_PKE_SHIFT)) & IOMUXC_SW_PAD_CTL_GRP_PKE_MASK)
#define IOMUXC_SW_PAD_CTL_GRP_PUE_MASK           (0x2000U)
#define IOMUXC_SW_PAD_CTL_GRP_PUE_SHIFT          (13U)
#define IOMUXC_SW_PAD_CTL_GRP_PUE(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_GRP_PUE_SHIFT)) & IOMUXC_SW_PAD_CTL_GRP_PUE_MASK)
#define IOMUXC_SW_PAD_CTL_GRP_HYS_MASK           (0x10000U)
#define IOMUXC_SW_PAD_CTL_GRP_HYS_SHIFT          (16U)
#define IOMUXC_SW_PAD_CTL_GRP_HYS(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_GRP_HYS_SHIFT)) & IOMUXC_SW_PAD_CTL_GRP_HYS_MASK)
#define IOMUXC_SW_PAD_CTL_GRP_DDR_INPUT_MASK     (0x20000U)
#define IOMUXC_SW_PAD_CTL_GRP_DDR_INPUT_SHIFT    (17U)
#define IOMUXC_SW_PAD_CTL_GRP_DDR_INPUT(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_GRP_DDR_INPUT_SHIFT)) & IOMUXC_SW_PAD_CTL_GRP_DDR_INPUT_MASK)
#define IOMUXC_SW_PAD_CTL_GRP_DDR_SEL_MASK       (0xC0000U)
#define IOMUXC_SW_PAD_CTL_GRP_DDR_SEL_SHIFT      (18U)
#define IOMUXC_SW_PAD_CTL_GRP_DDR_SEL(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_GRP_DDR_SEL_SHIFT)) & IOMUXC_SW_PAD_CTL_GRP_DDR_SEL_MASK)

/* The count of IOMUXC_SW_PAD_CTL_GRP */
#define IOMUXC_SW_PAD_CTL_GRP_COUNT              (10U)

/*! @name SELECT_INPUT - USB_OTG1_ID_SELECT_INPUT DAISY Register..USDHC2_WP_SELECT_INPUT DAISY Register */
#define IOMUXC_SELECT_INPUT_DAISY_MASK           (0x7U)  /* Merged from fields with different position or width, of widths (1, 2, 3), largest definition used */
#define IOMUXC_SELECT_INPUT_DAISY_SHIFT          (0U)
#define IOMUXC_SELECT_INPUT_DAISY(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC_SELECT_INPUT_DAISY_SHIFT)) & IOMUXC_SELECT_INPUT_DAISY_MASK)  /* Merged from fields with different position or width, of widths (1, 2, 3), largest definition used */

/* The count of IOMUXC_SELECT_INPUT */
#define IOMUXC_SELECT_INPUT_COUNT                (122U)


/*!
 * @}
 */ /* end of group IOMUXC_Register_Masks */


/* IOMUXC - Peripheral instance base addresses */
/** Peripheral IOMUXC base address */
#define IOMUXC_BASE                              (0x20E0000u)
/** Peripheral IOMUXC base pointer */
#define IOMUXC                                   ((IOMUXC_Type *)IOMUXC_BASE)
/** Array initializer of IOMUXC peripheral base addresses */
#define IOMUXC_BASE_ADDRS                        { IOMUXC_BASE }
/** Array initializer of IOMUXC peripheral base pointers */
#define IOMUXC_BASE_PTRS                         { IOMUXC }

/*!
 * @}
 */ /* end of group IOMUXC_Peripheral_Access_Layer */