void FireMolePrison::Message(MKMessage *arg0) {
    f64 pos[2];
    struct {
        s32 type;
        s32 unk4;
        f64 x;
        f64 y;
    } msg;
    FireMolePrisonDescriptor *desc;
    MKProp *temp_r3_74;
    s32 var_r30_52;
    s32 var_r31_53;
    void *temp_r6_60;

    if ((s32) arg0->unk0 != 0xBA) {
    } else {
        var_r31_53 = 0;
        var_r30_52 = 0;
        while (var_r31_53 < (s32) this->unk1FC) {
            temp_r6_60 = ((u8 *) this->unk1F8) + var_r30_52;
            pos[0] = M2C_FIELD(temp_r6_60, f64 *, 0);
            pos[1] = M2C_FIELD(temp_r6_60, f64 *, 8);
            SetSpawnPos(var_r31_53, *((MKVector3 *) pos));
            desc = checked_cast<FireMolePrisonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            temp_r3_74 = this->unk1A8.TrySpawnItem(M2C_FIELD(M2C_FIELD(desc, void **, 0x40), s32 (**)(void *), 0x24)(desc));
            if (temp_r3_74 != NULL) {
                msg.type = 0x98;
                msg.unk4 = 0;
                msg.x = pos[0];
                msg.y = pos[1];
                M2C_FIELD(M2C_FIELD(temp_r3_74, void **, 0x44), void (**)(void *, s32 *, f64), 0x2C)(temp_r3_74, (s32 *) &msg, pos[0]);
            }
            var_r31_53 += 1;
            var_r30_52 += 0x10;
        }
    }
    Shatterable::Message(arg0);
}
