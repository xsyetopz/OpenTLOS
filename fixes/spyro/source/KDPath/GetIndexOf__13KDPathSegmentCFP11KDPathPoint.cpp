s32 KDPathSegment::GetIndexOf(KDPathPoint *arg0) const {
    return (s32) ((u8 *) arg0 - (u8 *) this->unk24) / this->unk1C;
}
