void SnowballTree::Message(MKMessage *arg0) {
    SnowballTreeDescriptor *desc;

    if (arg0->unk0 == 4) {
        DropABall();
        if ((u8) KDSound_IsVoicePlaying(this->unkB4) == 0) {
            this->unkB4 = KDSound_Play3d(GS_SnowTreeHit, (const MKVector3 *) ((u8 *) this->unk8 + 0x30), 0U, -1, 0.0f, false);
        }
        desc = checked_cast<SnowballTreeDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        this->unk80->SetAnim((MKAnim *) desc->unk8C, 1.0f, 0.0f, 0, -1);
        this->unkC4 = 1;
    }
    KDProp::Message(arg0);
}
