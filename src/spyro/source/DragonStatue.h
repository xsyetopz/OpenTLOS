#ifndef SPYRO_SOURCE_DRAGONSTATUE_H
#define SPYRO_SOURCE_DRAGONSTATUE_H

#include <dolphin/types.h>
#include "spyro/source/EventMessage.h"
#include "spyro/source/KDProp.h"

class DragonStatue;
class EventMessage;
class KDProp;
class MKIniLine;
class MKMessage;

class DragonStatue : public KDProp {  // base: ctor/dtor vtable stores
public:
    virtual ~DragonStatue(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    void EmitDust(void);
    void EmitCrudAboveStatue(void);
    void EmitCrudAbovePlayer(void);
    void SnapDown(void);
    u8 IsUp(void);
    u8 IsDown(void);
    /* 0x089 */ u8 pad89[0x7];
    /* 0x090 */ EventMessage unk90;
    /* 0x094 */ EventMessage unk94;
    /* 0x098 */ EventMessage unk98;
    /* 0x09c */ EventMessage unk9C;
    /* 0x0a0 */ f32 unkA0;
    /* 0x0a4 */ u8 padA4[0x4];
    /* 0x0a8 */ f32 unkA8;
    /* 0x0ac */ f32 unkAC;
    /* 0x0b0 */ f32 unkB0;
    /* 0x0b4 */ u8 padB4[0x4];
    /* 0x0b8 */ f32 unkB8;
    /* 0x0bc */ f32 unkBC;
    /* 0x0c0 */ f32 unkC0;
    /* 0x0c4 */ u8 padC4[0x4];
    /* 0x0c8 */ f32 unkC8;
    /* 0x0cc */ f32 unkCC;
    /* 0x0d0 */ f32 unkD0;
    /* 0x0d4 */ u8 padD4[0x4];
    /* 0x0d8 */ f64 unkD8;
    /* 0x0e0 */ f32 unkE0;
    /* 0x0e4 */ u8 padE4[0x4];
    /* 0x0e8 */ f32 unkE8;
    /* 0x0ec */ f32 unkEC;
    /* 0x0f0 */ f32 unkF0;
    /* 0x0f4 */ f32 unkF4;
    /* 0x0f8 */ s32 unkF8;
    /* 0x0fc */ s32 unkFC;
    /* 0x100 */ s32 unk100;
    /* 0x104 */ s32 unk104;
    /* 0x108 */ u8 pad108[0x24];
    /* 0x12c */ s32 unk12C;
    /* 0x130 */ u8 pad130[0x24];
    /* 0x154 */ f32 unk154;
};

#endif  // SPYRO_SOURCE_DRAGONSTATUE_H
