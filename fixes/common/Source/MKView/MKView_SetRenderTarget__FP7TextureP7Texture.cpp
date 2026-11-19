void MKView_SetRenderTarget(Texture *arg0, Texture *arg1) {
    M2C_FIELD(pStack + 1, Texture **, 0x38) = arg0;
    M2C_FIELD(pStack + 1, Texture **, 0x3C) = arg1;
    MKView_SettingsCounter += 1;
}
