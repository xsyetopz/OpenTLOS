#include "spyro/source/ConvexityVortex.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/KDFaderObject.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/Level.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/TargetManager.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDRandom.h"
#include <m2c_macros.h>

M2C_UNK free(MKVector3 **);                         /* extern */
MKVector3 **malloc(M2C_UNK);                        /* extern */
extern s32 GS_ConvexFlyingPlatformLP;
extern s32 GS_ConvexFlyingPlatformStop;
extern M2C_UNK gEmptyPtrListDL;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;

#if 0 // DRAFT: undefined identifier 'MKVector'
void ConvexityVortex::SpawnElement(const MKVector3 &arg0) {
    f64 spA0;
    f64 sp98;
    MKVector3 sp88;
    MKVector3 sp78;
    M2C_UNK sp68;
    f64 sp60;
    f64 sp58;
    MKVector3 sp48;
    MKVector3 sp38;
    M2C_UNK sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    MKVector3 **temp_r3_51;
    MKVector3 **temp_r3_55;
    MKVector3 *temp_r31_57;

    temp_r3_51 = this->unkA0;
    if ((u32) M2C_FIELD(temp_r3_51, u32 *, -4) != 0U) {
        temp_r3_55 = temp_r3_51 - 4;
        this->unkA0 = temp_r3_55;
        temp_r31_57 = *temp_r3_55;
        if (temp_r31_57 != NULL) {
            M2C_FIELD(temp_r31_57, f32 *, 0x34) = 0.5f;
            M2C_FIELD(temp_r31_57, s32 *, 0x38) = 1;
            M2C_FIELD(temp_r31_57, s32 *, 0x3C) = (s32) M2C_FIELD((this + (MKRand_Int((int *) &gViewSeed, 0, 2) * 4)), s32 *, 0x4C);
            MKVector(1.0f, 1.0f, 1.0f);
            MKVector(-1.0f, -1.0f, -1.0f);
            KDRand_Vector(sp88, sp78);
            sp18 = sp88 * 5.370091495e-315;
            M2C_FIELD(temp_r31_57, f64 *, 0x10) = sp18;
            sp20 = sp88.unk8 * 6.2831855f;
            sp98 = sp18;
            spA0 = (f64) sp20;
            M2C_FIELD(temp_r31_57, f64 *, 0x18) = (f64) sp20;
            MKVector(1.0f, 1.0f, 1.0f);
            MKVector(-1.0f, -1.0f, -1.0f);
            KDRand_Vector(sp48, sp38);
            sp8 = sp48 * 5.370091495e-315;
            M2C_FIELD(temp_r31_57, f64 *, 0x20) = sp8;
            sp10 = sp48.unk8 * 6.2831855f;
            sp58 = sp8;
            sp60 = (f64) sp10;
            M2C_FIELD(temp_r31_57, f64 *, 0x28) = (f64) sp10;
            M2C_FIELD(temp_r31_57, f32 *, 0x30) = MKRand_Float((int *) &gViewSeed, 0.25f, 1.0f);
            M2C_FIELD(temp_r31_57, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
            M2C_FIELD(temp_r31_57, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
            ((KDSoundFader *) (temp_r31_57 + 0x40))->Init(0.25f, 0.25f);
        }
    }
}
#endif

#if 0 // DRAFT: function call 'MKModel_Destroy(ConvexityVortex)' does not match
void ConvexityVortex::Deinit() {
    MKHeap *temp_r3_211;
    MKVector3 **var_r30_171;
    MKVector3 **var_r31_185;
    MKVector3 **var_r3_186;
    MKVector3 **var_r4_184;
    MKVector3 *temp_r0_189;
    MKVector3 *temp_r0_208;
    MKVector3 *temp_r3_180;
    s32 var_r30_161;
    s32 var_r31_162;
    u32 temp_r0_194;

    var_r30_161 = 0;
    var_r31_162 = 0;
    do {
        MKModel_Destroy(*(this + (var_r31_162 + 0x4C)));
        var_r30_161 += 1;
        var_r31_162 += 4;
    } while (var_r30_161 < 2);
    var_r30_171 = this->unkA0;
loop_4:
    if (var_r30_171 != NULL) {
        temp_r3_180 = *var_r30_171;
        if (temp_r3_180 != NULL) {
            KDSound_Stop((s32 *) (temp_r3_180 + 0x40));
            var_r30_171 += 4;
            goto loop_4;
        }
    }
    var_r4_184 = this->unkA0;
    var_r31_185 = var_r4_184;
    var_r3_186 = var_r4_184;
loop_9:
    temp_r0_194 = M2C_FIELD(var_r3_186, u32 *, -4);
    var_r3_186 -= 4;
    if (temp_r0_194 != 0U) {
        temp_r0_189 = *var_r3_186;
        if (temp_r0_189 < var_r31_185) {
            var_r31_185 = (MKVector3 **) temp_r0_189;
        }
        goto loop_9;
    }
    if (var_r3_186 != &gEmptyPtrListDL) {
loop_15:
        temp_r0_208 = *var_r4_184;
        if (temp_r0_208 != NULL) {
            if (temp_r0_208 < var_r31_185) {
                var_r31_185 = (MKVector3 **) temp_r0_208;
            }
            var_r4_184 += 4;
            goto loop_15;
        }
        temp_r3_211 = ((MKHeap *) var_r3_186)->Current();
        if (temp_r3_211 != NULL) {
            ((MKHeap *) (temp_r3_211->Current()))->Free(var_r31_185, NULL, 0);
        } else {
            free(var_r31_185);
        }
    }
    this->unkA0 = NULL;
    MKProp::Deinit();
}
#endif

void ConvexityVortex::Draw() {
    Matrix sp30;
    f64 sp28;
    f64 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    MKVector3 **var_r29_258;
    MKVector3 *temp_r30_310;

    sp10 = 1.0f;
    sp14 = 1.0f;
    sp18 = 1.0f;
    sp1C = 1.0f;
    sp20 = (f64) sp10;
    sp28 = (f64) sp18;
    var_r29_258 = this->unkA0;
loop_5:
    if (var_r29_258 != NULL) {
        temp_r30_310 = *var_r29_258;
        if (temp_r30_310 != NULL) {
            M2C_STRUCT_COPY((s32) &(*(f32 *) ((u8 *) &sp28 + 0x4)) + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
            sp30.SetRotationPYR(*(temp_r30_310 + 0x10));
            sp30.Scale3x3(&sp30, M2C_FIELD(temp_r30_310, f32 *, 0x30));
            sp30.unk30 = temp_r30_310->unk0;
            sp30.unk34 = temp_r30_310->unk4;
            sp30.unk38 = temp_r30_310->unk8;
            sp30.unk3C = 1.0f;
            if ((s32) M2C_FIELD(temp_r30_310, s32 *, 0x38) == 1) {
                (*(f32 *) ((u8 *) &sp28 + 0x4)) = 1.0f - (M2C_FIELD(temp_r30_310, f32 *, 0x34) / 0.5f);
            } else {
                (*(f32 *) ((u8 *) &sp28 + 0x4)) = 1.0f;
            }
            MKModel_SetColor(M2C_FIELD(temp_r30_310, MKModel **, 0x3C), *((MKVector4 *) &sp20));
            MKModel_SetWorldMatrix(M2C_FIELD(temp_r30_310, MKModel **, 0x3C), sp30);
            MKModel_Draw(M2C_FIELD(temp_r30_310, MKModel **, 0x3C), NULL);
            var_r29_258 += 4;
            goto loop_5;
        }
    }
}

void ConvexityVortex::Message(MKMessage *arg0) {
    MKVector3 **var_r31_349;
    MKVector3 *temp_r3_359;
    s32 temp_r0_334;

    MKProp::Message(arg0);
    temp_r0_334 = arg0->unk0;
    switch (temp_r0_334) {                          /* irregular */
    case 0xB5:
        this->unkA8 = 1;
        break;
    case 0xB4:
        this->unkA8 = 0;
        break;
    }
    var_r31_349 = this->unkA0;
loop_8:
    if (var_r31_349 != NULL) {
        temp_r3_359 = *var_r31_349;
        if (temp_r3_359 != NULL) {
            ((KDSoundPlayer *) (temp_r3_359 + 0x40))->Message(arg0);
            var_r31_349 += 4;
            goto loop_8;
        }
    }
}

#if 0 // DRAFT: undefined identifier 'MKVector'
void ConvexityVortex::Update() {
    f64 spF0;                                       /* compiler-managed */
    f64 spE8;
    f64 spE0;                                       /* compiler-managed */
    f64 spD8;                                       /* compiler-managed */
    f64 spD0;
    f64 spC8;
    MKVector3 spB8;
    MKVector3 spA8;
    MKVector3 sp98;
    M2C_UNK sp88;
    f64 sp80;
    f64 sp78;
    MKVector3 sp68;
    f64 sp60;
    f64 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    s32 sp8;
    MKVector3 **temp_r3_681;
    MKVector3 **var_r30_451;
    MKVector3 *temp_r31_693;
    MKVector3 *temp_r4_684;
    f32 temp_f30_562;
    f32 var_f28_477;
    f32 var_f3_544;
    f64 temp_f0_430;
    f64 temp_f0_460;
    f64 temp_f0_569;
    f64 temp_f0_591;
    f64 temp_f1_483;
    f64 temp_f1_489;
    f64 temp_f1_493;
    s32 temp_r0_647;
    s32 temp_r3_512;
    s32 var_r0_522;
    u8 var_r6_646;
    void *temp_r3_457;
    void *temp_r3_636;
    void *temp_r4_407;

    this->unkA4 -= gUpdateTimeDelta;
    if ((this->unkA4 <= 0.0f) && ((u8) this->unkA8 != 0)) {
        this->unkA4 = MKRand_Float((int *) &gViewSeed, 1.0f, 1.5f);
        temp_r4_407 = this->unk8;
        spE8 = M2C_FIELD(temp_r4_407, f64 *, 0x30);
        spF0 = M2C_FIELD(temp_r4_407, f64 *, 0x38);
        MKVector(1.0f, 0.1f, 1.0f);
        MKVector(-1.0f, 0.1f, -1.0f);
        KDRand_Vector(spA8, sp98);
        Normalise(spB8);
        temp_f0_430 = spB8 * 5.907017874e-315;
        sp38 = temp_f0_430;
        spC8 = temp_f0_430;
        sp40 = spB8.unk8 * 50000.0f;
        spD0 = (f64) sp40;
        spE8 += temp_f0_430;
        spF0 = (f32) spF0 + (f32) spD0;
        SpawnElement(*((MKVector3 *) &spE8));
    }
    var_r30_451 = this->unkA0;
loop_39:
    if (var_r30_451 != NULL) {
        temp_r31_693 = *var_r30_451;
        if (temp_r31_693 != NULL) {
            temp_r3_457 = ((u8 *) this->unk8) + 0x30;
            temp_f0_460 = M2C_FIELD(temp_r3_457, f64 *, 0) - M2C_FIELD(temp_r31_693, f64 *, 0);
            sp48 = temp_f0_460;
            spD8 = temp_f0_460;
            sp50 = M2C_FIELD(temp_r3_457, f32 *, 8) - temp_r31_693->unk8;
            spE0 = (f64) sp50;
            var_f28_477 = ((f32) spE0 * (f32) spE0) + (((f32) spD8 * (f32) spD8) + ((*(f32 *) ((u8 *) &spD0 + 0xc)) * (*(f32 *) ((u8 *) &spD0 + 0xc))));
            if (var_f28_477 > 0.000001f) {
                if (var_f28_477 > 0.0f) {
                    temp_f1_483 = __frsqrte(var_f28_477);
                    temp_f1_489 = 0.5 * temp_f1_483 * -(((f64) var_f28_477 * (temp_f1_483 * temp_f1_483)) - 3.0);
                    temp_f1_493 = 0.5 * temp_f1_489 * -(((f64) var_f28_477 * (temp_f1_489 * temp_f1_489)) - 3.0);
                    var_f28_477 = (f32) ((f64) var_f28_477 * (0.5 * temp_f1_493 * -(((f64) var_f28_477 * (temp_f1_493 * temp_f1_493)) - 3.0)));
                } else if (var_f28_477 < M2C_BITWISE(f32, 0.0)) {
                    var_f28_477 = __float_nan;
                } else {
                    sp10 = var_f28_477;
                    temp_r3_512 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                    switch (temp_r3_512) {          /* irregular */
                    case 0x7F800000:
                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                            var_r0_522 = 1;
                        } else {
                            var_r0_522 = 2;
                        }
                        break;
                    case 0x0:
                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                            var_r0_522 = 5;
                        } else {
                            var_r0_522 = 3;
                        }
                        break;
                    default:
                        var_r0_522 = 4;
                        break;
                    }
                    if (var_r0_522 == 1) {
                        var_f28_477 = __float_nan;
                    }
                }
                var_f3_544 = 1.0f / var_f28_477;
            } else {
                var_f3_544 = 0.0f;
                var_f28_477 = 0.0f;
            }
            spD8 = (f32) spD8 * var_f3_544;
            (*(f32 *) ((u8 *) &spD0 + 0xc)) *= var_f3_544;
            spE0 = (f32) spE0 * var_f3_544;
            if ((s32) M2C_FIELD(temp_r31_693, s32 *, 0x38) != 3) {
                temp_f30_562 = gUpdateTimeDelta;
                sp68.operator*(20000.0f);
                temp_f0_569 = sp68 * (f64) temp_f30_562;
                sp28 = temp_f0_569;
                sp78 = temp_f0_569;
                sp30 = sp68.unk8 * temp_f30_562;
                sp80 = (f64) sp30;
                M2C_FIELD(temp_r31_693, f64 *, 0) = (f64) (M2C_FIELD(temp_r31_693, f64 *, 0) + temp_f0_569);
                temp_r31_693->unk8 += (f32) sp80;
            }
            temp_f0_591 = M2C_FIELD(temp_r31_693, f64 *, 0x20) * (f64) gUpdateTimeDelta;
            sp18 = temp_f0_591;
            sp58 = temp_f0_591;
            sp20 = M2C_FIELD(temp_r31_693, f32 *, 0x28) * gUpdateTimeDelta;
            sp60 = (f64) sp20;
            M2C_FIELD(temp_r31_693, f64 *, 0x10) = (f64) (M2C_FIELD(temp_r31_693, f64 *, 0x10) + temp_f0_591);
            M2C_FIELD(temp_r31_693, f32 *, 0x18) = (f32) (M2C_FIELD(temp_r31_693, f32 *, 0x18) + (f32) sp60);
            M2C_FIELD(temp_r31_693, f32 *, 0x34) = (f32) (M2C_FIELD(temp_r31_693, f32 *, 0x34) - gUpdateTimeDelta);
            if (M2C_FIELD(temp_r31_693, f32 *, 0x34) < 0.0f) {
                M2C_FIELD(temp_r31_693, f32 *, 0x34) = 0.0f;
            }
            if (((s32) M2C_FIELD(temp_r31_693, s32 *, 0x38) != 3) && (var_f28_477 <= 1000.0f)) {
                M2C_FIELD(temp_r31_693, s32 *, 0x38) = 3;
                KDSound_Play3d(GS_ConvexFlyingPlatformStop, temp_r31_693, 0U, -1, 0.0f, 0U);
                M2C_FIELD(temp_r31_693, f32 *, 0x34) = 0.5f;
                temp_r3_636 = this->unk8;
                M2C_FIELD(temp_r31_693, f64 *, 0) = (f64) M2C_FIELD(temp_r3_636, f64 *, 0x30);
                M2C_FIELD(temp_r31_693, f32 *, 8) = (f64) M2C_FIELD(temp_r3_636, f64 *, 0x38);
            }
            sp8 = 1;
            var_r6_646 = 0;
            temp_r0_647 = M2C_FIELD(temp_r31_693, s32 *, 0x38);
            if ((temp_r0_647 == 2) || (temp_r0_647 == 1)) {
                var_r6_646 = 1;
            }
            ((KDSoundFader *) (temp_r31_693 + 0x40))->Update(GS_ConvexFlyingPlatformLP, 1U, var_r6_646, NULL, temp_r31_693, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
            if ((s32) M2C_FIELD(temp_r31_693, s32 *, 0x38) != 3) {

            } else {
                M2C_FIELD(temp_r31_693, f32 *, 0x30) = (f32) (M2C_FIELD(temp_r31_693, f32 *, 0x30) * (M2C_FIELD(temp_r31_693, f32 *, 0x34) / 0.5f));
                if (M2C_FIELD(temp_r31_693, f32 *, 0x34) <= 0.0f) {
                    M2C_FIELD(temp_r31_693, s32 *, 0x38) = 0;
                    KDSound_Stop((s32 *) (temp_r31_693 + 0x40));
                    temp_r3_681 = this->unkA0;
                    this->unkA0 = temp_r3_681 + 4;
                    temp_r4_684 = *temp_r3_681;
                    *temp_r3_681 = *var_r30_451;
                    *var_r30_451 = temp_r4_684;
                }
            }
            var_r30_451 += 4;
            goto loop_39;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void ConvexityVortex::LoadDone() {
    MKProp::LoadDone();
    M2C_STRUCT_COPY((s32) &this->unk5C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    this->unk90 = M2C_FIELD(&MKProp::loadInfo, f32 *, 0x40);
    this->unk94 = M2C_BITWISE(f32, MKProp::loadInfo.__vptr);
    this->unk98 = MKProp::loadInfo.unk48;
    this->unk9C = 1.0f;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKModel *' to
void ConvexityVortex::Init() {
    MKHeap *temp_r3_776;
    MKHeap *temp_r3_778;
    MKVector3 **temp_r3_800;
    MKVector3 **temp_r3_806;
    MKVector3 **var_r3_785;
    MKVector3 **var_r5_794;
    s32 var_ctr_798;

    MKProp::Init();
    this->unk8 = &this->unk60;
    this->unk4C = MKModel_Create("P6001_TiltPlatform_A", NULL, 2, NULL);
    temp_r3_776 = MKModel_Create("P6001_TiltPlatform_C", NULL, 2, NULL);
    this->unk50 = temp_r3_776;
    temp_r3_778 = temp_r3_776->Current();
    if (temp_r3_778 != NULL) {
        var_r3_785 = ((MKHeap *) (temp_r3_778->Current()))->Alloc(0x440, NULL, 0);
    } else {
        var_r3_785 = malloc(0x440);
    }
    this->unkA0 = var_r3_785;
    var_r5_794 = this->unkA0;
    this->unkA0 = var_r5_794 + 0x410;
    M2C_FIELD(var_r5_794, s32 *, 0x410) = 0;
    var_ctr_798 = 0xA;
    do {
        temp_r3_800 = this->unkA0;
        this->unkA0 = temp_r3_800 + 4;
        M2C_FIELD(temp_r3_800, MKVector3 ***, 4) = var_r5_794;
        var_r5_794 += 0x68;
        var_ctr_798 -= 1;
    } while (var_ctr_798 != 0);
    temp_r3_806 = this->unkA0;
    this->unkA0 = temp_r3_806 + 4;
    M2C_FIELD(temp_r3_806, MKVector3 ***, 4) = NULL;
    this->unkA4 = 0.0f;
    this->unkA8 = 0;
}
#endif
