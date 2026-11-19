void Projectile::Collided(MKCollisionResult &arg0) {
    s32 *temp_r3_136;
    s32 temp_r3_125;

    this->unk14C &= ~0x10;
    temp_r3_125 = this->unk148;
    if (temp_r3_125 != 0) {
        KDSound_Play3d(temp_r3_125, (const MKVector3 *) (((u8 *) this->unk8) + 0x30), (u32) arg0.unk44, -1, 0.0f, false);
    }
    temp_r3_136 = this->unk138;
    if (temp_r3_136 != NULL) {
        KDSound_Stop((int *) temp_r3_136);
    }
}
