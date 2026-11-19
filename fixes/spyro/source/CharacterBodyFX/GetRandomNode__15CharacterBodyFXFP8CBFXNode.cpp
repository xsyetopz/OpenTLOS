void *CharacterBodyFX::GetRandomNode(CBFXNode *arg0) {
    s32 idx;
    s32 node;
    s32 r;

    if (this->unk8 == NULL) {
        return NULL;
    }
    r = MKRand_Int((int *) &gViewSeed, 0, this->unk8->unk4 - 1);
    node = r;
    if ((u8 *) this->unk4 + r * 0x70 == (u8 *) arg0 && r > 0) {
        node = r - 1;
    }
    idx = node * 0x70;
    if (((u8 *) this->unk4)[idx + 0x60] == 0 || this->unk10 == 0) {
        this->CalculateNodeData(node);
    }
    return (void *) ((u8 *) this->unk4 + idx);
}
