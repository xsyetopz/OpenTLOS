#ifndef SPYRO_SOURCE_DATAMAP_H
#define SPYRO_SOURCE_DATAMAP_H

#include <dolphin/types.h>

class DataMap;
class MKIniLine;

s32 DataMap_LoadLineBitfield(MKIniLine *, const char *, const DataMap *, unsigned int *);
s32 DataMap_LoadLine(MKIniLine *, const char *, const DataMap *, unsigned int *);
s32 DataMap_GetName(const DataMap *, unsigned int);
s32 DataMap_GetValue(const DataMap *, const char *);
#endif  // SPYRO_SOURCE_DATAMAP_H
