#include "spyro/source/Explosion4.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Character.h"
#include "spyro/source/Game.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDParticleSystem.h"
#include "spyro/source/ManagedLight.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "common/Source/MKCollision.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

M2C_UNK free(u32 *);                                /* extern */
u32 *malloc(M2C_UNK);                               /* extern */
extern s32 GS_Explosion2;
extern s32 GS_Rumble1Soft;
extern M2C_UNK gEmptyPtrList;
extern void **gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;

static s32 lit_762 = 0;
static u8 lit_763 = 1;

#if 0 // DRAFT: undefined identifier 'arg_sp10'
static s8 lit_stringBase0[0x49] = {
    0x73,
    0x6E,
    0x64,
    0x45,
    0x78,
    0x70,
    0x6C,
    0x6F,
    0x64,
    0x65,
    0,
    0x73,
    0x6E,
    0x64,
    0x45,
    0x78,
    0x70,
    0x6C,
    0x6F,
    0x64,
    0x65,
    0x52,
    0x75,
    0x6D,
    0x62,
    0x6C,
    0x65,
    0,
    0x45,
    0x78,
    0x70,
    0x34,
    0x46,
    0x6C,
    0x61,
    0x6D,
    0x65,
    0x50,
    0x53,
    0,
    0x45,
    0x78,
    0x70,
    0x34,
    0x53,
    0x6D,
    0x6F,
    0x6B,
    0x65,
    0x50,
    0x53,
    0,
    0x46,
    0x58,
    0x30,
    0x30,
    0x30,
    0x31,
    0x5F,
    0x45,
    0x78,
    0x70,
    0x32,
    0x53,
    0x68,
    0x6F,
    0x63,
    0x6B,
    0x77,
    0x61,
    0x76,
    0x65,
    0,
}; /* const */

void Explosion4::Trigger(const MKVector3 &arg0, float arg1, bool arg2, MKProp *arg3, int arg4, bool arg5, bool arg6, bool arg7, bool arg8) {
    ManagedLight *temp_r3_158;
    ManagedLight *temp_r3_208;
    f32 temp_f0_1802;
    f32 temp_f0_1836;
    f32 temp_f14_1807;
    f32 temp_f14_2145;
    f32 temp_f1_714;
    f32 temp_f1_900;
    f32 temp_f20_655;
    f32 temp_f20_709;
    f32 temp_f21_1572;
    f32 temp_f21_516;
    f32 temp_f21_712;
    f32 temp_f21_841;
    f32 temp_f22_1071;
    f32 temp_f22_1103;
    f32 temp_f22_1273;
    f32 temp_f22_1305;
    f32 temp_f22_1469;
    f32 temp_f22_1501;
    f32 temp_f22_1569;
    f32 temp_f22_362;
    f32 temp_f23_1576;
    f32 temp_f24_1006;
    f32 temp_f24_1208;
    f32 temp_f24_1404;
    f32 temp_f25_1066;
    f32 temp_f25_1098;
    f32 temp_f25_1268;
    f32 temp_f25_1300;
    f32 temp_f25_1464;
    f32 temp_f25_1496;
    f32 temp_f25_842;
    f32 temp_f26_260;
    f32 temp_f26_414;
    f32 temp_f26_568;
    f32 temp_f27_1891;
    f32 temp_f2_1888;
    f32 temp_f4_349;
    f32 temp_f4_503;
    s32 temp_r24_234;
    s32 temp_r3_2046;
    s32 temp_r3_2059;
    s32 var_r14_937;
    s32 var_r17_2047;
    s32 var_r18_2048;
    s32 var_r22_967;
    s32 var_r23_229;
    s32 var_r24_1556;
    s32 var_r24_1655;
    s32 var_r27_1365;
    s32 var_r27_796;
    s32 var_r30_1169;
    u8 temp_r21_87;
    u8 var_r14_2071;
    u8 var_r14_2126;
    void *temp_r23_705;
    void *temp_r26_256;
    void *temp_r26_410;
    void *temp_r26_564;
    void *temp_r3_114;
    void *temp_r3_172;
    void *temp_r3_1757;
    void *temp_r3_214;
    void *temp_r3_237;
    void *temp_r3_241;
    void *temp_r3_391;
    void *temp_r3_395;
    void *temp_r3_545;
    void *temp_r3_549;
    void *temp_r3_686;
    void *temp_r3_690;
    void *temp_r3_96;
    arg_sp10 = arg1;
    temp_r21_87 = M2C_FIELD(sp, u8 *, 0xB);
    temp_r3_96 = checked_cast<Explosion4Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    this->unk54 = 1;
    this->unk50 = 2.0f;
    this->unk58 = arg_sp10;
    this->unk68 = M2C_FIELD(&arg0, f64 *, 0);
    this->unk70 = M2C_FIELD(&arg0, f64 *, 8);
    this->unk90 = 0.5f;
    temp_r3_114 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
    arg_spD60 = M2C_FIELD(temp_r3_114, f64 *, 0x30);
    arg_spD68 = M2C_FIELD(temp_r3_114, f64 *, 0x38);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r16, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    arg_spD50 = arg_sp560;
    arg_sp568 = (f32) arg_spD68 - arg0.unk8;
    arg_spD58 = (f64) arg_sp568;
    arg_spD50.Normalise();
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
    M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r0, 0x0, qr0 */);
    arg_spD58 = (f32) arg_spD58 * 2.0f;
    this->unkA4 = 0.0f;
    this->unkA0 = 0.0f;
loop_2:
    if ((u32) *this->unk98 != 0) {
        this->unk98 += 4;
        goto loop_2;
    }
    this->unk94 = arg6;
    this->unkA8 = arg7;
    this->unk64 = this->unk58;
    temp_r3_158 = this->unk4C;
    if (temp_r3_158 != NULL) {
        arg_sp160 = 1.0f;
        arg_sp164 = 0.5f;
        arg_sp168 = 0.0f;
        arg_sp16C = 1.0f;
        temp_r3_158->unk20 = (f64) arg_sp160;
        temp_r3_158->unk28 = (f64) arg_sp168;
        temp_r3_172 = temp_r3_158->unk3C;
        arg_spCB0 = (f64) arg_sp160;
        arg_spCB8 = (f64) arg_sp168;
        if (temp_r3_172 != NULL) {
            M2C_FIELD(temp_r3_172, f64 *, 0) = (f64) arg_sp160;
            M2C_FIELD(temp_r3_172, f64 *, 8) = (f64) arg_sp168;
        }
        this->unk4C->SetRadius(10000.0f * this->unk58);
        MKVector(0.0f, 1.0f, 0.0f);
        arg_spC80.operator*(1000.0f);
        arg_spC90.operator*(this->unk58);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r15, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        temp_r3_208 = this->unk4C;
        arg_spCA0 = arg_sp150;
        arg_sp158 = (f32) M2C_FIELD(this, f64 *, 0x70) + arg_spC98;
        temp_r3_208->unk10 = arg_sp150;
        temp_r3_208->unk18 = (f64) arg_sp158;
        temp_r3_214 = temp_r3_208->unk3C;
        arg_spCA8 = (f64) arg_sp158;
        if (temp_r3_214 != NULL) {
            M2C_FIELD(temp_r3_214, f64 *, 0x10) = arg_sp150;
            M2C_FIELD(temp_r3_214, f64 *, 0x18) = (f64) arg_sp158;
        }
        gb.unk80->EnableLight(this->unk4C, 1U);
    }
    var_r23_229 = 0;
    temp_r24_234 = (s32) (20.0f * this->unk58);
