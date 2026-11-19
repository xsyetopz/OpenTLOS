#ifndef COMMON_SOURCE_MKMATERIAL_UTIL_H
#define COMMON_SOURCE_MKMATERIAL_UTIL_H

#include <dolphin/types.h>

class MKMaterialTypeInfo;

void MKMaterialInternal_AddTypeToList(MKMaterialTypeInfo *);
extern void * gpMKMaterialTypeInfoList;
#endif  // COMMON_SOURCE_MKMATERIAL_UTIL_H
