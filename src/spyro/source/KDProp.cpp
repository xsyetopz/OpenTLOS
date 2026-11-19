#include "spyro/source/KDProp.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionManager.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "spyro/source/KDSynkerPlayer2Messages.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

s32 stricmp(s8 *);                                  /* extern */
extern void **gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
#if 0 // DRAFT: identifier 'gUpdateCameraAlpha' redeclared
static M2C_UNK modInfo;                             /* unable to generate initializer: unknown type */
static u8 gUpdateCameraAlpha = 1;
#endif

#if 0 // DRAFT: function call 'stricmp(const char *)' does not match
u8 KDProp_LoadMaterialID(MKIniLine *arg0, const char *arg1, int *arg2) {
    s32 temp_r3_25;
    s32 temp_r3_39;
    s32 var_r31_32;

    arg0->GetFieldName();
    if (stricmp(arg1) == 0) {
        temp_r3_25 = arg0->GetInt(0);
        if (temp_r3_25 != 0) {
            *arg2 = temp_r3_25;
        } else {
            var_r31_32 = 0;
            *arg2 = 0;
loop_5:
            if (var_r31_32 < (s16) arg0->unk0) {
                temp_r3_39 = MKMaterial_GetMaterialIDMask(arg0->GetString(var_r31_32));
                var_r31_32 += 1;
                *arg2 |= temp_r3_39;
                goto loop_5;
            }
        }
        return 1U;
    }
    return 0U;
}
#endif

#if 0 // DRAFT: ')' expected
void KDProp::UpdateCameraAlpha() {
    f32 temp_f0_91;
    f32 temp_f2_81;
    f32 var_f1_89;

    if (!(((u8) this->unk88 >> 7U) & 1) && ((u8) M2C_FIELD(checked_cast<KDPropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), u8 *, 0x6C) != 0) && ((u8) gUpdateCameraAlpha != 0)) {
        temp_f2_81 = this->unk84;
        if (temp_f2_81 != 1.0f) {
            var_f1_89 = (1.5f * gUpdateTimeDelta) + temp_f2_81;
            temp_f0_91 = *M2C_FIELD(&modInfo, f32 **, 0xC);
            if (var_f1_89 < 1.0f) {

            } else {
                var_f1_89 = 1.0f;
            }
            if (var_f1_89 > temp_f0_91) {

            } else {
                var_f1_89 = temp_f0_91;
            }
            this->unk84 = var_f1_89;
            if (this->unk84 == 1.0f) {
                this->unk10 = (this->unk10 & ~0x4004) | (M2C_FIELD(this->unk0, s32 *, 0x14) & 0x4004);
            }
        }
    }
}
#endif

void KDProp::AddCollisionSubObject(int arg0, MKCollisionInfo *arg1) {
    M2C_UNK var_r31_139;
    void *temp_r30_138;

    temp_r30_138 = checked_cast<KDPropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    var_r31_139 = 2;
    if (!(this->unk10 & 3)) {
        var_r31_139 = 1;
    }
    ((MKCollisionManager *) (M2C_FIELD(*gMK, MKCollisionManager *(**)(void **), 0x84)(gMK)))->AddModel(this->unk4, arg0, (MKCollisionMode) var_r31_139, arg1, M2C_FIELD(temp_r30_138, u32 *, 0x64));
    arg1->unk4 = 1;
}

