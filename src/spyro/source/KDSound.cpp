#include "spyro/source/KDSound.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKStringCache.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
#include "spyro/source/CustomMaterialUpdater.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/KDFaderObject.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/Level.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_enums.h"
#include "dolphin/os.h"
#include "common/Source/FileSys.h"
#include "common/Source/StdMath.h"
#include "common/Source/Str.h"
#include "common/gc/Sound_GC.h"
#include "spyro/source/GameLanguage.h"
#include "spyro/source/Music.h"
#include <m2c_macros.h>

M2C_UNK free(MKHeap *);                             /* extern */
MKHeap *malloc(s32);                                /* extern */
s32 stricmp(s8 *, s8 *, M2C_UNK *);                 /* extern */
extern s32 GS_SlowMoSound;
extern u8 bMusicDucked;
extern u8 bSplitScreen;
extern M2C_UNK gEmptyPtrListDL;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;
extern SoundEventInstance **instanceCache;
extern s32 instanceCacheCount;
static M2C_UNK soundDuckData;
#if 0 // DRAFT: identifier 'gsData' redeclared
static u32 gsData[0xB];
#endif
static KDSoundData kdsData;
#if 0 // DRAFT: illegal use of incomplete struct/union/class
static struct _struct_soundPlayFollowArray_0x8 soundPlayFollowArray[0xF];
#endif
static s32 noSoundID = -0x63;
u8 firstInvalidSoundID__15GlobalSoundData[4] = { 0xFF, 0xFF, 0xFF, 0xFF };
u8 lastInvalidSoundID__15GlobalSoundData[4] = { 0xFF, 0xFF, 0xFF, 0xFF };

u8 KDSound_SoundDucking_IsPaused() {
    return M2C_FIELD(&soundDuckData, u8 *, 0x1D) == 0;
}

s32 KDSound_SoundDucking_GetState() {
    return M2C_FIELD(&soundDuckData, s32 *, 0x18);
}

f32 KDSound_SoundDucking_ForceDuck(SoundEventInstance **arg0) {
    SoundEventInstance *temp_r5_85;
    f32 temp_f1_103;
    f32 temp_f1_113;
    f32 temp_f1_90;
    f32 var_f1_120;
    f32 var_f30_98;
    f32 var_f31_53;
    s32 temp_r3_86;

    if (((s32) M2C_FIELD(&soundDuckData, s32 *, 0x18) == 0) || ((u8) M2C_FIELD(&soundDuckData, u8 *, 0x1D) == 0)) {
        return 1.0f;
    }
    var_f31_53 = 1.0f;
    switch ((s32) M2C_FIELD(&soundDuckData, s32 *, 0x18)) { /* switch 1; irregular */
    case 1:                                         /* switch 1 */
        var_f31_53 = ((M2C_FIELD(&soundDuckData, f32 *, 0x14) - 1.0f) * (M2C_FIELD(&soundDuckData, f32 *, 0) * M2C_FIELD(&soundDuckData, f32 *, 0xC))) + 1.0f;
        break;
    case 2:                                         /* switch 1 */
        var_f31_53 = M2C_FIELD(&soundDuckData, f32 *, 0x14);
        break;
    case 3:                                         /* switch 1 */
        var_f31_53 = ((1.0f - M2C_FIELD(&soundDuckData, f32 *, 0x14)) * (M2C_FIELD(&soundDuckData, f32 *, 0) * M2C_FIELD(&soundDuckData, f32 *, 0x10))) + M2C_FIELD(&soundDuckData, f32 *, 0x14);
        if (var_f31_53 >= 0.99f) {
            var_f31_53 = 1.0f;
        }
        break;
    }
    if ((arg0 == NULL) || (temp_r5_85 = *arg0, temp_r3_86 = temp_r5_85->unk0, ((temp_r3_86 == 0) != 0)) || (temp_f1_90 = temp_r5_85->unk8, ((temp_f1_90 == 0.0f) != 0))) {
        return var_f31_53;
    }
    var_f30_98 = temp_f1_90 * var_f31_53;
    switch ((s32) M2C_FIELD(&soundDuckData, s32 *, 0x18)) { /* switch 2; irregular */
    case 1:                                         /* switch 2 */
    case 2:                                         /* switch 2 */
        temp_f1_103 = KDSound_GetVolume(temp_r3_86);
        if (var_f30_98 < temp_f1_103) {

        } else {
            var_f30_98 = temp_f1_103;
        }
        break;
    case 3:                                         /* switch 2 */
        temp_f1_113 = KDSound_GetVolume(temp_r3_86);
        if (var_f30_98 > temp_f1_113) {

        } else {
            var_f30_98 = temp_f1_113;
        }
        break;
    }
    var_f1_120 = 1.0f;
    if (var_f30_98 < var_f1_120) {
        var_f1_120 = var_f30_98;
    }
    if (var_f1_120 > 0.0f) {

    } else {
        var_f1_120 = 0.0f;
    }
    KDSound_SetVolume((*arg0)->unk0, var_f1_120);
    return var_f31_53;
}

s32 KDSound_SoundDucking_UnDuck() {
    if (((s32) M2C_FIELD(&soundDuckData, s32 *, 0x18) == 3) || ((s32) M2C_FIELD(&soundDuckData, s32 *, 0x18) == 0) || ((u8) M2C_FIELD(&soundDuckData, u8 *, 0x1D) == 0)) {
        return 0;
    }
    if ((s32) M2C_FIELD(&soundDuckData, s32 *, 0x18) == 2) {
        M2C_FIELD(&soundDuckData, f32 *, 0) = 0.0f;
    } else if ((s32) M2C_FIELD(&soundDuckData, s32 *, 0x18) == 1) {
        M2C_FIELD(&soundDuckData, f32 *, 0) = (f32) (M2C_FIELD(&soundDuckData, f32 *, 8) * (M2C_FIELD(&soundDuckData, f32 *, 0) / M2C_FIELD(&soundDuckData, f32 *, 4)));
    }
    M2C_FIELD(&soundDuckData, s32 *, 0x18) = 3;
    return 1;
}

s32 KDSound_SoundDucking_Duck() {
    if (((s32) M2C_FIELD(&soundDuckData, s32 *, 0x18) == 1) || ((s32) M2C_FIELD(&soundDuckData, s32 *, 0x18) == 2) || ((u8) M2C_FIELD(&soundDuckData, u8 *, 0x1D) == 0)) {
        return 0;
    }
    if ((s32) M2C_FIELD(&soundDuckData, s32 *, 0x18) == 0) {
        M2C_FIELD(&soundDuckData, f32 *, 0) = 0.0f;
    } else if ((s32) M2C_FIELD(&soundDuckData, s32 *, 0x18) == 3) {
        M2C_FIELD(&soundDuckData, f32 *, 0) = (f32) (M2C_FIELD(&soundDuckData, f32 *, 4) * (M2C_FIELD(&soundDuckData, f32 *, 0) / M2C_FIELD(&soundDuckData, f32 *, 8)));
    }
    M2C_FIELD(&soundDuckData, s32 *, 0x18) = 1;
    return 1;
}

#if 0 // DRAFT: illegal use of keyword
void KDSound_SoundDucking_Update() {
    SoundEventInstance **var_r30_252;
    SoundEventInstance *temp_r3_264;

    if (((u8) M2C_FIELD(&soundDuckData, u8 *, 0x1D) != 0) && ((s32) M2C_FIELD(&soundDuckData, s32 *, 0x18) != 0) && (((s32) M2C_FIELD(&soundDuckData, s32 *, 0x18) != 2) || ((u8) M2C_FIELD(&soundDuckData, u8 *, 0x1C) != 0))) {
        if ((u8) M2C_FIELD(&gb, u8 *, 0x395) != 0) {
            return;
        }
        var_r30_252 = instanceCache;
loop_10:
        temp_r3_264 = *var_r30_252;
        if (temp_r3_264 != NULL) {
            if (Sound_IsVoicePlaying(temp_r3_264->unk0) != 0) {
                KDSound_SoundDucking_ForceDuck(var_r30_252);
            }
            var_r30_252 += 4;
            goto loop_10;
        }
        if (((s32) M2C_FIELD(&soundDuckData, s32 *, 0x18) == 1) || ((s32) M2C_FIELD(&soundDuckData, s32 *, 0x18) == 3)) {
            M2C_FIELD(&soundDuckData, f32 *, 0) = (f32) (M2C_FIELD(&soundDuckData, f32 *, 0) + gUpdateTimeDelta);
        }
        switch ((s32) M2C_FIELD(&soundDuckData, s32 *, 0x18)) { /* irregular */
        case 1:
            if (M2C_FIELD(&soundDuckData, f32 *, 0) >= M2C_FIELD(&soundDuckData, f32 *, 4)) {
                M2C_FIELD(&soundDuckData, s32 *, 0x18) = 2;
                return;
            }
            break;
        case 3:
            if (M2C_FIELD(&soundDuckData, f32 *, 0) >= M2C_FIELD(&soundDuckData, f32 *, 8)) {
                M2C_FIELD(&soundDuckData, s32 *, 0x18) = 0;
            }
            break;
        }
    } else {
    case 2:
    }
}
#endif

void KDSound_SoundDucking_Deinit() {
    M2C_FIELD(&soundDuckData, f32 *, 0) = 0.0f;
    M2C_FIELD(&soundDuckData, s8 *, 0x1D) = 0;
    M2C_FIELD(&soundDuckData, s32 *, 0x18) = 0;
}

void KDSound_SoundDucking_Init(float arg0, float arg1, float arg2, bool arg3) {
    f32 var_f1_0;
    f32 var_f2_0;
    f32 var_f3_0;

    var_f1_0 = arg0;
    var_f2_0 = arg1;
    var_f3_0 = arg2;
    M2C_FIELD(&soundDuckData, f32 *, 0) = 0.0f;
    M2C_FIELD(&soundDuckData, s8 *, 0x1D) = 1;
    M2C_FIELD(&soundDuckData, s32 *, 0x18) = 0;
    if (var_f1_0 < 1.0f) {

    } else {
        var_f1_0 = 1.0f;
    }
    if (var_f1_0 > 0.0f) {

    } else {
        var_f1_0 = 0.0f;
    }
    M2C_FIELD(&soundDuckData, f32 *, 0x14) = var_f1_0;
    if (var_f2_0 > 0.001f) {

    } else {
        var_f2_0 = 0.001f;
    }
    M2C_FIELD(&soundDuckData, f32 *, 4) = var_f2_0;
    M2C_FIELD(&soundDuckData, u8 *, 0x1C) = arg3;
    if (var_f3_0 > 0.001f) {

    } else {
        var_f3_0 = 0.001f;
    }
    M2C_FIELD(&soundDuckData, f32 *, 8) = var_f3_0;
    M2C_FIELD(&soundDuckData, f32 *, 0xC) = (f32) (1.0f / M2C_FIELD(&soundDuckData, f32 *, 4));
    M2C_FIELD(&soundDuckData, f32 *, 0x10) = (f32) (1.0f / (f32) var_f3_0);
}

#if 0 // DRAFT: function call 'Sound_GetID(signed char *)' does not match
s32 SoundMaterial::Play(const MKVector3 *arg0, SoundEvent *arg1, int arg2, float *arg3) {
    f32 temp_f1_515;
    f32 temp_f1_524;
    f32 temp_f1_567;
    f32 temp_f1_576;
    f32 var_f30_401;
    f32 var_f31_400;
    s32 temp_r3_449;
    s32 temp_r3_484;
    s32 temp_r3_550;
    s32 temp_r4_437;
    s32 temp_r4_472;
    s32 temp_r4_538;
    s32 var_r24_512;
    s32 var_r25_427;
    s32 var_r29_405;
    s32 var_r31_426;
    s8 *temp_r3_433;
    s8 *temp_r3_469;
    s8 *temp_r3_535;
    void *temp_r24_431;
    void *temp_r25_468;
    void *temp_r25_534;

    var_f31_400 = 1.0f;
    var_f30_401 = 0.0f;
    var_r29_405 = arg2;
    if (arg3 != NULL) {
        *arg3 = 1.0f;
    }
    if (var_r29_405 <= -1) {
        var_r29_405 = (s32) this->unkC;
    }
    if (((u8) this->unkD != 0) && (M2C_FIELD(this->unk10, f32 *, 4) != 1.0f)) {
        var_f31_400 = MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f);
    }
    var_r31_426 = 0;
    var_r25_427 = 0;
