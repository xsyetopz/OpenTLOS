void MKFFTWater::Draw(unsigned short *arg0, int arg1) {
    u16 *temp_r7_59;
    s16 var_r31_28;
    s32 temp_r0_44;
    s32 temp_r9_56;
    s32 var_r12_23;
    s32 var_r30_30;
    s32 var_r5_25;
    s32 var_r6_29;
    s32 var_r7_31;
    u16 temp_r10_36;
    void *temp_r11_37;

    if ((u8) bWaterEnabled != 0) {
        var_r12_23 = 0;
        var_r5_25 = 0;
loop_8:
        if (var_r12_23 < (s32) this->unk8) {
            var_r31_28 = 0;
            var_r6_29 = 0;
            var_r30_30 = 0;
            var_r7_31 = 0;
loop_6:
            if (var_r30_30 < (s32) *arg0) {
                temp_r10_36 = *(u16 *) ((u8 *) arg0 + (var_r7_31 + 2));
                temp_r11_37 = (u8 *) this->unkC + var_r5_25;
                if ((u8) *(u8 *) (M2C_FIELD(temp_r11_37, u8 **, 8) + (temp_r10_36 & 0x7FFF)) != 0) {
                    temp_r0_44 = var_r6_29 + 2;
                    var_r31_28 += 1;
                    var_r6_29 += 2;
                    *(u16 *) ((u8 *) M2C_FIELD(temp_r11_37, u16 **, 0x50C4) + temp_r0_44) = temp_r10_36;
                }
                var_r30_30 += 1;
                var_r7_31 += 2;
                goto loop_6;
            }
            temp_r9_56 = var_r5_25 + 0x50C4;
            var_r12_23 += 1;
            temp_r7_59 = *(u16 **) ((u8 *) this->unkC + temp_r9_56);
            var_r5_25 += 0x5168;
            *temp_r7_59 = var_r31_28;
            *(u16 *) ((u8 *) *(u16 **) ((u8 *) this->unkC + temp_r9_56) + ((var_r31_28 * 2) + 2)) = 0xFFFF;
            goto loop_8;
        }
    }
}
