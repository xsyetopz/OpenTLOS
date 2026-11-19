#include "spyro/source/TriggerObject.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

M2C_UNK free(MKVector3 *);                          /* extern */
MKVector3 *malloc(s32);                             /* extern */
s32 stricmp(s8 *);                                  /* extern */
extern M2C_UNK gEmptyPtrListDL;
extern void **gb;
u8 tempBoxRot__16TriggerBoxObject[0x10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

#if 0 // DRAFT: illegal implicit conversion from 'MKSceneManager *' to
s32 TriggerPolyObject::CheckTarget() {
    f64 sp10;
    f64 sp8;
    s32 temp_r3_32;
    s32 var_r31_47;
    void *temp_r3_46;
    void *var_r3_35;

    temp_r3_32 = this->unk54;
    if (temp_r3_32 > 0) {
        var_r3_35 = ((MKSceneManager *) temp_r3_32)->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */));
    } else {
        var_r3_35 = M2C_FIELD(*gb, void *(**)(void **), 0xC)(gb);
    }
    temp_r3_46 = M2C_FIELD(var_r3_35, void **, 8);
    var_r31_47 = 0;
    sp8 = M2C_FIELD(temp_r3_46, f64 *, 0x30);
    sp10 = M2C_FIELD(temp_r3_46, f64 *, 0x38);
    if (((*(f32 *) ((u8 *) &sp8 + 0x4)) >= this->unk88.unk1C) && ((*(f32 *) ((u8 *) &sp8 + 0x4)) <= this->unkA8) && (this->unk88.IsPointWithin(*((MKVector3 *) &sp8)) != 0)) {
        var_r31_47 = 1;
    }
    return var_r31_47;
}
#endif

s32 TriggerPolyObject::CheckPos(const MKVector3 &arg0) {
    f32 temp_f1_81;
    s32 var_r31_84;

    temp_f1_81 = arg0.unk4;
    var_r31_84 = 0;
    if ((temp_f1_81 >= this->unk88.unk1C) && (temp_f1_81 <= this->unkA8) && (this->unk88.IsPointWithin(arg0) != 0)) {
        var_r31_84 = 1;
    }
    return var_r31_84;
}

