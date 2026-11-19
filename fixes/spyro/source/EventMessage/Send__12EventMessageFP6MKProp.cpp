f32 EventMessage::Send(MKProp *arg0) {
    f32 var_f1_13;

    var_f1_13 = 1.0f;
    if ((u32) this->unk0 != 0U) {
        ConsoleCmds_pSenderProp = arg0;
        var_f1_13 = Console_Execute((const char *) this->unk0);
        ConsoleCmds_pSenderProp = NULL;
    }
    return var_f1_13;
}
