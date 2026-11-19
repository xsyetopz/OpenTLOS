s32 CharacterGraphNodeProp::LoadDone() {
    MKProp::LoadDone();
    this->unk50.SetPos(*(MKVector3 *) ((s8 *) &MKProp::loadInfo + 0x40));
}
