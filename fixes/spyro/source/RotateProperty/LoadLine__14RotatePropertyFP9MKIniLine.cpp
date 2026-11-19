s32 RotateProperty::LoadLine(MKIniLine *arg0) {
    u8 result;

    if (this->unk18 == NULL) {
        this->unk18 = arg0;
    }
    result = 0;
    if ((arg0->LoadString("subObject", (const char **) &this->unk10, 0) != 0) || (arg0->LoadVector3("Rotation", (MKVector3 *) &this->unk20, 0) != 0)) {
        result = 1;
    }
    return result;
}
