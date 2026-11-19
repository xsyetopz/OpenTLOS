void Music_SetDelayedPlay(const char *arg0, bool arg1) {
    pDelayedTrackBuffer[0x20] = (s8) arg1;
    strcpy((char *) pDelayedTrackBuffer, arg0);
    pDelayedTrackBuffer[0x21] = 1;
}
