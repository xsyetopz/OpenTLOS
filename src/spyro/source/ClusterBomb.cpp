#include "spyro/source/ClusterBomb.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKMemoryCard.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/CameraData.h"
#include "spyro/source/CrashFirePS.h"
#include "spyro/source/ExpShock.h"
#include "spyro/source/ExpSmokeAndFlamesPS.h"
#include "spyro/source/Explosion3.h"
#include "spyro/source/ExplosionFX.h"
#include "spyro/source/GameData.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/Level.h"
#include "spyro/source/ManagedLight.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDRandom.h"
#include <m2c_macros.h>

M2C_UNK free(MKVector3 **);                         /* extern */
MKVector3 **malloc(M2C_UNK);                        /* extern */
extern M2C_UNK gEmptyPtrListDL;
extern void **gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;

void ClusterBomb::DrawClusterBombs() {
    Matrix sp10;
    M2C_UNK spC;
    MKVector3 **var_r31_49;
    MKVector3 *temp_r6_86;

    var_r31_49 = this->unk4C;
loop_4:
    if (var_r31_49 != NULL) {
        temp_r6_86 = *var_r31_49;
        if (temp_r6_86 != NULL) {
            if ((s32) M2C_FIELD(temp_r6_86, s32 *, 0x24) != 2) {
                M2C_STRUCT_COPY((s32) &spC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
                sp10.unk30 = temp_r6_86->unk0;
                sp10.unk34 = temp_r6_86->unk4;
                sp10.unk38 = temp_r6_86->unk8;
                sp10.unk3C = 1.0f;
                MKModel_SetWorldMatrix(this->unk50, sp10);
                MKModel_Draw(this->unk50, NULL);
            }
            var_r31_49 += 4;
            goto loop_4;
        }
    }
}

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to 'double'
void ClusterBomb::UpdateClusterBombs() {
    s8 sp240;
    s32 sp23C;
    s32 sp238;
    s32 sp234;
    f32 sp230;
    s32 sp22C;
    s8 sp22B;
    s8 sp22A;
    s16 sp228;
    f32 sp224;
    f32 sp220;
    f32 sp21C;
    f32 sp218;
    f32 sp214;
    f32 sp210;
    f32 sp208;
    f32 sp204;
    f32 sp200;
    f32 sp1F8;
    f32 sp1F4;
    f32 sp1F0;
    BreathHitMessage sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    MKVector3 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    MKVector3 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    MKVector3 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp90;
    f64 sp88;
    f32 sp80;
    f64 sp78;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKVector3 **temp_r3_581;
    MKVector3 **var_r27_119;
    MKVector3 *temp_r28_593;
    MKVector3 *temp_r4_584;
    f32 temp_f0_220;
    f32 temp_f1_413;
    f32 temp_f27_536;
    f32 temp_f2_219;
    f32 temp_f2_331;
    f32 temp_f3_330;
    f32 temp_f4_221;
    f32 temp_f4_332;
    f32 var_f0_227;
    f32 var_f2_294;
    f32 var_f3_404;
    f32 var_f5_337;
    f64 temp_f0_145;
    f64 temp_f0_207;
    f64 temp_f0_452;
    f64 temp_f1_311;
    f64 temp_f2_233;
    f64 temp_f2_239;
    f64 temp_f2_243;
    f64 temp_f2_343;
    f64 temp_f2_349;
    f64 temp_f2_353;
    s32 temp_r0_129;
    s32 temp_r3_262;
    s32 temp_r3_372;
    s32 var_r0_272;
    s32 var_r0_382;
    void *temp_r25_515;

    var_r27_119 = this->unk4C;
loop_52:
    if (var_r27_119 != NULL) {
        temp_r28_593 = *var_r27_119;
        if (temp_r28_593 != NULL) {
            M2C_FIELD(temp_r28_593, f32 *, 0x28) = (f32) (M2C_FIELD(temp_r28_593, f32 *, 0x28) - gUpdateTimeDelta);
            temp_r0_129 = M2C_FIELD(temp_r28_593, s32 *, 0x24);
            switch (temp_r0_129) {                  /* switch 1; irregular */
            case 1:                                 /* switch 1 */
                sp188 = M2C_FIELD(temp_r28_593, f64 *, 0);
                sp190 = M2C_FIELD(temp_r28_593, f64 *, 8);
                temp_f0_145 = M2C_FIELD(temp_r28_593, f64 *, 0x10) * (f64) gUpdateTimeDelta;
                sp38 = temp_f0_145;
                sp178 = temp_f0_145;
                sp40 = M2C_FIELD(temp_r28_593, f32 *, 0x18) * gUpdateTimeDelta;
                sp180 = (f64) sp40;
                M2C_FIELD(temp_r28_593, f64 *, 0) = (f64) (M2C_FIELD(temp_r28_593, f64 *, 0) + temp_f0_145);
                temp_r28_593->unk8 += (f32) sp180;
                M2C_FIELD(temp_r28_593, f32 *, 0x14) = (f32) ((-2080.0f * gUpdateTimeDelta) + M2C_FIELD(temp_r28_593, f32 *, 0x14));
                sp1F0 = 0.0f;
                sp1F4 = 0.0f;
                sp1F8 = 0.0f;
                sp200 = 0.0f;
                sp204 = 0.0f;
                sp208 = 0.0f;
                sp210 = 0.0f;
                sp214 = 0.0f;
                sp218 = 0.0f;
                sp21C = 1.0f;
                sp220 = 0.0f;
                sp224 = 0.0f;
                sp228 = 0;
                sp22A = 0;
                sp22B = 0;
                sp22C = 0;
                sp230 = 3.4028235e38f;
                sp234 = 0;
                sp238 = 0;
                sp23C = -1;
                sp240 = 0;
                if (MKCollision_RayCollide(*((MKVector3 *) &sp188), *temp_r28_593, (MKCollisionResult *) &sp1F0, (MKCollisionMode) 7, 0x04000000) != 0) {
                    sp158.operator*(10.0f);
                    temp_f0_207 = (f64) sp1F0 + M2C_BITWISE(f64, sp158);
                    sp28 = temp_f0_207;
                    M2C_FIELD(temp_r28_593, f64 *, 0) = temp_f0_207;
                    sp30 = sp1F8 + sp158.unk8;
                    sp168 = temp_f0_207;
                    M2C_FIELD(temp_r28_593, f64 *, 8) = (f64) sp30;
                    temp_f2_219 = (f32) M2C_FIELD(temp_r28_593, f64 *, 0x10);
                    temp_f0_220 = M2C_FIELD(temp_r28_593, f32 *, 0x14);
                    temp_f4_221 = M2C_FIELD(temp_r28_593, f32 *, 0x18);
                    sp170 = (f64) sp30;
                    var_f0_227 = (temp_f4_221 * temp_f4_221) + ((temp_f2_219 * temp_f2_219) + (temp_f0_220 * temp_f0_220));
                    if (var_f0_227 > 0.000001f) {
                        if (var_f0_227 > 0.0f) {
                            temp_f2_233 = __frsqrte(var_f0_227);
                            temp_f2_239 = 0.5 * temp_f2_233 * -(((f64) var_f0_227 * (temp_f2_233 * temp_f2_233)) - 3.0);
                            temp_f2_243 = 0.5 * temp_f2_239 * -(((f64) var_f0_227 * (temp_f2_239 * temp_f2_239)) - 3.0);
                            var_f0_227 = (f32) ((f64) var_f0_227 * (0.5 * temp_f2_243 * -(((f64) var_f0_227 * (temp_f2_243 * temp_f2_243)) - 3.0)));
                        } else if (var_f0_227 < M2C_BITWISE(f32, 0.0)) {
                            var_f0_227 = __float_nan;
                        } else {
                            spC = var_f0_227;
                            temp_r3_262 = M2C_BITWISE(s32, spC) & 0x7F800000;
                            switch (temp_r3_262) {  /* switch 2; irregular */
                            case 0x7F800000:        /* switch 2 */
                                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                                    var_r0_272 = 1;
                                } else {
                                    var_r0_272 = 2;
                                }
                                break;
                            case 0x0:               /* switch 2 */
                                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                                    var_r0_272 = 5;
                                } else {
                                    var_r0_272 = 3;
                                }
                                break;
                            default:                /* switch 2 */
                                var_r0_272 = 4;
                                break;
                            }
                            if (var_r0_272 == 1) {
                                var_f0_227 = __float_nan;
                            }
                        }
                        var_f2_294 = 1.0f / var_f0_227;
                    } else {
                        var_f2_294 = 0.0f;
                        var_f0_227 = 0.0f;
                    }
                    M2C_FIELD(temp_r28_593, f64 *, 0x10) = (f32) ((f32) M2C_FIELD(temp_r28_593, f64 *, 0x10) * var_f2_294);
                    M2C_FIELD(temp_r28_593, f32 *, 0x14) = (f32) (M2C_FIELD(temp_r28_593, f32 *, 0x14) * var_f2_294);
                    M2C_FIELD(temp_r28_593, f32 *, 0x18) = (f32) (M2C_FIELD(temp_r28_593, f32 *, 0x18) * var_f2_294);
                    temp_f1_311 = sp200 * 5.304989477e-315;
                    sp18 = temp_f1_311;
                    sp148 = temp_f1_311;
                    sp20 = sp208 * 2.0f;
                    sp150 = (f64) sp20;
                    M2C_FIELD(temp_r28_593, f64 *, 0x10) = (f64) (M2C_FIELD(temp_r28_593, f64 *, 0x10) + temp_f1_311);
                    M2C_FIELD(temp_r28_593, f32 *, 0x18) = (f32) (M2C_FIELD(temp_r28_593, f32 *, 0x18) + (f32) sp150);
                    temp_f3_330 = (f32) M2C_FIELD(temp_r28_593, f64 *, 0x10);
                    temp_f2_331 = M2C_FIELD(temp_r28_593, f32 *, 0x14);
                    temp_f4_332 = M2C_FIELD(temp_r28_593, f32 *, 0x18);
                    var_f5_337 = (temp_f4_332 * temp_f4_332) + ((temp_f3_330 * temp_f3_330) + (temp_f2_331 * temp_f2_331));
                    if (var_f5_337 > 0.000001f) {
                        if (var_f5_337 > 0.0f) {
                            temp_f2_343 = __frsqrte(var_f5_337);
                            temp_f2_349 = 0.5 * temp_f2_343 * -(((f64) var_f5_337 * (temp_f2_343 * temp_f2_343)) - 3.0);
                            temp_f2_353 = 0.5 * temp_f2_349 * -(((f64) var_f5_337 * (temp_f2_349 * temp_f2_349)) - 3.0);
                            var_f5_337 = (f32) ((f64) var_f5_337 * (0.5 * temp_f2_353 * -(((f64) var_f5_337 * (temp_f2_353 * temp_f2_353)) - 3.0)));
                        } else if (var_f5_337 < M2C_BITWISE(f32, 0.0)) {
                            var_f5_337 = __float_nan;
                        } else {
                            sp8 = var_f5_337;
                            temp_r3_372 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                            switch (temp_r3_372) {  /* switch 3; irregular */
                            case 0x7F800000:        /* switch 3 */
                                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                    var_r0_382 = 1;
                                } else {
                                    var_r0_382 = 2;
                                }
                                break;
                            case 0x0:               /* switch 3 */
                                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                    var_r0_382 = 5;
                                } else {
                                    var_r0_382 = 3;
                                }
                                break;
                            default:                /* switch 3 */
                                var_r0_382 = 4;
                                break;
                            }
                            if (var_r0_382 == 1) {
                                var_f5_337 = __float_nan;
                            }
                        }
                        var_f3_404 = 1.0f / var_f5_337;
                    } else {
                        var_f3_404 = 0.0f;
                    }
                    temp_f1_413 = 0.5f * var_f0_227;
                    M2C_FIELD(temp_r28_593, f64 *, 0x10) = (f32) ((f32) M2C_FIELD(temp_r28_593, f64 *, 0x10) * var_f3_404);
                    M2C_FIELD(temp_r28_593, f32 *, 0x14) = (f32) (M2C_FIELD(temp_r28_593, f32 *, 0x14) * var_f3_404);
                    M2C_FIELD(temp_r28_593, f32 *, 0x18) = (f32) (M2C_FIELD(temp_r28_593, f32 *, 0x18) * var_f3_404);
                    M2C_FIELD(temp_r28_593, f64 *, 0x10) = (f64) (M2C_FIELD(temp_r28_593, f64 *, 0x10) * (f64) temp_f1_413);
                    M2C_FIELD(temp_r28_593, f32 *, 0x18) = (f32) (M2C_FIELD(temp_r28_593, f32 *, 0x18) * temp_f1_413);
                }
                spB0 = -1.0f;
                spA0 = 1.0f;
                spA8 = -1.0f;
                spAC = -1.0f;
                sp98 = 1.0f;
                sp9C = 1.0f;
                sp108 = (f64) spA8;
                sp110 = (f64) spB0;
                spF8 = (f64) sp98;
                sp100 = (f64) spA0;
                KDRand_Vector(sp118, *((MKVector3 *) &sp108));
                temp_f0_452 = sp118 * 5.49408334e-315;
                sp88 = temp_f0_452;
                sp128 = temp_f0_452;
                sp90 = sp118.unk8 * 50.0f;
                sp130 = (f64) sp90;
                sp78 = M2C_FIELD(temp_r28_593, f64 *, 0) + temp_f0_452;
                sp70 = 0.0f;
                sp68 = 0.0f;
                sp80 = temp_r28_593->unk8 + (f32) sp130;
                sp6C = 100.0f;
                sp138 = sp78;
                sp140 = (f64) sp80;
                spE8 = (f64) sp68;
                spF0 = (f64) sp70;
                sp10 = MKRand_Float((int *) &gViewSeed, 4.0f, 6.0f);
                ((CrashFirePS *) (M2C_FIELD(&gb, CrashFirePS **, 0x68)))->Emit(*((MKVector3 *) &sp138), *((MKVector3 *) &spE8), sp10);
                if (M2C_FIELD(temp_r28_593, f32 *, 0x28) <= 0.0f) {
                    sp50 = 1.0f;
                    sp60 = -1.0f;
                    sp48 = 1.0f;
                    sp4C = 1.0f;
                    sp58 = -1.0f;
                    sp5C = -1.0f;
                    spB8 = (f64) sp48;
                    spC0 = (f64) sp50;
                    spC8 = (f64) sp58;
                    spD0 = (f64) sp60;
                    temp_r25_515 = checked_cast<ClusterBombDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
                    KDRand_Vector(spD8, *((MKVector3 *) &spC8));
                    ((Explosion3 *) (M2C_FIELD(temp_r25_515, Explosion3 **, 0x60)))->Trigger(*temp_r28_593, 2.0f, 1U, 0U, spD8, NULL);
                    sp198.unk4 = 0;
                    temp_f27_536 = ((GameStats *) &GameData::gameData[0x70])->GetBreathAttackDamage(0, 1, 3);
                    sp198.Init(M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), MKProp *(**)(void **), 0xC)(M2C_FIELD(&gb, void ***, 0)), temp_f27_536, 1, 3, 0, 0, 0, -1);
                    sp198.unk10 = M2C_FIELD(temp_r28_593, f64 *, 0);
                    sp198.unk18 = M2C_FIELD(temp_r28_593, f64 *, 8);
                    M2C_FIELD(*gMK, M2C_UNK (**)(void **, BreathHitMessage *, M2C_UNK, M2C_UNK, MKVector3 *, M2C_UNK, f32), 0x94)(gMK, &sp198, 0, 1, temp_r28_593, 1, 600.0f);
                    M2C_FIELD(temp_r28_593, s32 *, 0x24) = 2;
                    M2C_FIELD(temp_r28_593, f32 *, 0x28) = 0.5f;
                }
                break;
            case 2:                                 /* switch 1 */
                if (M2C_FIELD(temp_r28_593, f32 *, 0x28) <= 0.0f) {
                    M2C_FIELD(temp_r28_593, s32 *, 0x24) = 0;
                    temp_r3_581 = this->unk4C;
                    this->unk4C = temp_r3_581 + 4;
                    temp_r4_584 = *temp_r3_581;
                    *temp_r3_581 = *var_r27_119;
                    *var_r27_119 = temp_r4_584;
                }
                break;
            }
            var_r27_119 += 4;
            goto loop_52;
        }
    }
}
#endif

