#include "spyro/source/GameParticleEmitter.h"
#include "common/Source/Animation.h"
#include "common/Source/Font.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKFont.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
#include "spyro/source/DialogBox.h"
#include "spyro/source/EmbersPS.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/Explosion4.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/FlyingBurningBits.h"
#include "spyro/source/FoundryGas.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/KDParticleSystem.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/LavaBubbleFX.h"
#include "spyro/source/LavaSteamPS.h"
#include "spyro/source/Level.h"
#include "spyro/source/LiquidFX.h"
#include "spyro/source/ManagedLight.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/SparksPS.h"
#include "spyro/source/TargetManager.h"
#include "spyro/source/WaterDripPS.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDRandom.h"
#include <m2c_macros.h>

extern MKSceneManager *gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;
static s32 lit_717 = 1;

void PointDirEmitter::SetPosition(const MKVector3 &arg0) {
    this->unk28 = M2C_FIELD(&arg0, f64 *, 0);
    this->unk30 = M2C_FIELD(&arg0, f64 *, 8);
}

void PointDirEmitter::SetDirection(const MKVector3 &arg0) {
    this->unk18 = M2C_FIELD(&arg0, f64 *, 0);
    this->unk20 = M2C_FIELD(&arg0, f64 *, 8);
}

#if 0 // DRAFT: undefined identifier 'MKVector'
void PointDirEmitter::GetEmissionData(MKVector3 *arg0, MKVector3 *arg1, MKVector3 *arg2, MKVector4 *arg3) {
    Matrix sp100;
    M2C_UNK spFC;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    MKVector3 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 temp_f1_148;
    f32 temp_f1_308;
    f32 temp_f1_57;
    f32 temp_f28_80;
    f32 temp_f29_75;
    f32 temp_f2_58;
    f32 temp_f31_133;
    f32 temp_f3_255;
    f32 temp_f6_262;
    f32 temp_f7_268;
    f32 var_f27_64;
    f32 var_f3_223;
    f32 var_f4_156;
    f64 temp_f0_242;
    f64 temp_f0_91;
    f64 temp_f1_162;
    f64 temp_f1_168;
    f64 temp_f1_172;
    f64 temp_f1_294;
    s32 temp_r3_191;
    s32 var_r0_201;

    if (arg0 != NULL) {
        M2C_FIELD(arg0, f64 *, 0) = (f64) this->unk28;
        M2C_FIELD(arg0, f64 *, 8) = (f64) this->unk30;
        temp_f1_57 = this->unk38;
        temp_f2_58 = this->unk3C;
        if ((temp_f1_57 == temp_f2_58) || (temp_f1_57 > temp_f2_58)) {
            var_f27_64 = 0.0f;
        } else {
            var_f27_64 = MKRand_Float((int *) &gViewSeed, temp_f1_57, temp_f2_58);
        }
        temp_f29_75 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        temp_f28_80 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        MKVector(MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f), temp_f28_80, temp_f29_75);
        temp_f0_91 = spC8 * (f64) var_f27_64;
        sp28 = temp_f0_91;
        spD8 = temp_f0_91;
        sp30 = spD0 * var_f27_64;
        spE0 = (f64) sp30;
        M2C_FIELD(arg0, f64 *, 0) = (f64) (M2C_FIELD(arg0, f64 *, 0) + temp_f0_91);
        arg0->unk8 += (f32) spE0;
    }
    if (arg1 != NULL) {
        M2C_FIELD(arg1, f64 *, 0) = (f64) this->unk18;
        M2C_FIELD(arg1, f64 *, 8) = (f64) this->unk20;
        M2C_STRUCT_COPY((s32) &spFC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
        sp70 = -1.0f;
        temp_f31_133 = this->unk40;
        sp60 = 1.0f;
        sp68 = -1.0f;
        sp6C = -1.0f;
        sp58 = 1.0f;
        sp5C = 1.0f;
        sp98 = (f64) sp68;
        spA0 = (f64) sp70;
        sp88 = (f64) sp58;
        sp90 = (f64) sp60;
        KDRand_Vector(spA8, *((MKVector3 *) &sp98));
        temp_f1_148 = M2C_BITWISE(f32, spA8);
        var_f4_156 = (spA8.unk8 * spA8.unk8) + ((temp_f1_148 * temp_f1_148) + (spA8.unk4 * spA8.unk4));
        if (var_f4_156 > 1e-12f) {
            if (var_f4_156 > 0.0f) {
                temp_f1_162 = __frsqrte(var_f4_156);
                temp_f1_168 = 0.5 * temp_f1_162 * -(((f64) var_f4_156 * (temp_f1_162 * temp_f1_162)) - 3.0);
                temp_f1_172 = 0.5 * temp_f1_168 * -(((f64) var_f4_156 * (temp_f1_168 * temp_f1_168)) - 3.0);
                var_f4_156 = (f32) ((f64) var_f4_156 * (0.5 * temp_f1_172 * -(((f64) var_f4_156 * (temp_f1_172 * temp_f1_172)) - 3.0)));
            } else if (var_f4_156 < M2C_BITWISE(f32, 0.0)) {
                var_f4_156 = __float_nan;
            } else {
                sp10 = var_f4_156;
                temp_r3_191 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_191) {              /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_201 = 1;
                    } else {
                        var_r0_201 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_201 = 5;
                    } else {
                        var_r0_201 = 3;
                    }
                    break;
                default:
                    var_r0_201 = 4;
                    break;
                }
                if (var_r0_201 == 1) {
                    var_f4_156 = __float_nan;
                }
            }
            var_f3_223 = 1.0f / var_f4_156;
        } else {
            var_f3_223 = 0.0f;
        }
        sp38 = M2C_BITWISE(f32, spA8) * var_f3_223;
        sp3C = spA8.unk4 * var_f3_223;
        sp40 = spA8.unk8 * var_f3_223;
        spB8 = (f64) sp38;
        spC0 = (f64) sp40;
        temp_f0_242 = spB8 * (f64) temp_f31_133;
        sp48 = temp_f0_242;
        spE8 = temp_f0_242;
        sp50 = (f32) spC0 * temp_f31_133;
        spF0 = (f64) sp50;
        sp100.RotatePYR(&sp100, *((MKVector3 *) &spE8));
        temp_f3_255 = arg1->unk4;
        temp_f6_262 = arg1->unk0;
        temp_f7_268 = arg1->unk8;
        sp18 = sp100.unk30 + ((temp_f7_268 * sp100.unk20) + ((temp_f6_262 * M2C_BITWISE(f32, sp100)) + (temp_f3_255 * sp100.unk10)));
        sp1C = sp100.unk34 + ((temp_f7_268 * sp100.unk24) + ((temp_f6_262 * sp100.unk4) + (temp_f3_255 * sp100.unk14)));
        sp20 = sp100.unk38 + ((temp_f7_268 * sp100.unk28) + ((temp_f6_262 * sp100.unk8) + (temp_f3_255 * sp100.unk18)));
        M2C_FIELD(arg1, f64 *, 0) = (f64) sp18;
        M2C_FIELD(arg1, f64 *, 8) = (f64) sp20;
        sp78 = (f64) sp18;
        sp80 = (f64) sp20;
        temp_f1_294 = MKRand_Float((int *) &gViewSeed, this->unk10, this->unkC);
        M2C_FIELD(arg1, f64 *, 0) = (f64) (M2C_FIELD(arg1, f64 *, 0) * temp_f1_294);
        arg1->unk8 *= (f32) temp_f1_294;
    }
    if (arg2 != NULL) {
        temp_f1_308 = MKRand_Float((int *) &gViewSeed, this->unk8, this->unk4);
        arg2->unk0 = temp_f1_308;
        arg2->unk4 = temp_f1_308;
        arg2->unk8 = temp_f1_308;
    }
}
#endif

