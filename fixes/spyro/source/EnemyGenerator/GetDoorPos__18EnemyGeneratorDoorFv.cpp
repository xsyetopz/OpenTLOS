MKVector3 EnemyGeneratorDoor::GetDoorPos() {
    MKVector3 sp8;

    MKModel_CalculateRefPointWorldPosition(M2C_FIELD(M2C_FIELD(this, void **, 8), MKModel **, 4), this->unk10, &sp8);
    return sp8;
}
