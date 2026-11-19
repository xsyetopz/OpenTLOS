#ifndef SPYRO_SOURCE_SPARXPATH_H
#define SPYRO_SOURCE_SPARXPATH_H

#include <dolphin/types.h>
#include "spyro/source/EventMessage.h"
#include "spyro/source/SplineProp.h"

class EventMessage;
class MKIniLine;
class MKMessage;
class SparxPath;
class SparxPath_cpp;
class SplineProp;

class SparxPath : public SplineProp {  // base: ctor/dtor vtable stores
public:
    virtual ~SparxPath(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Message(MKMessage *);
    /* 0x0b8 */ u8 padB8[0x8];
    /* 0x0c0 */ f32 unkC0;
    /* 0x0c4 */ EventMessage unkC4;
};

class SparxPath_cpp {
public:
    void __sinit(void);
};

#endif  // SPYRO_SOURCE_SPARXPATH_H
