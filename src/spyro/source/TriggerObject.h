#ifndef SPYRO_SOURCE_TRIGGEROBJECT_H
#define SPYRO_SOURCE_TRIGGEROBJECT_H

#include <dolphin/types.h>
#include "common/Source/Matrix.h"
#include "spyro/source/BoundingRegion.h"

class BoundingRegion;
class MKIniLine;
class MKMessage;
class MKSceneManager;
class MKVector3;
class Matrix;
class TriggerBoxObject;
class TriggerObject;
class TriggerObject_cpp;
class TriggerPlaneGroupObject;
class TriggerPlaneObject;
class TriggerPolyObject;
class TriggerSphereObject;

class TriggerObject {
public:
    virtual void Init(void);
    virtual void Deinit(void);
    virtual u8 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Reset(void);
    virtual void Message(MKMessage *);
    virtual void Resolve(void);
    virtual u16 Update(void);
    virtual void SetPos(const MKVector3 &);
    virtual void SetPos(const Matrix &);
    virtual s32 CheckPos(const MKVector3 &) = 0;
    virtual s32 CheckTarget(void) = 0;
    void EnableTrigger(bool);
    /* 0x004 */ u8 pad4[0xc];
    /* 0x010 */ Matrix unk10;
    /* 0x050 */ s32 unk50;
    /* 0x054 */ s32 unk54;
    /* 0x058 */ u8 pad58[0x8];
    /* 0x060 */ f32 unk60;
    /* 0x064 */ f32 unk64;
    /* 0x068 */ f32 unk68;
    /* 0x06c */ u8 pad6C[0x4];
    /* 0x070 */ f32 unk70;
    /* 0x074 */ f32 unk74;
    /* 0x078 */ f32 unk78;
};

class TriggerBoxObject : public TriggerObject {  // base: ctor/dtor vtable stores
public:
    virtual void LoadDone(void);
    virtual void SetPos(const MKVector3 &);
    virtual void SetPos(const Matrix &);
    virtual s32 CheckPos(const MKVector3 &);
    virtual s32 CheckTarget(void);
    virtual s32 LoadLine(char *, MKIniLine *);
    virtual void LoadDone(const MKVector3 &, const Matrix &);
    static u8 tempBoxRot[0x10];
    /* 0x004 */ u8 pad4[0xc];
    /* 0x010 */ Matrix unk10;
    /* 0x050 */ s32 unk50;
    /* 0x054 */ MKSceneManager* unk54;
    /* 0x058 */ u8 pad58[0x8];
    /* 0x060 */ f32 unk60;
    /* 0x064 */ f32 unk64;
    /* 0x068 */ f32 unk68;
    /* 0x06c */ u8 pad6C[0x4];
    /* 0x070 */ f32 unk70;
    /* 0x074 */ f32 unk74;
    /* 0x078 */ f32 unk78;
    /* 0x07c */ u8 pad7C[0x4];
    /* 0x080 */ f32 unk80;
    /* 0x084 */ f32 unk84;
    /* 0x088 */ f32 unk88;
    /* 0x08c */ u8 pad8C[0x4];
    /* 0x090 */ f32 unk90;
    /* 0x094 */ f32 unk94;
    /* 0x098 */ f32 unk98;
    /* 0x09c */ u8 pad9C[0x4];
    /* 0x0a0 */ f32 unkA0;
    /* 0x0a4 */ f32 unkA4;
    /* 0x0a8 */ f32 unkA8;
    /* 0x0ac */ u8 padAC[0x4];
    /* 0x0b0 */ f32 unkB0;
    /* 0x0b4 */ f32 unkB4;
    /* 0x0b8 */ f32 unkB8;
};

class TriggerObject_cpp {
public:
    void __sinit(void);
};

class TriggerPlaneGroupObject : public TriggerObject {  // base: vtable prefix
public:
    virtual void Deinit(void);
    virtual void LoadDone(void);
    virtual s32 CheckPos(const MKVector3 &);
    virtual s32 CheckTarget(void);
    s32 AddPlane(TriggerPlaneObject *);
    /* 0x004 */ u8 pad4[0x4c];
    /* 0x050 */ s32 unk50;
    /* 0x054 */ MKSceneManager* unk54;
    /* 0x058 */ u8 pad58[0x28];
    /* 0x080 */ TriggerPlaneObject*** unk80;
    /* 0x084 */ u8 unk84;
};

