void SwayProperty::Command(int arg0) {
    switch (arg0) {
    case 1:
        *(*(u8 **) KDProperty::pInstanceMem + (this->unk8 + 0x88)) = 1;
        return;
    case 2:
        *(*(u8 **) KDProperty::pInstanceMem + (this->unk8 + 0x88)) = 0;
        return;
    }
}
