#include "spyro/source/CharacterBodyFX.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "common/Source/StdMath.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

M2C_UNK free(CharacterBodyFX ***);                  /* extern */
CharacterBodyFX ***malloc(s32);                     /* extern */
extern M2C_UNK gEmptyPtrListDL;
extern s32 gViewSeed;

#if 0 // DRAFT: pointer/array required
void CharacterBodyFX::SetDataActive(bool arg0) {
    s32 temp_r0_27;
    s32 var_r4_21;
    s32 var_r7_22;

    this->unk10 = arg0;
    if (((u8) this->unk10 == 0) && ((CharacterBodyFXData *) this->unk8 != NULL) && ((u32) this->unk4 != 0U)) {
        var_r4_21 = 0;
        var_r7_22 = 0;
loop_5:
        if (var_r7_22 < (s32) this->unk8->unk4) {
            temp_r0_27 = var_r4_21 + 0x60;
            var_r7_22 += 1;
            var_r4_21 += 0x70;
            *(this->unk4 + temp_r0_27) = 0;
            goto loop_5;
        }
    }
}
#endif

void CharacterBodyFXManager::DestroyInstance(CharacterBodyFX *arg0) {
    CharacterBodyFX ***temp_r4_54;
    CharacterBodyFX ***var_r5_48;
    CharacterBodyFX **temp_r3_57;
    CharacterBodyFX **temp_r4_67;

    if (arg0 != NULL) {
        var_r5_48 = this->unk0;
loop_5:
        if (var_r5_48 != NULL) {
            temp_r4_67 = *var_r5_48;
            if (temp_r4_67 != NULL) {
                if ((CharacterBodyFX *) *temp_r4_67 == arg0) {
                    temp_r4_54 = this->unk0;
                    this->unk0 = temp_r4_54 + 4;
                    temp_r3_57 = *temp_r4_54;
                    *temp_r4_54 = *var_r5_48;
                    *var_r5_48 = temp_r3_57;
                } else {
                    var_r5_48 += 4;
                    goto loop_5;
                }
            }
        }
        arg0->Deinit();
        operator delete(arg0);
    }
}

