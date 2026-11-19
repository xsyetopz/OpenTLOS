#include "spyro/source/WobbleProperty.h"
#include "common/Source/Animation.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "spyro/source/KDProperty.h"
#include "common/Source/MKDynamicBone.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

s32 stricmp(s8 *, M2C_UNK *);                       /* extern */
extern s32 GS_PLACEHOLDER;
extern f32 gUpdateTimeDelta;
extern void **gb;

#if 0 // DRAFT: undefined identifier 'pInstanceMem'
void WobbleProperty::Command(int arg0) {
    if (arg0 == 1) {
        *(pInstanceMem.__vptr + (this->unk8 + 0xC)) = 0;
        M2C_FIELD(*(pInstanceMem.__vptr + this->unk8), s8 *, 0x30) = 0;
    }
}
#endif

#if 0 // DRAFT: function call 'stricmp(const char *, const char[8])' does not match
s32 WobbleProperty::ResolveCommand(const char *arg0) const {
    return stricmp(arg0, "Disable") == 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'pInstanceMem'
void WobbleProperty::Update() {
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f32 sp108;
    f32 spF8;
    f32 spE8;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp78;
    f32 sp68;
    f32 sp58;
    f32 sp48;
    f32 sp38;
    f32 sp28;
    f32 sp18;
    f32 sp8;
    f32 temp_f1_129;
    f32 temp_f1_86;
    f32 temp_f30_124;
    f32 temp_f3_350;
    f32 temp_f4_269;
    f32 var_f1_420;
    f32 var_f31_259;
    f32 var_f4_215;
    f32 var_f7_144;
    f64 temp_f2_154;
    f64 temp_f2_160;
    f64 temp_f2_164;
    s32 temp_r0_391;
    s32 temp_r3_183;
    s32 temp_r3_392;
    s32 temp_r3_404;
    s32 var_r0_193;
    void *temp_r30_116;
    void *temp_r3_256;
    void *temp_r3_335;
    void *temp_r4_334;

    if ((u8) *(pInstanceMem.__vptr + (this->unk8 + 0xC)) != 0) {
        temp_f1_86 = this->unk24;
        if (temp_f1_86 > 0.0f) {
            this->unk24 = temp_f1_86 - gUpdateTimeDelta;
        } else if (temp_f1_86 < 0.0f) {
            this->unk24 = 0.0f;
        }
        M2C_FIELD(*gb, M2C_UNK (**)(f64 *, void **), 0x2C)(&sp160, gb);
        sp1A0 = sp160;
        temp_r30_116 = pInstanceMem.__vptr + this->unk8;
        sp1A8 = sp168;
        temp_f30_124 = M2C_FIELD(*gb, f32 (**)(void **, void *, f64), 0x28)(gb, pInstanceMem.__vptr, sp160) + M2C_FIELD(temp_r30_116, f32 *, 4);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        temp_f1_129 = temp_f30_124 * temp_f30_124;
        sp190 = sp100;
        sp108 = M2C_FIELD(*(pInstanceMem.__vptr + this->unk8), f32 *, 8) - (f32) sp1A8;
        sp198 = (f64) sp108;
        var_f7_144 = ((f32) sp198 * (f32) sp198) + (((f32) sp190 * (f32) sp190) + (unksp194 * unksp194));
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (var_f7_144 == temp_f1_129) {
            if (var_f7_144 > 1e-12f) {
                if (var_f7_144 > 0.0f) {
                    temp_f2_154 = __frsqrte(var_f7_144);
                    temp_f2_160 = 0.5 * temp_f2_154 * -(((f64) var_f7_144 * (temp_f2_154 * temp_f2_154)) - 3.0);
                    temp_f2_164 = 0.5 * temp_f2_160 * -(((f64) var_f7_144 * (temp_f2_160 * temp_f2_160)) - 3.0);
                    var_f7_144 = (f32) ((f64) var_f7_144 * (0.5 * temp_f2_164 * -(((f64) var_f7_144 * (temp_f2_164 * temp_f2_164)) - 3.0)));
                } else if (var_f7_144 < M2C_BITWISE(f32, 0.0)) {
                    var_f7_144 = __float_nan;
                } else {
                    sp8 = var_f7_144;
                    temp_r3_183 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                    switch (temp_r3_183) {          /* irregular */
                    case 0x7F800000:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_193 = 1;
                        } else {
                            var_r0_193 = 2;
                        }
                        break;
                    case 0x0:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_193 = 5;
                        } else {
                            var_r0_193 = 3;
                        }
                        break;
                    default:
                        var_r0_193 = 4;
                        break;
                    }
                    if (var_r0_193 == 1) {
                        var_f7_144 = __float_nan;
                    }
                }
                var_f4_215 = 1.0f / var_f7_144;
            } else {
                var_f4_215 = 0.0f;
            }
            sp84 = unksp194 * var_f4_215;
            sp80 = (f32) sp190 * var_f4_215;
            sp88 = (f32) sp198 * var_f4_215;
            sp120 = (f64) sp80;
            sp128 = (f64) sp88;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f30 */);
            sp130 = spF0;
            spF8 = (f32) sp128 * temp_f30_124;
            sp138 = (f64) spF8;
            M2C_ERROR(/* unknown instruction: ps_add $f1, $f2, $f1 */);
            spE8 = (f32) sp1A8 + (f32) sp138;
            sp140 = spE0;
            temp_r3_256 = *(pInstanceMem.__vptr + this->unk8);
            sp148 = (f64) spE8;
            if (1.0f > 0.0625f) {
                var_f31_259 = 0.0625f;
            } else {
                var_f31_259 = 1.0f;
            }
            M2C_ERROR(/* unknown instruction: psq_lx $f2, $zero, $r3, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f3, $f2 */);
            temp_f4_269 = M2C_FIELD(temp_r3_256, f32 *, 8);
            spB0 = sp70;
            sp78 = (f32) sp148 - temp_f4_269;
            spB8 = (f64) sp78;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            spA0 = sp60;
            sp68 = (f32) spB8 * var_f31_259;
            spA8 = (f64) sp68;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
            sp90 = sp50;
            sp58 = temp_f4_269 + (f32) spA8;
            sp98 = (f64) sp58;
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f3, $f2 */);
            spD0 = sp40;
            sp48 = (f32) sp148 - (f32) sp98;
            spD8 = (f64) sp48;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            spC0 = sp30;
            sp38 = (f32) spD8 * var_f31_259;
            spC8 = (f64) sp38;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
            M2C_FIELD(temp_r3_256, f64 *, 0) = sp20;
            sp28 = (f32) sp98 + (f32) spC8;
            sp150 = sp20;
            M2C_FIELD(temp_r3_256, f32 *, 8) = (f64) sp28;
            sp158 = (f64) sp28;
            temp_r4_334 = pInstanceMem.__vptr + this->unk8;
            temp_r3_335 = M2C_FIELD(temp_r4_334, void **, 0);
            sp180 = M2C_FIELD(temp_r3_256, f64 *, 0);
            sp188 = (f64) M2C_FIELD(temp_r3_256, f32 *, 8);
            sp170 = M2C_FIELD(temp_r3_335, f64 *, 0x10);
            sp178 = M2C_FIELD(temp_r3_335, f64 *, 0x18);
            if (((s32) this->unk30 != 0) && ((u8) this->unk40 == 0) && (this->unk24 == 0.0f)) {
                temp_f3_350 = M2C_FIELD(temp_r4_334, f32 *, 8);
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f2, $f0 */);
                sp110 = sp10;
                sp18 = (f32) sp188 - (f32) sp178;
                sp118 = (f64) sp18;
                M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
                if ((((f32) sp118 * (f32) sp118) + (((f32) sp110 * (f32) sp110) + (unksp114 * unksp114))) == (temp_f3_350 * temp_f3_350)) {
                    this->unk40 = 1;
                    this->unk24 = this->unk1C;
                    M2C_FIELD((this + (this->unk3C * 4)), s32 *, 0x34) = KDSound_Play3d(this->unk30, M2C_FIELD(pInstanceMem.__vptr, s32 *, 8) + 0x30, 0U, -1, 0.0f, 0U);
                    temp_r0_391 = this->unk3C - 1;
                    temp_r3_392 = temp_r0_391 >> 0x1F;
                    this->unk3C = (temp_r3_392 ^ temp_r0_391) - temp_r3_392;
                }
            }
        } else {
            this->unk40 = 0;
        }
        temp_r3_404 = M2C_FIELD((this + (this->unk3C * 4)), s32 *, 0x34);
        if ((temp_r3_404 != 0) && (KDSound_IsVoicePlaying(temp_r3_404) != 0)) {
            var_f1_420 = -((4.0f * (this->unk2C * gUpdateTimeDelta)) - KDSound_GetVolume(M2C_FIELD((this + (this->unk3C * 4)), s32 *, 0x34)));
            if (var_f1_420 < 1.0f) {

            } else {
                var_f1_420 = 1.0f;
            }
            if (var_f1_420 > 0.0f) {

            } else {
                var_f1_420 = 0.0f;
            }
            if (var_f1_420 != 0.0f) {
                KDSound_SetVolume(M2C_FIELD((this + (this->unk3C * 4)), s32 *, 0x34), var_f1_420);
                return;
            }
            KDSound_Stop(this + ((this->unk3C * 4) + 0x34));
        }
    }
}
#endif