#if 0 // DRAFT: illegal implicit conversion from 'MKVector3' to
void TriggerPolyObject::LoadDone() {
    f32 temp_f1_126;
    f32 temp_f1_134;
    s32 var_r3_120;
    s32 var_r5_119;

    this->unk88.Init(this->unk84, this->unk80);
    var_r5_119 = 0;
    var_r3_120 = 0;
loop_6:
    if (var_r5_119 < (s32) this->unk80) {
        temp_f1_126 = *(this->unk84 + (var_r3_120 + 4));
        if (temp_f1_126 < this->unk88.unk1C) {
            this->unk88.unk1C = temp_f1_126;
        }
        temp_f1_134 = *(this->unk84 + (var_r3_120 + 4));
        if (temp_f1_134 > this->unkA8) {
            this->unkA8 = temp_f1_134;
        }
        var_r5_119 += 1;
        var_r3_120 += 0x10;
        goto loop_6;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
s32 TriggerPolyObject::LoadLine(char *arg0, MKIniLine *arg1) {
    MKHeap *temp_r3_174;
    MKIniLine *var_r28_192;
    MKVector3 *var_r3_181;
    s32 temp_r29_173;
    s32 temp_r3_170;
    s32 var_r30_194;

    TriggerObject::LoadLine(arg1);
    if (arg1->IsField(arg0) != 0) {
        temp_r3_170 = arg1->GetNmbrOfSubLines();
        this->unk80 = temp_r3_170;
        temp_r29_173 = this->unk80 * 0x10;
        temp_r3_174 = ((MKHeap *) temp_r3_170)->Current();
        if (temp_r3_174 != NULL) {
            var_r3_181 = ((MKHeap *) (temp_r3_174->Current()))->Alloc(temp_r29_173, NULL, 0);
        } else {
            var_r3_181 = malloc(temp_r29_173);
        }
        this->unk84 = var_r3_181;
        var_r28_192 = arg1->unkC->GetSubLine(arg1);
        var_r30_194 = 0;
loop_8:
        if (var_r28_192 != NULL) {
            if (var_r28_192->LoadVector3("waypoint", this->unk84 + var_r30_194, 0) != 0) {
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

#if 0 // DRAFT: illegal use of non-static member
void TriggerPolyObject::Deinit() {
    MKHeap *temp_r3_234;
    MKVector3 *temp_r31_233;

    temp_r31_233 = this->unk84;
    temp_r3_234 = MKHeap::Current();
    if (temp_r3_234 != NULL) {
        ((MKHeap *) (temp_r3_234->Current()))->Free(temp_r31_233, NULL, 0);
        return;
    }
    free(temp_r31_233);
}
#endif

void TriggerPolyObject::Init() {
    TriggerObject::Init();
    this->unk80 = 0;
    this->unk84 = NULL;
    this->unk88.unk1C = 9.99999e7f;
    this->unkA8 = -9.99999e7f;
}

s32 TriggerPlaneGroupObject::AddPlane(TriggerPlaneObject *arg0) {
    TriggerPlaneObject ***temp_r5_295;
    TriggerPlaneObject ***var_r6_280;
    TriggerPlaneObject **temp_r5_291;

    var_r6_280 = this->unk80;
loop_4:
    temp_r5_291 = *var_r6_280;
    if (temp_r5_291 == NULL) {
        temp_r5_295 = this->unk80 - 4;
        this->unk80 = temp_r5_295;
        **temp_r5_295 = arg0;
        this->unk54 = arg0->unk54;
        return 1;
    }
    if ((TriggerPlaneObject *) *temp_r5_291 == arg0) {
        return 0;
    }
    var_r6_280 += 4;
    goto loop_4;
}

#if 0 // DRAFT: illegal implicit conversion from 'MKSceneManager *' to
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
    TriggerPlaneObject ***var_r30_313;
    TriggerPlaneObject **temp_r3_418;
    TriggerPlaneObject *temp_r29_316;
    f32 temp_f1_377;
    s32 temp_r3_327;
    s32 temp_r3_382;
    s32 temp_r3_392;
    u8 temp_r3_321;
    u8 temp_ret_321;
    void *temp_r3_341;
    void *var_r3_330;

    var_r30_313 = this->unk80;
loop_17:
    temp_r3_418 = *var_r30_313;
    if (temp_r3_418 != NULL) {
        temp_r29_316 = *temp_r3_418;
        temp_ret_321 = temp_r29_316->CheckTarget();
        temp_r3_321 = temp_ret_321;
        if (temp_r3_321 != (u8) temp_r29_316->unkC0) {
            temp_r3_327 = temp_r29_316->unk54;
            if (temp_r3_327 > 0) {
                var_r3_330 = ((MKSceneManager *) temp_r3_327)->PropResolver_Resolve((s32) (u32) (u64) temp_ret_321);
            } else {
                var_r3_330 = M2C_FIELD(*gb, void *(**)(void **), 0xC)(gb);
            }
            temp_r3_341 = M2C_FIELD(var_r3_330, void **, 8);
            sp18 = -M2C_FIELD(temp_r3_341, f32 *, 0x20);
            sp1C = -M2C_FIELD(temp_r3_341, f32 *, 0x24);
            sp8 = -temp_r29_316->unk10.unk20;
            sp28 = (f64) sp18;
            spC = -temp_r29_316->unk10.unk24;
            sp20 = -M2C_FIELD(temp_r3_341, f32 *, 0x28);
            sp38 = (f64) sp8;
            sp10 = -temp_r29_316->unk10.unk28;
            sp30 = (f64) sp20;
            sp40 = (f64) sp10;
            temp_f1_377 = ((f32) sp40 * (f32) sp30) + (((f32) sp38 * (f32) sp28) + ((*(f32 *) ((u8 *) &sp38 + 0x4)) * (*(f32 *) ((u8 *) &sp28 + 0x4))));
            if (temp_r3_321 == 0) {
                if ((temp_f1_377 > 0.0f) && (temp_r3_382 = this->unk50, (((temp_r3_382 & 0x20) == 0) == 0))) {
                    this->unk50 = temp_r3_382 | 2;
                } else if (temp_f1_377 < 0.0f) {
                    temp_r3_392 = this->unk50;
                    if (!(temp_r3_392 & 0x20)) {
                        this->unk50 = temp_r3_392 | 4;
                    }
                }
                this->unk50 &= 0xFFFFFFF7;
            } else if (temp_f1_377 > 0.0f) {
                this->unk50 |= 0x20;
            } else {
                this->unk50 &= 0xFFFFFFDF;
            }
        }
        temp_r29_316->unkC0 = temp_r3_321;
        var_r30_313 += 4;
        goto loop_17;
    }
    this->unk84 = 0;
    return this->unk84;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void TriggerPlaneGroupObject::LoadDone() {
    MKHeap *temp_r3_567;
    MKVector3 *var_r3_574;
    TriggerPlaneObject ***temp_r3_589;
    TriggerPlaneObject ***temp_r3_595;
    TriggerPlaneObject ***var_r5_583;
    s32 var_ctr_587;

    this->unk84 = 0;
    temp_r3_567 = MKHeap::Current();
    if (temp_r3_567 != NULL) {
        var_r3_574 = ((MKHeap *) (temp_r3_567->Current()))->Alloc(0x108, NULL, 0);
    } else {
        var_r3_574 = malloc(0x108);
    }
    this->unk80 = (TriggerPlaneObject ***) var_r3_574;
    var_r5_583 = this->unk80;
    this->unk80 = var_r5_583 + 0x80;
    M2C_FIELD(var_r5_583, s32 *, 0x80) = 0;
    var_ctr_587 = 0x20;
    do {
        temp_r3_589 = this->unk80;
        this->unk80 = temp_r3_589 + 4;
        M2C_FIELD(temp_r3_589, TriggerPlaneObject ****, 4) = var_r5_583;
        var_r5_583 += 4;
        var_ctr_587 -= 1;
    } while (var_ctr_587 != 0);
    temp_r3_595 = this->unk80;
    this->unk80 = temp_r3_595 + 4;
    M2C_FIELD(temp_r3_595, TriggerPlaneObject ****, 4) = NULL;
}
#endif

#if 0 // DRAFT: type mismatch
void TriggerPlaneGroupObject::Deinit() {
    MKHeap *temp_r3_642;
    TriggerPlaneObject ***var_r31_616;
    TriggerPlaneObject ***var_r3_617;
    TriggerPlaneObject ***var_r4_615;
    TriggerPlaneObject **temp_r0_620;
    TriggerPlaneObject **temp_r0_639;
    u32 temp_r0_625;

    var_r4_615 = this->unk80;
    var_r31_616 = var_r4_615;
    var_r3_617 = var_r4_615;
loop_3:
    temp_r0_625 = M2C_FIELD(var_r3_617, u32 *, -4);
    var_r3_617 -= 4;
    if (temp_r0_625 != 0U) {
        temp_r0_620 = *var_r3_617;
        if (temp_r0_620 < var_r31_616) {
            var_r31_616 = (TriggerPlaneObject ***) temp_r0_620;
        }
        goto loop_3;
    }
    if (var_r3_617 != &gEmptyPtrListDL) {
loop_9:
        temp_r0_639 = *var_r4_615;
        if (temp_r0_639 != NULL) {
            if (temp_r0_639 < var_r31_616) {
                var_r31_616 = (TriggerPlaneObject ***) temp_r0_639;
            }
            var_r4_615 += 4;
            goto loop_9;
        }
        temp_r3_642 = ((MKHeap *) var_r3_617)->Current();
        if (temp_r3_642 != NULL) {
            ((MKHeap *) (temp_r3_642->Current()))->Free(var_r31_616, NULL, 0);
        } else {
            free((MKVector3 *) var_r31_616);
        }
    }
    this->unk80 = NULL;
}
#endif

void TriggerPlaneObject::LoadDone() {
    TriggerBoxObject::LoadDone();
    this->unkC0 = 0;
    this->unkC4 = 0;
}

#if 0 // DRAFT: undefined identifier 'unkC'
void TriggerBoxObject::LoadDone(const MKVector3 &arg0, const Matrix &arg1) {
    M2C_FIELD(TriggerBoxObject::tempBoxRot, f32 *, 0) = 0.0f;
    M2C_FIELD(TriggerBoxObject::tempBoxRot, f32 *, 4) = 0.0f;
    M2C_FIELD(TriggerBoxObject::tempBoxRot, f32 *, 8) = 0.0f;
    M2C_STRUCT_COPY((s32) &this->unkC + 4, (s32) (&arg1 - 4) + 4, 0x40);
    M2C_FIELD(this, f64 *, 0x70) = (f64) M2C_FIELD(&arg0, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x78) = (f64) M2C_FIELD(&arg0, f64 *, 8);
    ((Matrix *) &this->unk80)->InverseSimple(&this->unk10);
    this->unk60 = this->unk70 / -2.0f;
    this->unk64 = this->unk74 / -2.0f;
    this->unk68 = this->unk78 / -2.0f;
}
#endif

void TriggerBoxObject::LoadDone() {
    this->unk10.SetRotationPYR(*((MKVector3 *) TriggerBoxObject::tempBoxRot));
    M2C_FIELD(TriggerBoxObject::tempBoxRot, f32 *, 0) = 0.0f;
    M2C_FIELD(TriggerBoxObject::tempBoxRot, f32 *, 4) = 0.0f;
    M2C_FIELD(TriggerBoxObject::tempBoxRot, f32 *, 8) = 0.0f;
    ((Matrix *) &this->unk80)->InverseSimple(&this->unk10);
    this->unk60 = this->unk70 / -2.0f;
    this->unk64 = this->unk74 / -2.0f;
    this->unk68 = this->unk78 / -2.0f;
}

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
                this->unk10.unk34 = (*(f32 *) ((u8 *) &sp10 + 0x4));
                this->unk10.unk38 = (f32) sp18;
                this->unk10.unk3C = 1.0f;
            } else if ((var_r30_786->LoadVector3("rot", (MKVector3 *) TriggerBoxObject::tempBoxRot, 0) == 0) && (var_r30_786->LoadVector3("scale", (MKVector3 *) &this->unk70, 0) == 0) && (var_r30_786->LoadBool("bUseTrigger", &sp8, 0) != 0) && (sp8 == 0)) {
                this->unk50 &= 0xFFFFFFFE;
            }
            var_r30_786 = var_r30_786->unkC->GetNextLine(var_r30_786);
            goto loop_10;
        }
        return 1;
    }
    return 0;
}
#endif

void TriggerSphereObject::LoadDone() {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f0_875;
    f32 temp_f0_890;
    f64 temp_f0_880;

    temp_f0_875 = -this->unk80;
    this->unk60 = temp_f0_875;
    this->unk64 = temp_f0_875;
    this->unk68 = temp_f0_875;
    temp_f0_880 = (f64) M2C_FIELD(this, f32 *, 0x60) * 1.591496843e-314;
    sp8 = temp_f0_880;
    M2C_FIELD(this, f64 *, 0x70) = temp_f0_880;
    sp10 = this->unk68 * -2.0f;
    sp18 = temp_f0_880;
    M2C_FIELD(this, f64 *, 0x78) = (f64) sp10;
    temp_f0_890 = this->unk80;
    sp20 = (f64) sp10;
    this->unk80 = temp_f0_890 * temp_f0_890;
}

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to
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
                    this->unk80 = spC;
                }
            } else if (var_r29_918->LoadBool("bUseTrigger", &sp9, 0) != 0) {
                if (sp9 == 0) {
                    this->unk50 &= 0xFFFFFFFE;
                }
            } else {
                var_r29_918->GetFieldName();
                if (stricmp("pos") == 0) {
                    sp10 = M2C_FIELD(this, f64 *, 0x40);
                    sp18 = M2C_FIELD(this, f64 *, 0x48);
                    var_r29_918->AsVector3(0, (MKVector3 *) &sp10);
                    this->unk10.unk30 = (f32) sp10;
                    this->unk10.unk34 = (*(f32 *) ((u8 *) &sp10 + 0x4));
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
    if ((TriggerObject::LoadLine(arg1) != 0) || (arg1->LoadFloat("radius", &this->unk80, 0) != 0) || (arg1->LoadBool("bUseTrigger", &sp8, 0) != 0)) {
        var_r30_991 = 1;
    }
    if (var_r30_991 != 0) {
        if (sp8 == 0) {
            this->unk50 &= 1;
            return 1;
        }
        return 1;
    }
    return 0;
}
#endif

void TriggerSphereObject::Init(float arg0) {
    TriggerObject::Init();
    this->unk80 = arg0;
}

u16 TriggerObject::Update() {
    s32 temp_r3_1086;
    s32 temp_r3_1097;
    s32 temp_r4_1072;

    temp_r4_1072 = this->unk50;
    if (!(temp_r4_1072 & 1)) {
        return 0U;
    }
    this->unk50 = temp_r4_1072 & 0xFFFFFFF9;
    if (CheckTarget() != 0) {
        temp_r3_1086 = this->unk50;
        if (!(temp_r3_1086 & 8)) {
            this->unk50 = temp_r3_1086 | 2;
        }
        this->unk50 |= 8;
    } else {
        temp_r3_1097 = this->unk50;
        if (temp_r3_1097 & 8) {
            this->unk50 = temp_r3_1097 | 4;
            this->unk50 &= 0xFFFFFFFD;
        }
        this->unk50 &= 0xFFFFFFF7;
    }
    return (u16) this->unk50;
}

void TriggerObject::EnableTrigger(bool arg0) {
    if (arg0 != 0) {
        this->unk50 |= 1;
        return;
    }
    this->unk50 &= ~9;
}

#if 0 // DRAFT: undefined identifier 'IsWithIn'
void TriggerObject::Message(MKMessage *arg0) {
    s32 temp_r5_1155;
    u8 var_r4_1156;
    void *temp_r3_1151;

    if ((s32) arg0->unk0 != 0xD) {
        return;
    }
    temp_r3_1151 = checked_cast<IsWithIn *, MKMessage>(arg0);
    if ((u8) M2C_FIELD(temp_r3_1151, u8 *, 0x18) == 0) {
        temp_r5_1155 = this->unk50;
        var_r4_1156 = 0;
        if ((temp_r5_1155 & 8) && (temp_r5_1155 & 0x10)) {
            var_r4_1156 = 1;
        }
        M2C_FIELD(temp_r3_1151, u8 *, 0x18) = var_r4_1156;
    }
}
#endif

void TriggerObject::Reset() {
    this->unk50 &= 0xFFFFFFF1;
}

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
        this->unk10.unk34 = (*(f32 *) ((u8 *) &sp8 + 0x4));
        this->unk10.unk38 = (f32) sp10;
        this->unk10.unk3C = 1.0f;
        return 1U;
    }
    return arg0->LoadInt("targetID", &this->unk54, 0);
}
#endif

void TriggerObject::Init() {
    this->unk10.SetIdentity();
    this->unk50 = 1;
    this->unk54 = 0;
    this->unk60 = -1.0f;
    this->unk64 = -1.0f;
    this->unk68 = -1.0f;
    this->unk70 = 2.0f;
    this->unk74 = 2.0f;
    this->unk78 = 2.0f;
}

void TriggerObject_cpp::__sinit() {
    M2C_FIELD(TriggerBoxObject::tempBoxRot, f64 *, 0) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 0);
    M2C_FIELD(TriggerBoxObject::tempBoxRot, f64 *, 8) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
}
