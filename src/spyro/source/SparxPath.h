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

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline SparxPath::~SparxPath() {
    s32 temp_cr0_eq_26;

    if (this != NULL) {
        if (&this->unkC4 != NULL) {
            this->unkC4.Deinit();
        }
        temp_cr0_eq_26 = this == NULL;
        if (temp_cr0_eq_26 == 0) {
            if (temp_cr0_eq_26 == 0) {
            }
        }
    }
}

#endif  // SPYRO_SOURCE_SPARXPATH_H
