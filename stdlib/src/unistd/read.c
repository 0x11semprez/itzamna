#include <itzamna/unistd.h>

#include "arch/x86_64/syscall.h"

ssize_t itz_read(int fd, void *buf, size_t nbytes)
{
    return itz_syscall3(SYS_read, fd, (long)buf, (long)nbytes);
}
