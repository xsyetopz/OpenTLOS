#include "spyro/source/MeleeTrails.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/KDPropEx.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/Str.h"
#include "common/gc/MKModel_GC.h"
#include <m2c_macros.h>

M2C_UNK free(MKHeap *);                             /* extern */
MKHeap *malloc(M2C_UNK);                            /* extern */
extern M2C_UNK gEmptyPtrListDL;
extern f32 gUpdateTimeDelta;

#if 0 // DRAFT: ')' expected
void MeleeTrails::ResolveAnims(MKAnimScript *arg0) {
    void **temp_r3_52;
    void **var_r30_48;
    void *temp_r31_54;

    this->unkC8 = arg0;
    var_r30_48 = M2C_FIELD(checked_cast<MeleeTrailsDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), void ***, 0xE4);
loop_4:
    if ((var_r30_48 != NULL) && ((void *) *var_r30_48 != NULL)) {
        temp_r3_52 = M2C_FIELD(this, void ***, 0xD0) - 4;
        M2C_FIELD(this, void ***, 0xD0) = temp_r3_52;
        temp_r31_54 = *temp_r3_52;
        if (temp_r31_54 != NULL) {
            M2C_FIELD(temp_r31_54, void **, 0) = (void *) *var_r30_48;
            M2C_FIELD(temp_r31_54, void **, 4) = this->unkC8->GetAnim(M2C_FIELD(*var_r30_48, s8 **, 0x10));
            M2C_FIELD(temp_r31_54, s8 **, 8) = arg0->GetEventByName(M2C_FIELD(*var_r30_48, s8 **, 0x14), (MKAnimScriptedEvent::EventType) 0);
        }
        var_r30_48 += 4;
        goto loop_4;
    }
}
#endif

#if 0 // DRAFT: illegal operand
void MeleeTrails::EnableTrail(MKAnim *arg0, int arg1, bool arg2, float arg3, float arg4, float arg5) {
    s32 temp_r4_169;
    s32 var_r27_116;
    u32 temp_r3_172;
    void **temp_r3_123;
    void **var_r28_102;
    void *temp_r29_125;
    void *temp_r29_180;

    var_r28_102 = M2C_FIELD(this, void ***, 0xD0);
loop_9:
    if ((var_r28_102 == NULL) || (temp_r29_180 = *var_r28_102, ((temp_r29_180 == NULL) != 0))) {

    } else {
        if (((u32) M2C_FIELD(temp_r29_180, u32 *, 4) == arg0) && ((u32) M2C_FIELD(M2C_FIELD(this, void ***, 0xD4), u32 *, -4) != 0U)) {
            var_r27_116 = 0;
loop_7:
            temp_r4_169 = var_r27_116;
            var_r27_116 += 1;
            temp_r3_172 = this->unkC8->GetEvent(temp_r4_169, (MKAnimScriptedEvent::EventType) 0);
            if (temp_r3_172 == 0U) {
                goto block_8;
            }
            if (temp_r3_172 == (u32) M2C_FIELD(temp_r29_180, u32 *, 8)) {
                temp_r3_123 = M2C_FIELD(this, void ***, 0xD4) - 4;
                M2C_FIELD(this, void ***, 0xD4) = temp_r3_123;
                temp_r29_125 = *temp_r3_123;
                if (temp_r29_125 != NULL) {
                    M2C_FIELD(temp_r29_125, void **, 0x58) = (void *) *var_r28_102;
                    M2C_FIELD(temp_r29_125, f32 *, 0x40) = (f32) (M2C_FIELD(M2C_FIELD(*var_r28_102, void **, 0), f32 *, 8) * (1.0f / arg5));
                    M2C_FIELD(temp_r29_125, f32 *, 0x44) = 0.0f;
                    M2C_STRUCT_COPY(temp_r29_125, MKModel_GetWorldMatrix(this->unkC8->unk8), 0x40);
                    M2C_FIELD(temp_r29_125, f32 *, 0x48) = (f32) (0.25f * (f32) arg1);
                    M2C_FIELD(temp_r29_125, u8 *, 0x5C) = arg2;
                    M2C_FIELD(temp_r29_125, f32 *, 0x4C) = arg3;
                    M2C_FIELD(temp_r29_125, f32 *, 0x50) = arg4;
                    M2C_FIELD(temp_r29_125, f32 *, 0x54) = arg5;
                    return;
                }
                return;
            }
            goto loop_7;
        }
block_8:
        var_r28_102 += 4;
        goto loop_9;
    }
}
#endif