void WobbleProperty::ResolveInstance() {

}

#if 0 // DRAFT: undefined identifier 'pInstanceMem'
void WobbleProperty::LoadDoneInstance() {
    MKModel *temp_r28_479;
    f32 var_f4_510;
    f64 temp_f1_513;
    f64 temp_f1_519;
    f64 temp_f1_523;
    s32 temp_r30_486;
    s32 temp_r3_542;
    s32 var_r0_552;
    void *temp_r29_484;
    void *temp_r3_586;
    temp_r28_479 = M2C_FIELD(pInstanceMem.__vptr, MKModel **, 4);
    temp_r29_484 = pInstanceMem.__vptr;
    temp_r30_486 = this->unk8;
    *(temp_r29_484 + temp_r30_486) = MKDynamicBone_GetDynamicBone(temp_r28_479, ((Animation *) (MKModel_GetAnimation(temp_r28_479)))->GetNodeIndex(M2C_BITWISE(s8 *, this->unk14)));
    M2C_STRUCT_COPY((s32) &arg_sp1C + 4, M2C_FIELD(pInstanceMem.__vptr, s32 *, 8) - 4 + 4, 0x40);
    var_f4_510 = (arg_sp28 * arg_sp28) + ((arg_sp20 * arg_sp20) + (arg_sp24 * arg_sp24));
    if (var_f4_510 > 0.0f) {
        temp_f1_513 = __frsqrte(var_f4_510);
        temp_f1_519 = 0.5 * temp_f1_513 * -(((f64) var_f4_510 * (temp_f1_513 * temp_f1_513)) - 3.0);
        temp_f1_523 = 0.5 * temp_f1_519 * -(((f64) var_f4_510 * (temp_f1_519 * temp_f1_519)) - 3.0);
        var_f4_510 = (f32) ((f64) var_f4_510 * (0.5 * temp_f1_523 * -(((f64) var_f4_510 * (temp_f1_523 * temp_f1_523)) - 3.0)));
    } else if (var_f4_510 < M2C_BITWISE(f32, 0.0)) {
        var_f4_510 = __float_nan;
    } else {
        arg_sp10 = var_f4_510;
        temp_r3_542 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
        switch (temp_r3_542) {                      /* irregular */
        case 0x7F800000:
            if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                var_r0_552 = 1;
            } else {
                var_r0_552 = 2;
            }
            break;
        case 0x0:
            if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                var_r0_552 = 5;
            } else {
                var_r0_552 = 3;
            }
            break;
        default:
            var_r0_552 = 4;
            break;
        }
        if (var_r0_552 == 1) {
            var_f4_510 = __float_nan;
        }
    }
    *(pInstanceMem.__vptr + (this->unk8 + 4)) = this->unk18 * (f32) fabs((f32) fabs(var_f4_510));
    temp_r3_586 = pInstanceMem.__vptr + this->unk8;
    M2C_FIELD(temp_r3_586, f32 *, 8) = (f32) (this->unk20 * M2C_FIELD(temp_r3_586, f32 *, 4));
}
#endif

