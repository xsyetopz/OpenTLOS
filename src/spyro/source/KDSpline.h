#ifndef SPYRO_SOURCE_KDSPLINE_H
#define SPYRO_SOURCE_KDSPLINE_H

#include <dolphin/types.h>
#include "common/Source/Matrix.h"

class KDSpline;
class KDSpline_cpp;
class KDUniformSpline;
class MKVector3;
class Matrix;

class KDSpline {
public:
    KDSpline(void);
    void Deinit(void);
    void GetMeasure(float, Matrix *);
    s32 AddNode(const MKVector3 &);
    void Init(int, bool);
    /* 0x000 */ s32 unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ s32 unkC;
    /* 0x010 */ u8 unk10;
};

class KDSpline_cpp {
public:
    void __sinit(void);
};

class KDUniformSpline {
public:
    KDUniformSpline(void);
    void GetAcceleration(float) const;
    void GetVelocity(float) const;
    void RegulateSpeed(void);
    void Smooth(void);
    s32 MergeEnds(void);
    void Deinit(void);
    void GetMeasure(float, Matrix *, float *) const;
    void GetMatrix(int, Matrix *) const;
    void GetNextPositionFast(float, Matrix *, int *, float *) const;
    s32 AddNode(const MKVector3 &);
    void Init(void *, int, bool);
    void Init(int, bool);
    /* 0x000 */ s32 unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ s32 unkC;
    /* 0x010 */ u8 unk10;
};

void KDSpline_GetMeasure(const MKVector3 &, const MKVector3 &, const MKVector3 &, const MKVector3 &, float, Matrix *);
extern Matrix splinePosMixer;
extern u8 splineVelMixer[0x40];
extern u8 splineAccMixer[0x40];
extern f32 * KDSpline_PositionMixer;
extern f32 * KDSpline_VelocityMixer;
extern f32 * KDSpline_AccelerationMixer;
// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline KDSpline::KDSpline() {
    this->unk0 = 0;
    this->unk4 = 0;
    this->unk8 = 0.0f;
    this->unkC = 0;
    return this;
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline KDUniformSpline::KDUniformSpline() {
    this->unk0 = 0;
    this->unk4 = 0;
    this->unk8 = 0.0f;
    this->unkC = 0;
    return this;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'KDUniformSpline' to
inline void KDUniformSpline::GetAcceleration(float arg0) const {
    f64 sp38;
    KDUniformSpline sp20;
    f32 sp18;
    f32 sp8;

    sp8 = 0.0f;
    sp20.GetMeasure(arg0, M2C_ERROR(/* Read from unset register $r4 */), KDSpline_AccelerationMixer);
    sp20.unk10 = M2C_BITWISE(f64, sp20);
    sp38 = (f64) sp20.unk8;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    M2C_FIELD(this, f64 *, 0) = sp10;
    sp18 = (f32) sp38 * (sp8 * sp8);
    M2C_FIELD(this, f64 *, 8) = (f64) sp18;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'KDUniformSpline' to
inline void KDUniformSpline::GetVelocity(float arg0) const {
    f64 sp38;
    KDUniformSpline sp20;
    f32 sp18;
    f32 sp8;

    sp8 = 0.0f;
    sp20.GetMeasure(arg0, M2C_ERROR(/* Read from unset register $r4 */), KDSpline_VelocityMixer);
    sp20.unk10 = M2C_BITWISE(f64, sp20);
    sp38 = (f64) sp20.unk8;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    M2C_FIELD(this, f64 *, 0) = sp10;
    sp18 = (f32) sp38 * sp8;
    M2C_FIELD(this, f64 *, 8) = (f64) sp18;
}
#endif

#endif  // SPYRO_SOURCE_KDSPLINE_H
