s32 SplineProp::LoadDone() {
    MKVector3 sp10;
    f32 sp8;

    sp8 = 0.0f;
    sp10 = ((KDUniformSpline *) &this->unkB0->unk30)->GetMeasure(0.0f, (Matrix *) KDSpline_PositionMixer, &sp8);
    M2C_FIELD(&MKProp::loadInfo, MKVector3 *, 0x40) = sp10;
    MKProp::LoadDone();
    this->unk8 = &this->unk50;
    M2C_STRUCT_COPY((s32) &this->unk4C + 4, (s32) (&MKProp::loadInfo - 4) + 4, 0x40);
    this->unk50.SetRotationToNone();
    CalcBounds();
    this->unkC = (BoundingVolume *) &this->unk90;
    this->unkB0->LoadDone();
}
