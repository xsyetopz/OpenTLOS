#ifndef SPYRO_SOURCE_CHARACTERGRAPH_H
#define SPYRO_SOURCE_CHARACTERGRAPH_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/KDGraph.h"

class CharacterGraphManager;
class CharacterGraphNode;
class CharacterGraphNodeProp;
class DataMap;
class EventMessage;
class KDGraphNode;
class KDSplinePathSegmentProp;
class LinkInformation;
class MKIniLine;
class MKMessage;
class MKProp;

class CharacterGraphManager {
public:
    void Deinit(void);
    void Init(void);
};

class CharacterGraphNode : public KDGraphNode {  // base: vtable prefix
public:
    virtual void Init(void);
    void SendArriveMessage(void);
    s32 GetLinkPath(CharacterGraphNode *);
    s32 GetLinkInfo(CharacterGraphNode *);
    CharacterGraphNode * GetNextNode(void);
    CharacterGraphNode * GetRandomLink(int);
    CharacterGraphNode * GetLink(int) const;
    s32 IsLinked(CharacterGraphNode *) const;
    s32 Link(CharacterGraphNode *, int, LinkInformation, KDSplinePathSegmentProp *);
    CharacterGraphNode(void);
    /* 0x004 */ u8 pad4[0x2c];
    /* 0x030 */ s32 unk30;
    /* 0x034 */ u8 pad34[0x4];
    /* 0x038 */ EventMessage unk38;
    /* 0x03c */ s32 unk3C;
    /* 0x040 */ MKProp* unk40;
    /* 0x044 */ s32 unk44;
    /* 0x048 */ s32 unk48;
    /* 0x04c */ u8 pad4C[0x34];
    /* 0x080 */ u8 unk80;
};

class CharacterGraphNodeProp : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~CharacterGraphNodeProp(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Resolve(void);
    virtual void Message(MKMessage *);
    /* 0x04c */ u8 pad4C[0x4];
    /* 0x050 */ CharacterGraphNode unk50;
    /* 0x0d1 */ u8 padD1[0x7];
    /* 0x0d8 */ s32 unkD8;
    /* 0x0dc */ s32 unkDC;
    /* 0x0e0 */ s32 unkE0;
    /* 0x0e4 */ s32 unkE4;
    /* 0x0e8 */ s32 unkE8;
    /* 0x0ec */ s32 unkEC;
    /* 0x0f0 */ s32 unkF0;
    /* 0x0f4 */ s32 unkF4;
    /* 0x0f8 */ s32 unkF8;
    /* 0x0fc */ s32 unkFC;
    /* 0x100 */ s32 unk100;
    /* 0x104 */ s32 unk104;
    /* 0x108 */ s32 unk108;
    /* 0x10c */ s32 unk10C;
};

extern DataMap CharacterGraphLinkDataMap;
// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier '__vptr'
inline CharacterGraphNodeProp::~CharacterGraphNodeProp() {
    EventMessage *temp_r3_24;

    if (this != NULL) {
        if (&this->unk50 != NULL) {
            temp_r3_24 = &this->unk50.unk38;
            this->unk50.__vptr = &__vt;
            if (temp_r3_24 != NULL) {
                temp_r3_24->Deinit();
            }
        }
        if (this != NULL) {
        }
    }
}
#endif

#endif  // SPYRO_SOURCE_CHARACTERGRAPH_H
