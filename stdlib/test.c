#include <sys/types.h>

#include "include/string.h"
#include "include/syscstd.h"

int main(void)
{
    char c[] = "ifijrfr";
    size_t da = strlen(c);

    putnbr(da);
    write(1, "\n", 1);
    return 0;
}
