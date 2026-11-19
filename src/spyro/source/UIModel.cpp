#include "spyro/source/UIModel.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/UIAttributes.h"
#include "spyro/source/UIMessage.h"
#include "spyro/source/UIObject.h"
#include "unplaced_enums.h"
#include "common/Source/MKView.h"
#include "common/Source/system_extras.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/UIStringTable.h"
#include <m2c_macros.h>

extern u8 init_577;
extern u8 init_580;
static MKVector3 camera_576 = { 0.0f, 0.0f, 0.0f, 0.0f };
static MKVector3 lookat_579 = { 0.0f, 0.0f, 0.0f, 0.0f };

#if 0 // DRAFT: expression syntax error
void UIAnimatedModel::FreeResources() {
    MKModel *temp_r3_16;

    temp_r3_16 = this->unk64;
    if (temp_r3_16 != NULL) {
        MKModel_Destroy(temp_r3_16);
        this->unk64 = NULL;
    }
    this->unk60.Deinit();
    this->unk64 = NULL;
}
#endif

#if 0 // DRAFT: expression syntax error
void UIAnimatedModel::LoadResources() {
    s8 *temp_r31_51;

    if ((MKModel *) this->unk64 == NULL) {
        this->unk60.Init(this->unk60, NULL);
        temp_r31_51 = this->unk60.GetAnimName();
        this->unk64 = MKModel_Create(this->unk60.GetMeshName(), temp_r31_51, 2, NULL);
        M2C_FIELD(this, MKModel **, 0x70) = (MKModel *) this->unk64;
        this->unk60.CalculateSubObjectIndices();
        this->unk60.SetAnimation(MKModel_GetAnimation(this->unk64));
        this->unk60.SetAnim(this->unk60.GetAnim(0), 1.0f, 0.0f, 0, -1);
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void UIAnimatedModel::Update() {
    MKModel *temp_r3_94;

    temp_r3_94 = this->unk64;
    if ((temp_r3_94 != NULL) && (M2C_BITWISE(u32, this->unk68.unk18) != 0U) && ((u8) this->unk15 != 0)) {
        this->unk60.Animate(MKModel_GetAnimation(temp_r3_94), -1, NULL);
        KDSound_Play((MKAnimScript *) &this->unk60, 0U);
    }
}
#endif

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void UIModel::UpdateMatrix(RenderContext *arg0) {
    Matrix sp40;
    MKVector3 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;

    if ((s8) init_577 == 0) {
        sp28 = 0.0f;
        sp20 = 0.0f;
        sp24 = 0.0f;
        M2C_FIELD(&camera_576, f64 *, 8) = (f64) sp28;
        M2C_FIELD(&camera_576, f64 *, 0) = (f64) sp20;
        init_577 = 1;
    }
    if ((s8) init_580 == 0) {
        sp10 = 0.0f;
        sp14 = 0.0f;
        sp18 = 1.0f;
        M2C_FIELD(&lookat_579, f64 *, 0) = (f64) sp10;
        M2C_FIELD(&lookat_579, f64 *, 8) = (f64) sp18;
        init_580 = 1;
    }
    MKView_SetCameraLookAt(camera_576, lookat_579, 0.0f);
    M2C_STRUCT_COPY((s32) &sp30.unkC + 4, (s32) (arg0 - 4) + 4, 0x40);
    sp40.unk4 *= -1.0f;
    sp40.unk10 *= -1.0f;
    sp40.unk18 *= -1.0f;
    sp40.unk1C *= -1.0f;
    sp40.unk24 *= -1.0f;
    sp40.unk34 *= -1.0f;
    MKView_TransformPoint2Dto3D(arg0->unk30, arg0->unk34, (1000.0f * arg0->unk38) + 1000.0f, &sp30);
    sp40.unk3C = 1.0f;
    sp40.unk30 = M2C_BITWISE(f32, sp30);
    sp40.unk34 = sp30.unk4;
    sp40.unk38 = sp30.unk8;
    sp40.unk2C = 0.0f;
    sp40.unk1C = 0.0f;
    sp40.unkC = 0.0f;
    sp40.unk3C = 1.0f;
    MKModel_SetWorldMatrix(this->unk64, sp40);
    MKModel_SetColor(this->unk64, *((MKVector4 *) &arg0->unk40));
}
#endif

void UIModel::Draw(const RenderContext &arg0) {
    RenderContext sp10;

    if ((MKModel *) this->unk64 != NULL) {
        MKView_Push();
        MKView_SetProjection(0.0f, 0.0f, 0.0f);
        sp10.RenderContext(arg0, this->unk18);
        UpdateMatrix(&sp10);
        MKModel_Draw(this->unk64, NULL);
        MKView_Pop();
    }
}

void UIModel::Update() {

}

#if 0 // DRAFT: undefined identifier 'LoadString'
s32 UIModel::LoadLine(UIDataLine *arg0) {
    s8 *sp8;
    s8 *temp_r3_299;

    sp8 = NULL;
    if (arg0->LoadString("model", &sp8, 0) != 0) {
        temp_r3_299 = this->unk60;
        if (temp_r3_299 != NULL) {
            UIStringTable_Remove(temp_r3_299);
        }
        UIStringTable_Add(sp8);
        this->unk60 = M2C_ERROR(/* Read from unset register $r3 */);
        return 1;
    }
    return UIObject::LoadLine(arg0);
}
#endif

void UIModel::FreeResources() {
    MKModel *temp_r3_330;

    temp_r3_330 = this->unk64;
    if (temp_r3_330 != NULL) {
        MKModel_Destroy(temp_r3_330);
        this->unk64 = NULL;
    }
}

#if 0 // DRAFT: function call 'MKModel_Create(signed char *, int, int, int)' does not
void UIModel::LoadResources() {
    s32 var_r30_367;
    s8 *temp_r3_355;
    s8 *temp_r3_374;

    if ((MKModel *) this->unk64 == NULL) {
        temp_r3_355 = this->unk60;
        if (temp_r3_355 != NULL) {
            this->unk64 = MKModel_Create(temp_r3_355, NULL, 2, NULL);
            if ((MKModel *) this->unk64 != NULL) {
                var_r30_367 = 0;
loop_9:
                if (var_r30_367 < MKModel_GetNmbrOfSubObjects(this->unk64, (SubObjectType) 0)) {
                    temp_r3_374 = MKModel_GetSubObjectName(this->unk64, (SubObjectType) 0, var_r30_367);
                    if ((strnicmp(temp_r3_374, "F_", 2) == 0) || (strnicmp(temp_r3_374, "C_", 2) == 0) || (strnicmp(temp_r3_374, "L_", 2) == 0)) {
                        MKModel_EnableSubObject(this->unk64, (SubObjectType) 0, var_r30_367, 0U, 1U);
                    }
                    var_r30_367 += 1;
                    goto loop_9;
                }
            }
        }
    }
}
#endif

#if 0 // DRAFT: function call 'UIStringTable_Remove(signed char *)' does not match
void UIModel::Deinit() {
    s8 *temp_r3_428;

    temp_r3_428 = this->unk60;
    if (temp_r3_428 != NULL) {
        UIStringTable_Remove(temp_r3_428);
    }
    UIStringTable_Add(NULL);
    this->unk60 = M2C_ERROR(/* Read from unset register $r3 */);
    UIObject::Deinit();
}
#endif

void UIModel::Init() {
    UIObject::Init();
    this->unk60 = NULL;
    this->unk64 = NULL;
}
