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

#if 0 // DRAFT: pointer/array required
void WobbleProperty::Command(int arg0) {
    if (arg0 == 1) {
        *(*KDProperty::pInstanceMem + (this->unk8 + 0xC)) = 0;
        M2C_FIELD(*(*KDProperty::pInstanceMem + this->unk8), s8 *, 0x30) = 0;
    }
}
#endif

#if 0 // DRAFT: function call 'stricmp(const char *, const char[8])' does not match
s32 WobbleProperty::ResolveCommand(const char *arg0) const {
    return stricmp(arg0, "Disable") == 0;
}
#endif

#if 0 // DRAFT: pointer/array required
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
    f64 sp100;
    f32 spF8;
    f64 spF0;
    f32 spE8;
    f64 spE0;
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
    f64 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    f32 temp_f1_86;
    f32 temp_f30_124;
    f32 temp_f3_350;
    f32 temp_f4_269;
    f32 var_f1_420;
    f32 var_f31_259;
    f32 var_f4_215;
    f32 var_f7_144;
    f64 temp_f0_266;
    f64 temp_f0_277;
    f64 temp_f0_287;
    f64 temp_f0_297;
    f64 temp_f0_307;
    f64 temp_f0_317;
    f64 temp_f1_232;
    f64 temp_f2_154;
    f64 temp_f2_160;
    f64 temp_f2_164;
    f64 temp_f2_265;
    s32 temp_r0_391;
    s32 temp_r3_183;
    s32 temp_r3_392;
    s32 temp_r3_404;
    s32 var_r0_193;
    void *temp_r30_116;
    void *temp_r3_123;
    void *temp_r3_256;
    void *temp_r3_335;
    void *temp_r4_334;

    if ((u8) *(*KDProperty::pInstanceMem + (this->unk8 + 0xC)) != 0) {
        temp_f1_86 = this->unk24;
        if (temp_f1_86 > 0.0f) {
            this->unk24 = temp_f1_86 - gUpdateTimeDelta;
        } else if (temp_f1_86 < 0.0f) {
            this->unk24 = 0.0f;
        }
        M2C_FIELD(*gb, M2C_UNK (**)(f64 *, void **), 0x2C)(&sp160, gb);
        sp1A0 = sp160;
        temp_r30_116 = *KDProperty::pInstanceMem + this->unk8;
        sp1A8 = sp168;
        temp_r3_123 = *(*KDProperty::pInstanceMem + this->unk8);
        temp_f30_124 = M2C_FIELD(*gb, f32 (**)(void **, void *, f64), 0x28)(gb, *KDProperty::pInstanceMem, sp160) + M2C_FIELD(temp_r30_116, f32 *, 4);
        sp100 = M2C_FIELD(temp_r3_123, f64 *, 0) - sp1A0;
        sp190 = sp100;
        sp108 = M2C_FIELD(temp_r3_123, f32 *, 8) - (f32) sp1A8;
        sp198 = (f64) sp108;
        var_f7_144 = ((f32) sp198 * (f32) sp198) + (((f32) sp190 * (f32) sp190) + ((*(f32 *) ((u8 *) &sp190 + 0x4)) * (*(f32 *) ((u8 *) &sp190 + 0x4))));
        if (var_f7_144 <= (temp_f30_124 * temp_f30_124)) {
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
            sp84 = (*(f32 *) ((u8 *) &sp190 + 0x4)) * var_f4_215;
            sp80 = (f32) sp190 * var_f4_215;
            sp88 = (f32) sp198 * var_f4_215;
            sp120 = (f64) sp80;
            sp128 = (f64) sp88;
            temp_f1_232 = sp120 * (f64) temp_f30_124;
            spF0 = temp_f1_232;
            sp130 = temp_f1_232;
            spF8 = (f32) sp128 * temp_f30_124;
            sp138 = (f64) spF8;
            spE0 = sp1A0 + temp_f1_232;
            spE8 = (f32) sp1A8 + (f32) sp138;
            sp140 = spE0;
            temp_r3_256 = *(*KDProperty::pInstanceMem + this->unk8);
            sp148 = (f64) spE8;
            if (1.0f > 0.0625f) {
                var_f31_259 = 0.0625f;
            } else {
                var_f31_259 = 1.0f;
            }
            temp_f2_265 = M2C_FIELD(temp_r3_256, f64 *, 0);
            temp_f0_266 = sp140 - temp_f2_265;
            sp70 = temp_f0_266;
            temp_f4_269 = M2C_FIELD(temp_r3_256, f32 *, 8);
            spB0 = temp_f0_266;
            sp78 = (f32) sp148 - temp_f4_269;
            spB8 = (f64) sp78;
            temp_f0_277 = temp_f0_266 * (f64) var_f31_259;
            sp60 = temp_f0_277;
            spA0 = temp_f0_277;
            sp68 = (f32) spB8 * var_f31_259;
            spA8 = (f64) sp68;
            temp_f0_287 = temp_f2_265 + temp_f0_277;
            sp50 = temp_f0_287;
            sp90 = temp_f0_287;
            sp58 = temp_f4_269 + (f32) spA8;
            sp98 = (f64) sp58;
            temp_f0_297 = sp140 - sp90;
            sp40 = temp_f0_297;
            spD0 = temp_f0_297;
            sp48 = (f32) sp148 - (f32) sp98;
            spD8 = (f64) sp48;
            temp_f0_307 = temp_f0_297 * (f64) var_f31_259;
            sp30 = temp_f0_307;
            spC0 = temp_f0_307;
            sp38 = (f32) spD8 * var_f31_259;
            spC8 = (f64) sp38;
            temp_f0_317 = sp90 + temp_f0_307;
            sp20 = temp_f0_317;
            M2C_FIELD(temp_r3_256, f64 *, 0) = temp_f0_317;
            sp28 = (f32) sp98 + (f32) spC8;
            sp150 = temp_f0_317;
            M2C_FIELD(temp_r3_256, f32 *, 8) = (f64) sp28;
            sp158 = (f64) sp28;
            temp_r4_334 = *KDProperty::pInstanceMem + this->unk8;
            temp_r3_335 = M2C_FIELD(temp_r4_334, void **, 0);
            sp180 = M2C_FIELD(temp_r3_256, f64 *, 0);
            sp188 = (f64) M2C_FIELD(temp_r3_256, f32 *, 8);
            sp170 = M2C_FIELD(temp_r3_335, f64 *, 0x10);
            sp178 = M2C_FIELD(temp_r3_335, f64 *, 0x18);
            if (((s32) this->unk30 != 0) && ((u8) this->unk40 == 0) && (this->unk24 == 0.0f)) {
                temp_f3_350 = M2C_FIELD(temp_r4_334, f32 *, 8);
                sp10 = sp180 - sp170;
                sp110 = sp10;
                sp18 = (f32) sp188 - (f32) sp178;
                sp118 = (f64) sp18;
                if ((((f32) sp118 * (f32) sp118) + (((f32) sp110 * (f32) sp110) + ((*(f32 *) ((u8 *) &sp110 + 0x4)) * (*(f32 *) ((u8 *) &sp110 + 0x4))))) >= (temp_f3_350 * temp_f3_350)) {
                    this->unk40 = 1;
                    this->unk24 = this->unk1C;
                    M2C_FIELD((this + (this->unk3C * 4)), s32 *, 0x34) = KDSound_Play3d(this->unk30, M2C_FIELD(*KDProperty::pInstanceMem, s32 *, 8) + 0x30, 0U, -1, 0.0f, 0U);
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

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char' to
void WobbleProperty::LoadDoneInstance() {
    M2C_UNK sp1C;
    f32 sp10;
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

    temp_r28_479 = M2C_FIELD(*KDProperty::pInstanceMem, MKModel **, 4);
    temp_r29_484 = *KDProperty::pInstanceMem;
    temp_r30_486 = this->unk8;
    *(temp_r29_484 + temp_r30_486) = MKDynamicBone_GetDynamicBone(temp_r28_479, ((Animation *) (MKModel_GetAnimation(temp_r28_479)))->GetNodeIndex(M2C_BITWISE(s8 *, this->unk14)));
    M2C_STRUCT_COPY((s32) &sp1C + 4, M2C_FIELD(*KDProperty::pInstanceMem, s32 *, 8) - 4 + 4, 0x40);
    var_f4_510 = (sp28 * sp28) + ((sp20 * sp20) + (sp24 * sp24));
    if (var_f4_510 > 0.0f) {
        temp_f1_513 = __frsqrte(var_f4_510);
        temp_f1_519 = 0.5 * temp_f1_513 * -(((f64) var_f4_510 * (temp_f1_513 * temp_f1_513)) - 3.0);
        temp_f1_523 = 0.5 * temp_f1_519 * -(((f64) var_f4_510 * (temp_f1_519 * temp_f1_519)) - 3.0);
        var_f4_510 = (f32) ((f64) var_f4_510 * (0.5 * temp_f1_523 * -(((f64) var_f4_510 * (temp_f1_523 * temp_f1_523)) - 3.0)));
    } else if (var_f4_510 < M2C_BITWISE(f32, 0.0)) {
        var_f4_510 = __float_nan;
    } else {
        sp10 = var_f4_510;
        temp_r3_542 = M2C_BITWISE(s32, sp10) & 0x7F800000;
        switch (temp_r3_542) {                      /* irregular */
        case 0x7F800000:
            if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                var_r0_552 = 1;
            } else {
                var_r0_552 = 2;
            }
            break;
        case 0x0:
            if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
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
    *(*KDProperty::pInstanceMem + (this->unk8 + 4)) = this->unk18 * (f32) fabs((f32) fabs(var_f4_510));
    temp_r3_586 = *KDProperty::pInstanceMem + this->unk8;
    M2C_FIELD(temp_r3_586, f32 *, 8) = (f32) (this->unk20 * M2C_FIELD(temp_r3_586, f32 *, 4));
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to
s32 WobbleProperty::LoadLineInstance(MKIniLine *arg0) {
    arg0->LoadString("bonename", (s8 **) &this->unk14, 0);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void WobbleProperty::InitInstance() {
    f32 var_r31_632;
    void *temp_r4_629;

    temp_r4_629 = *KDProperty::pInstanceMem + this->unk8;
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

#if 0 // DRAFT: illegal explicit conversion from 'MKIniLine *' to
s32 WobbleProperty::LoadLine(MKIniLine *arg0) {
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
    this->unk4 = NULL;
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
