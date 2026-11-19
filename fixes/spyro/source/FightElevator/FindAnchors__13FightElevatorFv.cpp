void FightElevator::FindAnchors() {
    FightElevatorAnchor *cur;
    FightElevatorAnchor *next;
    void *pos;
    f32 dx;
    f32 dy;
    f32 dz;
    u8 found;
    s32 scan;
    s32 ctr;
    s32 count;
    s32 slot;

    cur = checked_cast<FightElevatorAnchor *, MKProp>(M2C_FIELD(this->unk298, MKProp **, 0x28));
    count = 0;
    slot = 0;
loop_12:
    if ((cur != NULL) && (count < 6)) {
        pos = M2C_FIELD(cur, void **, 8);
        dx = M2C_FIELD(pos, f32 *, 0x30) - M2C_FIELD(this->unk8, f32 *, 0x30);
        dy = M2C_FIELD(pos, f32 *, 0x34) - M2C_FIELD(this->unk8, f32 *, 0x34);
        dz = M2C_FIELD(pos, f32 *, 0x38) - M2C_FIELD(this->unk8, f32 *, 0x38);
        if ((((dz * dz) + ((dx * dx) + (dy * dy))) <= FIGHT_ELEVATOR_TO_BLOCKER_BLOCK_DISTANCE_SQ) && (dy < M2C_BITWISE(f32, 209.99998474121094)) && (dy > 0.0f)) {
            found = 0;
            scan = 0;
            ctr = 6;
loop_5:
            if ((u32) M2C_FIELD(this, s32 *, 0x29C + scan) == (u32) cur) {
                found = 1;
            } else {
                scan += 4;
                ctr -= 1;
                if (ctr != 0) {
                    goto loop_5;
                }
            }
            if (found == 0) {
                if ((u32) M2C_FIELD(this, s32 *, 0x29C + slot) == 0U) {
                    M2C_FIELD(this, FightElevatorAnchor **, 0x29C + slot) = cur;
                    count += 1;
                    slot += 4;
                }
            }
        }
        next = checked_cast<FightElevatorAnchor *, MKProp>(M2C_FIELD(cur, MKProp **, 0x38));
        cur = next;
        goto loop_12;
    }
}
