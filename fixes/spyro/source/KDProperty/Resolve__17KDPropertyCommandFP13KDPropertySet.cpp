void KDPropertyCommand::Resolve(KDPropertySet *arg0) {
    KDPropertyCommand *temp_r0_327;
    KDPropertyCommand *temp_r3_335;

    temp_r0_327 = this->unk0;
    if (temp_r0_327 != NULL) {
        this->unk0 = arg0->Find((const char *) temp_r0_327);
    }
    temp_r3_335 = this->unk0;
    if ((temp_r3_335 != NULL) && ((u32) this->unk4 != 0U)) {
        this->unk4 = ((KDProperty *) temp_r3_335)->ResolveCommand((const char *) this->unk4);
    }
}
