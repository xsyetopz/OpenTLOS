#include "spyro/source/KDSynkerPlayer3.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDSynkerPlayer2Messages.h"
#include "spyro/source/KDSynkerPlayerActor.h"
#include "spyro/source/KDSynkerPlayerActorList.h"
#include "spyro/source/KDSynkerPlayerCamera.h"
#include "spyro/source/KDSynkerPlayerEvents.h"
#include "spyro/source/KDSynkerPlayerSounds.h"
#include "spyro/source/KDSynkerPlayerTools.h"
#include "spyro/source/Level.h"
#include "common/Source/MKPackage.h"
#include "common/Source/Str.h"
#include "spyro/source/GameLanguage.h"
#include <m2c_macros.h>

M2C_UNK free(MKIni *);                              /* extern */
void *malloc(u32);                                  /* extern */
s32 strcmpi(s8 *);                                  /* extern */
M2C_UNK strtok(s8 *, s8 *);                         /* extern */
extern f32 gUpdateTimeDelta;
static s8 subFileName_791[0x100];

#if 0 // DRAFT: function call 'strncpy(signed char[256], const char *, unsigned int)' does
s8 *KDSynkerPlayer3::GetSubtitlesFileName(const char *arg0) {
    strncpy(subFileName_791, arg0, 6U);
    GameLanguage_GetCode(-1);
    subFileName_791[6] = (s8) *M2C_ERROR(/* Read from unset register $r3 */);
    subFileName_791[7] = (s8) M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), u8 *, 1);
    strcpy(&subFileName_791[8], ".sub");
    return subFileName_791;
}
#endif

#if 0 // DRAFT: pointer/array required
s32 KDSynkerPlayer3::GetActorProp(int arg0) {
    return *(this->unk100.unk4 + ((arg0 * 0x138) + 0x30));
}
#endif

#if 0 // DRAFT: pointer/array required
s32 KDSynkerPlayer3::GetActorAnimScript(int arg0) {
    return *(this->unk100.unk4 + ((arg0 * 0x138) + 0x38));
}
#endif

void KDSynkerPlayer3::GetActorModel(int arg0) {
    ((KDSP_Actor *) (this->unk100.unk4 + (arg0 * 0x138)))->GetModel();
}

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
void KDSynkerPlayer3::ParseSK2() {
    MKHeap *temp_r3_140;
    s32 var_r29_133;
    s32 var_r30_134;
    u32 temp_r27_137;
    void *temp_r28_136;
    void *var_r3_147;

    if ((MKIni *) this->unk54 == NULL) {
        operator new(0x50U, NULL, 0);
        this->unk54 = M2C_ERROR(/* Read from unset register $r3 */);
        this->unk54->Init(Str_Printf("%s.sc2", &this->unk28), 1, NULL);
    }
    ParseHeader();
    this->unk114.HeapAddSize(&this->unk4, this->unk54);
    this->unk148.HeapAddSize(&this->unk4, this->unk54);
    this->unk100.HeapAddSize(&this->unk4, this->unk54);
    this->unk60.HeapAddSize(&this->unk4, &this->unk28, this->unk54);
    this->unk120.HeapAddSize(&this->unk4, this->unk54, this->unk148.unk0);
    this->unk170.HeapAddSize(&this->unk4, GetSubtitlesFileName(&this->unk28));
    var_r29_133 = 0;
    var_r30_134 = 0;
    do {
        temp_r28_136 = this + var_r30_134;
        temp_r27_137 = M2C_FIELD(temp_r28_136, u32 *, 8);
        if (temp_r27_137 != 0U) {
            temp_r3_140 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
            if (temp_r3_140 != NULL) {
                var_r3_147 = ((MKHeap *) (temp_r3_140->Current()))->Alloc((s32) temp_r27_137, NULL, 0);
            } else {
                var_r3_147 = malloc(temp_r27_137);
            }
            M2C_FIELD(temp_r28_136, void **, 4) = var_r3_147;
        }
        var_r29_133 += 1;
        var_r30_134 += 0xC;
    } while (var_r29_133 < 3);
    this->unk114.Parse(&this->unk4, this->unk54);
    this->unk148.ParseDynamicSFX(&this->unk4, this->unk54);
    this->unk100.Parse(&this->unk4, this->unk54, this->unk23C, this->unk238);
    this->unk60.Parse(&this->unk4, &this->unk28, this->unk54, this->unk23C);
    if (!(this->unk50 & 8)) {
        this->unk100.Load(this->unk54, this->unk23C, 0U, this->unk60.unk88 == 0);
    }
    this->unk100.ResolveLookAt();
    this->unk120.Parse(this, &this->unk4, &this->unk28, this->unk54, this->unk148.unk0, &this->unk100);
    this->unk170.Parse(&this->unk4, GetSubtitlesFileName(&this->unk28));
    this->unk148.ResolveActors(&this->unk100);
}
#endif

