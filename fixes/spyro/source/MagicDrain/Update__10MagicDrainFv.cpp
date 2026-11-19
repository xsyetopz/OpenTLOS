void MagicDrain::Update() {
    MKVector3 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKVector3 *temp_r3_310;
    ManagedLight *temp_r3_327;
    ManagedLight *temp_r4_307;
    f32 temp_f1_326;
    f32 var_f1_283;
    void *temp_r3_329;
    void *temp_r4_315;

    Projectile::Update();
    if (((u8) this->unk158 != 0) && ((MKVector3 *) this->unk150 != NULL) && ((MKVector3 *) this->unk154 != NULL)) {
        this->unk1B8 -= gUpdateTimeDelta;
        if (this->unk1B8 <= 0.0f) {
            if (M2C_FIELD(GameData::gameData, f32 *, 0xA0) != 0.0f) {
                sp20 = 1.0f;
                sp30 = -1.0f;
                sp8 = 0.0f;
                spC = 1.0f;
                sp10 = 0.0f;
                sp14 = 1.0f;
                sp18 = 1.0f;
                sp1C = 1.0f;
                sp28 = -1.0f;
                sp2C = 1.0f;
                sp38 = (f64) sp8;
                sp40 = (f64) sp10;
                sp48 = (f64) sp18;
                sp50 = (f64) sp20;
                sp58 = (f64) sp28;
                sp60 = (f64) sp30;
                KDRand_Vector(sp68, *((MKVector3 *) &sp58));
                ((GemMagicFX *) (M2C_FIELD(&gb, GemMagicFX **, 0x238)))->Emit(*this->unk154, sp68, this->unk150, *((MKVector4 *) &sp38), 0U);
                KDSound_Play3d(GS_ELExtra3, this->unk154, 0U, -1, 0.0f, 0U);
                if ((u8) M2C_FIELD(&gb, u8 *, 0x3B5) == 0) {
                    var_f1_283 = -((20.0f * gUpdateTimeDelta) - M2C_FIELD(GameData::gameData, f32 *, 0xA0));
                    if (var_f1_283 < M2C_FIELD(GameData::gameData, f32 *, 0xA4)) {

                    } else {
                        var_f1_283 = M2C_FIELD(GameData::gameData, f32 *, 0xA4);
                    }
                    if (var_f1_283 > 0.0f) {

                    } else {
                        var_f1_283 = 0.0f;
                    }
                    ((Stat *) &GameData::gameData[0xA0])->SetValue(var_f1_283, 0U);
                }
            }
            this->unk1B8 = MKRand_Float((int *) &gViewSeed, 0.125f, 0.25f);
        }
        temp_r4_307 = this->unk15C;
        if (temp_r4_307 != NULL) {
            temp_r3_310 = this->unk150;
            temp_r4_307->unk10 = M2C_FIELD(temp_r3_310, f64 *, 0);
            temp_r4_307->unk18 = M2C_FIELD(temp_r3_310, f64 *, 8);
            temp_r4_315 = temp_r4_307->unk3C;
            if (temp_r4_315 != NULL) {
                M2C_FIELD(temp_r4_315, f64 *, 0x10) = (f64) M2C_FIELD(temp_r3_310, f64 *, 0);
                M2C_FIELD(temp_r4_315, f64 *, 0x18) = (f64) M2C_FIELD(temp_r3_310, f64 *, 8);
            }
            temp_f1_326 = MKRand_Float((int *) &gViewSeed, 500.0f, 600.0f);
            temp_r3_327 = this->unk15C;
            temp_r3_327->unk38 = temp_f1_326;
            temp_r3_329 = temp_r3_327->unk3C;
            if (temp_r3_329 != NULL) {
                M2C_FIELD(temp_r3_329, f32 *, 0x20) = temp_f1_326;
                M2C_FIELD(temp_r3_329, f32 *, 0x24) = (f32) (temp_f1_326 * temp_f1_326);
                M2C_FIELD(temp_r3_329, f32 *, 0x28) = (f32) (1.0f / temp_f1_326);
                M2C_FIELD(temp_r3_329, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_329, f32 *, 0x24));
            }
        }
    }
}
