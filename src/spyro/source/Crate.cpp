#include "spyro/source/Crate.h"
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
#include "common/Source/MKMemoryCard.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/CameraData.h"
#include "spyro/source/Collectable.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameData.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDPositionProperty.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/KDShatter2.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/Level.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/SeeSaw.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/ShockWave.h"
#include "spyro/source/SpyroTools.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "common/Source/system_extras.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDRandom.h"
#include <m2c_macros.h>

f64 fmod(void ***, f32, f64, f64);                  /* extern */
s32 stricmp(s8 *, M2C_UNK *);                       /* extern */
extern s32 GS_PLACEHOLDER;
extern s8 gAssertBool;
extern void **gMK;
extern f32 gUpdateTimeDelta;
extern void **gb;
extern s8 *pCollisionName;
#if 0 // DRAFT: illegal use of incomplete struct/union/class
static struct _struct_collectableTypes_0x14 collectableTypes[4]; /* unable to generate initializer: non-zero padding */
static M2C_UNK crateDescFlags;                      /* unable to generate initializer: unknown type */
static s8 *unshatteredNames[0x10];
#endif
#if 0 // DRAFT: illegal implicit conversion from 'const char[9]' to
static s8 *CRATE_REF_TARGET = "r_target";
#endif

#if 0 // DRAFT: declaration syntax error
static M2C_UNK .L_80359889;                         /* unable to generate initializer: unknown type; const */
static s8 .L_80359893[0xA] = { 0x50, 0x30, 0x30, 0x32, 0x33, 0x5F, 0x47, 0x65, 0x6D, 0 }; /* const */
static M2C_UNK .L_8035989D;                         /* unable to generate initializer: unknown type; const */

