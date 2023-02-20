CROSS=arm-none-eabi-

CC=$(CROSS)gcc
LD=$(CROSS)ld
OBJCOPY=$(CROSS)objcopy
OBJDUMP=$(CROSS)objdump

led.bin:led.elf
	$(OBJCOPY) -O binary -S -g $+ $@
	$(OBJDUMP) -D $+ > $@.dis

led.elf:led.o
	$(LD) -Ttext 0X87800000 $+ -o $@ -Map $@.map

led.o:led.s
	$(CC) -g -c $+ -o $@


clean:
	rm *.o *.elf *.bin