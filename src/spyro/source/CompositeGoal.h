#ifndef SPYRO_SOURCE_COMPOSITEGOAL_H
#define SPYRO_SOURCE_COMPOSITEGOAL_H

#include <dolphin/types.h>
#include "spyro/source/Goal.h"

class Cynder;

template <class T0>
class CompositeGoal : public Goal<T0> {  // base: vtable prefix
public:
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Terminate(void);
    virtual void Arbitrate(void);
    virtual void IsActive(void) const;
    virtual void IsActive(int);
    virtual void IsPresent(int);
    virtual void Init(T0 *, int, int, const char *);
    void RemoveAllSubgoals(void);
    void ActivateNextSubgoal(void);
    void AddSubgoalToFront(Goal<T0> *);
    void AddSubgoal(Goal<T0> *);
    void UpdateSubgoals(void);
};

#endif  // SPYRO_SOURCE_COMPOSITEGOAL_H
