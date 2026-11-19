#ifndef SPYRO_SOURCE_KDCAMERAHEROMOVEYAW_H
#define SPYRO_SOURCE_KDCAMERAHEROMOVEYAW_H

#include <dolphin/types.h>

class KDCameraHeroMoveYaw;

class KDCameraHeroMoveYaw {
public:
    class UpdateData;
    void Update(const KDCameraHeroMoveYaw::UpdateData &);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier 'KDMath_GetSmallestAngle'
inline void KDCameraHeroMoveYaw::Update(const KDCameraHeroMoveYaw::UpdateData &arg1) {
    f32 temp_f1_4409;
    f32 temp_f31_4376;
    f32 temp_f31_4407;
    f32 var_f0_4413;
    f32 var_f1_4379;
    s32 temp_r0_4368;

    if ((s32) M2C_FIELD(this, s32 *, 0) == 0) {
        M2C_FIELD(this, s32 *, 0) = 1;
    }
    temp_r0_4368 = M2C_FIELD(this, s32 *, 0);
    switch (temp_r0_4368) {                         /* irregular */
    case 1:
        temp_f31_4376 = M2C_FIELD(&arg1, f32 *, 0);
        var_f1_4379 = KDMath_GetSmallestAngle(M2C_FIELD(this, f32 *, 4), temp_f31_4376);
        if (var_f1_4379 < 0.0f) {
            var_f1_4379 = -var_f1_4379;
        }
        if (var_f1_4379 > 0.3f) {
            M2C_FIELD(this, s32 *, 0) = 2;
            return;
        }
        M2C_FIELD(this, f32 *, 4) = temp_f31_4376;
        return;
    case 2:
        if ((u8) M2C_FIELD(&arg1, u8 *, 4) != 0) {
            M2C_FIELD(this, s32 *, 0) = 1;
            M2C_FIELD(this, f32 *, 4) = (f32) M2C_FIELD(&arg1, f32 *, 0);
            return;
        }
        temp_f31_4407 = 4.712389f * gUpdateTimeDelta;
        temp_f1_4409 = KDMath_GetSmallestAngle(M2C_FIELD(this, f32 *, 4), M2C_FIELD(&arg1, f32 *, 0));
        if (temp_f1_4409 < 0.0f) {
            var_f0_4413 = -temp_f1_4409;
        } else {
            var_f0_4413 = temp_f1_4409;
        }
        if (var_f0_4413 > temp_f31_4407) {
            if (temp_f1_4409 > 0.0f) {
                M2C_FIELD(this, f32 *, 4) = (f32) (M2C_FIELD(this, f32 *, 4) + temp_f31_4407);
                return;
            }
            M2C_FIELD(this, f32 *, 4) = (f32) (M2C_FIELD(this, f32 *, 4) - temp_f31_4407);
            return;
        }
        M2C_FIELD(this, s32 *, 0) = 1;
        M2C_FIELD(this, f32 *, 4) = (f32) M2C_FIELD(&arg1, f32 *, 0);
        return;
    }
}
#endif

#endif  // SPYRO_SOURCE_KDCAMERAHEROMOVEYAW_H
