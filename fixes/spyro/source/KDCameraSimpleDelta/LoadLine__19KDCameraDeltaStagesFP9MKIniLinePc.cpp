extern "C" s32 stricmp(s8 *, s8 *);

s32 KDCameraDeltaStages::LoadLine(MKIniLine *arg0, char *arg1) {
    s8 *sp8;

    if ((s8) init_515 == 0) {
        pCurrentLoadingStage_514 = NULL;
        init_515 = 1;
    }
    if ((KDCameraDeltaStages *) pCurrentLoadingStage_514 == this) {
        if ((arg0->LoadFloat("pitch", &this->unk0, 0) != 0) || (arg0->LoadFloat("delta", &this->unk4, 0) != 0) || (arg0->LoadFloat("offset", &this->unk8, 0) != 0)) {
            return 1;
        }
        pCurrentLoadingStage_514 = NULL;
        goto block_8;
    }
block_8:
    if (stricmp(arg0->GetFieldName(), (s8 *) "deltaStageType") == 0) {
        sp8 = NULL;
        if ((arg0->AsString(0, (const char **) &sp8) != 0) && (stricmp(sp8, (s8 *) arg1) == 0)) {
            pCurrentLoadingStage_514 = this;
            return 1;
        }
    }
    return 0;
}
