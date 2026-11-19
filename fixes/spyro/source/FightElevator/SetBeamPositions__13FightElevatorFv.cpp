void FightElevator::SetBeamPositions() {
    MKVector3 sp8;
    FightElevatorAnchor *anchor;
    void *temp_r3;
    s32 count;
    s32 off;
    s32 aoff;
    s32 boff;

    count = 0;
    off = 0;
    boff = 0;
    temp_r3 = this->unk8;
    this->unk288 = M2C_FIELD(temp_r3, f64 *, 0x30);
    this->unk290 = M2C_FIELD(temp_r3, f64 *, 0x38);
    do {
        anchor = M2C_FIELD(this, FightElevatorAnchor **, off + 0x29C);
        if (anchor != NULL) {
            sp8 = anchor->GetZapAnchorPos();
            M2C_FIELD(this, MKVector3 *, boff + 0x228) = sp8;
        }
        count += 1;
        off += 4;
        boff += 0x10;
    } while (count < 6);
    AllocBeams();
}
