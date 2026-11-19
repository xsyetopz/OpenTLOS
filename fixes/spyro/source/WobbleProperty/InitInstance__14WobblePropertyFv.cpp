void WobbleProperty::InitInstance() {
    MKIniLine *var_r31;
    u8 *temp_r4;

    temp_r4 = *(u8 **) KDProperty::pInstanceMem + this->unk8;
    M2C_FIELD(temp_r4, s8 *, 0xC) = 1;
    M2C_FIELD(temp_r4, s32 *, 0) = 0;
    var_r31 = *(MKIniLine **) &this->unk10;
    while (var_r31 != NULL) {
        this->LoadLineInstance(var_r31);
        var_r31 = M2C_FIELD(var_r31, MKIni **, 0xC)->GetNextLine(var_r31);
    }
}
