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
    /* 0x040 */ f32 unk40;
    /* 0x044 */ f32 unk44;
    /* 0x048 */ f32 unk48;
    /* 0x04c */ f32 unk4C;
    /* 0x050 */ f32 unk50;
    /* 0x054 */ f32 unk54;
    /* 0x058 */ f32 unk58;
    /* 0x05c */ u8 pad5C[0x4];
    /* 0x060 */ s32 unk60;
    /* 0x064 */ f32 unk64;
    /* 0x068 */ f32 unk68;
    /* 0x06c */ f32 unk6C;
    /* 0x070 */ f32 unk70;
    /* 0x074 */ f32 unk74;
    /* 0x078 */ f32 unk78;
    /* 0x07c */ u8 pad7C[0xc];
    /* 0x088 */ f32 unk88;
};

#endif  // COMMON_SOURCE_MATRIX_H