class TriggerPlaneObject : public TriggerBoxObject {  // base: ctor/dtor vtable stores
public:
    virtual void LoadDone(void);
    /* 0x004 */ u8 pad4[0x2c];
    /* 0x030 */ f32 unk30;
    /* 0x034 */ f32 unk34;
    /* 0x038 */ f32 unk38;
    /* 0x03c */ u8 pad3C[0x18];
    /* 0x054 */ MKSceneManager* unk54;
    /* 0x058 */ u8 pad58[0x68];
    /* 0x0c0 */ u8 unkC0;
    /* 0x0c1 */ u8 padC1[0x3];
    /* 0x0c4 */ s32 unkC4;
};

class TriggerPolyObject : public TriggerObject {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void LoadDone(void);
    virtual s32 CheckPos(const MKVector3 &);
    virtual s32 CheckTarget(void);
    virtual s32 LoadLine(char *, MKIniLine *);
    /* 0x004 */ u8 pad4[0x50];
    /* 0x054 */ MKSceneManager* unk54;
    /* 0x058 */ u8 pad58[0x28];
    /* 0x080 */ s32 unk80;
    /* 0x084 */ MKVector3* unk84;
    /* 0x088 */ BoundingRegion unk88;
    /* 0x0a4 */ f32 unkA4;
    /* 0x0a8 */ f32 unkA8;
};

