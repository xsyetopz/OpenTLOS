#include "spyro/source/WobbleProp.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
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
#include "common/Source/Texture.h"
#include "spyro/source/AssaultCannon.h"
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
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/Level.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "common/Source/MKDynamicBone.h"
#include "common/Source/StdMath.h"
#include "spyro/source/Tools.h"
#include "unplaced_inlines.h"
#include <m2c_macros.h>

extern s32 GS_PLACEHOLDER;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern void **gb;

void WobbleProp::Draw() {
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 var_f1_86;
    f32 var_f2_70;
    f32 var_f31_54;
    f32 var_f3_100;

    if ((MKMaterial *) this->unkD4 != NULL) {
        var_f31_54 = MKRand_Float((int *) &gViewSeed, 0.8f, 1.0f);
        if ((u8) this->unkCC != 0) {
            var_f31_54 *= (0.5f * this->unkD0 * MKRand_Float((int *) &gViewSeed, -0.5f, 0.5f)) + 1.0f;
        }
        var_f2_70 = 0.2f * var_f31_54;
        if (var_f2_70 < 1.0f) {

        } else {
            var_f2_70 = 1.0f;
        }
        if (var_f2_70 > 0.0f) {

        } else {
            var_f2_70 = 0.0f;
        }
        var_f1_86 = 0.8f * var_f31_54;
        if (var_f1_86 < 1.0f) {

        } else {
            var_f1_86 = 1.0f;
        }
        if (var_f1_86 > 0.0f) {

        } else {
            var_f1_86 = 0.0f;
        }
        var_f3_100 = 1.0f;
        if (var_f31_54 < var_f3_100) {
            var_f3_100 = var_f31_54;
        }
        if (var_f3_100 > 0.0f) {

        } else {
            var_f3_100 = 0.0f;
        }
        sp8 = var_f3_100;
        spC = var_f1_86;
        sp10 = var_f2_70;
        sp14 = 1.0f;
        sp18 = (f64) sp8;
        sp20 = (f64) sp10;
        MKMaterial_SetColor(this->unkD4, *((MKVector4 *) &sp18));
    }
    GameProp::Draw();
}

