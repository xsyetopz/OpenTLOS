void LineSegmentTrail::FreeActiveTrail(LSTrail *arg0) {
    s32 i;
    LSTrail **trails;

    trails = (LSTrail **) ((s8 *) this + 0x58);
    for (i = 0; i < 6; i++) {
        if (trails[i] == arg0) {
            trails[i] = NULL;
            LineSegmentTrailPool::Free(arg0);
        }
    }
}
