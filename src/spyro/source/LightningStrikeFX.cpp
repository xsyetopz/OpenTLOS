#include "spyro/source/LightningStrikeFX.h"
#include "common/Source/Frustum.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/EmbersPS.h"
#include "spyro/source/LightManager.h"
#include "spyro/source/ManagedLight.h"
#include "spyro/source/ScreenWobbleFX.h"
#include "unplaced_templates.h"
#include "common/Source/MKView.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

M2C_UNK free(MKVector3 *);                          /* extern */
MKVector3 *malloc(s32);                             /* extern */
extern s32 GS_Lightning1;
extern s32 GS_Lightning2;
extern s32 GS_Lightning3;
extern M2C_UNK gEmptyPtrListDL;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern void **gb;

static s32 lit_549 = 0;
static u8 lit_550 = 1;

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
static s8 lit_stringBase0[0x14] = {
    0x53,
    0x74,
    0x72,
    0x69,
    0x6B,
    0x65,
    0x50,
    0x6F,
    0x69,
    0x6E,
    0x74,
    0x73,
    0,
    0x66,
    0x78,
    0x5F,
    0x33,
    0x35,
    0x31,
    0,
}; /* const */

void LightningStrikeFX::Strike() {
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    MKVector3 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    MKVector3 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f32 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA0;
    f32 sp90;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    LightningStrikeFXDescriptor *temp_r31_61;
    MKVector3 *temp_r4_182;
    MKVector3 *temp_r5_372;
    f32 temp_f1_231;
    f32 temp_f1_82;
    f32 var_f3_157;
    f32 var_f3_305;
    f32 var_f4_238;
    f32 var_f4_90;
    f64 temp_f1_102;
    f64 temp_f1_106;
    f64 temp_f1_244;
    f64 temp_f1_250;
    f64 temp_f1_254;
    f64 temp_f1_96;
    s32 temp_r29_368;
    s32 temp_r3_125;
    s32 temp_r3_273;
    s32 var_r0_135;
    s32 var_r0_283;
    s32 var_r28_209;
    s32 var_r28_361;

    temp_r31_61 = checked_cast<LightningStrikeFXDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    spC0 = -1.0f;
    spB0 = 1.0f;
    spB8 = -1.0f;
    spBC = 1.0f;
    spA8 = 1.0f;
    spAC = 2.0f;
    sp138 = (f64) spB8;
    sp140 = (f64) spC0;
    sp128 = (f64) spA8;
    sp130 = (f64) spB0;
    KDRand_Vector(sp148, *((MKVector3 *) &sp138));
    temp_f1_82 = M2C_BITWISE(f32, sp148);
    var_f4_90 = (sp148.unk8 * sp148.unk8) + ((temp_f1_82 * temp_f1_82) + (sp148.unk4 * sp148.unk4));
    if (var_f4_90 > 1e-12f) {
        if (var_f4_90 > 0.0f) {
            temp_f1_96 = __frsqrte(var_f4_90);
            temp_f1_102 = 0.5 * temp_f1_96 * -(((f64) var_f4_90 * (temp_f1_96 * temp_f1_96)) - 3.0);
            temp_f1_106 = 0.5 * temp_f1_102 * -(((f64) var_f4_90 * (temp_f1_102 * temp_f1_102)) - 3.0);
            var_f4_90 = (f32) ((f64) var_f4_90 * (0.5 * temp_f1_106 * -(((f64) var_f4_90 * (temp_f1_106 * temp_f1_106)) - 3.0)));
        } else if (var_f4_90 < M2C_BITWISE(f32, 0.0)) {
            var_f4_90 = __float_nan;
        } else {
            spC = var_f4_90;
            temp_r3_125 = M2C_BITWISE(s32, spC) & 0x7F800000;
            switch (temp_r3_125) {                  /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_135 = 1;
                } else {
                    var_r0_135 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_135 = 5;
                } else {
                    var_r0_135 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_135 = 4;
                break;
            }
            if (var_r0_135 == 1) {
                var_f4_90 = __float_nan;
            }
        }
        var_f3_157 = 1.0f / var_f4_90;
    } else {
        var_f3_157 = 0.0f;
    }
    sp78 = M2C_BITWISE(f32, sp148) * var_f3_157;
    sp7C = sp148.unk4 * var_f3_157;
    sp80 = sp148.unk8 * var_f3_157;
    sp158 = (f64) sp78;
    sp160 = (f64) sp80;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
    temp_r4_182 = this->unk4C;
    sp168 = sp98;
    spA0 = (f32) sp160 * 20000.0f;
    sp170 = (f64) spA0;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp178 = sp88;
    sp90 = temp_r4_182->unk8 + (f32) sp170;
    sp180 = (f64) sp90;
    temp_r31_61->SpawnStrikeArc(*temp_r4_182, *((MKVector3 *) &sp178), 5.0f, 0.25f);
    var_r28_209 = 0;
    do {
        sp70 = -1.0f;
        sp60 = 1.0f;
        sp68 = -1.0f;
        sp6C = -1.0f;
        sp58 = 1.0f;
        sp5C = 1.0f;
        spF8 = (f64) sp68;
        sp100 = (f64) sp70;
        spE8 = (f64) sp58;
        spF0 = (f64) sp60;
        KDRand_Vector(sp108, *((MKVector3 *) &spF8));
        temp_f1_231 = M2C_BITWISE(f32, sp108);
        var_f4_238 = (sp108.unk8 * sp108.unk8) + ((temp_f1_231 * temp_f1_231) + (sp108.unk4 * sp108.unk4));
        if (var_f4_238 > 1e-12f) {
            if (var_f4_238 > 0.0f) {
                temp_f1_244 = __frsqrte(var_f4_238);
                temp_f1_250 = 0.5 * temp_f1_244 * -(((f64) var_f4_238 * (temp_f1_244 * temp_f1_244)) - 3.0);
                temp_f1_254 = 0.5 * temp_f1_250 * -(((f64) var_f4_238 * (temp_f1_250 * temp_f1_250)) - 3.0);
                var_f4_238 = (f32) ((f64) var_f4_238 * (0.5 * temp_f1_254 * -(((f64) var_f4_238 * (temp_f1_254 * temp_f1_254)) - 3.0)));
            } else if (var_f4_238 < M2C_BITWISE(f32, 0.0)) {
                var_f4_238 = __float_nan;
            } else {
                sp8 = var_f4_238;
                temp_r3_273 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_273) {              /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_283 = 1;
                    } else {
                        var_r0_283 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_283 = 5;
                    } else {
                        var_r0_283 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_283 = 4;
                    break;
                }
                if (var_r0_283 == 1) {
                    var_f4_238 = __float_nan;
                }
            }
            var_f3_305 = 1.0f / var_f4_238;
        } else {
            var_f3_305 = 0.0f;
        }
        sp38 = M2C_BITWISE(f32, sp108) * var_f3_305;
        sp3C = sp108.unk4 * var_f3_305;
        sp40 = sp108.unk8 * var_f3_305;
        sp118 = (f64) sp38;
        sp120 = (f64) sp40;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
        sp188 = sp48;
        sp50 = (f32) sp120 * 800.0f;
        sp190 = (f64) sp50;
        sp30 = MKRand_Float(&gViewSeed, 0.75f, 1.0f);
        sp34 = 1.0f;
        sp28 = 0.75f;
        sp2C = 0.5f;
        spE0 = (f64) sp30;
        spD8 = (f64) sp28;
        sp10 = MKRand_Float(&gViewSeed, 10.0f, 20.0f);
        ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(*this->unk4C, *((MKVector3 *) &sp188), sp10, *((MKVector4 *) &spD8), -500.0f);
        var_r28_209 += 1;
    } while (var_r28_209 < 0x14);
    var_r28_361 = 0;
    do {
        temp_r29_368 = MKRand_Int(&gViewSeed, 0, this->unk50);
        temp_r5_372 = this->unk4C;
        temp_r31_61->SpawnStrikeArc(temp_r5_372[MKRand_Int(&gViewSeed, 0, this->unk50)], temp_r5_372[temp_r29_368], 3.0f, 0.125f);
        var_r28_361 += 1;
    } while (var_r28_361 < 3);
    this->unkC0 = 0.0f;
    this->unkC4 = 4.0f;
    if ((ManagedLight *) temp_r31_61->unk60 != NULL) {
        temp_r31_61->FlashLightningLight(*this->unk4C);
    }
    sp18 = 1.0f;
    sp1C = 0.7f;
    sp20 = 1.0f;
    sp24 = 1.0f;
    spC8 = (f64) sp18;
    spD0 = (f64) sp20;
    ((ScreenWobbleFX *) ((ScreenWobbleFX *) (&gb + 0xB8)))->EnableScreenFlash(*((MKVector4 *) &spC8), 3.0f * gUpdateTimeDelta);
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void LightningStrikeFX::Deinit() {
    MKHeap *temp_r3_443;
    MKVector3 *temp_r31_440;

    temp_r31_440 = this->unk4C;
    if (temp_r31_440 != NULL) {
        temp_r3_443 = MKHeap::Current();
        if (temp_r3_443 != NULL) {
            ((MKHeap *) (temp_r3_443->Current()))->Free(temp_r31_440, NULL, 0);
        } else {
            free(temp_r31_440);
        }
    }
    MKProp::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'P27LightningStrikeFXDescriptor'
void LightningStrikeFX::Draw() {
    ((LightningStrikeFXDescriptor *) (checked_cast<P27LightningStrikeFXDescriptor))->DrawStrikeArcs(16MKPropDescriptor>__FP16MKPropDescriptor((MKPropDescriptor *) this->unk0));
}
#endif

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void LightningStrikeFX::Update() {
    MKVector3 *temp_r5_543;
    f32 temp_f31_515;
    f32 var_f0_495;
    s32 temp_r30_536;
    s32 temp_r31_540;

    this->unkC4 -= gUpdateTimeDelta;
    var_f0_495 = this->unkC4;
    if (var_f0_495 < 4.0f) {

    } else {
        var_f0_495 = 4.0f;
    }
    if (var_f0_495 > 0.0f) {

    } else {
        var_f0_495 = 0.0f;
    }
    this->unkC4 = var_f0_495;
    this->unkC0 -= gUpdateTimeDelta;
    temp_f31_515 = this->unkC4;
    if (temp_f31_515 > 0.0f) {
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (this->unkC0 == 0.0f) {
            this->unkC0 = -((temp_f31_515 * 0.25f) - 1.0f) * MKRand_Float(&gViewSeed, 0.5f, 1.0f);
            temp_r30_536 = MKRand_Int(&gViewSeed, 0, this->unk50);
            temp_r31_540 = MKRand_Int(&gViewSeed, 0, this->unk50);
            temp_r5_543 = this->unk4C;
            ((LightningStrikeFXDescriptor *) (checked_cast<P27LightningStrikeFXDescriptor))->SpawnStrikeArc(*(16MKPropDescriptor>__FP16MKPropDescriptor((MKPropDescriptor *) this->unk0)), temp_r5_543[temp_r31_540], &temp_r5_543[temp_r30_536], 2.0f, 0.125f);
        }
    }
}
#endif

#if 0 // DRAFT: identifier 'LightningStrikeFX::LoadDone()' redeclared
s32 LightningStrikeFX::LoadDone() {
    f32 temp_f3_673;
    f32 temp_f3_708;
    f32 temp_f6_680;
    f32 temp_f7_686;
    f32 temp_f8_714;
    f32 temp_f9_720;
    s32 var_r30_574;
    MKProp::LoadDone();
    var_r30_574 = 0;
    arg_sp60 = 1e11f;
    arg_sp64 = 1e11f;
    arg_sp68 = 1e11f;
    this->unk60 = (f64) arg_sp60;
    arg_sp58 = -1e11f;
    arg_sp50 = -1e11f;
    arg_sp54 = -1e11f;
    this->unk68 = (f64) arg_sp68;
    this->unk70 = (f64) arg_sp50;
    arg_spF0 = (f64) arg_sp60;
    arg_spF8 = (f64) arg_sp68;
    arg_spE0 = (f64) arg_sp50;
    arg_spE8 = (f64) arg_sp58;
    this->unk78 = (f64) arg_sp58;
loop_2:
    if (var_r30_574 < (s32) this->unk50) {
        Min(*((MKVector3 *) &arg_spD0), *((MKVector3 *) &this->unk60));
        this->unk60 = arg_spD0;
        this->unk68 = arg_spD8;
        Max(*((MKVector3 *) &arg_spC0), *((MKVector3 *) &this->unk70));
        var_r30_574 += 1;
        this->unk70 = arg_spC0;
        this->unk78 = arg_spC8;
        goto loop_2;
    }
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r29, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r29, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    arg_sp90 = arg_sp10;
    arg_sp18 = (f32) M2C_FIELD(this, f64 *, 0x78) - (f32) M2C_FIELD(this, f64 *, 0x68);
    arg_sp98 = (f64) arg_sp18;
    arg_spA0.operator*(0.5f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r29, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_spB0 = arg_sp40;
    arg_sp48 = (f32) M2C_FIELD(this, f64 *, 0x68) + arg_spA8;
    this->unkB0 = (f32) arg_spB0;
    arg_spB8 = (f64) arg_sp48;
    this->unkB4 = arg_spB4;
    this->unkB8 = (f32) arg_spB8;
    this->unkBC = 1.0f;
    M2C_STRUCT_COPY((s32) &arg_spFC + 4, (s32) (this + 0x7C) + 4, 0x40);
    arg_sp100.Inverse((Matrix *) &arg_sp100);
    temp_f3_673 = M2C_FIELD(this, f32 *, 0x64);
    temp_f6_680 = (f32) M2C_FIELD(this, f64 *, 0x60);
    temp_f7_686 = (f32) M2C_FIELD(this, f64 *, 0x68);
    arg_sp30 = arg_sp130 + ((temp_f7_686 * arg_sp120) + ((temp_f6_680 * arg_sp100) + (temp_f3_673 * arg_sp110)));
    arg_sp34 = arg_sp134 + ((temp_f7_686 * arg_sp124) + ((temp_f6_680 * arg_sp104) + (temp_f3_673 * arg_sp114)));
    arg_sp38 = arg_sp138 + ((temp_f7_686 * arg_sp128) + ((temp_f6_680 * arg_sp108) + (temp_f3_673 * arg_sp118)));
    this->unk60 = (f64) arg_sp30;
    this->unk68 = (f64) arg_sp38;
    temp_f3_708 = M2C_FIELD(this, f32 *, 0x74);
    temp_f8_714 = (f32) M2C_FIELD(this, f64 *, 0x70);
    temp_f9_720 = (f32) M2C_FIELD(this, f64 *, 0x78);
    arg_sp80 = (f64) arg_sp30;
    arg_sp20 = arg_sp130 + ((temp_f9_720 * arg_sp120) + ((temp_f8_714 * arg_sp100) + (temp_f3_708 * arg_sp110)));
    arg_sp24 = arg_sp134 + ((temp_f9_720 * arg_sp124) + ((temp_f8_714 * arg_sp104) + (temp_f3_708 * arg_sp114)));
    arg_sp28 = arg_sp138 + ((temp_f9_720 * arg_sp128) + ((temp_f8_714 * arg_sp108) + (temp_f3_708 * arg_sp118)));
    this->unk70 = (f64) arg_sp20;
    this->unk78 = (f64) arg_sp28;
    arg_sp88 = (f64) arg_sp38;
    arg_sp70 = (f64) arg_sp20;
    arg_sp78 = (f64) arg_sp28;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r29, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r29, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    M2C_ERROR(/* unknown instruction: psq_stx $f0, $r29, $r3, 0x0, qr0 */);
    M2C_FIELD(this, f64 *, 0x78) = (f32) ((f32) M2C_FIELD(this, f64 *, 0x78) - (f32) M2C_FIELD(this, f64 *, 0x68));
    this->unkC = (BoundingVolume *) &this->unk60;
    return 0x70;
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_stringBase0'
s32 LightningStrikeFX::LoadLine(MKIniLine *arg0) {
    MKHeap *temp_r3_791;
    MKIniLine *var_r30_809;
    MKVector3 *temp_r5_815;
    MKVector3 *var_r3_798;
    s32 temp_r31_790;
    s32 temp_r3_787;
    s32 var_r31_808;

    if (MKProp::LoadLine(arg0) != 0) {
        return 1;
    }
    if (arg0->IsField(lit_stringBase0) != 0) {
        temp_r3_787 = arg0->GetNmbrOfSubLines();
        this->unk50 = temp_r3_787;
        temp_r31_790 = this->unk50 * 0x10;
        temp_r3_791 = temp_r3_787->Current();
        if (temp_r3_791 != NULL) {
            var_r3_798 = ((MKHeap *) (temp_r3_791->Current()))->Alloc(temp_r31_790, NULL, 0);
        } else {
            var_r3_798 = malloc(temp_r31_790);
        }
        this->unk4C = var_r3_798;
        var_r31_808 = 0;
        var_r30_809 = arg0->unkC->GetSubLine(arg0);
loop_8:
        if (var_r30_809 != NULL) {
            temp_r5_815 = this->unk4C + var_r31_808;
            var_r31_808 += 0x10;
            var_r30_809->AsVector3(0, temp_r5_815);
            var_r30_809 = var_r30_809->unkC->GetNextLine(var_r30_809);
            goto loop_8;
        }
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'identity'
void LightningStrikeFX::Init() {
    MKProp::Init();
    this->unk4C = NULL;
    this->unk50 = 0;
    M2C_STRUCT_COPY((s32) (this + 0x7C) + 4, (s32) (&identity - 4) + 4, 0x40);
    this->unk8 = &this->unk80;
    this->unkC4 = 0.0f;
    this->unkC0 = 0.0f;
}
#endif

void LightningStrikeFXDescriptor::FlashLightningLight(const MKVector3 &arg0) {
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    ManagedLight *temp_r3_896;
    ManagedLight *temp_r3_912;
    ManagedLight *temp_r4_884;
    f64 temp_f0_914;
    f64 temp_f1_913;
    void *temp_r3_904;
    void *temp_r3_917;

    this->unkA0 = 0.75f;
    temp_r4_884 = this->unk60;
    if (temp_r4_884 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_884, 1U);
        sp8 = 0.75f;
        temp_r3_896 = this->unk60;
        spC = 0.4f;
        sp10 = 1.0f;
        sp14 = 1.0f;
        temp_r3_896->unk20 = (f64) sp8;
        temp_r3_896->unk28 = (f64) sp10;
        temp_r3_904 = temp_r3_896->unk3C;
        sp18 = (f64) sp8;
        sp20 = (f64) sp10;
        if (temp_r3_904 != NULL) {
            M2C_FIELD(temp_r3_904, f64 *, 0) = (f64) sp8;
            M2C_FIELD(temp_r3_904, f64 *, 8) = (f64) sp10;
        }
        temp_r3_912 = this->unk60;
        temp_f1_913 = M2C_FIELD(&arg0, f64 *, 0);
        temp_f0_914 = M2C_FIELD(&arg0, f64 *, 8);
        temp_r3_912->unk10 = temp_f1_913;
        temp_r3_912->unk18 = temp_f0_914;
        temp_r3_917 = temp_r3_912->unk3C;
        if (temp_r3_917 != NULL) {
            M2C_FIELD(temp_r3_917, f64 *, 0x10) = temp_f1_913;
            M2C_FIELD(temp_r3_917, f64 *, 0x18) = temp_f0_914;
        }
    }
}

#if 0 // DRAFT: function call 'Normalise(MKVector3)' does not match
void LightningStrikeFXDescriptor::SpawnStrikeArc(const MKVector3 &arg0, const MKVector3 &arg1, float arg2, float arg3) {
    MKVector3 sp180;
    MKVector3 sp170;
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
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f32 sp98;
    f32 sp88;
    f32 sp78;
    f32 sp68;
    f32 sp58;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp18;
    f32 sp8;
    LightningStrikeFXDescriptor::StrikeArc **temp_r6_945;
    f32 temp_f1_1166;
    f32 temp_f1_1237;
    f32 var_f4_1012;
    f64 temp_f1_1015;
    f64 temp_f1_1021;
    f64 temp_f1_1025;
    s32 temp_r3_1044;
    s32 var_r0_1054;
    void *temp_r31_955;
    void *temp_r3_1138;
    void *temp_r3_1170;
    void *temp_r3_1209;
    void *temp_r3_1241;

    temp_r6_945 = this->unk98;
    if (((void *) M2C_FIELD(temp_r6_945, void **, -4) != NULL) && (this->unk98 = temp_r6_945 - 4, temp_r31_955 = M2C_FIELD(temp_r6_945, void **, -4), ((temp_r31_955 == NULL) == 0))) {
        M2C_FIELD(temp_r31_955, f64 *, 0x18) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r31_955, f64 *, 0x20) = (f64) M2C_FIELD(&arg0, f64 *, 8);
        sp38 = 1.0f;
        M2C_FIELD(temp_r31_955, f64 *, 0x28) = (f64) M2C_FIELD(&arg1, f64 *, 0);
        sp48 = -1.0f;
        M2C_FIELD(temp_r31_955, f64 *, 0x30) = (f64) M2C_FIELD(&arg1, f64 *, 8);
        sp30 = 1.0f;
        sp34 = 1.0f;
        sp40 = -1.0f;
        sp44 = -1.0f;
        sp150 = (f64) sp30;
        sp158 = (f64) sp38;
        sp160 = (f64) sp40;
        sp168 = (f64) sp48;
        KDRand_Vector(sp170, *((MKVector3 *) &sp160));
        Normalise(sp180);
        M2C_FIELD(temp_r31_955, f64 *, 0) = M2C_BITWISE(f64, sp180);
        M2C_FIELD(temp_r31_955, f64 *, 8) = (f64) sp180.unk8;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r29, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp140 = sp90;
        sp98 = arg1.unk8 - arg0.unk8;
        sp148 = (f64) sp98;
        var_f4_1012 = ((f32) sp148 * (f32) sp148) + (((f32) sp140 * (f32) sp140) + (unksp144 * unksp144));
        if (var_f4_1012 > 0.0f) {
            temp_f1_1015 = __frsqrte(var_f4_1012);
            temp_f1_1021 = 0.5 * temp_f1_1015 * -(((f64) var_f4_1012 * (temp_f1_1015 * temp_f1_1015)) - 3.0);
            temp_f1_1025 = 0.5 * temp_f1_1021 * -(((f64) var_f4_1012 * (temp_f1_1021 * temp_f1_1021)) - 3.0);
            var_f4_1012 = (f32) ((f64) var_f4_1012 * (0.5 * temp_f1_1025 * -(((f64) var_f4_1012 * (temp_f1_1025 * temp_f1_1025)) - 3.0)));
        } else if (var_f4_1012 < M2C_BITWISE(f32, 0.0)) {
            var_f4_1012 = __float_nan;
        } else {
            sp8 = var_f4_1012;
            temp_r3_1044 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_1044) {                 /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_1054 = 1;
                } else {
                    var_r0_1054 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_1054 = 5;
                } else {
                    var_r0_1054 = 3;
                }
                break;
            default:
                var_r0_1054 = 4;
                break;
            }
            if (var_r0_1054 == 1) {
                var_f4_1012 = __float_nan;
            }
        }
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r31, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r31, 0x0, qr0 */);
        M2C_FIELD(temp_r31_955, f64 *, 8) = (f32) ((f32) M2C_FIELD(temp_r31_955, f64 *, 8) * (200.0f * (var_f4_1012 / 1000.0f)));
        M2C_FIELD(temp_r31_955, f32 *, 0x4C) = arg3;
        M2C_FIELD(temp_r31_955, f32 *, 0x10) = arg3;
        M2C_FIELD(temp_r31_955, f32 *, 0x48) = arg2;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r29, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp120 = sp10;
        sp18 = arg1.unk8 + arg0.unk8;
        sp128 = (f64) sp18;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
        M2C_FIELD(temp_r31_955, f64 *, 0x38) = sp20;
        sp28 = (f32) sp128 * 0.5f;
        sp130 = sp20;
        sp138 = (f64) sp28;
        M2C_FIELD(temp_r31_955, f64 *, 0x40) = (f64) sp28;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (arg2 == 2.0f) {
            KDSound_Play3d(GS_Lightning3, temp_r31_955 + 0x38, 0U, -1, 0.0f, 0U);
            return;
        }
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (arg2 == 5.0f) {
            temp_r3_1138 = M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **), 0xC)(gb), void **, 8);
            spE0 = M2C_FIELD(temp_r3_1138, f64 *, 0x30);
            spE8 = M2C_FIELD(temp_r3_1138, f64 *, 0x38);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            spF0 = sp70;
            sp78 = (f32) spE8 - (f32) M2C_FIELD(temp_r31_955, f64 *, 0x20);
            spF8 = (f64) sp78;
            temp_f1_1166 = (f32) spF8 * (f32) spF8;
            temp_r3_1170 = M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **, f32, f32), 0xC)(gb, temp_f1_1166, (f32) spF8), void **, 8);
            sp100 = M2C_FIELD(temp_r3_1170, f64 *, 0x30);
            sp108 = M2C_FIELD(temp_r3_1170, f64 *, 0x38);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            sp110 = sp80;
            sp88 = (f32) sp108 - (f32) M2C_FIELD(temp_r31_955, f64 *, 0x40);
            sp118 = (f64) sp88;
            if ((((f32) sp118 * (f32) sp118) + (((f32) sp110 * (f32) sp110) + (unksp114 * unksp114))) > (temp_f1_1166 + (((f32) spF0 * (f32) spF0) + (unkspF4 * unkspF4)))) {
                M2C_FIELD(temp_r31_955, f64 *, 0x38) = (f64) M2C_FIELD(temp_r31_955, f64 *, 0x18);
                M2C_FIELD(temp_r31_955, f64 *, 0x40) = (f64) M2C_FIELD(temp_r31_955, f64 *, 0x20);
            }
            temp_r3_1209 = M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **), 0xC)(gb), void **, 8);
            spA0 = M2C_FIELD(temp_r3_1209, f64 *, 0x30);
            spA8 = M2C_FIELD(temp_r3_1209, f64 *, 0x38);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            spB0 = sp50;
            sp58 = (f32) spA8 - (f32) M2C_FIELD(temp_r31_955, f64 *, 0x30);
            spB8 = (f64) sp58;
            temp_f1_1237 = (f32) spB8 * (f32) spB8;
            temp_r3_1241 = M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **, f32, f32), 0xC)(gb, temp_f1_1237, (f32) spB8), void **, 8);
            spC0 = M2C_FIELD(temp_r3_1241, f64 *, 0x30);
            spC8 = M2C_FIELD(temp_r3_1241, f64 *, 0x38);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            spD0 = sp60;
            sp68 = (f32) spC8 - (f32) M2C_FIELD(temp_r31_955, f64 *, 0x40);
            spD8 = (f64) sp68;
            if ((((f32) spD8 * (f32) spD8) + (((f32) spD0 * (f32) spD0) + (unkspD4 * unkspD4))) > (temp_f1_1237 + (((f32) spB0 * (f32) spB0) + (unkspB4 * unkspB4)))) {
                M2C_FIELD(temp_r31_955, f64 *, 0x38) = (f64) M2C_FIELD(temp_r31_955, f64 *, 0x28);
                M2C_FIELD(temp_r31_955, f64 *, 0x40) = (f64) M2C_FIELD(temp_r31_955, f64 *, 0x30);
            }
            KDSound_Play3d(GS_Lightning1, temp_r31_955 + 0x38, 0U, -1, 0.0f, 0U);
            return;
        }
        KDSound_Play3d(GS_Lightning2, temp_r31_955 + 0x38, 0U, -1, 0.0f, 0U);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp2E0'
