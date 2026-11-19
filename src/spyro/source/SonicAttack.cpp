#include "spyro/source/SonicAttack.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/Projectile.h"
#include "unplaced_enums.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

M2C_UNK free(MKHeap *);                             /* extern */
MKHeap *malloc(M2C_UNK);                            /* extern */
extern M2C_UNK gEmptyPtrListDL;
extern f32 gUpdateTimeDelta;
#if 0 // DRAFT: identifier 'gb' redeclared
extern M2C_UNK gb;
#endif
extern MKPropDescriptor *pSonicAttackDescriptor;

#if 0 // DRAFT: type mismatch
void SonicAttack::Deinit() {
    MKHeap *temp_r0_56;
    MKHeap *temp_r0_75;
    MKHeap *temp_r3_78;
    MKHeap *var_r31_52;
    MKHeap *var_r3_53;
    MKHeap *var_r4_51;
    u32 temp_r0_61;

    var_r4_51 = this->unk15C;
    var_r31_52 = var_r4_51;
    var_r3_53 = var_r4_51;
loop_3:
    temp_r0_61 = M2C_FIELD(var_r3_53, u32 *, -4);
    var_r3_53 -= 4;
    if (temp_r0_61 != 0U) {
        temp_r0_56 = var_r3_53->unk0;
        if (temp_r0_56 < var_r31_52) {
            var_r31_52 = temp_r0_56;
        }
        goto loop_3;
    }
    if (var_r3_53 != &gEmptyPtrListDL) {
loop_9:
        temp_r0_75 = var_r4_51->unk0;
        if (temp_r0_75 != NULL) {
            if (temp_r0_75 < var_r31_52) {
                var_r31_52 = temp_r0_75;
            }
            var_r4_51 += 4;
            goto loop_9;
        }
        temp_r3_78 = var_r3_53->Current();
        if (temp_r3_78 != NULL) {
            ((MKHeap *) (temp_r3_78->Current()))->Free(var_r31_52, NULL, 0);
        } else {
            free(var_r31_52);
        }
    }
    this->unk15C = NULL;
    MKModel_Destroy(this->unk168);
    Projectile::Deinit();
}
#endif

void SonicAttack::DrawSonicRings() {
    MKHeap *temp_r4_124;
    MKHeap *var_r31_112;

    var_r31_112 = this->unk15C;
loop_2:
    if (var_r31_112 != NULL) {
        temp_r4_124 = var_r31_112->unk0;
        if (temp_r4_124 != NULL) {
            MKModel_SetWorldMatrix(this->unk168, *((Matrix *) temp_r4_124));
            MKModel_Draw(this->unk168, NULL);
            var_r31_112 += 4;
            goto loop_2;
        }
    }
}