loop_17:
    if (var_r23_229 < temp_r24_234) {
        temp_r3_237 = M2C_FIELD(temp_r3_96, void **, 0x60);
        temp_r3_241 = M2C_FIELD(M2C_FIELD(temp_r3_237, void **, 0x44), void *(**)(void *), 0x3C)(temp_r3_237);
        if (temp_r3_241 != NULL) {
            arg_spEF4 = temp_r24_234 ^ 0x80000000;
            arg_spEF0 = 0x43300000;
            temp_r26_256 = M2C_FIELD(temp_r3_241, void **, 0x2C);
            temp_f26_260 = 6.2831855f * ((f32) var_r23_229 / (f32) temp_r24_234);
            arg_spF00 = -_table_sinf(1.5707964f + temp_f26_260);
            arg_sp140 = _table_sinf(temp_f26_260);
            arg_sp148 = arg_spF00;
            arg_sp144 = 0.0f;
            arg_spC58 = (f64) arg_sp148;
            arg_spC50 = (f64) arg_sp140;
            Normalise(*((MKVector3 *) &arg_spC60));
            arg_spD70 = arg_spC60;
            arg_spD78 = arg_spC68;
            MKVector(0.0f, this->unk58 * (200.0f * MKRand_Float(&gViewSeed, 0.0f, 1.0f)), 0.0f);
            arg_spC10.operator*(100.0f);
            arg_spC20.operator*(this->unk58);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r15, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_spC30 = arg_sp50;
            arg_sp58 = (f32) M2C_FIELD(this, f64 *, 0x70) + arg_spC28;
            arg_spC38 = (f64) arg_sp58;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            M2C_FIELD(temp_r3_241, f64 *, 0) = arg_sp130;
            arg_sp138 = (f32) arg_spC38 + arg_spC08;
            arg_spC40 = arg_sp130;
            M2C_FIELD(temp_r3_241, f64 *, 8) = (f64) arg_sp138;
            arg_spC48 = (f64) arg_sp138;
            M2C_FIELD(temp_r3_241, f32 *, 0x20) = 0.0f;
            M2C_FIELD(temp_r3_241, f32 *, 0x24) = MKRand_Float(&gViewSeed, -6.2831855f, 6.2831855f);
            temp_f4_349 = this->unk58 * MKRand_Float(&gViewSeed, 5.0f, 8.0f);
            arg_sp120 = 0.5f;
            arg_sp124 = 0.5f;
            M2C_FIELD(temp_r3_241, f32 *, 0x28) = temp_f4_349;
            arg_sp128 = 0.5f;
            arg_sp12C = 1.0f;
            M2C_FIELD(temp_r3_241, f64 *, 0x10) = (f64) arg_sp120;
            M2C_FIELD(temp_r3_241, f64 *, 0x18) = (f64) arg_sp128;
            arg_spBF0 = (f64) arg_sp120;
            temp_f22_362 = this->unk58;
            arg_spBF8 = (f64) arg_sp128;
            arg_spBD0.operator*(2000.0f);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f22 */);
            M2C_FIELD(temp_r26_256, f64 *, 0) = arg_sp110;
            arg_sp118 = arg_spBD8 * temp_f22_362;
            arg_spBE0 = arg_sp110;
            M2C_FIELD(temp_r26_256, f64 *, 8) = (f64) arg_sp118;
            arg_spBE8 = (f64) arg_sp118;
            M2C_FIELD(temp_r26_256, f32 *, 0x18) = (f32) M2C_FIELD(temp_r3_241, f32 *, 0x28);
            M2C_FIELD(temp_r26_256, f32 *, 0x10) = 2.3561945f;
            M2C_FIELD(temp_r26_256, f32 *, 0x14) = (f32) (M2C_FIELD(M2C_FIELD(temp_r3_96, void **, 0x60), f32 *, 0xF4) - MKRand_Float(&gViewSeed, 0.0f, 0.2f));
        }
        temp_r3_391 = M2C_FIELD(temp_r3_96, void **, 0x60);
        temp_r3_395 = M2C_FIELD(M2C_FIELD(temp_r3_391, void **, 0x44), void *(**)(void *), 0x3C)(temp_r3_391);
        if (temp_r3_395 != NULL) {
            arg_spEEC = temp_r24_234 ^ 0x80000000;
            arg_spEE8 = 0x43300000;
            temp_r26_410 = M2C_FIELD(temp_r3_395, void **, 0x2C);
            temp_f26_414 = 6.2831855f * ((f32) var_r23_229 / (f32) temp_r24_234);
            arg_spEFC = -_table_sinf(1.5707964f + temp_f26_414);
            arg_sp100 = _table_sinf(temp_f26_414);
            arg_sp108 = arg_spEFC;
            arg_sp104 = 0.0f;
            arg_spBB8 = (f64) arg_sp108;
            arg_spBB0 = (f64) arg_sp100;
            Normalise(*((MKVector3 *) &arg_spBC0));
            arg_spD70 = arg_spBC0;
            arg_spD78 = arg_spBC8;
            MKVector(0.0f, this->unk58 * (200.0f * MKRand_Float(&gViewSeed, 0.0f, 1.0f)), 0.0f);
            arg_spB70.operator*(100.0f);
            arg_spB80.operator*(this->unk58);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r15, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_spB90 = arg_sp40;
            arg_sp48 = (f32) M2C_FIELD(this, f64 *, 0x70) + arg_spB88;
            arg_spB98 = (f64) arg_sp48;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            M2C_FIELD(temp_r3_395, f64 *, 0) = arg_spF0;
            arg_spF8 = (f32) arg_spB98 + arg_spB68;
            arg_spBA0 = arg_spF0;
            M2C_FIELD(temp_r3_395, f64 *, 8) = (f64) arg_spF8;
            arg_spBA8 = (f64) arg_spF8;
            M2C_FIELD(temp_r3_395, f32 *, 0x20) = 0.0f;
            M2C_FIELD(temp_r3_395, f32 *, 0x24) = MKRand_Float(&gViewSeed, -6.2831855f, 6.2831855f);
            temp_f4_503 = this->unk58 * MKRand_Float(&gViewSeed, 5.0f, 8.0f);
            arg_spE0 = 0.5f;
            arg_spE4 = 0.5f;
            M2C_FIELD(temp_r3_395, f32 *, 0x28) = temp_f4_503;
            arg_spE8 = 0.5f;
            arg_spEC = 1.0f;
            M2C_FIELD(temp_r3_395, f64 *, 0x10) = (f64) arg_spE0;
            M2C_FIELD(temp_r3_395, f64 *, 0x18) = (f64) arg_spE8;
            arg_spB50 = (f64) arg_spE0;
            temp_f21_516 = this->unk58;
            arg_spB58 = (f64) arg_spE8;
            arg_spB30.operator*(2000.0f);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f21 */);
            M2C_FIELD(temp_r26_410, f64 *, 0) = arg_spD0;
            arg_spD8 = arg_spB38 * temp_f21_516;
            arg_spB40 = arg_spD0;
            M2C_FIELD(temp_r26_410, f64 *, 8) = (f64) arg_spD8;
            arg_spB48 = (f64) arg_spD8;
            M2C_FIELD(temp_r26_410, f32 *, 0x18) = (f32) M2C_FIELD(temp_r3_395, f32 *, 0x28);
            M2C_FIELD(temp_r26_410, f32 *, 0x10) = -2.3561945f;
            M2C_FIELD(temp_r26_410, f32 *, 0x14) = (f32) (M2C_FIELD(M2C_FIELD(temp_r3_96, void **, 0x60), f32 *, 0xF4) - MKRand_Float(&gViewSeed, 0.0f, 0.2f));
        }
        temp_r3_545 = M2C_FIELD(temp_r3_96, void **, 0x64);
        temp_r3_549 = M2C_FIELD(M2C_FIELD(temp_r3_545, void **, 0x44), void *(**)(void *), 0x3C)(temp_r3_545);
        if (temp_r3_549 != NULL) {
            arg_spEEC = temp_r24_234 ^ 0x80000000;
            arg_spEE8 = 0x43300000;
            temp_r26_564 = M2C_FIELD(temp_r3_549, void **, 0x2C);
            temp_f26_568 = 6.2831855f * ((f32) var_r23_229 / (f32) temp_r24_234);
            arg_spEF8 = -_table_sinf(1.5707964f + temp_f26_568);
            arg_spC0 = _table_sinf(temp_f26_568);
            arg_spC8 = arg_spEF8;
            arg_spC4 = 0.0f;
            arg_spB18 = (f64) arg_spC8;
            arg_spB10 = (f64) arg_spC0;
            Normalise(*((MKVector3 *) &arg_spB20));
            arg_spD70 = arg_spB20;
            arg_spD78 = arg_spB28;
            MKVector(0.0f, this->unk58 * (200.0f * MKRand_Float(&gViewSeed, 0.0f, 1.0f)), 0.0f);
            arg_spAD0.operator*(100.0f);
            arg_spAE0.operator*(this->unk58);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r15, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_spAF0 = arg_sp30;
            arg_sp38 = (f32) M2C_FIELD(this, f64 *, 0x70) + arg_spAE8;
            arg_spAF8 = (f64) arg_sp38;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            M2C_FIELD(temp_r3_549, f64 *, 0) = arg_spB0;
            arg_spB8 = (f32) arg_spAF8 + arg_spAC8;
            arg_spB00 = arg_spB0;
            M2C_FIELD(temp_r3_549, f64 *, 8) = (f64) arg_spB8;
            M2C_FIELD(temp_r3_549, f32 *, 0x20) = 0.0f;
            arg_spB08 = (f64) arg_spB8;
            M2C_FIELD(temp_r3_549, f32 *, 0x24) = 0.0f;
            M2C_FIELD(temp_r3_549, f32 *, 0x28) = (f32) (this->unk58 * MKRand_Float(&gViewSeed, 5.0f, 8.0f));
            temp_f20_655 = this->unk58;
            arg_spAA0.operator*(2000.0f);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f20 */);
            M2C_FIELD(temp_r26_564, f64 *, 0) = arg_spA0;
            arg_spA8 = arg_spAA8 * temp_f20_655;
            arg_spAB0 = arg_spA0;
            M2C_FIELD(temp_r26_564, f64 *, 8) = (f64) arg_spA8;
            arg_spAB8 = (f64) arg_spA8;
            M2C_FIELD(temp_r26_564, f32 *, 0x18) = (f32) M2C_FIELD(temp_r3_549, f32 *, 0x28);
            M2C_FIELD(temp_r26_564, f32 *, 0x10) = 0.0f;
            M2C_FIELD(temp_r26_564, f32 *, 0x14) = (f32) (M2C_FIELD(M2C_FIELD(temp_r3_96, void **, 0x64), f32 *, 0xF4) - MKRand_Float(&gViewSeed, 0.0f, 0.75f));
        }
        var_r23_229 += 1;
        goto loop_17;
    }
    temp_r3_686 = M2C_FIELD(temp_r3_96, void **, 0x60);
    temp_r3_690 = M2C_FIELD(M2C_FIELD(temp_r3_686, void **, 0x44), void *(**)(void *), 0x3C)(temp_r3_686);
    if (temp_r3_690 != NULL) {
        temp_r23_705 = M2C_FIELD(temp_r3_690, void **, 0x2C);
        temp_f20_709 = 6.2831855f * ((f32) var_r23_229 / (f32) temp_r24_234);
        temp_f21_712 = -_table_sinf(1.5707964f + temp_f20_709);
        temp_f1_714 = _table_sinf(temp_f20_709);
        arg_sp98 = temp_f21_712;
        arg_sp90 = temp_f1_714;
        arg_sp94 = 0.0f;
        arg_spA88 = (f64) arg_sp98;
        arg_spA80 = (f64) arg_sp90;
        Normalise(*((MKVector3 *) &arg_spA90));
        arg_spD70 = arg_spA90;
        arg_spD78 = arg_spA98;
        MKVector(0.0f, 400.0f * this->unk58, 0.0f);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r15, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        M2C_FIELD(temp_r3_690, f64 *, 0) = arg_sp80;
        arg_sp88 = (f32) M2C_FIELD(this, f64 *, 0x70) + arg_spA68;
        arg_spA70 = arg_sp80;
        M2C_FIELD(temp_r3_690, f64 *, 8) = (f64) arg_sp88;
        arg_spA78 = (f64) arg_sp88;
        M2C_FIELD(temp_r3_690, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r3_690, f32 *, 0x24) = MKRand_Float(&gViewSeed, -6.2831855f, 6.2831855f);
        M2C_FIELD(temp_r3_690, f32 *, 0x28) = (f32) (8.0f * this->unk58);
        M2C_FIELD(temp_r23_705, f32 *, 0) = 0.0f;
        M2C_FIELD(temp_r23_705, f32 *, 4) = 0.0f;
        M2C_FIELD(temp_r23_705, f32 *, 8) = 0.0f;
        M2C_FIELD(temp_r23_705, f32 *, 0x18) = (f32) M2C_FIELD(temp_r3_690, f32 *, 0x28);
        M2C_FIELD(temp_r23_705, f32 *, 0x10) = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        M2C_FIELD(temp_r23_705, f32 *, 0x14) = (f32) M2C_FIELD(M2C_FIELD(temp_r3_96, void **, 0x60), f32 *, 0xF4);
    }
    arg_spF08 = 0.0;
    arg_spF10 = 5.164075695e-315;
    arg_spF18 = 5.465589745e-315;
    var_r27_796 = 0;
