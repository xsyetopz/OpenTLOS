#ifndef SPYRO_SOURCE_KDCAMERASIMPLEDELTA_H
#define SPYRO_SOURCE_KDCAMERASIMPLEDELTA_H

#include <dolphin/types.h>

class KDCameraDeltaStages;
class KDCameraDeltaStagesEx;
class KDCameraSimpleDelta;
class MKIniLine;
class MKVector3;

class KDCameraDeltaStages {
public:
    s32 LoadLine(MKIniLine *, char *);
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
};

class KDCameraDeltaStagesEx {
public:
    f32 GetPitch(void);
    f32 GetYDelta(void);
    f32 GetZDelta(void);
    void SetStages(float, float, float);
    void Init(float *, float *);
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ f32* unkC;
    /* 0x010 */ f32* unk10;
};

class KDCameraSimpleDelta {
public:
    class Override {
    public:
        void DisableSmoothDelta(void);
        void EnableSmoothDelta(float);
        void DisableSmoothPitch(void);
        void EnableSmoothPitch(float, float, bool);
        void EnableSmoothPitch(float, float);
    };
    f32 GetIdealPitch(void);
    u8 IsUsingIdealPitch(void);
    f32 GetIdealDelta(void);
    f32 GetCurrentPitch(void);
    MKVector3 GetIdealDeltaVector(void);
    MKVector3 GetCurrentDeltaVector(void);
    u8 IsUsingIdealStages(void);
    MKVector3 GetCurrentTargetOffset(void);
    u8 IsUsingIdealDelta(void);
    void OverrideUpdate(void);
    void DisableDeltaOverride(float);
    void DisablePitchOverride(float);
    void DisableOverride(float, float);
    void EnablePitchOverride(float, float);
    void EnableOverride(float, float, float);
    void SetDeltaStages(KDCameraDeltaStages *, bool, bool);
    MKVector3 GetDeltaVectorAtPitch(float);
    f32 GetCurrentDelta(void);
    void Update(const MKVector3 &);
    void ClearData(void);
    void Init(const KDCameraDeltaStages &, float, float);
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ f32* unkC;
    /* 0x010 */ f32* unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ f32 unk1C;
    /* 0x020 */ f32* unk20;
    /* 0x024 */ f32* unk24;
    /* 0x028 */ f32 unk28;
    /* 0x02c */ u8 pad2C[0x8];
    /* 0x034 */ f32 unk34;
    /* 0x038 */ u8 pad38[0x4];
    /* 0x03c */ f32 unk3C;
    /* 0x040 */ f32 unk40;
    /* 0x044 */ u8 unk44;
    /* 0x045 */ u8 pad45[0x3];
    /* 0x048 */ f32 unk48;
    /* 0x04c */ f32 unk4C;
    /* 0x050 */ f32 unk50;
    /* 0x054 */ u32 unk54;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

inline f32 KDCameraDeltaStagesEx::GetPitch() {
    f32 temp_f0_621;
    f32 temp_f0_629;
    f32 var_f1_620;

    var_f1_620 = this->unk0;
    temp_f0_621 = *this->unk10;
    if (var_f1_620 < temp_f0_621) {

    } else {
        var_f1_620 = temp_f0_621;
    }
    temp_f0_629 = *this->unkC;
    if (!(var_f1_620 > temp_f0_629)) {
        return temp_f0_629;
    }
    return var_f1_620;
}

#if 0 // DRAFT: undefined identifier 'Min'
inline f32 KDCameraSimpleDelta::GetIdealPitch() {
    f32 *temp_r31_1432;
    f32 temp_f0_1435;
    f32 temp_f1_1434;

    temp_r31_1432 = this->unkC;
    temp_f1_1434 = Min<float>(this->unk0, *this->unk10);
    temp_f0_1435 = *temp_r31_1432;
    if (temp_f1_1434 > temp_f0_1435) {
        return temp_f1_1434;
    }
    return temp_f0_1435;
}
#endif

inline u8 KDCameraSimpleDelta::IsUsingIdealPitch() {
    f32 temp_f1_1465;
    f32 temp_f2_1482;
    f32 var_f0_1464;
    f32 var_f1_1481;

    var_f0_1464 = this->unk0;
    temp_f1_1465 = *this->unk10;
    if (var_f0_1464 < temp_f1_1465) {

    } else {
        var_f0_1464 = temp_f1_1465;
    }
    if (var_f0_1464 > *this->unkC) {

    }
    var_f1_1481 = this->unk14;
    temp_f2_1482 = *this->unk24;
    if (var_f1_1481 < temp_f2_1482) {

    } else {
        var_f1_1481 = temp_f2_1482;
    }
    if (var_f1_1481 > *this->unk20) {

    }
    return ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1DU) & 1;
}

