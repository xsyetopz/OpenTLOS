#include "spyro/source/KDSynkerPlayerActor.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/KDBasicEnvelope.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/KDSynkerPlayer2Messages.h"
#include "spyro/source/KDSynkerPlayerActorList.h"
#include "spyro/source/KDSynkerPlayerCamera.h"
#include "spyro/source/KDSynkerPlayerTools.h"
#include "spyro/source/Shadow.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKWind.h"
#include "common/Source/StdMath.h"
#include "common/Source/system_extras.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

s32 atoi(s8 *, s32);                                /* extern */
f64 fmod(f32, f32);                                 /* extern */
M2C_UNK free(Matrix *);                             /* extern */
Matrix *malloc(M2C_UNK);                            /* extern */
s32 stricmp(s8 *, s8 *);                            /* extern */
s8 *strrchr(s8 *, M2C_UNK);                         /* extern */
u32 strstr(s8 *);                                   /* extern */
M2C_UNK strtok(s8 *, s8 *);                         /* extern */
extern f32 *KDSpline_PositionMixer;
extern f32 gUpdateTimeDelta;
extern u8 init_1397;
extern u8 init_1400;
extern u8 init_1506;
extern u8 init_1509;
extern u8 init_1512;
extern u8 init_1515;
extern u8 init_1526;
extern u8 init_1529;
extern u8 init_1532;
extern u8 init_1535;
extern f32 l_HARD_EYES_ANGLE_1525;
extern f32 l_HARD_HEAD_ANGLE_1505;
extern f32 l_MIN_EYES_DOT_1531;
extern f32 l_MIN_HEAD_DOT_1511;
extern f32 l_SOFT_EYES_ANGLE_1528;
extern f32 l_SOFT_HEAD_ANGLE_1508;
extern f32 l_SOFT_MIN_EYES_DOT_1534;
extern f32 l_SOFT_MIN_HEAD_DOT_1514;
extern u8 l_bVoiceStarted_1396;
extern u8 l_prevAwfFrame_1399;
static M2C_UNK lit_770;                                /* unable to generate initializer: unknown type */

static s32 lit_1411 = 0x2D;
#if 0 // DRAFT: illegal type
static s8 lit_stringBase0[0x105] = {
    0x42,
    0x61,
    0x72,
    0x73,
    0,
    0x65,
    0x6E,
    0x76,
    0,
    0x73,
    0x74,
    0x61,
    0x72,
    0x74,
    0,
    0x6C,
    0x65,
    0x6E,
    0x67,
    0x74,
    0x68,
    0,
    0x62,
    0x72,
    0x65,
    0x61,
    0x6B,
    0x65,
    0x72,
    0,
    0x68,
    0x65,
    0x61,
    0x64,
    0,
    0x6C,
    0x5F,
    0x65,
    0x79,
    0x65,
    0,
    0x65,
    0x79,
    0x65,
    0x5F,
    0x6C,
    0,
    0x72,
    0x5F,
    0x65,
    0x79,
    0x65,
    0,
    0x65,
    0x79,
    0x65,
    0x5F,
    0x72,
    0,
    0x68,
    0x65,
    0x61,
    0x64,
    0x41,
    0x6E,
    0x69,
    0x6D,
    0x73,
    0,
    0x6C,
    0x69,
    0x70,
    0x41,
    0x6E,
    0x69,
    0x6D,
    0x73,
    0,
    0x72,
    0x6F,
    0x6F,
    0x74,
    0,
    0x48,
    0x69,
    0x64,
    0x64,
    0x65,
    0x6E,
    0x53,
    0x75,
    0x62,
    0x4F,
    0x62,
    0x6A,
    0x73,
    0,
    0x5F,
    0x42,
    0x6F,
    0x64,
    0x79,
    0,
    0x5F,
    0x4C,
    0x69,
    0x70,
    0x73,
    0,
    0x5F,
    0x48,
    0x65,
    0x61,
    0x64,
    0,
    0x2E,
    0,
    0x2E,
    0x62,
    0x61,
    0x64,
    0,
    0x2E,
    0x6D,
    0x64,
    0x6C,
    0,
    0x5F,
    0x4C,
    0x4F,
    0x44,
    0,
    0x41,
    0x57,
    0x46,
    0x53,
    0,
    0x5F,
    0x50,
    0x6F,
    0x73,
    0,
    0x5F,
    0x56,
    0x6F,
    0x69,
    0x63,
    0x65,
    0,
    0x5F,
    0x4C,
    0x6F,
    0x6F,
    0x6B,
    0x48,
    0x65,
    0x61,
    0x64,
    0,
    0x5F,
    0x4C,
    0x6F,
    0x6F,
    0x6B,
    0x45,
    0x79,
    0x65,
    0x73,
    0,
    0x5F,
    0x4C,
    0x6F,
    0x6F,
    0x6B,
    0,
    0x50,
    0x61,
    0x74,
    0x68,
    0x73,
    0,
    0x70,
    0x6F,
    0x73,
    0,
    0x4C,
    0x56,
    0x45,
    0,
    0x41,
    0x69,
    0x6D,
    0x41,
    0x74,
    0x50,
    0x61,
    0x74,
    0x68,
    0,
    0x72,
    0x6F,
    0x74,
    0,
    0x42,
    0x41,
    0x44,
    0x52,
    0x65,
    0x66,
    0,
    0x50,
    0x72,
    0x6F,
    0x70,
    0x49,
    0x44,
    0,
    0x52,
    0x65,
    0x6D,
    0x61,
    0x69,
    0x6E,
    0x41,
    0x63,
    0x74,
    0x69,
    0x76,
    0x65,
    0,
    0x44,
    0x75,
    0x6D,
    0x6D,
    0x79,
    0,
    0x44,
    0x72,
    0x6F,
    0x70,
    0x53,
    0x68,
    0x61,
    0x64,
    0x6F,
    0x77,
    0,
    0x4C,
    0x69,
    0x74,
    0x46,
    0x72,
    0x6F,
    0x6D,
    0x47,
    0x72,
    0x6F,
    0x75,
    0x6E,
    0x64,
    0,
}; /* const */

