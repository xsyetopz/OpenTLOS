s32 FuryFXFire2::Trigger(const MKVector3 &arg0) {
    s32 temp_r0_472;
    s32 temp_r29_495;
    s32 temp_r3_470;
    s32 var_r30_488;
    u8 var_r3_478;
    u8 *temp_r5_474;

    this->unk90.unk30 = arg0.unk0;
    this->unk90.unk34 = arg0.unk4;
    this->unk90.unk38 = arg0.unk8;
    this->unk90.unk3C = 1.0f;
    if (this->unkD0 == 0) {
        this->unkD0 = 1;
        this->unkE8 = 1.0f;
        temp_r3_470 = *(s32 *) (GameData::gameData + 0x158) << 5;
        temp_r0_472 = *(s32 *) (GameData::gameData + 0x70 + temp_r3_470 + 0x7C);
        temp_r5_474 = GameData::gameData + 0x70 + temp_r3_470 + 0x64;
        if (temp_r0_472 == 3) {
            var_r3_478 = 0;
            if ((*(s32 *) temp_r5_474 == 3) && (*(s32 *) (temp_r5_474 + 4) == 3)) {
                var_r3_478 = 1;
            }
            var_r30_488 = var_r3_478 != 0;
        } else {
            var_r30_488 = *(s32 *) (temp_r5_474 + temp_r0_472 * 4);
        }
        temp_r29_495 = *(s32 *) (GameData::gameData + 0x158);
        this->unkF0.Init((MKProp *) gb.unk0->GetProp(), 15.0f * gb.unk37C, 3, var_r30_488, temp_r29_495, temp_r29_495, 0, -1);
        gb.unk381 = 1;
        return 1;
    }
    return 0;
}
