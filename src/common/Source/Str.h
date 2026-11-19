#ifndef COMMON_SOURCE_STR_H
#define COMMON_SOURCE_STR_H

#include <dolphin/types.h>

void Str_CompareIgnoreCase(const char *, const char *);
u8 * Str_FindChar(const char *, int);
s8 * Str_GetFilenameFromPath(const char *);
void Str_Lower(const char *);
void Str_Upper(const char *);
s8 * Str_Dup(const char *);
u8 * Str_CopyString(const char *, int);
s32 Str_snPrintf(char *, int, const char *, ...);
s8 * Str_Printf(const char *, ...);
extern u8 gNullStr;
extern s8 gAssertBool;
#endif  // COMMON_SOURCE_STR_H
