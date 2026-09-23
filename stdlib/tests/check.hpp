#ifndef ITZAMNA_TESTS_CHECK_HPP
#define ITZAMNA_TESTS_CHECK_HPP

#include <iostream>

// Minimal assertion helper: report every failure, keep running,
// and let main() turn the count into the process exit code.
inline int itz_failures = 0;

#define CHECK(expr)                                                      \
    do {                                                                 \
        if (!(expr)) {                                                   \
            std::cerr << __FILE__ << ":" << __LINE__ << ": CHECK failed: " \
                      << #expr << '\n';                                  \
            itz_failures++;                                              \
        }                                                                \
    } while (0)

#define CHECK_EQ(actual, expected)                                       \
    do {                                                                 \
        auto itz_a = (actual);                                           \
        auto itz_e = (expected);                                         \
        if (!(itz_a == itz_e)) {                                         \
            std::cerr << __FILE__ << ":" << __LINE__ << ": CHECK_EQ failed: " \
                      << #actual << " == " << #expected << " (got '"     \
                      << itz_a << "', expected '" << itz_e << "')\n";    \
            itz_failures++;                                              \
        }                                                                \
    } while (0)

inline int itz_test_result()
{
    return itz_failures == 0 ? 0 : 1;
}

#endif
