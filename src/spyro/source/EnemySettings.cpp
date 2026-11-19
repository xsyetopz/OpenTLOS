#include "spyro/source/EnemySettings.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/CustomMaterialUpdater.h"
#include "spyro/source/Level.h"
#include "unplaced_enums.h"
#include "spyro/source/DataMap.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(s32);                                  /* extern */
extern M2C_UNK gb;
extern s32 iLevels;
extern void *pLevelSettings;
#if 0 // DRAFT: illegal use of incomplete struct/union/class 'DataMap'
static DataMap estDataMap[0xA] = {
    { 0, "Health" },
    { 1, "Armour" },
    { 2, "DefensiveMax" },
    { 3, "DefensiveHitWeight" },
    { 4, "DefensiveDecayRate" },
    { 5, "AttackDamage" },
    { 6, "AttackDelay" },
    { 7, "AttackDefensiveThreshold" },
    { 8, "AttackDefensivePenalty" },
    { 9, NULL },
};
#endif
static f32 baselineSettings[9];
#if 0 // DRAFT: illegal use of incomplete struct/union/class '_struct_ddaSettings_0x24'
static struct _struct_ddaSettings_0x24 ddaSettings[5];
#endif
static s32 iEnemyDDALevel = 2;
static M2C_UNK lit_618;                                /* unable to generate initializer: unknown type; const */

void EnemySettings_UnregisterSettings(EnemySettings *arg0) {

}

void EnemySettings_RegisterSettings(const char *arg0, EnemySettings *arg1) {

}

#if 0 // DRAFT: illegal type
f32 EnemySettings_GetEnemySetting(EnemySettingType arg0) {
    f32 var_f1_28;
    s32 *var_r3_36;
    s32 temp_r5_25;
    void *temp_r4_33;

    temp_r5_25 = (s32) arg0 * 4;
    var_f1_28 = baselineSettings[(s32) arg0];
    if ((void *) pLevelSettings != NULL) {
        temp_r4_33 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x32C), void **, 0x18);
        if (temp_r4_33 != NULL) {
            var_r3_36 = M2C_FIELD(temp_r4_33, s32 **, 4);
        } else {
            var_r3_36 = M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x32C), void **, 0x24), s32 **, 4);
        }
        var_f1_28 *= *(pLevelSettings + ((*var_r3_36 * 0x24) + temp_r5_25));
    }
    return var_f1_28 * *(&ddaSettings[iEnemyDDALevel] + temp_r5_25);
}
#endif

#if 0 // DRAFT: undefined identifier 'ddaSettings'
void EnemySettings_ParseDDASettings(MKIniLine *arg0) {
    s32 sp8;
    MKIniLine *var_r30_67;

    var_r30_67 = arg0;
    sp8 = 0;
loop_5:
    if (var_r30_67 != NULL) {
        if ((var_r30_67->IsSection("DDA") != 0) || (var_r30_67->IsField("DDA") != 0)) {
            var_r30_67 = var_r30_67->unkC->GetSubLine(var_r30_67);
        } else {
            var_r30_67 = var_r30_67->unkC->GetNextLine(var_r30_67);
            goto loop_5;
        }
    }
loop_10:
    if (var_r30_67 != NULL) {
        if (var_r30_67->LoadInt("difficulty", (int *) &sp8, 0) != 0) {
            ((EnemySettings *) &ddaSettings[sp8])->LoadLine(var_r30_67->unkC->GetSubLine(var_r30_67));
        }
        var_r30_67 = var_r30_67->unkC->GetNextLine(var_r30_67);
        goto loop_10;
    }
}
#endif

void EnemySettings_ParseLevelSettings(MKIniLine *arg0, const char *arg1, EnemySettings *arg2) {
    MKIniLine *var_r28_141;

    var_r28_141 = arg0;
loop_5:
    if (var_r28_141 == NULL) {

    } else if ((var_r28_141->IsSection("level") != 0) || (var_r28_141->IsField("level") != 0)) {
        var_r28_141 = var_r28_141->unkC->GetSubLine(var_r28_141);
    } else {
        var_r28_141 = var_r28_141->unkC->GetNextLine(var_r28_141);
        goto loop_5;
    }
loop_11:
    if (var_r28_141 == NULL) {
        return;
    }
    if ((var_r28_141->IsSection(arg1) != 0) || (var_r28_141->IsField(arg1) != 0)) {
        arg2->LoadLine(var_r28_141->unkC->GetSubLine(var_r28_141));
        return;
    }
    var_r28_141 = var_r28_141->unkC->GetNextLine(var_r28_141);
    goto loop_11;
}

void EnemySettings_ParseBaselineSettings(MKIniLine *arg0) {
    MKIniLine *var_r30_215;

    var_r30_215 = arg0;
loop_5:
    if (var_r30_215 == NULL) {
        return;
    }
    if ((var_r30_215->IsSection("baseline") != 0) || (var_r30_215->IsField("baseline") != 0)) {
        ((EnemySettings *) baselineSettings)->LoadLine(var_r30_215->unkC->GetSubLine(var_r30_215));
        return;
    }
    var_r30_215 = var_r30_215->unkC->GetNextLine(var_r30_215);
    goto loop_5;
}

