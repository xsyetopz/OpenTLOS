#include "spyro/source/Leviathan.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/Platform.h"
#include "spyro/source/WaterSurfaceFX.h"
#include "unplaced_templates.h"
#include "common/Source/MKModel.h"
#include "common/Source/OmniLight.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDRandom.h"
#include <m2c_macros.h>

s32 stricmp(s8 *);                                  /* extern */
extern s32 GS_TurtleSwim;
extern f32 *KDSpline_PositionMixer;
extern f32 *KDSpline_VelocityMixer;
extern MKSceneManager *gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
#if 0 // DRAFT: illegal implicit conversion from 'const char *' to
static s8 *pLeviathanAnimEvents[3] = { "SmallSplashes", .L_80364D2E, NULL };
#endif

#if 0 // DRAFT: declaration syntax error
static s8 .L_80364D2E[0x73] = {
    0x48,
    0x75,
    0x67,
    0x65,
    0x53,
    0x70,
    0x6C,
    0x61,
    0x73,
    0x68,
    0x65,
    0x73,
    0,
    0x53,
    0x77,
    0x69,
    0x6D,
    0x53,
    0x6C,
    0x6F,
    0x77,
    0,
    0x53,
    0x77,
    0x69,
    0x6D,
    0,
    0x4C,
    0x6F,
    0x6F,
    0x6B,
    0x75,
    0x70,
    0,
    0x53,
    0x75,
    0x62,
    0x4D,
    0x65,
    0x72,
    0x67,
    0x65,
    0,
    0x73,
    0x70,
    0x65,
    0x65,
    0x64,
    0,
    0x77,
    0x61,
    0x74,
    0x65,
    0x72,
    0x68,
    0x65,
    0x69,
    0x67,
    0x68,
    0x74,
    0,
    0x77,
    0x61,
    0x79,
    0x70,
    0x6F,
    0x69,
    0x6E,
    0x74,
    0x73,
    0,
    0x57,
    0x61,
    0x74,
    0x65,
    0x72,
    0x44,
    0x72,
    0x6F,
    0x70,
    0x73,
    0x50,
    0x53,
    0,
    0x57,
    0x61,
    0x74,
    0x65,
    0x72,
    0x53,
    0x75,
    0x72,
    0x66,
    0x61,
    0x63,
    0x65,
    0x46,
    0x58,
    0,
    0x70,
    0x37,
    0x30,
    0x30,
    0x39,
    0x5F,
    0x57,
    0x61,
    0x74,
    0x65,
    0x72,
    0x57,
    0x61,
    0x6B,
    0x65,
    0,
}; /* const */

void Leviathan::SetDefaults() {
    this->unk19C = 2;
    this->unk194 = 0.0f;
    SetAnim(0);
    Update();
}
#endif

#if 0 // DRAFT: function call 'KDSound_Stop(long *)' does not match
void Leviathan::Deinit() {
    ((KDUniformSpline *) &this->unk180)->Deinit();
    KDSound_Stop(&this->unk1C0);
    MKModel_Destroy(this->unk1B8);
    Platform::Deinit();
}
#endif

void Leviathan::Draw() {
    f64 sp78;
    f64 sp70;
    M2C_UNK sp40;
    M2C_UNK sp3C;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f3_120;
    u8 temp_r30_152;
    u8 temp_r31_135;

    GameProp::Draw();
    M2C_STRUCT_COPY((s32) &sp3C + 4, (s32) (((u8 *) this->unk8) - 4) + 4, 0x40);
    sp30 = sp70;
    temp_f3_120 = this->unk1BC;
    sp38 = sp78;
    sp70 = (f32) sp30;
    (*(f32 *) ((u8 *) &sp70 + 0x4)) = temp_f3_120;
    sp78 = (f32) sp38;
    (*(f32 *) ((u8 *) &sp78 + 0x4)) = 1.0f;
    (*(f32 *) ((u8 *) &sp30 + 0x4)) = temp_f3_120;
    MKModel_SetWorldMatrix(this->unk1B8, *((Matrix *) &sp40));
    temp_r31_135 = MKMaterial_EnableFog(0U);
    sp10 = 1.0f;
    sp14 = 1.0f;
    sp18 = 1.0f;
    sp1C = this->unk20;
    sp20 = (f64) sp10;
    sp28 = (f64) sp18;
    MKModel_SetColor(this->unk1B8, *((MKVector4 *) &sp20));
    temp_r30_152 = OmniLight_SuspendAll(1U);
    MKModel_Draw(this->unk1B8, NULL);
    OmniLight_SuspendAll(temp_r30_152);
    MKMaterial_EnableFog(temp_r31_135);
}

void Leviathan::Message(MKMessage *arg0) {
    s32 temp_r0_178;

    ((KDSoundPlayer *) &this->unk1C0)->Message(arg0);
    temp_r0_178 = arg0->unk0;
    switch (temp_r0_178) {                          /* irregular */
    case 0xB5:
        if ((s32) this->unk19C == 2) {
            this->unk19C = 0;
            SetAnim(1);
        }
    default:
block_10:
        Platform::Message(arg0);
        return;
    case 0xB4:
        if ((s32) this->unk19C == 0) {
            this->unk19C = 1;
            SetAnim(3);
            return;
        }
        break;
    case 0x15:
        SetDefaults();
        goto block_10;
    }
}

