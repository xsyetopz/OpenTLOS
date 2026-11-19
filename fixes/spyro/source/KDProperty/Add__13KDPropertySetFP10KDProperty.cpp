void KDPropertySet::Add(KDProperty *arg0) {
    KDProperty *temp_r3_717;
    KDPropertySet *var_r4_712;

    if (arg0->Query(1) != 0) {
        var_r4_712 = this;
        goto loop_3_cond;
loop_3:
        var_r4_712 = (KDPropertySet *) &temp_r3_717->unkC;
loop_3_cond:
        temp_r3_717 = var_r4_712->unk0;
        if (temp_r3_717 != (KDProperty *) this->unk4) {
            goto loop_3;
        }
        var_r4_712->unk0 = arg0;
        arg0->unkC = (KDProperty *) this->unk4;
        this->unk4 = (KDPropertyCommand *) arg0;
        return;
    }
    arg0->unkC = this->unk0;
    this->unk0 = arg0;
}
