#include "spyro/source/SpeedWay.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/KDSpline.h"
#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier 'arg_sp160'
void SpeedWay::GetPathMatrix(float arg0) {
    arg_sp160.GetPosition(arg0);
    arg_sp1A0 = arg_sp160;
    arg_sp1A8 = arg_sp168;
    arg_sp150.GetPosition(arg0);
    arg_sp190 = arg_sp150;
    arg_sp198 = arg_sp158;
    arg_sp140.GetVelocity(arg0);
    arg_sp180 = arg_sp140;
    arg_sp188 = arg_sp148;
    arg_sp130.GetVelocity(arg0);
    arg_sp170 = arg_sp130;
    arg_sp178 = arg_sp138;
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    arg_sp110 = arg_sp70;
    arg_sp78 = (f32) arg_sp198 - (f32) arg_sp1A8;
    arg_sp118 = (f64) arg_sp78;
    Normalise(*((MKVector3 *) &arg_sp120));
    arg_sp1B0 = arg_sp120;
    arg_sp1B4 = arg_sp124;
    arg_sp1B8 = arg_sp128;
    arg_sp1BC = 0.0f;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_spE0 = arg_sp20;
    arg_sp28 = (f32) arg_sp188 + (f32) arg_sp178;
    arg_spE8 = (f64) arg_sp28;
    Normalise(*((MKVector3 *) &arg_spF0));
    arg_sp60 = -arg_spF0;
    arg_sp64 = -arg_spF4;
    arg_sp68 = -arg_spF8;
    arg_sp100 = (f64) arg_sp60;
    arg_sp108 = (f64) arg_sp68;
    arg_sp1D0 = (f32) arg_sp100;
    arg_sp1D4 = arg_sp104;
    arg_sp1D8 = (f32) arg_sp108;
    arg_sp58 = ((f32) arg_sp100 * arg_sp1B4) - (arg_sp104 * arg_sp1B0);
    arg_sp50 = (arg_sp104 * arg_sp1B8) - ((f32) arg_sp108 * arg_sp1B4);
    arg_sp54 = ((f32) arg_sp108 * arg_sp1B0) - ((f32) arg_sp100 * arg_sp1B8);
    arg_sp1DC = 0.0f;
    arg_spC0 = (f64) arg_sp50;
    arg_spC8 = (f64) arg_sp58;
    Normalise(*((MKVector3 *) &arg_spD0));
    arg_sp1C0 = arg_spD0;
    arg_sp1C4 = arg_spD4;
    arg_sp40 = (arg_spD4 * arg_sp1D8) - (arg_spD8 * arg_sp1D4);
    arg_sp44 = (arg_spD8 * arg_sp1D0) - (arg_spD0 * arg_sp1D8);
    arg_sp48 = (arg_spD0 * arg_sp1D4) - (arg_spD4 * arg_sp1D0);
    arg_sp1C8 = arg_spD8;
    arg_sp1CC = 0.0f;
    arg_spA0 = (f64) arg_sp40;
    arg_spA8 = (f64) arg_sp48;
    Normalise(*((MKVector3 *) &arg_spB0));
    arg_sp1B0 = arg_spB0;
    arg_sp1B4 = arg_spB4;
    arg_sp1B8 = arg_spB8;
    arg_sp1BC = 0.0f;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp18 = (f32) arg_sp1A8 + (f32) arg_sp198;
    arg_sp80 = arg_sp10;
    arg_sp88 = (f64) arg_sp18;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    arg_sp90 = arg_sp30;
    arg_sp38 = (f32) arg_sp88 * 0.5f;
    arg_sp1EC = 1.0f;
    arg_sp98 = (f64) arg_sp38;
    arg_sp1E0 = (f32) arg_sp90;
    arg_sp1E4 = arg_sp94;
    arg_sp1E8 = (f32) arg_sp98;
    arg_sp1DC = 0.0f;
    arg_sp1CC = 0.0f;
    arg_sp1BC = 0.0f;
    arg_sp1EC = 1.0f;
    M2C_STRUCT_COPY((s32) (this - 4) + 4, (s32) &arg_sp1AC + 4, 0x40);
}
#endif

void SpeedWay::Resolve() {
    MKProp::Resolve();
    this->unk4C.Resolve();
    this->unk94.Resolve();
}

#if 0 // DRAFT: expression syntax error
void SpeedWay::LoadDone() {
    MKProp::LoadDone();
    this->unk4C.LoadDone();
    this->unk94.LoadDone();
    this->unkDC.Init(*((KDUniformSpline *) &this->unk4C.unk2C), 0x10, 2);
    this->unkDC.unk4.Init(*((KDUniformSpline *) &this->unk94.unk2C), 0x10, 2);
}
#endif

#if 0 // DRAFT: function call 'LoadLine(SpeedWay *, MKIniLine *, const char[9])' does not
s32 SpeedWay::LoadLine(MKIniLine *arg0) {
    s32 var_r31_317;

    var_r31_317 = 0;
    if ((MKProp::LoadLine(arg0) != 0) || (this->unk4C.LoadLine(arg0, "pathLeft") != 0) || (this->unk94.LoadLine(arg0, "pathRight") != 0)) {
        var_r31_317 = 1;
    }
    return var_r31_317;
}
#endif

#if 0 // DRAFT: expression syntax error
void SpeedWay::Deinit() {
    this->unkDC.Deinit();
    this->unkDC.unk4.Deinit();
    this->unk4C.Deinit();
    this->unk94.Deinit();
    MKProp::Deinit();
}
#endif

void SpeedWay::Init() {
    MKProp::Init();
    this->unk4C.Init();
    this->unk94.Init();
}
