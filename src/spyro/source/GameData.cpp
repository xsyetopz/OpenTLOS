#include "spyro/source/GameData.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMemoryCard.h"
#include "spyro/source/CameraData.h"
#include "spyro/source/Level.h"
#include "common/Source/MKRumble.h"
#include "common/Source/MKSystem.h"
#include "common/Source/Timer.h"
#include "common/gc/Sound_GC.h"
#include "common/gc/System_GC.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern f32 gUpdateTimeDelta;
extern void **gb;
extern void *pLoadChunkInfo;
#if 0 // DRAFT: illegal use of incomplete struct/union/class '_struct_breathColors_0x10'
static M2C_UNK coverEffects;                        /* unable to generate initializer: unknown type */
static struct _struct_breathColors_0x10 breathColors[4] = { { 0.0, 0.0 }, { 0.0, 0.0 }, { 0.0, 0.0 }, { 0.0, 0.0 } };
#endif
#if 0 // DRAFT: illegal use of incomplete struct/union/class '_struct_breathShot_0x8'
static struct _struct_breathShot_0x8 breathShot[4]; /* unable to generate initializer: non-zero padding */
static struct _struct_breathCost_0x10 breathCost[4]; /* unable to generate initializer: non-zero padding */
static struct _struct_breathDamage_0x20 breathDamage[4]; /* unable to generate initializer: non-zero padding */
u8 gameData__8GameData[0x1B4];
#endif

static s32 lit_829 = 0;

void GameData::CopyToGameData(void *arg0) {
    M2C_UNK sp18;
    M2C_UNK sp8;
    s32 temp_r0_43;
    s32 var_ctr_21;
    s32 var_ctr_39;
    s32 var_r3_20;
    s32 var_r3_37;
    s32 var_r4_38;
    s32 var_r5_13;
    u8 var_r30_66;
    void *temp_r8_42;
    void *temp_r9_23;

    var_r5_13 = 0;
    var_r3_20 = 0;
    var_ctr_21 = 4;
    do {
        temp_r9_23 = this + var_r5_13;
        var_r5_13 += 0x18;
        *(&sp18 + var_r3_20) = M2C_FIELD(temp_r9_23, s32 *, 0x80);
        *(&sp8 + var_r3_20) = M2C_FIELD(temp_r9_23, s32 *, 0x84);
        var_r3_20 += 4;
        var_ctr_21 -= 1;
    } while (var_ctr_21 != 0);
    memcpy(this, arg0, 0x1B0U);
    var_r3_37 = 0;
    var_r4_38 = 0;
    var_ctr_39 = 4;
    do {
        temp_r8_42 = this + var_r3_37;
        temp_r0_43 = *(&sp8 + var_r4_38);
        var_r3_37 += 0x18;
        M2C_FIELD(temp_r8_42, s32 *, 0x80) = (s32) *(&sp18 + var_r4_38);
        var_r4_38 += 4;
        M2C_FIELD(temp_r8_42, s32 *, 0x84) = temp_r0_43;
        var_ctr_39 -= 1;
    } while (var_ctr_39 != 0);
    if (Sound_GetSystemAudioMode() != 0) {
        GetGameSettings();
        Sound_SetSystemAudioMode(M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC));
    }
    GetGameSettings();
    KDSound_SetMasterMusicVolume(M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 8));
    GetGameSettings();
    KDSound_SetMasterSoundVolume(M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 4));
    var_r30_66 = 0;
    if ((s32) M2C_FIELD(&gb, s32 *, 0x350) != 0) {
        GetGameSettings();
        if ((u8) M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), u8 *, 0x12) != 0) {
            var_r30_66 = 1;
        }
    }
    MKRumble_Enable(var_r30_66);
    GetGameSettings();
    Tools_EnableWideScreen(M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), u8 *, 0x11));
    pLoadChunkInfo = this->unk190.GetChunkByName(M2C_ERROR(/* Read from unset register $r4 */));
}

void GameData::CopyFromGameData(void *arg0) {
    memcpy(arg0, this, 0x1B0U);
}

s32 GameData::GetGameDataSize() {
    return 0x1B0;
}

#if 0 // DRAFT: undefined identifier 'unk0'
void GameData::UpdateDataHeader(void *arg0) {
    Timer_GetSystemTime(&this->unk0);
    if (arg0 != NULL) {
        memcpy(arg0, this, 0x1CU);
    }
}
#endif

