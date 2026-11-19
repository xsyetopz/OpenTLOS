#ifndef SPYRO_SOURCE_GAME_H
#define SPYRO_SOURCE_GAME_H

#include <dolphin/types.h>
#include "spyro/source/CutsceneSystem.h"
#include "spyro/source/GameStateMachine.h"

class CutsceneSystem;
class DialogBoxTheme;
class GameGlobals;
class GameStateMachine;
class GameStateMachineInit;
class GameStateMachineState;
class Game_cpp;
class HeroInterface;
class Level;
class MKFont;
class MKVector3;
class MKVector4;
class TargetManager;

class GameGlobals {
public:
    class Capture {
    public:
        void Release(void);
        void Get(void);
        void Lock(void);
        void Deinit(void);
        void Init(char *, int);
        /* 0x000 */ s8 unk0;
    };
    class Fade {
    public:
        void FadeOut(const MKVector4 *);
        void FadeIn(const MKVector4 *);
        void Draw(void);
        void Update(void);
        void Reset(void);
        void Deinit(void);
        void Init(void);
        /* 0x000 */ s8 unk0;
    };
    class KillRate {
    public:
        f32 GetRate(void);
        void Update(void);
        void AddKill(void);
        void Deinit(void);
        void Init(int, float);
        /* 0x000 */ s8 unk0;
    };
    void EnableSlowMotion(bool, float, float);
    void EmitFairyDandruf(const MKVector3 &, const MKVector3 &, const float &, const MKVector4 &);
    void EmitSnowCrud(const MKVector3 &, const MKVector3 &, const float &);
    void EmitDust(const MKVector3 &, const MKVector3 &, const float &, float);
    void EmitSmallRocks(const MKVector3 &, const MKVector3 &, const float &);
    void EmitCrud(const MKVector3 &, const MKVector3 &, const float &);
    void GetSpyro(void);
    void SetGamePaused(bool, bool (*)(void), void (*)(void), unsigned int);
    void InfiniteMagicOff(void);
    void InfiniteMagicOn(void);
    HeroInterface * SetHero(HeroInterface *);
    void ResetInGameData(void);
    void Deinit(void);
    void Init(void);
    /* 0x000 */ HeroInterface* unk0;
    /* 0x004 */ s8 unk4;
    /* 0x005 */ s8 unk5;
    /* 0x006 */ s8 unk6;
    /* 0x007 */ s8 unk7;
    /* 0x008 */ s8 unk8;
    /* 0x009 */ s8 unk9;
    /* 0x00a */ s8 unkA;
    /* 0x00b */ s8 unkB;
    /* 0x00c */ u8 padC[0x14];
    /* 0x020 */ TargetManager* unk20;
    /* 0x024 */ GameGlobals::Capture unk24;
    /* 0x025 */ u8 pad25[0x3b];
    /* 0x060 */ s32 unk60;
    /* 0x064 */ s32 unk64;
    /* 0x068 */ s32 unk68;
    /* 0x06c */ s32 unk6C;
    /* 0x070 */ s32 unk70;
    /* 0x074 */ s32 unk74;
    /* 0x078 */ void* unk78;
    /* 0x07c */ void* unk7C;
    /* 0x080 */ s32 unk80;
    /* 0x084 */ s32 unk84;
    /* 0x088 */ s32 unk88;
    /* 0x08c */ void* unk8C;
    /* 0x090 */ s32 unk90;
    /* 0x094 */ s32 unk94;
    /* 0x098 */ s32 unk98;
    /* 0x09c */ s32 unk9C;
    /* 0x0a0 */ s32 unkA0;
    /* 0x0a4 */ s32 unkA4;
    /* 0x0a8 */ s32 unkA8;
    /* 0x0ac */ s32 unkAC;
    /* 0x0b0 */ s32 unkB0;
    /* 0x0b4 */ s32 unkB4;
    /* 0x0b8 */ u8 padB8[0x178];
    /* 0x230 */ s32 unk230;
    /* 0x234 */ s32 unk234;
    /* 0x238 */ s32 unk238;
    /* 0x23c */ u8 pad23C[0x64];
    /* 0x2a0 */ void* unk2A0;
    /* 0x2a4 */ u8 pad2A4[0x8];
    /* 0x2ac */ s32 unk2AC;
    /* 0x2b0 */ u8 pad2B0[0x4];
    /* 0x2b4 */ void* unk2B4;
    /* 0x2b8 */ u8 pad2B8[0x8];
    /* 0x2c0 */ s32 unk2C0;
    /* 0x2c4 */ u8 pad2C4[0x4];
    /* 0x2c8 */ s32 unk2C8;
    /* 0x2cc */ u8 pad2CC[0x28];
    /* 0x2f4 */ s32 unk2F4;
    /* 0x2f8 */ u8 pad2F8[0x20];
    /* 0x318 */ MKFont* unk318;
    /* 0x31c */ MKFont* unk31C;
    /* 0x320 */ u8 pad320[0x4];
    /* 0x324 */ DialogBoxTheme* unk324;
    /* 0x328 */ u8 pad328[0x4];
    /* 0x32c */ Level* unk32C;
    /* 0x330 */ u8 pad330[0x24];
    /* 0x354 */ void* unk354;
    /* 0x358 */ s32 unk358;
    /* 0x35c */ s8 unk35C;
    /* 0x35d */ s8 unk35D;
    /* 0x35e */ s8 unk35E;
    /* 0x35f */ u8 pad35F[0x5];
    /* 0x364 */ s32 unk364;
    /* 0x368 */ f32 unk368;
    /* 0x36c */ f32 unk36C;
    /* 0x370 */ u8 pad370[0x4];
    /* 0x374 */ f32 unk374;
    /* 0x378 */ f32 unk378;
    /* 0x37c */ f32 unk37C;
    /* 0x380 */ s8 unk380;
    /* 0x381 */ s8 unk381;
    /* 0x382 */ s8 unk382;
    /* 0x383 */ u8 pad383[0x1];
    /* 0x384 */ f32 unk384;
    /* 0x388 */ f32 unk388;
    /* 0x38c */ f32 unk38C;
    /* 0x390 */ u8 pad390[0x4];
    /* 0x394 */ s8 unk394;
    /* 0x395 */ u8 unk395;
    /* 0x396 */ u8 unk396;
    /* 0x397 */ u8 pad397[0x1];
    /* 0x398 */ u32 unk398;
    /* 0x39c */ u32 unk39C;
    /* 0x3a0 */ u8 unk3A0;
    /* 0x3a1 */ u8 unk3A1;
    /* 0x3a2 */ u8 unk3A2;
};

class Game_cpp {
public:
    void __sinit(void);
};

s32 SpawnerType_ResolveFromStatType(int);
void LoadGlobalResources_Deinit(void);
void LoadGlobalResources_Update(void);
void Game_CheckCommandLineParameters(void);
void Game_InitSystem(void);
void Game_Draw(void);
u8 Game_Update(void);
void Game_Deinit(void);
void Game_Init(void);
extern u8 gClearColor[0x10];
extern GameStateMachineState gameStates;
extern GameStateMachineInit gameStateInit;
extern u8 fingerprintData[0x20c];
extern GameGlobals gb;
extern CutsceneSystem cutsceneSys;
extern s8 homeDir;
extern GameStateMachine gGMState;
extern s8 * platformCode;
extern u8 bQuit;
#endif  // SPYRO_SOURCE_GAME_H
