void LavaCannon::Message(MKMessage *arg0) {
    switch (arg0->unk0) {
    case 0xB5:
        Shatter(0, 0, -1, 0);
        break;
    case 0x4E:
        if ((u32) this->unk240 == arg0->unk4) {
            this->unk240 = NULL;
        }
        break;
    }
    Shatterable::Message(arg0);
}
