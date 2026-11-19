MKVector3 KDMath_GetDirection(const Matrix *arg1) {
    MKVector3 result;

    result.unk0 = -arg1->unk20;
    result.unk4 = -arg1->unk24;
    result.unk8 = -arg1->unk28;
    return result;
}
