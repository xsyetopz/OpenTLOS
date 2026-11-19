#include "spyro/source/ScryingPool.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "spyro/source/KDPropEx.h"
#include "unplaced_templates.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

extern s32 GS_PLACEHOLDER;
extern M2C_UNK gb;
#if 0 // DRAFT: function call 'KDSound_Stop(long *)' does not match
static s8 lit_stringBase0[0x1A] = {
    0x6E,
    0x6F,
    0x72,
    0x6D,
    0x61,
    0x6C,
    0x53,
    0x6F,
    0x75,
    0x6E,
    0x64,
    0,
    0x63,
    0x75,
    0x74,
    0x73,
    0x63,
    0x65,
    0x6E,
    0x65,
    0x53,
    0x6F,
    0x75,
    0x6E,
    0x64,
    0,
}; /* const */

void ScryingPool::Deinit() {
    KDSound_Stop(&this->unk98);
    KDPropEx::Deinit();
}
#endif

#if 0 // DRAFT: expression syntax error
void ScryingPool::Message(MKMessage *arg0) {
    this->unk98.Message(arg0);
    KDPropEx::Message(arg0);
}
#endif

#if 0 // DRAFT: expression syntax error
void ScryingPool::Update() {
    s32 sp8;
    s32 temp_r4_104;
    u8 var_r30_154;
    u8 var_r30_184;

    KDPropEx::Update();
    temp_r4_104 = this->unk94;
    if (temp_r4_104 != 0) {
        sp8 = 1;
        this->unk98.Update(temp_r4_104, 1U, temp_r4_104 == this->unk90, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    }
    if (((s32) this->unk94 != (s32) this->unk90) && (KDSound_IsVoicePlaying(this->unk98) == 0)) {
        this->unk94 = this->unk90;
    }
    if (((s32) this->unk94 == 0) && ((s32) this->unk90 == 0) && ((s32) M2C_FIELD(checked_cast<ScryingPoolDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xC0) != 0)) {
        this->unk90 = M2C_FIELD(checked_cast<ScryingPoolDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xC0);
    }
    if ((void *) M2C_FIELD(&gb, void **, 0xC) != NULL) {
        var_r30_154 = 0;
        if ((((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x78) != 0U) || ((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x84) != 0U)) && (((KDStateMachine<CutsceneSystem> *) (M2C_FIELD(&gb, void **, 0xC) + 0x24))->GetState() != 0)) {
            var_r30_154 = 1;
        }
        if ((var_r30_154 != 0) && ((s32) this->unk90 != (s32) M2C_FIELD(checked_cast<ScryingPoolDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xC4))) {
            this->unk90 = M2C_FIELD(checked_cast<ScryingPoolDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xC4);
        }
    }
    if ((void *) M2C_FIELD(&gb, void **, 0xC) != NULL) {
        var_r30_184 = 0;
        if ((((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x78) != 0U) || ((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x84) != 0U)) && (((KDStateMachine<CutsceneSystem> *) (M2C_FIELD(&gb, void **, 0xC) + 0x24))->GetState() != 0)) {
            var_r30_184 = 1;
        }
        if (var_r30_184 == 0) {
            goto block_23;
        }
    } else {
block_23:
        if ((s32) this->unk90 != (s32) M2C_FIELD(checked_cast<ScryingPoolDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xC0)) {
            this->unk90 = M2C_FIELD(checked_cast<ScryingPoolDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xC0);
        }
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void ScryingPool::Init() {
    KDPropEx::Init();
    this->unk98.Init(0.25f, 0.25f);
    this->unk90 = GS_PLACEHOLDER;
    this->unk94 = GS_PLACEHOLDER;
}
#endif

#if 0 // DRAFT: function call 'KDSound_LoadLine(MKIniLine *, signed char[26], long *)'
s32 ScryingPoolDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_251;

    var_r31_251 = 0;
    if ((KDPropExDescriptor::LoadLine(arg0) != 0) || (KDSound_LoadLine(arg0, lit_stringBase0, &this->unkC0) != 0) || (KDSound_LoadLine(arg0, &lit_stringBase0[0xC], &this->unkC4) != 0)) {
        var_r31_251 = 1;
    }
    return var_r31_251;
}
#endif

void ScryingPoolDescriptor::Init() {
    KDPropExDescriptor::Init();
    this->unkC0 = GS_PLACEHOLDER;
    this->unkC4 = GS_PLACEHOLDER;
}

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<ScryingPoolDescriptor *, MKPropDescriptor>(MKPropDescriptor *arg0) {

}
#endif
