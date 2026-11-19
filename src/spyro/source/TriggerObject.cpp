#include "spyro/source/TriggerObject.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKVector3.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

M2C_UNK free(f32);                                  /* extern */
void *malloc(s32);                                  /* extern */
s32 stricmp(s8 *);                                  /* extern */
extern M2C_UNK gEmptyPtrListDL;
extern void **gb;
#if 0 // DRAFT: undefined identifier 'unk44'
static TriggerBoxObject tempBoxRot__16TriggerBoxObject; /* type too large by 0xAC; unable to generate initializer: confusing struct layout */

s32 TriggerPolyObject::CheckTarget() {
    f64 sp10;
    f64 sp8;
    f32 temp_r3_32;
    s32 var_r31_47;
    void *temp_r3_46;
    void *var_r3_35;

    temp_r3_32 = this->unk10.unk44;
    if (M2C_BITWISE(s32, temp_r3_32) > 0) {
        var_r3_35 = ((MKSceneManager *) (M2C_BITWISE(MKSceneManager *, temp_r3_32)))->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */));
    } else {
        var_r3_35 = M2C_FIELD(*gb, void *(**)(void **), 0xC)(gb);
    }
    temp_r3_46 = M2C_FIELD(var_r3_35, void **, 8);
    var_r31_47 = 0;
    sp8 = M2C_FIELD(temp_r3_46, f64 *, 0x30);
    sp10 = M2C_FIELD(temp_r3_46, f64 *, 0x38);
    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
    if (unkspC == this->unkA4) {
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if ((unkspC == this->unkA8) && (this->unk10.unk78.IsPointWithin(*((MKVector3 *) &sp8)) != 0)) {
            var_r31_47 = 1;
        }
    }
    return var_r31_47;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk78'
