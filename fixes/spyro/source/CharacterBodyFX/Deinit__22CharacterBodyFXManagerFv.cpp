void CharacterBodyFXManager::Deinit() {
    CharacterBodyFX ***var31;
    CharacterBodyFX ***r3;
    CharacterBodyFX ***slot;
    CharacterBodyFX **entry;

    var31 = this->unk0;
    while (var31 != NULL && *var31 != NULL) {
        (**var31)->Deinit();
        operator delete(**var31);
        var31 += 1;
    }
    while (*this->unk0 != NULL) {
        this->unk0 += 1;
    }
    var31 = this->unk0;
    slot = this->unk0;
    r3 = this->unk0;
    r3 -= 1;
    entry = *r3;
    while (entry != NULL) {
        if ((u32) entry < (u32) var31) {
            var31 = (CharacterBodyFX ***) entry;
        }
        r3 -= 1;
        entry = *r3;
    }
    if ((u32) r3 != (u32) &gEmptyPtrListDL) {
        while (*slot != NULL) {
            if ((u32) *slot < (u32) var31) {
                var31 = (CharacterBodyFX ***) *slot;
            }
            slot += 1;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(var31, NULL, 0);
        } else {
            free(var31);
        }
    }
    this->unk0 = NULL;
}