#if 0 // DRAFT: illegal type
void Leviathan::EmitWaterSpray() {
    f64 sp300;
    f64 sp2F8;
    f64 sp2F0;
    f64 sp2E8;
    f64 sp2E0;
    f64 sp2D8;
    f64 sp2D0;
    f64 sp2C8;
    f64 sp2C0;
    f64 sp2B8;
    f64 sp2B0;
    f64 sp2A8;
    f64 sp2A0;
    f64 sp298;
    f64 sp290;
    f64 sp288;
    MKVector3 sp278;
    f64 sp270;
    f64 sp268;
    f64 sp260;
    f64 sp258;
    f64 sp250;
    f64 sp248;
    MKVector3 sp238;
    f64 sp230;
    f64 sp228;
    MKVector3 sp218;
    f64 sp210;
    f64 sp208;
    f64 sp200;
    f64 sp1F8;
    MKVector3 sp1E8;
    MKVector3 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    MKVector3 sp198;
    f64 sp190;
    f64 sp188;
    MKVector3 sp178;
    f64 sp170;
    f64 sp168;
    MKVector3 sp158;
    MKVector3 sp148;
    MKVector3 sp138;
    M2C_UNK sp128;
    MKVector3 sp118;
    MKVector3 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f32 spE0;
    f64 spD8;
    f32 spD0;
    f64 spC8;
    f32 spC0;
    f64 spB8;
    f32 spB0;
    f64 spA8;
    f32 spA0;
    f64 sp98;
    f32 sp90;
    f64 sp88;
    f32 sp80;
    f64 sp78;
    f32 sp70;
    f64 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKProp *temp_r3_477;
    f32 temp_f0_507;
    f32 temp_f31_431;
    f64 temp_f0_294;
    f64 temp_f0_306;
    f64 temp_f0_329;
    s32 var_r28_379;
    s32 var_r29_367;
    void *temp_r27_492;
    void *temp_r3_489;
    void *temp_r5_237;
    void *temp_r5_254;
    void *temp_r5_274;
    void *temp_r5_430;

    temp_r5_237 = this->unk8;
    sp48 = -M2C_FIELD(temp_r5_237, f32 *, 0x20);
    sp4C = -M2C_FIELD(temp_r5_237, f32 *, 0x24);
    sp50 = -M2C_FIELD(temp_r5_237, f32 *, 0x28);
    sp268 = (f64) sp48;
    sp270 = (f64) sp50;
    sp278.operator*(2000.0f);
    temp_r5_254 = this->unk8;
    spD8 = *(temp_r5_254 + 0x30) + M2C_BITWISE(f64, sp278);
    sp288 = spD8;
    spE0 = M2C_FIELD(temp_r5_254, f32 *, 0x38) + sp278.unk8;
    sp2C8 = spD8;
    sp290 = (f64) spE0;
    sp2D0 = (f64) spE0;
    sp218.operator*(500.0f);
    temp_r5_274 = this->unk8;
    sp38 = -M2C_FIELD(temp_r5_274, f32 *, 0);
    sp3C = -M2C_FIELD(temp_r5_274, f32 *, 4);
    sp40 = -M2C_FIELD(temp_r5_274, f32 *, 8);
    sp228 = (f64) sp38;
    sp230 = (f64) sp40;
    sp238.operator*(1000.0f);
    temp_f0_294 = sp2C8 + M2C_BITWISE(f64, sp238);
    sp28 = temp_f0_294;
    sp248 = temp_f0_294;
    sp30 = (f32) sp2D0 + sp238.unk8;
    sp250 = (f64) sp30;
    temp_f0_306 = sp248 + M2C_BITWISE(f64, sp218);
    spC8 = temp_f0_306;
    sp258 = temp_f0_306;
    sp2D8 = temp_f0_306;
    spD0 = (f32) sp250 + sp218.unk8;
    sp260 = (f64) spD0;
    sp2E0 = (f64) spD0;
    sp1D8.operator*(500.0f);
    sp1E8.operator*(1000.0f);
    temp_f0_329 = sp2C8 + M2C_BITWISE(f64, sp1E8);
    sp18 = temp_f0_329;
    sp1F8 = temp_f0_329;
    sp20 = (f32) sp2D0 + sp1E8.unk8;
    sp200 = (f64) sp20;
    spB8 = sp1F8 + M2C_BITWISE(f64, sp1D8);
    sp208 = spB8;
    spC0 = (f32) sp200 + sp1D8.unk8;
    sp2B8 = spB8;
    sp210 = (f64) spC0;
    sp2C0 = (f64) spC0;
    spA8 = sp2C8 - sp2D8;
    sp1C8 = spA8;
    spB0 = (f32) sp2D0 - (f32) sp2E0;
    sp2A8 = spA8;
    sp1D0 = (f64) spB0;
    sp2B0 = (f64) spB0;
    sp98 = sp2C8 - sp2B8;
    var_r29_367 = 0;
    sp1B8 = sp98;
    spA0 = (f32) sp2D0 - (f32) sp2C0;
    sp298 = sp98;
    sp1C0 = (f64) spA0;
    sp2A0 = (f64) spA0;
    do {
        var_r28_379 = 0;
loop_2:
        if (var_r29_367 != 0) {
            sp198.operator*(MKRand_Float(&gViewSeed, 0.0f, 1.0f));
            sp88 = sp2D8 + M2C_BITWISE(f64, sp198);
            sp1A8 = sp88;
            sp90 = (f32) sp2E0 + sp198.unk8;
            sp2F8 = sp88;
            sp1B0 = (f64) sp90;
            sp300 = (f64) sp90;
        } else {
            sp178.operator*(MKRand_Float(&gViewSeed, 0.0f, 1.0f));
            sp78 = sp2B8 + M2C_BITWISE(f64, sp178);
            sp188 = sp78;
            sp80 = (f32) sp2C0 + sp178.unk8;
            sp2F8 = sp78;
            sp190 = (f64) sp80;
            sp300 = (f64) sp80;
        }
        temp_r5_430 = this->unk8;
        temp_f31_431 = MKRand_Float(&gViewSeed, 0.5f, 1.0f);
        sp8 = -M2C_FIELD(temp_r5_430, f32 *, 0x20);
        spC = -M2C_FIELD(temp_r5_430, f32 *, 0x24);
        sp10 = -M2C_FIELD(temp_r5_430, f32 *, 0x28);
        spF8 = (f64) sp8;
        sp100 = (f64) sp10;
        sp108.operator*(4000.0f);
        sp118.operator*(temp_f31_431);
        MKVector(1.0f, 1.0f, 1.0f);
        MKVector(-1.0f, 0.0f, -1.0f);
        KDRand_Vector(sp148, sp138);
        sp158.operator*(3000.0f);
        sp68 = sp158 + M2C_BITWISE(f64, sp118);
        temp_r3_477 = this->unk1A0;
        sp168 = sp68;
        sp70 = sp158.unk8 + sp118.unk8;
        sp2E8 = sp68;
        sp170 = (f64) sp70;
        sp2F0 = (f64) sp70;
        temp_r3_489 = M2C_FIELD(temp_r3_477->__vptr, void *(**)(MKProp *, f64), 0x3C)(temp_r3_477, sp68);
        if (temp_r3_489 != NULL) {
            temp_r27_492 = M2C_FIELD(temp_r3_489, void **, 0x2C);
            M2C_FIELD(temp_r3_489, f64 *, 0) = sp2F8;
            M2C_FIELD(temp_r3_489, f64 *, 8) = sp300;
            M2C_FIELD(temp_r3_489, f32 *, 0x20) = 0.0f;
            M2C_FIELD(temp_r3_489, f32 *, 0x28) = 0.0f;
            temp_f0_507 = 3.1415927f * MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            sp58 = 0.5f;
            sp5C = 0.5f;
            M2C_FIELD(temp_r3_489, f32 *, 0x24) = (f32) (2.0f * temp_f0_507);
            sp60 = 0.5f;
            sp64 = 1.0f;
            M2C_FIELD(temp_r3_489, f64 *, 0x10) = (f64) sp58;
            M2C_FIELD(temp_r3_489, f64 *, 0x18) = (f64) sp60;
            M2C_FIELD(temp_r27_492, f64 *, 0) = sp2E8;
            spE8 = (f64) sp58;
            spF0 = (f64) sp60;
            M2C_FIELD(temp_r27_492, f64 *, 8) = sp2F0;
            M2C_FIELD(temp_r27_492, f32 *, 0x18) = MKRand_Float(&gViewSeed, 3.0f, 6.0f);
            M2C_FIELD(temp_r27_492, f32 *, 0x10) = 0.0f;
            M2C_FIELD(temp_r27_492, f32 *, 0x14) = (f32) M2C_FIELD(this->unk1A0, f32 *, 0xF4);
        }
        var_r28_379 += 1;
        if (var_r28_379 < 0xA) {
            goto loop_2;
        }
        var_r29_367 += 1;
    } while (var_r29_367 < 2);
}
#endif

