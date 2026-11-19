#include "spyro/source/Collectable2.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Coronas.h"
#include "spyro/source/FlyingChunkPS.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKModel_GC.h"
#include <m2c_macros.h>

extern f32 *KDSpline_PositionMixer;
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern void **gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;

static s32 lit_778 = 0;
static u8 lit_779 = 0;

void Collectable2Descriptor::Init() {
    MKPropDescriptor::Init();
    this->unkC = 2;
}

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void Collectable2::Collect() {
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    Corona *temp_r4_44;
    MKVector3 *temp_r30_104;
    f32 temp_f27_111;
    f32 temp_f27_138;
    f32 temp_f27_170;
    f32 temp_f27_77;
    f32 temp_f28_106;
    f32 temp_f28_143;
    f32 temp_f28_72;
    s32 var_r29_65;

    temp_r4_44 = this->unk74;
    if (temp_r4_44 != NULL) {
        temp_r4_44->unk31 &= ~0x40;
        ((Coronas *) (M2C_FIELD(&gb, Coronas **, 0x64)))->Free(this->unk74);
        this->unk74 = NULL;
    }
    Disable();
    var_r29_65 = 0;
    do {
        temp_f28_72 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        temp_f27_77 = MKRand_Float(&gViewSeed, 1.0f, 3.0f);
        sp58 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        sp5C = temp_f27_77;
        sp60 = temp_f28_72;
        spA8 = (f64) sp58;
        spB0 = (f64) sp60;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        spB8 = sp48;
        sp50 = (f32) spB0 * 600.0f;
        spC0 = (f64) sp50;
        temp_r30_104 = this->unk8 + 0x30;
        temp_f28_106 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        temp_f27_111 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        sp38 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        sp3C = temp_f27_111;
        sp40 = temp_f28_106;
        sp88 = (f64) sp38;
        sp90 = (f64) sp40;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
        sp98 = sp28;
        sp30 = (f32) sp90 * 3.1415927f;
        spA0 = (f64) sp30;
        temp_f27_138 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        temp_f28_143 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        sp18 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        sp1C = temp_f28_143;
        sp20 = temp_f27_138;
        sp68 = (f64) sp18;
        sp70 = (f64) sp20;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
        sp78 = sp8;
        sp10 = (f32) sp70 * 3.1415927f;
        sp80 = (f64) sp10;
        temp_f27_170 = MKRand_Float(&gViewSeed, 3.0f, 5.0f);
        ((FlyingChunkPS *) (M2C_FIELD(&gb, FlyingChunkPS **, 0x9C)))->Emit(*temp_r30_104, *((MKVector3 *) &spB8), *((MKVector3 *) &sp98), *((MKVector3 *) &sp78), temp_f27_170, *(MKModel_GetColor(this->unk4)), 0, NULL);
        var_r29_65 += 1;
    } while (var_r29_65 < 4);
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp8C'
void Collectable2::InitData(const Matrix &arg0, const MKVector3 *arg1, const MKVector3 *arg2, float arg3, float arg4, float arg5) {
    Corona *temp_r4_286;
    M2C_STRUCT_COPY((s32) &arg_sp8C + 4, (s32) (&arg0 - 4) + 4, 0x40);
    arg_sp90.Scale3x3((Matrix *) &arg_sp90, 2.0f);
    arg_sp50.SetRotateAroundAxis(*((MKVector3 *) &arg0), arg5);
    arg_sp90.Multiply3x3((Matrix *) &arg_sp90, (Matrix *) &arg_sp50);
    MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &arg_sp90));
    this->unk64 = arg1;
    this->unk68 = arg2;
    this->unk6C = arg3;
    this->unk70 = arg4;
    this->unk60 = 0.0f;
    if ((Corona *) this->unk74 == NULL) {
        arg_sp28 = 0.0f;
        arg_sp10 = 1.0f;
        arg_sp14 = 1.0f;
        arg_sp18 = 1.0f;
        arg_sp1C = 1.0f;
        arg_sp20 = 0.0f;
        arg_sp24 = 0.0f;
        arg_sp30 = (f64) arg_sp10;
        arg_sp38 = (f64) arg_sp18;
        arg_sp40 = (f64) arg_sp20;
        arg_sp48 = (f64) arg_sp28;
        this->unk74 = ((Coronas *) (M2C_FIELD(&gb, Coronas **, 0x64)))->Alloc(*((MKVector3 *) &arg_sp40), *((MKVector4 *) &arg_sp30), 0.5f, lit_778, lit_779);
        temp_r4_286 = this->unk74;
        if (temp_r4_286 != NULL) {
            temp_r4_286->unk31 |= 0x40;
        }
        this->unk78 = 0.0f;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'sWorkingChunkID'
void Collectable2::Message(MKMessage *arg0) {
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 temp_f4_347;
    f64 temp_f2_344;
    f64 temp_f3_342;
    void *temp_r3_336;
    void *temp_r3_341;
    void *temp_r4_340;

    MKProp::Message(arg0);
    if ((s32) arg0->unk0 != 9) {
        return;
    }
    if (M2C_FIELD(*gMK, u8 (**)(void **, Collectable2 *, s32), 0x9C)(gMK, this, sWorkingChunkID.unk0) != 0) {
        temp_r3_336 = checked_cast<CollectRequestMsg *, MKMessage>(arg0);
        temp_r4_340 = M2C_FIELD(checked_cast<MKProp *, MKProp>(M2C_FIELD(temp_r3_336, MKProp **, 0xC)), void **, 8);
        temp_r3_341 = this->unk8;
        temp_f3_342 = M2C_FIELD(temp_r4_340, f64 *, 0x30);
        temp_f2_344 = M2C_FIELD(temp_r4_340, f64 *, 0x38);
        sp58 = temp_f3_342;
        temp_f4_347 = M2C_FIELD(temp_r3_336, f32 *, 0x18);
        sp38 = M2C_FIELD(temp_r3_341, f64 *, 0x30);
        sp48 = temp_f3_342;
        sp50 = temp_f2_344;
        sp60 = temp_f2_344;
        sp40 = M2C_FIELD(temp_r3_341, f64 *, 0x38);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp18 = sp8;
        sp10 = (f32) sp60 - (f32) sp40;
        sp28 = sp8;
        sp20 = (f64) sp10;
        sp30 = (f64) sp10;
        if ((((f32) sp20 * (f32) sp20) + (((f32) sp18 * (f32) sp18) + (unksp1C * unksp1C))) < (temp_f4_347 * temp_f4_347)) {
            gameData.unkA0.Add(2.0f, 1U);
        }
    }
}
#endif

void Collectable2::Draw() {
    MKProp::Draw();
    MKModel_Draw(this->unk4, NULL);
}

#if 0 // DRAFT: undefined identifier 'arg_sp24C'
void Collectable2::Update() {
    Corona *temp_r3_738;
    Corona *temp_r4_605;
    f32 temp_f29_567;
    f32 temp_f29_581;
    f32 var_f4_646;
    f32 var_f4_713;
    f64 temp_f1_652;
    f64 temp_f1_658;
    f64 temp_f1_662;
    s32 temp_r3_681;
    s32 temp_r4_432;
    s32 var_r0_691;
    void *temp_r3_447;
    void *temp_r3_618;
    void *temp_r4_615;
    MKProp::Update();
    temp_r4_432 = MKModel_GetWorldMatrix(this->unk4) - 4;
    M2C_STRUCT_COPY((s32) &arg_sp24C + 4, temp_r4_432 + 4, 0x40);
    temp_r3_447 = M2C_FIELD(M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), void *(**)(void **, s32, void *), 0xC)(M2C_FIELD(&gb, void ***, 0), temp_r4_432 + 0x40, &arg_sp24C + 0x40), void **, 8);
    arg_sp1B8 = M2C_FIELD(temp_r3_447, f64 *, 0);
    this->unk4C.unk8 = 0.0f;
    this->unk4C.unk4 = 0;
    arg_sp1C0 = M2C_FIELD(temp_r3_447, f64 *, 8);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
    arg_sp178 = arg_spA8;
    arg_spB0 = (f32) arg_sp1C0 * this->unk70;
    arg_sp180 = (f64) arg_spB0;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp188 = arg_sp98;
    arg_spA0 = this->unk64->unk8 + (f32) arg_sp180;
    arg_sp190 = (f64) arg_spA0;
    this->unk4C.AddNode(*((MKVector3 *) &arg_sp188));
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    arg_sp50 = (f32) arg_sp1C0 * (5.0f * this->unk70);
    arg_sp70 = 0.0f;
    arg_sp68 = 0.0f;
    arg_sp6C = 500.0f * this->unk6C;
    arg_sp118 = arg_sp48;
    arg_sp120 = (f64) arg_sp50;
    arg_sp128 = (f64) arg_sp68;
    arg_sp130 = (f64) arg_sp70;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp138 = arg_sp88;
    arg_sp90 = this->unk64->unk8 + this->unk68->unk8;
    arg_sp140 = (f64) arg_sp90;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
    arg_sp148 = arg_sp78;
    arg_sp80 = (f32) arg_sp140 * 0.5f;
    arg_sp150 = (f64) arg_sp80;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp158 = arg_sp58;
    arg_sp60 = (f32) arg_sp150 + (f32) arg_sp130;
    arg_sp160 = (f64) arg_sp60;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp168 = arg_sp38;
    arg_sp40 = (f32) arg_sp160 + (f32) arg_sp120;
    arg_sp170 = (f64) arg_sp40;
    this->unk4C.AddNode(*((MKVector3 *) &arg_sp168));
    this->unk4C.AddNode(*this->unk68);
    temp_f29_567 = 9.424778f * gUpdateTimeDelta;
    Normalise(*((MKVector3 *) &arg_sp108));
    arg_sp210.SetRotateAroundAxis(*((MKVector3 *) &arg_sp108), temp_f29_567);
    arg_sp250.Multiply3x3((Matrix *) &arg_sp250, (Matrix *) &arg_sp210);
    temp_f29_581 = 0.7853982f * gUpdateTimeDelta;
    Normalise(*((MKVector3 *) &arg_spF8));
    arg_sp1D0.SetRotateAroundAxis(*((MKVector3 *) &arg_spF8), temp_f29_581);
    arg_sp250.Multiply3x3((Matrix *) &arg_sp250, (Matrix *) &arg_sp1D0);
    MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &arg_sp250));
    arg_sp14 = 0.0f;
    arg_spE8.GetMeasure(this->unk60, (Matrix *) &this->unk4C, KDSpline_PositionMixer);
    MKModel_SetPosition(this->unk4, *((MKVector3 *) &arg_spE8));
    temp_r4_605 = this->unk74;
    if (temp_r4_605 != NULL) {
        temp_r4_605->unk2C += 0.5f * gUpdateTimeDelta;
        temp_r4_615 = this->unk8;
        temp_r3_618 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
        arg_sp1A8 = M2C_FIELD(temp_r4_615, f64 *, 0x30);
        arg_spD8 = M2C_FIELD(temp_r3_618, f64 *, 0x30);
        arg_sp1B0 = M2C_FIELD(temp_r4_615, f64 *, 0x38);
        arg_spE0 = M2C_FIELD(temp_r3_618, f64 *, 0x38);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        arg_sp198 = arg_sp28;
        arg_sp30 = (f32) arg_spE0 - (f32) arg_sp1B0;
        arg_sp1A0 = (f64) arg_sp30;
        var_f4_646 = ((f32) arg_sp1A0 * (f32) arg_sp1A0) + (((f32) arg_sp198 * (f32) arg_sp198) + (arg_sp19C * arg_sp19C));
        if (var_f4_646 > 0.000001f) {
            if (var_f4_646 > 0.0f) {
                temp_f1_652 = __frsqrte(var_f4_646);
                temp_f1_658 = 0.5 * temp_f1_652 * -(((f64) var_f4_646 * (temp_f1_652 * temp_f1_652)) - 3.0);
                temp_f1_662 = 0.5 * temp_f1_658 * -(((f64) var_f4_646 * (temp_f1_658 * temp_f1_658)) - 3.0);
                var_f4_646 = (f32) ((f64) var_f4_646 * (0.5 * temp_f1_662 * -(((f64) var_f4_646 * (temp_f1_662 * temp_f1_662)) - 3.0)));
            } else if (var_f4_646 < M2C_BITWISE(f32, 0.0)) {
                var_f4_646 = __float_nan;
            } else {
                arg_sp10 = var_f4_646;
                temp_r3_681 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
                switch (temp_r3_681) {              /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                        var_r0_691 = 1;
                    } else {
                        var_r0_691 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                        var_r0_691 = 5;
                    } else {
                        var_r0_691 = 3;
                    }
                    break;
                default:
                    var_r0_691 = 4;
                    break;
                }
                if (var_r0_691 == 1) {
                    var_f4_646 = __float_nan;
                }
            }
            var_f4_713 = 1.0f / var_f4_646;
        } else {
            var_f4_713 = 0.0f;
        }
        arg_sp198 = (f32) arg_sp198 * var_f4_713;
        arg_sp19C *= var_f4_713;
        arg_sp1A0 = (f32) arg_sp1A0 * var_f4_713;
        arg_spB8.operator*(50.0f);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        temp_r3_738 = this->unk74;
        temp_r3_738->unk0 = arg_sp18;
        arg_sp20 = (f32) arg_sp1B0 + arg_spC0;
        arg_spC8 = arg_sp18;
        temp_r3_738->unk8 = (f64) arg_sp20;
        arg_spD0 = (f64) arg_sp20;
        this->unk78 += 10.0f * gUpdateTimeDelta;
        this->unk74->unk24 = (0.5f * _table_sinf(this->unk78)) + 2.5f;
    }
    this->unk60 += this->unk6C * gUpdateTimeDelta;
    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
    if (this->unk60 == 1.0f) {
        Collect();
    }
}
#endif

