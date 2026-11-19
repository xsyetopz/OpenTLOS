#ifndef COMMON_SOURCE_MKMETADATA_H
#define COMMON_SOURCE_MKMETADATA_H

#include <dolphin/types.h>

class MKMetadata;

class MKMetadata {
public:
    /* 0x000 */ MKMetadata* unk0;
    /* 0x004 */ MKMetadata* unk4;
};

void * MKMetadata_Resolve(MKMetadata *, int, const char **);
void MKMetadata_Close(MKMetadata *);
void MKMetadata_Open(const char *, const char *, int *);
void MKMetadata_OpenFromBuffer(const void *, const void *, int *);
void MKMetadata_DeinitModule(void);
void MKMetadata_InitModule(void);
#endif  // COMMON_SOURCE_MKMETADATA_H
