#ifndef SPYRO_SOURCE_KDSYNKERPLAYERTOOLS_H
#define SPYRO_SOURCE_KDSYNKERPLAYERTOOLS_H

#include <dolphin/types.h>

class KDBasicEnvelope;
class KDSP_Bar;
class KDSP_EnvelopeList;
class KDSynkerHeap;
class KDUniformSpline;
class MKIni;
class MKIniLine;
class MKModel;

class KDSP_EnvelopeList {
public:
    s32 * GetEnvelope(int);
    void LoadEnvelope(MKIniLine *, KDBasicEnvelope *);
    void Deinit(void);
    void Parse(KDSynkerHeap *, MKIni *);
    void HeapAddSize(KDSynkerHeap *, MKIni *);
    void Init(void);
    /* 0x000 */ s32 unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ MKIniLine* unk8;
};

u16 KDSP_ToolsGetMatchingNodeIndex(MKModel *, const char *);
s32 KDSP_ToolsGetSplinePercent(KDSP_Bar *, KDUniformSpline *, KDBasicEnvelope *, float, int &, float &);
#endif  // SPYRO_SOURCE_KDSYNKERPLAYERTOOLS_H