class TriggerSphereObject : public TriggerObject {  // base: vtable prefix
public:
    virtual void LoadDone(void);
    virtual s32 CheckPos(const MKVector3 &);
    virtual s32 CheckTarget(void);
    virtual void Init(float);
    virtual s32 LoadLine(char *, MKIniLine *);
    virtual f32 GetRadiusSquared(void);
    virtual void SetRadius(float);
    /* 0x004 */ u8 pad4[0x3c];
    /* 0x040 */ f64 unk40;
    /* 0x048 */ f64 unk48;
    /* 0x050 */ s32 unk50;
    /* 0x054 */ MKSceneManager* unk54;
    /* 0x058 */ u8 pad58[0x8];
    /* 0x060 */ f32 unk60;
    /* 0x064 */ f32 unk64;
    /* 0x068 */ f32 unk68;
    /* 0x06c */ u8 pad6C[0x4];
    /* 0x070 */ f64 unk70;
    /* 0x078 */ f64 unk78;
    /* 0x080 */ f32 unk80;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier 'unk44'
inline s32 TriggerBoxObject::CheckTarget() {
    f64 sp10;
    f64 sp8;
    f32 temp_r3_439;
    f64 temp_f1_459;
    s32 var_r31_454;
    void *temp_r5_456;
    void *var_r3_442;

    temp_r3_439 = this->unk10.unk44;
    if (M2C_BITWISE(s32, temp_r3_439) > 0) {
        var_r3_442 = ((MKSceneManager *) (M2C_BITWISE(MKSceneManager *, temp_r3_439)))->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */));
    } else {
        var_r3_442 = M2C_FIELD(*gb, void *(**)(void **), 0xC)(gb);
    }
    var_r31_454 = 0;
    if (var_r3_442 != NULL) {
        temp_r5_456 = M2C_FIELD(var_r3_442, void **, 8);
        temp_f1_459 = M2C_FIELD(temp_r5_456, f64 *, 0x30);
        sp8 = temp_f1_459;
        sp10 = M2C_FIELD(temp_r5_456, f64 *, 0x38);
        if (M2C_FIELD(this->__vptr, u8 (**)(TriggerBoxObject *, f64 *, void *, f64), 0x30)(this, &sp8, temp_r5_456, temp_f1_459) != 0) {
            var_r31_454 = 1;
        }
    }
    return var_r31_454;
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKVector3'
inline s32 TriggerBoxObject::CheckPos(const MKVector3 &arg0) {
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_531;
    f32 temp_f1_541;
    f32 temp_f4_512;
    f32 temp_f6_484;
    f32 temp_f7_488;
    f32 temp_f8_494;
    s32 var_r0_483;

    var_r0_483 = 0;
    temp_f6_484 = arg0.unk4;
    temp_f7_488 = arg0.unk0;
    temp_f8_494 = arg0.unk8;
    sp8 = this->unkB0 + ((temp_f8_494 * this->unkA0) + ((temp_f7_488 * this->unk10.unk70) + (temp_f6_484 * this->unk10.unk80)));
    spC = this->unkB4 + ((temp_f8_494 * this->unkA4) + ((temp_f7_488 * this->unk10.unk74) + (temp_f6_484 * this->unk10.unk84)));
    temp_f4_512 = this->unk10.unk50;
    sp28 = (f64) sp8;
    sp10 = this->unkB8 + ((temp_f8_494 * this->unkA8) + ((temp_f7_488 * this->unk10.unk78) + (temp_f6_484 * this->unk10.unk88)));
    sp18 = (f64) sp8;
    sp20 = (f64) sp10;
    sp30 = (f64) sp10;
    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
    if ((f32) sp28 == temp_f4_512) {
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if ((f32) sp28 == (temp_f4_512 + M2C_BITWISE(f32, this->unk10.unk60))) {
            temp_f1_531 = this->unk10.unk54;
            M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
            if (unksp2C == temp_f1_531) {
                M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                if (unksp2C == (temp_f1_531 + this->unk10.unk64)) {
                    temp_f1_541 = this->unk10.unk58;
                    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
                    if ((f32) sp30 == temp_f1_541) {
                        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                        if ((f32) sp30 == (temp_f1_541 + this->unk10.unk68)) {
                            var_r0_483 = 1;
                        }
                    }
                }
            }
        }
    }
    return var_r0_483;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC'
inline void TriggerBoxObject::SetPos(const Matrix &arg0) {
    M2C_STRUCT_COPY((s32) &this->unkC + 4, (s32) (&arg0 - 4) + 4, 0x40);
    this->unk10.unk70.InverseSimple(&this->unk10);
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKVector3'
inline void TriggerBoxObject::SetPos(const MKVector3 &arg0) {
    this->unk10.unk30 = arg0.unk0;
    this->unk10.unk34 = arg0.unk4;
    this->unk10.unk38 = arg0.unk8;
    this->unk10.unk3C = 1.0f;
    this->unk10.unk70.InverseSimple(&this->unk10);
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC'
inline void TriggerObject::SetPos(const Matrix &arg0) {
    M2C_STRUCT_COPY((s32) &this->unkC + 4, (s32) (&arg0 - 4) + 4, 0x40);
}
#endif

inline void TriggerObject::LoadDone() {

}

inline void TriggerObject::Deinit() {

}

inline void TriggerObject::Resolve() {

}

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKVector3'
inline void TriggerObject::SetPos(const MKVector3 &arg0) {
    this->unk10.unk30 = arg0.unk0;
    this->unk10.unk34 = arg0.unk4;
    this->unk10.unk38 = arg0.unk8;
    this->unk10.unk3C = 1.0f;
}
#endif

inline s32 TriggerPlaneGroupObject::CheckPos(const MKVector3 &arg0) {
    return 0;
}

#if 0 // DRAFT: undefined identifier 'unk70'
inline f32 TriggerSphereObject::GetRadiusSquared() {
    return this->unk10.unk70;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk70'
inline void TriggerSphereObject::SetRadius(float arg0) {
    this->unk10.unk70 = arg0 * arg0;
}
#endif

inline s32 TriggerSphereObject::CheckPos(const MKVector3 &arg0) {
    return (u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1FU;
}

#if 0 // DRAFT: undefined identifier 'unk44'
inline s32 TriggerSphereObject::CheckTarget() {
    f64 sp10;
    f64 sp8;
    f32 temp_f3_1397;
    f32 temp_f4_1392;
    f32 temp_f5_1391;
    f32 temp_r3_1365;
    s32 var_r0_1380;
    void *temp_r3_1382;
    void *var_r3_1368;

    temp_r3_1365 = this->unk10.unk44;
    if (M2C_BITWISE(s32, temp_r3_1365) > 0) {
        var_r3_1368 = ((MKSceneManager *) (M2C_BITWISE(MKSceneManager *, temp_r3_1365)))->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */));
    } else {
        var_r3_1368 = M2C_FIELD(*gb, void *(**)(void **), 0xC)(gb);
    }
    var_r0_1380 = 0;
    if (var_r3_1368 != NULL) {
        temp_r3_1382 = M2C_FIELD(var_r3_1368, void **, 8);
        sp8 = M2C_FIELD(temp_r3_1382, f64 *, 0x30);
        sp10 = M2C_FIELD(temp_r3_1382, f64 *, 0x38);
        temp_f5_1391 = this->unk10.unk34 - unkspC;
        temp_f4_1392 = this->unk10.unk30 - (f32) sp8;
        temp_f3_1397 = this->unk10.unk38 - (f32) sp10;
        if (((temp_f3_1397 * temp_f3_1397) + ((temp_f4_1392 * temp_f4_1392) + (temp_f5_1391 * temp_f5_1391))) < this->unk10.unk70) {
            var_r0_1380 = 1;
        }
    }
    return var_r0_1380;
}
#endif

#endif  // SPYRO_SOURCE_TRIGGEROBJECT_H
