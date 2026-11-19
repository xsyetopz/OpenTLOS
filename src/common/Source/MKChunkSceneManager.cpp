#include "common/Source/MKChunkSceneManager.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKFFTWater.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKLevelChunk.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKOcean.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
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
#include "common/Source/MKSystem.h"
#include "common/Source/Str.h"
#include <m2c_macros.h>

#if 0 // DRAFT: type mismatch
M2C_UNK __construct_array(void *, MKProp *(*)(MKProp *), MKProp *(*)(MKProp *, s16), M2C_UNK, M2C_UNK); /* extern */
M2C_UNK free(s32);                                  /* extern */
s32 malloc(s32);                                    /* extern */
s32 stricmp(s8 *, s8 *);                            /* extern */

void MKChunkSceneManager::PostDrawWater() {
    s32 temp_r0_29;
    s32 var_r30_23;
    s32 var_r31_24;
    void *temp_r3_28;

    var_r30_23 = 0;
    var_r31_24 = 0;
loop_6:
    if (var_r30_23 < (MKLevelChunk **) this->unkEC) {
        temp_r3_28 = *(this->unkE8 + var_r31_24);
        temp_r0_29 = M2C_FIELD(temp_r3_28, s32 *, 0x90);
        if (((temp_r0_29 == 9) || (temp_r0_29 == 0xC)) && (M2C_FIELD(temp_r3_28, s32 *, 0x138) & 1)) {
            M2C_FIELD(M2C_FIELD(temp_r3_28, void **, 8), M2C_UNK (**)(), 0x78)();
        }
        var_r30_23 += 1;
        var_r31_24 += 4;
        goto loop_6;
    }
}
#endif

#if 0 // DRAFT: type mismatch
void MKChunkSceneManager::DrawWater() {
    MKChunkSceneManager *temp_r29_63;
    MKChunkSceneManager *var_r3_0;
    s32 temp_r0_70;
    s32 temp_r0_98;
    s32 var_r30_64;
    s32 var_r30_92;
    s32 var_r31_65;
    s32 var_r31_93;
    void *temp_r3_97;

    var_r3_0 = this;
    temp_r29_63 = var_r3_0;
    var_r30_64 = 0;
    var_r31_65 = 0;
loop_6:
    if (var_r30_64 < (MKLevelChunk **) temp_r29_63->unkEC) {
        var_r3_0 = *(temp_r29_63->unkE8 + var_r31_65);
        temp_r0_70 = var_r3_0->unk90;
        if (((temp_r0_70 == 9) || (temp_r0_70 == 0xC)) && (var_r3_0->unk138 & 1)) {
            var_r3_0 = M2C_FIELD(var_r3_0->unk8, MKChunkSceneManager *(**)(M2C_UNK), 0x74)(0);
        }
        var_r30_64 += 1;
        var_r31_65 += 4;
        goto loop_6;
    }
    ((MKFFTWater *) var_r3_0)->ManagedDraw();
    var_r30_92 = 0;
    var_r31_93 = 0;
loop_13:
    if (var_r30_92 < (MKLevelChunk **) temp_r29_63->unkEC) {
        temp_r3_97 = *(temp_r29_63->unkE8 + var_r31_93);
        temp_r0_98 = M2C_FIELD(temp_r3_97, s32 *, 0x90);
        if (((temp_r0_98 == 9) || (temp_r0_98 == 0xC)) && (M2C_FIELD(temp_r3_97, s32 *, 0x138) & 1)) {
            M2C_FIELD(M2C_FIELD(temp_r3_97, void **, 8), M2C_UNK (**)(M2C_UNK), 0x74)(3);
        }
        var_r30_92 += 1;
        var_r31_93 += 4;
        goto loop_13;
    }
}
#endif

#if 0 // DRAFT: function call 'Str_FindChar(signed char *, long)' does not match
MKChunkSceneManager *MKChunkSceneManager::StripExtension(const char *arg0, char arg1) {
    u8 *temp_r3_135;

    temp_r3_135 = Str_FindChar((s8 *) this, (s32) (s8) arg0);
    if ((temp_r3_135 != NULL) && (temp_r3_135 != this)) {
        return Str_CopyString((s8 *) this, temp_r3_135 - this);
    }
    return this;
}
#endif

#if 0 // DRAFT: type mismatch
s32 MKChunkSceneManager::IsEnabled(MKProp *arg0, int arg1) {
    MKLevelChunk **temp_r0_165;
    MKLevelChunk **var_ctr_167;
    s32 temp_r4_176;
    s32 var_r6_166;
    void *temp_r7_172;

    if (arg1 == -1) {
        return (arg0->unk18 & 0x80000000) == 0;
    }
    temp_r0_165 = this->unkEC;
    var_r6_166 = 0;
    var_ctr_167 = temp_r0_165;
    if (temp_r0_165 > 0) {
loop_3:
        temp_r7_172 = *(this->unkE8 + var_r6_166);
        if (arg1 == (s32) M2C_FIELD(temp_r7_172, s32 *, 0x124)) {
            temp_r4_176 = arg0->unk18;
            if (!(temp_r4_176 & 0x80000000) && (temp_r4_176 & M2C_FIELD(temp_r7_172, s32 *, 0x80) & 0x7FFFFFFF) && !(temp_r4_176 & M2C_FIELD(temp_r7_172, s32 *, 0x84) & 0x7FFFFFFF)) {
                return 1;
            }
            return 0;
        }
        var_r6_166 += 4;
        var_ctr_167 -= 1;
        if (var_ctr_167 == NULL) {
            /* Duplicate return node #9. Try simplifying control flow for better match */
            return 1;
        }
        goto loop_3;
    }
    return 1;
}
#endif

