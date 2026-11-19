void DragonBustDoor::LoadDone() {
    s32 var_r30_184;
    s32 var_r31_186;

    Trap::LoadDone();
    this->unkEC = (s32) Tools_GetMatchingSubObjectIndex((SubObjectType) 0, (MKModel *) this->unk4, "LightYellow");
    this->unkF4 = (s32) Tools_GetMatchingSubObjectIndex((SubObjectType) 0, (MKModel *) this->unk4, "LightRed");
    this->unkFC = (s32) Tools_GetMatchingSubObjectIndex((SubObjectType) 0, (MKModel *) this->unk4, "LightGreen");
    var_r30_184 = 0;
    this->unk104 = (s32) Tools_GetMatchingSubObjectIndex((SubObjectType) 0, (MKModel *) this->unk4, "LightBlue");
    var_r31_186 = 0;
    do {
        MKModel_EnableSubObject((MKModel *) this->unk4, (SubObjectType) 0, *(s32 *) ((u8 *) this + var_r31_186 + 0xEC), 0, 1U);
        var_r30_184 += 1;
        var_r31_186 += 8;
    } while (var_r30_184 < 4);
}
