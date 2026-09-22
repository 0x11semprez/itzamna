#include <sys/types.h>

#include "lib_export.h"

#ifndef STRING_H
#define STRING_H

LIB_EXPORT_BEGIN
void putnbr(ssize_t n);
size_t strlen(const char str[]);
LIB_EXPORT_END

#endif
