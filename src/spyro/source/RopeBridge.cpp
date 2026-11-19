#include "spyro/source/RopeBridge.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionItem.h"
#include "common/Source/MKCollisionManager.h"
#include "common/Source/MKCollisionModel.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKCollisionUtil.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
#include "spyro/source/CustomMaterialUpdater.h"
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
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKView.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

void *__construct_new_array();                      /* extern */
M2C_UNK __destroy_new_array(void *, RopeBridge::BridgePiece *(*)(RopeBridge::BridgePiece *, s16)); /* extern */
f64 atan2(void *, f32, f32);                        /* extern */
M2C_UNK free(void *);                               /* extern */
void *malloc(s32);                                  /* extern */
s32 stricmp(s8 *);                                  /* extern */
extern s32 GS_TallPlainsBridge;
extern f32 ROPEBRIDGE_MAXROLL;
extern void **gMK;
extern f32 gUpdateTimeDelta;
extern M2C_UNK gb;
static M2C_UNK boundingVolume;                      /* unable to generate initializer: unknown type */

void RopeBridge::Reset() {
    this->unk1A4 = -1;
    this->unk1A8 = 0;
    this->unk1AC = 0.0f;
}

#if 0 // DRAFT: illegal type
void RopeBridge::DetachBridgeEnthusiasts() {
    s32 spC;
    s32 sp8;
    s32 var_r27_58;
    void *temp_r3_68;
    void *var_r28_61;

    var_r27_58 = 0;
    var_r28_61 = this->unk184;
loop_5:
    if (var_r27_58 < (s32) this->unk188) {
loop_3:
        if (M2C_FIELD(var_r28_61, void **, 0x40) != (void *) (((u8 *) var_r28_61) + 0x20)) {
            temp_r3_68 = M2C_FIELD(M2C_FIELD(var_r28_61, void **, 0x40), void **, 0x18);
            spC = 0;
            sp8 = 0x9C;
            M2C_FIELD(M2C_FIELD(temp_r3_68, void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(temp_r3_68, &sp8);
            goto loop_3;
        }
        var_r28_61 += 0x50;
        var_r27_58 += 1;
        goto loop_5;
    }
}
#endif

#if 0 // DRAFT: illegal type
void RopeBridge::FindBrokenPlank(const MKVector3 &arg0) {
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f0_138;
    f32 temp_f30_106;
    f32 var_f31_105;
    f64 temp_f0_122;
    f64 temp_f1_116;
    s32 var_r30_108;
    s32 var_r31_109;
    void *temp_r3_115;

    var_f31_105 = 3.4028235e38f;
    temp_f30_106 = arg0.unk8;
    var_r30_108 = 0;
    var_r31_109 = 0;
loop_4:
    if (var_r30_108 < (s32) this->unk188) {
        temp_r3_115 = MKModel_GetWorldMatrix(*(this->unk184 + (var_r31_109 + 0x48)));
        temp_f1_116 = M2C_FIELD(temp_r3_115, f64 *, 0x30);
        sp28 = temp_f1_116;
        sp30 = M2C_FIELD(temp_r3_115, f64 *, 0x38);
        temp_f0_122 = temp_f1_116 - M2C_FIELD(&arg0, f64 *, 0);
        sp8 = temp_f0_122;
        sp18 = temp_f0_122;
        sp10 = (f32) sp30 - temp_f30_106;
        sp20 = (f64) sp10;
        temp_f0_138 = ((f32) sp20 * (f32) sp20) + (((f32) sp18 * (f32) sp18) + ((*(f32 *) ((u8 *) &sp18 + 0x4)) * (*(f32 *) ((u8 *) &sp18 + 0x4))));
        if (temp_f0_138 < var_f31_105) {
            this->unk1A4 = var_r30_108;
            var_f31_105 = temp_f0_138;
        }
        var_r30_108 += 1;
        var_r31_109 += 0x50;
        goto loop_4;
    }
}
#endif

void RopeBridge::Detach(RopeBridgeAttachment *arg0) {
    arg0->unk24->unk20 = arg0->unk20;
    arg0->unk20->unk24 = arg0->unk24;
    arg0->unk24 = arg0;
    arg0->unk20 = arg0;
    arg0->unk1C = NULL;
    arg0->unk10 = M2C_FIELD(&gb, f32 *, 0x30C);
}

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to
u8 RopeBridge::Attach(RopeBridgeAttachment *arg0, MKCollisionInfo *arg1) {
    f64 sp10;
    f64 sp8;
    RopeBridgeAttachment *temp_r5_246;
    f64 temp_f0_215;
    f64 temp_f2_214;
    s32 temp_r0_224;
    s32 var_ctr_226;
    s32 var_r3_225;
    void *temp_r3_211;

    if ((M2C_FIELD(&gb, f32 *, 0x30C) - arg0->unk10) >= 0.5f) {
        if (KDSound_IsVoicePlaying(arg0->unk14) != 0) {
            KDSound_Stop((int *) &arg0->unk14);
        }
        temp_r3_211 = M2C_FIELD(arg0->unk18, void **, 8);
        temp_f2_214 = M2C_FIELD(temp_r3_211, f64 *, 0x30);
        temp_f0_215 = M2C_FIELD(temp_r3_211, f64 *, 0x38);
        sp8 = temp_f2_214;
        arg0->unk0 = temp_f2_214;
        arg0->unk8 = temp_f0_215;
        sp10 = temp_f0_215;
        arg0->unk14 = KDSound_Play3d(GS_TallPlainsBridge, (MKVector3 *) arg0, 0U, -1, 0.0f, 0U);
    }
    temp_r0_224 = this->unk188;
    var_r3_225 = 0;
    var_ctr_226 = temp_r0_224;
    if (temp_r0_224 > 0) {
loop_5:
        if (arg1 == (void *) (((u8 *) this->unk184) + (var_r3_225 + 0x10))) {
            arg0->unk24->unk20 = arg0->unk20;
            arg0->unk20->unk24 = arg0->unk24;
            arg0->unk24 = arg0;
            arg0->unk20 = arg0;
            temp_r5_246 = ((u8 *) this->unk184) + (var_r3_225 + 0x20);
            arg0->unk20 = temp_r5_246;
            arg0->unk24 = temp_r5_246->unk24;
            temp_r5_246->unk24 = arg0;
            arg0->unk24->unk20 = arg0;
            arg0->unk1C = this;
            return 1U;
        }
        var_r3_225 += 0x50;
        var_ctr_226 -= 1;
        if (var_ctr_226 == 0) {
            goto block_8;
        }
        goto loop_5;
    }
block_8:
    return 0U;
}
#endif

#if 0 // DRAFT: undefined identifier 'ApplyForceMsg'
void RopeBridge::Message(MKMessage *arg0) {
    f32 temp_f0_319;
    f32 var_f31_310;
    s32 temp_r0_279;
    s32 temp_r3_298;
    void *temp_r3_336;
    void *temp_r3_360;

    temp_r0_279 = arg0->unk0;
    switch (temp_r0_279) {                          /* irregular */
    case 0x3C:
        temp_r3_298 = checked_cast<ApplyForceMsg *, MKMessage>(arg0);
        ApplyForce(*(temp_r3_298 + 8), *(temp_r3_298 + 0x18));
        break;
    case 0x422:
        var_f31_310 = this->unk19C - (3.0f * gUpdateTimeDelta);
        Level::GetWorldInfo();
        if (var_f31_310 < 1.0f) {

        } else {
            var_f31_310 = 1.0f;
        }
        temp_f0_319 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 8);
        if (var_f31_310 > temp_f0_319) {

        } else {
            var_f31_310 = temp_f0_319;
        }
        this->unk19C = var_f31_310;
        this->unk10 |= 0x4000;
        break;
    case 0x99:
        if ((u8) this->unk1A8 == 0) {
            temp_r3_336 = checked_cast<RopeBridgeAttachDetachMsg *, MKMessage>(arg0);
            if (Attach(M2C_FIELD(temp_r3_336, RopeBridgeAttachment **, 8), M2C_FIELD(temp_r3_336, MKCollisionInfo **, 0xC)) != 0) {
                M2C_FIELD(temp_r3_336, s8 *, 0x10) = 1;
            }
        }
        break;
    case 0x9A:
        Detach(M2C_FIELD(checked_cast<RopeBridgeAttachDetachMsg *, MKMessage>(arg0), RopeBridgeAttachment **, 8));
        break;
    case 0x91:
        if ((u8) this->unk1A8 == 0) {
            temp_r3_360 = checked_cast<DropBoxDroppedMsg *, MKMessage>(arg0);
            FindBrokenPlank(*(temp_r3_360 + 8));
            this->unk1AC = M2C_FIELD(temp_r3_360, f32 *, 0x18);
        }
        break;
    }
    MKProp::Message(arg0);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void RopeBridge::Draw() {
    f64 sp68;
    f64 sp60;
    MKVector3 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 spC;
    f32 sp8;
    Matrix *temp_r3_398;
    f32 temp_f28_587;
    f32 temp_f2_582;
    f32 temp_f3_580;
    f32 temp_f3_584;
    f32 temp_f3_612;
    f32 var_f0_625;
    f32 var_f1_639;
    f32 var_f30_426;
    f32 var_f4_514;
    f64 temp_f1_429;
    f64 temp_f1_435;
    f64 temp_f1_439;
    f64 temp_f1_517;
    f64 temp_f1_523;
    f64 temp_f1_527;
    s32 temp_r3_458;
    s32 temp_r3_546;
    s32 temp_r4_666;
    s32 var_r0_468;
    s32 var_r0_556;
    s32 var_r28_603;
    s32 var_r30_604;

    temp_r3_398 = MKView_GetCameraMatrix();
    sp60 = M2C_FIELD(temp_r3_398, f64 *, 0x30);
    sp68 = M2C_FIELD(temp_r3_398, f64 *, 0x38);
    MKModel_CalculateCentre(M2C_FIELD(this->unk184, MKModel **, 0x48), &sp50);
    sp20 = sp60 - M2C_BITWISE(f64, sp50);
    sp40 = sp20;
    sp28 = (f32) sp68 - sp50.unk8;
    sp48 = (f64) sp28;
    var_f30_426 = ((f32) sp48 * (f32) sp48) + (((f32) sp40 * (f32) sp40) + ((*(f32 *) ((u8 *) &sp40 + 0x4)) * (*(f32 *) ((u8 *) &sp40 + 0x4))));
    if (var_f30_426 > 0.0f) {
        temp_f1_429 = __frsqrte(var_f30_426);
        temp_f1_435 = 0.5 * temp_f1_429 * -(((f64) var_f30_426 * (temp_f1_429 * temp_f1_429)) - 3.0);
        temp_f1_439 = 0.5 * temp_f1_435 * -(((f64) var_f30_426 * (temp_f1_435 * temp_f1_435)) - 3.0);
        var_f30_426 = (f32) ((f64) var_f30_426 * (0.5 * temp_f1_439 * -(((f64) var_f30_426 * (temp_f1_439 * temp_f1_439)) - 3.0)));
    } else if (var_f30_426 < M2C_BITWISE(f32, 0.0)) {
        var_f30_426 = __float_nan;
    } else {
        spC = var_f30_426;
        temp_r3_458 = M2C_BITWISE(s32, spC) & 0x7F800000;
        switch (temp_r3_458) {                      /* switch 1; irregular */
        case 0x7F800000:                            /* switch 1 */
            if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                var_r0_468 = 1;
            } else {
                var_r0_468 = 2;
            }
            break;
        case 0x0:                                   /* switch 1 */
            if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                var_r0_468 = 5;
            } else {
                var_r0_468 = 3;
            }
            break;
        default:                                    /* switch 1 */
            var_r0_468 = 4;
            break;
        }
        if (var_r0_468 == 1) {
            var_f30_426 = __float_nan;
        }
    }
    MKModel_CalculateCentre(M2C_FIELD((((u8 *) this->unk184) + (this->unk188 * 0x50)), MKModel **, -8), &sp50);
    sp10 = sp60 - M2C_BITWISE(f64, sp50);
    sp30 = sp10;
    sp18 = (f32) sp68 - sp50.unk8;
    sp38 = (f64) sp18;
    var_f4_514 = ((f32) sp38 * (f32) sp38) + (((f32) sp30 * (f32) sp30) + ((*(f32 *) ((u8 *) &sp30 + 0x4)) * (*(f32 *) ((u8 *) &sp30 + 0x4))));
    if (var_f4_514 > 0.0f) {
        temp_f1_517 = __frsqrte(var_f4_514);
        temp_f1_523 = 0.5 * temp_f1_517 * -(((f64) var_f4_514 * (temp_f1_517 * temp_f1_517)) - 3.0);
        temp_f1_527 = 0.5 * temp_f1_523 * -(((f64) var_f4_514 * (temp_f1_523 * temp_f1_523)) - 3.0);
        var_f4_514 = (f32) ((f64) var_f4_514 * (0.5 * temp_f1_527 * -(((f64) var_f4_514 * (temp_f1_527 * temp_f1_527)) - 3.0)));
    } else if (var_f4_514 < M2C_BITWISE(f32, 0.0)) {
        var_f4_514 = __float_nan;
    } else {
        sp8 = var_f4_514;
        temp_r3_546 = M2C_BITWISE(s32, sp8) & 0x7F800000;
        switch (temp_r3_546) {                      /* switch 2; irregular */
        case 0x7F800000:                            /* switch 2 */
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_556 = 1;
            } else {
                var_r0_556 = 2;
            }
            break;
        case 0x0:                                   /* switch 2 */
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_556 = 5;
            } else {
                var_r0_556 = 3;
            }
            break;
        default:                                    /* switch 2 */
            var_r0_556 = 4;
            break;
        }
        if (var_r0_556 == 1) {
            var_f4_514 = __float_nan;
        }
    }
    temp_f3_580 = M2C_FIELD(this->unk0, f32 *, 8);
    temp_f2_582 = -((0.5f * this->unk178) - temp_f3_580);
    temp_f3_584 = -((0.2f * temp_f3_580) - temp_f2_582);
    temp_f28_587 = 1.0f / (temp_f3_584 - temp_f2_582);
    if ((var_f30_426 > temp_f3_584) && (var_f4_514 > temp_f3_584)) {
        this->unk10 |= 0x80;
    } else {
        this->unk10 &= 0xFFFFFF7F;
    }
    var_r28_603 = 0;
    var_r30_604 = 0;
