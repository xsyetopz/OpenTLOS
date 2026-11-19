void LineSegmentTrail::EndTrail() {
    s32 i;
    LSTrail **trails;
    LSTrail *trail;

    trails = (LSTrail **) ((s8 *) this + 0x58);
    for (i = 0; i < 6; i++) {
        trail = trails[i];
        if ((trail != NULL) && ((u8) M2C_FIELD(trail, u8 *, 0x24) != 0) && ((u8) M2C_FIELD(trail, u8 *, 0x1C) == 0)) {
            M2C_FIELD(trail, u8 *, 0x1C) = 1U;
        }
    }
}
