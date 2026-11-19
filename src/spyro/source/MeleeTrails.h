#ifndef SPYRO_SOURCE_MELEETRAILS_H
#define SPYRO_SOURCE_MELEETRAILS_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "spyro/source/GameProp.h"

class GameProp;
class MKAnim;
class MKAnimScript;
class MKHeap;
class MKIniLine;
class MKMaterial;
class MKPropDescriptor;
class MeleeTrails;
class MeleeTrailsDescriptor;

class MeleeTrails : public GameProp {  // base: vtable prefix
public:
    virtual ~MeleeTrails(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    MeleeTrails(void);
    void ResolveAnims(MKAnimScript *);
    void EnableTrail(MKAnim *, int, bool, float, float, float);
    /* 0x0c4 */ u8 padC4[0x4];
    /* 0x0c8 */ MKAnimScript* unkC8;
    /* 0x0cc */ MKMaterial* unkCC;
};

class MeleeTrailsDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    MeleeTrailsDescriptor(void);
    void InitMeleeTrailData(char *);
    /* 0x048 */ u8 pad48[0x9c];
    /* 0x0e4 */ MKHeap* unkE4;
    /* 0x0e8 */ s8 unkE8;
    /* 0x0e9 */ u8 padE9[0x3e];
    /* 0x127 */ s8 unk127;
};

#endif  // SPYRO_SOURCE_MELEETRAILS_H
