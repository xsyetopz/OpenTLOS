#include "spyro/source/ExplosiveBarrelSpawner.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "spyro/source/ExplosiveBarrel.h"
#include "spyro/source/GameProp.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

extern MKSceneManager *gMK;
static s8 lit_stringBase0[0x10] = {
    0x45,
    0x78,
    0x70,
    0x6C,
    0x6F,
    0x73,
    0x69,
    0x76,
    0x65,
    0x42,
    0x61,
    0x72,
    0x72,
    0x65,
    0x6C,
    0,
}; /* const */

void ExplosiveBarrelSpawner::Update() {
    void *temp_r3_44;
    void *temp_r3_53;
    void *temp_r3_58;

    temp_r3_44 = this->unkC8;
    if ((temp_r3_44 != NULL) && (M2C_FIELD(M2C_FIELD(temp_r3_44, void **, 0x44), u8 (**)(), 0xB8)() != 0)) {
        temp_r3_53 = this->unkC8;
        M2C_FIELD(M2C_FIELD(temp_r3_53, void **, 0x44), M2C_UNK (**)(void *), 0x20)(temp_r3_53);
        temp_r3_58 = this->unkC8;
        M2C_FIELD(M2C_FIELD(temp_r3_58, void **, 0x44), M2C_UNK (**)(void *), 0x30)(temp_r3_58);
    }
}

#if 0 // DRAFT: ')' expected
void ExplosiveBarrelSpawner::LoadDone() {
    MKProp *temp_r3_87;
    s32 var_r30_81;

    GameProp::LoadDone();
    var_r30_81 = 0;
loop_2:
    if (var_r30_81 < (s32) M2C_FIELD(checked_cast<ExplosiveBarrelSpawnerDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xE4)) {
        temp_r3_87 = gMK->CreateProp(lit_stringBase0);
        this->unkC8 = checked_cast<ExplosiveBarrel *, MKProp>(temp_r3_87);
        temp_r3_87->Enable();
        var_r30_81 += 1;
        goto loop_2;
    }
}
#endif

#if 0 // DRAFT: identifier 'ExplosiveBarrelSpawnerDescriptor::LoadLine(MKIniLine *)'
void ExplosiveBarrelSpawnerDescriptor::LoadLine(MKIniLine *arg0) {
    GamePropDescriptor::LoadLine(arg0);
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void ExplosiveBarrelSpawnerDescriptor::Init() {
    GamePropDescriptor::Init();
    this->unkE4 = 1;
}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<ExplosiveBarrelSpawnerDescriptor *, MKPropDescriptor>(MKPropDescriptor *arg0) {

}
#endif
