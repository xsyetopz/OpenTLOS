void SpyroCollisionObject::Init(ColObjDescriptor *arg0, const MKVector3 &arg1, bool arg2, MKCollisionInfo *arg3, bool arg4, bool arg5, unsigned int arg6, MKProp *arg7, bool arg8) {
    MKVector3 sp10;

    CollisionObject::Init(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
    sp10 = MKVector(0.0f, M2C_FIELD(this->unk460, f32 *, 4), 0.0f);
    *(MKVector3 *) &this->unk480 = sp10;
    this->unk47C = 20.0f;
    this->unk478 = 20.0f;
}
