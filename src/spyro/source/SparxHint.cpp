#include "spyro/source/SparxHint.h"
#include "common/Source/Animation.h"
#include "common/Source/Font.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKFont.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
#include "spyro/source/DialogBox.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/Level.h"
#include "spyro/source/ManagedLight.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/Sparx.h"
#include "spyro/source/SparxFX.h"
#include "spyro/source/SparxPath.h"
#include "spyro/source/SplineProp.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern GameGlobals gb;
static BoundingVolume volume;                       /* type too large by 0x10; unable to generate initializer: not enough data */

#if 0 // DRAFT: ')' expected
void SparxHint::Message(MKMessage *arg0) {
    SparxHint *sp64;
    s32 sp60;
    u8 sp5E;
    s8 sp5D;
    s8 sp5C;
    s32 sp58;
    s32 sp54;
    s32 sp50;
    s32 sp4C;
    s32 sp48;
    s8 sp46;
    s8 sp45;
    s8 sp44;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    SparxHint *sp34;
    s32 sp30;
    u8 sp2E;
    s8 sp2D;
    s8 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s8 sp16;
    s8 sp15;
    s8 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    s32 temp_r0_54;
    s32 temp_r5_106;
    void *temp_r3_126;
    void *temp_r3_153;
    void *temp_r3_191;
    void *temp_r3_90;

    temp_r0_54 = arg0->unk0;
    switch (temp_r0_54) {                           /* irregular */
    case 0x18:
        if ((u32) M2C_FIELD(checked_cast<SparxHintMsg *, MKMessage>(arg0), u32 *, 0x14) != 0U) {
            this->unkA9 = 1;
        } else {
            this->unkA9 = 0;
            this->unk90.Send(NULL);
        }
        break;
    case 0xB5:
        gb.GetSpyro();
        temp_r3_90 = checked_cast<Sparx *, Sparx>(M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), Sparx **, 0xB70));
        if ((u8) this->unkA9 == 0) {
            sp54 = 0;
            sp50 = 0x18;
            sp58 = 0;
            sp64 = NULL;
            sp5C = 0;
            sp5D = 0;
            sp60 = 0;
            sp5E = 0;
            temp_r5_106 = this->unk94;
            sp58 = temp_r5_106;
            sp64 = this;
            sp5D = 1;
            sp5E = this->unkAB;
            sp60 = this->unkAC;
            M2C_FIELD(M2C_FIELD(temp_r3_90, void **, 0x44), M2C_UNK (**)(s32 *, s32, M2C_UNK), 0x2C)(&sp50, temp_r5_106, 0);
            this->unkAA = 1;
        }
        break;
    case 0xB4:
        gb.GetSpyro();
        temp_r3_126 = checked_cast<Sparx *, Sparx>(M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), Sparx **, 0xB70));
        sp4C = 0;
        sp3C = 0;
        sp38 = 0x18;
        sp40 = 0;
        sp44 = 0;
        sp45 = 0;
        sp48 = 0;
        sp46 = 0;
        sp4C = 0;
        M2C_FIELD(M2C_FIELD(temp_r3_126, void **, 0x44), M2C_UNK (**)(s32 *, M2C_UNK), 0x2C)(&sp38, 0);
        this->unkAA = 0;
        this->unkA9 = 0;
        this->unkA8 = 0;
        break;
    case 0xB7:
        gb.GetSpyro();
        temp_r3_153 = checked_cast<Sparx *, Sparx>(M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), Sparx **, 0xB70));
        if ((u8) this->unkA9 == 0) {
            sp24 = 0;
            sp20 = 0x18;
            sp28 = 0;
            sp34 = NULL;
            sp2C = 0;
            sp2D = 0;
            sp30 = 0;
            sp2E = 0;
            sp28 = this->unk94;
            sp34 = this;
            sp2D = 1;
            sp2E = this->unkAB;
            sp30 = this->unkAC;
            sp2C = 1;
            sp2D = 0;
            M2C_FIELD(M2C_FIELD(temp_r3_153, void **, 0x44), M2C_UNK (**)(s32 *, M2C_UNK, M2C_UNK), 0x2C)(&sp20, 1, 0);
            this->unkAA = 1;
        }
        break;
    case 0xB6:
        gb.GetSpyro();
        temp_r3_191 = checked_cast<Sparx *, Sparx>(M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), Sparx **, 0xB70));
        sp1C = 0;
        spC = 0;
        sp8 = 0x18;
        sp10 = 0;
        sp14 = 0;
        sp15 = 0;
        sp18 = 0;
        sp16 = 0;
        sp1C = 0;
        M2C_FIELD(M2C_FIELD(temp_r3_191, void **, 0x44), M2C_UNK (**)(s32 *, M2C_UNK), 0x2C)(&sp8, 0);
        this->unkAA = 0;
        this->unkA9 = 0;
        this->unkA8 = 0;
        break;
    }
    MKProp::Message(arg0);
}
#endif

