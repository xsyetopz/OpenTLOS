#ifndef SPYRO_SOURCE_GOAL_H
#define SPYRO_SOURCE_GOAL_H

#include <dolphin/types.h>

template <class T0>
class Goal {
public:
    virtual void Init(T0 *, int, const char *);
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Activate(void) = 0;
    virtual u8 Update(void) = 0;
    virtual void Terminate(void);
    virtual void Arbitrate(void);
    virtual void IsComplete(void) const;
    virtual void IsActive(void) const;
    virtual void IsInactive(void) const;
    virtual void HasFailed(void) const;
    virtual void GetType(void) const;
    virtual void IsActive(int);
    virtual void IsPresent(int);
    void ActivateIfInactive(void);
    void ReactivateIfFailed(void);
};

#endif  // SPYRO_SOURCE_GOAL_H
