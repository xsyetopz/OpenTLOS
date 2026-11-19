#include "spyro/source/SteamTrainCaboose.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Collectable2.h"
#include "spyro/source/EmbersPS.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/Explosion3.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/SpawnPointData.h"
#include "spyro/source/SpawnPointObject.h"
#include "spyro/source/SpawnerObject.h"
#include "spyro/source/SteamTrain.h"
#include "spyro/source/TrainTrack.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKModel.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/SpyroHud.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

M2C_UNK free(Enemy ***);                            /* extern */
Enemy ***malloc(M2C_UNK);                           /* extern */
extern s32 GS_TrainCrash;
extern s32 GS_TrainHit;
extern M2C_UNK gEmptyPtrListDL;
extern MKSceneManager *gMK;
extern s32 gViewSeed;
extern void **gb;
extern void *gpTranslation_StringArray;

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void TrainChaseSpawnPool::Destroy(Enemy *arg0) {
    s32 spC;
    s32 sp8;
    Enemy ***temp_r3_80;
    Enemy ***var_r31_59;
    Enemy **temp_r3_93;
    Enemy **temp_r4_83;

    var_r31_59 = this->unk0;
loop_4:
    if ((var_r31_59 == NULL) || (temp_r3_93 = *var_r31_59, ((temp_r3_93 == NULL) != 0))) {
        return;
    }
    if ((Enemy *) *temp_r3_93 == arg0) {
        spC = 0;
        sp8 = 0x15F;
        arg0->Message(&sp8);
        arg0->Disable();
        temp_r3_80 = this->unk0;
        this->unk0 = temp_r3_80 + 4;
        temp_r4_83 = *temp_r3_80;
        *temp_r3_80 = *var_r31_59;
        *var_r31_59 = temp_r4_83;
        return;
    }
    var_r31_59 += 4;
    goto loop_4;
}
#endif

Enemy *TrainChaseSpawnPool::Create() {
    Enemy ***temp_r4_107;
    Enemy ***temp_r4_111;

    temp_r4_107 = this->unk0;
    if ((u32) M2C_FIELD(temp_r4_107, u32 *, -4) != 0U) {
        temp_r4_111 = temp_r4_107 - 4;
        this->unk0 = temp_r4_111;
        return **temp_r4_111;
    }
    return NULL;
}

#if 0 // DRAFT: illegal operand 'TrainChaseSpawnPool *'
void TrainChaseSpawnPool::Action(SpawnAction arg0, int arg1, MKProp **arg2, SpawnerObject *arg3) {
    switch (this) {                                 /* irregular */
    case 0:
        *arg1 = ((TrainChaseSpawnPool *) (*TrainChaseSpawnPool::pInstance))->Create();
        return;
    case 1:
        *arg1 = NULL;
        return;
    case 2:
        ((TrainChaseSpawnPool *) (*TrainChaseSpawnPool::pInstance))->Destroy(*arg1);
        return;
    }
}
#endif

