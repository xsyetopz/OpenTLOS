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

void KDSP_Sounds::ResolveActors(KDSP_ActorList *arg0) {
    u8 *block;
    u8 *rec;
    u8 *entry;
    s32 i;
    s32 j;
    s32 k;

    i = 0;
    while (i < arg0->unk0) {
        block = (u8 *) arg0->unk4 + i * 0x138;
        j = 0;
        while (j < M2C_FIELD(block, s32 *, 0x54)) {
            rec = M2C_FIELD(block, u8 **, 0x58) + j * 0x24;
            k = 0;
            while (k < (s32) this->unk8) {
                entry = (u8 *) this->unkC + k * 0x18;
                if ((M2C_FIELD(entry, s32 *, 0) == M2C_FIELD(rec, s32 *, 0)) &&
                    (stricmp((s32) (entry + 8), (s32) (rec + 0xC)) == 0)) {
                    M2C_FIELD(entry, u8 **, 0x14) = block;
                }
                k += 1;
            }
            j += 1;
        }
        i += 1;
    }
}

void KDSP_Sounds::ParseDynamicSFX(KDSynkerHeap *arg0, MKIni *arg1) {
    MKIniLine *line;
    MKIniLine *cur;
    u8 *entry;
    u8 *start;
    s32 align;
    s32 count;

    line = this->unk4;
    if (line != NULL) {
        count = this->unk8;
        if (count != 0) {
            start = (u8 *) arg0->unk18;
            align = arg0->unk20 - 1;
            arg0->unk18 = start + ((count * 0x18 + align) & ~align);
            this->unkC = start;
            entry = (u8 *) this->unkC;
            cur = line->unkC->GetSubLine(line);
            while (cur != NULL) {
                M2C_FIELD(entry, s8 **, 8) = cur->GetFieldName();
                M2C_FIELD(entry, s32 *, 0xC) = -1;
                M2C_FIELD(entry, s32 *, 0x14) = 0;
                M2C_FIELD(entry, s32 *, 0) = cur->GetInt(0);
                M2C_FIELD(entry, s32 *, 4) = cur->GetInt(1);
                entry += 0x18;
                cur = cur->unkC->GetNextLine(cur);
            }
        }
    }
}

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