#if 0 // DRAFT: ')' expected
void KDProp::SetColorToGround() {
    MKCollisionResult spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    MKVector3 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    M2C_UNK sp50;
    M2C_UNK sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f64 sp20;
    f64 sp18;
    f64 sp10;
    u8 spC;
    MKCollisionInfo *sp8;
    MKCollisionInfo *temp_r4_181;
    f64 temp_f0_211;
    f64 temp_f0_249;
    void *temp_r3_199;

    this->unk88 &= ~0x40;
    if (M2C_FIELD(checked_cast<KDPropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x60) & 1) {
        temp_r4_181 = &this->unk70;
        sp8 = temp_r4_181;
        if (temp_r4_181 != NULL) {
            spC = this->unk70.unk4;
            this->unk70.unk4 = 0;
        }
        sp38 = 0.0f;
        sp30 = 0.0f;
        sp34 = 10000.0f;
        spA8 = (f64) sp38;
        spA0 = (f64) sp30;
        temp_r3_199 = MKModel_GetWorldMatrix(this->unk4);
        sp90 = M2C_FIELD(temp_r3_199, f64 *, 0x30);
        sp98 = M2C_FIELD(temp_r3_199, f64 *, 0x38);
        MKModel_CalculateCentre(this->unk4, &sp80);
        (*(f32 *) ((u8 *) &sp90 + 0x4)) = sp80.unk4;
        temp_f0_211 = sp90 - spA0;
        sp20 = temp_f0_211;
        sp70 = temp_f0_211;
        sp28 = (f32) sp98 - (f32) spA8;
        sp78 = (f64) sp28;
        if (MKCollision_RayCollide(*((MKVector3 *) &sp90), *((MKVector3 *) &sp70), &spB0, (MKCollisionMode) 4, M2C_FIELD(&modInfo, s32 *, 0)) != 0) {
            if ((u8) M2C_FIELD(&modInfo, u8 *, 0x15) != 0) {
                Tools_GroundColor((MKCollisionResult *) &sp50);
                sp10 = M2C_FIELD(&sp50, f64 *, 0) * this->unk50;
                temp_f0_249 = M2C_FIELD(&sp50, f64 *, 8) * this->unk58;
                sp18 = temp_f0_249;
                sp60 = sp10;
                sp68 = temp_f0_249;
                MKModel_SetColor(this->unk4, *((MKVector4 *) &sp60));
            } else {
                Tools_GroundColor((MKCollisionResult *) &sp40);
                MKModel_SetColor(this->unk4, *((MKVector4 *) &sp40));
            }
        } else {
            this->unk88 |= 0x40;
        }
        if (sp8 != NULL) {
            sp8->unk4 = spC;
        }
    }
}
#endif

void KDProp::Deinit() {
    MKAnimScript *temp_r3_294;
    MKModel *temp_r3_302;

    temp_r3_294 = this->unk80;
    if (temp_r3_294 != NULL) {
        temp_r3_294->Destroy();
        this->unk4 = NULL;
    } else {
        temp_r3_302 = this->unk4;
        if (temp_r3_302 != NULL) {
            MKModel_Destroy(temp_r3_302);
            this->unk4 = NULL;
        }
    }
    MKProp::Deinit();
}

void KDProp::Disable() {
    this->unk18 |= 0x80000000;
    this->unk70.unk4 = 0;
}

void KDProp::Enable() {
    this->unk18 &= 0x7FFFFFFF;
    this->unk70.unk4 = 1;
}

#if 0 // DRAFT: undefined identifier 'modInfo'
void KDProp::Draw() {
    f32 temp_f0_385;
    f32 var_f1_398;
    f32 var_f2_378;
    u8 var_r31_353;
    u8 var_r3_356;
    void *temp_r3_371;

    MKProp::Draw();
    if ((MKModel *) this->unk4 != NULL) {
        var_r31_353 = 0;
        var_r3_356 = 0;
        if ((((u8) M2C_FIELD(&modInfo, u8 *, 0x14) != 0) || ((MKAnimScript *) this->unk80 == NULL)) && (this->unk10 & 0x8000)) {
            var_r3_356 = 1;
        }
        if (var_r3_356 != 0) {
            temp_r3_371 = checked_cast<KDPropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            if ((void **) M2C_FIELD(&modInfo, void ***, 0x10) != NULL) {
                var_f2_378 = M2C_FIELD(*M2C_FIELD(&modInfo, void ***, 0x10), f32 *, 4);
            } else {
                var_f2_378 = 1.0f;
            }
            temp_f0_385 = var_f2_378 * M2C_FIELD(temp_r3_371, f32 *, 0x20);
            if (this->unk24 < (temp_f0_385 * temp_f0_385)) {
                var_r31_353 = 1;
            }
        }
        MKModel_EnableScissoring(this->unk4, var_r31_353);
        if (((u8) this->unk88 >> 7U) & 1) {
            var_f1_398 = 1.0f;
        } else {
            var_f1_398 = this->unk20 * this->unk84;
        }
        MKModel_SetAlpha(this->unk4, var_f1_398);
        MKModel_Draw(this->unk4, NULL);
    }
}
#endif

void KDProp::Update() {
    MKAnimScript *temp_r3_426;

    MKProp::Update();
    temp_r3_426 = this->unk80;
    if ((temp_r3_426 != NULL) && ((u32) temp_r3_426->unk20 != 0)) {
        this->unk80->Animate(MKModel_GetAnimation(temp_r3_426->unk8), -1, NULL);
    }
    UpdateCameraAlpha();
}

