#include "spyro/source/KDSynkerPlayerSounds.h"
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
#include "common/gc/Sound_GC.h"
#include "spyro/source/KDSynkerPlayerActor.h"
#include "spyro/source/KDSynkerPlayerActorList.h"
#include "spyro/source/Level.h"
#include "common/Source/FileSys.h"
#include "common/Source/MKPackage.h"
#include "common/Source/MKSystem.h"
#include "common/Source/Str.h"
#include "spyro/source/GameLanguage.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

M2C_UNK free(SoundBankHeader *);                    /* extern */
s32 stricmp(s32, s32);                              /* extern */

void KDSP_Sounds::GetDynamicSoundName(int arg0) {
    GameLanguage_GetAudioCode(-1);
    Str_Printf("%s%s", M2C_FIELD((((u8 *) this->unkC) + (arg0 * 0x18)), s32 *, 8), M2C_ERROR(/* Read from unset register $r3 */), "%s%s");
}

void KDSP_Sounds::GetDynamicBankName(int arg0) {
    GameLanguage_GetAudioCode(-1);
    Str_Printf("%s%s.gsb", M2C_FIELD((((u8 *) this->unkC) + (arg0 * 0x18)), s32 *, 8), M2C_ERROR(/* Read from unset register $r3 */), "%s%s");
}

#if 0 // DRAFT: illegal type
void KDSP_Sounds::ResolveActors(KDSP_ActorList *arg0) {
    s32 var_r23_82;
    s32 var_r25_83;
    s32 var_r26_78;
    s32 var_r27_73;
    s32 var_r30_77;
    s32 var_r31_72;
    void *temp_r24_79;
    void *temp_r4_89;
    void *temp_r5_88;

    var_r31_72 = 0;
    var_r27_73 = 0;
loop_11:
    if (var_r31_72 < (s32) arg0->unk0) {
        var_r30_77 = 0;
        var_r26_78 = 0;
        temp_r24_79 = (void *) (arg0->unk4 + var_r27_73);
loop_9:
        if (var_r30_77 < (s32) M2C_FIELD(temp_r24_79, s32 *, 0x54)) {
            var_r23_82 = 0;
            var_r25_83 = 0;
loop_7:
            if (var_r23_82 < (s32) this->unk8) {
                temp_r5_88 = ((u8 *) this->unkC) + var_r25_83;
                temp_r4_89 = (void *) (var_r26_78 + M2C_FIELD(temp_r24_79, s32 *, 0x58));
                if (((s32) M2C_FIELD(temp_r5_88, s32 *, 0) == (s32) M2C_FIELD(temp_r4_89, s32 *, 0)) && (stricmp(M2C_FIELD(temp_r5_88, s32 *, 8), M2C_FIELD(temp_r4_89, s32 *, 0xC)) == 0)) {
                    *(this->unkC + (var_r25_83 + 0x14)) = temp_r24_79;
                }
                var_r23_82 += 1;
                var_r25_83 += 0x18;
                goto loop_7;
            }
            var_r30_77 += 1;
            var_r26_78 += 0x24;
            goto loop_9;
        }
        var_r31_72 += 1;
        var_r27_73 += 0x138;
        goto loop_11;
    }
}
#endif

#if 0 // DRAFT: illegal type
void KDSP_Sounds::ParseDynamicSFX(KDSynkerHeap *arg0, MKIni *arg1) {
    MKIniLine *temp_r7_135;
    MKIniLine *var_r28_156;
    s32 temp_r0_138;
    s32 temp_r5_144;
    void *temp_r6_143;
    void *var_r29_151;

    temp_r7_135 = this->unk4;
    if (temp_r7_135 != NULL) {
        temp_r0_138 = this->unk8;
        if (temp_r0_138 != 0) {
            temp_r6_143 = arg0->unk18;
            temp_r5_144 = arg0->unk20 - 1;
            arg0->unk18 = ((u8 *) temp_r6_143) + (((temp_r0_138 * 0x18) + temp_r5_144) & ~temp_r5_144);
            this->unkC = temp_r6_143;
            var_r29_151 = this->unkC;
            var_r28_156 = temp_r7_135->unkC->GetSubLine(temp_r7_135);
loop_4:
            if (var_r28_156 != NULL) {
                M2C_FIELD(var_r29_151, s8 **, 8) = var_r28_156->GetFieldName();
                M2C_FIELD(var_r29_151, s32 *, 0xC) = -1;
                M2C_FIELD(var_r29_151, s32 *, 0x14) = 0;
                M2C_FIELD(var_r29_151, s32 *, 0) = var_r28_156->GetInt(0);
                M2C_FIELD(var_r29_151, s32 *, 4) = var_r28_156->GetInt(1);
                var_r29_151 += 0x18;
                var_r28_156 = var_r28_156->unkC->GetNextLine(var_r28_156);
                goto loop_4;
            }
        }
    }
}
#endif

