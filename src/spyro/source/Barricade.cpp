#include "spyro/source/Barricade.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "spyro/source/EmbersPS.h"
#include "spyro/source/Shatterable.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDRandom.h"
#include <m2c_macros.h>

extern s32 gViewSeed;
extern M2C_UNK gb;

#if 0 // DRAFT: undefined identifier 'MKVector'
s32 BarricadeProp::GetLookToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    f64 sp40;
    f64 sp38;
    f64 sp28;
    f64 sp18;
    f32 sp10;
    f64 sp8;

    MKVector(0.0f, 100.0f, 0.0f);
    ((MKProp *) &sp28)->GetPos();
    sp8 = sp28 + sp18;
    M2C_FIELD(arg1, f64 *, 0) = sp8;
    sp10 = sp30 + sp20;
    sp38 = sp8;
    sp40 = (f64) sp10;
    M2C_FIELD(arg1, f64 *, 8) = (f64) sp10;
    return 1;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
s32 BarricadeProp::GetMoveToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    MKProp sp38;
    MKVector3 sp28;
    M2C_UNK sp18;
    f32 sp10;
    f64 sp8;

    ((MKProp *) &sp18)->GetDir();
    sp28.operator*(-150.0f);
    sp38.GetPos();
    sp8 = sp38 + M2C_BITWISE(f64, sp28);
    M2C_FIELD(arg1, f64 *, 0) = sp8;
    sp10 = M2C_BITWISE(f32, sp38.unk8) + sp28.unk8;
    sp38.unk10 = sp8;
    sp38.unk18 = (f64) sp10;
    M2C_FIELD(arg1, f64 *, 8) = (f64) sp10;
    return 1;
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKAnimScript'
void BarricadeProp::Message(MKMessage *arg0) {
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    MKVector3 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    f32 temp_f1_208;
    f32 temp_f26_171;
    f64 temp_f0_196;
    s32 temp_r0_237;
    s32 var_r29_162;
    void *temp_r5_170;

    if ((s32) arg0->unk0 == 0x15E) {
        this->unk80->SetAnim(this->unk80->GetAnim("Explode"), 1.0f, 0.0f, 0, -1);
        this->unk19C = 1;
        var_r29_162 = 0;
        do {
            temp_r5_170 = this->unk8;
            temp_f26_171 = MKRand_Float(&gViewSeed, 0.5f, 1.0f);
            sp48 = -1.0f;
            sp38 = 1.0f;
            sp40 = -1.0f;
            sp44 = 0.25f;
            sp30 = 1.0f;
            sp34 = 1.0f;
            spA0 = M2C_FIELD(temp_r5_170, f64 *, 0x30);
            spA8 = M2C_FIELD(temp_r5_170, f64 *, 0x38);
            sp70 = (f64) sp40;
            sp78 = (f64) sp48;
            sp60 = (f64) sp30;
            sp68 = (f64) sp38;
            KDRand_Vector(sp80, *((MKVector3 *) &sp70));
            temp_f0_196 = sp80 * 5.717499035e-315;
            sp20 = temp_f0_196;
            sp90 = temp_f0_196;
            sp28 = sp80.unk8 * 2000.0f;
            sp98 = (f64) sp28;
            temp_f1_208 = MKRand_Float(&gViewSeed, 10.0f, 15.0f);
            sp10 = 1.0f;
            sp14 = temp_f26_171;
            sp8 = temp_f1_208;
            sp18 = 0.0f;
            sp1C = 1.0f;
            sp50 = (f64) sp10;
            sp58 = (f64) sp18;
            ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(*((MKVector3 *) &spA0), *((MKVector3 *) &sp90), sp8, *((MKVector4 *) &sp50), -2000.0f);
            var_r29_162 += 1;
        } while (var_r29_162 < 0xA);
    }
    if ((u8) this->unk19C != 0) {
        Shatterable::Message(arg0);
        return;
    }
    temp_r0_237 = arg0->unk0;
    if ((temp_r0_237 != 4) && (temp_r0_237 != 1) && (temp_r0_237 != 5)) {
        Shatterable::Message(arg0);
    }
}
#endif

void BarricadeProp::Update() {
    Shatterable::Update();
}

void BarricadeProp::Resolve() {
    Shatterable::Resolve();
}

#if 0 // DRAFT: type mismatch
void BarricadeProp::LoadDone() {
    Shatterable::LoadDone();
    if ((MKProp *) this->unk170 > 0) {
        this->unk19C = 1;
    }
}
#endif

void BarricadeProp::Deinit() {
    Shatterable::Deinit();
}

void BarricadeProp::Init() {
    this->unk198 = 0.0f;
    this->unk19C = 0;
    Shatterable::Init();
}
