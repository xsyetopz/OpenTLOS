s32 PlatformDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_817;

    var_r31_817 = 0;
    if ((GamePropDescriptor::LoadLine(arg0) != 0) || (arg0->LoadFloat("maxTilt", &M2C_FIELD(this, f32 *, 0xE4), 0) != 0) || (arg0->LoadBool("bUpdateRotationMatrix", (bool *) &this->unkF5, 0) != 0) || (arg0->LoadFloat("rotVel", &this->unkF8, 0) != 0) || (arg0->LoadFloat("maxShadowHeight", &this->unkFC, 0) != 0) || (arg0->LoadBool("enableSway", (bool *) &this->unk104, 0) != 0) || (arg0->LoadBool("enableBob", (bool *) &this->unk118, 0) != 0)) {
        var_r31_817 = 1;
    }
    return var_r31_817;
}
