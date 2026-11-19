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

extern "C" f64 acos(f64);
void *WaterTrickleEmitter::Update() {
    MKVector3 sp50;
    MKVector3 sp60;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    KDPathSegment *var_r30;
    f32 temp_f29;
    f32 temp_f28;
    f32 temp_f30;
    f32 temp_f4;
    f32 temp_f31;
    s32 var_r29;

    this->unk88 = this->unk88 + gUpdateTimeDelta;
    if (this->unk88 >= MKRand_Float((int *) &gViewSeed, M2C_FIELD(&this->unk4C, f32 *, 0x30), this->unk4C.unk34)) {
        this->unk88 = 0.0f;
        var_r30 = NULL;
        if (this->unk94 != 0) {
            var_r30 = &this->unk4C;
        }
        sp60.unk0 = 0.0f;
        sp60.unk4 = 0.0f;
        sp60.unk8 = 0.0f;
        sp60.unkC = 0.0f;
        var_r29 = 0;
        while (var_r29 < this->unk84) {
            if (this->unk94 != 0) {
                this->unk4C.GetPositionAlongPath(0.0f, sp50);
            } else {
                sp50.unk0 = M2C_FIELD(this->unk8, f32 *, 0x30);
                sp50.unk4 = M2C_FIELD(this->unk8, f32 *, 0x34);
                sp50.unk8 = M2C_FIELD(this->unk8, f32 *, 0x38);
                if (this->unkE0 > 0.0f) {
                    temp_f29 = MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f);
                    temp_f28 = (f32) acos(MKRand_Float((int *) &gViewSeed, this->unkE4, 1.0f));
                    temp_f30 = MKRand_Float((int *) &gViewSeed, this->unk8C, this->unk90);
                    _table_sincosf(temp_f28, sp18, sp14);
                    _table_sincosf(temp_f29, sp10, spC);
                    temp_f4 = sp18 * temp_f30;
                    sp60.unk0 = spC * temp_f4;
                    sp60.unk4 = sp10 * temp_f4;
                    sp60.unk8 = sp14 * temp_f30;
                    sp60.unkC = 0.0f;
                } else {
                    temp_f31 = MKRand_Float((int *) &gViewSeed, this->unk8C, this->unk90);
                    sp60.unk0 = M2C_FIELD(this->unk8, f32 *, 0x20) * temp_f31;
                    sp60.unk4 = M2C_FIELD(this->unk8, f32 *, 0x24) * temp_f31;
                    sp60.unk8 = M2C_FIELD(this->unk8, f32 *, 0x28) * temp_f31;
                }
            }
            sp8 = MKRand_Float((int *) &gViewSeed, 1.0f, 3.0f);
            M2C_FIELD(&gb, WaterDripPS **, 0x6C)->Emit(sp50, sp60, sp8, true, false, var_r30);
            var_r29 += 1;
        }
    }
}

s32 WaterTrickleEmitter::LoadDone() {
    MKProp::LoadDone();
    if (this->unk94 != 0) {
        this->unk4C.LoadDone();
        this->unk84 = 1;
    }
    this->unkA0.SetIdentity();
    this->unkA0.RotatePYR(&this->unkA0, M2C_FIELD(&MKProp::loadInfo, MKVector3 *, 0x50));
    this->unkA0.Scale3x3(&this->unkA0, M2C_FIELD(&MKProp::loadInfo, MKVector3 *, 0x60));
    this->unkA0.unk30 = M2C_FIELD(&MKProp::loadInfo, f32 *, 0x40);
    this->unkA0.unk34 = M2C_FIELD(&MKProp::loadInfo, f32 *, 0x44);
    this->unkA0.unk38 = M2C_FIELD(&MKProp::loadInfo, f32 *, 0x48);
    this->unkA0.unk3C = 1.0f;
    this->unkE4 = _table_sinf(1.5707964f + this->unkE0);
}

extern "C" s32 stricmp(s8 *, const char *);
s32 WaterTrickleEmitter::LoadLine(MKIniLine *arg0) {
    if (MKProp::LoadLine(arg0) != 0 ||
        arg0->LoadFloat("MinEmitRate", &M2C_FIELD(&this->unk4C, f32 *, 0x30), 0) != 0 ||
        arg0->LoadFloat("MaxEmitRate", &this->unk4C.unk34, 0) != 0 ||
        arg0->LoadInt("NumPerEmit", (int *) &this->unk84, 0) != 0 ||
        arg0->LoadFloat("MinEmitVel", &this->unk8C, 0) != 0 ||
        arg0->LoadFloat("MaxEmitVel", &this->unk90, 0) != 0 ||
        arg0->LoadFloat("Angle", &this->unkE0, 0) != 0) {
        return 1;
    }
    if (arg0->GetFieldName() != NULL) {
        arg0->GetFieldName();
        if (stricmp(arg0->GetFieldName(), "Waypoints") == 0) {
            if (arg0->GetNmbrOfSubLines() == 0) {
                this->unk94 = 0;
            } else {
                this->unk94 = 1;
            }
            this->unk4C.Init();
            this->unk4C.LoadLine(arg0);
        }
    }
    return 0;
}

void WaterTrickleEmitter::Init() {
    MKProp::Init();
    this->unk94 = 0;
    M2C_FIELD(&this->unk4C, f32 *, 0x30) = 0.0f;
    this->unk4C.unk34 = 0.0f;
    this->unk88 = 0.0f;
    this->unk84 = 0;
    this->unk8 = &this->unkA0;
    this->unkA0.SetIdentity();
    this->unk8C = 0.0f;
    this->unk90 = 200.0f;
    this->unkE0 = 0.0f;
}

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
