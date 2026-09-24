#include <itzamna/unistd.h>

#include "../arch/x86_64/syscall.h"

ssize_t itz_write(int fd, const void *buf, size_t nbytes)
{
    return itz_syscall3(SYS_write, fd, (long)buf, (long)nbytes);
}
