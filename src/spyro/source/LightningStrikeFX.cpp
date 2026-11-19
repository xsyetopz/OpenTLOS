#include "spyro/source/LightningStrikeFX.h"
#include "common/Source/Animation.h"
#include "common/Source/Frustum.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/EmbersPS.h"
#include "spyro/source/Level.h"
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
    f64 sp98;
    f32 sp90;
    f64 sp88;
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
    f64 sp48;
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
    f64 temp_f0_177;
    f64 temp_f0_189;
    f64 temp_f0_325;
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
    temp_f0_177 = sp158 * 5.852924563e-315;
    sp98 = temp_f0_177;
    temp_r4_182 = this->unk4C;
    sp168 = temp_f0_177;
    spA0 = (f32) sp160 * 20000.0f;
    sp170 = (f64) spA0;
    temp_f0_189 = M2C_FIELD(temp_r4_182, f64 *, 0) + temp_f0_177;
    sp88 = temp_f0_189;
    sp178 = temp_f0_189;
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
        temp_f0_325 = sp118 * 5.65986426e-315;
        sp48 = temp_f0_325;
        sp188 = temp_f0_325;
        sp50 = (f32) sp120 * 800.0f;
        sp190 = (f64) sp50;
        sp30 = MKRand_Float((int *) &gViewSeed, 0.75f, 1.0f);
        sp34 = 1.0f;
        sp28 = 0.75f;
        sp2C = 0.5f;
        spE0 = (f64) sp30;
        spD8 = (f64) sp28;
        sp10 = MKRand_Float((int *) &gViewSeed, 10.0f, 20.0f);
        ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(*this->unk4C, *((MKVector3 *) &sp188), sp10, *((MKVector4 *) &spD8), -500.0f);
        var_r28_209 += 1;
    } while (var_r28_209 < 0x14);
    var_r28_361 = 0;
    do {
        temp_r29_368 = MKRand_Int((int *) &gViewSeed, 0, this->unk50);
        temp_r5_372 = this->unk4C;
        temp_r31_61->SpawnStrikeArc(temp_r5_372[MKRand_Int((int *) &gViewSeed, 0, this->unk50)], temp_r5_372[temp_r29_368], 3.0f, 0.125f);
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
    ((ScreenWobbleFX *) (&gb + 0xB8))->EnableScreenFlash(*((MKVector4 *) &spC8), 3.0f * gUpdateTimeDelta);
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

#if 0 // DRAFT: undefined identifier 'P27LightningStrikeFXDescriptor'
void *LightningStrikeFX::Update() {
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
    if ((temp_f31_515 > 0.0f) && (this->unkC0 <= 0.0f)) {
        this->unkC0 = -((temp_f31_515 * 0.25f) - 1.0f) * MKRand_Float((int *) &gViewSeed, 0.5f, 1.0f);
        temp_r30_536 = MKRand_Int((int *) &gViewSeed, 0, this->unk50);
        temp_r31_540 = MKRand_Int((int *) &gViewSeed, 0, this->unk50);
        temp_r5_543 = this->unk4C;
        ((LightningStrikeFXDescriptor *) (checked_cast<P27LightningStrikeFXDescriptor))->SpawnStrikeArc(*(16MKPropDescriptor>__FP16MKPropDescriptor((MKPropDescriptor *) this->unk0)), temp_r5_543[temp_r31_540], &temp_r5_543[temp_r30_536], 2.0f, 0.125f);
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
s32 LightningStrikeFX::LoadDone() {
    Matrix sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    MKVector3 spD0;
    MKVector3 spC0;
    f64 spB8;
    f64 spB0;
    MKVector3 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f64 sp10;
    f32 temp_f3_673;
    f32 temp_f3_708;
    f32 temp_f6_680;
    f32 temp_f7_686;
    f32 temp_f8_714;
    f32 temp_f9_720;
    f64 temp_f0_625;
    s32 var_r30_574;

    MKProp::LoadDone();
    var_r30_574 = 0;
    sp60 = 1e11f;
    sp64 = 1e11f;
    sp68 = 1e11f;
    this->unk60 = (f64) sp60;
    sp58 = -1e11f;
    sp50 = -1e11f;
    sp54 = -1e11f;
    this->unk68 = (f64) sp68;
    this->unk70 = (f64) sp50;
    spF0 = (f64) sp60;
    spF8 = (f64) sp68;
    spE0 = (f64) sp50;
    spE8 = (f64) sp58;
    this->unk78 = (f64) sp58;
loop_2:
    if (var_r30_574 < (s32) this->unk50) {
        Min(spD0, *((MKVector3 *) &this->unk60));
        this->unk60 = M2C_BITWISE(f64, spD0);
        this->unk68 = (f64) spD0.unk8;
        Max(spC0, *((MKVector3 *) &this->unk70));
        var_r30_574 += 1;
        this->unk70 = M2C_BITWISE(f64, spC0);
        this->unk78 = (f64) spC0.unk8;
        goto loop_2;
    }
    temp_f0_625 = this->unk70 - this->unk60;
    sp10 = temp_f0_625;
    sp90 = temp_f0_625;
    sp18 = (f32) M2C_FIELD(this, f64 *, 0x78) - (f32) M2C_FIELD(this, f64 *, 0x68);
    sp98 = (f64) sp18;
    spA0.operator*(0.5f);
    sp40 = this->unk60 + M2C_BITWISE(f64, spA0);
    spB0 = sp40;
    sp48 = (f32) M2C_FIELD(this, f64 *, 0x68) + spA0.unk8;
    this->unkB0 = (f32) spB0;
    spB8 = (f64) sp48;
    this->unkB4 = (*(f32 *) ((u8 *) &spB0 + 0x4));
    this->unkB8 = (f32) spB8;
    this->unkBC = 1.0f;
    M2C_STRUCT_COPY((s32) &unkspFC + 4, (s32) (this + 0x7C) + 4, 0x40);
    sp100.Inverse(&sp100);
    temp_f3_673 = M2C_FIELD(this, f32 *, 0x64);
    temp_f6_680 = (f32) M2C_FIELD(this, f64 *, 0x60);
    temp_f7_686 = (f32) M2C_FIELD(this, f64 *, 0x68);
    sp30 = sp100.unk30 + ((temp_f7_686 * sp100.unk20) + ((temp_f6_680 * M2C_BITWISE(f32, sp100)) + (temp_f3_673 * sp100.unk10)));
    sp34 = sp100.unk34 + ((temp_f7_686 * sp100.unk24) + ((temp_f6_680 * sp100.unk4) + (temp_f3_673 * sp100.unk14)));
    sp38 = sp100.unk38 + ((temp_f7_686 * sp100.unk28) + ((temp_f6_680 * sp100.unk8) + (temp_f3_673 * sp100.unk18)));
    this->unk60 = (f64) sp30;
    this->unk68 = (f64) sp38;
    temp_f3_708 = M2C_FIELD(this, f32 *, 0x74);
    temp_f8_714 = (f32) M2C_FIELD(this, f64 *, 0x70);
    temp_f9_720 = (f32) M2C_FIELD(this, f64 *, 0x78);
    sp80 = (f64) sp30;
    sp20 = sp100.unk30 + ((temp_f9_720 * sp100.unk20) + ((temp_f8_714 * M2C_BITWISE(f32, sp100)) + (temp_f3_708 * sp100.unk10)));
    sp24 = sp100.unk34 + ((temp_f9_720 * sp100.unk24) + ((temp_f8_714 * sp100.unk4) + (temp_f3_708 * sp100.unk14)));
    sp28 = sp100.unk38 + ((temp_f9_720 * sp100.unk28) + ((temp_f8_714 * sp100.unk8) + (temp_f3_708 * sp100.unk18)));
    this->unk70 = (f64) sp20;
    this->unk78 = (f64) sp28;
    sp88 = (f64) sp38;
    sp70 = (f64) sp20;
    sp78 = (f64) sp28;
    this->unk70 -= this->unk60;
    M2C_FIELD(this, f64 *, 0x78) = (f32) ((f32) M2C_FIELD(this, f64 *, 0x78) - (f32) M2C_FIELD(this, f64 *, 0x68));
    this->unkC = (BoundingVolume *) &this->unk60;
    return 0x70;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
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
    if (arg0->IsField("StrikePoints") != 0) {
        temp_r3_787 = arg0->GetNmbrOfSubLines();
        this->unk50 = temp_r3_787;
        temp_r31_790 = this->unk50 * 0x10;
        temp_r3_791 = ((MKHeap *) temp_r3_787)->Current();
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

void LightningStrikeFX::Init() {
    MKProp::Init();
    this->unk4C = NULL;
    this->unk50 = 0;
    M2C_STRUCT_COPY((s32) (this + 0x7C) + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    this->unk8 = &this->unk80;
    this->unkC4 = 0.0f;
    this->unkC0 = 0.0f;
}

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
    f64 sp90;
    f32 sp88;
    f64 sp80;
    f32 sp78;
    f64 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    LightningStrikeFXDescriptor::StrikeArc **temp_r6_945;
    f32 temp_f1_1078;
    f32 temp_f1_1166;
    f32 temp_f1_1237;
    f32 var_f4_1012;
    f64 temp_f0_1091;
    f64 temp_f0_1146;
    f64 temp_f0_1178;
    f64 temp_f0_1217;
    f64 temp_f0_1249;
    f64 temp_f1_1015;
    f64 temp_f1_1021;
    f64 temp_f1_1025;
    f64 temp_f1_1139;
    f64 temp_f1_1171;
    f64 temp_f1_1210;
    f64 temp_f1_1242;
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
        sp90 = M2C_FIELD(&arg1, f64 *, 0) - M2C_FIELD(&arg0, f64 *, 0);
        sp140 = sp90;
        sp98 = arg1.unk8 - arg0.unk8;
        sp148 = (f64) sp98;
        var_f4_1012 = ((f32) sp148 * (f32) sp148) + (((f32) sp140 * (f32) sp140) + ((*(f32 *) ((u8 *) &sp140 + 0x4)) * (*(f32 *) ((u8 *) &sp140 + 0x4))));
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
        temp_f1_1078 = 200.0f * (var_f4_1012 / 1000.0f);
        M2C_FIELD(temp_r31_955, f64 *, 0) = (f64) (M2C_FIELD(temp_r31_955, f64 *, 0) * (f64) temp_f1_1078);
        M2C_FIELD(temp_r31_955, f64 *, 8) = (f32) ((f32) M2C_FIELD(temp_r31_955, f64 *, 8) * temp_f1_1078);
        M2C_FIELD(temp_r31_955, f32 *, 0x4C) = arg3;
        M2C_FIELD(temp_r31_955, f32 *, 0x10) = arg3;
        M2C_FIELD(temp_r31_955, f32 *, 0x48) = arg2;
        temp_f0_1091 = M2C_FIELD(&arg1, f64 *, 0) + M2C_FIELD(&arg0, f64 *, 0);
        sp10 = temp_f0_1091;
        sp120 = temp_f0_1091;
        sp18 = arg1.unk8 + arg0.unk8;
        sp128 = (f64) sp18;
        sp20 = temp_f0_1091 * 5.222099017e-315;
        M2C_FIELD(temp_r31_955, f64 *, 0x38) = sp20;
        sp28 = (f32) sp128 * 0.5f;
        sp130 = sp20;
        sp138 = (f64) sp28;
        M2C_FIELD(temp_r31_955, f64 *, 0x40) = (f64) sp28;
        M2C_ERROR(/* unknown instruction: cror 0x2, 0x0, 0x2 */);
        if (arg2 == 2.0f) {
            KDSound_Play3d(GS_Lightning3, ((u8 *) temp_r31_955) + 0x38, 0U, -1, 0.0f, 0U);
            return;
        }
        if (arg2 >= 5.0f) {
            temp_r3_1138 = M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **), 0xC)(gb), void **, 8);
            temp_f1_1139 = M2C_FIELD(temp_r3_1138, f64 *, 0x30);
            spE0 = temp_f1_1139;
            spE8 = M2C_FIELD(temp_r3_1138, f64 *, 0x38);
            temp_f0_1146 = temp_f1_1139 - M2C_FIELD(temp_r31_955, f64 *, 0x18);
            sp70 = temp_f0_1146;
            spF0 = temp_f0_1146;
            sp78 = (f32) spE8 - (f32) M2C_FIELD(temp_r31_955, f64 *, 0x20);
            spF8 = (f64) sp78;
            temp_f1_1166 = (f32) spF8 * (f32) spF8;
            temp_r3_1170 = M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **, f32, f32), 0xC)(gb, temp_f1_1166, (f32) spF8), void **, 8);
            temp_f1_1171 = M2C_FIELD(temp_r3_1170, f64 *, 0x30);
            sp100 = temp_f1_1171;
            sp108 = M2C_FIELD(temp_r3_1170, f64 *, 0x38);
            temp_f0_1178 = temp_f1_1171 - M2C_FIELD(temp_r31_955, f64 *, 0x38);
            sp80 = temp_f0_1178;
            sp110 = temp_f0_1178;
            sp88 = (f32) sp108 - (f32) M2C_FIELD(temp_r31_955, f64 *, 0x40);
            sp118 = (f64) sp88;
            if ((((f32) sp118 * (f32) sp118) + (((f32) sp110 * (f32) sp110) + ((*(f32 *) ((u8 *) &sp110 + 0x4)) * (*(f32 *) ((u8 *) &sp110 + 0x4))))) > (temp_f1_1166 + (((f32) spF0 * (f32) spF0) + ((*(f32 *) ((u8 *) &spF0 + 0x4)) * (*(f32 *) ((u8 *) &spF0 + 0x4)))))) {
                M2C_FIELD(temp_r31_955, f64 *, 0x38) = (f64) M2C_FIELD(temp_r31_955, f64 *, 0x18);
                M2C_FIELD(temp_r31_955, f64 *, 0x40) = (f64) M2C_FIELD(temp_r31_955, f64 *, 0x20);
            }
            temp_r3_1209 = M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **), 0xC)(gb), void **, 8);
            temp_f1_1210 = M2C_FIELD(temp_r3_1209, f64 *, 0x30);
            spA0 = temp_f1_1210;
            spA8 = M2C_FIELD(temp_r3_1209, f64 *, 0x38);
            temp_f0_1217 = temp_f1_1210 - M2C_FIELD(temp_r31_955, f64 *, 0x28);
            sp50 = temp_f0_1217;
            spB0 = temp_f0_1217;
            sp58 = (f32) spA8 - (f32) M2C_FIELD(temp_r31_955, f64 *, 0x30);
            spB8 = (f64) sp58;
            temp_f1_1237 = (f32) spB8 * (f32) spB8;
            temp_r3_1241 = M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **, f32, f32), 0xC)(gb, temp_f1_1237, (f32) spB8), void **, 8);
            temp_f1_1242 = M2C_FIELD(temp_r3_1241, f64 *, 0x30);
            spC0 = temp_f1_1242;
            spC8 = M2C_FIELD(temp_r3_1241, f64 *, 0x38);
            temp_f0_1249 = temp_f1_1242 - M2C_FIELD(temp_r31_955, f64 *, 0x38);
            sp60 = temp_f0_1249;
            spD0 = temp_f0_1249;
            sp68 = (f32) spC8 - (f32) M2C_FIELD(temp_r31_955, f64 *, 0x40);
            spD8 = (f64) sp68;
            if ((((f32) spD8 * (f32) spD8) + (((f32) spD0 * (f32) spD0) + ((*(f32 *) ((u8 *) &spD0 + 0x4)) * (*(f32 *) ((u8 *) &spD0 + 0x4))))) > (temp_f1_1237 + (((f32) spB0 * (f32) spB0) + ((*(f32 *) ((u8 *) &spB0 + 0x4)) * (*(f32 *) ((u8 *) &spB0 + 0x4)))))) {
                M2C_FIELD(temp_r31_955, f64 *, 0x38) = (f64) M2C_FIELD(temp_r31_955, f64 *, 0x28);
                M2C_FIELD(temp_r31_955, f64 *, 0x40) = (f64) M2C_FIELD(temp_r31_955, f64 *, 0x30);
            }
            KDSound_Play3d(GS_Lightning1, ((u8 *) temp_r31_955) + 0x38, 0U, -1, 0.0f, 0U);
            return;
        }
        KDSound_Play3d(GS_Lightning2, ((u8 *) temp_r31_955) + 0x38, 0U, -1, 0.0f, 0U);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp34C'
