#include "spyro/source/KDPropEx.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/KDCommonProperties.h"
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDPositionProperty.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

#if 0 // DRAFT: identifier 'pLocalToWorldPropertyName' redeclared was declared as: 'unsigned char[4]' now declared as: 'long *'
static M2C_UNK *pLocalToWorldPropertyName = "localToWorld";
#endif
#if 0 // DRAFT: identifier 'pModelPropertyName' redeclared was declared as: 'unsigned char[4]' now declared as: 'long *'
static M2C_UNK *pModelPropertyName = &.L_8035FAA5;
#endif
#if 0 // DRAFT: identifier 'pAnimScriptPropertyName' redeclared was declared as: 'unsigned char[4]' now declared as: 'long *'
static M2C_UNK *pAnimScriptPropertyName = &.L_8035FAB2;
#endif
#if 0 // DRAFT: declaration syntax error
static M2C_UNK .L_8035FAA5;                         /* unable to generate initializer: unknown type; const */
#endif
#if 0 // DRAFT: declaration syntax error
static M2C_UNK .L_8035FAB2;                         /* unable to generate initializer: unknown type; const */
#endif

void *KDPropEx::Update() {
    KDPropEx *sp8;
    KDPropExDescriptor *desc;
    KDProperty *var_r31;
    void *ret;

    sp8 = *(KDPropEx **) KDProperty::pInstanceMem;
    *(KDPropEx **) KDProperty::pInstanceMem = this;
    desc = checked_cast<KDPropExDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    var_r31 = (KDProperty *) desc->unk74.unk4;
    goto loop_2_cond;
loop_2:
    var_r31->Update();
    checked_cast<KDPropExDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    var_r31 = var_r31->unkC;
loop_2_cond:
    if (var_r31 != NULL) {
        goto loop_2;
    }
    ret = KDProp::Update();
    *(KDPropEx **) KDProperty::pInstanceMem = sp8;
    return ret;
}

#if 0 // DRAFT: ')' expected
void KDPropEx::Message(MKMessage *arg0) {
    KDPropEx *sp8;
    KDPropEx *temp_r0_59;
    void *var_r31_64;

    KDProp::Message(arg0);
    temp_r0_59 = (KDPropEx *) (*KDProperty::pInstanceMem);
    *KDProperty::pInstanceMem = (unsigned char) (this);
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
        *KDProperty::pInstanceMem = (unsigned char) (sp8);
    }
}
#endif

f32 KDPropEx::Resolve() {
    KDPropEx *sp8;
    KDPropExDescriptor *desc;
    KDProperty *var_r31;

    MKProp::Resolve();
    sp8 = *(KDPropEx **) KDProperty::pInstanceMem;
    *(KDPropEx **) KDProperty::pInstanceMem = this;
    desc = checked_cast<KDPropExDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    var_r31 = desc->unk74.unk0;
    goto loop_2_cond;
loop_2:
    var_r31->ResolveInstance();
    checked_cast<KDPropExDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    var_r31 = var_r31->unkC;
loop_2_cond:
    if (var_r31 != NULL) {
        goto loop_2;
    }
    *(KDPropEx **) KDProperty::pInstanceMem = sp8;
}

#if 0 // DRAFT: undefined identifier 'P18KDPropExDescriptor'
s32 KDPropEx::LoadDone() {
    KDPropEx *sp8;
    KDPropEx *temp_r3_143;
    s32 temp_r3_161;
    void **temp_r3_156;
    void *var_r31_183;

    KDProp::LoadDone();
    temp_r3_143 = (KDPropEx *) (*KDProperty::pInstanceMem);
    *KDProperty::pInstanceMem = (unsigned char) (this);
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
        *KDProperty::pInstanceMem = (unsigned char) (sp8);
    }
}
#endif

