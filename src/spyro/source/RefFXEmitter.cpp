#include "spyro/source/RefFXEmitter.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
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
#include "spyro/source/Steam.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include "common/Source/Str.h"
#include <m2c_macros.h>

extern MKSceneManager *gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;

void RefFXEmitter::Message(MKMessage *arg0) {
    KDProp::Message(arg0);
}

#if 0 // DRAFT: ')' expected
void *RefFXEmitter::Update() {
    Matrix sp60;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f32 temp_f2_71;
    f32 temp_f31_137;
    f64 temp_f0_151;
    u8 var_r0_70;
    void *temp_r31_132;

    KDProp::Update();
    var_r0_70 = 0;
    temp_f2_71 = this->unk90;
    if (temp_f2_71 == 0.0f) {
        this->unk94 = MKRand_Int((int *) &gViewSeed, 0, M2C_FIELD(checked_cast<RefFXEmitterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x98));
        this->unk90 = MKRand_Float((int *) &gViewSeed, 0.2f, 0.8f);
        var_r0_70 = 1;
    } else if (temp_f2_71 > 0.0f) {
        this->unk90 = temp_f2_71 - gUpdateTimeDelta;
        if (this->unk90 <= 0.0f) {
            this->unk90 = MKRand_Float((int *) &gViewSeed, -1.0f, -0.2f);
        }
        var_r0_70 = 1;
    } else {
        this->unk90 = temp_f2_71 + gUpdateTimeDelta;
        if (this->unk90 > 0.0f) {
            this->unk90 = 0.0f;
        }
    }
    if (var_r0_70 != 0) {
        MKModel_GetRefPointMatrix(this->unk4, M2C_FIELD((checked_cast<RefFXEmitterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (this->unk94 * 4)), s32 *, 0x70), &sp60, 1U);
        temp_r31_132 = checked_cast<RefFXEmitterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        temp_f31_137 = MKRand_Float((int *) &gViewSeed, -700.0f, -300.0f);
        sp28 = -sp60.unk10;
        sp2C = -sp60.unk14;
        sp30 = -sp60.unk18;
        sp38 = (f64) sp28;
        sp40 = (f64) sp30;
        temp_f0_151 = sp38 * (f64) temp_f31_137;
        sp18 = temp_f0_151;
        sp48 = temp_f0_151;
        sp20 = (f32) sp40 * temp_f31_137;
        sp50 = (f64) sp20;
        sp10 = MKRand_Float((int *) &gViewSeed, 2.0f, 5.0f);
        ((Steam *) (M2C_FIELD(temp_r31_132, Steam **, 0x9C)))->Emit(*((MKVector3 *) &sp60.unk30), *((MKVector3 *) &sp48), sp10);
    }
}
#endif

s32 RefFXEmitter::LoadDone() {
    KDProp::LoadDone();
}

s32 RefFXEmitter::LoadLine(MKIniLine *arg0) {
    KDProp::LoadLine(arg0);
}

void RefFXEmitter::Deinit() {
    KDProp::Deinit();
}

void RefFXEmitter::Init() {
    KDProp::Init();
    this->unk90 = 0.0f;
    this->unk94 = 0;
}

#if 0 // DRAFT: function call 'MKModel_RefPointExists(MKModel *, signed char *, int *)' does not match 'MKModel_RefPointExists(const MKModel *, const char *, int *)'
void RefFXEmitterDescriptor::Resolve() {
    s32 sp8;
    s32 temp_r3_257;

    MKPropDescriptor::Resolve();
    sp8 = -1;
    this->unk98 = 0;
loop_2:
    if (MKModel_RefPointExists(this->unk2C, Str_Printf("r_fxemit%d", this->unk98), (int *) &sp8) != 0) {
        temp_r3_257 = this->unk98;
        this->unk98 = temp_r3_257 + 1;
        *(this + ((temp_r3_257 * 4) + 0x70)) = sp8;
        goto loop_2;
    }
    this->unk9C = (long) (checked_cast<Steam *, MKProp>(gMK->CreateProp("Steam")));
}
#endif
