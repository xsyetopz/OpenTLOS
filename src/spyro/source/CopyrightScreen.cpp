#include "spyro/source/CopyrightScreen.h"
#include "spyro/source/KDMemoryCard.h"
#include "spyro/source/UIContainer.h"
#include "spyro/source/UIScreen.h"
#include "spyro/source/UISystem.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKInput.h"
#include <m2c_macros.h>

s32 stricmp(void *, u32);                           /* extern */
extern f32 gUpdateTimeDelta;
extern M2C_UNK gb;

#if 0 // DRAFT: expression syntax error
void CopyrightScreen::Update() {
    s32 sp8;
    f32 temp_f0_109;
    f32 temp_f0_40;
    f32 temp_r3_129;
    s32 temp_r0_115;
    s32 temp_r0_21;
    s32 temp_r0_257;
    s32 temp_r3_141;
    s32 temp_r3_157;
    s32 temp_r3_179;
    s32 temp_r3_199;
    s32 temp_ret_123;
    u8 temp_r4_158;
    void **temp_r3_86;

    UIScreen::Update();
    temp_r0_21 = this->unkBC.unk4;
    switch (temp_r0_21) {                           /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        this->unkBC.unk8 = M2C_BITWISE(f32, this->unkBC.unk8) + (gUpdateTimeDelta / 0.25f);
        temp_f0_40 = M2C_BITWISE(f32, this->unkBC.unk8);
        if (temp_f0_40 < 1.0f) {
            this->unk18.unk0 = temp_f0_40;
            this->unk18.unk4 = temp_f0_40;
            M2C_FIELD(this, f32 *, 0x20) = temp_f0_40;
            M2C_FIELD(this, f32 *, 0x24) = 1.0f;
        } else {
            this->unk18.unk0 = 1.0f;
            this->unk18.unk4 = 1.0f;
            M2C_FIELD(this, f32 *, 0x20) = 1.0f;
            M2C_FIELD(this, f32 *, 0x24) = 1.0f;
            this->unkBC.unk4 = 1;
            this->unkBC.unk8 = 0.0f;
        }
        break;
    case 1:                                         /* switch 1 */
        this->unkBC.unk8 = M2C_BITWISE(f32, this->unkBC.unk8) + (gUpdateTimeDelta / 4.5f);
        if ((M2C_BITWISE(f32, this->unkBC.unk8) >= 1.0f) && ((u8) *CopyrightScreen::bMemoryCardCheckDone != 0)) {
            this->unkBC.unk4 = 2;
            this->unkBC.unk8 = 0.0f;
        }
        break;
    case 2:                                         /* switch 1 */
        if (M2C_BITWISE(f32, this->unkBC.unk8) >= 1.0f) {
            temp_r3_86 = ui_cast<UISystem *, UIContainer *>(GetRoot());
            sp8 = 0xF;
            M2C_FIELD(*temp_r3_86, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
        }
        this->unkBC.unk8 = M2C_BITWISE(f32, this->unkBC.unk8) + (gUpdateTimeDelta / 0.25f);
        if (M2C_BITWISE(f32, this->unkBC.unk8) > 1.0f) {
            this->unkBC.unk8 = 1.0f;
        }
        temp_f0_109 = 1.0f - M2C_BITWISE(f32, this->unkBC.unk8);
        this->unk18.unk0 = temp_f0_109;
        this->unk18.unk4 = temp_f0_109;
        M2C_FIELD(this, f32 *, 0x20) = temp_f0_109;
        M2C_FIELD(this, f32 *, 0x24) = 1.0f;
        break;
    }
    temp_r0_115 = this->unkC8;
    switch (temp_r0_115) {                          /* switch 2; irregular */
    case 1:                                         /* switch 2 */
        temp_ret_123 = ((KDMemoryCard *) (M2C_ERROR(/* Read from unset register $r3 */)))->Update();
        if (temp_ret_123 == 0) {
            this->unkCC = M2C_BITWISE(f32, (M2C_BITWISE(s32, this->unkCC) + 1));
            temp_r3_129 = this->unkCC;
            if (M2C_BITWISE(s32, temp_r3_129) < 2) {
                this->unkD0 = ((KDMemoryCard *) (M2C_BITWISE(KDMemoryCard *, temp_r3_129)))->GetCard((s32) (u32) (u64) temp_ret_123);
                this->unkD0->SetState((KDMCState) 2);
            } else {
                this->unkD0 = ((KDMemoryCard *) (M2C_BITWISE(KDMemoryCard *, temp_r3_129)))->GetFirstAvailable();
                temp_r3_141 = this->unkD0;
                if ((u32) temp_r3_141 != 0U) {
                    temp_r3_141->SetState((KDMCState) 3);
                    this->unkC8 = 2;
                } else {
                    this->unkC8 = 0;
                }
            }
        }
        break;
    case 2:                                         /* switch 2 */
        if (((KDMemoryCard *) (M2C_ERROR(/* Read from unset register $r3 */)))->Update() == 0) {
            temp_r3_157 = this->unkD0;
            temp_r4_158 = M2C_FIELD(temp_r3_157, u8 *, 9);
            if ((temp_r4_158 != 0) && ((u8) M2C_FIELD(temp_r3_157, u8 *, 8) != 0)) {
                temp_r3_157->SetState((KDMCState) 3);
            } else if ((temp_r4_158 == 0) || (((s32) M2C_FIELD(temp_r3_157, s32 *, 0x1C) != 0) && ((s32) M2C_FIELD(temp_r3_157, s32 *, 0x20) == 0))) {
                this->unkD0 = temp_r3_157->GetNextAvailable((KDMemoryCard *) temp_r4_158);
                temp_r3_179 = this->unkD0;
                if ((u32) temp_r3_179 != 0U) {
                    temp_r3_179->SetState((KDMCState) 3);
                }
            } else if ((s32) M2C_FIELD(temp_r3_157, s32 *, 0x24) != 0) {
                M2C_FIELD(&gb, s8 *, 0x382) = 1;
                this->unkD0 = 0;
            } else {
                this->unkD0 = temp_r3_157->GetNextAvailable((KDMemoryCard *) temp_r4_158);
                temp_r3_199 = this->unkD0;
                if ((u32) temp_r3_199 != 0U) {
                    temp_r3_199->SetState((KDMCState) 3);
                }
            }
            if ((u32) this->unkD0 == 0U) {
                this->unkC8 = 0;
            }
        }
        break;
    default:                                        /* switch 2 */
        *CopyrightScreen::bMemoryCardCheckDone = 1;
        break;
    }
    if (stricmp("VideoMaker", this->unk4) == 0) {
        this->unk18.unk40 |= 8;
        this->unk18.unk30 += gUpdateTimeDelta / 150.0f;
    }
    if (((stricmp("Developer", this->unk4) == 0) || (stricmp("VideoMaker", this->unk4) == 0)) && (MKInput_GetState(3, (MKInputDevices) 0, NULL, NULL) > 0.0f)) {
        temp_r0_257 = this->unkBC.unk4;
        switch (temp_r0_257) {                      /* switch 3; irregular */
        case 0:                                     /* switch 3 */
            this->unkBC.unk4 = 2;
            return;
        case 1:                                     /* switch 3 */
            this->unkBC.unk8 = 1.0f;
            break;
        }
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void CopyrightScreen::OnEnter() {
    UIScreen::OnEnter();
    this->unkBC.unk4 = 0;
    this->unkBC.unk8 = 0.0f;
    this->unk18.unk0 = 0.0f;
    this->unk18.unk4 = 0.0f;
    M2C_FIELD(this, f32 *, 0x20) = 0.0f;
    M2C_FIELD(this, f32 *, 0x24) = 1.0f;
    this->unk18.unk40 |= 1;
    if ((u8) *CopyrightScreen::bMemoryCardCheckDone == 0) {
        this->unkC8 = 1;
        this->unkCC = 0.0f;
        this->unkD0 = ((KDMemoryCard *) (M2C_BITWISE(KDMemoryCard *, this->unkCC)))->GetCard(M2C_ERROR(/* Read from unset register $r4 */));
        this->unkD0->SetState((KDMCState) 2);
    }
}
#endif
