s32 FXBaseDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_232;

    var_r31_232 = 0;
    if ((KDPropExDescriptor::LoadLine(arg0) != 0) || (arg0->LoadInt("iBurstCount", (int *) &this->unkC0, 0) != 0) || (arg0->LoadFloat("fBurstCone", &this->unkC4, 0) != 0) || (arg0->LoadFloat("fBurstMinVel", &this->unkC8, 0) != 0) || (arg0->LoadFloat("fBurstMaxVel", &this->unkCC, 0) != 0) || (arg0->LoadFloat("fBurstMinRadius", &this->unkD0, 0) != 0) || (arg0->LoadFloat("fBurstMaxRadius", &this->unkD4, 0) != 0) || (arg0->LoadFloat("fBurstMinScale", &this->unkD8, 0) != 0) || (arg0->LoadFloat("fBurstMaxScale", &this->unkDC, 0) != 0)) {
        var_r31_232 = 1;
    }
    return var_r31_232;
}
