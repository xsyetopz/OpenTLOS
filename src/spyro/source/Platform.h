#ifndef SPYRO_SOURCE_PLATFORM_H
#define SPYRO_SOURCE_PLATFORM_H

#include <dolphin/types.h>
#include "spyro/source/GameProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/PlatformObject.h"

class GameProp;
class KDPropExDescriptor;
class MKIniLine;
class MKMessage;
class MKVector3;
class Platform;
class PlatformAttachment;
class PlatformDescriptor;
class PlatformObject;
class PlatformRider;

class PlatformRider {
public:
    void ToWorldDir(const MKVector3 &);
    void ToWorld(const MKVector3 &);
    void Attach(PlatformAttachment *);
    void Resolve(void);
    void LoadLine(MKIniLine *);
    void Init(void);
    /* 0x000 */ f64 unk0;
    /* 0x008 */ f64 unk8;
};

class Platform : public GameProp {  // base: vtable prefix
public:
    virtual ~Platform(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Reset(void);
    virtual void Message(MKMessage *);
    virtual void PropUpdate(void);
    virtual void UpdateMove(void);
    virtual void UpdateScale(void);
    virtual void UpdateSway(void);
    virtual void UpdateRotate(void);
    virtual void UpdateBob(void);
    Platform(void);
    void UpdateShadow(void);
    /* 0x0c4 */ u8 padC4[0x4];
    /* 0x0c8 */ f64 unkC8;
    /* 0x0d0 */ f64 unkD0;
    /* 0x0d8 */ f32 unkD8;
    /* 0x0dc */ f32 unkDC;
    /* 0x0e0 */ f32 unkE0;
    /* 0x0e4 */ u8 padE4[0x4];
    /* 0x0e8 */ f64 unkE8;
    /* 0x0f0 */ f64 unkF0;
    /* 0x0f8 */ f64 unkF8;
    /* 0x100 */ f64 unk100;
    /* 0x108 */ PlatformObject unk108;
    /* 0x14c */ u8 pad14C[0x4];
    /* 0x150 */ PlatformRider unk150;
    /* 0x160 */ u8 pad160[0xc];
    /* 0x16c */ f32 unk16C;
    /* 0x170 */ f32 unk170;
    /* 0x174 */ s8 unk174;
    /* 0x175 */ u8 unk175;
    /* 0x176 */ u8 pad176[0x2];
    /* 0x178 */ s32 unk178;
};

class PlatformDescriptor : public KDPropExDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    PlatformDescriptor(void);
    /* 0x0c0 */ u8 padC0[0x24];
    /* 0x0e4 */ f32 unkE4;
    /* 0x0e8 */ f32 unkE8;
    /* 0x0ec */ f32 unkEC;
    /* 0x0f0 */ f32 unkF0;
    /* 0x0f4 */ s8 unkF4;
    /* 0x0f5 */ u8 unkF5;
    /* 0x0f6 */ u8 padF6[0x2];
    /* 0x0f8 */ f32 unkF8;
    /* 0x0fc */ f32 unkFC;
    /* 0x100 */ s32 unk100;
    /* 0x104 */ u8 unk104;
    /* 0x105 */ u8 pad105[0x3];
    /* 0x108 */ f32 unk108;
    /* 0x10c */ f32 unk10C;
    /* 0x110 */ f32 unk110;
    /* 0x114 */ f32 unk114;
    /* 0x118 */ u8 unk118;
    /* 0x119 */ u8 pad119[0x3];
    /* 0x11c */ f32 unk11C;
    /* 0x120 */ f32 unk120;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier 'KDSound_Stop'
inline Platform::~Platform() {
    PlatformAttachment *temp_r0_19896;
    PlatformAttachment *temp_r4_19894;
    void *temp_r0_19878;
    void *temp_r4_19881;

    if (this != NULL) {
        if (&this->unk178 != NULL) {
            KDSound_Stop(&this->unk178);
        }
        if ((this + 0x15C) != NULL) {
            temp_r0_19878 = this->unk164;
            if (temp_r0_19878 != NULL) {
                temp_r4_19881 = this + 0x15C;
                if (temp_r0_19878 != temp_r4_19881) {
                    M2C_FIELD(this->unk168, void **, 8) = temp_r0_19878;
                    M2C_FIELD(this->unk164, void **, 0xC) = (void *) this->unk168;
                    this->unk168 = temp_r4_19881;
                    this->unk164 = temp_r4_19881;
                }
            }
        }
        if (&this->unk108 != NULL) {
            temp_r4_19894 = &this->unk108.unk28;
            if (temp_r4_19894 != NULL) {
                temp_r0_19896 = this->unk108.unk28.unk8;
                if ((temp_r0_19896 != NULL) && (temp_r0_19896 != temp_r4_19894)) {
                    this->unk108.unk28.unkC->unk8 = temp_r0_19896;
                    this->unk108.unk28.unk8->unkC = this->unk108.unk28.unkC;
                    this->unk108.unk28.unkC = temp_r4_19894;
                    this->unk108.unk28.unk8 = temp_r4_19894;
                }
            }
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk4'
inline Platform::Platform() {
    PlatformAttachment *temp_r4_19937;
    void *temp_r0_19939;

    temp_r4_19937 = &this->unk108.unk28;
    temp_r0_19939 = this + 0x15C;
    this->unk108.unk28.unk0 = NULL;
    this->unk108.unk28.unk4 = NULL;
    this->unk108.unk28.unk8 = temp_r4_19937;
    this->unk108.unk28.unkC = temp_r4_19937;
    M2C_FIELD(this, s32 *, 0x15C) = 0;
    this->unk160 = 0;
    this->unk164 = temp_r0_19939;
    this->unk168 = temp_r0_19939;
    this->unk178 = 0;
    return this;
}
#endif

inline void Platform::UpdateRotate() {

}

inline void Platform::UpdateMove() {

}

inline void Platform::UpdateScale() {

}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline PlatformDescriptor::PlatformDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_PLATFORM_H
