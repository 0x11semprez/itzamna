#include <sys/types.h>

#include <cstddef>

extern "C" {
#include "../../include/syscstd.h"
}

void test_write(int descriptor, const void *buf, size_t nbytes)
{
    write(descriptor, buf, nbytes);
}

int main()
{
    char c = 'c';
    test_write(1, &c, 1);
}
