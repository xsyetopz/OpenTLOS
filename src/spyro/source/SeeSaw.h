#ifndef SPYRO_SOURCE_SEESAW_H
#define SPYRO_SOURCE_SEESAW_H

#include <dolphin/types.h>
#include "common/Source/Matrix.h"
#include "spyro/source/KDProp.h"

class KDProp;
class KDPropDescriptor;
class MKIniLine;
class MKMessage;
class Matrix;
class Platform;
class PlatformAttachment;
class PlatformObject;
class SeeSaw;
class SeeSawDescriptor;

class PlatformAttachment {
public:
    /* 0x000 */ Platform* unk0;
    /* 0x004 */ PlatformObject* unk4;
    /* 0x008 */ PlatformAttachment* unk8;
    /* 0x00c */ PlatformAttachment* unkC;
};

class SeeSaw : public KDProp {  // base: ctor/dtor vtable stores
public:
    virtual ~SeeSaw(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    void Detach(PlatformAttachment *);
    void Attach(PlatformAttachment *);
    /* 0x089 */ u8 pad89[0x3];
    /* 0x08c */ u8 unk8C;
    /* 0x08d */ u8 pad8D[0x3];
    /* 0x090 */ Matrix unk90;
    /* 0x0d0 */ f64 unkD0;
    /* 0x0d8 */ f64 unkD8;
    /* 0x0e0 */ f32 unkE0;
    /* 0x0e4 */ f32 unkE4;
    /* 0x0e8 */ f32 unkE8;
    /* 0x0ec */ u8 padEC[0x4];
    /* 0x0f0 */ s32 unkF0;
    /* 0x0f4 */ u8 padF4[0x24];
    /* 0x118 */ PlatformAttachment unk118;
    /* 0x128 */ f32 unk128;
    /* 0x12c */ f32 unk12C;
    /* 0x130 */ f32 unk130;
    /* 0x134 */ f32 unk134;
    /* 0x138 */ f32 unk138;
    /* 0x13c */ s32 unk13C;
    /* 0x140 */ u8 unk140;
};

class SeeSawDescriptor : public KDPropDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    /* 0x06d */ u8 pad6D[0x3];
    /* 0x070 */ s32 unk70;
    /* 0x074 */ f32 unk74;
    /* 0x078 */ f32 unk78;
    /* 0x07c */ f32 unk7C;
    /* 0x080 */ f32 unk80;
    /* 0x084 */ f32 unk84;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'KDSound_Stop'
inline SeeSaw::~SeeSaw() {
    PlatformAttachment *temp_r0_23;
    PlatformAttachment *temp_r4_26;
    s32 temp_cr0_eq_44;

    if (this != NULL) {
        if (&this->unk118 != NULL) {
            temp_r0_23 = this->unk118.unk8;
            if (temp_r0_23 != NULL) {
                temp_r4_26 = &this->unk118;
                if (temp_r0_23 != temp_r4_26) {
                    this->unk118.unkC->unk8 = temp_r0_23;
                    this->unk118.unk8->unkC = this->unk118.unkC;
                    this->unk118.unkC = temp_r4_26;
                    this->unk118.unk8 = temp_r4_26;
                }
            }
        }
        if ((&this->unkF0 != NULL) && (&this->unkF0 != NULL)) {
            KDSound_Stop(&this->unkF0);
        }
        temp_cr0_eq_44 = this == NULL;
        if (temp_cr0_eq_44 == 0) {
            if (temp_cr0_eq_44 == 0) {
            }
        }
    }
}
#endif

#endif  // SPYRO_SOURCE_SEESAW_H
