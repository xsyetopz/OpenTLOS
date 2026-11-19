#include "spyro/source/CharacterBodyFX.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Level.h"
#include "common/Source/StdMath.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

M2C_UNK free(CharacterBodyFX ***);                  /* extern */
CharacterBodyFX ***malloc(s32);                     /* extern */
extern M2C_UNK gEmptyPtrListDL;
extern s32 gViewSeed;

void CharacterBodyFX::SetDataActive(bool arg0) {
    s32 i;
    s32 off;

    this->unk10 = arg0;
    if (this->unk10 == 0 && this->unk8 != NULL && this->unk4 != 0) {
        off = 0;
        i = 0;
        while (i < this->unk8->unk4) {
            ((u8 *) this->unk4)[off + 0x60] = 0;
            i += 1;
            off += 0x70;
        }
    }
}

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

void CharacterBodyFXManager::Deinit() {
    CharacterBodyFX ***var31;
    CharacterBodyFX ***r3;
    CharacterBodyFX ***slot;
    CharacterBodyFX **entry;

    var31 = this->unk0;
    while (var31 != NULL && *var31 != NULL) {
        (**var31)->Deinit();
        operator delete(**var31);
        var31 += 1;
    }
    while (*this->unk0 != NULL) {
        this->unk0 += 1;
    }
    var31 = this->unk0;
    slot = this->unk0;
    r3 = this->unk0;
    r3 -= 1;
    entry = *r3;
    while (entry != NULL) {
        if ((u32) entry < (u32) var31) {
            var31 = (CharacterBodyFX ***) entry;
        }
        r3 -= 1;
        entry = *r3;
    }
    if ((u32) r3 != (u32) &gEmptyPtrListDL) {
        while (*slot != NULL) {
            if ((u32) *slot < (u32) var31) {
                var31 = (CharacterBodyFX ***) *slot;
            }
            slot += 1;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(var31, NULL, 0);
        } else {
            free(var31);
        }
    }
    this->unk0 = NULL;
}

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

void CharacterBodyFXManager::Init() {
    CharacterBodyFX ***temp_r3_405;
    CharacterBodyFX ***temp_r3_411;
    CharacterBodyFX ***var_r3_390;
    CharacterBodyFX ***var_r5_399;
    s32 var_ctr_403;

    if (MKHeap::Current() != NULL) {
        var_r3_390 = (CharacterBodyFX ***) (((MKHeap *) (MKHeap::Current()))->Alloc(0x648, NULL, 0));
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

void *CharacterBodyFX::GetRandomNode(CBFXNode *arg0) {
    s32 idx;
    s32 node;
    s32 r;

    if (this->unk8 == NULL) {
        return NULL;
    }
    r = MKRand_Int((int *) &gViewSeed, 0, this->unk8->unk4 - 1);
    node = r;
    if ((u8 *) this->unk4 + r * 0x70 == (u8 *) arg0 && r > 0) {
        node = r - 1;
    }
    idx = node * 0x70;
    if (((u8 *) this->unk4)[idx + 0x60] == 0 || this->unk10 == 0) {
        this->CalculateNodeData(node);
    }
    return (void *) ((u8 *) this->unk4 + idx);
}

void CharacterBodyFX::Deinit() {
    s32 temp_r31_483;

    temp_r31_483 = this->unk4;
    if (((u32) temp_r31_483 != 0U) && ((u8) this->unk11 == 0)) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free((void *) temp_r31_483, NULL, 0);
        } else {
            free((CharacterBodyFX ***) temp_r31_483);
        }
    }
    this->unk4 = 0;
}

void CharacterBodyFX::Draw() {

}

void CharacterBodyFX::Update() {
    if ((u8) this->unk10 != 0) {
        CalculateNodeData(-1);
    }
}

