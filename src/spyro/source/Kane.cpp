#include "spyro/source/Kane.h"
#include "common/Source/MKIni.h"
#include "spyro/source/CharacterGraph.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/KaneGoal_Think.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier 'unkA04'
static s8 lit_stringBase0[0x17] = {
    0x53,
    0x74,
    0x61,
    0x72,
    0x74,
    0x45,
    0x6E,
    0x61,
    0x62,
    0x6C,
    0x65,
    0x64,
    0,
    0x53,
    0x74,
    0x61,
    0x72,
    0x74,
    0x4E,
    0x6F,
    0x64,
    0x65,
    0,
}; /* const */

s32 Kane::LoadLine(MKIniLine *arg0) {
    if ((Enemy::LoadLine(arg0) != 0) || (arg0->LoadBool(lit_stringBase0, &this->unk110.unkA04, 0) != 0) || (arg0->LoadInt(&lit_stringBase0[0xD], &this->unk110.unkA00, 0) != 0)) {
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkA00'
void Kane::Resolve() {
    s32 spC;
    s32 sp8;
    u32 temp_r3_91;

    Enemy::Resolve();
    temp_r3_91 = checked_cast<CharacterGraphNodeProp *, MKProp>(this->unk110.unkA00->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */)));
    if (temp_r3_91 != 0U) {
        this->unk110.unk970 = temp_r3_91 + 0x50;
    }
    this->unk110.unk92C->unk8 = 1;
    if ((u8) this->unk110.unkA04 == 0) {
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
    this->unk110.unk92C = temp_r31_139;
    this->unk110.unkA04 = 0;
    this->unk110.unkA00 = 0;
}
#endif