void ClusterBomb::SpawnClusterBomb(const MKVector3 &arg0, const MKVector3 &arg1) {
    MKVector3 **temp_r6_621;
    MKVector3 **temp_r6_625;
    MKVector3 *temp_r31_627;

    temp_r6_621 = this->unk4C;
    if ((u32) M2C_FIELD(temp_r6_621, u32 *, -4) != 0U) {
        temp_r6_625 = temp_r6_621 - 4;
        this->unk4C = temp_r6_625;
        temp_r31_627 = *temp_r6_625;
        if (temp_r31_627 != NULL) {
            M2C_FIELD(temp_r31_627, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
            M2C_FIELD(temp_r31_627, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
            M2C_FIELD(temp_r31_627, f64 *, 0x10) = (f64) M2C_FIELD(&arg1, f64 *, 0);
            M2C_FIELD(temp_r31_627, f64 *, 0x18) = (f64) M2C_FIELD(&arg1, f64 *, 8);
            M2C_FIELD(temp_r31_627, f32 *, 0x28) = (f32) (2.0f * MKRand_Float((int *) &gViewSeed, 0.5f, 1.0f));
            M2C_FIELD(temp_r31_627, s32 *, 0x24) = 1;
        }
    }
}

#if 0 // DRAFT: type mismatch 'MKVector3 *' and 'MKVector3 **'
void ClusterBomb::Deinit() {
    MKVector3 **var_r31_666;
    MKVector3 **var_r3_667;
    MKVector3 **var_r4_665;
    MKVector3 *temp_r0_670;
    MKVector3 *temp_r0_689;
    u32 temp_r0_675;

    MKModel_Destroy(this->unk50);
    var_r4_665 = this->unk4C;
    var_r31_666 = var_r4_665;
    var_r3_667 = var_r4_665;
loop_3:
    temp_r0_675 = M2C_FIELD(var_r3_667, u32 *, -4);
    var_r3_667 -= 4;
    if (temp_r0_675 != 0U) {
        temp_r0_670 = *var_r3_667;
        if (temp_r0_670 < var_r31_666) {
            var_r31_666 = (MKVector3 **) temp_r0_670;
        }
        goto loop_3;
    }
    if (var_r3_667 != &gEmptyPtrListDL) {
loop_9:
        temp_r0_689 = *var_r4_665;
        if (temp_r0_689 != NULL) {
            if (temp_r0_689 < var_r31_666) {
                var_r31_666 = (MKVector3 **) temp_r0_689;
            }
            var_r4_665 += 4;
            goto loop_9;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(var_r31_666, NULL, 0);
        } else {
            free(var_r31_666);
        }
    }
    this->unk4C = NULL;
    MKProp::Deinit();
}
#endif

void ClusterBomb::Draw() {
    DrawClusterBombs();
}

void *ClusterBomb::Update() {
    UpdateClusterBombs();
}

void ClusterBomb::Init() {
    MKVector3 **temp_r3_773;
    MKVector3 **temp_r4_779;
    MKVector3 **var_r3_758;
    MKVector3 **var_r5_767;
    s32 var_ctr_771;

    MKProp::Init();
    if (MKHeap::Current() != NULL) {
        var_r3_758 = (MKVector3 **) (((MKHeap *) (MKHeap::Current()))->Alloc(0x210, NULL, 0));
    } else {
        var_r3_758 = malloc(0x210);
    }
    this->unk4C = var_r3_758;
    var_r5_767 = this->unk4C;
    this->unk4C = var_r5_767 + 0x1E0;
    M2C_FIELD(var_r5_767, s32 *, 0x1E0) = 0;
    var_ctr_771 = 0xA;
    do {
        temp_r3_773 = this->unk4C;
        this->unk4C = temp_r3_773 + 4;
        M2C_FIELD(temp_r3_773, MKVector3 ***, 4) = var_r5_767;
        var_r5_767 += 0x30;
        var_ctr_771 -= 1;
    } while (var_ctr_771 != 0);
    temp_r4_779 = this->unk4C;
    this->unk4C = temp_r4_779 + 4;
    M2C_FIELD(temp_r4_779, MKVector3 ***, 4) = NULL;
    this->unk50 = MKModel_Create("P0002_LavaCannonBall", NULL, 2, NULL);
}

void ClusterBombDescriptor::Init() {
    MKPropDescriptor::Init();
    ((MKSceneManager *) gMK)->CreatePropDeferred("Explosion3", &this->unk60);
}
