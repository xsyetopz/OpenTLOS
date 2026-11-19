s32 MKOcean::LoadLine(MKIniLine *arg0) {
    s32 var_r31_500;

    var_r31_500 = 0;
    if ((((MKFFTBaseType *) this)->LoadLine(arg0) != 0) || (arg0->LoadFloat("Wave1XFrequency", &this->unk50D0, 0) != 0) || (arg0->LoadFloat("Wave1ZFrequency", &this->unk50D4, 0) != 0) || (arg0->LoadFloat("SmallestWaveLength", &this->unk5180, 0) != 0) || (arg0->LoadFloat("LargestWaveLength", &this->unk5184, 0) != 0) || (arg0->LoadFloat("FadeOff", &this->unk5174, 0) != 0) || (arg0->LoadFloat("WaveHeight", &this->unk5178, 0) != 0) || (arg0->LoadFloat("heightScaler", &this->unk517C, 0) != 0) || (arg0->LoadFloat("deadDistance", &this->unk521C, 0) != 0) || (arg0->LoadBool("Enabled", (bool *) &this->unk520C, 0) != 0) || (arg0->LoadFloat("WobbleAmount", &this->unk5170, 0) != 0)) {
        var_r31_500 = 1;
    }
    return var_r31_500;
}