#if 0 // DRAFT: type mismatch
void TrainChaseSpawnPool::Deinit() {
    Enemy ***var_r31_169;
    Enemy ***var_r3_170;
    Enemy ***var_r4_168;
    Enemy **temp_r0_173;
    Enemy **temp_r0_192;
    MKHeap *temp_r3_195;
    u32 temp_r0_178;

    var_r4_168 = this->unk0;
    var_r31_169 = var_r4_168;
    var_r3_170 = var_r4_168;
loop_3:
    temp_r0_178 = M2C_FIELD(var_r3_170, u32 *, -4);
    var_r3_170 -= 4;
    if (temp_r0_178 != 0U) {
        temp_r0_173 = *var_r3_170;
        if (temp_r0_173 < var_r31_169) {
            var_r31_169 = (Enemy ***) temp_r0_173;
        }
        goto loop_3;
    }
    if (var_r3_170 != &gEmptyPtrListDL) {
loop_9:
        temp_r0_192 = *var_r4_168;
        if (temp_r0_192 != NULL) {
            if (temp_r0_192 < var_r31_169) {
                var_r31_169 = (Enemy ***) temp_r0_192;
            }
            var_r4_168 += 4;
            goto loop_9;
        }
        temp_r3_195 = var_r3_170->Current();
        if (temp_r3_195 != NULL) {
            ((MKHeap *) (temp_r3_195->Current()))->Free(var_r31_169, NULL, 0);
        } else {
            free(var_r31_169);
        }
    }
    this->unk0 = NULL;
    *TrainChaseSpawnPool::pInstance = 0;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'TrainChaseSpawnPool *' to
void TrainChaseSpawnPool::Init() {
    Enemy ***temp_r3_249;
    Enemy ***temp_r4_255;
    Enemy ***var_r30_263;
    Enemy ***var_r3_234;
    Enemy ***var_r5_243;
    Enemy **temp_r4_269;
    MKHeap *temp_r3_227;
    s32 var_ctr_247;

    *TrainChaseSpawnPool::pInstance = this;
    temp_r3_227 = MKHeap::Current();
    if (temp_r3_227 != NULL) {
        var_r3_234 = ((MKHeap *) (temp_r3_227->Current()))->Alloc(0x18, NULL, 0);
    } else {
        var_r3_234 = malloc(0x18);
    }
    this->unk0 = var_r3_234;
    var_r5_243 = this->unk0;
    this->unk0 = var_r5_243 + 8;
    M2C_FIELD(var_r5_243, s32 *, 8) = 0;
    var_ctr_247 = 2;
    do {
        temp_r3_249 = this->unk0;
        this->unk0 = temp_r3_249 + 4;
        M2C_FIELD(temp_r3_249, Enemy ****, 4) = var_r5_243;
        var_r5_243 += 4;
        var_ctr_247 -= 1;
    } while (var_ctr_247 != 0);
    temp_r4_255 = this->unk0;
    this->unk0 = temp_r4_255 + 4;
    M2C_FIELD(temp_r4_255, Enemy ****, 4) = NULL;
    var_r30_263 = this->unk0 - 4;
loop_7:
    if ((var_r30_263 != NULL) && ((Enemy **) *var_r30_263 != NULL)) {
        temp_r4_269 = *var_r30_263;
        var_r30_263 -= 4;
        *temp_r4_269 = gMK->CreateProp("CynderTier2Train_C");
        goto loop_7;
    }
}
#endif

void SteamTrainCaboose::Disable() {
    KDProp::Disable();
    M2C_FIELD(&gb, s32 *, 0x360) = 0;
    EnemyHud_Modified(NULL, 0.0f, 0.0f, 0.0f);
}

void SteamTrainCaboose::Enable() {
    f32 temp_f1_322;

    KDProp::Enable();
    M2C_FIELD(&gb, SteamTrainCaboose **, 0x360) = this;
    temp_f1_322 = this->unkDC;
    EnemyHud_Modified((MKProp *) this, temp_f1_322, temp_f1_322, 50.0f);
}

#if 0 // DRAFT: undefined identifier 'sp28'
void SteamTrainCaboose::GetVel() {
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    SteamTrain *temp_r3_345;
    void *temp_r31_341;
    void *temp_r3_376;
    void *temp_r4_348;

    temp_r31_341 = M2C_ERROR(/* Read from unset register $r4 */);
    temp_r3_345 = checked_cast<SteamTrain *, MKProp>(((MKSceneManager *) (M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), MKSceneManager **, 0xD0)))->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */)));
    if (temp_r3_345 != NULL) {
        temp_r4_348 = M2C_FIELD(temp_r31_341, void **, 8);
        sp8 = -M2C_FIELD(temp_r4_348, f32 *, 0x20);
        spC = -M2C_FIELD(temp_r4_348, f32 *, 0x24);
        sp10 = -M2C_FIELD(temp_r4_348, f32 *, 0x28);
        sp38 = (f64) sp8;
        sp40 = (f64) sp10;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        M2C_FIELD(this, f64 *, 0) = sp28;
        sp30 = (f32) sp40 * temp_r3_345->unk104;
        M2C_FIELD(this, f64 *, 8) = (f64) sp30;
        return;
    }
    temp_r3_376 = M2C_FIELD(temp_r31_341, void **, 8);
    sp18 = -M2C_FIELD(temp_r3_376, f32 *, 0x20);
    sp1C = -M2C_FIELD(temp_r3_376, f32 *, 0x24);
    sp20 = -M2C_FIELD(temp_r3_376, f32 *, 0x28);
    M2C_FIELD(this, f64 *, 0) = (f64) sp18;
    M2C_FIELD(this, f64 *, 8) = (f64) sp20;
}
#endif

