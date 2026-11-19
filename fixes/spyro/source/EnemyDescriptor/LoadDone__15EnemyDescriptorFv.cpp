void EnemyDescriptor::LoadDone() {
    MKVector3 sp10;
    f32 sp8;
    CharacterBreathFXDescriptor *var_r3_2371;
    MKAnim *temp_r5_2119;
    f32 temp_f1_2132;
    f32 temp_f2_2131;
    f32 temp_f3_2133;
    f32 var_f4_2138;
    f64 temp_f1_2141;
    f64 temp_f1_2147;
    f64 temp_f1_2151;
    s32 temp_r3_2170;
    s32 var_r0_2180;
    s32 var_r20_2115;
    s32 var_r21_2110;
    s32 var_r22_2106;
    s32 var_r23_2102;
    s32 var_r25_2114;
    s32 var_r27_2109;
    s32 var_r28_2105;
    s32 var_r29_2101;
    void *temp_r26_2116;
    void *temp_r30_2118;
    void *temp_r3_2223;

    CharacterDescriptor::LoadDone();
    this->unkF4 = DataMap_GetValue(&enemyTypeDataMap, (const char *) this->unk0);
    this->unk7C.unk0 = this->unk60;
    this->unk7C.unk4 = this->unk7C.unk0;
    LoadDescriptorData();
    if ((u8) this->unk1D6 != 0) {
        EnemySettings_RegisterSettings((const char *) this->unk278, &this->unk1D8);
    }
    var_r29_2101 = 0;
    var_r23_2102 = 0;
loop_30:
    if (var_r29_2101 < (s32) this->unk200) {
        var_r28_2105 = 0;
        var_r22_2106 = 0;
        do {
            var_r27_2109 = 0;
            var_r21_2110 = 0;
loop_27:
            temp_r3_2223 = (u8 *) this->unk1FC + var_r23_2102 + var_r22_2106;
            if (var_r27_2109 < (s32) M2C_FIELD(temp_r3_2223, s32 *, 4)) {
                var_r25_2114 = 0;
                var_r20_2115 = 0;
                temp_r26_2116 = (void *) (M2C_FIELD(temp_r3_2223, s32 *, 0) + var_r21_2110);
                do {
                    temp_r30_2118 = ((u8 *) temp_r26_2116) + var_r20_2115;
                    temp_r5_2119 = M2C_FIELD(temp_r30_2118, MKAnim **, 0);
                    if (temp_r5_2119 != NULL) {
                        sp10 = SumAnimTranslation((MKAnimScript *) this->unk34, temp_r5_2119, M2C_FIELD(temp_r26_2116, f32 *, 0x64));
                        M2C_FIELD(temp_r30_2118, MKVector3 *, 8) = sp10;
                        temp_f2_2131 = (f32) M2C_FIELD(temp_r30_2118, f64 *, 8);
                        temp_f1_2132 = M2C_FIELD(temp_r30_2118, f32 *, 0xC);
                        temp_f3_2133 = (f32) M2C_FIELD(temp_r30_2118, f64 *, 0x10);
                        var_f4_2138 = (temp_f3_2133 * temp_f3_2133) + ((temp_f2_2131 * temp_f2_2131) + (temp_f1_2132 * temp_f1_2132));
                        if (var_f4_2138 > 0.0f) {
                            temp_f1_2141 = __frsqrte(var_f4_2138);
                            temp_f1_2147 = 0.5 * temp_f1_2141 * -(((f64) var_f4_2138 * (temp_f1_2141 * temp_f1_2141)) - 3.0);
                            temp_f1_2151 = 0.5 * temp_f1_2147 * -(((f64) var_f4_2138 * (temp_f1_2147 * temp_f1_2147)) - 3.0);
                            var_f4_2138 = (f32) ((f64) var_f4_2138 * (0.5 * temp_f1_2151 * -(((f64) var_f4_2138 * (temp_f1_2151 * temp_f1_2151)) - 3.0)));
                        } else if (var_f4_2138 < M2C_BITWISE(f32, 0.0)) {
                            var_f4_2138 = __float_nan;
                        } else {
                            sp8 = var_f4_2138;
                            temp_r3_2170 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                            switch (temp_r3_2170) { /* irregular */
                            case 0x7F800000:
                                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                    var_r0_2180 = 1;
                                } else {
                                    var_r0_2180 = 2;
                                }
                                break;
                            case 0x0:
                                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                    var_r0_2180 = 5;
                                } else {
                                    var_r0_2180 = 3;
                                }
                                break;
                            default:
                                var_r0_2180 = 4;
                                break;
                            }
                            if (var_r0_2180 == 1) {
                                var_f4_2138 = __float_nan;
                            }
                        }
                        M2C_FIELD(temp_r30_2118, f32 *, 0x18) = (f32) (var_f4_2138 / ((f32) M2C_FIELD(temp_r30_2118, MKAnim **, 0)->unk4 / 30.0f));
                    }
                    var_r25_2114 += 1;
                    var_r20_2115 += 0x20;
                } while (var_r25_2114 < 3);
                var_r27_2109 += 1;
                var_r21_2110 += 0x70;
                goto loop_27;
            }
            var_r28_2105 += 1;
            var_r22_2106 += 8;
        } while (var_r28_2105 < 0x13);
        var_r29_2101 += 1;
        var_r23_2102 += 0x98;
        goto loop_30;
    }
    this->unk12C *= 100.0f;
    this->unk130 *= 100.0f;
    this->unk134 *= 100.0f;
    this->unk138 *= 100.0f;
    this->unk13C *= 100.0f;
    this->unk148 *= 100.0f;
    this->unk140 *= 100.0f;
    this->unk164 *= 100.0f;
    this->unk14C *= 0.017453292f;
    this->unk154 *= 0.017453292f;
    this->unk158 *= 0.017453292f;
    this->unk15C *= 0.017453292f;
    this->unk160 *= 0.017453292f;
    this->unk268 = (u32) Tools_GetMatchingNodeIndex(this->unk2C, "l_foot");
    this->unk26C = (u32) Tools_GetMatchingNodeIndex(this->unk2C, "r_foot");
    this->unk270 = (u32) Tools_GetMatchingNodeIndex(this->unk2C, "head");
    this->unk288 = (s32) Tools_GetMatchingNodeIndex(this->unk2C, "pelvis");
    this->unk290 = GetAnimSequence(4, 0x14, 0, NULL);
    this->unk294 = GetAnimSequence(4, 0x15, 0, NULL);
    InitArmour();
    this->unk29C = (long) MKMaterial_Create("FX_FireOverride");
    this->unk2A0 = (long) MKMaterial_Create("FX_ElectricityOverride");
    this->unk2A4 = (long) MKMaterial_Create("FX_IceOverride");
    this->unk2A8 = (long) MKMaterial_Create("FX_EarthOverride");
    this->unk298 = (u32) Tools_GetMatchingSubObjectIndex((SubObjectType) 0, this->unk2C, "shield");
    this->unk284 = (MKHeap *) Tools_GetMatchingRefPointIndex(this->unk2C, "breath");
    if (((u8) this->unk264 != 0) && ((MKHeap *) this->unk284 != (MKHeap *)-1U)) {
        if (MKHeap::Current() != NULL) {
            var_r3_2371 = (CharacterBreathFXDescriptor *) (((MKHeap *) (MKHeap::Current()))->Alloc(0x20, NULL, 0));
        } else {
            var_r3_2371 = (CharacterBreathFXDescriptor *) (malloc(0x20));
        }
        this->unk258 = var_r3_2371;
        this->unk258->Init();
        this->unk258->unk0 = (u32) this->unk284;
    }
    this->unk260 = checked_cast<IceBitsPS *, MKProp>(gMK->CreateProp("IceBitsPS"));
    if (HasAttack(0x2000U, 0) != 0) {
        this->unk25C = (long) (checked_cast<ElementalRing *, MKProp>(gMK->CreateProp("ElementalRing")));
    }
}