#if 0 // DRAFT: pointer/array required
CharacterBodyFX *CharacterBodyFXManager::CreateInstance(int arg0) {
    CharacterBodyFX ***temp_r3_217;
    CharacterBodyFX *var_r30_102;

    if ((u32) M2C_FIELD(this->unk0, u32 *, -4) == 0U) {
        return NULL;
    }
    var_r30_102 = NULL;
    switch (arg0) {                                 /* irregular */
    case 0:
        operator new(0x28U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        var_r30_102 = M2C_ERROR(/* Read from unset register $r3 */);
        M2C_FIELD(*M2C_ERROR(/* Read from unset register $r3 */), M2C_UNK (**)(), 8)();
        break;
    case 1:
        operator new(0x40U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        var_r30_102 = M2C_ERROR(/* Read from unset register $r3 */);
        M2C_FIELD(*M2C_ERROR(/* Read from unset register $r3 */), M2C_UNK (**)(), 8)();
        break;
    case 2:
        operator new(0x58U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        var_r30_102 = M2C_ERROR(/* Read from unset register $r3 */);
        M2C_FIELD(*M2C_ERROR(/* Read from unset register $r3 */), M2C_UNK (**)(), 8)();
        break;
    case 3:
        operator new(0x24U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        var_r30_102 = M2C_ERROR(/* Read from unset register $r3 */);
        M2C_FIELD(*M2C_ERROR(/* Read from unset register $r3 */), M2C_UNK (**)(), 8)();
        break;
    case 4:
        operator new(0x30U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        var_r30_102 = M2C_ERROR(/* Read from unset register $r3 */);
        M2C_FIELD(*M2C_ERROR(/* Read from unset register $r3 */), M2C_UNK (**)(), 8)();
        break;
    }
    if (var_r30_102 != NULL) {
        temp_r3_217 = this->unk0 - 4;
        this->unk0 = temp_r3_217;
        **temp_r3_217 = var_r30_102;
    }
    return var_r30_102;
}
#endif

#if 0 // DRAFT: type mismatch
void CharacterBodyFXManager::Deinit() {
    CharacterBodyFX ***var_r31_239;
    CharacterBodyFX ***var_r31_267;
    CharacterBodyFX ***var_r3_268;
    CharacterBodyFX ***var_r4_263;
    CharacterBodyFX **temp_r0_271;
    CharacterBodyFX **temp_r0_290;
    CharacterBodyFX **temp_r3_254;
    CharacterBodyFX *temp_r3_242;
    MKHeap *temp_r3_293;
    u32 temp_r0_276;

    var_r31_239 = this->unk0;
loop_2:
    if (var_r31_239 != NULL) {
        temp_r3_254 = *var_r31_239;
        if (temp_r3_254 == NULL) {

        } else {
            temp_r3_242 = *temp_r3_254;
            temp_r3_242->Deinit();
            operator delete(**var_r31_239);
            var_r31_239 += 4;
            goto loop_2;
        }
    }
loop_6:
    var_r4_263 = this->unk0;
    if ((CharacterBodyFX **) *var_r4_263 != NULL) {
        this->unk0 += 4;
        goto loop_6;
    }
    var_r31_267 = var_r4_263;
    var_r3_268 = var_r4_263;
loop_10:
    temp_r0_276 = M2C_FIELD(var_r3_268, u32 *, -4);
    var_r3_268 -= 4;
    if (temp_r0_276 != 0U) {
        temp_r0_271 = *var_r3_268;
        if (temp_r0_271 < var_r31_267) {
            var_r31_267 = (CharacterBodyFX ***) temp_r0_271;
        }
        goto loop_10;
    }
    if (var_r3_268 != &gEmptyPtrListDL) {
loop_16:
        temp_r0_290 = *var_r4_263;
        if (temp_r0_290 != NULL) {
            if (temp_r0_290 < var_r31_267) {
                var_r31_267 = (CharacterBodyFX ***) temp_r0_290;
            }
            var_r4_263 += 4;
            goto loop_16;
        }
        temp_r3_293 = var_r3_268->Current();
        if (temp_r3_293 != NULL) {
            ((MKHeap *) (temp_r3_293->Current()))->Free(var_r31_267, NULL, 0);
        } else {
            free(var_r31_267);
        }
    }
    this->unk0 = NULL;
}
#endif

void CharacterBodyFXManager::Draw() {
    CharacterBodyFX ***var_r31_322;
    CharacterBodyFX **temp_r3_334;
    CharacterBodyFX *temp_r3_325;

    var_r31_322 = this->unk0;
loop_2:
    if (var_r31_322 != NULL) {
        temp_r3_334 = *var_r31_322;
        if (temp_r3_334 != NULL) {
            temp_r3_325 = *temp_r3_334;
            temp_r3_325->Draw();
            var_r31_322 += 4;
            goto loop_2;
        }
    }
}

void CharacterBodyFXManager::Update() {
    CharacterBodyFX ***var_r31_352;
    CharacterBodyFX **temp_r3_364;
    CharacterBodyFX *temp_r3_355;

    var_r31_352 = this->unk0;
loop_2:
    if (var_r31_352 != NULL) {
        temp_r3_364 = *var_r31_352;
        if (temp_r3_364 != NULL) {
            temp_r3_355 = *temp_r3_364;
            temp_r3_355->Update();
            var_r31_352 += 4;
            goto loop_2;
        }
    }
}

#if 0 // DRAFT: illegal use of non-static member
void CharacterBodyFXManager::Init() {
    CharacterBodyFX ***temp_r3_405;
    CharacterBodyFX ***temp_r3_411;
    CharacterBodyFX ***var_r3_390;
    CharacterBodyFX ***var_r5_399;
    MKHeap *temp_r3_383;
    s32 var_ctr_403;

    temp_r3_383 = MKHeap::Current();
    if (temp_r3_383 != NULL) {
        var_r3_390 = ((MKHeap *) (temp_r3_383->Current()))->Alloc(0x648, NULL, 0);
    } else {
        var_r3_390 = malloc(0x648);
    }
    this->unk0 = var_r3_390;
    var_r5_399 = this->unk0;
    this->unk0 = var_r5_399 + 0x320;
    M2C_FIELD(var_r5_399, s32 *, 0x320) = 0;
    var_ctr_403 = 0xC8;
    do {
        temp_r3_405 = this->unk0;
        this->unk0 = temp_r3_405 + 4;
        M2C_FIELD(temp_r3_405, CharacterBodyFX ****, 4) = var_r5_399;
        var_r5_399 += 4;
        var_ctr_403 -= 1;
    } while (var_ctr_403 != 0);
    temp_r3_411 = this->unk0;
    this->unk0 = temp_r3_411 + 4;
    M2C_FIELD(temp_r3_411, CharacterBodyFX ****, 4) = NULL;
}
#endif

#if 0 // DRAFT: function call 'MKRand_Int(long *, int, long)' does not match
void *CharacterBodyFX::GetRandomNode(CBFXNode *arg0) {
    CharacterBodyFXData *temp_r3_432;
    s32 temp_r31_453;
    s32 temp_r3_442;
    s32 temp_r5_444;
    s32 var_r4_445;

    temp_r3_432 = this->unk8;
    if (temp_r3_432 == NULL) {
        return NULL;
    }
    temp_r3_442 = MKRand_Int(&gViewSeed, 0, temp_r3_432->unk4 - 1);
    temp_r5_444 = this->unk4;
    var_r4_445 = temp_r3_442;
    if (((u32) (temp_r5_444 + (temp_r3_442 * 0x70)) == arg0) && (temp_r3_442 > 0)) {
        var_r4_445 = temp_r3_442 - 1;
    }
    temp_r31_453 = var_r4_445 * 0x70;
    if (((u8) M2C_FIELD((temp_r5_444 + temp_r31_453), u8 *, 0x60) == 0) || ((u8) this->unk10 == 0)) {
        CalculateNodeData(var_r4_445);
    }
    return this->unk4 + temp_r31_453;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void CharacterBodyFX::Deinit() {
    MKHeap *temp_r3_489;
    s32 temp_r31_483;

    temp_r31_483 = this->unk4;
    if (((u32) temp_r31_483 != 0U) && ((u8) this->unk11 == 0)) {
        temp_r3_489 = MKHeap::Current();
        if (temp_r3_489 != NULL) {
            ((MKHeap *) (temp_r3_489->Current()))->Free((void *) temp_r31_483, NULL, 0);
        } else {
            free((CharacterBodyFX ***) temp_r31_483);
        }
    }
    this->unk4 = 0;
}
#endif

void CharacterBodyFX::Draw() {

}

void CharacterBodyFX::Update() {
    if ((u8) this->unk10 != 0) {
        CalculateNodeData(-1);
    }
}

#if 0 // DRAFT: pointer/array required
void CharacterBodyFX::CalculateNodeData(int arg0) {
    Animation *temp_r25_593;
    CharacterBodyFXData *temp_r3_546;
    s32 temp_r7_596;
    s32 var_r0_551;
    s32 var_r26_556;
    s32 var_r28_557;
    s32 var_r29_550;
    void *temp_r3_679;
    void *temp_r4_581;
    temp_r3_546 = this->unk8;
    if (temp_r3_546 != NULL) {
        var_r29_550 = temp_r3_546->unk4;
        var_r0_551 = 0;
        if (arg0 != -1) {
            var_r0_551 = arg0;
            var_r29_550 = arg0 + 1;
        }
        var_r26_556 = var_r0_551 * 0x70;
        var_r28_557 = var_r0_551;
loop_10:
        if (var_r28_557 < var_r29_550) {
            if ((u32) M2C_FIELD(*(this->unk4 + var_r26_556), u32 *, 8) != -1U) {
                M2C_STRUCT_COPY((s32) &arg_spBC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
                temp_r4_581 = *(this->unk4 + var_r26_556);
                if ((s32) M2C_FIELD(temp_r4_581, s32 *, 0) == 0) {
                    MKModel_CalculateNodeWorldPosition(this->unkC, M2C_FIELD(temp_r4_581, s32 *, 8), (MKVector3 *) &arg_spA8);
                    temp_r25_593 = MKModel_GetAnimation(this->unkC);
                    temp_r7_596 = MKModel_GetWorldMatrix(this->unkC);
                    arg_sp10 = (s16) M2C_FIELD(*(this->unk4 + var_r26_556), s32 *, 8);
                    temp_r25_593->CalculateMatrices((Matrix *) &arg_spC0, 1, &arg_sp10, (Matrix *) temp_r7_596);
                } else {
                    MKModel_CalculateRefPointWorldPosition(this->unkC, M2C_FIELD(temp_r4_581, s32 *, 8), (MKVector3 *) &arg_spA8);
                }
                *(this->unk4 + (var_r26_556 + 0x60)) = 1;
                M2C_STRUCT_COPY((this->unk4 + (var_r26_556 + 0x20)) - 4 + 4, (s32) &arg_spBC + 4, 0x40);
                __ml(M2C_FIELD(*(this->unk4 + var_r26_556), f32 *, 0x28), *((MKVector3 *) &arg_sp48));
                __ml(M2C_FIELD(*(this->unk4 + var_r26_556), f32 *, 0x24), *((MKVector3 *) &arg_sp58));
                __ml(M2C_FIELD(*(this->unk4 + var_r26_556), f32 *, 0x20), *((MKVector3 *) &arg_sp68));
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp78 = arg_sp28;
                arg_sp30 = arg_spB0 + arg_sp70;
                arg_sp80 = (f64) arg_sp30;
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp88 = arg_sp18;
                arg_sp20 = (f32) arg_sp80 + arg_sp60;
                arg_sp90 = (f64) arg_sp20;
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                temp_r3_679 = this->unk4 + (var_r26_556 + 8);
                arg_sp98 = arg_sp38;
                M2C_FIELD(temp_r3_679, f64 *, 0) = arg_sp38;
                arg_sp40 = (f32) arg_sp90 + arg_sp50;
                arg_spA0 = (f64) arg_sp40;
                M2C_FIELD(temp_r3_679, f64 *, 8) = (f64) arg_sp40;
            }
            var_r28_557 += 1;
            var_r26_556 += 0x70;
            goto loop_10;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'Current'
void CharacterBodyFX::InitData(CharacterBodyFXData *arg0, MKModel *arg1, CBFXNode *arg2) {
    CharacterBodyFX ***var_r3_736;
    CharacterBodyFXData *temp_r3_726;
    CharacterBodyFXData *temp_r3_771;
    MKHeap *temp_r3_729;
    s32 temp_r28_728;
    s32 temp_r3_762;
    s32 var_r27_746;
    s32 var_r29_742;
    s32 var_r30_747;
    void *temp_r3_765;

    this->unkC = arg1;
    if ((s32) arg0->unk4 == 0) {
        this->unk8 = NULL;
        return;
    }
    this->unk8 = arg0;
    if (arg2 == NULL) {
        this->unk11 = 0;
        temp_r3_726 = this->unk8;
        temp_r28_728 = temp_r3_726->unk4 * 0x70;
        temp_r3_729 = temp_r3_726->Current();
        if (temp_r3_729 != NULL) {
            var_r3_736 = ((MKHeap *) (temp_r3_729->Current()))->Alloc(temp_r28_728, NULL, 0);
        } else {
            var_r3_736 = malloc(temp_r28_728);
        }
        var_r29_742 = 0;
        this->unk4 = (s32) var_r3_736;
        var_r27_746 = 0;
        var_r30_747 = 0;
loop_8:
        temp_r3_771 = this->unk8;
        if (var_r27_746 < (s32) temp_r3_771->unk4) {
            *(this->unk4 + var_r30_747) = temp_r3_771->unk0 + var_r29_742;
            *(this->unk4 + (var_r30_747 + 0x60)) = 0;
            ((Matrix *) (this->unk4 + (var_r30_747 + 0x20)))->SetIdentity();
            temp_r3_762 = var_r30_747 + 8;
            var_r27_746 += 1;
            var_r30_747 += 0x70;
            temp_r3_765 = this->unk4 + temp_r3_762;
            var_r29_742 += 0x30;
            M2C_FIELD(temp_r3_765, f32 *, 0) = 0.0f;
            M2C_FIELD(temp_r3_765, f32 *, 4) = 0.0f;
            M2C_FIELD(temp_r3_765, f32 *, 8) = 0.0f;
            goto loop_8;
        }
        return;
    }
    this->unk11 = 1;
    this->unk4 = (s32) arg2;
}
#endif

void CharacterBodyFX::Init() {
    this->unk4 = 0;
    this->unk10 = 0;
    this->unk11 = 0;
}

void CharacterBodyFXData::Deinit() {

}

#if 0 // DRAFT: illegal type
void CharacterBodyFXData::Init(CharacterBodyFxInit *arg0, int arg1, MKAnimScript *arg2) {
    s32 var_r30_815;
    s32 var_r31_816;
    void *temp_r4_822;

    var_r30_815 = 0;
    var_r31_816 = 0;
    this->unk0 = arg0;
    this->unk4 = arg1;
loop_5:
    if (var_r30_815 < (s32) this->unk4) {
        temp_r4_822 = this->unk0 + var_r31_816;
        if ((s32) M2C_FIELD(temp_r4_822, s32 *, 0) == 0) {
            *(this->unk0 + (var_r31_816 + 8)) = (s32) Tools_GetMatchingNodeIndex(arg2->unk8, M2C_FIELD(temp_r4_822, s8 **, 4));
        } else {
            *(this->unk0 + (var_r31_816 + 8)) = (s32) Tools_GetMatchingRefPointIndex(arg2->unk8, M2C_FIELD(temp_r4_822, s8 **, 4));
        }
        var_r30_815 += 1;
        var_r31_816 += 0x30;
        goto loop_5;
    }
}
#endif
