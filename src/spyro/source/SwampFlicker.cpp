#include "spyro/source/SwampFlicker.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Critters.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/Volume.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKModel.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDRandom.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(s32);                                  /* extern */
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;

#if 0 // DRAFT: illegal use of non-static member
void SwampFlicker::Deinit() {
    MKHeap *temp_r3_57;
    void *temp_r31_54;

    temp_r31_54 = this->unk170;
    if (temp_r31_54 != NULL) {
        temp_r3_57 = MKHeap::Current();
        if (temp_r3_57 != NULL) {
            ((MKHeap *) (temp_r3_57->Current()))->Free(temp_r31_54, NULL, 0);
        } else {
            free(temp_r31_54);
        }
    }
    this->unk170 = NULL;
    Critters::Deinit();
}
#endif

#if 0 // DRAFT: illegal type
void SwampFlicker::Draw() {
    Matrix *temp_r29_97;
    s32 var_r30_89;
    s32 var_r31_90;

    var_r30_89 = 0;
    var_r31_90 = 0;
loop_2:
    if (var_r30_89 < (s32) this->unk90) {
        temp_r29_97 = this->unk170 + var_r31_90;
        this->unk80->SetAnim(M2C_FIELD(temp_r29_97, MKAnim **, 0x50), 0.0f, 0.0f, 0, -1);
        this->unk80->JumpToPos(M2C_FIELD(temp_r29_97, f32 *, 0x54), -1);
        MKModel_SetWorldMatrix(this->unk4, *temp_r29_97);
        MKModel_Draw(this->unk4, NULL);
        var_r30_89 += 1;
        var_r31_90 += 0x70;
        goto loop_2;
    }
}
#endif