void GameData::GetSaveGameDescription() {
    TimerInfo sp8;

    Timer_GetSystemTime(&sp8);
    Tools_GetDateString(&sp8);
}

CameraData *GameData::GetCameraData() {
    return &this->unk60;
}

void GameData::GetGameSettings() {

}

#if 0 // DRAFT: illegal use of non-static member
void GameData::ClearData() {
    GameData::SaveState::ClearData();
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void GameData::Deinit() {
    GameData::SaveState::Deinit();
    M2C_FIELD(this, s8 *, 0x1B0) = 0;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void GameData::Init() {
    GameData::SaveState::Init();
    M2C_FIELD(this, s8 *, 0x1B0) = 1;
}
#endif

void GameData::ModuleDeinit() {
    ((GameData *) ((GameData *) GameData::gameData))->Deinit();
    *GameData::bModuleInitialised = 0;
}

void GameData::ModuleInit() {
    ((GameData *) ((GameData *) GameData::gameData))->Init();
    *GameData::bModuleInitialised = 1;
}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
GameData::GameData() {
    M2C_FIELD(this, s8 *, 0x1B0) = 0;
    ClearData();
    return this;
}
#endif

#if 0 // DRAFT: function call 'strcpy(signed char *, signed char *)' does not match
void GameData::SetSaveChunk(ChunkInfo *arg0) {
    strcpy((s8 *) &this->unk190, arg0->unk0);
    strcpy(&this->unk20, (s8 *) &this->unk190);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk0'
void GameData::SaveState::ClearData() {
    memset(this, 0, 0x40U);
    ((GameStats *) ((GameStats *) (this + 0x70)))->Clear();
    if ((s8 **) M2C_FIELD(&gb, s8 ***, 0x330) != NULL) {
        strcpy(&(this + 0x190)->unk0, *M2C_FIELD(&gb, s8 ***, 0x330));
        strcpy(&(this + 0x20)->unk0, &(this + 0x190)->unk0);
    }
}
#endif

void GameData::SaveState::Deinit() {
    ((CameraData *) ((CameraData *) (this + 0x60)))->Deinit();
}

void GameData::SaveState::Init() {
    ((GameSettings *) ((GameSettings *) (this + 0x40)))->Init();
    ((CameraData *) ((CameraData *) (this + 0x60)))->Init();
    ((GameStats *) ((GameStats *) (this + 0x70)))->Init();
    memset(this + 0x190, 0, 0x20U);
}

#if 0 // DRAFT: illegal operand
void GameStats::SetAttacksAvailable(unsigned int arg0) {
    s32 temp_r6_382;
    s32 var_ctr_375;
    s32 var_r8_373;

    var_r8_373 = 0;
    var_ctr_375 = 0x10;
    do {
        if (arg0 & (1 << var_r8_373)) {
            temp_r6_382 = ((var_r8_373 * 8) & 0x60) + 0x60;
            *(this + temp_r6_382) = *(this + temp_r6_382) | (1 << (var_r8_373 & 3));
        }
        var_r8_373 += 1;
        var_ctr_375 -= 1;
    } while (var_ctr_375 != 0);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
f32 GameStats::GetBreathAttackDamage(int arg0, int arg1, int arg2) {
    f32 *temp_r3_414;

    if (arg2 == 0) {
        return *(&breathDamage[arg0] + (arg1 * 0x10) + (arg2 * 4));
    }
    temp_r3_414 = &breathDamage[arg0] + (arg1 * 0x10);
    return *temp_r3_414 * *(temp_r3_414 + (arg2 * 4));
}
#endif

#if 0 // DRAFT: illegal operand
s32 GameStats::GetBreathAttackShotType() {
    s32 temp_r6_424;

    temp_r6_424 = this->unkE8;
    return *(&breathShot[temp_r6_424] + (*(this + ((temp_r6_424 << 5) + 0x7C)) * 4));
}
#endif

f32 GameStats::GetSpeedwayBoostCost() {
    return 10.0f * gUpdateTimeDelta;
}

#if 0 // DRAFT: illegal operand
f32 GameStats::GetOngoingBreathCost() {
    s32 temp_r0_449;

    temp_r0_449 = this->unkE8;
    return gUpdateTimeDelta * M2C_FIELD((&breathCost[temp_r0_449] + (*(this + ((temp_r0_449 << 5) + 0x7C)) * 8)), f32 *, 4);
}
#endif

#if 0 // DRAFT: illegal operand
f32 GameStats::GetInitialBreathCost() {
    s32 temp_r6_468;

    temp_r6_468 = this->unkE8;
    return *(&breathCost[temp_r6_468] + (*(this + ((temp_r6_468 << 5) + 0x7C)) * 8));
}
#endif

#if 0 // DRAFT: undefined identifier 'breathColors'
void *GameStats::GetCurrentBreathColor() {
    return &breathColors[this->unkE8];
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'BreathElement'
void GameStats::SetCurrentBreath(BreathElement arg0) {
    this->unkEC = (s32) arg0;
    if (((void **) gb == NULL) || (M2C_FIELD(*gb, u8 (**)(), 0x70)() == 0)) {
        this->unkE8 = (s32) arg0;
    }
}
#endif

f32 GameStats::TailStrikeDamage() {
    return 5.0f;
}

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'StatType'
s32 GameStats::GetGemAvailable(StatType arg0) {
    s32 temp_r5_542;
    void *temp_r6_551;
    void *var_r5_554;

    if (((u8) this->unk11A >> 6U) & 1) {
        return 1;
    }
    temp_r5_542 = 1 << (s32) arg0;
    if (temp_r5_542 == (s32) (temp_r5_542 & this->unkF9)) {
        if ((s32) arg0 == 1) {
            temp_r6_551 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x32C), void **, 0x18);
            if (temp_r6_551 != NULL) {
                var_r5_554 = M2C_FIELD(temp_r6_551, void **, 4);
            } else {
                var_r5_554 = M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x32C), void **, 0x24), void **, 4);
            }
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if ((f32) M2C_FIELD(var_r5_554, s32 *, 0x28) == M2C_FIELD((this + ((s32) arg0 * 0x18)), f32 *, 0xC)) {
                return 0;
            }
            goto block_9;
        }
block_9:
        return 1;
    }
    return 0;
}
#endif

