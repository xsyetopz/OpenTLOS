#ifndef SPYRO_SOURCE_KDSYNKERPLAYERACTORLIST_H
#define SPYRO_SOURCE_KDSYNKERPLAYERACTORLIST_H

#include <dolphin/types.h>

class KDInput;
class KDSP_Actor;
class KDSP_ActorList;
class KDSP_EnvelopeList;
class KDSP_Subtitles;
class KDSynkerHeap;
class MKIni;
class MKIniLine;
class MKVector3;

class KDSP_ActorList {
public:
    s32 GetActorId(const char *);
    void Update(float, KDSP_EnvelopeList *, const MKVector3 &, bool);
    void ResolveLookAt(void);
    void SendMessageToActorProp(bool);
    void Deinit(bool);
    KDSP_Actor * FindActor(const char *);
    void Load(MKIni *, int &, bool, bool);
    void Parse(KDSynkerHeap *, MKIni *, int &, KDInput *);
    void HeapAddSize(KDSynkerHeap *, MKIni *);
    void Init(void);
    /* 0x000 */ s32 unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 pad8[0x4];
    /* 0x00c */ MKIniLine* unkC;
    /* 0x010 */ MKIniLine* unk10;
};

class KDSP_Subtitles {
public:
    void Update(KDSP_ActorList *, int);
    void Parse(KDSynkerHeap *, const char *);
    void HeapAddSize(KDSynkerHeap *, const char *);
    void Reset(void);
    void Init(void);
    /* 0x000 */ u8 pad0[0x98];
    /* 0x098 */ u8* unk98;
    /* 0x09c */ s32 unk9C;
    /* 0x0a0 */ s32 unkA0;
    /* 0x0a4 */ s32 unkA4;
    /* 0x0a8 */ s32 unkA8;
};

class KDSynkerHeap {
public:
    /* 0x000 */ s32 unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ void* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ void* unk18;
    /* 0x01c */ s32 unk1C;
    /* 0x020 */ s32 unk20;
};

#endif  // SPYRO_SOURCE_KDSYNKERPLAYERACTORLIST_H
