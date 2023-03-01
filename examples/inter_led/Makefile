CROSS=arm-none-eabi-

CC=$(CROSS)gcc
LD=$(CROSS)ld
OBJCOPY=$(CROSS)objcopy
OBJDUMP=$(CROSS)objdump

INCLUDR+= -I ../../include
INCLUDR+= -I ../../lib/include

DRIVER := 	../../driver/gpio/gpio.c \
			../../driver/clk/clk.c \
			../../driver/epit/epit.c \

main.bin:main.elf
	$(OBJCOPY) -O binary -S -g $+ $@
	$(OBJDUMP) -D $+ > $@.dis

main.elf:start.o main.o moto.o irq_table.o gpio.o clk.o epit.o 
	$(LD) -T../../boot/imx6ull.lds $+ -o $@ -Map $@.map

main.o:main.c 
	$(CC) -g -c $+ -o $@ $(INCLUDR) 

moto.o:moto.c 
	$(CC) -g -c $+ -o $@ $(INCLUDR) 

#lib
irq_table.o:../../lib/irq_table.c
	$(CC) -g -c $+ -o $@ $(INCLUDR) -march=armv7-a

#driver
gpio.o:../../driver/gpio/gpio.c
	$(CC) -g -c $+ -o $@ $(INCLUDR) -march=armv7-a

clk.o:../../driver/clk/clk.c
	$(CC) -g -c $+ -o $@ $(INCLUDR) -march=armv7-a

epit.o:../../driver/epit/epit.c
	$(CC) -g -c $+ -o $@ $(INCLUDR) -march=armv7-a

#boot
start.o:../../boot/start.s
	$(CC) -g -c $+ -o $@


clean:
	rm *.o *.elf *.bin *map *.dis