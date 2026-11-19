void MKMatInfo_Endian(MatInfo *arg0) {
    s32 var_r29_1161;
    s32 var_r29_1173;
    s32 var_r30_1187;
    s32 var_r31_1162;
    s32 var_r31_1174;
    s32 var_r31_1188;

    ByteReverse<int unsigned>(M2C_FIELD(arg0, unsigned int *, 0x20));
    ByteReverse<int>(M2C_FIELD(arg0, int *, 0x24));
    ByteReverse<int>(M2C_FIELD(arg0, int *, 0x28));
    ByteReverse<float>(M2C_FIELD(arg0, f32 *, 0x2C));
    ByteReverse<float>(M2C_FIELD(arg0, f32 *, 0x30));
    ByteReverse<float>(M2C_FIELD(arg0, f32 *, 0x34));
    ByteReverse<float>(M2C_FIELD(arg0, f32 *, 0x38));
    ByteReverse<float>(M2C_FIELD(arg0, f32 *, 0x3C));
    var_r29_1161 = 0;
    var_r31_1162 = 0;
    do {
        ByteReverse<float>(M2C_FIELD(arg0, f32 *, 0x128 + var_r31_1162));
        ByteReverse<float>(M2C_FIELD(arg0, f32 *, 0x134 + var_r31_1162));
        var_r29_1161 += 1;
        var_r31_1162 += 4;
    } while (var_r29_1161 < 3);
    var_r29_1173 = 0;
    var_r31_1174 = 0;
    do {
        ByteReverse<float>(M2C_FIELD(arg0, f32 *, 0x140 + var_r31_1174));
        ByteReverse<float>(M2C_FIELD(arg0, f32 *, 0x150 + var_r31_1174));
        ByteReverse<float>(M2C_FIELD(arg0, f32 *, 0x160 + var_r31_1174));
        var_r29_1173 += 1;
        var_r31_1174 += 4;
    } while (var_r29_1173 < 4);
    var_r30_1187 = 0;
    var_r31_1188 = 0;
    do {
        ByteReverse<float>(M2C_FIELD(arg0, f32 *, 0x170 + var_r31_1188));
        var_r30_1187 += 1;
        var_r31_1188 += 4;
    } while (var_r30_1187 < 9);
    ByteReverse<float>(M2C_FIELD(arg0, f32 *, 0x194));
    ByteReverse<int unsigned>(M2C_FIELD(arg0, unsigned int *, 0x1E0));
    ByteReverse<int unsigned>(M2C_FIELD(arg0, unsigned int *, 0x1E4));
}
