#ifndef SPYRO_SOURCE_FURYFXFIRE_H
#define SPYRO_SOURCE_FURYFXFIRE_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "common/Source/Matrix.h"
#include "spyro/source/GameMessages.h"

class BreathHitMessage;
class Corona;
class FuryFXFire;
class FuryFXFire_cpp;
class HeroHurtReactionType;
class MKMaterial;
class MKMessage;
class MKModel;
class MKProp;
class MKVector3;
class ManagedLight;
class Matrix;

class FuryFXFire : public MKProp {  // base: ctor/dtor vtable stores
public:
    class DragonStruct {
    public:
        ~DragonStruct(void);
        DragonStruct(void);
    };
    virtual ~FuryFXFire(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    FuryFXFire(void);
    void ResetFury(void);
    s32 Trigger(const MKVector3 &, bool, bool, HeroHurtReactionType);
    void SetDefaults(void);
    void UpdateDragons(void);
    /* 0x04c */ u8 pad4C[0x44];
    /* 0x090 */ Matrix unk90;
    /* 0x0d0 */ f32 unkD0;
    /* 0x0d4 */ f32 unkD4;
    /* 0x0d8 */ f32 unkD8;
    /* 0x0dc */ u8 padDC[0x4];
    /* 0x0e0 */ MKMaterial* unkE0;
    /* 0x0e4 */ MKMaterial* unkE4;
    /* 0x0e8 */ ManagedLight* unkE8;
    /* 0x0ec */ MKModel* unkEC;
    /* 0x0f0 */ MKModel* unkF0;
    /* 0x0f4 */ Corona* unkF4;
    /* 0x0f8 */ f32 unkF8;
    /* 0x0fc */ f32 unkFC;
    /* 0x100 */ f32 unk100;
    /* 0x104 */ s32 unk104;
    /* 0x108 */ u8 pad108[0x188];
    /* 0x290 */ BreathHitMessage unk290;
    /* 0x2e1 */ u8 pad2E1[0x7];
    /* 0x2e8 */ s32 unk2E8;
    /* 0x2ec */ s32 unk2EC;
    /* 0x2f0 */ u8 unk2F0;
    /* 0x2f1 */ u8 unk2F1;
};

class FuryFXFire_cpp {
public:
    void __sinit(void);
};

#endif  // SPYRO_SOURCE_FURYFXFIRE_H
