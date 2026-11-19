#include "spyro/source/Kane.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKIni.h"
#include "spyro/source/CharacterGraph.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/KaneGoal_Think.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to
s32 Kane::LoadLine(MKIniLine *arg0) {
    if ((Enemy::LoadLine(arg0) != 0) || (arg0->LoadBool("StartEnabled", (u8 *) &this->unkAFC, 0) != 0) || (arg0->LoadInt("StartNode", &this->unkAF8, 0) != 0)) {
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'CharacterGraphNodeProp *' to
void Kane::Resolve() {
    s32 spC;
    s32 sp8;
    u32 temp_r3_91;

    Enemy::Resolve();
    temp_r3_91 = checked_cast<CharacterGraphNodeProp *, MKProp>(((MKSceneManager *) this->unkAF8)->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */)));
    if (temp_r3_91 != 0U) {
        this->unkA68 = M2C_BITWISE(f32, (temp_r3_91 + 0x50));
    }
    M2C_FIELD(this->unkA24, s8 *, 8) = 1;
    if ((u8) M2C_FIELD(this, u8 *, 0xB14) == 0) {
        spC = 0;
        sp8 = 0xBF;
        Message(&sp8);
        Disable();
    }
}
#endif

#if 0 // DRAFT: function call 'operator new(unsigned int, int, int)' does not match
void Kane::Init() {
    KaneGoal_Think *temp_r31_139;

    Enemy::Init();
    operator new(0x2CU, NULL, 0);
    temp_r31_139 = M2C_ERROR(/* Read from unset register $r3 */);
    if (temp_r31_139 != NULL) {
        temp_r31_139->__vptr = &__vt__12Goal<5Enemy>;
        temp_r31_139->unk4 = 0;
        temp_r31_139->unk8 = 1;
        temp_r31_139->unk9 = 0;
        temp_r31_139->unkC = 0;
        temp_r31_139->__vptr = &__vt__21CompositeGoal<5Enemy>;
        temp_r31_139->unk1C = 0;
        temp_r31_139->unk18 = 0;
        temp_r31_139->unk10 = 0;
        temp_r31_139->unk14 = 0;
        temp_r31_139->__vptr = &__vt;
    }
    temp_r31_139->Init((Enemy *) this);
    this->unkA24 = (EnemyAttack *) temp_r31_139;
    M2C_FIELD(this, s8 *, 0xB14) = 0;
    this->unkAF8 = 0;
}
#endif
