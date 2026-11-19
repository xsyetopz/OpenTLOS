void KDSP_Camera::ParseMCDFile(const char *arg0) {
    unsigned int *var_r31_101;

    this->unk94 = (unsigned long *) (MKArchive_Load(arg0, (int *) &this->unk90, NULL, -1));
    this->unk98 = NULL;
    var_r31_101 = (unsigned int *) this->unk94;
loop_5:
    if ((u8 *) var_r31_101 < (u8 *) this->unk94 + this->unk90) {
        if ((u32) (Endian<unsigned int>(*var_r31_101) + 0xBBB30000) == 0x4143U) {
            this->unk98 = (u32 *) ((u8 *) var_r31_101 + 0xC);
        } else {
            Endian<unsigned int>(*var_r31_101);
        }
        var_r31_101 = (unsigned int *) ((u8 *) var_r31_101 + Endian<unsigned int>(*(unsigned int *) ((u8 *) var_r31_101 + 4)) + 8);
        goto loop_5;
    }
}
