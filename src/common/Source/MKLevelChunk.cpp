#include "common/Source/MKLevelChunk.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKChunkSceneManager.h"
#include "common/Source/MKCollisionManager.h"
#include "common/Source/MKFFTWater.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "spyro/source/Level.h"
#include "common/Source/FileSys.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKGrass.h"
#include "common/Source/MKPackage.h"
#include "common/Source/MKSystem.h"
#include "common/Source/Str.h"
#include "common/gc/Sound_GC.h"
#include <m2c_macros.h>

M2C_UNK free(u32);                                  /* extern */
u32 malloc(s32);                                    /* extern */
s32 stricmp(s8 *, s8 *);                            /* extern */
u32 strstr(s32, s8 *);                              /* extern */
extern void **gMK;
extern MKHeap gMKDefaults;
#if 0 // DRAFT: illegal use of abstract class ('MKLevelChunk::SetActivePoint(const
static MKLevelChunk idCounter__12MKLevelChunk;      /* type too large by 0x14C; unable to generate initializer: confusing struct layout */
static s8 lit_stringBase0[0x52] = {
    0x73,
    0x66,
    0x78,
    0x5F,
    0x25,
    0x73,
    0x25,
    0x73,
    0,
    0x2E,
    0x67,
    0x73,
    0x62,
    0,
    0x73,
    0x6F,
    0x75,
    0x6E,
    0x64,
    0,
    0x25,
    0x73,
    0x25,
    0x73,
    0x2E,
    0x62,
    0x6E,
    0x69,
    0,
    0x25,
    0x73,
    0x25,
    0x73,
    0,
    0x73,
    0x66,
    0x78,
    0x5F,
    0x25,
    0x73,
    0,
    0x63,
    0x68,
    0x75,
    0x6E,
    0x6B,
    0,
    0x6C,
    0x65,
    0x76,
    0x65,
    0x6C,
    0,
    0x6F,
    0x76,
    0x65,
    0x72,
    0x6C,
    0x61,
    0x79,
    0,
    0x2E,
    0x6D,
    0x64,
    0x6C,
    0,
    0x67,
    0x72,
    0x6F,
    0x75,
    0x6E,
    0x64,
    0,
    0x66,
    0x66,
    0x74,
    0x77,
    0x61,
    0x74,
    0x65,
    0x72,
    0,
}; /* const */

