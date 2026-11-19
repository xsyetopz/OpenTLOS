void HurtProperty::Command(int arg0) {
    switch (arg0) {
    case 1:
        *(*(u8 **) KDProperty::pInstanceMem + this->unk8) = 1;
        DoHurt();
        return;
    case 2:
        *(*(u8 **) KDProperty::pInstanceMem + this->unk8) = 0;
        return;
    case 3:
        DoHurt();
        return;
    }
}