loop_52:
    temp_r4_666 = this->unk188;
    if (var_r28_603 < temp_r4_666) {
        temp_f3_612 = this->unk19C;
        var_f0_625 = temp_f3_612 * ((temp_f28_587 * (var_f30_426 + (((f32) var_r28_603 * (var_f4_514 - var_f30_426)) / (f32) (temp_r4_666 - 1)))) + -((temp_f28_587 * temp_f3_584) - 1.0f));
        if (var_f0_625 < 1.0f) {

        } else {
            var_f0_625 = 1.0f;
        }
        if (var_f0_625 > 0.0f) {

        } else {
            var_f0_625 = 0.0f;
        }
        var_f1_639 = temp_f3_612 * var_f0_625;
        if (var_f1_639 < 1.0f) {

        } else {
            var_f1_639 = 1.0f;
        }
        if (var_f1_639 > 0.0f) {

        } else {
            var_f1_639 = 0.0f;
        }
        MKModel_SetAlpha(*(this->unk184 + (var_r30_604 + 0x48)), var_f1_639);
        MKModel_Draw(*(this->unk184 + (var_r30_604 + 0x48)), NULL);
        var_r28_603 += 1;
        var_r30_604 += 0x50;
        goto loop_52;
    }
}
#endif

#if 0 // DRAFT: illegal type
void RopeBridge::UpdatePlanks(int arg0, float arg1, float arg2) {
    f64 sp1E0;                                      /* compiler-managed */
    f64 sp1D8;
    f64 sp1D0;                                      /* compiler-managed */
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    MKVector3 sp1A8;
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
    MKVector3 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    MKVector3 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f32 spD0;
    f64 spC8;
    f32 spC0;
    f64 spB8;
    f32 spB0;
    f64 spA8;
    f32 spA0;
    f64 sp98;
    f32 sp90;
    f64 sp88;
    f32 sp80;
    f64 sp78;
    f32 sp70;
    f64 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f29_1237;
    f32 temp_f31_764;
    f32 temp_f3_1188;
    f32 temp_f3_1234;
    f32 temp_f3_1244;
    f32 temp_f3_1285;
    f32 temp_f3_961;
    f32 temp_f5_881;
    f32 temp_f5_958;
    f32 temp_f6_1192;
    f32 temp_f7_887;
    f32 temp_f7_968;
    f64 temp_f0_1075;
    f64 temp_f0_1133;
    f64 temp_f0_1162;
    f64 temp_f0_1293;
    f64 temp_f0_769;
    f64 temp_f0_802;
    f64 temp_f0_855;
    f64 temp_f4_997;
    f64 temp_f6_1239;
    f64 temp_f8_963;
    s32 temp_r0_1093;
    s32 temp_r0_1149;
    s32 temp_r0_723;
    s32 temp_r0_785;
    s32 temp_r0_840;
    s32 temp_r0_977;
    s32 temp_r7_1208;
    s32 temp_r7_722;
    s32 var_ctr_1198;
    s32 var_ctr_893;
    s32 var_r27_1066;
    s32 var_r27_1115;
    s32 var_r29_1067;
    s32 var_r29_1116;
    s32 var_r29_746;
    s32 var_r31_744;
    s32 var_r3_1203;
    s32 var_r3_1284;
    s32 var_r3_718;
    s32 var_r3_836;
    s32 var_r4_897;
    s32 var_r5_898;
    s32 var_r6_835;
    s32 var_r7_1283;
    s32 var_r7_717;
    s32 var_r8_1202;
    void *temp_r0_1159;
    void *temp_r0_798;
    void *temp_r0_852;
    void *temp_r3_1100;
    void *temp_r3_1141;
    void *temp_r3_1155;
    void *temp_r3_1166;
    void *temp_r3_1267;
    void *temp_r3_1277;
    void *temp_r3_777;
    void *temp_r3_792;
    void *temp_r3_806;
    void *temp_r4_1050;
    void *temp_r4_1060;
    void *temp_r4_1160;
    void *temp_r4_1212;
    void *temp_r4_1243;
    void *temp_r4_1288;
    void *temp_r4_1309;
    void *temp_r4_800;
    void *temp_r4_843;
    void *temp_r4_848;
    void *temp_r4_859;
    void *temp_r5_1071;
    void *temp_r5_1124;
    void *temp_r5_1210;
    void *temp_r5_1254;
    void *temp_r5_751;
    void *temp_r5_853;
    void *temp_r6_1023;
    void *temp_r6_1036;
    void *temp_r6_1207;
    void *temp_r6_1289;
    void *temp_r6_910;
    void *temp_r6_933;
    void *temp_r6_969;
    void *temp_r6_984;
    void *temp_r7_1007;
    void *temp_r7_908;
    void *temp_r7_931;
    void *temp_r8_905;
    void *temp_r8_928;

    if ((u8) this->unk1A0 == 1) {
        if ((u8) this->unk1A1 == 0) {
            var_r7_717 = 1;
            var_r3_718 = 0x48;
loop_4:
            if (var_r7_717 < (s32) (this->unk188 - 1)) {
                temp_r7_722 = var_r7_717;
                temp_r0_723 = var_r3_718 + 0x40;
                var_r7_717 += 1;
                var_r3_718 += 0x48;
                *(this->unk180 + temp_r0_723) = (0.137f * (f32) temp_r7_722) + M2C_FIELD(&gb, f32 *, 0x30C);
                goto loop_4;
            }
            this->unk1A1 = 1;
            return;
        }
        var_r31_744 = 1;
        var_r29_746 = 0x48;
loop_10:
        if (var_r31_744 < (s32) (this->unk188 - 1)) {
            temp_r5_751 = ((u8 *) this->unk180) + var_r29_746;
            if (M2C_FIELD(&gb, f32 *, 0x30C) >= M2C_FIELD(temp_r5_751, f32 *, 0x40)) {
                M2C_FIELD(temp_r5_751, f64 *, 0) = (f64) M2C_FIELD(temp_r5_751, f64 *, 0x10);
                M2C_FIELD(temp_r5_751, f64 *, 8) = (f64) M2C_FIELD(temp_r5_751, f64 *, 0x18);
                temp_f31_764 = gUpdateTimeDelta;
                sp1A8.operator*(arg2);
                temp_f0_769 = sp1A8 * (f64) temp_f31_764;
                spB8 = temp_f0_769;
                sp1B8 = temp_f0_769;
                temp_r3_777 = ((u8 *) this->unk180) + (var_r29_746 + 0x20);
                spC0 = sp1A8.unk8 * temp_f31_764;
                sp1C0 = (f64) spC0;
                M2C_FIELD(temp_r3_777, f64 *, 0) = (f64) (M2C_FIELD(temp_r3_777, f64 *, 0) - temp_f0_769);
                temp_r0_785 = var_r29_746 + 0x24;
                M2C_FIELD(temp_r3_777, f32 *, 8) = (f32) (M2C_FIELD(temp_r3_777, f32 *, 8) - (f32) sp1C0);
                temp_r3_792 = this->unk180;
                *(temp_r3_792 + temp_r0_785) = -((980.0f * gUpdateTimeDelta) - *(temp_r3_792 + temp_r0_785));
                temp_r0_798 = this->unk180;
                temp_r4_800 = ((u8 *) temp_r0_798) + (var_r29_746 + 0x20);
                temp_f0_802 = M2C_FIELD(temp_r4_800, f64 *, 0) * (f64) gUpdateTimeDelta;
                spA8 = temp_f0_802;
                temp_r3_806 = ((u8 *) temp_r0_798) + (var_r29_746 + 0x10);
                sp198 = temp_f0_802;
                spB0 = M2C_FIELD(temp_r4_800, f32 *, 8) * gUpdateTimeDelta;
                sp1A0 = (f64) spB0;
                M2C_FIELD(temp_r3_806, f64 *, 0) = (f64) (M2C_FIELD(temp_r3_806, f64 *, 0) + temp_f0_802);
                M2C_FIELD(temp_r3_806, f32 *, 8) = (f32) (M2C_FIELD(temp_r3_806, f32 *, 8) + (f32) sp1A0);
            }
            var_r31_744 += 1;
            var_r29_746 += 0x48;
            goto loop_10;
        }
        return;
    }
    if ((u8) this->unk1A8 == 1) {
        var_r6_835 = 1;
        var_r3_836 = 0x48;
loop_15:
        if (var_r6_835 < (s32) (this->unk188 - 1)) {
            temp_r0_840 = var_r3_836 + 0x24;
            temp_r4_843 = ((u8 *) this->unk180) + var_r3_836;
            M2C_FIELD(temp_r4_843, f64 *, 0) = (f64) M2C_FIELD(temp_r4_843, f64 *, 0x10);
            M2C_FIELD(temp_r4_843, f64 *, 8) = (f64) M2C_FIELD(temp_r4_843, f64 *, 0x18);
            temp_r4_848 = this->unk180;
            *(temp_r4_848 + temp_r0_840) = *(temp_r4_848 + temp_r0_840) - 32.666668f;
            temp_r0_852 = this->unk180;
            temp_r5_853 = ((u8 *) temp_r0_852) + (var_r3_836 + 0x20);
            temp_f0_855 = M2C_FIELD(temp_r5_853, f64 *, 0) * 5.059081113e-315;
            sp98 = temp_f0_855;
            temp_r4_859 = ((u8 *) temp_r0_852) + (var_r3_836 + 0x10);
            sp188 = temp_f0_855;
            spA0 = M2C_FIELD(temp_r5_853, f32 *, 8) * 0.033333335f;
            sp190 = (f64) spA0;
            M2C_FIELD(temp_r4_859, f64 *, 0) = (f64) (M2C_FIELD(temp_r4_859, f64 *, 0) + temp_f0_855);
            var_r6_835 += 1;
            var_r3_836 += 0x48;
            M2C_FIELD(temp_r4_859, f32 *, 8) = (f32) (M2C_FIELD(temp_r4_859, f32 *, 8) + (f32) sp190);
            goto loop_15;
        }
        temp_f5_881 = this->unk18C;
        temp_f7_887 = 2.0f * temp_f5_881;
        var_ctr_893 = arg0;
        if (arg0 > 0) {
            do {
                var_r4_897 = 1;
                var_r5_898 = 0x48;
loop_27:
                if (var_r4_897 < (s32) this->unk188) {
                    if (var_r4_897 < (s32) this->unk1A4) {
                        temp_r8_905 = this->unk180;
                        temp_r7_908 = ((u8 *) temp_r8_905) + (var_r5_898 + 0x10);
                        temp_r6_910 = ((u8 *) temp_r8_905) + (((var_r4_897 - 1) * 0x48) + 0x10);
                        sp88 = M2C_FIELD(temp_r6_910, f64 *, 0) - M2C_FIELD(temp_r7_908, f64 *, 0);
                        sp178 = sp88;
                        sp90 = M2C_FIELD(temp_r6_910, f32 *, 8) - M2C_FIELD(temp_r7_908, f32 *, 8);
                        sp1D8 = sp88;
                        sp180 = (f64) sp90;
                        sp1E0 = (f64) sp90;
                    } else {
                        temp_r8_928 = this->unk180;
                        temp_r7_931 = ((u8 *) temp_r8_928) + (var_r5_898 + 0x10);
                        temp_r6_933 = ((u8 *) temp_r8_928) + (((var_r4_897 + 1) * 0x48) + 0x10);
                        sp78 = M2C_FIELD(temp_r6_933, f64 *, 0) - M2C_FIELD(temp_r7_931, f64 *, 0);
                        sp168 = sp78;
                        sp80 = M2C_FIELD(temp_r6_933, f32 *, 8) - M2C_FIELD(temp_r7_931, f32 *, 8);
                        sp1D8 = sp78;
                        sp170 = (f64) sp80;
                        sp1E0 = (f64) sp80;
                    }
                    temp_f5_958 = ((((f32) sp1E0 * (f32) sp1E0) + (((f32) sp1D8 * (f32) sp1D8) + ((*(f32 *) ((u8 *) &sp1D8 + 0x4)) * (*(f32 *) ((u8 *) &sp1D8 + 0x4))))) * (1.0f / temp_f7_887)) + (temp_f5_881 - ((temp_f5_881 * temp_f5_881) / temp_f7_887));
                    temp_f3_961 = (0.4f * (temp_f5_958 - this->unk18C)) / temp_f5_958;
                    temp_f8_963 = sp1D8 * (f64) temp_f3_961;
                    sp1D8 = temp_f8_963;
                    temp_f7_968 = (f32) sp1E0 * temp_f3_961;
                    temp_r6_969 = ((u8 *) this->unk180) + (var_r5_898 + 0x10);
                    sp1E0 = temp_f7_968;
                    M2C_FIELD(temp_r6_969, f64 *, 0) = (f64) (M2C_FIELD(temp_r6_969, f64 *, 0) + temp_f8_963);
                    M2C_FIELD(temp_r6_969, f32 *, 8) = (f32) (M2C_FIELD(temp_r6_969, f32 *, 8) + temp_f7_968);
                    temp_r0_977 = this->unk1A4;
                    if (var_r4_897 < temp_r0_977) {
                        temp_r6_984 = ((u8 *) this->unk180) + (((var_r4_897 - 1) * 0x48) + 0x10);
                        M2C_FIELD(temp_r6_984, f64 *, 0) = (f64) (M2C_FIELD(temp_r6_984, f64 *, 0) - temp_f8_963);
                        M2C_FIELD(temp_r6_984, f32 *, 8) = (f32) (M2C_FIELD(temp_r6_984, f32 *, 8) - temp_f7_968);
                    } else if (var_r4_897 == temp_r0_977) {
                        temp_f4_997 = M2C_FIELD(&MKVector3::up, f64 *, 0) * (f64) temp_f3_961;
                        sp68 = temp_f4_997;
                        sp158 = temp_f4_997;
                        temp_r7_1007 = ((u8 *) this->unk180) + (((var_r4_897 - 1) * 0x48) + 0x10);
                        sp70 = MKVector3::up.unk8 * temp_f3_961;
                        sp160 = (f64) sp70;
                        M2C_FIELD(temp_r7_1007, f64 *, 0) = (f64) (M2C_FIELD(temp_r7_1007, f64 *, 0) - temp_f4_997);
                        M2C_FIELD(temp_r7_1007, f32 *, 8) = (f32) (M2C_FIELD(temp_r7_1007, f32 *, 8) - (f32) sp160);
                        temp_r6_1023 = ((u8 *) this->unk180) + (((var_r4_897 + 1) * 0x48) + 0x10);
                        M2C_FIELD(temp_r6_1023, f64 *, 0) = (f64) (M2C_FIELD(temp_r6_1023, f64 *, 0) - temp_f8_963);
                        M2C_FIELD(temp_r6_1023, f32 *, 8) = (f32) (M2C_FIELD(temp_r6_1023, f32 *, 8) - temp_f7_968);
                    } else {
                        temp_r6_1036 = ((u8 *) this->unk180) + (((var_r4_897 + 1) * 0x48) + 0x10);
                        M2C_FIELD(temp_r6_1036, f64 *, 0) = (f64) (M2C_FIELD(temp_r6_1036, f64 *, 0) - temp_f8_963);
                        M2C_FIELD(temp_r6_1036, f32 *, 8) = (f32) (M2C_FIELD(temp_r6_1036, f32 *, 8) - temp_f7_968);
                    }
                    var_r4_897 += 1;
                    var_r5_898 += 0x48;
                    goto loop_27;
                }
                temp_r4_1050 = this->unk180;
                M2C_FIELD(temp_r4_1050, f32 *, 0x10) = 0.0f;
                M2C_FIELD(temp_r4_1050, f32 *, 0x14) = 0.0f;
                M2C_FIELD(temp_r4_1050, f32 *, 0x18) = 0.0f;
                temp_r4_1060 = ((u8 *) this->unk180) + ((this->unk188 * 0x48) + 0x10);
                M2C_FIELD(temp_r4_1060, f64 *, 0) = (f64) this->unk170;
                M2C_FIELD(temp_r4_1060, f64 *, 8) = (f64) M2C_FIELD(this, f64 *, 0x178);
                var_ctr_893 -= 1;
            } while (var_ctr_893 != 0);
        }
        var_r27_1066 = 0;
        var_r29_1067 = 0;
loop_31:
        if (var_r27_1066 < (s32) this->unk188) {
            temp_r5_1071 = ((u8 *) this->unk180) + var_r29_1067;
            temp_f0_1075 = *(temp_r5_1071 + 0x10) - M2C_FIELD(temp_r5_1071, f64 *, 0);
            sp18 = temp_f0_1075;
            sp128 = temp_f0_1075;
            sp20 = M2C_FIELD(temp_r5_1071, f32 *, 0x18) - M2C_FIELD(temp_r5_1071, f32 *, 8);
            sp130 = (f64) sp20;
            sp138.operator*(1.0f);
            sp58 = sp138 * 5.46558974e-315;
            temp_r0_1093 = var_r29_1067 + 0x20;
            var_r27_1066 += 1;
            var_r29_1067 += 0x48;
            temp_r3_1100 = ((u8 *) this->unk180) + temp_r0_1093;
            M2C_FIELD(temp_r3_1100, f64 *, 0) = sp58;
            sp60 = sp138.unk8 * 29.999998f;
            sp148 = sp58;
            sp150 = (f64) sp60;
            M2C_FIELD(temp_r3_1100, f64 *, 8) = (f64) sp60;
            goto loop_31;
        }
        return;
    }
    var_r27_1115 = 1;
    var_r29_1116 = 0x48;
loop_35:
    if (var_r27_1115 < (s32) (this->unk188 - 1)) {
        temp_r5_1124 = ((u8 *) this->unk180) + var_r29_1116;
        M2C_FIELD(temp_r5_1124, f64 *, 0) = (f64) M2C_FIELD(temp_r5_1124, f64 *, 0x10);
        M2C_FIELD(temp_r5_1124, f64 *, 8) = (f64) M2C_FIELD(temp_r5_1124, f64 *, 0x18);
        sp108.operator*(arg2);
        temp_f0_1133 = sp108 * (f64) arg1;
        sp48 = temp_f0_1133;
        sp118 = temp_f0_1133;
        temp_r3_1141 = ((u8 *) this->unk180) + (var_r29_1116 + 0x20);
        sp50 = sp108.unk8 * arg1;
        sp120 = (f64) sp50;
        M2C_FIELD(temp_r3_1141, f64 *, 0) = (f64) (M2C_FIELD(temp_r3_1141, f64 *, 0) - temp_f0_1133);
        temp_r0_1149 = var_r29_1116 + 0x24;
        M2C_FIELD(temp_r3_1141, f32 *, 8) = (f32) (M2C_FIELD(temp_r3_1141, f32 *, 8) - (f32) sp120);
        temp_r3_1155 = this->unk180;
        *(temp_r3_1155 + temp_r0_1149) = *(temp_r3_1155 + temp_r0_1149) - (980.0f * arg1);
        temp_r0_1159 = this->unk180;
        temp_r4_1160 = ((u8 *) temp_r0_1159) + (var_r29_1116 + 0x20);
        temp_f0_1162 = M2C_FIELD(temp_r4_1160, f64 *, 0) * (f64) arg1;
        sp38 = temp_f0_1162;
        temp_r3_1166 = ((u8 *) temp_r0_1159) + (var_r29_1116 + 0x10);
        spF8 = temp_f0_1162;
        sp40 = M2C_FIELD(temp_r4_1160, f32 *, 8) * arg1;
        sp100 = (f64) sp40;
        M2C_FIELD(temp_r3_1166, f64 *, 0) = (f64) (M2C_FIELD(temp_r3_1166, f64 *, 0) + temp_f0_1162);
        var_r27_1115 += 1;
        var_r29_1116 += 0x48;
        M2C_FIELD(temp_r3_1166, f32 *, 8) = (f32) (M2C_FIELD(temp_r3_1166, f32 *, 8) + (f32) sp100);
        goto loop_35;
    }
    temp_f3_1188 = this->unk18C;
    temp_f6_1192 = 2.0f * temp_f3_1188;
    var_ctr_1198 = arg0;
    if (arg0 > 0) {
        do {
            var_r8_1202 = 0;
            var_r3_1203 = 0;
loop_39:
            if (var_r8_1202 < (s32) this->unk188) {
                temp_r6_1207 = this->unk180;
                temp_r7_1208 = (var_r8_1202 + 1) * 0x48;
                temp_r5_1210 = ((u8 *) temp_r6_1207) + (var_r3_1203 + 0x10);
                temp_r4_1212 = ((u8 *) temp_r6_1207) + (temp_r7_1208 + 0x10);
                spC8 = M2C_FIELD(temp_r4_1212, f64 *, 0) - M2C_FIELD(temp_r5_1210, f64 *, 0);
                sp1C8 = spC8;
                spD0 = M2C_FIELD(temp_r4_1212, f32 *, 8) - M2C_FIELD(temp_r5_1210, f32 *, 8);
                sp1D0 = (f64) spD0;
                temp_f3_1234 = ((((f32) sp1D0 * (f32) sp1D0) + (((f32) sp1C8 * (f32) sp1C8) + ((*(f32 *) ((u8 *) &sp1C8 + 0x4)) * (*(f32 *) ((u8 *) &sp1C8 + 0x4))))) * (1.0f / temp_f6_1192)) + (temp_f3_1188 - ((temp_f3_1188 * temp_f3_1188) / temp_f6_1192));
                temp_f29_1237 = (0.4f * (temp_f3_1234 - this->unk18C)) / temp_f3_1234;
                temp_f6_1239 = sp1C8 * (f64) temp_f29_1237;
                sp1C8 = temp_f6_1239;
                temp_r4_1243 = ((u8 *) temp_r6_1207) + (var_r3_1203 + 0x10);
                temp_f3_1244 = (f32) sp1D0 * temp_f29_1237;
                sp1D0 = temp_f3_1244;
                M2C_FIELD(temp_r4_1243, f64 *, 0) = (f64) (M2C_FIELD(temp_r4_1243, f64 *, 0) + temp_f6_1239);
                M2C_FIELD(temp_r4_1243, f32 *, 8) = (f32) (M2C_FIELD(temp_r4_1243, f32 *, 8) + temp_f3_1244);
                temp_r5_1254 = ((u8 *) this->unk180) + (temp_r7_1208 + 0x10);
                M2C_FIELD(temp_r5_1254, f64 *, 0) = (f64) (M2C_FIELD(temp_r5_1254, f64 *, 0) - temp_f6_1239);
                var_r8_1202 += 1;
                var_r3_1203 += 0x48;
                M2C_FIELD(temp_r5_1254, f32 *, 8) = (f32) (M2C_FIELD(temp_r5_1254, f32 *, 8) - temp_f3_1244);
                goto loop_39;
            }
            temp_r3_1267 = this->unk180;
            M2C_FIELD(temp_r3_1267, f32 *, 0x10) = 0.0f;
            M2C_FIELD(temp_r3_1267, f32 *, 0x14) = 0.0f;
            M2C_FIELD(temp_r3_1267, f32 *, 0x18) = 0.0f;
            temp_r3_1277 = ((u8 *) this->unk180) + ((this->unk188 * 0x48) + 0x10);
            M2C_FIELD(temp_r3_1277, f64 *, 0) = (f64) this->unk170;
            M2C_FIELD(temp_r3_1277, f64 *, 8) = (f64) M2C_FIELD(this, f64 *, 0x178);
            var_ctr_1198 -= 1;
        } while (var_ctr_1198 != 0);
    }
    var_r7_1283 = 0;
    var_r3_1284 = 0;
    temp_f3_1285 = 1.0f / arg1;
loop_43:
    if (var_r7_1283 < (s32) this->unk188) {
        temp_r4_1288 = this->unk180;
        temp_r6_1289 = ((u8 *) temp_r4_1288) + var_r3_1284;
        temp_f0_1293 = *(temp_r6_1289 + 0x10) - M2C_FIELD(temp_r6_1289, f64 *, 0);
        sp8 = temp_f0_1293;
        spD8 = temp_f0_1293;
        sp10 = M2C_FIELD(temp_r6_1289, f32 *, 0x18) - M2C_FIELD(temp_r6_1289, f32 *, 8);
        spE0 = (f64) sp10;
        sp28 = temp_f0_1293 * (f64) temp_f3_1285;
        temp_r4_1309 = ((u8 *) temp_r4_1288) + (var_r3_1284 + 0x20);
        var_r7_1283 += 1;
        var_r3_1284 += 0x48;
        M2C_FIELD(temp_r4_1309, f64 *, 0) = sp28;
        sp30 = (f32) spE0 * temp_f3_1285;
        spE8 = sp28;
        spF0 = (f64) sp30;
        M2C_FIELD(temp_r4_1309, f64 *, 8) = (f64) sp30;
        goto loop_43;
    }
}
#endif

