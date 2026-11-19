#include "spyro/source/KDProperty.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Level.h"
#include <m2c_macros.h>

M2C_UNK free(KDPropertyCommand *);                  /* extern */
KDPropertyCommand *malloc(s32);                     /* extern */
s32 stricmp(s8 *, s8 *, s8 *);                      /* extern */
u8 classInfo__16KDScriptProperty[0x10];

void KDScriptProperty::Command(int arg0) {
    KDPropertyCommand **var_r31_100;
    KDPropertyCommand *temp_r3_106;
    s32 temp_r0_112;
    u8 var_r5_113;

    if (arg0 != 1) {
        return;
    }
    if ((s32) this->unk10.unk0 == 1) {
        var_r31_100 = &this->unk10.unk4;
    } else {
        var_r31_100 = &this->unk10.unk4->unk0;
    }
loop_11:
    if (var_r31_100 != NULL) {
        temp_r3_106 = M2C_FIELD(var_r31_100, KDPropertyCommand **, 0);
        M2C_FIELD(temp_r3_106->unk0, M2C_UNK (**)(KDPropertyCommand *, s32), 0x48)(temp_r3_106, M2C_FIELD(var_r31_100, s32 *, 4));
        temp_r0_112 = this->unk10.unk0;
        var_r5_113 = 0;
        if ((temp_r0_112 > 1) && ((KDPropertyCommand **) (var_r31_100 + 8) < (void *) (this->unk10.unk4 + (temp_r0_112 * 8)))) {
            var_r5_113 = 1;
        }
        if (var_r5_113 != 0) {
            var_r31_100 += 8;
        } else {
            var_r31_100 = NULL;
        }
        goto loop_11;
    }
}

