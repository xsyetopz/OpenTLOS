void HurtProperty::Update() {
    if (*(*(u8 **) KDProperty::pInstanceMem + this->unk8) != 0) {
        DoHurt();
    }
}