void KDSP_Sounds::HeapAddSize(KDSynkerHeap *arg0, MKIni *arg1) {
    MKIniLine *temp_r3_204;
    s32 temp_r3_207;
    s32 temp_r3_215;

    this->unk4 = arg1->GotoLine("DYNAMIC_SFX", NULL);
    temp_r3_204 = this->unk4;
    if (temp_r3_204 != NULL) {
        temp_r3_207 = temp_r3_204->GetNmbrOfSubLines();
        this->unk8 = temp_r3_207;
        if (temp_r3_207 != 0) {
            temp_r3_215 = arg0->unk20 - 1;
            arg0->unk1C += ((this->unk8 * 0x18) + temp_r3_215) & ~temp_r3_215;
        }
    }
}

void KDSP_Sounds::Deinit() {
    s32 temp_r3_239;
    s32 temp_r3_246;
    s32 temp_r3_253;

    if ((u8) this->unk0 != 0) {
        temp_r3_239 = this->unk20;
        if (temp_r3_239 != -1) {
            Sound_Stop(temp_r3_239);
            this->unk20 = -1;
        }
    }
    temp_r3_246 = this->unk1C;
    if (temp_r3_246 != -1) {
        Sound_UnloadBank(temp_r3_246);
        this->unk1C = -1;
    }
    temp_r3_253 = this->unk24;
    if (temp_r3_253 != -1) {
        Sound_UnloadBank(temp_r3_253);
        this->unk24 = -1;
    }
    if ((void *) this->unkC != NULL) {
        this->unkC = NULL;
        this->unk8 = 0;
    }
}

s32 KDSP_Sounds::WaitingForSoundPackage(int *arg0) {
    s32 temp_r3_286;
    s32 var_r31_281;

    var_r31_281 = 0;
    if ((s32) this->unk14 == (s32) this->unk10) {
        temp_r3_286 = *arg0;
        if ((temp_r3_286 != 0) && (MKPackage_QIsLoaded(temp_r3_286, NULL, NULL) == 0)) {
            var_r31_281 = 1;
        }
    }
    return var_r31_281;
}

#if 0 // DRAFT: function call 'Sound_Play3d(long, unsigned int, long, float, float)' does not match 'Sound_Play3d(int, unsigned char, MKVector3 *, float, float)'
s32 KDSP_Sounds::Update(int arg0, float arg1, int arg2, int *arg3, int *arg4) {
    KDSP_Actor *temp_r3_432;
    SoundBankHeader *temp_r3_390;
    s32 temp_r0_322;
    s32 temp_r0_354;
    s32 temp_r3_348;
    s32 temp_r3_363;
    s32 temp_r3_370;
    s32 temp_r3_422;
    s32 temp_r3_461;
    s32 temp_r3_473;
    s32 temp_r7_330;
    s32 var_ctr_323;
    s32 var_r31_318;
    s32 var_r3_321;
    s32 var_r4_438;
    s32 var_r8_320;
    u8 var_r5_328;
    void *temp_r6_329;

    *arg4 = -1;
    var_r31_318 = 1;
    this->unk10 = -1;
    var_r8_320 = 0;
    var_r3_321 = 0;
    temp_r0_322 = this->unk8;
    var_ctr_323 = temp_r0_322;
    if (temp_r0_322 > 0) {
loop_1:
        var_r5_328 = 0;
        temp_r6_329 = ((u8 *) this->unkC) + var_r3_321;
        temp_r7_330 = M2C_FIELD(temp_r6_329, s32 *, 0);
        if ((arg0 >= temp_r7_330) && (arg0 < (s32) (temp_r7_330 + M2C_FIELD(temp_r6_329, s32 *, 4)))) {
            var_r5_328 = 1;
        }
        if (var_r5_328 != 0) {
            this->unk10 = var_r8_320;
        } else {
            var_r8_320 += 1;
            var_r3_321 += 0x18;
            var_ctr_323 -= 1;
            if (var_ctr_323 != 0) {
                goto loop_1;
            }
        }
    }
    temp_r3_348 = this->unk10;
    if ((temp_r3_348 != -1) && (temp_r3_348 != (s32) this->unk18)) {
        temp_r0_354 = this->unk14;
        if (temp_r0_354 == temp_r3_348) {
            if (MKPackage_QIsLoaded(*arg3, NULL, NULL) != 0) {
                temp_r3_363 = this->unk20;
                if (temp_r3_363 != -1) {
                    Sound_Stop(temp_r3_363);
                    this->unk20 = -1;
                }
                temp_r3_370 = this->unk1C;
                if (temp_r3_370 != -1) {
                    Sound_UnloadBank(temp_r3_370);
                    this->unk1C = -1;
                }
                GetDynamicBankName(this->unk14);
                if (MKArchive_Exists(M2C_ERROR(/* Read from unset register $r3 */), NULL) != 0) {
                    GetDynamicBankName(this->unk14);
                    temp_r3_390 = (SoundBankHeader *) (MKArchive_Load(M2C_ERROR(/* Read from unset register $r3 */), NULL, NULL, -1));
                    this->unk1C = Sound_LoadBankFromMemory(temp_r3_390, 0U, -1);
                    if (MKHeap::Current() != NULL) {
                        ((MKHeap *) (MKHeap::Current()))->Free(temp_r3_390, NULL, 0);
                    } else {
                        free(temp_r3_390);
                    }
                }
                MKPackage_QFree(*arg3);
                *arg3 = 0;
                if (((u8) this->unk0 != 0) && ((u8) this->unk1 != 0)) {
                    GetDynamicSoundName(this->unk14);
                    temp_r3_422 = Sound_GetID(M2C_ERROR(/* Read from unset register $r3 */));
                    if (temp_r3_422 != 0) {
                        if (((u8) this->unk2 != 0) && (temp_r3_432 = M2C_FIELD((((u8 *) this->unkC) + (this->unk14 * 0x18)), KDSP_Actor **, 0x14), ((temp_r3_432 == NULL) == 0))) {
                            if (temp_r3_432->unk40 & 4) {
                                var_r4_438 = (long) (temp_r3_432->unk34);
                            } else {
                                var_r4_438 = MKModel_GetWorldMatrix(temp_r3_432->GetModel());
                            }
                            Sound_Play3d(temp_r3_422, 0xFFU, var_r4_438 + 0x30, 1000000.0f, 10000.0f);
                            this->unk20 = M2C_ERROR(/* Read from unset register $r3 */);
                        } else {
                            Sound_Play(temp_r3_422);
                            this->unk20 = M2C_ERROR(/* Read from unset register $r3 */);
                        }
                        if (arg1 != 1.0f) {
                            temp_r3_461 = this->unk20;
                            if (temp_r3_461 != -1) {
                                KDSound_SetPitch(temp_r3_461, arg1);
                            }
                        }
                    }
                }
                this->unk18 = this->unk14;
                this->unk14 = -1;
                temp_r3_473 = this->unk18 + 1;
                if (temp_r3_473 < (s32) this->unk8) {
                    this->unk14 = temp_r3_473;
                    GetDynamicBankName(this->unk14);
                    *arg3 = MKPackage_QLoadDynamic(M2C_ERROR(/* Read from unset register $r3 */), 0, NULL);
                }
            } else {
                var_r31_318 = 0;
            }
        } else if (temp_r0_354 != -1) {
            MKPackage_QCancel(*arg3);
            if (MKPackage_QIsLoaded(*arg3, NULL, NULL) != 0) {
                MKPackage_QFree(*arg3);
                *arg3 = 0;
                this->unk14 = this->unk10;
                GetDynamicBankName(this->unk14);
                *arg3 = MKPackage_QLoadDynamic(M2C_ERROR(/* Read from unset register $r3 */), 0, NULL);
            }
        } else {
            this->unk14 = temp_r3_348;
            GetDynamicBankName(this->unk14);
            *arg3 = MKPackage_QLoadDynamic(M2C_ERROR(/* Read from unset register $r3 */), 0, NULL);
        }
    }
    return var_r31_318;
}
#endif