void GameStats::SetLevelUpPoints(int arg0) {
    s32 temp_r5_590;
    s32 var_r4_0;

    var_r4_0 = arg0;
    temp_r5_590 = this->unkF4;
    if ((s32) lit_829 > var_r4_0) {
        var_r4_0 = lit_829;
    }
    this->unkF4 = var_r4_0;
    if (temp_r5_590 <= (s32) this->unkF4) {
        this->unkE4 = 1;
        GameData::gameData[0x18A] |= 0x80;
    }
}

#if 0 // DRAFT: illegal operand
void GameStats::SetEverything() {
    s32 temp_r5_625;
    s32 temp_r8_620;
    s32 var_ctr_622;
    s32 var_r10_621;
    s32 var_r4_615;
    s32 var_r9_613;

    var_r9_613 = 0;
    this->unkF8 = -1;
    var_r4_615 = 0;
    this->unkF9 = 0xFF;
    do {
        temp_r8_620 = var_r4_615 + 0x60;
        var_r10_621 = 0;
        var_ctr_622 = 4;
loop_2:
        temp_r5_625 = 1 << var_r10_621;
        var_r10_621 += 1;
        *(this + temp_r8_620) = *(this + temp_r8_620) | temp_r5_625;
        var_ctr_622 -= 1;
        if (var_ctr_622 != 0) {
            goto loop_2;
        }
        var_r9_613 += 1;
        var_r4_615 += 0x20;
    } while (var_r9_613 < 4);
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void GameStats::Clear() {
    s32 temp_r4_708;
    s32 temp_r7_703;
    s32 var_ctr_705;
    s32 var_r3_698;
    s32 var_r8_696;
    s32 var_r9_704;

    memset(this, 0, 0x120U);
    this->unk11A &= ~0x40;
    this->unk11C = 0;
    this->unkF9 = 1;
    this->unkF8 = 0x21;
    this->unkF0 = 1200.0f;
    Stat::Init(50.0f, 50.0f, NULL, NULL);
    this->unk18.Init(0.0f, 999999.0f, NULL, SpiritChange);
    this->unk30.Init(30.0f, 30.0f, NULL, NULL);
    this->unk48.Init(0.0f, 150.0f, NULL, NULL);
    this->unk11A &= ~0x80;
    System_GetCommandLineParameter("dev", 0U);
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        var_r8_696 = 0;
        this->unkF8 = -1;
        var_r3_698 = 0;
        this->unkF9 = 0xFF;
        do {
            temp_r7_703 = var_r3_698 + 0x60;
            var_r9_704 = 0;
            var_ctr_705 = 4;
loop_3:
            temp_r4_708 = 1 << var_r9_704;
            var_r9_704 += 1;
            *(this + temp_r7_703) = *(this + temp_r7_703) | temp_r4_708;
            var_ctr_705 -= 1;
            if (var_ctr_705 != 0) {
                goto loop_3;
            }
            var_r8_696 += 1;
            var_r3_698 += 0x20;
        } while (var_r8_696 < 4);
    }
    this->unkE6 = 0;
}
#endif

