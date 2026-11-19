f32 Conveyor::Resolve() {
    MKVector3 sp8;
    s32 var_r25;
    s32 var_r24;
    s32 var_r30;
    s32 var_r31;
    s32 var_r29;
    u8 *temp_r27;

    KDPropEx::Resolve();
    var_r25 = 0;
    var_r31 = 0;
    var_r30 = 0;
    do {
        temp_r27 = (u8 *) this + var_r30;
        var_r24 = 0;
        var_r29 = 0;
        do {
            *(s32 *) (temp_r27 + var_r29 + 0xC8) = MKModel_GetRefPointIndex(this->unk4, (const char *) Str_Printf("r_track%d_%d", var_r25 + 1, var_r24 + 1));
            MKModel_CalculateRefPointWorldPosition(this->unk4, *(s32 *) (temp_r27 + var_r29 + 0xC8), &sp8);
            ((KDUniformSpline *) ((u8 *) this + var_r31 + 0x118))->AddNode(sp8);
            var_r24 += 1;
            var_r29 += 4;
        } while (var_r24 < 0xA);
        var_r25 += 1;
        var_r30 += 0x28;
        var_r31 += 0x14;
    } while (var_r25 < 2);
}
