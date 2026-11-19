#include "spyro/source/Platform.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/SeeSaw.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKModel.h"
#include "common/Source/StdMath.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

extern s32 GS_PLACEHOLDER;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;

#if 0 // DRAFT: illegal explicit conversion from 'float' to
void PlatformRider::ToWorldDir(const MKVector3 &arg0) {
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f3_31;
    f32 temp_f6_37;
    f32 temp_f7_43;
    f32 temp_r6_24;
    void *temp_r4_30;

    temp_r6_24 = arg0.unk0;
    if ((M2C_BITWISE(u32, temp_r6_24) != 0U) && ((u8) M2C_FIELD(&arg0, u8 *, 8) != 0)) {
        temp_r4_30 = M2C_FIELD(temp_r6_24, void **, 8);
        temp_f3_31 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r5 */), f32 *, 4);
        temp_f6_37 = *M2C_ERROR(/* Read from unset register $r5 */);
        temp_f7_43 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r5 */), f32 *, 8);
        sp8 = (temp_f7_43 * M2C_FIELD(temp_r4_30, f32 *, 0x20)) + ((temp_f6_37 * M2C_FIELD(temp_r4_30, f32 *, 0)) + (temp_f3_31 * M2C_FIELD(temp_r4_30, f32 *, 0x10)));
        spC = (temp_f7_43 * M2C_FIELD(temp_r4_30, f32 *, 0x24)) + ((temp_f6_37 * M2C_FIELD(temp_r4_30, f32 *, 4)) + (temp_f3_31 * M2C_FIELD(temp_r4_30, f32 *, 0x14)));
        sp10 = (temp_f7_43 * M2C_FIELD(temp_r4_30, f32 *, 0x28)) + ((temp_f6_37 * M2C_FIELD(temp_r4_30, f32 *, 8)) + (temp_f3_31 * M2C_FIELD(temp_r4_30, f32 *, 0x18)));
        this->unk0 = (f64) sp8;
        this->unk8 = (f64) sp10;
        return;
    }
    this->unk0 = *M2C_ERROR(/* Read from unset register $r5 */);
    this->unk8 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r5 */), f64 *, 8);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'float' to
void PlatformRider::ToWorld(const MKVector3 &arg0) {
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f3_81;
    f32 temp_f6_87;
    f32 temp_f7_93;
    f32 temp_r6_74;
    void *temp_r4_80;

    temp_r6_74 = arg0.unk0;
    if ((M2C_BITWISE(u32, temp_r6_74) != 0U) && ((u8) M2C_FIELD(&arg0, u8 *, 8) != 0)) {
        temp_r4_80 = M2C_FIELD(temp_r6_74, void **, 8);
        temp_f3_81 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r5 */), f32 *, 4);
        temp_f6_87 = *M2C_ERROR(/* Read from unset register $r5 */);
        temp_f7_93 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r5 */), f32 *, 8);
        sp8 = M2C_FIELD(temp_r4_80, f32 *, 0x30) + ((temp_f7_93 * M2C_FIELD(temp_r4_80, f32 *, 0x20)) + ((temp_f6_87 * M2C_FIELD(temp_r4_80, f32 *, 0)) + (temp_f3_81 * M2C_FIELD(temp_r4_80, f32 *, 0x10))));
        spC = M2C_FIELD(temp_r4_80, f32 *, 0x34) + ((temp_f7_93 * M2C_FIELD(temp_r4_80, f32 *, 0x24)) + ((temp_f6_87 * M2C_FIELD(temp_r4_80, f32 *, 4)) + (temp_f3_81 * M2C_FIELD(temp_r4_80, f32 *, 0x14))));
        sp10 = M2C_FIELD(temp_r4_80, f32 *, 0x38) + ((temp_f7_93 * M2C_FIELD(temp_r4_80, f32 *, 0x28)) + ((temp_f6_87 * M2C_FIELD(temp_r4_80, f32 *, 8)) + (temp_f3_81 * M2C_FIELD(temp_r4_80, f32 *, 0x18))));
        this->unk0 = (f64) sp8;
        this->unk8 = (f64) sp10;
        return;
    }
    this->unk0 = *M2C_ERROR(/* Read from unset register $r5 */);
    this->unk8 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r5 */), f64 *, 8);
}
#endif

