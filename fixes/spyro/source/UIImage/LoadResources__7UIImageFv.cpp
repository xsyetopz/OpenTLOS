void UIImage::LoadResources() {
    s8 *temp_r3_259;

    if ((MKMaterial *) this->unk64 == NULL) {
        temp_r3_259 = this->unk60;
        if (temp_r3_259 != NULL) {
            this->unk64 = (MKMaterial *) MKMaterial_Create((const char *) temp_r3_259);
            MKMat_MK2_SetMaterialType(this->unk64, (MKMat_MK2_Standard_MaterialType) 3);
        }
    }
}
