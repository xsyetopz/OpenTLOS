MKVector3 KDMath_GetDirection(float arg1) {
    MKVector3 result;
    Matrix sp20;

    sp20.SetRotationYaw(arg1);
    result.unk0 = -sp20.unk20;
    result.unk4 = -sp20.unk24;
    result.unk8 = -sp20.unk28;
    return result;
}
