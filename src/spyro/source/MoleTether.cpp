#include "spyro/source/MoleTether.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/AITargetData.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/BoneBlurFX.h"
#include "spyro/source/Character.h"
#include "spyro/source/CharacterBodyFX.h"
#include "spyro/source/CharacterBreathFX.h"
#include "spyro/source/CharacterFireFX.h"
#include "spyro/source/CharacterGraph.h"
#include "spyro/source/CharacterZapFX.h"
#include "spyro/source/CollisionObject.h"
#include "spyro/source/Crate.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyAttackPattern.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EnemyRegion.h"
#include "spyro/source/EnemySettings.h"
#include "spyro/source/EnergyBeam.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/Goal.h"
#include "spyro/source/IceBitsPS.h"
#include "spyro/source/KDFaderObject.h"
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/KDPositionProperty.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/Level.h"
#include "spyro/source/MeleeTrails.h"
#include "spyro/source/MiningMole.h"
#include "spyro/source/NPCGoal_Think.h"
#include "spyro/source/Names.h"
#include "spyro/source/NodeLookAt.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/SB2.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/SpawnPointObject.h"
#include "spyro/source/SpawnerObject.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

extern s32 GS_MoleExtra2;
extern MKSceneManager *gMK;

void MoleTether::SetWorldMatrix(Matrix &arg0) {
    MKModel_SetWorldMatrix(this->unk4, arg0);
}

void MoleTether::Shatter(bool arg0, MKVector3 *arg1, int arg2, MKVector3 *arg3, bool arg4) {
    if (this->unk1F4 != NULL) {
        MoleTetherDescriptor *desc = checked_cast<MoleTetherDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        EnergyBeam *beam = (EnergyBeam *) M2C_FIELD(desc, EnergyBeam **, 0x16C);
        beam->FreeEnergyBeam(this->unk1F4);
        this->unk1F4 = NULL;
    }
    this->unk1FC = 0;
    Shatterable::Shatter(arg0, arg1, arg2, arg3, arg4, 0U);
}

#if 0 // DRAFT: ')' expected
void MoleTether::Message(MKMessage *arg0) {
    f64 sp10;
    f64 sp8;
    MiningMole *temp_r3_150;
    f64 temp_f0_155;
    f64 temp_f1_154;
    s32 temp_r0_112;
    s32 temp_r4_125;
    u32 temp_r4_159;
    void *temp_r3_153;
    void *temp_r3_169;

    ((KDSoundPlayer *) &this->unk1C8)->Message(arg0);
    temp_r0_112 = arg0->unk0;
    switch (temp_r0_112) {                          /* irregular */
    case 0xBE:
        if (((s32) this->unk16C != 0) && ((temp_r4_125 = this->unk180, ((temp_r4_125 == (s32) M2C_FIELD(checked_cast<MoleTetherDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x160)) == 0)) || ((s32) *(this->unk168 + (((temp_r4_125 - 1) << 7) + 0x44)) != 2))) {
            this->unk1FC = 1;
            if ((EnergyBeam::Beam *) this->unk1F4 != NULL) {
                ((EnergyBeam *) (M2C_FIELD(checked_cast<MoleTetherDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), EnergyBeam **, 0x16C)))->FreeEnergyBeam(this->unk1F4);
                this->unk1F4 = NULL;
            }
            temp_r3_150 = this->unk1F0;
            if (temp_r3_150 != NULL) {
                temp_r3_153 = temp_r3_150->unk8;
                temp_f1_154 = M2C_FIELD(temp_r3_153, f64 *, 0x30);
                temp_f0_155 = M2C_FIELD(temp_r3_153, f64 *, 0x38);
                sp8 = temp_f1_154;
                this->unk1B8 = temp_f1_154;
                this->unk1C0 = temp_f0_155;
                temp_r4_159 = this->unk1F8;
                sp10 = temp_f0_155;
                if (temp_r4_159 != -1U) {
                    MKModel_CalculateRefPointWorldPosition(this->unk4, (s32) temp_r4_159, &this->unk1A8);
                } else {
                    temp_r3_169 = this->unk8;
                    M2C_FIELD(this, f64 *, 0x1A8) = (f64) M2C_FIELD(temp_r3_169, f64 *, 0x30);
                    M2C_FIELD(this, f64 *, 0x1B0) = (f64) M2C_FIELD(temp_r3_169, f64 *, 0x38);
                }
                ((EnergyBeam *) (M2C_FIELD(checked_cast<MoleTetherDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), EnergyBeam **, 0x16C)))->SpawnEnergyBeam(&this->unk1A8, (MKVector3 *) &this->unk1B8, 1.0f);
                this->unk1F4 = M2C_ERROR(/* Read from unset register $r3 */);
            }
        }
        break;
    case 0xBF:
        this->unk1FC = 0;
        if ((EnergyBeam::Beam *) this->unk1F4 != NULL) {
            ((EnergyBeam *) (M2C_FIELD(checked_cast<MoleTetherDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), EnergyBeam **, 0x16C)))->FreeEnergyBeam(this->unk1F4);
            this->unk1F4 = NULL;
        }
        break;
    }
    Shatterable::Message(arg0);
}
#endif

void MoleTether::Deinit() {
    if (this->unk1F4 != NULL) {
        MoleTetherDescriptor *desc = checked_cast<MoleTetherDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        EnergyBeam *beam = (EnergyBeam *) M2C_FIELD(desc, EnergyBeam **, 0x16C);
        beam->FreeEnergyBeam(this->unk1F4);
        this->unk1F4 = NULL;
    }
    KDSound_Stop((int *) &this->unk1C8);
    Shatterable::Deinit();
}

void *MoleTether::Update() {
    f64 sp18;
    f64 sp10;
    s32 sp8;
    MiningMole *temp_r3_247;
    f64 temp_f0_252;
    f64 temp_f1_251;
    void *temp_r3_250;

    Shatterable::Update();
    temp_r3_247 = this->unk1F0;
    if (temp_r3_247 != NULL) {
        temp_r3_250 = temp_r3_247->unk8;
        temp_f1_251 = M2C_FIELD(temp_r3_250, f64 *, 0x30);
        temp_f0_252 = M2C_FIELD(temp_r3_250, f64 *, 0x38);
        sp10 = temp_f1_251;
        this->unk1B8 = temp_f1_251;
        sp18 = temp_f0_252;
        this->unk1C0 = temp_f0_252;
    }
    sp8 = 1;
    ((KDSoundFader *) &this->unk1C8)->Update(GS_MoleExtra2, 1U, this->unk1FC, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
}

s32 MoleTether::LoadDone() {
    Shatterable::LoadDone();
    this->unk1F8 = (u32) Tools_GetMatchingRefPointIndex(this->unk4, "fxemit0");
}

void MoleTether::Init() {
    Shatterable::Init();
    this->unk1F4 = NULL;
    this->unk1F0 = NULL;
    this->unk1F8 = 0xFFFF;
    ((KDSoundFader *) &this->unk1C8)->Init(0.25f, 0.25f);
    this->unk1FC = 0;
}

void MoleTetherDescriptor::LoadDone() {
    ShatterableDescriptor::LoadDone();
    MKProp *prop = gMK->CreateProp("EnergyBeam");
    EnergyBeam *beam = checked_cast<EnergyBeam *, MKProp>(prop);
    M2C_FIELD(this, EnergyBeam **, 0x16C) = beam;
}
