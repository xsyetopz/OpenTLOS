void KDSP_Sounds::LoadStaticSoundBank(const char *arg0, bool arg1) {
    const char *name;
    SoundBankHeader *bank;

    name = (const char *) Str_Printf("%s.gsb", arg0);
    if ((u8) MKArchive_Exists(name, NULL) != 0) {
        bank = (SoundBankHeader *) MKArchive_Load(name, NULL, NULL, -1);
        this->unk24 = Sound_LoadBankFromMemory(bank, 0, -1);
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) MKHeap::Main())->TFree(bank, NULL, 0);
        } else {
            free(bank);
        }
    }
}
