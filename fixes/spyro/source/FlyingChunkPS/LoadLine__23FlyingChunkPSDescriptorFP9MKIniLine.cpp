s32 FlyingChunkPSDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_2136;

    var_r31_2136 = 0;
    if ((GamePropColoredDescriptor::LoadLine(arg0) != 0) || (arg0->LoadInt("MaxNumChunks", (int *) &this->unkE8, 0) != 0) || (arg0->LoadFloat("MaxAge", &this->unkF0, 0) != 0) || (arg0->LoadBool("Collide", (bool *) &this->unkF4, 0) != 0) || (arg0->LoadVector3("Accel", &this->unkF8, 0) != 0)) {
        var_r31_2136 = 1;
    }
    return var_r31_2136;
}
