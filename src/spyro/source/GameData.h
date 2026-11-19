#ifndef SPYRO_SOURCE_GAMEDATA_H
#define SPYRO_SOURCE_GAMEDATA_H

#include <dolphin/types.h>
#include "common/Source/MKMemoryCard.h"
#include "spyro/source/CameraData.h"
#include "spyro/source/Level.h"
#include "unplaced_enums.h"

class CameraData;
class ChunkInfo;
class GameData;
class GameData_cpp;
class GameSettings;
class GameStats;
class Level;
class Stat;
class TimerInfo;

class GameData {
public:
    class SaveState {
    public:
        void ClearData(void);
        void Deinit(void);
        void Init(void);
        /* 0x000 */ s8 unk0;
    };
    void CopyToGameData(void *);
    void CopyFromGameData(void *);
    s32 GetGameDataSize(void);
    void UpdateDataHeader(void *);
    void GetSaveGameDescription(void);
    CameraData * GetCameraData(void);
    void GetGameSettings(void);
    void ClearData(void);
    void Deinit(void);
    void Init(void);
    void ModuleDeinit(void);
    void ModuleInit(void);
    GameData(void);
    void SetSaveChunk(ChunkInfo *);
    static u8 gameData[0x1b4];
    static u8 bModuleInitialised[0x1];
    /* 0x000 */ TimerInfo unk0;
    /* 0x01c */ u8 pad1C[0x4];
    /* 0x020 */ s8 unk20;
    /* 0x021 */ u8 pad21[0x1f];
    /* 0x040 */ u8 unk40;
    /* 0x041 */ u8 pad41[0x1f];
    /* 0x060 */ CameraData unk60;
    /* 0x070 */ u8 pad70[0x120];
    /* 0x190 */ Level unk190;
};

class GameData_cpp {
public:
    void __sinit(void);
};

class GameSettings {
public:
    void Init(void);
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ s32 unkC;
    /* 0x010 */ s8 unk10;
    /* 0x011 */ s8 unk11;
    /* 0x012 */ s8 unk12;
    /* 0x013 */ s8 unk13;
    /* 0x014 */ s8 unk14;
    /* 0x015 */ u8 pad15[0x3];
    /* 0x018 */ s32 unk18;
    /* 0x01c */ s32 unk1C;
};

class Stat {
public:
    void AdjustPrevious(float);
    void Add(float, bool);
    void SetValue(float, bool);
    void Init(float, float, void (*)(Stat *), float (*)(Stat *, float));
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ f32 unkC;
};

class GameStats {
public:
    void SetAttacksAvailable(unsigned int);
    f32 GetBreathAttackDamage(int, int, int);
    s32 GetBreathAttackShotType(void);
    f32 GetSpeedwayBoostCost(void);
    f32 GetOngoingBreathCost(void);
    f32 GetInitialBreathCost(void);
    void * GetCurrentBreathColor(void);
    void SetCurrentBreath(BreathElement);
    f32 TailStrikeDamage(void);
    s32 GetGemAvailable(StatType);
    void SetLevelUpPoints(int);
    void SetEverything(void);
    void Clear(void);
    void LoadIni(void);
    void Init(void);
    s32 GetCurrentBreathUpgrade(int);
    /* 0x000 */ f32 unk0;
    /* 0x004 */ u8 pad4[0x14];
    /* 0x018 */ Stat unk18;
    /* 0x028 */ u8 pad28[0x8];
    /* 0x030 */ Stat unk30;
    /* 0x040 */ u8 pad40[0x8];
    /* 0x048 */ Stat unk48;
    /* 0x058 */ u8 pad58[0x8c];
    /* 0x0e4 */ s8 unkE4;
    /* 0x0e5 */ u8 padE5[0x1];
    /* 0x0e6 */ s8 unkE6;
    /* 0x0e7 */ u8 padE7[0x1];
    /* 0x0e8 */ s32 unkE8;
    /* 0x0ec */ s32 unkEC;
    /* 0x0f0 */ f32 unkF0;
    /* 0x0f4 */ s32 unkF4;
    /* 0x0f8 */ s8 unkF8;
    /* 0x0f9 */ u8 unkF9;
    /* 0x0fa */ u8 padFA[0x20];
    /* 0x11a */ u8 unk11A;
    /* 0x11b */ u8 pad11B[0x1];
    /* 0x11c */ s32 unk11C;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: illegal type
inline s32 GameStats::GetCurrentBreathUpgrade(int arg0) {
    u8 var_r3_4478;
    void *temp_r5_4475;

    temp_r5_4475 = this + ((this->unkE8 << 5) + 0x64);
    if (arg0 == 3) {
        var_r3_4478 = 0;
        if (((s32) M2C_FIELD(temp_r5_4475, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r5_4475, s32 *, 4) == 3)) {
            var_r3_4478 = 1;
        }
        return var_r3_4478 != 0;
    }
    return *(temp_r5_4475 + (arg0 * 4));
}
#endif

#endif  // SPYRO_SOURCE_GAMEDATA_H
