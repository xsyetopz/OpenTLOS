#ifndef SPYRO_SOURCE_KDMEMORYCARD_H
#define SPYRO_SOURCE_KDMEMORYCARD_H

#include <dolphin/types.h>
#include "common/Source/MKMemoryCard.h"

class KDMCState;
class KDMemoryCard;
class KDMemoryCard_cpp;
class MKMemoryCardFileInfo;

class KDMemoryCard {
public:
    void LoadData_Update(int);
    void LoadData_Init(void);
    void LoadData(int, void *, int);
    void SaveData_Update(int);
    void SaveData_Init(void);
    void SaveData(int, void *, int, const char *);
    void DeleteCorrupted_Update(int);
    void DeleteCorrupted_Init(void);
    void Prepare_Update(int);
    void Prepare_Init(void);
    void Format_Update(int);
    void Format_Init(void);
    void CheckFilesExist_Update(int);
    void CheckFilesExist_Init(void);
    void CheckIsPrepared_Update(int);
    void CheckIsPrepared_Init(void);
    void CheckCard_Update(int);
    void CheckCard_Init(void);
    void IsAttached_Update(int);
    void IsAttached_Init(void);
    s32 IsBusy(void);
    void * GetNextAvailable(KDMemoryCard *);
    void * GetFirstAvailable(void);
    void SetState(KDMCState);
    s32 Update(void);
    s32 WasErrorDuringLast(void);
    void Reset(bool);
    void Init(int);
    void InitModule(void);
    s32 GetNextCard(void);
    void * GetCard(int);
    static KDMemoryCard stateData;
    static u8 state[0x4];
    static u8 numCardsPresent[0x4];
    static u8 currentCard[0x4];
    /* 0x000 */ u8 pad0[0x4];
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 unk9;
    /* 0x00a */ u8 unkA;
    /* 0x00b */ u8 unkB;
    /* 0x00c */ u8 unkC;
    /* 0x00d */ u8 unkD;
    /* 0x00e */ u8 padE[0x2];
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ s32 unk1C;
    /* 0x020 */ s32 unk20;
    /* 0x024 */ s32 unk24;
};

class KDMemoryCard_cpp {
public:
    void __sinit(void);
};

extern MKMemoryCardFileInfo tmpfileInfo;
#endif  // SPYRO_SOURCE_KDMEMORYCARD_H
