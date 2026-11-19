#include "spyro/source/WaterTrickleEmitter.h"
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
#include "spyro/source/Level.h"
#include "spyro/source/WaterDripPS.h"
#include "common/Source/StdMath.h"
#include "unplaced_inlines.h"
#include <m2c_macros.h>

f64 acos();                                         /* extern */
s32 stricmp(s8 *);                                  /* extern */
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;

void WaterTrickleEmitter::Deinit() {
    MKProp::Deinit();
    if ((u8) M2C_FIELD(this, u8 *, 0x94) != 0) {
        ((KDPathSegment *) &this->unk4C)->Deinit();
    }
}

#if 0 // DRAFT: illegal explicit conversion from 'Matrix *' to 'float'
void *WaterTrickleEmitter::Update() {
    f64 sp68;                                       /* compiler-managed */
    f64 sp60;                                       /* compiler-managed */
    MKVector3 sp50;
    f64 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    M2C_UNK *var_r30_89;
    f32 temp_f28_136;
    f32 temp_f29_130;
    f32 temp_f30_141;
    f32 temp_f4_152;
    f64 temp_f1_168;
    s32 var_r29_104;
    void *temp_r3_117;
    void *temp_r3_171;

    this->unk84 = M2C_BITWISE(f32, this->unk84) + gUpdateTimeDelta;
    if (M2C_BITWISE(f32, this->unk84) >= MKRand_Float((int *) &gViewSeed, M2C_BITWISE(f32, this->unk4C.unk2C), M2C_BITWISE(f32, this->unk4C.unk30))) {
        var_r30_89 = NULL;
        sp38 = 0.0f;
        sp30 = 0.0f;
        sp34 = 0.0f;
        this->unk84 = 0.0f;
        sp68 = (f64) sp38;
        sp60 = (f64) sp30;
        if ((u8) M2C_FIELD(this, u8 *, 0x94) != 0) {
            var_r30_89 = (long *) (&this->unk4C);
        }
        var_r29_104 = 0;
loop_10:
        if (var_r29_104 < M2C_BITWISE(s32, this->unk4C.unk34)) {
            if ((u8) M2C_FIELD(this, u8 *, 0x94) != 0) {
                ((KDPathSegment *) &this->unk4C)->GetPositionAlongPath(0.0f, sp50);
            } else {
                temp_r3_117 = this->unk8;
                sp50 = M2C_FIELD(temp_r3_117, f64 *, 0x30);
                sp50.unk8 = M2C_FIELD(temp_r3_117, f64 *, 0x38);
                if (this->unkA0.unk3C > 0.0f) {
                    temp_f29_130 = MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f);
                    MKRand_Float((int *) &gViewSeed, this->unkE0, 1.0f);
                    temp_f28_136 = (f32) acos();
                    temp_f30_141 = MKRand_Float((int *) &gViewSeed, this->unk88, this->unk8C);
                    _table_sincosf(temp_f28_136, sp18, sp14);
                    _table_sincosf(temp_f29_130, sp10, spC);
                    temp_f4_152 = sp18 * temp_f30_141;
                    sp68 = sp14 * temp_f30_141;
                    (*(f32 *) ((u8 *) &sp50 + 0x14)) = sp10 * temp_f4_152;
                    sp60 = spC * temp_f4_152;
                    (*(f32 *) ((u8 *) &sp50 + 0x1c)) = 0.0f;
                } else {
                    temp_f1_168 = MKRand_Float((int *) &gViewSeed, this->unk88, this->unk8C);
                    temp_r3_171 = ((u8 *) this->unk8) + 0x20;
                    sp20 = M2C_FIELD(temp_r3_171, f64 *, 0) * temp_f1_168;
                    sp40 = sp20;
                    sp28 = M2C_FIELD(temp_r3_171, f32 *, 8) * (f32) temp_f1_168;
                    sp60 = sp20;
                    sp48 = (f64) sp28;
                    sp68 = (f64) sp28;
                }
            }
            sp8 = MKRand_Float((int *) &gViewSeed, 1.0f, 3.0f);
            ((WaterDripPS *) (M2C_FIELD(&gb, WaterDripPS **, 0x6C)))->Emit(sp50, *((MKVector3 *) &sp60), sp8, 1U, 0U, (KDPathSegment *) var_r30_89);
            var_r29_104 += 1;
            goto loop_10;
        }
    }
}
#endif