#if 0 // DRAFT: pointer/array required
void CharacterBodyFX::CalculateNodeData(int arg0) {
    MKVector3 spE0;
    MKVector3 spD0;
    M2C_UNK spC0;
    M2C_UNK spBC;
    MKVector3 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    MKVector3 sp68;
    MKVector3 sp58;
    MKVector3 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    s16 sp10;
    Animation *temp_r25_593;
    CharacterBodyFXData *temp_r3_546;
    f64 temp_f0_649;
    f64 temp_f0_661;
    f64 temp_f0_673;
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
                M2C_STRUCT_COPY((s32) &spBC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
                temp_r4_581 = *(this->unk4 + var_r26_556);
                if ((s32) M2C_FIELD(temp_r4_581, s32 *, 0) == 0) {
                    MKModel_CalculateNodeWorldPosition(this->unkC, M2C_FIELD(temp_r4_581, s32 *, 8), &spA8);
                    temp_r25_593 = MKModel_GetAnimation(this->unkC);
                    temp_r7_596 = MKModel_GetWorldMatrix(this->unkC);
                    sp10 = (s16) M2C_FIELD(*(this->unk4 + var_r26_556), s32 *, 8);
                    temp_r25_593->CalculateMatrices((Matrix *) &spC0, 1, &sp10, (Matrix *) temp_r7_596);
                } else {
                    MKModel_CalculateRefPointWorldPosition(this->unkC, M2C_FIELD(temp_r4_581, s32 *, 8), &spA8);
                }
                *(this->unk4 + (var_r26_556 + 0x60)) = 1;
                M2C_STRUCT_COPY((this->unk4 + (var_r26_556 + 0x20)) - 4 + 4, (s32) &spBC + 4, 0x40);
                sp48 = __ml(M2C_FIELD(*(this->unk4 + var_r26_556), f32 *, 0x28), spE0);
                sp58 = __ml(M2C_FIELD(*(this->unk4 + var_r26_556), f32 *, 0x24), spD0);
                sp68 = __ml(M2C_FIELD(*(this->unk4 + var_r26_556), f32 *, 0x20), *((MKVector3 *) &spC0));
                temp_f0_649 = M2C_BITWISE(f64, spA8) + M2C_BITWISE(f64, sp68);
                sp28 = temp_f0_649;
                sp78 = temp_f0_649;
                sp30 = spA8.unk8 + sp68.unk8;
                sp80 = (f64) sp30;
                temp_f0_661 = sp78 + M2C_BITWISE(f64, sp58);
                sp18 = temp_f0_661;
                sp88 = temp_f0_661;
                sp20 = (f32) sp80 + sp58.unk8;
                sp90 = (f64) sp20;
                temp_f0_673 = sp88 + M2C_BITWISE(f64, sp48);
                sp38 = temp_f0_673;
                temp_r3_679 = (void *) (this->unk4 + (var_r26_556 + 8));
                sp98 = temp_f0_673;
                M2C_FIELD(temp_r3_679, f64 *, 0) = temp_f0_673;
                sp40 = (f32) sp90 + sp48.unk8;
                spA0 = (f64) sp40;
                M2C_FIELD(temp_r3_679, f64 *, 8) = (f64) sp40;
            }
            var_r28_557 += 1;
            var_r26_556 += 0x70;
            goto loop_10;
        }
    }
}
#endif

void CharacterBodyFX::InitData(CharacterBodyFXData *arg0, MKModel *arg1, CBFXNode *arg2) {
    s32 size;
    s32 i;
    s32 off;
    s32 src;
    void *mem;

    this->unkC = arg1;
    if (arg0->unk4 == 0) {
        this->unk8 = NULL;
        return;
    }
    this->unk8 = arg0;
    if (arg2 == NULL) {
        this->unk11 = 0;
        size = this->unk8->unk4 * 0x70;
        if (MKHeap::Current() != NULL) {
            mem = ((MKHeap *) (MKHeap::Current()))->Alloc(size, NULL, 0);
        } else {
            mem = malloc(size);
        }
        this->unk4 = (s32) mem;
        i = 0;
        off = 0;
        src = 0;
        while (i < this->unk8->unk4) {
            *(s32 *) ((u8 *) this->unk4 + off) = (s32) this->unk8->unk0 + src;
            ((u8 *) this->unk4)[off + 0x60] = 0;
            ((Matrix *) ((u8 *) this->unk4 + off + 0x20))->SetIdentity();
            *(f32 *) ((u8 *) this->unk4 + off + 8) = 0.0f;
            *(f32 *) ((u8 *) this->unk4 + off + 12) = 0.0f;
            *(f32 *) ((u8 *) this->unk4 + off + 16) = 0.0f;
            i += 1;
            off += 0x70;
            src += 0x30;
        }
        return;
    }
    this->unk11 = 1;
    this->unk4 = (s32) arg2;
}

void CharacterBodyFX::Init() {
    this->unk4 = 0;
    this->unk10 = 0;
    this->unk11 = 0;
}

void CharacterBodyFXData::Deinit() {

}

void CharacterBodyFXData::Init(CharacterBodyFxInit *arg0, int arg1, MKAnimScript *arg2) {
    s32 i;
    s32 off;
    u8 *entry;

    i = 0;
    off = 0;
    this->unk0 = arg0;
    this->unk4 = arg1;
    while (i < this->unk4) {
        entry = (u8 *) this->unk0 + off;
        if (*(s32 *) entry == 0) {
            *(s32 *) ((u8 *) this->unk0 + off + 8) = (u16) Tools_GetMatchingNodeIndex(arg2->unk8, *(char **) (entry + 4));
        } else {
            *(s32 *) ((u8 *) this->unk0 + off + 8) = (u16) Tools_GetMatchingRefPointIndex(arg2->unk8, *(char **) (entry + 4));
        }
        i += 1;
        off += 0x30;
    }
}