loop_22:
    if (var_r27_796 < (s32) ((f32) arg_spF18 * this->unk58)) {
        arg_sp548 = 1.0f;
        arg_sp558 = -1.0f;
        arg_sp540 = 1.0f;
        arg_sp544 = 1.0f;
        arg_sp550 = -1.0f;
        arg_sp554 = (f32) arg_spF08;
        arg_spA10 = (f64) arg_sp540;
        arg_spA18 = (f64) arg_sp548;
        arg_spA20 = (f64) arg_sp550;
        arg_spA28 = (f64) arg_sp558;
        KDRand_Vector(*((MKVector3 *) &arg_spA30), *((MKVector3 *) &arg_spA20));
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r26, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r23, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_spA40 = arg_sp530;
        arg_sp538 = arg_spA38 + (f32) arg_spD58;
        arg_spA48 = (f64) arg_sp538;
        Normalise(*((MKVector3 *) &arg_spA50));
        arg_spD40 = arg_spA50;
        arg_spD48 = arg_spA58;
        temp_f21_841 = MKRand_Float(&gViewSeed, 0.0f, 1.0f);
        temp_f25_842 = this->unk58;
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r22, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f14 */);
        arg_sp9E0 = arg_sp520;
        arg_sp528 = (f32) arg_spD48 * 100.0f;
        arg_sp9E8 = (f64) arg_sp528;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r14, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f25 */);
        arg_sp9F0 = arg_sp510;
        arg_sp518 = (f32) arg_sp9E8 * temp_f25_842;
        arg_sp9F8 = (f64) arg_sp518;
        M2C_ERROR(/* unknown instruction: psq_lx $f2, $r15, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r29, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f1, $f2, $f1 */);
        arg_spA00 = arg_sp500;
        arg_sp508 = (f32) M2C_FIELD(this, f64 *, 0x70) + (f32) arg_sp9F8;
        arg_spA08 = (f64) arg_sp508;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r22, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f19 */);
        arg_sp4F8 = (f32) arg_spD48 * 6000.0f;
        arg_sp9C0 = arg_sp4F0;
        arg_sp9C8 = (f64) arg_sp4F8;
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r28, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f25 */);
        arg_sp9D0 = arg_sp4E0;
        arg_sp4E8 = (f32) arg_sp9C8 * temp_f25_842;
        arg_sp9D8 = (f64) arg_sp4E8;
        temp_f1_900 = MKRand_Float(&gViewSeed, 10.0f, 15.0f);
        arg_sp4D0 = 1.0f;
        arg_sp4D8 = 0.8f * temp_f21_841;
        arg_sp4D4 = ((f32) arg_spF10 * temp_f21_841) + 0.8f;
        arg_sp4DC = 1.0f;
        arg_sp18 = this->unk58 * temp_f1_900;
        arg_sp9B0 = (f64) arg_sp4D0;
        arg_sp9B8 = (f64) arg_sp4D8;
        gb.unk74->Emit(*((MKVector3 *) &arg_spA00), *((MKVector3 *) &arg_sp9D0), arg_sp18, *((MKVector4 *) &arg_sp9B0), -1000.0f);
        var_r27_796 += 1;
        goto loop_22;
    }
    arg_spE90.Init();
    var_r14_937 = 0;
    if (MKCollision_SphereCollide(arg0, 100.0f, (MKCollisionResult *) &arg_spE90, 1, (MKCollisionMode) 7, 0) != 0) {
        var_r14_937 = arg_spED4;
    }
    if (arg5 != 0) {
        if ((var_r14_937 & 0x10000) || (var_r14_937 & 8)) {
            var_r22_967 = 0;
loop_30:
            if (var_r22_967 < (s32) (10.0f * this->unk58)) {
                arg_sp4B8 = 1.0f;
                arg_sp4C8 = -1.0f;
                arg_sp4B0 = 1.0f;
                arg_sp4B4 = 1.0f;
                arg_sp4C0 = -1.0f;
                arg_sp4C4 = 0.0f;
                arg_sp960 = (f64) arg_sp4B0;
                arg_sp968 = (f64) arg_sp4B8;
                arg_sp970 = (f64) arg_sp4C0;
                arg_sp978 = (f64) arg_sp4C8;
                KDRand_Vector(*((MKVector3 *) &arg_sp980), *((MKVector3 *) &arg_sp970));
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r24, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r27, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp990 = arg_sp4A0;
                arg_sp4A8 = arg_sp988 + (f32) arg_spD58;
                arg_sp998 = (f64) arg_sp4A8;
                Normalise(*((MKVector3 *) &arg_sp9A0));
                arg_spD30 = arg_sp9A0;
                temp_f24_1006 = this->unk58;
                arg_spD38 = arg_sp9A8;
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r28, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f18 */);
                arg_sp930 = arg_sp490;
                arg_sp498 = (f32) arg_spD38 * 100.0f;
                arg_sp938 = (f64) arg_sp498;
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r29, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f24 */);
                arg_sp940 = arg_sp480;
                arg_sp488 = (f32) arg_sp938 * temp_f24_1006;
                arg_sp948 = (f64) arg_sp488;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $r15, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp950 = arg_sp470;
                arg_sp478 = (f32) M2C_FIELD(this, f64 *, 0x70) + (f32) arg_sp948;
                arg_sp958 = (f64) arg_sp478;
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r28, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f17 */);
                arg_sp468 = (f32) arg_spD38 * 6000.0f;
                arg_sp910 = arg_sp460;
                arg_sp918 = (f64) arg_sp468;
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r31, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f24 */);
                arg_sp920 = arg_sp450;
                arg_sp458 = (f32) arg_sp918 * temp_f24_1006;
                arg_sp928 = (f64) arg_sp458;
                temp_f25_1066 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                temp_f22_1071 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                arg_sp440 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                arg_sp444 = temp_f22_1071;
                arg_sp448 = temp_f25_1066;
                arg_sp8F0 = (f64) arg_sp440;
                arg_sp8F8 = (f64) arg_sp448;
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r14, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f16 */);
                arg_sp900 = arg_sp430;
                arg_sp438 = (f32) arg_sp8F8 * 3.1415927f;
                arg_sp908 = (f64) arg_sp438;
                temp_f25_1098 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                temp_f22_1103 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                arg_sp420 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                arg_sp424 = temp_f22_1103;
                arg_sp428 = temp_f25_1098;
                arg_sp8D0 = (f64) arg_sp420;
                arg_sp8D8 = (f64) arg_sp428;
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f15 */);
                arg_sp8E0 = arg_sp410;
                arg_sp418 = (f32) arg_sp8D8 * 3.1415927f;
                arg_sp8E8 = (f64) arg_sp418;
                gb.unkA8->Emit(*((MKVector3 *) &arg_sp950), *((MKVector3 *) &arg_sp920), *((MKVector3 *) &arg_sp900), *((MKVector3 *) &arg_sp8E0), this->unk58 * MKRand_Float(&gViewSeed, 0.75f, 1.0f), *((MKVector4 *) &arg_spEB0), 2, NULL);
                var_r22_967 += 1;
                goto loop_30;
            }
        } else if (var_r14_937 & 0x8000) {
            var_r30_1169 = 0;
loop_35:
            if (var_r30_1169 < (s32) (10.0f * this->unk58)) {
                arg_sp3F8 = 1.0f;
                arg_sp408 = -1.0f;
                arg_sp3F0 = 1.0f;
                arg_sp3F4 = 1.0f;
                arg_sp400 = -1.0f;
                arg_sp404 = 0.0f;
                arg_sp880 = (f64) arg_sp3F0;
                arg_sp888 = (f64) arg_sp3F8;
                arg_sp890 = (f64) arg_sp400;
                arg_sp898 = (f64) arg_sp408;
                KDRand_Vector(*((MKVector3 *) &arg_sp8A0), *((MKVector3 *) &arg_sp890));
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r28, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r26, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp8B0 = arg_sp3E0;
                arg_sp3E8 = arg_sp8A8 + (f32) arg_spD58;
                arg_sp8B8 = (f64) arg_sp3E8;
                Normalise(*((MKVector3 *) &arg_sp8C0));
                arg_spD20 = arg_sp8C0;
                temp_f24_1208 = this->unk58;
                arg_spD28 = arg_sp8C8;
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r24, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f15 */);
                arg_sp850 = arg_sp3D0;
                arg_sp3D8 = (f32) arg_spD28 * 100.0f;
                arg_sp858 = (f64) arg_sp3D8;
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r23, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f24 */);
                arg_sp860 = arg_sp3C0;
                arg_sp3C8 = (f32) arg_sp858 * temp_f24_1208;
                arg_sp868 = (f64) arg_sp3C8;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $r15, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r22, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp870 = arg_sp3B0;
                arg_sp3B8 = (f32) M2C_FIELD(this, f64 *, 0x70) + (f32) arg_sp868;
                arg_sp878 = (f64) arg_sp3B8;
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r24, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f16 */);
                arg_sp3A8 = (f32) arg_spD28 * 6000.0f;
                arg_sp830 = arg_sp3A0;
                arg_sp838 = (f64) arg_sp3A8;
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r14, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f24 */);
                arg_sp840 = arg_sp390;
                arg_sp398 = (f32) arg_sp838 * temp_f24_1208;
                arg_sp848 = (f64) arg_sp398;
                temp_f25_1268 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                temp_f22_1273 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                arg_sp380 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                arg_sp384 = temp_f22_1273;
                arg_sp388 = temp_f25_1268;
                arg_sp810 = (f64) arg_sp380;
                arg_sp818 = (f64) arg_sp388;
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r31, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f17 */);
                arg_sp820 = arg_sp370;
                arg_sp378 = (f32) arg_sp818 * 3.1415927f;
                arg_sp828 = (f64) arg_sp378;
                temp_f25_1300 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                temp_f22_1305 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                arg_sp360 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                arg_sp364 = temp_f22_1305;
                arg_sp368 = temp_f25_1300;
                arg_sp7F0 = (f64) arg_sp360;
                arg_sp7F8 = (f64) arg_sp368;
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f18 */);
                arg_sp800 = arg_sp350;
                arg_sp358 = (f32) arg_sp7F8 * 3.1415927f;
                arg_sp808 = (f64) arg_sp358;
                gb.unkA0->Emit(*((MKVector3 *) &arg_sp870), *((MKVector3 *) &arg_sp840), *((MKVector3 *) &arg_sp820), *((MKVector3 *) &arg_sp800), this->unk58 * MKRand_Float(&gViewSeed, 0.75f, 1.0f), *((MKVector4 *) &arg_spEB0), 0xA, NULL);
                var_r30_1169 += 1;
                goto loop_35;
            }
        } else {
            var_r27_1365 = 0;
loop_39:
            if (var_r27_1365 < (s32) (10.0f * this->unk58)) {
                arg_sp338 = 1.0f;
                arg_sp348 = -1.0f;
                arg_sp330 = 1.0f;
                arg_sp334 = 1.0f;
                arg_sp340 = -1.0f;
                arg_sp344 = 0.0f;
                arg_sp7A0 = (f64) arg_sp330;
                arg_sp7A8 = (f64) arg_sp338;
                arg_sp7B0 = (f64) arg_sp340;
                arg_sp7B8 = (f64) arg_sp348;
                KDRand_Vector(*((MKVector3 *) &arg_sp7C0), *((MKVector3 *) &arg_sp7B0));
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r24, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r22, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp7D0 = arg_sp320;
                arg_sp328 = arg_sp7C8 + (f32) arg_spD58;
                arg_sp7D8 = (f64) arg_sp328;
                Normalise(*((MKVector3 *) &arg_sp7E0));
                arg_spD10 = arg_sp7E0;
                temp_f24_1404 = this->unk58;
                arg_spD18 = arg_sp7E8;
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r14, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f15 */);
                arg_sp770 = arg_sp310;
                arg_sp318 = (f32) arg_spD18 * 100.0f;
                arg_sp778 = (f64) arg_sp318;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f24 */);
                arg_sp780 = arg_sp300;
                arg_sp308 = (f32) arg_sp778 * temp_f24_1404;
                arg_sp788 = (f64) arg_sp308;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $r15, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp790 = arg_sp2F0;
                arg_sp2F8 = (f32) M2C_FIELD(this, f64 *, 0x70) + (f32) arg_sp788;
                arg_sp798 = (f64) arg_sp2F8;
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r14, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f16 */);
                arg_sp2E8 = (f32) arg_spD18 * 6000.0f;
                arg_sp750 = arg_sp2E0;
                arg_sp758 = (f64) arg_sp2E8;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f24 */);
                arg_sp760 = arg_sp2D0;
                arg_sp2D8 = (f32) arg_sp758 * temp_f24_1404;
                arg_sp768 = (f64) arg_sp2D8;
                temp_f25_1464 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                temp_f22_1469 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                arg_sp2C0 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                arg_sp2C4 = temp_f22_1469;
                arg_sp2C8 = temp_f25_1464;
                arg_sp730 = (f64) arg_sp2C0;
                arg_sp738 = (f64) arg_sp2C8;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f17 */);
                arg_sp740 = arg_sp2B0;
                arg_sp2B8 = (f32) arg_sp738 * 3.1415927f;
                arg_sp748 = (f64) arg_sp2B8;
                temp_f25_1496 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                temp_f22_1501 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                arg_sp2A0 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                arg_sp2A4 = temp_f22_1501;
                arg_sp2A8 = temp_f25_1496;
                arg_sp710 = (f64) arg_sp2A0;
                arg_sp718 = (f64) arg_sp2A8;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f18 */);
                arg_sp720 = arg_sp290;
                arg_sp298 = (f32) arg_sp718 * 3.1415927f;
                arg_sp728 = (f64) arg_sp298;
                gb.unkA4->Emit(*((MKVector3 *) &arg_sp790), *((MKVector3 *) &arg_sp760), *((MKVector3 *) &arg_sp740), *((MKVector3 *) &arg_sp720), this->unk58 * MKRand_Float(&gViewSeed, 0.75f, 1.0f), *((MKVector4 *) &arg_spEB0), 0xA, NULL);
                var_r27_1365 += 1;
                goto loop_39;
            }
        }
    }
    var_r24_1556 = 0;
    do {
        temp_f22_1569 = 2.0f * (3.1415927f * ((f32) var_r24_1556 / 20.0f));
        temp_f21_1572 = -_table_sinf(1.5707964f + temp_f22_1569);
        arg_sp280 = _table_sinf(temp_f22_1569);
        temp_f23_1576 = this->unk58;
        arg_sp284 = 0.0f;
        arg_sp288 = temp_f21_1572;
        arg_spD00 = (f64) arg_sp280;
        arg_spD08 = (f64) arg_sp288;
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r22, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        arg_sp6E0 = arg_sp270;
        arg_sp278 = (f32) arg_spD08 * 100.0f;
        arg_sp6E8 = (f64) arg_sp278;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f23 */);
        arg_sp6F0 = arg_sp260;
        arg_sp268 = (f32) arg_sp6E8 * temp_f23_1576;
        arg_sp6F8 = (f64) arg_sp268;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r15, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_sp700 = arg_sp250;
        arg_sp258 = (f32) M2C_FIELD(this, f64 *, 0x70) + (f32) arg_sp6F8;
        arg_sp708 = (f64) arg_sp258;
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r22, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
        arg_sp248 = (f32) arg_spD08 * 3500.0f;
        arg_sp6C0 = arg_sp240;
        arg_sp6C8 = (f64) arg_sp248;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f23 */);
        arg_sp6D0 = arg_sp230;
        arg_sp238 = (f32) arg_sp6C8 * temp_f23_1576;
        arg_sp14 = 2.5f * temp_f23_1576;
        arg_sp6D8 = (f64) arg_sp238;
        gb.EmitDust(*((MKVector3 *) &arg_sp700), *((MKVector3 *) &arg_sp6D0), arg_sp14, 0.0f);
        var_r24_1556 += 1;
    } while (var_r24_1556 < 0x14);
    var_r24_1655 = 0;
