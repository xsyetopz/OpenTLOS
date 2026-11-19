#include "spyro/source/FloatingPlatform.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/CrashFirePS.h"
#include "spyro/source/Crate.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/Platform.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/SeeSaw.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/TargetManager.h"
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

s32 stricmp(s8 *);                                  /* extern */
extern f32 *KDSpline_PositionMixer;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;

#if 0 // DRAFT: illegal explicit conversion from 'KDUniformSpline' to 'double'
void FloatingPlatform::UpdateMove() {
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f32 sp64;
    KDUniformSpline sp50;
    f64 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    f32 temp_f1_169;
    f32 temp_f1_92;
    f32 temp_f2_154;
    f32 temp_f5_116;
    f32 var_f0_76;
    f64 temp_f0_123;
    f64 temp_f0_133;

    if ((u8) this->unk1B0 == 0) {
        SetPos(this->unk1B8);
        return;
    }
    if ((s32) this->unk108.unk38 > 0) {
        this->unk180 += 50.0f * gUpdateTimeDelta;
        if (this->unk180 > 50.0f) {
            this->unk180 = 50.0f;
        }
    }
    if ((u32) this->unk1A4 != 0U) {
        var_f0_76 = (0.005f * this->unk180 * gUpdateTimeDelta) + this->unk1AC;
        if (var_f0_76 < 1.0f) {

        } else {
            var_f0_76 = 1.0f;
        }
        if (var_f0_76 > 0.0f) {

        } else {
            var_f0_76 = 0.0f;
        }
        this->unk1AC = var_f0_76;
        temp_f1_92 = this->unk1AC;
        if ((temp_f1_92 == 0.0f) || (temp_f1_92 == 1.0f)) {
            this->unk180 = 0.0f;
        }
        sp8 = 0.0f;
        sp50.GetMeasure(this->unk1AC, (Matrix *) &this->unk198, KDSpline_PositionMixer);
        M2C_FIELD(this, f64 *, 0x1B8) = M2C_BITWISE(f64, sp50);
        M2C_FIELD(this, f64 *, 0x1C0) = (f64) sp50.unk8;
    } else {
        temp_f5_116 = this->unk180;
        temp_f0_123 = M2C_FIELD(&MKVector3::up, f64 *, 0) * (f64) temp_f5_116;
        sp30 = temp_f0_123;
        sp40 = temp_f0_123;
        sp38 = MKVector3::up.unk8 * temp_f5_116;
        sp48 = (f64) sp38;
        temp_f0_133 = temp_f0_123 * (f64) gUpdateTimeDelta;
        sp20 = temp_f0_133;
        sp70 = temp_f0_133;
        sp28 = (f32) sp48 * gUpdateTimeDelta;
        sp78 = (f64) sp28;
        sp10 = M2C_FIELD(this, f64 *, 0x1B8) + temp_f0_133;
        sp50.unk10 = sp10;
        temp_f2_154 = this->unk184 + this->unk188;
        sp18 = this->unk1B8.unk8 + (f32) sp78;
        sp68 = (f64) sp18;
        M2C_ERROR(/* unknown instruction: cror 0x2, 0x0, 0x2 */);
        if (sp64 == temp_f2_154) {
            sp64 = temp_f2_154;
            this->unk180 = 0.0f;
        }
        temp_f1_169 = this->unk184 + this->unk18C;
        if (sp64 >= temp_f1_169) {
            sp64 = temp_f1_169;
            this->unk180 = 0.0f;
        }
        M2C_FIELD(this, f64 *, 0x1B8) = M2C_BITWISE(f64, sp50.unk10);
        M2C_FIELD(this, f64 *, 0x1C0) = sp68;
    }
    SetPos(this->unk1B8);
}
#endif

void FloatingPlatform::Message(MKMessage *arg0) {
    s32 temp_r0_202;

    temp_r0_202 = arg0->unk0;
    switch (temp_r0_202) {                          /* irregular */
    case 0xB5:
        this->unk1B0 = 1;
        break;
    case 0xB4:
        this->unk1B0 = 0;
        break;
    }
    Platform::Message(arg0);
}