#if 0 // DRAFT: type mismatch
s32 MKChunkSceneManager::IsEnabled(MKTerrainModel *arg0, int arg1) {
    MKLevelChunk **temp_r0_206;
    MKLevelChunk **var_ctr_208;
    s32 temp_r4_217;
    s32 var_r6_207;
    void *temp_r7_213;

    if (arg1 == -1) {
        return 1;
    }
    temp_r0_206 = this->unkEC;
    var_r6_207 = 0;
    var_ctr_208 = temp_r0_206;
    if (temp_r0_206 > 0) {
loop_3:
        temp_r7_213 = *(this->unkE8 + var_r6_207);
        if (arg1 == (s32) M2C_FIELD(temp_r7_213, s32 *, 0x124)) {
            temp_r4_217 = arg0->unk4;
            if (!(temp_r4_217 & 0x80000000) && (temp_r4_217 & M2C_FIELD(temp_r7_213, s32 *, 0x80) & 0x7FFFFFFF) && !(temp_r4_217 & M2C_FIELD(temp_r7_213, s32 *, 0x84) & 0x7FFFFFFF)) {
                return 1;
            }
            return 0;
        }
        var_r6_207 += 4;
        var_ctr_208 -= 1;
        if (var_ctr_208 == NULL) {
            /* Duplicate return node #9. Try simplifying control flow for better match */
            return 1;
        }
        goto loop_3;
    }
    return 1;
}
#endif

#if 0 // DRAFT: type mismatch
void MKChunkSceneManager::DisableZones(unsigned int arg0, bool arg1, int arg2) {
    s32 var_r10_243;
    s32 var_r7_244;
    void *temp_r8_258;
    void *temp_r8_265;

    var_r10_243 = 0;
    var_r7_244 = 0;
loop_7:
    if (var_r10_243 < (MKLevelChunk **) this->unkEC) {
        if ((arg2 == -1) || (arg2 == (s32) M2C_FIELD(*(this->unkE8 + var_r7_244), s32 *, 0x124))) {
            if (arg1 != 0) {
                temp_r8_258 = *(this->unkE8 + var_r7_244);
                M2C_FIELD(temp_r8_258, s32 *, 0x84) = (s32) (M2C_FIELD(temp_r8_258, s32 *, 0x84) | arg0);
            } else {
                temp_r8_265 = *(this->unkE8 + var_r7_244);
                M2C_FIELD(temp_r8_265, s32 *, 0x84) = (s32) (M2C_FIELD(temp_r8_265, s32 *, 0x84) & ~(arg0 | arg0));
            }
        }
        var_r10_243 += 1;
        var_r7_244 += 4;
        goto loop_7;
    }
}
#endif

#if 0 // DRAFT: type mismatch
void MKChunkSceneManager::EnableZones(unsigned int arg0, bool arg1, int arg2) {
    s32 var_r10_283;
    s32 var_r7_284;
    void *temp_r8_298;
    void *temp_r8_305;

    var_r10_283 = 0;
    var_r7_284 = 0;
loop_7:
    if (var_r10_283 < (MKLevelChunk **) this->unkEC) {
        if ((arg2 == -1) || (arg2 == (s32) M2C_FIELD(*(this->unkE8 + var_r7_284), s32 *, 0x124))) {
            if (arg1 != 0) {
                temp_r8_298 = *(this->unkE8 + var_r7_284);
                M2C_FIELD(temp_r8_298, s32 *, 0x80) = (s32) (M2C_FIELD(temp_r8_298, s32 *, 0x80) | arg0);
            } else {
                temp_r8_305 = *(this->unkE8 + var_r7_284);
                M2C_FIELD(temp_r8_305, s32 *, 0x80) = (s32) (M2C_FIELD(temp_r8_305, s32 *, 0x80) & ~(arg0 | arg0));
            }
        }
        var_r10_283 += 1;
        var_r7_284 += 4;
        goto loop_7;
    }
}
#endif

#if 0 // DRAFT: type mismatch
s32 MKChunkSceneManager::GetChunkAt(const MKVector3 &arg0) {
    f32 temp_f1_348;
    f32 var_f31_328;
    s32 temp_r0_338;
    s32 var_r29_332;
    s32 var_r30_331;
    s32 var_r31_333;
    void *temp_r3_337;

    var_f31_328 = 3.4028235e38f;
    var_r30_331 = 0;
    var_r29_332 = 0;
    var_r31_333 = 0;
loop_6:
    if (var_r29_332 < (MKLevelChunk **) this->unkEC) {
        temp_r3_337 = *(this->unkE8 + var_r31_333);
        temp_r0_338 = M2C_FIELD(temp_r3_337, s32 *, 0x90);
        if ((temp_r0_338 == 9) || (temp_r0_338 == 0xC)) {
            temp_f1_348 = M2C_FIELD(M2C_FIELD(temp_r3_337, void **, 8), f32 (**)(MKVector3 *), 0x84)(&arg0);
            if (temp_f1_348 < var_f31_328) {
                var_f31_328 = temp_f1_348;
                var_r30_331 = *(this->unkE8 + var_r31_333);
            }
        }
        var_r29_332 += 1;
        var_r31_333 += 4;
        goto loop_6;
    }
    return var_r30_331;
}
#endif

