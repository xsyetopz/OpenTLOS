void LineSegmentTrail::Deinit() {
    s32 i;
    LSTrail **trails;
    LSTrail *trail;
    MKMaterial *material;

    material = this->unk70;
    if (material != NULL) {
        MKMaterial_Destroy(material);
        this->unk70 = NULL;
    }
    trails = (LSTrail **) ((s8 *) this + 0x58);
    for (i = 0; i < 6; i++) {
        trail = trails[i];
        if (trail != NULL) {
            FreeActiveTrail(trail);
            trails[i] = NULL;
        }
    }
    this->unk74.Deinit();
    this->unk88.Deinit();
    LineSegmentTrailPool::Deinit();
    MKProp::Deinit();
}
