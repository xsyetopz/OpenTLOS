#include "spyro/source/FuryFXFire.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Coronas.h"
#include "spyro/source/FuryFX.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSynkerPlayer3.h"
#include "spyro/source/ManagedLight.h"
#include "spyro/source/ShapedTrailFX.h"
#include "spyro/source/Spyro.h"
#include "common/Source/MKView.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDMath.h"
#include <m2c_macros.h>

M2C_UNK __destroy_arr(M2C_UNK *, FuryFXFire::DragonStruct *(*)(FuryFXFire::DragonStruct *, s16), M2C_UNK, M2C_UNK); /* extern */
extern s32 GS_CynderFuryBuildUp2;
extern s32 GS_CynderFuryExtra1;
extern s32 GS_CynderFuryImpact;
extern s32 GS_CynderFuryLP;
extern s32 GS_Rumble1;
extern s32 GS_SpyroFuryAttack1;
extern s32 GS_SpyroFuryAttack2;
extern s32 GS_SpyroFuryAttack3;
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern void **gMK;
extern f32 gRenderState;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;

static s32 lit_761 = 0;
static u8 lit_762 = 1;

static s32 lit_766 = 0;
static u8 lit_767 = 0;
static s32 lit_774 = -1;
static s32 lit_775 = 6;

static u8 lit_845 = 1;
static u8 lit_910 = 0;

static u8 lit_1163 = 0;
#if 0 // DRAFT: pointer/array required
static s8 lit_stringBase0[0x53] = {
    0x46,
    0x58,
    0x5F,
    0x33,
    0x36,
    0x37,
    0,
    0x46,
    0x58,
    0x5F,
    0x46,
    0x6C,
    0x61,
    0x6D,
    0x65,
    0x57,
    0x61,
    0x6C,
    0x6C,
    0,
    0x46,
    0x78,
    0x30,
    0x30,
    0x31,
    0x39,
    0x5F,
    0x46,
    0x69,
    0x72,
    0x65,
    0x46,
    0x75,
    0x72,
    0x79,
    0x42,
    0x6C,
    0x61,
    0x73,
    0x74,
    0,
    0x49,
    0x63,
    0x65,
    0x53,
    0x68,
    0x61,
    0x72,
    0x64,
    0,
    0x53,
    0x68,
    0x61,
    0x70,
    0x65,
    0x64,
    0x54,
    0x72,
    0x61,
    0x69,
    0x6C,
    0x46,
    0x58,
    0,
    0x66,
    0x78,
    0x5F,
    0x63,
    0x79,
    0x6E,
    0x64,
    0x65,
    0x72,
    0x46,
    0x75,
    0x72,
    0x79,
    0x46,
    0x6C,
    0x61,
    0x6D,
    0x65,
    0,
}; /* const */

