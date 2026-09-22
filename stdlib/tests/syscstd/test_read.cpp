#include <sys/types.h>

#include <cstddef>
#include <iostream>

using namespace std;

extern "C" {
#include "../../include/syscstd.h"
}

void test_read(int descriptor, void *buf, size_t nbytes)
{
    read(descriptor, buf, nbytes);
}

int main()
{
    char c;
    test_read(1, &c, 1);
    cout << c << endl;
}
