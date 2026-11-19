#include "spyro/source/ScorchTrail.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "unplaced_templates.h"
#include "common/Source/MKView.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKModel_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include <m2c_macros.h>

M2C_UNK free(MKHeap *);                             /* extern */
MKHeap *malloc(M2C_UNK);                            /* extern */
extern M2C_UNK gEmptyPtrListDL;
extern s32 gRenderState;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void ScorchTrail::SpawnScorchMark(const MKVector3 &arg0, const MKVector3 &arg1, float arg2) {
    void **temp_r6_45;
    void **temp_r6_49;
    void *temp_r31_51;

    temp_r6_45 = M2C_FIELD(this, void ***, 0x60);
    if ((u32) M2C_FIELD(temp_r6_45, u32 *, -4) != 0U) {
        temp_r6_49 = temp_r6_45 - 4;
        M2C_FIELD(this, void ***, 0x60) = temp_r6_49;
        temp_r31_51 = *temp_r6_49;
        if (temp_r31_51 != NULL) {
            M2C_FIELD(temp_r31_51, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
            M2C_FIELD(temp_r31_51, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
            M2C_FIELD(temp_r31_51, f64 *, 0x10) = (f64) M2C_FIELD(&arg1, f64 *, 0);
            M2C_FIELD(temp_r31_51, f64 *, 0x18) = (f64) M2C_FIELD(&arg1, f64 *, 8);
            M2C_FIELD(temp_r31_51, f32 *, 0x20) = arg2;
            M2C_FIELD(temp_r31_51, f32 *, 0x24) = 2.0f;
            M2C_FIELD(temp_r31_51, f32 *, 0x28) = MKRand_Float(&gViewSeed, 0.0f, 6.2831855f);
        }
    }
}
#endif

#if 0 // DRAFT: ')' expected
void ScorchTrail::DrawScorchMarks() {
    f32 temp_f27_287;
    f32 temp_f2_214;
    f32 temp_f3_182;
    f32 temp_f5_180;
    f32 temp_f5_217;
    f32 temp_f7_176;
    f32 temp_f7_210;
    f32 var_f0_273;
    void **var_r27_154;
    void *temp_r28_344;
    MKMaterial_SetMaterial(M2C_FIELD(checked_cast<ScorchTrailDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKMaterial **, 0x6C));
    MKPrimitive(0xC, 0);
    arg_sp78 = 0.0f;
    arg_sp68 = 0.0f;
    arg_sp58 = 0.0f;
    arg_sp48 = 0.0f;
    arg_sp70 = -50.0f;
    arg_sp74 = 50.0f;
    arg_sp60 = 50.0f;
    arg_sp64 = 50.0f;
    arg_sp50 = -50.0f;
    arg_sp54 = -50.0f;
    arg_sp40 = 50.0f;
    arg_sp44 = -50.0f;
    arg_sp80 = 1.0f;
    arg_sp84 = 1.0f;
    arg_sp88 = 1.0f;
    arg_sp8C = 1.0f;
    arg_sp190 = (f64) arg_sp70;
    arg_sp198 = (f64) arg_sp78;
    arg_sp1A0 = (f64) arg_sp60;
    arg_sp1A8 = (f64) arg_sp68;
    arg_sp1B0 = (f64) arg_sp50;
    arg_sp1B8 = (f64) arg_sp58;
    arg_sp1C0 = (f64) arg_sp40;
    arg_sp1C8 = (f64) arg_sp48;
    arg_sp120 = (f64) arg_sp80;
    arg_sp128 = (f64) arg_sp88;
    arg_sp110 = (f64) arg_sp70;
    var_r27_154 = M2C_FIELD(this, void ***, 0x60);
    arg_sp118 = (f64) arg_sp78;
    arg_sp100 = (f64) arg_sp60;
    arg_sp108 = (f64) arg_sp68;
    arg_spF0 = (f64) arg_sp50;
    arg_spF8 = (f64) arg_sp58;
    arg_spE0 = (f64) arg_sp40;
    arg_spE8 = (f64) arg_sp48;
loop_8:
    if (var_r27_154 != NULL) {
        temp_r28_344 = *var_r27_154;
        if (temp_r28_344 != NULL) {
            M2C_STRUCT_COPY((s32) &arg_sp1CC + 4, (s32) (&identity - 4) + 4, 0x40);
            arg_sp38 = 0.0f;
            temp_f7_176 = M2C_FIELD(temp_r28_344, f32 *, 0x18);
            arg_sp30 = 0.0f;
            temp_f5_180 = M2C_FIELD(temp_r28_344, f32 *, 0x14);
            arg_sp34 = 1.0f;
            temp_f3_182 = M2C_FIELD(temp_r28_344, f32 *, 0x10);
            arg_sp148 = (f64) arg_sp38;
            arg_sp140 = (f64) arg_sp30;
            arg_spD0 = (f64) arg_sp30;
            arg_spD8 = (f64) arg_sp38;
            arg_sp20 = (arg_sp144 * temp_f7_176) - ((f32) arg_sp148 * temp_f5_180);
            arg_sp24 = ((f32) arg_sp148 * temp_f3_182) - ((f32) arg_sp140 * temp_f7_176);
            arg_sp28 = ((f32) arg_sp140 * temp_f5_180) - (arg_sp144 * temp_f3_182);
            arg_spB0 = (f64) arg_sp20;
            arg_spB8 = (f64) arg_sp28;
            Normalise(*((MKVector3 *) &arg_spC0));
            arg_sp130 = arg_spC0;
            temp_f7_210 = M2C_FIELD(temp_r28_344, f32 *, 0x14);
            arg_sp138 = arg_spC8;
            temp_f2_214 = M2C_FIELD(temp_r28_344, f32 *, 0x10);
            temp_f5_217 = M2C_FIELD(temp_r28_344, f32 *, 0x18);
            arg_sp18 = (temp_f2_214 * arg_sp134) - (temp_f7_210 * (f32) arg_sp130);
            arg_sp14 = (temp_f5_217 * (f32) arg_sp130) - (temp_f2_214 * (f32) arg_sp138);
            arg_sp10 = (temp_f7_210 * (f32) arg_sp138) - (temp_f5_217 * arg_sp134);
            arg_sp98 = (f64) arg_sp18;
            arg_sp90 = (f64) arg_sp10;
            Normalise(*((MKVector3 *) &arg_spA0));
            arg_sp140 = arg_spA0;
            arg_sp148 = arg_spA8;
            arg_sp1D0 = (f32) arg_sp130;
            arg_sp1D4 = arg_sp134;
            arg_sp1D8 = (f32) arg_sp138;
            arg_sp1DC = 0.0f;
            arg_sp1E0 = (f32) arg_sp140;
            arg_sp1E4 = arg_sp144;
            arg_sp1E8 = (f32) arg_sp148;
            arg_sp1EC = 0.0f;
            arg_sp1F0 = M2C_FIELD(temp_r28_344, f32 *, 0x10);
            arg_sp1F4 = M2C_FIELD(temp_r28_344, f32 *, 0x14);
            arg_sp1F8 = M2C_FIELD(temp_r28_344, f32 *, 0x18);
            arg_sp1FC = 0.0f;
            M2C_STRUCT_COPY((s32) &arg_sp14C + 4, (s32) (&identity - 4) + 4, 0x40);
            arg_sp150.SetRotationRoll(M2C_FIELD(temp_r28_344, f32 *, 0x28));
            arg_sp1D0.Multiply((Matrix *) &arg_sp150, (Matrix *) &arg_sp1D0);
            var_f0_273 = M2C_FIELD(temp_r28_344, f32 *, 0x24);
            if (var_f0_273 < 2.0f) {

            } else {
                var_f0_273 = 2.0f;
            }
            if (var_f0_273 > 0.0f) {

            } else {
                var_f0_273 = 0.0f;
            }
            temp_f27_287 = var_f0_273 * 0.5f;
            arg_sp1D0.Scale3x3((Matrix *) &arg_sp1D0, M2C_FIELD(temp_r28_344, f32 *, 0x20) * (1.0f + temp_f27_287));
            arg_sp200 = M2C_FIELD(temp_r28_344, f32 *, 0);
            arg_sp204 = M2C_FIELD(temp_r28_344, f32 *, 4);
            arg_sp208 = M2C_FIELD(temp_r28_344, f32 *, 8);
            arg_sp20C = 1.0f;
            MKSetMatrix(identity);
            MKSetMatrix(*((Matrix *) &arg_sp1D0));
            arg_sp120 = temp_f27_287;
            arg_sp124 = temp_f27_287;
            arg_sp128 = temp_f27_287;
            arg_sp12C = 1.0f;
            MKBegin(4);
            MKSetColorV(*((MKVector4 *) &arg_sp120));
            MKSetTexCoord1F(0.0f, 0.0f);
            MKSetPositionV(*((MKVector3 *) &arg_sp1A0));
            MKSetColorV(*((MKVector4 *) &arg_sp120));
            MKSetTexCoord1F(1.0f, 0.0f);
            MKSetPositionV(*((MKVector3 *) &arg_sp190));
            MKSetColorV(*((MKVector4 *) &arg_sp120));
            MKSetTexCoord1F(0.0f, 1.0f);
            MKSetPositionV(*((MKVector3 *) &arg_sp1C0));
            MKSetColorV(*((MKVector4 *) &arg_sp120));
            MKSetTexCoord1F(1.0f, 1.0f);
            MKSetPositionV(*((MKVector3 *) &arg_sp1B0));
            MKEnd();
            var_r27_154 += 4;
            goto loop_8;
        }
    }
    MKEndPrimitive();
}
#endif

void ScorchTrail::UpdateScorchMarks() {
    void **temp_r4_382;
    void **var_r6_370;
    void *temp_r4_394;
    void *temp_r5_385;

    var_r6_370 = M2C_FIELD(this, void ***, 0x60);
loop_4:
    if (var_r6_370 != NULL) {
        temp_r4_394 = *var_r6_370;
        if (temp_r4_394 == NULL) {
            return;
        }
        M2C_FIELD(temp_r4_394, f32 *, 0x24) = (f32) (M2C_FIELD(temp_r4_394, f32 *, 0x24) - gUpdateTimeDelta);
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (M2C_FIELD(temp_r4_394, f32 *, 0x24) == 0.0f) {
            temp_r4_382 = M2C_FIELD(this, void ***, 0x60);
            M2C_FIELD(this, void ***, 0x60) = (void **) (temp_r4_382 + 4);
            temp_r5_385 = *temp_r4_382;
            *temp_r4_382 = *var_r6_370;
            *var_r6_370 = temp_r5_385;
        }
        var_r6_370 += 4;
        goto loop_4;
    }
}

void ScorchTrail::SpawnPlasmaBubble(const MKVector3 &arg0, const MKVector3 &arg1, float arg2) {
    void **temp_r6_403;
    void **temp_r6_407;
    void *temp_r3_409;

    temp_r6_403 = M2C_FIELD(this, void ***, 0x5C);
    if ((u32) M2C_FIELD(temp_r6_403, u32 *, -4) != 0U) {
        temp_r6_407 = temp_r6_403 - 4;
        M2C_FIELD(this, void ***, 0x5C) = temp_r6_407;
        temp_r3_409 = *temp_r6_407;
        if (temp_r3_409 != NULL) {
            M2C_FIELD(temp_r3_409, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
            M2C_FIELD(temp_r3_409, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
            M2C_FIELD(temp_r3_409, f64 *, 0x10) = (f64) M2C_FIELD(&arg1, f64 *, 0);
            M2C_FIELD(temp_r3_409, f64 *, 0x18) = (f64) M2C_FIELD(&arg1, f64 *, 8);
            M2C_FIELD(temp_r3_409, f32 *, 0x20) = arg2;
            M2C_FIELD(temp_r3_409, f32 *, 0x24) = 4.0f;
        }
    }
}

#if 0 // DRAFT: undefined identifier 'arg_spCC'
void ScorchTrail::DrawPlasmaBubbles() {
    f32 temp_f27_569;
    f32 temp_f2_513;
    f32 temp_f3_481;
    f32 temp_f5_479;
    f32 temp_f5_516;
    f32 temp_f7_475;
    f32 temp_f7_509;
    f32 var_f0_555;
    void **var_r28_458;
    void *temp_r29_603;
    void *temp_r3_448;
    temp_r3_448 = checked_cast<ScorchTrailDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    gRenderState = M2C_FIELD(temp_r3_448, s32 *, 0x68);
    var_r28_458 = M2C_FIELD(this, void ***, 0x5C);
loop_8:
    if (var_r28_458 != NULL) {
        temp_r29_603 = *var_r28_458;
        if (temp_r29_603 != NULL) {
            M2C_STRUCT_COPY((s32) &arg_spCC + 4, (s32) (&identity - 4) + 4, 0x40);
            arg_sp38 = 0.0f;
            temp_f7_475 = M2C_FIELD(temp_r29_603, f32 *, 0x18);
            arg_sp30 = 0.0f;
            temp_f5_479 = M2C_FIELD(temp_r29_603, f32 *, 0x14);
            arg_sp34 = 1.0f;
            temp_f3_481 = M2C_FIELD(temp_r29_603, f32 *, 0x10);
            arg_spB8 = (f64) arg_sp38;
            arg_spB0 = (f64) arg_sp30;
            arg_spA0 = (f64) arg_sp30;
            arg_spA8 = (f64) arg_sp38;
            arg_sp20 = (arg_spB4 * temp_f7_475) - ((f32) arg_spB8 * temp_f5_479);
            arg_sp24 = ((f32) arg_spB8 * temp_f3_481) - ((f32) arg_spB0 * temp_f7_475);
            arg_sp28 = ((f32) arg_spB0 * temp_f5_479) - (arg_spB4 * temp_f3_481);
            arg_sp80 = (f64) arg_sp20;
            arg_sp88 = (f64) arg_sp28;
            Normalise(*((MKVector3 *) &arg_sp90));
            arg_spC0 = arg_sp90;
            temp_f7_509 = M2C_FIELD(temp_r29_603, f32 *, 0x14);
            arg_spC8 = arg_sp98;
            temp_f2_513 = M2C_FIELD(temp_r29_603, f32 *, 0x10);
            temp_f5_516 = M2C_FIELD(temp_r29_603, f32 *, 0x18);
            arg_sp18 = (temp_f2_513 * arg_spC4) - (temp_f7_509 * (f32) arg_spC0);
            arg_sp14 = (temp_f5_516 * (f32) arg_spC0) - (temp_f2_513 * (f32) arg_spC8);
            arg_sp10 = (temp_f7_509 * (f32) arg_spC8) - (temp_f5_516 * arg_spC4);
            arg_sp68 = (f64) arg_sp18;
            arg_sp60 = (f64) arg_sp10;
            Normalise(*((MKVector3 *) &arg_sp70));
            arg_spB0 = arg_sp70;
            arg_spB8 = arg_sp78;
            arg_spD0 = (f32) arg_spC0;
            arg_spD4 = arg_spC4;
            arg_spD8 = (f32) arg_spC8;
            arg_spDC = 0.0f;
            arg_spE0 = (f32) arg_spB0;
            arg_spE4 = arg_spB4;
            arg_spE8 = (f32) arg_spB8;
            arg_spEC = 0.0f;
            arg_spF0 = M2C_FIELD(temp_r29_603, f32 *, 0x10);
            arg_spF4 = M2C_FIELD(temp_r29_603, f32 *, 0x14);
            arg_spF8 = M2C_FIELD(temp_r29_603, f32 *, 0x18);
            arg_spFC = 0.0f;
            var_f0_555 = M2C_FIELD(temp_r29_603, f32 *, 0x24);
            if (var_f0_555 < 4.0f) {

            } else {
                var_f0_555 = 4.0f;
            }
            if (var_f0_555 > 0.0f) {

            } else {
                var_f0_555 = 0.0f;
            }
            temp_f27_569 = var_f0_555 * 0.25f;
            arg_spD0.Scale3x3((Matrix *) &arg_spD0, M2C_FIELD(temp_r29_603, f32 *, 0x20) * temp_f27_569);
            arg_sp100 = M2C_FIELD(temp_r29_603, f32 *, 0);
            arg_sp104 = M2C_FIELD(temp_r29_603, f32 *, 4);
            arg_sp108 = M2C_FIELD(temp_r29_603, f32 *, 8);
            arg_sp10C = 1.0f;
            MKModel_SetWorldMatrix(M2C_FIELD(temp_r3_448, MKModel **, 0x64), *((Matrix *) &arg_spD0));
            arg_sp40 = temp_f27_569;
            arg_sp44 = temp_f27_569;
            arg_sp48 = temp_f27_569;
            arg_sp4C = 1.0f;
            arg_sp50 = (f64) arg_sp40;
            arg_sp58 = (f64) arg_sp48;
            MKModel_SetColor(M2C_FIELD(temp_r3_448, MKModel **, 0x64), *((MKVector4 *) &arg_sp50));
            MKModel_Draw(M2C_FIELD(temp_r3_448, MKModel **, 0x64), NULL);
            var_r28_458 += 4;
            goto loop_8;
        }
    }
    gRenderState = 0;
}
#endif

void ScorchTrail::UpdatePlasmaBubbles() {
    void **temp_r4_643;
    void **var_r6_631;
    void *temp_r4_655;
    void *temp_r5_646;

    var_r6_631 = M2C_FIELD(this, void ***, 0x5C);
loop_4:
    if (var_r6_631 != NULL) {
        temp_r4_655 = *var_r6_631;
        if (temp_r4_655 == NULL) {
            return;
        }
        M2C_FIELD(temp_r4_655, f32 *, 0x24) = (f32) (M2C_FIELD(temp_r4_655, f32 *, 0x24) - gUpdateTimeDelta);
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (M2C_FIELD(temp_r4_655, f32 *, 0x24) == 0.0f) {
            temp_r4_643 = M2C_FIELD(this, void ***, 0x5C);
            M2C_FIELD(this, void ***, 0x5C) = (void **) (temp_r4_643 + 4);
            temp_r5_646 = *temp_r4_643;
            *temp_r4_643 = *var_r6_631;
            *var_r6_631 = temp_r5_646;
        }
        var_r6_631 += 4;
        goto loop_4;
    }
}

#if 0 // DRAFT: undefined identifier 'unk4C'
void ScorchTrail::EndTrail() {
    s32 temp_r0_680;

    if ((s32) M2C_FIELD((this->unk4C + (this->unk50 * 0x30)), s32 *, 0x24) != 0) {
        this->unk50 = this->unk54;
        M2C_FIELD((this->unk4C + (this->unk54 * 0x30)), s32 *, 0x24) = 0;
        temp_r0_680 = this->unk54 + 1;
        this->unk54 = temp_r0_680;
        if (temp_r0_680 >= 0x64) {
            this->unk54 = 0;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk4C'
void ScorchTrail::AddNode(const MKVector3 &arg0, const MKVector3 &arg1) {
    s32 *temp_r6_694;
    s32 temp_r0_738;
    s32 temp_r7_691;
    s32 var_r0_698;
    void *temp_r4_722;
    void *temp_r4_729;

    temp_r7_691 = this->unk54;
    temp_r6_694 = &this->unk4C->unk24;
    if ((s32) *(temp_r6_694 + (temp_r7_691 * 0x30)) == 0) {
        var_r0_698 = temp_r7_691 + 1;
        if (var_r0_698 >= 0x64) {
            var_r0_698 = 0;
        }
        if ((s32) *(temp_r6_694 + (var_r0_698 * 0x30)) == 0) {
            this->unk50 = temp_r7_691;
            M2C_FIELD((this->unk4C + (this->unk54 * 0x30)), s32 *, 0x24) = 1;
            temp_r4_722 = this->unk4C + (this->unk54 * 0x30);
            M2C_FIELD(temp_r4_722, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
            M2C_FIELD(temp_r4_722, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
            temp_r4_729 = this->unk4C + ((this->unk54 * 0x30) + 0x10);
            M2C_FIELD(temp_r4_729, f64 *, 0) = (f64) M2C_FIELD(&arg1, f64 *, 0);
            M2C_FIELD(temp_r4_729, f64 *, 8) = (f64) M2C_FIELD(&arg1, f64 *, 8);
            M2C_FIELD((this->unk4C + (this->unk54 * 0x30)), f32 *, 0x20) = 4.0f;
            temp_r0_738 = this->unk54 + 1;
            this->unk54 = temp_r0_738;
            if (temp_r0_738 >= 0x64) {
                this->unk54 = 0;
            }
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk4C'
void ScorchTrail::Deinit() {
    MKHeap *temp_r0_776;
    MKHeap *temp_r0_795;
    MKHeap *temp_r0_818;
    MKHeap *temp_r0_837;
    MKHeap *temp_r30_755;
    MKHeap *temp_r3_756;
    MKHeap *temp_r3_798;
    MKHeap *temp_r3_840;
    MKHeap *var_r30_772;
    MKHeap *var_r30_814;
    MKHeap *var_r3_773;
    MKHeap *var_r3_815;
    MKHeap *var_r4_771;
    MKHeap *var_r4_813;
    u32 temp_r0_781;
    u32 temp_r0_823;

    temp_r30_755 = this->unk4C;
    temp_r3_756 = MKHeap::Current();
    if (temp_r3_756 != NULL) {
        ((MKHeap *) (temp_r3_756->Current()))->Free(temp_r30_755, NULL, 0);
    } else {
        free(temp_r30_755);
    }
    this->unk4C = NULL;
    var_r4_771 = M2C_FIELD(this, MKHeap **, 0x5C);
    var_r30_772 = var_r4_771;
    var_r3_773 = var_r4_771;
loop_6:
    temp_r0_781 = M2C_FIELD(var_r3_773, u32 *, -4);
    var_r3_773 -= 4;
    if (temp_r0_781 != 0U) {
        temp_r0_776 = var_r3_773->unk0;
        if (temp_r0_776 < var_r30_772) {
            var_r30_772 = temp_r0_776;
        }
        goto loop_6;
    }
    if (var_r3_773 != &gEmptyPtrListDL) {
loop_12:
        temp_r0_795 = var_r4_771->unk0;
        if (temp_r0_795 != NULL) {
            if (temp_r0_795 < var_r30_772) {
                var_r30_772 = temp_r0_795;
            }
            var_r4_771 += 4;
            goto loop_12;
        }
        temp_r3_798 = var_r3_773->Current();
        if (temp_r3_798 != NULL) {
            ((MKHeap *) (temp_r3_798->Current()))->Free(var_r30_772, NULL, 0);
        } else {
            free(var_r30_772);
        }
    }
    M2C_FIELD(this, MKHeap **, 0x5C) = NULL;
    var_r4_813 = M2C_FIELD(this, MKHeap **, 0x60);
    var_r30_814 = var_r4_813;
    var_r3_815 = var_r4_813;
loop_19:
    temp_r0_823 = M2C_FIELD(var_r3_815, u32 *, -4);
    var_r3_815 -= 4;
    if (temp_r0_823 != 0U) {
        temp_r0_818 = var_r3_815->unk0;
        if (temp_r0_818 < var_r30_814) {
            var_r30_814 = temp_r0_818;
        }
        goto loop_19;
    }
    if (var_r3_815 != &gEmptyPtrListDL) {
loop_25:
        temp_r0_837 = var_r4_813->unk0;
        if (temp_r0_837 != NULL) {
            if (temp_r0_837 < var_r30_814) {
                var_r30_814 = temp_r0_837;
            }
            var_r4_813 += 4;
            goto loop_25;
        }
        temp_r3_840 = var_r3_815->Current();
        if (temp_r3_840 != NULL) {
            ((MKHeap *) (temp_r3_840->Current()))->Free(var_r30_814, NULL, 0);
        } else {
            free(var_r30_814);
        }
    }
    M2C_FIELD(this, MKHeap **, 0x60) = NULL;
    MKProp::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'unk4C'
void ScorchTrail::Draw() {
    f64 sp178;
    f64 sp170;
    f64 sp168;                                      /* compiler-managed */
    f64 sp160;                                      /* compiler-managed */
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
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp98;
    f32 sp88;
    f32 sp78;
    f32 sp68;
    f32 sp58;
    f32 sp48;
    f32 sp38;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKHeap *temp_r3_975;
    MKHeap *temp_r4_907;
    f32 temp_f1_1121;
    f32 temp_f2_1085;
    f32 temp_f2_896;
    f32 temp_f4_1084;
    f32 temp_f5_1083;
    f32 temp_f6_1080;
    f32 temp_f7_1079;
    f32 temp_f8_1077;
    f32 var_f0_1107;
    f32 var_f25_948;
    f32 var_f26_1125;
    f32 var_f3_1068;
    f32 var_f4_1001;
    f64 temp_f1_1007;
    f64 temp_f1_1013;
    f64 temp_f1_1017;
    s32 temp_r27_1104;
    s32 temp_r30_913;
    s32 temp_r3_1036;
    s32 temp_r5_974;
    s32 var_r0_1046;
    s32 var_r0_969;
    s32 var_r27_929;
    s32 var_r29_912;
    s32 var_r31_928;
    s32 var_r5_901;
    void *temp_r3_1081;

    MKView_Push();
    MKView_GetProjection(NULL, &spC, NULL);
    temp_f2_896 = spC + 2.0f;
    spC = temp_f2_896;
    MKView_SetProjection(0.0f, temp_f2_896, 0.0f);
    var_r5_901 = this->unk50 + 1;
    if (var_r5_901 >= 0x64) {
        var_r5_901 = 0;
    }
loop_2:
    temp_r4_907 = this->unk4C;
    if ((s32) *(temp_r4_907 + ((var_r5_901 * 0x30) + 0x24)) == 1) {
        var_r29_912 = var_r5_901;
        temp_r30_913 = var_r5_901;
loop_6:
        if ((s32) *(temp_r4_907 + ((var_r5_901 * 0x30) + 0x24)) == 1) {
            var_r29_912 = var_r5_901;
            var_r5_901 += 1;
            if (var_r5_901 >= 0x64) {
                var_r5_901 = 0;
            }
            goto loop_6;
        }
        var_r31_928 = temp_r30_913;
        var_r27_929 = 0;
        if (temp_r30_913 < var_r29_912) {
            var_r27_929 = (var_r29_912 - temp_r30_913) + 1;
        } else if (temp_r30_913 > var_r29_912) {
            var_r27_929 = var_r29_912 + (0x65 - temp_r30_913);
        }
        if (var_r27_929 >= 2) {
            var_f25_948 = 0.0f;
            MKMaterial_SetMaterial(M2C_FIELD(checked_cast<ScorchTrailDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKMaterial **, 0x60));
            MKPrimitive(0xC, 0);
            MKSetMatrix(identity);
            MKBegin(var_r27_929 * 2);
loop_13:
            if (var_r31_928 != var_r29_912) {
                var_r0_969 = var_r31_928 + 1;
                if (var_r0_969 >= 0x64) {
                    var_r0_969 = 0;
                }
                temp_r5_974 = var_r31_928 * 0x30;
                temp_r3_975 = this->unk4C;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                sp160 = sp30;
                sp38 = M2C_FIELD((temp_r3_975 + (var_r0_969 * 0x30)), f32 *, 8) - M2C_FIELD((temp_r3_975 + temp_r5_974), f32 *, 8);
                sp140 = sp30;
                sp168 = (f64) sp38;
                sp148 = (f64) sp38;
                var_f4_1001 = ((f32) sp168 * (f32) sp168) + (((f32) sp160 * (f32) sp160) + (unksp164 * unksp164));
                if (var_f4_1001 > 0.000001f) {
                    if (var_f4_1001 > 0.0f) {
                        temp_f1_1007 = __frsqrte(var_f4_1001);
                        temp_f1_1013 = 0.5 * temp_f1_1007 * -(((f64) var_f4_1001 * (temp_f1_1007 * temp_f1_1007)) - 3.0);
                        temp_f1_1017 = 0.5 * temp_f1_1013 * -(((f64) var_f4_1001 * (temp_f1_1013 * temp_f1_1013)) - 3.0);
                        var_f4_1001 = (f32) ((f64) var_f4_1001 * (0.5 * temp_f1_1017 * -(((f64) var_f4_1001 * (temp_f1_1017 * temp_f1_1017)) - 3.0)));
                    } else if (var_f4_1001 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_1001 = __float_nan;
                    } else {
                        sp8 = var_f4_1001;
                        temp_r3_1036 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                        switch (temp_r3_1036) {     /* irregular */
                        case 0x7F800000:
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_1046 = 1;
                            } else {
                                var_r0_1046 = 2;
                            }
                            break;
                        case 0x0:
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_1046 = 5;
                            } else {
                                var_r0_1046 = 3;
                            }
                            break;
                        default:
                            var_r0_1046 = 4;
                            break;
                        }
                        if (var_r0_1046 == 1) {
                            var_f4_1001 = __float_nan;
                        }
                    }
                    var_f3_1068 = 1.0f / var_f4_1001;
                } else {
                    var_f3_1068 = 0.0f;
                }
                temp_f8_1077 = (f32) sp160 * var_f3_1068;
                temp_f7_1079 = unksp164 * var_f3_1068;
                temp_f6_1080 = (f32) sp168 * var_f3_1068;
                temp_r3_1081 = this->unk4C + (temp_r5_974 + 0x10);
                sp160 = temp_f8_1077;
                temp_f5_1083 = M2C_FIELD(temp_r3_1081, f32 *, 4);
                temp_f4_1084 = M2C_FIELD(temp_r3_1081, f32 *, 8);
                temp_f2_1085 = M2C_FIELD(temp_r3_1081, f32 *, 0);
                unksp164 = temp_f7_1079;
                sp168 = temp_f6_1080;
                sp28 = (temp_f2_1085 * temp_f7_1079) - (temp_f5_1083 * temp_f8_1077);
                sp20 = (temp_f5_1083 * temp_f6_1080) - (temp_f4_1084 * temp_f7_1079);
                sp24 = (temp_f4_1084 * temp_f8_1077) - (temp_f2_1085 * temp_f6_1080);
                sp138 = (f64) sp28;
                sp130 = (f64) sp20;
                sp150 = (f64) sp20;
                sp158 = (f64) sp28;
            }
            temp_r27_1104 = var_r31_928 * 0x30;
            var_f0_1107 = *(this->unk4C + (temp_r27_1104 + 0x20));
            if (var_f0_1107 < 4.0f) {

            } else {
                var_f0_1107 = 4.0f;
            }
            if (var_f0_1107 > 0.0f) {

            } else {
                var_f0_1107 = 0.0f;
            }
            temp_f1_1121 = var_f0_1107 * 0.25f;
            sp1C = 1.0f;
            sp18 = temp_f1_1121;
            var_f26_1125 = temp_f1_1121;
            sp10 = temp_f1_1121;
            sp14 = temp_f1_1121;
            sp128 = (f64) sp18;
            sp120 = (f64) sp10;
            sp170 = (f64) sp10;
            sp178 = (f64) sp18;
            if ((var_r31_928 == temp_r30_913) || (var_r31_928 == var_r29_912)) {
                var_f26_1125 = 0.0f;
            }
            MKSetColorV(*((MKVector4 *) &sp170));
            MKSetTexCoord1F(0.0f, var_f25_948);
            spA0 = -(f32) sp150;
            spA4 = -unksp154;
            spA8 = -(f32) sp158;
            spE0 = (f64) spA0;
            spE8 = (f64) spA8;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
            spF0 = sp90;
            sp98 = (f32) spE8 * this->unk58;
            spF8 = (f64) sp98;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
            sp100 = sp80;
            sp88 = (f32) spF8 * var_f26_1125;
            sp108 = (f64) sp88;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp110 = sp70;
            sp78 = M2C_FIELD((this->unk4C + temp_r27_1104), f32 *, 8) + (f32) sp108;
            sp118 = (f64) sp78;
            MKSetPositionV(*((MKVector3 *) &sp110));
            MKSetColorV(*((MKVector4 *) &sp170));
            MKSetTexCoord1F(1.0f, var_f25_948);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
            spB0 = sp60;
            sp68 = (f32) sp158 * this->unk58;
            spB8 = (f64) sp68;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
            spC0 = sp50;
            sp58 = (f32) spB8 * var_f26_1125;
            spC8 = (f64) sp58;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            spD0 = sp40;
            sp48 = M2C_FIELD((this->unk4C + temp_r27_1104), f32 *, 8) + (f32) spC8;
            spD8 = (f64) sp48;
            MKSetPositionV(*((MKVector3 *) &spD0));
            var_f25_948 += 5.0f / (f32) var_r27_929;
            if (var_r31_928 != var_r29_912) {
                var_r31_928 += 1;
                if (var_r31_928 >= 0x64) {
                    var_r31_928 = 0;
                }
                goto loop_13;
            }
            MKEnd();
            MKEndPrimitive();
        }
        var_r5_901 = var_r29_912;
        if (var_r29_912 != (s32) this->unk50) {
            goto block_51;
        }
    } else {
block_51:
        var_r5_901 += 1;
        if (var_r5_901 >= 0x64) {
            var_r5_901 = 0;
        }
        if (var_r5_901 != (s32) this->unk50) {
            goto loop_2;
        }
    }
    DrawPlasmaBubbles();
    DrawScorchMarks();
    MKView_Pop();
}
#endif

#if 0 // DRAFT: undefined identifier 'unk4C'
void ScorchTrail::Update() {
    MKHeap *temp_r4_1309;
    s32 temp_r0_1311;
    s32 temp_r5_1308;
    s32 var_r6_1300;
    void *temp_r4_1316;

    var_r6_1300 = this->unk50 + 1;
    if (var_r6_1300 >= 0x64) {
        var_r6_1300 = 0;
    }
    do {
        temp_r5_1308 = var_r6_1300 * 0x30;
        temp_r4_1309 = this->unk4C;
        temp_r0_1311 = temp_r5_1308 + 0x20;
        *(temp_r4_1309 + temp_r0_1311) = *(temp_r4_1309 + temp_r0_1311) - gUpdateTimeDelta;
        temp_r4_1316 = this->unk4C + temp_r5_1308;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (M2C_FIELD(temp_r4_1316, f32 *, 0x20) == 0.0f) {
            M2C_FIELD(temp_r4_1316, s32 *, 0x24) = 0;
        }
        var_r6_1300 += 1;
        if (var_r6_1300 >= 0x64) {
            var_r6_1300 = 0;
        }
    } while (var_r6_1300 != (s32) this->unk50);
    UpdatePlasmaBubbles();
    UpdateScorchMarks();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void ScorchTrail::Init() {
    MKHeap *temp_r3_1351;
    MKHeap *temp_r3_1376;
    MKHeap *temp_r3_1384;
    MKHeap *temp_r3_1406;
    MKHeap *temp_r3_1412;
    MKHeap *temp_r3_1417;
    MKHeap *temp_r3_1439;
    MKHeap *temp_r3_1445;
    MKHeap *var_r3_1358;
    MKHeap *var_r3_1391;
    MKHeap *var_r3_1424;
    MKHeap *var_r5_1400;
    MKHeap *var_r5_1433;
    s32 *temp_r3_1414;
    s32 temp_r0_1373;
    s32 temp_r3_1372;
    s32 var_ctr_1369;
    s32 var_ctr_1404;
    s32 var_ctr_1437;
    s32 var_r4_1364;

    MKProp::Init();
    temp_r3_1351 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_1351 != NULL) {
        var_r3_1358 = ((MKHeap *) (temp_r3_1351->Current()))->Alloc(0x12C0, NULL, 0);
    } else {
        var_r3_1358 = malloc(0x12C0);
    }
    var_r4_1364 = 0;
    this->unk4C = var_r3_1358;
    var_ctr_1369 = 0x64;
    do {
        temp_r3_1372 = var_r4_1364 + 0x24;
        temp_r0_1373 = var_r4_1364 + 0x20;
        var_r4_1364 += 0x30;
        *(this->unk4C + temp_r3_1372) = 0;
        temp_r3_1376 = this->unk4C;
        *(temp_r3_1376 + temp_r0_1373) = 0.0f;
        var_ctr_1369 -= 1;
    } while (var_ctr_1369 != 0);
    this->unk50 = 0;
    this->unk54 = 0;
    this->unk58 = 10.0f;
    temp_r3_1384 = temp_r3_1376->Current();
    if (temp_r3_1384 != NULL) {
        var_r3_1391 = ((MKHeap *) (temp_r3_1384->Current()))->Alloc(0x418, NULL, 0);
    } else {
        var_r3_1391 = malloc(0x418);
    }
    M2C_FIELD(this, MKHeap **, 0x5C) = var_r3_1391;
    var_r5_1400 = M2C_FIELD(this, MKHeap **, 0x5C);
    M2C_FIELD(this, MKHeap **, 0x5C) = (MKHeap *) (var_r5_1400 + 0x3C0);
    M2C_FIELD(var_r5_1400, s32 *, 0x3C0) = 0;
    var_ctr_1404 = 0x14;
    do {
        temp_r3_1406 = M2C_FIELD(this, MKHeap **, 0x5C);
        M2C_FIELD(this, MKHeap **, 0x5C) = (MKHeap *) &temp_r3_1406->unk4;
        temp_r3_1406->unk4 = (s32) var_r5_1400;
        var_r5_1400 += 0x30;
        var_ctr_1404 -= 1;
    } while (var_ctr_1404 != 0);
    temp_r3_1412 = M2C_FIELD(this, MKHeap **, 0x5C);
    temp_r3_1414 = &temp_r3_1412->unk4;
    M2C_FIELD(this, MKHeap **, 0x5C) = (MKHeap *) temp_r3_1414;
    temp_r3_1412->unk4 = 0;
    temp_r3_1417 = temp_r3_1414->Current();
    if (temp_r3_1417 != NULL) {
        var_r3_1424 = ((MKHeap *) (temp_r3_1417->Current()))->Alloc(0x10C, NULL, 0);
    } else {
        var_r3_1424 = malloc(0x10C);
    }
    M2C_FIELD(this, MKHeap **, 0x60) = var_r3_1424;
    var_r5_1433 = M2C_FIELD(this, MKHeap **, 0x60);
    M2C_FIELD(this, MKHeap **, 0x60) = (MKHeap *) &var_r5_1433->unkF0;
    var_r5_1433->unkF0 = 0;
    var_ctr_1437 = 5;
    do {
        temp_r3_1439 = M2C_FIELD(this, MKHeap **, 0x60);
        M2C_FIELD(this, MKHeap **, 0x60) = (MKHeap *) &temp_r3_1439->unk4;
        temp_r3_1439->unk4 = (s32) var_r5_1433;
        var_r5_1433 += 0x30;
        var_ctr_1437 -= 1;
    } while (var_ctr_1437 != 0);
    temp_r3_1445 = M2C_FIELD(this, MKHeap **, 0x60);
    M2C_FIELD(this, MKHeap **, 0x60) = (MKHeap *) &temp_r3_1445->unk4;
    temp_r3_1445->unk4 = 0;
}
#endif

void ScorchTrailDescriptor::Deinit() {
    MKMaterial *temp_r3_1465;
    MKMaterial *temp_r3_1472;
    MKMaterial *temp_r3_1477;

    temp_r3_1465 = this->unk60;
    if (temp_r3_1465 != NULL) {
        MKMaterial_Destroy(temp_r3_1465);
    }
    MKModel_Destroy(this->unk64);
    temp_r3_1472 = this->unk68;
    if (temp_r3_1472 != NULL) {
        MKMaterial_Destroy(temp_r3_1472);
    }
    temp_r3_1477 = this->unk6C;
    if (temp_r3_1477 != NULL) {
        MKMaterial_Destroy(temp_r3_1477);
    }
    MKPropDescriptor::Deinit();
}

#if 0 // DRAFT: illegal implicit conversion from 'MKResource *' to
void ScorchTrailDescriptor::Init() {
    MKPropDescriptor::Init();
    this->unk60 = MKMaterial_Create("fx_379");
    this->unk64 = MKModel_Create("p0002_lavacannonball", NULL, 2, NULL);
    this->unk68 = MKMaterial_Create("ZapEnv");
    this->unk6C = MKMaterial_Create("fx_333");
}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<ScorchTrailDescriptor *, MKPropDescriptor>(MKPropDescriptor *arg0) {

}
#endif
