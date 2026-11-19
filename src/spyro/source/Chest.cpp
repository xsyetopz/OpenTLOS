#include "spyro/source/Chest.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/Collectable.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/Trap.h"
#include "unplaced_templates.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/PropFlags.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;
extern M2C_UNK gb;

void Chest::SetState(int arg0) {
    this->unkE0 = arg0;
    this->unk80->SetAnim(M2C_FIELD((checked_cast<ChestDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (this->unkE0 * 4)), MKAnim **, 0xE4), 1.0f, 0.0f, 0, -1);
}

void Chest::Message(MKMessage *arg0) {
    s32 temp_r0_81;

    if ((s32) arg0->unk0 != 0xB5) {

    } else {
        temp_r0_81 = this->unkE0;
        if ((temp_r0_81 == 0) || (temp_r0_81 == 2)) {
            this->unkE4 = 0;
            SetState(1);
        }
    }
    Trap::Message(arg0);
}

void Chest::Reset() {
    Trap::Reset();
    this->unkE4 = 0;
    this->unkE8 = 0.0f;
    SetState(0);
}

#if 0 // DRAFT: illegal type
void Chest::Update() {
    f64 sp70;                                       /* compiler-managed */
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f2_208;
    f64 temp_f0_186;
    f64 temp_f0_211;
    f64 temp_f1_174;
    s32 temp_r0_140;
    void *temp_r3_172;

    GameProp::Update();
    if (this->unk10 & 0x20000) {
        temp_r0_140 = this->unkE0;
        switch (temp_r0_140) {                      /* irregular */
        case 1:
            if (this->unk80->unk2C & 1) {
                SetState(2);
                return;
            }
            break;
        case 2:
            if ((s32) this->unkE4 < 0xA) {
                this->unkE8 += gUpdateTimeDelta;
                if (this->unkE8 >= 0.05f) {
                    this->unkE8 = 0.0f;
                    temp_r3_172 = this->unk8;
                    sp28 = 0.0f;
                    temp_f1_174 = M2C_FIELD(temp_r3_172, f64 *, 0x30);
                    sp2C = 150.0f;
                    sp30 = 0.0f;
                    sp48 = (f64) sp28;
                    sp58 = temp_f1_174;
                    sp50 = (f64) sp30;
                    sp60 = M2C_FIELD(temp_r3_172, f64 *, 0x38);
                    temp_f0_186 = temp_f1_174 + sp48;
                    sp18 = temp_f0_186;
                    sp68 = temp_f0_186;
                    sp20 = (f32) sp60 + (f32) sp50;
                    sp70 = (f64) sp20;
                    temp_f2_208 = (200.0f * ((f32) this->unkE4 / 10.0f)) - 100.0f;
                    temp_f0_211 = M2C_FIELD(temp_r3_172, f64 *, 0) * (f64) temp_f2_208;
                    sp8 = temp_f0_211;
                    sp38 = temp_f0_211;
                    sp10 = M2C_FIELD(temp_r3_172, f32 *, 8) * temp_f2_208;
                    sp40 = (f64) sp10;
                    sp68 -= temp_f0_211;
                    sp70 = (f32) sp70 - (f32) sp40;
                    ((CollectableSpawner *) (M2C_FIELD(&gb, CollectableSpawner **, 0x10)))->Spawn(*((MKVector3 *) &sp68), 300.0f, ((3.1415927f * ((f32) this->unkE4 / 10.0f)) - KDMath_GetYaw(*(temp_r3_172 + 0x20))) - 1.5707964f);
                    this->unkE4 += 1;
                }
            }
            break;
        }
    }
}
#endif

#if 0 // DRAFT: function call 'PropFlagsSet(unsigned long *, unsigned int)' does not match
void Chest::Init() {
    Trap::Init();
    PropFlagsSet((u32 *) &this->unk10, 0x80000U);
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void ChestDescriptor::LoadDone() {
    GamePropDescriptor::LoadDone();
    this->unkE4 = this->unk34->GetAnim("Closed");
    this->unkE8 = this->unk34->GetAnim("Opening");
    this->unkEC = this->unk34->GetAnim("Open");
}
#endif
