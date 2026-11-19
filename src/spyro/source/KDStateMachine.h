#ifndef SPYRO_SOURCE_KDSTATEMACHINE_H
#define SPYRO_SOURCE_KDSTATEMACHINE_H

#include <dolphin/types.h>

template <class T0>
class KDStateMachine {
public:
    class State;
    void Init(State *, KDStateMachine *);
    void Deinit(T0 *);
    void Deinit(void);
    void Update(T0 *, bool);
    void SetState(T0 *, int, bool);
    void Exit(T0 *);
    void GetState(void);
    void GetLastState(void);
    void GetStateName(int);
};

#endif  // SPYRO_SOURCE_KDSTATEMACHINE_H
