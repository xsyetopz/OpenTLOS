#include "spyro/source/KnifeTrap.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/Trap.h"
#include "spyro/source/PropFlags.h"
#include <m2c_macros.h>

void KnifeTrap::Update() {
    GameProp::Update();
    if (this->unk10 & 0x20000) {

    }
}

#if 0 // DRAFT: function call 'PropFlagsSet(unsigned long *, unsigned int)' does not match
void KnifeTrap::Reset() {
    PropFlagsSet((u32 *) &this->unk10, 0x80000U);
    Trap::Reset();
}
#endif

void KnifeTrapDescriptor::Init() {
    TrapDescriptor::Init();
    this->unkC = 0x12;
}
