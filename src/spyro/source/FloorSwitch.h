#ifndef SPYRO_SOURCE_FLOORSWITCH_H
#define SPYRO_SOURCE_FLOORSWITCH_H

#include <dolphin/types.h>
#include "common/Source/MKVector4.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/Trap.h"

class EventMessage;
class FloorSwitch;
class FloorSwitchDescriptor;
class FloorSwitch_cpp;
class KDPropExDescriptor;
class KDSoundPlayer;
class MKIniLine;
class MKMaterial;
class MKMessage;
class MKVector4;
class Trap;

class FloorSwitch : public Trap {  // base: vtable prefix
public:
    virtual ~FloorSwitch(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    FloorSwitch(void);
    void SetState(int);
    /* 0x0e0 */ s32 unkE0;
    /* 0x0e4 */ s32 unkE4;
    /* 0x0e8 */ f32 unkE8;
    /* 0x0ec */ u8 unkEC;
    /* 0x0ed */ u8 padED[0x3];
    /* 0x0f0 */ MKVector4 unkF0;
    /* 0x100 */ f64 unk100;
    /* 0x108 */ f64 unk108;
    /* 0x110 */ u8 unk110;
    /* 0x111 */ u8 pad111[0x3];
    /* 0x114 */ KDSoundPlayer* unk114;
    /* 0x118 */ KDSoundPlayer* unk118;
    /* 0x11c */ KDSoundPlayer* unk11C;
    /* 0x120 */ EventMessage unk120;
    /* 0x124 */ EventMessage unk124;
    /* 0x128 */ MKMaterial* unk128;
};

class FloorSwitchDescriptor : public KDPropExDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    FloorSwitchDescriptor(void);
    /* 0x0c0 */ u8 padC0[0x24];
    /* 0x0e4 */ s32 unkE4;
    /* 0x0e8 */ s32 unkE8;
    /* 0x0ec */ s32 unkEC;
    /* 0x0f0 */ s32 unkF0;
    /* 0x0f4 */ s32 unkF4;
    /* 0x0f8 */ s32 unkF8;
    /* 0x0fc */ s32 unkFC;
    /* 0x100 */ s32 unk100;
    /* 0x104 */ s32 unk104;
    /* 0x108 */ f32 unk108;
};

class FloorSwitch_cpp {
public:
    void __sinit(void);
};

#endif  // SPYRO_SOURCE_FLOORSWITCH_H