#if 0 // DRAFT: illegal operand
void RopeBridge::UpdatePlankMatrices() {
    MKCollisionResult sp330;
    Matrix sp2F0;
    MKVector3 sp2E0;                                /* compiler-managed */
    f32 sp2DC;
    f32 sp2D8;
    f32 sp2D4;
    f32 sp2D0;
    f32 sp2CC;
    f32 sp2C8;
    f32 sp2C4;
    f32 sp2C0;
    f32 sp2BC;
    f32 sp2B8;
    f32 sp2B4;
    f32 sp2B0;
    M2C_UNK sp2AC;
    f64 sp2A0;                                      /* compiler-managed */
    f64 sp298;                                      /* compiler-managed */
    f64 sp290;
    f64 sp288;
    f64 sp280;
    f64 sp278;
    f64 *sp270;
    s32 sp26C;
    s32 sp268;
    f64 sp260;
    f64 sp258;
    f64 sp250;
    f64 sp248;
    f64 sp240;
    f64 sp238;
    f64 sp230;
    f64 sp228;
    f64 sp220;
    f64 sp218;
    f64 sp210;
    f64 sp208;
    MKVector3 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    MKVector3 sp1A8;
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    MKVector3 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    MKVector3 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f32 sp120;
    f32 sp11C;
    f32 sp118;
    f32 sp110;
    f32 sp10C;
    f32 sp108;
    f32 sp100;
    f32 spFC;
    f32 spF8;
    f32 spF0;
    f64 spE8;
    f32 spE0;
    f64 spD8;
    f32 spD0;
    f32 spCC;
    f32 spC8;
    f32 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB0;
    f64 spA8;
    f32 spA0;
    f64 sp98;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
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
    f32 temp_f0_1969;
    f32 temp_f1_1970;
    f32 temp_f2_1972;
    f32 temp_f3_1968;
    f32 temp_f4_1971;
    f32 temp_f5_1546;
    f32 temp_f5_1966;
    f32 temp_f6_1544;
    f32 temp_f7_1711;
    f32 temp_f7_1783;
    f32 temp_f7_1852;
    f32 var_f2_1535;
    f32 var_f4_1469;
    f64 temp_f0_1607;
    f64 temp_f0_1657;
    f64 temp_f0_1691;
    f64 temp_f0_1763;
    f64 temp_f0_1832;
    f64 temp_f1_1474;
    f64 temp_f1_1480;
    f64 temp_f1_1484;
    s32 temp_r3_1503;
    s32 temp_r3_1678;
    s32 var_r0_1513;
    s32 var_r24_1369;
    s32 var_r25_1368;
    s32 var_r28_1367;
    void *temp_r3_1424;
    void *temp_r3_1447;
    void *temp_r3_1633;
    void *temp_r3_1661;
    void *temp_r3_1943;
    void *temp_r3_1984;
    void *temp_r4_1373;
    void *temp_r4_1423;
    void *temp_r4_1445;
    void *temp_r4_1635;
    void *temp_r4_1688;
    void *temp_r4_1760;
    void *temp_r4_1829;
    void *temp_r4_1902;
    void *temp_r5_1419;
    void *temp_r5_1442;
    void *temp_r5_1686;
    void *temp_r5_1759;
    void *temp_r5_1828;
    void *temp_r6_1683;
    void *temp_r6_1755;
    void *temp_r6_1824;
    void *var_r27_1897;

    var_r28_1367 = 0;
    var_r25_1368 = 0;
    var_r24_1369 = 0;
loop_40:
    if (var_r28_1367 < (s32) this->unk188) {
        temp_r4_1373 = ((u8 *) this->unk184) + var_r24_1369;
        if ((u32) M2C_FIELD(temp_r4_1373, u32 *, 0x40) != (void *) (((u8 *) temp_r4_1373) + 0x20)) {
            sp2F0.InverseSimple(MKModel_GetWorldMatrix(M2C_FIELD(temp_r4_1373, MKModel **, 0x48)));
        }
        M2C_STRUCT_COPY((s32) &sp2AC + 4, MKModel_GetWorldMatrix(*(this->unk184 + (var_r24_1369 + 0x48))) - 4 + 4, 0x40);
        sp100 = 0.0f;
        spF8 = 1.0f;
        spFC = 0.0f;
        sp260 = (f64) sp100;
        sp258 = (f64) spF8;
        sp2B0 = (f32) sp258;
        sp2B4 = (*(f32 *) ((u8 *) &sp258 + 0x4));
        sp2B8 = (f32) sp260;
        sp2BC = 0.0f;
        if (var_r28_1367 == (s32) (this->unk1A4 - 1)) {
            temp_r5_1419 = this->unk180;
            temp_r4_1423 = ((u8 *) temp_r5_1419) + (((var_r28_1367 - 2) * 0x48) + 0x10);
            temp_r3_1424 = ((u8 *) temp_r5_1419) + (((var_r28_1367 - 1) * 0x48) + 0x10);
            spE8 = M2C_FIELD(temp_r3_1424, f64 *, 0) - M2C_FIELD(temp_r4_1423, f64 *, 0);
            sp248 = spE8;
            spF0 = M2C_FIELD(temp_r3_1424, f32 *, 8) - M2C_FIELD(temp_r4_1423, f32 *, 8);
            sp298 = spE8;
            sp250 = (f64) spF0;
            sp2A0 = (f64) spF0;
        } else {
            temp_r5_1442 = this->unk180;
            temp_r4_1445 = ((u8 *) temp_r5_1442) + (var_r25_1368 + 0x10);
            temp_r3_1447 = ((u8 *) temp_r5_1442) + (((var_r28_1367 + 1) * 0x48) + 0x10);
            spD8 = M2C_FIELD(temp_r3_1447, f64 *, 0) - M2C_FIELD(temp_r4_1445, f64 *, 0);
            sp238 = spD8;
            spE0 = M2C_FIELD(temp_r3_1447, f32 *, 8) - M2C_FIELD(temp_r4_1445, f32 *, 8);
            sp298 = spD8;
            sp240 = (f64) spE0;
            sp2A0 = (f64) spE0;
        }
        sp298 = 0.0f;
        var_f4_1469 = ((f32) sp2A0 * (f32) sp2A0) + (0.0f + ((*(f32 *) ((u8 *) &sp290 + 0xc)) * (*(f32 *) ((u8 *) &sp290 + 0xc))));
        if (var_f4_1469 > 0.000001f) {
            if (var_f4_1469 > 0.0f) {
                temp_f1_1474 = __frsqrte(var_f4_1469);
                temp_f1_1480 = 0.5 * temp_f1_1474 * -(((f64) var_f4_1469 * (temp_f1_1474 * temp_f1_1474)) - 3.0);
                temp_f1_1484 = 0.5 * temp_f1_1480 * -(((f64) var_f4_1469 * (temp_f1_1480 * temp_f1_1480)) - 3.0);
                var_f4_1469 = (f32) ((f64) var_f4_1469 * (0.5 * temp_f1_1484 * -(((f64) var_f4_1469 * (temp_f1_1484 * temp_f1_1484)) - 3.0)));
            } else if (var_f4_1469 < M2C_BITWISE(f32, 0.0)) {
                var_f4_1469 = __float_nan;
            } else {
                sp10 = var_f4_1469;
                temp_r3_1503 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_1503) {             /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_1513 = 1;
                    } else {
                        var_r0_1513 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_1513 = 5;
                    } else {
                        var_r0_1513 = 3;
                    }
                    break;
                default:
                    var_r0_1513 = 4;
                    break;
                }
                if (var_r0_1513 == 1) {
                    var_f4_1469 = __float_nan;
                }
            }
            var_f2_1535 = 1.0f / var_f4_1469;
        } else {
            var_f2_1535 = 0.0f;
        }
        temp_f6_1544 = (*(f32 *) ((u8 *) &sp290 + 0xc)) * var_f2_1535;
        temp_f5_1546 = (f32) sp2A0 * var_f2_1535;
        spC8 = 0.0f;
        spCC = temp_f6_1544;
        spD0 = temp_f5_1546;
        spC0 = -temp_f6_1544;
        sp228 = (f64) spC8;
        sp230 = (f64) spD0;
        sp220 = (f64) spC0;
        spB8 = 0.0f;
        spBC = temp_f5_1546;
        sp2D0 = (f32) sp228;
        sp218 = (f64) spB8;
        sp2D4 = (*(f32 *) ((u8 *) &sp228 + 0x4));
        sp2D8 = (f32) sp230;
        sp2DC = 0.0f;
        sp2C0 = (f32) sp218;
        sp2C4 = (*(f32 *) ((u8 *) &sp218 + 0x4));
        sp2C8 = (f32) sp220;
        sp2CC = 0.0f;
        sp298 *= var_f2_1535;
        (*(f32 *) ((u8 *) &sp290 + 0xc)) = temp_f6_1544;
        sp2A0 = temp_f5_1546;
        ((Matrix *) &sp2B0)->RotateRoll((Matrix *) &sp2B0, *(this->unk184 + (var_r24_1369 + 8)));
        ((Matrix *) &sp2B0)->Multiply3x3((Matrix *) &sp2B0, &this->unk110);
        if (((u8) this->unk1A8 != 0) && (MKCollision_SphereCollide(sp2E0, 50.0f, &sp330, 1, (MKCollisionMode) 7, 0x7FFFFFFE) != 0)) {
            sp1F8.operator*(30.000002f);
            temp_f0_1607 = sp2E0 + M2C_BITWISE(f64, sp1F8);
            spA8 = temp_f0_1607;
            sp208 = temp_f0_1607;
            spB0 = sp2E0.unk8 + sp1F8.unk8;
            sp210 = (f64) spB0;
            sp2E0 = (f32) sp208;
            sp2E0.unk4 = (*(f32 *) ((u8 *) &sp208 + 0x4));
            sp2E0.unk8 = (f32) sp210;
            sp2E0.unkC = 1.0f;
            temp_r3_1633 = this->unk180;
            sp58 = -MKVector3::up.unk0;
            temp_r4_1635 = ((u8 *) temp_r3_1633) + (var_r25_1368 + 0x20);
            sp5C = -MKVector3::up.unk4;
            sp60 = -MKVector3::up.unk8;
            sp50 = -M2C_FIELD(temp_r4_1635, f32 *, 8);
            sp48 = -M2C_FIELD(temp_r4_1635, f32 *, 0);
            sp4C = -M2C_FIELD(temp_r4_1635, f32 *, 4);
            sp1C8 = (f64) sp58;
            sp1D8 = (f64) sp48;
            sp1D0 = (f64) sp60;
            sp1E0 = (f64) sp50;
            temp_f0_1657 = (f64) sp48 * sp1C8;
            sp98 = temp_f0_1657;
            temp_r3_1661 = ((u8 *) temp_r3_1633) + (var_r25_1368 + 0x20);
            M2C_FIELD(temp_r3_1661, f64 *, 0) = temp_f0_1657;
            sp1E8 = temp_f0_1657;
            spA0 = (f32) sp1E0 * (f32) sp1D0;
            sp1F0 = (f64) spA0;
            M2C_FIELD(temp_r3_1661, f64 *, 8) = (f64) spA0;
        }
        if ((var_r28_1367 == 0) || (var_r28_1367 == (s32) (this->unk188 - 1)) || (temp_r3_1678 = this->unk1A4, ((var_r28_1367 == temp_r3_1678) != 0))) {
            temp_r6_1683 = this->unk180;
            temp_r5_1686 = ((u8 *) temp_r6_1683) + (var_r25_1368 + 0x10);
            temp_r4_1688 = ((u8 *) temp_r6_1683) + (((var_r28_1367 + 1) * 0x48) + 0x10);
            temp_f0_1691 = M2C_FIELD(temp_r4_1688, f64 *, 0) + M2C_FIELD(temp_r5_1686, f64 *, 0);
            sp38 = temp_f0_1691;
            sp198 = temp_f0_1691;
            sp40 = M2C_FIELD(temp_r4_1688, f32 *, 8) + M2C_FIELD(temp_r5_1686, f32 *, 8);
            sp1A0 = (f64) sp40;
            sp1A8.operator*(0.5f);
            temp_f7_1711 = M2C_BITWISE(f32, sp1A8);
            sp2E0.unkC = 1.0f;
            sp88 = this->unk80 + ((sp1A8.unk8 * this->unk70) + ((temp_f7_1711 * this->unk50) + (sp1A8.unk4 * this->unk60)));
            sp8C = this->unk84 + ((sp1A8.unk8 * this->unk74) + ((temp_f7_1711 * this->unk54) + (sp1A8.unk4 * this->unk64)));
            sp90 = this->unk88 + ((sp1A8.unk8 * this->unk78) + ((temp_f7_1711 * this->unk58) + (sp1A8.unk4 * this->unk68)));
            sp1B8 = (f64) sp88;
            sp1C0 = (f64) sp90;
            sp2E0 = (f32) sp1B8;
            sp2E0.unk4 = (*(f32 *) ((u8 *) &sp1B8 + 0x4));
            sp2E0.unk8 = (f32) sp1C0;
        } else if (var_r28_1367 == (s32) (temp_r3_1678 - 1)) {
            temp_r6_1755 = this->unk180;
            temp_r5_1759 = ((u8 *) temp_r6_1755) + (((var_r28_1367 - 2) * 0x48) + 0x10);
            temp_r4_1760 = ((u8 *) temp_r6_1755) + (((var_r28_1367 - 1) * 0x48) + 0x10);
            temp_f0_1763 = M2C_FIELD(temp_r4_1760, f64 *, 0) + M2C_FIELD(temp_r5_1759, f64 *, 0);
            sp28 = temp_f0_1763;
            sp168 = temp_f0_1763;
            sp30 = M2C_FIELD(temp_r4_1760, f32 *, 8) + M2C_FIELD(temp_r5_1759, f32 *, 8);
            sp170 = (f64) sp30;
            sp178.operator*(0.5f);
            temp_f7_1783 = M2C_BITWISE(f32, sp178);
            sp2E0.unkC = 1.0f;
            sp78 = this->unk80 + ((sp178.unk8 * this->unk70) + ((temp_f7_1783 * this->unk50) + (sp178.unk4 * this->unk60)));
            sp7C = this->unk84 + ((sp178.unk8 * this->unk74) + ((temp_f7_1783 * this->unk54) + (sp178.unk4 * this->unk64)));
            sp80 = this->unk88 + ((sp178.unk8 * this->unk78) + ((temp_f7_1783 * this->unk58) + (sp178.unk4 * this->unk68)));
            sp188 = (f64) sp78;
            sp190 = (f64) sp80;
            sp2E0 = (f32) sp188;
            sp2E0.unk4 = (*(f32 *) ((u8 *) &sp188 + 0x4));
            sp2E0.unk8 = (f32) sp190;
        } else {
            temp_r6_1824 = this->unk180;
            temp_r5_1828 = ((u8 *) temp_r6_1824) + (((var_r28_1367 - 1) * 0x48) + 0x10);
            temp_r4_1829 = ((u8 *) temp_r6_1824) + (((var_r28_1367 + 1) * 0x48) + 0x10);
            temp_f0_1832 = M2C_FIELD(temp_r4_1829, f64 *, 0) + M2C_FIELD(temp_r5_1828, f64 *, 0);
            sp18 = temp_f0_1832;
            sp138 = temp_f0_1832;
            sp20 = M2C_FIELD(temp_r4_1829, f32 *, 8) + M2C_FIELD(temp_r5_1828, f32 *, 8);
            sp140 = (f64) sp20;
            sp148.operator*(0.5f);
            temp_f7_1852 = M2C_BITWISE(f32, sp148);
            sp2E0.unkC = 1.0f;
            sp68 = this->unk80 + ((sp148.unk8 * this->unk70) + ((temp_f7_1852 * this->unk50) + (sp148.unk4 * this->unk60)));
            sp6C = this->unk84 + ((sp148.unk8 * this->unk74) + ((temp_f7_1852 * this->unk54) + (sp148.unk4 * this->unk64)));
            sp70 = this->unk88 + ((sp148.unk8 * this->unk78) + ((temp_f7_1852 * this->unk58) + (sp148.unk4 * this->unk68)));
            sp158 = (f64) sp68;
            sp160 = (f64) sp70;
            sp2E0 = (f32) sp158;
            sp2E0.unk4 = (*(f32 *) ((u8 *) &sp158 + 0x4));
            sp2E0.unk8 = (f32) sp160;
        }
        MKModel_SetWorldMatrix(*(this->unk184 + (var_r24_1369 + 0x48)), *((Matrix *) &sp2B0));
        var_r27_1897 = *(this->unk184 + (var_r24_1369 + 0x40));
