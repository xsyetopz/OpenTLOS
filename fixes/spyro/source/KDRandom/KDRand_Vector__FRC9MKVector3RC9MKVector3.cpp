MKVector3 KDRand_Vector(const MKVector3 &arg1, const MKVector3 &arg2) {
    MKVector3 result;

    result.unk0 = MKRand_Float((int *) &gViewSeed, arg1.unk0, arg2.unk0);
    result.unk4 = MKRand_Float((int *) &gViewSeed, arg1.unk4, arg2.unk4);
    result.unk8 = MKRand_Float((int *) &gViewSeed, arg1.unk8, arg2.unk8);
    return result;
}
