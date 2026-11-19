#include "spyro/source/SiegeTower.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKDynamicBone.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKPtrList.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Ball.h"
#include "spyro/source/Catapult.h"
#include "spyro/source/Crate.h"
#include "spyro/source/EnemyGenerator.h"
#include "spyro/source/EnergyBeam.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/KDFaderObject.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDMatrixRefProperty.h"
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
#include "spyro/source/Projectile.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/SnowballTree.h"
#include "spyro/source/SpawnPointObject.h"
#include "spyro/source/SpawnerObject.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "spyro/source/Tools.h"
#include "unplaced_inlines.h"
#include <m2c_macros.h>

extern s32 GS_SiegeTowerExtra2;
extern s32 GS_SiegeTowerExtra3;
extern MKSceneManager *gMK;
extern f32 gUpdateTimeDelta;
extern M2C_UNK gb;
#if 0 // DRAFT: illegal use of incomplete struct/union/class '_struct_siegeTowerGroups_0x18'
static struct _struct_siegeTowerGroups_0x18 siegeTowerGroups[8];
#endif

#if 0 // DRAFT: illegal type
void SiegeTower::ZapBall(Ball *arg0) {
    f64 sp10;
    f64 sp8;
    f64 temp_f0_133;
    f64 temp_f1_131;
    u32 temp_r4_112;
    void *temp_r3_121;
    void *temp_r3_127;
    void *temp_r3_137;
    void *temp_r3_95;

    temp_r3_95 = this->unk248;
    if (temp_r3_95 != NULL) {
        M2C_FIELD(temp_r3_95, s32 *, 0x130) = 0;
    }
    this->unk248 = (void *) (Projectile::CreateInstance((ProjectileType) 0x11));
    if ((void *) this->unk248 != NULL) {
        this->unk298 = (u32) arg0;
        this->unk290 = 0.5f;
        M2C_FIELD(this->unk248, SiegeTower **, 0x130) = this;
        temp_r4_112 = this->unk324;
        if (temp_r4_112 != -1U) {
            MKModel_CalculateRefPointWorldPosition(this->unk4, (s32) temp_r4_112, &this->unk270);
        } else {
            temp_r3_121 = this->unk8;
            M2C_FIELD(this, f64 *, 0x270) = (f64) M2C_FIELD(temp_r3_121, f64 *, 0x30);
            M2C_FIELD(this, f64 *, 0x278) = (f64) M2C_FIELD(temp_r3_121, f64 *, 0x38);
        }
        temp_r3_127 = arg0->unk8;
        temp_f1_131 = M2C_FIELD(temp_r3_127, f64 *, 0x30);
        temp_f0_133 = M2C_FIELD(temp_r3_127, f64 *, 0x38);
        sp8 = temp_f1_131;
        M2C_FIELD(this, f64 *, 0x280) = temp_f1_131;
        M2C_FIELD(this, f64 *, 0x288) = temp_f0_133;
        temp_r3_137 = this->unk248;
        sp10 = temp_f0_133;
        M2C_FIELD(M2C_FIELD(temp_r3_137, void **, 0x44), M2C_UNK (**)(void *, MKVector3 *, MKVector3 *, M2C_UNK, M2C_UNK, f64), 0x50)(temp_r3_137, &this->unk270, &this->unk280, 0, 0, temp_f1_131);
        KDSound_Play3d(GS_SiegeTowerExtra2, arg0->unk8 + 0x30, 0U, -1, 0.0f, 0U);
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void SiegeTower::Shoot(Targetable *arg0) {
    s8 sp99;
    s8 sp98;
    s32 sp94;
    f32 sp90;
    s32 sp8C;
    s8 sp8A;
    s8 sp89;
    s8 sp88;
    f64 sp80;                                       /* compiler-managed */
    f64 sp78;                                       /* compiler-managed */
    SiegeTower *sp74;
    s32 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    MKProp *sp4C;
    MKProp *sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f64 temp_f1_202;
    u32 temp_r4_183;
    void *temp_r3_192;
    void *temp_r3_210;
    void *temp_r6_198;

    if (((void *) this->unk248 == NULL) && (arg0 != NULL)) {
        this->unk248 = (void *) (Projectile::CreateInstance((ProjectileType) 0x11));
        if ((void *) this->unk248 != NULL) {
            this->unk290 = 2.0f;
            M2C_FIELD(this->unk248, SiegeTower **, 0x130) = this;
            temp_r4_183 = this->unk324;
            if (temp_r4_183 != -1U) {
                MKModel_CalculateRefPointWorldPosition(this->unk4, (s32) temp_r4_183, &this->unk270);
            } else {
                temp_r3_192 = this->unk8;
                M2C_FIELD(this, f64 *, 0x270) = (f64) M2C_FIELD(temp_r3_192, f64 *, 0x30);
                M2C_FIELD(this, f64 *, 0x278) = (f64) M2C_FIELD(temp_r3_192, f64 *, 0x38);
            }
            temp_r6_198 = this->unk8;
            temp_f1_202 = M2C_FIELD(temp_r6_198, f64 *, 0x30);
            sp38 = temp_f1_202;
            sp40 = M2C_FIELD(temp_r6_198, f64 *, 0x38);
            M2C_FIELD(arg0->__vptr, M2C_UNK (**)(Targetable *, f64 *, MKVector3 *, void *, f64), 0x2C)(arg0, &sp38, &this->unk280, temp_r6_198, temp_f1_202);
            temp_r3_210 = this->unk248;
            M2C_FIELD(M2C_FIELD(temp_r3_210, void **, 0x44), M2C_UNK (**)(void *, MKVector3 *, MKVector3 *, M2C_UNK, M2C_UNK), 0x50)(temp_r3_210, &this->unk270, &this->unk280, 0, 0);
            sp10 = 0.0f;
            sp8 = 0.0f;
            spC = 0.0f;
            sp4C = NULL;
            sp28 = (f64) sp8;
            sp30 = (f64) sp10;
            sp48 = (MKProp *)7;
            sp70 = 1;
            sp74 = this;
            sp50 = (f64) sp8;
            sp58 = (f64) sp10;
            sp88 = 1;
            sp94 = 2;
            sp90 = 100.0f;
            sp89 = 0;
            sp8A = 0;
            sp8C = -1;
            sp60 = M2C_FIELD(&MKVector3::one, f64 *, 0);
            sp68 = M2C_FIELD(&MKVector3::one, f64 *, 8);
            sp98 = 0;
            if (this != NULL) {
                ((MKProp *) &sp18)->GetPos();
                sp78 = sp18;
                sp80 = sp20;
            } else {
                sp78 = 0.0f;
                (*(f32 *) ((u8 *) &sp74 + 0x8)) = 0.0f;
                sp80 = 0.0f;
            }
            sp99 = 1;
            M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0->__vptr, void *(**)(Targetable *), 8)(arg0), void **, 0x44), M2C_UNK (**)(MKProp **), 0x2C)(&sp48);
            KDSound_Play3d(GS_SiegeTowerExtra2, M2C_FIELD(M2C_FIELD(arg0->__vptr, void *(**)(Targetable *), 8)(arg0), s32 *, 8) + 0x30, 0U, -1, 0.0f, 0U);
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void SiegeTower::UpdateShooting(Targetable *arg0) {
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    MKVector3 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f64 temp_f0_409;
    f64 temp_f1_359;
    f64 temp_f1_408;
    u32 temp_r3_330;
    u32 temp_r4_340;
    u32 temp_r4_391;
    void *temp_r3_321;
    void *temp_r3_349;
    void *temp_r3_400;
    void *temp_r3_407;
    void *temp_r6_355;

    if ((void *) this->unk248 != NULL) {
        this->unk290 -= gUpdateTimeDelta;
        if (this->unk290 <= 0.0f) {
            temp_r3_321 = this->unk248;
            M2C_FIELD(M2C_FIELD(temp_r3_321, void **, 0x44), M2C_UNK (**)(void *), 0x54)(temp_r3_321);
            M2C_FIELD(this->unk248, s32 *, 0x130) = 0;
            this->unk248 = NULL;
            temp_r3_330 = this->unk298;
            if (temp_r3_330 != 0) {
                ((Ball *) temp_r3_330)->Smash();
                this->unk298 = 0;
            }
        } else {
            if (arg0 != NULL) {
                temp_r4_340 = this->unk324;
                if (temp_r4_340 != -1U) {
                    MKModel_CalculateRefPointWorldPosition(this->unk4, (s32) temp_r4_340, &this->unk270);
                } else {
                    temp_r3_349 = this->unk8;
                    M2C_FIELD(this, f64 *, 0x270) = (f64) M2C_FIELD(temp_r3_349, f64 *, 0x30);
                    M2C_FIELD(this, f64 *, 0x278) = (f64) M2C_FIELD(temp_r3_349, f64 *, 0x38);
                }
                temp_r6_355 = this->unk8;
                temp_f1_359 = M2C_FIELD(temp_r6_355, f64 *, 0x30);
                sp48 = temp_f1_359;
                sp50 = M2C_FIELD(temp_r6_355, f64 *, 0x38);
                M2C_FIELD(arg0->__vptr, M2C_UNK (**)(Targetable *, f64 *, f64 *, void *, f64), 0x2C)(arg0, &sp48, &sp58, temp_r6_355, temp_f1_359);
                sp28 = MKVector(0.0f, 100.0f, 0.0f);
                sp8 = sp58 + M2C_BITWISE(f64, sp28);
                M2C_FIELD(this, f64 *, 0x280) = sp8;
                sp10 = sp60 + sp28.unk8;
                sp38 = sp8;
                sp40 = (f64) sp10;
                M2C_FIELD(this, f64 *, 0x288) = (f64) sp10;
                return;
            }
            if ((u32) this->unk298 != 0) {
                temp_r4_391 = this->unk324;
                if (temp_r4_391 != -1U) {
                    MKModel_CalculateRefPointWorldPosition(this->unk4, (s32) temp_r4_391, &this->unk270);
                } else {
                    temp_r3_400 = this->unk8;
                    M2C_FIELD(this, f64 *, 0x270) = (f64) M2C_FIELD(temp_r3_400, f64 *, 0x30);
                    M2C_FIELD(this, f64 *, 0x278) = (f64) M2C_FIELD(temp_r3_400, f64 *, 0x38);
                }
                temp_r3_407 = M2C_FIELD(this->unk298, void **, 8);
                temp_f1_408 = M2C_FIELD(temp_r3_407, f64 *, 0x30);
                temp_f0_409 = M2C_FIELD(temp_r3_407, f64 *, 0x38);
                sp18 = temp_f1_408;
                M2C_FIELD(this, f64 *, 0x280) = temp_f1_408;
                sp20 = temp_f0_409;
                M2C_FIELD(this, f64 *, 0x288) = temp_f0_409;
            }
        }
    }
}
#endif

void SiegeTower::CalcSpikeBeamPositions() {
    void *temp_r3_431;

    temp_r3_431 = checked_cast<SiegeTowerDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    MKModel_CalculateRefPointWorldPosition(this->unk4, M2C_FIELD(temp_r3_431, s32 *, 0x170), &this->unk250);
    MKModel_CalculateRefPointWorldPosition(this->unk4, M2C_FIELD(temp_r3_431, s32 *, 0x174), &this->unk260);
}

void SiegeTower::FreeElecBeams() {
    EnergyBeam::Beam *temp_r4_458;
    void *temp_r3_457;

    temp_r3_457 = checked_cast<SiegeTowerDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    temp_r4_458 = this->unk24C;
    if (temp_r4_458 != NULL) {
        ((EnergyBeam *) (M2C_FIELD(temp_r3_457, EnergyBeam **, 0x16C)))->FreeEnergyBeam(temp_r4_458);
        this->unk24C = NULL;
    }
}

#if 0 // DRAFT: ')' expected
void SiegeTower::AllocElecBeams() {
    ((EnergyBeam *) (M2C_FIELD(checked_cast<SiegeTowerDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), EnergyBeam **, 0x16C)))->SpawnEnergyBeam(&this->unk250, &this->unk260, 0.25f);
    this->unk24C = M2C_ERROR(/* Read from unset register $r3 */);
}
#endif

#if 0 // DRAFT: undefined identifier 'FindInteractivePropMsg'
void SiegeTower::Message(MKMessage *arg0) {
    s32 temp_r0_510;
    void *temp_r3_535;
    void *temp_r3_544;

    ((KDSoundPlayer *) &this->unk2A0)->Message(arg0);
    ((KDSoundPlayer *) &this->unk2C8)->Message(arg0);
    temp_r0_510 = arg0->unk0;
    if (temp_r0_510 != 0x31) {
        if (temp_r0_510 < 0x31) {
            switch (temp_r0_510) {                  /* irregular */
            case 5:
                break;
            case 21:
                temp_r3_544 = this->unk248;
                if (temp_r3_544 != NULL) {
                    M2C_FIELD(M2C_FIELD(temp_r3_544, void **, 0x44), M2C_UNK (**)(), 0x54)();
                    M2C_FIELD(this->unk248, s32 *, 0x130) = 0;
                    this->unk248 = NULL;
                }
                goto block_17;
            }
        } else if (temp_r0_510 < 0xB4) {
            if (temp_r0_510 != 0x79) {
                goto block_17;
            }
            temp_r3_535 = checked_cast<FindInteractivePropMsg *, MKMessage>(arg0);
            if ((s32) M2C_FIELD(temp_r3_535, s32 *, 8) == 3) {
                M2C_FIELD(temp_r3_535, SiegeTower **, 0xC) = this;
            }
        } else {
            if (temp_r0_510 < 0xB6) {
                this->unk1C0.Message(arg0);
            }
block_17:
            this->unk1C0.Message(arg0);
            Shatterable::Message(arg0);
        }
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to 'double'
void SiegeTower::UpdateTurning(MKVector3 arg0) {
    MKVector3 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;                                       /* compiler-managed */
    f64 sp90;                                       /* compiler-managed */
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    MKVector3 sp60;
    f64 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    f32 temp_f0_709;
    f32 temp_f10_710;
    f32 temp_f2_714;
    f32 temp_f3_717;
    f32 temp_f8_716;
    f32 temp_f9_706;
    f32 var_f11_730;
    f32 var_f2_780;
    f32 var_f4_635;
    f32 var_f7_622;
    f32 var_f7_765;
    f64 temp_f0_616;
    f64 temp_f1_640;
    f64 temp_f1_646;
    f64 temp_f1_650;
    s32 temp_r3_669;
    s32 var_r0_679;
    u32 temp_r4_582;
    u8 var_r0_789;
    void *temp_r5_581;

    temp_r5_581 = this->unk8;
    temp_r4_582 = this->unk324;
    spA0 = M2C_FIELD(temp_r5_581, f64 *, 0x30);
    spA8 = M2C_FIELD(temp_r5_581, f64 *, 0x38);
    if (temp_r4_582 != -1U) {
        MKModel_CalculateRefPointWorldPosition(this->unk4, (s32) temp_r4_582, &spB0);
    } else {
        sp60.operator*(100.0f);
        sp10 = spA0 + M2C_BITWISE(f64, sp60);
        sp70 = sp10;
        sp18 = (f32) spA8 + sp60.unk8;
        spB0 = sp10;
        sp78 = (f64) sp18;
        spB0.unk8 = (f64) sp18;
    }
    temp_f0_616 = M2C_BITWISE(f64, spB0) - spA0;
    sp40 = temp_f0_616;
    var_f7_622 = 0.0f;
    sp90 = temp_f0_616;
    sp48 = spB0.unk8 - (f32) spA8;
    (*(f32 *) ((u8 *) &sp88 + 0xc)) = 0.0f;
    sp98 = (f64) sp48;
    var_f4_635 = ((f32) sp98 * (f32) sp98) + (((f32) sp90 * (f32) sp90) + (0.0f * 0.0f));
    if (var_f4_635 > 0.000001f) {
        if (var_f4_635 > 0.0f) {
            temp_f1_640 = __frsqrte(var_f4_635);
            temp_f1_646 = 0.5 * temp_f1_640 * -(((f64) var_f4_635 * (temp_f1_640 * temp_f1_640)) - 3.0);
            temp_f1_650 = 0.5 * temp_f1_646 * -(((f64) var_f4_635 * (temp_f1_646 * temp_f1_646)) - 3.0);
            var_f4_635 = (f32) ((f64) var_f4_635 * (0.5 * temp_f1_650 * -(((f64) var_f4_635 * (temp_f1_650 * temp_f1_650)) - 3.0)));
        } else if (var_f4_635 < M2C_BITWISE(f32, 0.0)) {
            var_f4_635 = __float_nan;
        } else {
            sp8 = var_f4_635;
            temp_r3_669 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_669) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_679 = 1;
                } else {
                    var_r0_679 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_679 = 5;
                } else {
                    var_r0_679 = 3;
                }
                break;
            default:
                var_r0_679 = 4;
                break;
            }
            if (var_r0_679 == 1) {
                var_f4_635 = __float_nan;
            }
        }
        var_f7_622 = 1.0f / var_f4_635;
    }
    temp_f9_706 = (*(f32 *) ((u8 *) &sp88 + 0xc)) * var_f7_622;
    sp38 = 0.0f;
    temp_f0_709 = M2C_FIELD(arg0, f32 *, 4);
    temp_f10_710 = (f32) sp90 * var_f7_622;
    temp_f2_714 = M2C_FIELD(arg0, f32 *, 0);
    sp58 = (f64) sp38;
    temp_f8_716 = (f32) sp98 * var_f7_622;
    temp_f3_717 = M2C_FIELD(arg0, f32 *, 8);
    sp30 = 0.0f;
    sp34 = 1.0f;
    sp50 = (f64) sp30;
    var_f11_730 = 15.0f * (1.0f - ((temp_f3_717 * temp_f8_716) + ((temp_f2_714 * temp_f10_710) + (temp_f0_709 * temp_f9_706))));
    sp90 = temp_f10_710;
    (*(f32 *) ((u8 *) &sp88 + 0xc)) = temp_f9_706;
    sp98 = temp_f8_716;
    sp28 = ((f32) sp50 * temp_f9_706) - ((*(f32 *) ((u8 *) &sp50 + 0x4)) * temp_f10_710);
    sp20 = ((*(f32 *) ((u8 *) &sp50 + 0x4)) * temp_f8_716) - ((f32) sp58 * temp_f9_706);
    sp24 = ((f32) sp58 * temp_f10_710) - ((f32) sp50 * temp_f8_716);
    sp88 = (f64) sp28;
    sp80 = (f64) sp20;
    if (var_f11_730 < 1.0f) {

    } else {
        var_f11_730 = 1.0f;
    }
    if (var_f11_730 > -1.0f) {

    } else {
        var_f11_730 = -1.0f;
    }
    var_f7_765 = 1.5f * var_f11_730;
    if (((temp_f3_717 * (f32) sp88) + ((temp_f2_714 * (f32) sp80) + (temp_f0_709 * (*(f32 *) ((u8 *) &sp80 + 0x4))))) > 0.0f) {
        var_f7_765 = -var_f7_765;
    }
    this->unk1B8 += var_f7_765 * gUpdateTimeDelta;
    if (var_f7_765 < 0.0f) {
        var_f2_780 = -var_f7_765;
    } else {
        var_f2_780 = var_f7_765;
    }
    if (var_f2_780 >= 0.02f) {
        var_r0_789 = 1;
    } else {
        var_r0_789 = 0;
    }
    this->unk32D = var_r0_789;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'float' to 'signed char *'
void SiegeTower::UpdateTurretBone(MKDynamicBone *arg0, void *arg1) {
    Matrix sp30;
    M2C_UNK sp2C;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    s16 temp_r31_855;

    M2C_STRUCT_COPY((s32) &sp2C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    sp10 = -arg0->unk0;
    sp14 = -arg0->unk4;
    sp18 = -arg0->unk8;
    sp20 = (f64) sp10;
    sp28 = (f64) sp18;
    sp30.Translate(&sp30, *((MKVector3 *) &sp20));
    sp30.RotateYaw(&sp30, arg0->unk10);
    sp30.Translate(&sp30, *((MKVector3 *) arg0));
    temp_r31_855 = M2C_FIELD(this->unk20, s16 *, 0x70);
    ((Animation *) (MKModel_GetAnimation(M2C_BITWISE(MKModel *, this->unk24))))->SetCustomMatrix((s32) temp_r31_855, &sp30, (AnimationMatrixPosition) 4, 0U);
}
#endif

#if 0 // DRAFT: ')' expected
void *SiegeTower::Update() {
    f64 sp70;
    f64 sp68;
    f64 sp60;                                       /* compiler-managed */
    f64 sp58;                                       /* compiler-managed */
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    s32 sp8;
    KDSynkerPlayer3 *temp_r3_1030;
    Targetable *var_r31_1066;
    f32 temp_f31_1052;
    f32 var_f1_1302;
    f32 var_f31_1137;
    f32 var_f4_1124;
    f64 temp_f0_1118;
    f64 temp_f1_1103;
    f64 temp_f1_1142;
    f64 temp_f1_1148;
    f64 temp_f1_1152;
    s32 temp_r0_1049;
    s32 temp_r3_1171;
    s32 var_r0_1181;
    u8 var_r29_887;
    u8 var_r29_932;
    u8 var_r31_1027;
    u8 var_r31_891;
    u8 var_r31_936;
    u8 var_r31_977;
    void *temp_r29_1029;
    void *temp_r3_1013;
    void *temp_r3_1111;
    void *temp_r4_914;
    void *temp_r4_959;
    void *temp_r4_992;
    void *temp_r6_1094;
    void *temp_r6_1102;

    Shatterable::Update();
    if ((s32) M2C_FIELD(checked_cast<SiegeTowerDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x178) != 0) {
        var_r29_887 = 0;
        if ((void *) this->unk248 != NULL) {
            var_r31_891 = 0;
            if ((((KDSynkerPlayer3 *) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), KDSynkerPlayer3 **, 0x78) != NULL) || ((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x84) != 0U)) && (((KDStateMachine<CutsceneSystem> *) (M2C_FIELD(&gb, void **, 0xC) + 0x24))->GetState() != 0)) {
                var_r31_891 = 1;
            }
            if (var_r31_891 == 0) {
                var_r29_887 = 1;
            }
        }
        temp_r4_914 = checked_cast<SiegeTowerDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        sp8 = 1;
        ((KDSoundFader *) &this->unk2A0)->Update(M2C_FIELD(temp_r4_914, s32 *, 0x178), 1U, var_r29_887, NULL, &this->unk280, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    }
    if ((s32) M2C_FIELD(checked_cast<SiegeTowerDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x17C) != 0) {
        var_r29_932 = 0;
        if ((void *) this->unk248 != NULL) {
            var_r31_936 = 0;
            if ((((KDSynkerPlayer3 *) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), KDSynkerPlayer3 **, 0x78) != NULL) || ((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x84) != 0U)) && (((KDStateMachine<CutsceneSystem> *) (M2C_FIELD(&gb, void **, 0xC) + 0x24))->GetState() != 0)) {
                var_r31_936 = 1;
            }
            if (var_r31_936 == 0) {
                var_r29_932 = 1;
            }
        }
        temp_r4_959 = checked_cast<SiegeTowerDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        sp8 = 1;
        ((KDSoundFader *) &this->unk2C8)->Update(M2C_FIELD(temp_r4_959, s32 *, 0x17C), 1U, var_r29_932, NULL, &this->unk280, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    }
    if ((s32) M2C_FIELD(checked_cast<SiegeTowerDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x180) != 0) {
        var_r31_977 = 0;
        if (((u8) this->unk32D != 0) && (IsDead() == 0)) {
            var_r31_977 = 1;
        }
        temp_r4_992 = checked_cast<SiegeTowerDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        sp8 = 1;
        ((KDSoundFader *) &this->unk2F0)->Update(M2C_FIELD(temp_r4_992, s32 *, 0x180), 1U, var_r31_977, NULL, &this->unk270, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    }
    if ((s32) this->unk180 == (s32) (M2C_FIELD(checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x160) - 1)) {
        FreeElecBeams();
        temp_r3_1013 = this->unk248;
        if (temp_r3_1013 != NULL) {
            M2C_FIELD(M2C_FIELD(temp_r3_1013, void **, 0x44), M2C_UNK (**)(), 0x54)();
            M2C_FIELD(this->unk248, s32 *, 0x130) = 0;
            this->unk248 = NULL;
        }
    } else {
        var_r31_1027 = 0;
        temp_r29_1029 = M2C_FIELD(&gb, void **, 0xC);
        temp_r3_1030 = M2C_FIELD(temp_r29_1029, KDSynkerPlayer3 **, 0x78);
        if (((temp_r3_1030 != NULL) && (temp_r3_1030->IsPlaying() != 0)) || (((s32) M2C_FIELD(temp_r29_1029, s32 *, 0x74) == 2) && (((KDStateMachine<CutsceneSystem> *) (((u8 *) temp_r29_1029) + 0x24))->GetState() == 2))) {
            var_r31_1027 = 1;
        }
        if (var_r31_1027 == 0) {
            temp_r0_1049 = this->unk17C;
            if (temp_r0_1049 == 2) {
                temp_f31_1052 = this->unk1C0.unk34;
                this->unk1C0.unk34 = 0.0f;
                this->unk1C0.Update();
                this->unk1C0.unk34 = temp_f31_1052;
            } else if (temp_r0_1049 != 3) {
                this->unk1C0.Update();
            }
        }
        var_r31_1066 = NULL;
        if ((u32) this->unk298 == 0) {
            var_r31_1066 = ((TargetContext *) (M2C_FIELD(&gb, s32 *, 0x20) + 8))->Get();
        }
        if ((var_r31_1066 != NULL) && (M2C_FIELD(var_r31_1066->__vptr, u8 (**)(Targetable *), 0x20)(var_r31_1066) != 0)) {
            var_r31_1066 = NULL;
        }
        if (var_r31_1066 != NULL) {
            temp_r6_1094 = M2C_FIELD(M2C_FIELD(var_r31_1066->__vptr, void *(**)(Targetable *), 8)(var_r31_1066), void **, 8);
            sp68 = M2C_FIELD(temp_r6_1094, f64 *, 0x30);
            sp70 = M2C_FIELD(temp_r6_1094, f64 *, 0x38);
            temp_r6_1102 = this->unk8;
            temp_f1_1103 = M2C_FIELD(temp_r6_1102, f64 *, 0x30);
            sp48 = temp_f1_1103;
            sp50 = M2C_FIELD(temp_r6_1102, f64 *, 0x38);
            M2C_FIELD(var_r31_1066->__vptr, M2C_UNK (**)(Targetable *, f64 *, f64 *, void *, f64), 0x2C)(var_r31_1066, &sp48, &sp68, temp_r6_1102, temp_f1_1103);
            temp_r3_1111 = this->unk8;
            sp38 = M2C_FIELD(temp_r3_1111, f64 *, 0x30);
            sp40 = M2C_FIELD(temp_r3_1111, f64 *, 0x38);
            temp_f0_1118 = sp68 - sp38;
            sp18 = temp_f0_1118;
            var_f4_1124 = 0.0f;
            sp58 = temp_f0_1118;
            sp20 = (f32) sp70 - (f32) sp40;
            (*(f32 *) ((u8 *) &sp50 + 0xc)) = 0.0f;
            sp60 = (f64) sp20;
            var_f31_1137 = ((f32) sp60 * (f32) sp60) + (((f32) sp58 * (f32) sp58) + (0.0f * 0.0f));
            if (var_f31_1137 > 0.000001f) {
                if (var_f31_1137 > 0.0f) {
                    temp_f1_1142 = __frsqrte(var_f31_1137);
                    temp_f1_1148 = 0.5 * temp_f1_1142 * -(((f64) var_f31_1137 * (temp_f1_1142 * temp_f1_1142)) - 3.0);
                    temp_f1_1152 = 0.5 * temp_f1_1148 * -(((f64) var_f31_1137 * (temp_f1_1148 * temp_f1_1148)) - 3.0);
                    var_f31_1137 = (f32) ((f64) var_f31_1137 * (0.5 * temp_f1_1152 * -(((f64) var_f31_1137 * (temp_f1_1152 * temp_f1_1152)) - 3.0)));
                } else if (var_f31_1137 < M2C_BITWISE(f32, 0.0)) {
                    var_f31_1137 = __float_nan;
                } else {
                    sp10 = var_f31_1137;
                    temp_r3_1171 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                    switch (temp_r3_1171) {         /* irregular */
                    case 0x7F800000:
                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                            var_r0_1181 = 1;
                        } else {
                            var_r0_1181 = 2;
                        }
                        break;
                    case 0x0:
                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                            var_r0_1181 = 5;
                        } else {
                            var_r0_1181 = 3;
                        }
                        break;
                    default:
                        var_r0_1181 = 4;
                        break;
                    }
                    if (var_r0_1181 == 1) {
                        var_f31_1137 = __float_nan;
                    }
                }
                var_f4_1124 = 1.0f / var_f31_1137;
            } else {
                var_f31_1137 = 0.0f;
            }
            sp58 = (f32) sp58 * var_f4_1124;
            (*(f32 *) ((u8 *) &sp50 + 0xc)) *= var_f4_1124;
            sp60 = (f32) sp60 * var_f4_1124;
            sp28 = (f64) sp58;
            sp30 = (f64) sp60;
            UpdateTurning((MKVector3) &sp28);
            if ((M2C_ERROR(/* Read from unset register $f1 */) < 0.1f) && (var_f31_1137 <= this->unk294)) {
                if (((void *) this->unk248 == NULL) && (this->unk31C <= 0.0f)) {
                    if ((KDSound_IsVoicePlaying(this->unk328) == 0) || ((u8) this->unk32C != 0)) {
                        this->unk32C = 0;
                        this->unk320 = 0.0f;
                        KDSound_Stop((int *) &this->unk328);
                        this->unk328 = KDSound_Play3d(GS_SiegeTowerExtra3, &this->unk270, 0U, -1, 0.0f, 0U);
                    }
                    this->unk31C = 1.5f;
                }
                this->unk31C -= gUpdateTimeDelta;
                if (this->unk31C <= 0.0f) {
                    this->unk31C = 0.0f;
                    this->unk32C = 1;
                    this->unk320 = 0.75f;
                    Shoot(var_r31_1066);
                }
            } else if (((u8) this->unk32C == 0) && (KDSound_IsVoicePlaying(this->unk328) != 0)) {
                this->unk32C = 1;
                this->unk320 = 0.75f;
            }
        }
        if ((u8) this->unk32C != 0) {
            var_f1_1302 = this->unk320 * this->unk318;
            if (var_f1_1302 < 1.0f) {

            } else {
                var_f1_1302 = 1.0f;
            }
            if (var_f1_1302 > 0.0f) {

            } else {
                var_f1_1302 = 0.0f;
            }
            KDSound_SetVolume(this->unk328, var_f1_1302);
            this->unk320 -= gUpdateTimeDelta;
            if (this->unk320 <= 0.0f) {
                KDSound_Stop((int *) &this->unk328);
            }
        }
        UpdateShooting(var_r31_1066);
    }
}
#endif

