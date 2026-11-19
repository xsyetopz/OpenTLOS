#include "spyro/source/Collectable2.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Coronas.h"
#include "spyro/source/FlyingChunkPS.h"
#include "spyro/source/GameData.h"
#include "spyro/source/KDSpline.h"
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
    f64 sp8;
    Corona *temp_r4_44;
    MKVector3 *temp_r30_104;
    f32 temp_f27_111;
    f32 temp_f27_138;
    f32 temp_f27_170;
    f32 temp_f27_77;
    f32 temp_f28_106;
    f32 temp_f28_143;
    f32 temp_f28_72;
    f64 temp_f0_125;
    f64 temp_f0_157;
    f64 temp_f0_91;
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
        temp_f0_91 = spA8 * 5.64367472e-315;
        sp48 = temp_f0_91;
        spB8 = temp_f0_91;
        sp50 = (f32) spB0 * 600.0f;
        spC0 = (f64) sp50;
        temp_r30_104 = ((u8 *) this->unk8) + 0x30;
        temp_f28_106 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        temp_f27_111 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        sp38 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        sp3C = temp_f27_111;
        sp40 = temp_f28_106;
        sp88 = (f64) sp38;
        sp90 = (f64) sp40;
        temp_f0_125 = sp88 * 5.328646264e-315;
        sp28 = temp_f0_125;
        sp98 = temp_f0_125;
        sp30 = (f32) sp90 * 3.1415927f;
        spA0 = (f64) sp30;
        temp_f27_138 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        temp_f28_143 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        sp18 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        sp1C = temp_f28_143;
        sp20 = temp_f27_138;
        sp68 = (f64) sp18;
        sp70 = (f64) sp20;
        temp_f0_157 = sp68 * 5.328646264e-315;
        sp8 = temp_f0_157;
        sp78 = temp_f0_157;
        sp10 = (f32) sp70 * 3.1415927f;
        sp80 = (f64) sp10;
        temp_f27_170 = MKRand_Float(&gViewSeed, 3.0f, 5.0f);
        ((FlyingChunkPS *) (M2C_FIELD(&gb, FlyingChunkPS **, 0x9C)))->Emit(*temp_r30_104, *((MKVector3 *) &spB8), *((MKVector3 *) &sp98), *((MKVector3 *) &sp78), temp_f27_170, *(MKModel_GetColor(this->unk4)), 0, NULL);
        var_r29_65 += 1;
    } while (var_r29_65 < 4);
}
#endif

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void Collectable2::InitData(const Matrix &arg0, const MKVector3 *arg1, const MKVector3 *arg2, float arg3, float arg4, float arg5) {
    Matrix sp90;
    Matrix sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    Corona *temp_r4_286;

    M2C_STRUCT_COPY((s32) &sp50.unk3C + 4, (s32) (&arg0 - 4) + 4, 0x40);
    sp90.Scale3x3(&sp90, 2.0f);
    sp50.SetRotateAroundAxis(*((MKVector3 *) &arg0), arg5);
    sp90.Multiply3x3(&sp90, &sp50);
    MKModel_SetWorldMatrix(this->unk4, sp90);
    this->unk64 = arg1;
    this->unk68 = arg2;
    this->unk6C = arg3;
    this->unk70 = arg4;
    this->unk60 = 0.0f;
    if ((Corona *) this->unk74 == NULL) {
        sp28 = 0.0f;
        sp10 = 1.0f;
        sp14 = 1.0f;
        sp18 = 1.0f;
        sp1C = 1.0f;
        sp20 = 0.0f;
        sp24 = 0.0f;
        sp30 = (f64) sp10;
        sp38 = (f64) sp18;
        sp40 = (f64) sp20;
        sp48 = (f64) sp28;
        this->unk74 = ((Coronas *) (M2C_FIELD(&gb, Coronas **, 0x64)))->Alloc(*((MKVector3 *) &sp40), *((MKVector4 *) &sp30), 0.5f, lit_778, lit_779);
        temp_r4_286 = this->unk74;
        if (temp_r4_286 != NULL) {
            temp_r4_286->unk31 |= 0x40;
        }
        this->unk78 = 0.0f;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'CollectRequestMsg'
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
    f64 sp8;
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
    if (M2C_FIELD(*gMK, u8 (**)(void **, Collectable2 *, s32), 0x9C)(gMK, this, *MKResource::sWorkingChunkID) != 0) {
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
        sp8 = sp58 - sp38;
        sp18 = sp8;
        sp10 = (f32) sp60 - (f32) sp40;
        sp28 = sp8;
        sp20 = (f64) sp10;
        sp30 = (f64) sp10;
        if ((((f32) sp20 * (f32) sp20) + (((f32) sp18 * (f32) sp18) + ((*(f32 *) ((u8 *) &sp18 + 0x4)) * (*(f32 *) ((u8 *) &sp18 + 0x4))))) < (temp_f4_347 * temp_f4_347)) {
            ((Stat *) &GameData::gameData[0xA0])->Add(2.0f, 1U);
        }
    }
}
#endif

void Collectable2::Draw() {
    MKProp::Draw();
    MKModel_Draw(this->unk4, NULL);
}

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void Collectable2::Update() {
    Matrix sp250;
    Matrix sp210;
    Matrix sp1D0;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    f64 sp1A0;                                      /* compiler-managed */
    f64 sp198;                                      /* compiler-managed */
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
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
    MKVector3 sp108;
    MKVector3 spF8;
    M2C_UNK spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    MKVector3 spB8;
    f32 spB0;
    f64 spA8;
    f32 spA0;
    f64 sp98;
    f32 sp90;
    f64 sp88;
    f32 sp80;
    f64 sp78;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    Corona *temp_r3_738;
    Corona *temp_r4_605;
    MKVector3 *temp_r3_504;
    MKVector3 *temp_r4_464;
    MKVector3 *temp_r4_502;
    f32 temp_f1_486;
    f32 temp_f29_567;
    f32 temp_f29_581;
    f32 temp_f2_455;
    f32 var_f4_646;
    f32 var_f4_713;
    f64 temp_f0_459;
    f64 temp_f0_471;
    f64 temp_f0_512;
    f64 temp_f0_524;
    f64 temp_f0_535;
    f64 temp_f0_547;
    f64 temp_f0_733;
    f64 temp_f1_620;
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
    M2C_STRUCT_COPY((s32) &sp210.unk3C + 4, temp_r4_432 + 4, 0x40);
    temp_r3_447 = M2C_FIELD(M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), void *(**)(void **, s32, void *), 0xC)(M2C_FIELD(&gb, void ***, 0), temp_r4_432 + 0x40, &sp210.unk3C + 0x40), void **, 8);
    sp1B8 = M2C_FIELD(temp_r3_447, f64 *, 0);
    this->unk4C.unk8 = 0.0f;
    this->unk4C.unk4 = 0;
    temp_f2_455 = this->unk70;
    sp1C0 = M2C_FIELD(temp_r3_447, f64 *, 8);
    temp_f0_459 = sp1B8 * (f64) temp_f2_455;
    spA8 = temp_f0_459;
    temp_r4_464 = this->unk64;
    sp178 = temp_f0_459;
    spB0 = (f32) sp1C0 * temp_f2_455;
    sp180 = (f64) spB0;
    temp_f0_471 = M2C_FIELD(temp_r4_464, f64 *, 0) + temp_f0_459;
    sp98 = temp_f0_471;
    sp188 = temp_f0_471;
    spA0 = temp_r4_464->unk8 + (f32) sp180;
    sp190 = (f64) spA0;
    this->unk4C.AddNode(*((MKVector3 *) &sp188));
    temp_f1_486 = 5.0f * this->unk70;
    sp48 = sp1B8 * (f64) temp_f1_486;
    sp50 = (f32) sp1C0 * temp_f1_486;
    sp70 = 0.0f;
    sp68 = 0.0f;
    temp_r4_502 = this->unk68;
    sp6C = 500.0f * this->unk6C;
    temp_r3_504 = this->unk64;
    sp118 = sp48;
    sp120 = (f64) sp50;
    sp128 = (f64) sp68;
    sp130 = (f64) sp70;
    temp_f0_512 = M2C_FIELD(temp_r3_504, f64 *, 0) + M2C_FIELD(temp_r4_502, f64 *, 0);
    sp88 = temp_f0_512;
    sp138 = temp_f0_512;
    sp90 = temp_r3_504->unk8 + temp_r4_502->unk8;
    sp140 = (f64) sp90;
    temp_f0_524 = temp_f0_512 * 5.222099017e-315;
    sp78 = temp_f0_524;
    sp148 = temp_f0_524;
    sp80 = (f32) sp140 * 0.5f;
    sp150 = (f64) sp80;
    temp_f0_535 = sp148 + sp128;
    sp58 = temp_f0_535;
    sp158 = temp_f0_535;
    sp60 = (f32) sp150 + (f32) sp130;
    sp160 = (f64) sp60;
    temp_f0_547 = sp158 + sp118;
    sp38 = temp_f0_547;
    sp168 = temp_f0_547;
    sp40 = (f32) sp160 + (f32) sp120;
    sp170 = (f64) sp40;
    this->unk4C.AddNode(*((MKVector3 *) &sp168));
    this->unk4C.AddNode(*this->unk68);
    temp_f29_567 = 9.424778f * gUpdateTimeDelta;
    Normalise(sp108);
    sp210.SetRotateAroundAxis(sp108, temp_f29_567);
    sp250.Multiply3x3(&sp250, &sp210);
    temp_f29_581 = 0.7853982f * gUpdateTimeDelta;
    Normalise(spF8);
    sp1D0.SetRotateAroundAxis(spF8, temp_f29_581);
    sp250.Multiply3x3(&sp250, &sp1D0);
    MKModel_SetWorldMatrix(this->unk4, sp250);
    sp14 = 0.0f;
    ((KDUniformSpline *) &spE8)->GetMeasure(this->unk60, (Matrix *) &this->unk4C, KDSpline_PositionMixer);
    MKModel_SetPosition(this->unk4, *((MKVector3 *) &spE8));
    temp_r4_605 = this->unk74;
    if (temp_r4_605 != NULL) {
        temp_r4_605->unk2C += 0.5f * gUpdateTimeDelta;
        temp_r4_615 = this->unk8;
        temp_r3_618 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
        temp_f1_620 = M2C_FIELD(temp_r3_618, f64 *, 0x30);
        sp1A8 = M2C_FIELD(temp_r4_615, f64 *, 0x30);
        spD8 = temp_f1_620;
        sp1B0 = M2C_FIELD(temp_r4_615, f64 *, 0x38);
        spE0 = M2C_FIELD(temp_r3_618, f64 *, 0x38);
        sp28 = temp_f1_620 - sp1A8;
        sp198 = sp28;
        sp30 = (f32) spE0 - (f32) sp1B0;
        sp1A0 = (f64) sp30;
        var_f4_646 = ((f32) sp1A0 * (f32) sp1A0) + (((f32) sp198 * (f32) sp198) + ((*(f32 *) ((u8 *) &sp190 + 0xc)) * (*(f32 *) ((u8 *) &sp190 + 0xc))));
        if (var_f4_646 > 0.000001f) {
            if (var_f4_646 > 0.0f) {
                temp_f1_652 = __frsqrte(var_f4_646);
                temp_f1_658 = 0.5 * temp_f1_652 * -(((f64) var_f4_646 * (temp_f1_652 * temp_f1_652)) - 3.0);
                temp_f1_662 = 0.5 * temp_f1_658 * -(((f64) var_f4_646 * (temp_f1_658 * temp_f1_658)) - 3.0);
                var_f4_646 = (f32) ((f64) var_f4_646 * (0.5 * temp_f1_662 * -(((f64) var_f4_646 * (temp_f1_662 * temp_f1_662)) - 3.0)));
            } else if (var_f4_646 < M2C_BITWISE(f32, 0.0)) {
                var_f4_646 = __float_nan;
            } else {
                sp10 = var_f4_646;
                temp_r3_681 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_681) {              /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_691 = 1;
                    } else {
                        var_r0_691 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
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
        sp198 = (f32) sp198 * var_f4_713;
        (*(f32 *) ((u8 *) &sp190 + 0xc)) *= var_f4_713;
        sp1A0 = (f32) sp1A0 * var_f4_713;
        spB8.operator*(50.0f);
        temp_f0_733 = sp1A8 + M2C_BITWISE(f64, spB8);
        sp18 = temp_f0_733;
        temp_r3_738 = this->unk74;
        temp_r3_738->unk0 = temp_f0_733;
        sp20 = (f32) sp1B0 + spB8.unk8;
        spC8 = temp_f0_733;
        temp_r3_738->unk8 = (f64) sp20;
        spD0 = (f64) sp20;
        this->unk78 += 10.0f * gUpdateTimeDelta;
        this->unk74->unk24 = (0.5f * _table_sinf(this->unk78)) + 2.5f;
    }
    this->unk60 += this->unk6C * gUpdateTimeDelta;
    if (this->unk60 >= 1.0f) {
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
