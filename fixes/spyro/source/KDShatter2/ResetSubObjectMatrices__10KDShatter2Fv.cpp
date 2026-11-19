void KDShatter2::ResetSubObjectMatrices() {
    s32 i;
    s32 off;
    s16 bone;

    if (unk50 == NULL) {
        return;
    }
    if (MKModel_GetAnimation(unk4C) != NULL) {
        i = 0;
        off = 0;
        while (i < unk50->unk1640) {
            bone = MKModel_GetSubObjectBoneIndex(unk4C, (SubObjectType) 0, M2C_FIELD(unk50, s32 *, off + 0xA0));
            MKModel_GetAnimation(unk4C)->SetCustomMatrix(bone, NULL, (AnimationMatrixPosition) 4, false);
            i += 1;
            off += 0xB0;
        }
        return;
    }
    i = 0;
    off = 0;
    while (i < unk50->unk1640) {
        MKModel_SetSubObjectLocalMatrix(unk4C, (SubObjectType) 0, M2C_FIELD(unk50, s32 *, off + 0xA0), NULL);
        i += 1;
        off += 0xB0;
    }
}
