#ifndef SPYRO_SOURCE_KDCAMERAMESSAGESTORAGE_H
#define SPYRO_SOURCE_KDCAMERAMESSAGESTORAGE_H

#include <dolphin/types.h>

class KDMessageStorage;
class KDMessageStorageDescriptor;
class MKHeap;
class MKMessage;

class KDMessageStorage {
public:
    s32 * GetMessageAtIndex(int);
    void * GetDesc(int);
    s32 * GetMessage(int);
    s32 CanMessageBeStored(int);
    u8 IsMessageStored(int);
    void StoreMessage(MKMessage *);
    void Deinit(void);
    void Init(KDMessageStorageDescriptor *, int);
    /* 0x000 */ MKHeap* unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ KDMessageStorageDescriptor* unkC;
    /* 0x010 */ s32 unk10;
};

#endif  // SPYRO_SOURCE_KDCAMERAMESSAGESTORAGE_H
