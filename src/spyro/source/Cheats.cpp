#include "spyro/source/Cheats.h"
#include "common/Source/MKInput.h"
#include "common/Source/MKWidgetsInternal.h"
#include "common/Source/MKSystem.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

extern s32 GS_CheatDisable;
extern s32 GS_CheatEnabled;
extern M2C_UNK gb;
extern MKInputReceiver *pReceiver;
static M2C_UNK cheats;                              /* unable to generate initializer: unknown type */
static s32 cheatCount = 3;

void Cheats_Deinit() {
    MKInputReceiver_Destroy(pReceiver);
    pReceiver = NULL;
}

#if 0 // DRAFT: undefined identifier 'CheatReceiver'
void Cheats_Init() {
    pReceiver = MKInputReceiver_Create((u8 (*)(MKInputEvent *, void *)) CheatReceiver, 0x3C, 2, NULL);
}
#endif

#if 0 // DRAFT: illegal type
s32 CheatReceiver(MKInputEvent *arg0, void *arg1) {
    M2C_UNK (*temp_r12_93)(M2C_UNK);
    s32 *temp_r7_66;
    s32 temp_r6_155;
    s32 temp_r6_81;
    s32 var_ctr_144;
    s32 var_ctr_56;
    s32 var_r3_114;
    s32 var_r3_126;
    s32 var_r3_140;
    s32 var_r4_55;
    u8 *temp_r3_105;
    void *temp_r8_80;

    if ((s32) arg0->unk0 != 2) {

    } else {
        var_r4_55 = 0;
        var_ctr_56 = cheatCount;
        if ((s32) cheatCount > 0) {
loop_3:
            if ((((u8) arg0->unkC == 0) || (temp_r7_66 = &cheats + var_r4_55, (((s32) M2C_FIELD(arg0, s32 *, 8) == (s32) *(temp_r7_66 + ((*temp_r7_66 * 4) + 0xC))) == 0))) && ((u8) arg0->unkD != 0)) {
                temp_r8_80 = &cheats + var_r4_55;
                temp_r6_81 = M2C_FIELD(temp_r8_80, s32 *, 0);
                if ((s32) M2C_FIELD(arg0, s32 *, 8) == (s32) *(temp_r8_80 + ((temp_r6_81 * 4) + 0xC))) {
                    M2C_FIELD(temp_r8_80, s32 *, 0) = (s32) (temp_r6_81 + 1);
                    if ((s32) M2C_FIELD(temp_r8_80, s32 *, 0) >= (s32) M2C_FIELD(temp_r8_80, s32 *, 4)) {
                        temp_r12_93 = M2C_FIELD(temp_r8_80, M2C_UNK (**)(M2C_UNK), 8);
                        if (temp_r12_93 != NULL) {
                            temp_r12_93(0);
                            KDSound_Play(GS_CheatEnabled, 0U, -1);
                        } else {
                            temp_r3_105 = M2C_FIELD(temp_r8_80, u8 **, 0x48);
                            if (temp_r3_105 != NULL) {
                                *temp_r3_105 = *temp_r3_105 == 0;
                                var_r3_114 = GS_CheatDisable;
                                if ((u8) *M2C_FIELD(temp_r8_80, u8 **, 0x48) != 0) {
                                    var_r3_114 = GS_CheatEnabled;
                                }
                                KDSound_Play(var_r3_114, 0U, -1);
                            } else {
                                var_r3_126 = GS_CheatDisable;
                                M2C_FIELD(temp_r8_80, u8 *, 0x4C) = (u8) (M2C_FIELD(temp_r8_80, u8 *, 0x4C) == 0);
                                if ((u8) M2C_FIELD(temp_r8_80, u8 *, 0x4C) != 0) {
                                    var_r3_126 = GS_CheatEnabled;
                                }
                                KDSound_Play(var_r3_126, 0U, -1);
                            }
                        }
                        var_r3_140 = 0;
                        var_ctr_144 = cheatCount;
                        if ((s32) cheatCount > 0) {
                            do {
                                *(&cheats + var_r3_140) = 0;
                                var_r3_140 += 0x50;
                                var_ctr_144 -= 1;
                            } while (var_ctr_144 != 0);
                        }
                    } else {
                        goto block_22;
                    }
                } else {
                    M2C_FIELD(temp_r8_80, s32 *, 0) = 0;
                    temp_r6_155 = M2C_FIELD(temp_r8_80, s32 *, 0);
                    if ((s32) M2C_FIELD(arg0, s32 *, 8) == (s32) *(temp_r8_80 + ((temp_r6_155 * 4) + 0xC))) {
                        M2C_FIELD(temp_r8_80, s32 *, 0) = (s32) (temp_r6_155 + 1);
                    }
                    goto block_22;
                }
            } else {
block_22:
                var_r4_55 += 0x50;
                var_ctr_56 -= 1;
                if (var_ctr_56 != 0) {
                    goto loop_3;
                }
            }
        }
    }
    return 1;
}
#endif

void Cheats_CheckCommandLineParameters() {
    u8 var_r3_188;
    u8 var_r4_207;

    System_GetCommandLineParameter("infiniteMagic", 0U);
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        var_r3_188 = 1;
    } else {
        var_r3_188 = M2C_FIELD(&gb, u8 *, 0x3B5);
    }
    M2C_FIELD(&gb, u8 *, 0x3B5) = (u8) (var_r3_188 != 0);
    System_GetCommandLineParameter("invincible", 0U);
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        var_r4_207 = 1;
    } else {
        var_r4_207 = M2C_FIELD(&gb, u8 *, 0x3B4);
    }
    M2C_FIELD(&gb, u8 *, 0x3B4) = (u8) (var_r4_207 != 0);
}

#if 0 // DRAFT: undefined identifier 'gameData'
void LotsOfLevelUps(void *arg0) {
    gameData.unk88.SetValue(23000.0f, 0U);
}
#endif
