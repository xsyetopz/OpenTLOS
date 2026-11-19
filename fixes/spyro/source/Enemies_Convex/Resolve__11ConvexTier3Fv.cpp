f32 ConvexTier3::Resolve() {
    MKVector3 sp18;
    ModelCloth *cloth;
    s32 i;
    s32 off;

    Enemy::Resolve();
    cloth = MKModel_GetCloth(this->unk4);
    if (cloth != NULL) {
        i = 0;
        off = 0;
        while (i < cloth->unk4) {
            sp18.unk0 = 0.0f;
            sp18.unk4 = 0.0f;
            sp18.unk8 = 0.0f;
            ((MKCloth *) ((u8 *) cloth->unk8 + off))->SetForce(0, sp18, -1);
            i += 1;
            off += 0xF8;
        }
    }
}
