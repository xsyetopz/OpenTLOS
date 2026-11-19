extern "C" s32 strcmpi(s8 *, s8 *);
UIObject *UIContainer::FindChild(const char *arg0) {
    UIObject *var_r31_259;

    for (var_r31_259 = this->unk60; var_r31_259 != NULL; var_r31_259 = var_r31_259->unk10) {
        if (((u32) var_r31_259->unk4 != 0) && (strcmpi((s8 *) arg0, (s8 *) var_r31_259->unk4) == 0)) {
            return var_r31_259;
        }
    }
    return NULL;
}
