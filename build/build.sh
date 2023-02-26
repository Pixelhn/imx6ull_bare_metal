#!/bin/bash


BOOT_BIN=boot.img

if [ -z $1 ];
then
    echo "input error!"
    exit
fi

if [ $1 = "clear" ];
then
    rm *.imx *.img
    exit
fi

./mkimage -n u-boot-dtb.cfgout -T imximage -e 0x87800000 -d $1 boot.imx || exit

dd if=/dev/zero of=boot.img bs=1M count=1

parted -s ${BOOT_BIN} mklabel msdos


dd if=boot.imx of=boot.img bs=512 seek=2 conv=notrunc

if [ -b $2 ];
then
    sudo dd if=boot.img of=/dev/sda
    sync
fi