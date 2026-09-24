#include <sys/types.h>

#include <cstddef>
#include <iostream>

#include <itzamna/unistd.h>

using namespace std;

void test_read(int descriptor, void *buf, size_t nbytes)
{
    itz_read(descriptor, buf, nbytes);
}

int main()
{
    char c;
    test_read(0, &c, 1);
    cout << c << endl;
}
