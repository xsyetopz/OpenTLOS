#include "spyro/source/ElementalCombatController.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/EnemySpawner.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/SpawnPointData.h"
#include "spyro/source/SpawnPointObject.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

M2C_UNK __destroy_arr(s32 *, EventMessage *(*)(EventMessage *, s16), M2C_UNK, M2C_UNK); /* extern */
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern f32 gUpdateTimeDelta;
extern s32 gb;

void ElementalCombatController::AttemptSpawn() {
    s32 temp_r3_84;

    if (((u8) this->unkC8.unk4C >> 7U) & 1) {
        this->unkC8.FunctionOn();
        this->unkC8.unk38 = M2C_FIELD(&gb, f32 *, 0x30C) - 1.0f;
        temp_r3_84 = this->unk3DC.unk0;
        switch (temp_r3_84) {                       /* irregular */
        case 0x8000000:
            this->unkC8.TrySpawnItems(7, 0U);
            break;
        case 0x20000000:
            this->unkC8.TrySpawnItems(0xA, 0U);
            break;
        case 0x10000000:
            this->unkC8.TrySpawnItems(1, 0U);
            break;
        case 0x40000000:
            this->unkC8.TrySpawnItems(4, 0U);
            break;
        }
        this->unkC8.FunctionOff();
    }
}

#if 0 // DRAFT: illegal use of abstract class ('HeroInterface::pure_slot0()')
void ElementalCombatController::SetupSpawnPoints() {
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    HeroInterface sp8;
    Matrix *temp_r25_183;
    s32 var_r29_153;
    s32 var_r31_151;
    void *temp_r24_155;
    void *temp_r26_159;
    void *temp_r3_200;
    void *temp_r4_163;

    var_r31_151 = 0;
    var_r29_153 = 0;
    temp_r24_155 = M2C_FIELD(M2C_FIELD((this + (this->unk3E0 * 4)), void **, 0x360), void **, 0x54);
loop_2:
    temp_r3_200 = M2C_FIELD(temp_r24_155, void **, 0x18);
    if (var_r31_151 < (s32) M2C_FIELD(temp_r3_200, s32 *, 0x20)) {
        temp_r26_159 = this + var_r29_153;
        temp_r4_163 = M2C_FIELD(temp_r3_200, s32 *, 0x24) + (var_r31_151 * M2C_FIELD(temp_r3_200, s32 *, 0x1C));
        sp28 = M2C_FIELD(temp_r4_163, f64 *, 0);
        sp30 = M2C_FIELD(temp_r4_163, f64 *, 8);
        M2C_FIELD(M2C_FIELD(temp_r26_159, void **, 0x124), s32 *, 4) = (s32) (this->unk3DC.unk0 | 0x4200);
        sp8.GetPos();
        sp18 = M2C_BITWISE(f64, sp8);
        sp20 = sp8.unk8;
        unksp1C = unksp2C;
        this->unkC8.AddSpawnPoint(temp_r26_159 + 0x120);
        temp_r25_183 = temp_r26_159 + 0x130;
        temp_r25_183->SetIdentity();
        M2C_FIELD(temp_r26_159, f32 *, 0x160) = (f32) sp28;
        M2C_FIELD(temp_r26_159, f32 *, 0x164) = unksp2C;
        M2C_FIELD(temp_r26_159, f32 *, 0x168) = (f32) sp30;
        M2C_FIELD(temp_r26_159, f32 *, 0x16C) = 1.0f;
        temp_r25_183->SetLookAt(*((MKVector3 *) &sp28), *((MKVector3 *) &sp18));
        var_r31_151 += 1;
        var_r29_153 += 0x60;
        goto loop_2;
    }
    this->unkC8.AddSpawnPointEnd();
}
#endif

