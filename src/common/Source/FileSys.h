#ifndef COMMON_SOURCE_FILESYS_H
#define COMMON_SOURCE_FILESYS_H

#include <dolphin/types.h>

class RkvFileEntry;
class RkvTOC;

class RkvFileEntry {
public:
    /* 0x000 */ s8* unk0;
    /* 0x004 */ u32 unk4;
    /* 0x008 */ u32 unk8;
    /* 0x00c */ u8 padC[0x4];
    /* 0x010 */ s16 unk10;
    /* 0x012 */ s8 unk12;
    /* 0x013 */ u8 pad13[0x1];
    /* 0x014 */ u32 unk14;
};

class RkvTOC {
public:
    s32 GetAsyncHandle(void);
    RkvFileEntry * GetEntry(const char *);
    s32 Deinit(void);
    void AsyncRegUpdate(void);
    s32 Init(const char *, bool, unsigned int, int, const char *);
    /* 0x000 */ s8 unk0;
    /* 0x001 */ u8 pad1[0x3f];
    /* 0x040 */ s8 unk40;
    /* 0x041 */ u8 pad41[0x1f];
    /* 0x060 */ s32 unk60;
    /* 0x064 */ s32 unk64;
    /* 0x068 */ s8* unk68;
    /* 0x06c */ s32 unk6C;
    /* 0x070 */ u8 unk70;
};

u32 MKArchive_GetOffset(const char *);
void MKArchive_Close(int);
s32 MKArchive_Open(const char *, int *, bool);
void MKArchive_OutputFileOrder(void);
s32 MKArchive_Save(const char *, bool, void *, int);
s8 * MKArchive_Load(const char *, int *, void *, int);
s32 MKArchive_Exists(const char *, int *);
void MKArchive_SetLoadInterceptHandler(void *(*)(const char *, int *, void *, int *));
s32 MKArchive_GetAsyncRegistrationStatus(void);
void MKArchive_Update(void);
s32 MKArchive_DeregisterArchive(const char *);
s32 MKArchive_RegisterArchive(const char *, bool);
void MKArchive_DeinitModule(void);
void MKArchive_InitModule(void);
extern s8 * gpTempMemFilePatterns;
extern u32 gMKArchive_ArchiveOverride;
#endif  // COMMON_SOURCE_FILESYS_H
