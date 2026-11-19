void PhrasePlayer_UnloadIniData(PhraseEvent **arg0, int *arg1, UIStringTable *arg2) {
    PhraseEvent *temp_r31_547;
    s32 var_r30_528;
    s32 var_r31_529;

    if (*arg0 != NULL) {
        var_r30_528 = 0;
        var_r31_529 = 0;
        while (var_r30_528 < (s32) *arg1) {
            arg2->Remove(M2C_FIELD(*arg0, const char **, var_r31_529));
            arg2->Remove(M2C_FIELD(*arg0, const char **, var_r31_529 + 4));
            var_r30_528 += 1;
            var_r31_529 += 0x18;
        }
        temp_r31_547 = *arg0;
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_547, NULL, 0);
        } else {
            free(temp_r31_547);
        }
        *arg0 = NULL;
        *arg1 = 0;
    }
    arg2->Deinit();
}