inline f32 KDCameraSimpleDelta::GetIdealDelta() {
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    f32 temp_f1_2045;
    f32 temp_f31_2041;
    f32 temp_f31_2043;
    f32 var_f1_2060;
    f64 temp_f2_2063;
    f64 temp_f2_2069;
    f64 temp_f2_2073;
    s32 temp_r3_2092;
    s32 var_r0_2102;

    temp_f31_2041 = this->unk28;
    temp_f31_2043 = ((KDCameraDeltaStagesEx *) this)->GetZDelta() + temp_f31_2041;
    temp_f1_2045 = ((KDCameraDeltaStagesEx *) this)->GetYDelta();
    sp18 = temp_f31_2043;
    sp10 = 0.0f;
    sp14 = temp_f1_2045;
    sp28 = (f64) sp18;
    sp20 = (f64) sp10;
    var_f1_2060 = ((f32) sp28 * (f32) sp28) + (((f32) sp20 * (f32) sp20) + ((*(f32 *) ((u8 *) &sp20 + 0x4)) * (*(f32 *) ((u8 *) &sp20 + 0x4))));
    if (var_f1_2060 > 0.0f) {
        temp_f2_2063 = __frsqrte(var_f1_2060);
        temp_f2_2069 = 0.5 * temp_f2_2063 * -(((f64) var_f1_2060 * (temp_f2_2063 * temp_f2_2063)) - 3.0);
        temp_f2_2073 = 0.5 * temp_f2_2069 * -(((f64) var_f1_2060 * (temp_f2_2069 * temp_f2_2069)) - 3.0);
        return (f32) ((f64) var_f1_2060 * (0.5 * temp_f2_2073 * -(((f64) var_f1_2060 * (temp_f2_2073 * temp_f2_2073)) - 3.0)));
    }
    if (var_f1_2060 < M2C_BITWISE(f32, 0.0)) {
        return __float_nan;
    }
    sp8 = var_f1_2060;
    temp_r3_2092 = M2C_BITWISE(s32, sp8) & 0x7F800000;
    switch (temp_r3_2092) {                         /* irregular */
    case 0x7F800000:
        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
            var_r0_2102 = 1;
        } else {
            var_r0_2102 = 2;
        }
        break;
    case 0x0:
        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
            var_r0_2102 = 5;
        } else {
            var_r0_2102 = 3;
        }
        break;
    default:
        var_r0_2102 = 4;
        break;
    }
    if (var_r0_2102 == 1) {
        var_f1_2060 = __float_nan;
    }
    return var_f1_2060;
}

#if 0 // DRAFT: undefined identifier 'Min'
inline f32 KDCameraSimpleDelta::GetCurrentPitch() {
    f32 *temp_r31_3480;
    f32 temp_f0_3483;
    f32 temp_f1_3482;

    temp_r31_3480 = this->unk20;
    temp_f1_3482 = Min<float>(this->unk14, *this->unk24);
    temp_f0_3483 = *temp_r31_3480;
    if (temp_f1_3482 > temp_f0_3483) {
        return temp_f1_3482;
    }
    return temp_f0_3483;
}
#endif

#if 0 // DRAFT: identifier 'KDCameraSimpleDelta::GetIdealDeltaVector()' redeclared was declared as: 'MKVector3 ()' now declared as: 'void ()'
inline void KDCameraSimpleDelta::GetIdealDeltaVector() {
    MKVector3 result;
    MKVector3 *sret = &result;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f31_1213;
    f32 temp_f31_1216;

    temp_f31_1213 = this->unk28;
    temp_f31_1216 = ((KDCameraDeltaStagesEx *) this)->GetZDelta() + temp_f31_1213;
    spC = ((KDCameraDeltaStagesEx *) this)->GetYDelta();
    sp8 = 0.0f;
    sp10 = temp_f31_1216;
    M2C_FIELD(sret, f64 *, 0) = (f64) sp8;
    M2C_FIELD(sret, f64 *, 8) = (f64) sp10;
    return result;
}
#endif