#if 0 // DRAFT: type mismatch
void MeleeTrails::Deinit() {
    MKHeap *temp_r0_210;
    MKHeap *temp_r0_229;
    MKHeap *temp_r0_252;
    MKHeap *temp_r0_271;
    MKHeap *temp_r3_232;
    MKHeap *temp_r3_274;
    MKHeap *var_r30_206;
    MKHeap *var_r30_248;
    MKHeap *var_r3_207;
    MKHeap *var_r3_249;
    MKHeap *var_r4_205;
    MKHeap *var_r4_247;
    u32 temp_r0_215;
    u32 temp_r0_257;

    var_r4_205 = M2C_FIELD(this, MKHeap **, 0xD0);
    var_r30_206 = var_r4_205;
    var_r3_207 = var_r4_205;
loop_3:
    temp_r0_215 = M2C_FIELD(var_r3_207, u32 *, -4);
    var_r3_207 -= 4;
    if (temp_r0_215 != 0U) {
        temp_r0_210 = var_r3_207->unk0;
        if (temp_r0_210 < var_r30_206) {
            var_r30_206 = temp_r0_210;
        }
        goto loop_3;
    }
    if (var_r3_207 != &gEmptyPtrListDL) {
loop_9:
        temp_r0_229 = var_r4_205->unk0;
        if (temp_r0_229 != NULL) {
            if (temp_r0_229 < var_r30_206) {
                var_r30_206 = temp_r0_229;
            }
            var_r4_205 += 4;
            goto loop_9;
        }
        temp_r3_232 = var_r3_207->Current();
        if (temp_r3_232 != NULL) {
            ((MKHeap *) (temp_r3_232->Current()))->Free(var_r30_206, NULL, 0);
        } else {
            free(var_r30_206);
        }
    }
    M2C_FIELD(this, MKHeap **, 0xD0) = NULL;
    var_r4_247 = M2C_FIELD(this, MKHeap **, 0xD4);
    var_r30_248 = var_r4_247;
    var_r3_249 = var_r4_247;
loop_16:
    temp_r0_257 = M2C_FIELD(var_r3_249, u32 *, -4);
    var_r3_249 -= 4;
    if (temp_r0_257 != 0U) {
        temp_r0_252 = var_r3_249->unk0;
        if (temp_r0_252 < var_r30_248) {
            var_r30_248 = temp_r0_252;
        }
        goto loop_16;
    }
    if (var_r3_249 != &gEmptyPtrListDL) {
loop_22:
        temp_r0_271 = var_r4_247->unk0;
        if (temp_r0_271 != NULL) {
            if (temp_r0_271 < var_r30_248) {
                var_r30_248 = temp_r0_271;
            }
            var_r4_247 += 4;
            goto loop_22;
        }
        temp_r3_274 = var_r3_249->Current();
        if (temp_r3_274 != NULL) {
            ((MKHeap *) (temp_r3_274->Current()))->Free(var_r30_248, NULL, 0);
        } else {
            free(var_r30_248);
        }
    }
    M2C_FIELD(this, MKHeap **, 0xD4) = NULL;
    GameProp::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp8C'
void MeleeTrails::Draw() {
    f32 temp_f1_381;
    f32 temp_f29_327;
    s32 *temp_r3_324;
    void **var_r30_316;
    void *temp_r31_427;
    var_r30_316 = M2C_FIELD(this, void ***, 0xD4);
loop_7:
    if (var_r30_316 != NULL) {
        temp_r31_427 = *var_r30_316;
        if (temp_r31_427 != NULL) {
            temp_r3_324 = *M2C_FIELD(temp_r31_427, s32 ***, 0x58);
            temp_f29_327 = M2C_FIELD(temp_r31_427, f32 *, 0x40) / M2C_FIELD(temp_r3_324, f32 *, 8);
            if ((u8) M2C_FIELD(temp_r3_324, u8 *, 0xC) != 0) {
                M2C_STRUCT_COPY((s32) &arg_sp8C + 4, MKModel_GetWorldMatrix(this->unkC8->unk8) - 4 + 4, 0x40);
            } else {
                M2C_STRUCT_COPY((s32) &arg_sp8C + 4, (s32) (temp_r31_427 - 4) + 4, 0x40);
            }
            if ((u8) M2C_FIELD(temp_r31_427, u8 *, 0x5C) != 0) {
                arg_sp90.Scale3x3((Matrix *) &arg_sp90, ((1.0f - temp_f29_327) * M2C_FIELD(temp_r31_427, f32 *, 0x50)) + 1.0f);
            }
            MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &arg_sp90));
            MKModel_EnableOnlySubObject(this->unk4, (SubObjectType) 0, **M2C_FIELD(temp_r31_427, s32 ***, 0x58), 1U, 1U);
            arg_sp2C = 1.0f;
            temp_f1_381 = temp_f29_327 * M2C_FIELD(temp_r31_427, f32 *, 0x4C);
            arg_sp28 = temp_f1_381;
            arg_sp20 = temp_f1_381;
            arg_sp24 = temp_f1_381;
            arg_sp48 = (f64) arg_sp28;
            arg_sp40 = (f64) arg_sp20;
            MKModel_SetColor(this->unk4, *((MKVector4 *) &arg_sp40));
            M2C_STRUCT_COPY((s32) &arg_sp4C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
            arg_sp18 = 0.0f;
            arg_sp10 = M2C_FIELD(temp_r31_427, f32 *, 0x44);
            arg_sp14 = M2C_FIELD(temp_r31_427, f32 *, 0x48);
            arg_sp38 = (f64) arg_sp18;
            arg_sp30 = (f64) arg_sp10;
            arg_sp80 = (f32) arg_sp30;
            arg_sp84 = arg_sp34;
            arg_sp88 = (f32) arg_sp38;
            arg_sp8C = 1.0f;
            MKMaterial_SetTextureMatrix(this->unkCC, (Matrix *) &arg_sp50);
            MKModel_Draw(this->unk4, NULL);
            var_r30_316 += 4;
            goto loop_7;
        }
    }
}
#endif

