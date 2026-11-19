#include "spyro/source/KDGraph.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

#if 0 // DRAFT: illegal implicit conversion from 'KDGraphNodeProp' to 'MKSceneManager *'
f32 KDGraphNodeProp::Resolve() {
    MKSceneManager *temp_r3_63;
    s32 temp_r3_67;
    s32 var_r30_59;
    s32 var_r31_60;

    var_r30_59 = 0;
    var_r31_60 = 0;
    do {
        temp_r3_63 = *(this + (var_r31_60 + 0x90));
        if (temp_r3_63 != NULL) {
            temp_r3_67 = (long) (checked_cast<KDGraphNodeProp *, MKProp>(temp_r3_63->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */))));
            if (temp_r3_67 != 0) {
                M2C_FIELD(M2C_FIELD(this, void **, 0x50), M2C_UNK (**)(u8 *, s32, s32), 0xC)(&this->unk50, temp_r3_67 + 0x50, var_r30_59);
            }
        }
        var_r30_59 += 1;
        var_r31_60 += 4;
    } while (var_r30_59 < 6);
}
#endif

s32 KDGraphNodeProp::LoadDone() {
    f64 sp10;
    f64 sp8;

    MKProp::LoadDone();
    sp8 = M2C_FIELD(&MKProp::loadInfo, f64 *, 0x40);
    sp10 = M2C_FIELD(&MKProp::loadInfo, f64 *, 0x48);
    M2C_FIELD(M2C_FIELD(this, void **, 0x50), M2C_UNK (**)(u8 *, f64 *, MKProp *, f64), 0x2C)(&this->unk50, &sp8, &MKProp::loadInfo, M2C_FIELD(&MKProp::loadInfo, f64 *, 0x40));
}

s32 KDGraphNodeProp::LoadLine(MKIniLine *arg0) {
    if (MKProp::LoadLine(arg0) != 0) {
        return 1;
    }
    if ((arg0->LoadInt("LinkID1", (int *) &this->unk90, 0) != 0) || (arg0->LoadInt("LinkID2", (int *) &this->unk94, 0) != 0) || (arg0->LoadInt("LinkID3", (int *) &this->unk98, 0) != 0) || (arg0->LoadInt("LinkID4", (int *) &this->unk9C, 0) != 0) || (arg0->LoadInt("LinkID5", (int *) &this->unkA0, 0) != 0) || (arg0->LoadInt("LinkID6", (int *) &this->unkA4, 0) != 0)) {
        this->unk8C += 1;
        return 1;
    }
    return 0;
}

#if 0 // DRAFT: illegal operand
void KDGraphNodeProp::Init() {
    s32 temp_r0_231;
    s32 var_ctr_229;
    s32 var_r3_227;

    MKProp::Init();
    M2C_FIELD(M2C_FIELD(this, void **, 0x50), M2C_UNK (**)(u8 *), 8)(&this->unk50);
    var_r3_227 = 0;
    this->unk8C = 0;
    var_ctr_229 = 6;
    do {
        temp_r0_231 = var_r3_227 + 0x90;
        var_r3_227 += 4;
        *(this + temp_r0_231) = 0;
        var_ctr_229 -= 1;
    } while (var_ctr_229 != 0);
}
#endif

s32 KDGraphNode::GetLink(int arg0) {
    if ((arg0 >= 0) && (arg0 < 6)) {
        return M2C_FIELD((this + (arg0 * 4)), s32 *, 0x18);
    }
    return 0;
}

#if 0 // DRAFT: illegal explicit conversion from 'const KDGraphNode' to 'unsigned long'
s32 KDGraphNode::IsLinked(KDGraphNode *arg0) const {
    s32 var_ctr_263;
    s32 var_r5_262;

    var_r5_262 = 0;
    var_ctr_263 = 6;
loop_1:
    if ((u32) *(this + (var_r5_262 + 0x18)) == arg0) {
        return 1;
    }
    var_r5_262 += 4;
    var_ctr_263 -= 1;
    if (var_ctr_263 == 0) {
        return 0;
    }
    goto loop_1;
}
#endif

s32 KDGraphNode::Unlink(int arg0) {
    void *temp_r4_282;

    temp_r4_282 = this + (arg0 * 4);
    if ((u32) M2C_FIELD(temp_r4_282, u32 *, 0x18) != 0U) {
        M2C_FIELD(temp_r4_282, u32 *, 0x18) = 0U;
        this->unk30 -= 1;
        return 1;
    }
    return 0;
}

#if 0 // DRAFT: illegal explicit conversion from 'KDGraphNode' to 'unsigned long'
s32 KDGraphNode::Unlink(KDGraphNode *arg0) {
    s32 var_ctr_303;
    s32 var_r5_302;

    var_r5_302 = 0;
    var_ctr_303 = 6;
loop_1:
    if (arg0 == (u32) *(this + (var_r5_302 + 0x18))) {
        M2C_FIELD((this + var_r5_302), s32 *, 0x18) = 0;
        this->unk30 -= 1;
        return 1;
    }
    var_r5_302 += 4;
    var_ctr_303 -= 1;
    if (var_ctr_303 == 0) {
        return 0;
    }
    goto loop_1;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'KDGraphNode' to 'unsigned long'
s32 KDGraphNode::Link(KDGraphNode *arg0, int arg1) {
    s32 var_ctr_332;
    s32 var_r5_331;
    s32 var_r6_330;
    void *temp_r6_352;

    if (arg1 == -1) {
        var_r6_330 = 0;
        var_r5_331 = 0;
        var_ctr_332 = 6;
loop_2:
        if ((u32) *(this + (var_r5_331 + 0x18)) == 0U) {
            M2C_FIELD((this + var_r5_331), KDGraphNode **, 0x18) = arg0;
            this->unk30 += 1;
            return var_r6_330;
        }
        var_r6_330 += 1;
        var_r5_331 += 4;
        var_ctr_332 -= 1;
        if (var_ctr_332 == 0) {
            /* Duplicate return node #8. Try simplifying control flow for better match */
            return -1;
        }
        goto loop_2;
    }
    temp_r6_352 = this + (arg1 * 4);
    if ((KDGraphNode *) M2C_FIELD(temp_r6_352, KDGraphNode **, 0x18) == NULL) {
        M2C_FIELD(temp_r6_352, KDGraphNode **, 0x18) = arg0;
        this->unk30 += 1;
        return arg1;
    }
    return -1;
}
#endif

#if 0 // DRAFT: illegal operand
void KDGraphNode::Init() {
    s32 temp_r0_381;
    s32 var_ctr_379;
    s32 var_r4_376;

    this->unk30 = 0;
    var_r4_376 = 0;
    this->unk8 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    this->unk10 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    var_ctr_379 = 6;
    do {
        temp_r0_381 = var_r4_376 + 0x18;
        var_r4_376 += 4;
        *(this + temp_r0_381) = 0;
        var_ctr_379 -= 1;
    } while (var_ctr_379 != 0);
}
#endif

#if 0 // DRAFT: illegal operand
KDGraphNode::KDGraphNode() {
    s32 temp_r0_405;
    s32 var_ctr_403;
    s32 var_r4_400;

    this->unk8 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    var_r4_400 = 0;
    this->unk10 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unk30 = 0;
    var_ctr_403 = 6;
    do {
        temp_r0_405 = var_r4_400 + 0x18;
        var_r4_400 += 4;
        *(this + temp_r0_405) = 0;
        var_ctr_403 -= 1;
    } while (var_ctr_403 != 0);
}
#endif
