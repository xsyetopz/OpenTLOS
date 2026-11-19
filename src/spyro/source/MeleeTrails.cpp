#include "spyro/source/MeleeTrails.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDPositionProperty.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/Level.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/Str.h"
#include "common/gc/MKModel_GC.h"
#include <m2c_macros.h>

M2C_UNK free(M2C_UNK *);                            /* extern */
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

void MeleeTrails::Deinit() {
    M2C_UNK *temp_r0_210;
    M2C_UNK *temp_r0_229;
    M2C_UNK *temp_r0_252;
    M2C_UNK *temp_r0_271;
    M2C_UNK *var_r30_206;
    M2C_UNK *var_r30_248;
    M2C_UNK *var_r3_207;
    M2C_UNK *var_r3_249;
    M2C_UNK *var_r4_205;
    M2C_UNK *var_r4_247;
    u32 temp_r0_215;
    u32 temp_r0_257;

    var_r4_205 = M2C_FIELD(this, M2C_UNK **, 0xD0);
    var_r30_206 = var_r4_205;
    var_r3_207 = var_r4_205;
loop_3:
    temp_r0_215 = M2C_FIELD(var_r3_207, u32 *, -4);
    var_r3_207 -= 4;
    if (temp_r0_215 != 0U) {
        temp_r0_210 = (long *) (*var_r3_207);
        if (temp_r0_210 < var_r30_206) {
            var_r30_206 = temp_r0_210;
        }
        goto loop_3;
    }
    if (var_r3_207 != &gEmptyPtrListDL) {
loop_9:
        temp_r0_229 = (long *) (*var_r4_205);
        if (temp_r0_229 != NULL) {
            if (temp_r0_229 < var_r30_206) {
                var_r30_206 = temp_r0_229;
            }
            var_r4_205 += 4;
            goto loop_9;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(var_r30_206, NULL, 0);
        } else {
            free(var_r30_206);
        }
    }
    M2C_FIELD(this, M2C_UNK **, 0xD0) = NULL;
    var_r4_247 = M2C_FIELD(this, M2C_UNK **, 0xD4);
    var_r30_248 = var_r4_247;
    var_r3_249 = var_r4_247;
loop_16:
    temp_r0_257 = M2C_FIELD(var_r3_249, u32 *, -4);
    var_r3_249 -= 4;
    if (temp_r0_257 != 0U) {
        temp_r0_252 = (long *) (*var_r3_249);
        if (temp_r0_252 < var_r30_248) {
            var_r30_248 = temp_r0_252;
        }
        goto loop_16;
    }
    if (var_r3_249 != &gEmptyPtrListDL) {
loop_22:
        temp_r0_271 = (long *) (*var_r4_247);
        if (temp_r0_271 != NULL) {
            if (temp_r0_271 < var_r30_248) {
                var_r30_248 = temp_r0_271;
            }
            var_r4_247 += 4;
            goto loop_22;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(var_r30_248, NULL, 0);
        } else {
            free(var_r30_248);
        }
    }
    M2C_FIELD(this, M2C_UNK **, 0xD4) = NULL;
    GameProp::Deinit();
}

