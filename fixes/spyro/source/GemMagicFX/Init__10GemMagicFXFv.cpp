static f32 lit_699 = 0.7f;

void GemMagicFX::Init() {
    MKHeap *var_r3_1038;
    MKHeap *var_r3_1071;
    u8 *var_r5_1047;
    u8 *temp_r3_1053;
    u8 *temp_r3_1059;
    s32 var_ctr_1051;
    s32 var_r28_1081;
    s32 var_r30_1082;
    ShapedTrailFX *temp_r3_1087;
    MKVector4 src;
    MKVector4 dst;

    MKProp::Init();
    if (MKHeap::Current() != NULL) {
        var_r3_1038 = (MKHeap *) (((MKHeap *) (MKHeap::Current()))->Alloc(0x558, NULL, 0));
    } else {
        var_r3_1038 = malloc(0x558);
    }
    this->unk4C = var_r3_1038;
    var_r5_1047 = (u8 *) this->unk4C;
    this->unk4C = (MKHeap *) (var_r5_1047 + 0x500);
    *(u32 *) (var_r5_1047 + 0x500) = 0;
    var_ctr_1051 = 0x14;
    do {
        temp_r3_1053 = (u8 *) this->unk4C;
        this->unk4C = (MKHeap *) (temp_r3_1053 + 4);
        *(u32 *) (temp_r3_1053 + 4) = (u32) var_r5_1047;
        var_r5_1047 += 0x40;
        var_ctr_1051 -= 1;
    } while (var_ctr_1051 != 0);
    temp_r3_1059 = (u8 *) this->unk4C;
    this->unk4C = (MKHeap *) (temp_r3_1059 + 4);
    *(u32 *) (temp_r3_1059 + 4) = 0;
    if (MKHeap::Current() != NULL) {
        var_r3_1071 = (MKHeap *) (((MKHeap *) (MKHeap::Current()))->Alloc(0x50, NULL, 0));
    } else {
        var_r3_1071 = malloc(0x50);
    }
    this->unk50 = var_r3_1071;
    var_r28_1081 = 0;
    var_r30_1082 = 0;
    do {
        temp_r3_1087 = checked_cast<ShapedTrailFX *, MKProp>(gMK->CreateProp("ShapedTrailFX"));
        src.unk0 = 1.0f;
        src.unk4 = 1.0f;
        src.unk8 = 1.0f;
        src.unkC = 1.0f;
        dst = src;
        M2C_FIELD(this->unk50, s32 *, var_r30_1082) = (s32) temp_r3_1087;
        ((ShapedTrailFX *) M2C_FIELD(this->unk50, s32 *, var_r30_1082))->InitData(NULL, lit_697, "fx_362", lit_698, dst, lit_699, 1U, 0.3f);
        var_r28_1081 += 1;
        M2C_FIELD(this->unk50, u8 *, var_r30_1082 + 4) = 0;
        var_r30_1082 += 8;
    } while (var_r28_1081 < 0xA);
    this->unk54 = (MKMaterial *) (MKMaterial_Create("fx_002"));
}
