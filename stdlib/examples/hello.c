#include <itzamna/io.h>
#include <itzamna/string.h>
#include <itzamna/unistd.h>

int main(void)
{
    const char str[] = "ifijrfr";

    itz_putnbr((ssize_t)itz_strlen(str));
    itz_write(1, "\n", 1);
    return 0;
}
