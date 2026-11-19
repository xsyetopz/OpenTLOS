#ifndef COMMON_SOURCE_MKINI_H
#define COMMON_SOURCE_MKINI_H

#include <dolphin/types.h>

class MKIni;
class MKIniLine;
class MKVector3;
class MKVector4;

class MKIni {
public:
    static s32 Exists(const char *);
    u8 IsMaskedOut(MKIniLine *);
    void ReadBinary(const char *);
    MKIniLine * GetSubLine(MKIniLine *);
    MKIniLine * GetPrevLine(MKIniLine *);
    MKIniLine * GetNextLine(MKIniLine *);
    MKIniLine * GetFirstLine(void);
    MKIniLine * GotoLine(const char *, const char *);
    void Warning(const char *);
    void Deinit(void);
    s32 Init(const char *, int, const char *);
    /* 0x000 */ s8 unk0;
    /* 0x001 */ u8 pad1[0x3];
    /* 0x004 */ void* unk4;
    /* 0x008 */ void* unk8;
    /* 0x00c */ u32 unkC;
    /* 0x010 */ MKIniLine* unk10;
    /* 0x014 */ void* unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ s8 unk1C;
    /* 0x01d */ u8 pad1D[0x1f];
    /* 0x03c */ s32 unk3C;
    /* 0x040 */ s32 unk40;
    /* 0x044 */ s8* unk44;
    /* 0x048 */ void* unk48;
    /* 0x04c */ s32 unk4C;
};

class MKIniLine {
public:
    s32 GetNmbrOfSubLines(void);
    s32 IsSection(const char *);
    s32 IsField(const char *);
    s32 LoadVector4(const char *, MKVector4 *, int);
    s32 LoadVector3(const char *, MKVector3 *, int);
    s32 LoadString(const char *, const char **, int);
    s32 LoadFloat(const char *, float *, int);
    s32 LoadInt(const char *, int *, int);
    s32 LoadBool(const char *, bool *, int);
    s32 AsVector4(int, MKVector4 *);
    s32 AsVector3(int, MKVector3 *);
    s32 AsString(int, const char **);
    s32 AsFloat(int, float *);
    s32 AsInt(int, int *);
    s32 AsBool(int, bool *);
    s32 AsFlag(int, int *);
    MKVector3 GetVector3(int);
    f32 GetFloat(int);
    s32 GetInt(int);
    s32 GetFlag(int);
    s32 GetBool(int);
    s32 GetString(int);
    u8 * GetMaskName(void);
    s8 * GetFieldName(void);
    s8 * GetSectionName(void);
    /* 0x000 */ s16 unk0;
    /* 0x002 */ u16 unk2;
    /* 0x004 */ u16 unk4;
    /* 0x006 */ u16 unk6;
    /* 0x008 */ u16 unk8;
    /* 0x00a */ u16 unkA;
    /* 0x00c */ MKIni* unkC;
};

#endif  // COMMON_SOURCE_MKINI_H
