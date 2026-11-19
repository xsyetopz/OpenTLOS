#include "spyro/source/SparxPath.h"
#include "common/Source/Animation.h"
#include "common/Source/Font.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKFont.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
#include "spyro/source/DialogBox.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/Level.h"
#include "spyro/source/ManagedLight.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/Sparx.h"
#include "spyro/source/SparxFX.h"
#include "spyro/source/SplineProp.h"
#include "spyro/source/TargetManager.h"
#include <m2c_macros.h>

extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern GameGlobals gb;

void SparxPath::Message(MKMessage *arg0) {
    Sparx *temp_r3_77;
    void *spyro;
    s32 temp_r0_58;

    temp_r0_58 = arg0->unk0;
    switch (temp_r0_58) {                           /* irregular */
    case 0xB5:
        spyro = gb.GetSpyro();
        ((Sparx *) (M2C_FIELD(spyro, Sparx **, 0xB70)))->SetPath(this);
        break;
    case 0xB4:
        spyro = gb.GetSpyro();
        temp_r3_77 = (Sparx *) M2C_FIELD(spyro, Sparx **, 0xB70);
        if ((u32) temp_r3_77->unk1F4 == (u32) this) {
            temp_r3_77->SetPath(NULL);
        }
        break;
    }
    MKProp::Message(arg0);
}

f32 SparxPath::Resolve() {
    MKProp::Resolve();
    this->unkC0 *= 100.0f;
}

s32 SparxPath::LoadLine(MKIniLine *arg0) {
    s32 var_r31_123;

    var_r31_123 = 0;
    if ((SplineProp::LoadLine(arg0) != 0) || (arg0->LoadFloat("Speed", &this->unkC0, 0) != 0) || (this->unkC4.LoadLine(arg0, "OnComplete") != 0)) {
        var_r31_123 = 1;
    }
    return var_r31_123;
}

void SparxPath::Deinit() {
    SplineProp::Deinit();
}

void SparxPath::Init() {
    this->unkC0 = 200.0f;
    SplineProp::Init();
}

void SparxPath_cpp::__sinit() {
    f32 temp_f0_217;
    f64 temp_f1_198;
    f64 temp_f1_206;
    f64 temp_f3_186;
    f64 temp_f4_195;
    f64 temp_f4_203;
    f64 temp_f8_188;

    temp_f3_186 = __frsqrte(2014000.0);
    temp_f8_188 = __frsqrte(380000.0);
    temp_f4_195 = 0.5 * temp_f3_186 * -((2014000.0 * (temp_f3_186 * temp_f3_186)) - 3.0);
    temp_f1_198 = 0.5 * temp_f8_188 * -((380000.0 * (temp_f8_188 * temp_f8_188)) - 3.0);
    temp_f4_203 = 0.5 * temp_f4_195 * -((2014000.0 * (temp_f4_195 * temp_f4_195)) - 3.0);
    temp_f1_206 = 0.5 * temp_f1_198 * -((380000.0 * (temp_f1_198 * temp_f1_198)) - 3.0);
    temp_f0_217 = (f32) (380000.0 * (0.5 * temp_f1_206 * -((380000.0 * (temp_f1_206 * temp_f1_206)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_203 * -((2014000.0 * (temp_f4_203 * temp_f4_203)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_217;
}
