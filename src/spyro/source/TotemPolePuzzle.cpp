#include "spyro/source/TotemPolePuzzle.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/GameProp.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(s32);                                  /* extern */
extern MKSceneManager *gMK;
extern f32 gUpdateTimeDelta;

#if 0 // DRAFT: illegal use of non-static member
void TotemPolePuzzle::Deinit() {
    MKHeap *temp_r3_51;
    void *temp_r31_50;

    temp_r31_50 = this->unkC8;
    temp_r3_51 = MKHeap::Current();
    if (temp_r3_51 != NULL) {
        ((MKHeap *) (temp_r3_51->Current()))->Free(temp_r31_50, NULL, 0);
    } else {
        free(temp_r31_50);
    }
    this->unkC8 = NULL;
    GameProp::Deinit();
}
#endif

#if 0 // DRAFT: illegal type
void TotemPolePuzzle::Update() {
    s32 temp_r0_85;
    s32 var_ctr_87;
    s32 var_r3_86;
    void *temp_r5_92;

    if ((u8) this->unkD8 == 0) {
        temp_r0_85 = this->unkCC;
        var_r3_86 = 0;
        var_ctr_87 = temp_r0_85;
        if (temp_r0_85 > 0) {
loop_2:
            temp_r5_92 = *(this->unkC8 + var_r3_86);
            if ((s32) M2C_FIELD(temp_r5_92, s32 *, 0xD0) == (s32) M2C_FIELD(temp_r5_92, s32 *, 0xD4)) {
                var_r3_86 += 4;
                var_ctr_87 -= 1;
                if (var_ctr_87 == 0) {
                    goto block_4;
                }
                goto loop_2;
            }
        } else {
block_4:
            this->unkD8 = 1;
            this->unkD4.Send(NULL);
        }
    }
}
#endif

#if 0 // DRAFT: illegal type
void TotemPolePuzzle::LoadDone() {
    f64 sp70;                                       /* compiler-managed */
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
    f32 spC;
    f32 sp8;
    s32 var_r30_124;
    s32 var_r31_126;

    GameProp::LoadDone();
    var_r30_124 = 0;
    var_r31_126 = 0;
    sp68 = this->unkE0;
    sp70 = this->unkE8;
loop_2:
    if (var_r30_124 < (s32) this->unkCC) {
        MKModel_SetPosition(M2C_FIELD(*(this->unkC8 + var_r31_126), MKModel **, 4), *((MKVector3 *) &sp68));
        sp10 = 0.0f;
        sp8 = 0.0f;
        spC = this->unkD0;
        sp60 = (f64) sp10;
        sp58 = (f64) sp8;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        var_r30_124 += 1;
        var_r31_126 += 4;
        sp70 = (f32) sp70 + (f32) sp60;
        goto loop_2;
    }
    sp28 = 0.0f;
    sp2C = this->unkD0;
    sp30 = 0.0f;
    sp38 = (f64) sp28;
    sp40 = (f64) sp30;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r29, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    sp48 = sp18;
    sp20 = (f32) M2C_FIELD(this, f64 *, 0xE8) - (f32) sp40;
    sp50 = (f64) sp20;
    MKModel_SetPosition(this->unk4, *((MKVector3 *) &sp48));
}
#endif

