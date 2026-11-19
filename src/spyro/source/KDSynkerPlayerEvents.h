#ifndef SPYRO_SOURCE_KDSYNKERPLAYEREVENTS_H
#define SPYRO_SOURCE_KDSYNKERPLAYEREVENTS_H

#include <dolphin/types.h>

class KDSP_ActorList;
class KDSP_EnvelopeList;
class KDSP_Events;
class KDSynkerHeap;
class KDSynkerPlayer3;
class KDSynkerPlayerEvent;
class KDSynkerPlayerEventCreationTable;
class KDSynkerPlayerEventLoadInfo;
class MKAnimScript;
class MKIni;
class MKIniLine;
class MKModel;
class MKProp;
class MKVector3;

class KDSP_Events {
public:
    KDSynkerPlayerEvent * CreateEvent(const char *);
    void UpdateSfx(KDSP_ActorList *, int, float);
    void StopSfx(void);
    void SkipToEnd(void);
    void Deinit(void);
    u8 IsTweenAnimEvent(const char *);
    u8 IsSoundEvent(const char *);
    void * FindEvent(const char *);
    void UpdateTweenAnims(int, KDSP_EnvelopeList *);
    void Update(KDSynkerPlayer3 *, float, bool);
    void Draw(void);
    void Parse(KDSynkerPlayer3 *, KDSynkerHeap *, const char *, MKIni *, bool, KDSP_ActorList *);
    void HeapAddSize(KDSynkerHeap *, MKIni *, bool);
    void AddEventType(const char *);
    void Init(KDSynkerPlayer3 *, KDSynkerPlayerEventCreationTable *);
    /* 0x000 */ MKIniLine* unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ void* unk8;
    /* 0x00c */ s32 unkC;
    /* 0x010 */ void* unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ void* unk18;
    /* 0x01c */ s32 unk1C;
    /* 0x020 */ void* unk20;
    /* 0x024 */ KDSynkerPlayerEventCreationTable* unk24;
};

class KDSynkerPlayerEvent {
public:
    virtual void Init(void);
    virtual void Deinit(void);
    virtual s32 LoadLine(void);
    virtual void LoadDone(void);
    virtual void Enter(void);
    virtual void Update(void);
    virtual void Exit(void);
    virtual void Draw(void);
    void Load(MKIniLine *);
    s32 LoadProp(const char *, MKProp **);
    s32 LoadVector3(const char *, MKVector3 *);
    s32 LoadFloat(const char *, float *);
    s32 LoadString(const char *, char *);
    s32 LoadBool(const char *, bool *);
    u8 LoadInt(const char *, int *);
    void LoadNode(const char *, MKModel **, int *);
    s32 LoadActorModel(const char *, MKModel **);
    s32 LoadActorAnimScript(const char *, MKAnimScript **);
    u8 LoadActorID(const char *, int *);
    static KDSynkerPlayerEvent loadInfo;
    static KDSynkerPlayerEvent updateData;
    static KDSynkerPlayerEvent pSynker;
    static KDSynkerPlayerEvent pLine;
};

class KDSynkerPlayerEventCreationTable {
public:
    /* 0x000 */ u32 unk0;
};

class KDSynkerPlayerEventLoadInfo {
public:
    void Init(void);
    /* 0x000 */ s32 unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ s8 unkC;
};

extern u8 PLAYSOUND3D_STRING[0x4];
extern u8 HEADTWEEN_STRING[0x4];
#endif  // SPYRO_SOURCE_KDSYNKERPLAYEREVENTS_H
