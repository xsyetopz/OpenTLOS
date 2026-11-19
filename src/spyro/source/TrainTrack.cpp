#include "spyro/source/TrainTrack.h"
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
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
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
#include "spyro/source/KDSpline.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "common/Source/Str.h"
#include <m2c_macros.h>

s32 stricmp(s8 *);                                  /* extern */
extern s8 gAssertBool;
extern void **gMK;

#if 0 // DRAFT: illegal implicit conversion from 'TrainTrackDescriptor' to
void TrainTrack::Build() {
    M2C_UNK spD0;
    MKVector3 spC0;
    f64 spB8;
    f64 spB0;
    MKVector3 spA0;
    f64 sp98;
    f64 sp90;
    KDSpline sp70;
    f64 sp68;
    f64 sp60;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    f32 var_f1_210;
    f32 var_f1_316;
    f32 var_f1_90;
    f64 temp_f0_199;
    f64 temp_f0_305;
    s32 temp_r3_121;
    s32 temp_r3_153;
    s32 temp_ret_338;
    s32 var_r24_329;
    s32 var_r25_174;
    s32 var_r25_223;
    s32 var_r25_280;
    s32 var_r27_175;
    s32 var_r27_281;
    s32 var_r27_54;
    s32 var_r28_48;
    s32 var_r28_96;
    s32 var_r29_52;
    s32 var_r30_53;
    u8 var_r24_278;
    u8 var_r26_172;
    void *temp_r24_178;
    void *temp_r28_284;
    void *temp_r3_67;
    void *temp_r3_90;
    void *temp_ret_85;
    void *temp_ret_90;
    void *var_r3_70;

    var_r28_48 = 0;
    this->unk4C.unk8 = 0.0f;
    var_r29_52 = 0;
    var_r30_53 = 0;
    var_r27_54 = 0;
    this->unk4C.unk4 = 0;
    this->unk60.unk8 = 0.0f;
    this->unk60.unk4 = 0;
    this->unk74.unk8 = 0.0f;
    this->unk74.unk4 = 0;
    this->unk88.unk8 = 0.0f;
    this->unk88.unk4 = 0;
loop_6:
    temp_ret_85 = checked_cast<TrainTrackDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    if (var_r30_53 < (s32) M2C_FIELD(temp_ret_85, s32 *, 0x27C)) {
        temp_r3_67 = *(checked_cast<TrainTrackDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (var_r27_54 + 0x240));
        if (temp_r3_67 != NULL) {
            var_r3_70 = M2C_FIELD(temp_r3_67, void **, 0x28);
loop_4:
            if (var_r3_70 != NULL) {
                *(&spD0 + var_r28_48) = var_r3_70;
                var_r28_48 += 4;
                var_r3_70 = M2C_FIELD(var_r3_70, void **, 0x38);
                var_r29_52 += 1;
                goto loop_4;
            }
        }
        var_r30_53 += 1;
        var_r27_54 += 4;
        goto loop_6;
    }
    temp_ret_90 = ((MKSceneManager *)0x31)->PropResolver_Resolve((s32) (u32) (u64) temp_ret_85);
    var_f1_90 = M2C_BITWISE(f32, temp_ret_90);
    temp_r3_90 = temp_ret_90;
    sp18 = -1;
    var_r28_96 = 0;
loop_8:
    if (MKModel_RefPointExists(M2C_FIELD(temp_r3_90, MKModel **, 4), Str_Printf("r_Spyro_L%d", var_r28_96, var_f1_90), (int *) &sp18) != 0) {
        MKModel_CalculateRefPointWorldPosition(M2C_FIELD(temp_r3_90, MKModel **, 4), sp18, &spC0);
        temp_r3_121 = MKModel_GetRefPointIndex(M2C_FIELD(temp_r3_90, MKModel **, 4), Str_Printf("r_Spyro_R%d", var_r28_96, M2C_BITWISE(f32, this->unk4C.AddNode(spC0))));
        sp18 = temp_r3_121;
        MKModel_CalculateRefPointWorldPosition(M2C_FIELD(temp_r3_90, MKModel **, 4), temp_r3_121, &spC0);
        if (MKModel_RefPointExists(M2C_FIELD(temp_r3_90, MKModel **, 4), Str_Printf("r_Steam_L%d", var_r28_96, M2C_BITWISE(f32, this->unk60.AddNode(spC0))), (int *) &sp18) != 0) {
            MKModel_CalculateRefPointWorldPosition(M2C_FIELD(temp_r3_90, MKModel **, 4), sp18, &spC0);
            temp_r3_153 = MKModel_GetRefPointIndex(M2C_FIELD(temp_r3_90, MKModel **, 4), Str_Printf("r_Steam_R%d", var_r28_96, M2C_BITWISE(f32, this->unk74.AddNode(spC0))));
            sp18 = temp_r3_153;
            MKModel_CalculateRefPointWorldPosition(M2C_FIELD(temp_r3_90, MKModel **, 4), temp_r3_153, &spC0);
            var_f1_90 = M2C_BITWISE(f32, this->unk88.AddNode(spC0));
            var_r28_96 += 1;
            if (var_r28_96 < 0xA) {
                goto loop_8;
            }
        }
    }
    do {
        var_r26_172 = 0;
        sp14 = -1;
        var_r25_174 = 0;
        var_r27_175 = 0;
loop_19:
        if (var_r25_174 < var_r29_52) {
            temp_r24_178 = *(&spD0 + var_r27_175);
            gAssertBool = MKModel_RefPointExists(M2C_FIELD(temp_r24_178, MKModel **, 4), "r_Spyro_L0", (int *) &sp14);
            sp70.GetMeasure(1.0f, (Matrix *) &this->unk4C);
            spB0 = M2C_BITWISE(f64, sp70);
            spB8 = (f64) sp70.unk8;
            MKModel_CalculateRefPointWorldPosition(M2C_FIELD(temp_r24_178, MKModel **, 4), sp14, &spA0);
            temp_f0_199 = M2C_BITWISE(f64, spA0) - spB0;
            sp30 = temp_f0_199;
            sp60 = temp_f0_199;
            sp38 = spA0.unk8 - (f32) spB8;
            var_f1_210 = (f32) sp60 * (f32) sp60;
            sp68 = (f64) sp38;
            if ((((f32) sp68 * (f32) sp68) + (var_f1_210 + ((*(f32 *) ((u8 *) &sp60 + 0x4)) * (*(f32 *) ((u8 *) &sp60 + 0x4))))) < 2500.0f) {
                sp10 = -1;
                var_r25_223 = 1;
loop_15:
                if (MKModel_RefPointExists(M2C_FIELD(temp_r24_178, MKModel **, 4), Str_Printf("r_Spyro_L%d", var_r25_223, var_f1_210), (int *) &sp10) != 0) {
                    MKModel_CalculateRefPointWorldPosition(M2C_FIELD(temp_r24_178, MKModel **, 4), sp10, &spA0);
                    MKModel_CalculateRefPointWorldPosition(M2C_FIELD(temp_r24_178, MKModel **, 4), MKModel_GetRefPointIndex(M2C_FIELD(temp_r24_178, MKModel **, 4), Str_Printf("r_Spyro_R%d", var_r25_223, M2C_BITWISE(f32, this->unk4C.AddNode(spA0)))), &spA0);
                    var_f1_210 = M2C_BITWISE(f32, this->unk60.AddNode(spA0));
                    var_r25_223 += 1;
                    if (var_r25_223 < 0xA) {
                        goto loop_15;
                    }
                }
                var_r26_172 = 1;
            } else {
                var_r25_174 += 1;
                var_r27_175 += 4;
                goto loop_19;
            }
        }
    } while (var_r26_172 != 0);
    do {
        var_r24_278 = 0;
        spC = -1;
        var_r25_280 = 0;
        var_r27_281 = 0;
loop_30:
        if (var_r25_280 < var_r29_52) {
            temp_r28_284 = *(&spD0 + var_r27_281);
            gAssertBool = MKModel_RefPointExists(M2C_FIELD(temp_r28_284, MKModel **, 4), "r_Steam_L0", (int *) &spC);
            ((KDSpline *) &sp50)->GetMeasure(1.0f, (Matrix *) &this->unk74);
            sp90 = sp50;
            sp98 = sp58;
            MKModel_CalculateRefPointWorldPosition(M2C_FIELD(temp_r28_284, MKModel **, 4), spC, (MKVector3 *) &sp70.unk10);
            temp_f0_305 = M2C_BITWISE(f64, sp70.unk10) - sp90;
            sp20 = temp_f0_305;
            sp40 = temp_f0_305;
            sp28 = sp88 - (f32) sp98;
            var_f1_316 = (f32) sp40 * (f32) sp40;
            sp48 = (f64) sp28;
            if ((((f32) sp48 * (f32) sp48) + (var_f1_316 + ((*(f32 *) ((u8 *) &sp40 + 0x4)) * (*(f32 *) ((u8 *) &sp40 + 0x4))))) < 2500.0f) {
                sp8 = -1;
                var_r24_329 = 1;
loop_25:
                temp_ret_338 = MKModel_RefPointExists(M2C_FIELD(temp_r28_284, MKModel **, 4), Str_Printf("r_Spyro_L%d", var_r24_329, var_f1_316), (int *) &sp8);
                if ((temp_ret_338 != 0) && (MKModel_RefPointExists(M2C_FIELD(temp_r28_284, MKModel **, 4), Str_Printf("r_Steam_L%d", var_r24_329, M2C_BITWISE(f32, temp_ret_338)), (int *) &sp8) != 0)) {
                    MKModel_CalculateRefPointWorldPosition(M2C_FIELD(temp_r28_284, MKModel **, 4), sp8, (MKVector3 *) &sp70.unk10);
                    MKModel_CalculateRefPointWorldPosition(M2C_FIELD(temp_r28_284, MKModel **, 4), MKModel_GetRefPointIndex(M2C_FIELD(temp_r28_284, MKModel **, 4), Str_Printf("r_Steam_R%d", var_r24_329, M2C_BITWISE(f32, this->unk74.AddNode(*((MKVector3 *) &sp70.unk10))))), (MKVector3 *) &sp70.unk10);
                    var_f1_316 = M2C_BITWISE(f32, this->unk88.AddNode(*((MKVector3 *) &sp70.unk10)));
                    var_r24_329 += 1;
                    if (var_r24_329 < 0xA) {
                        goto loop_25;
                    }
                }
                var_r24_278 = 1;
            } else {
                var_r25_280 += 1;
                var_r27_281 += 4;
                goto loop_30;
            }
        }
    } while (var_r24_278 != 0);
}
#endif

