#ifndef SPYRO_SOURCE_KDSYNKERPLAYER2MESSAGES_H
#define SPYRO_SOURCE_KDSYNKERPLAYER2MESSAGES_H

#include <dolphin/types.h>

class KDS_Message_PropBodyAnimUpdate;
class KDS_Message_PropEnd;
class KDS_Message_PropLookUpdate;
class KDS_Message_PropResolve;
class KDS_Message_PropSetPosRot;
class KDS_Message_SetCamera;
class KDS_Message_SetCameraSimple;
class MKAnim;
class MKAnimScript;
class MKModel;
class MKProp;
class MKVector3;
class Matrix;

class KDS_Message_PropBodyAnimUpdate {
public:
    void Init(MKAnimScript *, MKAnim *, float, float, float);
    /* 0x000 */ s32 unk0;
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ MKAnimScript* unk8;
    /* 0x00c */ MKAnim* unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ s8 unk1C;
};

class KDS_Message_PropEnd {
public:
    void Init(bool, bool);
    /* 0x000 */ s32 unk0;
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ s8 unk8;
    /* 0x009 */ s8 unk9;
};

class KDS_Message_PropLookUpdate {
public:
    void Init(MKVector3 *, MKProp *);
    /* 0x000 */ s32 unk0;
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ MKVector3* unk8;
    /* 0x00c */ MKProp* unkC;
    /* 0x010 */ s8 unk10;
};

class KDS_Message_PropResolve {
public:
    void Set(MKProp *, MKModel *);
    void Set(MKProp *, MKAnimScript *);
    void Init(void);
    /* 0x000 */ s32 unk0;
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u32 unk8;
    /* 0x00c */ MKAnimScript* unkC;
    /* 0x010 */ MKModel* unk10;
};

class KDS_Message_PropSetPosRot {
public:
    void Init(const MKVector3 &, const MKVector3 &);
    /* 0x000 */ s32 unk0;
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ f64 unk8;
    /* 0x010 */ f64 unk10;
    /* 0x018 */ f64 unk18;
    /* 0x020 */ f64 unk20;
};

class KDS_Message_SetCamera {
public:
    void Init(Matrix *, float, float, float);
    /* 0x000 */ s32 unk0;
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ Matrix* unk8;
    /* 0x00c */ f32 unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
};

class KDS_Message_SetCameraSimple {
public:
    void Init(const Matrix &);
    /* 0x000 */ s32 unk0;
};

#endif  // SPYRO_SOURCE_KDSYNKERPLAYER2MESSAGES_H
