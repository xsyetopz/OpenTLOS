s32 KDProp::LoadLine(MKIniLine *arg0) {
    u8 sp8;

    if (MKProp::LoadLine(arg0) != 0) {
        return 1;
    }
    if (arg0->LoadBool("bDrawAtFullAlpha", (bool *) &sp8, 0) != 0) {
        this->unk88 = (this->unk88 & ~0x80) | ((sp8 << 7) & 0x80);
        return 1;
    }
    if (arg0->LoadBool("bUseCollisionColor", (bool *) &sp8, 0) != 0) {
        this->unk88 = (this->unk88 & ~0x20) | ((sp8 << 5) & 0x20);
        return 1;
    }
    return arg0->LoadVector4("collisionColor", (MKVector4 *) &this->unk60, 0);
}
