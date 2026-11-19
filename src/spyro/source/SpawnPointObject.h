#ifndef SPYRO_SOURCE_SPAWNPOINTOBJECT_H
#define SPYRO_SOURCE_SPAWNPOINTOBJECT_H

#include <dolphin/types.h>

class MKIniLine;
class SpawnPointData;
class SpawnPointObject;
class SpawnerObject;

class SpawnPointObject {
public:
    void Resolve(void);
    void LoadDone(void);
    s32 LoadLine(MKIniLine *);
    void Deinit(void);
    void Init(SpawnPointData *);
    /* 0x000 */ SpawnerObject* unk0;
    /* 0x004 */ void* unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ s32 unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ u8 pad1C[0x24];
    /* 0x040 */ f32 unk40;
    /* 0x044 */ f32 unk44;
    /* 0x048 */ f32 unk48;
    /* 0x04c */ f32 unk4C;
    /* 0x050 */ u8 unk50;
    /* 0x051 */ s8 unk51;
    /* 0x052 */ u8 unk52;
};

#endif  // SPYRO_SOURCE_SPAWNPOINTOBJECT_H
