void Phrase_LoadPackage();
void Phrase_LoadSound();
void Phrase_Unload();

void Phrase_Update() {
    u8 var_r31_1270;

    switch ((s32) M2C_FIELD(&phraseData, s32 *, 0x24)) {
    case 1:
        if ((s32) M2C_FIELD(&phraseData, s32 *, 0x30) != 0) {
            var_r31_1270 = 0;
            if ((((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x78) != 0U) || ((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x84) != 0U)) && (((KDStateMachine<CutsceneSystem> *) (((u8 *) M2C_FIELD(&gb, void **, 0xC)) + 0x24))->GetState() != 0)) {
                var_r31_1270 = 1;
            }
            if (var_r31_1270 == 0) {
                Phrase_LoadPackage();
                return;
            }
        } else {
            return;
        }
        break;
    case 2:
        if ((MKPackage_QIsLoaded(M2C_FIELD(&phraseData, s32 *, 0x28), NULL, NULL) != 0) && (Sound_IsBankLoading() == 0)) {
            Music_Duck(0.0f, 0.5f);
            Phrase_LoadSound();
            return;
        }
        break;
    case 3:
        if (KDSound_IsVoicePlaying(M2C_FIELD(&phraseData, s32 *, 0x20)) == 0) {
            Phrase_Unload();
            Music_UnDuck(2.0f);
        }
        break;
    }
}
