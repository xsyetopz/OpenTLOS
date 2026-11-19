#include "spyro/source/UIModel.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/UIAttributes.h"
#include "spyro/source/UIContainer.h"
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

void UIAnimatedModel::FreeResources() {
    MKModel *temp_r3_16;

    temp_r3_16 = this->unk64;
    if (temp_r3_16 != NULL) {
        MKModel_Destroy(temp_r3_16);
        this->unk64 = NULL;
    }
    this->unk68.Deinit();
    this->unk68.unk4 = NULL;
}

void UIAnimatedModel::LoadResources() {
    s8 *animName;

    if ((MKModel *) this->unk64 == NULL) {
        this->unk68.Init((const char *) this->unk60, (MKModel *) NULL);
        animName = this->unk68.GetAnimName();
        this->unk64 = MKModel_Create((const char *) this->unk68.GetMeshName(), (const char *) animName, 2, NULL);
        this->unk68.unk8 = this->unk64;
        this->unk68.CalculateSubObjectIndices();
        this->unk68.SetAnimation(MKModel_GetAnimation(this->unk64));
        this->unk68.SetAnim((MKAnim *) this->unk68.GetAnim(0), 1.0f, 0.0f, 0, -1);
    }
}

void UIAnimatedModel::Update() {
    MKModel *temp_r3_94;

    temp_r3_94 = this->unk64;
    if ((temp_r3_94 != NULL) && ((u32) this->unk68.unk20 != 0) && ((u8) this->unk15 != 0)) {
        this->unk68.Animate(MKModel_GetAnimation(temp_r3_94), -1, NULL);
        KDSound_Play(&this->unk68, 0U);
    }
}

void UIModel::UpdateMatrix(RenderContext *arg0) {
    Matrix sp40;
    MKVector3 sp30;

    /* Lazily initialise the two static camera vectors on first use. */
    if ((s8) init_577 == 0) {
        camera_576.unk0 = 0.0f;
        camera_576.unk4 = 0.0f;
        camera_576.unk8 = 0.0f;
        init_577 = 1;
    }
    if ((s8) init_580 == 0) {
        lookat_579.unk0 = 0.0f;
        lookat_579.unk4 = 0.0f;
        lookat_579.unk8 = 1.0f;
        init_580 = 1;
    }
    MKView_SetCameraLookAt(camera_576, lookat_579, 0.0f);

    /* Start from the render context's leading matrix, negate the rotation terms, then rebuild the translation. */
    sp40 = *(Matrix *) arg0;
    sp40.unk4 *= -1.0f;
    sp40.unk10 *= -1.0f;
    sp40.unk18 *= -1.0f;
    sp40.unk1C *= -1.0f;
    sp40.unk24 *= -1.0f;
    sp40.unk34 *= -1.0f;
    MKView_TransformPoint2Dto3D(arg0->unk30, arg0->unk34, (1000.0f * arg0->unk38) + 1000.0f, &sp30);
    sp40.unk3C = 1.0f;
    sp40.unk30 = sp30.unk0;
    sp40.unk34 = sp30.unk4;
    sp40.unk38 = sp30.unk8;
    sp40.unk2C = 0.0f;
    sp40.unk1C = 0.0f;
    sp40.unkC = 0.0f;
    sp40.unk3C = 1.0f;
    MKModel_SetWorldMatrix(this->unk64, sp40);
    MKModel_SetColor(this->unk64, *((MKVector4 *) &arg0->unk40));
}

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

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to 'const char **'
s32 UIModel::LoadLine(UIDataLine *arg0) {
    s8 *sp8;
    s8 *temp_r3_299;

    sp8 = NULL;
    if (((MKIniLine *) arg0)->LoadString("model", &sp8, 0) != 0) {
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

void UIModel::LoadResources() {
    s32 index;
    const char *subName;
    s8 *modelName;

    if ((MKModel *) this->unk64 == NULL) {
        modelName = this->unk60;
        if (modelName != NULL) {
            this->unk64 = MKModel_Create((const char *) modelName, NULL, 2, NULL);
            if ((MKModel *) this->unk64 != NULL) {
                /* Enable every sub-object whose name starts with F_, C_ or L_. */
                for (index = 0; index < MKModel_GetNmbrOfSubObjects(this->unk64, (SubObjectType) 0); index += 1) {
                    subName = (const char *) MKModel_GetSubObjectName(this->unk64, (SubObjectType) 0, index);
                    if ((strnicmp(subName, "F_", 2) == 0) || (strnicmp(subName, "C_", 2) == 0) || (strnicmp(subName, "L_", 2) == 0)) {
                        MKModel_EnableSubObject(this->unk64, (SubObjectType) 0, index, 0, 1U);
                    }
                }
            }
        }
    }
}

#if 0 // DRAFT: function call 'UIStringTable_Remove(signed char *)' does not match 'UIStringTable_Remove(const char *)'
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
