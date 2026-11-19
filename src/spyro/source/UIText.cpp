#include "spyro/source/UIText.h"
#include "common/Source/Font.h"
#include "common/Source/MKFont.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/UIAttributes.h"
#include "spyro/source/UIContainer.h"
#include "spyro/source/UIMessage.h"
#include "spyro/source/UIObject.h"
#include "spyro/source/UIStringTable.h"
#include <m2c_macros.h>

extern s32 gpTranslation_StringArray;

#if 0 // DRAFT: pointer/array required
void UIText::GetStringWidth() {
    s32 temp_r0_14;
    s8 *var_r4_19;

    temp_r0_14 = this->unk6C;
    if (temp_r0_14 >= 0) {
        var_r4_19 = *(gpTranslation_StringArray + (temp_r0_14 * 4));
    } else {
        var_r4_19 = this->unk68;
    }
    this->unk64->CalcLength(var_r4_19);
}
#endif

#if 0 // DRAFT: pointer/array required
void UIText::Draw(const RenderContext &arg0) {
    RenderContext spB0;
    Matrix sp70;
    f64 sp68;
    f64 sp60;                                       /* compiler-managed */
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f3_162;
    s32 temp_r0_151;
    s32 temp_r3_121;
    s32 temp_r4_100;
    s8 *var_r29_156;

    sp38 = 0.0f;
    sp30 = 0.0f;
    sp34 = 0.0f;
    sp68 = (f64) sp38;
    sp60 = (f64) sp30;
    if ((((s8 *) this->unk68 != NULL) || ((s32) this->unk6C >= 0)) && ((MKFont *) this->unk64 != NULL) && !(this->unk18.unk34 <= 0.0f)) {
        if (this->unk18.unk38 <= 0.0f) {
            return;
        }
        spB0.RenderContext();
        spB0.AddState(arg0, this->unk18);
        temp_r4_100 = this->unk18.unk3C;
        if (!(temp_r4_100 & 3)) {
            sp60 = this->unk18.unk34 * 0.5f;
        } else if (temp_r4_100 & 1) {
            sp60 = 0.0f;
        } else {
            sp60 = this->unk18.unk34 / -2.0f;
        }
        temp_r3_121 = this->unk18.unk3C;
        if (!(temp_r3_121 & 0xC)) {
            (*(f32 *) ((u8 *) &sp58 + 0xc)) = this->unk18.unk38 * 0.5f;
        } else if (temp_r3_121 & 4) {
            (*(f32 *) ((u8 *) &sp58 + 0xc)) = 0.0f;
        } else {
            (*(f32 *) ((u8 *) &sp58 + 0xc)) = this->unk18.unk38 / -2.0f;
        }
        sp70.SetIdentity();
        sp70.Translate(&sp70, *((MKVector3 *) &sp60));
        ((Matrix *) &spB0)->Multiply(&sp70, (Matrix *) &spB0);
        temp_r0_151 = this->unk6C;
        if (temp_r0_151 >= 0) {
            var_r29_156 = *(gpTranslation_StringArray + (temp_r0_151 * 4));
        } else {
            var_r29_156 = this->unk68;
        }
        temp_f3_162 = this->unk70;
        if ((temp_f3_162 != 0.0f) || (this->unk74 != 0.0f)) {
            sp28 = spB0.unk38;
            sp20 = spB0.unk30 + temp_f3_162;
            sp24 = spB0.unk34 + this->unk74;
            sp58 = (f64) sp28;
            sp50 = (f64) sp20;
            spB0.unk30 = (f32) sp50;
            spB0.unk34 = (*(f32 *) ((u8 *) &sp50 + 0x4));
            spB0.unk38 = (f32) sp58;
            spB0.unk3C = 1.0f;
            this->unk64->DrawString(var_r29_156, this->unk18.unk34, this->unk18.unk38, (Matrix *) &spB0, this->unk18.unk3C, (u32) (128.0f * (*(f32 *) ((u8 *) &spB0 + 0x4c))) << 0x18, 1.0f, 1.0f, NULL, 1U);
            sp18 = spB0.unk38;
            sp10 = spB0.unk30 - this->unk70;
            sp14 = spB0.unk34 - this->unk74;
            sp48 = (f64) sp18;
            sp40 = (f64) sp10;
            spB0.unk30 = (f32) sp40;
            spB0.unk34 = (*(f32 *) ((u8 *) &sp40 + 0x4));
            spB0.unk38 = (f32) sp48;
            spB0.unk3C = 1.0f;
        }
        this->unk64->DrawString(var_r29_156, this->unk18.unk34, this->unk18.unk38, (Matrix *) &spB0, this->unk18.unk3C, (u32) (128.0f * (f32) spB0.unk40) | (((u32) (128.0f * (*(f32 *) ((u8 *) &spB0 + 0x44))) << 8) | (((u32) (128.0f * (*(f32 *) ((u8 *) &spB0 + 0x4c))) << 0x18) | ((u32) (128.0f * (f32) spB0.unk48) << 0x10))), 1.0f, 1.0f, NULL, 1U);
    }
}
#endif

