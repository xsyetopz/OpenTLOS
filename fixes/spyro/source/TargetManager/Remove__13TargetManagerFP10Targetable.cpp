void TargetManager::Remove(Targetable *arg0) {
    TargetManager ***temp_r3_700;
    TargetManager ***var_r4_684;

    if ((arg0 != NULL) && (this->unk8.Get() == arg0)) {
        this->unk8.Set((Targetable *) NULL);
    }
    var_r4_684 = this->unk0;
    while (*var_r4_684 != NULL) {
        if (*var_r4_684 == (TargetManager **) arg0) {
            break;
        }
        var_r4_684 += 1;
    }
    if (*var_r4_684 == NULL) {
        var_r4_684 = NULL;
    }
    if (var_r4_684 != NULL) {
        temp_r3_700 = this->unk0;
        this->unk0 = temp_r3_700 + 1;
        *var_r4_684 = *temp_r3_700;
    }
}
