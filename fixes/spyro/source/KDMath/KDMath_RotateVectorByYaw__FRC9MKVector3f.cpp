MKVector3 KDMath_RotateVectorByYaw(const MKVector3 &arg1, float farg0) {
    MKVector3 result;
    Matrix sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f3_639;
    f32 temp_f6_644;
    f32 temp_f7_653;

    sp20.SetIdentity();
    sp20.SetRotationYaw(farg0);
    temp_f3_639 = arg1.unk4;
    temp_f6_644 = arg1.unk0;
    temp_f7_653 = arg1.unk8;
    sp10 = sp20.unk30 + ((temp_f7_653 * sp20.unk20) + ((temp_f6_644 * sp20.unk0) + (temp_f3_639 * sp20.unk10)));
    sp14 = sp20.unk34 + ((temp_f7_653 * sp20.unk24) + ((temp_f6_644 * sp20.unk4) + (temp_f3_639 * sp20.unk14)));
    sp18 = sp20.unk38 + ((temp_f7_653 * sp20.unk28) + ((temp_f6_644 * sp20.unk8) + (temp_f3_639 * sp20.unk18)));
    result.unk0 = sp10;
    result.unk4 = sp14;
    result.unk8 = sp18;
    return result;
}
