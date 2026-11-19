void SwarmProp::Draw() {
    Matrix sp70;
    Matrix sp30;
    MKVector4 sp20;
    SwarmPropDescriptor *desc;
    SwarmEntity **cur;

    KDProp::Draw();
    M2C_STRUCT_COPY(&sp70, MKView_GetCameraMatrix(), 0x40);
    M2C_STRUCT_COPY(&sp30, &this->unk90, 0x40);
    sp30.Multiply3x3(&sp30, &sp70);
    desc = checked_cast<SwarmPropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    MKMaterial_SetMaterial(M2C_FIELD(desc, MKMaterial **, 0x90));
    sp20.unk0 = 0.8f;
    sp20.unk4 = 0.8f;
    sp20.unk8 = 0.0f;
    sp20.unkC = 1.0f;
    MKPrimitive(0xC, 0);
    cur = this->unkF4;
    while (*cur != NULL) {
        DrawEntity(*cur, sp30, sp20, 10.0f);
        cur += 1;
    }
    MKEndPrimitive();
}