loop_44:
    if (var_r24_1655 < (s32) (10.0f * this->unk58)) {
        arg_sp218 = 1.0f;
        arg_sp228 = -1.0f;
        arg_sp210 = 1.0f;
        arg_sp214 = 1.0f;
        arg_sp220 = -1.0f;
        arg_sp224 = 0.0f;
        arg_sp670 = (f64) arg_sp210;
        arg_sp678 = (f64) arg_sp218;
        arg_sp680 = (f64) arg_sp220;
        arg_sp688 = (f64) arg_sp228;
        KDRand_Vector(*((MKVector3 *) &arg_sp690), *((MKVector3 *) &arg_sp680));
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r23, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r22, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_sp6A0 = arg_sp200;
        arg_sp208 = arg_sp698 + (f32) arg_spD58;
        arg_sp6A8 = (f64) arg_sp208;
        Normalise(*((MKVector3 *) &arg_sp6B0));
        arg_spCF0 = arg_sp6B0;
        arg_spCF8 = arg_sp6B8;
        arg_spF04 = this->unk58;
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r14, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
        arg_sp640 = arg_sp1F0;
        arg_sp1F8 = (f32) arg_spCF8 * 100.0f;
        arg_sp648 = (f64) arg_sp1F8;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f0 */);
        arg_sp650 = arg_sp1E0;
        arg_sp1E8 = (f32) arg_sp648 * arg_spF04;
        arg_sp658 = (f64) arg_sp1E8;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r15, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_sp660 = arg_sp1D0;
        arg_sp1D8 = (f32) M2C_FIELD(this, f64 *, 0x70) + (f32) arg_sp658;
        arg_sp668 = (f64) arg_sp1D8;
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r14, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
        arg_sp1C8 = (f32) arg_spCF8 * 4000.0f;
        arg_sp630 = arg_sp1C0;
        arg_sp638 = (f64) arg_sp1C8;
        this->unk5C.Emit(*((MKVector3 *) &arg_sp660), *((MKVector3 *) &arg_sp630));
        var_r24_1655 += 1;
        goto loop_44;
    }
    temp_r3_1757 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
    arg_spCE0 = M2C_FIELD(temp_r3_1757, f64 *, 0x30);
    arg_spCE8 = M2C_FIELD(temp_r3_1757, f64 *, 0x38);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r16, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    arg_sp610 = arg_sp1B0;
    arg_sp1B8 = arg0.unk8 - (f32) arg_spCE8;
    arg_sp618 = (f64) arg_sp1B8;
    Normalise(*((MKVector3 *) &arg_sp620));
    arg_spCD0 = arg_sp620;
    arg_spCD8 = arg_sp628;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r15, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    arg_sp600 = arg_sp1A0;
    arg_sp1A8 = (f32) arg_spCE8 - (f32) M2C_FIELD(this, f64 *, 0x70);
    arg_sp608 = (f64) arg_sp1A8;
    temp_f0_1802 = 100.0f * (112.0f * this->unk58);
    temp_f14_1807 = ((f32) arg_sp608 * (f32) arg_sp608) + (((f32) arg_sp600 * (f32) arg_sp600) + (arg_sp604 * arg_sp604));
    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
    if (temp_f14_1807 == (temp_f0_1802 * temp_f0_1802)) {
        M2C_STRUCT_COPY((s32) &arg_spE1C + 4, (s32) (M2C_FIELD(&gb, void **, 0x3B8) + 0xAC) + 4, 0x70);
        if (arg_spE20.IsVisible(*((MKVector3 *) &this->unk68), 100.0f * (25.0f * this->unk58)) != 0) {
            temp_f0_1836 = 100.0f * (40.0f * this->unk58);
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (temp_f14_1807 == (temp_f0_1836 * temp_f0_1836)) {
                arg_sp190 = 1.0f;
                arg_sp194 = 0.8f;
                arg_sp198 = 0.0f;
                arg_sp19C = 1.0f;
                arg_sp5F0 = (f64) arg_sp190;
                arg_sp5F8 = (f64) arg_sp198;
                gb.unkB8.EnableScreenFlash(*((MKVector4 *) &arg_sp5F0), 40.0f * gUpdateTimeDelta);
            } else {
                arg_sp180 = 1.0f;
                arg_sp184 = 1.0f;
                arg_sp188 = 0.0f;
                arg_sp18C = 1.0f;
                arg_sp5E0 = (f64) arg_sp180;
                arg_sp5E8 = (f64) arg_sp188;
                gb.unkB8.EnableScreenFlash(*((MKVector4 *) &arg_sp5E0), 3.0f * gUpdateTimeDelta);
            }
        }
        if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
            temp_f2_1888 = 2000.0f * (1.0f + this->unk58);
            temp_f27_1891 = 1.0f - (temp_f14_1807 / (temp_f2_1888 * temp_f2_1888));
            if (temp_f27_1891 > 0.0f) {
                arg_spD84 = 0;
                MKVector(1.0f, 1.0f, 1.0f);
                arg_sp5C0.operator*(500.0f);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f27 */);
                arg_spD80 = 0x417;
                arg_spD88 = arg_sp70;
                arg_sp78 = arg_sp5C8 * temp_f27_1891;
                arg_spD98 = 1;
                arg_spD90 = (f64) arg_sp78;
                arg_sp5D0 = arg_sp70;
                arg_sp5D8 = (f64) arg_sp78;
                M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &arg_spD80, arg_sp70);
            }
        }
    }
    if (arg5 != 0) {
        M2C_STRUCT_COPY((s32) &arg_spDDC + 4, (s32) (&identity - 4) + 4, 0x40);
        arg_sp178 = 0.0f;
        arg_sp170 = 0.0f;
        arg_sp174 = 1.0f;
        arg_spCC8 = (f64) arg_sp178;
        arg_spCC0 = (f64) arg_sp170;
        KDMath_BuildMatrixFromFwd((Matrix *) &arg_spDE0, *((MKVector3 *) &arg_spCD0), (MKVector3 *) &arg_spCC0);
        arg_spDE0.Scale3x3((Matrix *) &arg_spDE0, 2.5f * this->unk58);
        arg_sp20 = -(f32) arg_spCD0;
        arg_sp24 = -arg_spCD4;
        arg_sp28 = -(f32) arg_spCD8;
        arg_sp570 = (f64) arg_sp20;
        arg_sp578 = (f64) arg_sp28;
        arg_sp580.operator*(700.0f);
        arg_sp590.operator*(this->unk58);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r16, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_sp5A0 = arg_sp60;
        arg_sp68 = arg0.unk8 + arg_sp598;
        arg_sp5A8 = (f64) arg_sp68;
        arg_spE10 = (f32) arg_sp5A0;
        arg_spE14 = arg_sp5A4;
        arg_spE18 = (f32) arg_sp5A8;
        arg_spE1C = 1.0f;
        gb.unk1C0.StartWarp((Matrix *) &arg_spDE0);
    }
    this->unk78 = 0.0f;
    this->unk7C = 0.0f;
    this->unk80 = 0.0f;
    if (arg2 != 0) {
        arg_spDA4 = 0;
        arg_spDA0.Init(arg3, *((MKVector3 *) &this->unk68), this->unk9C * this->unk58, 0U, 1U, 0, (f32) arg4, 0);
        M2C_FIELD(*gMK, M2C_UNK (**)(void **, M2C_UNK *, M2C_UNK, M2C_UNK, f64 *, M2C_UNK, f32), 0x94)(gMK, &arg_spDA0, 0, 0, &this->unk68, 1, this->unk9C);
    }
    temp_r3_2046 = this->unk88;
    var_r17_2047 = 0;
    var_r18_2048 = 0;
    if (temp_r3_2046 != 0) {
        var_r17_2047 = KDSound_Play3d(temp_r3_2046, (MKVector3 *) &this->unk68, 0U, -1, 0.0f, 0U);
    }
    temp_r3_2059 = this->unk8C;
    if (temp_r3_2059 != 0) {
        var_r18_2048 = KDSound_Play3d(temp_r3_2059, (MKVector3 *) &this->unk68, 0U, -1, 0.0f, 0U);
    }
    var_r14_2071 = 0;
    if ((((u32) M2C_FIELD(gb.unkC, u32 *, 0x78) != 0U) || ((u32) M2C_FIELD(gb.unkC, u32 *, 0x84) != 0U)) && (((KDStateMachine<CutsceneSystem> *) (gb.unkC + 0x24))->GetState() != 0)) {
        var_r14_2071 = 1;
    }
    if (var_r14_2071 != 0) {
        if (var_r17_2047 != 0) {
            KDSound_SetVolume(var_r17_2047, 0.25f * ((f32) KDSound_GetSoundEventVol(this->unk88) / 255.0f));
        }
        if (var_r18_2048 != 0) {
            KDSound_SetVolume(var_r18_2048, 0.25f * ((f32) KDSound_GetSoundEventVol(this->unk8C) / 255.0f));
        }
    }
    var_r14_2126 = 0;
    if ((((u32) M2C_FIELD(gb.unkC, u32 *, 0x78) != 0U) || ((u32) M2C_FIELD(gb.unkC, u32 *, 0x84) != 0U)) && (((KDStateMachine<CutsceneSystem> *) (gb.unkC + 0x24))->GetState() != 0)) {
        var_r14_2126 = 1;
    }
    if ((var_r14_2126 == 0) && (temp_r21_87 != 0)) {
        temp_f14_2145 = this->unk58;
        ((KDInput *) (M2C_FIELD(gb.unk0->__vptr, KDInput *(**)(HeroInterface *), 0x40)(gb.unk0)))->RumblePlay3D(temp_f14_2145, temp_f14_2145, 0.5f, (MKVector3 *) &this->unk68, 50.0f, 0, 4.0f, 0U);
    }
}
#endif