#if 0 // DRAFT: undefined identifier 'sp58'
void TrainTrack::GetTrackZAxis(int arg0, float arg1) {
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp50;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    f32 var_f3_514;
    f32 var_f4_447;
    f64 temp_f1_453;
    f64 temp_f1_459;
    f64 temp_f1_463;
    s32 temp_r3_482;
    s32 var_r0_492;

    ((TrainTrack *) &sp50)->GetTrackPos(arg0, arg1, M2C_ERROR(/* Read from unset register $r5 */));
    sp70 = sp50;
    sp78 = sp58;
    ((TrainTrack *) &sp40)->GetTrackPos(arg0, 100.0f + arg1, M2C_ERROR(/* Read from unset register $r5 */));
    sp60 = sp40;
    sp68 = sp48;
    sp10 = sp70 - sp60;
    sp30 = sp10;
    sp18 = (f32) sp78 - (f32) sp68;
    sp38 = (f64) sp18;
    var_f4_447 = ((f32) sp38 * (f32) sp38) + (((f32) sp30 * (f32) sp30) + ((*(f32 *) ((u8 *) &sp30 + 0x4)) * (*(f32 *) ((u8 *) &sp30 + 0x4))));
    if (var_f4_447 > 1e-12f) {
        if (var_f4_447 > 0.0f) {
            temp_f1_453 = __frsqrte(var_f4_447);
            temp_f1_459 = 0.5 * temp_f1_453 * -(((f64) var_f4_447 * (temp_f1_453 * temp_f1_453)) - 3.0);
            temp_f1_463 = 0.5 * temp_f1_459 * -(((f64) var_f4_447 * (temp_f1_459 * temp_f1_459)) - 3.0);
            var_f4_447 = (f32) ((f64) var_f4_447 * (0.5 * temp_f1_463 * -(((f64) var_f4_447 * (temp_f1_463 * temp_f1_463)) - 3.0)));
        } else if (var_f4_447 < M2C_BITWISE(f32, 0.0)) {
            var_f4_447 = __float_nan;
        } else {
            sp8 = var_f4_447;
            temp_r3_482 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_482) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_492 = 1;
                } else {
                    var_r0_492 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_492 = 5;
                } else {
                    var_r0_492 = 3;
                }
                break;
            default:
                var_r0_492 = 4;
                break;
            }
            if (var_r0_492 == 1) {
                var_f4_447 = __float_nan;
            }
        }
        var_f3_514 = 1.0f / var_f4_447;
    } else {
        var_f3_514 = 0.0f;
    }
    sp24 = (*(f32 *) ((u8 *) &sp30 + 0x4)) * var_f3_514;
    sp20 = (f32) sp30 * var_f3_514;
    sp28 = (f32) sp38 * var_f3_514;
    M2C_FIELD(this, f64 *, 0) = (f64) sp20;
    M2C_FIELD(this, f64 *, 8) = (f64) sp28;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'void *' to
