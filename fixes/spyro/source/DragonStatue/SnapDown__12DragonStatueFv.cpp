void DragonStatue::SnapDown() {
    MKVector3 pos;

    *(f64 *) &pos.unk0 = this->unkD8;
    pos.unk8 = this->unkE0;
    pos.unk4 = pos.unk4 - 6600.0f;
    this->SetPos(pos);
    this->unk100 = 1;
}
