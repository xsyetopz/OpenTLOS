#ifndef SPYRO_SOURCE_TRAPSPAWNPOOL_H
#define SPYRO_SOURCE_TRAPSPAWNPOOL_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "common/Source/Matrix.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/KDSpline.h"

class KDPathSegment;
class KDUniformSpline;
class MKIniLine;
class MKProp;
class MKPropDescriptor;
class Matrix;
class TrapSpawnPool;
class TrapSpawnPoolDescriptor;

class TrapSpawnPool : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~TrapSpawnPool(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Reset(void);
    virtual void Update(void);
    /* 0x04c */ u8 pad4C[0x4];
    /* 0x050 */ Matrix unk50;
    /* 0x090 */ s32 unk90;
    /* 0x094 */ f32 unk94;
    /* 0x098 */ f32 unk98;
    /* 0x09c */ void** unk9C;
    /* 0x0a0 */ KDUniformSpline unkA0;
    /* 0x0b4 */ KDPathSegment unkB4;
    /* 0x0ec */ f32 unkEC;
    /* 0x0f0 */ f32 unkF0;
    /* 0x0f4 */ u8 padF4[0x4];
    /* 0x0f8 */ f32 unkF8;
    /* 0x0fc */ f32 unkFC;
    /* 0x100 */ f32 unk100;
    /* 0x104 */ f32 unk104;
    /* 0x108 */ f32 unk108;
    /* 0x10c */ f32 unk10C;
    /* 0x110 */ s8 unk110;
    /* 0x111 */ u8 pad111[0x3];
    /* 0x114 */ s32 unk114;
    /* 0x118 */ f32 unk118;
    /* 0x11c */ f32 unk11C;
};

class TrapSpawnPoolDescriptor : public MKPropDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    /* 0x044 */ u8 pad44[0x1c];
    /* 0x060 */ s8* unk60;
    /* 0x064 */ s32 unk64;
    /* 0x068 */ u8 pad68[0xc];
    /* 0x074 */ f32 unk74;
    /* 0x078 */ f32 unk78;
    /* 0x07c */ u8 pad7C[0x4];
    /* 0x080 */ f32 unk80;
    /* 0x084 */ f32 unk84;
    /* 0x088 */ f32 unk88;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline TrapSpawnPool::~TrapSpawnPool() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_TRAPSPAWNPOOL_H
