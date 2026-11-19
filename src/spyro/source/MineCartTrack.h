#ifndef SPYRO_SOURCE_MINECARTTRACK_H
#define SPYRO_SOURCE_MINECARTTRACK_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "common/Source/Matrix.h"

class MKIniLine;
class MKMessage;
class MKProp;
class MKPropDescriptor;
class Matrix;
class MineCartTrack;
class MineCartTrackDescriptor;

class MineCartTrack : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~MineCartTrack(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    /* 0x04c */ u8 unk4C;
    /* 0x04d */ u8 pad4D[0x3];
    /* 0x050 */ Matrix unk50;
    /* 0x090 */ f32 unk90;
    /* 0x094 */ f32 unk94;
    /* 0x098 */ f32 unk98;
    /* 0x09c */ u8 pad9C[0x4];
    /* 0x0a0 */ f64 unkA0;
    /* 0x0a8 */ f64 unkA8;
    /* 0x0b0 */ f64 unkB0;
    /* 0x0b8 */ f64 unkB8;
    /* 0x0c0 */ u8 padC0[0x40];
    /* 0x100 */ u8 unk100;
    /* 0x101 */ u8 pad101[0x3];
    /* 0x104 */ s32 unk104;
    /* 0x108 */ s32 unk108;
    /* 0x10c */ s32 unk10C;
    /* 0x110 */ s32 unk110;
    /* 0x114 */ s32 unk114;
    /* 0x118 */ s32 unk118;
    /* 0x11c */ s32 unk11C;
    /* 0x120 */ s32 unk120;
    /* 0x124 */ u8 pad124[0x20];
    /* 0x144 */ u8 unk144;
};

class MineCartTrackDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    /* 0x048 */ u8 pad48[0x20];
    /* 0x068 */ f64 unk68;
    /* 0x070 */ f64 unk70;
    /* 0x078 */ f64 unk78;
};

#endif  // SPYRO_SOURCE_MINECARTTRACK_H