loop_46:
    if (var_r31_426 >= (s32) this->unkD) {
        return 0;
    }
    temp_r24_431 = ((u8 *) this->unk10) + var_r25_427;
    temp_r3_433 = M2C_FIELD(temp_r24_431, s8 **, 0);
    var_f30_401 += M2C_FIELD(temp_r24_431, f32 *, 4);
    if ((temp_r3_433 != NULL) && ((temp_r4_437 = M2C_FIELD(temp_r24_431, s32 *, 8), ((temp_r4_437 == 0) != 0)) || ((temp_r4_437 >= (s32) *GlobalSoundData::firstInvalidSoundID) && (temp_r4_437 <= (s32) *GlobalSoundData::lastInvalidSoundID)))) {
        M2C_FIELD(temp_r24_431, s32 *, 8) = Sound_GetID(temp_r3_433);
        temp_r3_449 = M2C_FIELD(temp_r24_431, s32 *, 8);
        if ((temp_r3_449 >= (s32) *GlobalSoundData::firstInvalidSoundID) && (temp_r3_449 <= (s32) *GlobalSoundData::lastInvalidSoundID)) {
            M2C_FIELD(temp_r24_431, s32 *, 8) = 0;
        }
    }
    if (((s32) M2C_FIELD(temp_r24_431, s32 *, 8) > 0) && (var_f31_400 <= var_f30_401)) {
        if (arg0 != NULL) {
            temp_r25_468 = ((u8 *) this->unk10) + var_r25_427;
            temp_r3_469 = M2C_FIELD(temp_r25_468, s8 **, 0);
            if ((temp_r3_469 != NULL) && ((temp_r4_472 = M2C_FIELD(temp_r25_468, s32 *, 8), ((temp_r4_472 == 0) != 0)) || ((temp_r4_472 >= (s32) *GlobalSoundData::firstInvalidSoundID) && (temp_r4_472 <= (s32) *GlobalSoundData::lastInvalidSoundID)))) {
                M2C_FIELD(temp_r25_468, s32 *, 8) = Sound_GetID(temp_r3_469);
                temp_r3_484 = M2C_FIELD(temp_r25_468, s32 *, 8);
                if ((temp_r3_484 >= (s32) *GlobalSoundData::firstInvalidSoundID) && (temp_r3_484 <= (s32) *GlobalSoundData::lastInvalidSoundID)) {
                    M2C_FIELD(temp_r25_468, s32 *, 8) = 0;
                }
            }
            Sound_Play3d(M2C_FIELD(temp_r25_468, s32 *, 8), (u8) var_r29_405, arg0, (f32) arg1->unk4, (f32) arg1->unk8);
            var_r24_512 = M2C_ERROR(/* Read from unset register $r3 */);
            if ((var_r24_512 > 0) && ((temp_f1_515 = this->unk4, ((temp_f1_515 == 1.0f) == 0)) || (this->unk8 != 1.0f))) {
                temp_f1_524 = MKRand_Float((int *) &gViewSeed, temp_f1_515, this->unk8);
                Sound_SetPitch3d(var_r24_512, temp_f1_524);
                if (arg3 != NULL) {
                    *arg3 = temp_f1_524;
                }
            }
        } else {
            temp_r25_534 = ((u8 *) this->unk10) + var_r25_427;
            temp_r3_535 = M2C_FIELD(temp_r25_534, s8 **, 0);
            if ((temp_r3_535 != NULL) && ((temp_r4_538 = M2C_FIELD(temp_r25_534, s32 *, 8), ((temp_r4_538 == 0) != 0)) || ((temp_r4_538 >= (s32) *GlobalSoundData::firstInvalidSoundID) && (temp_r4_538 <= (s32) *GlobalSoundData::lastInvalidSoundID)))) {
                M2C_FIELD(temp_r25_534, s32 *, 8) = Sound_GetID(temp_r3_535);
                temp_r3_550 = M2C_FIELD(temp_r25_534, s32 *, 8);
                if ((temp_r3_550 >= (s32) *GlobalSoundData::firstInvalidSoundID) && (temp_r3_550 <= (s32) *GlobalSoundData::lastInvalidSoundID)) {
                    M2C_FIELD(temp_r25_534, s32 *, 8) = 0;
                }
            }
            Sound_PlayV(M2C_FIELD(temp_r25_534, s32 *, 8), (u8) var_r29_405, (u8) var_r29_405);
            var_r24_512 = M2C_ERROR(/* Read from unset register $r3 */);
            if ((var_r24_512 > 0) && ((temp_f1_567 = this->unk4, ((temp_f1_567 == 1.0f) == 0)) || (this->unk8 != 1.0f))) {
                temp_f1_576 = MKRand_Float((int *) &gViewSeed, temp_f1_567, this->unk8);
                Sound_SetPitch(var_r24_512, temp_f1_576);
                if (arg3 != NULL) {
                    *arg3 = temp_f1_576;
                }
            }
        }
        if (var_r24_512 < 0) {
            var_r24_512 = 0;
        }
        return var_r24_512;
    }
    var_r31_426 += 1;
    var_r25_427 += 0xC;
    goto loop_46;
}
#endif

