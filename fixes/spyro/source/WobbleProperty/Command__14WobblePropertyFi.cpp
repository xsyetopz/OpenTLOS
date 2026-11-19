void WobbleProperty::Command(int arg0) {
    s8 *temp_r3;

    if (arg0 == 1) {
        *(*(u8 **) KDProperty::pInstanceMem + (this->unk8 + 0xC)) = 0;
        temp_r3 = *(s8 **) (*(u8 **) KDProperty::pInstanceMem + this->unk8);
        M2C_FIELD(temp_r3, s8 *, 0x30) = 0;
    }
}