#if 0 // DRAFT: pointer/array required
void Explosion4::Deinit() {
    MKHeap *temp_r3_2275;
    ManagedLight *temp_r4_2254;
    u32 *temp_r31_2271;
    u32 *temp_r3_2266;

    temp_r4_2254 = this->unk4C;
    if (temp_r4_2254 != NULL) {
        gb.unk80->FreeManagedLight(temp_r4_2254);
    }
    this->unk5C.Deinit();
    do {
        temp_r3_2266 = this->unk98 - 4;
        this->unk98 = temp_r3_2266;
    } while ((u32) *temp_r3_2266 != 0);
    temp_r31_2271 = this->unk98;
    if (temp_r31_2271 != &gEmptyPtrList) {
        temp_r3_2275 = temp_r3_2266->Current();
        if (temp_r3_2275 != NULL) {
            ((MKHeap *) (temp_r3_2275->Current()))->Free(temp_r31_2271, NULL, 0);
        } else {
            free(temp_r31_2271);
        }
    }
    this->unk98 = NULL;
    MKProp::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_spBC'
void Explosion4::Draw() {
    f32 temp_f30_2343;
    f32 temp_f31_2341;
    f32 temp_f3_2351;
    this->unk5C.Draw();
    if (((s32) this->unk54 == 1) && (this->unk90 > 0.0f) && ((u8) this->unkA8 != 0)) {
        M2C_STRUCT_COPY((s32) &arg_spBC + 4, (s32) (&identity - 4) + 4, 0x40);
        temp_f31_2341 = this->unk90 / 0.5f;
        temp_f30_2343 = this->unk64;
        temp_f3_2351 = 1.0f - _table_sinf((6.2831855f * temp_f31_2341) + 1.5707964f);
        arg_sp28 = temp_f30_2343;
        arg_sp20 = this->unk64;
        arg_sp78 = (f64) arg_sp28;
        arg_sp24 = 20.0f * this->unk58 * temp_f3_2351;
        arg_sp70 = (f64) arg_sp20;
        arg_spC0.Scale3x3((Matrix *) &arg_spC0, *((MKVector3 *) &arg_sp70));
        M2C_STRUCT_COPY((s32) &arg_sp7C + 4, (s32) (&identity - 4) + 4, 0x40);
        arg_sp80.RotatePYR((Matrix *) &arg_sp80, *((MKVector3 *) &this->unk78));
        MKVector(0.0f, 200.0f * this->unk58, 0.0f);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_sp60 = arg_sp10;
        arg_sp18 = M2C_FIELD(this, f32 *, 0x70) + arg_sp58;
        arg_sp68 = (f64) arg_sp18;
        arg_spB0 = (f32) arg_sp60;
        arg_spB4 = arg_sp64;
        arg_spB8 = (f32) arg_sp68;
        arg_spBC = 1.0f;
        arg_spC0.Multiply4x4((Matrix *) &arg_spC0, (Matrix *) &arg_sp80);
        MKModel_SetWorldMatrix(M2C_FIELD(checked_cast<Explosion4Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKModel **, 0x68), *((Matrix *) &arg_spC0));
        arg_sp30 = temp_f31_2341;
        arg_sp34 = temp_f31_2341;
        arg_sp38 = temp_f31_2341;
        arg_sp3C = 1.0f;
        arg_sp40 = (f64) arg_sp30;
        arg_sp48 = (f64) arg_sp38;
        MKModel_SetColor(M2C_FIELD(checked_cast<Explosion4Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKModel **, 0x68), *((MKVector4 *) &arg_sp40));
        MKModel_Draw(M2C_FIELD(checked_cast<Explosion4Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKModel **, 0x68), NULL);
    }
}
#endif

#if 0 // DRAFT: pointer/array required
void Explosion4::Update() {
    s8 sp406;
    s8 sp405;
    s8 sp404;
    s32 sp400;
    u32 **sp3FC;
    s32 sp3F8;
    s32 sp3F4;
    s32 sp3F0;
    f32 sp3EC;
    f32 sp3E8;
    f64 sp3E0;
    f64 sp3D8;
    s32 sp3D0;
    s32 sp3CC;
    s32 sp3C8;
    f64 sp3C0;
    f64 sp3B8;
    f64 sp3B0;
    f64 sp3A8;
    f64 sp3A0;
    f64 sp398;
    f64 sp390;
    f64 sp388;
    f64 sp380;
    f64 sp378;
    f64 sp370;
    f64 sp368;
    f64 sp360;
    f64 sp358;
    f64 sp350;
    f64 sp348;
    f64 sp340;
    f64 sp338;
    f64 sp330;
    f64 sp328;
    MKVector3 sp318;
    f64 sp310;
    f64 sp308;
    f64 sp300;
    f64 sp2F8;
    f64 sp2F0;
    f64 sp2E8;
    f64 sp2E0;
    f64 sp2D8;
    f64 sp2D0;
    f64 sp2C8;
    f64 sp2C0;
    f64 sp2B8;
    f64 sp2B0;
    f64 sp2A8;
    f64 sp2A0;
    f64 sp298;
    MKVector3 sp288;
    f64 sp280;
    f64 sp278;
    f64 sp270;
    f64 sp268;
    f64 sp260;
    f64 sp258;
    f64 sp250;
    f64 sp248;
    f64 sp240;
    f64 sp238;
    f64 sp230;
    f64 sp228;
    f64 sp220;
    f64 sp218;
    f64 sp210;
    f64 sp208;
    MKVector3 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f32 sp1B0;
    f32 sp1A0;
    f32 sp19C;
    f32 sp198;
    f32 sp190;
    f32 sp180;
    f32 sp17C;
    f32 sp178;
    f32 sp170;
    f32 sp16C;
    f32 sp168;
    f32 sp160;
    f32 sp150;
    f32 sp140;
    f32 sp130;
    f32 sp12C;
    f32 sp128;
    f32 sp120;
    f32 sp110;
    f32 sp10C;
    f32 sp108;
    f32 sp100;
    f32 spFC;
    f32 spF8;
    f32 spF0;
    f32 spE0;
    f32 spD0;
    f32 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB0;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp80;
    f32 sp70;
    f32 sp60;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Character *temp_r28_2596;
    ManagedLight *temp_r3_2515;
    ManagedLight *temp_r4_2504;
    ManagedLight *temp_r4_2537;
    TargetManager ***var_r30_2585;
    TargetManager **temp_r29_2699;
    f32 temp_f0_2522;
    f32 temp_f0_3095;
    f32 temp_f1_2498;
    f32 temp_f1_2645;
    f32 temp_f1_2831;
    f32 temp_f29_3015;
    f32 temp_f30_2881;
    f32 temp_f31_2747;
    f32 temp_f4_2563;
    f32 temp_f6_2965;
    f32 var_f0_2472;
    f64 temp_f2_2672;
    f64 temp_f3_2671;
    s32 temp_cr0_eq_2609;
    s32 temp_r0_2487;
    void *temp_r28_2745;
    void *temp_r28_2879;
    void *temp_r28_3013;
    void *temp_r3_2524;
    void *temp_r3_2555;
    void *temp_r3_2626;
    void *temp_r3_2729;
    void *temp_r3_2731;
    void *temp_r3_2735;
    void *temp_r3_2865;
    void *temp_r3_2869;
    void *temp_r3_2999;
    void *temp_r3_3003;

    var_f0_2472 = this->unk90 - gUpdateTimeDelta;
    if (var_f0_2472 < 0.5f) {

    } else {
        var_f0_2472 = 0.5f;
    }
    if (var_f0_2472 > 0.0f) {

    } else {
        var_f0_2472 = 0.0f;
    }
    this->unk90 = var_f0_2472;
    temp_r0_2487 = this->unk54;
    if (temp_r0_2487 != 1) {
        if (temp_r0_2487 < 1) {

        }
    } else {
        this->unk50 -= gUpdateTimeDelta;
        temp_f1_2498 = this->unk50;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (temp_f1_2498 == 0.0f) {
            this->unk54 = 0;
            temp_r4_2504 = this->unk4C;
            if (temp_r4_2504 != NULL) {
                gb.unk80->EnableLight(temp_r4_2504, 0U);
            }
        } else {
            temp_r3_2515 = this->unk4C;
            if (temp_r3_2515 != NULL) {
                temp_f0_2522 = temp_f1_2498 * 0.5f * (10000.0f * this->unk58);
                temp_r3_2515->unk38 = temp_f0_2522;
                temp_r3_2524 = temp_r3_2515->unk3C;
                if (temp_r3_2524 != NULL) {
                    M2C_FIELD(temp_r3_2524, f32 *, 0x20) = temp_f0_2522;
                    M2C_FIELD(temp_r3_2524, f32 *, 0x24) = (f32) (temp_f0_2522 * temp_f0_2522);
                    M2C_FIELD(temp_r3_2524, f32 *, 0x28) = (f32) (1.0f / temp_f0_2522);
                    M2C_FIELD(temp_r3_2524, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_2524, f32 *, 0x24));
                }
                temp_r4_2537 = this->unk4C;
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f3 */);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $r3, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f3 */);
                sp3C0 = sp1C0;
                unksp3C4 = 1.0f;
                temp_r4_2537->unk20 = sp1B8;
                sp3B8 = sp1B8;
                temp_r4_2537->unk28 = sp3C0;
                temp_r3_2555 = temp_r4_2537->unk3C;
                if (temp_r3_2555 != NULL) {
                    M2C_FIELD(temp_r3_2555, f64 *, 0) = sp1B8;
                    M2C_FIELD(temp_r3_2555, f64 *, 8) = sp3C0;
                }
            }
            temp_f4_2563 = this->unk58;
            this->unk64 = (100.0f * temp_f4_2563 * (1.0f - (this->unk90 / 0.5f))) + temp_f4_2563;
            if ((this->unk90 > 0.0f) && ((u8) this->unk94 != 0) && ((u8) this->unkA8 != 0)) {
                var_r30_2585 = gb.unk20->Begin();
loop_30:
                if (var_r30_2585 != NULL) {
                    temp_r29_2699 = *var_r30_2585;
                    if (temp_r29_2699 != NULL) {
                        temp_r28_2596 = ((Character *(*)(TargetManager **)) (*temp_r29_2699)->unk8.unk4)(temp_r29_2699);
                        if (((*temp_r29_2699)->unk8.unk0(temp_r29_2699) != NULL) && (M2C_FIELD(*temp_r29_2699, u8 (**)(TargetManager **), 0x18)(temp_r29_2699) != 0) && ((temp_cr0_eq_2609 = temp_r28_2596 == NULL, (temp_cr0_eq_2609 != 0)) || ((temp_cr0_eq_2609 == 0) && (temp_r28_2596->IsActive() != 0) && (temp_r28_2596->IsKnockedUp() == 0)))) {
                            temp_r3_2626 = M2C_FIELD((*temp_r29_2699)->unk8.unk0(temp_r29_2699), void **, 8);
                            sp368 = M2C_FIELD(temp_r3_2626, f64 *, 0x30);
                            sp370 = M2C_FIELD(temp_r3_2626, f64 *, 0x38);
                            M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
                            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                            sp3A8 = sp1A8;
                            sp1B0 = (f32) sp370 - M2C_FIELD(this, f32 *, 0x70);
                            temp_f1_2645 = 25.0f * this->unk64;
                            sp3B0 = (f64) sp1B0;
                            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                            if ((((f32) sp3B0 * (f32) sp3B0) + (((f32) sp3A8 * (f32) sp3A8) + (unksp3AC * unksp3AC))) == (temp_f1_2645 * temp_f1_2645)) {
                                sp3CC = 0;
                                sp3C8 = 4;
                                sp3D0 = 0;
                                temp_f3_2671 = this->unk68;
                                temp_f2_2672 = this->unk70;
                                sp3D8 = temp_f3_2671;
                                sp3E0 = temp_f2_2672;
                                sp3E8 = 0.0f;
                                sp404 = 0;
                                sp3F0 = 8;
                                sp3F8 = 0x1001;
                                sp405 = 0;
                                sp406 = 0;
                                sp3F4 = -1;
                                sp3FC = &this->unk98;
                                sp400 = 0;
                                sp3EC = 1.0f;
                                M2C_FIELD(M2C_FIELD((*temp_r29_2699)->unk8.unk0(temp_r29_2699, -1, 0x1001, 8, 0, 0.0f, temp_f2_2672, temp_f3_2671), void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp3C8);
                            }
                        }
                        var_r30_2585 += 4;
                        goto loop_30;
                    }
                }
            }
            this->unkA4 -= gUpdateTimeDelta;
            this->unkA0 += 1500.0f * this->unk58 * gUpdateTimeDelta;
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if ((2.0f - this->unk50) == 0.5f) {
                M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                if (this->unkA4 == 0.0f) {
                    this->unkA4 = 0.1f;
                    temp_r3_2729 = checked_cast<Explosion4Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
                    temp_r3_2731 = M2C_FIELD(temp_r3_2729, void **, 0x60);
                    temp_r3_2735 = M2C_FIELD(M2C_FIELD(temp_r3_2731, void **, 0x44), void *(**)(void *), 0x3C)(temp_r3_2731);
                    if (temp_r3_2735 != NULL) {
                        sp180 = -1.0f;
                        temp_r28_2745 = M2C_FIELD(temp_r3_2735, void **, 0x2C);
                        sp170 = 1.0f;
                        temp_f31_2747 = this->unk58;
                        sp178 = -1.0f;
                        sp17C = 0.0f;
                        sp168 = 1.0f;
                        sp16C = 0.0f;
                        sp308 = (f64) sp178;
                        sp310 = (f64) sp180;
                        sp2F8 = (f64) sp168;
                        sp300 = (f64) sp170;
                        KDRand_Vector(sp318, *((MKVector3 *) &sp308));
                        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
                        sp328 = sp158;
                        sp160 = sp318.unk8 * 200.0f;
                        sp330 = (f64) sp160;
                        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
                        sp1A0 = 0.0f;
                        sp150 = (f32) sp330 * temp_f31_2747;
                        sp198 = 0.0f;
                        sp19C = this->unkA0;
                        sp338 = sp148;
                        sp348 = (f64) sp198;
                        sp340 = (f64) sp150;
                        sp350 = (f64) sp1A0;
                        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
                        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                        sp358 = sp188;
                        sp190 = M2C_FIELD(this, f32 *, 0x70) + (f32) sp350;
                        sp360 = (f64) sp190;
                        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                        M2C_FIELD(temp_r3_2735, f64 *, 0) = sp138;
                        sp398 = sp138;
                        sp140 = (f32) sp360 + (f32) sp340;
                        M2C_FIELD(temp_r3_2735, f64 *, 8) = (f64) sp140;
                        sp3A0 = (f64) sp140;
                        M2C_FIELD(temp_r3_2735, f32 *, 0x20) = 0.0f;
                        M2C_FIELD(temp_r3_2735, f32 *, 0x24) = MKRand_Float(&gViewSeed, -6.2831855f, 6.2831855f);
                        temp_f1_2831 = this->unk58 * MKRand_Float(&gViewSeed, 5.0f, 8.0f);
                        sp50 = 0.0f;
                        M2C_FIELD(temp_r3_2735, f32 *, 0x28) = temp_f1_2831;
                        sp48 = 0.0f;
                        sp38 = 0.5f;
                        sp4C = 1000.0f * this->unk58;
                        sp3C = 0.5f;
                        M2C_FIELD(temp_r28_2745, f64 *, 0) = (f64) sp48;
                        M2C_FIELD(temp_r28_2745, f64 *, 8) = (f64) sp50;
                        sp40 = 0.5f;
                        M2C_FIELD(temp_r28_2745, f32 *, 0x18) = (f32) M2C_FIELD(temp_r3_2735, f32 *, 0x28);
                        M2C_FIELD(temp_r28_2745, f32 *, 0x10) = 2.3561945f;
                        sp44 = 1.0f;
                        M2C_FIELD(temp_r28_2745, f32 *, 0x14) = (f32) M2C_FIELD(M2C_FIELD(temp_r3_2729, void **, 0x60), f32 *, 0xF4);
                        M2C_FIELD(temp_r3_2735, f64 *, 0x10) = (f64) sp38;
                        sp2E8 = (f64) sp48;
                        sp2F0 = (f64) sp50;
                        sp2D8 = (f64) sp38;
                        sp2E0 = (f64) sp40;
                        M2C_FIELD(temp_r3_2735, f64 *, 0x18) = (f64) sp40;
                    }
                    temp_r3_2865 = M2C_FIELD(temp_r3_2729, void **, 0x60);
                    temp_r3_2869 = M2C_FIELD(M2C_FIELD(temp_r3_2865, void **, 0x44), void *(**)(void *), 0x3C)(temp_r3_2865);
                    if (temp_r3_2869 != NULL) {
                        sp110 = -1.0f;
                        temp_r28_2879 = M2C_FIELD(temp_r3_2869, void **, 0x2C);
                        sp100 = 1.0f;
                        temp_f30_2881 = this->unk58;
                        sp108 = -1.0f;
                        sp10C = 0.0f;
                        spF8 = 1.0f;
                        spFC = 0.0f;
                        sp278 = (f64) sp108;
                        sp280 = (f64) sp110;
                        sp268 = (f64) spF8;
                        sp270 = (f64) sp100;
                        KDRand_Vector(sp288, *((MKVector3 *) &sp278));
                        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f27 */);
                        sp298 = spE8;
                        spF0 = sp288.unk8 * 200.0f;
                        sp2A0 = (f64) spF0;
                        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
                        sp130 = 0.0f;
                        spE0 = (f32) sp2A0 * temp_f30_2881;
                        sp128 = 0.0f;
                        sp12C = this->unkA0;
                        sp2A8 = spD8;
                        sp2B8 = (f64) sp128;
                        sp2B0 = (f64) spE0;
                        sp2C0 = (f64) sp130;
                        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
                        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                        sp2C8 = sp118;
                        sp120 = M2C_FIELD(this, f32 *, 0x70) + (f32) sp2C0;
                        sp2D0 = (f64) sp120;
                        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                        M2C_FIELD(temp_r3_2869, f64 *, 0) = spC8;
                        sp388 = spC8;
                        spD0 = (f32) sp2D0 + (f32) sp2B0;
                        M2C_FIELD(temp_r3_2869, f64 *, 8) = (f64) spD0;
                        sp390 = (f64) spD0;
                        M2C_FIELD(temp_r3_2869, f32 *, 0x20) = 0.0f;
                        M2C_FIELD(temp_r3_2869, f32 *, 0x24) = MKRand_Float(&gViewSeed, -6.2831855f, 6.2831855f);
                        temp_f6_2965 = this->unk58 * MKRand_Float(&gViewSeed, 5.0f, 8.0f);
                        sp28 = 0.5f;
                        sp2C = 0.5f;
                        M2C_FIELD(temp_r3_2869, f32 *, 0x28) = temp_f6_2965;
                        sp30 = 0.5f;
                        sp34 = 1.0f;
                        M2C_FIELD(temp_r3_2869, f64 *, 0x10) = (f64) sp28;
                        M2C_FIELD(temp_r3_2869, f64 *, 0x18) = (f64) sp30;
                        sp20 = 0.0f;
                        sp18 = 0.0f;
                        sp1C = 1000.0f * this->unk58;
                        sp258 = (f64) sp28;
                        M2C_FIELD(temp_r28_2879, f64 *, 0) = (f64) sp18;
                        M2C_FIELD(temp_r28_2879, f64 *, 8) = (f64) sp20;
                        sp260 = (f64) sp30;
                        M2C_FIELD(temp_r28_2879, f32 *, 0x18) = (f32) M2C_FIELD(temp_r3_2869, f32 *, 0x28);
                        M2C_FIELD(temp_r28_2879, f32 *, 0x10) = -2.3561945f;
                        sp248 = (f64) sp18;
                        sp250 = (f64) sp20;
                        M2C_FIELD(temp_r28_2879, f32 *, 0x14) = (f32) M2C_FIELD(M2C_FIELD(temp_r3_2729, void **, 0x60), f32 *, 0xF4);
                    }
                    temp_r3_2999 = M2C_FIELD(temp_r3_2729, void **, 0x64);
                    temp_r3_3003 = M2C_FIELD(M2C_FIELD(temp_r3_2999, void **, 0x44), void *(**)(void *), 0x3C)(temp_r3_2999);
                    if (temp_r3_3003 != NULL) {
                        spA0 = -1.0f;
                        temp_r28_3013 = M2C_FIELD(temp_r3_3003, void **, 0x2C);
                        sp90 = 1.0f;
                        temp_f29_3015 = this->unk58;
                        sp98 = -1.0f;
                        sp9C = 0.0f;
                        sp88 = 1.0f;
                        sp8C = 0.0f;
                        sp1E8 = (f64) sp98;
                        sp1F0 = (f64) spA0;
                        sp1D8 = (f64) sp88;
                        sp1E0 = (f64) sp90;
                        KDRand_Vector(sp1F8, *((MKVector3 *) &sp1E8));
                        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
                        sp208 = sp78;
                        sp80 = sp1F8.unk8 * 200.0f;
                        sp210 = (f64) sp80;
                        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
                        spC0 = 0.0f;
                        sp70 = (f32) sp210 * temp_f29_3015;
                        spB8 = 0.0f;
                        spBC = this->unkA0;
                        sp218 = sp68;
                        sp228 = (f64) spB8;
                        sp220 = (f64) sp70;
                        sp230 = (f64) spC0;
                        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
                        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                        sp238 = spA8;
                        spB0 = M2C_FIELD(this, f32 *, 0x70) + (f32) sp230;
                        sp240 = (f64) spB0;
                        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                        M2C_FIELD(temp_r3_3003, f64 *, 0) = sp58;
                        sp378 = sp58;
                        sp60 = (f32) sp240 + (f32) sp220;
                        M2C_FIELD(temp_r3_3003, f64 *, 8) = (f64) sp60;
                        M2C_FIELD(temp_r3_3003, f32 *, 0x20) = 0.0f;
                        sp380 = (f64) sp60;
                        M2C_FIELD(temp_r3_3003, f32 *, 0x24) = 0.0f;
                        temp_f0_3095 = this->unk58 * MKRand_Float(&gViewSeed, 5.0f, 8.0f);
                        sp10 = 0.0f;
                        M2C_FIELD(temp_r3_3003, f32 *, 0x28) = temp_f0_3095;
                        sp8 = 0.0f;
                        sp1D0 = (f64) sp10;
                        spC = 1000.0f * this->unk58;
                        M2C_FIELD(temp_r28_3013, f64 *, 0) = (f64) sp8;
                        M2C_FIELD(temp_r28_3013, f64 *, 8) = (f64) sp10;
                        sp1C8 = (f64) sp8;
                        M2C_FIELD(temp_r28_3013, f32 *, 0x18) = (f32) M2C_FIELD(temp_r3_3003, f32 *, 0x28);
                        M2C_FIELD(temp_r28_3013, f32 *, 0x10) = 0.0f;
                        M2C_FIELD(temp_r28_3013, f32 *, 0x14) = (f32) M2C_FIELD(M2C_FIELD(temp_r3_2729, void **, 0x64), f32 *, 0xF4);
                    }
                }
            }
        }
    }
    this->unk5C.Update();
}
#endif

