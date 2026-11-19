#include "common/Source/MKAnimScript.h"
#include "common/Source/Animation.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKVector3.h"
#include "unplaced_enums.h"
#include "common/Source/FileSys.h"
#include "common/Source/Str.h"
#include "common/Source/system_extras.h"
#include <m2c_macros.h>

#if 0 // DRAFT: identifier 'gAssertBool' redeclared
u64 __shl2i(M2C_UNK, M2C_UNK, s32);                 /* extern */
M2C_UNK free(MKResource *);                         /* extern */
MKResource *malloc(s32);                            /* extern */
s32 sscanf(s8 *, void *, f32 *, f32 *, s8 *);       /* extern */
s32 strcmpi(s8 *, s8 *);                            /* extern */
s32 stricmp(MKAnim *, s8 *, M2C_UNK);               /* extern */
s8 *strrchr(M2C_UNK);                               /* extern */
extern u8 gAssertBool;
#endif
extern M2C_UNK gEmptyPtrList;
extern f32 gUpdateTimeDelta;
extern MKResource **mkAnimScriptTemplates;

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to
u8 pSoundEventKeyWord__19MKAnimScriptedEvent[4];    /* unable to generate initializer: cannot parse "MKSound" as integer; const */
u8 pSubObjectEnableEventKeyWord__19MKAnimScriptedEvent[4]; /* unable to generate initializer: cannot parse .L_8036DAA8 as integer; const */
u8 pSubObjectDisableEventKeyWord__19MKAnimScriptedEvent[4]; /* unable to generate initializer: cannot parse .L_8036DABA as integer; const */
u8 pSubObjectEnableAllEventKeyWord__19MKAnimScriptedEvent[4]; /* unable to generate initializer: cannot parse .L_8036DACD as integer; const */
u8 pSubObjectDisableAllEventKeyWord__19MKAnimScriptedEvent[4]; /* unable to generate initializer: cannot parse .L_8036DAE2 as integer; const */
u8 pAliasMaterialEventKeyWord__19MKAnimScriptedEvent[4]; /* unable to generate initializer: cannot parse .L_8036DAF8 as integer; const */
u8 pOnEnterKeyWord__19MKAnimScriptedEvent[4];       /* unable to generate initializer: cannot parse .L_8036DB08 as integer; const */
u8 pOnExitKeyWord__19MKAnimScriptedEvent[4];        /* unable to generate initializer: cannot parse .L_8036DB10 as integer; const */

void MKAnimScriptTemplate::DeinitMKAnimScriptData() {
    MKAnim *temp_r30_22;
    MKAnimScriptedEvent *var_r28_27;
    s16 temp_r30_30;
    s32 var_r27_31;
    s32 var_r29_16;
    s32 var_r31_17;
    void *temp_r3_44;

    var_r29_16 = 0;
    var_r31_17 = 0;
loop_5:
    temp_r3_44 = this->unk34;
    if (var_r29_16 < (s32) M2C_FIELD(temp_r3_44, u16 *, 8)) {
        temp_r30_22 = ((u8 *) temp_r3_44) + (var_r31_17 + 0x10);
        var_r28_27 = temp_r30_22->GetFirstEvent((MKAnimScriptedEvent::EventType) 6);
        temp_r30_30 = temp_r30_22->GetNumberOfEvents((MKAnimScriptedEvent::EventType) 6);
        var_r27_31 = 0;
loop_3:
        if (var_r27_31 < temp_r30_30) {
            var_r28_27->FreeMaterial();
            var_r28_27 += 0x10;
            var_r27_31 += 1;
            goto loop_3;
        }
        var_r29_16 += 1;
        var_r31_17 += 0x30;
        goto loop_5;
    }
}
#endif

void MKAnimScriptedEvent::FreeMaterial() {

}

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to
s32 MKAnimScriptedEvent::GetStringSizeOfEvent(MKIniLine *arg0) {
    s8 *sp18;
    s8 *sp14;
    s8 *sp10;
    s8 *spC;
    s8 *sp8;
    s16 temp_r0_74;
    s32 temp_r31_131;
    s32 var_r31_72;

    var_r31_72 = 0;
    if (ParseEventType(arg0) != 0) {
        temp_r0_74 = this->unk4;
        switch (temp_r0_74) {                       /* irregular */
        case 0:
            sp18 = NULL;
            gAssertBool = arg0->AsString(0, &sp18);
            var_r31_72 = strlen(sp18) + 1;
            break;
        default:
            sp14 = NULL;
            arg0->AsString(2, &sp14);
            var_r31_72 = strlen(sp14) + 1;
            break;
        case 1:
            sp10 = NULL;
            arg0->AsString(2, &sp10);
            var_r31_72 = strlen(sp10) + 1;
            break;
        case 6:
            spC = NULL;
            arg0->AsString(2, &spC);
            temp_r31_131 = strlen(spC) + 1;
            sp8 = NULL;
            arg0->AsString(3, &sp8);
            var_r31_72 = strlen(sp8) + temp_r31_131 + 1;
            break;
        }
    }
    return var_r31_72;
}
#endif

