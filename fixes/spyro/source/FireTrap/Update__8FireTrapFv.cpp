void *FireTrap::Update() {
    struct {
        s32 unk0;
        s32 unk4;
        MKVector3 unk8;
        MKVector3 unk18;
        s32 unk28;
        FireTrap *unk2C;
        MKVector3 unk30;
        s8 unk40;
        s8 unk41;
        s8 unk42;
        s32 unk44;
        f32 unk48;
        s32 unk4C;
        s8 unk50;
        s8 unk51;
    } msg;
    MKVector3 *pos;
    MKVector3 *heroPos;
    MKVector3 dir;
    MKVector3 delta;
    MKVector3 emitPos;
    f32 scale;

    GameProp::Update();
    if ((this->unk10 & 0x20000) && (this->unk10 & 0x80000)) {
        pos = (MKVector3 *) ((u8 *) this->unk8 + 0x30);

        if (this->unkE0 > 1.0f) {
            dir.unk0 = MKVector3::up.unk0 * 650.0f;
            dir.unk4 = MKVector3::up.unk4 * 650.0f;
            dir.unk8 = MKVector3::up.unk8 * 650.0f;
            ((CrashFirePS *) gb.unk68)->Emit(*pos, dir, 6.0f);

            heroPos = (MKVector3 *) ((u8 *) M2C_FIELD(gb.unk0->GetProp(), void **, 8) + 0x30);
            delta.unk0 = heroPos->unk0 - pos->unk0;
            delta.unk4 = 0.0f;
            delta.unk8 = heroPos->unk8 - pos->unk8;
            if ((delta.unk8 * delta.unk8) + ((delta.unk0 * delta.unk0) + (0.0f * 0.0f)) < 10000.0f) {
                msg.unk0 = 7;
                msg.unk4 = 0;
                msg.unk8.unk0 = delta.unk0 * 20.0f;
                msg.unk8.unk4 = 0.0f;
                msg.unk8.unk8 = delta.unk8 * 20.0f;
                msg.unk18 = MKVector3::one;
                msg.unk28 = 1;
                msg.unk2C = this;
                if (this != NULL) {
                    msg.unk30 = *pos;
                } else {
                    msg.unk30.unk0 = 0.0f;
                    msg.unk30.unk4 = 0.0f;
                    msg.unk30.unk8 = 0.0f;
                }
                msg.unk40 = 0;
                msg.unk41 = 0;
                msg.unk42 = 1;
                msg.unk44 = -1;
                msg.unk48 = 10.0f;
                msg.unk4C = 2;
                msg.unk50 = 0;
                msg.unk51 = 0;
                gb.unk0->Message((MKMessage *) &msg);
            }
        }
        if ((this->unkE0 < 1.0f) && (MKRand_Int((int *) &gViewSeed, 0, 0xA) == 0)) {
            emitPos.unk0 = pos->unk0;
            emitPos.unk4 = pos->unk4 + 15.0f;
            emitPos.unk8 = pos->unk8;
            dir.unk0 = MKVector3::up.unk0 * 300.0f;
            dir.unk4 = MKVector3::up.unk4 * 300.0f;
            dir.unk8 = MKVector3::up.unk8 * 300.0f;
            ((SparksPS *) gb.unk84)->Emit(emitPos, dir, 5.0f);
        }
        scale = this->unkE0;
        if (((scale > 0.5f) && (scale < 1.0f)) || (MKRand_Int((int *) &gViewSeed, 0, 0xA) == 0)) {
            dir.unk0 = MKVector3::up.unk0 * 650.0f;
            dir.unk4 = MKVector3::up.unk4 * 650.0f;
            dir.unk8 = MKVector3::up.unk8 * 650.0f;
            gb.EmitDust(*pos, dir, 0.5f, 0.0f);
        }
        this->unkE0 += gUpdateTimeDelta;
    }
}
