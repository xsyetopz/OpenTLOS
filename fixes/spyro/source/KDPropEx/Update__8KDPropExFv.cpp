void *KDPropEx::Update() {
    KDPropEx *sp8;
    KDPropExDescriptor *desc;
    KDProperty *var_r31;
    void *ret;

    sp8 = *(KDPropEx **) KDProperty::pInstanceMem;
    *(KDPropEx **) KDProperty::pInstanceMem = this;
    desc = checked_cast<KDPropExDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    var_r31 = (KDProperty *) desc->unk74.unk4;
    goto loop_2_cond;
loop_2:
    var_r31->Update();
    checked_cast<KDPropExDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    var_r31 = var_r31->unkC;
loop_2_cond:
    if (var_r31 != NULL) {
        goto loop_2;
    }
    ret = KDProp::Update();
    *(KDPropEx **) KDProperty::pInstanceMem = sp8;
    return ret;
}
