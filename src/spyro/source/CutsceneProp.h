#ifndef SPYRO_SOURCE_CUTSCENEPROP_H
#define SPYRO_SOURCE_CUTSCENEPROP_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "spyro/source/CutsceneObject.h"

class CutsceneObject;
class CutsceneProp;
class MKIniLine;
class MKMessage;
class MKProp;

class CutsceneProp : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~CutsceneProp(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    virtual void Disable(void);
    /* 0x04c */ u8 pad4C[0x4];
    /* 0x050 */ CutsceneObject unk50;
    /* 0x0b4 */ u8 padB4[0x4];
    /* 0x0b8 */ f32 unkB8;
    /* 0x0bc */ u8 unkBC;
    /* 0x0bd */ u8 unkBD;
    /* 0x0be */ u8 unkBE;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline CutsceneProp::~CutsceneProp() {
    if (this != NULL) {
    }
}

#endif  // SPYRO_SOURCE_CUTSCENEPROP_H
