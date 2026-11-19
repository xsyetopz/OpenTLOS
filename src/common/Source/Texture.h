#ifndef COMMON_SOURCE_TEXTURE_H
#define COMMON_SOURCE_TEXTURE_H

#include <dolphin.h>

class MKHeap;
class Texture;

class Texture {
public:
    void ReloadGuts(float);
    s8 * CreateMpegTarget(const char *, void *, int, int);
    void CaptureDrawBuffer(float, float, float, float);
    void CreateRenderTarget(const char *, int, int, int);
    s8 * CreateFromRawData(const char *, void *, int, int, int, int);
    void Use(void);
    MKHeap * Find(const char *);
    void Destroy(void);
    s8 * Create(const char *, float);
    void InitModule(void);
    /* 0x000 */ s8 unk0;
    /* 0x001 */ u8 pad1[0x23];
    /* 0x024 */ s32 unk24;
    /* 0x028 */ s32 unk28;
    /* 0x02c */ s32 unk2C;
    /* 0x030 */ u8 pad30[0x2];
    /* 0x032 */ u8 unk32;
    /* 0x033 */ u8 pad33[0x1];
    /* 0x034 */ u32 unk34;
    /* 0x038 */ u8 unk38;
    /* 0x039 */ u8 pad39[0x3];
    /* 0x03c */ void* unk3C;
    /* 0x040 */ void* unk40;
    /* 0x044 */ void* unk44;
    /* 0x048 */ GXTexRegion* unk48;
    /* 0x04c */ u8 pad4C[0x14];
    /* 0x060 */ GXTexObj unk60;
    /* 0x061 */ u8 pad61[0x1f];
    /* 0x080 */ s8* unk80;
    /* 0x084 */ void* unk84;
};

extern u8 Texture_filterType[0x4];
#endif  // COMMON_SOURCE_TEXTURE_H