void PlatformRider::Attach(PlatformAttachment *arg0) {
    s32 sp18;
    u8 sp14;
    PlatformAttachment *sp10;
    s32 spC;
    s32 sp8;
    void *temp_r3_134;

    temp_r3_134 = M2C_FIELD(this, void **, 0);
    if ((temp_r3_134 != NULL) && ((u8) M2C_FIELD(this, u8 *, 8) == 0)) {
        sp10 = arg0;
        spC = 0;
        sp8 = 0x23;
        sp14 = 0;
        sp18 = 0;
        M2C_FIELD(M2C_FIELD(temp_r3_134, void **, 0x44), M2C_UNK (**)(s32 *, M2C_UNK), 0x2C)(&sp8, 0);
        M2C_FIELD(this, u8 *, 8) = sp14;
    }
}

#if 0 // DRAFT: type mismatch
void PlatformRider::Resolve() {
    MKSceneManager *temp_r3_170;

    temp_r3_170 = M2C_FIELD(this, MKSceneManager **, 4);
    if (temp_r3_170 > 0) {
        M2C_FIELD(this, void **, 0) = temp_r3_170->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */));
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'PlatformRider *' to
void PlatformRider::LoadLine(MKIniLine *arg0) {
    arg0->LoadInt("platformID", this + 4, 0);
}
#endif

void PlatformRider::Init() {
    M2C_FIELD(this, s32 *, 4) = 0;
    M2C_FIELD(this, s32 *, 0) = 0;
    M2C_FIELD(this, s8 *, 8) = 0;
}

#if 0 // DRAFT: illegal implicit conversion from 'double' to
void Platform::UpdateBob() {
    f64 sp10;
    f64 sp8;
    f32 temp_f2_237;
    void *temp_r3_221;
    void *temp_r3_226;

    temp_r3_221 = checked_cast<PlatformDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    if ((u8) M2C_FIELD(temp_r3_221, u8 *, 0x118) != 0) {
        temp_r3_226 = this->unk8;
        sp8 = M2C_FIELD(temp_r3_226, f64 *, 0x30);
        sp10 = M2C_FIELD(temp_r3_226, f64 *, 0x38);
        temp_f2_237 = M2C_FIELD(temp_r3_221, f32 *, 0x11C);
        (*(f32 *) ((u8 *) &sp8 + 0x4)) += temp_f2_237 * _table_sinf(6.2831855f * (this->unkB8 * M2C_FIELD(temp_r3_221, f32 *, 0x120)));
        SetPos(sp8, temp_f2_237);
    }
}
#endif

void Platform::UpdateSway() {
    f64 sp10;                                       /* compiler-managed */
    f64 sp8;                                        /* compiler-managed */
    f32 temp_f1_330;
    f32 temp_f3_305;
    f32 temp_f5_318;
    f32 temp_f6_290;
    f32 var_f2_319;
    f32 var_f4_291;
    void *temp_r3_264;

    temp_r3_264 = checked_cast<PlatformDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    if (((u8) M2C_FIELD(temp_r3_264, u8 *, 0x104) != 0) && ((s32) this->unk108.unk38 <= 0)) {
        sp8 = M2C_FIELD(this, f64 *, 0x110);
        sp10 = M2C_FIELD(this, f64 *, 0x118);
        temp_f6_290 = M2C_FIELD(temp_r3_264, f32 *, 0x10C) * _table_sinf(6.2831855f * (this->unk16C * (this->unkB8 * M2C_FIELD(temp_r3_264, f32 *, 0x108))));
        var_f4_291 = 0.5f * (3.0f * gUpdateTimeDelta);
        if (var_f4_291 < 1.0f) {

        } else {
            var_f4_291 = 1.0f;
        }
        temp_f3_305 = (var_f4_291 * (temp_f6_290 - (f32) sp8)) + (f32) sp8;
        sp8 = (var_f4_291 * (temp_f6_290 - temp_f3_305)) + temp_f3_305;
        temp_f5_318 = M2C_FIELD(temp_r3_264, f32 *, 0x114) * _table_sinf(6.2831855f * (this->unk170 * (this->unkB8 * M2C_FIELD(temp_r3_264, f32 *, 0x110))));
        var_f2_319 = 0.5f * (3.0f * gUpdateTimeDelta);
        if (var_f2_319 < 1.0f) {

        } else {
            var_f2_319 = 1.0f;
        }
        M2C_FIELD(this, f64 *, 0x110) = (f64) sp8;
        temp_f1_330 = (var_f2_319 * (temp_f5_318 - (f32) sp10)) + (f32) sp10;
        sp10 = (var_f2_319 * (temp_f5_318 - temp_f1_330)) + temp_f1_330;
        M2C_FIELD(this, f64 *, 0x118) = (f64) sp10;
    }
}

