#ifndef SPYRO_SOURCE_POOL_H
#define SPYRO_SOURCE_POOL_H

#include <dolphin/types.h>

template <class T0>
class Pool {
public:
    class Fragment;
    void Deinit(void);
    void Init(int, int);
    void Free(T0 *);
    void Alloc(int);
    void Merge(Fragment **);
};

#endif  // SPYRO_SOURCE_POOL_H
