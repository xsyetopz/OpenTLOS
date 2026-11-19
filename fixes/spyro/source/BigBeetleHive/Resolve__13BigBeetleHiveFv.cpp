f32 BigBeetleHive::Resolve() {
    BeetleNestSmall *nest;
    s32 var_r28_585;
    s32 var_r31_587;
    void *temp_r29_589;

    Shatterable::Resolve();
    var_r28_585 = 0;
    var_r31_587 = 0;
    do {
        temp_r29_589 = (u8 *) this + var_r31_587;
        if ((s32) M2C_FIELD(temp_r29_589, s32 *, 0x1B0) != -1) {
            M2C_FIELD(temp_r29_589, s32 *, 0x1B4) = (s32) Tools_GetMatchingRefPointIndex(this->unk4, (const char *) Str_Printf("r_attach%d", var_r28_585));
            nest = checked_cast<BeetleNestSmall *, MKProp>(MKSceneManager::PropResolver_Resolve(M2C_FIELD(temp_r29_589, s32 *, 0x1B0)));
            M2C_FIELD(temp_r29_589, s32 *, 0x1AC) = (long) nest;
        }
        var_r28_585 += 1;
        var_r31_587 += 0xC;
    } while (var_r28_585 < 5);
}
