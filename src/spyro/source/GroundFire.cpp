#include "spyro/source/GroundFire.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMemoryCard.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/CameraData.h"
#include "spyro/source/CrashFirePS.h"
#include "spyro/source/GameData.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/KDFaderObject.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/Level.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDRandom.h"
#include <m2c_macros.h>

M2C_UNK free(MKHeap *);                             /* extern */
MKHeap *malloc(s32);                                /* extern */
extern s32 GS_SpyroFireBurnGroundLP;
extern s32 GS_SpyroFuryStepsBurnLP;
extern M2C_UNK gEmptyPtrListDL;
extern void **gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;

#if 0 // DRAFT: undefined identifier 'unk3C'
void GroundFire::Emit(const MKVector3 &arg0, float arg1, bool arg2) {
    KDSoundFader *temp_r31_22;
    MKHeap *temp_r6_16;
    s32 var_r0_40;

    temp_r6_16 = this->unk0;
    if ((KDSoundFader *) M2C_FIELD(temp_r6_16, KDSoundFader **, -4) != NULL) {
        this->unk0 = temp_r6_16 - 4;
        temp_r31_22 = M2C_FIELD(temp_r6_16, KDSoundFader **, -4);
        if (temp_r31_22 != NULL) {
            temp_r31_22->unk28 = M2C_FIELD(&arg0, f64 *, 0);
            M2C_FIELD(temp_r31_22, f64 *, 0x30) = (f64) M2C_FIELD(&arg0, f64 *, 8);
            temp_r31_22->unk40 = arg1;
            temp_r31_22->unk38 = arg1;
            temp_r31_22->unk3C = 0.0f;
            temp_r31_22->Init(0.5f, 0.25f);
            M2C_FIELD(temp_r31_22, s8 *, 0x48) = 1;
            var_r0_40 = GS_SpyroFireBurnGroundLP;
            if (arg2 != 0) {
                var_r0_40 = GS_SpyroFuryStepsBurnLP;
            }
            temp_r31_22->unk44 = var_r0_40;
        }
    }
}
#endif