u8 ShatterObject::Shatter(bool arg0, MKVector3 *arg1, int arg2, MKVector3 *arg3) {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKVector3 *var_r5_0;
    MKVector3 *var_r7_0;
    f32 var_f0_106;
    s32 temp_r0_130;
    s32 var_r4_124;
    u8 var_r31_131;

    var_r5_0 = arg1;
    var_r7_0 = arg3;
    sp10 = 0.0f;
    sp8 = 0.0f;
    spC = this->unk7C->unk6C;
    sp20 = (f64) sp10;
    sp18 = (f64) sp8;
    if (var_r7_0 != NULL) {

    } else {
        var_r7_0 = (MKVector3 *) &sp18;
    }
    this->unk20 = M2C_FIELD(var_r7_0, f64 *, 0);
    this->unk28 = M2C_FIELD(var_r7_0, f64 *, 8);
    if (arg0 != 0) {
        var_f0_106 = 0.2f;
    } else {
        var_f0_106 = 1.0f;
    }
    this->unk38 = var_f0_106;
    if (var_r5_0 != NULL) {

    } else {
        var_r5_0 = this->unk80->unk8 + 0x30;
    }
    if (arg2 == -1) {
        var_r4_124 = this->unk7C->unk8C;
    } else {
        var_r4_124 = arg2;
    }
    KDShatter2::Shatter(var_r4_124, var_r5_0);
    temp_r0_130 = this->unk44;
    var_r31_131 = 0;
    if ((temp_r0_130 == 1) || (temp_r0_130 == 2)) {
        var_r31_131 = 1;
    }
    if (var_r31_131 != 0) {
        this->unk6C = 1;
        this->unk78.Send(this->unk80);
    }
    return var_r31_131;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void ShatterObject::Draw() {
    KDShatter2::Draw(1U);
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void ShatterObject::Update() {
    KDShatter2::Update();
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void ShatterObject::Reset() {
    KDShatter2::Reset();
    this->unk3C = M2C_FIELD(this->unk80->unk0, f32 *, 0x20);
    this->unk6C = 0;
}
#endif

#if 0 // DRAFT: function call 'strnicmp(signed char *, const char[1], int)' does not match
void ShatterObject::LoadDone() {
    MKProp *temp_r3_260;
    ShatterObjectDescriptor *temp_r4_291;
    s16 temp_r29_224;
    s32 var_r28_226;
    s8 *temp_r3_233;

    this->unk68 = 0;
    this->unk6C = 1;
    this->unk70 = this->unk80;
    this->unk74 = 0;
    temp_r29_224 = MKModel_GetNmbrOfSubObjects(this->unk80->unk4, (SubObjectType) 0);
    var_r28_226 = 0;
loop_7:
    if (var_r28_226 < temp_r29_224) {
        temp_r3_233 = MKModel_GetSubObjectName(this->unk80->unk4, (SubObjectType) 0, var_r28_226);
        if (strnicmp(temp_r3_233, "", 2) == 0) {
            MKModel_EnableSubObject(this->unk80->unk4, (SubObjectType) 0, var_r28_226, 0U, 1U);
            if (((s8 *) pCollisionName != NULL) && (stricmp(temp_r3_233) == 0)) {
                ((KDProp *) this->unk80)->AddCollisionSubObject(var_r28_226, (MKCollisionInfo *) &this->unk68);
            } else {
                temp_r3_260 = this->unk80;
                ((KDProp *) temp_r3_260)->AddCollisionSubObject(var_r28_226, temp_r3_260 + 0x70);
            }
        }
        var_r28_226 += 1;
        goto loop_7;
    }
    this->unk6C = 0;
    this->unk0 = this->unk7C->unk7C;
    this->unk4 = this->unk7C->unk78;
    this->unk10 = this->unk7C->unk80;
    this->unk8 = this->unk7C->unk84;
    this->unk14 = this->unk7C->unk74;
    this->unk18 = this->unk7C->unk70;
    temp_r4_291 = this->unk7C;
    this->unk54 = temp_r4_291;
    this->unk58 = &temp_r4_291->unk24;
    this->unk5C = &temp_r4_291->unk48;
    KDShatter2::LoadDone(this->unk80->unk4, NULL);
}
#endif

void ShatterObject::LoadLine(MKIniLine *arg0) {
    this->unk78.LoadLine(arg0, "");
}

#if 0 // DRAFT: illegal use of non-static member
void ShatterObject::Deinit() {
    KDShatter2::Deinit();
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void ShatterObject::Init(ShatterObjectDescriptor *arg0, KDPropEx *arg1) {
    this->unk7C = arg0;
    this->unk80 = (MKProp *) arg1;
    KDShatter2::Init();
}
#endif

#if 0 // DRAFT: function call 'MKModel_SubObjectExists(MKModel *, SubObjectType, signed
void ShatterObjectDescriptor::LoadDone(MKModel *arg0, const char *arg1) {
    s32 sp10;
    s32 spC;
    s32 sp8;
    s32 temp_r0_378;
    s32 temp_r0_409;
    s32 temp_r0_440;
    s32 var_r25_367;
    s32 var_r25_398;
    s32 var_r26_429;
    s32 var_r27_368;
    s32 var_r27_400;
    s32 var_r28_369;
    s32 var_r28_399;
    s32 var_r28_431;
    s32 var_r31_430;
    u16 temp_r0_385;
    u16 temp_r0_416;
    u16 temp_r0_447;

    if ((u16) this->unk0 != 0) {
        var_r25_367 = 0;
        var_r27_368 = 0;
        var_r28_369 = 0;
loop_3:
        temp_r0_385 = this->unk0;
        if (var_r25_367 < (s32) temp_r0_385) {
            temp_r0_378 = var_r27_368 + 2;
            gAssertBool = MKModel_SubObjectExists(arg0, (SubObjectType) 0, *(unshatteredNames + var_r28_369), (int *) &sp10);
            var_r28_369 += 4;
            var_r25_367 += 1;
            var_r27_368 += 2;
            *(this + temp_r0_378) = (s16) sp10;
            goto loop_3;
        }
        M2C_FIELD((this + (temp_r0_385 * 2)), s16 *, 2) = 0xFFFF;
    }
    if ((u16) this->unk24 != 0) {
        var_r25_398 = 0;
        var_r28_399 = 0;
        var_r27_400 = 0;
loop_8:
        temp_r0_416 = this->unk24;
        if (var_r25_398 < (s32) temp_r0_416) {
            temp_r0_409 = var_r28_399 + 0x26;
            gAssertBool = MKModel_SubObjectExists(arg0, (SubObjectType) 0, *(unshatteredNames + 0x40 + var_r27_400), (int *) &spC);
            var_r27_400 += 4;
            var_r25_398 += 1;
            var_r28_399 += 2;
            *(this + temp_r0_409) = (s16) spC;
            goto loop_8;
        }
        M2C_FIELD((this + (temp_r0_416 * 2)), s16 *, 0x26) = 0xFFFF;
    }
    if ((u16) this->unk48 != 0) {
        var_r26_429 = 0;
        var_r31_430 = 0;
        var_r28_431 = 0;
loop_13:
        temp_r0_447 = this->unk48;
        if (var_r26_429 < (s32) temp_r0_447) {
            temp_r0_440 = var_r31_430 + 0x4A;
            gAssertBool = MKModel_SubObjectExists(arg0, (SubObjectType) 0, *(unshatteredNames + 0x80 + var_r28_431), (int *) &sp8);
            var_r28_431 += 4;
            var_r26_429 += 1;
            var_r31_430 += 2;
            *(this + temp_r0_440) = (s16) sp8;
            goto loop_13;
        }
        M2C_FIELD((this + (temp_r0_447 * 2)), s16 *, 0x4A) = 0xFFFF;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to
u8 ShatterObjectDescriptor::LoadLine(MKIniLine *arg0, const char *arg1) {
    MKIniLine *var_r31_569;
    MKIniLine *var_r31_601;
    MKIniLine *var_r31_633;

    if ((arg0->LoadString("", &pCollisionName, 0) != 0) || (arg0->LoadFloat("", &this->unk6C, 0) != 0) || (arg0->LoadFloat("", &this->unk70, 0) != 0) || (arg0->LoadFloat("", &this->unk78, 0) != 0) || (arg0->LoadFloat("", &this->unk7C, 0) != 0) || (arg0->LoadFloat("", &this->unk80, 0) != 0) || (arg0->LoadFloat("", &this->unk84, 0) != 0) || (arg0->LoadFloat("", &this->unk74, 0) != 0) || (KDSound_LoadLine(arg0, "", (int *) &this->unk8C) != 0)) {
        return 1U;
    }
    if (arg0->IsField("") != 0) {
        var_r31_569 = arg0->unkC->GetSubLine(arg0);
loop_13:
        if (var_r31_569 != NULL) {
            unshatteredNames[this->unk0] = var_r31_569->GetFieldName();
            this->unk0 += 1;
            var_r31_569 = var_r31_569->unkC->GetNextLine(var_r31_569);
            goto loop_13;
        }
        return 1U;
    }
    if (arg0->IsField("") != 0) {
        var_r31_601 = arg0->unkC->GetSubLine(arg0);
loop_18:
        if (var_r31_601 != NULL) {
            (unshatteredNames + 0x40)[this->unk24] = var_r31_601->GetFieldName();
            this->unk24 += 1;
            var_r31_601 = var_r31_601->unkC->GetNextLine(var_r31_601);
            goto loop_18;
        }
        return 1U;
    }
    if (arg0->IsField("") != 0) {
        var_r31_633 = arg0->unkC->GetSubLine(arg0);
loop_23:
        if (var_r31_633 != NULL) {
            (unshatteredNames + 0x80)[this->unk48] = var_r31_633->GetFieldName();
            this->unk48 += 1;
            var_r31_633 = var_r31_633->unkC->GetNextLine(var_r31_633);
            goto loop_23;
        }
        return 1U;
    }
    return 0U;
}
#endif

void ShatterObjectDescriptor::Init(KDPropExDescriptor *arg0) {
    this->unk88 = arg0;
    pCollisionName = NULL;
    this->unk0 = 0;
    this->unk2 = -1;
    this->unk24 = 0;
    this->unk26 = -1;
    this->unk48 = 0;
    this->unk4A = -1;
    this->unk70 = 1250.0f;
    this->unk6C = 100.7f;
    this->unk80 = 3.0f;
    this->unk78 = 0.3f;
    this->unk7C = 2000.0f;
    this->unk74 = 4.0f;
    this->unk84 = 0.3f;
    this->unk8C = GS_PLACEHOLDER;
}

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void Crate::UpdateShadow(bool arg0) {
    MKVector3 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f1_773;
    f32 var_f0_709;
    f32 var_f0_723;
    f64 temp_f0_754;
    f64 temp_f0_766;

    if (arg0 != 0) {
        var_f0_709 = (1.8f * gUpdateTimeDelta) + this->unk168;
        if (var_f0_709 < 1.0f) {

        } else {
            var_f0_709 = 1.0f;
        }
        this->unk168 = var_f0_709;
    } else {
        var_f0_723 = -((1.8f * gUpdateTimeDelta) - this->unk168);
        if (var_f0_723 > 0.0f) {

        } else {
            var_f0_723 = 0.0f;
        }
        this->unk168 = var_f0_723;
    }
    if (this->unk168 != 0.0f) {
        MKModel_CalculateCentre(this->unk4, &sp78);
        sp20 = 0.0f;
        sp18 = 0.0f;
        sp1C = 10.0f;
        sp50 = (f64) sp20;
        sp48 = (f64) sp18;
        KDRand_Box(4.0f);
        temp_f0_754 = sp58 + M2C_BITWISE(f64, sp78);
        sp28 = temp_f0_754;
        sp68 = temp_f0_754;
        sp30 = sp60 + sp78.unk8;
        sp70 = (f64) sp30;
        temp_f0_766 = sp68 + sp48;
        sp8 = temp_f0_766;
        temp_f1_773 = (f32) sp70 + (f32) sp50;
        sp38 = temp_f0_766;
        sp10 = temp_f1_773;
        sp40 = (f64) sp10;
        ((SpyroLighting *) (M2C_FIELD(*gb, SpyroLighting *(**)(void **, f32, f32), 0x38)(gb, temp_f1_773, (f32) sp70)))->ApplyPointLight((MKVector3) &sp38, 500.0f, this->unk168);
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'double *' to
void Crate::Shatter(bool arg0) {
    s32 sp78;
    f32 sp74;
    s8 sp72;
    s8 sp71;
    s8 sp70;
    s32 sp6C;
    f32 sp68;
    f64 sp60;
    f64 sp58;
    Crate *sp50;
    s32 sp4C;
    s32 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_855;
    f32 var_f1_823;
    f64 temp_f2_859;
    f64 temp_f3_857;
    s32 temp_r0_803;
    s32 temp_r10_861;
    void *temp_r3_811;
    void *temp_r3_880;
    void *temp_r7_883;
    void *temp_r8_853;

    temp_r0_803 = this->unkC8;
    if (temp_r0_803 != 0) {
        if (temp_r0_803 == 4) {
            return;
        }
        temp_r3_811 = checked_cast<CrateDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        if (M2C_FIELD(temp_r3_811, s32 *, 0x100) & 8) {
            this->unk70.unk4 = 0;
            SpawnContents();
            if ((s32) this->unkC8 == 2) {
                var_f1_823 = 550.0f;
            } else {
                var_f1_823 = 320.0f;
            }
            spC = var_f1_823;
            sp8 = 0.0f;
            sp10 = 0.0f;
            sp38 = (f64) sp8;
            sp40 = (f64) sp10;
            this->unkE0.Shatter(0U, NULL, -1, (MKVector3 *) &sp38);
            this->unkC8 = 4;
            if ((u8) M2C_FIELD(temp_r3_811, u8 *, 0x1B8) != 0) {
                sp4C = 0;
                temp_r8_853 = this->unk8;
                temp_f1_855 = M2C_FIELD(temp_r3_811, f32 *, 0x1C0);
                temp_f3_857 = M2C_FIELD(temp_r8_853, f64 *, 0x30);
                temp_f2_859 = M2C_FIELD(temp_r8_853, f64 *, 0x38);
                temp_r10_861 = M2C_FIELD(temp_r3_811, s32 *, 0x1C8);
                sp28 = temp_f3_857;
                sp48 = 1;
                sp50 = this;
                sp58 = temp_f3_857;
                sp60 = temp_f2_859;
                sp68 = temp_f1_855;
                sp70 = 1;
                sp71 = 0;
                sp72 = 1;
                sp6C = temp_r10_861;
                sp74 = 5.0f;
                sp78 = 0;
                sp30 = temp_f2_859;
                M2C_FIELD(*gMK, M2C_UNK (**)(void **, s32 *, M2C_UNK, M2C_UNK, void *, M2C_UNK, M2C_UNK, s32, f32, f64, f64), 0x94)(gMK, &sp48, 0, 1, ((u8 *) temp_r8_853) + 0x30, 1, 0, temp_r10_861, temp_f1_855, temp_f2_859, temp_f3_857);
            }
            temp_r3_880 = this->unk1DC.unk0;
            if (temp_r3_880 != NULL) {
                temp_r7_883 = this->unk8;
                sp18 = M2C_FIELD(temp_r7_883, f64 *, 0x30);
                sp20 = M2C_FIELD(temp_r7_883, f64 *, 0x38);
                ((ShockWave *) temp_r3_880)->Start((MKVector3) &sp18, M2C_FIELD(temp_r3_811, f32 *, 0x1BC), M2C_FIELD(temp_r3_811, f32 *, 0x1C0), 1U, 0U, 0U);
            }
        }
    }
}
#endif

void Crate::SpawnContents() {
    f64 sp10;
    f64 sp8;
    s32 temp_r0_923;
    s32 var_r30_913;
    s32 var_r6_924;
    u32 temp_r29_917;
    void *temp_r5_929;

    var_r30_913 = 0;
loop_6:
    if (var_r30_913 < (s32) this->unk180) {
        temp_r29_917 = this->unk17C;
        if (((GameStats *) &GameData::gameData[0x70])->GetGemAvailable((StatType) temp_r29_917) != 0) {
            temp_r0_923 = this->unk184;
            var_r6_924 = -1;
            if (temp_r0_923 > -1) {
                var_r6_924 = temp_r0_923 + var_r30_913;
            }
            temp_r5_929 = this->unk8;
            sp8 = M2C_FIELD(temp_r5_929, f64 *, 0x30);
            sp10 = M2C_FIELD(temp_r5_929, f64 *, 0x38);
            ((CollectableSpawner *) (M2C_FIELD(&(&gb)[temp_r29_917], CollectableSpawner **, 0x10)))->Spawn(*((MKVector3 *) &sp8), 1, 0.0f, 0.0f, var_r6_924, (MKProp *) this);
        }
        var_r30_913 += 1;
        goto loop_6;
    }
}

void Crate::Respawn() {
    this->unkCC += gUpdateTimeDelta;
    if (this->unkCC >= 1.0f) {
        this->unkCC = 1.0f;
        this->unkC8 = 1;
    }
}

#if 0 // DRAFT: ')' expected
void Crate::Shattering() {
    s32 var_ctr_1005;
    s32 var_r0_1000;
    void *temp_r4_997;

    this->unkE0.Update();
    if ((u8) this->unk178 != 0) {
loop_7:
        if (M2C_FIELD(&gb, f32 *, 0x30C) > this->unk174) {
            this->unk174 += 0.041f;
            temp_r4_997 = this->unkE0.unk50;
            if (temp_r4_997 != NULL) {
                var_r0_1000 = M2C_FIELD(temp_r4_997, s32 *, 0x1640);
            } else {
                var_r0_1000 = 0;
            }
            var_ctr_1005 = var_r0_1000;
            if (var_r0_1000 > 0) {
                do {
                    var_ctr_1005 -= 1;
                } while (var_ctr_1005 != 0);
            }
            goto loop_7;
        }
    }
    if ((s32) this->unkE0.unk44 != 1) {
        this->unk178 = 0;
        this->unk170 = M2C_FIELD(checked_cast<CrateDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x10C);
        if (this->unk170 <= 0.0f) {
            Disable();
            return;
        }
        this->unkC8 = 7;
    }
}
#endif

#if 0 // DRAFT: ')' expected
void Crate::Spin() {
    Matrix sp20;
    f64 sp18;
    f64 sp10;
    f32 temp_f1_1063;
    f32 temp_f1_1100;
    f32 temp_f31_1086;
    void *temp_r4_1074;

    temp_f1_1063 = this->unk16C - gUpdateTimeDelta;
    this->unk16C = temp_f1_1063;
    if (temp_f1_1063 < 0.0f) {
        Shatter(0);
        return;
    }
    temp_r4_1074 = this->unk8;
    sp10 = M2C_FIELD(temp_r4_1074, f64 *, 0x10);
    sp18 = M2C_FIELD(temp_r4_1074, f64 *, 0x18);
    temp_f31_1086 = 0.5f * (M2C_FIELD(checked_cast<CrateDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0xE4) - this->unk16C);
    M2C_STRUCT_COPY((s32) &unksp1C + 4, MKModel_GetWorldMatrix(this->unk188) - 4 + 4, 0x40);
    temp_f1_1100 = temp_f31_1086 - 0.5f;
    sp20.SetRotationYaw(KDMath_NormaliseAngle((*(f32 *) ((u8 *) &sp10 + 0x4)) + (6.2831855f * -((4.0f * (temp_f1_1100 * temp_f1_1100)) - 1.0f))));
    MKModel_SetWorldMatrix(this->unk188, sp20);
}
#endif

void Crate::Fall() {
    Shatter(0);
}

void Crate::Burn() {
    s32 var_ctr_1148;

    this->unk178 = 1;
    var_ctr_1148 = 5;
    do {
        var_ctr_1148 -= 1;
    } while (var_ctr_1148 != 0);
    this->unkC8 = 2;
}

#if 0 // DRAFT: undefined identifier 'TargetPositionRequest'
void Crate::Message(MKMessage *arg0) {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    Attachment *temp_r4_1259;
    f32 temp_f31_1310;
    f64 temp_f1_1246;
    f64 temp_f2_1247;
    s32 temp_r0_1167;
    s32 temp_r0_1194;
    u32 temp_r3_1257;
    u32 temp_r3_1268;
    u8 var_r28_1166;
    u8 var_r29_1169;
    void *temp_r3_1241;
    void *temp_r3_1311;
    void *temp_r4_1245;
    void *temp_r4_1269;
    void *temp_r4_1313;

    var_r28_1166 = 0;
    temp_r0_1167 = this->unkC8;
    var_r29_1169 = 0;
    if ((temp_r0_1167 != 4) && (temp_r0_1167 != 2) && (temp_r0_1167 != 7) && (M2C_FIELD(*gMK, u8 (**)(void **, Crate *, s32), 0x9C)(gMK, this, *MKResource::sWorkingChunkID) != 0)) {
        var_r29_1169 = 1;
    }
    if ((var_r29_1169 != 0) && (this->unk10 & 0x160000)) {
        var_r28_1166 = 1;
    }
    temp_r0_1194 = arg0->unk0;
    switch (temp_r0_1194) {                         /* irregular */
    case 0x40:
        if (var_r28_1166 == 0) {
            return;
        }
    default:
block_38:
        this->unk190.Message(arg0);
        GameProp::Message(arg0);
        return;
    case 0xBA:
    case 0x1:
        if (var_r28_1166 != 0) {
            Shatter(0);
        }
        goto block_38;
    case 0x58:
        temp_r3_1241 = checked_cast<TargetPositionRequest *, MKMessage>(arg0);
        M2C_FIELD(temp_r3_1241, s8 *, 0x18) = 1;
        temp_r4_1245 = this->unk8;
        temp_f1_1246 = M2C_FIELD(temp_r4_1245, f64 *, 0x30);
        temp_f2_1247 = M2C_FIELD(temp_r4_1245, f64 *, 0x38);
        sp38 = temp_f1_1246;
        M2C_FIELD(temp_r3_1241, f64 *, 8) = temp_f1_1246;
        M2C_FIELD(temp_r3_1241, f64 *, 0x10) = temp_f2_1247;
        sp40 = temp_f2_1247;
        M2C_FIELD(temp_r3_1241, f32 *, 0xC) = (f32) (M2C_FIELD(temp_r3_1241, f32 *, 0xC) + 47.5f);
        goto block_38;
    case 0x5C:
        temp_r3_1257 = arg0->unk4;
        temp_r4_1259 = temp_r3_1257 + 0x128;
        M2C_FIELD(temp_r3_1257, Attachment ***, 0x12C) = &this->unk1DC.unk4;
        M2C_FIELD(temp_r3_1257, Attachment **, 0x130) = (Attachment *) this->unk1E4;
        this->unk1E4 = temp_r4_1259;
        M2C_FIELD(temp_r3_1257, Attachment **, 0x130)->unk4 = temp_r4_1259;
        goto block_38;
    case 0x5D:
        temp_r3_1268 = arg0->unk4;
        temp_r4_1269 = temp_r3_1268 + 0x128;
        M2C_FIELD(temp_r3_1268, Attachment **, 0x130)->unk4 = (Attachment *) M2C_FIELD(temp_r3_1268, Attachment ***, 0x12C);
        M2C_FIELD(M2C_FIELD(temp_r4_1269, void **, 4), void **, 8) = (void *) M2C_FIELD(temp_r4_1269, void **, 8);
        M2C_FIELD(temp_r4_1269, void **, 8) = temp_r4_1269;
        M2C_FIELD(temp_r4_1269, void **, 4) = temp_r4_1269;
        goto block_38;
    case 0xBF:
        this->unk70.unk4 = 0;
        this->unkC8 = 0;
        goto block_38;
    case 0xBE:
        this->unk70.unk4 = 1;
        this->unkC8 = 1;
        goto block_38;
    case 0xD5:
        this->unk190.Message(arg0);
        GameProp::Message(arg0);
        if (M2C_FIELD(checked_cast<CrateDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x10C) > 0.0f) {
            temp_f31_1310 = 1.5f * M2C_FIELD(M2C_FIELD(checked_cast<CrateDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), void **, 0x1C), f32 *, 0xC);
            temp_r3_1311 = ((HeroInterface *) gb)->GetPosPtr();
            temp_r4_1313 = ((u8 *) this->unk8) + 0x30;
            sp8 = M2C_FIELD(temp_r4_1313, f64 *, 0) - M2C_FIELD(temp_r3_1311, f64 *, 0);
            sp18 = sp8;
            sp10 = M2C_FIELD(temp_r4_1313, f32 *, 8) - M2C_FIELD(temp_r3_1311, f32 *, 8);
            sp20 = (f64) sp10;
            sp28 = sp8;
            sp30 = (f64) sp10;
            if ((((f32) sp20 * (f32) sp20) + (((f32) sp18 * (f32) sp18) + ((*(f32 *) ((u8 *) &sp18 + 0x4)) * (*(f32 *) ((u8 *) &sp18 + 0x4))))) < (temp_f31_1310 * temp_f31_1310)) {
                this->unk170 += gUpdateTimeDelta;
                this->unk70.unk4 = 0;
                this->unkC8 = 7;
                return;
            }
        }
        break;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp6C'
void Crate::Update() {
    MKCollisionResult spB0;
    Matrix sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f64 sp10;
    f32 temp_f1_1469;
    f32 temp_f2_1488;
    f32 temp_f31_1461;
    f32 temp_f31_1509;
    f64 temp_f3_1416;
    s32 temp_r0_1400;
    s32 temp_r0_1565;
    void *temp_r30_1401;
    void *temp_r3_1510;
    void *temp_r4_1512;

    if ((s32) this->unkC8 != 0) {
        temp_r0_1400 = this->unkC8;
        temp_r30_1401 = checked_cast<CrateDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        if ((temp_r0_1400 != 4) && (temp_r0_1400 != 7)) {
            UpdateShadow(temp_r0_1400 == 2);
            if (M2C_FIELD(temp_r30_1401, s32 *, 0x100) & 0x20) {
                temp_f3_1416 = this->unkD8;
                sp60 = this->unkD0;
                sp68 = temp_f3_1416;
                (*(f32 *) ((u8 *) &sp60 + 0x4)) += M2C_FIELD(temp_r30_1401, f32 *, 0xF4) * _table_sinf(M2C_FIELD(temp_r30_1401, f32 *, 0xF8) * (f32) fmod(&gb, M2C_FIELD(&gb, f32 *, 0x30C) + (f32) sp60, 3.141590118408203, temp_f3_1416));
                MKModel_SetPosition(this->unk4, *((MKVector3 *) &sp60));
            }
            if ((MKModel *) this->unk188 != NULL) {
                M2C_STRUCT_COPY((s32) &unksp6C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
                temp_f31_1461 = M2C_FIELD(MKModel_GetBoundingVolume(this->unk188, (SubObjectType) 0, -1), f32 *, 0x14) * 0.5f;
                temp_f1_1469 = (M2C_FIELD(MKModel_GetBoundingVolume(this->unk4, (SubObjectType) 0, -1), f32 *, 0x14) * 0.5f) - temp_f31_1461;
                sp28 = 0.0f;
                sp20 = 0.0f;
                sp24 = temp_f1_1469;
                sp58 = (f64) sp28;
                sp50 = (f64) sp20;
                sp70.Translate(&sp70, *((MKVector3 *) &sp50));
                sp70.Multiply(&sp70, (Matrix *) this->unk8);
                MKModel_SetWorldMatrix(this->unk188, sp70);
            }
        }
        GameProp::Update();
        temp_f2_1488 = this->unk170;
        if (temp_f2_1488 > 0.0f) {
            this->unk170 = temp_f2_1488 - gUpdateTimeDelta;
            if (this->unk170 <= 0.0f) {
                this->unk70.unk4 = 0;
                temp_f31_1509 = 1.5f * M2C_FIELD(M2C_FIELD(checked_cast<CrateDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), void **, 0x1C), f32 *, 0xC);
                temp_r3_1510 = ((HeroInterface *) M2C_FIELD(&gb, void ***, 0))->GetPosPtr();
                temp_r4_1512 = ((u8 *) this->unk8) + 0x30;
                sp10 = M2C_FIELD(temp_r4_1512, f64 *, 0) - M2C_FIELD(temp_r3_1510, f64 *, 0);
                sp30 = sp10;
                sp18 = M2C_FIELD(temp_r4_1512, f32 *, 8) - M2C_FIELD(temp_r3_1510, f32 *, 8);
                sp38 = (f64) sp18;
                sp40 = sp10;
                sp48 = (f64) sp18;
                if (!((((f32) sp38 * (f32) sp38) + (((f32) sp30 * (f32) sp30) + ((*(f32 *) ((u8 *) &sp30 + 0x4)) * (*(f32 *) ((u8 *) &sp30 + 0x4))))) < (temp_f31_1509 * temp_f31_1509)) && (MKCollision_SphereCollide(*(this->unk8 + 0x30), M2C_FIELD(M2C_FIELD(checked_cast<CrateDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), void **, 0x1C), f32 *, 0xC), &spB0, 1, (MKCollisionMode) 2, 0) == 0)) {
                    this->unk70.unk4 = 1;
                    this->unkE0.Reset();
                    this->unkC8 = 6;
                    this->unkCC = 0.0f;
                } else {
                    this->unk170 += gUpdateTimeDelta;
                }
            }
        }
        temp_r0_1565 = this->unkC8;
        switch (temp_r0_1565) {                     /* irregular */
        case 3:
            Spin();
            return;
        case 2:
            Burn();
            return;
        case 5:
            Fall();
            return;
        case 4:
            Shattering();
            return;
        case 6:
            Respawn();
            break;
        }
    }
}
#endif

void Crate::ClearData() {
    this->unk16C = 0.0f;
    this->unk168 = 0.0f;
    this->unk174 = 0.0f;
    this->unkC8 = 1;
    this->unk178 = 0;
}

void Crate::Reset() {
    GameProp::Reset();
    ClearData();
    this->unkE0.Reset();
}

void Crate::Draw() {
    f64 sp10;
    f64 sp8;
    MKModel *temp_r3_1665;
    f32 temp_f0_1682;
    f32 var_f0_1699;
    f64 *temp_r3_1691;
    s32 temp_r0_1656;
    u8 var_r4_1674;

    if ((this->unk10 & 0x40000) && (temp_r0_1656 = this->unkC8, ((temp_r0_1656 == 0) == 0)) && (temp_r0_1656 != 5)) {
        if (temp_r0_1656 == 7) {
            return;
        }
        temp_r3_1665 = this->unk188;
        if ((temp_r3_1665 != NULL) && (temp_r0_1656 < 4)) {
            MKModel_Draw(temp_r3_1665, NULL);
        }
        var_r4_1674 = 0;
        if (this->unk10 & 0x8000) {
            temp_f0_1682 = M2C_FIELD(this->unk0, f32 *, 0x20) * M2C_FIELD(gMK, f32 *, 4);
            if (this->unk24 < (temp_f0_1682 * temp_f0_1682)) {
                var_r4_1674 = 1;
            }
        }
        MKModel_EnableScissoring(this->unk4, var_r4_1674);
        temp_r3_1691 = MKModel_GetColor(this->unk4);
        sp8 = M2C_FIELD(temp_r3_1691, f64 *, 0);
        sp10 = M2C_FIELD(temp_r3_1691, f64 *, 8);
        if (((u8) this->unk88 >> 7U) & 1) {
            var_f0_1699 = 1.0f;
        } else {
            var_f0_1699 = this->unk20 * this->unk84;
        }
        (*(f32 *) ((u8 *) &sp10 + 0x4)) = var_f0_1699;
        MKModel_SetColor(this->unk4, *((MKVector4 *) &sp8));
        PreDraw();
        this->unkE0.Draw();
        PostDraw();
    }
}

void Crate::Resolve() {
    void *temp_r3_1733;

    KDPropEx::Resolve();
    temp_r3_1733 = this->unk1DC.unk0;
    if (temp_r3_1733 != NULL) {
        ((ShockWave *) temp_r3_1733)->SetMessage(this->unk14, "");
    }
}

#if 0 // DRAFT: expression syntax error
void Crate::LoadDone() {
    Matrix sp30;
    M2C_UNK sp2C;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f1_1840;
    f32 temp_f31_1832;
    u32 temp_r0_1788;
    u32 temp_r29_1769;
    void *temp_r3_1865;

    GameProp::LoadDone();
    this->unkE0.LoadDone();
    this->unk190.LoadDone((MKProp *) this, NULL);
    temp_r29_1769 = this->unk17C;
    this->unk17C = 0;
loop_3:
    if (temp_r29_1769 != 0) {
        temp_r0_1788 = this->unk17C;
        if ((s32) temp_r0_1788 < 4) {
            if (stricmp((s8 *) temp_r29_1769, collectableTypes[temp_r0_1788].unk0) != 0) {
                this->unk17C += 1;
                goto loop_3;
            }
        }
    }
    if ((u8) M2C_FIELD(checked_cast<CrateDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), u8 *, 0x124) != 0) {
        this->unk188 = MKModel_Create(collectableTypes[this->unk17C].unk10, NULL, 2, NULL);
        if ((MKModel *) this->unk188 != NULL) {
            M2C_STRUCT_COPY((s32) &sp2C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
            temp_f31_1832 = M2C_FIELD(MKModel_GetBoundingVolume(this->unk188, (SubObjectType) 0, -1), f32 *, 0x14) * 0.5f;
            temp_f1_1840 = (M2C_FIELD(MKModel_GetBoundingVolume(this->unk4, (SubObjectType) 0, -1), f32 *, 0x14) * 0.5f) - temp_f31_1832;
            sp18 = 0.0f;
            sp10 = 0.0f;
            sp14 = temp_f1_1840;
            sp28 = (f64) sp18;
            sp20 = (f64) sp10;
            sp30.Translate(&sp30, *((MKVector3 *) &sp20));
            sp30.Multiply(&sp30, (Matrix *) this->unk8);
            MKModel_SetWorldMatrix(this->unk188, sp30);
        }
    }
    this->unk20 = M2C_FIELD(checked_cast<CrateDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0xFC);
    this->unk70.unk4 = 1;
    ClearData();
    temp_r3_1865 = this->unk8;
    this->unkD0 = M2C_FIELD(temp_r3_1865, f64 *, 0x30);
    this->unkD8 = M2C_FIELD(temp_r3_1865, f64 *, 0x38);
    if (((u8) M2C_FIELD(checked_cast<CrateDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), u8 *, 0x1B8) != 0) && (M2C_FIELD(checked_cast<CrateDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x1C0) > 0.0f)) {
        ((MKSceneManager *) gMK)->CreatePropDeferred("", (MKProp **) &this->unk1DC);
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to
s32 Crate::LoadLine(MKIniLine *arg0) {
    s32 var_r31_1907;

    var_r31_1907 = 0;
    if ((GameProp::LoadLine(arg0) != 0) || (arg0->LoadString("", (s8 **) &this->unk17C, 1) != 0) || (arg0->LoadInt("", (int *) &this->unk180, 0) != 0) || (arg0->LoadInt("", (int *) &this->unk184, 0) != 0) || (this->unkE0.LoadLine(arg0), (((u8) M2C_ERROR(/* Read from unset register $r3 */) == 0) == 0))) {
        var_r31_1907 = 1;
    }
    return var_r31_1907;
}
#endif

#if 0 // DRAFT: type mismatch
void Crate::Deinit() {
    Attachment *temp_r30_1966;
    Attachment *var_r3_1963;
    MKModel *temp_r3_1976;

    var_r3_1963 = this->unk1DC.unk8;
loop_3:
    if (var_r3_1963 != &this->unk1DC.unk4) {
        temp_r30_1966 = var_r3_1963->unk4;
        if (Crate_ParentDestroyed(var_r3_1963, this) != 0) {
            var_r3_1963 = temp_r30_1966;
            goto loop_3;
        }
    }
    temp_r3_1976 = this->unk188;
    if (temp_r3_1976 != NULL) {
        MKModel_Destroy(temp_r3_1976);
    }
    this->unk188 = NULL;
    this->unk190.Deinit();
    this->unkE0.Deinit();
    GameProp::Deinit();
}
#endif

u8 Crate_ParentDestroyed(Attachment *arg0, void *arg1) {
    void *spC;
    s32 sp8;
    void *temp_r3_2008;

    spC = NULL;
    spC = arg1;
    sp8 = 0x5E;
    temp_r3_2008 = arg0->unk0;
    M2C_FIELD(M2C_FIELD(temp_r3_2008, void **, 0x44), M2C_UNK (**)(void *, s32 *, M2C_UNK), 0x2C)(temp_r3_2008, &sp8, 0);
    return 1U;
}

#if 0 // DRAFT: undefined identifier 'P15CrateDescriptor'
void Crate::Init() {
    GameProp::Init();
    this->unk70.unk4 = 1;
    this->unk17C = 0;
    this->unk180 = 0;
    this->unk184 = -1;
    this->unkE0.Init(checked_cast<P15CrateDescriptor, 16MKPropDescriptor>__FP16MKPropDescriptor((MKPropDescriptor *) this->unk0) + 0x128, (KDPropEx *) this);
    this->unk1DC.unk0 = NULL;
    this->unk188 = NULL;
    this->unk170 = 0.0f;
    this->unk190.Init(checked_cast<P15CrateDescriptor, 16MKPropDescriptor>__FP16MKPropDescriptor((MKPropDescriptor *) this->unk0) + 0x110, &this->unk70);
}
#endif

#if 0 // DRAFT: undefined identifier 'CRATE_REF_TARGET'
void CrateDescriptor::LoadDone() {
    GamePropDescriptor::LoadDone();
    MKModel_RefPointExists(this->unk2C, CRATE_REF_TARGET, (int *) &this->unk108);
    this->unk114 = ((MKVector3 *) (MKModel_GetBoundingVolume(this->unk2C, (SubObjectType) 0, -1)))->Magnitude();
    this->unk118 = 0.1f * this->unk114;
    if ((u8) this->unk1B8 != 0) {
        this->unkC |= 0x40;
    }
    this->unk128.LoadDone(this->unk2C, this->unk0);
}
#endif

#if 0 // DRAFT: undefined identifier 'unkE4'
s32 CrateDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r29_2355;
    s8 *temp_r4_2390;
    u8 var_r28_2271;

    if ((GamePropDescriptor::LoadLine(arg0) == 0) && (arg0->LoadFloat("", &this->unkE8, 0) == 0) && (arg0->LoadFloat("", &this->unkE4, 0) == 0) && (arg0->LoadFloat("", &this->unkEC, 0) == 0) && (arg0->LoadFloat("", &this->unkF0, 0) == 0) && (arg0->LoadFloat("", &this->unkF4, 0) == 0) && (arg0->LoadFloat("", &this->unkF8, 0) == 0) && (arg0->LoadFloat("", &this->unkFC, 0) == 0) && (arg0->LoadFloat("", &this->unk10C, 0) == 0)) {
        var_r28_2271 = 0;
        if ((arg0->LoadFloat("", &this->unk110, 0) != 0) || (arg0->LoadBool("", &this->unk121, 0) != 0)) {
            var_r28_2271 = 1;
        }
        if ((var_r28_2271 != 0) || (arg0->LoadBool("", &this->unk1B8, 0) != 0) || (arg0->LoadFloat("", &this->unk1BC, 0) != 0) || (arg0->LoadFloat("", &this->unk1C0, 0) != 0) || (arg0->LoadFloat("", &this->unk1C4, 0) != 0) || (arg0->LoadInt("", (int *) &this->unk1C8, 0) != 0) || (arg0->LoadBool("", &this->unk124, 0) != 0) || (this->unk128.LoadLine(arg0, this->unk0) != 0)) {
            goto block_20;
        }
        var_r29_2355 = 0;
loop_28:
        temp_r4_2390 = *(&crateDescFlags + var_r29_2355);
        if (temp_r4_2390 == NULL) {
            return 0;
        }
        if (arg0->IsField(temp_r4_2390) != 0) {
            if (arg0->GetBool(0) != 0) {
                this->unk100 |= M2C_FIELD((&crateDescFlags + var_r29_2355), s32 *, 4);
            } else {
                this->unk100 &= ~M2C_FIELD((&crateDescFlags + var_r29_2355), s32 *, 4);
            }
            return 1;
        }
        var_r29_2355 += 8;
        goto loop_28;
    }
block_20:
    return 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkE4'
void CrateDescriptor::Init() {
    GamePropDescriptor::Init();
    this->unk100 = 0x8F;
    this->unk104 = 0;
    this->unkE8 = 2.0f;
    this->unkE4 = 0.8f;
    this->unkEC = 0.7f;
    this->unkF0 = 180.0f;
    this->unkF4 = 10.0f;
    this->unkF8 = 2.0f;
    this->unk108 = -1;
    this->unkFC = 1.0f;
    this->unk124 = 0;
    this->unk10C = 0.0f;
    this->unkC = 2;
    this->unk1B8 = 0;
    this->unk1BC = 0.0f;
    this->unk1C0 = 0.0f;
    this->unk1C4 = 1.0f;
    this->unk1C8 = 0;
    this->unk110 = 0.5f;
    this->unk114 = 0.0f;
    this->unk118 = 0.0f;
    this->unk11C = 6.0f;
    this->unk120 = 0;
    this->unk121 = 1;
    this->unk110 = 0.0f;
    this->unk128.Init((KDPropExDescriptor *) this);
}
#endif
