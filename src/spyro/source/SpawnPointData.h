#ifndef SPYRO_SOURCE_SPAWNPOINTDATA_H
#define SPYRO_SOURCE_SPAWNPOINTDATA_H

#include <dolphin/types.h>

class MKIniLine;
class SpawnPointData;

class SpawnPointData {
public:
    virtual ~SpawnPointData(void);
    virtual void Init(void) = 0;
    virtual void Deinit(void) = 0;
    virtual s32 LoadLine(MKIniLine *) = 0;
    virtual void LoadDone(void) = 0;
    virtual void Resolve(void) = 0;
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ s32 unk8;
    /* 0x00c */ s32 unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
};

#endif  // SPYRO_SOURCE_SPAWNPOINTDATA_H
