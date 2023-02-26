CROSS=arm-none-eabi-

CC=$(CROSS)gcc
LD=$(CROSS)ld
OBJCOPY=$(CROSS)objcopy
OBJDUMP=$(CROSS)objdump

INCLUDR+=../../include

main.bin:main.elf
	$(OBJCOPY) -O binary -S -g $+ $@
	$(OBJDUMP) -D $+ > $@.dis

main.elf:start.o main.o irq_table.o gpio.o clk.o
	$(LD) -T../../boot/imx6ull.lds $+ -o $@ -Map $@.map

main.o:main.c
	$(CC) -g -c $+ -o $@ -I $(INCLUDR) 

irq_table.o:irq_table.c
	$(CC) -g -c $+ -o $@ -I $(INCLUDR) -march=armv7-a

gpio.o:../../driver/gpio/gpio.c
	$(CC) -g -c $+ -o $@ -I $(INCLUDR) -march=armv7-a

clk.o:../../driver/clk/clk.c
	$(CC) -g -c $+ -o $@ -I $(INCLUDR) -march=armv7-a

start.o:../../boot/start.s
	$(CC) -g -c $+ -o $@


clean:
	rm *.o *.elf *.bin *map *.dis