#if 0 // DRAFT: illegal type
void Leviathan::EmitHugeSplash() {
    f64 sp300;
    f64 sp2F8;
    f64 sp2F0;
    f64 sp2E8;
    f64 sp2E0;
    f64 sp2D8;
    f64 sp2D0;
    f64 sp2C8;
    f64 sp2C0;
    f64 sp2B8;
    f64 sp2B0;
    f64 sp2A8;
    f64 sp2A0;
    f64 sp298;
    f64 sp290;
    f64 sp288;
    MKVector3 sp278;
    f64 sp270;
    f64 sp268;
    f64 sp260;
    f64 sp258;
    f64 sp250;
    f64 sp248;
    MKVector3 sp238;
    f64 sp230;
    f64 sp228;
    MKVector3 sp218;
    f64 sp210;
    f64 sp208;
    f64 sp200;
    f64 sp1F8;
    MKVector3 sp1E8;
    MKVector3 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    MKVector3 sp198;
    f64 sp190;
    f64 sp188;
    MKVector3 sp178;
    f64 sp170;
    f64 sp168;
    MKVector3 sp158;
    MKVector3 sp148;
    MKVector3 sp138;
    M2C_UNK sp128;
    MKVector3 sp118;
    MKVector3 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f32 spE0;
    f64 spD8;
    f32 spD0;
    f64 spC8;
    f32 spC0;
    f64 spB8;
    f32 spB0;
    f64 spA8;
    f32 spA0;
    f64 sp98;
    f32 sp90;
    f64 sp88;
    f32 sp80;
    f64 sp78;
    f32 sp70;
    f64 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKProp *temp_r3_810;
    f32 temp_f0_840;
    f32 temp_f31_764;
    f64 temp_f0_627;
    f64 temp_f0_639;
    f64 temp_f0_662;
    s32 var_r28_712;
    s32 var_r29_700;
    void *temp_r27_825;
    void *temp_r3_822;
    void *temp_r5_570;
    void *temp_r5_587;
    void *temp_r5_607;
    void *temp_r5_763;

    temp_r5_570 = this->unk8;
    sp48 = -M2C_FIELD(temp_r5_570, f32 *, 0x20);
    sp4C = -M2C_FIELD(temp_r5_570, f32 *, 0x24);
    sp50 = -M2C_FIELD(temp_r5_570, f32 *, 0x28);
    sp268 = (f64) sp48;
    sp270 = (f64) sp50;
    sp278.operator*(2000.0f);
    temp_r5_587 = this->unk8;
    spD8 = *(temp_r5_587 + 0x30) + M2C_BITWISE(f64, sp278);
    sp288 = spD8;
    spE0 = M2C_FIELD(temp_r5_587, f32 *, 0x38) + sp278.unk8;
    sp2C8 = spD8;
    sp290 = (f64) spE0;
    sp2D0 = (f64) spE0;
    sp218.operator*(500.0f);
    temp_r5_607 = this->unk8;
    sp38 = -M2C_FIELD(temp_r5_607, f32 *, 0);
    sp3C = -M2C_FIELD(temp_r5_607, f32 *, 4);
    sp40 = -M2C_FIELD(temp_r5_607, f32 *, 8);
    sp228 = (f64) sp38;
    sp230 = (f64) sp40;
    sp238.operator*(1000.0f);
    temp_f0_627 = sp2C8 + M2C_BITWISE(f64, sp238);
    sp28 = temp_f0_627;
    sp248 = temp_f0_627;
    sp30 = (f32) sp2D0 + sp238.unk8;
    sp250 = (f64) sp30;
    temp_f0_639 = sp248 + M2C_BITWISE(f64, sp218);
    spC8 = temp_f0_639;
    sp258 = temp_f0_639;
    sp2D8 = temp_f0_639;
    spD0 = (f32) sp250 + sp218.unk8;
    sp260 = (f64) spD0;
    sp2E0 = (f64) spD0;
    sp1D8.operator*(500.0f);
    sp1E8.operator*(1000.0f);
    temp_f0_662 = sp2C8 + M2C_BITWISE(f64, sp1E8);
    sp18 = temp_f0_662;
    sp1F8 = temp_f0_662;
    sp20 = (f32) sp2D0 + sp1E8.unk8;
    sp200 = (f64) sp20;
    spB8 = sp1F8 + M2C_BITWISE(f64, sp1D8);
    sp208 = spB8;
    spC0 = (f32) sp200 + sp1D8.unk8;
    sp2B8 = spB8;
    sp210 = (f64) spC0;
    sp2C0 = (f64) spC0;
    spA8 = sp2C8 - sp2D8;
    sp1C8 = spA8;
    spB0 = (f32) sp2D0 - (f32) sp2E0;
    sp2A8 = spA8;
    sp1D0 = (f64) spB0;
    sp2B0 = (f64) spB0;
    sp98 = sp2C8 - sp2B8;
    var_r29_700 = 0;
    sp1B8 = sp98;
    spA0 = (f32) sp2D0 - (f32) sp2C0;
    sp298 = sp98;
    sp1C0 = (f64) spA0;
    sp2A0 = (f64) spA0;
    do {
        var_r28_712 = 0;
loop_2:
        if (var_r29_700 != 0) {
            sp198.operator*(MKRand_Float(&gViewSeed, 0.0f, 1.0f));
            sp88 = sp2D8 + M2C_BITWISE(f64, sp198);
            sp1A8 = sp88;
            sp90 = (f32) sp2E0 + sp198.unk8;
            sp2F8 = sp88;
            sp1B0 = (f64) sp90;
            sp300 = (f64) sp90;
        } else {
            sp178.operator*(MKRand_Float(&gViewSeed, 0.0f, 1.0f));
            sp78 = sp2B8 + M2C_BITWISE(f64, sp178);
            sp188 = sp78;
            sp80 = (f32) sp2C0 + sp178.unk8;
            sp2F8 = sp78;
            sp190 = (f64) sp80;
            sp300 = (f64) sp80;
        }
        temp_r5_763 = this->unk8;
        temp_f31_764 = MKRand_Float(&gViewSeed, 0.5f, 1.0f);
        sp8 = -M2C_FIELD(temp_r5_763, f32 *, 0x20);
        spC = -M2C_FIELD(temp_r5_763, f32 *, 0x24);
        sp10 = -M2C_FIELD(temp_r5_763, f32 *, 0x28);
        spF8 = (f64) sp8;
        sp100 = (f64) sp10;
        sp108.operator*(4000.0f);
        sp118.operator*(temp_f31_764);
        MKVector(1.0f, 5.0f, 1.0f);
        MKVector(-1.0f, 0.0f, -1.0f);
        KDRand_Vector(sp148, sp138);
        sp158.operator*(3000.0f);
        sp68 = sp158 + M2C_BITWISE(f64, sp118);
        temp_r3_810 = this->unk1A0;
        sp168 = sp68;
        sp70 = sp158.unk8 + sp118.unk8;
        sp2E8 = sp68;
        sp170 = (f64) sp70;
        sp2F0 = (f64) sp70;
        temp_r3_822 = M2C_FIELD(temp_r3_810->__vptr, void *(**)(MKProp *, f64), 0x3C)(temp_r3_810, sp68);
        if (temp_r3_822 != NULL) {
            temp_r27_825 = M2C_FIELD(temp_r3_822, void **, 0x2C);
            M2C_FIELD(temp_r3_822, f64 *, 0) = sp2F8;
            M2C_FIELD(temp_r3_822, f64 *, 8) = sp300;
            M2C_FIELD(temp_r3_822, f32 *, 0x20) = 0.0f;
            M2C_FIELD(temp_r3_822, f32 *, 0x28) = 0.0f;
            temp_f0_840 = 3.1415927f * MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            sp58 = 0.5f;
            sp5C = 0.5f;
            M2C_FIELD(temp_r3_822, f32 *, 0x24) = (f32) (2.0f * temp_f0_840);
            sp60 = 0.5f;
            sp64 = 1.0f;
            M2C_FIELD(temp_r3_822, f64 *, 0x10) = (f64) sp58;
            M2C_FIELD(temp_r3_822, f64 *, 0x18) = (f64) sp60;
            M2C_FIELD(temp_r27_825, f64 *, 0) = sp2E8;
            spE8 = (f64) sp58;
            spF0 = (f64) sp60;
            M2C_FIELD(temp_r27_825, f64 *, 8) = sp2F0;
            M2C_FIELD(temp_r27_825, f32 *, 0x18) = MKRand_Float(&gViewSeed, 3.0f, 6.0f);
            M2C_FIELD(temp_r27_825, f32 *, 0x10) = 0.0f;
            M2C_FIELD(temp_r27_825, f32 *, 0x14) = (f32) M2C_FIELD(this->unk1A0, f32 *, 0xF4);
        }
        var_r28_712 += 1;
        if (var_r28_712 < 0x32) {
            goto loop_2;
        }
        var_r29_700 += 1;
    } while (var_r29_700 < 2);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'KDUniformSpline' to
void Leviathan::UpdateMove() {
    Matrix spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;                                       /* compiler-managed */
    f64 spD0;                                       /* compiler-managed */
    f64 spC8;                                       /* compiler-managed */
    f64 spC0;                                       /* compiler-managed */
    f64 spB8;                                       /* compiler-managed */
    f64 spB0;                                       /* compiler-managed */
    f64 spA8;
    KDUniformSpline sp90;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f5_1263;
    f32 temp_f6_1259;
    f32 temp_f7_1176;
    f32 temp_f7_1261;
    f32 temp_f8_1162;
    f32 temp_f9_1169;
    f32 var_f0_909;
    f32 var_f10_1065;
    f32 var_f10_1184;
    f32 var_f11_1164;
    f32 var_f1_936;
    f32 var_f2_1186;
    f32 var_f4_1090;
    f32 var_f4_992;
    f32 var_f7_983;
    f64 temp_f0_1289;
    f64 temp_f1_1003;
    f64 temp_f1_1007;
    f64 temp_f1_1096;
    f64 temp_f1_1102;
    f64 temp_f1_1106;
    f64 temp_f1_1276;
    f64 temp_f1_997;
    f64 temp_f4_1194;
    f64 temp_f4_1200;
    f64 temp_f4_1204;
    s32 temp_r3_1026;
    s32 temp_r3_1125;
    s32 temp_r3_1223;
    s32 var_r0_1036;
    s32 var_r0_1135;
    s32 var_r0_1233;

    if ((u32) this->unk18C != 0U) {
        if ((s32) this->unk19C != 2) {
            var_f0_909 = (this->unk198 * gUpdateTimeDelta) + this->unk194;
            if (var_f0_909 < 1.0f) {

            } else {
                var_f0_909 = 1.0f;
            }
            if (var_f0_909 > 0.0f) {

            } else {
                var_f0_909 = 0.0f;
            }
            this->unk194 = var_f0_909;
        }
        sp1C = 0.0f;
        sp90.GetMeasure(this->unk194, (Matrix *) &this->unk180, KDSpline_PositionMixer);
        var_f1_936 = this->unk194 - 0.001f;
        spE0 = M2C_BITWISE(f64, sp90);
        spE8 = (f64) sp90.unk8;
        if (var_f1_936 < 1.0f) {

        } else {
            var_f1_936 = 1.0f;
        }
        if (var_f1_936 > 0.0f) {

        } else {
            var_f1_936 = 0.0f;
        }
        ((KDUniformSpline *) &sp80)->GetVelocity(var_f1_936);
        spD0 = sp80;
        spD8 = sp88;
        if ((this->unk194 == 1.0f) && ((s32) this->unk19C != 2)) {
            this->unk19C = 2;
        }
        M2C_STRUCT_COPY((s32) &spF0.unk3C + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
        var_f7_983 = 0.0f;
        (*(f32 *) ((u8 *) &spA8 + 0x2c)) = 0.0f;
        var_f4_992 = ((f32) spD8 * (f32) spD8) + (((f32) spD0 * (f32) spD0) + (0.0f * 0.0f));
        if (var_f4_992 > 0.000001f) {
            if (var_f4_992 > 0.0f) {
                temp_f1_997 = __frsqrte(var_f4_992);
                temp_f1_1003 = 0.5 * temp_f1_997 * -(((f64) var_f4_992 * (temp_f1_997 * temp_f1_997)) - 3.0);
                temp_f1_1007 = 0.5 * temp_f1_1003 * -(((f64) var_f4_992 * (temp_f1_1003 * temp_f1_1003)) - 3.0);
                var_f4_992 = (f32) ((f64) var_f4_992 * (0.5 * temp_f1_1007 * -(((f64) var_f4_992 * (temp_f1_1007 * temp_f1_1007)) - 3.0)));
            } else if (var_f4_992 < M2C_BITWISE(f32, 0.0)) {
                var_f4_992 = __float_nan;
            } else {
                sp18 = var_f4_992;
                temp_r3_1026 = M2C_BITWISE(s32, sp18) & 0x7F800000;
                switch (temp_r3_1026) {             /* switch 1; irregular */
                case 0x7F800000:                    /* switch 1 */
                    if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                        var_r0_1036 = 1;
                    } else {
                        var_r0_1036 = 2;
                    }
                    break;
                case 0x0:                           /* switch 1 */
                    if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                        var_r0_1036 = 5;
                    } else {
                        var_r0_1036 = 3;
                    }
                    break;
                default:                            /* switch 1 */
                    var_r0_1036 = 4;
                    break;
                }
                if (var_r0_1036 == 1) {
                    var_f4_992 = __float_nan;
                }
            }
            var_f7_983 = 1.0f / var_f4_992;
        }
        var_f10_1065 = 0.0f;
        sp40 = -sp150;
        sp44 = -sp154;
        sp48 = -sp158;
        spC0 = (f64) sp40;
        spC8 = (f64) sp48;
        spD0 = (f32) spD0 * var_f7_983;
        (*(f32 *) ((u8 *) &spA8 + 0x2c)) *= var_f7_983;
        spD8 = (f32) spD8 * var_f7_983;
        var_f4_1090 = ((f32) spC8 * (f32) spC8) + (((f32) spC0 * (f32) spC0) + (0.0f * 0.0f));
        (*(f32 *) ((u8 *) &spA8 + 0x1c)) = 0.0f;
        if (var_f4_1090 > 0.000001f) {
            if (var_f4_1090 > 0.0f) {
                temp_f1_1096 = __frsqrte(var_f4_1090);
                temp_f1_1102 = 0.5 * temp_f1_1096 * -(((f64) var_f4_1090 * (temp_f1_1096 * temp_f1_1096)) - 3.0);
                temp_f1_1106 = 0.5 * temp_f1_1102 * -(((f64) var_f4_1090 * (temp_f1_1102 * temp_f1_1102)) - 3.0);
                var_f4_1090 = (f32) ((f64) var_f4_1090 * (0.5 * temp_f1_1106 * -(((f64) var_f4_1090 * (temp_f1_1106 * temp_f1_1106)) - 3.0)));
            } else if (var_f4_1090 < M2C_BITWISE(f32, 0.0)) {
                var_f4_1090 = __float_nan;
            } else {
                sp14 = var_f4_1090;
                temp_r3_1125 = M2C_BITWISE(s32, sp14) & 0x7F800000;
                switch (temp_r3_1125) {             /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                        var_r0_1135 = 1;
                    } else {
                        var_r0_1135 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                        var_r0_1135 = 5;
                    } else {
                        var_r0_1135 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_1135 = 4;
                    break;
                }
                if (var_r0_1135 == 1) {
                    var_f4_1090 = __float_nan;
                }
            }
            var_f10_1065 = 1.0f / var_f4_1090;
        }
        spB0 = sp130;
        temp_f8_1162 = (*(f32 *) ((u8 *) &spA8 + 0x1c)) * var_f10_1065;
        var_f11_1164 = 0.0f;
        temp_f9_1169 = (f32) spC0 * var_f10_1065;
        spB8 = sp138;
        temp_f7_1176 = (f32) spC8 * var_f10_1065;
        var_f10_1184 = ((f32) spB8 * (f32) spB8) + (((f32) spB0 * (f32) spB0) + (0.0f * 0.0f));
        spC0 = temp_f9_1169;
        var_f2_1186 = 1.0f - ((temp_f7_1176 * spD8) + ((temp_f9_1169 * spD0) + (temp_f8_1162 * (*(f32 *) ((u8 *) &spA8 + 0x2c)))));
        (*(f32 *) ((u8 *) &spA8 + 0x1c)) = temp_f8_1162;
        spC8 = temp_f7_1176;
        (*(f32 *) ((u8 *) &spA8 + 0xc)) = 0.0f;
        if (var_f10_1184 > 0.000001f) {
            if (var_f10_1184 > 0.0f) {
                temp_f4_1194 = __frsqrte(var_f10_1184);
                temp_f4_1200 = 0.5 * temp_f4_1194 * -(((f64) var_f10_1184 * (temp_f4_1194 * temp_f4_1194)) - 3.0);
                temp_f4_1204 = 0.5 * temp_f4_1200 * -(((f64) var_f10_1184 * (temp_f4_1200 * temp_f4_1200)) - 3.0);
                var_f10_1184 = (f32) ((f64) var_f10_1184 * (0.5 * temp_f4_1204 * -(((f64) var_f10_1184 * (temp_f4_1204 * temp_f4_1204)) - 3.0)));
            } else if (var_f10_1184 < M2C_BITWISE(f32, 0.0)) {
                var_f10_1184 = __float_nan;
            } else {
                sp10 = var_f10_1184;
                temp_r3_1223 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_1223) {             /* switch 3; irregular */
                case 0x7F800000:                    /* switch 3 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_1233 = 1;
                    } else {
                        var_r0_1233 = 2;
                    }
                    break;
                case 0x0:                           /* switch 3 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_1233 = 5;
                    } else {
                        var_r0_1233 = 3;
                    }
                    break;
                default:                            /* switch 3 */
                    var_r0_1233 = 4;
                    break;
                }
                if (var_r0_1233 == 1) {
                    var_f10_1184 = __float_nan;
                }
            }
            var_f11_1164 = 1.0f / var_f10_1184;
        }
        temp_f6_1259 = (*(f32 *) ((u8 *) &spA8 + 0xc)) * var_f11_1164;
        temp_f7_1261 = (f32) spB0 * var_f11_1164;
        temp_f5_1263 = (f32) spB8 * var_f11_1164;
        spB0 = temp_f7_1261;
        (*(f32 *) ((u8 *) &spA8 + 0xc)) = temp_f6_1259;
        spB8 = temp_f5_1263;
        if (((spD8 * temp_f5_1263) + ((spD0 * temp_f7_1261) + ((*(f32 *) ((u8 *) &spA8 + 0x2c)) * temp_f6_1259))) < 0.0f) {
            var_f2_1186 = -var_f2_1186;
        }
        temp_f1_1276 = M2C_FIELD(this, f64 *, 0x110);
        sp30 = 0.0f;
        sp34 = var_f2_1186;
        sp38 = 0.0f;
        sp90.unk10 = (f64) sp30;
        sp60 = temp_f1_1276;
        spA8 = (f64) sp38;
        sp68 = M2C_FIELD(this, f64 *, 0x118);
        temp_f0_1289 = temp_f1_1276 + M2C_BITWISE(f64, sp90.unk10);
        sp20 = temp_f0_1289;
        sp70 = temp_f0_1289;
        sp28 = (f32) sp68 + (f32) spA8;
        sp78 = (f64) sp28;
        spF0.SetRotationPYR(*((MKVector3 *) &sp70));
        spF0.unk30 = (f32) spE0;
        spF0.unk34 = (*(f32 *) ((u8 *) &spE0 + 0x4));
        spF0.unk38 = (f32) spE8;
        spF0.unk3C = 1.0f;
        MKModel_SetWorldMatrix(this->unk4, spF0);
        ((Matrix *) &sp50)->GetRotationPYR();
        M2C_FIELD(this, f64 *, 0x110) = sp50;
        M2C_FIELD(this, f64 *, 0x118) = sp58;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'KDUniformSpline' to
void Leviathan::Update() {
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    KDUniformSpline sp80;
    f64 sp78;
    f64 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    s32 sp8;
    f32 var_f1_1362;
    f32 var_f3_1473;
    f32 var_f4_1406;
    f64 temp_f0_1510;
    f64 temp_f1_1412;
    f64 temp_f1_1418;
    f64 temp_f1_1422;
    s32 temp_r3_1441;
    s32 var_r0_1451;

    sp8 = 1;
    ((KDSoundFader *) &this->unk1C0)->Update(GS_TurtleSwim, 1U, this->unk19C == 0, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    if ((s32) this->unk19C != 2) {
        var_f1_1362 = this->unk194 - 0.001f;
        if (var_f1_1362 < 1.0f) {

        } else {
            var_f1_1362 = 1.0f;
        }
        if (var_f1_1362 > 0.0f) {

        } else {
            var_f1_1362 = 0.0f;
        }
        sp18 = 0.0f;
        sp80.GetMeasure(var_f1_1362, (Matrix *) &this->unk180, KDSpline_VelocityMixer);
        sp70 = M2C_BITWISE(f64, sp80);
        sp78 = (f64) sp80.unk8;
        sp60 = sp70 * (f64) sp18;
        spC0 = sp60;
        sp68 = (f32) sp78 * sp18;
        spC8 = (f64) sp68;
        var_f4_1406 = ((f32) spC8 * (f32) spC8) + (((f32) spC0 * (f32) spC0) + ((*(f32 *) ((u8 *) &spC0 + 0x4)) * (*(f32 *) ((u8 *) &spC0 + 0x4))));
        if (var_f4_1406 > 1e-12f) {
            if (var_f4_1406 > 0.0f) {
                temp_f1_1412 = __frsqrte(var_f4_1406);
                temp_f1_1418 = 0.5 * temp_f1_1412 * -(((f64) var_f4_1406 * (temp_f1_1412 * temp_f1_1412)) - 3.0);
                temp_f1_1422 = 0.5 * temp_f1_1418 * -(((f64) var_f4_1406 * (temp_f1_1418 * temp_f1_1418)) - 3.0);
                var_f4_1406 = (f32) ((f64) var_f4_1406 * (0.5 * temp_f1_1422 * -(((f64) var_f4_1406 * (temp_f1_1422 * temp_f1_1422)) - 3.0)));
            } else if (var_f4_1406 < M2C_BITWISE(f32, 0.0)) {
                var_f4_1406 = __float_nan;
            } else {
                sp10 = var_f4_1406;
                temp_r3_1441 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_1441) {             /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_1451 = 1;
                    } else {
                        var_r0_1451 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_1451 = 5;
                    } else {
                        var_r0_1451 = 3;
                    }
                    break;
                default:
                    var_r0_1451 = 4;
                    break;
                }
                if (var_r0_1451 == 1) {
                    var_f4_1406 = __float_nan;
                }
            }
            var_f3_1473 = 1.0f / var_f4_1406;
        } else {
            var_f3_1473 = 0.0f;
        }
        sp54 = (*(f32 *) ((u8 *) &spC0 + 0x4)) * var_f3_1473;
        sp50 = (f32) spC0 * var_f3_1473;
        sp58 = (f32) spC8 * var_f3_1473;
        spE0 = (f64) sp50;
        spE8 = (f64) sp58;
        sp40 = spE0 * 5.717499035e-315;
        spA0 = sp40;
        sp48 = (f32) spE8 * 2000.0f;
        sp14 = 0.0f;
        spA8 = (f64) sp48;
        ((KDUniformSpline *) &spB0)->GetMeasure(this->unk194, (Matrix *) &this->unk180, KDSpline_PositionMixer);
        temp_f0_1510 = spB0 + spA0;
        sp30 = temp_f0_1510;
        spD0 = temp_f0_1510;
        sp38 = spB8 + (f32) spA8;
        spD8 = (f64) sp38;
        sp20 = spE0 * 5.7700341e-315;
        sp28 = (f32) spE8 * 5000.0f;
        sp80.unk10 = sp20;
        sp98 = (f64) sp28;
        this->unk1A4->AddMovementForce(*((MKVector3 *) &spD0), *((MKVector3 *) &sp80.unk10));
    }
    if (this->unk80->CheckEvent(0) != 0) {
        EmitWaterSpray();
    }
    if (this->unk80->CheckEvent(1) != 0) {
        EmitHugeSplash();
    }
    if (((s32) this->unk19C == 1) && (this->unk80->unk2C & 1)) {
        this->unk19C = 2;
        SetAnim(0);
    }
    GameProp::Update();
}
#endif

