#include "spyro/source/ElecZapCrystal.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "spyro/source/EmbersPS.h"
#include "spyro/source/KDProp.h"
#include "common/Source/MKModel.h"
#include "common/Source/StdMath.h"
#include "common/Source/Str.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

M2C_UNK free(M2C_UNK *);                            /* extern */
M2C_UNK *malloc(M2C_UNK);                           /* extern */
extern s32 GS_LightningCrystal1;
extern s32 GS_LightningCrystal2;
extern M2C_UNK gEmptyPtrListDL;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;

#if 0 // DRAFT: undefined identifier 'unkB0'
void ElecZapCrystal::TriggerSubObjFader(int arg0, float arg1) {
    M2C_UNK *temp_r3_51;
    M2C_UNK *temp_r5_45;
    M2C_UNK *temp_r5_49;

    temp_r5_45 = this->unkB0;
    if ((u32) M2C_FIELD(temp_r5_45, u32 *, -4) != 0U) {
        temp_r5_49 = temp_r5_45 - 4;
        this->unkB0 = temp_r5_49;
        temp_r3_51 = *temp_r5_49;
        if (temp_r3_51 != NULL) {
            M2C_FIELD(temp_r3_51, M2C_UNK **, 0) = (M2C_UNK *) arg0;
            M2C_FIELD(temp_r3_51, f32 *, 8) = arg1;
            M2C_FIELD(temp_r3_51, f32 *, 4) = arg1;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unkB0'
void ElecZapCrystal::Deinit() {
    M2C_UNK *temp_r0_73;
    M2C_UNK *temp_r0_92;
    M2C_UNK *var_r31_69;
    M2C_UNK *var_r3_70;
    M2C_UNK *var_r4_68;
    MKHeap *temp_r3_95;
    u32 temp_r0_78;

    var_r4_68 = this->unkB0;
    var_r31_69 = var_r4_68;
    var_r3_70 = var_r4_68;
loop_3:
    temp_r0_78 = M2C_FIELD(var_r3_70, u32 *, -4);
    var_r3_70 -= 4;
    if (temp_r0_78 != 0U) {
        temp_r0_73 = *var_r3_70;
        if (temp_r0_73 < var_r31_69) {
            var_r31_69 = temp_r0_73;
        }
        goto loop_3;
    }
    if (var_r3_70 != &gEmptyPtrListDL) {
loop_9:
        temp_r0_92 = *var_r4_68;
        if (temp_r0_92 != NULL) {
            if (temp_r0_92 < var_r31_69) {
                var_r31_69 = temp_r0_92;
            }
            var_r4_68 += 4;
            goto loop_9;
        }
        temp_r3_95 = var_r3_70->Current();
        if (temp_r3_95 != NULL) {
            ((MKHeap *) (temp_r3_95->Current()))->Free(var_r31_69, NULL, 0);
        } else {
            free(var_r31_69);
        }
    }
    this->unkB0 = NULL;
    KDProp::Deinit();
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void ElecZapCrystal::Draw() {
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    M2C_UNK *temp_r31_172;
    M2C_UNK *var_r30_141;
    f32 temp_f1_149;

    MKModel_SetColor(this->unk4, this->unkC8);
    MKModel_EnableOnlySubObject(this->unk4, (SubObjectType) 0, this->unk90, 1U, 1U);
    MKModel_Draw(this->unk4, NULL);
    var_r30_141 = this->unkB0;
loop_2:
    if (var_r30_141 != NULL) {
        temp_r31_172 = *var_r30_141;
        if (temp_r31_172 != NULL) {
            sp14 = 1.0f;
            temp_f1_149 = M2C_FIELD(temp_r31_172, f32 *, 8) / M2C_FIELD(temp_r31_172, f32 *, 4);
            sp10 = temp_f1_149;
            sp8 = temp_f1_149;
            spC = temp_f1_149;
            sp20 = (f64) sp10;
            sp18 = (f64) sp8;
            MKModel_SetColor(this->unk4, *((MKVector4 *) &sp18));
            MKModel_EnableOnlySubObject(this->unk4, (SubObjectType) 0, (s32) M2C_FIELD(temp_r31_172, M2C_UNK **, 0), 1U, 1U);
            MKModel_Draw(this->unk4, NULL);
            var_r30_141 += 4;
            goto loop_2;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unkB0'
void ElecZapCrystal::Update() {
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    MKVector3 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    M2C_UNK *temp_r3_229;
    M2C_UNK *temp_r3_241;
    M2C_UNK *temp_r4_232;
    M2C_UNK *var_r5_204;
    f32 temp_f27_266;
    f32 temp_f27_391;
    f32 temp_f3_209;
    f32 var_f1_210;
    s32 temp_r0_249;
    s32 var_r28_316;

    var_r5_204 = this->unkB0;
loop_10:
    if (var_r5_204 != NULL) {
        temp_r3_241 = *var_r5_204;
        if (temp_r3_241 != NULL) {
            temp_f3_209 = M2C_FIELD(temp_r3_241, f32 *, 4);
            var_f1_210 = M2C_FIELD(temp_r3_241, f32 *, 8) - gUpdateTimeDelta;
            if (var_f1_210 < temp_f3_209) {

            } else {
                var_f1_210 = temp_f3_209;
            }
            if (var_f1_210 > 0.0f) {

            } else {
                var_f1_210 = 0.0f;
            }
            M2C_FIELD(temp_r3_241, f32 *, 8) = var_f1_210;
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (M2C_FIELD(temp_r3_241, f32 *, 8) == 0.0f) {
                temp_r3_229 = this->unkB0;
                this->unkB0 = temp_r3_229 + 4;
                temp_r4_232 = *temp_r3_229;
                *temp_r3_229 = *var_r5_204;
                *var_r5_204 = temp_r4_232;
            }
            var_r5_204 += 4;
            goto loop_10;
        }
    }
    this->unkBC -= gUpdateTimeDelta;
    temp_r0_249 = this->unkB4;
    switch (temp_r0_249) {                          /* irregular */
    case 0:
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (this->unkBC == 0.0f) {
            temp_f27_266 = MKRand_Float(&gViewSeed, 0.2f, 0.5f);
            TriggerSubObjFader(M2C_FIELD((this + (MKRand_Int(&gViewSeed, 0, 4) * 4)), s32 *, 0xA0), temp_f27_266);
            this->unkB4 = 1;
            this->unkBC = 0.5f;
            MKModel_CalculateRefPointWorldPosition(this->unk4, this->unkB8, &this->unkD8);
            KDSound_Play3d(GS_LightningCrystal1, &this->unkD8, 0U, -1, 0.0f, 0U);
            sp54 = 0.8f;
            sp50 = 1.0f;
            sp58 = 0.9f;
            sp5C = 1.0f;
            spB0 = (f64) sp50;
            spB8 = (f64) sp58;
            ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(this->unkD8, MKVector3::zero, 60.0f, *((MKVector4 *) &spB0), 0.0f);
            var_r28_316 = 0;
            do {
                sp48 = -1.0f;
                sp38 = 1.0f;
                sp40 = -1.0f;
                sp44 = 0.0f;
                sp30 = 1.0f;
                sp34 = 1.0f;
                sp80 = (f64) sp40;
                sp88 = (f64) sp48;
                sp70 = (f64) sp30;
                sp78 = (f64) sp38;
                KDRand_Vector(sp90, *((MKVector3 *) &sp80));
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r29, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
                spA0 = sp20;
                sp28 = sp90.unk8 * 2000.0f;
                spA8 = (f64) sp28;
                sp8 = MKRand_Float(&gViewSeed, 10.0f, 20.0f);
                sp18 = MKRand_Float(&gViewSeed, 0.4f, 1.0f);
                sp1C = 1.0f;
                sp10 = 1.0f;
                sp14 = 0.4f;
                sp68 = (f64) sp18;
                sp60 = (f64) sp10;
                ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(this->unkD8, *((MKVector3 *) &spA0), sp8, *((MKVector4 *) &sp60), -2000.0f);
                var_r28_316 += 1;
            } while (var_r28_316 < 0x14);
            return;
        }
        return;
    case 1:
        this->unkC0 -= gUpdateTimeDelta;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (this->unkC0 == 0.0f) {
            temp_f27_391 = MKRand_Float(&gViewSeed, 0.1f, 0.4f);
            TriggerSubObjFader(M2C_FIELD((this + (MKRand_Int(&gViewSeed, 0, 3) * 4)), s32 *, 0x94), temp_f27_391);
            KDSound_Play3d(GS_LightningCrystal2, &this->unkD8, 0U, -1, 0.0f, 0U);
            this->unkC0 = MKRand_Float(&gViewSeed, 0.1f, 0.2f);
        }
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (this->unkBC == 0.0f) {
            this->unkB4 = 0;
            this->unkBC = MKRand_Float(&gViewSeed, 0.5f, 1.0f);
        }
        break;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void ElecZapCrystal::LoadDone() {
    f32 var_f1_464;
    s32 temp_r0_481;
    s32 temp_r0_501;
    s32 var_r28_469;
    s32 var_r28_488;
    s32 var_r30_470;
    s32 var_r30_490;
    u16 temp_ret_464;
    u16 temp_ret_479;
    u16 temp_ret_499;

    KDProp::LoadDone();
    M2C_FIELD(this, f64 *, 0xC8) = (f64) M2C_FIELD(&MKProp::loadInfo, f64 *, 0x70);
    M2C_FIELD(this, f64 *, 0xD0) = (f64) M2C_FIELD(&MKProp::loadInfo, f64 *, 0x78);
    temp_ret_464 = Tools_GetMatchingSubObjectIndex((SubObjectType) 0, this->unk4, "BlueCrystal");
    var_f1_464 = M2C_BITWISE(f32, temp_ret_464);
    this->unk90 = (s32) temp_ret_464;
    var_r28_469 = 0;
    var_r30_470 = 0;
    do {
        temp_ret_479 = Tools_GetMatchingSubObjectIndex((SubObjectType) 0, this->unk4, Str_Printf("Elec%d", var_r28_469 + 1, var_f1_464));
        var_f1_464 = M2C_BITWISE(f32, temp_ret_479);
        var_r28_469 += 1;
        temp_r0_481 = var_r30_470 + 0x94;
        var_r30_470 += 4;
        *(this + temp_r0_481) = (s32) temp_ret_479;
    } while (var_r28_469 < 3);
    var_r28_488 = 0;
    var_r30_490 = 0;
    do {
        temp_ret_499 = Tools_GetMatchingSubObjectIndex((SubObjectType) 0, this->unk4, Str_Printf("Strike%d", var_r28_488 + 1, var_f1_464));
        var_f1_464 = M2C_BITWISE(f32, temp_ret_499);
        var_r28_488 += 1;
        temp_r0_501 = var_r30_490 + 0xA0;
        var_r30_490 += 4;
        *(this + temp_r0_501) = (s32) temp_ret_499;
    } while (var_r28_488 < 4);
    this->unkB8 = (s32) Tools_GetMatchingRefPointIndex(this->unk4, "FX");
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void ElecZapCrystal::Init() {
    M2C_UNK *temp_r3_552;
    M2C_UNK *temp_r3_558;
    M2C_UNK *var_r3_537;
    M2C_UNK *var_r5_546;
    MKHeap *temp_r3_530;
    s32 var_ctr_550;

    KDProp::Init();
    temp_r3_530 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_530 != NULL) {
        var_r3_537 = ((MKHeap *) (temp_r3_530->Current()))->Alloc(0x88, NULL, 0);
    } else {
        var_r3_537 = malloc(0x88);
    }
    this->unkB0 = var_r3_537;
    var_r5_546 = this->unkB0;
    this->unkB0 = var_r5_546 + 0x60;
    M2C_FIELD(var_r5_546, s32 *, 0x60) = 0;
    var_ctr_550 = 8;
    do {
        temp_r3_552 = this->unkB0;
        this->unkB0 = temp_r3_552 + 4;
        M2C_FIELD(temp_r3_552, M2C_UNK **, 4) = var_r5_546;
        var_r5_546 += 0xC;
        var_ctr_550 -= 1;
    } while (var_ctr_550 != 0);
    temp_r3_558 = this->unkB0;
    this->unkB0 = temp_r3_558 + 4;
    M2C_FIELD(temp_r3_558, M2C_UNK **, 4) = NULL;
    this->unkBC = 0.0f;
    this->unkB4 = 0;
    this->unkC0 = 0.0f;
    this->unkD8.unk0 = 0.0f;
    this->unkD8.unk4 = 0.0f;
    this->unkD8.unk8 = 0.0f;
    this->unkC8.unk0 = 1.0f;
    this->unkC8.unk4 = 1.0f;
    this->unkC8.unk8 = 1.0f;
    this->unkC8.unkC = 1.0f;
}
#endif
