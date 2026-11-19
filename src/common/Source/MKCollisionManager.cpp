#include "common/Source/MKCollisionManager.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionItem.h"
#include "common/Source/MKCollisionModel.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKCollisionUtil.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include <m2c_macros.h>

M2C_UNK free(MKHeap *);                             /* extern */
s8 *malloc(M2C_UNK);                                /* extern */
s32 stricmp(s8 *, MKHeap *);                        /* extern */
static s8 name_982[0x20];

static u32 testID = 1U;

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKCollisionMode'
s32 MKCollisionManager::CalcMaxGridOverlap(const MKCollisionAABB &arg0, Matrix *arg1, MKCollisionMode arg2) {
    MKCollisionAABB sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp8;
    f32 var_f4_43;
    f64 temp_f1_46;
    f64 temp_f1_52;
    f64 temp_f1_56;
    s32 temp_r0_111;
    s32 temp_r3_75;
    s32 var_r0_85;

    MKCollision_CalcAABB(arg1, arg0, &sp30);
    if ((s32) arg2 & 1) {
        sp30.unk14 = sp30.unk4;
    }
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    sp20 = sp10;
    sp18 = sp30.unk18 - sp30.unk8;
    sp28 = (f64) sp18;
    var_f4_43 = ((f32) sp28 * (f32) sp28) + (((f32) sp20 * (f32) sp20) + (unksp24 * unksp24));
    if (var_f4_43 > 0.0f) {
        temp_f1_46 = __frsqrte(var_f4_43);
        temp_f1_52 = 0.5 * temp_f1_46 * -(((f64) var_f4_43 * (temp_f1_46 * temp_f1_46)) - 3.0);
        temp_f1_56 = 0.5 * temp_f1_52 * -(((f64) var_f4_43 * (temp_f1_52 * temp_f1_52)) - 3.0);
        var_f4_43 = (f32) ((f64) var_f4_43 * (0.5 * temp_f1_56 * -(((f64) var_f4_43 * (temp_f1_56 * temp_f1_56)) - 3.0)));
    } else if (var_f4_43 < M2C_BITWISE(f32, 0.0)) {
        var_f4_43 = __float_nan;
    } else {
        sp8 = var_f4_43;
        temp_r3_75 = M2C_BITWISE(s32, sp8) & 0x7F800000;
        switch (temp_r3_75) {                       /* irregular */
        case 0x7F800000:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_85 = 1;
            } else {
                var_r0_85 = 2;
            }
            break;
        case 0x0:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_85 = 5;
            } else {
                var_r0_85 = 3;
            }
            break;
        default:
            var_r0_85 = 4;
            break;
        }
        if (var_r0_85 == 1) {
            var_f4_43 = __float_nan;
        }
    }
    temp_r0_111 = (s32) (0.001f * var_f4_43) + 2;
    return temp_r0_111 * temp_r0_111;
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKCollisionMode'
void MKCollisionManager::UpdateItemLinks(MKCollisionItem *arg0, MKCollisionMode arg1) {
    M2C_UNK sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    MKHeap *temp_r10_279;
    MKHeap *temp_r10_295;
    MKHeap *temp_r4_232;
    MKHeap *temp_r7_276;
    MKHeap *temp_r7_292;
    MKHeap *temp_r8_269;
    MKHeap *temp_r8_281;
    MKHeap *temp_r8_296;
    MKHeap *var_r5_221;
    f32 temp_f1_136;
    f32 temp_f1_145;
    f32 temp_f1_154;
    f32 temp_f1_163;
    f32 temp_f1_172;
    f32 temp_f1_181;
    f32 var_f0_135;
    f32 var_f0_144;
    f32 var_f0_153;
    f32 var_f0_162;
    f32 var_f0_171;
    f32 var_f0_180;
    s32 temp_r10_263;
    s32 temp_r11_264;
    s32 temp_r8_262;
    s32 temp_r9_260;
    s32 var_r4_249;
    s32 var_r5_255;
    s32 var_r6_252;
    u32 temp_r11_258;

    sp14 = 0;
    sp10 = 0;
    spC = 0;
    sp8 = 0;
    var_f0_135 = this->unk0;
    temp_f1_136 = arg0->unk10;
    if (var_f0_135 < temp_f1_136) {

    } else {
        var_f0_135 = temp_f1_136;
    }
    this->unk0 = var_f0_135;
    var_f0_144 = this->unk4;
    temp_f1_145 = arg0->unk14;
    if (var_f0_144 < temp_f1_145) {

    } else {
        var_f0_144 = temp_f1_145;
    }
    this->unk4 = var_f0_144;
    var_f0_153 = this->unk8;
    temp_f1_154 = arg0->unk18;
    if (var_f0_153 < temp_f1_154) {

    } else {
        var_f0_153 = temp_f1_154;
    }
    this->unk8 = var_f0_153;
    var_f0_162 = this->unk10;
    temp_f1_163 = arg0->unk20;
    if (var_f0_162 > temp_f1_163) {

    } else {
        var_f0_162 = temp_f1_163;
    }
    this->unk10 = var_f0_162;
    var_f0_171 = this->unk14;
    temp_f1_172 = arg0->unk24;
    if (var_f0_171 > temp_f1_172) {

    } else {
        var_f0_171 = temp_f1_172;
    }
    this->unk14 = var_f0_171;
    var_f0_180 = this->unk18;
    temp_f1_181 = arg0->unk28;
    if (var_f0_180 > temp_f1_181) {

    } else {
        var_f0_180 = temp_f1_181;
    }
    this->unk18 = var_f0_180;
    if ((arg0->unk30 != arg0->unk10) || (arg0->unk40 != arg0->unk20) || (arg0->unk38 != arg0->unk18) || (arg0->unk48 != arg0->unk28)) {
        M2C_FIELD(arg0, f32 *, 0x30) = (f64) M2C_FIELD(arg0, f32 *, 0x10);
        M2C_FIELD(arg0, f32 *, 0x38) = (f64) M2C_FIELD(arg0, f32 *, 0x18);
        M2C_FIELD(arg0, f32 *, 0x40) = (f64) M2C_FIELD(arg0, f32 *, 0x20);
        M2C_FIELD(arg0, f32 *, 0x48) = (f64) M2C_FIELD(arg0, f32 *, 0x28);
        FindGridOverlap(*((MKCollisionAABB *) &arg0->unk10), &sp14, &sp10, &spC, &sp8);
        var_r5_221 = arg0->unk58;
loop_24:
        temp_r4_232 = var_r5_221->unk0;
        if (temp_r4_232 != NULL) {
            var_r5_221 += 4;
            *temp_r4_232->unk4 = (MKHeap *) temp_r4_232->unk0;
            temp_r4_232->unk0->unk4 = temp_r4_232->unk4;
            goto loop_24;
        }
loop_27:
        if ((MKHeap *) arg0->unk58->unk0 != NULL) {
            arg0->unk58 = (MKHeap *) &arg0->unk58->unk4;
            goto loop_27;
        }
        memset(&sp18, 0, 0x200U);
        var_r4_249 = sp10;
        var_r6_252 = var_r4_249 << 5;
loop_38:
        if (var_r4_249 <= sp8) {
            var_r5_255 = sp14;
loop_36:
            if (var_r5_255 <= spC) {
                temp_r11_258 = var_r5_255 + var_r6_252;
                temp_r9_260 = (temp_r11_258 >> 1U) & 0x1FC;
                temp_r8_262 = *(&sp18 + temp_r9_260);
                temp_r10_263 = 1 << (temp_r11_258 & 7);
                temp_r11_264 = temp_r11_258 & 0x3FF;
                if (!(temp_r10_263 & temp_r8_262)) {
                    *(&sp18 + temp_r9_260) = temp_r8_262 | temp_r10_263;
                    temp_r8_269 = arg0->unk58;
                    if ((u32) M2C_FIELD(temp_r8_269, u32 *, -4) != 0U) {
                        if ((s32) ((s32) arg1 & 2) != 0) {
                            temp_r7_276 = temp_r8_269 - 4;
                            arg0->unk58 = temp_r7_276;
                            temp_r10_279 = temp_r7_276->unk0;
                            temp_r8_281 = this->unk2C + ((temp_r11_264 * 0x18) + 0xC);
                            temp_r10_279->unk8 = (s32) arg0;
                            temp_r10_279->unk4 = temp_r8_281->unk4;
                            temp_r10_279->unk0 = temp_r8_281;
                            *temp_r8_281->unk4 = temp_r10_279;
                            temp_r8_281->unk4 = (s32) temp_r10_279;
                        } else {
                            temp_r7_292 = temp_r8_269 - 4;
                            arg0->unk58 = temp_r7_292;
                            temp_r10_295 = temp_r7_292->unk0;
                            temp_r8_296 = this->unk2C + (temp_r11_264 * 0x18);
                            temp_r10_295->unk8 = (s32) arg0;
                            temp_r10_295->unk4 = temp_r8_296->unk4;
                            temp_r10_295->unk0 = temp_r8_296;
                            *temp_r8_296->unk4 = temp_r10_295;
                            temp_r8_296->unk4 = (s32) temp_r10_295;
                        }
                        goto block_35;
                    }
                } else {
block_35:
                    var_r5_255 += 1;
                    goto loop_36;
                }
            }
            var_r4_249 += 1;
            var_r6_252 += 0x20;
            goto loop_38;
        }
    }
}
#endif

