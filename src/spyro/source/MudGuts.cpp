#include "spyro/source/MudGuts.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Critters.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/Level.h"
#include "spyro/source/Volume.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDMath.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(s32);                                  /* extern */
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;

#if 0 // DRAFT: illegal use of non-static member
void MudGutsCritter::Deinit() {
    MKHeap *temp_r3_57;
    void *temp_r31_54;

    temp_r31_54 = this->unk170;
    if (temp_r31_54 != NULL) {
        temp_r3_57 = MKHeap::Current();
        if (temp_r3_57 != NULL) {
            ((MKHeap *) (temp_r3_57->Current()))->Free(temp_r31_54, NULL, 0);
        } else {
            free(temp_r31_54);
        }
    }
    this->unk170 = NULL;
    Critters::Deinit();
}
#endif

void MudGutsCritter::Draw() {
    Matrix sp10;
    M2C_UNK spC;
    s32 var_r30_92;
    s32 var_r31_93;
    void *temp_r29_100;

    var_r30_92 = 0;
    var_r31_93 = 0;
loop_2:
    if (var_r30_92 < (s32) this->unk90) {
        temp_r29_100 = ((u8 *) this->unk170) + var_r31_93;
        this->unk80->SetAnim(M2C_FIELD(temp_r29_100, MKAnim **, 0x50), 0.0f, 0.0f, 0, -1);
        this->unk80->JumpToPos(M2C_FIELD(temp_r29_100, f32 *, 0x54), -1);
        M2C_STRUCT_COPY((s32) &spC + 4, (s32) (((u8 *) temp_r29_100) - 4) + 4, 0x40);
        MKModel_SetWorldMatrix(this->unk4, sp10);
        MKModel_Draw(this->unk4, NULL);
        var_r30_92 += 1;
        var_r31_93 += 0x70;
        goto loop_2;
    }
}

#if 0 // DRAFT: undefined identifier 'sp38'
void MudGutsCritter::FindNewSwimParameters(MudGuts *arg0) {
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;                                       /* compiler-managed */
    f64 sp50;                                       /* compiler-managed */
    f64 sp48;
    f64 sp40;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    f32 temp_f3_179;
    f32 var_f31_192;
    f32 var_f3_259;
    f64 temp_f0_173;
    f64 temp_f1_198;
    f64 temp_f1_204;
    f64 temp_f1_208;
    s32 temp_r30_270;
    s32 temp_r3_227;
    s32 var_r0_237;

    sp28 = 0.0f;
    sp20 = 0.0f;
    sp24 = 1.0f;
    sp80 = arg0->unk30;
    sp88 = arg0->unk38;
    sp70 = (f64) sp20;
    sp78 = (f64) sp28;
    ((Volume *) &sp30)->GetRandPos();
    sp60 = sp30;
    sp68 = sp38;
    temp_f0_173 = sp30 - arg0->unk30;
    sp10 = temp_f0_173;
    temp_f3_179 = arg0->unk4;
    sp50 = temp_f0_173;
    sp18 = (f32) sp68 - (f32) M2C_FIELD(arg0, f64 *, 0x38);
    (*(f32 *) ((u8 *) &sp48 + 0xc)) = temp_f3_179;
    sp58 = (f64) sp18;
    var_f31_192 = ((f32) sp58 * (f32) sp58) + (((f32) sp50 * (f32) sp50) + (temp_f3_179 * temp_f3_179));
    if (var_f31_192 > 0.000001f) {
        if (var_f31_192 > 0.0f) {
            temp_f1_198 = __frsqrte(var_f31_192);
            temp_f1_204 = 0.5 * temp_f1_198 * -(((f64) var_f31_192 * (temp_f1_198 * temp_f1_198)) - 3.0);
            temp_f1_208 = 0.5 * temp_f1_204 * -(((f64) var_f31_192 * (temp_f1_204 * temp_f1_204)) - 3.0);
            var_f31_192 = (f32) ((f64) var_f31_192 * (0.5 * temp_f1_208 * -(((f64) var_f31_192 * (temp_f1_208 * temp_f1_208)) - 3.0)));
        } else if (var_f31_192 < M2C_BITWISE(f32, 0.0)) {
            var_f31_192 = __float_nan;
        } else {
            sp8 = var_f31_192;
            temp_r3_227 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_227) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_237 = 1;
                } else {
                    var_r0_237 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_237 = 5;
                } else {
                    var_r0_237 = 3;
                }
                break;
            default:
                var_r0_237 = 4;
                break;
            }
            if (var_r0_237 == 1) {
                var_f31_192 = __float_nan;
            }
        }
        var_f3_259 = 1.0f / var_f31_192;
    } else {
        var_f3_259 = 0.0f;
        var_f31_192 = 0.0f;
    }
    temp_r30_270 = arg0->unk60;
    sp50 = (f32) sp50 * var_f3_259;
    (*(f32 *) ((u8 *) &sp48 + 0xc)) *= var_f3_259;
    sp58 = (f32) sp58 * var_f3_259;
    arg0->unk50 = M2C_FIELD((checked_cast<MudGutsCritterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (temp_r30_270 * 4)), void **, 0x70);
    arg0->unk58 = 30.0f / (30.0f * ((f32) M2C_FIELD(arg0->unk50, s16 *, 4) / 30.0f));
    arg0->unk54 = 0.0f;
    arg0->unk64 = var_f31_192 / 200.0f;
    sp40 = (f64) sp50;
    sp48 = (f64) sp58;
    KDMath_BuildMatrixFromUp((Matrix *) arg0, *((MKVector3 *) &sp70), *((MKVector3 *) &sp40));
    M2C_FIELD(arg0, f64 *, 0x30) = (f32) sp80;
    M2C_FIELD(arg0, f32 *, 0x34) = (*(f32 *) ((u8 *) &sp80 + 0x4));
    M2C_FIELD(arg0, f64 *, 0x38) = (f32) sp88;
    M2C_FIELD(arg0, f32 *, 0x3C) = 1.0f;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to
