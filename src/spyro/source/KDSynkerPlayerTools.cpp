#include "spyro/source/KDSynkerPlayerTools.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/KDBasicEnvelope.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/KDSynkerPlayerActor.h"
#include "spyro/source/KDSynkerPlayerActorList.h"
#include "spyro/source/KDSynkerPlayerCamera.h"
#include "spyro/source/Level.h"
#include <m2c_macros.h>

#if 0 // DRAFT: illegal implicit conversion from 'long' to
s32 stricmp(u8 *, s8 *);                            /* extern */

s32 *KDSP_EnvelopeList::GetEnvelope(int arg0) {
    s32 *temp_r3_13;

    temp_r3_13 = this->unk4 + (arg0 * 0x5C);
    if ((s32) *temp_r3_13 <= 0) {
        return NULL;
    }
    return temp_r3_13;
}
#endif

void KDSP_EnvelopeList::LoadEnvelope(MKIniLine *arg0, KDBasicEnvelope *arg1) {
    f32 temp_f31_57;
    s32 temp_r31_49;
    s32 var_r29_51;
    s32 var_r30_50;

    arg1->unk0 = 0;
    arg1->unk4 = 0.0f;
    arg1->unk8 = 1.0f;
    arg1->unk4 = arg0->GetFloat(0);
    arg1->unk8 = arg0->GetFloat(1);
    temp_r31_49 = arg0->GetInt(2);
    var_r30_50 = 3;
    var_r29_51 = 0;
loop_2:
    if (var_r29_51 < temp_r31_49) {
        temp_f31_57 = arg0->GetFloat(var_r30_50 + 1);
        arg1->Add(arg0->GetFloat(var_r30_50), temp_f31_57);
        var_r30_50 += 2;
        var_r29_51 += 1;
        goto loop_2;
    }
}

void KDSP_EnvelopeList::Deinit() {
    this->unk4 = 0;
    this->unk0 = 0;
}

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void KDSP_EnvelopeList::Parse(KDSynkerHeap *arg0, MKIni *arg1) {
    KDBasicEnvelope *temp_r5_120;
    MKIniLine *temp_r6_95;
    MKIniLine *var_r30_114;
    s32 temp_r0_98;
    s32 temp_r3_105;
    s32 var_r31_104;
    void *temp_r5_103;

    temp_r6_95 = this->unk8;
    if (temp_r6_95 != NULL) {
        temp_r0_98 = this->unk0;
        if (temp_r0_98 != 0) {
            temp_r5_103 = arg0->unk18;
            var_r31_104 = 0;
            temp_r3_105 = arg0->unk20 - 1;
            arg0->unk18 = ((u8 *) temp_r5_103) + (((temp_r0_98 * 0x5C) + temp_r3_105) & ~temp_r3_105);
            this->unk4 = (s32) temp_r5_103;
            var_r30_114 = temp_r6_95->unkC->GetSubLine(temp_r6_95);
loop_4:
            if (var_r30_114 != NULL) {
                temp_r5_120 = this->unk4 + var_r31_104;
                var_r31_104 += 0x5C;
                LoadEnvelope(var_r30_114, temp_r5_120);
                var_r30_114 = var_r30_114->unkC->GetNextLine(var_r30_114);
                goto loop_4;
            }
        }
    }
}
#endif

void KDSP_EnvelopeList::HeapAddSize(KDSynkerHeap *arg0, MKIni *arg1) {
    MKIniLine *temp_r3_154;
    s32 temp_r0_159;
    s32 temp_r3_165;

    this->unk8 = arg1->GotoLine("ENVELOPE_TABLE", NULL);
    temp_r3_154 = this->unk8;
    if (temp_r3_154 != NULL) {
        this->unk0 = temp_r3_154->GetNmbrOfSubLines();
        temp_r0_159 = this->unk0;
        if (temp_r0_159 != 0) {
            temp_r3_165 = arg0->unk20 - 1;
            arg0->unk1C += ((temp_r0_159 * 0x5C) + temp_r3_165) & ~temp_r3_165;
        }
    }
}

void KDSP_EnvelopeList::Init() {
    this->unk0 = 0;
    this->unk4 = 0;
    this->unk8 = NULL;
}

#if 0 // DRAFT: pointer/array required
u16 KDSP_ToolsGetMatchingNodeIndex(MKModel *arg0, const char *arg1) {
    Animation *temp_r3_196;
    s32 var_r28_205;
    s8 temp_r31_199;
    u16 var_r29_200;
    u8 temp_r3_218;

    temp_r3_196 = MKModel_GetAnimation(arg0);
    temp_r31_199 = temp_r3_196->GetNmbrOfNodes();
    var_r29_200 = 0;
loop_8:
    if ((s32) var_r29_200 >= temp_r31_199) {
        return 0xFFFFU;
    }
    var_r28_205 = temp_r3_196->GetNodeName((s32) var_r29_200);
loop_5:
    temp_r3_218 = *var_r28_205;
    if (((s8) temp_r3_218 == 0) || ((s8) temp_r3_218 == 0)) {
        var_r29_200 += 1;
        goto loop_8;
    }
    if (stricmp((u8 *) var_r28_205, arg1) == 0) {
        return var_r29_200;
    }
    var_r28_205 += 1;
    goto loop_5;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'float' to
s32 KDSP_ToolsGetSplinePercent(KDSP_Bar *arg0, KDUniformSpline *arg1, KDBasicEnvelope *arg2, float arg3, int &arg4, float &arg5) {
    f32 temp_f1_329;
    f32 temp_f2_316;
    f32 var_f0_271;
    f32 var_f0_296;
    f32 var_f0_344;
    f32 var_f3_313;
    s32 temp_r5_325;

    if ((s32) arg1->unk0 == 1) {
        return 0;
    }
    var_f0_271 = (arg3 - (f32) arg0->unk0) / (f32) arg0->unk4;
    if (var_f0_271 < 1.0f) {

    } else {
        var_f0_271 = 1.0f;
    }
    if (var_f0_271 > 0.0f) {

    } else {
        var_f0_271 = 0.0f;
    }
    &arg5 = var_f0_271;
    if ((arg2 != NULL) && ((s32) arg2->unk0 > 0)) {
        &arg5 = arg2->GetValue(&arg5);
    }
    var_f0_296 = &arg5;
    if (var_f0_296 < 1.0f) {

    } else {
        var_f0_296 = 1.0f;
    }
    if (var_f0_296 > 0.0f) {

    } else {
        var_f0_296 = 0.0f;
    }
    &arg5 = var_f0_296;
    var_f3_313 = 0.0f;
    temp_f2_316 = &arg5 * arg1->unk8;
    &arg4 = 0;
loop_19:
    temp_r5_325 = &arg4;
    temp_f1_329 = *(arg1->unkC + ((temp_r5_325 << 5) + 0x1C));
    if (((var_f3_313 + temp_f1_329) < temp_f2_316) && (temp_r5_325 < (s32) (arg1->unk4 - 1))) {
        var_f3_313 += temp_f1_329;
        &arg4 += 1;
        goto loop_19;
    }
    if (temp_f1_329 > 0.0f) {
        &arg5 = (temp_f2_316 - var_f3_313) / temp_f1_329;
        var_f0_344 = &arg5;
        if (var_f0_344 < 1.0f) {

        } else {
            var_f0_344 = 1.0f;
        }
        if (var_f0_344 > 0.0f) {

        } else {
            var_f0_344 = 0.0f;
        }
        &arg5 = var_f0_344;
        return 1;
    }
    return 0;
}
#endif
