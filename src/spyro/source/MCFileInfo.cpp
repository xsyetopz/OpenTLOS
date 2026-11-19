#include "spyro/source/MCFileInfo.h"
#include "common/Source/MKMemoryCard.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Level.h"
#include "spyro/source/MemoryCard.h"
#include "spyro/source/UIAttributes.h"
#include "spyro/source/UIContainer.h"
#include "spyro/source/UIMessage.h"
#include "spyro/source/UIObject.h"
#include "spyro/source/UIText.h"
#include "unplaced_templates.h"
#include "common/Source/Str.h"
#include "spyro/source/Hud.h"
#include "spyro/source/Tools.h"
#include "spyro/source/UIStringTable.h"
#include <m2c_macros.h>

s32 stricmp(void *, void *);                        /* extern */
extern void *gpTranslation_StringArray;

void MCFileInfo::Draw(const RenderContext &arg0) {
    RenderContext sp10;
    f32 temp_f25_74;
    f32 temp_f26_72;
    f32 temp_f27_48;
    f32 temp_f28_47;
    f32 temp_f31_140;
    f32 temp_f31_174;
    f32 var_f29_44;
    f32 var_f30_40;
    s32 temp_r0_41;
    s32 temp_r0_58;
    s32 temp_r3_39;

    UIContainer::Draw(arg0);
    sp10.RenderContext(arg0, this->unk18);
    temp_r3_39 = this->unk18.unk3C;
    var_f30_40 = 0.0f;
    temp_r0_41 = temp_r3_39 & 3;
    var_f29_44 = 0.0f;
    temp_f28_47 = this->unk18.unk34 - 6.0f;
    temp_f27_48 = this->unk18.unk38 - 6.0f;
    if (temp_r0_41 == 1) {
        var_f30_40 = -((0.5f * temp_f28_47) - 0.0f);
    } else if (temp_r0_41 == 2) {
        var_f30_40 = 0.0f - temp_f28_47;
    }
    temp_r0_58 = temp_r3_39 & 0xC;
    if (temp_r0_58 == 4) {
        var_f29_44 = -((0.5f * temp_f27_48) - 0.0f);
    } else if (temp_r0_58 == 8) {
        var_f29_44 = 0.0f - temp_f27_48;
    }
    temp_f26_72 = var_f30_40 + temp_f28_47;
    temp_f25_74 = var_f29_44 + temp_f27_48;
    Hud_DrawIcon(0, 4, var_f30_40 - 2.0f, var_f29_44 - 2.0f, 6.0f, 6.0f, *((MKVector4 *) &sp10.unk40), 0.0f, 0.0f, 1.0f, 1.0f, 0U, 0U, *((Matrix *) &sp10));
    Hud_DrawIcon(0, 5, temp_f26_72 + 2.0f, var_f29_44 - 2.0f, 6.0f, 6.0f, *((MKVector4 *) &sp10.unk40), 0.0f, 0.0f, 1.0f, 1.0f, 0U, 0U, *((Matrix *) &sp10));
    Hud_DrawIcon(0, 6, temp_f26_72 + 2.0f, temp_f25_74 + 2.0f, 6.0f, 6.0f, *((MKVector4 *) &sp10.unk40), 0.0f, 0.0f, 1.0f, 1.0f, 0U, 0U, *((Matrix *) &sp10));
    Hud_DrawIcon(0, 7, var_f30_40 - 2.0f, temp_f25_74 + 2.0f, 6.0f, 6.0f, *((MKVector4 *) &sp10.unk40), 0.0f, 0.0f, 1.0f, 1.0f, 0U, 0U, *((Matrix *) &sp10));
    temp_f31_140 = (0.5f * temp_f28_47) + var_f30_40;
    Hud_DrawIcon(0, 9, temp_f31_140, var_f29_44 - 2.0f, temp_f28_47, 6.0f, *((MKVector4 *) &sp10.unk40), 0.0f, 0.0f, 1.0f, 1.0f, 0U, 0U, *((Matrix *) &sp10));
    Hud_DrawIcon(0, 0xA, temp_f31_140, temp_f25_74 + 2.0f, temp_f28_47, 6.0f, *((MKVector4 *) &sp10.unk40), 0.0f, 0.0f, 1.0f, 1.0f, 0U, 0U, *((Matrix *) &sp10));
    temp_f31_174 = (0.5f * temp_f27_48) + var_f29_44;
    Hud_DrawIcon(0, 0xB, var_f30_40 - 2.0f, temp_f31_174, 6.0f, temp_f27_48, *((MKVector4 *) &sp10.unk40), 0.0f, 0.0f, 1.0f, 1.0f, 0U, 0U, *((Matrix *) &sp10));
    Hud_DrawIcon(0, 0xC, temp_f26_72 + 2.0f, temp_f31_174, 6.0f, temp_f27_48, *((MKVector4 *) &sp10.unk40), 0.0f, 0.0f, 1.0f, 1.0f, 0U, 0U, *((Matrix *) &sp10));
}

