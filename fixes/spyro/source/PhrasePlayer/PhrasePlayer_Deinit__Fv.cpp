void Phrase_Unload();
void PhrasePlayer_UnloadIniData(PhraseEvent **, int *, UIStringTable *);

void PhrasePlayer_Deinit() {
    Phrase_Unload();
    PhrasePlayer_UnloadIniData((PhraseEvent **) (&phraseData + 0x3C), (int *) (&phraseData + 0x48), &globalstringTable);
}
