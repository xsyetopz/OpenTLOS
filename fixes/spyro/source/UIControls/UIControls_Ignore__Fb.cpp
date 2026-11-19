void UIControls_Ignore(bool arg0) {
    M2C_FIELD(&allControllers, u8 *, 0x1D) = arg0;
}
