s32 ElementalSpline::LoadLine(MKIniLine *arg0) {
    if (((SplineProp *) this)->SplineProp::LoadLine(arg0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("Element", (int *) &this->unk110, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadFloat("Width", &this->unkB4, 0) != 0) {
        this->unkB4 *= 100.0f;
        return 1U;
    }
    if (arg0->LoadFloat("StartTime", &this->unk100, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadFloat("HoldTime", &this->unk104, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadFloat("EndTime", &this->unk108, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("SubDivisions", (int *) &this->unk114, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadBool("HurtHero", (bool *) &this->unk118, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadVector4("EffectColour", &this->unkE0, 0) != 0) {
        return 1U;
    }
    if (this->unkD4.LoadLine(arg0, "OnConnect") != 0) {
        return 1U;
    }
    return (u8) (this->unkD8.LoadLine(arg0, "OnComplete") != 0);
}