void FuryFXFire::ResetFury() {
    s32 spC;
    s32 sp8;
    f32 temp_r4_118;
    f32 temp_r4_63;
    s32 var_r27_97;
    s32 var_r30_96;
    void *temp_r28_100;
    void *temp_r4_107;
    void *temp_r5_102;

    SetDefaults();
    temp_r4_63 = this->unk90.unk58;
    if (M2C_BITWISE(u32, temp_r4_63) != 0U) {
        gb.unk80->EnableLight(M2C_BITWISE(ManagedLight *, temp_r4_63), 0U);
    }
    gb.unkD0 = 0;
    gb.unk2CC.Disable(this->unk2E8);
    this->unk2E8 = -1;
    if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
        spC = 0;
        sp8 = 0x459;
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    }
    var_r30_96 = 0;
    var_r27_97 = 0;
    do {
        temp_r28_100 = this + var_r30_96;
        temp_r5_102 = M2C_FIELD(temp_r28_100, void **, 0x130);
        M2C_FIELD(temp_r5_102, u8 *, 0xA0) = (u8) ((M2C_FIELD(temp_r5_102, u8 *, 0xA0) & ~0x80) | ((lit_1163 << 7) & 0x80));
        temp_r4_107 = M2C_FIELD(temp_r28_100, void **, 0x130);
        M2C_FIELD(temp_r4_107, u8 *, 0xA0) = (u8) (M2C_FIELD(temp_r4_107, u8 *, 0xA0) & ~0x40);
        KDSound_Stop(temp_r28_100 + 0x134);
        KDSound_Stop(temp_r28_100 + 0x15C);
        var_r27_97 += 1;
        var_r30_96 += 0x80;
    } while (var_r27_97 < 3);
    temp_r4_118 = this->unk90.unk64;
    if (M2C_BITWISE(u32, temp_r4_118) != 0U) {
        M2C_FIELD(temp_r4_118, u8 *, 0x31) = (u8) (M2C_FIELD(temp_r4_118, u8 *, 0x31) & ~0x40);
    }
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'HeroHurtReactionType'
s32 FuryFXFire::Trigger(const MKVector3 &arg0, bool arg1, bool arg2, HeroHurtReactionType arg3) {
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    M2C_UNK sp58;
    f64 sp50;
    f64 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Matrix *temp_r3_198;
    s32 temp_r0_270;
    s32 temp_r29_293;
    s32 temp_r3_268;
    s32 var_ctr_176;
    s32 var_ctr_239;
    s32 var_r30_286;
    s32 var_r3_174;
    s32 var_r3_219;
    u8 var_r3_276;
    void *temp_r4_179;
    void *temp_r4_242;
    void *temp_r5_272;

    if (M2C_BITWISE(s32, this->unk90.unk74) == 0) {
        M2C_FIELD(this, u8 *, 0x2F0) = arg1;
        M2C_FIELD(this, u8 *, 0x2F1) = arg2;
        this->unk2E8 = (s32) arg3;
        if ((u8) M2C_FIELD(this, u8 *, 0x2F1) == 0) {
            this->unk90.unk30 = arg0.unk0;
            this->unk90.unk34 = arg0.unk4;
            this->unk90.unk38 = arg0.unk8;
            this->unk90.unk3C = 1.0f;
            this->unk2E8 = gb.unk2CC.Enable(0.5f, 0.0f, 0.0f, -1.0f);
            this->unk90.unk70 = 1.0f;
            var_r3_174 = 0;
            gb.unk381 = 1;
            var_ctr_176 = 3;
            do {
                temp_r4_179 = *(this + (var_r3_174 + 0x130));
                if (temp_r4_179 != NULL) {
                    sp38 = 1.0f;
                    sp3C = 1.0f;
                    sp40 = 1.0f;
                    sp44 = 1.0f;
                    M2C_FIELD(temp_r4_179, f64 *, 0x50) = (f64) sp38;
                    sp88 = (f64) sp38;
                    sp90 = (f64) sp40;
                    M2C_FIELD(temp_r4_179, f64 *, 0x58) = (f64) sp40;
                }
                var_r3_174 += 0x80;
                var_ctr_176 -= 1;
            } while (var_ctr_176 != 0);
        } else {
            temp_r3_198 = &this->unk90;
            sp30 = 1.0f;
            sp28 = 1.0f;
            sp2C = 3.0f;
            sp80 = (f64) sp30;
            sp78 = (f64) sp28;
            temp_r3_198->Scale3x3(temp_r3_198, *((MKVector3 *) &sp78));
            MKVector(0.0f, 600.0f, 0.0f);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r29, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            var_r3_219 = 0;
            sp68 = sp18;
            sp20 = arg0.unk8 - sp60;
            this->unk90.unk30 = (f32) sp68;
            sp70 = (f64) sp20;
            this->unk90.unk34 = unksp6C;
            this->unk90.unk38 = (f32) sp70;
            this->unk90.unk3C = 1.0f;
            this->unk90.unk70 = 0.0f;
            var_ctr_239 = 3;
            do {
                temp_r4_242 = *(this + (var_r3_219 + 0x130));
                if (temp_r4_242 != NULL) {
                    sp8 = 1.0f;
                    spC = 0.0f;
                    sp10 = 0.0f;
                    sp14 = 1.0f;
                    M2C_FIELD(temp_r4_242, f64 *, 0x50) = (f64) sp8;
                    sp48 = (f64) sp8;
                    sp50 = (f64) sp10;
                    M2C_FIELD(temp_r4_242, f64 *, 0x58) = (f64) sp10;
                }
                var_r3_219 += 0x80;
                var_ctr_239 -= 1;
            } while (var_ctr_239 != 0);
        }
        this->unk90.unk68 = 0.0f;
        this->unk90.unk6C = 0.0f;
        this->unk90.unk74 = 1e-45f;
        temp_r3_268 = gameData.unk158 << 5;
        temp_r0_270 = *(&gameData.unk70 + (temp_r3_268 + 0x7C));
        temp_r5_272 = &gameData.unk70 + (temp_r3_268 + 0x64);
        if (temp_r0_270 == 3) {
            var_r3_276 = 0;
            if (((s32) M2C_FIELD(temp_r5_272, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r5_272, s32 *, 4) == 3)) {
                var_r3_276 = 1;
            }
            var_r30_286 = var_r3_276 != 0;
        } else {
            var_r30_286 = *(temp_r5_272 + (temp_r0_270 * 4));
        }
        temp_r29_293 = gameData.unk158;
        this->unk290.Init(M2C_FIELD(gb.unk0->__vptr, MKProp *(**)(HeroInterface *), 0xC)(gb.unk0), 15.0f * gb.unk37C, 3, var_r30_286, temp_r29_293, temp_r29_293, 0, -1);
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void FuryFXFire::SetDefaults() {
    FuryFX::SetDefaults();
    this->unk90.unk74 = 0.0f;
    this->unk90.SetIdentity();
    this->unk90.unk40 = 1.0f;
    this->unk90.unk44 = 1.0f;
    this->unk90.unk48 = 1.0f;
    this->unk90.unk70 = 0.0f;
    this->unk90.unk68 = -1.0f;
    this->unk90.unk6C = 0.0f;
    M2C_FIELD(this, s8 *, 0x2F0) = 0;
    M2C_FIELD(this, s8 *, 0x2F1) = 0;
    this->unk2E8 = 1;
}
#endif

#if 0 // DRAFT: illegal type
void FuryFXFire::Deinit() {
    f32 temp_r3_417;
    f32 temp_r4_382;
    f32 temp_r4_396;
    s32 var_r29_368;
    s32 var_r31_369;
    void *temp_r30_371;

    var_r29_368 = 0;
    var_r31_369 = 0;
    do {
        temp_r30_371 = this + var_r31_369;
        KDSound_Stop(temp_r30_371 + 0x134);
        KDSound_Stop(temp_r30_371 + 0x15C);
        var_r29_368 += 1;
        var_r31_369 += 0x80;
    } while (var_r29_368 < 3);
    MKMaterial_Destroy(M2C_BITWISE(MKMaterial *, this->unk90.unk50));
    temp_r4_382 = this->unk90.unk58;
    if (M2C_BITWISE(u32, temp_r4_382) != 0U) {
        gb.unk80->EnableLight(M2C_BITWISE(ManagedLight *, temp_r4_382), 0U);
        gb.unk80->FreeManagedLight(M2C_BITWISE(ManagedLight *, this->unk90.unk58));
        this->unk90.unk58 = 0.0f;
    }
    temp_r4_396 = this->unk90.unk64;
    if (M2C_BITWISE(u32, temp_r4_396) != 0U) {
        gb.unk64->Free(M2C_BITWISE(Corona *, temp_r4_396));
        this->unk90.unk64 = 0.0f;
    }
    MKModel_Destroy(this->unk90.unk5C);
    MKModel_Destroy((MKModel *) this->unk90.unk60);
    gb.unk2CC.Disable(this->unk2E8);
    this->unk2E8 = -1;
    temp_r3_417 = this->unk90.unk54;
    if (M2C_BITWISE(u32, temp_r3_417) != 0U) {
        MKMaterial_Destroy(M2C_BITWISE(MKMaterial *, temp_r3_417));
    }
    FuryFX::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp10'
void FuryFXFire::Draw() {
    f32 temp_f2_459;
    f32 temp_r0_442;
    temp_r0_442 = this->unk90.unk74;
    switch (M2C_BITWISE(s32, temp_r0_442)) {        /* irregular */
    case 1:
        return;
    default:
        MKView_Push();
        MKView_GetProjection(NULL, &arg_sp10, NULL);
        temp_f2_459 = arg_sp10 + 10.0f;
        arg_sp10 = temp_f2_459;
        MKView_SetProjection(0.0f, temp_f2_459, 0.0f);
        M2C_STRUCT_COPY((s32) &arg_sp3C + 4, (s32) &this->unk8C + 4, 0x40);
        arg_sp18 = 7.0f * this->unk90.unk40;
        arg_sp20 = 7.0f * this->unk90.unk48;
        arg_sp1C = 3.0f * this->unk90.unk44;
        arg_sp30 = (f64) arg_sp20;
        arg_sp28 = (f64) arg_sp18;
        arg_sp40.Scale3x3((Matrix *) &arg_sp40, *((MKVector3 *) &arg_sp28));
        MKModel_SetWorldMatrix((MKModel *) this->unk90.unk60, *((Matrix *) &arg_sp40));
        if ((u8) M2C_FIELD(this, u8 *, 0x2F1) != 0) {
            gRenderState = this->unk90.unk54;
            MKModel_Draw((MKModel *) this->unk90.unk60, NULL);
            gRenderState = 0.0f;
            MKModel_Draw((MKModel *) this->unk90.unk60, NULL);
        } else {
            MKModel_Draw((MKModel *) this->unk90.unk60, NULL);
        }
        MKView_Pop();
        /* fallthrough */
    case 0:
    case 6:
        return;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp48'
void FuryFXFire::UpdateDragons() {
    MKVector3 *temp_r25_660;
    f32 temp_f1_602;
    f32 temp_f1_720;
    f32 temp_f22_586;
    f32 temp_f23_591;
    f32 temp_f24_600;
    f32 temp_r3_694;
    f32 temp_r3_725;
    f32 temp_r3_741;
    f32 var_f1_592;
    s32 var_r26_565;
    s32 var_r28_563;
    s32 var_r4_654;
    s32 var_r4_676;
    void *temp_r30_570;
    void *temp_r3_648;
    void *temp_r3_710;
    void *temp_r3_733;
    void *temp_r3_744;
    var_r28_563 = 0;
    var_r26_565 = 0;
    do {
        temp_r30_570 = this + var_r26_565;
        M2C_FIELD(temp_r30_570, f32 *, 0x110) = (f32) ((M2C_FIELD(temp_r30_570, f32 *, 0x114) * gUpdateTimeDelta) + M2C_FIELD(temp_r30_570, f32 *, 0x110));
        M2C_FIELD(temp_r30_570, f32 *, 0x118) = (f32) ((2.0f * gUpdateTimeDelta) + M2C_FIELD(temp_r30_570, f32 *, 0x118));
        M2C_FIELD(temp_r30_570, f32 *, 0x11C) = (f32) (M2C_FIELD(temp_r30_570, f32 *, 0x11C) + gUpdateTimeDelta);
        temp_f22_586 = 400.0f * this->unk90.unk40;
        temp_f23_591 = temp_f22_586 * -_table_sinf(1.5707964f + M2C_FIELD(temp_r30_570, f32 *, 0x110));
        var_f1_592 = _table_sinf(M2C_FIELD(temp_r30_570, f32 *, 0x118));
        if (var_f1_592 < 0.0f) {
            var_f1_592 = -var_f1_592;
        }
        temp_f24_600 = (50.0f * this->unk90.unk44) + (300.0f * var_f1_592);
        temp_f1_602 = temp_f22_586 * _table_sinf(M2C_FIELD(temp_r30_570, f32 *, 0x110));
        arg_sp48 = temp_f23_591;
        arg_sp40 = temp_f1_602;
        arg_sp44 = temp_f24_600;
        arg_sp88 = (f64) arg_sp48;
        arg_sp80 = (f64) arg_sp40;
        arg_sp90 = (f64) arg_sp40;
        arg_sp98 = (f64) arg_sp48;
        M2C_STRUCT_COPY((s32) &arg_sp9C + 4, (s32) (&identity - 4) + 4, 0x40);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r29, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_spDC = 1.0f;
        arg_sp70 = arg_sp30;
        arg_sp38 = (f32) arg_sp98 + this->unk90.unk38;
        arg_sp78 = (f64) arg_sp38;
        arg_spD0 = (f32) arg_sp70;
        arg_spD4 = arg_sp74;
        arg_spD8 = (f32) arg_sp78;
        MKModel_SetWorldMatrix(this->unk90.unk5C, *((Matrix *) &arg_spA0));
        ((ShapedTrailFX *) (M2C_FIELD(temp_r30_570, ShapedTrailFX **, 0x130)))->UpdateTrail();
        temp_r3_648 = MKModel_GetWorldMatrix(M2C_FIELD(temp_r30_570, ShapedTrailFX **, 0x130)->unk78);
        M2C_FIELD(temp_r30_570, f64 *, 0x120) = (f64) M2C_FIELD(temp_r3_648, f64 *, 0x30);
        M2C_FIELD(temp_r30_570, f64 *, 0x128) = (f64) M2C_FIELD(temp_r3_648, f64 *, 0x38);
        var_r4_654 = GS_SpyroFuryAttack1;
        if ((u8) M2C_FIELD(this, u8 *, 0x2F1) != 0) {
            var_r4_654 = GS_CynderFuryLP;
        }
        temp_r25_660 = temp_r30_570 + 0x120;
        arg_sp8 = 1;
        ((KDSoundFader *) (temp_r30_570 + 0x134))->Update(var_r4_654, 1U, ((u8) M2C_FIELD(temp_r30_570, ShapedTrailFX **, 0x130)->unkA0 >> 6U) & 1, NULL, temp_r25_660, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
        arg_sp8 = 1;
        var_r4_676 = GS_SpyroFuryAttack3;
        if ((u8) M2C_FIELD(this, u8 *, 0x2F1) != 0) {
            var_r4_676 = GS_CynderFuryExtra1;
        }
        ((KDSoundFader *) (temp_r30_570 + 0x15C))->Update(var_r4_676, 1U, ((u8) M2C_FIELD(temp_r30_570, ShapedTrailFX **, 0x130)->unkA0 >> 6U) & 1, NULL, temp_r25_660, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
        var_r28_563 += 1;
        var_r26_565 += 0x80;
    } while (var_r28_563 < 3);
    temp_r3_694 = this->unk90.unk58;
    if (M2C_BITWISE(u32, temp_r3_694) != 0U) {
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r29, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        M2C_FIELD(temp_r3_694, f64 *, 0x10) = arg_sp20;
        arg_sp28 = (f32) arg_sp98 + this->unk90.unk38;
        arg_sp60 = arg_sp20;
        M2C_FIELD(temp_r3_694, f64 *, 0x18) = (f64) arg_sp28;
        temp_r3_710 = M2C_FIELD(temp_r3_694, void **, 0x3C);
        arg_sp68 = (f64) arg_sp28;
        if (temp_r3_710 != NULL) {
            M2C_FIELD(temp_r3_710, f64 *, 0x10) = arg_sp20;
            M2C_FIELD(temp_r3_710, f64 *, 0x18) = (f64) arg_sp28;
        }
        temp_f1_720 = MKRand_Float(&gViewSeed, 0.25f, 0.5f);
        arg_sp10 = 0.75f;
        temp_r3_725 = this->unk90.unk58;
        arg_sp14 = temp_f1_720;
        arg_sp18 = 0.0f;
        arg_sp1C = 1.0f;
        M2C_FIELD(temp_r3_725, f64 *, 0x20) = (f64) arg_sp10;
        M2C_FIELD(temp_r3_725, f64 *, 0x28) = (f64) arg_sp18;
        temp_r3_733 = M2C_FIELD(temp_r3_725, void **, 0x3C);
        arg_sp50 = (f64) arg_sp10;
        arg_sp58 = (f64) arg_sp18;
        if (temp_r3_733 != NULL) {
            M2C_FIELD(temp_r3_733, f64 *, 0) = (f64) arg_sp10;
            M2C_FIELD(temp_r3_733, f64 *, 8) = (f64) arg_sp18;
        }
        temp_r3_741 = this->unk90.unk58;
        M2C_FIELD(temp_r3_741, f32 *, 0x38) = 1000.0f;
        temp_r3_744 = M2C_FIELD(temp_r3_741, void **, 0x3C);
        if (temp_r3_744 != NULL) {
            M2C_FIELD(temp_r3_744, f32 *, 0x20) = 1000.0f;
            M2C_FIELD(temp_r3_744, f32 *, 0x24) = 1000000.0f;
            M2C_FIELD(temp_r3_744, f32 *, 0x28) = 0.001f;
            M2C_FIELD(temp_r3_744, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_744, f32 *, 0x24));
        }
    }
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void FuryFXFire::Message(MKMessage *arg0) {
    s32 var_r29_795;
    s32 var_r31_796;
    void *temp_r30_798;

    KDProp::Message(arg0);
    var_r29_795 = 0;
    var_r31_796 = 0;
    do {
        temp_r30_798 = this + var_r31_796;
        ((KDSoundPlayer *) (temp_r30_798 + 0x134))->Message(arg0);
        ((KDSoundPlayer *) (temp_r30_798 + 0x15C))->Message(arg0);
        var_r29_795 += 1;
        var_r31_796 += 0x80;
    } while (var_r29_795 < 3);
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void FuryFXFire::Update() {
    KDSynkerPlayer3 *temp_r3_2372;
    f32 temp_f19_2670;
    f32 temp_f1_1081;
    f32 temp_f1_1445;
    f32 temp_f1_1781;
    f32 temp_f1_2456;
    f32 temp_f1_2559;
    f32 temp_f1_2696;
    f32 temp_f1_869;
    f32 temp_f20_1360;
    f32 temp_f20_1433;
    f32 temp_f20_1442;
    f32 temp_f20_1498;
    f32 temp_f20_1542;
    f32 temp_f20_1696;
    f32 temp_f20_1769;
    f32 temp_f20_1778;
    f32 temp_f20_1834;
    f32 temp_f20_1878;
    f32 temp_f20_2672;
    f32 temp_f20_2681;
    f32 temp_f20_2772;
    f32 temp_f20_932;
    f32 temp_f21_1365;
    f32 temp_f21_1440;
    f32 temp_f21_1493;
    f32 temp_f21_1701;
    f32 temp_f21_1776;
    f32 temp_f21_1829;
    f32 temp_f21_2679;
    f32 temp_f21_2777;
    f32 temp_f21_2819;
    f32 temp_f22_1431;
    f32 temp_f22_1767;
    f32 temp_f22_2654;
    f32 temp_f23_1419;
    f32 temp_f23_1755;
    f32 temp_f2_2684;
    f32 temp_f30_1424;
    f32 temp_f30_1760;
    f32 temp_f3_860;
    f32 temp_f3_873;
    f32 temp_f4_2454;
    f32 temp_r0_1041;
    f32 temp_r3_1342;
    f32 temp_r3_1652;
    f32 temp_r3_1659;
    f32 temp_r3_2054;
    f32 temp_r3_2060;
    f32 temp_r3_2341;
    f32 temp_r3_2418;
    f32 temp_r3_2449;
    f32 temp_r3_2485;
    f32 temp_r4_1131;
    f32 temp_r4_1331;
    f32 temp_r4_1631;
    f32 temp_r4_2098;
    f32 temp_r4_2586;
    f32 var_f0_2850;
    f32 var_f20_1061;
    f32 var_f27_2435;
    f64 temp_f2_2249;
    s32 temp_r28_2647;
    s32 temp_r29_1403;
    s32 temp_r29_1739;
    s32 var_r24_2650;
    s32 var_r25_2640;
    s32 var_r26_1238;
    s32 var_r26_1414;
    s32 var_r26_1750;
    s32 var_r28_1141;
    s32 var_r28_2072;
    s32 var_r29_1143;
    s32 var_r31_2073;
    s32 var_r3_2323;
    u8 var_r27_2370;
    void *temp_r26_1147;
    void *temp_r26_2080;
    void *temp_r28_2371;
    void *temp_r3_1148;
    void *temp_r3_2346;
    void *temp_r3_2424;
    void *temp_r3_2458;
    void *temp_r3_2491;
    void *temp_r4_1167;
    void *temp_r4_2087;
    void *temp_r5_2082;
    void *temp_r6_1154;
    this->unk90.unk70 -= gUpdateTimeDelta;
    if ((u8) M2C_FIELD(this, u8 *, 0x2F1) == 0) {
        temp_f3_860 = this->unk90.unk68;
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (temp_f3_860 == 0.0f) {
            this->unk90.unk68 = temp_f3_860 + gUpdateTimeDelta;
            temp_f1_869 = this->unk90.unk68;
            if (temp_f1_869 < 1.0f) {
                this->unk90.unk6C = 0.0f;
                temp_f3_873 = this->unk90.unk68;
                if ((temp_f3_873 > 0.0f) && (M2C_ERROR(/* unknown instruction: cror eq, lt, eq */), ((temp_f3_873 == 0.5f) != 0))) {
                    this->unk90.unk6C = (2.0f * temp_f3_873 * 0.0625f) + 0.0f;
                } else if ((temp_f3_873 > 0.5f) && (M2C_ERROR(/* unknown instruction: cror eq, lt, eq */), ((temp_f3_873 == 0.75f) != 0))) {
                    this->unk90.unk6C = (4.0f * (temp_f3_873 - 0.5f) * 0.0625f) + 0.0625f;
                } else if ((temp_f3_873 > 0.75f) && (M2C_ERROR(/* unknown instruction: cror eq, lt, eq */), ((temp_f3_873 == 0.875f) != 0))) {
                    this->unk90.unk6C = (8.0f * (temp_f3_873 - 0.75f) * 0.125f) + 0.125f;
                } else if (temp_f3_873 > 0.875f) {
                    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                    if (temp_f3_873 == 1.0f) {
                        this->unk90.unk6C = (8.0f * (temp_f3_873 - 0.875f) * 0.25f) + 0.25f;
                    }
                }
                temp_f20_932 = this->unk90.unk6C;
                ((KDInput *) (M2C_FIELD(gb.unk0->__vptr, KDInput *(**)(HeroInterface *), 0x40)(gb.unk0)))->RumblePlay(temp_f20_932, temp_f20_932, 0.033f, 0, 4.0f, 0U);
            } else {
                M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
                if ((temp_f1_869 == 5.1f) && (M2C_ERROR(/* unknown instruction: cror eq, lt, eq */), ((temp_f1_869 == 5.4f) != 0)) && ((u8) M2C_FIELD(this, u8 *, 0x2F0) == 0)) {
                    ((KDInput *) (M2C_FIELD(gb.unk0->__vptr, KDInput *(**)(HeroInterface *), 0x40)(gb.unk0)))->RumblePlay(0.6f, 0.0f, 0.05f, 0, 4.0f, 0U);
                } else {
                    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
                    if ((temp_f1_869 == 6.1f) && (M2C_ERROR(/* unknown instruction: cror eq, lt, eq */), ((temp_f1_869 == 6.4f) != 0)) && ((u8) M2C_FIELD(this, u8 *, 0x2F0) == 0)) {
                        ((KDInput *) (M2C_FIELD(gb.unk0->__vptr, KDInput *(**)(HeroInterface *), 0x40)(gb.unk0)))->RumblePlay(0.0f, 0.4f, 0.05f, 0, 4.0f, 0U);
                    } else {
                        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
                        if ((temp_f1_869 == 7.0f) && (M2C_ERROR(/* unknown instruction: cror eq, lt, eq */), ((temp_f1_869 == 7.4f) != 0)) && ((u8) M2C_FIELD(this, u8 *, 0x2F0) == 0)) {
                            ((KDInput *) (M2C_FIELD(gb.unk0->__vptr, KDInput *(**)(HeroInterface *), 0x40)(gb.unk0)))->RumblePlay(0.3f, 0.0f, 0.05f, 0, 4.0f, 0U);
                        } else if (temp_f1_869 > 7.4f) {
                            this->unk90.unk68 = -1.0f;
                        }
                    }
                }
            }
        }
    }
    if (M2C_BITWISE(s32, this->unk90.unk74) != 0) {
        UpdateDragons();
    }
    temp_r0_1041 = this->unk90.unk74;
    if (M2C_BITWISE(u32, temp_r0_1041) <= 6U) {
        switch (M2C_BITWISE(s32, temp_r0_1041)) {
            return;
        case 1:
            if (((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) && ((u8) M2C_FIELD(this, u8 *, 0x2F1) == 0)) {
                var_f20_1061 = this->unk90.unk70;
                if (var_f20_1061 < 1.0f) {

                } else {
                    var_f20_1061 = 1.0f;
                }
                if (var_f20_1061 > 0.0f) {

                } else {
                    var_f20_1061 = 0.0f;
                }
                arg_sp874 = 0;
                temp_f1_1081 = M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), f32 (**)(), 0x54)();
                arg_sp870 = 0x458;
                arg_sp878 = temp_f1_1081 + (0.017453292f * (30.0f * (1.0f - var_f20_1061)));
                M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f32, f32), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &arg_sp870, 30.0f, 0.017453292f);
            }
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (this->unk90.unk70 == 0.0f) {
                this->unk90.unk74 = 3e-45f;
                this->unk90.unk70 = 0.25f;
                gb.unk2CC.Disable(this->unk2E8);
                this->unk2E8 = -1;
                this->unk90.unk40 = 0.05f;
                this->unk90.unk44 = 1.0f;
                this->unk90.unk48 = 0.05f;
                if ((u8) M2C_FIELD(this, u8 *, 0x2F1) != 0) {
                    KDSound_Play3d(GS_CynderFuryBuildUp2, (MKVector3 *) &this->unk90.unk30, 0U, -1, 0.0f, 0U);
                }
                temp_r4_1131 = this->unk90.unk58;
                if (M2C_BITWISE(u32, temp_r4_1131) != 0U) {
                    gb.unk80->EnableLight(M2C_BITWISE(ManagedLight *, temp_r4_1131), 1U);
                }
                var_r28_1141 = 0;
                var_r29_1143 = 0;
                do {
                    temp_r26_1147 = this + var_r29_1143;
                    temp_r3_1148 = M2C_FIELD(temp_r26_1147, void **, 0x130);
                    M2C_FIELD(M2C_FIELD(temp_r3_1148, void **, 0x44), M2C_UNK (**)(void *), 0x20)(temp_r3_1148);
                    temp_r6_1154 = M2C_FIELD(temp_r26_1147, void **, 0x130);
                    M2C_FIELD(temp_r6_1154, u8 *, 0xA0) = (u8) ((M2C_FIELD(temp_r6_1154, u8 *, 0xA0) & ~0x80) | ((lit_845 << 7) & 0x80));
                    temp_r4_1167 = M2C_FIELD(temp_r26_1147, void **, 0x130);
                    M2C_FIELD(temp_r4_1167, u8 *, 0xA0) = (u8) (M2C_FIELD(temp_r4_1167, u8 *, 0xA0) | 0x40);
                    M2C_FIELD(temp_r26_1147, f32 *, 0x110) = (f32) (6.2831855f / (f32) (var_r28_1141 + 1));
                    M2C_FIELD(temp_r26_1147, f32 *, 0x114) = 3.7699115f;
                    M2C_FIELD(temp_r26_1147, f32 *, 0x118) = MKRand_Float(&gViewSeed, 0.0f, 10000.0f);
                    var_r28_1141 += 1;
                    M2C_FIELD(temp_r26_1147, f32 *, 0x11C) = MKRand_Float(&gViewSeed, 0.0f, 10000.0f);
                    var_r29_1143 += 0x80;
                } while (var_r28_1141 < 3);
                if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
                    arg_sp8E4 = 0;
                    MKVector(1.0f, 1.0f, 1.0f);
                    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f23 */);
                    arg_sp8E0 = 0x417;
                    arg_sp8E8 = arg_sp160;
                    arg_sp168 = arg_sp7F8 * 150.0f;
                    arg_sp8F8 = 1;
                    arg_sp8F0 = (f64) arg_sp168;
                    arg_sp800 = arg_sp160;
                    arg_sp808 = (f64) arg_sp168;
                    M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &arg_sp8E0, arg_sp160);
                }
                arg_sp360 = 1.0f;
                arg_sp364 = 1.0f;
                arg_sp368 = 1.0f;
                arg_sp36C = 1.0f;
                arg_sp7E0 = (f64) arg_sp360;
                arg_sp7E8 = (f64) arg_sp368;
                MKModel_SetColor((MKModel *) this->unk90.unk60, *((MKVector4 *) &arg_sp7E0));
                return;
            }
            break;
        case 2:
            var_r26_1238 = 0;
            gb.unkD0 = 1;
            do {
                gb.unkB8.AddRandomWobbleForce(1.0f);
                var_r26_1238 += 1;
            } while (var_r26_1238 < 5);
            MKVector(3.0f, 5.0f, 3.0f);
            MKVector(6.0f, 0.0f, 6.0f);
            arg_sp7A0.operator*(gUpdateTimeDelta);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp7B0 = arg_sp70;
            arg_sp78 = this->unk90.unk48 + arg_sp7A8;
            arg_sp7B8 = (f64) arg_sp78;
            MKVector(0.0f, 0.0f, 0.0f);
            Min(*((MKVector3 *) &arg_sp150), *((MKVector3 *) &arg_sp7B0));
            Max(*((MKVector3 *) &arg_sp7D0), *((MKVector3 *) &arg_sp150));
            M2C_FIELD(this, f32 *, 0xD0) = arg_sp7D0;
            M2C_FIELD(this, f32 *, 0xD8) = arg_sp7D8;
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (this->unk90.unk70 == 0.0f) {
                this->unk90.unk70 = 1.5f;
                if ((u8) M2C_FIELD(this, u8 *, 0x2F1) != 0) {
                    this->unk90.unk70 -= 0.3f;
                }
                this->unk90.unk74 = M2C_BITWISE(f32, (M2C_BITWISE(s32, this->unk90.unk74) + 1));
                if (((u8) M2C_FIELD(this, u8 *, 0x2F0) == 0) && ((u8) M2C_FIELD(this, u8 *, 0x2F1) == 0)) {
                    ((KDInput *) (M2C_FIELD(gb.unk0->__vptr, KDInput *(**)(HeroInterface *), 0x40)(gb.unk0)))->RumblePlay(0.5f, 0.5f, 0.33f, 0, 4.0f, 0U);
                }
                temp_r4_1331 = this->unk90.unk64;
                if (M2C_BITWISE(u32, temp_r4_1331) != 0U) {
                    M2C_FIELD(temp_r4_1331, u8 *, 0x31) = (u8) (M2C_FIELD(temp_r4_1331, u8 *, 0x31) | 0x40);
                    M2C_FIELD(this->unk90.unk64, f32 *, 0x24) = 0.0f;
                    temp_r3_1342 = this->unk90.unk64;
                    M2C_FIELD(temp_r3_1342, f32 *, 0x2C) = (f32) ((2.0f * gUpdateTimeDelta) + M2C_FIELD(temp_r3_1342, f32 *, 0x2C));
                    return;
                }
            } else {
                if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
                    arg_sp8C4 = 0;
                    temp_f20_1360 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                    temp_f21_1365 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                    MKVector(MKRand_Float(&gViewSeed, -1.0f, 1.0f), temp_f21_1365, temp_f20_1360);
                    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f23 */);
                    arg_sp8C0 = 0x417;
                    arg_sp8C8 = arg_sp140;
                    arg_sp148 = arg_sp768 * 10.0f;
                    arg_sp8D8 = 1;
                    arg_sp8D0 = (f64) arg_sp148;
                    arg_sp770 = arg_sp140;
                    arg_sp778 = (f64) arg_sp148;
                    M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &arg_sp8C0, arg_sp140);
                }
                temp_r29_1403 = MKRand_Int(&gViewSeed, 0xF, 0x1E);
                var_r26_1414 = 0;
                temp_f23_1419 = 6.2831855f / (f32) (temp_r29_1403 - 1);
loop_71:
                if (var_r26_1414 < temp_r29_1403) {
                    temp_f30_1424 = this->unk90.unk40;
                    temp_f22_1431 = (f32) var_r26_1414 * temp_f23_1419;
                    temp_f20_1433 = MKRand_Float(&gViewSeed, 0.8f, 1.0f);
                    temp_f21_1440 = -_table_sinf(1.5707964f + temp_f22_1431) * temp_f20_1433;
                    temp_f20_1442 = MKRand_Float(&gViewSeed, 0.8f, 1.0f);
                    temp_f1_1445 = _table_sinf(temp_f22_1431) * temp_f20_1442;
                    arg_sp358 = temp_f21_1440;
                    arg_sp350 = temp_f1_1445;
                    arg_sp354 = 0.0f;
                    arg_sp738 = (f64) arg_sp358;
                    arg_sp730 = (f64) arg_sp350;
                    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
                    arg_sp740 = arg_sp340;
                    arg_sp348 = (f32) arg_sp738 * 400.0f;
                    arg_sp748 = (f64) arg_sp348;
                    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
                    arg_sp750 = arg_sp330;
                    arg_sp338 = (f32) arg_sp748 * temp_f30_1424;
                    arg_sp758 = (f64) arg_sp338;
                    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                    arg_sp860 = arg_sp320;
                    arg_sp328 = this->unk90.unk38 + (f32) arg_sp758;
                    arg_sp868 = (f64) arg_sp328;
                    if ((u8) M2C_FIELD(this, u8 *, 0x2F1) == 0) {
                        temp_f21_1493 = MKRand_Float(&gViewSeed, 0.0f, 0.2f);
                        temp_f20_1498 = MKRand_Float(&gViewSeed, 0.6f, 0.8f);
                        arg_sp300 = MKRand_Float(&gViewSeed, 0.8f, 1.0f);
                        arg_sp304 = temp_f20_1498;
                        arg_sp308 = temp_f21_1493;
                        arg_sp30C = 1.0f;
                        arg_sp710 = (f64) arg_sp300;
                        arg_sp718 = (f64) arg_sp308;
                        arg_sp24 = MKRand_Float(&gViewSeed, 3.0f, 6.0f);
                        arg_sp314 = MKRand_Float(&gViewSeed, 100.0f, 700.0f);
                        arg_sp310 = 0.0f;
                        arg_sp318 = 0.0f;
                        arg_sp720 = (f64) arg_sp310;
                        arg_sp728 = (f64) arg_sp318;
                        gb.unk74->Emit(*((MKVector3 *) &arg_sp860), *((MKVector3 *) &arg_sp720), arg_sp24, *((MKVector4 *) &arg_sp710), 100.0f);
                    } else {
                        temp_f20_1542 = MKRand_Float(&gViewSeed, 0.3f, 1.9f);
                        arg_sp2E4 = MKRand_Float(&gViewSeed, 0.1f, 0.2f);
                        arg_sp2E0 = 1.0f;
                        arg_sp2E8 = temp_f20_1542;
                        arg_sp2EC = 1.0f;
                        arg_sp6F0 = (f64) arg_sp2E0;
                        arg_sp6F8 = (f64) arg_sp2E8;
                        arg_sp20 = MKRand_Float(&gViewSeed, 3.0f, 6.0f);
                        arg_sp2F4 = MKRand_Float(&gViewSeed, 100.0f, 700.0f);
                        arg_sp2F0 = 0.0f;
                        arg_sp2F8 = 0.0f;
                        arg_sp700 = (f64) arg_sp2F0;
                        arg_sp708 = (f64) arg_sp2F8;
                        gb.unk74->Emit(*((MKVector3 *) &arg_sp860), *((MKVector3 *) &arg_sp700), arg_sp20, *((MKVector4 *) &arg_sp6F0), 100.0f);
                    }
                    var_r26_1414 += 1;
                    goto loop_71;
                }
                return;
            }
            break;
        case 3:
            MKVector(5.0f, 50.0f, 5.0f);
            MKVector(-1.0f, 4.0f, -1.0f);
            arg_sp6B0.operator*(gUpdateTimeDelta);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp6C0 = arg_sp60;
            arg_sp68 = this->unk90.unk48 + arg_sp6B8;
            arg_sp6C8 = (f64) arg_sp68;
            MKVector(0.1f, 0.0f, 0.1f);
            Min(*((MKVector3 *) &arg_sp130), *((MKVector3 *) &arg_sp6C0));
            Max(*((MKVector3 *) &arg_sp6E0), *((MKVector3 *) &arg_sp130));
            M2C_FIELD(this, f32 *, 0xD0) = arg_sp6E0;
            M2C_FIELD(this, f32 *, 0xD8) = arg_sp6E8;
            temp_r4_1631 = this->unk90.unk64;
            if (M2C_BITWISE(u32, temp_r4_1631) != 0U) {
                M2C_FIELD(temp_r4_1631, f32 *, 0x24) = (f32) this->unk90.unk44;
                MKVector(0.0f, 75.0f * this->unk90.unk44, 0.0f);
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                temp_r3_1652 = this->unk90.unk64;
                M2C_FIELD(temp_r3_1652, f64 *, 0) = arg_sp120;
                arg_sp128 = this->unk90.unk38 + arg_sp678;
                arg_sp680 = arg_sp120;
                M2C_FIELD(temp_r3_1652, f64 *, 8) = (f64) arg_sp128;
                temp_r3_1659 = this->unk90.unk64;
                arg_sp688 = (f64) arg_sp128;
                M2C_FIELD(temp_r3_1659, f32 *, 0x2C) = (f32) ((2.0f * gUpdateTimeDelta) + M2C_FIELD(temp_r3_1659, f32 *, 0x2C));
            }
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (this->unk90.unk70 == 0.0f) {
                if ((u8) M2C_FIELD(this, u8 *, 0x2F0) != 0) {
                    this->unk90.unk70 = 3.0f;
                } else {
                    this->unk90.unk70 = 0.2f;
                }
                this->unk90.unk74 = M2C_BITWISE(f32, (M2C_BITWISE(s32, this->unk90.unk74) + 1));
            }
            if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
                arg_sp8A4 = 0;
                temp_f20_1696 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                temp_f21_1701 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                MKVector(MKRand_Float(&gViewSeed, -1.0f, 1.0f), temp_f21_1701, temp_f20_1696);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f23 */);
                arg_sp8A0 = 0x417;
                arg_sp8A8 = arg_sp110;
                arg_sp118 = arg_sp658 * 10.0f;
                arg_sp8B8 = 1;
                arg_sp8B0 = (f64) arg_sp118;
                arg_sp660 = arg_sp110;
                arg_sp668 = (f64) arg_sp118;
                M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &arg_sp8A0, arg_sp110);
            }
            temp_r29_1739 = MKRand_Int(&gViewSeed, 0xF, 0x1E);
            var_r26_1750 = 0;
            temp_f23_1755 = 6.2831855f / (f32) (temp_r29_1739 - 1);
