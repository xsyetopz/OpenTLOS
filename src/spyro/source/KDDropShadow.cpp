#include "spyro/source/KDDropShadow.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/Level.h"
#include "unplaced_templates.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include <m2c_macros.h>

#if 0 // DRAFT: ')' expected
MKHeap *malloc(s32);                                /* extern */

void KDDropShadow::Draw() {
    Matrix *var_r31_61;
    Matrix *var_r3_104;
    Matrix *var_r3_53;
    f32 temp_f1_70;
    f32 temp_f1_84;
    f32 temp_f1_91;
    f32 temp_f3_98;

    MKMaterial_SetMaterial(M2C_FIELD(checked_cast<KDDropShadowDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKMaterial **, 0x38));
    MKPrimitive(0xC, 0x10);
    var_r3_53 = this->unk50;
    if (var_r3_53 != (Matrix *) this->unk54) {

    } else {
        var_r3_53 = NULL;
    }
    var_r31_61 = var_r3_53;
loop_7:
    if (var_r31_61 != NULL) {
        MKSetMatrix(*var_r31_61);
        MKBegin(4);
        temp_f1_70 = -M2C_FIELD(var_r31_61, f32 *, 0x40);
        MKSetPositionF(temp_f1_70, 1.0f, temp_f1_70);
        MKSetTexCoord1F(1.0f, 0.0f);
        MKSetColorF(1.0f, 1.0f, 1.0f, M2C_FIELD(var_r31_61, f32 *, 0x44));
        MKSetTexCoord1F(0.0f, 0.0f);
        temp_f1_84 = M2C_FIELD(var_r31_61, f32 *, 0x40);
        MKSetPositionF(temp_f1_84, 1.0f, -temp_f1_84);
        MKSetTexCoord1F(1.0f, 1.0f);
        temp_f1_91 = M2C_FIELD(var_r31_61, f32 *, 0x40);
        MKSetPositionF(temp_f1_91, 1.0f, temp_f1_91);
        MKSetTexCoord1F(0.0f, 1.0f);
        temp_f3_98 = M2C_FIELD(var_r31_61, f32 *, 0x40);
        MKSetPositionF(-temp_f3_98, 1.0f, temp_f3_98);
        MKEnd();
        var_r3_104 = var_r31_61 + 0x50;
        if (var_r3_104 >= (Matrix *) this->unk54) {
            var_r3_104 = NULL;
        }
        var_r31_61 = var_r3_104;
        goto loop_7;
    }
    this->unk50 = this->unk54;
    MKEndPrimitive();
}
#endif

void KDDropShadow::Reset() {
    MKProp::Reset();
    this->unk50 = this->unk54;
}

void KDDropShadow::Deinit() {
    this->unk4C->FreeFromAnyHeap(NULL, NULL, M2C_ERROR(/* Read from unset register $r6 */));
    this->unk54 = NULL;
    this->unk50 = NULL;
    this->unk4C = NULL;
    MKProp::Deinit();
}

#if 0 // DRAFT: ')' expected
s32 KDDropShadow::LoadDone() {
    MKHeap *var_r3_185;
    Matrix *temp_r0_194;
    s32 temp_r31_177;

    MKProp::LoadDone();
    temp_r31_177 = M2C_FIELD(checked_cast<KDDropShadowDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x60);
    if (MKHeap::Current() != NULL) {
        var_r3_185 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r31_177 * 0x50, NULL, 0);
    } else {
        var_r3_185 = malloc(temp_r31_177 * 0x50);
    }
    this->unk4C = var_r3_185;
    temp_r0_194 = this->unk4C + (temp_r31_177 * 0x50);
    this->unk50 = temp_r0_194;
    this->unk54 = temp_r0_194;
}
#endif

s32 KDDropShadowDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_213;

    var_r31_213 = 0;
    if ((MKPropDescriptor::LoadLine(arg0) != 0) || (arg0->LoadInt("listSize", (int *) &this->unk60, 0) != 0) || (arg0->LoadFloat("unitSize", &this->unk64, 0) != 0)) {
        var_r31_213 = 1;
    }
    return var_r31_213;
}

void KDDropShadowDescriptor::Init() {
    MKPropDescriptor::Init();
    this->unk60 = 0x32;
    this->unk64 = 1.0f;
}
