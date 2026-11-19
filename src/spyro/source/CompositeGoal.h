#ifndef SPYRO_SOURCE_COMPOSITEGOAL_H
#define SPYRO_SOURCE_COMPOSITEGOAL_H

#include <dolphin/types.h>
#include "spyro/source/Goal.h"

class Cynder;

template <class T0>
class CompositeGoal : public Goal<T0> {  // base: inlined ctor vtable stores
public:
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Terminate(void);
    virtual void Arbitrate(void);
    virtual s32 IsActive(void) const;
    virtual u8 IsActive(int);
    virtual s32 IsPresent(int);
    virtual void Init(T0 *, int, int, const char *);
    void RemoveAllSubgoals(void);
    u8 ActivateNextSubgoal(void);
    void AddSubgoalToFront(Goal<T0> *);
    void AddSubgoal(Goal<T0> *);
    u8 UpdateSubgoals(void);
};

#endif  // SPYRO_SOURCE_COMPOSITEGOAL_H
