void KDPropEx::Deinit() {
    KDPropEx *sp8;
    KDPropExDescriptor *desc;
    KDProperty *var_r31;

    sp8 = *(KDPropEx **) KDProperty::pInstanceMem;
    *(KDPropEx **) KDProperty::pInstanceMem = this;
    desc = checked_cast<KDPropExDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    var_r31 = desc->unk74.unk0;
    goto loop_2_cond;
loop_2:
    var_r31->DeinitInstance();
    checked_cast<KDPropExDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    var_r31 = var_r31->unkC;
loop_2_cond:
    if (var_r31 != NULL) {
        goto loop_2;
    }
    *(KDPropEx **) KDProperty::pInstanceMem = sp8;
    KDProp::Deinit();
}
