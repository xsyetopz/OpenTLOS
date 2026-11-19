#ifndef SPYRO_SOURCE_LEVEL_H
#define SPYRO_SOURCE_LEVEL_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "spyro/source/EventMessage.h"

class ChunkInfo;
class ChunkProp;
class CustomMaterialUpdater;
class EventMessage;
class Level;
class LevelInfo;
class Level_cpp;
class MKHeap;
class MKIniLine;
class MKMessage;
class MKModel;
class MKProp;
class MKVector3;
class MKVector4;
class MaterialInfo;
class QueueInfo;
class TerrainInfo;
class WorldInfo;

class ChunkInfo {
public:
    void DeinitEnv(void);
    void InitEnv(void);
    void Use(void);
    u8 IsLoaded(void);
    void UpdateState(void);
    void Load(const char **, int, bool, bool);
    void Dequeue(void);
    void Queue(void);
    s32 LoadLine(MKIniLine *);
    void Deinit(void);
    void Init(void);
    /* 0x000 */ s8* unk0;
    /* 0x004 */ void* unk4;
    /* 0x008 */ ChunkInfo* unk8;
    /* 0x00c */ s32 unkC;
    /* 0x010 */ void* unk10;
    /* 0x014 */ TerrainInfo* unk14;
    /* 0x018 */ MaterialInfo* unk18;
    /* 0x01c */ s32 unk1C;
    /* 0x020 */ s32 unk20;
    /* 0x024 */ s32 unk24;
    /* 0x028 */ u32 unk28;
    /* 0x02c */ u32 unk2C;
    /* 0x030 */ u32 unk30;
    /* 0x034 */ s8 unk34;
    /* 0x035 */ s8 unk35;
    /* 0x036 */ u16 unk36;
    /* 0x038 */ s8* unk38;
    /* 0x03c */ s8* unk3C;
    /* 0x040 */ MKModel* unk40;
    /* 0x044 */ MKModel* unk44;
    /* 0x048 */ u32 unk48;
    /* 0x04c */ f32 unk4C;
    /* 0x050 */ f32 unk50;
    /* 0x054 */ f32 unk54;
    /* 0x058 */ f32 unk58;
    /* 0x05c */ s32 unk5C;
    /* 0x060 */ s32 unk60;
};

class ChunkProp : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~ChunkProp(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual s32 LoadDone(void);
    virtual void Deinit(void);
    virtual void Message(MKMessage *);
    /* 0x04c */ EventMessage unk4C;
    /* 0x050 */ EventMessage unk50;
};

