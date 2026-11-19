void *LavaDerickDescriptor::CalcBounds() {
    MKVector3 sp8;
    BoundingVolume *bv;
    f32 var_f0;

    MKModel_CalculateRefPointWorldPosition(this->unk2C, (s32) Tools_GetMatchingRefPointIndex(this->unk2C, "hurtsphere1"), &sp8);
    bv = this->unk1C;
    var_f0 = sp8.unk0;
    if (var_f0 < bv->unk0) {
    } else {
        var_f0 = bv->unk0;
    }
    bv->unk0 = var_f0;
    var_f0 = sp8.unk4;
    if (var_f0 < bv->unk4) {
    } else {
        var_f0 = bv->unk4;
    }
    bv->unk4 = var_f0;
    var_f0 = sp8.unk8;
    if (var_f0 < bv->unk8) {
    } else {
        var_f0 = bv->unk8;
    }
    bv->unk8 = var_f0;
    var_f0 = sp8.unk0 - bv->unk0;
    if (var_f0 > bv->unk10) {
    } else {
        var_f0 = bv->unk10;
    }
    bv->unk10 = var_f0;
    var_f0 = sp8.unk4 - bv->unk4;
    if (var_f0 > bv->unk14) {
    } else {
        var_f0 = bv->unk14;
    }
    bv->unk14 = var_f0;
    var_f0 = sp8.unk8 - bv->unk8;
    if (var_f0 > bv->unk18) {
    } else {
        var_f0 = bv->unk18;
    }
    bv->unk18 = var_f0;
    bv->unk10 = bv->unk10 - bv->unk0;
    bv->unk14 = bv->unk14 - bv->unk4;
    bv->unk18 -= bv->unk8;
    return &bv->unk10;
}