void MeleeTrails::Update() {
    void **temp_r3_475;
    void **var_r31_456;
    void *temp_r4_478;
    void *temp_r4_498;

    var_r31_456 = M2C_FIELD(this, void ***, 0xD4);
loop_5:
    if (var_r31_456 != NULL) {
        temp_r4_498 = *var_r31_456;
        if (temp_r4_498 != NULL) {
            M2C_FIELD(temp_r4_498, f32 *, 0x40) = (f32) (M2C_FIELD(temp_r4_498, f32 *, 0x40) - gUpdateTimeDelta);
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (M2C_FIELD(temp_r4_498, f32 *, 0x40) == 0.0f) {
                MKModel_EnableSubObject(this->unk4, (SubObjectType) 0, **M2C_FIELD(temp_r4_498, s32 ***, 0x58), 0U, 1U);
                temp_r3_475 = M2C_FIELD(this, void ***, 0xD4);
                M2C_FIELD(this, void ***, 0xD4) = (void **) (temp_r3_475 + 4);
                temp_r4_478 = *temp_r3_475;
                *temp_r3_475 = *var_r31_456;
                *var_r31_456 = temp_r4_478;
            } else {
                M2C_FIELD(temp_r4_498, f32 *, 0x44) = (f32) ((M2C_FIELD(temp_r4_498, f32 *, 0x54) * (M2C_FIELD(*M2C_FIELD(temp_r4_498, s32 ***, 0x58), f32 *, 4) * gUpdateTimeDelta)) + M2C_FIELD(temp_r4_498, f32 *, 0x44));
            }
            var_r31_456 += 4;
            goto loop_5;
        }
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void MeleeTrails::LoadDone() {
    GameProp::LoadDone();
    this->unkCC = MKModel_GetMaterial(this->unk4, 0, 0U);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void MeleeTrails::Init() {
    MKHeap *temp_r3_541;
    MKHeap *temp_r3_563;
    MKHeap *temp_r3_569;
    MKHeap *temp_r3_574;
    MKHeap *temp_r3_596;
    MKHeap *temp_r3_602;
    MKHeap *var_r3_548;
    MKHeap *var_r3_581;
    MKHeap *var_r5_557;
    MKHeap *var_r5_590;
    s32 *temp_r3_571;
    s32 var_ctr_561;
    s32 var_ctr_594;

    GameProp::Init();
    temp_r3_541 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_541 != NULL) {
        var_r3_548 = ((MKHeap *) (temp_r3_541->Current()))->Alloc(0x1FC, NULL, 0);
    } else {
        var_r3_548 = malloc(0x1FC);
    }
    M2C_FIELD(this, MKHeap **, 0xD0) = var_r3_548;
    var_r5_557 = M2C_FIELD(this, MKHeap **, 0xD0);
    M2C_FIELD(this, MKHeap **, 0xD0) = (MKHeap *) (var_r5_557 + 0x190);
    M2C_FIELD(var_r5_557, s32 *, 0x190) = 0;
    var_ctr_561 = 0x19;
    do {
        temp_r3_563 = M2C_FIELD(this, MKHeap **, 0xD0);
        M2C_FIELD(this, MKHeap **, 0xD0) = (MKHeap *) &temp_r3_563->unk4;
        temp_r3_563->unk4 = (s32) var_r5_557;
        var_r5_557 += 0x10;
        var_ctr_561 -= 1;
    } while (var_ctr_561 != 0);
    temp_r3_569 = M2C_FIELD(this, MKHeap **, 0xD0);
    temp_r3_571 = &temp_r3_569->unk4;
    M2C_FIELD(this, MKHeap **, 0xD0) = (MKHeap *) temp_r3_571;
    temp_r3_569->unk4 = 0;
    temp_r3_574 = temp_r3_571->Current();
    if (temp_r3_574 != NULL) {
        var_r3_581 = ((MKHeap *) (temp_r3_574->Current()))->Alloc(0x9CC, NULL, 0);
    } else {
        var_r3_581 = malloc(0x9CC);
    }
    M2C_FIELD(this, MKHeap **, 0xD4) = var_r3_581;
    var_r5_590 = M2C_FIELD(this, MKHeap **, 0xD4);
    M2C_FIELD(this, MKHeap **, 0xD4) = (MKHeap *) (var_r5_590 + 0x960);
    M2C_FIELD(var_r5_590, s32 *, 0x960) = 0;
    var_ctr_594 = 0x19;
    do {
        temp_r3_596 = M2C_FIELD(this, MKHeap **, 0xD4);
        M2C_FIELD(this, MKHeap **, 0xD4) = (MKHeap *) &temp_r3_596->unk4;
        temp_r3_596->unk4 = (s32) var_r5_590;
        var_r5_590 += 0x60;
        var_ctr_594 -= 1;
    } while (var_ctr_594 != 0);
    temp_r3_602 = M2C_FIELD(this, MKHeap **, 0xD4);
    M2C_FIELD(this, MKHeap **, 0xD4) = (MKHeap *) &temp_r3_602->unk4;
    temp_r3_602->unk4 = 0;
    this->unkC8 = NULL;
}
#endif

#if 0 // DRAFT: type mismatch
void MeleeTrailsDescriptor::Deinit() {
    MKHeap *temp_r0_628;
    MKHeap *temp_r0_647;
    MKHeap *temp_r3_650;
    MKHeap *var_r31_624;
    MKHeap *var_r3_625;
    MKHeap *var_r4_623;
    u32 temp_r0_633;

    var_r4_623 = this->unkE4;
    var_r31_624 = var_r4_623;
    var_r3_625 = var_r4_623;
loop_3:
    temp_r0_633 = M2C_FIELD(var_r3_625, u32 *, -4);
    var_r3_625 -= 4;
    if (temp_r0_633 != 0U) {
        temp_r0_628 = var_r3_625->unk0;
        if (temp_r0_628 < var_r31_624) {
            var_r31_624 = temp_r0_628;
        }
        goto loop_3;
    }
    if (var_r3_625 != &gEmptyPtrListDL) {
loop_9:
        temp_r0_647 = var_r4_623->unk0;
        if (temp_r0_647 != NULL) {
            if (temp_r0_647 < var_r31_624) {
                var_r31_624 = temp_r0_647;
            }
            var_r4_623 += 4;
            goto loop_9;
        }
        temp_r3_650 = var_r3_625->Current();
        if (temp_r3_650 != NULL) {
            ((MKHeap *) (temp_r3_650->Current()))->Free(var_r31_624, NULL, 0);
        } else {
            free(var_r31_624);
        }
    }
    this->unkE4 = NULL;
    KDPropExDescriptor::Deinit();
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void MeleeTrailsDescriptor::LoadDone() {
    GamePropDescriptor::LoadDone();
    InitMeleeTrailData(&this->unkE8);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
void MeleeTrailsDescriptor::InitMeleeTrailData(char *arg0) {
    MKIni spC;
    s8 *sp8;
    MKHeap *temp_r27_733;
    MKHeap *temp_r5_730;
    MKIniLine *var_r26_729;
    MKIniLine *var_r30_714;

    spC.Init(Str_Printf("%s.ini", "ELEMENT_Fire"), 0, NULL);
    var_r30_714 = spC.GetFirstLine();
loop_12:
    if (var_r30_714 != NULL) {
        if (var_r30_714->IsSection("Anim") != 0) {
            var_r26_729 = var_r30_714->unkC->GetSubLine(var_r30_714);
            temp_r5_730 = this->unkE4 - 4;
            this->unkE4 = temp_r5_730;
            temp_r27_733 = temp_r5_730->unk0;
            temp_r27_733->unk10 = 0.0f;
            temp_r27_733->unk14 = 0;
            M2C_FIELD(temp_r27_733, s8 *, 0xC) = 0;
loop_10:
            if (var_r26_729 != NULL) {
                if (var_r26_729->IsField("Name") != 0) {
                    var_r26_729->AsString(0, (s8 **) &temp_r27_733->unk10);
                }
                if (var_r26_729->IsField("EventName") != 0) {
                    var_r26_729->AsString(0, (s8 **) &temp_r27_733->unk14);
                }
                var_r26_729->LoadFloat("ScrollSpeed", (f32 *) &temp_r27_733->unk4, 0);
                var_r26_729->LoadFloat("TrailLife", (f32 *) &temp_r27_733->unk8, 0);
                if (var_r26_729->IsField("Subobject") != 0) {
                    var_r26_729->AsString(0, &sp8);
                    temp_r27_733->unk0 = MKModel_GetSubObjectIndex(this->unk2C, (SubObjectType) 0, sp8);
                }
                var_r26_729->LoadBool("Follow", (u8 *) &temp_r27_733->unkC, 0);
                var_r26_729 = var_r26_729->unkC->GetNextLine(var_r26_729);
                goto loop_10;
            }
        }
        var_r30_714 = var_r30_714->unkC->GetNextLine(var_r30_714);
        goto loop_12;
    }
    spC.Deinit();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to
s32 MeleeTrailsDescriptor::LoadLine(MKIniLine *arg0) {
    s8 *sp8;

    if ((arg0->IsField("mtdFile") != 0) && (arg0->AsString(0, &sp8) != 0)) {
        strncpy(&this->unkE8, sp8, 0x40U);
        this->unk127 = 0;
    }
    GamePropDescriptor::LoadLine(arg0);
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void MeleeTrailsDescriptor::Init() {
    MKHeap *temp_r3_861;
    MKHeap *temp_r3_883;
    MKHeap *temp_r3_889;
    MKHeap *var_r3_868;
    MKHeap *var_r5_877;
    s32 var_ctr_881;

    GamePropDescriptor::Init();
    temp_r3_861 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_861 != NULL) {
        var_r3_868 = ((MKHeap *) (temp_r3_861->Current()))->Alloc(0x38C, NULL, 0);
    } else {
        var_r3_868 = malloc(0x38C);
    }
    this->unkE4 = var_r3_868;
    var_r5_877 = this->unkE4;
    this->unkE4 = var_r5_877 + 0x320;
    M2C_FIELD(var_r5_877, s32 *, 0x320) = 0;
    var_ctr_881 = 0x19;
    do {
        temp_r3_883 = this->unkE4;
        this->unkE4 = (MKHeap *) &temp_r3_883->unk4;
        temp_r3_883->unk4 = (s32) var_r5_877;
        var_r5_877 += 0x20;
        var_ctr_881 -= 1;
    } while (var_ctr_881 != 0);
    temp_r3_889 = this->unkE4;
    this->unkE4 = (MKHeap *) &temp_r3_889->unk4;
    temp_r3_889->unk4 = 0;
}
#endif