#if 0 // DRAFT: function call 'strcmpi(const char[8])' does not match
void KDSynkerPlayer3::ParseHeader() {
    MKIniLine *temp_r3_230;
    MKIniLine *var_r30_236;

    temp_r3_230 = this->unk54->GotoLine("GENERAL", NULL);
    if (temp_r3_230 != NULL) {
        var_r30_236 = temp_r3_230->unkC->GetSubLine(temp_r3_230);
loop_5:
        if (var_r30_236 == NULL) {

        } else {
            var_r30_236->GetFieldName();
            if (strcmpi("Version") == 0) {
                var_r30_236->GetInt(0);
                return;
            }
            var_r30_236 = var_r30_236->unkC->GetNextLine(var_r30_236);
            goto loop_5;
        }
    }
}
#endif

s32 KDSynkerPlayer3::GetSubTitle(int arg0) {
    return M2C_FIELD((this + (arg0 * 8)), s32 *, 0x21C);
}

s32 KDSynkerPlayer3::GetSubTitleCount() {
    return this->unk170.unkA4;
}

s32 KDSynkerPlayer3::IsUnloaded() {
    return this->unk4C == 8;
}

s32 KDSynkerPlayer3::IsUnloading() {
    s32 temp_r0_295;

    temp_r0_295 = this->unk4C;
    if ((temp_r0_295 == 7) || (temp_r0_295 == 6)) {
        return 1;
    }
    return 0;
}

s32 KDSynkerPlayer3::IsAtEnd() {
    s32 var_r4_310;

    var_r4_310 = 0;
    if (((s32) this->unk4C == 5) && (this->unk50 & 4)) {
        var_r4_310 = 1;
    }
    return var_r4_310;
}

s32 KDSynkerPlayer3::IsPlaying() {
    return this->unk4C == 5;
}

s32 KDSynkerPlayer3::IsReadyToPlay() {
    return this->unk4C == 4;
}

s32 KDSynkerPlayer3::IsLoading() {
    s32 temp_r0_345;

    temp_r0_345 = this->unk4C;
    if ((temp_r0_345 == 1) || (temp_r0_345 == 2)) {
        return 1;
    }
    return 0;
}

s32 KDSynkerPlayer3::IsActive() {
    return this->unk4C != 0;
}

