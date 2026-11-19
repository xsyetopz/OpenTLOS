#include "spyro/source/DartTrap.h"
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
#include "common/Source/MKPtrList.h"
#include "common/Source/MKResource.h"
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
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/Level.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Projectile.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

extern s32 GS_DartTrapFire;
extern f32 gUpdateTimeDelta;
extern GameGlobals gb;
#if 0 // DRAFT: illegal implicit conversion from 'const char[5]' to
static s8 *pDartTrapAnimEvents = "Fire";
#endif

void DartTrap::SetState(int arg0) {
    if ((s32) this->unk94 != arg0) {
        this->unk94 = arg0;
    }
}

void DartTrap::SetAnim(int arg0) {
    this->unk80->SetAnim(M2C_FIELD((checked_cast<DartTrapDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (arg0 * 4)), MKAnim **, 0x70), this->unkA0, 0.0f, 0, -1);
}

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void DartTrap::Shoot() {
    MKCollisionResult spC0;
    MKVector3 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;                                       /* compiler-managed */
    f64 sp90;                                       /* compiler-managed */
    f64 sp88;
    f64 sp80;
    MKVector3 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    f32 var_f4_140;
    f32 var_f4_207;
    f64 temp_f0_241;
    f64 temp_f0_297;
    f64 temp_f1_146;
    f64 temp_f1_152;
    f64 temp_f1_156;
    s32 temp_r3_175;
    s32 var_r0_185;
    void *temp_r3_100;
    void *temp_r3_107;
    void *temp_r3_118;
    void *temp_r3_271;
    void *temp_r3_290;
    void *temp_r3_91;

    temp_r3_91 = this->unk90;
    if (temp_r3_91 != NULL) {
        M2C_FIELD(temp_r3_91, s32 *, 0x130) = 0;
    }
    this->unk90 = ((Projectile *)0xE)->CreateInstance((ProjectileType) M2C_ERROR(/* Read from unset register $r4 */));
    temp_r3_100 = this->unk90;
    if (temp_r3_100 != NULL) {
        M2C_FIELD(M2C_FIELD(temp_r3_100, void **, 0x44), M2C_UNK (**)(), 0x20)();
        temp_r3_107 = this->unk90;
        M2C_FIELD(M2C_FIELD(temp_r3_107, void **, 0x44), M2C_UNK (**)(void *), 0x30)(temp_r3_107);
        M2C_FIELD(this->unk90, DartTrap **, 0x130) = this;
        MKModel_CalculateRefPointWorldPosition(this->unk4, this->unk98, &spB0);
        temp_r3_118 = this->unk8;
        sp40 = -M2C_FIELD(temp_r3_118, f32 *, 0x20);
        sp44 = -M2C_FIELD(temp_r3_118, f32 *, 0x24);
        sp48 = -M2C_FIELD(temp_r3_118, f32 *, 0x28);
        sp90 = (f64) sp40;
        sp98 = (f64) sp48;
        var_f4_140 = ((f32) sp98 * (f32) sp98) + (((f32) sp90 * (f32) sp90) + ((*(f32 *) ((u8 *) &sp88 + 0xc)) * (*(f32 *) ((u8 *) &sp88 + 0xc))));
        if (var_f4_140 > 0.000001f) {
            if (var_f4_140 > 0.0f) {
                temp_f1_146 = __frsqrte(var_f4_140);
                temp_f1_152 = 0.5 * temp_f1_146 * -(((f64) var_f4_140 * (temp_f1_146 * temp_f1_146)) - 3.0);
                temp_f1_156 = 0.5 * temp_f1_152 * -(((f64) var_f4_140 * (temp_f1_152 * temp_f1_152)) - 3.0);
                var_f4_140 = (f32) ((f64) var_f4_140 * (0.5 * temp_f1_156 * -(((f64) var_f4_140 * (temp_f1_156 * temp_f1_156)) - 3.0)));
            } else if (var_f4_140 < M2C_BITWISE(f32, 0.0)) {
                var_f4_140 = __float_nan;
            } else {
                sp8 = var_f4_140;
                temp_r3_175 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_175) {              /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_185 = 1;
                    } else {
                        var_r0_185 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_185 = 5;
                    } else {
                        var_r0_185 = 3;
                    }
                    break;
                default:
                    var_r0_185 = 4;
                    break;
                }
                if (var_r0_185 == 1) {
                    var_f4_140 = __float_nan;
                }
            }
            var_f4_207 = 1.0f / var_f4_140;
        } else {
            var_f4_207 = 0.0f;
        }
        sp90 = (f32) sp90 * var_f4_207;
        (*(f32 *) ((u8 *) &sp88 + 0xc)) *= var_f4_207;
        sp98 = (f32) sp98 * var_f4_207;
        sp70.operator*(2000.0f);
        sp20 = M2C_BITWISE(f64, spB0) + M2C_BITWISE(f64, sp70);
        sp80 = sp20;
        sp28 = spB0.unk8 + sp70.unk8;
        spA0 = sp20;
        sp88 = (f64) sp28;
        spA8 = (f64) sp28;
        temp_f0_241 = (f64) sp90 * 5.53552857e-315;
        sp10 = temp_f0_241;
        sp60 = temp_f0_241;
        sp18 = sp98 * 100.0f;
        sp68 = (f64) sp18;
        spB0 = M2C_BITWISE(f64, spB0) + temp_f0_241;
        spB0.unk8 += (f32) sp68;
        if (MKCollision_RayCollide(spB0, *((MKVector3 *) &spA0), &spC0, (MKCollisionMode) 7, 0) != 0) {
            spA0 = M2C_BITWISE(f64, spC0);
            spA8 = (f64) spC0.unk8;
        }
        temp_r3_271 = this->unk90;
        M2C_FIELD(M2C_FIELD(temp_r3_271, void **, 0x44), M2C_UNK (**)(void *, MKVector3 *, f64 *, DartTrap *, M2C_UNK, M2C_UNK, f32), 0x4C)(temp_r3_271, &spB0, &spA0, this, 0, 0, 2000.0f);
        KDSound_Play3d(GS_DartTrapFire, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
        temp_r3_290 = this->unk90;
        M2C_FIELD(M2C_FIELD(temp_r3_290, void **, 0x44), M2C_UNK (**)(void *), 0x24)(temp_r3_290);
        temp_f0_297 = (f64) sp90 * 5.60222949e-315;
        sp30 = temp_f0_297;
        sp50 = temp_f0_297;
        sp38 = sp98 * 300.0f;
        sp58 = (f64) sp38;
        gb.EmitDust(spB0, *((MKVector3 *) &sp50), 1.0f, 0.0f);
    }
}
#endif

