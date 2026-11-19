#include "spyro/source/SpyroAnimTables.h"
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
#include "common/Source/Matrix.h"
#include "spyro/source/InputModifier.h"
#include "spyro/source/KDCamera.h"
#include "spyro/source/KDCameraHeroData.h"
#include "spyro/source/KDCameraHeroMoveYaw.h"
#include "spyro/source/KDCameraJumpTargetOffset.h"
#include "spyro/source/KDCameraMessageStorage.h"
#include "spyro/source/KDCameraPoint.h"
#include "spyro/source/KDCameraSimpleDelta.h"
#include "spyro/source/KDCameraState.h"
#include "spyro/source/KDCollisionObject.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/NodeLookAt.h"
#include "spyro/source/Spyro.h"
#include "spyro/source/SpyroCombatState.h"
#include "spyro/source/SpyroState.h"
#include "spyro/source/SpyroTools.h"
#include "spyro/source/SpyroUtils.h"
#include "spyro/source/TargetManager.h"
#include "spyro/source/Tools.h"
#include "unplaced_enums.h"
#include <m2c_macros.h>

extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
static M2C_UNK animEnt;                             /* unable to generate initializer: unknown type */
#if 0 // DRAFT: illegal use of incomplete struct/union/class '_struct_idleAnimTable_0x18'
static struct _struct_idleAnimTable_0x18 idleAnimTable[2];
#endif
static s32 lit_738 = 0;