MKLevelChunk *MKChunkSceneManager::GetWorkingChunk() {
    return this->unkF4;
}

#if 0 // DRAFT: type mismatch
void MKChunkSceneManager::EnableTerrainModel(const char *arg0, bool arg1) {
    s32 temp_r0_394;
    s32 var_r30_388;
    s32 var_r31_389;
    void *temp_r3_393;

    var_r30_388 = 0;
    var_r31_389 = 0;
loop_5:
    if (var_r30_388 < (MKLevelChunk **) this->unkEC) {
        temp_r3_393 = *(this->unkE8 + var_r31_389);
        temp_r0_394 = M2C_FIELD(temp_r3_393, s32 *, 0x90);
        if ((temp_r0_394 == 9) || (temp_r0_394 == 0xC)) {
            M2C_FIELD(M2C_FIELD(temp_r3_393, void **, 8), M2C_UNK (**)(s8 *, u8), 0x88)(arg0, arg1);
        }
        var_r30_388 += 1;
        var_r31_389 += 4;
        goto loop_5;
    }
}
#endif

s32 MKChunkSceneManager::GetCollisionManager() {
    return M2C_BITWISE(s32, this->unkF4->unk14.unk7C);
}

#if 0 // DRAFT: type mismatch
void MKChunkSceneManager::SetActivePoint(const MKVector3 &arg0) {
    s32 var_r30_437;
    s32 var_r31_438;
    void *temp_r3_443;

    var_r30_437 = 0;
    var_r31_438 = 0;
loop_2:
    if (var_r30_437 < (MKLevelChunk **) this->unkEC) {
        temp_r3_443 = *(this->unkE8 + var_r31_438);
        M2C_FIELD(M2C_FIELD(temp_r3_443, void **, 8), M2C_UNK (**)(void *, MKVector3 *), 0x14)(temp_r3_443, &arg0);
        var_r30_437 += 1;
        var_r31_438 += 4;
        goto loop_2;
    }
}
#endif

#if 0 // DRAFT: type mismatch
void MKChunkSceneManager::SetWorkingChunk(MKLevelChunk *arg0) {
    MKLevelChunk **temp_r0_475;
    MKLevelChunk **var_ctr_476;
    s32 var_r3_473;
    s32 var_r6_472;

    if (arg0 != NULL) {
        var_r6_472 = 0;
        var_r3_473 = 0;
        *MKResource::sWorkingChunkID = arg0->unk14.unk10C;
        temp_r0_475 = this->unkEC;
        var_ctr_476 = temp_r0_475;
        if (temp_r0_475 > 0) {
loop_2:
            if ((s32) arg0->unk14.unk10C == (s32) M2C_FIELD(*(this->unkE8 + var_r3_473), s32 *, 0x124)) {
                *MKResource::sWorkingChunkIndex = var_r6_472;
            } else {
                var_r6_472 += 1;
                var_r3_473 += 4;
                var_ctr_476 -= 1;
                if (var_ctr_476 != NULL) {
                    goto loop_2;
                }
            }
        }
        arg0->Activate();
    } else {
        *MKResource::sWorkingChunkID = -1;
        *MKResource::sWorkingChunkIndex = -1;
        this->unkF4->Deactivate();
    }
    this->unkF4 = arg0;
}
#endif

#if 0 // DRAFT: type mismatch
void MKChunkSceneManager::EnableAllChunks(bool arg0) {
    MKLevelChunk *temp_r3_526;
    s32 var_r29_520;
    s32 var_r31_521;

    var_r29_520 = 0;
    var_r31_521 = 0;
loop_5:
    if (var_r29_520 < (MKLevelChunk **) this->unkEC) {
        temp_r3_526 = *(this->unkE8 + var_r31_521);
        if (arg0 != 0) {
            temp_r3_526->ApplyFlags(7U);
        } else {
            temp_r3_526->ApplyFlags(0U);
        }
        var_r29_520 += 1;
        var_r31_521 += 4;
        goto loop_5;
    }
}
#endif

s32 MKChunkSceneManager::IsLockedChunkReadyForUse(MKLevelChunk *arg0) {
    return ((u32) arg0->unk138 >> 6U) & 1;
}

void MKChunkSceneManager::UnlockChunk(MKLevelChunk *arg0) {
    M2C_FIELD(arg0->unk8, M2C_UNK (**)(MKLevelChunk *), 0x44)(arg0);
}

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to
MKLevelChunk *MKChunkSceneManager::LockChunk(MKChunkRequest *arg0, char **arg1, int arg2) {
    MKLevelChunk *temp_r3_588;

    temp_r3_588 = ((MKLevelChunk *) arg0)->Game_ChunkChooser((MKChunkRequest *) arg1, (s8 **) arg2, this->unkE8, this->unkEC, M2C_ERROR(/* Read from unset register $r8 */));
    M2C_FIELD(temp_r3_588->unk8, M2C_UNK (**)(s32, u8), 0x40)(arg0->unk0, arg0->unkC);
    return temp_r3_588;
}
#endif

