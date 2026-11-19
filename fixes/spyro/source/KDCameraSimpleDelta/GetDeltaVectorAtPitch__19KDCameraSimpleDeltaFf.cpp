#pragma dont_inline on
MKVector3 KDCameraSimpleDelta::GetDeltaVectorAtPitch(float farg0) {
    MKVector3 result;
    Matrix sp30;
    f32 temp_f1_839;

    sp30.SetIdentity();
    sp30.SetRotationPitch(farg0);
    temp_f1_839 = GetCurrentDelta();
    result.unk0 = 0.0f;
    result.unk4 = sp30.unk24 * temp_f1_839;
    result.unk8 = sp30.unk28 * temp_f1_839;
    return result;
}
#pragma dont_inline reset
