#include "spyro/source/AnimProperty.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/KDAnimScriptProperty.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/Level.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(s32);                                  /* extern */
s32 stricmp(s8 *, M2C_UNK *);                       /* extern */
extern s32 gViewSeed;

void AnimProperty::Update() {
    KDProp *prop;
    MKAnimScript *anim;
    f32 temp_f0;
    f32 var_f1;
    s32 flags;
    s32 temp_r3;
    s32 temp_r5;
    s32 var_ctr;
    s32 var_r29;
    s32 var_r30;
    s32 var_r3;
    s32 var_r6;

    if ((u8) *(*(u8 **) KDProperty::pInstanceMem + this->unk8) == 0) {
        return;
    }
    prop = checked_cast<KDProp *, MKProp>(*(MKProp **) KDProperty::pInstanceMem);
    flags = M2C_FIELD(M2C_FIELD(prop, void **, 0x80), s32 *, 0x2C);
    if ((flags & 1) == 0) {
        prop = checked_cast<KDProp *, MKProp>(*(MKProp **) KDProperty::pInstanceMem);
        flags = M2C_FIELD(M2C_FIELD(prop, void **, 0x80), s32 *, 0x2C);
        if ((flags & 2) == 0) {
            return;
        }
    }
    var_r30 = 0;
    var_r29 = 0;
    if ((s32) this->unk18 > 1) {
loop_4:
        var_f1 = MKRand_Float((int *) &gViewSeed, 0.0f, this->unk20);
        temp_r5 = this->unk18;
        var_r6 = 0;
        var_r3 = 0;
        var_ctr = temp_r5;
        if (temp_r5 > 0) {
loop_5:
            temp_f0 = *(f32 *) ((s8 *) this->unk14 + (var_r3 + 4));
            if (var_f1 <= temp_f0) {
                var_r30 = var_r6;
            } else {
                var_f1 -= temp_f0;
                var_r6 += 1;
                var_r3 += 8;
                var_ctr -= 1;
                if (var_ctr != 0) {
                    goto loop_5;
                }
            }
        }
        var_r29 += 1;
        if (var_r29 < temp_r5) {
            temp_r3 = *(s32 *) (*(u8 **) KDProperty::pInstanceMem + (this->unk8 + 4));
            if ((var_r30 == temp_r3) && ((s32) this->unk1C != temp_r3)) {
                goto loop_4;
            }
        }
    }
    *(s32 *) (*(u8 **) KDProperty::pInstanceMem + (this->unk8 + 4)) = var_r30;
    prop = checked_cast<KDProp *, MKProp>(*(MKProp **) KDProperty::pInstanceMem);
    anim = M2C_FIELD(prop, MKAnimScript **, 0x80);
    anim->SetAnim(*(MKAnim **) ((s8 *) this->unk14 + var_r30 * 8), 1.0f, 0.0f, 0, -1);
}

void AnimProperty::Command(int arg0) {
    switch (arg0) {
    case 1:
    case 3:
        *(*(u8 **) KDProperty::pInstanceMem + this->unk8) = 1;
        return;
    case 2:
        *(*(u8 **) KDProperty::pInstanceMem + this->unk8) = 0;
        return;
    }
}

extern "C" s32 stricmp(const char *, const char *);
s32 AnimProperty::ResolveCommand(const char *arg0) const {
    return stricmp(arg0, "Reset") == 0 ? 3 : 0;
}

void AnimProperty::Resolve(KDPropertySet *arg0) {
    KDProperty *found;
    s32 i;
    s32 off;

    found = (KDProperty *) arg0->Find("defaultAnimScript");
    this->unk10 = property_cast<KDAnimScriptProperty *, KDProperty *>(found);
    i = 0;
    off = 0;
    while (i < (s32) this->unk18) {
        i += 1;
        *(void **) ((s8 *) this->unk14 + off) = ((MKAnimScript *) M2C_FIELD(this->unk10, MKAnimScript **, 0x10))->GetAnim(*(const char **) ((s8 *) this->unk14 + off));
        off += 8;
    }
}

void AnimProperty::Deinit() {
    void *temp_r31_230;

    temp_r31_230 = this->unk14;
    if (temp_r31_230 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_230, NULL, 0);
            return;
        }
        free(temp_r31_230);
    }
}

void AnimProperty::LoadDone() {
    f32 temp_f0;
    f32 max;
    s32 i;
    s32 off;

    max = 0.0f;
    i = 0;
    off = 0;
    while (i < (s32) this->unk18) {
        if (*(f32 *) ((s8 *) this->unk14 + off + 4) > max) {
            this->unk1C = i;
            max = *(f32 *) ((s8 *) this->unk14 + off + 4);
        }
        i += 1;
        temp_f0 = *(f32 *) ((s8 *) this->unk14 + off + 4);
        off += 8;
        this->unk20 += temp_f0;
    }
}

s32 AnimProperty::LoadLine(MKIniLine *arg0) {
    MKIniLine *line;
    s32 size;
    s32 off;
    void *mem;

    if (arg0->IsField("AnimNames") != 0) {
        line = arg0->unkC->GetSubLine(arg0);
        this->unk18 = arg0->GetNmbrOfSubLines();
        size = this->unk18 * 8;
        if (MKHeap::Current() != NULL) {
            mem = MKHeap::Current()->Alloc(size, NULL, 0);
        } else {
            mem = malloc(size);
        }
        this->unk14 = mem;
        off = 0;
        while (line != NULL) {
            *(s8 **) ((s8 *) this->unk14 + off) = line->GetFieldName();
            *(f32 *) ((s8 *) this->unk14 + off + 4) = line->GetFloat(0);
            off += 8;
            line = line->unkC->GetNextLine(line);
        }
    }
    return 0;
}

void AnimProperty::Init(char *arg0) {
    this->unk4 = (signed char *) (arg0);
    this->unk10 = NULL;
    this->unk14 = NULL;
    this->unk18 = 0;
    this->unk20 = 0.0f;
    this->unk1C = 0;
}