#if 0 // DRAFT: type mismatch
MKLevelChunk *MKChunkSceneManager::QueueChunkLoad(const char *arg0, MKChunkRequest *arg1, char **arg2, int arg3, const char *arg4, bool arg5, bool arg6) {
    MKLevelChunk *temp_r3_622;
    MKLevelChunk *temp_r3_678;
    s32 temp_cr0_eq_624;
    s32 var_r24_618;
    s32 var_r31_617;

    var_r31_617 = 0;
    var_r24_618 = 0;
loop_10:
    if (var_r31_617 >= (MKLevelChunk **) this->unkEC) {
        arg1->unkC = 0;
        arg1->unk8 = 0;
        temp_r3_678 = ((MKLevelChunk *) arg1)->Game_ChunkChooser((MKChunkRequest *) arg2, (s8 **) arg3, this->unkE8, this->unkEC, M2C_ERROR(/* Read from unset register $r8 */));
        temp_r3_678->QueueChunkLoad(arg0, arg1->unk4, arg6);
        return temp_r3_678;
    }
    temp_r3_622 = *(this->unkE8 + var_r24_618);
    temp_cr0_eq_624 = (s32) temp_r3_622->unk14.unk78 == 9;
    if ((((temp_cr0_eq_624 != 0) || (temp_cr0_eq_624 != 0)) && ((s8 *) arg1->unk4 != NULL) && (stricmp(arg1->unk4, temp_r3_622->GetChunkName()) == 0)) || ((stricmp(*(this->unkE8 + var_r24_618) + 0xC4, arg1->unk4) == 0) && (strlen(*(this->unkE8 + var_r24_618) + 0x104) == 0)) || (stricmp(*(this->unkE8 + var_r24_618) + 0x104, arg1->unk4) == 0)) {
        return *(this->unkE8 + var_r24_618);
    }
    var_r31_617 += 1;
    var_r24_618 += 4;
    goto loop_10;
}
#endif

#if 0 // DRAFT: type mismatch
s32 MKChunkSceneManager::IsChunkLoaded(const char *arg0) {
    s32 var_r30_702;
    s32 var_r31_703;

    var_r30_702 = 0;
    var_r31_703 = 0;
loop_5:
    if (var_r30_702 >= (MKLevelChunk **) this->unkEC) {
        return 0;
    }
    if ((((MKLevelChunk *) (*(this->unkE8 + var_r31_703)))->GetChunkName() != NULL) && (stricmp(arg0, ((MKLevelChunk *) (*(this->unkE8 + var_r31_703)))->GetChunkName()) == 0)) {
        return M2C_FIELD(*(this->unkE8 + var_r31_703), s32 *, 0x90) == 9;
    }
    var_r30_702 += 1;
    var_r31_703 += 4;
    goto loop_5;
}
#endif

#if 0 // DRAFT: type mismatch
void MKChunkSceneManager::CalculateUpdateDistances() {
    s32 var_r30_750;
    s32 var_r31_751;
    void *temp_r3_762;

    var_r30_750 = 0;
    var_r31_751 = 0;
loop_2:
    if (var_r30_750 < (MKLevelChunk **) this->unkEC) {
        SetWorkingChunk(*(this->unkE8 + var_r31_751));
        temp_r3_762 = *(this->unkE8 + var_r31_751);
        M2C_FIELD(M2C_FIELD(temp_r3_762, void **, 8), M2C_UNK (**)(void *), 0x28)(temp_r3_762);
        SetWorkingChunk(0);
        var_r30_750 += 1;
        var_r31_751 += 4;
        goto loop_2;
    }
}
#endif

#if 0 // DRAFT: type mismatch
void MKChunkSceneManager::CalculateVisibility(bool arg0) {
    s32 var_r30_795;
    s32 var_r31_796;
    void *temp_r3_808;

    var_r30_795 = 0;
    var_r31_796 = 0;
loop_2:
    if (var_r30_795 < (MKLevelChunk **) this->unkEC) {
        SetWorkingChunk(*(this->unkE8 + var_r31_796));
        temp_r3_808 = *(this->unkE8 + var_r31_796);
        M2C_FIELD(M2C_FIELD(temp_r3_808, void **, 8), M2C_UNK (**)(void *, u8), 0x24)(temp_r3_808, arg0);
        SetWorkingChunk(0);
        var_r30_795 += 1;
        var_r31_796 += 4;
        goto loop_2;
    }
}
#endif

