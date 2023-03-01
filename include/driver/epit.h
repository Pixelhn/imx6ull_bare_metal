#ifndef __EPIT_H__
#define __EPIT_H__



/* ----------------------------------------------------------------------------
   -- EPIT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EPIT_Peripheral_Access_Layer EPIT Peripheral Access Layer
 * @{
 */

/** EPIT - Register Layout Typedef */
typedef struct {
  __IO uint32_t CR;                                /**< Control register, offset: 0x0 */
  __IO uint32_t SR;                                /**< Status register, offset: 0x4 */
  __IO uint32_t LR;                                /**< Load register, offset: 0x8 */
  __IO uint32_t CMPR;                              /**< Compare register, offset: 0xC */
  __I  uint32_t CNR;                               /**< Counter register, offset: 0x10 */
} EPIT_Type;

/* ----------------------------------------------------------------------------
   -- EPIT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EPIT_Register_Masks EPIT Register Masks
 * @{
 */

/*! @name CR - Control register */
#define EPIT_CR_EN_MASK                          (0x1U)
#define EPIT_CR_EN_SHIFT                         (0U)
#define EPIT_CR_EN(x)                            (((uint32_t)(((uint32_t)(x)) << EPIT_CR_EN_SHIFT)) & EPIT_CR_EN_MASK)
#define EPIT_CR_ENMOD_MASK                       (0x2U)
#define EPIT_CR_ENMOD_SHIFT                      (1U)
#define EPIT_CR_ENMOD(x)                         (((uint32_t)(((uint32_t)(x)) << EPIT_CR_ENMOD_SHIFT)) & EPIT_CR_ENMOD_MASK)
#define EPIT_CR_OCIEN_MASK                       (0x4U)
#define EPIT_CR_OCIEN_SHIFT                      (2U)
#define EPIT_CR_OCIEN(x)                         (((uint32_t)(((uint32_t)(x)) << EPIT_CR_OCIEN_SHIFT)) & EPIT_CR_OCIEN_MASK)
#define EPIT_CR_RLD_MASK                         (0x8U)
#define EPIT_CR_RLD_SHIFT                        (3U)
#define EPIT_CR_RLD(x)                           (((uint32_t)(((uint32_t)(x)) << EPIT_CR_RLD_SHIFT)) & EPIT_CR_RLD_MASK)
#define EPIT_CR_PRESCALAR_MASK                   (0xFFF0U)
#define EPIT_CR_PRESCALAR_SHIFT                  (4U)
#define EPIT_CR_PRESCALAR(x)                     (((uint32_t)(((uint32_t)(x)) << EPIT_CR_PRESCALAR_SHIFT)) & EPIT_CR_PRESCALAR_MASK)
#define EPIT_CR_SWR_MASK                         (0x10000U)
#define EPIT_CR_SWR_SHIFT                        (16U)
#define EPIT_CR_SWR(x)                           (((uint32_t)(((uint32_t)(x)) << EPIT_CR_SWR_SHIFT)) & EPIT_CR_SWR_MASK)
#define EPIT_CR_IOVW_MASK                        (0x20000U)
#define EPIT_CR_IOVW_SHIFT                       (17U)
#define EPIT_CR_IOVW(x)                          (((uint32_t)(((uint32_t)(x)) << EPIT_CR_IOVW_SHIFT)) & EPIT_CR_IOVW_MASK)
#define EPIT_CR_DBGEN_MASK                       (0x40000U)
#define EPIT_CR_DBGEN_SHIFT                      (18U)
#define EPIT_CR_DBGEN(x)                         (((uint32_t)(((uint32_t)(x)) << EPIT_CR_DBGEN_SHIFT)) & EPIT_CR_DBGEN_MASK)
#define EPIT_CR_WAITEN_MASK                      (0x80000U)
#define EPIT_CR_WAITEN_SHIFT                     (19U)
#define EPIT_CR_WAITEN(x)                        (((uint32_t)(((uint32_t)(x)) << EPIT_CR_WAITEN_SHIFT)) & EPIT_CR_WAITEN_MASK)
#define EPIT_CR_STOPEN_MASK                      (0x200000U)
#define EPIT_CR_STOPEN_SHIFT                     (21U)
#define EPIT_CR_STOPEN(x)                        (((uint32_t)(((uint32_t)(x)) << EPIT_CR_STOPEN_SHIFT)) & EPIT_CR_STOPEN_MASK)
#define EPIT_CR_OM_MASK                          (0xC00000U)
#define EPIT_CR_OM_SHIFT                         (22U)
#define EPIT_CR_OM(x)                            (((uint32_t)(((uint32_t)(x)) << EPIT_CR_OM_SHIFT)) & EPIT_CR_OM_MASK)
#define EPIT_CR_CLKSRC_MASK                      (0x3000000U)
#define EPIT_CR_CLKSRC_SHIFT                     (24U)
#define EPIT_CR_CLKSRC(x)                        (((uint32_t)(((uint32_t)(x)) << EPIT_CR_CLKSRC_SHIFT)) & EPIT_CR_CLKSRC_MASK)