void PointDirEmitter::Deinit() {

}

void PointDirEmitter::Draw() {

}

void PointDirEmitter::Update() {

}

void PointDirEmitter::LoadDone() {

}

s32 PointDirEmitter::LoadLine(MKIniLine *arg0) {
    MKIniLine *var_r30_364;

    var_r30_364 = arg0;
loop_2:
    if (var_r30_364 != NULL) {
        var_r30_364->LoadFloat("MinVel", &this->unk10, 0);
        var_r30_364->LoadFloat("MaxVel", &this->unkC, 0);
        var_r30_364->LoadFloat("MinScale", &this->unk8, 0);
        var_r30_364->LoadFloat("MaxScale", &this->unk4, 0);
        var_r30_364->LoadFloat("MinRadialOffs", &this->unk38, 0);
        var_r30_364->LoadFloat("MaxRadialOffs", &this->unk3C, 0);
        var_r30_364->LoadFloat("EmissionCone", &this->unk40, 0);
        var_r30_364 = var_r30_364->unkC->GetNextLine(var_r30_364);
        goto loop_2;
    }
    return 0;
}

void PointDirEmitter::Init() {
    this->unk38 = 0.0f;
    this->unk3C = 0.0f;
    this->unk40 = 0.0f;
}

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void DirectedLineEmitter::GetEmissionData(MKVector3 *arg0, MKVector3 *arg1, MKVector3 *arg2, MKVector4 *arg3) {
    MKVector3 sp168;
    MKVector3 sp158;
    f64 sp150;
    f64 sp148;
    MKVector3 sp138;
    MKVector3 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    MKVector3 spE8;
    MKVector3 spD8;
    f64 spD0;
    f64 spC8;
    f64 spB8;
    MKVector3 spA8;
    f64 spA0;
    f64 sp98;
    MKVector3 sp88;
    f64 sp80;
    f64 sp78;
    f32 sp70;
    f64 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f1_629;
    f32 temp_f1_686;
    f32 temp_f1_740;
    f32 temp_f28_652;
    f32 temp_f29_736;
    f32 temp_f2_478;
    f32 temp_f2_630;
    f32 temp_f31_541;
    f32 temp_f31_647;
    f32 temp_f31_731;
    f32 var_f29_636;
    f64 temp_f0_544;
    f64 temp_f0_555;
    f64 temp_f0_581;
    f64 temp_f0_607;
    f64 temp_f0_663;
    f64 temp_f0_706;
    f64 temp_f1_767;
    f64 temp_f3_543;
    s32 temp_r0_693;
    s32 temp_r3_448;
    s32 temp_r3_530;

    if (arg0 != NULL) {
        temp_r3_448 = this->unk9C;
        if (temp_r3_448 & 1) {
            this->unk38 = MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f);
            ((KDPathSegment *) &this->unk3C)->GetPositionAlongPath(this->unk38, *arg0);
        } else if (temp_r3_448 & 2) {
            if ((s32) this->unkA0 == 0) {
                this->unk38 += gUpdateTimeDelta;
            } else {
                this->unk38 -= gUpdateTimeDelta;
            }
            temp_f2_478 = this->unk38;
            if (temp_f2_478 > 1.0f) {
                if (this->unk9C & 4) {
                    if ((s32) this->unkA0 == 0) {
                        this->unkA0 = 1;
                    } else {
                        this->unkA0 = 0;
                    }
                    this->unk38 = 1.0f;
                } else {
                    this->unk38 = 0.0f;
                }
            } else if (temp_f2_478 < 0.0f) {
                if (this->unk9C & 4) {
                    if ((s32) this->unkA0 == 0) {
                        this->unkA0 = 1;
                    } else {
                        this->unkA0 = 0;
                    }
                    this->unk38 = 0.0f;
                } else {
                    this->unk38 = 1.0f;
                }
            }
            ((KDPathSegment *) &this->unk3C)->GetPositionAlongPath(this->unk38, *arg0);
        }
        temp_r3_530 = this->unk9C;
        if (temp_r3_530 & 8) {
            ((KDPathSegment *) &this->unk3C.unk2C)->GetPositionAlongPath(this->unk38, sp168);
            temp_f31_541 = MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f);
            temp_f3_543 = M2C_FIELD(arg0, f64 *, 0);
            temp_f0_544 = M2C_BITWISE(f64, sp168) - temp_f3_543;
            sp8 = temp_f0_544;
            sp108 = temp_f0_544;
            sp10 = sp168.unk8 - arg0->unk8;
            sp110 = (f64) sp10;
            temp_f0_555 = temp_f0_544 * (f64) temp_f31_541;
            sp58 = temp_f0_555;
            sp118 = temp_f0_555;
            sp60 = (f32) sp110 * temp_f31_541;
            sp120 = (f64) sp60;
            M2C_FIELD(arg0, f64 *, 0) = (f64) (temp_f3_543 + temp_f0_555);
            arg0->unk8 += (f32) sp120;
        } else if (temp_r3_530 & 0x10) {
            ((KDPathSegment *) &this->unk3C.unk2C)->GetPositionAlongPath(this->unk38, sp158);
            temp_f0_581 = M2C_BITWISE(f64, sp158) - M2C_FIELD(arg0, f64 *, 0);
            sp68 = temp_f0_581;
            sp148 = temp_f0_581;
            sp70 = sp158.unk8 - arg0->unk8;
            sp150 = (f64) sp70;
            spD8.operator*(0.5f * ((std *) (M2C_ERROR(/* Read from unset register $r3 */)))->sin(100.0f * this->unk38));
            spE8.operator*(0.5f);
            temp_f0_607 = spE8 + M2C_BITWISE(f64, spD8);
            sp48 = temp_f0_607;
            spF8 = temp_f0_607;
            sp50 = spE8.unk8 + spD8.unk8;
            sp100 = (f64) sp50;
            M2C_FIELD(arg0, f64 *, 0) = (f64) (M2C_FIELD(arg0, f64 *, 0) + temp_f0_607);
            arg0->unk8 += (f32) sp100;
        }
        if (this->unk9C & 0x20) {
            temp_f1_629 = M2C_BITWISE(f32, this->unkA4);
            temp_f2_630 = this->unkA8;
            if ((temp_f1_629 == temp_f2_630) || (temp_f1_629 > temp_f2_630)) {
                var_f29_636 = 0.0f;
            } else {
                var_f29_636 = MKRand_Float((int *) &gViewSeed, temp_f1_629, temp_f2_630);
            }
            temp_f31_647 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
            temp_f28_652 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
            MKVector(MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f), temp_f28_652, temp_f31_647);
            temp_f0_663 = spB8 * (f64) var_f29_636;
            sp38 = temp_f0_663;
            spC8 = temp_f0_663;
            sp40 = spC0 * var_f29_636;
            spD0 = (f64) sp40;
            M2C_FIELD(arg0, f64 *, 0) = (f64) (M2C_FIELD(arg0, f64 *, 0) + temp_f0_663);
            arg0->unk8 += (f32) spD0;
        }
    }
    if (arg2 != NULL) {
        temp_f1_686 = MKRand_Float((int *) &gViewSeed, this->unk8, this->unk4);
        arg2->unk0 = temp_f1_686;
        arg2->unk4 = temp_f1_686;
        arg2->unk8 = temp_f1_686;
    }
    if (arg1 != NULL) {
        temp_r0_693 = this->unk9C;
        switch (temp_r0_693) {                      /* irregular */
        case 0:
            ((KDPathSegment *) &this->unk3C)->GetPositionAlongPath(this->unk38, sp138);
            ((KDPathSegment *) &this->unk3C.unk2C)->GetPositionAlongPath(this->unk38, sp128);
            temp_f0_706 = M2C_BITWISE(f64, sp128) - M2C_BITWISE(f64, sp138);
            sp28 = temp_f0_706;
            sp98 = temp_f0_706;
            sp30 = sp128.unk8 - sp138.unk8;
            spA0 = (f64) sp30;
            Normalise(spA8);
            M2C_FIELD(arg1, f64 *, 0) = M2C_BITWISE(f64, spA8);
            M2C_FIELD(arg1, f64 *, 8) = (f64) spA8.unk8;
            break;
        case 1:
            temp_f31_731 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
            temp_f29_736 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
            temp_f1_740 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
            sp20 = temp_f31_731;
            sp18 = temp_f1_740;
            sp1C = temp_f29_736;
            sp80 = (f64) sp20;
            sp78 = (f64) sp18;
            Normalise(sp88);
            M2C_FIELD(arg1, f64 *, 0) = M2C_BITWISE(f64, sp88);
            M2C_FIELD(arg1, f64 *, 8) = (f64) sp88.unk8;
            break;
        case 2:
            M2C_FIELD(arg1, f64 *, 0) = (f64) this->unk18;
            M2C_FIELD(arg1, f64 *, 8) = (f64) this->unk20;
            break;
        }
        temp_f1_767 = MKRand_Float((int *) &gViewSeed, this->unk10, this->unkC);
        M2C_FIELD(arg1, f64 *, 0) = (f64) (M2C_FIELD(arg1, f64 *, 0) * temp_f1_767);
        arg1->unk8 *= (f32) temp_f1_767;
    }
}
#endif

