#ifndef SPYRO_SOURCE_CHUNKDATA_H
#define SPYRO_SOURCE_CHUNKDATA_H

#include <dolphin/types.h>

class ChunkData;

class ChunkData {
public:
    ChunkData(void);
    static u8 pCurrentEventStrings[0x4];
};

#endif  // SPYRO_SOURCE_CHUNKDATA_H
