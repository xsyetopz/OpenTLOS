void NoController_Draw() {
    Tools_Ortho sp8;
    const char *msg;

    msg = (const char *) M2C_FIELD(gpTranslation_StringArray, s8 **, 0xFC);
    ErrorMessage_Draw(msg);
}
