#ifndef COMMON_GC_MKMODEL_GC_H
#define COMMON_GC_MKMODEL_GC_H

#include <dolphin/types.h>

class MKModel;
class MKModelTemplate;
class MKModel_Blob;
class Matrix;
class MeshChunkExplorer;
class MeshChunkGC;

class MeshChunkExplorer {
public:
    /* 0x000 */ s32 unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ u8 unkC;
    /* 0x00d */ u8 padD[0x2f];
    /* 0x03c */ u16* unk3C;
    /* 0x040 */ u8 pad40[0x4];
    /* 0x044 */ s32 unk44;
    /* 0x048 */ u8 pad48[0x8];
    /* 0x050 */ u8 unk50;
    /* 0x051 */ u8 pad51[0x7];
    /* 0x058 */ f32 unk58;
    /* 0x05c */ f32 unk5C;
    /* 0x060 */ f32 unk60;
    /* 0x064 */ u8 pad64[0x4];
    /* 0x068 */ f32 unk68;
    /* 0x06c */ f32 unk6C;
    /* 0x070 */ f32 unk70;
    /* 0x074 */ u8 pad74[0x4];
    /* 0x078 */ f32 unk78;
    /* 0x07c */ f32 unk7C;
    /* 0x080 */ f32 unk80;
    /* 0x084 */ f32 unk84;
    /* 0x088 */ f32 unk88;
    /* 0x08c */ f32 unk8C;
    /* 0x090 */ s32 unk90;
    /* 0x094 */ s32 unk94;
    /* 0x098 */ s32 unk98;
};

class MeshChunkGC {
public:
    /* 0x000 */ u8 pad0[0x6];
    /* 0x006 */ u16 unk6;
    /* 0x008 */ u8 pad8[0x8];
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
};

void MKModel_BlobDraw(const MKModel *, int, const MKModel_Blob *);
void MKModel_BlobBegin(const MKModel *);
void MKModel_BlobPreprocess(MKModel *);
void MKModel_ExploreEnd(MeshChunkExplorer *);
s32 MKModel_ExploreNextStrip(MeshChunkExplorer *);
void MKModel_ExploreCalculateVertex(MeshChunkExplorer *, int);
void MKModel_ExploreMeshChunk(MeshChunkExplorer *, int, int, int);
void MKModel_ExploreBegin(const MKModel *);
void MKModel_Draw(const MKModel *, const unsigned short *);
void MKModel_UnpackTemplatePlatformSpecific(MKModelTemplate *);
void MKModel_InitModulePlatformSpecific(void);
void Model_DrawWeightedBlendShape(MeshChunkGC *, float *, unsigned long, const Matrix *, float *);
#endif  // COMMON_GC_MKMODEL_GC_H
