#include "spyro/source/EnemyGenerator.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
#include "spyro/source/EnemySpawner.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/KDPositionProperty.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/KDSynkerPlayer3.h"
#include "spyro/source/KDSynkerPlayerActor.h"
#include "spyro/source/KDSynkerPlayerActorList.h"
#include "spyro/source/KDSynkerPlayerCamera.h"
#include "spyro/source/KDSynkerPlayerEvents.h"
#include "spyro/source/KDSynkerPlayerSounds.h"
#include "spyro/source/KDSynkerPlayerTools.h"
#include "spyro/source/Level.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/SpawnPointData.h"
#include "spyro/source/SpawnPointObject.h"
#include "spyro/source/SpawnerObject.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "common/Source/Str.h"
#include "spyro/source/DataMap.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(s32);                                  /* extern */
extern DataMap enemyTypeDataMap;
extern void **gMK;
extern M2C_UNK gb;

void EnemyGeneratorDescriptor::LoadDone() {

}

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to 'bool *'
s32 EnemyGeneratorDescriptor::LoadLine(MKIniLine *arg0) {
    s8 *sp8;
    MKIniLine *var_r24_38;
    MKIniLine *var_r25_166;
    MKIniLine *var_r25_286;
    MKIniLine *var_r26_117;
    s32 temp_r26_92;
    s32 temp_r27_67;
    s32 var_r26_33;
    s32 var_r28_32;
    s32 var_r29_29;
    s32 var_r30_34;
    void *var_r3_100;
    void *var_r3_75;

    if (arg0->IsField("EnemyGenerator") != 0) {
        var_r29_29 = 0;
        sp8 = NULL;
        var_r28_32 = 0;
        var_r26_33 = 0;
        var_r30_34 = 0;
        var_r24_38 = arg0->unkC->GetSubLine(arg0);
loop_7:
        if (var_r24_38 != NULL) {
            if (var_r24_38->IsField("Door") != 0) {
                var_r28_32 += 1;
            }
            if (var_r24_38->IsField("Wave") != 0) {
                var_r26_33 += 1;
            }
            var_r24_38 = var_r24_38->unkC->GetNextLine(var_r24_38);
            goto loop_7;
        }
        if (var_r28_32 > 0) {
            this->unk8 = var_r28_32;
            temp_r27_67 = this->unk8 * 0x24;
            if (MKHeap::Current() != NULL) {
                var_r3_75 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r27_67, NULL, 0);
            } else {
                var_r3_75 = malloc(temp_r27_67);
            }
            this->unk10 = var_r3_75;
            memset(this->unk10, 0, this->unk8 * 0x24);
        }
        if (var_r26_33 > 0) {
            this->unkC = var_r26_33;
            temp_r26_92 = this->unkC * 0x14;
            if (MKHeap::Current() != NULL) {
                var_r3_100 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r26_92, NULL, 0);
            } else {
                var_r3_100 = malloc(temp_r26_92);
            }
            this->unk14 = var_r3_100;
            memset(this->unk14, 0, this->unkC * 0x14);
        }
        var_r26_117 = arg0->unkC->GetSubLine(arg0);
loop_49:
        if (var_r26_117 != NULL) {
            if ((var_r26_117->LoadInt("spawnPointProps", (int *) &this->unk0, 0) == 0) && (var_r26_117->LoadInt("doorProps", (int *) &this->unk4, 0) == 0) && (var_r26_117->LoadBool("bLockSpawnPoints", &this->unk18, 0) == 0) && (var_r26_117->LoadBool("bSpawnFromVisibleDoors", &this->unk19, 0) == 0)) {
                if (var_r26_117->IsField("Door") != 0) {
                    var_r25_166 = var_r26_117->unkC->GetSubLine(var_r26_117);
loop_35:
                    if (var_r25_166 != NULL) {
                        if ((var_r25_166->LoadInt("spawnPointProp", ((u8 *) this->unk10) + var_r30_34, 0) == 0) && (var_r25_166->LoadInt("doorProp", ((u8 *) this->unk10) + (var_r30_34 + 4), 0) == 0) && (var_r25_166->LoadString("doorRefPt", ((u8 *) this->unk10) + (var_r30_34 + 8), 0) == 0) && (var_r25_166->LoadString("spawnRefPt", ((u8 *) this->unk10) + (var_r30_34 + 0xC), 0) == 0) && (var_r25_166->LoadString("openingScript", ((u8 *) this->unk10) + (var_r30_34 + 0x10), 0) == 0) && (var_r25_166->LoadString("closingScript", ((u8 *) this->unk10) + (var_r30_34 + 0x14), 0) == 0) && (var_r25_166->LoadString("openScript", ((u8 *) this->unk10) + (var_r30_34 + 0x18), 0) == 0) && (var_r25_166->LoadString("closedScript", ((u8 *) this->unk10) + (var_r30_34 + 0x1C), 0) == 0)) {
                            var_r25_166->LoadBool("bAnimate", ((u8 *) this->unk10) + (var_r30_34 + 0x20), 0);
                        }
                        var_r25_166 = var_r25_166->unkC->GetNextLine(var_r25_166);
                        goto loop_35;
                    }
                    var_r30_34 += 0x24;
                } else if (var_r26_117->IsField("Wave") != 0) {
                    var_r25_286 = var_r26_117->unkC->GetSubLine(var_r26_117);
loop_46:
                    if (var_r25_286 != NULL) {
                        if ((var_r25_286->LoadInt("iMaxSpawnAmount", ((u8 *) this->unk14) + var_r29_29, 0) == 0) && (var_r25_286->LoadInt("iMaxActive", ((u8 *) this->unk14) + (var_r29_29 + 4), 0) == 0) && (var_r25_286->LoadFloat("fSpawnDelay", ((u8 *) this->unk14) + (var_r29_29 + 0xC), 0) == 0) && (var_r25_286->LoadFloat("fDelayBetweenSpawns", ((u8 *) this->unk14) + (var_r29_29 + 0x10), 0) == 0) && (var_r25_286->LoadString("iEnemyType", &sp8, 0) != 0)) {
                            *(var_r29_29 + (((u8 *) this->unk14) + 8)) = DataMap_GetValue(&enemyTypeDataMap, sp8);
                        }
                        var_r25_286 = var_r25_286->unkC->GetNextLine(var_r25_286);
                        goto loop_46;
                    }
                    var_r29_29 += 0x14;
                }
            }
            var_r26_117 = var_r26_117->unkC->GetNextLine(var_r26_117);
            goto loop_49;
        }
        return 1;
    }
    return 0;
}
#endif

