#!/bin/bash


BOOT_BIN=boot.bin

if [ -z $1 ];
then
    echo "input error!"
    exit
fi

./mkimage -n u-boot-dtb.cfgout -T imximage -e 0x87800000 -d $1 boot.imx || exit

dd if=/dev/zero of=boot.bin bs=1M count=1

parted -s ${BOOT_BIN} mklabel msdos


dd if=boot.imx of=boot.bin bs=512 seek=2 conv=notrunc
