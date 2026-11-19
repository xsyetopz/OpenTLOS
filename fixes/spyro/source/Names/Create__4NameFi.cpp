static Names firstNames[6];
static Names lastNames[6];

void Name::Create(int arg0) {
    if (arg0 == -1) {
        this->unk4 = NULL;
        this->unk0 = NULL;
        return;
    }
    this->unk0 = firstNames[arg0].GetRandom();
    this->unk4 = lastNames[arg0].GetRandom();
}
