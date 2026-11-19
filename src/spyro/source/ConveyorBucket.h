#ifndef SPYRO_SOURCE_CONVEYORBUCKET_H
#define SPYRO_SOURCE_CONVEYORBUCKET_H

#include <dolphin/types.h>
#include "spyro/source/GameProp.h"

class ConveyorBucket;
class GameProp;
class MKIniLine;
class MKMessage;

class ConveyorBucket : public GameProp {  // base: vtable prefix
public:
    virtual ~ConveyorBucket(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    ConveyorBucket(void);
    void DirtParticles(void);
    /* 0x0c4 */ u8 padC4[0x4];
    /* 0x0c8 */ f64 unkC8;
    /* 0x0d0 */ f32 unkD0;
    /* 0x0d4 */ u8 padD4[0x4];
    /* 0x0d8 */ f64 unkD8;
    /* 0x0e0 */ f32 unkE0;
    /* 0x0e4 */ u8 padE4[0x4];
    /* 0x0e8 */ f32 unkE8;
};

#endif  // SPYRO_SOURCE_CONVEYORBUCKET_H
