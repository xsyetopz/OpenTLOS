void KDSP_ActorList::Parse(KDSynkerHeap *arg0, MKIni *arg1, int &arg2, KDInput *arg3) {
    MKIniLine *line;
    MKIniLine *sub;
    void *buf;
    s32 off;
    s32 align;

    KDSP_Actor::SetInput(arg3);
    line = this->unkC;
    if (line != NULL && this->unk0 != 0) {
        align = arg0->unk14 - 1;
        buf = arg0->unkC;
        arg0->unkC = (u8 *) buf + (((this->unk0 * 0x138) + align) & ~align);
        this->unk4 = (s32) buf;
        memset((void *) this->unk4, 0, this->unk0 * 0x138);
        off = this->unk4;
        sub = line->unkC->GetSubLine(line);
        sub = sub->unkC->GetNextLine(sub);
        while (sub != NULL) {
            ((KDSP_Actor *) off)->Init();
            ((KDSP_Actor *) off)->LoadActorDataSection(arg0, sub);
            off += 0x138;
            sub = sub->unkC->GetNextLine(sub);
        }
    }
    line = this->unk10;
    if (line != NULL && this->unk0 != 0) {
        sub = line->unkC->GetSubLine(line);
        while (sub != NULL) {
            FindActor((const char *) sub->GetFieldName())->LoadActorSection(arg0, sub, arg2);
            sub = sub->unkC->GetNextLine(sub);
        }
    }
}
