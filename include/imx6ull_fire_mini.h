#include "cc.h"
#include "io/io.h"
#include "irq/irq.h"
#include "ccm/ccm.h"

#include "gpio.h"


#define SW2_KEY     IOMUXC_SNVS_SNVS_TAMPER1_GPIO5_IO01

#define D4_LED      IOMUXC_GPIO1_IO04_GPIO1_IO04
#define D5_LED      IOMUXC_CSI_HSYNC_GPIO4_IO20
#define D6_LED      IOMUXC_CSI_VSYNC_GPIO4_IO19
#define D7_LED      IOMUXC_SNVS_SNVS_TAMPER3_GPIO5_IO03