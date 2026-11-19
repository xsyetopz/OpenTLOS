#include "spyro/source/NPCGuardian.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKIni.h"
#include "spyro/source/CharacterGraph.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/NPCGuardianGoal_Think.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier 'unkA00'
static s8 lit_stringBase0[0x1F] = {
    0x46,
    0x6F,
    0x6C,
    0x6C,
    0x6F,
    0x77,
    0x47,
    0x72,
    0x61,
    0x70,
    0x68,
    0x49,
    0x44,
    0,
    0x42,
    0x65,
    0x68,
    0x61,
    0x76,
    0x69,
    0x6F,
    0x75,
    0x72,
    0,
    0x4F,
    0x6E,
    0x4C,
    0x6F,
    0x61,
    0x64,
    0,
}; /* const */

void NPCGuardian::Message(MKMessage *arg0) {
    if ((s32) arg0->unk0 != 0xB5) {

    } else {
        this->unk110.unkA00 = 1;
    }
    Enemy::Message(arg0);
}
#endif

#if 0 // DRAFT: undefined identifier 'unkA08'
void NPCGuardian::Resolve() {
    MKSceneManager *temp_r3_74;
    s32 temp_r31_86;
    u32 temp_r3_78;

    Enemy::Resolve();
    temp_r3_74 = this->unk110.unkA08;
    if (temp_r3_74 != NULL) {
        temp_r3_78 = checked_cast<CharacterGraphNodeProp *, MKProp>(temp_r3_74->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */)));
        if (temp_r3_78 != 0U) {
            this->unk110.unk970 = temp_r3_78 + 0x50;
            this->unk110.unk980 = 0;
        }
    }
    temp_r31_86 = this->unk110.unkA0C;
    M2C_FIELD(checked_cast<P21NPCGuardianGoal_Think,12Goal<5Enemy>>__FP12Goal<5Enemy>(this->unk110.unk92C), s32 *, 0x20) = temp_r31_86;
    if (!(this->unk110.unk570 & 0x160000)) {
        Disable();
    }
    this->unk110.unkA04.Send(NULL);
}
#endif

void NPCGuardian::LoadDone() {
    Enemy::LoadDone();
}

#if 0 // DRAFT: identifier 'NPCGuardian::LoadLine(MKIniLine *)' redeclared
u8 NPCGuardian::LoadLine(MKIniLine *arg0) {
    if (Enemy::LoadLine(arg0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt(lit_stringBase0, (s32 *) &this->unk110.unkA08, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt(&lit_stringBase0[0xE], &this->unk110.unkA0C, 0) != 0) {
        return 1U;
    }
    return (u8) (this->unk110.unkA04.LoadLine(arg0, &lit_stringBase0[0x18]) != 0);
}
#endif

#if 0 // DRAFT: function call 'operator new(unsigned int, int, int)' does not match
void NPCGuardian::Init() {
    NPCGuardianGoal_Think *temp_r31_191;

    Enemy::Init();
    operator new(0x34U, NULL, 0);
    temp_r31_191 = M2C_ERROR(/* Read from unset register $r3 */);
    if (temp_r31_191 != NULL) {
        temp_r31_191->__vptr = &__vt__12Goal<5Enemy>;
        temp_r31_191->unk4 = 0;
        temp_r31_191->unk8 = 1;
        temp_r31_191->unk9 = 0;
        temp_r31_191->unkC = 0;
        temp_r31_191->__vptr = &__vt__21CompositeGoal<5Enemy>;
        temp_r31_191->unk1C = 0;
        temp_r31_191->unk18 = 0;
        temp_r31_191->unk10 = 0;
        temp_r31_191->unk14 = 0;
        temp_r31_191->__vptr = &__vt;
    }
    temp_r31_191->Init((Enemy *) this);
    this->unk110.unk92C = (Goal<Enemy> *) temp_r31_191;
    this->unk110.unk488 = 0.0f;
    this->unk110.unk48C = 0.0f;
    this->unk110.unk490 = 0.0f;
    this->unk110.unkA08 = NULL;
    this->unk110.unkA00 = 0;
}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<NPCGuardianGoal_Think *, Goal<Enemy>>(Goal<Enemy> *arg0) {

}
#endif