void TrainTrack::GetTrackYAxis(int arg0, float arg1) {
    TrainTrack sp40;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    f32 temp_f2_581;
    f32 temp_f4_559;
    f32 temp_f5_564;
    f32 temp_f5_578;
    f32 temp_f6_582;
    f32 temp_f7_562;
    f32 var_f3_652;
    f32 var_f4_585;
    f64 temp_f1_591;
    f64 temp_f1_597;
    f64 temp_f1_601;
    s32 temp_r3_620;
    s32 var_r0_630;

    ((TrainTrack *) &sp30)->GetTrackZAxis(arg0, arg1);
    sp40.GetTrackXAxis(arg0, arg1);
    temp_f4_559 = M2C_BITWISE(f32, sp40.unk8);
    temp_f7_562 = M2C_BITWISE(f32, sp40.unk4);
    temp_f5_564 = M2C_BITWISE(f32, sp40);
    sp14 = (sp38 * temp_f5_564) - (sp30 * temp_f4_559);
    sp10 = (sp34 * temp_f4_559) - (sp38 * temp_f7_562);
    sp18 = (sp30 * temp_f7_562) - (sp34 * temp_f5_564);
    sp40.unk10 = (f64) sp10;
    temp_f5_578 = M2C_BITWISE(f32, sp40.unk14);
    sp40.unk18 = (f64) sp18;
    temp_f2_581 = M2C_BITWISE(f32, sp40.unk10);
    temp_f6_582 = M2C_BITWISE(f32, sp40.unk18);
    var_f4_585 = (temp_f6_582 * temp_f6_582) + ((temp_f2_581 * temp_f2_581) + (temp_f5_578 * temp_f5_578));
    if (var_f4_585 > 1e-12f) {
        if (var_f4_585 > 0.0f) {
            temp_f1_591 = __frsqrte(var_f4_585);
            temp_f1_597 = 0.5 * temp_f1_591 * -(((f64) var_f4_585 * (temp_f1_591 * temp_f1_591)) - 3.0);
            temp_f1_601 = 0.5 * temp_f1_597 * -(((f64) var_f4_585 * (temp_f1_597 * temp_f1_597)) - 3.0);
            var_f4_585 = (f32) ((f64) var_f4_585 * (0.5 * temp_f1_601 * -(((f64) var_f4_585 * (temp_f1_601 * temp_f1_601)) - 3.0)));
        } else if (var_f4_585 < M2C_BITWISE(f32, 0.0)) {
            var_f4_585 = __float_nan;
        } else {
            sp8 = var_f4_585;
            temp_r3_620 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_620) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_630 = 1;
                } else {
                    var_r0_630 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_630 = 5;
                } else {
                    var_r0_630 = 3;
                }
                break;
            default:
                var_r0_630 = 4;
                break;
            }
            if (var_r0_630 == 1) {
                var_f4_585 = __float_nan;
            }
        }
        var_f3_652 = 1.0f / var_f4_585;
    } else {
        var_f3_652 = 0.0f;
    }
    sp24 = temp_f5_578 * var_f3_652;
    sp20 = M2C_BITWISE(f32, sp40.unk10) * var_f3_652;
    sp28 = temp_f6_582 * var_f3_652;
    M2C_FIELD(this, f64 *, 0) = (f64) sp20;
    M2C_FIELD(this, f64 *, 8) = (f64) sp28;
}
#endif

