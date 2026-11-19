#ifndef SPYRO_SOURCE_COLLIDEBOX_H
#define SPYRO_SOURCE_COLLIDEBOX_H

#include <dolphin/types.h>
#include "spyro/source/KDProp.h"

class CollideBox;
class KDProp;
class MKIniLine;
class MKMessage;

class CollideBox : public KDProp {  // base: ctor/dtor vtable stores
public:
    virtual ~CollideBox(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Message(MKMessage *);
    /* 0x090 */ u8 unk90;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline CollideBox::~CollideBox() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
            if (temp_cr0_eq_15 == 0) {
            }
        }
    }
}

#endif  // SPYRO_SOURCE_COLLIDEBOX_H