void *SparxHint::Update() {
    SparxHint *sp54;
    s32 sp50;
    s8 sp4E;
    s8 sp4D;
    s8 sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    s8 sp36;
    s8 sp35;
    s8 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    f64 sp20;
    f64 sp18;
    f64 sp10;
    f64 sp8;
    f32 temp_f0_279;
    f32 temp_f0_308;
    f32 temp_f1_272;
    f32 temp_f2_271;
    f32 temp_f2_275;
    s32 temp_r3_232;
    s32 temp_r3_312;
    u8 temp_r0_261;
    void *temp_r30_253;
    void *temp_r3_260;
    void *temp_r5_250;

    MKProp::Update();
    temp_r3_232 = this->unk98;
    if (((temp_r3_232 == 0) || (temp_r3_232 > (s32) this->unk9C)) && ((u8) this->unkA8 != 0) && ((u8) this->unkAA == 0)) {
        gb.GetSpyro();
        temp_r5_250 = this->unk8;
        temp_r30_253 = checked_cast<Sparx *, Sparx>(M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), Sparx **, 0xB70));
        sp8 = M2C_FIELD(temp_r5_250, f64 *, 0x30);
        sp10 = M2C_FIELD(temp_r5_250, f64 *, 0x38);
        gb.GetSpyro();
        temp_r3_260 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), void **, 8);
        temp_r0_261 = this->unkA9;
        sp18 = M2C_FIELD(temp_r3_260, f64 *, 0x30);
        sp20 = M2C_FIELD(temp_r3_260, f64 *, 0x38);
        temp_f2_271 = (f32) sp20 - (f32) sp10;
        temp_f1_272 = (f32) sp18 - (f32) sp8;
        temp_f2_275 = (temp_f1_272 * temp_f1_272) + (temp_f2_271 * temp_f2_271);
        if (temp_r0_261 == 0) {
            temp_f0_279 = 100.0f * this->unkA0;
            if (temp_f2_275 < (temp_f0_279 * temp_f0_279)) {
                sp44 = 0;
                sp40 = 0x18;
                sp48 = 0;
                sp54 = NULL;
                sp4C = 0;
                sp4D = 0;
                sp50 = 0;
                sp4E = 0;
                sp48 = this->unk94;
                sp54 = this;
                M2C_FIELD(M2C_FIELD(temp_r30_253, void **, 0x44), M2C_UNK (**)(void *, s32 *, M2C_UNK), 0x2C)(temp_r30_253, &sp40, 0);
                return;
            }
        }
        if (temp_r0_261 != 0) {
            temp_f0_308 = 100.0f * this->unkA4;
            if (temp_f2_275 > (temp_f0_308 * temp_f0_308)) {
                temp_r3_312 = this->unk98;
                if ((temp_r3_312 != 0) && (temp_r3_312 <= (s32) this->unk9C)) {
                    this->unkA8 = 0;
                } else {
                    this->unk9C += 1;
                }
                this->unkA9 = 0;
                sp3C = 0;
                sp2C = 0;
                sp28 = 0x18;
                sp30 = 0;
                sp34 = 0;
                sp35 = 0;
                sp38 = 0;
                sp36 = 0;
                sp3C = 0;
                M2C_FIELD(M2C_FIELD(temp_r30_253, void **, 0x44), M2C_UNK (**)(void *, s32 *, M2C_UNK), 0x2C)(temp_r30_253, &sp28, 0);
                this->unk90.Send(NULL);
            }
        }
    }
}

