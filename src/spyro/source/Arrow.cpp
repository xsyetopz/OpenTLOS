#include "spyro/source/Arrow.h"
#include "common/Source/Animation.h"
#include "common/Source/Font.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
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
#include "spyro/source/DialogBox.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDPositionProperty.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/Level.h"
#include "spyro/source/TargetManager.h"
#include "spyro/source/Trap.h"
#include "spyro/source/PropFlags.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;
extern GameGlobals gb;

void Arrow::Fire(const Matrix &arg0, float arg1, float arg2) {
    MKModel_SetWorldMatrix(this->unk4, arg0);
    this->unkE0 = arg1;
    this->unkE4 = 0.0f;
    this->unkE8 = arg2;
}

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void *Arrow::Update() {
    s8 sp119;
    s8 sp118;
    s32 sp114;
    f32 sp110;
    s32 sp10C;
    s8 sp10A;
    s8 sp109;
    s8 sp108;
    f64 sp100;                                      /* compiler-managed */
    f64 spF8;                                       /* compiler-managed */
    Arrow *spF4;
    s32 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    s32 spCC;
    s32 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f1_165;
    f32 temp_f29_132;
    f64 temp_f0_138;
    f64 temp_f0_148;
    f64 temp_f0_195;
    f64 temp_f1_180;
    f64 temp_f1_189;
    f64 temp_f30_133;
    s32 temp_r3_126;
    void *temp_r3_136;
    void *temp_r3_188;
    void *temp_r4_177;
    void *temp_r5_282;

    GameProp::Update();
    temp_r3_126 = this->unk10;
    if ((temp_r3_126 & 0x20000) && (temp_r3_126 & 0x80000)) {
        temp_f29_132 = gUpdateTimeDelta;
        temp_f30_133 = -this->unkE0;
        temp_r3_136 = MKModel_GetWorldMatrix(this->unk4) + 0x20;
        temp_f0_138 = M2C_FIELD(temp_r3_136, f64 *, 0) * temp_f30_133;
        sp48 = temp_f0_138;
        sp98 = temp_f0_138;
        sp50 = M2C_FIELD(temp_r3_136, f32 *, 8) * (f32) temp_f30_133;
        spA0 = (f64) sp50;
        temp_f0_148 = temp_f0_138 * (f64) temp_f29_132;
        sp38 = temp_f0_148;
        spA8 = temp_f0_148;
        sp40 = (f32) spA0 * temp_f29_132;
        spB0 = (f64) sp40;
        MKModel_SetPosition(this->unk4, *((MKVector3 *) &spA8));
        this->unkE4 += gUpdateTimeDelta;
        temp_f1_165 = this->unkE8;
        if (this->unkE4 >= temp_f1_165) {
            this->unkE4 = temp_f1_165;
            Disable();
        }
        temp_r4_177 = this->unk8;
        temp_f1_180 = M2C_FIELD(temp_r4_177, f64 *, 0x30);
        sp78 = temp_f1_180;
        sp80 = M2C_FIELD(temp_r4_177, f64 *, 0x38);
        temp_r3_188 = M2C_FIELD(gb.unk0->GetProp(temp_r4_177, temp_f1_180), void **, 8);
        temp_f1_189 = M2C_FIELD(temp_r3_188, f64 *, 0x30);
        sp88 = temp_f1_189;
        sp90 = M2C_FIELD(temp_r3_188, f64 *, 0x38);
        temp_f0_195 = temp_f1_189 - sp78;
        sp28 = temp_f0_195;
        spB8 = temp_f0_195;
        sp30 = (f32) sp90 - (f32) sp80;
        (*(f32 *) ((u8 *) &spB8 + 0x4)) = 0.0f;
        spC0 = (f64) sp30;
        if ((((f32) spC0 * (f32) spC0) + (((f32) spB8 * (f32) spB8) + (0.0f * 0.0f))) < 10000.0f) {
            spCC = 0;
            sp8 = spB8 * 5.439686476e-315;
            sp10 = (f32) spC0 * 20.0f;
            sp68 = sp8;
            sp70 = (f64) sp10;
            spC8 = 7;
            spF0 = 1;
            spF4 = this;
            spD0 = sp8;
            spD8 = (f64) sp10;
            sp108 = 0;
            sp114 = 2;
            sp110 = 10.0f;
            sp109 = 0;
            sp10A = 1;
            sp10C = -1;
            spE0 = M2C_FIELD(&MKVector3::one, f64 *, 0);
            spE8 = M2C_FIELD(&MKVector3::one, f64 *, 8);
            sp118 = 0;
            if (this != NULL) {
                ((MKProp *) &sp18)->GetPos();
                spF8 = sp18;
                sp100 = sp20;
            } else {
                spF8 = 0.0f;
                (*(f32 *) ((u8 *) &spF4 + 0x8)) = 0.0f;
                sp100 = 0.0f;
            }
            sp119 = 0;
            gb.unk0->Message(&spC8);
            Disable();
        }
        temp_r5_282 = this->unk8;
        sp58 = M2C_FIELD(temp_r5_282, f64 *, 0x30);
        sp60 = M2C_FIELD(temp_r5_282, f64 *, 0x38);
        gb.EmitDust(*((MKVector3 *) &sp58), MKVector3::zero, 0.5f, 0.0f);
    }
}
#endif

void Arrow::Reset() {
    PropFlagsSet((unsigned int *) &this->unk10, 0x80000U);
    Trap::Reset();
}

void ArrowDescriptor::Init() {
    TrapDescriptor::Init();
    this->unkC = 0x12;
}