loop_38:
        if (var_r27_1897 != (void *) (((u8 *) this->unk184) + (var_r24_1369 + 0x20))) {
            temp_r4_1902 = M2C_FIELD(M2C_FIELD(var_r27_1897, void **, 0x18), void **, 8);
            sp128 = M2C_FIELD(temp_r4_1902, f64 *, 0x30);
            sp130 = M2C_FIELD(temp_r4_1902, f64 *, 0x38);
            sp118 = sp2F0.unk30 + (((f32) sp130 * sp2F0.unk20) + (((f32) sp128 * M2C_BITWISE(f32, sp2F0)) + ((*(f32 *) ((u8 *) &sp128 + 0x4)) * sp2F0.unk10)));
            sp11C = sp2F0.unk34 + (((f32) sp130 * sp2F0.unk24) + (((f32) sp128 * sp2F0.unk4) + ((*(f32 *) ((u8 *) &sp128 + 0x4)) * sp2F0.unk14)));
            sp120 = sp2F0.unk38 + (((f32) sp130 * sp2F0.unk28) + (((f32) sp128 * sp2F0.unk8) + ((*(f32 *) ((u8 *) &sp128 + 0x4)) * sp2F0.unk18)));
            sp288 = (f64) sp118;
            sp290 = (f64) sp120;
            temp_r3_1943 = MKModel_GetWorldMatrix(*(var_r24_1369 + (((u8 *) this->unk184) + 0x48)));
            temp_f5_1966 = M2C_FIELD(temp_r3_1943, f32 *, 0x30);
            temp_f3_1968 = M2C_FIELD(temp_r3_1943, f32 *, 0x34);
            temp_f0_1969 = ((f32) sp290 * M2C_FIELD(temp_r3_1943, f32 *, 0x28)) + (((f32) sp288 * M2C_FIELD(temp_r3_1943, f32 *, 8)) + ((*(f32 *) ((u8 *) &sp288 + 0x4)) * M2C_FIELD(temp_r3_1943, f32 *, 0x18)));
            temp_f1_1970 = M2C_FIELD(temp_r3_1943, f32 *, 0x38);
            temp_f4_1971 = temp_f5_1966 + (((f32) sp290 * M2C_FIELD(temp_r3_1943, f32 *, 0x20)) + (((f32) sp288 * M2C_FIELD(temp_r3_1943, f32 *, 0)) + ((*(f32 *) ((u8 *) &sp288 + 0x4)) * M2C_FIELD(temp_r3_1943, f32 *, 0x10))));
            temp_f2_1972 = temp_f3_1968 + (((f32) sp290 * M2C_FIELD(temp_r3_1943, f32 *, 0x24)) + (((f32) sp288 * M2C_FIELD(temp_r3_1943, f32 *, 4)) + ((*(f32 *) ((u8 *) &sp288 + 0x4)) * M2C_FIELD(temp_r3_1943, f32 *, 0x14))));
            sp26C = 0;
            sp108 = temp_f4_1971;
            sp10C = temp_f2_1972;
            sp110 = temp_f1_1970 + temp_f0_1969;
            sp278 = (f64) sp108;
            sp280 = (f64) sp110;
            sp268 = 0x9B;
            sp270 = &sp278;
            temp_r3_1984 = M2C_FIELD(var_r27_1897, void **, 0x18);
            M2C_FIELD(M2C_FIELD(temp_r3_1984, void **, 0x44), M2C_UNK (**)(void *, s32 *, M2C_UNK, f64, f32, f32, f32, f32, f32, f32), 0x2C)(temp_r3_1984, &sp268, 0, (f64) sp108, temp_f2_1972, temp_f3_1968, temp_f4_1971, temp_f5_1966, (f32) sp290, (f32) sp288);
            var_r27_1897 = M2C_FIELD(var_r27_1897, void **, 0x20);
            goto loop_38;
        }
        var_r28_1367 += 1;
        var_r25_1368 += 0x48;
        var_r24_1369 += 0x50;
        goto loop_40;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to
