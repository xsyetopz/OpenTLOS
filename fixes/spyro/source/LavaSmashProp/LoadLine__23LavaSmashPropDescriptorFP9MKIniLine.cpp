s32 LavaSmashPropDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_796;

    var_r31_796 = 0;
    if ((ShatterableDescriptor::LoadLine(arg0) != 0) || (arg0->LoadFloat("burnRadius", &M2C_FIELD(this, f32 *, 0x16C), 0) != 0) || (arg0->LoadFloat("lavaBubbleYOffset", &this->unk170, 0) != 0) || (arg0->LoadFloat("sinkSpeed", &this->unk178, 0) != 0) || (arg0->LoadFloat("sinkDepth", &this->unk174, 0) != 0) || (arg0->LoadFloat("LavaSoundFadeIn", &this->unk180, 0) != 0) || (arg0->LoadFloat("LavaSoundFadeOut", &this->unk184, 0) != 0) || (KDSound_LoadLine(arg0, "LavaBubbleSound", (int *) &this->unk17C) != 0)) {
        var_r31_796 = 1;
    }
    return var_r31_796;
}
