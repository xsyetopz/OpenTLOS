#include "spyro/source/UIText.h"
#include "common/Source/MKFont.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/UIMessage.h"
#include "spyro/source/UIObject.h"
#include "spyro/source/UIStringTable.h"
#include <m2c_macros.h>

extern s32 gpTranslation_StringArray;

#if 0 // DRAFT: type mismatch
void UIText::GetStringWidth() {
    MKFont *temp_r0_14;
    s8 *var_r4_19;

    temp_r0_14 = this->unk64;
    if (temp_r0_14 >= 0) {
        var_r4_19 = *(gpTranslation_StringArray + ((s32) temp_r0_14 * 4));
    } else {
        var_r4_19 = this->unk60;
    }
    this->unk64->CalcLength(var_r4_19);
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp38'
void UIText::Draw(const RenderContext &arg0) {
    MKFont *temp_r0_151;
    f32 temp_f3_162;
    s32 temp_r3_121;
    s32 temp_r4_100;
    s8 *var_r29_156;
    arg_sp38 = 0.0f;
    arg_sp30 = 0.0f;
    arg_sp34 = 0.0f;
    arg_sp68 = (f64) arg_sp38;
    arg_sp60 = (f64) arg_sp30;
    if ((((s8 *) this->unk60 != NULL) || ((MKFont *) this->unk64 >= 0)) && ((MKFont *) this->unk64 != NULL) && (M2C_ERROR(/* unknown instruction: cror eq, lt, eq */), ((this->unk18.unk34 == 0.0f) == 0))) {
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (this->unk18.unk38 == 0.0f) {
            return;
        }
        arg_spB0.RenderContext();
        arg_spB0.AddState(arg0, this->unk18);
        temp_r4_100 = this->unk18.unk3C;
        if (!(temp_r4_100 & 3)) {
            arg_sp60 = this->unk18.unk34 * 0.5f;
        } else if (temp_r4_100 & 1) {
            arg_sp60 = 0.0f;
        } else {
            arg_sp60 = this->unk18.unk34 / -2.0f;
        }
        temp_r3_121 = this->unk18.unk3C;
        if (!(temp_r3_121 & 0xC)) {
            arg_sp64 = this->unk18.unk38 * 0.5f;
        } else if (temp_r3_121 & 4) {
            arg_sp64 = 0.0f;
        } else {
            arg_sp64 = this->unk18.unk38 / -2.0f;
        }
        arg_sp70.SetIdentity();
        arg_sp70.Translate((Matrix *) &arg_sp70, *((MKVector3 *) &arg_sp60));
        arg_spB0.Multiply((Matrix *) &arg_sp70, (Matrix *) &arg_spB0);
        temp_r0_151 = this->unk64;
        if (temp_r0_151 >= 0) {
            var_r29_156 = *(gpTranslation_StringArray + ((s32) temp_r0_151 * 4));
        } else {
            var_r29_156 = this->unk60;
        }
        temp_f3_162 = M2C_BITWISE(f32, this->unk68);
        if ((temp_f3_162 != 0.0f) || (M2C_BITWISE(f32, this->unk6C) != 0.0f)) {
            arg_sp28 = arg_spE8;
            arg_sp20 = arg_spE0 + temp_f3_162;
            arg_sp24 = arg_spE4 + M2C_BITWISE(f32, this->unk6C);
            arg_sp58 = (f64) arg_sp28;
            arg_sp50 = (f64) arg_sp20;
            arg_spE0 = (f32) arg_sp50;
            arg_spE4 = arg_sp54;
            arg_spE8 = (f32) arg_sp58;
            arg_spEC = 1.0f;
            this->unk64->DrawString(var_r29_156, this->unk18.unk34, this->unk18.unk38, (Matrix *) &arg_spB0, this->unk18.unk3C, (u32) (128.0f * arg_spFC) << 0x18, 1.0f, 1.0f, NULL, 1U);
            arg_sp18 = arg_spE8;
            arg_sp10 = arg_spE0 - M2C_BITWISE(f32, this->unk68);
            arg_sp14 = arg_spE4 - M2C_BITWISE(f32, this->unk6C);
            arg_sp48 = (f64) arg_sp18;
            arg_sp40 = (f64) arg_sp10;
            arg_spE0 = (f32) arg_sp40;
            arg_spE4 = arg_sp44;
            arg_spE8 = (f32) arg_sp48;
            arg_spEC = 1.0f;
        }
        this->unk64->DrawString(var_r29_156, this->unk18.unk34, this->unk18.unk38, (Matrix *) &arg_spB0, this->unk18.unk3C, (u32) (128.0f * arg_spF0) | (((u32) (128.0f * arg_spF4) << 8) | (((u32) (128.0f * arg_spFC) << 0x18) | ((u32) (128.0f * arg_spF8) << 0x10))), 1.0f, 1.0f, NULL, 1U);
    }
}
#endif

void UIText::Update() {

}

#if 0 // DRAFT: undefined identifier 'LoadString'
s32 UIText::LoadLine(UIDataLine *arg0) {
    s8 *sp8;
    s8 *temp_r3_276;
    s8 *temp_r3_297;

    sp8 = NULL;
    if (arg0->LoadString("font", &sp8, 0) != 0) {
        temp_r3_276 = this->unk60;
        if (temp_r3_276 != NULL) {
            UIStringTable_Remove(temp_r3_276);
        }
        UIStringTable_Add(sp8);
        this->unk60 = M2C_ERROR(/* Read from unset register $r3 */);
        return 1;
    }
    if (arg0->LoadString("text", &sp8, 0) != 0) {
        temp_r3_297 = this->unk60;
        if (temp_r3_297 != NULL) {
            UIStringTable_Remove(temp_r3_297);
        }
        UIStringTable_Add(sp8);
        this->unk60 = M2C_ERROR(/* Read from unset register $r3 */);
        this->unk64 = (MKFont *)-1;
        return 1;
    }
    if (arg0->LoadInt("stringId", (s32 *) &this->unk64, 0) != 0) {
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

#if 0 // DRAFT: expression syntax error
void UIText::LoadResources() {
    s8 *temp_r3_367;

    if ((MKFont *) this->unk64 == NULL) {
        temp_r3_367 = this->unk60;
        if (temp_r3_367 == NULL) {
            return;
        }
        this->unk64 = temp_r3_367->Create(M2C_ERROR(/* Read from unset register $r4 */));
    }
}
#endif

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
    temp_r3_398 = this->unk60;
    if (temp_r3_398 != NULL) {
        UIStringTable_Remove(temp_r3_398);
    }
    UIStringTable_Add(NULL);
    this->unk60 = M2C_ERROR(/* Read from unset register $r3 */);
    this->unk64 = (MKFont *)-1;
    UIObject::Deinit();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'float' to
void UIText::Init() {
    UIObject::Init();
    this->unk60 = NULL;
    this->unk60 = NULL;
    this->unk64 = (MKFont *)-1;
    this->unk64 = NULL;
    this->unk68 = 0.0f;
    this->unk6C = 0.0f;
}
#endif
