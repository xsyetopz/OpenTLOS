#include "spyro/source/SpyroHud.h"
#include "common/Source/MKFont.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/CutsceneEvent.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/GameData.h"
#include "spyro/source/HudData.h"
#include "spyro/source/HudItems.h"
#include "unplaced_enums.h"
#include "common/Source/MKSystem.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "spyro/source/Hud.h"
#include <m2c_macros.h>

M2C_UNK __construct_array(M2C_UNK *, HudData *(*)(HudData *), M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern f32 gUpdateTimeDelta;
extern M2C_UNK gb;
#if 0 // DRAFT: illegal use of incomplete struct/union/class
static M2C_UNK HUD_BAR_BACKGROUND;                  /* unable to generate initializer: unknown type */
static struct _struct_vEnemyHealthBarColour_0x10 vEnemyHealthBarColour[5] = { { 0.0, 0.0 }, { 0.0, 0.0 }, { 0.0, 0.0 }, { 0.0, 0.0 }, { 0.0, 0.0 } };
#endif
#if 0 // DRAFT: illegal use of incomplete struct/union/class
static struct _struct_vEnemyHealthBarSize_0x8 vEnemyHealthBarSize[4] = { {  }, {  }, {  }, {  } };
#endif
static M2C_UNK hudItem;
static M2C_UNK hudData;
static s32 iEnemyHealthBarColours = 5;

static M2C_UNK hudDesc;                             /* unable to generate initializer: unknown type; const */

void EnemyHudData::Init(Enemy *arg0, float arg1, float arg2) {
    Enemy *temp_r4_14;

    this->unk0 = arg0;
    this->unk4 = arg1;
    this->unkC = arg2;
    temp_r4_14 = this->unk0;
    if (temp_r4_14 != NULL) {
        this->unk8 = temp_r4_14->unkAB0;
        this->unk10 = M2C_FIELD(this->unk0->unkA20, s32 *, 0x118);
        this->unk14 = M2C_FIELD(this->unk0->unkA20, s32 *, 0x11C);
        this->unk18 = M2C_BITWISE(s32, this->unk0->unkAD0);
    }
}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
EnemyHudData::EnemyHudData() {
    this->unk0 = NULL;
    this->unk4 = 0.0f;
    this->unk8 = 0.0f;
    this->unkC = 0.0f;
    this->unk10 = 0;
    this->unk14 = 1;
    this->unk18 = 0;
    return this;
}
#endif

s32 EnemyHud_GetEnemy() {
    return M2C_FIELD(&hudData, s32 *, 0x5C);
}

#if 0 // DRAFT: undefined identifier '__vptr'
void EnemyHud_Modified(const EnemyHudData &arg0) {
    Enemy *temp_r3_67;
    f32 temp_f1_110;
    f32 temp_f2_113;

    temp_r3_67 = arg0.unk0;
    if ((temp_r3_67 == NULL) || ((u32) M2C_FIELD(&gb, u32 *, 0x360) == 0U) || ((u32) M2C_FIELD(&gb, u32 *, 0x360) == M2C_FIELD(temp_r3_67->__vptr, u32 (**)(), 0xD0)())) {
        M2C_FIELD(&hudData, s8 *, 0x6D) = 1;
        if ((Enemy *) arg0.unk0 != NULL) {
            HudItem_Modified(&hudItem + 0x20);
            M2C_FIELD(&hudData, f32 *, 0x3C) = 2.0f;
        } else if ((u8) M2C_FIELD(&hudItem, u8 *, 0x39) == 0) {
            HudItem_SetState(&hudItem + 0x20, (HudItemState) 0, 1U);
            M2C_FIELD(&hudData, f32 *, 0x3C) = 0.0f;
        }
        temp_f1_110 = arg0.unk8;
        temp_f2_113 = arg0.unk4;
        M2C_FIELD(&hudData, Enemy **, 0x40) = (Enemy *) arg0.unk0;
        M2C_FIELD(&hudData, f32 *, 0x44) = temp_f2_113;
        M2C_FIELD(&hudData, f32 *, 0x48) = temp_f1_110;
        M2C_FIELD(&hudData, f32 *, 0x4C) = (f32) arg0.unkC;
        M2C_FIELD(&hudData, s32 *, 0x50) = (s32) arg0.unk10;
        M2C_FIELD(&hudData, s32 *, 0x54) = (s32) arg0.unk14;
        M2C_FIELD(&hudData, s32 *, 0x58) = (s32) arg0.unk18;
        M2C_FIELD(&hudData, f32 *, 0x64) = temp_f1_110;
        if ((Enemy *) arg0.unk0 != (Enemy *) M2C_FIELD(&hudData, Enemy **, 0x5C)) {
            M2C_FIELD(&hudData, f32 *, 0x60) = temp_f2_113;
        }
        M2C_FIELD(&hudData, f32 *, 0x68) = (f32) arg0.unkC;
        M2C_FIELD(&hudData, Enemy **, 0x5C) = (Enemy *) arg0.unk0;
    }
}
#endif

#if 0 // DRAFT: illegal operand
void EnemyHud_Modified(MKProp *arg0, float arg1, float arg2, float arg3) {
    if ((arg0 == NULL) || ((u32) M2C_FIELD(&gb, u32 *, 0x360) == 0U) || ((u32) M2C_FIELD(&gb, u32 *, 0x360) == arg0)) {
        M2C_FIELD(&hudData, s8 *, 0x6D) = 0;
        if (arg0 != NULL) {
            HudItem_Modified(&hudItem + 0x20);
            M2C_FIELD(&hudData, f32 *, 0x3C) = 2.0f;
        } else if ((u8) M2C_FIELD(&hudItem, u8 *, 0x39) == 0) {
            HudItem_SetState(&hudItem + 0x20, (HudItemState) 0, 1U);
            M2C_FIELD(&hudData, f32 *, 0x3C) = 0.0f;
        }
        M2C_FIELD(&hudData, f32 *, 0x64) = arg2;
        if (arg0 != (MKProp *) M2C_FIELD(&hudData, MKProp **, 0x5C)) {
            M2C_FIELD(&hudData, f32 *, 0x60) = arg1;
        }
        M2C_FIELD(&hudData, f32 *, 0x68) = arg3;
        M2C_FIELD(&hudData, MKProp **, 0x5C) = arg0;
    }
}
#endif

void SpyroHud_ResetAfterCutScene() {
    M2C_FIELD(&hudItem, s32 *, 0) = 0;
    M2C_FIELD(&hudItem, s32 *, 0x20) = 0;
}

#if 0 // DRAFT: function call 'Hud_Remove(long *)' does not match
void SpyroHud_Deinit() {
    s32 var_r29_234;
    s32 var_r31_236;

    var_r29_234 = 1;
    var_r31_236 = 0x20;
    do {
        Hud_Remove(&hudItem + var_r31_236);
        var_r29_234 -= 1;
        var_r31_236 -= 0x20;
    } while (var_r29_234 >= 0);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void SpyroHud_Init() {
    HudItem *temp_r3_283;
    s32 var_r24_276;
    s32 var_r29_279;
    s32 var_r30_278;
    s32 var_r31_277;
    void *temp_r25_282;
    void *temp_r5_281;

    memset(&hudData, 0, 0x70U);
    memset(&hudItem, 0, 0x40U);
    var_r24_276 = 0;
    var_r31_277 = 0;
    var_r30_278 = 0;
    var_r29_279 = 0;
    do {
        temp_r5_281 = &hudDesc + var_r29_279;
        temp_r25_282 = &hudData + var_r30_278;
        temp_r3_283 = &hudItem + var_r31_277;
        temp_r3_283->unk14 = temp_r25_282;
        temp_r3_283->unk4 = M2C_FIELD(temp_r5_281, s32 *, 4);
        temp_r3_283->unk8 = M2C_FIELD(temp_r5_281, s32 *, 8);
        temp_r3_283->unkC = M2C_FIELD(temp_r5_281, s32 *, 0xC);
        M2C_FIELD(temp_r25_282, void **, 0) = temp_r5_281;
        temp_r3_283->unk18 = M2C_FIELD(temp_r5_281, u8 *, 0xB0);
        Hud_Add(temp_r3_283);
        var_r24_276 += 1;
        M2C_FIELD(temp_r25_282, f32 *, 4) = 0.0f;
        var_r31_277 += 0x20;
        var_r30_278 += 0x38;
        var_r29_279 += 0xB4;
    } while (var_r24_276 < 2);
}
#endif

void SpyroHud_StateChange(void *arg0, HudItemState arg1, HudItemState arg2) {
    if ((*M2C_FIELD(arg0, s32 **, 0) & 0x10) && ((s32) arg2 == 0)) {
        M2C_FIELD(arg0, s32 *, 0x24) = 0;
        M2C_FIELD(arg0, f32 *, 0x2C) = 0.0f;
        M2C_FIELD(arg0, f32 *, 0x28) = 0.0f;
        M2C_FIELD(arg0, f32 *, 0x30) = 0.0f;
    }
}

#if 0 // DRAFT: illegal type
void SpyroHud_Draw(void *arg0, HudItemState arg1, float arg2) {
    Matrix sp710;
    Matrix sp6D0;
    Matrix sp690;
    M2C_UNK sp68C;
    s8 *sp688;
    s32 sp684;
    s32 sp680;
    f64 sp678;
    f64 sp670;                                      /* compiler-managed */
    f64 sp668;
    f64 sp660;
    s8 *sp658;
    s32 sp654;
    s32 sp650;
    f64 sp648;
    f64 sp640;                                      /* compiler-managed */
    f64 sp638;
    f64 sp630;
    f64 sp628;
    f64 sp620;
    f64 sp618;
    f64 sp610;
    f64 sp608;
    f64 sp600;
    f64 sp5F8;
    f64 sp5F0;
    f64 sp5E8;
    f64 sp5E0;
    f64 sp5D8;
    f64 sp5D0;
    f64 sp5C8;
    f64 sp5C0;
    f64 sp5B8;
    f64 sp5B0;
    f64 sp5A8;
    f64 sp5A0;
    f64 sp598;
    f64 sp590;
    f64 sp588;
    f64 sp580;
    f64 sp578;
    f64 sp570;
    f64 sp568;
    f64 sp560;
    f64 sp558;
    f64 sp550;
    f64 sp548;
    f64 sp540;
    f64 sp538;
    f64 sp530;
    f64 sp528;
    f64 sp520;
    f64 sp518;
    f64 sp510;
    f64 sp508;
    f64 sp500;
    f64 sp4F8;
    f64 sp4F0;
    f64 sp4E8;
    f64 sp4E0;
    f64 sp4D8;
    f64 sp4D0;
    f64 sp4C8;
    f64 sp4C0;
    f32 sp4BC;
    f32 sp4B8;
    f32 sp4B4;
    f32 sp4B0;
    f32 sp4AC;
    f32 sp4A8;
    f32 sp4A4;
    f32 sp4A0;
    f32 sp49C;
    f32 sp498;
    f32 sp494;
    f32 sp490;
    f32 sp488;
    f32 sp484;
    f32 sp480;
    f32 sp47C;
    f32 sp478;
    f32 sp474;
    f32 sp470;
    f32 sp46C;
    f32 sp468;
    f32 sp464;
    f32 sp460;
    f32 sp458;
    f32 sp454;
    f32 sp450;
    f32 sp44C;
    f32 sp448;
    f32 sp444;
    f32 sp440;
    f32 sp43C;
    f32 sp438;
    f32 sp434;
    f32 sp430;
    f32 sp42C;
    f32 sp428;
    f32 sp424;
    f32 sp420;
    f32 sp41C;
    f32 sp418;
    f32 sp414;
    f32 sp410;
    f32 sp40C;
    f32 sp408;
    f32 sp404;
    f32 sp400;
    f32 sp3FC;
    f32 sp3F8;
    f32 sp3F4;
    f32 sp3F0;
    f32 sp3EC;
    f32 sp3E8;
    f32 sp3E4;
    f32 sp3E0;
    f32 sp3DC;
    f32 sp3D8;
    f32 sp3D4;
    f32 sp3D0;
    f32 sp3CC;
    f32 sp3C8;
    f32 sp3C4;
    f32 sp3C0;
    f32 sp3BC;
    f32 sp3B8;
    f32 sp3B4;
    f32 sp3B0;
    f32 sp3AC;
    f32 sp3A8;
    f32 sp3A4;
    f32 sp3A0;
    f32 sp39C;
    f32 sp398;
    f32 sp394;
    f32 sp390;
    f32 sp38C;
    f32 sp388;
    f32 sp384;
    f32 sp380;
    f32 sp37C;
    f32 sp378;
    f32 sp374;
    f32 sp370;
    f32 sp36C;
    f32 sp368;
    f32 sp364;
    f32 sp360;
    f32 sp35C;
    f32 sp358;
    f32 sp354;
    f32 sp350;
    f32 sp34C;
    f32 sp348;
    f32 sp344;
    f32 sp340;
    f32 sp33C;
    f32 sp338;
    f32 sp334;
    f32 sp330;
    f32 sp32C;
    f32 sp328;
    f32 sp324;
    f32 sp320;
    f32 sp31C;
    f32 sp318;
    f32 sp314;
    f32 sp310;
    f32 sp30C;
    f32 sp308;
    f32 sp304;
    f32 sp300;
    f32 sp2FC;
    f32 sp2F8;
    f32 sp2F4;
    f32 sp2F0;
    f32 sp2EC;
    f32 sp2E8;
    f32 sp2E4;
    f32 sp2E0;
    f32 sp2DC;
    f32 sp2D8;
    f32 sp2D4;
    f32 sp2D0;
    f32 sp2CC;
    f32 sp2C8;
    f32 sp2C4;
    f32 sp2C0;
    f32 sp2BC;
    f32 sp2B8;
    f32 sp2B4;
    f32 sp2B0;
    f32 sp2AC;
    f32 sp2A8;
    f32 sp2A4;
    f32 sp2A0;
    f32 sp29C;
    f32 sp298;
    f32 sp294;
    f32 sp290;
    f32 sp28C;
    f32 sp288;
    f32 sp284;
    f32 sp280;
    f32 sp27C;
    f32 sp278;
    f32 sp274;
    f32 sp270;
    f32 sp26C;
    f32 sp268;
    f32 sp264;
    f32 sp260;
    f32 sp25C;
    f32 sp258;
    f32 sp254;
    f32 sp250;
    f32 sp24C;
    f32 sp248;
    f32 sp244;
    f32 sp240;
    f32 sp23C;
    f32 sp238;
    f32 sp234;
    f32 sp230;
    f32 sp22C;
    f32 sp228;
    f32 sp224;
    f32 sp220;
    f32 sp21C;
    f32 sp218;
    f32 sp214;
    f32 sp210;
    f32 sp20C;
    f32 sp208;
    f32 sp204;
    f32 sp200;
    f32 sp1FC;
    f32 sp1F8;
    f32 sp1F4;
    f32 sp1F0;
    f32 sp1EC;
    f32 sp1E8;
    f32 sp1E4;
    f32 sp1E0;
    f32 sp1DC;
    f32 sp1D8;
    f32 sp1D4;
    f32 sp1D0;
    f32 sp1CC;
    f32 sp1C8;
    f32 sp1C4;
    f32 sp1C0;
    f32 sp1BC;
    f32 sp1B8;
    f32 sp1B4;
    f32 sp1B0;
    f32 sp1AC;
    f32 sp1A8;
    f32 sp1A4;
    f32 sp1A0;
    f32 sp19C;
    f32 sp198;
    f32 sp194;
    f32 sp190;
    f32 sp18C;
    f32 sp188;
    f32 sp184;
    f32 sp180;
    f32 sp17C;
    f32 sp178;
    f32 sp174;
    f32 sp170;
    f32 sp16C;
    f32 sp168;
    f32 sp164;
    f32 sp160;
    f32 sp15C;
    f32 sp158;
    f32 sp154;
    f32 sp150;
    f32 sp14C;
    f32 sp148;
    f32 sp144;
    f32 sp140;
    f32 sp13C;
    f32 sp138;
    f32 sp134;
    f32 sp130;
    f32 sp12C;
    f32 sp128;
    f32 sp124;
    f32 sp120;
    f32 sp11C;
    f32 sp118;
    f32 sp114;
    f32 sp110;
    f32 sp10C;
    f32 sp108;
    f32 sp104;
    f32 sp100;
    f32 spFC;
    f32 spF8;
    f32 spF4;
    f32 spF0;
    f32 spEC;
    f32 spE8;
    f32 spE4;
    f32 spE0;
    f32 spDC;
    f32 spD8;
    f32 spD4;
    f32 spD0;
    f32 spCC;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
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
    f32 temp_f0_1515;
    f32 temp_f0_560;
    f32 temp_f0_755;
    f32 temp_f10_415;
    f32 temp_f25_551;
    f32 temp_f25_746;
    f32 temp_f26_1596;
    f32 temp_f26_554;
    f32 temp_f26_749;
    f32 temp_f28_1604;
    f32 temp_f29_1603;
    f32 temp_f3_651;
    f32 var_f0_367;
    f32 var_f1_1519;
    f32 var_f31_354;
    f32 var_f3_1567;
    s32 temp_r0_1456;
    s32 temp_r0_657;
    s32 var_r6_605;
    struct _struct_vEnemyHealthBarColour_0x10 *temp_r3_669;
    struct _struct_vEnemyHealthBarSize_0x8 *temp_r5_602;
    u32 temp_r30_401;
    void *temp_r12_1298;
    void *temp_r12_781;
    void *temp_r26_1047;
    void *temp_r26_403;
    void *temp_r26_841;
    void *temp_r26_945;
    void *temp_r3_1507;
    void *temp_r3_516;
    void *temp_r3_711;
    void *temp_r4_1149;
    void *temp_r4_1358;
    void *temp_r5_524;
    void *temp_r5_719;
    void *temp_r7_586;
    void *var_r4_389;

    var_f31_354 = 1.0f;
    switch ((s32) arg1) {                           /* irregular */
    case 2:
        break;
    case 3:
        var_f0_367 = 2.0f * arg2;
        if (var_f0_367 < 1.0f) {

        } else {
            var_f0_367 = 1.0f;
        }
        if (var_f0_367 > 0.0f) {

        } else {
            var_f0_367 = 0.0f;
        }
        var_f31_354 = var_f0_367;
        break;
    }
    if ((s32) arg1 != 0) {
        if (System_IsWideScreenEnabled() != 0) {
            var_r4_389 = M2C_FIELD(arg0, void **, 0) + 0x18;
        } else {
            var_r4_389 = M2C_FIELD(arg0, void **, 0) + 0x10;
        }
        sp318 = M2C_FIELD(var_r4_389, f32 *, 0);
        temp_r30_401 = ((u8) GameData::gameData[0x168] >> 3U) & 1;
        sp31C = M2C_FIELD(var_r4_389, f32 *, 4);
        temp_r26_403 = M2C_FIELD(arg0, void **, 0);
        if ((M2C_FIELD(temp_r26_403, s32 *, 0) & 0x10) && ((void *) M2C_FIELD(arg0, void **, 0x24) != NULL) && ((u8) M2C_FIELD(arg0, u8 *, 0x35) == 0)) {
            temp_f10_415 = M2C_FIELD(arg0, f32 *, 0x30);
            sp194 = 0.0f;
            sp190 = 5.0f * temp_f10_415;
            sp314 = sp194;
            sp310 = sp190;
            sp188 = M2C_FIELD(temp_r26_403, f32 *, 0x38) * 0.75f;
            sp18C = M2C_FIELD(temp_r26_403, f32 *, 0x3C) * 0.75f;
            sp180 = sp310 * 0.75f;
            sp184 = sp314 * 0.75f;
            sp308 = sp188;
            sp30C = sp18C;
            sp248 = sp180;
            sp24C = sp184;
            sp490 = 1.0f;
            sp494 = 0.0f;
            sp178 = sp308 - sp248;
            sp17C = sp30C - sp24C;
            sp300 = sp178;
            sp304 = sp17C;
            sp498 = 0.0f;
            sp49C = var_f31_354;
            sp170 = M2C_FIELD(temp_r26_403, f32 *, 0x40) * 0.75f;
            sp174 = M2C_FIELD(temp_r26_403, f32 *, 0x44) * 0.75f;
            sp2F8 = sp170;
            sp2FC = sp174;
            sp4A0 = 0.3f;
            sp4A4 = 0.3f;
            sp4A8 = 0.3f;
            sp4AC = var_f31_354;
            sp4B0 = 1.0f;
            sp4B4 = 1.0f;
            sp4B8 = 1.0f;
            sp4BC = var_f31_354;
            sp5D0 = (f64) sp490;
            sp5D8 = (f64) sp498;
            sp5E0 = (f64) sp4A0;
            sp5E8 = (f64) sp4A8;
            sp5F0 = (f64) sp4B0;
            sp5F8 = (f64) sp4B8;
            sp8 = 1e-45f;
            Hud_DrawBarHorz(*((MKVector2 *) &sp318), *((MKVector2 *) &sp308), *((MKVector2 *) &sp300), *((MKVector2 *) &sp2F8), *((MKVector2 *) &sp300), *((MKVector4 *) &sp5F0), *((MKVector4 *) &sp5E0), *((MKVector4 *) &sp5D0), 0.75f * M2C_FIELD(M2C_FIELD(arg0, void **, 0), f32 *, 0x94), M2C_FIELD(arg0, f32 *, 0x2C) / temp_f10_415, M2C_FIELD(arg0, f32 *, 0x28) / temp_f10_415, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
            sp684 = 0;
            sp688 = NULL;
            sp680 = 0x8D;
            temp_r3_516 = M2C_FIELD(arg0, void **, 0x24);
            M2C_FIELD(M2C_FIELD(temp_r3_516, void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(temp_r3_516, &sp680);
            if (sp688 != NULL) {
                temp_r5_524 = M2C_FIELD(arg0, void **, 0);
                sp488 = 0.0f;
                sp168 = sp318 + M2C_FIELD(temp_r5_524, f32 *, 0x30);
                sp16C = sp31C + M2C_FIELD(temp_r5_524, f32 *, 0x34);
                sp240 = sp168;
                sp244 = sp16C;
                sp480 = sp240;
                sp484 = sp244;
                sp678 = (f64) sp488;
                sp670 = (f64) sp480;
                temp_f25_551 = ((MKFont *) (M2C_FIELD(&gb, MKFont **, 0x318)))->CalcLength(sp688);
                temp_f26_554 = ((MKFont *) (M2C_FIELD(&gb, MKFont **, 0x318)))->GetHeight();
                temp_f0_560 = -((0.5f * temp_f26_554) - unksp674);
                sp670 = -((0.5f * temp_f25_551) - (f32) sp670);
                unksp674 = temp_f0_560;
                sp710.SetIdentity();
                sp710.Translate(&sp710, *((MKVector3 *) &sp670));
                ((MKFont *) (M2C_FIELD(&gb, MKFont **, 0x318)))->DrawString(sp688, temp_f25_551, temp_f26_554, &sp710, 0xA, ((u32) (128.0f * var_f31_354) << 0x18) | 0x800000 | 0x8080, 1.0f, 1.0f, NULL, 1U);
            }
        }
        temp_r7_586 = M2C_FIELD(arg0, void **, 0);
        if ((M2C_FIELD(temp_r7_586, s32 *, 0) & 0x10) && ((void *) M2C_FIELD(arg0, void **, 0x24) != NULL) && ((u8) M2C_FIELD(arg0, u8 *, 0x35) != 0)) {
            temp_r5_602 = &vEnemyHealthBarSize[M2C_FIELD(arg0, s32 *, 0x18)];
            var_r6_605 = iEnemyHealthBarColours - 1;
            sp2F0 = M2C_FIELD(temp_r5_602, f32 *, -8);
            sp2F4 = M2C_FIELD(temp_r5_602, f32 *, -4);
            sp160 = M2C_FIELD(temp_r7_586, f32 *, 0x38) * 0.75f;
            sp164 = M2C_FIELD(temp_r7_586, f32 *, 0x3C) * 0.75f;
            sp158 = sp2F0 * 0.75f;
            sp15C = sp2F4 * 0.75f;
            sp2E8 = sp160;
            sp2EC = sp164;
            sp238 = sp158;
            sp23C = sp15C;
            sp150 = sp2E8 - sp238;
            sp154 = sp2EC - sp23C;
            sp2E0 = sp150;
            sp2E4 = sp154;
            sp148 = M2C_FIELD(temp_r7_586, f32 *, 0x40) * 0.75f;
            sp14C = M2C_FIELD(temp_r7_586, f32 *, 0x44) * 0.75f;
            sp2D8 = sp148;
            sp2DC = sp14C;
            temp_f3_651 = M2C_FIELD(arg0, f32 *, 0x30);
            temp_r0_657 = (M2C_FIELD(arg0, s32 *, 0x1C) - M2C_FIELD(arg0, s32 *, 0x20)) - 1;
            if (temp_r0_657 < var_r6_605) {
                var_r6_605 = temp_r0_657;
            }
            temp_r3_669 = &vEnemyHealthBarColour[var_r6_605];
            sp460 = 0.3f;
            sp464 = 0.3f;
            sp468 = 0.3f;
            sp46C = var_f31_354;
            sp668 = temp_r3_669->unk8;
            sp470 = 1.0f;
            sp474 = 1.0f;
            sp478 = 1.0f;
            sp47C = var_f31_354;
            sp660 = temp_r3_669->unk0;
            unksp66C = var_f31_354;
            sp5B0 = (f64) sp460;
            sp5B8 = (f64) sp468;
            sp5C0 = (f64) sp470;
            sp5C8 = (f64) sp478;
            sp8 = 1e-45f;
            Hud_DrawBarHorz(*((MKVector2 *) &sp318), *((MKVector2 *) &sp2E8), *((MKVector2 *) &sp2E0), *((MKVector2 *) &sp2D8), *((MKVector2 *) &sp2E0), *((MKVector4 *) &sp5C0), *((MKVector4 *) &sp5B0), *((MKVector4 *) &sp660), 0.75f * M2C_FIELD(M2C_FIELD(arg0, void **, 0), f32 *, 0x94), M2C_FIELD(arg0, f32 *, 0x2C) / temp_f3_651, M2C_FIELD(arg0, f32 *, 0x28) / temp_f3_651, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
            sp654 = 0;
            sp658 = NULL;
            sp650 = 0x8D;
            temp_r3_711 = M2C_FIELD(arg0, void **, 0x24);
            M2C_FIELD(M2C_FIELD(temp_r3_711, void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(temp_r3_711, &sp650);
            if (sp658 != NULL) {
                temp_r5_719 = M2C_FIELD(arg0, void **, 0);
                sp458 = 0.0f;
                sp140 = sp318 + M2C_FIELD(temp_r5_719, f32 *, 0x30);
                sp144 = sp31C + M2C_FIELD(temp_r5_719, f32 *, 0x34);
                sp230 = sp140;
                sp234 = sp144;
                sp450 = sp230;
                sp454 = sp234;
                sp648 = (f64) sp458;
                sp640 = (f64) sp450;
                temp_f25_746 = ((MKFont *) (M2C_FIELD(&gb, MKFont **, 0x318)))->CalcLength(sp658);
                temp_f26_749 = ((MKFont *) (M2C_FIELD(&gb, MKFont **, 0x318)))->GetHeight();
                temp_f0_755 = -((0.5f * temp_f26_749) - unksp644);
                sp640 = -((0.5f * temp_f25_746) - (f32) sp640);
                unksp644 = temp_f0_755;
                sp6D0.SetIdentity();
                sp6D0.Translate(&sp6D0, *((MKVector3 *) &sp640));
                ((MKFont *) (M2C_FIELD(&gb, MKFont **, 0x318)))->DrawString(sp658, temp_f25_746, temp_f26_749, &sp6D0, 0xA, ((u32) (128.0f * var_f31_354) << 0x18) | 0x800000 | 0x8080, 1.0f, 1.0f, NULL, 1U);
            }
        }
        temp_r12_781 = M2C_FIELD(arg0, void **, 0);
        if (M2C_FIELD(temp_r12_781, s32 *, 0) & 0x40) {
            sp440 = 1.0f;
            sp444 = 1.0f;
            sp448 = 1.0f;
            sp44C = var_f31_354;
            sp5A0 = (f64) sp440;
            sp5A8 = (f64) sp448;
            sp128 = M2C_FIELD(temp_r12_781, f32 *, 0x78) * 0.75f;
            sp12C = M2C_FIELD(temp_r12_781, f32 *, 0x7C) * 0.75f;
            sp218 = sp128;
            sp21C = sp12C;
            sp138 = M2C_FIELD(temp_r12_781, f32 *, 0x20) * 0.75f;
            sp13C = M2C_FIELD(temp_r12_781, f32 *, 0x24) * 0.75f;
            sp220 = sp138;
            sp224 = sp13C;
            sp130 = sp318 + sp220;
            sp134 = sp31C + sp224;
            sp228 = sp130;
            sp22C = sp134;
            Hud_DrawIcon(0, 3, *((MKVector2 *) &sp228), *((MKVector2 *) &sp218), *((MKVector4 *) &sp5A0), 0.0f, 0.0f, 1.0f, 1.0f, 0U, 0U, Matrix::identity);
        }
        temp_r26_841 = M2C_FIELD(arg0, void **, 0);
        if (M2C_FIELD(temp_r26_841, s32 *, 0) & 1) {
            sp124 = 0.0f;
            sp120 = 2.5f * M2C_FIELD(GameData::gameData, f32 *, 0x74);
            sp2D4 = sp124;
            sp2D0 = sp120;
            sp118 = M2C_FIELD(temp_r26_841, f32 *, 0x38) * 0.75f;
            sp11C = M2C_FIELD(temp_r26_841, f32 *, 0x3C) * 0.75f;
            sp110 = sp2D0 * 0.75f;
            sp114 = sp2D4 * 0.75f;
            sp2C8 = sp118;
            sp2CC = sp11C;
            sp210 = sp110;
            sp214 = sp114;
            sp410 = 1.0f;
            sp414 = 0.0f;
            sp108 = sp2C8 + sp210;
            sp10C = sp2CC + sp214;
            sp2C0 = sp108;
            sp2C4 = sp10C;
            sp418 = 0.0f;
            sp41C = var_f31_354;
            sp100 = M2C_FIELD(temp_r26_841, f32 *, 0x40) * 0.75f;
            sp104 = M2C_FIELD(temp_r26_841, f32 *, 0x44) * 0.75f;
            sp420 = 0.3f;
            sp424 = 0.3f;
            sp428 = 0.3f;
            sp42C = var_f31_354;
            sp430 = 1.0f;
            sp434 = 1.0f;
            sp438 = 1.0f;
            sp43C = var_f31_354;
            sp2B8 = sp100;
            sp2BC = sp104;
            sp570 = (f64) sp410;
            sp578 = (f64) sp418;
            sp580 = (f64) sp420;
            sp588 = (f64) sp428;
            sp590 = (f64) sp430;
            sp598 = (f64) sp438;
            sp8 = 0.0f;
            Hud_DrawBarHorz(*((MKVector2 *) &sp318), *((MKVector2 *) &sp2C8), *((MKVector2 *) &sp2C0), *((MKVector2 *) &sp2B8), *((MKVector2 *) &sp2C0), *((MKVector4 *) &sp590), *((MKVector4 *) &sp580), *((MKVector4 *) &sp570), 0.75f * M2C_FIELD(M2C_FIELD(arg0, void **, 0), f32 *, 0x94), M2C_FIELD(GameData::gameData, f32 *, 0x70) / M2C_FIELD(GameData::gameData, f32 *, 0x74), M2C_FIELD(GameData::gameData, f32 *, 0x78) / M2C_FIELD(GameData::gameData, f32 *, 0x74), M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
        }
        if (temp_r30_401 != 0) {
            temp_r26_945 = M2C_FIELD(arg0, void **, 0);
            if (M2C_FIELD(temp_r26_945, s32 *, 0) & 2) {
                spFC = 0.0f;
                spF8 = 2.0f * M2C_FIELD(GameData::gameData, f32 *, 0xA4);
                sp2B4 = spFC;
                sp2B0 = spF8;
                spF0 = M2C_FIELD(temp_r26_945, f32 *, 0x48) * 0.75f;
                spF4 = M2C_FIELD(temp_r26_945, f32 *, 0x4C) * 0.75f;
                spE8 = sp2B0 * 0.75f;
                spEC = sp2B4 * 0.75f;
                sp2A8 = spF0;
                sp2AC = spF4;
                sp208 = spE8;
                sp20C = spEC;
                sp3E0 = 0.0f;
                sp3E4 = 1.0f;
                spE0 = sp2A8 + sp208;
                spE4 = sp2AC + sp20C;
                sp2A0 = spE0;
                sp2A4 = spE4;
                sp3E8 = 0.0f;
                sp3EC = var_f31_354;
                spD8 = M2C_FIELD(temp_r26_945, f32 *, 0x50) * 0.75f;
                spDC = M2C_FIELD(temp_r26_945, f32 *, 0x54) * 0.75f;
                sp3F0 = 0.3f;
                sp3F4 = 0.3f;
                sp3F8 = 0.3f;
                sp3FC = var_f31_354;
                sp400 = 1.0f;
                sp404 = 1.0f;
                sp408 = 1.0f;
                sp40C = var_f31_354;
                sp298 = spD8;
                sp29C = spDC;
                sp540 = (f64) sp3E0;
                sp548 = (f64) sp3E8;
                sp550 = (f64) sp3F0;
                sp558 = (f64) sp3F8;
                sp560 = (f64) sp400;
                sp568 = (f64) sp408;
                sp8 = 0.0f;
                Hud_DrawBarHorz(*((MKVector2 *) &sp318), *((MKVector2 *) &sp2A8), *((MKVector2 *) &sp2A0), *((MKVector2 *) &sp298), *((MKVector2 *) &sp2A0), *((MKVector4 *) &sp560), *((MKVector4 *) &sp550), *((MKVector4 *) &sp540), 0.75f * M2C_FIELD(M2C_FIELD(arg0, void **, 0), f32 *, 0x9C), M2C_FIELD(GameData::gameData, f32 *, 0xA0) / M2C_FIELD(GameData::gameData, f32 *, 0xA4), M2C_FIELD(GameData::gameData, f32 *, 0xA8) / M2C_FIELD(GameData::gameData, f32 *, 0xA4), M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
            }
        }
        temp_r26_1047 = M2C_FIELD(arg0, void **, 0);
        if (M2C_FIELD(temp_r26_1047, s32 *, 0) & 4) {
            spD0 = 0.0f;
            spD4 = 0.2f * M2C_FIELD(GameData::gameData, f32 *, 0x8C);
            sp290 = spD0;
            sp294 = spD4;
            spC8 = M2C_FIELD(temp_r26_1047, f32 *, 0x58) * 0.75f;
            spCC = M2C_FIELD(temp_r26_1047, f32 *, 0x5C) * 0.75f;
            spC0 = sp290 * 0.75f;
            spC4 = sp294 * 0.75f;
            sp288 = spC8;
            sp28C = spCC;
            sp200 = spC0;
            sp204 = spC4;
            sp3B0 = 0.0f;
            sp3B4 = 1.0f;
            spB8 = sp288 + sp200;
            spBC = sp28C + sp204;
            sp280 = spB8;
            sp284 = spBC;
            sp3B8 = 1.0f;
            sp3BC = var_f31_354;
            spB0 = M2C_FIELD(temp_r26_1047, f32 *, 0x60) * 0.75f;
            spB4 = M2C_FIELD(temp_r26_1047, f32 *, 0x64) * 0.75f;
            sp3C0 = 0.3f;
            sp3C4 = 0.3f;
            sp3C8 = 0.3f;
            sp3CC = var_f31_354;
            sp3D0 = 1.0f;
            sp3D4 = 1.0f;
            sp3D8 = 1.0f;
            sp3DC = var_f31_354;
            sp278 = spB0;
            sp27C = spB4;
            sp510 = (f64) sp3B0;
            sp518 = (f64) sp3B8;
            sp520 = (f64) sp3C0;
            sp528 = (f64) sp3C8;
            sp530 = (f64) sp3D0;
            sp538 = (f64) sp3D8;
            sp8 = 0.0f;
            Hud_DrawBarVert(*((MKVector2 *) &sp318), *((MKVector2 *) &sp288), *((MKVector2 *) &sp280), *((MKVector2 *) &sp278), *((MKVector2 *) &sp280), *((MKVector4 *) &sp530), *((MKVector4 *) &sp520), *((MKVector4 *) &sp510), 0.75f * M2C_FIELD(M2C_FIELD(arg0, void **, 0), f32 *, 0xA0), M2C_FIELD(GameData::gameData, f32 *, 0x88) / M2C_FIELD(GameData::gameData, f32 *, 0x8C), M2C_FIELD(GameData::gameData, f32 *, 0x90) / M2C_FIELD(GameData::gameData, f32 *, 0x8C), M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
        }
        temp_r4_1149 = M2C_FIELD(arg0, void **, 0);
        if (!(M2C_FIELD(temp_r4_1149, s32 *, 0) & 0x10)) {
            spA8 = M2C_FIELD(temp_r4_1149, f32 *, 0x28) * 0.75f;
            spAC = M2C_FIELD(temp_r4_1149, f32 *, 0x2C) * 0.75f;
            sp1F8 = spA8;
            sp1FC = spAC;
            spA0 = sp318 + sp1F8;
            spA4 = sp31C + sp1FC;
            sp270 = spA0;
            sp274 = spA4;
            M2C_STRUCT_COPY((s32) &sp68C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
            sp690.SetRotationRoll(-0.25f);
            sp9C = 8.0f;
            sp88 = 25.6f;
            sp8C = 25.6f;
            sp1EC = sp9C;
            sp3A0 = 1.0f;
            sp3A4 = 1.0f;
            sp3A8 = 1.0f;
            sp3AC = var_f31_354;
            sp500 = (f64) sp3A0;
            sp94 = sp274 + sp1EC;
            sp508 = (f64) sp3A8;
            sp1E0 = sp88;
            sp1E4 = sp8C;
            sp1F4 = sp94;
            sp98 = 0.75f * ((0.5f * M2C_FIELD(M2C_FIELD(arg0, void **, 0), f32 *, 0x88)) + 12.8f);
            sp1E8 = sp98;
            sp90 = sp270 + sp1E8;
            sp1F0 = sp90;
            Hud_DrawIcon(0, 0xD, *((MKVector2 *) &sp1F0), *((MKVector2 *) &sp1E0), *((MKVector4 *) &sp500), 0.0f, 0.0f, 1.0f, 1.0f, 1U, 1U, sp690);
            sp84 = 0.0f;
            sp70 = 19.2f;
            sp74 = 19.2f;
            sp398 = 1.0f;
            sp39C = var_f31_354;
            sp390 = 1.0f;
            sp394 = 1.0f;
            sp1D4 = sp84;
            sp4F8 = (f64) sp398;
            sp4F0 = (f64) sp390;
            sp1C8 = sp70;
            sp1CC = sp74;
            sp7C = sp274 - sp1D4;
            sp1DC = sp7C;
            sp80 = 0.75f * ((0.5f * M2C_FIELD(M2C_FIELD(arg0, void **, 0), f32 *, 0x88)) + 9.6f);
            sp1D0 = sp80;
            sp78 = sp270 - sp1D0;
            sp1D8 = sp78;
            Hud_DrawIcon(0, 0xD, *((MKVector2 *) &sp1D8), *((MKVector2 *) &sp1C8), *((MKVector4 *) &sp4F0), 0.0f, 0.0f, 1.0f, 1.0f, 0U, 0U, sp690);
        }
        temp_r12_1298 = M2C_FIELD(arg0, void **, 0);
        if (M2C_FIELD(temp_r12_1298, s32 *, 0) & 0x20) {
            sp380 = 1.0f;
            sp384 = 1.0f;
            sp388 = 1.0f;
            sp38C = var_f31_354;
            sp4E0 = (f64) sp380;
            sp4E8 = (f64) sp388;
            sp58 = M2C_FIELD(temp_r12_1298, f32 *, 0x80) * 0.75f;
            sp5C = M2C_FIELD(temp_r12_1298, f32 *, 0x84) * 0.75f;
            sp1B0 = sp58;
            sp1B4 = sp5C;
            sp68 = M2C_FIELD(temp_r12_1298, f32 *, 0x20) * 0.75f;
            sp6C = M2C_FIELD(temp_r12_1298, f32 *, 0x24) * 0.75f;
            sp1B8 = sp68;
            sp1BC = sp6C;
            sp60 = sp318 + sp1B8;
            sp64 = sp31C + sp1BC;
            sp1C0 = sp60;
            sp1C4 = sp64;
            Hud_DrawIcon(0, 3, *((MKVector2 *) &sp1C0), *((MKVector2 *) &sp1B0), *((MKVector4 *) &sp4E0), 0.0f, 0.0f, 1.0f, 1.0f, 0U, 0U, Matrix::identity);
        }
        temp_r4_1358 = M2C_FIELD(arg0, void **, 0);
        if (M2C_FIELD(temp_r4_1358, s32 *, 0) & 0x80) {
            sp50 = M2C_FIELD(temp_r4_1358, f32 *, 0x28) * 0.75f;
            sp54 = M2C_FIELD(temp_r4_1358, f32 *, 0x2C) * 0.75f;
            sp1A8 = sp50;
            sp1AC = sp54;
            sp48 = sp318 + sp1A8;
            sp4C = sp31C + sp1AC;
            sp268 = sp48;
            sp26C = sp4C;
            sp40 = M2C_FIELD(temp_r4_1358, f32 *, 0x88) * 0.75f;
            sp44 = M2C_FIELD(temp_r4_1358, f32 *, 0x8C) * 0.75f;
            sp260 = sp40;
            sp264 = sp44;
            if (temp_r30_401 == 0) {
                sp370 = 0.8f;
                sp374 = 0.0f;
                sp378 = 0.8f;
                sp37C = var_f31_354;
                sp360 = 0.3f;
                sp364 = 0.0f;
                sp368 = 0.3f;
                sp36C = var_f31_354;
                sp630 = (f64) sp370;
                sp638 = (f64) sp378;
                sp620 = (f64) sp360;
                sp628 = (f64) sp368;
                sp8 = 6.2831855f;
                spC = 6.2831855f;
                sp10 = 0.0f;
                sp14 = 0.0f;
                sp18 = 1.0f;
                sp1C = 1.0f;
                Hud_DrawArc(sp268, sp26C, 0.35f * sp260, 0.35f * sp264, 0.0f, 0.0f, 0.0f, 0.0f, (f32) (f64) sp378, (f32) (f64) sp370, (MKVector4 *) &sp630, (MKVector4 *) &sp620, NULL, NULL, M2C_ERROR(/* Read from unset register $f11 */), M2C_ERROR(/* Read from unset register $f12 */), M2C_ERROR(/* Read from unset register $f13 */), M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
            }
            if (temp_r30_401 != 0) {
                sp350 = 1.0f;
                sp38 = sp260 * 0.68f;
                temp_r0_1456 = M2C_FIELD(&gb, u8 *, 0x35D) - 1;
                sp354 = 1.0f;
                sp3C = sp264 * 0.68f;
                sp358 = 1.0f;
                sp35C = var_f31_354;
                sp4D0 = (f64) sp350;
                sp4D8 = (f64) sp358;
                sp1A0 = sp38;
                sp1A4 = sp3C;
                Hud_DrawIcon(M2C_FIELD(GameData::gameData, s32 *, 0x15C), 8 & ~((temp_r0_1456 - temp_r0_1456) - !M2C_CARRY), *((MKVector2 *) &sp268), *((MKVector2 *) &sp1A0), *((MKVector4 *) &sp4D0), 0.0f, 0.0f, 1.0f, 1.0f, 0U, 0U, Matrix::identity);
            }
            sp340 = 1.0f;
            sp344 = 1.0f;
            sp348 = 1.0f;
            sp34C = var_f31_354;
            sp4C0 = (f64) sp340;
            sp4C8 = (f64) sp348;
            Hud_DrawIcon(0, 3, *((MKVector2 *) &sp268), *((MKVector2 *) &sp260), *((MKVector4 *) &sp4C0), 0.0f, 0.0f, 1.0f, 1.0f, 0U, 0U, Matrix::identity);
        }
        if (temp_r30_401 != 0) {
            temp_r3_1507 = M2C_FIELD(arg0, void **, 0);
            if (M2C_FIELD(temp_r3_1507, s32 *, 0) & 8) {
                temp_f0_1515 = M2C_FIELD(GameData::gameData, f32 *, 0xB8) / M2C_FIELD(GameData::gameData, f32 *, 0xBC);
                var_f1_1519 = 1.0f;
                sp30 = M2C_FIELD(temp_r3_1507, f32 *, 0x28) * 0.75f;
                sp34 = M2C_FIELD(temp_r3_1507, f32 *, 0x2C) * 0.75f;
                sp198 = sp30;
                sp19C = sp34;
                sp20 = M2C_FIELD(temp_r3_1507, f32 *, 0x88) * 0.75f;
                sp24 = M2C_FIELD(temp_r3_1507, f32 *, 0x8C) * 0.75f;
                sp28 = sp318 + sp198;
                sp2C = sp31C + sp19C;
                sp258 = sp28;
                sp25C = sp2C;
                sp250 = sp20;
                sp254 = sp24;
                M2C_ERROR(/* unknown instruction: cror 0x2, 0x1, 0x2 */);
                if (temp_f0_1515 == 1.0f) {
                    var_f3_1567 = (M2C_FIELD(&gb, f32 *, 0x30C) - (f32) (s32) M2C_FIELD(&gb, f32 *, 0x30C)) - 0.5f;
                    if (var_f3_1567 < 0.0f) {
                        var_f3_1567 = -var_f3_1567;
                    }
                    var_f1_1519 = 0.5f + var_f3_1567;
                }
                sp330 = 0.753f * var_f1_1519;
                sp334 = 0.0f;
                sp338 = 0.95f * var_f1_1519;
                sp33C = var_f31_354;
                temp_f26_1596 = -((6.2831855f * temp_f0_1515) - -1.6650441f);
                temp_f29_1603 = 0.41f * sp254;
                temp_f28_1604 = 0.41f * sp250;
                sp320 = 0.867f * var_f1_1519;
                sp324 = 0.357f * var_f1_1519;
                sp328 = var_f1_1519;
                sp32C = var_f31_354;
                sp610 = (f64) sp330;
                sp618 = (f64) sp338;
                sp600 = (f64) sp320;
                sp608 = (f64) sp328;
                sp8 = -1.6650441f;
                spC = -1.6650441f;
                sp10 = 0.0f;
                sp14 = 0.0f;
                sp18 = 1.0f;
                sp1C = 1.0f;
                Hud_DrawArc(sp258, sp25C, 0.47f * sp250, 0.47f * sp254, temp_f28_1604, temp_f29_1603, temp_f26_1596, temp_f26_1596, -1.6650441f, (f32) (f64) sp328, (MKVector4 *) &sp610, (MKVector4 *) &sp610, NULL, NULL, (f32) (f64) sp320, (f32) (f64) sp338, (f32) (f64) sp330, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
                sp8 = -1.6650441f;
                spC = -1.6650441f;
                sp10 = 0.0f;
                sp14 = 0.0f;
                sp18 = 1.0f;
                sp1C = 1.0f;
                Hud_DrawArc(sp258, sp25C, temp_f28_1604, temp_f29_1603, 0.38f * sp250, 0.38f * sp254, temp_f26_1596, temp_f26_1596, 1.0f, 0.0f, (MKVector4 *) &sp600, (MKVector4 *) &sp600, NULL, NULL, M2C_ERROR(/* Read from unset register $f11 */), M2C_ERROR(/* Read from unset register $f12 */), M2C_ERROR(/* Read from unset register $f13 */), M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
                sp8 = -1.6650441f;
                spC = -1.6650441f;
                sp10 = 0.0f;
                sp14 = 0.0f;
                sp18 = 1.0f;
                sp1C = 1.0f;
                Hud_DrawArc(sp258, sp25C, 0.425f * sp250, 0.425f * sp254, 0.39f * sp250, 0.39f * sp254, temp_f26_1596, temp_f26_1596, 1.0f, M2C_ERROR(/* Read from unset register $f10 */), (MKVector4 *) &sp610, (MKVector4 *) &sp600, NULL, NULL, M2C_ERROR(/* Read from unset register $f11 */), M2C_ERROR(/* Read from unset register $f12 */), M2C_ERROR(/* Read from unset register $f13 */), M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
            }
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp8'
void Hud_DrawBarVert(const MKVector2 &arg0, const MKVector2 &arg1, const MKVector2 &arg2, const MKVector2 &arg3, const MKVector2 &arg4, const MKVector4 &arg5, const MKVector4 &arg6, const MKVector4 &arg7, float arg8, float arg9, float arg10, bool arg11) {
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
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
    f32 temp_f23_1796;
    f32 temp_f28_1756;
    f32 temp_f28_1919;
    f32 temp_f29_1734;
    f32 temp_f29_1791;
    f32 temp_f29_1951;
    f32 temp_f2_1917;
    f32 temp_f3_1923;
    f32 temp_f5_1730;
    f32 temp_f6_1728;
    f32 var_f0_1760;
    f32 var_f0_1769;
    f32 var_f0_1853;
    f32 var_f0_1864;
    f32 var_f0_1895;
    f32 var_f0_1906;
    f32 var_f26_1754;
    f32 var_f27_1755;
    f32 var_f2_1943;
    f32 var_f2_2009;
    f32 var_f4_1742;
    f32 var_f4_1920;
    f32 var_f4_2004;
    f32 var_f5_1960;
    f32 var_f5_2026;
    f64 temp_f0_1823;
    f64 temp_f0_1834;

    temp_f6_1728 = arg4.unk4;
    temp_f5_1730 = arg3.unk4;
    temp_f29_1734 = 0.6f * arg8;
    if (temp_f6_1728 > temp_f5_1730) {
        var_f4_1742 = temp_f29_1734;
    } else {
        var_f4_1742 = -temp_f29_1734;
    }
    var_f26_1754 = (0.5f * var_f4_1742) + (temp_f6_1728 - temp_f5_1730);
    var_f27_1755 = arg0.unk4 + temp_f5_1730;
    temp_f28_1756 = -((0.5f * temp_f29_1734) - (arg0.unk0 + arg3.unk0));
    if (arg_sp8 != 0) {
        if (temp_f6_1728 > temp_f5_1730) {
            var_f0_1760 = temp_f29_1734;
        } else {
            var_f0_1760 = -temp_f29_1734;
        }
        var_f26_1754 += 0.5f * var_f0_1760;
        if (temp_f6_1728 > temp_f5_1730) {
            var_f0_1769 = -temp_f29_1734;
        } else {
            var_f0_1769 = temp_f29_1734;
        }
        var_f27_1755 += 0.5f * var_f0_1769;
    }
    MKMaterial_SetMaterial(M2C_FIELD(&gb, MKMaterial **, 0x328));
    MKPrimitive(0xC, 3);
    MKBegin(4);
    MKSetColorV(arg6);
    MKSetPositionF(temp_f28_1756, var_f27_1755, 0.0f);
    temp_f29_1791 = temp_f28_1756 + temp_f29_1734;
    MKSetPositionF(temp_f29_1791, var_f27_1755, 0.0f);
    temp_f23_1796 = var_f27_1755 + var_f26_1754;
    MKSetPositionF(temp_f28_1756, temp_f23_1796, 0.0f);
    MKSetPositionF(temp_f29_1791, temp_f23_1796, 0.0f);
    MKEnd();
    MKEndPrimitive();
    if (arg9 != arg10) {
        MKMaterial_SetMaterial(M2C_FIELD(&gb, MKMaterial **, 0x328));
        MKPrimitive(0xC, 3);
        MKBegin(4);
        spB8 = M2C_FIELD(&arg6, f64 *, 0) + M2C_FIELD(&arg7, f64 *, 0);
        temp_f0_1823 = M2C_FIELD(&arg6, f64 *, 8) + M2C_FIELD(&arg7, f64 *, 8);
        spC0 = temp_f0_1823;
        spC8 = spB8;
        spD0 = temp_f0_1823;
        spA8 = spC8 * 5.222099017e-315;
        temp_f0_1834 = temp_f0_1823 * 5.222099017e-315;
        spB0 = temp_f0_1834;
        spD8 = spA8;
        spE0 = temp_f0_1834;
        MKSetColorV(*((MKVector4 *) &spD8));
        MKSetPositionF(temp_f28_1756, var_f27_1755, 0.0f);
        MKSetPositionF(temp_f29_1791, var_f27_1755, 0.0f);
        if (arg9 > arg10) {
            var_f0_1853 = arg9;
        } else {
            var_f0_1853 = arg10;
        }
        MKSetPositionF(temp_f28_1756, (var_f26_1754 * var_f0_1853) + var_f27_1755, 0.0f);
        if (arg9 > arg10) {
            var_f0_1864 = arg9;
        } else {
            var_f0_1864 = arg10;
        }
        MKSetPositionF(temp_f29_1791, (var_f26_1754 * var_f0_1864) + var_f27_1755, 0.0f);
        MKEnd();
        MKEndPrimitive();
    }
    MKMaterial_SetMaterial(M2C_FIELD(&gb, MKMaterial **, 0x328));
    MKPrimitive(0xC, 3);
    MKBegin(4);
    MKSetColorV(arg7);
    MKSetPositionF(temp_f28_1756, var_f27_1755, 0.0f);
    MKSetPositionF(temp_f29_1791, var_f27_1755, 0.0f);
    if (arg9 < arg10) {
        var_f0_1895 = arg9;
    } else {
        var_f0_1895 = arg10;
    }
    MKSetPositionF(temp_f28_1756, (var_f26_1754 * var_f0_1895) + var_f27_1755, 0.0f);
    if (arg9 < arg10) {
        var_f0_1906 = arg9;
    } else {
        var_f0_1906 = arg10;
    }
    MKSetPositionF(temp_f29_1791, (var_f26_1754 * var_f0_1906) + var_f27_1755, 0.0f);
    MKEnd();
    MKEndPrimitive();
    temp_f2_1917 = arg1.unk4;
    temp_f28_1919 = arg2.unk4 - temp_f2_1917;
    var_f4_1920 = 0.5f;
    sp50 = 0.0f;
    temp_f3_1923 = 0.5f * temp_f28_1919;
    sp98 = sp50;
    sp54 = temp_f3_1923;
    sp9C = sp54;
    sp48 = arg1.unk0 + sp98;
    sp4C = temp_f2_1917 + sp9C;
    spA0 = sp48;
    spA4 = sp4C;
    if (temp_f28_1919 > 0.0f) {
        var_f4_1920 = 1.0f;
    }
    var_f2_1943 = 0.0f;
    if (temp_f28_1919 > 0.0f) {
        var_f2_1943 = 0.5f;
    }
    sp30 = arg8;
    temp_f29_1951 = 0.5f * arg8;
    sp34 = temp_f29_1951;
    sp80 = sp30;
    sp84 = sp34;
    if (temp_f28_1919 > 0.0f) {
        var_f5_1960 = arg8;
    } else {
        var_f5_1960 = -arg8;
    }
    sp40 = spA0;
    sp88 = sp40;
    sp44 = (0.25f * var_f5_1960) + (spA4 + temp_f3_1923);
    sp8C = sp44;
    sp38 = arg0.unk0 + sp88;
    sp3C = arg0.unk4 + sp8C;
    sp90 = sp38;
    sp94 = sp3C;
    Hud_DrawIcon(0, 3, *((MKVector2 *) &sp90), *((MKVector2 *) &sp80), arg5, 0.0f, var_f2_1943, 1.0f, var_f4_1920, 0U, 0U, Matrix::identity);
    if (arg_sp8 != 0) {
        if (temp_f28_1919 > 0.0f) {
            var_f4_2004 = 0.5f;
        } else {
            var_f4_2004 = 1.0f;
        }
        var_f2_2009 = 0.0f;
        if (temp_f28_1919 > 0.0f) {

        } else {
            var_f2_2009 = 0.5f;
        }
        sp18 = arg8;
        sp1C = temp_f29_1951;
        sp68 = sp18;
        sp6C = sp1C;
        if (temp_f28_1919 > 0.0f) {
            var_f5_2026 = -arg8;
        } else {
            var_f5_2026 = arg8;
        }
        sp28 = spA0;
        sp2C = (0.25f * var_f5_2026) + arg1.unk4;
        sp70 = sp28;
        sp74 = sp2C;
        sp20 = arg0.unk0 + sp70;
        sp24 = arg0.unk4 + sp74;
        sp78 = sp20;
        sp7C = sp24;
        Hud_DrawIcon(0, 3, *((MKVector2 *) &sp78), *((MKVector2 *) &sp68), arg5, 0.0f, var_f2_2009, 1.0f, var_f4_2004, 0U, 0U, Matrix::identity);
    }
    sp8 = arg8;
    spC = temp_f28_1919;
    sp10 = arg0.unk0 + spA0;
    sp14 = arg0.unk4 + spA4;
    sp58 = sp8;
    sp5C = spC;
    sp60 = sp10;
    sp64 = sp14;
    Hud_DrawIcon(0, 3, *((MKVector2 *) &sp60), *((MKVector2 *) &sp58), arg5, 0.0f, 0.5f, 1.0f, 0.5f, 0U, 0U, Matrix::identity);
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp8'
void Hud_DrawBarHorz(const MKVector2 &arg0, const MKVector2 &arg1, const MKVector2 &arg2, const MKVector2 &arg3, const MKVector2 &arg4, const MKVector4 &arg5, const MKVector4 &arg6, const MKVector4 &arg7, float arg8, float arg9, float arg10, bool arg11) {
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f32 sp144;
    f32 sp140;
    f32 sp13C;
    f32 sp138;
    f32 sp134;
    f32 sp130;
    f32 sp12C;
    f32 sp128;
    f32 sp124;
    f32 sp120;
    f32 sp11C;
    f32 sp118;
    f32 sp114;
    f32 sp110;
    f32 sp10C;
    f32 sp108;
    f32 sp104;
    f32 sp100;
    f32 spFC;
    f32 spF8;
    f32 spF4;
    f32 spF0;
    f32 spEC;
    f32 spE8;
    f32 spE4;
    f32 spE0;
    f32 spDC;
    f32 spD8;
    f32 spD4;
    f32 spD0;
    f32 spCC;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
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
    f32 temp_f23_2211;
    f32 temp_f23_2381;
    f32 temp_f27_2339;
    f32 temp_f28_2176;
    f32 temp_f29_2342;
    f32 temp_f30_2154;
    f32 temp_f30_2216;
    f32 temp_f31_2415;
    f32 temp_f3_2346;
    f32 temp_f4_2340;
    f32 temp_f5_2150;
    f32 temp_f6_2148;
    f32 var_f0_2180;
    f32 var_f0_2189;
    f32 var_f0_2268;
    f32 var_f0_2283;
    f32 var_f0_2310;
    f32 var_f0_2325;
    f32 var_f0_2426;
    f32 var_f27_2174;
    f32 var_f29_2175;
    f32 var_f2_2478;
    f32 var_f2_2529;
    f32 var_f4_2162;
    f32 var_f4_2372;
    f64 temp_f0_2243;
    f64 temp_f0_2254;

    temp_f6_2148 = arg4.unk0;
    temp_f5_2150 = arg3.unk0;
    temp_f30_2154 = 0.7f * arg8;
    if (temp_f6_2148 > temp_f5_2150) {
        var_f4_2162 = temp_f30_2154;
    } else {
        var_f4_2162 = -temp_f30_2154;
    }
    var_f27_2174 = (0.5f * var_f4_2162) + (temp_f6_2148 - temp_f5_2150);
    var_f29_2175 = arg0.unk0 + temp_f5_2150;
    temp_f28_2176 = -((0.5f * temp_f30_2154) - (arg0.unk4 + arg3.unk4));
    if (arg_sp8 != 0) {
        if (temp_f6_2148 > temp_f5_2150) {
            var_f0_2180 = temp_f30_2154;
        } else {
            var_f0_2180 = -temp_f30_2154;
        }
        var_f27_2174 += 0.5f * var_f0_2180;
        if (temp_f6_2148 > temp_f5_2150) {
            var_f0_2189 = -temp_f30_2154;
        } else {
            var_f0_2189 = temp_f30_2154;
        }
        var_f29_2175 += 0.5f * var_f0_2189;
    }
    MKMaterial_SetMaterial(M2C_FIELD(&gb, MKMaterial **, 0x328));
    MKPrimitive(0xC, 3);
    MKBegin(4);
    MKSetColorV(arg6);
    MKSetPositionF(var_f29_2175, temp_f28_2176, 0.0f);
    temp_f23_2211 = var_f29_2175 + var_f27_2174;
    MKSetPositionF(temp_f23_2211, temp_f28_2176, 0.0f);
    temp_f30_2216 = temp_f28_2176 + temp_f30_2154;
    MKSetPositionF(var_f29_2175, temp_f30_2216, 0.0f);
    MKSetPositionF(temp_f23_2211, temp_f30_2216, 0.0f);
    MKEnd();
    MKEndPrimitive();
    if (arg9 != arg10) {
        MKMaterial_SetMaterial(M2C_FIELD(&gb, MKMaterial **, 0x328));
        MKPrimitive(0xC, 3);
        MKBegin(4);
        sp158 = M2C_FIELD(&arg6, f64 *, 0) + M2C_FIELD(&arg7, f64 *, 0);
        temp_f0_2243 = M2C_FIELD(&arg6, f64 *, 8) + M2C_FIELD(&arg7, f64 *, 8);
        sp160 = temp_f0_2243;
        sp168 = sp158;
        sp170 = temp_f0_2243;
        sp148 = sp168 * 5.222099017e-315;
        temp_f0_2254 = temp_f0_2243 * 5.222099017e-315;
        sp150 = temp_f0_2254;
        sp178 = sp148;
        sp180 = temp_f0_2254;
        MKSetColorV(*((MKVector4 *) &sp178));
        MKSetPositionF(var_f29_2175, temp_f28_2176, 0.0f);
        if (arg9 > arg10) {
            var_f0_2268 = arg9;
        } else {
            var_f0_2268 = arg10;
        }
        MKSetPositionF((var_f27_2174 * var_f0_2268) + var_f29_2175, temp_f28_2176, 0.0f);
        MKSetPositionF(var_f29_2175, temp_f30_2216, 0.0f);
        if (arg9 > arg10) {
            var_f0_2283 = arg9;
        } else {
            var_f0_2283 = arg10;
        }
        MKSetPositionF((var_f27_2174 * var_f0_2283) + var_f29_2175, temp_f30_2216, 0.0f);
        MKEnd();
        MKEndPrimitive();
    }
    MKMaterial_SetMaterial(M2C_FIELD(&gb, MKMaterial **, 0x328));
    MKPrimitive(0xC, 3);
    MKBegin(4);
    MKSetColorV(arg7);
    MKSetPositionF(var_f29_2175, temp_f28_2176, 0.0f);
    if (arg9 < arg10) {
        var_f0_2310 = arg9;
    } else {
        var_f0_2310 = arg10;
    }
    MKSetPositionF((var_f27_2174 * var_f0_2310) + var_f29_2175, temp_f28_2176, 0.0f);
    MKSetPositionF(var_f29_2175, temp_f30_2216, 0.0f);
    if (arg9 < arg10) {
        var_f0_2325 = arg9;
    } else {
        var_f0_2325 = arg10;
    }
    MKSetPositionF((var_f27_2174 * var_f0_2325) + var_f29_2175, temp_f30_2216, 0.0f);
    MKEnd();
    MKEndPrimitive();
    temp_f27_2339 = 0.5f * arg8;
    temp_f4_2340 = arg1.unk0;
    temp_f29_2342 = arg2.unk0 - temp_f4_2340;
    sp80 = temp_f27_2339;
    temp_f3_2346 = 0.5f * temp_f29_2342;
    spA4 = -0.5f * temp_f27_2339;
    spA0 = temp_f3_2346;
    sp13C = spA4;
    sp138 = spA0;
    sp84 = temp_f27_2339;
    sp9C = arg1.unk4 + sp13C;
    sp98 = temp_f4_2340 + sp138;
    sp144 = sp9C;
    sp140 = sp98;
    sp120 = sp80;
    sp124 = sp84;
    if (temp_f29_2342 > 0.0f) {
        var_f4_2372 = arg8;
    } else {
        var_f4_2372 = -arg8;
    }
    temp_f23_2381 = sp140 + temp_f3_2346;
    sp94 = sp144;
    sp12C = sp94;
    sp90 = (0.25f * var_f4_2372) + temp_f23_2381;
    sp128 = sp90;
    sp8C = arg0.unk4 + sp12C;
    sp88 = arg0.unk0 + sp128;
    sp134 = sp8C;
    sp130 = sp88;
    Hud_DrawIcon(0, 5, *((MKVector2 *) &sp130), *((MKVector2 *) &sp120), arg5, 0.0f, 0.0f, 1.0f, 1.0f, (u8) ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1FU), 0U, Matrix::identity);
    sp68 = temp_f27_2339;
    temp_f31_2415 = sp144 + temp_f27_2339;
    sp6C = temp_f27_2339;
    sp108 = sp68;
    sp10C = sp6C;
    if (temp_f29_2342 > 0.0f) {
        var_f0_2426 = arg8;
    } else {
        var_f0_2426 = -arg8;
    }
    sp7C = temp_f31_2415;
    sp78 = (0.25f * var_f0_2426) + temp_f23_2381;
    sp114 = sp7C;
    sp110 = sp78;
    sp70 = arg0.unk0 + sp110;
    sp74 = arg0.unk4 + sp114;
    sp118 = sp70;
    sp11C = sp74;
    Hud_DrawIcon(0, 6, *((MKVector2 *) &sp118), *((MKVector2 *) &sp108), arg5, 0.0f, 0.0f, 1.0f, 1.0f, (u8) ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1FU), 0U, Matrix::identity);
    if (arg_sp8 != 0) {
        sp50 = temp_f27_2339;
        sp54 = temp_f27_2339;
        spF0 = sp50;
        spF4 = sp54;
        if (temp_f29_2342 > 0.0f) {
            var_f2_2478 = -arg8;
        } else {
            var_f2_2478 = arg8;
        }
        sp64 = sp144;
        sp60 = (0.25f * var_f2_2478) + arg1.unk0;
        spFC = sp64;
        spF8 = sp60;
        sp5C = arg0.unk4 + spFC;
        sp58 = arg0.unk0 + spF8;
        sp104 = sp5C;
        sp100 = sp58;
        Hud_DrawIcon(0, 4, *((MKVector2 *) &sp100), *((MKVector2 *) &spF0), arg5, 0.0f, 0.0f, 1.0f, 1.0f, (u8) ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1FU), 0U, Matrix::identity);
        sp38 = temp_f27_2339;
        sp3C = temp_f27_2339;
        spD8 = sp38;
        spDC = sp3C;
        if (temp_f29_2342 > 0.0f) {
            var_f2_2529 = -arg8;
        } else {
            var_f2_2529 = arg8;
        }
        sp4C = temp_f31_2415;
        sp48 = (0.25f * var_f2_2529) + arg1.unk0;
        spE4 = sp4C;
        spE0 = sp48;
        sp44 = arg0.unk4 + spE4;
        sp40 = arg0.unk0 + spE0;
        spEC = sp44;
        spE8 = sp40;
        Hud_DrawIcon(0, 7, *((MKVector2 *) &spE8), *((MKVector2 *) &spD8), arg5, 0.0f, 0.0f, 1.0f, 1.0f, (u8) ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1FU), 0U, Matrix::identity);
    }
    sp28 = temp_f29_2342;
    sp2C = temp_f27_2339;
    sp30 = arg0.unk0 + sp140;
    sp34 = arg0.unk4 + sp144;
    spC8 = sp28;
    spCC = sp2C;
    spD0 = sp30;
    spD4 = sp34;
    Hud_DrawIcon(0, 9, *((MKVector2 *) &spD0), *((MKVector2 *) &spC8), arg5, 0.0f, 0.0f, 1.0f, 1.0f, 0U, 0U, Matrix::identity);
    sp1C = temp_f27_2339;
    sp18 = 0.0f;
    sp20 = arg0.unk0 + sp140;
    sp24 = arg0.unk4 + sp144;
    spB0 = sp18;
    spB4 = sp1C;
    spB8 = sp20;
    spBC = sp24;
    sp8 = temp_f29_2342;
    spC = temp_f27_2339;
    sp10 = spB8 + spB0;
    sp14 = spBC + spB4;
    spA8 = sp8;
    spAC = spC;
    spC0 = sp10;
    spC4 = sp14;
    Hud_DrawIcon(0, 0xA, *((MKVector2 *) &spC0), *((MKVector2 *) &spA8), arg5, 0.0f, 0.0f, 1.0f, 1.0f, 0U, 0U, Matrix::identity);
}
#endif

s32 SpyroHud_Update(void *arg0) {
    f32 temp_f1_2769;
    f32 temp_f2_2772;
    f32 temp_f3_2770;
    f32 var_f0_2777;
    f32 var_f0_2782;
    f32 var_f0_2801;
    f32 var_f0_2806;
    s32 var_r3_2829;

    if ((*M2C_FIELD(arg0, s32 **, 0) & 1) && (M2C_FIELD(GameData::gameData, f32 *, 0x78) != M2C_FIELD(GameData::gameData, f32 *, 0x70))) {
        M2C_FIELD(arg0, f32 *, 4) = 2.0f;
        ((Stat *) &GameData::gameData[0x70])->AdjustPrevious(gUpdateTimeDelta / 3.0f);
    }
    if ((*M2C_FIELD(arg0, s32 **, 0) & 2) && (M2C_FIELD(GameData::gameData, f32 *, 0xA8) != M2C_FIELD(GameData::gameData, f32 *, 0xA0))) {
        M2C_FIELD(arg0, f32 *, 4) = 2.0f;
        ((Stat *) &GameData::gameData[0xA0])->AdjustPrevious(gUpdateTimeDelta / 3.0f);
    }
    if ((*M2C_FIELD(arg0, s32 **, 0) & 4) && (M2C_FIELD(GameData::gameData, f32 *, 0x90) != M2C_FIELD(GameData::gameData, f32 *, 0x88))) {
        M2C_FIELD(arg0, f32 *, 4) = 2.0f;
        ((Stat *) &GameData::gameData[0x88])->AdjustPrevious(gUpdateTimeDelta / 3.0f);
    }
    if ((*M2C_FIELD(arg0, s32 **, 0) & 8) && (M2C_FIELD(GameData::gameData, f32 *, 0xC0) != M2C_FIELD(GameData::gameData, f32 *, 0xB8))) {
        M2C_FIELD(arg0, f32 *, 4) = 2.0f;
        ((Stat *) &GameData::gameData[0xB8])->AdjustPrevious(gUpdateTimeDelta / 3.0f);
    }
    if ((*M2C_FIELD(arg0, s32 **, 0) & 0x10) && (M2C_FIELD(arg0, f32 *, 0x2C) != M2C_FIELD(arg0, f32 *, 0x28))) {
        M2C_FIELD(arg0, f32 *, 4) = 2.0f;
        temp_f1_2769 = M2C_FIELD(arg0, f32 *, 0x28);
        temp_f3_2770 = M2C_FIELD(arg0, f32 *, 0x2C);
        temp_f2_2772 = M2C_FIELD(arg0, f32 *, 0x30) * (gUpdateTimeDelta / 3.0f);
        if (temp_f1_2769 < temp_f3_2770) {
            if (temp_f2_2772 < 0.0f) {
                var_f0_2777 = -temp_f2_2772;
            } else {
                var_f0_2777 = temp_f2_2772;
            }
            var_f0_2782 = temp_f1_2769 + var_f0_2777;
            if (var_f0_2782 < temp_f3_2770) {

            } else {
                var_f0_2782 = temp_f3_2770;
            }
            if (var_f0_2782 > temp_f1_2769) {

            } else {
                var_f0_2782 = temp_f1_2769;
            }
            M2C_FIELD(arg0, f32 *, 0x28) = var_f0_2782;
        } else {
            if (temp_f2_2772 < 0.0f) {
                var_f0_2801 = -temp_f2_2772;
            } else {
                var_f0_2801 = temp_f2_2772;
            }
            var_f0_2806 = temp_f1_2769 - var_f0_2801;
            if (var_f0_2806 < temp_f1_2769) {

            } else {
                var_f0_2806 = temp_f1_2769;
            }
            if (var_f0_2806 > temp_f3_2770) {

            } else {
                var_f0_2806 = temp_f3_2770;
            }
            M2C_FIELD(arg0, f32 *, 0x28) = var_f0_2806;
        }
    }
    M2C_FIELD(arg0, f32 *, 4) = (f32) (M2C_FIELD(arg0, f32 *, 4) - gUpdateTimeDelta);
    var_r3_2829 = 0;
    M2C_FIELD(arg0, u8 *, 0x34) = (u8) (((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1EU) & 1);
    if (((u8) M2C_FIELD(arg0, u8 *, 0x34) != 0) || ((u32) M2C_FIELD(&gb, u32 *, 0x360) != 0U)) {
        var_r3_2829 = 1;
    }
    return var_r3_2829;
}

#if 0 // DRAFT: '(' expected
void SpyroHud_cpp::__sinit() {
    f32 sp84;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
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
    void *temp_r11_2867;
    void *temp_r8_2869;

    __construct_array(&hudData, &HudData::HudData, 0, 0x38, 2);
    temp_r11_2867 = &HUD_BAR_BACKGROUND + 0x10;
    temp_r8_2869 = &HUD_BAR_BACKGROUND + 0x60;
    sp20 = 50.0f;
    sp24 = 0.0f;
    sp18 = 100.0f;
    sp1C = 0.0f;
    sp10 = 150.0f;
    sp14 = 0.0f;
    sp8 = 300.0f;
    spC = 0.0f;
    sp78 = 0.35f;
    sp7C = 0.35f;
    sp80 = 0.35f;
    sp84 = 1.0f;
    sp68 = 1.0f;
    sp6C = 0.0f;
    sp70 = 0.0f;
    sp74 = 1.0f;
    sp58 = 1.0f;
    sp5C = 0.45f;
    sp60 = 0.0f;
    sp64 = 1.0f;
    sp48 = 1.0f;
    sp4C = 1.0f;
    sp50 = 0.0f;
    sp54 = 1.0f;
    sp38 = 0.0f;
    sp3C = 1.0f;
    sp40 = 0.0f;
    sp44 = 1.0f;
    sp28 = 0.0f;
    sp2C = 0.0f;
    sp30 = 1.0f;
    sp34 = 1.0f;
    M2C_FIELD(&HUD_BAR_BACKGROUND, f64 *, 0) = (f64) sp78;
    M2C_FIELD(&HUD_BAR_BACKGROUND, f64 *, 8) = (f64) sp80;
    M2C_FIELD(&HUD_BAR_BACKGROUND, f64 *, 0x10) = (f64) sp68;
    M2C_FIELD(&HUD_BAR_BACKGROUND, f64 *, 0x18) = (f64) sp70;
    M2C_FIELD(temp_r11_2867, f64 *, 0x10) = (f64) sp58;
    M2C_FIELD(temp_r11_2867, f64 *, 0x18) = (f64) sp60;
    M2C_FIELD(temp_r11_2867, f64 *, 0x20) = (f64) sp48;
    M2C_FIELD(temp_r11_2867, f64 *, 0x28) = (f64) sp50;
    M2C_FIELD(temp_r11_2867, f64 *, 0x30) = (f64) sp38;
    M2C_FIELD(temp_r11_2867, f64 *, 0x38) = (f64) sp40;
    M2C_FIELD(temp_r11_2867, f64 *, 0x40) = (f64) sp28;
    M2C_FIELD(temp_r11_2867, f64 *, 0x48) = (f64) sp30;
    M2C_FIELD(&HUD_BAR_BACKGROUND, f32 *, 0x60) = sp20;
    M2C_FIELD(&HUD_BAR_BACKGROUND, f32 *, 0x64) = sp24;
    M2C_FIELD(temp_r8_2869, f32 *, 8) = sp18;
    M2C_FIELD(temp_r8_2869, f32 *, 0xC) = sp1C;
    M2C_FIELD(temp_r8_2869, f32 *, 0x10) = sp10;
    M2C_FIELD(temp_r8_2869, f32 *, 0x14) = sp14;
    M2C_FIELD(temp_r8_2869, f32 *, 0x18) = sp8;
    M2C_FIELD(temp_r8_2869, f32 *, 0x1C) = spC;
}
#endif
