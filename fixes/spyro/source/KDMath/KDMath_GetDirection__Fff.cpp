MKVector3 KDMath_GetDirection(float farg0, float farg1) {
    MKVector3 result;
    Matrix sp20;

    sp20.SetRotationPitch(farg1);
    sp20.RotateYaw(&sp20, farg0);
    result.unk0 = -sp20.unk20;
    result.unk4 = -sp20.unk24;
    result.unk8 = -sp20.unk28;
    return result;
}