#if 0 // DRAFT: undefined identifier 'Current'
s32 TotemPolePuzzle::LoadLine(MKIniLine *arg0) {
    s8 *sp10;
    s32 spC;
    s32 sp8;
    MKHeap *temp_r3_231;
    MKIniLine *temp_r3_227;
    MKIniLine *var_r28_229;
    MKIniLine *var_r28_288;
    MKIniLine *var_r28_326;
    TotemPolePiece *temp_r3_297;
    s32 temp_r29_230;
    s32 var_r29_245;
    s32 var_r29_286;
    s32 var_r29_324;
    s32 var_r29_355;
    s32 var_r30_246;
    s32 var_r30_287;
    s32 var_r30_325;
    void *var_r3_238;

    if (GameProp::LoadLine(arg0) != 0) {
        return 1;
    }
    if (arg0->IsField("Pieces") != 0) {
        this->unkE0 = M2C_FIELD(&MKProp::loadInfo, f64 *, 0x40);
        this->unkE8 = M2C_FIELD(&MKProp::loadInfo, f64 *, 0x48);
        this->unkDC = M2C_FIELD(&MKProp::loadInfo, f32 *, 0x54);
        this->unkCC = arg0->GetNmbrOfSubLines();
        temp_r3_227 = arg0->unkC->GetSubLine(arg0);
        var_r28_229 = temp_r3_227;
        temp_r29_230 = this->unkCC * 4;
        temp_r3_231 = temp_r3_227->Current();
        if (temp_r3_231 != NULL) {
            var_r3_238 = ((MKHeap *) (temp_r3_231->Current()))->Alloc(temp_r29_230, NULL, 0);
        } else {
            var_r3_238 = malloc(temp_r29_230);
        }
        this->unkC8 = var_r3_238;
        var_r29_245 = 0;
        var_r30_246 = 0;
loop_8:
        if (var_r29_245 < (s32) this->unkCC) {
            var_r28_229->AsString(1, &sp10);
            *(this->unkC8 + var_r30_246) = checked_cast<TotemPolePiece *, MKProp>(gMK->CreateProp(sp10));
            M2C_FIELD(*(this->unkC8 + var_r30_246), f32 *, 0xE0) = (f32) this->unkDC;
            var_r28_229 = var_r28_229->unkC->GetNextLine(var_r28_229);
            var_r29_245 += 1;
            var_r30_246 += 4;
            goto loop_8;
        }
        return 1;
    }
    if (arg0->IsField("InitialPieceStates") != 0) {
        var_r29_286 = 0;
        var_r30_287 = 0;
        var_r28_288 = arg0->unkC->GetSubLine(arg0);
loop_13:
        if (var_r29_286 < (s32) this->unkCC) {
            var_r28_288->AsInt(0, &spC);
            temp_r3_297 = *(this->unkC8 + var_r30_287);
            temp_r3_297->unkD4 = spC;
            temp_r3_297->SetDesiredYaw(temp_r3_297->unkD0);
            var_r28_288 = var_r28_288->unkC->GetNextLine(var_r28_288);
            var_r29_286 += 1;
            var_r30_287 += 4;
            goto loop_13;
        }
        return 1;
    }
    if (arg0->IsField("DesiredPieceStates") != 0) {
        var_r29_324 = 0;
        var_r30_325 = 0;
        var_r28_326 = arg0->unkC->GetSubLine(arg0);
loop_18:
        if (var_r29_324 < (s32) this->unkCC) {
            var_r28_326->AsInt(0, &sp8);
            M2C_FIELD(*(this->unkC8 + var_r30_325), s32 *, 0xD0) = sp8;
            var_r28_326 = var_r28_326->unkC->GetNextLine(var_r28_326);
            var_r29_324 += 1;
            var_r30_325 += 4;
            goto loop_18;
        }
        return 1;
    }
    var_r29_355 = 0;
    if ((arg0->LoadFloat("PieceHeight", &this->unkD0, 0) != 0) || (this->unkD4.LoadLine(arg0, "OnComplete") != 0)) {
        var_r29_355 = 1;
    }
    return var_r29_355;
}
#endif

void TotemPolePuzzle::Init() {
    GameProp::Init();
    this->unkC8 = NULL;
    this->unkCC = 0;
    this->unkD0 = 200.0f;
    this->unkD8 = 0;
}

void TotemPolePiece::SetDesiredYaw(int arg0) {
    switch (arg0) {                                 /* irregular */
    case 0:
        this->unkD8 = this->unkE0;
        return;
    case 2:
        this->unkD8 = 3.1415927f + this->unkE0;
        return;
    case 3:
        this->unkD8 = 4.712389f + this->unkE0;
        return;
    case 1:
        this->unkD8 = 1.5707964f + this->unkE0;
        return;
    }
}

#if 0 // DRAFT: undefined identifier 'unkC8'
void TotemPolePiece::Deinit() {
    this->unkC8.UnregisterTargetable();
    GameProp::Deinit();
}
#endif

