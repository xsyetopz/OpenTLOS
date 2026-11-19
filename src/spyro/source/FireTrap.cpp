#include "spyro/source/FireTrap.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/Trap.h"
#include "common/Source/StdMath.h"
#include "spyro/source/PropFlags.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;

void FireTrap::Message(MKMessage *arg0) {
    s32 temp_r0_48;

    Trap::Message(arg0);
    temp_r0_48 = arg0->unk0;
    if (temp_r0_48 != 0xB5) {
        if (temp_r0_48 < 0xB5) {

        }
    } else {
        this->unkE0 = 0.0f;
    }
}

#if 0 // DRAFT: undefined identifier 'sp78'
void FireTrap::Update() {
    s8 sp199;
    s8 sp198;
    s32 sp194;
    f32 sp190;
    s32 sp18C;
    s8 sp18A;
    s8 sp189;
    s8 sp188;
    f64 sp180;                                      /* compiler-managed */
    f64 sp178;                                      /* compiler-managed */
    FireTrap *sp174;
    s32 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    s32 sp14C;
    s32 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f32 sp80;
    f32 sp70;
    f64 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f32 sp30;
    f32 sp20;
    f32 sp10;
    f32 temp_f1_271;
    f64 temp_f1_117;
    s32 temp_r3_79;
    void *temp_r3_125;
    void *temp_r3_226;
    void *temp_r4_114;
    void *temp_r5_286;
    void *temp_r5_89;

    GameProp::Update();
    temp_r3_79 = this->unk10;
    if ((temp_r3_79 & 0x20000) && (temp_r3_79 & 0x80000)) {
        if (this->unkE0 > 1.0f) {
            temp_r5_89 = this->unk8;
            sp128 = M2C_FIELD(temp_r5_89, f64 *, 0x30);
            sp130 = M2C_FIELD(temp_r5_89, f64 *, 0x38);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
            sp118 = sp78;
            sp80 = MKVector3::up.unk8 * 650.0f;
            sp120 = (f64) sp80;
            gb.unk68->Emit(*((MKVector3 *) &sp128), *((MKVector3 *) &sp118), 6.0f);
            temp_r4_114 = this->unk8;
            temp_f1_117 = M2C_FIELD(temp_r4_114, f64 *, 0x30);
            spF8 = temp_f1_117;
            sp100 = M2C_FIELD(temp_r4_114, f64 *, 0x38);
            temp_r3_125 = M2C_FIELD(gb.unk0->GetProp(temp_r4_114, temp_f1_117), void **, 8);
            sp108 = M2C_FIELD(temp_r3_125, f64 *, 0x30);
            sp110 = M2C_FIELD(temp_r3_125, f64 *, 0x38);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            sp138 = sp68;
            sp70 = (f32) sp110 - (f32) sp100;
            unksp13C = 0.0f;
            sp140 = (f64) sp70;
            if ((((f32) sp140 * (f32) sp140) + (((f32) sp138 * (f32) sp138) + (0.0f * 0.0f))) < 10000.0f) {
                sp14C = 0;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
                sp10 = (f32) sp140 * 20.0f;
                spE8 = sp8;
                spF0 = (f64) sp10;
                sp148 = 7;
                sp170 = 1;
                sp174 = this;
                sp150 = sp8;
                sp158 = (f64) sp10;
                sp188 = 0;
                sp194 = 2;
                sp190 = 10.0f;
                sp189 = 0;
                sp18A = 1;
                sp18C = -1;
                sp160 = M2C_FIELD(&MKVector3::one, f64 *, 0);
                sp168 = M2C_FIELD(&MKVector3::one, f64 *, 8);
                sp198 = 0;
                if (this != NULL) {
                    sp58.GetPos();
                    sp178 = sp58;
                    sp180 = sp60;
                } else {
                    sp178 = 0.0f;
                    unksp17C = 0.0f;
                    sp180 = 0.0f;
                }
                sp199 = 0;
                gb.unk0->Message(&sp148);
            }
        }
        if ((this->unkE0 < 1.0f) && (MKRand_Int(&gViewSeed, 0, 0xA) == 0)) {
            temp_r3_226 = this->unk8;
            sp48 = 0.0f;
            sp4C = 15.0f;
            sp50 = 0.0f;
            spB8 = (f64) sp48;
            spC8 = M2C_FIELD(temp_r3_226, f64 *, 0x30);
            spC0 = (f64) sp50;
            spD0 = M2C_FIELD(temp_r3_226, f64 *, 0x38);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            spD8 = sp38;
            sp40 = (f32) spD0 + (f32) spC0;
            spE0 = (f64) sp40;
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            spA8 = sp28;
            sp30 = MKVector3::up.unk8 * 300.0f;
            spB0 = (f64) sp30;
            gb.unk84->Emit(*((MKVector3 *) &spD8), *((MKVector3 *) &spA8), 5.0f);
        }
        temp_f1_271 = this->unkE0;
        if (((temp_f1_271 > 0.5f) && (temp_f1_271 < 1.0f)) || (MKRand_Int(&gViewSeed, 0, 0xA) == 0)) {
            temp_r5_286 = this->unk8;
            sp98 = M2C_FIELD(temp_r5_286, f64 *, 0x30);
            spA0 = M2C_FIELD(temp_r5_286, f64 *, 0x38);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
            sp88 = sp18;
            sp20 = MKVector3::up.unk8 * 650.0f;
            sp90 = (f64) sp20;
            gb.EmitDust(*((MKVector3 *) &sp98), *((MKVector3 *) &sp88), 0.5f, 0.0f);
        }
        this->unkE0 += gUpdateTimeDelta;
    }
}
#endif

#if 0 // DRAFT: function call 'PropFlagsSet(unsigned long *, unsigned int)' does not match
void FireTrap::Reset() {
    PropFlagsSet((u32 *) &this->unk10, 0x80000U);
    Trap::Reset();
    this->unkE0 = 0.0f;
    PropFlagsClear((u32 *) &this->unk10, 0x80000U);
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void FireTrapDescriptor::Init() {
    TrapDescriptor::Init();
    this->unkC = 0x12;
}
#endif
