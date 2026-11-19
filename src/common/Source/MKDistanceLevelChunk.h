#ifndef COMMON_SOURCE_MKDISTANCELEVELCHUNK_H
#define COMMON_SOURCE_MKDISTANCELEVELCHUNK_H

#include <dolphin/types.h>
#include "common/Source/MKLevelChunk.h"
#include "common/Source/MKProp.h"

class BoundingVolume;
class MKDistanceLevelChunk;
class MKFFTWater;
class MKLevelChunk;
class MKMessage;
class MKModel;
class MKProp;
class MKPropDescriptor;
class MKVector3;
class SMNode;
class SMTree;
class TerrainModel;

class BoundingVolume {
public:
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ u8 padC[0x4];
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ s32 unk1C;
    /* 0x020 */ s32 unk20;
    /* 0x024 */ s32 unk24;
    /* 0x028 */ MKProp* unk28;
    /* 0x02c */ f32 unk2C;
};

class MKDistanceLevelChunk : public MKLevelChunk {  // base: ctor/dtor vtable stores
public:
    virtual ~MKDistanceLevelChunk(void);
    virtual void SetActivePoint(const MKVector3 &);
    virtual s32 ResetAllProps(void);
    virtual s32 ResolveAllProps(void);
    virtual void CalculateVisibility(bool);
    virtual void CalculateUpdateDistances(void);
    virtual s32 Optimise(void);
    virtual void UpdateProps(void);
    virtual void DrawTerrain(int);
    virtual void DrawProps(int);
    virtual void SendMessage(MKMessage *, unsigned int, bool, MKVector3 *, float, bool);
    virtual void SetTerrainDrawCallback(void (*)(MKModel *, unsigned short *, void *));
    virtual void SetTerrainUserData(const char *, void *);
    virtual MKPropDescriptor * GetDescriptorList(void) const;
    virtual void Init(MKLevelChunk::MKLevelChunkInit *);
    virtual void Deinit(void);
    virtual void AddProp(MKProp *);
    virtual void AddDescriptor(MKPropDescriptor *);
    virtual MKModel * AddTerrainModel(const char *, int);
    virtual MKPropDescriptor * FindDescriptor(const char *);
    virtual MKProp * FindProp(const char *);
    virtual s32 FindTerrainModel(const char *);
    virtual void DrawWater(int);
    virtual void PostDrawWater(void);
    virtual s32 InitChunk(void);
    virtual s32 DeinitChunk(void);
    virtual f32 GetDistanceFromPoint(const MKVector3 &);
    virtual void EnableTerrainModel(const char *, bool);
    virtual s32 GetPropsInRange(MKProp **, int, const MKVector3 &, float, int, bool);
    void DL_Draw_DrawVeryLastLayer(void);
    void DL_Draw_DrawLastLayer(void);
    void DL_Draw_AboveWaterLayer(void);
    void DL_Draw_BelowWaterLayer(void);
    void DL_Draw_SolidLayer(void);
    void DL_Begin(void);
    void DL_Init(MKPropDescriptor *);
    void AddPropToDrawList(MKProp *, int, float, float);
    void CheckPropVisRecursive(SMNode *, int);
    void CalcGlobalPropVis(void);
    void CalcDynamicPropVis(void);
    void CalcStaticPropVis(void);
    void UpdateProp(MKProp *, MKMessage *);
    void DrawRecursiveTerrain(SMNode *, int);
    void * ChunkCreator(const char *);
    /* 0x004 */ u32 unk4;
    /* 0x008 */ u8 pad8[0x78];
    /* 0x080 */ s32 unk80;
    /* 0x084 */ s32 unk84;
    /* 0x088 */ u8 pad88[0x8];
    /* 0x090 */ s32 unk90;
    /* 0x094 */ u8 pad94[0x4];
    /* 0x098 */ MKFFTWater* unk98;
    /* 0x09c */ u16* unk9C;
    /* 0x0a0 */ u8 padA0[0x88];
    /* 0x128 */ MKProp* unk128;
    /* 0x12c */ MKPropDescriptor* unk12C;
    /* 0x130 */ u8 pad130[0x8];
    /* 0x138 */ s32 unk138;
    /* 0x13c */ s32 unk13C;
    /* 0x140 */ s32 unk140;
    /* 0x144 */ f32 unk144;
    /* 0x148 */ u8 pad148[0x4];
    /* 0x14c */ MKPropDescriptor* unk14C;
    /* 0x150 */ u8 unk150;
    /* 0x151 */ u8 pad151[0x7];
    /* 0x158 */ f64 unk158;
    /* 0x160 */ f64 unk160;
    /* 0x168 */ s8 unk168;
    /* 0x169 */ u8 pad169[0x33];
    /* 0x19c */ void* unk19C;
    /* 0x1a0 */ void* unk1A0;
    /* 0x1a4 */ u8 pad1A4[0x14];
    /* 0x1b8 */ u8 unk1B8;
    /* 0x1b9 */ u8 pad1B9[0x2f];
    /* 0x1e8 */ void* unk1E8;
    /* 0x1ec */ void* unk1EC;
    /* 0x1f0 */ u8 pad1F0[0x14];
    /* 0x204 */ s32 unk204;
    /* 0x208 */ s32 unk208;
    /* 0x20c */ s32 unk20C;
    /* 0x210 */ u8 pad210[0x40];
    /* 0x250 */ f32 unk250;
    /* 0x254 */ f32 unk254;
    /* 0x258 */ f32 unk258;
    /* 0x25c */ u8 pad25C[0x4];
    /* 0x260 */ s32 unk260;
    /* 0x264 */ s32 unk264;
    /* 0x268 */ u16 unk268;
    /* 0x26a */ u8 pad26A[0x7fe];
    /* 0xa68 */ u8 unkA68;
    /* 0xa69 */ u8 padA69[0xf9f];
    /* 0x1a08 */ u8 unk1A08;
    /* 0x1a09 */ u8 pad1A09[0xf9f];
    /* 0x29a8 */ void* unk29A8;
    /* 0x29ac */ SMNode* unk29AC;
    /* 0x29b0 */ u8 pad29B0[0x8];
    /* 0x29b8 */ s32 unk29B8;
    /* 0x29bc */ s32 unk29BC;
    /* 0x29c0 */ u8 pad29C0[0x20];
    /* 0x29e0 */ MKProp unk29E0;
    /* 0x2a2c */ MKProp unk2A2C;
    /* 0x2a78 */ MKProp unk2A78;
    /* 0x2ac4 */ u8 pad2AC4[0x280];
    /* 0x2d44 */ MKPropDescriptor* unk2D44;
    /* 0x2d48 */ MKPropDescriptor* unk2D48;
    /* 0x2d4c */ MKPropDescriptor* unk2D4C;
    /* 0x2d50 */ s32 unk2D50;
    /* 0x2d54 */ s32 unk2D54;
    /* 0x2d58 */ s32 unk2D58;
    /* 0x2d5c */ s32 unk2D5C;
    /* 0x2d60 */ TerrainModel* unk2D60;
};

