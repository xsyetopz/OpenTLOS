void PoisonBomb::EmitPoisonTrail() {
    MKVector3 sp58;
    MKVector3 sp68;
    MKVector3 sp48;
    MKVector3 sp38;
    MKVector3 *temp_r31_91;

    temp_r31_91 = (MKVector3 *) (((u8 *) this->unk8) + 0x30);
    sp48.unk0 = -1.0f;
    sp48.unk4 = 0.0f;
    sp48.unk8 = -1.0f;
    sp38.unk0 = 1.0f;
    sp38.unk4 = 1.0f;
    sp38.unk8 = 1.0f;
    sp58 = KDRand_Vector(sp48, sp38);
    sp68.unk0 = sp58.unk0 * 100.0f;
    sp68.unk4 = sp58.unk4 * 100.0f;
    sp68.unk8 = sp58.unk8 * 100.0f;
    ((HeatDistortPS *) (&gb + 0x240))->Emit(*temp_r31_91, sp68, 1.0f, MKRand_Float((int *) &gViewSeed, 3.0f, 4.0f));
}
