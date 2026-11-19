s32 SwayProperty::LoadLine(MKIniLine *arg0) {
    u8 var_r31_576;

    if ((MKIniLine *) this->unk18 == NULL) {
        this->unk18 = arg0;
    }
    var_r31_576 = 0;
    if ((arg0->LoadString("subObject", (const char **) &this->unk10, 0) != 0) || (arg0->LoadVector3("Range", (MKVector3 *) &this->unk20, 0) != 0) || (arg0->LoadFloat("Period", &this->unk30, 0) != 0)) {
        var_r31_576 = 1;
    }
    return var_r31_576;
}