s32 KDSP_Sounds::Update(int arg0, float arg1, int arg2, int *arg3, int *arg4) {
    KDSP_Actor *actor;
    SoundBankHeader *bank;
    const char *lang;
    const char *name;
    u8 *entry;
    s32 result;
    s32 k;
    s32 count;
    s32 start;
    s32 cur;
    s32 temp;
    s32 id;
    s32 matrix;
    s32 next;

    *arg4 = -1;
    result = 1;
    this->unk10 = -1;
    k = 0;
    count = this->unk8;
    while (k < count) {
        entry = (u8 *) this->unkC + k * 0x18;
        start = M2C_FIELD(entry, s32 *, 0);
        if ((arg0 >= start) && (arg0 < start + M2C_FIELD(entry, s32 *, 4))) {
            this->unk10 = k;
            break;
        }
        k += 1;
    }
    temp = this->unk10;
    if ((temp != -1) && (temp != (s32) this->unk18)) {
        if (this->unk14 == temp) {
            if (MKPackage_QIsLoaded(*arg3, NULL, NULL) != 0) {
                cur = this->unk20;
                if (cur != -1) {
                    Sound_Stop(cur);
                    this->unk20 = -1;
                }
                cur = this->unk1C;
                if (cur != -1) {
                    Sound_UnloadBank(cur);
                    this->unk1C = -1;
                }
                entry = (u8 *) this->unkC + this->unk14 * 0x18;
                lang = ((const char *(*)(int)) GameLanguage_GetAudioCode)(-1);
                name = (const char *) Str_Printf("%s%s.gsb", M2C_FIELD(entry, s8 **, 8), lang);
                if ((u8) MKArchive_Exists(name, NULL) != 0) {
                    entry = (u8 *) this->unkC + this->unk14 * 0x18;
                    lang = ((const char *(*)(int)) GameLanguage_GetAudioCode)(-1);
                    name = (const char *) Str_Printf("%s%s.gsb", M2C_FIELD(entry, s8 **, 8), lang);
                    bank = (SoundBankHeader *) MKArchive_Load(name, NULL, NULL, -1);
                    this->unk1C = Sound_LoadBankFromMemory(bank, 0, -1);
                    if (MKHeap::Current() != NULL) {
                        ((MKHeap *) MKHeap::Current())->Free(bank, NULL, 0);
                    } else {
                        free(bank);
                    }
                }
                MKPackage_QFree(*arg3);
                *arg3 = 0;
                if (((u8) this->unk0 != 0) && ((u8) this->unk1 != 0)) {
                    entry = (u8 *) this->unkC + this->unk14 * 0x18;
                    lang = ((const char *(*)(int)) GameLanguage_GetAudioCode)(-1);
                    name = (const char *) Str_Printf("%s%s", M2C_FIELD(entry, s8 **, 8), lang);
                    id = Sound_GetID(name);
                    if (id != 0) {
                        actor = M2C_FIELD(entry, KDSP_Actor **, 0x14);
                        if (((u8) this->unk2 != 0) && (actor != NULL)) {
                            if (actor->unk40 & 4) {
                                matrix = (s32) actor->unk34;
                            } else {
                                matrix = MKModel_GetWorldMatrix(actor->GetModel());
                            }
                            this->unk20 = ((s32 (*)(int, unsigned char, MKVector3 *, float, float)) Sound_Play3d)(id, 0xFF, (MKVector3 *) (matrix + 0x30), 1000000.0f, 10000.0f);
                        } else {
                            this->unk20 = ((s32 (*)(int)) Sound_Play)(id);
                        }
                        if (arg1 != 1.0f) {
                            cur = this->unk20;
                            if (cur != -1) {
                                KDSound_SetPitch(cur, arg1);
                            }
                        }
                    }
                }
                this->unk18 = this->unk14;
                this->unk14 = -1;
                next = this->unk18 + 1;
                if (next < (s32) this->unk8) {
                    this->unk14 = next;
                    entry = (u8 *) this->unkC + this->unk14 * 0x18;
                    lang = ((const char *(*)(int)) GameLanguage_GetAudioCode)(-1);
                    name = (const char *) Str_Printf("%s%s.gsb", M2C_FIELD(entry, s8 **, 8), lang);
                    *arg3 = MKPackage_QLoadDynamic(name, 0, NULL);
                }
            } else {
                result = 0;
            }
        } else if (this->unk14 != -1) {
            MKPackage_QCancel(*arg3);
            if (MKPackage_QIsLoaded(*arg3, NULL, NULL) != 0) {
                MKPackage_QFree(*arg3);
                *arg3 = 0;
                this->unk14 = this->unk10;
                entry = (u8 *) this->unkC + this->unk14 * 0x18;
                lang = ((const char *(*)(int)) GameLanguage_GetAudioCode)(-1);
                name = (const char *) Str_Printf("%s%s.gsb", M2C_FIELD(entry, s8 **, 8), lang);
                *arg3 = MKPackage_QLoadDynamic(name, 0, NULL);
            }
        } else {
            this->unk14 = temp;
            entry = (u8 *) this->unkC + this->unk14 * 0x18;
            lang = ((const char *(*)(int)) GameLanguage_GetAudioCode)(-1);
            name = (const char *) Str_Printf("%s%s.gsb", M2C_FIELD(entry, s8 **, 8), lang);
            *arg3 = MKPackage_QLoadDynamic(name, 0, NULL);
        }
    }
    return result;
}

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

void KDSP_Sounds::LoadStaticSoundBank(const char *arg0, bool arg1) {
    const char *name;
    SoundBankHeader *bank;

    name = (const char *) Str_Printf("%s.gsb", arg0);
    if ((u8) MKArchive_Exists(name, NULL) != 0) {
        bank = (SoundBankHeader *) MKArchive_Load(name, NULL, NULL, -1);
        this->unk24 = Sound_LoadBankFromMemory(bank, 0, -1);
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) MKHeap::Main())->TFree(bank, NULL, 0);
        } else {
            free(bank);
        }
    }
}

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