void KDSP_Sounds::UnloadPlaying(int *arg0) {
    if (((s32) this->unk14 != -1) && (MKPackage_QIsLoaded(*arg0, NULL, NULL) != 0)) {
        MKPackage_QFree(*arg0);
        *arg0 = 0;
        this->unk14 = -1;
    }
}

s32 KDSP_Sounds::LoadDynamicSoundBank(int *arg0, bool arg1) {
    if ((s32) this->unk8 > 0) {
        this->unk14 = 0;
        GetDynamicBankName(0);
        *arg0 = MKPackage_QLoadDynamic(M2C_ERROR(/* Read from unset register $r3 */), 0, NULL);
        return 1;
    }
    return 0;
}

#if 0 // DRAFT: function call 'MKArchive_Exists(signed char *, int)' does not match 'MKArchive_Exists(const char *, int *)'
void KDSP_Sounds::LoadStaticSoundBank(const char *arg0, bool arg1) {
    SoundBankHeader *temp_r3_618;
    s8 *temp_r3_608;

    temp_r3_608 = Str_Printf("%s.gsb", "%s%s");
    if (MKArchive_Exists(temp_r3_608, NULL) != 0) {
        temp_r3_618 = MKArchive_Load(temp_r3_608, NULL, NULL, -1);
        this->unk24 = Sound_LoadBankFromMemory(temp_r3_618, 0U, -1);
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Main()))->TFree(temp_r3_618, NULL, 0);
            return;
        }
        free(temp_r3_618);
    }
}
#endif

void KDSP_Sounds::Init() {
    this->unk10 = 0;
    this->unk8 = 0;
    this->unkC = NULL;
    this->unk4 = NULL;
    this->unk14 = -1;
    this->unk18 = -1;
    this->unk1C = -1;
    this->unk20 = -1;
    this->unk24 = -1;
    System_GetCommandLineParameter("sound", 1U);
    this->unk0 = M2C_ERROR(/* Read from unset register $r3 */) != 0;
    this->unk1 = 1;
    this->unk2 = 0;
}
