#include "spyro/source/MoltenMetalBucket.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/KDFaderObject.h"
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDPositionProperty.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/LiquidFX.h"
#include "spyro/source/ManagedLight.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include <m2c_macros.h>

extern MKSceneManager *gMK;
#if 0 // DRAFT: expression syntax error
static s8 *pMoltenMetalBucketEvents[3] = (signed char *) ({ "emitStart", "emitStop", NULL });
#endif
static s32 lit_655 = 1;

#if 0 // DRAFT: ')' expected
void MoltenMetalBucket::Stop() {
    u8 temp_r3_76;

    this->unk80->SetAnim(M2C_FIELD(checked_cast<MoltenMetalBucketDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKAnim **, 0x100), 1.0f, 0.25f, 0, -1);
    temp_r3_76 = this->unk178;
    this->unk178 = (temp_r3_76 & ~0x80) | ((CLZ((temp_r3_76 >> 7U) & 1) << 2) & 0x80);
}
#endif

#if 0 // DRAFT: ')' expected
void MoltenMetalBucket::Start() {
    u8 temp_r3_106;

    this->unk80->SetAnim(M2C_FIELD(checked_cast<MoltenMetalBucketDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKAnim **, 0xFC), 1.0f, 0.25f, 0, -1);
    temp_r3_106 = this->unk178;
    this->unk178 = (temp_r3_106 & ~0x80) | ((CLZ((temp_r3_106 >> 7U) & 1) << 2) & 0x80);
}
#endif

#if 0 // DRAFT: ')' expected
void MoltenMetalBucket::PourStop() {
    this->unk80->SetAnim(M2C_FIELD(checked_cast<MoltenMetalBucketDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKAnim **, 0xF8), 0.25f, 0.25f, 0, -1);
}
#endif

#if 0 // DRAFT: ')' expected
void MoltenMetalBucket::Pour() {
    this->unk80->SetAnim(M2C_FIELD(checked_cast<MoltenMetalBucketDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKAnim **, 0xF4), 0.25f, 0.25f, 0, -1);
}
#endif

void MoltenMetalBucket::Message(MKMessage *arg0) {
    s32 temp_r0_177;

    temp_r0_177 = arg0->unk0;
    switch (temp_r0_177) {                          /* irregular */
    case 0xB5:
        Pour();
        break;
    case 0xB4:
        PourStop();
        break;
    }
    GameProp::Message(arg0);
    ((KDSoundPlayer *) &this->unkEC)->Message(arg0);
    ((KDSoundPlayer *) &this->unk114)->Message(arg0);
    ((KDSoundPlayer *) &this->unk13C)->Message(arg0);
}

