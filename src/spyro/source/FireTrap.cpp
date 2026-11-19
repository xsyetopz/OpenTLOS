#include "spyro/source/FireTrap.h"
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
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/CrashFirePS.h"
#include "spyro/source/Crate.h"
#include "spyro/source/DialogBox.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDPositionProperty.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/Level.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/SparksPS.h"
#include "spyro/source/TargetManager.h"
#include "spyro/source/Trap.h"
#include "common/Source/StdMath.h"
#include "spyro/source/PropFlags.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;

void FireTrap::Message(MKMessage *arg0) {
    s32 temp_r0_48;

    Trap::Message(arg0);
    temp_r0_48 = arg0->unk0;
    if (temp_r0_48 != 0xB5) {
        if (temp_r0_48 < 0xB5) {

        }
    } else {
        this->unkE0 = 0.0f;
    }
}

#if 0 // DRAFT: function call 'GetProp(HeroInterface *, void *, double)' does not match
void *FireTrap::Update() {
    s8 sp199;
    s8 sp198;
    s32 sp194;
    f32 sp190;
    s32 sp18C;
    s8 sp18A;
    s8 sp189;
    s8 sp188;
    f64 sp180;                                      /* compiler-managed */
    f64 sp178;                                      /* compiler-managed */
    FireTrap *sp174;
    s32 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    s32 sp14C;
    s32 sp148;
    f64 sp140;
    f64 sp138;
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
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f32 sp80;
    f64 sp78;
    f32 sp70;
    f64 sp68;
    f64 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f1_271;
    f64 temp_f0_132;
    f64 temp_f0_240;
    f64 temp_f0_254;
    f64 temp_f0_294;
    f64 temp_f0_97;
    f64 temp_f1_117;
    f64 temp_f1_126;
    f64 temp_f1_228;
    s32 temp_r3_79;
    void *temp_r3_125;
    void *temp_r3_226;
    void *temp_r4_114;
    void *temp_r5_286;
    void *temp_r5_89;

    GameProp::Update();
    temp_r3_79 = this->unk10;
    if ((temp_r3_79 & 0x20000) && (temp_r3_79 & 0x80000)) {
        if (this->unkE0 > 1.0f) {
            temp_r5_89 = this->unk8;
            sp128 = M2C_FIELD(temp_r5_89, f64 *, 0x30);
            sp130 = M2C_FIELD(temp_r5_89, f64 *, 0x38);
            temp_f0_97 = M2C_FIELD(&MKVector3::up, f64 *, 0) * 5.647722104e-315;
            sp78 = temp_f0_97;
            sp118 = temp_f0_97;
            sp80 = MKVector3::up.unk8 * 650.0f;
            sp120 = (f64) sp80;
            ((CrashFirePS *) gb.unk68)->Emit(*((MKVector3 *) &sp128), *((MKVector3 *) &sp118), 6.0f);
            temp_r4_114 = this->unk8;
            temp_f1_117 = M2C_FIELD(temp_r4_114, f64 *, 0x30);
            spF8 = temp_f1_117;
            sp100 = M2C_FIELD(temp_r4_114, f64 *, 0x38);
            temp_r3_125 = M2C_FIELD(gb.unk0->GetProp(temp_r4_114, temp_f1_117), void **, 8);
            temp_f1_126 = M2C_FIELD(temp_r3_125, f64 *, 0x30);
            sp108 = temp_f1_126;
            sp110 = M2C_FIELD(temp_r3_125, f64 *, 0x38);
            temp_f0_132 = temp_f1_126 - spF8;
            sp68 = temp_f0_132;
            sp138 = temp_f0_132;
            sp70 = (f32) sp110 - (f32) sp100;
            (*(f32 *) ((u8 *) &sp138 + 0x4)) = 0.0f;
            sp140 = (f64) sp70;
            if ((((f32) sp140 * (f32) sp140) + (((f32) sp138 * (f32) sp138) + (0.0f * 0.0f))) < 10000.0f) {
                sp14C = 0;
                sp8 = sp138 * 5.439686476e-315;
                sp10 = (f32) sp140 * 20.0f;
                spE8 = sp8;
                spF0 = (f64) sp10;
                sp148 = 7;
                sp170 = 1;
                sp174 = this;
                sp150 = sp8;
                sp158 = (f64) sp10;
                sp188 = 0;
                sp194 = 2;
                sp190 = 10.0f;
                sp189 = 0;
                sp18A = 1;
                sp18C = -1;
                sp160 = M2C_FIELD(&MKVector3::one, f64 *, 0);
                sp168 = M2C_FIELD(&MKVector3::one, f64 *, 8);
                sp198 = 0;
                if (this != NULL) {
                    ((MKProp *) &sp58)->GetPos();
                    sp178 = sp58;
                    sp180 = sp60;
                } else {
                    sp178 = 0.0f;
                    (*(f32 *) ((u8 *) &sp174 + 0x8)) = 0.0f;
                    sp180 = 0.0f;
                }
                sp199 = 0;
                gb.unk0->Message(&sp148);
            }
        }
        if ((this->unkE0 < 1.0f) && (MKRand_Int((int *) &gViewSeed, 0, 0xA) == 0)) {
            temp_r3_226 = this->unk8;
            sp48 = 0.0f;
            temp_f1_228 = M2C_FIELD(temp_r3_226, f64 *, 0x30);
            sp4C = 15.0f;
            sp50 = 0.0f;
            spB8 = (f64) sp48;
            spC8 = temp_f1_228;
            spC0 = (f64) sp50;
            spD0 = M2C_FIELD(temp_r3_226, f64 *, 0x38);
            temp_f0_240 = temp_f1_228 + spB8;
            sp38 = temp_f0_240;
            spD8 = temp_f0_240;
            sp40 = (f32) spD0 + (f32) spC0;
            spE0 = (f64) sp40;
            temp_f0_254 = M2C_FIELD(&MKVector3::up, f64 *, 0) * 5.60222949e-315;
            sp28 = temp_f0_254;
            spA8 = temp_f0_254;
            sp30 = MKVector3::up.unk8 * 300.0f;
            spB0 = (f64) sp30;
            ((SparksPS *) gb.unk84)->Emit(*((MKVector3 *) &spD8), *((MKVector3 *) &spA8), 5.0f);
        }
        temp_f1_271 = this->unkE0;
        if (((temp_f1_271 > 0.5f) && (temp_f1_271 < 1.0f)) || (MKRand_Int((int *) &gViewSeed, 0, 0xA) == 0)) {
            temp_r5_286 = this->unk8;
            sp98 = M2C_FIELD(temp_r5_286, f64 *, 0x30);
            spA0 = M2C_FIELD(temp_r5_286, f64 *, 0x38);
            temp_f0_294 = M2C_FIELD(&MKVector3::up, f64 *, 0) * 5.647722104e-315;
            sp18 = temp_f0_294;
            sp88 = temp_f0_294;
            sp20 = MKVector3::up.unk8 * 650.0f;
            sp90 = (f64) sp20;
            gb.EmitDust(*((MKVector3 *) &sp98), *((MKVector3 *) &sp88), 0.5f, 0.0f);
        }
        this->unkE0 += gUpdateTimeDelta;
    }
}
#endif

void FireTrap::Reset() {
    PropFlagsSet((unsigned int *) &this->unk10, 0x80000U);
    Trap::Reset();
    this->unkE0 = 0.0f;
    PropFlagsClear((unsigned int *) &this->unk10, 0x80000U);
}

#if 0 // DRAFT: illegal use of non-static member
void FireTrapDescriptor::Init() {
    TrapDescriptor::Init();
    this->unkC = 0x12;
}
#endif
