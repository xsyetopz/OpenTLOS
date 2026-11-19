void MKShape_DrawBox(const MKCollisionAABB &arg0, const MKVector4 &arg1, const Matrix &arg2, bool arg3) {
    MKShape_DrawBox(*((const MKVector3 *) &arg0), *((const MKVector3 *) ((u8 *) &arg0 + 0x10)), arg1, arg2, arg3);
}
