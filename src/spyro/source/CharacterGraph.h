#ifndef SPYRO_SOURCE_CHARACTERGRAPH_H
#define SPYRO_SOURCE_CHARACTERGRAPH_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/KDGraph.h"
#include "unplaced_enums.h"

class CharacterGraphManager;
class CharacterGraphNode;
class CharacterGraphNodeProp;
class DataMap;
class EventMessage;
class KDGraphNode;
class KDSplinePathSegmentProp;
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
    /* 0x04c */ s32 unk4C;
    /* 0x050 */ s32 unk50;
    /* 0x054 */ s32 unk54;
    /* 0x058 */ s32 unk58;
    /* 0x05c */ s32 unk5C;
    /* 0x060 */ s32 unk60;
    /* 0x064 */ s32 unk64;
    /* 0x068 */ u8 pad68[0x18];
    /* 0x080 */ u8 unk80;
    /* 0x081 */ u8 pad81[0x7];
    /* 0x088 */ s32 unk88;
    /* 0x08c */ s32 unk8C;
    /* 0x090 */ s32 unk90;
    /* 0x094 */ s32 unk94;
    /* 0x098 */ s32 unk98;
    /* 0x09c */ s32 unk9C;
    /* 0x0a0 */ s32 unkA0;
    /* 0x0a4 */ s32 unkA4;
    /* 0x0a8 */ s32 unkA8;
    /* 0x0ac */ s32 unkAC;
    /* 0x0b0 */ s32 unkB0;
    /* 0x0b4 */ s32 unkB4;
    /* 0x0b8 */ s32 unkB8;
    /* 0x0bc */ s32 unkBC;
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
