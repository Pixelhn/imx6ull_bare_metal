CROSS=arm-none-eabi-

CC=$(CROSS)gcc
LD=$(CROSS)ld
OBJCOPY=$(CROSS)objcopy
OBJDUMP=$(CROSS)objdump

INCLUDR+=../../include

main.bin:main.elf
	$(OBJCOPY) -O binary -S -g $+ $@
	$(OBJDUMP) -D $+ > $@.dis

main.elf:start.o main.o button.o
	$(LD) -Tlds $+ -o $@ -Map $@.map

main.o:main.c
	$(CC) -g -c $+ -o $@ -I $(INCLUDR) 

button.o:button.c
	$(CC) -g -c $+ -o $@ -I $(INCLUDR) 

start.o:start.s
	$(CC) -g -c $+ -o $@


clean:
	rm *.o *.elf *.bin *map *.dis