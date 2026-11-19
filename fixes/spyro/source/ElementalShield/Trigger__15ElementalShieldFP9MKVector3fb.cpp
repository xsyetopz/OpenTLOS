void ElementalShield::Trigger(MKVector3 *arg0, float arg1, bool arg2) {
    if ((s32) this->unk90 == 0) {
        this->unk90 = 1;
        KDSound_Play3d(this->unkB4, (const MKVector3 *) (((u8 *) this->unk8) + 0x30), 0U, -1, 0.0f, 0U);
        this->unk98 = arg1;
        this->unk9C = 0.0f;
        this->unk94 = 1.0f;
        this->unkA8 = arg2;
        this->unkAC = arg0;
    }
}
