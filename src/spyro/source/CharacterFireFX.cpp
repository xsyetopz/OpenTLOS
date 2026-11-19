#include "spyro/source/CharacterFireFX.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/CharacterBodyFX.h"
#include "spyro/source/Game.h"
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;

#if 0 // DRAFT: illegal use of non-static member
void CharacterFireFX::EmitFire() {
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    f32 temp_f1_56;
    f32 temp_f31_80;
    s32 var_r29_36;
    void **temp_r3_40;
    void *temp_r31_76;

    this->unk14 -= gUpdateTimeDelta;
    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
    if (this->unk14 == 0.0f) {
        this->unk14 = 0.0f;
        var_r29_36 = 0;
        do {
            temp_r3_40 = CharacterBodyFX::GetRandomNode(NULL);
            if (temp_r3_40 != NULL) {
                sp8 = 3.0f * M2C_FIELD(*temp_r3_40, f32 *, 0x10);
                temp_f1_56 = 100.0f * MKRand_Float(&gViewSeed, 0.5f, 1.0f);
                sp28 = 0.0f;
                sp20 = 0.0f;
                sp24 = temp_f1_56;
                sp48 = (f64) sp28;
                sp40 = (f64) sp20;
                gb.unk68->Emit(*(temp_r3_40 + 8), *((MKVector3 *) &sp40), sp8);
            }
            var_r29_36 += 1;
        } while (var_r29_36 < 5);
    }
    temp_r31_76 = CharacterBodyFX::GetRandomNode(NULL);
    temp_f31_80 = MKRand_Float(&gViewSeed, 1.5f, 2.5f);
    sp14 = MKRand_Float(&gViewSeed, 400.0f, 600.0f);
    sp10 = 0.0f;
    sp18 = 0.0f;
    sp30 = (f64) sp10;
    sp38 = (f64) sp18;
    gb.unk240.Emit(*(temp_r31_76 + 8), *((MKVector3 *) &sp30), temp_f31_80, 1.0f);
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void CharacterFireFX::EmitSmoke() {
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    f32 temp_f2_144;
    void **temp_r3_129;

    this->unk18 -= gUpdateTimeDelta;
    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
    if (this->unk18 == 0.0f) {
        this->unk18 = 0.1f;
        temp_r3_129 = CharacterBodyFX::GetRandomNode(NULL);
        if (temp_r3_129 != NULL) {
            sp8 = 0.5f * M2C_FIELD(*temp_r3_129, f32 *, 0x10);
            temp_f2_144 = 100.0f * MKRand_Float(&gViewSeed, 0.5f, 1.0f);
            sp18 = 0.0f;
            sp10 = 0.0f;
            sp14 = temp_f2_144;
            sp28 = (f64) sp18;
            sp20 = (f64) sp10;
            gb.EmitDust(*(temp_r3_129 + 8), *((MKVector3 *) &sp20), sp8, 0.0f);
        }
    }
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void CharacterFireFX::Enable(bool arg0, float arg1) {
    if (arg0 != 0) {
        this->unk20 = 1;
        this->unk1C = arg1;
    } else {
        this->unk20 = 0;
    }
    CharacterBodyFX::SetDataActive(arg0);
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void CharacterFireFX::Deinit() {
    CharacterBodyFX::Deinit();
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void CharacterFireFX::Update() {
    s32 temp_r0_217;

    if ((u32) this->unk8 != 0) {
        CharacterBodyFX::Update();
        this->unk1C -= gUpdateTimeDelta;
        temp_r0_217 = this->unk20;
        switch (temp_r0_217) {                      /* irregular */
        case 1:
            EmitFire();
            EmitSmoke();
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (this->unk1C == 0.0f) {
                this->unk20 = 2;
                this->unk1C = 1.0f;
                return;
            }
            break;
        case 2:
            EmitSmoke();
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (this->unk1C == 0.0f) {
                this->unk20 = 0;
                CharacterBodyFX::SetDataActive(0U);
            }
            break;
        }
    }
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void CharacterFireFX::InitData(CharacterBodyFXData *arg0, MKModel *arg1, CBFXNode *arg2) {
    if ((s32) arg0->unk4 == 0) {
        this->unk8 = 0;
        return;
    }
    CharacterBodyFX::InitData(arg0, arg1, arg2);
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void CharacterFireFX::Init() {
    CharacterBodyFX::Init();
    this->unk14 = 0.0f;
    this->unk18 = 0.0f;
    this->unk1C = 0.0f;
    this->unk20 = 0;
}
#endif