void MeleeTrails::Draw() {
    Matrix sp90;
    Matrix sp50;
    MKVector4 sp40;
    u8 *temp_r3_324;
    void **var_r30_316;
    void *temp_r31_427;
    f32 temp_f29_327;
    f32 temp_f1_381;

    var_r30_316 = M2C_FIELD(this, void ***, 0xD4);
    while (var_r30_316 != NULL && (temp_r31_427 = *var_r30_316) != NULL) {
        temp_r3_324 = (u8 *) *M2C_FIELD(temp_r31_427, s32 ***, 0x58);
        temp_f29_327 = M2C_FIELD(temp_r31_427, f32 *, 0x40) / M2C_FIELD(temp_r3_324, f32 *, 8);
        if (temp_r3_324[0xC] != 0) {
            M2C_STRUCT_COPY(&sp90, (const void *) MKModel_GetWorldMatrix(this->unkC8->unk8), 0x40);
        } else {
            M2C_STRUCT_COPY(&sp90, temp_r31_427, 0x40);
        }
        if (((u8 *) temp_r31_427)[0x5C] != 0) {
            sp90.Scale3x3(&sp90, ((1.0f - temp_f29_327) * M2C_FIELD(temp_r31_427, f32 *, 0x50)) + 1.0f);
        }
        MKModel_SetWorldMatrix(this->unk4, sp90);
        MKModel_EnableOnlySubObject(this->unk4, (SubObjectType) 0, **M2C_FIELD(temp_r31_427, s32 ***, 0x58), 1U, 1U);
        temp_f1_381 = temp_f29_327 * M2C_FIELD(temp_r31_427, f32 *, 0x4C);
        sp40.unk0 = temp_f1_381;
        sp40.unk4 = temp_f1_381;
        sp40.unk8 = temp_f1_381;
        sp40.unkC = 1.0f;
        MKModel_SetColor(this->unk4, sp40);
        M2C_STRUCT_COPY(&sp50, &Matrix::identity, 0x40);
        sp50.unk30 = M2C_FIELD(temp_r31_427, f32 *, 0x44);
        sp50.unk34 = M2C_FIELD(temp_r31_427, f32 *, 0x48);
        sp50.unk38 = 0.0f;
        sp50.unk3C = 1.0f;
        MKMaterial_SetTextureMatrix(this->unkCC, &sp50);
        MKModel_Draw(this->unk4, NULL);
        var_r30_316 += 1;
    }
}

