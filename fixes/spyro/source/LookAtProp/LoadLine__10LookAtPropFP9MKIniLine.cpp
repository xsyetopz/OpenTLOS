s32 LookAtProp::LoadLine(MKIniLine *arg0) {
    if (MKProp::LoadLine(arg0) != 0) {
        return 1U;
    }
    return (u8) (arg0->LoadInt("PropID", (int *) &this->unk4C, 0) != 0);
}
