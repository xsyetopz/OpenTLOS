#ifndef SPYRO_SOURCE_BIRD_H
#define SPYRO_SOURCE_BIRD_H

#include <dolphin/types.h>
#include "spyro/source/CreationTable.h"
#include "spyro/source/Critters.h"
#include "spyro/source/KDSpline.h"

class Bird;
class BirdCritter;
class BirdCritterDescriptor;
class Critters;
class CrittersDescriptor;
class KDUniformSpline;
class MKIniLine;

class Bird {
public:
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ f32 unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ f32 unk1C;
    /* 0x020 */ f32 unk20;
    /* 0x024 */ f32 unk24;
    /* 0x028 */ f32 unk28;
    /* 0x02c */ f32 unk2C;
    /* 0x030 */ u8 pad30[0x4];
    /* 0x034 */ f32 unk34;
    /* 0x038 */ f32 unk38;
    /* 0x03c */ f32 unk3C;
    /* 0x040 */ u8 pad40[0x10];
    /* 0x050 */ void* unk50;
    /* 0x054 */ f32 unk54;
    /* 0x058 */ f32 unk58;
    /* 0x05c */ u8 pad5C[0x4];
    /* 0x060 */ s32 unk60;
    /* 0x064 */ f32 unk64;
    /* 0x068 */ KDUniformSpline unk68;
    /* 0x07c */ f32 unk7C;
    /* 0x080 */ f32 unk80;
    /* 0x084 */ f32 unk84;
    /* 0x088 */ u8 unk88;
    /* 0x089 */ u8 pad89[0x3];
    /* 0x08c */ f32 unk8C;
};

class BirdCritter : public Critters {  // base: ctor/dtor vtable stores
public:
    virtual ~BirdCritter(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Draw(void);
    BirdCritter(void);
    void FindNewFlyParameters(Bird *, bool);
    void SetFlyingExitState(Bird *);
    void SetFlyingLoopState(Bird *);
    void SetFlyingEnterState(Bird *);
    void SetIdleState(Bird *);
    /* 0x168 */ u8 pad168[0x8];
    /* 0x170 */ void* unk170;
    /* 0x174 */ void* unk174;
    /* 0x178 */ s32 unk178;
};

class BirdCritterDescriptor : public CrittersDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    BirdCritterDescriptor(void);
    /* 0x06d */ u8 pad6D[0x3];
    /* 0x070 */ s32 unk70;
    /* 0x074 */ s32 unk74;
    /* 0x078 */ s32 unk78;
    /* 0x07c */ s32 unk7C;
    /* 0x080 */ s32 unk80;
    /* 0x084 */ s32 unk84;
    /* 0x088 */ f32 unk88;
    /* 0x08c */ f32 unk8C;
    /* 0x090 */ s32 unk90;
};

#endif  // SPYRO_SOURCE_BIRD_H
