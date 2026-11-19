class ScreenMsg;

void UIProp::Message(MKMessage *arg0) {
    UIMessage sp8;
    ScreenMsg *temp_r3_msg;
    s32 temp_r0_107;

    temp_r0_107 = M2C_FIELD(arg0, s32 *, 0);
    switch (temp_r0_107) {
    case 0x7E:
        sp8.unk0 = 0xF;
        ((UIObject *) this->unk54)->Message(&sp8);
        break;
    case 0x7F:
        temp_r3_msg = checked_cast<ScreenMsg *, MKMessage>(arg0);
        ((UISystem *) this->unk54)->PushScreen((const char *) M2C_FIELD(temp_r3_msg, s8 **, 8));
        break;
    case 0x80:
        temp_r3_msg = checked_cast<ScreenMsg *, MKMessage>(arg0);
        ((UISystem *) this->unk54)->ChangeScreen((const char *) M2C_FIELD(temp_r3_msg, s8 **, 8));
        break;
    }
    MKProp::Message(arg0);
}
