#ifndef SPYRO_SOURCE_FURYFXFIRE_H
#define SPYRO_SOURCE_FURYFXFIRE_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "common/Source/Matrix.h"
#include "spyro/source/GameMessages.h"

class BreathHitMessage;
class FuryFXFire;
class FuryFXFire_cpp;
class HeroHurtReactionType;
class MKMessage;
class MKProp;
class MKVector3;
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
    /* 0x11c */ u8 pad11C[0x174];
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