#if 0 // DRAFT: pointer/array required
void Explosion4::Resolve() {
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
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    ManagedLight *temp_r4_3181;

    MKProp::Resolve();
    sp20 = 0.0f;
    sp30 = 0.0f;
    sp8 = 1.0f;
    spC = 1.0f;
    sp10 = 1.0f;
    sp14 = 1.0f;
    sp18 = 0.0f;
    sp1C = 0.0f;
    sp28 = 0.0f;
    sp2C = 0.0f;
    sp38 = (f64) sp8;
    sp40 = (f64) sp10;
    sp48 = (f64) sp18;
    sp50 = (f64) sp20;
    sp58 = (f64) sp28;
    sp60 = (f64) sp30;
    this->unk4C = gb.unk80->AllocManagedLight(*((MKVector3 *) &sp58), *((MKVector3 *) &sp48), *((MKVector4 *) &sp38), 1000.0f, lit_762, lit_763);
    temp_r4_3181 = this->unk4C;
    if (temp_r4_3181 != NULL) {
        gb.unk80->EnableLight(temp_r4_3181, 0U);
    }
}
#endif

#if 0 // DRAFT: ')' expected
void Explosion4::LoadDone() {
    MKProp::LoadDone();
    this->unk88 = M2C_FIELD(checked_cast<Explosion4Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x6C);
    this->unk8C = M2C_FIELD(checked_cast<Explosion4Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x70);
}
#endif