void DirectedLineEmitter::Deinit() {
    ((KDPathSegment *) &this->unk3C.unk2C)->Deinit();
    ((KDPathSegment *) &this->unk3C)->Deinit();
}

void DirectedLineEmitter::Draw() {

}

void DirectedLineEmitter::Update() {

}

void DirectedLineEmitter::LoadDone() {
    ((KDPathSegment *) &this->unk3C.unk2C)->LoadDone();
    ((KDPathSegment *) &this->unk3C)->LoadDone();
}

s32 DirectedLineEmitter::LoadLine(MKIniLine *arg0) {
    MKIniLine *var_r30_865;

    var_r30_865 = arg0;
loop_2:
    if (var_r30_865 != NULL) {
        var_r30_865->LoadInt("EmissionPosType", (int *) &this->unk9C, 0);
        var_r30_865->LoadInt("DirectionType", (int *) &this->unk9C, 0);
        var_r30_865->LoadInt("LinearDirectionType", (int *) &this->unkA0, 0);
        var_r30_865->LoadFloat("MinRadialOffs", (f32 *) &this->unkA4, 0);
        var_r30_865->LoadFloat("MaxRadialOffs", &this->unkA8, 0);
        var_r30_865->LoadFloat("MinScale", &this->unk8, 0);
        var_r30_865->LoadFloat("MaxScale", &this->unk4, 0);
        var_r30_865->LoadFloat("MinVel", &this->unk10, 0);
        var_r30_865->LoadFloat("MaxVel", &this->unkC, 0);
        ((KDPathSegment *) &this->unk3C.unk2C)->LoadWaypoints(var_r30_865, "DestPath");
        ((KDPathSegment *) &this->unk3C)->LoadWaypoints(var_r30_865, "SourcePath");
        var_r30_865 = var_r30_865->unkC->GetNextLine(var_r30_865);
        goto loop_2;
    }
    return 0;
}

