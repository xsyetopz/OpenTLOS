#include "spyro/source/KDCameraMessageStorage.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKHeap.h"
#include <m2c_macros.h>

#if 0 // DRAFT: illegal implicit conversion from 'MKHeap' to
M2C_UNK free(MKHeap *);                             /* extern */
MKHeap *malloc(s32);                                /* extern */

s32 *KDMessageStorage::GetMessageAtIndex(int arg0) {
    return *(this->unk0 + (arg0 * 4));
}
#endif

#if 0 // DRAFT: illegal type
void *KDMessageStorage::GetDesc(int arg0) {
    s32 temp_r0_20;
    s32 var_ctr_22;
    s32 var_r5_21;
    void *temp_r6_27;

    temp_r0_20 = this->unk10;
    var_r5_21 = 0;
    var_ctr_22 = temp_r0_20;
    if (temp_r0_20 > 0) {
loop_1:
        temp_r6_27 = this->unkC + var_r5_21;
        if (arg0 == (s32) M2C_FIELD(temp_r6_27, s32 *, 8)) {
            return temp_r6_27;
        }
        var_r5_21 += 0xC;
        var_ctr_22 -= 1;
        if (var_ctr_22 == 0) {
            /* Duplicate return node #4. Try simplifying control flow for better match */
            return NULL;
        }
        goto loop_1;
    }
    return NULL;
}
#endif

s32 *KDMessageStorage::GetMessage(int arg0) {
    s32 var_r31_50;

    var_r31_50 = 0;
loop_4:
    if (var_r31_50 >= (s32) (this->unk4 + 1)) {
        return NULL;
    }
    if (arg0 == (s32) *GetMessageAtIndex(var_r31_50)) {
        return GetMessageAtIndex(var_r31_50);
    }
    var_r31_50 += 1;
    goto loop_4;
}

#if 0 // DRAFT: illegal type
s32 KDMessageStorage::CanMessageBeStored(int arg0) {
    s32 temp_r0_82;
    s32 var_ctr_84;
    s32 var_r5_83;

    temp_r0_82 = this->unk10;
    var_r5_83 = 0;
    var_ctr_84 = temp_r0_82;
    if (temp_r0_82 > 0) {
loop_1:
        if (arg0 == (s32) *(this->unkC + (var_r5_83 + 8))) {
            return 1;
        }
        var_r5_83 += 0xC;
        var_ctr_84 -= 1;
        if (var_ctr_84 == 0) {
            /* Duplicate return node #4. Try simplifying control flow for better match */
            return 0;
        }
        goto loop_1;
    }
    return 0;
}
#endif

u8 KDMessageStorage::IsMessageStored(int arg0) {
    s32 var_r31_112;

    var_r31_112 = 0;
loop_4:
    if (var_r31_112 >= (s32) (this->unk4 + 1)) {
        return 0U;
    }
    if (arg0 == (s32) *GetMessageAtIndex(var_r31_112)) {
        return 1U;
    }
    var_r31_112 += 1;
    goto loop_4;
}

#if 0 // DRAFT: function call 'memcpy(MKHeap, MKMessage *, unsigned long)' does not match
void KDMessageStorage::StoreMessage(MKMessage *arg0) {
    void *temp_r31_156;

    if (IsMessageStored(arg0->unk0) != 0) {
        temp_r31_156 = GetDesc(arg0->unk0);
        memcpy(GetMessage(arg0->unk0), arg0, M2C_FIELD(temp_r31_156, u32 *, 4));
        return;
    }
    this->unk4 += 1;
    memcpy(*(this->unk0 + (this->unk4 * 4)), arg0, M2C_FIELD(GetDesc(arg0->unk0), u32 *, 4));
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKHeap' to
void KDMessageStorage::Deinit() {
    MKHeap *temp_r30_198;
    MKHeap *temp_r30_218;
    MKHeap *temp_r3_197;
    MKHeap *temp_r3_199;
    MKHeap *temp_r3_219;
    s32 var_r29_193;
    s32 var_r31_194;

    var_r29_193 = 0;
    var_r31_194 = 0;
loop_5:
    if (var_r29_193 < (s32) this->unk8) {
        temp_r3_197 = this->unk0;
        temp_r30_198 = *(temp_r3_197 + var_r31_194);
        temp_r3_199 = temp_r3_197->Current();
        if (temp_r3_199 != NULL) {
            ((MKHeap *) (temp_r3_199->Current()))->Free(temp_r30_198, NULL, 0);
        } else {
            free(temp_r30_198);
        }
        var_r29_193 += 1;
        var_r31_194 += 4;
        goto loop_5;
    }
    temp_r30_218 = this->unk0;
    temp_r3_219 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_219 != NULL) {
        ((MKHeap *) (temp_r3_219->Current()))->Free(temp_r30_218, NULL, 0);
        return;
    }
    free(temp_r30_218);
}
#endif

#if 0 // DRAFT: illegal type
void KDMessageStorage::Init(KDMessageStorageDescriptor *arg0, int arg1) {
    MKHeap *temp_r3_266;
    MKHeap *temp_r3_303;
    MKHeap *var_r3_273;
    MKHeap *var_r3_281;
    MKHeap *var_r3_310;
    s32 temp_r0_282;
    s32 temp_r0_290;
    s32 temp_r30_265;
    s32 temp_r3_255;
    s32 temp_r4_251;
    s32 var_ctr_283;
    s32 var_r28_299;
    s32 var_r29_280;
    s32 var_r30_300;
    s32 var_r5_289;

    this->unkC = arg0;
    this->unk10 = 0;
    do {
        temp_r4_251 = this->unk10;
        temp_r3_255 = *(this->unkC + ((temp_r4_251 * 0xC) + 4));
        if (temp_r3_255 != 0) {
            this->unk10 = temp_r4_251 + 1;
        }
    } while (temp_r3_255 != 0);
    this->unk8 = arg1;
    temp_r30_265 = this->unk8 * 4;
    temp_r3_266 = ((MKHeap *) temp_r3_255)->Current();
    if (temp_r3_266 != NULL) {
        var_r3_273 = ((MKHeap *) (temp_r3_266->Current()))->Alloc(temp_r30_265, NULL, 0);
    } else {
        var_r3_273 = malloc(temp_r30_265);
    }
    this->unk0 = var_r3_273;
    var_r29_280 = 0;
    var_r3_281 = NULL;
    temp_r0_282 = this->unk10;
    var_ctr_283 = temp_r0_282;
    if (temp_r0_282 > 0) {
        do {
            var_r5_289 = var_r29_280;
            temp_r0_290 = *(this->unkC + (var_r3_281 + 4));
            if (temp_r0_290 > var_r29_280) {
                var_r5_289 = temp_r0_290;
            }
            var_r29_280 = var_r5_289;
            var_r3_281 += 0xC;
            var_ctr_283 -= 1;
        } while (var_ctr_283 != 0);
    }
    var_r28_299 = 0;
    var_r30_300 = 0;
loop_16:
    if (var_r28_299 < (s32) this->unk8) {
        temp_r3_303 = var_r3_281->Current();
        if (temp_r3_303 != NULL) {
            var_r3_310 = ((MKHeap *) (temp_r3_303->Current()))->Alloc(var_r29_280, NULL, 0);
        } else {
            var_r3_310 = malloc(var_r29_280);
        }
        *(this->unk0 + var_r30_300) = var_r3_310;
        var_r3_281 = memset(*(this->unk0 + var_r30_300), 0xFC, (u32) var_r29_280);
        var_r28_299 += 1;
        var_r30_300 += 4;
        goto loop_16;
    }
    this->unk4 = -1;
}
#endif