void EnemySettings_ParseEnemyDDALevel(MKIniLine *arg0) {
    MKIniLine *var_r30_262;

    var_r30_262 = arg0;
loop_5:
    if (var_r30_262 == NULL) {
        return;
    }
    if ((var_r30_262->IsSection("EnemyDDALevel") != 0) || (var_r30_262->IsField("EnemyDDALevel") != 0)) {
        iEnemyDDALevel = var_r30_262->GetInt(0);
        return;
    }
    var_r30_262 = var_r30_262->unkC->GetNextLine(var_r30_262);
    goto loop_5;
}

#if 0 // DRAFT: illegal type
void EnemySettings_ParseIniFile(const char *arg0) {
    MKIni sp8;
    MKIniLine *temp_r3_317;
    s32 var_r30_324;
    s32 var_r31_325;

    if (MKIni::Exists(arg0) != 0) {
        MKHeap::ActivateTempMemOverride();
        sp8.Init(arg0, 0, NULL);
        MKHeap::DeactivateTempMemOverride();
        temp_r3_317 = sp8.GetFirstLine();
        EnemySettings_ParseEnemyDDALevel(temp_r3_317);
        EnemySettings_ParseBaselineSettings(temp_r3_317);
        EnemySettings_ParseDDASettings(temp_r3_317);
        var_r30_324 = 0;
        var_r31_325 = 0;
loop_3:
        if (var_r30_324 < (s32) iLevels) {
            EnemySettings_ParseLevelSettings(temp_r3_317, M2C_FIELD(Level::GetLevelInfo(var_r30_324), s8 **, 4), pLevelSettings + var_r31_325);
            var_r30_324 += 1;
            var_r31_325 += 0x24;
            goto loop_3;
        }
        MKHeap::ActivateTempMemOverride();
        sp8.Deinit();
        MKHeap::DeactivateTempMemOverride();
    }
}
#endif

void EnemySettings_DeinitModule() {
    void *temp_r31_369;

    temp_r31_369 = pLevelSettings;
    if (temp_r31_369 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_369, NULL, 0);
        } else {
            free(temp_r31_369);
        }
    }
    pLevelSettings = NULL;
}

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to 'const char *'
void EnemySettings_InitModule() {
    s8 sp8;
    M2C_UNK sp4;
    s32 temp_r30_439;
    s32 var_r29_458;
    s32 var_r29_472;
    s32 var_r31_459;
    s32 var_r31_474;
    void *temp_r4_405;
    void *var_r3_447;

    temp_r4_405 = &lit_618 - 4;
    M2C_STRUCT_COPY((s32) &sp4 + 4, (s32) ((u8 *) temp_r4_405) + 4, 0x10);
    M2C_FIELD((&sp4 + 0x10), u16 *, 4) = (u16) M2C_FIELD((((u8 *) temp_r4_405) + 0x10), u16 *, 4);
    iLevels = Level::GetLevelCount();
    pLevelSettings = NULL;
    memset(baselineSettings, 0, 0x24U);
    memset(ddaSettings, 0, 0xB4U);
    if ((s32) iLevels != 0) {
        if (MKIni::Exists(&sp8) == 0) {
            return;
        }
        temp_r30_439 = iLevels * 0x24;
        if (MKHeap::Current() != NULL) {
            var_r3_447 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r30_439, NULL, 0);
        } else {
            var_r3_447 = malloc(temp_r30_439);
        }
        pLevelSettings = var_r3_447;
        memset(var_r3_447, 0, iLevels * 0x24);
        var_r29_458 = 0;
        var_r31_459 = 0;
loop_8:
        if (var_r29_458 < (s32) iLevels) {
            ((EnemySettings *) (pLevelSettings + var_r31_459))->InitToOne();
            var_r29_458 += 1;
            var_r31_459 += 0x24;
            goto loop_8;
        }
        var_r29_472 = 0;
        var_r31_474 = 0;
        do {
            ((EnemySettings *) (ddaSettings + var_r31_474))->InitToOne();
            var_r29_472 += 1;
            var_r31_474 += 0x24;
        } while (var_r29_472 < 5);
        EnemySettings_ParseIniFile(&sp8);
    }
}
#endif

#if 0 // DRAFT: function call 'DataMap_GetName(signed char[10], unsigned long)' does not match 'DataMap_GetName(const DataMap *, unsigned int)'
void EnemySettings::LoadLine(MKIniLine *arg0) {
    MKIniLine *var_r28_508;
    s32 var_r31_513;
    u32 var_r29_512;

    var_r28_508 = arg0;
loop_5:
    if (var_r28_508 != NULL) {
        var_r29_512 = 0;
        var_r31_513 = 0;
loop_2:
        if (var_r28_508->LoadFloat(DataMap_GetName(estDataMap, var_r29_512), (f32 *) &this[var_r31_513], 0) == 0) {
            var_r29_512 += 1;
            var_r31_513 += 4;
            if ((s32) var_r29_512 < 9) {
                goto loop_2;
            }
        }
        var_r28_508 = var_r28_508->unkC->GetNextLine(var_r28_508);
        goto loop_5;
    }
}
#endif

#if 0 // DRAFT: illegal operand
void EnemySettings::InitToOne() {
    s32 var_ctr_550;
    s32 var_r4_549;

    var_r4_549 = 0;
    var_ctr_550 = 9;
    do {
        this[var_r4_549] = 1.0f;
        var_r4_549 += 4;
        var_ctr_550 -= 1;
    } while (var_ctr_550 != 0);
}
#endif
