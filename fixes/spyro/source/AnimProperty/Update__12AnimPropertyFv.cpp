void AnimProperty::Update() {
    KDProp *prop;
    MKAnimScript *anim;
    f32 temp_f0;
    f32 var_f1;
    s32 flags;
    s32 temp_r3;
    s32 temp_r5;
    s32 var_ctr;
    s32 var_r29;
    s32 var_r30;
    s32 var_r3;
    s32 var_r6;

    if ((u8) *(*(u8 **) KDProperty::pInstanceMem + this->unk8) == 0) {
        return;
    }
    prop = checked_cast<KDProp *, MKProp>(*(MKProp **) KDProperty::pInstanceMem);
    flags = M2C_FIELD(M2C_FIELD(prop, void **, 0x80), s32 *, 0x2C);
    if ((flags & 1) == 0) {
        prop = checked_cast<KDProp *, MKProp>(*(MKProp **) KDProperty::pInstanceMem);
        flags = M2C_FIELD(M2C_FIELD(prop, void **, 0x80), s32 *, 0x2C);
        if ((flags & 2) == 0) {
            return;
        }
    }
    var_r30 = 0;
    var_r29 = 0;
    if ((s32) this->unk18 > 1) {
loop_4:
        var_f1 = MKRand_Float((int *) &gViewSeed, 0.0f, this->unk20);
        temp_r5 = this->unk18;
        var_r6 = 0;
        var_r3 = 0;
        var_ctr = temp_r5;
        if (temp_r5 > 0) {
loop_5:
            temp_f0 = *(f32 *) ((s8 *) this->unk14 + (var_r3 + 4));
            if (var_f1 <= temp_f0) {
                var_r30 = var_r6;
            } else {
                var_f1 -= temp_f0;
                var_r6 += 1;
                var_r3 += 8;
                var_ctr -= 1;
                if (var_ctr != 0) {
                    goto loop_5;
                }
            }
        }
        var_r29 += 1;
        if (var_r29 < temp_r5) {
            temp_r3 = *(s32 *) (*(u8 **) KDProperty::pInstanceMem + (this->unk8 + 4));
            if ((var_r30 == temp_r3) && ((s32) this->unk1C != temp_r3)) {
                goto loop_4;
            }
        }
    }
    *(s32 *) (*(u8 **) KDProperty::pInstanceMem + (this->unk8 + 4)) = var_r30;
    prop = checked_cast<KDProp *, MKProp>(*(MKProp **) KDProperty::pInstanceMem);
    anim = M2C_FIELD(prop, MKAnimScript **, 0x80);
    anim->SetAnim(*(MKAnim **) ((s8 *) this->unk14 + var_r30 * 8), 1.0f, 0.0f, 0, -1);
}
