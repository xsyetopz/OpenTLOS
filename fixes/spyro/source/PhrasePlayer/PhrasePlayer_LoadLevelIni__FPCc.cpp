void PhrasePlayer_LoadIni(const char *, PhraseEvent **, int *, UIStringTable *);

void PhrasePlayer_LoadLevelIni(const char *arg0) {
    PhrasePlayer_LoadIni(arg0, (PhraseEvent **) (&phraseData + 0x40), (int *) (&phraseData + 0x4C), &levelstringTable);
}