void *MudGutsCritter::Update() {
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    MKVector3 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f64 sp8;
    MudGuts *temp_r29_339;
    f32 temp_f1_430;
    f64 temp_f0_377;
    s32 temp_r0_348;
    s32 var_r30_333;
    s32 var_r31_334;

    var_r30_333 = 0;
    var_r31_334 = 0;
loop_15:
    if (var_r30_333 < (s32) this->unk90) {
        temp_r29_339 = ((u8 *) this->unk170) + var_r31_334;
        temp_r29_339->unk64 -= gUpdateTimeDelta;
        temp_r29_339->unk54 += temp_r29_339->unk58 * gUpdateTimeDelta;
        temp_r0_348 = temp_r29_339->unk60;
        if (temp_r0_348 < 2) {
            if (temp_r0_348 < 0) {

            } else {
                sp18 = -temp_r29_339->unk20;
                sp1C = -temp_r29_339->unk24;
                sp20 = -temp_r29_339->unk28;
                sp48 = (f64) sp18;
                sp50 = (f64) sp20;
                sp28.operator*(200.0f * gUpdateTimeDelta);
                temp_f0_377 = *(temp_r29_339 + 0x30) + M2C_BITWISE(f64, sp28);
                sp8 = temp_f0_377;
                sp38 = temp_f0_377;
                sp10 = M2C_FIELD(temp_r29_339, f32 *, 0x38) + sp28.unk8;
                M2C_FIELD(temp_r29_339, f32 *, 0x30) = (f32) sp38;
                sp40 = (f64) sp10;
                M2C_FIELD(temp_r29_339, f32 *, 0x34) = (*(f32 *) ((u8 *) &sp38 + 0x4));
                M2C_FIELD(temp_r29_339, f32 *, 0x38) = (f32) sp40;
                M2C_FIELD(temp_r29_339, f32 *, 0x3C) = 1.0f;
                if (((temp_r29_339->unk64 <= 0.0f) && ((s32) temp_r29_339->unk60 == 0)) || (((s32) temp_r29_339->unk60 == 1) && (temp_r29_339->unk54 >= 1.0f))) {
                    if (MKRand_Int((int *) &gViewSeed, 0, 5) == 0) {
                        temp_r29_339->unk60 = 1;
                    } else {
                        temp_r29_339->unk60 = 0;
                    }
                    FindNewSwimParameters(temp_r29_339);
                }
                temp_f1_430 = temp_r29_339->unk54;
                if (temp_f1_430 > 1.0f) {
                    temp_r29_339->unk54 = temp_f1_430 - 1.0f;
                }
            }
        }
        var_r30_333 += 1;
        var_r31_334 += 0x70;
        goto loop_15;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to
f32 MudGutsCritter::Resolve() {
    f32 sp8;
    MudGuts *temp_r28_471;
    s32 var_r29_464;
    s32 var_r31_465;

    MKProp::Resolve();
    var_r29_464 = 0;
    var_r31_465 = 0;
loop_2:
    if (var_r29_464 < (s32) this->unk90) {
        temp_r28_471 = ((u8 *) this->unk170) + var_r31_465;
        M2C_STRUCT_COPY(temp_r28_471, &Matrix::identity, 0x40);
        ((Volume *) &sp8)->GetRandPos();
        M2C_FIELD(temp_r28_471, f32 *, 0x30) = sp8;
        M2C_FIELD(temp_r28_471, f32 *, 0x34) = spC;
        M2C_FIELD(temp_r28_471, f32 *, 0x38) = sp10;
        M2C_FIELD(temp_r28_471, f32 *, 0x3C) = 1.0f;
        temp_r28_471->unk60 = 0;
        FindNewSwimParameters(temp_r28_471);
        var_r29_464 += 1;
        var_r31_465 += 0x70;
        goto loop_2;
    }
}
#endif

s32 MudGutsCritter::LoadDone() {
    MKHeap *temp_r3_521;
    s32 temp_r31_520;
    void *var_r3_528;

    Critters::LoadDone();
    temp_r31_520 = this->unk90 * 0x70;
    temp_r3_521 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_521 != NULL) {
        var_r3_528 = ((MKHeap *) (temp_r3_521->Current()))->Alloc(temp_r31_520, NULL, 0);
    } else {
        var_r3_528 = malloc(temp_r31_520);
    }
    this->unk170 = var_r3_528;
}

void MudGutsCritter::Init() {
    Critters::Init();
}

void MudGutsCritterDescriptor::Deinit() {
    KDPropDescriptor::Deinit();
}

void MudGutsCritterDescriptor::LoadDone() {
    s8 *temp_r31_577;
    s8 *temp_r31_595;
    void *var_r3_587;
    void *var_r3_605;

    KDPropDescriptor::LoadDone();
    temp_r31_577 = this->unk34;
    if (((MKAnimScript *) temp_r31_577)->Exists("Swim") != 0) {
        var_r3_587 = ((MKAnimScript *) temp_r31_577)->GetAnim("Swim");
    } else {
        var_r3_587 = NULL;
    }
    this->unk70 = (s32) var_r3_587;
    temp_r31_595 = this->unk34;
    if (((MKAnimScript *) temp_r31_595)->Exists("Jump") != 0) {
        var_r3_605 = ((MKAnimScript *) temp_r31_595)->GetAnim("Jump");
    } else {
        var_r3_605 = NULL;
    }
    this->unk74 = (s32) var_r3_605;
}

void MudGutsCritterDescriptor::Init() {
    KDPropDescriptor::Init();
}
