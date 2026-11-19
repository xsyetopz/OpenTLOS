void GlowingPropManager::Draw() {
    MKProp ***var_r31_91;

    var_r31_91 = this->unk0;
    while (var_r31_91 != NULL && *var_r31_91 != NULL && **var_r31_91 != NULL) {
        (**var_r31_91)->Draw();
        var_r31_91 = (MKProp ***) ((u8 *) var_r31_91 + 4);
    }
    for (; *this->unk0 != NULL; this->unk0 = (MKProp ***) ((u8 *) this->unk0 + 4)) {
    }
}
