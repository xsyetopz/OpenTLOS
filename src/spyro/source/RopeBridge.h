#ifndef SPYRO_SOURCE_ROPEBRIDGE_H
#define SPYRO_SOURCE_ROPEBRIDGE_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "common/Source/Matrix.h"

class MKCollisionInfo;
class MKIniLine;
class MKMessage;
class MKProp;
class MKPropDescriptor;
class MKVector3;
class Matrix;
class RopeBridge;
class RopeBridgeAttachment;
class RopeBridgeDescriptor;
class RopeBridge_cpp;

class RopeBridge : public MKProp {  // base: ctor/dtor vtable stores
public:
    class BridgePiece {
    public:
        ~BridgePiece(void);
        BridgePiece(void);
    };
    virtual ~RopeBridge(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    void DetachBridgeEnthusiasts(void);
    void FindBrokenPlank(const MKVector3 &);
    void Detach(RopeBridgeAttachment *);
    u8 Attach(RopeBridgeAttachment *, MKCollisionInfo *);
    void UpdatePlanks(int, float, float);
    void UpdatePlankMatrices(void);
    void ApplyForce(const MKVector3 &, const MKVector3 &);
    void HighDetailUpdate(void);
    void LowDetailUpdate(void);
    void BuildBridgeStartPosition(void);
    void SetUpCullingLocalToWorld(void);
    void CalculateTranformationMatrices(void);
    u8 LoadStartAndEnd(MKIniLine *);
    /* 0x04c */ u8 pad4C[0x4];
    /* 0x050 */ f32 unk50;
    /* 0x054 */ f32 unk54;
    /* 0x058 */ f32 unk58;
    /* 0x05c */ u8 pad5C[0x4];
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
    /* 0x08c */ f32 unk8C;
    /* 0x090 */ Matrix unk90;
    /* 0x0d0 */ f32 unkD0;
    /* 0x0d4 */ f32 unkD4;
    /* 0x0d8 */ f32 unkD8;
    /* 0x0dc */ u8 padDC[0x4];
    /* 0x0e0 */ f32 unkE0;
    /* 0x0e4 */ f32 unkE4;
    /* 0x0e8 */ f32 unkE8;
    /* 0x0ec */ u8 padEC[0x4];
    /* 0x0f0 */ f32 unkF0;
    /* 0x0f4 */ f32 unkF4;
    /* 0x0f8 */ f32 unkF8;
    /* 0x0fc */ u8 padFC[0x4];
    /* 0x100 */ f32 unk100;
    /* 0x104 */ f32 unk104;
    /* 0x108 */ f32 unk108;
    /* 0x10c */ u8 pad10C[0x4];
    /* 0x110 */ Matrix unk110;
    /* 0x150 */ f32 unk150;
    /* 0x154 */ f32 unk154;
    /* 0x158 */ f32 unk158;
    /* 0x15c */ u8 pad15C[0x4];
    /* 0x160 */ f32 unk160;
    /* 0x164 */ f32 unk164;
    /* 0x168 */ f32 unk168;
    /* 0x16c */ u8 pad16C[0x4];
    /* 0x170 */ f64 unk170;
    /* 0x178 */ f32 unk178;
    /* 0x17c */ u8 pad17C[0x4];
    /* 0x180 */ void* unk180;
    /* 0x184 */ void* unk184;
    /* 0x188 */ s32 unk188;
    /* 0x18c */ f32 unk18C;
    /* 0x190 */ f32 unk190;
    /* 0x194 */ f32 unk194;
    /* 0x198 */ s8* unk198;
    /* 0x19c */ f32 unk19C;
    /* 0x1a0 */ u8 unk1A0;
    /* 0x1a1 */ u8 unk1A1;
    /* 0x1a2 */ u8 pad1A2[0x2];
    /* 0x1a4 */ s32 unk1A4;
    /* 0x1a8 */ u8 unk1A8;
    /* 0x1a9 */ u8 pad1A9[0x3];
    /* 0x1ac */ f32 unk1AC;
};

class RopeBridgeAttachment {
public:
    /* 0x000 */ f64 unk0;
    /* 0x008 */ f64 unk8;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ void* unk18;
    /* 0x01c */ RopeBridge* unk1C;
    /* 0x020 */ RopeBridgeAttachment* unk20;
    /* 0x024 */ RopeBridgeAttachment* unk24;
};

class RopeBridgeDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void Deinit(void);
    static u8 pFirstDesc[0x4];
    /* 0x048 */ u8 pad48[0x18];
    /* 0x060 */ s32 unk60;
    /* 0x064 */ s32 unk64;
    /* 0x068 */ RopeBridgeDescriptor* unk68;
    /* 0x06c */ RopeBridgeDescriptor* unk6C;
};

class RopeBridge_cpp {
public:
    void __sinit(void);
};

#endif  // SPYRO_SOURCE_ROPEBRIDGE_H