#if 0 // DRAFT: type mismatch
s32 MKChunkSceneManager::GetPropsInRange(MKProp **arg0, int arg1, const MKVector3 &arg2, float arg3, int arg4, bool arg5) {
    s32 var_r29_848;
    s32 var_r30_847;
    s32 var_r31_849;
    void *temp_r3_858;

    var_r30_847 = 0;
    var_r29_848 = 0;
    var_r31_849 = 0;
loop_4:
    if (var_r29_848 < (MKLevelChunk **) this->unkEC) {
        if (var_r30_847 < arg1) {
            temp_r3_858 = *(this->unkE8 + var_r31_849);
            var_r30_847 += M2C_FIELD(M2C_FIELD(temp_r3_858, void **, 8), s32 (**)(void *, MKProp **, s32, MKVector3 *, s32, u8, f32), 0x8C)(temp_r3_858, &arg0[var_r30_847], arg1 - var_r30_847, &arg2, arg4, arg5, arg3);
        }
        var_r29_848 += 1;
        var_r31_849 += 4;
        goto loop_4;
    }
    return var_r30_847;
}
#endif

#if 0 // DRAFT: type mismatch
void MKChunkSceneManager::SendMessage(MKMessage *arg0, unsigned int arg1, bool arg2, MKVector3 *arg3, float arg4, bool arg5) {
    s32 temp_r0_905;
    s32 var_r30_899;
    s32 var_r31_900;
    void *temp_r3_904;

    var_r30_899 = 0;
    var_r31_900 = 0;
loop_5:
    if (var_r30_899 < (MKLevelChunk **) this->unkEC) {
        temp_r3_904 = *(this->unkE8 + var_r31_900);
        temp_r0_905 = M2C_FIELD(temp_r3_904, s32 *, 0x90);
        if ((temp_r0_905 == 9) || (temp_r0_905 == 0xC)) {
            M2C_FIELD(M2C_FIELD(temp_r3_904, void **, 8), M2C_UNK (**)(MKMessage *, u32, u8, MKVector3 *, u8, f32), 0x3C)(arg0, arg1, arg2, arg3, arg5, arg4);
        }
        var_r30_899 += 1;
        var_r31_900 += 4;
        goto loop_5;
    }
}
#endif

#if 0 // DRAFT: type mismatch
u32 MKChunkSceneManager::FindTerrainModel(const char *arg0) {
    MKLevelChunk *temp_r3_948;
    s32 var_r30_959;
    s32 var_r31_960;
    u32 temp_r3_954;
    u32 temp_r3_972;
    void *temp_r3_965;

    if ((u8) this->unkE4 != 0) {
        temp_r3_948 = this->unkF4;
        if (temp_r3_948 != NULL) {
            temp_r3_954 = M2C_FIELD(temp_r3_948->unk8, u32 (**)(), 0x70)();
            if (temp_r3_954 != 0) {
                return temp_r3_954;
            }
        }
        var_r30_959 = 0;
        var_r31_960 = 0;
loop_9:
        if (var_r30_959 >= (MKLevelChunk **) this->unkEC) {
            goto block_10;
        }
        temp_r3_965 = *(this->unkE8 + var_r31_960);
        if (temp_r3_965 != (MKLevelChunk *) this->unkF4) {
            temp_r3_972 = M2C_FIELD(M2C_FIELD(temp_r3_965, void **, 8), u32 (**)(s8 *), 0x70)(arg0);
            if (temp_r3_972 != 0) {
                return temp_r3_972;
            }
        }
        var_r30_959 += 1;
        var_r31_960 += 4;
        goto loop_9;
    }
block_10:
    return 0U;
}
#endif

#if 0 // DRAFT: type mismatch
u32 MKChunkSceneManager::FindProp(const char *arg0) {
    MKLevelChunk *temp_r3_1005;
    s32 var_r30_1016;
    s32 var_r31_1017;
    u32 temp_r3_1011;
    u32 temp_r3_1029;
    void *temp_r3_1022;

    if ((u8) this->unkE4 != 0) {
        temp_r3_1005 = this->unkF4;
        if (temp_r3_1005 != NULL) {
            temp_r3_1011 = M2C_FIELD(temp_r3_1005->unk8, u32 (**)(), 0x6C)();
            if (temp_r3_1011 != 0) {
                return temp_r3_1011;
            }
        }
        var_r30_1016 = 0;
        var_r31_1017 = 0;
loop_9:
        if (var_r30_1016 >= (MKLevelChunk **) this->unkEC) {
            goto block_10;
        }
        temp_r3_1022 = *(this->unkE8 + var_r31_1017);
        if (temp_r3_1022 != (MKLevelChunk *) this->unkF4) {
            temp_r3_1029 = M2C_FIELD(M2C_FIELD(temp_r3_1022, void **, 8), u32 (**)(s8 *), 0x6C)(arg0);
            if (temp_r3_1029 != 0) {
                return temp_r3_1029;
            }
        }
        var_r30_1016 += 1;
        var_r31_1017 += 4;
        goto loop_9;
    }
block_10:
    return 0U;
}
#endif

void MKChunkSceneManager::FindDescriptorInLocalChunk(const char *arg0) {
    MKLevelChunk *temp_r3_1056;

    temp_r3_1056 = this->unkF4;
    M2C_FIELD(temp_r3_1056->unk8, M2C_UNK (**)(MKLevelChunk *), 0x68)(temp_r3_1056);
}