#if 0 // DRAFT: pointer/array required
void Explosion4::Init() {
    MKHeap *temp_r3_3240;
    s32 var_ctr_3260;
    u32 *temp_r3_3262;
    u32 *temp_r3_3267;
    u32 *var_r3_3247;

    MKProp::Init();
    this->unk4C = NULL;
    this->unk54 = 0;
    this->unk5C.Init();
    this->unk88 = 0;
    this->unk8C = 0;
    this->unk94 = 1;
    this->unk9C = 1500.0f;
    temp_r3_3240 = NULL->Current();
    if (temp_r3_3240 != NULL) {
        var_r3_3247 = ((MKHeap *) (temp_r3_3240->Current()))->Alloc(0x30, NULL, 0);
    } else {
        var_r3_3247 = malloc(0x30);
    }
    this->unk98 = var_r3_3247;
    M2C_FIELD(this->unk98, u32 *, 0) = 0;
    var_ctr_3260 = 0xA;
    do {
        temp_r3_3262 = this->unk98;
        this->unk98 = temp_r3_3262 + 4;
        M2C_FIELD(temp_r3_3262, s32 *, 4) = 0xDEADBEEF;
        var_ctr_3260 -= 1;
    } while (var_ctr_3260 != 0);
    temp_r3_3267 = this->unk98;
    this->unk98 = temp_r3_3267 + 4;
    M2C_FIELD(temp_r3_3267, s32 *, 4) = 0;
}
#endif

