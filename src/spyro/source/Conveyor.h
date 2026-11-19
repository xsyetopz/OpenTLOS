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

class Conveyor : public GameProp {  // base: base ctor call
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
    /* 0x0c8 */ u8 padC8[0x50];
    /* 0x118 */ Matrix unk118;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline Conveyor::~Conveyor() {
}

#if 0 // DRAFT: '(' expected
inline Conveyor::Conveyor() {
    __construct_array((KDUniformSpline *) &this->unk118, (MKAnimScript *(*)(MKAnimScript *)) &KDUniformSpline::KDUniformSpline, NULL, 0x14, 2);
    return this;
}
#endif

#endif  // SPYRO_SOURCE_CONVEYOR_H
