#ifndef SPYRO_SOURCE_PITCOVER_H
#define SPYRO_SOURCE_PITCOVER_H

#include <dolphin/types.h>
#include "spyro/source/KDProp.h"

class KDProp;
class MKMessage;
class PitCover;

class PitCover : public KDProp {  // base: ctor/dtor vtable stores
public:
    virtual ~PitCover(void);
    virtual void LoadDone(void);
    virtual void Message(MKMessage *);
    /* 0x089 */ u8 pad89[0x7];
    /* 0x090 */ s32 unk90;
    /* 0x094 */ s32 unk94;
    /* 0x098 */ u8 pad98[0x4];
    /* 0x09c */ s32 unk9C;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline PitCover::~PitCover() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
            if (temp_cr0_eq_15 == 0) {
            }
        }
    }
}

#endif  // SPYRO_SOURCE_PITCOVER_H
