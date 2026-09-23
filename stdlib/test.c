#include <sys/types.h>

#include "include/string.h"
#include "include/syscstd.h"

int main(void)
{
    char c[] = "ifijrfr";
    int da = strlen(c);

    write(1, &da, 1);
    return 0;
}
