#ifndef SPYRO_SOURCE_KDGRAPH_H
#define SPYRO_SOURCE_KDGRAPH_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"

class KDGraphNode;
class KDGraphNodeProp;
class MKIniLine;
class MKProp;
class MKVector3;

class KDGraphNode {
public:
    virtual void Init(void);
    virtual s32 Link(KDGraphNode *, int);
    virtual s32 Unlink(KDGraphNode *);
    virtual s32 Unlink(int);
    virtual s32 GetNumLinks(void) const;
    virtual s32 FreeLinkAvaliable(void);
    virtual s32 IsFreeLink(int) const;
    virtual s32 IsLinked(KDGraphNode *) const;
    virtual s32 GetLink(int);
    virtual void SetPos(MKVector3);
    virtual void GetPos(void) const;
    KDGraphNode(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ f64 unk8;
    /* 0x010 */ f64 unk10;
    /* 0x018 */ u8 pad18[0x18];
    /* 0x030 */ s32 unk30;
};

class KDGraphNodeProp : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~KDGraphNodeProp(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    /* 0x04c */ u8 pad4C[0x40];
    /* 0x08c */ s32 unk8C;
    /* 0x090 */ s32 unk90;
    /* 0x094 */ s32 unk94;
    /* 0x098 */ s32 unk98;
    /* 0x09c */ s32 unk9C;
    /* 0x0a0 */ s32 unkA0;
    /* 0x0a4 */ s32 unkA4;
};

#endif  // SPYRO_SOURCE_KDGRAPH_H