#if 0 // DRAFT: function call 'stricmp(const char *, const char[8], const char[7])' does
s32 KDScriptProperty::ResolveCommand(const char *arg0) const {
    return stricmp(arg0, "Trigger", "script") == 0;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
u8 KDPropertyCommandList::LoadLine(MKIniLine *arg0, const char *arg1) {
    KDPropertyCommand **var_r0_203;
    KDPropertyCommand **var_r0_236;
    KDPropertyCommand **var_r29_208;
    KDPropertyCommand *var_r3_189;
    MKHeap *temp_r3_182;
    MKIniLine *var_r30_200;
    s32 temp_r0_178;
    s32 temp_r0_221;
    s32 temp_r30_181;
    s32 temp_r3_176;
    u8 var_r5_222;

    if (arg0->IsField(arg1) != 0) {
        temp_r3_176 = arg0->GetNmbrOfSubLines();
        this->unk0 = temp_r3_176;
        temp_r0_178 = this->unk0;
        if (temp_r0_178 > 1) {
            temp_r30_181 = temp_r0_178 * 8;
            temp_r3_182 = ((MKHeap *) temp_r3_176)->Current();
            if (temp_r3_182 != NULL) {
                var_r3_189 = ((MKHeap *) (temp_r3_182->Current()))->Alloc(temp_r30_181, NULL, 0);
            } else {
                var_r3_189 = malloc(temp_r30_181);
            }
            this->unk4 = var_r3_189;
            var_r30_200 = arg0->unkC->GetSubLine(arg0);
            if ((s32) this->unk0 == 1) {
                var_r0_203 = &this->unk4;
            } else {
                var_r0_203 = &this->unk4->unk0;
            }
            var_r29_208 = var_r0_203;
loop_16:
            if (var_r30_200 != NULL) {
                M2C_FIELD(var_r29_208, KDPropertyCommand **, 0) = NULL;
                M2C_FIELD(var_r29_208, s32 *, 4) = 0;
                ((KDPropertyCommand *) var_r29_208)->LoadLine(var_r30_200, NULL);
                temp_r0_221 = this->unk0;
                var_r5_222 = 0;
                var_r30_200 = var_r30_200->unkC->GetNextLine(var_r30_200);
                if ((temp_r0_221 > 1) && ((KDPropertyCommand **) (var_r29_208 + 8) < (void *) (this->unk4 + (temp_r0_221 * 8)))) {
                    var_r5_222 = 1;
                }
                if (var_r5_222 != 0) {
                    var_r0_236 = var_r29_208 + 8;
                } else {
                    var_r0_236 = NULL;
                }
                var_r29_208 = var_r0_236;
                goto loop_16;
            }
        } else {
            this->unk4 = NULL;
            this->unk8 = 0;
            if ((s32) this->unk0 == 0) {
                ((KDPropertyCommand *) &this->unk4)->LoadLine(arg0, arg1);
            } else {
                ((KDPropertyCommand *) &this->unk4)->LoadLine(arg0->unkC->GetSubLine(arg0), NULL);
            }
            this->unk0 = 1;
        }
        return 1U;
    }
    return 0U;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void KDPropertyCommandList::Deinit() {
    KDPropertyCommand *temp_r31_290;
    MKHeap *temp_r3_296;

    temp_r31_290 = this->unk4;
    if ((temp_r31_290 != NULL) && ((s32) this->unk0 > 1)) {
        temp_r3_296 = MKHeap::Current();
        if (temp_r3_296 != NULL) {
            ((MKHeap *) (temp_r3_296->Current()))->Free(temp_r31_290, NULL, 0);
        } else {
            free(temp_r31_290);
        }
    }
    this->unk4 = NULL;
    this->unk0 = 0;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
void KDPropertyCommand::Resolve(KDPropertySet *arg0) {
    KDPropertyCommand *temp_r0_327;
    KDPropertyCommand *temp_r3_335;

    temp_r0_327 = this->unk0;
    if (temp_r0_327 != NULL) {
        this->unk0 = arg0->Find((s8 *) temp_r0_327);
    }
    temp_r3_335 = this->unk0;
    if ((temp_r3_335 != NULL) && ((u32) this->unk4 != 0U)) {
        this->unk4 = M2C_FIELD(temp_r3_335->unk0, s32 (**)(), 0x24)();
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
s32 KDPropertyCommand::LoadLine(MKIniLine *arg0, const char *arg1) {
    if (arg1 != NULL) {
        if (arg0->IsField(arg1) == 0) {
            return 0;
        }
        this->unk0 = arg0->GetString(0);
        goto block_5;
    }
    this->unk0 = arg0->GetFieldName();
block_5:
    this->unk4 = arg0->GetString(arg1 != NULL);
    return 1;
}
#endif

#if 0 // DRAFT: function call 'stricmp(signed char *, const char *)' does not match
KDPropertyClassInfo *KDPropertyClassRegistry::Find(const char *arg0) {
    KDPropertyClassInfo *var_r31_409;

    if (arg0 == NULL) {
        return NULL;
    }
    var_r31_409 = this->unk0;
loop_6:
    if (var_r31_409 == NULL) {
        return NULL;
    }
    if (stricmp(var_r31_409->unk0, arg0) == 0) {
        return var_r31_409;
    }
    var_r31_409 = var_r31_409->unkC;
    goto loop_6;
}
#endif

void KDPropertyClassRegistry::Add(KDPropertyClassInfo *arg0) {
    KDPropertyClassInfo *temp_r5_442;
    KDPropertyClassRegistry *var_r3_0;

    var_r3_0 = this;
loop_3:
    temp_r5_442 = var_r3_0->unk0;
    if (temp_r5_442 == NULL) {
        var_r3_0->unk0 = arg0;
        return;
    }
    if (temp_r5_442 != arg0) {
        var_r3_0 = (KDPropertyClassRegistry *) &temp_r5_442->unkC;
        goto loop_3;
    }
}

#if 0 // DRAFT: function call 'stricmp(signed char *, const char *)' does not match
KDPropertyCommand *KDPropertySet::Find(const char *arg0) {
    KDProperty *var_r30_460;
    KDPropertyCommand *var_r30_482;
    s32 var_r3_486;
    s8 *var_r3_463;

    var_r30_460 = this->unk0;
loop_7:
    if (var_r30_460 == NULL) {
        var_r30_482 = this->unk8;
loop_15:
        if (var_r30_482 == NULL) {
            return NULL;
        }
        var_r3_486 = var_r30_482->unk4;
        if ((u32) var_r3_486 != 0U) {

        } else {
            var_r3_486 = (s32) "";
        }
        if (stricmp((s8 *) var_r3_486, arg0) == 0) {
            return var_r30_482;
        }
        var_r30_482 = var_r30_482->unkC;
        goto loop_15;
    }
    var_r3_463 = var_r30_460->unk4;
    if (var_r3_463 != NULL) {

    } else {
        var_r3_463 = "";
    }
    if (stricmp(var_r3_463, arg0) == 0) {
        return (KDPropertyCommand *) var_r30_460;
    }
    var_r30_460 = var_r30_460->unkC;
    goto loop_7;
}
#endif

s32 KDPropertySet::AllocInstanceMem(int arg0, int arg1) {
    s32 temp_r5_523;
    s32 temp_r6_517;

    temp_r6_517 = arg1 - 1;
    this->unkC = ~(temp_r6_517 | temp_r6_517) & ((arg1 + this->unkC) - 1);
    temp_r5_523 = this->unkC;
    this->unkC = temp_r5_523 + arg0;
    return temp_r5_523;
}

void KDPropertySet::LoadDone() {
    KDProperty *var_r31_538;
    KDProperty *var_r31_563;
    s32 temp_r30_549;

    var_r31_538 = this->unk0;
loop_2:
    if (var_r31_538 != NULL) {
        temp_r30_549 = var_r31_538->GetInstanceDataSize();
        var_r31_538->unk8 = AllocInstanceMem(temp_r30_549, var_r31_538->GetInstanceDataAlignment());
        var_r31_538 = var_r31_538->unkC;
        goto loop_2;
    }
    var_r31_563 = this->unk0;
loop_5:
    if (var_r31_563 != NULL) {
        var_r31_563->Resolve(this);
        var_r31_563 = var_r31_563->unkC;
        goto loop_5;
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
s32 KDPropertySet::LoadLine(MKIniLine *arg0, KDPropertyClassRegistry *arg1) {
    KDProperty *temp_r31_610;
    KDPropertyClassInfo *temp_r3_604;
    MKIniLine *var_r30_623;
    s8 *temp_r3_594;

    temp_r3_594 = arg0->GetFieldName();
    if ((s32) *temp_r3_594 != 0x2A) {
        return 0;
    }
    temp_r3_604 = arg1->Find(&temp_r3_594[1]);
    if (temp_r3_604 != NULL) {
        temp_r31_610 = temp_r3_604->unk4();
        temp_r31_610->Init(arg0->GetString(0));
        var_r30_623 = arg0->unkC->GetSubLine(arg0);
loop_5:
        if (var_r30_623 != NULL) {
            temp_r31_610->LoadLine(var_r30_623);
            var_r30_623 = var_r30_623->unkC->GetNextLine(var_r30_623);
            goto loop_5;
        }
        temp_r31_610->LoadDone();
        Add(temp_r31_610);
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: type mismatch
void KDPropertySet::Remove(KDProperty *arg0) {
    KDProperty *temp_r5_679;
    KDPropertySet *var_r3_0;

    var_r3_0 = this;
    if ((KDPropertyCommand *) var_r3_0->unk4 == arg0) {
        var_r3_0->unk4 = (KDPropertyCommand *) arg0->unkC;
    }
loop_5:
    temp_r5_679 = var_r3_0->unk0;
    if (temp_r5_679 == NULL) {
        return;
    }
    if (temp_r5_679 == arg0) {
        var_r3_0->unk0 = arg0->unkC;
        arg0->unkC = NULL;
        return;
    }
    var_r3_0 = (KDPropertySet *) &temp_r5_679->unkC;
    goto loop_5;
}
#endif

void KDPropertySet::AddPublished(KDProperty *arg0) {
    arg0->unkC = (KDProperty *) this->unk8;
    this->unk8 = (KDPropertyCommand *) arg0;
}

#if 0 // DRAFT: type mismatch
void KDPropertySet::Add(KDProperty *arg0) {
    KDProperty *temp_r3_717;
    KDPropertySet *var_r4_712;

    if (arg0->Query(1) != 0) {
        var_r4_712 = this;
loop_3:
        temp_r3_717 = var_r4_712->unk0;
        if (temp_r3_717 != (KDPropertyCommand *) this->unk4) {
            var_r4_712 = (KDPropertySet *) &temp_r3_717->unkC;
            goto loop_3;
        }
        var_r4_712->unk0 = arg0;
        arg0->unkC = (KDProperty *) this->unk4;
        this->unk4 = (KDPropertyCommand *) arg0;
        return;
    }
    arg0->unkC = this->unk0;
    this->unk0 = arg0;
}
#endif

void KDPropertySet::Deinit() {
    KDProperty *var_r31_745;

    var_r31_745 = this->unk0;
loop_2:
    if (var_r31_745 != NULL) {
        Remove(var_r31_745);
        var_r31_745->Deinit();
        operator delete(var_r31_745);
        var_r31_745 = this->unk0;
        goto loop_2;
    }
}

s32 KDProperty::IsOfType(KDPropertyClassInfo *arg0) const {
    void *var_r3_780;

    var_r3_780 = GetClassInfo();
loop_4:
    if (var_r3_780 == NULL) {
        return 0;
    }
    if (var_r3_780 == arg0) {
        return 1;
    }
    var_r3_780 = M2C_FIELD(var_r3_780, void **, 8);
    goto loop_4;
}

#if 0 // DRAFT: illegal implicit conversion from 'const char[9]' to
void KDProperty_cpp::__sinit() {
    M2C_FIELD(KDScriptProperty::classInfo, s8 **, 0) = "KDScript";
    M2C_FIELD(KDScriptProperty::classInfo, s32 *, 8) = 0;
    M2C_FIELD(KDScriptProperty::classInfo, void (**)(KDPropertyConstructor<KDScriptProperty> *), 4) = &KDPropertyConstructor<KDScriptProperty>::Construct;
}
#endif