#if 0 // DRAFT: ')' expected
void Platform::UpdateShadow() {
    MKCollisionResult sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    M2C_UNK sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f64 sp10;
    f64 sp8;
    f32 temp_f1_384;
    f64 temp_f3_357;
    f64 temp_f4_356;
    u8 var_r0_381;
    void *temp_r3_355;

    temp_r3_355 = this->unk8;
    temp_f4_356 = M2C_FIELD(temp_r3_355, f64 *, 0x30);
    temp_f3_357 = M2C_FIELD(temp_r3_355, f64 *, 0x38);
    sp58 = temp_f4_356;
    sp50 = temp_f3_357;
    sp68 = temp_f4_356;
    sp30 = (f32) sp50;
    sp28 = (f32) sp68;
    sp2C = (*(f32 *) ((u8 *) &sp58 + 0x4)) - 10.0f;
    sp90 = (f64) sp30;
    sp88 = (f64) sp28;
    sp48 = temp_f4_356;
    sp8 = temp_f4_356;
    sp10 = temp_f3_357;
    sp60 = temp_f3_357;
    sp70 = temp_f3_357;
    var_r0_381 = 0;
    temp_f1_384 = (*(f32 *) ((u8 *) &sp88 + 0x4)) - M2C_FIELD(checked_cast<PlatformDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0xFC);
    sp20 = (f32) sp90;
    sp18 = (f32) sp88;
    sp1C = temp_f1_384;
    sp80 = (f64) sp20;
    sp78 = (f64) sp18;
    if (((f32) sp88 == this->unkD8) && ((*(f32 *) ((u8 *) &sp88 + 0x4)) == this->unkDC) && ((f32) sp90 == this->unkE0)) {
        var_r0_381 = 1;
    }
    if (var_r0_381 == 0) {
        this->unk174 = 0;
        if (MKCollision_RayCollide(*((MKVector3 *) &sp88), *((MKVector3 *) &sp78), &sp98, (MKCollisionMode) 1, 0x200) != 0) {
            this->unkF8 = (f64) sp98.unk10;
            this->unk100 = (f64) sp98.unk18;
            this->unkE8 = M2C_BITWISE(f64, sp98);
            this->unkF0 = (f64) sp98.unk8;
            this->unk174 = 1;
            if (M2C_FIELD(checked_cast<PlatformDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x60) & 1) {
                Tools_GroundColor((MKCollisionResult *) &sp38);
                MKModel_SetColor(this->unk4, *((MKVector4 *) &sp38));
            }
        }
        M2C_FIELD(this, f32 *, 0xD8) = sp88;
        M2C_FIELD(this, f32 *, 0xE0) = sp90;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'Platform *' to
void Platform::Resolve() {
    KDPropEx::Resolve();
    this->unk150.Resolve();
    this->unk150.Attach(this + 0x15C);
    if ((M2C_FIELD(checked_cast<PlatformDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0xFC) > 0.0f) && ((u8) this->unk175 != 0)) {
        UpdateShadow();
    }
}
#endif

#if 0 // DRAFT: ')' expected
void Platform::Message(MKMessage *arg0) {
    s32 temp_r0_494;

    temp_r0_494 = arg0->unk0;
    switch (temp_r0_494) {                          /* irregular */
    case 39:
        M2C_FIELD(checked_cast<CollisionInfoRequest *, MKMessage>(arg0), MKCollisionInfo **, 8) = &this->unk70;
        break;
    case -4:
        ((KDSoundPlayer *) &this->unk178)->Message(arg0);
        break;
    }
    this->unk108.Message(arg0);
    GameProp::Message(arg0);
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp1C'
void Platform::Reset() {
    Matrix sp20;
    f64 sp18;
    f64 sp10;

    GameProp::Reset();
    this->unk108.Reset();
    M2C_FIELD(this, f64 *, 0x110) = (f64) this->unkC8;
    M2C_FIELD(this, f64 *, 0x118) = (f64) this->unkD0;
    sp10 = M2C_FIELD(this, f64 *, 0x110);
    sp18 = M2C_FIELD(this, f64 *, 0x118);
    M2C_STRUCT_COPY((s32) &unksp1C + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
    sp20.SetRotationPYR(*((MKVector3 *) &sp10));
    MKModel_SetWorldMatrix(this->unk4, sp20);
    this->unk16C = MKRand_Float(&gViewSeed, 0.9f, 1.1f);
    this->unk170 = MKRand_Float(&gViewSeed, 0.9f, 1.1f);
}
#endif

#if 0 // DRAFT: ')' expected
void Platform::PropUpdate() {
    GameProp::PropUpdate();
    this->unk108.BeginUpdate();
    this->unk108.UpdateTilt();
    UpdateMove();
    UpdateSway();
    UpdateRotate();
    UpdateBob();
    this->unk108.EndUpdate();
    if ((M2C_FIELD(checked_cast<PlatformDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0xFC) > 0.0f) && ((u8) this->unk175 != 0)) {
        UpdateShadow();
    }
    UpdateScale();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKProp *' to
void Platform::LoadDone() {
    M2C_FIELD(&MKProp::loadInfo, f64 *, 0x60) = (f64) M2C_FIELD(&MKVector3::one, f64 *, 0);
    M2C_FIELD(&MKProp::loadInfo, f64 *, 0x68) = (f64) M2C_FIELD(&MKVector3::one, f64 *, 8);
    GameProp::LoadDone();
    this->unkC8 = M2C_FIELD(&MKProp::loadInfo, f64 *, 0x50);
    this->unkD0 = M2C_FIELD(&MKProp::loadInfo, f64 *, 0x58);
    this->unk108.LoadDone((MKProp *) this, &MKProp::loadInfo + 0x60);
    M2C_FIELD(this, f64 *, 0x110) = (f64) this->unkC8;
    M2C_FIELD(this, f64 *, 0x118) = (f64) this->unkD0;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to
s32 Platform::LoadLine(MKIniLine *arg0) {
    s32 var_r31_688;

    var_r31_688 = 0;
    if ((GameProp::LoadLine(arg0) != 0) || (this->unk150.LoadLine(arg0), (((u8) M2C_ERROR(/* Read from unset register $r3 */) == 0) == 0)) || (arg0->LoadBool("bUseDropShadow", &this->unk175, 0) != 0)) {
        var_r31_688 = 1;
    }
    return var_r31_688;
}
#endif

#if 0 // DRAFT: function call 'KDSound_Stop(long *)' does not match
void Platform::Deinit() {
    KDSound_Stop(&this->unk178);
    this->unk108.Deinit();
    GameProp::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'P18PlatformDescriptor'
void Platform::Init() {
    GameProp::Init();
    this->unk150.Init();
    this->unk108.Init(checked_cast<P18PlatformDescriptor, 16MKPropDescriptor>__FP16MKPropDescriptor((MKPropDescriptor *) this->unk0) + 0xE4, &this->unk70);
    M2C_FIELD(this, f32 *, 0xE8) = 0.0f;
    M2C_FIELD(this, f32 *, 0xEC) = 0.0f;
    M2C_FIELD(this, f32 *, 0xF0) = 0.0f;
    M2C_FIELD(this, f32 *, 0xF8) = 0.0f;
    M2C_FIELD(this, f32 *, 0xFC) = 0.0f;
    M2C_FIELD(this, f32 *, 0x100) = 0.0f;
    this->unkD8 = 0.0f;
    this->unkDC = 0.0f;
    this->unkE0 = 0.0f;
    this->unk174 = 0;
    this->unk16C = 1.0f;
    this->unk170 = 1.0f;
    this->unk178 = 0;
    this->unk175 = 1;
    M2C_FIELD(this, Platform **, 0x15C) = this;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void PlatformDescriptor::LoadDone() {
    GamePropDescriptor::LoadDone();
    this->unkE8 = ((MKVector3 *) (MKModel_GetBoundingVolume(this->unk2C, (SubObjectType) 0, -1)))->Magnitude();
    this->unkEC = 0.1f * this->unkE8;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
s32 PlatformDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_817;

    var_r31_817 = 0;
    if ((GamePropDescriptor::LoadLine(arg0) != 0) || (arg0->LoadFloat("maxTilt", &this->unkE4, 0) != 0) || (arg0->LoadBool("bUpdateRotationMatrix", &this->unkF5, 0) != 0) || (arg0->LoadFloat("rotVel", &this->unkF8, 0) != 0) || (arg0->LoadFloat("maxShadowHeight", &this->unkFC, 0) != 0) || (arg0->LoadBool("enableSway", &this->unk104, 0) != 0) || (arg0->LoadBool("enableBob", &this->unk118, 0) != 0)) {
        var_r31_817 = 1;
    }
    return var_r31_817;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void PlatformDescriptor::Init() {
    GamePropDescriptor::Init();
    this->unkE4 = 0.5f;
    this->unkE8 = 0.0f;
    this->unkEC = 0.0f;
    this->unkF0 = 6.0f;
    this->unkF4 = 0;
    this->unkF5 = 1;
    this->unkFC = 1000.0f;
    this->unk100 = GS_PLACEHOLDER;
    this->unk104 = 0;
    this->unk108 = 0.0f;
    this->unk10C = 0.0f;
    this->unk110 = 0.0f;
    this->unk114 = 0.0f;
    this->unk118 = 0;
    this->unk11C = 50.0f;
    this->unk120 = 0.3f;
}
#endif
