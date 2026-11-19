void EnergyBeam::SpawnEnergyBeam(MKVector3 *arg0, MKVector3 *arg1, float arg2) {
    f32 temp_f27_932;
    f32 temp_f27_962;
    f32 temp_f28_927;
    f32 temp_f28_967;
    f32 temp_f30_924;
    f32 sp20;
    f32 sp10;
    MKVector3 sp68;
    MKVector3 sp58;
    MKVector3 sp38;
    MKVector3 sp28;
    MKHeap *temp_r29_907;
    MKHeap *temp_r6_898;
    MKHeap *temp_r6_905;
    s8 *temp_r28_948;
    s32 var_r27_918;
    s32 var_r31_919;

    temp_r6_898 = this->unk90;
    if ((u32) M2C_FIELD(temp_r6_898, u32 *, -4) == 0U) {
        return;
    }
    temp_r6_905 = (MKHeap *) ((s8 *) temp_r6_898 - 4);
    this->unk90 = temp_r6_905;
    temp_r29_907 = temp_r6_905->unk0;
    if (temp_r29_907 != NULL) {
        temp_r29_907->unk0 = (MKHeap *) arg0;
        temp_r29_907->unk4 = (s32) arg1;
        M2C_FIELD(temp_r29_907, s8 *, 0x10) = 1;
        ResetSafePositions((EnergyBeam::Beam *) temp_r29_907);
        var_r27_918 = 0;
        var_r31_919 = 0;
        do {
            temp_f30_924 = M2C_FIELD(temp_r29_907, f32 *, 0x8) / 1000.0f;
            temp_f28_927 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
            temp_f27_932 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
            sp58 = MKVector(MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f), temp_f27_932, temp_f28_927);
            sp68 = sp58.operator*(2500.0f);
            temp_r28_948 = (s8 *) temp_r29_907 + var_r31_919;
            M2C_FIELD(temp_r28_948, f32 *, 0x30) = sp68.unk0 * temp_f30_924;
            M2C_FIELD(temp_r28_948, f32 *, 0x34) = sp68.unk4 * temp_f30_924;
            sp20 = sp68.unk8 * temp_f30_924;
            M2C_FIELD(temp_r28_948, f32 *, 0x38) = sp20;
            temp_f27_962 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
            temp_f28_967 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
            sp28 = MKVector(MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f), temp_f28_967, temp_f27_962);
            sp38 = sp28.operator*(200.0f);
            M2C_FIELD(temp_r28_948, f32 *, 0x20) = M2C_FIELD(temp_r28_948, f32 *, 0x40) + sp38.unk0;
            M2C_FIELD(temp_r28_948, f32 *, 0x24) = M2C_FIELD(temp_r28_948, f32 *, 0x44) + sp38.unk4;
            sp10 = M2C_FIELD(temp_r28_948, f32 *, 0x48) + sp38.unk8;
            M2C_FIELD(temp_r28_948, f32 *, 0x28) = sp10;
            M2C_FIELD(temp_r28_948, f32 *, 0x60) = MKRand_Float((int *) &gViewSeed, 0.25f, 1.0f);
            var_r27_918 += 1;
            var_r31_919 += 0x50;
            M2C_FIELD(temp_r29_907, f32 *, 0xC) = arg2;
        } while (var_r27_918 < 8);
        UpdateTargetVelocities((EnergyBeam::Beam *) temp_r29_907);
    }
}