void RopeBridge::ApplyForce(const MKVector3 &arg0, const MKVector3 &arg1) {
    f64 sp80;
    f64 sp78;
    f64 sp70;                                       /* compiler-managed */
    f64 sp68;                                       /* compiler-managed */
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f10_2036;
    f32 temp_f11_2039;
    f32 temp_f11_2068;
    f32 temp_f12_2041;
    f32 temp_f13_2045;
    f32 temp_f1_2037;
    f32 temp_f26_2033;
    f32 temp_f27_2055;
    f32 temp_f28_2053;
    f32 temp_f29_2047;
    f32 temp_f2_2044;
    f32 temp_f2_2098;
    f32 temp_f2_2113;
    f32 temp_f30_2043;
    f32 temp_f31_2051;
    f32 temp_f3_2110;
    f32 temp_f4_2112;
    f32 temp_f5_2032;
    f32 temp_f5_2102;
    f32 temp_f6_2034;
    f32 var_f0_2173;
    f64 *temp_r4_2120;
    f64 temp_f1_2117;
    s32 temp_r0_2090;
    s32 temp_r5_2162;
    s32 var_ctr_2093;
    s32 var_r4_2092;
    s32 var_r7_2091;
    void *temp_r3_2171;
    void *temp_r4_2146;
    void *temp_r4_2166;
    void *temp_r5_2097;
    void *temp_r6_2061;

    temp_f5_2032 = arg0.unk4;
    temp_f26_2033 = this->unkE8;
    temp_f6_2034 = this->unkE0;
    temp_f10_2036 = arg0.unk0;
    temp_f1_2037 = this->unkD8;
    temp_f11_2039 = this->unkE4;
    temp_f12_2041 = arg0.unk8;
    temp_f30_2043 = arg1.unk4;
    temp_f2_2044 = this->unkF8;
    temp_f13_2045 = this->unkD0;
    temp_f29_2047 = this->unkD4;
    temp_f31_2051 = this->unkF0;
    temp_f28_2053 = arg1.unk0;
    temp_f27_2055 = this->unkF4;
    sp40 = this->unk108 + ((temp_f12_2041 * temp_f2_2044) + ((temp_f10_2036 * temp_f1_2037) + (temp_f5_2032 * temp_f26_2033)));
    temp_r6_2061 = this->unk180;
    sp80 = (f64) sp40;
    temp_f11_2068 = arg1.unk8;
    sp38 = this->unk100 + ((temp_f12_2041 * temp_f31_2051) + ((temp_f10_2036 * temp_f13_2045) + (temp_f5_2032 * temp_f6_2034)));
    sp3C = this->unk104 + ((temp_f12_2041 * temp_f27_2055) + ((temp_f10_2036 * temp_f29_2047) + (temp_f5_2032 * temp_f11_2039)));
    sp30 = (temp_f11_2068 * temp_f2_2044) + ((temp_f28_2053 * temp_f1_2037) + (temp_f30_2043 * temp_f26_2033));
    sp28 = (temp_f11_2068 * temp_f31_2051) + ((temp_f28_2053 * temp_f13_2045) + (temp_f30_2043 * temp_f6_2034));
    sp2C = (temp_f11_2068 * temp_f27_2055) + ((temp_f28_2053 * temp_f29_2047) + (temp_f30_2043 * temp_f11_2039));
    sp78 = (f64) sp38;
    sp68 = (f64) sp28;
    sp70 = (f64) sp30;
    if (!((f32) sp80 < M2C_FIELD(temp_r6_2061, f32 *, 0x18)) && (temp_r0_2090 = this->unk188, var_r7_2091 = 0, var_r4_2092 = 0, var_ctr_2093 = temp_r0_2090, ((temp_r0_2090 > 0) != 0))) {
loop_2:
        temp_r5_2097 = ((u8 *) temp_r6_2061) + var_r4_2092;
        temp_f2_2098 = M2C_FIELD(temp_r5_2097, f32 *, 0x60);
        if (temp_f2_2098 >= (f32) sp80) {
            temp_f5_2102 = M2C_FIELD(temp_r5_2097, f32 *, 0x18);
            temp_f3_2110 = ((f32) sp80 - temp_f5_2102) / (temp_f2_2098 - temp_f5_2102);
            sp68 = (f32) sp68 * 0.2f;
            temp_f4_2112 = 1.0f - temp_f3_2110;
            temp_f2_2113 = (f32) sp70 * 0.2f;
            sp70 = temp_f2_2113;
            temp_f1_2117 = (f64) sp68 * (f64) temp_f4_2112;
            sp18 = temp_f1_2117;
            temp_r4_2120 = ((u8 *) temp_r5_2097) + 0x20;
            sp20 = temp_f2_2113 * temp_f4_2112;
            sp58 = temp_f1_2117;
            sp60 = (f64) sp20;
            *temp_r4_2120 += sp58;
            M2C_FIELD(temp_r5_2097, f32 *, 0x28) = (f32) (M2C_FIELD(temp_r5_2097, f32 *, 0x28) + (f32) sp60);
            sp8 = (f64) sp68 * (f64) temp_f3_2110;
            sp10 = temp_f2_2113 * temp_f3_2110;
            sp48 = sp8;
            temp_r4_2146 = ((u8 *) this->unk180) + (((var_r7_2091 + 1) * 0x48) + 0x20);
            sp50 = (f64) sp10;
            M2C_FIELD(temp_r4_2146, f64 *, 0) = (f64) (M2C_FIELD(temp_r4_2146, f64 *, 0) + sp48);
            M2C_FIELD(temp_r4_2146, f32 *, 8) = (f32) (M2C_FIELD(temp_r4_2146, f32 *, 8) + (f32) sp50);
            if ((var_r7_2091 != 0) && (var_r7_2091 != (s32) (this->unk188 - 1))) {
                temp_r5_2162 = var_r7_2091 * 0x50;
                temp_r4_2166 = ((u8 *) this->unk184) + temp_r5_2162;
                M2C_FIELD(temp_r4_2166, f32 *, 0x4C) = (f32) ((0.02f * (f32) sp78) + M2C_FIELD(temp_r4_2166, f32 *, 0x4C));
                temp_r3_2171 = this->unk184;
                var_f0_2173 = *(temp_r3_2171 + (temp_r5_2162 + 0x4C));
                if (var_f0_2173 < 10.0f) {

                } else {
                    var_f0_2173 = 10.0f;
                }
                if (var_f0_2173 > -10.0f) {

                } else {
                    var_f0_2173 = -10.0f;
                }
                M2C_FIELD((((u8 *) temp_r3_2171) + temp_r5_2162), f32 *, 0x4C) = var_f0_2173;
            }
        } else {
            var_r7_2091 += 1;
            var_r4_2092 += 0x48;
            var_ctr_2093 -= 1;
            if (var_ctr_2093 == 0) {

            } else {
                goto loop_2;
            }
        }
    }
}
#endif

#if 0 // DRAFT: illegal type
void RopeBridge::HighDetailUpdate() {
    f32 temp_f2_2232;
    f32 temp_f5_2226;
    f32 var_f0_2241;
    s32 var_r4_2224;
    void *var_r5_2229;

    UpdatePlanks(0x1E, 0.033333335f, 0.0f);
    var_r4_2224 = 1;
    temp_f5_2226 = -ROPEBRIDGE_MAXROLL;
    var_r5_2229 = ((u8 *) this->unk184) + 0x50;
loop_10:
    if (var_r4_2224 < (s32) (this->unk188 - 1)) {
        temp_f2_2232 = M2C_FIELD(var_r5_2229, f32 *, 0x4C);
        if (temp_f2_2232 != 0.0f) {
            M2C_FIELD(var_r5_2229, f32 *, 8) = (f32) ((temp_f2_2232 * gUpdateTimeDelta) + M2C_FIELD(var_r5_2229, f32 *, 8));
            M2C_FIELD(var_r5_2229, f32 *, 0x4C) = 0.0f;
        }
        var_f0_2241 = M2C_FIELD(var_r5_2229, f32 *, 8);
        if (var_f0_2241 < ROPEBRIDGE_MAXROLL) {

        } else {
            var_f0_2241 = ROPEBRIDGE_MAXROLL;
        }
        if (var_f0_2241 > temp_f5_2226) {

        } else {
            var_f0_2241 = temp_f5_2226;
        }
        M2C_FIELD(var_r5_2229, f32 *, 8) = var_f0_2241;
        var_r4_2224 += 1;
        M2C_FIELD(var_r5_2229, f32 *, 8) = (f32) (0.5f * ((0.5f * (M2C_FIELD(var_r5_2229, f32 *, -0x48) + M2C_FIELD(var_r5_2229, f32 *, 0x58))) + M2C_FIELD(var_r5_2229, f32 *, 8)));
        var_r5_2229 += 0x50;
        goto loop_10;
    }
}
#endif

