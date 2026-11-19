#include "spyro/source/KDSynkerPlayerEvents.h"
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
#include "spyro/source/KDBasicEnvelope.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSynkerPlayer3.h"
#include "spyro/source/KDSynkerPlayerActor.h"
#include "spyro/source/KDSynkerPlayerActorList.h"
#include "spyro/source/KDSynkerPlayerCamera.h"
#include "spyro/source/KDSynkerPlayerSounds.h"
#include "spyro/source/KDSynkerPlayerTools.h"
#include "spyro/source/Level.h"
#include "common/Source/Str.h"
#include "common/Source/system_extras.h"
#include "common/gc/Sound_GC.h"
#include <m2c_macros.h>

s32 stricmp(s8 *);                                  /* extern */
KDSynkerPlayerEvent loadInfo__19KDSynkerPlayerEvent;
KDSynkerPlayerEvent updateData__19KDSynkerPlayerEvent;

#if 0 // DRAFT: identifier 'PLAYSOUND3D_STRING' redeclared
static s8 *PLAYSOUND3D_STRING = "PlaySound3D";
#endif
#if 0 // DRAFT: identifier 'HEADTWEEN_STRING' redeclared
static s8 *HEADTWEEN_STRING = .L_8035FFF4;
#endif

#if 0 // DRAFT: declaration syntax error
static s8 .L_8035FFF4[0x5D] = {
    0x48,
    0x65,
    0x61,
    0x64,
    0x54,
    0x77,
    0x65,
    0x65,
    0x6E,
    0,
    0x74,
    0x79,
    0x70,
    0x65,
    0,
    0x45,
    0x56,
    0x45,
    0x4E,
    0x54,
    0x5F,
    0x25,
    0x64,
    0,
    0x65,
    0x6E,
    0x76,
    0,
    0x42,
    0x61,
    0x72,
    0x4E,
    0x61,
    0x6D,
    0x65,
    0,
    0x73,
    0x74,
    0x61,
    0x72,
    0x74,
    0,
    0x6C,
    0x65,
    0x6E,
    0x67,
    0x74,
    0x68,
    0,
    0x62,
    0x72,
    0x65,
    0x61,
    0x6B,
    0x65,
    0x72,
    0,
    0x50,
    0x72,
    0x6F,
    0x70,
    0,
    0x53,
    0x6F,
    0x75,
    0x6E,
    0x64,
    0,
    0x50,
    0x6F,
    0x73,
    0x69,
    0x74,
    0x69,
    0x6F,
    0x6E,
    0,
    0x4E,
    0x6F,
    0x64,
    0x65,
    0,
    0x45,
    0x56,
    0x45,
    0x4E,
    0x54,
    0x5F,
    0x44,
    0x41,
    0x54,
    0x41,
    0,
}; /* const */

void KDSynkerPlayerEvent::Load(MKIniLine *arg0) {
    MKIniLine *temp_r3_27;

    ((KDSynkerPlayerEventLoadInfo *) &KDSynkerPlayerEvent::loadInfo)->Init();
    Init();
    temp_r3_27 = arg0->unkC->GetSubLine(arg0);
    KDSynkerPlayerEvent::pLine.__vptr = temp_r3_27->unkC->GetNextLine(temp_r3_27);
loop_2:
    if ((void *) KDSynkerPlayerEvent::pLine.__vptr != NULL) {
        LoadLine();
        KDSynkerPlayerEvent::pLine.__vptr = ((MKIni *) (M2C_FIELD(KDSynkerPlayerEvent::pLine.__vptr, MKIni **, 0xC)))->GetNextLine((MKIniLine *) KDSynkerPlayerEvent::pLine.__vptr);
        goto loop_2;
    }
    LoadDone();
}
#endif

s32 KDSynkerPlayerEvent::LoadProp(const char *arg0, MKProp **arg1) {
    s32 sp8;
    u8 temp_ret_68;

    temp_ret_68 = LoadInt(arg0, (int *) &sp8);
    if (temp_ret_68 != 0) {
        *arg1 = ((MKSceneManager *) sp8)->PropResolver_Resolve((s32) (u32) (u64) temp_ret_68);
        return 1;
    }
    return 0;
}