void ElementalCombatController::Update() {
    s32 temp_r3_240;

    MKProp::Update();
    if ((u8) M2C_FIELD(this, u8 *, 0x3E8) != 0) {
        this->unkC8.GetNumberActive();
        if ((s32) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
            this->unk3EC += gUpdateTimeDelta;
            M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
            if (this->unk3EC == M2C_FIELD(this, f32 *, 0x3EC)) {
                temp_r3_240 = this->unk3E0;
                if (temp_r3_240 > 0) {
                    ((EventMessage *) (this + (((temp_r3_240 - 1) * 4) + 0x3A0)))->Send((MKProp *) this);
                }
                if ((u32) M2C_FIELD((this + (this->unk3E0 * 4)), u32 *, 0x360) != 0U) {
                    this->unkC8.RemoveAllSpawnPoints(0U);
                    SetupSpawnPoints();
                    AttemptSpawn();
                } else {
                    this->unk3E0 = 0;
                    M2C_FIELD(this, u8 *, 0x3E8) = 0U;
                    this->unkB0.Send((MKProp *) this);
                }
                this->unk3E0 += 1;
                if ((s32) this->unk3E0 >= 0x10) {
                    M2C_FIELD(this, u8 *, 0x3E8) = 0U;
                    this->unk3E0 = 0;
                }
            }
        } else {
            this->unk3EC = 0.0f;
        }
    }
}

#if 0 // DRAFT: undefined identifier 'zero'
void ElementalCombatController::Message(MKMessage *arg0) {
    s8 sp2A;
    s8 sp29;
    s8 sp28;
    s8 sp24;
    f32 sp20;
    f64 sp18;
    f64 sp10;
    s32 spC;
    s32 sp8;
    s32 temp_r0_302;
    u8 var_r0_313;

    temp_r0_302 = arg0->unk0;
    switch (temp_r0_302) {                          /* irregular */
    case 0xB5:
        M2C_FIELD(this, s8 *, 0x3E8) = 1;
        var_r0_313 = 0;
        this->unk3E0 = 0;
        if ((this->unkB8 == zero.unk0) && (this->unkBC == zero.unk4) && (this->unkC0 == zero.unk8)) {
            var_r0_313 = 1;
        }
        if (var_r0_313 == 0) {
            spC = 0;
            sp8 = 0xE;
            sp29 = 1;
            sp10 = (f64) M2C_FIELD(this, f32 *, 0xB8);
            sp18 = (f64) M2C_FIELD(this, f32 *, 0xC0);
            sp20 = 0.0f;
            sp24 = 0;
            sp28 = 0;
            sp2A = 1;
            sp29 = 1;
            gb.GetSpyro();
            M2C_FIELD(M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), void **, 0x44), M2C_UNK (**)(), 0x2C)();
        }
        break;
    case 0xB4:
        M2C_FIELD(this, s8 *, 0x3E8) = 0;
        break;
    }
    MKProp::Message(arg0);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'ElementalCombatController' to
void ElementalCombatController::Resolve() {
    MKSceneManager *temp_r3_382;
    s32 temp_r30_381;
    s32 var_r29_378;
    s32 var_r31_379;

    var_r29_378 = 0;
    var_r31_379 = 0;
    do {
        temp_r30_381 = var_r31_379 + 0x360;
        temp_r3_382 = *(this + temp_r30_381);
        if (temp_r3_382 != NULL) {
            *(this + temp_r30_381) = checked_cast<SpawnPoint *, MKProp>(temp_r3_382->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */)));
        }
        var_r29_378 += 1;
        var_r31_379 += 4;
    } while (var_r29_378 < 0x10);
    MKProp::Resolve();
}
#endif

