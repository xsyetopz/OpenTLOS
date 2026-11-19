#include "spyro/source/KDPath.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include <m2c_macros.h>

M2C_UNK free(KDPathManager *);                      /* extern */
KDPathManager *malloc(s32);                         /* extern */
static MKVector3 waypointLoadInfo[0x40];

#if 0 // DRAFT: pointer/array required
void KDPathManager::NearestPointLocalSegment(int arg0, const MKVector3 &arg1) {
    KDPathIterator sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    KDPathSegment *var_r28_116;
    Matrix *var_r30_119;
    f32 temp_f10_142;
    f32 temp_f29_185;
    f32 temp_f30_115;
    f32 temp_f5_139;
    f32 temp_f8_140;
    f32 var_f31_101;
    s32 var_r29_126;
    void *temp_r3_137;

    var_f31_101 = 3.4028235e38f;
    sp48.Init();
    sp48.SetTo(arg0->GetPathList(M2C_ERROR(/* Read from unset register $r4 */)), 0);
    temp_f30_115 = arg1.unk8;
    var_r28_116 = arg0->GetPathList(M2C_ERROR(/* Read from unset register $r4 */));
loop_10:
    if (var_r28_116 != NULL) {
        var_r30_119 = var_r28_116->unk30;
        if (var_r30_119 != NULL) {

        } else {
            var_r30_119 = &identity;
        }
        var_r29_126 = 0;
loop_8:
        if (var_r29_126 < (s32) var_r28_116->unk20) {
            temp_r3_137 = var_r28_116->unk24 + (var_r29_126 * var_r28_116->unk1C);
            temp_f5_139 = M2C_FIELD(temp_r3_137, f32 *, 4);
            temp_f8_140 = M2C_FIELD(temp_r3_137, f32 *, 0);
            temp_f10_142 = M2C_FIELD(temp_r3_137, f32 *, 8);
            sp18 = var_r30_119->unk30 + ((temp_f10_142 * var_r30_119->unk20) + ((temp_f8_140 * var_r30_119->unk0) + (temp_f5_139 * var_r30_119->unk10)));
            sp1C = var_r30_119->unk34 + ((temp_f10_142 * var_r30_119->unk24) + ((temp_f8_140 * var_r30_119->unk4) + (temp_f5_139 * var_r30_119->unk14)));
            sp20 = var_r30_119->unk38 + ((temp_f10_142 * var_r30_119->unk28) + ((temp_f8_140 * var_r30_119->unk8) + (temp_f5_139 * var_r30_119->unk18)));
            sp28 = (f64) sp18;
            sp30 = (f64) sp20;
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r26, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            sp38 = sp8;
            sp10 = (f32) sp30 - temp_f30_115;
            sp40 = (f64) sp10;
            temp_f29_185 = ((f32) sp40 * (f32) sp40) + (((f32) sp38 * (f32) sp38) + (unksp3C * unksp3C));
            if (temp_f29_185 < var_f31_101) {
                sp48.SetTo(var_r28_116, var_r29_126);
                var_f31_101 = temp_f29_185;
            }
            var_r29_126 += 1;
            goto loop_8;
        }
        var_r28_116 = var_r28_116->unk28;
        goto loop_10;
    }
    this->unk0 = (KDPathManager *) sp48;
    this->unk4 = sp48.unk4;
    this->unk8 = M2C_BITWISE(f32, sp48.unk8);
}
#endif

#if 0 // DRAFT: pointer/array required
void KDPathManager::NearestPoint(int arg0, const MKVector3 &arg1) {
    KDPathIterator sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    KDPathSegment *var_r30_250;
    f32 temp_f30_278;
    f32 temp_f31_249;
    f32 var_f29_235;
    s32 var_r31_253;

    var_f29_235 = 1e11f;
    sp28.Init();
    sp28.SetTo(arg0->GetPathList(M2C_ERROR(/* Read from unset register $r4 */)), 0);
    temp_f31_249 = arg1.unk8;
    var_r30_250 = arg0->GetPathList(M2C_ERROR(/* Read from unset register $r4 */));
loop_7:
    if (var_r30_250 != NULL) {
        var_r31_253 = 0;
loop_5:
        if (var_r31_253 < (s32) var_r30_250->unk20) {
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r29, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            sp18 = sp8;
            sp10 = M2C_FIELD((var_r30_250->unk24 + (var_r31_253 * var_r30_250->unk1C)), f32 *, 8) - temp_f31_249;
            sp20 = (f64) sp10;
            temp_f30_278 = ((f32) sp20 * (f32) sp20) + (((f32) sp18 * (f32) sp18) + (unksp1C * unksp1C));
            if (temp_f30_278 < var_f29_235) {
                sp28.SetTo(var_r30_250, var_r31_253);
                var_f29_235 = temp_f30_278;
            }
            var_r31_253 += 1;
            goto loop_5;
        }
        var_r30_250 = var_r30_250->unk28;
        goto loop_7;
    }
    this->unk0 = (KDPathManager *) sp28;
    this->unk4 = sp28.unk4;
    this->unk8 = M2C_BITWISE(f32, sp28.unk8);
}
#endif

