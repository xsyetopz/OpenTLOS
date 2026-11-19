s32 MKProp::LoadLine(MKIniLine *arg0) {
    s32 var_r4_1383;

    if (arg0->LoadInt("ID", (int *) &this->unk14, 0) != 0) {
        if ((s32) this->unk14 != 0) {
            var_r4_1383 = arg0->GetString(1);
            if (var_r4_1383 == 0) {
                var_r4_1383 = *(s32 *) this->unk0;
            }
            MKSceneManager::PropResolver_Add(this, (const char *) var_r4_1383);
        }
        return 1;
    }
    if (arg0->LoadInt("zone", (int *) &this->unk18, 0) != 0) {
        if ((u32) this->unk18 == 0U) {
            this->unk18 = 1;
        }
        return 1;
    }
    if (arg0->IsField("collide") != 0) {
        if (arg0->GetBool(0) != 0) {
            this->unk10 &= 0xFFFFFFEF;
        } else {
            this->unk10 |= 0x10;
        }
        goto block_17;
    }
    if (arg0->LoadInt("groupMask", (int *) &this->unk18, 0) != 0) {
        return 1;
    }
block_17:
    ((MKPropLoadInfo *) &MKProp::loadInfo)->LoadLine(arg0);
    return 0;
}