void DirectedLineEmitter::SetPosition(const MKVector3 &arg0) {
    this->unk28 = M2C_FIELD(&arg0, f64 *, 0);
    this->unk30 = M2C_FIELD(&arg0, f64 *, 8);
}

void DirectedLineEmitter::SetDirection(const MKVector3 &arg0) {
    this->unk18 = M2C_FIELD(&arg0, f64 *, 0);
    this->unk20 = M2C_FIELD(&arg0, f64 *, 8);
}

void DirectedLineEmitter::Init() {
    this->unk38 = 0.0f;
    this->unkA4 = 0.0f;
    this->unkA8 = 0.0f;
    ((KDPathSegment *) &this->unk3C)->Init();
    ((KDPathSegment *) &this->unk3C.unk2C)->Init();
    this->unkA0 = 0;
    this->unk9C = 0;
    this->unk9C = 9;
    this->unk4 = 1.0f;
    this->unk8 = 0.5f;
    this->unkC = 1.0f;
    this->unk10 = 0.5f;
}

void GameParticleEmitter::Deinit() {
    void **temp_r3_998;

    temp_r3_998 = this->unkC8;
    if (temp_r3_998 != NULL) {
        M2C_FIELD(*temp_r3_998, M2C_UNK (**)(), 0x1C)();
        operator delete(this->unkC8);
    }
    GameProp::Deinit();
}

void GameParticleEmitter::Draw() {
    void **temp_r3_1023;

    temp_r3_1023 = this->unkC8;
    if (temp_r3_1023 != NULL) {
        M2C_FIELD(*temp_r3_1023, M2C_UNK (**)(), 0x18)();
    }
}

void GameParticleEmitter::Message(MKMessage *arg0) {
    s32 temp_r0_1043;

    temp_r0_1043 = arg0->unk0;
    switch (temp_r0_1043) {                         /* irregular */
    case 0xB5:
        this->unkE0 = 1;
        break;
    case 0xB4:
        this->unkE0 = 0;
        break;
    }
    GameProp::Message(arg0);
}

