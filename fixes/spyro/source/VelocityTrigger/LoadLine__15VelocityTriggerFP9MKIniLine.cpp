s32 VelocityTrigger::LoadLine(MKIniLine *arg0) {
    s32 var_r31_165;

    var_r31_165 = 0;
    if ((TriggerBoxProp::LoadLine(arg0) != 0) || (M2C_FIELD(this->unk190, u8 (**)(void *, const char *, MKIniLine *), 0x38)(&this->unk190, "box", arg0) != 0) || (arg0->LoadVector3("TrigInitalVelocity", &this->unk250, 0) != 0) || (arg0->LoadVector3("TrigAcceleration", &this->unk260, 0) != 0) || (arg0->LoadVector3("TrigNoiseMin", &this->unk270, 0) != 0) || (arg0->LoadVector3("TrigNoiseMax", &this->unk280, 0) != 0)) {
        var_r31_165 = 1;
    }
    return var_r31_165;
}
