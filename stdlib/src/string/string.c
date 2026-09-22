#include "../../include/string.h"

#include <sys/types.h>

#include "../../include/syscstd.h"

void putnbr(ssize_t n)
{
    char c;

    if (n < 0) {
        write(1, "-", 1);
        n = -n;
    }

    if (n >= 10) {
        n /= 10;
    }

    c = n % 10 + '0';
    write(1, &c, 1);
}

size_t strlen(const char str[])
{
    size_t counter_of_char = 0;
    while (str[counter_of_char] != '\0') {
        counter_of_char++;
    }

    return counter_of_char;
}
