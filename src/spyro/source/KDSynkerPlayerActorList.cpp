#include "spyro/source/KDSynkerPlayerActorList.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDSynkerPlayer2Messages.h"
#include "spyro/source/KDSynkerPlayerActor.h"
#include "spyro/source/KDSynkerPlayerTools.h"
#include "common/Source/FileSys.h"
#include <m2c_macros.h>

#if 0 // DRAFT: illegal operand
s32 atoi(u8 *);                                     /* extern */
s32 strcmpi(s32, s8 *);                             /* extern */
s32 stricmp(s32, s8 *);                             /* extern */
s8 *strtok(s8 *, M2C_UNK *);                        /* extern */

void KDSP_Subtitles::Update(KDSP_ActorList *arg0, int arg1) {
    s32 temp_r0_14;
    s32 temp_r12_30;
    s32 temp_r12_74;
    s32 temp_r31_27;
    s32 var_ctr_111;
    s32 var_ctr_15;
    s32 var_r10_21;
    s32 var_r4_110;
    s32 var_r5_109;
    s32 var_r6_108;
    s32 var_r7_20;
    s32 var_r9_12;
    u8 var_r11_31;
    u8 var_r11_75;
    void *temp_r6_22;
    void *temp_r8_26;

    var_r9_12 = 0;
    temp_r0_14 = arg0->unk0;
    var_ctr_15 = temp_r0_14;
    if (temp_r0_14 > 0) {
        do {
            var_r7_20 = 0;
            var_r10_21 = 0;
            temp_r6_22 = (void *) (arg0->unk4 + var_r9_12);
loop_14:
            if (var_r7_20 < (s32) M2C_FIELD(temp_r6_22, s32 *, 0x54)) {
                temp_r8_26 = (void *) (M2C_FIELD(temp_r6_22, s32 *, 0x58) + var_r10_21);
                temp_r31_27 = M2C_FIELD(temp_r8_26, s32 *, 0x1C);
                if (temp_r31_27 == -1) {
                    temp_r12_30 = M2C_FIELD(temp_r8_26, s32 *, 0);
                    var_r11_31 = 0;
                    if ((arg1 >= temp_r12_30) && (arg1 < (s32) (temp_r12_30 + M2C_FIELD(temp_r8_26, s32 *, 4)))) {
                        var_r11_31 = 1;
                    }
                    if (var_r11_31 != 0) {
                        M2C_FIELD(temp_r8_26, s32 *, 0x1C) = (s32) this->unkA8;
                        *(this + ((this->unkA8 * 8) + 0xAC)) = *(this + (M2C_FIELD(temp_r8_26, s32 *, 8) * 4));
                        *(this + ((this->unkA8 * 8) + 0xB0)) = 0.033f * (f32) M2C_FIELD(temp_r8_26, s32 *, 4);
                        this->unkA8 = (this->unkA8 + 1) % 3;
                    }
                } else {
                    temp_r12_74 = M2C_FIELD(temp_r8_26, s32 *, 0);
                    var_r11_75 = 0;
                    if ((arg1 >= temp_r12_74) && (arg1 < (s32) (temp_r12_74 + M2C_FIELD(temp_r8_26, s32 *, 4)))) {
                        var_r11_75 = 1;
                    }
                    if (var_r11_75 == 0) {
                        *(this + ((temp_r31_27 * 8) + 0xAC)) = 0;
                        *(this + ((M2C_FIELD(temp_r8_26, s32 *, 0x1C) * 8) + 0xB0)) = 0.0f;
                        M2C_FIELD(temp_r8_26, s32 *, 0x1C) = -1;
                    }
                }
                var_r7_20 += 1;
                var_r10_21 += 0x24;
                goto loop_14;
            }
            var_r9_12 += 0x138;
            var_ctr_15 -= 1;
        } while (var_ctr_15 != 0);
    }
    var_r6_108 = 0;
    var_r5_109 = 0;
    var_r4_110 = 0;
    var_ctr_111 = 3;
    do {
        if ((u32) *(this + (var_r4_110 + 0xAC)) != 0U) {
            var_r6_108 = var_r5_109 + 1;
        }
        var_r5_109 += 1;
        var_r4_110 += 8;
        var_ctr_111 -= 1;
    } while (var_ctr_111 != 0);
    this->unkA4 = var_r6_108;
    if (var_r6_108 == 0) {
        this->unkA8 = 0;
    }
}
#endif

