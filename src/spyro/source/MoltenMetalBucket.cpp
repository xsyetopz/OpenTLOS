#include "spyro/source/MoltenMetalBucket.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/LiquidFX.h"
#include "unplaced_templates.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

extern MKSceneManager *gMK;
#if 0 // DRAFT: illegal implicit conversion from 'const char *' to
static s8 *pMoltenMetalBucketEvents[3] = { "emitStart", .L_8035D0A2, NULL };
#endif
static s32 lit_655 = 1;

#if 0 // DRAFT: declaration syntax error
static s8 .L_8035D0A2[0xB4] = {
    0x65,
    0x6D,
    0x69,
    0x74,
    0x53,
    0x74,
    0x6F,
    0x70,
    0,
    0x4D,
    0x6F,
    0x6C,
    0x74,
    0x65,
    0x6E,
    0x4D,
    0x65,
    0x74,
    0x61,
    0x6C,
    0x46,
    0x58,
    0,
    0x72,
    0x5F,
    0x65,
    0x6D,
    0x69,
    0x74,
    0x74,
    0x65,
    0x72,
    0,
    0x72,
    0x5F,
    0x65,
    0x6D,
    0x69,
    0x74,
    0x74,
    0x65,
    0x72,
    0x5F,
    0x31,
    0,
    0x66,
    0x78,
    0x5F,
    0x30,
    0x30,
    0x33,
    0,
    0x69,
    0x64,
    0x6C,
    0x65,
    0,
    0x70,
    0x6F,
    0x75,
    0x72,
    0,
    0x72,
    0x65,
    0x73,
    0x65,
    0x74,
    0,
    0x73,
    0x74,
    0x61,
    0x72,
    0x74,
    0,
    0x73,
    0x74,
    0x6F,
    0x70,
    0,
    0x73,
    0x6E,
    0x64,
    0x4D,
    0x6F,
    0x76,
    0x69,
    0x6E,
    0x67,
    0,
    0x73,
    0x6E,
    0x64,
    0x50,
    0x6F,
    0x75,
    0x72,
    0x69,
    0x6E,
    0x67,
    0,
    0x73,
    0x6E,
    0x64,
    0x42,
    0x75,
    0x72,
    0x6E,
    0x69,
    0x6E,
    0x67,
    0,
    0x4D,
    0x6F,
    0x76,
    0x65,
    0x46,
    0x61,
    0x64,
    0x65,
    0x49,
    0x6E,
    0,
    0x4D,
    0x6F,
    0x76,
    0x65,
    0x46,
    0x61,
    0x64,
    0x65,
    0x4F,
    0x75,
    0x74,
    0,
    0x50,
    0x6F,
    0x75,
    0x72,
    0x46,
    0x61,
    0x64,
    0x65,
    0x49,
    0x6E,
    0,
    0x50,
    0x6F,
    0x75,
    0x72,
    0x46,
    0x61,
    0x64,
    0x65,
    0x4F,
    0x75,
    0x74,
    0,
    0x42,
    0x75,
    0x72,
    0x6E,
    0x46,
    0x61,
    0x64,
    0x65,
    0x49,
    0x6E,
    0,
    0x42,
    0x75,
    0x72,
    0x6E,
    0x46,
    0x61,
    0x64,
    0x65,
    0x4F,
    0x75,
    0x74,
    0,
}; /* const */

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

#if 0 // DRAFT: expression syntax error
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
    this->unkEC.Message(arg0);
    this->unk114.Message(arg0);
    this->unk13C.Message(arg0);
}
#endif