#if 0 // DRAFT: undefined identifier 'spA0'
void *WobbleProp::Update() {
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    MKVector3 sp78;
    MKVector3 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    MKVector3 *temp_r30_287;
    f32 temp_f28_174;
    f32 temp_f28_351;
    f32 temp_f29_193;
    f32 temp_f2_252;
    f32 temp_f31_209;
    f32 var_f1_322;
    f64 temp_f0_191;
    f64 temp_f0_332;
    s32 temp_ret_322;
    void *temp_r3_231;
    void *temp_r4_249;
    void *temp_r4_328;
    void *temp_r5_188;

    GameProp::Update();
    M2C_FIELD(*gb, M2C_UNK (**)(f64 *, void **), 0x2C)(&sp98, gb);
    spB8 = sp98;
    spC0 = spA0;
    temp_f28_174 = 120.00001f + M2C_FIELD(*gb, f32 (**)(void **, f64), 0x28)(gb, sp98);
    if ((u8) this->unkCC != 0) {
        this->unkD0 -= gUpdateTimeDelta;
        if (this->unkD0 < 0.0f) {
            this->unkCC = 0;
        }
    }
    temp_r5_188 = this->unkC8;
    temp_f0_191 = M2C_FIELD(temp_r5_188, f64 *, 0) - spB8;
    sp38 = temp_f0_191;
    temp_f29_193 = temp_f28_174 * temp_f28_174;
    spA8 = temp_f0_191;
    sp40 = M2C_FIELD(temp_r5_188, f32 *, 8) - (f32) spC0;
    spB0 = (f64) sp40;
    temp_f31_209 = ((f32) spB0 * (f32) spB0) + (((f32) spA8 * (f32) spA8) + ((*(f32 *) ((u8 *) &spA8 + 0x4)) * (*(f32 *) ((u8 *) &spA8 + 0x4))));
    if (temp_f31_209 < temp_f29_193) {
        M2C_FIELD(temp_r5_188, f64 *, 0x10) = (f64) M2C_FIELD(temp_r5_188, f64 *, 0);
        M2C_FIELD(temp_r5_188, f64 *, 0x18) = (f64) M2C_FIELD(temp_r5_188, f32 *, 8);
        sp68 = Normalise(*((MKVector3 *) &spA8));
        sp78 = sp68.operator*(temp_f28_174);
        sp8 = spB8 + M2C_BITWISE(f64, sp78);
        temp_r3_231 = this->unkC8;
        sp88 = sp8;
        sp10 = (f32) spC0 + sp78.unk8;
        M2C_FIELD(temp_r3_231, f64 *, 0) = sp8;
        M2C_FIELD(temp_r3_231, f32 *, 8) = (f64) sp10;
        this->unkCC = 1;
        sp90 = (f64) sp10;
        if (((s32) M2C_FIELD(checked_cast<WobblePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xE4) != 0) && ((u8) this->unkDC == 0)) {
            temp_r4_249 = this->unkC8;
            temp_f2_252 = temp_f28_174 * M2C_FIELD(checked_cast<WobblePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0xE8);
            sp28 = M2C_FIELD(temp_r4_249, f64 *, 0) - *(temp_r4_249 + 0x10);
            sp58 = sp28;
            sp30 = M2C_FIELD(temp_r4_249, f32 *, 8) - (f32) M2C_FIELD(temp_r4_249, f64 *, 0x18);
            sp60 = (f64) sp30;
            if ((((f32) sp60 * (f32) sp60) + (((f32) sp58 * (f32) sp58) + ((*(f32 *) ((u8 *) &sp58 + 0x4)) * (*(f32 *) ((u8 *) &sp58 + 0x4))))) >= (temp_f2_252 * temp_f2_252)) {
                this->unkDC = 1;
                if (KDSound_IsVoicePlaying(this->unkD8) != 0) {
                    KDSound_Stop((int *) &this->unkD8);
                }
                temp_r30_287 = (MKVector3 *) (((u8 *) this->unk8) + 0x30);
                this->unkD8 = KDSound_Play3d(M2C_FIELD(checked_cast<WobblePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xE4), temp_r30_287, 0U, -1, 0.0f, 0U);
                this->unkE8 = KDSound_GetVolume(this->unkD8);
                this->unkE4 = 0.5f;
            }
        }
        this->unkD0 = 2.0f;
    } else {
        this->unkDC = 0;
    }
    if ((KDSound_IsVoicePlaying(this->unkD8) != 0) && (this->unkE4 == 0.0f)) {
        KDSound_Stop((int *) &this->unkD8);
    }
    temp_ret_322 = KDSound_IsVoicePlaying(this->unkD8);
    var_f1_322 = M2C_BITWISE(f32, temp_ret_322);
    if ((temp_ret_322 != 0) && (temp_f31_209 >= temp_f29_193)) {
        temp_r4_328 = this->unkC8;
        temp_f0_332 = M2C_FIELD(temp_r4_328, f64 *, 0) - *(temp_r4_328 + 0x10);
        sp18 = temp_f0_332;
        sp48 = temp_f0_332;
        sp20 = M2C_FIELD(temp_r4_328, f32 *, 8) - (f32) M2C_FIELD(temp_r4_328, f64 *, 0x18);
        sp50 = (f64) sp20;
        var_f1_322 = ((f32) sp48 * (f32) sp48) + ((*(f32 *) ((u8 *) &sp48 + 0x4)) * (*(f32 *) ((u8 *) &sp48 + 0x4)));
        temp_f28_351 = ((f32) sp50 * (f32) sp50) + var_f1_322;
        if ((this->unkE0 < 1.0f) && (temp_f28_351 < 1.0f)) {
            KDSound_SetVolume(this->unkD8, this->unkE8 * (2.0f * this->unkE4));
            this->unkE4 -= gUpdateTimeDelta;
            var_f1_322 = this->unkE4;
            if (var_f1_322 < 0.0f) {
                this->unkE4 = 0.0f;
            }
        }
        this->unkE0 = temp_f28_351;
    }
    return M2C_BITWISE(void *, var_f1_322);
}
#endif

void WobbleProp::Message(MKMessage *arg0) {
    GameProp::Message(arg0);
}

s32 WobbleProp::LoadDone() {
    WobblePropDescriptor *temp_r3;

    GameProp::LoadDone();
    this->unkC8 = MKDynamicBone_GetDynamicBone(this->unk4, ((Animation *) (MKModel_GetAnimation(this->unk4)))->GetNodeIndex("d_wobbler"));
    this->unkCC = 0;
    this->unkD0 = 0.0f;
    temp_r3 = checked_cast<WobblePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    this->unkD4 = Tools_GetMatchingMaterial(this->unk4, (const char *) M2C_FIELD(temp_r3, s8 **, 0xEC));
}

void WobbleProp::Init() {
    GameProp::Init();
    this->unkD8 = 0;
    this->unkDC = 0;
    this->unkE0 = 0.0f;
    this->unkE4 = 0.5f;
    this->unkE8 = 0.0f;
}

s32 WobblePropDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_472;

    var_r31_472 = 0;
    if ((GamePropDescriptor::LoadLine(arg0) != 0) || (arg0->LoadFloat("HitSoundSensitivity", &M2C_FIELD(this, f32 *, 0xE8), 0) != 0) || (arg0->LoadString("LampFlickerMatName", (const char **) &M2C_FIELD(this, s8 **, 0xEC), 0) != 0) || (KDSound_LoadLine(arg0, "hitSound", (int *) &M2C_FIELD(this, s32 *, 0xE4)) != 0)) {
        var_r31_472 = 1;
    }
    return var_r31_472;
}

void WobblePropDescriptor::Init() {
    GamePropDescriptor::Init();
    M2C_FIELD(this, s8 **, 0xEC) = NULL;
    M2C_FIELD(this, s32 *, 0xE4) = GS_PLACEHOLDER;
    M2C_FIELD(this, f32 *, 0xE8) = 0.05f;
}
