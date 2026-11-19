s32 RotateProperty::LoadLineInstance(MKIniLine *arg0) {
    return arg0->LoadBool("Enabled", (bool *) (*(u8 **) KDProperty::pInstanceMem + (this->unk8 + 0x84)), 0);
}
