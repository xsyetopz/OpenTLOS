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

#if 0 // DRAFT: undefined identifier 'unkA08'
s32 NPCGuardian::LoadLine(MKIniLine *arg0) {
    if (Enemy::LoadLine(arg0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("FollowGraphID", (s32 *) &this->unk110.unkA08, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("Behaviour", &this->unk110.unkA0C, 0) != 0) {
        return 1U;
    }
    return (u8) (this->unk110.unkA04.LoadLine(arg0, "OnLoad") != 0);
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