class SMNode {
public:
    /* 0x000 */ u8 pad0[0x20];
    /* 0x020 */ SMNode* unk20;
    /* 0x024 */ SMNode* unk24;
    /* 0x028 */ MKProp* unk28;
};

class SMTree {
public:
    u8 LinkUp(void);
    void LinkUpRow(int, int, int);
    void PairUp(int, int, int);
    void Deinit(void);
    void Update(void);
    void InternalInit(int);
    void Init(int, MKProp *);
    void Init(TerrainModel *);
    void Reset(void);
    /* 0x000 */ BoundingVolume* unk0;
    /* 0x004 */ void* unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ s32 unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ s32 unk1C;
    /* 0x020 */ u8 pad20[0x4];
    /* 0x024 */ s32 unk24;
    /* 0x028 */ s32 unk28;
    /* 0x02c */ MKProp* unk2C;
    /* 0x030 */ MKProp* unk30;
    /* 0x034 */ BoundingVolume* unk34;
};

class TerrainModel {
public:
    /* 0x000 */ TerrainModel* unk0;
    /* 0x004 */ MKModel* unk4;
    /* 0x008 */ u8 pad8[0x8];
    /* 0x010 */ SMTree unk10;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier '__vt'
inline void *MKDistanceLevelChunk::ChunkCreator(const char *arg0) {
    void *temp_r31_1737;

    operator new(0x2D70U, NULL, 0);
    temp_r31_1737 = M2C_ERROR(/* Read from unset register $r3 */);
    if (temp_r31_1737 != NULL) {
        M2C_FIELD(temp_r31_1737, M2C_UNK **, 8) = &__vt;
        M2C_FIELD(temp_r31_1737, M2C_UNK **, 8) = &__vt;
        __construct_array(temp_r31_1737 + 0x16C, &MKProp::MKProp, &MKProp::~MKProp, 0x4C, 2);
        M2C_FIELD(temp_r31_1737, M2C_UNK **, 0x2A24) = &__vt;
        M2C_FIELD(temp_r31_1737, M2C_UNK **, 0x2A70) = &__vt;
        M2C_FIELD(temp_r31_1737, M2C_UNK **, 0x2ABC) = &__vt;
    }
    return temp_r31_1737;
}
#endif

#if 0 // DRAFT: undefined identifier '__vt'
inline MKDistanceLevelChunk::~MKDistanceLevelChunk() {
    this->unk8 = &__vt;
    if (&this->unk2A2C.__vptr != NULL) {
        this->unk2A78.unk3C = &__vt;
    }
    if (&this->unk29E0.__vptr != NULL) {
        this->unk2A2C.unk3C = &__vt;
    }
    if (&this->unk29E0 != NULL) {
        this->unk29E0.unk3C = &__vt;
    }
    __destroy_arr(this + 0x16C, &MKProp::~MKProp, 0x4C, 2);
    if (this != NULL) {
        this->unk8 = &__vt;
    }
}
#endif

inline MKPropDescriptor *MKDistanceLevelChunk::GetDescriptorList() const {
    return (MKPropDescriptor *) this->unk148;
}

inline void MKDistanceLevelChunk::SetActivePoint(const MKVector3 &arg0) {
    this->unk158 = M2C_FIELD(&arg0, f64 *, 0);
    this->unk158 = M2C_FIELD(&arg0, f64 *, 8);
}

#endif  // COMMON_SOURCE_MKDISTANCELEVELCHUNK_H
