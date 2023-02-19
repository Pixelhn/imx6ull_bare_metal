#include <stdio.h>
#include <stdint.h>
#include "../ebf_linux_uboot/include/imximage.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define ENTRY 0x87800000

#define CC(x) (x << 8) | (x >> 8)

int main(int argc, char *argv[])
{
    int fd = -1;
    flash_header_v2_t   head;
    boot_data_t         bd;
    dcd_v2_t            dcd;

    fd = open(argv[1], O_RDONLY);
    if (fd <= 0)
        return -1;

    read(fd, &head, sizeof(flash_header_v2_t));

    printf("%d\n", head.header.length);

    printf("self        %X\n", head.self);
    printf("boot data   %X\n", head.boot_data_ptr);
    printf("DCD         %X\n", head.dcd_ptr);
    printf("entry       %X\n", head.entry);

    lseek(fd, head.boot_data_ptr - head.self, SEEK_SET);
    read(fd, &bd, sizeof(boot_data_t));

    printf("bd start  %X\n", bd.start);
    printf("bd size   %d\n", bd.size);
    printf("bd plugin %X\n", bd.plugin);

    lseek(fd, head.dcd_ptr - head.self, SEEK_SET);
    read(fd, &dcd, sizeof(dcd_v2_t));

    printf("dcd %X\n", dcd.header.tag);
    printf("dcd %X\n", dcd.header.version);
    dcd.header.length = CC(dcd.header.length);
    printf("dcd %d\n", dcd.header.length);

    close(fd);
    return 0;
}