#if 0 // DRAFT: function call 'strcpy(signed char *, int)' does not match
MKHeap *MKCollisionManager::CreateCollisionModel(const char *arg0, int arg1) {
    s8 sp8;
    MKCollisionModel *var_r30_356;
    MKCollisionModel *var_r3_355;
    MKHeap *temp_r3_344;
    MKHeap *temp_r3_367;
    MKHeap *temp_r3_382;
    s8 *temp_r29_381;
    s8 *var_r3_389;

    MKCollision_MangleName(arg0, arg1);
    strcpy(&sp8, M2C_ERROR(/* Read from unset register $r3 */));
    temp_r3_344 = FindTemplate(&sp8);
    if (temp_r3_344 != NULL) {
        temp_r3_344->unk24 += 1;
        return (MKHeap *) temp_r3_344->unk20;
    }
    var_r3_355 = sp8.Create(NULL, M2C_ERROR(/* Read from unset register $r5 */));
    var_r30_356 = var_r3_355;
    if (var_r30_356 == NULL) {
        MKCollision_MangleName(arg0, arg1, 1U);
        strcpy(&sp8, M2C_ERROR(/* Read from unset register $r3 */));
        temp_r3_367 = FindTemplate(&sp8);
        if (temp_r3_367 != NULL) {
            temp_r3_367->unk24 += 1;
            return (MKHeap *) temp_r3_367->unk20;
        }
        var_r3_355 = sp8.Create(NULL, M2C_ERROR(/* Read from unset register $r5 */));
        var_r30_356 = var_r3_355;
        goto block_6;
    }
block_6:
    temp_r29_381 = this->unk24;
    temp_r3_382 = var_r3_355->Current();
    if (temp_r3_382 != NULL) {
        var_r3_389 = ((MKHeap *) (temp_r3_382->Current()))->Alloc(0x2C, NULL, 0);
    } else {
        var_r3_389 = malloc(0x2C);
    }
    this->unk24 = var_r3_389;
    M2C_FIELD(this->unk24, s8 **, 0x28) = temp_r29_381;
    strcpy(this->unk24, &sp8);
    M2C_FIELD(this->unk24, MKCollisionModel **, 0x20) = var_r30_356;
    M2C_FIELD(this->unk24, s32 *, 0x24) = 1;
    return (MKHeap *) M2C_FIELD(this->unk24, MKCollisionModel **, 0x20);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
MKHeap *MKCollisionManager::CreateCollisionModel(MKModel *arg0, int arg1) {
    MKHeap *temp_r3_430;
    MKHeap *temp_r3_440;
    s8 *temp_r30_439;
    s8 *temp_r3_425;
    s8 *var_r3_447;

    temp_r3_425 = GetFileName(arg0, arg1);
    temp_r3_430 = FindTemplate(temp_r3_425);
    if (temp_r3_430 != NULL) {
        temp_r3_430->unk24 += 1;
        return (MKHeap *) temp_r3_430->unk20;
    }
    temp_r30_439 = this->unk24;
    temp_r3_440 = temp_r3_430->Current();
    if (temp_r3_440 != NULL) {
        var_r3_447 = ((MKHeap *) (temp_r3_440->Current()))->Alloc(0x2C, NULL, 0);
    } else {
        var_r3_447 = malloc(0x2C);
    }
    this->unk24 = var_r3_447;
    M2C_FIELD(this->unk24, s8 **, 0x28) = temp_r30_439;
    strcpy(this->unk24, temp_r3_425);
    M2C_FIELD(this->unk24, MKCollisionModel **, 0x20) = temp_r3_425->Create((s8 *) arg0, M2C_ERROR(/* Read from unset register $r5 */));
    M2C_FIELD(this->unk24, s32 *, 0x24) = 1;
    return (MKHeap *) M2C_FIELD(this->unk24, MKCollisionModel **, 0x20);
}
#endif

#if 0 // DRAFT: function call 'stricmp(const char *, MKHeap *)' does not match
MKHeap *MKCollisionManager::FindTemplate(const char *arg0) {
    s8 *var_r31_485;

    var_r31_485 = this->unk24;
loop_4:
    if (var_r31_485 == NULL) {
        return NULL;
    }
    if (stricmp(arg0, (MKHeap *) var_r31_485) == 0) {
        return (MKHeap *) var_r31_485;
    }
    var_r31_485 = M2C_FIELD(var_r31_485, s8 **, 0x28);
    goto loop_4;
}
#endif

#if 0 // DRAFT: function call 'MKCollision_MangleName(MKHeap *, int)' does not match
s8 *MKCollisionManager::GetFileName(MKModel *arg0, int arg1) {
    MKCollision_MangleName(MKModel_GetName(arg0), arg1);
    strcpy(name_982, M2C_ERROR(/* Read from unset register $r3 */));
    return name_982;
}
#endif

u8 MKCollisionManager::GetTriVerts(MKCollisionModel *arg0, const MKCollisionResult &arg1, MKVector3 *arg2) {
    s32 temp_cr0_gt_560;
    s32 temp_cr0_gt_591;
    u8 temp_r0_541;
    u8 var_r7_555;
    u8 var_r8_585;
    void **var_r3_563;
    void **var_r3_594;
    void *temp_r4_556;
    void *temp_r7_587;
    void *var_r3_557;
    void *var_r3_588;

    temp_r0_541 = M2C_FIELD(&arg1, u8 *, 0x3B);
    switch (temp_r0_541) {                          /* irregular */
    case 7:
        return arg0->GetVerts((u32) arg1.unk3C, arg2);
    case 1:
        var_r7_555 = M2C_FIELD(&arg1, u8 *, 0x3A);
        temp_r4_556 = this->unk2C + (M2C_FIELD(&arg1, u16 *, 0x38) * 0x18);
        var_r3_557 = M2C_FIELD(temp_r4_556, void **, 4);
loop_7:
        if (var_r3_557 == temp_r4_556) {
            var_r3_563 = NULL;
        } else {
            temp_cr0_gt_560 = (s32) var_r7_555 > 0;
            var_r7_555 -= 1;
            if (temp_cr0_gt_560 == 0) {
                var_r3_563 = M2C_FIELD(var_r3_557, void ***, 8);
            } else {
                var_r3_557 = M2C_FIELD(var_r3_557, void **, 4);
                goto loop_7;
            }
        }
        return M2C_FIELD(*var_r3_563, u8 (**)(s32, MKVector3 *), 0x2C)(arg1.unk3C, arg2);
    case 2:
        var_r8_585 = M2C_FIELD(&arg1, u8 *, 0x3A);
        temp_r7_587 = this->unk2C + ((M2C_FIELD(&arg1, u16 *, 0x38) * 0x18) + 0xC);
        var_r3_588 = M2C_FIELD(temp_r7_587, void **, 4);
loop_15:
        if (var_r3_588 == temp_r7_587) {
            var_r3_594 = NULL;
        } else {
            temp_cr0_gt_591 = (s32) var_r8_585 > 0;
            var_r8_585 -= 1;
            if (temp_cr0_gt_591 == 0) {
                var_r3_594 = M2C_FIELD(var_r3_588, void ***, 8);
            } else {
                var_r3_588 = M2C_FIELD(var_r3_588, void **, 4);
                goto loop_15;
            }
        }
        return M2C_FIELD(*var_r3_594, u8 (**)(s32, MKVector3 *), 0x2C)(arg1.unk3C, arg2);
    default:
        return 0U;
    }
}

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKCollisionMode'
s32 MKCollisionManager::SphereCollide(const MKVector3 &arg0, float arg1, MKCollisionResult *arg2, int arg3, MKCollisionMode arg4, int arg5) {
    MKCollisionRay sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    MKCollisionModel *var_r19_637;
    MKCollisionResult *temp_r17_832;
    MKCollisionResult *temp_r17_970;
    MKCollisionResult *temp_r18_673;
    s32 temp_r20_727;
    s32 temp_r25_729;
    s32 temp_r4_866;
    s32 var_r19_731;
    s32 var_r19_868;
    s32 var_r21_722;
    s32 var_r22_716;
    s32 var_r24_635;
    s32 var_r28_719;
    u8 var_r0_641;
    u8 var_r0_739;
    u8 var_r0_877;
    u8 var_r17_737;
    u8 var_r17_875;
    u8 var_r18_805;
    u8 var_r18_943;
    u8 var_r5_756;
    u8 var_r5_894;
    u8 var_r6_789;
    u8 var_r6_927;
    u8 var_r7_741;
    u8 var_r7_879;
    u8 var_r8_743;
    u8 var_r8_881;
    void **temp_r3_742;
    void **temp_r3_880;
    void *temp_r3_827;
    void *temp_r3_965;
    void *temp_r4_736;
    void *temp_r4_807;
    void *temp_r4_874;
    void *temp_r4_945;
    void *temp_r5_788;
    void *temp_r5_926;
    void *var_r23_733;
    void *var_r25_870;

    sp18.Init(arg0, arg0, arg1, (u32) arg5);
    var_r24_635 = 0;
    if ((s32) arg4 & 5) {
        var_r19_637 = this->unk28;
loop_14:
        if (var_r19_637 == NULL) {
            goto block_15;
        }
        var_r0_641 = 0;
        if (((f32) sp18.unk10 > var_r19_637->unk8.unk0) && (M2C_BITWISE(f32, sp18) < var_r19_637->unk8.unk10) && (unksp2C > var_r19_637->unk8.unk4) && (unksp1C < var_r19_637->unk8.unk14) && ((f32) sp18.unk18 > var_r19_637->unk8.unk8) && ((f32) sp18.unk8 < var_r19_637->unk8.unk18)) {
            var_r0_641 = 1;
        }
        if (var_r0_641 != 0) {
            temp_r18_673 = arg2 + (var_r24_635 * 0x58);
            var_r24_635 += UpdateSphereResults(var_r19_637, var_r19_637->SphereTest(sp18, temp_r18_673, arg3 - var_r24_635), temp_r18_673, -1, (MKCollisionMode) 7, 0);
        }
        if (var_r24_635 >= arg3) {
            return var_r24_635;
        }
        var_r19_637 = M2C_FIELD(var_r19_637, MKCollisionModel **, 0x48);
        goto loop_14;
    }
block_15:
    if (var_r24_635 >= arg3) {
        return var_r24_635;
    }
    sp14 = 0;
    testID += 1;
    sp10 = 0;
    spC = 0;
    sp8 = 0;
    FindGridOverlap(*((MKCollisionAABB *) &sp18), &sp14, &sp10, &spC, &sp8);
    var_r22_716 = sp10;
    var_r28_719 = var_r22_716 << 5;
loop_92:
    if (var_r22_716 > sp8) {
        return var_r24_635;
    }
    var_r21_722 = sp14;
loop_90:
    if (var_r21_722 > spC) {
        var_r22_716 += 1;
        var_r28_719 += 0x20;
        goto loop_92;
    }
    temp_r20_727 = (var_r21_722 + var_r28_719) & 0x3FF;
    if ((s32) ((s32) arg4 & 1) != 0) {
        temp_r25_729 = temp_r20_727 * 0x18;
        var_r19_731 = 0;
        var_r23_733 = *(this->unk2C + (temp_r25_729 + 4));
loop_53:
        if (var_r23_733 == (void *) (this->unk2C + temp_r25_729)) {
            goto block_54;
        }
        temp_r4_736 = M2C_FIELD(var_r23_733, void **, 8);
        var_r17_737 = 0;
        var_r0_739 = 0;
        var_r7_741 = 0;
        temp_r3_742 = this->unk34;
        var_r8_743 = 0;
        if ((u32) M2C_FIELD(temp_r4_736, u32 *, 4) != (u32) testID) {
            M2C_FIELD(temp_r4_736, u32 *, 4) = (u32) testID;
            if (!(M2C_FIELD(temp_r4_736, s32 *, 0x54) & sp18.unk58)) {
                var_r8_743 = 1;
            }
        }
        if (var_r8_743 != 0) {
            var_r5_756 = 0;
            if ((M2C_FIELD(temp_r4_736, f32 *, 0x20) > M2C_BITWISE(f32, sp18)) && (M2C_FIELD(temp_r4_736, f32 *, 0x10) < (f32) sp18.unk10) && (M2C_FIELD(temp_r4_736, f32 *, 0x24) > unksp1C) && (M2C_FIELD(temp_r4_736, f32 *, 0x14) < unksp2C) && (M2C_FIELD(temp_r4_736, f32 *, 0x28) > (f32) sp18.unk8) && (M2C_FIELD(temp_r4_736, f32 *, 0x18) < (f32) sp18.unk18)) {
                var_r5_756 = 1;
            }
            if (var_r5_756 != 0) {
                var_r7_741 = 1;
            }
        }
        if (var_r7_741 != 0) {
            temp_r5_788 = M2C_FIELD(temp_r4_736, void **, 8);
            var_r6_789 = 0;
            if ((temp_r5_788 == NULL) || ((u8) M2C_FIELD(temp_r5_788, u8 *, 4) != 0)) {
                var_r6_789 = 1;
            }
            if (var_r6_789 != 0) {
                var_r0_739 = 1;
            }
        }
        if (var_r0_739 != 0) {
            var_r18_805 = 0;
            if ((temp_r3_742 == NULL) || (temp_r4_807 = M2C_FIELD(temp_r4_736, void **, 8), ((temp_r4_807 == NULL) != 0)) || (M2C_FIELD(*temp_r3_742, u8 (**)(s32, s32), 0x9C)(M2C_FIELD(temp_r4_807, s32 *, 8), MKResource::sWorkingChunkID.unk0) != 0)) {
                var_r18_805 = 1;
            }
            if (var_r18_805 != 0) {
                var_r17_737 = 1;
            }
        }
        if (var_r17_737 != 0) {
            temp_r3_827 = M2C_FIELD(var_r23_733, void **, 8);
            temp_r17_832 = arg2 + (var_r24_635 * 0x58);
            var_r24_635 += UpdateSphereResults(NULL, M2C_FIELD(M2C_FIELD(temp_r3_827, void **, 0), s32 (**)(void *, MKCollisionRay *, MKCollisionResult *, s32), 0x18)(temp_r3_827, &sp18, temp_r17_832, arg3 - var_r24_635), temp_r17_832, temp_r20_727, (MKCollisionMode) 1, var_r19_731);
            if (var_r24_635 >= arg3) {
                return var_r24_635;
            }
        }
        var_r19_731 += 1;
        if (var_r24_635 >= arg3) {
            return var_r24_635;
        }
        var_r23_733 = M2C_FIELD(var_r23_733, void **, 4);
        goto loop_53;
    }
block_54:
    if ((s32) ((s32) arg4 & 2) != 0) {
        temp_r4_866 = temp_r20_727 * 0x18;
        var_r19_868 = 0;
        var_r25_870 = *(this->unk2C + (temp_r4_866 + 0x10));
loop_88:
        if (var_r25_870 == (void *) (this->unk2C + (temp_r4_866 + 0xC))) {
            goto block_89;
        }
        temp_r4_874 = M2C_FIELD(var_r25_870, void **, 8);
        var_r17_875 = 0;
        var_r0_877 = 0;
        var_r7_879 = 0;
        temp_r3_880 = this->unk34;
        var_r8_881 = 0;
        if ((u32) M2C_FIELD(temp_r4_874, u32 *, 4) != (u32) testID) {
            M2C_FIELD(temp_r4_874, u32 *, 4) = (u32) testID;
            if (!(M2C_FIELD(temp_r4_874, s32 *, 0x54) & sp18.unk58)) {
                var_r8_881 = 1;
            }
        }
        if (var_r8_881 != 0) {
            var_r5_894 = 0;
            if ((M2C_FIELD(temp_r4_874, f32 *, 0x20) > M2C_BITWISE(f32, sp18)) && (M2C_FIELD(temp_r4_874, f32 *, 0x10) < (f32) sp18.unk10) && (M2C_FIELD(temp_r4_874, f32 *, 0x24) > unksp1C) && (M2C_FIELD(temp_r4_874, f32 *, 0x14) < unksp2C) && (M2C_FIELD(temp_r4_874, f32 *, 0x28) > (f32) sp18.unk8) && (M2C_FIELD(temp_r4_874, f32 *, 0x18) < (f32) sp18.unk18)) {
                var_r5_894 = 1;
            }
            if (var_r5_894 != 0) {
                var_r7_879 = 1;
            }
        }
        if (var_r7_879 != 0) {
            temp_r5_926 = M2C_FIELD(temp_r4_874, void **, 8);
            var_r6_927 = 0;
            if ((temp_r5_926 == NULL) || ((u8) M2C_FIELD(temp_r5_926, u8 *, 4) != 0)) {
                var_r6_927 = 1;
            }
            if (var_r6_927 != 0) {
                var_r0_877 = 1;
            }
        }
        if (var_r0_877 != 0) {
            var_r18_943 = 0;
            if ((temp_r3_880 == NULL) || (temp_r4_945 = M2C_FIELD(temp_r4_874, void **, 8), ((temp_r4_945 == NULL) != 0)) || (M2C_FIELD(*temp_r3_880, u8 (**)(s32, s32), 0x9C)(M2C_FIELD(temp_r4_945, s32 *, 8), MKResource::sWorkingChunkID.unk0) != 0)) {
                var_r18_943 = 1;
            }
            if (var_r18_943 != 0) {
                var_r17_875 = 1;
            }
        }
        if (var_r17_875 != 0) {
            temp_r3_965 = M2C_FIELD(var_r25_870, void **, 8);
            temp_r17_970 = arg2 + (var_r24_635 * 0x58);
            var_r24_635 += UpdateSphereResults(NULL, M2C_FIELD(M2C_FIELD(temp_r3_965, void **, 0), s32 (**)(void *, MKCollisionRay *, MKCollisionResult *, s32), 0x18)(temp_r3_965, &sp18, temp_r17_970, arg3 - var_r24_635), temp_r17_970, temp_r20_727, (MKCollisionMode) 2, var_r19_868);
            if (var_r24_635 >= arg3) {
                return var_r24_635;
            }
        }
        var_r19_868 += 1;
        if (var_r24_635 >= arg3) {
            return var_r24_635;
        }
        var_r25_870 = M2C_FIELD(var_r25_870, void **, 4);
        goto loop_88;
    }
block_89:
    var_r21_722 += 1;
    goto loop_90;
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKCollisionMode'
u8 MKCollisionManager::SweepSphereCollide(const MKVector3 &arg0, const MKVector3 &arg1, float arg2, MKCollisionResult *arg3, MKCollisionMode arg4, int arg5) {
    u8 sp178;
    s32 sp174;
    void *sp170;
    s32 sp16C;
    f32 sp168;
    s32 sp164;
    s8 sp163;
    s8 sp162;
    s16 sp160;
    f32 sp15C;
    f32 sp158;
    f32 sp154;
    f32 sp150;
    f32 sp14C;
    f32 sp148;
    f32 sp140;
    f32 sp13C;
    f32 sp138;
    f32 sp130;
    f32 sp12C;
    f32 sp128;
    s8 sp120;
    s32 sp11C;
    s32 sp118;
    s32 sp114;
    f32 sp110;
    s32 sp10C;
    s8 sp10B;
    s8 sp10A;
    s16 sp108;
    f32 sp104;
    f32 sp100;
    f32 spFC;
    f32 spF8;
    f32 spF4;
    f32 spF0;
    f32 spE8;
    f32 spE4;
    f32 spE0;
    f32 spD8;
    f32 spD4;
    f32 spD0;
    MKCollisionRay sp70;
    MKVector3 sp40;
    MKVector3 sp30;
    MKVector3 sp20;
    MKCollisionModel *sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    MKCollisionModel *var_r20_1086;
    s32 temp_r20_1174;
    s32 temp_r26_1172;
    s32 temp_r4_1308;
    s32 var_r18_1176;
    s32 var_r18_1310;
    s32 var_r23_1164;
    s32 var_r27_1167;
    s32 var_r28_1161;
    u8 var_r0_1090;
    u8 var_r0_1201;
    u8 var_r0_1336;
    u8 var_r19_1121;
    u8 var_r20_1317;
    u8 var_r20_1410;
    u8 var_r21_1250;
    u8 var_r21_1275;
    u8 var_r21_1385;
    u8 var_r22_1182;
    u8 var_r29_1039;
    u8 var_r5_1234;
    u8 var_r5_1369;
    u8 var_r6_1184;
    u8 var_r6_1319;
    u8 var_r7_1186;
    u8 var_r7_1321;
    u8 var_r8_1188;
    u8 var_r8_1323;
    void **temp_r3_1187;
    void **temp_r3_1322;
    void *temp_r3_1272;
    void *temp_r3_1407;
    void *temp_r4_1181;
    void *temp_r4_1252;
    void *temp_r4_1316;
    void *temp_r4_1387;
    void *temp_r7_1233;
    void *temp_r7_1368;
    void *var_r19_1178;
    void *var_r19_1312;

    var_r29_1039 = 0;
    sp128 = 0.0f;
    sp12C = 0.0f;
    sp130 = 0.0f;
    sp138 = 0.0f;
    sp13C = 0.0f;
    sp140 = 0.0f;
    sp148 = 0.0f;
    sp14C = 0.0f;
    sp150 = 0.0f;
    sp154 = 1.0f;
    sp158 = 0.0f;
    sp15C = 0.0f;
    sp160 = 0;
    sp162 = 0;
    sp163 = 0;
    sp164 = 0;
    sp168 = 3.4028235e38f;
    sp16C = 0;
    sp170 = NULL;
    sp174 = -1;
    sp178 = 0;
    sp18 = NULL;
    spD0 = 0.0f;
    spD4 = 0.0f;
    spD8 = 0.0f;
    spE0 = 0.0f;
    spE4 = 0.0f;
    spE8 = 0.0f;
    spF0 = 0.0f;
    spF4 = 0.0f;
    spF8 = 0.0f;
    spFC = 1.0f;
    sp100 = 0.0f;
    sp104 = 0.0f;
    sp108 = 0;
    sp10A = 0;
    sp10B = 0;
    sp10C = 0;
    sp110 = 3.4028235e38f;
    sp114 = 0;
    sp118 = 0;
    sp11C = -1;
    sp120 = 0;
    sp70.Init(arg0, arg1, arg2, (u32) arg5);
    if ((s32) arg4 & 5) {
        var_r20_1086 = this->unk28;
loop_15:
        if (var_r20_1086 != NULL) {
            var_r0_1090 = 0;
            if (((f32) sp70.unk10 > var_r20_1086->unk8.unk0) && (M2C_BITWISE(f32, sp70) < var_r20_1086->unk8.unk10) && (unksp84 > var_r20_1086->unk8.unk4) && (unksp74 < var_r20_1086->unk8.unk14) && ((f32) sp70.unk18 > var_r20_1086->unk8.unk8) && ((f32) sp70.unk8 < var_r20_1086->unk8.unk18)) {
                var_r0_1090 = 1;
            }
            if (var_r0_1090 != 0) {
                var_r19_1121 = 0;
                var_r20_1086->SweepSphereTest(sp70, (MKCollisionResult *) &spD0);
                if ((UpdateBestResult(var_r20_1086, M2C_ERROR(/* Read from unset register $r3 */), *((MKCollisionResult *) &spD0), (MKCollisionResult *) &sp128, sp18, -1, (MKCollisionMode) 7, 0) != 0) || (var_r29_1039 != 0)) {
                    var_r19_1121 = 1;
                }
                var_r29_1039 = var_r19_1121;
            }
            var_r20_1086 = M2C_FIELD(var_r20_1086, MKCollisionModel **, 0x48);
            goto loop_15;
        }
    }
    sp14 = 0;
    testID += 1;
    sp10 = 0;
    spC = 0;
    sp8 = 0;
    FindGridOverlap(*((MKCollisionAABB *) &sp70), &sp14, &sp10, &spC, &sp8);
    var_r28_1161 = sp10;
    var_r23_1164 = var_r28_1161 << 5;
loop_91:
    if (var_r28_1161 <= sp8) {
        var_r27_1167 = sp14;
loop_89:
        if (var_r27_1167 <= spC) {
            temp_r26_1172 = (var_r27_1167 + var_r23_1164) & 0x3FF;
            if ((s32) ((s32) arg4 & 1) != 0) {
                temp_r20_1174 = temp_r26_1172 * 0x18;
                var_r18_1176 = 0;
                var_r19_1178 = *(this->unk2C + (temp_r20_1174 + 4));
loop_52:
                if (var_r19_1178 != (void *) (this->unk2C + temp_r20_1174)) {
                    temp_r4_1181 = M2C_FIELD(var_r19_1178, void **, 8);
                    var_r22_1182 = 0;
                    var_r6_1184 = 0;
                    var_r7_1186 = 0;
                    temp_r3_1187 = this->unk34;
                    var_r8_1188 = 0;
                    if ((u32) M2C_FIELD(temp_r4_1181, u32 *, 4) != (u32) testID) {
                        M2C_FIELD(temp_r4_1181, u32 *, 4) = (u32) testID;
                        if (!(M2C_FIELD(temp_r4_1181, s32 *, 0x54) & sp70.unk58)) {
                            var_r8_1188 = 1;
                        }
                    }
                    if (var_r8_1188 != 0) {
                        var_r0_1201 = 0;
                        if ((M2C_FIELD(temp_r4_1181, f32 *, 0x20) > M2C_BITWISE(f32, sp70)) && (M2C_FIELD(temp_r4_1181, f32 *, 0x10) < (f32) sp70.unk10) && (M2C_FIELD(temp_r4_1181, f32 *, 0x24) > unksp74) && (M2C_FIELD(temp_r4_1181, f32 *, 0x14) < unksp84) && (M2C_FIELD(temp_r4_1181, f32 *, 0x28) > (f32) sp70.unk8) && (M2C_FIELD(temp_r4_1181, f32 *, 0x18) < (f32) sp70.unk18)) {
                            var_r0_1201 = 1;
                        }
                        if (var_r0_1201 != 0) {
                            var_r7_1186 = 1;
                        }
                    }
                    if (var_r7_1186 != 0) {
                        temp_r7_1233 = M2C_FIELD(temp_r4_1181, void **, 8);
                        var_r5_1234 = 0;
                        if ((temp_r7_1233 == NULL) || ((u8) M2C_FIELD(temp_r7_1233, u8 *, 4) != 0)) {
                            var_r5_1234 = 1;
                        }
                        if (var_r5_1234 != 0) {
                            var_r6_1184 = 1;
                        }
                    }
                    if (var_r6_1184 != 0) {
                        var_r21_1250 = 0;
                        if ((temp_r3_1187 == NULL) || (temp_r4_1252 = M2C_FIELD(temp_r4_1181, void **, 8), ((temp_r4_1252 == NULL) != 0)) || (M2C_FIELD(*temp_r3_1187, u8 (**)(s32, s32), 0x9C)(M2C_FIELD(temp_r4_1252, s32 *, 8), MKResource::sWorkingChunkID.unk0) != 0)) {
                            var_r21_1250 = 1;
                        }
                        if (var_r21_1250 != 0) {
                            var_r22_1182 = 1;
                        }
                    }
                    if (var_r22_1182 != 0) {
                        temp_r3_1272 = M2C_FIELD(var_r19_1178, void **, 8);
                        var_r21_1275 = 0;
                        if ((UpdateBestResult(NULL, M2C_FIELD(M2C_FIELD(temp_r3_1272, void **, 0), u8 (**)(void *, MKCollisionRay *, f32 *), 0x14)(temp_r3_1272, &sp70, &spD0), *((MKCollisionResult *) &spD0), (MKCollisionResult *) &sp128, sp18, temp_r26_1172, (MKCollisionMode) 1, var_r18_1176) != 0) || (var_r29_1039 != 0)) {
                            var_r21_1275 = 1;
                        }
                        var_r29_1039 = var_r21_1275;
                    }
                    var_r19_1178 = M2C_FIELD(var_r19_1178, void **, 4);
                    var_r18_1176 += 1;
                    goto loop_52;
                }
            }
            if ((s32) ((s32) arg4 & 2) != 0) {
                temp_r4_1308 = temp_r26_1172 * 0x18;
                var_r18_1310 = 0;
                var_r19_1312 = *(this->unk2C + (temp_r4_1308 + 0x10));
loop_87:
                if (var_r19_1312 != (void *) (this->unk2C + (temp_r4_1308 + 0xC))) {
                    temp_r4_1316 = M2C_FIELD(var_r19_1312, void **, 8);
                    var_r20_1317 = 0;
                    var_r6_1319 = 0;
                    var_r7_1321 = 0;
                    temp_r3_1322 = this->unk34;
                    var_r8_1323 = 0;
                    if ((u32) M2C_FIELD(temp_r4_1316, u32 *, 4) != (u32) testID) {
                        M2C_FIELD(temp_r4_1316, u32 *, 4) = (u32) testID;
                        if (!(M2C_FIELD(temp_r4_1316, s32 *, 0x54) & sp70.unk58)) {
                            var_r8_1323 = 1;
                        }
                    }
                    if (var_r8_1323 != 0) {
                        var_r0_1336 = 0;
                        if ((M2C_FIELD(temp_r4_1316, f32 *, 0x20) > M2C_BITWISE(f32, sp70)) && (M2C_FIELD(temp_r4_1316, f32 *, 0x10) < (f32) sp70.unk10) && (M2C_FIELD(temp_r4_1316, f32 *, 0x24) > unksp74) && (M2C_FIELD(temp_r4_1316, f32 *, 0x14) < unksp84) && (M2C_FIELD(temp_r4_1316, f32 *, 0x28) > (f32) sp70.unk8) && (M2C_FIELD(temp_r4_1316, f32 *, 0x18) < (f32) sp70.unk18)) {
                            var_r0_1336 = 1;
                        }
                        if (var_r0_1336 != 0) {
                            var_r7_1321 = 1;
                        }
                    }
                    if (var_r7_1321 != 0) {
                        temp_r7_1368 = M2C_FIELD(temp_r4_1316, void **, 8);
                        var_r5_1369 = 0;
                        if ((temp_r7_1368 == NULL) || ((u8) M2C_FIELD(temp_r7_1368, u8 *, 4) != 0)) {
                            var_r5_1369 = 1;
                        }
                        if (var_r5_1369 != 0) {
                            var_r6_1319 = 1;
                        }
                    }
                    if (var_r6_1319 != 0) {
                        var_r21_1385 = 0;
                        if ((temp_r3_1322 == NULL) || (temp_r4_1387 = M2C_FIELD(temp_r4_1316, void **, 8), ((temp_r4_1387 == NULL) != 0)) || (M2C_FIELD(*temp_r3_1322, u8 (**)(s32, s32), 0x9C)(M2C_FIELD(temp_r4_1387, s32 *, 8), MKResource::sWorkingChunkID.unk0) != 0)) {
                            var_r21_1385 = 1;
                        }
                        if (var_r21_1385 != 0) {
                            var_r20_1317 = 1;
                        }
                    }
                    if (var_r20_1317 != 0) {
                        temp_r3_1407 = M2C_FIELD(var_r19_1312, void **, 8);
                        var_r20_1410 = 0;
                        if ((UpdateBestResult(NULL, M2C_FIELD(M2C_FIELD(temp_r3_1407, void **, 0), u8 (**)(void *, MKCollisionRay *, f32 *), 0x14)(temp_r3_1407, &sp70, &spD0), *((MKCollisionResult *) &spD0), (MKCollisionResult *) &sp128, sp18, temp_r26_1172, (MKCollisionMode) 2, var_r18_1310) != 0) || (var_r29_1039 != 0)) {
                            var_r20_1410 = 1;
                        }
                        var_r29_1039 = var_r20_1410;
                    }
                    var_r19_1312 = M2C_FIELD(var_r19_1312, void **, 4);
                    var_r18_1310 += 1;
                    goto loop_87;
                }
            }
            var_r27_1167 += 1;
            goto loop_89;
        }
        var_r28_1161 += 1;
        var_r23_1164 += 0x20;
        goto loop_91;
    }
    if ((var_r29_1039 != 0) && (arg3 != NULL)) {
        M2C_FIELD(arg3, f64 *, 0) = (f64) sp128;
        M2C_FIELD(arg3, f64 *, 8) = (f64) sp130;
        M2C_FIELD(arg3, f64 *, 0x10) = (f64) sp138;
        M2C_FIELD(arg3, f64 *, 0x18) = (f64) sp140;
        M2C_FIELD(arg3, f64 *, 0x20) = (f64) sp148;
        M2C_FIELD(arg3, f64 *, 0x28) = (f64) sp150;
        arg3->unk30 = sp158;
        arg3->unk34 = sp15C;
        arg3->unk38 = (s32) sp160;
        arg3->unk3C = sp164;
        arg3->unk40 = sp168;
        arg3->unk44 = sp16C;
        arg3->unk48 = sp170;
        arg3->unk4C = sp174;
        arg3->unk50 = sp178;
        arg3->unk50 = var_r29_1039;
        Normalise(sp30);
        M2C_FIELD(arg3, f64 *, 0x10) = M2C_BITWISE(f64, sp30);
        M2C_FIELD(arg3, f64 *, 0x18) = (f64) sp30.unk8;
        if (GetTriVerts(sp18, *arg3, &sp40) != 0) {
            GetInterpolatedColorFromPoly(sp20, (MKVector3 *) arg3);
            M2C_FIELD(arg3, f64 *, 0x20) = M2C_BITWISE(f64, sp20);
            M2C_FIELD(arg3, f64 *, 0x28) = (f64) sp20.unk8;
        }
    }
    return var_r29_1039;
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKCollisionMode'
s32 MKCollisionManager::GetGroundPoint(const MKVector3 &arg0, const MKVector3 &arg1, MKCollisionResult *arg2, int arg3, int arg4, MKCollisionGroundHint *arg5, MKCollisionMode arg6) {
    u8 sp1A8;
    s32 sp1A4;
    void *sp1A0;
    s32 sp19C;
    f32 sp198;
    s32 sp194;
    s8 sp193;
    s8 sp192;
    s16 sp190;
    f32 sp18C;
    f32 sp188;
    f32 sp184;
    f32 sp180;
    f32 sp17C;
    f32 sp178;
    f32 sp170;
    f32 sp16C;
    f32 sp168;
    f32 sp160;
    f32 sp15C;
    f32 sp158;
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
    MKCollisionRay spA0;
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
    MKVector3 sp38;
    MKVector3 sp28;
    MKVector3 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    MKCollisionModel *var_r15_1602;
    MKCollisionModel *var_r30_1539;
    s32 temp_cr0_eq_1770;
    s32 temp_cr0_eq_1954;
    s32 temp_r18_1662;
    s32 temp_r26_1660;
    s32 temp_r4_1845;
    s32 var_r16_1664;
    s32 var_r16_1847;
    s32 var_r21_1652;
    s32 var_r27_1655;
    s32 var_r28_1649;
    u8 var_r0_1672;
    u8 var_r0_1856;
    u8 var_r18_1854;
    u8 var_r19_1738;
    u8 var_r19_1922;
    u8 var_r20_1670;
    u8 var_r29_1540;
    u8 var_r5_1689;
    u8 var_r5_1873;
    u8 var_r6_1722;
    u8 var_r6_1906;
    u8 var_r7_1674;
    u8 var_r7_1858;
    u8 var_r8_1676;
    u8 var_r8_1860;
    void **temp_r3_1675;
    void **temp_r3_1859;
    void *temp_r3_1760;
    void *temp_r3_1944;
    void *temp_r4_1669;
    void *temp_r4_1740;
    void *temp_r4_1853;
    void *temp_r4_1924;
    void *temp_r5_1721;
    void *temp_r5_1905;
    void *var_r17_1666;
    void *var_r17_1849;

    var_r30_1539 = NULL;
    var_r29_1540 = 0;
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
    spA0.Init(arg0, arg1, 0.0f, (u32) arg3);
    sp158 = 0.0f;
    sp15C = 0.0f;
    sp160 = 0.0f;
    sp168 = 0.0f;
    sp16C = 0.0f;
    sp170 = 0.0f;
    sp178 = 0.0f;
    sp17C = 0.0f;
    sp180 = 0.0f;
    sp184 = 1.0f;
    sp188 = 0.0f;
    sp18C = 0.0f;
    sp190 = 0;
    sp192 = 0;
    sp193 = 0;
    sp194 = 0;
    sp198 = 3.4028235e38f;
    sp19C = 0;
    sp1A0 = NULL;
    sp1A4 = -1;
    sp1A8 = 0;
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
    if ((s32) arg6 & 5) {
        var_r15_1602 = this->unk28;
loop_6:
        if (var_r15_1602 != NULL) {
            if (var_r15_1602->GetGroundPoint(spA0, (MKCollisionResult *) &sp100, (MKCollisionGroundHint *) &sp68) != 0) {
                var_r29_1540 = 1;
                StoreItemInfo((MKCollisionResult *) &sp100, -1, (MKCollisionMode) 7, 0);
                var_r30_1539 = var_r15_1602;
                if (arg5 != NULL) {
                    arg5->Set(&sp68);
                }
            } else {
                var_r15_1602 = M2C_FIELD(var_r15_1602, MKCollisionModel **, 0x48);
                goto loop_6;
            }
        }
    }
    sp14 = 0;
    testID += 1;
    sp10 = 0;
    spC = 0;
    sp8 = 0;
    FindGridOverlap(*((MKCollisionAABB *) &spA0), &sp14, &sp10, &spC, &sp8);
    var_r28_1649 = sp10;
    var_r21_1652 = var_r28_1649 << 5;
loop_86:
    if (var_r28_1649 <= sp8) {
        var_r27_1655 = sp14;
loop_84:
        if (var_r27_1655 <= spC) {
            temp_r26_1660 = (var_r27_1655 + var_r21_1652) & 0x3FF;
            if ((s32) ((s32) arg6 & 1) != 0) {
                temp_r18_1662 = temp_r26_1660 * 0x18;
                var_r16_1664 = 0;
                var_r17_1666 = *(this->unk2C + (temp_r18_1662 + 4));
loop_45:
                if (var_r17_1666 != (void *) (this->unk2C + temp_r18_1662)) {
                    temp_r4_1669 = M2C_FIELD(var_r17_1666, void **, 8);
                    var_r20_1670 = 0;
                    var_r0_1672 = 0;
                    var_r7_1674 = 0;
                    temp_r3_1675 = this->unk34;
                    var_r8_1676 = 0;
                    if ((u32) M2C_FIELD(temp_r4_1669, u32 *, 4) != (u32) testID) {
                        M2C_FIELD(temp_r4_1669, u32 *, 4) = (u32) testID;
                        if (!(M2C_FIELD(temp_r4_1669, s32 *, 0x54) & spA0.unk58)) {
                            var_r8_1676 = 1;
                        }
                    }
                    if (var_r8_1676 != 0) {
                        var_r5_1689 = 0;
                        if ((M2C_FIELD(temp_r4_1669, f32 *, 0x20) > M2C_BITWISE(f32, spA0)) && (M2C_FIELD(temp_r4_1669, f32 *, 0x10) < (f32) spA0.unk10) && (M2C_FIELD(temp_r4_1669, f32 *, 0x24) > unkspA4) && (M2C_FIELD(temp_r4_1669, f32 *, 0x14) < unkspB4) && (M2C_FIELD(temp_r4_1669, f32 *, 0x28) > (f32) spA0.unk8) && (M2C_FIELD(temp_r4_1669, f32 *, 0x18) < (f32) spA0.unk18)) {
                            var_r5_1689 = 1;
                        }
                        if (var_r5_1689 != 0) {
                            var_r7_1674 = 1;
                        }
                    }
                    if (var_r7_1674 != 0) {
                        temp_r5_1721 = M2C_FIELD(temp_r4_1669, void **, 8);
                        var_r6_1722 = 0;
                        if ((temp_r5_1721 == NULL) || ((u8) M2C_FIELD(temp_r5_1721, u8 *, 4) != 0)) {
                            var_r6_1722 = 1;
                        }
                        if (var_r6_1722 != 0) {
                            var_r0_1672 = 1;
                        }
                    }
                    if (var_r0_1672 != 0) {
                        var_r19_1738 = 0;
                        if ((temp_r3_1675 == NULL) || (temp_r4_1740 = M2C_FIELD(temp_r4_1669, void **, 8), ((temp_r4_1740 == NULL) != 0)) || (M2C_FIELD(*temp_r3_1675, u8 (**)(s32, s32), 0x9C)(M2C_FIELD(temp_r4_1740, s32 *, 8), MKResource::sWorkingChunkID.unk0) != 0)) {
                            var_r19_1738 = 1;
                        }
                        if (var_r19_1738 != 0) {
                            var_r20_1670 = 1;
                        }
                    }
                    if (var_r20_1670 != 0) {
                        temp_r3_1760 = M2C_FIELD(var_r17_1666, void **, 8);
                        if ((M2C_FIELD(M2C_FIELD(temp_r3_1760, void **, 0), u8 (**)(void *, MKCollisionRay *, f32 *, M2C_UNK **), 0x10)(temp_r3_1760, &spA0, &sp158, &sp68) != 0) && ((temp_cr0_eq_1770 = var_r29_1540 == 0, (temp_cr0_eq_1770 != 0)) || ((temp_cr0_eq_1770 == 0) && (M2C_ERROR(/* unknown instruction: cror eq, lt, eq */), ((sp198 == sp140) != 0))))) {
                            var_r29_1540 = 1;
                            var_r30_1539 = NULL;
                            sp100 = (f64) sp158;
                            sp108 = (f64) sp160;
                            sp110 = (f64) sp168;
                            sp118 = (f64) sp170;
                            sp120 = (f64) sp178;
                            sp128 = (f64) sp180;
                            sp130 = sp188;
                            sp134 = sp18C;
                            sp138 = (s32) sp190;
                            sp13C = sp194;
                            sp140 = sp198;
                            sp144 = sp19C;
                            sp148 = sp1A0;
                            sp14C = sp1A4;
                            sp150 = sp1A8;
                            StoreItemInfo((MKCollisionResult *) &sp100, temp_r26_1660, (MKCollisionMode) 1, var_r16_1664);
                            if (arg5 != NULL) {
                                arg5->unk8 = sp70;
                                arg5->unk10 = sp78;
                                arg5->unk18 = (f64) sp80;
                                arg5->unk20 = (f64) sp88;
                                arg5->unk28 = sp90;
                                arg5->unk2C = sp94;
                                arg5->unk30 = sp98;
                                arg5->unk34 = sp9C;
                            }
                        }
                    }
                    var_r17_1666 = M2C_FIELD(var_r17_1666, void **, 4);
                    var_r16_1664 += 1;
                    goto loop_45;
                }
            }
            if ((s32) ((s32) arg6 & 2) != 0) {
                temp_r4_1845 = temp_r26_1660 * 0x18;
                var_r16_1847 = 0;
                var_r17_1849 = *(this->unk2C + (temp_r4_1845 + 0x10));
loop_82:
                if (var_r17_1849 != (void *) (this->unk2C + (temp_r4_1845 + 0xC))) {
                    temp_r4_1853 = M2C_FIELD(var_r17_1849, void **, 8);
                    var_r18_1854 = 0;
                    var_r0_1856 = 0;
                    var_r7_1858 = 0;
                    temp_r3_1859 = this->unk34;
                    var_r8_1860 = 0;
                    if ((u32) M2C_FIELD(temp_r4_1853, u32 *, 4) != (u32) testID) {
                        M2C_FIELD(temp_r4_1853, u32 *, 4) = (u32) testID;
                        if (!(M2C_FIELD(temp_r4_1853, s32 *, 0x54) & spA0.unk58)) {
                            var_r8_1860 = 1;
                        }
                    }
                    if (var_r8_1860 != 0) {
                        var_r5_1873 = 0;
                        if ((M2C_FIELD(temp_r4_1853, f32 *, 0x20) > M2C_BITWISE(f32, spA0)) && (M2C_FIELD(temp_r4_1853, f32 *, 0x10) < (f32) spA0.unk10) && (M2C_FIELD(temp_r4_1853, f32 *, 0x24) > unkspA4) && (M2C_FIELD(temp_r4_1853, f32 *, 0x14) < unkspB4) && (M2C_FIELD(temp_r4_1853, f32 *, 0x28) > (f32) spA0.unk8) && (M2C_FIELD(temp_r4_1853, f32 *, 0x18) < (f32) spA0.unk18)) {
                            var_r5_1873 = 1;
                        }
                        if (var_r5_1873 != 0) {
                            var_r7_1858 = 1;
                        }
                    }
                    if (var_r7_1858 != 0) {
                        temp_r5_1905 = M2C_FIELD(temp_r4_1853, void **, 8);
                        var_r6_1906 = 0;
                        if ((temp_r5_1905 == NULL) || ((u8) M2C_FIELD(temp_r5_1905, u8 *, 4) != 0)) {
                            var_r6_1906 = 1;
                        }
                        if (var_r6_1906 != 0) {
                            var_r0_1856 = 1;
                        }
                    }
                    if (var_r0_1856 != 0) {
                        var_r19_1922 = 0;
                        if ((temp_r3_1859 == NULL) || (temp_r4_1924 = M2C_FIELD(temp_r4_1853, void **, 8), ((temp_r4_1924 == NULL) != 0)) || (M2C_FIELD(*temp_r3_1859, u8 (**)(s32, s32), 0x9C)(M2C_FIELD(temp_r4_1924, s32 *, 8), MKResource::sWorkingChunkID.unk0) != 0)) {
                            var_r19_1922 = 1;
                        }
                        if (var_r19_1922 != 0) {
                            var_r18_1854 = 1;
                        }
                    }
                    if (var_r18_1854 != 0) {
                        temp_r3_1944 = M2C_FIELD(var_r17_1849, void **, 8);
                        if ((M2C_FIELD(M2C_FIELD(temp_r3_1944, void **, 0), u8 (**)(void *, MKCollisionRay *, f32 *, M2C_UNK **), 0x10)(temp_r3_1944, &spA0, &sp158, &sp68) != 0) && ((temp_cr0_eq_1954 = var_r29_1540 == 0, (temp_cr0_eq_1954 != 0)) || ((temp_cr0_eq_1954 == 0) && (M2C_ERROR(/* unknown instruction: cror eq, lt, eq */), ((sp198 == sp140) != 0))))) {
                            var_r29_1540 = 1;
                            var_r30_1539 = NULL;
                            sp100 = (f64) sp158;
                            sp108 = (f64) sp160;
                            sp110 = (f64) sp168;
                            sp118 = (f64) sp170;
                            sp120 = (f64) sp178;
                            sp128 = (f64) sp180;
                            sp130 = sp188;
                            sp134 = sp18C;
                            sp138 = (s32) sp190;
                            sp13C = sp194;
                            sp140 = sp198;
                            sp144 = sp19C;
                            sp148 = sp1A0;
                            sp14C = sp1A4;
                            sp150 = sp1A8;
                            StoreItemInfo((MKCollisionResult *) &sp100, temp_r26_1660, (MKCollisionMode) 2, var_r16_1847);
                            if (arg5 != NULL) {
                                arg5->unk8 = sp70;
                                arg5->unk10 = sp78;
                                arg5->unk18 = (f64) sp80;
                                arg5->unk20 = (f64) sp88;
                                arg5->unk28 = sp90;
                                arg5->unk2C = sp94;
                                arg5->unk30 = sp98;
                                arg5->unk34 = sp9C;
                            }
                        }
                    }
                    var_r17_1849 = M2C_FIELD(var_r17_1849, void **, 4);
                    var_r16_1847 += 1;
                    goto loop_82;
                }
            }
            var_r27_1655 += 1;
            goto loop_84;
        }
        var_r28_1649 += 1;
        var_r21_1652 += 0x20;
        goto loop_86;
    }
    if (var_r29_1540 != 0) {
        M2C_FIELD(arg2, f64 *, 0) = sp100;
        M2C_FIELD(arg2, f64 *, 8) = sp108;
        M2C_FIELD(arg2, f64 *, 0x10) = sp110;
        M2C_FIELD(arg2, f64 *, 0x18) = sp118;
        M2C_FIELD(arg2, f64 *, 0x20) = sp120;
        M2C_FIELD(arg2, f64 *, 0x28) = sp128;
        arg2->unk30 = sp130;
        arg2->unk34 = sp134;
        arg2->unk38 = sp138;
        arg2->unk3C = sp13C;
        arg2->unk40 = sp140;
        arg2->unk44 = sp144;
        arg2->unk48 = sp148;
        arg2->unk4C = sp14C;
        arg2->unk50 = sp150;
        arg2->unk50 = 1;
        if (arg4 & 2) {
            Normalise(sp28);
            M2C_FIELD(arg2, f64 *, 0x10) = M2C_BITWISE(f64, sp28);
            M2C_FIELD(arg2, f64 *, 0x18) = (f64) sp28.unk8;
            if (arg5 != NULL) {
                arg5->unk8 = M2C_FIELD(arg2, f64 *, 0x10);
                arg5->unk10 = M2C_FIELD(arg2, f64 *, 0x18);
            }
        }
        if ((arg4 & 4) && (GetTriVerts(var_r30_1539, *arg2, &sp38) != 0)) {
            GetInterpolatedColorFromPoly(sp18, (MKVector3 *) arg2);
            M2C_FIELD(arg2, f64 *, 0x20) = M2C_BITWISE(f64, sp18);
            M2C_FIELD(arg2, f64 *, 0x28) = (f64) sp18.unk8;
            if (arg5 != NULL) {
                arg5->unk18 = M2C_FIELD(arg2, f64 *, 0x20);
                arg5->unk20 = M2C_FIELD(arg2, f64 *, 0x28);
            }
        }
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKCollisionMode'
u8 MKCollisionManager::RayCollide(const MKVector3 &arg0, const MKVector3 &arg1, MKCollisionResult *arg2, MKCollisionMode arg3, int arg4) {
    u8 sp178;
    s32 sp174;
    void *sp170;
    s32 sp16C;
    f32 sp168;
    s32 sp164;
    s8 sp163;
    s8 sp162;
    s16 sp160;
    f32 sp15C;
    f32 sp158;
    f32 sp154;
    f32 sp150;
    f32 sp14C;
    f32 sp148;
    f32 sp140;
    f32 sp13C;
    f32 sp138;
    f32 sp130;
    f32 sp12C;
    f32 sp128;
    s8 sp120;
    s32 sp11C;
    s32 sp118;
    s32 sp114;
    f32 sp110;
    s32 sp10C;
    s8 sp10B;
    s8 sp10A;
    s16 sp108;
    f32 sp104;
    f32 sp100;
    f32 spFC;
    f32 spF8;
    f32 spF4;
    f32 spF0;
    f32 spE8;
    f32 spE4;
    f32 spE0;
    f32 spD8;
    f32 spD4;
    f32 spD0;
    MKCollisionRay sp70;
    MKVector3 sp40;
    MKVector3 sp30;
    MKVector3 sp20;
    MKCollisionModel *sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    MKCollisionModel *var_r20_2188;
    s32 temp_r20_2276;
    s32 temp_r26_2274;
    s32 temp_r4_2410;
    s32 var_r18_2278;
    s32 var_r18_2412;
    s32 var_r23_2266;
    s32 var_r27_2269;
    s32 var_r28_2263;
    u8 var_r0_2192;
    u8 var_r0_2303;
    u8 var_r0_2438;
    u8 var_r19_2223;
    u8 var_r20_2419;
    u8 var_r20_2512;
    u8 var_r21_2352;
    u8 var_r21_2377;
    u8 var_r21_2487;
    u8 var_r22_2284;
    u8 var_r29_2141;
    u8 var_r5_2336;
    u8 var_r5_2471;
    u8 var_r6_2286;
    u8 var_r6_2421;
    u8 var_r7_2288;
    u8 var_r7_2423;
    u8 var_r8_2290;
    u8 var_r8_2425;
    void **temp_r3_2289;
    void **temp_r3_2424;
    void *temp_r3_2374;
    void *temp_r3_2509;
    void *temp_r4_2283;
    void *temp_r4_2354;
    void *temp_r4_2418;
    void *temp_r4_2489;
    void *temp_r7_2335;
    void *temp_r7_2470;
    void *var_r19_2280;
    void *var_r19_2414;

    var_r29_2141 = 0;
    sp128 = 0.0f;
    sp12C = 0.0f;
    sp130 = 0.0f;
    sp138 = 0.0f;
    sp13C = 0.0f;
    sp140 = 0.0f;
    sp148 = 0.0f;
    sp14C = 0.0f;
    sp150 = 0.0f;
    sp154 = 1.0f;
    sp158 = 0.0f;
    sp15C = 0.0f;
    sp160 = 0;
    sp162 = 0;
    sp163 = 0;
    sp164 = 0;
    sp168 = 3.4028235e38f;
    sp16C = 0;
    sp170 = NULL;
    sp174 = -1;
    sp178 = 0;
    sp18 = NULL;
    spD0 = 0.0f;
    spD4 = 0.0f;
    spD8 = 0.0f;
    spE0 = 0.0f;
    spE4 = 0.0f;
    spE8 = 0.0f;
    spF0 = 0.0f;
    spF4 = 0.0f;
    spF8 = 0.0f;
    spFC = 1.0f;
    sp100 = 0.0f;
    sp104 = 0.0f;
    sp108 = 0;
    sp10A = 0;
    sp10B = 0;
    sp10C = 0;
    sp110 = 3.4028235e38f;
    sp114 = 0;
    sp118 = 0;
    sp11C = -1;
    sp120 = 0;
    sp70.Init(arg0, arg1, 0.0f, (u32) arg4);
    if ((s32) arg3 & 5) {
        var_r20_2188 = this->unk28;
loop_15:
        if (var_r20_2188 != NULL) {
            var_r0_2192 = 0;
            if (((f32) sp70.unk10 > var_r20_2188->unk8.unk0) && (M2C_BITWISE(f32, sp70) < var_r20_2188->unk8.unk10) && (unksp84 > var_r20_2188->unk8.unk4) && (unksp74 < var_r20_2188->unk8.unk14) && ((f32) sp70.unk18 > var_r20_2188->unk8.unk8) && ((f32) sp70.unk8 < var_r20_2188->unk8.unk18)) {
                var_r0_2192 = 1;
            }
            if (var_r0_2192 != 0) {
                var_r19_2223 = 0;
                var_r20_2188->RayTest(sp70, (MKCollisionResult *) &spD0);
                if ((UpdateBestResult(var_r20_2188, M2C_ERROR(/* Read from unset register $r3 */), *((MKCollisionResult *) &spD0), (MKCollisionResult *) &sp128, sp18, -1, (MKCollisionMode) 7, 0) != 0) || (var_r29_2141 != 0)) {
                    var_r19_2223 = 1;
                }
                var_r29_2141 = var_r19_2223;
            }
            var_r20_2188 = M2C_FIELD(var_r20_2188, MKCollisionModel **, 0x48);
            goto loop_15;
        }
    }
    sp14 = 0;
    testID += 1;
    sp10 = 0;
    spC = 0;
    sp8 = 0;
    FindGridOverlap(*((MKCollisionAABB *) &sp70), &sp14, &sp10, &spC, &sp8);
    var_r28_2263 = sp10;
    var_r23_2266 = var_r28_2263 << 5;
loop_91:
    if (var_r28_2263 <= sp8) {
        var_r27_2269 = sp14;
loop_89:
        if (var_r27_2269 <= spC) {
            temp_r26_2274 = (var_r27_2269 + var_r23_2266) & 0x3FF;
            if ((s32) ((s32) arg3 & 1) != 0) {
                temp_r20_2276 = temp_r26_2274 * 0x18;
                var_r18_2278 = 0;
                var_r19_2280 = *(this->unk2C + (temp_r20_2276 + 4));
loop_52:
                if (var_r19_2280 != (void *) (this->unk2C + temp_r20_2276)) {
                    temp_r4_2283 = M2C_FIELD(var_r19_2280, void **, 8);
                    var_r22_2284 = 0;
                    var_r6_2286 = 0;
                    var_r7_2288 = 0;
                    temp_r3_2289 = this->unk34;
                    var_r8_2290 = 0;
                    if ((u32) M2C_FIELD(temp_r4_2283, u32 *, 4) != (u32) testID) {
                        M2C_FIELD(temp_r4_2283, u32 *, 4) = (u32) testID;
                        if (!(M2C_FIELD(temp_r4_2283, s32 *, 0x54) & sp70.unk58)) {
                            var_r8_2290 = 1;
                        }
                    }
                    if (var_r8_2290 != 0) {
                        var_r0_2303 = 0;
                        if ((M2C_FIELD(temp_r4_2283, f32 *, 0x20) > M2C_BITWISE(f32, sp70)) && (M2C_FIELD(temp_r4_2283, f32 *, 0x10) < (f32) sp70.unk10) && (M2C_FIELD(temp_r4_2283, f32 *, 0x24) > unksp74) && (M2C_FIELD(temp_r4_2283, f32 *, 0x14) < unksp84) && (M2C_FIELD(temp_r4_2283, f32 *, 0x28) > (f32) sp70.unk8) && (M2C_FIELD(temp_r4_2283, f32 *, 0x18) < (f32) sp70.unk18)) {
                            var_r0_2303 = 1;
                        }
                        if (var_r0_2303 != 0) {
                            var_r7_2288 = 1;
                        }
                    }
                    if (var_r7_2288 != 0) {
                        temp_r7_2335 = M2C_FIELD(temp_r4_2283, void **, 8);
                        var_r5_2336 = 0;
                        if ((temp_r7_2335 == NULL) || ((u8) M2C_FIELD(temp_r7_2335, u8 *, 4) != 0)) {
                            var_r5_2336 = 1;
                        }
                        if (var_r5_2336 != 0) {
                            var_r6_2286 = 1;
                        }
                    }
                    if (var_r6_2286 != 0) {
                        var_r21_2352 = 0;
                        if ((temp_r3_2289 == NULL) || (temp_r4_2354 = M2C_FIELD(temp_r4_2283, void **, 8), ((temp_r4_2354 == NULL) != 0)) || (M2C_FIELD(*temp_r3_2289, u8 (**)(s32, s32), 0x9C)(M2C_FIELD(temp_r4_2354, s32 *, 8), MKResource::sWorkingChunkID.unk0) != 0)) {
                            var_r21_2352 = 1;
                        }
                        if (var_r21_2352 != 0) {
                            var_r22_2284 = 1;
                        }
                    }
                    if (var_r22_2284 != 0) {
                        temp_r3_2374 = M2C_FIELD(var_r19_2280, void **, 8);
                        var_r21_2377 = 0;
                        if ((UpdateBestResult(NULL, M2C_FIELD(M2C_FIELD(temp_r3_2374, void **, 0), u8 (**)(void *, MKCollisionRay *, f32 *), 0xC)(temp_r3_2374, &sp70, &spD0), *((MKCollisionResult *) &spD0), (MKCollisionResult *) &sp128, sp18, temp_r26_2274, (MKCollisionMode) 1, var_r18_2278) != 0) || (var_r29_2141 != 0)) {
                            var_r21_2377 = 1;
                        }
                        var_r29_2141 = var_r21_2377;
                    }
                    var_r19_2280 = M2C_FIELD(var_r19_2280, void **, 4);
                    var_r18_2278 += 1;
                    goto loop_52;
                }
            }
            if ((s32) ((s32) arg3 & 2) != 0) {
                temp_r4_2410 = temp_r26_2274 * 0x18;
                var_r18_2412 = 0;
                var_r19_2414 = *(this->unk2C + (temp_r4_2410 + 0x10));
loop_87:
                if (var_r19_2414 != (void *) (this->unk2C + (temp_r4_2410 + 0xC))) {
                    temp_r4_2418 = M2C_FIELD(var_r19_2414, void **, 8);
                    var_r20_2419 = 0;
                    var_r6_2421 = 0;
                    var_r7_2423 = 0;
                    temp_r3_2424 = this->unk34;
                    var_r8_2425 = 0;
                    if ((u32) M2C_FIELD(temp_r4_2418, u32 *, 4) != (u32) testID) {
                        M2C_FIELD(temp_r4_2418, u32 *, 4) = (u32) testID;
                        if (!(M2C_FIELD(temp_r4_2418, s32 *, 0x54) & sp70.unk58)) {
                            var_r8_2425 = 1;
                        }
                    }
                    if (var_r8_2425 != 0) {
                        var_r0_2438 = 0;
                        if ((M2C_FIELD(temp_r4_2418, f32 *, 0x20) > M2C_BITWISE(f32, sp70)) && (M2C_FIELD(temp_r4_2418, f32 *, 0x10) < (f32) sp70.unk10) && (M2C_FIELD(temp_r4_2418, f32 *, 0x24) > unksp74) && (M2C_FIELD(temp_r4_2418, f32 *, 0x14) < unksp84) && (M2C_FIELD(temp_r4_2418, f32 *, 0x28) > (f32) sp70.unk8) && (M2C_FIELD(temp_r4_2418, f32 *, 0x18) < (f32) sp70.unk18)) {
                            var_r0_2438 = 1;
                        }
                        if (var_r0_2438 != 0) {
                            var_r7_2423 = 1;
                        }
                    }
                    if (var_r7_2423 != 0) {
                        temp_r7_2470 = M2C_FIELD(temp_r4_2418, void **, 8);
                        var_r5_2471 = 0;
                        if ((temp_r7_2470 == NULL) || ((u8) M2C_FIELD(temp_r7_2470, u8 *, 4) != 0)) {
                            var_r5_2471 = 1;
                        }
                        if (var_r5_2471 != 0) {
                            var_r6_2421 = 1;
                        }
                    }
                    if (var_r6_2421 != 0) {
                        var_r21_2487 = 0;
                        if ((temp_r3_2424 == NULL) || (temp_r4_2489 = M2C_FIELD(temp_r4_2418, void **, 8), ((temp_r4_2489 == NULL) != 0)) || (M2C_FIELD(*temp_r3_2424, u8 (**)(s32, s32), 0x9C)(M2C_FIELD(temp_r4_2489, s32 *, 8), MKResource::sWorkingChunkID.unk0) != 0)) {
                            var_r21_2487 = 1;
                        }
                        if (var_r21_2487 != 0) {
                            var_r20_2419 = 1;
                        }
                    }
                    if (var_r20_2419 != 0) {
                        temp_r3_2509 = M2C_FIELD(var_r19_2414, void **, 8);
                        var_r20_2512 = 0;
                        if ((UpdateBestResult(NULL, M2C_FIELD(M2C_FIELD(temp_r3_2509, void **, 0), u8 (**)(void *, MKCollisionRay *, f32 *), 0xC)(temp_r3_2509, &sp70, &spD0), *((MKCollisionResult *) &spD0), (MKCollisionResult *) &sp128, sp18, temp_r26_2274, (MKCollisionMode) 2, var_r18_2412) != 0) || (var_r29_2141 != 0)) {
                            var_r20_2512 = 1;
                        }
                        var_r29_2141 = var_r20_2512;
                    }
                    var_r19_2414 = M2C_FIELD(var_r19_2414, void **, 4);
                    var_r18_2412 += 1;
                    goto loop_87;
                }
            }
            var_r27_2269 += 1;
            goto loop_89;
        }
        var_r28_2263 += 1;
        var_r23_2266 += 0x20;
        goto loop_91;
    }
    if ((var_r29_2141 != 0) && (arg2 != NULL)) {
        M2C_FIELD(arg2, f64 *, 0) = (f64) sp128;
        M2C_FIELD(arg2, f64 *, 8) = (f64) sp130;
        M2C_FIELD(arg2, f64 *, 0x10) = (f64) sp138;
        M2C_FIELD(arg2, f64 *, 0x18) = (f64) sp140;
        M2C_FIELD(arg2, f64 *, 0x20) = (f64) sp148;
        M2C_FIELD(arg2, f64 *, 0x28) = (f64) sp150;
        arg2->unk30 = sp158;
        arg2->unk34 = sp15C;
        arg2->unk38 = (s32) sp160;
        arg2->unk3C = sp164;
        arg2->unk40 = sp168;
        arg2->unk44 = sp16C;
        arg2->unk48 = sp170;
        arg2->unk4C = sp174;
        arg2->unk50 = sp178;
        arg2->unk50 = var_r29_2141;
        Normalise(sp30);
        M2C_FIELD(arg2, f64 *, 0x10) = M2C_BITWISE(f64, sp30);
        M2C_FIELD(arg2, f64 *, 0x18) = (f64) sp30.unk8;
        if (GetTriVerts(sp18, *arg2, &sp40) != 0) {
            GetInterpolatedColorFromPoly(sp20, (MKVector3 *) arg2);
            M2C_FIELD(arg2, f64 *, 0x20) = M2C_BITWISE(f64, sp20);
            M2C_FIELD(arg2, f64 *, 0x28) = (f64) sp20.unk8;
        }
    }
    return var_r29_2141;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void MKCollisionManager::ForceUpdate(unsigned int arg0) {
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), M2C_UNK (**)(u32), 0x28)(arg0);
    ((MKCollisionManager *) (M2C_FIELD(arg0, MKCollisionManager **, 0x50)))->UpdateItemLinks((MKCollisionItem *) arg0, (MKCollisionMode) 2);
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKCollisionMode'
void MKCollisionManager::AddCapsule(MKVector3 *arg0, MKVector3 *arg1, float arg2, const MKVector4 &arg3, const MKVector4 &arg4, MKCollisionMode arg5, MKCollisionInfo *arg6, unsigned int arg7) {
    MKCollisionCapsuleItem *temp_r31_2671;
    s32 temp_r3_2733;
    operator new(0xB0U, NULL, 0);
    temp_r31_2671 = M2C_ERROR(/* Read from unset register $r3 */);
    if (temp_r31_2671 != NULL) {
        temp_r31_2671->__vptr = &__vt;
        temp_r31_2671->__vptr = &__vt;
        temp_r31_2671->__vptr = &__vt;
    }
    arg_spB0.SetIdentity();
    arg_sp38 = arg2;
    arg_sp30 = arg2;
    arg_sp34 = arg2;
    arg_sp88 = (f64) arg_sp38;
    arg_sp80 = (f64) arg_sp30;
    Min(*((MKVector3 *) &arg_sp60), *arg0);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    arg_sp70 = arg_sp20;
    arg_sp28 = arg_sp68 - (f32) arg_sp88;
    arg_sp90 = arg_sp20;
    arg_sp78 = (f64) arg_sp28;
    arg_sp98 = (f64) arg_sp28;
    Max(*((MKVector3 *) &arg_sp40), *arg0);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp50 = arg_sp10;
    arg_sp18 = arg_sp48 + (f32) arg_sp88;
    arg_spA0 = arg_sp10;
    arg_sp58 = (f64) arg_sp18;
    arg_spA8 = (f64) arg_sp18;
    temp_r3_2733 = CalcMaxGridOverlap(*((MKCollisionAABB *) &arg_sp90), (Matrix *) &arg_spB0, arg5);
    arg_sp8 = arg7;
    arg_spC = this;
    temp_r31_2671->Init(arg0, arg1, arg2, arg3, arg4, arg5, arg6, temp_r3_2733, M2C_ERROR(/* Unable to find stack arg 0x0 in block */), M2C_ERROR(/* Unable to find stack arg 0x4 in block */));
    if ((s32) arg5 & 2) {
        temp_r31_2671->unkC = (s32) this->unk30;
        this->unk30 = temp_r31_2671;
    }
    UpdateItemLinks((MKCollisionItem *) temp_r31_2671, arg5);
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKCollisionMode'
void MKCollisionManager::AddSphere(MKVector3 *arg0, float arg1, float arg2, const MKVector4 &arg3, MKCollisionMode arg4, MKCollisionInfo *arg5, unsigned int arg6) {
    MKCollisionSphereItem *temp_r31_2794;
    f32 temp_f3_2820;
    operator new(0x90U, NULL, 0);
    temp_r31_2794 = M2C_ERROR(/* Read from unset register $r3 */);
    if (temp_r31_2794 != NULL) {
        temp_r31_2794->__vptr = &__vt;
        temp_r31_2794->__vptr = &__vt;
        temp_r31_2794->__vptr = &__vt;
    }
    arg_sp90.SetIdentity();
    arg_sp30 = arg1;
    arg_sp34 = arg1;
    arg_sp38 = arg1;
    arg_sp60 = (f64) arg_sp30;
    arg_sp68 = (f64) arg_sp38;
    M2C_ERROR(/* unknown instruction: psq_lx $f2, $zero, $r26, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f2, $f1 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f1 */);
    temp_f3_2820 = arg0->unk8;
    arg_sp50 = arg_sp20;
    arg_sp70 = arg_sp20;
    arg_sp28 = temp_f3_2820 - (f32) arg_sp68;
    arg_sp58 = (f64) arg_sp28;
    arg_sp78 = (f64) arg_sp28;
    arg_sp18 = temp_f3_2820 + (f32) arg_sp68;
    arg_sp40 = arg_sp10;
    arg_sp48 = (f64) arg_sp18;
    arg_sp80 = arg_sp10;
    arg_sp88 = (f64) arg_sp18;
    temp_r31_2794->Init(arg0, arg1, arg2, arg3, arg4, arg5, CalcMaxGridOverlap(*((MKCollisionAABB *) &arg_sp70), (Matrix *) &arg_sp90, arg4), arg6, this);
    if ((s32) arg4 & 2) {
        temp_r31_2794->unkC = (s32) this->unk30;
        this->unk30 = (MKCollisionCapsuleItem *) temp_r31_2794;
    }
    UpdateItemLinks((MKCollisionItem *) temp_r31_2794, arg4);
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKCollisionMode'
void MKCollisionManager::AddModel(MKModel *arg0, int arg1, MKCollisionMode arg2, MKCollisionInfo *arg3, unsigned int arg4) {
    MKCollisionModelItem *temp_r30_2914;
    MKHeap *temp_r29_2896;
    s32 temp_r3_2930;
    temp_r29_2896 = CreateCollisionModel(arg0, arg1);
    if (MKModel_GetAnimation(arg0) != NULL) {
        MKModel_GetAnimation(arg0);
    }
    MKModel_CalculateSubObjectLocalToWorldMatrix(arg0, (SubObjectType) 0, arg1, (Matrix *) &arg_sp10);
    if (temp_r29_2896 != NULL) {
        operator new(0x130U, NULL, 0);
        temp_r30_2914 = M2C_ERROR(/* Read from unset register $r3 */);
        if (temp_r30_2914 != NULL) {
            temp_r30_2914->__vptr = &__vt;
            temp_r30_2914->__vptr = &__vt;
            temp_r30_2914->__vptr = &__vt;
        }
        temp_r3_2930 = CalcMaxGridOverlap(*((MKCollisionAABB *) &temp_r29_2896->unk8), (Matrix *) &arg_sp10, arg2);
        arg_sp8 = this;
        temp_r30_2914->Init((MKCollisionModel *) temp_r29_2896, arg0, arg1, arg2, arg3, temp_r3_2930, arg4, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
        if ((s32) arg2 & 2) {
            temp_r30_2914->unkC = (s32) this->unk30;
            this->unk30 = (MKCollisionCapsuleItem *) temp_r30_2914;
        }
        UpdateItemLinks((MKCollisionItem *) temp_r30_2914, arg2);
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void MKCollisionManager::Update() {
    MKCollisionCapsuleItem *var_r31_2971;

    if ((u8) this->unk38 != 0) {
        var_r31_2971 = this->unk30;
loop_3:
        if (var_r31_2971 != NULL) {
            var_r31_2971->Update();
            UpdateItemLinks((MKCollisionItem *) var_r31_2971, (MKCollisionMode) 2);
            var_r31_2971 = (MKCollisionCapsuleItem *) var_r31_2971->unkC;
            goto loop_3;
        }
    }
}
#endif

u8 MKCollisionManager::Enable(bool arg0) {
    u8 temp_r0_2998;

    temp_r0_2998 = this->unk38;
    this->unk38 = arg0;
    return temp_r0_2998;
}

#if 0 // DRAFT: illegal implicit conversion from 'MKHeap' to
void MKCollisionManager::Deinit() {
    MKHeap *temp_r30_3060;
    MKHeap *temp_r3_3030;
    MKHeap *temp_r3_3061;
    s32 var_r28_3012;
    s32 var_r31_3013;
    s8 *temp_r28_3087;
    s8 *var_r27_3074;
    void **temp_r3_3022;
    void **temp_r3_3041;
    void **temp_r3_3077;
    void *temp_r27_3039;
    void *temp_r30_3020;
    void *var_r29_3017;
    void *var_r29_3036;

    var_r28_3012 = 0;
    var_r31_3013 = 0;
    do {
        var_r29_3017 = *(this->unk2C + (var_r31_3013 + 4));
loop_3:
        temp_r3_3030 = this->unk2C;
        if (var_r29_3017 != (void *) (temp_r3_3030 + var_r31_3013)) {
            temp_r30_3020 = var_r29_3017;
            var_r29_3017 = M2C_FIELD(var_r29_3017, void **, 4);
            temp_r3_3022 = M2C_FIELD(temp_r30_3020, void ***, 8);
            M2C_FIELD(*temp_r3_3022, M2C_UNK (**)(void **), 8)(temp_r3_3022);
            operator delete(M2C_FIELD(temp_r30_3020, void ***, 8));
            goto loop_3;
        }
        var_r29_3036 = *(temp_r3_3030 + (var_r31_3013 + 0x10));
loop_6:
        if (var_r29_3036 != (void *) (this->unk2C + (var_r31_3013 + 0xC))) {
            temp_r27_3039 = var_r29_3036;
            var_r29_3036 = M2C_FIELD(var_r29_3036, void **, 4);
            temp_r3_3041 = M2C_FIELD(temp_r27_3039, void ***, 8);
            M2C_FIELD(*temp_r3_3041, M2C_UNK (**)(void **), 8)(temp_r3_3041);
            operator delete(M2C_FIELD(temp_r27_3039, void ***, 8));
            goto loop_6;
        }
        var_r28_3012 += 1;
        var_r31_3013 += 0x18;
    } while (var_r28_3012 < 0x400);
    this->unk30 = NULL;
    this->unk28 = NULL;
    temp_r30_3060 = this->unk2C;
    temp_r3_3061 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_3061 != NULL) {
        ((MKHeap *) (temp_r3_3061->Current()))->Free(temp_r30_3060, NULL, 0);
    } else {
        free(temp_r30_3060);
    }
    var_r27_3074 = this->unk24;
loop_15:
    if (var_r27_3074 != NULL) {
        temp_r3_3077 = M2C_FIELD(var_r27_3074, void ***, 0x20);
        if (temp_r3_3077 != NULL) {
            M2C_FIELD(*temp_r3_3077, M2C_UNK (**)(), 8)();
            operator delete(M2C_FIELD(var_r27_3074, void ***, 0x20));
        }
        temp_r28_3087 = M2C_FIELD(var_r27_3074, s8 **, 0x28);
        operator delete(var_r27_3074);
        var_r27_3074 = temp_r28_3087;
        goto loop_15;
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void MKCollisionManager::Init(const char **arg0, int arg1, MKSceneManager *arg2, int arg3) {
    MKCollisionModel *temp_r28_3121;
    MKCollisionModel *var_r3_3141;
    f32 temp_f1_3158;
    f32 temp_f1_3167;
    f32 temp_f1_3176;
    f32 temp_f1_3185;
    f32 temp_f1_3194;
    f32 temp_f1_3203;
    f32 var_f0_3157;
    f32 var_f0_3166;
    f32 var_f0_3175;
    f32 var_f0_3184;
    f32 var_f0_3193;
    f32 var_f0_3202;
    s32 var_ctr_3223;
    s32 var_r29_3114;
    s32 var_r30_3109;
    s32 var_r3_3222;
    void *temp_r0_3229;
    void *temp_r4_3226;

    var_r30_3109 = 0;
    var_r29_3114 = 0;
    this->unk38 = 1;
    this->unk34 = &arg2->__vptr;
    this->unk24 = NULL;
    this->unk30 = NULL;
loop_2:
    if (var_r29_3114 < arg3) {
        temp_r28_3121 = this->unk28;
        this->unk28 = CreateCollisionModel(*(arg0 + var_r30_3109), arg1);
        var_r29_3114 += 1;
        var_r30_3109 += 4;
        M2C_FIELD(this->unk28, MKCollisionModel **, 0x48) = temp_r28_3121;
        goto loop_2;
    }
    M2C_FIELD(this, f64 *, 0) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 8) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
    M2C_FIELD(this, f64 *, 0x10) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x18) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
    var_r3_3141 = this->unk28;
loop_26:
    if (var_r3_3141 != NULL) {
        if (var_r3_3141 == (MKCollisionModel *) this->unk28) {
            M2C_FIELD(this, f64 *, 0) = (f64) M2C_FIELD(var_r3_3141, f64 *, 8);
            M2C_FIELD(this, f64 *, 8) = (f64) M2C_FIELD(var_r3_3141, f64 *, 0x10);
            M2C_FIELD(this, f64 *, 0x10) = (f64) M2C_FIELD(var_r3_3141, f64 *, 0x18);
            M2C_FIELD(this, f64 *, 0x18) = (f64) M2C_FIELD(var_r3_3141, f64 *, 0x20);
        } else {
            var_f0_3157 = var_r3_3141->unk8.unk10;
            temp_f1_3158 = this->unk10;
            if (var_f0_3157 > temp_f1_3158) {

            } else {
                var_f0_3157 = temp_f1_3158;
            }
            this->unk10 = var_f0_3157;
            var_f0_3166 = var_r3_3141->unk8.unk14;
            temp_f1_3167 = this->unk14;
            if (var_f0_3166 > temp_f1_3167) {

            } else {
                var_f0_3166 = temp_f1_3167;
            }
            this->unk14 = var_f0_3166;
            var_f0_3175 = var_r3_3141->unk8.unk18;
            temp_f1_3176 = this->unk18;
            if (var_f0_3175 > temp_f1_3176) {

            } else {
                var_f0_3175 = temp_f1_3176;
            }
            this->unk18 = var_f0_3175;
            var_f0_3184 = var_r3_3141->unk8.unk0;
            temp_f1_3185 = this->unk0;
            if (var_f0_3184 < temp_f1_3185) {

            } else {
                var_f0_3184 = temp_f1_3185;
            }
            this->unk0 = var_f0_3184;
            var_f0_3193 = var_r3_3141->unk8.unk4;
            temp_f1_3194 = this->unk4;
            if (var_f0_3193 < temp_f1_3194) {

            } else {
                var_f0_3193 = temp_f1_3194;
            }
            this->unk4 = var_f0_3193;
            var_f0_3202 = var_r3_3141->unk8.unk8;
            temp_f1_3203 = this->unk8;
            if (var_f0_3202 < temp_f1_3203) {

            } else {
                var_f0_3202 = temp_f1_3203;
            }
            this->unk8 = var_f0_3202;
        }
        var_r3_3141 = M2C_FIELD(var_r3_3141, MKCollisionModel **, 0x48);
        goto loop_26;
    }
    operator new[](0x6000U, NULL, 0);
    this->unk2C = M2C_ERROR(/* Read from unset register $r3 */);
    var_r3_3222 = 0;
    var_ctr_3223 = 0x400;
    do {
        temp_r4_3226 = this->unk2C + var_r3_3222;
        var_r3_3222 += 0x18;
        M2C_FIELD(temp_r4_3226, void **, 4) = temp_r4_3226;
        temp_r0_3229 = temp_r4_3226 + 0xC;
        M2C_FIELD(temp_r4_3226, void **, 0) = temp_r4_3226;
        M2C_FIELD(temp_r4_3226, void **, 0x10) = temp_r0_3229;
        M2C_FIELD(temp_r4_3226, void **, 0xC) = temp_r0_3229;
        var_ctr_3223 -= 1;
    } while (var_ctr_3223 != 0);
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
MKCollisionManager::MKCollisionManager() {
    this->unk28 = NULL;
    this->unk2C = NULL;
    this->unk30 = NULL;
    this->unk20 = 0;
    return this;
}
#endif

void MKCollisionManager::FindGridOverlap(const MKCollisionAABB &arg0, int *arg1, int *arg2, int *arg3, int *arg4) {
    *arg1 = (s32) (0.001f * arg0.unk0);
    *arg2 = (s32) (0.001f * arg0.unk8);
    *arg3 = (s32) (0.001f * arg0.unk10);
    *arg4 = (s32) (0.001f * arg0.unk18);
}

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKCollisionMode'
s32 MKCollisionManager::UpdateSphereResults(MKCollisionModel *arg0, int arg1, MKCollisionResult *arg2, int arg3, MKCollisionMode arg4, int arg5) {
    MKVector3 sp28;
    MKVector3 sp18;
    MKVector3 sp8;
    MKCollisionResult *temp_r30_3303;
    s32 var_r29_3299;
    s32 var_r31_3300;

    var_r29_3299 = 0;
    var_r31_3300 = 0;
loop_4:
    if (var_r29_3299 < arg1) {
        temp_r30_3303 = arg2 + var_r31_3300;
        StoreItemInfo(temp_r30_3303, arg3, arg4, arg5);
        temp_r30_3303->unk50 = 1;
        Normalise(sp18);
        M2C_FIELD(temp_r30_3303, f64 *, 0x10) = M2C_BITWISE(f64, sp18);
        M2C_FIELD(temp_r30_3303, f64 *, 0x18) = (f64) sp18.unk8;
        if (GetTriVerts(arg0, *temp_r30_3303, &sp28) != 0) {
            GetInterpolatedColorFromPoly(sp8, (MKVector3 *) temp_r30_3303);
            M2C_FIELD(temp_r30_3303, f64 *, 0x20) = M2C_BITWISE(f64, sp8);
            M2C_FIELD(temp_r30_3303, f64 *, 0x28) = (f64) sp8.unk8;
        }
        var_r29_3299 += 1;
        var_r31_3300 += 0x58;
        goto loop_4;
    }
    return arg1;
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKCollisionMode'
u8 UpdateBestResult(MKCollisionModel *arg0, bool arg1, const MKCollisionResult &arg2, MKCollisionResult *arg3, MKCollisionModel *&arg4, int arg5, MKCollisionMode arg6, int arg7) {
    f32 temp_f2_3358;

    if (arg1 != 0) {
        temp_f2_3358 = arg2.unk40;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (temp_f2_3358 == arg3->unk40) {
            M2C_FIELD(arg3, f64 *, 0) = (f64) M2C_FIELD(&arg2, f64 *, 0);
            M2C_FIELD(arg3, f64 *, 8) = (f64) M2C_FIELD(&arg2, f64 *, 8);
            M2C_FIELD(arg3, f64 *, 0x10) = (f64) M2C_FIELD(&arg2, f64 *, 0x10);
            M2C_FIELD(arg3, f64 *, 0x18) = (f64) M2C_FIELD(&arg2, f64 *, 0x18);
            M2C_FIELD(arg3, f64 *, 0x20) = (f64) M2C_FIELD(&arg2, f64 *, 0x20);
            M2C_FIELD(arg3, f64 *, 0x28) = (f64) M2C_FIELD(&arg2, f64 *, 0x28);
            arg3->unk30 = arg2.unk30;
            arg3->unk34 = arg2.unk34;
            arg3->unk38 = arg2.unk38;
            arg3->unk3C = arg2.unk3C;
            arg3->unk40 = temp_f2_3358;
            arg3->unk44 = arg2.unk44;
            arg3->unk48 = arg2.unk48;
            arg3->unk4C = arg2.unk4C;
            arg3->unk50 = arg2.unk50;
            &arg4 = arg0;
            StoreItemInfo(arg3, arg5, arg6, arg7);
        }
    }
    return arg1;
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKCollisionMode'
void StoreItemInfo(MKCollisionResult *arg0, int arg1, MKCollisionMode arg2, int arg3) {
    if (arg0 != NULL) {
        M2C_FIELD(arg0, s16 *, 0x38) = (s16) arg1;
        M2C_FIELD(arg0, s8 *, 0x3B) = (s8) arg2;
        M2C_FIELD(arg0, s8 *, 0x3A) = (s8) arg3;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'InterpolateVertexColor'
void GetInterpolatedColorFromPoly(const MKVector3 &arg0, const MKVector3 *arg1) {
    MKVector4 sp8;
    MKVector3 *temp_r31_3426;

    temp_r31_3426 = M2C_ERROR(/* Read from unset register $r5 */);
    MKCollision_GetVertexColorFromPoly(temp_r31_3426, &sp8);
    InterpolateVertexColor(arg0, arg1, (MKVector4 *) temp_r31_3426);
}
#endif

#if 0 // DRAFT: undefined identifier 'sp148'
void InterpolateVertexColor(const MKVector3 &arg0, const MKVector3 *arg1, const MKVector4 *arg2) {
    f64 sp1D0;
    f64 sp1C8;
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
    f32 sp150;
    f32 sp140;
    f32 sp130;
    f32 sp12C;
    f32 sp128;
    f32 sp120;
    f32 sp110;
    f32 sp10C;
    f32 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f32 spC0;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f32 sp60;
    f32 sp50;
    f32 sp40;
    f32 temp_f0_3549;
    f32 temp_f1_3547;
    f32 temp_f29_3484;
    f32 temp_f2_3652;
    f32 temp_f30_3473;
    f32 temp_f6_3474;
    f32 var_f2_3528;
    f32 var_f3_3564;
    f32 var_f6_3641;

    M2C_ERROR(/* unknown instruction: psq_lx $f13, $r5, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f5, $zero, $r5, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f13, $f5 */);
    temp_f30_3473 = M2C_FIELD(arg2, f32 *, 0x18);
    temp_f6_3474 = arg2->unk8;
    sp1C8 = sp148;
    sp150 = temp_f30_3473 - temp_f6_3474;
    sp1D0 = (f64) sp150;
    M2C_ERROR(/* unknown instruction: psq_lx $f31, $r5, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f31, $f5 */);
    temp_f29_3484 = M2C_FIELD(arg2, f32 *, 0x28);
    sp1B8 = sp138;
    sp140 = temp_f29_3484 - temp_f6_3474;
    sp1C0 = (f64) sp140;
    sp12C = ((f32) sp1C0 * (f32) sp1C8) - ((f32) sp1B8 * (f32) sp1D0);
    sp128 = (unksp1BC * (f32) sp1D0) - ((f32) sp1C0 * unksp1CC);
    sp130 = ((f32) sp1B8 * unksp1CC) - (unksp1BC * (f32) sp1C8);
    sp1A8 = (f64) sp128;
    sp1B0 = (f64) sp130;
    M2C_ERROR(/* unknown instruction: psq_lx $f2, $zero, $r4, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f2, $f2, $f5 */);
    sp198 = sp118;
    sp120 = arg1->unk8 - temp_f6_3474;
    sp1A0 = (f64) sp120;
    var_f2_3528 = 0.0f;
    sp10C = ((f32) sp1A0 * (f32) sp1A8) - ((f32) sp198 * (f32) sp1B0);
    sp108 = (unksp19C * (f32) sp1B0) - ((f32) sp1A0 * unksp1AC);
    sp110 = ((f32) sp198 * unksp1AC) - (unksp19C * (f32) sp1A8);
    sp188 = (f64) sp108;
    sp190 = (f64) sp110;
    temp_f1_3547 = ((f32) sp190 * (f32) sp1D0) + (((f32) sp188 * (f32) sp1C8) + (unksp18C * unksp1CC));
    temp_f0_3549 = temp_f1_3547 - (((f32) sp190 * (f32) sp1C0) + (((f32) sp188 * (f32) sp1B8) + (unksp18C * unksp1BC)));
    if (temp_f0_3549 != 0.0f) {
        var_f2_3528 = temp_f1_3547 / temp_f0_3549;
    }
    if (var_f2_3528 < 1.0f) {

    } else {
        var_f2_3528 = 1.0f;
    }
    if (var_f2_3528 > 0.0f) {
        var_f3_3564 = var_f2_3528;
    } else {
        var_f3_3564 = 0.0f;
    }
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r6, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f2, $r6, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f0, $f2 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r6, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f7, $r6, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f0, $f7 */);
    spF8 = sp88;
    sp100 = sp90;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f3 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f3 */);
    spE8 = sp78;
    spF0 = sp80;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f7, $f0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f31, $f13 */);
    sp178 = sp68;
    sp180 = sp70;
    sp60 = temp_f29_3484 - temp_f30_3473;
    spD8 = sp58;
    spE0 = (f64) sp60;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f3 */);
    spC8 = sp48;
    sp50 = (f32) spE0 * var_f3_3564;
    spD0 = (f64) sp50;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f13, $f0 */);
    sp158 = sp38;
    sp40 = temp_f30_3473 + (f32) spD0;
    sp160 = (f64) sp40;
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f0, $f5 */);
    sp168 = spB8;
    var_f6_3641 = 0.0f;
    spC0 = (f32) sp160 - temp_f6_3474;
    sp170 = (f64) spC0;
    temp_f2_3652 = ((f32) sp170 * (f32) sp170) + (((f32) sp168 * (f32) sp168) + (unksp16C * unksp16C));
    if (temp_f2_3652 != 0.0f) {
        var_f6_3641 = (((f32) sp170 * (f32) sp1A0) + (((f32) sp168 * (f32) sp198) + (unksp16C * unksp19C))) / temp_f2_3652;
    }
    if (var_f6_3641 < 1.0f) {

    } else {
        var_f6_3641 = 1.0f;
    }
    if (var_f6_3641 > 0.0f) {

    }
    M2C_ERROR(/* unknown instruction: psq_lx $f2, $zero, $r6, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f0, $f2 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f3, $r6, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f0, $f3 */);
    spA8 = sp28;
    spB0 = sp30;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f4 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f4 */);
    sp98 = sp18;
    spA0 = sp20;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f3, $f0 */);
    M2C_FIELD(&arg0, f64 *, 0) = sp8;
    M2C_FIELD(&arg0, f64 *, 8) = sp10;
}
#endif