#if 0 // DRAFT: undefined identifier '__vptr'
s32 KDSynkerPlayerEvent::LoadVector3(const char *arg0, MKVector3 *arg1) {
    MKIniLine sp8;

    if (((MKIniLine *) KDSynkerPlayerEvent::pLine.__vptr)->IsField(arg0) != 0) {
        sp8.GetVector3((s32) KDSynkerPlayerEvent::pLine.__vptr);
        M2C_FIELD(arg1, f64 *, 0) = M2C_BITWISE(f64, sp8);
        M2C_FIELD(arg1, f64 *, 8) = M2C_BITWISE(f64, sp8.unk8);
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
s32 KDSynkerPlayerEvent::LoadFloat(const char *arg0, float *arg1) {
    if (((MKIniLine *) KDSynkerPlayerEvent::pLine.__vptr)->IsField(arg0) != 0) {
        *arg1 = ((MKIniLine *) KDSynkerPlayerEvent::pLine.__vptr)->GetFloat(0);
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
s32 KDSynkerPlayerEvent::LoadString(const char *arg0, char *arg1) {
    if (((MKIniLine *) KDSynkerPlayerEvent::pLine.__vptr)->IsField(arg0) != 0) {
        strcpy(arg1, ((MKIniLine *) KDSynkerPlayerEvent::pLine.__vptr)->GetString(0));
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
s32 KDSynkerPlayerEvent::LoadBool(const char *arg0, bool *arg1) {
    if (((MKIniLine *) KDSynkerPlayerEvent::pLine.__vptr)->IsField(arg0) != 0) {
        *arg1 = ((MKIniLine *) KDSynkerPlayerEvent::pLine.__vptr)->GetInt(0) != 0;
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
u8 KDSynkerPlayerEvent::LoadInt(const char *arg0, int *arg1) {
    if (((MKIniLine *) KDSynkerPlayerEvent::pLine.__vptr)->IsField(arg0) != 0) {
        *arg1 = ((MKIniLine *) KDSynkerPlayerEvent::pLine.__vptr)->GetInt(0);
        return 1U;
    }
    return 0U;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void KDSynkerPlayerEvent::LoadNode(const char *arg0, MKModel **arg1, int *arg2) {
    NodeLoadLine1((KDSynkerPlayer3 *) KDSynkerPlayerEvent::pSynker.__vptr, (MKIniLine *) KDSynkerPlayerEvent::pLine.__vptr, arg0, arg1, NULL, NULL, arg2);
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
s32 KDSynkerPlayerEvent::LoadActorModel(const char *arg0, MKModel **arg1) {
    s32 sp8;

    if (LoadActorID(arg0, (int *) &sp8) != 0) {
        ((KDSynkerPlayer3 *) KDSynkerPlayerEvent::pSynker.__vptr)->GetActorModel(sp8);
        *arg1 = M2C_ERROR(/* Read from unset register $r3 */);
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
s32 KDSynkerPlayerEvent::LoadActorAnimScript(const char *arg0, MKAnimScript **arg1) {
    s32 sp8;

    if (LoadActorID(arg0, (int *) &sp8) != 0) {
        *arg1 = ((KDSynkerPlayer3 *) KDSynkerPlayerEvent::pSynker.__vptr)->GetActorAnimScript(sp8);
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
u8 KDSynkerPlayerEvent::LoadActorID(const char *arg0, int *arg1) {
    if (((MKIniLine *) KDSynkerPlayerEvent::pLine.__vptr)->IsField(arg0) != 0) {
        *arg1 = ((KDSP_ActorList *) (KDSynkerPlayerEvent::pSynker.__vptr + 0x100))->GetActorId(((MKIniLine *) KDSynkerPlayerEvent::pLine.__vptr)->GetString(0));
        return 1U;
    }
    return 0U;
}
#endif

void KDSynkerPlayerEventLoadInfo::Init() {
    this->unk0 = -1;
    this->unk8 = 0;
    this->unk4 = 0;
    this->unkC = 0;
}

#if 0 // DRAFT: function call 'stricmp(const char *)' does not match
KDSynkerPlayerEvent *KDSP_Events::CreateEvent(const char *arg0) {
    KDSynkerPlayerEventCreationTable *var_r31_364;

    var_r31_364 = this->unk24;
loop_4:
    if ((u32) var_r31_364->unk0 == 0) {
        return NULL;
    }
    if (stricmp(arg0) == 0) {
        return M2C_FIELD(var_r31_364, KDSynkerPlayerEvent *(**)(), 4)();
    }
    var_r31_364 += 8;
    goto loop_4;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void KDSP_Events::UpdateSfx(KDSP_ActorList *arg0, int arg1, float arg2) {
    MKVector3 sp10;
    s32 sp8;
    MKModel *temp_r0_435;
    MKProp *var_r28_424;
    MKVector3 *var_r8_425;
    s32 temp_r3_412;
    s32 temp_r5_409;
    s32 var_r24_404;
    s32 var_r30_403;
    u8 temp_r23_468;
    u8 var_r29_423;
    u8 var_r31_413;
    u8 var_r5_460;
    void *temp_r3_486;
    void *temp_r4_408;
    void *temp_r6_461;
    void *var_r3_426;

    var_r30_403 = 0;
    var_r24_404 = 0;
loop_26:
    if (var_r30_403 < (s32) this->unk1C) {
        temp_r4_408 = ((u8 *) this->unk20) + var_r24_404;
        temp_r5_409 = M2C_FIELD(temp_r4_408, s32 *, 0x14);
        if (!(temp_r5_409 & 1)) {
            temp_r3_412 = M2C_FIELD(temp_r4_408, s32 *, 0);
            var_r31_413 = 0;
            if ((arg1 >= temp_r3_412) && (arg1 < (s32) (temp_r3_412 + M2C_FIELD(temp_r4_408, s32 *, 4)))) {
                var_r31_413 = 1;
            }
            var_r29_423 = var_r31_413;
            var_r28_424 = NULL;
            var_r8_425 = NULL;
            var_r3_426 = NULL;
            if (temp_r5_409 & 8) {
                MKModel_CalculateNodeWorldPosition(M2C_FIELD(temp_r4_408, MKModel **, 0x18), M2C_FIELD(temp_r4_408, s32 *, 0x1C), &sp10);
                var_r8_425 = &sp10;
            } else {
                temp_r0_435 = M2C_FIELD(temp_r4_408, MKModel **, 0x18);
                if (temp_r0_435 != (MKModel *)-1) {
                    var_r3_426 = arg0->unk4 + ((s32) temp_r0_435 * 0x138);
                }
                if ((var_r3_426 != NULL) && (M2C_FIELD(var_r3_426, s32 *, 0x40) & 4)) {
                    var_r8_425 = M2C_FIELD(var_r3_426, s32 *, 0x34) + 0x30;
                } else if (var_r3_426 != NULL) {
                    var_r28_424 = M2C_FIELD(var_r3_426, MKProp **, 0x30);
                } else {
                    var_r28_424 = NULL;
                }
            }
            var_r5_460 = 0;
            temp_r6_461 = ((u8 *) this->unk20) + var_r24_404;
            sp8 = ((u32) M2C_FIELD(temp_r6_461, u32 *, 0x14) >> 1U) & 1;
            temp_r23_468 = M2C_FIELD(temp_r6_461, s32 *, 0x10) != 0;
            if ((var_r28_424 != NULL) || (var_r8_425 != NULL)) {
                var_r5_460 = 1;
            }
            ((KDSoundPlayer *) (((u8 *) temp_r6_461) + 0x10))->Update(M2C_FIELD(temp_r6_461, s32 *, 0xC), var_r5_460, var_r31_413, var_r28_424, var_r8_425, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
            if ((var_r31_413 != 0) && (temp_r23_468 != 0)) {
                temp_r3_486 = ((u8 *) this->unk20) + var_r24_404;
                if ((s32) M2C_FIELD(temp_r3_486, s32 *, 0x10) == 0) {
                    var_r29_423 = 0;
                    M2C_FIELD(temp_r3_486, s32 *, 0x14) = (s32) (M2C_FIELD(temp_r3_486, s32 *, 0x14) | 1);
                }
            }
            if ((var_r29_423 != 0) && (arg2 != 1.0f)) {
                KDSound_SetPitch(*(this->unk20 + (var_r24_404 + 0x10)), arg2);
            }
        }
        var_r30_403 += 1;
        var_r24_404 += 0x20;
        goto loop_26;
    }
}
#endif

#if 0 // DRAFT: function call 'KDSound_Stop(unsigned char *)' does not match
void KDSP_Events::StopSfx() {
    s32 var_r30_529;
    s32 var_r31_530;

    var_r30_529 = 0;
    var_r31_530 = 0;
loop_2:
    if (var_r30_529 < (s32) this->unk1C) {
        KDSound_Stop(((u8 *) this->unk20) + (var_r31_530 + 0x10));
        var_r30_529 += 1;
        var_r31_530 += 0x20;
        goto loop_2;
    }
}
#endif

void KDSP_Events::SkipToEnd() {
    s32 temp_r4_564;
    s32 var_r30_558;
    s32 var_r31_559;
    void **temp_r29_567;
    void *temp_r5_563;

    var_r30_558 = 0;
    var_r31_559 = 0;
loop_9:
    if (var_r30_558 < (s32) this->unkC) {
        temp_r5_563 = ((u8 *) this->unk10) + var_r31_559;
        temp_r4_564 = M2C_FIELD(temp_r5_563, s32 *, 0xC);
        temp_r29_567 = M2C_FIELD(M2C_FIELD(temp_r5_563, void **, 8), void ***, 8);
        if (temp_r4_564 & 1) {
            if (!(temp_r4_564 & 2)) {
                M2C_FIELD(temp_r5_563, s32 *, 0xC) = (s32) (temp_r4_564 | 2);
                if (temp_r29_567 != NULL) {
                    M2C_FIELD(*temp_r29_567, M2C_UNK (**)(void **), 0x18)(temp_r29_567);
                    M2C_FIELD(*temp_r29_567, M2C_UNK (**)(void **), 0x1C)(temp_r29_567);
                    M2C_FIELD(*temp_r29_567, M2C_UNK (**)(void **), 0x20)(temp_r29_567);
                }
            }
        } else if ((temp_r29_567 != NULL) && (temp_r4_564 & 4)) {
            M2C_FIELD(temp_r5_563, s32 *, 0xC) = (s32) (temp_r4_564 & 0xFFFFFFFB);
            M2C_FIELD(*temp_r29_567, M2C_UNK (**)(void **), 0x20)(temp_r29_567);
        }
        var_r30_558 += 1;
        var_r31_559 += 0x14;
        goto loop_9;
    }
}

#if 0 // DRAFT: illegal type
void KDSP_Events::Deinit() {
    s32 var_r28_636;
    s32 var_r30_635;
    void **temp_r3_642;

    if ((void *) this->unk20 != NULL) {
        this->unk20 = NULL;
        this->unk1C = 0;
    }
    if ((void *) this->unk8 != NULL) {
        var_r30_635 = 0;
        var_r28_636 = 0;
loop_7:
        if (var_r28_636 < (s32) this->unk4) {
            temp_r3_642 = *(this->unk8 + (var_r30_635 + 8));
            if (temp_r3_642 != NULL) {
                M2C_FIELD(*temp_r3_642, M2C_UNK (**)(), 0xC)();
                operator delete(*(this->unk8 + (var_r30_635 + 8)));
                *(this->unk8 + (var_r30_635 + 8)) = 0;
            }
            var_r28_636 += 1;
            var_r30_635 += 0x10;
            goto loop_7;
        }
        this->unk4 = 0;
        this->unk8 = NULL;
    }
    if ((void *) this->unk10 != NULL) {
        this->unkC = 0;
        this->unk10 = NULL;
    }
    if ((void *) this->unk18 != NULL) {
        this->unk18 = NULL;
        this->unk14 = 0;
    }
}
#endif

#if 0 // DRAFT: function call 'strnicmp(long, unsigned char[4], int)' does not match
u8 KDSP_Events::IsTweenAnimEvent(const char *arg0) {
    MKIniLine *temp_r3_703;
    MKIniLine *temp_r4_701;
    void *temp_r3_695;

    temp_r3_695 = FindEvent(arg0);
    if (temp_r3_695 == NULL) {
        return 0U;
    }
    temp_r4_701 = M2C_FIELD(temp_r3_695, MKIniLine **, 4);
    temp_r3_703 = temp_r4_701->unkC->GetSubLine(temp_r4_701);
    if ((temp_r3_703 != NULL) && (temp_r3_703->IsField("") != 0)) {
        return strnicmp(temp_r3_703->GetString(0), HEADTWEEN_STRING, 9) == 0;
    }
    return 0U;
}
#endif

#if 0 // DRAFT: function call 'strnicmp(unsigned char[4], long, int)' does not match
u8 KDSP_Events::IsSoundEvent(const char *arg0) {
    MKIniLine *temp_r3_746;
    MKIniLine *temp_r4_744;
    void *temp_r3_738;

    temp_r3_738 = FindEvent(arg0);
    if (temp_r3_738 == NULL) {
        return 0U;
    }
    temp_r4_744 = M2C_FIELD(temp_r3_738, MKIniLine **, 4);
    temp_r3_746 = temp_r4_744->unkC->GetSubLine(temp_r4_744);
    if ((temp_r3_746 != NULL) && (temp_r3_746->IsField("") != 0)) {
        return strnicmp(PLAYSOUND3D_STRING, temp_r3_746->GetString(0), 9) == 0;
    }
    return 0U;
}
#endif

#if 0 // DRAFT: illegal type
void *KDSP_Events::FindEvent(const char *arg0) {
    s32 var_r30_785;
    s32 var_r31_786;

    var_r30_785 = 0;
    var_r31_786 = 0;
loop_5:
    if (var_r30_785 >= (s32) this->unk4) {
        return NULL;
    }
    if (((u32) *(this->unk8 + var_r31_786) != 0U) && (stricmp(arg0) == 0)) {
        return ((u8 *) this->unk8) + var_r31_786;
    }
    var_r30_785 += 1;
    var_r31_786 += 0x10;
    goto loop_5;
}
#endif

void KDSP_Events::UpdateTweenAnims(int arg0, KDSP_EnvelopeList *arg1) {
    Animation *temp_r25_905;
    f32 var_f31_872;
    s32 *temp_r24_890;
    s32 temp_r6_835;
    s32 var_r26_829;
    s32 var_r31_828;
    u8 var_r3_833;
    void *temp_r30_834;

    var_r31_828 = 0;
    var_r26_829 = 0;
loop_15:
    if (var_r31_828 < (s32) this->unk14) {
        var_r3_833 = 0;
        temp_r30_834 = ((u8 *) this->unk18) + var_r26_829;
        temp_r6_835 = M2C_FIELD(temp_r30_834, s32 *, 0);
        if ((arg0 >= temp_r6_835) && (arg0 < (s32) (temp_r6_835 + M2C_FIELD(temp_r30_834, s32 *, 4)))) {
            var_r3_833 = 1;
        }
        if ((var_r3_833 != 0) && ((void *) M2C_FIELD(temp_r30_834, void **, 8) != NULL) && ((s32) M2C_FIELD(temp_r30_834, s32 *, 0xC) != -1)) {
            var_f31_872 = ((f32) arg0 - (f32) temp_r6_835) / (f32) M2C_FIELD(temp_r30_834, s32 *, 4);
            if (var_f31_872 < 1.0f) {

            } else {
                var_f31_872 = 1.0f;
            }
            if (var_f31_872 > 0.0f) {

            } else {
                var_f31_872 = 0.0f;
            }
            temp_r24_890 = arg1->GetEnvelope(M2C_FIELD(temp_r30_834, s32 *, 0x18));
            ((Animation *) (MKModel_GetAnimation(M2C_FIELD(M2C_FIELD(M2C_FIELD(temp_r30_834, void **, 8), void **, 0x38), MKModel **, 8))))->TweenNode(M2C_FIELD(temp_r30_834, f32 *, 0x10), 1.0f, M2C_FIELD(temp_r30_834, s32 *, 0xC), 1U, 1U);
            temp_r25_905 = MKModel_GetAnimation(M2C_FIELD(M2C_FIELD(M2C_FIELD(temp_r30_834, void **, 8), void **, 0x38), MKModel **, 8));
            temp_r25_905->TweenNode(M2C_FIELD(temp_r30_834, f32 *, 0x14), ((KDBasicEnvelope *) temp_r24_890)->GetValue(var_f31_872), M2C_FIELD(temp_r30_834, s32 *, 0xC), 1U, 1U);
        }
        var_r31_828 += 1;
        var_r26_829 += 0x1C;
        goto loop_15;
    }
}

#if 0 // DRAFT: undefined identifier '__vptr'
void KDSP_Events::Update(KDSynkerPlayer3 *arg0, float arg1, bool arg2) {
    f32 var_f0_1065;
    f32 var_f1_1030;
    s32 *var_r3_1007;
    s32 temp_r29_953;
    s32 temp_r3_1082;
    s32 temp_r3_1098;
    s32 temp_r3_1116;
    s32 temp_r3_960;
    s32 temp_r4_976;
    s32 var_r28_949;
    s32 var_r31_943;
    u8 var_r26_973;
    u8 var_r3_964;
    u8 var_r3_977;
    void **temp_r25_990;
    void *temp_r27_959;

    var_r31_943 = 0;
    KDSynkerPlayerEvent::pSynker.__vptr = arg0;
    var_r28_949 = 0;
    M2C_FIELD(&KDSynkerPlayerEvent::updateData, f32 *, 4) = arg1;
    KDSynkerPlayerEvent::updateData.__vptr = 0.0f;
    temp_r29_953 = (s32) arg1;
    M2C_FIELD(&KDSynkerPlayerEvent::updateData, s32 *, 0xC) = 0;
    M2C_FIELD(&KDSynkerPlayerEvent::updateData, s32 *, 8) = 0;
loop_41:
    if (var_r28_949 < (s32) this->unkC) {
        temp_r27_959 = ((u8 *) this->unk10) + var_r31_943;
        temp_r3_960 = M2C_FIELD(temp_r27_959, s32 *, 0xC);
        if (temp_r3_960 & 1) {
            var_r3_964 = 0;
            if (!(temp_r3_960 & 2) && (temp_r29_953 > 0) && (temp_r29_953 >= (s32) M2C_FIELD(temp_r27_959, s32 *, 0))) {
                var_r3_964 = 1;
            }
            var_r26_973 = var_r3_964;
        } else {
            temp_r4_976 = M2C_FIELD(temp_r27_959, s32 *, 0);
            var_r3_977 = 0;
            if ((temp_r29_953 >= temp_r4_976) && (temp_r29_953 < (s32) (temp_r4_976 + M2C_FIELD(temp_r27_959, s32 *, 4)))) {
                var_r3_977 = 1;
            }
            var_r26_973 = var_r3_977;
        }
        temp_r25_990 = M2C_FIELD(M2C_FIELD(temp_r27_959, void **, 8), void ***, 8);
        if (var_r26_973 != 0) {
            M2C_FIELD(temp_r27_959, s32 *, 0xC) = (s32) (M2C_FIELD(temp_r27_959, s32 *, 0xC) | 2);
            if (temp_r25_990 != NULL) {
                M2C_FIELD(&KDSynkerPlayerEvent::updateData, s32 *, 8) = (s32) M2C_FIELD(temp_r27_959, s32 *, 0);
                M2C_FIELD(&KDSynkerPlayerEvent::updateData, s32 *, 0xC) = (s32) M2C_FIELD(temp_r27_959, s32 *, 4);
                if ((s32) M2C_FIELD(KDSynkerPlayerEvent::pSynker.__vptr, s32 *, 0x114) > 0) {
                    var_r3_1007 = ((KDSP_EnvelopeList *) (KDSynkerPlayerEvent::pSynker.__vptr + 0x114))->GetEnvelope(M2C_FIELD(temp_r27_959, s32 *, 0x10));
                } else {
                    var_r3_1007 = NULL;
                }
                if (var_r3_1007 != NULL) {
                    var_f1_1030 = (arg1 - (f32) M2C_FIELD(temp_r27_959, s32 *, 0)) / (f32) M2C_FIELD(temp_r27_959, s32 *, 4);
                    if (var_f1_1030 < 1.0f) {

                    } else {
                        var_f1_1030 = 1.0f;
                    }
                    if (var_f1_1030 > 0.0f) {

                    } else {
                        var_f1_1030 = 0.0f;
                    }
                    KDSynkerPlayerEvent::updateData.__vptr = ((KDBasicEnvelope *) var_r3_1007)->GetValue(var_f1_1030);
                } else {
                    var_f0_1065 = (arg1 - (f32) M2C_FIELD(temp_r27_959, s32 *, 0)) / (f32) M2C_FIELD(temp_r27_959, s32 *, 4);
                    if (var_f0_1065 < 1.0f) {

                    } else {
                        var_f0_1065 = 1.0f;
                    }
                    if (var_f0_1065 > 0.0f) {

                    } else {
                        var_f0_1065 = 0.0f;
                    }
                    KDSynkerPlayerEvent::updateData.__vptr = var_f0_1065;
                }
                temp_r3_1082 = M2C_FIELD(temp_r27_959, s32 *, 0xC);
                if (!(temp_r3_1082 & 4)) {
                    M2C_FIELD(temp_r27_959, s32 *, 0xC) = (s32) (temp_r3_1082 | 4);
                    M2C_FIELD(*temp_r25_990, M2C_UNK (**)(void **), 0x18)(temp_r25_990);
                }
                M2C_FIELD(*temp_r25_990, M2C_UNK (**)(void **), 0x1C)(temp_r25_990);
                temp_r3_1098 = M2C_FIELD(temp_r27_959, s32 *, 0xC);
                if (temp_r3_1098 & 1) {
                    M2C_FIELD(temp_r27_959, s32 *, 0xC) = (s32) (temp_r3_1098 & 0xFFFFFFFB);
                    M2C_FIELD(*temp_r25_990, M2C_UNK (**)(void **), 0x20)(temp_r25_990);
                }
            }
        }
        if (((var_r26_973 == 0) || (arg2 != 0)) && (temp_r25_990 != NULL)) {
            temp_r3_1116 = M2C_FIELD(temp_r27_959, s32 *, 0xC);
            if (temp_r3_1116 & 4) {
                M2C_FIELD(temp_r27_959, s32 *, 0xC) = (s32) (temp_r3_1116 & 0xFFFFFFFB);
                M2C_FIELD(*temp_r25_990, M2C_UNK (**)(void **), 0x20)(temp_r25_990);
            }
        }
        var_r28_949 += 1;
        var_r31_943 += 0x14;
        goto loop_41;
    }
}
#endif

void KDSP_Events::Draw() {
    s32 var_r30_1150;
    s32 var_r31_1151;
    void **temp_r3_1157;
    void *temp_r4_1155;

    var_r30_1150 = 0;
    var_r31_1151 = 0;
loop_5:
    if (var_r30_1150 < (s32) this->unkC) {
        temp_r4_1155 = ((u8 *) this->unk10) + var_r31_1151;
        temp_r3_1157 = M2C_FIELD(M2C_FIELD(temp_r4_1155, void **, 8), void ***, 8);
        if ((temp_r3_1157 != NULL) && (M2C_FIELD(temp_r4_1155, s32 *, 0xC) & 4)) {
            M2C_FIELD(*temp_r3_1157, M2C_UNK (**)(), 0x24)();
        }
        var_r30_1150 += 1;
        var_r31_1151 += 0x14;
        goto loop_5;
    }
}

#if 0 // DRAFT: undefined identifier '__vptr'
void KDSP_Events::Parse(KDSynkerPlayer3 *arg0, KDSynkerHeap *arg1, const char *arg2, MKIni *arg3, bool arg4, KDSP_ActorList *arg5) {
    s32 sp18;
    s8 *sp14;
    s32 sp10;
    s32 spC;
    u8 sp8;
    KDSynkerPlayerEvent *temp_r3_1609;
    MKIniLine *temp_r19_1589;
    MKIniLine *temp_r23_1460;
    MKIniLine *temp_r3_1298;
    MKIniLine *temp_r3_1400;
    MKIniLine *temp_r3_1462;
    MKIniLine *temp_r4_1194;
    MKIniLine *temp_r4_1398;
    MKIniLine *temp_r4_1456;
    MKIniLine *temp_r4_1459;
    MKIniLine *temp_r4_1585;
    MKIniLine *var_r18_1467;
    MKIniLine *var_r22_1213;
    MKIniLine *var_r23_1317;
    MKIniLine *var_r23_1405;
    MKIniLine *var_r28_1304;
    s32 temp_r0_1197;
    s32 temp_r0_1243;
    s32 temp_r0_1256;
    s32 temp_r0_1269;
    s32 temp_r3_1203;
    s32 temp_r3_1249;
    s32 temp_r3_1262;
    s32 temp_r3_1275;
    s32 temp_r4_1432;
    s32 var_r18_1580;
    s32 var_r20_1579;
    s32 var_r26_1288;
    u8 var_r19_1323;
    void *temp_r21_1584;
    void *temp_r3_1377;
    void *temp_r3_1516;
    void *temp_r4_1248;
    void *temp_r4_1261;
    void *temp_r4_1274;
    void *temp_r5_1202;
    void *var_r21_1209;
    void *var_r27_1282;
    void *var_r29_1286;
    void *var_r31_1284;

    KDSynkerPlayerEvent::pSynker.__vptr = arg0;
    temp_r4_1194 = this->unk0;
    if (temp_r4_1194 != NULL) {
        temp_r0_1197 = this->unk4;
        if (temp_r0_1197 != 0) {
            temp_r5_1202 = arg1->unkC;
            temp_r3_1203 = arg1->unk14 - 1;
            arg1->unkC = ((u8 *) temp_r5_1202) + (((temp_r0_1197 * 0x10) + temp_r3_1203) & ~temp_r3_1203);
            this->unk8 = temp_r5_1202;
            var_r21_1209 = this->unk8;
            var_r22_1213 = temp_r4_1194->unkC->GetSubLine(temp_r4_1194);
loop_4:
            if (var_r22_1213 != NULL) {
                M2C_FIELD(var_r21_1209, s8 **, 0) = var_r22_1213->GetFieldName();
                M2C_FIELD(var_r21_1209, MKIniLine **, 4) = var_r22_1213;
                M2C_FIELD(var_r21_1209, s32 *, 8) = 0;
                M2C_FIELD(var_r21_1209, s32 *, 0xC) = 0;
                var_r22_1213 = var_r22_1213->unkC->GetNextLine(var_r22_1213);
                var_r21_1209 += 0x10;
                goto loop_4;
            }
        }
    }
    if (((s32) this->unkC != 0) || ((s32) this->unk1C != 0) || ((s32) this->unk14 != 0)) {
        if (arg4 != 0) {
            temp_r0_1243 = this->unk1C;
            if (temp_r0_1243 != 0) {
                temp_r4_1248 = arg1->unk18;
                temp_r3_1249 = arg1->unk20 - 1;
                arg1->unk18 = ((u8 *) temp_r4_1248) + (((temp_r0_1243 << 5) + temp_r3_1249) & ~temp_r3_1249);
                this->unk20 = temp_r4_1248;
            }
        }
        temp_r0_1256 = this->unkC;
        if (temp_r0_1256 != 0) {
            temp_r4_1261 = arg1->unk18;
            temp_r3_1262 = arg1->unk20 - 1;
            arg1->unk18 = ((u8 *) temp_r4_1261) + (((temp_r0_1256 * 0x14) + temp_r3_1262) & ~temp_r3_1262);
            this->unk10 = temp_r4_1261;
        }
        temp_r0_1269 = this->unk14;
        if (temp_r0_1269 != 0) {
            temp_r4_1274 = arg1->unk18;
            temp_r3_1275 = arg1->unk20 - 1;
            arg1->unk18 = ((u8 *) temp_r4_1274) + (((temp_r0_1269 * 0x1C) + temp_r3_1275) & ~temp_r3_1275);
            this->unk18 = temp_r4_1274;
        }
        var_r27_1282 = this->unk10;
        var_r31_1284 = this->unk20;
        var_r29_1286 = this->unk18;
        var_r26_1288 = 0;
        sp18 = 0;
        do {
            temp_r3_1298 = arg3->GotoLine(Str_Printf("", var_r26_1288), NULL);
            if (temp_r3_1298 != NULL) {
                var_r28_1304 = temp_r3_1298->unkC->GetSubLine(temp_r3_1298);
loop_58:
                if (var_r28_1304 != NULL) {
                    sp14 = NULL;
                    sp10 = -1;
                    spC = -1;
                    sp8 = 0;
                    var_r23_1317 = var_r28_1304->unkC->GetSubLine(var_r28_1304);
loop_27:
                    if (var_r23_1317 != NULL) {
                        var_r19_1323 = 0;
                        if ((var_r23_1317->LoadInt("", (int *) &sp18, 0) != 0) || (var_r23_1317->LoadString("", &sp14, 0) != 0) || (var_r23_1317->LoadInt("", (int *) &sp10, 0) != 0) || (var_r23_1317->LoadInt("", (int *) &spC, 0) != 0)) {
                            var_r19_1323 = 1;
                        }
                        if (var_r19_1323 == 0) {
                            var_r23_1317->LoadBool("", &sp8, 0);
                        }
                        var_r23_1317 = var_r23_1317->unkC->GetNextLine(var_r23_1317);
                        goto loop_27;
                    }
                    temp_r3_1377 = FindEvent(sp14);
                    if (temp_r3_1377 != NULL) {
                        M2C_FIELD(temp_r3_1377, s32 *, 0xC) = (s32) (M2C_FIELD(temp_r3_1377, s32 *, 0xC) + 1);
                        if (IsTweenAnimEvent(sp14) != 0) {
                            M2C_FIELD(var_r29_1286, s32 *, 0) = sp10;
                            M2C_FIELD(var_r29_1286, s32 *, 4) = spC;
                            M2C_FIELD(var_r29_1286, s32 *, 0x18) = sp18;
                            M2C_FIELD(var_r29_1286, KDSP_Actor **, 8) = NULL;
                            M2C_FIELD(var_r29_1286, s32 *, 0xC) = -1;
                            temp_r4_1398 = M2C_FIELD(temp_r3_1377, MKIniLine **, 4);
                            temp_r3_1400 = temp_r4_1398->unkC->GetSubLine(temp_r4_1398);
                            var_r23_1405 = temp_r3_1400->unkC->GetNextLine(temp_r3_1400);
loop_34:
                            if (var_r23_1405 != NULL) {
                                if (var_r23_1405->IsField("") != 0) {
                                    M2C_FIELD(var_r29_1286, KDSP_Actor **, 8) = (KDSP_Actor *) (arg5->unk4 + (arg5->GetActorId(var_r23_1405->GetString(0)) * 0x138));
                                }
                                var_r23_1405 = var_r23_1405->unkC->GetNextLine(var_r23_1405);
                                goto loop_34;
                            }
                            temp_r4_1432 = M2C_FIELD(var_r29_1286, s32 *, 0);
                            ((KDSP_Actor *) (M2C_FIELD(var_r29_1286, KDSP_Actor **, 8)))->GetTweenAnimParams(temp_r4_1432, temp_r4_1432 + M2C_FIELD(var_r29_1286, s32 *, 4), ((u8 *) var_r29_1286) + 0x10, ((u8 *) var_r29_1286) + 0x14, ((u8 *) var_r29_1286) + 0xC);
                            var_r29_1286 += 0x1C;
                        } else if (IsSoundEvent(sp14) != 0) {
                            if (arg4 != 0) {
                                M2C_FIELD(var_r31_1284, s32 *, 0x14) = 0;
                                M2C_FIELD(var_r31_1284, s32 *, 0) = sp10;
                                M2C_FIELD(var_r31_1284, s32 *, 4) = spC;
                                temp_r4_1456 = M2C_FIELD(temp_r3_1377, MKIniLine **, 4);
                                temp_r4_1459 = M2C_FIELD(temp_r3_1377, MKIniLine **, 4);
                                temp_r23_1460 = temp_r4_1456->unkC->GetSubLine(temp_r4_1456);
                                temp_r3_1462 = temp_r4_1459->unkC->GetSubLine(temp_r4_1459);
                                var_r18_1467 = temp_r3_1462->unkC->GetNextLine(temp_r3_1462);
loop_46:
                                if (var_r18_1467 != NULL) {
                                    if (var_r18_1467->IsField("") != 0) {
                                        M2C_FIELD(var_r31_1284, s32 *, 8) = var_r18_1467->GetString(0);
                                    }
                                    if (var_r18_1467->IsField("") != 0) {
                                        M2C_FIELD(var_r31_1284, s32 *, 0x18) = arg5->GetActorId(var_r18_1467->GetString(0));
                                    }
                                    if (NodeLoadLine2(arg5, var_r18_1467, "", ((u8 *) var_r31_1284) + 0x18, ((u8 *) var_r31_1284) + 0x1C) != 0) {
                                        M2C_FIELD(var_r31_1284, s32 *, 0x14) = (s32) (M2C_FIELD(var_r31_1284, s32 *, 0x14) | 8);
                                    }
                                    var_r18_1467 = var_r18_1467->unkC->GetNextLine(var_r18_1467);
                                    goto loop_46;
                                }
                                temp_r3_1516 = temp_r23_1460->GetString(0);
                                if (((s32) M2C_FIELD(temp_r3_1516, u8 *, 9) == 0x33) && ((s32) M2C_FIELD(temp_r3_1516, u8 *, 0xA) == 0x44)) {
                                    M2C_FIELD(var_r31_1284, s32 *, 0x14) = (s32) (M2C_FIELD(var_r31_1284, s32 *, 0x14) | 4);
                                } else {
                                    M2C_FIELD(var_r31_1284, s32 *, 0x18) = -1;
                                }
                                M2C_FIELD(var_r31_1284, s32 *, 0x10) = 0;
                                M2C_FIELD(var_r31_1284, s32 *, 0xC) = KDSound_ResolveSound((s8 *) M2C_FIELD(var_r31_1284, s32 *, 8), NULL);
                                if ((s32) M2C_FIELD(var_r31_1284, s32 *, 0xC) > 0) {
                                    M2C_FIELD(var_r31_1284, s32 *, 0x14) = (s32) (M2C_FIELD(var_r31_1284, s32 *, 0x14) | 2);
                                } else if (arg4 != 0) {
                                    M2C_FIELD(var_r31_1284, s32 *, 0xC) = Sound_GetID((s8 *) M2C_FIELD(var_r31_1284, s32 *, 8));
                                }
                                var_r31_1284 += 0x20;
                            }
                        } else {
                            M2C_FIELD(var_r27_1282, s32 *, 0) = sp10;
                            M2C_FIELD(var_r27_1282, s32 *, 4) = spC;
                            M2C_FIELD(var_r27_1282, s32 *, 0xC) = (s32) (sp8 != 0);
                            M2C_FIELD(var_r27_1282, void **, 8) = temp_r3_1377;
                            M2C_FIELD(var_r27_1282, s32 *, 0x10) = sp18;
                            var_r27_1282 += 0x14;
                        }
                    }
                    var_r28_1304 = var_r28_1304->unkC->GetNextLine(var_r28_1304);
                    goto loop_58;
                }
            }
            var_r26_1288 += 1;
        } while (var_r26_1288 < 0x20);
    }
    var_r20_1579 = 0;
    var_r18_1580 = 0;
loop_67:
    if (var_r20_1579 < (s32) this->unk4) {
        temp_r21_1584 = ((u8 *) this->unk8) + var_r18_1580;
        temp_r4_1585 = M2C_FIELD(temp_r21_1584, MKIniLine **, 4);
        temp_r19_1589 = temp_r4_1585->unkC->GetSubLine(temp_r4_1585);
        if (((s32) M2C_FIELD(temp_r21_1584, s32 *, 0xC) > 0) && (IsSoundEvent(M2C_FIELD(temp_r21_1584, s8 **, 0)) == 0) && (IsTweenAnimEvent(M2C_FIELD(temp_r21_1584, s8 **, 0)) == 0)) {
            M2C_FIELD(temp_r21_1584, KDSynkerPlayerEvent **, 8) = CreateEvent(temp_r19_1589->GetString(0));
            temp_r3_1609 = M2C_FIELD(temp_r21_1584, KDSynkerPlayerEvent **, 8);
            if (temp_r3_1609 != NULL) {
                temp_r3_1609->Load(M2C_FIELD(temp_r21_1584, MKIniLine **, 4));
            }
        }
        var_r20_1579 += 1;
        var_r18_1580 += 0x10;
        goto loop_67;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKIniLine *' to
void KDSP_Events::HeapAddSize(KDSynkerHeap *arg0, MKIni *arg1, bool arg2) {
    s8 *sp8;
    MKIniLine *temp_r3_1644;
    MKIniLine *temp_r3_1674;
    MKIniLine *temp_r3_1684;
    MKIniLine *temp_ret_1644;
    MKIniLine *temp_ret_1674;
    MKIniLine *temp_ret_1678;
    MKIniLine *temp_ret_1703;
    MKIniLine *var_r25_1679;
    f32 var_f1_1644;
    s32 temp_r0_1651;
    s32 temp_r0_1714;
    s32 temp_r0_1726;
    s32 temp_r0_1738;
    s32 temp_r3_1657;
    s32 temp_r3_1720;
    s32 temp_r3_1732;
    s32 temp_r3_1744;
    s32 temp_ret_1649;
    s32 var_r31_1664;

    temp_ret_1644 = arg1->GotoLine("", NULL);
    var_f1_1644 = M2C_BITWISE(f32, temp_ret_1644);
    temp_r3_1644 = temp_ret_1644;
    this->unk0 = temp_r3_1644;
    if (temp_r3_1644 != NULL) {
        temp_ret_1649 = this->unk0->GetNmbrOfSubLines();
        var_f1_1644 = M2C_BITWISE(f32, temp_ret_1649);
        this->unk4 = temp_ret_1649;
        temp_r0_1651 = this->unk4;
        if (temp_r0_1651 != 0) {
            temp_r3_1657 = arg0->unk14 - 1;
            arg0->unk10 += ((temp_r0_1651 * 0x10) + temp_r3_1657) & ~temp_r3_1657;
        }
    }
    var_r31_1664 = 0;
    do {
        temp_ret_1674 = arg1->GotoLine(Str_Printf("", var_r31_1664, var_f1_1644), NULL);
        var_f1_1644 = M2C_BITWISE(f32, temp_ret_1674);
        temp_r3_1674 = temp_ret_1674;
        if (temp_r3_1674 != NULL) {
            temp_ret_1678 = temp_r3_1674->unkC->GetSubLine(temp_r3_1674);
            var_f1_1644 = M2C_BITWISE(f32, temp_ret_1678);
            var_r25_1679 = temp_ret_1678;
loop_10:
            if (var_r25_1679 != NULL) {
                temp_r3_1684 = var_r25_1679->unkC->GetSubLine(var_r25_1679);
                if (temp_r3_1684 != NULL) {
                    sp8 = NULL;
                    if (temp_r3_1684->LoadString("", &sp8, 0) != 0) {
                        AddEventType(sp8);
                    }
                }
                temp_ret_1703 = var_r25_1679->unkC->GetNextLine(var_r25_1679);
                var_f1_1644 = M2C_BITWISE(f32, temp_ret_1703);
                var_r25_1679 = temp_ret_1703;
                goto loop_10;
            }
        }
        var_r31_1664 += 1;
    } while (var_r31_1664 < 0x20);
    if (arg2 != 0) {
        temp_r0_1714 = this->unk1C;
        if (temp_r0_1714 != 0) {
            temp_r3_1720 = arg0->unk20 - 1;
            arg0->unk1C += ((temp_r0_1714 << 5) + temp_r3_1720) & ~temp_r3_1720;
        }
    }
    temp_r0_1726 = this->unkC;
    if (temp_r0_1726 != 0) {
        temp_r3_1732 = arg0->unk20 - 1;
        arg0->unk1C += ((temp_r0_1726 * 0x14) + temp_r3_1732) & ~temp_r3_1732;
    }
    temp_r0_1738 = this->unk14;
    if (temp_r0_1738 != 0) {
        temp_r3_1744 = arg0->unk20 - 1;
        arg0->unk1C += ((temp_r0_1738 * 0x1C) + temp_r3_1744) & ~temp_r3_1744;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void KDSP_Events::AddEventType(const char *arg0) {
    MKIniLine *temp_r4_1766;
    MKIniLine *var_r31_1771;
    s8 *temp_r3_1788;

    temp_r4_1766 = this->unk0;
    if (temp_r4_1766 != NULL) {
        var_r31_1771 = temp_r4_1766->unkC->GetSubLine(temp_r4_1766);
loop_10:
        if (var_r31_1771 == NULL) {

        } else if (var_r31_1771->IsField(arg0) != 0) {
            if (var_r31_1771->unkC->GetSubLine(var_r31_1771) != NULL) {
                temp_r3_1788 = ((MKIniLine *) (var_r31_1771->unkC->GetSubLine(var_r31_1771)))->GetString(0);
                if (strnicmp(temp_r3_1788, HEADTWEEN_STRING, 9) == 0) {
                    this->unk14 += 1;
                    return;
                }
                if (strnicmp(PLAYSOUND3D_STRING, temp_r3_1788, 9) == 0) {
                    this->unk1C += 1;
                    return;
                }
                this->unkC += 1;
            }
        } else {
            var_r31_1771 = var_r31_1771->unkC->GetNextLine(var_r31_1771);
            goto loop_10;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void KDSP_Events::Init(KDSynkerPlayer3 *arg0, KDSynkerPlayerEventCreationTable *arg1) {
    this->unk4 = 0;
    this->unk8 = NULL;
    this->unkC = 0;
    this->unk10 = NULL;
    this->unk0 = NULL;
    this->unk14 = 0;
    this->unk18 = NULL;
    this->unk1C = 0;
    this->unk20 = NULL;
    this->unk24 = arg1;
    KDSynkerPlayerEvent::pSynker.__vptr = arg0;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
u8 NodeLoadLine2(KDSP_ActorList *arg0, MKIniLine *arg1, const char *arg2, MKModel **arg3, int *arg4) {
    s32 temp_r3_1877;
    s8 *temp_r3_1867;
    s8 *temp_r3_1870;
    u8 temp_r29_1873;

    if (arg1->IsField(arg2) != 0) {
        temp_r3_1867 = arg1->GetString(0);
        temp_r3_1870 = strchr(temp_r3_1867, 0x3A);
        temp_r29_1873 = *temp_r3_1870;
        *temp_r3_1870 = 0;
        temp_r3_1877 = arg0->GetActorId(temp_r3_1867);
        *temp_r3_1870 = (s8) temp_r29_1873;
        *arg3 = ((KDSP_Actor *) (arg0->unk4 + (temp_r3_1877 * 0x138)))->GetModel();
        *arg4 = (s32) KDSP_ToolsGetMatchingNodeIndex(*arg3, temp_r3_1870 + 1);
        return 1U;
    }
    return 0U;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
s32 NodeLoadLine1(KDSynkerPlayer3 *arg0, MKIniLine *arg1, const char *arg2, MKModel **arg3, MKProp **arg4, int *arg5, int *arg6) {
    s32 temp_r30_1933;
    s8 *temp_r3_1921;
    s8 *temp_r3_1924;
    u8 temp_r29_1927;

    if (arg1->IsField(arg2) != 0) {
        temp_r3_1921 = arg1->GetString(0);
        temp_r3_1924 = strchr(temp_r3_1921, 0x3A);
        temp_r29_1927 = *temp_r3_1924;
        *temp_r3_1924 = 0;
        temp_r30_1933 = arg0->unk100.GetActorId(temp_r3_1921);
        if (arg5 != NULL) {
            *arg5 = temp_r30_1933;
        }
        *temp_r3_1924 = (s8) temp_r29_1927;
        if (arg4 != NULL) {
            *arg4 = arg0->GetActorProp(temp_r30_1933);
        }
        arg0->GetActorModel(temp_r30_1933);
        if (arg3 != NULL) {
            *arg3 = M2C_ERROR(/* Read from unset register $r3 */);
        }
        *arg6 = (s32) KDSP_ToolsGetMatchingNodeIndex(M2C_ERROR(/* Read from unset register $r3 */), temp_r3_1924 + 1);
        return 1;
    }
    return 0;
}
#endif
