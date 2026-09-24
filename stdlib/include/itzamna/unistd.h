#ifndef ITZAMNA_UNISTD_H
#define ITZAMNA_UNISTD_H

#include <itzamna/export.h>
#include <stddef.h>
#include <sys/types.h>

ITZ_BEGIN_DECLS

ssize_t itz_read(int fd, void *buf, size_t nbytes);
ssize_t itz_write(int fd, const void *buf, size_t nbytes);

ITZ_END_DECLS

#endif
