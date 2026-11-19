void LavaCannonDescriptor::LoadDone() {
    MKAnimScript *anims;
    void *anim;

    ShatterableDescriptor::LoadDone();
    anims = (MKAnimScript *) this->unk34;
    if (anims->Exists("idle") != 0) {
        anim = anims->GetAnim("idle");
    } else {
        anim = NULL;
    }
    M2C_FIELD(this, s32 *, 0x16C) = (s32) anim;
    anims = (MKAnimScript *) this->unk34;
    if (anims->Exists("idle") != 0) {
        anim = anims->GetAnim("idle");
    } else {
        anim = NULL;
    }
    this->unk170 = (s32) anim;
    anims = (MKAnimScript *) this->unk34;
    if (anims->Exists("idle") != 0) {
        anim = anims->GetAnim("idle");
    } else {
        anim = NULL;
    }
    this->unk174 = (s32) anim;
    anims = (MKAnimScript *) this->unk34;
    if (anims->Exists("firing") != 0) {
        anim = anims->GetAnim("firing");
    } else {
        anim = NULL;
    }
    this->unk178 = (s32) anim;
    anims = (MKAnimScript *) this->unk34;
    if (anims->Exists("exploding") != 0) {
        anim = anims->GetAnim("exploding");
    } else {
        anim = NULL;
    }
    this->unk17C = (s32) anim;
    anims = (MKAnimScript *) this->unk34;
    if (anims->Exists("idle") != 0) {
        anim = anims->GetAnim("idle");
    } else {
        anim = NULL;
    }
    this->unk180 = (s32) anim;
    this->unk184 = MKModel_GetAnimation(((MKAnimScript *) this->unk34)->unk8)->GetNodeIndex("z_yaw");
    this->unk188 = MKModel_GetAnimation(((MKAnimScript *) this->unk34)->unk8)->GetNodeIndex("z_pitch");
    this->unk18C = MKModel_GetAnimation(((MKAnimScript *) this->unk34)->unk8)->GetNodeIndex("z_barrel1");
    this->unk190 = MKModel_GetRefPointIndex(this->unk2C, "r_emitter");
    this->unk19C = (s32) checked_cast<Explosion4 *, MKProp>(gMK->CreateProp("Explosion4"));
    this->unk1AC.unk0 = (s8 *) "fire";
    this->unk1B4 = (s8 *) "firesound";
}
