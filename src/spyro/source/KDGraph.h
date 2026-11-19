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
    virtual MKVector3 GetPos(void) const;
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
    virtual s32 LoadDone(void);
    virtual void Deinit(void);
    virtual f32 Resolve(void);
    /* 0x04c */ u8 pad4C[0x4];
    /* 0x050 */ u8 unk50;
    /* 0x051 */ u8 pad51[0x3b];
    /* 0x08c */ s32 unk8C;
    /* 0x090 */ s32 unk90;
    /* 0x094 */ s32 unk94;
    /* 0x098 */ s32 unk98;
    /* 0x09c */ s32 unk9C;
    /* 0x0a0 */ s32 unkA0;
    /* 0x0a4 */ s32 unkA4;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

inline MKVector3 KDGraphNode::GetPos() const {
    MKVector3 result;
    MKVector3 *sret = &result;
    M2C_FIELD(sret, f64 *, 0) = (f64) this->unk8;
    M2C_FIELD(sret, f64 *, 8) = (f64) this->unk10;
    return result;
}

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to 'signed char *'
inline void KDGraphNode::SetPos(MKVector3 arg0) {
    this->unk8 = M2C_FIELD(arg0, f64 *, 0);
    this->unk10 = M2C_FIELD(arg0, f64 *, 8);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'KDGraphNode' to 'unsigned long'
inline s32 KDGraphNode::FreeLinkAvaliable() {
    s32 var_ctr_418;
    s32 var_r4_417;
    s32 var_r5_416;

    var_r5_416 = 0;
    var_r4_417 = 0;
    var_ctr_418 = 6;
loop_1:
    if ((u32) *(this + (var_r4_417 + 0x18)) == 0U) {
        return var_r5_416;
    }
    var_r5_416 += 1;
    var_r4_417 += 4;
    var_ctr_418 -= 1;
    if (var_ctr_418 == 0) {
        return -1;
    }
    goto loop_1;
}
#endif

inline s32 KDGraphNode::IsFreeLink(int arg0) const {
    return M2C_FIELD((this + (arg0 * 4)), s32 *, 0x18) == 0;
}

inline s32 KDGraphNode::GetNumLinks() const {
    return this->unk30;
}

inline KDGraphNodeProp::~KDGraphNodeProp() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
        }
    }
}

inline void KDGraphNodeProp::Deinit() {
    MKProp::Deinit();
}

#endif  // SPYRO_SOURCE_KDGRAPH_H
