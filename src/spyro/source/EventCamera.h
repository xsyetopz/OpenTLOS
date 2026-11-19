#ifndef SPYRO_SOURCE_EVENTCAMERA_H
#define SPYRO_SOURCE_EVENTCAMERA_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"

class EventCamera;
class EventCameraDescriptor;
class EventCamera_cpp;
class MKIniLine;
class MKMessage;
class MKProp;
class MKPropDescriptor;
class MKSceneManager;
class MKVector3;

class EventCamera : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~EventCamera(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    void CalculateCircleTangent(MKVector3, MKVector3, float);
    void FunctionOff(void);
    void FunctionOn(void);
    void GetSourceStart(void);
    void GetTargetStart(void);
    /* 0x04c */ u8 pad4C[0x4];
    /* 0x050 */ f64 unk50;
    /* 0x058 */ f64 unk58;
    /* 0x060 */ MKVector3 unk60;
    /* 0x070 */ f64 unk70;
    /* 0x078 */ f64 unk78;
    /* 0x080 */ f64 unk80;
    /* 0x088 */ f64 unk88;
    /* 0x090 */ f64 unk90;
    /* 0x098 */ f64 unk98;
    /* 0x0a0 */ f64 unkA0;
    /* 0x0a8 */ f64 unkA8;
    /* 0x0b0 */ void* unkB0;
    /* 0x0b4 */ void* unkB4;
    /* 0x0b8 */ EventCamera* unkB8;
    /* 0x0bc */ f32 unkBC;
    /* 0x0c0 */ f32 unkC0;
    /* 0x0c4 */ f32 unkC4;
    /* 0x0c8 */ f32 unkC8;
    /* 0x0cc */ f32 unkCC;
    /* 0x0d0 */ f32 unkD0;
    /* 0x0d4 */ f32 unkD4;
    /* 0x0d8 */ f32 unkD8;
    /* 0x0dc */ f32 unkDC;
    /* 0x0e0 */ f32 unkE0;
    /* 0x0e4 */ f32 unkE4;
    /* 0x0e8 */ f32 unkE8;
    /* 0x0ec */ f32 unkEC;
    /* 0x0f0 */ MKSceneManager* unkF0;
    /* 0x0f4 */ u8 unkF4;
    /* 0x0f5 */ u8 unkF5;
    /* 0x0f6 */ u8 unkF6;
    /* 0x0f7 */ u8 unkF7;
    /* 0x0f8 */ u8 unkF8;
    /* 0x0f9 */ u8 unkF9;
    /* 0x0fa */ u8 unkFA;
    /* 0x0fb */ u8 unkFB;
    /* 0x0fc */ u8 unkFC;
    /* 0x0fd */ u8 unkFD;
    /* 0x0fe */ u8 unkFE;
    /* 0x0ff */ u8 unkFF;
    /* 0x100 */ u8 unk100;
    /* 0x101 */ u8 unk101;
    /* 0x102 */ u8 unk102;
    /* 0x103 */ u8 unk103;
    /* 0x104 */ u8 unk104;
    /* 0x105 */ u8 pad105[0x3];
    /* 0x108 */ s32 unk108;
};

class EventCameraDescriptor : public MKPropDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
};

class EventCamera_cpp {
public:
    void __sinit(void);
};

EventCamera * EventCamera_GetCurrent(void);
extern s8 EventCamera_bRemainTargetable;
// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline EventCamera::~EventCamera() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_EVENTCAMERA_H
