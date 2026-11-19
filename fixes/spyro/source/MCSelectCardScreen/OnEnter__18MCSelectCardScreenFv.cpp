void MCSelectCardScreen::OnEnter() {
    MemoryCardScreen::OnEnter();
    *(s32 *) MemoryCardScreen::selectedCard = 0;
    *(s32 *) MemoryCardScreen::selectedFile = -1;
    ClearDisplay();
    this->unkD0 = 0;
    this->unkF0 = ui_cast<MCSaveScreen *, UIScreen *>((UIScreen *) ui_cast<UISystem *, UIContainer *>(GetRoot())->unk98) != NULL;
}
