s32 AnimProperty::LoadLine(MKIniLine *arg0) {
    MKIniLine *line;
    s32 size;
    s32 off;
    void *mem;

    if (arg0->IsField("AnimNames") != 0) {
        line = arg0->unkC->GetSubLine(arg0);
        this->unk18 = arg0->GetNmbrOfSubLines();
        size = this->unk18 * 8;
        if (MKHeap::Current() != NULL) {
            mem = MKHeap::Current()->Alloc(size, NULL, 0);
        } else {
            mem = malloc(size);
        }
        this->unk14 = mem;
        off = 0;
        while (line != NULL) {
            *(s8 **) ((s8 *) this->unk14 + off) = line->GetFieldName();
            *(f32 *) ((s8 *) this->unk14 + off + 4) = line->GetFloat(0);
            off += 8;
            line = line->unkC->GetNextLine(line);
        }
    }
    return 0;
}
