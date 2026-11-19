#include "spyro/source/KDParticleEmitter.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/KDPath.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

f64 acos();                                         /* extern */
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;

#if 0 // DRAFT: undefined identifier '__vptr'
void KDParticleBoxEmitter::InitBoxParticlePostion(KDParticleEmitter *arg0, MKParticle *arg1) {
    void *temp_r3_40;

    temp_r3_40 = checked_cast<KDParticleBoxEmitter *, KDParticleEmitter>((KDParticleEmitter *) this);
    M2C_FIELD(arg0, f64 *, 0) = (f64) M2C_FIELD(temp_r3_40, f64 *, 0x78);
    arg0->unk8 = M2C_FIELD(temp_r3_40, f64 *, 0x80);
    arg0->__vptr = (M2C_FIELD(temp_r3_40, f32 *, 0x88) * MKRand_Float(&gViewSeed, 0.0f, 1.0f)) + M2C_BITWISE(f32, arg0->__vptr);
    arg0->unk4 += M2C_FIELD(temp_r3_40, f32 *, 0x8C) * MKRand_Float(&gViewSeed, 0.0f, 1.0f);
    M2C_FIELD(arg0, f64 *, 8) = (f32) ((M2C_FIELD(temp_r3_40, f32 *, 0x90) * MKRand_Float(&gViewSeed, 0.0f, 1.0f)) + (f32) M2C_FIELD(arg0, f64 *, 8));
}
#endif

#if 0 // DRAFT: undefined identifier 'unk44'
void KDParticleBoxEmitter::Init() {
    KDParticleEmitter::Init();
    this->unk44 = &KDParticleBoxEmitter::InitBoxParticlePostion;
}
#endif

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void KDParticleLineEmitter::InitLineParticlePostion(KDParticleEmitter *arg0, MKParticle *arg1) {
    void *temp_r31_106;

    temp_r31_106 = checked_cast<KDParticleLineEmitter *, KDParticleEmitter>((KDParticleEmitter *) this);
    ((KDPathSegment *) (M2C_FIELD(temp_r31_106, KDPathSegment **, 0x78)))->GetPositionAlongPath(MKRand_Float(&gViewSeed, 0.0f, 1.0f), *((MKVector3 *) arg0));
}
#endif

