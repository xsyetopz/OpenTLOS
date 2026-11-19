#ifndef COMMON_SOURCE_MKGRASS_MP_H
#define COMMON_SOURCE_MKGRASS_MP_H

#include <dolphin/types.h>

class Frustum;
class GrassStrip;
class GrassSubObject;
class GrassUsedType;
class GrassVertex;
class MKAttachment;
class MKGrassType;
class MKModel;
class MKModel_Blob;
class MeshChunkExplorer;
class OmniLight;

class GrassStrip {
public:
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ f32 unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ u16 unk14;
};

class GrassSubObject {
public:
    /* 0x000 */ u16 unk0;
    /* 0x002 */ u16 unk2;
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ GrassStrip* unk8;
};

class GrassUsedType {
public:
    /* 0x000 */ u16 unk0;
    /* 0x002 */ u16 unk2;
    /* 0x004 */ void* unk4;
};

class GrassVertex {
public:
    /* 0x000 */ f64 unk0;
    /* 0x008 */ f64 unk8;
    /* 0x010 */ f64 unk10;
    /* 0x018 */ f64 unk18;
};

class MKModel_Blob {
public:
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ f32 unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ f32 unk1C;
    /* 0x020 */ f32 unk20;
    /* 0x024 */ f32 unk24;
    /* 0x028 */ f32 unk28;
    /* 0x02c */ f32 unk2C;
    /* 0x030 */ f32 unk30;
    /* 0x034 */ f32 unk34;
    /* 0x038 */ f32 unk38;
    /* 0x03c */ f32 unk3C;
    /* 0x040 */ f32 unk40;
    /* 0x044 */ f32 unk44;
    /* 0x048 */ f32 unk48;
    /* 0x04c */ f32 unk4C;
    /* 0x050 */ s32 unk50;
};

void MKGrass_FlushSubObject(MKGrassType *);
void MKGrass_DrawSubObject(const Frustum &, const MKModel *, const MKAttachment *, MKGrassType *, GrassSubObject *, bool, int, OmniLight **);
void MKGrass_InitDraw(void);
u32 OptimiseGrassTypeData(MKModel *, GrassUsedType *);
void CreateGrassStripData(MKModel *, MeshChunkExplorer *, GrassUsedType *);
#endif  // COMMON_SOURCE_MKGRASS_MP_H