class Level {
public:
    void GetNextLevel(LevelInfo *);
    static void GetWorldInfo(void);
    void EnvDomeChanged(void);
    static void * GetStartLevelInfo(void);
    void CancelQueue(void);
    void EnableChunksForLevel(ChunkInfo *);
    u8 GetNextInQueue(QueueInfo *, bool);
    MKHeap * AddChunkToQueue(ChunkInfo *, int);
    void DOFGetPlanes(float *, float *, float *, float *);
    void DOFSetPlanes(float, float, float, float);
    void DOFApplyEffect(void);
    MKModel * GetEnvDome(void);
    void * GetLevelByName(const char *);
    void SwitchTo(ChunkInfo *);
    void SetEnvChunk(ChunkInfo *);
    void LoadChunk(ChunkInfo *, int);
    s32 SetDesiredChunks(ChunkInfo **, int);
    Level * GetNextChunk(ChunkInfo *);
    void * GetChunkByName(const char *);
    void ResolveGameSpecificProps(void);
    void ApplyViewParameters(void);
    void SetProjectionToDefaults(void);
    void FreeTempMemory(void);
    void FreeGlobalResources(void);
    void LoadGlobalResources(void);
    void FinaliseResources(void);
    void ResolveGameProps(const char *);
    void CreateNormalResources(void);
    void DrawEnvDome(void);
    void Draw(void);
    void UpdateState(void);
    void Update(void);
    void Deinit(void);
    void Init(ChunkInfo *);
    static void DeinitModule(void);
    static void InitLevelInfo(void);
    static void InitModule(void);
    static MaterialInfo * AllocMaterialInfo(void);
    static TerrainInfo * AllocTerrainInfo(void);
    ChunkInfo * AllocChunkInfo(void);
    static LevelInfo * AllocLevelInfo(void);
    void * GetLevelInfo(int);
    static s32 GetLevelCount(void);
    static u8 pGlobalLevelIni[0x4];
    static u8 pGlobalModelIni[0x4];
    static u8 levelInfoCount[0x4];
    static u8 levelInfoAllocCount[0x4];
    static u8 pLevelInfo[0x4];
    static u8 chunkInfoCount[0x4];
    static u8 chunkInfoAllocCount[0x4];
    static u8 pChunkInfo[0x4];
    static u8 terrainInfoCount[0x4];
    static u8 terrainInfoAllocCount[0x4];
    static u8 pTerrainInfo[0x4];
    static u8 materialInfoCount[0x4];
    static u8 materialInfoAllocCount[0x4];
    static u8 pMaterialInfo[0x4];
    static u8 pWorldInfo[0x4];
    /* 0x000 */ u8 unk0;
    /* 0x001 */ u8 pad1[0x3];
    /* 0x004 */ void* unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ f32 unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ u32 unk1C;
    /* 0x020 */ s32 unk20;
    /* 0x024 */ s32 unk24;
    /* 0x028 */ u8 unk28;
    /* 0x029 */ u8 pad29[0x3];
    /* 0x02c */ f32 unk2C;
    /* 0x030 */ MKModel* unk30;
    /* 0x034 */ u8 pad34[0x4];
    /* 0x038 */ f64 unk38;
    /* 0x040 */ f64 unk40;
    /* 0x048 */ s32 unk48;
    /* 0x04c */ f32 unk4C;
    /* 0x050 */ f32 unk50;
    /* 0x054 */ f32 unk54;
    /* 0x058 */ MKVector3 unk58;
    /* 0x068 */ s32 unk68;
    /* 0x06c */ f32 unk6C;
    /* 0x070 */ f32 unk70;
    /* 0x074 */ f32 unk74;
    /* 0x078 */ s32 unk78;
    /* 0x07c */ ChunkInfo* unk7C;
    /* 0x080 */ s32 unk80;
    /* 0x084 */ u8 unk84;
    /* 0x085 */ u8 pad85[0x27];
    /* 0x0ac */ s32 unkAC;
    /* 0x0b0 */ f32 unkB0;
    /* 0x0b4 */ f32 unkB4;
    /* 0x0b8 */ MKVector4 unkB8;
    /* 0x0c8 */ f64 unkC8;
    /* 0x0d0 */ f64 unkD0;
    /* 0x0d8 */ f32 unkD8;
    /* 0x0dc */ u8 padDC[0x4];
    /* 0x0e0 */ f32 unkE0;
    /* 0x0e4 */ s8 unkE4;
    /* 0x0e5 */ u8 padE5[0x3];
    /* 0x0e8 */ f32 unkE8;
    /* 0x0ec */ f32 unkEC;
};

class LevelInfo {
public:
    ChunkInfo * GetChunkByName(const char *);
    void AddChunkInfo(ChunkInfo *);
    void LoadDone(void);
    s32 LoadLine(MKIniLine *);
    void Init(void);
    /* 0x000 */ u8 pad0[0x4];
    /* 0x004 */ s8* unk4;
    /* 0x008 */ s8* unk8;
    /* 0x00c */ s8* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s8* unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ s32 unk1C;
    /* 0x020 */ s32 unk20;
    /* 0x024 */ f32 unk24;
    /* 0x028 */ s32 unk28;
    /* 0x02c */ u8 pad2C[0x4];
    /* 0x030 */ MKVector4 unk30;
    /* 0x040 */ u8 unk40;
    /* 0x041 */ u8 pad41[0x5f];
    /* 0x0a0 */ MKVector4 unkA0;
    /* 0x0b0 */ f32 unkB0;
    /* 0x0b4 */ f32 unkB4;
    /* 0x0b8 */ f32 unkB8;
    /* 0x0bc */ f32 unkBC;
    /* 0x0c0 */ MKVector4 unkC0;
    /* 0x0d0 */ MKVector3 unkD0;
    /* 0x0e0 */ f32 unkE0;
    /* 0x0e4 */ u8 padE4[0x4];
    /* 0x0e8 */ MKVector3 unkE8;
    /* 0x0f8 */ f32 unkF8;
    /* 0x0fc */ u8 padFC[0x4];
    /* 0x100 */ MKHeap* unk100;
    /* 0x104 */ MKHeap* unk104;
    /* 0x108 */ f32 unk108;
    /* 0x10c */ f32 unk10C;
    /* 0x110 */ f32 unk110;
    /* 0x114 */ s8* unk114;
    /* 0x118 */ s8* unk118;
    /* 0x11c */ ChunkInfo* unk11C;
    /* 0x120 */ WorldInfo* unk120;
    /* 0x124 */ LevelInfo* unk124;
};

