#include "spyro/source/EnemyDeathFX.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "spyro/source/Collectable.h"
#include "spyro/source/Coronas.h"
#include "spyro/source/EmbersPS.h"
#include "spyro/source/GameData.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

extern s32 GS_GemSpawn1;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;

static s32 lit_634 = 2;
static u8 lit_635 = 0;

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void EnemyDeathFX::Trigger(int *arg0, const MKVector3 &arg1, float arg2, int arg3) {
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    Corona *temp_r3_57;
    Corona *temp_r3_69;
    f32 temp_f27_135;
    f32 temp_f27_98;
    f32 temp_f28_140;
    f32 temp_f28_93;
    f32 temp_f31_88;
    f32 temp_f3_200;
    f32 temp_f3_258;
    f32 var_f1_208;
    f32 var_f1_266;
    f64 temp_f0_112;
    f64 temp_f0_122;
    s32 temp_r0_355;
    s32 temp_r28_301;
    s32 var_ctr_353;
    s32 var_r28_81;
    s32 var_r30_186;
    s32 var_r3_352;
    s32 var_r4_347;

    temp_r3_57 = this->unk64;
    if (temp_r3_57 != NULL) {
        temp_r3_57->unk0 = M2C_FIELD(&arg1, f64 *, 0);
        temp_r3_57->unk8 = M2C_FIELD(&arg1, f64 *, 8);
        this->unk64->unk24 = 12.0f * arg2;
        temp_r3_69 = this->unk64;
        temp_r3_69->unk31 |= 0x40;
    }
    this->unk68 = arg2;
    this->unk50 = M2C_FIELD(&arg1, f64 *, 0);
    var_r28_81 = 0;
    this->unk58 = M2C_FIELD(&arg1, f64 *, 8);
    this->unk6C = 1;
    this->unk60 = 0.5f;
    do {
        temp_f31_88 = this->unk68;
        temp_f28_93 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        temp_f27_98 = MKRand_Float(&gViewSeed, 0.5f, 1.0f);
        sp40 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        sp44 = temp_f27_98;
        sp48 = temp_f28_93;
        sp60 = (f64) sp40;
        sp68 = (f64) sp48;
        temp_f0_112 = sp60 * 5.65176949e-315;
        sp30 = temp_f0_112;
        sp70 = temp_f0_112;
        sp38 = (f32) sp68 * 700.0f;
        sp78 = (f64) sp38;
        temp_f0_122 = temp_f0_112 * (f64) temp_f31_88;
        sp20 = temp_f0_122;
        sp90 = temp_f0_122;
        sp28 = (f32) sp78 * temp_f31_88;
        sp98 = (f64) sp28;
        temp_f27_135 = MKRand_Float(&gViewSeed, 0.5f, 1.0f);
        temp_f28_140 = MKRand_Float(&gViewSeed, 0.5f, 1.0f);
        sp10 = MKRand_Float(&gViewSeed, 0.5f, 1.0f);
        sp14 = temp_f28_140;
        sp18 = temp_f27_135;
        sp1C = 1.0f;
        sp50 = (f64) sp10;
        sp58 = (f64) sp18;
        sp8 = this->unk68 * MKRand_Float(&gViewSeed, 12.0f, 20.0f);
        ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(*((MKVector3 *) &this->unk50), *((MKVector3 *) &sp90), sp8, *((MKVector4 *) &sp50), 0.0f);
        var_r28_81 += 1;
    } while (var_r28_81 < 0xF);
    sp80 = this->unk50;
    sp88 = this->unk58;
    (*(f32 *) ((u8 *) &sp80 + 0x4)) += 50.0f;
    KDSound_Play3d(GS_GemSpawn1, (MKVector3 *) &this->unk50, 0U, -1, 0.0f, 0U);
    var_r30_186 = 0;
    if ((((GameStats *) &GameData::gameData[0x70])->GetGemAvailable((StatType) 0) != 0) && (arg0 != NULL)) {
        temp_f3_200 = M2C_FIELD(GameData::gameData, f32 *, 0x70) / M2C_FIELD(GameData::gameData, f32 *, 0x74);
        var_f1_208 = (f32) M2C_FIELD(arg0, s32 *, 0);
        if (temp_f3_200 > 0.9f) {
            var_f1_208 = -((0.5f * var_f1_208) - var_f1_208);
        } else if (temp_f3_200 > 0.75f) {
            var_f1_208 = -((0.25f * var_f1_208) - var_f1_208);
        } else if (temp_f3_200 < 0.1f) {
            var_f1_208 += 0.5f * var_f1_208;
        } else if (temp_f3_200 < 0.25f) {
            var_f1_208 += 0.25f * var_f1_208;
        }
        var_r30_186 = (s32) var_f1_208;
        ((CollectableSpawner *) (M2C_FIELD(&gb, CollectableSpawner **, 0x10)))->Spawn(*((MKVector3 *) &sp80), var_r30_186, 200.0f, 500.0f, -1, NULL);
    }
    if ((((GameStats *) &GameData::gameData[0x70])->GetGemAvailable((StatType) 2) != 0) && (arg0 != NULL)) {
        temp_f3_258 = M2C_FIELD(GameData::gameData, f32 *, 0xA0) / M2C_FIELD(GameData::gameData, f32 *, 0xA4);
        var_f1_266 = (f32) M2C_FIELD(arg0, s32 *, 8);
        if (temp_f3_258 > 0.9f) {
            var_f1_266 = -((0.5f * var_f1_266) - var_f1_266);
        } else if (temp_f3_258 > 0.75f) {
            var_f1_266 = -((0.25f * var_f1_266) - var_f1_266);
        } else if (temp_f3_258 < 0.1f) {
            var_f1_266 += 0.5f * var_f1_266;
        } else if (temp_f3_258 < 0.25f) {
            var_f1_266 += 0.25f * var_f1_266;
        }
        temp_r28_301 = (s32) var_f1_266;
        ((CollectableSpawner *) (M2C_FIELD(&gb, CollectableSpawner **, 0x18)))->Spawn(*((MKVector3 *) &sp80), temp_r28_301, 200.0f, 500.0f, -1, NULL);
        var_r30_186 += temp_r28_301;
    }
    if ((((GameStats *) &GameData::gameData[0x70])->GetGemAvailable((StatType) 3) != 0) && (arg0 != NULL)) {
        ((CollectableSpawner *) (M2C_FIELD(&gb, CollectableSpawner **, 0x1C)))->Spawn(*((MKVector3 *) &sp80), M2C_FIELD(arg0, s32 *, 0xC), 200.0f, 500.0f, -1, NULL);
        var_r30_186 += M2C_FIELD(arg0, s32 *, 0xC);
    }
    if ((((GameStats *) &GameData::gameData[0x70])->GetGemAvailable((StatType) 1) != 0) && (arg0 != NULL)) {
        ((CollectableSpawner *) (M2C_FIELD(&gb, CollectableSpawner **, 0x14)))->Spawn(*((MKVector3 *) &sp80), M2C_FIELD(arg0, s32 *, 4), 200.0f, 500.0f, -1, NULL);
        var_r30_186 += M2C_FIELD(arg0, s32 *, 4);
    }
    var_r4_347 = 0;
    if ((var_r30_186 == 0) && (arg0 != NULL)) {
        var_r3_352 = 0;
        var_ctr_353 = 4;
        do {
            temp_r0_355 = *(arg0 + var_r3_352);
            var_r3_352 += 4;
            var_r4_347 += temp_r0_355;
            var_ctr_353 -= 1;
        } while (var_ctr_353 != 0);
    }
    if ((var_r30_186 != 0) && ((arg0 != NULL) || (var_r4_347 > 0))) {
        ((CollectableSpawner *) (M2C_FIELD(&gb, CollectableSpawner **, 0x10)))->Spawn(*((MKVector3 *) &sp80), 1, 200.0f, 500.0f, -1, NULL);
    }
}
#endif