void LightningStrikeFXDescriptor::DrawStrikeArc(LightningStrikeFXDescriptor::StrikeArc *arg1) {
    f32 temp_f1_1379;
    f32 temp_f25_1818;
    f32 temp_f25_1882;
    f32 temp_f26_1740;
    f32 temp_f27_1367;
    f32 temp_f28_1780;
    f32 temp_f29_1783;
    f32 temp_f30_1782;
    f32 temp_f31_1755;
    f32 temp_f5_1337;
    f32 temp_f7_1722;
    f32 var_f3_1478;
    f32 var_f3_1584;
    f32 var_f4_1411;
    f32 var_f4_1517;
    f32 var_f4_1647;
    f32 var_f6_1714;
    f64 temp_f1_1417;
    f64 temp_f1_1423;
    f64 temp_f1_1427;
    f64 temp_f1_1523;
    f64 temp_f1_1529;
    f64 temp_f1_1533;
    f64 temp_f1_1653;
    f64 temp_f1_1659;
    f64 temp_f1_1663;
    s32 temp_r3_1446;
    s32 temp_r3_1552;
    s32 temp_r3_1682;
    s32 var_r0_1456;
    s32 var_r0_1562;
    s32 var_r0_1692;
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f3, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f0, $f3 */);
    temp_f5_1337 = M2C_FIELD(arg1, f32 *, 0x20);
    arg_sp2E0 = arg_sp1A0;
    arg_sp1A8 = M2C_FIELD(arg1, f32 *, 0x30) - temp_f5_1337;
    arg_sp2E8 = (f64) arg_sp1A8;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f2 */);
    arg_sp2F0 = arg_sp190;
    arg_sp198 = (f32) arg_sp2E8 * 0.5f;
    arg_sp2F8 = (f64) arg_sp198;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f3, $f0 */);
    arg_sp340 = arg_sp180;
    temp_f27_1367 = 1.0f - (M2C_FIELD(arg1, f32 *, 0x10) / M2C_FIELD(arg1, f32 *, 0x4C));
    arg_sp188 = temp_f5_1337 + (f32) arg_sp2F8;
    arg_sp348 = (f64) arg_sp188;
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r31, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    temp_f1_1379 = M2C_FIELD(arg1, f32 *, 8) * _table_sinf(6.2831855f * temp_f27_1367);
    arg_sp2D0 = arg_sp40;
    arg_sp48 = temp_f1_1379;
    arg_sp2D8 = (f64) arg_sp48;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp348 = (f32) arg_sp348 + (f32) arg_sp2D8;
    M2C_STRUCT_COPY((s32) &arg_sp34C + 4, MKView_GetCameraMatrix() - 4 + 4, 0x40);
    var_f4_1411 = (arg_sp358 * arg_sp358) + ((arg_sp350 * arg_sp350) + (arg_sp354 * arg_sp354));
    if (var_f4_1411 > 1e-12f) {
        if (var_f4_1411 > 0.0f) {
            temp_f1_1417 = __frsqrte(var_f4_1411);
            temp_f1_1423 = 0.5 * temp_f1_1417 * -(((f64) var_f4_1411 * (temp_f1_1417 * temp_f1_1417)) - 3.0);
            temp_f1_1427 = 0.5 * temp_f1_1423 * -(((f64) var_f4_1411 * (temp_f1_1423 * temp_f1_1423)) - 3.0);
            var_f4_1411 = (f32) ((f64) var_f4_1411 * (0.5 * temp_f1_1427 * -(((f64) var_f4_1411 * (temp_f1_1427 * temp_f1_1427)) - 3.0)));
        } else if (var_f4_1411 < M2C_BITWISE(f32, 0.0)) {
            var_f4_1411 = __float_nan;
        } else {
            arg_sp18 = var_f4_1411;
            temp_r3_1446 = M2C_BITWISE(s32, arg_sp18) & 0x7F800000;
            switch (temp_r3_1446) {                 /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, arg_sp18) & 0x7FFFFF) {
                    var_r0_1456 = 1;
                } else {
                    var_r0_1456 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, arg_sp18) & 0x7FFFFF) {
                    var_r0_1456 = 5;
                } else {
                    var_r0_1456 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_1456 = 4;
                break;
            }
            if (var_r0_1456 == 1) {
                var_f4_1411 = __float_nan;
            }
        }
        var_f3_1478 = 1.0f / var_f4_1411;
    } else {
        var_f3_1478 = 0.0f;
    }
    arg_sp170 = arg_sp350 * var_f3_1478;
    arg_sp174 = arg_sp354 * var_f3_1478;
    arg_sp178 = arg_sp358 * var_f3_1478;
    arg_sp320 = (f64) arg_sp170;
    arg_sp328 = (f64) arg_sp178;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    arg_sp2C0 = arg_sp160;
    arg_sp168 = M2C_FIELD(arg1, f32 *, 0x30) - M2C_FIELD(arg1, f32 *, 0x20);
    arg_sp2C8 = (f64) arg_sp168;
    var_f4_1517 = ((f32) arg_sp2C8 * (f32) arg_sp2C8) + (((f32) arg_sp2C0 * (f32) arg_sp2C0) + (arg_sp2C4 * arg_sp2C4));
    if (var_f4_1517 > 1e-12f) {
        if (var_f4_1517 > 0.0f) {
            temp_f1_1523 = __frsqrte(var_f4_1517);
            temp_f1_1529 = 0.5 * temp_f1_1523 * -(((f64) var_f4_1517 * (temp_f1_1523 * temp_f1_1523)) - 3.0);
            temp_f1_1533 = 0.5 * temp_f1_1529 * -(((f64) var_f4_1517 * (temp_f1_1529 * temp_f1_1529)) - 3.0);
            var_f4_1517 = (f32) ((f64) var_f4_1517 * (0.5 * temp_f1_1533 * -(((f64) var_f4_1517 * (temp_f1_1533 * temp_f1_1533)) - 3.0)));
        } else if (var_f4_1517 < M2C_BITWISE(f32, 0.0)) {
            var_f4_1517 = __float_nan;
        } else {
            arg_sp14 = var_f4_1517;
            temp_r3_1552 = M2C_BITWISE(s32, arg_sp14) & 0x7F800000;
            switch (temp_r3_1552) {                 /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                    var_r0_1562 = 1;
                } else {
                    var_r0_1562 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                    var_r0_1562 = 5;
                } else {
                    var_r0_1562 = 3;
                }
                break;
            default:                                /* switch 2 */
                var_r0_1562 = 4;
                break;
            }
            if (var_r0_1562 == 1) {
                var_f4_1517 = __float_nan;
            }
        }
        var_f3_1584 = 1.0f / var_f4_1517;
    } else {
        var_f3_1584 = 0.0f;
    }
    arg_sp154 = arg_sp2C4 * var_f3_1584;
    arg_sp150 = (f32) arg_sp2C0 * var_f3_1584;
    arg_sp158 = (f32) arg_sp2C8 * var_f3_1584;
    arg_sp310 = (f64) arg_sp150;
    arg_sp318 = (f64) arg_sp158;
    arg_sp38 = ((f32) arg_sp310 * arg_sp324) - (arg_sp314 * (f32) arg_sp320);
    arg_sp30 = (arg_sp314 * (f32) arg_sp328) - ((f32) arg_sp318 * arg_sp324);
    arg_sp34 = ((f32) arg_sp318 * (f32) arg_sp320) - ((f32) arg_sp310 * (f32) arg_sp328);
    arg_sp338 = (f64) arg_sp38;
    arg_sp330 = (f64) arg_sp30;
    arg_sp2B0 = (f64) arg_sp30;
    arg_sp2B8 = (f64) arg_sp38;
    arg_sp24 = ((f32) arg_sp318 * (f32) arg_sp330) - ((f32) arg_sp310 * (f32) arg_sp338);
    arg_sp20 = (arg_sp314 * (f32) arg_sp338) - ((f32) arg_sp318 * arg_sp334);
    arg_sp28 = ((f32) arg_sp310 * arg_sp334) - (arg_sp314 * (f32) arg_sp330);
    arg_sp330 = (f64) arg_sp20;
    arg_sp338 = (f64) arg_sp28;
    arg_sp2A0 = (f64) arg_sp20;
    arg_sp2A8 = (f64) arg_sp28;
    var_f4_1647 = ((f32) arg_sp338 * (f32) arg_sp338) + (((f32) arg_sp330 * (f32) arg_sp330) + (arg_sp334 * arg_sp334));
    if (var_f4_1647 > 0.000001f) {
        if (var_f4_1647 > 0.0f) {
            temp_f1_1653 = __frsqrte(var_f4_1647);
            temp_f1_1659 = 0.5 * temp_f1_1653 * -(((f64) var_f4_1647 * (temp_f1_1653 * temp_f1_1653)) - 3.0);
            temp_f1_1663 = 0.5 * temp_f1_1659 * -(((f64) var_f4_1647 * (temp_f1_1659 * temp_f1_1659)) - 3.0);
            var_f4_1647 = (f32) ((f64) var_f4_1647 * (0.5 * temp_f1_1663 * -(((f64) var_f4_1647 * (temp_f1_1663 * temp_f1_1663)) - 3.0)));
        } else if (var_f4_1647 < M2C_BITWISE(f32, 0.0)) {
            var_f4_1647 = __float_nan;
        } else {
            arg_sp10 = var_f4_1647;
            temp_r3_1682 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
            switch (temp_r3_1682) {                 /* switch 3; irregular */
            case 0x7F800000:                        /* switch 3 */
                if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                    var_r0_1692 = 1;
                } else {
                    var_r0_1692 = 2;
                }
                break;
            case 0x0:                               /* switch 3 */
                if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                    var_r0_1692 = 5;
                } else {
                    var_r0_1692 = 3;
                }
                break;
            default:                                /* switch 3 */
                var_r0_1692 = 4;
                break;
            }
            if (var_r0_1692 == 1) {
                var_f4_1647 = __float_nan;
            }
        }
        var_f6_1714 = 1.0f / var_f4_1647;
    } else {
        var_f6_1714 = 0.0f;
    }
    temp_f7_1722 = 1.0f - temp_f27_1367;
    arg_sp14C = 1.0f;
    arg_sp148 = temp_f7_1722;
    arg_sp140 = temp_f7_1722;
    arg_sp144 = temp_f7_1722;
    arg_sp308 = (f64) arg_sp148;
    arg_sp300 = (f64) arg_sp140;
    arg_sp330 = (f32) arg_sp330 * var_f6_1714;
    temp_f26_1740 = 30.000002f * M2C_FIELD(arg1, f32 *, 0x48);
    arg_sp334 *= var_f6_1714;
    arg_sp338 = (f32) arg_sp338 * var_f6_1714;
    MKBegin(6);
    MKSetColorV(*((MKVector4 *) &arg_sp300));
    MKSetTexCoord1F(0.0f, 0.0f);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
    temp_f31_1755 = (f32) arg_sp338 * temp_f26_1740;
    arg_sp280 = arg_sp130;
    arg_sp138 = temp_f31_1755;
    arg_sp288 = (f64) arg_sp138;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp290 = arg_sp120;
    arg_sp128 = M2C_FIELD(arg1, f32 *, 0x20) + (f32) arg_sp288;
    arg_sp298 = (f64) arg_sp128;
    MKSetPositionV(*((MKVector3 *) &arg_sp290));
    MKSetColorV(*((MKVector4 *) &arg_sp300));
    MKSetTexCoord1F(1.0f, 0.0f);
    temp_f28_1780 = -(f32) arg_sp338;
    temp_f30_1782 = -(f32) arg_sp330;
    temp_f29_1783 = -arg_sp334;
    arg_sp118 = temp_f28_1780;
    arg_sp110 = temp_f30_1782;
    arg_sp114 = temp_f29_1783;
    arg_sp258 = (f64) arg_sp118;
    arg_sp250 = (f64) arg_sp110;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
    arg_sp260 = arg_sp100;
    arg_sp108 = (f32) arg_sp258 * temp_f26_1740;
    arg_sp268 = (f64) arg_sp108;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp270 = arg_spF0;
    arg_spF8 = M2C_FIELD(arg1, f32 *, 0x20) + (f32) arg_sp268;
    arg_sp278 = (f64) arg_spF8;
    MKSetPositionV(*((MKVector3 *) &arg_sp270));
    temp_f25_1818 = 0.0f + 1.0f;
    MKSetColorV(*((MKVector4 *) &arg_sp300));
    MKSetTexCoord1F(0.0f, temp_f25_1818);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
    arg_spE8 = temp_f31_1755;
    arg_sp230 = arg_spE0;
    arg_sp238 = (f64) arg_spE8;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp240 = arg_spD0;
    arg_spD8 = (f32) arg_sp348 + (f32) arg_sp238;
    arg_sp248 = (f64) arg_spD8;
    MKSetPositionV(*((MKVector3 *) &arg_sp240));
    MKSetColorV(*((MKVector4 *) &arg_sp300));
    MKSetTexCoord1F(1.0f, temp_f25_1818);
    arg_spC0 = temp_f30_1782;
    arg_spC4 = temp_f29_1783;
    arg_spC8 = temp_f28_1780;
    arg_sp200 = (f64) arg_spC0;
    arg_sp208 = (f64) arg_spC8;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
    arg_sp210 = arg_spB0;
    arg_spB8 = (f32) arg_sp208 * temp_f26_1740;
    arg_sp218 = (f64) arg_spB8;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp220 = arg_spA0;
    arg_spA8 = (f32) arg_sp348 + (f32) arg_sp218;
    arg_sp228 = (f64) arg_spA8;
    MKSetPositionV(*((MKVector3 *) &arg_sp220));
    temp_f25_1882 = temp_f25_1818 + 1.0f;
    MKSetColorV(*((MKVector4 *) &arg_sp300));
    MKSetTexCoord1F(0.0f, temp_f25_1882);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
    arg_sp98 = temp_f31_1755;
    arg_sp1E0 = arg_sp90;
    arg_sp1E8 = (f64) arg_sp98;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp1F0 = arg_sp80;
    arg_sp88 = M2C_FIELD(arg1, f32 *, 0x30) + (f32) arg_sp1E8;
    arg_sp1F8 = (f64) arg_sp88;
    MKSetPositionV(*((MKVector3 *) &arg_sp1F0));
    MKSetColorV(*((MKVector4 *) &arg_sp300));
    MKSetTexCoord1F(1.0f, temp_f25_1882);
    arg_sp70 = temp_f30_1782;
    arg_sp74 = temp_f29_1783;
    arg_sp78 = temp_f28_1780;
    arg_sp1B0 = (f64) arg_sp70;
    arg_sp1B8 = (f64) arg_sp78;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
    arg_sp1C0 = arg_sp60;
    arg_sp68 = (f32) arg_sp1B8 * temp_f26_1740;
    arg_sp1C8 = (f64) arg_sp68;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp1D0 = arg_sp50;
    arg_sp58 = M2C_FIELD(arg1, f32 *, 0x30) + (f32) arg_sp1C8;
    arg_sp1D8 = (f64) arg_sp58;
    MKSetPositionV(*((MKVector3 *) &arg_sp1D0));
    MKEnd();
}
#endif

