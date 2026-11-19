#include "spyro/source/ZapCage.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/GameData.h"
#include "spyro/source/ZapArcFX.h"
#include "unplaced_templates.h"
#include "common/Source/MKModel.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDRandom.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;
static u8 lit_720 = 1;

void ZapCage::Reset() {
    MKProp::Reset();
    this->unk4C = 0;
    this->unk50 = 0.0f;
    this->unk54 = NULL;
}

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void ZapCage::Trigger(MKProp *arg0, float arg1) {
    void *temp_r3_80;

    this->unk4C = 1;
    this->unk50 = arg1;
    this->unk58 = MKRand_Float(&gViewSeed, 0.0f, 6.2831855f);
    this->unk54 = arg0;
    this->unk5C = 0.0f;
    temp_r3_80 = checked_cast<Enemy *, MKProp>(this->unk54);
    M2C_FIELD(temp_r3_80, u8 *, 0xB02) = (u8) (M2C_FIELD(temp_r3_80, u8 *, 0xB02) | 0x40);
}
#endif

void ZapCage::Deinit() {
    MKProp::Deinit();
}

#if 0 // DRAFT: undefined identifier 'arg_sp10'
void ZapCage::Update() {
    MKHeap **temp_r30_164;
    f32 temp_f2_220;
    f32 temp_f5_244;
    s32 temp_r0_127;
    void *temp_r29_332;
    void *temp_r3_198;
    this->unk50 -= gUpdateTimeDelta;
    this->unk58 += 12.566371f * gUpdateTimeDelta;
    temp_r0_127 = this->unk4C;
    if (temp_r0_127 != 1) {
        if ((temp_r0_127 < 1) && (temp_r0_127 < 0)) {

        }
    } else {
        arg_sp10 = 1.0f;
        M2C_STRUCT_COPY((s32) &arg_sp18C + 4, M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8) - 4 + 4, 0x40);
        arg_sp1C0 = 0.0f;
        arg_sp1C4 = 0.0f;
        arg_sp1C8 = 0.0f;
        arg_sp1CC = 1.0f;
        temp_r30_164 = MKModel_GetBoundingVolume(this->unk54->unk4, (SubObjectType) 0, -1);
        arg_sp128.GetPos();
        arg_sp18 = (0.5f * M2C_FIELD(temp_r30_164, f32 *, 0x10)) + M2C_BITWISE(f32, M2C_FIELD(temp_r30_164, MKHeap **, 0));
        arg_sp1C = (0.5f * M2C_FIELD(temp_r30_164, f32 *, 0x14)) + M2C_FIELD(temp_r30_164, f32 *, 4);
        arg_sp20 = (0.5f * M2C_FIELD(temp_r30_164, f32 *, 0x18)) + M2C_FIELD(temp_r30_164, f32 *, 8);
        arg_sp138 = (f64) arg_sp18;
        arg_sp140 = (f64) arg_sp20;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_sp178 = arg_sp78;
        arg_sp148 = arg_sp78;
        arg_sp80 = (f32) arg_sp140 + arg_sp130;
        arg_sp180 = (f64) arg_sp80;
        temp_r3_198 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
        arg_sp150 = (f64) arg_sp80;
        arg_spF8 = M2C_FIELD(temp_r3_198, f64 *, 0x30);
        arg_sp100 = M2C_FIELD(temp_r3_198, f64 *, 0x38);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        arg_sp108 = arg_sp68;
        arg_sp70 = (f32) arg_sp100 - (f32) arg_sp180;
        arg_sp110 = (f64) arg_sp70;
        Normalise(*((MKVector3 *) &arg_sp118));
        temp_f2_220 = M2C_FIELD(temp_r30_164, f32 *, 0xC);
        arg_sp158 = arg_sp118;
        arg_sp160 = arg_sp120;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        arg_spE8 = arg_sp58;
        arg_sp60 = (f32) arg_sp160 * temp_f2_220;
        arg_spF0 = (f64) arg_sp60;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        temp_f5_244 = temp_f2_220 / 300.0f;
        arg_sp40 = 0.0f;
        arg_sp50 = 0.0f;
        arg_sp38 = temp_f5_244;
        arg_sp3C = 1.0f;
        arg_sp48 = -1.0f * temp_f5_244;
        arg_sp4C = 0.125f * temp_f5_244;
        arg_sp180 = (f32) arg_sp180 + (f32) arg_spF0;
        arg_sp10 = temp_f5_244;
        arg_spB8 = (f64) arg_sp38;
        arg_spC0 = (f64) arg_sp40;
        arg_spC8 = (f64) arg_sp48;
        arg_spD0 = (f64) arg_sp50;
        KDRand_Vector(*((MKVector3 *) &arg_spD8), *((MKVector3 *) &arg_spC8));
        arg_sp168 = arg_spD8;
        arg_sp170 = arg_spE0;
        arg_sp88 = 1.0f;
        arg_sp8C = 1.0f;
        arg_sp30 = arg_sp1C8 + (((f32) arg_sp170 * arg_sp1B8) + (((f32) arg_sp168 * arg_sp198) + (arg_sp16C * arg_sp1A8)));
        arg_sp28 = arg_sp1C0 + (((f32) arg_sp170 * arg_sp1B0) + (((f32) arg_sp168 * arg_sp190) + (arg_sp16C * arg_sp1A0)));
        arg_sp2C = arg_sp1C4 + (((f32) arg_sp170 * arg_sp1B4) + (((f32) arg_sp168 * arg_sp194) + (arg_sp16C * arg_sp1A4)));
        arg_sp90 = 0.2f;
        arg_sp94 = 1.0f;
        arg_spA8 = (f64) arg_sp28;
        arg_spB0 = (f64) arg_sp30;
        arg_sp168 = (f64) arg_sp28;
        arg_sp170 = (f64) arg_sp30;
        arg_sp98 = (f64) arg_sp88;
        arg_spA0 = (f64) arg_sp90;
        ((ZapArcFX *) (M2C_FIELD(&gb, ZapArcFX **, 0x94)))->Trigger(*((MKVector3 *) &arg_sp178), *((MKVector3 *) &arg_sp168), arg_sp10, lit_720, (MKVector4) &arg_sp98);
        temp_r29_332 = checked_cast<Enemy *, MKProp>(this->unk54);
        this->unk5C -= gUpdateTimeDelta;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (this->unk5C == 0.0f) {
            this->unk5C = 0.3f;
            arg_sp1D4 = 0;
            arg_sp1D0.Init(NULL, ((GameStats *) ((GameStats *) &GameData::gameData[0x70]))->GetBreathAttackDamage(1, 1, 0), 1, 0, 1, 0, 0, -1);
            M2C_FIELD(M2C_FIELD(temp_r29_332, void **, 0x44), M2C_UNK (**)(void *, M2C_UNK *), 0x2C)(temp_r29_332, &arg_sp1D0);
        }
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if ((this->unk50 == 0.0f) || (M2C_ERROR(/* unknown instruction: cror eq, lt, eq */), ((M2C_FIELD(temp_r29_332, f32 *, 0xAC8) == 0.0f) != 0))) {
            M2C_FIELD(temp_r29_332, u8 *, 0xB02) = (u8) (M2C_FIELD(temp_r29_332, u8 *, 0xB02) & ~0x40);
            this->unk4C = 0;
            Disable(0);
        }
    }
}
#endif

void ZapCage::Init() {
    MKProp::Init();
    this->unk4C = 0;
    this->unk50 = 0.0f;
    this->unk58 = 0.0f;
    this->unk54 = NULL;
    this->unk5C = 0.0f;
}
