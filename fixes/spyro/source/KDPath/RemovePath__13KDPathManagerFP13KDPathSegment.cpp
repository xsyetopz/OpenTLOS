void KDPathManager::RemovePath(KDPathSegment *arg0) {
    KDPathNode *temp_r3_335;
    KDPathNode *temp_r3_351;
    s32 temp_r3_344;

    ((KDPathNode *) this)->Unlink();
    ((KDPathNode *) &this->unk8)->Unlink();
    temp_r3_335 = this->unk2C;
    if (temp_r3_335 != NULL) {
        temp_r3_335->unk28 = this->unk28;
    } else {
        temp_r3_344 = this->unk18 * 4;
        if ((u32) *(KDPathSegment **) ((u8 *) *(KDPathSegment ***) KDPathManager::pPathLists + temp_r3_344) == (u32) this) {
            *(KDPathSegment **) ((u8 *) *(KDPathSegment ***) KDPathManager::pPathLists + temp_r3_344) = (KDPathSegment *) this->unk28;
        }
    }
    temp_r3_351 = this->unk28;
    if (temp_r3_351 != NULL) {
        temp_r3_351->unk2C = this->unk2C;
    }
    this->unk2C = NULL;
    this->unk28 = NULL;
}
