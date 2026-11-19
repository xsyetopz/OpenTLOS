#include "spyro/source/CharacterGraph.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/KDGraph.h"
#include "spyro/source/KDPath.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include "spyro/source/DataMap.h"
#include <m2c_macros.h>

s32 atoi(s32);                                      /* extern */
extern s32 gViewSeed;
#if 0 // DRAFT: illegal use of incomplete struct/union/class 'DataMap'
static DataMap CharacterGraphLinkDataMap;           /* unable to generate initializer: confusing struct layout */

void CharacterGraphManager::Deinit() {

}
#endif

void CharacterGraphManager::Init() {

}

#if 0 // DRAFT: undefined identifier 'SendArgMessage'
void CharacterGraphNodeProp::Message(MKMessage *arg0) {
    s32 temp_r0_70;
    s32 temp_r31_90;
    void *temp_r3_84;

    temp_r0_70 = arg0->unk0;
    switch (temp_r0_70) {                           /* irregular */
    case 0x154:
        temp_r3_84 = checked_cast<SendArgMessage *, MKMessage>(arg0);
        temp_r31_90 = DataMap_GetValue(&CharacterGraphLinkDataMap, M2C_FIELD(temp_r3_84, s8 **, 0x10));
        M2C_FIELD((this + ((atoi(M2C_FIELD(temp_r3_84, s32 *, 0xC)) - 1) * 4)), s32 *, 0xA0) = temp_r31_90;
        break;
    case 0x155:
        this->unk50.unk44 = DataMap_GetValue(&CharacterGraphLinkDataMap, M2C_FIELD(checked_cast<SendArgMessage *, MKMessage>(arg0), s8 **, 0xC));
        this->unk50.unk80 |= 0x80;
        break;
    case 0x156:
        this->unk50.unk48 = atoi(M2C_FIELD(checked_cast<SendArgMessage *, MKMessage>(arg0), s32 *, 0xC));
        this->unk50.unk80 |= 0x40;
        break;
    case 0x5B:
        M2C_FIELD(checked_cast<GetPosMsg *, MKMessage>(arg0), f64 **, 8) = &this->unk50.unk8;
        break;
    }
    MKProp::Message(arg0);
}
#endif

#if 0 // DRAFT: function call 'checked_cast(void *)' does not match
void CharacterGraphNodeProp::Resolve() {
    KDSplinePathSegmentProp *var_r29_147;
    MKSceneManager *temp_r3_155;
    s32 temp_r0_178;
    s32 temp_r3_164;
    s32 var_r28_148;
    s32 var_r31_149;
    void *temp_r30_151;

    var_r29_147 = NULL;
    var_r28_148 = 0;
    var_r31_149 = 0;
    do {
        temp_r30_151 = this + var_r31_149;
        if ((MKSceneManager *) M2C_FIELD(temp_r30_151, MKSceneManager **, 0xDC) != NULL) {
            temp_r3_155 = M2C_FIELD(temp_r30_151, MKSceneManager **, 0xF4);
            if (temp_r3_155 != NULL) {
                var_r29_147 = checked_cast<KDSplinePathSegmentProp *, MKProp>(temp_r3_155->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */)));
            }
            temp_r3_164 = checked_cast<CharacterGraphNodeProp *, MKProp>(((MKSceneManager *) (M2C_FIELD(temp_r30_151, MKSceneManager **, 0xDC)))->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */)));
            if (temp_r3_164 != 0) {
                this->unk50.Link(temp_r3_164 + 0x50, var_r28_148, (LinkInformation) M2C_FIELD(temp_r30_151, s32 *, 0xA0), var_r29_147);
            }
        }
        var_r28_148 += 1;
        var_r31_149 += 4;
    } while (var_r28_148 < 6);
    temp_r0_178 = this->unk50.unkBC;
    if (temp_r0_178 != 0) {
        this->unk50.unk3C = temp_r0_178;
        this->unk50.unk80 |= 0x20;
    }
    this->unk50.unk40 = (MKProp *) this;
    this->unk50.unk4C = this->unk14;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'double *' to
