#include "spyro/source/KDCameraMessageStorage.h"
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
#include <m2c_macros.h>

M2C_UNK free(MKHeap *);                             /* extern */
MKHeap *malloc(s32);                                /* extern */

s32 *KDMessageStorage::GetMessageAtIndex(int arg0) {
    return ((s32 **) this->unk0)[arg0];
}

void *KDMessageStorage::GetDesc(int arg0) {
    s32 var_r5_21;
    s32 var_ctr_22;
    void *temp_r6_27;

    var_r5_21 = 0;
    var_ctr_22 = this->unk10;
    while (var_ctr_22 > 0) {
        temp_r6_27 = (s8 *) this->unkC + var_r5_21;
        if (arg0 == (s32) M2C_FIELD(temp_r6_27, s32 *, 8)) {
            return temp_r6_27;
        }
        var_r5_21 += 0xC;
        var_ctr_22 -= 1;
    }
    return NULL;
}

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

s32 KDMessageStorage::CanMessageBeStored(int arg0) {
    s32 var_r5_83;
    s32 var_ctr_84;

    var_r5_83 = 0;
    var_ctr_84 = this->unk10;
    while (var_ctr_84 > 0) {
        if (arg0 == M2C_FIELD(this->unkC, s32 *, var_r5_83 + 8)) {
            return 1;
        }
        var_r5_83 += 0xC;
        var_ctr_84 -= 1;
    }
    return 0;
}

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

void KDMessageStorage::StoreMessage(MKMessage *arg0) {
    void *temp_r31_156;

    if (IsMessageStored(arg0->unk0) != 0) {
        temp_r31_156 = GetDesc(arg0->unk0);
        memcpy(GetMessage(arg0->unk0), arg0, M2C_FIELD(temp_r31_156, u32 *, 4));
        return;
    }
    this->unk4 += 1;
    temp_r31_156 = GetDesc(arg0->unk0);
    memcpy(((void **) this->unk0)[this->unk4], arg0, M2C_FIELD(temp_r31_156, u32 *, 4));
}

extern "C" void free(void *);
void KDMessageStorage::Deinit() {
    MKHeap *temp_r30_198;
    MKHeap *temp_r30_218;
    s32 var_r29_193;
    s32 var_r31_194;

    var_r29_193 = 0;
    var_r31_194 = 0;
    while (var_r29_193 < (s32) this->unk8) {
        temp_r30_198 = M2C_FIELD(this->unk0, MKHeap **, var_r31_194);
        if (MKHeap::Current() != NULL) {
            MKHeap::Current()->Free(temp_r30_198, NULL, 0);
        } else {
            free((void *) temp_r30_198);
        }
        var_r29_193 += 1;
        var_r31_194 += 4;
    }
    temp_r30_218 = this->unk0;
    if (MKHeap::Current() != NULL) {
        MKHeap::Current()->Free(temp_r30_218, NULL, 0);
        return;
    }
    free((void *) temp_r30_218);
}

extern "C" void *malloc(unsigned long);
void KDMessageStorage::Init(KDMessageStorageDescriptor *arg0, int arg1) {
    MKHeap *var_r3_273;
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
    s32 var_r3_281;
    s32 var_r5_289;

    this->unkC = arg0;
    this->unk10 = 0;
    do {
        temp_r4_251 = this->unk10;
        temp_r3_255 = M2C_FIELD(this->unkC, s32 *, (temp_r4_251 * 0xC) + 4);
        if (temp_r3_255 != 0) {
            this->unk10 = temp_r4_251 + 1;
        }
    } while (temp_r3_255 != 0);
    this->unk8 = arg1;
    temp_r30_265 = this->unk8 * 4;
    if (MKHeap::Current() != NULL) {
        var_r3_273 = (MKHeap *) MKHeap::Current()->Alloc(temp_r30_265, NULL, 0);
    } else {
        var_r3_273 = (MKHeap *) malloc((unsigned long) temp_r30_265);
    }
    this->unk0 = var_r3_273;
    var_r29_280 = 0;
    var_r3_281 = 0;
    temp_r0_282 = this->unk10;
    var_ctr_283 = temp_r0_282;
    if (temp_r0_282 > 0) {
        do {
            var_r5_289 = var_r29_280;
            temp_r0_290 = M2C_FIELD(this->unkC, s32 *, var_r3_281 + 4);
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
    while (var_r28_299 < (s32) this->unk8) {
        if (MKHeap::Current() != NULL) {
            var_r3_310 = (MKHeap *) MKHeap::Current()->Alloc(var_r29_280, NULL, 0);
        } else {
            var_r3_310 = (MKHeap *) malloc((unsigned long) var_r29_280);
        }
        M2C_FIELD(this->unk0, MKHeap **, var_r30_300) = var_r3_310;
        memset(M2C_FIELD(this->unk0, MKHeap **, var_r30_300), 0xFC, (u32) var_r29_280);
        var_r28_299 += 1;
        var_r30_300 += 4;
    }
    this->unk4 = -1;
}