#if 0 // DRAFT: illegal type
void GameStats::LoadIni() {
    M2C_UNK *sp68;
    void *sp64;
    void *sp60;
    void *sp5C;
    f32 *sp58;
    MKIni sp8;
    MKIniLine *temp_r3_765;
    MKIniLine *temp_r3_788;
    MKIniLine *var_r15_808;
    MKIniLine *var_r16_794;
    MKIniLine *var_r18_770;
    MKIniLine *var_r20_748;
    f32 *temp_r14_790;
    s32 var_r17_775;
    s32 var_r19_752;
    s32 var_r25_810;
    s32 var_r26_778;
    s32 var_r27_777;
    s32 var_r28_776;
    s32 var_r29_755;
    s32 var_r30_754;
    s32 var_r31_753;

    if (sp8.Init("GameStats.ini", 0, NULL) != 0) {
        var_r20_748 = sp8.GetFirstLine();
        sp60 = &coverEffects + 0x288;
loop_21:
        if (var_r20_748 != NULL) {
            var_r19_752 = 0;
            var_r31_753 = 0;
            var_r30_754 = 0;
            var_r29_755 = 0;
            do {
                if (var_r20_748->IsSection(*(sp60 + var_r29_755)) != 0) {
                    temp_r3_765 = var_r20_748->unkC->GetSubLine(var_r20_748);
                    sp64 = &coverEffects + 0x270;
                    var_r18_770 = temp_r3_765;
loop_18:
                    if (var_r18_770 != NULL) {
                        var_r17_775 = 0;
                        var_r28_776 = 0;
                        var_r27_777 = 0;
                        var_r26_778 = 0;
                        do {
                            if (var_r18_770->IsField(*(sp64 + var_r26_778)) != 0) {
                                temp_r3_788 = var_r18_770->unkC->GetSubLine(var_r18_770);
                                temp_r14_790 = &coverEffects + 0x1B0 + var_r31_753 + var_r28_776;
                                sp5C = &coverEffects + 0x1F0 + var_r30_754 + var_r27_777;
                                var_r16_794 = temp_r3_788;
                                sp58 = temp_r14_790 + 4;
loop_15:
                                if (var_r16_794 != NULL) {
                                    if (var_r16_794->IsField("Upgrades") != 0) {
                                        var_r15_808 = var_r16_794->unkC->GetSubLine(var_r16_794);
                                        var_r25_810 = 0;
                                        sp68 = "Attack1";
loop_13:
                                        if (var_r15_808 != NULL) {
                                            if (var_r15_808->LoadFloat(sp68 + 0x5B, sp5C + var_r25_810, 0) != 0) {
                                                var_r25_810 += 4;
                                            }
                                            var_r15_808 = var_r15_808->unkC->GetNextLine(var_r15_808);
                                            goto loop_13;
                                        }
                                    }
                                    var_r16_794->LoadFloat("InitialCost", temp_r14_790, 0);
                                    var_r16_794->LoadFloat("OngoingCost", sp58, 0);
                                    var_r16_794 = var_r16_794->unkC->GetNextLine(var_r16_794);
                                    goto loop_15;
                                }
                            }
                            var_r17_775 += 1;
                            var_r27_777 += 0x10;
                            var_r26_778 += 4;
                            var_r28_776 += 8;
                        } while (var_r17_775 < 2);
                        var_r18_770 = var_r18_770->unkC->GetNextLine(var_r18_770);
                        goto loop_18;
                    }
                }
                var_r19_752 += 1;
                var_r30_754 += 0x20;
                var_r29_755 += 4;
                var_r31_753 += 0x10;
            } while (var_r19_752 < 4);
            var_r20_748 = var_r20_748->unkC->GetNextLine(var_r20_748);
            goto loop_21;
        }
        sp8.Deinit();
    }
}
#endif

