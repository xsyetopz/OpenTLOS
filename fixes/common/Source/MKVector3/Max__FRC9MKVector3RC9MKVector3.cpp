MKVector3 Max(const MKVector3 &arg1, const MKVector3 &arg2) {
    MKVector3 result;

    result.unk0 = arg1.unk0;
    if (result.unk0 > arg2.unk0) {
    } else {
        result.unk0 = arg2.unk0;
    }
    result.unk4 = arg1.unk4;
    if (result.unk4 > arg2.unk4) {
    } else {
        result.unk4 = arg2.unk4;
    }
    result.unk8 = arg1.unk8;
    if (result.unk8 > arg2.unk8) {
    } else {
        result.unk8 = arg2.unk8;
    }
    return result;
}
