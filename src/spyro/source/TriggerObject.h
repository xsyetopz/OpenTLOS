#ifndef SPYRO_SOURCE_TRIGGEROBJECT_H
#define SPYRO_SOURCE_TRIGGEROBJECT_H

#include <dolphin/types.h>
#include "common/Source/Matrix.h"
#include "spyro/source/BoundingRegion.h"

class BoundingRegion;
class MKIniLine;
class MKMessage;
class MKSceneManager;
class MKVector3;
class Matrix;
class TriggerBoxObject;
class TriggerObject;
class TriggerObject_cpp;
class TriggerPlaneGroupObject;
class TriggerPlaneObject;
class TriggerPolyObject;
class TriggerSphereObject;

class TriggerObject {
public:
    virtual void Init(void);
    virtual void Deinit(void);
    virtual u8 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Reset(void);
    virtual void Message(MKMessage *);
    virtual void Resolve(void);
    virtual u16 Update(void);
    virtual void SetPos(const MKVector3 &);
    virtual void SetPos(const Matrix &);
    virtual s32 CheckPos(const MKVector3 &) = 0;
    virtual s32 CheckTarget(void) = 0;
    void EnableTrigger(bool);
    /* 0x004 */ u8 pad4[0xc];
    /* 0x010 */ Matrix unk10;
    /* 0x050 */ s32 unk50;
    /* 0x054 */ s32 unk54;
    /* 0x058 */ u8 pad58[0x8];
    /* 0x060 */ f32 unk60;
    /* 0x064 */ f32 unk64;
    /* 0x068 */ f32 unk68;
    /* 0x06c */ u8 pad6C[0x4];
    /* 0x070 */ f32 unk70;
    /* 0x074 */ f32 unk74;
    /* 0x078 */ f32 unk78;
};

class TriggerBoxObject : public TriggerObject {  // base: ctor/dtor vtable stores
public:
    virtual void LoadDone(void);
    virtual void SetPos(const MKVector3 &);
    virtual void SetPos(const Matrix &);
    virtual s32 CheckPos(const MKVector3 &);
    virtual s32 CheckTarget(void);
    virtual s32 LoadLine(char *, MKIniLine *);
    virtual void LoadDone(const MKVector3 &, const Matrix &);
    static u8 tempBoxRot[0x10];
    /* 0x004 */ u8 pad4[0xc];
    /* 0x010 */ Matrix unk10;
    /* 0x050 */ s32 unk50;
    /* 0x054 */ MKSceneManager* unk54;
    /* 0x058 */ u8 pad58[0x8];
    /* 0x060 */ f32 unk60;
    /* 0x064 */ f32 unk64;
    /* 0x068 */ f32 unk68;
    /* 0x06c */ u8 pad6C[0x4];
    /* 0x070 */ f32 unk70;
    /* 0x074 */ f32 unk74;
    /* 0x078 */ f32 unk78;
    /* 0x07c */ u8 pad7C[0x4];
    /* 0x080 */ f32 unk80;
    /* 0x084 */ f32 unk84;
    /* 0x088 */ f32 unk88;
    /* 0x08c */ u8 pad8C[0x4];
    /* 0x090 */ f32 unk90;
    /* 0x094 */ f32 unk94;
    /* 0x098 */ f32 unk98;
    /* 0x09c */ u8 pad9C[0x4];
    /* 0x0a0 */ f32 unkA0;
    /* 0x0a4 */ f32 unkA4;
    /* 0x0a8 */ f32 unkA8;
    /* 0x0ac */ u8 padAC[0x4];
    /* 0x0b0 */ f32 unkB0;
    /* 0x0b4 */ f32 unkB4;
    /* 0x0b8 */ f32 unkB8;
};

class TriggerObject_cpp {
public:
    void __sinit(void);
};

class TriggerPlaneGroupObject : public TriggerObject {  // base: vtable prefix
public:
    virtual void Deinit(void);
    virtual void LoadDone(void);
    virtual s32 CheckPos(const MKVector3 &);
    virtual s32 CheckTarget(void);
    s32 AddPlane(TriggerPlaneObject *);
    /* 0x004 */ u8 pad4[0x4c];
    /* 0x050 */ s32 unk50;
    /* 0x054 */ MKSceneManager* unk54;
    /* 0x058 */ u8 pad58[0x28];
    /* 0x080 */ TriggerPlaneObject*** unk80;
    /* 0x084 */ u8 unk84;
};

class TriggerPlaneObject : public TriggerBoxObject {  // base: ctor/dtor vtable stores
public:
    virtual void LoadDone(void);
    /* 0x004 */ u8 pad4[0x2c];
    /* 0x030 */ f32 unk30;
    /* 0x034 */ f32 unk34;
    /* 0x038 */ f32 unk38;
    /* 0x03c */ u8 pad3C[0x18];
    /* 0x054 */ MKSceneManager* unk54;
    /* 0x058 */ u8 pad58[0x68];
    /* 0x0c0 */ u8 unkC0;
    /* 0x0c1 */ u8 padC1[0x3];
    /* 0x0c4 */ s32 unkC4;
};

class TriggerPolyObject : public TriggerObject {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void LoadDone(void);
    virtual s32 CheckPos(const MKVector3 &);
    virtual s32 CheckTarget(void);
    virtual s32 LoadLine(char *, MKIniLine *);
    /* 0x004 */ u8 pad4[0x50];
    /* 0x054 */ MKSceneManager* unk54;
    /* 0x058 */ u8 pad58[0x28];
    /* 0x080 */ s32 unk80;
    /* 0x084 */ MKVector3* unk84;
    /* 0x088 */ BoundingRegion unk88;
    /* 0x0a4 */ f32 unkA4;
    /* 0x0a8 */ f32 unkA8;
};

class TriggerSphereObject : public TriggerObject {  // base: vtable prefix
public:
    virtual void LoadDone(void);
    virtual s32 CheckPos(const MKVector3 &);
    virtual s32 CheckTarget(void);
    virtual void Init(float);
    virtual s32 LoadLine(char *, MKIniLine *);
    virtual f32 GetRadiusSquared(void);
    virtual void SetRadius(float);
    /* 0x004 */ u8 pad4[0x3c];
    /* 0x040 */ f64 unk40;
    /* 0x048 */ f64 unk48;
    /* 0x050 */ s32 unk50;
    /* 0x054 */ MKSceneManager* unk54;
    /* 0x058 */ u8 pad58[0x8];
    /* 0x060 */ f32 unk60;
    /* 0x064 */ f32 unk64;
    /* 0x068 */ f32 unk68;
    /* 0x06c */ u8 pad6C[0x4];
    /* 0x070 */ f64 unk70;
    /* 0x078 */ f64 unk78;
    /* 0x080 */ f32 unk80;
};

#endif  // SPYRO_SOURCE_TRIGGEROBJECT_H