#if 0 // DRAFT: type mismatch
u32 MKChunkSceneManager::FindDescriptor(const char *arg0) {
    MKLevelChunk *temp_r3_1079;
    s32 var_r30_1090;
    s32 var_r31_1091;
    u32 temp_r3_1085;
    u32 temp_r3_1103;
    void *temp_r3_1096;

    if ((u8) this->unkE4 != 0) {
        temp_r3_1079 = this->unkF4;
        if (temp_r3_1079 != NULL) {
            temp_r3_1085 = M2C_FIELD(temp_r3_1079->unk8, u32 (**)(), 0x68)();
            if (temp_r3_1085 != 0) {
                return temp_r3_1085;
            }
        }
        var_r30_1090 = 0;
        var_r31_1091 = 0;
loop_9:
        if (var_r30_1090 >= (MKLevelChunk **) this->unkEC) {
            goto block_10;
        }
        temp_r3_1096 = *(this->unkE8 + var_r31_1091);
        if (temp_r3_1096 != (MKLevelChunk *) this->unkF4) {
            temp_r3_1103 = M2C_FIELD(M2C_FIELD(temp_r3_1096, void **, 8), u32 (**)(s8 *), 0x68)(arg0);
            if (temp_r3_1103 != 0) {
                return temp_r3_1103;
            }
        }
        var_r30_1090 += 1;
        var_r31_1091 += 4;
        goto loop_9;
    }
block_10:
    return 0U;
}
#endif

void MKChunkSceneManager::AddTerrainModel(const char *arg0, int arg1) {
    MKLevelChunk *temp_r3_1130;

    temp_r3_1130 = this->unkF4;
    M2C_FIELD(temp_r3_1130->unk8, M2C_UNK (**)(MKLevelChunk *), 0x64)(temp_r3_1130);
}

void MKChunkSceneManager::AddPropDescriptor(MKPropDescriptor *arg0) {
    MKLevelChunk *temp_r3_1147;

    temp_r3_1147 = this->unkF4;
    M2C_FIELD(temp_r3_1147->unk8, M2C_UNK (**)(MKLevelChunk *), 0x60)(temp_r3_1147);
}

void MKChunkSceneManager::AddProp(MKProp *arg0) {
    MKLevelChunk *temp_r3_1164;

    temp_r3_1164 = this->unkF4;
    M2C_FIELD(temp_r3_1164->unk8, M2C_UNK (**)(MKLevelChunk *), 0x5C)(temp_r3_1164);
}

void MKChunkSceneManager::ResolveAllProps() {

}

#if 0 // DRAFT: type mismatch
void MKChunkSceneManager::DrawTerrain(int arg0) {
    s32 temp_r0_1196;
    s32 var_r30_1190;
    s32 var_r31_1191;
    void *temp_r3_1195;

    var_r30_1190 = 0;
    var_r31_1191 = 0;
loop_5:
    if (var_r30_1190 < (MKLevelChunk **) this->unkEC) {
        temp_r3_1195 = *(this->unkD8 + var_r31_1191);
        temp_r0_1196 = M2C_FIELD(temp_r3_1195, s32 *, 0x90);
        if ((temp_r0_1196 == 9) || (temp_r0_1196 == 0xC)) {
            M2C_FIELD(M2C_FIELD(temp_r3_1195, void **, 8), M2C_UNK (**)(s32), 0x34)(arg0);
        }
        var_r30_1190 += 1;
        var_r31_1191 += 4;
        goto loop_5;
    }
}
#endif

#if 0 // DRAFT: type mismatch
void MKChunkSceneManager::DrawProps(int arg0) {
    s32 temp_r0_1236;
    s32 var_r30_1230;
    s32 var_r31_1231;
    void *temp_r3_1235;

    var_r30_1230 = 0;
    var_r31_1231 = 0;
loop_5:
    if (var_r30_1230 < (MKLevelChunk **) this->unkEC) {
        temp_r3_1235 = *(this->unkD8 + var_r31_1231);
        temp_r0_1236 = M2C_FIELD(temp_r3_1235, s32 *, 0x90);
        if ((temp_r0_1236 == 9) || (temp_r0_1236 == 0xC)) {
            M2C_FIELD(M2C_FIELD(temp_r3_1235, void **, 8), M2C_UNK (**)(s32), 0x38)(arg0);
        }
        var_r30_1230 += 1;
        var_r31_1231 += 4;
        goto loop_5;
    }
}
#endif

#if 0 // DRAFT: type mismatch
void MKChunkSceneManager::UpdateState() {
    s32 var_r30_1272;
    s32 var_r31_1273;
    void *temp_r3_1284;

    if ((u8) this->unkE4 != 0) {
        var_r30_1272 = 0;
        var_r31_1273 = 0;
loop_3:
        if (var_r30_1272 < (MKLevelChunk **) this->unkEC) {
            SetWorkingChunk(*(this->unkE8 + var_r31_1273));
            temp_r3_1284 = *(this->unkE8 + var_r31_1273);
            M2C_FIELD(M2C_FIELD(temp_r3_1284, void **, 8), M2C_UNK (**)(void *), 0x18)(temp_r3_1284);
            SetWorkingChunk(0);
            var_r30_1272 += 1;
            var_r31_1273 += 4;
            goto loop_3;
        }
    }
}
#endif

