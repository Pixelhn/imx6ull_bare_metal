CROSS=arm-none-eabi-

CC=$(CROSS)gcc
LD=$(CROSS)ld
OBJCOPY=$(CROSS)objcopy
OBJDUMP=$(CROSS)objdump

main.bin:main.elf
	$(OBJCOPY) -O binary -S -g $+ $@
	$(OBJDUMP) -D $+ > $@.dis

main.elf:start.o main.o
	$(LD) -Ttext 0X87800000 $+ -o $@ -Map $@.map

main.o:main.c
	$(CC) -g -c $+ -o $@

start.o:start.s
	$(CC) -g -c $+ -o $@


clean:
	rm *.o *.elf *.bin *map *.dis