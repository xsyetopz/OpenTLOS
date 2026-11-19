void TargetContext::Set(MKProp *arg0) {
    Targetable *sp10;
    s32 spC;
    s32 sp8;

    spC = 0;
    sp10 = NULL;
    sp8 = 0x8E;
    if (arg0 != NULL) {
        arg0->Message((MKMessage *) &sp8);
        Set(sp10);
        return;
    }
    Set((Targetable *) NULL);
}
