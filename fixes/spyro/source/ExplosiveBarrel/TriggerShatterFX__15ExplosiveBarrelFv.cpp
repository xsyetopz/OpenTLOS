void ExplosiveBarrel::TriggerShatterFX() {
    ExplosiveBarrelDescriptor *desc;
    MKVector3 pos;
    MKVector3 rv;
    MKVector3 scaled;
    MKVector3 vel;
    f32 a;
    f32 b;
    f32 c;
    f32 size;
    s32 i;

    this->unk1BA = 0;
    desc = checked_cast<ExplosiveBarrelDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    M2C_FIELD(M2C_FIELD(desc, void **, 0x16C), s32 *, 0x88) = GS_TNTBarrelExplode;
    pos = *((MKVector3 *) ((s8 *) this->unk8 + 0x30));
    desc = checked_cast<ExplosiveBarrelDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    M2C_FIELD(desc, Explosion4 **, 0x16C)->Trigger(pos, this->unk1B0, true, (MKProp *) this, 0xF, true, true, true, true);

    for (i = 0; i < 4; i++) {
        pos = *((MKVector3 *) ((s8 *) this->unk8 + 0x30));
        a = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        b = MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f);
        rv = MKVector(MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f), b, a);
        scaled.unk0 = rv.unk0 * 100.0f;
        scaled.unk4 = rv.unk4 * 100.0f;
        scaled.unk8 = rv.unk8 * 100.0f;
        pos.unk0 = pos.unk0 + scaled.unk0;
        pos.unk4 = pos.unk4 + scaled.unk4;
        pos.unk8 = pos.unk8 + scaled.unk8;
        a = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        b = MKRand_Float((int *) &gViewSeed, 0.0f, 3.0f);
        c = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        vel.unk0 = c * 50.0f;
        vel.unk4 = b * 50.0f;
        vel.unk8 = a * 50.0f;
        size = MKRand_Float((int *) &gViewSeed, 2.0f, 3.0f);
        gb.EmitDust(pos, vel, size, 0.0f);
    }

    for (i = 0; i < 8; i++) {
        pos = *((MKVector3 *) ((s8 *) this->unk8 + 0x30));
        a = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        b = MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f);
        rv = MKVector(MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f), b, a);
        scaled.unk0 = rv.unk0 * 100.0f;
        scaled.unk4 = rv.unk4 * 100.0f;
        scaled.unk8 = rv.unk8 * 100.0f;
        pos.unk0 = pos.unk0 + scaled.unk0;
        pos.unk4 = pos.unk4 + scaled.unk4;
        pos.unk8 = pos.unk8 + scaled.unk8;
        a = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        b = MKRand_Float((int *) &gViewSeed, 0.0f, 6.0f);
        c = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        vel.unk0 = c * 100.0f;
        vel.unk4 = b * 100.0f;
        vel.unk8 = a * 100.0f;
        size = MKRand_Float((int *) &gViewSeed, 0.25f, 0.5f);
        gb.EmitCrud(pos, vel, size);
    }
}
