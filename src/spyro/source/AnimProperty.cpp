#include "spyro/source/AnimProperty.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "spyro/source/KDAnimScriptProperty.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDProperty.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(s32);                                  /* extern */
s32 stricmp(s8 *, M2C_UNK *);                       /* extern */
extern s32 gViewSeed;

#if 0 // DRAFT: expression syntax error
void AnimProperty::Update() {
    f32 temp_f0_89;
    f32 var_f1_79;
    s32 temp_r3_107;
    s32 temp_r5_80;
    s32 var_ctr_83;
    s32 var_r29_72;
    s32 var_r30_71;
    s32 var_r3_82;
    s32 var_r6_81;

    if (((u8) *(KDProperty::pInstanceMem.__vptr + this->unk8) != 0) && ((M2C_FIELD(M2C_FIELD(checked_cast<KDProp *, MKProp>((MKProp *) KDProperty::pInstanceMem.__vptr), void **, 0x80), s32 *, 0x2C) & 1) || (M2C_FIELD(M2C_FIELD(checked_cast<KDProp *, MKProp>((MKProp *) KDProperty::pInstanceMem.__vptr), void **, 0x80), s32 *, 0x2C) & 2))) {
        var_r30_71 = 0;
        var_r29_72 = 0;
        if ((s32) this->unk18 > 1) {
loop_4:
            var_f1_79 = MKRand_Float(&gViewSeed, 0.0f, this->unk20);
            temp_r5_80 = this->unk18;
            var_r6_81 = 0;
            var_r3_82 = 0;
            var_ctr_83 = temp_r5_80;
            if (temp_r5_80 > 0) {
loop_5:
                temp_f0_89 = *(this->unk14 + (var_r3_82 + 4));
                M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                if (var_f1_79 == temp_f0_89) {
                    var_r30_71 = var_r6_81;
                } else {
                    var_f1_79 -= temp_f0_89;
                    var_r6_81 += 1;
                    var_r3_82 += 8;
                    var_ctr_83 -= 1;
                    if (var_ctr_83 != 0) {
                        goto loop_5;
                    }
                }
            }
            var_r29_72 += 1;
            if (var_r29_72 < temp_r5_80) {
                temp_r3_107 = *(KDProperty::pInstanceMem.__vptr + (this->unk8 + 4));
                if ((var_r30_71 == temp_r3_107) && ((s32) this->unk1C != temp_r3_107)) {
                    goto loop_4;
                }
            }
        }
        *(KDProperty::pInstanceMem.__vptr + (this->unk8 + 4)) = var_r30_71;
        ((MKAnimScript *) (M2C_FIELD(checked_cast<KDProp *, MKProp>((MKProp *) KDProperty::pInstanceMem.__vptr), MKAnimScript **, 0x80)))->SetAnim(*(this->unk14 + (var_r30_71 * 8)), 1.0f, 0.0f, 0, -1);
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void AnimProperty::Command(int arg0) {
    switch (arg0) {                                 /* irregular */
    case 3:
        *(KDProperty::pInstanceMem.__vptr + this->unk8) = 1;
        return;
    case 2:
        *(KDProperty::pInstanceMem.__vptr + this->unk8) = 0;
        return;
    }
}
#endif

#if 0 // DRAFT: function call 'stricmp(const char *, const char[6])' does not match
s32 AnimProperty::ResolveCommand(const char *arg0) const {
    s32 temp_r3_174;

    temp_r3_174 = stricmp(arg0, "Reset") - 1;
    return 3 & ((temp_r3_174 - temp_r3_174) - !M2C_CARRY);
}
#endif

#if 0 // DRAFT: function call 'property_cast(KDPropertyCommand *)' does not match
void AnimProperty::Resolve(KDPropertySet *arg0) {
    s32 var_r30_199;
    s32 var_r31_200;

    this->unk10 = property_cast<KDAnimScriptProperty *, KDProperty *>(arg0->Find("defaultAnimScript"));
    var_r30_199 = 0;
    var_r31_200 = 0;
loop_2:
    if (var_r30_199 < (s32) this->unk18) {
        var_r30_199 += 1;
        *(this->unk14 + var_r31_200) = ((MKAnimScript *) (M2C_FIELD(this->unk10, MKAnimScript **, 0x10)))->GetAnim(*(this->unk14 + var_r31_200));
        var_r31_200 += 8;
        goto loop_2;
    }
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void AnimProperty::Deinit() {
    MKHeap *temp_r3_233;
    void *temp_r31_230;

    temp_r31_230 = this->unk14;
    if (temp_r31_230 != NULL) {
        temp_r3_233 = MKHeap::Current();
        if (temp_r3_233 != NULL) {
            ((MKHeap *) (temp_r3_233->Current()))->Free(temp_r31_230, NULL, 0);
            return;
        }
        free(temp_r31_230);
    }
}
#endif

#if 0 // DRAFT: illegal type
void AnimProperty::LoadDone() {
    f32 temp_f0_274;
    f32 var_f2_256;
    s32 temp_r0_262;
    s32 var_r4_258;
    s32 var_r6_257;

    var_f2_256 = 0.0f;
    var_r6_257 = 0;
    var_r4_258 = 0;
loop_4:
    if (var_r6_257 < (s32) this->unk18) {
        temp_r0_262 = var_r4_258 + 4;
        if (*(this->unk14 + temp_r0_262) > var_f2_256) {
            this->unk1C = var_r6_257;
            var_f2_256 = *(this->unk14 + temp_r0_262);
        }
        var_r6_257 += 1;
        temp_f0_274 = *(this->unk14 + (var_r4_258 + 4));
        var_r4_258 += 8;
        this->unk20 += temp_f0_274;
        goto loop_4;
    }
}
#endif

#if 0 // DRAFT: pointer/array required
s32 AnimProperty::LoadLine(MKIniLine *arg0) {
    MKHeap *temp_r3_311;
    MKIniLine *var_r30_306;
    s32 temp_r0_336;
    s32 temp_r31_310;
    s32 temp_r3_307;
    s32 var_r31_325;
    void *var_r3_318;

    if (arg0->IsField("AnimNames") != 0) {
        var_r30_306 = arg0->unkC->GetSubLine(arg0);
        temp_r3_307 = arg0->GetNmbrOfSubLines();
        this->unk18 = temp_r3_307;
        temp_r31_310 = this->unk18 * 8;
        temp_r3_311 = temp_r3_307->Current();
        if (temp_r3_311 != NULL) {
            var_r3_318 = ((MKHeap *) (temp_r3_311->Current()))->Alloc(temp_r31_310, NULL, 0);
        } else {
            var_r3_318 = malloc(temp_r31_310);
        }
        this->unk14 = var_r3_318;
        var_r31_325 = 0;
loop_6:
        if (var_r30_306 != NULL) {
            *(this->unk14 + var_r31_325) = var_r30_306->GetFieldName();
            temp_r0_336 = var_r31_325 + 4;
            var_r31_325 += 8;
            *(this->unk14 + temp_r0_336) = var_r30_306->GetFloat(0);
            var_r30_306 = var_r30_306->unkC->GetNextLine(var_r30_306);
            goto loop_6;
        }
    }
    return 0;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'char *' to
void AnimProperty::Init(char *arg0) {
    this->unk4 = arg0;
    this->unk10 = NULL;
    this->unk14 = NULL;
    this->unk18 = 0;
    this->unk20 = 0.0f;
    this->unk1C = 0;
}
#endif