void EnemyGeneratorDescriptor::Deinit() {
    void *temp_r31_384;
    void *temp_r31_402;

    temp_r31_384 = this->unk10;
    if (temp_r31_384 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_384, NULL, 0);
        } else {
            free(temp_r31_384);
        }
    }
    this->unk10 = NULL;
    temp_r31_402 = this->unk14;
    if (temp_r31_402 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_402, NULL, 0);
        } else {
            free(temp_r31_402);
        }
    }
    this->unk14 = NULL;
}

void EnemyGeneratorDescriptor::Init() {
    this->unk18 = 1;
    this->unk19 = 0;
    this->unk0 = 0;
    this->unk4 = 0;
    this->unk8 = 0;
    this->unkC = 0;
    this->unk10 = NULL;
    this->unk14 = NULL;
}

#if 0 // DRAFT: identifier 'EnemyGeneratorDoor::GetSpawnPos()' redeclared was declared as: 'MKVector3 ()' now declared as: 'void ()'
void EnemyGeneratorDoor::GetSpawnPos() {
    MKVector3 result;
    MKVector3 *sret = &result;
    f64 sp10;
    f64 sp8;
    SpawnPointObject *temp_r3_455;

    if ((s32) M2C_FIELD(M2C_FIELD(this, void **, 0), s32 *, 0x80) > 0) {
        temp_r3_455 = this->unk18;
        sp8 = M2C_FIELD(temp_r3_455, f64 *, 0x40);
        sp10 = M2C_FIELD(temp_r3_455, f64 *, 0x48);
    } else {
        MKModel_CalculateRefPointWorldPosition(M2C_FIELD(M2C_FIELD(this, void **, 8), MKModel **, 4), this->unk14, (MKVector3 *) &sp8);
    }
    M2C_FIELD(sret, f64 *, 0) = sp8;
    M2C_FIELD(sret, f64 *, 8) = sp10;
    return result;
}
#endif

#if 0 // DRAFT: identifier 'EnemyGeneratorDoor::GetDoorDir()' redeclared was declared as: 'MKVector3 ()' now declared as: 'void ()'
void EnemyGeneratorDoor::GetDoorDir() {
    MKVector3 result;
    MKVector3 *sret = &result;
    Matrix sp80;
    f64 sp70;
    f64 sp68;
    MKVector3 sp58;
    MKVector3 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f32 var_f3_614;
    f32 var_f4_547;
    f64 temp_f1_553;
    f64 temp_f1_559;
    f64 temp_f1_563;
    s32 temp_r3_582;
    s32 var_r0_592;

    if (((u8) M2C_FIELD(MKModel_GetRefPointData(M2C_FIELD(M2C_FIELD(this, void **, 8), MKModel **, 4), this->unk10), u8 *, 0x16) == 5) && (MKModel_GetRefPointMatrix(M2C_FIELD(M2C_FIELD(this, void **, 8), MKModel **, 4), this->unk10, &sp80, 1U) != 0)) {
        sp38 = -sp80.unk20;
        sp3C = -sp80.unk24;
        sp40 = -sp80.unk28;
        M2C_FIELD(sret, f64 *, 0) = (f64) sp38;
        M2C_FIELD(sret, f64 *, 8) = (f64) sp40;
        return result;
    }
    sp48 = GetSpawnPos();
    sp58 = GetDoorPos();
    sp18 = sp58 - M2C_BITWISE(f64, sp48);
    sp68 = sp18;
    sp20 = sp58.unk8 - sp48.unk8;
    sp70 = (f64) sp20;
    var_f4_547 = ((f32) sp70 * (f32) sp70) + (((f32) sp68 * (f32) sp68) + ((*(f32 *) ((u8 *) &sp68 + 0x4)) * (*(f32 *) ((u8 *) &sp68 + 0x4))));
    if (var_f4_547 > 1e-12f) {
        if (var_f4_547 > 0.0f) {
            temp_f1_553 = __frsqrte(var_f4_547);
            temp_f1_559 = 0.5 * temp_f1_553 * -(((f64) var_f4_547 * (temp_f1_553 * temp_f1_553)) - 3.0);
            temp_f1_563 = 0.5 * temp_f1_559 * -(((f64) var_f4_547 * (temp_f1_559 * temp_f1_559)) - 3.0);
            var_f4_547 = (f32) ((f64) var_f4_547 * (0.5 * temp_f1_563 * -(((f64) var_f4_547 * (temp_f1_563 * temp_f1_563)) - 3.0)));
        } else if (var_f4_547 < M2C_BITWISE(f32, 0.0)) {
            var_f4_547 = __float_nan;
        } else {
            sp10 = var_f4_547;
            temp_r3_582 = M2C_BITWISE(s32, sp10) & 0x7F800000;
            switch (temp_r3_582) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_592 = 1;
                } else {
                    var_r0_592 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_592 = 5;
                } else {
                    var_r0_592 = 3;
                }
                break;
            default:
                var_r0_592 = 4;
                break;
            }
            if (var_r0_592 == 1) {
                var_f4_547 = __float_nan;
            }
        }
        var_f3_614 = 1.0f / var_f4_547;
    } else {
        var_f3_614 = 0.0f;
    }
    sp2C = (*(f32 *) ((u8 *) &sp68 + 0x4)) * var_f3_614;
    sp28 = (f32) sp68 * var_f3_614;
    sp30 = (f32) sp70 * var_f3_614;
    M2C_FIELD(sret, f64 *, 0) = (f64) sp28;
    M2C_FIELD(sret, f64 *, 8) = (f64) sp30;
    return result;
}
#endif

