#ifndef SPYRO_SOURCE_LAVACANNON_H
#define SPYRO_SOURCE_LAVACANNON_H

#include <dolphin/types.h>
#include "common/Source/MKVector3.h"
#include "spyro/source/AnimUtils.h"
#include "spyro/source/Shatterable.h"

class AnimEventDesc;
class AnimEventEntry;
class AnimEventManager;
class LavaCannon;
class LavaCannonDescriptor;
class MKIniLine;
class MKMessage;
class MKVector3;
class Shatterable;
class ShatterableDescriptor;

class AnimEventEntry {
public:
    /* 0x000 */ s8* unk0;
};

class LavaCannon : public Shatterable {  // base: base ctor call
public:
    virtual ~LavaCannon(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual s32 LoadDone(void);
    virtual void Deinit(void);
    virtual f32 Resolve(void);
    virtual void Reset(void);
    virtual void * Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    virtual void Shatter(bool, MKVector3 *, int, MKVector3 *);
    LavaCannon(void);
    void EmitExplodingEffects(void);
    void EmitFiringEffects(void);
    void SetState(int);
    /* 0x1a8 */ f64 unk1A8;
    /* 0x1b0 */ f64 unk1B0;
    /* 0x1b8 */ f64 unk1B8;
    /* 0x1c0 */ f64 unk1C0;
    /* 0x1c8 */ f64 unk1C8;
    /* 0x1d0 */ f64 unk1D0;
    /* 0x1d8 */ f32 unk1D8;
    /* 0x1dc */ f32 unk1DC;
    /* 0x1e0 */ f32 unk1E0;
    /* 0x1e4 */ u8 pad1E4[0x4];
    /* 0x1e8 */ f64 unk1E8;
    /* 0x1f0 */ f32 unk1F0;
    /* 0x1f4 */ u8 pad1F4[0x4];
    /* 0x1f8 */ MKVector3 unk1F8;
    /* 0x208 */ AnimEventManager unk208;
    /* 0x214 */ u8 pad214[0x4];
    /* 0x218 */ MKVector3 unk218;
    /* 0x228 */ s32 unk228;
    /* 0x22c */ f32 unk22C;
    /* 0x230 */ f32 unk230;
    /* 0x234 */ f32 unk234;
    /* 0x238 */ u8 unk238;
    /* 0x239 */ u8 unk239;
    /* 0x23a */ u8 pad23A[0x6];
    /* 0x240 */ void* unk240;
    /* 0x244 */ f32 unk244;
    /* 0x248 */ f32 unk248;
    /* 0x24c */ f32 unk24C;
    /* 0x250 */ f32 unk250;
    /* 0x254 */ f32 unk254;
    /* 0x258 */ f32 unk258;
    /* 0x25c */ s32 unk25C;
    /* 0x260 */ s32 unk260;
    /* 0x264 */ u8 unk264;
};

class LavaCannonDescriptor : public ShatterableDescriptor {  // base: base ctor call
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Resolve(void);
    LavaCannonDescriptor(void);
    /* 0x170 */ s32 unk170;
    /* 0x174 */ s32 unk174;
    /* 0x178 */ s32 unk178;
    /* 0x17c */ s32 unk17C;
    /* 0x180 */ s32 unk180;
    /* 0x184 */ s32 unk184;
    /* 0x188 */ s32 unk188;
    /* 0x18c */ s32 unk18C;
    /* 0x190 */ s32 unk190;
    /* 0x194 */ s32 unk194;
    /* 0x198 */ s32 unk198;
    /* 0x19c */ s32 unk19C;
    /* 0x1a0 */ u8 pad1A0[0x4];
    /* 0x1a4 */ AnimEventDesc unk1A4;
    /* 0x1ac */ AnimEventEntry unk1AC;
    /* 0x1b0 */ u8 pad1B0[0x4];
    /* 0x1b4 */ s8* unk1B4;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unkC8'
inline LavaCannon::LavaCannon() {
    this->unkC8 = &__vt + 0x48;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC8'
inline LavaCannon::~LavaCannon() {
    this->unkC8 = &__vt.unk48;
}
#endif

inline LavaCannonDescriptor::LavaCannonDescriptor() {
}

#endif  // SPYRO_SOURCE_LAVACANNON_H
