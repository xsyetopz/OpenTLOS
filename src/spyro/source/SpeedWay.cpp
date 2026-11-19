#include "spyro/source/SpeedWay.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/Level.h"
#include "spyro/source/SplineTools.h"
#include <m2c_macros.h>

#if 0 // DRAFT: illegal explicit conversion from 'SplitPath' to
void SpeedWay::GetPathMatrix(float arg0) {
    f32 sp1EC;
    f32 sp1E8;
    f32 sp1E4;
    f32 sp1E0;
    f32 sp1DC;
    f32 sp1D8;
    f32 sp1D4;
    f32 sp1D0;
    f32 sp1CC;
    f32 sp1C8;
    f32 sp1C4;
    f32 sp1C0;
    f32 sp1BC;
    f32 sp1B8;
    f32 sp1B4;
    f32 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    SplitPath sp160;
    SplitPath sp150;
    SplitPath sp140;
    SplitPath sp130;
    MKVector3 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    MKVector3 spF0;
    f64 spE8;
    f64 spE0;
    MKVector3 spD0;
    f64 spC8;
    f64 spC0;
    MKVector3 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f32 sp78;
    f64 sp70;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 temp_f6_166;
    f64 temp_f0_113;
    f64 temp_f0_90;

    sp160.GetPosition(arg0);
    sp1A0 = M2C_BITWISE(f64, sp160);
    sp1A8 = sp160.unk8;
    sp150.GetPosition(arg0);
    sp190 = M2C_BITWISE(f64, sp150);
    sp198 = sp150.unk8;
    sp140.GetVelocity(arg0);
    sp180 = M2C_BITWISE(f64, sp140);
    sp188 = sp140.unk8;
    sp130.GetVelocity(arg0);
    sp170 = M2C_BITWISE(f64, sp130);
    sp178 = sp130.unk8;
    temp_f0_90 = sp190 - sp1A0;
    sp70 = temp_f0_90;
    sp110 = temp_f0_90;
    sp78 = (f32) sp198 - (f32) sp1A8;
    sp118 = (f64) sp78;
    Normalise(sp120);
    sp1B0 = M2C_BITWISE(f32, sp120);
    sp1B4 = sp120.unk4;
    sp1B8 = sp120.unk8;
    sp1BC = 0.0f;
    temp_f0_113 = sp180 + sp170;
    sp20 = temp_f0_113;
    spE0 = temp_f0_113;
    sp28 = (f32) sp188 + (f32) sp178;
    spE8 = (f64) sp28;
    Normalise(spF0);
    sp60 = -M2C_BITWISE(f32, spF0);
    sp64 = -spF0.unk4;
    sp68 = -spF0.unk8;
    sp100 = (f64) sp60;
    sp108 = (f64) sp68;
    sp1D0 = (f32) sp100;
    sp1D4 = (*(f32 *) ((u8 *) &sp100 + 0x4));
    sp1D8 = (f32) sp108;
    sp58 = ((f32) sp100 * sp1B4) - ((*(f32 *) ((u8 *) &sp100 + 0x4)) * sp1B0);
    sp50 = ((*(f32 *) ((u8 *) &sp100 + 0x4)) * sp1B8) - ((f32) sp108 * sp1B4);
    sp54 = ((f32) sp108 * sp1B0) - ((f32) sp100 * sp1B8);
    sp1DC = 0.0f;
    spC0 = (f64) sp50;
    spC8 = (f64) sp58;
    Normalise(spD0);
    temp_f6_166 = M2C_BITWISE(f32, spD0);
    sp1C0 = temp_f6_166;
    sp1C4 = spD0.unk4;
    sp40 = (spD0.unk4 * sp1D8) - (spD0.unk8 * sp1D4);
    sp44 = (spD0.unk8 * sp1D0) - (temp_f6_166 * sp1D8);
    sp48 = (temp_f6_166 * sp1D4) - (spD0.unk4 * sp1D0);
    sp1C8 = spD0.unk8;
    sp1CC = 0.0f;
    spA0 = (f64) sp40;
    spA8 = (f64) sp48;
    Normalise(spB0);
    sp1B0 = M2C_BITWISE(f32, spB0);
    sp1B4 = spB0.unk4;
    sp1B8 = spB0.unk8;
    sp1BC = 0.0f;
    sp10 = sp1A0 + sp190;
    sp18 = (f32) sp1A8 + (f32) sp198;
    sp80 = sp10;
    sp88 = (f64) sp18;
    sp30 = sp80 * 5.222099017e-315;
    sp90 = sp30;
    sp38 = (f32) sp88 * 0.5f;
    sp1EC = 1.0f;
    sp98 = (f64) sp38;
    sp1E0 = (f32) sp90;
    sp1E4 = (*(f32 *) ((u8 *) &sp90 + 0x4));
    sp1E8 = (f32) sp98;
    sp1DC = 0.0f;
    sp1CC = 0.0f;
    sp1BC = 0.0f;
    sp1EC = 1.0f;
    M2C_STRUCT_COPY((s32) (this - 4) + 4, (s32) &unksp1AC + 4, 0x40);
}
#endif

void SpeedWay::Resolve() {
    MKProp::Resolve();
    ((KDPathSegment *) &this->unk4C)->Resolve();
    ((KDPathSegment *) &this->unk94)->Resolve();
}

void SpeedWay::LoadDone() {
    MKProp::LoadDone();
    ((KDSplinePathSegment *) &this->unk4C)->LoadDone();
    ((KDSplinePathSegment *) &this->unk94)->LoadDone();
    ((SplitPath *) &this->unkDC)->Init(*((KDUniformSpline *) &this->unk4C.unk2C), 0x10, 2);
    ((SplitPath *) &this->unkDC.unk4)->Init(*((KDUniformSpline *) &this->unk94.unk2C), 0x10, 2);
}

s32 SpeedWay::LoadLine(MKIniLine *arg0) {
    s32 var_r31_317;

    var_r31_317 = 0;
    if ((MKProp::LoadLine(arg0) != 0) || (((KDSplinePathSegment *) &this->unk4C)->LoadLine(arg0, "pathLeft") != 0) || (((KDSplinePathSegment *) &this->unk94)->LoadLine(arg0, "pathRight") != 0)) {
        var_r31_317 = 1;
    }
    return var_r31_317;
}

void SpeedWay::Deinit() {
    ((SplitPath *) &this->unkDC)->Deinit();
    ((SplitPath *) &this->unkDC.unk4)->Deinit();
    ((KDSplinePathSegment *) &this->unk4C)->Deinit();
    ((KDSplinePathSegment *) &this->unk94)->Deinit();
    MKProp::Deinit();
}

void SpeedWay::Init() {
    MKProp::Init();
    ((KDSplinePathSegment *) &this->unk4C)->Init();
    ((KDSplinePathSegment *) &this->unk94)->Init();
}
