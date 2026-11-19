f32 LavaCannon::Resolve() {
    LavaCannonDescriptor *desc;

    Shatterable::Resolve();
    desc = checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    this->unk208.Init((AnimEventDesc *) ((u8 *) desc + 0x1A4));
    MKModel_GetAnimation(this->unk80->unk8)->EnableCustomMatrices(1);
}