void *MeleeTrails::Update() {
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
            if (M2C_FIELD(temp_r4_498, f32 *, 0x40) <= 0.0f) {
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

s32 MeleeTrails::LoadDone() {
    GameProp::LoadDone();
    this->unkCC = MKModel_GetMaterial(this->unk4, 0, 0U);
}

void MeleeTrails::Init() {
    MKHeap *temp_r3_563;
    MKHeap *temp_r3_569;
    MKHeap *temp_r3_596;
    MKHeap *temp_r3_602;
    MKHeap *var_r3_548;
    MKHeap *var_r3_581;
    MKHeap *var_r5_557;
    MKHeap *var_r5_590;
    s32 var_ctr_561;
    s32 var_ctr_594;

    GameProp::Init();
    if (MKHeap::Current() != NULL) {
        var_r3_548 = (MKHeap *) (((MKHeap *) (MKHeap::Current()))->Alloc(0x1FC, NULL, 0));
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
    M2C_FIELD(this, MKHeap **, 0xD0) = (MKHeap *) &temp_r3_569->unk4;
    temp_r3_569->unk4 = 0;
    if (MKHeap::Current() != NULL) {
        var_r3_581 = (MKHeap *) (((MKHeap *) (MKHeap::Current()))->Alloc(0x9CC, NULL, 0));
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

void MeleeTrailsDescriptor::Deinit() {
    u8 *temp_r0_628;
    u8 *temp_r0_647;
    u8 *var_r31_624;
    u8 *var_r3_625;
    u8 *var_r4_623;
    u32 temp_r0_633;

    var_r4_623 = M2C_FIELD(this, u8 **, 0xE4);
    var_r31_624 = var_r4_623;
    var_r3_625 = var_r4_623;
loop_3:
    temp_r0_633 = M2C_FIELD(var_r3_625, u32 *, -4);
    var_r3_625 -= 4;
    if (temp_r0_633 != 0U) {
        temp_r0_628 = M2C_FIELD(var_r3_625, u8 **, 0);
        if (temp_r0_628 < var_r31_624) {
            var_r31_624 = temp_r0_628;
        }
        goto loop_3;
    }
    if (var_r3_625 != (u8 *) &gEmptyPtrListDL) {
loop_9:
        temp_r0_647 = M2C_FIELD(var_r4_623, u8 **, 0);
        if (temp_r0_647 != NULL) {
            if (temp_r0_647 < var_r31_624) {
                var_r31_624 = temp_r0_647;
            }
            var_r4_623 += 4;
            goto loop_9;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(var_r31_624, NULL, 0);
        } else {
            free((M2C_UNK *) var_r31_624);
        }
    }
    M2C_FIELD(this, u8 **, 0xE4) = NULL;
    KDPropExDescriptor::Deinit();
}

void MeleeTrailsDescriptor::LoadDone() {
    GamePropDescriptor::LoadDone();
    InitMeleeTrailData((char *) &this->unkE8);
}

void MeleeTrailsDescriptor::InitMeleeTrailData(char *arg0) {
    MKIni spC;
    const char *sp8;
    u8 *temp_r27;
    u8 *temp_r5;
    MKIniLine *var_r26;
    MKIniLine *var_r30;

    spC.Init((const char *) Str_Printf("%s.ini", arg0), 0, NULL);
    var_r30 = spC.GetFirstLine();
    while (var_r30 != NULL) {
        if (var_r30->IsSection("Anim") != 0) {
            var_r26 = var_r30->unkC->GetSubLine(var_r30);
            temp_r5 = M2C_FIELD(this, u8 **, 0xE4) - 4;
            M2C_FIELD(this, u8 **, 0xE4) = temp_r5;
            temp_r27 = M2C_FIELD(temp_r5, u8 **, 0);
            M2C_FIELD(temp_r27, u8 **, 0x10) = NULL;
            M2C_FIELD(temp_r27, u8 **, 0x14) = NULL;
            temp_r27[0xC] = 0;
            while (var_r26 != NULL) {
                if (var_r26->IsField("Name") != 0) {
                    var_r26->AsString(0, (const char **) (temp_r27 + 0x10));
                }
                if (var_r26->IsField("EventName") != 0) {
                    var_r26->AsString(0, (const char **) (temp_r27 + 0x14));
                }
                var_r26->LoadFloat("ScrollSpeed", (f32 *) (temp_r27 + 4), 0);
                var_r26->LoadFloat("TrailLife", (f32 *) (temp_r27 + 8), 0);
                if (var_r26->IsField("Subobject") != 0) {
                    var_r26->AsString(0, &sp8);
                    M2C_FIELD(temp_r27, s32 *, 0) = MKModel_GetSubObjectIndex(M2C_FIELD(this, MKModel **, 0x2C), (SubObjectType) 0, sp8);
                }
                var_r26->LoadBool("Follow", (bool *) (temp_r27 + 0xC), 0);
                var_r26 = var_r26->unkC->GetNextLine(var_r26);
            }
        }
        var_r30 = var_r30->unkC->GetNextLine(var_r30);
    }
    spC.Deinit();
}

s32 MeleeTrailsDescriptor::LoadLine(MKIniLine *arg0) {
    const char *sp8;

    if ((arg0->IsField("mtdFile") != 0) && (arg0->AsString(0, &sp8) != 0)) {
        strncpy((char *) &this->unkE8, sp8, 0x40U);
        this->unk127 = 0;
    }
    return GamePropDescriptor::LoadLine(arg0);
}

void MeleeTrailsDescriptor::Init() {
    u8 *var_r5;
    u8 *temp;
    s32 var_ctr;

    GamePropDescriptor::Init();
    if (MKHeap::Current() != NULL) {
        var_r5 = (u8 *) (((MKHeap *) (MKHeap::Current()))->Alloc(0x38C, NULL, 0));
    } else {
        var_r5 = (u8 *) malloc(0x38C);
    }
    M2C_FIELD(this, u8 **, 0xE4) = var_r5;
    var_r5 = M2C_FIELD(this, u8 **, 0xE4);
    M2C_FIELD(this, u8 **, 0xE4) = var_r5 + 0x320;
    M2C_FIELD(var_r5, s32 *, 0x320) = 0;
    var_ctr = 0x19;
    do {
        temp = M2C_FIELD(this, u8 **, 0xE4) + 4;
        M2C_FIELD(this, u8 **, 0xE4) = temp;
        M2C_FIELD(temp, u8 **, 0) = var_r5;
        var_r5 += 0x20;
        var_ctr -= 1;
    } while (var_ctr != 0);
    temp = M2C_FIELD(this, u8 **, 0xE4) + 4;
    M2C_FIELD(this, u8 **, 0xE4) = temp;
    M2C_FIELD(temp, s32 *, 0) = 0;
}
