s32 KDParticleEmitter::LoadLine(MKIniLine *arg0) {
    s32 var_r31_615;

    var_r31_615 = 0;
    if ((arg0->LoadBool("active", (bool *) &this->unk40, 0) != 0) || (arg0->LoadFloat("rate", (f32 *) &this->unk2C, 0) != 0) || (arg0->LoadFloat("angle", &this->unk38, 0) != 0) || (arg0->LoadFloat("minScale", &this->unk68, 0) != 0) || (arg0->LoadFloat("maxScale", &this->unk64, 0) != 0) || (arg0->LoadFloat("minVel", &this->unk50, 0) != 0) || (arg0->LoadFloat("maxVel", &this->unk4C, 0) != 0) || (arg0->LoadFloat("minRot", &this->unk58, 0) != 0) || (arg0->LoadFloat("maxRot", &this->unk54, 0) != 0) || (arg0->LoadFloat("minRotVel", &this->unk60, 0) != 0) || (arg0->LoadFloat("maxRotVel", &this->unk5C, 0) != 0)) {
        var_r31_615 = 1;
    }
    return var_r31_615;
}