#if 0 // DRAFT: undefined identifier 'KDS_Message_PropGetCollisionColor'
void KDProp::Message(MKMessage *arg0) {
    KDS_Message_PropResolve *temp_r3_472;
    MKAnimScript *temp_r5_476;
    f32 temp_f2_510;
    f32 var_f0_511;
    s32 temp_r0_459;
    void *temp_r3_492;

    MKProp::Message(arg0);
    temp_r0_459 = arg0->unk0;
    switch (temp_r0_459) {                          /* irregular */
    case 0x802:
        temp_r3_472 = checked_cast<KDS_Message_PropResolve *, MKMessage>(arg0);
        if ((u32) temp_r3_472->unk8 == 0U) {
            temp_r5_476 = this->unk80;
            if (temp_r5_476 != NULL) {
                temp_r3_472->Set((MKProp *) this, temp_r5_476);
                return;
            }
            temp_r3_472->Set((MKProp *) this, this->unk4);
            return;
        }
        return;
    case 0x808:
        if (((u8) this->unk88 >> 5U) & 1) {
            temp_r3_492 = checked_cast<KDS_Message_PropGetCollisionColor *, MKMessage>(arg0);
            M2C_FIELD(temp_r3_492, f64 *, 8) = (f64) this->unk60;
            M2C_FIELD(temp_r3_492, f64 *, 0x10) = (f64) this->unk68;
            return;
        }
        break;
    case 0x422:
        if (!(((u8) this->unk88 >> 7U) & 1)) {
            temp_f2_510 = *M2C_FIELD(&modInfo, f32 **, 0xC);
            var_f0_511 = this->unk84 - (3.0f * gUpdateTimeDelta);
            if (var_f0_511 < 1.0f) {

            } else {
                var_f0_511 = 1.0f;
            }
            if (var_f0_511 > temp_f2_510) {

            } else {
                var_f0_511 = temp_f2_510;
            }
            this->unk84 = var_f0_511;
            this->unk10 &= 0xFFFFFFFB;
            this->unk10 |= 0x4000;
        }
        break;
    }
}
#endif

