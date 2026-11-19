#include "spyro/source/KDParticleEffects.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDModelProperty.h"
#include "spyro/source/KDParticleEmitter.h"
#include "spyro/source/KDPathProperty.h"
#include "spyro/source/KDProperty.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include <m2c_macros.h>

s32 stricmp(s8 *, s8 *, s8 *);                      /* extern */
extern MKSceneManager *gMK;
u8 classInfo__24KDParticleSystemProperty[0x10];
u8 classInfo__25KDParticleEmitterProperty[0x10];
u8 classInfo__29KDParticleLineEmitterProperty[0x10];
u8 classInfo__28KDParticleBoxEmitterProperty[0x10];

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void KDParticleBoxEmitterProperty::Command(int arg0) {
    f64 sp40;
    M2C_UNK sp10;
    void **temp_r3_127;
    void *temp_r31_133;

    if (arg0 == 3) {
        temp_r3_127 = this->unk20;
        temp_r31_133 = *KDProperty::pInstanceMem + this->unk8;
        M2C_FIELD(*temp_r3_127, M2C_UNK (**)(void **, M2C_UNK *, s32), 0x58)(temp_r3_127, &sp10, *KDProperty::pInstanceMem);
        M2C_FIELD(temp_r31_133, M2C_UNK **, 0x70) = &sp10;
        M2C_FIELD(temp_r31_133, f64 *, 0x18) = sp40;
        M2C_FIELD(temp_r31_133, f64 *, 0x20) = sp48;
        M2C_FIELD(temp_r31_133, f64 **, 0x6C) = &sp40;
        ((KDParticleEmitter *) (*KDProperty::pInstanceMem + this->unk8))->Burst();
        return;
    }
    KDParticleEmitterProperty::Command(arg0);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void KDParticleBoxEmitterProperty::Update() {
    f64 sp40;
    M2C_UNK sp10;
    KDParticleEmitter *temp_r31_172;
    void **temp_r3_176;

    temp_r31_172 = *KDProperty::pInstanceMem + this->unk8;
    if ((u8) temp_r31_172->unk40 != 0) {
        temp_r3_176 = this->unk20;
        M2C_FIELD(*temp_r3_176, M2C_UNK (**)(void **, M2C_UNK *), 0x58)(temp_r3_176, &sp10);
        temp_r31_172->unk70 = &sp10;
        temp_r31_172->unk18 = sp40;
        M2C_FIELD(temp_r31_172, f64 *, 0x20) = sp48;
        temp_r31_172->unk6C = &sp40;
        temp_r31_172->Update();
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void KDParticleBoxEmitterProperty::ResolveInstance() {
    void *temp_r3_215;
    void *temp_r3_223;

    KDParticleEmitterProperty::ResolveInstance();
    temp_r3_215 = *KDProperty::pInstanceMem + (this->unk8 + 0x78);
    M2C_FIELD(temp_r3_215, f64 *, 0) = (f64) this->unk28;
    M2C_FIELD(temp_r3_215, f64 *, 8) = (f64) this->unk30;
    temp_r3_223 = *KDProperty::pInstanceMem + (this->unk8 + 0x88);
    M2C_FIELD(temp_r3_223, f64 *, 0) = (f64) this->unk38;
    M2C_FIELD(temp_r3_223, f64 *, 8) = (f64) this->unk40;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void KDParticleBoxEmitterProperty::InitInstance() {
    M2C_UNK **temp_r5_243;
    MKIniLine *var_r31_259;
    void **temp_r3_254;

    temp_r5_243 = *KDProperty::pInstanceMem + this->unk8;
    if (temp_r5_243 != NULL) {
        *temp_r5_243 = &__vt;
        *temp_r5_243 = &__vt;
    }
    temp_r3_254 = *KDProperty::pInstanceMem + this->unk8;
    M2C_FIELD(*temp_r3_254, M2C_UNK (**)(void **), 8)(temp_r3_254);
    var_r31_259 = this->unk10;
loop_4:
    if (var_r31_259 != NULL) {
        LoadLineInstance(var_r31_259);
        var_r31_259 = var_r31_259->unkC->GetNextLine(var_r31_259);
        goto loop_4;
    }
}
#endif

void KDParticleBoxEmitterProperty::Resolve(KDPropertySet *arg0) {
    KDParticleEmitterProperty::Resolve(arg0);
}

s32 KDParticleBoxEmitterProperty::LoadLine(MKIniLine *arg0) {
    s32 var_r31_307;

    var_r31_307 = 0;
    if ((arg0->LoadVector3("boxv1", (MKVector3 *) &this->unk28, 0) != 0) || (arg0->LoadVector3("boxv2", (MKVector3 *) &this->unk38, 0) != 0) || (KDParticleEmitterProperty::LoadLine(arg0) != 0)) {
        var_r31_307 = 1;
    }
    return var_r31_307;
}

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void KDParticleLineEmitterProperty::Command(int arg0) {
    M2C_UNK sp10;
    void **temp_r3_351;
    void *temp_r31_357;

    if (arg0 == 3) {
        temp_r3_351 = this->unk20;
        temp_r31_357 = *KDProperty::pInstanceMem + this->unk8;
        M2C_FIELD(*temp_r3_351, M2C_UNK (**)(void **, M2C_UNK *, s32), 0x58)(temp_r3_351, &sp10, *KDProperty::pInstanceMem);
        M2C_FIELD(temp_r31_357, M2C_UNK **, 0x70) = &sp10;
        M2C_FIELD(temp_r31_357, f64 *, 0x18) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 0);
        M2C_FIELD(temp_r31_357, f64 *, 0x20) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
        M2C_FIELD(temp_r31_357, MKVector3 **, 0x6C) = &MKVector3::zero;
        ((KDParticleEmitter *) (*KDProperty::pInstanceMem + this->unk8))->Burst();
        return;
    }
    KDParticleEmitterProperty::Command(arg0);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void KDParticleLineEmitterProperty::Update() {
    Matrix sp10;
    KDParticleEmitter *temp_r31_396;
    void **temp_r3_400;

    temp_r31_396 = *KDProperty::pInstanceMem + this->unk8;
    if ((u8) temp_r31_396->unk40 != 0) {
        temp_r3_400 = this->unk20;
        M2C_FIELD(*temp_r3_400, M2C_UNK (**)(void **, Matrix *), 0x58)(temp_r3_400, &sp10);
        temp_r31_396->unk70 = &sp10;
        temp_r31_396->unk18 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
        M2C_FIELD(temp_r31_396, f64 *, 0x20) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
        temp_r31_396->unk6C = &MKVector3::zero;
        temp_r31_396->Update();
    }
}
#endif

#if 0 // DRAFT: pointer/array required
void KDParticleLineEmitterProperty::ResolveInstance() {
    s32 temp_r4_440;
    void *temp_r3_435;

    KDParticleEmitterProperty::ResolveInstance();
    temp_r3_435 = this->unk28;
    if (temp_r3_435 != NULL) {
        temp_r4_440 = *KDProperty::pInstanceMem + M2C_FIELD(temp_r3_435, s32 *, 8);
        if (temp_r4_440 != 0) {
            *(*KDProperty::pInstanceMem + (this->unk8 + 0x78)) = temp_r4_440;
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void KDParticleLineEmitterProperty::InitInstance() {
    M2C_UNK **temp_r5_463;
    MKIniLine *var_r31_479;
    void **temp_r3_474;

    temp_r5_463 = *KDProperty::pInstanceMem + this->unk8;
    if (temp_r5_463 != NULL) {
        *temp_r5_463 = &__vt;
        *temp_r5_463 = &__vt;
    }
    temp_r3_474 = *KDProperty::pInstanceMem + this->unk8;
    M2C_FIELD(*temp_r3_474, M2C_UNK (**)(void **), 8)(temp_r3_474);
    var_r31_479 = this->unk10;
loop_4:
    if (var_r31_479 != NULL) {
        LoadLineInstance(var_r31_479);
        var_r31_479 = var_r31_479->unkC->GetNextLine(var_r31_479);
        goto loop_4;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
void KDParticleLineEmitterProperty::Resolve(KDPropertySet *arg0) {
    s8 *temp_r4_512;

    KDParticleEmitterProperty::Resolve(arg0);
    temp_r4_512 = this->unk24;
    if (temp_r4_512 != NULL) {
        this->unk28 = property_cast<KDPathProperty *, KDProperty *>(arg0->Find(temp_r4_512));
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to
s32 KDParticleLineEmitterProperty::LoadLine(MKIniLine *arg0) {
    s32 var_r31_539;

    var_r31_539 = 0;
    if ((arg0->LoadString("line", &this->unk24, 0) != 0) || (KDParticleEmitterProperty::LoadLine(arg0) != 0)) {
        var_r31_539 = 1;
    }
    return var_r31_539;
}
#endif

#if 0 // DRAFT: pointer/array required
void KDParticleEmitterProperty::Command(int arg0) {
    M2C_UNK sp40;
    M2C_UNK sp10;
    void **temp_r3_601;
    void *temp_r31_607;
    void *temp_r3_596;
    void *temp_r3_629;

    switch (arg0) {                                 /* irregular */
    case 1:
        *(*KDProperty::pInstanceMem + (this->unk8 + 0x40)) = 1;
        return;
    case 2:
        temp_r3_596 = *KDProperty::pInstanceMem + this->unk8;
        M2C_FIELD(temp_r3_596, s8 *, 0x40) = 0;
        M2C_FIELD(temp_r3_596, f32 *, 0x34) = 0.0f;
        return;
    case 3:
        temp_r3_601 = this->unk20;
        temp_r31_607 = *KDProperty::pInstanceMem + this->unk8;
        M2C_FIELD(*temp_r3_601, M2C_UNK (**)(void **, M2C_UNK *, s32), 0x58)(temp_r3_601, &sp10, *KDProperty::pInstanceMem);
        M2C_FIELD(temp_r31_607, M2C_UNK **, 0x70) = &sp10;
        M2C_FIELD(temp_r31_607, M2C_UNK **, 0x6C) = &sp40;
        ((KDParticleEmitter *) (*KDProperty::pInstanceMem + this->unk8))->Burst();
        return;
    case 4:
        ((MKBaseParticleSystem *) (*(*KDProperty::pInstanceMem + (this->unk8 + 0x28))))->DestroyAllParticles();
        temp_r3_629 = *KDProperty::pInstanceMem + this->unk8;
        M2C_FIELD(temp_r3_629, s8 *, 0x40) = 0;
        M2C_FIELD(temp_r3_629, f32 *, 0x34) = 0.0f;
        return;
    }
}
#endif

#if 0 // DRAFT: function call 'stricmp(const char *, const char[9])' does not match
s32 KDParticleEmitterProperty::ResolveCommand(const char *arg0) const {
    s32 temp_r3_684;

    if (stricmp(arg0, "Activate") == 0) {
        return 1;
    }
    if (stricmp(arg0, "Deactivate") == 0) {
        return 2;
    }
    if (stricmp(arg0, "Burst") == 0) {
        return 3;
    }
    temp_r3_684 = stricmp(arg0, "DestroyAll") - 1;
    return 4 & ((temp_r3_684 - temp_r3_684) - !M2C_CARRY);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void KDParticleEmitterProperty::Update() {
    Matrix sp10;
    KDParticleEmitter *temp_r31_708;
    void **temp_r3_720;

    temp_r31_708 = *KDProperty::pInstanceMem + this->unk8;
    if ((u8) temp_r31_708->unk40 != 0) {
        if ((u8) this->unk18->unk18 != 0) {
            sp10.SetIdentity();
        } else {
            temp_r3_720 = this->unk20;
            M2C_FIELD(*temp_r3_720, M2C_UNK (**)(void **, Matrix *), 0x58)(temp_r3_720, &sp10);
        }
        temp_r31_708->unk70 = &sp10;
        temp_r31_708->unk6C = &sp10.unk30;
        temp_r31_708->Update();
    }
}
#endif

#if 0 // DRAFT: pointer/array required
void KDParticleEmitterProperty::ResolveInstance() {
    *(*KDProperty::pInstanceMem + (this->unk8 + 0x28)) = *(*KDProperty::pInstanceMem + this->unk18->unk8);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void KDParticleEmitterProperty::InitInstance() {
    M2C_UNK **temp_r4_765;
    MKIniLine *var_r31_778;
    void **temp_r3_773;

    temp_r4_765 = *KDProperty::pInstanceMem + this->unk8;
    if (temp_r4_765 != NULL) {
        *temp_r4_765 = &__vt;
    }
    temp_r3_773 = *KDProperty::pInstanceMem + this->unk8;
    M2C_FIELD(*temp_r3_773, M2C_UNK (**)(void **), 8)(temp_r3_773);
    var_r31_778 = this->unk10;
loop_4:
    if (var_r31_778 != NULL) {
        LoadLineInstance(var_r31_778);
        var_r31_778 = var_r31_778->unkC->GetNextLine(var_r31_778);
        goto loop_4;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
void KDParticleEmitterProperty::Resolve(KDPropertySet *arg0) {
    s8 *temp_r4_813;
    s8 *temp_r4_824;

    if ((void **) this->unk20 == NULL) {
        temp_r4_813 = this->unk1C;
        if (temp_r4_813 != NULL) {
            this->unk20 = property_cast<KDMatrixProperty *, KDProperty *>(arg0->Find(temp_r4_813));
        }
    }
    if ((KDParticleSystemProperty *) this->unk18 == NULL) {
        temp_r4_824 = this->unk14;
        if (temp_r4_824 != NULL) {
            this->unk18 = property_cast<KDParticleSystemProperty *, KDProperty *>(arg0->Find(temp_r4_824));
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to
s32 KDParticleEmitterProperty::LoadLine(MKIniLine *arg0) {
    u8 var_r31_858;

    if ((MKIniLine *) this->unk10 == NULL) {
        this->unk10 = arg0;
    }
    var_r31_858 = 0;
    if ((arg0->LoadString("particleType", &this->unk14, 0) != 0) || (arg0->LoadString("origin", &this->unk1C, 0) != 0)) {
        var_r31_858 = 1;
    }
    return var_r31_858;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const char[13]' to
KDParticleEmitterProperty::KDParticleEmitterProperty() {
    this->unk4 = NULL;
    this->unkC = NULL;
    this->unk8 = 0;
    this->unk10 = NULL;
    this->unk14 = NULL;
    this->unk18 = NULL;
    this->unk1C = "localToWorld";
    this->unk20 = NULL;
    return this;
}
#endif

#if 0 // DRAFT: pointer/array required
void KDParticleSystemProperty::Command(int arg0) {
    if (arg0 != 1) {
        return;
    }
    ((MKBaseParticleSystem *) (*(*KDProperty::pInstanceMem + this->unk8)))->DestroyAllParticles();
}
#endif

#if 0 // DRAFT: function call 'stricmp(const char *, const char[11], const char[6])' does
s32 KDParticleSystemProperty::ResolveCommand(const char *arg0) const {
    return stricmp(arg0, "DestroyAll", "boxv1") == 0;
}
#endif

#if 0 // DRAFT: pointer/array required
void KDParticleSystemProperty::Update() {
    void **temp_r3_957;

    if ((u8) this->unk18 != 0) {
        temp_r3_957 = this->unk14;
        M2C_FIELD(*temp_r3_957, M2C_UNK (**)(void **, s32), 0x58)(temp_r3_957, *(*KDProperty::pInstanceMem + this->unk8) + 0x60);
    }
}
#endif

#if 0 // DRAFT: pointer/array required
void KDParticleSystemProperty::ResolveInstance() {
    MKHeap **temp_r3_993;
    MKModel *temp_r3_988;
    void **temp_r3_1038;
    void *temp_r31_987;
    void *temp_r3_1005;
    void *temp_r3_1024;
    void *temp_r3_1031;
    void *temp_r4_994;

    temp_r31_987 = *(*KDProperty::pInstanceMem + this->unk8);
    temp_r3_988 = *(*KDProperty::pInstanceMem + M2C_FIELD(this->unk10, s32 *, 8));
    if (temp_r3_988 != NULL) {
        temp_r3_993 = MKModel_GetBoundingVolume(temp_r3_988, (SubObjectType) 0, -1);
        temp_r4_994 = M2C_FIELD(temp_r31_987, void **, 0);
        M2C_FIELD(temp_r4_994, f64 *, 0x60) = (f64) M2C_FIELD(temp_r3_993, f64 *, 0);
        M2C_FIELD(temp_r4_994, f64 *, 0x68) = (f64) M2C_FIELD(temp_r3_993, f64 *, 8);
        M2C_FIELD(temp_r4_994, f64 *, 0x70) = (f64) M2C_FIELD(temp_r3_993, f64 *, 0x10);
        M2C_FIELD(temp_r4_994, f64 *, 0x78) = (f64) M2C_FIELD(temp_r3_993, f64 *, 0x18);
        temp_r3_1005 = M2C_FIELD(temp_r31_987, void **, 0) + 0x60;
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r3, 0x0, qr0 */);
        M2C_FIELD(temp_r3_1005, f32 *, 8) = (f32) (M2C_FIELD(temp_r3_1005, f32 *, 8) * 1.5f);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r3, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        M2C_ERROR(/* unknown instruction: psq_stx $f0, $r3, $r0, 0x0, qr0 */);
        M2C_FIELD(temp_r3_1005, f32 *, 0x18) = (f32) (M2C_FIELD(temp_r3_1005, f32 *, 0x18) * 1.5f);
        M2C_FIELD(temp_r3_1005, f32 *, 0xC) = (f32) (M2C_FIELD(temp_r3_1005, f32 *, 0xC) * 1.5f);
    } else {
        temp_r3_1024 = M2C_FIELD(temp_r31_987, void **, 0);
        M2C_FIELD(temp_r3_1024, f64 *, 0x60) = -500.0f;
        M2C_FIELD(temp_r3_1024, f32 *, 0x64) = -500.0f;
        M2C_FIELD(temp_r3_1024, f64 *, 0x68) = -500.0f;
        temp_r3_1031 = M2C_FIELD(temp_r31_987, void **, 0);
        M2C_FIELD(temp_r3_1031, f64 *, 0x70) = 1000.0f;
        M2C_FIELD(temp_r3_1031, f32 *, 0x74) = 1000.0f;
        M2C_FIELD(temp_r3_1031, f64 *, 0x78) = 1000.0f;
        M2C_FIELD(M2C_FIELD(temp_r31_987, void **, 0), f32 *, 0x6C) = 500.0f;
    }
    temp_r3_1038 = this->unk14;
    M2C_FIELD(temp_r31_987, s32 *, 8) = M2C_FIELD(*temp_r3_1038, s32 (**)(void **), 0x54)(temp_r3_1038);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const char[1]' to
void KDParticleSystemProperty::InitInstance() {
    s32 temp_r30_1061;
    s32 temp_r31_1063;
    s8 *var_r4_1060;

    var_r4_1060 = this->unk4;
    temp_r30_1061 = *KDProperty::pInstanceMem;
    temp_r31_1063 = this->unk8;
    if (var_r4_1060 != NULL) {

    } else {
        var_r4_1060 = "";
    }
    *(temp_r30_1061 + temp_r31_1063) = gMK->CreateProp(var_r4_1060);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
void KDParticleSystemProperty::Resolve(KDPropertySet *arg0) {
    s8 *temp_r4_1090;
    void **temp_r4_1098;

    temp_r4_1090 = this->unk10;
    if (temp_r4_1090 != NULL) {
        this->unk10 = property_cast<KDModelProperty *, KDProperty *>(arg0->Find(temp_r4_1090));
    }
    temp_r4_1098 = this->unk14;
    if (temp_r4_1098 != NULL) {
        this->unk14 = property_cast<KDMatrixProperty *, KDProperty *>(arg0->Find((s8 *) temp_r4_1098));
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to
s32 KDParticleSystemProperty::LoadLine(MKIniLine *arg0) {
    u8 var_r31_1125;

    var_r31_1125 = 0;
    if ((arg0->LoadString("model", &this->unk10, 0) != 0) || (arg0->LoadString("origin", (s8 **) &this->unk14, 0) != 0) || (arg0->LoadBool("localParticles", &this->unk18, 0) != 0)) {
        var_r31_1125 = 1;
    }
    return var_r31_1125;
}
#endif

void KDParticleEffects_RegisterAll(KDPropertyClassRegistry *arg0) {
    arg0->Add((KDPropertyClassInfo *) KDParticleSystemProperty::classInfo);
    arg0->Add((KDPropertyClassInfo *) (KDParticleSystemProperty::classInfo + 0x10));
    arg0->Add((KDPropertyClassInfo *) (KDParticleSystemProperty::classInfo + 0x20));
    arg0->Add((KDPropertyClassInfo *) (KDParticleSystemProperty::classInfo + 0x30));
}

/* KDPropertyConstructor<KDParticleBoxEmitterProperty>::Construct (void) */

#if 0 // DRAFT: illegal implicit conversion from 'const char[17]' to
void KDParticleEffects_cpp::__sinit() {
    u8 *temp_r10_1452;
    u8 *temp_r4_1456;
    u8 *temp_r7_1454;

    temp_r10_1452 = KDParticleSystemProperty::classInfo + 0x10;
    temp_r7_1454 = KDParticleSystemProperty::classInfo + 0x20;
    temp_r4_1456 = KDParticleSystemProperty::classInfo + 0x30;
    M2C_FIELD(KDParticleSystemProperty::classInfo, s8 **, 0) = "KDParticleSystem";
    M2C_FIELD(KDParticleSystemProperty::classInfo, s32 *, 8) = 0;
    M2C_FIELD(KDParticleSystemProperty::classInfo, void (**)(KDPropertyConstructor<KDParticleSystemProperty> *), 4) = &KDPropertyConstructor<KDParticleSystemProperty>::Construct;
    M2C_FIELD(KDParticleSystemProperty::classInfo, s8 **, 0x10) = "KDParticleEmitter";
    M2C_FIELD(temp_r10_1452, s32 *, 8) = 0;
    M2C_FIELD(temp_r10_1452, KDParticleEmitterProperty *(**)(KDPropertyConstructor<KDParticleEmitterProperty> *), 4) = &KDPropertyConstructor<KDParticleEmitterProperty>::Construct;
    M2C_FIELD(KDParticleSystemProperty::classInfo, s8 **, 0x20) = "KDParticleLineEmitter";
    M2C_FIELD(temp_r7_1454, u8 **, 8) = temp_r10_1452;
    M2C_FIELD(temp_r7_1454, void *(**)(KDPropertyConstructor<KDParticleLineEmitterProperty> *), 4) = &KDPropertyConstructor<KDParticleLineEmitterProperty>::Construct;
    M2C_FIELD(KDParticleSystemProperty::classInfo, s8 **, 0x30) = "KDParticleBoxEmitter";
    M2C_FIELD(temp_r4_1456, u8 **, 8) = temp_r10_1452;
    M2C_FIELD(temp_r4_1456, struct __vt **(**)(KDPropertyConstructor<KDParticleBoxEmitterProperty> *), 4) = &KDPropertyConstructor<KDParticleBoxEmitterProperty>::Construct;
}
#endif