loop_87:
            if (var_r26_1750 < temp_r29_1739) {
                temp_f30_1760 = this->unk90.unk40;
                temp_f22_1767 = (f32) var_r26_1750 * temp_f23_1755;
                temp_f20_1769 = MKRand_Float(&gViewSeed, 0.8f, 1.0f);
                temp_f21_1776 = -_table_sinf(1.5707964f + temp_f22_1767) * temp_f20_1769;
                temp_f20_1778 = MKRand_Float(&gViewSeed, 0.8f, 1.0f);
                temp_f1_1781 = _table_sinf(temp_f22_1767) * temp_f20_1778;
                arg_sp2D8 = temp_f21_1776;
                arg_sp2D0 = temp_f1_1781;
                arg_sp2D4 = 0.0f;
                arg_sp628 = (f64) arg_sp2D8;
                arg_sp620 = (f64) arg_sp2D0;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
                arg_sp630 = arg_sp2C0;
                arg_sp2C8 = (f32) arg_sp628 * 1000.0f;
                arg_sp638 = (f64) arg_sp2C8;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
                arg_sp640 = arg_sp2B0;
                arg_sp2B8 = (f32) arg_sp638 * temp_f30_1760;
                arg_sp648 = (f64) arg_sp2B8;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp850 = arg_sp2A0;
                arg_sp2A8 = this->unk90.unk38 + (f32) arg_sp648;
                arg_sp858 = (f64) arg_sp2A8;
                if ((u8) M2C_FIELD(this, u8 *, 0x2F1) == 0) {
                    temp_f21_1829 = MKRand_Float(&gViewSeed, 0.0f, 0.2f);
                    temp_f20_1834 = MKRand_Float(&gViewSeed, 0.6f, 0.8f);
                    arg_sp280 = MKRand_Float(&gViewSeed, 0.8f, 1.0f);
                    arg_sp284 = temp_f20_1834;
                    arg_sp288 = temp_f21_1829;
                    arg_sp28C = 1.0f;
                    arg_sp600 = (f64) arg_sp280;
                    arg_sp608 = (f64) arg_sp288;
                    arg_sp1C = MKRand_Float(&gViewSeed, 3.0f, 6.0f);
                    arg_sp294 = MKRand_Float(&gViewSeed, 100.0f, 700.0f);
                    arg_sp290 = 0.0f;
                    arg_sp298 = 0.0f;
                    arg_sp610 = (f64) arg_sp290;
                    arg_sp618 = (f64) arg_sp298;
                    gb.unk74->Emit(*((MKVector3 *) &arg_sp850), *((MKVector3 *) &arg_sp610), arg_sp1C, *((MKVector4 *) &arg_sp600), 100.0f);
                } else {
                    temp_f20_1878 = MKRand_Float(&gViewSeed, 0.3f, 1.9f);
                    arg_sp264 = MKRand_Float(&gViewSeed, 0.1f, 0.2f);
                    arg_sp260 = 1.0f;
                    arg_sp268 = temp_f20_1878;
                    arg_sp26C = 1.0f;
                    arg_sp5E0 = (f64) arg_sp260;
                    arg_sp5E8 = (f64) arg_sp268;
                    arg_sp18 = MKRand_Float(&gViewSeed, 3.0f, 6.0f);
                    arg_sp274 = MKRand_Float(&gViewSeed, 100.0f, 700.0f);
                    arg_sp270 = 0.0f;
                    arg_sp278 = 0.0f;
                    arg_sp5F0 = (f64) arg_sp270;
                    arg_sp5F8 = (f64) arg_sp278;
                    gb.unk74->Emit(*((MKVector3 *) &arg_sp850), *((MKVector3 *) &arg_sp5F0), arg_sp18, *((MKVector4 *) &arg_sp5E0), 100.0f);
                }
                var_r26_1750 += 1;
                goto loop_87;
            }
            return;
        case 4:
            if ((u8) M2C_FIELD(this, u8 *, 0x2F0) != 0) {
                MKVector(5.0f, 50.0f, 5.0f);
                MKVector(-2.0f, 0.0f, -2.0f);
                arg_sp5A0.operator*(gUpdateTimeDelta);
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp5B0 = arg_sp50;
                arg_sp58 = this->unk90.unk48 + arg_sp5A8;
                arg_sp5B8 = (f64) arg_sp58;
                MKVector(0.05f, 0.0f, 0.05f);
                Min(*((MKVector3 *) &arg_sp100), *((MKVector3 *) &arg_sp5B0));
                Max(*((MKVector3 *) &arg_sp5D0), *((MKVector3 *) &arg_sp100));
                M2C_FIELD(this, f32 *, 0xD0) = arg_sp5D0;
                M2C_FIELD(this, f32 *, 0xD8) = arg_sp5D8;
            } else {
                MKVector(5.0f, 50.0f, 5.0f);
                MKVector(-2.0f, -3.0f, -2.0f);
                arg_sp540.operator*(gUpdateTimeDelta);
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp550 = arg_sp40;
                arg_sp48 = this->unk90.unk48 + arg_sp548;
                arg_sp558 = (f64) arg_sp48;
                MKVector(0.05f, 0.0f, 0.05f);
                Min(*((MKVector3 *) &arg_spF0), *((MKVector3 *) &arg_sp550));
                Max(*((MKVector3 *) &arg_sp570), *((MKVector3 *) &arg_spF0));
                M2C_FIELD(this, f32 *, 0xD0) = arg_sp570;
                M2C_FIELD(this, f32 *, 0xD8) = arg_sp578;
            }
            if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
                arg_sp884 = 0;
                MKVector(1.0f, 1.0f, 1.0f);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f23 */);
                arg_sp880 = 0x417;
                arg_sp888 = arg_spE0;
                arg_spE8 = arg_sp508 * 500.0f;
                arg_sp898 = 1;
                arg_sp890 = (f64) arg_spE8;
                arg_sp510 = arg_spE0;
                arg_sp518 = (f64) arg_spE8;
                M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &arg_sp880, arg_spE0);
            }
            temp_r3_2054 = this->unk90.unk64;
            if (M2C_BITWISE(u32, temp_r3_2054) != 0U) {
                M2C_FIELD(temp_r3_2054, f32 *, 0x24) = (f32) this->unk90.unk44;
                temp_r3_2060 = this->unk90.unk64;
                M2C_FIELD(temp_r3_2060, f32 *, 0x2C) = (f32) ((2.0f * gUpdateTimeDelta) + M2C_FIELD(temp_r3_2060, f32 *, 0x2C));
            }
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (this->unk90.unk70 == 0.0f) {
                var_r28_2072 = 0;
                var_r31_2073 = 0;
                this->unk90.unk70 = 0.6f;
                this->unk90.unk74 = M2C_BITWISE(f32, (M2C_BITWISE(s32, this->unk90.unk74) + 1));
                do {
                    temp_r26_2080 = this + var_r31_2073;
                    temp_r5_2082 = M2C_FIELD(temp_r26_2080, void **, 0x130);
                    M2C_FIELD(temp_r5_2082, u8 *, 0xA0) = (u8) ((M2C_FIELD(temp_r5_2082, u8 *, 0xA0) & ~0x80) | ((lit_910 << 7) & 0x80));
                    temp_r4_2087 = M2C_FIELD(temp_r26_2080, void **, 0x130);
                    M2C_FIELD(temp_r4_2087, u8 *, 0xA0) = (u8) (M2C_FIELD(temp_r4_2087, u8 *, 0xA0) & ~0x40);
                    KDSound_Stop(temp_r26_2080 + 0x134);
                    KDSound_Stop(temp_r26_2080 + 0x15C);
                    var_r28_2072 += 1;
                    var_r31_2073 += 0x80;
                } while (var_r28_2072 < 3);
                temp_r4_2098 = this->unk90.unk64;
                if (M2C_BITWISE(u32, temp_r4_2098) != 0U) {
                    M2C_FIELD(temp_r4_2098, u8 *, 0x31) = (u8) (M2C_FIELD(temp_r4_2098, u8 *, 0x31) & ~0x40);
                }
                arg_sp250 = 1.0f;
                arg_sp254 = 1.0f;
                arg_sp258 = 1.0f;
                arg_sp25C = 1.0f;
                arg_sp4F0 = (f64) arg_sp250;
                arg_sp4F8 = (f64) arg_sp258;
                gb.unkB8.EnableScreenFlash(*((MKVector4 *) &arg_sp4F0), 3.0f * gUpdateTimeDelta);
                if (((u8) M2C_FIELD(this, u8 *, 0x2F0) == 0) && ((u8) M2C_FIELD(this, u8 *, 0x2F1) == 0)) {
                    ((KDInput *) (M2C_FIELD(gb.unk0->__vptr, KDInput *(**)(HeroInterface *), 0x40)(gb.unk0)))->RumblePlay(0.99f, 0.99f, 0.66f, 0, 4.0f, 0U);
                }
                if ((u8) M2C_FIELD(this, u8 *, 0x2F1) != 0) {
                    ((KDInput *) (M2C_FIELD(gb.unk0->__vptr, KDInput *(**)(HeroInterface *), 0x40)(gb.unk0)))->RumblePlay3D(0.99f, 0.99f, 0.66f, (MKVector3 *) &this->unk90.unk30, 50.0f, 0, 4.0f, 1U);
                }
                M2C_STRUCT_COPY((s32) &arg_sp8FC + 4, (s32) (&identity - 4) + 4, 0x40);
                arg_sp248 = 1.0f;
                arg_sp238 = 0.0f;
                arg_sp240 = 0.0f;
                arg_sp244 = 0.0f;
                arg_sp230 = 0.0f;
                arg_sp234 = -1.0f;
                arg_sp840 = (f64) arg_sp240;
                arg_sp848 = (f64) arg_sp248;
                arg_sp4E0 = (f64) arg_sp230;
                arg_sp4E8 = (f64) arg_sp238;
                KDMath_BuildMatrixFromFwd((Matrix *) &arg_sp900, *((MKVector3 *) &arg_sp4E0), (MKVector3 *) &arg_sp840);
                arg_spD8 = 2.0f;
                arg_spD0 = 2.0f;
                arg_spD4 = 2.0f;
                arg_sp4D8 = (f64) arg_spD8;
                arg_sp4D0 = (f64) arg_spD0;
                arg_sp900.Scale3x3((Matrix *) &arg_sp900, *((MKVector3 *) &arg_sp4D0));
                MKVector(0.0f, 300.0f, 0.0f);
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r26, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp4C0 = arg_spC0;
                arg_spC8 = this->unk90.unk38 + arg_sp4B8;
                arg_sp4C8 = (f64) arg_spC8;
                arg_sp930 = (f32) arg_sp4C0;
                arg_sp934 = arg_sp4C4;
                arg_sp938 = (f32) arg_sp4C8;
                arg_sp93C = 1.0f;
                gb.unk1C0.StartWarp((Matrix *) &arg_sp900);
                if ((u8) M2C_FIELD(this, u8 *, 0x2F1) == 0) {
                    this->unk290.unk50 = 0;
                    temp_f2_2249 = M2C_FIELD(this, f64 *, 0xC0);
                    M2C_FIELD(this, f64 *, 0x2A0) = temp_f2_2249;
                    M2C_FIELD(this, f64 *, 0x2A8) = (f64) M2C_FIELD(this, f32 *, 0xC8);
                    M2C_FIELD(*gMK, M2C_UNK (**)(void **, BreathHitMessage *, M2C_UNK, M2C_UNK, f32 *, M2C_UNK, f32, f64), 0x94)(gMK, &this->unk290, 0, 0, &this->unk290.unk10, 1, 3000.0f, temp_f2_2249);
                } else {
                    arg_sp944 = 0;
                    arg_spB8 = 0.0f;
                    arg_spB0 = 0.0f;
                    arg_spB4 = 0.0f;
                    arg_sp4A8 = (f64) arg_spB8;
                    arg_sp4A0 = (f64) arg_spB0;
                    arg_sp940 = 7;
                    arg_sp968 = this->unk2E8;
                    arg_sp96C = 0;
                    arg_sp948 = (f64) arg_spB0;
                    arg_sp950 = (f64) arg_spB8;
                    arg_sp980 = 1;
                    arg_sp98C = 2;
                    arg_sp988 = 1000.0f;
                    arg_sp980 = 0;
                    (s16) arg_sp980 = 0;
                    arg_sp984 = -1;
                    arg_sp958 = M2C_FIELD(&one, f64 *, 0);
                    arg_sp960 = M2C_FIELD(&one, f64 *, 8);
                    arg_sp990 = 0;
                    arg_sp970 = 0.0f;
                    arg_sp974 = 0.0f;
                    arg_sp978 = 0.0f;
                    arg_sp990 = 0;
                    M2C_FIELD(M2C_FIELD(M2C_FIELD(gb.unk0->__vptr, void *(**)(HeroInterface *), 0xC)(gb.unk0), void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&arg_sp940);
                }
                var_r3_2323 = GS_SpyroFuryAttack2;
                if ((u8) M2C_FIELD(this, u8 *, 0x2F1) != 0) {
                    var_r3_2323 = GS_CynderFuryImpact;
                }
                KDSound_Play3d(var_r3_2323, (MKVector3 *) &this->unk290.unk10, 0U, -1, 0.0f, 0U);
                KDSound_Play3d(GS_Rumble1, (MKVector3 *) &this->unk290.unk10, 0U, -1, 0.0f, 0U);
                temp_r3_2341 = this->unk90.unk58;
                if (M2C_BITWISE(u32, temp_r3_2341) != 0U) {
                    M2C_FIELD(temp_r3_2341, f32 *, 0x38) = 10000.0f;
                    temp_r3_2346 = M2C_FIELD(temp_r3_2341, void **, 0x3C);
                    if (temp_r3_2346 != NULL) {
                        M2C_FIELD(temp_r3_2346, f32 *, 0x20) = 10000.0f;
                        M2C_FIELD(temp_r3_2346, f32 *, 0x24) = 1e8f;
                        M2C_FIELD(temp_r3_2346, f32 *, 0x28) = 0.0001f;
                        M2C_FIELD(temp_r3_2346, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_2346, f32 *, 0x24));
                    }
                }
                this->unk2E8 = gb.unk2CC.Enable(0.5f, 0.0f, 0.0f, -1.0f);
                var_r27_2370 = 0;
                temp_r28_2371 = gb.unkC;
                temp_r3_2372 = M2C_FIELD(temp_r28_2371, KDSynkerPlayer3 **, 0x78);
                if (((temp_r3_2372 != NULL) && (temp_r3_2372->IsPlaying() != 0)) || (((s32) M2C_FIELD(temp_r28_2371, s32 *, 0x74) == 2) && (((KDStateMachine<CutsceneSystem> *) (temp_r28_2371 + 0x24))->GetState() == 2))) {
                    var_r27_2370 = 1;
                }
                if ((var_r27_2370 == 0) && ((u8) M2C_FIELD(this, u8 *, 0x2F1) == 0)) {
                    gb.GetSpyro();
                    ((Spyro *) (M2C_ERROR(/* Read from unset register $r3 */)))->SetRage(0, 15.0f);
                }
            }
            if (M2C_BITWISE(u32, this->unk90.unk58) != 0U) {
                MKVector(0.0f, 500.0f, 0.0f);
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                temp_r3_2418 = this->unk90.unk58;
                arg_sp490 = arg_spA0;
                arg_spA8 = this->unk90.unk38 + arg_sp488;
                M2C_FIELD(temp_r3_2418, f64 *, 0x10) = arg_spA0;
                M2C_FIELD(temp_r3_2418, f64 *, 0x18) = (f64) arg_spA8;
                temp_r3_2424 = M2C_FIELD(temp_r3_2418, void **, 0x3C);
                arg_sp498 = (f64) arg_spA8;
                if (temp_r3_2424 != NULL) {
                    M2C_FIELD(temp_r3_2424, f64 *, 0x10) = arg_spA0;
                    M2C_FIELD(temp_r3_2424, f64 *, 0x18) = (f64) arg_spA8;
                    return;
                }
            }
            break;
        case 5:
            var_f27_2435 = this->unk90.unk70 / 0.6f;
            if (var_f27_2435 < 1.0f) {

            } else {
                var_f27_2435 = 1.0f;
            }
            if (var_f27_2435 > 0.0f) {

            } else {
                var_f27_2435 = 0.0f;
            }
            temp_r3_2449 = this->unk90.unk58;
            if (M2C_BITWISE(u32, temp_r3_2449) != 0U) {
                temp_f4_2454 = 1.0f - var_f27_2435;
                temp_f1_2456 = (4000.0f * temp_f4_2454) + 10000.0f;
                M2C_FIELD(temp_r3_2449, f32 *, 0x38) = temp_f1_2456;
                temp_r3_2458 = M2C_FIELD(temp_r3_2449, void **, 0x3C);
                if (temp_r3_2458 != NULL) {
                    M2C_FIELD(temp_r3_2458, f32 *, 0x20) = temp_f1_2456;
                    M2C_FIELD(temp_r3_2458, f32 *, 0x24) = (f32) (temp_f1_2456 * temp_f1_2456);
                    M2C_FIELD(temp_r3_2458, f32 *, 0x28) = (f32) (1.0f / temp_f1_2456);
                    M2C_FIELD(temp_r3_2458, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_2458, f32 *, 0x24));
                }
                MKVector(0.0f, 17000.0f * temp_f4_2454, 0.0f);
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                temp_r3_2485 = this->unk90.unk58;
                arg_sp470 = arg_sp90;
                arg_sp98 = this->unk90.unk38 + arg_sp468;
                M2C_FIELD(temp_r3_2485, f64 *, 0x10) = arg_sp90;
                M2C_FIELD(temp_r3_2485, f64 *, 0x18) = (f64) arg_sp98;
                temp_r3_2491 = M2C_FIELD(temp_r3_2485, void **, 0x3C);
                arg_sp478 = (f64) arg_sp98;
                if (temp_r3_2491 != NULL) {
                    M2C_FIELD(temp_r3_2491, f64 *, 0x10) = arg_sp90;
                    M2C_FIELD(temp_r3_2491, f64 *, 0x18) = (f64) arg_sp98;
                }
            }
            MKVector(500.0f, 500.0f, 500.0f);
            MKVector(20.0f, -10.0f, 20.0f);
            arg_sp420.operator*(gUpdateTimeDelta);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp430 = arg_sp30;
            arg_sp38 = this->unk90.unk48 + arg_sp428;
            arg_sp438 = (f64) arg_sp38;
            MKVector(0.1f, 0.0f, 0.1f);
            Min(*((MKVector3 *) &arg_sp80), *((MKVector3 *) &arg_sp430));
            Max(*((MKVector3 *) &arg_sp450), *((MKVector3 *) &arg_sp80));
            M2C_FIELD(this, f32 *, 0xD0) = arg_sp450;
            M2C_FIELD(this, f32 *, 0xD8) = arg_sp458;
            if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
                M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                if ((var_f27_2435 == 0.5f) && ((u8) M2C_FIELD(this, u8 *, 0x2F1) == 0)) {
                    arg_sp834 = 0;
                    temp_f1_2559 = M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), f32 (**)(), 0x54)();
                    arg_sp830 = 0x458;
                    arg_sp838 = temp_f1_2559 + (0.017453292f * (30.0f * (var_f27_2435 / 0.5f)));
                    M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f32, f32), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &arg_sp830, 30.0f, 0.017453292f);
                }
            }
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (this->unk90.unk70 == 0.0f) {
                this->unk90.unk74 = 8e-45f;
                this->unk90.unk70 = 1.4f;
                temp_r4_2586 = this->unk90.unk58;
                if (M2C_BITWISE(u32, temp_r4_2586) != 0U) {
                    gb.unk80->EnableLight(M2C_BITWISE(ManagedLight *, temp_r4_2586), 0U);
                }
                if (((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) && ((u8) M2C_FIELD(this, u8 *, 0x2F1) == 0)) {
                    arg_sp2C = 0;
                    arg_sp28 = 0x459;
                    M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&arg_sp28);
                }
                gb.unk2CC.Disable(this->unk2E8);
                this->unk2E8 = -1;
            }
            arg_sp210 = var_f27_2435;
            arg_sp214 = var_f27_2435;
            arg_sp218 = var_f27_2435;
            arg_sp21C = 1.0f;
            arg_sp3F0 = (f64) arg_sp210;
            arg_sp3F8 = (f64) arg_sp218;
            MKModel_SetColor((MKModel *) this->unk90.unk60, *((MKVector4 *) &arg_sp3F0));
            var_r25_2640 = 0;
            do {
                temp_r28_2647 = MKRand_Int(&gViewSeed, 0xF, 0x1E);
                var_r24_2650 = 0;
                temp_f22_2654 = 6.2831855f / (f32) temp_r28_2647;
loop_156:
                if (var_r24_2650 < temp_r28_2647) {
                    temp_f19_2670 = (f32) var_r24_2650 * (temp_f22_2654 + MKRand_Float(&gViewSeed, -0.2f, 0.2f));
                    temp_f20_2672 = MKRand_Float(&gViewSeed, 0.4f, 1.0f);
                    temp_f21_2679 = -_table_sinf(1.5707964f + temp_f19_2670) * temp_f20_2672;
                    temp_f20_2681 = MKRand_Float(&gViewSeed, 0.4f, 1.0f);
                    temp_f2_2684 = _table_sinf(temp_f19_2670) * temp_f20_2681;
                    arg_sp208 = temp_f21_2679;
                    arg_sp200 = temp_f2_2684;
                    arg_sp204 = 0.0f;
                    arg_sp828 = (f64) arg_sp208;
                    arg_sp820 = (f64) arg_sp200;
                    temp_f1_2696 = 150.0f + MKRand_Float(&gViewSeed, -100.0f, 350.0f);
                    arg_sp1C8 = 0.0f;
                    arg_sp1C0 = 0.0f;
                    arg_sp1C4 = temp_f1_2696;
                    arg_sp3B8 = (f64) arg_sp1C8;
                    arg_sp3B0 = (f64) arg_sp1C0;
                    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r29, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f25 */);
                    arg_sp3C0 = arg_sp1F0;
                    arg_sp1F8 = (f32) arg_sp828 * 200.0f;
                    arg_sp3C8 = (f64) arg_sp1F8;
                    M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f26 */);
                    arg_sp3D0 = arg_sp1E0;
                    arg_sp1E8 = (f32) arg_sp3C8 * this->unk90.unk40;
                    arg_sp3D8 = (f64) arg_sp1E8;
                    M2C_ERROR(/* unknown instruction: psq_lx $f2, $zero, $r26, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_add $f1, $f2, $f1 */);
                    arg_sp3E0 = arg_sp1D0;
                    arg_sp1D8 = this->unk90.unk38 + (f32) arg_sp3D8;
                    arg_sp3E8 = (f64) arg_sp1D8;
                    M2C_ERROR(/* unknown instruction: ps_add $f1, $f2, $f1 */);
                    arg_sp810 = arg_sp1B0;
                    arg_sp1B8 = (f32) arg_sp3E8 + (f32) arg_sp3B8;
                    arg_sp818 = (f64) arg_sp1B8;
                    if ((u8) M2C_FIELD(this, u8 *, 0x2F1) == 0) {
                        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r29, 0x0, qr0 */);
                        M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f24 */);
                        arg_sp1A8 = (f32) arg_sp828 * 1000.0f;
                        arg_sp3A0 = arg_sp1A0;
                        arg_sp3A8 = (f64) arg_sp1A8;
                        arg_sp14 = MKRand_Float(&gViewSeed, 3.0f, 6.0f);
                        temp_f20_2772 = MKRand_Float(&gViewSeed, 0.0f, 0.2f);
                        temp_f21_2777 = MKRand_Float(&gViewSeed, 0.6f, 0.8f);
                        arg_sp190 = MKRand_Float(&gViewSeed, 0.8f, 1.0f);
                        arg_sp194 = temp_f21_2777;
                        arg_sp198 = temp_f20_2772;
                        arg_sp19C = 1.0f;
                        arg_sp390 = (f64) arg_sp190;
                        arg_sp398 = (f64) arg_sp198;
                        gb.unk74->Emit(*((MKVector3 *) &arg_sp810), *((MKVector3 *) &arg_sp3A0), arg_sp14, *((MKVector4 *) &arg_sp390), -400.0f);
                    } else {
                        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r29, 0x0, qr0 */);
                        M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f23 */);
                        arg_sp188 = (f32) arg_sp828 * 1000.0f;
                        arg_sp380 = arg_sp180;
                        arg_sp388 = (f64) arg_sp188;
                        arg_sp10 = MKRand_Float(&gViewSeed, 3.0f, 6.0f);
                        temp_f21_2819 = MKRand_Float(&gViewSeed, 0.3f, 1.9f);
                        arg_sp174 = MKRand_Float(&gViewSeed, 0.1f, 0.2f);
                        arg_sp170 = 1.0f;
                        arg_sp178 = temp_f21_2819;
                        arg_sp17C = 1.0f;
                        arg_sp370 = (f64) arg_sp170;
                        arg_sp378 = (f64) arg_sp178;
                        gb.unk74->Emit(*((MKVector3 *) &arg_sp810), *((MKVector3 *) &arg_sp380), arg_sp10, *((MKVector4 *) &arg_sp370), -400.0f);
                    }
                    var_r24_2650 += 1;
                    goto loop_156;
                }
                var_r25_2640 += 1;
            } while (var_r25_2640 < 2);
            return;
        case 6:
            var_f0_2850 = this->unk90.unk70;
            if (var_f0_2850 < 1.4f) {

            } else {
                var_f0_2850 = 1.4f;
            }
            if (var_f0_2850 > 0.0f) {

            } else {
                var_f0_2850 = 0.0f;
            }
            this->unk90.unk70 = var_f0_2850;
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (this->unk90.unk70 == 0.0f) {
                this->unk90.unk74 = 0.0f;
                gb.unkB8.unk18 = 0;
                gb.unk381 = 0;
            }
            break;
        }
    }
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void FuryFXFire::Resolve() {
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_r4_2975;
    f32 temp_r4_3009;
    s32 var_r28_3020;
    s32 var_r31_3021;
    void *temp_r29_3025;

    FuryFX::Resolve();
    sp50 = 0.0f;
    sp60 = 0.0f;
    sp38 = 1.0f;
    sp3C = 0.75f;
    sp40 = 1.0f;
    sp44 = 1.0f;
    sp48 = 0.0f;
    sp4C = 0.0f;
    sp58 = 0.0f;
    sp5C = 0.0f;
    sp98 = (f64) sp38;
    spA0 = (f64) sp40;
    spA8 = (f64) sp48;
    spB0 = (f64) sp50;
    spB8 = (f64) sp58;
    spC0 = (f64) sp60;
    this->unk90.unk58 = M2C_BITWISE(f32, gb.unk80->AllocManagedLight(*((MKVector3 *) &spB8), *((MKVector3 *) &spA8), *((MKVector4 *) &sp98), 4000.0f, lit_761, lit_762));
    temp_r4_2975 = this->unk90.unk58;
    if (M2C_BITWISE(u32, temp_r4_2975) != 0U) {
        gb.unk80->EnableLight(M2C_BITWISE(ManagedLight *, temp_r4_2975), 0U);
    }
    sp18 = 1.0f;
    sp1C = 1.0f;
    sp30 = 0.0f;
    sp20 = 1.0f;
    sp24 = 1.0f;
    sp28 = 0.0f;
    sp2C = 0.0f;
    sp78 = (f64) sp18;
    sp80 = (f64) sp20;
    sp88 = (f64) sp28;
    sp90 = (f64) sp30;
    this->unk90.unk64 = M2C_BITWISE(f32, gb.unk64->Alloc(*((MKVector3 *) &sp88), *((MKVector4 *) &sp78), 1.0f, lit_766, lit_767));
    temp_r4_3009 = this->unk90.unk64;
    if (M2C_BITWISE(u32, temp_r4_3009) != 0U) {
        M2C_FIELD(temp_r4_3009, u8 *, 0x31) = (u8) (M2C_FIELD(temp_r4_3009, u8 *, 0x31) & ~0x40);
    }
    var_r28_3020 = 0;
    var_r31_3021 = 0;
    do {
        sp8 = 1.0f;
        temp_r29_3025 = this + var_r31_3021;
        spC = 1.0f;
        sp10 = 1.0f;
        sp14 = 1.0f;
        sp68 = (f64) sp8;
        sp70 = (f64) sp10;
        ((ShapedTrailFX *) (M2C_FIELD(temp_r29_3025, ShapedTrailFX **, 0x130)))->InitData(this->unk90.unk5C, lit_774, lit_stringBase0, lit_775, *((MKVector4 *) &sp68), 2.5f, 0U, 1.0f);
        ((KDSoundFader *) (temp_r29_3025 + 0x134))->Init(0.25f, 0.25f);
        ((KDSoundFader *) (temp_r29_3025 + 0x15C))->Init(0.25f, 0.25f);
        M2C_FIELD(temp_r29_3025, f32 *, 0x110) = MKRand_Float(&gViewSeed, 0.0f, 6.2831855f);
        M2C_FIELD(temp_r29_3025, f32 *, 0x114) = MKRand_Float(&gViewSeed, 3.1415927f, 6.2831855f);
        M2C_FIELD(temp_r29_3025, f32 *, 0x118) = MKRand_Float(&gViewSeed, 0.0f, 100.0f);
        var_r28_3020 += 1;
        M2C_FIELD(temp_r29_3025, f32 *, 0x11C) = MKRand_Float(&gViewSeed, 0.0f, 100.0f);
        var_r31_3021 += 0x80;
    } while (var_r28_3020 < 3);
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void FuryFXFire::Init() {
    s32 var_r29_3123;
    s32 var_r31_3124;

    FuryFX::Init();
    SetDefaults();
    this->unk90.unk50 = M2C_BITWISE(f32, MKMaterial_Create(&lit_stringBase0[7]));
    this->unk90.unk58 = 0.0f;
    this->unk90.unk60 = MKModel_Create(&lit_stringBase0[0x14], NULL, 2, NULL);
    this->unk90.unk68 = -1.0f;
    this->unk90.unk6C = 0.0f;
    this->unk90.unk5C = MKModel_Create(&lit_stringBase0[0x29], NULL, 2, NULL);
    var_r29_3123 = 0;
    var_r31_3124 = 0;
    do {
        gMK->CreatePropDeferred(&lit_stringBase0[0x32], this + (var_r31_3124 + 0x130));
        var_r29_3123 += 1;
        var_r31_3124 += 0x80;
    } while (var_r29_3123 < 3);
    this->unk2E8 = -1;
    this->unk90.unk54 = M2C_BITWISE(f32, MKMaterial_Create(&lit_stringBase0[0x40]));
}
#endif

void FuryFXFire_cpp::__sinit() {
    f32 temp_f0_3184;
    f64 temp_f1_3165;
    f64 temp_f1_3173;
    f64 temp_f3_3153;
    f64 temp_f4_3162;
    f64 temp_f4_3170;
    f64 temp_f8_3155;

    temp_f3_3153 = __frsqrte(2014000.0);
    temp_f8_3155 = __frsqrte(380000.0);
    temp_f4_3162 = 0.5 * temp_f3_3153 * -((2014000.0 * (temp_f3_3153 * temp_f3_3153)) - 3.0);
    temp_f1_3165 = 0.5 * temp_f8_3155 * -((380000.0 * (temp_f8_3155 * temp_f8_3155)) - 3.0);
    temp_f4_3170 = 0.5 * temp_f4_3162 * -((2014000.0 * (temp_f4_3162 * temp_f4_3162)) - 3.0);
    temp_f1_3173 = 0.5 * temp_f1_3165 * -((380000.0 * (temp_f1_3165 * temp_f1_3165)) - 3.0);
    temp_f0_3184 = (f32) (380000.0 * (0.5 * temp_f1_3173 * -((380000.0 * (temp_f1_3173 * temp_f1_3173)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_3170 * -((2014000.0 * (temp_f4_3170 * temp_f4_3170)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_3184;
}
