s32 WobbleProperty::LoadLineInstance(MKIniLine *arg0) {
    return arg0->LoadString("bonename", (const char **) &this->unk14, 0);
}