#if 0 // DRAFT: undefined identifier 'sp58'
void TrainTrack::GetTrackXAxis(int arg0, float arg1) {
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp50;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    f32 var_f3_793;
    f32 var_f4_726;
    f64 temp_f1_732;
    f64 temp_f1_738;
    f64 temp_f1_742;
    s32 temp_r3_761;
    s32 var_r0_771;

    ((TrainTrack *) &sp50)->GetTrackPos(arg0, arg1, M2C_ERROR(/* Read from unset register $r5 */));
    sp70 = sp50;
    sp78 = sp58;
    ((TrainTrack *) &sp40)->GetTrackPos(arg0, arg1, M2C_ERROR(/* Read from unset register $r5 */));
    sp60 = sp40;
    sp68 = sp48;
    sp10 = sp70 - sp60;
    sp30 = sp10;
    sp18 = (f32) sp78 - (f32) sp68;
    sp38 = (f64) sp18;
    var_f4_726 = ((f32) sp38 * (f32) sp38) + (((f32) sp30 * (f32) sp30) + ((*(f32 *) ((u8 *) &sp30 + 0x4)) * (*(f32 *) ((u8 *) &sp30 + 0x4))));
    if (var_f4_726 > 1e-12f) {
        if (var_f4_726 > 0.0f) {
            temp_f1_732 = __frsqrte(var_f4_726);
            temp_f1_738 = 0.5 * temp_f1_732 * -(((f64) var_f4_726 * (temp_f1_732 * temp_f1_732)) - 3.0);
            temp_f1_742 = 0.5 * temp_f1_738 * -(((f64) var_f4_726 * (temp_f1_738 * temp_f1_738)) - 3.0);
            var_f4_726 = (f32) ((f64) var_f4_726 * (0.5 * temp_f1_742 * -(((f64) var_f4_726 * (temp_f1_742 * temp_f1_742)) - 3.0)));
        } else if (var_f4_726 < M2C_BITWISE(f32, 0.0)) {
            var_f4_726 = __float_nan;
        } else {
            sp8 = var_f4_726;
            temp_r3_761 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_761) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_771 = 1;
                } else {
                    var_r0_771 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_771 = 5;
                } else {
                    var_r0_771 = 3;
                }
                break;
            default:
                var_r0_771 = 4;
                break;
            }
            if (var_r0_771 == 1) {
                var_f4_726 = __float_nan;
            }
        }
        var_f3_793 = 1.0f / var_f4_726;
    } else {
        var_f3_793 = 0.0f;
    }
    sp24 = (*(f32 *) ((u8 *) &sp30 + 0x4)) * var_f3_793;
    sp20 = (f32) sp30 * var_f3_793;
    sp28 = (f32) sp38 * var_f3_793;
    M2C_FIELD(this, f64 *, 0) = (f64) sp20;
    M2C_FIELD(this, f64 *, 8) = (f64) sp28;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void TrainTrack::GetTrackPos(int arg0, float arg1, int arg2) {
    KDSpline sp78;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    KDSpline sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f32 var_f30_844;
    f64 temp_f0_890;
    s32 temp_r31_868;
    s32 temp_r4_840;

    if (arg1 == M2C_FIELD(arg0, f32 *, 0xD0)) {
        M2C_FIELD(this, f64 *, 0) = (f64) M2C_FIELD(arg0, f64 *, 0xC0);
        M2C_FIELD(this, f64 *, 8) = (f64) M2C_FIELD(arg0, f64 *, 0xC8);
        return;
    }
    temp_r4_840 = arg2 * 0x28;
    var_f30_844 = arg1 / M2C_FIELD((arg0 + temp_r4_840), f32 *, 0x54);
    if (var_f30_844 < 1.0f) {

    } else {
        var_f30_844 = 1.0f;
    }
    if (var_f30_844 > 0.0f) {

    } else {
        var_f30_844 = 0.0f;
    }
    if ((s32) M2C_ERROR(/* Read from unset register $r6 */) != 0) {
        if ((s32) M2C_ERROR(/* Read from unset register $r6 */) < 0) {
            goto block_13;
        }
        if ((s32) M2C_ERROR(/* Read from unset register $r6 */) < 2) {
            sp28.GetMeasure(var_f30_844, arg0 + (temp_r4_840 + 0x60));
            M2C_FIELD(arg0, f64 *, 0xC0) = M2C_BITWISE(f64, sp28);
            M2C_FIELD(arg0, f64 *, 0xC8) = (f64) sp28.unk8;
        } else {
block_13:
            temp_r31_868 = arg0 + temp_r4_840;
            sp78.GetMeasure(var_f30_844, temp_r31_868 + 0x4C);
            M2C_FIELD(arg0, f64 *, 0xA0) = M2C_BITWISE(f64, sp78);
            M2C_FIELD(arg0, f64 *, 0xA8) = (f64) sp78.unk8;
            ((KDSpline *) &sp68)->GetMeasure(var_f30_844, temp_r31_868 + 0x60);
            M2C_FIELD(arg0, f64 *, 0xB0) = sp68;
            M2C_FIELD(arg0, f64 *, 0xB8) = sp70;
            temp_f0_890 = M2C_FIELD(arg0, f64 *, 0xA0) + M2C_FIELD(arg0, f64 *, 0xB0);
            sp8 = temp_f0_890;
            sp48 = temp_f0_890;
            sp10 = (f32) M2C_FIELD(arg0, f64 *, 0xA8) + (f32) M2C_FIELD(arg0, f64 *, 0xB8);
            sp50 = (f64) sp10;
            sp18 = temp_f0_890 * 5.222099017e-315;
            M2C_FIELD(arg0, f64 *, 0xC0) = sp18;
            sp20 = (f32) sp50 * 0.5f;
            sp58 = sp18;
            sp60 = (f64) sp20;
            M2C_FIELD(arg0, f64 *, 0xC8) = (f64) sp20;
        }
    } else {
        ((KDSpline *) &sp28.unk10)->GetMeasure(var_f30_844, arg0 + (temp_r4_840 + 0x4C));
        M2C_FIELD(arg0, f64 *, 0xC0) = M2C_BITWISE(f64, sp28.unk10);
        M2C_FIELD(arg0, f64 *, 0xC8) = sp40;
    }
    M2C_FIELD(this, f64 *, 0) = (f64) M2C_FIELD(arg0, f64 *, 0xC0);
    M2C_FIELD(this, f64 *, 8) = (f64) M2C_FIELD(arg0, f64 *, 0xC8);
}
#endif