#if 0 // DRAFT: declaration syntax error
s32 SoundEvent::Play(const MKVector3 *arg0, unsigned int arg1, int arg2) {
    f32 spC;
    SoundEventInstance *sp8;
    SoundEventInstance **temp_r3_675;
    SoundEventInstance **temp_r4_749;
    SoundEventInstance **var_r29_655;
    SoundEventInstance *temp_r3_688;
    SoundEventInstance *temp_r4_678;
    SoundEventInstance *temp_r4_751;
    SoundEventInstance *temp_r5_662;
    SoundMaterial *temp_r3_716;
    SoundMaterial *temp_r3_731;
    s32 temp_r0_703;
    s32 var_r30_624;
    s32 var_r31_623;
    s32 var_r4_710;
    u8 temp_r0_709;
    u8 var_ctr_711;
    u8 var_r26_814;
    u8 var_r4_757;
    void *temp_r22_630;
    void *temp_r4_663;
    void *var_r23_627;

    var_r31_623 = 0;
    var_r30_624 = 0;
    spC = 1.0f;
    var_r23_627 = this->unk20;
loop_5:
    if (var_r23_627 != &this->unk14) {
        temp_r22_630 = M2C_FIELD(var_r23_627, void **, 0xC);
        if (Sound_IsVoicePlaying(M2C_FIELD(var_r23_627, s32 *, 0)) != 0) {
            var_r30_624 += 1;
        } else {
            M2C_FIELD(M2C_FIELD(var_r23_627, void **, 0x10), void **, 0xC) = (void *) M2C_FIELD(var_r23_627, void **, 0xC);
            M2C_FIELD(M2C_FIELD(var_r23_627, void **, 0xC), void **, 0x10) = (void *) M2C_FIELD(var_r23_627, void **, 0x10);
            M2C_FIELD(var_r23_627, void **, 0xC) = NULL;
            M2C_FIELD(var_r23_627, void **, 0x10) = NULL;
        }
        var_r23_627 = temp_r22_630;
        goto loop_5;
    }
    if ((u32) M2C_FIELD(instanceCache, u32 *, -4) == 0U) {
        var_r29_655 = instanceCache;
loop_13:
        temp_r3_688 = *var_r29_655;
        if (temp_r3_688 != NULL) {
            if (Sound_IsVoicePlaying(temp_r3_688->unk0) == 0) {
                temp_r5_662 = *var_r29_655;
                temp_r4_663 = M2C_FIELD(temp_r5_662, void **, 0xC);
                if (temp_r4_663 != NULL) {
                    M2C_FIELD(M2C_FIELD(temp_r5_662, void **, 0x10), void **, 0xC) = temp_r4_663;
                    M2C_FIELD(M2C_FIELD(temp_r5_662, void **, 0xC), void **, 0x10) = (void *) M2C_FIELD(temp_r5_662, void **, 0x10);
                    M2C_FIELD(temp_r5_662, void **, 0xC) = NULL;
                    M2C_FIELD(temp_r5_662, void **, 0x10) = NULL;
                }
                temp_r3_675 = instanceCache;
                instanceCache = temp_r3_675 + 4;
                temp_r4_678 = M2C_FIELD(temp_r3_675, SoundEventInstance **, 0);
                M2C_FIELD(temp_r3_675, SoundEventInstance **, 0) = *var_r29_655;
                *var_r29_655 = temp_r4_678;
                instanceCacheCount -= 1;
            }
            var_r29_655 += 4;
            goto loop_13;
        }
    }
    if (((u32) M2C_FIELD(instanceCache, u32 *, -4) != 0U) && ((((s32) instanceCacheCount < 0x29) && !(((u8) this->unk2C >> 7U) & 1)) || (temp_r0_703 = this->unk28, ((temp_r0_703 == 0) != 0)) || (var_r30_624 < temp_r0_703))) {
        temp_r0_709 = this->unkC;
        var_r4_710 = 0;
        var_ctr_711 = temp_r0_709;
        if ((s32) temp_r0_709 > 0) {
loop_20:
            temp_r3_716 = this->unk10 + var_r4_710;
            if (arg1 & temp_r3_716->unk0) {
                var_r31_623 = temp_r3_716->Play(arg0, this, arg2, &spC);
            } else {
                var_r4_710 += 0x14;
                var_ctr_711 -= 1;
                if (var_ctr_711 != 0) {
                    goto loop_20;
                }
            }
        }
        temp_r3_731 = this->unk10;
        if ((temp_r3_731 != NULL) && (var_r31_623 == 0)) {
            var_r31_623 = temp_r3_731->Play(arg0, this, arg2, &spC);
        }
        if (var_r31_623 != 0) {
            temp_r4_749 = instanceCache - 4;
            instanceCache = temp_r4_749;
            temp_r4_751 = *temp_r4_749;
            sp8 = temp_r4_751;
            temp_r4_751->unk0 = var_r31_623;
            if (M2C_FIELD(&gb, f32 *, 0x2D0) != 1.0f) {
                var_r4_757 = 1;
            } else {
                var_r4_757 = 0;
            }
            if ((((u8) M2C_FIELD(&kdsData, u8 *, 0x150) >> 7U) & 1) && (var_r4_757 != 0) && (M2C_FIELD(&gb, f32 *, 0x2D0) != 1.0f)) {
                KDSound_SetPitch(var_r31_623, spC * M2C_FIELD(&gb, f32 *, 0x2D0));
            }
            sp8->unk4 = spC;
            if (arg2 == -1) {
                sp8->unk8 = (f32) this->unk10->unkC / 255.0f;
            } else {
                sp8->unk8 = (f32) arg2 / 255.0f;
            }
            if ((void *) M2C_FIELD(&gb, void **, 0xC) != NULL) {
                var_r26_814 = 0;
                if ((((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x78) != 0U) || ((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x84) != 0U)) && (((KDStateMachine<CutsceneSystem> *) (M2C_FIELD(&gb, void **, 0xC) + 0x24))->GetState() != 0)) {
                    var_r26_814 = 1;
                }
                if (var_r26_814 == 0) {
                    goto block_43;
                }
            } else {
block_43:
                if ((u8) M2C_FIELD(&gb, u8 *, 0x395) == 0) {
                    KDSound_SoundDucking_ForceDuck(&sp8);
                }
            }
            M2C_FIELD(sp8, u8 **, 0xC) = &this->unk14;
            M2C_FIELD(sp8, void **, 0x10) = (void *) this->unk24;
            M2C_FIELD(M2C_FIELD(sp8, void **, 0x10), SoundEventInstance **, 0xC) = sp8;
            M2C_FIELD(M2C_FIELD(sp8, u8 **, 0xC), SoundEventInstance **, 0x10) = sp8;
            instanceCacheCount += 1;
        }
    }
    return var_r31_623;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void SoundEvent::Reset() {
    s32 var_r4_863;
    s32 var_r5_868;
    s32 var_r8_862;
    s32 var_r9_867;
    void *temp_r7_872;
    void *temp_r7_882;

    var_r8_862 = 0;
    var_r4_863 = 0;
loop_7:
    if (var_r8_862 < (s32) this->unkC) {
        var_r9_867 = 0;
        var_r5_868 = 0;
loop_5:
        temp_r7_882 = var_r4_863 + this->unk10;
        if (var_r9_867 < (s32) M2C_FIELD(temp_r7_882, u8 *, 0xD)) {
            temp_r7_872 = M2C_FIELD(temp_r7_882, s32 *, 0x10) + var_r5_868;
            if ((u32) M2C_FIELD(temp_r7_872, u32 *, 0) != 0U) {
                M2C_FIELD(temp_r7_872, s32 *, 8) = 0;
            }
            var_r9_867 += 1;
            var_r5_868 += 0xC;
            goto loop_5;
        }
        var_r8_862 += 1;
        var_r4_863 += 0x14;
        goto loop_7;
    }
}
#endif

void *GlobalSoundData::GetSoundDataBlock(int arg0) {
    s32 temp_r0_898;

    temp_r0_898 = this->unk1C;
    this->unk1C = temp_r0_898 + arg0;
    return ((u8 *) this->unk10) + (temp_r0_898 * 0xC);
}

#if 0 // DRAFT: illegal implicit conversion from 'MKHeap *' to
SoundMaterial *GlobalSoundData::GetSoundMatBlock(int arg0) {
    s32 temp_r0_910;

    temp_r0_910 = this->unk18;
    this->unk18 = temp_r0_910 + arg0;
    return this->unkC + (temp_r0_910 * 0x14);
}
#endif

#if 0 // DRAFT: function call 'stricmp(const char[11], signed char *)' does not match
u8 GlobalSoundData::CountMaterials(MKIniLine *arg0) {
    MKIniLine *var_r30_927;
    u8 var_r29_928;

    var_r30_927 = arg0;
    var_r29_928 = 0;
loop_4:
    if ((var_r30_927 != NULL) && (var_r30_927->GetFieldName() != NULL) && (stricmp("soundevent", var_r30_927->GetFieldName()) != 0)) {
        if (stricmp("material", var_r30_927->GetFieldName()) == 0) {
            var_r29_928 += 1;
        }
        var_r30_927 = var_r30_927->unkC->GetNextLine(var_r30_927);
        goto loop_4;
    }
    return var_r29_928;
}
#endif

#if 0 // DRAFT: function call 'stricmp(const char[6], signed char *)' does not match
MKIniLine *GlobalSoundData::ParseSound(SoundMaterial *arg0, MKIniLine *arg1) {
    s8 *sp8;
    MKIniLine *temp_r3_1017;
    MKIniLine *var_r30_978;
    void *temp_r31_1002;

    var_r30_978 = arg1;
loop_12:
    if ((var_r30_978 != NULL) && (var_r30_978->GetFieldName() != NULL)) {
        if ((stricmp("sound", var_r30_978->GetFieldName()) == 0) && (var_r30_978->AsString(0, &sp8) != 0)) {
            arg0->unkD += 1;
            temp_r31_1002 = GetSoundDataBlock(1);
            if ((void *) arg0->unk10 == NULL) {
                arg0->unk10 = temp_r31_1002;
            }
            M2C_FIELD(temp_r31_1002, s32 *, 8) = 0;
            M2C_FIELD(temp_r31_1002, MKStringCache **, 0) = this->unk20->Add(sp8);
            M2C_FIELD(temp_r31_1002, f32 *, 4) = 1.0f;
            temp_r3_1017 = var_r30_978->unkC->GetNextLine(var_r30_978);
            var_r30_978 = temp_r3_1017;
            if ((var_r30_978 != NULL) && (temp_r3_1017->GetFieldName() != NULL) && (stricmp("chance", var_r30_978->GetFieldName(), "Default") == 0)) {
                var_r30_978->AsFloat(0, ((u8 *) temp_r31_1002) + 4);
            } else if (var_r30_978 != NULL) {
                var_r30_978 = var_r30_978->unkC->GetPrevLine(var_r30_978);
            }
        } else {
            var_r30_978 = var_r30_978->unkC->GetNextLine(var_r30_978);
            goto loop_12;
        }
    }
    return var_r30_978;
}
#endif

#if 0 // DRAFT: function call 'stricmp(const char[11], signed char *, const char[8])' does
MKIniLine *GlobalSoundData::ParseSoundMaterial(SoundMaterial *arg0, MKIniLine *arg1, unsigned char arg2, float arg3, float arg4) {
    s32 sp14;
    f32 sp10;
    f32 spC;
    s32 sp8;
    MKIniLine *var_r29_1093;
    f32 temp_f0_1197;
    s32 var_r30_1080;
    u8 var_r31_1077;

    var_r31_1077 = arg2;
    var_r30_1080 = 0;
    sp14 = 0;
    sp10 = arg3;
    spC = arg4;
    if (arg1->AsInt(0, (int *) &sp14) != 0) {
        var_r30_1080 = sp14;
    }
    var_r29_1093 = arg1->unkC->GetNextLine(arg1);
loop_17:
    if (var_r29_1093 != NULL) {
        if (var_r29_1093->GetFieldName() != NULL) {
            if ((stricmp("SoundEvent", var_r29_1093->GetFieldName(), "Default") != 0) && (stricmp("material", var_r29_1093->GetFieldName(), "Default") != 0)) {
                if (stricmp("sound", var_r29_1093->GetFieldName(), "Default") == 0) {
                    var_r29_1093 = ParseSound(arg0, var_r29_1093);
                } else if (stricmp("minPitch", var_r29_1093->GetFieldName(), "Default") == 0) {
                    var_r29_1093->AsFloat(0, &sp10);
                } else if (stricmp("maxPitch", var_r29_1093->GetFieldName(), "Default") == 0) {
                    var_r29_1093->AsFloat(0, &spC);
                } else if (stricmp("volume", var_r29_1093->GetFieldName(), "Default") == 0) {
                    var_r29_1093->AsInt(0, (int *) &sp8);
                    var_r31_1077 = (u8) sp8;
                } else {
                    var_r29_1093->unkC->Warning("Unknown SoundMaterial field");
                }
                goto block_15;
            }
        } else {
block_15:
            if (var_r29_1093 != NULL) {
                var_r29_1093 = var_r29_1093->unkC->GetNextLine(var_r29_1093);
            }
            goto loop_17;
        }
    }
    temp_f0_1197 = sp10;
    if (temp_f0_1197 > spC) {
        sp10 = spC;
        spC = temp_f0_1197;
    }
    if (arg0 != NULL) {
        arg0->unkC = var_r31_1077;
        arg0->unk4 = sp10;
        arg0->unk8 = spC;
        arg0->unk0 = var_r30_1080;
    }
    return var_r29_1093;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
MKIniLine *GlobalSoundData::ParseSoundEvent(SoundEvent *arg0, MKIniLine *arg1) {
    f32 sp18;
    f32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    MKIniLine *var_r27_1259;
    MKStringCache *temp_r3_1240;
    SoundMaterial *var_r28_1248;
    s32 var_r23_1277;
    u8 *temp_r0_1244;
    u8 var_r25_1233;
    u8 var_r30_1249;

    var_r25_1233 = 0xFF;
    sp18 = 1.0f;
    sp14 = 1.0f;
    temp_r3_1240 = this->unk20->Add(arg1->GetString(0));
    sp10 = 0x3E8;
    temp_r0_1244 = &arg0->unk14;
    spC = 0;
    var_r28_1248 = NULL;
    var_r30_1249 = 0;
    arg0->unk28 = 0;
    arg0->unk2C &= ~0x80;
    arg0->unk20 = temp_r0_1244;
    arg0->unk24 = temp_r0_1244;
    var_r27_1259 = arg1->unkC->GetNextLine(arg1);
loop_27:
    if ((var_r27_1259 != NULL) && (var_r27_1259->GetFieldName() != NULL) && (stricmp("SoundEvent", var_r27_1259->GetFieldName()) != 0)) {
        if (stricmp("material", var_r27_1259->GetFieldName()) == 0) {
            var_r30_1249 = CountMaterials(var_r27_1259);
            if (var_r30_1249 != 0) {
                var_r23_1277 = 0;
                var_r28_1248 = GetSoundMatBlock((s32) var_r30_1249);
loop_5:
                if ((var_r27_1259 != NULL) && (var_r27_1259->GetFieldName() != NULL) && (stricmp("SoundEvent", var_r27_1259->GetFieldName()) != 0)) {
                    if (stricmp("material", var_r27_1259->GetFieldName()) != 0) {

                    } else {
                        var_r27_1259 = ParseSoundMaterial(var_r28_1248 + var_r23_1277, var_r27_1259, var_r25_1233, sp18, sp14);
                        var_r23_1277 += 0x14;
                        goto loop_5;
                    }
                }
            }
        } else {
            if (stricmp("minPitch", var_r27_1259->GetFieldName(), "Default") == 0) {
                var_r27_1259->AsFloat(0, &sp18);
            } else if (stricmp("maxPitch", var_r27_1259->GetFieldName(), "Default") == 0) {
                var_r27_1259->AsFloat(0, &sp14);
            } else if (stricmp("range", var_r27_1259->GetFieldName(), "Default") == 0) {
                var_r27_1259->AsInt(0, (int *) &sp10);
            } else if (stricmp("minRange", var_r27_1259->GetFieldName(), "Default") == 0) {
                var_r27_1259->AsInt(0, (int *) &spC);
            } else if (stricmp("volume", var_r27_1259->GetFieldName(), "Default") == 0) {
                var_r27_1259->AsInt(0, (int *) &sp8);
                var_r25_1233 = (u8) sp8;
            } else if (stricmp("Comment", var_r27_1259->GetFieldName(), "Default") != 0) {
                if (var_r27_1259->IsField("throttle") != 0) {
                    arg0->unk28 = var_r27_1259->GetInt(0);
                } else if (var_r27_1259->IsField("ForceThrottle") != 0) {
                    arg0->unk2C = (arg0->unk2C & ~0x80) | ((var_r27_1259->GetBool(0) << 7) & 0x80);
                } else {
                    var_r27_1259->unkC->Warning("Unknown SoundEvent field");
                }
            }
            var_r27_1259 = var_r27_1259->unkC->GetNextLine(var_r27_1259);
        }
        goto loop_27;
    }
    if (arg0 != NULL) {
        arg0->unk0 = (s32) temp_r3_1240;
        arg0->unk4 = sp10;
        arg0->unk8 = spC;
        arg0->unk10 = var_r28_1248;
        arg0->unkC = var_r30_1249;
    }
    return var_r27_1259;
}
#endif

#if 0 // DRAFT: function call 'stricmp(const char[6], signed char *, const char[8])' does
MKIniLine *GlobalSoundData::SkipSetupSection(MKIni *arg0) {
    MKIniLine *temp_r3_1485;
    MKIniLine *var_r31_1486;

    temp_r3_1485 = arg0->GotoLine("setup", NULL);
    var_r31_1486 = temp_r3_1485;
    if (stricmp("setup", temp_r3_1485->GetSectionName(), "Default") == 0) {
        var_r31_1486 = var_r31_1486->unkC->GetNextLine(var_r31_1486);
loop_4:
        if (var_r31_1486 != NULL) {
            if (var_r31_1486->GetSectionName() == NULL) {
                var_r31_1486 = var_r31_1486->unkC->GetNextLine(var_r31_1486);
                goto loop_4;
            }
        }
    }
    return var_r31_1486;
}
#endif

#if 0 // DRAFT: function call 'stricmp(const char[11], signed char *, const char[8])' does
void GlobalSoundData::ParseInSoundEvents(MKIni *arg0) {
    MKIniLine *var_r31_1531;

    var_r31_1531 = SkipSetupSection(arg0);
    this->unk4 = 0;
    this->unk14 = 0;
    this->unk18 = 0;
    this->unk1C = 0;
loop_13:
    if (var_r31_1531 != NULL) {
        if ((var_r31_1531->GetFieldName() != NULL) && (stricmp("GroupIndex", var_r31_1531->GetFieldName(), "Default") == 0) && ((s16) var_r31_1531->unk0 > 0)) {
            this->unk4 = var_r31_1531->GetInt(0);
        }
        if ((var_r31_1531->GetFieldName() != NULL) && (stricmp("SoundEvent", var_r31_1531->GetFieldName(), "Default") == 0)) {
            var_r31_1531 = ParseSoundEvent(this->unk8 + (this->unk14 * 0x30), var_r31_1531);
            *(this->unk0 + (this->unk4 * 4)) = this->unk8 + (this->unk14 * 0x30);
            this->unk14 += 1;
            this->unk4 += 1;
        }
        if ((var_r31_1531 != NULL) && ((var_r31_1531->GetFieldName() == NULL) || ((var_r31_1531->GetFieldName() != NULL) && (var_r31_1531->GetFieldName(), ((stricmp"SoundEvent" == 0) == 0))))) {
            var_r31_1531 = var_r31_1531->unkC->GetNextLine(var_r31_1531);
        }
        goto loop_13;
    }
}
#endif

#if 0 // DRAFT: function call 'stricmp(const char[11], signed char *, const char[8])' does
void GlobalSoundData::ParseAndBuildHeaps(MKIni *arg0) {
    s8 *sp8;
    MKHeap *var_r3_1763;
    MKHeap *var_r3_1779;
    MKHeap *var_r3_1795;
    MKHeap *var_r3_1811;
    MKIniLine *var_r29_1640;
    MKIniLine *var_r30_1638;
    s32 temp_r29_1755;
    s32 temp_r29_1771;
    s32 temp_r29_1787;
    s32 temp_r29_1803;

    var_r30_1638 = SkipSetupSection(arg0);
    sp8 = NULL;
    var_r29_1640 = var_r30_1638;
loop_12:
    if (var_r30_1638 != NULL) {
        if ((var_r30_1638->GetFieldName() != NULL) && (stricmp("GroupIndex", var_r30_1638->GetFieldName(), "Default") == 0)) {
            if ((s16) var_r30_1638->unk0 > 0) {
                this->unk4 = var_r30_1638->GetInt(0);
            }
        } else if ((var_r30_1638->GetFieldName() != NULL) && (stricmp("SoundEvent", var_r30_1638->GetFieldName(), "Default") == 0)) {
            this->unk20->Add(var_r30_1638->GetString(0));
            this->unk14 += 1;
            this->unk4 += 1;
        } else if ((var_r30_1638->GetFieldName() != NULL) && (stricmp("Material", var_r30_1638->GetFieldName(), "Default") == 0)) {
            this->unk18 += 1;
        }
        var_r30_1638 = var_r30_1638->unkC->GetNextLine(var_r30_1638);
        goto loop_12;
    }
loop_19:
    if (var_r29_1640 != NULL) {
        if ((var_r29_1640->GetFieldName() != NULL) && (stricmp("sound", var_r29_1640->GetFieldName(), "Default") == 0) && (var_r29_1640->AsString(0, &sp8) != 0)) {
            this->unk1C += 1;
            this->unk20->Add(sp8);
        }
        var_r29_1640 = var_r29_1640->unkC->GetNextLine(var_r29_1640);
        goto loop_19;
    }
    this->unk20->Optimise();
    this->unk20 = M2C_ERROR(/* Read from unset register $r3 */);
    temp_r29_1755 = this->unk4 * 4;
    if (MKHeap::Current() != NULL) {
        var_r3_1763 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r29_1755, NULL, 0);
    } else {
        var_r3_1763 = malloc(temp_r29_1755);
    }
    this->unk0 = var_r3_1763;
    temp_r29_1771 = this->unk14 * 0x30;
    if (MKHeap::Current() != NULL) {
        var_r3_1779 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r29_1771, NULL, 0);
    } else {
        var_r3_1779 = malloc(temp_r29_1771);
    }
    this->unk8 = var_r3_1779;
    temp_r29_1787 = this->unk18 * 0x14;
    if (MKHeap::Current() != NULL) {
        var_r3_1795 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r29_1787, NULL, 0);
    } else {
        var_r3_1795 = malloc(temp_r29_1787);
    }
    this->unkC = var_r3_1795;
    temp_r29_1803 = this->unk1C * 0xC;
    if (MKHeap::Current() != NULL) {
        var_r3_1811 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r29_1803, NULL, 0);
    } else {
        var_r3_1811 = malloc(temp_r29_1803);
    }
    this->unk10 = var_r3_1811;
    memset(this->unk0, 0, this->unk4 * 4);
    memset(this->unk8, 0, this->unk14 * 0x30);
    memset(this->unkC, 0, this->unk18 * 0x14);
    memset(this->unk10, 0, this->unk1C * 0xC);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKHeap *' to
