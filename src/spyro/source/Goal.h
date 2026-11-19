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
    virtual s32 IsComplete(void) const;
    virtual s32 IsActive(void) const;
    virtual s32 IsInactive(void) const;
    virtual s32 HasFailed(void) const;
    virtual s32 GetType(void) const;
    virtual s32 IsActive(int);
    virtual s32 IsPresent(int);
    void ActivateIfInactive(void);
    void ReactivateIfFailed(void);
};

#endif  // SPYRO_SOURCE_GOAL_H