f32 SiegeTower::Resolve() {
    u32 temp_r4_1352;
    void *temp_r3_1361;

    Shatterable::Resolve();
    temp_r4_1352 = this->unk324;
    if (temp_r4_1352 != -1U) {
        MKModel_CalculateRefPointWorldPosition(this->unk4, (s32) temp_r4_1352, &this->unk270);
    } else {
        temp_r3_1361 = this->unk8;
        M2C_FIELD(this, f64 *, 0x270) = (f64) M2C_FIELD(temp_r3_1361, f64 *, 0x30);
        M2C_FIELD(this, f64 *, 0x278) = (f64) M2C_FIELD(temp_r3_1361, f64 *, 0x38);
    }
    this->unk1C0.Resolve();
}

#if 0 // DRAFT: illegal implicit conversion from 'Animation *' to 'int'
s32 SiegeTower::LoadDone() {
    f64 sp8;
    s32 temp_r0_1422;
    s32 var_ctr_1431;
    s32 var_r3_1430;
    struct _struct_siegeTowerGroups_0x18 *temp_r4_1429;
    u16 temp_r30_1398;

    Shatterable::LoadDone();
    this->unk1C0.LoadDone();
    this->unk324 = (u32) Tools_GetMatchingRefPointIndex(this->unk4, "r_ammo");
    temp_r30_1398 = Tools_GetMatchingNodeIndex(this->unk4, "m_p3028_disc");
    ((Animation *) &sp8)->GetNodeOrigin(MKModel_GetAnimation(this->unk4));
    this->unk1A8 = sp8;
    this->unk1B0 = sp10;
    MKDynamicBone_SetUpdater(MKDynamicBone_AddDynamicBone(this->unk4, (s32) temp_r30_1398), (void (*)(MKDynamicBone *, void *)) &SiegeTower::UpdateTurretBone, &this->unk1A8);
    this->unk1B8 = 0.0f;
    CalcSpikeBeamPositions();
    AllocElecBeams();
    temp_r0_1422 = this->unk29C;
    if (temp_r0_1422 < 0xFF) {
        temp_r4_1429 = &siegeTowerGroups[temp_r0_1422];
        var_r3_1430 = 0;
        var_ctr_1431 = 6;
loop_2:
        if ((u32) *(temp_r4_1429 + var_r3_1430) == 0U) {
            *(temp_r4_1429 + var_r3_1430) = this;
            return;
        }
        var_r3_1430 += 4;
        var_ctr_1431 -= 1;
        if (var_ctr_1431 == 0) {

        } else {
            goto loop_2;
        }
    }
}
#endif

