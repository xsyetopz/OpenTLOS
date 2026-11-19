void LavaCannon::EmitExplodingEffects() {
    MKVector3 sp50;
    MKVector3 sp40;
    MKVector3 sp30;
    MKVector3 sp20;
    MKVector3 sp10;
    LavaCannonDescriptor *desc;
    void *cutscene;
    s32 sound;
    u8 playing;

    switch (this->unk25C) {
    case 0:
        if (this->unk254 >= 0.4f) {
            desc = checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            MKModel_CalculateNodeWorldPosition(this->unk80->unk8, desc->unk188, &sp50);
            desc = checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            ((Explosion4 *) desc->unk19C)->Trigger(sp50, 0.75f, 0, NULL, 5, 0, 1, 1, 1);
            this->unk254 = 0.0f;
            this->unk25C += 1;
        }
        break;
    case 1:
        if (this->unk254 >= 0.3f) {
            desc = checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            MKModel_CalculateNodeWorldPosition(this->unk80->unk8, desc->unk18C, &sp40);
            desc = checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            ((Explosion4 *) desc->unk19C)->Trigger(sp40, 0.75f, 0, NULL, 5, 0, 1, 1, 1);
            this->unk254 = 0.0f;
            this->unk25C += 1;
        }
        break;
    case 2:
        if (this->unk254 >= 0.2f) {
            desc = checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            MKModel_CalculateNodeWorldPosition(this->unk80->unk8, desc->unk184, &sp30);
            desc = checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            ((Explosion4 *) desc->unk19C)->Trigger(sp30, 0.75f, 0, NULL, 5, 0, 1, 1, 1);
            this->unk254 = 0.0f;
            this->unk25C += 1;
        }
        break;
    case 3:
        if (this->unk254 >= 0.2f) {
            desc = checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            MKModel_CalculateNodeWorldPosition(this->unk80->unk8, desc->unk18C, &sp20);
            desc = checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            ((Explosion4 *) desc->unk19C)->Trigger(sp20, 1.0f, 0, NULL, 5, 0, 1, 1, 1);
            this->unk254 = 0.0f;
            this->unk25C += 1;
        }
        break;
    case 4:
        if (this->unk254 >= 0.1f) {
            desc = checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            MKModel_CalculateNodeWorldPosition(this->unk80->unk8, desc->unk188, &sp10);
            desc = checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            ((Explosion4 *) desc->unk19C)->Trigger(sp10, 1.0f, 0, NULL, 5, 0, 1, 1, 1);
            this->unk254 = 0.0f;
            this->unk25C += 1;
            Shatterable::Shatter(0, NULL, -1, NULL, 1, 0);
            this->unk264 = 1;
            playing = 0;
            sound = KDSound_Play3d(GS_TowerHit, (const MKVector3 *) ((s8 *) this->unk8 + 0x30), 0, -1, 0.0f, 0);
            cutscene = M2C_FIELD(&gb, void **, 0xC);
            if (((M2C_FIELD(cutscene, u32 *, 0x78) != 0) || (M2C_FIELD(cutscene, u32 *, 0x84) != 0)) &&
                (((KDStateMachine<CutsceneSystem> *) ((s8 *) cutscene + 0x24))->GetState() != 0)) {
                playing = 1;
            }
            if (playing != 0) {
                KDSound_SetVolume(sound, 0.25f * (f32) KDSound_GetSoundEventVol(GS_TowerHit));
            }
        }
        break;
    }
    this->unk254 += gUpdateTimeDelta;
}
