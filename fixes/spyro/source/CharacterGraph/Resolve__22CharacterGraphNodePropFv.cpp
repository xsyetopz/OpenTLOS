f32 CharacterGraphNodeProp::Resolve() {
    KDSplinePathSegmentProp *var_r29_147;
    CharacterGraphNodeProp *temp_r4_164;
    s32 temp_r3_155;
    s32 temp_r0_178;
    s32 var_r28_148;
    s32 var_r31_149;
    u8 *temp_r30_151;

    var_r29_147 = NULL;
    var_r28_148 = 0;
    var_r31_149 = 0;
    do {
        temp_r30_151 = (u8 *) this + var_r31_149;
        if ((s32) M2C_FIELD(temp_r30_151, s32 *, 0xDC) != 0) {
            temp_r3_155 = M2C_FIELD(temp_r30_151, s32 *, 0xF4);
            if (temp_r3_155 != 0) {
                var_r29_147 = checked_cast<KDSplinePathSegmentProp *, MKProp>(MKSceneManager::PropResolver_Resolve(temp_r3_155));
            }
            temp_r4_164 = checked_cast<CharacterGraphNodeProp *, MKProp>(MKSceneManager::PropResolver_Resolve(M2C_FIELD(temp_r30_151, s32 *, 0xDC)));
            if (temp_r4_164 != NULL) {
                this->unk50.Link(&temp_r4_164->unk50, var_r28_148, (LinkInformation) M2C_FIELD(temp_r30_151, s32 *, 0xA0), var_r29_147);
            }
        }
        var_r28_148 += 1;
        var_r31_149 += 4;
    } while (var_r28_148 < 6);
    temp_r0_178 = this->unk50.unkBC;
    if (temp_r0_178 != 0) {
        this->unk50.unk3C = temp_r0_178;
        this->unk50.unk80 |= 0x20;
    }
    this->unk50.unk40 = (MKProp *) this;
    this->unk50.unk4C = this->unk14;
}
