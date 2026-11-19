s32 WobbleProp::LoadDone() {
    WobblePropDescriptor *temp_r3;

    GameProp::LoadDone();
    this->unkC8 = MKDynamicBone_GetDynamicBone(this->unk4, ((Animation *) (MKModel_GetAnimation(this->unk4)))->GetNodeIndex("d_wobbler"));
    this->unkCC = 0;
    this->unkD0 = 0.0f;
    temp_r3 = checked_cast<WobblePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    this->unkD4 = Tools_GetMatchingMaterial(this->unk4, (const char *) M2C_FIELD(temp_r3, s8 **, 0xEC));
}