#if 0 // DRAFT: illegal operand
void KDSP_Subtitles::Parse(KDSynkerHeap *arg0, const char *arg1) {
    s8 spA;
    u8 sp9;
    u8 sp8;
    s32 temp_r0_141;
    s32 temp_r3_185;
    s32 temp_r5_146;
    s32 temp_r6_147;
    s32 var_r29_157;
    s32 var_r5_158;
    u8 *var_r30_159;
    u8 temp_r3_163;

    temp_r0_141 = this->unkA0;
    if (temp_r0_141 > 0) {
        temp_r5_146 = arg0->unk0;
        temp_r6_147 = arg0->unk8 - 1;
        arg0->unk0 = temp_r5_146 + ((temp_r0_141 + temp_r6_147) & ~temp_r6_147);
        this->unk98 = (unsigned char *) (MKArchive_Load(arg1, NULL, (void *) temp_r5_146, this->unkA0));
        var_r29_157 = 0;
        var_r5_158 = 0;
        var_r30_159 = this->unk98;
        spA = 0;
loop_19:
        if (((s32) (var_r30_159 - this->unk98) < (s32) this->unkA0) && ((s32) this->unk9C < 0x26)) {
            temp_r3_163 = *var_r30_159;
            switch ((s8) temp_r3_163) {             /* irregular */
            case 13:
            case 10:
                var_r29_157 = 0;
                *var_r30_159 = 0;
                var_r5_158 = 0;
                break;
            case 32:
            case 9:
                var_r29_157 += 1;
                if (var_r29_157 == 1) {
                    temp_r3_185 = atoi(&sp8);
                    var_r5_158 = 0;
                    if (temp_r3_185 < 0x26) {
                        *(this + (temp_r3_185 * 4)) = var_r30_159 + 1;
                    }
                }
                break;
            default:
                if ((var_r29_157 == 0) && ((s8) temp_r3_163 > 0x20) && ((s8) temp_r3_163 <= 0x7A)) {
                    if (var_r5_158 == 8) {
                        sp8 = temp_r3_163;
                    } else if (var_r5_158 == 9) {
                        sp9 = temp_r3_163;
                    }
                    var_r5_158 += 1;
                }
                break;
            }
            var_r30_159 += 1;
            goto loop_19;
        }
    }
}
#endif

void KDSP_Subtitles::HeapAddSize(KDSynkerHeap *arg0, const char *arg1) {
    s32 temp_r4_245;

    if (MKArchive_Exists(arg1, (int *) &this->unkA0) != 0) {
        temp_r4_245 = arg0->unk8 - 1;
        arg0->unk4 += (this->unkA0 + temp_r4_245) & ~temp_r4_245;
    }
}

void KDSP_Subtitles::Reset() {
    s32 var_ctr_266;
    s32 var_r4_262;
    void *temp_r6_268;

    var_r4_262 = 0;
    var_ctr_266 = 3;
    do {
        temp_r6_268 = this + var_r4_262;
        var_r4_262 += 8;
        M2C_FIELD(temp_r6_268, s32 *, 0xAC) = 0;
        M2C_FIELD(temp_r6_268, f32 *, 0xB0) = 0.0f;
        var_ctr_266 -= 1;
    } while (var_ctr_266 != 0);
    this->unkA8 = 0;
    this->unkA4 = 0;
}

void KDSP_Subtitles::Init() {
    Reset();
    memset(this, 0, 0x98U);
    this->unk98 = NULL;
    this->unk9C = 0;
    this->unkA0 = 0;
}

#if 0 // DRAFT: pointer/array required
s32 KDSP_ActorList::GetActorId(const char *arg0) {
    s32 var_r30_312;
    s32 var_r31_313;

    var_r30_312 = 0;
    var_r31_313 = 0;
loop_4:
    if (var_r30_312 >= (s32) this->unk0) {
        return -1;
    }
    if (strcmpi(*(this->unk4 + (var_r31_313 + 0x5C)), arg0) == 0) {
        return var_r30_312;
    }
    var_r30_312 += 1;
    var_r31_313 += 0x138;
    goto loop_4;
}
#endif