#if 0 // DRAFT: illegal type
void SwampFlicker::Update() {
    s8 sp208;
    s32 sp204;
    s32 sp200;
    s32 sp1FC;
    f32 sp1F8;
    s32 sp1F4;
    s8 sp1F3;
    s8 sp1F2;
    s16 sp1F0;
    f32 sp1EC;
    f32 sp1E8;
    f32 sp1E4;
    f32 sp1E0;
    f32 sp1DC;
    f32 sp1D8;
    f32 sp1D0;
    f32 sp1CC;
    f32 sp1C8;
    f32 sp1C0;
    f32 sp1BC;
    f32 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    MKVector3 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    MKVector3 spB8;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp90;
    f64 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f64 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    Matrix *temp_r30_141;
    f32 temp_f31_392;
    f64 temp_f0_266;
    f64 temp_f0_285;
    f64 temp_f0_344;
    f64 temp_f0_369;
    f64 temp_f0_399;
    s32 temp_r0_145;
    s32 temp_r27_167;
    s32 temp_r27_433;
    s32 var_r28_136;
    s32 var_r31_135;

    var_r31_135 = 0;
    var_r28_136 = 0;
loop_16:
    if (var_r31_135 < (s32) this->unk90) {
        temp_r30_141 = this->unk170 + var_r28_136;
        M2C_FIELD(temp_r30_141, f32 *, 0x64) = (f32) (M2C_FIELD(temp_r30_141, f32 *, 0x64) - gUpdateTimeDelta);
        temp_r0_145 = M2C_FIELD(temp_r30_141, s32 *, 0x60);
        if (temp_r0_145 != 2) {
            if (temp_r0_145 < 2) {
                if (temp_r0_145 < 0) {

                } else {
                    M2C_FIELD(temp_r30_141, f32 *, 0x54) = (f32) ((M2C_FIELD(temp_r30_141, f32 *, 0x58) * gUpdateTimeDelta) + M2C_FIELD(temp_r30_141, f32 *, 0x54));
                    if (M2C_FIELD(temp_r30_141, f32 *, 0x54) > 1.0f) {
                        M2C_FIELD(temp_r30_141, s32 *, 0x60) = MKRand_Int(&gViewSeed, 0, 1);
                        temp_r27_167 = M2C_FIELD(temp_r30_141, s32 *, 0x60);
                        M2C_FIELD(temp_r30_141, void **, 0x50) = (void *) *(checked_cast<SwampFlickerDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + ((temp_r27_167 * 4) + 0x70));
                        M2C_FIELD(temp_r30_141, f32 *, 0x58) = (f32) (30.0f / (30.0f * ((f32) M2C_FIELD(M2C_FIELD(temp_r30_141, void **, 0x50), s16 *, 4) / 30.0f)));
                        M2C_FIELD(temp_r30_141, f32 *, 0x54) = 0.0f;
                    } else if (M2C_FIELD(temp_r30_141, f32 *, 0x64) <= 0.0f) {
                        M2C_FIELD(temp_r30_141, f32 *, 0x64) = 0.0f;
                        M2C_FIELD(temp_r30_141, s32 *, 0x60) = 2;
                        M2C_FIELD(temp_r30_141, void **, 0x50) = (void *) M2C_FIELD(checked_cast<SwampFlickerDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), void **, 0x78);
                        spB0 = 0.0f;
                        sp80 = 0.0f;
                        sp78 = 0.0f;
                        sp7C = -200.0f;
                        spA8 = 0.0f;
                        spAC = 1.0f;
                        sp148 = (f64) sp78;
                        sp150 = (f64) sp80;
                        M2C_FIELD(temp_r30_141, f32 *, 0x58) = (f32) (30.0f / (30.0f * ((f32) M2C_FIELD(M2C_FIELD(temp_r30_141, void **, 0x50), s16 *, 4) / 30.0f)));
                        M2C_FIELD(temp_r30_141, f32 *, 0x54) = 0.0f;
                        sp1A8 = M2C_FIELD(temp_r30_141, f64 *, 0x30);
                        sp1B0 = M2C_FIELD(temp_r30_141, f64 *, 0x38);
                        sp198 = (f64) spA8;
                        sp1A0 = (f64) spB0;
                        sp1B8 = 0.0f;
                        sp1BC = 0.0f;
                        sp1C0 = 0.0f;
                        sp1C8 = 0.0f;
                        sp1CC = 0.0f;
                        sp1D0 = 0.0f;
                        sp1D8 = 0.0f;
                        sp1DC = 0.0f;
                        sp1E0 = 0.0f;
                        sp1E4 = 1.0f;
                        sp1E8 = 0.0f;
                        sp1EC = 0.0f;
                        sp1F0 = 0;
                        sp1F2 = 0;
                        sp1F3 = 0;
                        sp1F4 = 0;
                        sp1F8 = 3.4028235e38f;
                        sp1FC = 0;
                        sp200 = 0;
                        sp204 = -1;
                        sp208 = 0;
                        temp_f0_266 = sp1A8 + sp148;
                        sp68 = temp_f0_266;
                        sp98 = 0.0f;
                        sp158 = temp_f0_266;
                        sp70 = (f32) sp1B0 + (f32) sp150;
                        sp160 = (f64) sp70;
                        spA0 = 0.0f;
                        sp9C = 200.0f;
                        sp170 = (f64) spA0;
                        sp168 = (f64) sp98;
                        temp_f0_285 = sp1A8 + sp168;
                        sp88 = temp_f0_285;
                        sp178 = temp_f0_285;
                        sp90 = (f32) sp1B0 + (f32) sp170;
                        sp180 = (f64) sp90;
                        if (MKCollision_RayCollide(*((MKVector3 *) &sp178), *((MKVector3 *) &sp158), (MKCollisionResult *) &sp1B8, (MKCollisionMode) 4, 0x0C000000) != 0) {
                            sp198 = (f64) sp1C8;
                            sp1A0 = (f64) sp1D0;
                        }
                        sp138.GetRandPos();
                        sp38 = 0.0f;
                        sp3C = -200.0f;
                        sp40 = 0.0f;
                        sp188 = sp138;
                        spF8 = (f64) sp38;
                        sp190 = sp140;
                        sp100 = (f64) sp40;
                        sp28 = sp188 + spF8;
                        sp60 = 0.0f;
                        sp58 = 0.0f;
                        sp5C = 200.0f;
                        sp30 = (f32) sp190 + (f32) sp100;
                        sp118 = (f64) sp58;
                        sp108 = sp28;
                        sp110 = (f64) sp30;
                        sp120 = (f64) sp60;
                        temp_f0_344 = sp188 + sp118;
                        sp48 = temp_f0_344;
                        sp128 = temp_f0_344;
                        sp50 = (f32) sp190 + (f32) sp120;
                        sp130 = (f64) sp50;
                        if (MKCollision_RayCollide(*((MKVector3 *) &sp128), *((MKVector3 *) &sp108), (MKCollisionResult *) &sp1B8, (MKCollisionMode) 4, 0x0C000000) != 0) {
                            sp188 = (f64) sp1B8;
                            sp190 = (f64) sp1C0;
                        }
                        temp_f0_369 = sp188 - *(temp_r30_141 + 0x30);
                        sp18 = temp_f0_369;
                        spD8 = temp_f0_369;
                        sp20 = (f32) sp190 - (f32) temp_r30_141->unk38;
                        spE0 = (f64) sp20;
                        Normalise(spE8);
                        M2C_FIELD(temp_r30_141, f64 *, 0x40) = M2C_BITWISE(f64, spE8);
                        M2C_FIELD(temp_r30_141, f64 *, 0x48) = (f64) spE8.unk8;
                        KDMath_BuildMatrixFromFwd(temp_r30_141, *(temp_r30_141 + 0x40), (MKVector3 *) &sp198);
                    }
                }
            }
        } else {
            temp_f31_392 = gUpdateTimeDelta;
            spB8.operator*(200.0f);
            temp_f0_399 = spB8 * (f64) temp_f31_392;
            sp8 = temp_f0_399;
            spC8 = temp_f0_399;
            sp10 = spB8.unk8 * temp_f31_392;
            spD0 = (f64) sp10;
            temp_r30_141->Translate(temp_r30_141, *((MKVector3 *) &spC8));
            M2C_FIELD(temp_r30_141, f32 *, 0x54) = (f32) ((M2C_FIELD(temp_r30_141, f32 *, 0x58) * gUpdateTimeDelta) + M2C_FIELD(temp_r30_141, f32 *, 0x54));
            if (M2C_FIELD(temp_r30_141, f32 *, 0x54) >= 1.0f) {
                M2C_FIELD(temp_r30_141, f32 *, 0x64) = (f32) (5.0f * MKRand_Float(&gViewSeed, 0.5f, 1.0f));
                M2C_FIELD(temp_r30_141, s32 *, 0x60) = MKRand_Int(&gViewSeed, 0, 1);
                temp_r27_433 = M2C_FIELD(temp_r30_141, s32 *, 0x60);
                M2C_FIELD(temp_r30_141, void **, 0x50) = (void *) *(checked_cast<SwampFlickerDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + ((temp_r27_433 * 4) + 0x70));
                M2C_FIELD(temp_r30_141, f32 *, 0x58) = (f32) (30.0f / (30.0f * ((f32) M2C_FIELD(M2C_FIELD(temp_r30_141, void **, 0x50), s16 *, 4) / 30.0f)));
                M2C_FIELD(temp_r30_141, f32 *, 0x54) = 0.0f;
            }
        }
        var_r31_135 += 1;
        var_r28_136 += 0x70;
        goto loop_16;
    }
}
#endif

