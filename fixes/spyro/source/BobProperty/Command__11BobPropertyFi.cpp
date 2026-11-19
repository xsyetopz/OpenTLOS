void BobProperty::Command(int arg0) {
    switch (arg0) {
    case 1:
        *(*(u8 **) KDProperty::pInstanceMem + (this->unk8 + 0x14)) = 1;
        return;
    case 2:
        *(*(u8 **) KDProperty::pInstanceMem + (this->unk8 + 0x14)) = 0;
        return;
    }
}
