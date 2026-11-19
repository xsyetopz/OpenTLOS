#ifndef SPYRO_SOURCE_KDSYNKERPLAYER3_H
#define SPYRO_SOURCE_KDSYNKERPLAYER3_H

#include <dolphin/types.h>
#include "spyro/source/KDSynkerPlayerActorList.h"
#include "spyro/source/KDSynkerPlayerCamera.h"
#include "spyro/source/KDSynkerPlayerEvents.h"
#include "spyro/source/KDSynkerPlayerSounds.h"
#include "spyro/source/KDSynkerPlayerTools.h"

class KDInput;
class KDSP_ActorList;
class KDSP_Camera;
class KDSP_EnvelopeList;
class KDSP_Events;
class KDSP_Sounds;
class KDSP_Subtitles;
class KDSynkerHeap;
class KDSynkerPlayer3;
class MKIni;

class KDSynkerPlayer3 {
public:
    class CallBackMode;
    virtual void Init(const char *, bool, bool, MKIni *);
    virtual void Deinit(void);
    s8 * GetSubtitlesFileName(const char *);
    s32 GetActorProp(int);
    s32 GetActorAnimScript(int);
    void GetActorModel(int);
    void ParseSK2(void);
    void ParseHeader(void);
    s32 GetSubTitle(int);
    s32 GetSubTitleCount(void);
    s32 IsUnloaded(void);
    s32 IsUnloading(void);
    s32 IsAtEnd(void);
    s32 IsPlaying(void);
    s32 IsReadyToPlay(void);
    s32 IsLoading(void);
    s32 IsActive(void);
    void Unload(void);
    void Draw(void);
    void Play(bool);
    void SkipToEnd(bool);
    void Update_Unloading_Playing(void);
    void Update_Unloading_Loading(void);
    void ActorCallback(KDSynkerPlayer3::CallBackMode);
    void Update_Playing(bool);
    void Update_PrimingSound(void);
    void Update_ParseData(void);
    void Update_Loading(void);
    void Update(void);
    void SetPlaySpeed(float);
    static u8 pCameraProp[0x4];
    static u8 pActorCallback[0x4];
    static u8 pEventCreationTable[0x4];
    /* 0x004 */ KDSynkerHeap unk4;
    /* 0x028 */ s8 unk28;
    /* 0x029 */ u8 pad29[0x1f];
    /* 0x048 */ f32 unk48;
    /* 0x04c */ s32 unk4C;
    /* 0x050 */ u32 unk50;
    /* 0x054 */ MKIni* unk54;
    /* 0x058 */ u8 unk58;
    /* 0x059 */ u8 pad59[0x7];
    /* 0x060 */ KDSP_Camera unk60;
    /* 0x100 */ KDSP_ActorList unk100;
    /* 0x114 */ KDSP_EnvelopeList unk114;
    /* 0x120 */ KDSP_Events unk120;
    /* 0x148 */ KDSP_Sounds unk148;
    /* 0x170 */ KDSP_Subtitles unk170;
    /* 0x21c */ u8 pad21C[0x18];
    /* 0x234 */ s32 unk234;
    /* 0x238 */ KDInput* unk238;
    /* 0x23c */ s32 unk23C;
    /* 0x240 */ s8 unk240;
    /* 0x241 */ u8 pad241[0x3];
    /* 0x244 */ f32 unk244;
    /* 0x248 */ f32 unk248;
    /* 0x24c */ s32 unk24C;
    /* 0x250 */ s32 unk250;
    /* 0x254 */ s32 unk254;
};

#endif  // SPYRO_SOURCE_KDSYNKERPLAYER3_H
