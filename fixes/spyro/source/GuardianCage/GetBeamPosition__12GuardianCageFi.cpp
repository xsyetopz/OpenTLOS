MKVector3 GuardianCage::GetBeamPosition(int arg2) {
    MKVector3 sp8;
    s32 temp_r4;

    temp_r4 = *((s32 *) (((u8 *) this) + (arg2 * 4) + 0xC8));
    MKModel_CalculateRefPointWorldPosition(this->unk4, temp_r4, &sp8);
    return sp8;
}
