#include "spyro/source/ConveyorBucket.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/KDPropEx.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void ConveyorBucket::DirtParticles() {
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    MKVector3 sp120;
    MKVector3 sp110;
    MKVector3 sp100;
    MKVector3 spF0;
    MKVector3 spE0;
    MKVector3 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp78;
    f64 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_158;
    f32 temp_f30_151;
    f64 temp_f0_111;
    f64 temp_f0_123;
    f64 temp_f0_135;
    f64 temp_f0_171;
    f64 temp_f0_183;
    f64 temp_f0_99;
    void *temp_r3_162;
    void *temp_r3_96;

    this->unkE8 += gUpdateTimeDelta * MKRand_Float(&gViewSeed, 0.0f, 1.0f);
    if (!(this->unkE8 < 0.1f)) {
        this->unkE8 = 0.0f;
        spD0.operator*(200.0f);
        spE0.operator*(350.0f);
        spF0.operator*(MKRand_Float(&gViewSeed, -1.0f, 1.0f));
        sp100.operator*(140.0f);
        sp110.operator*(MKRand_Float(&gViewSeed, -1.0f, 1.0f));
        sp120.operator*(200.0f);
        temp_r3_96 = ((u8 *) this->unk8) + 0x30;
        temp_f0_99 = M2C_FIELD(temp_r3_96, f64 *, 0) + M2C_BITWISE(f64, sp120);
        sp30 = temp_f0_99;
        sp130 = temp_f0_99;
        sp38 = M2C_FIELD(temp_r3_96, f32 *, 8) + sp120.unk8;
        sp138 = (f64) sp38;
        temp_f0_111 = sp130 + M2C_BITWISE(f64, sp100);
        sp20 = temp_f0_111;
        sp140 = temp_f0_111;
        sp28 = (f32) sp138 + sp100.unk8;
        sp148 = (f64) sp28;
        temp_f0_123 = sp140 + M2C_BITWISE(f64, spE0);
        sp10 = temp_f0_123;
        sp150 = temp_f0_123;
        sp18 = (f32) sp148 + spE0.unk8;
        sp158 = (f64) sp18;
        temp_f0_135 = sp150 + M2C_BITWISE(f64, spD0);
        sp40 = temp_f0_135;
        sp160 = temp_f0_135;
        sp170 = temp_f0_135;
        sp48 = (f32) sp158 + spD0.unk8;
        sp168 = (f64) sp48;
        sp178 = (f64) sp48;
        temp_f30_151 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        temp_f1_158 = 0.5f * MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        sp84 = 0.0f;
        temp_r3_162 = ((u8 *) this->unk8) + 0x10;
        sp80 = temp_f1_158;
        sp88 = 0.5f * temp_f30_151;
        spA0 = (f64) sp80;
        spA8 = (f64) sp88;
        temp_f0_171 = M2C_FIELD(temp_r3_162, f64 *, 0) + spA0;
        sp70 = temp_f0_171;
        spB0 = temp_f0_171;
        sp78 = M2C_FIELD(temp_r3_162, f32 *, 8) + (f32) spA8;
        spB8 = (f64) sp78;
        temp_f0_183 = temp_f0_171 * 5.593163344e-315;
        sp60 = temp_f0_183;
        spC0 = temp_f0_183;
        sp68 = (f32) spB8 * 250.0f;
        spC8 = (f64) sp68;
        spC = MKRand_Float(&gViewSeed, 0.2f, 0.5f);
        gb.EmitCrud(*((MKVector3 *) &sp170), *((MKVector3 *) &spC0), spC);
        sp8 = MKRand_Float(&gViewSeed, 2.5f, 3.5f);
        sp58 = 0.0f;
        sp50 = 0.0f;
        sp54 = 0.0f;
        sp98 = (f64) sp58;
        sp90 = (f64) sp50;
        gb.EmitDust(*((MKVector3 *) &sp170), *((MKVector3 *) &sp90), sp8, 0.0f);
    }
}
#endif

#if 0 // DRAFT: ')' expected
void ConveyorBucket::Message(MKMessage *arg0) {
    s8 sp80;
    s32 sp7C;
    s32 sp78;
    f64 *sp74;
    f64 *sp70;
    s32 sp6C;
    s32 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f2_293;
    f64 temp_f1_270;
    void **temp_r3_252;
    void *temp_r3_256;
    void *temp_r4_267;

    if ((s32) arg0->unk0 != 0x12) {

    } else {
        temp_r3_252 = M2C_FIELD(checked_cast<CollisionObjectCollideMsg *, MKMessage>(arg0), void ***, 0xC);
        temp_r3_256 = M2C_FIELD(*temp_r3_252, void *(**)(void **), 0x2C)(temp_r3_252);
        if (temp_r3_256 != NULL) {
            sp6C = 0;
            sp18 = this->unkD8 * 5.222099017e-315;
            temp_r4_267 = M2C_FIELD(temp_r3_256, void **, 8);
            temp_f1_270 = M2C_FIELD(temp_r4_267, f64 *, 0x30);
            sp20 = this->unkE0 * 0.5f;
            sp28 = sp18;
            sp38 = temp_f1_270;
            sp30 = (f64) sp20;
            sp40 = M2C_FIELD(temp_r4_267, f64 *, 0x38);
            sp8 = temp_f1_270 + sp28;
            sp58 = sp8;
            temp_f2_293 = (f32) sp40 + (f32) sp30;
            sp48 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
            sp10 = temp_f2_293;
            sp50 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
            sp60 = (f64) sp10;
            sp68 = 0x22;
            sp70 = &sp58;
            sp74 = &sp48;
            sp78 = 0;
            sp7C = 0;
            sp80 = 0;
            M2C_FIELD(M2C_FIELD(temp_r3_256, void **, 0x44), M2C_UNK (**)(s32 *, f64 *, M2C_UNK, M2C_UNK, f64, f32, f32, f32), 0x2C)(&sp68, &sp58, 0x22, 0, (f64) sp10, temp_f2_293, (f32) sp30, (f32) sp40);
        }
    }
    GameProp::Message(arg0);
}
#endif

void ConveyorBucket::Update() {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    void *temp_r4_339;
    void *temp_r4_355;

    GameProp::Update();
    temp_r4_339 = ((u8 *) this->unk8) + 0x30;
    sp8 = M2C_FIELD(temp_r4_339, f64 *, 0) - this->unkC8;
    this->unkD8 = sp8;
    sp10 = M2C_FIELD(temp_r4_339, f32 *, 8) - this->unkD0;
    sp18 = sp8;
    M2C_FIELD(this, f64 *, 0xE0) = (f64) sp10;
    temp_r4_355 = this->unk8;
    sp20 = (f64) sp10;
    this->unkC8 = M2C_FIELD(temp_r4_355, f64 *, 0x30);
    M2C_FIELD(this, f32 *, 0xD0) = (f64) M2C_FIELD(temp_r4_355, f64 *, 0x38);
    DirtParticles();
}

void ConveyorBucket::Resolve() {
    KDPropEx::Resolve();
}

void ConveyorBucket::LoadDone() {
    GameProp::LoadDone();
}

s32 ConveyorBucket::LoadLine(MKIniLine *arg0) {
    GameProp::LoadLine(arg0);
}

void ConveyorBucket::Deinit() {
    GameProp::Deinit();
}

void ConveyorBucket::Init() {
    GameProp::Init();
    this->unkC8 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 0xD0) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unkD8 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 0xE0) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unkE8 = 0.0f;
}
