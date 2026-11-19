#include "spyro/source/DragonBustDoor.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKIni.h"
#include "spyro/source/Door.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/Trap.h"
#include "common/Source/MKModel.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

static s8 lit_stringBase0[0x60] = {
    0x4C,
    0x69,
    0x67,
    0x68,
    0x74,
    0x59,
    0x65,
    0x6C,
    0x6C,
    0x6F,
    0x77,
    0,
    0x4C,
    0x69,
    0x67,
    0x68,
    0x74,
    0x52,
    0x65,
    0x64,
    0,
    0x4C,
    0x69,
    0x67,
    0x68,
    0x74,
    0x47,
    0x72,
    0x65,
    0x65,
    0x6E,
    0,
    0x4C,
    0x69,
    0x67,
    0x68,
    0x74,
    0x42,
    0x6C,
    0x75,
    0x65,
    0,
    0x59,
    0x65,
    0x6C,
    0x6C,
    0x6F,
    0x77,
    0x53,
    0x77,
    0x69,
    0x74,
    0x63,
    0x68,
    0x49,
    0x44,
    0,
    0x52,
    0x65,
    0x64,
    0x53,
    0x77,
    0x69,
    0x74,
    0x63,
    0x68,
    0x49,
    0x44,
    0,
    0x47,
    0x72,
    0x65,
    0x65,
    0x6E,
    0x53,
    0x77,
    0x69,
    0x74,
    0x63,
    0x68,
    0x49,
    0x44,
    0,
    0x42,
    0x6C,
    0x75,
    0x65,
    0x53,
    0x77,
    0x69,
    0x74,
    0x63,
    0x68,
    0x49,
    0x44,
    0,
}; /* const */

void DragonBustDoor::Deinit() {
    GameProp::Deinit();
}

#if 0 // DRAFT: illegal use of non-static member
void DragonBustDoor::Message(MKMessage *arg0) {
    u8 sp18;
    s32 sp14;
    s32 sp10;
    DragonBustDoor *spC;
    s32 sp8;
    s32 var_r28_67;
    s32 var_r29_65;
    s32 var_r31_64;
    void *temp_r30_69;
    void *temp_r3_71;

    if ((s32) arg0->unk0 != 0xB5) {
        Door::Message(arg0);
    } else {
        var_r31_64 = 0;
        var_r29_65 = 0;
        sp14 = 0;
        var_r28_67 = 0;
        do {
            temp_r30_69 = this + var_r31_64;
            temp_r3_71 = ((MKSceneManager *) (M2C_FIELD(temp_r30_69, MKSceneManager **, 0xE8)))->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */));
            if (temp_r3_71 != NULL) {
                sp10 = 0x4F;
                sp18 = 0;
                M2C_FIELD(M2C_FIELD(temp_r3_71, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp10);
                if (sp18 != 0) {
                    MKModel_EnableSubObject(this->unk4, (SubObjectType) 0, M2C_FIELD(temp_r30_69, s32 *, 0xEC), 1U, 1U);
                    var_r29_65 += 1;
                }
            }
            var_r28_67 += 1;
            var_r31_64 += 8;
        } while (var_r28_67 < 4);
        if (var_r29_65 == 4) {
            spC = NULL;
            sp8 = 0xB5;
            spC = this;
            Door::Message((MKMessage *) &sp8);
        }
    }
}
#endif

void DragonBustDoor::Draw() {
    GameProp::Draw();
}

#if 0 // DRAFT: illegal use of non-static member
void DragonBustDoor::Update() {
    Door::Update();
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void DragonBustDoor::LoadDone() {
    s32 var_r30_184;
    s32 var_r31_186;

    Trap::LoadDone();
    this->unkE8 = (s32) Tools_GetMatchingSubObjectIndex((SubObjectType) 0, this->unk4, lit_stringBase0);
    this->unkF0 = (s32) Tools_GetMatchingSubObjectIndex((SubObjectType) 0, this->unk4, &lit_stringBase0[0xC]);
    this->unkF8 = (s32) Tools_GetMatchingSubObjectIndex((SubObjectType) 0, this->unk4, &lit_stringBase0[0x15]);
    var_r30_184 = 0;
    this->unk100 = (s32) Tools_GetMatchingSubObjectIndex((SubObjectType) 0, this->unk4, &lit_stringBase0[0x20]);
    var_r31_186 = 0;
    do {
        MKModel_EnableSubObject(this->unk4, (SubObjectType) 0, *(this + (var_r31_186 + 0xEC)), 0U, 1U);
        var_r30_184 += 1;
        var_r31_186 += 8;
    } while (var_r30_184 < 4);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
s32 DragonBustDoor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_215;

    var_r31_215 = 0;
    if ((Trap::LoadLine(arg0) != 0) || (arg0->LoadInt(&lit_stringBase0[0x2A], &this->unkE8, 0) != 0) || (arg0->LoadInt(&lit_stringBase0[0x39], &this->unkEC, 0) != 0) || (arg0->LoadInt(&lit_stringBase0[0x45], &this->unkF4, 0) != 0) || (arg0->LoadInt(&lit_stringBase0[0x53], &this->unkFC, 0) != 0)) {
        var_r31_215 = 1;
    }
    return var_r31_215;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void DragonBustDoor::Init() {
    s32 var_ctr_278;
    s32 var_r3_276;
    void *temp_r5_280;

    Door::Init();
    var_r3_276 = 0;
    var_ctr_278 = 4;
    do {
        temp_r5_280 = this + var_r3_276;
        var_r3_276 += 8;
        M2C_FIELD(temp_r5_280, s32 *, 0xE8) = -1;
        M2C_FIELD(temp_r5_280, s32 *, 0xEC) = -1;
        var_ctr_278 -= 1;
    } while (var_ctr_278 != 0);
}
#endif
