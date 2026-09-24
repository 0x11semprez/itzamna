#include <cstddef>

#include <itzamna/string.h>

#include "check.hpp"

static void test_strlen()
{
    CHECK_EQ(itz_strlen(""), static_cast<size_t>(0));
    CHECK_EQ(itz_strlen("a"), static_cast<size_t>(1));
    CHECK_EQ(itz_strlen("ifijrfr"), static_cast<size_t>(7));
}

static void test_strlen_stops_at_first_nul()
{
    const char str[] = "ab\0cd";
    CHECK_EQ(itz_strlen(str), static_cast<size_t>(2));
}

int main()
{
    test_strlen();
    test_strlen_stops_at_first_nul();
    return itz_test_result();
}
