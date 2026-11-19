void Music_Deinit() {
    s32 var_r30_1018;
    s32 var_r31_1019;
    void *temp_r31_1037;

    if (pTracks != NULL) {
        var_r30_1018 = 0;
        var_r31_1019 = 0;
        while (var_r30_1018 < (s32) trackCount) {
            stringTable.Remove((const char *) ((MusicTrack *) ((s8 *) pTracks + var_r31_1019))->unk4);
            stringTable.Remove((const char *) ((MusicTrack *) ((s8 *) pTracks + var_r31_1019))->unk0);
            var_r30_1018 += 1;
            var_r31_1019 += 0x28;
        }
        temp_r31_1037 = pTracks;
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_1037, NULL, 0);
        } else {
            free(temp_r31_1037);
        }
        pTracks = NULL;
    }
    stringTable.Deinit();
}
