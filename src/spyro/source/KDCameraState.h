#ifndef SPYRO_SOURCE_KDCAMERASTATE_H
#define SPYRO_SOURCE_KDCAMERASTATE_H

#include <dolphin/types.h>

class KDCamera;
class KDCameraStateDescriptor;
class KDCameraStateStack;
class MKMessage;

class KDCameraStateStack {
public:
    class Object {
    public:
        void ClearData(void);
        /* 0x000 */ s8 unk0;
    };
    void StateUpdate(void);
    void StateExit(void);
    void StateEnter(void);
    void * GetDescriptor(int);
    void GetDescriptorAtIndex(int);
    void GetObjectAtIndex(int);
    s32 IsStateMessage(MKMessage *);
    s32 HandleStateMessage(int);
    void * PopObjectOffStack(void);
    s32 Pop(int);
    void Push(int);
    void Update(void);
    void Reset(void);
    void Deinit(void);
    void Init(KDCamera *, KDCameraStateDescriptor *, int);
    KDCameraStateStack(void);
    /* 0x000 */ u8 pad0[0x10];
    /* 0x010 */ s32 unk10;
    /* 0x014 */ KDCamera* unk14;
    /* 0x018 */ KDCameraStateDescriptor* unk18;
    /* 0x01c */ s32 unk1C;
};

#endif  // SPYRO_SOURCE_KDCAMERASTATE_H