void KDProp::Reset() {
    s32 var_r31_551;

    MKProp::Reset();
    if ((MKModel *) this->unk4 != NULL) {
        var_r31_551 = 0;
loop_3:
        if (var_r31_551 < MKModel_GetNmbrOfSubObjects(this->unk4, (SubObjectType) 2)) {
            ((MKCloth *) (MKModel_GetClothSubObject(this->unk4, var_r31_551)))->Reset();
            var_r31_551 += 1;
            goto loop_3;
        }
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char' to
void KDProp::LoadDone() {
    MKAnim *var_r3_627;
    MKAnim *var_r3_647;
    MKAnim *var_r4_633;
    MKAnimScript *temp_r29_619;
    MKAnimScript *temp_r29_635;
    MKAnimScript *temp_r3_586;
    MKHeap *var_r0_695;
    MKHeap *var_r3_690;
    MKModel *temp_r3_678;
    MKModel *temp_r3_715;
    MKResource *var_r3_603;
    f32 temp_f31_742;
    f64 *temp_r0_744;
    s32 var_r29_768;
    s32 var_r29_791;
    s8 *var_r29_594;
    void *temp_r3_584;

    temp_r3_584 = checked_cast<KDPropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    temp_r3_586 = M2C_FIELD(temp_r3_584, MKAnimScript **, 0x34);
    if ((temp_r3_586 != NULL) || ((MKResource *) *KDProp::pCustomAnimScrName != NULL)) {
        var_r29_594 = NULL;
        if ((temp_r3_586 != NULL) && ((u32) MKModel_GetAnimation(temp_r3_586->unk8)->unk18 != 0U)) {
            var_r29_594 = (s8 *)1;
        }
        var_r3_603 = *KDProp::pCustomAnimScrName;
        if (var_r3_603 != NULL) {

        } else {
            var_r3_603 = ((MKAnimScript *) (M2C_FIELD(temp_r3_584, MKAnimScript **, 0x34)))->GetName();
        }
        this->unk80 = ((MKAnimScript *) var_r3_603)->Create(var_r29_594, M2C_ERROR(/* Read from unset register $r5 */));
        this->unk4 = this->unk80->unk8;
        temp_r29_619 = this->unk80;
        if (temp_r29_619->Exists("idle01") != 0) {
            var_r3_627 = temp_r29_619->GetAnim("idle01");
        } else {
            var_r3_627 = NULL;
        }
        var_r4_633 = var_r3_627;
        if (var_r3_627 == NULL) {
            temp_r29_635 = this->unk80;
            if (temp_r29_635->Exists("idle") != 0) {
                var_r3_647 = temp_r29_635->GetAnim("idle");
            } else {
                var_r3_647 = NULL;
            }
            var_r4_633 = var_r3_647;
        }
        if (var_r4_633 != NULL) {
            this->unk80->SetAnim(var_r4_633, 1.0f, 0.0f, 0, -1);
            if (M2C_FIELD(temp_r3_584, s32 *, 0x60) & 8) {
                this->unk80->JumpToPos(MKRand_Float(&gViewSeed, 0.0f, 1.0f), -1);
            }
        }
        this->unk10 &= 0xFFFFFFFB;
    } else {
        temp_r3_678 = M2C_FIELD(temp_r3_584, MKModel **, 0x2C);
        if ((temp_r3_678 != NULL) || ((MKHeap *) *KDProp::pCustomModelName != NULL)) {
            if (MKModel_GetAnimation(temp_r3_678) != NULL) {
                var_r3_690 = ((Animation *) (MKModel_GetAnimation(M2C_FIELD(temp_r3_584, MKModel **, 0x2C))))->GetName();
            } else {
                var_r3_690 = NULL;
            }
            var_r0_695 = *KDProp::pCustomModelName;
            if (var_r0_695 != NULL) {

            } else {
                var_r0_695 = MKModel_GetName(M2C_FIELD(temp_r3_584, MKModel **, 0x2C));
            }
            this->unk4 = MKModel_Create((s8 *) var_r0_695, (s8 *) var_r3_690, 2, NULL);
        }
    }
    *KDProp::pCustomAnimScrName = NULL;
    *KDProp::pCustomModelName = NULL;
    temp_r3_715 = this->unk4;
    if ((temp_r3_715 != NULL) && ((this->unk8 = MKModel_GetWorldMatrix(temp_r3_715), this->unk50 = M2C_FIELD(&MKProp::loadInfo, f64 *, 0x70), this->unk58 = M2C_FIELD(&MKProp::loadInfo, f64 *, 0x78), (((f32) M2C_FIELD(&MKProp::loadInfo, f64 *, 0x70) == 1.0f) == 0)) || (M2C_FIELD(&MKProp::loadInfo, f32 *, 0x74) != 1.0f) || ((f32) M2C_FIELD(&MKProp::loadInfo, f64 *, 0x78) != 1.0f))) {
        MKModel_SetColor(this->unk4, MKProp::loadInfo + 0x70);
    }
    temp_f31_742 = M2C_FIELD(temp_r3_584, f32 *, 0x68);
    temp_r0_744 = &MKProp::loadInfo + 0x60;
    *temp_r0_744 *= (f64) temp_f31_742;
    M2C_FIELD(&MKProp::loadInfo, f32 *, 0x68) = (f32) (M2C_FIELD(&MKProp::loadInfo, f32 *, 0x68) * temp_f31_742);
    MKProp::LoadDone();
    if (((MKAnimScript *) this->unk80 == NULL) && ((MKModel *) this->unk4 == NULL)) {
        this->unk10 = (this->unk10 & 0xFFFFFFFC) | 2;
        return;
    }
    if (!(this->unk10 & 0x10)) {
        var_r29_768 = 0;
loop_42:
        if (var_r29_768 < MKModel_GetNmbrOfSubObjects(this->unk4, (SubObjectType) 0)) {
            if (MKModel_IsSubObjectPrefixed(this->unk4, (SubObjectType) 0, var_r29_768, 0x43) != 0) {
                AddCollisionSubObject(var_r29_768, &this->unk70);
            }
            var_r29_768 += 1;
            goto loop_42;
        }
    }
    var_r29_791 = 0;
loop_49:
    if (var_r29_791 < MKModel_GetNmbrOfSubObjects(this->unk4, (SubObjectType) 0)) {
        if ((MKModel_IsSubObjectPrefixed(this->unk4, (SubObjectType) 0, var_r29_791, 0x46) != 0) || (MKModel_IsSubObjectPrefixed(this->unk4, (SubObjectType) 0, var_r29_791, 0x43) != 0) || (MKModel_IsSubObjectPrefixed(this->unk4, (SubObjectType) 0, var_r29_791, 0x4C) != 0)) {
            MKModel_EnableSubObject(this->unk4, (SubObjectType) 0, var_r29_791, 0U, 1U);
        }
        var_r29_791 += 1;
        goto loop_49;
    }
    SetColorToGround();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to
s32 KDProp::LoadLine(MKIniLine *arg0) {
    u8 sp8;

    if (MKProp::LoadLine(arg0) != 0) {
        return 1;
    }
    if (arg0->LoadBool("bDrawAtFullAlpha", &sp8, 0) != 0) {
        this->unk88 = (this->unk88 & ~0x80) | ((sp8 << 7) & 0x80);
        return 1;
    }
    if (arg0->LoadBool("bUseCollisionColor", &sp8, 0) != 0) {
        this->unk88 = (this->unk88 & ~0x20) | ((sp8 << 5) & 0x20);
        return 1;
    }
    return arg0->LoadVector4("collisionColor", (MKVector4 *) &this->unk60, 0);
}
#endif

void KDProp::Init() {
    MKProp::Init();
    this->unk70.unk0 = 0;
    this->unk70.unk4 = 1;
    this->unk70.unk8 = (MKProp *) this;
    this->unk70.unkC = 0;
    this->unk10 &= 0xFFFFFFEF;
    this->unk80 = NULL;
    this->unk20 = 1.0f;
    this->unk84 = 1.0f;
    this->unk88 &= ~0x80;
    this->unk88 &= ~0x20;
}

void KDPropDescriptor::Deinit() {
    MKPropDescriptor::Deinit();
}

void KDPropDescriptor::LoadDone() {
    MKPropDescriptor::LoadDone();
}

#if 0 // DRAFT: function call 'KDProp_LoadMaterialID(MKIniLine *, const char[11], long *)'
s32 KDPropDescriptor::LoadLine(MKIniLine *arg0) {
    u8 sp8;

    if ((MKPropDescriptor::LoadLine(arg0) != 0) || (arg0->LoadFloat("defaultScale", &this->unk68, 0) != 0) || (KDProp_LoadMaterialID(arg0, "materialID", &this->unk64) != 0)) {
        return 1U;
    }
    if (arg0->LoadBool("bUseGroundColor", &sp8, 0) != 0) {
        if (sp8 != 0) {
            this->unk60 |= 1;
        } else {
            this->unk60 &= 0xFFFFFFFE;
        }
        return 1U;
    }
    if (arg0->LoadBool("bInteractive", &sp8, 0) != 0) {
        if (sp8 != 0) {
            this->unk60 |= 4;
        } else {
            this->unk60 &= 0xFFFFFFFB;
        }
        return 1U;
    }
    if (arg0->LoadBool("bRandomAnimOffset", &sp8, 0) != 0) {
        if (sp8 != 0) {
            this->unk60 |= 8;
        } else {
            this->unk60 &= 0xFFFFFFF7;
        }
        return 1U;
    }
    return (u8) (arg0->LoadBool("bUpdateCameraAlpha", &this->unk6C, 0) != 0);
}
#endif

void KDPropDescriptor::Init() {
    MKPropDescriptor::Init();
    this->unk60 = 5;
    this->unk64 = 0;
    this->unk68 = 1.0f;
    this->unk6C = 1;
}

#if 0 // DRAFT: undefined identifier 'modInfo'
void KDProp_InitModule(KDPropModuleInfo *arg0) {
    M2C_FIELD(&modInfo, s32 *, 0) = (s32) arg0->unk0;
    M2C_FIELD(&modInfo, s32 *, 4) = (s32) arg0->unk4;
    M2C_FIELD(&modInfo, s32 *, 8) = (s32) arg0->unk8;
    M2C_FIELD(&modInfo, s32 *, 0xC) = (s32) arg0->unkC;
    M2C_FIELD(&modInfo, s32 *, 0x10) = (s32) arg0->unk10;
    M2C_FIELD(&modInfo, u8 *, 0x14) = (u8) arg0->unk14;
    M2C_FIELD(&modInfo, u8 *, 0x15) = (u8) arg0->unk15;
}
#endif
