MusicTrack *Music_FindTrack(const char *arg0) {
    MusicTrack *var_r30_408;
    s32 var_r29_409;
    s32 var_r31_410;

    var_r30_408 = NULL;
    var_r29_409 = 0;
    var_r31_410 = 0;
    while ((pTracks != NULL) && (var_r29_409 < (s32) trackCount) && (var_r30_408 == NULL)) {
        if (stricmp((s8 *) arg0, ((MusicTrack *) ((s8 *) pTracks + var_r31_410))->unk0) == 0) {
            var_r30_408 = (MusicTrack *) ((s8 *) pTracks + var_r31_410);
        }
        var_r29_409 += 1;
        var_r31_410 += 0x28;
    }
    return var_r30_408;
}
