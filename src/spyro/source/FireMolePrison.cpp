#include "spyro/source/FireMolePrison.h"
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
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/FireMolePrisonDescriptor.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDPositionProperty.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/SpawnPointObject.h"
#include "spyro/source/SpawnerObject.h"
#include "spyro/source/TargetManager.h"
#include "spyro/source/shatterwaypointspawn.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

extern s32 GS_MoleHelpMe;
extern s32 GS_MoleScurry;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;

void FireMolePrison::Message(MKMessage *arg0) {
    f64 pos[2];
    struct {
        s32 type;
        s32 unk4;
        f64 x;
        f64 y;
    } msg;
    FireMolePrisonDescriptor *desc;
    MKProp *temp_r3_74;
    s32 var_r30_52;
    s32 var_r31_53;
    void *temp_r6_60;

    if ((s32) arg0->unk0 != 0xBA) {
    } else {
        var_r31_53 = 0;
        var_r30_52 = 0;
        while (var_r31_53 < (s32) this->unk1FC) {
            temp_r6_60 = ((u8 *) this->unk1F8) + var_r30_52;
            pos[0] = M2C_FIELD(temp_r6_60, f64 *, 0);
            pos[1] = M2C_FIELD(temp_r6_60, f64 *, 8);
            SetSpawnPos(var_r31_53, *((MKVector3 *) pos));
            desc = checked_cast<FireMolePrisonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            temp_r3_74 = this->unk1A8.TrySpawnItem(M2C_FIELD(M2C_FIELD(desc, void **, 0x40), s32 (**)(void *), 0x24)(desc));
            if (temp_r3_74 != NULL) {
                msg.type = 0x98;
                msg.unk4 = 0;
                msg.x = pos[0];
                msg.y = pos[1];
                M2C_FIELD(M2C_FIELD(temp_r3_74, void **, 0x44), void (**)(void *, s32 *, f64), 0x2C)(temp_r3_74, (s32 *) &msg, pos[0]);
            }
            var_r31_53 += 1;
            var_r30_52 += 0x10;
        }
    }
    Shatterable::Message(arg0);
}

void *FireMolePrison::Update() {
    f32 temp_f1_117;

    Shatterable::Update();
    temp_f1_117 = this->unk20C;
    if (temp_f1_117 > 0.0f) {
        this->unk20C = temp_f1_117 - gUpdateTimeDelta;
    }
    if ((IsDead() == 0) && (KDSound_IsVoicePlaying(this->unk208) == 0) && (this->unk20C <= 0.0f)) {
        this->unk20C = MKRand_Float((int *) &gViewSeed, 1.0f, 4.0f);
        this->unk208 = KDSound_Play3d(GS_MoleHelpMe, (const MKVector3 *) ((u8 *) this->unk8 + 0x30), 0U, -1, 0.0f, 0U);
    } else if ((IsDead() != 0) && (KDSound_IsVoicePlaying(this->unk208) != 0)) {
        KDSound_Stop((int *) &this->unk208);
    }
    if ((IsDead() != 0) && ((u8) this->unk210 == 0)) {
        this->unk210 = 1;
        KDSound_Play3d(GS_MoleScurry, (const MKVector3 *) ((u8 *) this->unk8 + 0x30), 0U, -1, 0.0f, 0U);
    }
}

void FireMolePrison::Deinit() {
    KDSound_Stop((int *) &this->unk208);
    ShatterWaypointSpawn::Deinit();
}

void FireMolePrison::Init() {
    ShatterWaypointSpawn::Init();
    this->unk208 = 0;
    this->unk20C = 0.0f;
    this->unk210 = 0;
}
