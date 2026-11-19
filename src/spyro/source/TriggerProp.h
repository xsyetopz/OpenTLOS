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
    static u8 pFirstActiveTrigger[0x4];
    static u8 pFirstTrigger[0x4];
    /* 0x04c */ s16 unk4C;
    /* 0x04e */ u8 pad4E[0x2];
    /* 0x050 */ u8 unk50;
    /* 0x051 */ u8 pad51[0x3f];
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
    /* 0x0c4 */ u8 padC4[0xc];
    /* 0x0d0 */ void* unkD0;
};

class TriggerPropDescriptor : public MKPropDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual void Deinit(void);
    /* 0x044 */ u8 pad44[0x1c];
    /* 0x060 */ f32 unk60;
    /* 0x064 */ f32 unk64;
    /* 0x068 */ f32 unk68;
    /* 0x06c */ u8 pad6C[0x4];
    /* 0x070 */ f64 unk70;
    /* 0x078 */ f64 unk78;
    /* 0x080 */ s8 unk80;
};

class TriggerPlaneGroupPropDescriptor : public TriggerPropDescriptor {  // base: inlined ctor vtable stores
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
    /* 0x0c4 */ u8 padC4[0xdc];
    /* 0x1a0 */ MKProp* unk1A0;
    /* 0x1a4 */ MKSceneManager* unk1A4;
};

class TriggerPolyProp : public TriggerProp {  // base: ctor/dtor vtable stores
public:
    virtual ~TriggerPolyProp(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    /* 0x0c4 */ u8 padC4[0xc];
    /* 0x0d0 */ void* unkD0;
};

class TriggerSphereProp : public TriggerProp {  // base: ctor/dtor vtable stores
public:
    virtual ~TriggerSphereProp(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline TriggerBoxProp::~TriggerBoxProp() {
    s32 temp_cr0_eq_12475;

    temp_cr0_eq_12475 = this == NULL;
    if (temp_cr0_eq_12475 == 0) {
        if (temp_cr0_eq_12475 == 0) {
            if (&this->unkB4 != NULL) {
                this->unkB4.Deinit();
            }
            if (&this->unkB0 != NULL) {
                this->unkB0.Deinit();
            }
            if (&this->unkAC != NULL) {
                this->unkAC.Deinit();
            }
            if (this != NULL) {
            }
        }
    }
}

inline TriggerPlaneGroupProp::~TriggerPlaneGroupProp() {
    s32 temp_cr0_eq_1506;

    temp_cr0_eq_1506 = this == NULL;
    if (temp_cr0_eq_1506 == 0) {
        if (temp_cr0_eq_1506 == 0) {
            if (&this->unkB4 != NULL) {
                this->unkB4.Deinit();
            }
            if (&this->unkB0 != NULL) {
                this->unkB0.Deinit();
            }
            if (&this->unkAC != NULL) {
                this->unkAC.Deinit();
            }
            if (this != NULL) {
            }
        }
    }
}

#if 0 // DRAFT: undefined identifier 'unkD0'
inline TriggerPlaneProp::TriggerPlaneProp() {
    this->unkAC.unk0 = 0;
    this->unkAC.Init();
    this->unkB0.unk0 = 0;
    this->unkB0.Init();
    this->unkB4.unk0 = 0;
    this->unkB4.Init();
    this->unkD0 = &__vt;
    this->unkD0 = &__vt;
    this->unkD0 = &__vt;
    return this;
}
#endif

inline TriggerPlaneProp::~TriggerPlaneProp() {
    s32 temp_cr0_eq_1557;

    temp_cr0_eq_1557 = this == NULL;
    if (temp_cr0_eq_1557 == 0) {
        if (temp_cr0_eq_1557 == 0) {
            if (&this->unkB4 != NULL) {
                this->unkB4.Deinit();
            }
            if (&this->unkB0 != NULL) {
                this->unkB0.Deinit();
            }
            if (&this->unkAC != NULL) {
                this->unkAC.Deinit();
            }
            if (this != NULL) {
            }
        }
    }
}

inline TriggerPolyProp::~TriggerPolyProp() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
            if (&this->unkB4 != NULL) {
                this->unkB4.Deinit();
            }
            if (&this->unkB0 != NULL) {
                this->unkB0.Deinit();
            }
            if (&this->unkAC != NULL) {
                this->unkAC.Deinit();
            }
            if (this != NULL) {
            }
        }
    }
}

inline TriggerProp::~TriggerProp() {
    if (&this->unkB4 != NULL) {
        this->unkB4.Deinit();
    }
    if (&this->unkB0 != NULL) {
        this->unkB0.Deinit();
    }
    if (&this->unkAC != NULL) {
        this->unkAC.Deinit();
    }
    if (this != NULL) {
    }
}

inline TriggerSphereProp::~TriggerSphereProp() {
    s32 temp_cr0_eq_1608;

    temp_cr0_eq_1608 = this == NULL;
    if (temp_cr0_eq_1608 == 0) {
        if (temp_cr0_eq_1608 == 0) {
            if (&this->unkB4 != NULL) {
                this->unkB4.Deinit();
            }
            if (&this->unkB0 != NULL) {
                this->unkB0.Deinit();
            }
            if (&this->unkAC != NULL) {
                this->unkAC.Deinit();
            }
            if (this != NULL) {
            }
        }
    }
}

#endif  // SPYRO_SOURCE_TRIGGERPROP_H
