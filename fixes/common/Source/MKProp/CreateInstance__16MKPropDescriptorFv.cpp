MKProp *MKPropDescriptor::CreateInstance() {
    MKProp *var_r31_18;

    var_r31_18 = (MKProp *) this->unk28;
    while (var_r31_18 != NULL) {
        if (var_r31_18->unk18 & 0x80000000) {
            var_r31_18->Enable();
            return var_r31_18;
        }
        var_r31_18 = var_r31_18->unk38;
    }
    return NULL;
}
