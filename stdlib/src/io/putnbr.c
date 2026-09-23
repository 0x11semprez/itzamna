#include <itzamna/io.h>
#include <itzamna/unistd.h>

void itz_putnbr(ssize_t n)
{
    /* Work on the magnitude as unsigned so SSIZE_MIN does not overflow. */
    size_t u = (size_t)n;
    char c;

    if (n < 0) {
        itz_write(1, "-", 1);
        u = -u;
    }

    if (u >= 10) {
        itz_putnbr((ssize_t)(u / 10));
    }

    c = (char)(u % 10 + '0');
    itz_write(1, &c, 1);
}