void FloatingPlatform::PropUpdate() {
    MKVector3 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 spC;
    f32 sp8;
    f64 temp_f0_265;
    f64 temp_f0_294;
    void *temp_r4_263;
    void *temp_r4_292;

    Platform::PropUpdate();
    if ((u8) this->unk1B0 != 0) {
        this->unk180 = -((20.0f * gUpdateTimeDelta) - this->unk180);
        if (this->unk180 < -50.0f) {
            this->unk180 = -50.0f;
        }
        MKModel_CalculateRefPointWorldPosition(this->unk4, this->unk190, &sp50);
        if (MKRand_Int((int *) &gViewSeed, 0, 3) == 0) {
            temp_r4_263 = ((u8 *) this->unk8) + 0x10;
            temp_f0_265 = M2C_FIELD(temp_r4_263, f64 *, 0) * 5.56078426e-315;
            sp20 = temp_f0_265;
            sp40 = temp_f0_265;
            sp28 = M2C_FIELD(temp_r4_263, f32 *, 8) * 150.0f;
            sp48 = (f64) sp28;
            spC = MKRand_Float((int *) &gViewSeed, 1.0f, 3.0f);
            ((CrashFirePS *) (M2C_FIELD(&gb, CrashFirePS **, 0x68)))->Emit(sp50, *((MKVector3 *) &sp40), spC);
        }
        if ((s32) this->unk108.unk38 > 0) {
            temp_r4_292 = ((u8 *) this->unk8) + 0x10;
            temp_f0_294 = M2C_FIELD(temp_r4_292, f64 *, 0) * 1.628603276e-314;
            sp10 = temp_f0_294;
            sp30 = temp_f0_294;
            sp18 = M2C_FIELD(temp_r4_292, f32 *, 8) * -1000.0f;
            sp38 = (f64) sp18;
            sp8 = MKRand_Float((int *) &gViewSeed, 2.0f, 8.0f);
            ((CrashFirePS *) (M2C_FIELD(&gb, CrashFirePS **, 0x68)))->Emit(sp50, *((MKVector3 *) &sp30), sp8);
        }
    }
}

void FloatingPlatform::Reset() {
    KDUniformSpline sp10;
    f32 sp8;

    this->unk180 = 0.0f;
    if ((u32) this->unk1A4 != 0U) {
        if ((u8) this->unk194 != 0) {
            this->unk1AC = 1.0f;
            this->unk1B0 = 0;
        }
        sp8 = 0.0f;
        sp10.GetMeasure(this->unk1AC, (Matrix *) &this->unk198, KDSpline_PositionMixer);
        MKModel_SetPosition(this->unk4, *((MKVector3 *) &sp10));
    }
}

f32 FloatingPlatform::Resolve() {
    Platform::Resolve();
    this->unk184 = M2C_FIELD(this->unk8, f32 *, 0x34);
    this->unk190 = MKModel_GetRefPointIndex(this->unk4, "r_flame");
}

s32 FloatingPlatform::LoadDone() {
    Platform::LoadDone();
    this->unk188 *= 100.0f;
    this->unk18C *= 100.0f;
    M2C_FIELD(this, f64 *, 0x1B8) = (f64) M2C_FIELD(&MKProp::loadInfo, f64 *, 0x40);
    M2C_FIELD(this, f64 *, 0x1C0) = (f64) M2C_FIELD(&MKProp::loadInfo, f64 *, 0x48);
}

#if 0 // DRAFT: function call 'stricmp(const char[10])' does not match 'stricmp(signed char *)'
s32 FloatingPlatform::LoadLine(MKIniLine *arg0) {
    MKVector3 sp8;
    MKIniLine *var_r30_463;
    s32 temp_r3_450;
    s32 var_r30_488;

    if (Platform::LoadLine(arg0) != 0) {
        return 1;
    }
    arg0->GetFieldName();
    if (stricmp("waypoints") == 0) {
        if ((u32) this->unk1A4 != 0U) {
            return 0;
        }
        temp_r3_450 = arg0->GetNmbrOfSubLines();
        if (temp_r3_450 == 0) {
            return 0;
        }
        ((KDUniformSpline *) &this->unk198)->Init(temp_r3_450, 0U);
        var_r30_463 = arg0->unkC->GetSubLine(arg0);
loop_9:
        if (var_r30_463 != NULL) {
            var_r30_463->AsVector3(0, &sp8);
            ((KDUniformSpline *) &this->unk198)->AddNode(sp8);
            var_r30_463 = var_r30_463->unkC->GetNextLine(var_r30_463);
            goto loop_9;
        }
        return 1;
    }
    var_r30_488 = 0;
    if ((arg0->LoadFloat("Floor", &this->unk188, 0) != 0) || (arg0->LoadFloat("Ceiling", &this->unk18C, 0) != 0) || (arg0->LoadBool("StartAtPathEnd", &this->unk194, 0) != 0)) {
        var_r30_488 = 1;
    }
    return var_r30_488;
}
#endif

void FloatingPlatform::Deinit() {
    if ((u32) this->unk1A4 != 0U) {
        ((KDUniformSpline *) &this->unk198)->Deinit();
    }
    Platform::Deinit();
}

void FloatingPlatform::Init() {
    Platform::Init();
    this->unk188 = 0.0f;
    this->unk18C = 5.0f;
    this->unk194 = 0;
    this->unk1AC = 0.0f;
    this->unk1B0 = 1;
    this->unk1B8.unk0 = 0.0f;
    this->unk1B8.unk4 = 0.0f;
    this->unk1B8.unk8 = 0.0f;
}
