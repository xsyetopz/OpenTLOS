void MKHeap::GetMemoryStatistics(int *arg0, int *arg1, int *arg2) {
    *arg0 = this->unkC - (s32) this->unk0;
    *arg1 = this->unk4 - this->unk44;
    *arg2 = this->unk44 - this->unkC;
}
