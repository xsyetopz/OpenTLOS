#ifndef SPYRO_SOURCE_TRAINCONTROLLER_H
#define SPYRO_SOURCE_TRAINCONTROLLER_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "spyro/source/EventMessage.h"

class EventMessage;
class MKIniLine;
class MKMessage;
class MKProp;
class MKPropDescriptor;
class MKSceneManager;
class TrainController;
class TrainControllerDescriptor;
class TrainController_cpp;

class TrainController : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~TrainController(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual s32 LoadDone(void);
    virtual void Reset(void);
    virtual void * Update(void);
    virtual void Message(MKMessage *);
    void SetStage(int);
    /* 0x04c */ MKSceneManager* unk4C;
    /* 0x050 */ MKSceneManager* unk50;
    /* 0x054 */ MKSceneManager* unk54;
    /* 0x058 */ MKSceneManager* unk58;
    /* 0x05c */ u32 unk5C;
    /* 0x060 */ f32 unk60;
    /* 0x064 */ EventMessage unk64;
    /* 0x068 */ EventMessage unk68;
    /* 0x06c */ s8 unk6C;
};

class TrainControllerDescriptor : public MKPropDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
};

class TrainController_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline TrainController::~TrainController() {
    if (&this->unk68 != NULL) {
        this->unk68.Deinit();
    }
    if (&this->unk64 != NULL) {
        this->unk64.Deinit();
    }
    if (this != NULL) {
    }
}

#endif  // SPYRO_SOURCE_TRAINCONTROLLER_H
