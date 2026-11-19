void DragonStatue::EmitCrudAbovePlayer() {
    s32 i;
    void *prop;
    MKVector3 pos;
    MKVector3 vel;
    f32 px;
    f32 py;
    f32 pz;
    f32 sx;
    f32 sy;
    f32 sz;
    f32 scale;

    for (i = 0; i < (s32) this->unkF8; i += 1) {
        prop = M2C_FIELD(gb.unk0->GetProp(), void **, 8);
        px = M2C_FIELD(prop, f32 *, 0x30);
        py = M2C_FIELD(prop, f32 *, 0x34) + 200.0f;
        pz = M2C_FIELD(prop, f32 *, 0x38);

        sx = MKRand_Float((int *) &gViewSeed, -10.0f, 10.0f);
        sy = MKRand_Float((int *) &gViewSeed, 4.0f, 6.0f);
        sz = MKRand_Float((int *) &gViewSeed, -10.0f, 10.0f);
        pos.unk0 = px + sx * 100.0f;
        pos.unk4 = py + sy * 100.0f;
        pos.unk8 = pz + sz * 100.0f;

        sx = MKRand_Float((int *) &gViewSeed, -4.0f, 4.0f);
        sy = MKRand_Float((int *) &gViewSeed, -2.0f, 0.5f);
        sz = MKRand_Float((int *) &gViewSeed, -4.0f, 4.0f);
        vel.unk0 = sx * 100.0f;
        vel.unk4 = sy * 100.0f;
        vel.unk8 = sz * 100.0f;

        scale = MKRand_Float((int *) &gViewSeed, 0.25f, 0.5f);
        gb.EmitCrud(pos, vel, scale);
    }
}
