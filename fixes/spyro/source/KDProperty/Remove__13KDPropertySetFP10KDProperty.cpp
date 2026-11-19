void KDPropertySet::Remove(KDProperty *arg0) {
    KDProperty *temp_r5_679;
    KDPropertySet *var_r3_0;

    var_r3_0 = this;
    if (var_r3_0->unk4 == (KDPropertyCommand *) arg0) {
        var_r3_0->unk4 = (KDPropertyCommand *) arg0->unkC;
    }
    goto loop_5_cond;
loop_5:
    if (temp_r5_679 == arg0) {
        var_r3_0->unk0 = arg0->unkC;
        arg0->unkC = NULL;
        return;
    }
    var_r3_0 = (KDPropertySet *) &temp_r5_679->unkC;
loop_5_cond:
    temp_r5_679 = var_r3_0->unk0;
    if (temp_r5_679 != NULL) {
        goto loop_5;
    }
}