#if 0 // DRAFT: ')' expected
void *MoltenMetalBucket::Update() {
    s8 sp1A8;
    s32 sp1A4;
    s32 sp1A0;
    s32 sp19C;
    f32 sp198;
    s32 sp194;
    s8 sp193;
    s8 sp192;
    s16 sp190;
    f32 sp18C;
    f32 sp188;
    f32 sp184;
    f32 sp180;
    f32 sp17C;
    f32 sp178;
    f32 sp170;
    f32 sp16C;
    f32 sp168;
    f32 sp160;
    f32 sp15C;
    f32 sp158;
    MKVector3 sp148;
    MKVector3 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f32 spA0;
    f64 sp98;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f64 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    s32 spC;
    s32 sp8;
    f32 temp_f30_382;
    f32 temp_f3_470;
    f32 var_f29_377;
    f32 var_f3_372;
    f32 var_f4_282;
    f32 var_f4_349;
    f64 temp_f0_434;
    f64 temp_f1_288;
    f64 temp_f1_294;
    f64 temp_f1_298;
    f64 temp_f4_413;
    s32 temp_r3_317;
    s32 var_r0_327;
    u8 var_r30_384;
    void *temp_r3_225;
    void *temp_r3_240;
    void *temp_r4_533;
    void *temp_r4_554;
    void *temp_r4_575;

    GameProp::Update();
    temp_r3_225 = ((u8 *) this->unk8) + 0x30;
    sp18 = M2C_FIELD(temp_r3_225, f64 *, 0) - this->unkC8;
    this->unkD8 = sp18;
    sp20 = M2C_FIELD(temp_r3_225, f32 *, 8) - this->unkD0;
    sp118 = sp18;
    this->unkE0 = (f64) sp20;
    temp_r3_240 = this->unk8;
    sp120 = (f64) sp20;
    this->unkC8 = M2C_FIELD(temp_r3_240, f64 *, 0x30);
    M2C_FIELD(this, f32 *, 0xD0) = (f64) M2C_FIELD(temp_r3_240, f64 *, 0x38);
    if (((u8) this->unkE8 >> 7U) & 1) {
        MKModel_CalculateRefPointWorldPosition(this->unk4, M2C_FIELD(checked_cast<MoltenMetalBucketDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xE4), &sp148);
        MKModel_CalculateRefPointWorldPosition(this->unk4, M2C_FIELD(checked_cast<MoltenMetalBucketDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xE8), &sp138);
        sp98 = M2C_BITWISE(f64, sp138) - M2C_BITWISE(f64, sp148);
        sp108 = sp98;
        spA0 = sp138.unk8 - sp148.unk8;
        sp110 = (f64) spA0;
        var_f4_282 = ((f32) sp110 * (f32) sp110) + (((f32) sp108 * (f32) sp108) + ((*(f32 *) ((u8 *) &sp108 + 0x4)) * (*(f32 *) ((u8 *) &sp108 + 0x4))));
        if (var_f4_282 > 1e-12f) {
            if (var_f4_282 > 0.0f) {
                temp_f1_288 = __frsqrte(var_f4_282);
                temp_f1_294 = 0.5 * temp_f1_288 * -(((f64) var_f4_282 * (temp_f1_288 * temp_f1_288)) - 3.0);
                temp_f1_298 = 0.5 * temp_f1_294 * -(((f64) var_f4_282 * (temp_f1_294 * temp_f1_294)) - 3.0);
                var_f4_282 = (f32) ((f64) var_f4_282 * (0.5 * temp_f1_298 * -(((f64) var_f4_282 * (temp_f1_298 * temp_f1_298)) - 3.0)));
            } else if (var_f4_282 < M2C_BITWISE(f32, 0.0)) {
                var_f4_282 = __float_nan;
            } else {
                sp10 = var_f4_282;
                temp_r3_317 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_317) {              /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_327 = 1;
                    } else {
                        var_r0_327 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_327 = 5;
                    } else {
                        var_r0_327 = 3;
                    }
                    break;
                default:
                    var_r0_327 = 4;
                    break;
                }
                if (var_r0_327 == 1) {
                    var_f4_282 = __float_nan;
                }
            }
            var_f4_349 = 1.0f / var_f4_282;
        } else {
            var_f4_349 = 0.0f;
        }
        sp8C = (*(f32 *) ((u8 *) &sp108 + 0x4)) * var_f4_349;
        sp88 = (f32) sp108 * var_f4_349;
        sp90 = (f32) sp110 * var_f4_349;
        sp128 = (f64) sp88;
        sp130 = (f64) sp90;
        if ((*(f32 *) ((u8 *) &sp128 + 0x4)) <= 0.0f) {
            var_f3_372 = 1.5f * (*(f32 *) ((u8 *) &sp128 + 0x4));
            if (var_f3_372 < 0.0f) {
                var_f3_372 = -var_f3_372;
            }
            var_f29_377 = 0.0f;
            sp58 = 0.0f;
            temp_f30_382 = 0.5f + var_f3_372;
            var_r30_384 = 0;
            sp5C = -3000.0f;
            sp60 = 0.0f;
            spC8 = (f64) sp58;
            sp158 = 0.0f;
            sp15C = 0.0f;
            sp160 = 0.0f;
            sp168 = 0.0f;
            sp16C = 0.0f;
            sp170 = 0.0f;
            sp178 = 0.0f;
            sp17C = 0.0f;
            sp180 = 0.0f;
            sp184 = 1.0f;
            sp188 = 0.0f;
            sp18C = 0.0f;
            sp190 = 0;
            sp192 = 0;
            sp193 = 0;
            sp194 = 0;
            sp198 = 3.4028235e38f;
            sp19C = 0;
            sp1A0 = 0;
            sp1A4 = -1;
            sp1A8 = 0;
            spD0 = (f64) sp60;
            temp_f4_413 = M2C_BITWISE(f64, sp148);
            sp48 = temp_f4_413 + spC8;
            sp80 = 0.0f;
            sp78 = 0.0f;
            sp7C = -50.0f;
            sp50 = sp148.unk8 + (f32) spD0;
            spE8 = (f64) sp78;
            spD8 = sp48;
            spE0 = (f64) sp50;
            spF0 = (f64) sp80;
            temp_f0_434 = temp_f4_413 + spE8;
            sp68 = temp_f0_434;
            spF8 = temp_f0_434;
            sp70 = sp148.unk8 + (f32) spF0;
            sp100 = (f64) sp70;
            if (MKCollision_RayCollide(*((MKVector3 *) &spF8), *((MKVector3 *) &spD8), (MKCollisionResult *) &sp158, (MKCollisionMode) 4, 0x0C000000) != 0) {
                var_f29_377 = sp15C;
                var_r30_384 = 1;
                this->unk168 = (f64) sp158;
                this->unk170 = (f64) sp160;
            }
            sp8 = -1;
            this->unk180.Init((MKProp *) this, 1, 0, 0, 0, 0, 0, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
            temp_f3_470 = 100.0f * temp_f30_382;
            sp38 = sp128 * (f64) temp_f3_470;
            sp30 = 1.5f;
            sp40 = (f32) sp130 * temp_f3_470;
            sp28 = temp_f30_382;
            sp2C = temp_f30_382;
            spB8 = sp38;
            spC0 = (f64) sp40;
            spA8 = (f64) sp28;
            spB0 = (f64) sp30;
            sp8 = 0;
            spC = 0;
            this->unk17C->Emit(lit_655, sp148, *((MKVector3 *) &spB8), *((MKVector3 *) &spA8), 3.0f, var_f29_377, var_r30_384, &this->unk180, M2C_ERROR(/* Unable to find stack arg 0x0 in block */), M2C_ERROR(/* Unable to find stack arg 0x4 in block */));
        }
    }
    if (this->unk80->CheckEvent(0) != 0) {
        this->unkE8 |= 0x80;
    } else if (this->unk80->CheckEvent(1) != 0) {
        this->unkE8 &= ~0x80;
    }
    if ((s32) M2C_FIELD(checked_cast<MoltenMetalBucketDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x104) != 0) {
        temp_r4_533 = checked_cast<MoltenMetalBucketDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        sp8 = 1;
        ((KDSoundFader *) &this->unkEC)->Update(M2C_FIELD(temp_r4_533, s32 *, 0x104), 1U, ((u8) this->unk178 >> 7U) & 1, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    }
    if ((s32) M2C_FIELD(checked_cast<MoltenMetalBucketDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x108) != 0) {
        temp_r4_554 = checked_cast<MoltenMetalBucketDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        sp8 = 1;
        ((KDSoundFader *) &this->unk114)->Update(M2C_FIELD(temp_r4_554, s32 *, 0x108), 1U, ((u8) this->unkE8 >> 7U) & 1, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    }
    if ((s32) M2C_FIELD(checked_cast<MoltenMetalBucketDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x10C) != 0) {
        temp_r4_575 = checked_cast<MoltenMetalBucketDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        sp8 = 1;
        ((KDSoundFader *) &this->unk13C)->Update(M2C_FIELD(temp_r4_575, s32 *, 0x10C), 1U, ((u8) this->unkE8 >> 7U) & 1, NULL, (MKVector3 *) &this->unk168, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    }
}
#endif

#if 0 // DRAFT: expression syntax error
f32 MoltenMetalBucket::Resolve() {
    void *temp_r31_612;
    void *temp_r31_621;
    void *temp_r31_630;

    KDPropEx::Resolve();
    temp_r31_612 = checked_cast<MoltenMetalBucketDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    ((KDSoundFader *) &this->unkEC)->Init(M2C_FIELD(checked_cast<MoltenMetalBucketDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x110), M2C_FIELD(temp_r31_612, f32 *, 0x114));
    temp_r31_621 = checked_cast<MoltenMetalBucketDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    ((KDSoundFader *) &this->unk114)->Init(M2C_FIELD(checked_cast<MoltenMetalBucketDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x118), M2C_FIELD(temp_r31_621, f32 *, 0x11C));
    temp_r31_630 = checked_cast<MoltenMetalBucketDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    ((KDSoundFader *) &this->unk13C)->Init(M2C_FIELD(checked_cast<MoltenMetalBucketDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x120), M2C_FIELD(temp_r31_630, f32 *, 0x124));
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *[3]' to 'const char **'
s32 MoltenMetalBucket::LoadDone() {
    GameProp::LoadDone();
    this->unk80->InitEvents(pMoltenMetalBucketEvents);
    this->unk17C = checked_cast<LiquidFX *, MKProp>(gMK->CreateProp(""));
}
#endif

void MoltenMetalBucket::Deinit() {
    KDSound_Stop((int *) &this->unkEC);
    KDSound_Stop((int *) &this->unk114);
    KDSound_Stop((int *) &this->unk13C);
    GameProp::Deinit();
}

void MoltenMetalBucket::Init() {
    GameProp::Init();
    this->unkC8 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 0xD0) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unkD8 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    this->unkE0 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unkE8 &= ~0x80;
    this->unk178 &= ~0x80;
    M2C_FIELD(this, f32 *, 0x168) = 0.0f;
    M2C_FIELD(this, f32 *, 0x16C) = 0.0f;
    M2C_FIELD(this, f32 *, 0x170) = 0.0f;
}

void MoltenMetalBucketDescriptor::Deinit() {
    KDPropExDescriptor::Deinit();
    MKMaterial_Destroy(this->unkEC);
}

#if 0 // DRAFT: undefined identifier 'unkE4'
void MoltenMetalBucketDescriptor::Resolve() {
    MKPropDescriptor::Resolve();
    this->unkE4 = MKModel_GetRefPointIndex(this->unk2C, "");
    this->unkE8 = MKModel_GetRefPointIndex(this->unk2C, "");
    this->unkEC = MKMaterial_Create"";
    this->unkF0 = (long) (((MKAnimScript *) this->unk34)->GetAnim(""));
    this->unkF4 = (long) (((MKAnimScript *) this->unk34)->GetAnim(""));
    this->unkF8 = (long) (((MKAnimScript *) this->unk34)->GetAnim(""));
    this->unkFC = (long) (((MKAnimScript *) this->unk34)->GetAnim(""));
    this->unk100 = (long) (((MKAnimScript *) this->unk34)->GetAnim(""));
}
#endif

s32 MoltenMetalBucketDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_818;

    var_r31_818 = 0;
    if ((GamePropDescriptor::LoadLine(arg0) != 0) || (KDSound_LoadLine(arg0, "", (int *) &this->unk104) != 0) || (KDSound_LoadLine(arg0, "", (int *) &this->unk108) != 0) || (KDSound_LoadLine(arg0, "", (int *) &this->unk10C) != 0) || (arg0->LoadFloat("", &this->unk110, 0) != 0) || (arg0->LoadFloat("", &this->unk114, 0) != 0) || (arg0->LoadFloat("", &this->unk118, 0) != 0) || (arg0->LoadFloat("", &this->unk11C, 0) != 0) || (arg0->LoadFloat("", &this->unk120, 0) != 0) || (arg0->LoadFloat("", &this->unk124, 0) != 0)) {
        var_r31_818 = 1;
    }
    return var_r31_818;
}

void MoltenMetalBucketDescriptor::Init() {
    GamePropDescriptor::Init();
    this->unk104 = 0;
    this->unk108 = 0;
    this->unk10C = 0;
    this->unk110 = 0.25f;
    this->unk114 = 0.25f;
    this->unk118 = 0.25f;
    this->unk11C = 0.25f;
    this->unk120 = 0.25f;
    this->unk124 = 0.25f;
}
