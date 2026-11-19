#include "spyro/source/UIImage.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/UIAttributes.h"
#include "spyro/source/UIContainer.h"
#include "spyro/source/UIMessage.h"
#include "spyro/source/UIObject.h"
#include "unplaced_enums.h"
#include "common/Source/MKMat_MK2_Standard.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "spyro/source/UIStringTable.h"
#include <m2c_macros.h>

extern MKMaterial *gpMKWhiteMaterial;

void UIImage::Draw(const RenderContext &arg0) {
    RenderContext sp90;
    f32 sp20[3];
    f32 sp30[3];
    f32 sp40[3];
    f32 sp50[3];
    f32 sp60[3];
    f32 sp70[3];
    f32 sp80[3];
    f32 var_f1_32;
    f32 var_f1_51;
    s32 temp_r3_29;
    s32 temp_r3_48;

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
        sp20[0] = M2C_FIELD(&sp90, f32 *, 0x10) * var_f1_32;
        sp20[1] = M2C_FIELD(&sp90, f32 *, 0x14) * var_f1_32;
        sp20[2] = M2C_FIELD(&sp90, f32 *, 0x18) * var_f1_32;
        temp_r3_48 = this->unk18.unk3C;
        if (!(temp_r3_48 & 3)) {
            var_f1_51 = 0.0f;
        } else if (temp_r3_48 & 1) {
            var_f1_51 = -0.5f * this->unk18.unk34;
        } else {
            var_f1_51 = -this->unk18.unk34;
        }
        sp30[0] = M2C_FIELD(&sp90, f32 *, 0x0) * var_f1_51;
        sp30[1] = M2C_FIELD(&sp90, f32 *, 0x4) * var_f1_51;
        sp30[2] = M2C_FIELD(&sp90, f32 *, 0x8) * var_f1_51;
        sp40[0] = sp30[0] + sp20[0];
        sp40[1] = sp30[1] + sp20[1];
        sp40[2] = sp30[2] + sp20[2];
        ((Matrix *) &sp90)->Translate((Matrix *) &sp90, *((MKVector3 *) sp40));
    }
    sp50[0] = 0.0f;
    sp50[1] = 0.0f;
    sp50[2] = 0.0f;
    sp60[0] = this->unk18.unk34;
    sp60[1] = 0.0f;
    sp60[2] = 0.0f;
    sp70[0] = 0.0f;
    sp70[1] = this->unk18.unk38;
    sp70[2] = 0.0f;
    sp80[0] = this->unk18.unk34;
    sp80[1] = this->unk18.unk38;
    sp80[2] = 0.0f;
    if (this->unk64 != NULL) {
        MKMaterial_SetMaterial(this->unk64);
    } else {
        MKMaterial_SetMaterial(gpMKWhiteMaterial);
    }
    MKPrimitive(0xC, 1);
    MKSetMatrix(*((Matrix *) &sp90));
    MKBegin(4);
    MKSetColorV(*((MKVector4 *) &sp90.unk40));
    MKSetTexCoord1F(this->unk68, this->unk6C);
    MKSetPositionV(*((MKVector3 *) sp50));
    MKSetTexCoord1F(this->unk70, this->unk6C);
    MKSetPositionV(*((MKVector3 *) sp60));
    MKSetTexCoord1F(this->unk68, this->unk74);
    MKSetPositionV(*((MKVector3 *) sp70));
    MKSetTexCoord1F(this->unk70, this->unk74);
    MKSetPositionV(*((MKVector3 *) sp80));
    MKEnd();
    MKEndPrimitive();
}

void UIImage::Update() {

}

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to 'const char **'
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
        ((MKIniLine *) arg0)->AsFloat(0, &this->unk68);
        ((MKIniLine *) arg0)->AsFloat(1, &this->unk6C);
        ((MKIniLine *) arg0)->AsFloat(2, &this->unk70);
        ((MKIniLine *) arg0)->AsFloat(3, &this->unk74);
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

void UIImage::LoadResources() {
    s8 *temp_r3_259;

    if ((MKMaterial *) this->unk64 == NULL) {
        temp_r3_259 = this->unk60;
        if (temp_r3_259 != NULL) {
            this->unk64 = (MKMaterial *) MKMaterial_Create((const char *) temp_r3_259);
            MKMat_MK2_SetMaterialType(this->unk64, (MKMat_MK2_Standard_MaterialType) 3);
        }
    }
}

void UIImage::SetUVs(float arg0, float arg1, float arg2, float arg3) {
    this->unk68 = arg0;
    this->unk6C = arg1;
    this->unk70 = arg2;
    this->unk74 = arg3;
}

#if 0 // DRAFT: function call 'UIStringTable_Remove(signed char *)' does not match 'UIStringTable_Remove(const char *)'
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