#if 0 // DRAFT: undefined identifier 'identity'
void LightningStrikeFXDescriptor::DrawStrikeArcs() {
    LightningStrikeFXDescriptor::StrikeArc **var_r31_1989;
    LightningStrikeFXDescriptor::StrikeArc *temp_r4_1998;

    if ((u8) this->unk9C == 0) {
        MKMaterial_SetMaterial(this->unk94);
        MKPrimitive(0xC, 0);
        MKSetMatrix(identity);
        var_r31_1989 = this->unk98;
loop_3:
        if (var_r31_1989 != NULL) {
            temp_r4_1998 = *var_r31_1989;
            if (temp_r4_1998 != NULL) {
                DrawStrikeArc(temp_r4_1998);
                var_r31_1989 += 4;
                goto loop_3;
            }
        }
        MKEndPrimitive();
        this->unk9C = 1;
    }
}
#endif

#if 0 // DRAFT: type mismatch
void LightningStrikeFXDescriptor::Deinit() {
    LightningStrikeFXDescriptor::StrikeArc **var_r31_2039;
    LightningStrikeFXDescriptor::StrikeArc **var_r3_2040;
    LightningStrikeFXDescriptor::StrikeArc **var_r4_2038;
    LightningStrikeFXDescriptor::StrikeArc *temp_r0_2043;
    LightningStrikeFXDescriptor::StrikeArc *temp_r0_2062;
    MKHeap *temp_r3_2065;
    MKMaterial *temp_r3_2021;
    ManagedLight *temp_r4_2028;
    u32 temp_r0_2048;

    temp_r3_2021 = this->unk94;
    if (temp_r3_2021 != NULL) {
        MKMaterial_Destroy(temp_r3_2021);
        this->unk94 = NULL;
    }
    temp_r4_2028 = this->unk60;
    if (temp_r4_2028 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->FreeManagedLight(temp_r4_2028);
        this->unk60 = NULL;
    }
    var_r4_2038 = this->unk98;
    var_r31_2039 = var_r4_2038;
    var_r3_2040 = var_r4_2038;
loop_7:
    temp_r0_2048 = M2C_FIELD(var_r3_2040, u32 *, -4);
    var_r3_2040 -= 4;
    if (temp_r0_2048 != 0U) {
        temp_r0_2043 = *var_r3_2040;
        if (temp_r0_2043 < var_r31_2039) {
            var_r31_2039 = (LightningStrikeFXDescriptor::StrikeArc **) temp_r0_2043;
        }
        goto loop_7;
    }
    if (var_r3_2040 != &gEmptyPtrListDL) {
loop_13:
        temp_r0_2062 = *var_r4_2038;
        if (temp_r0_2062 != NULL) {
            if (temp_r0_2062 < var_r31_2039) {
                var_r31_2039 = (LightningStrikeFXDescriptor::StrikeArc **) temp_r0_2062;
            }
            var_r4_2038 += 4;
            goto loop_13;
        }
        temp_r3_2065 = var_r3_2040->Current();
        if (temp_r3_2065 != NULL) {
            ((MKHeap *) (temp_r3_2065->Current()))->Free(var_r31_2039, NULL, 0);
        } else {
            free((MKVector3 *) var_r31_2039);
        }
    }
    this->unk98 = NULL;
    MKPropDescriptor::Deinit();
}
#endif

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void LightningStrikeFXDescriptor::Update() {
    Frustum sp28;
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    LightningStrikeFXDescriptor::StrikeArc **temp_r3_2113;
    LightningStrikeFXDescriptor::StrikeArc **var_r5_2102;
    LightningStrikeFXDescriptor::StrikeArc *temp_r3_2125;
    LightningStrikeFXDescriptor::StrikeArc *temp_r4_2116;
    ManagedLight *temp_r3_2177;
    ManagedLight *temp_r4_2149;
    f32 temp_f1_2169;
    f32 temp_f2_2152;
    f32 temp_f31_2167;
    f32 var_f0_2134;
    s32 var_r28_2208;
    s32 var_r30_2209;
    void *temp_r3_2188;
    void *var_r27_2218;

    this->unk9C = 0;
    var_r5_2102 = this->unk98;
loop_4:
    if (var_r5_2102 != NULL) {
        temp_r3_2125 = *var_r5_2102;
        if (temp_r3_2125 != NULL) {
            M2C_FIELD(temp_r3_2125, f32 *, 0x10) = (f32) (M2C_FIELD(temp_r3_2125, f32 *, 0x10) - gUpdateTimeDelta);
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (M2C_FIELD(temp_r3_2125, f32 *, 0x10) == 0.0f) {
                temp_r3_2113 = this->unk98;
                this->unk98 = temp_r3_2113 + 4;
                temp_r4_2116 = *temp_r3_2113;
                *temp_r3_2113 = *var_r5_2102;
                *var_r5_2102 = temp_r4_2116;
            }
            var_r5_2102 += 4;
            goto loop_4;
        }
    }
    this->unkA0 -= gUpdateTimeDelta;
    var_f0_2134 = this->unkA0;
    if (var_f0_2134 < 0.75f) {

    } else {
        var_f0_2134 = 0.75f;
    }
    if (var_f0_2134 > 0.0f) {

    } else {
        var_f0_2134 = 0.0f;
    }
    this->unkA0 = var_f0_2134;
    temp_r4_2149 = this->unk60;
    if (temp_r4_2149 != NULL) {
        temp_f2_2152 = this->unkA0;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (temp_f2_2152 == 0.0f) {
            ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_2149, 0U);
        } else {
            temp_f31_2167 = temp_f2_2152 / 0.75f;
            temp_f1_2169 = MKRand_Float(&gViewSeed, 0.1f, 1.0f);
            sp10 = temp_f31_2167 * temp_f1_2169;
            temp_r3_2177 = this->unk60;
            sp14 = 1.0f;
            sp8 = 0.75f * temp_f31_2167 * temp_f1_2169;
            spC = 0.4f * temp_f31_2167 * temp_f1_2169;
            sp20 = (f64) sp10;
            temp_r3_2177->unk20 = (f64) sp8;
            temp_r3_2177->unk28 = (f64) sp10;
            temp_r3_2188 = temp_r3_2177->unk3C;
            sp18 = (f64) sp8;
            if (temp_r3_2188 != NULL) {
                M2C_FIELD(temp_r3_2188, f64 *, 0) = (f64) sp8;
                M2C_FIELD(temp_r3_2188, f64 *, 8) = (f64) sp10;
            }
        }
    }
    this->unk90 -= gUpdateTimeDelta;
    if (!(this->unk90 > 0.0f)) {
        var_r28_2208 = 0;
        var_r30_2209 = 0;
        M2C_STRUCT_COPY((s32) &unksp24 + 4, M2C_FIELD(&gb, s32 *, 0x3B8) + 0xAC + 4, 0x70);
        var_r27_2218 = this->unk28;
loop_22:
        if (var_r27_2218 != NULL) {
            if ((sp28.IsVisible(M2C_FIELD(var_r27_2218, Matrix **, 8), M2C_FIELD(var_r27_2218, BoundingVolume **, 0xC)) == 0) || (var_r28_2208 += 1, *(&sp98[0] + var_r30_2209) = var_r27_2218, var_r30_2209 += 4, ((var_r28_2208 < 0xA) != 0))) {
                var_r27_2218 = M2C_FIELD(var_r27_2218, void **, 0x38);
                goto loop_22;
            }
        }
        if ((var_r28_2208 != 0) && ((s32) this->unkA4 > 0xA)) {
            ((LightningStrikeFX *) (checked_cast<P17LightningStrikeFX))->Strike(6MKProp>__FP6MKProp((&sp98[0])[MKRand_Int(&gViewSeed, 0, var_r28_2208)]));
            this->unk90 = MKRand_Float(&gViewSeed, 4.0f, 5.0f);
        }
        this->unkA4 += 1;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void LightningStrikeFXDescriptor::Resolve() {
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    ManagedLight *temp_r4_2318;

    MKPropDescriptor::Resolve();
    sp20 = 0.0f;
    sp30 = 0.0f;
    sp8 = 0.75f;
    spC = 0.4f;
    sp10 = 1.0f;
    sp14 = 1.0f;
    sp18 = 0.0f;
    sp1C = 0.0f;
    sp28 = 0.0f;
    sp2C = 0.0f;
    sp38 = (f64) sp8;
    sp40 = (f64) sp10;
    sp48 = (f64) sp18;
    sp50 = (f64) sp20;
    sp58 = (f64) sp28;
    sp60 = (f64) sp30;
    this->unk60 = ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->AllocManagedLight(*((MKVector3 *) &sp58), *((MKVector3 *) &sp48), *((MKVector4 *) &sp38), 10000.0f, lit_549, lit_550);
    temp_r4_2318 = this->unk60;
    if (temp_r4_2318 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_2318, 0U);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'zero'
void LightningStrikeFXDescriptor::Init() {
    LightningStrikeFXDescriptor::StrikeArc **temp_r3_2383;
    LightningStrikeFXDescriptor::StrikeArc **temp_r3_2389;
    LightningStrikeFXDescriptor::StrikeArc **var_r5_2377;
    MKHeap *temp_r3_2361;
    MKMaterial *temp_r3_2359;
    MKVector3 *var_r3_2368;
    s32 var_ctr_2381;

    MKPropDescriptor::Init();
    this->unk60 = NULL;
    M2C_FIELD(this, f64 *, 0x70) = (f64) M2C_FIELD(&zero, f64 *, 0);
    this->unk78 = M2C_FIELD(&zero, f64 *, 8);
    this->unk80 = M2C_FIELD(&zero, f64 *, 0);
    this->unk88 = M2C_FIELD(&zero, f64 *, 8);
    this->unk1C = (BoundingVolume *) &this->unk70;
    this->unk90 = 0.0f;
    this->unkA4 = 0;
    temp_r3_2359 = MKMaterial_Create(&lit_stringBase0[0xD]);
    this->unk94 = temp_r3_2359;
    temp_r3_2361 = temp_r3_2359->Current();
    if (temp_r3_2361 != NULL) {
        var_r3_2368 = ((MKHeap *) (temp_r3_2361->Current()))->Alloc(0x698, NULL, 0);
    } else {
        var_r3_2368 = malloc(0x698);
    }
    this->unk98 = (LightningStrikeFXDescriptor::StrikeArc **) var_r3_2368;
    var_r5_2377 = this->unk98;
    this->unk98 = var_r5_2377 + 0x640;
    M2C_FIELD(var_r5_2377, s32 *, 0x640) = 0;
    var_ctr_2381 = 0x14;
    do {
        temp_r3_2383 = this->unk98;
        this->unk98 = temp_r3_2383 + 4;
        M2C_FIELD(temp_r3_2383, LightningStrikeFXDescriptor::StrikeArc ***, 4) = var_r5_2377;
        var_r5_2377 += 0x50;
        var_ctr_2381 -= 1;
    } while (var_ctr_2381 != 0);
    temp_r3_2389 = this->unk98;
    this->unk98 = temp_r3_2389 + 4;
    M2C_FIELD(temp_r3_2389, LightningStrikeFXDescriptor::StrikeArc ***, 4) = NULL;
    this->unk9C = 0;
    this->unkA0 = 0.0f;
}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<LightningStrikeFX *, MKProp>(MKProp *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<LightningStrikeFXDescriptor *, MKPropDescriptor>(MKPropDescriptor *arg0) {

}
#endif
