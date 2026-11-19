#include "spyro/source/UIImage.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/UIAttributes.h"
#include "spyro/source/UIMessage.h"
#include "spyro/source/UIObject.h"
#include "unplaced_enums.h"
#include "common/Source/MKMat_MK2_Standard.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "spyro/source/UIStringTable.h"
#include <m2c_macros.h>

extern MKMaterial *gpMKWhiteMaterial;

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void UIImage::Draw(const RenderContext &arg0) {
    RenderContext sp90;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f64 sp48;
    f64 sp40;
    MKVector3 sp30;
    MKVector3 sp20;
    f32 sp18;
    f64 sp10;
    MKMaterial *temp_r3_103;
    f32 temp_f0_90;
    f32 temp_f0_96;
    f32 var_f1_32;
    f32 var_f1_51;
    f64 temp_f0_70;
    s32 temp_r3_29;
    s32 temp_r3_48;

    sp90.RenderContext();
    sp90.AddState(arg0, this->unk18);
    if (this->unk18.unk40 & 0x20) {
        temp_r3_29 = this->unk18.unk3C;
        if (!(temp_r3_29 & 0xC)) {
            var_f1_32 = 0.0f;
        } else if (temp_r3_29 & 4) {
            var_f1_32 = -0.5f * this->unk18.unk38;
        } else {
            var_f1_32 = -this->unk18.unk38;
        }
        sp20.operator*(var_f1_32);
        temp_r3_48 = this->unk18.unk3C;
        if (!(temp_r3_48 & 3)) {
            var_f1_51 = 0.0f;
        } else if (temp_r3_48 & 1) {
            var_f1_51 = -0.5f * this->unk18.unk34;
        } else {
            var_f1_51 = -this->unk18.unk34;
        }
        sp30.operator*(var_f1_51);
        temp_f0_70 = sp30 + M2C_BITWISE(f64, sp20);
        sp10 = temp_f0_70;
        sp40 = temp_f0_70;
        sp18 = sp30.unk8 + sp20.unk8;
        sp48 = (f64) sp18;
        ((Matrix *) &sp90)->Translate((Matrix *) &sp90, *((MKVector3 *) &sp40));
    }
    sp50 = 0.0f;
    temp_f0_90 = this->unk18.unk34;
    sp60 = temp_f0_90;
    sp70 = 0.0f;
    sp80 = temp_f0_90;
    sp54 = 0.0f;
    sp64 = 0.0f;
    temp_f0_96 = this->unk18.unk38;
    sp74 = temp_f0_96;
    sp84 = temp_f0_96;
    sp58 = 0.0f;
    sp68 = 0.0f;
    sp78 = 0.0f;
    sp88 = 0.0f;
    temp_r3_103 = this->unk64;
    if (temp_r3_103 != NULL) {
        MKMaterial_SetMaterial(temp_r3_103);
    } else {
        MKMaterial_SetMaterial(gpMKWhiteMaterial);
    }
    MKPrimitive(0xC, 1);
    MKSetMatrix(*((Matrix *) &sp90));
    MKBegin(4);
    MKSetColorV(*((MKVector4 *) &sp90.unk40));
    MKSetTexCoord1F(M2C_BITWISE(f32, this->unk60), M2C_BITWISE(f32, this->unk64));
    MKSetPositionV(*((MKVector3 *) &sp50));
    MKSetTexCoord1F(this->unk68, M2C_BITWISE(f32, this->unk64));
    MKSetPositionV(*((MKVector3 *) &sp60));
    MKSetTexCoord1F(M2C_BITWISE(f32, this->unk60), this->unk6C);
    MKSetPositionV(*((MKVector3 *) &sp70));
    MKSetTexCoord1F(this->unk68, this->unk6C);
    MKSetPositionV(*((MKVector3 *) &sp80));
    MKEnd();
    MKEndPrimitive();
}
#endif

void UIImage::Update() {

}

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to
s32 UIImage::LoadLine(UIDataLine *arg0) {
    s8 *sp8;
    s8 *temp_r3_177;

    sp8 = NULL;
    if (((MKIniLine *) arg0)->LoadString("texture", &sp8, 0) != 0) {
        temp_r3_177 = this->unk60;
        if (temp_r3_177 != NULL) {
            UIStringTable_Remove(temp_r3_177);
        }
        UIStringTable_Add(sp8);
        this->unk60 = M2C_ERROR(/* Read from unset register $r3 */);
        return 1;
    }
    if (((MKIniLine *) arg0)->IsField("UVs") != 0) {
        ((MKIniLine *) arg0)->AsFloat(0, (f32 *) &this->unk60);
        ((MKIniLine *) arg0)->AsFloat(1, (f32 *) &this->unk64);
        ((MKIniLine *) arg0)->AsFloat(2, &this->unk68);
        ((MKIniLine *) arg0)->AsFloat(3, &this->unk6C);
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