void GlobalSoundData::Update() {
    SoundEvent *temp_r3_1869;
    s32 var_r28_1863;
    s32 var_r31_1865;
    u32 temp_r29_1859;
    u32 temp_r30_1864;

    if (this->unk28 > 0.0f) {
        temp_r29_1859 = OSGetTick();
        var_r28_1863 = this->unk24;
        temp_r30_1864 = (u32) (675000.0f * this->unk28);
        var_r31_1865 = var_r28_1863 * 0x30;
loop_2:
        var_r28_1863 += 1;
        temp_r3_1869 = this->unk8 + var_r31_1865;
        var_r31_1865 += 0x30;
        temp_r3_1869->Reset();
        if ((u32) (OSGetTick() - temp_r29_1859) < temp_r30_1864) {
            if (var_r28_1863 < (s32) this->unk14) {
                goto loop_2;
            }
        }
        if (var_r28_1863 < (s32) this->unk14) {
            this->unk24 = var_r28_1863;
            return;
        }
        this->unk28 = 0.0f;
    }
}
#endif

void GlobalSoundData::InvalidateSoundIDRange(int arg0, int arg1) {
    *GlobalSoundData::firstInvalidSoundID = arg0;
    *GlobalSoundData::lastInvalidSoundID = arg1;
}

void GlobalSoundData::ResolveSoundIDs(float arg0) {
    InvalidateSoundIDRange(-1, -1);
    this->unk24 = 0;
    this->unk28 = arg0;
    Update();
}

void GlobalSoundData::ResolveSoundIDs() {
    s32 var_r30_1944;
    s32 var_r31_1945;

    InvalidateSoundIDRange(-1, -1);
    if ((MKHeap *) this->unk8 != NULL) {
        var_r30_1944 = 0;
        var_r31_1945 = 0;
loop_3:
        if (var_r30_1944 < (s32) this->unk14) {
            ((SoundEvent *) (this->unk8 + var_r31_1945))->Reset();
            var_r30_1944 += 1;
            var_r31_1945 += 0x30;
            goto loop_3;
        }
    }
}

void GlobalSoundData::Deinit() {
    MKHeap *temp_r31_1973;
    MKHeap *temp_r31_1989;
    MKHeap *temp_r31_2005;
    MKStringCache *temp_r3_2037;
    void *temp_r31_2021;

    temp_r31_1973 = this->unk0;
    if (temp_r31_1973 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_1973, NULL, 0);
        } else {
            free(temp_r31_1973);
        }
    }
    temp_r31_1989 = this->unk8;
    if (temp_r31_1989 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_1989, NULL, 0);
        } else {
            free(temp_r31_1989);
        }
    }
    temp_r31_2005 = this->unkC;
    if (temp_r31_2005 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_2005, NULL, 0);
        } else {
            free(temp_r31_2005);
        }
    }
    temp_r31_2021 = this->unk10;
    if (temp_r31_2021 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_2021, NULL, 0);
        } else {
            free((MKHeap *) temp_r31_2021);
        }
    }
    temp_r3_2037 = this->unk20;
    if (temp_r3_2037 != NULL) {
        temp_r3_2037->Destroy();
    }
    this->unk0 = NULL;
    this->unk8 = NULL;
    this->unkC = NULL;
    this->unk10 = NULL;
    this->unk20 = NULL;
    this->unk4 = 0;
    this->unk14 = 0;
    this->unk18 = 0;
    this->unk1C = 0;
}

void GlobalSoundData::Init(const char *arg0, int arg1) {
    MKIni sp8;
    s32 temp_r31_2087;
    s32 var_r3_2092;

    this->unk0 = NULL;
    this->unk8 = NULL;
    this->unkC = NULL;
    this->unk10 = NULL;
    this->unk4 = 0;
    this->unk14 = 0;
    this->unk18 = 0;
    this->unk1C = 0;
    this->unk24 = 0;
    this->unk28 = 0.0f;
    MKHeap::ActivateTempMemOverride();
    temp_r31_2087 = sp8.Init(arg0, 0, NULL);
    MKHeap::DeactivateTempMemOverride();
    if ((u8) temp_r31_2087 != 0) {
        var_r3_2092 = 0x5800;
        if (arg1 > 0) {
            var_r3_2092 = arg1;
        }
        this->unk20 = ((MKStringCache *) var_r3_2092)->Create(M2C_ERROR(/* Read from unset register $r4 */));
        ParseAndBuildHeaps(&sp8);
        ParseInSoundEvents(&sp8);
        sp8.Deinit();
    }
}

void KDSoundData::Deinit() {
    if ((s32) kdsData.unk30 > 0) {
        Sound_UnloadBank(kdsData.unk30);
    }
    kdsData.unk30 = 0;
    this->unk34 = 0;
    this->unk38 = 0;
}

