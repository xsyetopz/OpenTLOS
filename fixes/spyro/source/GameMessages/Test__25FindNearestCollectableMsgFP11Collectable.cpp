void FindNearestCollectableMsg::Test(Collectable *arg0) {
    f32 sp8[3];
    f32 temp_f1_599;
    f32 temp_f3_595;
    f32 temp_f4_591;
    f32 temp_f5_589;
    s32 temp_r5_576;

    if ((arg0 != NULL) && (this->unk18 & (1 << arg0->GetItemType())) && ((s32) arg0->unkD4 == 6)) {
        temp_r5_576 = this->unk1C;
        this->unk1C = temp_r5_576 + 1;
        /* The asm loads the vptr from offset 0x44, then slot 0x44 writes the position as three f32 at sp8. */
        M2C_FIELD(M2C_FIELD(arg0, void ***, 0x44), M2C_UNK (**)(f32 *, Collectable *, s32), 0x44)(sp8, arg0, temp_r5_576);
        temp_f5_589 = sp8[1] - this->unkC;
        temp_f4_591 = sp8[0] - this->unk8;
        temp_f3_595 = sp8[2] - this->unk10;
        temp_f1_599 = (temp_f3_595 * temp_f3_595) + ((temp_f4_591 * temp_f4_591) + (temp_f5_589 * temp_f5_589));
        if (temp_f1_599 < this->unk20) {
            this->unk24 = arg0;
            this->unk20 = temp_f1_599;
        }
    }
}
