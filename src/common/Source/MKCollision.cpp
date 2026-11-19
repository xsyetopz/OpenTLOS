#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionManager.h"
#include "common/Source/MKCollisionModel.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKCollisionUtil.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Str.h"
#include <m2c_macros.h>

#if 0 // DRAFT: identifier 'defaultCollisionMax' redeclared
M2C_UNK free(MKCollisionManager **);                /* extern */
MKCollisionManager **malloc(M2C_UNK);               /* extern */
extern M2C_UNK defaultCollisionMax;
#endif
#if 0 // DRAFT: identifier 'defaultCollisionMin' redeclared
extern M2C_UNK defaultCollisionMin;
#endif
extern M2C_UNK gEmptyPtrList;
extern MKCollisionManager **managers;
#if 0 // DRAFT: illegal implicit conversion from 'const char[2]' to
static M2C_UNK lit_834;                                /* unable to generate initializer: unknown type; const */
static M2C_UNK lit_840;                                /* unable to generate initializer: unknown type; const */

void MKCollision_MangleName(const char *arg0, int arg1, bool arg2) {
    s8 sp8;
    M2C_UNK sp4;
    s8 *temp_ret_29;
    s8 *var_r30_31;
    s8 *var_r4_37;
    s8 *var_r5_24;

    var_r5_24 = "s";
    if (arg2 != 0) {
        var_r5_24 = "b";
    }
    temp_ret_29 = Str_Printf("_%02d%s", var_r5_24);
    var_r30_31 = temp_ret_29;
    if (arg1 < 0) {
        var_r4_37 = "s";
        if (arg2 != 0) {
            var_r4_37 = "b";
        }
        var_r30_31 = Str_Printf("_all%s", var_r4_37, "_%02d%s", M2C_BITWISE(f32, temp_ret_29));
    }
    M2C_STRUCT_COPY((s32) &sp4 + 4, (s32) (&lit_840 - 4) + 4, 0x100);
    Str_Printf("%s%s", &sp8, var_r30_31, M2C_BITWISE(f32, strncpy(&sp8, arg0, 0x20 - (strlen(var_r30_31) + 5))));
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'signed char *' to
void MKCollision_MangleName(const char *arg0, int arg1) {
    s8 sp8;
    M2C_UNK sp4;
    s8 *temp_ret_91;
    s8 *var_r31_93;

    temp_ret_91 = Str_Printf("_%02d", "_%02d%s");
    var_r31_93 = temp_ret_91;
    if (arg1 < 0) {
        var_r31_93 = Str_Printf("_all", (u32) (u64) temp_ret_91, M2C_BITWISE(f32, temp_ret_91));
    }
    M2C_STRUCT_COPY((s32) &sp4 + 4, (s32) (&lit_834 - 4) + 4, 0x100);
    Str_Printf("%s%s", &sp8, var_r31_93, M2C_BITWISE(f32, strncpy(&sp8, arg0, 0x20 - (strlen(var_r31_93) + 5))));
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKCollisionMode'
u8 MKCollision_GetGroundPoint(const MKVector3 &arg0, float arg1, MKCollisionResult *arg2, int arg3, int arg4, MKCollisionGroundHint *arg5, MKCollisionMode arg6) {
    MKCollisionRay sp150;
    u8 sp148;
    s32 sp144;
    void *sp140;
    s32 sp13C;
    f32 sp138;
    s32 sp134;
    s8 sp133;
    s8 sp132;
    s16 sp130;                                      /* compiler-managed */
    f32 sp12C;
    f32 sp128;
    f32 sp124;
    f32 sp120;                                      /* compiler-managed */
    f32 sp11C;
    f32 sp118;                                      /* compiler-managed */
    f32 sp110;                                      /* compiler-managed */
    f32 sp10C;
    f32 sp108;                                      /* compiler-managed */
    f32 sp100;                                      /* compiler-managed */
    f32 spFC;
    f32 spF8;                                       /* compiler-managed */
    u8 spF0;
    s32 spEC;
    void *spE8;
    s32 spE4;
    f32 spE0;
    s32 spDC;
    s8 spDB;
    s8 spDA;
    s16 spD8;
    f32 spD4;
    f32 spD0;
    f32 spCC;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    s32 sp9C;
    s32 sp98;
    s32 sp94;
    s32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f64 sp78;
    f64 sp70;
    M2C_UNK *sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    MKCollisionManager **var_r30_219;
    MKCollisionManager *temp_r3_364;
    u8 var_r0_282;
    u8 var_r31_212;

    sp1C = arg1;
    sp18 = 0.0f;
    sp20 = 0.0f;
    sp28 = (f64) sp18;
    sp30 = (f64) sp20;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r24, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    sp38 = sp8;
    sp10 = arg0.unk8 - (f32) sp30;
    sp40 = (f64) sp10;
    if ((arg5 != NULL) && (arg2 != NULL)) {
        sp150.Init(arg0, *((MKVector3 *) &sp38), 0.0f, (u32) arg3);
        if (arg5->Update(sp150, arg2, arg4) != 0) {
            return 1U;
        }
    }
    var_r31_212 = 0;
    sp58 = M2C_FIELD(&arg0, f64 *, 0);
    sp48 = sp38;
    sp50 = sp40;
    var_r30_219 = managers;
    sp60 = (f64) M2C_FIELD(&arg0, f32 *, 8);
    spF8 = 0.0f;
    spFC = 0.0f;
    sp100 = 0.0f;
    sp108 = 0.0f;
    sp10C = 0.0f;
    sp110 = 0.0f;
    sp118 = 0.0f;
    sp11C = 0.0f;
    sp120 = 0.0f;
    sp124 = 1.0f;
    sp128 = 0.0f;
    sp12C = 0.0f;
    sp130 = 0;
    sp132 = 0;
    sp133 = 0;
    sp134 = 0;
    sp138 = 3.4028235e38f;
    sp13C = 0;
    sp140 = NULL;
    sp144 = -1;
    sp148 = 0;
    spA0 = 0.0f;
    spA4 = 0.0f;
    spA8 = 0.0f;
    spB0 = 0.0f;
    spB4 = 0.0f;
    spB8 = 0.0f;
    spC0 = 0.0f;
    spC4 = 0.0f;
    spC8 = 0.0f;
    spCC = 1.0f;
    spD0 = 0.0f;
    spD4 = 0.0f;
    spD8 = 0;
    spDA = 0;
    spDB = 0;
    spDC = 0;
    spE0 = 3.4028235e38f;
    spE4 = 0;
    spE8 = NULL;
    spEC = -1;
    spF0 = 0;
    sp68 = &__vt;
    sp70 = M2C_FIELD(&MKVector3::up, f64 *, 0);
    sp78 = M2C_FIELD(&MKVector3::up, f64 *, 8);
    sp80 = 0.0f;
    sp84 = 0.0f;
    sp88 = 0.0f;
    sp8C = 0.0f;
    sp90 = 0;
    sp94 = 0;
    sp98 = 0;
    sp9C = 0;
loop_18:
    if (var_r30_219 != NULL) {
        temp_r3_364 = *var_r30_219;
        if (temp_r3_364 != NULL) {
            var_r0_282 = 0;
            if (((f32) sp58 > temp_r3_364->unk0) && ((f32) sp48 < temp_r3_364->unk10) && (unksp5C > temp_r3_364->unk4) && (unksp4C < temp_r3_364->unk14) && ((f32) sp60 > temp_r3_364->unk8) && ((f32) sp50 < temp_r3_364->unk18)) {
                var_r0_282 = 1;
            }
            if ((var_r0_282 != 0) && (temp_r3_364->GetGroundPoint(arg0, *((MKVector3 *) &sp38), (MKCollisionResult *) &spA0, arg3, arg4, (MKCollisionGroundHint *) &sp68, arg6) != 0)) {
                M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                if (spE0 == sp138) {
                    var_r31_212 = 1;
                    spF8 = (f64) spA0;
                    sp100 = (f64) spA8;
                    sp108 = (f64) spB0;
                    sp110 = (f64) spB8;
                    sp118 = (f64) spC0;
                    sp120 = (f64) spC8;
                    sp128 = spD0;
                    sp12C = spD4;
                    sp130 = (s32) spD8;
                    sp134 = spDC;
                    sp138 = spE0;
                    sp13C = spE4;
                    sp140 = spE8;
                    sp144 = spEC;
                    sp148 = spF0;
                    if (arg5 != NULL) {
                        arg5->Set(&sp68);
                    }
                }
            }
            var_r30_219 += 4;
            goto loop_18;
        }
    }
    if ((var_r31_212 != 0) && (arg2 != NULL)) {
        M2C_FIELD(arg2, f64 *, 0) = spF8;
        M2C_FIELD(arg2, f64 *, 8) = sp100;
        M2C_FIELD(arg2, f64 *, 0x10) = sp108;
        M2C_FIELD(arg2, f64 *, 0x18) = sp110;
        M2C_FIELD(arg2, f64 *, 0x20) = sp118;
        M2C_FIELD(arg2, f64 *, 0x28) = sp120;
        arg2->unk30 = sp128;
        arg2->unk34 = sp12C;
        arg2->unk38 = sp130;
        arg2->unk3C = sp134;
        arg2->unk40 = sp138;
        arg2->unk44 = sp13C;
        arg2->unk48 = sp140;
        arg2->unk4C = sp144;
        arg2->unk50 = sp148;
    }
    return var_r31_212;
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKCollisionMode'
s32 MKCollision_SphereCollide(const MKVector3 &arg0, float arg1, MKCollisionResult *arg2, int arg3, MKCollisionMode arg4, int arg5) {
    s8 spD8;
    s32 spD4;
    s32 spD0;
    s32 spCC;
    f32 spC8;
    s32 spC4;
    s8 spC3;
    s8 spC2;
    s16 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp10;
    MKCollisionManager **var_r30_571;
    MKCollisionManager *temp_r3_617;
    MKCollisionResult *var_r26_465;
    f32 temp_f4_481;
    s32 var_ctr_540;
    s32 var_r27_466;
    s32 var_r31_501;
    s32 var_r3_537;
    u8 var_r0_580;
    void *temp_r5_544;

    var_r26_465 = arg2;
    var_r27_466 = arg3;
    sp30 = arg1;
    sp28 = arg1;
    sp2C = arg1;
    sp60 = (f64) sp30;
    sp58 = (f64) sp28;
    M2C_ERROR(/* unknown instruction: psq_lx $f2, $zero, $r25, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f2, $f1 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f1 */);
    temp_f4_481 = arg0.unk8;
    sp48 = sp18;
    sp20 = temp_f4_481 - (f32) sp60;
    sp68 = sp18;
    sp50 = (f64) sp20;
    sp70 = (f64) sp20;
    sp10 = temp_f4_481 + (f32) sp60;
    var_r31_501 = 0;
    sp38 = sp8;
    sp40 = (f64) sp10;
    sp78 = sp8;
    sp80 = (f64) sp10;
    sp88 = 0.0f;
    sp8C = 0.0f;
    sp90 = 0.0f;
    sp98 = 0.0f;
    sp9C = 0.0f;
    spA0 = 0.0f;
    spA8 = 0.0f;
    spAC = 0.0f;
    spB0 = 0.0f;
    spB4 = 1.0f;
    spB8 = 0.0f;
    spBC = 0.0f;
    spC0 = 0;
    spC2 = 0;
    spC3 = 0;
    spC4 = 0;
    spC8 = 3.4028235e38f;
    spCC = 0;
    spD0 = 0;
    spD4 = -1;
    spD8 = 0;
    if (var_r26_465 == NULL) {
        var_r26_465 = (MKCollisionResult *) &sp88;
        var_r27_466 = 1;
    }
    if (var_r27_466 <= 0) {
        var_r27_466 = 1;
    }
    var_r3_537 = 0;
    var_ctr_540 = var_r27_466;
    if (var_r27_466 > 0) {
        do {
            temp_r5_544 = var_r26_465 + var_r3_537;
            M2C_FIELD(temp_r5_544, f32 *, 0) = 0.0f;
            var_r3_537 += 0x58;
            M2C_FIELD(temp_r5_544, f32 *, 4) = 0.0f;
            M2C_FIELD(temp_r5_544, f32 *, 8) = 0.0f;
            M2C_FIELD(temp_r5_544, f32 *, 0x10) = 0.0f;
            M2C_FIELD(temp_r5_544, f32 *, 0x14) = 0.0f;
            M2C_FIELD(temp_r5_544, f32 *, 0x18) = 0.0f;
            M2C_FIELD(temp_r5_544, f32 *, 0x20) = 0.0f;
            M2C_FIELD(temp_r5_544, f32 *, 0x24) = 0.0f;
            M2C_FIELD(temp_r5_544, f32 *, 0x28) = 0.0f;
            M2C_FIELD(temp_r5_544, f32 *, 0x2C) = 1.0f;
            M2C_FIELD(temp_r5_544, f32 *, 0x30) = 0.0f;
            M2C_FIELD(temp_r5_544, f32 *, 0x34) = 0.0f;
            M2C_FIELD(temp_r5_544, s16 *, 0x38) = 0;
            M2C_FIELD(temp_r5_544, s8 *, 0x3A) = 0;
            M2C_FIELD(temp_r5_544, s8 *, 0x3B) = 0;
            M2C_FIELD(temp_r5_544, s32 *, 0x3C) = 0;
            M2C_FIELD(temp_r5_544, f32 *, 0x40) = 3.4028235e38f;
            M2C_FIELD(temp_r5_544, s32 *, 0x44) = 0;
            M2C_FIELD(temp_r5_544, s32 *, 0x48) = 0;
            M2C_FIELD(temp_r5_544, s32 *, 0x4C) = -1;
            M2C_FIELD(temp_r5_544, s8 *, 0x50) = 0;
            var_ctr_540 -= 1;
        } while (var_ctr_540 != 0);
    }
    var_r30_571 = managers;
loop_18:
    temp_r3_617 = *var_r30_571;
    if (temp_r3_617 != NULL) {
        var_r0_580 = 0;
        if (((f32) sp78 > temp_r3_617->unk0) && ((f32) sp68 < temp_r3_617->unk10) && (unksp7C > temp_r3_617->unk4) && (unksp6C < temp_r3_617->unk14) && ((f32) sp80 > temp_r3_617->unk8) && ((f32) sp70 < temp_r3_617->unk18)) {
            var_r0_580 = 1;
        }
        if (var_r0_580 != 0) {
            var_r31_501 += temp_r3_617->SphereCollide(arg0, arg1, var_r26_465 + (var_r31_501 * 0x58), var_r27_466 - var_r31_501, arg4, arg5);
        }
        if (var_r31_501 < var_r27_466) {
            var_r30_571 += 4;
            goto loop_18;
        }
    }
    return var_r31_501;
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKCollisionMode'
u8 MKCollision_SweepSphereCollide(const MKVector3 &arg0, const MKVector3 &arg1, float arg2, MKCollisionResult *arg3, MKCollisionMode arg4, int arg5) {
    u8 sp150;
    s32 sp14C;
    void *sp148;
    s32 sp144;
    f32 sp140;
    s32 sp13C;
    s8 sp13B;
    s8 sp13A;
    s16 sp138;                                      /* compiler-managed */
    f32 sp134;
    f32 sp130;
    f32 sp12C;
    f32 sp128;                                      /* compiler-managed */
    f32 sp124;
    f32 sp120;                                      /* compiler-managed */
    f32 sp118;                                      /* compiler-managed */
    f32 sp114;
    f32 sp110;                                      /* compiler-managed */
    f32 sp108;                                      /* compiler-managed */
    f32 sp104;
    f32 sp100;                                      /* compiler-managed */
    u8 spF8;
    s32 spF4;
    void *spF0;
    s32 spEC;
    f32 spE8;
    s32 spE4;
    s8 spE3;
    s8 spE2;
    s16 spE0;
    f32 spDC;
    f32 spD8;
    f32 spD4;
    f32 spD0;
    f32 spCC;
    f32 spC8;
    f32 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    MKVector3 sp58;
    f64 sp50;
    f64 sp48;
    MKVector3 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp10;
    MKCollisionManager **var_r30_754;
    MKCollisionManager *temp_r3_839;
    u8 var_r0_768;
    u8 var_r31_753;

    sp30 = arg2;
    sp28 = arg2;
    sp2C = arg2;
    sp80 = (f64) sp30;
    sp78 = (f64) sp28;
    Min(sp58, arg0);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    sp68 = sp18;
    sp20 = sp58.unk8 - (f32) sp80;
    sp88 = sp18;
    sp70 = (f64) sp20;
    sp90 = (f64) sp20;
    Max(sp38, arg0);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp10 = sp38.unk8 + (f32) sp80;
    sp48 = sp8;
    sp50 = (f64) sp10;
    sp98 = sp8;
    spA0 = (f64) sp10;
    sp100 = 0.0f;
    sp104 = 0.0f;
    sp108 = 0.0f;
    sp110 = 0.0f;
    sp114 = 0.0f;
    sp118 = 0.0f;
    sp120 = 0.0f;
    sp124 = 0.0f;
    sp128 = 0.0f;
    sp12C = 1.0f;
    sp130 = 0.0f;
    sp134 = 0.0f;
    sp138 = 0;
    sp13A = 0;
    sp13B = 0;
    sp13C = 0;
    sp140 = 3.4028235e38f;
    sp144 = 0;
    sp148 = NULL;
    sp14C = -1;
    sp150 = 0;
    spA8 = 0.0f;
    spAC = 0.0f;
    spB0 = 0.0f;
    spB8 = 0.0f;
    spBC = 0.0f;
    spC0 = 0.0f;
    spC8 = 0.0f;
    spCC = 0.0f;
    spD0 = 0.0f;
    spD4 = 1.0f;
    spD8 = 0.0f;
    spDC = 0.0f;
    spE0 = 0;
    spE2 = 0;
    spE3 = 0;
    spE4 = 0;
    spE8 = 3.4028235e38f;
    var_r31_753 = 0;
    var_r30_754 = managers;
    spEC = 0;
    spF0 = NULL;
    spF4 = -1;
    spF8 = 0;
    sp140 = 1.0f;
loop_13:
    temp_r3_839 = *var_r30_754;
    if (temp_r3_839 != NULL) {
        var_r0_768 = 0;
        if (((f32) sp98 > temp_r3_839->unk0) && ((f32) sp88 < temp_r3_839->unk10) && (unksp9C > temp_r3_839->unk4) && (unksp8C < temp_r3_839->unk14) && ((f32) spA0 > temp_r3_839->unk8) && ((f32) sp90 < temp_r3_839->unk18)) {
            var_r0_768 = 1;
        }
        if ((var_r0_768 != 0) && (temp_r3_839->SweepSphereCollide(arg0, arg1, arg2, (MKCollisionResult *) &spA8, arg4, arg5) != 0)) {
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (spE8 == sp140) {
                var_r31_753 = 1;
                sp100 = (f64) spA8;
                sp108 = (f64) spB0;
                sp110 = (f64) spB8;
                sp118 = (f64) spC0;
                sp120 = (f64) spC8;
                sp128 = (f64) spD0;
                sp130 = spD8;
                sp134 = spDC;
                sp138 = (s32) spE0;
                sp13C = spE4;
                sp140 = spE8;
                sp144 = spEC;
                sp148 = spF0;
                sp14C = spF4;
                sp150 = spF8;
            }
        }
        var_r30_754 += 4;
        goto loop_13;
    }
    if ((var_r31_753 != 0) && (arg3 != NULL)) {
        M2C_FIELD(arg3, f64 *, 0) = sp100;
        M2C_FIELD(arg3, f64 *, 8) = sp108;
        M2C_FIELD(arg3, f64 *, 0x10) = sp110;
        M2C_FIELD(arg3, f64 *, 0x18) = sp118;
        M2C_FIELD(arg3, f64 *, 0x20) = sp120;
        M2C_FIELD(arg3, f64 *, 0x28) = sp128;
        arg3->unk30 = sp130;
        arg3->unk34 = sp134;
        arg3->unk38 = sp138;
        arg3->unk3C = sp13C;
        arg3->unk40 = sp140;
        arg3->unk44 = sp144;
        arg3->unk48 = sp148;
        arg3->unk4C = sp14C;
        arg3->unk50 = sp150;
    }
    return var_r31_753;
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKCollisionMode'
u8 MKCollision_RayCollide(const MKVector3 &arg0, const MKVector3 &arg1, MKCollisionResult *arg2, MKCollisionMode arg3, int arg4) {
    u8 spF0;
    s32 spEC;
    void *spE8;
    s32 spE4;
    f32 spE0;
    s32 spDC;
    s8 spDB;
    s8 spDA;
    s16 spD8;                                       /* compiler-managed */
    f32 spD4;
    f32 spD0;
    f32 spCC;
    f32 spC8;                                       /* compiler-managed */
    f32 spC4;
    f32 spC0;                                       /* compiler-managed */
    f32 spB8;                                       /* compiler-managed */
    f32 spB4;
    f32 spB0;                                       /* compiler-managed */
    f32 spA8;                                       /* compiler-managed */
    f32 spA4;
    f32 spA0;                                       /* compiler-managed */
    u8 sp98;
    s32 sp94;
    void *sp90;
    s32 sp8C;
    f32 sp88;
    s32 sp84;
    s8 sp83;
    s8 sp82;
    s16 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    MKVector3 sp18;
    MKVector3 sp8;
    MKCollisionManager **var_r30_941;
    MKCollisionManager *temp_r3_1064;
    u8 var_r0_992;
    u8 var_r31_936;

    Min(sp18, arg0);
    sp28 = M2C_BITWISE(f64, sp18);
    sp30 = (f64) sp18.unk8;
    Max(sp8, arg0);
    var_r31_936 = 0;
    sp38 = M2C_BITWISE(f64, sp8);
    sp40 = (f64) sp8.unk8;
    var_r30_941 = managers;
    spA0 = 0.0f;
    spA4 = 0.0f;
    spA8 = 0.0f;
    spB0 = 0.0f;
    spB4 = 0.0f;
    spB8 = 0.0f;
    spC0 = 0.0f;
    spC4 = 0.0f;
    spC8 = 0.0f;
    spCC = 1.0f;
    spD0 = 0.0f;
    spD4 = 0.0f;
    spD8 = 0;
    spDA = 0;
    spDB = 0;
    spDC = 0;
    spE0 = 3.4028235e38f;
    spE4 = 0;
    spE8 = NULL;
    spEC = -1;
    spF0 = 0;
    sp48 = 0.0f;
    sp4C = 0.0f;
    sp50 = 0.0f;
    sp58 = 0.0f;
    sp5C = 0.0f;
    sp60 = 0.0f;
    sp68 = 0.0f;
    sp6C = 0.0f;
    sp70 = 0.0f;
    sp74 = 1.0f;
    sp78 = 0.0f;
    sp7C = 0.0f;
    sp80 = 0;
    sp82 = 0;
    sp83 = 0;
    sp84 = 0;
    sp88 = 3.4028235e38f;
    sp8C = 0;
    sp90 = NULL;
    sp94 = -1;
    sp98 = 0;
loop_13:
    if (var_r30_941 != NULL) {
        temp_r3_1064 = *var_r30_941;
        if (temp_r3_1064 != NULL) {
            var_r0_992 = 0;
            if (((f32) sp38 > temp_r3_1064->unk0) && ((f32) sp28 < temp_r3_1064->unk10) && (unksp3C > temp_r3_1064->unk4) && (unksp2C < temp_r3_1064->unk14) && ((f32) sp40 > temp_r3_1064->unk8) && ((f32) sp30 < temp_r3_1064->unk18)) {
                var_r0_992 = 1;
            }
            if ((var_r0_992 != 0) && (temp_r3_1064->RayCollide(arg0, arg1, (MKCollisionResult *) &sp48, arg3, arg4) != 0)) {
                M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                if (sp88 == spE0) {
                    var_r31_936 = 1;
                    spA0 = (f64) sp48;
                    spA8 = (f64) sp50;
                    spB0 = (f64) sp58;
                    spB8 = (f64) sp60;
                    spC0 = (f64) sp68;
                    spC8 = (f64) sp70;
                    spD0 = sp78;
                    spD4 = sp7C;
                    spD8 = (s32) sp80;
                    spDC = sp84;
                    spE0 = sp88;
                    spE4 = sp8C;
                    spE8 = sp90;
                    spEC = sp94;
                    spF0 = sp98;
                }
            }
            var_r30_941 += 4;
            goto loop_13;
        }
    }
    if ((var_r31_936 != 0) && (arg2 != NULL)) {
        M2C_FIELD(arg2, f64 *, 0) = spA0;
        M2C_FIELD(arg2, f64 *, 8) = spA8;
        M2C_FIELD(arg2, f64 *, 0x10) = spB0;
        M2C_FIELD(arg2, f64 *, 0x18) = spB8;
        M2C_FIELD(arg2, f64 *, 0x20) = spC0;
        M2C_FIELD(arg2, f64 *, 0x28) = spC8;
        arg2->unk30 = spD0;
        arg2->unk34 = spD4;
        arg2->unk38 = spD8;
        arg2->unk3C = spDC;
        arg2->unk40 = spE0;
        arg2->unk44 = spE4;
        arg2->unk48 = spE8;
        arg2->unk4C = spEC;
        arg2->unk50 = spF0;
    }
    return var_r31_936;
}
#endif

#if 0 // DRAFT: expression syntax error
void MKCollision_RemoveManager(MKCollisionManager *arg0) {
    managers.Destroy(arg0);
}
#endif

void MKCollision_AddManager(MKCollisionManager *arg0) {
    MKCollisionManager **temp_r4_1140;

    temp_r4_1140 = managers - 4;
    managers = temp_r4_1140;
    *temp_r4_1140 = arg0;
}

void MKCollision_Draw() {

}

void MKCollision_Update() {
    MKCollisionManager **var_r31_1159;
    MKCollisionManager *temp_r3_1165;

    var_r31_1159 = managers;
loop_2:
    temp_r3_1165 = *var_r31_1159;
    if (temp_r3_1165 != NULL) {
        temp_r3_1165->Update();
        var_r31_1159 += 4;
        goto loop_2;
    }
}

#if 0 // DRAFT: type mismatch
void MKCollision_Deinit() {
    MKCollisionManager **temp_r31_1184;
    MKCollisionManager **temp_r3_1183;
    MKHeap *temp_r3_1192;

    do {
        temp_r3_1183 = managers;
        temp_r31_1184 = temp_r3_1183 - 4;
        managers = temp_r31_1184;
    } while ((u32) M2C_FIELD(temp_r3_1183, u32 *, -4) != 0U);
    if (temp_r31_1184 != &gEmptyPtrList) {
        temp_r3_1192 = temp_r3_1183->Current();
        if (temp_r3_1192 != NULL) {
            ((MKHeap *) (temp_r3_1192->Current()))->Free(temp_r31_1184, NULL, 0);
        } else {
            free(temp_r31_1184);
        }
    }
    managers = NULL;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void MKCollision_Init() {
    MKCollisionManager **var_r3_1227;
    MKHeap *temp_r3_1220;
    s32 var_ctr_1239;

    temp_r3_1220 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_1220 != NULL) {
        var_r3_1227 = ((MKHeap *) (temp_r3_1220->Current()))->Alloc(0x48, NULL, 0);
    } else {
        var_r3_1227 = malloc(0x48);
    }
    managers = var_r3_1227;
    *var_r3_1227 = NULL;
    var_ctr_1239 = 0x10;
    do {
        managers += 4;
        M2C_FIELD(managers, s32 *, 4) = 0xDEADBEEF;
        var_ctr_1239 -= 1;
    } while (var_ctr_1239 != 0);
    managers += 4;
    M2C_FIELD(managers, s32 *, 4) = 0;
}
#endif

void MKCollision_DeinitModule() {

}

void MKCollision_SetDefaultBoundingBox(const MKVector3 &arg0, const MKVector3 &arg1) {
    M2C_FIELD(&defaultCollisionMin, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
    M2C_FIELD(&defaultCollisionMin, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
    M2C_FIELD(&defaultCollisionMax, f64 *, 0) = (f64) M2C_FIELD(&arg1, f64 *, 0);
    M2C_FIELD(&defaultCollisionMax, f64 *, 8) = (f64) M2C_FIELD(&arg1, f64 *, 8);
}

void MKCollision_InitModule() {
    M2C_FIELD(&defaultCollisionMin, f32 *, 0) = -500000.0f;
    M2C_FIELD(&defaultCollisionMax, f32 *, 0) = 500000.0f;
    M2C_FIELD(&defaultCollisionMin, f32 *, 4) = -500000.0f;
    M2C_FIELD(&defaultCollisionMin, f32 *, 8) = -500000.0f;
    M2C_FIELD(&defaultCollisionMax, f32 *, 4) = 500000.0f;
    M2C_FIELD(&defaultCollisionMax, f32 *, 8) = 500000.0f;
}

void MKCollisionInfo::GetRadius() {
    void **temp_r4_1304;

    temp_r4_1304 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), void ***, 0xC);
    M2C_FIELD(*temp_r4_1304, M2C_UNK (**)(void **), 0x30)(temp_r4_1304);
}
