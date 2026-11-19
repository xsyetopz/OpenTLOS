#ifndef COMMON_SOURCE_MKLEVELCHUNK_H
#define COMMON_SOURCE_MKLEVELCHUNK_H

#include <dolphin/types.h>
#include "common/Source/MKHeap.h"

class MKChunkRequest;
class MKHeap;
class MKLevelChunk;
class MKMessage;
class MKModel;
class MKProp;
class MKPropDescriptor;
class MKVector3;

class MKLevelChunk {
public:
    class MKLevelChunkInit;
    virtual ~MKLevelChunk(void);
    virtual void Create(int, int, int, int, const char *);
    virtual void Destroy(void);
    virtual void SetActivePoint(const MKVector3 &) = 0;
    virtual void UpdateState(void);
    virtual s32 ResetAllProps(void) = 0;
    virtual s32 ResolveAllProps(void) = 0;
    virtual void CalculateVisibility(bool) = 0;
    virtual void CalculateUpdateDistances(void) = 0;
    virtual s32 Optimise(void) = 0;
    virtual void UpdateProps(void) = 0;
    virtual void DrawTerrain(int) = 0;
    virtual void DrawProps(int) = 0;
    virtual void SendMessage(MKMessage *, unsigned int, bool, MKVector3 *, float, bool) = 0;
    virtual void LockChunk(int, bool);
    virtual void UnlockChunk(void);
    virtual void SetTerrainDrawCallback(void (*)(MKModel *, unsigned short *, void *)) = 0;
    virtual void SetTerrainUserData(const char *, void *) = 0;
    virtual MKPropDescriptor * GetDescriptorList(void) const;
    virtual void Init(MKLevelChunk::MKLevelChunkInit *);
    virtual void Deinit(void);
    virtual void AddProp(MKProp *) = 0;
    virtual void AddDescriptor(MKPropDescriptor *) = 0;
    virtual MKModel * AddTerrainModel(const char *, int) = 0;
    virtual MKPropDescriptor * FindDescriptor(const char *) = 0;
    virtual MKProp * FindProp(const char *) = 0;
    virtual s32 FindTerrainModel(const char *) = 0;
    virtual void DrawWater(int) = 0;
    virtual void PostDrawWater(void) = 0;
    virtual s32 InitChunk(void);
    virtual s32 DeinitChunk(void);
    virtual f32 GetDistanceFromPoint(const MKVector3 &) = 0;
    virtual void EnableTerrainModel(const char *, bool) = 0;
    virtual s32 GetPropsInRange(MKProp **, int, const MKVector3 &, float, int, bool) = 0;
    void * Game_ChunkChooser(MKChunkRequest *, char **, int, MKLevelChunk **, int);
    s32 Game_ChunkInitComplete(MKLevelChunk *, bool);
    s32 Game_UserInit(MKLevelChunk *, bool);
    s32 Update_AppLocked(void);
    s32 Update_Release(void);
    s32 Update_Deinit(void);
    s32 Update_Ready(void);
    s32 Update_Reset(void);
    s32 Update_Optimise(void);
    s32 Update_Resolve(void);
    s32 Update_Init(void);
    s32 Update_Loading(void);
    s32 Update_LoadSound(void);
    s32 Update_LoadingIni(void);
    s32 Update_Unloaded(void);
    void ApplyFlags(unsigned int);
    MKModel * AddWaterModel(const char *);
    u8 IsReady(void);
    void QueueChunkLoad(const char *, const char *, bool);
    s8 * GetChunkName(void);
    void Release(void);
    void Deactivate(void);
    void Activate(void);
    static u8 idCounter[0x4];
    static u8 pResolver[0x4];
    /* 0x004 */ u32 unk4;
    /* 0x008 */ void* unk8;
    /* 0x00c */ s32 unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ MKHeap unk14;
    /* 0x134 */ s32 unk134;
    /* 0x138 */ u32 unk138;
    /* 0x13c */ u32 unk13C;
    /* 0x140 */ s32 unk140;
    /* 0x144 */ f32 unk144;
    /* 0x148 */ s32 unk148;
};

#endif  // COMMON_SOURCE_MKLEVELCHUNK_H
