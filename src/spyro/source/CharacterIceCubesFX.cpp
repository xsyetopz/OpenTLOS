#include "spyro/source/CharacterIceCubesFX.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/CharacterBodyFX.h"
#include "spyro/source/Crate.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDPositionProperty.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/Level.h"
#include "spyro/source/PooledShatterProp.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(s32);                                  /* extern */
extern void **gMK;
extern f32 gUpdateTimeDelta;

#if 0 // DRAFT: pointer/array required
void CharacterIceCubesFX::Trigger() {
    s32 var_r28_21;
    s32 var_r29_23;
    s32 var_r30_22;
    void *temp_r3_38;
    void *temp_r3_46;

    if ((CharacterBodyFXData *) this->unk8 != NULL) {
        SetDataActive(1U);
        var_r28_21 = 0;
        var_r30_22 = 0;
        var_r29_23 = 0;
loop_6:
        if (var_r28_21 < (s32) this->unk8->unk4) {
            if ((u32) M2C_FIELD(*(this->unk4 + var_r29_23), u32 *, 8) != -1U) {
                *(this->unk14 + var_r30_22) = checked_cast<PooledShatterProp *, MKProp>(this->unk24->CreateInstance());
                temp_r3_38 = *(this->unk14 + var_r30_22);
                if (temp_r3_38 != NULL) {
                    M2C_FIELD(M2C_FIELD(temp_r3_38, void **, 0x44), M2C_UNK (**)(), 0x20)();
                    temp_r3_46 = *(this->unk14 + var_r30_22);
                    M2C_FIELD(M2C_FIELD(temp_r3_46, void **, 0x44), M2C_UNK (**)(void *), 0x30)(temp_r3_46);
                    MKModel_SetColor(M2C_FIELD(*(this->unk14 + var_r30_22), MKModel **, 4), MKVector4::one);
                }
            }
            var_r28_21 += 1;
            var_r30_22 += 4;
            var_r29_23 += 0x70;
            goto loop_6;
        }
        this->unk20 = 1;
        this->unk18 = 1;
    }
}
#endif

void CharacterIceCubesFX::Reset() {
    this->unk20 = 0;
    this->unk1C = 0.0f;
    this->unk18 = 0;
    this->unk21 = 0;
}

#if 0 // DRAFT: illegal use of non-static member
void CharacterIceCubesFX::Deinit() {
    MKHeap *temp_r3_100;
    void *temp_r31_97;

    temp_r31_97 = this->unk14;
    if (temp_r31_97 != NULL) {
        temp_r3_100 = MKHeap::Current();
        if (temp_r3_100 != NULL) {
            ((MKHeap *) (temp_r3_100->Current()))->Free(temp_r31_97, NULL, 0);
        } else {
            free(temp_r31_97);
        }
    }
    CharacterBodyFX::Deinit();
}
#endif

void CharacterIceCubesFX::Draw() {

}

#if 0 // DRAFT: illegal type
void CharacterIceCubesFX::Shatter() {
    Matrix sp10;
    s32 var_r28_150;
    s32 var_r29_149;
    s32 var_r31_148;
    void *temp_r3_154;
    void *temp_r3_187;

    this->unk20 = 0;
    this->unk21 = 1;
    if ((CharacterBodyFXData *) this->unk8 != NULL) {
        SetDataActive(0U);
        var_r31_148 = 0;
        var_r29_149 = 0;
        var_r28_150 = 0;
loop_5:
        if (var_r31_148 < (s32) this->unk8->unk4) {
            temp_r3_154 = *(this->unk14 + var_r28_150);
            if (temp_r3_154 != NULL) {
                M2C_STRUCT_COPY((s32) &sp10.unkC + 4, MKModel_GetWorldMatrix(M2C_FIELD(temp_r3_154, MKModel **, 4)) - 4 + 4, 0x40);
                sp10.NormaliseScale();
                ((Matrix *) &sp10.unk10)->Scale3x3((Matrix *) &sp10.unk10, *(*(this->unk4 + var_r29_149) + 0x10));
                MKModel_SetWorldMatrix(M2C_FIELD(*(this->unk14 + var_r28_150), MKModel **, 4), *((Matrix *) &sp10.unk10));
                temp_r3_187 = *(this->unk14 + var_r28_150);
                M2C_FIELD(M2C_FIELD(temp_r3_187, void **, 0x44), M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK), 0x94)(temp_r3_187, 0, 0, -1, 0, 1, 0);
                *(this->unk14 + var_r28_150) = 0;
            }
            var_r31_148 += 1;
            var_r29_149 += 0x70;
            var_r28_150 += 4;
            goto loop_5;
        }
    }
}
#endif

