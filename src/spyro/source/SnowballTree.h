#ifndef SPYRO_SOURCE_SNOWBALLTREE_H
#define SPYRO_SOURCE_SNOWBALLTREE_H

#include <dolphin/types.h>
#include "common/Source/MKVector3.h"
#include "spyro/source/KDProp.h"

class KDProp;
class KDPropDescriptor;
class MKIniLine;
class MKMessage;
class MKVector3;
class SnowballTree;
class SnowballTreeDescriptor;
class SnowballTree_cpp;

class SnowballTree : public KDProp {  // base: ctor/dtor vtable stores
public:
    virtual ~SnowballTree(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    void DropABall(void);
    /* 0x089 */ u8 pad89[0x17];
    /* 0x0a0 */ MKVector3 unkA0;
    /* 0x0b0 */ u8 unkB0;
    /* 0x0b1 */ u8 padB1[0x3];
    /* 0x0b4 */ s32 unkB4;
    /* 0x0b8 */ s32 unkB8;
    /* 0x0bc */ f32 unkBC;
    /* 0x0c0 */ f32 unkC0;
    /* 0x0c4 */ u8 unkC4;
};

class SnowballTreeDescriptor : public KDPropDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    /* 0x06d */ u8 pad6D[0x3];
    /* 0x070 */ s32 unk70;
    /* 0x074 */ s32 unk74;
    /* 0x078 */ s32 unk78;
    /* 0x07c */ s32 unk7C;
    /* 0x080 */ f32 unk80;
    /* 0x084 */ f32 unk84;
    /* 0x088 */ s32 unk88;
    /* 0x08c */ s32 unk8C;
};

class SnowballTree_cpp {
public:
    void __sinit(void);
};

void SnowBallTree_InitModule(void);
// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline SnowballTree::~SnowballTree() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
            if (temp_cr0_eq_15 == 0) {
            }
        }
    }
}

#endif  // SPYRO_SOURCE_SNOWBALLTREE_H
