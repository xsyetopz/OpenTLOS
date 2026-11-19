#include "spyro/source/Barricade.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
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
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
#include "spyro/source/EmbersPS.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/TargetManager.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDRandom.h"
#include "unplaced_inlines.h"
#include <m2c_macros.h>

extern s32 gViewSeed;
extern M2C_UNK gb;

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to 'double'
s32 BarricadeProp::GetLookToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    f64 sp40;
    f64 sp38;
    f64 sp28;
    MKVector3 sp18;
    f32 sp10;
    f64 sp8;

    sp18 = MKVector(0.0f, 100.0f, 0.0f);
    ((MKProp *) &sp28)->GetPos();
    sp8 = sp28 + M2C_BITWISE(f64, sp18);
    M2C_FIELD(arg1, f64 *, 0) = sp8;
    sp10 = sp30 + sp18.unk8;
    sp38 = sp8;
    sp40 = (f64) sp10;
    M2C_FIELD(arg1, f64 *, 8) = (f64) sp10;
    return 1;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to 'double'
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

void BarricadeProp::Message(MKMessage *arg0) {
    MKVector3 pos;
    MKVector3 a;
    MKVector3 b;
    MKVector3 dir;
    MKVector3 vel;
    MKVector4 color;
    f32 rand1;
    f32 rand2;
    s32 i;

    if ((s32) arg0->unk0 == 0x15E) {
        this->unk80->SetAnim((MKAnim *) this->unk80->GetAnim("Explode"), 1.0f, 0.0f, 0, -1);
        this->unk1AC = 1;
        i = 0;
        do {
            rand1 = MKRand_Float((int *) &gViewSeed, 0.5f, 1.0f);
            pos.unk0 = M2C_FIELD(this->unk8, f32 *, 0x30);
            pos.unk4 = M2C_FIELD(this->unk8, f32 *, 0x34);
            pos.unk8 = M2C_FIELD(this->unk8, f32 *, 0x38);
            a.unk0 = -1.0f;
            a.unk4 = 0.25f;
            a.unk8 = -1.0f;
            b.unk0 = 1.0f;
            b.unk4 = 1.0f;
            b.unk8 = 1.0f;
            dir = KDRand_Vector(a, b);
            vel.unk0 = dir.unk0 * 2000.0f;
            vel.unk4 = dir.unk4 * 2000.0f;
            vel.unk8 = dir.unk8 * 2000.0f;
            rand2 = MKRand_Float((int *) &gViewSeed, 10.0f, 15.0f);
            color.unk0 = 1.0f;
            color.unk4 = rand1;
            color.unk8 = 0.0f;
            color.unkC = 1.0f;
            ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(pos, vel, rand2, color, -2000.0f);
            i += 1;
        } while (i < 0xA);
    }
    if ((u8) this->unk1AC != 0) {
        Shatterable::Message(arg0);
        return;
    }
    i = arg0->unk0;
    if ((i != 4) && (i != 1) && (i != 5)) {
        Shatterable::Message(arg0);
    }
}

void *BarricadeProp::Update() {
    Shatterable::Update();
}

f32 BarricadeProp::Resolve() {
    Shatterable::Resolve();
}

s32 BarricadeProp::LoadDone() {
    Shatterable::LoadDone();
    if ((s32) this->unk180 > 0) {
        this->unk1AC = 1;
    }
}

void BarricadeProp::Deinit() {
    Shatterable::Deinit();
}

void BarricadeProp::Init() {
    this->unk1A8 = 0;
    this->unk1AC = 0;
    Shatterable::Init();
}
