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
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline SpawnPointData::~SpawnPointData() {
}

#endif  // SPYRO_SOURCE_SPAWNPOINTDATA_H
