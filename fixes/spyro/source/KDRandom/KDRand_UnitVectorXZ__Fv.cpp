MKVector3 KDRand_UnitVectorXZ() {
    MKVector3 result;

    _table_sincosf(MKRand_Float((int *) &gViewSeed, 0.0f, 6.2831855f), result.unk0, result.unk8);
    result.unk4 = 0.0f;
    result.unk8 = -result.unk8;
    return result;
}
