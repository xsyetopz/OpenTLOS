#ifndef SPYRO_SOURCE_KDSYNKERPLAYERACTOR_H
#define SPYRO_SOURCE_KDSYNKERPLAYERACTOR_H

#include <dolphin/types.h>
#include "common/Source/MKVector3.h"

class KDInput;
class KDSP_Actor;
class KDSP_AnimBar;
class KDSP_EnvelopeList;
class KDSP_GenericBar;
class KDSP_LookBar;
class KDSynkerHeap;
class MKAnim;
class MKAnimScript;
class MKIniLine;
class MKModel;
class MKProp;
class MKSceneManager;
class MKVector3;
class Matrix;

class KDSP_Actor {
public:
    void UpdateLookat(void);
    void UpdateAimNode(MKAnimScript *, MKVector3 &, int);
    void UpdateLookatNode(MKAnimScript *, int, int, int, KDSP_LookBar &, MKProp *, MKVector3 &, MKVector3 &, float, float, bool *, float, bool *, bool, float);
    void UpdateLipAnim(float);
    void UpdateSoundAnimEvents(const MKVector3 &, int);
    void UpdateHeadAnim(float);
    void UpdateBodyAnim(float, bool, bool);
    void UpdatePosRot(float, bool *, int *);
    s32 GetTweenAnimParams(int, int, float *, float *, int *);
    void UpdateCurrentBars(int);
    void Update(float, const MKVector3 &, bool);
    void * FindActorPath(const char *);
    s32 GetMatchingNodeIndex(const char *);
    void GetEnvelope(int);
    void SetInput(KDInput *);
    void SetEnvelopeList(KDSP_EnvelopeList *);
    MKModel * GetModel(void);
    void ParseAWFS(KDSynkerHeap *, MKIniLine *, int);
    void ResolveLookEyesBar(KDSynkerHeap *, KDSP_GenericBar *, int, int);
    void ResolveLookHeadBar(KDSynkerHeap *, KDSP_GenericBar *, int, int);
    void ResolvePosBar(KDSynkerHeap *, KDSP_GenericBar *, int, int);
    void ResolveBodyBarAnim(KDSynkerHeap *, KDSP_GenericBar *, int, int);
    void ResolveBodyBar(KDSynkerHeap *, KDSP_GenericBar *, int, int);
    void ResolveHeadBarAnim(KDSynkerHeap *, KDSP_GenericBar *, int, int);
    void ResolveHeadBar(KDSynkerHeap *, KDSP_GenericBar *, int, int);
    void ResolveLipsBarAnim(KDSynkerHeap *, KDSP_GenericBar *, int, int);
    void ResolveAnim(KDSP_AnimBar *, const char *);
    void ResolveLipsBar(KDSynkerHeap *, KDSP_GenericBar *, int, int);
    void ResolveVoiceBar(KDSynkerHeap *, KDSP_GenericBar *, int, int);
    void Draw(void);
    void Deinit(bool);
    void LoadActorSectionPostResolve(MKIniLine *, bool, int &);
    void Resolve(bool, void (*)(const char *, MKModel **, MKAnimScript **), bool);
    void UpdateCloth(void);
    void HideSpecialSubObjects(void);
    s32 LoadAWFS(KDSynkerHeap *, MKIniLine *);
    void LoadActorSection(KDSynkerHeap *, MKIniLine *, int &);
    s32 LoadADSPaths(KDSynkerHeap *, MKIniLine *);
    void HeapAddSize(KDSynkerHeap *, MKIniLine *);
    s32 HeapAddSizeAWFSBar(KDSynkerHeap *, MKIniLine *);
    u8 HeapAddSizeBar(KDSynkerHeap *, MKIniLine *, const char *, int);
    u8 LoadADSFlag(MKIniLine *, const char *, int);
    u8 LoadADSBadRef(MKIniLine *);
    u8 LoadADSPropID(MKIniLine *);
    void LoadActorDataSection(KDSynkerHeap *, MKIniLine *);
    void Init(void);
    /* 0x000 */ u8 pad0[0x28];
    /* 0x028 */ f32 unk28;
    /* 0x02c */ u8 pad2C[0x4];
    /* 0x030 */ u32 unk30;
    /* 0x034 */ Matrix* unk34;
    /* 0x038 */ MKAnimScript* unk38;
    /* 0x03c */ MKModel* unk3C;
    /* 0x040 */ s32 unk40;
    /* 0x044 */ s32 unk44;
    /* 0x048 */ void* unk48;
    /* 0x04c */ s32 unk4C;
    /* 0x050 */ void* unk50;
    /* 0x054 */ s32 unk54;
    /* 0x058 */ void* unk58;
    /* 0x05c */ s8* unk5C;
    /* 0x060 */ s8* unk60;
    /* 0x064 */ MKSceneManager* unk64;
    /* 0x068 */ s32 unk68;
    /* 0x06c */ void* unk6C;
    /* 0x070 */ MKAnimScript* unk70;
    /* 0x074 */ MKAnimScript* unk74;
    /* 0x078 */ MKIniLine* unk78;
    /* 0x07c */ s32 unk7C;
    /* 0x080 */ s32 unk80;
    /* 0x084 */ s32 unk84;
    /* 0x088 */ s32 unk88;
    /* 0x08c */ s32 unk8C;
    /* 0x090 */ s32 unk90;
    /* 0x094 */ u8 pad94[0x4];
    /* 0x098 */ s32 unk98;
    /* 0x09c */ void* unk9C;
    /* 0x0a0 */ s32 unkA0;
    /* 0x0a4 */ void* unkA4;
    /* 0x0a8 */ s32 unkA8;
    /* 0x0ac */ void* unkAC;
    /* 0x0b0 */ s32 unkB0;
    /* 0x0b4 */ void* unkB4;
    /* 0x0b8 */ s32 unkB8;
    /* 0x0bc */ s32 unkBC;
    /* 0x0c0 */ s32 unkC0;
    /* 0x0c4 */ s32 unkC4;
    /* 0x0c8 */ s32 unkC8;
    /* 0x0cc */ s32 unkCC;
    /* 0x0d0 */ s32 unkD0;
    /* 0x0d4 */ u8 padD4[0x4];
    /* 0x0d8 */ MKVector3 unkD8;
    /* 0x0e8 */ MKVector3 unkE8;
    /* 0x0f8 */ MKVector3 unkF8;
    /* 0x108 */ MKVector3 unk108;
    /* 0x118 */ f32 unk118;
    /* 0x11c */ f32 unk11C;
    /* 0x120 */ f32 unk120;
    /* 0x124 */ u8 pad124[0x4];
    /* 0x128 */ MKAnim* unk128;
    /* 0x12c */ f32 unk12C;
    /* 0x130 */ u32 unk130;
    /* 0x134 */ s32 unk134;
};

class KDSP_AnimBar {
public:
    /* 0x000 */ u8 pad0[0x8];
    /* 0x008 */ u32 unk8;
    /* 0x00c */ u8 padC[0x4];
    /* 0x010 */ u8 unk10;
};

class KDSP_GenericBar {
public:
    /* 0x000 */ s8* unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ s32 unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
};

class KDSP_LookBar {
public:
    /* 0x000 */ u8 pad0[0xc];
    /* 0x00c */ KDSP_Actor* unkC;
    /* 0x010 */ u32 unk10;
};

#endif  // SPYRO_SOURCE_KDSYNKERPLAYERACTOR_H
