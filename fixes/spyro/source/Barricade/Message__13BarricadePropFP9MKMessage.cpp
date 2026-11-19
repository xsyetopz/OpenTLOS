void BarricadeProp::Message(MKMessage *arg0) {
    MKVector3 pos;
    MKVector3 a;
    MKVector3 b;
    MKVector3 dir;
    MKVector3 vel;
    MKVector4 color;
    f32 rand1;
    f32 rand2;
    s32 i;

    if ((s32) arg0->unk0 == 0x15E) {
        this->unk80->SetAnim((MKAnim *) this->unk80->GetAnim("Explode"), 1.0f, 0.0f, 0, -1);
        this->unk1AC = 1;
        i = 0;
        do {
            rand1 = MKRand_Float((int *) &gViewSeed, 0.5f, 1.0f);
            pos.unk0 = M2C_FIELD(this->unk8, f32 *, 0x30);
            pos.unk4 = M2C_FIELD(this->unk8, f32 *, 0x34);
            pos.unk8 = M2C_FIELD(this->unk8, f32 *, 0x38);
            a.unk0 = -1.0f;
            a.unk4 = 0.25f;
            a.unk8 = -1.0f;
            b.unk0 = 1.0f;
            b.unk4 = 1.0f;
            b.unk8 = 1.0f;
            dir = KDRand_Vector(a, b);
            vel.unk0 = dir.unk0 * 2000.0f;
            vel.unk4 = dir.unk4 * 2000.0f;
            vel.unk8 = dir.unk8 * 2000.0f;
            rand2 = MKRand_Float((int *) &gViewSeed, 10.0f, 15.0f);
            color.unk0 = 1.0f;
            color.unk4 = rand1;
            color.unk8 = 0.0f;
            color.unkC = 1.0f;
            ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(pos, vel, rand2, color, -2000.0f);
            i += 1;
        } while (i < 0xA);
    }
    if ((u8) this->unk1AC != 0) {
        Shatterable::Message(arg0);
        return;
    }
    i = arg0->unk0;
    if ((i != 4) && (i != 1) && (i != 5)) {
        Shatterable::Message(arg0);
    }
}