void SteamTrainCaboose::SetState(SteamTrainCabooseState arg0) {
    this->unkC8 = (s32) arg0;
    this->unk80->SetAnim(M2C_FIELD((checked_cast<SteamTrainCabooseDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (this->unkC8 * 4)), MKAnim **, 0xE4), 1.0f, 0.0f, 0, -1);
}

u8 SteamTrainCaboose::IsBlownUp() {
    return this->unkD8;
}

void SteamTrainCaboose::BlowUp() {
    if ((u8) this->unkD8 == 0) {
        this->unk110.FunctionOff();
        SetState((SteamTrainCabooseState) 3);
    }
}

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void SteamTrainCaboose::Message(MKMessage *arg0) {
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
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    s32 spC;
    s32 sp8;
    Collectable2 *temp_r3_542;
    Collectable2 *temp_r3_706;
    SteamTrain *temp_r3_592;
    SteamTrain *temp_r3_628;
    f32 temp_f1_744;
    f32 temp_f29_560;
    f32 temp_f29_713;
    f32 temp_f30_554;
    f32 temp_f30_718;
    f32 temp_f31_549;
    f32 temp_f31_724;
    s32 temp_r0_475;
    s32 temp_r0_661;
    s32 temp_r30_762;
    s32 var_r27_696;
    s32 var_r28_532;
    void *temp_r4_569;
    void *temp_r4_597;
    void *temp_r4_633;
    void *temp_r4_733;

    temp_r0_475 = arg0->unk0;
    switch (temp_r0_475) {                          /* irregular */
    case 0xB5:
        this->unk110.FunctionOn();
        SetState((SteamTrainCabooseState) 1);
        Enable();
        Update();
    default:
block_34:
        GameProp::Message(arg0);
        return;
    case 0xB4:
        this->unk110.FunctionOff();
        SetState((SteamTrainCabooseState) 0);
        Disable();
        EnemyHud_Modified(NULL, 0.0f, 0.0f, 0.0f);
        goto block_34;
    case 0x5:
        var_r28_532 = 0;
        do {
            temp_r3_542 = checked_cast<Collectable2 *, MKProp>(((MKPropDescriptor *) (gMK->FindDescriptor("MagicGem2")))->CreateInstance());
            if (temp_r3_542 != NULL) {
                temp_f31_549 = MKRand_Float(&gViewSeed, 0.0f, 6.2831855f);
                temp_f30_554 = MKRand_Float(&gViewSeed, -50.0f, 50.0f);
                temp_f29_560 = MKRand_Float(&gViewSeed, 0.5f, 1.0f);
                temp_r4_569 = this->unk8;
                temp_r3_542->InitData(*((Matrix *) temp_r4_569), temp_r4_569 + 0x30, M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **), 0xC)(gb), s32 *, 8) + 0x30, temp_f29_560, temp_f30_554, temp_f31_549);
            }
            var_r28_532 += 1;
        } while (var_r28_532 < 5);
        spC = 0;
        sp8 = 7;
        temp_r3_592 = checked_cast<SteamTrain *, MKProp>(this->unkD0->PropResolver_Resolve((s32) (u32) Message(&sp8)));
        if (temp_r3_592 != NULL) {
            temp_r4_597 = this->unk8;
            sp40 = 0.0f;
            sp44 = 500.0f;
            sp48 = 0.0f;
            sp70 = (f64) sp40;
            sp80 = M2C_FIELD(temp_r4_597, f64 *, 0x30);
            sp78 = (f64) sp48;
            sp88 = M2C_FIELD(temp_r4_597, f64 *, 0x38);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            spA0 = sp30;
            sp38 = (f32) sp88 + (f32) sp78;
            spA8 = (f64) sp38;
            temp_r3_592->TriggerDamageFX(*((MKVector3 *) &spA0), 1.0f);
        }
        goto block_34;
    case 0x7:
        temp_r3_628 = checked_cast<SteamTrain *, MKProp>(this->unkD0->PropResolver_Resolve((s32) arg0));
        if (temp_r3_628 != NULL) {
            temp_r4_633 = this->unk8;
            sp20 = 0.0f;
            sp24 = 500.0f;
            sp28 = 0.0f;
            sp50 = (f64) sp20;
            sp60 = M2C_FIELD(temp_r4_633, f64 *, 0x30);
            sp58 = (f64) sp28;
            sp68 = M2C_FIELD(temp_r4_633, f64 *, 0x38);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp90 = sp10;
            sp18 = (f32) sp68 + (f32) sp58;
            sp98 = (f64) sp18;
            temp_r3_628->TriggerDamageFX(*((MKVector3 *) &sp90), 1.0f);
        }
        temp_r0_661 = this->unkC8;
        if ((temp_r0_661 != 3) && (temp_r0_661 != 2) && ((u8) this->unkD8 == 0)) {
            SetState((SteamTrainCabooseState) 2);
        }
        KDSound_Play3d(GS_TrainHit, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
        ((KDInput *) (M2C_FIELD(*gb, KDInput *(**)(void **), 0x40)(gb)))->RumblePlay(0.99f, 0.8f, 0.15f, 0, 4.0f, 0U);
        var_r27_696 = 0;
        do {
            temp_r3_706 = checked_cast<Collectable2 *, MKProp>(((MKPropDescriptor *) (gMK->FindDescriptor("MagicGem2")))->CreateInstance());
            if (temp_r3_706 != NULL) {
                temp_f29_713 = MKRand_Float(&gViewSeed, 0.0f, 6.2831855f);
                temp_f30_718 = MKRand_Float(&gViewSeed, -50.0f, 50.0f);
                temp_f31_724 = MKRand_Float(&gViewSeed, 0.5f, 1.0f);
                temp_r4_733 = this->unk8;
                temp_r3_706->InitData(*((Matrix *) temp_r4_733), temp_r4_733 + 0x30, M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **), 0xC)(gb), s32 *, 8) + 0x30, temp_f31_724, temp_f30_718, temp_f29_713);
            }
            var_r27_696 += 1;
        } while (var_r27_696 < 5);
        temp_f1_744 = this->unkDC;
        this->unkDC = temp_f1_744 - 0.25f;
        if (this->unkDC < 1.0f) {
            this->unkDC = 1.0f;
        }
        EnemyHud_Modified((MKProp *) this, temp_f1_744, this->unkDC, 50.0f);
        goto block_34;
    case 0x8D:
        temp_r30_762 = M2C_FIELD(gpTranslation_StringArray, s32 *, 0x320);
        M2C_FIELD(checked_cast<GetNameMsg *, MKMessage>(arg0), s32 *, 8) = temp_r30_762;
        return;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'TrainTrack *' to