#if 0 // DRAFT: type mismatch
void TotemPolePiece::Message(MKMessage *arg0) {
    AssaultCannon ***temp_r5_475;
    AssaultCannon **temp_r3_497;
    AssaultCannon **temp_r3_501;
    AssaultCannon **var_r3_478;
    AssaultCannon *temp_r0_487;
    TotemPolePiece *var_r0_521;
    s32 temp_r0_467;
    s32 temp_r0_510;
    void *temp_r3_519;

    temp_r0_467 = arg0->unk0;
    switch (temp_r0_467) {                          /* irregular */
    case 0x4:
        temp_r5_475 = arg0->unk34;
        if (temp_r5_475 != NULL) {
            var_r3_478 = *temp_r5_475;
loop_9:
            temp_r0_487 = *var_r3_478;
            if (temp_r0_487 == NULL) {
                var_r3_478 = NULL;
            } else if (temp_r0_487 == this) {

            } else {
                var_r3_478 += 4;
                goto loop_9;
            }
            if (var_r3_478 == NULL) {
                goto block_12;
            }
        } else {
block_12:
            if (temp_r5_475 != NULL) {
                temp_r3_497 = *temp_r5_475;
                if ((u32) M2C_FIELD(temp_r3_497, u32 *, -4) != 0U) {
                    temp_r3_501 = temp_r3_497 - 4;
                    *temp_r5_475 = temp_r3_501;
                    *temp_r3_501 = (AssaultCannon *) this;
                }
            }
            this->unkD8 += 1.5707964f;
            temp_r0_510 = this->unkD4 + 1;
            this->unkD4 = temp_r0_510;
            if (temp_r0_510 == 4) {
                this->unkD4 = 0;
            }
        default:
            GameProp::Message(arg0);
        }
        return;
    case 0x8E:
        temp_r3_519 = checked_cast<GetTargetableMsg *, MKMessage>(arg0);
        var_r0_521 = this;
        if (this != NULL) {
            var_r0_521 = (TotemPolePiece *) &this->unkC8;
        }
        M2C_FIELD(temp_r3_519, TotemPolePiece **, 8) = var_r0_521;
        return;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC8'
void TotemPolePiece::Resolve() {
    this->unkC8.RegisterTargetable();
}
#endif

void TotemPolePiece::Draw() {
    GameProp::Draw();
}

#if 0 // DRAFT: undefined identifier 'arg_spC'
void TotemPolePiece::Update() {
    f32 temp_f2_589;
    f32 temp_f2_593;
    f32 temp_f2_598;
    f32 temp_f4_590;
    f32 var_f1_599;
    f32 var_f3_582;
    void *temp_r3_626;
    GameProp::Update();
    var_f3_582 = 0.5f * (1.5f * gUpdateTimeDelta);
    if (var_f3_582 < 1.0f) {

    } else {
        var_f3_582 = 1.0f;
    }
    temp_f2_589 = this->unkDC;
    temp_f4_590 = this->unkD8;
    temp_f2_593 = (var_f3_582 * (temp_f4_590 - temp_f2_589)) + temp_f2_589;
    this->unkDC = (var_f3_582 * (temp_f4_590 - temp_f2_593)) + temp_f2_593;
    temp_f2_598 = this->unkD8;
    var_f1_599 = this->unkDC - temp_f2_598;
    if (var_f1_599 < 0.0f) {
        var_f1_599 = -var_f1_599;
    }
    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
    if (var_f1_599 == 0.000001f) {
        this->unkDC = temp_f2_598;
    }
    M2C_STRUCT_COPY((s32) &arg_spC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    arg_sp10.RotateYaw((Matrix *) &arg_sp10, this->unkDC);
    temp_r3_626 = this->unk8;
    arg_sp40 = M2C_FIELD(temp_r3_626, f32 *, 0x30);
    arg_sp44 = M2C_FIELD(temp_r3_626, f32 *, 0x34);
    arg_sp48 = M2C_FIELD(temp_r3_626, f32 *, 0x38);
    arg_sp4C = 1.0f;
    MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &arg_sp10));
}
#endif

void TotemPolePiece::Init() {
    GameProp::Init();
    this->unkD0 = 4;
    this->unkD4 = 0;
    this->unkDC = 0.0f;
    this->unkD8 = 0.0f;
}
