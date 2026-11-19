s32 KDSoundProp::LoadLine(MKIniLine *arg0) {
    const char *sp8;
    s32 result;

    if (MKProp::LoadLine(arg0) != 0) {
        return 1;
    }
    if (arg0->LoadString("sound", &sp8, 0) != 0) {
        if ((u8) *sp8 == 0x2A) {
            sp8 += 1;
        }
        this->unk50 = KDSound_ResolveSound(sp8, NULL);
        return 1;
    }
    if (arg0->LoadString("dummySphere", &sp8, 0) != 0) {
        result = 1;
    } else {
        result = 0;
        if ((arg0->LoadFloat("minDelay", &this->unk58, 0) != 0) || (arg0->LoadFloat("maxDelay", &this->unk5C, 0) != 0)) {
            result = 1;
        }
    }
    return result;
}
