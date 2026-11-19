void UIModel::LoadResources() {
    s32 index;
    const char *subName;
    s8 *modelName;

    if ((MKModel *) this->unk64 == NULL) {
        modelName = this->unk60;
        if (modelName != NULL) {
            this->unk64 = MKModel_Create((const char *) modelName, NULL, 2, NULL);
            if ((MKModel *) this->unk64 != NULL) {
                /* Enable every sub-object whose name starts with F_, C_ or L_. */
                for (index = 0; index < MKModel_GetNmbrOfSubObjects(this->unk64, (SubObjectType) 0); index += 1) {
                    subName = (const char *) MKModel_GetSubObjectName(this->unk64, (SubObjectType) 0, index);
                    if ((strnicmp(subName, "F_", 2) == 0) || (strnicmp(subName, "C_", 2) == 0) || (strnicmp(subName, "L_", 2) == 0)) {
                        MKModel_EnableSubObject(this->unk64, (SubObjectType) 0, index, 0, 1U);
                    }
                }
            }
        }
    }
}