void GameStats::Init() {
    Clear();
    LoadIni();
}

f32 SpiritChange(Stat *arg0, float arg1) {
    f32 temp_f2_938;
    f32 var_f1_0;
    void *temp_r5_918;
    void *var_r4_921;

    var_f1_0 = arg1;
    if (!(((u8) GameData::gameData[0x18A] >> 6U) & 1)) {
        temp_r5_918 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x32C), void **, 0x18);
        if (temp_r5_918 != NULL) {
            var_r4_921 = M2C_FIELD(temp_r5_918, void **, 4);
        } else {
            var_r4_921 = M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x32C), void **, 0x24), void **, 4);
        }
        temp_f2_938 = (var_f1_0 + arg0->unkC) - (f32) M2C_FIELD(var_r4_921, s32 *, 0x28);
        if (temp_f2_938 > 0.0f) {
            var_f1_0 -= temp_f2_938;
        }
    }
    return var_f1_0;
}

void Stat::AdjustPrevious(float arg0) {
    f32 temp_f1_953;
    f32 temp_f2_951;
    f32 temp_f3_952;
    f32 var_f0_959;
    f32 var_f0_964;
    f32 var_f0_983;
    f32 var_f0_988;

    temp_f2_951 = this->unk8;
    temp_f3_952 = this->unk0;
    temp_f1_953 = this->unk4 * arg0;
    if (temp_f2_951 < temp_f3_952) {
        if (temp_f1_953 < 0.0f) {
            var_f0_959 = -temp_f1_953;
        } else {
            var_f0_959 = temp_f1_953;
        }
        var_f0_964 = temp_f2_951 + var_f0_959;
        if (var_f0_964 < temp_f3_952) {

        } else {
            var_f0_964 = temp_f3_952;
        }
        if (var_f0_964 > temp_f2_951) {

        } else {
            var_f0_964 = temp_f2_951;
        }
        this->unk8 = var_f0_964;
        return;
    }
    if (temp_f1_953 < 0.0f) {
        var_f0_983 = -temp_f1_953;
    } else {
        var_f0_983 = temp_f1_953;
    }
    var_f0_988 = temp_f2_951 - var_f0_983;
    if (var_f0_988 < temp_f2_951) {

    } else {
        var_f0_988 = temp_f2_951;
    }
    if (var_f0_988 > temp_f3_952) {

    } else {
        var_f0_988 = temp_f3_952;
    }
    this->unk8 = var_f0_988;
}

void Stat::Add(float arg0, bool arg1) {
    M2C_UNK (*temp_r12_1059)(Stat *);
    f32 (*temp_r12_1022)(Stat *);
    f32 temp_f2_1017;
    f32 temp_f2_1030;
    f32 var_f0_1031;
    f32 var_f1_0;

    var_f1_0 = arg0;
    if (arg1 != 0) {
        temp_f2_1017 = this->unk0;
        if (this->unk8 == temp_f2_1017) {
            this->unk8 = temp_f2_1017;
        }
    }
    temp_r12_1022 = M2C_FIELD(this, f32 (**)(Stat *), 0x14);
    if (temp_r12_1022 != NULL) {
        var_f1_0 = temp_r12_1022(this);
    }
    temp_f2_1030 = this->unk4;
    var_f0_1031 = this->unk0 + var_f1_0;
    if (var_f0_1031 < temp_f2_1030) {

    } else {
        var_f0_1031 = temp_f2_1030;
    }
    if (var_f0_1031 > 0.0f) {

    } else {
        var_f0_1031 = 0.0f;
    }
    this->unk0 = var_f0_1031;
    this->unkC += var_f1_0;
    if (arg1 == 0) {
        this->unk8 = this->unk0;
    }
    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
    if (this->unk0 == this->unk4) {
        temp_r12_1059 = M2C_FIELD(this, M2C_UNK (**)(Stat *), 0x10);
        if (temp_r12_1059 != NULL) {
            temp_r12_1059(this);
        }
    }
}

