void GuardianCage::StateDeadEnter() {
    MKVector3 vA;
    MKVector3 vC;
    MKVector3 vD;
    MKVector3 vF;
    MKVector4 vW;
    f32 rA;
    f32 rB;
    f32 rC;
    f32 rD;
    f32 rE;
    f32 rF;
    f32 rG;
    f32 rH;
    f32 rI;
    f32 rJ;
    f32 rK;
    f32 rL;
    f32 rScale;
    u8 *temp_r4;
    s32 var_r30_78;

    var_r30_78 = 0;
    do {
        rA = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        rB = MKRand_Float((int *) &gViewSeed, 1.0f, 3.0f);
        rC = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        vA.unk0 = rC * 1000.0f;
        vA.unk4 = rB * 1000.0f;
        vA.unk8 = rA * 1000.0f;

        rD = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        rE = MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f);
        rF = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        temp_r4 = ((u8 *) this->unk8) + 0x30;
        vC.unk0 = M2C_FIELD(temp_r4, f32 *, 0x0) + rF * 400.0f;
        vC.unk4 = M2C_FIELD(temp_r4, f32 *, 0x4) + rE * 400.0f;
        vC.unk8 = M2C_FIELD(temp_r4, f32 *, 0x8) + rD * 400.0f;

        rG = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        rH = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        rI = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        vD.unk0 = rI * 3.1415927f;
        vD.unk4 = rH * 3.1415927f;
        vD.unk8 = rG * 3.1415927f;

        rJ = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        rK = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        rL = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        vF.unk0 = rL * 3.1415927f;
        vF.unk4 = rK * 3.1415927f;
        vF.unk8 = rJ * 3.1415927f;

        rScale = MKRand_Float((int *) &gViewSeed, 1.0f, 2.0f);
        vW.unk0 = 1.0f;
        vW.unk4 = 1.0f;
        vW.unk8 = 1.0f;
        vW.unkC = 1.0f;
        ((FlyingChunkPS *) gb.unkA0)->Emit(vC, vA, vD, vF, rScale, vW, 0, NULL);
        var_r30_78 += 1;
    } while (var_r30_78 < 0xF);
    KDSound_Play3d(GS_PrisonBallShatter, (const MKVector3 *) (((u8 *) this->unk8) + 0x30), 0U, -1, 0.0f, false);
    this->unk148.Send(NULL);
}
