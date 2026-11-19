#ifndef COMMON_SOURCE_MKPTRLIST_H
#define COMMON_SOURCE_MKPTRLIST_H

#include <dolphin/types.h>

template <class T0>
class MKPtrList {
public:
    void Destroy(T0 *);
};

#endif  // COMMON_SOURCE_MKPTRLIST_H