#if 0 // DRAFT: identifier 'KDCameraSimpleDelta::GetCurrentDeltaVector()' redeclared was declared as: 'MKVector3 ()' now declared as: 'void ()'
inline void KDCameraSimpleDelta::GetCurrentDeltaVector() {
    MKVector3 result;
    MKVector3 *sret = &result;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f31_1247;
    f32 temp_f31_1250;

    temp_f31_1247 = this->unk28;
    temp_f31_1250 = ((KDCameraDeltaStagesEx *) &this->unk14)->GetZDelta() + temp_f31_1247;
    spC = ((KDCameraDeltaStagesEx *) &this->unk14)->GetYDelta();
    sp8 = 0.0f;
    sp10 = temp_f31_1250;
    M2C_FIELD(sret, f64 *, 0) = (f64) sp8;
    M2C_FIELD(sret, f64 *, 8) = (f64) sp10;
    return result;
}
#endif

inline u8 KDCameraSimpleDelta::IsUsingIdealStages() {
    u8 var_r31_3678;

    var_r31_3678 = 0;
    if ((IsUsingIdealPitch() != 0) && (IsUsingIdealDelta() != 0)) {
        var_r31_3678 = 1;
    }
    return var_r31_3678;
}

#if 0 // DRAFT: identifier 'KDCameraSimpleDelta::GetCurrentTargetOffset()' redeclared was declared as: 'MKVector3 ()' now declared as: 'void ()'
inline void KDCameraSimpleDelta::GetCurrentTargetOffset() {
    MKVector3 result;
    MKVector3 *sret = &result;
    f32 sp10;
    f32 spC;
    f32 sp8;

    sp8 = 0.0f;
    spC = this->unk1C;
    sp10 = 0.0f;
    M2C_FIELD(sret, f64 *, 0) = (f64) sp8;
    M2C_FIELD(sret, f64 *, 8) = (f64) sp10;
    return result;
}
#endif

inline f32 KDCameraSimpleDelta::GetCurrentDelta() {
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    f32 temp_f1_877;
    f32 temp_f31_872;
    f32 temp_f31_875;
    f32 var_f1_892;
    f64 temp_f2_895;
    f64 temp_f2_901;
    f64 temp_f2_905;
    s32 temp_r3_924;
    s32 var_r0_934;

    temp_f31_872 = this->unk28;
    temp_f31_875 = ((KDCameraDeltaStagesEx *) &this->unk14)->GetZDelta() + temp_f31_872;
    temp_f1_877 = ((KDCameraDeltaStagesEx *) &this->unk14)->GetYDelta();
    sp18 = temp_f31_875;
    sp10 = 0.0f;
    sp14 = temp_f1_877;
    sp28 = (f64) sp18;
    sp20 = (f64) sp10;
    var_f1_892 = ((f32) sp28 * (f32) sp28) + (((f32) sp20 * (f32) sp20) + ((*(f32 *) ((u8 *) &sp20 + 0x4)) * (*(f32 *) ((u8 *) &sp20 + 0x4))));
    if (var_f1_892 > 0.0f) {
        temp_f2_895 = __frsqrte(var_f1_892);
        temp_f2_901 = 0.5 * temp_f2_895 * -(((f64) var_f1_892 * (temp_f2_895 * temp_f2_895)) - 3.0);
        temp_f2_905 = 0.5 * temp_f2_901 * -(((f64) var_f1_892 * (temp_f2_901 * temp_f2_901)) - 3.0);
        return (f32) ((f64) var_f1_892 * (0.5 * temp_f2_905 * -(((f64) var_f1_892 * (temp_f2_905 * temp_f2_905)) - 3.0)));
    }
    if (var_f1_892 < M2C_BITWISE(f32, 0.0)) {
        return __float_nan;
    }
    sp8 = var_f1_892;
    temp_r3_924 = M2C_BITWISE(s32, sp8) & 0x7F800000;
    switch (temp_r3_924) {                          /* irregular */
    case 0x7F800000:
        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
            var_r0_934 = 1;
        } else {
            var_r0_934 = 2;
        }
        break;
    case 0x0:
        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
            var_r0_934 = 5;
        } else {
            var_r0_934 = 3;
        }
        break;
    default:
        var_r0_934 = 4;
        break;
    }
    if (var_r0_934 == 1) {
        var_f1_892 = __float_nan;
    }
    return var_f1_892;
}

#endif  // SPYRO_SOURCE_KDCAMERASIMPLEDELTA_H