void Leviathan::Resolve() {
    MKAnimScript *temp_r30_1588;
    MKAnimScript *temp_r30_1608;
    MKAnimScript *temp_r30_1626;
    MKAnimScript *temp_r30_1644;
    void *var_r3_1600;
    void *var_r3_1618;
    void *var_r3_1636;
    void *var_r3_1654;

    Platform::Resolve();
    temp_r30_1588 = this->unk80;
    if (temp_r30_1588->Exists("") != 0) {
        var_r3_1600 = temp_r30_1588->GetAnim("");
    } else {
        var_r3_1600 = NULL;
    }
    this->unk1A8 = (s32) var_r3_1600;
    temp_r30_1608 = this->unk80;
    if (temp_r30_1608->Exists("") != 0) {
        var_r3_1618 = temp_r30_1608->GetAnim("");
    } else {
        var_r3_1618 = NULL;
    }
    this->unk1AC = (s32) var_r3_1618;
    temp_r30_1626 = this->unk80;
    if (temp_r30_1626->Exists("") != 0) {
        var_r3_1636 = temp_r30_1626->GetAnim("");
    } else {
        var_r3_1636 = NULL;
    }
    this->unk1B0 = (s32) var_r3_1636;
    temp_r30_1644 = this->unk80;
    if (temp_r30_1644->Exists("") != 0) {
        var_r3_1654 = temp_r30_1644->GetAnim("");
    } else {
        var_r3_1654 = NULL;
    }
    this->unk1B4 = (s32) var_r3_1654;
    SetAnim(0);
}

