#include <limits>
#include <string>

#include <sys/types.h>
#include <unistd.h>

#include <itzamna/io.h>

#include "check.hpp"

// Run itz_putnbr with stdout redirected into a pipe and return what it printed.
static std::string capture_putnbr(ssize_t n)
{
    int fds[2];
    if (pipe(fds) != 0) {
        return "<pipe failed>";
    }

    int saved = dup(1);
    dup2(fds[1], 1);
    close(fds[1]);

    itz_putnbr(n);

    dup2(saved, 1);
    close(saved);

    std::string out;
    char buf[64];
    ssize_t got;
    while ((got = read(fds[0], buf, sizeof(buf))) > 0) {
        out.append(buf, static_cast<size_t>(got));
    }
    close(fds[0]);
    return out;
}

static void test_putnbr_small()
{
    CHECK_EQ(capture_putnbr(0), std::string("0"));
    CHECK_EQ(capture_putnbr(7), std::string("7"));
    CHECK_EQ(capture_putnbr(-5), std::string("-5"));
}

static void test_putnbr_multi_digit()
{
    CHECK_EQ(capture_putnbr(10), std::string("10"));
    CHECK_EQ(capture_putnbr(123), std::string("123"));
    CHECK_EQ(capture_putnbr(-45), std::string("-45"));
}

static void test_putnbr_limits()
{
    CHECK_EQ(capture_putnbr(std::numeric_limits<ssize_t>::max()),
             std::string("9223372036854775807"));
    CHECK_EQ(capture_putnbr(std::numeric_limits<ssize_t>::min()),
             std::string("-9223372036854775808"));
}

int main()
{
    test_putnbr_small();
    test_putnbr_multi_digit();
    test_putnbr_limits();
    return itz_test_result();
}