void KDSP_ActorList::Update(float arg0, KDSP_EnvelopeList *arg1, const MKVector3 &arg2, bool arg3) {
    s32 var_r30_356;
    s32 var_r30_371;
    s32 var_r31_355;
    s32 var_r31_370;

    ((KDSP_Actor *) arg1)->SetEnvelopeList(arg1);
    var_r31_355 = this->unk4;
    var_r30_356 = 0;
loop_2:
    if (var_r30_356 < (s32) this->unk0) {
        ((KDSP_Actor *) var_r31_355)->Update(arg0, arg2, arg3);
        var_r31_355 += 0x138;
        var_r30_356 += 1;
        goto loop_2;
    }
    var_r31_370 = this->unk4;
    var_r30_371 = 0;
loop_5:
    if (var_r30_371 < (s32) this->unk0) {
        ((KDSP_Actor *) var_r31_370)->UpdateLookat();
        var_r31_370 += 0x138;
        var_r30_371 += 1;
        goto loop_5;
    }
}

#if 0 // DRAFT: function call 'strcpy(signed char *, signed char *)' does not match 'strcpy(char *, const char *)'
void KDSP_ActorList::ResolveLookAt() {
    s8 sp28;
    s8 sp8;
    s32 temp_r3_404;
    s32 var_r24_443;
    s32 var_r25_410;
    s32 var_r27_412;
    s32 var_r27_445;
    s32 var_r28_399;
    s32 var_r31_398;
    void *temp_r24_417;
    void *temp_r25_450;
    void *temp_r30_403;

    var_r31_398 = 0;
    var_r28_399 = 0;
loop_10:
    if (var_r31_398 < (s32) this->unk0) {
        temp_r30_403 = (void *) (this->unk4 + var_r28_399);
        temp_r3_404 = M2C_FIELD(temp_r30_403, s32 *, 0x40);
        if (!(temp_r3_404 & 4) && !(temp_r3_404 & 8)) {
            var_r25_410 = 0;
            var_r27_412 = 0;
loop_5:
            if (var_r25_410 < (s32) M2C_FIELD(temp_r30_403, s32 *, 0x44)) {
                temp_r24_417 = (void *) (M2C_FIELD(temp_r30_403, s32 *, 0x48) + var_r27_412);
                strcpy(&sp28, M2C_FIELD(temp_r24_417, s8 **, 8));
                strtok(&sp28, ":");
                M2C_FIELD(temp_r24_417, KDSP_Actor **, 0xC) = (const char *) (FindActor(&sp28));
                var_r27_412 += 0x14;
                M2C_FIELD(temp_r24_417, s32 *, 0x10) = (s32) ((KDSP_Actor *) (M2C_FIELD(temp_r24_417, KDSP_Actor **, 0xC)))->GetMatchingNodeIndex(strtok(NULL, "\n"));
                var_r25_410 += 1;
                goto loop_5;
            }
            var_r24_443 = 0;
            var_r27_445 = 0;
loop_8:
            if (var_r24_443 < (s32) M2C_FIELD(temp_r30_403, s32 *, 0x4C)) {
                temp_r25_450 = (void *) (M2C_FIELD(temp_r30_403, s32 *, 0x50) + var_r27_445);
                strcpy(&sp8, M2C_FIELD(temp_r25_450, s8 **, 8));
                strtok(&sp8, ":");
                M2C_FIELD(temp_r25_450, KDSP_Actor **, 0xC) = (const char *) (FindActor(&sp8));
                var_r27_445 += 0x14;
                M2C_FIELD(temp_r25_450, s32 *, 0x10) = (s32) ((KDSP_Actor *) (M2C_FIELD(temp_r25_450, KDSP_Actor **, 0xC)))->GetMatchingNodeIndex(strtok(NULL, "\n"));
                var_r24_443 += 1;
                goto loop_8;
            }
        }
        var_r31_398 += 1;
        var_r28_399 += 0x138;
        goto loop_10;
    }
}
#endif

