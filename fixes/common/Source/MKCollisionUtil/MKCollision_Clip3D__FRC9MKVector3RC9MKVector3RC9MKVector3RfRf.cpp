s32 MKCollision_Clip3D(const MKVector3 &arg0, const MKVector3 &arg1, const MKVector3 &arg2, float &arg3, float &arg4) {
    s32 var_r31_1590;

    var_r31_1590 = 0;
    arg3 = 0.0f;
    arg4 = 1.0f;
    if ((Clip(arg1.unk0, -arg0.unk0, arg2.unk0, arg3, arg4) != 0) && (Clip(arg1.unk4, -arg0.unk4, arg2.unk4, arg3, arg4) != 0) && (Clip(arg1.unk8, -arg0.unk8, arg2.unk8, arg3, arg4) != 0)) {
        var_r31_1590 = 1;
    }
    return var_r31_1590;
}