void GameParticleEmitter::Update() {
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f64 temp_f0_1088;
    f64 temp_f1_1082;
    u32 temp_r0_1129;
    void **temp_r3_1110;
    void *temp_r3_1081;
    void *temp_r4_1080;

    if ((u8) this->unkE0 != 0) {
        temp_r4_1080 = ((u8 *) this->unk8) + 0x30;
        temp_r3_1081 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
        temp_f1_1082 = M2C_FIELD(temp_r3_1081, f64 *, 0x30);
        sp18 = temp_f1_1082;
        sp20 = M2C_FIELD(temp_r3_1081, f64 *, 0x38);
        temp_f0_1088 = temp_f1_1082 - M2C_FIELD(temp_r4_1080, f64 *, 0);
        sp8 = temp_f0_1088;
        sp28 = temp_f0_1088;
        sp10 = (f32) sp20 - M2C_FIELD(temp_r4_1080, f32 *, 8);
        sp30 = (f64) sp10;
        this->unk24 = ((f32) sp30 * (f32) sp30) + (((f32) sp28 * (f32) sp28) + ((*(f32 *) ((u8 *) &sp28 + 0x4)) * (*(f32 *) ((u8 *) &sp28 + 0x4))));
        if (!(this->unk24 > this->unkE4)) {
            temp_r3_1110 = this->unkC8;
            if (temp_r3_1110 != NULL) {
                M2C_FIELD(*temp_r3_1110, M2C_UNK (**)(), 0x14)();
            }
            this->unkD8 += gUpdateTimeDelta;
            if (this->unkD8 >= this->unkD4) {
                this->unkD8 = 0.0f;
                temp_r0_1129 = this->unkCC;
                switch (temp_r0_1129) {
                case 0:
                    EmitLavaBubble();
                    break;
                case 1:
                    EmitMoltenMetal();
                    break;
                case 2:
                    EmitFoundryGas();
                    break;
                case 3:
                    EmitSparks();
                    break;
                case 4:
                    EmitLavaSteam();
                    break;
                case 5:
                    EmitExplosion();
                    break;
                case 6:
                    EmitHeat();
                    break;
                case 7:
                    EmitWaterfall();
                    break;
                case 8:
                    EmitWaterfallMist();
                    break;
                case 9:
                    EmitWaterDrip();
                    break;
                case 10:
                    EmitDust();
                    break;
                case 11:
                    EmitEmber();
                    break;
                }
            }
            if ((u8) this->unkE1 != 0) {
                this->unkE0 = 0;
            }
        }
    }
}

void GameParticleEmitter::EmitEmber() {
    MKVector3 sp28;
    f32 sp18;
    MKVector3 sp8;
    s32 var_r30_1211;
    void **temp_r3_1215;

    if ((void **) this->unkC8 != NULL) {
        var_r30_1211 = 0;
loop_3:
        if (var_r30_1211 < (s32) this->unkDC) {
            temp_r3_1215 = this->unkC8;
            M2C_FIELD(*temp_r3_1215, M2C_UNK (**)(void **, MKVector3 *, MKVector3 *, f32 *, M2C_UNK), 0x20)(temp_r3_1215, &sp28, &sp8, &sp18, 0);
            ((EmbersPS *) gb.unk74)->Emit(sp28, sp8, sp18, this->unk108, 0.0f);
            var_r30_1211 += 1;
            goto loop_3;
        }
    }
}

void GameParticleEmitter::EmitDust() {
    MKVector3 sp28;
    f32 sp18;
    MKVector3 sp8;
    s32 var_r30_1256;
    void **temp_r3_1260;

    if ((void **) this->unkC8 != NULL) {
        var_r30_1256 = 0;
loop_3:
        if (var_r30_1256 < (s32) this->unkDC) {
            temp_r3_1260 = this->unkC8;
            M2C_FIELD(*temp_r3_1260, M2C_UNK (**)(void **, MKVector3 *, MKVector3 *, f32 *, M2C_UNK), 0x20)(temp_r3_1260, &sp28, &sp8, &sp18, 0);
            gb.EmitDust(sp28, sp8, sp18, 0.0f);
            var_r30_1256 += 1;
            goto loop_3;
        }
    }
}

void GameParticleEmitter::EmitWaterDrip() {
    MKVector3 sp28;
    f32 sp18;
    MKVector3 sp8;
    s32 var_r30_1300;
    void **temp_r3_1304;

    if ((void **) this->unkC8 != NULL) {
        var_r30_1300 = 0;
loop_3:
        if (var_r30_1300 < (s32) this->unkDC) {
            temp_r3_1304 = this->unkC8;
            M2C_FIELD(*temp_r3_1304, M2C_UNK (**)(void **, MKVector3 *, MKVector3 *, f32 *, M2C_UNK), 0x20)(temp_r3_1304, &sp28, &sp8, &sp18, 0);
            ((WaterDripPS *) gb.unk6C)->Emit(sp28, sp8, sp18, 1U, 1U, NULL);
            var_r30_1300 += 1;
            goto loop_3;
        }
    }
}

