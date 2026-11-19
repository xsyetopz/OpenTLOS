void FireBombFX::Fire(const MKVector3 &arg0, const MKVector3 &arg1, float arg2, MKProp *arg3, bool arg4, bool arg5, int arg6, const MKVector3 &arg7) {
    s8 spC8;
    s32 spC4;
    MKCollisionInfo *spC0;
    s32 spBC;
    f32 spB8;
    s32 spB4;
    s8 spB3;
    s8 spB2;
    s16 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    MKVector3 spDiff;
    MKVector3 spStep;
    MKVector3 spPt;
    f32 sp8;
    void *spC;
    u8 sp10;
    MKProp *temp_r3_231;
    MKProp *temp_r3_291;
    ManagedLight *temp_r4_161;
    ShapedTrailFX *temp_r3_130;
    ShapedTrailFX *temp_r3_147;
    ShapedTrailFX *temp_r4_136;
    f32 temp_f1_137;
    f32 temp_f2_410;
    f32 var_f4_346;
    f64 temp_f1_349;
    f64 temp_f1_355;
    f64 temp_f1_359;
    s32 temp_r0_242;
    s32 temp_r30_175;
    s32 temp_r31_178;
    s32 temp_r3_378;
    s32 temp_r4_176;
    s32 var_r0_388;
    s32 var_r23_213;
    s32 var_r6_194;
    s32 var_r7_269;
    u8 var_r4_184;
    u8 var_r4_203;
    void *temp_r5_180;

    MKModel_SetPosition(this->unk4, arg0);
    this->unkE0 = 1;
    temp_r3_130 = this->unkCC;
    temp_r3_130->Reset();
    temp_r4_136 = this->unkCC;
    temp_f1_137 = 2.5f * arg2;
    temp_r4_136->unkA0 = (temp_r4_136->unkA0 & ~0x80) | ((lit_762 << 7) & 0x80);
    if (temp_f1_137 != 0.0f) {
        temp_r4_136->unk98 = temp_f1_137;
    }
    temp_r3_147 = this->unkCC;
    temp_r3_147->unkA0 |= 0x40;
    this->unk120 = arg3;
    M2C_FIELD(this, u8 *, 0x1B8) = arg5;
    this->unkFC = 0.0f;
    this->unk104 = 0.0f;
    this->unk128 = arg2;
    M2C_FIELD(this, u8 *, 0x1B0) = arg4;
    this->unkC8 = 10.0f;
    temp_r4_161 = this->unk108;
    if (temp_r4_161 != NULL) {
        ((LightManager *) gb.unk80)->EnableLight(temp_r4_161, 1U);
    }
    this->unk124 = 10000.0f;
    temp_r30_175 = M2C_FIELD(GameData::gameData, s32 *, 0x158);
    temp_r4_176 = temp_r30_175 << 5;
    temp_r31_178 = M2C_FIELD(&GameData::gameData[0x70], s32 *, temp_r4_176 + 0x7C);
    temp_r5_180 = &GameData::gameData[0x70] + (temp_r4_176 + 0x64);
    if (temp_r31_178 == 3) {
        var_r4_184 = 0;
        if (((s32) M2C_FIELD(temp_r5_180, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r5_180, s32 *, 4) == 3)) {
            var_r4_184 = 1;
        }
        var_r6_194 = var_r4_184 != 0;
    } else {
        var_r6_194 = M2C_FIELD(temp_r5_180, s32 *, temp_r31_178 * 4);
    }
    if (temp_r31_178 == 3) {
        var_r4_203 = 0;
        if (((s32) M2C_FIELD(temp_r5_180, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r5_180, s32 *, 4) == 3)) {
            var_r4_203 = 1;
        }
        var_r23_213 = var_r4_203 != 0;
    } else {
        var_r23_213 = M2C_FIELD(temp_r5_180, s32 *, temp_r31_178 * 4);
    }
    this->unk130.Init(arg3, ((GameStats *) &GameData::gameData[0x70])->GetBreathAttackDamage(temp_r30_175, temp_r31_178, var_r6_194), temp_r31_178, var_r23_213, temp_r30_175, temp_r30_175, 0, -1);
    temp_r3_231 = this->unk120;
    if ((temp_r3_231 != NULL) && (M2C_FIELD(temp_r3_231->unk0, s32 *, 0xC) & 8)) {
        this->unk130.unk34 = 5.0f;
    }
    this->unk1C0 = arg6;
    temp_r0_242 = this->unk1C0;
    switch (temp_r0_242) {
    case 0:
        this->unkD0 = M2C_FIELD(&arg1, f64 *, 0);
        this->unkD8 = M2C_FIELD(&arg1, f64 *, 8);
        spC = (void *) gb.unk0->GetCollisionInfo();
        if (spC != NULL) {
            sp10 = M2C_FIELD(spC, u8 *, 4);
            M2C_FIELD(spC, u8 *, 4) = 0U;
        }
        var_r7_269 = 0;
        sp78 = 0.0f;
        sp7C = 0.0f;
        sp80 = 0.0f;
        sp88 = 0.0f;
        sp8C = 0.0f;
        sp90 = 0.0f;
        sp98 = 0.0f;
        sp9C = 0.0f;
        spA0 = 0.0f;
        spA4 = 1.0f;
        spA8 = 0.0f;
        spAC = 0.0f;
        spB0 = 0;
        spB2 = 0;
        spB3 = 0;
        spB4 = 0;
        spB8 = 3.4028235e38f;
        spBC = 0;
        spC0 = NULL;
        spC4 = -1;
        spC8 = 0;
        temp_r3_291 = this->unk120;
        if ((temp_r3_291 != NULL) && (M2C_FIELD(temp_r3_291->unk0, s32 *, 0xC) & 8)) {
            var_r7_269 = 0x08000000;
        }
        if (MKCollision_SphereCollide(arg0, 50.0f, (MKCollisionResult *) &sp78, 1, (MKCollisionMode) 7, var_r7_269) != 0) {
            Explode(MKVector3::up, *((MKVector3 *) &sp78), spC0);
        }
        if (spC != NULL) {
            M2C_FIELD(spC, u8 *, 4) = sp10;
            return;
        }
        return;
    case 1:
    case 2:
        spDiff.unk0 = arg7.unk0 - arg0.unk0;
        spDiff.unk4 = arg7.unk4 - arg0.unk4;
        spDiff.unk8 = arg7.unk8 - arg0.unk8;
        var_f4_346 = (spDiff.unk8 * spDiff.unk8) + ((spDiff.unk0 * spDiff.unk0) + (spDiff.unk4 * spDiff.unk4));
        if (var_f4_346 > 0.0f) {
            temp_f1_349 = __frsqrte(var_f4_346);
            temp_f1_355 = 0.5 * temp_f1_349 * -(((f64) var_f4_346 * (temp_f1_349 * temp_f1_349)) - 3.0);
            temp_f1_359 = 0.5 * temp_f1_355 * -(((f64) var_f4_346 * (temp_f1_355 * temp_f1_355)) - 3.0);
            var_f4_346 = (f32) ((f64) var_f4_346 * (0.5 * temp_f1_359 * -(((f64) var_f4_346 * (temp_f1_359 * temp_f1_359)) - 3.0)));
        } else if (var_f4_346 < 0.0f) {
            var_f4_346 = __float_nan;
        } else {
            sp8 = var_f4_346;
            temp_r3_378 = *(s32 *) &sp8 & 0x7F800000;
            switch (temp_r3_378) {
            case 0x7F800000:
                if (*(s32 *) &sp8 & 0x7FFFFF) {
                    var_r0_388 = 1;
                } else {
                    var_r0_388 = 2;
                }
                break;
            case 0x0:
                if (*(s32 *) &sp8 & 0x7FFFFF) {
                    var_r0_388 = 5;
                } else {
                    var_r0_388 = 3;
                }
                break;
            default:
                var_r0_388 = 4;
                break;
            }
            if (var_r0_388 == 1) {
                var_f4_346 = __float_nan;
            }
        }
        temp_f2_410 = 0.5f * var_f4_346;
        spStep.unk0 = arg1.unk0 * temp_f2_410;
        spStep.unk4 = arg1.unk4 * temp_f2_410;
        spStep.unk8 = arg1.unk8 * temp_f2_410;
        spPt.unk0 = arg0.unk0 + spStep.unk0;
        spPt.unk4 = arg0.unk4 + spStep.unk4;
        spPt.unk8 = arg0.unk8 + spStep.unk8;
        this->unk1C8 = 0.0f;
        this->unk1C8 = 0.0f;
        ((KDUniformSpline *) &this->unk1C4)->AddNode(arg0);
        ((KDUniformSpline *) &this->unk1C4)->AddNode(spPt);
        ((KDUniformSpline *) &this->unk1C4)->AddNode(arg7);
        this->unk1D8 = 0.0f;
        this->unk1D8 = 10000.0f / this->unk1C8;
        if (((s32) this->unk1C0 == 2) && (gb.unk0->GetHeroType() == 0)) {
            KDSound_Play3d(GS_CynderBreathStart2, (const MKVector3 *) (((u8 *) this->unk8) + 0x30), 0U, -1, 0.0f, 0U);
        }
        break;
    }
}
