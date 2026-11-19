s32 ElementalWall::LoadLine(MKIniLine *arg0) {
    if (SplineProp::LoadLine(arg0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("Element", (int *) &this->unk100, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadBool("InfiniteCollision", (bool *) &this->unk11C, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadFloat("Height", &this->unk10C, 0) != 0) {
        this->unk110 = 100.0f * this->unk10C;
        this->unk10C = 0.0f;
        return 1U;
    }
    if (arg0->LoadInt("HSubDivisions", (int *) &this->unk104, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("VSubDivisions", (int *) &this->unk108, 0) != 0) {
        return 1U;
    }
    return (u8) (arg0->LoadFloat("IgniteTime", &this->unk120, 0) != 0);
}
