#include "spyro/source/CopyrightScreen.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/KDMemoryCard.h"
#include "spyro/source/UIAttributes.h"
#include "spyro/source/UIContainer.h"
#include "spyro/source/UIMessage.h"
#include "spyro/source/UIObject.h"
#include "spyro/source/UIScreen.h"
#include "spyro/source/UISystem.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKInput.h"
#include <m2c_macros.h>

s32 stricmp(void *, u32);                           /* extern */
extern f32 gUpdateTimeDelta;
extern M2C_UNK gb;

#if 0 // DRAFT: type mismatch 'KDMemoryCard *' and 'int'
void CopyrightScreen::Update() {
    s32 sp8;
    KDMemoryCard *temp_r3_129;
    KDMemoryCard *temp_r3_141;
    KDMemoryCard *temp_r3_157;
    KDMemoryCard *temp_r3_179;
    KDMemoryCard *temp_r3_199;
    f32 temp_f0_109;
    f32 temp_f0_40;
    s32 temp_r0_115;
    s32 temp_r0_21;
    s32 temp_r0_257;
    u8 temp_r4_158;
    void **temp_r3_86;

    UIScreen::Update();
    temp_r0_21 = this->unkC8;
    switch (temp_r0_21) {                           /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        this->unkCC += gUpdateTimeDelta / 0.25f;
        temp_f0_40 = this->unkCC;
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
            this->unkC8 = 1;
            this->unkCC = 0.0f;
        }
        break;
    case 1:                                         /* switch 1 */
        this->unkCC += gUpdateTimeDelta / 4.5f;
        if ((this->unkCC >= 1.0f) && ((u8) *CopyrightScreen::bMemoryCardCheckDone != 0)) {
            this->unkC8 = 2;
            this->unkCC = 0.0f;
        }
        break;
    case 2:                                         /* switch 1 */
        if (this->unkCC >= 1.0f) {
            temp_r3_86 = (void **) (ui_cast<UISystem *, UIContainer *>(GetRoot()));
            sp8 = 0xF;
            M2C_FIELD(*temp_r3_86, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
        }
        this->unkCC += gUpdateTimeDelta / 0.25f;
        if (this->unkCC > 1.0f) {
            this->unkCC = 1.0f;
        }
        temp_f0_109 = 1.0f - this->unkCC;
        this->unk18.unk0 = temp_f0_109;
        this->unk18.unk4 = temp_f0_109;
        M2C_FIELD(this, f32 *, 0x20) = temp_f0_109;
        M2C_FIELD(this, f32 *, 0x24) = 1.0f;
        break;
    }
    temp_r0_115 = this->unkD0;
    switch (temp_r0_115) {                          /* switch 2; irregular */
    case 1:                                         /* switch 2 */
        if (KDMemoryCard::Update() == 0) {
            this->unkD4 += 1;
            temp_r3_129 = this->unkD4;
            if (temp_r3_129 < 2) {
                this->unkD8 = (KDMemoryCard *) (KDMemoryCard::GetCard((s32) temp_r3_129));
                this->unkD8->SetState((KDMCState) 2);
            } else {
                this->unkD8 = (KDMemoryCard *) (KDMemoryCard::GetFirstAvailable());
                temp_r3_141 = this->unkD8;
                if (temp_r3_141 != NULL) {
                    temp_r3_141->SetState((KDMCState) 3);
                    this->unkD0 = 2;
                } else {
                    this->unkD0 = 0;
                }
            }
        }
        break;
    case 2:                                         /* switch 2 */
        if (KDMemoryCard::Update() == 0) {
            temp_r3_157 = this->unkD8;
            temp_r4_158 = temp_r3_157->unk9;
            if ((temp_r4_158 != 0) && ((u8) temp_r3_157->unk8 != 0)) {
                temp_r3_157->SetState((KDMCState) 3);
            } else if ((temp_r4_158 == 0) || (((s32) temp_r3_157->unk1C != 0) && ((s32) temp_r3_157->unk20 == 0))) {
                this->unkD8 = (KDMemoryCard *) (KDMemoryCard::GetNextAvailable(temp_r3_157));
                temp_r3_179 = this->unkD8;
                if (temp_r3_179 != NULL) {
                    temp_r3_179->SetState((KDMCState) 3);
                }
            } else if ((s32) temp_r3_157->unk24 != 0) {
                M2C_FIELD(&gb, s8 *, 0x382) = 1;
                this->unkD8 = NULL;
            } else {
                this->unkD8 = (KDMemoryCard *) (KDMemoryCard::GetNextAvailable(temp_r3_157));
                temp_r3_199 = this->unkD8;
                if (temp_r3_199 != NULL) {
                    temp_r3_199->SetState((KDMCState) 3);
                }
            }
            if ((KDMemoryCard *) this->unkD8 == NULL) {
                this->unkD0 = 0;
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
        temp_r0_257 = this->unkC8;
        switch (temp_r0_257) {                      /* switch 3; irregular */
        case 0:                                     /* switch 3 */
            this->unkC8 = 2;
            return;
        case 1:                                     /* switch 3 */
            this->unkCC = 1.0f;
            break;
        }
    }
}
#endif

void CopyrightScreen::OnEnter() {
    UIScreen::OnEnter();
    this->unkC8 = 0;
    this->unkCC = 0.0f;
    this->unk18.unk0 = 0.0f;
    this->unk18.unk4 = 0.0f;
    M2C_FIELD(this, f32 *, 0x20) = 0.0f;
    M2C_FIELD(this, f32 *, 0x24) = 1.0f;
    this->unk18.unk40 |= 1;
    if ((u8) *CopyrightScreen::bMemoryCardCheckDone == 0) {
        this->unkD0 = 1;
        this->unkD4 = NULL;
        this->unkD8 = (KDMemoryCard *) (KDMemoryCard::GetCard((s32) this->unkD4));
        this->unkD8->SetState((KDMCState) 2);
    }
}
