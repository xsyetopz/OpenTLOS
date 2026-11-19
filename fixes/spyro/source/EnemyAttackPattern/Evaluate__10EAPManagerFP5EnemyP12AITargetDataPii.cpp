extern s32 gViewSeed;

s32 EAPManager::Evaluate(Enemy *arg0, AITargetData *arg1, int *arg2, int arg3) {
    f32 sp18[0x14];
    EAPCondition *temp_r25_797;
    EAPItem *temp_r3_850;
    f32 temp_f0_860;
    f32 temp_f0_889;
    f32 temp_f1_876;
    f32 var_f28_749;
    f32 var_f29_746;
    f32 var_f30_796;
    s32 *temp_r5_880;
    s32 temp_r0_826;
    s32 temp_r0_884;
    s32 temp_r4_849;
    s32 var_ctr_822;
    s32 var_ctr_885;
    s32 var_r17_792;
    s32 var_r18_787;
    s32 var_r19_786;
    s32 var_r26_791;
    s32 var_r27_785;
    s32 var_r3_821;
    s32 var_r3_883;
    s32 var_r6_882;
    u8 var_r17_754;
    u8 var_r28_790;

    var_f29_746 = 0.0f;
    var_f28_749 = 0.0f;
    var_r17_754 = 0;
    if (((u8) M2C_FIELD(arg1, u8 *, 0x48) == 2) || (arg1->unk40.Get() != NULL)) {
        var_r17_754 = 1;
    }
    if (var_r17_754 != 0) {
        MKVector3 sp8 = arg1->GetDir();

        fCachedOwnerAngle = NormaliseAngle(KDMath_GetYaw(*((MKVector3 *) &arg0->unkC0)));
        fCachedTargetAngle = NormaliseAngle(KDMath_GetYaw(sp8));
        memset(sp18, 0, 0x50U);
        var_r27_785 = 0;
        var_r19_786 = 0;
        var_r18_787 = 0;
loop_23:
        if (var_r27_785 < (s32) M2C_FIELD(this->unk4, s32 *, 4)) {
            var_r28_790 = arg2 == NULL;
            var_r26_791 = 0;
            var_r17_792 = 0;
loop_17:
            temp_r4_849 = M2C_FIELD(this->unk4, s32 *, 0);
            temp_r3_850 = (EAPItem *) (var_r18_787 + temp_r4_849);
            if (var_r26_791 < temp_r3_850->unk8) {
                var_f30_796 = 0.0f;
                temp_r25_797 = (EAPCondition *) ((u8 *) temp_r3_850->unk4 + var_r17_792);
                if ((temp_r25_797->unk8 != 1) && (!(temp_r3_850->unk0->unk38 & 0x1000) || !(M2C_FIELD(GameData::gameData, f32 *, 0xA0) <= 0.0f))) {
                    if ((u8) EvaluateCondition((EAPItem *) (temp_r4_849 + var_r18_787), temp_r25_797, arg0, arg1) != 0) {
                        var_f30_796 = temp_r25_797->unkC;
                        if (var_r28_790 == 0) {
                            var_r3_821 = 0;
                            var_ctr_822 = arg3;
                            if (arg3 > 0) {
                                do {
                                    temp_r0_826 = *(s32 *) ((u8 *) arg2 + var_r3_821);
                                    var_r3_821 += 4;
                                    var_r28_790 = temp_r25_797->unk4 == temp_r0_826;
                                    var_ctr_822 -= 1;
                                } while (var_ctr_822 != 0);
                            }
                        }
                    }
                    if (var_f30_796 < 0.0f) {
                        *(f32 *) ((u8 *) sp18 + var_r19_786) = -1.0f;
                    } else {
                        *(f32 *) ((u8 *) sp18 + var_r19_786) = *(f32 *) ((u8 *) sp18 + var_r19_786) + var_f30_796;
                        goto block_16;
                    }
                } else {
block_16:
                    var_r26_791 += 1;
                    var_r17_792 += 0x10;
                    goto loop_17;
                }
            }
            if (var_r28_790 == 0) {
                *(f32 *) ((u8 *) sp18 + var_r19_786) = 0.0f;
            }
            temp_f0_860 = *(f32 *) ((u8 *) sp18 + var_r19_786);
            if (temp_f0_860 > 0.0f) {
                var_f29_746 += temp_f0_860;
            }
            var_r27_785 += 1;
            var_r19_786 += 4;
            var_r18_787 += 0xC;
            goto loop_23;
        }
        temp_f1_876 = MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f);
        if (var_f29_746 > 0.0f) {
            temp_r5_880 = this->unk4;
            var_r6_882 = 0;
            var_r3_883 = 0;
            temp_r0_884 = M2C_FIELD(temp_r5_880, s32 *, 4);
            var_ctr_885 = temp_r0_884;
            if (temp_r0_884 > 0) {
loop_26:
                temp_f0_889 = *(f32 *) ((u8 *) sp18 + var_r3_883);
                if (temp_f0_889 >= 0.0f) {
                    var_f28_749 += temp_f0_889 / var_f29_746;
                    if (var_f28_749 > temp_f1_876) {
                        return M2C_FIELD(temp_r5_880, s32 *, 0) + (var_r6_882 * 0xC);
                    }
                }
                var_r6_882 += 1;
                var_r3_883 += 4;
                var_ctr_885 -= 1;
                if (var_ctr_885 == 0) {
                    goto block_30;
                }
                goto loop_26;
            }
        }
        goto block_30;
    }
block_30:
    fCachedOwnerAngle = 0.0f;
    fCachedTargetAngle = 0.0f;
    return 0;
}