void KDSP_Actor::UpdateLookat() {
    MKVector3 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    MKVector3 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f32 sp98;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp78;
    f32 sp68;
    f32 sp58;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp28;
    u8 sp1B;
    u8 sp1A;
    u8 sp19;
    u8 sp18;
    s32 sp14;
    u8 *sp10;
    u8 *spC;
    MKVector3 *sp8;
    s32 temp_r3_24;
    s32 temp_r6_156;
    s32 temp_r6_182;
    s32 temp_r6_74;
    s32 temp_r7_159;
    s32 temp_r7_185;
    s32 temp_r7_84;

    temp_r3_24 = this->unk40;
    if (!(temp_r3_24 & 4)) {
        if (temp_r3_24 & 8) {
            return;
        }
        sp1B = 0;
        sp1A = 0;
        sp19 = 1;
        sp18 = 1;
        if ((s8) init_1506 == 0) {
            init_1506 = 1;
            l_HARD_HEAD_ANGLE_1505 = 2.0943952f;
        }
        if ((s8) init_1509 == 0) {
            init_1509 = 1;
            l_SOFT_HEAD_ANGLE_1508 = 1.3613569f;
        }
        if ((s8) init_1512 == 0) {
            l_MIN_HEAD_DOT_1511 = _table_sinf(1.5707964f + l_HARD_HEAD_ANGLE_1505);
            init_1512 = 1;
        }
        if ((s8) init_1515 == 0) {
            l_SOFT_MIN_HEAD_DOT_1514 = _table_sinf(1.5707964f + l_SOFT_HEAD_ANGLE_1508);
            init_1515 = 1;
        }
        temp_r6_74 = this->unk84;
        if (((temp_r6_74 != -1) || ((u32) this->unk30 != 0)) && ((s32) this->unk44 > 0)) {
            temp_r7_84 = this->unkD0;
            sp8 = &this->unkD8;
            spC = &sp1B;
            sp10 = &sp1A;
            sp14 = 1;
            UpdateLookatNode(this->unk38, -1, temp_r6_74, temp_r7_84, *(this->unk48 + (temp_r7_84 * 0x14)), (MKProp *) this->unk30, this->unk108, *(M2C_ERROR(/* Unable to find stack arg 0x0 in block */)), l_SOFT_MIN_HEAD_DOT_1514, l_MIN_HEAD_DOT_1511, M2C_ERROR(/* Unable to find stack arg 0x4 in block */), l_SOFT_HEAD_ANGLE_1508, M2C_ERROR(/* Unable to find stack arg 0x8 in block */), M2C_ERROR(/* Unable to find stack arg 0xc in block */), 0.2f);
            if (sp1A == 0) {
                UpdateAimNode(this->unk38, this->unkD8, this->unk84);
            }
        }
        if ((s32) this->unk4C > 0) {
            if ((s8) init_1526 == 0) {
                init_1526 = 1;
                l_HARD_EYES_ANGLE_1525 = 1.0471976f;
            }
            if ((s8) init_1529 == 0) {
                init_1529 = 1;
                l_SOFT_EYES_ANGLE_1528 = 0.31415927f;
            }
            if ((s8) init_1532 == 0) {
                l_MIN_EYES_DOT_1531 = _table_sinf(1.5707964f + l_HARD_EYES_ANGLE_1525);
                init_1532 = 1;
            }
            if ((s8) init_1535 == 0) {
                l_SOFT_MIN_EYES_DOT_1534 = _table_sinf(1.5707964f + l_SOFT_EYES_ANGLE_1528);
                init_1535 = 1;
            }
            temp_r6_156 = this->unk88;
            if (temp_r6_156 != -1) {
                temp_r7_159 = this->unkC4;
                sp8 = &this->unkF8;
                spC = &sp19;
                sp10 = &sp1A;
                sp14 = 0;
                UpdateLookatNode(this->unk38, this->unk84, temp_r6_156, temp_r7_159, *(this->unk50 + (temp_r7_159 * 0x14)), NULL, this->unk108, *(M2C_ERROR(/* Unable to find stack arg 0x0 in block */)), l_SOFT_MIN_EYES_DOT_1534, l_MIN_EYES_DOT_1531, M2C_ERROR(/* Unable to find stack arg 0x4 in block */), l_SOFT_EYES_ANGLE_1528, M2C_ERROR(/* Unable to find stack arg 0x8 in block */), M2C_ERROR(/* Unable to find stack arg 0xc in block */), 0.4f);
            }
            temp_r6_182 = this->unk8C;
            if (temp_r6_182 != -1) {
                temp_r7_185 = this->unkC4;
                sp8 = &this->unkE8;
                spC = &sp18;
                sp10 = &sp1A;
                sp14 = 0;
                UpdateLookatNode(this->unk38, this->unk84, temp_r6_182, temp_r7_185, *(this->unk50 + (temp_r7_185 * 0x14)), NULL, this->unk108, *(M2C_ERROR(/* Unable to find stack arg 0x0 in block */)), l_SOFT_MIN_EYES_DOT_1534, l_MIN_EYES_DOT_1531, M2C_ERROR(/* Unable to find stack arg 0x4 in block */), l_SOFT_EYES_ANGLE_1528, M2C_ERROR(/* Unable to find stack arg 0x8 in block */), M2C_ERROR(/* Unable to find stack arg 0xc in block */), 0.4f);
            }
            if ((sp19 == 0) || (sp18 == 0)) {
                sp80 = 0.0f;
                sp84 = 0.0f;
                sp88 = 1.0f;
                spF0 = (f64) sp80;
                spF8 = (f64) sp88;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
                sp100 = sp70;
                sp78 = (f32) spF8 * 0.4f;
                sp108 = (f64) sp78;
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
                sp110 = sp90;
                sp98 = this->unkF8.unk8 * 0.6f;
                sp118 = (f64) sp98;
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                sp120 = sp60;
                sp68 = (f32) sp118 + (f32) sp108;
                sp128 = (f64) sp68;
                Normalise(sp130);
                sp40 = 0.0f;
                sp44 = 0.0f;
                sp48 = 1.0f;
                M2C_FIELD(this, f64 *, 0xF8) = M2C_BITWISE(f64, sp130);
                spA0 = (f64) sp40;
                M2C_FIELD(this, f32 *, 0x100) = (f64) sp130.unk8;
                spA8 = (f64) sp48;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
                spB0 = sp30;
                sp38 = (f32) spA8 * 0.4f;
                spB8 = (f64) sp38;
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
                spC0 = sp50;
                sp58 = this->unkE8.unk8 * 0.6f;
                spC8 = (f64) sp58;
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                spD0 = sp20;
                sp28 = (f32) spC8 + (f32) spB8;
                spD8 = (f64) sp28;
                Normalise(spE0);
                M2C_FIELD(this, f64 *, 0xE8) = M2C_BITWISE(f64, spE0);
                M2C_FIELD(this, f32 *, 0xF0) = (f64) spE0.unk8;
            }
            UpdateAimNode(this->unk38, this->unkF8, this->unk88);
            UpdateAimNode(this->unk38, this->unkE8, this->unk8C);
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp120'
void KDSP_Actor::UpdateAimNode(MKAnimScript *arg0, MKVector3 &arg1, int arg2) {
    f32 temp_f7_368;
    f32 temp_f8_365;
    f32 temp_f9_360;
    if (arg2 != -1) {
        temp_f9_360 = arg1.unk0;
        arg_sp120 = temp_f9_360;
        arg_sp38 = 0.0f;
        temp_f8_365 = arg1.unk4;
        arg_sp124 = temp_f8_365;
        temp_f7_368 = arg1.unk8;
        arg_sp98 = (f64) arg_sp38;
        arg_sp30 = 0.0f;
        arg_sp34 = 1.0f;
        arg_sp128 = temp_f7_368;
        arg_sp90 = (f64) arg_sp30;
        arg_sp12C = 0.0f;
        arg_sp110 = (f32) arg_sp90;
        arg_sp114 = arg_sp94;
        arg_sp28 = ((f32) arg_sp90 * temp_f8_365) - (arg_sp94 * temp_f9_360);
        arg_sp20 = (arg_sp94 * temp_f7_368) - ((f32) arg_sp98 * temp_f8_365);
        arg_sp24 = ((f32) arg_sp98 * temp_f9_360) - ((f32) arg_sp90 * temp_f7_368);
        arg_sp118 = (f32) arg_sp98;
        arg_sp11C = 0.0f;
        arg_sp70 = (f64) arg_sp20;
        arg_sp78 = (f64) arg_sp28;
        Normalise(*((MKVector3 *) &arg_sp80));
        arg_sp100 = arg_sp80;
        arg_sp18 = (arg_sp120 * arg_sp84) - (arg_sp124 * arg_sp80);
        arg_sp10 = (arg_sp124 * arg_sp88) - (arg_sp128 * arg_sp84);
        arg_sp14 = (arg_sp128 * arg_sp80) - (arg_sp120 * arg_sp88);
        arg_sp68 = (f64) arg_sp18;
        arg_sp60 = (f64) arg_sp10;
        arg_sp104 = arg_sp84;
        arg_sp108 = arg_sp88;
        arg_sp10C = 0.0f;
        arg_sp110 = (f32) arg_sp60;
        arg_sp114 = arg_sp64;
        arg_sp118 = (f32) arg_sp68;
        arg_sp11C = 0.0f;
        arg_sp130 = 0.0f;
        arg_sp134 = 0.0f;
        arg_sp138 = 0.0f;
        arg_sp13C = 1.0f;
        arg_sp50.GetNodeOrigin(MKModel_GetAnimation(arg0->unk8));
        arg_spB0 = arg_sp50;
        arg_spB8 = arg_sp58;
        arg_sp40 = -(f32) arg_spB0;
        arg_sp44 = -arg_spB4;
        arg_sp48 = -(f32) arg_spB8;
        arg_spA0 = (f64) arg_sp40;
        arg_spA8 = (f64) arg_sp48;
        arg_spC0.SetIdentity();
        arg_spF0 = (f32) arg_spA0;
        arg_spF4 = arg_spA4;
        arg_spF8 = (f32) arg_spA8;
        arg_spFC = 1.0f;
        arg_spC0.Multiply((Matrix *) &arg_spC0, (Matrix *) &arg_sp100);
        arg_spC0.Translate((Matrix *) &arg_spC0, *((MKVector3 *) &arg_spB0));
        ((Animation *) (MKModel_GetAnimation(arg0->unk8)))->SetCustomMatrix(arg2, (Matrix *) &arg_spC0, (AnimationMatrixPosition) 2, 0U);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp1CC'
void KDSP_Actor::UpdateLookatNode(MKAnimScript *arg0, int arg1, int arg2, int arg3, KDSP_LookBar &arg4, MKProp *arg5, MKVector3 &arg6, MKVector3 &arg7, float arg8, float arg9, bool *arg10, float arg11, bool *arg12, bool arg13, float arg14) {
    KDSP_Actor *temp_r24_513;
    MKModel *temp_r3_538;
    Matrix *temp_r3_559;
    f32 temp_f3_701;
    f32 temp_f4_704;
    f32 temp_f5_698;
    f32 var_f3_664;
    f32 var_f3_777;
    f32 var_f4_710;
    f64 temp_f1_716;
    f64 temp_f1_722;
    f64 temp_f1_726;
    s32 temp_r3_745;
    s32 var_r0_755;
    s8 *temp_r29_522;
    u32 temp_r4_541;
    u8 *temp_r30_523;
    u8 temp_r31_525;
    u8 var_r0_967;
    void *temp_r28_520;
    void *temp_r3_549;
    temp_r24_513 = arg4.unkC;
    arg_sp1CC = 0;
    temp_r28_520 = M2C_FIELD(sp, void **, 8);
    temp_r29_522 = M2C_FIELD(sp, s8 **, 0xC);
    temp_r30_523 = M2C_FIELD(sp, u8 **, 0x10);
    temp_r31_525 = M2C_FIELD(sp, u8 *, 0x17);
    arg_sp1C8.Init(NULL, NULL);
    if ((arg3 != -1) && (temp_r24_513 != NULL)) {
        temp_r3_538 = temp_r24_513->GetModel();
        if (temp_r3_538 != NULL) {
            temp_r4_541 = arg4.unk10;
            if (temp_r4_541 != -1U) {
                MKModel_CalculateNodeWorldPosition(temp_r3_538, (s32) temp_r4_541, &arg6);
            } else {
                temp_r3_549 = MKModel_GetWorldMatrix(temp_r3_538);
                M2C_FIELD(&arg6, f64 *, 0) = (f64) M2C_FIELD(temp_r3_549, f64 *, 0x30);
                M2C_FIELD(&arg6, f64 *, 8) = (f64) M2C_FIELD(temp_r3_549, f64 *, 0x38);
            }
        } else if (temp_r24_513->unk40 & 4) {
            temp_r3_559 = temp_r24_513->unk34;
            M2C_FIELD(&arg6, f64 *, 0) = (f64) M2C_FIELD(temp_r3_559, f64 *, 0x30);
            M2C_FIELD(&arg6, f64 *, 8) = (f64) M2C_FIELD(temp_r3_559, f64 *, 0x38);
        }
        if (temp_r31_525 != 0) {
            arg_sp1C8.Init(&arg6, (MKProp *) temp_r24_513->unk30);
            if (arg5 != NULL) {
                arg5->Message(&arg_sp1C8);
            }
        }
        if (((temp_r31_525 == 0) || (arg_sp1D8 == 0)) && (arg2 != -1)) {
            MKModel_CalculateNodeWorldPosition(arg0->unk8, arg2, (MKVector3 *) &arg_sp1B8);
            if (arg1 >= 0) {
                MKModel_CalculateNodeWorldMatrix(arg0->unk8, arg1, (Matrix *) &arg_sp220);
                arg_sp260.InverseSimple((Matrix *) &arg_sp220);
            } else {
                arg_sp260.InverseSimple(MKModel_GetWorldMatrix(arg0->unk8));
            }
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r23, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            arg_sp178 = arg_spB8;
            arg_spC0 = arg_sp1C0 - arg6.unk8;
            arg_sp180 = (f64) arg_spC0;
            arg_spA8 = ((f32) arg_sp180 * arg_sp280) + (((f32) arg_sp178 * arg_sp260) + (arg_sp17C * arg_sp270));
            arg_spAC = ((f32) arg_sp180 * arg_sp284) + (((f32) arg_sp178 * arg_sp264) + (arg_sp17C * arg_sp274));
            arg_spB0 = ((f32) arg_sp180 * arg_sp288) + (((f32) arg_sp178 * arg_sp268) + (arg_sp17C * arg_sp278));
            arg_sp1A8 = (f64) arg_spA8;
            arg_spA0 = 1.0f;
            arg_sp1B0 = (f64) arg_spB0;
            arg_sp98 = 0.0f;
            arg_sp9C = 0.0f;
            var_f3_664 = ((f32) arg_sp1B0 * (f32) arg_sp1B0) + (((f32) arg_sp1A8 * (f32) arg_sp1A8) + (arg_sp1AC * arg_sp1AC));
            arg_sp1A0 = (f64) arg_spA0;
            arg_sp198 = (f64) arg_sp98;
            if (var_f3_664 > 0.000001f) {
                Normalise(*((MKVector3 *) &arg_sp168));
                arg_sp1A8 = arg_sp168;
                arg_sp1B0 = arg_sp170;
                var_f3_664 = ((f32) arg_sp1B0 * (f32) arg_sp1A0) + (((f32) arg_sp1A8 * (f32) arg_sp198) + (arg_sp1AC * arg_sp19C));
            }
            if ((var_f3_664 < arg8) && (var_f3_664 > arg9)) {
                temp_f5_698 = (arg_sp19C * (f32) arg_sp1B0) - ((f32) arg_sp1A0 * arg_sp1AC);
                temp_f3_701 = ((f32) arg_sp1A0 * (f32) arg_sp1A8) - ((f32) arg_sp198 * (f32) arg_sp1B0);
                arg_sp188 = temp_f5_698;
                temp_f4_704 = ((f32) arg_sp198 * arg_sp1AC) - (arg_sp19C * (f32) arg_sp1A8);
                arg_sp18C = temp_f3_701;
                arg_sp190 = temp_f4_704;
                var_f4_710 = (temp_f4_704 * temp_f4_704) + ((temp_f5_698 * temp_f5_698) + (temp_f3_701 * temp_f3_701));
                if (var_f4_710 > 0.000001f) {
                    if (var_f4_710 > 0.0f) {
                        temp_f1_716 = __frsqrte(var_f4_710);
                        temp_f1_722 = 0.5 * temp_f1_716 * -(((f64) var_f4_710 * (temp_f1_716 * temp_f1_716)) - 3.0);
                        temp_f1_726 = 0.5 * temp_f1_722 * -(((f64) var_f4_710 * (temp_f1_722 * temp_f1_722)) - 3.0);
                        var_f4_710 = (f32) ((f64) var_f4_710 * (0.5 * temp_f1_726 * -(((f64) var_f4_710 * (temp_f1_726 * temp_f1_726)) - 3.0)));
                    } else if (var_f4_710 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_710 = __float_nan;
                    } else {
                        arg_sp10 = var_f4_710;
                        temp_r3_745 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
                        switch (temp_r3_745) {      /* irregular */
                        case 0x7F800000:
                            if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                                var_r0_755 = 1;
                            } else {
                                var_r0_755 = 2;
                            }
                            break;
                        case 0x0:
                            if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                                var_r0_755 = 5;
                            } else {
                                var_r0_755 = 3;
                            }
                            break;
                        default:
                            var_r0_755 = 4;
                            break;
                        }
                        if (var_r0_755 == 1) {
                            var_f4_710 = __float_nan;
                        }
                    }
                    var_f3_777 = 1.0f / var_f4_710;
                } else {
                    var_f3_777 = 0.0f;
                }
                arg_sp188 *= var_f3_777;
                arg_sp18C *= var_f3_777;
                arg_sp190 *= var_f3_777;
                M2C_STRUCT_COPY((s32) &arg_sp1DC + 4, (s32) (&identity - 4) + 4, 0x40);
                arg_sp1E0.SetRotateAroundAxis(*((MKVector3 *) &arg_sp188), arg11);
                arg_sp88 = ((f32) arg_sp1A0 * arg_sp200) + (((f32) arg_sp198 * arg_sp1E0) + (arg_sp19C * arg_sp1F0));
                arg_sp8C = ((f32) arg_sp1A0 * arg_sp204) + (((f32) arg_sp198 * arg_sp1E4) + (arg_sp19C * arg_sp1F4));
                arg_sp90 = ((f32) arg_sp1A0 * arg_sp208) + (((f32) arg_sp198 * arg_sp1E8) + (arg_sp19C * arg_sp1F8));
                arg_sp1A8 = (f64) arg_sp88;
                arg_sp1B0 = (f64) arg_sp90;
                arg_sp158 = (f64) arg_sp88;
                arg_sp160 = (f64) arg_sp90;
                *temp_r29_522 = 1;
            } else if (var_f3_664 < arg9) {
                arg_sp1A8 = 0.0f;
                arg_sp1AC = 0.0f;
                arg_sp1B0 = 1.0f;
                *temp_r29_522 = 0;
            } else {
                *temp_r29_522 = 1;
            }
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
            arg_sp118 = arg_sp68;
            arg_sp70 = (f32) arg_sp1B0 * arg14;
            arg_sp120 = (f64) arg_sp70;
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r28, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            arg_sp128 = arg_sp78;
            arg_sp80 = M2C_FIELD(temp_r28_520, f32 *, 8) * (1.0f - arg14);
            arg_sp130 = (f64) arg_sp80;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp138 = arg_sp58;
            arg_sp60 = (f32) arg_sp130 + (f32) arg_sp120;
            arg_sp140 = (f64) arg_sp60;
            Normalise(*((MKVector3 *) &arg_sp148));
            M2C_FIELD(temp_r28_520, f64 *, 0) = arg_sp148;
            M2C_FIELD(temp_r28_520, f32 *, 8) = arg_sp150;
        }
    } else {
        if ((arg5 != NULL) && (temp_r31_525 == 0)) {
            arg5->Message(&arg_sp1C8);
        }
        if ((temp_r31_525 == 0) || (arg_sp1D8 == 0)) {
            arg_sp38 = 0.0f;
            arg_sp3C = 0.0f;
            arg_sp40 = 1.0f;
            arg_spC8 = (f64) arg_sp38;
            arg_spD0 = (f64) arg_sp40;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
            arg_spD8 = arg_sp28;
            arg_sp30 = (f32) arg_spD0 * arg14;
            arg_spE0 = (f64) arg_sp30;
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r28, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            arg_spE8 = arg_sp48;
            arg_sp50 = M2C_FIELD(temp_r28_520, f32 *, 8) * (1.0f - arg14);
            arg_spF0 = (f64) arg_sp50;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_spF8 = arg_sp18;
            arg_sp20 = (f32) arg_spF0 + (f32) arg_spE0;
            arg_sp100 = (f64) arg_sp20;
            Normalise(*((MKVector3 *) &arg_sp108));
            M2C_FIELD(temp_r28_520, f64 *, 0) = arg_sp108;
            M2C_FIELD(temp_r28_520, f32 *, 8) = arg_sp110;
        }
    }
    if (temp_r31_525 != 0) {
        var_r0_967 = arg_sp1D8;
    } else {
        var_r0_967 = temp_r31_525;
    }
    *temp_r30_523 = var_r0_967;
}
#endif

#if 0 // DRAFT: illegal type
void KDSP_Actor::UpdateLipAnim(float arg0) {
    s32 sp34;
    s32 sp30;
    s32 sp24;
    s32 sp20;
    s16 spA;
    s16 sp8;
    MKAnim *temp_r4_1015;
    f32 temp_f0_1213;
    f32 temp_f0_1280;
    f32 temp_f0_1286;
    f32 temp_f1_1133;
    f32 temp_f1_1176;
    f32 temp_f30_1144;
    f32 temp_ret_1133;
    f32 var_f1_1119;
    f32 var_f1_1162;
    f32 var_f1_1251;
    f32 var_f29_1212;
    f32 var_f29_1285;
    f32 var_f30_1183;
    s16 temp_r0_1024;
    s32 temp_r0_1061;
    s32 temp_r0_1091;
    s32 temp_r3_1006;
    s32 temp_r5_1072;
    s32 var_r4_1074;
    u8 var_r27_1080;
    void *temp_r29_1068;
    void *temp_r31_1014;

    temp_r3_1006 = this->unkBC;
    if ((temp_r3_1006 != -1) && ((s32) this->unk80 != -1) && (temp_r31_1014 = this->unk9C + (temp_r3_1006 * 0x18), temp_r4_1015 = M2C_FIELD(temp_r31_1014, MKAnim **, 8), ((temp_r4_1015 == NULL) == 0))) {
        this->unk38->GetStartAndEnd(temp_r4_1015, &spA, &sp8);
        temp_r0_1024 = sp8 - spA;
        if (temp_r0_1024 == 0) {
            ((Animation *) (MKModel_GetAnimation(this->unk38->unk8)))->TweenNode((f32) spA, M2C_FIELD(temp_r31_1014, f32 *, 0xC), this->unk80, 0U, 0U);
            return;
        }
        if ((s8) init_1397 == 0) {
            l_bVoiceStarted_1396 = 0;
            init_1397 = 1;
        }
        if ((s8) init_1400 == 0) {
            l_prevAwfFrame_1399 = 0;
            init_1400 = 1;
        }
        temp_r0_1061 = this->unkB8;
        if (temp_r0_1061 != -1) {
            temp_r29_1068 = this->unk58 + (temp_r0_1061 * 0x24);
            temp_r5_1072 = M2C_FIELD(temp_r29_1068, s32 *, 0x14) - 1;
            var_r4_1074 = (s32) arg0 - M2C_FIELD(temp_r29_1068, s32 *, 0);
            if (temp_r5_1072 < var_r4_1074) {
                var_r4_1074 = temp_r5_1072;
            }
            var_r27_1080 = *(M2C_FIELD(temp_r29_1068, s32 *, 0x18) + var_r4_1074);
            if ((u8) l_bVoiceStarted_1396 == 0) {
                l_prevAwfFrame_1399 = var_r27_1080;
                l_bVoiceStarted_1396 = 1;
            }
            if (var_r27_1080 < (u8) l_prevAwfFrame_1399) {
                var_r4_1074 = lit_1411;
                temp_r0_1091 = l_prevAwfFrame_1399 - var_r27_1080;
                if (temp_r0_1091 < var_r4_1074) {
                    var_r4_1074 = temp_r0_1091;
                }
                var_r27_1080 = l_prevAwfFrame_1399 - (u8) var_r4_1074;
            }
            l_prevAwfFrame_1399 = var_r27_1080;
            ((KDSP_Actor *) (M2C_FIELD(temp_r31_1014, KDSP_Actor **, 0x14)))->GetEnvelope(var_r4_1074);
            var_f1_1119 = (arg0 - (f32) M2C_FIELD(temp_r31_1014, s32 *, 0)) / (f32) M2C_FIELD(temp_r31_1014, s32 *, 4);
            if (var_f1_1119 < 1.0f) {

            } else {
                var_f1_1119 = 1.0f;
            }
            if (var_f1_1119 > 0.0f) {

            } else {
                var_f1_1119 = 0.0f;
            }
            temp_ret_1133 = ((KDBasicEnvelope *) (M2C_ERROR(/* Read from unset register $r3 */)))->GetValue(var_f1_1119);
            temp_f1_1133 = temp_ret_1133;
            temp_f30_1144 = (f32) var_r27_1080 / 255.0f;
            ((KDSP_Actor *) (M2C_FIELD(temp_r29_1068, KDSP_Actor **, 0x20)))->GetEnvelope((s32) (u32) M2C_BITWISE(u64, temp_ret_1133));
            var_f1_1162 = (arg0 - (f32) M2C_FIELD(temp_r29_1068, s32 *, 0)) / (f32) M2C_FIELD(temp_r29_1068, s32 *, 4);
            if (var_f1_1162 < 1.0f) {

            } else {
                var_f1_1162 = 1.0f;
            }
            if (var_f1_1162 > 0.0f) {

            } else {
                var_f1_1162 = 0.0f;
            }
            temp_f1_1176 = ((KDBasicEnvelope *) (M2C_ERROR(/* Read from unset register $r3 */)))->GetValue(var_f1_1162);
            if ((u8) M2C_FIELD(temp_r29_1068, u8 *, 0x10) != 0) {
                var_f30_1183 = (temp_f30_1144 * temp_f1_1176) + (temp_f1_1133 * (1.0f - temp_f1_1176));
            } else if (temp_f1_1176 < 0.1f) {
                var_f30_1183 = temp_f1_1133;
            } else {
                var_f30_1183 = temp_f30_1144 * temp_f1_1133;
            }
            sp34 = sp8 ^ 0x80000000;
            sp30 = 0x43300000;
            var_f29_1212 = ((f32) temp_r0_1024 * var_f30_1183) + (f32) spA;
            temp_f0_1213 = (f32) sp8;
            if (var_f29_1212 < temp_f0_1213) {

            } else {
                var_f29_1212 = temp_f0_1213;
            }
            ((Animation *) (MKModel_GetAnimation(this->unk38->unk8)))->TweenNode(var_f29_1212, M2C_FIELD(temp_r31_1014, f32 *, 0xC), this->unk80, 0U, 0U);
            return;
        }
        l_bVoiceStarted_1396 = 1;
        ((KDSP_Actor *) (M2C_FIELD(temp_r31_1014, KDSP_Actor **, 0x14)))->GetEnvelope(M2C_ERROR(/* Read from unset register $r4 */));
        var_f1_1251 = (arg0 - (f32) M2C_FIELD(temp_r31_1014, s32 *, 0)) / (f32) M2C_FIELD(temp_r31_1014, s32 *, 4);
        if (var_f1_1251 < 1.0f) {

        } else {
            var_f1_1251 = 1.0f;
        }
        if (var_f1_1251 > 0.0f) {

        } else {
            var_f1_1251 = 0.0f;
        }
        temp_f0_1280 = ((KDBasicEnvelope *) (M2C_ERROR(/* Read from unset register $r3 */)))->GetValue(var_f1_1251) * (f32) temp_r0_1024;
        sp24 = sp8 ^ 0x80000000;
        sp20 = 0x43300000;
        var_f29_1285 = (f32) spA + temp_f0_1280;
        temp_f0_1286 = (f32) sp8;
        if (var_f29_1285 < temp_f0_1286) {

        } else {
            var_f29_1285 = temp_f0_1286;
        }
        ((Animation *) (MKModel_GetAnimation(this->unk38->unk8)))->TweenNode(var_f29_1285, M2C_FIELD(temp_r31_1014, f32 *, 0xC), this->unk80, 0U, 0U);
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void KDSP_Actor::UpdateSoundAnimEvents(const MKVector3 &arg0, int arg1) {
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    MKAnimScript *temp_r3_1326;
    u8 var_r31_1333;
    void *temp_r3_1353;

    temp_r3_1326 = this->unk38;
    if ((temp_r3_1326 != NULL) && !(this->unk40 & 8)) {
        var_r31_1333 = 0;
        if (((u32) temp_r3_1326->unk20 == (u32) this->unk130) && ((s32) this->unk134 == temp_r3_1326->GetCurrentFrame())) {
            var_r31_1333 = 1;
        }
        this->unk130 = this->unk38->unk20;
        this->unk134 = this->unk38->GetCurrentFrame();
        if (var_r31_1333 == 0) {
            temp_r3_1353 = MKModel_GetWorldMatrix(this->unk38->unk8);
            sp28 = M2C_FIELD(temp_r3_1353, f64 *, 0x30);
            sp30 = M2C_FIELD(temp_r3_1353, f64 *, 0x38);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r29, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            sp18 = sp8;
            sp10 = (f32) sp30 - arg0.unk8;
            sp20 = (f64) sp10;
            KDSound_Play3d(this->unk38, (MKVector3 *) &sp28, (u32) arg1, ((f32) sp20 * (f32) sp20) + (((f32) sp18 * (f32) sp18) + (unksp1C * unksp1C)), 0U);
        }
    }
}
#endif

#if 0 // DRAFT: illegal type
void KDSP_Actor::UpdateHeadAnim(float arg0) {
    s32 sp24;
    s32 sp20;
    s16 spA;
    s16 sp8;
    MKAnim *temp_r4_1410;
    f32 temp_f0_1487;
    f32 temp_f0_1493;
    f32 var_f1_1458;
    f32 var_f31_1492;
    s16 temp_r0_1419;
    s32 temp_r3_1401;
    void *temp_r31_1409;

    temp_r3_1401 = this->unkC0;
    if ((temp_r3_1401 != -1) && ((s32) this->unk7C != -1) && (temp_r31_1409 = this->unkA4 + (temp_r3_1401 * 0x18), temp_r4_1410 = M2C_FIELD(temp_r31_1409, MKAnim **, 8), ((temp_r4_1410 == NULL) == 0))) {
        this->unk38->GetStartAndEnd(temp_r4_1410, &spA, &sp8);
        temp_r0_1419 = sp8 - spA;
        if (temp_r0_1419 == 0) {
            ((Animation *) (MKModel_GetAnimation(this->unk38->unk8)))->TweenNode((f32) spA, M2C_FIELD(temp_r31_1409, f32 *, 0xC), this->unk7C, 0U, 0U);
            return;
        }
        ((KDSP_Actor *) (M2C_FIELD(temp_r31_1409, KDSP_Actor **, 0x14)))->GetEnvelope(M2C_ERROR(/* Read from unset register $r4 */));
        var_f1_1458 = (arg0 - (f32) M2C_FIELD(temp_r31_1409, s32 *, 0)) / (f32) M2C_FIELD(temp_r31_1409, s32 *, 4);
        if (var_f1_1458 < 1.0f) {

        } else {
            var_f1_1458 = 1.0f;
        }
        if (var_f1_1458 > 0.0f) {

        } else {
            var_f1_1458 = 0.0f;
        }
        temp_f0_1487 = ((KDBasicEnvelope *) (M2C_ERROR(/* Read from unset register $r3 */)))->GetValue(var_f1_1458) * (f32) temp_r0_1419;
        sp24 = sp8 ^ 0x80000000;
        sp20 = 0x43300000;
        var_f31_1492 = (f32) spA + temp_f0_1487;
        temp_f0_1493 = (f32) sp8;
        if (var_f31_1492 < temp_f0_1493) {

        } else {
            var_f31_1492 = temp_f0_1493;
        }
        ((Animation *) (MKModel_GetAnimation(this->unk38->unk8)))->TweenNode(var_f31_1492, M2C_FIELD(temp_r31_1409, f32 *, 0xC), this->unk7C, 0U, 0U);
    }
}
#endif

#if 0 // DRAFT: illegal type
void KDSP_Actor::UpdateBodyAnim(float arg0, bool arg1, bool arg2) {
    KDS_Message_PropBodyAnimUpdate spC;
    s16 spA;
    s16 sp8;
    MKAnim *temp_r0_1542;
    MKAnim *temp_r3_1539;
    MKAnimScript *var_r0_1582;
    MKAnimScript *var_r4_1574;
    f32 temp_f0_1561;
    f32 temp_f1_1681;
    f32 temp_f31_1670;
    f32 var_f2_1553;
    f32 var_f30_1668;
    f32 var_f30_1683;
    f32 var_f3_1560;
    s16 temp_r0_1620;
    s32 temp_r0_1532;
    u32 temp_r3_1596;
    u8 var_r3_1569;
    void *temp_r31_1538;

    temp_r0_1532 = this->unkC8;
    if (temp_r0_1532 != -1) {
        temp_r31_1538 = this->unkAC + (temp_r0_1532 * 0x18);
        temp_r3_1539 = M2C_FIELD(temp_r31_1538, MKAnim **, 8);
        if (temp_r3_1539 != NULL) {
            temp_r0_1542 = this->unk128;
            if ((temp_r0_1542 != NULL) && (temp_r3_1539 != temp_r0_1542)) {
                this->unk12C = 0.0f;
            }
            if (((u8) M2C_FIELD(temp_r31_1538, u8 *, 0x10) >> 7U) & 1) {
                var_f2_1553 = 1.25f;
            } else {
                var_f2_1553 = 2.5f;
            }
            var_f3_1560 = 1.0f;
            temp_f0_1561 = (var_f2_1553 * gUpdateTimeDelta) + this->unk12C;
            if (var_f3_1560 < temp_f0_1561) {

            } else {
                var_f3_1560 = temp_f0_1561;
            }
            this->unk12C = var_f3_1560;
            var_r3_1569 = 1;
            if ((u32) this->unk30 != 0) {
                var_r4_1574 = NULL;
                spC.unk4 = 0;
                if (this->unk40 & 0x20) {
                    if (((u8) M2C_FIELD(temp_r31_1538, u8 *, 0x10) >> 6U) & 1) {
                        var_r0_1582 = this->unk70;
                    } else {
                        var_r0_1582 = this->unk74;
                    }
                    this->unk38 = var_r0_1582;
                    var_r4_1574 = var_r0_1582;
                }
                spC.Init(var_r4_1574, M2C_FIELD(temp_r31_1538, MKAnim **, 8), this->unk12C, arg0, 0.0f);
                temp_r3_1596 = this->unk30;
                M2C_FIELD(M2C_FIELD(temp_r3_1596, void **, 0x44), M2C_UNK (**)(u32, KDS_Message_PropBodyAnimUpdate *), 0x2C)(temp_r3_1596, &spC);
                var_r3_1569 = (u8) spC.unk1C;
            }
            if (var_r3_1569 != 0) {
                this->unk38->SetAnim(M2C_FIELD(temp_r31_1538, MKAnim **, 8), 1.0f, 0.0f, 0x20, -1);
                this->unk38->GetStartAndEnd(M2C_FIELD(temp_r31_1538, MKAnim **, 8), &spA, &sp8);
                temp_r0_1620 = sp8 - spA;
                if (temp_r0_1620 == 0) {
                    ((Animation *) (MKModel_GetAnimation(this->unk38->unk8)))->Tween((f32) spA, this->unk12C);
                    this->unk38->SetCurrentFrame((f32) spA, 0U);
                } else {
                    var_f30_1668 = (arg0 - (f32) M2C_FIELD(temp_r31_1538, s32 *, 0)) / (f32) M2C_FIELD(temp_r31_1538, s32 *, 4);
                    temp_f31_1670 = (f32) temp_r0_1620;
                    ((KDSP_Actor *) (M2C_FIELD(temp_r31_1538, KDSP_Actor **, 0x14)))->GetEnvelope(0x43300000);
                    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
                        var_f30_1668 = ((KDBasicEnvelope *) (M2C_ERROR(/* Read from unset register $r3 */)))->GetValue(var_f30_1668);
                    }
                    temp_f1_1681 = (f32) fmod(temp_f31_1670 * var_f30_1668, temp_f31_1670);
                    var_f30_1683 = temp_f1_1681;
                    if (arg2 != 0) {
                        var_f30_1683 = (f32) floor((f64) temp_f1_1681);
                    }
                    ((Animation *) (MKModel_GetAnimation(this->unk38->unk8)))->Tween((f32) spA + var_f30_1683, this->unk12C);
                    this->unk38->SetCurrentFrame((f32) spA + var_f30_1683, 0U);
                }
            }
            this->unk128 = M2C_FIELD(temp_r31_1538, MKAnim **, 8);
        }
    }
}
#endif

#if 0 // DRAFT: illegal type
void KDSP_Actor::UpdatePosRot(float arg0, bool *arg1, int *arg2) {
    KDBasicEnvelope *temp_r26_1765;
    KDSP_Bar *temp_r27_1758;
    MKModel *temp_r3_1916;
    Matrix *temp_r3_2047;
    Matrix *var_r3_1921;
    f32 temp_f7_1863;
    f32 var_f0_1834;
    f32 var_f1_1779;
    f32 var_f1_1794;
    f32 var_f1_1932;
    f32 var_f31_1802;
    f32 var_f3_1842;
    s32 temp_r0_1753;
    u32 temp_r3_2064;
    void *temp_r31_1759;
    void *temp_r3_1858;
    void *temp_r3_1905;
    void *temp_r4_1854;
    void *temp_r5_1851;
    *arg2 = 0;
    *arg1 = 0;
    temp_r0_1753 = this->unkCC;
    if (temp_r0_1753 != -1) {
        temp_r27_1758 = this->unkB4 + (temp_r0_1753 * 0x10);
        temp_r31_1759 = temp_r27_1758->unk8;
        temp_r27_1758->unkC->GetEnvelope((s32) arg1);
        temp_r26_1765 = M2C_ERROR(/* Read from unset register $r3 */);
        var_f1_1779 = (arg0 - (f32) temp_r27_1758->unk0) / (f32) temp_r27_1758->unk4;
        if (var_f1_1779 < 1.0f) {

        } else {
            var_f1_1779 = 1.0f;
        }
        if (var_f1_1779 > 0.0f) {

        } else {
            var_f1_1779 = 0.0f;
        }
        var_f1_1794 = temp_r26_1765->GetValue(var_f1_1779);
        if (var_f1_1794 < 1.0f) {

        } else {
            var_f1_1794 = 1.0f;
        }
        var_f31_1802 = 0.0f;
        if (var_f1_1794 > var_f31_1802) {
            var_f31_1802 = var_f1_1794;
        }
        arg_sp14 = 0.0f;
        arg_sp80.GetMeasure(var_f31_1802, temp_r31_1759 + 8, KDSpline_PositionMixer);
        arg_spF0 = arg_sp80;
        arg_spF8 = arg_sp88;
        *arg1 = M2C_FIELD(temp_r31_1759, u8 *, 5);
        arg_sp1C = 0;
        arg_sp18 = 0.0f;
        if (KDSP_ToolsGetSplinePercent(temp_r27_1758, temp_r31_1759 + 8, temp_r26_1765, arg0, arg_sp1C, arg_sp18) != 0) {
            var_f0_1834 = 0.0f;
            if (var_f0_1834 > arg_sp18) {

            } else {
                var_f0_1834 = arg_sp18;
            }
            var_f3_1842 = 1.0f;
            if (var_f3_1842 < var_f0_1834) {

            } else {
                var_f3_1842 = var_f0_1834;
            }
            arg_sp18 = var_f3_1842;
            temp_r5_1851 = M2C_FIELD(temp_r31_1759, void **, 0x28);
            temp_r4_1854 = temp_r5_1851 + (arg_sp1C << 5);
            temp_r3_1858 = temp_r5_1851 + ((arg_sp1C + 1) << 5);
            temp_f7_1863 = 1.0f - var_f3_1842;
            arg_spD0 = M2C_FIELD(temp_r4_1854, f64 *, 0);
            arg_spD8 = M2C_FIELD(temp_r4_1854, f64 *, 8);
            arg_spC0 = M2C_FIELD(temp_r3_1858, f64 *, 0);
            arg_spC8 = M2C_FIELD(temp_r3_1858, f64 *, 8);
            if ((u8) M2C_FIELD(temp_r31_1759, u8 *, 4) != 0) {
                arg_spE0 = ((f32) arg_spD0 * temp_f7_1863) + ((f32) arg_spC0 * var_f3_1842);
                arg_spE4 = (arg_spD4 * temp_f7_1863) + (arg_spC4 * var_f3_1842);
                arg_spE8 = ((f32) arg_spD8 * temp_f7_1863) + ((f32) arg_spC8 * var_f3_1842);
            } else {
                KDMath_SmoothToAngle((f32) arg_spD8, (f32) arg_spC8, var_f3_1842);
                KDMath_SmoothToAngle(arg_spD4, arg_spC4, arg_sp18);
                KDMath_SmoothToAngle((f32) arg_spD0, (f32) arg_spC0, arg_sp18);
                arg_spE0 = M2C_ERROR(/* Read from unset register $f1 */);
                arg_spE4 = M2C_ERROR(/* Read from unset register $f1 */);
                arg_spE8 = M2C_ERROR(/* Read from unset register $f1 */);
            }
        } else {
            temp_r3_1905 = M2C_FIELD(temp_r31_1759, void **, 0x28);
            arg_spE0 = M2C_FIELD(temp_r3_1905, f32 *, 0);
            arg_spE4 = M2C_FIELD(temp_r3_1905, f32 *, 4);
            arg_spE8 = M2C_FIELD(temp_r3_1905, f32 *, 8);
            arg_spEC = 1.0f;
        }
        temp_r3_1916 = GetModel();
        if (this->unk40 & 4) {
            var_r3_1921 = this->unk34;
        } else {
            var_r3_1921 = MKModel_GetWorldMatrix(temp_r3_1916);
        }
        if ((u8) M2C_FIELD(temp_r31_1759, u8 *, 4) != 0) {
            var_f1_1932 = 0.1f + var_f31_1802;
            if (var_f1_1932 < 1.0f) {

            } else {
                var_f1_1932 = 1.0f;
            }
            arg_sp10 = 0.0f;
            arg_sp70.GetMeasure(var_f1_1932, temp_r31_1759 + 8, KDSpline_PositionMixer);
            arg_spB0 = arg_sp70;
            arg_spB8 = arg_sp78;
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            arg_sp60 = arg_sp20;
            arg_sp28 = (f32) arg_spB8 - (f32) arg_spF8;
            arg_spA0 = arg_sp20;
            arg_sp68 = (f64) arg_sp28;
            arg_spA8 = (f64) arg_sp28;
        }
        if ((this->unk40 & 4) || ((u32) this->unk30 != 0)) {
            if ((u8) M2C_FIELD(temp_r31_1759, u8 *, 4) != 0) {
                if ((((f32) arg_spA8 * (f32) arg_spA8) + (((f32) arg_spA0 * (f32) arg_spA0) + (arg_spA4 * arg_spA4))) > 0.000001f) {
                    M2C_STRUCT_COPY((s32) &arg_sp1EC + 4, (s32) (&identity - 4) + 4, 0x40);
                    arg_sp1F0.SetRotationPYR(*((MKVector3 *) &arg_spE0));
                    M2C_STRUCT_COPY((s32) &arg_sp1AC + 4, (s32) (&identity - 4) + 4, 0x40);
                    arg_sp1B0.SetLookAt(*((MKVector3 *) &arg_spB0), *((MKVector3 *) &arg_spF0));
                    arg_sp1F0.Multiply3x3((Matrix *) &arg_sp1F0, (Matrix *) &arg_sp1B0);
                    arg_sp50.GetRotationPYR();
                    arg_spE0 = arg_sp50;
                    arg_spE8 = arg_sp58;
                } else {
                    arg_sp40.GetRotationPYR();
                    arg_spE0 = arg_sp40;
                    arg_spE4 = arg_sp44;
                    arg_spE8 = arg_sp48;
                    arg_spEC = 1.0f;
                }
            }
            if (this->unk40 & 4) {
                this->unk34->SetRotationPYR(*((MKVector3 *) &arg_spE0));
                temp_r3_2047 = this->unk34;
                temp_r3_2047->unk30 = (f32) arg_spF0;
                temp_r3_2047->unk34 = arg_spF4;
                temp_r3_2047->unk38 = (f32) arg_spF8;
                temp_r3_2047->unk3C = 1.0f;
                return;
            }
            arg_sp184 = 0;
            arg_sp180.Init(*((MKVector3 *) &arg_spF0), *((MKVector3 *) &arg_spE0));
            temp_r3_2064 = this->unk30;
            M2C_FIELD(M2C_FIELD(temp_r3_2064, void **, 0x44), M2C_UNK (**)(u32, M2C_UNK *), 0x2C)(temp_r3_2064, &arg_sp180);
            return;
        }
        M2C_STRUCT_COPY((s32) &arg_sp13C + 4, (s32) (var_r3_1921 - 4) + 4, 0x40);
        if ((u8) M2C_FIELD(temp_r31_1759, u8 *, 4) != 0) {
            if ((((f32) arg_spA8 * (f32) arg_spA8) + (((f32) arg_spA0 * (f32) arg_spA0) + (arg_spA4 * arg_spA4))) > 0.000001f) {
                arg_sp140.SetRotationPYR(*((MKVector3 *) &arg_spE0));
                M2C_STRUCT_COPY((s32) &arg_spFC + 4, (s32) (&identity - 4) + 4, 0x40);
                arg_sp100.SetLookAt(*((MKVector3 *) &arg_spB0), *((MKVector3 *) &arg_spF0));
                arg_sp140.Multiply3x3((Matrix *) &arg_sp140, (Matrix *) &arg_sp100);
            }
        } else {
            arg_sp140.SetRotationPYR(*((MKVector3 *) &arg_spE0));
        }
        arg_sp170 = (f32) arg_spF0;
        arg_sp174 = arg_spF4;
        arg_sp178 = (f32) arg_spF8;
        arg_sp17C = 1.0f;
        MKModel_SetWorldMatrix(temp_r3_1916, *((Matrix *) &arg_sp140));
        if (this->unk40 & 1) {
            arg_sp230 = 0.0f;
            arg_sp234 = 0.0f;
            arg_sp238 = 0.0f;
            arg_sp240 = 0.0f;
            arg_sp244 = 0.0f;
            arg_sp248 = 0.0f;
            arg_sp250 = 0.0f;
            arg_sp254 = 0.0f;
            arg_sp258 = 0.0f;
            arg_sp25C = 1.0f;
            arg_sp260 = 0.0f;
            arg_sp264 = 0.0f;
            arg_sp268 = 0;
            arg_sp268 = 0;
            (s8) arg_sp268 = 0;
            arg_sp26C = 0;
            arg_sp270 = 3.4028235e38f;
            arg_sp274 = 0;
            arg_sp278 = 0;
            arg_sp27C = -1;
            arg_sp280 = 0;
            MKModel_CalculateCentre(GetModel(), (MKVector3 *) &arg_sp90);
            if (MKCollision_GetGroundPoint(*((MKVector3 *) &arg_sp90), 5000.0f, (MKCollisionResult *) &arg_sp230, 0, 4, NULL, (MKCollisionMode) 7) != 0) {
                *arg2 = arg_sp274;
                Tools_GroundColor((MKCollisionResult *) &arg_sp30);
                MKModel_SetColor(GetModel(), *((MKVector4 *) &arg_sp30));
            }
            this->unk28 = arg_sp234;
        }
    }
}
#endif

#if 0 // DRAFT: illegal type
s32 KDSP_Actor::GetTweenAnimParams(int arg0, int arg1, float *arg2, float *arg3, int *arg4) {
    s32 temp_r11_2249;
    s32 temp_r12_2222;
    s32 temp_r31_2214;
    s32 var_ctr_2215;
    s32 var_ctr_2242;
    s32 var_r0_2209;
    s32 var_r12_2240;
    s32 var_r29_2213;
    s32 var_r30_2212;
    s32 var_r4_2241;
    s32 var_r9_2210;
    u8 var_r10_2247;
    u8 var_r11_2220;
    void *temp_r10_2221;
    void *temp_r4_2275;
    void *temp_r5_2273;
    void *temp_r5_2277;
    void *temp_r9_2248;

    var_r0_2209 = -1;
    var_r9_2210 = 0;
    var_r30_2212 = -1;
    var_r29_2213 = 0;
    temp_r31_2214 = this->unkA0;
    var_ctr_2215 = temp_r31_2214;
    if (temp_r31_2214 > 0) {
loop_1:
        var_r11_2220 = 0;
        temp_r10_2221 = this->unkA4 + var_r9_2210;
        temp_r12_2222 = M2C_FIELD(temp_r10_2221, s32 *, 0);
        if ((arg0 >= temp_r12_2222) && (arg0 < (s32) (temp_r12_2222 + M2C_FIELD(temp_r10_2221, s32 *, 4)))) {
            var_r11_2220 = 1;
        }
        if (var_r11_2220 != 0) {
            var_r30_2212 = var_r29_2213;
        } else {
            var_r29_2213 += 1;
            var_r9_2210 += 0x18;
            var_ctr_2215 -= 1;
            if (var_ctr_2215 != 0) {
                goto loop_1;
            }
        }
    }
    var_r12_2240 = 0;
    var_r4_2241 = 0;
    var_ctr_2242 = temp_r31_2214;
    if (temp_r31_2214 > 0) {
loop_8:
        var_r10_2247 = 0;
        temp_r9_2248 = this->unkA4 + var_r4_2241;
        temp_r11_2249 = M2C_FIELD(temp_r9_2248, s32 *, 0);
        if ((arg1 >= temp_r11_2249) && (arg1 < (s32) (temp_r11_2249 + M2C_FIELD(temp_r9_2248, s32 *, 4)))) {
            var_r10_2247 = 1;
        }
        if (var_r10_2247 != 0) {
            var_r0_2209 = var_r12_2240;
        } else {
            var_r12_2240 += 1;
            var_r4_2241 += 0x18;
            var_ctr_2242 -= 1;
            if (var_ctr_2242 != 0) {
                goto loop_8;
            }
        }
    }
    if ((var_r30_2212 != -1) && (var_r0_2209 != -1)) {
        temp_r5_2273 = this->unkA4 + 8;
        temp_r4_2275 = *(temp_r5_2273 + (var_r30_2212 * 0x18));
        temp_r5_2277 = *(temp_r5_2273 + (var_r0_2209 * 0x18));
        if ((temp_r4_2275 != NULL) && (temp_r5_2277 != NULL)) {
            *arg2 = (f32) M2C_FIELD(temp_r4_2275, s16 *, 0xA);
            *arg3 = (f32) M2C_FIELD(temp_r5_2277, s16 *, 0xC);
            *arg4 = this->unk7C;
            return 1;
        }
    }
    return 0;
}
#endif

#if 0 // DRAFT: illegal type
void KDSP_Actor::UpdateCurrentBars(int arg0) {
    s32 temp_r0_2351;
    s32 temp_r0_2381;
    s32 temp_r0_2411;
    s32 temp_r0_2441;
    s32 temp_r0_2471;
    s32 temp_r0_2501;
    s32 temp_r5_2340;
    s32 temp_r8_2321;
    s32 temp_r8_2359;
    s32 temp_r8_2389;
    s32 temp_r8_2419;
    s32 temp_r8_2449;
    s32 temp_r8_2479;
    s32 temp_r8_2509;
    s32 var_ctr_2352;
    s32 var_ctr_2382;
    s32 var_ctr_2412;
    s32 var_ctr_2442;
    s32 var_ctr_2472;
    s32 var_ctr_2502;
    s32 var_r5_2315;
    s32 var_r5_2350;
    s32 var_r5_2380;
    s32 var_r5_2410;
    s32 var_r5_2440;
    s32 var_r5_2470;
    s32 var_r5_2500;
    s32 var_r9_2313;
    s32 var_r9_2348;
    s32 var_r9_2378;
    s32 var_r9_2408;
    s32 var_r9_2438;
    s32 var_r9_2468;
    s32 var_r9_2498;
    u8 var_r6_2319;
    u8 var_r6_2357;
    u8 var_r6_2387;
    u8 var_r6_2417;
    u8 var_r6_2447;
    u8 var_r6_2477;
    u8 var_r6_2507;
    void *temp_r7_2320;
    void *temp_r7_2358;
    void *temp_r7_2388;
    void *temp_r7_2418;
    void *temp_r7_2448;
    void *temp_r7_2478;
    void *temp_r7_2508;

    var_r9_2313 = 0;
    this->unkCC = -1;
    var_r5_2315 = 0;
loop_7:
    if (var_r9_2313 < (s32) this->unkB0) {
        var_r6_2319 = 0;
        temp_r7_2320 = this->unkB4 + var_r5_2315;
        temp_r8_2321 = M2C_FIELD(temp_r7_2320, s32 *, 0);
        if ((arg0 >= temp_r8_2321) && (arg0 < (s32) (temp_r8_2321 + M2C_FIELD(temp_r7_2320, s32 *, 4)))) {
            var_r6_2319 = 1;
        }
        if (var_r6_2319 != 0) {
            this->unkCC = var_r9_2313;
        }
        var_r9_2313 += 1;
        var_r5_2315 += 0x10;
        goto loop_7;
    }
    temp_r5_2340 = this->unk40;
    if (!(temp_r5_2340 & 4)) {
        if (temp_r5_2340 & 8) {
            return;
        }
        var_r9_2348 = 0;
        this->unkB8 = -1;
        var_r5_2350 = 0;
        temp_r0_2351 = this->unk54;
        var_ctr_2352 = temp_r0_2351;
        if (temp_r0_2351 > 0) {
loop_12:
            var_r6_2357 = 0;
            temp_r7_2358 = this->unk58 + var_r5_2350;
            temp_r8_2359 = M2C_FIELD(temp_r7_2358, s32 *, 0);
            if ((arg0 >= temp_r8_2359) && (arg0 < (s32) (temp_r8_2359 + M2C_FIELD(temp_r7_2358, s32 *, 4)))) {
                var_r6_2357 = 1;
            }
            if (var_r6_2357 != 0) {
                this->unkB8 = var_r9_2348;
            } else {
                var_r9_2348 += 1;
                var_r5_2350 += 0x24;
                var_ctr_2352 -= 1;
                if (var_ctr_2352 != 0) {
                    goto loop_12;
                }
            }
        }
        var_r9_2378 = 0;
        this->unkBC = -1;
        var_r5_2380 = 0;
        temp_r0_2381 = this->unk98;
        var_ctr_2382 = temp_r0_2381;
        if (temp_r0_2381 > 0) {
loop_19:
            var_r6_2387 = 0;
            temp_r7_2388 = this->unk9C + var_r5_2380;
            temp_r8_2389 = M2C_FIELD(temp_r7_2388, s32 *, 0);
            if ((arg0 >= temp_r8_2389) && (arg0 < (s32) (temp_r8_2389 + M2C_FIELD(temp_r7_2388, s32 *, 4)))) {
                var_r6_2387 = 1;
            }
            if (var_r6_2387 != 0) {
                this->unkBC = var_r9_2378;
            } else {
                var_r9_2378 += 1;
                var_r5_2380 += 0x18;
                var_ctr_2382 -= 1;
                if (var_ctr_2382 != 0) {
                    goto loop_19;
                }
            }
        }
        var_r9_2408 = 0;
        this->unkC0 = -1;
        var_r5_2410 = 0;
        temp_r0_2411 = this->unkA0;
        var_ctr_2412 = temp_r0_2411;
        if (temp_r0_2411 > 0) {
loop_26:
            var_r6_2417 = 0;
            temp_r7_2418 = this->unkA4 + var_r5_2410;
            temp_r8_2419 = M2C_FIELD(temp_r7_2418, s32 *, 0);
            if ((arg0 >= temp_r8_2419) && (arg0 < (s32) (temp_r8_2419 + M2C_FIELD(temp_r7_2418, s32 *, 4)))) {
                var_r6_2417 = 1;
            }
            if (var_r6_2417 != 0) {
                this->unkC0 = var_r9_2408;
            } else {
                var_r9_2408 += 1;
                var_r5_2410 += 0x18;
                var_ctr_2412 -= 1;
                if (var_ctr_2412 != 0) {
                    goto loop_26;
                }
            }
        }
        var_r9_2438 = 0;
        this->unkC8 = -1;
        var_r5_2440 = 0;
        temp_r0_2441 = this->unkA8;
        var_ctr_2442 = temp_r0_2441;
        if (temp_r0_2441 > 0) {
loop_33:
            var_r6_2447 = 0;
            temp_r7_2448 = this->unkAC + var_r5_2440;
            temp_r8_2449 = M2C_FIELD(temp_r7_2448, s32 *, 0);
            if ((arg0 >= temp_r8_2449) && (arg0 < (s32) (temp_r8_2449 + M2C_FIELD(temp_r7_2448, s32 *, 4)))) {
                var_r6_2447 = 1;
            }
            if (var_r6_2447 != 0) {
                this->unkC8 = var_r9_2438;
            } else {
                var_r9_2438 += 1;
                var_r5_2440 += 0x18;
                var_ctr_2442 -= 1;
                if (var_ctr_2442 != 0) {
                    goto loop_33;
                }
            }
        }
        var_r9_2468 = 0;
        this->unkD0 = -1;
        var_r5_2470 = 0;
        temp_r0_2471 = this->unk44;
        var_ctr_2472 = temp_r0_2471;
        if (temp_r0_2471 > 0) {
loop_40:
            var_r6_2477 = 0;
            temp_r7_2478 = this->unk48 + var_r5_2470;
            temp_r8_2479 = M2C_FIELD(temp_r7_2478, s32 *, 0);
            if ((arg0 >= temp_r8_2479) && (arg0 < (s32) (temp_r8_2479 + M2C_FIELD(temp_r7_2478, s32 *, 4)))) {
                var_r6_2477 = 1;
            }
            if (var_r6_2477 != 0) {
                this->unkD0 = var_r9_2468;
            } else {
                var_r9_2468 += 1;
                var_r5_2470 += 0x14;
                var_ctr_2472 -= 1;
                if (var_ctr_2472 != 0) {
                    goto loop_40;
                }
            }
        }
        var_r9_2498 = 0;
        this->unkC4 = -1;
        var_r5_2500 = 0;
        temp_r0_2501 = this->unk4C;
        var_ctr_2502 = temp_r0_2501;
        if (temp_r0_2501 > 0) {
loop_47:
            var_r6_2507 = 0;
            temp_r7_2508 = this->unk50 + var_r5_2500;
            temp_r8_2509 = M2C_FIELD(temp_r7_2508, s32 *, 0);
            if ((arg0 >= temp_r8_2509) && (arg0 < (s32) (temp_r8_2509 + M2C_FIELD(temp_r7_2508, s32 *, 4)))) {
                var_r6_2507 = 1;
            }
            if (var_r6_2507 != 0) {
                this->unkC4 = var_r9_2498;
                return;
            }
            var_r9_2498 += 1;
            var_r5_2500 += 0x14;
            var_ctr_2502 -= 1;
            if (var_ctr_2502 == 0) {
                return;
            }
            goto loop_47;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'ModelSubObjectHide'
void KDSP_Actor::Update(float arg0, const MKVector3 &arg1, bool arg2) {
    s32 spC;
    u8 sp8;
    MKAnimScript *temp_r4_2544;
    MKIniLine *temp_r3_2541;
    s32 temp_r3_2565;

    temp_r3_2541 = this->unk78;
    if (temp_r3_2541 != NULL) {
        temp_r4_2544 = this->unk70;
        if (temp_r4_2544 != NULL) {
            ModelSubObjectHide(temp_r3_2541, temp_r4_2544->unk8);
            this->unk78 = NULL;
        }
    }
    sp8 = 0;
    spC = 0;
    UpdateCurrentBars((s32) arg0);
    UpdatePosRot(arg0, &sp8, &spC);
    temp_r3_2565 = this->unk40;
    if (!(temp_r3_2565 & 4)) {
        if (temp_r3_2565 & 8) {
            return;
        }
        UpdateBodyAnim(arg0, sp8, arg2);
        UpdateSoundAnimEvents(arg1, spC);
        UpdateHeadAnim(arg0);
        UpdateLipAnim(arg0);
        UpdateCloth();
    }
}
#endif

#if 0 // DRAFT: illegal type
void *KDSP_Actor::FindActorPath(const char *arg0) {
    s32 var_r30_2607;
    s32 var_r31_2608;

    var_r30_2607 = 0;
    var_r31_2608 = 0;
loop_4:
    if (var_r30_2607 >= (s32) this->unk68) {
        return NULL;
    }
    if (stricmp(*(this->unk6C + var_r31_2608), arg0) == 0) {
        return this->unk6C + var_r31_2608;
    }
    var_r30_2607 += 1;
    var_r31_2608 += 0x30;
    goto loop_4;
}
#endif

s32 KDSP_Actor::GetMatchingNodeIndex(const char *arg0) {
    s32 temp_r5_2642;

    temp_r5_2642 = this->unk40;
    if ((temp_r5_2642 & 4) || (temp_r5_2642 & 8)) {
        return 0xFFFF;
    }
    return KDSP_ToolsGetMatchingNodeIndex(this->unk38->unk8, arg0);
}

#if 0 // DRAFT: undefined identifier 'pEnvelopeData'
void KDSP_Actor::GetEnvelope(int arg0) {
    pEnvelopeData.unk0->GetEnvelope((s32) this);
}
#endif

#if 0 // DRAFT: undefined identifier 'pInput'
void KDSP_Actor::SetInput(KDInput *arg0) {
    pInput.unk0 = (KDSP_EnvelopeList *) this;
}
#endif

#if 0 // DRAFT: undefined identifier 'pEnvelopeData'
void KDSP_Actor::SetEnvelopeList(KDSP_EnvelopeList *arg0) {
    pEnvelopeData.unk0 = (KDSP_EnvelopeList *) this;
}
#endif

MKModel *KDSP_Actor::GetModel() {
    s32 temp_r4_2694;

    temp_r4_2694 = this->unk40;
    if (temp_r4_2694 & 4) {
        return NULL;
    }
    if (temp_r4_2694 & 8) {
        return this->unk3C;
    }
    return this->unk38->unk8;
}

#if 0 // DRAFT: illegal type
void KDSP_Actor::ParseAWFS(KDSynkerHeap *arg0, MKIniLine *arg1, int arg2) {
    MKIniLine *var_r28_2757;
    MKIniLine *var_r3_2727;
    s32 temp_r3_2749;
    s32 temp_r3_2765;
    s32 var_r27_2726;
    s32 var_r27_2760;
    s32 var_r30_2748;
    void *temp_r31_2742;
    void *temp_r5_2747;

    if (arg2 < (s32) this->unk54) {
        var_r27_2726 = 0;
        var_r3_2727 = arg1->unkC->GetSubLine(arg1);
loop_3:
        if (var_r3_2727 != NULL) {
            var_r27_2726 = (var_r3_2727->unk0 + var_r27_2726) - 1;
            var_r3_2727 = var_r3_2727->unkC->GetNextLine(var_r3_2727);
            goto loop_3;
        }
        temp_r31_2742 = this->unk58 + (arg2 * 0x24);
        M2C_FIELD(temp_r31_2742, s32 *, 0x14) = var_r27_2726;
        if (var_r27_2726 != 0) {
            temp_r5_2747 = arg0->unk18;
            var_r30_2748 = 0;
            temp_r3_2749 = arg0->unk20 - 1;
            arg0->unk18 = temp_r5_2747 + ((var_r27_2726 + temp_r3_2749) & ~temp_r3_2749);
            M2C_FIELD(temp_r31_2742, void **, 0x18) = temp_r5_2747;
            var_r28_2757 = arg1->unkC->GetSubLine(arg1);
loop_10:
            if (var_r28_2757 != NULL) {
                var_r27_2760 = 0;
loop_8:
                if (var_r27_2760 < (s32) (var_r28_2757->unk0 - 1)) {
                    temp_r3_2765 = var_r28_2757->GetInt(var_r27_2760);
                    var_r27_2760 += 1;
                    *(M2C_FIELD(temp_r31_2742, void **, 0x18) + var_r30_2748) = (s8) temp_r3_2765;
                    var_r30_2748 += 1;
                    goto loop_8;
                }
                var_r28_2757 = var_r28_2757->unkC->GetNextLine(var_r28_2757);
                goto loop_10;
            }
        }
    }
}
#endif

#if 0 // DRAFT: illegal type
void KDSP_Actor::ResolveLookEyesBar(KDSynkerHeap *arg0, KDSP_GenericBar *arg1, int arg2, int arg3) {
    s32 temp_r7_2802;
    s32 temp_r9_2812;
    void *temp_r8_2809;
    void *temp_r9_2801;

    if ((void *) this->unk50 == NULL) {
        this->unk4C = arg3;
        if (arg3 != 0) {
            temp_r9_2801 = arg0->unk18;
            temp_r7_2802 = arg0->unk20 - 1;
            arg0->unk18 = temp_r9_2801 + (((arg3 * 0x14) + temp_r7_2802) & ~temp_r7_2802);
            this->unk50 = temp_r9_2801;
        }
    }
    temp_r8_2809 = this->unk50;
    if (temp_r8_2809 != NULL) {
        temp_r9_2812 = arg2 * 0x14;
        *(temp_r8_2809 + temp_r9_2812) = arg1->unkC;
        M2C_FIELD((this->unk50 + temp_r9_2812), s32 *, 4) = (s32) arg1->unk10;
        M2C_FIELD((this->unk50 + temp_r9_2812), s32 *, 0xC) = 0;
        M2C_FIELD((this->unk50 + temp_r9_2812), s8 **, 8) = (s8 *) arg1->unk0;
        M2C_FIELD((this->unk50 + temp_r9_2812), s32 *, 0x10) = 0xFFFF;
    }
}
#endif

#if 0 // DRAFT: illegal type
void KDSP_Actor::ResolveLookHeadBar(KDSynkerHeap *arg0, KDSP_GenericBar *arg1, int arg2, int arg3) {
    s32 temp_r7_2847;
    s32 temp_r9_2857;
    void *temp_r8_2854;
    void *temp_r9_2846;

    if ((void *) this->unk48 == NULL) {
        this->unk44 = arg3;
        if (arg3 != 0) {
            temp_r9_2846 = arg0->unk18;
            temp_r7_2847 = arg0->unk20 - 1;
            arg0->unk18 = temp_r9_2846 + (((arg3 * 0x14) + temp_r7_2847) & ~temp_r7_2847);
            this->unk48 = temp_r9_2846;
        }
    }
    temp_r8_2854 = this->unk48;
    if (temp_r8_2854 != NULL) {
        temp_r9_2857 = arg2 * 0x14;
        *(temp_r8_2854 + temp_r9_2857) = arg1->unkC;
        M2C_FIELD((this->unk48 + temp_r9_2857), s32 *, 4) = (s32) arg1->unk10;
        M2C_FIELD((this->unk48 + temp_r9_2857), s32 *, 0xC) = 0;
        M2C_FIELD((this->unk48 + temp_r9_2857), s8 **, 8) = (s8 *) arg1->unk0;
        M2C_FIELD((this->unk48 + temp_r9_2857), s32 *, 0x10) = 0xFFFF;
    }
}
#endif

#if 0 // DRAFT: illegal type
void KDSP_Actor::ResolvePosBar(KDSynkerHeap *arg0, KDSP_GenericBar *arg1, int arg2, int arg3) {
    s32 temp_r31_2909;
    s32 temp_r3_2898;
    void *temp_r4_2905;
    void *temp_r5_2897;

    if ((void *) this->unkB4 == NULL) {
        this->unkB0 = arg3;
        if (arg3 != 0) {
            temp_r5_2897 = arg0->unk18;
            temp_r3_2898 = arg0->unk20 - 1;
            arg0->unk18 = temp_r5_2897 + (((arg3 * 0x10) + temp_r3_2898) & ~temp_r3_2898);
            this->unkB4 = temp_r5_2897;
        }
    }
    temp_r4_2905 = this->unkB4;
    if (temp_r4_2905 != NULL) {
        temp_r31_2909 = arg2 * 0x10;
        *(temp_r4_2905 + temp_r31_2909) = arg1->unkC;
        M2C_FIELD((this->unkB4 + temp_r31_2909), s32 *, 4) = (s32) arg1->unk10;
        M2C_FIELD((this->unkB4 + temp_r31_2909), void **, 8) = FindActorPath(arg1->unk0);
        M2C_FIELD((this->unkB4 + temp_r31_2909), s32 *, 0xC) = (s32) arg1->unk14;
    }
}
#endif

#if 0 // DRAFT: illegal type
void KDSP_Actor::ResolveBodyBarAnim(KDSynkerHeap *arg0, KDSP_GenericBar *arg1, int arg2, int arg3) {
    ResolveAnim(this->unkAC + (arg2 * 0x18), arg1->unk0);
}
#endif

#if 0 // DRAFT: illegal type
void KDSP_Actor::ResolveBodyBar(KDSynkerHeap *arg0, KDSP_GenericBar *arg1, int arg2, int arg3) {
    f32 var_f0_2982;
    s32 temp_r4_2988;
    s32 temp_r7_2962;
    s32 temp_r9_2972;
    void *temp_r4_2969;
    void *temp_r7_2992;
    void *temp_r9_2961;

    if ((void *) this->unkAC == NULL) {
        this->unkA8 = arg3;
        if (arg3 != 0) {
            temp_r9_2961 = arg0->unk18;
            temp_r7_2962 = arg0->unk20 - 1;
            arg0->unk18 = temp_r9_2961 + (((arg3 * 0x18) + temp_r7_2962) & ~temp_r7_2962);
            this->unkAC = temp_r9_2961;
        }
    }
    temp_r4_2969 = this->unkAC;
    if (temp_r4_2969 != NULL) {
        temp_r9_2972 = arg2 * 0x18;
        *(temp_r4_2969 + temp_r9_2972) = arg1->unkC;
        M2C_FIELD((this->unkAC + temp_r9_2972), s32 *, 4) = (s32) arg1->unk10;
        if ((u8) arg1->unk8 != 0) {
            var_f0_2982 = 0.5f;
        } else {
            var_f0_2982 = 0.9f;
        }
        temp_r4_2988 = temp_r9_2972 + 0x10;
        M2C_FIELD((this->unkAC + temp_r9_2972), f32 *, 0xC) = var_f0_2982;
        temp_r7_2992 = this->unkAC;
        *(temp_r7_2992 + temp_r4_2988) = (*(temp_r7_2992 + temp_r4_2988) & ~0x80) | ((arg1->unk8 << 7) & 0x80);
        M2C_FIELD((this->unkAC + temp_r9_2972), s32 *, 8) = 0;
        M2C_FIELD((this->unkAC + temp_r9_2972), s32 *, 0x14) = (s32) arg1->unk14;
    }
}
#endif

#if 0 // DRAFT: illegal type
void KDSP_Actor::ResolveHeadBarAnim(KDSynkerHeap *arg0, KDSP_GenericBar *arg1, int arg2, int arg3) {
    ResolveAnim(this->unkA4 + (arg2 * 0x18), arg1->unk0);
}
#endif

#if 0 // DRAFT: illegal type
void KDSP_Actor::ResolveHeadBar(KDSynkerHeap *arg0, KDSP_GenericBar *arg1, int arg2, int arg3) {
    f32 var_f0_3062;
    s32 temp_r4_3049;
    s32 temp_r7_3036;
    s32 temp_r8_3046;
    void *temp_r4_3043;
    void *temp_r6_3054;
    void *temp_r9_3035;

    if ((void *) this->unkA4 == NULL) {
        this->unkA0 = arg3;
        if (arg3 != 0) {
            temp_r9_3035 = arg0->unk18;
            temp_r7_3036 = arg0->unk20 - 1;
            arg0->unk18 = temp_r9_3035 + (((arg3 * 0x18) + temp_r7_3036) & ~temp_r7_3036);
            this->unkA4 = temp_r9_3035;
        }
    }
    temp_r4_3043 = this->unkA4;
    if (temp_r4_3043 != NULL) {
        temp_r8_3046 = arg2 * 0x18;
        *(temp_r4_3043 + temp_r8_3046) = arg1->unkC;
        temp_r4_3049 = temp_r8_3046 + 0x10;
        M2C_FIELD((this->unkA4 + temp_r8_3046), s32 *, 4) = (s32) arg1->unk10;
        temp_r6_3054 = this->unkA4;
        *(temp_r6_3054 + temp_r4_3049) = (*(temp_r6_3054 + temp_r4_3049) & ~0x80) | ((arg1->unk8 << 7) & 0x80);
        if ((u8) arg1->unk8 != 0) {
            var_f0_3062 = 0.25f;
        } else {
            var_f0_3062 = 0.5f;
        }
        M2C_FIELD((this->unkA4 + temp_r8_3046), f32 *, 0xC) = var_f0_3062;
        M2C_FIELD((this->unkA4 + temp_r8_3046), s32 *, 0x14) = (s32) arg1->unk14;
        M2C_FIELD((this->unkA4 + temp_r8_3046), s32 *, 8) = 0;
    }
}
#endif

#if 0 // DRAFT: illegal type
void KDSP_Actor::ResolveLipsBarAnim(KDSynkerHeap *arg0, KDSP_GenericBar *arg1, int arg2, int arg3) {
    ResolveAnim(this->unk9C + (arg2 * 0x18), arg1->unk0);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void KDSP_Actor::ResolveAnim(KDSP_AnimBar *arg0, const char *arg1) {
    MKAnimScript *temp_r31_3108;
    MKAnimScript *temp_r3_3133;
    void *var_r3_3109;

    temp_r31_3108 = this->unk70;
    var_r3_3109 = NULL;
    if (temp_r31_3108 != NULL) {
        if (temp_r31_3108->Exists(arg1) != 0) {
            var_r3_3109 = temp_r31_3108->GetAnim(arg1);
        } else {
            var_r3_3109 = NULL;
        }
    }
    if (var_r3_3109 != NULL) {
        arg0->unk8 = (u32) var_r3_3109;
        arg0->unk10 |= 0x40;
        return;
    }
    temp_r3_3133 = this->unk74;
    if (temp_r3_3133 != NULL) {
        arg0->unk8 = temp_r3_3133->GetAnim(arg1);
        arg0->unk10 &= ~0x40;
    }
}
#endif

#if 0 // DRAFT: illegal type
void KDSP_Actor::ResolveLipsBar(KDSynkerHeap *arg0, KDSP_GenericBar *arg1, int arg2, int arg3) {
    f32 var_f0_3183;
    s32 temp_r6_3189;
    s32 temp_r7_3163;
    s32 temp_r9_3173;
    void *temp_r4_3170;
    void *temp_r7_3193;
    void *temp_r9_3162;

    if ((void *) this->unk9C == NULL) {
        this->unk98 = arg3;
        if (arg3 != 0) {
            temp_r9_3162 = arg0->unk18;
            temp_r7_3163 = arg0->unk20 - 1;
            arg0->unk18 = temp_r9_3162 + (((arg3 * 0x18) + temp_r7_3163) & ~temp_r7_3163);
            this->unk9C = temp_r9_3162;
        }
    }
    temp_r4_3170 = this->unk9C;
    if (temp_r4_3170 != NULL) {
        temp_r9_3173 = arg2 * 0x18;
        *(temp_r4_3170 + temp_r9_3173) = arg1->unkC;
        M2C_FIELD((this->unk9C + temp_r9_3173), s32 *, 4) = (s32) arg1->unk10;
        if ((u8) arg1->unk8 != 0) {
            var_f0_3183 = 0.25f;
        } else {
            var_f0_3183 = 0.5f;
        }
        temp_r6_3189 = temp_r9_3173 + 0x10;
        M2C_FIELD((this->unk9C + temp_r9_3173), f32 *, 0xC) = var_f0_3183;
        temp_r7_3193 = this->unk9C;
        *(temp_r7_3193 + temp_r6_3189) = (*(temp_r7_3193 + temp_r6_3189) & ~0x80) | ((arg1->unk8 << 7) & 0x80);
        M2C_FIELD((this->unk9C + temp_r9_3173), s32 *, 0x14) = (s32) arg1->unk14;
        M2C_FIELD((this->unk9C + temp_r9_3173), s32 *, 8) = 0;
    }
}
#endif

#if 0 // DRAFT: illegal type
void KDSP_Actor::ResolveVoiceBar(KDSynkerHeap *arg0, KDSP_GenericBar *arg1, int arg2, int arg3) {
    s32 temp_r31_3236;
    s32 temp_r3_3226;
    s32 temp_r4_3240;
    void *temp_r3_3233;
    void *temp_r5_3225;

    if ((void *) this->unk58 == NULL) {
        this->unk54 = arg3;
        if (arg3 != 0) {
            temp_r5_3225 = arg0->unk18;
            temp_r3_3226 = arg0->unk20 - 1;
            arg0->unk18 = temp_r5_3225 + (((arg3 * 0x24) + temp_r3_3226) & ~temp_r3_3226);
            this->unk58 = temp_r5_3225;
        }
    }
    temp_r3_3233 = this->unk58;
    if (temp_r3_3233 != NULL) {
        temp_r31_3236 = arg2 * 0x24;
        *(temp_r3_3233 + temp_r31_3236) = arg1->unkC;
        temp_r4_3240 = arg1->unk10;
        M2C_FIELD((this->unk58 + temp_r31_3236), s32 *, 4) = temp_r4_3240;
        M2C_FIELD((this->unk58 + temp_r31_3236), s32 *, 8) = atoi(arg1->unk0, temp_r4_3240);
        M2C_FIELD((this->unk58 + temp_r31_3236), s32 *, 0xC) = (s32) arg1->unk4;
        M2C_FIELD((this->unk58 + temp_r31_3236), u8 *, 0x10) = (u8) arg1->unk8;
        M2C_FIELD((this->unk58 + temp_r31_3236), s32 *, 0x14) = 0;
        M2C_FIELD((this->unk58 + temp_r31_3236), s32 *, 0x18) = 0;
        M2C_FIELD((this->unk58 + temp_r31_3236), s32 *, 0x1C) = -1;
        M2C_FIELD((this->unk58 + temp_r31_3236), s32 *, 0x20) = (s32) arg1->unk14;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'GetSubLine__5MKIniFP9MKIniLine'
void ProcessBars__10KDSP_ActorFP12KDSynkerHeapM10KDSP_ActorFPCvPvP12KDSynkerHeapP15KDSP_GenericBarii_vP9MKIniLineRi(KDSP_Actor *arg0, KDSynkerHeap *arg1, s32 *arg2, MKIniLine *arg3, s32 *arg4) {
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    u8 sp10;
    s32 spC;
    s8 *sp8;
    MKIniLine *var_r19_3294;
    MKIniLine *var_r19_3342;
    MKIniLine *var_r24_3324;
    s32 temp_r29_3315;
    s32 temp_r4_3393;
    s32 temp_r6_3400;
    s32 var_r0_3394;
    s32 var_r28_3317;
    u8 var_r20_3348;

    var_r19_3294 = GetSubLine__5MKIniFP9MKIniLine(arg3->unkC, arg3);
loop_2:
    if ((var_r19_3294 != NULL) && (IsField__9MKIniLineFPCc(var_r19_3294, lit_stringBase0) == 0)) {
        var_r19_3294 = GetNextLine__5MKIniFP9MKIniLine(var_r19_3294->unkC, var_r19_3294);
        goto loop_2;
    }
    temp_r29_3315 = GetNmbrOfSubLines__9MKIniLineFv(var_r19_3294);
    var_r28_3317 = 0;
    var_r24_3324 = GetSubLine__5MKIniFP9MKIniLine(var_r19_3294->unkC, var_r19_3294);
loop_17:
    if (var_r24_3324 != NULL) {
        sp8 = GetFieldName__9MKIniLineFv(var_r24_3324);
        spC = GetString__9MKIniLineFi(var_r24_3324, 0);
        sp18 = 0;
        sp14 = 0;
        sp10 = 0;
        var_r19_3342 = GetSubLine__5MKIniFP9MKIniLine(var_r24_3324->unkC, var_r24_3324);
loop_13:
        if (var_r19_3342 != NULL) {
            var_r20_3348 = 0;
            if ((LoadInt__9MKIniLineFPCcPii(var_r19_3342, &lit_stringBase0[5], &sp1C, 0) != 0) || (LoadInt__9MKIniLineFPCcPii(var_r19_3342, &lit_stringBase0[9], &sp14, 0) != 0) || (LoadInt__9MKIniLineFPCcPii(var_r19_3342, &lit_stringBase0[0xF], &sp18, 0) != 0)) {
                var_r20_3348 = 1;
            }
            if (var_r20_3348 == 0) {
                LoadBool__9MKIniLineFPCcPbi(var_r19_3342, &lit_stringBase0[0x16], &sp10, 0);
            }
            var_r19_3342 = GetNextLine__5MKIniFP9MKIniLine(var_r19_3342->unkC, var_r19_3342);
            goto loop_13;
        }
        temp_r4_3393 = *arg4;
        var_r0_3394 = sp14 + sp18;
        if (temp_r4_3393 > var_r0_3394) {
            var_r0_3394 = temp_r4_3393;
        }
        *arg4 = var_r0_3394;
        temp_r6_3400 = var_r28_3317;
        var_r28_3317 += 1;
        __ptmf_scall(arg0, arg1, &sp8, temp_r6_3400, temp_r29_3315);
        var_r24_3324 = GetNextLine__5MKIniFP9MKIniLine(var_r24_3324->unkC, var_r24_3324);
        goto loop_17;
    }
}
#endif

void KDSP_Actor::Draw() {
    if (this->unk40 & 0x40) {
        MKModel_Draw(this->unk3C, NULL);
        return;
    }
    MKModel_Draw(this->unk38->unk8, NULL);
}

#if 0 // DRAFT: illegal use of non-static member
void KDSP_Actor::Deinit(bool arg0) {
    KDS_Message_PropEnd sp8;
    MKAnimScript *temp_r3_3586;
    MKHeap *temp_r3_3504;
    Matrix *temp_r31_3501;
    s32 temp_r0_3479;
    s32 temp_r29_3524;
    s32 temp_r29_3539;
    s32 temp_r29_3554;
    s32 var_r3_3473;
    s32 var_r6_3474;
    u32 temp_r3_3577;

    if ((((MKAnimScript *) this->unk38 != NULL) || ((MKModel *) this->unk3C != NULL)) && ((u32) this->unk30 == 0)) {
        Shadow::Deinit();
    }
    if ((void *) this->unk58 != NULL) {
        var_r3_3473 = 0;
        var_r6_3474 = 0;
loop_7:
        if (var_r6_3474 < (s32) this->unk54) {
            temp_r0_3479 = var_r3_3473 + 0x18;
            var_r6_3474 += 1;
            var_r3_3473 += 0x24;
            *(this->unk58 + temp_r0_3479) = 0;
            goto loop_7;
        }
        this->unk58 = NULL;
    }
    this->unk6C = NULL;
    this->unkB4 = NULL;
    this->unkAC = NULL;
    this->unk48 = NULL;
    this->unk50 = NULL;
    this->unk9C = NULL;
    this->unkA4 = NULL;
    if (this->unk40 & 4) {
        temp_r31_3501 = this->unk34;
        if (temp_r31_3501 != NULL) {
            temp_r3_3504 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
            if (temp_r3_3504 != NULL) {
                ((MKHeap *) (temp_r3_3504->Current()))->Free(temp_r31_3501, NULL, 0);
            } else {
                free(temp_r31_3501);
            }
            this->unk34 = NULL;
        }
    } else {
        if ((u32) this->unk30 != 0) {
            temp_r29_3524 = this->unk84;
            if ((temp_r29_3524 != -1) && ((s32) this->unk44 > 0)) {
                ((Animation *) (MKModel_GetAnimation(this->unk70->unk8)))->SetCustomMatrix(temp_r29_3524, NULL, (AnimationMatrixPosition) 2, 0U);
            }
            temp_r29_3539 = this->unk88;
            if ((temp_r29_3539 != -1) && ((s32) this->unk4C > 0)) {
                ((Animation *) (MKModel_GetAnimation(this->unk70->unk8)))->SetCustomMatrix(temp_r29_3539, NULL, (AnimationMatrixPosition) 2, 0U);
            }
            temp_r29_3554 = this->unk8C;
            if ((temp_r29_3554 != -1) && ((s32) this->unk4C > 0)) {
                ((Animation *) (MKModel_GetAnimation(this->unk70->unk8)))->SetCustomMatrix(temp_r29_3554, NULL, (AnimationMatrixPosition) 2, 0U);
            }
            sp8.unk4 = 0;
            sp8.Init((((u32) this->unk40 >> 4U) & 1) ^ 1, arg0);
            temp_r3_3577 = this->unk30;
            M2C_FIELD(M2C_FIELD(temp_r3_3577, void **, 0x44), M2C_UNK (**)(u32, KDS_Message_PropEnd *), 0x2C)(temp_r3_3577, &sp8);
            this->unk30 = 0;
        }
        temp_r3_3586 = this->unk74;
        if (temp_r3_3586 != NULL) {
            temp_r3_3586->Destroy();
            this->unk74 = NULL;
        }
        if (this->unk40 & 0x40) {
            MKModel_Destroy(this->unk3C);
            this->unk3C = NULL;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_stringBase0'
void KDSP_Actor::LoadActorSectionPostResolve(MKIniLine *arg0, bool arg1, int &arg2) {
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    MKAnimScript *temp_r3_3624;
    MKAnimScript *temp_r3_3772;
    MKIniLine *var_r28_3708;
    MKIniLine *var_r29_3734;
    s32 temp_r7_3621;

    temp_r7_3621 = this->unk40;
    if (!(temp_r7_3621 & 4)) {
        temp_r3_3624 = this->unk38;
        if ((temp_r3_3624 != NULL) && !(temp_r7_3621 & 8)) {
            this->unk84 = FindNode(MKModel_GetAnimation(temp_r3_3624->unk8), &lit_stringBase0[0x1E]);
            this->unk88 = FindNode(MKModel_GetAnimation(this->unk38->unk8), &lit_stringBase0[0x23]);
            if ((s32) this->unk88 == -1) {
                this->unk88 = FindNode(MKModel_GetAnimation(this->unk38->unk8), &lit_stringBase0[0x29]);
            }
            this->unk8C = FindNode(MKModel_GetAnimation(this->unk38->unk8), &lit_stringBase0[0x2F]);
            if ((s32) this->unk8C == -1) {
                this->unk8C = FindNode(MKModel_GetAnimation(this->unk38->unk8), &lit_stringBase0[0x35]);
            }
            this->unk7C = FindNode(MKModel_GetAnimation(this->unk38->unk8), &lit_stringBase0[0x3B]);
            this->unk80 = FindNode(MKModel_GetAnimation(this->unk38->unk8), &lit_stringBase0[0x45]);
            this->unk90 = FindNode(MKModel_GetAnimation(this->unk38->unk8), &lit_stringBase0[0x4E]);
        }
        if (this->unk40 & 8) {
            var_r28_3708 = arg0->unkC->GetSubLine(arg0);
loop_13:
            if (var_r28_3708 != NULL) {
                if (var_r28_3708->IsField(&lit_stringBase0[0x53]) != 0) {
                    ModelSubObjectHide(var_r28_3708, this->unk3C);
                }
                var_r28_3708 = var_r28_3708->unkC->GetNextLine(var_r28_3708);
                goto loop_13;
            }
            return;
        }
        var_r29_3734 = arg0->unkC->GetSubLine(arg0);
loop_29:
        if (var_r29_3734 != NULL) {
            var_r29_3734->GetFieldName();
            if (strstr(&lit_stringBase0[0x61]) != 0U) {
                sp20 = M2C_FIELD(&lit_770, s32 *, 0x60);
                sp24 = M2C_FIELD(&lit_770, s32 *, 0x64);
                sp28 = M2C_FIELD(&lit_770, s32 *, 0x68);
                ProcessBars__10KDSP_ActorFP12KDSynkerHeapM10KDSP_ActorFPCvPvP12KDSynkerHeapP15KDSP_GenericBarii_vP9MKIniLineRi(this, NULL, &sp20, var_r29_3734, &arg2, M2C_FIELD(&lit_770, s32 *, 0x64));
            } else if (arg1 == 0) {
                if (var_r29_3734->IsField(&lit_stringBase0[0x53]) != 0) {
                    if ((MKAnimScript *) this->unk70 != NULL) {
                        this->unk78 = var_r29_3734;
                    }
                    temp_r3_3772 = this->unk74;
                    if (temp_r3_3772 != NULL) {
                        ModelSubObjectHide(var_r29_3734, temp_r3_3772->unk8);
                    }
                } else {
                    var_r29_3734->GetFieldName();
                    if (strstr(&lit_stringBase0[0x67]) != 0U) {
                        sp14 = M2C_FIELD(&lit_770, s32 *, 0x6C);
                        sp18 = M2C_FIELD(&lit_770, s32 *, 0x70);
                        sp1C = M2C_FIELD(&lit_770, s32 *, 0x74);
                        ProcessBars__10KDSP_ActorFP12KDSynkerHeapM10KDSP_ActorFPCvPvP12KDSynkerHeapP15KDSP_GenericBarii_vP9MKIniLineRi(this, NULL, &sp14, var_r29_3734, &arg2, M2C_FIELD(&lit_770, s32 *, 0x70));
                    } else {
                        var_r29_3734->GetFieldName();
                        if (strstr(&lit_stringBase0[0x6D]) != 0U) {
                            sp8 = M2C_FIELD(&lit_770, s32 *, 0x78);
                            spC = M2C_FIELD(&lit_770, s32 *, 0x7C);
                            sp10 = M2C_FIELD(&lit_770, s32 *, 0x80);
                            ProcessBars__10KDSP_ActorFP12KDSynkerHeapM10KDSP_ActorFPCvPvP12KDSynkerHeapP15KDSP_GenericBarii_vP9MKIniLineRi(this, NULL, &sp8, var_r29_3734, &arg2, M2C_FIELD(&lit_770, s32 *, 0x7C));
                        }
                    }
                }
            }
            var_r29_3734 = var_r29_3734->unkC->GetNextLine(var_r29_3734);
            goto loop_29;
        }
    }
}
#endif

#if 0 // DRAFT: identifier 'arg2' redeclared
void KDSP_Actor::Resolve(bool arg0, void (*arg2)(const char *, MKModel **, MKAnimScript **), bool arg2) {
    KDS_Message_PropResolve sp28;
    s8 sp8;
    MKAnimScript *temp_r3_3940;
    MKAnimScript *temp_r4_3996;
    MKHeap *temp_r3_3850;
    MKModel *var_r4_4009;
    Matrix *var_r3_3857;
    s8 *temp_r31_3934;
    s8 *temp_r4_3917;
    u32 temp_r3_3875;

    if (this->unk40 & 4) {
        temp_r3_3850 = MKHeap::Current();
        if (temp_r3_3850 != NULL) {
            var_r3_3857 = ((MKHeap *) (temp_r3_3850->Current()))->Alloc(0x40, NULL, 0);
        } else {
            var_r3_3857 = malloc(0x40);
        }
        this->unk34 = var_r3_3857;
        this->unk34->SetIdentity();
        return;
    }
    if ((u32) this->unk30 != 0) {
        sp28.unk4 = 0;
        sp28.Init();
        temp_r3_3875 = this->unk30;
        M2C_FIELD(M2C_FIELD(temp_r3_3875, void **, 0x44), M2C_UNK (**)(u32, KDS_Message_PropResolve *), 0x2C)(temp_r3_3875, &sp28);
        if (sp28.unk8 != 0) {
            this->unk30 = sp28.unk8;
            if (sp28.unk10 != NULL) {
                this->unk40 |= 8;
                this->unk3C = sp28.unk10;
            } else {
                this->unk38 = sp28.unkC;
                this->unk70 = sp28.unkC;
            }
        }
    } else if (arg1 != NULL) {
        arg1(this->unk5C, &this->unk3C, &this->unk70);
        this->unk38 = this->unk70;
        if ((MKModel *) this->unk3C != NULL) {
            this->unk40 |= 8;
        }
    }
    temp_r4_3917 = this->unk60;
    if (((s8) (u8) *temp_r4_3917 != 0) && (arg2 == 0)) {
        strcpy(&sp8, temp_r4_3917);
        strtok(&sp8, &lit_stringBase0[0x73]);
        temp_r31_3934 = strrchr(this->unk60, 0x2E);
        if (stricmp(&lit_stringBase0[0x75]) == 0) {
            temp_r3_3940 = this->unk70;
            if ((temp_r3_3940 != NULL) && (temp_r3_3940->GetName(), ((stricmp(&sp8) == 0) != 0))) {
                this->unk38 = this->unk70;
            } else {
                this->unk40 |= 0x20;
                this->unk74 = sp8.Create(NULL, M2C_ERROR(/* Read from unset register $r5 */));
                this->unk38 = this->unk74;
                ((Animation *) (MKModel_GetAnimation(this->unk74->unk8)))->EnableCustomMatrices(1U);
                MKModel_EnableTrivialRejection(this->unk74->unk8, 1U);
                UpdateCloth();
            }
        } else if (((MKModel *) this->unk3C == NULL) && (stricmp(temp_r31_3934, &lit_stringBase0[0x7A]) == 0)) {
            this->unk40 |= 0x48;
            this->unk3C = MKModel_Create(&sp8, NULL, 2, NULL);
            UpdateCloth();
        }
    }
    temp_r4_3996 = this->unk38;
    if (((temp_r4_3996 != NULL) || ((MKModel *) this->unk3C != NULL)) && ((u32) this->unk30 == 0)) {
        if (temp_r4_3996 != NULL) {
            var_r4_4009 = temp_r4_3996->unk8;
        } else {
            var_r4_4009 = this->unk3C;
        }
        Shadow::Init(var_r4_4009, NULL, 2000.0f, NULL, 1500.0f);
        Shadow::Show(1U);
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void KDSP_Actor::UpdateCloth() {
    f64 sp30;
    f64 sp28;
    MKVector3 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKCloth *temp_r3_4054;
    MKModel *temp_r3_4041;
    s16 temp_r31_4047;
    s32 var_r29_4049;

    temp_r3_4041 = GetModel();
    if (temp_r3_4041 != NULL) {
        temp_r31_4047 = MKModel_GetNmbrOfSubObjects(temp_r3_4041, (SubObjectType) 2);
        var_r29_4049 = 0;
loop_3:
        if (var_r29_4049 < temp_r31_4047) {
            temp_r3_4054 = MKModel_GetClothSubObject(temp_r3_4041, var_r29_4049);
            temp_r3_4054->SetIterations(3);
            sp10 = 0.0f;
            sp8 = 0.0f;
            spC = -981.00006f;
            sp30 = (f64) sp10;
            sp28 = (f64) sp8;
            temp_r3_4054->SetForce(0, *((MKVector3 *) &sp28), -1);
            MKModel_GetPosition(temp_r3_4041);
            MKWind_GetVelocity(sp18);
            temp_r3_4054->SetForce(1, sp18, -1);
            temp_r3_4054->SetFriction(1.0f);
            var_r29_4049 += 1;
            goto loop_3;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'HideSpecialSubObjectsInternal'
void KDSP_Actor::HideSpecialSubObjects() {
    MKAnimScript *temp_r3_4113;

    if (this->unk40 & 0x20) {
        HideSpecialSubObjectsInternal(this->unk74->unk8);
        temp_r3_4113 = this->unk70;
        if (temp_r3_4113 != NULL) {
            HideSpecialSubObjectsInternal(temp_r3_4113->unk8);
        }
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void HideSpecialSubObjectsInternal(MKModel *arg0) {
    s16 temp_r30_4138;
    u16 var_r28_4140;

    if (arg0 != NULL) {
        temp_r30_4138 = MKModel_GetNmbrOfSubObjects(arg0, (SubObjectType) 0);
        var_r28_4140 = 0;
loop_5:
        if ((s32) var_r28_4140 < temp_r30_4138) {
            if (strnicmp(MKModel_GetSubObjectName(arg0, (SubObjectType) 0, (s32) var_r28_4140) + 5, &lit_stringBase0[0x7F], 4) == 0) {
                MKModel_EnableSubObject(arg0, (SubObjectType) 0, (s32) var_r28_4140, 0U, 1U);
            }
            var_r28_4140 += 1;
            goto loop_5;
        }
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void ModelSubObjectHide(MKIniLine *arg0, MKModel *arg1) {
    s32 sp8;
    MKIniLine *var_r30_4198;
    s32 temp_r31_4200;
    s32 var_r29_4201;
    s8 *temp_r3_4205;

    if (arg0 != NULL) {
        if (arg1 == NULL) {
            return;
        }
        MKModel_EnableOnlySubObject(arg1, (SubObjectType) 0, -1, 0U, 1U);
        var_r30_4198 = arg0->unkC->GetSubLine(arg0);
        temp_r31_4200 = arg0->GetNmbrOfSubLines();
        var_r29_4201 = 0;
loop_8:
        if (var_r29_4201 < temp_r31_4200) {
            temp_r3_4205 = var_r30_4198->GetFieldName();
            if ((temp_r3_4205 != NULL) && (MKModel_SubObjectExists(arg1, (SubObjectType) 0, temp_r3_4205, &sp8) != 0)) {
                MKModel_EnableSubObject(arg1, (SubObjectType) 0, sp8, 0U, 1U);
            }
            var_r30_4198 = var_r30_4198->unkC->GetNextLine(var_r30_4198);
            var_r29_4201 += 1;
            goto loop_8;
        }
    }
}
#endif

#if 0 // DRAFT: pointer/array required
s32 FindNode(Animation *arg0, const char *arg1) {
    s32 var_r30_4248;
    s32 var_r3_4253;
    s32 var_r5_4254;
    s8 temp_r31_4247;
    u8 temp_r4_4266;

    temp_r31_4247 = arg0->GetNmbrOfNodes();
    var_r30_4248 = 0;
loop_11:
    if (var_r30_4248 >= temp_r31_4247) {
        return -1;
    }
    var_r3_4253 = arg0->GetNodeName(var_r30_4248);
    var_r5_4254 = 0;
loop_5:
    if (var_r5_4254 < 2) {
        temp_r4_4266 = *var_r3_4253;
        if (((s8) temp_r4_4266 != 0) && ((s8) temp_r4_4266 != 0)) {
            if ((s8) temp_r4_4266 == 0x5F) {
                var_r5_4254 += 1;
            }
            var_r3_4253 += 1;
            goto loop_5;
        }
    }
    if (stricmp(arg1) == 0) {
        return var_r30_4248;
    }
    var_r30_4248 += 1;
    goto loop_11;
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_stringBase0'
s32 KDSP_Actor::LoadAWFS(KDSynkerHeap *arg0, MKIniLine *arg1) {
    MKIniLine *var_r30_4313;
    s32 temp_r6_4319;
    s32 var_r31_4311;

    if (arg1->IsField(&lit_stringBase0[0x84]) != 0) {
        var_r31_4311 = 0;
        var_r30_4313 = arg1->unkC->GetSubLine(arg1);
loop_4:
        if (var_r30_4313 != NULL) {
            if (var_r31_4311 < (s32) this->unk54) {
                temp_r6_4319 = var_r31_4311;
                var_r31_4311 += 1;
                ParseAWFS(arg0, var_r30_4313, temp_r6_4319);
                var_r30_4313 = var_r30_4313->unkC->GetNextLine(var_r30_4313);
                goto loop_4;
            }
        }
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'GetFieldName__9MKIniLineFv'
u8 LoadBar__10KDSP_ActorFP12KDSynkerHeapP9MKIniLinePCcM10KDSP_ActorFPCvPvP12KDSynkerHeapP15KDSP_GenericBarii_vRi(KDSP_Actor *arg0, KDSynkerHeap *arg1, MKIniLine *arg2, s8 *arg3, s32 *arg4, s32 *arg5) {
    s32 sp10;
    s32 spC;
    s32 sp8;
    s32 temp_r8_4366;

    GetFieldName__9MKIniLineFv(arg2);
    if (strstr(arg3) != 0U) {
        temp_r8_4366 = M2C_FIELD(arg4, s32 *, 4);
        sp8 = M2C_FIELD(arg4, s32 *, 0);
        spC = temp_r8_4366;
        sp10 = M2C_FIELD(arg4, s32 *, 8);
        ProcessBars__10KDSP_ActorFP12KDSynkerHeapM10KDSP_ActorFPCvPvP12KDSynkerHeapP15KDSP_GenericBarii_vP9MKIniLineRi(arg0, arg1, &sp8, arg2, arg5, temp_r8_4366);
        return 1U;
    }
    return 0U;
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_stringBase0'
void KDSP_Actor::LoadActorSection(KDSynkerHeap *arg0, MKIniLine *arg1, int &arg2) {
    s32 sp64;
    s32 sp60;
    s32 sp5C;
    s32 sp58;
    s32 sp54;
    s32 sp50;
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    MKIniLine *var_r19_4404;
    u8 var_r20_4419;
    u8 var_r21_4417;
    u8 var_r22_4416;
    u8 var_r23_4415;
    u8 var_r24_4413;
    u8 var_r25_4411;
    u8 var_r26_4409;

    var_r19_4404 = arg1->unkC->GetSubLine(arg1);
loop_25:
    if (var_r19_4404 != NULL) {
        var_r26_4409 = 1;
        var_r25_4411 = 1;
        var_r24_4413 = 1;
        sp5C = M2C_FIELD(&lit_770, s32 *, 0);
        var_r23_4415 = 1;
        var_r22_4416 = 1;
        var_r21_4417 = 1;
        sp60 = M2C_FIELD(&lit_770, s32 *, 4);
        var_r20_4419 = 1;
        sp64 = M2C_FIELD(&lit_770, s32 *, 8);
        if (LoadBar__10KDSP_ActorFP12KDSynkerHeapP9MKIniLinePCcM10KDSP_ActorFPCvPvP12KDSynkerHeapP15KDSP_GenericBarii_vRi(this, arg0, var_r19_4404, &lit_stringBase0[0x89], &sp5C, &arg2) == 0) {
            sp50 = M2C_FIELD(&lit_770, s32 *, 0xC);
            sp54 = M2C_FIELD(&lit_770, s32 *, 0x10);
            sp58 = M2C_FIELD(&lit_770, s32 *, 0x14);
            if (LoadBar__10KDSP_ActorFP12KDSynkerHeapP9MKIniLinePCcM10KDSP_ActorFPCvPvP12KDSynkerHeapP15KDSP_GenericBarii_vRi(this, arg0, var_r19_4404, &lit_stringBase0[0x61], &sp50, &arg2) == 0) {
                var_r20_4419 = 0;
            }
        }
        if (var_r20_4419 == 0) {
            sp44 = M2C_FIELD(&lit_770, s32 *, 0x18);
            sp48 = M2C_FIELD(&lit_770, s32 *, 0x1C);
            sp4C = M2C_FIELD(&lit_770, s32 *, 0x20);
            if (LoadBar__10KDSP_ActorFP12KDSynkerHeapP9MKIniLinePCcM10KDSP_ActorFPCvPvP12KDSynkerHeapP15KDSP_GenericBarii_vRi(this, arg0, var_r19_4404, &lit_stringBase0[0x8E], &sp44, &arg2) == 0) {
                var_r21_4417 = 0;
            }
        }
        if (var_r21_4417 == 0) {
            sp38 = M2C_FIELD(&lit_770, s32 *, 0x24);
            sp3C = M2C_FIELD(&lit_770, s32 *, 0x28);
            sp40 = M2C_FIELD(&lit_770, s32 *, 0x2C);
            if (LoadBar__10KDSP_ActorFP12KDSynkerHeapP9MKIniLinePCcM10KDSP_ActorFPCvPvP12KDSynkerHeapP15KDSP_GenericBarii_vRi(this, arg0, var_r19_4404, &lit_stringBase0[0x67], &sp38, &arg2) == 0) {
                var_r22_4416 = 0;
            }
        }
        if (var_r22_4416 == 0) {
            sp2C = M2C_FIELD(&lit_770, s32 *, 0x30);
            sp30 = M2C_FIELD(&lit_770, s32 *, 0x34);
            sp34 = M2C_FIELD(&lit_770, s32 *, 0x38);
            if (LoadBar__10KDSP_ActorFP12KDSynkerHeapP9MKIniLinePCcM10KDSP_ActorFPCvPvP12KDSynkerHeapP15KDSP_GenericBarii_vRi(this, arg0, var_r19_4404, &lit_stringBase0[0x95], &sp2C, &arg2) == 0) {
                var_r23_4415 = 0;
            }
        }
        if (var_r23_4415 == 0) {
            sp20 = M2C_FIELD(&lit_770, s32 *, 0x3C);
            sp24 = M2C_FIELD(&lit_770, s32 *, 0x40);
            sp28 = M2C_FIELD(&lit_770, s32 *, 0x44);
            if (LoadBar__10KDSP_ActorFP12KDSynkerHeapP9MKIniLinePCcM10KDSP_ActorFPCvPvP12KDSynkerHeapP15KDSP_GenericBarii_vRi(this, arg0, var_r19_4404, &lit_stringBase0[0x9F], &sp20, &arg2) == 0) {
                var_r24_4413 = 0;
            }
        }
        if (var_r24_4413 == 0) {
            sp14 = M2C_FIELD(&lit_770, s32 *, 0x48);
            sp18 = M2C_FIELD(&lit_770, s32 *, 0x4C);
            sp1C = M2C_FIELD(&lit_770, s32 *, 0x50);
            if (LoadBar__10KDSP_ActorFP12KDSynkerHeapP9MKIniLinePCcM10KDSP_ActorFPCvPvP12KDSynkerHeapP15KDSP_GenericBarii_vRi(this, arg0, var_r19_4404, &lit_stringBase0[0xA9], &sp14, &arg2) == 0) {
                var_r25_4411 = 0;
            }
        }
        if (var_r25_4411 == 0) {
            sp8 = M2C_FIELD(&lit_770, s32 *, 0x54);
            spC = M2C_FIELD(&lit_770, s32 *, 0x58);
            sp10 = M2C_FIELD(&lit_770, s32 *, 0x5C);
            if (LoadBar__10KDSP_ActorFP12KDSynkerHeapP9MKIniLinePCcM10KDSP_ActorFPCvPvP12KDSynkerHeapP15KDSP_GenericBarii_vRi(this, arg0, var_r19_4404, &lit_stringBase0[0x6D], &sp8, &arg2) == 0) {
                var_r26_4409 = 0;
            }
        }
        if (var_r26_4409 == 0) {
            LoadAWFS(arg0, var_r19_4404);
        }
        var_r19_4404 = var_r19_4404->unkC->GetNextLine(var_r19_4404);
        goto loop_25;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_stringBase0'
s32 KDSP_Actor::LoadADSPaths(KDSynkerHeap *arg0, MKIniLine *arg1) {
    MKIniLine sp18;
    MKIniLine sp8;
    MKIniLine *var_r26_4646;
    MKIniLine *var_r26_4692;
    MKIniLine *var_r28_4635;
    s32 temp_r0_4618;
    s32 temp_r26_4666;
    s32 temp_r3_4625;
    s32 temp_r6_4669;
    s32 temp_r7_4681;
    s32 var_r27_4643;
    void *temp_r4_4667;
    void *temp_r4_4679;
    void *temp_r5_4623;
    void *var_r29_4631;

    if (arg1->IsField(&lit_stringBase0[0xAF]) != 0) {
        this->unk6C = NULL;
        this->unk68 = arg1->GetNmbrOfSubLines();
        temp_r0_4618 = this->unk68;
        if (temp_r0_4618 != 0) {
            temp_r5_4623 = arg0->unk18;
            temp_r3_4625 = arg0->unk20 - 1;
            arg0->unk18 = temp_r5_4623 + (((temp_r0_4618 * 0x30) + temp_r3_4625) & ~temp_r3_4625);
            this->unk6C = temp_r5_4623;
            var_r29_4631 = this->unk6C;
            var_r28_4635 = arg1->unkC->GetSubLine(arg1);
loop_22:
            if (var_r28_4635 != NULL) {
                M2C_FIELD(var_r29_4631, s8 **, 0) = var_r28_4635->GetFieldName();
                var_r27_4643 = 0;
                var_r26_4646 = var_r28_4635->unkC->GetSubLine(var_r28_4635);
loop_7:
                if (var_r26_4646 != NULL) {
                    if (var_r26_4646->IsField(&lit_stringBase0[0xB5]) != 0) {
                        var_r27_4643 += 1;
                    }
                    var_r26_4646 = var_r26_4646->unkC->GetNextLine(var_r26_4646);
                    goto loop_7;
                }
                if (var_r27_4643 != 0) {
                    temp_r26_4666 = var_r27_4643 << 5;
                    temp_r4_4667 = arg0->unkC;
                    temp_r6_4669 = arg0->unk14 - 1;
                    arg0->unkC = temp_r4_4667 + ((temp_r26_4666 + temp_r6_4669) & ~temp_r6_4669);
                    ((KDUniformSpline *) (var_r29_4631 + 8))->Init(temp_r4_4667, var_r27_4643, 0U);
                    temp_r4_4679 = arg0->unkC;
                    temp_r7_4681 = arg0->unk14 - 1;
                    arg0->unkC = temp_r4_4679 + ((temp_r26_4666 + temp_r7_4681) & ~temp_r7_4681);
                    ((KDUniformSpline *) (var_r29_4631 + 0x1C))->Init(temp_r4_4679, var_r27_4643, 0U);
                }
                var_r26_4692 = var_r28_4635->unkC->GetSubLine(var_r28_4635);
loop_20:
                if (var_r26_4692 != NULL) {
                    if (var_r26_4692->IsField(&lit_stringBase0[0xB9]) != 0) {
                        M2C_FIELD(var_r29_4631, s8 *, 5) = var_r26_4692->GetBool(0);
                    } else if (var_r26_4692->IsField(&lit_stringBase0[0xBD]) != 0) {
                        M2C_FIELD(var_r29_4631, s8 *, 4) = var_r26_4692->GetBool(0);
                    } else if (var_r26_4692->IsField(&lit_stringBase0[0xB5]) != 0) {
                        sp18.GetVector3((s32) var_r26_4692);
                        ((KDUniformSpline *) (var_r29_4631 + 8))->AddNode(*((MKVector3 *) &sp18));
                    } else if (var_r26_4692->IsField(&lit_stringBase0[0xC7]) != 0) {
                        sp8.GetVector3((s32) var_r26_4692);
                        ((KDUniformSpline *) (var_r29_4631 + 0x1C))->AddNode(*((MKVector3 *) &sp8));
                    }
                    var_r26_4692 = var_r26_4692->unkC->GetNextLine(var_r26_4692);
                    goto loop_20;
                }
                var_r29_4631 += 0x30;
                var_r28_4635 = var_r28_4635->unkC->GetNextLine(var_r28_4635);
                goto loop_22;
            }
        }
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_stringBase0'
void KDSP_Actor::HeapAddSize(KDSynkerHeap *arg0, MKIniLine *arg1) {
    MKIniLine *var_r24_4827;
    MKIniLine *var_r26_4819;
    MKIniLine *var_r27_4791;
    s32 temp_r0_4803;
    s32 temp_r3_4809;
    s32 temp_r3_4849;
    s32 temp_r3_4856;
    s32 temp_r5_4847;
    s32 var_r25_4825;

    var_r27_4791 = arg1->unkC->GetSubLine(arg1);
loop_25:
    if (var_r27_4791 != NULL) {
        if (var_r27_4791->IsField(&lit_stringBase0[0xAF]) != 0) {
            this->unk68 = var_r27_4791->GetNmbrOfSubLines();
            temp_r0_4803 = this->unk68;
            if (temp_r0_4803 != 0) {
                temp_r3_4809 = arg0->unk20 - 1;
                arg0->unk1C += ((temp_r0_4803 * 0x30) + temp_r3_4809) & ~temp_r3_4809;
            }
            var_r26_4819 = var_r27_4791->unkC->GetSubLine(var_r27_4791);
loop_13:
            if (var_r26_4819 != NULL) {
                var_r25_4825 = 0;
                var_r24_4827 = var_r26_4819->unkC->GetSubLine(var_r26_4819);
loop_9:
                if (var_r24_4827 != NULL) {
                    if (var_r24_4827->IsField(&lit_stringBase0[0xB5]) != 0) {
                        var_r25_4825 += 1;
                    }
                    var_r24_4827 = var_r24_4827->unkC->GetNextLine(var_r24_4827);
                    goto loop_9;
                }
                if (var_r25_4825 != 0) {
                    temp_r5_4847 = var_r25_4825 << 5;
                    temp_r3_4849 = arg0->unk14 - 1;
                    arg0->unk10 += (temp_r5_4847 + temp_r3_4849) & ~temp_r3_4849;
                    temp_r3_4856 = arg0->unk14 - 1;
                    arg0->unk10 += (temp_r5_4847 + temp_r3_4856) & ~temp_r3_4856;
                }
                var_r26_4819 = var_r26_4819->unkC->GetNextLine(var_r26_4819);
                goto loop_13;
            }
        } else if ((HeapAddSizeBar(arg0, var_r27_4791, &lit_stringBase0[0x89], 0x10) == 0) && (HeapAddSizeBar(arg0, var_r27_4791, &lit_stringBase0[0x61], 0x18) == 0) && (HeapAddSizeBar(arg0, var_r27_4791, &lit_stringBase0[0x8E], 0x24) == 0) && (HeapAddSizeBar(arg0, var_r27_4791, &lit_stringBase0[0x67], 0x18) == 0) && (HeapAddSizeBar(arg0, var_r27_4791, &lit_stringBase0[0x95], 0x14) == 0) && (HeapAddSizeBar(arg0, var_r27_4791, &lit_stringBase0[0x9F], 0x14) == 0) && (HeapAddSizeBar(arg0, var_r27_4791, &lit_stringBase0[0xA9], 0x14) == 0) && (HeapAddSizeBar(arg0, var_r27_4791, &lit_stringBase0[0x6D], 0x18) == 0)) {
            HeapAddSizeAWFSBar(arg0, var_r27_4791);
        }
        var_r27_4791 = var_r27_4791->unkC->GetNextLine(var_r27_4791);
        goto loop_25;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_stringBase0'
s32 KDSP_Actor::HeapAddSizeAWFSBar(KDSynkerHeap *arg0, MKIniLine *arg1) {
    MKIniLine *var_r30_4989;
    MKIniLine *var_r3_4995;
    s32 temp_r3_5011;
    s32 var_r29_4994;

    if (arg1->IsField(&lit_stringBase0[0x84]) != 0) {
        var_r30_4989 = arg1->unkC->GetSubLine(arg1);
loop_8:
        if (var_r30_4989 != NULL) {
            var_r29_4994 = 0;
            var_r3_4995 = var_r30_4989->unkC->GetSubLine(var_r30_4989);
loop_4:
            if (var_r3_4995 != NULL) {
                var_r29_4994 = (var_r3_4995->unk0 + var_r29_4994) - 1;
                var_r3_4995 = var_r3_4995->unkC->GetNextLine(var_r3_4995);
                goto loop_4;
            }
            if (var_r29_4994 != 0) {
                temp_r3_5011 = arg0->unk20 - 1;
                arg0->unk1C += (var_r29_4994 + temp_r3_5011) & ~temp_r3_5011;
            }
            var_r30_4989 = var_r30_4989->unkC->GetNextLine(var_r30_4989);
            goto loop_8;
        }
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: function call 'strstr(const char *)' does not match
u8 KDSP_Actor::HeapAddSizeBar(KDSynkerHeap *arg0, MKIniLine *arg1, const char *arg2, int arg3) {
    MKIniLine *var_r29_5057;
    s32 temp_r3_5075;
    s32 temp_r3_5081;

    arg1->GetFieldName();
    if (strstr(arg2) != 0U) {
        var_r29_5057 = arg1->unkC->GetSubLine(arg1);
loop_3:
        if ((var_r29_5057 != NULL) && (var_r29_5057->IsField(lit_stringBase0) == 0)) {
            var_r29_5057 = var_r29_5057->unkC->GetNextLine(var_r29_5057);
            goto loop_3;
        }
        temp_r3_5075 = var_r29_5057->GetNmbrOfSubLines();
        if (temp_r3_5075 > 0) {
            temp_r3_5081 = arg0->unk20 - 1;
            arg0->unk1C += ((arg3 * temp_r3_5075) + temp_r3_5081) & ~temp_r3_5081;
        }
        return 1U;
    }
    return 0U;
}
#endif

u8 KDSP_Actor::LoadADSFlag(MKIniLine *arg0, const char *arg1, int arg2) {
    if (arg0->IsField(arg1) != 0) {
        if (arg0->GetInt(0) != 0) {
            this->unk40 |= arg2;
        } else {
            this->unk40 &= ~arg2;
        }
        return 1U;
    }
    return 0U;
}

#if 0 // DRAFT: undefined identifier 'lit_stringBase0'
u8 KDSP_Actor::LoadADSBadRef(MKIniLine *arg0) {
    return (u8) (arg0->IsField(&lit_stringBase0[0xCB]) != 0);
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_stringBase0'
u8 KDSP_Actor::LoadADSPropID(MKIniLine *arg0) {
    MKSceneManager *temp_r3_5181;
    s32 temp_ret_5179;

    if (arg0->IsField(&lit_stringBase0[0xD2]) != 0) {
        temp_ret_5179 = arg0->GetInt(0);
        this->unk64 = temp_ret_5179;
        temp_r3_5181 = this->unk64;
        if (temp_r3_5181 > 0) {
            this->unk30 = temp_r3_5181->PropResolver_Resolve((s32) (u32) (u64) temp_ret_5179);
        }
        return 1U;
    }
    return 0U;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void KDSP_Actor::LoadActorDataSection(KDSynkerHeap *arg0, MKIniLine *arg1) {
    MKIniLine *var_r31_5220;
    u8 var_r28_5225;

    this->unk5C = arg1->GetString(0);
    this->unk60 = arg1->GetString(1);
    var_r31_5220 = arg1->unkC->GetSubLine(arg1);
loop_11:
    if (var_r31_5220 != NULL) {
        var_r28_5225 = 0;
        if ((LoadADSPropID(var_r31_5220) != 0) || (LoadADSBadRef(var_r31_5220) != 0) || (LoadADSFlag(var_r31_5220, &lit_stringBase0[0xD9], 0x10) != 0) || (LoadADSFlag(var_r31_5220, &lit_stringBase0[0xE6], 4) != 0) || (LoadADSFlag(var_r31_5220, &lit_stringBase0[0xEC], 2) != 0) || (LoadADSFlag(var_r31_5220, &lit_stringBase0[0xF7], 1) != 0)) {
            var_r28_5225 = 1;
        }
        if (var_r28_5225 == 0) {
            LoadADSPaths(arg0, var_r31_5220);
        }
        var_r31_5220 = var_r31_5220->unkC->GetNextLine(var_r31_5220);
        goto loop_11;
    }
}
#endif

void KDSP_Actor::Init() {
    this->unkC4 = -1;
    this->unkD0 = -1;
    this->unkCC = -1;
    this->unkC8 = -1;
    this->unkC0 = -1;
    this->unkBC = -1;
    this->unkB8 = -1;
    this->unkD8.unk0 = 0.0f;
    this->unkD8.unk4 = 0.0f;
    this->unkD8.unk8 = 1.0f;
    this->unk12C = 1.0f;
    this->unk78 = NULL;
    this->unk90 = -1;
    this->unk118 = 0.0f;
    this->unk11C = 0.0f;
    this->unk120 = 0.0f;
    this->unk130 = 0;
    this->unk134 = -1;
}
