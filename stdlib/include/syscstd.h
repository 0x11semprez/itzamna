#include <sys/syscall.h>
#include <sys/types.h>

#include "lib_export.h"
#ifndef SYSCSTD_H
#define SYSCSTD_H

LIB_EXPORT_BEGIN
ssize_t write(int descriptors, const void *buf, size_t bytes);
ssize_t read(int descriptors, void *buf, size_t nbytes);
LIB_EXPORT_END

#endif
