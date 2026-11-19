#include "spyro/source/MoleTether.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/EnergyBeam.h"
#include "spyro/source/Shatterable.h"
#include "unplaced_templates.h"
#include "common/Source/MKModel.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

extern s32 GS_MoleExtra2;
extern MKSceneManager *gMK;

void MoleTether::SetWorldMatrix(Matrix &arg0) {
    MKModel_SetWorldMatrix(this->unk4, arg0);
}

#if 0 // DRAFT: undefined identifier 'unk1F4'
void MoleTether::Shatter(bool arg0, MKVector3 *arg1, int arg2, MKVector3 *arg3, bool arg4) {
    if ((EnergyBeam::Beam *) this->unk1F4 != NULL) {
        ((EnergyBeam *) (M2C_FIELD(checked_cast<MoleTetherDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), EnergyBeam **, 0x16C)))->FreeEnergyBeam(this->unk1F4);
        this->unk1F4 = NULL;
    }
    this->unk1FC = 0;
    Shatterable::Shatter(arg0, arg1, arg2, arg3, arg4, 0U);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk1B8'
void MoleTether::Message(MKMessage *arg0) {
    f64 sp10;
    f64 sp8;
    MKProp *temp_r4_125;
    f64 temp_f0_155;
    f64 temp_f1_154;
    s32 temp_r0_112;
    u32 temp_r4_159;
    void *temp_r3_150;
    void *temp_r3_153;
    void *temp_r3_169;

    this->unk1B8.Message(arg0);
    temp_r0_112 = arg0->unk0;
    switch (temp_r0_112) {                          /* irregular */
    case 0xBE:
        if (((s32) this->unk15C.unk0 != 0) && ((temp_r4_125 = this->unk170, ((temp_r4_125 == (s32) M2C_FIELD(checked_cast<MoleTetherDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x160)) == 0)) || ((s32) *(this->unk158 + (((s32) (temp_r4_125 - 1) << 7) + 0x44)) != 2))) {
            this->unk1FC = 1;
            if ((EnergyBeam::Beam *) this->unk1F4 != NULL) {
                ((EnergyBeam *) (M2C_FIELD(checked_cast<MoleTetherDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), EnergyBeam **, 0x16C)))->FreeEnergyBeam(this->unk1F4);
                this->unk1F4 = NULL;
            }
            temp_r3_150 = this->unk1F0;
            if (temp_r3_150 != NULL) {
                temp_r3_153 = M2C_FIELD(temp_r3_150, void **, 8);
                temp_f1_154 = M2C_FIELD(temp_r3_153, f64 *, 0x30);
                temp_f0_155 = M2C_FIELD(temp_r3_153, f64 *, 0x38);
                sp8 = temp_f1_154;
                M2C_FIELD(this, f64 *, 0x1B8) = temp_f1_154;
                M2C_FIELD(this, f64 *, 0x1C0) = temp_f0_155;
                temp_r4_159 = this->unk1F8;
                sp10 = temp_f0_155;
                if (temp_r4_159 != -1U) {
                    MKModel_CalculateRefPointWorldPosition(this->unk4, (s32) temp_r4_159, (MKVector3 *) &this->unk198);
                } else {
                    temp_r3_169 = this->unk8;
                    M2C_FIELD(this, f64 *, 0x1A8) = (f64) M2C_FIELD(temp_r3_169, f64 *, 0x30);
                    M2C_FIELD(this, f64 *, 0x1B0) = (f64) M2C_FIELD(temp_r3_169, f64 *, 0x38);
                }
                ((EnergyBeam *) (M2C_FIELD(checked_cast<MoleTetherDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), EnergyBeam **, 0x16C)))->SpawnEnergyBeam((MKVector3 *) &this->unk198, &this->unk1A8, 1.0f);
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

#if 0 // DRAFT: expression syntax error
void MoleTether::Deinit() {
    if ((EnergyBeam::Beam *) this->unk1F4 != NULL) {
        ((EnergyBeam *) (M2C_FIELD(checked_cast<MoleTetherDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), EnergyBeam **, 0x16C)))->FreeEnergyBeam(this->unk1F4);
        this->unk1F4 = NULL;
    }
    KDSound_Stop((s32 *) &this->unk1B8);
    Shatterable::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'unk1F0'
void MoleTether::Update() {
    f64 sp18;
    f64 sp10;
    s32 sp8;
    f64 temp_f0_252;
    f64 temp_f1_251;
    void *temp_r3_247;
    void *temp_r3_250;

    Shatterable::Update();
    temp_r3_247 = this->unk1F0;
    if (temp_r3_247 != NULL) {
        temp_r3_250 = M2C_FIELD(temp_r3_247, void **, 8);
        temp_f1_251 = M2C_FIELD(temp_r3_250, f64 *, 0x30);
        temp_f0_252 = M2C_FIELD(temp_r3_250, f64 *, 0x38);
        sp10 = temp_f1_251;
        M2C_FIELD(this, f64 *, 0x1B8) = temp_f1_251;
        sp18 = temp_f0_252;
        M2C_FIELD(this, f64 *, 0x1C0) = temp_f0_252;
    }
    sp8 = 1;
    this->unk1B8.Update(GS_MoleExtra2, 1U, this->unk1FC, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
}
#endif

#if 0 // DRAFT: undefined identifier 'unk1F8'
void MoleTether::LoadDone() {
    Shatterable::LoadDone();
    this->unk1F8 = (u32) Tools_GetMatchingRefPointIndex(this->unk4, "fxemit0");
}
#endif

#if 0 // DRAFT: undefined identifier 'unk1F4'
void MoleTether::Init() {
    Shatterable::Init();
    this->unk1F4 = NULL;
    this->unk1F0 = NULL;
    this->unk1F8 = 0xFFFFU;
    this->unk1B8.Init(0.25f, 0.25f);
    this->unk1FC = 0;
}
#endif

#if 0 // DRAFT: expression syntax error
void MoleTetherDescriptor::LoadDone() {
    ShatterableDescriptor::LoadDone();
    this->unk16C = checked_cast<EnergyBeam *, MKProp>(gMK->CreateProp("EnergyBeam"));
}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<MoleTetherDescriptor *, MKPropDescriptor>(MKPropDescriptor *arg0) {

}
#endif