#if 0 // DRAFT: undefined identifier 'unk44'
void KDParticleLineEmitter::Init() {
    KDParticleEmitter::Init();
    this->unk78 = 0;
    this->unk44 = &KDParticleLineEmitter::InitLineParticlePostion;
}
#endif

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void KDParticleEmitter::InitPointParticleParameters(KDParticleEmitter *arg0, MKParticle *arg1) {
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Matrix *temp_r3_176;
    f32 temp_f0_303;
    f32 temp_f1_178;
    f32 temp_f29_274;
    f32 temp_f2_177;
    f32 temp_f2_287;
    f32 temp_f30_269;
    f32 temp_f31_263;
    f32 temp_f3_180;
    f32 var_f4_184;
    f64 temp_f1_187;
    f64 temp_f1_193;
    f64 temp_f1_197;
    f64 temp_f31_247;
    s32 temp_r3_216;
    s32 var_r0_226;
    void *temp_r31_164;

    arg0->unk24 = MKRand_Float(&gViewSeed, this->unk58, this->unk54);
    temp_r31_164 = arg0->unk2C;
    M2C_FIELD(temp_r31_164, f32 *, 0x14) = (f32) this->unk28->unkF4;
    M2C_FIELD(temp_r31_164, f32 *, 0) = 0.0f;
    M2C_FIELD(temp_r31_164, f32 *, 4) = 0.0f;
    M2C_FIELD(temp_r31_164, f32 *, 8) = 0.0f;
    M2C_FIELD(temp_r31_164, f32 *, 0x10) = 0.0f;
    M2C_FIELD(temp_r31_164, f32 *, 0x10) = MKRand_Float(&gViewSeed, this->unk60, this->unk5C);
    temp_r3_176 = this->unk70;
    temp_f2_177 = temp_r3_176->unk0;
    temp_f1_178 = temp_r3_176->unk4;
    temp_f3_180 = temp_r3_176->unk8;
    var_f4_184 = (temp_f3_180 * temp_f3_180) + ((temp_f2_177 * temp_f2_177) + (temp_f1_178 * temp_f1_178));
    if (var_f4_184 > 0.0f) {
        temp_f1_187 = __frsqrte(var_f4_184);
        temp_f1_193 = 0.5 * temp_f1_187 * -(((f64) var_f4_184 * (temp_f1_187 * temp_f1_187)) - 3.0);
        temp_f1_197 = 0.5 * temp_f1_193 * -(((f64) var_f4_184 * (temp_f1_193 * temp_f1_193)) - 3.0);
        var_f4_184 = (f32) ((f64) var_f4_184 * (0.5 * temp_f1_197 * -(((f64) var_f4_184 * (temp_f1_197 * temp_f1_197)) - 3.0)));
    } else if (var_f4_184 < M2C_BITWISE(f32, 0.0)) {
        var_f4_184 = __float_nan;
    } else {
        sp8 = var_f4_184;
        temp_r3_216 = M2C_BITWISE(s32, sp8) & 0x7F800000;
        switch (temp_r3_216) {                      /* irregular */
        case 0x7F800000:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_226 = 1;
            } else {
                var_r0_226 = 2;
            }
            break;
        case 0x0:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_226 = 5;
            } else {
                var_r0_226 = 3;
            }
            break;
        default:
            var_r0_226 = 4;
            break;
        }
        if (var_r0_226 == 1) {
            var_f4_184 = __float_nan;
        }
    }
    temp_f31_247 = fabs(var_f4_184);
    M2C_FIELD(temp_r31_164, f32 *, 0x18) = (f32) ((f32) temp_f31_247 * MKRand_Float(&gViewSeed, this->unk68, this->unk64));
    if (this->unk38 > 0.0f) {
        temp_f31_263 = MKRand_Float(&gViewSeed, -3.1415927f, 3.1415927f);
        MKRand_Float(&gViewSeed, this->unk3C, 1.0f);
        temp_f30_269 = (f32) acos();
        temp_f29_274 = -MKRand_Float(&gViewSeed, this->unk50, this->unk4C);
        _table_sincosf(temp_f30_269, sp18, sp14);
        _table_sincosf(temp_f31_263, sp10, spC);
        temp_f2_287 = sp18 * temp_f29_274;
        M2C_FIELD(temp_r31_164, f32 *, 8) = (f32) (sp14 * temp_f29_274);
        M2C_FIELD(temp_r31_164, f32 *, 4) = (f32) (sp10 * temp_f2_287);
        M2C_FIELD(temp_r31_164, f32 *, 0) = (f32) (spC * temp_f2_287);
        M2C_FIELD(temp_r31_164, f32 *, 0xC) = 0.0f;
        return;
    }
    temp_f0_303 = -MKRand_Float(&gViewSeed, this->unk50, this->unk4C);
    M2C_FIELD(temp_r31_164, f32 *, 0) = 0.0f;
    M2C_FIELD(temp_r31_164, f32 *, 4) = 0.0f;
    M2C_FIELD(temp_r31_164, f32 *, 8) = temp_f0_303;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void KDParticleEmitter::InitPointParticlePosition(KDParticleEmitter *arg0, MKParticle *arg1) {
    arg0->__vptr = 0.0f;
    arg0->unk4 = 0.0f;
    M2C_FIELD(arg0, f32 *, 8) = 0.0f;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void KDParticleEmitter::Emit(int arg0, MKVector3 *arg1) {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    KDParticleEmitter *temp_r3_344;
    MKBaseParticleSystem *temp_r3_444;
    Matrix *temp_r3_363;
    Matrix *temp_r3_403;
    f32 temp_f1_440;
    f32 temp_f2_423;
    f32 temp_f3_366;
    f32 temp_f3_404;
    f32 temp_f3_420;
    f32 temp_f4_421;
    f32 temp_f5_419;
    f32 temp_f6_370;
    f32 temp_f6_409;
    f32 temp_f7_379;
    f32 temp_f7_418;
    f64 *temp_r3_432;
    s32 temp_cr0_eq_455;
    s32 var_r29_339;
    void (*temp_r12_347)(KDParticleEmitter *, KDParticleEmitter *, MKParticle *);
    void (*temp_r12_355)(KDParticleEmitter *, KDParticleEmitter *, MKParticle *);
    void *temp_r4_364;

    var_r29_339 = arg0;
loop_7:
    temp_cr0_eq_455 = var_r29_339 == 0;
    var_r29_339 -= 1;
    if (temp_cr0_eq_455 == 0) {
        temp_r3_344 = this->unk28->AllocateParticle();
        if (temp_r3_344 != NULL) {
            temp_r12_347 = this->unk44;
            if (temp_r12_347 != NULL) {
                temp_r12_347(this, temp_r3_344, M2C_ERROR(/* Read from unset register $r5 */));
            }
            temp_r12_355 = this->unk48;
            if (temp_r12_355 != NULL) {
                temp_r12_355(this, temp_r3_344, M2C_ERROR(/* Read from unset register $r5 */));
            }
            temp_r3_363 = this->unk70;
            temp_r4_364 = temp_r3_344->unk2C;
            temp_f3_366 = M2C_FIELD(temp_r4_364, f32 *, 4);
            temp_f6_370 = M2C_FIELD(temp_r4_364, f32 *, 0);
            temp_f7_379 = M2C_FIELD(temp_r4_364, f32 *, 8);
            sp18 = (temp_f7_379 * temp_r3_363->unk20) + ((temp_f6_370 * temp_r3_363->unk0) + (temp_f3_366 * temp_r3_363->unk10));
            sp1C = (temp_f7_379 * temp_r3_363->unk24) + ((temp_f6_370 * temp_r3_363->unk4) + (temp_f3_366 * temp_r3_363->unk14));
            sp20 = (temp_f7_379 * temp_r3_363->unk28) + ((temp_f6_370 * temp_r3_363->unk8) + (temp_f3_366 * temp_r3_363->unk18));
            M2C_FIELD(temp_r4_364, f32 *, 0) = (f64) sp18;
            M2C_FIELD(temp_r4_364, f32 *, 8) = (f64) sp20;
            sp38 = (f64) sp18;
            sp40 = (f64) sp20;
            M2C_FIELD(temp_r4_364, f32 *, 0) = (f64) ((f64) M2C_FIELD(temp_r4_364, f32 *, 0) + M2C_FIELD(arg1, f64 *, 0));
            M2C_FIELD(temp_r4_364, f32 *, 8) = (f32) (M2C_FIELD(temp_r4_364, f32 *, 8) + arg1->unk8);
            temp_r3_403 = this->unk70;
            temp_f3_404 = temp_r3_344->unk4;
            temp_f6_409 = M2C_BITWISE(f32, temp_r3_344->__vptr);
            temp_f7_418 = M2C_FIELD(temp_r3_344, f32 *, 8);
            temp_f5_419 = temp_r3_403->unk20;
            temp_f3_420 = temp_r3_403->unk24;
            temp_f4_421 = (temp_f7_418 * temp_f5_419) + ((temp_f6_409 * temp_r3_403->unk0) + (temp_f3_404 * temp_r3_403->unk10));
            temp_f2_423 = (temp_f7_418 * temp_f3_420) + ((temp_f6_409 * temp_r3_403->unk4) + (temp_f3_404 * temp_r3_403->unk14));
            sp8 = temp_f4_421;
            spC = temp_f2_423;
            sp10 = (temp_f7_418 * temp_r3_403->unk28) + ((temp_f6_409 * temp_r3_403->unk8) + (temp_f3_404 * temp_r3_403->unk18));
            M2C_FIELD(temp_r3_344, void **, 0) = (f64) sp8;
            temp_r3_344->unk8 = (f64) sp10;
            temp_r3_432 = this->unk6C;
            sp28 = (f64) sp8;
            sp30 = (f64) sp10;
            M2C_FIELD(temp_r3_344, void **, 0) = (f64) (M2C_BITWISE(f64, M2C_FIELD(temp_r3_344, void **, 0)) + M2C_FIELD(temp_r3_432, f64 *, 0));
            temp_f1_440 = M2C_FIELD(temp_r3_344, f32 *, 8);
            M2C_FIELD(temp_r3_344, f32 *, 8) = (f32) (temp_f1_440 + M2C_FIELD(temp_r3_432, f32 *, 8));
            temp_r3_444 = this->unk28;
            temp_r3_444->unkF0(temp_r3_444, temp_r3_344, temp_f1_440, temp_f2_423, temp_f3_420, temp_f4_421, temp_f5_419, temp_f6_409, temp_f7_418);
            temp_r3_344->unk10 = M2C_FIELD(this, f32 *, 8);
            temp_r3_344->unk14 = M2C_FIELD(this, f32 *, 0xC);
            M2C_FIELD(temp_r3_344, f32 *, 0x18) = (f32) this->unk10;
            goto loop_7;
        }
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'void *' to
void KDParticleEmitter::Burst() {
    f32 sp10;
    f32 spC;
    f32 sp8;

    sp8 = 0.0f;
    spC = 0.0f;
    sp10 = 0.0f;
    Emit((s32) M2C_BITWISE(f32, this->unk2C), (MKVector3 *) &sp8);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'void *' to
void KDParticleEmitter::Update() {
    f64 sp50;                                       /* compiler-managed */
    f64 sp48;                                       /* compiler-managed */
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f2_506;
    f32 temp_f4_518;
    f64 *temp_r3_510;
    f64 *temp_r4_545;
    s32 temp_r31_562;

    if (((u8) this->unk40 == 0) && ((MKBaseParticleSystem *) this->unk28 == NULL)) {
        this->unk30 = 0.0f;
        return;
    }
    temp_f2_506 = this->unk34;
    if (temp_f2_506 > 0.0f) {
        temp_r3_510 = this->unk6C;
        sp8 = M2C_FIELD(temp_r3_510, f64 *, 0) - this->unk18;
        temp_f4_518 = 1.0f / temp_f2_506;
        sp28 = sp8;
        sp10 = M2C_FIELD(temp_r3_510, f32 *, 8) - this->unk20;
        sp30 = (f64) sp10;
        sp18 = sp28 * (f64) temp_f4_518;
        sp38 = sp18;
        sp20 = (f32) sp30 * temp_f4_518;
        sp48 = sp18;
        sp40 = (f64) sp20;
        sp50 = (f64) sp20;
    } else {
        sp48 = 0.0f;
        (*(f32 *) ((u8 *) &sp40 + 0xc)) = 0.0f;
        sp50 = 0.0f;
    }
    temp_r4_545 = this->unk6C;
    this->unk18 = M2C_FIELD(temp_r4_545, f64 *, 0);
    M2C_FIELD(this, f32 *, 0x20) = (f64) M2C_FIELD(temp_r4_545, f32 *, 8);
    this->unk34 = gUpdateTimeDelta;
    this->unk30 += M2C_BITWISE(f32, this->unk2C) * gUpdateTimeDelta;
    temp_r31_562 = (s32) this->unk30;
    Emit(temp_r31_562, (MKVector3 *) &sp48);
    this->unk30 -= (f32) temp_r31_562;
}
#endif

void KDParticleEmitter::LoadDone() {
    this->unk3C = _table_sinf(1.5707964f + this->unk38);
}

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to
s32 KDParticleEmitter::LoadLine(MKIniLine *arg0) {
    s32 var_r31_615;

    var_r31_615 = 0;
    if ((arg0->LoadBool("active", &this->unk40, 0) != 0) || (arg0->LoadFloat("rate", (f32 *) &this->unk2C, 0) != 0) || (arg0->LoadFloat("angle", &this->unk38, 0) != 0) || (arg0->LoadFloat("minScale", &this->unk68, 0) != 0) || (arg0->LoadFloat("maxScale", &this->unk64, 0) != 0) || (arg0->LoadFloat("minVel", &this->unk50, 0) != 0) || (arg0->LoadFloat("maxVel", &this->unk4C, 0) != 0) || (arg0->LoadFloat("minRot", &this->unk58, 0) != 0) || (arg0->LoadFloat("maxRot", &this->unk54, 0) != 0) || (arg0->LoadFloat("minRotVel", &this->unk60, 0) != 0) || (arg0->LoadFloat("maxRotVel", &this->unk5C, 0) != 0)) {
        var_r31_615 = 1;
    }
    return var_r31_615;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'float' to
void KDParticleEmitter::Init() {
    this->unk28 = NULL;
    this->unk40 = 1;
    this->unk2C = 0.0f;
    this->unk30 = 0.0f;
    this->unk38 = 0.0f;
    this->unk3C = 1.0f;
    this->unk4C = 0.0f;
    this->unk50 = 0.0f;
    this->unk54 = 3.1415927f;
    this->unk58 = -3.1415927f;
    this->unk5C = 0.0f;
    this->unk60 = 0.0f;
    this->unk64 = 1.0f;
    this->unk68 = 1.0f;
    this->unk18 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x20) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unk34 = 0.0f;
    this->unk70 = &Matrix::identity;
    this->unk6C = (f64 *) &MKVector3::zero;
    M2C_FIELD(this, f32 *, 8) = 1.0f;
    M2C_FIELD(this, f32 *, 0xC) = 1.0f;
    this->unk10 = 1.0f;
    this->unk14 = 1.0f;
    this->unk44 = &KDParticleEmitter::InitPointParticlePosition;
    this->unk48 = &KDParticleEmitter::InitPointParticleParameters;
}
#endif
