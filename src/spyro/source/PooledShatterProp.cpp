#include "spyro/source/PooledShatterProp.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/Shatterable.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

#if 0 // DRAFT: illegal operand
void PooledShatterProp::Update() {
    MKProp *temp_r4_133;
    void *temp_r3_129;

    Shatterable::Update();
    temp_r3_129 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    if (((s32) this->unk15C.unk0 == 0) || ((temp_r4_133 = this->unk170, ((temp_r4_133 == (s32) M2C_FIELD(temp_r3_129, s32 *, 0x160)) != 0)) && ((s32) *(this->unk158 + (((s32) (temp_r4_133 - 1) << 7) + 0x44)) == 2))) {
        Reset();
        Disable();
    }
}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<ShatterableDescriptor *, MKPropDescriptor>(MKPropDescriptor *arg0) {

}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_IsAttacking'
void Shatterable::lit_200lit_IsAttacking() {
    ((Shatterable *) (this - 0xC8))->Shatterable::IsAttacking();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetTimeLastHit'
void Shatterable::lit_200lit_GetTimeLastHit() {
    ((Shatterable *) (this - 0xC8))->Shatterable::GetTimeLastHit();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetCollisionHeight'
void Shatterable::lit_200lit_GetCollisionHeight() {
    ((Shatterable *) (this - 0xC8))->Shatterable::GetCollisionHeight();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetCollisionRadius'
void Shatterable::lit_200lit_GetCollisionRadius() {
    ((Shatterable *) (this - 0xC8))->Shatterable::GetCollisionRadius();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetCollisionInfo'
void Shatterable::lit_200lit_GetCollisionInfo() {
    ((Shatterable *) (this - 0xC8))->Shatterable::GetCollisionInfo();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetVel'
void Shatterable::lit_200lit_GetVel() {
    Shatterable::GetVel();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetAimPoint'
void Shatterable::lit_200lit_GetAimPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    ((Shatterable *) (this - 0xC8))->Shatterable::GetAimPoint(arg0, arg1);
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetLookToPoint'
void Shatterable::lit_200lit_GetLookToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    ((Shatterable *) (this - 0xC8))->Shatterable::GetLookToPoint(arg0, arg1);
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetMoveToPoint'
void Shatterable::lit_200lit_GetMoveToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    ((Shatterable *) (this - 0xC8))->Shatterable::GetMoveToPoint(arg0, arg1);
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_IsDead'
void Shatterable::lit_200lit_IsDead() {
    ((Shatterable *) (this - 0xC8))->Shatterable::IsDead();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_IsShatterable'
void Shatterable::lit_200lit_IsShatterable() {
    ((Shatterable *) (this - 0xC8))->Shatterable::IsShatterable();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_IsEnemy'
void Shatterable::lit_200lit_IsEnemy() {
    ((Shatterable *) (this - 0xC8))->Shatterable::IsEnemy();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_IsFriend'
void Shatterable::lit_200lit_IsFriend() {
    ((Shatterable *) (this - 0xC8))->Shatterable::IsFriend();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_IsHero'
void Shatterable::lit_200lit_IsHero() {
    ((Shatterable *) (this - 0xC8))->Shatterable::IsHero();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetEnemy'
void Shatterable::lit_200lit_GetEnemy() {
    ((Shatterable *) (this - 0xC8))->Shatterable::GetEnemy();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_200lit_GetProp'
void Shatterable::lit_200lit_GetProp() {
    ((Shatterable *) (this - 0xC8))->Shatterable::GetProp();
}
#endif