#if 0 // DRAFT: undefined identifier 'sp18'
void MoltenMetalBucket::Update() {
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
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f32 sp40;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp10;
    s32 spC;
    s32 sp8;
    f32 temp_f30_382;
    f32 var_f29_377;
    f32 var_f3_372;
    f32 var_f4_282;
    f32 var_f4_349;
    f64 temp_f1_288;
    f64 temp_f1_294;
    f64 temp_f1_298;
    s32 temp_r3_317;
    s32 var_r0_327;
    u8 var_r30_384;
    void *temp_r3_240;
    void *temp_r4_533;
    void *temp_r4_554;
    void *temp_r4_575;

    GameProp::Update();
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    this->unkD8 = sp18;
    sp20 = M2C_FIELD((this->unk8 + 0x30), f32 *, 8) - this->unkD0;
    sp118 = sp18;
    this->unkE0 = (f64) sp20;
    temp_r3_240 = this->unk8;
    sp120 = (f64) sp20;
    this->unkC8 = M2C_FIELD(temp_r3_240, f64 *, 0x30);
    M2C_FIELD(this, f32 *, 0xD0) = (f64) M2C_FIELD(temp_r3_240, f64 *, 0x38);
    if (((u8) this->unkE8 >> 7U) & 1) {
        MKModel_CalculateRefPointWorldPosition(this->unk4, M2C_FIELD(checked_cast<MoltenMetalBucketDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xE4), &sp148);
        MKModel_CalculateRefPointWorldPosition(this->unk4, M2C_FIELD(checked_cast<MoltenMetalBucketDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xE8), &sp138);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp108 = sp98;
        spA0 = sp138.unk8 - sp148.unk8;
        sp110 = (f64) spA0;
        var_f4_282 = ((f32) sp110 * (f32) sp110) + (((f32) sp108 * (f32) sp108) + (unksp10C * unksp10C));
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
        sp8C = unksp10C * var_f4_349;
        sp88 = (f32) sp108 * var_f4_349;
        sp90 = (f32) sp110 * var_f4_349;
        sp128 = (f64) sp88;
        sp130 = (f64) sp90;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (unksp12C == 0.0f) {
            var_f3_372 = 1.5f * unksp12C;
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
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f4, $f0 */);
            sp80 = 0.0f;
            sp78 = 0.0f;
            sp7C = -50.0f;
            sp50 = sp148.unk8 + (f32) spD0;
            spE8 = (f64) sp78;
            spD8 = sp48;
            spE0 = (f64) sp50;
            spF0 = (f64) sp80;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f4, $f0 */);
            spF8 = sp68;
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
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            sp30 = 1.5f;
            sp40 = (f32) sp130 * (100.0f * temp_f30_382);
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
        this->unkEC.Update(M2C_FIELD(temp_r4_533, s32 *, 0x104), 1U, ((u8) this->unk178 >> 7U) & 1, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    }
    if ((s32) M2C_FIELD(checked_cast<MoltenMetalBucketDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x108) != 0) {
        temp_r4_554 = checked_cast<MoltenMetalBucketDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        sp8 = 1;
        this->unk114.Update(M2C_FIELD(temp_r4_554, s32 *, 0x108), 1U, ((u8) this->unkE8 >> 7U) & 1, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    }
    if ((s32) M2C_FIELD(checked_cast<MoltenMetalBucketDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x10C) != 0) {
        temp_r4_575 = checked_cast<MoltenMetalBucketDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        sp8 = 1;
        this->unk13C.Update(M2C_FIELD(temp_r4_575, s32 *, 0x10C), 1U, ((u8) this->unkE8 >> 7U) & 1, NULL, (MKVector3 *) &this->unk168, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void MoltenMetalBucket::Resolve() {
    void *temp_r31_612;
    void *temp_r31_621;
    void *temp_r31_630;

    KDPropEx::Resolve();
    temp_r31_612 = checked_cast<MoltenMetalBucketDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    this->unkEC.Init(M2C_FIELD(checked_cast<MoltenMetalBucketDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x110), M2C_FIELD(temp_r31_612, f32 *, 0x114));
    temp_r31_621 = checked_cast<MoltenMetalBucketDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    this->unk114.Init(M2C_FIELD(checked_cast<MoltenMetalBucketDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x118), M2C_FIELD(temp_r31_621, f32 *, 0x11C));
    temp_r31_630 = checked_cast<MoltenMetalBucketDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    this->unk13C.Init(M2C_FIELD(checked_cast<MoltenMetalBucketDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x120), M2C_FIELD(temp_r31_630, f32 *, 0x124));
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *[3]' to
void MoltenMetalBucket::LoadDone() {
    GameProp::LoadDone();
    this->unk80->InitEvents(pMoltenMetalBucketEvents);
    this->unk17C = checked_cast<LiquidFX *, MKProp>(gMK->CreateProp(""));
}
#endif

#if 0 // DRAFT: function call 'KDSound_Stop(long *)' does not match
void MoltenMetalBucket::Deinit() {
    KDSound_Stop(&this->unkEC);
    KDSound_Stop(&this->unk114);
    KDSound_Stop(&this->unk13C);
    GameProp::Deinit();
}
#endif

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

#if 0 // DRAFT: illegal implicit conversion from 'MKResource * (const char *)' to
void MoltenMetalBucketDescriptor::Resolve() {
    MKPropDescriptor::Resolve();
    this->unkE4 = MKModel_GetRefPointIndex(this->unk2C, "");
    this->unkE8 = MKModel_GetRefPointIndex(this->unk2C, "");
    this->unkEC = MKMaterial_Create"";
    this->unkF0 = this->unk34->GetAnim("");
    this->unkF4 = this->unk34->GetAnim("");
    this->unkF8 = this->unk34->GetAnim("");
    this->unkFC = this->unk34->GetAnim("");
    this->unk100 = this->unk34->GetAnim("");
}
#endif

#if 0 // DRAFT: function call 'KDSound_LoadLine(MKIniLine *, const char[1], long *)' does
s32 MoltenMetalBucketDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_818;

    var_r31_818 = 0;
    if ((GamePropDescriptor::LoadLine(arg0) != 0) || (KDSound_LoadLine(arg0, "", &this->unk104) != 0) || (KDSound_LoadLine(arg0, "", &this->unk108) != 0) || (KDSound_LoadLine(arg0, "", &this->unk10C) != 0) || (arg0->LoadFloat("", &this->unk110, 0) != 0) || (arg0->LoadFloat("", &this->unk114, 0) != 0) || (arg0->LoadFloat("", &this->unk118, 0) != 0) || (arg0->LoadFloat("", &this->unk11C, 0) != 0) || (arg0->LoadFloat("", &this->unk120, 0) != 0) || (arg0->LoadFloat("", &this->unk124, 0) != 0)) {
        var_r31_818 = 1;
    }
    return var_r31_818;
}
#endif

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
