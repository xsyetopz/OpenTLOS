#ifndef SPYRO_SOURCE_FIGHTELEVATORANCHOR_H
#define SPYRO_SOURCE_FIGHTELEVATORANCHOR_H

#include <dolphin/types.h>
#include "spyro/source/Shatterable.h"

class FightElevatorAnchor;
class MKIniLine;
class MKSceneManager;
class Shatterable;

class FightElevatorAnchor : public Shatterable {  // base: vtable prefix
public:
    virtual ~FightElevatorAnchor(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Update(void);
    FightElevatorAnchor(void);
    void GetZapAnchorPos(void);
    /* 0x1a8 */ MKSceneManager* unk1A8;
    /* 0x1ac */ s32 unk1AC;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unkC8'
inline FightElevatorAnchor::FightElevatorAnchor() {
    this->unkC8 = &__vt + 0x48;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC8'
inline FightElevatorAnchor::~FightElevatorAnchor() {
    this->unkC8 = &__vt.unk48;
}
#endif

#endif  // SPYRO_SOURCE_FIGHTELEVATORANCHOR_H
