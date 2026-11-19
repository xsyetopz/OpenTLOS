void KDSP_ActorList::Load(MKIni *arg0, int &arg1, bool arg2, bool arg3) {
    s32 i;
    s32 off;
    MKIniLine *line;

    off = 0;
    for (i = 0; i < this->unk0; i++) {
        ((KDSP_Actor *) (this->unk4 + off))->Resolve(arg2, M2C_FIELD(this, void (**)(const char *, MKModel **, MKAnimScript **), 0x8), arg3);
        off += 0x138;
    }
    line = this->unk10;
    if (line != NULL && this->unk0 != 0) {
        line = line->unkC->GetSubLine(line);
        while (line != NULL) {
            FindActor((const char *) line->GetFieldName())->LoadActorSectionPostResolve(line, arg2, arg1);
            line = line->unkC->GetNextLine(line);
        }
    }
    off = 0;
    for (i = 0; i < this->unk0; i++) {
        ((KDSP_Actor *) (this->unk4 + off))->HideSpecialSubObjects();
        off += 0x138;
    }
}
