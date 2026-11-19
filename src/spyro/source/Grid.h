#ifndef SPYRO_SOURCE_GRID_H
#define SPYRO_SOURCE_GRID_H

#include <dolphin/types.h>

class MKVector3;

template <class T0>
class Grid {
public:
    class Cell;
    void GetValueAt(const MKVector3 &, T0 *, T0 (*)(const T0 &, const T0 &, float));
    void CalcCell(Cell *, T0 *, const MKVector3 &);
};

#endif  // SPYRO_SOURCE_GRID_H
