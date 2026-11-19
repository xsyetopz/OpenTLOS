#include "spyro/source/TimeDeltaModifier.h"

s32 FuryFXFire::Trigger(const MKVector3 &arg0, bool arg1, bool arg2, HeroHurtReactionType arg3) {
    MKVector3 scale;
    MKVector3 sp58;
    void *temp_r4_179;
    void *temp_r4_242;
    s32 i;
    s32 temp_r0_270;
    s32 temp_r3_268;
    s32 temp_r29_293;
    s32 var_r30_286;
    s32 var_r3_276;

    if (this->unk104 != 0) {
        return 0;
    }
    this->unk2F0 = arg1;
    this->unk2F1 = arg2;
    this->unk2EC = (s32) arg3;
    if ((u8) this->unk2F1 == 0) {
        this->unk90.unk30 = arg0.unk0;
        this->unk90.unk34 = arg0.unk4;
        this->unk90.unk38 = arg0.unk8;
        this->unk90.unk3C = 1.0f;
        this->unk2E8 = M2C_FIELD(&gb, TimeDeltaModifier *, 0x2CC).Enable(0.5f, 0.0f, 0.0f, -1.0f);
        this->unk100 = 1.0f;
        gb.unk381 = 1;
        for (i = 0; i < 3; i++) {
            temp_r4_179 = *(void **) ((u8 *) this + i * 0x80 + 0x130);
            if (temp_r4_179 != NULL) {
                M2C_FIELD(temp_r4_179, f32 *, 0x50) = 1.0f;
                M2C_FIELD(temp_r4_179, f32 *, 0x54) = 1.0f;
                M2C_FIELD(temp_r4_179, f32 *, 0x58) = 1.0f;
                M2C_FIELD(temp_r4_179, f32 *, 0x5C) = 1.0f;
            }
        }
    } else {
        scale.unk0 = 1.0f;
        scale.unk4 = 3.0f;
        scale.unk8 = 1.0f;
        this->unk90.Scale3x3(&this->unk90, scale);
        sp58.unk0 = 0.0f;
        sp58.unk4 = 600.0f;
        sp58.unk8 = 0.0f;
        this->unk90.unk30 = arg0.unk0 - sp58.unk0;
        this->unk90.unk34 = arg0.unk4 - sp58.unk4;
        this->unk90.unk38 = arg0.unk8 - sp58.unk8;
        this->unk90.unk3C = 1.0f;
        this->unk100 = 0.0f;
        for (i = 0; i < 3; i++) {
            temp_r4_242 = *(void **) ((u8 *) this + i * 0x80 + 0x130);
            if (temp_r4_242 != NULL) {
                M2C_FIELD(temp_r4_242, f32 *, 0x50) = 1.0f;
                M2C_FIELD(temp_r4_242, f32 *, 0x54) = 0.0f;
                M2C_FIELD(temp_r4_242, f32 *, 0x58) = 0.0f;
                M2C_FIELD(temp_r4_242, f32 *, 0x5C) = 1.0f;
            }
        }
    }
    this->unkF8 = 0.0f;
    this->unkFC = 0.0f;
    this->unk104 = 1;
    temp_r3_268 = M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5;
    temp_r0_270 = M2C_FIELD(GameData::gameData, s32 *, 0x70 + temp_r3_268 + 0x7C);
    if (temp_r0_270 == 3) {
        var_r3_276 = 0;
        if ((M2C_FIELD(GameData::gameData, s32 *, 0x70 + temp_r3_268 + 0x64) == 3) &&
            (M2C_FIELD(GameData::gameData, s32 *, 0x70 + temp_r3_268 + 0x64 + 4) == 3)) {
            var_r3_276 = 1;
        }
        var_r30_286 = var_r3_276 != 0;
    } else {
        var_r30_286 = M2C_FIELD(GameData::gameData, s32 *, 0x70 + temp_r3_268 + 0x64 + temp_r0_270 * 4);
    }
    temp_r29_293 = M2C_FIELD(GameData::gameData, s32 *, 0x158);
    this->unk290.Init((MKProp *) gb.unk0->GetProp(), 15.0f * gb.unk37C, 3, var_r30_286, temp_r29_293, temp_r29_293, 0, -1);
    return 1;
}
