void EarthBombFX::Draw() {
    EarthBombFXDescriptor *desc;

    if ((u8) this->unkE0 != 0) {
        desc = checked_cast<EarthBombFXDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        gRenderState = (s32) desc->unkEC;
        GameProp::Draw();
        gRenderState = 0;
    }
}
