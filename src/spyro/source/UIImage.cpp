#include "spyro/source/UIImage.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/UIMessage.h"
#include "spyro/source/UIObject.h"
#include "unplaced_enums.h"
#include "common/Source/MKMat_MK2_Standard.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "spyro/source/UIStringTable.h"
#include <m2c_macros.h>

extern MKMaterial *gpMKWhiteMaterial;

#if 0 // DRAFT: undefined identifier 'arg_sp90'
void UIImage::Draw(const RenderContext &arg0) {
    MKMaterial *temp_r3_103;
    f32 temp_f0_90;
    f32 temp_f0_96;
    f32 var_f1_32;
    f32 var_f1_51;
    s32 temp_r3_29;
    s32 temp_r3_48;
    arg_sp90.RenderContext();
    arg_sp90.AddState(arg0, this->unk18);
    if (this->unk18.unk40 & 0x20) {
        temp_r3_29 = this->unk18.unk3C;
        if (!(temp_r3_29 & 0xC)) {
            var_f1_32 = 0.0f;
        } else if (temp_r3_29 & 4) {
            var_f1_32 = -0.5f * this->unk18.unk38;
        } else {
            var_f1_32 = -this->unk18.unk38;
        }
        arg_sp20.operator*(var_f1_32);
        temp_r3_48 = this->unk18.unk3C;
        if (!(temp_r3_48 & 3)) {
            var_f1_51 = 0.0f;
        } else if (temp_r3_48 & 1) {
            var_f1_51 = -0.5f * this->unk18.unk34;
        } else {
            var_f1_51 = -this->unk18.unk34;
        }
        arg_sp30.operator*(var_f1_51);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_sp40 = arg_sp10;
        arg_sp18 = arg_sp38 + arg_sp28;
        arg_sp48 = (f64) arg_sp18;
        arg_sp90.Translate((Matrix *) &arg_sp90, *((MKVector3 *) &arg_sp40));
    }
    arg_sp50 = 0.0f;
    temp_f0_90 = this->unk18.unk34;
    arg_sp60 = temp_f0_90;
    arg_sp70 = 0.0f;
    arg_sp80 = temp_f0_90;
    arg_sp54 = 0.0f;
    arg_sp64 = 0.0f;
    temp_f0_96 = this->unk18.unk38;
    arg_sp74 = temp_f0_96;
    arg_sp84 = temp_f0_96;
    arg_sp58 = 0.0f;
    arg_sp68 = 0.0f;
    arg_sp78 = 0.0f;
    arg_sp88 = 0.0f;
    temp_r3_103 = this->unk64;
    if (temp_r3_103 != NULL) {
        MKMaterial_SetMaterial(temp_r3_103);
    } else {
        MKMaterial_SetMaterial(gpMKWhiteMaterial);
    }
    MKPrimitive(0xC, 1);
    MKSetMatrix(*((Matrix *) &arg_sp90));
    MKBegin(4);
    MKSetColorV(*((MKVector4 *) &arg_spD0));
    MKSetTexCoord1F(M2C_BITWISE(f32, this->unk60), M2C_BITWISE(f32, this->unk64));
    MKSetPositionV(*((MKVector3 *) &arg_sp50));
    MKSetTexCoord1F(this->unk68, M2C_BITWISE(f32, this->unk64));
    MKSetPositionV(*((MKVector3 *) &arg_sp60));
    MKSetTexCoord1F(M2C_BITWISE(f32, this->unk60), this->unk6C);
    MKSetPositionV(*((MKVector3 *) &arg_sp70));
    MKSetTexCoord1F(this->unk68, this->unk6C);
    MKSetPositionV(*((MKVector3 *) &arg_sp80));
    MKEnd();
    MKEndPrimitive();
}
#endif

void UIImage::Update() {

}

#if 0 // DRAFT: undefined identifier 'LoadString'
s32 UIImage::LoadLine(UIDataLine *arg0) {
    s8 *sp8;
    s8 *temp_r3_177;

    sp8 = NULL;
    if (arg0->LoadString("texture", &sp8, 0) != 0) {
        temp_r3_177 = this->unk60;
        if (temp_r3_177 != NULL) {
            UIStringTable_Remove(temp_r3_177);
        }
        UIStringTable_Add(sp8);
        this->unk60 = M2C_ERROR(/* Read from unset register $r3 */);
        return 1;
    }
    if (arg0->IsField("UVs") != 0) {
        arg0->AsFloat(0, (f32 *) &this->unk60);
        arg0->AsFloat(1, (f32 *) &this->unk64);
        arg0->AsFloat(2, &this->unk68);
        arg0->AsFloat(3, &this->unk6C);
        return 1;
    }
    return UIObject::LoadLine(arg0);
}
#endif

void UIImage::FreeResources() {
    MKMaterial *temp_r3_234;

    temp_r3_234 = this->unk64;
    if (temp_r3_234 != NULL) {
        MKMaterial_Destroy(temp_r3_234);
        this->unk64 = NULL;
    }
}

#if 0 // DRAFT: function call 'MKMaterial_Create(signed char *)' does not match
void UIImage::LoadResources() {
    s8 *temp_r3_259;

    if ((MKMaterial *) this->unk64 == NULL) {
        temp_r3_259 = this->unk60;
        if (temp_r3_259 != NULL) {
            this->unk64 = MKMaterial_Create(temp_r3_259);
            MKMat_MK2_SetMaterialType(this->unk64, (MKMat_MK2_Standard_MaterialType) 3);
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'float' to
void UIImage::SetUVs(float arg0, float arg1, float arg2, float arg3) {
    this->unk60 = arg0;
    this->unk64 = arg1;
    this->unk68 = arg2;
    this->unk6C = arg3;
}
#endif

#if 0 // DRAFT: function call 'UIStringTable_Remove(signed char *)' does not match
void UIImage::Deinit() {
    s8 *temp_r3_293;

    temp_r3_293 = this->unk60;
    if (temp_r3_293 != NULL) {
        UIStringTable_Remove(temp_r3_293);
    }
    UIStringTable_Add(NULL);
    this->unk60 = M2C_ERROR(/* Read from unset register $r3 */);
    UIObject::Deinit();
}
#endif

void UIImage::Init() {
    UIObject::Init();
    this->unk60 = NULL;
    this->unk64 = NULL;
    SetUVs(0.0f, 0.0f, 1.0f, 1.0f);
}
