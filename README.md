# IMX6ULL  bare_metal

裸机开发

ARMv7架构学习


## 目录结构

***build***
打包工具与脚本

其中mkimage与u-boot-dtb.cfgout来自imx6ull的uboot，参考uboot内.imx生成过程，为程序添加IVT、Boot Data、DCD头部3Kb内容

```
./tools/mkimage -n u-boot-dtb.cfgout -T imximage -e 0x87800000 -d led.bin boot.imx
```

生成的boot.img镜像可直接烧写至sd卡启动裸机程序


***SDK_2.2_MCIM6ULL***
官方SDK

