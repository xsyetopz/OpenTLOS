void Music_ClearDelayedPlayBuffer() {
    pDelayedTrackBuffer[0x20] = 0;
    strcpy((char *) pDelayedTrackBuffer, "");
    pDelayedTrackBuffer[0x21] = 0;
}
