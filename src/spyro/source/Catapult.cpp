#include "spyro/source/Catapult.h"
#include "common/Source/Animation.h"
#include "common/Source/Font.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKFont.h"
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
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Ball.h"
#include "spyro/source/Crate.h"
#include "spyro/source/DialogBox.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/ExplodeMsg.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/KDFaderObject.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/Level.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/SnowballTree.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "common/Source/MKView.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/PhrasePlayer.h"
#include <m2c_macros.h>

extern f32 *KDSpline_PositionMixer;
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern f32 gUpdateTimeDelta;
extern GameGlobals gb;
static M2C_UNK lit_723;                                /* unable to generate initializer: unknown type */
u8 states__8Catapult[0xB4] = {
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};
#if 0 // DRAFT: illegal use of incomplete struct/union/class '_struct_groups_0x18'
static struct _struct_groups_0x18 groups[8];
#endif
u8 pEvents__8Catapult[8];                           /* unable to generate initializer: cannot parse "fire" as integer */

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'Catapult::State'
void Catapult::SetState(Catapult::State arg1) {
    this->unkF8.SetState(this, (s32) arg1, 0U);
}
#endif

s32 Catapult::CanLoadBall() {
    return this->unkF8.GetState() == 0;
}

#if 0 // DRAFT: illegal explicit conversion from 'int' to 'Catapult::State'
void Catapult::SetBall(Ball *arg0) {
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    MKVector3 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f64 sp8;
    f64 temp_f0_134;
    f64 temp_f0_146;
    f64 temp_f0_157;
    void *temp_r5_113;

    this->unk12C = (u32) arg0;
    temp_r5_113 = M2C_FIELD(this->unk12C, void **, 8);
    spA8 = M2C_FIELD(temp_r5_113, f64 *, 0x30);
    spB0 = M2C_FIELD(temp_r5_113, f64 *, 0x38);
    sp78 = GetAmmoPos();
    sp20 = 0.0f;
    sp18 = 0.0f;
    sp1C = 100.0f;
    *(MKVector3 *) &sp98 = sp78;
    sp48 = (f64) sp18;
    sp50 = (f64) sp20;
    temp_f0_134 = spA8 + sp98;
    sp38 = temp_f0_134;
    sp58 = temp_f0_134;
    sp40 = (f32) spB0 + (f32) spA0;
    sp60 = (f64) sp40;
    temp_f0_146 = temp_f0_134 * 5.222099017e-315;
    sp28 = temp_f0_146;
    sp68 = temp_f0_146;
    sp30 = (f32) sp60 * 0.5f;
    sp70 = (f64) sp30;
    temp_f0_157 = sp68 + sp48;
    sp8 = temp_f0_157;
    sp88 = temp_f0_157;
    sp10 = (f32) sp70 + (f32) sp50;
    sp90 = (f64) sp10;
    this->unk118.unk8 = 0.0f;
    this->unk118.unk4 = 0;
    this->unk118.AddNode(*((MKVector3 *) &spA8));
    this->unk118.AddNode(*((MKVector3 *) &sp88));
    this->unk118.AddNode(*((MKVector3 *) &sp98));
    this->unk138 = 0.0f;
    SetState((Catapult::State) 1);
}
#endif

#if 0 // DRAFT: identifier 'Catapult::GetAmmoDir()' redeclared was declared as: 'MKVector3 ()' now declared as: 'void ()'
void Catapult::GetAmmoDir() {
    MKVector3 result;
    MKVector3 *sret = &result;
    Matrix sp10;

    MKModel_GetRefPointMatrix(this->unk4, M2C_FIELD(checked_cast<CatapultDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x70), &sp10, 1U);
    M2C_FIELD(sret, f64 *, 0) = (f64) sp10.unk10;
    M2C_FIELD(sret, f64 *, 8) = (f64) sp10.unk18;
    return result;
}
#endif

