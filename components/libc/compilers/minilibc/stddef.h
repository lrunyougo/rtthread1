#ifndef __STDDEF_H__
#define __STDDEF_H__

#include <sys/types.h>
typedef signed long ptrdiff_t;
#define offsetof(s,m) ((unsigned)&(((s *)0)->m))
#endif