#if 0 // DRAFT: type mismatch
void MKChunkSceneManager::Update() {
    s32 temp_r0_1327;
    s32 var_r30_1321;
    s32 var_r31_1322;
    void *temp_r29_1326;

    CalculateUpdateDistances();
    var_r30_1321 = 0;
    var_r31_1322 = 0;
loop_5:
    if (var_r30_1321 < (MKLevelChunk **) this->unkEC) {
        temp_r29_1326 = *(this->unkDC + var_r31_1322);
        temp_r0_1327 = M2C_FIELD(temp_r29_1326, s32 *, 0x90);
        if ((temp_r0_1327 == 9) || (temp_r0_1327 == 0xC)) {
            SetWorkingChunk(temp_r29_1326);
            M2C_FIELD(M2C_FIELD(temp_r29_1326, void **, 8), M2C_UNK (**)(void *), 0x30)(temp_r29_1326);
            SetWorkingChunk(NULL);
        }
        var_r30_1321 += 1;
        var_r31_1322 += 4;
        goto loop_5;
    }
}
#endif

#if 0 // DRAFT: illegal operand
void MKChunkSceneManager::SetChunkDrawOrder(MKLevelChunk **arg0) {
    MKLevelChunk **var_r4_0;
    MKLevelChunk *temp_r0_1375;
    s32 var_r5_1367;

    var_r4_0 = arg0;
    var_r5_1367 = 0;
loop_2:
    temp_r0_1375 = *var_r4_0;
    if (temp_r0_1375 != NULL) {
        var_r4_0 += 4;
        *(this->unkD8 + var_r5_1367) = temp_r0_1375;
        var_r5_1367 += 4;
        goto loop_2;
    }
}
#endif

#if 0 // DRAFT: illegal type
void MKChunkSceneManager::SetChunkUpdateOrder(MKLevelChunk **arg0) {
    MKLevelChunk **var_r4_0;
    MKLevelChunk *temp_r0_1392;
    s32 var_r5_1384;

    var_r4_0 = arg0;
    var_r5_1384 = 0;
loop_2:
    temp_r0_1392 = *var_r4_0;
    if (temp_r0_1392 != NULL) {
        var_r4_0 += 4;
        *(this->unkDC + var_r5_1384) = temp_r0_1392;
        var_r5_1384 += 4;
        goto loop_2;
    }
}
#endif

void MKChunkSceneManager::ResetAll() {

}

void MKChunkSceneManager::Optimise() {
    this->unk19 = 1;
}

#if 0 // DRAFT: type mismatch
void MKChunkSceneManager::Deinit() {
    MKHeap *temp_r29_1521;
    MKLevelChunk **var_r3_1478;
    s32 temp_r29_1504;
    s32 var_r30_1422;
    s32 var_r30_1451;
    s32 var_r30_1481;
    void *temp_r29_1535;
    void *temp_r3_1433;
    void *temp_r3_1462;
    void *temp_r3_1485;
    void *var_r28_1421;
    void *var_r28_1450;
    void *var_r28_1480;

    var_r28_1421 = this->unkEC - 1;
    var_r30_1422 = (s32) var_r28_1421 * 4;
loop_2:
    if (var_r28_1421 >= 0) {
        SetWorkingChunk(*(this->unkE8 + var_r30_1422));
        temp_r3_1433 = *(this->unkE8 + var_r30_1422);
        M2C_FIELD(M2C_FIELD(temp_r3_1433, void **, 8), M2C_UNK (**)(void *), 0x58)(temp_r3_1433);
        SetWorkingChunk(0);
        var_r28_1421 -= 1;
        var_r30_1422 -= 4;
        goto loop_2;
    }
    var_r28_1450 = this->unkEC - 1;
    var_r30_1451 = (s32) var_r28_1450 * 4;
loop_5:
    if (var_r28_1450 >= 0) {
        SetWorkingChunk(*(this->unkE8 + var_r30_1451));
        temp_r3_1462 = *(this->unkE8 + var_r30_1451);
        M2C_FIELD(M2C_FIELD(temp_r3_1462, void **, 8), M2C_UNK (**)(void *), 0x10)(temp_r3_1462);
        SetWorkingChunk(0);
        var_r28_1450 -= 1;
        var_r30_1451 -= 4;
        goto loop_5;
    }
    var_r3_1478 = this->unkEC;
    var_r28_1480 = var_r3_1478 - 1;
    var_r30_1481 = (s32) var_r28_1480 * 4;
loop_10:
    if (var_r28_1480 >= 0) {
        temp_r3_1485 = *(this->unkE8 + var_r30_1481);
        if (temp_r3_1485 != NULL) {
            M2C_FIELD(M2C_FIELD(temp_r3_1485, void **, 8), M2C_UNK (**)(M2C_UNK), 8)(1);
        }
        var_r3_1478 = (MKLevelChunk **) this->unkE8;
        var_r28_1480 -= 1;
        *(var_r3_1478 + var_r30_1481) = 0;
        var_r30_1481 -= 4;
        goto loop_10;
    }
    ((MKSceneManager *) var_r3_1478)->PropResolver_Deinit();
    this->unk19 = 0;
    temp_r29_1504 = this->unkE8;
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free((void *) temp_r29_1504, NULL, 0);
    } else {
        free(temp_r29_1504);
    }
    this->unkE8 = 0;
    this->unkE4 = 0;
    temp_r29_1521 = this->unkD8;
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(temp_r29_1521, NULL, 0);
    } else {
        free((s32) temp_r29_1521);
    }
    temp_r29_1535 = this->unkDC;
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(temp_r29_1535, NULL, 0);
    } else {
        free((s32) temp_r29_1535);
    }
    MKSceneManager::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'unk34'