void Leviathan::SetAnim(int arg0) {
    this->unk80->SetAnim(M2C_FIELD((this + (arg0 * 4)), MKAnim **, 0x1A8), 1.0f, 0.5f, 0, -1);
}

#if 0 // DRAFT: undefined identifier 'pLeviathanAnimEvents'
void Leviathan::LoadDone() {
    Platform::LoadDone();
    if ((u32) this->unk18C != 0U) {
        this->unk198 /= this->unk188;
    } else {
        this->unk198 = 0.0005f;
    }
    this->unk80->InitEvents(pLeviathanAnimEvents);
}
#endif

#if 0 // DRAFT: ')' expected
s32 Leviathan::LoadLine(MKIniLine *arg0) {
    MKVector3 sp8;
    MKIniLine *var_r30_1785;
    s32 temp_r3_1772;

    if ((Platform::LoadLine(arg0) != 0) || (arg0->LoadFloat("", &this->unk198, 0) != 0) || (arg0->LoadFloat("", &this->unk1BC, 0) != 0)) {
        return 1;
    }
    arg0->GetFieldName();
    if (stricmp"" == 0) {
        if ((u32) this->unk18C != 0U) {
            return 0;
        }
        temp_r3_1772 = arg0->GetNmbrOfSubLines();
        if (temp_r3_1772 == 0) {
            return 0;
        }
        ((KDUniformSpline *) &this->unk180)->Init(temp_r3_1772, 0U);
        var_r30_1785 = arg0->unkC->GetSubLine(arg0);
loop_11:
        if (var_r30_1785 != NULL) {
            var_r30_1785->AsVector3(0, &sp8);
            ((KDUniformSpline *) &this->unk180)->AddNode(sp8);
            var_r30_1785 = var_r30_1785->unkC->GetNextLine(var_r30_1785);
            goto loop_11;
        }
        return 1;
    }
    return 0;
}
#endif

void Leviathan::Init() {
    Platform::Init();
    this->unk19C = 2;
    this->unk194 = 0.0f;
    this->unk198 = 100.0f;
    gMK->CreatePropDeferred("", &this->unk1A0);
    this->unk1A4 = checked_cast<WaterSurfaceFX *, MKProp>(gMK->CreateProp(""));
    this->unk1A4->unk58 = 2.0f;
    this->unk1B8 = MKModel_Create("", NULL, 2, NULL);
    this->unk1BC = 0.0f;
    ((KDSoundFader *) &this->unk1C0)->Init(0.25f, 0.25f);
}