void DartTrap::Deinit() {
    void *temp_r4_331;

    temp_r4_331 = this->unk90;
    if (temp_r4_331 != NULL) {
        M2C_FIELD(temp_r4_331, s32 *, 0x130) = 0;
        this->unk90 = NULL;
    }
    KDProp::Deinit();
}

void DartTrap::Message(MKMessage *arg0) {
    s32 temp_r0_354;

    temp_r0_354 = arg0->unk0;
    switch (temp_r0_354) {                          /* irregular */
    case 0xB5:
        SetState(1);
        SetAnim(1);
        break;
    case 0xB4:
        if ((s32) this->unk94 != 0) {
            SetState(0);
            SetAnim(3);
        }
        break;
    }
    KDProp::Message(arg0);
}

#if 0 // DRAFT: function call 'KDSound_Play3d(MKAnimScript *, unsigned char *, unsigned
void DartTrap::Update() {
    s32 temp_r0_401;

    KDProp::Update();
    this->unkAC -= gUpdateTimeDelta;
    temp_r0_401 = this->unk94;
    switch (temp_r0_401) {                          /* irregular */
    case 0:
        break;
    case 1:
        if (this->unk80->unk2C & 1) {
            SetState(2);
            SetAnim(2);
            this->unkAC = this->unkA4;
            this->unk9C = 0.0f;
        }
        break;
    case 2:
        this->unk9C -= gUpdateTimeDelta;
        if ((this->unk9C <= 0.0f) && (this->unk80->unk2C & 1)) {
            SetAnim(2);
            this->unk9C = 1.0f / this->unkA0;
        }
        if (this->unk80->CheckEvent(0) != 0) {
            Shoot();
        }
        if (this->unkAC <= 0.0f) {
            SetState(3);
            SetAnim(3);
            this->unkAC = this->unkA8;
        }
        break;
    case 3:
        if ((this->unk80->unk2C & 1) && (this->unkAC <= 0.0f)) {
            if ((u8) this->unkB0 != 0) {
                SetState(0);
                SetAnim(0);
            } else {
                SetState(1);
                SetAnim(1);
                this->unkAC = this->unkA4;
            }
        }
        break;
    }
    KDSound_Play3d(this->unk80, ((u8 *) this->unk8) + 0x30, 0U, 0.0f, 0U);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to
void DartTrap::LoadDone() {
    KDProp::LoadDone();
    this->unk98 = (s32) Tools_GetMatchingRefPointIndex(this->unk4, "r_ref");
    this->unk80->InitEvents(&pDartTrapAnimEvents);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to
s32 DartTrap::LoadLine(MKIniLine *arg0) {
    s32 var_r31_552;

    var_r31_552 = 0;
    if ((KDProp::LoadLine(arg0) != 0) || (arg0->LoadFloat("SpeedMultiplier", &this->unkA0, 0) != 0) || (arg0->LoadFloat("OnTime", &this->unkA4, 0) != 0) || (arg0->LoadFloat("OffTime", &this->unkA8, 0) != 0) || (arg0->LoadBool("OneShot", &this->unkB0, 0) != 0)) {
        var_r31_552 = 1;
    }
    return var_r31_552;
}
#endif

void DartTrap::Init() {
    KDProp::Init();
    this->unk90 = NULL;
    this->unk94 = 0;
    this->unk9C = 0.0f;
    this->unkAC = 0.0f;
    this->unkA4 = 1.0f;
    this->unkA8 = 1.0f;
    this->unkB0 = 0;
}

void DartTrapDescriptor::LoadDone() {
    s8 *temp_r30_638;
    s8 *temp_r30_658;
    s8 *temp_r30_676;
    s8 *temp_r30_694;
    void *var_r3_650;
    void *var_r3_668;
    void *var_r3_686;
    void *var_r3_704;

    KDPropDescriptor::LoadDone();
    temp_r30_638 = this->unk34;
    if (((MKAnimScript *) temp_r30_638)->Exists("Idle") != 0) {
        var_r3_650 = ((MKAnimScript *) temp_r30_638)->GetAnim("Idle");
    } else {
        var_r3_650 = NULL;
    }
    this->unk70 = (s32) var_r3_650;
    temp_r30_658 = this->unk34;
    if (((MKAnimScript *) temp_r30_658)->Exists("Open") != 0) {
        var_r3_668 = ((MKAnimScript *) temp_r30_658)->GetAnim("Open");
    } else {
        var_r3_668 = NULL;
    }
    this->unk74 = (s32) var_r3_668;
    temp_r30_676 = this->unk34;
    if (((MKAnimScript *) temp_r30_676)->Exists("Shoot") != 0) {
        var_r3_686 = ((MKAnimScript *) temp_r30_676)->GetAnim("Shoot");
    } else {
        var_r3_686 = NULL;
    }
    this->unk78 = (s32) var_r3_686;
    temp_r30_694 = this->unk34;
    if (((MKAnimScript *) temp_r30_694)->Exists("Close") != 0) {
        var_r3_704 = ((MKAnimScript *) temp_r30_694)->GetAnim("Close");
    } else {
        var_r3_704 = NULL;
    }
    this->unk7C = (s32) var_r3_704;
}

#if 0 // DRAFT: illegal operand
void DartTrapDescriptor::Init() {
    s32 temp_r0_731;
    s32 var_ctr_729;
    s32 var_r3_726;

    KDPropDescriptor::Init();
    var_r3_726 = 0;
    var_ctr_729 = 4;
    do {
        temp_r0_731 = var_r3_726 + 0x70;
        var_r3_726 += 4;
        *(this + temp_r0_731) = 0;
        var_ctr_729 -= 1;
    } while (var_ctr_729 != 0);
}
#endif
