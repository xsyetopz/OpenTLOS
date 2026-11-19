#ifndef COMMON_SOURCE_MKSTRINGCACHE_H
#define COMMON_SOURCE_MKSTRINGCACHE_H

#include <dolphin/types.h>

class MKHeap;
class MKStringCache;

class MKStringCache {
public:
    MKHeap * GetUsedLength(void);
    MKStringCache * Add(const char *);
    MKStringCache * Find(const char *);
    void Optimise(void);
    void Init(int);
    void Destroy(void);
    MKStringCache * Create(int);
    /* 0x000 */ s8 unk0;
    /* 0x001 */ s8 unk1;
};

#endif  // COMMON_SOURCE_MKSTRINGCACHE_H