#if 0 // DRAFT: identifier 'Catapult::GetAmmoPos()' redeclared was declared as: 'MKVector3 ()' now declared as: 'void ()'
void Catapult::GetAmmoPos() {
    MKVector3 result;
    MKVector3 *sret = &result;
    Matrix sp10;

    MKModel_GetRefPointMatrix(this->unk4, M2C_FIELD(checked_cast<CatapultDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x70), &sp10, 1U);
    M2C_FIELD(sret, f64 *, 0) = (f64) sp10.unk30;
    M2C_FIELD(sret, f64 *, 8) = (f64) sp10.unk38;
    return result;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to 'Catapult::State'
void Catapult::Message(MKMessage *arg0) {
    f64 sp10;
    f64 sp8;
    f32 temp_f3_307;
    f32 temp_f3_316;
    f32 temp_f4_313;
    f32 temp_f5_308;
    s32 temp_r0_268;
    void *temp_r31_293;
    void *temp_r3_298;

    ((KDSoundPlayer *) &this->unkA0)->Message(arg0);
    temp_r0_268 = arg0->unk0;
    switch (temp_r0_268) {                          /* irregular */
    default:
        if (this->unkF8.GetState() == 2) {
            SetState((Catapult::State) 3);
        }
        break;
    case 0x1:
        temp_r31_293 = checked_cast<ExplodeMsg *, MKMessage>(arg0);
        if (this->unkF8.GetState() == 2) {
            temp_r3_298 = this->unk8;
            sp8 = M2C_FIELD(temp_r3_298, f64 *, 0x30);
            sp10 = M2C_FIELD(temp_r3_298, f64 *, 0x38);
            temp_f3_307 = (*(f32 *) ((u8 *) &sp8 + 0x4)) - M2C_FIELD(temp_r31_293, f32 *, 0x14);
            temp_f5_308 = (f32) sp8 - M2C_FIELD(temp_r31_293, f32 *, 0x10);
            temp_f4_313 = (f32) sp10 - M2C_FIELD(temp_r31_293, f32 *, 0x18);
            temp_f3_316 = M2C_FIELD(temp_r31_293, f32 *, 0x20) + 300.0f;
            if (((temp_f4_313 * temp_f4_313) + ((temp_f5_308 * temp_f5_308) + (temp_f3_307 * temp_f3_307))) < (temp_f3_316 * temp_f3_316)) {
                SetState((Catapult::State) 3);
            }
        }
        break;
    case 0x88:
        M2C_FIELD(checked_cast<CanHeroHurtYouMsg *, MKMessage>(arg0), s8 *, 8) = 1;
        break;
    }
    KDProp::Message(arg0);
}
#endif

#if 0 // DRAFT: ')' expected
void Catapult::WindBackUpdate() {
    s32 sp60;
    s32 sp5C;
    s32 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f0_423;
    f32 temp_f31_353;
    f32 var_f3_422;
    f64 temp_f1_381;
    void *temp_r3_379;
    void *temp_r3_464;
    void *temp_r4_378;

    temp_f31_353 = this->unk13C;
    MKView_Push();
    MKView_SetCameraMatrix(*(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), Matrix **, 8)));
    if (MKView_VisibilityTest(*(M2C_FIELD(checked_cast<CatapultDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), BoundingVolume **, 0x1C)), *((Matrix *) this->unk8)) == 0) {
        this->unk13C = 1.0f;
    } else {
        temp_r4_378 = M2C_FIELD(gb.unk0->GetProp(), void **, 8);
        temp_r3_379 = this->unk8;
        temp_f1_381 = M2C_FIELD(temp_r3_379, f64 *, 0x30);
        sp38 = M2C_FIELD(temp_r4_378, f64 *, 0x30);
        sp48 = temp_f1_381;
        sp40 = M2C_FIELD(temp_r4_378, f64 *, 0x38);
        sp50 = M2C_FIELD(temp_r3_379, f64 *, 0x38);
        sp8 = temp_f1_381 - sp38;
        sp18 = sp8;
        sp10 = (f32) sp50 - (f32) sp40;
        sp28 = sp8;
        sp20 = (f64) sp10;
        sp30 = (f64) sp10;
        if ((((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1FU) == 0) || (this->unk13C > 0.67f)) {
            var_f3_422 = 1.0f;
            temp_f0_423 = (gUpdateTimeDelta * this->unk144) + this->unk13C;
            if (var_f3_422 < temp_f0_423) {

            } else {
                var_f3_422 = temp_f0_423;
            }
            this->unk13C = var_f3_422;
            this->unk144 -= gUpdateTimeDelta;
            if (this->unk144 < 0.3f) {
                this->unk144 = 0.3f;
            }
            if (temp_f31_353 != this->unk13C) {
                this->unk14C = 1;
            }
        }
    }
    this->unk80->JumpToPos(this->unk13C, -1);
    if (this->unk13C == 1.0f) {
        sp60 = 0;
        sp5C = 0;
        sp58 = 0x19;
        sp60 = 0;
        gb.GetSpyro();
        temp_r3_464 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), void **, 0xB70);
        M2C_FIELD(M2C_FIELD(temp_r3_464, void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(temp_r3_464, &sp58);
        SetState((Catapult::State) 0);
        this->unk14C = 0;
    }
    MKView_Pop();
}
#endif