void SteamTrainCaboose::Update() {
    f32 sp36C;
    f32 sp368;
    f32 sp364;
    f32 sp360;
    f32 sp35C;
    f32 sp358;
    f32 sp354;
    f32 sp350;
    f32 sp34C;
    f32 sp348;
    f32 sp344;
    f32 sp340;
    f32 sp33C;
    f32 sp338;
    f32 sp334;
    f32 sp330;
    f64 sp328;
    f64 sp320;
    f64 sp318;
    f64 sp310;
    f64 sp308;
    f64 sp300;
    f64 sp2F8;
    f64 sp2F0;
    MKVector3 sp2E0;
    f64 sp2D8;
    f64 sp2D0;
    f64 sp2C8;
    f64 sp2C0;
    f64 sp2B8;
    f64 sp2B0;
    f64 sp2A8;
    f64 sp2A0;
    f64 sp298;
    f64 sp290;
    f64 sp288;
    f64 sp280;
    f64 sp278;
    f64 sp270;
    f64 sp268;
    f64 sp260;
    f64 sp258;
    f64 sp250;
    f64 sp248;
    f64 sp240;
    f64 sp238;
    f64 sp230;
    f64 sp228;
    f64 sp220;
    f64 sp218;
    f64 sp210;
    f64 sp208;
    f64 sp200;
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    f64 sp1C0;
    f32 sp1B0;
    f32 sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    MKVector3 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f32 sp148;
    f32 sp144;
    f32 sp140;
    f32 sp138;
    f32 sp128;
    f32 sp124;
    f32 sp120;
    f32 sp118;
    f32 sp108;
    f32 spF8;
    f32 spF4;
    f32 spF0;
    f32 spE8;
    f32 spE4;
    f32 spE0;
    f32 spD8;
    f32 spC8;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spA8;
    f32 sp9C;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    SteamTrain *temp_r3_821;
    f32 temp_f1_913;
    f32 temp_f28_937;
    f32 temp_f29_942;
    f32 temp_f29_989;
    f32 temp_f2_1282;
    f32 temp_f30_1026;
    f32 temp_f31_994;
    s32 temp_r0_824;
    s32 var_r28_1162;
    u64 temp_r3_816;
    u64 temp_ret_816;
    void *temp_r28_850;
    void *temp_r3_1100;
    void *temp_r3_1123;
    void *temp_r3_1147;
    void *temp_r3_1327;
    void *temp_r3_893;

    GameProp::Update();
    if ((s32) this->unkC8 != 0) {
        this->unk110.TrySpawnItems(0x10, 0U);
        if ((u8) this->unkD8 == 0) {
            temp_ret_816 = checked_cast<TrainTrack *, MKProp>(this->unkCC->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */)));
            temp_r3_816 = temp_ret_816;
            if ((temp_r3_816 != 0) && (temp_r3_821 = checked_cast<SteamTrain *, MKProp>(this->unkD0->PropResolver_Resolve((s32) (u32) temp_ret_816)), ((temp_r3_821 == NULL) == 0))) {
                temp_r0_824 = this->unkC8;
                switch (temp_r0_824) {              /* irregular */
                case 2:
                    if (this->unk80->unk2C & 1) {
                        SetState((SteamTrainCabooseState) 1);
                    }
                default:
block_20:
                    this->unkD4 = temp_r3_821->unk10C - 1200.0f;
                    sp1C0.GetTrackZAxis((s32) temp_r3_816, this->unkD4);
                    sp310 = sp1C0;
                    sp318 = sp1C8;
                    if ((((f32) sp318 * (f32) sp318) + (((f32) sp310 * (f32) sp310) + (unksp314 * unksp314))) > 0.0001f) {
                        M2C_STRUCT_COPY((s32) &unksp32C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
                        sp1B0.GetTrackPos((s32) temp_r3_816, this->unkD4, 1);
                        sp360 = sp1B0;
                        sp364 = sp1B4;
                        sp368 = sp1B8;
                        sp36C = 1.0f;
                        sp1A0.GetTrackXAxis((s32) temp_r3_816, this->unkD4);
                        sp330 = sp1A0;
                        sp48 = ((f32) sp310 * sp1A4) - (unksp314 * sp1A0);
                        sp40 = (unksp314 * sp1A8) - ((f32) sp318 * sp1A4);
                        sp44 = ((f32) sp318 * sp1A0) - ((f32) sp310 * sp1A8);
                        sp198 = (f64) sp48;
                        sp190 = (f64) sp40;
                        sp334 = sp1A4;
                        sp338 = sp1A8;
                        sp33C = 0.0f;
                        sp350 = (f32) sp310;
                        sp354 = unksp314;
                        sp358 = (f32) sp318;
                        sp35C = 0.0f;
                        sp340 = (f32) sp190;
                        sp344 = unksp194;
                        sp348 = (f32) sp198;
                        sp34C = 0.0f;
                        Normalise(sp170);
                        temp_f2_1282 = M2C_BITWISE(f32, sp170);
                        sp33C = 0.0f;
                        sp34C = 0.0f;
                        sp38 = (temp_f2_1282 * sp354) - (sp170.unk4 * sp350);
                        sp30 = (sp170.unk4 * sp358) - (sp170.unk8 * sp354);
                        sp34 = (sp170.unk8 * sp350) - (temp_f2_1282 * sp358);
                        sp188 = (f64) sp38;
                        sp180 = (f64) sp30;
                        sp330 = (f32) sp180;
                        sp334 = unksp184;
                        sp338 = (f32) sp188;
                        sp28 = (sp350 * unksp184) - (sp354 * (f32) sp180);
                        sp20 = (sp354 * (f32) sp188) - (sp358 * unksp184);
                        sp24 = (sp358 * (f32) sp180) - (sp350 * (f32) sp188);
                        sp168 = (f64) sp28;
                        sp160 = (f64) sp20;
                        sp340 = (f32) sp160;
                        sp344 = unksp164;
                        sp348 = (f32) sp168;
                        MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &sp330));
                    }
                    goto block_22;
                case 3:
                    if (MKRand_Int(&gViewSeed, 0, 7) == 0) {
                        temp_r28_850 = checked_cast<SteamTrainCabooseDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
                        sp140 = -5.0f;
                        sp144 = 0.0f;
                        sp148 = -5.0f;
                        sp2C0 = (f64) sp140;
                        sp2C8 = (f64) sp148;
                        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
                        sp128 = 5.0f;
                        sp138 = (f32) sp2C8 * 100.0f;
                        sp120 = 5.0f;
                        sp124 = 10.0f;
                        sp2D0 = sp130;
                        sp2A0 = (f64) sp120;
                        sp2D8 = (f64) sp138;
                        sp2A8 = (f64) sp128;
                        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
                        sp2B0 = sp110;
                        sp118 = (f32) sp2A8 * 100.0f;
                        sp2B8 = (f64) sp118;
                        KDRand_Vector(sp2E0, *((MKVector3 *) &sp2D0));
                        temp_r3_893 = this->unk8;
                        sp2F0 = M2C_FIELD(temp_r3_893, f64 *, 0x30);
                        sp2F8 = M2C_FIELD(temp_r3_893, f64 *, 0x38);
                        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                        sp300 = sp100;
                        sp108 = (f32) sp2F8 + sp2E0.unk8;
                        sp308 = (f64) sp108;
                        temp_f1_913 = MKRand_Float(&gViewSeed, 1.0f, 2.0f);
                        spF0 = 0.5f;
                        spF4 = 0.5f;
                        spF8 = 0.0f;
                        sp18 = temp_f1_913;
                        sp290 = (f64) spF0;
                        sp298 = (f64) spF8;
                        ((Explosion3 *) (M2C_FIELD(temp_r28_850, Explosion3 **, 0xF4)))->Trigger(*((MKVector3 *) &sp300), sp18, 1U, 1U, *((MKVector3 *) &sp290), (MKProp *) this);
                    }
                    temp_f28_937 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                    temp_f29_942 = MKRand_Float(&gViewSeed, 0.0f, 2.0f);
                    spE0 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                    spE4 = temp_f29_942;
                    spE8 = temp_f28_937;
                    sp270 = (f64) spE0;
                    sp278 = (f64) spE8;
                    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
                    sp280 = spD0;
                    spD8 = (f32) sp278 * 300.0f;
                    sp288 = (f64) spD8;
                    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                    sp320 = spC0;
                    spC8 = M2C_FIELD((this->unk8 + 0x30), f32 *, 8) + (f32) sp288;
                    sp328 = (f64) spC8;
                    if (MKRand_Int(&gViewSeed, 0, 4) == 0) {
                        temp_f29_989 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                        temp_f31_994 = MKRand_Float(&gViewSeed, 0.5f, 1.0f);
                        spB0 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                        spB4 = temp_f31_994;
                        spB8 = temp_f29_989;
                        sp250 = (f64) spB0;
                        sp258 = (f64) spB8;
                        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
                        sp260 = spA0;
                        spA8 = (f32) sp258 * 800.0f;
                        sp268 = (f64) spA8;
                        sp14 = MKRand_Float(&gViewSeed, 5.0f, 8.0f);
                        temp_f30_1026 = MKRand_Float(&gViewSeed, 0.75f, 1.0f);
                        sp90 = MKRand_Float(&gViewSeed, 0.85f, 1.0f);
                        sp94 = temp_f30_1026;
                        sp98 = 0.5f;
                        sp9C = 1.0f;
                        sp240 = (f64) sp90;
                        sp248 = (f64) sp98;
                        ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(*((MKVector3 *) &sp320), *((MKVector3 *) &sp260), sp14, *((MKVector4 *) &sp240), -1000.0f);
                    }
                    if (MKRand_Int(&gViewSeed, 0, 4) == 0) {
                        sp10 = MKRand_Float(&gViewSeed, 3.0f, 5.0f);
                        sp88 = 0.0f;
                        sp80 = 0.0f;
                        sp84 = 0.0f;
                        sp238 = (f64) sp88;
                        sp230 = (f64) sp80;
                        gb.EmitDust(*((MKVector3 *) &sp320), *((MKVector3 *) &sp230), sp10, 0.0f);
                    }
                    if (this->unk80->unk2C & 1) {
                        KDSound_Play3d(GS_TrainCrash, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
                        sp70 = -0.5f;
                        sp74 = 0.5f;
                        sp78 = 0.0f;
                        sp210 = (f64) sp70;
                        sp218 = (f64) sp78;
                        temp_r3_1100 = this->unk8;
                        sp220 = M2C_FIELD(temp_r3_1100, f64 *, 0x30);
                        sp228 = M2C_FIELD(temp_r3_1100, f64 *, 0x38);
                        ((Explosion3 *) (M2C_FIELD(checked_cast<SteamTrainCabooseDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), Explosion3 **, 0xF4)))->Trigger(*((MKVector3 *) &sp220), 6.0f, 1U, 1U, *((MKVector3 *) &sp210), (MKProp *) this);
                        sp68 = 0.0f;
                        sp60 = 0.0f;
                        sp64 = 0.0f;
                        sp1F8 = (f64) sp68;
                        sp1F0 = (f64) sp60;
                        temp_r3_1123 = this->unk8;
                        sp200 = M2C_FIELD(temp_r3_1123, f64 *, 0x30);
                        sp208 = M2C_FIELD(temp_r3_1123, f64 *, 0x38);
                        ((Explosion3 *) (M2C_FIELD(checked_cast<SteamTrainCabooseDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), Explosion3 **, 0xF4)))->Trigger(*((MKVector3 *) &sp200), 8.0f, 1U, 1U, *((MKVector3 *) &sp1F0), (MKProp *) this);
                        sp50 = 0.5f;
                        sp54 = 0.5f;
                        sp58 = 0.0f;
                        sp1D0 = (f64) sp50;
                        sp1D8 = (f64) sp58;
                        temp_r3_1147 = this->unk8;
                        sp1E0 = M2C_FIELD(temp_r3_1147, f64 *, 0x30);
                        sp1E8 = M2C_FIELD(temp_r3_1147, f64 *, 0x38);
                        ((Explosion3 *) (M2C_FIELD(checked_cast<SteamTrainCabooseDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), Explosion3 **, 0xF4)))->Trigger(*((MKVector3 *) &sp1E0), 10.0f, 1U, 1U, *((MKVector3 *) &sp1D0), (MKProp *) this);
                        var_r28_1162 = 0;
                        do {
                            temp_r3_821->TriggerDamageFX(*((MKVector3 *) &sp320), 2.0f);
                            var_r28_1162 += 1;
                        } while (var_r28_1162 < 2);
                        this->unkD8 = 1;
                        Disable();
                        SetState((SteamTrainCabooseState) 0);
                        return;
                    }
                    goto block_20;
                }
            }
        } else {
block_22:
            temp_r3_1327 = this->unk8;
            sp150 = M2C_FIELD(temp_r3_1327, f64 *, 0x30);
            sp158 = M2C_FIELD(temp_r3_1327, f64 *, 0x38);
            this->unkE0.unk28 = unksp154;
        }
    }
}
#endif

