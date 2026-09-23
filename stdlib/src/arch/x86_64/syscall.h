#ifndef ITZAMNA_ARCH_SYSCALL_H
#define ITZAMNA_ARCH_SYSCALL_H

#include <sys/syscall.h>

/*
 * Raw Linux x86_64 syscall entry points.
 * Arguments go in rdi, rsi, rdx; the kernel clobbers rcx and r11.
 */

static inline long itz_syscall1(long n, long a1)
{
    long ret;

    __asm__ volatile("syscall"
                     : "=a"(ret)
                     : "a"(n), "D"(a1)
                     : "rcx", "r11", "memory");
    return ret;
}

static inline long itz_syscall2(long n, long a1, long a2)
{
    long ret;

    __asm__ volatile("syscall"
                     : "=a"(ret)
                     : "a"(n), "D"(a1), "S"(a2)
                     : "rcx", "r11", "memory");
    return ret;
}

static inline long itz_syscall3(long n, long a1, long a2, long a3)
{
    long ret;

    __asm__ volatile("syscall"
                     : "=a"(ret)
                     : "a"(n), "D"(a1), "S"(a2), "d"(a3)
                     : "rcx", "r11", "memory");
    return ret;
}

#endif
