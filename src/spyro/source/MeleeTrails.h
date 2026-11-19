#ifndef SPYRO_SOURCE_MELEETRAILS_H
#define SPYRO_SOURCE_MELEETRAILS_H

#include <dolphin/types.h>
#include "spyro/source/GameProp.h"

class GameProp;
class GamePropDescriptor;
class MKAnim;
class MKAnimScript;
class MKIniLine;
class MKMaterial;
class MeleeTrails;
class MeleeTrailsDescriptor;

class MeleeTrails : public GameProp {  // base: base ctor call
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
    /* 0x0c8 */ MKAnimScript* unkC8;
    /* 0x0cc */ MKMaterial* unkCC;
};

class MeleeTrailsDescriptor : public GamePropDescriptor {  // base: base ctor call
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    MeleeTrailsDescriptor(void);
    void InitMeleeTrailData(char *);
    /* 0x0e8 */ s8 unkE8;
    /* 0x0e9 */ u8 padE9[0x3e];
    /* 0x127 */ s8 unk127;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline MeleeTrails::MeleeTrails() {
    return this;
}
#endif

inline MeleeTrails::~MeleeTrails() {
}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline MeleeTrailsDescriptor::MeleeTrailsDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_MELEETRAILS_H