#if 0 // DRAFT: identifier 'EnemyGeneratorDoor::GetDoorPos()' redeclared was declared as: 'MKVector3 ()' now declared as: 'void ()'
void EnemyGeneratorDoor::GetDoorPos() {
    MKVector3 result;
    MKVector3 *sret = &result;
    MKVector3 sp8;

    MKModel_CalculateRefPointWorldPosition(M2C_FIELD(M2C_FIELD(this, void **, 8), MKModel **, 4), this->unk10, &sp8);
    M2C_FIELD(sret, MKVector3 *, 0) = sp8;
    return result;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void EnemyGeneratorDoor::Close() {
    void **sp10;
    s32 spC;
    s32 sp8;
    MKProp *temp_r3_674;
    u64 temp_r31_700;
    void **temp_r3_702;

    if ((void **) this->unk20 != NULL) {
        temp_r3_674 = M2C_FIELD(this, MKProp **, 8);
        if ((temp_r3_674 != NULL) && ((spC = 0, sp10 = NULL, sp8 = 0x8E, M2C_FIELD(temp_r3_674->__vptr, M2C_UNK (**)(s32 *, M2C_UNK), 0x2C)(&sp8, 0), ((sp10 == NULL) != 0)) || (M2C_FIELD(*sp10, u8 (**)(), 0x20)() == 0))) {
            temp_r31_700 = KDProperty::GetOwnerProp();
            KDProperty::SetOwnerProp(M2C_FIELD(this, MKProp **, 8));
            temp_r3_702 = this->unk20;
            M2C_FIELD(*temp_r3_702, M2C_UNK (**)(void **, M2C_UNK), 0x48)(temp_r3_702, 1);
            KDProperty::SetOwnerProp((MKProp *) temp_r31_700);
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void EnemyGeneratorDoor::Open() {
    void **sp10;
    s32 spC;
    s32 sp8;
    MKProp *temp_r3_743;
    u64 temp_r31_769;
    void **temp_r3_771;

    if ((void **) this->unk1C != NULL) {
        temp_r3_743 = M2C_FIELD(this, MKProp **, 8);
        if ((temp_r3_743 != NULL) && ((spC = 0, sp10 = NULL, sp8 = 0x8E, M2C_FIELD(temp_r3_743->__vptr, M2C_UNK (**)(s32 *, M2C_UNK), 0x2C)(&sp8, 0), ((sp10 == NULL) != 0)) || (M2C_FIELD(*sp10, u8 (**)(), 0x20)() == 0))) {
            temp_r31_769 = KDProperty::GetOwnerProp();
            KDProperty::SetOwnerProp(M2C_FIELD(this, MKProp **, 8));
            temp_r3_771 = this->unk1C;
            M2C_FIELD(*temp_r3_771, M2C_UNK (**)(void **, M2C_UNK), 0x48)(temp_r3_771, 1);
            KDProperty::SetOwnerProp((MKProp *) temp_r31_769);
        }
    }
}
#endif

void EnemyGeneratorDoor::Deinit() {
    if ((u8) this->unk2C != 0) {
        this->unk18->Deinit();
        operator delete(this->unk18);
    }
}

#if 0 // DRAFT: function call 'Tools_GetMatchingRefPointIndex(MKModel *, signed char *)' does not match 'Tools_GetMatchingRefPointIndex(MKModel *, const char *)'
void EnemyGeneratorDoor::Init(EnemyGenerator *arg0, EnemyGeneratorDoorData *arg1, MKProp *arg2, SpawnPointObject *arg3) {
    MKProp *temp_r3_837;
    MKProp *temp_r3_913;
    SpawnPointData *temp_r30_861;
    SpawnPointObject *temp_r3_854;
    s32 temp_r30_919;
    s8 *temp_r4_920;
    s8 *temp_r4_929;
    s8 *temp_r4_938;
    s8 *temp_r4_947;

    M2C_FIELD(this, EnemyGenerator **, 0) = arg0;
    M2C_FIELD(this, EnemyGeneratorDoorData **, 4) = arg1;
    M2C_FIELD(this, MKProp **, 8) = NULL;
    M2C_FIELD(this, s32 *, 0xC) = 0;
    this->unk10 = 0xFFFF;
    this->unk14 = 0xFFFF;
    this->unk1C = NULL;
    this->unk20 = NULL;
    this->unk24 = NULL;
    this->unk28 = NULL;
    M2C_FIELD(this, MKProp **, 8) = arg2;
    this->unk18 = arg3;
    this->unk2C = this->unk18 == NULL;
    temp_r3_837 = M2C_FIELD(this, MKProp **, 8);
    if (temp_r3_837 != NULL) {
        this->unk10 = (s32) Tools_GetMatchingRefPointIndex(temp_r3_837->unk4, M2C_FIELD(this, EnemyGeneratorDoorData **, 4)->unk8);
        this->unk14 = (s32) Tools_GetMatchingRefPointIndex(M2C_FIELD(this, MKProp **, 8)->unk4, M2C_FIELD(this, EnemyGeneratorDoorData **, 4)->unkC);
    }
    temp_r3_854 = this->unk18;
    if (temp_r3_854 == NULL) {
        operator new(0x28U, NULL, 0);
        temp_r30_861 = M2C_ERROR(/* Read from unset register $r3 */);
        if (temp_r30_861 != NULL) {
            temp_r30_861->__vptr = &__vt;
            temp_r30_861->__vptr = &__vt;
            M2C_FIELD(temp_r30_861, s32 *, 8) = 0;
            ((EventMessage *) (temp_r30_861 + 8))->Init();
            M2C_FIELD(temp_r30_861, s32 *, 0xC) = 0;
            ((EventMessage *) (temp_r30_861 + 0xC))->Init();
            M2C_FIELD(temp_r30_861, s32 *, 0x10) = 0;
            ((EventMessage *) (temp_r30_861 + 0x10))->Init();
            M2C_FIELD(temp_r30_861, s32 *, 0x14) = 0;
            ((EventMessage *) (temp_r30_861 + 0x14))->Init();
        }
        operator new(0x60U, NULL, 0);
        this->unk18 = M2C_ERROR(/* Read from unset register $r3 */);
        temp_r30_861->Init();
        this->unk18->Init(temp_r30_861);
        this->unk18->LoadDone();
        M2C_FIELD(temp_r30_861, s32 *, 4) = (s32) (M2C_FIELD(temp_r30_861, s32 *, 4) | 0x4220);
    } else {
        checked_cast<EnemySpawnPointData *, SpawnPointData>((SpawnPointData *) temp_r3_854->unk4);
    }
    if ((u8) M2C_FIELD(this, EnemyGeneratorDoorData **, 4)->unk20 != 0) {
        temp_r3_913 = M2C_FIELD(this, MKProp **, 8);
        if (temp_r3_913 != NULL) {
            temp_r30_919 = (long) (checked_cast<KDPropExDescriptor *, MKPropDescriptor>((MKPropDescriptor *) temp_r3_913->unk0));
            temp_r4_920 = M2C_FIELD(this, EnemyGeneratorDoorData **, 4)->unk10;
            if (temp_r4_920 != NULL) {
                this->unk1C = (const char *) (checked_cast<KDScriptProperty *, KDProperty>(((KDPropertySet *) (temp_r30_919 + 0x74))->Find(temp_r4_920)));
            }
            temp_r4_929 = M2C_FIELD(this, EnemyGeneratorDoorData **, 4)->unk14;
            if (temp_r4_929 != NULL) {
                this->unk20 = (const char *) (checked_cast<KDScriptProperty *, KDProperty>(((KDPropertySet *) (temp_r30_919 + 0x74))->Find(temp_r4_929)));
            }
            temp_r4_938 = M2C_FIELD(this, EnemyGeneratorDoorData **, 4)->unk18;
            if (temp_r4_938 != NULL) {
                this->unk24 = (const char *) (checked_cast<KDScriptProperty *, KDProperty>(((KDPropertySet *) (temp_r30_919 + 0x74))->Find(temp_r4_938)));
            }
            temp_r4_947 = M2C_FIELD(this, EnemyGeneratorDoorData **, 4)->unk1C;
            if (temp_r4_947 != NULL) {
                this->unk28 = (const char *) (checked_cast<KDScriptProperty *, KDProperty>(((KDPropertySet *) (temp_r30_919 + 0x74))->Find(temp_r4_947)));
            }
        }
    }
}
#endif

#if 0 // DRAFT: illegal type
u8 EnemyGenerator::HasEnemyWaveFinished() {
    s32 temp_r4_977;
    s32 temp_r5_969;
    u8 var_r31_975;

    temp_r5_969 = this->unk7C;
    if (temp_r5_969 < (s32) this->unk78) {
        var_r31_975 = 0;
        temp_r4_977 = *(this->unk50->unk14 + (temp_r5_969 * 0x14));
        if ((temp_r4_977 > 0) && ((s32) this->unk20 == temp_r4_977)) {
            GetNumberActive();
            if ((s32) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
                var_r31_975 = 1;
            }
        }
    } else {
        var_r31_975 = 1;
    }
    return var_r31_975;
}
#endif

#if 0 // DRAFT: illegal type
void EnemyGenerator::StartEnemyWave() {
    if ((s32) this->unk7C < (s32) this->unk78) {
        this->unk20 = 0;
        this->unk24 = *(this->unk50->unk14 + (this->unk7C * 0x14));
        this->unk28 = M2C_FIELD((this->unk50->unk14 + (this->unk7C * 0x14)), s32 *, 4);
        this->unk30 = M2C_FIELD((this->unk50->unk14 + (this->unk7C * 0x14)), f32 *, 0xC);
        this->unk34 = M2C_FIELD((this->unk50->unk14 + (this->unk7C * 0x14)), f32 *, 0x10);
        FunctionOn();
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to 'float'
void EnemyGenerator::UpdateUsedSpawnPointMask() {
    f64 sp20;
    f64 sp18;
    MKVector3 sp8;
    s32 temp_r30_1066;
    s32 var_r29_1061;
    u32 *var_r28_1059;
    u32 temp_r4_1102;
    void *temp_r3_1077;

    SpawnerObject::UpdateUsedSpawnPointMask();
    if ((u8) this->unk85 != 0) {
        var_r28_1059 = this->unk44;
        var_r29_1061 = 0;
loop_6:
        if (var_r28_1059 != NULL) {
            temp_r4_1102 = *var_r28_1059;
            if (temp_r4_1102 != 0) {
                temp_r30_1066 = 1 << var_r29_1061;
                if (!(this->unk1C & temp_r30_1066)) {
                    sp8 = ((EnemyGeneratorDoor *) (GetDoor((SpawnPointObject *) temp_r4_1102)))->GetDoorDir();
                    temp_r3_1077 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
                    sp18 = M2C_FIELD(temp_r3_1077, f64 *, 0x20);
                    sp20 = M2C_FIELD(temp_r3_1077, f64 *, 0x28);
                    if ((((f32) sp20 * sp8.unk8) + (((f32) sp18 * M2C_BITWISE(f32, sp8)) + ((*(f32 *) ((u8 *) &sp18 + 0x4)) * sp8.unk4))) > 0.0f) {
                        this->unk1C |= temp_r30_1066;
                    }
                }
                var_r29_1061 += 1;
                var_r28_1059 += 4;
                goto loop_6;
            }
        }
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to 'float'
SpawnPointObject *EnemyGenerator::GetSpawnPointObject() {
    MKVector3 sp8;
    SpawnPointObject *temp_r3_1121;

    temp_r3_1121 = SpawnerObject::GetSpawnPointObject();
    if (temp_r3_1121 != NULL) {
        sp8 = ((EnemyGeneratorDoor *) (GetDoor(temp_r3_1121)))->GetSpawnPos();
        temp_r3_1121->unk40 = M2C_BITWISE(f32, sp8);
        temp_r3_1121->unk44 = sp8.unk4;
        temp_r3_1121->unk48 = sp8.unk8;
        temp_r3_1121->unk4C = 1.0f;
    }
    return temp_r3_1121;
}
#endif

void EnemyGenerator::DespawnAll() {
    DespawnAll();
}

#if 0 // DRAFT: illegal operand
void *EnemyGenerator::GetDoor(SpawnPointObject *arg0) {
    s32 temp_r7_1164;
    s32 var_ctr_1166;
    s32 var_r5_1165;
    void *temp_r6_1171;

    temp_r7_1164 = this->unk70;
    var_r5_1165 = 0;
    var_ctr_1166 = temp_r7_1164;
    if (temp_r7_1164 > 0) {
loop_1:
        temp_r6_1171 = ((u8 *) this->unk54) + var_r5_1165;
        if ((u32) M2C_FIELD(temp_r6_1171, u32 *, 0x18) == arg0) {
            return temp_r6_1171;
        }
        var_r5_1165 += 0x30;
        var_ctr_1166 -= 1;
        if (var_ctr_1166 == 0) {
            goto block_4;
        }
        goto loop_1;
    }
block_4:
    if (temp_r7_1164 > 0) {
        return this->unk54;
    }
    return NULL;
}
#endif

void EnemyGenerator::Message(MKMessage *arg0) {
    s32 temp_r0_1196;

    temp_r0_1196 = arg0->unk0;
    switch (temp_r0_1196) {                         /* irregular */
    case 0xB5:
        FunctionOn();
        return;
    case 0xB4:
        FunctionOff();
        return;
    }
}

#if 0 // DRAFT: declaration syntax error
void EnemyGenerator::Update() {
    KDSynkerPlayer3 *temp_r3_1254;
    u8 var_r30_1251;
    void *temp_r29_1253;

    if (((s32) this->unk7C < (s32) this->unk78) && (HasEnemyWaveFinished() != 0)) {
        this->unk7C += 1;
        StartEnemyWave();
        this->unk68.Send(NULL);
        if ((s32) this->unk7C == (s32) this->unk78) {
            this->unk6C.Send(NULL);
        }
    }
    if ((s32) this->unk7C < (s32) this->unk78) {
        var_r30_1251 = 0;
        temp_r29_1253 = M2C_FIELD(&gb, void **, 0xC);
        temp_r3_1254 = M2C_FIELD(temp_r29_1253, KDSynkerPlayer3 **, 0x78);
        if (((temp_r3_1254 != NULL) && (temp_r3_1254->IsPlaying() != 0)) || (((s32) M2C_FIELD(temp_r29_1253, s32 *, 0x74) == 2) && (((KDStateMachine<CutsceneSystem> *) (((u8 *) temp_r29_1253) + 0x24))->GetState() == 2))) {
            var_r30_1251 = 1;
        }
        if (var_r30_1251 == 0) {
            TrySpawnItems(M2C_FIELD((this->unk50->unk14 + (this->unk7C * 0x14)), s32 *, 8), 0U);
        }
    }
}
#endif

void EnemyGenerator::SetDefaults() {
    SetDefaults();
    this->unk7C = this->unk74;
    StartEnemyWave();
}

#if 0 // DRAFT: illegal type
void EnemyGenerator::Resolve() {
    SpawnPointObject *spC8;
    s32 spC4;
    s32 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    MKVector3 sp80;
    MKVector3 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    EnemyGeneratorDescriptor *temp_r3_1333;
    EnemyGeneratorDescriptor *temp_r5_1437;
    MKProp *var_r6_1459;
    SpawnPointObject *var_r7_1439;
    f32 var_f4_1515;
    f32 var_f6_1498;
    f64 temp_f0_1492;
    f64 temp_f1_1486;
    f64 temp_f1_1520;
    f64 temp_f1_1526;
    f64 temp_f1_1530;
    s32 temp_r0_1584;
    s32 temp_r3_1549;
    s32 temp_r4_1367;
    s32 var_r0_1559;
    s32 var_r27_1319;
    s32 var_r27_1341;
    s32 var_r27_1375;
    s32 var_r27_1434;
    s32 var_r28_1318;
    s32 var_r28_1340;
    s32 var_r28_1433;
    s32 var_r30_1374;
    s32 var_r30_1431;
    s32 var_r8_1438;
    u32 temp_r3_1323;
    u32 temp_r3_1345;
    void *temp_r3_1379;
    void *temp_r3_1396;
    void *temp_r4_1612;
    void *temp_r4_1633;
    void *temp_r5_1592;

    var_r28_1318 = 0;
    var_r27_1319 = 0;
loop_4:
    temp_r3_1333 = this->unk50;
    if (var_r28_1318 < (s32) temp_r3_1333->unk4) {
        temp_r3_1323 = *(this->unk58 + var_r27_1319);
        if (temp_r3_1323 != 0U) {
            *(this->unk58 + var_r27_1319) = MKSceneManager::PropResolver_Resolve((s32) temp_r3_1323);
        }
        var_r28_1318 += 1;
        var_r27_1319 += 4;
        goto loop_4;
    }
    if ((s32) temp_r3_1333->unk0 > 0) {
        var_r28_1340 = 0;
        var_r27_1341 = 0;
loop_11:
        if (var_r28_1340 < (s32) this->unk50->unk0) {
            temp_r3_1345 = *(this->unk5C + var_r27_1341);
            if (temp_r3_1345 != 0U) {
                *(this->unk5C + var_r27_1341) = MKSceneManager::PropResolver_Resolve((s32) temp_r3_1345);
                if ((u32) *(this->unk5C + var_r27_1341) != 0U) {
                    this->unk80 += 1;
                }
            }
            var_r28_1340 += 1;
            var_r27_1341 += 4;
            goto loop_11;
        }
    }
    temp_r4_1367 = this->unk80;
    if (temp_r4_1367 != 0) {
        spC4 = 0;
        AddSpawnPointBegin(temp_r4_1367);
        var_r30_1374 = 0;
        var_r27_1375 = 0;
loop_21:
        if (var_r30_1374 < (s32) this->unk80) {
            temp_r3_1379 = *(this->unk5C + var_r27_1375);
            if (temp_r3_1379 != NULL) {
                spC0 = 0x35;
                spC8 = NULL;
                M2C_FIELD(M2C_FIELD(temp_r3_1379, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&spC0);
                *(this->unk5C + var_r27_1375) = spC8;
                temp_r3_1396 = M2C_FIELD(*(this->unk5C + var_r27_1375), void **, 4);
                M2C_FIELD(temp_r3_1396, s32 *, 4) = (s32) (M2C_FIELD(temp_r3_1396, s32 *, 4) | 0x4220);
                if ((u32) M2C_FIELD(temp_r3_1396, u32 *, 0x20) != 0U) {
                    M2C_FIELD(temp_r3_1396, s32 *, 4) = (s32) (M2C_FIELD(temp_r3_1396, s32 *, 4) | 0x80);
                }
                if ((u32) M2C_FIELD(temp_r3_1396, u32 *, 0x24) != 0U) {
                    M2C_FIELD(temp_r3_1396, s32 *, 4) = (s32) (M2C_FIELD(temp_r3_1396, s32 *, 4) | 0x800);
                }
                AddSpawnPoint(spC8);
            }
            var_r30_1374 += 1;
            var_r27_1375 += 4;
            goto loop_21;
        }
    } else {
        AddSpawnPointBegin(this->unk70);
    }
    var_r30_1431 = 0;
    var_r28_1433 = 0;
    var_r27_1434 = 0;
loop_54:
    if (var_r30_1431 < (s32) this->unk70) {
        temp_r5_1437 = this->unk50;
        var_r8_1438 = var_r30_1431;
        var_r7_1439 = NULL;
        if (var_r30_1431 >= (s32) temp_r5_1437->unk8) {
            var_r8_1438 = 0;
        }
        if ((s32) this->unk80 != 0) {
            var_r7_1439 = *(this->unk5C + (*(temp_r5_1437->unk10 + (var_r8_1438 * 0x24)) * 4));
        }
        if ((s32) temp_r5_1437->unk4 > 0) {
            var_r6_1459 = *(this->unk58 + var_r27_1434);
        } else {
            var_r6_1459 = this->unk60;
        }
        ((EnemyGeneratorDoor *) (((u8 *) this->unk54) + var_r28_1433))->Init(this, temp_r5_1437->unk10 + (var_r8_1438 * 0x24), var_r6_1459, var_r7_1439);
        if ((s32) this->unk80 == 0) {
            sp80 = ((EnemyGeneratorDoor *) (((u8 *) this->unk54) + var_r28_1433))->GetSpawnPos();
            *(MKVector3 *) &spB0 = sp80;
            sp70 = ((EnemyGeneratorDoor *) (((u8 *) this->unk54) + var_r28_1433))->GetDoorPos();
            temp_f1_1486 = M2C_BITWISE(f64, sp70);
            spA0 = temp_f1_1486;
            spA8 = (f64) sp70.unk8;
            temp_f0_1492 = temp_f1_1486 - spB0;
            sp40 = temp_f0_1492;
            sp30 = temp_f0_1492;
            var_f6_1498 = 0.0f;
            (*(f32 *) ((u8 *) &sp30 + 0x4)) = 0.0f;
            sp48 = (f32) spA8 - (f32) spB8;
            sp60 = sp30;
            sp68 = (f64) sp48;
            sp38 = (f64) sp48;
            var_f4_1515 = ((f32) sp68 * (f32) sp68) + (((f32) sp60 * (f32) sp60) + ((*(f32 *) ((u8 *) &sp60 + 0x4)) * (*(f32 *) ((u8 *) &sp60 + 0x4))));
            if (var_f4_1515 > 1e-12f) {
                if (var_f4_1515 > 0.0f) {
                    temp_f1_1520 = __frsqrte(var_f4_1515);
                    temp_f1_1526 = 0.5 * temp_f1_1520 * -(((f64) var_f4_1515 * (temp_f1_1520 * temp_f1_1520)) - 3.0);
                    temp_f1_1530 = 0.5 * temp_f1_1526 * -(((f64) var_f4_1515 * (temp_f1_1526 * temp_f1_1526)) - 3.0);
                    var_f4_1515 = (f32) ((f64) var_f4_1515 * (0.5 * temp_f1_1530 * -(((f64) var_f4_1515 * (temp_f1_1530 * temp_f1_1530)) - 3.0)));
                } else if (var_f4_1515 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_1515 = __float_nan;
                } else {
                    sp8 = var_f4_1515;
                    temp_r3_1549 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                    switch (temp_r3_1549) {         /* irregular */
                    case 0x7F800000:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_1559 = 1;
                        } else {
                            var_r0_1559 = 2;
                        }
                        break;
                    case 0x0:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_1559 = 5;
                        } else {
                            var_r0_1559 = 3;
                        }
                        break;
                    default:
                        var_r0_1559 = 4;
                        break;
                    }
                    if (var_r0_1559 == 1) {
                        var_f4_1515 = __float_nan;
                    }
                }
                var_f6_1498 = 1.0f / var_f4_1515;
            }
            temp_r0_1584 = var_r28_1433 + 0x18;
            temp_r5_1592 = *(this->unk54 + temp_r0_1584);
            M2C_FIELD(temp_r5_1592, f32 *, 0x40) = (f32) spB0;
            sp28 = (f32) sp68 * var_f6_1498;
            M2C_FIELD(temp_r5_1592, f32 *, 0x44) = (*(f32 *) ((u8 *) &spB0 + 0x4));
            M2C_FIELD(temp_r5_1592, f32 *, 0x48) = (f32) spB8;
            sp98 = (f64) sp28;
            M2C_FIELD(temp_r5_1592, f32 *, 0x4C) = 1.0f;
            sp20 = (f32) sp60 * var_f6_1498;
            temp_r4_1612 = *(this->unk54 + temp_r0_1584);
            sp24 = (*(f32 *) ((u8 *) &sp60 + 0x4)) * var_f6_1498;
            sp90 = (f64) sp20;
            M2C_FIELD(temp_r4_1612, f32 *, 0x30) = (f32) sp90;
            M2C_FIELD(temp_r4_1612, f32 *, 0x34) = (*(f32 *) ((u8 *) &sp90 + 0x4));
            M2C_FIELD(temp_r4_1612, f32 *, 0x38) = (f32) sp98;
            M2C_FIELD(temp_r4_1612, f32 *, 0x3C) = 0.0f;
            sp18 = (MKVector3::up.unk0 * (*(f32 *) ((u8 *) &sp90 + 0x4))) - (MKVector3::up.unk4 * (f32) sp90);
            sp10 = (MKVector3::up.unk4 * (f32) sp98) - (MKVector3::up.unk8 * (*(f32 *) ((u8 *) &sp90 + 0x4)));
            temp_r4_1633 = *(this->unk54 + temp_r0_1584);
            sp14 = (MKVector3::up.unk8 * (f32) sp90) - (MKVector3::up.unk0 * (f32) sp98);
            sp58 = (f64) sp18;
            sp50 = (f64) sp10;
            M2C_FIELD(temp_r4_1633, f32 *, 0x10) = (f32) sp50;
            M2C_FIELD(temp_r4_1633, f32 *, 0x14) = (*(f32 *) ((u8 *) &sp50 + 0x4));
            M2C_FIELD(temp_r4_1633, f32 *, 0x18) = (f32) sp58;
            M2C_FIELD(temp_r4_1633, f32 *, 0x1C) = 0.0f;
            AddSpawnPoint(*(this->unk54 + temp_r0_1584));
        }
        var_r30_1431 += 1;
        var_r28_1433 += 0x30;
        var_r27_1434 += 4;
        goto loop_54;
    }
    AddSpawnPointEnd();
    SetDefaults();
    this->unk4C = (this->unk4C & ~0x10) | ((this->unk50->unk18 << 4) & 0x10);
    if (((u8) this->unk84 == 0) || (((MKProp *) this->unk60 != NULL) && (M2C_FIELD(*gMK, u8 (**)(void **, s32), 0x9C)(gMK, *MKResource::sWorkingChunkID) == 0))) {
        FunctionOff();
    }
}
#endif

#if 0 // DRAFT: function call 'LoadDone(EnemyGenerator *, int, int, unsigned int, unsigned long)' does not match 'EnemyGenerator::LoadDone()'
void EnemyGenerator::LoadDone() {
    MKProp *temp_r4_1696;
    s32 var_r7_1699;

    temp_r4_1696 = this->unk60;
    if (temp_r4_1696 != NULL) {
        var_r7_1699 = temp_r4_1696->unk18;
    } else {
        var_r7_1699 = 1;
    }
    LoadDone(0, 0xA, 0U, (u32) var_r7_1699);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to 'bool *' Too many errors printed, aborting program
s32 EnemyGenerator::LoadLine(MKIniLine *arg0) {
    s32 var_r27_1724;
    s32 var_r27_1752;
    s32 var_r31_1726;
    s32 var_r31_1754;
    s32 var_r31_1781;

    var_r27_1724 = 0;
    var_r31_1726 = 0;
loop_4:
    if (var_r27_1724 >= (s32) this->unk50->unk4) {
        var_r27_1752 = 0;
        var_r31_1754 = 0;
loop_9:
        if (var_r27_1752 >= (s32) this->unk50->unk0) {
            var_r31_1781 = 0;
            if ((SpawnerObject::LoadLine(arg0) != 0) || (arg0->LoadInt("iEnemyWaveStart", (int *) &this->unk74, 0) != 0) || (arg0->LoadInt("iEnemyWaveEnd", (int *) &this->unk78, 0) != 0) || (arg0->LoadBool("bActive", &this->unk84, 0) != 0) || (this->unk68.LoadLine(arg0, "OnEnemyWaveComplete") != 0) || (this->unk6C.LoadLine(arg0, "OnAllEnemyWavesComplete") != 0)) {
                var_r31_1781 = 1;
            }
            return var_r31_1781;
        }
        if (arg0->LoadInt(Str_Printf("spawnPointID%d", var_r27_1752 + 1), ((u8 *) this->unk5C) + var_r31_1754, 0) != 0) {
            return 1;
        }
        var_r27_1752 += 1;
        var_r31_1754 += 4;
        goto loop_9;
    }
    if (arg0->LoadInt(Str_Printf("doorID%d", var_r27_1724 + 1), ((u8 *) this->unk58) + var_r31_1726, 0) != 0) {
        return 1;
    }
    var_r27_1724 += 1;
    var_r31_1726 += 4;
    goto loop_4;
}
#endif

void EnemyGenerator::Deinit() {
    s32 var_r30_1853;
    s32 var_r31_1854;
    void *temp_r31_1866;
    void *temp_r31_1880;
    void *temp_r31_1896;

    RemoveAllSpawnPoints(0U);
    if ((void *) this->unk54 != NULL) {
        var_r30_1853 = 0;
        var_r31_1854 = 0;
loop_3:
        if (var_r30_1853 < (s32) this->unk70) {
            ((EnemyGeneratorDoor *) (((u8 *) this->unk54) + var_r31_1854))->Deinit();
            var_r30_1853 += 1;
            var_r31_1854 += 0x30;
            goto loop_3;
        }
        temp_r31_1866 = this->unk54;
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_1866, NULL, 0);
        } else {
            free(temp_r31_1866);
        }
    }
    temp_r31_1880 = this->unk58;
    if (temp_r31_1880 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_1880, NULL, 0);
        } else {
            free(temp_r31_1880);
        }
    }
    temp_r31_1896 = this->unk5C;
    if (temp_r31_1896 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_1896, NULL, 0);
        } else {
            free(temp_r31_1896);
        }
    }
    Deinit();
}

#if 0 // DRAFT: undefined identifier 'EnemySpawnPool_Action'
void EnemyGenerator::Init(EnemyGeneratorDescriptor *arg0, MKProp *arg1) {
    EnemyGeneratorDescriptor *temp_r3_1956;
    s32 temp_r0_1958;
    s32 temp_r0_1964;
    s32 temp_r0_1989;
    s32 temp_r0_2015;
    s32 temp_r30_1967;
    s32 temp_r30_1992;
    s32 temp_r30_2018;
    s32 var_r4_1957;
    void *var_r3_1975;
    void *var_r3_2000;
    void *var_r3_2026;

    Init(EnemySpawnPool_Action, 1);
    this->unk50 = arg0;
    this->unk54 = NULL;
    this->unk58 = NULL;
    this->unk5C = NULL;
    this->unk60 = arg1;
    this->unk68.Init();
    this->unk6C.Init();
    this->unk7C = 0;
    this->unk74 = 0;
    this->unk78 = this->unk50->unkC;
    this->unk85 = this->unk50->unk19;
    this->unk80 = 0;
    temp_r3_1956 = this->unk50;
    var_r4_1957 = temp_r3_1956->unk0;
    temp_r0_1958 = temp_r3_1956->unk8;
    if (temp_r0_1958 > var_r4_1957) {
        var_r4_1957 = temp_r0_1958;
    }
    this->unk70 = var_r4_1957;
    temp_r0_1964 = this->unk70;
    if (temp_r0_1964 > 0) {
        temp_r30_1967 = temp_r0_1964 * 0x30;
        if (MKHeap::Current() != NULL) {
            var_r3_1975 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r30_1967, NULL, 0);
        } else {
            var_r3_1975 = malloc(temp_r30_1967);
        }
        this->unk54 = var_r3_1975;
        memset(this->unk54, 0, this->unk70 * 0x30);
    }
    temp_r0_1989 = this->unk50->unk4;
    if (temp_r0_1989 > 0) {
        temp_r30_1992 = temp_r0_1989 * 4;
        if (MKHeap::Current() != NULL) {
            var_r3_2000 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r30_1992, NULL, 0);
        } else {
            var_r3_2000 = malloc(temp_r30_1992);
        }
        this->unk58 = var_r3_2000;
        memset(this->unk58, 0, this->unk50->unk4 * 4);
    }
    temp_r0_2015 = this->unk50->unk0;
    if (temp_r0_2015 > 0) {
        temp_r30_2018 = temp_r0_2015 * 4;
        if (MKHeap::Current() != NULL) {
            var_r3_2026 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r30_2018, NULL, 0);
        } else {
            var_r3_2026 = malloc(temp_r30_2018);
        }
        this->unk5C = var_r3_2026;
        memset(this->unk5C, 0, this->unk50->unk0 * 4);
    }
}
#endif
