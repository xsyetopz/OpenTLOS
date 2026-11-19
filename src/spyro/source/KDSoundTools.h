#ifndef SPYRO_SOURCE_KDSOUNDTOOLS_H
#define SPYRO_SOURCE_KDSOUNDTOOLS_H

#include <dolphin/types.h>

class KDSoundFader;
class KDSoundFlangedFader;
class KDSound_AfterRumble;
class KDSound_LoopSoundEvent;
class KDSound_SoundWall;
class KDUniformSpline;
class MKAnimScript;
class MKMessage;
class MKProp;
class MKVector3;

class KDSoundFlangedFader {
public:
    ~KDSoundFlangedFader(void);
    void Stop(void);
    void Update(int, bool, bool, MKProp *, MKVector3 *, unsigned int, int);
    void Message(MKMessage *);
    void Deinit(void);
    void RecalcVariables(int, float, float, float);
    void Init(int, float, float, float, float, float);
    /* 0x000 */ s32 unk0;
    /* 0x004 */ u8 pad4[0x24];
    /* 0x028 */ s32 unk28;
    /* 0x02c */ u8 pad2C[0x24];
    /* 0x050 */ s32 unk50;
    /* 0x054 */ f32 unk54;
    /* 0x058 */ f32 unk58;
    /* 0x05c */ f32 unk5C;
    /* 0x060 */ f32 unk60;
    /* 0x064 */ f32 unk64;
    /* 0x068 */ f32 unk68;
    /* 0x06c */ f32 unk6C;
};

class KDSound_AfterRumble {
public:
    void Init(void);
    void Stop(void);
    void Update(void);
    void Message(MKMessage *);
    void Trigger(MKVector3, int, float, float);
    /* 0x000 */ s32 unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ s32 unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ u8 pad1C[0x4];
    /* 0x020 */ f32 unk20;
    /* 0x024 */ f32 unk24;
    /* 0x028 */ f32 unk28;
    /* 0x02c */ u8 pad2C[0x4];
    /* 0x030 */ f32 unk30;
    /* 0x034 */ f32 unk34;
    /* 0x038 */ f32 unk38;
    /* 0x03c */ u8 pad3C[0x4];
    /* 0x040 */ f32 unk40;
    /* 0x044 */ f32 unk44;
    /* 0x048 */ f32 unk48;
    /* 0x04c */ u8 pad4C[0x4];
    /* 0x050 */ f32 unk50;
    /* 0x054 */ f32 unk54;
    /* 0x058 */ f32 unk58;
    /* 0x05c */ u8 pad5C[0x4];
    /* 0x060 */ s32 unk60;
    /* 0x064 */ f32 unk64;
    /* 0x068 */ s32 unk68;
    /* 0x06c */ f32 unk6C;
};

class KDSound_LoopSoundEvent {
public:
    void Update(MKVector3 *, unsigned int);
    void Message(MKMessage *);
    void Deinit(void);
    void Init(MKAnimScript *, int, int, int, int, int, int);
    /* 0x000 */ KDSoundFader* unk0;
    /* 0x004 */ KDSoundFader* unk4;
    /* 0x008 */ KDSoundFader* unk8;
    /* 0x00c */ MKAnimScript* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ s32 unk1C;
    /* 0x020 */ s32 unk20;
    /* 0x024 */ s32 unk24;
};

class KDSound_SoundWall {
public:
    ~KDSound_SoundWall(void);
    void SetBeginEndTimes(float, float);
    void Update(bool);
    void Message(MKMessage *);
    void Deinit(void);
    void Init(KDUniformSpline *, float, int, int, int, float, float, float, float);
    /* 0x000 */ s32 unk0;
    /* 0x004 */ u8 pad4[0x24];
    /* 0x028 */ KDUniformSpline* unk28;
    /* 0x02c */ u8 pad2C[0x4];
    /* 0x030 */ f32 unk30;
    /* 0x034 */ f32 unk34;
    /* 0x038 */ f32 unk38;
    /* 0x03c */ u8 pad3C[0x4];
    /* 0x040 */ f64 unk40;
    /* 0x048 */ f64 unk48;
    /* 0x050 */ f32 unk50;
    /* 0x054 */ f32 unk54;
    /* 0x058 */ f32 unk58;
    /* 0x05c */ s32 unk5C;
    /* 0x060 */ s32 unk60;
    /* 0x064 */ s32 unk64;
    /* 0x068 */ s32 unk68;
    /* 0x06c */ u8 unk6C;
};

#endif  // SPYRO_SOURCE_KDSOUNDTOOLS_H