#if 0 // DRAFT: function call 'strcpy(signed char *, const char[1])' does not match
void KDSoundData::Init(bool arg0) {
    this->unk0 = 0;
    strcpy(&this->unk8, "");
    strcpy(&this->unk12, "");
    this->unk28 = 0;
    this->unk2C = 0;
    this->unk30 = 0;
    this->unk34 = 0;
    this->unk38 = 0;
    if ((arg0 != 0) && (MKArchive_Exists("SFX_common.gsb", NULL) != 0)) {
        kdsData.unk30 = Sound_LoadBank("SFX_common", 0U, -1);
    }
    this->unk3C = 1.0f;
    this->unk40 = 0.75f;
    this->unk44 = 1.0f;
    this->unk48 = 1.0f;
    this->unk4C = 1.0f;
    this->unk50 = 1.0f;
    this->unk54 = 0;
    this->unk58 = 0;
    this->unk78 = 0;
    strcpy(&this->unk7C, "");
    strcpy(&this->unk9C, "");
    this->unk5C.Reset();
    this->unk140 = 0;
    this->unk144 = 0;
    this->unkD0 = 0;
    strcpy(&this->unkD1, "");
    this->unkCC = 0.0f;
    this->unkF4 = 0.0f;
    this->unkF8 = 0.0f;
    this->unkFC = 0.0f;
    this->unk100 = 0.0f;
    this->unkBC = 0;
    this->unkC0 = 0;
    this->unkC4 = 0;
    this->unkC8 = 0;
    this->unkC9 = 0;
    this->unk104 = 0;
    this->unk105 = 0;
    strcpy(&this->unk106, "");
    this->unk128 = 0.0f;
    this->unk12C = 0.0f;
    this->unk130 = 0.0f;
    this->unk138 = 0;
    this->unk13C = 0;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void KDSoundFader::Update(int arg0, bool arg1, bool arg2, MKProp *arg3, const MKVector3 *arg4, unsigned int arg5, int arg6, bool arg7) {
    s32 sp8;
    f32 temp_f2_2276;
    s32 temp_r0_2381;
    s32 temp_r31_2268;
    s32 var_r29_2267;
    u8 var_r25_2263;
    u8 var_r5_2287;
    u8 var_r5_2397;

    var_r25_2263 = arg2;
    var_r29_2267 = arg6;
    temp_r31_2268 = this->unk0;
    if (temp_r31_2268 != 0) {
        if ((var_r25_2263 == 0) && ((s32) this->unkC.unk4 != 2) && (temp_f2_2276 = this->unk8, ((temp_f2_2276 > 0.0f) != 0))) {
            var_r25_2263 = 1;
            if (this->unk4 > 0.0f) {
                var_r5_2287 = 1;
            } else {
                var_r5_2287 = 0;
            }
            this->unkC.Fade((KDFaderObject::FadeMode) 5, 0.0f, temp_f2_2276, 0.0f, var_r5_2287);
        } else if ((var_r25_2263 != 0) && ((s32) this->unkC.unk4 == 2)) {
            this->unkC.Fade((KDFaderObject::FadeMode) 1, this->unk4, 0.0f, 0.0f, 1U);
        }
        if (var_r29_2267 == -1) {
            var_r29_2267 = (s32) M2C_FIELD(M2C_FIELD(*(*gsData + (arg0 * 4)), void **, 0x10), u8 *, 0xC);
        }
        if ((s32) this->unkC.unk4 != 0) {
            this->unkC.Update();
            var_r29_2267 = (s32) (u8) (s32) ((f32) var_r29_2267 * this->unkC.GetFadePercentage());
            if ((s32) this->unkC.unk4 == 2) {
                var_r25_2263 = 1;
            }
        }
        if ((KDSound_SoundDucking_GetState() != 0) && (KDSound_SoundDucking_IsPaused() == 0) && ((u8) M2C_FIELD(&gb, u8 *, 0x395) == 0)) {
            var_r29_2267 = (s32) (u8) (s32) ((f32) var_r29_2267 * KDSound_SoundDucking_ForceDuck(NULL));
        }
    } else {
        var_r29_2267 = 0;
    }
    sp8 = (s32) arg_sp8;
    ((KDSoundPlayer *) this)->Update(arg0, arg1, var_r25_2263, arg3, arg4, arg5, var_r29_2267, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    temp_r0_2381 = this->unk0;
    if ((temp_r31_2268 != temp_r0_2381) && ((temp_r31_2268 == 0) || (temp_r0_2381 != 0))) {
        if (this->unk8 > 0.0f) {
            var_r5_2397 = 1;
        } else {
            var_r5_2397 = 0;
        }
        this->unkC.Fade((KDFaderObject::FadeMode) 1, this->unk4, 0.0f, 0.0f, var_r5_2397);
    }
}
#endif

void KDSoundFader::Init(float arg0, float arg1) {
    this->unk0 = 0;
    this->unkC.Reset();
    this->unk4 = arg0;
    this->unk8 = arg1;
}

#if 0 // DRAFT: illegal implicit conversion from 'const MKVector3 *' to
void KDSoundPlayer::Update(int arg0, bool arg1, bool arg2, MKProp *arg3, const MKVector3 *arg4, unsigned int arg5, int arg6, bool arg7) {
    f64 sp20;
    f64 sp18;
    f64 sp10;
    f64 sp8;
    MKProp *var_r27_2450;
    MKVector3 *var_r28_2451;
    MKVector3 *var_r4_2494;
    MKVector3 *var_r5_2512;
    s32 temp_r4_2479;
    u8 var_r23_2462;
    u8 var_r26_2448;
    u8 var_r3_2470;
    void *temp_r3_2578;

    var_r26_2448 = arg1;
    var_r27_2450 = arg3;
    var_r28_2451 = arg4;
    if ((u8) bSplitScreen != 0) {
        var_r26_2448 = 0;
        var_r27_2450 = NULL;
        var_r28_2451 = NULL;
    }
    var_r23_2462 = 0;
    if ((var_r27_2450 != NULL) || (var_r28_2451 != NULL)) {
        var_r23_2462 = 1;
    }
    var_r3_2470 = 1;
    if ((var_r23_2462 != 0) && (arg_sp8 != 0)) {
        var_r3_2470 = KDS_IsSoundInRange(arg0, var_r27_2450, var_r28_2451);
    }
    temp_r4_2479 = this->unk0;
    if (temp_r4_2479 == 0) {
        if (var_r23_2462 != 0) {
            if ((arg2 != 0) && (var_r3_2470 != 0)) {
                if (arg_sp8 != 0) {
                    if (var_r27_2450 != NULL) {
                        var_r4_2494 = var_r27_2450->unk8 + 0x30;
                    } else {
                        var_r4_2494 = var_r28_2451;
                    }
                    this->unk0 = KDSound_Play3d(arg0, var_r4_2494, arg5, arg6, 0.0f, 0U);
                    return;
                }
                if (var_r27_2450 != NULL) {
                    var_r5_2512 = var_r27_2450->unk8 + 0x30;
                } else {
                    var_r5_2512 = var_r28_2451;
                }
                Sound_Play3d(arg0, (u8) arg6, var_r5_2512, 3000.0f, 0.0f);
                this->unk0 = M2C_ERROR(/* Read from unset register $r3 */);
            }
        } else if (arg2 != 0) {
            if (arg_sp8 != 0) {
                this->unk0 = KDSound_Play(arg0, arg5, arg6);
                return;
            }
            Sound_PlayV(arg0, (u8) arg6, (u8) arg6);
            this->unk0 = M2C_ERROR(/* Read from unset register $r3 */);
        }
    } else {
        if (arg2 == 0) {
            KDSound_Stop((int *) &this->unk0);
            return;
        }
        if ((var_r23_2462 != 0) && (var_r3_2470 == 0)) {
            KDSound_Stop((int *) &this->unk0);
            return;
        }
        if (Sound_IsVoicePlaying(temp_r4_2479) == 0) {
            this->unk0 = 0;
            return;
        }
        if (var_r23_2462 != 0) {
            if ((var_r26_2448 != 0) || (arg6 > -1)) {
                if (var_r28_2451 != NULL) {
                    sp18 = M2C_FIELD(var_r28_2451, f64 *, 0);
                    sp20 = M2C_FIELD(var_r28_2451, f64 *, 8);
                } else {
                    temp_r3_2578 = var_r27_2450->unk8;
                    sp18 = M2C_FIELD(temp_r3_2578, f64 *, 0x30);
                    sp20 = M2C_FIELD(temp_r3_2578, f64 *, 0x38);
                }
                sp8 = sp18;
                sp10 = sp20;
                Sound_Update3d(this->unk0, arg6, (MKVector3 *) &sp8);
            }
        } else if (arg6 > -1) {
            Sound_SetVolume(this->unk0, (u8) arg6, (u8) arg6);
        }
    }
}
#endif

void KDSoundPlayer::Message(MKMessage *arg0) {
    if ((s32) arg0->unk0 == -4) {
        KDSound_Stop((int *) &this->unk0);
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void KDS_FollowSndPosArrayShuffleDown(int arg0) {
    s32 temp_r0_2644;
    s32 var_ctr_2639;
    s32 var_r3_2638;
    s32 var_r6_2634;
    struct _struct_soundPlayFollowArray_0x8 *temp_r3_2658;
    void *temp_r5_2643;

    if (arg0 >= 0) {
        if (arg0 > 0xF) {
            return;
        }
        var_r6_2634 = arg0 + 1;
        var_r3_2638 = var_r6_2634 * 8;
        var_ctr_2639 = 0xF - var_r6_2634;
        if (var_r6_2634 < 0xF) {
loop_4:
            temp_r5_2643 = soundPlayFollowArray + var_r3_2638;
            temp_r0_2644 = M2C_FIELD(temp_r5_2643, s32 *, 0);
            if (temp_r0_2644 != -1) {
                M2C_FIELD(temp_r5_2643, s32 *, -8) = temp_r0_2644;
                var_r6_2634 += 1;
                var_r3_2638 += 8;
                M2C_FIELD(temp_r5_2643, s32 *, -4) = (s32) M2C_FIELD(temp_r5_2643, s32 *, 4);
                var_ctr_2639 -= 1;
                if (var_ctr_2639 != 0) {
                    goto loop_4;
                }
            }
        }
        temp_r3_2658 = &soundPlayFollowArray[var_r6_2634];
        M2C_FIELD(temp_r3_2658, s32 *, -8) = -1;
        M2C_FIELD(temp_r3_2658, s32 *, -4) = 0;
    }
}
#endif

#if 0 // DRAFT: pointer/array required
u8 KDS_FollowSndPosArraySndEventIsIn(int arg0, int &arg1) {
    s32 var_ctr_2673;
    s32 var_r5_2672;
    s32 var_r7_2671;

    var_r7_2671 = 0;
    var_r5_2672 = 0;
    var_ctr_2673 = 0xF;
loop_1:
    if (arg0 == (s32) *(soundPlayFollowArray + var_r5_2672)) {
        &arg1 = var_r7_2671;
        return 1U;
    }
    var_r7_2671 += 1;
    var_r5_2672 += 8;
    var_ctr_2673 -= 1;
    if (var_ctr_2673 == 0) {
        return 0U;
    }
    goto loop_1;
}
#endif

#if 0 // DRAFT: pointer/array required
s32 KDS_FollowSndPosArrayGetNextSlot() {
    s32 var_ctr_2698;
    s32 var_r4_2697;
    s32 var_r6_2696;

    var_r6_2696 = 0;
    var_r4_2697 = 0;
    var_ctr_2698 = 0xF;
loop_1:
    if ((s32) *(soundPlayFollowArray + var_r4_2697) == -1) {
        return var_r6_2696;
    }
    var_r6_2696 += 1;
    var_r4_2697 += 8;
    var_ctr_2698 -= 1;
    if (var_ctr_2698 == 0) {
        return -1;
    }
    goto loop_1;
}
#endif

#if 0 // DRAFT: function call 'KDS_FollowSndPosArraySndEventIsIn(int, long)' does not
void KDS_FollowSndPosArrayRemove(int arg0) {
    s32 sp8;

    if (KDS_FollowSndPosArraySndEventIsIn(arg0, sp8) != 0) {
        KDS_FollowSndPosArrayShuffleDown(sp8);
    }
}
#endif

#if 0 // DRAFT: pointer/array required
void KDS_FollowSndPosArrayAdd(int arg0, const MKVector3 *arg1) {
    s32 temp_r3_2740;

    temp_r3_2740 = KDS_FollowSndPosArrayGetNextSlot();
    if (temp_r3_2740 != -1) {
        soundPlayFollowArray[temp_r3_2740].unk0 = arg0;
        soundPlayFollowArray[temp_r3_2740].unk4 = arg1;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void KDS_FollowSndPosArrayInit() {
    s32 var_ctr_2766;
    s32 var_r3_2760;
    void *temp_r7_2768;

    var_r3_2760 = 0;
    var_ctr_2766 = 0xF;
    do {
        temp_r7_2768 = soundPlayFollowArray + var_r3_2760;
        var_r3_2760 += 8;
        M2C_FIELD(temp_r7_2768, s32 *, 0) = -1;
        M2C_FIELD(temp_r7_2768, s32 *, 4) = 0;
        var_ctr_2766 -= 1;
    } while (var_ctr_2766 != 0);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const MKVector3 *' to
u8 KDS_IsSoundInRange(int arg0, MKProp *arg1, const MKVector3 *arg2) {
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    MKVector3 *var_r5_0;
    f64 temp_f0_2792;
    f64 temp_f0_2822;
    f64 temp_f1_2815;
    void *temp_r4_2812;

    var_r5_0 = arg2;
    if (arg1 != NULL) {
        var_r5_0 = arg1->unk8 + 0x30;
    }
    if (var_r5_0 != NULL) {
        temp_f0_2792 = M2C_FIELD(var_r5_0, f64 *, 0) - M2C_FIELD(kdsData.unk140, f64 *, 0);
        sp18 = temp_f0_2792;
        sp48 = temp_f0_2792;
        sp20 = var_r5_0->unk8 - M2C_FIELD(kdsData.unk140, f32 *, 8);
        sp50 = (f64) sp20;
    } else {
        temp_r4_2812 = arg1->unk8;
        temp_f1_2815 = M2C_FIELD(temp_r4_2812, f64 *, 0x30);
        sp28 = temp_f1_2815;
        sp30 = M2C_FIELD(temp_r4_2812, f64 *, 0x38);
        temp_f0_2822 = temp_f1_2815 - M2C_FIELD(kdsData.unk140, f64 *, 0);
        sp8 = temp_f0_2822;
        sp38 = temp_f0_2822;
        sp10 = (f32) sp30 - M2C_FIELD(kdsData.unk140, f32 *, 8);
        sp40 = (f64) sp10;
    }
    return ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1DU) & 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk134'
void KDS_UpdateMusicFading() {
    f32 temp_f31_2977;
    f32 var_f1_2970;

    if (((s32) kdsData.unk54 > 0) && (Sound_IsVoicePlaying(kdsData.unk54) == 0)) {
        kdsData.unk54 = 0;
        KDSound_UnDuckMusic(kdsData.unk50);
        kdsData.unk58 = 4;
    }
    switch ((s32) kdsData.unk58) {                  /* irregular */
    case 1:
        if ((s32) kdsData.unk5C.unk4 == 0) {
            kdsData.unk58 = 0;
            return;
        }
block_27:
        kdsData.unk5C.Update();
        KDSound_ScaleMasterVolume(kdsData.unk5C.GetFadePercentage(), 2);
        return;
    case 2:
        if (((s32) kdsData.unk5C.unk4 == 2) || ((s32) kdsData.unk5C.unk4 == 1)) {
            kdsData.unk58 = 0;
            Sound_MusicPause(1U);
            return;
        }
        goto block_27;
    case 3:
        if (kdsData.unk5C.GetFadePercentage() == 0.0f) {
            Sound_MusicStop();
            if ((u32) kdsData.unk78 != 0U) {
                kdsData.unk58 = 1;
                Sound_MusicPlay((s8 *) kdsData.unk78, 1U, kdsData.unk134);
                kdsData.unk78 = 0;
                goto block_27;
            }
            kdsData.unk58 = 0;
            return;
        }
        goto block_27;
    case 4:
        if ((s32) kdsData.unk5C.unk4 == 0) {
            if ((s32) kdsData.unk5C.unk8 == 1) {
                bMusicDucked = 0;
                kdsData.unk4C = 1.0f;
            }
            kdsData.unk58 = 0;
            bMusicDucked = 0;
            return;
        }
        kdsData.unk5C.Update();
        var_f1_2970 = 0.0f;
        if (kdsData.unk40 > 0.0f) {
            temp_f31_2977 = kdsData.unk4C / kdsData.unk40;
            var_f1_2970 = ((1.0f - temp_f31_2977) * kdsData.unk5C.GetFadePercentage()) + temp_f31_2977;
        }
        KDSound_ScaleMasterVolume(var_f1_2970, 2);
        return;
    }
}
#endif

s32 KDSound_IsVoicePlaying(int arg0) {
    s32 var_r31_3014;

    var_r31_3014 = 0;
    if ((arg0 > 0) && (Sound_IsVoicePlaying(arg0) != 0)) {
        var_r31_3014 = 1;
    }
    return var_r31_3014;
}

void KDSound_ScaleMasterVolume(float arg0, int arg1) {
    f32 var_f0_3037;
    f32 var_f4_3049;

    if (arg1 & 1) {
        var_f0_3037 = arg0;
    } else {
        var_f0_3037 = kdsData.unk44;
    }
    kdsData.unk44 = var_f0_3037;
    if (arg1 & 2) {
        var_f4_3049 = arg0;
    } else {
        var_f4_3049 = kdsData.unk48;
    }
    kdsData.unk48 = var_f4_3049;
    Sound_SetMasterVolume(kdsData.unk3C * kdsData.unk44, kdsData.unk40 * (f32) var_f4_3049);
}

void KDSound_SetMasterMusicVolume(float arg0) {
    KDSound_SetMasterVolume(kdsData.unk3C, arg0);
}

void KDSound_SetMasterSoundVolume(float arg0) {
    KDSound_SetMasterVolume(arg0, kdsData.unk40);
}

void KDSound_SetMasterVolume(float arg0, float arg1) {
    f32 temp_f31_3121;

    kdsData.unk3C = arg0;
    kdsData.unk40 = arg1;
    Level::GetWorldInfo();
    M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 0x6C) = arg1;
    Level::GetWorldInfo();
    temp_f31_3121 = arg1 * M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 0x78);
    Level::GetWorldInfo();
    M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 0x74) = temp_f31_3121;
    kdsData.unk44 = 1.0f;
    kdsData.unk48 = 1.0f;
    Sound_SetMasterVolume(kdsData.unk3C, kdsData.unk40);
}

#if 0 // DRAFT: function call 'stricmp(const char *)' does not match
s32 KDSound_LoadLine(MKIniLine *arg0, const char *arg1, int *arg2) {
    s8 *sp8;

    if (arg0->GetFieldName() != NULL) {
        arg0->GetFieldName();
        if (stricmp(arg1) == 0) {
            sp8 = NULL;
            if (arg0->AsString(0, &sp8) != 0) {
                *arg2 = KDSound_ResolveSound(sp8, NULL);
                return 1;
            }
        }
    }
    return 0;
}
#endif

#if 0 // DRAFT: pointer/array required
s32 KDSound_ResolveSound(const char *arg0, int *arg1) {
    s32 var_r27_3200;
    s32 var_r27_3228;
    s32 var_r27_3255;
    s32 var_r29_3201;
    s32 var_r29_3230;
    s32 var_r31_3256;
    s8 **temp_r3_3205;
    s8 **temp_r3_3234;
    s8 **temp_r3_3260;

    if ((u32) M2C_FIELD(gsData, u32 *, 0) != 0U) {
        if (arg1 != NULL) {
            var_r27_3200 = *arg1;
            var_r29_3201 = var_r27_3200 * 4;
loop_7:
            if (var_r27_3200 >= (s32) gsData[1]) {
                if ((s32) *arg1 != 0) {
                    var_r27_3228 = 0;
                    var_r29_3230 = 0;
loop_14:
                    if (var_r27_3228 >= (s32) *arg1) {
                        goto block_22;
                    }
                    temp_r3_3234 = *(M2C_FIELD(gsData, u32 *, 0) + var_r29_3230);
                    if ((temp_r3_3234 != NULL) && (stricmp(*temp_r3_3234, arg0) == 0)) {
                        *arg1 = var_r27_3228 + 1;
                        return var_r27_3228;
                    }
                    var_r27_3228 += 1;
                    var_r29_3230 += 4;
                    goto loop_14;
                }
                goto block_22;
            }
            temp_r3_3205 = *(M2C_FIELD(gsData, u32 *, 0) + var_r29_3201);
            if ((temp_r3_3205 != NULL) && (stricmp(*temp_r3_3205, arg0) == 0)) {
                *arg1 = var_r27_3200 + 1;
                return var_r27_3200;
            }
            var_r27_3200 += 1;
            var_r29_3201 += 4;
            goto loop_7;
        }
        var_r27_3255 = 0;
        var_r31_3256 = 0;
loop_21:
        if (var_r27_3255 >= (s32) gsData[1]) {
            goto block_22;
        }
        temp_r3_3260 = *(M2C_FIELD(gsData, u32 *, 0) + var_r31_3256);
        if ((temp_r3_3260 != NULL) && (stricmp(*temp_r3_3260, arg0) == 0)) {
            return var_r27_3255;
        }
        var_r27_3255 += 1;
        var_r31_3256 += 4;
        goto loop_21;
    }
block_22:
    return 0;
}
#endif

void KDSound_SetMusicNotInterrupt(bool arg0) {
    kdsData.unkBC = (s8) arg0;
}

u8 KDSound_IsMusicPaused() {
    return (u8) kdsData.unkC9;
}

void KDSound_IsMusicPlaying() {
    Sound_MusicIsPlaying();
}

#if 0 // DRAFT: function call 'Sound_MusicPlay(signed char *, unsigned int, int)' does not
void KDSound_UnDuckMusic(float arg0) {
    if ((kdsData.unk4C < 1.0f) && ((s32) kdsData.unk54 <= 0)) {
        if ((s32) kdsData.unk58 == 3) {
            Sound_MusicStop();
            bMusicDucked = 0;
            if ((u32) kdsData.unk78 != 0U) {
                Sound_MusicPlay((s8 *) kdsData.unk78, 1U, 0);
                kdsData.unk78 = 0;
            }
        }
        kdsData.unk50 = arg0;
        kdsData.unk5C.Fade((KDFaderObject::FadeMode) 1, (f32) arg0, 0.0f, 0.0f, 0U);
        kdsData.unk58 = 4;
    }
}
#endif

#if 0 // DRAFT: function call 'Sound_MusicPlay(signed char *, unsigned int, int)' does not
void KDSound_DuckMusic(float arg0, float arg1) {
    u8 var_r5_3410;

    if (arg0 < kdsData.unk40) {
        if ((s32) kdsData.unk58 == 3) {
            Sound_MusicStop();
            if ((u32) kdsData.unk78 != 0U) {
                Sound_MusicPlay((s8 *) kdsData.unk78, 1U, 0);
                kdsData.unk78 = 0;
            }
        }
        var_r5_3410 = 0;
        if ((s32) kdsData.unk58 == 4) {
            if ((s32) kdsData.unk5C.unk4 == 1) {
                var_r5_3410 = 1;
                goto block_9;
            }
        } else if (!(kdsData.unk4C < 1.0f)) {
block_9:
            kdsData.unk4C = arg0;
            kdsData.unk50 = arg1;
            kdsData.unk5C.Fade((KDFaderObject::FadeMode) 5, 0.0f, (f32) arg1, 0.0f, var_r5_3410);
            kdsData.unk58 = 4;
            bMusicDucked = 1;
        }
    }
}
#endif

void KDSound_PauseMusic(bool arg0, bool arg1) {
    f32 temp_f31_3527;

    Sound_MusicPause(arg0);
    kdsData.unkC9 = (s8) arg0;
    if (arg0 == 0) {
        if ((u32) kdsData.unk78 != 0U) {
            kdsData.unk58 = 3;
        } else if (((arg1 != 0) || ((u8) bMusicDucked != 0)) && (((s32) kdsData.unk5C.unk4 == 2) || ((s32) kdsData.unk5C.unk4 == 1))) {
            kdsData.unk58 = 4;
        } else {
            kdsData.unk58 = 1;
        }
        if ((arg1 != 0) || ((u8) bMusicDucked != 0)) {
            if (kdsData.unk4C < 1.0f) {
                if (kdsData.unk40 < kdsData.unk4C) {
                    kdsData.unk4C = 1.0f;
                    if ((s32) kdsData.unk58 == 4) {
                        kdsData.unk58 = 0;
                    }
                } else {
                    temp_f31_3527 = kdsData.unk4C / kdsData.unk40;
                    KDSound_ScaleMasterVolume(((1.0f - temp_f31_3527) * kdsData.unk5C.GetFadePercentage()) + temp_f31_3527, 2);
                }
            } else {
                bMusicDucked = 0;
            }
        } else {
            KDSound_ScaleMasterVolume(1.0f, 2);
        }
    } else {
        kdsData.unk58 = 2;
    }
}

s32 KDSound_MusicIsStopping() {
    return kdsData.unk58 == 3;
}

void KDSound_ResetMusic() {
    Sound_MusicStop();
    kdsData.unkBC = 0;
    kdsData.unkD0 = 0;
    kdsData.unk104 = 0;
    kdsData.unk58 = 0;
    kdsData.unk5C.Reset();
    kdsData.unk4C = 1.0f;
    bMusicDucked = 0;
}

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void KDSound_StopMusic(float arg0) {
    if ((u8) kdsData.unkBC == 0) {
        kdsData.unkD0 = 0;
        if (arg0 > 0.0f) {
            kdsData.unk58 = 3;
            kdsData.unk5C.Fade((KDFaderObject::FadeMode) 5, 0.0f, arg0, 0.0f, 1U);
            return;
        }
        kdsData.unk58 = 0;
        kdsData.unk4C = 1.0f;
        bMusicDucked = 0;
        Sound_MusicStop();
    }
}
#endif

#if 0 // DRAFT: function call 'strncpy(signed char *, const char *, unsigned int)' does
void KDSound_PlayMusic(const char *arg0, float arg1, float arg2, int arg3) {
    strncpy(&kdsData.unk9C, arg0, 0x20U);
    if ((stricmp(arg0, KDSound_GetCurrentMusicTrackName()) != 0) || (KDSound_IsMusicPlaying(), (((u8) M2C_ERROR(/* Read from unset register $r3 */) == 0) != 0))) {
        if ((u8) kdsData.unkBC != 0) {
            return;
        }
        kdsData.unkD0 = 0;
        strcpy(&kdsData.unk7C, arg0);
        kdsData.unk78 = 0;
        kdsData.unk4C = 1.0f;
        kdsData.unk134 = arg3;
        if (arg2 > 0.0f) {
            kdsData.unk78 = (s32) &kdsData.unk7C;
            kdsData.unk58 = 3;
            kdsData.unk5C.Fade((KDFaderObject::FadeMode) 7, arg1, arg2, 0.0f, 1U);
            return;
        }
        if (arg1 > 0.0f) {
            kdsData.unk58 = 1;
            kdsData.unk5C.Fade((KDFaderObject::FadeMode) 1, arg1, 0.0f, 0.0f, 1U);
        } else {
            kdsData.unk58 = 1;
            KDSound_ScaleMasterVolume(1.0f, 2);
        }
        Sound_MusicStop();
        Sound_MusicPlay(&kdsData.unk7C, 1U, arg3);
    }
}
#endif

void KDSound_SetSFXLimit(bool arg0, int arg1) {
    kdsData.unkC8 = (s8) arg0;
    kdsData.unkC4 = arg1;
}

void KDSound_GetAcousticProperty() {
    Sound_GetAcousticProperty();
}

void KDSound_SetAcousticProperty(Sound_AcousticProperty arg0) {
    Sound_SetAcousticProperty(arg0);
}

s8 *KDSound_GetCurrentMusicTrackName() {
    return &kdsData.unk7C;
}

void KDSound_MusicGetResumePosition() {
    Sound_MusicGetResumePosition();
}

f32 KDSound_GetMasterMusicVolume() {
    return kdsData.unk40;
}

f32 KDSound_GetMasterSoundVolume() {
    return kdsData.unk3C;
}

void KDSound_StopAll() {
    Sound_StopAll();
}

void KDSound_PauseAll(bool arg0) {
    Sound_PauseAll(arg0);
}

void KDSound_SetPitch(int arg0, float arg1) {
    SoundEventInstance **var_r4_3849;
    SoundEventInstance *temp_r3_3860;

    if (arg0 > 0) {
        Sound_SetPitch(arg0, arg1);
        var_r4_3849 = instanceCache;
loop_5:
        temp_r3_3860 = *var_r4_3849;
        if (temp_r3_3860 == NULL) {

        } else {
            if ((s32) temp_r3_3860->unk0 == arg0) {
                temp_r3_3860->unk4 = arg1;
                return;
            }
            var_r4_3849 += 4;
            goto loop_5;
        }
    }
}

void KDSound_GetVolume(int arg0, float *arg1, float *arg2) {
    u8 sp9;
    u8 sp8;

    if (arg0 == 0) {
        *arg1 = 0.0f;
        *arg2 = 0.0f;
        return;
    }
    sp9 = 0;
    sp8 = 0;
    Sound_GetVolume(arg0, &sp9, &sp8);
    *arg1 = (f32) sp9 / 255.0f;
    *arg2 = (f32) sp8 / 255.0f;
}

f32 KDSound_GetVolume(int arg0) {
    f32 spC;
    f32 sp8;

    if (arg0 == 0) {
        return 0.0f;
    }
    KDSound_GetVolume(arg0, &spC, &sp8);
    if (spC > sp8) {
        return spC;
    }
    return sp8;
}

void KDSound_SetVolume(int arg0, float arg1, float arg2) {
    if (arg0 > 0) {
        Sound_SetVolume(arg0, (u8) (s32) (255.0f * arg1), (u8) (s32) (255.0f * arg2));
    }
}

void KDSound_SetVolume(int arg0, float arg1) {
    if (arg0 > 0) {
        KDSound_SetVolume(arg0, arg1, arg1);
    }
}

void KDSound_Stop(int *arg0) {
    s32 temp_r3_3997;

    temp_r3_3997 = *arg0;
    if ((temp_r3_3997 > 0) && (Sound_IsVoicePlaying(temp_r3_3997) != 0)) {
        Sound_Stop3d(*arg0);
    }
    *arg0 = 0;
}

void KDS_UpdateEnvironmentalAudio() {
    if ((s32) kdsData.unk13C != (s32) kdsData.unk138) {
        kdsData.unk13C = kdsData.unk138;
        Sound_SetAcousticProperty((Sound_AcousticProperty) kdsData.unk138);
    }
}

#if 0 // DRAFT: pointer/array required
void KDS_UpdatePlay3dFollowSounds() {
    s32 temp_r28_4050;
    s32 var_r29_4044;
    struct _struct_soundPlayFollowArray_0x8 *temp_r30_4049;

    var_r29_4044 = 0;
loop_6:
    if (var_r29_4044 < 0xF) {
        temp_r30_4049 = &soundPlayFollowArray[var_r29_4044];
        temp_r28_4050 = temp_r30_4049->unk0;
        if (temp_r28_4050 != -1) {
            if (Sound_IsVoicePlaying(temp_r28_4050) == 0) {
                KDS_FollowSndPosArrayRemove(temp_r28_4050);
                var_r29_4044 -= 1;
            } else {
                Sound_Update3d(temp_r28_4050, -1, temp_r30_4049->unk4);
            }
            var_r29_4044 += 1;
            goto loop_6;
        }
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
s32 KDSound_Play3d(MKAnimScript *arg0, const MKVector3 *arg1, unsigned int arg2, float arg3, bool arg4) {
    s32 temp_r4_4124;
    s32 var_r30_4100;
    s32 var_r3_4106;
    s8 *temp_r3_4128;

    if ((u8) bSplitScreen != 0) {
        return KDSound_Play(arg0, arg2);
    }
    var_r30_4100 = 0;
    kdsData.unk144 = (s32) arg0;
loop_8:
    temp_r4_4124 = var_r30_4100;
    var_r30_4100 += 1;
    temp_r3_4128 = arg0->GetEvent(temp_r4_4124, (MKAnimScriptedEvent::EventType) 1);
    if (temp_r3_4128 == NULL) {
        kdsData.unk144 = 0;
        return -1;
    }
    var_r3_4106 = KDSound_ResolveSound(temp_r3_4128, NULL);
    if (var_r3_4106 == (s32) noSoundID) {
        return 0;
    }
    if (var_r3_4106 <= -1) {
        var_r3_4106 = 0;
    }
    KDSound_Play3d(var_r3_4106, arg1, arg2, -1, arg3, arg4);
    goto loop_8;
}
#endif

#if 0 // DRAFT: pointer/array required
s32 KDSound_Play3d(int arg0, const MKVector3 *arg1, unsigned int arg2, int arg3, float arg4, bool arg5) {
    s32 temp_r27_4200;
    s32 temp_r3_4219;

    if ((arg0 < 0) || (arg0 > (s32) (gsData[1] - 1))) {
        return 0;
    }
    if ((u8) bSplitScreen != 0) {
        return KDSound_Play(arg0, arg2, arg3);
    }
    if (arg0 == (s32) noSoundID) {
        return 0;
    }
    if ((u8) kdsData.unkC8 != 0) {
        if ((s32) kdsData.unkC0 > (s32) kdsData.unkC4) {
            return 0;
        }
        kdsData.unkC0 += 1;
        goto block_11;
    }
block_11:
    if ((u32) M2C_FIELD(gsData, u32 *, 0) != 0U) {
        temp_r27_4200 = arg0 * 4;
        if ((u32) *(M2C_FIELD(gsData, u32 *, 0) + temp_r27_4200) != 0U) {
            if (KDS_IsSoundInRange(arg0, NULL, arg1) == 0) {
                return 0;
            }
            temp_r3_4219 = ((SoundEvent *) (*(M2C_FIELD(gsData, u32 *, 0) + temp_r27_4200)))->Play(arg1, arg2, arg3);
            if (arg5 != 0) {
                KDS_FollowSndPosArrayAdd(temp_r3_4219, arg1);
            }
            return temp_r3_4219;
        }
    }
    return 0;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
s32 KDSound_Play(MKAnimScript *arg0, unsigned int arg1) {
    s32 temp_r3_4254;
    s32 temp_r4_4267;
    s32 var_r30_4249;
    s8 *temp_r3_4271;

    var_r30_4249 = 0;
    kdsData.unk144 = (s32) arg0;
loop_5:
    temp_r4_4267 = var_r30_4249;
    var_r30_4249 += 1;
    temp_r3_4271 = arg0->GetEvent(temp_r4_4267, (MKAnimScriptedEvent::EventType) 1);
    if (temp_r3_4271 == NULL) {
        kdsData.unk144 = 0;
        return -1;
    }
    temp_r3_4254 = KDSound_ResolveSound(temp_r3_4271, NULL);
    if (temp_r3_4254 == (s32) noSoundID) {
        return 0;
    }
    if (temp_r3_4254 > -1) {
        KDSound_Play(temp_r3_4254, arg1, -1);
    }
    goto loop_5;
}
#endif

#if 0 // DRAFT: pointer/array required
s32 KDSound_Play(int arg0, unsigned int arg1, int arg2) {
    SoundEvent *temp_r3_4319;

    if (arg0 == (s32) noSoundID) {
        return 0;
    }
    if ((u8) kdsData.unkC8 != 0) {
        if ((s32) kdsData.unkC0 > (s32) kdsData.unkC4) {
            return 0;
        }
        kdsData.unkC0 += 1;
        goto block_6;
    }
block_6:
    if ((u32) *gsData != 0U) {
        temp_r3_4319 = *(*gsData + (arg0 * 4));
        if (temp_r3_4319 != NULL) {
            return temp_r3_4319->Play(NULL, arg1, arg2);
        }
    }
    return 0;
}
#endif

#if 0 // DRAFT: pointer/array required
u8 KDSound_GetSoundEventVol(int arg0) {
    if (arg0 < 1) {
        return 0U;
    }
    return M2C_FIELD(M2C_FIELD(*(*gsData + (arg0 * 4)), void **, 0x10), u8 *, 0xC);
}
#endif

#if 0 // DRAFT: function call 'Sound_SetListener(const Matrix *)' does not match
void KDSound_SetListener(const Matrix *arg0) {
    if (arg0 != NULL) {
        Sound_SetListener(arg0);
        kdsData.unk140 = (s32) &arg0->unk30;
        return;
    }
    kdsData.unk140 = 0;
}
#endif

void KDSound_Update() {
    if ((u8) kdsData.unkC8 != 0) {
        kdsData.unkC0 = 0;
    }
    KDS_UpdateEnvironmentalAudio();
    KDS_UpdateMusicFading();
    KDS_UpdatePlay3dFollowSounds();
    ((GlobalSoundData *) gsData)->Update();
    KDSound_ProcessChronoSound();
    KDSound_SoundDucking_Update();
}

void KDSound_Deinit() {
    Sound_StopAll();
    Sound_MusicStop();
    if ((s32) kdsData.unk2C > 0) {
        Sound_UnloadBank(kdsData.unk2C);
    }
    if ((s32) kdsData.unk28 > 0) {
        Sound_UnloadBank(kdsData.unk28);
    }
    kdsData.unk28 = 0;
    kdsData.unk2C = 0;
    kdsData.unk78 = 0;
}

#if 0 // DRAFT: function call 'strncpy(signed char *, const char *, unsigned int)' does
void KDSound_SetLevelID(const char *arg0) {
    if (arg0 != NULL) {
        strncpy(&kdsData.unk8, arg0, 0xAU);
    }
}
#endif

s32 KDSound_IsChronoSoundWarpActive() {
    return ((u8) M2C_FIELD(&kdsData, u8 *, 0x150) >> 6U) & 1;
}

s32 KDSound_IsChronoSoundWarpEnabled() {
    return ((u8) M2C_FIELD(&kdsData, u8 *, 0x150) >> 7U) & 1;
}

void KDSound_EnableChronoSoundWarp(bool arg0, bool arg1) {
    u8 temp_r4_4493;

    temp_r4_4493 = (M2C_FIELD(&kdsData, u8 *, 0x150) & ~0x80) | ((arg0 << 7) & 0x80);
    M2C_FIELD(&kdsData, u8 *, 0x150) = temp_r4_4493;
    if (arg1 != 0) {
        M2C_FIELD(&kdsData, u8 *, 0x150) = (u8) (temp_r4_4493 | 0x80);
    }
}

#if 0 // DRAFT: declaration syntax error
void KDSound_ProcessChronoSound() {
    SoundEventInstance **var_r28_4692;
    SoundEventInstance *temp_r3_4699;
    SoundEventInstance *temp_r3_4710;
    f32 temp_f31_4537;
    f32 temp_f31_4701;
    s32 temp_cr0_eq_4588;
    u32 temp_r0_4616;
    u8 var_r28_4519;
    u8 var_r29_4513;
    u8 var_r30_4540;

    var_r29_4513 = 0;
    if ((void *) M2C_FIELD(&gb, void **, 0xC) != NULL) {
        var_r28_4519 = 0;
        if ((((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x78) != 0U) || ((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x84) != 0U)) && (((KDStateMachine<CutsceneSystem> *) (M2C_FIELD(&gb, void **, 0xC) + 0x24))->GetState() != 0)) {
            var_r28_4519 = 1;
        }
        var_r29_4513 = var_r28_4519;
    }
    temp_f31_4537 = M2C_FIELD(&gb, f32 *, 0x2D0);
    if (temp_f31_4537 != 1.0f) {
        var_r30_4540 = 1;
    } else {
        var_r30_4540 = 0;
    }
    if (((u8) M2C_FIELD(&gb, u8 *, 0x395) == 0) && (var_r29_4513 == 0) && ((s32) M2C_FIELD(&kdsData, s32 *, 0x14C) == 0) && (((u8) M2C_FIELD(&kdsData, u8 *, 0x150) >> 7U) & 1) && (temp_f31_4537 != 1.0f)) {
        M2C_FIELD(&kdsData, s32 *, 0x14C) = KDSound_Play(GS_SlowMoSound, 0U, -1);
        if ((void **) M2C_FIELD(&gb, void ***, 0) != NULL) {
            ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(), 0x40)()))->RumbleStop();
        }
    }
    if ((temp_f31_4537 == 1.0f) && ((s32) M2C_FIELD(&kdsData, s32 *, 0x14C) != 0) && ((temp_cr0_eq_4588 = (((u8) M2C_FIELD(&kdsData, u8 *, 0x150) >> 7U) & 1) == 0, (temp_cr0_eq_4588 != 0)) || ((temp_cr0_eq_4588 == 0) && (M2C_FIELD(&kdsData, f32 *, 0x148) == 1.0f))) && ((u8) M2C_FIELD(&gb, u8 *, 0x395) == 0) && (var_r29_4513 == 0)) {
        M2C_FIELD(&kdsData, s32 *, 0x14C) = 0;
        if ((void **) M2C_FIELD(&gb, void ***, 0) != NULL) {
            ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(), 0x40)()))->RumbleStop();
        }
    }
    temp_r0_4616 = ((u8) M2C_FIELD(&kdsData, u8 *, 0x150) >> 7U) & 1;
    if ((temp_r0_4616 == 0) && (M2C_FIELD(&kdsData, f32 *, 0x148) == 1.0f)) {
        M2C_FIELD(&kdsData, u8 *, 0x150) = (u8) (M2C_FIELD(&kdsData, u8 *, 0x150) & ~0x40);
        return;
    }
    if ((temp_r0_4616 != 0) && (temp_f31_4537 == M2C_FIELD(&kdsData, f32 *, 0x148))) {
        M2C_FIELD(&kdsData, u8 *, 0x150) = (u8) (M2C_FIELD(&kdsData, u8 *, 0x150) & ~0x40);
        return;
    }
    if ((temp_r0_4616 == 0) && (M2C_FIELD(&kdsData, f32 *, 0x148) != 1.0f)) {
        M2C_FIELD(&kdsData, f32 *, 0x148) = 1.0f;
        M2C_FIELD(&kdsData, u8 *, 0x150) = (u8) (M2C_FIELD(&kdsData, u8 *, 0x150) | 0x40);
    }
    if ((((u8) M2C_FIELD(&kdsData, u8 *, 0x150) >> 7U) & 1) && (var_r30_4540 != 0)) {
        M2C_FIELD(&kdsData, f32 *, 0x148) = temp_f31_4537;
        M2C_FIELD(&kdsData, u8 *, 0x150) = (u8) (M2C_FIELD(&kdsData, u8 *, 0x150) | 0x40);
    }
    if ((u8) M2C_FIELD(&gb, u8 *, 0x395) == 0) {
        if ((M2C_FIELD(&kdsData, f32 *, 0x148) != 1.0f) && (var_r29_4513 == 0)) {
            Music_Duck(0.3f * kdsData.unk40, 0.5f);
        }
        if ((M2C_FIELD(&kdsData, f32 *, 0x148) == 1.0f) && (var_r29_4513 == 0)) {
            Music_UnDuck(0.5f);
        }
        var_r28_4692 = instanceCache;
loop_48:
        temp_r3_4710 = *var_r28_4692;
        if (temp_r3_4710 != NULL) {
            if (Sound_IsVoicePlaying(temp_r3_4710->unk0) != 0) {
                temp_r3_4699 = *var_r28_4692;
                temp_f31_4701 = temp_r3_4699->unk4;
                KDSound_SetPitch(temp_r3_4699->unk0, temp_f31_4701 * M2C_FIELD(&kdsData, f32 *, 0x148));
                (*var_r28_4692)->unk4 = temp_f31_4701;
            }
            var_r28_4692 += 4;
            goto loop_48;
        }
    }
}
#endif

void KDSound_InvalidateSoundIDRange(int arg0, int arg1) {
    ((GlobalSoundData *) gsData)->InvalidateSoundIDRange(arg0, arg1);
}

void KDSound_ResolveSoundIDs(float arg0) {
    ((GlobalSoundData *) gsData)->ResolveSoundIDs(arg0);
}

#if 0 // DRAFT: function call 'strncpy(signed char *, const char *, unsigned int)' does
void KDSound_Init(const char *arg0) {
    s32 temp_ret_4781;
    s32 temp_ret_4806;
    u8 temp_r3_4828;

    kdsData.unk28 = 0;
    kdsData.unk2C = 0;
    temp_ret_4781 = MKArchive_Exists(Str_Printf("SFX_%s%s", arg0, ".gsb", M2C_BITWISE(f32, strncpy(&kdsData.unk8, arg0, 0xAU))), NULL);
    if (temp_ret_4781 != 0) {
        kdsData.unk28 = Sound_LoadBank(Str_Printf("SFX_%s", arg0, M2C_BITWISE(f32, temp_ret_4781)), 0U, -1);
    }
    GameLanguage_GetCode(-1);
    temp_ret_4806 = MKArchive_Exists(Str_Printf("VOX_%s_%s%s", arg0, M2C_ERROR(/* Read from unset register $r3 */), ".gsb"), NULL);
    if (temp_ret_4806 != 0) {
        kdsData.unk2C = Sound_LoadBank(Str_Printf("VOX_%s", arg0, M2C_BITWISE(f32, temp_ret_4806)), 0U, -1);
    }
    ((GlobalSoundData *) gsData)->ResolveSoundIDs();
    temp_r3_4828 = M2C_FIELD(&kdsData, u8 *, 0x150) & ~0x80;
    M2C_FIELD(&kdsData, s32 *, 0x14C) = 0;
    M2C_FIELD(&kdsData, u8 *, 0x150) = temp_r3_4828;
    M2C_FIELD(&kdsData, f32 *, 0x148) = (f32) M2C_FIELD(&gb, f32 *, 0x374);
    M2C_FIELD(&kdsData, u8 *, 0x150) = (u8) (temp_r3_4828 & ~0x40);
}
#endif

#if 0 // DRAFT: type mismatch
void KDSound_DeinitModule() {
    SoundEventInstance **var_r31_4853;
    SoundEventInstance **var_r3_4854;
    SoundEventInstance **var_r4_4852;
    SoundEventInstance *temp_r0_4857;
    SoundEventInstance *temp_r0_4876;
    u32 temp_r0_4862;

    KDSound_Deinit();
    var_r4_4852 = instanceCache;
    var_r31_4853 = var_r4_4852;
    var_r3_4854 = var_r4_4852;
loop_3:
    temp_r0_4862 = M2C_FIELD(var_r3_4854, u32 *, -4);
    var_r3_4854 -= 4;
    if (temp_r0_4862 != 0U) {
        temp_r0_4857 = *var_r3_4854;
        if (temp_r0_4857 < var_r31_4853) {
            var_r31_4853 = (SoundEventInstance **) temp_r0_4857;
        }
        goto loop_3;
    }
    if (var_r3_4854 != &gEmptyPtrListDL) {
loop_9:
        temp_r0_4876 = *var_r4_4852;
        if (temp_r0_4876 != NULL) {
            if (temp_r0_4876 < var_r31_4853) {
                var_r31_4853 = (SoundEventInstance **) temp_r0_4876;
            }
            var_r4_4852 += 4;
            goto loop_9;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(var_r31_4853, NULL, 0);
        } else {
            free((MKHeap *) var_r31_4853);
        }
    }
    instanceCache = NULL;
    ((GlobalSoundData *) gsData)->Deinit();
    kdsData.Deinit();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void KDSound_InitModule(bool arg0, int arg1) {
    MKHeap *var_r3_4938;
    s32 var_ctr_4950;

    kdsData.Init(arg0);
    ((GlobalSoundData *) gsData)->Init("global.sound", arg1);
    ((GlobalSoundData *) gsData)->ResolveSoundIDs();
    KDS_FollowSndPosArrayInit();
    if (MKHeap::Current() != NULL) {
        var_r3_4938 = ((MKHeap *) (MKHeap::Current()))->Alloc(0x608, NULL, 0);
    } else {
        var_r3_4938 = malloc(0x608);
    }
    instanceCache = (SoundEventInstance **) var_r3_4938;
    instanceCache = var_r3_4938 + 0x500;
    M2C_FIELD(var_r3_4938, s32 *, 0x500) = 0;
    var_ctr_4950 = 0x40;
    do {
        instanceCache += 4;
        M2C_FIELD(instanceCache, MKHeap **, 4) = var_r3_4938;
        var_r3_4938 += 0x14;
        var_ctr_4950 -= 1;
    } while (var_ctr_4950 != 0);
    instanceCache += 4;
    M2C_FIELD(instanceCache, MKHeap **, 4) = NULL;
}
#endif