void SteamTrainCaboose::Reset() {
    GameProp::Reset();
    this->unkD4 = 0.0f;
    this->unkD8 = 0;
    SetState((SteamTrainCabooseState) 0);
    if (this->unkCC->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */)) == NULL) {
        Disable();
    }
    this->unk110.SetDefaults();
    this->unk110.FunctionOff();
    this->unkDC = 50.0f;
}

#if 0 // DRAFT: undefined identifier '__vptr'
void SteamTrainCaboose::LoadDone() {
    M2C_UNK sp8;
    SpawnPointData *temp_r26_1450;
    SpawnPointObject *temp_r25_1476;
    s32 var_r25_1410;
    s32 var_r25_1511;
    s32 var_r28_1439;
    s32 var_r30_1438;
    s32 var_r30_1512;

    GameProp::LoadDone();
    this->unkE0.Init(this->unk4, (MKProp *) this, 1000.0f, NULL, 1500.0f);
    this->unkE0.Show(1U);
    var_r25_1410 = 0;
    do {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp("MagicGem2"), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r25_1410 += 1;
    } while (var_r25_1410 < 5);
    Disable();
    operator new(4U, NULL, 0);
    M2C_FIELD(this, TrainChaseSpawnPool **, 0x160) = (TrainChaseSpawnPool *) M2C_ERROR(/* Read from unset register $r3 */);
    ((TrainChaseSpawnPool *) (M2C_FIELD(this, TrainChaseSpawnPool **, 0x160)))->Init();
    var_r30_1438 = 0;
    var_r28_1439 = 0;
    do {
        operator new(0x60U, NULL, 0);
        *(&sp8 + var_r28_1439) = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x28U, NULL, 0);
        temp_r26_1450 = M2C_ERROR(/* Read from unset register $r3 */);
        if (temp_r26_1450 != NULL) {
            temp_r26_1450->__vptr = &__vt;
            temp_r26_1450->__vptr = &__vt;
            M2C_FIELD(temp_r26_1450, s32 *, 8) = 0;
            ((EventMessage *) (temp_r26_1450 + 8))->Init();
            M2C_FIELD(temp_r26_1450, s32 *, 0xC) = 0;
            ((EventMessage *) (temp_r26_1450 + 0xC))->Init();
            M2C_FIELD(temp_r26_1450, s32 *, 0x10) = 0;
            ((EventMessage *) (temp_r26_1450 + 0x10))->Init();
            M2C_FIELD(temp_r26_1450, s32 *, 0x14) = 0;
            ((EventMessage *) (temp_r26_1450 + 0x14))->Init();
        }
        temp_r25_1476 = *(&sp8 + var_r28_1439);
        temp_r25_1476->Init(temp_r26_1450);
        temp_r25_1476->unk10 = (s32) this->unk4;
        temp_r25_1476->unk14 = (s32) Tools_GetMatchingRefPointIndex(this->unk4, "spawn_00");
        var_r28_1439 += 4;
        temp_r25_1476->unk18 = var_r30_1438;
        var_r30_1438 += 1;
        temp_r25_1476->unk50 = 1;
    } while (var_r30_1438 < 2);
    this->unk110.unk2C = 10.0f;
    this->unk110.unk30 = 5.0f;
    M2C_FIELD(this, u8 *, 0x15C) = (u8) (M2C_FIELD(this, u8 *, 0x15C) | 0x10);
    this->unk110.LoadDone(0, 2, 0U, 1U);
    this->unk110.AddSpawnPointBegin(2);
    var_r25_1511 = 0;
    var_r30_1512 = 0;
    do {
        this->unk110.AddSpawnPoint(*(&sp8 + var_r30_1512));
        var_r25_1511 += 1;
        var_r30_1512 += 4;
    } while (var_r25_1511 < 2);
    this->unk110.AddSpawnPointEnd();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
