MKVector3 FightElevatorAnchor::GetZapAnchorPos() {
    MKVector3 sp8;

    MKModel_CalculateRefPointWorldPosition(this->unk4, this->unk1AC, &sp8);
    return sp8;
}