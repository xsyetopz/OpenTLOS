u8 KDClothDescriptor::LoadLine(MKIniLine *arg0) {
    u8 var_r31_305;

    var_r31_305 = 0;
    if ((arg0->LoadInt("lit", (int *) &this->unk10, 0) != 0) || (arg0->LoadFloat("gravity", &this->unk0, 0) != 0) || (arg0->LoadFloat("friction", &this->unk4, 0) != 0) || (arg0->LoadFloat("windMultiplier", &this->unk8, 0) != 0) || (arg0->LoadInt("iterations", (int *) &this->unkC, 0) != 0) || (arg0->LoadString("clothSubObject", (const char **) &this->unk14, 0) != 0)) {
        var_r31_305 = 1;
    }
    return var_r31_305;
}
