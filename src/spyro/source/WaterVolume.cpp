#include "spyro/source/WaterVolume.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionManager.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/Matrix.h"
#include "spyro/source/KDWaterVolume.h"
#include "unplaced_enums.h"
#include "spyro/source/PropFlags.h"
#include <m2c_macros.h>

extern void **gMK;
extern M2C_UNK gb;
static M2C_UNK volumeTypes;                         /* unable to generate initializer: unknown type */

s32 WaterVolume::IsEnabled() {
    return (this->unk10 & 0x160000) != 0;
}

#if 0 // DRAFT: function call 'PropFlagsSet(unsigned long *, unsigned int)' does not match
void WaterVolume::Message(MKMessage *arg0) {
    s32 temp_r0_61;

    temp_r0_61 = arg0->unk0;
    switch (temp_r0_61) {                           /* irregular */
    case 0xBE:
        PropFlagsSet((u32 *) &this->unk10, 0x160000U);
        break;
    case 0xBF:
        PropFlagsClear((u32 *) &this->unk10, 0x160000U);
        break;
    }
    MKProp::Message(arg0);
}
#endif

void WaterVolume::Resolve() {
    s8 sp14;
    MKCollisionInfo *sp10;
    s32 spC;
    s32 sp8;
    MKCollisionInfo *temp_r5_98;

    MKProp::Resolve();
    temp_r5_98 = &this->unkE0;
    spC = 0;
    sp8 = 0x40F;
    sp10 = temp_r5_98;
    sp14 = 1;
    M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, MKCollisionInfo *, M2C_UNK), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp8, temp_r5_98, 0x40F);
}

#if 0 // DRAFT: function call 'MKModel_Create(MKHeap *, int, int, int)' does not match
void WaterVolume::LoadDone() {
    Matrix sp10;
    M2C_UNK spC;
    s32 temp_r31_161;

    KDWaterVolume::LoadDone();
    this->unk4 = MKModel_Create(MKModel_GetName(M2C_FIELD(this->unk0, MKModel **, 0x2C)), NULL, 2, NULL);
    M2C_STRUCT_COPY((s32) &spC + 4, (s32) &this->unk50.unk3C + 4, 0x40);
    MKModel_SetWorldMatrix(this->unk4, sp10);
    temp_r31_161 = MKModel_GetSubObjectIndex(this->unk4, (SubObjectType) 0, "C_Collide");
    ((MKCollisionManager *) (M2C_FIELD(*gMK, MKCollisionManager *(**)(void **), 0x84)(gMK)))->AddModel(this->unk4, temp_r31_161, (MKCollisionMode) 1, &this->unkE0, 0U);
}
#endif

#if 0 // DRAFT: function call 'PropFlagsLoadLine(unsigned long *, MKIniLine *)' does not
s32 WaterVolume::LoadLine(MKIniLine *arg0) {
    s32 var_r31_189;

    var_r31_189 = 0;
    if ((MKProp::LoadLine(arg0) != 0) || (PropFlagsLoadLine((u32 *) &this->unk10, arg0) != 0)) {
        var_r31_189 = 1;
    }
    return var_r31_189;
}
#endif

void WaterVolume::Deinit() {
    MKCollisionInfo *sp10;
    s32 spC;
    s32 sp8;

    spC = 0;
    sp8 = 0x410;
    sp10 = &this->unkE0;
    M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, M2C_UNK), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp8, 0x410);
    KDWaterVolume::Deinit();
}

#if 0 // DRAFT: function call 'PropFlagsSet(unsigned long *, unsigned int)' does not match
void WaterVolume::Init() {
    MKProp::Init();
    PropFlagsSet((u32 *) &this->unk10, 0x160000U);
    this->unkE0.unk0 = 0;
    this->unkE0.unk4 = 1;
    this->unkE0.unk8 = (MKProp *) this;
    this->unkE0.unkC = 0;
    this->unkE0.unk4 = 0;
}
#endif

void WaterVolumeDescriptor::Init() {
    KDWaterVolumeDescriptor::Init();
    this->unk64 = (u32) &volumeTypes;
    this->unkC = 0x100;
}
