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

#if 0 // DRAFT: illegal implicit conversion from 'const char[6]' to
void ArrowTrap::Message(MKMessage *arg0) {
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp8;
    MKVector3 *temp_r30_74;
    f32 temp_f3_85;
    s32 var_r29_67;

    if ((s32) arg0->unk0 != 0xB5) {

    } else {
        ((Arrow *) (((MKPropDescriptor *) (M2C_FIELD(*gMK, MKPropDescriptor *(**)(void **, M2C_UNK *), 0x5C)(gMK, "Arrow")))->CreateInstance()))->Fire(*((Matrix *) this->unk8), 1000.0f, 4.0f);
        var_r29_67 = 0;
        do {
            temp_r30_74 = this->unk8 + 0x30;
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            temp_f3_85 = M2C_FIELD((this->unk8 + 0x20), f32 *, 8) * MKRand_Float(&gViewSeed, -700.0f, -300.0f);
            sp20 = sp10;
            sp18 = temp_f3_85;
            sp28 = (f64) sp18;
            sp8 = MKRand_Float(&gViewSeed, 0.5f, 1.0f);
            gb.EmitDust(*temp_r30_74, *((MKVector3 *) &sp20), sp8, 0.0f);
            var_r29_67 += 1;
        } while (var_r29_67 < 6);
    }
    Trap::Message(arg0);
}
#endif

#if 0 // DRAFT: function call 'PropFlagsSet(unsigned long *, unsigned int)' does not match
void ArrowTrap::Reset() {
    PropFlagsSet((u32 *) &this->unk10, 0x80000U);
    Trap::Reset();
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void ArrowTrapDescriptor::Init() {
    TrapDescriptor::Init();
    this->unkC = 0x12;
}
#endif