#if 0 // DRAFT: identifier 'WobbleProperty::LoadLineInstance(MKIniLine *)' redeclared
void WobbleProperty::LoadLineInstance(MKIniLine *arg0) {
    arg0->LoadString("bonename", (s8 **) &this->unk14, 0);
}
#endif

#if 0 // DRAFT: undefined identifier 'pInstanceMem'
void WobbleProperty::InitInstance() {
    f32 var_r31_632;
    void *temp_r4_629;

    temp_r4_629 = pInstanceMem.__vptr + this->unk8;
    M2C_FIELD(temp_r4_629, s8 *, 0xC) = 1;
    M2C_FIELD(temp_r4_629, s32 *, 0) = 0;
    var_r31_632 = this->unk10;
loop_2:
    if (M2C_BITWISE(u32, var_r31_632) != 0U) {
        LoadLineInstance(var_r31_632);
        var_r31_632 = M2C_BITWISE(f32, ((MKIni *) (M2C_FIELD(var_r31_632, MKIni **, 0xC)))->GetNextLine(M2C_BITWISE(MKIniLine *, var_r31_632)));
        goto loop_2;
    }
}
#endif

void WobbleProperty::Resolve(KDPropertySet *arg0) {
    s32 temp_r3_663;

    temp_r3_663 = this->unk30;
    if (temp_r3_663 != 0) {
        this->unk2C = (f32) KDSound_GetSoundEventVol(temp_r3_663) / 255.0f;
        return;
    }
    this->unk2C = 0.0f;
}

#if 0 // DRAFT: identifier 'WobbleProperty::LoadLine(MKIniLine *)' redeclared
u8 WobbleProperty::LoadLine(MKIniLine *arg0) {
    u8 var_r31_708;

    if (M2C_BITWISE(u32, this->unk10) == 0U) {
        this->unk10 = M2C_BITWISE(f32, arg0);
    }
    var_r31_708 = 0;
    if ((arg0->LoadFloat("collisionradius", &this->unk18, 0) != 0) || (arg0->LoadFloat("antispamDelay", &this->unk1C, 0) != 0) || (arg0->LoadFloat("HitSoundSensitivity", &this->unk20, 0) != 0) || (KDSound_LoadLine(arg0, "hitSound", &this->unk30) != 0)) {
        var_r31_708 = 1;
    }
    return var_r31_708;
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
WobbleProperty::WobbleProperty() {
    this->unk4 = 0;
    this->unkC = NULL;
    this->unk8 = 0;
    this->unk34 = 0;
    this->unk38 = 0;
    this->unk10 = 0.0f;
    this->unk3C = 0;
    this->unk40 = 0;
    this->unk24 = 0.0f;
    this->unk1C = 0.0f;
    this->unk30 = GS_PLACEHOLDER;
    this->unk20 = 0.05f;
    this->unk18 = 150.0f;
    return this;
}
#endif
