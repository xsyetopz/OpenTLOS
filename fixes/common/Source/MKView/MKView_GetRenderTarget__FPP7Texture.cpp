Texture *MKView_GetRenderTarget(Texture **arg0) {
    if (arg0 != NULL) {
        *arg0 = M2C_FIELD(pStack + 1, Texture **, 0x3C);
    }
    return M2C_FIELD(pStack + 1, Texture **, 0x38);
}