#if 0 // DRAFT: expression syntax error
KDPathSegment *KDPathManager::GetPathList(int arg0) {
    return *(pPathLists.unk0 + ((s32) this * 4));
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void KDPathManager::RemovePath(KDPathSegment *arg0) {
    KDPathNode *temp_r3_335;
    KDPathNode *temp_r3_351;
    s32 temp_r3_344;

    KDPathNode::Unlink();
    this->unk8.Unlink();
    temp_r3_335 = this->unk2C;
    if (temp_r3_335 != NULL) {
        temp_r3_335->unk28 = this->unk28;
    } else {
        temp_r3_344 = this->unk18 * 4;
        if ((u32) *(pPathLists.unk0 + temp_r3_344) == this) {
            *(pPathLists.unk0 + temp_r3_344) = this->unk28;
        }
    }
    temp_r3_351 = this->unk28;
    if (temp_r3_351 != NULL) {
        temp_r3_351->unk2C = this->unk2C;
    }
    this->unk2C = NULL;
    this->unk28 = NULL;
}
#endif

#if 0 // DRAFT: expression syntax error
void KDPathManager::AddPath(KDPathSegment *arg0) {
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
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
    f32 sp30;
    f32 sp20;
    f32 sp10;
    KDPathNode **var_r3_382;
    KDPathNode *var_r31_383;
    KDPathNode *var_r4_379;

    var_r4_379 = NULL;
    var_r3_382 = pPathLists.unk0 + (this->unk18 * 4);
    var_r31_383 = *var_r3_382;
loop_10:
    if (var_r31_383 != NULL) {
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        spA8 = sp38;
        sp40 = M2C_FIELD(this->unk24, f32 *, 8) - M2C_FIELD(var_r31_383->unk24, f32 *, 8);
        spB8 = sp38;
        spB0 = (f64) sp40;
        spC0 = (f64) sp40;
        if ((((f32) spB0 * (f32) spB0) + (((f32) spA8 * (f32) spA8) + (unkspAC * unkspAC))) < 10000.0f) {
            KDPathNode::Link(var_r31_383);
        }
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r5, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp88 = sp28;
        sp30 = M2C_FIELD(this->unk24, f32 *, 8) - M2C_FIELD((var_r31_383->unk24 + ((var_r31_383->unk20 - 1) * var_r31_383->unk1C)), f32 *, 8);
        sp90 = (f64) sp30;
        sp98 = sp28;
        spA0 = (f64) sp30;
        if ((((f32) sp90 * (f32) sp90) + (((f32) sp88 * (f32) sp88) + (unksp8C * unksp8C))) < 10000.0f) {
            KDPathNode::Link((KDPathNode *) &var_r31_383->unk8);
        }
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp68 = sp18;
        sp20 = M2C_FIELD((this->unk24 + ((this->unk20 - 1) * this->unk1C)), f32 *, 8) - M2C_FIELD(var_r31_383->unk24, f32 *, 8);
        sp70 = (f64) sp20;
        sp78 = sp18;
        sp80 = (f64) sp20;
        if ((((f32) sp70 * (f32) sp70) + (((f32) sp68 * (f32) sp68) + (unksp6C * unksp6C))) < 10000.0f) {
            this->unk8.Link(var_r31_383);
        }
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp48 = sp8;
        sp10 = M2C_FIELD((this->unk24 + ((this->unk20 - 1) * this->unk1C)), f32 *, 8) - M2C_FIELD((var_r31_383->unk24 + ((var_r31_383->unk20 - 1) * var_r31_383->unk1C)), f32 *, 8);
        sp58 = sp8;
        sp50 = (f64) sp10;
        sp60 = (f64) sp10;
        if ((((f32) sp50 * (f32) sp50) + (((f32) sp48 * (f32) sp48) + (unksp4C * unksp4C))) < 10000.0f) {
            this->unk8.Link((KDPathNode *) &var_r31_383->unk8);
        }
        var_r4_379 = var_r31_383;
        var_r3_382 = &var_r31_383->unk28;
        var_r31_383 = var_r31_383->unk28;
        goto loop_10;
    }
    this->unk2C = var_r4_379;
    *var_r3_382 = (KDPathNode *) this;
}
#endif

#if 0 // DRAFT: expression syntax error
void KDPathManager::Deinit() {
    KDPathManager *temp_r31_550;
    MKHeap *temp_r3_553;

    temp_r31_550 = pPathLists.unk0;
    if (temp_r31_550 != NULL) {
        temp_r3_553 = MKHeap::Current();
        if (temp_r3_553 != NULL) {
            ((MKHeap *) (temp_r3_553->Current()))->Free(temp_r31_550, NULL, 0);
        } else {
            free(temp_r31_550);
        }
    }
    pPathLists.unk0 = NULL;
    numTypes.unk0 = NULL;
}
#endif

#if 0 // DRAFT: expression syntax error
void KDPathManager::Init(int arg0) {
    KDPathManager *var_r3_592;
    MKHeap *temp_r3_585;
    s32 temp_r31_583;
    s32 var_r3_603;
    void *temp_r4_601;
    void *var_ctr_604;

    temp_r31_583 = (s32) this * 4;
    numTypes.unk0 = this;
    temp_r3_585 = MKHeap::Current();
    if (temp_r3_585 != NULL) {
        var_r3_592 = ((MKHeap *) (temp_r3_585->Current()))->Alloc(temp_r31_583, NULL, 0);
    } else {
        var_r3_592 = malloc(temp_r31_583);
    }
    pPathLists.unk0 = var_r3_592;
    temp_r4_601 = numTypes.unk0 - 1;
    var_r3_603 = (s32) temp_r4_601 * 4;
    var_ctr_604 = temp_r4_601 + 1;
    if (temp_r4_601 >= 0) {
        do {
            *(pPathLists.unk0 + var_r3_603) = 0;
            var_r3_603 -= 4;
            var_ctr_604 -= 1;
        } while (var_ctr_604 != NULL);
    }
}
#endif

void KDPathIterator::SetTo(KDPathSegment *arg0, int arg1) {
    this->unk0 = arg0;
    this->unk4 = arg1;
}

void KDPathIterator::Init() {
    this->unk8 |= 0x80;
    this->unk8 |= 0x40;
    this->unk8 &= ~0x20;
    this->unk8 &= ~0x10;
    this->unk0 = NULL;
    this->unk4 = 0;
}

#if 0 // DRAFT: undefined identifier 'AddPath'
void KDSplinePathSegmentProp::LoadDone() {
    MKProp::LoadDone();
    this->unk4C.LoadDone();
    this->unk4C.AddPath(M2C_ERROR(/* Read from unset register $r4 */));
}
#endif

#if 0 // DRAFT: undefined identifier 'RemovePath'
void KDSplinePathSegmentProp::Deinit() {
    MKProp::Deinit();
    this->unk4C.RemovePath(M2C_ERROR(/* Read from unset register $r4 */));
    this->unk4C.Deinit();
}
#endif

void KDSplinePathSegmentProp::Init() {
    MKProp::Init();
    this->unk4C.Init();
}

#if 0 // DRAFT: illegal type
void KDPathSegment::GetPositionAlongPath(float arg0, MKVector3 &arg1) {
    f64 sp40;                                       /* compiler-managed */
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp10;
    f32 temp_f1_760;
    f32 temp_f4_743;
    f32 temp_f6_747;
    f32 temp_f7_718;
    f32 var_f2_712;
    s32 temp_r5_714;
    s32 var_ctr_719;
    s32 var_r8_711;
    void *temp_r5_725;
    void *temp_r6_713;
    void *var_r7_716;

    var_r8_711 = 1;
    var_f2_712 = 0.0f;
    temp_r6_713 = this->unk24;
    temp_r5_714 = this->unk20;
    var_r7_716 = temp_r6_713;
    temp_f7_718 = arg0 * M2C_FIELD(temp_r6_713, f32 *, 0xC);
    var_ctr_719 = temp_r5_714 - 1;
    if (temp_r5_714 > 1) {
loop_1:
        temp_r5_725 = temp_r6_713 + (var_r8_711 * this->unk1C);
        var_r7_716 = temp_r5_725;
        var_f2_712 += M2C_FIELD(temp_r5_725, f32 *, 0xC);
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (var_f2_712 != temp_f7_718) {
            var_r8_711 += 1;
            var_ctr_719 -= 1;
            if (var_ctr_719 != 0) {
                goto loop_1;
            }
        }
    }
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r7, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f5, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f0, $f5 */);
    temp_f4_743 = M2C_FIELD(var_r7_716, f32 *, 0xC);
    temp_f6_747 = M2C_FIELD((temp_r6_713 + ((var_r8_711 - 1) * this->unk1C)), f32 *, 8);
    sp38 = sp18;
    sp20 = M2C_FIELD(var_r7_716, f32 *, 8) - temp_f6_747;
    sp40 = (f64) sp20;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f3 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f5, $f0 */);
    temp_f1_760 = (f32) sp40 * ((temp_f7_718 - (var_f2_712 - temp_f4_743)) / temp_f4_743);
    sp40 = temp_f1_760;
    sp10 = temp_f6_747 + temp_f1_760;
    M2C_FIELD(&arg1, f64 *, 0) = sp8;
    sp28 = sp8;
    sp30 = (f64) sp10;
    M2C_FIELD(&arg1, f64 *, 8) = (f64) sp10;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void KDSplinePathSegment::LoadDone() {
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp18;
    f32 sp8;
    MKVector3 *temp_r4_977;
    MKVector3 *temp_r5_887;
    f32 var_f5_912;
    f64 temp_f1_915;
    f64 temp_f1_921;
    f64 temp_f1_925;
    s32 temp_r3_816;
    s32 temp_r3_944;
    s32 temp_r3_978;
    s32 temp_r4_783;
    s32 temp_r4_836;
    s32 temp_r4_885;
    s32 var_r0_954;
    s32 var_r28_805;
    s32 var_r30_807;
    s32 var_r6_880;
    void *temp_r4_891;
    void *temp_r5_839;

    temp_r4_783 = this->unk20;
    if (temp_r4_783 > 0) {
        if ((u32) this->unk30.unkC == 0U) {
            if (((u8) this->unk44 != 0) && (temp_r4_783 >= 3)) {
                this->unk30.Init(temp_r4_783 + 1, 1U);
            } else {
                this->unk30.Init(temp_r4_783, 1U);
            }
            var_r28_805 = 0;
            var_r30_807 = 0;
loop_8:
            temp_r3_816 = this->unk20;
            if (var_r28_805 < temp_r3_816) {
                this->unk30.AddNode(*(waypointLoadInfo + var_r30_807));
                var_r28_805 += 1;
                var_r30_807 += 0x10;
                goto loop_8;
            }
            if (((u8) this->unk44 != 0) && (temp_r3_816 >= 3)) {
                this->unk30.AddNode(*waypointLoadInfo);
                this->unk20 += 1;
            }
            this->unk24 = (MKVector3 *) this->unk30.unkC;
        }
        temp_r4_836 = this->unk30.unkC;
        temp_r5_839 = temp_r4_836 + ((this->unk30.unk0 - 1) << 5);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r5, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp30 = sp10;
        sp18 = M2C_FIELD(temp_r4_836, f32 *, 8) - M2C_FIELD(temp_r5_839, f32 *, 8);
        sp38 = (f64) sp18;
        sp40 = sp10;
        sp48 = (f64) sp18;
        if ((((f32) sp38 * (f32) sp38) + (((f32) sp30 * (f32) sp30) + (unksp34 * unksp34))) < 10000.0f) {
            M2C_FIELD(temp_r5_839, f32 *, 0) = (f32) M2C_FIELD(temp_r4_836, f32 *, 0);
            M2C_FIELD(temp_r5_839, f32 *, 4) = (f32) M2C_FIELD(temp_r4_836, f32 *, 4);
            M2C_FIELD(temp_r5_839, f32 *, 8) = (f32) M2C_FIELD(temp_r4_836, f32 *, 8);
            this->unk30.MergeEnds();
            this->unk45 = 1;
        } else {
            this->unk45 = 0;
        }
        var_r6_880 = 1;
        this->unk24->unkC = 0.0f;
loop_35:
        if (var_r6_880 < (s32) this->unk20) {
            temp_r4_885 = this->unk1C;
            temp_r5_887 = this->unk24;
            temp_r4_891 = temp_r5_887 + (var_r6_880 * temp_r4_885);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            sp50 = sp20;
            sp28 = M2C_FIELD(temp_r4_891, f32 *, 8) - M2C_FIELD((temp_r5_887 + ((var_r6_880 - 1) * temp_r4_885)), f32 *, 8);
            sp58 = (f64) sp28;
            unksp5C = 0.0f;
            var_f5_912 = ((f32) sp58 * (f32) sp58) + (((f32) sp50 * (f32) sp50) + (unksp54 * unksp54));
            if (var_f5_912 > 0.0f) {
                temp_f1_915 = __frsqrte(var_f5_912);
                temp_f1_921 = 0.5 * temp_f1_915 * -(((f64) var_f5_912 * (temp_f1_915 * temp_f1_915)) - 3.0);
                temp_f1_925 = 0.5 * temp_f1_921 * -(((f64) var_f5_912 * (temp_f1_921 * temp_f1_921)) - 3.0);
                var_f5_912 = (f32) ((f64) var_f5_912 * (0.5 * temp_f1_925 * -(((f64) var_f5_912 * (temp_f1_925 * temp_f1_925)) - 3.0)));
            } else if (var_f5_912 < M2C_BITWISE(f32, 0.0)) {
                var_f5_912 = __float_nan;
            } else {
                sp8 = var_f5_912;
                temp_r3_944 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_944) {              /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_954 = 1;
                    } else {
                        var_r0_954 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_954 = 5;
                    } else {
                        var_r0_954 = 3;
                    }
                    break;
                default:
                    var_r0_954 = 4;
                    break;
                }
                if (var_r0_954 == 1) {
                    var_f5_912 = __float_nan;
                }
            }
            M2C_FIELD(temp_r4_891, f32 *, 0xC) = var_f5_912;
            temp_r4_977 = this->unk24;
            temp_r3_978 = var_r6_880 * this->unk1C;
            var_r6_880 += 1;
            temp_r4_977->unkC += *(temp_r4_977 + (temp_r3_978 + 0xC));
            goto loop_35;
        }
    }
}
#endif

