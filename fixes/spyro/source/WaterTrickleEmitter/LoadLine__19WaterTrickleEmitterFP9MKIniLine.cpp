extern "C" s32 stricmp(s8 *, const char *);

s32 WaterTrickleEmitter::LoadLine(MKIniLine *arg0) {
    if (MKProp::LoadLine(arg0) != 0 ||
        arg0->LoadFloat("MinEmitRate", &M2C_FIELD(&this->unk4C, f32 *, 0x30), 0) != 0 ||
        arg0->LoadFloat("MaxEmitRate", &this->unk4C.unk34, 0) != 0 ||
        arg0->LoadInt("NumPerEmit", (int *) &this->unk84, 0) != 0 ||
        arg0->LoadFloat("MinEmitVel", &this->unk8C, 0) != 0 ||
        arg0->LoadFloat("MaxEmitVel", &this->unk90, 0) != 0 ||
        arg0->LoadFloat("Angle", &this->unkE0, 0) != 0) {
        return 1;
    }
    if (arg0->GetFieldName() != NULL) {
        arg0->GetFieldName();
        if (stricmp(arg0->GetFieldName(), "Waypoints") == 0) {
            if (arg0->GetNmbrOfSubLines() == 0) {
                this->unk94 = 0;
            } else {
                this->unk94 = 1;
            }
            this->unk4C.Init();
            this->unk4C.LoadLine(arg0);
        }
    }
    return 0;
}
