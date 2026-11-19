#include "spyro/source/PuddleSplash.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(M2C_UNK);                              /* extern */
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;

void PuddleSplash::Deinit() {
    MKHeap *temp_r3_50;
    void *temp_r31_47;

    MKProp::Deinit();
    temp_r31_47 = this->unk4C;
    if (temp_r31_47 != NULL) {
        temp_r3_50 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_50 != NULL) {
            ((MKHeap *) (temp_r3_50->Current()))->Free(temp_r31_47, NULL, 0);
        } else {
            free(temp_r31_47);
        }
        this->unk4C = NULL;
    }
}

#if 0 // DRAFT: undefined identifier 'arg_spA8'
void PuddleSplash::Draw() {
    MKMaterial *temp_r3_87;
    f32 temp_f1_315;
    f32 temp_f2_313;
    f32 temp_f31_295;
    f32 temp_f3_293;
    s32 var_r26_251;
    s32 var_r28_249;
    void *temp_r4_301;
    void *temp_r5_290;
    temp_r3_87 = M2C_FIELD(this->unk4C, MKMaterial **, 0x1C);
    if (temp_r3_87 != NULL) {
        MKMaterial_SetMaterial(temp_r3_87);
    }
    MKPrimitive(0xC, 0);
    arg_spA8 = 0.0f;
    arg_spA0 = 1.0f;
    arg_spA4 = 0.0f;
    arg_sp1E8 = (f64) arg_spA8;
    arg_sp1E0 = (f64) arg_spA0;
    arg_spB8 = 1.0f;
    arg_sp48 = -(f32) arg_sp1E8;
    arg_spB0 = 0.0f;
    arg_spB4 = 0.0f;
    arg_sp40 = -(f32) arg_sp1E0;
    arg_sp44 = -arg_sp1E4;
    arg_sp1F0 = (f64) arg_spB0;
    arg_sp1F8 = (f64) arg_spB8;
    arg_sp190 = (f64) arg_sp40;
    arg_sp198 = (f64) arg_sp48;
    arg_sp1A0.operator*(10.0f);
    arg_sp1B0.operator*(10.0f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp1C0 = arg_sp90;
    arg_sp98 = arg_sp1B8 + arg_sp1A8;
    arg_sp240 = arg_sp90;
    arg_sp1C8 = (f64) arg_sp98;
    arg_sp248 = (f64) arg_sp98;
    arg_sp160.operator*(10.0f);
    arg_sp170.operator*(10.0f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp38 = -(f32) arg_sp1E8;
    arg_sp88 = arg_sp178 + arg_sp168;
    arg_sp30 = -(f32) arg_sp1E0;
    arg_sp34 = -arg_sp1E4;
    arg_sp180 = arg_sp80;
    arg_sp188 = (f64) arg_sp88;
    arg_sp250 = arg_sp80;
    arg_sp258 = (f64) arg_sp88;
    arg_sp110 = (f64) arg_sp30;
    arg_sp118 = (f64) arg_sp38;
    arg_sp120.operator*(10.0f);
    arg_sp20 = -(f32) arg_sp1F0;
    arg_sp24 = -arg_sp1F4;
    arg_sp28 = -(f32) arg_sp1F8;
    arg_sp130 = (f64) arg_sp20;
    arg_sp138 = (f64) arg_sp28;
    arg_sp140.operator*(10.0f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp150 = arg_sp70;
    arg_sp78 = arg_sp148 + arg_sp128;
    arg_sp260 = arg_sp70;
    arg_sp158 = (f64) arg_sp78;
    arg_sp268 = (f64) arg_sp78;
    arg_spD0.operator*(10.0f);
    arg_sp10 = -(f32) arg_sp1F0;
    arg_sp14 = -arg_sp1F4;
    arg_sp18 = -(f32) arg_sp1F8;
    arg_spE0 = (f64) arg_sp10;
    arg_spE8 = (f64) arg_sp18;
    arg_spF0.operator*(10.0f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    var_r28_249 = 0;
    var_r26_251 = 0;
    arg_sp100 = arg_sp60;
    arg_sp68 = arg_spF8 + arg_spD8;
    arg_sp270 = arg_sp60;
    arg_sp108 = (f64) arg_sp68;
    arg_sp278 = (f64) arg_sp68;
    do {
        if ((u8) *(this->unk4C + (var_r26_251 + 0x20)) != 0) {
            MKEndPrimitive();
            MKMaterial_SetMaterial(*(this->unk4C + (var_r26_251 + 0x1C)));
            MKPrimitive(0xC, 0);
            M2C_STRUCT_COPY((s32) &arg_sp1FC + 4, (s32) (&identity - 4) + 4, 0x40);
            temp_r5_290 = this->unk4C + var_r26_251;
            temp_f3_293 = M2C_FIELD(temp_r5_290, f32 *, 0x10);
            temp_f31_295 = 1.0f - (M2C_FIELD(temp_r5_290, f32 *, 0x14) / M2C_FIELD(temp_r5_290, f32 *, 0x18));
            arg_sp200.Scale3x3((Matrix *) &arg_sp200, (temp_f31_295 * temp_f3_293) + temp_f3_293);
            temp_r4_301 = this->unk4C + var_r26_251;
            arg_sp230 = M2C_FIELD(temp_r4_301, f32 *, 0);
            arg_sp234 = M2C_FIELD(temp_r4_301, f32 *, 4);
            arg_sp238 = M2C_FIELD(temp_r4_301, f32 *, 8);
            arg_sp23C = 1.0f;
            MKSetMatrix(*((Matrix *) &arg_sp200));
            temp_f2_313 = 1.0f - temp_f31_295;
            arg_sp5C = 1.0f;
            temp_f1_315 = 0.8f * temp_f2_313;
            arg_sp58 = temp_f2_313;
            arg_sp50 = temp_f1_315;
            arg_sp54 = temp_f1_315;
            arg_spC8 = (f64) arg_sp58;
            arg_spC0 = (f64) arg_sp50;
            arg_sp1D0 = (f64) arg_sp50;
            arg_sp1D8 = (f64) arg_sp58;
            MKBegin(4);
            MKSetColorV(*((MKVector4 *) &arg_sp1D0));
            MKSetTexCoord1F(0.0f, 1.0f);
            MKSetPositionV(*((MKVector3 *) &arg_sp240));
            MKSetColorV(*((MKVector4 *) &arg_sp1D0));
            MKSetTexCoord1F(1.0f, 1.0f);
            MKSetPositionV(*((MKVector3 *) &arg_sp250));
            MKSetColorV(*((MKVector4 *) &arg_sp1D0));
            MKSetTexCoord1F(0.0f, 0.0f);
            MKSetPositionV(*((MKVector3 *) &arg_sp260));
            MKSetColorV(*((MKVector4 *) &arg_sp1D0));
            MKSetTexCoord1F(1.0f, 0.0f);
            MKSetPositionV(*((MKVector3 *) &arg_sp270));
            MKEnd();
        }
        var_r28_249 += 1;
        var_r26_251 += 0x28;
    } while (var_r28_249 < 0x64);
    MKEndPrimitive();
}
#endif

#if 0 // DRAFT: illegal type
void PuddleSplash::Emit(const MKVector3 &arg0, const float &arg1, bool arg2) {
    s32 temp_r29_429;
    s32 var_ctr_381;
    s32 var_r30_380;
    void *temp_r3_383;
    void *temp_r3_399;

    var_r30_380 = 0;
    var_ctr_381 = 0x64;
loop_1:
    temp_r3_383 = this->unk4C;
    if ((u8) *(temp_r3_383 + (var_r30_380 + 0x20)) == 0) {
        M2C_FIELD((temp_r3_383 + var_r30_380), s8 *, 0x20) = 1;
        M2C_FIELD((this->unk4C + var_r30_380), f32 *, 0x10) = (f32) &arg1;
        temp_r3_399 = this->unk4C + var_r30_380;
        M2C_FIELD(temp_r3_399, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r3_399, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
        if (arg2 != 0) {
            M2C_FIELD((this->unk4C + var_r30_380), f32 *, 0x18) = 3.0f;
            M2C_FIELD((this->unk4C + var_r30_380), f32 *, 0x14) = 3.0f;
            M2C_FIELD((this->unk4C + var_r30_380), s32 *, 0x1C) = (s32) M2C_FIELD(checked_cast<PuddleSplashDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x6C);
            return;
        }
        M2C_FIELD((this->unk4C + var_r30_380), f32 *, 0x18) = 0.35f;
        M2C_FIELD((this->unk4C + var_r30_380), f32 *, 0x14) = 0.35f;
        temp_r29_429 = MKRand_Int(&gViewSeed, 0, 3);
        M2C_FIELD((this->unk4C + var_r30_380), s32 *, 0x1C) = (s32) M2C_FIELD((checked_cast<PuddleSplashDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (temp_r29_429 * 4)), s32 *, 0x60);
        return;
    }
    var_r30_380 += 0x28;
    var_ctr_381 -= 1;
    if (var_ctr_381 == 0) {
        return;
    }
    goto loop_1;
}
#endif

#if 0 // DRAFT: illegal type
void PuddleSplash::Update() {
    s32 var_ctr_457;
    s32 var_r4_453;
    void *temp_r6_460;
    void *temp_r6_469;

    var_r4_453 = 0;
    var_ctr_457 = 0x64;
    do {
        temp_r6_460 = this->unk4C + var_r4_453;
        if ((u8) M2C_FIELD(temp_r6_460, u8 *, 0x20) != 0) {
            M2C_FIELD(temp_r6_460, f32 *, 0x14) = (f32) (M2C_FIELD(temp_r6_460, f32 *, 0x14) - gUpdateTimeDelta);
            temp_r6_469 = this->unk4C + var_r4_453;
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (M2C_FIELD(temp_r6_469, f32 *, 0x14) == 0.0f) {
                M2C_FIELD(temp_r6_469, s8 *, 0x20) = 0;
            }
        }
        var_r4_453 += 0x28;
        var_ctr_457 -= 1;
    } while (var_ctr_457 != 0);
}
#endif

#if 0 // DRAFT: illegal type
void PuddleSplash::LoadDone() {
    MKHeap *temp_r3_490;
    s32 temp_r0_512;
    s32 temp_r3_511;
    s32 var_ctr_508;
    s32 var_r4_503;
    void *var_r3_497;

    MKProp::LoadDone();
    temp_r3_490 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_490 != NULL) {
        var_r3_497 = ((MKHeap *) (temp_r3_490->Current()))->Alloc(0xFA0, NULL, 0);
    } else {
        var_r3_497 = malloc(0xFA0);
    }
    var_r4_503 = 0;
    this->unk4C = var_r3_497;
    var_ctr_508 = 0x64;
    do {
        temp_r3_511 = var_r4_503 + 0x20;
        temp_r0_512 = var_r4_503 + 0x1C;
        var_r4_503 += 0x28;
        *(this->unk4C + temp_r3_511) = 0;
        *(this->unk4C + temp_r0_512) = 0;
        var_ctr_508 -= 1;
    } while (var_ctr_508 != 0);
}
#endif

void PuddleSplash::Init() {
    MKProp::Init();
    this->unk4C = NULL;
}

#if 0 // DRAFT: function call 'MKMaterial_Destroy(PuddleSplashDescriptor)' does not match
void PuddleSplashDescriptor::Deinit() {
    s32 var_r30_552;
    s32 var_r31_553;

    MKPropDescriptor::Deinit();
    var_r30_552 = 0;
    var_r31_553 = 0;
    do {
        MKMaterial_Destroy(*(this + (var_r31_553 + 0x60)));
        var_r30_552 += 1;
        var_r31_553 += 4;
    } while (var_r30_552 < 4);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKResource *' to
void PuddleSplashDescriptor::Init() {
    MKPropDescriptor::Init();
    this->unk60 = MKMaterial_Create("fx_006");
    this->unk64 = MKMaterial_Create("fx_007");
    this->unk68 = MKMaterial_Create("fx_008");
    this->unk6C = MKMaterial_Create("fx_365");
}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<PuddleSplashDescriptor *, MKPropDescriptor>(MKPropDescriptor *arg0) {

}
#endif
