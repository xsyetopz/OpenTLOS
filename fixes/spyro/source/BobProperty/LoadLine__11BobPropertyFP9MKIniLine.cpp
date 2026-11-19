s32 BobProperty::LoadLine(MKIniLine *arg0) {
    u8 var_r31_409;

    if (this->unk18 == NULL) {
        this->unk18 = arg0;
    }
    var_r31_409 = 0;
    if ((arg0->LoadString("subObject", (const char **) &this->unk10, 0) != 0) || (arg0->LoadVector3("Range", (MKVector3 *) &this->unk20, 0) != 0) || (arg0->LoadFloat("Period", &this->unk30, 0) != 0)) {
        var_r31_409 = 1;
    }
    return var_r31_409;
}