#if 0 // DRAFT: undefined identifier 'sp30'
void GameParticleEmitter::EmitWaterfallMist() {
    f64 sp28;
    f32 sp18;
    f64 sp8;
    s32 var_r31_1345;
    void **temp_r3_1348;
    void *temp_r3_1357;
    void *temp_r3_1361;
    void *temp_r4_1364;

    if ((void **) this->unkC8 != NULL) {
        var_r31_1345 = 0;
loop_5:
        if (var_r31_1345 < (s32) this->unkDC) {
            temp_r3_1348 = this->unkC8;
            M2C_FIELD(*temp_r3_1348, M2C_UNK (**)(void **, f64 *, f64 *, f32 *, M2C_UNK), 0x20)(temp_r3_1348, &sp28, &sp8, &sp18, 0);
            temp_r3_1357 = this->unk100;
            temp_r3_1361 = M2C_FIELD(M2C_FIELD(temp_r3_1357, void **, 0x44), void *(**)(void *), 0x3C)(temp_r3_1357);
            if (temp_r3_1361 != NULL) {
                temp_r4_1364 = M2C_FIELD(temp_r3_1361, void **, 0x2C);
                M2C_FIELD(temp_r3_1361, f64 *, 0) = sp28;
                M2C_FIELD(temp_r3_1361, f64 *, 8) = sp30;
                M2C_FIELD(temp_r3_1361, f32 *, 0x20) = 0.0f;
                M2C_FIELD(temp_r3_1361, f32 *, 0x28) = 0.0f;
                M2C_FIELD(temp_r3_1361, f32 *, 0x24) = 0.0f;
                M2C_FIELD(temp_r3_1361, f64 *, 0x10) = (f64) M2C_FIELD(this, f64 *, 0x108);
                M2C_FIELD(temp_r3_1361, f64 *, 0x18) = (f64) M2C_FIELD(this, f64 *, 0x110);
                M2C_FIELD(temp_r4_1364, f64 *, 0) = sp8;
                M2C_FIELD(temp_r4_1364, f64 *, 8) = sp10;
                M2C_FIELD(temp_r4_1364, f32 *, 0x18) = sp18;
                M2C_FIELD(temp_r4_1364, f32 *, 0x10) = 0.0f;
                M2C_FIELD(temp_r4_1364, f32 *, 0x14) = (f32) M2C_FIELD(this->unk100, f32 *, 0xF4);
            }
            var_r31_1345 += 1;
            goto loop_5;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'sp30'
void GameParticleEmitter::EmitWaterfall() {
    f64 sp28;
    f32 sp18;
    f64 sp8;
    s32 var_r31_1412;
    void **temp_r3_1415;
    void *temp_r3_1424;
    void *temp_r3_1428;
    void *temp_r4_1431;

    if ((void **) this->unkC8 != NULL) {
        var_r31_1412 = 0;
loop_5:
        if (var_r31_1412 < (s32) this->unkDC) {
            temp_r3_1415 = this->unkC8;
            M2C_FIELD(*temp_r3_1415, M2C_UNK (**)(void **, f64 *, f64 *, f32 *, M2C_UNK), 0x20)(temp_r3_1415, &sp28, &sp8, &sp18, 0);
            temp_r3_1424 = this->unkFC;
            temp_r3_1428 = M2C_FIELD(M2C_FIELD(temp_r3_1424, void **, 0x44), void *(**)(void *), 0x3C)(temp_r3_1424);
            if (temp_r3_1428 != NULL) {
                temp_r4_1431 = M2C_FIELD(temp_r3_1428, void **, 0x2C);
                M2C_FIELD(temp_r3_1428, f64 *, 0) = sp28;
                M2C_FIELD(temp_r3_1428, f64 *, 8) = sp30;
                M2C_FIELD(temp_r3_1428, f32 *, 0x20) = 0.0f;
                M2C_FIELD(temp_r3_1428, f32 *, 0x28) = 0.0f;
                M2C_FIELD(temp_r3_1428, f32 *, 0x24) = 0.0f;
                M2C_FIELD(temp_r3_1428, f64 *, 0x10) = (f64) M2C_FIELD(this, f64 *, 0x108);
                M2C_FIELD(temp_r3_1428, f64 *, 0x18) = (f64) M2C_FIELD(this, f64 *, 0x110);
                M2C_FIELD(temp_r4_1431, f64 *, 0) = sp8;
                M2C_FIELD(temp_r4_1431, f64 *, 8) = sp10;
                M2C_FIELD(temp_r4_1431, f32 *, 0x18) = sp18;
                M2C_FIELD(temp_r4_1431, f32 *, 0x10) = 0.0f;
                M2C_FIELD(temp_r4_1431, f32 *, 0x14) = (f32) M2C_FIELD(this->unkFC, f32 *, 0xF4);
            }
            var_r31_1412 += 1;
            goto loop_5;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk240'
void GameParticleEmitter::EmitHeat() {
    MKVector3 sp58;
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
    f32 temp_f1_1502;
    f64 temp_f0_1512;
    s32 var_r30_1486;
    void **temp_r3_1490;

    if ((void **) this->unkC8 != NULL) {
        var_r30_1486 = 0;
loop_3:
        if (var_r30_1486 < (s32) this->unkDC) {
            temp_r3_1490 = this->unkC8;
            M2C_FIELD(*temp_r3_1490, M2C_UNK (**)(void **, MKVector3 *, M2C_UNK, f32 *, M2C_UNK), 0x20)(temp_r3_1490, &sp58, 0, &sp48, 0);
            temp_f1_1502 = MKRand_Float((int *) &gViewSeed, 1.0f, 1.5f);
            sp18 = 0.0f;
            sp1C = temp_f1_1502;
            sp20 = 0.0f;
            sp28 = (f64) sp18;
            sp30 = (f64) sp20;
            temp_f0_1512 = sp28 * 5.61841903e-315;
            sp8 = temp_f0_1512;
            sp38 = temp_f0_1512;
            sp10 = (f32) sp30 * 400.0f;
            sp40 = (f64) sp10;
            gb.unk240.Emit(sp58, *((MKVector3 *) &sp38), sp48, 1.0f);
            var_r30_1486 += 1;
            goto loop_3;
        }
    }
}
#endif

void GameParticleEmitter::EmitExplosion() {
    MKVector3 sp20;
    f32 sp10;
    s32 sp8;
    s32 var_r30_1555;
    void **temp_r3_1559;

    if ((void **) this->unkC8 != NULL) {
        var_r30_1555 = 0;
loop_3:
        if (var_r30_1555 < (s32) this->unkDC) {
            temp_r3_1559 = this->unkC8;
            M2C_FIELD(*temp_r3_1559, M2C_UNK (**)(void **, MKVector3 *, M2C_UNK, f32 *, M2C_UNK), 0x20)(temp_r3_1559, &sp20, 0, &sp10, 0);
            sp8 = 1;
            this->unkF8->Trigger(sp20, sp10, 0U, NULL, 5, 1U, 1U, 1U, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
            var_r30_1555 += 1;
            goto loop_3;
        }
    }
}

void GameParticleEmitter::EmitLavaSteam() {
    MKVector3 sp28;
    f32 sp18;
    MKVector3 sp8;
    s32 var_r31_1603;
    void **temp_r3_1606;

    if ((void **) this->unkC8 != NULL) {
        var_r31_1603 = 0;
loop_3:
        if (var_r31_1603 < (s32) this->unkDC) {
            temp_r3_1606 = this->unkC8;
            M2C_FIELD(*temp_r3_1606, M2C_UNK (**)(void **, MKVector3 *, MKVector3 *, f32 *, M2C_UNK), 0x20)(temp_r3_1606, &sp28, &sp8, &sp18, 0);
            this->unkF4->Emit(sp28, sp8, sp18);
            var_r31_1603 += 1;
            goto loop_3;
        }
    }
}

void GameParticleEmitter::EmitSparks() {
    MKVector3 sp28;
    f32 sp18;
    MKVector3 sp8;
    s32 var_r31_1644;
    void **temp_r3_1647;

    if ((void **) this->unkC8 != NULL) {
        var_r31_1644 = 0;
loop_3:
        if (var_r31_1644 < (s32) this->unkDC) {
            temp_r3_1647 = this->unkC8;
            M2C_FIELD(*temp_r3_1647, M2C_UNK (**)(void **, MKVector3 *, MKVector3 *, f32 *, M2C_UNK), 0x20)(temp_r3_1647, &sp28, &sp8, &sp18, 0);
            this->unkF0->Emit(sp28, sp8, sp18);
            var_r31_1644 += 1;
            goto loop_3;
        }
    }
}

void GameParticleEmitter::EmitFoundryGas() {
    MKVector3 sp28;
    f32 sp18;
    MKVector3 sp8;
    s32 var_r31_1685;
    void **temp_r3_1688;

    if ((void **) this->unkC8 != NULL) {
        var_r31_1685 = 0;
loop_3:
        if (var_r31_1685 < (s32) this->unkDC) {
            temp_r3_1688 = this->unkC8;
            M2C_FIELD(*temp_r3_1688, M2C_UNK (**)(void **, MKVector3 *, MKVector3 *, f32 *, M2C_UNK), 0x20)(temp_r3_1688, &sp28, &sp8, &sp18, 0);
            this->unkEC->Emit(sp28, sp8, sp18);
            var_r31_1685 += 1;
            goto loop_3;
        }
    }
}

void GameParticleEmitter::EmitMoltenMetal() {
    MKVector3 sp30;
    MKVector3 sp20;
    MKVector3 sp10;
    s32 spC;
    s32 sp8;
    s32 var_r31_1726;
    void **temp_r3_1729;

    if ((void **) this->unkC8 != NULL) {
        var_r31_1726 = 0;
loop_3:
        if (var_r31_1726 < (s32) this->unkDC) {
            temp_r3_1729 = this->unkC8;
            M2C_FIELD(*temp_r3_1729, M2C_UNK (**)(void **, MKVector3 *, MKVector3 *, MKVector3 *, M2C_UNK), 0x20)(temp_r3_1729, &sp30, &sp10, &sp20, 0);
            sp8 = 0;
            spC = 0;
            this->unkE8->Emit(lit_717, sp30, sp10, sp20, 3.0f, 0.0f, 0U, NULL, M2C_ERROR(/* Unable to find stack arg 0x0 in block */), M2C_ERROR(/* Unable to find stack arg 0x4 in block */));
            var_r31_1726 += 1;
            goto loop_3;
        }
    }
}

void GameParticleEmitter::EmitLavaBubble() {
    MKVector3 sp18;
    MKVector3 sp8;
    s32 var_r30_1776;
    void **temp_r3_1780;

    if ((void **) this->unkC8 != NULL) {
        var_r30_1776 = 0;
loop_3:
        if (var_r30_1776 < (s32) this->unkDC) {
            temp_r3_1780 = this->unkC8;
            M2C_FIELD(*temp_r3_1780, M2C_UNK (**)(void **, MKVector3 *, M2C_UNK, MKVector3 *, M2C_UNK), 0x20)(temp_r3_1780, &sp18, 0, &sp8, 0);
            ((LavaBubbleFX *) gb.unk90)->CreateBubble(sp18, sp8);
            var_r30_1776 += 1;
            goto loop_3;
        }
    }
}

void GameParticleEmitter::LoadDone() {
    f32 temp_f0_1821;
    u32 temp_r0_1846;
    void **temp_r3_1824;
    void **temp_r3_1831;
    void **temp_r3_1838;

    GameProp::LoadDone();
    M2C_FIELD(this, f64 *, 0x108) = (f64) M2C_FIELD(&MKProp::loadInfo, f64 *, 0x70);
    M2C_FIELD(this, f64 *, 0x110) = (f64) M2C_FIELD(&MKProp::loadInfo, f64 *, 0x78);
    temp_f0_1821 = this->unkE4;
    this->unkE4 = temp_f0_1821 * temp_f0_1821;
    temp_r3_1824 = this->unkC8;
    if (temp_r3_1824 != NULL) {
        M2C_FIELD(*temp_r3_1824, M2C_UNK (**)(), 0x10)();
        temp_r3_1831 = this->unkC8;
        M2C_FIELD(*temp_r3_1831, M2C_UNK (**)(void **, void *), 0x28)(temp_r3_1831, ((u8 *) this->unk8) + 0x30);
        temp_r3_1838 = this->unkC8;
        M2C_FIELD(*temp_r3_1838, M2C_UNK (**)(void **, void *), 0x24)(temp_r3_1838, ((u8 *) this->unk8) + 0x20);
    }
    temp_r0_1846 = this->unkCC;
    switch (temp_r0_1846) {
    case 1:
        this->unkE8 = checked_cast<LiquidFX *, MKProp>(gMK->CreateProp("MoltenMetalFX"));
        return;
    case 2:
        this->unkEC = checked_cast<FoundryGas *, MKProp>(gMK->CreateProp("FoundryGas"));
        return;
    case 3:
        this->unkF0 = checked_cast<SparksPS *, MKProp>(gMK->CreateProp("SparksPS"));
        return;
    case 4:
        this->unkF4 = checked_cast<LavaSteamPS *, MKProp>(gMK->CreateProp("LavaSteamPS"));
        return;
    case 5:
        this->unkF8 = checked_cast<Explosion4 *, MKProp>(gMK->CreateProp("Explosion4"));
        return;
    case 7:
        this->unkFC = checked_cast<KDEnvParticleSystem *, MKProp>(gMK->CreateProp("WaterFallPS"));
        return;
    case 8:
        this->unk100 = checked_cast<KDEnvParticleSystem *, MKProp>(gMK->CreateProp("WaterfallMistPS"));
        /* fallthrough */
    default:
        return;
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to
s32 GameParticleEmitter::LoadLine(MKIniLine *arg0) {
    MKIniLine *var_r29_2006;
    s32 temp_r0_2019;
    void **temp_r3_2042;
    void **temp_r3_2047;
    void **temp_r3_2069;
    void **temp_r3_2074;

    if ((GameProp::LoadLine(arg0) != 0) || (arg0->LoadInt("ParticleType", (int *) &this->unkCC, 0) != 0) || (arg0->LoadFloat("EmitRate", &this->unkD4, 0) != 0) || (arg0->LoadInt("NumPerEmit", (int *) &this->unkDC, 0) != 0) || (arg0->LoadBool("StartEnabled", &this->unkE0, 0) != 0) || (arg0->LoadBool("OneShot", &this->unkE1, 0) != 0) || (arg0->LoadFloat("UpdateDist", &this->unkE4, 0) != 0)) {
        return 1;
    }
    if (arg0->IsField("EmitterProperty") != 0) {
        var_r29_2006 = arg0->unkC->GetSubLine(arg0);
loop_23:
        if (var_r29_2006 != NULL) {
            if (var_r29_2006->IsField("EmissionType") != 0) {
                var_r29_2006->AsInt(0, (int *) &this->unkD0);
                temp_r0_2019 = this->unkD0;
                switch (temp_r0_2019) {             /* irregular */
                case 0:
                    operator new(0x48U, NULL, 0);
                    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
                        *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
                        *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
                    }
                    this->unkC8 = M2C_ERROR(/* Read from unset register $r3 */);
                    temp_r3_2042 = this->unkC8;
                    M2C_FIELD(*temp_r3_2042, M2C_UNK (**)(void **), 8)(temp_r3_2042);
                    temp_r3_2047 = this->unkC8;
                    M2C_FIELD(*temp_r3_2047, M2C_UNK (**)(void **, MKIniLine *), 0xC)(temp_r3_2047, var_r29_2006);
                    break;
                case 1:
                    operator new(0xB0U, NULL, 0);
                    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
                        *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
                        *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
                    }
                    this->unkC8 = M2C_ERROR(/* Read from unset register $r3 */);
                    temp_r3_2069 = this->unkC8;
                    M2C_FIELD(*temp_r3_2069, M2C_UNK (**)(void **), 8)(temp_r3_2069);
                    temp_r3_2074 = this->unkC8;
                    M2C_FIELD(*temp_r3_2074, M2C_UNK (**)(void **, MKIniLine *), 0xC)(temp_r3_2074, var_r29_2006);
                    break;
                }
            }
            var_r29_2006 = var_r29_2006->unkC->GetNextLine(var_r29_2006);
            goto loop_23;
        }
        return 1;
    }
    return 0;
}
#endif

void GameParticleEmitter::Init() {
    GameProp::Init();
    this->unkC8 = NULL;
    this->unkCC = 0xC;
    this->unkD0 = 2;
    this->unkD4 = 0.0f;
    this->unkD8 = 0.0f;
    this->unkE8 = NULL;
    this->unkEC = NULL;
    this->unkF0 = NULL;
    this->unkF4 = NULL;
    this->unkF8 = NULL;
    this->unkFC = NULL;
    this->unk100 = NULL;
    this->unkE1 = 0;
    this->unkE0 = 1;
    this->unkE4 = 10000.0f;
}
