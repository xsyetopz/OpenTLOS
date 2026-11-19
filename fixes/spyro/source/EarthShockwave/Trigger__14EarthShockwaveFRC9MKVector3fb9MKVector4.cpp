void EarthShockwave::Trigger(const MKVector3 &arg0, float arg1, bool arg2, MKVector4 arg3) {
    MKVector3 *pos;
    MKVector3 above;
    MKVector3 below;
    MKCollisionResult hit;
    Matrix sp190;
    MKVector3 spF0;
    MKVector3 vel;
    struct {
        s32 unk0;
        s32 unk4;
        MKVector3 unk8;
        u8 unk18;
    } sp170;
    f64 sp40;
    MKVector3 fwd;
    MKVector3 up;
    MKVector3 scale;
    MKVector3 negFwd;
    MKVector3 offset;

    this->unkA8 = 1;
    this->unkA0 = 0.5f;
    this->unkAC = arg2;
    *((MKVector4 *) &this->unkB0) = arg3;
    this->unkA4 = arg1;
    *((MKVector3 *) &this->unk90) = arg0;
    pos = (MKVector3 *) &this->unk90;

    above.unk0 = pos->unk0;
    above.unk4 = pos->unk4 + 200.0f;
    above.unk8 = pos->unk8;
    below.unk0 = pos->unk0;
    below.unk4 = pos->unk4 - 1000.0f;
    below.unk8 = pos->unk8;

    hit.unk0 = 0.0f;
    hit.unk4 = 0.0f;
    hit.unk8 = 0.0f;
    hit.unk10 = 0.0f;
    hit.unk14 = 0.0f;
    hit.unk18 = 0.0f;
    hit.unk20 = 0.0f;
    hit.unk24 = 0.0f;
    hit.unk28 = 0.0f;
    hit.unk2C = 1.0f;
    hit.unk30 = 0.0f;
    hit.unk34 = 0.0f;
    hit.unk38 = 0;
    hit.unk3C = 0;
    hit.unk40 = 3.4028235e38f;
    hit.unk44 = 0;
    hit.unk48 = NULL;
    hit.unk4C = -1;
    hit.unk50 = 0;
    if (MKCollision_RayCollide(above, below, &hit, (MKCollisionMode) 4, 0x0C000002) != 0) {
        *((MKVector3 *) &this->unk90) = *((MKVector3 *) &hit);
    }

    sp190 = Matrix::identity;
    sp190.Scale3x3(&sp190, 0.0f);
    sp190.unk30 = pos->unk0;
    sp190.unk34 = pos->unk4;
    sp190.unk38 = pos->unk8;
    sp190.unk3C = 1.0f;
    MKModel_SetWorldMatrix(this->unk4, sp190);
    MKModel_SetColor(this->unk4, *((MKVector4 *) &this->unkB0));

    if (M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
        spF0 = MKVector(1.0f, 1.0f, 1.0f);
        vel.unk0 = spF0.unk0 * 150.0f;
        vel.unk4 = spF0.unk4 * 150.0f;
        vel.unk8 = spF0.unk8 * 150.0f;
        sp170.unk0 = 0x417;
        sp170.unk4 = 0;
        sp170.unk8.unk0 = vel.unk0;
        sp170.unk8.unk4 = vel.unk4;
        sp170.unk8.unk8 = vel.unk8;
        sp170.unk18 = 1;
        sp40 = M2C_FIELD(&vel, f64 *, 0);
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), (s32 *) &sp170, sp40);
    }

    sp190 = Matrix::identity;
    fwd.unk0 = 0.0f;
    fwd.unk4 = -1.0f;
    fwd.unk8 = 0.0f;
    up.unk0 = 0.0f;
    up.unk4 = 0.0f;
    up.unk8 = 1.0f;
    KDMath_BuildMatrixFromFwd(&sp190, fwd, &up);
    scale.unk0 = 2.0f * arg1;
    scale.unk4 = 2.0f * arg1;
    scale.unk8 = 0.75f;
    sp190.Scale3x3(&sp190, scale);

    negFwd.unk0 = -fwd.unk0;
    negFwd.unk4 = -fwd.unk4;
    negFwd.unk8 = -fwd.unk8;
    offset.unk0 = negFwd.unk0 * 175.0f;
    offset.unk4 = negFwd.unk4 * 175.0f;
    offset.unk8 = negFwd.unk8 * 175.0f;
    sp190.unk30 = pos->unk0 + offset.unk0;
    sp190.unk34 = pos->unk4 + offset.unk4;
    sp190.unk38 = pos->unk8 + offset.unk8;
    sp190.unk3C = 1.0f;
    ((ExplosionWarpFX *) ((u8 *) &gb + 0x1C0))->StartWarp(&sp190);
}