s32 SteamTrainCaboose::LoadLine(MKIniLine *arg0) {
    s32 var_r31_1539;

    var_r31_1539 = 0;
    if ((GameProp::LoadLine(arg0) != 0) || (arg0->LoadInt("trackID", (s32 *) &this->unkCC, 0) != 0) || (arg0->LoadInt("trainID", (s32 *) &this->unkD0, 0) != 0)) {
        var_r31_1539 = 1;
    }
    return var_r31_1539;
}
#endif

#if 0 // DRAFT: illegal operand
void SteamTrainCaboose::Deinit() {
    if ((u32) M2C_FIELD(&gb, u32 *, 0x360) == this) {
        M2C_FIELD(&gb, u32 *, 0x360) = 0U;
        EnemyHud_Modified(NULL, 0.0f, 0.0f, 0.0f);
    }
    ((TrainChaseSpawnPool *) (M2C_FIELD(this, TrainChaseSpawnPool **, 0x160)))->Deinit();
    operator delete(M2C_FIELD(this, TrainChaseSpawnPool **, 0x160));
    this->unk110.RemoveAllSpawnPoints(1U);
    this->unk110.Deinit();
    this->unkE0.Deinit();
    GameProp::Deinit();
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'void
void SteamTrainCaboose::Init() {
    GameProp::Init();
    this->unkD4 = 0.0f;
    this->unkD8 = 0;
    this->unkCC = NULL;
    this->unkD0 = NULL;
    this->unkDC = 50.0f;
    this->unk110.Init((void (*)(SpawnAction, s32, MKProp **, SpawnerObject *)) &TrainChaseSpawnPool::Action, 0);
    M2C_FIELD(this, s32 *, 0x160) = 0;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void SteamTrainCabooseDescriptor::LoadDone() {
    GamePropDescriptor::LoadDone();
    this->unkE4 = this->unk34->GetAnim("idle");
    this->unkE8 = this->unk34->GetAnim("idle");
    this->unkEC = this->unk34->GetAnim("flinch");
    this->unkF0 = this->unk34->GetAnim("crash");
    this->unkF4 = checked_cast<Explosion3 *, MKProp>(gMK->CreateProp("Explosion3"));
}
#endif