#if 0 // DRAFT: illegal type
void SwampFlicker::LoadDone() {
    s8 sp190;
    s32 sp18C;
    s32 sp188;
    Volume sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    MKVector3 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    MKHeap *temp_r3_503;
    Matrix *temp_r30_536;
    f32 temp_f1_672;
    f32 var_f3_746;
    f32 var_f4_679;
    f64 temp_f0_628;
    f64 temp_f1_685;
    f64 temp_f1_691;
    f64 temp_f1_695;
    f64 temp_f5_569;
    s32 temp_r26_539;
    s32 temp_r27_502;
    s32 temp_r3_714;
    s32 var_r0_724;
    s32 var_r28_519;
    s32 var_r31_517;
    void *var_r3_510;

    Critters::LoadDone();
    temp_r27_502 = this->unk90 * 0x70;
    temp_r3_503 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_503 != NULL) {
        var_r3_510 = ((MKHeap *) (temp_r3_503->Current()))->Alloc(temp_r27_502, NULL, 0);
    } else {
        var_r3_510 = malloc(temp_r27_502);
    }
    this->unk170 = var_r3_510;
    var_r31_517 = 0;
    var_r28_519 = 0;
loop_27:
    if (var_r31_517 < (s32) this->unk90) {
        temp_r30_536 = this->unk170 + var_r28_519;
        M2C_FIELD(temp_r30_536, s32 *, 0x60) = MKRand_Int(&gViewSeed, 0, 1);
        temp_r26_539 = M2C_FIELD(temp_r30_536, s32 *, 0x60);
        M2C_FIELD(temp_r30_536, void **, 0x50) = (void *) *(checked_cast<SwampFlickerDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + ((temp_r26_539 * 4) + 0x70));
        M2C_FIELD(temp_r30_536, f32 *, 0x58) = (f32) (30.0f / (30.0f * ((f32) M2C_FIELD(M2C_FIELD(temp_r30_536, void **, 0x50), s16 *, 4) / 30.0f)));
        M2C_FIELD(temp_r30_536, f32 *, 0x54) = 0.0f;
        M2C_FIELD(temp_r30_536, f32 *, 0x64) = (f32) (5.0f * MKRand_Float(&gViewSeed, 0.5f, 1.0f));
        sp100.GetRandPos();
        sp50 = 0.0f;
        temp_f5_569 = M2C_BITWISE(f64, sp100);
        sp54 = -200.0f;
        sp88 = 0.0f;
        sp58 = 0.0f;
        sp80 = 0.0f;
        sp84 = 1.0f;
        sp100.unk30 = temp_f5_569;
        spC0 = (f64) sp50;
        sp100.unk38 = sp100.unk8;
        sp100.unk20 = (f64) sp80;
        sp100.unk28 = (f64) sp88;
        sp100.unk40 = 0.0f;
        sp100.unk40.unk4 = 0.0f;
        sp100.unk40.unk8 = 0.0f;
        sp100.unk40.unk10 = 0.0f;
        sp100.unk40.unk14 = 0.0f;
        sp100.unk40.unk18 = 0.0f;
        sp100.unk40.unk20 = 0.0f;
        sp100.unk40.unk24 = 0.0f;
        sp100.unk40.unk28 = 0.0f;
        sp100.unk40.unk2C = 1.0f;
        sp100.unk40.unk30 = 0.0f;
        sp100.unk40.unk34 = 0.0f;
        sp100.unk40.unk38 = 0;
        unksp17A = 0;
        unksp17B = 0;
        sp100.unk40.unk3C = 0.0f;
        sp100.unk80 = 3.4028235e38f;
        sp100.unk84 = 0.0f;
        sp188 = 0;
        sp18C = -1;
        sp190 = 0;
        spC8 = (f64) sp58;
        sp40 = temp_f5_569 + spC0;
        sp78 = 0.0f;
        sp70 = 0.0f;
        sp74 = 200.0f;
        sp48 = (f32) sp100.unk38 + (f32) spC8;
        spE0 = (f64) sp70;
        spD0 = sp40;
        spD8 = (f64) sp48;
        spE8 = (f64) sp78;
        temp_f0_628 = temp_f5_569 + spE0;
        sp60 = temp_f0_628;
        spF0 = temp_f0_628;
        sp68 = (f32) sp100.unk38 + (f32) spE8;
        spF8 = (f64) sp68;
        if (MKCollision_RayCollide(*((MKVector3 *) &spF0), *((MKVector3 *) &spD0), (MKCollisionResult *) &sp100.unk40, (MKCollisionMode) 4, 0x0C000000) != 0) {
            sp100.unk30 = M2C_BITWISE(f64, sp100.unk40);
            sp100.unk38 = (f64) sp100.unk40.unk8;
            sp100.unk20 = (f64) sp100.unk40.unk10;
            sp100.unk28 = (f64) sp100.unk40.unk18;
        }
        sp38 = -1.0f;
        sp28 = 1.0f;
        sp30 = -1.0f;
        sp34 = 0.0f;
        sp20 = 1.0f;
        sp24 = 0.0f;
        spA0 = (f64) sp30;
        spA8 = (f64) sp38;
        sp90 = (f64) sp20;
        sp98 = (f64) sp28;
        KDRand_Vector(spB0, *((MKVector3 *) &spA0));
        temp_f1_672 = M2C_BITWISE(f32, spB0);
        var_f4_679 = (spB0.unk8 * spB0.unk8) + ((temp_f1_672 * temp_f1_672) + (spB0.unk4 * spB0.unk4));
        if (var_f4_679 > 1e-12f) {
            if (var_f4_679 > 0.0f) {
                temp_f1_685 = __frsqrte(var_f4_679);
                temp_f1_691 = 0.5 * temp_f1_685 * -(((f64) var_f4_679 * (temp_f1_685 * temp_f1_685)) - 3.0);
                temp_f1_695 = 0.5 * temp_f1_691 * -(((f64) var_f4_679 * (temp_f1_691 * temp_f1_691)) - 3.0);
                var_f4_679 = (f32) ((f64) var_f4_679 * (0.5 * temp_f1_695 * -(((f64) var_f4_679 * (temp_f1_695 * temp_f1_695)) - 3.0)));
            } else if (var_f4_679 < M2C_BITWISE(f32, 0.0)) {
                var_f4_679 = __float_nan;
            } else {
                sp8 = var_f4_679;
                temp_r3_714 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_714) {              /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_724 = 1;
                    } else {
                        var_r0_724 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_724 = 5;
                    } else {
                        var_r0_724 = 3;
                    }
                    break;
                default:
                    var_r0_724 = 4;
                    break;
                }
                if (var_r0_724 == 1) {
                    var_f4_679 = __float_nan;
                }
            }
            var_f3_746 = 1.0f / var_f4_679;
        } else {
            var_f3_746 = 0.0f;
        }
        sp10 = M2C_BITWISE(f32, spB0) * var_f3_746;
        sp14 = spB0.unk4 * var_f3_746;
        sp18 = spB0.unk8 * var_f3_746;
        sp100.unk10 = (f64) sp10;
        sp100.unk18 = (f64) sp18;
        KDMath_BuildMatrixFromUp(temp_r30_536, *((MKVector3 *) &sp100.unk20), *((MKVector3 *) &sp100.unk10));
        var_r31_517 += 1;
        var_r28_519 += 0x70;
        temp_r30_536->unk30 = (f32) sp100.unk30;
        temp_r30_536->unk34 = unksp134;
        temp_r30_536->unk38 = (f32) sp100.unk38;
        temp_r30_536->unk3C = 1.0f;
        goto loop_27;
    }
}
#endif

