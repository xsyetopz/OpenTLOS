void AnimManager::Init(AnimEntry *arg0, int arg1, MKAnimScript *arg2) {
    s32 i;
    s32 off;

    i = 0;
    off = 0;
    this->unk0 = arg0;
    this->unk4 = arg1;
    while (i < this->unk4) {
        void *anim = arg2->GetAnim(M2C_FIELD(this->unk0, const char **, off));
        M2C_FIELD(this->unk0, void **, off + 4) = anim;
        i += 1;
        off += 8;
    }
}