void CharacterGraphNodeProp::LoadDone() {
    f64 sp10;
    f64 sp8;

    MKProp::LoadDone();
    sp8 = M2C_FIELD(&MKProp::loadInfo, f64 *, 0x40);
    sp10 = M2C_FIELD(&MKProp::loadInfo, f64 *, 0x48);
    this->unk50.SetPos(&sp8, &MKProp::loadInfo, M2C_FIELD(&MKProp::loadInfo, f64 *, 0x40));
}
#endif

#if 0 // DRAFT: expression syntax error
s32 CharacterGraphNodeProp::LoadLine(MKIniLine *arg0) {
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;

    sp14 = 0;
    sp14.Init();
    if (MKProp::LoadLine(arg0) != 0) {
        sp14.Deinit();
        return 1;
    }
    if (arg0->LoadInt("ArriveInfo", &spC, 0) != 0) {
        if (spC != 0) {
            this->unk50.unk44 = spC;
            this->unk50.unk80 |= 0x80;
        }
        sp14.Deinit();
        return 1;
    }
    if (arg0->LoadInt("Count", &sp8, 0) != 0) {
        this->unk50.unk48 = sp8;
        this->unk50.unk80 |= 0x40;
        sp14.Deinit();
        return 1;
    }
    if (arg0->LoadInt("PropID", &this->unk50.unkBC, 0) != 0) {
        sp14.Deinit();
        return 1;
    }
    if (arg0->LoadInt("LinkInfo1", &sp10, 0) != 0) {
        this->unk50.unk50 = sp10;
        sp14.Deinit();
        return 1;
    }
    if (arg0->LoadInt("LinkInfo2", &sp10, 0) != 0) {
        this->unk50.unk54 = sp10;
        sp14.Deinit();
        return 1;
    }
    if (arg0->LoadInt("LinkInfo3", &sp10, 0) != 0) {
        this->unk50.unk58 = sp10;
        sp14.Deinit();
        return 1;
    }
    if (arg0->LoadInt("LinkInfo4", &sp10, 0) != 0) {
        this->unk50.unk5C = sp10;
        sp14.Deinit();
        return 1;
    }
    if (arg0->LoadInt("LinkInfo5", &sp10, 0) != 0) {
        this->unk50.unk60 = sp10;
        sp14.Deinit();
        return 1;
    }
    if (arg0->LoadInt("LinkInfo6", &sp10, 0) != 0) {
        this->unk50.unk64 = sp10;
        sp14.Deinit();
        return 1;
    }
    if ((arg0->LoadInt("PathID1", &this->unk50.unkA4, 0) != 0) || (arg0->LoadInt("PathID2", &this->unk50.unkA8, 0) != 0) || (arg0->LoadInt("PathID3", &this->unk50.unkAC, 0) != 0) || (arg0->LoadInt("PathID4", &this->unk50.unkB0, 0) != 0) || (arg0->LoadInt("PathID4", &this->unk50.unkB4, 0) != 0) || (arg0->LoadInt("PathID4", &this->unk50.unkB8, 0) != 0)) {
        sp14.Deinit();
        return 1;
    }
    if ((arg0->LoadInt("LinkID1", &this->unk50.unk8C, 0) != 0) || (arg0->LoadInt("LinkID2", &this->unk50.unk90, 0) != 0) || (arg0->LoadInt("LinkID3", &this->unk50.unk94, 0) != 0) || (arg0->LoadInt("LinkID4", &this->unk50.unk98, 0) != 0) || (arg0->LoadInt("LinkID4", &this->unk50.unk9C, 0) != 0) || (arg0->LoadInt("LinkID4", &this->unk50.unkA0, 0) != 0)) {
        this->unk50.unk88 += 1;
        sp14.Deinit();
        return 1;
    }
    if (sp14.LoadLine(arg0, "OnArrive") != 0) {
        this->unk50.unk38.operator=(*((EventMessage *) &sp14));
        sp14.Deinit();
        return 1;
    }
    sp14.Deinit();
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk88'
void CharacterGraphNodeProp::Init() {
    s32 var_ctr_569;
    s32 var_r3_567;
    void *temp_r5_571;

    MKProp::Init();
    this->unk50.Init();
    var_r3_567 = 0;
    this->unk50.unk88 = 0;
    var_ctr_569 = 6;
    do {
        temp_r5_571 = this + var_r3_567;
        var_r3_567 += 4;
        M2C_FIELD(temp_r5_571, s32 *, 0xDC) = 0;
        M2C_FIELD(temp_r5_571, s32 *, 0xA0) = 0;
        M2C_FIELD(temp_r5_571, s32 *, 0xF4) = 0;
        var_ctr_569 -= 1;
    } while (var_ctr_569 != 0);
    this->unk50.unkBC = 0;
}
#endif

void CharacterGraphNode::SendArriveMessage() {
    this->unk38.Send(this->unk40);
}

#if 0 // DRAFT: illegal explicit conversion from 'CharacterGraphNode' to
s32 CharacterGraphNode::GetLinkPath(CharacterGraphNode *arg0) {
    s32 var_ctr_606;
    s32 var_r5_605;

    var_r5_605 = 0;
    var_ctr_606 = 6;
loop_1:
    if (arg0 == (u32) *(this + (var_r5_605 + 0x18))) {
        return M2C_FIELD((this + var_r5_605), s32 *, 0x68);
    }
    var_r5_605 += 4;
    var_ctr_606 -= 1;
    if (var_ctr_606 == 0) {
        return 0;
    }
    goto loop_1;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'CharacterGraphNode' to
s32 CharacterGraphNode::GetLinkInfo(CharacterGraphNode *arg0) {
    s32 var_ctr_627;
    s32 var_r5_626;

    var_r5_626 = 0;
    var_ctr_627 = 6;
loop_1:
    if (arg0 == (u32) *(this + (var_r5_626 + 0x18))) {
        return M2C_FIELD((this + var_r5_626), s32 *, 0x50);
    }
    var_r5_626 += 4;
    var_ctr_627 -= 1;
    if (var_ctr_627 == 0) {
        return -1;
    }
    goto loop_1;
}
#endif

CharacterGraphNode *CharacterGraphNode::GetNextNode() {
    s32 var_r31_657;

    if (GetNumLinks() == 1) {
        var_r31_657 = 0;
loop_2:
        if (GetLink(var_r31_657) != NULL) {
            return GetLink(var_r31_657);
        }
        var_r31_657 += 1;
        if (var_r31_657 >= 6) {
            goto block_5;
        }
        goto loop_2;
    }
block_5:
    return NULL;
}

#if 0 // DRAFT: function call 'MKRand_Int(long *, int, int)' does not match
CharacterGraphNode *CharacterGraphNode::GetRandomLink(int arg0) {
    CharacterGraphNode *var_r31_690;
    KDGraphNode *temp_r3_707;
    s32 var_r30_691;
    s32 var_r3_697;

    var_r31_690 = this;
    var_r30_691 = 0;
loop_5:
    if ((var_r30_691 < arg0) && (var_r31_690->GetNumLinks() != 0)) {
        var_r3_697 = MKRand_Int(&gViewSeed, 0, 5);
loop_3:
        temp_r3_707 = *(var_r31_690 + ((var_r3_697 * 4) + 0x18));
        if (temp_r3_707 == NULL) {
            var_r3_697 = MKRand_Int(&gViewSeed, 0, 6);
            goto loop_3;
        }
        var_r31_690 = checked_cast<CharacterGraphNode *, KDGraphNode>(temp_r3_707);
        var_r30_691 += 1;
        goto loop_5;
    }
    return var_r31_690;
}
#endif

CharacterGraphNode *CharacterGraphNode::GetLink(int arg0) const {
    if ((arg0 >= 0) && (arg0 < 6)) {
        return checked_cast<CharacterGraphNode *, KDGraphNode>(M2C_FIELD((this + (arg0 * 4)), KDGraphNode **, 0x18));
    }
    return NULL;
}

#if 0 // DRAFT: illegal explicit conversion from 'const CharacterGraphNode' to
s32 CharacterGraphNode::IsLinked(CharacterGraphNode *arg0) const {
    s32 var_ctr_761;
    s32 var_r5_760;

    var_r5_760 = 0;
    var_ctr_761 = 6;
loop_1:
    if ((u32) *(this + (var_r5_760 + 0x18)) == arg0) {
        return 1;
    }
    var_r5_760 += 4;
    var_ctr_761 -= 1;
    if (var_ctr_761 == 0) {
        return 0;
    }
    goto loop_1;
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'LinkInformation'
s32 CharacterGraphNode::Link(CharacterGraphNode *arg0, int arg1, LinkInformation arg2, KDSplinePathSegmentProp *arg3) {
    s32 var_ctr_784;
    s32 var_r5_783;
    s32 var_r8_782;
    void *temp_r5_790;
    void *temp_r8_806;

    if (arg1 == -1) {
        var_r8_782 = 0;
        var_r5_783 = 0;
        var_ctr_784 = 6;
loop_2:
        if ((u32) *(this + (var_r5_783 + 0x18)) == 0U) {
            temp_r5_790 = this + var_r5_783;
            M2C_FIELD(temp_r5_790, CharacterGraphNode **, 0x18) = arg0;
            M2C_FIELD(temp_r5_790, s32 *, 0x50) = (s32) arg2;
            M2C_FIELD(temp_r5_790, KDSplinePathSegmentProp **, 0x68) = arg3;
            this->unk30 += 1;
            return var_r8_782;
        }
        var_r8_782 += 1;
        var_r5_783 += 4;
        var_ctr_784 -= 1;
        if (var_ctr_784 == 0) {
            /* Duplicate return node #8. Try simplifying control flow for better match */
            return -1;
        }
        goto loop_2;
    }
    temp_r8_806 = this + (arg1 * 4);
    if ((CharacterGraphNode *) M2C_FIELD(temp_r8_806, CharacterGraphNode **, 0x18) == NULL) {
        M2C_FIELD(temp_r8_806, CharacterGraphNode **, 0x18) = arg0;
        M2C_FIELD(temp_r8_806, s32 *, 0x50) = (s32) arg2;
        M2C_FIELD(temp_r8_806, KDSplinePathSegmentProp **, 0x68) = arg3;
        this->unk30 += 1;
        return arg1;
    }
    return -1;
}
#endif

void CharacterGraphNode::Init() {
    s32 var_ctr_837;
    s32 var_r3_832;
    void *temp_r7_839;

    KDGraphNode::Init();
    var_r3_832 = 0;
    var_ctr_837 = 6;
    do {
        temp_r7_839 = this + var_r3_832;
        var_r3_832 += 4;
        M2C_FIELD(temp_r7_839, s32 *, 0x50) = 0;
        M2C_FIELD(temp_r7_839, s32 *, 0x68) = 0;
        M2C_FIELD(temp_r7_839, s32 *, 0x18) = 0;
        var_ctr_837 -= 1;
    } while (var_ctr_837 != 0);
    this->unk80 &= ~0x80;
    this->unk80 &= ~0x40;
    this->unk44 = 0;
    this->unk48 = 0;
    this->unk3C = 0;
}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
CharacterGraphNode::CharacterGraphNode() {
    s32 var_ctr_882;
    s32 var_r3_878;
    void *temp_r6_884;

    this->unk38.unk0 = 0;
    this->unk38.Init();
    var_r3_878 = 0;
    var_ctr_882 = 6;
    do {
        temp_r6_884 = this + var_r3_878;
        var_r3_878 += 4;
        M2C_FIELD(temp_r6_884, s32 *, 0x50) = 0;
        M2C_FIELD(temp_r6_884, s32 *, 0x68) = 0;
        var_ctr_882 -= 1;
    } while (var_ctr_882 != 0);
    this->unk80 &= ~0x80;
    this->unk80 &= ~0x40;
    this->unk44 = 0;
    this->unk48 = 0;
    this->unk3C = 0;
    return this;
}
#endif
