#include "spyro/source/NPCGuardian.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKIni.h"
#include "spyro/source/CharacterGraph.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/NPCGuardianGoal_Think.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

void NPCGuardian::Message(MKMessage *arg0) {
    if ((s32) arg0->unk0 != 0xB5) {

    } else {
        this->unkB10 = 1;
    }
    Enemy::Message(arg0);
}

#if 0 // DRAFT: illegal implicit conversion from 'CharacterGraphNodeProp *' to
void NPCGuardian::Resolve() {
    MKSceneManager *temp_r3_74;
    s32 temp_r31_86;
    u32 temp_r3_78;

    Enemy::Resolve();
    temp_r3_74 = this->unkB18;
    if (temp_r3_74 != NULL) {
        temp_r3_78 = checked_cast<CharacterGraphNodeProp *, MKProp>(temp_r3_74->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */)));
        if (temp_r3_78 != 0U) {
            this->unkA80 = temp_r3_78 + 0x50;
            this->unkA90 = 0;
        }
    }
    temp_r31_86 = this->unkB1C;
    M2C_FIELD(checked_cast<P21NPCGuardianGoal_Think,12Goal<5Enemy>>__FP12Goal<5Enemy>((Goal<Enemy> *) this->unkA3C), s32 *, 0x20) = temp_r31_86;
    if (!(this->unk680 & 0x160000)) {
        Disable();
    }
    this->unkB14.Send(NULL);
}
#endif

void NPCGuardian::LoadDone() {
    Enemy::LoadDone();
}

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
s32 NPCGuardian::LoadLine(MKIniLine *arg0) {
    if (Enemy::LoadLine(arg0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("FollowGraphID", (s32 *) &this->unkB18, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("Behaviour", &this->unkB1C, 0) != 0) {
        return 1U;
    }
    return (u8) (this->unkB14.LoadLine(arg0, "OnLoad") != 0);
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
    this->unkA3C = &temp_r31_191->__vptr;
    this->unk598 = 0.0f;
    this->unk59C = 0.0f;
    this->unk5A0 = 0.0f;
    this->unkB18 = NULL;
    this->unkB10 = 0;
}
#endif
