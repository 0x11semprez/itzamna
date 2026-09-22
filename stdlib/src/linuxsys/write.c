#include "../../include/linuxsys/write.h"

#include <sys/syscall.h>

ssize_t write(int descriptors, const void *buf, size_t nbytes)
{
    long value;

    __asm__ volatile("syscall"
                     : "=a"(value)
                     : "a"(1L), "D"((long)descriptors), "S"(buf), "d"(nbytes)
                     : "rcx", "r11", "memory");
    return value;
}
