#include "spyro/source/GameProperties.h"
#include "common/Source/MKCollisionManager.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "spyro/source/ControllerRumbleProperty.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/GameCameraMessages.h"
#include "spyro/source/HurtProperty.h"
#include "spyro/source/KDCommonProperties.h"
#include "spyro/source/KDPositionProperty.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/MessageMap.h"
#include "spyro/source/RotateProperty.h"
#include "spyro/source/SwayProperty.h"
#include "spyro/source/WobbleProperty.h"
#include "unplaced_templates.h"
#include "spyro/source/GameEnums.h"
#include "spyro/source/KDProp.h"
#include <m2c_macros.h>

s32 stricmp(s8 *, M2C_UNK *);                       /* extern */
extern void **gMK;
extern f32 gUpdateTimeDelta;
extern M2C_UNK gb;
extern MessageMap globalMessageMap;
#if 0 // DRAFT: undefined identifier 'pInstanceMem'
static MessageHandlerProperty classInfo__22MessageHandlerProperty; /* type too large by 0x18 */
static TimerProperty classInfo__13TimerProperty;    /* type too large by 0x14 */
static CameraShakeProperty classInfo__19CameraShakeProperty; /* type too large by 0xC */
static MessageBroadcasterProperty classInfo__26MessageBroadcasterProperty; /* type too large by 0xC */
static CollisionSphereProperty classInfo__23CollisionSphereProperty; /* type too large by 0x10 */
static EventMessageProperty classInfo__20EventMessageProperty; /* type too large by 4 */

void EventMessageProperty::Command(int arg0) {
    if (arg0 != 1) {
        return;
    }
    ((EventMessage *) (pInstanceMem.__vptr + this->unk8))->Send((MKProp *) pInstanceMem.__vptr);
}
#endif

#if 0 // DRAFT: function call 'stricmp(const char *, const char[5])' does not match
s32 EventMessageProperty::ResolveCommand(const char *arg0) const {
    return stricmp(arg0, "Send") == 0;
}
#endif

#if 0 // DRAFT: identifier 'EventMessageProperty::LoadLineInstance(MKIniLine *)'
u8 EventMessageProperty::LoadLineInstance(MKIniLine *arg0) {
    return (u8) (((EventMessage *) (pInstanceMem.__vptr + this->unk8))->LoadLine(arg0, this->unk10) != 0);
}
#endif