void Stat::SetValue(float arg0, bool arg1) {
    f32 temp_f0_1076;
    f32 var_f1_0;

    var_f1_0 = arg0;
    temp_f0_1076 = this->unk4;
    if (var_f1_0 < temp_f0_1076) {

    } else {
        var_f1_0 = temp_f0_1076;
    }
    if (var_f1_0 > 0.0f) {

    } else {
        var_f1_0 = 0.0f;
    }
    this->unk0 = var_f1_0;
    if (arg1 == 0) {
        this->unk8 = this->unk0;
    }
}

void Stat::Init(float arg0, float arg1, void (*arg2)(Stat *), float (*arg3)(Stat *, float)) {
    this->unk0 = arg0;
    this->unkC = 0.0f;
    this->unk8 = this->unk0;
    this->unk4 = arg1;
    M2C_FIELD(this, void (**)(Stat *), 0x10) = arg2;
    M2C_FIELD(this, f32 (**)(Stat *, f32), 0x14) = arg3;
}

void GameSettings::Init() {
    s32 var_r3_1133;

    this->unkC = 1;
    this->unk4 = 1.0f;
    this->unk8 = 0.6f;
    System_GetCommandLineParameter("widescreen", 0U);
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        var_r3_1133 = 1;
    } else {
        var_r3_1133 = System_GetWideScreenPreference();
    }
    this->unk11 = (s8) var_r3_1133;
    this->unk18 = 0;
    this->unk1C = 0;
    this->unk12 = 1;
    System_GetCommandLineParameter("invertControllerY", 0U);
    this->unk13 = (M2C_ERROR(/* Read from unset register $r3 */) != 0) != 0;
    System_GetCommandLineParameter("invertCameraX", 0U);
    this->unk14 = (M2C_ERROR(/* Read from unset register $r3 */) != 0) != 0;
    System_GetCommandLineParameter("subtitles", 0U);
    this->unk10 = M2C_ERROR(/* Read from unset register $r3 */) != 0;
    this->unk0 = M2C_FIELD(&gb, f32 *, 0x38C);
}

#if 0 // DRAFT: expression syntax error
void GameData_cpp::__sinit() {
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f0_1223;
    f64 temp_f1_1203;
    f64 temp_f1_1211;
    f64 temp_f3_1191;
    f64 temp_f4_1202;
    f64 temp_f4_1210;
    f64 temp_f8_1193;

    temp_f3_1191 = __frsqrte(2014000.0);
    temp_f8_1193 = __frsqrte(380000.0);
    temp_f4_1202 = 0.5 * temp_f3_1191 * -((2014000.0 * (temp_f3_1191 * temp_f3_1191)) - 3.0);
    temp_f1_1203 = 0.5 * temp_f8_1193 * -((380000.0 * (temp_f8_1193 * temp_f8_1193)) - 3.0);
    temp_f4_1210 = 0.5 * temp_f4_1202 * -((2014000.0 * (temp_f4_1202 * temp_f4_1202)) - 3.0);
    temp_f1_1211 = 0.5 * temp_f1_1203 * -((380000.0 * (temp_f1_1203 * temp_f1_1203)) - 3.0);
    temp_f0_1223 = (f32) (380000.0 * (0.5 * temp_f1_1211 * -((380000.0 * (temp_f1_1211 * temp_f1_1211)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_1210 * -((2014000.0 * (temp_f4_1210 * temp_f4_1210)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_1223;
    ((GameData *) ((GameData *) GameData::gameData))->GameData();
    sp38 = 1.0f;
    sp3C = 0.5f;
    sp40 = 0.2f;
    sp44 = 1.0f;
    sp28 = 1.0f;
    sp2C = 1.0f;
    breathColors->unk0 = (f64) sp38;
    sp30 = 0.3f;
    sp34 = 1.0f;
    sp18 = 0.25f;
    sp1C = 0.25f;
    sp20 = 1.0f;
    sp24 = 1.0f;
    sp8 = 0.0f;
    spC = 1.0f;
    sp10 = 0.0f;
    sp14 = 1.0f;
    breathColors->unk8 = (f64) sp40;
    breathColors[1].unk0 = (f64) sp28;
    breathColors[1].unk8 = (f64) sp30;
    breathColors[2].unk0 = (f64) sp18;
    breathColors[2].unk8 = (f64) sp20;
    breathColors[3].unk0 = (f64) sp8;
    breathColors[3].unk8 = (f64) sp10;
}
#endif
