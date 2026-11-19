#ifndef COMMON_SOURCE_MKCHUNKSCENEMANAGER_H
#define COMMON_SOURCE_MKCHUNKSCENEMANAGER_H

#include <dolphin/types.h>
#include "common/Source/MKBaseSceneManager.h"

class MKChunkRequest;
class MKChunkSceneManager;
class MKHeap;
class MKLevelChunk;
class MKMessage;
class MKProp;
class MKPropDescriptor;
class MKSceneManager;
class MKSceneManagerInit;
class MKTerrainModel;
class MKVector3;

class MKChunkRequest {
public:
    /* 0x000 */ s32 unk0;
    /* 0x004 */ s8* unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ u8 unkC;
};

class MKChunkSceneManager : public MKSceneManager {  // base: vtable prefix
public:
    virtual void Init(MKSceneManagerInit *);
    virtual void Deinit(void);
    virtual void Optimise(void);
    virtual void ResetAll(void);
    virtual void ResolveAllProps(void);
    virtual void Update(void);
    virtual void UpdateState(void);
    virtual void DrawProps(int);
    virtual void DrawTerrain(int);
    virtual s32 GetChunkArray(void);
    virtual s32 IsChunkLoaded(const char *);
    virtual MKLevelChunk * QueueChunkLoad(const char *, MKChunkRequest *, char **, int, const char *, bool, bool);
    virtual MKLevelChunk * LockChunk(MKChunkRequest *, char **, int);
    virtual void UnlockChunk(MKLevelChunk *);
    virtual s32 IsLockedChunkReadyForUse(MKLevelChunk *);
    virtual void EnableAllChunks(bool);
    virtual void AddProp(MKProp *);
    virtual void AddTerrainModel(const char *, int);
    virtual void AddPropDescriptor(MKPropDescriptor *);
    virtual u32 FindDescriptor(const char *);
    virtual u32 FindProp(const char *);
    virtual void DrawWater(void);
    virtual void PostDrawWater(void);
    virtual void SetWorkingChunk(MKLevelChunk *);
    virtual void SetActivePoint(const MKVector3 &);
    virtual MKLevelChunk * GetWorkingChunk(void);
    virtual s32 GetChunkAt(const MKVector3 &);
    virtual s32 GetCollisionManager(void);
    virtual void EnableTerrainModel(const char *, bool);
    virtual void CalculateVisibility(bool);
    virtual void CalculateUpdateDistances(void);
    virtual void SendMessage(MKMessage *, unsigned int, bool, MKVector3 *, float, bool);
    virtual s32 GetPropsInRange(MKProp **, int, const MKVector3 &, float, int, bool);
    virtual s32 IsEnabled(MKProp *, int);
    virtual s32 IsEnabled(MKTerrainModel *, int);
    virtual void EnableZones(unsigned int, bool, int);
    virtual void DisableZones(unsigned int, bool, int);
    virtual void SetChunkUpdateOrder(MKLevelChunk **);
    virtual void SetChunkDrawOrder(MKLevelChunk **);
    virtual void FindDescriptorInLocalChunk(const char *);
    virtual u32 FindTerrainModel(const char *);
    MKChunkSceneManager * StripExtension(const char *, char);
    static u8 bChunksUseHeaps[0x1];
    static u8 bPackageSystemInUse[0x1];
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ void* unk8;
    /* 0x00c */ u8 padC[0xd];
    /* 0x019 */ s8 unk19;
    /* 0x01a */ u8 pad1A[0x76];
    /* 0x090 */ s32 unk90;
    /* 0x094 */ u8 pad94[0x14];
    /* 0x0a8 */ s32 unkA8;
    /* 0x0ac */ u8 padAC[0x2c];
    /* 0x0d8 */ MKHeap* unkD8;
    /* 0x0dc */ void* unkDC;
    /* 0x0e0 */ u8 padE0[0x4];
    /* 0x0e4 */ u8 unkE4;
    /* 0x0e5 */ u8 padE5[0x3];
    /* 0x0e8 */ s32 unkE8;
    /* 0x0ec */ MKLevelChunk** unkEC;
    /* 0x0f0 */ u8 padF0[0x4];
    /* 0x0f4 */ MKLevelChunk* unkF4;
    /* 0x0f8 */ u8 padF8[0x40];
    /* 0x138 */ s32 unk138;
};

class MKTerrainModel {
public:
    /* 0x000 */ u8 pad0[0x4];
    /* 0x004 */ s32 unk4;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline s32 MKChunkSceneManager::GetChunkArray() {
    return this->unkE8;
}

#endif  // COMMON_SOURCE_MKCHUNKSCENEMANAGER_H
