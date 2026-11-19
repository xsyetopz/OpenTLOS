void KDSP_Sounds::ParseDynamicSFX(KDSynkerHeap *arg0, MKIni *arg1) {
    MKIniLine *line;
    MKIniLine *cur;
    u8 *entry;
    u8 *start;
    s32 align;
    s32 count;

    line = this->unk4;
    if (line != NULL) {
        count = this->unk8;
        if (count != 0) {
            start = (u8 *) arg0->unk18;
            align = arg0->unk20 - 1;
            arg0->unk18 = start + ((count * 0x18 + align) & ~align);
            this->unkC = start;
            entry = (u8 *) this->unkC;
            cur = line->unkC->GetSubLine(line);
            while (cur != NULL) {
                M2C_FIELD(entry, s8 **, 8) = cur->GetFieldName();
                M2C_FIELD(entry, s32 *, 0xC) = -1;
                M2C_FIELD(entry, s32 *, 0x14) = 0;
                M2C_FIELD(entry, s32 *, 0) = cur->GetInt(0);
                M2C_FIELD(entry, s32 *, 4) = cur->GetInt(1);
                entry += 0x18;
                cur = cur->unkC->GetNextLine(cur);
            }
        }
    }
}