void EnemyDeathFX::Deinit() {
    Corona *temp_r4_403;

    temp_r4_403 = this->unk64;
    if (temp_r4_403 != NULL) {
        ((Coronas *) (M2C_FIELD(&gb, Coronas **, 0x64)))->Free(temp_r4_403);
    }
    MKProp::Deinit();
}

void EnemyDeathFX::Draw() {

}

void EnemyDeathFX::Update() {
    Corona *temp_r3_444;
    Corona *temp_r4_452;
    f32 temp_f2_439;
    f32 temp_f4_457;

    if ((u8) this->unk6C != 0) {
        this->unk60 -= gUpdateTimeDelta;
        temp_f2_439 = this->unk60;
        if (temp_f2_439 < 0.0f) {
            this->unk6C = 0;
            temp_r3_444 = this->unk64;
            if (temp_r3_444 != NULL) {
                temp_r3_444->unk31 &= ~0x40;
            }
        } else {
            temp_r4_452 = this->unk64;
            if (temp_r4_452 != NULL) {
                temp_f4_457 = temp_f2_439 / 0.5f;
                temp_r4_452->unk24 = this->unk68 * (12.0f * temp_f4_457);
                this->unk64->unk2C = 0.5f * (3.1415927f * temp_f4_457);
            }
        }
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void EnemyDeathFX::Resolve() {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Corona *temp_r4_507;

    MKProp::Resolve();
    sp20 = 0.0f;
    sp8 = 1.0f;
    spC = 0.75f;
    sp10 = 0.75f;
    sp14 = 1.0f;
    sp18 = 0.0f;
    sp1C = 0.0f;
    sp28 = (f64) sp8;
    sp30 = (f64) sp10;
    sp38 = (f64) sp18;
    sp40 = (f64) sp20;
    this->unk64 = ((Coronas *) (M2C_FIELD(&gb, Coronas **, 0x64)))->Alloc(*((MKVector3 *) &sp38), *((MKVector4 *) &sp28), 10.0f, lit_634, lit_635);
    temp_r4_507 = this->unk64;
    if (temp_r4_507 != NULL) {
        temp_r4_507->unk31 &= ~0x40;
    }
}
#endif

void EnemyDeathFX::Init() {
    MKProp::Init();
    M2C_FIELD(this, f32 *, 0x50) = 0.0f;
    M2C_FIELD(this, f32 *, 0x54) = 0.0f;
    M2C_FIELD(this, f32 *, 0x58) = 0.0f;
    this->unk60 = 0.0f;
    this->unk68 = 0.0f;
    this->unk6C = 0;
    this->unk64 = NULL;
}