#if 0 // DRAFT: illegal type
void RopeBridge::LowDetailUpdate() {
    s32 temp_r0_2294;
    s32 var_r3_2290;
    s32 var_r5_2289;

    UpdatePlanks(0xA, 0.018333334f, 8.0f);
    var_r5_2289 = 1;
    var_r3_2290 = 0x50;
loop_2:
    if (var_r5_2289 < (s32) (this->unk188 - 1)) {
        temp_r0_2294 = var_r3_2290 + 8;
        var_r5_2289 += 1;
        var_r3_2290 += 0x50;
        *(this->unk184 + temp_r0_2294) = 0.0f;
        goto loop_2;
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__float_nan'
void *RopeBridge::Update() {
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    f32 temp_f0_2336;
    f32 temp_f1_2447;
    f32 temp_f2_2322;
    f32 var_f31_2327;
    f32 var_f4_2381;
    f64 temp_f1_2358;
    f64 temp_f1_2384;
    f64 temp_f1_2390;
    f64 temp_f1_2394;
    s32 temp_r3_2346;
    s32 temp_r3_2413;
    s32 var_r0_2423;
    void *temp_r3_2357;
    void *temp_r4_2356;

    MKProp::Update();
    temp_f2_2322 = this->unk19C;
    if (temp_f2_2322 != 1.0f) {
        var_f31_2327 = (1.5f * gUpdateTimeDelta) + temp_f2_2322;
        Level::GetWorldInfo();
        if (var_f31_2327 < 1.0f) {

        } else {
            var_f31_2327 = 1.0f;
        }
        temp_f0_2336 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 8);
        if (var_f31_2327 > temp_f0_2336) {

        } else {
            var_f31_2327 = temp_f0_2336;
        }
        this->unk19C = var_f31_2327;
    } else {
        temp_r3_2346 = this->unk10;
        if (temp_r3_2346 & 0x4000) {
            this->unk10 = temp_r3_2346 & 0xFFFFBFFF;
        }
    }
    temp_r4_2356 = ((u8 *) this->unk8) + 0x30;
    temp_r3_2357 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
    temp_f1_2358 = M2C_FIELD(temp_r3_2357, f64 *, 0x30);
    sp20 = temp_f1_2358;
    sp28 = M2C_FIELD(temp_r3_2357, f64 *, 0x38);
    sp10 = temp_f1_2358 - M2C_FIELD(temp_r4_2356, f64 *, 0);
    sp30 = sp10;
    sp18 = (f32) sp28 - M2C_FIELD(temp_r4_2356, f32 *, 8);
    sp38 = (f64) sp18;
    var_f4_2381 = ((f32) sp38 * (f32) sp38) + (((f32) sp30 * (f32) sp30) + ((*(f32 *) ((u8 *) &sp30 + 0x4)) * (*(f32 *) ((u8 *) &sp30 + 0x4))));
    if (var_f4_2381 > 0.0f) {
        temp_f1_2384 = __frsqrte(var_f4_2381);
        temp_f1_2390 = 0.5 * temp_f1_2384 * -(((f64) var_f4_2381 * (temp_f1_2384 * temp_f1_2384)) - 3.0);
        temp_f1_2394 = 0.5 * temp_f1_2390 * -(((f64) var_f4_2381 * (temp_f1_2390 * temp_f1_2390)) - 3.0);
        var_f4_2381 = (f32) ((f64) var_f4_2381 * (0.5 * temp_f1_2394 * -(((f64) var_f4_2381 * (temp_f1_2394 * temp_f1_2394)) - 3.0)));
    } else if (var_f4_2381 < M2C_BITWISE(f32, 0.0)) {
        var_f4_2381 = __float_nan;
    } else {
        sp8 = var_f4_2381;
        temp_r3_2413 = M2C_BITWISE(s32, sp8) & 0x7F800000;
        switch (temp_r3_2413) {                     /* irregular */
        case 0x7F800000:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_2423 = 1;
            } else {
                var_r0_2423 = 2;
            }
            break;
        case 0x0:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_2423 = 5;
            } else {
                var_r0_2423 = 3;
            }
            break;
        default:
            var_r0_2423 = 4;
            break;
        }
        if (var_r0_2423 == 1) {
            var_f4_2381 = __float_nan;
        }
    }
    temp_f1_2447 = 0.5f * this->unk190;
    if (var_f4_2381 < (1000.0f + temp_f1_2447)) {
        HighDetailUpdate();
        UpdatePlankMatrices();
    } else if (var_f4_2381 < (10000.0f + temp_f1_2447)) {
        LowDetailUpdate();
        UpdatePlankMatrices();
    }
    if (((u8) this->unk1A8 == 0) && ((s32) this->unk1A4 != -1)) {
        this->unk1AC -= gUpdateTimeDelta;
        if (this->unk1AC < 0.0f) {
            DetachBridgeEnthusiasts();
            this->unk1A8 = 1;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'sp1B0'
f32 RopeBridge::Resolve() {
    s8 sp2B8;
    s32 sp2B4;
    s32 sp2B0;
    s32 sp2AC;
    f32 sp2A8;
    s32 sp2A4;
    s8 sp2A3;
    s8 sp2A2;
    s16 sp2A0;
    f32 sp29C;
    f32 sp298;
    f32 sp294;
    f32 sp290;
    f32 sp28C;
    f32 sp288;
    f32 sp280;
    f32 sp27C;
    f32 sp278;
    f32 sp270;
    f32 sp26C;
    f32 sp268;
    f64 sp260;
    f64 sp258;
    f64 sp250;
    f64 sp248;
    f64 sp240;
    f64 sp238;
    f64 sp230;
    f64 sp228;
    f64 sp220;
    f64 sp218;
    f64 sp210;
    f64 sp208;
    f64 sp200;
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f32 sp140;
    f32 sp13C;
    f32 sp138;
    f32 sp134;
    f32 sp130;
    f32 sp12C;
    f32 sp128;
    f32 sp120;
    f32 sp11C;
    f32 sp118;
    f32 sp110;
    f64 sp108;
    f32 sp100;
    f32 spFC;
    f32 spF8;
    f32 spF0;
    f64 spE8;
    f32 spE0;
    f32 spDC;
    f32 spD8;
    f32 spD0;
    f32 spCC;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB0;
    f64 spA8;
    f32 spA0;
    f64 sp98;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp80;
    f64 sp78;
    f32 sp70;
    f64 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f64 sp10;
    f64 sp8;
    f32 temp_f0_2601;
    f32 temp_f0_2705;
    f32 temp_f10_2718;
    f32 temp_f11_2723;
    f32 temp_f12_2696;
    f32 temp_f13_2593;
    f32 temp_f1_2604;
    f32 temp_f1_2713;
    f32 temp_f26_2597;
    f32 temp_f27_2592;
    f32 temp_f2_2595;
    f32 temp_f2_2721;
    f32 temp_f31_2824;
    f32 temp_f3_2598;
    f32 temp_f3_2727;
    f32 temp_f4_2602;
    f32 temp_f4_2702;
    f32 temp_f5_2576;
    f32 temp_f5_2712;
    f32 temp_f6_2578;
    f32 temp_f6_2720;
    f32 temp_f7_2585;
    f32 temp_f7_2725;
    f32 temp_f8_2588;
    f32 temp_f8_2700;
    f32 temp_f9_2711;
    f64 temp_f0_2571;
    f64 temp_f0_2682;
    f64 temp_f0_2694;
    f64 temp_f13_2692;
    f64 temp_f13_2749;
    s32 temp_r0_2858;
    s32 temp_r3_2864;
    s32 var_r29_2797;
    s32 var_r31_2796;

    sp138 = 0.0f;
    sp13C = -1.0f;
    sp140 = -1.0f;
    sp258 = (f64) sp138;
    sp260 = (f64) sp140;
    sp128 = 1.0f;
    sp12C = 1.0f;
    sp120 = -(f32) sp260;
    sp130 = 1.0f;
    sp134 = 1.0f;
    sp118 = -(f32) sp258;
    sp11C = -(*(f32 *) ((u8 *) &sp258 + 0x4));
    sp268 = 0.0f;
    sp26C = 0.0f;
    sp270 = 0.0f;
    sp278 = 0.0f;
    sp27C = 0.0f;
    sp280 = 0.0f;
    sp288 = 0.0f;
    sp28C = 0.0f;
    sp290 = 0.0f;
    sp294 = 1.0f;
    sp298 = 0.0f;
    sp29C = 0.0f;
    sp2A0 = 0;
    sp2A2 = 0;
    sp2A3 = 0;
    sp2A4 = 0;
    sp2A8 = 3.4028235e38f;
    sp2AC = 0;
    sp2B0 = 0;
    sp2B4 = -1;
    sp2B8 = 0;
    sp248 = (f64) sp128;
    sp250 = (f64) sp130;
    sp1C8 = (f64) sp118;
    sp1D0 = (f64) sp120;
    temp_f0_2571 = sp1C8 * 5.46558975e-315;
    sp108 = temp_f0_2571;
    temp_f5_2576 = this->unk60;
    sp1D8 = temp_f0_2571;
    temp_f6_2578 = this->unk50;
    sp110 = (f32) sp1D0 * 30.000002f;
    sp1E0 = (f64) sp110;
    temp_f7_2585 = this->unk70;
    temp_f8_2588 = this->unk80;
    spF8 = temp_f8_2588 + (((f32) sp1E0 * temp_f7_2585) + (((f32) sp1D8 * temp_f6_2578) + ((*(f32 *) ((u8 *) &sp1D8 + 0x4)) * temp_f5_2576)));
    temp_f27_2592 = this->unk64;
    temp_f13_2593 = this->unk68;
    temp_f2_2595 = this->unk54;
    temp_f26_2597 = this->unk58;
    temp_f3_2598 = this->unk74;
    temp_f0_2601 = this->unk78;
    temp_f4_2602 = this->unk84;
    temp_f1_2604 = this->unk88;
    spFC = temp_f4_2602 + (((f32) sp1E0 * temp_f3_2598) + (((f32) sp1D8 * temp_f2_2595) + ((*(f32 *) ((u8 *) &sp1D8 + 0x4)) * temp_f27_2592)));
    sp100 = temp_f1_2604 + (((f32) sp1E0 * temp_f0_2601) + (((f32) sp1D8 * temp_f26_2597) + ((*(f32 *) ((u8 *) &sp1D8 + 0x4)) * temp_f13_2593)));
    sp238 = (f64) spF8;
    sp240 = (f64) sp100;
    spE8 = sp258 * 5.49408334e-315;
    spF0 = (f32) sp260 * 50.0f;
    sp1B8 = spE8;
    sp1C0 = (f64) spF0;
    spD8 = temp_f8_2588 + (((f32) sp1C0 * temp_f7_2585) + (((f32) sp1B8 * temp_f6_2578) + ((*(f32 *) ((u8 *) &sp1B8 + 0x4)) * temp_f5_2576)));
    spDC = temp_f4_2602 + (((f32) sp1C0 * temp_f3_2598) + (((f32) sp1B8 * temp_f2_2595) + ((*(f32 *) ((u8 *) &sp1B8 + 0x4)) * temp_f27_2592)));
    spE0 = temp_f1_2604 + (((f32) sp1C0 * temp_f0_2601) + (((f32) sp1B8 * temp_f26_2597) + ((*(f32 *) ((u8 *) &sp1B8 + 0x4)) * temp_f13_2593)));
    sp228 = (f64) spD8;
    sp230 = (f64) spE0;
    if (MKCollision_RayCollide(*((MKVector3 *) &sp238), *((MKVector3 *) &sp228), (MKCollisionResult *) &sp268, (MKCollisionMode) 7, 0) != 0) {
        Tools_GroundColor((MKCollisionResult *) &sp1A8);
        sp248 = sp1A8;
        sp250 = sp1B0;
    }
    spC8 = 0.0f;
    spCC = -1.0f;
    spD0 = 1.0f;
    spB8 = 1.0f;
    spBC = 1.0f;
    spC0 = 1.0f;
    spC4 = 1.0f;
    sp218 = (f64) spC8;
    sp220 = (f64) spD0;
    sp208 = (f64) spB8;
    sp210 = (f64) spC0;
    temp_f0_2682 = sp218 * 5.46558975e-315;
    spA8 = temp_f0_2682;
    sp188 = temp_f0_2682;
    spB0 = (f32) sp220 * 30.000002f;
    sp190 = (f64) spB0;
    temp_f13_2692 = this->unk170;
    temp_f0_2694 = temp_f13_2692 - temp_f0_2682;
    sp98 = temp_f0_2694;
    temp_f12_2696 = this->unk178;
    temp_f8_2700 = this->unk60;
    sp198 = temp_f0_2694;
    temp_f4_2702 = this->unk64;
    spA0 = temp_f12_2696 - (f32) sp190;
    temp_f0_2705 = this->unk68;
    temp_f9_2711 = this->unk50;
    temp_f5_2712 = this->unk54;
    temp_f1_2713 = this->unk58;
    sp1A0 = (f64) spA0;
    temp_f10_2718 = this->unk70;
    temp_f6_2720 = this->unk74;
    temp_f2_2721 = this->unk78;
    temp_f11_2723 = this->unk80;
    temp_f7_2725 = this->unk84;
    temp_f3_2727 = this->unk88;
    sp88 = temp_f11_2723 + (((f32) sp1A0 * temp_f10_2718) + (((f32) sp198 * temp_f9_2711) + ((*(f32 *) ((u8 *) &sp198 + 0x4)) * temp_f8_2700)));
    sp8C = temp_f7_2725 + (((f32) sp1A0 * temp_f6_2720) + (((f32) sp198 * temp_f5_2712) + ((*(f32 *) ((u8 *) &sp198 + 0x4)) * temp_f4_2702)));
    sp90 = temp_f3_2727 + (((f32) sp1A0 * temp_f2_2721) + (((f32) sp198 * temp_f1_2713) + ((*(f32 *) ((u8 *) &sp198 + 0x4)) * temp_f0_2705)));
    sp1F8 = (f64) sp88;
    sp200 = (f64) sp90;
    sp78 = sp218 * 5.49408334e-315;
    sp80 = (f32) sp220 * 50.0f;
    sp168 = sp78;
    sp170 = (f64) sp80;
    temp_f13_2749 = temp_f13_2692 + sp168;
    sp68 = temp_f13_2749;
    sp70 = temp_f12_2696 + (f32) sp170;
    sp178 = temp_f13_2749;
    sp180 = (f64) sp70;
    sp58 = temp_f11_2723 + (((f32) sp180 * temp_f10_2718) + (((f32) sp178 * temp_f9_2711) + ((*(f32 *) ((u8 *) &sp178 + 0x4)) * temp_f8_2700)));
    sp5C = temp_f7_2725 + (((f32) sp180 * temp_f6_2720) + (((f32) sp178 * temp_f5_2712) + ((*(f32 *) ((u8 *) &sp178 + 0x4)) * temp_f4_2702)));
    sp60 = temp_f3_2727 + (((f32) sp180 * temp_f2_2721) + (((f32) sp178 * temp_f1_2713) + ((*(f32 *) ((u8 *) &sp178 + 0x4)) * temp_f0_2705)));
    sp1E8 = (f64) sp58;
    sp1F0 = (f64) sp60;
    if (MKCollision_RayCollide(*((MKVector3 *) &sp1F8), *((MKVector3 *) &sp1E8), (MKCollisionResult *) &sp268, (MKCollisionMode) 7, 0) != 0) {
        Tools_GroundColor((MKCollisionResult *) &sp158);
        sp208 = sp158;
        sp210 = sp160;
    }
    var_r31_2796 = 0;
    var_r29_2797 = 0;
loop_6:
    temp_r3_2864 = this->unk188;
    if (var_r31_2796 < temp_r3_2864) {
        temp_f31_2824 = (f32) var_r31_2796 / (f32) (temp_r3_2864 - 1);
        sp28 = sp208 - sp248;
        sp30 = sp210 - sp250;
        sp48 = sp28;
        sp50 = sp30;
        sp18 = sp48 * (f64) temp_f31_2824;
        sp20 = sp50 * (f64) temp_f31_2824;
        sp38 = sp18;
        sp40 = sp20;
        sp8 = sp248 + sp38;
        sp10 = sp250 + sp40;
        sp148 = sp8;
        sp150 = sp10;
        MKModel_SetColor(*(this->unk184 + (var_r29_2797 + 0x48)), *((MKVector4 *) &sp148));
        temp_r0_2858 = var_r29_2797 + 0x14;
        var_r29_2797 += 0x50;
        *(this->unk184 + temp_r0_2858) = 1;
        var_r31_2796 += 1;
        goto loop_6;
    }
    return M2C_BITWISE(f32, temp_r3_2864);
}
#endif

#if 0 // DRAFT: undefined identifier 'MKVector'
void RopeBridge::BuildBridgeStartPosition() {
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f64 sp50;
    f64 sp48;
    MKVector3 sp38;
    MKVector3 sp28;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f1_2925;
    f32 temp_f4_2917;
    f32 var_f3_2915;
    s32 temp_r0_3014;
    s32 temp_r4_2964;
    s32 temp_r4_2990;
    s32 temp_r5_2966;
    s32 var_r27_2995;
    s32 var_r28_2908;
    s32 var_r30_2906;
    s32 var_r30_2996;
    s32 var_r31_2997;
    void *temp_r3_2971;
    void *temp_r3_3004;
    void *temp_r3_3015;
    void *temp_r4_2980;
    void *temp_r5_2985;

    var_r30_2906 = 0;
    var_r28_2908 = 0;
loop_5:
    temp_r4_2990 = this->unk188;
    if (var_r30_2906 < (s32) (temp_r4_2990 + 1)) {
        var_f3_2915 = 0.0f;
        temp_f4_2917 = this->unk194;
        temp_f1_2925 = (f32) var_r30_2906 / (f32) temp_r4_2990;
        if (var_f3_2915 > temp_f4_2917) {

        } else {
            var_f3_2915 = temp_f4_2917;
        }
        MKVector(0.0f, temp_f1_2925 * (1.0f - temp_f1_2925) * 4.07f * (this->unk178 * var_f3_2915), 0.0f);
        sp28.operator*((f32) var_r30_2906);
        sp38.operator/((f32) this->unk188);
        sp8 = sp38 - sp18;
        temp_r4_2964 = var_r28_2908 + 0x20;
        temp_r5_2966 = var_r28_2908 + 0x30;
        var_r30_2906 += 1;
        temp_r3_2971 = ((u8 *) this->unk180) + (var_r28_2908 + 0x10);
        var_r28_2908 += 0x48;
        M2C_FIELD(temp_r3_2971, f64 *, 0) = sp8;
        sp10 = sp38.unk8 - sp20;
        sp48 = sp8;
        M2C_FIELD(temp_r3_2971, f64 *, 8) = (f64) sp10;
        sp50 = (f64) sp10;
        temp_r4_2980 = ((u8 *) this->unk180) + temp_r4_2964;
        M2C_FIELD(temp_r4_2980, f32 *, 0) = 0.0f;
        M2C_FIELD(temp_r4_2980, f32 *, 4) = 0.0f;
        M2C_FIELD(temp_r4_2980, f32 *, 8) = 0.0f;
        temp_r5_2985 = ((u8 *) this->unk180) + temp_r5_2966;
        M2C_FIELD(temp_r5_2985, f32 *, 0) = 0.0f;
        M2C_FIELD(temp_r5_2985, f32 *, 4) = 0.0f;
        M2C_FIELD(temp_r5_2985, f32 *, 8) = 0.0f;
        goto loop_5;
    }
    var_r27_2995 = 0;
    var_r30_2996 = 0;
    var_r31_2997 = 0;
loop_8:
    if (var_r27_2995 < (s32) this->unk188) {
        KDMath_GetYaw((Matrix *) &this->unk50);
        sp5C = M2C_ERROR(/* Read from unset register $f1 */);
        temp_r3_3004 = ((u8 *) this->unk180) + var_r31_2997;
        sp60 = 0.0f;
        temp_r0_3014 = var_r30_2996 + 0x4C;
        temp_r3_3015 = ((u8 *) this->unk184) + var_r30_2996;
        var_r30_2996 += 0x50;
        sp58 = (f32) atan2(temp_r3_3004, M2C_FIELD(temp_r3_3004, f32 *, 0x5C) - M2C_FIELD(temp_r3_3004, f32 *, 0x14), this->unk18C);
        var_r27_2995 += 1;
        var_r31_2997 += 0x48;
        M2C_FIELD(temp_r3_3015, f64 *, 0) = (f64) sp58;
        M2C_FIELD(temp_r3_3015, f64 *, 8) = (f64) sp60;
        *(this->unk184 + temp_r0_3014) = 0.0f;
        goto loop_8;
    }
    KDMath_GetYaw((Matrix *) &this->unk50);
    this->unk110.SetRotationYaw(M2C_ERROR(/* Read from unset register $f1 */));
    UpdatePlankMatrices();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKHeap *' to
void RopeBridge::SetUpCullingLocalToWorld() {
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f0_3106;
    f32 temp_f29_3094;
    f32 temp_f29_3123;
    f32 temp_f2_3171;
    f32 temp_f4_3121;
    f32 var_f1_3125;
    f32 var_f2_3100;
    f32 var_f30_3105;
    f32 var_f3_3113;
    f64 temp_f0_3150;

    temp_f29_3094 = *MKModel_GetBoundingVolume(M2C_FIELD(this->unk184, MKModel **, 0x48), (SubObjectType) 0, -1);
    var_f2_3100 = M2C_FIELD(MKModel_GetBoundingVolume(M2C_FIELD(this->unk184, MKModel **, 0x48), (SubObjectType) 0, -1), f32 *, 0x10) - temp_f29_3094;
    if (var_f2_3100 < 0.0f) {
        var_f2_3100 = -var_f2_3100;
    }
    var_f30_3105 = 0.0f;
    temp_f0_3106 = M2C_FIELD(this, f32 *, 0x174);
    if (var_f30_3105 > temp_f0_3106) {

    } else {
        var_f30_3105 = temp_f0_3106;
    }
    var_f3_3113 = 0.0f;
    if (var_f3_3113 < temp_f0_3106) {

    } else {
        var_f3_3113 = temp_f0_3106;
    }
    temp_f4_3121 = this->unk178;
    temp_f29_3123 = -((0.2f * temp_f4_3121) - var_f3_3113);
    sp68 = var_f2_3100;
    var_f1_3125 = var_f30_3105 - temp_f29_3123;
    if (var_f1_3125 < 0.0f) {
        var_f1_3125 = -var_f1_3125;
    }
    sp6C = var_f1_3125;
    sp70 = temp_f4_3121;
    sp8 = (f64) sp68 * 5.222099017e-315;
    sp10 = temp_f4_3121 * 0.5f;
    sp48 = sp8;
    sp50 = (f64) sp10;
    this->unk90.Scale3x3((Matrix *) &this->unk50, *((MKVector3 *) &sp48));
    temp_f0_3150 = M2C_FIELD(this, f64 *, 0x150) + M2C_FIELD(this, f64 *, 0x160);
    sp28 = temp_f0_3150;
    sp38 = temp_f0_3150;
    sp30 = this->unk158 + this->unk168;
    sp40 = (f64) sp30;
    sp18 = temp_f0_3150 * 5.222099017e-315;
    sp58 = sp18;
    temp_f2_3171 = (0.5f * (var_f30_3105 + temp_f29_3123)) + this->unk154;
    sp20 = (f32) sp40 * 0.5f;
    this->unk90.unk30 = (f32) sp58;
    sp60 = (f64) sp20;
    this->unk90.unk34 = temp_f2_3171;
    (*(f32 *) ((u8 *) &sp58 + 0x4)) = temp_f2_3171;
    this->unk90.unk38 = (f32) sp60;
    this->unk90.unk3C = 1.0f;
    this->unk8 = &this->unk90;
}
#endif

void RopeBridge::CalculateTranformationMatrices() {
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f3_3253;
    f32 temp_f6_3259;
    f32 temp_f7_3265;

    sp28 = M2C_FIELD(this, f64 *, 0x160) - M2C_FIELD(this, f64 *, 0x150);
    sp58 = sp28;
    sp30 = this->unk168 - this->unk158;
    (*(f32 *) ((u8 *) &sp58 + 0x4)) = 0.0f;
    sp60 = (f64) sp30;
    ((Matrix *) &this->unk50)->SetIdentity();
    sp18 = -(f32) sp58;
    sp1C = -(*(f32 *) ((u8 *) &sp58 + 0x4));
    sp20 = -(f32) sp60;
    sp48 = (f64) sp18;
    sp50 = (f64) sp20;
    KDMath_BuildMatrixFromFwd((Matrix *) &this->unk50, *((MKVector3 *) &sp48), NULL);
    this->unk80 = this->unk150;
    this->unk84 = this->unk154;
    this->unk88 = this->unk158;
    this->unk8C = 1.0f;
    ((Matrix *) &this->unkD0)->Inverse((Matrix *) &this->unk50);
    temp_f3_3253 = this->unk164;
    temp_f6_3259 = this->unk160;
    temp_f7_3265 = this->unk168;
    sp8 = this->unk100 + ((temp_f7_3265 * this->unkF0) + ((temp_f6_3259 * this->unkD0) + (temp_f3_3253 * this->unkE0)));
    spC = this->unk104 + ((temp_f7_3265 * this->unkF4) + ((temp_f6_3259 * this->unkD4) + (temp_f3_3253 * this->unkE4)));
    sp10 = this->unk108 + ((temp_f7_3265 * this->unkF8) + ((temp_f6_3259 * this->unkD8) + (temp_f3_3253 * this->unkE8)));
    this->unk170 = (f64) sp8;
    sp38 = (f64) sp8;
    sp40 = (f64) sp10;
    M2C_FIELD(this, f64 *, 0x178) = (f64) sp10;
}

#if 0 // DRAFT: undefined identifier '__float_nan'
s32 RopeBridge::LoadDone() {
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    f32 temp_f3_3406;
    f32 var_f4_3326;
    f64 temp_f1_3329;
    f64 temp_f1_3335;
    f64 temp_f1_3339;
    s32 temp_r0_3458;
    s32 temp_r0_3542;
    s32 temp_r25_3470;
    s32 temp_r27_3431;
    s32 temp_r3_3358;
    s32 var_r0_3368;
    s32 var_r29_3449;
    s32 var_r31_3448;
    s32 var_r3_3526;
    s32 var_r6_3525;
    void *temp_r26_3484;
    void *temp_r28_3480;
    void *temp_r4_3531;
    void *temp_r4_3547;
    void *temp_r4_3552;
    void *temp_r4_3554;
    void *temp_r5_3537;
    void *temp_r5_3553;
    void *temp_r6_3469;
    void *var_r3_3439;

    MKProp::LoadDone();
    sp10 = M2C_FIELD(this, f64 *, 0x160) - M2C_FIELD(this, f64 *, 0x150);
    sp20 = sp10;
    sp18 = this->unk168 - this->unk158;
    sp28 = (f64) sp18;
    var_f4_3326 = ((f32) sp28 * (f32) sp28) + (((f32) sp20 * (f32) sp20) + ((*(f32 *) ((u8 *) &sp20 + 0x4)) * (*(f32 *) ((u8 *) &sp20 + 0x4))));
    if (var_f4_3326 > 0.0f) {
        temp_f1_3329 = __frsqrte(var_f4_3326);
        temp_f1_3335 = 0.5 * temp_f1_3329 * -(((f64) var_f4_3326 * (temp_f1_3329 * temp_f1_3329)) - 3.0);
        temp_f1_3339 = 0.5 * temp_f1_3335 * -(((f64) var_f4_3326 * (temp_f1_3335 * temp_f1_3335)) - 3.0);
        var_f4_3326 = (f32) ((f64) var_f4_3326 * (0.5 * temp_f1_3339 * -(((f64) var_f4_3326 * (temp_f1_3339 * temp_f1_3339)) - 3.0)));
    } else if (var_f4_3326 < M2C_BITWISE(f32, 0.0)) {
        var_f4_3326 = __float_nan;
    } else {
        sp8 = var_f4_3326;
        temp_r3_3358 = M2C_BITWISE(s32, sp8) & 0x7F800000;
        switch (temp_r3_3358) {                     /* irregular */
        case 0x7F800000:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_3368 = 1;
            } else {
                var_r0_3368 = 2;
            }
            break;
        case 0x0:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_3368 = 5;
            } else {
                var_r0_3368 = 3;
            }
            break;
        default:
            var_r0_3368 = 4;
            break;
        }
        if (var_r0_3368 == 1) {
            var_f4_3326 = __float_nan;
        }
    }
    this->unk190 = var_f4_3326;
    this->unk188 = (s32) (0.5f + (this->unk190 / this->unk18C)) - 1;
    temp_f3_3406 = this->unk18C;
    this->unk18C = temp_f3_3406 * (this->unk190 / (temp_f3_3406 * (f32) (this->unk188 + 1)));
    operator new[]((this->unk188 * 0x50) + 0x10, NULL, 0);
    this->unk184 = __construct_new_array();
    temp_r27_3431 = (this->unk188 + 1) * 0x48;
    if (MKHeap::Current() != NULL) {
        var_r3_3439 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r27_3431, NULL, 0);
    } else {
        var_r3_3439 = malloc(temp_r27_3431);
    }
    this->unk180 = var_r3_3439;
    var_r31_3448 = 0;
    var_r29_3449 = 0;
loop_22:
    if (var_r31_3448 < (s32) this->unk188) {
        temp_r0_3458 = var_r29_3449 + 0x48;
        *(this->unk184 + temp_r0_3458) = MKModel_Create(this->unk198, NULL, 2, NULL);
        temp_r6_3469 = ((u8 *) this->unk184) + (var_r29_3449 + 0x10);
        temp_r25_3470 = MKModel_GetSubObjectIndex(*(this->unk184 + temp_r0_3458), (SubObjectType) 0, "C_Collide");
        M2C_FIELD(temp_r6_3469, s32 *, 0) = 0;
        M2C_FIELD(temp_r6_3469, s8 *, 4) = 1;
        M2C_FIELD(temp_r6_3469, RopeBridge **, 8) = this;
        M2C_FIELD(temp_r6_3469, s32 *, 0xC) = 0;
        *(this->unk184 + (var_r29_3449 + 0x14)) = 0;
        temp_r28_3480 = checked_cast<RopeBridgeDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        temp_r26_3484 = ((u8 *) this->unk184) + var_r29_3449;
        ((MKCollisionManager *) (M2C_FIELD(*gMK, MKCollisionManager *(**)(void **), 0x84)(gMK)))->AddModel(M2C_FIELD(temp_r26_3484, MKModel **, 0x48), temp_r25_3470, (MKCollisionMode) 7, ((u8 *) temp_r26_3484) + 0x10, M2C_FIELD(temp_r28_3480, u32 *, 0x60));
        MKModel_EnableSubObject(*(this->unk184 + (var_r29_3449 + 0x48)), (SubObjectType) 0, temp_r25_3470, 0U, 1U);
        var_r31_3448 += 1;
        var_r29_3449 += 0x50;
        goto loop_22;
    }
    CalculateTranformationMatrices();
    BuildBridgeStartPosition();
    this->unk18C *= 1.0f + this->unk194;
    M2C_FIELD(this->unk0, M2C_UNK **, 0x1C) = &boundingVolume;
    SetUpCullingLocalToWorld();
    var_r6_3525 = 1;
    var_r3_3526 = 0x48;
loop_25:
    if (var_r6_3525 < (s32) (this->unk188 - 1)) {
        temp_r4_3531 = ((u8 *) this->unk180) + var_r3_3526;
        M2C_FIELD(temp_r4_3531, f64 *, 0) = (f64) M2C_FIELD(temp_r4_3531, f64 *, 0x10);
        M2C_FIELD(temp_r4_3531, f64 *, 8) = (f64) M2C_FIELD(temp_r4_3531, f64 *, 0x18);
        temp_r5_3537 = ((u8 *) this->unk180) + (var_r3_3526 + 0x20);
        M2C_FIELD(temp_r5_3537, f64 *, 0) = (f64) (M2C_FIELD(temp_r5_3537, f64 *, 0) - M2C_FIELD(temp_r5_3537, f64 *, 0));
        temp_r0_3542 = var_r3_3526 + 0x24;
        M2C_FIELD(temp_r5_3537, f32 *, 8) = (f32) (M2C_FIELD(temp_r5_3537, f32 *, 8) - M2C_FIELD(temp_r5_3537, f32 *, 8));
        temp_r4_3547 = this->unk180;
        *(temp_r4_3547 + temp_r0_3542) = *(temp_r4_3547 + temp_r0_3542) - 686.0f;
        temp_r4_3552 = ((u8 *) this->unk180) + var_r3_3526;
        temp_r5_3553 = ((u8 *) temp_r4_3552) + 0x20;
        temp_r4_3554 = ((u8 *) temp_r4_3552) + 0x10;
        M2C_FIELD(temp_r4_3554, f64 *, 0) = (f64) (M2C_FIELD(temp_r4_3554, f64 *, 0) + M2C_FIELD(temp_r5_3553, f64 *, 0));
        var_r6_3525 += 1;
        var_r3_3526 += 0x48;
        M2C_FIELD(temp_r4_3554, f32 *, 8) = (f32) (M2C_FIELD(temp_r4_3554, f32 *, 8) + M2C_FIELD(temp_r5_3553, f32 *, 8));
        goto loop_25;
    }
    UpdatePlankMatrices();
}
#endif

