MKVector3 KDMath_LocaliseVector(const MKVector3 &arg1, MKVector3 *arg2, const MKVector3 &arg3) {
    Matrix sp10;

    sp10.SetIdentity();
    gAssertBool = KDMath_BuildMatrixFromFwd(&sp10, arg1, arg2);
    return KDMath_LocaliseVector(&sp10, arg3);
}
