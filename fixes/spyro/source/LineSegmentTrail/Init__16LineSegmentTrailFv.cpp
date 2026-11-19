void LineSegmentTrail::Init() {
    s32 i;
    LSTrail **trails;

    MKProp::Init();
    this->unk4C = NULL;
    this->unk50 = -1;
    this->unk54 = -1;
    this->unk70 = NULL;
    this->unk74.Init(0x14, 0U);
    this->unk88.Init(0x14, 0U);
    trails = (LSTrail **) ((s8 *) this + 0x58);
    for (i = 0; i < 6; i++) {
        trails[i] = NULL;
    }
    LineSegmentTrailPool::Init();
}
