void PauseMenu_AutosaveScreen(const char *);

void Autosave_Error() {
    *(KDMemoryCard **) MemoryCardScreen::selectedCard = autosaveCard;
    Autosave_Reset();
    autosave_state = 0;
    PauseMenu_AutosaveScreen("AutosaveError");
}