#if 0 // DRAFT: type mismatch
void GroundFire::Deinit() {
    MKHeap *temp_r0_66;
    MKHeap *temp_r0_85;
    MKHeap *temp_r3_88;
    MKHeap *var_r31_62;
    MKHeap *var_r3_63;
    MKHeap *var_r4_61;
    u32 temp_r0_71;

    var_r4_61 = this->unk0;
    var_r31_62 = var_r4_61;
    var_r3_63 = var_r4_61;
loop_3:
    temp_r0_71 = M2C_FIELD(var_r3_63, u32 *, -4);
    var_r3_63 -= 4;
    if (temp_r0_71 != 0U) {
        temp_r0_66 = var_r3_63->unk0;
        if (temp_r0_66 < var_r31_62) {
            var_r31_62 = temp_r0_66;
        }
        goto loop_3;
    }
    if (var_r3_63 != &gEmptyPtrListDL) {
loop_9:
        temp_r0_85 = var_r4_61->unk0;
        if (temp_r0_85 != NULL) {
            if (temp_r0_85 < var_r31_62) {
                var_r31_62 = temp_r0_85;
            }
            var_r4_61 += 4;
            goto loop_9;
        }
        temp_r3_88 = var_r3_63->Current();
        if (temp_r3_88 != NULL) {
            ((MKHeap *) (temp_r3_88->Current()))->Free(var_r31_62, NULL, 0);
        } else {
            free(var_r31_62);
        }
    }
    this->unk0 = NULL;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void' to
void GroundFire::Update() {
    BreathHitMessage spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    MKVector3 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    s32 sp8;
    MKHeap *temp_r26_306;
    MKHeap *temp_r3_294;
    MKHeap *temp_r4_297;
    MKHeap *var_r28_137;
    MKProp *temp_r4_244;
    f32 temp_f1_198;
    f32 temp_f25_159;
    f32 temp_f2_199;
    f64 temp_f0_172;
    f64 temp_f0_184;

    var_r28_137 = this->unk0;
loop_8:
    if (var_r28_137 != NULL) {
        temp_r26_306 = var_r28_137->unk0;
        if (temp_r26_306 != NULL) {
            sp60 = -1.0f;
            sp50 = 1.0f;
            temp_f25_159 = 100.0f * (0.1f * M2C_BITWISE(f32, temp_r26_306->unk40));
            sp58 = -1.0f;
            sp5C = 0.0f;
            sp48 = 1.0f;
            sp4C = 0.0f;
            sp88 = (f64) sp58;
            sp90 = (f64) sp60;
            sp78 = (f64) sp48;
            sp80 = (f64) sp50;
            KDRand_Vector(sp98, *((MKVector3 *) &sp88));
            temp_f0_172 = sp98 * (f64) temp_f25_159;
            sp38 = temp_f0_172;
            spA8 = temp_f0_172;
            sp40 = sp98.unk8 * temp_f25_159;
            spB0 = (f64) sp40;
            temp_f0_184 = M2C_FIELD(temp_r26_306, f64 *, 0x28) + temp_f0_172;
            sp28 = temp_f0_184;
            spB8 = temp_f0_184;
            sp30 = M2C_FIELD(temp_r26_306, f32 *, 0x30) + (f32) spB0;
            spC0 = (f64) sp30;
            temp_f1_198 = 100.0f * MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f);
            temp_f2_199 = M2C_BITWISE(f32, temp_r26_306->unk40);
            sp20 = 0.0f;
            sp18 = 0.0f;
            sp1C = temp_f2_199 * temp_f1_198;
            sp70 = (f64) sp20;
            sp68 = (f64) sp18;
            sp10 = 2.0f * temp_f2_199;
            ((CrashFirePS *) (M2C_FIELD(&gb, CrashFirePS **, 0x68)))->Emit(*((MKVector3 *) &spB8), *((MKVector3 *) &sp68), sp10);
            sp8 = 1;
            ((KDSoundFader *) temp_r26_306)->Update(temp_r26_306->unk44, 1U, M2C_FIELD(temp_r26_306, u8 *, 0x48), NULL, (MKVector3 *) &temp_r26_306->unk28, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
            temp_r26_306->unk3C = M2C_BITWISE(f32, temp_r26_306->unk3C) - gUpdateTimeDelta;
            if (M2C_BITWISE(f32, temp_r26_306->unk3C) <= 0.0f) {
                spC8.unk4 = 0;
                temp_r4_244 = M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), MKProp *(**)(void **), 0xC)(M2C_FIELD(&gb, void ***, 0));
                sp8 = -1;
                spC8.Init(temp_r4_244, 1, 0, *(&GameData::gameData[0x70] + ((M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5) + 0x64)), 0, 0, 0, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
                spC8.unk10 = M2C_FIELD(temp_r26_306, f64 *, 0x28);
                spC8.unk18 = temp_r26_306->unk30;
                M2C_FIELD(*gMK, M2C_UNK (**)(void **, BreathHitMessage *, M2C_UNK, M2C_UNK, MKHeap **, M2C_UNK, f32), 0x94)(gMK, &spC8, 0, 0, &temp_r26_306->unk28, 1, 75.0f * M2C_BITWISE(f32, temp_r26_306->unk40));
                temp_r26_306->unk3C = 0.25f;
            }
            temp_r26_306->unk38 -= gUpdateTimeDelta;
            if (temp_r26_306->unk38 <= 0.25f) {
                M2C_FIELD(temp_r26_306, u8 *, 0x48) = 0U;
            }
            if (temp_r26_306->unk38 <= 0.0f) {
                KDSound_Stop((s32 *) temp_r26_306);
                temp_r3_294 = this->unk0;
                this->unk0 = (MKHeap *) &temp_r3_294->unk4;
                temp_r4_297 = temp_r3_294->unk0;
                temp_r3_294->unk0 = var_r28_137->unk0;
                var_r28_137->unk0 = temp_r4_297;
            }
            var_r28_137 += 4;
            goto loop_8;
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void GroundFire::Init(int arg0) {
    MKHeap *temp_r3_348;
    MKHeap *temp_r3_371;
    MKHeap *temp_r3_378;
    MKHeap *temp_r3_385;
    MKHeap *var_r3_358;
    MKHeap *var_r5_370;
    s32 var_ctr_374;

    if (arg0 == 0) {
        this->unk0 = &gEmptyPtrListDL + 4;
        return;
    }
    temp_r3_348 = MKHeap::Current();
    if (temp_r3_348 != NULL) {
        var_r3_358 = ((MKHeap *) (temp_r3_348->Current()))->Alloc(((arg0 + 2) * 4) + (arg0 * 0x50), NULL, 0);
    } else {
        var_r3_358 = malloc(((arg0 + 2) * 4) + (arg0 * 0x50));
    }
    this->unk0 = var_r3_358;
    var_r5_370 = this->unk0;
    temp_r3_371 = var_r5_370 + (arg0 * 0x50);
    this->unk0 = temp_r3_371;
    temp_r3_371->unk0 = NULL;
    var_ctr_374 = arg0;
    if (arg0 > 0) {
        do {
            temp_r3_378 = this->unk0;
            this->unk0 = (MKHeap *) &temp_r3_378->unk4;
            temp_r3_378->unk4 = (s32) var_r5_370;
            var_r5_370 += 0x50;
            var_ctr_374 -= 1;
        } while (var_ctr_374 != 0);
    }
    temp_r3_385 = this->unk0;
    this->unk0 = (MKHeap *) &temp_r3_385->unk4;
    temp_r3_385->unk4 = 0;
}
#endif
