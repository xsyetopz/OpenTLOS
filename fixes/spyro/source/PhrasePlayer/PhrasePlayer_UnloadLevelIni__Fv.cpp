void PhrasePlayer_UnloadIniData(PhraseEvent **, int *, UIStringTable *);

void PhrasePlayer_UnloadLevelIni() {
    PhrasePlayer_UnloadIniData((PhraseEvent **) (&phraseData + 0x40), (int *) (&phraseData + 0x4C), &levelstringTable);
}
