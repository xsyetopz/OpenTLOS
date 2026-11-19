#ifndef SPYRO_SOURCE_CONVEYOR_H
#define SPYRO_SOURCE_CONVEYOR_H

#include <dolphin/types.h>
#include "common/Source/Matrix.h"
#include "spyro/source/GameProp.h"

class Conveyor;
class GameProp;
class MKIniLine;
class MKMessage;
class Matrix;

class Conveyor : public GameProp {  // base: vtable prefix
public:
    virtual ~Conveyor(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    Conveyor(void);
    /* 0x0c4 */ u8 padC4[0x54];
    /* 0x118 */ Matrix unk118;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline Conveyor::~Conveyor() {
}

#if 0 // DRAFT: '(' expected
inline Conveyor::Conveyor() {
    __construct_array(&this->unk118.unk0, (MKAnimScript *(*)(MKAnimScript *)) &KDUniformSpline::KDUniformSpline, NULL, 0x14, 2);
    return this;
}
#endif

#endif  // SPYRO_SOURCE_CONVEYOR_H
