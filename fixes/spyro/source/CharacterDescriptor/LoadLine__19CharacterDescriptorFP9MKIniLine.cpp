s32 CharacterDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_46;

    var_r31_46 = 0;
    if ((MKPropDescriptor::LoadLine(arg0) != 0) || (KDProp_LoadMaterialID(arg0, "materialID", (int *) &this->unk70) != 0) || (arg0->LoadInt("colItemType", (int *) &this->unk6C, 0) != 0) || (arg0->LoadFloat("charaColRadius", &this->unk60, 0) != 0) || (arg0->LoadFloat("charaColHeight", &this->unk64, 0) != 0) || (arg0->LoadFloat("charaColOffsetY", &this->unk68, 0) != 0) || (arg0->LoadBool("bFindGroundColour", (bool *) &this->unk74, 0) != 0) || (arg0->LoadBool("bStoreGroundColourResult", (bool *) ((u8 *) this + 0x75), 0) != 0) || (arg0->LoadString("overrideMaterial", (const char **) &this->unkDC, 0) != 0) || (arg0->LoadBool("bUseSteeringBehaviours", (bool *) ((u8 *) this + 0x77), 0) != 0) || (arg0->LoadBool("bPlayAnimSndsInCutscenes", (bool *) &this->unk78, 0) != 0) || (arg0->LoadBool("bUseQuickCollision", (bool *) ((u8 *) this + 0x76), 0) != 0)) {
        var_r31_46 = 1;
    }
    return var_r31_46;
}