s32 MKLevelChunk::Update_AppLocked() {
    s32 var_r5_43;
    u32 temp_r4_42;

    temp_r4_42 = this->unk138;
    var_r5_43 = 0;
    if (!(temp_r4_42 & 0x40)) {
        if (temp_r4_42 & 0x200) {
            this->unk138 = temp_r4_42 | 0x400;
            var_r5_43 = 0xA;
            this->unk138 &= 0xFFFFF7FF;
            this->unk4 = 0;
        } else {
            var_r5_43 = 9;
            this->unk138 = temp_r4_42 & 0xFFFFFFDF;
            this->unk138 &= 0xFFFFFF7F;
            this->unk138 &= 0xFFFFF7FF;
        }
    }
    return var_r5_43;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkAC'
s32 MKLevelChunk::Update_Release() {
    s32 var_r5_77;
    u32 temp_r4_81;

    var_r5_77 = 0;
    temp_r4_81 = this->unk14.unk64;
    this->unk14.unk64 = temp_r4_81 + 1;
    if ((s32) temp_r4_81 > 3) {
        Release();
        var_r5_77 = 1;
        this->unk138 |= 0x02000000;
        this->unk138 &= 0xFFFFFBFF;
        this->unk14.unkAC = 0;
        this->unk14.unk8C = 0;
    }
    return var_r5_77;
}
#endif

#if 0 // DRAFT: undefined identifier 'bPackageSystemInUse'
s32 MKLevelChunk::Update_Deinit() {
    u32 temp_r3_130;

    if (!(this->unk138 & 0x1000)) {
        Game_ChunkInitComplete(NULL, M2C_ERROR(/* Read from unset register $r5 */));
        this->unk138 |= 0x1000;
    }
    if (M2C_FIELD(this->unk8, u8 (**)(MKLevelChunk *), 0x80)(this) != 0) {
        temp_r3_130 = this->unk138;
        if (temp_r3_130 & 0x10000) {
            MKPackage_QFree(this->unk10);
            this->unk10 = 0;
            bPackageSystemInUse = 0;
            this->unk138 &= 0xFFFEFFFF;
        } else if (temp_r3_130 & 0x80000) {
            MKPackage_QFree(this->unk10);
            this->unk10 = 0;
            bPackageSystemInUse = 0;
            this->unk138 &= 0xFFF7FFFF;
        }
        this->unk138 |= 0x01000000;
        this->unk14.unk64 = 0;
        this->unk14.unk78 = 1.5e-44f;
    }
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkEC'
s32 MKLevelChunk::Update_Ready() {
    s32 var_r31_178;
    u32 temp_r3_187;

    var_r31_178 = 0;
    if ((strlen(&this->unk14.unkEC) != 0) || (this->unk138 & 0x20)) {
        temp_r3_187 = this->unk138;
        if (temp_r3_187 & 0x100) {
            var_r31_178 = 0xC;
            this->unk138 = temp_r3_187 | 0x40;
            this->unk138 |= 0x80;
        } else {
            this->unk138 = temp_r3_187 | 0x400;
            var_r31_178 = 0xA;
            this->unk4 = 0;
        }
    }
    return var_r31_178;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkEC'
s32 MKLevelChunk::Update_Reset() {
    s32 var_r31_220;

    var_r31_220 = 0;
    if (M2C_FIELD(this->unk8, u8 (**)(), 0x1C)() != 0) {
        this->unk138 |= 0x800000;
        if ((strlen(&this->unk14.unkEC) != 0) || (this->unk138 & 0x20)) {
            var_r31_220 = 0xA;
        } else {
            ApplyFlags(this->unk14.unk88);
            Game_ChunkInitComplete((MKLevelChunk *)1, M2C_ERROR(/* Read from unset register $r5 */));
            var_r31_220 = 9;
            this->unk14.unk110 = NULL;
            this->unk14.unk114 = 0;
            this->unk14.unkAC = 0;
            this->unk14.unk8C = 0;
            this->unk14.unk88 = 0;
            this->unk138 &= 0xFFFFFBFF;
        }
    }
    return var_r31_220;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk110'
s32 MKLevelChunk::Update_Optimise() {
    s32 var_r31_274;

    var_r31_274 = 0;
    if (M2C_FIELD(this->unk8, u8 (**)(), 0x2C)() != 0) {
        var_r31_274 = 8;
        this->unk138 |= 0x400000;
        this->unk14.unk110 = NULL;
        this->unk14.unk114 = 0;
    }
    return var_r31_274;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'float' to
s32 MKLevelChunk::Update_Resolve() {
    s32 var_r31_305;

    var_r31_305 = 0;
    if (M2C_FIELD(this->unk8, u8 (**)(), 0x20)() != 0) {
        var_r31_305 = 7;
        this->unk138 |= 0x200000;
        if (this->unk138 & 0x20000) {
            ((MKIni *) (M2C_BITWISE(MKIni *, this->unk14.unk74)))->Deinit();
            this->unk138 &= 0xFFFDFFFF;
        }
    }
    return var_r31_305;
}
#endif

#if 0 // DRAFT: undefined identifier 'bPackageSystemInUse'
s32 MKLevelChunk::Update_Init() {
    s32 var_r31_341;

    var_r31_341 = 0;
    if (M2C_FIELD(*gMK, u8 (**)(void **), 0x4C)(gMK) != 0) {
        MKGrass_LevelInit();
        this->unk138 &= 0xFFF7FFFF;
        MKPackage_QFree(this->unk10);
        var_r31_341 = 6;
        this->unk10 = 0;
        bPackageSystemInUse = 0;
        this->unk138 |= 0x100000;
        this->unk14.unk110 = NULL;
        this->unk14.unk114 = 0;
        ((MKChunkSceneManager *) (M2C_BITWISE(s32, this->unk14.unk74) + 0x1C))->StripExtension((s8 *)0x2E, M2C_ERROR(/* Read from unset register $r5 */));
        ((M2C_UNK (*)()) pResolver.__vptr)();
    }
    return var_r31_341;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkEC'
s32 MKLevelChunk::Update_Loading() {
    s32 var_r31_390;

    var_r31_390 = 0;
    this->unk138 &= 0xFFFBFFFF;
    if (MKPackage_QIsLoaded(this->unk10, NULL, NULL) != 0) {
        this->unk138 |= 0x80000;
        if ((strlen(&this->unk14.unkEC) != 0) || (this->unk138 & 0x20)) {
            var_r31_390 = 0xA;
        } else if (M2C_FIELD(this->unk8, u8 (**)(MKLevelChunk *), 0x7C)(this) != 0) {
            M2C_FIELD(*gMK, M2C_UNK (**)(void **, f32), 0x48)(gMK, this->unk14.unk74);
            var_r31_390 = 5;
        }
    }
    return var_r31_390;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkAC'
s32 MKLevelChunk::Update_LoadSound() {
    s32 sp8;
    s32 temp_r3_497;
    s32 var_r30_446;
    s8 *temp_r3_451;
    u32 temp_r3_482;

    var_r30_446 = 0;
    sp8 = -1;
    temp_r3_451 = Str_Printf(lit_stringBase0, &this->unk14.unkAC, &lit_stringBase0[9]);
    if (((s32) M2C_FIELD(this, s32 *, 0x130) == -1) || (MKArchive_Exists(temp_r3_451, NULL) == 0) || (this->unk138 & 0x40000) || (System_GetCommandLineParameter(&lit_stringBase0[0xE], 1U), (((u32) M2C_ERROR(/* Read from unset register $r3 */) == 0U) != 0)) || (Sound_IsBankLoaded(&sp8) != 0)) {
        if ((s32) M2C_FIELD(this, s32 *, 0x130) == -2) {
            M2C_FIELD(this, s32 *, 0x130) = sp8;
        }
        temp_r3_482 = this->unk138 | 0x40000;
        this->unk138 = temp_r3_482;
        bPackageSystemInUse = 1;
        temp_r3_482->ActivateTempMemOverride();
        temp_r3_497 = MKPackage_QLoadDynamic(Str_Printf(&lit_stringBase0[0x14], &this->unk14.unkAC, gMKDefaults.unk28, lit_stringBase0), 0, NULL);
        this->unk10 = temp_r3_497;
        temp_r3_497->DeactivateTempMemOverride();
        var_r30_446 = 2;
    }
    return var_r30_446;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkEC'
s32 MKLevelChunk::Update_LoadingIni() {
    s32 var_r31_520;
    u32 temp_r3_529;

    var_r31_520 = 0;
    if (MKPackage_QIsLoaded(this->unk10, NULL, NULL) != 0) {
        this->unk138 |= 0x10000;
        temp_r3_529 = strlen(&this->unk14.unkEC);
        if ((temp_r3_529 != 0) || (this->unk138 & 0x20)) {
            var_r31_520 = 0xA;
        } else {
            temp_r3_529->ActivateTempMemOverride();
            ((MKHeap *) (((MKIni *) (M2C_BITWISE(MKIni *, this->unk14.unk74)))->Init(Str_Printf(&lit_stringBase0[0x1D], &this->unk14.unkAC, gMKDefaults.unk28, lit_stringBase0), 4, NULL)))->DeactivateTempMemOverride();
            this->unk138 |= 0x20000;
            MKPackage_QFree(this->unk10);
            bPackageSystemInUse = 0U;
            this->unk138 &= 0xFFFEFFFF;
            if ((strlen(&this->unk14.unkEC) != 0) || (this->unk138 & 0x20)) {
                var_r31_520 = 0xA;
            } else if ((u8) bPackageSystemInUse == 0) {
                bPackageSystemInUse = 1U;
                this->unk10 = MKPackage_QLoad(&this->unk14.unkAC, 0);
                var_r31_520 = 4;
                this->__vptr = NULL;
            }
        }
    }
    return var_r31_520;
}
#endif

#if 0 // DRAFT: undefined identifier 'bChunksUseHeaps'
s32 MKLevelChunk::Update_Unloaded() {
    f32 temp_f1_656;
    s32 temp_r5_689;
    s32 var_r31_605;
    s8 *temp_r3_669;
    s8 *temp_ret_669;
    u32 temp_r3_609;

    var_r31_605 = 0;
    this->unk138 &= 0xFC00FFFF;
    temp_r3_609 = this->unk138;
    if (temp_r3_609 & 0x20) {
        if (temp_r3_609 & 0x80) {
            this->unk138 = temp_r3_609 & 0xFFFFFFDF;
            this->unk138 &= 0xFFFFFF7F;
        } else {
            if ((u8) bChunksUseHeaps != 0) {
                M2C_FIELD(this, s32 *, 0x74) = this->unk14.Mark();
            }
            var_r31_605 = 0xC;
            this->unk138 |= 0x40;
            this->unk138 |= 0x80;
        }
    } else if ((strlen(&this->unk14.unkEC) != 0) && ((u8) bPackageSystemInUse == 0)) {
        if ((u8) bChunksUseHeaps != 0) {
            M2C_FIELD(this, s32 *, 0x74) = this->unk14.Mark();
        }
        strcpy(&this->unk14.unkAC, &this->unk14.unkEC);
        temp_f1_656 = M2C_BITWISE(f32, strcpy(&this->unk14.unk8C, &this->unk14.unkCC));
        this->unk14.unkEC = 0;
        this->unk14.unkCC = 0;
        var_r31_605 = 3;
        this->unk138 |= 0x400;
        temp_ret_669 = Str_Printf(&lit_stringBase0[0x22], &this->unk14.unkAC, temp_f1_656);
        temp_r3_669 = temp_ret_669;
        if (MKArchive_Exists(Str_Printf(&lit_stringBase0[0x1D], temp_r3_669, &lit_stringBase0[9], M2C_BITWISE(f32, temp_ret_669)), NULL) != 0) {
            System_GetCommandLineParameter(&lit_stringBase0[0xE], 1U);
            if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
                temp_r5_689 = M2C_FIELD(this, s32 *, 0x130);
                if (temp_r5_689 > -1) {
                    Sound_LoadBank(temp_r3_669, 1U, temp_r5_689);
                } else if (temp_r5_689 == -2) {
                    Sound_LoadBank(temp_r3_669, 1U, -1);
                }
            }
        }
    }
    return var_r31_605;
}
#endif

void MKLevelChunk::UpdateState() {
    f32 temp_r0_721;
    s32 var_r5_717;

    var_r5_717 = 0;
    temp_r0_721 = this->unk14.unk78;
    if (M2C_BITWISE(u32, temp_r0_721) <= 0xCU) {
        switch (M2C_BITWISE(s32, temp_r0_721)) {
        case 1:
            var_r5_717 = Update_Unloaded();
            break;
        case 2:
            var_r5_717 = Update_LoadingIni();
            break;
        case 3:
            var_r5_717 = Update_LoadSound();
            break;
        case 4:
            var_r5_717 = Update_Loading();
            break;
        case 5:
            var_r5_717 = Update_Init();
            break;
        case 6:
            var_r5_717 = Update_Resolve();
            break;
        case 7:
            var_r5_717 = Update_Optimise();
            break;
        case 8:
            var_r5_717 = Update_Reset();
            break;
        case 9:
            var_r5_717 = Update_Ready();
            break;
        case 10:
            var_r5_717 = Update_Deinit();
            break;
        case 11:
            var_r5_717 = Update_Release();
            break;
        case 12:
            var_r5_717 = Update_AppLocked();
            break;
        }
    }
    if (var_r5_717 != 0) {
        this->unk14.unk78 = M2C_BITWISE(f32, var_r5_717);
        if (var_r5_717 == 0xA) {
            this->unk4 = 0;
            this->unk138 &= 0xFFFFEFFF;
        }
    }
}

#if 0 // DRAFT: illegal explicit conversion from 'float' to
void MKLevelChunk::ApplyFlags(unsigned int arg0) {
    u32 temp_r3_806;

    temp_r3_806 = this->unk138 & 2;
    if ((temp_r3_806 == 0) && (arg0 & 4)) {
        MKCollision_AddManager(M2C_BITWISE(MKCollisionManager *, this->unk14.unk7C));
        this->unk138 |= 2;
    } else if ((temp_r3_806 != 0) && !(arg0 & 4)) {
        MKCollision_RemoveManager(M2C_BITWISE(MKCollisionManager *, this->unk14.unk7C));
        this->unk138 &= 0xFFFFFFFD;
    }
    this->unk134 = (s32) arg0;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'float' to
MKModel *MKLevelChunk::AddWaterModel(const char *arg0) {
    MKHeap *temp_r3_859;
    MKHeap *temp_r3_862;
    MKModel *temp_r30_854;
    s32 temp_r31_861;
    void *var_r3_869;

    operator new(0x14U, NULL, 0);
    this->unk14.unk80 = M2C_ERROR(/* Read from unset register $r3 */);
    ((MKFFTWater *) (M2C_BITWISE(MKFFTWater *, this->unk14.unk80)))->Init(arg0);
    temp_r30_854 = M2C_FIELD(this->unk14.unk80, MKModel **, 4);
    MKModel_EnableScissoring(temp_r30_854, 1U);
    temp_r3_859 = MKModel_GetNmbrOfSubObjects(temp_r30_854, (SubObjectType) 0);
    temp_r31_861 = (temp_r3_859 + 2) * 2;
    temp_r3_862 = temp_r3_859->Current();
    if (temp_r3_862 != NULL) {
        var_r3_869 = ((MKHeap *) (temp_r3_862->Current()))->Alloc(temp_r31_861, NULL, 0);
    } else {
        var_r3_869 = malloc(temp_r31_861);
    }
    this->unk14.unk84 = M2C_BITWISE(f32, var_r3_869);
    return temp_r30_854;
}
#endif

#if 0 // DRAFT: identifier 'MKLevelChunk::DeinitChunk()' redeclared
u8 MKLevelChunk::DeinitChunk() {
    MKHeap *temp_r3_918;
    f32 temp_r30_917;
    u32 temp_r0_893;
    u32 temp_r3_953;
    u32 temp_r3_961;
    u8 var_r5_889;

    var_r5_889 = 0;
    temp_r0_893 = this->unk4;
    switch (temp_r0_893) {
    case 0:
        MKGrass_LevelDeinit();
        ((MKCollisionManager *) (M2C_BITWISE(MKCollisionManager *, this->unk14.unk7C)))->Enable(0U);
        var_r5_889 = 1;
        break;
    case 5:
        if (this->unk138 & 8) {
            ((MKFFTWater *) (M2C_BITWISE(MKFFTWater *, this->unk14.unk80)))->Deinit();
            operator delete(M2C_BITWISE(void *, this->unk14.unk80));
            temp_r30_917 = this->unk14.unk84;
            temp_r3_918 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
            if (temp_r3_918 != NULL) {
                ((MKHeap *) (temp_r3_918->Current()))->Free(M2C_BITWISE(void *, temp_r30_917), NULL, 0);
            } else {
                free(M2C_BITWISE(u32, temp_r30_917));
            }
            this->unk14.unk84 = 0.0f;
            this->unk14.unk80 = 0.0f;
            this->unk138 &= 0xFFFFFFF7;
        }
        var_r5_889 = 1;
        break;
    case 4:
        if (this->unk138 & 0x10) {
            Game_UserInit(NULL, 0U);
            this->unk138 &= 0xFFFFFFEF;
        }
        var_r5_889 = 1;
        break;
    case 7:
        temp_r3_953 = this->unk138;
        if (temp_r3_953 & 1) {
            this->unk138 = temp_r3_953 & 0xFFFFFFFE;
            ((MKCollisionManager *) (M2C_BITWISE(MKCollisionManager *, this->unk14.unk7C)))->Deinit();
        }
        temp_r3_961 = this->unk138;
        if (temp_r3_961 & 2) {
            this->unk138 = temp_r3_961 & 0xFFFFFFFD;
            MKCollision_RemoveManager(M2C_BITWISE(MKCollisionManager *, this->unk14.unk7C));
        }
        var_r5_889 = 1;
        break;
    case 8:
        if (this->unk138 & 0x20000) {
            ((MKIni *) (M2C_BITWISE(MKIni *, this->unk14.unk74)))->Deinit();
            this->unk138 &= 0xFFFDFFFF;
        }
        var_r5_889 = 1;
        break;
    }
    return var_r5_889;
}
#endif

#if 0 // DRAFT: identifier 'MKLevelChunk::InitChunk()' redeclared
u8 MKLevelChunk::InitChunk() {
    s8 *sp10;
    s8 *spC;
    s8 *sp8;
    MKHeap *temp_r3_1198;
    MKHeap *temp_r3_1215;
    MKHeap *temp_r3_1389;
    MKHeap *temp_r3_1402;
    MKHeap *var_r3_1206;
    MKIni *temp_r27_1196;
    MKIniLine *temp_r3_1015;
    MKIniLine *temp_r3_1234;
    MKIniLine *temp_r3_1426;
    MKIniLine *var_r23_1427;
    MKIniLine *var_r24_1235;
    MKIniLine *var_r25_1016;
    MKIniLine *var_r25_1109;
    MKIniLine *var_r25_1328;
    MKIniLine *var_r25_1520;
    s32 temp_r25_1214;
    s32 temp_r26_1137;
    s32 temp_r26_1197;
    s32 temp_r27_1141;
    s32 temp_r3_1545;
    s32 temp_ret_1545;
    s32 var_r27_1232;
    s32 var_r28_1143;
    s32 var_r28_1233;
    s32 var_r29_1231;
    s8 **var_r3_1223;
    s8 **var_r4_1378;
    s8 *temp_r23_1250;
    s8 *temp_r23_1350;
    s8 *temp_r24_1442;
    s8 *temp_r26_1031;
    s8 *var_r25_1241;
    s8 *var_r25_1433;
    s8 *var_r27_1022;
    u32 temp_ret_1146;
    u8 var_r4_996;
    void *temp_r0_1000;

    var_r4_996 = 0;
    temp_r0_1000 = this->__vptr;
    switch (temp_r0_1000) {                         /* irregular */
    case 1:
        temp_r3_1015 = ((MKIni *) (M2C_FIELD(gMK, MKIni **, 0x28)))->GetFirstLine();
        var_r25_1016 = temp_r3_1015;
        temp_r3_1015->GetFieldName();
        sp10 = NULL;
        var_r27_1022 = NULL;
        var_r25_1016->AsString(0, &sp10);
loop_21:
        if (var_r25_1016 != NULL) {
            temp_r26_1031 = var_r25_1016->GetFieldName();
            var_r27_1022 = var_r25_1016->GetSectionName();
            var_r25_1016->AsString(0, &sp10);
            if ((temp_r26_1031 == NULL) || (stricmp(temp_r26_1031, &lit_stringBase0[0x29]) != 0) || (sp10 == NULL) || (stricmp(&this->unk14.unkAC) != 0)) {
                if ((temp_r26_1031 != NULL) && (stricmp(temp_r26_1031, &lit_stringBase0[0x2F]) == 0) && (sp10 != NULL) && (stricmp(&this->unk14.unk8C) == 0)) {
                    var_r25_1016 = var_r25_1016->unkC->GetSubLine(var_r25_1016);
                    goto loop_21;
                }
                if ((temp_r26_1031 != NULL) || (var_r27_1022 == NULL) || (stricmp(var_r27_1022, &this->unk14.unkAC) != 0)) {
                    var_r25_1016 = var_r25_1016->unkC->GetNextLine(var_r25_1016);
                    goto loop_21;
                }
            }
        }
        if (var_r25_1016 != NULL) {
            if ((var_r27_1022 == NULL) || (stricmp(var_r27_1022, &this->unk14.unkAC) != 0)) {
                var_r25_1109 = var_r25_1016->unkC->GetSubLine(var_r25_1016);
            } else {
                var_r25_1109 = var_r25_1016->unkC->GetNextLine(var_r25_1016);
            }
loop_34:
            if ((var_r25_1109 != NULL) && (var_r25_1109->GetSectionName() == NULL)) {
                if (var_r25_1109->GetFieldName() != NULL) {
                    ((MKChunkSceneManager *) (var_r25_1109->GetFieldName()))->StripExtension((s8 *)0x5F, M2C_ERROR(/* Read from unset register $r5 */));
                    if (stricmp(&lit_stringBase0[0x35]) == 0) {
                        temp_r26_1137 = var_r25_1109->GetString(0);
                        temp_r27_1141 = var_r25_1109->GetInt(1);
                        var_r28_1143 = temp_r26_1137;
                        temp_ret_1146 = strstr(temp_r26_1137, &lit_stringBase0[0x3D]);
                        if (temp_ret_1146 == 0U) {
                            var_r28_1143 = Str_Printf(&lit_stringBase0[0x1D], temp_r26_1137, &lit_stringBase0[0x3D], M2C_BITWISE(f32, temp_ret_1146));
                        }
                        if (MKArchive_Exists((s8 *) var_r28_1143, NULL) != 0) {
                            M2C_FIELD(this->unk8, M2C_UNK (**)(MKLevelChunk *, MKChunkSceneManager *, s32), 0x64)(this, temp_r26_1137->StripExtension((s8 *)0x2E, M2C_ERROR(/* Read from unset register $r5 */)), temp_r27_1141);
                        }
                    }
                }
                var_r25_1109 = var_r25_1109->unkC->GetNextLine(var_r25_1109);
                goto loop_34;
            }
        }
        var_r4_996 = 1;
        this->unk138 |= 4;
        break;
    case 2:
        temp_r27_1196 = M2C_FIELD(gMK, MKIni **, 0x28);
        temp_r26_1197 = gMKDefaults.unkE0 << 5;
        temp_r3_1198 = gMKDefaults.Current();
        if (temp_r3_1198 != NULL) {
            var_r3_1206 = ((MKHeap *) (temp_r3_1198->Main()))->TAlloc(temp_r26_1197, NULL, 0, 0U);
        } else {
            var_r3_1206 = malloc(temp_r26_1197);
        }
        temp_r25_1214 = gMKDefaults.unkE0 * 4;
        temp_r3_1215 = var_r3_1206->Current();
        if (temp_r3_1215 != NULL) {
            var_r3_1223 = ((MKHeap *) (temp_r3_1215->Main()))->TAlloc(temp_r25_1214, NULL, 0, 0U);
        } else {
            var_r3_1223 = malloc(temp_r25_1214);
        }
        var_r29_1231 = 0;
        var_r27_1232 = 0;
        var_r28_1233 = 0;
        temp_r3_1234 = temp_r27_1196->GetFirstLine();
        var_r24_1235 = temp_r3_1234;
        temp_r3_1234->GetFieldName();
        spC = NULL;
        var_r25_1241 = NULL;
        var_r24_1235->AsString(0, &spC);
loop_57:
        if (var_r24_1235 != NULL) {
            temp_r23_1250 = var_r24_1235->GetFieldName();
            var_r25_1241 = var_r24_1235->GetSectionName();
            var_r24_1235->AsString(0, &spC);
            if ((temp_r23_1250 == NULL) || (stricmp(temp_r23_1250, &lit_stringBase0[0x29]) != 0) || (spC == NULL) || (stricmp(&this->unk14.unkAC) != 0)) {
                if ((temp_r23_1250 != NULL) && (stricmp(temp_r23_1250, &lit_stringBase0[0x2F]) == 0) && (spC != NULL) && (stricmp(&this->unk14.unk8C) == 0)) {
                    var_r24_1235 = var_r24_1235->unkC->GetSubLine(var_r24_1235);
                    goto loop_57;
                }
                if ((temp_r23_1250 != NULL) || (var_r25_1241 == NULL) || (stricmp(var_r25_1241, &this->unk14.unkAC) != 0)) {
                    var_r24_1235 = var_r24_1235->unkC->GetNextLine(var_r24_1235);
                    goto loop_57;
                }
            }
        }
        if (var_r24_1235 != NULL) {
            if ((var_r25_1241 == NULL) || (stricmp(var_r25_1241, &this->unk14.unkAC) != 0)) {
                var_r25_1328 = var_r24_1235->unkC->GetSubLine(var_r24_1235);
            } else {
                var_r25_1328 = var_r24_1235->unkC->GetNextLine(var_r24_1235);
            }
loop_67:
            if ((var_r25_1328 != NULL) && (var_r25_1328->GetSectionName() == NULL)) {
                if (var_r25_1328->GetFieldName() != NULL) {
                    var_r25_1328->GetFieldName();
                    if (stricmp(&lit_stringBase0[0x42]) == 0) {
                        temp_r23_1350 = var_r3_1206 + var_r28_1233;
                        strcpy(temp_r23_1350, ((MKChunkSceneManager *) (var_r25_1328->GetString(0)))->StripExtension((s8 *)0x2E, M2C_ERROR(/* Read from unset register $r5 */)));
                        *(var_r3_1223 + var_r27_1232) = temp_r23_1350;
                        var_r29_1231 += 1;
                        var_r27_1232 += 4;
                        var_r28_1233 += 0x20;
                    }
                }
                var_r25_1328 = var_r25_1328->unkC->GetNextLine(var_r25_1328);
                goto loop_67;
            }
        }
        if (var_r29_1231 != 0) {
            var_r4_1378 = var_r3_1223;
        } else {
            var_r4_1378 = NULL;
        }
        ((MKCollisionManager *) (M2C_BITWISE(MKCollisionManager *, this->unk14.unk7C)))->Init(var_r4_1378, -1, (MKSceneManager *) gMK, var_r29_1231);
        MKCollision_AddManager(M2C_BITWISE(MKCollisionManager *, this->unk14.unk7C));
        temp_r3_1389 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_1389 != NULL) {
            ((MKHeap *) (temp_r3_1389->Main()))->TFree(var_r3_1223, NULL, 0);
        } else {
            free((u32) var_r3_1223);
        }
        temp_r3_1402 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_1402 != NULL) {
            ((MKHeap *) (temp_r3_1402->Main()))->TFree(var_r3_1206, NULL, 0);
        } else {
            free((u32) var_r3_1206);
        }
        var_r4_996 = 1;
        this->unk138 |= 1;
        this->unk138 |= 2;
        break;
    case 3:
        temp_r3_1426 = ((MKIni *) (M2C_FIELD(gMK, MKIni **, 0x28)))->GetFirstLine();
        var_r23_1427 = temp_r3_1426;
        temp_r3_1426->GetFieldName();
        sp8 = NULL;
        var_r25_1433 = NULL;
        var_r23_1427->AsString(0, &sp8);
loop_93:
        if (var_r23_1427 != NULL) {
            temp_r24_1442 = var_r23_1427->GetFieldName();
            var_r25_1433 = var_r23_1427->GetSectionName();
            var_r23_1427->AsString(0, &sp8);
            if ((temp_r24_1442 == NULL) || (stricmp(temp_r24_1442, &lit_stringBase0[0x29]) != 0) || (sp8 == NULL) || (stricmp(&this->unk14.unkAC) != 0)) {
                if ((temp_r24_1442 != NULL) && (stricmp(temp_r24_1442, &lit_stringBase0[0x2F]) == 0) && (sp8 != NULL) && (stricmp(&this->unk14.unk8C) == 0)) {
                    var_r23_1427 = var_r23_1427->unkC->GetSubLine(var_r23_1427);
                    goto loop_93;
                }
                if ((temp_r24_1442 != NULL) || (var_r25_1433 == NULL) || (stricmp(var_r25_1433, &this->unk14.unkAC) != 0)) {
                    var_r23_1427 = var_r23_1427->unkC->GetNextLine(var_r23_1427);
                    goto loop_93;
                }
            }
        }
        if (var_r23_1427 != NULL) {
            if ((var_r25_1433 == NULL) || (stricmp(var_r25_1433, &this->unk14.unkAC) != 0)) {
                var_r25_1520 = var_r23_1427->unkC->GetSubLine(var_r23_1427);
            } else {
                var_r25_1520 = var_r23_1427->unkC->GetNextLine(var_r23_1427);
            }
loop_104:
            if ((var_r25_1520 != NULL) && (var_r25_1520->GetSectionName() == NULL)) {
                if (var_r25_1520->GetFieldName() != NULL) {
                    ((MKChunkSceneManager *) (var_r25_1520->GetFieldName()))->StripExtension((s8 *)0x5F, M2C_ERROR(/* Read from unset register $r5 */));
                    if (stricmp(&lit_stringBase0[0x49]) == 0) {
                        temp_ret_1545 = var_r25_1520->GetString(0);
                        temp_r3_1545 = temp_ret_1545;
                        if (MKArchive_Exists(Str_Printf(&lit_stringBase0[0x1D], temp_r3_1545, &lit_stringBase0[0x3D], M2C_BITWISE(f32, temp_ret_1545)), NULL) != 0) {
                            AddWaterModel((s8 *) temp_r3_1545);
                            this->unk138 |= 8;
                        }
                    }
                }
                var_r25_1520 = var_r25_1520->unkC->GetNextLine(var_r25_1520);
                goto loop_104;
            }
        }
        var_r4_996 = 1;
        break;
    case 4:
        Game_UserInit((MKLevelChunk *)1, M2C_ERROR(/* Read from unset register $r5 */));
        var_r4_996 = 1;
        this->unk138 |= 0x10;
        break;
    }
    return var_r4_996;
}
#endif

void MKLevelChunk::UnlockChunk() {
    this->unk138 &= 0xFFFFFFBF;
    this->unk138 &= 0xFFFFFEFF;
}

#if 0 // DRAFT: undefined identifier 'unkEC'
void MKLevelChunk::LockChunk(int arg0, bool arg1) {
    this->unk14.unkEC = 0;
    this->unk14.unkCC = 0;
    if (arg1 != 0) {
        this->unk138 |= 0x800;
    }
    this->unk138 |= 0x20;
    if (arg0 == 1) {
        this->unk138 |= 0x100;
        this->unk138 &= 0xFFFFFDFF;
        return;
    }
    ApplyFlags(0U);
    this->unk138 |= 0x200;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkEC'
u8 MKLevelChunk::IsReady() {
    f32 temp_r0_1659;
    u8 var_r31_1658;

    var_r31_1658 = 0;
    temp_r0_1659 = this->unk14.unk78;
    if (((M2C_BITWISE(s32, temp_r0_1659) == 9) || (M2C_BITWISE(s32, temp_r0_1659) == 0xC)) && (strlen(&this->unk14.unkEC) == 0)) {
        var_r31_1658 = 1;
    }
    return var_r31_1658;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkEC'
void MKLevelChunk::QueueChunkLoad(const char *arg0, const char *arg1, bool arg2) {
    strcpy(&this->unk14.unkEC, arg1);
    strcpy(&this->unk14.unkCC, arg0);
    if (arg2 != 0) {
        this->unk14.unk88 = 7;
        return;
    }
    this->unk14.unk88 = 0;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
s8 *MKLevelChunk::GetChunkName() {
    f32 temp_r0_1719;

    temp_r0_1719 = this->unk14.unk78;
    if ((M2C_BITWISE(s32, temp_r0_1719) == 9) || (M2C_BITWISE(s32, temp_r0_1719) == 0xC) || (M2C_BITWISE(s32, temp_r0_1719) == 0xA)) {
        return ((MKChunkSceneManager *) (M2C_BITWISE(s32, this->unk14.unk74) + 0x1C))->StripExtension((s8 *)0x2E, M2C_ERROR(/* Read from unset register $r5 */));
    }
    if (strlen(&this->unk14.unkAC) != 0) {
        return this->unk14.unkAC.StripExtension((s8 *)0x2E, M2C_ERROR(/* Read from unset register $r5 */));
    }
    if (strlen(&this->unk14.unkEC) != 0) {
        return this->unk14.unkEC.StripExtension((s8 *)0x2E, M2C_ERROR(/* Read from unset register $r5 */));
    }
    return NULL;
}
#endif

#if 0 // DRAFT: undefined identifier 'bChunksUseHeaps'
void MKLevelChunk::Release() {
    if ((u8) bChunksUseHeaps != 0) {
        this->unk14.Release(M2C_FIELD(this, s32 *, 0x74));
        M2C_FIELD(this, s32 *, 0x74) = -1;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unkEC'
void MKLevelChunk::Deinit() {
    if (M2C_BITWISE(s32, this->unk14.unk78) != 0) {
        this->unk14.unkEC = 0;
        this->unk14.unkCC = 0;
loop_6:
        if (IsReady() != 0) {
            Game_ChunkInitComplete(NULL, M2C_ERROR(/* Read from unset register $r5 */));
            this->unk14.unk78 = 1.4e-44f;
            this->unk4 = 0;
            this->unk138 &= 0xFFFFEFFF;
            this->unk138 |= 0x1400;
loop_9:
            if (M2C_BITWISE(s32, this->unk14.unk78) != 1) {
                MKModel_RemoveDestroyedModels();
                M2C_FIELD(this->unk8, M2C_UNK (**)(MKLevelChunk *), 0x18)(this);
                goto loop_9;
            }
            this->unk14.unk10C = (void *)-1;
        } else if (M2C_BITWISE(s32, this->unk14.unk78) != 1) {
            MKModel_RemoveDestroyedModels();
            if (M2C_BITWISE(s32, this->unk14.unk78) == 3) {
                Sound_Update();
            }
            M2C_FIELD(this->unk8, M2C_UNK (**)(MKLevelChunk *), 0x18)(this);
            goto loop_6;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk10C'
void MKLevelChunk::Init(MKLevelChunk::MKLevelChunkInit *arg1) {
    void *temp_r6_1872;

    this->unk14.unk78 = 1e-45f;
    this->unk14.unk68 = 0xFFFFFF;
    this->unk14.unk6C = -0.0f;
    if ((u8) M2C_FIELD(arg1, u8 *, 0) != 0) {
        this->unk14.unk10C = (void *)-1;
        M2C_FIELD(this, s8 *, 0x88) = 1;
    } else {
        temp_r6_1872 = idCounter.__vptr;
        idCounter.__vptr = temp_r6_1872 + 1;
        this->unk14.unk10C = temp_r6_1872;
        M2C_FIELD(this, s8 *, 0x88) = 0;
    }
    this->unk14.unk110 = NULL;
    this->unk14.unk114 = 0;
    this->unk14.unk80 = 0.0f;
    this->unk14.unk84 = 0.0f;
    this->unk144 = 0.0f;
    this->unkC = M2C_FIELD(arg1, s32 *, 4);
}
#endif

#if 0 // DRAFT: undefined identifier 'bChunksUseHeaps'
void MKLevelChunk::Deactivate() {
    if ((u8) bChunksUseHeaps != 0) {
        MKHeap::Pop();
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'bChunksUseHeaps'
void MKLevelChunk::Activate() {
    if ((u8) bChunksUseHeaps != 0) {
        this->unk14.Push();
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'float' to
void MKLevelChunk::Destroy() {
    s32 temp_r3_1933;

    temp_r3_1933 = M2C_FIELD(this, s32 *, 0x130);
    if (temp_r3_1933 > -1) {
        Sound_UnloadBank(temp_r3_1933);
        M2C_FIELD(this, s32 *, 0x130) = -1;
    }
    this->unk138 &= 0xFFFBFFFF;
    Activate();
    operator delete(M2C_BITWISE(void *, this->unk14.unk74));
    this->unk14.unk74 = 0.0f;
    operator delete(M2C_BITWISE(void *, this->unk14.unk7C));
    this->unk14.unk7C = 0.0f;
    M2C_FIELD(this->unk8, M2C_UNK (**)(MKLevelChunk *), 0x58)(this);
    if ((u8) bChunksUseHeaps != 0) {
        ((MKHeap *) (((MKHeap *) (this->unk14.Release(this->unk14.unk58)))->Main()))->Push();
        this->unk14.DeInit();
        ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Pop();
        this->unk14.unk58->FreeFromAnyHeap(NULL, NULL, M2C_ERROR(/* Read from unset register $r6 */));
    }
    Deactivate();
}
#endif

#if 0 // DRAFT: undefined identifier 'bChunksUseHeaps'
void MKLevelChunk::Create(int arg0, int arg1, int arg2, int arg3, const char *arg4) {
    MKCollisionManager *var_r0_2045;
    MKHeap *temp_r3_1999;
    s32 var_r0_2029;
    void *var_r3_2006;

    if ((u8) bChunksUseHeaps != 0) {
        temp_r3_1999 = MKHeap::Current();
        if (temp_r3_1999 != NULL) {
            var_r3_2006 = ((MKHeap *) (temp_r3_1999->Current()))->Alloc(arg0, NULL, 0);
        } else {
            var_r3_2006 = malloc(arg0);
        }
        this->unk14.Init(arg0, 0, arg4, var_r3_2006);
        this->unk14.unk58 = this->unk14.Mark();
    } else {
        this->unk14.unk58 = -1;
    }
    M2C_FIELD(this, s32 *, 0x74) = -1;
    var_r0_2029 = arg0;
    if (arg3 != 0) {
        var_r0_2029 = arg3;
    }
    this->unk14.unk60 = var_r0_2029;
    Activate();
    operator new(0x50U, NULL, 0);
    this->unk14.unk74 = M2C_ERROR(/* Read from unset register $r3 */);
    operator new(0x40U, NULL, 0);
    var_r0_2045 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r0_2045 != NULL) {
        var_r0_2045 = ((MKCollisionManager *) (M2C_ERROR(/* Read from unset register $r3 */)))->MKCollisionManager();
    }
    this->unk14.unk7C = M2C_BITWISE(f32, var_r0_2045);
    M2C_FIELD(this->unk14.unk7C, MKLevelChunk **, 0x20) = this;
    Deactivate();
    if (arg2 > 0) {
        if ((u8) bChunksUseHeaps != 0) {
            M2C_FIELD(this, s32 *, 0x130) = Sound_ReserveMemory(arg2, arg1);
            this->unk14.unk11C = (Level *) arg2;
        } else {
            M2C_FIELD(this, s32 *, 0x130) = -2;
            this->unk14.unk11C = NULL;
        }
    } else {
        M2C_FIELD(this, s32 *, 0x130) = -1;
        this->unk14.unk11C = NULL;
    }
    this->unk14.unkAC = 0;
    this->unk14.unk8C = 0;
    this->unk14.unkEC = 0;
    this->unk14.unkCC = 0;
    this->unk14.unk88 = 7;
    this->unk134 = 7;
    this->unk138 = 0;
    this->unk13C = 3;
    this->unk140 = 200000.0f;
    this->unk14.unk78 = 0.0f;
}
#endif
