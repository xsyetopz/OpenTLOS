void Cheats_Init() {
    s32 CheatReceiver(MKInputEvent *arg0, void *arg1);

    pReceiver = MKInputReceiver_Create((bool (*)(MKInputEvent *, void *)) CheatReceiver, 0x3C, 2, NULL);
}