void LightningStrikeFXDescriptor::DrawStrikeArc(LightningStrikeFXDescriptor::StrikeArc *arg1) {
    f64 sp348;                                      /* compiler-managed */
    f64 sp340;
    f64 sp338;                                      /* compiler-managed */
    f64 sp330;                                      /* compiler-managed */
    f64 sp328;
    f64 sp320;
    f64 sp318;
    f64 sp310;
    f64 sp308;
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
    f64 sp280;
    f64 sp278;
    f64 sp270;
    f64 sp268;
    f64 sp260;
    f64 sp258;
    f64 sp250;
    f64 sp248;
    f64 sp240;
    f64 sp238;
    f64 sp230;
    f64 sp228;
    f64 sp220;
    f64 sp218;
    f64 sp210;
    f64 sp208;
    f64 sp200;
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f32 sp1A8;
    f64 sp1A0;
    f32 sp198;
    f64 sp190;
    f32 sp188;
    f64 sp180;
    f32 sp178;
    f32 sp174;
    f32 sp170;
    f32 sp168;
    f64 sp160;
    f32 sp158;
    f32 sp154;
    f32 sp150;
    f32 sp14C;
    f32 sp148;
    f32 sp144;
    f32 sp140;
    f32 sp138;
    f64 sp130;
    f32 sp128;
    f64 sp120;
    f32 sp118;
    f32 sp114;
    f32 sp110;
    f32 sp108;
    f64 sp100;
    f32 spF8;
    f64 spF0;
    f32 spE8;
    f64 spE0;
    f32 spD8;
    f64 spD0;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spB8;
    f64 spB0;
    f32 spA8;
    f64 spA0;
    f32 sp98;
    f64 sp90;
    f32 sp88;
    f64 sp80;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
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
    f64 temp_f0_1334;
    f64 temp_f0_1346;
    f64 temp_f0_1375;
    f64 temp_f0_1750;
    f64 temp_f0_1762;
    f64 temp_f0_1792;
    f64 temp_f0_1804;
    f64 temp_f0_1833;
    f64 temp_f0_1858;
    f64 temp_f0_1869;
    f64 temp_f0_1898;
    f64 temp_f0_1923;
    f64 temp_f0_1935;
    f64 temp_f1_1372;
    f64 temp_f1_1417;
    f64 temp_f1_1423;
    f64 temp_f1_1427;
    f64 temp_f1_1523;
    f64 temp_f1_1529;
    f64 temp_f1_1533;
    f64 temp_f1_1653;
    f64 temp_f1_1659;
    f64 temp_f1_1663;
    f64 temp_f3_1333;
    s32 temp_r3_1446;
    s32 temp_r3_1552;
    s32 temp_r3_1682;
    s32 var_r0_1456;
    s32 var_r0_1562;
    s32 var_r0_1692;

    temp_f3_1333 = M2C_FIELD(arg1, f64 *, 0x18);
    temp_f0_1334 = M2C_FIELD(arg1, f64 *, 0x28) - temp_f3_1333;
    sp1A0 = temp_f0_1334;
    temp_f5_1337 = M2C_FIELD(arg1, f32 *, 0x20);
    sp2E0 = temp_f0_1334;
    sp1A8 = M2C_FIELD(arg1, f32 *, 0x30) - temp_f5_1337;
    sp2E8 = (f64) sp1A8;
    temp_f0_1346 = temp_f0_1334 * 5.222099017e-315;
    sp190 = temp_f0_1346;
    sp2F0 = temp_f0_1346;
    sp198 = (f32) sp2E8 * 0.5f;
    sp2F8 = (f64) sp198;
    sp180 = temp_f3_1333 + temp_f0_1346;
    sp340 = sp180;
    temp_f27_1367 = 1.0f - (M2C_FIELD(arg1, f32 *, 0x10) / M2C_FIELD(arg1, f32 *, 0x4C));
    sp188 = temp_f5_1337 + (f32) sp2F8;
    sp348 = (f64) sp188;
    temp_f1_1372 = _table_sinf(6.2831855f * temp_f27_1367);
    temp_f0_1375 = M2C_FIELD(arg1, f64 *, 0) * temp_f1_1372;
    sp40 = temp_f0_1375;
    sp2D0 = temp_f0_1375;
    sp48 = M2C_FIELD(arg1, f32 *, 8) * (f32) temp_f1_1372;
    sp2D8 = (f64) sp48;
    sp340 += temp_f0_1375;
    sp348 = (f32) sp348 + (f32) sp2D8;
    M2C_STRUCT_COPY((s32) &unksp34C + 4, MKView_GetCameraMatrix() - 4 + 4, 0x40);
    var_f4_1411 = (sp358 * sp358) + ((sp350 * sp350) + (sp354 * sp354));
    if (var_f4_1411 > 1e-12f) {
        if (var_f4_1411 > 0.0f) {
            temp_f1_1417 = __frsqrte(var_f4_1411);
            temp_f1_1423 = 0.5 * temp_f1_1417 * -(((f64) var_f4_1411 * (temp_f1_1417 * temp_f1_1417)) - 3.0);
            temp_f1_1427 = 0.5 * temp_f1_1423 * -(((f64) var_f4_1411 * (temp_f1_1423 * temp_f1_1423)) - 3.0);
            var_f4_1411 = (f32) ((f64) var_f4_1411 * (0.5 * temp_f1_1427 * -(((f64) var_f4_1411 * (temp_f1_1427 * temp_f1_1427)) - 3.0)));
        } else if (var_f4_1411 < M2C_BITWISE(f32, 0.0)) {
            var_f4_1411 = __float_nan;
        } else {
            sp18 = var_f4_1411;
            temp_r3_1446 = M2C_BITWISE(s32, sp18) & 0x7F800000;
            switch (temp_r3_1446) {                 /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                    var_r0_1456 = 1;
                } else {
                    var_r0_1456 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
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
    sp170 = sp350 * var_f3_1478;
    sp174 = sp354 * var_f3_1478;
    sp178 = sp358 * var_f3_1478;
    sp320 = (f64) sp170;
    sp328 = (f64) sp178;
    sp160 = M2C_FIELD(arg1, f64 *, 0x28) - M2C_FIELD(arg1, f64 *, 0x18);
    sp2C0 = sp160;
    sp168 = M2C_FIELD(arg1, f32 *, 0x30) - M2C_FIELD(arg1, f32 *, 0x20);
    sp2C8 = (f64) sp168;
    var_f4_1517 = ((f32) sp2C8 * (f32) sp2C8) + (((f32) sp2C0 * (f32) sp2C0) + ((*(f32 *) ((u8 *) &sp2C0 + 0x4)) * (*(f32 *) ((u8 *) &sp2C0 + 0x4))));
    if (var_f4_1517 > 1e-12f) {
        if (var_f4_1517 > 0.0f) {
            temp_f1_1523 = __frsqrte(var_f4_1517);
            temp_f1_1529 = 0.5 * temp_f1_1523 * -(((f64) var_f4_1517 * (temp_f1_1523 * temp_f1_1523)) - 3.0);
            temp_f1_1533 = 0.5 * temp_f1_1529 * -(((f64) var_f4_1517 * (temp_f1_1529 * temp_f1_1529)) - 3.0);
            var_f4_1517 = (f32) ((f64) var_f4_1517 * (0.5 * temp_f1_1533 * -(((f64) var_f4_1517 * (temp_f1_1533 * temp_f1_1533)) - 3.0)));
        } else if (var_f4_1517 < M2C_BITWISE(f32, 0.0)) {
            var_f4_1517 = __float_nan;
        } else {
            sp14 = var_f4_1517;
            temp_r3_1552 = M2C_BITWISE(s32, sp14) & 0x7F800000;
            switch (temp_r3_1552) {                 /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                    var_r0_1562 = 1;
                } else {
                    var_r0_1562 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
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
    sp154 = (*(f32 *) ((u8 *) &sp2C0 + 0x4)) * var_f3_1584;
    sp150 = (f32) sp2C0 * var_f3_1584;
    sp158 = (f32) sp2C8 * var_f3_1584;
    sp310 = (f64) sp150;
    sp318 = (f64) sp158;
    sp38 = ((f32) sp310 * (*(f32 *) ((u8 *) &sp320 + 0x4))) - ((*(f32 *) ((u8 *) &sp310 + 0x4)) * (f32) sp320);
    sp30 = ((*(f32 *) ((u8 *) &sp310 + 0x4)) * (f32) sp328) - ((f32) sp318 * (*(f32 *) ((u8 *) &sp320 + 0x4)));
    sp34 = ((f32) sp318 * (f32) sp320) - ((f32) sp310 * (f32) sp328);
    sp338 = (f64) sp38;
    sp330 = (f64) sp30;
    sp2B0 = (f64) sp30;
    sp2B8 = (f64) sp38;
    sp24 = ((f32) sp318 * (f32) sp330) - ((f32) sp310 * (f32) sp338);
    sp20 = ((*(f32 *) ((u8 *) &sp310 + 0x4)) * (f32) sp338) - ((f32) sp318 * (*(f32 *) ((u8 *) &sp328 + 0xc)));
    sp28 = ((f32) sp310 * (*(f32 *) ((u8 *) &sp328 + 0xc))) - ((*(f32 *) ((u8 *) &sp310 + 0x4)) * (f32) sp330);
    sp330 = (f64) sp20;
    sp338 = (f64) sp28;
    sp2A0 = (f64) sp20;
    sp2A8 = (f64) sp28;
    var_f4_1647 = ((f32) sp338 * (f32) sp338) + (((f32) sp330 * (f32) sp330) + ((*(f32 *) ((u8 *) &sp328 + 0xc)) * (*(f32 *) ((u8 *) &sp328 + 0xc))));
    if (var_f4_1647 > 0.000001f) {
        if (var_f4_1647 > 0.0f) {
            temp_f1_1653 = __frsqrte(var_f4_1647);
            temp_f1_1659 = 0.5 * temp_f1_1653 * -(((f64) var_f4_1647 * (temp_f1_1653 * temp_f1_1653)) - 3.0);
            temp_f1_1663 = 0.5 * temp_f1_1659 * -(((f64) var_f4_1647 * (temp_f1_1659 * temp_f1_1659)) - 3.0);
            var_f4_1647 = (f32) ((f64) var_f4_1647 * (0.5 * temp_f1_1663 * -(((f64) var_f4_1647 * (temp_f1_1663 * temp_f1_1663)) - 3.0)));
        } else if (var_f4_1647 < M2C_BITWISE(f32, 0.0)) {
            var_f4_1647 = __float_nan;
        } else {
            sp10 = var_f4_1647;
            temp_r3_1682 = M2C_BITWISE(s32, sp10) & 0x7F800000;
            switch (temp_r3_1682) {                 /* switch 3; irregular */
            case 0x7F800000:                        /* switch 3 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_1692 = 1;
                } else {
                    var_r0_1692 = 2;
                }
                break;
            case 0x0:                               /* switch 3 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
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
    sp14C = 1.0f;
    sp148 = temp_f7_1722;
    sp140 = temp_f7_1722;
    sp144 = temp_f7_1722;
    sp308 = (f64) sp148;
    sp300 = (f64) sp140;
    sp330 = (f32) sp330 * var_f6_1714;
    temp_f26_1740 = 30.000002f * M2C_FIELD(arg1, f32 *, 0x48);
    (*(f32 *) ((u8 *) &sp328 + 0xc)) *= var_f6_1714;
    sp338 = (f32) sp338 * var_f6_1714;
    MKBegin(6);
    MKSetColorV(*((MKVector4 *) &sp300));
    MKSetTexCoord1F(0.0f, 0.0f);
    temp_f0_1750 = (f64) sp330 * (f64) temp_f26_1740;
    sp130 = temp_f0_1750;
    temp_f31_1755 = sp338 * temp_f26_1740;
    sp280 = temp_f0_1750;
    sp138 = temp_f31_1755;
    sp288 = (f64) sp138;
    temp_f0_1762 = M2C_FIELD(arg1, f64 *, 0x18) + temp_f0_1750;
    sp120 = temp_f0_1762;
    sp290 = temp_f0_1762;
    sp128 = M2C_FIELD(arg1, f32 *, 0x20) + (f32) sp288;
    sp298 = (f64) sp128;
    MKSetPositionV(*((MKVector3 *) &sp290));
    MKSetColorV(*((MKVector4 *) &sp300));
    MKSetTexCoord1F(1.0f, 0.0f);
    temp_f28_1780 = -sp338;
    temp_f30_1782 = -sp330;
    temp_f29_1783 = -(*(f32 *) ((u8 *) &sp328 + 0xc));
    sp118 = temp_f28_1780;
    sp110 = temp_f30_1782;
    sp114 = temp_f29_1783;
    sp258 = (f64) sp118;
    sp250 = (f64) sp110;
    temp_f0_1792 = sp250 * (f64) temp_f26_1740;
    sp100 = temp_f0_1792;
    sp260 = temp_f0_1792;
    sp108 = (f32) sp258 * temp_f26_1740;
    sp268 = (f64) sp108;
    temp_f0_1804 = M2C_FIELD(arg1, f64 *, 0x18) + temp_f0_1792;
    spF0 = temp_f0_1804;
    sp270 = temp_f0_1804;
    spF8 = M2C_FIELD(arg1, f32 *, 0x20) + (f32) sp268;
    sp278 = (f64) spF8;
    MKSetPositionV(*((MKVector3 *) &sp270));
    temp_f25_1818 = 0.0f + 1.0f;
    MKSetColorV(*((MKVector4 *) &sp300));
    MKSetTexCoord1F(0.0f, temp_f25_1818);
    spE0 = (f64) sp330 * (f64) temp_f26_1740;
    spE8 = temp_f31_1755;
    sp230 = spE0;
    sp238 = (f64) spE8;
    temp_f0_1833 = sp340 + sp230;
    spD0 = temp_f0_1833;
    sp240 = temp_f0_1833;
    spD8 = sp348 + (f32) sp238;
    sp248 = (f64) spD8;
    MKSetPositionV(*((MKVector3 *) &sp240));
    MKSetColorV(*((MKVector4 *) &sp300));
    MKSetTexCoord1F(1.0f, temp_f25_1818);
    spC0 = temp_f30_1782;
    spC4 = temp_f29_1783;
    spC8 = temp_f28_1780;
    sp200 = (f64) spC0;
    sp208 = (f64) spC8;
    temp_f0_1858 = sp200 * (f64) temp_f26_1740;
    spB0 = temp_f0_1858;
    sp210 = temp_f0_1858;
    spB8 = (f32) sp208 * temp_f26_1740;
    sp218 = (f64) spB8;
    temp_f0_1869 = sp340 + temp_f0_1858;
    spA0 = temp_f0_1869;
    sp220 = temp_f0_1869;
    spA8 = sp348 + (f32) sp218;
    sp228 = (f64) spA8;
    MKSetPositionV(*((MKVector3 *) &sp220));
    temp_f25_1882 = temp_f25_1818 + 1.0f;
    MKSetColorV(*((MKVector4 *) &sp300));
    MKSetTexCoord1F(0.0f, temp_f25_1882);
    sp90 = (f64) sp330 * (f64) temp_f26_1740;
    sp98 = temp_f31_1755;
    sp1E0 = sp90;
    sp1E8 = (f64) sp98;
    temp_f0_1898 = M2C_FIELD(arg1, f64 *, 0x28) + sp1E0;
    sp80 = temp_f0_1898;
    sp1F0 = temp_f0_1898;
    sp88 = M2C_FIELD(arg1, f32 *, 0x30) + (f32) sp1E8;
    sp1F8 = (f64) sp88;
    MKSetPositionV(*((MKVector3 *) &sp1F0));
    MKSetColorV(*((MKVector4 *) &sp300));
    MKSetTexCoord1F(1.0f, temp_f25_1882);
    sp70 = temp_f30_1782;
    sp74 = temp_f29_1783;
    sp78 = temp_f28_1780;
    sp1B0 = (f64) sp70;
    sp1B8 = (f64) sp78;
    temp_f0_1923 = sp1B0 * (f64) temp_f26_1740;
    sp60 = temp_f0_1923;
    sp1C0 = temp_f0_1923;
    sp68 = (f32) sp1B8 * temp_f26_1740;
    sp1C8 = (f64) sp68;
    temp_f0_1935 = M2C_FIELD(arg1, f64 *, 0x28) + temp_f0_1923;
    sp50 = temp_f0_1935;
    sp1D0 = temp_f0_1935;
    sp58 = M2C_FIELD(arg1, f32 *, 0x30) + (f32) sp1C8;
    sp1D8 = (f64) sp58;
    MKSetPositionV(*((MKVector3 *) &sp1D0));
    MKEnd();
}
#endif

void LightningStrikeFXDescriptor::DrawStrikeArcs() {
    LightningStrikeFXDescriptor::StrikeArc **var_r31_1989;
    LightningStrikeFXDescriptor::StrikeArc *temp_r4_1998;

    if ((u8) this->unk9C == 0) {
        MKMaterial_SetMaterial(this->unk94);
        MKPrimitive(0xC, 0);
        MKSetMatrix(Matrix::identity);
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
        temp_r3_2065 = ((MKHeap *) var_r3_2040)->Current();
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

#if 0 // DRAFT: undefined identifier 'unksp24'
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
            if (M2C_FIELD(temp_r3_2125, f32 *, 0x10) <= 0.0f) {
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
        if (temp_f2_2152 <= 0.0f) {
            ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_2149, 0U);
        } else {
            temp_f31_2167 = temp_f2_2152 / 0.75f;
            temp_f1_2169 = MKRand_Float((int *) &gViewSeed, 0.1f, 1.0f);
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
            ((LightningStrikeFX *) (checked_cast<P17LightningStrikeFX))->Strike(6MKProp>__FP6MKProp((&sp98[0])[MKRand_Int((int *) &gViewSeed, 0, var_r28_2208)]));
            this->unk90 = MKRand_Float((int *) &gViewSeed, 4.0f, 5.0f);
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

#if 0 // DRAFT: illegal implicit conversion from 'MKResource *' to
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
    M2C_FIELD(this, f64 *, 0x70) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 0);
    this->unk78 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unk80 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    this->unk88 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unk1C = (BoundingVolume *) &this->unk70;
    this->unk90 = 0.0f;
    this->unkA4 = 0;
    temp_r3_2359 = MKMaterial_Create("fx_351");
    this->unk94 = temp_r3_2359;
    temp_r3_2361 = ((MKHeap *) temp_r3_2359)->Current();
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