void MKChunkSceneManager::Init(MKSceneManagerInit *arg0) {
    s32 spC;
    u8 sp8;
    MKHeap *var_r3_1624;
    s32 temp_r26_1600;
    s32 temp_r26_1616;
    s32 temp_r26_1632;
    s32 temp_r4_1706;
    s32 temp_r5_1663;
    s32 var_r27_1651;
    s32 var_r28_1650;
    s32 var_r31_1649;
    void *(*var_r0_1585)(MKDistanceLevelChunk *, s8 *);
    void *temp_r25_1654;
    void *temp_r3_1672;
    void *temp_r3_1689;
    void *temp_ret_1662;
    void *var_r3_1608;
    void *var_r3_1640;
    s8 *phi_r4_18;

    MKSceneManager::Init(arg0);
    if (((MKLevelChunk **) arg0->unk34 == (MKLevelChunk **)2) || (System_GetCommandLineParameter("enginechunks", 0U), (((u32) M2C_ERROR(/* Read from unset register $r3 */) == 0U) == 0))) {
        *MKChunkSceneManager::bChunksUseHeaps = 0;
    } else {
        *MKChunkSceneManager::bChunksUseHeaps = 1;
    }
    var_r0_1585 = arg0->unkCC;
    if (var_r0_1585 != NULL) {

    } else {
        var_r0_1585 = &MKDistanceLevelChunk::ChunkCreator;
    }
    this->unkE0 = var_r0_1585;
    ((MKSceneManager *) (M2C_ERROR(/* Read from unset register $r3 */)))->PropResolver_Init();
    this->unkEC = arg0->unk34;
    this->unkA8 = -1;
    temp_r26_1600 = (s32) this->unkEC * 4;
    if (MKHeap::Current() != NULL) {
        var_r3_1608 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r26_1600, NULL, 0);
    } else {
        var_r3_1608 = malloc(temp_r26_1600);
    }
    this->unkE8 = (s32) var_r3_1608;
    temp_r26_1616 = (s32) this->unkEC * 4;
    if (MKHeap::Current() != NULL) {
        var_r3_1624 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r26_1616, NULL, 0);
    } else {
        var_r3_1624 = malloc(temp_r26_1616);
    }
    this->unkD8 = var_r3_1624;
    temp_r26_1632 = (s32) this->unkEC * 4;
    if (MKHeap::Current() != NULL) {
        var_r3_1640 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r26_1632, NULL, 0);
    } else {
        var_r3_1640 = malloc(temp_r26_1632);
    }
    this->unkDC = var_r3_1640;
    var_r31_1649 = 0;
    var_r28_1650 = 0;
    var_r27_1651 = 0;
    phi_r4_18 = "enginechunks";
loop_18:
    if (var_r31_1649 < (MKLevelChunk **) this->unkEC) {
        temp_r25_1654 = arg0 + var_r27_1651;
        sp8 = M2C_FIELD(temp_r25_1654, u8 *, 0x4C);
        spC = M2C_FIELD(temp_r25_1654, s32 *, 0x50);
        temp_ret_1662 = this->unkE0(NULL, phi_r4_18);
        temp_r5_1663 = this->unkE8;
        *(temp_r5_1663 + var_r28_1650) = temp_ret_1662;
        temp_r3_1672 = *(this->unkE8 + var_r28_1650);
        M2C_FIELD(M2C_FIELD(temp_r3_1672, void **, 8), M2C_UNK (**)(void *, s32, s32, s32, s32, s8 *), 0xC)(temp_r3_1672, M2C_FIELD(temp_r25_1654, s32 *, 0x3C), M2C_FIELD(temp_r25_1654, s32 *, 0x40), M2C_FIELD(temp_r25_1654, s32 *, 0x48), M2C_FIELD(temp_r25_1654, s32 *, 0x44), Str_Printf("Chunk%d", var_r31_1649, temp_r5_1663, M2C_BITWISE(f32, temp_ret_1662)));
        SetWorkingChunk(*(this->unkE8 + var_r28_1650));
        temp_r3_1689 = *(this->unkE8 + var_r28_1650);
        M2C_FIELD(M2C_FIELD(temp_r3_1689, void **, 8), M2C_UNK (**)(void *, u8 *), 0x54)(temp_r3_1689, &sp8);
        SetWorkingChunk(0);
        var_r31_1649 += 1;
        var_r27_1651 += 0x18;
        *(this->unkD8 + var_r28_1650) = *(this->unkE8 + var_r28_1650);
        temp_r4_1706 = this->unkE8;
        *(this->unkDC + var_r28_1650) = *(temp_r4_1706 + var_r28_1650);
        var_r28_1650 += 4;
        phi_r4_18 = (s8 *) temp_r4_1706;
        goto loop_18;
    }
    this->unkF4 = NULL;
    this->unkE4 = 1;
}
#endif
