void KDClothDescriptor::Resolve(MKModel *arg0) {
    s8 *temp_r5_278;

    temp_r5_278 = this->unk14;
    if (temp_r5_278 != NULL) {
        this->unk18 = MKModel_GetSubObjectIndex(arg0, (SubObjectType) 2, (const char *) temp_r5_278);
    }
}
