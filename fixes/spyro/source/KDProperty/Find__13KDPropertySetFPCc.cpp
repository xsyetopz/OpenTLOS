extern "C" s32 stricmp(const char *, const char *);
KDPropertyCommand *KDPropertySet::Find(const char *arg0) {
    KDProperty *var_r30_460;
    KDPropertyCommand *var_r30_482;
    const char *name;

    var_r30_460 = this->unk0;
    goto loop_7_cond;
loop_7:
    name = (const char *) var_r30_460->unk4;
    if (name == NULL) {
        name = "";
    }
    if (stricmp(name, arg0) == 0) {
        return (KDPropertyCommand *) var_r30_460;
    }
    var_r30_460 = var_r30_460->unkC;
loop_7_cond:
    if (var_r30_460 != NULL) {
        goto loop_7;
    }
    var_r30_482 = this->unk8;
    goto loop_15_cond;
loop_15:
    name = (const char *) var_r30_482->unk4;
    if (name == NULL) {
        name = "";
    }
    if (stricmp(name, arg0) == 0) {
        return var_r30_482;
    }
    var_r30_482 = var_r30_482->unkC;
loop_15_cond:
    if (var_r30_482 != NULL) {
        goto loop_15;
    }
    return NULL;
}
