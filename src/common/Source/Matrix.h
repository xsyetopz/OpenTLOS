#ifndef COMMON_SOURCE_MATRIX_H
#define COMMON_SOURCE_MATRIX_H

#include <dolphin/types.h>

class MKVector3;
class MKVector4;
class Matrix;

class Matrix {
public:
    void ZAxis3(void) const;
    void YAxis3(void) const;
    void XAxis3(void) const;
    void SetRotateAroundAxis(const MKVector3 &, float);
    void Inverse(const Matrix *);
    void RotatePYR(const Matrix *, const MKVector3 &);
    void RotateRoll(const Matrix *, float);
    void RotateYaw(const Matrix *, float);
    void RotatePitch(const Matrix *, float);
    void Translate(const Matrix *, const MKVector4 &);
    void Translate(const Matrix *, const MKVector3 &);
    void Scale4x3(const Matrix *, float);
    void Scale3x3(const Matrix *, const MKVector3 &);
    void Scale3x3(const Matrix *, float);
    void Multiply4x4(const Matrix *, const Matrix *);
    void Multiply3x3(const Matrix *, const Matrix *);
    f32 Multiply(const Matrix *, const Matrix *);
    void InverseSimple(const Matrix *);
    void Transpose3x3(const Matrix *);
    void Transpose(const Matrix *);
    void SetLookAt(const MKVector3 &, const MKVector3 &);
    void GetRotationRPY(void) const;
    void GetRotationPRY(void) const;
    void GetRotationPYR(void) const;
    void SetRotationPYR(const MKVector3 &);
    void SetRotationRoll(float);
    void SetRotationYaw(float);
    void SetRotationPitch(float);
    void NormaliseScale(void);
    void SetRotationToNone(void);
    void SetZero(void);
    void SetIdentity(void);
    void CopyRotation(const Matrix *);
    static Matrix identity;
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ f32 unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ f32 unk1C;
    /* 0x020 */ f32 unk20;
    /* 0x024 */ f32 unk24;
    /* 0x028 */ f32 unk28;
    /* 0x02c */ f32 unk2C;
    /* 0x030 */ f32 unk30;
    /* 0x034 */ f32 unk34;
    /* 0x038 */ f32 unk38;
    /* 0x03c */ f32 unk3C;
};

#endif  // COMMON_SOURCE_MATRIX_H
