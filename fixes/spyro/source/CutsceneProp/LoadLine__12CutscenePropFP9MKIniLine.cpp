s32 CutsceneProp::LoadLine(MKIniLine *arg0) {
    s32 result = 0;

    if (((u8) MKProp::LoadLine(arg0) != 0) || ((u8) arg0->LoadBool("bLevelIntro", (bool *) &this->unkBC, 0) != 0) || ((u8) arg0->LoadFloat("MusicDuckValue", &this->unkB8, 0) != 0) || ((u8) PropFlagsLoadLine((unsigned int *) &this->unk10, arg0) != 0) || ((u8) this->unk50.LoadLine(arg0) != 0)) {
        result = 1;
    }
    return result;
}
