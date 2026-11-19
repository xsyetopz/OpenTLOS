void *LineSegmentTrail::Update() {
    s32 i;
    LSTrail **trails;
    LSTrail *trail;

    trails = (LSTrail **) ((s8 *) this + 0x58);
    for (i = 0; i < 6; i++) {
        trail = trails[i];
        if (trail != NULL) {
            UpdateTrail(trail);
        }
    }
}
