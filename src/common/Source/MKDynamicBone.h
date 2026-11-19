#ifndef COMMON_SOURCE_MKDYNAMICBONE_H
#define COMMON_SOURCE_MKDYNAMICBONE_H

#include <dolphin/types.h>

class MKDynamicBone;
class MKDynamicBoneSystem;
class MKModel;
class Matrix;

class MKDynamicBone {
public:
    void DefaultUpdater(MKDynamicBone *, void *);
    void Reset(void);
    void Update(void);
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ f32 unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ f32 unk1C;
    /* 0x020 */ Matrix* unk20;
    /* 0x024 */ MKModel* unk24;
    /* 0x028 */ void* unk28;
    /* 0x02c */ u8 pad2C[0x4];
    /* 0x030 */ u8 unk30;
    /* 0x031 */ u8 pad31[0x3f];
    /* 0x070 */ s16 unk70;
    /* 0x072 */ s16 unk72;
    /* 0x074 */ f32 unk74;
};

class MKDynamicBoneSystem {
public:
    void ResetModel(MKModel *);
    void Update(void);
    void Enable(MKModel *, bool);
    void RemoveModel(MKModel *);
    void AddModel(MKModel *);
    void Deinit(void);
    void Init(void);
    /* 0x000 */ MKDynamicBone** unk0;
    /* 0x004 */ u8 unk4;
};

void MKDynamicBone_SetUpdater(MKDynamicBone *, void (*)(MKDynamicBone *, void *), void *);
void * MKDynamicBone_GetDynamicBone(MKModel *, int);
void * MKDynamicBone_AddDynamicBone(MKModel *, int);
void MKDynamicBone_ResetModel(MKModel *);
extern u8 gDynamicBoneEnable[0x4];
extern MKDynamicBoneSystem gDynamicBones;
extern MKDynamicBone ** spareTemplates;
#endif  // COMMON_SOURCE_MKDYNAMICBONE_H
