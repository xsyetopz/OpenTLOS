void BigBeetleHive::Shatter(bool arg0, MKVector3 *arg1, int arg2, MKVector3 *arg3) {
    KDSound_Play3d(GS_OBBigHiveSmash1, (const MKVector3 *) ((u8 *) this->unk8 + 0x30), 0U, -1, 0.0f, false);
    KDSound_Play3d(GS_OBBigHiveSmash2, (const MKVector3 *) ((u8 *) this->unk8 + 0x30), 0U, -1, 0.0f, false);
    Shatterable::Shatter(arg0, arg1, arg2, arg3, true, false);
}
