#include "../../include/linuxsys/read.h"

ssize_t read(int descriptors, void *buf, size_t nbytes)
{
    long value;

    __asm__ volatile("syscall"
                     : "=a"(value)
                     : "a"(0L), "D"((long)descriptors), "S"(buf), "d"(nbytes)
                     : "rcx", "r11", "memory");
    return value;
}
