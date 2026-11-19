#include "spyro/source/TrainController.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "spyro/source/SteamTrain.h"
#include "spyro/source/SteamTrainCaboose.h"
#include "spyro/source/TrainChaseSpyro.h"
#include "unplaced_templates.h"
#include "common/Source/Str.h"
#include <m2c_macros.h>

s32 stricmp(s8 *, s8 *);                            /* extern */
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern void **gMK;
extern f32 gUpdateTimeDelta;

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKSceneManager'
void TrainController::SetStage(int arg0) {
    SteamTrain *temp_r3_74;
    u32 var_r4_61;
    u64 temp_ret_65;
    void *temp_r3_61;
    void *temp_ret_61;

    this->unk5C = (u32) arg0;
    temp_ret_61 = checked_cast<TrainChaseSpyro *, MKProp>(this->unk58->PropResolver_Resolve(arg0));
    temp_r3_61 = temp_ret_61;
    var_r4_61 = (u32) (u64) temp_ret_61;
    if (temp_r3_61 != NULL) {
        temp_ret_65 = checked_cast<TrainControllerDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        var_r4_61 = (u32) temp_ret_65;
        M2C_FIELD(temp_r3_61, f32 *, 0xDC) = (f32) M2C_FIELD((temp_ret_65 + (this->unk5C * 0xC)), f32 *, 0x60);
    }
    temp_r3_74 = checked_cast<SteamTrain *, MKProp>(this->unk50->PropResolver_Resolve((s32) var_r4_61));
    if (temp_r3_74 != NULL) {
        temp_r3_74->unk108 = M2C_FIELD((checked_cast<TrainControllerDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (this->unk5C * 0xC)), f32 *, 0x64);
    }
    this->unk60 = 0.0f;
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKSceneManager'
void TrainController::Message(MKMessage *arg0) {
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
    SteamTrain *temp_r3_306;
    SteamTrain *temp_r3_334;
    SteamTrain *temp_r3_402;
    SteamTrain *temp_r3_411;
    s32 temp_r0_104;
    u32 var_r4_166;
    u32 var_r4_180;
    u32 var_r4_194;
    u32 var_r4_227;
    u32 var_r4_241;
    u32 var_r4_255;
    u32 var_r4_369;
    void *temp_r3_166;
    void *temp_r3_180;
    void *temp_r3_194;
    void *temp_r3_208;
    void *temp_r3_227;
    void *temp_r3_241;
    void *temp_r3_255;
    void *temp_r3_269;
    void *temp_r3_355;
    void *temp_r3_369;
    void *temp_r3_379;
    void *temp_r3_390;
    void *temp_r3_419;
    void *temp_ret_166;
    void *temp_ret_180;
    void *temp_ret_194;
    void *temp_ret_227;
    void *temp_ret_241;
    void *temp_ret_255;
    void *temp_ret_369;

    MKProp::Message(arg0);
    temp_r0_104 = arg0->unk0;
    switch (temp_r0_104) {                          /* irregular */
    case 0xB5:
        Enable();
        temp_ret_166 = this->unk50->PropResolver_Resolve((s32) (u32) Reset());
        temp_r3_166 = temp_ret_166;
        var_r4_166 = (u32) (u64) temp_ret_166;
        if (temp_r3_166 != NULL) {
            sp4C = 0;
            sp48 = 0xB5;
            var_r4_166 = (u32) M2C_FIELD(M2C_FIELD(temp_r3_166, void **, 0x44), u64 (**)(s32 *), 0x2C)(&sp48);
        }
        temp_ret_180 = this->unk4C->PropResolver_Resolve((s32) var_r4_166);
        temp_r3_180 = temp_ret_180;
        var_r4_180 = (u32) (u64) temp_ret_180;
        if (temp_r3_180 != NULL) {
            sp44 = 0;
            sp40 = 0xB5;
            var_r4_180 = (u32) M2C_FIELD(M2C_FIELD(temp_r3_180, void **, 0x44), u64 (**)(s32 *), 0x2C)(&sp40);
        }
        temp_ret_194 = this->unk54->PropResolver_Resolve((s32) var_r4_180);
        temp_r3_194 = temp_ret_194;
        var_r4_194 = (u32) (u64) temp_ret_194;
        if (temp_r3_194 != NULL) {
            sp3C = 0;
            sp38 = 0xB5;
            var_r4_194 = (u32) M2C_FIELD(M2C_FIELD(temp_r3_194, void **, 0x44), u64 (**)(s32 *), 0x2C)(&sp38);
        }
        temp_r3_208 = this->unk58->PropResolver_Resolve((s32) var_r4_194);
        if (temp_r3_208 != NULL) {
            sp34 = 0;
            sp30 = 0xB5;
            M2C_FIELD(M2C_FIELD(temp_r3_208, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp30);
        }
        this->unk68.Send((MKProp *) this);
        return;
    case 0xB4:
        temp_ret_227 = this->unk50->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */));
        temp_r3_227 = temp_ret_227;
        var_r4_227 = (u32) (u64) temp_ret_227;
        if (temp_r3_227 != NULL) {
            sp2C = 0;
            sp28 = 0xB4;
            var_r4_227 = (u32) M2C_FIELD(M2C_FIELD(temp_r3_227, void **, 0x44), u64 (**)(s32 *), 0x2C)(&sp28);
        }
        temp_ret_241 = this->unk4C->PropResolver_Resolve((s32) var_r4_227);
        temp_r3_241 = temp_ret_241;
        var_r4_241 = (u32) (u64) temp_ret_241;
        if (temp_r3_241 != NULL) {
            sp24 = 0;
            sp20 = 0xB4;
            var_r4_241 = (u32) M2C_FIELD(M2C_FIELD(temp_r3_241, void **, 0x44), u64 (**)(s32 *), 0x2C)(&sp20);
        }
        temp_ret_255 = this->unk54->PropResolver_Resolve((s32) var_r4_241);
        temp_r3_255 = temp_ret_255;
        var_r4_255 = (u32) (u64) temp_ret_255;
        if (temp_r3_255 != NULL) {
            sp1C = 0;
            sp18 = 0xB4;
            var_r4_255 = (u32) M2C_FIELD(M2C_FIELD(temp_r3_255, void **, 0x44), u64 (**)(s32 *), 0x2C)(&sp18);
        }
        temp_r3_269 = this->unk58->PropResolver_Resolve((s32) var_r4_255);
        if (temp_r3_269 != NULL) {
            sp14 = 0;
            sp10 = 0xB4;
            M2C_FIELD(M2C_FIELD(temp_r3_269, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp10);
        }
        Disable();
        return;
    case 0x138:
        SetStage(0);
        return;
    case 0x139:
        SetStage(1);
        return;
    case 0x13A:
        SetStage(2);
        return;
    case 0x13B:
        temp_r3_306 = checked_cast<SteamTrain *, MKProp>(this->unk50->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */)));
        if (temp_r3_306 != NULL) {
            M2C_FIELD(temp_r3_306, s8 *, 0x131) = 0;
        }
        SetStage(3);
        return;
    case 0x13C:
        SetStage(4);
        return;
    case 0x13D:
        SetStage(5);
        return;
    case 0x13E:
        SetStage(6);
        return;
    case 0x13F:
        temp_r3_334 = checked_cast<SteamTrain *, MKProp>(this->unk50->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */)));
        if (temp_r3_334 != NULL) {
            temp_r3_334->Stop(0U);
        }
        SetStage(7);
        return;
    case 0x140:
        this->unk64.Send((MKProp *) this);
        return;
    case 0x148:
        this->unk6C = 1;
        return;
    case 0x149:
        temp_r3_355 = this->unk58->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */));
        if (temp_r3_355 != NULL) {
            M2C_FIELD(M2C_FIELD(temp_r3_355, void **, 0x44), M2C_UNK (**)(MKMessage *), 0x2C)(arg0);
        }
        this->unk6C = 0;
        return;
    case 0x14A:
        temp_ret_369 = this->unk50->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */));
        temp_r3_369 = temp_ret_369;
        var_r4_369 = (u32) (u64) temp_ret_369;
        if (temp_r3_369 != NULL) {
            var_r4_369 = (u32) M2C_FIELD(M2C_FIELD(temp_r3_369, void **, 0x44), u64 (**)(MKMessage *), 0x2C)(arg0);
        }
        temp_r3_379 = this->unk58->PropResolver_Resolve((s32) var_r4_369);
        if (temp_r3_379 != NULL) {
            M2C_FIELD(M2C_FIELD(temp_r3_379, void **, 0x44), M2C_UNK (**)(MKMessage *), 0x2C)(arg0);
            return;
        }
        return;
    case 0x14B:
        temp_r3_390 = this->unk58->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */));
        if (temp_r3_390 != NULL) {
            M2C_FIELD(M2C_FIELD(temp_r3_390, void **, 0x44), M2C_UNK (**)(MKMessage *), 0x2C)(arg0);
            return;
        }
        break;
    case 0x142:
        temp_r3_402 = checked_cast<SteamTrain *, MKProp>(this->unk50->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */)));
        if (temp_r3_402 != NULL) {
            M2C_FIELD(temp_r3_402, s8 *, 0x131) = 1;
            return;
        }
        break;
    case 0x141:
        temp_r3_411 = checked_cast<SteamTrain *, MKProp>(this->unk50->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */)));
        if (temp_r3_411 != NULL) {
            temp_r3_411->Stop(1U);
            return;
        }
        break;
    case 0x143:
        temp_r3_419 = this->unk58->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */));
        if (temp_r3_419 != NULL) {
            sp54 = 0;
            sp50 = 0x148;
            M2C_FIELD(M2C_FIELD(temp_r3_419, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp50);
            return;
        }
        break;
    case 0x1C:
        spC = 0;
        sp8 = 0xB4;
        Message(&sp8);
        break;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'TrainControllerDescriptor *' to
void TrainController::Update() {
    SteamTrainCaboose *temp_r3_482;
    u64 temp_ret_471;

    MKProp::Update();
    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
    if (M2C_FIELD((checked_cast<TrainControllerDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (this->unk5C * 0xC)), f32 *, 0x68) == 0.0f) {
        temp_ret_471 = checked_cast<TrainControllerDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (this->unk60 == M2C_FIELD((temp_ret_471 + (this->unk5C * 0xC)), f32 *, 0x68)) {
            temp_r3_482 = checked_cast<SteamTrainCaboose *, MKProp>(this->unk54->PropResolver_Resolve((s32) (u32) temp_ret_471));
            if ((temp_r3_482 != NULL) && (temp_r3_482->IsBlownUp() == 0)) {
                temp_r3_482->BlowUp();
            }
        }
    }
    this->unk60 += gUpdateTimeDelta;
}
#endif

#if 0 // DRAFT: expression syntax error
void TrainController::Reset() {
    s32 spC;
    s32 sp8;
    SteamTrain *temp_r3_532;
    u32 var_r4_522;
    u8 temp_ret_517;
    void *temp_r3_522;
    void *temp_ret_522;

    MKProp::Reset();
    temp_ret_517 = M2C_FIELD(*gMK, u8 (**)(void **, TrainController *, s32), 0x9C)(gMK, this, MKResource::sWorkingChunkID.unk0);
    if (temp_ret_517 != 0) {
        temp_ret_522 = checked_cast<TrainChaseSpyro *, MKProp>(this->unk58->PropResolver_Resolve((s32) (u32) (u64) temp_ret_517));
        temp_r3_522 = temp_ret_522;
        var_r4_522 = (u32) (u64) temp_ret_522;
        if (temp_r3_522 != NULL) {
            var_r4_522 = (u32) M2C_FIELD(M2C_FIELD(temp_r3_522, void **, 0x44), u64 (**)(), 0x20)();
        }
        temp_r3_532 = checked_cast<SteamTrain *, MKProp>(this->unk50->PropResolver_Resolve((s32) var_r4_522));
        if (temp_r3_532 != NULL) {
            M2C_FIELD(temp_r3_532->__vptr, M2C_UNK (**)(), 0x20)();
        }
        SetStage(0);
        spC = 0;
        sp8 = 0xD5;
        M2C_FIELD(*gMK, M2C_UNK (**)(void **, s32 *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, f32), 0x94)(gMK, &sp8, 0x40000, 1, 0, 1, 0.0f);
    }
    this->unk6C = 0;
}
#endif

#if 0 // DRAFT: function call 'Disable(MKProp *, void *)' does not match
void TrainController::LoadDone() {
    void *temp_r4_577;

    MKProp::LoadDone();
    temp_r4_577 = this->unk0;
    M2C_FIELD(temp_r4_577, s32 *, 0xC) = (s32) (M2C_FIELD(temp_r4_577, s32 *, 0xC) | 0x20);
    Disable(temp_r4_577);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
s32 TrainController::LoadLine(MKIniLine *arg0) {
    s32 var_r31_602;

    var_r31_602 = 0;
    if ((MKProp::LoadLine(arg0) != 0) || (arg0->LoadInt("trackID", (s32 *) &this->unk4C, 0) != 0) || (arg0->LoadInt("trainID", (s32 *) &this->unk50, 0) != 0) || (arg0->LoadInt("cabooseID", (s32 *) &this->unk54, 0) != 0) || (arg0->LoadInt("spyroCartID", (s32 *) &this->unk58, 0) != 0) || (this->unk64.LoadLine(arg0, "OnFinish") != 0) || (this->unk68.LoadLine(arg0, "OnReset") != 0)) {
        var_r31_602 = 1;
    }
    return var_r31_602;
}
#endif

void TrainController::Init() {
    MKProp::Init();
    this->unk5C = 0;
    this->unk60 = 0.0f;
    this->unk4C = NULL;
    this->unk50 = NULL;
    this->unk54 = NULL;
    this->unk58 = NULL;
    this->unk6C = 0;
}

#if 0 // DRAFT: function call 'stricmp(const char[14])' does not match
s32 TrainControllerDescriptor::LoadLine(MKIniLine *arg0) {
    MKIniLine *temp_ret_789;
    MKIniLine *var_r22_726;
    MKIniLine *var_r28_701;
    f32 temp_f1_789;
    s32 var_r26_718;
    s32 var_r30_716;
    s8 *temp_r21_735;
    u8 var_r29_719;
    void *temp_r4_725;

    var_r28_701 = arg0;
    if (MKPropDescriptor::LoadLine(arg0) != 0) {
        return 1;
    }
    if (var_r28_701->IsField("Stage_01") != 0) {
        var_r30_716 = 0;
        var_r26_718 = 0;
        var_r29_719 = 0;
loop_15:
        if (var_r29_719 == 0) {
            temp_r4_725 = this + var_r26_718;
            var_r22_726 = var_r28_701->unkC->GetSubLine(var_r28_701);
loop_12:
            if (var_r22_726 != NULL) {
                temp_r21_735 = var_r22_726->GetFieldName();
                if (stricmp("SpyroMaxSpeed") == 0) {
                    var_r22_726->AsFloat(0, temp_r4_725 + 0x60);
                    M2C_FIELD(temp_r4_725, f32 *, 0x60) = (f32) (M2C_FIELD(temp_r4_725, f32 *, 0x60) * 100.0f);
                } else if (stricmp(temp_r21_735, "TrainMaxSpeed") == 0) {
                    var_r22_726->AsFloat(0, temp_r4_725 + 0x64);
                    M2C_FIELD(temp_r4_725, f32 *, 0x64) = (f32) (M2C_FIELD(temp_r4_725, f32 *, 0x64) * 100.0f);
                } else if (stricmp(temp_r21_735, "DestroyCaboose") == 0) {
                    var_r22_726->AsFloat(0, temp_r4_725 + 0x68);
                }
                var_r22_726 = var_r22_726->unkC->GetNextLine(var_r22_726);
                goto loop_12;
            }
            var_r30_716 += 1;
            var_r26_718 += 0xC;
            temp_ret_789 = var_r28_701->unkC->GetNextLine(var_r28_701);
            temp_f1_789 = M2C_BITWISE(f32, temp_ret_789);
            var_r28_701 = temp_ret_789;
            if (var_r28_701->IsField(Str_Printf("Stage_%02d", var_r30_716 + 1, temp_f1_789)) == 0) {
                var_r29_719 = 1;
            }
            goto loop_15;
        }
        return 1;
    }
    return 0;
}
#endif

void TrainControllerDescriptor::Init() {
    s32 var_ctr_829;
    s32 var_r3_828;
    void *temp_r4_831;

    MKPropDescriptor::Init();
    var_r3_828 = 0;
    var_ctr_829 = 8;
    do {
        temp_r4_831 = this + var_r3_828;
        var_r3_828 += 0xC;
        M2C_FIELD(temp_r4_831, f32 *, 0x60) = 1.0f;
        M2C_FIELD(temp_r4_831, f32 *, 0x64) = 1.0f;
        M2C_FIELD(temp_r4_831, f32 *, 0x68) = -1.0f;
        var_ctr_829 -= 1;
    } while (var_ctr_829 != 0);
}

void TrainController_cpp::__sinit() {
    f32 temp_f0_891;
    f64 temp_f1_872;
    f64 temp_f1_880;
    f64 temp_f3_860;
    f64 temp_f4_869;
    f64 temp_f4_877;
    f64 temp_f8_862;

    temp_f3_860 = __frsqrte(2014000.0);
    temp_f8_862 = __frsqrte(380000.0);
    temp_f4_869 = 0.5 * temp_f3_860 * -((2014000.0 * (temp_f3_860 * temp_f3_860)) - 3.0);
    temp_f1_872 = 0.5 * temp_f8_862 * -((380000.0 * (temp_f8_862 * temp_f8_862)) - 3.0);
    temp_f4_877 = 0.5 * temp_f4_869 * -((2014000.0 * (temp_f4_869 * temp_f4_869)) - 3.0);
    temp_f1_880 = 0.5 * temp_f1_872 * -((380000.0 * (temp_f1_872 * temp_f1_872)) - 3.0);
    temp_f0_891 = (f32) (380000.0 * (0.5 * temp_f1_880 * -((380000.0 * (temp_f1_880 * temp_f1_880)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_877 * -((2014000.0 * (temp_f4_877 * temp_f4_877)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_891;
}