void Explosion4Descriptor::Deinit() {
    MKModel_Destroy(this->unk68);
    MKPropDescriptor::Deinit();
}

#if 0 // DRAFT: undefined identifier 'lit_stringBase0'
s32 Explosion4Descriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_3307;

    var_r31_3307 = 0;
    if ((MKPropDescriptor::LoadLine(arg0) != 0) || (KDSound_LoadLine(arg0, lit_stringBase0, &this->unk6C) != 0) || (KDSound_LoadLine(arg0, &lit_stringBase0[0xB], &this->unk70) != 0)) {
        var_r31_3307 = 1;
    }
    return var_r31_3307;
}
#endif

#if 0 // DRAFT: expression syntax error
void Explosion4Descriptor::Init() {
    MKPropDescriptor::Init();
    this->unk6C = GS_Explosion2;
    this->unk70 = GS_Rumble1Soft;
    this->unk60 = checked_cast<KDEnvParticleSystem *, MKProp>(gMK->CreateProp(&lit_stringBase0[0x1C]));
    this->unk64 = checked_cast<KDEnvParticleSystem *, MKProp>(gMK->CreateProp(&lit_stringBase0[0x28]));
    this->unk68 = MKModel_Create(&lit_stringBase0[0x34], NULL, 2, NULL);
}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<Explosion4Descriptor *, MKPropDescriptor>(MKPropDescriptor *arg0) {

}
#endif