class Level_cpp {
public:
    void __sinit(void);
};

class MaterialInfo {
public:
    void Destroy(void);
    void Create(MKModel *);
    s32 LoadLine(MKIniLine *);
    void Init(void);
    /* 0x000 */ s8* unk0;
    /* 0x004 */ CustomMaterialUpdater* unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ MaterialInfo* unkC;
};

class QueueInfo {
public:
    /* 0x000 */ ChunkInfo* unk0;
    /* 0x004 */ s32 unk4;
};

class TerrainInfo {
public:
    void LoadLine(MKIniLine *);
    /* 0x000 */ s8* unk0;
    /* 0x004 */ TerrainInfo* unk4;
    /* 0x008 */ s32 unk8;
};

class WorldInfo {
public:
    void AddLevelInfo(LevelInfo *);
    void LoadDone(void);
    u8 LoadSize(MKIniLine *, const char *, int *, int *, int);
    s32 LoadLine(MKIniLine *);
    void Init(void);
    /* 0x000 */ f32 unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ s32 unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ LevelInfo* unk14;
    /* 0x018 */ ChunkInfo* unk18;
    /* 0x01c */ f32 unk1C;
    /* 0x020 */ f32 unk20;
    /* 0x024 */ f32 unk24;
    /* 0x028 */ u8 pad28[0x4];
    /* 0x02c */ s32 unk2C;
    /* 0x030 */ s32 unk30;
    /* 0x034 */ s32 unk34;
    /* 0x038 */ s32 unk38;
    /* 0x03c */ s32 unk3C;
    /* 0x040 */ s32 unk40;
    /* 0x044 */ s32 unk44;
    /* 0x048 */ s32 unk48;
    /* 0x04c */ s32 unk4C;
    /* 0x050 */ s32 unk50;
    /* 0x054 */ s32 unk54;
    /* 0x058 */ s32 unk58;
    /* 0x05c */ s32 unk5C;
    /* 0x060 */ s32 unk60;
    /* 0x064 */ s32 unk64;
    /* 0x068 */ s32 unk68;
    /* 0x06c */ f32 unk6C;
    /* 0x070 */ f32 unk70;
    /* 0x074 */ f32 unk74;
    /* 0x078 */ f32 unk78;
    /* 0x07c */ s8 unk7C;
    /* 0x07d */ u8 pad7D[0x3];
    /* 0x080 */ u8 unk80;
    /* 0x081 */ u8 pad81[0x5f];
    /* 0x0e0 */ MKVector4 unkE0;
    /* 0x0f0 */ f32 unkF0;
    /* 0x0f4 */ f32 unkF4;
    /* 0x0f8 */ s32 unkF8;
    /* 0x0fc */ s32 unkFC;
};

extern u8 pGlobalLevelName[0x4];
extern u8 pGlobalLV3Name[0x4];
extern u8 pGlobalModelName[0x4];
// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline ChunkProp::~ChunkProp() {
    if (&this->unk50 != NULL) {
        this->unk50.Deinit();
    }
    if (&this->unk4C != NULL) {
        this->unk4C.Deinit();
    }
    if (this != NULL) {
    }
}

inline void *Level::GetLevelInfo(int arg0) {
    return (void *) (*Level::pLevelInfo + ((s32) this * 0x128));
}

inline s32 Level::GetLevelCount() {
    return *Level::levelInfoCount;
}

inline void Level::GetNextLevel(LevelInfo *arg0) {
    if (this != NULL) {

    }
}

inline void Level::GetWorldInfo() {

}

#endif  // SPYRO_SOURCE_LEVEL_H