#if 0 // DRAFT: illegal explicit conversion from 'signed char *' to
void SonicAttack::UpdateSonicRings() {
    u8 sp140;
    s32 sp13C;
    void *sp138;
    s32 sp134;
    f32 sp130;
    s32 sp12C;
    s8 sp12B;
    s8 sp12A;
    s16 sp128;
    f32 sp124;
    f32 sp120;
    f32 sp11C;
    f32 sp118;
    f32 sp114;
    f32 sp110;
    f32 sp108;
    f32 sp104;
    f32 sp100;
    f32 spF8;
    f32 spF4;
    f32 spF0;
    s8 spE9;
    s8 spE8;
    s32 spE4;
    f32 spE0;
    s32 spDC;
    s8 spDA;
    s8 spD9;
    s8 spD8;
    f64 spD0;                                       /* compiler-managed */
    f64 spC8;                                       /* compiler-managed */
    MKProp *spC4;
    s32 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    s32 sp9C;
    s32 sp98;
    f64 sp90;
    f64 sp88;
    MKVector3 sp78;
    MKVector3 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKHeap *temp_r30_362;
    MKHeap *temp_r3_350;
    MKHeap *temp_r4_353;
    MKHeap *var_r28_156;
    MKProp *temp_r4_286;
    MKPtrList<MKProp> *temp_r3_256;
    MKPtrList<MKProp> *temp_r4_337;
    f32 temp_f29_175;
    f64 temp_f0_190;
    u8 var_r27_211;
    void **temp_r3_339;
    void **var_r3_259;
    void *temp_r0_268;
    void *var_r29_247;

    var_r28_156 = this->unk15C;
loop_24:
    if (var_r28_156 != NULL) {
        temp_r30_362 = var_r28_156->unk0;
        if (temp_r30_362 != NULL) {
            ((Matrix *) temp_r30_362)->Scale3x3((Matrix *) temp_r30_362, (2.0f * gUpdateTimeDelta) + 1.0f);
            temp_f29_175 = gUpdateTimeDelta;
            sp8 = -M2C_BITWISE(f32, temp_r30_362->unk20);
            spC = -M2C_BITWISE(f32, temp_r30_362->unk24);
            sp10 = -M2C_BITWISE(f32, temp_r30_362->unk28);
            sp58 = (f64) sp8;
            sp60 = (f64) sp10;
            Normalise(sp68);
            sp78.operator*(3000.0f);
            temp_f0_190 = sp78 * (f64) temp_f29_175;
            sp28 = temp_f0_190;
            sp88 = temp_f0_190;
            sp30 = sp78.unk8 * temp_f29_175;
            sp90 = (f64) sp30;
            ((Matrix *) temp_r30_362)->Translate((Matrix *) temp_r30_362, *((MKVector3 *) &sp88));
            var_r27_211 = 0;
            temp_r30_362->unk40 = M2C_BITWISE(f32, temp_r30_362->unk40) - gUpdateTimeDelta;
            spF0 = 0.0f;
            spF4 = 0.0f;
            spF8 = 0.0f;
            sp100 = 0.0f;
            sp104 = 0.0f;
            sp108 = 0.0f;
            sp110 = 0.0f;
            sp114 = 0.0f;
            sp118 = 0.0f;
            sp11C = 1.0f;
            sp120 = 0.0f;
            sp124 = 0.0f;
            sp128 = 0;
            sp12A = 0;
            sp12B = 0;
            sp12C = 0;
            sp130 = 3.4028235e38f;
            sp134 = 0;
            sp138 = NULL;
            sp13C = -1;
            sp140 = 0;
            if (MKCollision_SphereCollide(*((MKVector3 *) &temp_r30_362->unk30), 200.0f, (MKCollisionResult *) &spF0, 1, (MKCollisionMode) 2, 0x08000000) != 0) {
                var_r27_211 = 1;
                if ((sp140 != 0) && (sp138 != NULL) && (var_r29_247 = M2C_FIELD(sp138, void **, 8), ((var_r29_247 == NULL) == 0))) {

                } else {
                    var_r29_247 = NULL;
                }
                if (var_r29_247 != NULL) {
                    temp_r3_256 = this->unk134;
                    if (temp_r3_256 != NULL) {
                        var_r3_259 = *temp_r3_256;
loop_13:
                        temp_r0_268 = *var_r3_259;
                        if (temp_r0_268 == NULL) {
                            var_r3_259 = NULL;
                        } else if (temp_r0_268 == var_r29_247) {

                        } else {
                            var_r3_259 += 4;
                            goto loop_13;
                        }
                        if (var_r3_259 == NULL) {
                            goto block_16;
                        }
                    } else {
block_16:
                        sp9C = 0;
                        sp18 = M2C_BITWISE(f64, M2C_FIELD(temp_r30_362, s8 **, 0x20)) * 1.58735232e-314;
                        temp_r4_286 = this->unk130;
                        sp20 = M2C_BITWISE(f32, temp_r30_362->unk28) * -1.0f;
                        sp48 = sp18;
                        sp50 = (f64) sp20;
                        sp98 = 7;
                        spC0 = this->unk144;
                        spC4 = temp_r4_286;
                        spA0 = sp18;
                        spA8 = (f64) sp20;
                        spD8 = 0;
                        spE4 = 2;
                        spE0 = 10.0f;
                        spD9 = 0;
                        spDA = 1;
                        spDC = -1;
                        spB0 = M2C_FIELD(&MKVector3::one, f64 *, 0);
                        spB8 = M2C_FIELD(&MKVector3::one, f64 *, 8);
                        spE8 = 0;
                        if (temp_r4_286 != NULL) {
                            ((MKProp *) &sp38)->GetPos();
                            spC8 = sp38;
                            spD0 = sp40;
                        } else {
                            spC8 = 0.0f;
                            (*(f32 *) ((u8 *) &spC4 + 0x8)) = 0.0f;
                            spD0 = 0.0f;
                        }
                        spE9 = 0;
                        M2C_FIELD(M2C_FIELD(var_r29_247, void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(var_r29_247, &sp98);
                        temp_r4_337 = this->unk134;
                        temp_r3_339 = *temp_r4_337 - 4;
                        *temp_r4_337 = temp_r3_339;
                        *temp_r3_339 = var_r29_247;
                    }
                }
            }
            if ((M2C_BITWISE(f32, temp_r30_362->unk40) <= 0.0f) || (var_r27_211 != 0)) {
                temp_r3_350 = this->unk15C;
                this->unk15C = (MKHeap *) &temp_r3_350->unk4;
                temp_r4_353 = temp_r3_350->unk0;
                temp_r3_350->unk0 = var_r28_156->unk0;
                var_r28_156->unk0 = temp_r4_353;
            }
            var_r28_156 += 4;
            goto loop_24;
        }
    }
    if (((u8) this->unk16C != 0) && ((MKHeap *) this->unk15C->unk0 == NULL)) {
        this->unk16C = 0;
        Disable();
    }
}
#endif

void SonicAttack::SpawnSonicRing(const MKVector3 &arg0, const MKVector3 &arg1) {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKHeap *temp_r6_408;
    Matrix *temp_r31_414;

    temp_r6_408 = this->unk15C;
    if ((Matrix *) M2C_FIELD(temp_r6_408, Matrix **, -4) != NULL) {
        this->unk15C = temp_r6_408 - 4;
        temp_r31_414 = M2C_FIELD(temp_r6_408, Matrix **, -4);
        if (temp_r31_414 != NULL) {
            spC = 1.0f;
            sp8 = 0.0f;
            sp10 = 0.0f;
            M2C_FIELD(temp_r31_414, f32 *, 0x40) = 1.0f;
            sp18 = (f64) sp8;
            sp20 = (f64) sp10;
            M2C_STRUCT_COPY(temp_r31_414, &Matrix::identity, 0x40);
            KDMath_BuildMatrixFromFwd(temp_r31_414, arg1, (MKVector3 *) &sp18);
            temp_r31_414->unk30 = arg0.unk0;
            temp_r31_414->unk34 = arg0.unk4;
            temp_r31_414->unk38 = arg0.unk8;
            temp_r31_414->unk3C = 1.0f;
        }
    }
}

void SonicAttack::FireBurstEnd() {
    this->unk158 = 0;
    this->unk150 = NULL;
    this->unk154 = NULL;
    this->unk16C = 1;
}

void SonicAttack::FireBurst(MKVector3 *arg0, MKVector3 *arg1, int arg2, int arg3) {
    this->unk158 = 1;
    this->unk150 = arg0;
    this->unk154 = arg1;
    this->unk164 = 0.0f;
loop_2:
    if ((MKHeap *) this->unk15C->unk0 != NULL) {
        this->unk15C = (MKHeap *) &this->unk15C->unk4;
        goto loop_2;
    }
    Enable();
}

void SonicAttack::Fire(const MKVector3 &arg0, const MKVector3 &arg1, MKProp *arg2, int arg3, int arg4) {
    Disable();
    this->unk164 = 0.0f;
}

void SonicAttack::Collided(MKCollisionResult &arg0) {
    Disable();
}

#if 0 // DRAFT: illegal implicit conversion from 'GameGlobals *' to
void SonicAttack::Draw() {
    GameGlobals::Capture *temp_r31_550;

    temp_r31_550 = &gb + 0x24;
    temp_r31_550->Get();
    DrawSonicRings();
    temp_r31_550->Release();
}
#endif

#if 0 // DRAFT: undefined identifier '__float_nan'
void SonicAttack::Update() {
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    MKVector3 *temp_r3_592;
    MKVector3 *temp_r4_591;
    f32 var_f4_584;
    f32 var_f5_612;
    f64 temp_f1_617;
    f64 temp_f1_623;
    f64 temp_f1_627;
    s32 temp_r3_646;
    s32 var_r0_656;

    Projectile::Update();
    if (((u8) this->unk158 != 0) && ((MKVector3 *) this->unk150 != NULL) && ((MKVector3 *) this->unk154 != NULL)) {
        var_f4_584 = 0.0f;
        this->unk164 -= gUpdateTimeDelta;
        if (this->unk164 <= 0.0f) {
            temp_r4_591 = this->unk150;
            temp_r3_592 = this->unk154;
            sp20 = M2C_FIELD(temp_r3_592, f64 *, 0) - M2C_FIELD(temp_r4_591, f64 *, 0);
            sp30 = sp20;
            sp28 = temp_r3_592->unk8 - temp_r4_591->unk8;
            sp38 = (f64) sp28;
            var_f5_612 = ((f32) sp38 * (f32) sp38) + (((f32) sp30 * (f32) sp30) + ((*(f32 *) ((u8 *) &sp30 + 0x4)) * (*(f32 *) ((u8 *) &sp30 + 0x4))));
            if (var_f5_612 > 1e-12f) {
                if (var_f5_612 > 0.0f) {
                    temp_f1_617 = __frsqrte(var_f5_612);
                    temp_f1_623 = 0.5 * temp_f1_617 * -(((f64) var_f5_612 * (temp_f1_617 * temp_f1_617)) - 3.0);
                    temp_f1_627 = 0.5 * temp_f1_623 * -(((f64) var_f5_612 * (temp_f1_623 * temp_f1_623)) - 3.0);
                    var_f5_612 = (f32) ((f64) var_f5_612 * (0.5 * temp_f1_627 * -(((f64) var_f5_612 * (temp_f1_627 * temp_f1_627)) - 3.0)));
                } else if (var_f5_612 < M2C_BITWISE(f32, 0.0)) {
                    var_f5_612 = __float_nan;
                } else {
                    sp8 = var_f5_612;
                    temp_r3_646 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                    switch (temp_r3_646) {          /* irregular */
                    case 0x7F800000:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_656 = 1;
                        } else {
                            var_r0_656 = 2;
                        }
                        break;
                    case 0x0:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_656 = 5;
                        } else {
                            var_r0_656 = 3;
                        }
                        break;
                    default:
                        var_r0_656 = 4;
                        break;
                    }
                    if (var_r0_656 == 1) {
                        var_f5_612 = __float_nan;
                    }
                }
                var_f4_584 = 1.0f / var_f5_612;
            }
            sp14 = (*(f32 *) ((u8 *) &sp30 + 0x4)) * var_f4_584;
            sp10 = (f32) sp30 * var_f4_584;
            sp18 = (f32) sp38 * var_f4_584;
            sp40 = (f64) sp10;
            sp48 = (f64) sp18;
            SpawnSonicRing(*this->unk150, *((MKVector3 *) &sp40));
            this->unk164 = 0.075f;
        }
    }
    UpdateSonicRings();
}
#endif

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void SonicAttack::LoadDone() {
    Matrix sp30;
    M2C_UNK sp2C;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;

    Projectile::LoadDone();
    this->unk168 = MKModel_Create("fx0031_sonicring", NULL, 2, NULL);
    this->unk160 = Tools_GetMatchingMaterial(this->unk168, "fx0031_sonicring");
    M2C_STRUCT_COPY((s32) &sp2C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    sp10 = 0.01f;
    sp14 = -0.01f;
    sp18 = 0.0f;
    sp20 = (f64) sp10;
    sp28 = (f64) sp18;
    sp30.unk30 = (f32) sp20;
    sp30.unk34 = (*(f32 *) ((u8 *) &sp20 + 0x4));
    sp30.unk38 = (f32) sp28;
    sp30.unk3C = 1.0f;
    MKMaterial_SetTextureMatrix(this->unk160, &sp30);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void SonicAttack::Init() {
    MKHeap *temp_r3_783;
    MKHeap *temp_r3_805;
    MKHeap *temp_r3_811;
    MKHeap *var_r3_790;
    MKHeap *var_r5_799;
    s32 var_ctr_803;

    Projectile::Init();
    SetDefaults();
    temp_r3_783 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_783 != NULL) {
        var_r3_790 = ((MKHeap *) (temp_r3_783->Current()))->Alloc(0x1070, NULL, 0);
    } else {
        var_r3_790 = malloc(0x1070);
    }
    this->unk15C = var_r3_790;
    var_r5_799 = this->unk15C;
    this->unk15C = var_r5_799 + 0xFA0;
    M2C_FIELD(var_r5_799, s32 *, 0xFA0) = 0;
    var_ctr_803 = 0x32;
    do {
        temp_r3_805 = this->unk15C;
        this->unk15C = (MKHeap *) &temp_r3_805->unk4;
        temp_r3_805->unk4 = (s32) var_r5_799;
        var_r5_799 += 0x50;
        var_ctr_803 -= 1;
    } while (var_ctr_803 != 0);
    temp_r3_811 = this->unk15C;
    this->unk15C = (MKHeap *) &temp_r3_811->unk4;
    temp_r3_811->unk4 = 0;
}
#endif

void SonicAttack::Reset() {
    Projectile::Reset();
    SetDefaults();
}

void SonicAttack::SetDefaults() {
    this->unk150 = NULL;
    this->unk154 = NULL;
    this->unk158 = 0;
    this->unk164 = 0.0f;
    this->unk16C = 0;
}

void *SonicAttack::CreateInstance() {
    void *temp_r3_864;

    if ((MKPropDescriptor *) pSonicAttackDescriptor != NULL) {
        temp_r3_864 = pSonicAttackDescriptor->CreateInstance();
        if (temp_r3_864 != NULL) {
            M2C_FIELD(M2C_FIELD(temp_r3_864, void **, 0x44), M2C_UNK (**)(), 0x20)();
            return temp_r3_864;
        }
    }
    return NULL;
}

#if 0 // DRAFT: illegal use of non-static member
void SonicAttackDescriptor::LoadDone() {
    GamePropDescriptor::LoadDone();
    pSonicAttackDescriptor = (MKPropDescriptor *) this;
}
#endif

void SonicAttackDescriptor::Deinit() {
    pSonicAttackDescriptor = NULL;
    KDPropExDescriptor::Deinit();
}
