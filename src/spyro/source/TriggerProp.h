#ifndef SPYRO_SOURCE_TRIGGERPROP_H
#define SPYRO_SOURCE_TRIGGERPROP_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "spyro/source/EventMessage.h"

class EventMessage;
class MKIniLine;
class MKMessage;
class MKProp;
class MKPropDescriptor;
class MKSceneManager;
class TriggerBoxProp;
class TriggerObject;
class TriggerPlaneGroupProp;
class TriggerPlaneGroupPropDescriptor;
class TriggerPlaneProp;
class TriggerPolyProp;
class TriggerProp;
class TriggerPropDescriptor;
class TriggerSphereProp;

class TriggerProp : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~TriggerProp(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    virtual void Enable(void);
    virtual void Disable(void);
    virtual void OnEnter(void);
    virtual void OnExit(void);
    virtual void OnAction(void);
    virtual s32 CheckQueue(void);
    void UpdateActiveList(void);
    void RemoveFromActiveList(TriggerProp *);
    void AddToActiveList(TriggerProp *);
    /* 0x04c */ s16 unk4C;
    /* 0x04e */ u8 pad4E[0x42];
    /* 0x090 */ MKPropDescriptor* unk90;
    /* 0x094 */ TriggerProp* unk94;
    /* 0x098 */ MKPropDescriptor* unk98;
    /* 0x09c */ TriggerProp* unk9C;
    /* 0x0a0 */ s32 unkA0;
    /* 0x0a4 */ f32 unkA4;
    /* 0x0a8 */ TriggerObject* unkA8;
    /* 0x0ac */ EventMessage unkAC;
    /* 0x0b0 */ EventMessage unkB0;
    /* 0x0b4 */ EventMessage unkB4;
    /* 0x0b8 */ u8 padB8[0x4];
    /* 0x0bc */ s32 unkBC;
    /* 0x0c0 */ u8 unkC0;
};

class TriggerBoxProp : public TriggerProp {  // base: ctor/dtor vtable stores
public:
    virtual ~TriggerBoxProp(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
};

class TriggerPlaneGroupProp : public TriggerProp {  // base: ctor/dtor vtable stores
public:
    virtual ~TriggerPlaneGroupProp(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    /* 0x0c1 */ u8 padC1[0xf];
    /* 0x0d0 */ void* unkD0;
};

class TriggerPropDescriptor : public MKPropDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual void Deinit(void);
    /* 0x048 */ u8 pad48[0x18];
    /* 0x060 */ f32 unk60;
    /* 0x064 */ f32 unk64;
    /* 0x068 */ f32 unk68;
    /* 0x06c */ u8 pad6C[0x4];
    /* 0x070 */ f64 unk70;
    /* 0x078 */ f64 unk78;
    /* 0x080 */ s8 unk80;
};

class TriggerPlaneGroupPropDescriptor : public TriggerPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
};

class TriggerPlaneProp : public TriggerProp {  // base: ctor/dtor vtable stores
public:
    virtual ~TriggerPlaneProp(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void Resolve(void);
    TriggerPlaneProp(void);
    /* 0x0c1 */ u8 padC1[0xdf];
    /* 0x1a0 */ MKProp* unk1A0;
    /* 0x1a4 */ MKSceneManager* unk1A4;
};

class TriggerPolyProp : public TriggerProp {  // base: ctor/dtor vtable stores
public:
    virtual ~TriggerPolyProp(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    /* 0x0c1 */ u8 padC1[0xf];
    /* 0x0d0 */ void* unkD0;
};

class TriggerSphereProp : public TriggerProp {  // base: ctor/dtor vtable stores
public:
    virtual ~TriggerSphereProp(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
};

#endif  // SPYRO_SOURCE_TRIGGERPROP_H
