#ifndef ITZAMNA_EXPORT_H
#define ITZAMNA_EXPORT_H

/* Give public declarations C linkage when included from C++. */
#ifdef __cplusplus
#define ITZ_BEGIN_DECLS extern "C" {
#define ITZ_END_DECLS }
#else
#define ITZ_BEGIN_DECLS
#define ITZ_END_DECLS
#endif

#endif
