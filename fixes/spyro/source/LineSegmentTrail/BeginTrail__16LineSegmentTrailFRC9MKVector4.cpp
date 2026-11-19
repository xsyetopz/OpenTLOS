void LineSegmentTrail::BeginTrail(const MKVector4 &arg0) {
    s32 i;
    LSTrail **trails;
    LSTrail *trail;

    trails = (LSTrail **) ((s8 *) this + 0x58);
    for (i = 0; i < 6; i++) {
        if (trails[i] == NULL) {
            trails[i] = (LSTrail *) LineSegmentTrailPool::Alloc();
            if (trails[i] != NULL) {
                trail = trails[i];
                *(MKVector4 *) &trail->unk8 = arg0;
                UpdateTrail(trail);
                return;
            }
        }
    }
}