#if 0 // DRAFT: illegal explicit conversion from 'int' to 'Spyro::AnimScriptNode'
void SpyroBreatheAnimTable::Update(Spyro *arg0) {
    u32 temp_r4_23;
    u32 temp_r4_45;

    if ((u8) arg0->unk3D3 != 0) {
        temp_r4_23 = this->unk4;
        if ((u32) arg0->GetAnimScript((Spyro::AnimScriptNode) 0)->unk20 != (u32) M2C_FIELD((arg0->unkB4 + (temp_r4_23 * 8)), u32 *, 4)) {
            arg0->SetAnim(temp_r4_23, 0.2f, (Spyro::AnimScriptNode) 0, 1U, 1.0f);
            return;
        }
    }
    if ((u8) arg0->unk3D3 == 0) {
        temp_r4_45 = this->unk0;
        if ((u32) arg0->GetAnimScript((Spyro::AnimScriptNode) 0)->unk20 != (u32) M2C_FIELD((arg0->unkB4 + (temp_r4_45 * 8)), u32 *, 4)) {
            arg0->SetAnim(temp_r4_45, 0.2f, (Spyro::AnimScriptNode) 0, 1U, 1.0f);
        }
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to 'Spyro::AnimScriptNode'
void SpyroBreatheAnimTable::Start(Spyro *arg0, float arg1) {
    if ((u8) arg0->unk3D3 != 0) {
        arg0->SetAnim(this->unk4, arg1, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
        return;
    }
    arg0->SetAnim(this->unk0, arg1, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
}
#endif

#if 0 // DRAFT: illegal type
u8 SpyroStartCycleAnimTable::IsAnimInTable(Spyro *arg0, MKAnim *arg1) {
    u8 var_r6_102;
    u8 var_r7_105;
    void *temp_r4_107;

    var_r6_102 = 0;
    if (arg1 != NULL) {
        var_r7_105 = 1;
        temp_r4_107 = arg0->unkB4 + 4;
        if ((arg1 != (u32) *(temp_r4_107 + (this->unk0 * 8))) && (arg1 != (u32) *(temp_r4_107 + (this->unk4 * 8)))) {
            var_r7_105 = 0;
        }
        if (var_r7_105 != 0) {
            var_r6_102 = 1;
        }
    }
    return var_r6_102;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to 'Spyro::AnimScriptNode'
void SpyroStartCycleAnimTable::Update(Spyro *arg0) {
    if (arg0->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1) {
        arg0->SetAnim(this->unk4, 0.0f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to 'Spyro::AnimScriptNode'
void SpyroStartCycleAnimTable::Start(Spyro *arg0, float arg1) {
    arg0->SetAnim((u32) this->unk0, arg1, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
}
#endif

#if 0 // DRAFT: undefined identifier 'GetIndexAnim'
void SpyroIdleAnimTable::Update(Spyro *arg0, bool arg1, unsigned int arg2, IdleAnimNumber arg3, float arg4) {
    void *temp_r3_187;

    temp_r3_187 = GetIndexAnim(arg2, arg3, arg4);
    if (temp_r3_187 != NULL) {
        this->unk0 = temp_r3_187;
        if ((u32) M2C_FIELD(this->unk0, u32 *, 4) != 0U) {
            arg0->SetAnim(M2C_FIELD(temp_r3_187, MKAnim **, 4), M2C_FIELD(temp_r3_187, f32 *, 8), (Spyro::AnimScriptNode) 0, 0U, 1.0f);
        }
    }
}
#endif

void SpyroIdleAnimTable::Deinit() {

}

void SpyroIdleAnimTable::Init(MKAnimScript *arg0) {
    this->unk0 = NULL;
    SpyroAnimTables_InitIndexTable(arg0);
}

u8 SpyroIdleAnimEntry::IsValid(MaterialIndex arg0, IdleAnimNumber arg1, IdleAnimMoveVel arg2) {
    u8 var_r8_238;

    var_r8_238 = 0;
    if (((1 << (s32) arg0) & this->unkC) && ((1 << (s32) arg1) & this->unk10) && ((1 << (s32) arg2) & this->unk14)) {
        var_r8_238 = 1;
    }
    return var_r8_238;
}

#if 0 // DRAFT: function call 'GetAnim(signed char *)' does not match 'MKAnimScript::GetAnim(int)' 'MKAnimScript::GetAnim(const char *)'
void SpyroAnimTables_InitIndexTable(MKAnimScript *arg0) {
    SpyroIdleAnimEntry *temp_r20_270;
    s32 var_ctr_326;
    s32 var_r0_331;
    s32 var_r11_314;
    s32 var_r12_318;
    s32 var_r18_283;
    s32 var_r18_323;
    s32 var_r19_265;
    s32 var_r23_275;
    s32 var_r24_279;
    s32 var_r27_284;
    s32 var_r28_280;
    s32 var_r29_276;
    s32 var_r30_268;
    s32 var_r3_315;
    s32 var_r4_319;
    s32 var_r5_324;
    void *temp_r8_322;

    var_r19_265 = 0;
    var_r30_268 = 0;
    do {
        temp_r20_270 = (SpyroIdleAnimEntry *) (&animEnt + var_r30_268);
        temp_r20_270->unk4 = arg0->GetAnim(temp_r20_270->unk0);
        var_r23_275 = 0;
        var_r29_276 = 0;
loop_2:
        var_r24_279 = 0;
        var_r28_280 = 0;
loop_3:
        var_r18_283 = 0;
        var_r27_284 = 0;
loop_4:
        if (temp_r20_270->IsValid((MaterialIndex) var_r23_275, (IdleAnimNumber) var_r18_283, (IdleAnimMoveVel) var_r24_279) != 0) {
            *(idleAnimTable + var_r29_276 + var_r28_280 + var_r27_284) = (signed char) (temp_r20_270);
        }
        var_r18_283 += 1;
        var_r27_284 += 4;
        if (var_r18_283 < 3) {
            goto loop_4;
        }
        var_r24_279 += 1;
        var_r28_280 += 0xC;
        if (var_r24_279 < 2) {
            goto loop_3;
        }
        var_r23_275 += 1;
        var_r29_276 += 0x18;
        if (var_r23_275 < 2) {
            goto loop_2;
        }
        var_r19_265 += 1;
        var_r30_268 += 0x18;
    } while (var_r19_265 < 3);
    var_r11_314 = 0;
    var_r3_315 = 0;
    do {
        var_r12_318 = 0;
        var_r4_319 = 0;
loop_12:
        temp_r8_322 = idleAnimTable + var_r3_315 + var_r4_319;
        var_r18_323 = 0;
        var_r5_324 = 0;
        var_ctr_326 = 3;
loop_13:
        if ((u32) *(temp_r8_322 + var_r5_324) == 0U) {
            var_r0_331 = var_r18_323 - 1;
            if ((s32) lit_738 > var_r0_331) {
                var_r0_331 = lit_738;
            }
            *(temp_r8_322 + var_r5_324) = *(temp_r8_322 + (var_r0_331 * 4));
        }
        if ((u32) *(temp_r8_322 + var_r5_324) == 0U) {
            *(temp_r8_322 + var_r5_324) = 0;
        }
        var_r18_323 += 1;
        var_r5_324 += 4;
        var_ctr_326 -= 1;
        if (var_ctr_326 != 0) {
            goto loop_13;
        }
        var_r12_318 += 1;
        var_r4_319 += 0xC;
        if (var_r12_318 < 2) {
            goto loop_12;
        }
        var_r11_314 += 1;
        var_r3_315 += 0x18;
    } while (var_r11_314 < 2);
}
#endif

#if 0 // DRAFT: illegal type
void *GetIndexAnim(unsigned int arg0, IdleAnimNumber arg1, float arg2) {
    s32 temp_r3_379;
    s32 var_r0_372;
    s32 var_r3_367;
    void *temp_r4_383;

    var_r3_367 = 0;
    if (arg0 & 8) {
        var_r3_367 = 1;
    }
    var_r0_372 = 0;
    if (arg2 > 1.0f) {
        var_r0_372 = 1;
    }
    temp_r3_379 = (s32) arg1 * 4;
    temp_r4_383 = &idleAnimTable[var_r3_367] + (var_r0_372 * 0xC);
    if ((u32) *(temp_r4_383 + temp_r3_379) == 0U) {
        *(temp_r4_383 + temp_r3_379) = 0;
    }
    return *(temp_r4_383 + temp_r3_379);
}
#endif

void SpyroAnimTables_cpp::__sinit() {
    f32 temp_f0_429;
    f64 temp_f1_410;
    f64 temp_f1_418;
    f64 temp_f3_398;
    f64 temp_f4_407;
    f64 temp_f4_415;
    f64 temp_f8_400;

    temp_f3_398 = __frsqrte(2014000.0);
    temp_f8_400 = __frsqrte(380000.0);
    temp_f4_407 = 0.5 * temp_f3_398 * -((2014000.0 * (temp_f3_398 * temp_f3_398)) - 3.0);
    temp_f1_410 = 0.5 * temp_f8_400 * -((380000.0 * (temp_f8_400 * temp_f8_400)) - 3.0);
    temp_f4_415 = 0.5 * temp_f4_407 * -((2014000.0 * (temp_f4_407 * temp_f4_407)) - 3.0);
    temp_f1_418 = 0.5 * temp_f1_410 * -((380000.0 * (temp_f1_410 * temp_f1_410)) - 3.0);
    temp_f0_429 = (f32) (380000.0 * (0.5 * temp_f1_418 * -((380000.0 * (temp_f1_418 * temp_f1_418)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_415 * -((2014000.0 * (temp_f4_415 * temp_f4_415)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_429;
}
