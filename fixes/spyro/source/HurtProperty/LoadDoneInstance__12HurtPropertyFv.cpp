void HurtProperty::LoadDoneInstance() {
    *(*(u8 **) KDProperty::pInstanceMem + this->unk8) = this->unk20;
}
