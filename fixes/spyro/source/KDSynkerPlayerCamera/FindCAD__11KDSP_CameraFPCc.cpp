extern "C" int strcmpi(const char *, const char *);

void *KDSP_Camera::FindCAD(const char *arg0) {
    s32 var_r30_55;
    s32 var_r31_56;

    for (var_r30_55 = 0, var_r31_56 = 0; var_r30_55 < (s32) this->unk7C; var_r30_55 += 1, var_r31_56 += 0xC) {
        if (strcmpi(*(const char **) ((u8 *) this->unk84 + var_r31_56 + 8), arg0) == 0) {
            return (u8 *) this->unk84 + var_r31_56;
        }
    }
    return NULL;
}
