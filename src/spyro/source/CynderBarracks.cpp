#include "spyro/source/CynderBarracks.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "spyro/source/Shatterable.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

extern M2C_UNK gb;

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'CynderBarracksState'
void CynderBarracks::SetState(CynderBarracksState arg0) {
    this->unk198 = M2C_BITWISE(f32, arg0);
    if (M2C_BITWISE(s32, this->unk198) == 1) {
        M2C_FIELD(this, f32 *, 0x1B0) = (f32) (5.0f + M2C_FIELD(&gb, f32 *, 0x30C));
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'FindInteractivePropMsg'
void CynderBarracks::Message(MKMessage *arg0) {
    s32 temp_r0_90;
    void *temp_r3_104;

    temp_r0_90 = arg0->unk0;
    if (temp_r0_90 < 0xB4) {
        if (temp_r0_90 != 0x79) {
            goto block_8;
        }
        temp_r3_104 = checked_cast<FindInteractivePropMsg *, MKMessage>(arg0);
        if ((M2C_BITWISE(s32, this->unk198) != 2) && ((s32) M2C_FIELD(temp_r3_104, s32 *, 8) == 2)) {
            M2C_FIELD(temp_r3_104, CynderBarracks **, 0xC) = this;
        }
    } else {
        if (temp_r0_90 < 0xB6) {
            this->unk1B4.Message(arg0);
        }
block_8:
        Shatterable::Message(arg0);
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void CynderBarracks::Update() {
    Shatterable::Update();
    if (M2C_BITWISE(s32, this->unk198) != 0) {
        return;
    }
    if ((s32) this->unk16C == 3) {
        SetState((CynderBarracksState) 2);
        return;
    }
    this->unk1B4.Update();
}
#endif

void CynderBarracks::Resolve() {
    Shatterable::Resolve();
    this->unk1B4.Resolve();
}

void CynderBarracks::LoadDone() {
    Shatterable::LoadDone();
    this->unk1B4.LoadDone();
}

#if 0 // DRAFT: illegal implicit conversion from 'EnemyGenerator *' to
s32 CynderBarracks::LoadLine(MKIniLine *arg0) {
    s32 var_r31_202;

    var_r31_202 = 0;
    if ((Shatterable::LoadLine(arg0) != 0) || (M2C_FIELD(M2C_FIELD(this, void **, 0x1B4), u8 (**)(M2C_UNK *, MKIniLine *), 8)(&this->unk1B4, arg0) != 0)) {
        var_r31_202 = 1;
    }
    return var_r31_202;
}
#endif

void CynderBarracks::Deinit() {
    this->unk1B4.Deinit();
    Shatterable::Deinit();
}

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void CynderBarracks::Init() {
    Shatterable::Init();
    M2C_FIELD(this, s32 *, 0x1AC) = 0x32;
    M2C_FIELD(this, f32 *, 0x1B0) = 0.0f;
    SetState((CynderBarracksState) 0);
    this->unk1B4.Init(checked_cast<P24CynderBarracksDescriptor, 16MKPropDescriptor>__FP16MKPropDescriptor((MKPropDescriptor *) this->unk0) + 0x16C, (MKProp *) this);
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void CynderBarracksDescriptor::LoadDone() {
    ShatterableDescriptor::LoadDone();
    this->unk16C.LoadDone();
}
#endif

#if 0 // DRAFT: illegal use of non-static member
s32 CynderBarracksDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_301;

    var_r31_301 = 0;
    if ((ShatterableDescriptor::LoadLine(arg0) != 0) || (this->unk16C.LoadLine(arg0) != 0)) {
        var_r31_301 = 1;
    }
    return var_r31_301;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void CynderBarracksDescriptor::Deinit() {
    this->unk16C.Deinit();
    ShatterableDescriptor::Deinit();
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void CynderBarracksDescriptor::Init() {
    ShatterableDescriptor::Init();
    this->unk64 |= 0x2000;
    this->unk16C.Init();
}
#endif
