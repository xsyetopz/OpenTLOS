s32 PolyRegion::LoadLine(char *arg0, MKIniLine *arg1) {
    MKIniLine *var_r27_42;
    MKVector3 *var_r3_31;
    f32 temp_f1_58;
    f32 temp_f1_66;
    s32 temp_r28_23;
    s32 var_r29_44;

    if (arg1->IsField(arg0) != 0) {
        temp_r28_23 = arg1->GetNmbrOfSubLines() * 0x10;
        if (MKHeap::Current() != NULL) {
            var_r3_31 = (MKVector3 *) (((MKHeap *) (MKHeap::Current()))->Alloc(temp_r28_23, NULL, 0));
        } else {
            var_r3_31 = malloc(temp_r28_23);
        }
        this->unk0 = var_r3_31;
        var_r27_42 = arg1->unkC->GetSubLine(arg1);
        var_r29_44 = 0;
        while (var_r27_42 != NULL) {
            if (var_r27_42->LoadVector3("waypoint", (MKVector3 *) ((u8 *) this->unk0 + var_r29_44), 0) != 0) {
                temp_f1_58 = *(f32 *) ((u8 *) this->unk0 + (var_r29_44 + 4));
                if (temp_f1_58 < this->unk4.unk1C) {
                    this->unk4.unk1C = temp_f1_58;
                }
                temp_f1_66 = *(f32 *) ((u8 *) this->unk0 + (var_r29_44 + 4));
                if (temp_f1_66 > this->unk24) {
                    this->unk24 = temp_f1_66;
                }
                var_r29_44 += 0x10;
            }
            var_r27_42 = var_r27_42->unkC->GetNextLine(var_r27_42);
        }
        ((BoundingRegion *) &this->unk4)->Init(this->unk0, arg1->GetNmbrOfSubLines());
        this->unk30 = M2C_FIELD(this, f32 *, 0x10);
        this->unk34 = this->unk4.unk1C;
        this->unk38 = this->unk4.unk14;
        this->unk40 = this->unk4.unk10;
        this->unk44 = this->unk24;
        this->unk48 = this->unk4.unk18;
        this->unk40 = this->unk40 - this->unk30;
        this->unk44 = this->unk44 - this->unk34;
        this->unk48 = this->unk48 - this->unk38;
        return 1;
    }
    return 0;
}
