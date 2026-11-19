#include "spyro/source/ArrowTrap.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Arrow.h"
#include "spyro/source/Game.h"
#include "spyro/source/Trap.h"
#include "common/Source/StdMath.h"
#include "spyro/source/PropFlags.h"
#include <m2c_macros.h>

extern void **gMK;
extern s32 gViewSeed;
extern GameGlobals gb;

void ArrowTrap::Message(MKMessage *arg0) {
    s32 i;
    f32 sp8;
    MKVector3 pos;
    MKVector3 vel;

    if ((s32) arg0->unk0 == 0xB5) {
        ((Arrow *) (((MKPropDescriptor *) (M2C_FIELD(*gMK, MKPropDescriptor *(**)(void **, const char *), 0x5C)(gMK, "Arrow")))->CreateInstance()))->Fire(*((Matrix *) this->unk8), 1000.0f, 4.0f);
        for (i = 0; i < 6; i++) {
            pos = *((MKVector3 *) ((u8 *) this->unk8 + 0x30));
            f32 speed = MKRand_Float((int *) &gViewSeed, -700.0f, -300.0f);
            MKVector3 *dir = (MKVector3 *) ((u8 *) this->unk8 + 0x20);
            vel.unk0 = dir->unk0 * speed;
            vel.unk4 = dir->unk4 * speed;
            vel.unk8 = dir->unk8 * speed;
            sp8 = MKRand_Float((int *) &gViewSeed, 0.5f, 1.0f);
            gb.EmitDust(pos, vel, sp8, 0.0f);
        }
    }
    Trap::Message(arg0);
}

void ArrowTrap::Reset() {
    PropFlagsSet((unsigned int *) &this->unk10, 0x80000U);
    Trap::Reset();
}

void ArrowTrapDescriptor::Init() {
    TrapDescriptor::Init();
    this->unkC = 0x12;
}