#if 0 // DRAFT: illegal type
void CharacterIceCubesFX::Update() {
    Matrix sp70;
    Matrix sp30;
    M2C_UNK sp2C;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 temp_f31_321;
    f64 temp_f0_347;
    s32 var_r28_237;
    s32 var_r28_320;
    s32 var_r29_238;
    s32 var_r29_319;
    s32 var_r31_236;
    s32 var_r31_317;
    void *temp_r3_242;
    void *temp_r3_268;
    void *temp_r3_281;
    void *temp_r3_325;
    void *temp_r4_345;

    if ((CharacterBodyFXData *) this->unk8 != NULL) {
        CharacterBodyFX::Update();
        if ((u8) this->unk10 != 0) {
            var_r31_236 = 0;
            var_r28_237 = 0;
            var_r29_238 = 0;
loop_9:
            if (var_r31_236 < (s32) this->unk8->unk4) {
                temp_r3_242 = *(this->unk14 + var_r29_238);
                if ((temp_r3_242 != NULL) && ((s32) M2C_FIELD(temp_r3_242, s32 *, 0x16C) == 2)) {
                    if ((u8) this->unk18 != 0) {
                        M2C_STRUCT_COPY((s32) &sp30.unk3C + 4, (this->unk4 + (var_r28_237 + 0x20)) - 4 + 4, 0x40);
                        temp_r3_268 = this->unk4 + (var_r28_237 + 8);
                        sp70.unk30 = M2C_FIELD(temp_r3_268, f32 *, 0);
                        sp70.unk34 = M2C_FIELD(temp_r3_268, f32 *, 4);
                        sp70.unk38 = M2C_FIELD(temp_r3_268, f32 *, 8);
                        sp70.unk3C = 1.0f;
                        MKModel_SetWorldMatrix(M2C_FIELD(*(this->unk14 + var_r29_238), MKModel **, 4), sp70);
                        temp_r3_281 = *(this->unk14 + var_r29_238);
                        M2C_FIELD(M2C_FIELD(temp_r3_281, void **, 0x44), M2C_UNK (**)(void *), 0x30)(temp_r3_281);
                    } else {
                        M2C_FIELD(M2C_FIELD(temp_r3_242, void **, 0x44), M2C_UNK (**)(), 0x34)();
                    }
                }
                var_r31_236 += 1;
                var_r28_237 += 0x70;
                var_r29_238 += 4;
                goto loop_9;
            }
        }
        if ((u8) this->unk20 != 0) {
            this->unk1C += gUpdateTimeDelta;
            if (this->unk1C >= 0.25f) {
                this->unk1C = 0.25f;
            }
            var_r31_317 = 0;
            var_r29_319 = 0;
            var_r28_320 = 0;
            temp_f31_321 = this->unk1C / 0.25f;
loop_18:
            if (var_r31_317 < (s32) this->unk8->unk4) {
                temp_r3_325 = *(this->unk14 + var_r28_320);
                if ((temp_r3_325 != NULL) && ((s32) M2C_FIELD(temp_r3_325, s32 *, 0x16C) == 2)) {
                    M2C_STRUCT_COPY((s32) &sp2C + 4, MKModel_GetWorldMatrix(M2C_FIELD(temp_r3_325, MKModel **, 4)) - 4 + 4, 0x40);
                    temp_r4_345 = *(this->unk4 + var_r29_319) + 0x10;
                    temp_f0_347 = M2C_FIELD(temp_r4_345, f64 *, 0) * (f64) temp_f31_321;
                    sp10 = temp_f0_347;
                    sp20 = temp_f0_347;
                    sp18 = M2C_FIELD(temp_r4_345, f32 *, 8) * temp_f31_321;
                    sp28 = (f64) sp18;
                    sp30.Scale3x3(&sp30, *((MKVector3 *) &sp20));
                    MKModel_SetWorldMatrix(M2C_FIELD(*(this->unk14 + var_r28_320), MKModel **, 4), sp30);
                }
                var_r31_317 += 1;
                var_r29_319 += 0x70;
                var_r28_320 += 4;
                goto loop_18;
            }
        }
    }
}
#endif

#if 0 // DRAFT: illegal type
void CharacterIceCubesFX::InitData(CharacterBodyFXData *arg0, MKModel *arg1, CBFXNode *arg2) {
    CharacterBodyFXData *temp_r3_401;
    MKHeap *temp_r3_404;
    s32 temp_r31_403;
    s32 var_r4_417;
    s32 var_r6_420;
    void *var_r3_411;

    if ((s32) arg0->unk4 == 0) {
        this->unk8 = NULL;
        return;
    }
    CharacterBodyFX::InitData(arg0, arg1, arg2);
    temp_r3_401 = this->unk8;
    temp_r31_403 = temp_r3_401->unk4 * 4;
    temp_r3_404 = ((MKHeap *) temp_r3_401)->Current();
    if (temp_r3_404 != NULL) {
        var_r3_411 = ((MKHeap *) (temp_r3_404->Current()))->Alloc(temp_r31_403, NULL, 0);
    } else {
        var_r3_411 = malloc(temp_r31_403);
    }
    var_r4_417 = 0;
    this->unk14 = var_r3_411;
    var_r6_420 = 0;
loop_7:
    if (var_r6_420 < (s32) this->unk8->unk4) {
        var_r6_420 += 1;
        *(this->unk14 + var_r4_417) = 0;
        var_r4_417 += 4;
        goto loop_7;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const char[8]' to
void CharacterIceCubesFX::Init() {
    CharacterBodyFX::Init();
    this->unk14 = NULL;
    this->unk20 = 0;
    this->unk1C = 0.0f;
    this->unk18 = 0;
    this->unk21 = 0;
    this->unk24 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>(M2C_FIELD(*gMK, MKPropDescriptor *(**)(void **, M2C_UNK *), 0x5C)(gMK, "IceCube"));
}
#endif