u8 KDSplinePathSegment::LoadWaypoints(MKIniLine *arg0, const char *arg1) {
    MKVector3 sp8;
    MKIniLine *var_r29_1039;
    s32 temp_r4_1014;

    if (arg0->IsField(arg1) != 0) {
        this->unk20 = arg0->GetNmbrOfSubLines();
        temp_r4_1014 = this->unk20;
        if (temp_r4_1014 == 0) {
            return 1U;
        }
        if (((u8) this->unk44 != 0) && (temp_r4_1014 >= 3)) {
            this->unk30.Init(temp_r4_1014 + 1, 1U);
        } else {
            this->unk30.Init(temp_r4_1014, 1U);
        }
        var_r29_1039 = arg0->unkC->GetSubLine(arg0);
loop_11:
        if (var_r29_1039 != NULL) {
            if (var_r29_1039->LoadVector3("waypoint", &sp8, 0) != 0) {
                this->unk30.AddNode(sp8);
            }
            var_r29_1039 = var_r29_1039->unkC->GetNextLine(var_r29_1039);
            goto loop_11;
        }
        if (((u8) this->unk44 != 0) && ((s32) this->unk20 >= 3)) {
            this->unk30.AddNode(*((MKVector3 *) this->unk30.unkC));
            this->unk20 += 1;
        }
        this->unk24 = (MKVector3 *) this->unk30.unkC;
        return 1U;
    }
    if (arg0->LoadVector3("waypoint", &waypointLoadInfo[this->unk20], 0) != 0) {
        this->unk20 += 1;
        return 1U;
    }
    return 0U;
}

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
u8 KDSplinePathSegment::LoadLine(MKIniLine *arg0, const char *arg1) {
    s32 sp8;

    sp8 = 0;
    if (arg0->LoadInt("type", &sp8, 0) != 0) {
        this->unk18 = (s16) sp8;
        return 1U;
    }
    return LoadWaypoints(arg0, arg1);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to
u8 KDSplinePathSegment::LoadLine(MKIniLine *arg0) {
    u8 var_r31_1156;

    var_r31_1156 = 0;
    if ((LoadLine(arg0, "waypoints") != 0) || (arg0->LoadBool("bForceLoop", (u8 *) &this->unk44, 0) != 0)) {
        var_r31_1156 = 1;
    }
    return var_r31_1156;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void KDSplinePathSegment::Deinit() {
    this->unk30.Deinit();
    this->unk24 = NULL;
    KDPathSegment::Deinit();
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void KDSplinePathSegment::Init() {
    KDPathSegment::Init();
    this->unk30.Init(0, 0U);
    this->unk44 = 0;
    this->unk45 = 0;
    this->unk1C = 0x20;
    this->unk1A = 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk34'
void KDLocalPathSegmentProp::Resolve() {
    MKSceneManager *temp_r3_1240;
    MKSceneManager *temp_r3_1245;
    f32 temp_f10_1283;
    f32 temp_f5_1280;
    f32 temp_f8_1281;
    s32 temp_r0_1264;
    s32 temp_r3_1311;
    s32 var_ctr_1266;
    s32 var_r5_1265;
    void *temp_r3_1278;
    MKProp::Resolve();
    temp_r3_1240 = this->unk4C.unk34;
    if (temp_r3_1240 != NULL) {
        this->unk4C.unk34 = temp_r3_1240->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */));
        temp_r3_1245 = this->unk4C.unk34;
        if (temp_r3_1245 != NULL) {
            this->unk4C.unk2C = M2C_BITWISE(s32, temp_r3_1245->unk8);
            M2C_STRUCT_COPY((s32) &arg_sp2C + 4, this->unk4C.unk2C - 4 + 4, 0x40);
            arg_sp30.Inverse((Matrix *) &arg_sp30);
            temp_r0_1264 = this->unk4C.unk1C;
            var_r5_1265 = 0;
            var_ctr_1266 = temp_r0_1264;
            if (temp_r0_1264 > 0) {
                do {
                    temp_r3_1278 = this->unk4C.unk20 + (var_r5_1265 * M2C_FIELD(this, s32 *, 0x68));
                    temp_f5_1280 = M2C_FIELD(temp_r3_1278, f32 *, 4);
                    temp_f8_1281 = M2C_FIELD(temp_r3_1278, f32 *, 0);
                    temp_f10_1283 = M2C_FIELD(temp_r3_1278, f32 *, 8);
                    arg_sp10 = arg_sp60 + ((temp_f10_1283 * arg_sp50) + ((temp_f8_1281 * arg_sp30) + (temp_f5_1280 * arg_sp40)));
                    arg_sp14 = arg_sp64 + ((temp_f10_1283 * arg_sp54) + ((temp_f8_1281 * arg_sp34) + (temp_f5_1280 * arg_sp44)));
                    arg_sp18 = arg_sp68 + ((temp_f10_1283 * arg_sp58) + ((temp_f8_1281 * arg_sp38) + (temp_f5_1280 * arg_sp48)));
                    M2C_FIELD(temp_r3_1278, f32 *, 0) = (f64) arg_sp10;
                    M2C_FIELD(temp_r3_1278, f32 *, 8) = (f64) arg_sp18;
                    temp_r3_1311 = var_r5_1265 * M2C_FIELD(this, s32 *, 0x68);
                    arg_sp20 = (f64) arg_sp10;
                    var_r5_1265 += 1;
                    arg_sp28 = (f64) arg_sp18;
                    *(this->unk4C.unk20 + (temp_r3_1311 + 0xC)) = M2C_FIELD(temp_r3_1278, f32 *, 0xC);
                    var_ctr_1266 -= 1;
                } while (var_ctr_1266 != 0);
            }
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'AddPath'
void KDLocalPathSegmentProp::LoadDone() {
    MKProp::LoadDone();
    this->unk4C.LoadDone();
    this->unk4C.AddPath(M2C_ERROR(/* Read from unset register $r4 */));
}
#endif

#if 0 // DRAFT: undefined identifier 'unk34'
s32 KDLocalPathSegmentProp::LoadLine(MKIniLine *arg0) {
    s32 var_r31_1356;

    var_r31_1356 = 0;
    if ((MKProp::LoadLine(arg0) != 0) || (this->unk4C.LoadLine(arg0) != 0) || (arg0->LoadInt("parentID", (s32 *) &this->unk4C.unk34, 0) != 0)) {
        var_r31_1356 = 1;
    }
    return var_r31_1356;
}
#endif

#if 0 // DRAFT: undefined identifier 'RemovePath'
void KDLocalPathSegmentProp::Deinit() {
    MKProp::Deinit();
    this->unk4C.RemovePath(M2C_ERROR(/* Read from unset register $r4 */));
    this->unk4C.Deinit();
    this->unk4C.unk34 = NULL;
}
#endif

#if 0 // DRAFT: function call 'Init(KDLocalPathSegmentProp *, KDLocalPathSegmentProp *)'
void KDLocalPathSegmentProp::Init() {
    MKProp::Init();
    this->unk4C.Init(this);
    this->unk4C.unk34 = NULL;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void KDLocalPathSegment::Init(KDLocalPathSegmentProp *arg0) {
    KDPathSegment::Init();
    this->unk30 = NULL;
    this->unk1A = 2;
    this->unk34 = arg0;
}
#endif

#if 0 // DRAFT: undefined identifier 'AddPath'
void KDPathSegmentProp::LoadDone() {
    MKProp::LoadDone();
    this->unk4C.LoadDone();
    this->unk4C.AddPath(M2C_ERROR(/* Read from unset register $r4 */));
}
#endif

#if 0 // DRAFT: undefined identifier 'RemovePath'
void KDPathSegmentProp::Deinit() {
    MKProp::Deinit();
    this->unk4C.RemovePath(M2C_ERROR(/* Read from unset register $r4 */));
    this->unk4C.Deinit();
}
#endif

void KDPathSegmentProp::Init() {
    MKProp::Init();
    this->unk4C.Init();
}

#if 0 // DRAFT: illegal type
void *KDPathSegment::GetNearestPointXZ(const MKVector3 &arg0) {
    f32 temp_f0_1532;
    f32 temp_f1_1529;
    f32 temp_f4_1528;
    f32 var_f5_1513;
    s32 temp_r0_1511;
    s32 var_ctr_1517;
    s32 var_r6_1514;
    void *temp_r4_1525;
    void *var_r5_1512;

    temp_r0_1511 = this->unk20;
    var_r5_1512 = NULL;
    var_f5_1513 = 3.4028235e38f;
    var_r6_1514 = 0;
    var_ctr_1517 = temp_r0_1511;
    if (temp_r0_1511 > 0) {
        do {
            temp_r4_1525 = this->unk24 + (var_r6_1514 * this->unk1C);
            temp_f4_1528 = arg0.unk8 - M2C_FIELD(temp_r4_1525, f32 *, 8);
            temp_f1_1529 = arg0.unk0 - M2C_FIELD(temp_r4_1525, f32 *, 0);
            temp_f0_1532 = (temp_f1_1529 * temp_f1_1529) + (temp_f4_1528 * temp_f4_1528);
            if ((var_r5_1512 == NULL) || (temp_f0_1532 < var_f5_1513)) {
                var_r5_1512 = temp_r4_1525;
                var_f5_1513 = temp_f0_1532;
            }
            var_r6_1514 += 1;
            var_ctr_1517 -= 1;
        } while (var_ctr_1517 != 0);
    }
    return var_r5_1512;
}
#endif

#if 0 // DRAFT: illegal type
s32 KDPathSegment::GetIndexOf(KDPathPoint *arg0) const {
    return (s32) (arg0 - this->unk24) / (s32) this->unk1C;
}
#endif

void KDPathSegment::Resolve() {

}

#if 0 // DRAFT: pointer/array required
void KDPathSegment::LoadDone() {
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp8;
    KDPathManager *var_r3_1586;
    MKHeap *temp_r3_1579;
    f32 var_f5_1633;
    f64 temp_f1_1636;
    f64 temp_f1_1642;
    f64 temp_f1_1646;
    s32 temp_r30_1578;
    s32 temp_r3_1571;
    s32 temp_r3_1665;
    s32 temp_r3_1699;
    s32 temp_r4_1606;
    s32 var_r0_1675;
    s32 var_r6_1601;
    void *temp_r4_1612;
    void *temp_r4_1698;
    void *temp_r5_1608;

    temp_r3_1571 = this->unk20;
    if (temp_r3_1571 > 0) {
        if ((void *) this->unk24 == NULL) {
            temp_r30_1578 = temp_r3_1571 * this->unk1C;
            temp_r3_1579 = temp_r3_1571->Current();
            if (temp_r3_1579 != NULL) {
                var_r3_1586 = ((MKHeap *) (temp_r3_1579->Current()))->Alloc(temp_r30_1578, NULL, 0);
            } else {
                var_r3_1586 = malloc(temp_r30_1578);
            }
            this->unk24 = var_r3_1586;
            memcpy(this->unk24, waypointLoadInfo, this->unk20 * 0x10);
        }
        var_r6_1601 = 1;
        M2C_FIELD(this->unk24, f32 *, 0xC) = 0.0f;
loop_25:
        if (var_r6_1601 < (s32) this->unk20) {
            temp_r4_1606 = this->unk1C;
            temp_r5_1608 = this->unk24;
            temp_r4_1612 = temp_r5_1608 + (var_r6_1601 * temp_r4_1606);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            sp20 = sp10;
            sp18 = M2C_FIELD(temp_r4_1612, f32 *, 8) - M2C_FIELD((temp_r5_1608 + ((var_r6_1601 - 1) * temp_r4_1606)), f32 *, 8);
            sp28 = (f64) sp18;
            unksp2C = 0.0f;
            var_f5_1633 = ((f32) sp28 * (f32) sp28) + (((f32) sp20 * (f32) sp20) + (unksp24 * unksp24));
            if (var_f5_1633 > 0.0f) {
                temp_f1_1636 = __frsqrte(var_f5_1633);
                temp_f1_1642 = 0.5 * temp_f1_1636 * -(((f64) var_f5_1633 * (temp_f1_1636 * temp_f1_1636)) - 3.0);
                temp_f1_1646 = 0.5 * temp_f1_1642 * -(((f64) var_f5_1633 * (temp_f1_1642 * temp_f1_1642)) - 3.0);
                var_f5_1633 = (f32) ((f64) var_f5_1633 * (0.5 * temp_f1_1646 * -(((f64) var_f5_1633 * (temp_f1_1646 * temp_f1_1646)) - 3.0)));
            } else if (var_f5_1633 < M2C_BITWISE(f32, 0.0)) {
                var_f5_1633 = __float_nan;
            } else {
                sp8 = var_f5_1633;
                temp_r3_1665 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_1665) {             /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_1675 = 1;
                    } else {
                        var_r0_1675 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_1675 = 5;
                    } else {
                        var_r0_1675 = 3;
                    }
                    break;
                default:
                    var_r0_1675 = 4;
                    break;
                }
                if (var_r0_1675 == 1) {
                    var_f5_1633 = __float_nan;
                }
            }
            M2C_FIELD(temp_r4_1612, f32 *, 0xC) = var_f5_1633;
            temp_r4_1698 = this->unk24;
            temp_r3_1699 = var_r6_1601 * this->unk1C;
            var_r6_1601 += 1;
            M2C_FIELD(temp_r4_1698, f32 *, 0xC) = (f32) (M2C_FIELD(temp_r4_1698, f32 *, 0xC) + *(temp_r4_1698 + (temp_r3_1699 + 0xC)));
            goto loop_25;
        }
    }
}
#endif

#if 0 // DRAFT: pointer/array required
void KDPathSegment::CopyWaypointArray(MKVector3 *arg0, int arg1) {
    KDPathManager *var_r3_1738;
    MKHeap *temp_r3_1731;
    s32 temp_r0_1753;
    s32 temp_r31_1730;
    s32 temp_r3_1728;
    s32 var_r3_1746;
    s32 var_r6_1745;
    void *temp_r4_1750;
    void *temp_r4_1757;

    this->unk20 = arg1;
    temp_r3_1728 = this->unk20;
    temp_r31_1730 = temp_r3_1728 * this->unk1C;
    temp_r3_1731 = temp_r3_1728->Current();
    if (temp_r3_1731 != NULL) {
        var_r3_1738 = ((MKHeap *) (temp_r3_1731->Current()))->Alloc(temp_r31_1730, NULL, 0);
    } else {
        var_r3_1738 = malloc(temp_r31_1730);
    }
    this->unk24 = var_r3_1738;
    var_r6_1745 = 0;
    var_r3_1746 = 0;
loop_5:
    if (var_r6_1745 < (s32) this->unk20) {
        temp_r4_1750 = arg0 + var_r3_1746;
        var_r3_1746 += 0x10;
        temp_r0_1753 = var_r6_1745 * this->unk1C;
        var_r6_1745 += 1;
        temp_r4_1757 = this->unk24 + temp_r0_1753;
        M2C_FIELD(temp_r4_1757, f64 *, 0) = (f64) M2C_FIELD(temp_r4_1750, f64 *, 0);
        M2C_FIELD(temp_r4_1757, f64 *, 8) = (f64) M2C_FIELD(temp_r4_1750, f64 *, 8);
        goto loop_5;
    }
}
#endif

#if 0 // DRAFT: pointer/array required
u8 KDPathSegment::LoadWaypoints(MKIniLine *arg0, const char *arg1) {
    KDPathManager *var_r3_1803;
    MKHeap *temp_r3_1796;
    MKIniLine *var_r29_1815;
    s32 temp_r30_1795;
    s32 temp_r3_1788;
    s32 var_r28_1814;

    if (arg0->IsField(arg1) != 0) {
        this->unk20 = arg0->GetNmbrOfSubLines();
        temp_r3_1788 = this->unk20;
        if (temp_r3_1788 == 0) {
            return 1U;
        }
        temp_r30_1795 = temp_r3_1788 * this->unk1C;
        temp_r3_1796 = temp_r3_1788->Current();
        if (temp_r3_1796 != NULL) {
            var_r3_1803 = ((MKHeap *) (temp_r3_1796->Current()))->Alloc(temp_r30_1795, NULL, 0);
        } else {
            var_r3_1803 = malloc(temp_r30_1795);
        }
        this->unk24 = var_r3_1803;
        var_r28_1814 = 0;
        var_r29_1815 = arg0->unkC->GetSubLine(arg0);
loop_10:
        if (var_r29_1815 != NULL) {
            if (var_r29_1815->LoadVector3("waypoint", this->unk24 + (var_r28_1814 * this->unk1C), 0) != 0) {
                var_r28_1814 += 1;
            }
            var_r29_1815 = var_r29_1815->unkC->GetNextLine(var_r29_1815);
            goto loop_10;
        }
        return 1U;
    }
    if (arg0->LoadVector3("waypoint", &waypointLoadInfo[this->unk20], 0) != 0) {
        this->unk20 += 1;
        return 1U;
    }
    return 0U;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
u8 KDPathSegment::LoadLine(MKIniLine *arg0) {
    s32 sp8;

    sp8 = 0;
    if (arg0->LoadInt("type", &sp8, 0) != 0) {
        this->unk18 = (s16) sp8;
        return 1U;
    }
    return LoadWaypoints(arg0, "waypoints");
}
#endif

void KDPathSegment::Deinit() {
    s32 sp10;
    s32 spC;
    s32 sp8;
    MKHeap *temp_r3_1933;
    MKHeap *var_r3_1915;
    s32 temp_r5_1922;
    void *temp_r31_1930;

    var_r3_1915 = this->unk10;
    if (var_r3_1915 != NULL) {
        spC = 0;
        temp_r5_1922 = this->unk14;
        sp8 = 0xA1;
        sp10 = temp_r5_1922;
        var_r3_1915 = M2C_FIELD(var_r3_1915->unk44, MKHeap *(**)(s32 *, s32), 0x2C)(&sp8, temp_r5_1922);
    }
    temp_r31_1930 = this->unk24;
    if (temp_r31_1930 != NULL) {
        temp_r3_1933 = var_r3_1915->Current();
        if (temp_r3_1933 != NULL) {
            ((MKHeap *) (temp_r3_1933->Current()))->Free(temp_r31_1930, NULL, 0);
        } else {
            free((KDPathManager *) temp_r31_1930);
        }
    }
    this->unk24 = NULL;
}

#if 0 // DRAFT: illegal use of non-static member
void KDPathSegment::Init() {
    this->unk18 = -1;
    this->unk1C = 0x10;
    this->unk20 = 0;
    this->unk1A = 0;
    this->unk24 = NULL;
    this->unk2C = 0;
    this->unk28 = NULL;
    this->unk10 = NULL;
    this->unk14 = 0;
    KDPathNode::Init(this, 1U);
    this->unk8.Init(this, 0U);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk8'
void KDPathNode::CountBranches() {
    KDPathNode *var_r0_2009;
    KDPathNode *var_r5_2026;
    KDPathNode *var_r9_1993;
    s8 var_r4_2033;
    s8 var_r7_1992;
    s8 var_r8_1994;
    u8 temp_r4_1996;

    var_r7_1992 = 0;
    var_r9_1993 = this;
    var_r8_1994 = 0;
    do {
        temp_r4_1996 = var_r9_1993->unk4;
        if (temp_r4_1996 != 0) {
            var_r7_1992 += 1;
        }
        if (temp_r4_1996 == 0) {
            var_r8_1994 += 1;
        }
        if (temp_r4_1996 != 0) {
            var_r0_2009 = var_r9_1993->unk0;
        } else {
            var_r0_2009 = (KDPathNode *) &var_r9_1993->unk0->unk8;
        }
        var_r9_1993 = var_r0_2009;
    } while (var_r0_2009 != this);
    do {
        if ((u8) var_r9_1993->unk4 != 0) {
            var_r5_2026 = var_r9_1993->unk0;
        } else {
            var_r5_2026 = (KDPathNode *) &var_r9_1993->unk0->unk8;
        }
        var_r5_2026->unk5 = var_r7_1992 + (var_r8_1994 - 1);
        var_r4_2033 = var_r7_1992;
        if ((u8) var_r9_1993->unk4 != 0) {
            var_r4_2033 = var_r8_1994;
        }
        var_r5_2026->unk6 = var_r4_2033;
        var_r9_1993 = var_r5_2026;
    } while (var_r5_2026 != this);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk8'
void KDPathNode::Unlink() {
    KDPathNode *var_r0_2067;
    KDPathNode *var_r0_2105;
    KDPathNode *var_r5_2049;
    KDPathNode *var_r5_2083;
    KDPathNode *var_r7_2076;
    u8 temp_r5_2102;
    u8 temp_r6_2064;

    var_r5_2049 = this;
loop_5:
    temp_r6_2064 = var_r5_2049->unk4;
    if (temp_r6_2064 != 0) {
        var_r0_2067 = var_r5_2049->unk0;
    } else {
        var_r0_2067 = (KDPathNode *) &var_r5_2049->unk0->unk8;
    }
    if (var_r0_2067 != this) {
        if (temp_r6_2064 != 0) {
            var_r5_2049 = var_r5_2049->unk0;
        } else {
            var_r5_2049 = (KDPathNode *) &var_r5_2049->unk0->unk8;
        }
        var_r5_2049->unk5 -= 1;
        goto loop_5;
    }
    var_r7_2076 = this;
loop_18:
    temp_r5_2102 = var_r7_2076->unk4;
    if (temp_r5_2102 != 0) {
        var_r0_2105 = var_r7_2076->unk0;
    } else {
        var_r0_2105 = (KDPathNode *) &var_r7_2076->unk0->unk8;
    }
    if (var_r0_2105 != this) {
        if (temp_r5_2102 != temp_r6_2064) {
            if (temp_r5_2102 != 0) {
                var_r5_2083 = var_r7_2076->unk0;
            } else {
                var_r5_2083 = (KDPathNode *) &var_r7_2076->unk0->unk8;
            }
            var_r5_2083->unk6 = (u8) var_r5_2083->unk6 - 1;
        }
        if ((u8) var_r7_2076->unk4 != 0) {
            var_r7_2076 = var_r7_2076->unk0;
        } else {
            var_r7_2076 = (KDPathNode *) &var_r7_2076->unk0->unk8;
        }
        goto loop_18;
    }
    var_r7_2076->unk0 = this->unk0;
    var_r7_2076->unk4 = this->unk4;
    this->unk0 = var_r5_2049->unk0;
    this->unk4 = temp_r6_2064;
    this->unk5 = 0;
    this->unk6 = 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk8'
void KDPathNode::Link(KDPathNode *arg0) {
    KDPathNode *temp_r4_2177;
    KDPathNode *var_r0_2152;
    KDPathNode *var_r7_2130;
    u8 temp_r6_2160;
    u8 var_r0_2139;
    u8 var_r0_2166;

    var_r7_2130 = arg0;
loop_9:
    temp_r6_2160 = var_r7_2130->unk4;
    if (temp_r6_2160 != 0) {
        var_r0_2166 = var_r7_2130->unk0 != arg0;
    } else {
        var_r0_2166 = &var_r7_2130->unk0->unk8 != arg0;
    }
    if (var_r0_2166 == 0) {
        temp_r4_2177 = var_r7_2130->unk0;
        var_r7_2130->unk0 = this->unk0;
        var_r7_2130->unk4 = this->unk4;
        this->unk0 = temp_r4_2177;
        this->unk4 = temp_r6_2160;
        CountBranches();
    } else {
        if (temp_r6_2160 != 0) {
            var_r0_2139 = var_r7_2130->unk0 == this;
        } else {
            var_r0_2139 = &var_r7_2130->unk0->unk8 == this;
        }
        if (var_r0_2139 == 0) {
            if (temp_r6_2160 != 0) {
                var_r0_2152 = var_r7_2130->unk0;
            } else {
                var_r0_2152 = (KDPathNode *) &var_r7_2130->unk0->unk8;
            }
            var_r7_2130 = var_r0_2152;
            goto loop_9;
        }
    }
}
#endif

void KDPathNode::Init(KDPathSegment *arg0, bool arg1) {
    this->unk0 = (KDPathNode *) arg0;
    this->unk4 = arg1;
    this->unk5 = 0;
    this->unk6 = 0;
    this->unk7 = 0x1A;
}
