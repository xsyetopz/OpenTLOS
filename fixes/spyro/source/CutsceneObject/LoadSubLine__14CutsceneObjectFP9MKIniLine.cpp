s32 CutsceneObject::LoadSubLine(MKIniLine *arg0) {
    MKIniLine *var_r31_275;
    s32 var_r31_344;
    s8 *var_r3_322;
    u32 temp_r3_312;

    if (arg0->IsField("camera") != 0) {
        var_r31_275 = arg0->unkC->GetSubLine(arg0);
        while (var_r31_275 != NULL) {
            if (var_r31_275->LoadVector3("cameraSource", &this->unk20, 0) == 0) {
                var_r31_275 = var_r31_275->unkC->GetNextLine(var_r31_275);
            } else {
                break;
            }
        }
        return 1;
    }
    if ((arg0->IsField("levelCode") != 0) && (arg0->GetString(0) != 0U)) {
        temp_r3_312 = strlen((const char *) arg0->GetString(0));
        if (temp_r3_312 != 0) {
            if (MKHeap::Current() != NULL) {
                var_r3_322 = (s8 *) (((MKHeap *) (MKHeap::Current()))->Alloc(temp_r3_312 + 1, NULL, 0));
            } else {
                var_r3_322 = malloc(temp_r3_312 + 1);
            }
            this->unk54 = var_r3_322;
            strcpy((char *) this->unk54, (const char *) arg0->GetString(0));
        }
        return 1;
    }
    var_r31_344 = 0;
    if ((arg0->LoadInt("disabledZone", (int *) &this->unk50, 0) != 0) || (arg0->LoadInt("cutscene1", (int *) &this->unk48, 0) != 0) || (arg0->LoadInt("altCutscene1", (int *) &this->unk4C, 0) != 0) || (arg0->LoadBool("bBlankScreenAfter", (bool *) &this->unk5C, 0) != 0) || (arg0->LoadBool("bBlankThroughLoadScreen", (bool *) &this->unk5D, 0) != 0) || (arg0->LoadBool("bSetHeroPos", (bool *) &this->unk5E, 0) != 0) || (arg0->LoadBool("bSetCameraPos", (bool *) &this->unk60, 0) != 0) || (arg0->LoadBool("bVideo", (bool *) &this->unk59, 0) != 0) || (arg0->LoadVector3("heroPos", (MKVector3 *) &this->unk10, 0) != 0) || (arg0->LoadFloat("heroLookYaw", &this->unk44, 0) != 0) || (arg0->LoadBool("bLeaveHeroVisible", (bool *) &this->unk5F, 0) != 0) || (arg0->LoadBool("bUseLoadingScreen", (bool *) &this->unk62, 0) != 0) || (arg0->LoadBool("bZoomVideo", (bool *) &this->unk63, 0) != 0) || (this->unk30.LoadLine(arg0, "onCompletion") != 0) || (this->unk34.LoadLine(arg0, "onActivation") != 0) || (this->unk38.LoadLine(arg0, "onPlay") != 0) || (this->unk3C.LoadLine(arg0, "onStop") != 0) || (this->unk40.LoadLine(arg0, "skipQuery") != 0) || (arg0->LoadVector4("BlankColour", (MKVector4 *) this, 0) != 0)) {
        var_r31_344 = 1;
    }
    return var_r31_344;
}