u8 MKAnimScriptedEvent::ParseEvent(MKIniLine *arg0, char *arg1) {
    s16 temp_r0_163;
    u8 var_r3_160;

    var_r3_160 = ParseEventType(arg0);
    if (var_r3_160 != 0) {
        temp_r0_163 = this->unk4;
        if (temp_r0_163 != 1) {
            if (temp_r0_163 < 1) {
                if (temp_r0_163 < 0) {
                    goto block_12;
                }
                return ParseCodeEvent(arg0, arg1);
            }
            if (temp_r0_163 != 6) {
                if (temp_r0_163 < 6) {
                    return ParseSubObjectEvent(arg0, arg1);
                }
block_12:
                var_r3_160 = 0;
                /* Duplicate return node #13. Try simplifying control flow for better match */
                return var_r3_160;
            }
            return ParseAliasMaterialEvent(arg0, arg1);
        }
        return ParseSoundEvent(arg0, arg1);
    }
    return var_r3_160;
}

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to
u8 MKAnimScriptedEvent::ParseAliasMaterialEvent(MKIniLine *arg0, char *arg1) {
    s8 *spC;
    s8 *sp8;
    s32 var_r31_227;

    spC = NULL;
    sp8 = NULL;
    var_r31_227 = arg0->AsString(2, &spC);
    this->unk0 = AddToStringTable(arg1, spC);
    if ((u8) var_r31_227 != 0) {
        var_r31_227 = arg0->AsString(3, &sp8);
    }
    if ((u8) var_r31_227 != 0) {
        var_r31_227 = ParseFrameNo(arg0);
    }
    if (((u8) var_r31_227 != 0) && (stricmp(this->unk0, sp8) == 0)) {
        this->unkC = 0;
    }
    return (u8) var_r31_227;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to
u8 MKAnimScriptedEvent::ParseSubObjectEvent(MKIniLine *arg0, char *arg1) {
    s8 *sp8;
    s16 temp_r0_277;
    s32 var_r31_275;
    u8 temp_r3_293;

    var_r31_275 = 1;
    sp8 = NULL;
    temp_r0_277 = this->unk4;
    if ((temp_r0_277 == 2) || (temp_r0_277 == 3)) {
        var_r31_275 = arg0->AsString(2, &sp8);
    }
    if ((u8) var_r31_275 != 0) {
        temp_r3_293 = ParseFrameNo(arg0);
        this->unkC = 0;
        var_r31_275 = (s32) temp_r3_293;
        this->unk8 = -1;
        if (sp8 != NULL) {
            this->unk0 = AddToStringTable(arg1, sp8);
        } else {
            this->unk0 = NULL;
        }
    }
    return (u8) var_r31_275;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to
u8 MKAnimScriptedEvent::ParseSoundEvent(MKIniLine *arg0, char *arg1) {
    s8 *sp8;
    u8 temp_r3_332;
    u8 temp_r5_340;
    u8 var_r31_334;

    sp8 = NULL;
    temp_r3_332 = arg0->AsString(2, &sp8);
    var_r31_334 = temp_r3_332;
    if (temp_r3_332 != 0) {
        temp_r5_340 = ParseFrameNo(arg0);
        this->unkC = (s32) this->unk6;
        var_r31_334 = temp_r5_340;
        this->unk8 = -1;
        this->unk0 = AddToStringTable(arg1, sp8);
    }
    return var_r31_334;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to
u8 MKAnimScriptedEvent::ParseCodeEvent(MKIniLine *arg0, char *arg1) {
    s8 *sp1C;
    s8 *sp18;
    s32 sp14;
    s32 sp10;
    f32 spC;
    f32 sp8;
    s16 temp_r0_380;
    s16 temp_r3_447;
    s16 temp_r5_430;
    s32 temp_r3_413;
    s32 temp_r3_469;

    sp1C = NULL;
    sp18 = NULL;
    gAssertBool = arg0->AsString(0, &sp1C);
    gAssertBool = ParseFrameNo(arg0);
    temp_r0_380 = this->unk6;
    if ((temp_r0_380 == -1) || (temp_r0_380 == -2)) {
        this->unkC = (s32) temp_r0_380;
        this->unk0 = AddToStringTable(arg1, sp1C);
        this->unk8 = -1;
        return 1U;
    }
    gAssertBool = arg0->AsString(1, &sp18);
    if (strchr(sp18, 0x2E) != NULL) {
        temp_r3_413 = sscanf(sp18, "%f-%f", &spC, &sp8);
        switch (temp_r3_413) {                      /* switch 1; irregular */
        case 1:                                     /* switch 1 */
            sp8 = spC;
            /* fallthrough */
        default:                                    /* switch 1 */
            temp_r5_430 = M2C_FIELD(*MKAnimScriptedEvent::pSrcAnim, s16 *, 0xA);
            sp14 = temp_r5_430 + (s32) (spC * (f32) (M2C_FIELD(*MKAnimScriptedEvent::pSrcAnim, s16 *, 0xC) - temp_r5_430));
            temp_r3_447 = M2C_FIELD(*MKAnimScriptedEvent::pSrcAnim, s16 *, 0xA);
            sp10 = temp_r3_447 + (s32) (sp8 * (f32) (M2C_FIELD(*MKAnimScriptedEvent::pSrcAnim, s16 *, 0xC) - temp_r3_447));
            goto block_17;
        case 0:                                     /* switch 1 */
            return 0U;
        }
    } else {
        temp_r3_469 = sscanf(sp18, "%d-%d", (f32 *) &sp14, (f32 *) &sp10);
        switch (temp_r3_469) {                      /* switch 2; irregular */
        case 0:                                     /* switch 2 */
            sp14 = -3;
            /* fallthrough */
        case 1:                                     /* switch 2 */
            sp10 = sp14;
            break;
        }
block_17:
        if (sp14 != -3) {
            this->unk6 = (s16) sp14;
            this->unkC = (s32) (s16) sp10;
            this->unk0 = AddToStringTable(arg1, sp1C);
            this->unk8 = -1;
            return 1U;
        }
        return 0U;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to
u8 MKAnimScriptedEvent::ParseFrameNo(MKIniLine *arg0) {
    f32 spC;
    s8 *sp8;
    s32 temp_r31_527;

    sp8 = NULL;
    temp_r31_527 = arg0->AsString(1, &sp8);
    sscanf(sp8, "%s", &spC);
    if (stricmp(*MKAnimScriptedEvent::pOnExitKeyWord, (s8 *) &spC) == 0) {
        this->unk6 = -1;
        return (u8) temp_r31_527;
    }
    if (stricmp(*MKAnimScriptedEvent::pOnEnterKeyWord, (s8 *) &spC) == 0) {
        this->unk6 = -2;
        return (u8) temp_r31_527;
    }
    this->unk6 = GetFrameOrProportion(arg0, 1, *MKAnimScriptedEvent::pSrcAnim);
    return (u8) temp_r31_527;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to
u8 MKAnimScriptedEvent::ParseEventType(MKIniLine *arg0) {
    s8 *sp8;
    s32 temp_r31_583;

    sp8 = NULL;
    temp_r31_583 = arg0->AsString(0, &sp8);
    if (stricmp((MKAnim *) sp8, *MKAnimScriptedEvent::pSoundEventKeyWord) == 0) {
        this->unk4 = 1;
    } else if (stricmp((MKAnim *) sp8, *MKAnimScriptedEvent::pSubObjectEnableEventKeyWord) == 0) {
        this->unk4 = 2;
    } else if (stricmp((MKAnim *) sp8, *MKAnimScriptedEvent::pSubObjectDisableEventKeyWord) == 0) {
        this->unk4 = 3;
    } else if (stricmp((MKAnim *) sp8, *MKAnimScriptedEvent::pSubObjectEnableAllEventKeyWord) == 0) {
        this->unk4 = 4;
    } else if (stricmp((MKAnim *) sp8, *MKAnimScriptedEvent::pSubObjectDisableAllEventKeyWord) == 0) {
        this->unk4 = 5;
    } else if (stricmp((MKAnim *) sp8, *MKAnimScriptedEvent::pAliasMaterialEventKeyWord) == 0) {
        this->unk4 = 6;
    } else {
        this->unk4 = 0;
    }
    return (u8) temp_r31_583;
}
#endif

void MKAnimScript::SetCurrentFrame(float arg0, bool arg1) {
    s16 temp_r5_688;
    s16 temp_r6_656;
    s16 temp_r7_657;
    u32 temp_r4_685;
    u32 temp_r5_653;

    temp_r5_653 = this->unk20;
    if (temp_r5_653 != 0) {
        temp_r6_656 = M2C_FIELD(temp_r5_653, s16 *, 0xA);
        temp_r7_657 = M2C_FIELD(temp_r5_653, s16 *, 0xC);
        if (temp_r6_656 == temp_r7_657) {
            this->unk24 = 0.0f;
        } else {
            this->unk24 = (arg0 - (f32) temp_r6_656) / (f32) (temp_r7_657 - temp_r6_656);
        }
        this->unk3C = this->unk40;
        if (arg1 == 0) {
            temp_r4_685 = this->unk20;
            temp_r5_688 = M2C_FIELD(temp_r4_685, s16 *, 0xA);
            this->unk40 = temp_r5_688 + (s32) (this->unk24 * (f32) (M2C_FIELD(temp_r4_685, s16 *, 0xC) - temp_r5_688));
            CheckEvents();
        }
    }
}

MKResource *MKAnimScript::GetName() {
    return this->unk4;
}

void MKAnimScript::SetAnimation(Animation *arg0) {
    this->unkC = arg0;
}

void MKAnimScript::SetCurrentFrame(int arg0) {
    s16 temp_r7_732;
    u32 temp_r6_729;

    temp_r6_729 = this->unk20;
    if (temp_r6_729 != 0) {
        temp_r7_732 = M2C_FIELD(temp_r6_729, s16 *, 0xA);
        this->unk24 = (f32) (arg0 - temp_r7_732) / (f32) (M2C_FIELD(temp_r6_729, s16 *, 0xC) - temp_r7_732);
    }
}

s32 MKAnimScript::GetCurrentFrame() {
    s16 temp_r5_762;
    u32 temp_r4_759;

    temp_r4_759 = this->unk20;
    if (temp_r4_759 != 0) {
        temp_r5_762 = M2C_FIELD(temp_r4_759, s16 *, 0xA);
        return temp_r5_762 + (s32) (this->unk24 * (f32) (M2C_FIELD(temp_r4_759, s16 *, 0xC) - temp_r5_762));
    }
    return 0;
}

void MKAnimScript::GetStartAndEnd(MKAnim *arg0, short *arg1, short *arg2) {
    if (arg1 != NULL) {
        *arg1 = arg0->unkA;
    }
    if (arg2 != NULL) {
        *arg2 = arg0->unkC;
    }
}

void MKAnimScript::JumpToPos(float arg0, int arg1) {
    Animation *temp_r4_856;
    s16 temp_r6_839;
    u32 temp_r4_837;

    this->unk24 = arg0;
    if ((arg0 == 1.0f) && (this->unk38 > 0.0f)) {
        this->unk2C = 1;
    } else if ((arg0 == 0.0f) && (this->unk38 < 0.0f)) {
        this->unk2C = 1;
    } else {
        this->unk2C = 0;
    }
    this->unk10 = NULL;
    temp_r4_837 = this->unk20;
    temp_r6_839 = M2C_FIELD(temp_r4_837, s16 *, 0xA);
    this->unk40 = temp_r6_839 + (s32) (this->unk24 * (f32) (M2C_FIELD(temp_r4_837, s16 *, 0xC) - temp_r6_839));
    this->unk3C = this->unk40 - 1;
    temp_r4_856 = this->unkC;
    if (temp_r4_856 != NULL) {
        Apply(temp_r4_856, arg1);
    }
}

#if 0 // DRAFT: illegal use of non-static member
void MKAnimScript::Destroy() {
    if ((u8) this->unk0 != 0) {
        MKModel_Destroy(this->unk8);
        this->unk0 = 0;
    }
    this->unk8 = NULL;
    Deinit();
    MKHeap::FreeFromAnyHeap(NULL, NULL, M2C_ERROR(/* Read from unset register $r6 */));
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKAnimScript' to
MKAnimScript *MKAnimScript::Create(const char *arg0, int arg1) {
    MKAnimScript *var_r30_910;
    s8 *temp_r31_923;

    operator new(0x58U, NULL, 0);
    var_r30_910 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r30_910 != NULL) {
        var_r30_910 = ((MKAnimScript *) (M2C_ERROR(/* Read from unset register $r3 */)))->MKAnimScript();
    }
    var_r30_910->Init((s8 *) this, NULL);
    var_r30_910->unk0 = 1;
    temp_r31_923 = var_r30_910->GetAnimName();
    var_r30_910->unk8 = MKModel_Create(var_r30_910->GetMeshName(), temp_r31_923, 2, NULL);
    var_r30_910->CalculateSubObjectIndices();
    var_r30_910->SetupAliasMaterials();
    var_r30_910->SetAnimation(MKModel_GetAnimation(var_r30_910->unk8));
    return var_r30_910;
}
#endif

void MKAnimScript::Apply(Animation *arg0, int arg1) {
    MKAnim *temp_r3_989;
    f32 temp_f0_1043;
    f32 temp_f0_1077;
    f32 temp_f1_1007;
    f32 temp_f31_987;
    f32 temp_f3_1036;
    f32 var_f2_1033;
    f32 var_f2_1066;
    s16 temp_r0_969;
    s16 temp_r5_992;
    s16 temp_r7_971;
    s32 temp_r6_977;
    u32 temp_r3_959;

    temp_r3_959 = this->unk20;
    if (temp_r3_959 == 0) {
        arg0->Tween(0.0f, 1.0f);
        return;
    }
    temp_r0_969 = M2C_FIELD(temp_r3_959, s16 *, 0xA);
    temp_r7_971 = M2C_FIELD(temp_r3_959, s16 *, 0xC);
    temp_r6_977 = this->unk2C;
    temp_f31_987 = ((f32) (temp_r7_971 - temp_r0_969) * this->unk24) + (f32) temp_r0_969;
    if (temp_r6_977 & 4) {
        temp_r3_989 = this->unk10;
        if (temp_r3_989 != NULL) {
            temp_r5_992 = temp_r3_989->unkA;
            temp_f1_1007 = ((f32) (temp_r3_989->unkC - temp_r5_992) * this->unk14) + (f32) temp_r5_992;
            if (arg1 == -1) {
                arg0->Tween(temp_f1_1007, 1.0f);
                arg0->Tween(temp_f31_987, this->unk30);
                return;
            }
            arg0->TweenNode(temp_f1_1007, 1.0f, arg1, 1U, 1U);
            arg0->TweenNode(temp_f31_987, this->unk30, arg1, 1U, 1U);
            return;
        }
        var_f2_1033 = 1.0f;
        temp_f3_1036 = 1.0f - this->unk30;
        if (temp_f3_1036 != 0.0f) {
            var_f2_1033 = 1.0f;
            temp_f0_1043 = (this->unk34 * gUpdateTimeDelta) / temp_f3_1036;
            if (var_f2_1033 < temp_f0_1043) {

            } else {
                var_f2_1033 = temp_f0_1043;
            }
        }
        if (arg1 == -1) {
            arg0->Tween(temp_f31_987, var_f2_1033);
            return;
        }
        arg0->TweenNode(temp_f31_987, var_f2_1033, arg1, 1U, 1U);
        return;
    }
    var_f2_1066 = 1.0f;
    if (temp_r6_977 & 8) {
        temp_f0_1077 = 0.033333335f * ((f32) temp_r7_971 - temp_f31_987) * this->unk34;
        if (temp_f0_1077 < 1.0f) {
            var_f2_1066 = temp_f0_1077;
        }
    }
    if (arg1 == -1) {
        arg0->Tween(temp_f31_987, var_f2_1066);
        return;
    }
    arg0->TweenNode(temp_f31_987, var_f2_1066, arg1, 1U, 1U);
}

#if 0 // DRAFT: illegal explicit conversion from 'MKAnimScript_LVECalc' to
void MKAnimScript::Animate(Animation *arg0, int arg1, MKVector3 *arg2) {
    s32 sp174;
    s32 sp170;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    MKAnimScript_LVECalc sp100;
    MKAnimScript_LVECalc sp98;
    f64 sp90;                                       /* compiler-managed */
    f64 sp88;
    f64 sp78;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp48;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f30_1253;
    f32 temp_f31_1251;
    f64 temp_f0_1310;
    s16 temp_r6_1239;
    s32 temp_r3_1132;
    u32 temp_r3_1188;
    u32 temp_r7_1235;

    if ((u32) this->unk20 == 0) {
        if (arg2 != NULL) {
            M2C_FIELD(arg2, f64 *, 0) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 0);
            M2C_FIELD(arg2, f64 *, 8) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
        }
    } else {
        temp_r3_1132 = this->unk2C;
        if (temp_r3_1132 & 1) {
            this->unk3C = this->unk40;
            if (arg2 != NULL) {
                M2C_FIELD(arg2, f64 *, 0) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 0);
                M2C_FIELD(arg2, f64 *, 8) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
            }
            if (arg0 != NULL) {
                Apply(arg0, arg1);
            }
        } else {
            if (temp_r3_1132 & 4) {
                this->unk30 += this->unk34 * gUpdateTimeDelta;
                if (this->unk30 >= 1.0f) {
                    this->unk30 = 1.0f;
                    this->unk2C &= 0xFFFFFFFB;
                    this->unk10 = NULL;
                }
            }
            if (((MKAnimScript_AnimInfo *) &this->unk20)->Animate(this->unk38, &sp100) != 0) {
                this->unk10 = NULL;
            }
            if (this->unk2C & 2) {
                this->unk44 += 1;
            }
            temp_r3_1188 = this->unk20;
            this->unk3C = this->unk40;
            this->unk40 = M2C_FIELD(this->unk20, s16 *, 0xA) + (s32) (this->unk24 * (f32) (M2C_FIELD(temp_r3_1188, s16 *, 0xC) - M2C_FIELD(temp_r3_1188, s16 *, 0xA)));
            if ((MKAnim *) this->unk10 != NULL) {
                ((MKAnimScript_AnimInfo *) &this->unk10)->Animate(this->unk38, &sp98);
            }
            if (arg0 != NULL) {
                Apply(arg0, arg1);
            }
            sp88 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
            sp90 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
            if ((arg0 != NULL) && ((s32) arg0->unk28 != -1)) {
                temp_r7_1235 = this->unk20;
                sp170 = 0x43300000;
                temp_r6_1239 = M2C_FIELD(temp_r7_1235, s16 *, 0xA);
                sp174 = temp_r6_1239 ^ 0x80000000;
                temp_f31_1251 = (f32) temp_r6_1239;
                temp_f30_1253 = (f32) M2C_FIELD(temp_r7_1235, s16 *, 0xC) - temp_f31_1251;
                ((Animation *) &sp78)->GetPositionalOffset((M2C_BITWISE(f32, sp100) * temp_f30_1253) + temp_f31_1251);
                sp128 = sp78;
                sp130 = sp80;
                ((Animation *) &sp68)->GetPositionalOffset((sp100.unk4 * temp_f30_1253) + temp_f31_1251);
                sp138 = sp68;
                sp140 = sp70;
                sp18 = sp138 - sp128;
                sp58 = sp18;
                sp20 = (f32) sp140 - (f32) sp130;
                sp88 = sp18;
                sp60 = (f64) sp20;
                sp90 = (f64) sp20;
                if ((u8) sp100.unk10 != 0) {
                    ((Animation *) &sp48)->GetPositionalOffset((sp100.unk8 * temp_f30_1253) + temp_f31_1251);
                    sp148 = sp48;
                    sp150 = sp50;
                    ((Animation *) &sp38)->GetPositionalOffset((sp100.unkC * temp_f30_1253) + temp_f31_1251);
                    sp158 = sp38;
                    sp160 = sp40;
                    temp_f0_1310 = sp158 - sp148;
                    sp8 = temp_f0_1310;
                    sp28 = temp_f0_1310;
                    sp10 = (f32) sp160 - (f32) sp150;
                    sp30 = (f64) sp10;
                    sp88 += temp_f0_1310;
                    sp90 = (f32) sp90 + (f32) sp30;
                }
            }
            this->unk4C = 0;
            this->unk48 = 0;
            CheckEvents();
            if (arg2 != NULL) {
                M2C_FIELD(arg2, f64 *, 0) = sp88;
                M2C_FIELD(arg2, f64 *, 8) = (f64) sp90;
            }
        }
    }
}
#endif

u8 MKAnimScript_AnimInfo::Animate(float arg0, MKAnimScript_LVECalc *arg1) {
    f32 temp_f2_1471;
    u8 temp_r0_1371;

    arg1->unk0 = this->unk4;
    arg1->unk10 = 0;
    this->unk4 += gUpdateTimeDelta * (this->unk8 * arg0);
    this->unkC &= 0xFFFFFFFD;
    arg1->unk4 = this->unk4;
    temp_r0_1371 = M2C_FIELD(this->unk0, u8 *, 8);
    if (temp_r0_1371 == 1) {
        if (this->unk8 == 0.0f) {
            this->unkC |= 2;
        }
loop_5:
        if (this->unk4 > 1.0f) {
            this->unkC |= 2;
            this->unk4 -= 1.0f;
            arg1->unk4 = 1.0f;
            arg1->unk8 = 0.0f;
            arg1->unkC = this->unk4;
            arg1->unk10 = 1;
            goto loop_5;
        }
loop_8:
        if (this->unk4 < 0.0f) {
            this->unkC |= 2;
            this->unk4 += 1.0f;
            arg1->unk4 = 0.0f;
            arg1->unk8 = 1.0f;
            arg1->unkC = this->unk4;
            arg1->unk10 = 1;
            goto loop_8;
        }
        /* Duplicate return node #23. Try simplifying control flow for better match */
        return 0U;
    }
    if (temp_r0_1371 == 2) {
        if (this->unk8 == 0.0f) {
            this->unkC |= 2;
        }
        if (this->unk4 > 1.0f) {
            this->unk4 = 1.0f;
            this->unk8 = -this->unk8;
            arg1->unk4 = this->unk4;
        }
        if (this->unk4 < 0.0f) {
            this->unkC |= 2;
            this->unk4 = 0.0f;
            this->unk8 = -this->unk8;
            arg1->unk4 = this->unk4;
        }
        /* Duplicate return node #23. Try simplifying control flow for better match */
        return 0U;
    }
    if (this->unk8 == 0.0f) {
        this->unkC |= 1;
        this->unk4 = 1.0f;
        /* Duplicate return node #23. Try simplifying control flow for better match */
        return 0U;
    }
    temp_f2_1471 = this->unk4;
    if (temp_f2_1471 >= 1.0f) {
        this->unkC |= 1;
        this->unk4 = 1.0f;
        arg1->unk4 = this->unk4;
        return 1U;
    }
    if (temp_f2_1471 < 0.0f) {
        this->unkC |= 1;
        this->unk4 = 0.0f;
        arg1->unk4 = this->unk4;
        return 1U;
    }
    return 0U;
}

#if 0 // DRAFT: undefined identifier '__shl2i'
void MKAnimScript::Check(int arg0, int arg1, MKAnimScriptedEvent &arg2) {
    s16 temp_r0_1509;
    s32 temp_r3_1511;
    s32 temp_r7_1508;
    u64 temp_ret_1526;
    u64 temp_ret_1543;

    temp_r7_1508 = arg2.unk8;
    temp_r0_1509 = arg2.unk6;
    temp_r3_1511 = arg2.unkC;
    if ((temp_r7_1508 != -1) && (temp_r0_1509 != -1) && (temp_r0_1509 != -2)) {
        if (arg0 <= arg1) {
            if ((temp_r3_1511 > arg0) && (temp_r0_1509 <= arg1)) {
                temp_ret_1526 = __shl2i(0, 1, temp_r7_1508);
                this->unk4C |= (u32) temp_ret_1526;
                this->unk48 |= temp_ret_1526;
            }
        } else if ((temp_r3_1511 > arg0) || (temp_r0_1509 <= arg1)) {
            temp_ret_1543 = __shl2i(0, 1, temp_r7_1508);
            this->unk4C |= (u32) temp_ret_1543;
            this->unk48 |= temp_ret_1543;
        }
    }
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class
void MKAnimScript::CheckSwitch(MKAnimScriptedEvent::AnimationSwitch arg1) {
    M2C_UNK var_r24_1636;
    MKModel *temp_r3_1600;
    s16 temp_r0_1680;
    s16 temp_r25_1608;
    s16 var_ctr_1681;
    s32 var_r27_1571;
    s32 var_r27_1597;
    s32 var_r30_1570;
    s32 var_r30_1596;
    s8 *temp_r3_1635;
    u32 temp_r31_1567;
    u64 temp_ret_1582;
    void *temp_r26_1604;
    void *temp_r3_1575;

    temp_r31_1567 = this->unk20;
    if (temp_r31_1567 != 0) {
        var_r30_1570 = 0;
        var_r27_1571 = 0;
loop_5:
        if (var_r30_1570 < (s16) M2C_FIELD(temp_r31_1567, s16 *, 0xE)) {
            temp_r3_1575 = M2C_FIELD(temp_r31_1567, s32 *, 0x10) + var_r27_1571;
            if ((s16) M2C_FIELD(temp_r3_1575, s16 *, 6) == (s32) arg1) {
                temp_ret_1582 = __shl2i(0, 1, M2C_FIELD(temp_r3_1575, s32 *, 8));
                this->unk4C |= (u32) temp_ret_1582;
                this->unk48 |= temp_ret_1582;
            }
            var_r30_1570 += 1;
            var_r27_1571 += 0x10;
            goto loop_5;
        }
        var_r30_1596 = 0;
        var_r27_1597 = 0;
loop_20:
        if (var_r30_1596 < (s16) M2C_FIELD(temp_r31_1567, s16 *, 0x1C)) {
            temp_r3_1600 = this->unk8;
            if (temp_r3_1600 != NULL) {
                temp_r26_1604 = M2C_FIELD(temp_r31_1567, s32 *, 0x20) + var_r27_1597;
                if ((s16) M2C_FIELD(temp_r26_1604, s16 *, 6) == (s32) arg1) {
                    temp_r25_1608 = M2C_FIELD(temp_r26_1604, s16 *, 4);
                    if (temp_r25_1608 == 4) {
                        MKModel_EnableOnlySubObject(temp_r3_1600, (SubObjectType) 0, -1, 0U, 1U);
                        this->unk54 |= ~0;
                    } else if (temp_r25_1608 == 5) {
                        MKModel_EnableOnlySubObject(temp_r3_1600, (SubObjectType) 0, -1, 1U, 1U);
                        this->unk54 |= ~0;
                    } else {
                        temp_r3_1635 = M2C_FIELD(temp_r26_1604, s8 **, 0);
                        var_r24_1636 = 0;
                        if (temp_r3_1635 != NULL) {
                            if (strnicmp(temp_r3_1635, "p_", 2) == 0) {
                                var_r24_1636 = 2;
                            } else if (strnicmp(M2C_FIELD(temp_r26_1604, s8 **, 0), "s_", 2) == 0) {
                                var_r24_1636 = 1;
                            }
                        }
                        MKModel_EnableSubObject(this->unk8, (SubObjectType) var_r24_1636, M2C_FIELD(temp_r26_1604, s32 *, 8), temp_r25_1608 == 2, 1U);
                        this->unk54 |= 1 << M2C_FIELD(temp_r26_1604, s32 *, 8);
                    }
                }
            }
            var_r30_1596 += 1;
            var_r27_1597 += 0x10;
            goto loop_20;
        }
        temp_r0_1680 = M2C_FIELD(temp_r31_1567, s16 *, 0x24);
        var_ctr_1681 = temp_r0_1680;
        if (temp_r0_1680 > 0) {
            do {
                var_ctr_1681 -= 1;
            } while (var_ctr_1681 != 0);
        }
    }
}
#endif

#if 0 // DRAFT: pointer/array required
void MKAnimScript::CheckEvents() {
    MKModel *temp_r3_1738;
    s16 temp_r0_1822;
    s16 temp_r4_1743;
    s16 temp_r5_1749;
    s16 var_ctr_1823;
    s32 var_r27_1718;
    s32 var_r27_1735;
    s32 var_r29_1717;
    s32 var_r29_1734;
    s32 var_r30_1711;
    s32 var_r31_1710;
    u32 temp_r3_1730;
    u32 temp_r4_1818;
    u8 var_r0_1752;
    void *temp_r26_1742;

    if ((u32) this->unk20 != 0) {
        if (this->unk38 >= 0.0f) {
            var_r31_1710 = this->unk3C;
            var_r30_1711 = this->unk40;
        } else {
            var_r31_1710 = this->unk40;
            var_r30_1711 = this->unk3C;
        }
        var_r29_1717 = 0;
        var_r27_1718 = 0;
loop_6:
        temp_r3_1730 = this->unk20;
        if (var_r29_1717 < (s16) M2C_FIELD(temp_r3_1730, s16 *, 0xE)) {
            Check(var_r31_1710, var_r30_1711, *(M2C_FIELD(temp_r3_1730, s32 *, 0x10) + var_r27_1718));
            var_r29_1717 += 1;
            var_r27_1718 += 0x10;
            goto loop_6;
        }
        var_r29_1734 = 0;
        var_r27_1735 = 0;
loop_27:
        temp_r4_1818 = this->unk20;
        if (var_r29_1734 < (s16) M2C_FIELD(temp_r4_1818, s16 *, 0x1C)) {
            temp_r3_1738 = this->unk8;
            if (temp_r3_1738 != NULL) {
                temp_r26_1742 = M2C_FIELD(temp_r4_1818, s32 *, 0x20) + var_r27_1735;
                temp_r4_1743 = M2C_FIELD(temp_r26_1742, s16 *, 6);
                if ((temp_r4_1743 != -1) && (temp_r4_1743 != -2)) {
                    temp_r5_1749 = M2C_FIELD(temp_r26_1742, s16 *, 4);
                    if (var_r31_1710 < var_r30_1711) {
                        var_r0_1752 = 0;
                        if ((temp_r4_1743 > var_r31_1710) && (temp_r4_1743 <= var_r30_1711)) {
                            var_r0_1752 = 1;
                        }
                    } else if (var_r31_1710 == var_r30_1711) {
                        var_r0_1752 = temp_r4_1743 == var_r31_1710;
                    } else {
                        var_r0_1752 = 0;
                        if ((temp_r4_1743 > var_r31_1710) || (temp_r4_1743 <= var_r30_1711)) {
                            var_r0_1752 = 1;
                        }
                    }
                    if (var_r0_1752 != 0) {
                        if (temp_r5_1749 == 4) {
                            MKModel_EnableOnlySubObject(temp_r3_1738, (SubObjectType) 0, -1, 0U, 1U);
                            this->unk54 |= ~0;
                        } else if (temp_r5_1749 == 5) {
                            MKModel_EnableOnlySubObject(temp_r3_1738, (SubObjectType) 0, -1, 1U, 1U);
                            this->unk54 |= ~0;
                        } else {
                            MKModel_EnableSubObject(temp_r3_1738, (SubObjectType) 0, M2C_FIELD(temp_r26_1742, s32 *, 8), temp_r5_1749 == 2, 1U);
                            this->unk54 |= 1 << M2C_FIELD(temp_r26_1742, s32 *, 8);
                        }
                    }
                }
            }
            var_r29_1734 += 1;
            var_r27_1735 += 0x10;
            goto loop_27;
        }
        temp_r0_1822 = M2C_FIELD(temp_r4_1818, s16 *, 0x24);
        var_ctr_1823 = temp_r0_1822;
        if (temp_r0_1822 > 0) {
            do {
                var_ctr_1823 -= 1;
            } while (var_ctr_1823 != 0);
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__shl2i'
u8 MKAnimScript::CheckEvent(int arg0) {
    u64 temp_ret_1848;

    temp_ret_1848 = __shl2i(0, 1, arg0);
    return (u8) (((((u32) temp_ret_1848 & this->unk4C) ^ 0) | ((temp_ret_1848 & this->unk48) ^ 0)) != 0);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const char **' to
void MKAnimScript::InitEvents(const char **arg0) {
    s32 var_r24_1885;
    s32 var_r25_1880;
    s32 var_r27_1875;
    s32 var_r30_1886;
    s32 var_r31_1881;
    s8 **var_r28_1874;
    void *temp_r23_1891;
    void *temp_r26_1877;
    void *temp_r29_1884;

    var_r28_1874 = arg0;
    var_r27_1875 = 0;
    temp_r26_1877 = M2C_FIELD(this->unk4, void **, 0x34);
loop_10:
    if ((s8 *) *var_r28_1874 != NULL) {
        var_r25_1880 = 0;
        var_r31_1881 = 0;
loop_8:
        if (var_r25_1880 < (s32) M2C_FIELD(temp_r26_1877, u16 *, 8)) {
            temp_r29_1884 = ((u8 *) temp_r26_1877) + var_r31_1881;
            var_r24_1885 = 0;
            var_r30_1886 = 0;
loop_6:
            if (var_r24_1885 < (s16) M2C_FIELD(temp_r29_1884, s16 *, 0x1E)) {
                temp_r23_1891 = M2C_FIELD(temp_r29_1884, s32 *, 0x20) + var_r30_1886;
                if (stricmp((MKAnim *) *var_r28_1874, M2C_FIELD(temp_r23_1891, s8 **, 0)) == 0) {
                    M2C_FIELD(temp_r23_1891, s32 *, 8) = var_r27_1875;
                }
                var_r24_1885 += 1;
                var_r30_1886 += 0x10;
                goto loop_6;
            }
            var_r25_1880 += 1;
            var_r31_1881 += 0x30;
            goto loop_8;
        }
        var_r27_1875 += 1;
        var_r28_1874 += 4;
        goto loop_10;
    }
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class
s32 MKAnimScript::GetEvent(int arg1, MKAnimScriptedEvent::EventType arg2) {
    MKAnimScriptedEvent *temp_r31_1958;
    s16 temp_r0_1969;
    s16 temp_r3_1961;
    s16 var_ctr_1964;
    s32 temp_cr0_eq_1979;
    s32 temp_cr0_eq_1990;
    s32 temp_cr0_eq_2003;
    s32 temp_cr0_eq_2014;
    s32 temp_r0_1936;
    s32 temp_r0_1973;
    s32 temp_r4_1937;
    s32 temp_r6_1997;
    s32 var_r29_1950;
    s32 var_r30_1949;
    s32 var_r4_1963;
    s32 var_r5_1962;
    u32 temp_r3_1933;
    void *temp_r3_1968;

    temp_r3_1933 = this->unk20;
    if ((temp_r3_1933 == 0) || (temp_r0_1936 = this->unk3C, temp_r4_1937 = this->unk40, ((temp_r0_1936 == temp_r4_1937) != 0))) {
        return 0;
    }
    if (this->unk38 >= 0.0f) {
        var_r30_1949 = temp_r0_1936;
        var_r29_1950 = temp_r4_1937;
    } else {
        var_r30_1949 = temp_r4_1937;
        var_r29_1950 = temp_r0_1936;
    }
    temp_r31_1958 = ((MKAnim *) temp_r3_1933)->GetFirstEvent(arg2);
    temp_r3_1961 = ((MKAnim *) this->unk20)->GetNumberOfEvents(arg2);
    var_r5_1962 = 0;
    var_r4_1963 = 0;
    var_ctr_1964 = temp_r3_1961;
    if (temp_r3_1961 > 0) {
loop_7:
        temp_r3_1968 = temp_r31_1958 + var_r4_1963;
        temp_r0_1969 = M2C_FIELD(temp_r3_1968, s16 *, 6);
        if (temp_r0_1969 == -2) {
            temp_r0_1973 = this->unk50;
            if (var_r30_1949 < var_r29_1950) {
                if ((temp_r0_1973 >= var_r30_1949) && (temp_r0_1973 <= var_r29_1950)) {
                    temp_cr0_eq_1979 = var_r5_1962 == arg1;
                    var_r5_1962 += 1;
                    if (temp_cr0_eq_1979 != 0) {
                        return M2C_FIELD(temp_r3_1968, s32 *, 0);
                    }
                }
                goto block_26;
            }
            if ((temp_r0_1973 >= var_r30_1949) || (temp_r0_1973 <= var_r29_1950)) {
                temp_cr0_eq_1990 = var_r5_1962 == arg1;
                var_r5_1962 += 1;
                if (temp_cr0_eq_1990 != 0) {
                    return M2C_FIELD(temp_r3_1968, s32 *, 0);
                }
            }
            goto block_26;
        }
        temp_r6_1997 = M2C_FIELD(temp_r3_1968, s32 *, 0xC);
        if (var_r30_1949 < var_r29_1950) {
            if ((temp_r6_1997 > var_r30_1949) && (temp_r0_1969 <= var_r29_1950)) {
                temp_cr0_eq_2003 = var_r5_1962 == arg1;
                var_r5_1962 += 1;
                if (temp_cr0_eq_2003 != 0) {
                    return M2C_FIELD(temp_r3_1968, s32 *, 0);
                }
            }
            goto block_26;
        }
        if ((temp_r6_1997 > var_r30_1949) || (temp_r0_1969 <= var_r29_1950)) {
            temp_cr0_eq_2014 = var_r5_1962 == arg1;
            var_r5_1962 += 1;
            if (temp_cr0_eq_2014 != 0) {
                return M2C_FIELD(temp_r3_1968, s32 *, 0);
            }
        }
block_26:
        var_r4_1963 += 0x10;
        var_ctr_1964 -= 1;
        if (var_ctr_1964 == 0) {
            goto block_27;
        }
        goto loop_7;
    }
block_27:
    return 0;
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class
s8 *MKAnimScript::GetEventByName(const char *arg1, MKAnimScriptedEvent::EventType arg2) {
    MKAnim *temp_r30_2049;
    MKAnimScriptedEvent *var_r27_2054;
    s16 temp_r30_2057;
    s32 var_r26_2058;
    s32 var_r28_2041;
    s32 var_r31_2042;
    void *temp_r29_2044;

    var_r28_2041 = 0;
    var_r31_2042 = 0;
    temp_r29_2044 = M2C_FIELD(this->unk4, void **, 0x34);
loop_7:
    if (var_r28_2041 >= (s32) M2C_FIELD(temp_r29_2044, u16 *, 8)) {
        return NULL;
    }
    temp_r30_2049 = ((u8 *) temp_r29_2044) + (var_r31_2042 + 0x10);
    var_r27_2054 = temp_r30_2049->GetFirstEvent(arg2);
    temp_r30_2057 = temp_r30_2049->GetNumberOfEvents(arg2);
    var_r26_2058 = 0;
loop_5:
    if (var_r26_2058 >= temp_r30_2057) {
        var_r28_2041 += 1;
        var_r31_2042 += 0x30;
        goto loop_7;
    }
    if (strcmpi(arg1, &var_r27_2054->unk0->unk0) == 0) {
        return &var_r27_2054->unk0->unk0;
    }
    var_r27_2054 += 0x10;
    var_r26_2058 += 1;
    goto loop_5;
}
#endif

#if 0 // DRAFT: illegal operand
void MKAnimScript::SetAnim(MKAnim *arg0, float arg1, float arg2, int arg3, int arg4) {
    Animation *temp_r4_2289;
    f32 temp_f2_2109;
    f32 var_f0_2255;
    f32 var_f31_2146;
    s32 temp_r4_2245;
    u32 temp_r4_2242;
    u8 var_r3_2107;

    if (arg0 != NULL) {
        this->unk38 = arg1;
        var_r3_2107 = 0;
        temp_f2_2109 = this->unk24;
        if (((temp_f2_2109 == 1.0f) && (arg1 > 0.0f)) || ((temp_f2_2109 == 0.0f) && (arg1 < 0.0f))) {
            var_r3_2107 = 1;
        }
        if (var_r3_2107 != 0) {
            this->unk2C |= 1;
        } else {
            this->unk2C &= 0xFFFFFFFE;
        }
        this->unk4C = 0;
        this->unk48 = 0;
        if ((arg0 != (u32) this->unk20) || (var_r3_2107 != 0) || (arg3 & 4)) {
            var_f31_2146 = 0.0f;
            if (arg1 >= 0.0f) {

            } else {
                var_f31_2146 = 1.0f;
            }
            CheckSwitch((MKAnimScriptedEvent::AnimationSwitch) -1);
            if (arg3 & 0x10) {
                this->unk10 = (MKAnim *) this->unk20;
                this->unk20 = (u32) arg0;
                this->unk2C = 4;
                this->unk1C = 0;
                this->unk18 = this->unk28;
                this->unk34 = 1.0f / arg2;
                this->unk14 = this->unk24;
                if (arg3 & 1) {
                    var_f31_2146 = this->unk24;
                }
                this->unk24 = var_f31_2146;
                this->unk30 = 0.0f;
            } else if (arg2 == 0.0f) {
                this->unk10 = NULL;
                this->unk20 = (u32) arg0;
                this->unk2C = 0;
                if (arg3 & 1) {
                    var_f31_2146 = this->unk24;
                }
                this->unk24 = var_f31_2146;
            } else if (!(arg3 & 2)) {
                this->unk10 = NULL;
                this->unk20 = (u32) arg0;
                this->unk2C = 4;
                this->unk30 = 0.0f;
                this->unk34 = 1.0f / arg2;
                if (arg3 & 1) {
                    var_f31_2146 = this->unk24;
                }
                this->unk24 = var_f31_2146;
            } else {
                this->unk10 = (MKAnim *) this->unk20;
                this->unk20 = (u32) arg0;
                this->unk2C = 4;
                this->unk1C = 0;
                this->unk18 = this->unk28;
                this->unk34 = 1.0f / arg2;
                this->unk14 = this->unk24;
                if (arg3 & 1) {
                    var_f31_2146 = this->unk24;
                }
                this->unk24 = var_f31_2146;
                this->unk30 = 0.0f;
            }
            if (arg3 & 8) {
                this->unk2C |= 8;
            }
            temp_r4_2242 = this->unk20;
            temp_r4_2245 = M2C_FIELD(temp_r4_2242, s16 *, 0xC) - M2C_FIELD(temp_r4_2242, s16 *, 0xA);
            if (temp_r4_2245 != 0) {
                var_f0_2255 = 30.0f / (f32) temp_r4_2245;
            } else {
                var_f0_2255 = 0.0f;
            }
            this->unk28 = var_f0_2255;
            this->unk40 = M2C_FIELD(this->unk20, s16 *, 0xA) + (s32) (this->unk24 * (f32) temp_r4_2245);
            this->unk3C = this->unk40 - 1;
            this->unk44 = 0;
            this->unk50 = this->unk40;
            CheckSwitch((MKAnimScriptedEvent::AnimationSwitch) -2);
            CheckEvents();
            temp_r4_2289 = this->unkC;
            if ((temp_r4_2289 != NULL) && !(arg3 & 0x20)) {
                Apply(temp_r4_2289, arg4);
            }
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
void MKAnimScript::ReadBinary(const char *arg0) {
    MKResource *temp_r3_2323;
    MKResource *temp_r4_2326;
    MKResource *temp_r4_2338;
    MKResource *temp_r7_2527;
    s32 temp_r8_2416;
    s32 temp_r8_2427;
    s32 temp_r8_2440;
    s32 temp_r9_2429;
    s32 temp_r9_2442;
    s32 temp_r9_2465;
    s32 temp_r9_2487;
    s32 temp_r9_2509;
    s32 var_r10_2410;
    s32 var_r10_2458;
    s32 var_r10_2480;
    s32 var_r10_2502;
    s32 var_r3_2350;
    s32 var_r5_2351;
    s32 var_r6_2411;
    s32 var_r6_2459;
    s32 var_r6_2481;
    s32 var_r6_2503;
    void **temp_r3_2327;
    void **temp_r3_2339;
    void **temp_r6_2528;
    void *temp_r0_2328;
    void *temp_r0_2340;
    void *temp_r0_2356;
    void *temp_r4_2355;
    void *temp_r6_2366;
    void *temp_r6_2377;
    void *temp_r6_2388;
    void *temp_r6_2399;
    void *temp_r7_2414;
    void *temp_r7_2426;
    void *temp_r7_2439;
    void *temp_r8_2463;
    void *temp_r8_2485;
    void *temp_r8_2507;

    this->unk4 = MKArchive_Load(arg0, NULL, NULL, -1);
    temp_r3_2323 = this->unk4;
    M2C_FIELD(temp_r3_2323, void ***, 0x34) = (void **) (temp_r3_2323 + 0x38);
    temp_r4_2326 = this->unk4;
    temp_r3_2327 = M2C_FIELD(temp_r4_2326, void ***, 0x34);
    temp_r0_2328 = M2C_FIELD(temp_r3_2327, void **, 4);
    if (temp_r0_2328 > 0) {
        M2C_FIELD(temp_r3_2327, void **, 4) = (void *) (((u8 *) temp_r0_2328) + temp_r4_2326);
    } else {
        M2C_FIELD(temp_r3_2327, void **, 4) = NULL;
    }
    temp_r4_2338 = this->unk4;
    temp_r3_2339 = M2C_FIELD(temp_r4_2338, void ***, 0x34);
    temp_r0_2340 = *temp_r3_2339;
    if (temp_r0_2340 > 0) {
        *temp_r3_2339 = ((u8 *) temp_r0_2340) + temp_r4_2338;
    } else {
        *temp_r3_2339 = NULL;
    }
    var_r3_2350 = 0;
    var_r5_2351 = 0;
loop_53:
    temp_r7_2527 = this->unk4;
    temp_r6_2528 = M2C_FIELD(temp_r7_2527, void ***, 0x34);
    if (var_r3_2350 < (s32) M2C_FIELD(temp_r6_2528, u16 *, 8)) {
        temp_r4_2355 = temp_r6_2528 + (var_r5_2351 + 0x10);
        temp_r0_2356 = M2C_FIELD(temp_r4_2355, void **, 0);
        if (temp_r0_2356 > 0) {
            M2C_FIELD(temp_r4_2355, void **, 0) = (void *) (((u8 *) temp_r0_2356) + temp_r7_2527);
        } else {
            M2C_FIELD(temp_r4_2355, void **, 0) = NULL;
        }
        temp_r6_2366 = M2C_FIELD(temp_r4_2355, void **, 0x28);
        if (temp_r6_2366 > 0) {
            M2C_FIELD(temp_r4_2355, void **, 0x28) = (void *) (((u8 *) temp_r6_2366) + this->unk4);
        } else {
            M2C_FIELD(temp_r4_2355, void **, 0x28) = NULL;
        }
        temp_r6_2377 = M2C_FIELD(temp_r4_2355, void **, 0x10);
        if (temp_r6_2377 > 0) {
            M2C_FIELD(temp_r4_2355, void **, 0x10) = (void *) (((u8 *) temp_r6_2377) + this->unk4);
        } else {
            M2C_FIELD(temp_r4_2355, void **, 0x10) = NULL;
        }
        temp_r6_2388 = M2C_FIELD(temp_r4_2355, void **, 0x18);
        if (temp_r6_2388 > 0) {
            M2C_FIELD(temp_r4_2355, void **, 0x18) = (void *) (((u8 *) temp_r6_2388) + this->unk4);
        } else {
            M2C_FIELD(temp_r4_2355, void **, 0x18) = NULL;
        }
        temp_r6_2399 = M2C_FIELD(temp_r4_2355, void **, 0x20);
        if (temp_r6_2399 > 0) {
            M2C_FIELD(temp_r4_2355, void **, 0x20) = (void *) (((u8 *) temp_r6_2399) + this->unk4);
        } else {
            M2C_FIELD(temp_r4_2355, void **, 0x20) = NULL;
        }
        var_r10_2410 = 0;
        var_r6_2411 = 0;
loop_33:
        if (var_r10_2410 < (s16) M2C_FIELD(temp_r4_2355, s16 *, 0x24)) {
            temp_r7_2414 = M2C_FIELD(temp_r4_2355, void **, 0x28);
            temp_r8_2416 = *(temp_r7_2414 + var_r6_2411);
            if (temp_r8_2416 > 0) {
                *(temp_r7_2414 + var_r6_2411) = temp_r8_2416 + this->unk4;
            } else {
                *(temp_r7_2414 + var_r6_2411) = 0;
            }
            temp_r7_2426 = M2C_FIELD(temp_r4_2355, void **, 0x28);
            temp_r8_2427 = var_r6_2411 + 8;
            temp_r9_2429 = *(temp_r7_2426 + temp_r8_2427);
            if (temp_r9_2429 > 0) {
                *(temp_r7_2426 + temp_r8_2427) = temp_r9_2429 + this->unk4;
            } else {
                *(temp_r7_2426 + temp_r8_2427) = 0;
            }
            temp_r7_2439 = M2C_FIELD(temp_r4_2355, void **, 0x28);
            temp_r8_2440 = var_r6_2411 + 0xC;
            temp_r9_2442 = *(temp_r7_2439 + temp_r8_2440);
            if (temp_r9_2442 > 0) {
                *(temp_r7_2439 + temp_r8_2440) = temp_r9_2442 + this->unk4;
            } else {
                *(temp_r7_2439 + temp_r8_2440) = 0;
            }
            var_r10_2410 += 1;
            var_r6_2411 += 0x10;
            goto loop_33;
        }
        var_r10_2458 = 0;
        var_r6_2459 = 0;
loop_39:
        if (var_r10_2458 < (s16) M2C_FIELD(temp_r4_2355, s16 *, 0xE)) {
            temp_r8_2463 = M2C_FIELD(temp_r4_2355, void **, 0x10);
            temp_r9_2465 = *(temp_r8_2463 + var_r6_2459);
            if (temp_r9_2465 > 0) {
                *(temp_r8_2463 + var_r6_2459) = temp_r9_2465 + this->unk4;
            } else {
                *(temp_r8_2463 + var_r6_2459) = 0;
            }
            var_r10_2458 += 1;
            var_r6_2459 += 0x10;
            goto loop_39;
        }
        var_r10_2480 = 0;
        var_r6_2481 = 0;
loop_45:
        if (var_r10_2480 < (s16) M2C_FIELD(temp_r4_2355, s16 *, 0x14)) {
            temp_r8_2485 = M2C_FIELD(temp_r4_2355, void **, 0x18);
            temp_r9_2487 = *(temp_r8_2485 + var_r6_2481);
            if (temp_r9_2487 > 0) {
                *(temp_r8_2485 + var_r6_2481) = temp_r9_2487 + this->unk4;
            } else {
                *(temp_r8_2485 + var_r6_2481) = 0;
            }
            var_r10_2480 += 1;
            var_r6_2481 += 0x10;
            goto loop_45;
        }
        var_r10_2502 = 0;
        var_r6_2503 = 0;
loop_51:
        if (var_r10_2502 < (s16) M2C_FIELD(temp_r4_2355, s16 *, 0x1C)) {
            temp_r8_2507 = M2C_FIELD(temp_r4_2355, void **, 0x20);
            temp_r9_2509 = *(temp_r8_2507 + var_r6_2503);
            if (temp_r9_2509 > 0) {
                *(temp_r8_2507 + var_r6_2503) = temp_r9_2509 + this->unk4;
            } else {
                *(temp_r8_2507 + var_r6_2503) = 0;
            }
            var_r10_2502 += 1;
            var_r6_2503 += 0x10;
            goto loop_51;
        }
        var_r3_2350 += 1;
        var_r5_2351 += 0x30;
        goto loop_53;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'stricmp'
void MKAnimScript::Init(const char *arg0, MKModel *arg1) {
    MKIni sp2C;
    s8 spC;
    s32 sp8;
    MKIni *temp_r3_2600;
    MKResource **temp_r3_2631;
    MKResource **var_r30_2551;
    MKResource *temp_r0_2569;
    MKResource *temp_r0_2630;
    MKResource *temp_r4_2573;
    s32 temp_ret_2587;
    s8 *temp_r3_2584;
    s8 *temp_ret_2600;

    this->unk0 = 0;
    this->unk8 = arg1;
    var_r30_2551 = mkAnimScriptTemplates;
loop_4:
    if ((MKResource *) *var_r30_2551 != NULL) {
        if ((stricmp((MKAnim *) arg0) != 0) || (((MKResource *) (*var_r30_2551))->IsResourceAvailable() == 0)) {
            var_r30_2551 += 4;
            goto loop_4;
        }
    }
    temp_r0_2569 = *var_r30_2551;
    if (temp_r0_2569 != NULL) {
        this->unk4 = temp_r0_2569;
        temp_r4_2573 = this->unk4;
        temp_r4_2573->unk24 += 1;
        goto block_13;
    }
    temp_r3_2584 = Str_Printf("%s.bbi", arg0);
    temp_ret_2587 = MKArchive_Exists(temp_r3_2584, &sp8);
    if (temp_ret_2587 != 0) {
        ReadBinary(temp_r3_2584);
        goto block_12;
    }
    temp_ret_2600 = Str_Printf("%s.bad", arg0, M2C_BITWISE(f32, temp_ret_2587));
    temp_r3_2600 = temp_ret_2600;
    if (temp_r3_2600->Exists((s8 *) (u32) (u64) temp_ret_2600) != 0) {
        ((MKHeap *) (strcpy(&spC, &temp_r3_2600->unk0)))->ActivateTempMemOverride();
        ((MKHeap *) (sp2C.Init(&spC, 0, NULL)))->DeactivateTempMemOverride();
        this->unk4 = ParseBadFile(&sp2C, &spC, this->unk8);
        sp2C.Deinit();
block_12:
        temp_r0_2630 = this->unk4;
        temp_r3_2631 = mkAnimScriptTemplates - 4;
        mkAnimScriptTemplates = temp_r3_2631;
        *temp_r3_2631 = temp_r0_2630;
        this->unk4 = temp_r0_2630;
        strcpy(&this->unk4->unk0, arg0);
        this->unk4->unk24 = 1;
        this->unk4->InitialiseResource();
block_13:
        this->unk20 = 0;
        this->unk24 = 0.0f;
        this->unk28 = 0.0f;
        this->unk2C = 1;
        this->unk38 = 1.0f;
        this->unk3C = -1;
        this->unk40 = 0;
        this->unk44 = 0;
        this->unk4C = 0;
        this->unk48 = 0;
        this->unkC = NULL;
        this->unk50 = 0;
        this->unk54 = 0;
        CalculateSubObjectIndices();
        SetupAliasMaterials();
        return;
    }
    this->unk4 = NULL;
}
#endif

s8 *MKAnimScript::GetAnimName() {
    return M2C_FIELD(M2C_FIELD(this->unk4, void **, 0x34), s8 **, 4);
}

s8 *MKAnimScript::GetMeshName() {
    return *M2C_FIELD(this->unk4, s8 ***, 0x34);
}

#if 0 // DRAFT: illegal type
s32 MKAnimScript::Exists(const char *arg0) {
    s32 var_r30_2700;
    s32 var_r31_2701;
    void *temp_r4_2717;

    var_r30_2700 = 0;
    var_r31_2701 = 0;
loop_4:
    temp_r4_2717 = M2C_FIELD(this->unk4, void **, 0x34);
    if (var_r30_2700 >= (s32) M2C_FIELD(temp_r4_2717, u16 *, 8)) {
        return 0;
    }
    if (strcmpi(arg0, *(temp_r4_2717 + (var_r31_2701 + 0x10))) == 0) {
        return 1;
    }
    var_r30_2700 += 1;
    var_r31_2701 += 0x30;
    goto loop_4;
}
#endif

void *MKAnimScript::GetAnim(int arg0) {
    void *temp_r5_2734;

    temp_r5_2734 = M2C_FIELD(this->unk4, void **, 0x34);
    if (arg0 < (s32) M2C_FIELD(temp_r5_2734, u16 *, 8)) {
        return ((u8 *) temp_r5_2734) + ((arg0 * 0x30) + 0x10);
    }
    return NULL;
}

#if 0 // DRAFT: illegal type
void *MKAnimScript::GetAnim(const char *arg0) {
    s32 var_r30_2762;
    s32 var_r31_2763;
    void *temp_r4_2782;

    if ((s8) (u8) *arg0 == 0) {
        return NULL;
    }
    var_r30_2762 = 0;
    var_r31_2763 = 0;
loop_6:
    temp_r4_2782 = M2C_FIELD(this->unk4, void **, 0x34);
    if (var_r30_2762 >= (s32) M2C_FIELD(temp_r4_2782, u16 *, 8)) {
        return NULL;
    }
    if (strcmpi(arg0, *(temp_r4_2782 + (var_r31_2763 + 0x10))) == 0) {
        return M2C_FIELD(this->unk4, void **, 0x34) + (var_r31_2763 + 0x10);
    }
    var_r30_2762 += 1;
    var_r31_2763 += 0x30;
    goto loop_6;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk24'
void MKAnimScript::Deinit() {
    MKHeap *temp_r3_2816;
    MKResource *temp_r31_2815;
    MKResource *temp_r4_2803;
    s32 temp_r0_2807;

    temp_r4_2803 = this->unk4;
    if (temp_r4_2803 != NULL) {
        temp_r0_2807 = temp_r4_2803->unk24 - 1;
        temp_r4_2803->unk24 = temp_r0_2807;
        if (temp_r0_2807 == 0) {
            ((MKAnimScriptTemplate *) this->unk4)->DeinitMKAnimScriptData();
            temp_r31_2815 = this->unk4;
            temp_r3_2816 = ((MKHeap *) (((MKPtrList<MKAnimScriptTemplate> *) &mkAnimScriptTemplates)->Destroy((MKAnimScriptTemplate *) this->unk4)))->Current();
            if (temp_r3_2816 != NULL) {
                ((MKHeap *) (temp_r3_2816->Current()))->Free(temp_r31_2815, NULL, 0);
            } else {
                free(temp_r31_2815);
            }
        }
        this->unk4 = NULL;
    }
}
#endif

#if 0 // DRAFT: function call 'Init(signed char *, MKModel *)' does not match
void MKAnimScript::Init(MKAnimScript *arg0, MKModel *arg1) {
    Init(&arg0->unk4->unk0, arg1);
}
#endif

#if 0 // DRAFT: illegal type
void MKAnimScript::SetupAliasMaterials() {
    MKAnim *temp_r28_2875;
    s16 temp_r3_2880;
    s16 var_ctr_2881;
    s32 var_r29_2865;
    s32 var_r31_2866;
    u16 temp_r30_2868;

    if ((MKModel *) this->unk8 != NULL) {
        var_r29_2865 = 0;
        var_r31_2866 = 0;
        temp_r30_2868 = M2C_FIELD(M2C_FIELD(this->unk4, void **, 0x34), u16 *, 8);
loop_5:
        if (var_r29_2865 < (s32) temp_r30_2868) {
            temp_r28_2875 = M2C_FIELD(this->unk4, void **, 0x34) + (var_r31_2866 + 0x10);
            temp_r28_2875->GetFirstEvent((MKAnimScriptedEvent::EventType) 6);
            temp_r3_2880 = temp_r28_2875->GetNumberOfEvents((MKAnimScriptedEvent::EventType) 6);
            var_ctr_2881 = temp_r3_2880;
            if (temp_r3_2880 > 0) {
                do {
                    var_ctr_2881 -= 1;
                } while (var_ctr_2881 != 0);
            }
            var_r29_2865 += 1;
            var_r31_2866 += 0x30;
            goto loop_5;
        }
    }
}
#endif

#if 0 // DRAFT: illegal type
void MKAnimScript::CalculateSubObjectIndices() {
    M2C_UNK var_r24_2935;
    MKAnim *temp_r29_2922;
    MKAnim *temp_r3_2934;
    MKAnimScriptedEvent *var_r26_2927;
    s16 temp_r29_2930;
    s32 var_r25_2931;
    s32 var_r27_2912;
    s32 var_r30_2913;
    u16 temp_r28_2915;

    if ((MKModel *) this->unk8 != NULL) {
        var_r27_2912 = 0;
        var_r30_2913 = 0;
        temp_r28_2915 = M2C_FIELD(M2C_FIELD(this->unk4, void **, 0x34), u16 *, 8);
loop_12:
        if (var_r27_2912 < (s32) temp_r28_2915) {
            temp_r29_2922 = M2C_FIELD(this->unk4, void **, 0x34) + (var_r30_2913 + 0x10);
            var_r26_2927 = temp_r29_2922->GetFirstEvent((MKAnimScriptedEvent::EventType) 2);
            temp_r29_2930 = temp_r29_2922->GetNumberOfEvents((MKAnimScriptedEvent::EventType) 2);
            var_r25_2931 = 0;
loop_10:
            if (var_r25_2931 < temp_r29_2930) {
                temp_r3_2934 = var_r26_2927->unk0;
                var_r24_2935 = 0;
                if (temp_r3_2934 != NULL) {
                    if (strnicmp(&temp_r3_2934->unk0, "p_", 2) == 0) {
                        var_r24_2935 = 2;
                    } else if (strnicmp(&var_r26_2927->unk0->unk0, "s_", 2) == 0) {
                        var_r24_2935 = 1;
                    }
                    MKModel_SubObjectExists(this->unk8, (SubObjectType) var_r24_2935, &var_r26_2927->unk0->unk0, &var_r26_2927->unk8);
                }
                var_r26_2927 += 0x10;
                var_r25_2931 += 1;
                goto loop_10;
            }
            var_r27_2912 += 1;
            var_r30_2913 += 0x30;
            goto loop_12;
        }
    }
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
MKAnimScript::MKAnimScript() {
    this->unk4 = NULL;
    return this;
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class
s16 MKAnim::GetNumberOfEvents(MKAnimScriptedEvent::EventType arg1) {
    if ((s32) arg1 != 1) {
        if ((s32) arg1 < 1) {
            if ((s32) arg1 < 0) {
                /* Duplicate return node #11. Try simplifying control flow for better match */
                return 0;
            }
            return this->unkE;
        }
        if ((s32) arg1 != 6) {
            if ((s32) arg1 < 6) {
                return this->unk1C;
            }
            return 0;
        }
        return this->unk24;
    }
    return this->unk14;
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class
MKAnimScriptedEvent *MKAnim::GetFirstEvent(MKAnimScriptedEvent::EventType arg1) {
    if ((s32) arg1 != 1) {
        if ((s32) arg1 < 1) {
            if ((s32) arg1 < 0) {
                /* Duplicate return node #11. Try simplifying control flow for better match */
                return NULL;
            }
            return this->unk10;
        }
        if ((s32) arg1 != 6) {
            if ((s32) arg1 < 6) {
                return this->unk20;
            }
            return NULL;
        }
        return this->unk28;
    }
    return this->unk18;
}
#endif

#if 0 // DRAFT: function call 'strlen(signed char *)' does not match
MKResource *ParseBadFile(MKIni *arg0, const char *arg1, MKModel *arg2) {
    s8 sp90;
    f32 sp70;
    f32 sp50;
    MKAnimScriptedEvent sp40;
    MKAnimScriptedEvent sp30;
    s8 *sp2C;
    s8 *sp28;
    f32 sp24;
    f32 sp20;
    s8 *sp1C;
    s8 *sp18;
    s8 *sp14;
    s8 *sp10;
    s8 *spC;
    s8 *sp8;
    MKAnim *var_r30_3261;
    MKAnimScriptedEvent *temp_r22_3650;
    MKAnimScriptedEvent *temp_r22_3723;
    MKAnimScriptedEvent *var_r24_3260;
    MKAnimScriptedEvent *var_r25_3254;
    MKAnimScriptedEvent *var_r27_3256;
    MKAnimScriptedEvent *var_r28_3258;
    MKHeap *temp_r3_3226;
    MKIniLine *var_r25_3070;
    MKIniLine *var_r26_3268;
    MKResource *var_r23_3234;
    s16 var_r23_3616;
    s16 var_r23_3689;
    s32 temp_r3_3221;
    s32 temp_r3_3455;
    s32 temp_r3_3824;
    s32 temp_ret_3435;
    s32 var_r23_3068;
    s32 var_r26_3062;
    s32 var_r27_3063;
    s32 var_r28_3064;
    s32 var_r29_3065;
    s32 var_r30_3066;
    s32 var_r31_3067;
    s8 *temp_r29_3262;
    s8 *temp_r3_3305;
    s8 *temp_r3_3346;
    s8 *var_r23_3433;
    u16 temp_r5_3277;
    u16 temp_r6_3386;
    u32 temp_r25_3225;
    u32 temp_r3_3435;
    void *temp_r3_3523;
    void *temp_r3_3543;
    void *temp_r3_3563;
    void *temp_r3_3583;
    void *temp_r4_3826;
    void *temp_r6_3275;
    void *temp_r7_3383;

    var_r26_3062 = 0;
    var_r27_3063 = 0;
    var_r28_3064 = 0;
    var_r29_3065 = 0;
    var_r30_3066 = 0;
    var_r31_3067 = 0;
    var_r23_3068 = 1;
    var_r25_3070 = arg0->GotoLine(NULL, NULL);
loop_28:
    if (var_r25_3070 != NULL) {
        if (var_r25_3070->GetSectionName() != NULL) {
            var_r26_3062 += 1;
            var_r23_3068 = strlen(var_r25_3070->GetSectionName()) + var_r23_3068 + 1;
        } else if (var_r25_3070->GetFieldName() != NULL) {
            if (var_r25_3070->IsField("mesh") != 0) {
                var_r23_3068 = strlen(var_r25_3070->GetString(0)) + var_r23_3068 + 1;
            } else if (var_r25_3070->IsField("skeleton") != 0) {
                var_r23_3068 = strlen(var_r25_3070->GetString(0)) + var_r23_3068 + 1;
            } else if (var_r25_3070->IsField("anim") != 0) {
                var_r26_3062 += 1;
                var_r23_3068 = strlen(var_r25_3070->GetString(0)) + var_r23_3068 + 1;
            } else if (var_r25_3070->IsField("event") != 0) {
                var_r23_3068 += sp40.GetStringSizeOfEvent(var_r25_3070);
                switch (sp40.unk4) {                /* switch 1; irregular */
                case 0:                             /* switch 1 */
                    var_r27_3063 += 1;
                    break;
                case 1:                             /* switch 1 */
                    var_r28_3064 += 1;
                    break;
                default:                            /* switch 1 */
                    var_r29_3065 += 1;
                    break;
                case 6:                             /* switch 1 */
                    var_r30_3066 += 1;
                    break;
                }
                var_r31_3067 += 1;
            } else if (var_r25_3070->IsField("soundevent") != 0) {
                sp2C = NULL;
                var_r25_3070->AsString(0, &sp2C);
                var_r28_3064 += 1;
                var_r23_3068 = strlen(sp2C) + var_r23_3068 + 1;
                var_r31_3067 += 1;
            } else if (var_r25_3070->IsField("subobjectevent") != 0) {
                sp28 = NULL;
                var_r25_3070->AsString(0, &sp28);
                var_r29_3065 += 1;
                var_r23_3068 = strlen(sp28) + var_r23_3068 + 1;
                var_r31_3067 += 1;
            }
        }
        var_r25_3070 = var_r25_3070->unkC->GetNextLine(var_r25_3070);
        goto loop_28;
    }
    temp_r3_3221 = var_r26_3062 * 0x30;
    temp_r25_3225 = temp_r3_3221 + (var_r31_3067 * 0x10) + var_r23_3068 + 0x10;
    temp_r3_3226 = ((MKHeap *) temp_r3_3221)->Current();
    if (temp_r3_3226 != NULL) {
        var_r23_3234 = ((MKHeap *) (temp_r3_3226->Current()))->Alloc(temp_r25_3225 + 0x38, NULL, 0);
    } else {
        var_r23_3234 = malloc(temp_r25_3225 + 0x38);
    }
    M2C_FIELD(var_r23_3234, void **, 0x34) = (void *) (var_r23_3234 + 0x38);
    memset(M2C_FIELD(var_r23_3234, void **, 0x34), 0, temp_r25_3225);
    var_r25_3254 = M2C_FIELD(var_r23_3234, void **, 0x34) + ((var_r26_3062 * 0x30) + 0x10);
    var_r27_3256 = var_r25_3254 + (var_r27_3063 * 0x10);
    var_r28_3258 = var_r27_3256 + (var_r28_3064 * 0x10);
    var_r24_3260 = var_r28_3258 + (var_r29_3065 * 0x10);
    var_r30_3261 = NULL;
    temp_r29_3262 = var_r24_3260 + (var_r30_3066 * 0x10);
    M2C_FIELD(temp_r29_3262, s8 *, 1) = 0;
    M2C_FIELD(temp_r29_3262, s8 *, 0) = 0;
    var_r26_3268 = arg0->GotoLine(NULL, NULL);
loop_99:
    if (var_r26_3268 != NULL) {
        if (var_r26_3268->GetSectionName() != NULL) {
            temp_r6_3275 = M2C_FIELD(var_r23_3234, void **, 0x34);
            temp_r5_3277 = M2C_FIELD(temp_r6_3275, u16 *, 8);
            M2C_FIELD(temp_r6_3275, u16 *, 8) = (u16) (temp_r5_3277 + 1);
            var_r30_3261 = ((u8 *) temp_r6_3275) + ((temp_r5_3277 * 0x30) + 0x10);
            *var_r30_3261 = AddToStringTable(temp_r29_3262, var_r26_3268->GetSectionName());
        } else if (var_r26_3268->GetFieldName() != NULL) {
            if (var_r26_3268->IsField("mesh") != 0) {
                var_r26_3268->GetString(0);
                temp_r3_3305 = strrchr(0x2E);
                if ((temp_r3_3305 != NULL) && ((strcmpi".ase" == 0) || (strcmpi(temp_r3_3305, ".mdl") != 0))) {
                    *temp_r3_3305 = 0;
                }
                M2C_FIELD(M2C_FIELD(var_r23_3234, void **, 0x34), MKAnim **, 0) = AddToStringTable(temp_r29_3262, var_r26_3268->GetString(0));
            } else if (var_r26_3268->IsField("skeleton") != 0) {
                var_r26_3268->GetString(0);
                temp_r3_3346 = strrchr(0x2E);
                if ((temp_r3_3346 != NULL) && ((strcmpi".ase" == 0) || (strcmpi(temp_r3_3346, ".anm") != 0))) {
                    *temp_r3_3346 = 0;
                }
                M2C_FIELD(M2C_FIELD(var_r23_3234, void **, 0x34), MKAnim **, 4) = AddToStringTable(temp_r29_3262, var_r26_3268->GetString(0));
            } else if (var_r26_3268->IsField("anim") != 0) {
                temp_r7_3383 = M2C_FIELD(var_r23_3234, void **, 0x34);
                temp_r6_3386 = M2C_FIELD(temp_r7_3383, u16 *, 8);
                M2C_FIELD(temp_r7_3383, u16 *, 8) = (u16) (temp_r6_3386 + 1);
                var_r30_3261 = ((u8 *) temp_r7_3383) + ((temp_r6_3386 * 0x30) + 0x10);
                M2C_FIELD(var_r30_3261, MKAnim **, 0) = AddToStringTable(temp_r29_3262, var_r26_3268->GetString(0));
                var_r30_3261->unk8 = 0;
                var_r30_3261->unk4 = 0;
                var_r30_3261->unk6 = 0;
                var_r30_3261->unkE = 0;
                var_r30_3261->unk14 = 0;
                var_r30_3261->unk1C = 0;
                var_r30_3261->unk24 = 0;
                var_r30_3261->unk10 = var_r25_3254;
                var_r30_3261->unk18 = var_r27_3256;
                var_r30_3261->unk20 = var_r28_3258;
                var_r30_3261->unk28 = var_r24_3260;
                var_r30_3261->unk2C = 0;
                var_r30_3261->unkC = -1;
                var_r30_3261->unkA = -1;
            } else if (((s8) *var_r26_3268->GetFieldName() >= 0x30) && ((s8) *var_r26_3268->GetFieldName() <= 0x39)) {
                sp90 = 0;
                var_r23_3433 = var_r26_3268->GetFieldName();
                temp_ret_3435 = var_r26_3268->GetString(0);
                temp_r3_3435 = temp_ret_3435;
                if (temp_r3_3435 != 0U) {
                    var_r23_3433 = Str_Printf("%s%s", var_r23_3433, temp_r3_3435, "MKSound", M2C_BITWISE(f32, temp_ret_3435));
                }
                temp_r3_3455 = sscanf(var_r23_3433, "%d-%d,%s", &sp24, &sp20, &sp90);
                switch (temp_r3_3455) {             /* switch 2; irregular */
                case 0:                             /* switch 2 */
                    sp20 = 0.0f;
                    sp24 = 0.0f;
                    break;
                case 1:                             /* switch 2 */
                    sscanf(var_r23_3433, "%d,%s", &sp24, (f32 *) &sp90);
                    sp20 = sp24;
                    break;
                }
                var_r30_3261->unkA = M2C_BITWISE(s16, sp24);
                var_r30_3261->unkC = M2C_BITWISE(s16, sp20);
                var_r30_3261->unk4 = (var_r30_3261->unk4 + M2C_BITWISE(s32, sp20)) - M2C_BITWISE(s32, sp24);
            } else if (var_r26_3268->IsField("event") != 0) {
                *MKAnimScriptedEvent::pSrcAnim = var_r30_3261;
                if (sp30.ParseEvent(var_r26_3268, temp_r29_3262) != 0) {
                    switch (sp30.unk4) {            /* switch 3; irregular */
                    case 0:                         /* switch 3 */
                        var_r25_3254 += 0x10;
                        temp_r3_3523 = var_r30_3261->unk10 + (var_r30_3261->unkE * 0x10);
                        M2C_FIELD(temp_r3_3523, s32 *, 0) = (s32) sp30;
                        M2C_FIELD(temp_r3_3523, s16 *, 4) = sp30.unk4;
                        M2C_FIELD(temp_r3_3523, s16 *, 6) = sp30.unk6;
                        M2C_FIELD(temp_r3_3523, s32 *, 8) = sp30.unk8;
                        M2C_FIELD(temp_r3_3523, s32 *, 0xC) = sp30.unkC;
                        var_r30_3261->unkE += 1;
                        break;
                    case 1:                         /* switch 3 */
                        var_r27_3256 += 0x10;
                        temp_r3_3543 = var_r30_3261->unk18 + (var_r30_3261->unk14 * 0x10);
                        M2C_FIELD(temp_r3_3543, s32 *, 0) = (s32) sp30;
                        M2C_FIELD(temp_r3_3543, s16 *, 4) = sp30.unk4;
                        M2C_FIELD(temp_r3_3543, s16 *, 6) = sp30.unk6;
                        M2C_FIELD(temp_r3_3543, s32 *, 8) = sp30.unk8;
                        M2C_FIELD(temp_r3_3543, s32 *, 0xC) = sp30.unkC;
                        var_r30_3261->unk14 += 1;
                        break;
                    default:                        /* switch 3 */
                        var_r28_3258 += 0x10;
                        temp_r3_3563 = var_r30_3261->unk20 + (var_r30_3261->unk1C * 0x10);
                        M2C_FIELD(temp_r3_3563, s32 *, 0) = (s32) sp30;
                        M2C_FIELD(temp_r3_3563, s16 *, 4) = sp30.unk4;
                        M2C_FIELD(temp_r3_3563, s16 *, 6) = sp30.unk6;
                        M2C_FIELD(temp_r3_3563, s32 *, 8) = sp30.unk8;
                        M2C_FIELD(temp_r3_3563, s32 *, 0xC) = sp30.unkC;
                        var_r30_3261->unk1C += 1;
                        break;
                    case 6:                         /* switch 3 */
                        var_r24_3260 += 0x10;
                        temp_r3_3583 = var_r30_3261->unk28 + (var_r30_3261->unk24 * 0x10);
                        M2C_FIELD(temp_r3_3583, s32 *, 0) = (s32) sp30;
                        M2C_FIELD(temp_r3_3583, s16 *, 4) = sp30.unk4;
                        M2C_FIELD(temp_r3_3583, s16 *, 6) = sp30.unk6;
                        M2C_FIELD(temp_r3_3583, s32 *, 8) = sp30.unk8;
                        M2C_FIELD(temp_r3_3583, s32 *, 0xC) = sp30.unkC;
                        var_r30_3261->unk24 += 1;
                        break;
                    }
                }
            } else if (var_r26_3268->IsField("soundevent") != 0) {
                sp1C = NULL;
                var_r26_3268->AsString(0, &sp1C);
                var_r23_3616 = GetFrameOrProportion(var_r26_3268, 1, var_r30_3261);
                sp18 = NULL;
                var_r26_3268->AsString(1, &sp18);
                sscanf(sp18, "%s", &sp70);
                if (stricmp(*MKAnimScriptedEvent::pOnExitKeyWord, (s8 *) &sp70) == 0) {
                    var_r23_3616 = -1;
                } else if (stricmp(*MKAnimScriptedEvent::pOnEnterKeyWord, (s8 *) &sp70) == 0) {
                    var_r23_3616 = -2;
                }
                temp_r22_3650 = &var_r30_3261->unk18[var_r30_3261->unk14];
                temp_r22_3650->unk4 = 1;
                temp_r22_3650->unk6 = var_r23_3616;
                temp_r22_3650->unkC = (s32) var_r23_3616;
                temp_r22_3650->unk8 = -1;
                temp_r22_3650->unk0 = AddToStringTable(temp_r29_3262, sp1C);
                var_r27_3256 += 0x10;
                var_r30_3261->unk14 += 1;
            } else if (var_r26_3268->IsField("subobjectevent") != 0) {
                sp14 = NULL;
                var_r26_3268->AsString(0, &sp14);
                sp10 = NULL;
                var_r26_3268->AsString(1, &sp10);
                var_r23_3689 = GetFrameOrProportion(var_r26_3268, 2, var_r30_3261);
                spC = NULL;
                var_r26_3268->AsString(2, &spC);
                sscanf(spC, "%s", &sp50);
                if (stricmp(*MKAnimScriptedEvent::pOnExitKeyWord, (s8 *) &sp50) == 0) {
                    var_r23_3689 = -1;
                } else if (stricmp(*MKAnimScriptedEvent::pOnEnterKeyWord, (s8 *) &sp50) == 0) {
                    var_r23_3689 = -2;
                }
                temp_r22_3723 = &var_r30_3261->unk20[var_r30_3261->unk1C];
                temp_r22_3723->unk6 = var_r23_3689;
                temp_r22_3723->unkC = 0;
                temp_r22_3723->unk8 = -1;
                if (stricmp((MKAnim *) sp14, "enable", 0) == 0) {
                    temp_r22_3723->unk4 = 2;
                } else if (stricmp((MKAnim *) sp14, "disable") == 0) {
                    temp_r22_3723->unk4 = 3;
                }
                temp_r22_3723->unk0 = AddToStringTable(temp_r29_3262, sp10);
                var_r28_3258 += 0x10;
                var_r30_3261->unk1C += 1;
            } else if (var_r26_3268->IsField("cycle") != 0) {
                sp8 = "";
                var_r26_3268->AsString(0, &sp8);
                if (strcmpi(sp8, "loop") == 0) {
                    var_r30_3261->unk8 = 1;
                } else if (strcmpi(sp8, "rebound") == 0) {
                    var_r30_3261->unk8 = 2;
                } else if (strcmpi(sp8, "stop") == 0) {
                    var_r30_3261->unk8 = 0;
                } else {
                    var_r30_3261->unk8 = 0;
                }
            }
        }
        var_r26_3268 = var_r26_3268->unkC->GetNextLine(var_r26_3268);
        goto loop_99;
    }
    var_r23_3234->unk28 = temp_r29_3262 - M2C_FIELD(var_r23_3234, void **, 0x34);
loop_102:
    temp_r3_3824 = var_r23_3234->unk28;
    temp_r4_3826 = temp_r3_3824 + M2C_FIELD(var_r23_3234, void **, 0x34);
    if ((s8) M2C_FIELD(temp_r4_3826, u8 *, 0) != 0) {
block_101:
        var_r23_3234->unk28 += 1;
        goto loop_102;
    }
    if ((s8) M2C_FIELD(temp_r4_3826, u8 *, 1) != 0) {
        goto block_101;
    }
    var_r23_3234->unk28 = temp_r3_3824 + 2;
    return var_r23_3234;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'char *' to
MKAnim *AddToStringTable(char *arg0, const char *arg1) {
    s32 temp_r3_3858;
    s8 *var_r28_3851;
    u32 temp_r30_3854;

    var_r28_3851 = arg0;
    temp_r30_3854 = strlen(arg1);
loop_5:
    if ((s8) (u8) *var_r28_3851 == 0) {
        strcpy(var_r28_3851, arg1);
        M2C_FIELD(&var_r28_3851[temp_r30_3854], s8 *, 1) = 0;
        return (MKAnim *) var_r28_3851;
    }
    temp_r3_3858 = strlen(var_r28_3851);
    if ((temp_r3_3858 == (s32) temp_r30_3854) && (strcmpi(var_r28_3851, arg1) == 0)) {
        return (MKAnim *) var_r28_3851;
    }
    var_r28_3851 = &var_r28_3851[temp_r3_3858] + 1;
    goto loop_5;
}
#endif

#if 0 // DRAFT: type mismatch
void MKAnimScript_DeinitModule() {
    MKHeap *temp_r3_3908;
    MKResource **temp_r31_3900;
    MKResource **temp_r3_3899;

    do {
        temp_r3_3899 = mkAnimScriptTemplates;
        temp_r31_3900 = temp_r3_3899 - 4;
        mkAnimScriptTemplates = temp_r31_3900;
    } while ((u32) M2C_FIELD(temp_r3_3899, u32 *, -4) != 0U);
    if (temp_r31_3900 != &gEmptyPtrList) {
        temp_r3_3908 = ((MKHeap *) temp_r3_3899)->Current();
        if (temp_r3_3908 != NULL) {
            ((MKHeap *) (temp_r3_3908->Current()))->Free(temp_r31_3900, NULL, 0);
        } else {
            free((MKResource *) temp_r31_3900);
        }
    }
    mkAnimScriptTemplates = NULL;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void MKAnimScript_InitModule() {
    MKHeap *temp_r3_3936;
    MKResource *var_r3_3943;
    s32 var_ctr_3955;

    temp_r3_3936 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_3936 != NULL) {
        var_r3_3943 = ((MKHeap *) (temp_r3_3936->Current()))->Alloc(0x408, NULL, 0);
    } else {
        var_r3_3943 = malloc(0x408);
    }
    mkAnimScriptTemplates = (MKResource **) var_r3_3943;
    *var_r3_3943 = 0;
    var_ctr_3955 = 0x100;
    do {
        mkAnimScriptTemplates += 4;
        M2C_FIELD(mkAnimScriptTemplates, s32 *, 4) = 0xDEADBEEF;
        var_ctr_3955 -= 1;
    } while (var_ctr_3955 != 0);
    mkAnimScriptTemplates += 4;
    M2C_FIELD(mkAnimScriptTemplates, s32 *, 4) = 0;
}
#endif

#if 0 // DRAFT: function call 'strchr(long, int)' does not match
s16 GetFrameOrProportion(MKIniLine *arg0, int arg1, MKAnim *arg2) {
    s16 temp_r31_3993;

    if ((arg0->GetString(arg1) != 0U) && (strchr(arg0->GetString(arg1), 0x2E) != NULL)) {
        temp_r31_3993 = arg2->unkA;
        return temp_r31_3993 + (s32) (arg0->GetFloat(arg1) * (f32) (arg2->unkC - temp_r31_3993));
    }
    return arg0->GetInt(arg1);
}
#endif
