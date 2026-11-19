#include "spyro/source/FuryFX.h"
#include "common/Source/MKProp.h"
#include "spyro/source/KDProp.h"
#include <m2c_macros.h>

void FuryFX::SetDefaults() {

}

void FuryFX::Deinit() {
    KDProp::Deinit();
}

void FuryFX::Draw() {

}

void FuryFX::Update() {

}

void FuryFX::Resolve() {
    MKProp::Resolve();
}

void FuryFX::Init() {
    KDProp::Init();
}
