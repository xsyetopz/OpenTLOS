#include "spyro/source/Torch.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "spyro/source/Coronas.h"
#include "spyro/source/CrashFirePS.h"
#include "spyro/source/EmbersPS.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/LightManager.h"
#include "spyro/source/ManagedLight.h"
#include "common/Source/MKModel.h"
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;

static s32 lit_534 = 0;
static u8 lit_535 = 0;

static s32 lit_537 = 0;
static u8 lit_538 = 1;

void Torch::Deinit() {
    Corona *temp_r4_44;
    ManagedLight *temp_r4_54;

    temp_r4_44 = this->unk108;
    if (temp_r4_44 != NULL) {
        ((Coronas *) (M2C_FIELD(&gb, Coronas **, 0x64)))->Free(temp_r4_44);
        this->unk108 = NULL;
    }
    temp_r4_54 = this->unk11C;
    if (temp_r4_54 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->FreeManagedLight(temp_r4_54);
        this->unk11C = NULL;
    }
    GameProp::Deinit();
}

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void Torch::Update() {
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    M2C_UNK sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spA8;
    f32 sp98;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp68;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Corona *temp_r4_117;
    ManagedLight *temp_r3_324;
    f32 temp_f1_187;
    f32 temp_f27_147;
    f32 temp_f27_252;
    f32 temp_f28_152;
    f32 temp_f28_230;
    f32 temp_f28_257;
    f32 temp_f30_235;
    f32 temp_f31_97;
    void *temp_r3_342;

    GameProp::Update();
    temp_f31_97 = MKRand_Float(&gViewSeed, 0.5f, 1.0f);
    if ((Corona *) this->unk108 != NULL) {
        this->unk108->unk24 = MKRand_Float(&gViewSeed, 0.75f, 1.0f);
        sp30 = -((0.1f * temp_f31_97) - 1.0f);
        temp_r4_117 = this->unk108;
        sp34 = -((0.5f * temp_f31_97) - 1.0f);
        sp38 = -((0.75f * temp_f31_97) - 1.0f);
        sp3C = 0.85f;
        M2C_FIELD(temp_r4_117, f64 *, 0x10) = (f64) sp30;
        sp160 = (f64) sp30;
        sp168 = (f64) sp38;
        M2C_FIELD(temp_r4_117, f64 *, 0x18) = (f64) sp38;
        this->unk108->unk2C = MKRand_Float(&gViewSeed, 0.0f, 6.2831855f);
    }
    this->unk110 += gUpdateTimeDelta;
    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
    if (this->unk110 == this->unk10C) {
        this->unk110 = 0.0f;
        temp_f27_147 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        temp_f28_152 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        spB0 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        spB4 = temp_f28_152;
        spB8 = temp_f27_147;
        sp150 = (f64) spB0;
        sp158 = (f64) spB8;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
        sp180 = spA0;
        spA8 = (f32) sp158 * 5.0f;
        sp188 = (f64) spA8;
        spC = MKRand_Float(&gViewSeed, 1.0f, 2.0f);
        temp_f1_187 = 50.0f * MKRand_Float(&gViewSeed, 0.0f, 1.0f);
        sp88 = 0.0f;
        sp80 = 0.0f;
        sp84 = temp_f1_187;
        sp138 = (f64) sp88;
        sp130 = (f64) sp80;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp140 = sp90;
        sp98 = this->unkF8.unk8 + (f32) sp188;
        sp148 = (f64) sp98;
        ((CrashFirePS *) (M2C_FIELD(&gb, CrashFirePS **, 0x68)))->Emit(*((MKVector3 *) &sp140), *((MKVector3 *) &sp130), spC);
    }
    this->unk118 += gUpdateTimeDelta;
    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
    if (this->unk118 == this->unk114) {
        this->unk118 = 0.0f;
        temp_f28_230 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        temp_f30_235 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        sp70 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        sp74 = temp_f30_235;
        sp78 = temp_f28_230;
        sp120 = (f64) sp70;
        sp128 = (f64) sp78;
        temp_f27_252 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        temp_f28_257 = MKRand_Float(&gViewSeed, -0.1f, 0.1f);
        MKVector(MKRand_Float(&gViewSeed, -1.0f, 1.0f), temp_f28_257, temp_f27_252);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
        sp40 = 1.0f;
        sp28 = sp108 * 10.0f;
        sp44 = 1.0f;
        sp48 = 1.0f;
        sp4C = 1.0f;
        sp110 = sp20;
        sp118 = (f64) sp28;
        sp170 = sp20;
        sp178 = (f64) sp28;
        spD0 = (f64) sp40;
        spD8 = (f64) sp48;
        sp8 = MKRand_Float(&gViewSeed, 0.2f, 1.0f);
        sp58 = 0.0f;
        sp50 = 0.0f;
        sp54 = 0.0f;
        spE8 = (f64) sp58;
        spE0 = (f64) sp50;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        spF0 = sp60;
        sp68 = this->unkF8.unk8 + (f32) sp178;
        spF8 = (f64) sp68;
        ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(*((MKVector3 *) &spF0), *((MKVector3 *) &spE0), sp8, *((MKVector4 *) &spD0), 0.0f);
    }
    temp_r3_324 = this->unk11C;
    if (temp_r3_324 != NULL) {
        sp1C = 1.0f;
        sp10 = -((0.1f * temp_f31_97) - 1.0f);
        sp14 = -((0.5f * temp_f31_97) - 1.0f);
        sp18 = -((0.75f * temp_f31_97) - 1.0f);
        temp_r3_324->unk20 = (f64) sp10;
        temp_r3_324->unk28 = (f64) sp18;
        temp_r3_342 = temp_r3_324->unk3C;
        spC0 = (f64) sp10;
        spC8 = (f64) sp18;
        if (temp_r3_342 != NULL) {
            M2C_FIELD(temp_r3_342, f64 *, 0) = (f64) sp10;
            M2C_FIELD(temp_r3_342, f64 *, 8) = (f64) sp18;
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void Torch::LoadDone() {
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKHeap **temp_r3_412;

    GameProp::LoadDone();
    this->unkF0 = MKModel_GetRefPointIndex(this->unk4, "r_fxemit0");
    MKModel_CalculateRefPointWorldPosition(this->unk4, this->unkF0, &this->unkF8);
    sp48 = 1.0f;
    sp4C = 0.75f;
    sp50 = 0.5f;
    sp54 = 0.85f;
    sp98 = (f64) sp48;
    spA0 = (f64) sp50;
    this->unk108 = ((Coronas *) (M2C_FIELD(&gb, Coronas **, 0x64)))->Alloc(this->unkF8, *((MKVector4 *) &sp98), 2.25f, lit_534, lit_535);
    this->unkC = (BoundingVolume *) &this->unkD0;
    temp_r3_412 = MKModel_GetBoundingVolume(this->unk4, (SubObjectType) 0, -1);
    M2C_FIELD(this, f64 *, 0xD0) = (f64) M2C_FIELD(temp_r3_412, f64 *, 0);
    this->unkD8 = M2C_FIELD(temp_r3_412, f64 *, 8);
    sp18 = -650.0f;
    this->unkE0 = M2C_FIELD(temp_r3_412, f64 *, 0x10);
    sp1C = -200.0f;
    sp20 = -650.0f;
    this->unkE8 = M2C_FIELD(temp_r3_412, f64 *, 0x18);
    M2C_FIELD(this, f64 *, 0xD0) = (f64) sp18;
    sp10 = 1200.0f;
    sp40 = 0.0f;
    sp8 = 1200.0f;
    spC = 800.0f;
    this->unkD8 = (f64) sp20;
    this->unkE0 = (f64) sp8;
    this->unkE8 = (f64) sp10;
    sp28 = 1.0f;
    sp2C = 0.75f;
    sp30 = 0.5f;
    sp34 = 1.0f;
    sp38 = 0.0f;
    sp3C = 0.0f;
    sp88 = (f64) sp18;
    sp90 = (f64) sp20;
    sp78 = (f64) sp8;
    sp80 = (f64) sp10;
    sp58 = (f64) sp28;
    sp60 = (f64) sp30;
    sp68 = (f64) sp38;
    sp70 = (f64) sp40;
    this->unk11C = ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->AllocManagedLight(this->unkF8, *((MKVector3 *) &sp68), *((MKVector4 *) &sp58), 600.0f, lit_537, lit_538);
    ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(this->unk11C, 1U);
}
#endif

void Torch::Disable() {
    ManagedLight *temp_r4_493;

    KDProp::Disable();
    temp_r4_493 = this->unk11C;
    if (temp_r4_493 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_493, 0U);
    }
}

void Torch::Enable() {
    ManagedLight *temp_r4_518;

    KDProp::Enable();
    temp_r4_518 = this->unk11C;
    if (temp_r4_518 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_518, 1U);
    }
}

void Torch::Init() {
    GameProp::Init();
    this->unkF8.unk0 = 0.0f;
    this->unkF8.unk4 = 0.0f;
    this->unkF8.unk8 = 0.0f;
    this->unkF0 = -1;
    this->unk108 = NULL;
    this->unk10C = 0.02f;
    this->unk110 = 0.0f;
    this->unk114 = 0.5f;
    this->unk118 = 0.0f;
    this->unk11C = NULL;
}