/*! @name SR - Status register */
#define EPIT_SR_OCIF_MASK                        (0x1U)
#define EPIT_SR_OCIF_SHIFT                       (0U)
#define EPIT_SR_OCIF(x)                          (((uint32_t)(((uint32_t)(x)) << EPIT_SR_OCIF_SHIFT)) & EPIT_SR_OCIF_MASK)

/*! @name LR - Load register */
#define EPIT_LR_LOAD_MASK                        (0xFFFFFFFFU)
#define EPIT_LR_LOAD_SHIFT                       (0U)
#define EPIT_LR_LOAD(x)                          (((uint32_t)(((uint32_t)(x)) << EPIT_LR_LOAD_SHIFT)) & EPIT_LR_LOAD_MASK)

/*! @name CMPR - Compare register */
#define EPIT_CMPR_COMPARE_MASK                   (0xFFFFFFFFU)
#define EPIT_CMPR_COMPARE_SHIFT                  (0U)
#define EPIT_CMPR_COMPARE(x)                     (((uint32_t)(((uint32_t)(x)) << EPIT_CMPR_COMPARE_SHIFT)) & EPIT_CMPR_COMPARE_MASK)

/*! @name CNR - Counter register */
#define EPIT_CNR_COUNT_MASK                      (0xFFFFFFFFU)
#define EPIT_CNR_COUNT_SHIFT                     (0U)
#define EPIT_CNR_COUNT(x)                        (((uint32_t)(((uint32_t)(x)) << EPIT_CNR_COUNT_SHIFT)) & EPIT_CNR_COUNT_MASK)


/*!
 * @}
 */ /* end of group EPIT_Register_Masks */


/* EPIT - Peripheral instance base addresses */
/** Peripheral EPIT1 base address */
#define EPIT1_BASE                               (0x20D0000u)
/** Peripheral EPIT1 base pointer */
#define EPIT1                                    ((EPIT_Type *)EPIT1_BASE)
/** Peripheral EPIT2 base address */
#define EPIT2_BASE                               (0x20D4000u)
/** Peripheral EPIT2 base pointer */
#define EPIT2                                    ((EPIT_Type *)EPIT2_BASE)
/** Array initializer of EPIT peripheral base addresses */
#define EPIT_BASE_ADDRS                          { 0u, EPIT1_BASE, EPIT2_BASE }
/** Array initializer of EPIT peripheral base pointers */
#define EPIT_BASE_PTRS                           { (EPIT_Type *)0u, EPIT1, EPIT2 }
/** Interrupt vectors for the EPIT peripheral type */
#define EPIT_IRQS                                { NotAvail_IRQn, EPIT1_IRQn, EPIT2_IRQn }

/*!
 * @}
 */ /* end of group EPIT_Peripheral_Access_Layer */

#endif