#if 0 // DRAFT: ')' expected
void Catapult::WindBackEnter() {
    Catapult *sp10;
    s32 spC;
    s32 sp8;
    void *temp_r3_503;

    sp10 = NULL;
    spC = 0;
    sp8 = 0x19;
    sp10 = this;
    gb.GetSpyro();
    temp_r3_503 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), void **, 0xB70);
    M2C_FIELD(M2C_FIELD(temp_r3_503, void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(temp_r3_503, &sp8);
    this->unk80->SetAnim(M2C_FIELD(checked_cast<CatapultDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKAnim **, 0x74), 1.0f, 0.0f, 0, -1);
    this->unk13C = 0.0f;
    this->unk144 = 1.0f;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to 'double'
void Catapult::FireUpdate() {
    Matrix spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    MKVector3 spA0;
    f64 sp98;
    f64 sp90;
    MKVector3 sp80;
    MKVector3 sp70;
    MKVector3 sp60;
    MKVector3 sp50;
    f64 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    u32 temp_r30_546;
    u32 temp_r3_576;

    spA0 = GetAmmoPos();
    temp_r30_546 = this->unk12C;
    *(MKVector3 *) &spC0 = spA0;
    if (temp_r30_546 != 0) {
        sp50 = GetAmmoDir();
        sp60 = sp50.operator*(M2C_FIELD(temp_r30_546, f32 *, 0x274));
        sp70 = sp60.operator*(M2C_FIELD(temp_r30_546, f32 *, 0x280));
        sp80 = sp70.operator*(0.5f);
        sp20 = spC0 + M2C_BITWISE(f64, sp80);
        temp_r3_576 = this->unk12C;
        sp90 = sp20;
        sp28 = (f32) spC8 + sp80.unk8;
        M2C_FIELD(temp_r3_576, f64 *, 0xE0) = sp20;
        sp98 = (f64) sp28;
        M2C_FIELD(temp_r3_576, f64 *, 0xE8) = (f64) sp28;
    }
    if ((this->unk80->CheckEvent(0) != 0) && ((u32) this->unk12C != 0)) {
        sp30 = 0.0f;
        sp34 = 0.0f;
        sp38 = -3950.0f * this->unk140;
        spB0 = (f64) sp30;
        spB8 = (f64) sp38;
        M2C_STRUCT_COPY((s32) &unkspCC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
        KDMath_GetYaw((Matrix *) this->unk8);
        spD0.RotatePitch(&spD0, -0.7f);
        spD0.RotateYaw(&spD0, M2C_ERROR(/* Read from unset register $f1 */));
        sp10 = spD0.unk30 + (((f32) spB8 * spD0.unk20) + (((f32) spB0 * M2C_BITWISE(f32, spD0)) + ((*(f32 *) ((u8 *) &spB0 + 0x4)) * spD0.unk10)));
        sp14 = spD0.unk34 + (((f32) spB8 * spD0.unk24) + (((f32) spB0 * spD0.unk4) + ((*(f32 *) ((u8 *) &spB0 + 0x4)) * spD0.unk14)));
        sp18 = spD0.unk38 + (((f32) spB8 * spD0.unk28) + (((f32) spB0 * spD0.unk8) + ((*(f32 *) ((u8 *) &spB0 + 0x4)) * spD0.unk18)));
        spB0 = (f64) sp10;
        spB8 = (f64) sp18;
        sp40 = (f64) sp10;
        sp48 = (f64) sp18;
        ((Ball *) this->unk12C)->Fire(*((MKVector3 *) &spB0));
        this->unk12C = 0;
        ((KDInput *) (gb.unk0->GetInput()))->RumblePlay3D(0.8f, 0.0f, 0.3f, ((u8 *) this->unk8) + 0x30, 37.0f, 0, 4.0f, 0U);
    }
    if (this->unk80->unk2C & 1) {
        SetState((Catapult::State) 4);
    }
}
#endif

#if 0 // DRAFT: ')' expected
void Catapult::FireEnter() {
    MKVector3 *temp_r31_742;

    this->unk130 = this->unk130 + 1;
    this->unk80->SetAnim(M2C_FIELD(checked_cast<CatapultDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKAnim **, 0x7C), 1.0f, 0.0f, 0, -1);
    if ((s32) this->unk130 == 1) {
        this->unk110.Send((MKProp *) this);
    }
    this->unk10C.Send((MKProp *) this);
    if ((s32) M2C_FIELD(checked_cast<CatapultDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x80) != 0) {
        temp_r31_742 = ((u8 *) this->unk8) + 0x30;
        KDSound_Play3d(M2C_FIELD(checked_cast<CatapultDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x80), temp_r31_742, 0U, -1, 0.0f, 0U);
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'KDUniformSpline' to 'double'
void Catapult::LoadAmmoUpdate() {
    f64 sp78;
    KDUniformSpline sp60;
    MKVector3 sp50;
    MKVector3 sp40;
    MKVector3 sp30;
    MKVector3 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    f32 temp_f0_771;
    f32 var_f3_770;
    u32 temp_r31_779;
    u32 temp_r3_813;

    var_f3_770 = 1.0f;
    temp_f0_771 = (2.0f * gUpdateTimeDelta) + this->unk138;
    if (var_f3_770 < temp_f0_771) {

    } else {
        var_f3_770 = temp_f0_771;
    }
    this->unk138 = var_f3_770;
    temp_r31_779 = this->unk12C;
    if (temp_r31_779 != 0) {
        sp20 = GetAmmoDir();
        sp30 = sp20.operator*(M2C_FIELD(temp_r31_779, f32 *, 0x274));
        sp40 = sp30.operator*(M2C_FIELD(temp_r31_779, f32 *, 0x280));
        sp50 = sp40.operator*(0.5f);
        sp8 = 0.0f;
        sp60.GetMeasure(this->unk138, (Matrix *) &this->unk118, KDSpline_PositionMixer);
        sp10 = M2C_BITWISE(f64, sp60) + M2C_BITWISE(f64, sp50);
        temp_r3_813 = this->unk12C;
        sp60.unk10 = sp10;
        sp18 = sp60.unk8 + sp50.unk8;
        M2C_FIELD(temp_r3_813, f64 *, 0xE0) = sp10;
        sp78 = (f64) sp18;
        M2C_FIELD(temp_r3_813, f64 *, 0xE8) = (f64) sp18;
    }
    if (this->unk138 == 1.0f) {
        this->unk134 += 1;
        if ((s32) this->unk134 == 1) {
            this->unk114.Send((MKProp *) this);
        }
        SetState((Catapult::State) 2);
    }
}
#endif

#if 0 // DRAFT: ')' expected
void Catapult::IdleEnter() {
    MKVector3 *temp_r31_870;

    this->unk80->SetAnim(M2C_FIELD(checked_cast<CatapultDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKAnim **, 0x78), 1.0f, 0.0f, 0, -1);
    if (this->unkF8.GetLastState() == 4) {
        temp_r31_870 = (MKVector3 *) (((u8 *) this->unk8) + 0x30);
        KDSound_Play3d(M2C_FIELD(checked_cast<CatapultDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x88), temp_r31_870, 0U, -1, 0.0f, 0U);
    }
}
#endif

#if 0 // DRAFT: ')' expected
void *Catapult::Update() {
    MKVector3 sp10;
    s32 sp8;
    f32 temp_f1_915;
    f32 var_f1_923;
    void *temp_r4_933;

    sp10 = GetAmmoPos();
    *(MKVector3 *) &this->unk90 = sp10;
    KDProp::Update();
    this->unk14C = 0;
    this->unkF8.Update(this, 0);
    if ((s32) M2C_FIELD(checked_cast<CatapultDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x84) != 0) {
        temp_f1_915 = this->unk13C;
        if (temp_f1_915 >= 0.3f) {
            var_f1_923 = (0.714f * (temp_f1_915 - 0.3f)) + 0.7f;
        } else {
            var_f1_923 = 0.7f;
        }
        KDSound_SetPitch(this->unkA0, var_f1_923);
        temp_r4_933 = checked_cast<CatapultDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        sp8 = 1;
        ((KDSoundFader *) &this->unkA0)->Update(M2C_FIELD(temp_r4_933, s32 *, 0x84), 1U, this->unk14C, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to 'Catapult::State'
void Catapult::Reset() {
    MKVector3 sp8;

    KDProp::Reset();
    this->unk118.unk8 = 0.0f;
    this->unk118.unk4 = 0;
    this->unk138 = 0.0f;
    this->unk13C = 1.0f;
    this->unk12C = 0;
    sp8 = GetAmmoPos();
    *(MKVector3 *) &this->unk90 = sp8;
    SetState((Catapult::State) 0);
    this->unk14C = 0;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to 'Catapult::State'
void Catapult::Unload() {
    if (this->unkF8.GetState() & 2) {
        this->unk12C = 0;
        SetState((Catapult::State) 4);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'groups'
s32 Catapult::LoadDone() {
    s32 var_ctr_1026;
    s32 var_r3_1025;
    struct _struct_groups_0x18 *temp_r4_1030;

    KDProp::LoadDone();
    var_r3_1025 = 0;
    var_ctr_1026 = 6;
loop_1:
    temp_r4_1030 = &groups[this->unk14D];
    if ((u32) *(temp_r4_1030 + var_r3_1025) == 0U) {
        *(temp_r4_1030 + var_r3_1025) = this;
    } else {
        var_r3_1025 += 4;
        var_ctr_1026 -= 1;
        if (var_ctr_1026 != 0) {
            goto loop_1;
        }
    }
    this->unk130 = 0;
    this->unk134 = 0;
    this->unkF8.Init((KDStateMachine<Catapult>::State *) Catapult::states, NULL);
    this->unk80->InitEvents((s8 **) Catapult::pEvents);
    this->unkC8.Init(this->unk4, (MKProp *) this, 2000.0f, NULL, 1500.0f);
}
#endif

s32 Catapult::LoadLine(MKIniLine *arg0) {
    if ((KDProp::LoadLine(arg0) != 0) || (this->unk10C.LoadLine(arg0, "OnFire") != 0) || (this->unk110.LoadLine(arg0, "OnFirstFire") != 0) || (this->unk114.LoadLine(arg0, "OnFirstLoad") != 0) || (arg0->LoadFloat("fPowerMul", &this->unk140, 0) != 0)) {
        return 1;
    }
    if (arg0->IsField("group") != 0) {
        this->unk14D = arg0->GetInt(0);
        return 1;
    }
    return 0;
}

#if 0 // DRAFT: undefined identifier 'groups'
void Catapult::Deinit() {
    s32 temp_r3_1174;
    s32 var_ctr_1153;
    s32 var_r3_1148;
    struct _struct_groups_0x18 *temp_r5_1157;

    if ((u8) this->unk14D < 0xFFU) {
        var_r3_1148 = 0;
        var_ctr_1153 = 6;
        do {
            temp_r5_1157 = &groups[this->unk14D];
            if ((u32) *(temp_r5_1157 + var_r3_1148) == this) {
                *(temp_r5_1157 + var_r3_1148) = 0;
            }
            var_r3_1148 += 4;
            var_ctr_1153 -= 1;
        } while (var_ctr_1153 != 0);
    }
    this->unkF8.Deinit();
    this->unk118.Deinit();
    this->unkC8.Deinit();
    KDSound_Stop((int *) &this->unkA0);
    temp_r3_1174 = this->unk148;
    if (temp_r3_1174 != 0) {
        PhrasePlayer_StopEvent(temp_r3_1174);
    }
    KDProp::Deinit();
}
#endif

void Catapult::Init() {
    KDProp::Init();
    this->unk118.Init(3, 0U);
    ((KDSoundFader *) &this->unkA0)->Init(0.25f, 0.25f);
    this->unk14D = 0xFF;
    this->unk140 = 1.0f;
    this->unk148 = 0;
}

void CatapultDescriptor::LoadDone() {
    KDPropDescriptor::LoadDone();
    this->unk7C = (long) (((MKAnimScript *) this->unk34)->GetAnim("fire"));
    this->unk74 = (long) (((MKAnimScript *) this->unk34)->GetAnim("windup"));
    this->unk78 = (long) (((MKAnimScript *) this->unk34)->GetAnim("loaded"));
    this->unk70 = MKModel_GetRefPointIndex(this->unk2C, "r_ammo");
}

s32 CatapultDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_1266;

    var_r31_1266 = 0;
    if ((KDPropDescriptor::LoadLine(arg0) != 0) || (KDSound_LoadLine(arg0, "sndFire", (int *) &this->unk80) != 0) || (KDSound_LoadLine(arg0, "sndClick", (int *) &this->unk88) != 0) || (KDSound_LoadLine(arg0, "sndWindUpLP", (int *) &this->unk84) != 0)) {
        var_r31_1266 = 1;
    }
    return var_r31_1266;
}

void CatapultDescriptor::Init() {
    KDPropDescriptor::Init();
    this->unk80 = 0;
    this->unk84 = 0;
    this->unk88 = 0;
}

#if 0 // DRAFT: undefined identifier 'groups'
s32 Catapult_GetCatapult(int arg0, int arg1) {
    return *(&groups[arg0] + (arg1 * 4));
}
#endif

s32 Catapult_GetMaxPerGroup() {
    return 6;
}

#if 0 // DRAFT: undefined identifier 'groups'
void Catapult_InitModule() {
    memset(groups, 0, 0xC0U);
}
#endif

#if 0 // DRAFT: undefined identifier '__ptmf_null'
void Catapult_cpp::__sinit() {
    s32 sp10;
    s32 spC;
    s32 sp8;
    f64 temp_f0_1581;
    f64 temp_f1_1578;
    f64 temp_f1_1587;
    f64 temp_f1_1606;
    f64 temp_f3_1564;
    f64 temp_f3_1577;
    f64 temp_f4_1575;
    f64 temp_f4_1584;
    f64 temp_f4_1604;
    f64 temp_f8_1566;
    void *temp_r30_1576;

    temp_f3_1564 = __frsqrte(2014000.0);
    temp_f8_1566 = __frsqrte(380000.0);
    temp_f4_1575 = 0.5 * temp_f3_1564;
    temp_r30_1576 = &lit_723 + 0x48;
    temp_f3_1577 = -((2014000.0 * (temp_f3_1564 * temp_f3_1564)) - 3.0);
    temp_f1_1578 = 0.5 * temp_f8_1566;
    temp_f0_1581 = -((380000.0 * (temp_f8_1566 * temp_f8_1566)) - 3.0);
    M2C_FIELD(&lit_723, s32 *, 0x48) = (s32) M2C_FIELD(&lit_723, s32 *, 0);
    temp_f4_1584 = temp_f4_1575 * temp_f3_1577;
    M2C_FIELD(&lit_723, s32 *, 0x50) = (s32) M2C_FIELD(&lit_723, s32 *, 8);
    temp_f1_1587 = temp_f1_1578 * temp_f0_1581;
    M2C_FIELD(&lit_723, s32 *, 0x4C) = (s32) M2C_FIELD(&lit_723, s32 *, 4);
    sp8 = M2C_FIELD(&__ptmf_null, s32 *, 0);
    spC = M2C_FIELD(&__ptmf_null, s32 *, 4);
    sp10 = M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r30_1576, s32 *, 0xC) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    temp_f4_1604 = 0.5 * temp_f4_1584 * -((2014000.0 * (temp_f4_1584 * temp_f4_1584)) - 3.0);
    M2C_FIELD(temp_r30_1576, s32 *, 0x10) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    temp_f1_1606 = 0.5 * temp_f1_1587 * -((380000.0 * (temp_f1_1587 * temp_f1_1587)) - 3.0);
    M2C_FIELD(temp_r30_1576, s32 *, 0x14) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r30_1576, s32 *, 0x18) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r30_1576, s32 *, 0x1C) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r30_1576, s32 *, 0x20) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r30_1576, s32 *, 0x24) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r30_1576, s32 *, 0x28) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r30_1576, s32 *, 0x2C) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r30_1576, s32 *, 0x30) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r30_1576, s32 *, 0x34) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r30_1576, s32 *, 0x38) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r30_1576, s32 *, 0x3C) = (s32) M2C_FIELD(&lit_723, s32 *, 0xC);
    M2C_FIELD(temp_r30_1576, s32 *, 0x40) = (s32) M2C_FIELD(&lit_723, s32 *, 0x10);
    M2C_FIELD(temp_r30_1576, s32 *, 0x44) = (s32) M2C_FIELD(&lit_723, s32 *, 0x14);
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_1604 * -((2014000.0 * (temp_f4_1604 * temp_f4_1604)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = (f32) (380000.0 * (0.5 * temp_f1_1606 * -((380000.0 * (temp_f1_1606 * temp_f1_1606)) - 3.0)));
    M2C_FIELD(temp_r30_1576, s32 *, 0x48) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r30_1576, s32 *, 0x4C) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r30_1576, s32 *, 0x50) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r30_1576, s32 *, 0x54) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r30_1576, s32 *, 0x58) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r30_1576, s32 *, 0x5C) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r30_1576, s32 *, 0x60) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r30_1576, s32 *, 0x64) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r30_1576, s32 *, 0x68) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r30_1576, s32 *, 0x6C) = (s32) M2C_FIELD(&lit_723, s32 *, 0x18);
    M2C_FIELD(temp_r30_1576, s32 *, 0x70) = (s32) M2C_FIELD(&lit_723, s32 *, 0x1C);
    M2C_FIELD(temp_r30_1576, s32 *, 0x74) = (s32) M2C_FIELD(&lit_723, s32 *, 0x20);
    M2C_FIELD(temp_r30_1576, s32 *, 0x78) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r30_1576, s32 *, 0x7C) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r30_1576, s32 *, 0x80) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r30_1576, s32 *, 0x84) = (s32) M2C_FIELD(&lit_723, s32 *, 0x24);
    M2C_FIELD(temp_r30_1576, s32 *, 0x88) = (s32) M2C_FIELD(&lit_723, s32 *, 0x28);
    M2C_FIELD(temp_r30_1576, s32 *, 0x8C) = (s32) M2C_FIELD(&lit_723, s32 *, 0x2C);
    M2C_FIELD(temp_r30_1576, s32 *, 0x90) = (s32) M2C_FIELD(&lit_723, s32 *, 0x30);
    M2C_FIELD(temp_r30_1576, s32 *, 0x94) = (s32) M2C_FIELD(&lit_723, s32 *, 0x34);
    M2C_FIELD(temp_r30_1576, s32 *, 0x98) = (s32) M2C_FIELD(&lit_723, s32 *, 0x38);
    M2C_FIELD(temp_r30_1576, s32 *, 0x9C) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r30_1576, s32 *, 0xA0) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r30_1576, s32 *, 0xA4) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r30_1576, s32 *, 0xA8) = (s32) M2C_FIELD(&lit_723, s32 *, 0x3C);
    M2C_FIELD(temp_r30_1576, s32 *, 0xAC) = (s32) M2C_FIELD(&lit_723, s32 *, 0x40);
    M2C_FIELD(temp_r30_1576, s32 *, 0xB0) = (s32) M2C_FIELD(&lit_723, s32 *, 0x44);
}
#endif
