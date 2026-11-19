#ifndef COMMON_SOURCE_MKHEAP_H
#define COMMON_SOURCE_MKHEAP_H

#include <dolphin/types.h>

class Level;
class MKHeap;
class MKModel;

class MKHeap {
public:
    void SetTempMemOverrideStatus(bool);
    void DeactivateTempMemOverride(void);
    void ActivateTempMemOverride(void);
    void GetMemoryStatistics(int *, int *, int *);
    void DumpFragmentation(void);
    void DumpTBlocks(void);
    u8 ExistsInHeap(const void *);
    void FreeFromAnyHeap(void *, const char *, int);
    void TFree(const void *, const char *, int);
    void * TReAlloc(void *, int, const char *, int);
    void * TAlloc(int, const char *, int, bool);
    void Free(const void *, const char *, int);
    void * ReAlloc(void *, int, const char *, int);
    void * Alloc(int, const char *, int);
    s32 Release(int);
    s32 Mark(void);
    u32 Main(void);
    MKHeap * Current(void);
    s32 Pop(void);
    void Push(void);
    u32 GetPeak(void);
    void UpdatePeak(void);
    void GetHeapStatistics(int *, int *, int *, int *, int *);
    u8 IsWithinAHeap(void);
    void RemoveHeapFromGlobalList(void);
    void AddHeapToGlobalList(void);
    void DeInit(void);
    void Init(int, int, const char *, void *);
    void InitModule(void);
    static u8 heapObjects[0x28];
    static u8 heapList[0x28];
    static u8 peak[0x4];
    static u8 mainHeapPeak[0x4];
    static u8 tempHeapPeak[0x4];
    static u8 currentHeap[0x4];
    static u8 tempMemOverride[0x4];
    /* 0x000 */ MKHeap* unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ s32 unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ void* unk1C;
    /* 0x020 */ s8* unk20;
    /* 0x024 */ s32 unk24;
    /* 0x028 */ MKHeap* unk28;
    /* 0x02c */ s32 unk2C;
    /* 0x030 */ f64 unk30;
    /* 0x038 */ f32 unk38;
    /* 0x03c */ s32 unk3C;
    /* 0x040 */ s32 unk40;
    /* 0x044 */ s32 unk44;
    /* 0x048 */ MKHeap* unk48;
    /* 0x04c */ s8 unk4C;
    /* 0x04d */ u8 pad4D[0x3];
    /* 0x050 */ s32 unk50;
    /* 0x054 */ void* unk54;
    /* 0x058 */ s32 unk58;
    /* 0x05c */ u8 pad5C[0x4];
    /* 0x060 */ s32 unk60;
    /* 0x064 */ u32 unk64;
    /* 0x068 */ s32 unk68;
    /* 0x06c */ f32 unk6C;
    /* 0x070 */ u32 unk70;
    /* 0x074 */ f32 unk74;
    /* 0x078 */ f32 unk78;
    /* 0x07c */ f32 unk7C;
    /* 0x080 */ f32 unk80;
    /* 0x084 */ f32 unk84;
    /* 0x088 */ u8 pad88[0x14];
    /* 0x09c */ MKModel* unk9C;
    /* 0x0a0 */ u8 padA0[0x4];
    /* 0x0a4 */ f32 unkA4;
    /* 0x0a8 */ f32 unkA8;
    /* 0x0ac */ u8 padAC[0x1c];
    /* 0x0c8 */ void* unkC8;
    /* 0x0cc */ u8 padCC[0x28];
    /* 0x0f4 */ s32 unkF4;
    /* 0x0f8 */ u8 padF8[0x20];
    /* 0x118 */ s8 unk118;
    /* 0x119 */ u8 pad119[0x3];
    /* 0x11c */ Level* unk11C;
};

void __nwa(unsigned long, const char *, int);
void __nw(unsigned long, const char *, int);
void __dla(void *);
void __dl(void *);
#endif  // COMMON_SOURCE_MKHEAP_H
