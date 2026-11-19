#include "spyro/source/FightElevatorAnchor.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKSceneManager'
void FightElevatorAnchor::Update() {
    FightElevatorAnchor *spC;
    s32 sp8;
    void *temp_r3_51;

    Shatterable::Update();
    if ((s32) this->unk17C != 3) {
        temp_r3_51 = this->unk1A8->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */));
        if (temp_r3_51 != NULL) {
            spC = NULL;
            sp8 = 0x94;
            spC = this;
            M2C_FIELD(M2C_FIELD(temp_r3_51, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
        }
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void FightElevatorAnchor::GetZapAnchorPos() {
    MKVector3 sp8;

    MKModel_CalculateRefPointWorldPosition(M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), MKModel **, 4), M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), s32 *, 0x1AC), &sp8);
    M2C_FIELD(this, f64 *, 0) = M2C_BITWISE(f64, sp8);
    M2C_FIELD(this, f64 *, 8) = (f64) sp8.unk8;
}
#endif

void FightElevatorAnchor::LoadDone() {
    Shatterable::LoadDone();
    this->unk1AC = (s32) Tools_GetMatchingRefPointIndex(this->unk4, "fxemit0");
}

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
s32 FightElevatorAnchor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_126;

    var_r31_126 = 0;
    if ((Shatterable::LoadLine(arg0) != 0) || (arg0->LoadInt("TargetID", (s32 *) &this->unk1A8, 0) != 0)) {
        var_r31_126 = 1;
    }
    return var_r31_126;
}
#endif

void FightElevatorAnchor::Init() {
    Shatterable::Init();
    this->unk1A8 = NULL;
}
