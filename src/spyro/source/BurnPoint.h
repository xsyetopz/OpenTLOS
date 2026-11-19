#ifndef SPYRO_SOURCE_BURNPOINT_H
#define SPYRO_SOURCE_BURNPOINT_H

#include <dolphin/types.h>

class BurnPoint;

class BurnPoint {
public:
    ~BurnPoint(void);
    BurnPoint(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unk14'
inline BurnPoint::~BurnPoint() {
    if ((&this->unk14 != NULL) && (&this->unk14 != NULL)) {
        KDSound_Stop(&this->unk14);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk14'
inline BurnPoint::BurnPoint() {
    this->unk14 = 0;
    return this;
}
#endif

#endif  // SPYRO_SOURCE_BURNPOINT_H
