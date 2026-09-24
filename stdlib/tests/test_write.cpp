#include <sys/types.h>

#include <cstddef>

#include <itzamna/unistd.h>

void test_write(int descriptor, const void *buf, size_t nbytes)
{
    itz_write(descriptor, buf, nbytes);
}

int main()
{
    char c = 'c';
    test_write(1, &c, 1);
}
