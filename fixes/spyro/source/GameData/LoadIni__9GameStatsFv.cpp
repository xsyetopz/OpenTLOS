void GameStats::LoadIni() {
    MKIni ini;
    MKIniLine *sec;
    MKIniLine *sub;
    MKIniLine *leaf;
    MKIniLine *upg;
    u8 *ce;
    u8 *secNames;
    u8 *fldNames;
    u8 *secDst;
    u8 *secBank;
    u8 *upgDst;
    f32 *valDst;
    s32 i;
    s32 secSlot;
    s32 secBankOff;
    s32 secDstOff;
    s32 j;
    s32 fldSlot;
    s32 fldBankOff;
    s32 valOff;
    s32 k;

    ce = (u8 *) &coverEffects;
    secNames = ce + 0x288;
    fldNames = ce + 0x270;
    if (ini.Init("GameStats.ini", 0, NULL) != 0) {
        sec = ini.GetFirstLine();
        while (sec != NULL) {
            i = 0;
            secSlot = 0;
            secBankOff = 0;
            secDstOff = 0;
            do {
                if (sec->IsSection(*(const char **) (secNames + secSlot)) != 0) {
                    sub = sec->unkC->GetSubLine(sec);
                    secDst = ce + 0x1B0 + secDstOff;
                    secBank = ce + 0x1F0 + secBankOff;
                    while (sub != NULL) {
                        j = 0;
                        fldSlot = 0;
                        fldBankOff = 0;
                        valOff = 0;
                        do {
                            if (sub->IsField(*(const char **) (fldNames + fldSlot)) != 0) {
                                leaf = sub->unkC->GetSubLine(sub);
                                valDst = (f32 *) (secDst + valOff);
                                upgDst = secBank + fldBankOff;
                                while (leaf != NULL) {
                                    if (leaf->IsField("Upgrades") != 0) {
                                        upg = leaf->unkC->GetSubLine(leaf);
                                        k = 0;
                                        while (upg != NULL) {
                                            if (upg->LoadFloat("Damage", (f32 *) (upgDst + k), 0) != 0) {
                                                k += 4;
                                            }
                                            upg = upg->unkC->GetNextLine(upg);
                                        }
                                    }
                                    leaf->LoadFloat("InitialCost", valDst, 0);
                                    leaf->LoadFloat("OngoingCost", (f32 *) ((u8 *) valDst + 4), 0);
                                    leaf = leaf->unkC->GetNextLine(leaf);
                                }
                            }
                            j += 1;
                            fldBankOff += 0x10;
                            fldSlot += 4;
                            valOff += 8;
                        } while (j < 2);
                        sub = sub->unkC->GetNextLine(sub);
                    }
                }
                i += 1;
                secBankOff += 0x20;
                secSlot += 4;
                secDstOff += 0x10;
            } while (i < 4);
            sec = sec->unkC->GetNextLine(sec);
        }
        ini.Deinit();
    }
}
