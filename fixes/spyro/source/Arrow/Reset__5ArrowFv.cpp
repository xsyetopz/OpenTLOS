void Arrow::Reset() {
    PropFlagsSet((unsigned int *) &this->unk10, 0x80000U);
    Trap::Reset();
}
