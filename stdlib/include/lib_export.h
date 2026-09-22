#ifndef LIB_EXPORT_H
#define LIB_EXPORT_H

#ifdef __cplusplus
#define LIB_EXPORT_BEGIN extern "C" {
#define LIB_EXPORT_END }
#else
#define LIB_EXPORT_BEGIN
#define LIB_EXPORT_END
#endif

#endif
