s32 ConsoleProp::LoadLine(MKIniLine *arg0) {
    MKIniLine *macro;
    MKIniLine *sub;
    void *mem;
    s32 off;

    if (MKProp::LoadLine(arg0) != 0) {
        return 1;
    }
    if (arg0->IsField("Macros") != 0) {
        this->unk50 = arg0->GetNmbrOfSubLines();
        if (this->unk50 != 0) {
            if (MKHeap::Current() != NULL) {
                mem = ((MKHeap *) (MKHeap::Current()))->Alloc(this->unk50 * 0x24, NULL, 0);
            } else {
                mem = malloc(this->unk50 * 0x24);
            }
            this->unk4C = mem;
            memset(this->unk4C, 0, this->unk50 * 0x24);
            sub = arg0->unkC->GetSubLine(arg0);
            off = 0;
            while (sub != NULL) {
                if (sub->IsField("Macro") != 0) {
                    macro = sub->unkC->GetSubLine(sub);
                    // The shipped loop never advances `macro` (asm 0x8022E938-0x8022E9A4
                    // branches back without GetNextLine): a Macro with sub-lines hangs.
                    while (macro != NULL) {
                        if (macro->IsField("MacroName") != 0) {
                            strcpy((char *) ((u8 *) this->unk4C + off), (const char *) macro->GetString(0));
                        } else if (macro->IsField("ScriptCommand") != 0) {
                            *(const char **) ((u8 *) this->unk4C + off + 0x20) = (const char *) macro->GetString(0);
                        }
                    }
                }
                off += 0x24;
                sub = sub->unkC->GetNextLine(sub);
            }
        }
        return 1;
    }
    return 0;
}
