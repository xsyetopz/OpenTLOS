void RumbleTimer_Init() {
    s32 InputReceiver(MKInputEvent *, void *);

    bStopped = 0;
    timer = 15.0f;
    pReceiver = MKInputReceiver_Create((bool (*)(MKInputEvent *, void *)) InputReceiver, -1, 5, NULL);
}