void MCFileInfo::Message(UIMessage *arg0) {
    if ((s32) arg0->unk0 == 1) {
        Reset();
    }
    UIContainer::Message(arg0);
}

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void MCFileInfo::Reset() {
    s32 sp10;
    s32 spC;
    s32 sp8;
    TimerInfo *temp_r4_274;
    UIObject *var_r28_463;
    UIObject *var_r30_340;
    f32 temp_f31_431;
    s32 temp_r30_288;
    s32 temp_ret_412;
    s32 temp_ret_506;
    s32 var_r3_364;
    s32 var_r3_532;
    s8 *temp_r3_298;
    s8 *temp_r3_310;
    s8 *temp_r3_321;
    u32 temp_r29_515;
    u32 temp_r3_434;
    u8 temp_r3_381;
    u8 var_r29_344;
    u8 var_r31_467;
    void *temp_r30_282;
    void *temp_r30_297;
    void *temp_r30_309;
    void *temp_r3_331;
    void *var_r30_403;
    void *var_r4_518;
    void *var_r7_456;

    if (((void *) *MemoryCardScreen::selectedCard != NULL) && ((u8) M2C_FIELD(*MemoryCardScreen::selectedCard, u8 *, 9) != 0)) {
        if ((u8) M2C_FIELD(*MemoryCardScreen::selectedCard, u8 *, 8) != 0) {
            return;
        }
        temp_r4_274 = *MemoryCardScreen::selectedCard + ((this->unk218 * 0xC0) + 0x40);
        if (((s8) M2C_FIELD(temp_r4_274, u8 *, 0xA5) != 0) || ((s8) M2C_FIELD(temp_r4_274, u8 *, 0xA4) == 0)) {
            temp_r30_282 = this->unk70;
            if (temp_r30_282 != NULL) {
                if ((s8) M2C_FIELD(temp_r4_274, u8 *, 0xA4) == 0) {
                    temp_r30_288 = M2C_FIELD(*MemoryCardScreen::selectedCard, s32 *, 0x18);
                    if ((temp_r30_288 < MemoryCard_GetSaveGameBlockSize()) || ((s32) M2C_FIELD(*MemoryCardScreen::selectedCard, s32 *, 0x14) < 1)) {
                        temp_r30_297 = this->unk70;
                        temp_r3_298 = M2C_FIELD(temp_r30_297, s8 **, 0x68);
                        if (temp_r3_298 != NULL) {
                            UIStringTable_Remove(temp_r3_298);
                        }
                        M2C_FIELD(temp_r30_297, s8 **, 0x68) = NULL;
                        M2C_FIELD(temp_r30_297, s32 *, 0x6C) = 0x4A;
                    } else {
                        temp_r30_309 = this->unk70;
                        temp_r3_310 = M2C_FIELD(temp_r30_309, s8 **, 0x68);
                        if (temp_r3_310 != NULL) {
                            UIStringTable_Remove(temp_r3_310);
                        }
                        M2C_FIELD(temp_r30_309, s8 **, 0x68) = NULL;
                        M2C_FIELD(temp_r30_309, s32 *, 0x6C) = 0x42;
                    }
                } else {
                    temp_r3_321 = M2C_FIELD(temp_r30_282, s8 **, 0x68);
                    if (temp_r3_321 != NULL) {
                        UIStringTable_Remove(temp_r3_321);
                    }
                    M2C_FIELD(temp_r30_282, s8 **, 0x68) = NULL;
                    M2C_FIELD(temp_r30_282, s32 *, 0x6C) = 0x4B;
                }
                temp_r3_331 = this->unk70;
                sp10 = 2;
                M2C_FIELD(M2C_FIELD(temp_r3_331, void **, 0), M2C_UNK (**)(void *, s32 *), 0x2C)(temp_r3_331, &sp10);
            }
            var_r30_340 = this->unk60;
loop_28:
            if (var_r30_340 != NULL) {
                var_r29_344 = 0;
                if (((u32) var_r30_340->unk4 == 0) || (stricmp"background" == 0) || (stricmp((void *) var_r30_340->unk4, "message") == 0)) {
                    var_r29_344 = 1;
                }
                var_r3_364 = 3;
                if (var_r29_344 != 0) {
                    var_r3_364 = 2;
                }
                spC = var_r3_364;
                var_r30_340->Message(&spC);
                var_r30_340 = var_r30_340->unk10;
                goto loop_28;
            }
            return;
        }
        temp_r3_381 = M2C_FIELD(temp_r4_274, u8 *, 0x20);
        if (((s8) temp_r3_381 > 0) && (((s8) temp_r3_381 < 0x20) || ((s8) temp_r3_381 > 0x7A))) {
            M2C_FIELD(temp_r4_274, u8 *, 0xA5) = 1U;
            Reset();
            return;
        }
        Tools_GetDateString(temp_r4_274);
        strcpy(&this->unk178, M2C_ERROR(/* Read from unset register $r3 */));
        var_r30_403 = NULL;
        this->unk78 = 0;
        if ((s8) M2C_FIELD(temp_r4_274, u8 *, 0x20) != 0) {
            temp_ret_412 = stricmp(temp_r4_274 + 0x20, "swamp_07");
            if (temp_ret_412 == 0) {
                strcpy(&this->unk78, M2C_FIELD(gpTranslation_StringArray, s8 **, 0x38));
            } else {
                var_r30_403 = M2C_FIELD(((Level *) (temp_r4_274 + 0x20))->GetChunkByName((s8 *) (u32) (u64) temp_ret_412), void **, 4);
                strcpy(&this->unk78, *(gpTranslation_StringArray + (M2C_FIELD(var_r30_403, s32 *, 0x10) * 4)));
            }
        }
        temp_f31_431 = M2C_FIELD(temp_r4_274, f32 *, 0x1C);
        temp_r3_434 = (u32) (temp_f31_431 / 3600.0f);
        if ((s32) M2C_FIELD(temp_r4_274, s32 *, 0x3C) != 0) {
            var_r7_456 = M2C_FIELD(gpTranslation_StringArray, void **, 0x54);
        } else {
            var_r7_456 = "";
        }
        sprintf(&this->unk1B8, "%dh %dm   %s", temp_r3_434, (u32) (temp_f31_431 - (f32) (temp_r3_434 * 0xE10)) / 60U, var_r7_456);
        var_r28_463 = this->unk60;
loop_60:
        if (var_r28_463 != NULL) {
            var_r31_467 = 0;
            if ((u32) var_r28_463->unk4 == 0) {
                var_r31_467 = 1;
            } else if (stricmp"percent" == 0) {
                var_r31_467 = 1;
            } else if (stricmp((void *) var_r28_463->unk4, "time") == 0) {
                var_r31_467 = 1;
            } else if (stricmp((void *) var_r28_463->unk4, "location") == 0) {
                var_r31_467 = 1;
            } else {
                temp_ret_506 = stricmp((void *) var_r28_463->unk4, "background");
                if (temp_ret_506 == 0) {
                    var_r31_467 = 1;
                } else {
                    temp_r29_515 = var_r28_463->unk4;
                    if (var_r30_403 != NULL) {
                        var_r4_518 = M2C_FIELD(var_r30_403, void **, 4);
                    } else {
                        var_r4_518 = "dojo";
                    }
                    Str_Printf("icon_%s", var_r4_518, M2C_BITWISE(f32, temp_ret_506));
                    if (stricmp((void *) temp_r29_515) == 0) {
                        var_r31_467 = 1;
                    }
                }
            }
            var_r3_532 = 3;
            if (var_r31_467 != 0) {
                var_r3_532 = 2;
            }
            sp8 = var_r3_532;
            var_r28_463->Message(&sp8);
            var_r28_463 = var_r28_463->unk10;
            goto loop_60;
        }
    }
}
#endif

