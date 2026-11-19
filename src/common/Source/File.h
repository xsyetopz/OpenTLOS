#ifndef COMMON_SOURCE_FILE_H
#define COMMON_SOURCE_FILE_H

#include <dolphin/types.h>

void File_FileServerOutputFilename(const char *);
void File_FileServerFilename(const char *);
s32 File_IsAnyBusy(void);
s32 File_Sync(int, int);
s32 File_IsBusy(int);
u32 File_Length(const char *);
s32 File_Seek(int, int, int);
s32 File_Write(int, const void *, int);
s32 File_Read(int, void *, int, int);
s32 File_Close(int);
s32 File_Open(const char *, int);
void File_DeinitModule(void);
void File_InitModule(void);
#endif  // COMMON_SOURCE_FILE_H