void SwampFlicker::Init() {
    Critters::Init();
}

void SwampFlickerDescriptor::Deinit() {
    KDPropDescriptor::Deinit();
}

#if 0 // DRAFT: expression syntax error
void SwampFlickerDescriptor::LoadDone() {
    s8 *temp_r30_843;
    s8 *temp_r30_861;
    s8 *temp_r30_879;
    void *var_r3_853;
    void *var_r3_871;
    void *var_r3_889;

    KDPropDescriptor::LoadDone();
    temp_r30_843 = this->unk34;
    if (temp_r30_843->Exists("idle_01") != 0) {
        var_r3_853 = temp_r30_843->GetAnim("idle_01");
    } else {
        var_r3_853 = NULL;
    }
    this->unk70 = (s32) var_r3_853;
    temp_r30_861 = this->unk34;
    if (temp_r30_861->Exists("idle_02") != 0) {
        var_r3_871 = temp_r30_861->GetAnim("idle_02");
    } else {
        var_r3_871 = NULL;
    }
    this->unk74 = (s32) var_r3_871;
    temp_r30_879 = this->unk34;
    if (temp_r30_879->Exists("bounce") != 0) {
        var_r3_889 = temp_r30_879->GetAnim("bounce");
    } else {
        var_r3_889 = NULL;
    }
    this->unk78 = (s32) var_r3_889;
}
#endif

void SwampFlickerDescriptor::Init() {
    KDPropDescriptor::Init();
}
