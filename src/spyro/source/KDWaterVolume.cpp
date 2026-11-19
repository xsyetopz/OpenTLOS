#include "spyro/source/KDWaterVolume.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/KDVolume.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKCollision.h"
#include <m2c_macros.h>

s32 stricmp(s32, s32, u32);                         /* extern */

s32 KDWaterVolume::IsEnabled() {
    return 1;
}

void KDWaterVolume::LoadDone() {
    MKProp::LoadDone();
    this->unk50.Init(*((Matrix *) &MKProp::loadInfo));
}

void KDWaterVolume::Deinit() {
    this->unk50.Deinit();
    MKProp::Deinit();
}

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char' to
f32 KDWaterVolume::GetWaterSurface(const MKVector3 &arg0) {
    f32 sp8;
    f32 var_f0_86;
    f32 var_f31_63;
    void *var_r30_70;
    void *var_r31_65;

    var_f31_63 = -1e11f;
    var_r31_65 = *KDWaterVolumeDescriptor::pFirstDesc;
loop_10:
    if (var_r31_65 != NULL) {
        var_r30_70 = checked_cast<KDWaterVolume *, MKProp>(M2C_FIELD(var_r31_65, MKProp **, 0x28));
loop_8:
        if (var_r30_70 != NULL) {
            if ((M2C_FIELD(M2C_FIELD(var_r30_70, void **, 0x44), u8 (**)(void *), 0x38)(var_r30_70) != 0) && (((KDVolume *) (((u8 *) var_r30_70) + 0x50))->IsWithinXZ(*((MKVector3 *) this), &sp8) != 0)) {
                var_f0_86 = sp8;
                if (var_f31_63 > var_f0_86) {
                    var_f0_86 = var_f31_63;
                }
                var_f31_63 = var_f0_86;
            }
            var_r30_70 = checked_cast<KDWaterVolume *, MKProp>(M2C_FIELD(var_r30_70, MKProp **, 0x38));
            goto loop_8;
        }
        var_r31_65 = M2C_FIELD(var_r31_65, void **, 0x68);
        goto loop_10;
    }
    return var_f31_63;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'void *' to
s32 KDWaterVolume::GetWaterHeight(const MKVector3 &arg0, float arg1, float *arg2, MKCollisionResult *arg3, int arg4) {
    u8 sp98;
    s32 sp94;
    s32 sp90;
    s32 sp8C;
    f32 sp88;
    s32 sp84;
    s8 sp83;
    s8 sp82;
    s16 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f64 sp8;
    f64 temp_f0_158;

    sp20 = 0.0f;
    sp1C = -arg1;
    sp18 = 0.0f;
    sp48 = 0.0f;
    sp4C = 0.0f;
    sp50 = 0.0f;
    sp58 = 0.0f;
    sp5C = 0.0f;
    sp60 = 0.0f;
    sp68 = 0.0f;
    sp6C = 0.0f;
    sp70 = 0.0f;
    sp74 = 1.0f;
    sp78 = 0.0f;
    sp7C = 0.0f;
    sp80 = 0;
    sp82 = 0;
    sp83 = 0;
    sp84 = 0;
    sp88 = 3.4028235e38f;
    sp8C = 0;
    sp90 = 0;
    sp94 = -1;
    sp98 = 0;
    sp28 = (f64) sp18;
    sp30 = (f64) sp20;
    temp_f0_158 = M2C_FIELD(this, f64 *, 0) + sp28;
    sp8 = temp_f0_158;
    sp38 = temp_f0_158;
    sp10 = M2C_BITWISE(f32, this->unk8) + (f32) sp30;
    sp40 = (f64) sp10;
    if (MKCollision_RayCollide(*((MKVector3 *) this), *((MKVector3 *) &sp38), (MKCollisionResult *) &sp48, (MKCollisionMode) 1, (s32) arg3) != 0) {
        if (arg2 != NULL) {
            M2C_FIELD(arg2, f64 *, 0) = (f64) sp48;
            M2C_FIELD(arg2, f64 *, 8) = (f64) sp50;
            M2C_FIELD(arg2, f64 *, 0x10) = (f64) sp58;
            M2C_FIELD(arg2, f64 *, 0x18) = (f64) sp60;
            M2C_FIELD(arg2, f64 *, 0x20) = (f64) sp68;
            M2C_FIELD(arg2, f64 *, 0x28) = (f64) sp70;
            M2C_FIELD(arg2, f32 *, 0x30) = sp78;
            M2C_FIELD(arg2, f32 *, 0x34) = sp7C;
            M2C_FIELD(arg2, s32 *, 0x38) = (s32) sp80;
            M2C_FIELD(arg2, s32 *, 0x3C) = sp84;
            M2C_FIELD(arg2, f32 *, 0x40) = sp88;
            M2C_FIELD(arg2, s32 *, 0x44) = sp8C;
            M2C_FIELD(arg2, s32 *, 0x48) = sp90;
            M2C_FIELD(arg2, s32 *, 0x4C) = sp94;
            M2C_FIELD(arg2, u8 *, 0x50) = sp98;
        }
        return ((KDWaterVolume *) &sp48)->IsWithin(arg0, NULL, M2C_ERROR(/* Read from unset register $r6 */));
    }
    return 0;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char' to
s32 KDWaterVolume::IsWithin(const MKVector3 &arg0, float *arg1, int *arg2) {
    f32 sp8;
    f32 var_f0_262;
    f32 var_f31_233;
    s32 var_r31_236;
    void *var_r29_246;
    void *var_r30_241;

    var_f31_233 = -1e11f;
    var_r31_236 = 0;
    if (arg1 != NULL) {
        *arg1 = 0.0f;
    }
    var_r30_241 = *KDWaterVolumeDescriptor::pFirstDesc;
loop_15:
    if (var_r30_241 != NULL) {
        var_r29_246 = checked_cast<KDWaterVolume *, MKProp>(M2C_FIELD(var_r30_241, MKProp **, 0x28));
loop_13:
        if (var_r29_246 != NULL) {
            if ((M2C_FIELD(M2C_FIELD(var_r29_246, void **, 0x44), u8 (**)(void *), 0x38)(var_r29_246) != 0) && (((KDVolume *) (((u8 *) var_r29_246) + 0x50))->IsWithin(*((MKVector3 *) this), &sp8) != 0)) {
                var_f0_262 = sp8;
                var_r31_236 = 1;
                if (var_f31_233 > var_f0_262) {
                    var_f0_262 = var_f31_233;
                }
                var_f31_233 = var_f0_262;
                if (&arg0 != NULL) {
                    arg0.unk0 = var_f0_262;
                }
                if (arg1 != NULL) {
                    *arg1 = M2C_BITWISE(f32, (M2C_BITWISE(s32, *arg1) | M2C_FIELD(var_r30_241, s32 *, 0x60)));
                }
            }
            var_r29_246 = checked_cast<KDWaterVolume *, MKProp>(M2C_FIELD(var_r29_246, MKProp **, 0x38));
            goto loop_13;
        }
        var_r30_241 = M2C_FIELD(var_r30_241, void **, 0x68);
        goto loop_15;
    }
    return var_r31_236;
}
#endif

#if 0 // DRAFT: pointer/array required
s32 KDWaterVolumeDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r28_324;
    s32 var_r29_327;
    u32 temp_r5_333;

    if (MKPropDescriptor::LoadLine(arg0) != 0) {
        return 1;
    }
    if (((u32) this->unk64 != 0) && (arg0->IsField("volumeType") != 0)) {
        var_r28_324 = 0;
loop_11:
        if (var_r28_324 < (s16) arg0->unk0) {
            var_r29_327 = 0;
loop_9:
            if ((u32) *(this->unk64 + var_r29_327) != 0U) {
                temp_r5_333 = this->unk64;
                if (stricmp(*(temp_r5_333 + var_r29_327), arg0->GetString(var_r28_324), temp_r5_333) == 0) {
                    this->unk60 |= *(this->unk64 + (var_r29_327 + 4));
                }
                var_r29_327 += 8;
                goto loop_9;
            }
            var_r28_324 += 1;
            goto loop_11;
        }
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char' to
void KDWaterVolumeDescriptor::Deinit() {
    void *var_r3_378;
    void *var_r4_385;

    MKPropDescriptor::Deinit();
    var_r3_378 = *KDWaterVolumeDescriptor::pFirstDesc;
    if (var_r3_378 == this) {
        *KDWaterVolumeDescriptor::pFirstDesc = M2C_FIELD(var_r3_378, void **, 0x68);
        return;
    }
    var_r4_385 = M2C_FIELD(var_r3_378, void **, 0x68);
loop_6:
    if (var_r4_385 == NULL) {
        return;
    }
    if (var_r4_385 == this) {
        M2C_FIELD(var_r3_378, void **, 0x68) = (void *) M2C_FIELD(var_r4_385, void **, 0x68);
        return;
    }
    var_r3_378 = var_r4_385;
    var_r4_385 = M2C_FIELD(var_r4_385, void **, 0x68);
    goto loop_6;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char' to
void KDWaterVolumeDescriptor::Init() {
    MKPropDescriptor::Init();
    this->unk60 = 0;
    this->unk68 = *KDWaterVolumeDescriptor::pFirstDesc;
    *KDWaterVolumeDescriptor::pFirstDesc = this;
}
#endif