void UIText::Update() {

}

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to
s32 UIText::LoadLine(UIDataLine *arg0) {
    s8 *sp8;
    s8 *temp_r3_276;
    s8 *temp_r3_297;

    sp8 = NULL;
    if (((MKIniLine *) arg0)->LoadString("font", &sp8, 0) != 0) {
        temp_r3_276 = this->unk60;
        if (temp_r3_276 != NULL) {
            UIStringTable_Remove(temp_r3_276);
        }
        UIStringTable_Add(sp8);
        this->unk60 = M2C_ERROR(/* Read from unset register $r3 */);
        return 1;
    }
    if (((MKIniLine *) arg0)->LoadString("text", &sp8, 0) != 0) {
        temp_r3_297 = this->unk68;
        if (temp_r3_297 != NULL) {
            UIStringTable_Remove(temp_r3_297);
        }
        UIStringTable_Add(sp8);
        this->unk68 = M2C_ERROR(/* Read from unset register $r3 */);
        this->unk6C = -1;
        return 1;
    }
    if (((MKIniLine *) arg0)->LoadInt("stringId", (int *) &this->unk6C, 0) != 0) {
        return 1;
    }
    return UIObject::LoadLine(arg0);
}
#endif

void UIText::FreeResources() {
    MKFont *temp_r3_342;

    temp_r3_342 = this->unk64;
    if (temp_r3_342 != NULL) {
        temp_r3_342->Destroy();
        this->unk64 = NULL;
    }
}

void UIText::LoadResources() {
    s8 *temp_r3_367;

    if ((MKFont *) this->unk64 == NULL) {
        temp_r3_367 = this->unk60;
        if (temp_r3_367 == NULL) {
            return;
        }
        this->unk64 = ((MKFont *) temp_r3_367)->Create(M2C_ERROR(/* Read from unset register $r4 */));
    }
}

#if 0 // DRAFT: function call 'UIStringTable_Remove(signed char *)' does not match
void UIText::Deinit() {
    s8 *temp_r3_390;
    s8 *temp_r3_398;

    temp_r3_390 = this->unk60;
    if (temp_r3_390 != NULL) {
        UIStringTable_Remove(temp_r3_390);
    }
    UIStringTable_Add(NULL);
    this->unk60 = M2C_ERROR(/* Read from unset register $r3 */);
    temp_r3_398 = this->unk68;
    if (temp_r3_398 != NULL) {
        UIStringTable_Remove(temp_r3_398);
    }
    UIStringTable_Add(NULL);
    this->unk68 = M2C_ERROR(/* Read from unset register $r3 */);
    this->unk6C = -1;
    UIObject::Deinit();
}
#endif

void UIText::Init() {
    UIObject::Init();
    this->unk60 = NULL;
    this->unk68 = NULL;
    this->unk6C = -1;
    this->unk64 = NULL;
    this->unk70 = 0.0f;
    this->unk74 = 0.0f;
}
