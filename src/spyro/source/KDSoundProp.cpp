#include "spyro/source/KDSoundProp.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "spyro/source/KDSound.h"
#include "common/Source/StdMath.h"
#include "common/gc/Sound_GC.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void KDSoundProp::Play() {
    s32 sp8;

    sp8 = 1;
    ((KDSoundPlayer *) &this->unkA0)->Update(this->unk50, 0U, 1U, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    this->unk54 = MKRand_Float(&gViewSeed, this->unk58, this->unk5C);
}
#endif

#if 0 // DRAFT: function call 'KDSound_Stop(long *)' does not match
void KDSoundProp::Message(MKMessage *arg0) {
    if ((s32) arg0->unk0 != -4) {

    } else if ((s32) this->unk4C != 0) {
        KDSound_Stop(&this->unkA0);
        this->unk4C = 1;
    }
    MKProp::Message(arg0);
}
#endif

void KDSoundProp::Update() {
    s32 sp8;
    s32 temp_r0_79;
    s32 temp_r3_110;

    temp_r0_79 = this->unk4C;
    switch (temp_r0_79) {                           /* irregular */
    case 1:
        Play();
        if ((s32) this->unkA0 > 0) {
            this->unk4C = 2;
            return;
        }
        return;
    case 2:
        sp8 = 1;
        ((KDSoundPlayer *) &this->unkA0)->Update(this->unk50, 0U, 1U, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
        temp_r3_110 = this->unkA0;
        if ((temp_r3_110 == 0) || (Sound_IsVoicePlaying(temp_r3_110) == 0)) {
            this->unkA0 = 0;
            this->unk4C = 3;
            return;
        }
        break;
    case 3:
        this->unk54 -= gUpdateTimeDelta;
        if (this->unk54 <= 0.0f) {
            this->unk4C = 1;
        }
        break;
    }
}

#if 0 // DRAFT: function call 'KDSound_Stop(long *)' does not match
void KDSoundProp::Reset() {
    MKProp::Reset();
    KDSound_Stop(&this->unkA0);
    this->unk54 = 0.0f;
    this->unk4C = 1;
}
#endif

void KDSoundProp::LoadDone() {
    MKProp::LoadDone();
    M2C_STRUCT_COPY((s32) &this->unk5C + 4, (s32) (&MKProp::loadInfo - 4) + 4, 0x40);
}

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to
s32 KDSoundProp::LoadLine(MKIniLine *arg0) {
    s8 *sp8;
    s32 var_r30_238;

    if (MKProp::LoadLine(arg0) != 0) {
        return 1;
    }
    if (arg0->LoadString("sound", &sp8, 0) != 0) {
        if ((s32) (u8) *sp8 == 0x2A) {
            sp8 += 1;
        }
        this->unk50 = KDSound_ResolveSound(sp8, NULL);
        return 1;
    }
    if (arg0->LoadString("dummySphere", &sp8, 0) != 0) {
        var_r30_238 = 1;
    } else {
        var_r30_238 = 0;
        if ((arg0->LoadFloat("minDelay", &this->unk58, 0) != 0) || (arg0->LoadFloat("maxDelay", &this->unk5C, 0) != 0)) {
            var_r30_238 = 1;
        }
    }
    return var_r30_238;
}
#endif

#if 0 // DRAFT: function call 'KDSound_Stop(long *)' does not match
void KDSoundProp::Deinit() {
    MKProp::Deinit();
    KDSound_Stop(&this->unkA0);
}
#endif

void KDSoundProp::Init() {
    MKProp::Init();
    this->unk50 = 0;
    this->unk4C = 1;
    this->unk5C = 0.0f;
    this->unk58 = 0.0f;
    this->unk54 = 0.0f;
    this->unkA0 = 0;
    this->unk60.SetIdentity();
    this->unk8 = &this->unk60;
}

void KDSoundPropDescriptor::Init() {
    MKPropDescriptor::Init();
    this->unk7C &= 0xFFFFFFF8;
    M2C_FIELD(this, f32 *, 0x60) = -5.0f;
    this->unk64 = -5.0f;
    this->unk68 = -5.0f;
    this->unk70 = 10.0f;
    this->unk74 = 10.0f;
    this->unk78 = 10.0f;
    this->unk1C = (BoundingVolume *) &this->unk60;
}
