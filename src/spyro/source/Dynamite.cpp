#include "spyro/source/Dynamite.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionItem.h"
#include "common/Source/MKCollisionManager.h"
#include "common/Source/MKCollisionModel.h"
#include "common/Source/MKCollisionUtil.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKPtrList.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
#include "spyro/source/DynamiteExplosion.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/InputModifier.h"
#include "spyro/source/KDCamera.h"
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDPositionProperty.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/Level.h"
#include "spyro/source/MeleeAttackHitMsg.h"
#include "spyro/source/NodeLookAt.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Projectile.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/SparksPS.h"
#include "spyro/source/Spyro.h"
#include "spyro/source/SpyroCombatState.h"
#include "spyro/source/SpyroState.h"
#include "spyro/source/SpyroTools.h"
#include "spyro/source/SpyroUtils.h"
#include "spyro/source/TargetManager.h"
#include "spyro/source/Tools.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "spyro/source/DataMap.h"
#include "unplaced_inlines.h"
#include <m2c_macros.h>

extern DataMap ElementTypeDataMap;
extern s32 GS_TNTBounce;
extern s32 GS_TNTFuseLP;
extern s32 GS_TNTKickAway;
extern void **gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;
extern MKPropDescriptor *pEarthDynamiteDescriptor;
extern MKPropDescriptor *pElecDynamiteDescriptor;
extern MKPropDescriptor *pFireDynamiteDescriptor;
extern MKPropDescriptor *pIceDynamiteDescriptor;

void Dynamite::Disable() {
    PlatformDetach();
    this->unk188.unk4 = 0;
    Projectile::Disable();
}

void Dynamite::PlatformDetach() {
    s32 sp18;
    s8 sp14;
    u8 *sp10;
    s32 spC;
    s32 sp8;
    MKProp *temp_r3_93;

    temp_r3_93 = this->unk164;
    if (temp_r3_93 != NULL) {
        spC = 0;
        sp8 = 0x24;
        sp10 = &this->unk154;
        sp14 = 0;
        sp18 = 0;
        temp_r3_93->Message((MKMessage *) &sp8);
        this->unk164 = NULL;
    }
}

void Dynamite::PlatformAttach(MKProp *arg0, MKCollisionInfo *arg1) {
    MKCollisionInfo *sp18;
    u8 sp14;
    u8 *sp10;
    s32 spC;
    s32 sp8;
    MKProp *temp_r3_135;

    PlatformDetach();
    if (M2C_FIELD(arg0->unk0, s32 *, 0xC) & 0x4000) {
        this->unk164 = arg0;
        temp_r3_135 = this->unk164;
        if (temp_r3_135 != NULL) {
            spC = 0;
            sp8 = 0x23;
            sp10 = &this->unk154;
            sp14 = 0;
            sp18 = arg1;
            temp_r3_135->Message((MKMessage *) &sp8);
            if (sp14 == 0) {
                this->unk164 = NULL;
            }
        }
    }
}

void Dynamite::Collided(MKCollisionResult &arg0) {
    MKVector3 sp58;
    f32 unk14;
    f32 unk18;
    f32 temp_f28;
    f32 temp_f30;

    unk14 = M2C_FIELD(&arg0, f32 *, 0x14);
    if ((this->unk185 == 0) || !((f32) __fabsf(unk14) <= 0.25f)) {
        Projectile::Collided(arg0);
        if (((u8) this->unk184 >> 7U) & 1) {
            this->unk14C &= ~0x40;
            return;
        }
        unk18 = M2C_FIELD(&arg0, f32 *, 0x18);
        temp_f28 = (M2C_FIELD(this, f32 *, 0xD0) * unk18) + ((M2C_FIELD(this, f32 *, 0xC8) * M2C_FIELD(&arg0, f32 *, 0x10)) + (M2C_FIELD(this, f32 *, 0xCC) * unk14));
        if (temp_f28 < 0.0f) {
            sp58.unk0 = M2C_FIELD(&arg0, f32 *, 0x0) + (M2C_FIELD(&arg0, f32 *, 0x10) * 10.0f);
            sp58.unk4 = M2C_FIELD(&arg0, f32 *, 0x4) + (unk14 * 10.0f);
            sp58.unk8 = M2C_FIELD(&arg0, f32 *, 0x8) + (unk18 * 10.0f);
            MKModel_SetPosition(this->unk4, sp58);
            temp_f30 = 2.0f * temp_f28;
            M2C_FIELD(this, f32 *, 0xC8) = M2C_FIELD(this, f32 *, 0xC8) - (M2C_FIELD(&arg0, f32 *, 0x10) * temp_f30);
            M2C_FIELD(this, f32 *, 0xCC) = M2C_FIELD(this, f32 *, 0xCC) - (unk14 * temp_f30);
            M2C_FIELD(this, f32 *, 0xD0) = M2C_FIELD(this, f32 *, 0xD0) - (unk18 * temp_f30);
            M2C_FIELD(this, f32 *, 0xC8) = M2C_FIELD(this, f32 *, 0xC8) * 0.5f;
            M2C_FIELD(this, f32 *, 0xCC) = M2C_FIELD(this, f32 *, 0xCC) * 0.5f;
            M2C_FIELD(this, f32 *, 0xD0) = M2C_FIELD(this, f32 *, 0xD0) * 0.5f;
            this->unk170 = 0.75f * -this->unk170;
            this->unk180 += 1;
            KDSound_Play3d(GS_TNTBounce, (const MKVector3 *) (((u8 *) this->unk8) + 0x30), M2C_FIELD(&arg0, u32 *, 0x44), -1, 0.0f, false);
        }
    }
}

