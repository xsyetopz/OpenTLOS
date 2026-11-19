MKVector3 SteamTrainCaboose::GetVel() {
    MKVector3 result;
    SteamTrain *temp_r3_345;
    void *temp_r4_348;
    f32 temp_f3_349;
    void *temp_r3_376;

    temp_r3_345 = checked_cast<SteamTrain *, MKProp>(MKSceneManager::PropResolver_Resolve((s32) this->unkD0));
    if (temp_r3_345 != NULL) {
        temp_r4_348 = this->unk8;
        temp_f3_349 = temp_r3_345->unk108;
        result.unk0 = -M2C_FIELD(temp_r4_348, f32 *, 0x20) * temp_f3_349;
        result.unk4 = -M2C_FIELD(temp_r4_348, f32 *, 0x24) * temp_f3_349;
        result.unk8 = -M2C_FIELD(temp_r4_348, f32 *, 0x28) * temp_f3_349;
        return result;
    }
    temp_r3_376 = this->unk8;
    result.unk0 = -M2C_FIELD(temp_r3_376, f32 *, 0x20);
    result.unk4 = -M2C_FIELD(temp_r3_376, f32 *, 0x24);
    result.unk8 = -M2C_FIELD(temp_r3_376, f32 *, 0x28);
    return result;
}
