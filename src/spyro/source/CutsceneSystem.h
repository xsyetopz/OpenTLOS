#ifndef SPYRO_SOURCE_CUTSCENESYSTEM_H
#define SPYRO_SOURCE_CUTSCENESYSTEM_H

#include <dolphin/types.h>
#include "common/Source/MKVector4.h"
#include "spyro/source/KDSynkerPlayer3.h"
#include "spyro/source/UIStringTable.h"

class CutsceneObject;
class CutsceneSystem;
class CutsceneSystem_cpp;
class GameSynkerPlayer;
class GameVideo;
class KDSynkerPlayer3;
class MKAnimScript;
class MKIni;
class MKModel;
class MKVector3;
class MKVector4;
class UIStringTable;

class CutsceneSystem {
public:
    class Location {
    public:
        void SetTextID(int);
        void Update(void);
        void Deinit(void);
        void Init(CutsceneSystem *);
    };
    void SetCustomSubtitle(const char *, int, bool);
    void SetDuckValue(float);
    void NotifyProps(bool);
    void OnStop(void);
    void OnPlay(void);
    void OnBeginLoad(void);
    void Deactivate(void);
    s32 Activate(const char *, bool);
    void Abort(bool);
    void PlayIntro(CutsceneObject &, float);
    s32 Play(CutsceneObject &, float);
    s32 Play(const char *, float, void (*)(const char *, MKModel **, MKAnimScript **), bool);
    void DrawSubtitles(void);
    void Draw(void);
    void UnloadingDeinit(void);
    void UnloadingUpdate(void);
    void UnloadingInit(void);
    void MissingCutsceneDeinit(void);
    void MissingCutsceneUpdate(void);
    void MissingCutsceneInit(void);
    void PlayCutsceneDeinit(void);
    void PlayCutsceneUpdate(void);
    void PlayCutsceneInit(void);
    void LoadingDeinit(void);
    void LoadingUpdate(void);
    void LoadingInit(void);
    void Update(void);
    void Deinit(void);
    void Init(void);
    void DeinitModule(void);
    void InitModule(void);
    /* 0x000 */ u8 pad0[0x4];
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 pad8[0x8];
    /* 0x010 */ f32 unk10;
    /* 0x014 */ u8 pad14[0x8];
    /* 0x01c */ void* unk1C;
    /* 0x020 */ u8 unk20;
    /* 0x021 */ u8 pad21[0x17];
    /* 0x038 */ MKVector4 unk38;
    /* 0x048 */ s8 unk48;
    /* 0x049 */ u8 pad49[0x1f];
    /* 0x068 */ CutsceneObject* unk68;
    /* 0x06c */ CutsceneObject* unk6C;
    /* 0x070 */ s8 unk70;
    /* 0x071 */ u8 pad71[0x3];
    /* 0x074 */ s32 unk74;
    /* 0x078 */ MKVector3* unk78;
    /* 0x07c */ s8* unk7C;
    /* 0x080 */ s8* unk80;
    /* 0x084 */ GameVideo* unk84;
    /* 0x088 */ u8 unk88;
    /* 0x089 */ u8 unk89;
    /* 0x08a */ u8 pad8A[0x2];
    /* 0x08c */ s32 unk8C;
    /* 0x090 */ f32 unk90;
    /* 0x094 */ u8 pad94[0x4];
    /* 0x098 */ s32 unk98;
    /* 0x09c */ u8 unk9C;
    /* 0x09d */ u8 unk9D;
    /* 0x09e */ s8 unk9E;
    /* 0x09f */ u8 unk9F;
    /* 0x0a0 */ u8 padA0[0x4];
    /* 0x0a4 */ f32 unkA4;
    /* 0x0a8 */ u8 unkA8;
    /* 0x0a9 */ u8 unkA9;
    /* 0x0aa */ u8 unkAA;
    /* 0x0ab */ s8 unkAB;
};

class CutsceneSystem_cpp {
public:
    void __sinit(void);
};

class GameSynkerPlayer : public KDSynkerPlayer3 {  // base: inlined ctor vtable stores
public:
    virtual void Init(const char *, bool, bool, MKIni *);
    virtual void Deinit(void);
    /* 0x004 */ u8 pad4[0x25c];
    /* 0x260 */ UIStringTable unk260;
};

#endif  // SPYRO_SOURCE_CUTSCENESYSTEM_H