#if 0 // DRAFT: function call 'stricmp(const char[10])' does not match
u8 RopeBridge::LoadStartAndEnd(MKIniLine *arg0) {
    MKIniLine *temp_r3_3651;
    MKIniLine *temp_r3_3667;

    arg0->GetFieldName();
    if (stricmp("waypoints") == 0) {
        temp_r3_3651 = arg0->unkC->GetSubLine(arg0);
        temp_r3_3651->GetFieldName();
        if (stricmp("waypoint") == 0) {
            temp_r3_3651->AsVector3(0, (MKVector3 *) &this->unk150);
        }
        temp_r3_3667 = temp_r3_3651->unkC->GetNextLine(temp_r3_3651);
        temp_r3_3667->GetFieldName();
        if (stricmp("waypoint") == 0) {
            temp_r3_3667->AsVector3(0, (MKVector3 *) &this->unk160);
        }
        return 1U;
    }
    return 0U;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to
s32 RopeBridge::LoadLine(MKIniLine *arg0) {
    s32 var_r31_3702;

    var_r31_3702 = 0;
    if ((MKProp::LoadLine(arg0) != 0) || (LoadStartAndEnd(arg0) != 0) || (arg0->LoadString("plankModel", &this->unk198, 1) != 0) || (arg0->LoadFloat("plankSpacing", &this->unk18C, 0) != 0) || (arg0->LoadFloat("sagAmount", &this->unk194, 0) != 0)) {
        var_r31_3702 = 1;
    }
    return var_r31_3702;
}
#endif

#if 0 // DRAFT: illegal type
void RopeBridge::Deinit() {
    s32 spC;
    s32 sp8;
    MKModel *temp_r3_3782;
    s32 var_r26_3761;
    void *temp_r0_3757;
    void *temp_r28_3802;
    void *temp_r3_3770;
    void *var_r27_3760;

    temp_r0_3757 = this->unk184;
    if (temp_r0_3757 != NULL) {
        var_r27_3760 = temp_r0_3757;
        var_r26_3761 = 0;
loop_8:
        if (var_r26_3761 < (s32) this->unk188) {
loop_4:
            if (M2C_FIELD(var_r27_3760, void **, 0x40) != (void *) (((u8 *) var_r27_3760) + 0x20)) {
                temp_r3_3770 = M2C_FIELD(M2C_FIELD(var_r27_3760, void **, 0x40), void **, 0x18);
                spC = 0;
                sp8 = 0x9C;
                M2C_FIELD(M2C_FIELD(temp_r3_3770, void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(temp_r3_3770, &sp8);
                goto loop_4;
            }
            temp_r3_3782 = M2C_FIELD(var_r27_3760, MKModel **, 0x48);
            if (temp_r3_3782 != NULL) {
                MKModel_Destroy(temp_r3_3782);
            }
            var_r26_3761 += 1;
            M2C_FIELD(var_r27_3760, MKModel **, 0x48) = NULL;
            var_r27_3760 += 0x50;
            goto loop_8;
        }
        __destroy_new_array(this->unk184, &RopeBridge::BridgePiece::~BridgePiece);
        this->unk184 = NULL;
    }
    temp_r28_3802 = this->unk180;
    if (temp_r28_3802 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r28_3802, NULL, 0);
        } else {
            free(temp_r28_3802);
        }
        this->unk180 = NULL;
    }
    MKProp::Deinit();
}
#endif

void RopeBridge::Init() {
    MKProp::Init();
    this->unk198 = NULL;
    this->unk150 = 0.0f;
    this->unk154 = 0.0f;
    this->unk158 = 0.0f;
    this->unk160 = 0.0f;
    this->unk164 = 0.0f;
    this->unk168 = 0.0f;
    this->unk18C = 55.0f;
    this->unk194 = 0.15f;
    this->unk1A0 = 0;
    this->unk1A1 = 0;
    this->unk1A4 = -1;
    this->unk1A8 = 0;
    this->unk1AC = 0.0f;
}

s32 RopeBridgeDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_3874;

    var_r31_3874 = 0;
    if ((MKPropDescriptor::LoadLine(arg0) != 0) || (KDProp_LoadMaterialID(arg0, "materialID", (int *) &this->unk60) != 0)) {
        var_r31_3874 = 1;
    }
    return var_r31_3874;
}