#if 0 // DRAFT: undefined identifier 'pInstanceMem'
void EventMessageProperty::DeinitInstance() {
    ((EventMessage *) (pInstanceMem.__vptr + this->unk8))->Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'pInstanceMem'
void EventMessageProperty::InitInstance() {
    ((EventMessage *) (pInstanceMem.__vptr + this->unk8))->Init();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const char[1]' to
void EventMessageProperty::LoadDone() {
    s8 *var_r0_122;

    if ((s8 *) this->unk10 == NULL) {
        var_r0_122 = this->unk4;
        if (var_r0_122 != NULL) {

        } else {
            var_r0_122 = "";
        }
        this->unk10 = var_r0_122;
    }
}
#endif

#if 0 // DRAFT: identifier 'EventMessageProperty::LoadLine(MKIniLine *)' redeclared
u8 EventMessageProperty::LoadLine(MKIniLine *arg0) {
    return (u8) (arg0->LoadString("eventName", &this->unk10, 0) != 0);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const char *' to
void EventMessageProperty::Init(const char *arg0) {
    this->unk4 = arg0;
    this->unk10 = NULL;
}
#endif

#if 0 // DRAFT: undefined identifier 'pInstanceMem'
void CollisionSphereProperty::Command(int arg0) {
    switch (arg0) {                                 /* irregular */
    case 1:
        M2C_FIELD(*(pInstanceMem.__vptr + this->unk8), s8 *, 4) = 1;
        return;
    case 2:
        M2C_FIELD(*(pInstanceMem.__vptr + this->unk8), s8 *, 4) = 0;
        return;
    }
}
#endif

#if 0 // DRAFT: function call 'stricmp(const char *, const char[9])' does not match
s32 CollisionSphereProperty::ResolveCommand(const char *arg0) const {
    s32 temp_r3_213;

    if (stricmp(arg0, "Activate") == 0) {
        return 1;
    }
    temp_r3_213 = stricmp(arg0, "Deactivate") - 1;
    return 2 & ((temp_r3_213 - temp_r3_213) - !M2C_CARRY);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
void CollisionSphereProperty::Resolve(KDPropertySet *arg0) {
    s8 *temp_r0_233;

    temp_r0_233 = this->unk10;
    if (temp_r0_233 != NULL) {
        this->unk10 = property_cast<KDPositionProperty *, KDProperty *>(arg0->Find(temp_r0_233));
    }
}
#endif

#if 0 // DRAFT: function call 'KDProp_LoadMaterialID(MKIniLine *, const char[11], long *)'
s32 CollisionSphereProperty::LoadLine(MKIniLine *arg0) {
    s32 var_r31_261;

    var_r31_261 = 0;
    if ((arg0->LoadFloat("CollisionRadius", &this->unk14, 0) != 0) || (arg0->LoadFloat("YOffset", &this->unk18, 0) != 0) || (KDProp_LoadMaterialID(arg0, "MaterialID", (s32 *) &this->unk1C) != 0) || (arg0->LoadString("origin", &this->unk10, 0) != 0)) {
        var_r31_261 = 1;
    }
    return var_r31_261;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const char *' to
void CollisionSphereProperty::Init(const char *arg0) {
    this->unk4 = arg0;
    this->unk14 = 0.0f;
    this->unk18 = 0.0f;
    this->unk1C = 0;
    this->unk10 = "localToWorld";
}
#endif

#if 0 // DRAFT: undefined identifier 'pInstanceMem'
void CollisionSphereProperty::ResolveInstance() {
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    M2C_UNK var_r28_329;
    MKVector3 *temp_r31_355;
    s32 temp_r30_341;
    s8 *temp_r3_350;
    void *temp_r29_330;

    var_r28_329 = 1;
    temp_r29_330 = pInstanceMem.__vptr;
    if (M2C_FIELD(temp_r29_330, s32 *, 0x10) & 1) {
        var_r28_329 = 2;
    }
    if (this->unk14 > 0.0f) {
        temp_r30_341 = this->unk8;
        sp8 = 1.0f;
        spC = 1.0f;
        sp10 = 1.0f;
        sp14 = 1.0f;
        sp18 = (f64) sp8;
        sp20 = (f64) sp10;
        temp_r3_350 = this->unk10;
        temp_r31_355 = M2C_FIELD(*temp_r3_350, MKVector3 *(**)(s8 *, f64), 0x50)(temp_r3_350, (f64) sp8);
        ((MKCollisionManager *) (M2C_FIELD(*gMK, MKCollisionManager *(**)(void **), 0x84)(gMK)))->AddSphere(temp_r31_355, this->unk14, this->unk18, *((MKVector4 *) &sp18), (MKCollisionMode) var_r28_329, *(temp_r29_330 + temp_r30_341), this->unk1C);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'pInstanceMem'
void MessageBroadcasterProperty::Update() {
    s32 spC;
    s8 *sp8;

    if ((u8) *(pInstanceMem.__vptr + this->unk8) != 0) {
        if (this->unk10 == 0.0f) {
            return;
        }
        spC = 0;
        sp8 = this->unk14;
        M2C_FIELD(*gMK, M2C_UNK (**)(void **, s8 **, s32, M2C_UNK, s32, M2C_UNK), 0x94)(gMK, &sp8, this->unk18, 0, M2C_FIELD(pInstanceMem.__vptr, s32 *, 8) + 0x30, 1);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'pInstanceMem'
void MessageBroadcasterProperty::Command(int arg0) {
    s32 spC;
    s8 *sp8;

    switch (arg0) {                                 /* irregular */
    case 1:
        *(pInstanceMem.__vptr + this->unk8) = 1;
        return;
    case 2:
        *(pInstanceMem.__vptr + this->unk8) = 0;
        return;
    case 3:
        spC = 0;
        sp8 = this->unk14;
        M2C_FIELD(*gMK, M2C_UNK (**)(void **, s8 **, s32, M2C_UNK, s32, M2C_UNK, f32), 0x94)(gMK, &sp8, this->unk18, 0, M2C_FIELD(pInstanceMem.__vptr, s32 *, 8) + 0x30, 1, this->unk10);
        return;
    }
}
#endif

#if 0 // DRAFT: function call 'stricmp(const char *, const char[9])' does not match
s32 MessageBroadcasterProperty::ResolveCommand(const char *arg0) const {
    s32 temp_r3_503;

    if (stricmp(arg0, "Activate") == 0) {
        return 1;
    }
    if (stricmp(arg0, "Deactivate") == 0) {
        return 2;
    }
    temp_r3_503 = stricmp(arg0, "Send") - 1;
    return 3 & ((temp_r3_503 - temp_r3_503) - !M2C_CARRY);
}
#endif

#if 0 // DRAFT: function call 'PropTypes_LoadLine(MKIniLine *, const char[12], long *)'
s32 MessageBroadcasterProperty::LoadLine(MKIniLine *arg0) {
    if ((PropTypes_LoadLine(arg0, "MessageMask", &this->unk18) != 0) || (arg0->LoadFloat("Radius", &this->unk10, 0) != 0)) {
        return 1;
    }
    if (arg0->IsField("MessageID") != 0) {
        this->unk14 = globalMessageMap.GetIdFromString(arg0->GetString(0));
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'pInstanceMem'
void MessageBroadcasterProperty::ResolveInstance() {
    *(pInstanceMem.__vptr + this->unk8) = 0;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const char *' to
void MessageBroadcasterProperty::Init(const char *arg0) {
    this->unk4 = arg0;
    this->unk10 = 0.0f;
    this->unk18 = 0;
    this->unk14 = (s8 *)-1;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk4'
void CameraShakeProperty::Command(int arg0) {
    AddCameraTrackedShakePropMessage sp14;
    void *sp10;
    s32 spC;
    s32 sp8;

    switch (arg0) {                                 /* irregular */
    case 1:
        sp14.unk4 = 0;
        sp14.Init((MKProp *) pInstanceMem.__vptr, this->unk10, this->unk14, 1U, this->unk18);
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, AddCameraTrackedShakePropMessage *), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp14);
        return;
    case 2:
        spC = 0;
        sp8 = 0x456;
        sp10 = pInstanceMem.__vptr;
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, M2C_UNK), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp8, 0x456);
        return;
    }
}
#endif

#if 0 // DRAFT: function call 'stricmp(const char *, const char[6])' does not match
s32 CameraShakeProperty::ResolveCommand(const char *arg0) const {
    s32 temp_r3_672;

    if (stricmp(arg0, "start") == 0) {
        return 1;
    }
    temp_r3_672 = stricmp(arg0, "end") - 1;
    return 2 & ((temp_r3_672 - temp_r3_672) - !M2C_CARRY);
}
#endif

s32 CameraShakeProperty::LoadLine(MKIniLine *arg0) {
    s32 var_r31_696;

    var_r31_696 = 0;
    if ((arg0->LoadFloat("range", &this->unk10, 0) != 0) || (arg0->LoadFloat("shake", &this->unk14, 0) != 0) || (arg0->LoadFloat("vibrate", &this->unk18, 0) != 0)) {
        var_r31_696 = 1;
    }
    return var_r31_696;
}

#if 0 // DRAFT: undefined identifier 'pInstanceMem'
void TimerProperty::Command(int arg0) {
    if (arg0 != 1) {
        KDScriptProperty::Command(arg0);
        return;
    }
    *(pInstanceMem.__vptr + (this->unk8 + 4)) = 1;
    *(pInstanceMem.__vptr + this->unk8) = 0.0f;
}
#endif

#if 0 // DRAFT: undefined identifier 'pInstanceMem'
void TimerProperty::Update() {
    void *temp_r4_769;
    void *temp_r5_780;

    temp_r4_769 = pInstanceMem.__vptr + this->unk8;
    if ((u8) M2C_FIELD(temp_r4_769, u8 *, 4) != 0) {
        M2C_FIELD(temp_r4_769, f32 *, 0) = (f32) (M2C_FIELD(temp_r4_769, f32 *, 0) + gUpdateTimeDelta);
        temp_r5_780 = pInstanceMem.__vptr + this->unk8;
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (M2C_FIELD(temp_r5_780, f32 *, 0) == this->unk1C) {
            M2C_FIELD(temp_r5_780, s8 *, 4) = 0;
            KDScriptProperty::Command(1);
        }
    }
}
#endif

s32 TimerProperty::LoadLine(MKIniLine *arg0) {
    s32 var_r31_808;

    var_r31_808 = 1;
    if ((this->unk10.LoadLine(arg0, "script") == 0) && (arg0->LoadFloat("interval", &this->unk1C, 0) == 0)) {
        var_r31_808 = 0;
    }
    return var_r31_808;
}

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
void MessageHandlerProperty::Resolve(KDPropertySet *arg0) {
    s32 var_r4_841;

    KDMessageHandlerProperty::Resolve(arg0);
    var_r4_841 = this->unk1C;
    if ((u32) var_r4_841 != 0U) {

    } else {
        var_r4_841 = (s32) this->unk4;
        if ((u32) var_r4_841 != 0U) {

        } else {
            var_r4_841 = (s32) "";
        }
    }
    this->unk1C = globalMessageMap.GetIdFromString((s8 *) var_r4_841);
}
#endif

#if 0 // DRAFT: undefined identifier 'propertyClassRegistry'
void GameProperties_RegisterAll() {
    KDCommonProperties_RegisterAll((KDPropertyClassRegistry *) &propertyClassRegistry);
    propertyClassRegistry.Add((KDPropertyClassInfo *) &classInfo);
    propertyClassRegistry.Add((KDPropertyClassInfo *) &classInfo.unk10);
    propertyClassRegistry.Add((KDPropertyClassInfo *) &classInfo.unk20);
    propertyClassRegistry.Add(&classInfo + 0x30);
    propertyClassRegistry.Add(&classInfo + 0x40);
    propertyClassRegistry.Add((KDPropertyClassInfo *) (&classInfo + 0x50));
    propertyClassRegistry.Add(&classInfo + 0x60);
    propertyClassRegistry.Add(&classInfo + 0x70);
    propertyClassRegistry.Add(&classInfo + 0x80);
    propertyClassRegistry.Add(&classInfo + 0x90);
    propertyClassRegistry.Add((KDPropertyClassInfo *) (&classInfo + 0xA0));
    propertyClassRegistry.Add(&classInfo + 0xB0);
    propertyClassRegistry.Add(&classInfo + 0xC0);
    propertyClassRegistry.Add(&classInfo + 0xD0);
}
#endif

#if 0 // DRAFT: undefined identifier 'classInfo'
void GameProperties_cpp::__sinit() {
    MessageHandlerProperty *temp_r11_1478;
    MessageHandlerProperty *temp_r15_1528;
    void *temp_r11_1531;
    void *temp_r18_1525;
    void *temp_r21_1522;
    void *temp_r27_1473;
    void *temp_r30_1476;
    void *temp_r3_1537;
    void *temp_r6_1486;
    void *temp_r8_1481;
    void *temp_r8_1534;

    temp_r27_1473 = &classInfo + 0x30;
    temp_r30_1476 = &classInfo + 0x40;
    temp_r11_1478 = &classInfo + 0x50;
    temp_r8_1481 = &classInfo + 0x60;
    temp_r6_1486 = &classInfo + 0x70;
    classInfo.__vptr = "MessageHandler";
    classInfo.unk8 = (s32) &classInfo;
    classInfo.unk4 = (s8 *) &KDPropertyConstructor<MessageHandlerProperty>::Construct;
    classInfo.unk10.unk0 = (s32) "Timer";
    classInfo.unk10.unk8 = (s32) &classInfo;
    classInfo.unk10.unk4 = (KDPropertyCommand *) &KDPropertyConstructor<TimerProperty>::Construct;
    classInfo.unk20 = "CameraShake";
    M2C_FIELD(&classInfo, s32 *, 0x28) = 0;
    M2C_FIELD(&classInfo, void (**)(KDPropertyConstructor<CameraShakeProperty> *), 0x24) = &KDPropertyConstructor<CameraShakeProperty>::Construct;
    M2C_FIELD(&classInfo, void **, 0x30) = (void *) "MessageBroadcaster";
    M2C_FIELD(temp_r27_1473, s32 *, 8) = 0;
    M2C_FIELD(temp_r27_1473, void (**)(KDPropertyConstructor<MessageBroadcasterProperty> *), 4) = &KDPropertyConstructor<MessageBroadcasterProperty>::Construct;
    M2C_FIELD(&classInfo, void **, 0x40) = (void *) "PhrasePlayer";
    M2C_FIELD(temp_r30_1476, s32 *, 8) = 0;
    M2C_FIELD(temp_r30_1476, void (**)(KDPropertyConstructor<PhrasePlayerProperty> *), 4) = &KDPropertyConstructor<PhrasePlayerProperty>::Construct;
    M2C_FIELD(&classInfo, void **, 0x50) = (void *) "Anim";
    temp_r11_1478->unk8 = 0;
    temp_r11_1478->unk4 = (s8 *) &KDPropertyConstructor<AnimProperty>::Construct;
    M2C_FIELD(&classInfo, void **, 0x60) = (void *) "CollisionSphere";
    M2C_FIELD(temp_r8_1481, s32 *, 8) = 0;
    M2C_FIELD(temp_r8_1481, void (**)(KDPropertyConstructor<CollisionSphereProperty> *), 4) = &KDPropertyConstructor<CollisionSphereProperty>::Construct;
    M2C_FIELD(&classInfo, void **, 0x70) = (void *) "Hurt";
    M2C_FIELD(temp_r6_1486, s32 *, 8) = 0;
    M2C_FIELD(temp_r6_1486, HurtProperty *(**)(KDPropertyConstructor<HurtProperty> *), 4) = &KDPropertyConstructor<HurtProperty>::Construct;
    temp_r21_1522 = &classInfo + 0x80;
    temp_r18_1525 = &classInfo + 0x90;
    temp_r15_1528 = &classInfo + 0xA0;
    temp_r11_1531 = &classInfo + 0xB0;
    temp_r8_1534 = &classInfo + 0xC0;
    temp_r3_1537 = &classInfo + 0xD0;
    M2C_FIELD(&classInfo, void **, 0x80) = (void *) "ControllerRumble";
    M2C_FIELD(temp_r21_1522, s32 *, 8) = 0;
    M2C_FIELD(temp_r21_1522, ControllerRumbleProperty *(**)(KDPropertyConstructor<ControllerRumbleProperty> *), 4) = &KDPropertyConstructor<ControllerRumbleProperty>::Construct;
    M2C_FIELD(&classInfo, void **, 0x90) = (void *) "Rotate";
    M2C_FIELD(temp_r18_1525, s32 *, 8) = 0;
    M2C_FIELD(temp_r18_1525, RotateProperty *(**)(KDPropertyConstructor<RotateProperty> *), 4) = &KDPropertyConstructor<RotateProperty>::Construct;
    M2C_FIELD(&classInfo, void **, 0xA0) = (void *) "Bob";
    temp_r15_1528->unk8 = 0;
    temp_r15_1528->unk4 = (s8 *) &KDPropertyConstructor<BobProperty>::Construct;
    M2C_FIELD(&classInfo, void **, 0xB0) = (void *) "Sway";
    M2C_FIELD(temp_r11_1531, s32 *, 8) = 0;
    M2C_FIELD(temp_r11_1531, SwayProperty *(**)(KDPropertyConstructor<SwayProperty> *), 4) = &KDPropertyConstructor<SwayProperty>::Construct;
    M2C_FIELD(&classInfo, void **, 0xC0) = (void *) "Wobble";
    M2C_FIELD(temp_r8_1534, s32 *, 8) = 0;
    M2C_FIELD(temp_r8_1534, WobbleProperty *(**)(KDPropertyConstructor<WobbleProperty> *), 4) = &KDPropertyConstructor<WobbleProperty>::Construct;
    M2C_FIELD(&classInfo, void **, 0xD0) = (void *) "EventMessage";
    M2C_FIELD(temp_r3_1537, s32 *, 8) = 0;
    M2C_FIELD(temp_r3_1537, void (**)(KDPropertyConstructor<EventMessageProperty> *), 4) = &KDPropertyConstructor<EventMessageProperty>::Construct;
}
#endif