#if 0 // DRAFT: illegal operand
s32 WaterTrickleEmitter::LoadDone() {
    M2C_UNK *temp_r3_239;
    M2C_UNK *temp_r3_245;

    MKProp::LoadDone();
    if ((u8) M2C_FIELD(this, u8 *, 0x94) != 0) {
        ((KDPathSegment *) &this->unk4C)->LoadDone();
        this->unk4C.unk34 = 1e-45f;
    }
    ((Matrix *) &this->unkA0)->SetIdentity();
    temp_r3_239 = (long *) (&this->unkA0);
    ((Matrix *) temp_r3_239)->RotatePYR((Matrix *) temp_r3_239, MKProp::loadInfo + 0x50);
    temp_r3_245 = (long *) (&this->unkA0);
    ((Matrix *) temp_r3_245)->Scale3x3((Matrix *) temp_r3_245, MKProp::loadInfo + 0x60);
    this->unkA0.unk2C = M2C_FIELD(&MKProp::loadInfo, f32 *, 0x40);
    this->unkA0.unk30 = M2C_BITWISE(f32, MKProp::loadInfo.__vptr);
    this->unkA0.unk34 = MKProp::loadInfo.unk48;
    this->unkA0.unk38 = 1.0f;
    this->unkE0 = _table_sinf(1.5707964f + this->unkA0.unk3C);
}
#endif

#if 0 // DRAFT: function call 'stricmp(const char[10])' does not match 'stricmp(signed char *)'
s32 WaterTrickleEmitter::LoadLine(MKIniLine *arg0) {
    if ((MKProp::LoadLine(arg0) != 0) || (arg0->LoadFloat("MinEmitRate", (f32 *) &this->unk4C.unk2C, 0) != 0) || (arg0->LoadFloat("MaxEmitRate", (f32 *) &this->unk4C.unk30, 0) != 0) || (arg0->LoadInt("NumPerEmit", (int *) &this->unk4C.unk34, 0) != 0) || (arg0->LoadFloat("MinEmitVel", &this->unk88, 0) != 0) || (arg0->LoadFloat("MaxEmitVel", &this->unk8C, 0) != 0) || (arg0->LoadFloat("Angle", &this->unkA0.unk3C, 0) != 0)) {
        return 1;
    }
    if (arg0->GetFieldName() != NULL) {
        arg0->GetFieldName();
        if (stricmp("Waypoints") == 0) {
            if (arg0->GetNmbrOfSubLines() == 0) {
                M2C_FIELD(this, s8 *, 0x94) = 0;
            } else {
                M2C_FIELD(this, s8 *, 0x94) = 1;
            }
            ((KDPathSegment *) &this->unk4C)->Init();
            ((KDPathSegment *) &this->unk4C)->LoadLine(arg0);
        }
    }
    return 0;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'float' to 'Matrix *'
void WaterTrickleEmitter::Init() {
    M2C_UNK *temp_r3_391;

    MKProp::Init();
    M2C_FIELD(this, s8 *, 0x94) = 0;
    temp_r3_391 = (long *) (&this->unkA0);
    this->unk4C.unk2C = 0.0f;
    this->unk4C.unk30 = 0.0f;
    this->unk84 = 0.0f;
    this->unk4C.unk34 = 0.0f;
    this->unk8 = temp_r3_391;
    ((Matrix *) temp_r3_391)->SetIdentity();
    this->unk88 = 0.0f;
    this->unk8C = 200.0f;
    this->unkA0.unk3C = 0.0f;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to 'float'
void WaterTrickleEmitterDescriptor::Init() {
    f64 sp50;
    f64 sp48;
    MKVector3 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;

    MKPropDescriptor::Init();
    this->unk1C = (BoundingVolume *) &this->unk60;
    sp38 = MKVector(200.0f, 200.0f, 200.0f);
    sp18 = -M2C_BITWISE(f32, sp38);
    sp1C = -sp38.unk4;
    sp20 = -sp38.unk8;
    M2C_FIELD(this, f64 *, 0x60) = (f64) sp18;
    sp10 = 400.0f;
    sp8 = 400.0f;
    spC = 400.0f;
    this->unk68 = (f64) sp20;
    this->unk70 = (f64) sp8;
    sp48 = (f64) sp18;
    sp50 = (f64) sp20;
    sp28 = (f64) sp8;
    sp30 = (f64) sp10;
    this->unk78 = (f64) sp10;
}
#endif
