void PauseMenu_AutosaveScreen(const char *);

void Autosave_Abort() {
    *(KDMemoryCard **) MemoryCardScreen::selectedCard = autosaveCard;
    Autosave_Reset();
    autosave_state = 0;
    PauseMenu_AutosaveScreen("AutosaveCardRemoved");
}
