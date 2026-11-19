#include "spyro/source/TrapSpawnPool.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "unplaced_templates.h"
#include "common/Source/MKCollision.h"
#include "spyro/source/PropFlags.h"
#include <m2c_macros.h>

M2C_UNK free(f32);                                  /* extern */
void *malloc(s32);                                  /* extern */
extern MKSceneManager *gMK;
extern M2C_UNK gb;

#if 0 // DRAFT: undefined identifier 'unk44'
void TrapSpawnPool::Update() {
    u8 sp1C;
    s32 sp18;
    s32 sp14;
    TrapSpawnPool *sp10;
    s32 spC;
    s32 sp8;
    s32 var_r26_57;
    s32 var_r31_56;
    void *temp_r25_65;

    MKProp::Update();
    if ((this->unk10 & 0x20000) && !(this->unk50.unk44 > M2C_FIELD(&gb, f32 *, 0x30C))) {
        var_r31_56 = 0;
        var_r26_57 = 0;
loop_6:
        if (var_r26_57 >= M2C_BITWISE(s32, this->unk50.unk40)) {

        } else {
            temp_r25_65 = *(M2C_BITWISE(s32, this->unk50.unk4C) + var_r31_56);
            sp18 = 0;
            sp14 = 0x32;
            sp1C = 0;
            M2C_FIELD(M2C_FIELD(temp_r25_65, void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(temp_r25_65, &sp14);
            if (sp1C != 0) {
                M2C_FIELD(M2C_FIELD(temp_r25_65, void **, 0x44), M2C_UNK (**)(void *), 0x30)(temp_r25_65);
                spC = 0;
                sp8 = 0xA8;
                sp10 = this;
                M2C_FIELD(M2C_FIELD(temp_r25_65, void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(temp_r25_65, &sp8);
                this->unk50.unk44 = M2C_FIELD(&gb, f32 *, 0x30C) + this->unk50.unk48;
                return;
            }
            var_r26_57 += 1;
            var_r31_56 += 4;
            goto loop_6;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk44'
void TrapSpawnPool::Reset() {
    MKProp::Reset();
    this->unk50.unk44 = M2C_FIELD(&gb, f32 *, 0x30C) + this->unk50.unk48;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk84'
void TrapSpawnPool::Resolve() {
    MKCollisionResult sp60;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp8;
    f32 temp_f0_188;
    f32 temp_f1_187;
    f32 temp_f2_254;
    f32 temp_f3_190;
    f32 temp_r3_198;
    f32 temp_r5_261;
    f32 var_f4_288;
    f64 temp_f1_291;
    f64 temp_f1_297;
    f64 temp_f1_301;
    s32 temp_r31_152;
    s32 temp_r3_320;
    s32 temp_r4_260;
    s32 var_ctr_164;
    s32 var_r0_330;
    s32 var_r29_158;
    s32 var_r29_358;
    s32 var_r29_376;
    s32 var_r31_377;
    void *temp_r3_172;
    void *temp_r3_381;

    MKProp::Resolve();
    sp50 = 0.0f;
    temp_r31_152 = this->unk50.unk84;
    sp54 = 0.0f;
    sp58 = 0.0f;
    var_r29_158 = 0;
    this->unk10C = 0.5f * (this->unk104 * M2C_FIELD(MKModel_GetBoundingVolume(M2C_FIELD(*this->unk50.unk4C, MKModel **, 4), (SubObjectType) 0, -1), f32 *, 0x10));
    var_ctr_164 = temp_r31_152;
    if (temp_r31_152 > 0) {
        do {
            temp_r3_172 = M2C_BITWISE(s32, this->unk50.unk88) + (var_r29_158 * this->unk50.unk80);
            M2C_FIELD(temp_r3_172, f32 *, 4) = (f32) (M2C_FIELD(temp_r3_172, f32 *, 4) + this->unk10C);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            var_r29_158 += 1;
            sp58 += M2C_FIELD(temp_r3_172, f32 *, 8);
            var_ctr_164 -= 1;
        } while (var_ctr_164 != 0);
    }
    temp_f1_187 = this->unkE8;
    temp_f0_188 = this->unkEC;
    temp_f3_190 = this->unkF0;
    if (((temp_f3_190 * temp_f3_190) + ((temp_f1_187 * temp_f1_187) + (temp_f0_188 * temp_f0_188))) < 0.1f) {
        temp_r3_198 = this->unk50.unk88;
        M2C_FIELD(this, f32 *, 0xE8) = (f64) M2C_FIELD(temp_r3_198, f64 *, 0);
        M2C_FIELD(this, f32 *, 0xF0) = (f64) M2C_FIELD(temp_r3_198, f64 *, 8);
    }
    sp40 = (f64) M2C_FIELD(this, f32 *, 0xE8);
    sp48 = (f64) M2C_FIELD(this, f32 *, 0xF0);
    unksp44 -= 10000.0f;
    if (MKCollision_RayCollide(*((MKVector3 *) &this->unkE8), *((MKVector3 *) &sp40), &sp60, (MKCollisionMode) 7, 0x200) != 0) {
        M2C_FIELD(this->unk50.unk88, f32 *, 4) = (f32) (sp60.unk4 + this->unk10C);
        this->unk110 = (this->unkEC - M2C_FIELD(this->unk50.unk88, f32 *, 4)) > (2.0f * this->unk10C);
    }
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    temp_f2_254 = sp58 * (1.0f / (f32) var_r29_158);
    this->unk50.unk30 = sp50;
    this->unk50.unk34 = sp54;
    this->unk50.unk38 = temp_f2_254;
    this->unk50.unk3C = 1.0f;
    temp_r4_260 = this->unk50.unk80;
    temp_r5_261 = this->unk50.unk88;
    sp58 = temp_f2_254;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    sp30 = sp10;
    sp18 = M2C_FIELD((M2C_BITWISE(s32, temp_r5_261) + ((temp_r31_152 - 1) * temp_r4_260)), f32 *, 8) - M2C_FIELD((M2C_BITWISE(s32, temp_r5_261) + ((temp_r31_152 - 2) * temp_r4_260)), f32 *, 8);
    sp20 = sp10;
    sp38 = (f64) sp18;
    sp28 = (f64) sp18;
    var_f4_288 = ((f32) sp38 * (f32) sp38) + (((f32) sp30 * (f32) sp30) + (unksp34 * unksp34));
    if (var_f4_288 > 0.0f) {
        temp_f1_291 = __frsqrte(var_f4_288);
        temp_f1_297 = 0.5 * temp_f1_291 * -(((f64) var_f4_288 * (temp_f1_291 * temp_f1_291)) - 3.0);
        temp_f1_301 = 0.5 * temp_f1_297 * -(((f64) var_f4_288 * (temp_f1_297 * temp_f1_297)) - 3.0);
        var_f4_288 = (f32) ((f64) var_f4_288 * (0.5 * temp_f1_301 * -(((f64) var_f4_288 * (temp_f1_301 * temp_f1_301)) - 3.0)));
    } else if (var_f4_288 < M2C_BITWISE(f32, 0.0)) {
        var_f4_288 = __float_nan;
    } else {
        sp8 = var_f4_288;
        temp_r3_320 = M2C_BITWISE(s32, sp8) & 0x7F800000;
        switch (temp_r3_320) {                      /* irregular */
        case 0x7F800000:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_330 = 1;
            } else {
                var_r0_330 = 2;
            }
            break;
        case 0x0:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_330 = 5;
            } else {
                var_r0_330 = 3;
            }
            break;
        default:
            var_r0_330 = 4;
            break;
        }
        if (var_r0_330 == 1) {
            var_f4_288 = __float_nan;
        }
    }
    this->unk108 = 0.5f * var_f4_288;
    this->unk50.unk50.Init(temp_r31_152, 0U);
    var_r29_358 = 0;
loop_25:
    if (var_r29_358 < temp_r31_152) {
        this->unk50.unk50.AddNode(*(M2C_BITWISE(s32, this->unk50.unk88) + (var_r29_358 * this->unk50.unk80)));
        var_r29_358 += 1;
        goto loop_25;
    }
    Reset();
    var_r29_376 = 0;
    var_r31_377 = 0;
loop_28:
    if (var_r29_376 < M2C_BITWISE(s32, this->unk50.unk40)) {
        temp_r3_381 = *(M2C_BITWISE(s32, this->unk50.unk4C) + var_r31_377);
        M2C_FIELD(M2C_FIELD(temp_r3_381, void **, 0x44), M2C_UNK (**)(void *), 0x34)(temp_r3_381);
        var_r29_376 += 1;
        var_r31_377 += 4;
        goto loop_28;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk40'
void TrapSpawnPool::LoadDone() {
    MKHeap *temp_r3_412;
    s32 temp_r31_411;
    s32 var_r30_426;
    s32 var_r31_427;
    void *var_r3_419;

    MKProp::LoadDone();
    temp_r31_411 = M2C_BITWISE(s32, this->unk50.unk40) * 4;
    temp_r3_412 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_412 != NULL) {
        var_r3_419 = ((MKHeap *) (temp_r3_412->Current()))->Alloc(temp_r31_411, NULL, 0);
    } else {
        var_r3_419 = malloc(temp_r31_411);
    }
    this->unk50.unk4C = M2C_BITWISE(f32, var_r3_419);
    var_r30_426 = 0;
    var_r31_427 = 0;
loop_5:
    if (var_r30_426 < M2C_BITWISE(s32, this->unk50.unk40)) {
        gMK->CreatePropDeferred(M2C_FIELD(checked_cast<TrapSpawnPoolDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s8 **, 0x60), M2C_BITWISE(s32, this->unk50.unk4C) + var_r31_427);
        var_r30_426 += 1;
        var_r31_427 += 4;
        goto loop_5;
    }
    this->unk50.unk64.LoadDone();
}
#endif

#if 0 // DRAFT: undefined identifier 'unk40'
s32 TrapSpawnPool::LoadLine(MKIniLine *arg0) {
    s32 var_r31_462;

    var_r31_462 = 0;
    if ((MKProp::LoadLine(arg0) != 0) || (arg0->LoadInt("numberInPool", (s32 *) &this->unk50.unk40, 0) != 0) || (arg0->LoadInt("timeComplete", &this->unk114, 0) != 0) || (arg0->LoadFloat("spawnTime", &this->unk50.unk48, 0) != 0) || (arg0->LoadFloat("bolFallSpeed", &this->unk118, 0) != 0) || (arg0->LoadFloat("bounceHeight", &this->unkFC, 0) != 0) || (arg0->LoadFloat("bounceLength", &this->unk100, 0) != 0) || (arg0->LoadFloat("bounceTime", &this->unkF8, 0) != 0) || (arg0->LoadFloat("bounceDropOff", &this->unk11C, 0) != 0) || (arg0->LoadFloat("scale", &this->unk104, 0) != 0) || (arg0->LoadVector3("dropPos", (MKVector3 *) &this->unkE8, 0) != 0) || (PropFlagsLoadLine((u32 *) &this->unk10, arg0) != 0) || (this->unk50.unk64.LoadLine(arg0) != 0)) {
        var_r31_462 = 1;
    }
    return var_r31_462;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk64'
void TrapSpawnPool::Deinit() {
    MKHeap *temp_r3_589;
    f32 temp_r31_588;

    this->unk50.unk64.Deinit();
    this->unk50.unk50.Deinit();
    temp_r31_588 = this->unk50.unk4C;
    temp_r3_589 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_589 != NULL) {
        ((MKHeap *) (temp_r3_589->Current()))->Free(M2C_BITWISE(void *, temp_r31_588), NULL, 0);
    } else {
        free(temp_r31_588);
    }
    MKProp::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'unk40'
void TrapSpawnPool::Init() {
    MKProp::Init();
    this->unk50.unk40 = 0.0f;
    this->unk50.unk44 = 0.0f;
    this->unk50.unk48 = 0.0f;
    this->unk50.unk64.Init();
    this->unk50.SetIdentity();
    this->unkFC = 0.0f;
    this->unk100 = 0.0f;
    this->unkF8 = 0.0f;
    this->unk104 = 1.0f;
    this->unk10C = 0.0f;
    this->unk108 = 0.0f;
    this->unk110 = 0;
    this->unkE8 = 0.0f;
    this->unkEC = 0.0f;
    this->unkF0 = 0.0f;
    PropFlagsInit((u32 *) &this->unk10, 0x160000U);
    this->unk8 = &this->unk50;
    this->unk114 = 0xA;
    this->unk118 = 600.0f;
    this->unk11C = 0.0f;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to
s32 TrapSpawnPoolDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_669;

    var_r31_669 = 0;
    if ((MKPropDescriptor::LoadLine(arg0) != 0) || (arg0->LoadBool("bRoll", (u8 *) &this->unk64, 0) != 0) || (arg0->LoadString("propName", &this->unk60, 0) != 0)) {
        var_r31_669 = 1;
    }
    return var_r31_669;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk70'
void TrapSpawnPoolDescriptor::Init() {
    MKPropDescriptor::Init();
    M2C_FIELD(this, f32 *, 0x70) = -1.0f;
    this->unk74 = -1.0f;
    this->unk78 = -1.0f;
    this->unk80 = 2.0f;
    this->unk84 = 2.0f;
    this->unk88 = 2.0f;
    this->unk1C = (BoundingVolume *) &this->unk70;
    this->unk60 = NULL;
    M2C_FIELD(this, s8 *, 0x64) = 0;
}
#endif
