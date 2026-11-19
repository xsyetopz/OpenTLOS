#ifndef COMMON_SOURCE_MKBASESCENEMANAGER_H
#define COMMON_SOURCE_MKBASESCENEMANAGER_H

#include <dolphin/types.h>

class MKChunkRequest;
class MKIni;
class MKIniLine;
class MKLevelChunk;
class MKMessage;
class MKProp;
class MKPropCreationTable;
class MKPropDescriptor;
class MKSceneManager;
class MKSceneManagerInit;
class MKTerrainModel;
class MKVector3;

class MKSceneManager {
public:
    virtual void Init(MKSceneManagerInit *);
    virtual void Deinit(void);
    virtual void Optimise(void) = 0;
    virtual void ResetAll(void) = 0;
    virtual void ResolveAllProps(void) = 0;
    virtual void Update(void) = 0;
    virtual void UpdateState(void) = 0;
    virtual void DrawProps(int) = 0;
    virtual void DrawTerrain(int) = 0;
    virtual s32 GetChunkArray(void) = 0;
    virtual s32 IsChunkLoaded(const char *) = 0;
    virtual MKLevelChunk * QueueChunkLoad(const char *, MKChunkRequest *, char **, int, const char *, bool, bool) = 0;
    virtual MKLevelChunk * LockChunk(MKChunkRequest *, char **, int) = 0;
    virtual void UnlockChunk(MKLevelChunk *) = 0;
    virtual s32 IsLockedChunkReadyForUse(MKLevelChunk *) = 0;
    virtual void EnableAllChunks(bool) = 0;
    virtual void BeginChunkLoad(MKIni *);
    virtual s32 LoadChunk(void);
    virtual void AddProp(MKProp *) = 0;
    virtual void AddTerrainModel(const char *, int) = 0;
    virtual void AddPropDescriptor(MKPropDescriptor *) = 0;
    virtual u32 FindDescriptor(const char *) = 0;
    virtual u32 FindProp(const char *) = 0;
    virtual void DrawWater(void) = 0;
    virtual void PostDrawWater(void) = 0;
    virtual void DrawDebug(void);
    virtual void DumpState(void);
    virtual void SetWorkingChunk(MKLevelChunk *) = 0;
    virtual void SetActivePoint(const MKVector3 &) = 0;
    virtual MKLevelChunk * GetWorkingChunk(void) = 0;
    virtual s32 GetChunkAt(const MKVector3 &) = 0;
    virtual s32 GetCollisionManager(void) = 0;
    virtual void EnableTerrainModel(const char *, bool) = 0;
    virtual void CalculateVisibility(bool) = 0;
    virtual void CalculateUpdateDistances(void) = 0;
    virtual void SendMessage(MKMessage *, unsigned int, bool, MKVector3 *, float, bool) = 0;
    virtual s32 GetPropsInRange(MKProp **, int, const MKVector3 &, float, int, bool) = 0;
    virtual s32 IsEnabled(MKProp *, int) = 0;
    virtual s32 IsEnabled(MKTerrainModel *, int) = 0;
    virtual void EnableZones(unsigned int, bool, int) = 0;
    virtual void DisableZones(unsigned int, bool, int) = 0;
    virtual void SetChunkUpdateOrder(MKLevelChunk **) = 0;
    virtual void SetChunkDrawOrder(MKLevelChunk **) = 0;
    virtual void FindDescriptorInLocalChunk(const char *) = 0;
    void CreatePropDeferred(const char *, MKProp **);
    void * CreateProp(const char *);
    MKPropCreationTable * CreateDescriptor(const char *, MKPropCreationTable **);
    void PropResolver_Deinit(void);
    void * PropResolver_Resolve(int);
    void PropResolver_Remove(MKProp *);
    void PropResolver_Add(MKProp *, const char *);
    void PropResolver_Init(void);
    static u8 pPropMapping[0x4];
    static u8 nmbrOfMappings[0x4];
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ s8** unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s8 unk18;
    /* 0x019 */ s8 unk19;
    /* 0x01a */ u8 pad1A[0x2];
    /* 0x01c */ void* unk1C;
    /* 0x020 */ s32 unk20;
    /* 0x024 */ MKIni* unk24;
    /* 0x028 */ s32 unk28;
    /* 0x02c */ u8 pad2C[0x18];
    /* 0x044 */ void* unk44;
    /* 0x048 */ u8 pad48[0x68];
    /* 0x0b0 */ f32 unkB0;
    /* 0x0b4 */ s32 unkB4;
    /* 0x0b8 */ s32 unkB8;
    /* 0x0bc */ s32 unkBC;
    /* 0x0c0 */ MKIniLine* unkC0;
    /* 0x0c4 */ MKIniLine* unkC4;
    /* 0x0c8 */ MKPropCreationTable* unkC8;
    /* 0x0cc */ MKPropCreationTable* unkCC;
    /* 0x0d0 */ void* unkD0;
};

class MKSceneManagerInit {
public:
    /* 0x000 */ u8 pad0[0x20];
    /* 0x020 */ f32 unk20;
    /* 0x024 */ f32 unk24;
    /* 0x028 */ MKIni* unk28;
    /* 0x02c */ s32 unk2C;
    /* 0x030 */ void* unk30;
    /* 0x034 */ u8 pad34[0x4];
    /* 0x038 */ f32 unk38;
    /* 0x03c */ u8 pad3C[0x94];
    /* 0x0d0 */ s32 unkD0;
};

void ComparePropCreatorFunc(const void *, const void *);
#endif  // COMMON_SOURCE_MKBASESCENEMANAGER_H
