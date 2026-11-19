void AnimProperty::Command(int arg0) {
    switch (arg0) {
    case 1:
    case 3:
        *(*(u8 **) KDProperty::pInstanceMem + this->unk8) = 1;
        return;
    case 2:
        *(*(u8 **) KDProperty::pInstanceMem + this->unk8) = 0;
        return;
    }
}