void KDSynkerPlayer3::Deinit() {
    this->unk4C = 0;
}

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void KDSynkerPlayer3::Unload() {
    MKHeap *temp_r3_441;
    MKHeap *temp_r3_446;
    MKHeap *temp_r3_473;
    MKIni *temp_r26_445;
    MKIni *temp_r28_472;
    MKIni *temp_r3_465;
    s32 temp_r0_398;
    s32 temp_r3_393;
    s32 var_r28_436;
    s32 var_r30_437;
    u32 temp_r3_381;
    u32 temp_r4_382;
    void *temp_r27_440;

    temp_r3_381 = this->unk50;
    temp_r4_382 = temp_r3_381 & 0x10;
    if (((temp_r4_382 != 0) && ((s32) this->unk4C == 3)) || (!(temp_r3_381 & 8) && (temp_r4_382 == 0))) {
        temp_r3_393 = this->unk250;
        if (temp_r3_393 > 0) {
            MKPackage_QCancel(temp_r3_393);
        }
    }
    temp_r0_398 = this->unk4C;
    if (temp_r0_398 < 3) {
        if (temp_r0_398 < 1) {
            return;
        }
        this->unk4C = 6;
        return;
    }
    if (temp_r0_398 < 6) {
        this->unk4C = 7;
        if ((u8) this->unk148.unk0 != 0) {
            this->unk120.StopSfx();
        }
        this->unk120.Deinit();
        this->unk148.Deinit();
        this->unk114.Deinit();
        ActorCallback((KDSynkerPlayer3::CallBackMode) 1);
        this->unk100.Deinit(((u32) this->unk50 >> 5U) & 1);
        this->unk60.Deinit();
        var_r28_436 = 0;
        var_r30_437 = 0;
        do {
            temp_r27_440 = this + var_r30_437;
            temp_r3_441 = M2C_FIELD(temp_r27_440, MKHeap **, 4);
            if (temp_r3_441 != NULL) {
                temp_r26_445 = temp_r3_441 - M2C_FIELD(temp_r27_440, s32 *, 8);
                temp_r3_446 = temp_r3_441->Current();
                if (temp_r3_446 != NULL) {
                    ((MKHeap *) (temp_r3_446->Current()))->Free(temp_r26_445, NULL, 0);
                } else {
                    free(temp_r26_445);
                }
                M2C_FIELD(temp_r27_440, MKHeap **, 4) = NULL;
            }
            var_r28_436 += 1;
            var_r30_437 += 0xC;
        } while (var_r28_436 < 3);
        temp_r3_465 = this->unk54;
        if ((temp_r3_465 != NULL) && ((u8) this->unk58 == 0)) {
            temp_r3_465->Deinit();
            temp_r28_472 = this->unk54;
            temp_r3_473 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
            if (temp_r3_473 != NULL) {
                ((MKHeap *) (temp_r3_473->Current()))->Free(temp_r28_472, NULL, 0);
            } else {
                free(temp_r28_472);
            }
            this->unk54 = NULL;
        }
        this->unk254 = 3;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void KDSynkerPlayer3::Draw() {
    KDSP_Actor *temp_r3_526;
    s32 temp_r30_520;
    s32 var_r29_521;
    s32 var_r31_522;
    u8 var_r4_529;

    if (((s32) this->unk4C == 5) && !(this->unk50 & 4)) {
        if ((u32) *KDSynkerPlayer3::pActorCallback != 0U) {
            ActorCallback((KDSynkerPlayer3::CallBackMode) 3);
        } else {
            temp_r30_520 = this->unk100.unk0;
            var_r29_521 = 0;
            var_r31_522 = 0;
loop_13:
            if (var_r29_521 < temp_r30_520) {
                temp_r3_526 = this->unk100.unk4 + var_r31_522;
                if (temp_r3_526 != NULL) {
                    var_r4_529 = 0;
                    if (((u32) temp_r3_526->unk30 == 0U) && !(temp_r3_526->unk40 & 4) && ((s32) temp_r3_526->unkCC != -1)) {
                        var_r4_529 = 1;
                    }
                    if (var_r4_529 != 0) {
                        temp_r3_526->Draw();
                    }
                }
                var_r29_521 += 1;
                var_r31_522 += 0x138;
                goto loop_13;
            }
        }
        this->unk120.Draw();
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void KDSynkerPlayer3::Play(bool arg0) {
    if (arg0 != 0) {
        this->unk50 |= 1;
    } else {
        this->unk50 &= 0xFFFFFFFE;
    }
    if (this->unk50 & 8) {
        this->unk100.Load(this->unk54, this->unk23C, 1U, arg0 == 0);
    }
    ActorCallback((KDSynkerPlayer3::CallBackMode) 0);
    this->unk100.SendMessageToActorProp(1U);
    this->unk50 &= 0xFFFFFFFD;
    this->unk4C = 5;
    Update_Playing(1U);
}
#endif

void KDSynkerPlayer3::SkipToEnd(bool arg0) {
    this->unk24C = this->unk23C;
    this->unk248 = (f32) this->unk24C;
    this->unk244 = this->unk248 / 30.0f;
    this->unk170.Reset();
    this->unk50 |= 0x20;
    if (arg0 != 0) {
        this->unk120.SkipToEnd();
    }
}

void KDSynkerPlayer3::Update_Unloading_Playing() {
    if (!(this->unk50 & 8)) {
        this->unk148.UnloadPlaying((int *) &this->unk250);
    }
    this->unk254 -= 1;
    if (((s32) this->unk254 <= 0) && ((s32) this->unk148.unk14 == -1)) {
        this->unk4C = 8;
    }
}

void KDSynkerPlayer3::Update_Unloading_Loading() {
    u32 temp_r3_695;

    temp_r3_695 = this->unk50;
    if ((temp_r3_695 & 8) || (temp_r3_695 & 0x10)) {
        this->unk4C = 8;
        return;
    }
    if (MKPackage_QIsLoaded(this->unk250, NULL, NULL) != 0) {
        MKPackage_QFree(this->unk250);
        this->unk250 = 0;
        this->unk4C = 8;
    }
}

#if 0 // DRAFT: illegal use of incomplete struct/union/class
void KDSynkerPlayer3::ActorCallback(KDSynkerPlayer3::CallBackMode arg1) {
    s32 temp_r30_737;
    s32 temp_r3_751;
    s32 var_r29_738;
    s32 var_r31_739;
    void *temp_r5_743;

    if (((M2C_UNK (*)(KDSynkerPlayer3::CallBackMode, s32, s32, s32)) *KDSynkerPlayer3::pActorCallback) != NULL) {
        temp_r30_737 = this->unk100.unk0;
        var_r29_738 = 0;
        var_r31_739 = 0;
loop_12:
        if (var_r29_738 < temp_r30_737) {
            temp_r5_743 = this->unk100.unk4 + var_r31_739;
            if ((temp_r5_743 != NULL) && (((M2C_UNK (*)(KDSynkerPlayer3::CallBackMode, s32, s32, s32)) *KDSynkerPlayer3::pActorCallback) != NULL) && ((u32) M2C_FIELD(temp_r5_743, u32 *, 0x30) == 0U)) {
                temp_r3_751 = M2C_FIELD(temp_r5_743, s32 *, 0x40);
                if (!(temp_r3_751 & 4) && (((s32) M2C_FIELD(temp_r5_743, s32 *, 0xCC) != -1) || ((u32) ((s32) arg1 - 2) > 1U))) {
                    if (temp_r3_751 & 0x40) {
                        *KDSynkerPlayer3::pActorCallback(arg1, var_r29_738, M2C_FIELD(temp_r5_743, s32 *, 0x3C), 0);
                    } else {
                        *KDSynkerPlayer3::pActorCallback(arg1, var_r29_738, 0, M2C_FIELD(temp_r5_743, s32 *, 0x38));
                    }
                }
            }
            var_r29_738 += 1;
            var_r31_739 += 0x138;
            goto loop_12;
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
void KDSynkerPlayer3::Update_Playing(bool arg0) {
    KDS_Message_SetCamera spC;
    s32 sp8;
    s32 temp_r3_826;
    s32 temp_r3_876;
    u32 temp_r3_847;

    if (arg0 == 0) {
        this->unk240 = this->unk148.Update(this->unk24C, this->unk48, this->unk23C, (int *) &this->unk250, (int *) &sp8) == 0;
        if (((u8) this->unk148.unk0 != 0) && ((u8) this->unk148.unk1 != 0)) {
            this->unk120.UpdateSfx(&this->unk100, this->unk24C, this->unk48);
        }
        temp_r3_826 = this->unk23C - 1;
        if ((s32) this->unk24C >= temp_r3_826) {
            this->unk24C = temp_r3_826;
            this->unk248 = (f32) this->unk24C;
            this->unk244 = this->unk248 / 30.0f;
            this->unk50 |= 4;
        }
        temp_r3_847 = this->unk50;
        if (!(temp_r3_847 & 2) && !(temp_r3_847 & 4) && ((temp_r3_847 & 8) || (this->unk148.WaitingForSoundPackage((int *) &this->unk250) == 0))) {
            this->unk244 += gUpdateTimeDelta * this->unk48;
            this->unk248 = 30.0f * this->unk244;
            this->unk24C = (s32) this->unk248;
            temp_r3_876 = this->unk23C - 1;
            if ((s32) this->unk24C >= temp_r3_876) {
                this->unk24C = temp_r3_876;
                this->unk248 = (f32) this->unk24C;
                this->unk244 = this->unk248 / 30.0f;
            }
        }
    }
    if (this->unk50 & 1) {
        this->unk60.Update(&this->unk28, this->unk248, &this->unk114);
    }
    if ((this->unk50 & 1) && ((void *) *KDSynkerPlayer3::pCameraProp != NULL)) {
        spC.unk4 = 0;
        spC.Init((Matrix *) &this->unk60, this->unk60.unk60, this->unk60.unk64, this->unk60.unk68);
        M2C_FIELD(M2C_FIELD(*KDSynkerPlayer3::pCameraProp, void **, 0x44), M2C_UNK (**)(void *, KDS_Message_SetCamera *), 0x2C)(*KDSynkerPlayer3::pCameraProp, &spC);
    }
    this->unk170.Update(&this->unk100, this->unk24C);
    this->unk100.Update(this->unk248, &this->unk114, *((MKVector3 *) &this->unk60.unk40), (u8) this->unk60.unk6C);
    this->unk120.Update(this, this->unk248, ((u32) this->unk50 >> 2U) & 1);
    this->unk120.UpdateTweenAnims(this->unk24C, &this->unk114);
    ActorCallback((KDSynkerPlayer3::CallBackMode) 2);
}
#endif

void KDSynkerPlayer3::Update_PrimingSound() {
    if (MKPackage_QIsLoaded(this->unk250, NULL, NULL) != 0) {
        this->unk4C = 4;
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
void KDSynkerPlayer3::Update_ParseData() {
    u32 temp_r3_992;

    this->unk148.LoadStaticSoundBank(&this->unk28, ((u32) this->unk50 >> 3U) & 1);
    ParseSK2();
    temp_r3_992 = this->unk50;
    if (!(temp_r3_992 & 8) && !(temp_r3_992 & 0x10)) {
        MKPackage_QFree(this->unk250);
        this->unk250 = 0;
    }
    if (this->unk148.LoadDynamicSoundBank((int *) &this->unk250, ((u32) this->unk50 >> 3U) & 1) != 0) {
        this->unk4C = 3;
        return;
    }
    this->unk4C = 4;
}
#endif

void KDSynkerPlayer3::Update_Loading() {
    if (MKPackage_QIsLoaded(this->unk250, NULL, NULL) != 0) {
        Update_ParseData();
    }
}

void KDSynkerPlayer3::Update() {
    s32 temp_r0_1053;

    temp_r0_1053 = this->unk4C;
    if ((u32) temp_r0_1053 <= 8U) {
        switch (temp_r0_1053) {
        case 1:
            Update_Loading();
            return;
        case 2:
            Update_ParseData();
            return;
        case 3:
            Update_PrimingSound();
            return;
        case 5:
            Update_Playing(0U);
            return;
        case 6:
            Update_Unloading_Loading();
            return;
        case 7:
            Update_Unloading_Playing();
            break;
        }
    }
}

void KDSynkerPlayer3::SetPlaySpeed(float arg0) {
    this->unk48 = arg0;
}

#if 0 // DRAFT: function call 'strcpy(signed char *, const char *)' does not match
void KDSynkerPlayer3::Init(const char *arg0, bool arg1, bool arg2, MKIni *arg3) {
    u32 temp_r3_1176;

    this->unk50 = 0;
    if (arg1 != 0) {
        this->unk50 |= 8;
    } else {
        this->unk50 &= 0xFFFFFFF7;
    }
    if (arg2 != 0) {
        this->unk50 |= 0x10;
    } else {
        this->unk50 &= 0xFFFFFFEF;
    }
    strcpy(&this->unk28, arg0);
    strtok(&this->unk28, ".");
    this->unk58 = arg3 != NULL;
    this->unk54 = arg3;
    this->unk4.unk8 = 0x40;
    this->unk4.unk4 = 0;
    this->unk4.unk0 = 0;
    this->unk4.unk14 = 0x10;
    this->unk4.unk10 = 0;
    this->unk4.unkC = NULL;
    this->unk4.unk20 = 4;
    this->unk4.unk1C = 0;
    this->unk4.unk18 = NULL;
    this->unk60.Init();
    this->unk100.Init();
    this->unk114.Init();
    this->unk120.Init(this, *KDSynkerPlayer3::pEventCreationTable);
    this->unk148.Init();
    this->unk170.Init();
    this->unk234 = 0;
    this->unk23C = 0;
    this->unk244 = 0.0f;
    this->unk24C = 0;
    this->unk248 = 0.0f;
    this->unk48 = 1.0f;
    this->unk240 = 0;
    this->unk238 = NULL;
    temp_r3_1176 = this->unk50;
    if ((temp_r3_1176 & 8) || (temp_r3_1176 & 0x10)) {
        this->unk250 = 0;
        this->unk4C = 2;
        Update();
        return;
    }
    this->unk4C = 1;
    this->unk250 = MKPackage_QLoad(Str_Printf("%s.sc2", &this->unk28, 0.0f), 0);
}
#endif