void Collectable2::Resolve() {
    MKProp::Resolve();
}

#if 0 // DRAFT: function call 'MKModel_Create(MKHeap *, int, int, int)' does not match
void Collectable2::LoadDone() {
    MKProp::LoadDone();
    this->unk4 = MKModel_Create(MKModel_GetName(M2C_FIELD(this->unk0, MKModel **, 0x2C)), NULL, 2, NULL);
    this->unk8 = MKModel_GetWorldMatrix(this->unk4);
}
#endif

void Collectable2::Deinit() {
    MKProp::Deinit();
    this->unk4C.Deinit();
}

void Collectable2::Init() {
    MKProp::Init();
    this->unk4C.Init(3, 0U);
    this->unk60 = 0.0f;
    this->unk6C = 1.0f;
    this->unk74 = NULL;
    this->unk78 = 0.0f;
}

void Collectable2_cpp::__sinit() {
    f32 temp_f0_935;
    f64 temp_f1_916;
    f64 temp_f1_924;
    f64 temp_f3_904;
    f64 temp_f4_913;
    f64 temp_f4_921;
    f64 temp_f8_906;

    temp_f3_904 = __frsqrte(2014000.0);
    temp_f8_906 = __frsqrte(380000.0);
    temp_f4_913 = 0.5 * temp_f3_904 * -((2014000.0 * (temp_f3_904 * temp_f3_904)) - 3.0);
    temp_f1_916 = 0.5 * temp_f8_906 * -((380000.0 * (temp_f8_906 * temp_f8_906)) - 3.0);
    temp_f4_921 = 0.5 * temp_f4_913 * -((2014000.0 * (temp_f4_913 * temp_f4_913)) - 3.0);
    temp_f1_924 = 0.5 * temp_f1_916 * -((380000.0 * (temp_f1_916 * temp_f1_916)) - 3.0);
    temp_f0_935 = (f32) (380000.0 * (0.5 * temp_f1_924 * -((380000.0 * (temp_f1_924 * temp_f1_924)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_921 * -((2014000.0 * (temp_f4_921 * temp_f4_921)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_935;
}
