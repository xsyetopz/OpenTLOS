s32 KDPropEx::LoadLine(MKIniLine *arg0) {
    KDPropEx *spC;
    bool sp8;
    KDPropExDescriptor *desc;
    KDProperty *var_r31;

    spC = *(KDPropEx **) KDProperty::pInstanceMem;
    *(KDPropEx **) KDProperty::pInstanceMem = this;
    desc = checked_cast<KDPropExDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    var_r31 = desc->unk74.unk0;
    goto loop_2_cond;
loop_2:
    var_r31->LoadLineInstance(arg0);
    checked_cast<KDPropExDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    var_r31 = var_r31->unkC;
loop_2_cond:
    if (var_r31 != NULL) {
        goto loop_2;
    }
    if (KDProp::LoadLine(arg0) != 0) {
        *(KDPropEx **) KDProperty::pInstanceMem = spC;
        return 1;
    }
    if ((arg0->LoadBool("Collide", &sp8, 0) != 0) && (sp8 == 0)) {
        *(u8 *) ((u8 *) this + 0x74) = 0;
    }
    *(KDPropEx **) KDProperty::pInstanceMem = spC;
    return 0;
}
