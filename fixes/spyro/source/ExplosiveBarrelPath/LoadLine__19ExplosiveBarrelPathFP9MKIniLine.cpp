s32 ExplosiveBarrelPath::LoadLine(MKIniLine *arg0) {
    MKVector3 sp58;
    MKVector3 sp48;
    MKVector3 sp38;
    MKVector3 sp28;
    MKVector3 sp18;
    MKVector3 sp8;
    MKIniLine *var_r30_1936;
    MKIniLine *var_r30_2010;
    s32 temp_r3_1937;
    s32 temp_r3_2011;
    s32 var_r31_2077;

    if (MKProp::LoadLine(arg0) != 0) {
        return 1;
    }
    if (arg0->IsField("LeftTrack") != 0) {
        var_r30_1936 = arg0->unkC->GetSubLine(arg0);
        temp_r3_1937 = arg0->GetNmbrOfSubLines();
        if (temp_r3_1937 != 0) {
            ((KDUniformSpline *) &this->unk50)->Init(temp_r3_1937, 0);
            while (var_r30_1936 != NULL) {
                sp58 = var_r30_1936->GetVector3(0);
                if ((u8) this->unk1B0 != 0) {
                    *(MKVector3 *) &this->unk190 = sp58;
                    *(MKVector3 *) &this->unk1A0 = sp58;
                    this->unk1B0 = 0;
                } else {
                    sp48 = Min(*(MKVector3 *) &this->unk190, sp58);
                    *(MKVector3 *) &this->unk190 = sp48;
                    sp38 = Max(*(MKVector3 *) &this->unk1A0, sp58);
                    *(MKVector3 *) &this->unk1A0 = sp38;
                }
                ((KDUniformSpline *) &this->unk50)->AddNode(sp58);
                var_r30_1936 = var_r30_1936->unkC->GetNextLine(var_r30_1936);
            }
        }
        return 1;
    }
    if (arg0->IsField("RightTrack") != 0) {
        var_r30_2010 = arg0->unkC->GetSubLine(arg0);
        temp_r3_2011 = arg0->GetNmbrOfSubLines();
        if (temp_r3_2011 != 0) {
            ((KDUniformSpline *) &this->unk50.unk14)->Init(temp_r3_2011, 0);
            while (var_r30_2010 != NULL) {
                sp28 = var_r30_2010->GetVector3(0);
                if ((u8) this->unk1B0 != 0) {
                    *(MKVector3 *) &this->unk190 = sp28;
                    *(MKVector3 *) &this->unk1A0 = sp28;
                    this->unk1B0 = 0;
                } else {
                    sp18 = Min(*(MKVector3 *) &this->unk190, sp28);
                    *(MKVector3 *) &this->unk190 = sp18;
                    sp8 = Max(*(MKVector3 *) &this->unk1A0, sp28);
                    *(MKVector3 *) &this->unk1A0 = sp8;
                }
                ((KDUniformSpline *) &this->unk50.unk14)->AddNode(sp28);
                var_r30_2010 = var_r30_2010->unkC->GetNextLine(var_r30_2010);
            }
        }
        return 1;
    }
    var_r31_2077 = 0;
    if ((arg0->LoadFloat("Speed", &this->unk220, 0) != 0) || (arg0->LoadFloat("Acceleration", &this->unk224, 0) != 0) || (arg0->LoadInt("BounceChance", (int *) &this->unk228, 0) != 0) || (arg0->LoadFloat("BounceSpeed", &this->unk22C, 0) != 0) || (arg0->LoadBool("bAutoShootBarrels", (bool *) &this->unk231, 0) != 0) || (arg0->LoadBool("bOneShot", (bool *) &this->unk230, 0) != 0) || (arg0->LoadFloat("fAutoShootDelay", &this->unk234, 0) != 0) || (arg0->LoadFloat("fExplosionRadiusScale", &this->unk23C, 0) != 0)) {
        var_r31_2077 = 1;
    }
    return var_r31_2077;
}