#if 0 // DRAFT: undefined identifier 'unk90'
void ElementalCombatController::LoadDone() {
    s32 temp_r0_440;
    s32 var_r30_430;
    s32 var_r31_431;

    this->unk98 = 1.0f;
    this->unk94 = 1.0f;
    M2C_FIELD(this, f32 *, 0x90) = 1.0f;
    this->unkA8 = -1.0f;
    this->unkA4 = -1.0f;
    this->unkA0 = -1.0f;
    M2C_FIELD(this->unk0, M2C_UNK **, 0x1C) = &this->unk90;
    this->unkC8.LoadDone(0, 6, 0U, (u32) this->unk18);
    this->unkC8.AddSpawnPointBegin(6);
    var_r30_430 = 0;
    var_r31_431 = 0;
    do {
        ((SpawnPointObject *) (this + (var_r31_431 + 0x120)))->LoadDone();
        var_r30_430 += 1;
        var_r31_431 += 0x60;
    } while (var_r30_430 < 6);
    temp_r0_440 = this->unk3DC.unk0;
    switch (temp_r0_440) {                          /* irregular */
    case 0:
        this->unk3DC.unk0 = 0x08000000;
        break;
    case 1:
        this->unk3DC.unk0 = 0x20000000;
        break;
    case 2:
        this->unk3DC.unk0 = 0x10000000;
        break;
    case 3:
        this->unk3DC.unk0 = 0x40000000;
        break;
    }
    MKProp::LoadDone();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
s32 ElementalCombatController::LoadLine(MKIniLine *arg0) {
    if (MKProp::LoadLine(arg0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("Element", &this->unk3DC.unk0, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadFloat("WaveSpawnDelay", (f32 *) &this->unk3E8, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadVector3("PlayerStart", (MKVector3 *) &this->unkB8, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("SpawnPointIDWave1", &this->unk360, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("SpawnPointIDWave2", &this->unk360, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("SpawnPointIDWave3", &this->unk364, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("SpawnPointIDWave4", &this->unk368, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("SpawnPointIDWave5", &this->unk36C, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("SpawnPointIDWave6", &this->unk370, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("SpawnPointIDWave7", &this->unk374, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("SpawnPointIDWave8", &this->unk378, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("SpawnPointIDWave9", &this->unk37C, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("SpawnPointIDWave10", &this->unk380, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("SpawnPointIDWave11", &this->unk384, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("SpawnPointIDWave12", &this->unk388, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("SpawnPointIDWave13", &this->unk38C, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("SpawnPointIDWave14", &this->unk390, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("SpawnPointIDWave15", &this->unk394, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("SpawnPointIDWave16", &this->unk398, 0) != 0) {
        return 1U;
    }
    if (this->unkB0.LoadLine(arg0, "OnComplete") != 0) {
        return 1U;
    }
    if (this->unk39C.LoadLine(arg0, "OnWave1Complete") != 0) {
        return 1U;
    }
    if (this->unk3A0.LoadLine(arg0, "OnWave2Complete") != 0) {
        return 1U;
    }
    if (this->unk3A4.LoadLine(arg0, "OnWave3Complete") != 0) {
        return 1U;
    }
    if (this->unk3A8.LoadLine(arg0, "OnWave4Complete") != 0) {
        return 1U;
    }
    if (this->unk3AC.LoadLine(arg0, "OnWave5Complete") != 0) {
        return 1U;
    }
    if (this->unk3B0.LoadLine(arg0, "OnWave6Complete") != 0) {
        return 1U;
    }
    if (this->unk3B4.LoadLine(arg0, "OnWave7Complete") != 0) {
        return 1U;
    }
    if (this->unk3B8.LoadLine(arg0, "OnWave8Complete") != 0) {
        return 1U;
    }
    if (this->unk3BC.LoadLine(arg0, "OnWave9Complete") != 0) {
        return 1U;
    }
    if (this->unk3C0.LoadLine(arg0, "OnWave10Complete") != 0) {
        return 1U;
    }
    if (this->unk3C4.LoadLine(arg0, "OnWave11Complete") != 0) {
        return 1U;
    }
    if (this->unk3C8.LoadLine(arg0, "OnWave12Complete") != 0) {
        return 1U;
    }
    if (this->unk3CC.LoadLine(arg0, "OnWave13Complete") != 0) {
        return 1U;
    }
    if (this->unk3D0.LoadLine(arg0, "OnWave14Complete") != 0) {
        return 1U;
    }
    if (this->unk3D4.LoadLine(arg0, "OnWave15Complete") != 0) {
        return 1U;
    }
    return (u8) (this->unk3D8.LoadLine(arg0, "OnWave16Complete") != 0);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'ElementalCombatController' to
void ElementalCombatController::Deinit() {
    s32 temp_cr0_eq_928;
    s32 var_r30_923;
    s32 var_r31_924;
    void **temp_r3_927;

    this->unkC8.Deinit();
    var_r30_923 = 0;
    var_r31_924 = 0;
    do {
        temp_r3_927 = *(this + (var_r31_924 + 0x124));
        temp_cr0_eq_928 = temp_r3_927 == NULL;
        if ((temp_cr0_eq_928 == 0) && (temp_cr0_eq_928 == 0)) {
            M2C_FIELD(*temp_r3_927, M2C_UNK (**)(M2C_UNK), 8)(1);
        }
        var_r30_923 += 1;
        var_r31_924 += 0x60;
    } while (var_r30_923 < 6);
    MKProp::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'zero'
void ElementalCombatController::Init() {
    SpawnPointData *temp_r29_991;
    s32 temp_r0_975;
    s32 var_ctr_973;
    s32 var_r28_984;
    s32 var_r30_985;
    s32 var_r3_965;

    M2C_FIELD(this, s8 *, 0x3E8) = 0;
    M2C_FIELD(this, f32 *, 0x3EC) = 0.0f;
    var_r3_965 = 0;
    this->unk3EC = 0.0f;
    this->unk3E0 = 0;
    this->unk3DC.unk0 = 0;
    M2C_FIELD(this, f64 *, 0xB8) = (f64) M2C_FIELD(&zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 0xC0) = (f64) M2C_FIELD(&zero, f64 *, 8);
    var_ctr_973 = 0x10;
    do {
        temp_r0_975 = var_r3_965 + 0x360;
        var_r3_965 += 4;
        *(this + temp_r0_975) = 0;
        var_ctr_973 -= 1;
    } while (var_ctr_973 != 0);
    this->unkC8.Init(EnemySpawnPool_Action, 0);
    var_r28_984 = 0;
    var_r30_985 = 0;
    do {
        operator new(0x28U, NULL, 0);
        temp_r29_991 = M2C_ERROR(/* Read from unset register $r3 */);
        if (temp_r29_991 != NULL) {
            temp_r29_991->__vptr = &__vt;
            temp_r29_991->__vptr = &__vt;
            M2C_FIELD(temp_r29_991, s32 *, 8) = 0;
            ((EventMessage *) (temp_r29_991 + 8))->Init();
            M2C_FIELD(temp_r29_991, s32 *, 0xC) = 0;
            ((EventMessage *) (temp_r29_991 + 0xC))->Init();
            M2C_FIELD(temp_r29_991, s32 *, 0x10) = 0;
            ((EventMessage *) (temp_r29_991 + 0x10))->Init();
            M2C_FIELD(temp_r29_991, s32 *, 0x14) = 0;
            ((EventMessage *) (temp_r29_991 + 0x14))->Init();
        }
        ((SpawnPointObject *) (this + (var_r30_985 + 0x120)))->Init(temp_r29_991);
        var_r28_984 += 1;
        var_r30_985 += 0x60;
    } while (var_r28_984 < 6);
    MKProp::Init();
}
#endif

void ElementalCombatController_cpp::__sinit() {
    f32 temp_f0_1068;
    f64 temp_f1_1049;
    f64 temp_f1_1057;
    f64 temp_f3_1037;
    f64 temp_f4_1046;
    f64 temp_f4_1054;
    f64 temp_f8_1039;

    temp_f3_1037 = __frsqrte(2014000.0);
    temp_f8_1039 = __frsqrte(380000.0);
    temp_f4_1046 = 0.5 * temp_f3_1037 * -((2014000.0 * (temp_f3_1037 * temp_f3_1037)) - 3.0);
    temp_f1_1049 = 0.5 * temp_f8_1039 * -((380000.0 * (temp_f8_1039 * temp_f8_1039)) - 3.0);
    temp_f4_1054 = 0.5 * temp_f4_1046 * -((2014000.0 * (temp_f4_1046 * temp_f4_1046)) - 3.0);
    temp_f1_1057 = 0.5 * temp_f1_1049 * -((380000.0 * (temp_f1_1049 * temp_f1_1049)) - 3.0);
    temp_f0_1068 = (f32) (380000.0 * (0.5 * temp_f1_1057 * -((380000.0 * (temp_f1_1057 * temp_f1_1057)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_1054 * -((2014000.0 * (temp_f4_1054 * temp_f4_1054)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_1068;
}
