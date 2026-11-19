s32 UISystem::Message(UIMessage *arg0) {
    s32 temp_r5_269;

    temp_r5_269 = arg0->unk0;
    switch (temp_r5_269) {
    case 0xD:
        ChangeScreen_Internal(ui_cast<UIScreen *, UIObject *>((UIObject *) arg0->unk4));
    default:
    block_14:
        return UIContainer::Message(arg0);
    case 0xE:
        PushScreen_Internal(ui_cast<UIScreen *, UIObject *>((UIObject *) arg0->unk4));
        goto block_14;
    case 0xF:
        PopScreen_Internal();
        goto block_14;
    case 0x8001:
        this->unk9E = 1;
        return 1;
    }
}
