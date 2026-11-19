void FuryFXEarth::EmitLeaves() {
    MKVector3 sp90;
    MKVector3 sp80;
    MKVector3 pos;
    MKVector3 vel;
    MKVector3 lo;
    MKVector3 hi;
    s32 sp8;
    s32 var_r31_772;

    if (!(this->unk10C > 0.0f)) {
        var_r31_772 = 0;
        this->unk10C = 0.2f;
        do {
            sp90 = MKVector(0.0f, 25.0f, 0.0f);
            pos.unk0 = this->unk110.unk0 + sp90.unk0;
            pos.unk4 = this->unk110.unk4 + sp90.unk4;
            pos.unk8 = this->unk110.unk8 + sp90.unk8;
            lo.unk0 = -1.0f;
            lo.unk4 = 0.0f;
            lo.unk8 = -1.0f;
            hi.unk0 = 1.0f;
            hi.unk4 = 1.0f;
            hi.unk8 = 1.0f;
            sp80 = KDRand_Vector(lo, hi);
            vel.unk0 = sp80.unk0 * 220.0f;
            vel.unk4 = sp80.unk4 * 220.0f;
            vel.unk8 = sp80.unk8 * 220.0f;
            sp8 = MKRand_Int((int *) &gViewSeed, 0, 3);
            this->unk100->Emit(pos, vel, 2.0f, sp8, 1U);
            var_r31_772 += 1;
        } while (var_r31_772 < 0xA);
    }
}
