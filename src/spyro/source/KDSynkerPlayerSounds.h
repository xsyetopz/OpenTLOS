#ifndef SPYRO_SOURCE_KDSYNKERPLAYERSOUNDS_H
#define SPYRO_SOURCE_KDSYNKERPLAYERSOUNDS_H

#include <dolphin/types.h>

class KDSP_ActorList;
class KDSP_Sounds;
class KDSynkerHeap;
class MKIni;
class MKIniLine;

class KDSP_Sounds {
public:
    void GetDynamicSoundName(int);
    void GetDynamicBankName(int);
    void ResolveActors(KDSP_ActorList *);
    void ParseDynamicSFX(KDSynkerHeap *, MKIni *);
    void HeapAddSize(KDSynkerHeap *, MKIni *);
    void Deinit(void);
    s32 WaitingForSoundPackage(int *);
    s32 Update(int, float, int, int *, int *);
    void UnloadPlaying(int *);
    s32 LoadDynamicSoundBank(int *, bool);
    void LoadStaticSoundBank(const char *, bool);
    void Init(void);
    /* 0x000 */ u8 unk0;
    /* 0x001 */ u8 unk1;
    /* 0x002 */ u8 unk2;
    /* 0x003 */ u8 pad3[0x1];
    /* 0x004 */ MKIniLine* unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ void* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ s32 unk1C;
    /* 0x020 */ s32 unk20;
    /* 0x024 */ s32 unk24;
};

#endif  // SPYRO_SOURCE_KDSYNKERPLAYERSOUNDS_H
