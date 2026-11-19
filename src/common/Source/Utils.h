#ifndef COMMON_SOURCE_UTILS_H
#define COMMON_SOURCE_UTILS_H

#include <dolphin/types.h>
#include "common/Source/MKHeap.h"

class MKHeap;

s32 Util_WildcardPatternMatch(const char *, const char *);
void * Util_BinarySearch(const void *, void *, int, int, int (*)(const void *, const void *));
extern MKHeap gEmptyPtrList;
extern MKHeap gEmptyPtrListDL;
#endif  // COMMON_SOURCE_UTILS_H
