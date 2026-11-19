s32 KDDropShadow::LoadDone() {
    KDDropShadowDescriptor *desc;
    MKHeap *var_r3_185;
    Matrix *temp_r0_194;
    s32 temp_r31_177;

    MKProp::LoadDone();
    desc = checked_cast<KDDropShadowDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    temp_r31_177 = desc->unk60;
    if (MKHeap::Current() != NULL) {
        var_r3_185 = (MKHeap *) (((MKHeap *) (MKHeap::Current()))->Alloc(temp_r31_177 * 0x50, NULL, 0));
    } else {
        var_r3_185 = malloc(temp_r31_177 * 0x50);
    }
    this->unk4C = var_r3_185;
    temp_r0_194 = (Matrix *) ((u8 *) this->unk4C + (temp_r31_177 * 0x50));
    this->unk50 = temp_r0_194;
    this->unk54 = temp_r0_194;
}
