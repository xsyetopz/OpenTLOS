#include "spyro/source/PitCover.h"
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
#include "spyro/source/Crate.h"
#include "spyro/source/DialogBox.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FallingLeaves.h"
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
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/TargetManager.h"
#include "common/Source/StdMath.h"
#include "common/Source/Str.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

extern s32 GS_PitTrapFall;
extern s32 gViewSeed;
extern GameGlobals gb;

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void PitCover::Message(MKMessage *arg0) {
    MKVector3 sp180;
    MKVector3 sp170;
    MKVector3 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    MKVector3 sp100;
    MKVector3 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    MKVector3 spB0;
    MKVector3 spA0;
    f64 sp98;
    f64 sp90;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    s32 spC;
    f32 sp8;
    f32 temp_f1_172;
    f32 temp_f1_230;
    f64 temp_f0_139;
    f64 temp_f0_151;
    f64 temp_f0_203;
    f64 temp_f0_215;
    f64 temp_f2_84;
    s32 temp_r0_55;
    s32 var_r30_121;

    temp_r0_55 = arg0->unk0;
    if (temp_r0_55 != 0xB5) {
        if (temp_r0_55 < 0xB5) {
            if (temp_r0_55 != 0x63) {
                goto block_7;
            }
            goto block_4;
        }
        goto block_7;
    }
block_4:
    if ((u8) this->unk70.unk4 != 0) {
        Disable();
        MKModel_CalculateRefPointWorldPosition(this->unk4, this->unk90, &sp180);
        MKModel_CalculateRefPointWorldPosition(this->unk4, this->unk94, &sp170);
        MKModel_CalculateRefPointWorldPosition(this->unk4, this->unk9C, &sp160);
        temp_f2_84 = M2C_BITWISE(f64, sp180);
        sp60 = M2C_BITWISE(f64, sp170) - temp_f2_84;
        sp140 = sp60;
        sp68 = sp170.unk8 - sp180.unk8;
        sp170 = sp60;
        sp148 = (f64) sp68;
        sp170.unk8 = (f64) sp68;
        sp50 = M2C_BITWISE(f64, sp160) - temp_f2_84;
        sp160 = sp50;
        sp58 = sp160.unk8 - sp180.unk8;
        sp130 = sp50;
        sp160.unk8 = (f64) sp58;
        sp138 = (f64) sp58;
        KDSound_Play3d(GS_PitTrapFall, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
        var_r30_121 = 0;
        do {
            __ml(MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f), spF0);
            __ml(MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f), sp100);
            temp_f0_139 = M2C_BITWISE(f64, sp180) + M2C_BITWISE(f64, sp100);
            sp20 = temp_f0_139;
            sp110 = temp_f0_139;
            sp28 = sp180.unk8 + sp100.unk8;
            sp118 = (f64) sp28;
            temp_f0_151 = sp110 + M2C_BITWISE(f64, spF0);
            sp40 = temp_f0_151;
            sp120 = temp_f0_151;
            sp150 = temp_f0_151;
            sp48 = (f32) sp118 + spF0.unk8;
            sp128 = (f64) sp48;
            sp158 = (f64) sp48;
            spC = MKRand_Int((int *) &gViewSeed, 0, 2);
            temp_f1_172 = 300.0f * MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f);
            sp88 = 0.0f;
            sp80 = 0.0f;
            sp84 = temp_f1_172;
            spE8 = (f64) sp88;
            spE0 = (f64) sp80;
            ((FallingLeaves *) gb.unk234)->Emit(*((MKVector3 *) &sp150), *((MKVector3 *) &spE0), 10.0f, spC, 1U);
            __ml(MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f), spA0);
            __ml(MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f), spB0);
            temp_f0_203 = M2C_BITWISE(f64, sp180) + M2C_BITWISE(f64, spB0);
            sp10 = temp_f0_203;
            spC0 = temp_f0_203;
            sp18 = sp180.unk8 + spB0.unk8;
            spC8 = (f64) sp18;
            temp_f0_215 = spC0 + M2C_BITWISE(f64, spA0);
            sp30 = temp_f0_215;
            spD0 = temp_f0_215;
            sp150 = temp_f0_215;
            sp38 = (f32) spC8 + spA0.unk8;
            spD8 = (f64) sp38;
            sp158 = (f64) sp38;
            temp_f1_230 = MKRand_Float((int *) &gViewSeed, 2.0f, 3.0f);
            sp78 = 0.0f;
            sp8 = temp_f1_230;
            sp70 = 0.0f;
            sp74 = 0.0f;
            sp98 = (f64) sp78;
            sp90 = (f64) sp70;
            gb.EmitDust(*((MKVector3 *) &sp150), *((MKVector3 *) &sp90), sp8, 0.0f);
            var_r30_121 += 1;
        } while (var_r30_121 < 0x1E);
block_7:
        KDProp::Message(arg0);
    }
}
#endif

#if 0 // DRAFT: function call 'Tools_GetMatchingRefPointIndex(MKModel *, signed char *)'
void PitCover::LoadDone() {
    s32 temp_r0_286;
    s32 var_r29_274;
    s32 var_r31_276;
    u16 temp_r3_284;
    void *temp_r3_292;

    KDProp::LoadDone();
    var_r29_274 = 0;
    var_r31_276 = 0;
    do {
        temp_r3_284 = Tools_GetMatchingRefPointIndex(this->unk4, Str_Printf("r_fxemit%d", var_r29_274));
        var_r29_274 += 1;
        temp_r0_286 = var_r31_276 + 0x90;
        var_r31_276 += 4;
        *(this + temp_r0_286) = (s32) temp_r3_284;
    } while (var_r29_274 < 4);
    temp_r3_292 = this->unk0;
    M2C_FIELD(temp_r3_292, s32 *, 0xC) = (s32) (M2C_FIELD(temp_r3_292, s32 *, 0xC) | 0x10);
}
#endif