void KDSP_ActorList::SendMessageToActorProp(bool arg0) {
    KDS_Message_PropEnd sp10;
    s32 spC;
    s32 sp8;
    s32 var_r30_498;
    s32 var_r31_499;
    void *temp_r29_503;
    void *temp_r3_504;
    void *temp_r3_528;

    var_r30_498 = 0;
    var_r31_499 = 0;
loop_6:
    if (var_r30_498 < (s32) this->unk0) {
        temp_r29_503 = (void *) (this->unk4 + var_r31_499);
        temp_r3_504 = M2C_FIELD(temp_r29_503, void **, 0x30);
        if (temp_r3_504 != NULL) {
            if (arg0 != 0) {
                spC = 0;
                sp8 = 0x803;
                M2C_FIELD(M2C_FIELD(temp_r3_504, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
            } else {
                sp10.unk4 = 0;
                sp10.Init((((u32) M2C_FIELD(temp_r29_503, u32 *, 0x40) >> 4U) & 1) ^ 1, 0U);
                temp_r3_528 = M2C_FIELD(temp_r29_503, void **, 0x30);
                M2C_FIELD(M2C_FIELD(temp_r3_528, void **, 0x44), M2C_UNK (**)(void *, KDS_Message_PropEnd *), 0x2C)(temp_r3_528, &sp10);
            }
        }
        var_r30_498 += 1;
        var_r31_499 += 0x138;
        goto loop_6;
    }
}

void KDSP_ActorList::Deinit(bool arg0) {
    s32 var_r30_557;
    s32 var_r31_558;

    var_r30_557 = 0;
    var_r31_558 = 0;
loop_2:
    if (var_r30_557 < (s32) this->unk0) {
        ((KDSP_Actor *) (this->unk4 + var_r31_558))->Deinit(arg0);
        var_r30_557 += 1;
        var_r31_558 += 0x138;
        goto loop_2;
    }
    this->unk4 = 0;
    this->unk0 = 0;
}

#if 0 // DRAFT: pointer/array required
KDSP_Actor *KDSP_ActorList::FindActor(const char *arg0) {
    s32 var_r30_590;
    s32 var_r31_591;

    var_r30_590 = 0;
    var_r31_591 = 0;
loop_4:
    if (var_r30_590 >= (s32) this->unk0) {
        return NULL;
    }
    if (stricmp(*(this->unk4 + (var_r31_591 + 0x5C)), arg0) == 0) {
        return (KDSP_Actor *) (this->unk4 + var_r31_591);
    }
    var_r30_590 += 1;
    var_r31_591 += 0x138;
    goto loop_4;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk8'
void KDSP_ActorList::Load(MKIni *arg0, int &arg1, bool arg2, bool arg3) {
    MKIniLine *temp_r4_647;
    MKIniLine *var_r29_654;
    s32 temp_r0_644;
    s32 var_r29_631;
    s32 var_r29_674;
    s32 var_r30_632;
    s32 var_r30_675;

    var_r29_631 = 0;
    var_r30_632 = 0;
loop_2:
    temp_r0_644 = this->unk0;
    if (var_r29_631 < temp_r0_644) {
        ((KDSP_Actor *) (this->unk4 + var_r30_632))->Resolve(arg2, this->unk8, arg3);
        var_r29_631 += 1;
        var_r30_632 += 0x138;
        goto loop_2;
    }
    temp_r4_647 = this->unk10;
    if ((temp_r4_647 != NULL) && (temp_r0_644 != 0)) {
        var_r29_654 = temp_r4_647->unkC->GetSubLine(temp_r4_647);
loop_7:
        if (var_r29_654 != NULL) {
            ((KDSP_Actor *) (FindActor(var_r29_654->GetFieldName())))->LoadActorSectionPostResolve(var_r29_654, arg2, arg1);
            var_r29_654 = var_r29_654->unkC->GetNextLine(var_r29_654);
            goto loop_7;
        }
    }
    var_r29_674 = 0;
    var_r30_675 = 0;
loop_10:
    if (var_r29_674 < (s32) this->unk0) {
        ((KDSP_Actor *) (this->unk4 + var_r30_675))->HideSpecialSubObjects();
        var_r29_674 += 1;
        var_r30_675 += 0x138;
        goto loop_10;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to 'const char *'
void KDSP_ActorList::Parse(KDSynkerHeap *arg0, MKIni *arg1, int &arg2, KDInput *arg3) {
    MKIniLine *temp_r28_706;
    MKIniLine *temp_r3_729;
    MKIniLine *temp_r4_751;
    MKIniLine *var_r27_759;
    MKIniLine *var_r28_733;
    s32 temp_r0_709;
    s32 temp_r3_716;
    s32 var_r27_726;
    void *temp_r5_714;

    ((KDSP_Actor *) arg3)->SetInput((KDInput *) arg0);
    temp_r28_706 = this->unkC;
    if (temp_r28_706 != NULL) {
        temp_r0_709 = this->unk0;
        if (temp_r0_709 != 0) {
            temp_r5_714 = arg0->unkC;
            temp_r3_716 = arg0->unk14 - 1;
            arg0->unkC = ((u8 *) temp_r5_714) + (((temp_r0_709 * 0x138) + temp_r3_716) & ~temp_r3_716);
            this->unk4 = (s32) temp_r5_714;
            memset((void *) this->unk4, 0, this->unk0 * 0x138);
            var_r27_726 = this->unk4;
            temp_r3_729 = temp_r28_706->unkC->GetSubLine(temp_r28_706);
            var_r28_733 = temp_r3_729->unkC->GetNextLine(temp_r3_729);
loop_4:
            if (var_r28_733 != NULL) {
                ((KDSP_Actor *) var_r27_726)->Init();
                ((KDSP_Actor *) var_r27_726)->LoadActorDataSection(arg0, var_r28_733);
                var_r27_726 += 0x138;
                var_r28_733 = var_r28_733->unkC->GetNextLine(var_r28_733);
                goto loop_4;
            }
        }
    }
    temp_r4_751 = this->unk10;
    if ((temp_r4_751 != NULL) && ((s32) this->unk0 != 0)) {
        var_r27_759 = temp_r4_751->unkC->GetSubLine(temp_r4_751);
loop_9:
        if (var_r27_759 != NULL) {
            ((KDSP_Actor *) (FindActor(var_r27_759->GetFieldName())))->LoadActorSection(arg0, var_r27_759, arg2);
            var_r27_759 = var_r27_759->unkC->GetNextLine(var_r27_759);
            goto loop_9;
        }
    }
}
#endif

void KDSP_ActorList::HeapAddSize(KDSynkerHeap *arg0, MKIni *arg1) {
    KDSP_Actor sp8;
    MKIniLine *temp_r29_810;
    MKIniLine *temp_r3_830;
    MKIniLine *temp_r4_849;
    MKIniLine *var_r29_834;
    MKIniLine *var_r29_854;
    s32 temp_r0_817;
    s32 temp_r3_824;

    this->unkC = arg1->GotoLine("ACTOR_DATA", NULL);
    this->unk10 = arg1->GotoLine("ACTORS", NULL);
    temp_r29_810 = this->unkC;
    if (temp_r29_810 != NULL) {
        this->unk0 = temp_r29_810->GetNmbrOfSubLines() - 1;
        temp_r0_817 = this->unk0;
        if (temp_r0_817 != 0) {
            temp_r3_824 = arg0->unk14 - 1;
            arg0->unk10 += ((temp_r0_817 * 0x138) + temp_r3_824) & ~temp_r3_824;
            temp_r3_830 = temp_r29_810->unkC->GetSubLine(temp_r29_810);
            var_r29_834 = temp_r3_830->unkC->GetNextLine(temp_r3_830);
loop_4:
            if (var_r29_834 != NULL) {
                sp8.HeapAddSize(arg0, var_r29_834);
                var_r29_834 = var_r29_834->unkC->GetNextLine(var_r29_834);
                goto loop_4;
            }
            goto block_5;
        }
    } else {
block_5:
        temp_r4_849 = this->unk10;
        if (temp_r4_849 != NULL) {
            var_r29_854 = temp_r4_849->unkC->GetSubLine(temp_r4_849);
loop_8:
            if (var_r29_854 != NULL) {
                sp8.HeapAddSize(arg0, var_r29_854);
                var_r29_854 = var_r29_854->unkC->GetNextLine(var_r29_854);
                goto loop_8;
            }
        }
    }
}

#if 0 // DRAFT: undefined identifier 'unk8'
void KDSP_ActorList::Init() {
    this->unk0 = 0;
    this->unk4 = 0;
    this->unk8 = NULL;
    this->unkC = NULL;
    this->unk10 = NULL;
}
#endif
