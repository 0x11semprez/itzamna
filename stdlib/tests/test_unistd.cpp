#include <cerrno>
#include <cstring>

#include <unistd.h>

#include <itzamna/unistd.h>

#include "check.hpp"

static void test_write_then_read_through_pipe()
{
    int fds[2];
    CHECK_EQ(pipe(fds), 0);

    const char msg[] = "hello";
    CHECK_EQ(itz_write(fds[1], msg, 5), 5);

    char buf[8] = {};
    CHECK_EQ(itz_read(fds[0], buf, sizeof(buf)), 5);
    CHECK(std::memcmp(buf, msg, 5) == 0);

    close(fds[0]);
    close(fds[1]);
}

static void test_read_zero_bytes()
{
    int fds[2];
    CHECK_EQ(pipe(fds), 0);

    char c = 'x';
    CHECK_EQ(itz_read(fds[0], &c, 0), 0);
    CHECK_EQ(c, 'x');

    close(fds[0]);
    close(fds[1]);
}

static void test_read_eof()
{
    int fds[2];
    CHECK_EQ(pipe(fds), 0);
    close(fds[1]);

    char c;
    CHECK_EQ(itz_read(fds[0], &c, 1), 0);

    close(fds[0]);
}

static void test_bad_fd_returns_negative_errno()
{
    char c = 'x';
    CHECK_EQ(itz_write(-1, &c, 1), -EBADF);
    CHECK_EQ(itz_read(-1, &c, 1), -EBADF);
}

int main()
{
    test_write_then_read_through_pipe();
    test_read_zero_bytes();
    test_read_eof();
    test_bad_fd_returns_negative_errno();
    return itz_test_result();
}