#if 0 // DRAFT: illegal implicit conversion from 'RopeBridgeDescriptor *' to
void RopeBridgeDescriptor::Deinit() {
    RopeBridgeDescriptor *temp_r4_3909;
    RopeBridgeDescriptor *temp_r4_3915;

    if ((RopeBridgeDescriptor *) *RopeBridgeDescriptor::pFirstDesc == this) {
        *RopeBridgeDescriptor::pFirstDesc = this->unk6C;
    }
    temp_r4_3909 = this->unk68;
    if (temp_r4_3909 != NULL) {
        temp_r4_3909->unk6C = this->unk6C;
    }
    temp_r4_3915 = this->unk6C;
    if (temp_r4_3915 != NULL) {
        temp_r4_3915->unk68 = this->unk68;
    }
    this->unk68 = NULL;
    this->unk6C = NULL;
    this->unk64 = 0;
    MKPropDescriptor::Deinit();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char' to
void RopeBridgeDescriptor::Init() {
    MKPropDescriptor::Init();
    this->unk60 = 0;
    this->unkC |= 0x20000;
    this->unk6C = *RopeBridgeDescriptor::pFirstDesc;
    this->unk68 = NULL;
    if ((RopeBridgeDescriptor *) *RopeBridgeDescriptor::pFirstDesc != NULL) {
        (*RopeBridgeDescriptor::pFirstDesc)->unk68 = this;
    }
    *RopeBridgeDescriptor::pFirstDesc = this;
    this->unk64 = M2C_FIELD(*gMK, s32 (**)(void **), 0x7C)(gMK);
}
#endif

void RopeBridge_cpp::__sinit() {
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;

    sp18 = -1.0f;
    sp20 = -1.0f;
    sp1C = -1.0f;
    sp10 = 2.0f;
    sp8 = 2.0f;
    M2C_FIELD(&boundingVolume, f64 *, 0) = (f64) sp18;
    spC = 2.0f;
    ROPEBRIDGE_MAXROLL = 0.34906584f;
    M2C_FIELD(&boundingVolume, f64 *, 8) = (f64) sp20;
    M2C_FIELD(&boundingVolume, f64 *, 0x10) = (f64) sp8;
    M2C_FIELD(&boundingVolume, f64 *, 0x18) = (f64) sp10;
}