s32 SparxHint::LoadDone() {
    MKProp::LoadDone();
    this->unk8 = &this->unk50;
    M2C_STRUCT_COPY((s32) &this->unk4C + 4, (s32) (&MKProp::loadInfo - 4) + 4, 0x40);
}

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to 'bool *'
s32 SparxHint::LoadLine(MKIniLine *arg0) {
    s32 var_r31_394;

    var_r31_394 = 0;
    if ((MKProp::LoadLine(arg0) != 0) || (arg0->LoadInt("Priority", (int *) &this->unk94, 0) != 0) || (arg0->LoadFloat("RadiusNotify", &this->unkA0, 0) != 0) || (arg0->LoadFloat("RadiusdeActivate", &this->unkA4, 0) != 0) || (arg0->LoadInt("NumUses", (int *) &this->unk98, 0) != 0) || (arg0->LoadInt("SpeechMode", (int *) &this->unkAC, 0) != 0) || (arg0->LoadBool("Snap", &this->unkAB, 0) != 0) || (this->unk90.LoadLine(arg0, "OnReleaseSparx") != 0)) {
        var_r31_394 = 1;
    }
    return var_r31_394;
}
#endif

void SparxHint::Init() {
    MKProp::Init();
    this->unk98 = 0;
    this->unk9C = 0;
    this->unk94 = 1;
    this->unkA0 = 10.0f;
    this->unkA4 = 20.0f;
    this->unkA8 = 1;
    this->unkAA = 0;
    this->unkAB = 0;
    this->unkA9 = 0;
    this->unkAC = 0;
}

void SparxHintDescriptor::Init() {
    MKPropDescriptor::Init();
    this->unk1C = &volume;
}

void SparxHint_cpp::__sinit() {
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f64 temp_f0_529;
    f64 temp_f1_560;
    f64 temp_f2_524;
    f64 temp_f4_531;
    f64 temp_f4_559;
    f64 temp_f5_526;
    f64 temp_f5_545;
    f64 temp_f9_543;

    temp_f2_524 = __frsqrte(2014000.0);
    temp_f5_526 = __frsqrte(380000.0);
    temp_f0_529 = temp_f2_524 * temp_f2_524;
    temp_f4_531 = temp_f5_526 * temp_f5_526;
    sp18 = -0.5f;
    sp20 = -0.5f;
    sp1C = -0.5f;
    sp10 = 1.0f;
    temp_f9_543 = 0.5 * temp_f2_524 * -((2014000.0 * temp_f0_529) - 3.0);
    M2C_FIELD(&volume, f64 *, 0) = (f64) sp18;
    temp_f5_545 = 0.5 * temp_f5_526 * -((380000.0 * temp_f4_531) - 3.0);
    sp8 = 1.0f;
    spC = 1.0f;
    M2C_FIELD(&volume, f64 *, 8) = (f64) sp20;
    M2C_FIELD(&volume, f64 *, 0x10) = (f64) sp8;
    M2C_FIELD(&volume, f64 *, 0x18) = (f64) sp10;
    temp_f4_559 = 0.5 * temp_f9_543 * -((2014000.0 * (temp_f9_543 * temp_f9_543)) - 3.0);
    temp_f1_560 = 0.5 * temp_f5_545 * -((380000.0 * (temp_f5_545 * temp_f5_545)) - 3.0);
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_559 * -((2014000.0 * (temp_f4_559 * temp_f4_559)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = (f32) (380000.0 * (0.5 * temp_f1_560 * -((380000.0 * (temp_f1_560 * temp_f1_560)) - 3.0)));
}