s32 KDPropEx::LoadLine(MKIniLine *arg0) {
    KDPropEx *spC;
    bool sp8;
    KDPropExDescriptor *desc;
    KDProperty *var_r31;

    spC = *(KDPropEx **) KDProperty::pInstanceMem;
    *(KDPropEx **) KDProperty::pInstanceMem = this;
    desc = checked_cast<KDPropExDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    var_r31 = desc->unk74.unk0;
    goto loop_2_cond;
loop_2:
    var_r31->LoadLineInstance(arg0);
    checked_cast<KDPropExDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    var_r31 = var_r31->unkC;
loop_2_cond:
    if (var_r31 != NULL) {
        goto loop_2;
    }
    if (KDProp::LoadLine(arg0) != 0) {
        *(KDPropEx **) KDProperty::pInstanceMem = spC;
        return 1;
    }
    if ((arg0->LoadBool("Collide", &sp8, 0) != 0) && (sp8 == 0)) {
        *(u8 *) ((u8 *) this + 0x74) = 0;
    }
    *(KDPropEx **) KDProperty::pInstanceMem = spC;
    return 0;
}

void KDPropEx::Deinit() {
    KDPropEx *sp8;
    KDPropExDescriptor *desc;
    KDProperty *var_r31;

    sp8 = *(KDPropEx **) KDProperty::pInstanceMem;
    *(KDPropEx **) KDProperty::pInstanceMem = this;
    desc = checked_cast<KDPropExDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    var_r31 = desc->unk74.unk0;
    goto loop_2_cond;
loop_2:
    var_r31->DeinitInstance();
    checked_cast<KDPropExDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    var_r31 = var_r31->unkC;
loop_2_cond:
    if (var_r31 != NULL) {
        goto loop_2;
    }
    *(KDPropEx **) KDProperty::pInstanceMem = sp8;
    KDProp::Deinit();
}

void KDPropEx::Init() {
    KDPropEx *sp8;
    KDPropExDescriptor *desc;
    KDProperty *var_r31;

    KDProp::Init();
    sp8 = *(KDPropEx **) KDProperty::pInstanceMem;
    *(KDPropEx **) KDProperty::pInstanceMem = this;
    desc = checked_cast<KDPropExDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    var_r31 = desc->unk74.unk0;
    goto loop_2_cond;
loop_2:
    var_r31->InitInstance();
    checked_cast<KDPropExDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    var_r31 = var_r31->unkC;
loop_2_cond:
    if (var_r31 != NULL) {
        goto loop_2;
    }
    *(KDPropEx **) KDProperty::pInstanceMem = sp8;
}

void KDPropExDescriptor::Deinit() {
    this->unk74.Deinit();
    KDPropDescriptor::Deinit();
}

#if 0 // DRAFT: undefined identifier '__vptr'
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
        this->unk84 = (unsigned long) (property_cast<KDMessageHandlerProperty *, KDProperty *>(var_r31_395));
        if ((u32) this->unk84 == 0) {
            var_r31_395 = var_r31_395->unkC;
            goto loop_3;
        }
    }
    if ((MKModel *) this->unk2C == NULL) {
        temp_r3_416 = ((KDProperty *(*)(KDMatrixProperty *)) KDMatrixProperty::classInfo.unk4)(&KDMatrixProperty::classInfo);
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

void KDPropExDescriptor::Init() {
    KDProperty *p88;
    KDProperty *p9C;

    KDCommonProperties_RegisterAll((KDPropertyClassRegistry *) KDPropExDescriptor::propertyClassRegistry);
    KDPropDescriptor::Init();
    this->unk74.unk0 = NULL;
    this->unk74.unk4 = NULL;
    this->unk74.unk8 = NULL;
    this->unk74.unkC = 0;
    this->unk74.AllocInstanceMem(this->unk70, 0x40);
    this->unk84 = 0;
    this->unkB0.Init(*(const char **) pLocalToWorldPropertyName);
    this->unkB0.unk8 = 8;
    this->unk74.AddPublished((KDProperty *) &this->unkB0);
    p9C = (KDProperty *) ((u8 *) this + 0x9C);
    p9C->Init(*(const char **) pModelPropertyName);
    p9C->unk8 = 4;
    this->unk74.AddPublished(p9C);
    p88 = (KDProperty *) ((u8 *) this + 0x88);
    p88->Init(*(const char **) pAnimScriptPropertyName);
    p88->unk8 = 0x80;
    this->unk74.AddPublished(p88);
    this->unkC |= 1;
}

void KDPropEx_cpp::__sinit() {
    *KDPropExDescriptor::propertyClassRegistry = 0;
}
