#include "spyro/source/KDPropEx.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "spyro/source/KDCommonProperties.h"
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDProperty.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

#if 0 // DRAFT: identifier 'pLocalToWorldPropertyName' redeclared
static M2C_UNK *pLocalToWorldPropertyName = "localToWorld";
#endif
#if 0 // DRAFT: identifier 'pModelPropertyName' redeclared
static M2C_UNK *pModelPropertyName = &.L_8035FAA5;
#endif
#if 0 // DRAFT: identifier 'pAnimScriptPropertyName' redeclared
static M2C_UNK *pAnimScriptPropertyName = &.L_8035FAB2;
#endif
#if 0 // DRAFT: declaration syntax error
static M2C_UNK .L_8035FAA5;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8035FAB2;                         /* unable to generate initializer: unknown type; const */

void KDPropEx::Update() {
    KDPropEx *sp8;
    KDPropEx *temp_r0_16;
    void *var_r31_21;

    temp_r0_16 = *KDProperty::pInstanceMem;
    *KDProperty::pInstanceMem = this;
    sp8 = temp_r0_16;
    var_r31_21 = M2C_FIELD(checked_cast<KDPropExDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), void **, 0x78);
loop_2:
    if (var_r31_21 != NULL) {
        M2C_FIELD(M2C_FIELD(var_r31_21, void **, 0), M2C_UNK (**)(void *), 0x44)(var_r31_21);
        checked_cast<KDPropExDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        var_r31_21 = M2C_FIELD(var_r31_21, void **, 0xC);
        goto loop_2;
    }
    KDProp::Update();
    if (&sp8 != NULL) {
        *KDProperty::pInstanceMem = sp8;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char' to
void KDPropEx::Message(MKMessage *arg0) {
    KDPropEx *sp8;
    KDPropEx *temp_r0_59;
    void *var_r31_64;

    KDProp::Message(arg0);
    temp_r0_59 = *KDProperty::pInstanceMem;
    *KDProperty::pInstanceMem = this;
    sp8 = temp_r0_59;
    var_r31_64 = M2C_FIELD(checked_cast<KDPropExDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), void **, 0x84);
loop_4:
    if (var_r31_64 != NULL) {
        if ((s32) arg0->unk0 == (s32) M2C_FIELD(var_r31_64, s32 *, 0x1C)) {
            M2C_FIELD(M2C_FIELD(var_r31_64, void **, 0), M2C_UNK (**)(void *, MKMessage *), 0x50)(var_r31_64, arg0);
        }
        var_r31_64 = M2C_FIELD(var_r31_64, void **, 0x20);
        goto loop_4;
    }
    if (&sp8 != NULL) {
        *KDProperty::pInstanceMem = sp8;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char' to
void KDPropEx::Resolve() {
    KDPropEx *sp8;
    KDPropEx *temp_r0_103;
    void *var_r31_108;

    MKProp::Resolve();
    temp_r0_103 = *KDProperty::pInstanceMem;
    *KDProperty::pInstanceMem = this;
    sp8 = temp_r0_103;
    var_r31_108 = M2C_FIELD(checked_cast<KDPropExDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), void **, 0x74);
loop_2:
    if (var_r31_108 != NULL) {
        M2C_FIELD(M2C_FIELD(var_r31_108, void **, 0), M2C_UNK (**)(void *), 0x40)(var_r31_108);
        checked_cast<KDPropExDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        var_r31_108 = M2C_FIELD(var_r31_108, void **, 0xC);
        goto loop_2;
    }
    if (&sp8 != NULL) {
        *KDProperty::pInstanceMem = sp8;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char' to
void KDPropEx::LoadDone() {
    KDPropEx *sp8;
    KDPropEx *temp_r3_143;
    s32 temp_r3_161;
    void **temp_r3_156;
    void *var_r31_183;

    KDProp::LoadDone();
    temp_r3_143 = *KDProperty::pInstanceMem;
    *KDProperty::pInstanceMem = this;
    sp8 = temp_r3_143;
    if ((MKModel *) this->unk4 == NULL) {
        temp_r3_156 = property_cast<KDMatrixProperty *, KDProperty *>(((KDPropertySet *) (checked_cast<P18KDPropExDescriptor))->Find(16MKPropDescriptor>__FP16MKPropDescriptor((MKPropDescriptor *) this->unk0) + 0x74, "ltwm"));
        temp_r3_161 = M2C_FIELD(*temp_r3_156, s32 (**)(), 0x54)();
        M2C_STRUCT_COPY(temp_r3_161, &MKProp::loadInfo, 0x40);
        this->unk8 = M2C_FIELD(*temp_r3_156, void *(**)(void **, s32, s32), 0x54)(temp_r3_156, ((s32) &MKProp::loadInfo - 4) + 0x40, (temp_r3_161 - 4) + 0x40);
    }
    var_r31_183 = M2C_FIELD(checked_cast<KDPropExDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), void **, 0x74);
loop_4:
    if (var_r31_183 != NULL) {
        M2C_FIELD(M2C_FIELD(var_r31_183, void **, 0), M2C_UNK (**)(void *), 0x3C)(var_r31_183);
        checked_cast<KDPropExDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        var_r31_183 = M2C_FIELD(var_r31_183, void **, 0xC);
        goto loop_4;
    }
    if (&sp8 != NULL) {
        *KDProperty::pInstanceMem = sp8;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char' to
s32 KDPropEx::LoadLine(MKIniLine *arg0) {
    KDPropEx *spC;
    u8 sp8;
    KDPropEx *temp_r0_218;
    void *var_r31_223;

    temp_r0_218 = *KDProperty::pInstanceMem;
    *KDProperty::pInstanceMem = this;
    spC = temp_r0_218;
    var_r31_223 = M2C_FIELD(checked_cast<KDPropExDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), void **, 0x74);
loop_2:
    if (var_r31_223 != NULL) {
        M2C_FIELD(M2C_FIELD(var_r31_223, void **, 0), M2C_UNK (**)(void *, MKIniLine *), 0x38)(var_r31_223, arg0);
        checked_cast<KDPropExDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        var_r31_223 = M2C_FIELD(var_r31_223, void **, 0xC);
        goto loop_2;
    }
    if (KDProp::LoadLine(arg0) != 0) {
        if (&spC != NULL) {
            *KDProperty::pInstanceMem = spC;
        }
        return 1;
    }
    if ((arg0->LoadBool("Collide", &sp8, 0) != 0) && (sp8 == 0)) {
        this->unk70.unk4 = 0;
    }
    if (&spC != NULL) {
        *KDProperty::pInstanceMem = spC;
    }
    return 0;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char' to
void KDPropEx::Deinit() {
    KDPropEx *sp8;
    KDPropEx *temp_r0_288;
    void *var_r31_293;

    temp_r0_288 = *KDProperty::pInstanceMem;
    *KDProperty::pInstanceMem = this;
    sp8 = temp_r0_288;
    var_r31_293 = M2C_FIELD(checked_cast<KDPropExDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), void **, 0x74);
loop_2:
    if (var_r31_293 != NULL) {
        M2C_FIELD(M2C_FIELD(var_r31_293, void **, 0), M2C_UNK (**)(void *), 0x34)(var_r31_293);
        checked_cast<KDPropExDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        var_r31_293 = M2C_FIELD(var_r31_293, void **, 0xC);
        goto loop_2;
    }
    if (&sp8 != NULL) {
        *KDProperty::pInstanceMem = sp8;
    }
    KDProp::Deinit();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char' to
void KDPropEx::Init() {
    KDPropEx *sp8;
    KDPropEx *temp_r0_330;
    void *var_r31_335;

    KDProp::Init();
    temp_r0_330 = *KDProperty::pInstanceMem;
    *KDProperty::pInstanceMem = this;
    sp8 = temp_r0_330;
    var_r31_335 = M2C_FIELD(checked_cast<KDPropExDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), void **, 0x74);
loop_2:
    if (var_r31_335 != NULL) {
        M2C_FIELD(M2C_FIELD(var_r31_335, void **, 0), M2C_UNK (**)(void *), 0x30)(var_r31_335);
        checked_cast<KDPropExDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        var_r31_335 = M2C_FIELD(var_r31_335, void **, 0xC);
        goto loop_2;
    }
    if (&sp8 != NULL) {
        *KDProperty::pInstanceMem = sp8;
    }
}
#endif

void KDPropExDescriptor::Deinit() {
    this->unk74.Deinit();
    KDPropDescriptor::Deinit();
}

#if 0 // DRAFT: illegal implicit conversion from 'KDMessageHandlerProperty *' to
void KDPropExDescriptor::LoadDone() {
    KDProperty *temp_r3_416;
    KDProperty *var_r31_395;

    KDPropDescriptor::LoadDone();
    this->unkAC = (s32) this->unk2C;
    this->unk98 = (s32) this->unk34;
    this->unk74.LoadDone();
    var_r31_395 = this->unk74.unk0;
loop_3:
    if (var_r31_395 != NULL) {
        this->unk84 = property_cast<KDMessageHandlerProperty *, KDProperty *>(var_r31_395);
        if ((u32) this->unk84 == 0) {
            var_r31_395 = var_r31_395->unkC;
            goto loop_3;
        }
    }
    if ((MKModel *) this->unk2C == NULL) {
        temp_r3_416 = KDMatrixProperty::classInfo.unk4(&KDMatrixProperty::classInfo);
        M2C_FIELD(temp_r3_416->__vptr, M2C_UNK (**)(void *), 8)"ltwm";
        temp_r3_416->LoadDone();
        temp_r3_416->unk8 = this->unk74.AllocInstanceMem(0x40, 0x40);
        this->unk74.Add(temp_r3_416);
    }
}
#endif

s32 KDPropExDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_455;

    var_r31_455 = 0;
    if ((KDPropDescriptor::LoadLine(arg0) != 0) || (this->unk74.LoadLine(arg0, (KDPropertyClassRegistry *) KDPropExDescriptor::propertyClassRegistry) != 0)) {
        var_r31_455 = 1;
    }
    return var_r31_455;
}

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char[4]' to
void KDPropExDescriptor::Init() {
    KDCommonProperties_RegisterAll((KDPropertyClassRegistry *) KDPropExDescriptor::propertyClassRegistry);
    KDPropDescriptor::Init();
    this->unk74.unk0 = NULL;
    this->unk74.unk4 = NULL;
    this->unk74.unk8 = NULL;
    this->unk74.unkC = 0;
    this->unk74.AllocInstanceMem(this->unk70, 0x40);
    this->unk84 = 0;
    this->unkB0.Init(pLocalToWorldPropertyName);
    this->unkB0.unk8 = 8;
    this->unk74.AddPublished((KDProperty *) &this->unkB0);
    this->unk9C.Init(pModelPropertyName);
    this->unk9C.unk8 = 4;
    this->unk74.AddPublished(&this->unk9C);
    this->unk88.Init(pAnimScriptPropertyName);
    this->unk88.unk8 = 0x80;
    this->unk74.AddPublished(&this->unk88);
    this->unkC |= 1;
}
#endif

void KDPropEx_cpp::__sinit() {
    *KDPropExDescriptor::propertyClassRegistry = 0;
}