s32 TriggerPolyObject::CheckPos(const MKVector3 &arg0) {
    f32 temp_f1_81;
    s32 var_r31_84;

    temp_f1_81 = arg0.unk4;
    var_r31_84 = 0;
    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
    if (temp_f1_81 == this->unkA4) {
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if ((temp_f1_81 == this->unkA8) && (this->unk10.unk78.IsPointWithin(arg0) != 0)) {
            var_r31_84 = 1;
        }
    }
    return var_r31_84;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk78'
void TriggerPolyObject::LoadDone() {
    f32 temp_f1_126;
    f32 temp_f1_134;
    s32 var_r3_120;
    s32 var_r5_119;

    this->unk10.unk78.Init(M2C_BITWISE(MKVector3 *, this->unk10.unk74), M2C_BITWISE(s32, this->unk10.unk70));
    var_r5_119 = 0;
    var_r3_120 = 0;
loop_6:
    if (var_r5_119 < M2C_BITWISE(s32, this->unk10.unk70)) {
        temp_f1_126 = *(M2C_BITWISE(s32, this->unk10.unk74) + (var_r3_120 + 4));
        if (temp_f1_126 < this->unkA4) {
            this->unkA4 = temp_f1_126;
        }
        temp_f1_134 = *(M2C_BITWISE(s32, this->unk10.unk74) + (var_r3_120 + 4));
        if (temp_f1_134 > this->unkA8) {
            this->unkA8 = temp_f1_134;
        }
        var_r5_119 += 1;
        var_r3_120 += 0x10;
        goto loop_6;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk70'
s32 TriggerPolyObject::LoadLine(char *arg0, MKIniLine *arg1) {
    MKHeap *temp_r3_174;
    MKIniLine *var_r28_192;
    s32 temp_r29_173;
    s32 temp_r3_170;
    s32 var_r30_194;
    void *var_r3_181;

    TriggerObject::LoadLine(arg1);
    if (arg1->IsField(arg0) != 0) {
        temp_r3_170 = arg1->GetNmbrOfSubLines();
        this->unk10.unk70 = M2C_BITWISE(f32, temp_r3_170);
        temp_r29_173 = M2C_BITWISE(s32, this->unk10.unk70) * 0x10;
        temp_r3_174 = temp_r3_170->Current();
        if (temp_r3_174 != NULL) {
            var_r3_181 = ((MKHeap *) (temp_r3_174->Current()))->Alloc(temp_r29_173, NULL, 0);
        } else {
            var_r3_181 = malloc(temp_r29_173);
        }
        this->unk10.unk74 = M2C_BITWISE(f32, var_r3_181);
        var_r28_192 = arg1->unkC->GetSubLine(arg1);
        var_r30_194 = 0;
loop_8:
        if (var_r28_192 != NULL) {
            if (var_r28_192->LoadVector3("waypoint", M2C_BITWISE(s32, this->unk10.unk74) + var_r30_194, 0) != 0) {
                var_r30_194 += 0x10;
            }
            var_r28_192 = var_r28_192->unkC->GetNextLine(var_r28_192);
            goto loop_8;
        }
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk74'
void TriggerPolyObject::Deinit() {
    MKHeap *temp_r3_234;
    f32 temp_r31_233;

    temp_r31_233 = this->unk10.unk74;
    temp_r3_234 = MKHeap::Current();
    if (temp_r3_234 != NULL) {
        ((MKHeap *) (temp_r3_234->Current()))->Free(M2C_BITWISE(void *, temp_r31_233), NULL, 0);
        return;
    }
    free(temp_r31_233);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk70'
void TriggerPolyObject::Init() {
    TriggerObject::Init();
    this->unk10.unk70 = 0.0f;
    this->unk10.unk74 = 0.0f;
    this->unkA4 = 9.99999e7f;
    this->unkA8 = -9.99999e7f;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk70'
s32 TriggerPlaneGroupObject::AddPlane(TriggerPlaneObject *arg0) {
    TriggerPlaneObject ***temp_r5_295;
    f32 var_r6_280;
    u32 *temp_r5_291;

    var_r6_280 = this->unk10.unk70;
loop_4:
    temp_r5_291 = *var_r6_280;
    if (temp_r5_291 == NULL) {
        temp_r5_295 = M2C_BITWISE(s32, this->unk10.unk70) - 4;
        this->unk10.unk70 = M2C_BITWISE(f32, temp_r5_295);
        **temp_r5_295 = arg0;
        this->unk10.unk44 = arg0->unk10.unk44;
        return 1;
    }
    if ((u32) *temp_r5_291 == arg0) {
        return 0;
    }
    var_r6_280 = M2C_BITWISE(f32, (M2C_BITWISE(s32, var_r6_280) + 4));
    goto loop_4;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk70'
s32 TriggerPlaneGroupObject::CheckTarget() {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKSceneManager *temp_r3_327;
    f32 temp_f1_377;
    f32 temp_r3_382;
    f32 temp_r3_392;
    f32 var_r30_313;
    u8 temp_r3_321;
    u8 temp_ret_321;
    void **temp_r3_418;
    void *temp_r29_316;
    void *temp_r3_341;
    void *var_r3_330;

    var_r30_313 = this->unk10.unk70;
loop_17:
    temp_r3_418 = *var_r30_313;
    if (temp_r3_418 != NULL) {
        temp_r29_316 = *temp_r3_418;
        temp_ret_321 = M2C_FIELD(M2C_FIELD(temp_r29_316, void **, 0), u8 (**)(void *), 0x34)(temp_r29_316);
        temp_r3_321 = temp_ret_321;
        if (temp_r3_321 != (u8) M2C_FIELD(temp_r29_316, u8 *, 0xC0)) {
            temp_r3_327 = M2C_FIELD(temp_r29_316, MKSceneManager **, 0x54);
            if (temp_r3_327 > 0) {
                var_r3_330 = temp_r3_327->PropResolver_Resolve((s32) (u32) (u64) temp_ret_321);
            } else {
                var_r3_330 = M2C_FIELD(*gb, void *(**)(void **), 0xC)(gb);
            }
            temp_r3_341 = M2C_FIELD(var_r3_330, void **, 8);
            sp18 = -M2C_FIELD(temp_r3_341, f32 *, 0x20);
            sp1C = -M2C_FIELD(temp_r3_341, f32 *, 0x24);
            sp8 = -M2C_FIELD(temp_r29_316, f32 *, 0x30);
            sp28 = (f64) sp18;
            spC = -M2C_FIELD(temp_r29_316, f32 *, 0x34);
            sp20 = -M2C_FIELD(temp_r3_341, f32 *, 0x28);
            sp38 = (f64) sp8;
            sp10 = -M2C_FIELD(temp_r29_316, f32 *, 0x38);
            sp30 = (f64) sp20;
            sp40 = (f64) sp10;
            temp_f1_377 = ((f32) sp40 * (f32) sp30) + (((f32) sp38 * (f32) sp28) + (unksp3C * unksp2C));
            if (temp_r3_321 == 0) {
                if ((temp_f1_377 > 0.0f) && (temp_r3_382 = this->unk10.unk40, (((M2C_BITWISE(s32, temp_r3_382) & 0x20) == 0) == 0))) {
                    this->unk10.unk40 = M2C_BITWISE(f32, (M2C_BITWISE(s32, temp_r3_382) | 2));
                } else if (temp_f1_377 < 0.0f) {
                    temp_r3_392 = this->unk10.unk40;
                    if (!(M2C_BITWISE(s32, temp_r3_392) & 0x20)) {
                        this->unk10.unk40 = M2C_BITWISE(f32, (M2C_BITWISE(s32, temp_r3_392) | 4));
                    }
                }
                this->unk10.unk40 = M2C_BITWISE(f32, (M2C_BITWISE(s32, this->unk10.unk40) & 0xFFFFFFF7));
            } else if (temp_f1_377 > 0.0f) {
                this->unk10.unk40 = M2C_BITWISE(f32, (M2C_BITWISE(s32, this->unk10.unk40) | 0x20));
            } else {
                this->unk10.unk40 = M2C_BITWISE(f32, (M2C_BITWISE(s32, this->unk10.unk40) & 0xFFFFFFDF));
            }
        }
        M2C_FIELD(temp_r29_316, u8 *, 0xC0) = temp_r3_321;
        var_r30_313 = M2C_BITWISE(f32, (M2C_BITWISE(s32, var_r30_313) + 4));
        goto loop_17;
    }
    M2C_FIELD(this, u8 *, 0x84) = 0U;
    return M2C_FIELD(this, u8 *, 0x84);
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void TriggerPlaneGroupObject::LoadDone() {
    MKHeap *temp_r3_567;
    f32 temp_r3_589;
    f32 temp_r3_595;
    f32 var_r5_583;
    s32 var_ctr_587;
    void *var_r3_574;

    M2C_FIELD(this, s8 *, 0x84) = 0;
    temp_r3_567 = MKHeap::Current();
    if (temp_r3_567 != NULL) {
        var_r3_574 = ((MKHeap *) (temp_r3_567->Current()))->Alloc(0x108, NULL, 0);
    } else {
        var_r3_574 = malloc(0x108);
    }
    this->unk10.unk70 = M2C_BITWISE(f32, var_r3_574);
    var_r5_583 = this->unk10.unk70;
    this->unk10.unk70 = M2C_BITWISE(f32, (M2C_BITWISE(s32, var_r5_583) + 0x80));
    M2C_FIELD(var_r5_583, s32 *, 0x80) = 0;
    var_ctr_587 = 0x20;
    do {
        temp_r3_589 = this->unk10.unk70;
        this->unk10.unk70 = M2C_BITWISE(f32, (M2C_BITWISE(void *, temp_r3_589) + 4));
        M2C_FIELD(M2C_BITWISE(void *, temp_r3_589), f32 *, 4) = var_r5_583;
        var_r5_583 = M2C_BITWISE(f32, (M2C_BITWISE(s32, var_r5_583) + 4));
        var_ctr_587 -= 1;
    } while (var_ctr_587 != 0);
    temp_r3_595 = this->unk10.unk70;
    this->unk10.unk70 = M2C_BITWISE(f32, (M2C_BITWISE(void *, temp_r3_595) + 4));
    M2C_FIELD(M2C_BITWISE(void *, temp_r3_595), s32 *, 4) = 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk70'
void TriggerPlaneGroupObject::Deinit() {
    MKHeap *temp_r3_642;
    f32 var_r31_616;
    f32 var_r3_617;
    f32 var_r4_615;
    u32 temp_r0_620;
    u32 temp_r0_625;
    u32 temp_r0_639;

    var_r4_615 = this->unk10.unk70;
    var_r31_616 = var_r4_615;
    var_r3_617 = var_r4_615;
loop_3:
    temp_r0_625 = M2C_FIELD(var_r3_617, u32 *, -4);
    var_r3_617 = M2C_BITWISE(f32, (M2C_BITWISE(s32, var_r3_617) - 4));
    if (temp_r0_625 != 0U) {
        temp_r0_620 = *var_r3_617;
        if (temp_r0_620 < M2C_BITWISE(u32, var_r31_616)) {
            var_r31_616 = M2C_BITWISE(f32, temp_r0_620);
        }
        goto loop_3;
    }
    if (M2C_BITWISE(u32, var_r3_617) != &gEmptyPtrListDL) {
loop_9:
        temp_r0_639 = *var_r4_615;
        if (temp_r0_639 != 0U) {
            if (temp_r0_639 < M2C_BITWISE(u32, var_r31_616)) {
                var_r31_616 = M2C_BITWISE(f32, temp_r0_639);
            }
            var_r4_615 = M2C_BITWISE(f32, (M2C_BITWISE(s32, var_r4_615) + 4));
            goto loop_9;
        }
        temp_r3_642 = ((MKHeap *) (M2C_BITWISE(MKHeap *, var_r3_617)))->Current();
        if (temp_r3_642 != NULL) {
            ((MKHeap *) (temp_r3_642->Current()))->Free(M2C_BITWISE(void *, var_r31_616), NULL, 0);
        } else {
            free(var_r31_616);
        }
    }
    this->unk10.unk70 = 0.0f;
}
#endif

void TriggerPlaneObject::LoadDone() {
    TriggerBoxObject::LoadDone();
    this->unkC0 = 0;
    this->unkC4 = 0;
}

#if 0 // DRAFT: expression syntax error
void TriggerBoxObject::LoadDone(const MKVector3 &arg0, const Matrix &arg1) {
    tempBoxRot.__vptr = 0.0f;
    tempBoxRot.unk4 = 0.0f;
    tempBoxRot.unk8 = 0.0f;
    M2C_STRUCT_COPY((s32) &this->unkC + 4, (s32) (&arg1 - 4) + 4, 0x40);
    M2C_FIELD(this, f64 *, 0x70) = (f64) M2C_FIELD(&arg0, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x78) = (f64) M2C_FIELD(&arg0, f64 *, 8);
    this->unk10.unk70.InverseSimple(&this->unk10);
    this->unk10.unk50 = M2C_BITWISE(f32, this->unk10.unk60) / -2.0f;
    this->unk10.unk54 = this->unk10.unk64 / -2.0f;
    this->unk10.unk58 = this->unk10.unk68 / -2.0f;
}
#endif

#if 0 // DRAFT: expression syntax error
void TriggerBoxObject::LoadDone() {
    this->unk10.SetRotationPYR(*((MKVector3 *) &tempBoxRot));
    tempBoxRot.__vptr = 0.0f;
    tempBoxRot.unk4 = 0.0f;
    tempBoxRot.unk8 = 0.0f;
    this->unk10.unk70.InverseSimple(&this->unk10);
    this->unk10.unk50 = M2C_BITWISE(f32, this->unk10.unk60) / -2.0f;
    this->unk10.unk54 = this->unk10.unk64 / -2.0f;
    this->unk10.unk58 = this->unk10.unk68 / -2.0f;
}
#endif

#if 0 // DRAFT: function call 'stricmp(const char[4])' does not match
s32 TriggerBoxObject::LoadLine(char *arg0, MKIniLine *arg1) {
    f64 sp18;
    f64 sp10;
    u8 sp8;
    MKIniLine *var_r30_786;

    if (arg1->IsField(arg0) != 0) {
        var_r30_786 = arg1->unkC->GetSubLine(arg1);
loop_10:
        if (var_r30_786 != NULL) {
            var_r30_786->GetFieldName();
            if (stricmp("pos") == 0) {
                sp10 = M2C_FIELD(this, f64 *, 0x40);
                sp18 = M2C_FIELD(this, f64 *, 0x48);
                var_r30_786->AsVector3(0, (MKVector3 *) &sp10);
                this->unk10.unk30 = (f32) sp10;
                this->unk10.unk34 = unksp14;
                this->unk10.unk38 = (f32) sp18;
                this->unk10.unk3C = 1.0f;
            } else if ((var_r30_786->LoadVector3("rot", (MKVector3 *) &tempBoxRot, 0) == 0) && (var_r30_786->LoadVector3("scale", (MKVector3 *) &this->unk10.unk60, 0) == 0) && (var_r30_786->LoadBool("bUseTrigger", &sp8, 0) != 0) && (sp8 == 0)) {
                this->unk10.unk40 = M2C_BITWISE(f32, (M2C_BITWISE(s32, this->unk10.unk40) & 0xFFFFFFFE));
            }
            var_r30_786 = var_r30_786->unkC->GetNextLine(var_r30_786);
            goto loop_10;
        }
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk70'
void TriggerSphereObject::LoadDone() {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 temp_f0_875;
    f32 temp_f0_890;

    temp_f0_875 = -this->unk10.unk70;
    this->unk10.unk50 = temp_f0_875;
    this->unk10.unk54 = temp_f0_875;
    this->unk10.unk58 = temp_f0_875;
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r3, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f2 */);
    M2C_FIELD(this, f64 *, 0x70) = sp8;
    sp10 = this->unk10.unk58 * -2.0f;
    sp18 = sp8;
    M2C_FIELD(this, f64 *, 0x78) = (f64) sp10;
    temp_f0_890 = this->unk10.unk70;
    sp20 = (f64) sp10;
    this->unk10.unk70 = temp_f0_890 * temp_f0_890;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk70'
s32 TriggerSphereObject::LoadLine(char *arg0, MKIniLine *arg1) {
    f64 sp18;
    f64 sp10;
    f32 spC;
    u8 sp9;
    u8 sp8;
    MKIniLine *var_r29_918;
    u8 var_r30_991;

    if (arg1->IsField(arg0) != 0) {
        var_r29_918 = arg1->unkC->GetSubLine(arg1);
loop_11:
        if (var_r29_918 != NULL) {
            spC = 0.0f;
            sp9 = 1;
            if (var_r29_918->LoadFloat("radius", &spC, 0) != 0) {
                if (spC > 0.0f) {
                    this->unk10.unk70 = spC;
                }
            } else if (var_r29_918->LoadBool("bUseTrigger", &sp9, 0) != 0) {
                if (sp9 == 0) {
                    this->unk10.unk40 = M2C_BITWISE(f32, (M2C_BITWISE(s32, this->unk10.unk40) & 0xFFFFFFFE));
                }
            } else {
                var_r29_918->GetFieldName();
                if (stricmp("pos") == 0) {
                    sp10 = M2C_FIELD(this, f64 *, 0x40);
                    sp18 = M2C_FIELD(this, f64 *, 0x48);
                    var_r29_918->AsVector3(0, (MKVector3 *) &sp10);
                    this->unk10.unk30 = (f32) sp10;
                    this->unk10.unk34 = unksp14;
                    this->unk10.unk38 = (f32) sp18;
                    this->unk10.unk3C = 1.0f;
                }
            }
            var_r29_918 = var_r29_918->unkC->GetNextLine(var_r29_918);
            goto loop_11;
        }
        return 1;
    }
    var_r30_991 = 0;
    sp8 = 0;
    if ((TriggerObject::LoadLine(arg1) != 0) || (arg1->LoadFloat("radius", &this->unk10.unk70, 0) != 0) || (arg1->LoadBool("bUseTrigger", &sp8, 0) != 0)) {
        var_r30_991 = 1;
    }
    if (var_r30_991 != 0) {
        if (sp8 == 0) {
            this->unk10.unk40 = M2C_BITWISE(f32, (M2C_BITWISE(s32, this->unk10.unk40) & 1));
            return 1;
        }
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk70'
void TriggerSphereObject::Init(float arg0) {
    TriggerObject::Init();
    this->unk10.unk70 = arg0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk40'
u16 TriggerObject::Update() {
    f32 temp_r3_1086;
    f32 temp_r3_1097;
    f32 temp_r4_1072;

    temp_r4_1072 = this->unk10.unk40;
    if (!(M2C_BITWISE(s32, temp_r4_1072) & 1)) {
        return 0U;
    }
    this->unk10.unk40 = M2C_BITWISE(f32, (M2C_BITWISE(s32, temp_r4_1072) & 0xFFFFFFF9));
    if (CheckTarget() != 0) {
        temp_r3_1086 = this->unk10.unk40;
        if (!(M2C_BITWISE(s32, temp_r3_1086) & 8)) {
            this->unk10.unk40 = M2C_BITWISE(f32, (M2C_BITWISE(s32, temp_r3_1086) | 2));
        }
        this->unk10.unk40 = M2C_BITWISE(f32, (M2C_BITWISE(s32, this->unk10.unk40) | 8));
    } else {
        temp_r3_1097 = this->unk10.unk40;
        if (M2C_BITWISE(s32, temp_r3_1097) & 8) {
            this->unk10.unk40 = M2C_BITWISE(f32, (M2C_BITWISE(s32, temp_r3_1097) | 4));
            this->unk10.unk40 = M2C_BITWISE(f32, (M2C_BITWISE(s32, this->unk10.unk40) & 0xFFFFFFFD));
        }
        this->unk10.unk40 = M2C_BITWISE(f32, (M2C_BITWISE(s32, this->unk10.unk40) & 0xFFFFFFF7));
    }
    return M2C_BITWISE(u16, this->unk10.unk40);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk40'
void TriggerObject::EnableTrigger(bool arg0) {
    if (arg0 != 0) {
        this->unk10.unk40 = M2C_BITWISE(f32, (M2C_BITWISE(s32, this->unk10.unk40) | 1));
        return;
    }
    this->unk10.unk40 = M2C_BITWISE(f32, (M2C_BITWISE(s32, this->unk10.unk40) & ~9));
}
#endif

#if 0 // DRAFT: undefined identifier 'IsWithIn'
void TriggerObject::Message(MKMessage *arg0) {
    f32 temp_r5_1155;
    u8 var_r4_1156;
    void *temp_r3_1151;

    if ((s32) arg0->unk0 != 0xD) {
        return;
    }
    temp_r3_1151 = checked_cast<IsWithIn *, MKMessage>(arg0);
    if ((u8) M2C_FIELD(temp_r3_1151, u8 *, 0x18) == 0) {
        temp_r5_1155 = this->unk10.unk40;
        var_r4_1156 = 0;
        if ((M2C_BITWISE(s32, temp_r5_1155) & 8) && (M2C_BITWISE(s32, temp_r5_1155) & 0x10)) {
            var_r4_1156 = 1;
        }
        M2C_FIELD(temp_r3_1151, u8 *, 0x18) = var_r4_1156;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk40'
void TriggerObject::Reset() {
    this->unk10.unk40 = M2C_BITWISE(f32, (M2C_BITWISE(s32, this->unk10.unk40) & 0xFFFFFFF1));
}
#endif

#if 0 // DRAFT: function call 'stricmp(const char[4])' does not match
u8 TriggerObject::LoadLine(MKIniLine *arg0) {
    f64 sp10;
    f64 sp8;

    arg0->GetFieldName();
    if (stricmp("pos") == 0) {
        sp8 = M2C_FIELD(this, f64 *, 0x40);
        sp10 = M2C_FIELD(this, f64 *, 0x48);
        arg0->AsVector3(0, (MKVector3 *) &sp8);
        this->unk10.unk30 = (f32) sp8;
        this->unk10.unk34 = unkspC;
        this->unk10.unk38 = (f32) sp10;
        this->unk10.unk3C = 1.0f;
        return 1U;
    }
    return arg0->LoadInt("targetID", (s32 *) &this->unk10.unk44, 0);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk40'
void TriggerObject::Init() {
    this->unk10.SetIdentity();
    this->unk10.unk40 = 1e-45f;
    this->unk10.unk44 = 0.0f;
    this->unk10.unk50 = -1.0f;
    this->unk10.unk54 = -1.0f;
    this->unk10.unk58 = -1.0f;
    this->unk10.unk60 = 2.0f;
    this->unk10.unk64 = 2.0f;
    this->unk10.unk68 = 2.0f;
}
#endif

#if 0 // DRAFT: undefined identifier 'tempBoxRot'
void TriggerObject_cpp::__sinit() {
    M2C_FIELD(&tempBoxRot, f64 *, 0) = (f64) M2C_FIELD(&zero, f64 *, 0);
    M2C_FIELD(&tempBoxRot, f64 *, 8) = (f64) M2C_FIELD(&zero, f64 *, 8);
}
#endif
