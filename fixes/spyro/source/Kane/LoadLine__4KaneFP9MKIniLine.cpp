s32 Kane::LoadLine(MKIniLine *arg0) {
    if (((u8) Enemy::LoadLine(arg0) != 0) || (arg0->LoadBool("StartEnabled", (bool *) &this->unkB14, 0) != 0) || (arg0->LoadInt("StartNode", (int *) &this->unkB10, 0) != 0)) {
        return 1;
    }
    return 0;
}