f32 TrainTrack::GetTrackLength(int arg0) {
    return M2C_FIELD((this + (arg0 * 0x28)), f32 *, 0x54);
}

void TrainTrack::Message(MKMessage *arg0) {
    s32 temp_r0_973;

    MKProp::Message(arg0);
    temp_r0_973 = arg0->unk0;
    switch (temp_r0_973) {                          /* irregular */
    case 0xB5:
        Enable();
        Build();
        return;
    case 0xB4:
        Disable();
        return;
    }
}

void *TrainTrack::Update() {
    MKProp::Update();
}

void TrainTrack::Reset() {
    MKProp::Reset();
}

f32 TrainTrack::Resolve() {
    MKProp::Resolve();
}

s32 TrainTrack::LoadDone() {
    MKProp::LoadDone();
    Disable();
}

s32 TrainTrack::LoadLine(MKIniLine *arg0) {
    MKProp::LoadLine(arg0);
}

void TrainTrack::Deinit() {
    MKProp::Deinit();
    this->unk4C.Deinit();
    this->unk60.Deinit();
    this->unk74.Deinit();
    this->unk88.Deinit();
}

void TrainTrack::Init() {
    MKProp::Init();
    this->unk4C.Init(0x3E8, 0U);
    this->unk60.Init(0x3E8, 0U);
    this->unk74.Init(0x3E8, 0U);
    this->unk88.Init(0x3E8, 0U);
}

