u8 HasAttack(int arg0, int arg1);

void DrawBreathIcon(float arg0, float arg1, float arg2, int arg3, int arg4, const MKVector4 &arg5) {
    MKVector4 sp8;
    f32 temp_f3_848;
    f32 temp_f3_865;

    sp8.unk0 = arg5.unk0;
    sp8.unk4 = arg5.unk4;
    sp8.unk8 = arg5.unk8;
    sp8.unkC = arg5.unkC;
    if (HasAttack(arg3, arg4) == 0) {
        sp8.unk0 *= 0.375f;
        sp8.unk4 *= 0.375f;
        sp8.unk8 *= 0.375f;
    }
    temp_f3_848 = 73.0f * arg2;
    Hud_DrawIcon(arg3, arg4, arg0 + arg2, arg1, temp_f3_848, temp_f3_848, sp8, 0.0f, 0.0f, 1.0f, 1.0f, 0U, 0U, Matrix::identity);
    temp_f3_865 = 106.0f * arg2;
    Hud_DrawIcon(arg3, 3, arg0, arg1, temp_f3_865, temp_f3_865, arg5, 0.0f, 0.0f, 1.0f, 1.0f, 0U, 0U, Matrix::identity);
}