#if 0 // DRAFT: pointer/array required
void MCFileInfo::Resolve() {
    s8 *temp_r3_629;
    s8 *temp_r3_646;
    s8 *temp_r3_663;
    u32 temp_r3_566;
    u32 var_r4_570;
    u8 temp_r3_591;
    void *temp_r30_626;
    void *temp_r30_643;
    void *temp_r30_660;

    UIContainer::Resolve();
    temp_r3_566 = this->unk4;
    this->unk218 = 0;
    var_r4_570 = temp_r3_566;
    if (temp_r3_566 != 0) {
loop_6:
        temp_r3_591 = *var_r4_570;
        if ((s8) temp_r3_591 != 0) {
            if (((s8) temp_r3_591 >= 0x30) && ((s8) temp_r3_591 <= 0x39)) {
                this->unk218 *= 0xA;
                this->unk218 = ((s8) *var_r4_570 + this->unk218) - 0x30;
            }
            var_r4_570 += 1;
            goto loop_6;
        }
    }
    this->unk218 -= 1;
    this->unk68 = ui_cast<UIText *, UIObject *>(FindChild("Percent"));
    this->unk6C = ui_cast<UIText *, UIObject *>(FindChild("Time"));
    this->unk74 = ui_cast<UIText *, UIObject *>(FindChild("Location"));
    this->unk70 = ui_cast<UIText *, UIObject *>(FindChild("Message"));
    temp_r30_626 = this->unk68;
    if (temp_r30_626 != NULL) {
        temp_r3_629 = M2C_FIELD(temp_r30_626, s8 **, 0x68);
        if (temp_r3_629 != NULL) {
            UIStringTable_Remove(temp_r3_629);
        }
        UIStringTable_Add(NULL);
        M2C_FIELD(temp_r30_626, s8 **, 0x68) = (s8 *) M2C_ERROR(/* Read from unset register $r3 */);
        M2C_FIELD(temp_r30_626, s32 *, 0x6C) = -1;
        M2C_FIELD(this->unk68, s8 **, 0x68) = &this->unk178;
    }
    temp_r30_643 = this->unk6C;
    if (temp_r30_643 != NULL) {
        temp_r3_646 = M2C_FIELD(temp_r30_643, s8 **, 0x68);
        if (temp_r3_646 != NULL) {
            UIStringTable_Remove(temp_r3_646);
        }
        UIStringTable_Add(NULL);
        M2C_FIELD(temp_r30_643, s8 **, 0x68) = (s8 *) M2C_ERROR(/* Read from unset register $r3 */);
        M2C_FIELD(temp_r30_643, s32 *, 0x6C) = -1;
        M2C_FIELD(this->unk6C, s8 **, 0x68) = &this->unk1B8;
    }
    temp_r30_660 = this->unk74;
    if (temp_r30_660 != NULL) {
        temp_r3_663 = M2C_FIELD(temp_r30_660, s8 **, 0x68);
        if (temp_r3_663 != NULL) {
            UIStringTable_Remove(temp_r3_663);
        }
        UIStringTable_Add(NULL);
        M2C_FIELD(temp_r30_660, s8 **, 0x68) = (s8 *) M2C_ERROR(/* Read from unset register $r3 */);
        M2C_FIELD(temp_r30_660, s32 *, 0x6C) = -1;
        M2C_FIELD(this->unk74, s8 **, 0x68) = &this->unk78;
    }
}
#endif

void MCFileInfo::Deinit() {
    void *temp_r4_690;
    void *temp_r4_696;
    void *temp_r4_702;

    temp_r4_690 = this->unk68;
    if (temp_r4_690 != NULL) {
        M2C_FIELD(temp_r4_690, s32 *, 0x68) = 0;
    }
    temp_r4_696 = this->unk6C;
    if (temp_r4_696 != NULL) {
        M2C_FIELD(temp_r4_696, s32 *, 0x68) = 0;
    }
    temp_r4_702 = this->unk74;
    if (temp_r4_702 != NULL) {
        M2C_FIELD(temp_r4_702, s32 *, 0x68) = 0;
    }
    UIContainer::Deinit();
}

void MCFileInfo::Init() {
    UIContainer::Init();
    this->unk218 = 0;
    this->unk178 = 0;
    this->unk1B8 = 0;
    this->unk78 = 0;
    this->unk68 = NULL;
    this->unk6C = NULL;
    this->unk74 = NULL;
    this->unk70 = NULL;
}
