#include "spyro/source/LavaBall.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "spyro/source/Explosion4.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/Projectile.h"
#include "spyro/source/ShapedTrailFX.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

extern MKSceneManager *gMK;
extern MKPropDescriptor *pLavaBallDescriptor;
static s32 lit_507 = -1;
static s32 lit_508 = 5;

static u8 lit_514 = 1;
static u8 lit_518 = 1;
static u8 lit_522 = 0;

#if 0 // DRAFT: function call 'Disable(Projectile *, unsigned char, ShapedTrailFX *)' does
void LavaBall::Collided(MKCollisionResult &arg0) {
    s32 sp8;
    ShapedTrailFX *temp_r5_118;
    void *temp_r3_105;

    Projectile::Collided(arg0);
    temp_r3_105 = checked_cast<LavaBallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    sp8 = 1;
    ((Explosion4 *) (M2C_FIELD(temp_r3_105, Explosion4 **, 0xF0)))->Trigger(*((MKVector3 *) &arg0), 0.75f, 1U, this->unk130, 5, 1U, 1U, 1U, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    temp_r5_118 = this->unk150;
    temp_r5_118->unkA0 = (temp_r5_118->unkA0 & ~0x80) | ((lit_522 << 7) & 0x80);
    Disable(lit_522, temp_r5_118);
}
#endif

void LavaBall::FireAtTarget(const MKVector3 &arg0, const MKVector3 &arg1, float arg2, MKProp *arg3, int arg4, int arg5) {
    ShapedTrailFX *temp_r3_144;
    ShapedTrailFX *temp_r3_155;
    ShapedTrailFX *temp_r5_149;

    Projectile::FireAtTarget(arg0, arg1, arg2, arg3, arg4, arg5);
    temp_r3_144 = this->unk150;
    temp_r3_144->Reset();
    temp_r5_149 = this->unk150;
    temp_r5_149->unkA0 = (temp_r5_149->unkA0 & ~0x80) | ((lit_518 << 7) & 0x80);
    temp_r3_155 = this->unk150;
    temp_r3_155->unkA0 |= 0x40;
}

void LavaBall::Fire(const MKVector3 &arg0, const MKVector3 &arg1, MKProp *arg2, int arg3, int arg4) {
    ShapedTrailFX *temp_r3_175;
    ShapedTrailFX *temp_r3_186;
    ShapedTrailFX *temp_r5_180;

    Projectile::Fire(arg0, arg1, arg2, arg3, arg4);
    temp_r3_175 = this->unk150;
    temp_r3_175->Reset();
    temp_r5_180 = this->unk150;
    temp_r5_180->unkA0 = (temp_r5_180->unkA0 & ~0x80) | ((lit_514 << 7) & 0x80);
    temp_r3_186 = this->unk150;
    temp_r3_186->unkA0 |= 0x40;
}

#if 0 // DRAFT: function call 'checked_cast(void *)' does not match
void LavaBall::LoadDone() {
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    ShapedTrailFX *temp_r3_210;

    Projectile::LoadDone();
    temp_r3_210 = checked_cast<ShapedTrailFX *, MKProp>(gMK->CreateProp("ShapedTrailFX"));
    sp8 = 1.0f;
    spC = 0.5f;
    sp10 = 0.0f;
    sp14 = 0.75f;
    this->unk150 = temp_r3_210;
    sp18 = (f64) sp8;
    sp20 = (f64) sp10;
    this->unk150->InitData(this->unk4, lit_507, "FX_323", lit_508, *((MKVector4 *) &sp18), 2.0f, 1U, 0.2f);
}
#endif

void *LavaBall::CreateInstance() {
    void *temp_r3_253;

    if ((MKPropDescriptor *) pLavaBallDescriptor != NULL) {
        temp_r3_253 = pLavaBallDescriptor->CreateInstance();
        if (temp_r3_253 != NULL) {
            M2C_FIELD(M2C_FIELD(temp_r3_253, void **, 0x44), M2C_UNK (**)(), 0x20)();
            return temp_r3_253;
        }
    }
    return NULL;
}

#if 0 // DRAFT: illegal use of non-static member
void LavaBallDescriptor::LoadDone() {
    GamePropDescriptor::LoadDone();
    this->unkF0 = checked_cast<Explosion4 *, MKProp>(gMK->CreateProp("Explosion4"));
    pLavaBallDescriptor = (MKPropDescriptor *) this;
}
#endif

void LavaBallDescriptor::Deinit() {
    pLavaBallDescriptor = NULL;
    KDPropExDescriptor::Deinit();
}
