void RotateProperty::Command(int arg0) {
    switch (arg0) {
    case 1:
        *(*(u8 **) KDProperty::pInstanceMem + (this->unk8 + 0x84)) = 1;
        return;
    case 2:
        *(*(u8 **) KDProperty::pInstanceMem + (this->unk8 + 0x84)) = 0;
        return;
    }
}
