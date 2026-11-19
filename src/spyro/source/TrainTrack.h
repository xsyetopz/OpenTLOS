#ifndef SPYRO_SOURCE_TRAINTRACK_H
#define SPYRO_SOURCE_TRAINTRACK_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "spyro/source/KDSpline.h"

class KDSpline;
class MKIniLine;
class MKMessage;
class MKProp;
class MKPropDescriptor;
class MKVector3;
class TrainTrack;
class TrainTrackDescriptor;

class TrainTrack : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~TrainTrack(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual s32 LoadDone(void);
    virtual void Deinit(void);
    virtual f32 Resolve(void);
    virtual void Reset(void);
    virtual void * Update(void);
    virtual void Message(MKMessage *);
    void Build(void);
    MKVector3 GetTrackZAxis(int, float);
    MKVector3 GetTrackYAxis(int, float);
    MKVector3 GetTrackXAxis(int, float);
    void GetTrackPos(int, float, int);
    f32 GetTrackLength(int);
    /* 0x04c */ KDSpline unk4C;
    /* 0x060 */ KDSpline unk60;
    /* 0x074 */ KDSpline unk74;
    /* 0x088 */ KDSpline unk88;
};

class TrainTrackDescriptor : public MKPropDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Resolve(void);
    /* 0x044 */ u8 pad44[0x238];
    /* 0x27c */ s32 unk27C;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline TrainTrack::~TrainTrack() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_TRAINTRACK_H