s32 SiegeTower::LoadLine(MKIniLine *arg0) {
    if ((Shatterable::LoadLine(arg0) != 0) || (this->unk1C0.LoadLine(arg0) != 0) || (arg0->LoadFloat("fTargetRange", &this->unk294, 0) != 0)) {
        return 1;
    }
    if (arg0->IsField("group") != 0) {
        this->unk29C = (s32) arg0->GetInt(0);
        return 1;
    }
    return 0;
}

#if 0 // DRAFT: undefined identifier 'siegeTowerGroups'
void SiegeTower::Deinit() {
    s32 var_ctr_1542;
    s32 var_r3_1537;
    struct _struct_siegeTowerGroups_0x18 *temp_r5_1546;
    void *temp_r3_1516;

    this->unk1C0.Deinit();
    temp_r3_1516 = this->unk248;
    if (temp_r3_1516 != NULL) {
        M2C_FIELD(temp_r3_1516, s32 *, 0x130) = 0;
    }
    this->unk248 = NULL;
    KDSound_Stop((int *) &this->unk2A0);
    KDSound_Stop((int *) &this->unk2C8);
    KDSound_Stop((int *) &this->unk2F0);
    KDSound_Stop((int *) &this->unk328);
    FreeElecBeams();
    if ((s32) this->unk29C < 0xFF) {
        var_r3_1537 = 0;
        var_ctr_1542 = 6;
        do {
            temp_r5_1546 = &siegeTowerGroups[this->unk29C];
            if ((u32) *(temp_r5_1546 + var_r3_1537) == this) {
                *(temp_r5_1546 + var_r3_1537) = 0;
            }
            var_r3_1537 += 4;
            var_ctr_1542 -= 1;
        } while (var_ctr_1542 != 0);
    }
    Shatterable::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'P20SiegeTowerDescriptor'
void SiegeTower::Init() {
    Shatterable::Init();
    this->unk1C0.Init(checked_cast<P20SiegeTowerDescriptor, 16MKPropDescriptor>__FP16MKPropDescriptor((MKPropDescriptor *) this->unk0) + 0x184, (MKProp *) this);
    this->unk248 = NULL;
    this->unk290 = 0.0f;
    ((KDSoundFader *) &this->unk2A0)->Init(0.05f, 0.25f);
    ((KDSoundFader *) &this->unk2C8)->Init(0.05f, 0.25f);
    ((KDSoundFader *) &this->unk2F0)->Init(0.25f, 0.25f);
    this->unk280.unk0 = 0.0f;
    this->unk280.unk4 = 0.0f;
    this->unk280.unk8 = 0.0f;
    this->unk32D = 0;
    this->unk328 = 0;
    this->unk31C = 0.0f;
    this->unk32C = 0;
    this->unk320 = 0.0f;
    this->unk318 = (1.3333334f * (f32) KDSound_GetSoundEventVol(GS_SiegeTowerExtra3)) / 255.0f;
    this->unk298 = 0;
    this->unk29C = 0xFF;
    this->unk294 = 3000.0f;
}
#endif

void SiegeTowerDescriptor::LoadDone() {
    ShatterableDescriptor::LoadDone();
    this->unk184.LoadDone();
    this->unk170 = (s32) Tools_GetMatchingRefPointIndex(this->unk2C, "fxemit0");
    this->unk174 = (s32) Tools_GetMatchingRefPointIndex(this->unk2C, "fxemit1");
}

s32 SiegeTowerDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_1674;

    var_r31_1674 = 0;
    if ((ShatterableDescriptor::LoadLine(arg0) != 0) || (KDSound_LoadLine(arg0, "ZapSoundLoop", (int *) &this->unk178) != 0) || (KDSound_LoadLine(arg0, "ZapSoundLoop2", (int *) &this->unk17C) != 0) || (KDSound_LoadLine(arg0, "TurningSoundLoop", (int *) &this->unk180) != 0) || (this->unk184.LoadLine(arg0) != 0)) {
        var_r31_1674 = 1;
    }
    return var_r31_1674;
}

void SiegeTowerDescriptor::Deinit() {
    this->unk184.Deinit();
    ShatterableDescriptor::Deinit();
}

#if 0 // DRAFT: undefined identifier 'unk16C'
void SiegeTowerDescriptor::Init() {
    ShatterableDescriptor::Init();
    this->unk64 |= 0x2000;
    this->unk178 = 0;
    this->unk17C = 0;
    this->unk180 = 0;
    this->unk16C = checked_cast<EnergyBeam *, MKProp>(gMK->CreateProp("EnergyBeam"));
    this->unk184.Init();
}
#endif

#if 0 // DRAFT: undefined identifier 'siegeTowerGroups'
s32 SiegeTower_GetSiegeTower(int arg0, int arg1) {
    return *(&siegeTowerGroups[arg0] + (arg1 * 4));
}
#endif

s32 SiegeTower_GetMaxPerGroup() {
    return 6;
}

#if 0 // DRAFT: undefined identifier 'siegeTowerGroups'
void SiegeTower_InitModule() {
    memset(siegeTowerGroups, 0, 0xC0U);
}
#endif