#if 0 // DRAFT: illegal operand
void TrainTrackDescriptor::Resolve() {
    s32 temp_r0_1153;
    s32 var_r29_1141;
    s32 var_r30_1143;
    s32 var_r31_1142;

    MKPropDescriptor::Resolve();
    var_r29_1141 = 0;
    var_r31_1142 = 0;
    var_r30_1143 = 0;
loop_2:
    if (var_r29_1141 < (s32) this->unk27C) {
        temp_r0_1153 = var_r31_1142 + 0x240;
        var_r31_1142 += 4;
        *(this + temp_r0_1153) = M2C_FIELD(*gMK, s32 (**)(void **, void *), 0x5C)(gMK, this + (var_r30_1143 + 0x60));
        var_r30_1143 += 0x20;
        var_r29_1141 += 1;
        goto loop_2;
    }
}
#endif

void TrainTrackDescriptor::LoadDone() {
    MKPropDescriptor::LoadDone();
}

#if 0 // DRAFT: function call 'stricmp(const char[6])' does not match
s32 TrainTrackDescriptor::LoadLine(MKIniLine *arg0) {
    s32 temp_r4_1209;
    s32 temp_r5_1208;

    if (MKPropDescriptor::LoadLine(arg0) != 0) {
        return 1;
    }
    arg0->GetFieldName();
    if (stricmp("piece") == 0) {
        temp_r5_1208 = this->unk27C;
        temp_r4_1209 = arg0->GetString(0);
        this->unk27C = temp_r5_1208 + 1;
        strcpy(this + ((temp_r5_1208 << 5) + 0x60), (s8 *) temp_r4_1209);
        return 1;
    }
    return 0;
}
#endif

void TrainTrackDescriptor::Init() {
    MKPropDescriptor::Init();
    this->unk27C = 0;
}
