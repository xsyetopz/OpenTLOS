void LavaBall::Collided(MKCollisionResult &arg0) {
    LavaBallDescriptor *temp_r3_105;
    ShapedTrailFX *temp_r5_118;
    void **vtbl;

    Projectile::Collided(arg0);
    temp_r3_105 = checked_cast<LavaBallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    M2C_FIELD(temp_r3_105, Explosion4 **, 0xF0)->Trigger(*((MKVector3 *) &arg0), 0.75f, 1U, this->unk130, 5, 1U, 1U, 1U, 1U);
    temp_r5_118 = this->unk150;
    temp_r5_118->unkA0 = (temp_r5_118->unkA0 & ~0x80) | ((lit_522 << 7) & 0x80);
    vtbl = *(void ***) ((u8 *) this + 0x44);
    ((void (*)(LavaBall *, u8, ShapedTrailFX *)) vtbl[13])(this, lit_522, temp_r5_118);
}
