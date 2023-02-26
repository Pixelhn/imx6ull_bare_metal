# MUX
//引脚复用

IOMUXC_SW_MUX_CTL_PAD_*

0-3 ALT*
4   SION

# PAD
//IO属性
IOMUXC_SW_PAD_CTL_PAD_*

0       1   SRE     压摆率 0低 1高
1-2     2
3-5     3   DSE     IO驱动能力
6-7     2   SPEED   IO速度
8-10    3
11      1   ODE     开路输出（输出）
12      1   PKE     使能或禁止PUE PUS
13      1   PUE     保持器（输入）
14-15   2   PUS     上下拉电阻
16      1   HYS     迟滞比较器
17-31   16


# CCM
时钟控制
CCM_CCGR0 -- CCM_CCGR6
2位



## 
ADC_Peripheral_Access_Layer
ADC_5HC_Peripheral_Access_Layer

AIPSTZ_Peripheral_Access_Layer
APBH_Peripheral_Access_Layer


CAN_Peripheral_Access_Layer
CCM_Peripheral_Access_Layer //时钟