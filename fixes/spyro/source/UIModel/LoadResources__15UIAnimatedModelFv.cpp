void UIAnimatedModel::LoadResources() {
    s8 *animName;

    if ((MKModel *) this->unk64 == NULL) {
        this->unk68.Init((const char *) this->unk60, (MKModel *) NULL);
        animName = this->unk68.GetAnimName();
        this->unk64 = MKModel_Create((const char *) this->unk68.GetMeshName(), (const char *) animName, 2, NULL);
        this->unk68.unk8 = this->unk64;
        this->unk68.CalculateSubObjectIndices();
        this->unk68.SetAnimation(MKModel_GetAnimation(this->unk64));
        this->unk68.SetAnim((MKAnim *) this->unk68.GetAnim(0), 1.0f, 0.0f, 0, -1);
    }
}
