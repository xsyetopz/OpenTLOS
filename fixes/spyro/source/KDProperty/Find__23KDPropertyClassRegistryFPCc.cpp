extern "C" s32 stricmp(const char *, const char *);
KDPropertyClassInfo *KDPropertyClassRegistry::Find(const char *arg0) {
    KDPropertyClassInfo *var_r31_409;

    if (arg0 == NULL) {
        return NULL;
    }
    var_r31_409 = this->unk0;
    goto loop_6_cond;
loop_6:
    if (stricmp((const char *) var_r31_409->unk0, arg0) == 0) {
        return var_r31_409;
    }
    var_r31_409 = var_r31_409->unkC;
loop_6_cond:
    if (var_r31_409 != NULL) {
        goto loop_6;
    }
    return NULL;
}
