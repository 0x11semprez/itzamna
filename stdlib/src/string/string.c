#include "../../include/string.h"

#include <sys/types.h>

#include <itzamna/unistd.h>

void putnbr(ssize_t n)
{
    size_t u = (size_t)n;
    char c;

    if (n < 0) {
        itz_write(1, "-", 1);
        u = -u;
    }

    if (u >= 10) {
        putnbr((ssize_t)(u / 10));
    }

    c = u % 10 + '0';
    itz_write(1, &c, 1);
}

size_t strlen(const char str[])
{
    size_t counter_of_char = 0;
    while (str[counter_of_char] != '\0') {
        counter_of_char++;
    }

    return counter_of_char;
}
