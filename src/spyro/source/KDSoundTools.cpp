#include "spyro/source/KDSoundTools.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/KDFaderObject.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/TargetManager.h"
#include "spyro/source/Tools.h"
#include "unplaced_inlines.h"
#include <m2c_macros.h>

extern f32 *KDSpline_PositionMixer;
extern f32 gUpdateTimeDelta;
extern M2C_UNK gb;

void KDSound_SoundWall::SetBeginEndTimes(float arg0, float arg1) {
    this->unk54 = arg0;
    this->unk58 = arg1;
}

#if 0 // DRAFT: undefined identifier 'sp20'
void KDSound_SoundWall::Update(bool arg0) {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp18;
    f32 sp10;
    s32 sp8;
    f32 temp_f0_91;
    f32 temp_f1_76;
    f32 temp_f2_88;
    f32 var_f1_61;
    f32 var_f1_90;
    f64 temp_f0_57;
    f64 temp_f1_56;
    s32 temp_r3_112;
    s32 temp_r3_124;
    u8 var_r0_31;
    void *temp_r3_33;
    void *temp_r3_55;

    if ((s32) this->unk68 != 0) {
        var_r0_31 = 0;
        temp_r3_33 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
        sp38 = M2C_FIELD(temp_r3_33, f64 *, 0x30);
        sp40 = M2C_FIELD(temp_r3_33, f64 *, 0x38);
        if ((this->unk30 == (f32) sp38) && (this->unk34 == (*(f32 *) ((u8 *) &sp38 + 0x4))) && (this->unk38 == (f32) sp40)) {
            var_r0_31 = 1;
        }
        if ((var_r0_31 == 0) && (arg0 != 0)) {
            temp_r3_55 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
            temp_f1_56 = M2C_FIELD(temp_r3_55, f64 *, 0x30);
            temp_f0_57 = M2C_FIELD(temp_r3_55, f64 *, 0x38);
            sp28 = temp_f1_56;
            M2C_FIELD(this, f32 *, 0x30) = temp_f1_56;
            M2C_FIELD(this, f32 *, 0x38) = temp_f0_57;
            var_f1_61 = this->unk58;
            sp30 = temp_f0_57;
            if (var_f1_61 > 0.0001f) {

            } else {
                var_f1_61 = 0.0001f;
            }
            this->unk58 = var_f1_61;
            temp_f1_76 = Tools_GetClosestSplineTime(this->unk28, *((MKVector3 *) &this->unk30), this->unk68, this->unk54, this->unk58);
            sp10 = 0.0f;
            ((KDUniformSpline *) &sp18)->GetMeasure(temp_f1_76, (Matrix *) this->unk28, KDSpline_PositionMixer);
            this->unk40 = sp18;
            this->unk48 = sp20;
            temp_f2_88 = M2C_FIELD(this, f32 *, 0x44);
            var_f1_90 = this->unk34;
            temp_f0_91 = temp_f2_88 + this->unk50;
            if (var_f1_90 < temp_f0_91) {

            } else {
                var_f1_90 = temp_f0_91;
            }
            if (var_f1_90 > temp_f2_88) {

            } else {
                var_f1_90 = temp_f2_88;
            }
            M2C_FIELD(this, f32 *, 0x44) = var_f1_90;
        }
    }
    if (arg0 != (u8) this->unk6C) {
        if (arg0 != 0) {
            temp_r3_112 = this->unk60;
            if (temp_r3_112 != 0) {
                KDSound_Play3d(temp_r3_112, (MKVector3 *) &this->unk40, 0U, -1, 0.0f, 0U);
            }
        }
        if (arg0 == 0) {
            temp_r3_124 = this->unk64;
            if (temp_r3_124 != 0) {
                KDSound_Play3d(temp_r3_124, (MKVector3 *) &this->unk40, 0U, -1, 0.0f, 0U);
            }
        }
        this->unk6C = arg0;
    }
    if (((u8) this->unk6C != 0) || (KDSound_IsVoicePlaying(this->unk0) != 0)) {
        sp8 = 1;
        ((KDSoundFader *) this)->Update(this->unk5C, 1U, this->unk6C, NULL, (MKVector3 *) &this->unk40, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    }
}
#endif

void KDSound_SoundWall::Message(MKMessage *arg0) {
    ((KDSoundPlayer *) this)->Message(arg0);
}

void KDSound_SoundWall::Deinit() {
    KDSound_Stop((int *) &this->unk0);
}

#if 0 // DRAFT: illegal explicit conversion from 'KDUniformSpline' to 'double'
void KDSound_SoundWall::Init(KDUniformSpline *arg0, float arg1, int arg2, int arg3, int arg4, float arg5, float arg6, float arg7, float arg8) {
    KDUniformSpline sp10;
    f32 sp8;
    KDUniformSpline *temp_r4_238;

    ((KDSoundFader *) this)->Init(arg5, arg6);
    this->unk30 = 0.0f;
    this->unk34 = 0.0f;
    this->unk38 = 0.0f;
    M2C_FIELD(this, f32 *, 0x40) = 0.0f;
    M2C_FIELD(this, f32 *, 0x44) = 0.0f;
    M2C_FIELD(this, f32 *, 0x48) = 0.0f;
    this->unk54 = arg7;
    this->unk58 = arg8;
    this->unk28 = arg0;
    this->unk5C = arg2;
    this->unk60 = arg3;
    this->unk64 = arg4;
    this->unk50 = arg1;
    this->unk68 = (s32) (this->unk28->unk8 / 50.0f);
    this->unk6C = 0;
    temp_r4_238 = this->unk28;
    if ((temp_r4_238->unk8 <= 200.0f) && (this->unk50 <= 200.0f)) {
        sp8 = 0.0f;
        sp10.GetMeasure(0.5f, (Matrix *) temp_r4_238, KDSpline_PositionMixer);
        this->unk40 = M2C_BITWISE(f64, sp10);
        this->unk48 = (f64) sp10.unk8;
        M2C_FIELD(this, f32 *, 0x44) = (f32) ((this->unk50 * 0.5f) + M2C_FIELD(this, f32 *, 0x44));
        this->unk68 = 0;
    }
}
#endif

void KDSound_LoopSoundEvent::Update(MKVector3 *arg0, unsigned int arg1) {
    s32 sp8;
    u8 temp_r6_295;
    u8 temp_r6_313;
    u8 temp_r6_331;

    if ((KDSoundFader *) this->unk0 != NULL) {
        temp_r6_295 = this->unkC->CheckEvent(this->unk1C);
        sp8 = 1;
        this->unk0->Update(this->unk10, 1U, temp_r6_295, NULL, arg0, arg1, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    }
    if ((KDSoundFader *) this->unk4 != NULL) {
        temp_r6_313 = this->unkC->CheckEvent(this->unk20);
        sp8 = 1;
        this->unk4->Update(this->unk14, 1U, temp_r6_313, NULL, arg0, arg1, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    }
    if ((KDSoundFader *) this->unk8 != NULL) {
        temp_r6_331 = this->unkC->CheckEvent(this->unk24);
        sp8 = 1;
        this->unk8->Update(this->unk18, 1U, temp_r6_331, NULL, arg0, arg1, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    }
}

void KDSound_LoopSoundEvent::Message(MKMessage *arg0) {
    KDSoundFader *temp_r3_358;
    KDSoundFader *temp_r3_363;
    KDSoundFader *temp_r3_369;

    temp_r3_358 = this->unk0;
    if (temp_r3_358 != NULL) {
        ((KDSoundPlayer *) temp_r3_358)->Message(arg0);
    }
    temp_r3_363 = this->unk4;
    if (temp_r3_363 != NULL) {
        ((KDSoundPlayer *) temp_r3_363)->Message(arg0);
    }
    temp_r3_369 = this->unk8;
    if (temp_r3_369 != NULL) {
        ((KDSoundPlayer *) temp_r3_369)->Message(arg0);
    }
}

void KDSound_LoopSoundEvent::Deinit() {
    KDSoundFader *temp_r31_394;
    KDSoundFader *temp_r31_408;
    KDSoundFader *temp_r31_422;
    KDSoundFader *temp_r3_390;
    KDSoundFader *temp_r3_404;
    KDSoundFader *temp_r3_418;
    s32 temp_cr0_eq_395;
    s32 temp_cr0_eq_409;
    s32 temp_cr0_eq_423;

    temp_r3_390 = this->unk0;
    if (temp_r3_390 != NULL) {
        KDSound_Stop((int *) &temp_r3_390->unk0);
        temp_r31_394 = this->unk0;
        temp_cr0_eq_395 = temp_r31_394 == NULL;
        if (temp_cr0_eq_395 == 0) {
            if (temp_cr0_eq_395 == 0) {
                KDSound_Stop((int *) &temp_r31_394->unk0);
            }
            operator delete(temp_r31_394);
        }
    }
    temp_r3_404 = this->unk4;
    if (temp_r3_404 != NULL) {
        KDSound_Stop((int *) &temp_r3_404->unk0);
        temp_r31_408 = this->unk4;
        temp_cr0_eq_409 = temp_r31_408 == NULL;
        if (temp_cr0_eq_409 == 0) {
            if (temp_cr0_eq_409 == 0) {
                KDSound_Stop((int *) &temp_r31_408->unk0);
            }
            operator delete(temp_r31_408);
        }
    }
    temp_r3_418 = this->unk8;
    if (temp_r3_418 != NULL) {
        KDSound_Stop((int *) &temp_r3_418->unk0);
        temp_r31_422 = this->unk8;
        temp_cr0_eq_423 = temp_r31_422 == NULL;
        if (temp_cr0_eq_423 == 0) {
            if (temp_cr0_eq_423 == 0) {
                KDSound_Stop((int *) &temp_r31_422->unk0);
            }
            operator delete(temp_r31_422);
        }
    }
}

#if 0 // DRAFT: pointer/array required
void KDSound_LoopSoundEvent::Init(MKAnimScript *arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6) {
    this->unk10 = arg2;
    this->unk14 = arg4;
    this->unk18 = arg6;
    this->unk0 = NULL;
    this->unk4 = NULL;
    this->unk8 = NULL;
    this->unkC = arg0;
    this->unk1C = arg1;
    this->unk20 = arg3;
    this->unk24 = arg5;
    if (((s32) this->unk10 != 0) && ((s32) this->unk1C >= 0)) {
        operator new(0x28U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = 0;
        }
        this->unk0 = M2C_ERROR(/* Read from unset register $r3 */);
        this->unk0->Init(0.25f, 0.25f);
    }
    if (((s32) this->unk14 != 0) && ((s32) this->unk20 >= 0)) {
        operator new(0x28U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = 0;
        }
        this->unk4 = M2C_ERROR(/* Read from unset register $r3 */);
        this->unk4->Init(0.25f, 0.25f);
    }
    if (((s32) this->unk18 != 0) && ((s32) this->unk24 >= 0)) {
        operator new(0x28U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = 0;
        }
        this->unk8 = M2C_ERROR(/* Read from unset register $r3 */);
        this->unk8->Init(0.25f, 0.25f);
    }
}
#endif

void KDSound_AfterRumble::Init() {
    this->unk0 = 0;
    this->unk4 = 0;
    this->unk8 = 0;
    this->unkC = 0;
    this->unk10 = 0.0f;
    this->unk14 = 0.0f;
    this->unk18 = 0.0f;
    this->unk20 = 0.0f;
    this->unk24 = 0.0f;
    this->unk28 = 0.0f;
    this->unk30 = 0.0f;
    this->unk34 = 0.0f;
    this->unk38 = 0.0f;
    this->unk40 = 0.0f;
    this->unk44 = 0.0f;
    this->unk48 = 0.0f;
    this->unk50 = 0.0f;
    this->unk54 = 0.0f;
    this->unk58 = 0.0f;
    this->unk64 = 0.0f;
    this->unk6C = 1000.0f;
    this->unk60 = 0;
    this->unk68 = 0;
}

void KDSound_AfterRumble::Stop() {
    s32 temp_r3_568;
    s32 temp_r3_577;
    s32 temp_r3_586;
    s32 temp_r3_595;

    temp_r3_568 = this->unk0;
    if ((temp_r3_568 != 0) && (KDSound_IsVoicePlaying(temp_r3_568) != 0)) {
        KDSound_Stop((int *) &this->unk0);
    }
    temp_r3_577 = this->unk4;
    if ((temp_r3_577 != 0) && (KDSound_IsVoicePlaying(temp_r3_577) != 0)) {
        KDSound_Stop((int *) &this->unk4);
    }
    temp_r3_586 = this->unk8;
    if ((temp_r3_586 != 0) && (KDSound_IsVoicePlaying(temp_r3_586) != 0)) {
        KDSound_Stop((int *) &this->unk8);
    }
    temp_r3_595 = this->unkC;
    if ((temp_r3_595 != 0) && (KDSound_IsVoicePlaying(temp_r3_595) != 0)) {
        KDSound_Stop((int *) &this->unkC);
    }
}

void KDSound_AfterRumble::Update() {
    s32 temp_r0_619;

    temp_r0_619 = this->unk68;
    if (temp_r0_619 != 0) {
        if (temp_r0_619 == 2) {
            if (KDSound_IsVoicePlaying(this->unk0) == 0) {
                this->unk68 = 0;
            }
        } else {
            this->unk64 -= gUpdateTimeDelta;
            if (this->unk64 <= 0.0f) {
                this->unk68 = 2;
                this->unk0 = KDSound_Play3d(this->unk60, (MKVector3 *) &this->unk20, 0U, -1, 0.0f, 0U);
                this->unk4 = KDSound_Play3d(this->unk60, (MKVector3 *) &this->unk30, 0U, -1, 0.0f, 0U);
                this->unk8 = KDSound_Play3d(this->unk60, (MKVector3 *) &this->unk40, 0U, -1, 0.0f, 0U);
                this->unkC = KDSound_Play3d(this->unk60, (MKVector3 *) &this->unk50, 0U, -1, 0.0f, 0U);
            }
        }
    }
}

void KDSound_AfterRumble::Message(MKMessage *arg0) {
    if ((s32) arg0->unk0 == -4) {
        if ((s32) this->unk68 == 2) {
            Stop();
        }
        this->unk68 = 0;
    }
}

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to 'signed char *'
void KDSound_AfterRumble::Trigger(MKVector3 arg0, int arg1, float arg2, float arg3) {
    f64 spC0;
    f64 spB8;
    MKVector3 spA8;
    f64 spA0;
    f64 sp98;
    MKVector3 sp88;
    f64 sp80;
    f64 sp78;
    MKVector3 sp68;
    f64 sp60;
    f64 sp58;
    MKVector3 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f64 temp_f0_736;
    f64 temp_f0_777;

    M2C_FIELD(this, f64 *, 0x10) = (f64) M2C_FIELD(arg0, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x18) = (f64) M2C_FIELD(arg0, f64 *, 8);
    this->unk6C = arg3;
    this->unk64 = arg2;
    this->unk60 = arg1;
    if ((s32) this->unk68 == 2) {
        Stop();
    }
    spA8 = MKVector(this->unk6C, 0.0f, 0.0f);
    temp_f0_736 = M2C_FIELD(this, f64 *, 0x10) + M2C_BITWISE(f64, spA8);
    sp38 = temp_f0_736;
    M2C_FIELD(this, f64 *, 0x20) = temp_f0_736;
    sp40 = this->unk18 + spA8.unk8;
    spB8 = temp_f0_736;
    M2C_FIELD(this, f64 *, 0x28) = (f64) sp40;
    spC0 = (f64) sp40;
    sp88 = MKVector(-this->unk6C, 0.0f, 0.0f);
    sp28 = M2C_FIELD(this, f64 *, 0x10) + M2C_BITWISE(f64, sp88);
    M2C_FIELD(this, f64 *, 0x30) = sp28;
    sp30 = this->unk18 + sp88.unk8;
    sp98 = sp28;
    M2C_FIELD(this, f64 *, 0x38) = (f64) sp30;
    spA0 = (f64) sp30;
    sp68 = MKVector(0.0f, 0.0f, this->unk6C);
    temp_f0_777 = M2C_FIELD(this, f64 *, 0x10) + M2C_BITWISE(f64, sp68);
    sp18 = temp_f0_777;
    M2C_FIELD(this, f64 *, 0x40) = temp_f0_777;
    sp20 = this->unk18 + sp68.unk8;
    sp78 = temp_f0_777;
    M2C_FIELD(this, f64 *, 0x48) = (f64) sp20;
    sp80 = (f64) sp20;
    sp48 = MKVector(0.0f, 0.0f, -this->unk6C);
    sp8 = M2C_FIELD(this, f64 *, 0x10) + M2C_BITWISE(f64, sp48);
    M2C_FIELD(this, f64 *, 0x50) = sp8;
    sp10 = this->unk18 + sp48.unk8;
    sp58 = sp8;
    M2C_FIELD(this, f64 *, 0x58) = (f64) sp10;
    sp60 = (f64) sp10;
    this->unk68 = 1;
}
#endif

void KDSoundFlangedFader::Stop() {
    s32 temp_r0_827;

    temp_r0_827 = this->unk50;
    switch (temp_r0_827) {                          /* irregular */
    case 0:
        this->unk6C = 0.0f;
        break;
    case 1:
        this->unk6C = this->unk54;
        break;
    }
    KDSound_Stop((int *) &this->unk0);
    KDSound_Stop((int *) &this->unk28);
}

#if 0 // DRAFT: undefined identifier 'sin'
void KDSoundFlangedFader::Update(int arg0, bool arg1, bool arg2, MKProp *arg3, MKVector3 *arg4, unsigned int arg5, int arg6) {
    s32 sp8;
    f32 temp_f1_898;
    f32 temp_f2_923;
    f32 temp_f3_922;
    s32 temp_r0_884;
    s32 temp_r0_946;

    sp8 = 1;
    ((KDSoundFader *) this)->Update(arg0, arg1, arg2, arg3, arg4, arg5, arg6, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    sp8 = 1;
    ((KDSoundFader *) &this->unk28)->Update(arg0, arg1, arg2, arg3, arg4, arg5, arg6, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    if (arg2 != 0) {
        temp_r0_884 = this->unk50;
        switch (temp_r0_884) {                      /* switch 1; irregular */
        case 0:                                     /* switch 1 */
            this->unk6C += gUpdateTimeDelta * this->unk60;
            temp_f1_898 = this->unk6C;
            if (temp_f1_898 >= 360.0f) {
                this->unk6C = temp_f1_898 - 360.0f;
            }
            KDSound_SetPitch(this->unk28, (this->unk68 * (f32) sin((f64) (0.017453292f * this->unk6C))) + this->unk64);
            return;
        case 1:                                     /* switch 1 */
            this->unk6C += gUpdateTimeDelta * this->unk5C;
            temp_f3_922 = this->unk6C;
            temp_f2_923 = this->unk58;
            if (((temp_f3_922 > temp_f2_923) && (this->unk5C > 0.0f)) || ((temp_f3_922 < temp_f2_923) && (this->unk5C < 0.0f))) {
                this->unk6C = this->unk54;
            }
            KDSound_SetPitch(this->unk28, this->unk6C);
            return;
        }
    } else {
        temp_r0_946 = this->unk50;
        switch (temp_r0_946) {                      /* switch 2; irregular */
        case 0:                                     /* switch 2 */
            this->unk6C = 0.0f;
            return;
        case 1:                                     /* switch 2 */
            this->unk6C = this->unk54;
            return;
        }
    }
}
#endif

void KDSoundFlangedFader::Message(MKMessage *arg0) {
    ((KDSoundPlayer *) this)->Message(arg0);
    ((KDSoundPlayer *) &this->unk28)->Message(arg0);
    if ((s32) arg0->unk0 == -4) {
        Stop();
    }
}

void KDSoundFlangedFader::Deinit() {
    KDSound_Stop((int *) &this->unk0);
    KDSound_Stop((int *) &this->unk28);
}

void KDSoundFlangedFader::RecalcVariables(int arg0, float arg1, float arg2, float arg3) {
    this->unk50 = arg0;
    this->unk54 = arg1;
    this->unk58 = arg2;
    this->unk60 = arg3;
    this->unk5C = this->unk60 * (this->unk58 - this->unk54);
    this->unk64 = (this->unk54 + this->unk58) * 0.5f;
    this->unk68 = (this->unk58 - this->unk54) * 0.5f;
    if ((s32) this->unk50 == 0) {
        this->unk60 *= 360.0f;
        return;
    }
    if ((u8) ((((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1DU) & 1) ^ 1) != 0) {
        this->unk6C = this->unk54;
    }
}

void KDSoundFlangedFader::Init(int arg0, float arg1, float arg2, float arg3, float arg4, float arg5) {
    RecalcVariables(arg0, arg1, arg2, arg3);
    this->unk6C = 0.0f;
    this->unk54 = 0.0f;
    ((KDSoundFader *) this)->Init(arg4, arg5);
    ((KDSoundFader *) &this->unk28)->Init(arg4, arg5);
}