void Dynamite::SetExplodeNearHero(bool arg0, float arg1) {
    this->unk184 = (this->unk184 & ~0x40) | ((arg0 << 6) & 0x40);
    this->unk174 = arg1;
}

void Dynamite::SetExplodeOnContact(bool arg0) {
    this->unk184 = (this->unk184 & ~0x80) | ((arg0 << 7) & 0x80);
}

void Dynamite::Deactivate() {
    PlatformDetach();
    GameProp::Deactivate();
    this->unk14C &= ~0x80;
    this->unk184 &= ~0x20;
}

void Dynamite::Activate() {
    GameProp::Activate();
    this->unk184 |= 0x20;
}

#if 0 // DRAFT: illegal type
void *Dynamite::Update() {
    f64 sp200;
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    MKVector3 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    MKVector3 spF8;
    MKVector3 spE8;
    f32 spE0;
    f64 spD8;
    f32 spD0;
    f64 spC8;
    f32 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA0;
    f64 sp98;
    f32 sp90;
    f64 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f64 sp38;
    u8 sp30;
    MKCollisionInfo *sp2C;
    Dynamite *sp28;
    s32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    s32 sp8;
    Dynamite *var_r7_510;
    MKCollisionInfo *temp_r4_384;
    MKProp *var_r30_556;
    f32 temp_f1_718;
    f32 temp_f28_740;
    f32 temp_f29_745;
    f32 temp_f29_887;
    f32 temp_f2_616;
    f32 temp_f30_732;
    f32 temp_f30_892;
    f32 temp_f4_653;
    f32 var_f0_717;
    f32 var_f3_831;
    f32 var_f3_978;
    f32 var_f4_426;
    f32 var_f4_764;
    f32 var_f4_911;
    f64 temp_f0_610;
    f64 temp_f0_849;
    f64 temp_f0_859;
    f64 temp_f0_996;
    f64 temp_f1_403;
    f64 temp_f1_429;
    f64 temp_f1_435;
    f64 temp_f1_439;
    f64 temp_f1_604;
    f64 temp_f1_770;
    f64 temp_f1_776;
    f64 temp_f1_780;
    f64 temp_f1_917;
    f64 temp_f1_923;
    f64 temp_f1_927;
    f64 temp_f2_529;
    s32 temp_r3_458;
    s32 temp_r3_553;
    s32 temp_r3_799;
    s32 temp_r3_946;
    s32 var_r0_468;
    s32 var_r0_809;
    s32 var_r0_956;
    void *temp_r30_598;
    void *temp_r3_402;
    void *temp_r3_603;
    void *temp_r4_392;
    void *temp_r4_595;
    void *temp_r5_525;

    temp_r4_384 = &this->unk188;
    sp2C = temp_r4_384;
    if (temp_r4_384 != NULL) {
        sp30 = this->unk188.unk4;
        this->unk188.unk4 = 0;
    }
    temp_r4_392 = this->unk8;
    sp1F8 = M2C_FIELD(temp_r4_392, f64 *, 0x30);
    sp200 = M2C_FIELD(temp_r4_392, f64 *, 0x38);
    Projectile::Update();
    if ((u8) this->unk185 != 0) {
        temp_r3_402 = this->unk8;
        temp_f1_403 = M2C_FIELD(temp_r3_402, f64 *, 0x30);
        sp1B8 = temp_f1_403;
        sp1C0 = M2C_FIELD(temp_r3_402, f64 *, 0x38);
        spD8 = temp_f1_403 - sp1F8;
        sp1E8 = spD8;
        spE0 = (f32) sp1C0 - (f32) sp200;
        sp1F0 = (f64) spE0;
        var_f4_426 = ((f32) sp1F0 * (f32) sp1F0) + (((f32) sp1E8 * (f32) sp1E8) + ((*(f32 *) ((u8 *) &sp1E8 + 0x4)) * (*(f32 *) ((u8 *) &sp1E8 + 0x4))));
        if (var_f4_426 > 0.0f) {
            temp_f1_429 = __frsqrte(var_f4_426);
            temp_f1_435 = 0.5 * temp_f1_429 * -(((f64) var_f4_426 * (temp_f1_429 * temp_f1_429)) - 3.0);
            temp_f1_439 = 0.5 * temp_f1_435 * -(((f64) var_f4_426 * (temp_f1_435 * temp_f1_435)) - 3.0);
            var_f4_426 = (f32) ((f64) var_f4_426 * (0.5 * temp_f1_439 * -(((f64) var_f4_426 * (temp_f1_439 * temp_f1_439)) - 3.0)));
        } else if (var_f4_426 < M2C_BITWISE(f32, 0.0)) {
            var_f4_426 = __float_nan;
        } else {
            sp18 = var_f4_426;
            temp_r3_458 = M2C_BITWISE(s32, sp18) & 0x7F800000;
            switch (temp_r3_458) {                  /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                    var_r0_468 = 1;
                } else {
                    var_r0_468 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                    var_r0_468 = 5;
                } else {
                    var_r0_468 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_468 = 4;
                break;
            }
            if (var_r0_468 == 1) {
                var_f4_426 = __float_nan;
            }
        }
        this->unk17C += var_f4_426;
        if (this->unk17C >= 300.0f) {
            this->unk185 = 0;
        }
    }
    sp8 = 1;
    if (((u8) this->unk14C >> 7U) & 1) {
        var_r7_510 = this;
    } else {
        var_r7_510 = (Dynamite *) this->unk130;
    }
    ((KDSoundPlayer *) &this->unk150)->Update(GS_TNTFuseLP, 1U, ((u8) this->unk184 >> 5U) & 1, (MKProp *) var_r7_510, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    if (((s32) this->unk180 >= 5) && (((u8) this->unk14C >> 6U) & 1)) {
        temp_r5_525 = this->unk8;
        temp_f2_529 = M2C_FIELD(temp_r5_525, f64 *, 0x30);
        sp28 = NULL;
        sp1D8 = temp_f2_529;
        sp1E0 = M2C_FIELD(temp_r5_525, f64 *, 0x38);
        sp24 = 0x73;
        sp28 = this;
        M2C_FIELD(*gMK, M2C_UNK (**)(void **, s32 *, M2C_UNK, M2C_UNK, f64 *, M2C_UNK, f32, f64), 0x94)(gMK, &sp24, 8, 0, &sp1D8, 1, 500.0f, temp_f2_529);
        this->unk14C &= ~0x40;
        if (((u8) this->unk128 != 0) && (temp_r3_553 = this->unk120, (((u32) temp_r3_553 == 0U) == 0)) && (var_r30_556 = M2C_FIELD(temp_r3_553, MKProp **, 8), ((var_r30_556 == NULL) == 0))) {

        } else {
            var_r30_556 = NULL;
        }
        if ((var_r30_556 != NULL) && (M2C_FIELD(var_r30_556->unk0, s32 *, 0xC) & 0x4000) && (var_r30_556 != (MKProp *) this->unk164)) {
            PlatformDetach();
            PlatformAttach(var_r30_556, (MKCollisionInfo *) this->unk120);
        }
    }
    if (((u8) this->unk14C >> 7U) & 1) {
        if ((((u8) this->unk184 >> 6U) & 1) && ((this->unk168 -= gUpdateTimeDelta, ((this->unk168 <= 0.0f) != 0)) || (temp_r4_595 = this->unk8, temp_r30_598 = ((u8 *) temp_r4_595) + 0x30, temp_r3_603 = M2C_FIELD(M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), void *(**)(void **, void *), 0xC)(M2C_FIELD(&gb, void ***, 0), temp_r4_595), void **, 8), temp_f1_604 = M2C_FIELD(temp_r3_603, f64 *, 0x30), sp198 = temp_f1_604, sp1A0 = M2C_FIELD(temp_r3_603, f64 *, 0x38), temp_f0_610 = temp_f1_604 - M2C_FIELD(temp_r30_598, f64 *, 0), spC8 = temp_f0_610, temp_f2_616 = this->unk174, sp1A8 = temp_f0_610, spD0 = (f32) sp1A0 - M2C_FIELD(temp_r30_598, f32 *, 8), sp1B0 = (f64) spD0, (((((f32) sp1B0 * (f32) sp1B0) + (((f32) sp1A8 * (f32) sp1A8) + ((*(f32 *) ((u8 *) &sp1A8 + 0x4)) * (*(f32 *) ((u8 *) &sp1A8 + 0x4))))) <= (temp_f2_616 * temp_f2_616)) != 0)))) {
            this->unk14C &= ~0x40;
            this->unk168 = 0.0f;
        }
        if (((u8) this->unk14C >> 6U) & 1) {
            spC0 = 0.0f;
            this->unk16C += this->unk170 * gUpdateTimeDelta;
            temp_f4_653 = this->unk170;
            spB8 = 0.0f;
            this->unk170 = -((0.2f * temp_f4_653 * gUpdateTimeDelta) - temp_f4_653);
            spBC = this->unk16C;
            sp190 = (f64) spC0;
            sp188 = (f64) spB8;
            MKModel_SetRotation(this->unk4, *((MKVector3 *) &sp188));
        } else {
            this->unk168 -= gUpdateTimeDelta;
            if (this->unk168 <= 0.0f) {
                this->unk168 = 0.0f;
                this->unk184 &= ~0x20;
                KDSound_Stop((int *) &this->unk150);
                ((DynamiteExplosion *) (M2C_FIELD(&gb, DynamiteExplosion **, 0x2F4)))->Trigger(*(this->unk8 + 0x30), 1.0f, 1U, M2C_FIELD(checked_cast<DynamiteDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xF4), NULL);
                this->unk14C &= ~0x80;
                Disable();
            }
        }
    }
    MKModel_CalculateRefPointWorldPosition(this->unk4, M2C_FIELD(checked_cast<DynamiteDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xF0), &sp1C8);
    if (((u8) this->unk14C >> 7U) & 1) {
        var_f0_717 = this->unk168;
        temp_f1_718 = this->unk178;
        if (var_f0_717 < temp_f1_718) {

        } else {
            var_f0_717 = temp_f1_718;
        }
        if (var_f0_717 > 0.0f) {

        } else {
            var_f0_717 = 0.0f;
        }
        temp_f30_732 = var_f0_717 / temp_f1_718;
        if (temp_f30_732 > 0.1f) {
            temp_f28_740 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
            temp_f29_745 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
            spA8 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
            spAC = temp_f29_745;
            spB0 = temp_f28_740;
            sp148 = (f64) spA8;
            sp150 = (f64) spB0;
            var_f4_764 = ((f32) sp150 * (f32) sp150) + (((f32) sp148 * (f32) sp148) + ((*(f32 *) ((u8 *) &sp148 + 0x4)) * (*(f32 *) ((u8 *) &sp148 + 0x4))));
            if (var_f4_764 > 1e-12f) {
                if (var_f4_764 > 0.0f) {
                    temp_f1_770 = __frsqrte(var_f4_764);
                    temp_f1_776 = 0.5 * temp_f1_770 * -(((f64) var_f4_764 * (temp_f1_770 * temp_f1_770)) - 3.0);
                    temp_f1_780 = 0.5 * temp_f1_776 * -(((f64) var_f4_764 * (temp_f1_776 * temp_f1_776)) - 3.0);
                    var_f4_764 = (f32) ((f64) var_f4_764 * (0.5 * temp_f1_780 * -(((f64) var_f4_764 * (temp_f1_780 * temp_f1_780)) - 3.0)));
                } else if (var_f4_764 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_764 = __float_nan;
                } else {
                    sp14 = var_f4_764;
                    temp_r3_799 = M2C_BITWISE(s32, sp14) & 0x7F800000;
                    switch (temp_r3_799) {          /* switch 2; irregular */
                    case 0x7F800000:                /* switch 2 */
                        if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                            var_r0_809 = 1;
                        } else {
                            var_r0_809 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 2 */
                        if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                            var_r0_809 = 5;
                        } else {
                            var_r0_809 = 3;
                        }
                        break;
                    default:                        /* switch 2 */
                        var_r0_809 = 4;
                        break;
                    }
                    if (var_r0_809 == 1) {
                        var_f4_764 = __float_nan;
                    }
                }
                var_f3_831 = 1.0f / var_f4_764;
            } else {
                var_f3_831 = 0.0f;
            }
            sp7C = (*(f32 *) ((u8 *) &sp148 + 0x4)) * var_f3_831;
            sp78 = (f32) sp148 * var_f3_831;
            sp80 = (f32) sp150 * var_f3_831;
            sp158 = (f64) sp78;
            sp160 = (f64) sp80;
            temp_f0_849 = sp158 * 5.634608575e-315;
            sp98 = temp_f0_849;
            sp168 = temp_f0_849;
            spA0 = (f32) sp160 * 500.0f;
            sp170 = (f64) spA0;
            temp_f0_859 = temp_f0_849 * (f64) temp_f30_732;
            sp88 = temp_f0_859;
            sp178 = temp_f0_859;
            sp90 = (f32) sp170 * temp_f30_732;
            sp180 = (f64) sp90;
            sp20 = temp_f30_732 * MKRand_Float((int *) &gViewSeed, 1.5f, 3.0f);
            ((SparksPS *) (M2C_FIELD(&gb, SparksPS **, 0x84)))->Emit(sp1C8, *((MKVector3 *) &sp178), sp20);
        }
    } else {
        temp_f29_887 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        temp_f30_892 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        sp68 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        sp6C = temp_f30_892;
        sp70 = temp_f29_887;
        sp118 = (f64) sp68;
        sp120 = (f64) sp70;
        var_f4_911 = ((f32) sp120 * (f32) sp120) + (((f32) sp118 * (f32) sp118) + ((*(f32 *) ((u8 *) &sp118 + 0x4)) * (*(f32 *) ((u8 *) &sp118 + 0x4))));
        if (var_f4_911 > 1e-12f) {
            if (var_f4_911 > 0.0f) {
                temp_f1_917 = __frsqrte(var_f4_911);
                temp_f1_923 = 0.5 * temp_f1_917 * -(((f64) var_f4_911 * (temp_f1_917 * temp_f1_917)) - 3.0);
                temp_f1_927 = 0.5 * temp_f1_923 * -(((f64) var_f4_911 * (temp_f1_923 * temp_f1_923)) - 3.0);
                var_f4_911 = (f32) ((f64) var_f4_911 * (0.5 * temp_f1_927 * -(((f64) var_f4_911 * (temp_f1_927 * temp_f1_927)) - 3.0)));
            } else if (var_f4_911 < M2C_BITWISE(f32, 0.0)) {
                var_f4_911 = __float_nan;
            } else {
                sp10 = var_f4_911;
                temp_r3_946 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_946) {              /* switch 3; irregular */
                case 0x7F800000:                    /* switch 3 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_956 = 1;
                    } else {
                        var_r0_956 = 2;
                    }
                    break;
                case 0x0:                           /* switch 3 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_956 = 5;
                    } else {
                        var_r0_956 = 3;
                    }
                    break;
                default:                            /* switch 3 */
                    var_r0_956 = 4;
                    break;
                }
                if (var_r0_956 == 1) {
                    var_f4_911 = __float_nan;
                }
            }
            var_f3_978 = 1.0f / var_f4_911;
        } else {
            var_f3_978 = 0.0f;
        }
        sp4C = (*(f32 *) ((u8 *) &sp118 + 0x4)) * var_f3_978;
        sp48 = (f32) sp118 * var_f3_978;
        sp50 = (f32) sp120 * var_f3_978;
        sp128 = (f64) sp48;
        sp130 = (f64) sp50;
        temp_f0_996 = sp128 * 5.634608575e-315;
        sp58 = temp_f0_996;
        sp138 = temp_f0_996;
        sp60 = (f32) sp130 * 500.0f;
        sp140 = (f64) sp60;
        sp1C = MKRand_Float((int *) &gViewSeed, 1.5f, 3.0f);
        ((SparksPS *) (M2C_FIELD(&gb, SparksPS **, 0x84)))->Emit(sp1C8, *((MKVector3 *) &sp138), sp1C);
    }
    spE8 = MKVector(0.0f, 50.0f, 0.0f);
    spF8 = GetPos();
    sp38 = spF8 + M2C_BITWISE(f64, spE8);
    this->unk198 = sp38;
    sp40 = spF8.unk8 + spE8.unk8;
    sp108 = sp38;
    sp110 = (f64) sp40;
    this->unk1A0 = (f64) sp40;
    if (sp2C != NULL) {
        sp2C->unk4 = sp30;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to 'double'
void Dynamite::SetInitialState() {
    f64 sp40;
    f64 sp38;
    MKVector3 sp28;
    MKVector3 sp18;
    f32 sp10;
    f64 sp8;

    this->unk188.unk4 = 1;
    sp18 = MKVector(0.0f, 50.0f, 0.0f);
    sp28 = GetPos();
    sp8 = sp28 + M2C_BITWISE(f64, sp18);
    this->unk198 = sp8;
    sp10 = sp28.unk8 + sp18.unk8;
    sp38 = sp8;
    this->unk1A0 = (f64) sp10;
    this->unk17C = 0.0f;
    sp40 = (f64) sp10;
    this->unk185 = 1;
}
#endif

s32 Dynamite::LoadDone() {
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;

    Projectile::LoadDone();
    sp8 = 0.0f;
    spC = 1.0f;
    sp10 = 0.0f;
    sp14 = 1.0f;
    sp18 = (f64) sp8;
    sp20 = (f64) sp10;
    ((MKCollisionManager *) (M2C_FIELD(*gMK, MKCollisionManager *(**)(void **, f64, f32), 0x84)(gMK, (f64) sp8, 0.0f)))->AddSphere((MKVector3 *) &this->unk198, 50.0f, 0.0f, *((MKVector4 *) &sp18), (MKCollisionMode) 2, &this->unk188, 0x28000020U);
    this->unk188.unk4 = 0;
}

void Dynamite::Reset() {
    Projectile::Reset();
    this->unk180 = 0;
    this->unk178 = 1.0f;
    this->unk168 = 1.0f;
    this->unk16C = 0.0f;
    this->unk170 = 12.566371f;
    this->unk184 &= ~0x80;
    this->unk184 &= ~0x40;
    this->unk184 |= 0x20;
    this->unk17C = 0.0f;
    PlatformDetach();
}

#if 0 // DRAFT: illegal operand 'Dynamite *'
Dynamite *Dynamite::CreateInstance(int arg0) {
    Dynamite *var_r31_1194;

    var_r31_1194 = NULL;
    switch (this) {                                 /* irregular */
    case 0:
        if ((MKPropDescriptor *) pFireDynamiteDescriptor != NULL) {
            var_r31_1194 = checked_cast<Dynamite *, MKProp>(pFireDynamiteDescriptor->CreateInstance());
        }
        break;
    case 1:
        if ((MKPropDescriptor *) pElecDynamiteDescriptor != NULL) {
            var_r31_1194 = checked_cast<Dynamite *, MKProp>(pElecDynamiteDescriptor->CreateInstance());
        }
        break;
    case 2:
        if ((MKPropDescriptor *) pIceDynamiteDescriptor != NULL) {
            var_r31_1194 = checked_cast<Dynamite *, MKProp>(pIceDynamiteDescriptor->CreateInstance());
        }
        break;
    case 3:
        if ((MKPropDescriptor *) pEarthDynamiteDescriptor != NULL) {
            var_r31_1194 = checked_cast<Dynamite *, MKProp>(pEarthDynamiteDescriptor->CreateInstance());
        }
        break;
    }
    if (var_r31_1194 != NULL) {
        var_r31_1194->Reset();
        var_r31_1194->SetInitialState();
        return var_r31_1194;
    }
    return NULL;
}
#endif

#if 0 // DRAFT: undefined identifier 'PlatformMoveMsg'
void Dynamite::Message(MKMessage *arg0) {
    Matrix spB0;
    M2C_UNK spAC;
    f64 spA0;                                       /* compiler-managed */
    f64 sp98;                                       /* compiler-managed */
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    Dynamite ***temp_r4_1327;
    Dynamite **temp_r3_1349;
    Dynamite **temp_r3_1353;
    Dynamite **var_r3_1330;
    Dynamite *temp_r0_1339;
    f32 temp_f0_1458;
    f32 temp_f1_1484;
    f32 var_f4_1371;
    f32 var_f5_1384;
    f64 temp_f0_1365;
    f64 temp_f0_1478;
    f64 temp_f1_1358;
    f64 temp_f1_1389;
    f64 temp_f1_1395;
    f64 temp_f1_1399;
    f64 temp_f1_1463;
    f64 temp_f3_1471;
    f64 temp_f4_1469;
    s32 temp_r0_1272;
    s32 temp_r3_1418;
    s32 var_r0_1428;
    void *temp_r31_1286;
    void *temp_r3_1307;
    void *temp_r3_1325;
    void *temp_r3_1357;
    void *temp_r3_1466;

    temp_r0_1272 = arg0->unk0;
    switch (temp_r0_1272) {                         /* switch 1; irregular */
    case 34:                                        /* switch 1 */
        temp_r31_1286 = checked_cast<PlatformMoveMsg *, MKMessage>(arg0);
        M2C_STRUCT_COPY((s32) &spAC + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
        spB0.Multiply3x3(&spB0, M2C_FIELD(temp_r31_1286, Matrix **, 0x10));
        spB0.Multiply3x3(&spB0, M2C_FIELD(temp_r31_1286, Matrix **, 0x14));
        temp_r3_1307 = M2C_FIELD(temp_r31_1286, void **, 8);
        spB0.unk30 = M2C_FIELD(temp_r3_1307, f32 *, 0);
        spB0.unk34 = M2C_FIELD(temp_r3_1307, f32 *, 4);
        spB0.unk38 = M2C_FIELD(temp_r3_1307, f32 *, 8);
        spB0.unk3C = 1.0f;
        MKModel_SetWorldMatrix(this->unk4, spB0);
    default:                                        /* switch 1 */
block_39:
        ((KDSoundPlayer *) &this->unk150)->Message(arg0);
        Projectile::Message(arg0);
        break;
    case 38:                                        /* switch 1 */
        PlatformDetach();
        goto block_39;
    case 4:                                         /* switch 1 */
        temp_r3_1325 = checked_cast<MeleeAttackHitMsg *, MKMessage>(arg0);
        temp_r4_1327 = M2C_FIELD(temp_r3_1325, Dynamite ****, 0x34);
        if (temp_r4_1327 != NULL) {
            var_r3_1330 = *temp_r4_1327;
loop_13:
            temp_r0_1339 = *var_r3_1330;
            if (temp_r0_1339 == NULL) {
                var_r3_1330 = NULL;
            } else if (temp_r0_1339 == this) {

            } else {
                var_r3_1330 += 4;
                goto loop_13;
            }
            if (var_r3_1330 == NULL) {
                goto block_16;
            }
        } else {
block_16:
            if (temp_r4_1327 != NULL) {
                temp_r3_1349 = *temp_r4_1327;
                if ((u32) M2C_FIELD(temp_r3_1349, u32 *, -4) != 0U) {
                    temp_r3_1353 = temp_r3_1349 - 4;
                    *temp_r4_1327 = temp_r3_1353;
                    *temp_r3_1353 = this;
                }
            }
            temp_r3_1357 = this->unk8;
            temp_f1_1358 = M2C_FIELD(temp_r3_1357, f64 *, 0x30);
            sp68 = temp_f1_1358;
            sp70 = M2C_FIELD(temp_r3_1357, f64 *, 0x38);
            temp_f0_1365 = temp_f1_1358 - M2C_FIELD(temp_r3_1325, f64 *, 0x10);
            sp38 = temp_f0_1365;
            var_f4_1371 = 0.0f;
            sp98 = temp_f0_1365;
            sp40 = (f32) sp70 - M2C_FIELD(temp_r3_1325, f32 *, 0x18);
            (*(f32 *) ((u8 *) &sp90 + 0xc)) = 0.0f;
            spA0 = (f64) sp40;
            var_f5_1384 = ((f32) spA0 * (f32) spA0) + (((f32) sp98 * (f32) sp98) + (0.0f * 0.0f));
            if (var_f5_1384 > 0.000001f) {
                if (var_f5_1384 > 0.0f) {
                    temp_f1_1389 = __frsqrte(var_f5_1384);
                    temp_f1_1395 = 0.5 * temp_f1_1389 * -(((f64) var_f5_1384 * (temp_f1_1389 * temp_f1_1389)) - 3.0);
                    temp_f1_1399 = 0.5 * temp_f1_1395 * -(((f64) var_f5_1384 * (temp_f1_1395 * temp_f1_1395)) - 3.0);
                    var_f5_1384 = (f32) ((f64) var_f5_1384 * (0.5 * temp_f1_1399 * -(((f64) var_f5_1384 * (temp_f1_1399 * temp_f1_1399)) - 3.0)));
                } else if (var_f5_1384 < M2C_BITWISE(f32, 0.0)) {
                    var_f5_1384 = __float_nan;
                } else {
                    sp10 = var_f5_1384;
                    temp_r3_1418 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                    switch (temp_r3_1418) {         /* switch 2; irregular */
                    case 0x7F800000:                /* switch 2 */
                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                            var_r0_1428 = 1;
                        } else {
                            var_r0_1428 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 2 */
                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                            var_r0_1428 = 5;
                        } else {
                            var_r0_1428 = 3;
                        }
                        break;
                    default:                        /* switch 2 */
                        var_r0_1428 = 4;
                        break;
                    }
                    if (var_r0_1428 == 1) {
                        var_f5_1384 = __float_nan;
                    }
                }
                var_f4_1371 = 1.0f / var_f5_1384;
            }
            temp_f0_1458 = (f32) spA0 * var_f4_1371;
            sp98 = (f32) sp98 * var_f4_1371;
            (*(f32 *) ((u8 *) &sp90 + 0xc)) *= var_f4_1371;
            spA0 = temp_f0_1458;
            temp_f1_1463 = (f64) sp98 * 5.676053805e-315;
            sp28 = temp_f1_1463;
            temp_r3_1466 = this->unk8;
            sp30 = temp_f0_1458 * 1000.0f;
            temp_f4_1469 = M2C_FIELD(temp_r3_1466, f64 *, 0x30);
            temp_f3_1471 = M2C_FIELD(temp_r3_1466, f64 *, 0x38);
            sp48 = temp_f1_1463;
            sp58 = temp_f4_1469;
            sp50 = (f64) sp30;
            sp60 = temp_f3_1471;
            temp_f0_1478 = sp58 + sp48;
            sp18 = temp_f0_1478;
            temp_f1_1484 = (f32) sp60 + (f32) sp50;
            sp78 = temp_f4_1469;
            sp88 = temp_f0_1478;
            sp20 = temp_f1_1484;
            sp80 = temp_f3_1471;
            sp90 = (f64) sp20;
            Reset(temp_f1_1484, (f32) sp60, temp_f3_1471, temp_f4_1469);
            FireAtTarget(sp78, sp88, this->unk130, 0, 0, 1500.0f);
            M2C_FIELD(temp_r3_1325, s8 *, 0x3E) = 1;
            KDSound_Play3d(GS_TNTKickAway, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
            goto block_39;
        }
        break;
    }
}
#endif

void Dynamite::Deinit() {
    KDSound_Stop((int *) &this->unk150);
    PlatformDetach();
    Projectile::Deinit();
}

void Dynamite::Init() {
    Projectile::Init();
    this->unk180 = 0;
    this->unk178 = 1.0f;
    this->unk168 = 1.0f;
    this->unk16C = 0.0f;
    this->unk170 = 12.566371f;
    this->unk184 &= ~0x80;
    this->unk184 &= ~0x40;
    this->unk184 |= 0x20;
    this->unk150 = 0;
    this->unk164 = NULL;
    M2C_FIELD(this, Dynamite **, 0x154) = this;
    M2C_FIELD(this, f32 *, 0x198) = 0.0f;
    M2C_FIELD(this, f32 *, 0x19C) = 0.0f;
    M2C_FIELD(this, f32 *, 0x1A0) = 0.0f;
    this->unk185 = 0;
    this->unk188.unk0 = 0;
    this->unk188.unk4 = 1;
    this->unk188.unk8 = (MKProp *) this;
    this->unk188.unkC = 0;
    this->unk17C = 0.0f;
}

void DynamiteDescriptor::LoadDone() {
    s32 temp_r0_1611;

    GamePropDescriptor::LoadDone();
    temp_r0_1611 = this->unkF4;
    switch (temp_r0_1611) {                         /* irregular */
    case 0:
        pFireDynamiteDescriptor = (MKPropDescriptor *) this;
        break;
    case 1:
        pElecDynamiteDescriptor = (MKPropDescriptor *) this;
        break;
    case 2:
        pIceDynamiteDescriptor = (MKPropDescriptor *) this;
        break;
    case 3:
        pEarthDynamiteDescriptor = (MKPropDescriptor *) this;
        break;
    }
    this->unkF0 = MKModel_GetRefPointIndex(this->unk2C, "r_fxemit0");
}

s32 DynamiteDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_1656;

    var_r31_1656 = 0;
    if ((ProjectileDescriptor::LoadLine(arg0) != 0) || (DataMap_LoadLine(arg0, "Element", &ElementTypeDataMap, (unsigned int *) &this->unkF4) != 0)) {
        var_r31_1656 = 1;
    }
    return var_r31_1656;
}

void DynamiteDescriptor::Deinit() {
    s32 temp_r0_1687;

    temp_r0_1687 = this->unkF4;
    switch (temp_r0_1687) {                         /* irregular */
    case 0:
        pFireDynamiteDescriptor = NULL;
        break;
    case 1:
        pElecDynamiteDescriptor = NULL;
        break;
    case 2:
        pIceDynamiteDescriptor = NULL;
        break;
    case 3:
        pEarthDynamiteDescriptor = NULL;
        break;
    }
    KDPropExDescriptor::Deinit();
}

void DynamiteDescriptor::Init() {
    ProjectileDescriptor::Init();
    this->unkF0 = -1;
    this->unkF4 = 0;
}
