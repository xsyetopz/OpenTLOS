void LightningStrikeFX::Draw() {
    LightningStrikeFXDescriptor *desc;

    desc = checked_cast<LightningStrikeFXDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    desc->DrawStrikeArcs();
}
