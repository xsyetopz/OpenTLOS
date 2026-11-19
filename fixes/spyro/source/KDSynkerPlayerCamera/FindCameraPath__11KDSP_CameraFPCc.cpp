extern "C" int stricmp(const char *, const char *);

void *KDSP_Camera::FindCameraPath(const char *arg0) {
    s32 var_r30_17;
    s32 var_r31_18;

    for (var_r30_17 = 0, var_r31_18 = 0; var_r30_17 < (s32) this->unk74; var_r30_17 += 1, var_r31_18 += 0x40) {
        if (stricmp(*(const char **) ((u8 *) this->unk78 + var_r31_18), arg0) == 0) {
            return (u8 *) this->unk78 + var_r31_18;
        }
    }
    return NULL;
}
