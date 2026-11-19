#include "spyro/source/FlowerCritter.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Critters.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/Level.h"
#include "spyro/source/Volume.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDRandom.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(s32);                                  /* extern */
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;

void FlowerCritter::Deinit() {
    void *temp_r31_54;

    temp_r31_54 = this->unk170;
    if (temp_r31_54 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_54, NULL, 0);
        } else {
            free(temp_r31_54);
        }
    }
    this->unk170 = NULL;
    Critters::Deinit();
}

void FlowerCritter::Draw() {
    Matrix sp50;
    M2C_UNK sp4C;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f64 sp10;
    f32 temp_f1_132;
    s32 temp_r0_120;
    s32 var_r29_93;
    s32 var_r31_94;
    void *temp_r28_101;

    var_r29_93 = 0;
    var_r31_94 = 0;
loop_6:
    if (var_r29_93 < (s32) this->unk90) {
        temp_r28_101 = ((u8 *) this->unk170) + var_r31_94;
        this->unk80->SetAnim(M2C_FIELD(temp_r28_101, MKAnim **, 0x50), 0.0f, 0.0f, 0, -1);
        this->unk80->JumpToPos(M2C_FIELD(temp_r28_101, f32 *, 0x54), -1);
        M2C_STRUCT_COPY((s32) &sp4C + 4, (s32) (((u8 *) temp_r28_101) - 4) + 4, 0x40);
        temp_r0_120 = M2C_FIELD(temp_r28_101, s32 *, 0x60);
        if ((temp_r0_120 == 3) || (temp_r0_120 == 4) || (temp_r0_120 == 5)) {
            temp_f1_132 = 300.0f * _table_sinf(M2C_FIELD(temp_r28_101, f32 *, 0x68));
            sp28 = 0.0f;
            sp20 = 0.0f;
            sp24 = temp_f1_132;
            sp38 = (f64) sp28;
            sp30 = (f64) sp20;
            sp10 = sp50.unk30 + sp30;
            sp40 = sp10;
            sp18 = sp50.unk38 + (f32) sp38;
            sp48 = (f64) sp18;
            sp50.unk30 = (f32) sp40;
            sp50.unk34 = (*(f32 *) ((u8 *) &sp40 + 0x4));
            sp50.unk38 = (f32) sp48;
            sp50.unk3C = 1.0f;
        }
        MKModel_SetWorldMatrix(this->unk4, sp50);
        MKModel_Draw(this->unk4, NULL);
        var_r29_93 += 1;
        var_r31_94 += 0x70;
        goto loop_6;
    }
}

#if 0 // DRAFT: illegal explicit conversion from 'FlowerCritterDescriptor' to 'void *'
void *FlowerCritter::Update() {
    s8 sp278;
    s32 sp274;
    s32 sp270;
    s32 sp26C;
    f32 sp268;
    s32 sp264;
    s8 sp263;
    s8 sp262;
    s16 sp260;
    f32 sp25C;
    f32 sp258;
    f32 sp254;
    f32 sp250;
    f32 sp24C;
    f32 sp248;
    f32 sp240;
    f32 sp23C;
    f32 sp238;
    f32 sp230;
    f32 sp22C;
    f32 sp228;
    f64 sp220;
    f64 sp218;
    f64 sp210;
    f64 sp208;
    f64 sp200;
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    MKVector3 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    MKVector3 sp108;
    f64 spF8;
    MKVector3 spE8;
    f64 spE0;
    f64 spD8;
    f32 spD0;
    f32 spCC;
    f32 spC8;
    f32 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB0;
    f64 spA8;
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
    Matrix *temp_r30_197;
    f32 temp_f31_460;
    f32 var_f1_486;
    f64 temp_f0_332;
    f64 temp_f0_351;
    f64 temp_f0_410;
    f64 temp_f0_435;
    f64 temp_f0_467;
    f64 temp_f0_544;
    s32 temp_r0_201;
    s32 temp_r27_226;
    s32 temp_r27_263;
    s32 temp_r27_573;
    s32 var_r28_192;
    s32 var_r31_191;

    var_r31_191 = 0;
    var_r28_192 = 0;
loop_26:
    if (var_r31_191 < (s32) this->unk90) {
        temp_r30_197 = (Matrix *) (((u8 *) this->unk170) + var_r28_192);
        M2C_FIELD(temp_r30_197, f32 *, 0x64) = (f32) (M2C_FIELD(temp_r30_197, f32 *, 0x64) - gUpdateTimeDelta);
        temp_r0_201 = M2C_FIELD(temp_r30_197, s32 *, 0x60);
        if (temp_r0_201 < 3) {
            if (temp_r0_201 < 0) {

            } else {
                M2C_FIELD(temp_r30_197, f32 *, 0x54) = (f32) ((M2C_FIELD(temp_r30_197, f32 *, 0x58) * gUpdateTimeDelta) + M2C_FIELD(temp_r30_197, f32 *, 0x54));
                if (M2C_FIELD(temp_r30_197, f32 *, 0x54) > 1.0f) {
                    M2C_FIELD(temp_r30_197, s32 *, 0x60) = MKRand_Int((int *) &gViewSeed, 0, 2);
                    temp_r27_226 = M2C_FIELD(temp_r30_197, s32 *, 0x60);
                    M2C_FIELD(temp_r30_197, void **, 0x50) = (void *) *(checked_cast<FlowerCritterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + ((temp_r27_226 * 4) + 0x70));
                    M2C_FIELD(temp_r30_197, f32 *, 0x58) = (f32) (30.0f / (30.0f * ((f32) M2C_FIELD(M2C_FIELD(temp_r30_197, void **, 0x50), s16 *, 4) / 30.0f)));
                    M2C_FIELD(temp_r30_197, f32 *, 0x54) = 0.0f;
                } else if (M2C_FIELD(temp_r30_197, f32 *, 0x64) <= 0.0f) {
                    M2C_FIELD(temp_r30_197, f32 *, 0x64) = 4.0f;
                    M2C_FIELD(temp_r30_197, s32 *, 0x60) = MKRand_Int((int *) &gViewSeed, 3, 5);
                    temp_r27_263 = M2C_FIELD(temp_r30_197, s32 *, 0x60);
                    M2C_FIELD(temp_r30_197, void **, 0x50) = (void *) *(checked_cast<FlowerCritterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + ((temp_r27_263 * 4) + 0x70));
                    spD0 = 0.0f;
                    spA0 = 0.0f;
                    sp98 = 0.0f;
                    sp9C = -500.0f;
                    spC8 = 0.0f;
                    spCC = 1.0f;
                    sp198 = (f64) sp98;
                    sp1A0 = (f64) spA0;
                    M2C_FIELD(temp_r30_197, f32 *, 0x58) = (f32) (30.0f / (30.0f * ((f32) M2C_FIELD(M2C_FIELD(temp_r30_197, void **, 0x50), s16 *, 4) / 30.0f)));
                    M2C_FIELD(temp_r30_197, f32 *, 0x54) = 0.0f;
                    sp218 = M2C_FIELD(temp_r30_197, f64 *, 0x30);
                    sp220 = M2C_FIELD(temp_r30_197, f64 *, 0x38);
                    sp208 = (f64) spC8;
                    sp210 = (f64) spD0;
                    sp228 = 0.0f;
                    sp22C = 0.0f;
                    sp230 = 0.0f;
                    sp238 = 0.0f;
                    sp23C = 0.0f;
                    sp240 = 0.0f;
                    sp248 = 0.0f;
                    sp24C = 0.0f;
                    sp250 = 0.0f;
                    sp254 = 1.0f;
                    sp258 = 0.0f;
                    sp25C = 0.0f;
                    sp260 = 0;
                    sp262 = 0;
                    sp263 = 0;
                    sp264 = 0;
                    sp268 = 3.4028235e38f;
                    sp26C = 0;
                    sp270 = 0;
                    sp274 = -1;
                    sp278 = 0;
                    temp_f0_332 = sp218 + sp198;
                    sp88 = temp_f0_332;
                    sp1A8 = temp_f0_332;
                    sp90 = (f32) sp220 + (f32) sp1A0;
                    sp1B0 = (f64) sp90;
                    spC0 = 0.0f;
                    spB8 = 0.0f;
                    spBC = 200.0f;
                    sp1C0 = (f64) spC0;
                    sp1B8 = (f64) spB8;
                    temp_f0_351 = sp218 + sp1B8;
                    spA8 = temp_f0_351;
                    sp1C8 = temp_f0_351;
                    spB0 = (f32) sp220 + (f32) sp1C0;
                    sp1D0 = (f64) spB0;
                    if (MKCollision_RayCollide(*((MKVector3 *) &sp1C8), *((MKVector3 *) &sp1A8), (MKCollisionResult *) &sp228, (MKCollisionMode) 4, 0x0C000000) != 0) {
                        sp208 = (f64) sp238;
                        sp210 = (f64) sp240;
                    }
                    ((Volume *) &sp188)->GetRandPos();
                    sp58 = 0.0f;
                    sp5C = -500.0f;
                    sp60 = 0.0f;
                    sp1F8 = sp188;
                    sp148 = (f64) sp58;
                    sp200 = sp190;
                    sp150 = (f64) sp60;
                    sp48 = sp1F8 + sp148;
                    sp80 = 0.0f;
                    sp78 = 0.0f;
                    sp7C = 200.0f;
                    sp50 = (f32) sp200 + (f32) sp150;
                    sp168 = (f64) sp78;
                    sp158 = sp48;
                    sp160 = (f64) sp50;
                    sp170 = (f64) sp80;
                    temp_f0_410 = sp1F8 + sp168;
                    sp68 = temp_f0_410;
                    sp178 = temp_f0_410;
                    sp70 = (f32) sp200 + (f32) sp170;
                    sp180 = (f64) sp70;
                    if (MKCollision_RayCollide(*((MKVector3 *) &sp178), *((MKVector3 *) &sp158), (MKCollisionResult *) &sp228, (MKCollisionMode) 4, 0x0C000000) != 0) {
                        sp1F8 = (f64) sp228;
                        sp200 = (f64) sp230;
                    }
                    temp_f0_435 = sp1F8 - *(temp_r30_197 + 0x30);
                    sp28 = temp_f0_435;
                    sp128 = temp_f0_435;
                    sp30 = (f32) sp200 - (f32) temp_r30_197->unk38;
                    sp130 = (f64) sp30;
                    Normalise(sp138);
                    M2C_FIELD(temp_r30_197, f64 *, 0x40) = M2C_BITWISE(f64, sp138);
                    M2C_FIELD(temp_r30_197, f64 *, 0x48) = (f64) sp138.unk8;
                    KDMath_BuildMatrixFromFwd(temp_r30_197, *(temp_r30_197 + 0x40), (MKVector3 *) &sp208);
                    M2C_FIELD(temp_r30_197, f32 *, 0x68) = 0.0f;
                }
            }
        } else if (temp_r0_201 < 6) {
            temp_f31_460 = gUpdateTimeDelta;
            sp108.operator*(200.0f);
            temp_f0_467 = sp108 * (f64) temp_f31_460;
            sp18 = temp_f0_467;
            sp118 = temp_f0_467;
            sp20 = sp108.unk8 * temp_f31_460;
            sp120 = (f64) sp20;
            temp_r30_197->Translate(temp_r30_197, *((MKVector3 *) &sp118));
            M2C_FIELD(temp_r30_197, f32 *, 0x54) = (f32) ((M2C_FIELD(temp_r30_197, f32 *, 0x58) * gUpdateTimeDelta) + M2C_FIELD(temp_r30_197, f32 *, 0x54));
            var_f1_486 = M2C_FIELD(temp_r30_197, f32 *, 0x64);
            if (var_f1_486 < 4.0f) {

            } else {
                var_f1_486 = 4.0f;
            }
            if (var_f1_486 > 0.0f) {

            } else {
                var_f1_486 = 0.0f;
            }
            M2C_FIELD(temp_r30_197, f32 *, 0x68) = (f32) (3.1415927f * -((var_f1_486 * 0.25f) - 1.0f));
            if (M2C_FIELD(temp_r30_197, f32 *, 0x64) <= 0.0f) {
                if ((u8) this->unk174 != 0) {
                    M2C_FIELD(temp_r30_197, f32 *, 0x64) = (f32) (5.0f * MKRand_Float((int *) &gViewSeed, 0.5f, 1.0f));
                    M2C_FIELD(temp_r30_197, s32 *, 0x60) = MKRand_Int((int *) &gViewSeed, 0, 2);
                } else {
                    sp40 = 0.0f;
                    sp38 = 0.0f;
                    sp3C = 1.0f;
                    sp1F0 = (f64) sp40;
                    sp1E8 = (f64) sp38;
                    ((Volume *) &spF8)->GetRandPos();
                    sp1D8 = spF8;
                    sp1E0 = sp100;
                    temp_f0_544 = spF8 - M2C_FIELD(temp_r30_197, f64 *, 0x30);
                    sp8 = temp_f0_544;
                    spD8 = temp_f0_544;
                    sp10 = (f32) sp1E0 - temp_r30_197->unk38;
                    spE0 = (f64) sp10;
                    Normalise(spE8);
                    M2C_FIELD(temp_r30_197, f64 *, 0x40) = M2C_BITWISE(f64, spE8);
                    M2C_FIELD(temp_r30_197, f64 *, 0x48) = (f64) spE8.unk8;
                    KDMath_BuildMatrixFromUp(temp_r30_197, *((MKVector3 *) &sp1E8), *(MKVector3 *) (temp_r30_197 + 0x40));
                    M2C_FIELD(temp_r30_197, s32 *, 0x60) = MKRand_Int((int *) &gViewSeed, 3, 5);
                    M2C_FIELD(temp_r30_197, f32 *, 0x64) = 4.0f;
                }
                temp_r27_573 = M2C_FIELD(temp_r30_197, s32 *, 0x60);
                M2C_FIELD(temp_r30_197, void **, 0x50) = (void *) *(checked_cast<FlowerCritterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + ((temp_r27_573 * 4) + 0x70));
                M2C_FIELD(temp_r30_197, f32 *, 0x58) = (f32) (30.0f / (30.0f * ((f32) M2C_FIELD(M2C_FIELD(temp_r30_197, void **, 0x50), s16 *, 4) / 30.0f)));
                M2C_FIELD(temp_r30_197, f32 *, 0x54) = 0.0f;
            }
        }
        var_r31_191 += 1;
        var_r28_192 += 0x70;
        goto loop_26;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'FlowerCritterDescriptor' to 'void *'
s32 FlowerCritter::LoadDone() {
    s8 sp1C8;
    s32 sp1C4;
    s32 sp1C0;
    Volume sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    MKVector3 spE8;
    MKVector3 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spA8;
    MKVector3 sp98;
    f64 sp90;
    f64 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f64 sp8;
    Matrix *temp_r26_657;
    f64 temp_f0_771;
    f64 temp_f0_836;
    s32 temp_r27_681;
    s32 temp_r28_630;
    s32 var_r29_647;
    s32 var_r31_645;
    void *var_r3_638;

    Critters::LoadDone();
    temp_r28_630 = this->unk90 * 0x70;
    if (MKHeap::Current() != NULL) {
        var_r3_638 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r28_630, NULL, 0);
    } else {
        var_r3_638 = malloc(temp_r28_630);
    }
    this->unk170 = var_r3_638;
    var_r31_645 = 0;
    var_r29_647 = 0;
loop_13:
    if (var_r31_645 < (s32) this->unk90) {
        temp_r26_657 = (Matrix *) (((u8 *) this->unk170) + var_r29_647);
        if ((u8) this->unk174 != 0) {
            M2C_FIELD(temp_r26_657, s32 *, 0x60) = MKRand_Int((int *) &gViewSeed, 0, 2);
            M2C_FIELD(temp_r26_657, f32 *, 0x64) = (f32) (5.0f * MKRand_Float((int *) &gViewSeed, 0.5f, 1.0f));
        } else {
            M2C_FIELD(temp_r26_657, s32 *, 0x60) = MKRand_Int((int *) &gViewSeed, 3, 5);
            M2C_FIELD(temp_r26_657, f32 *, 0x64) = 4.0f;
        }
        temp_r27_681 = M2C_FIELD(temp_r26_657, s32 *, 0x60);
        M2C_FIELD(temp_r26_657, void **, 0x50) = (void *) *(checked_cast<FlowerCritterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + ((temp_r27_681 * 4) + 0x70));
        M2C_FIELD(temp_r26_657, f32 *, 0x58) = (f32) (30.0f / (30.0f * ((f32) M2C_FIELD(M2C_FIELD(temp_r26_657, void **, 0x50), s16 *, 4) / 30.0f)));
        M2C_FIELD(temp_r26_657, f32 *, 0x54) = 0.0f;
        M2C_FIELD(temp_r26_657, f32 *, 0x68) = 0.0f;
        sp138.GetRandPos();
        sp80 = 0.0f;
        sp78 = 0.0f;
        sp7C = 1.0f;
        sp138.unk28 = (f64) sp80;
        sp138.unk20 = (f64) sp78;
        sp138.unk30 = M2C_BITWISE(f64, sp138);
        sp138.unk38 = sp138.unk8;
        if ((u8) this->unk174 != 0) {
            sp50 = 0.0f;
            sp48 = 0.0f;
            sp4C = -500.0f;
            sp138.unk40 = 0.0f;
            spF8 = (f64) sp48;
            sp138.unk40.unk4 = 0.0f;
            sp138.unk40.unk8 = 0.0f;
            sp138.unk40.unk10 = 0.0f;
            sp138.unk40.unk14 = 0.0f;
            sp138.unk40.unk18 = 0.0f;
            sp138.unk40.unk20 = 0.0f;
            sp138.unk40.unk24 = 0.0f;
            sp138.unk40.unk28 = 0.0f;
            sp138.unk40.unk2C = 1.0f;
            sp138.unk40.unk30 = 0.0f;
            sp138.unk40.unk34 = 0.0f;
            sp138.unk40.unk38 = 0;
            (*(u8 *) ((u8 *) &sp138 + 0x7a)) = 0;
            (*(u8 *) ((u8 *) &sp138 + 0x7b)) = 0;
            sp138.unk40.unk3C = 0.0f;
            sp138.unk80 = 3.4028235e38f;
            sp138.unk84 = 0.0f;
            sp1C0 = 0;
            sp1C4 = -1;
            sp1C8 = 0;
            sp100 = (f64) sp50;
            sp38 = sp138.unk30 + spF8;
            sp70 = 0.0f;
            sp68 = 0.0f;
            sp6C = 200.0f;
            sp40 = (f32) sp138.unk38 + (f32) sp100;
            sp118 = (f64) sp68;
            sp108 = sp38;
            sp110 = (f64) sp40;
            sp120 = (f64) sp70;
            temp_f0_771 = sp138.unk30 + sp118;
            sp58 = temp_f0_771;
            sp128 = temp_f0_771;
            sp60 = (f32) sp138.unk38 + (f32) sp120;
            sp130 = (f64) sp60;
            if (MKCollision_RayCollide(*((MKVector3 *) &sp128), *((MKVector3 *) &sp108), (MKCollisionResult *) &sp138.unk40, (MKCollisionMode) 4, 0x0C000000) != 0) {
                sp138.unk30 = M2C_BITWISE(f64, sp138.unk40);
                sp138.unk38 = (f64) sp138.unk40.unk8;
                sp138.unk20 = (f64) sp138.unk40.unk10;
                sp138.unk28 = (f64) sp138.unk40.unk18;
            }
            sp20 = 1.0f;
            sp30 = -1.0f;
            sp18 = 1.0f;
            sp1C = 0.0f;
            sp28 = -1.0f;
            sp2C = 0.0f;
            spB8 = (f64) sp18;
            spC0 = (f64) sp20;
            spC8 = (f64) sp28;
            spD0 = (f64) sp30;
            KDRand_Vector(spD8, *((MKVector3 *) &spC8));
            Normalise(spE8);
            M2C_FIELD(temp_r26_657, f64 *, 0x40) = M2C_BITWISE(f64, spE8);
            M2C_FIELD(temp_r26_657, f64 *, 0x48) = (f64) spE8.unk8;
        } else {
            ((Volume *) &spA8)->GetRandPos();
            sp138.unk10 = spA8;
            sp138.unk18 = spB0;
            temp_f0_836 = spA8 - sp138.unk30;
            sp8 = temp_f0_836;
            sp88 = temp_f0_836;
            sp10 = (f32) sp138.unk18 - (f32) sp138.unk38;
            sp90 = (f64) sp10;
            Normalise(sp98);
            M2C_FIELD(temp_r26_657, f64 *, 0x40) = M2C_BITWISE(f64, sp98);
            M2C_FIELD(temp_r26_657, f64 *, 0x48) = (f64) sp98.unk8;
        }
        KDMath_BuildMatrixFromUp(temp_r26_657, *((MKVector3 *) &sp138.unk20), *(temp_r26_657 + 0x40));
        var_r31_645 += 1;
        var_r29_647 += 0x70;
        temp_r26_657->unk30 = (f32) sp138.unk30;
        temp_r26_657->unk34 = (*(f32 *) ((u8 *) &sp138 + 0x34));
        temp_r26_657->unk38 = (f32) sp138.unk38;
        temp_r26_657->unk3C = 1.0f;
        goto loop_13;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to 'bool *'
s32 FlowerCritter::LoadLine(MKIniLine *arg0) {
    s32 var_r31_895;

    var_r31_895 = 0;
    if ((Critters::LoadLine(arg0) != 0) || (arg0->LoadBool("CanLand", &this->unk174, 0) != 0)) {
        var_r31_895 = 1;
    }
    return var_r31_895;
}
#endif

void FlowerCritter::Init() {
    Critters::Init();
    this->unk174 = 0;
}

void FlowerCritterDescriptor::Deinit() {
    KDPropDescriptor::Deinit();
}

void FlowerCritterDescriptor::LoadDone() {
    s8 *temp_r30_1014;
    s8 *temp_r30_1032;
    s8 *temp_r30_1050;
    s8 *temp_r30_958;
    s8 *temp_r30_978;
    s8 *temp_r30_996;
    void *var_r3_1006;
    void *var_r3_1024;
    void *var_r3_1042;
    void *var_r3_1060;
    void *var_r3_970;
    void *var_r3_988;

    KDPropDescriptor::LoadDone();
    temp_r30_958 = this->unk34;
    if (((MKAnimScript *) temp_r30_958)->Exists("idle_01") != 0) {
        var_r3_970 = ((MKAnimScript *) temp_r30_958)->GetAnim("idle_01");
    } else {
        var_r3_970 = NULL;
    }
    this->unk70 = (s32) var_r3_970;
    temp_r30_978 = this->unk34;
    if (((MKAnimScript *) temp_r30_978)->Exists("idle_02") != 0) {
        var_r3_988 = ((MKAnimScript *) temp_r30_978)->GetAnim("idle_02");
    } else {
        var_r3_988 = NULL;
    }
    this->unk74 = (s32) var_r3_988;
    temp_r30_996 = this->unk34;
    if (((MKAnimScript *) temp_r30_996)->Exists("idle_02") != 0) {
        var_r3_1006 = ((MKAnimScript *) temp_r30_996)->GetAnim("idle_02");
    } else {
        var_r3_1006 = NULL;
    }
    this->unk78 = (s32) var_r3_1006;
    temp_r30_1014 = this->unk34;
    if (((MKAnimScript *) temp_r30_1014)->Exists("fly_01") != 0) {
        var_r3_1024 = ((MKAnimScript *) temp_r30_1014)->GetAnim("fly_01");
    } else {
        var_r3_1024 = NULL;
    }
    this->unk7C = (s32) var_r3_1024;
    temp_r30_1032 = this->unk34;
    if (((MKAnimScript *) temp_r30_1032)->Exists("fly_02") != 0) {
        var_r3_1042 = ((MKAnimScript *) temp_r30_1032)->GetAnim("fly_02");
    } else {
        var_r3_1042 = NULL;
    }
    this->unk80 = (s32) var_r3_1042;
    temp_r30_1050 = this->unk34;
    if (((MKAnimScript *) temp_r30_1050)->Exists("fly_03") != 0) {
        var_r3_1060 = ((MKAnimScript *) temp_r30_1050)->GetAnim("fly_03");
    } else {
        var_r3_1060 = NULL;
    }
    this->unk84 = (s32) var_r3_1060;
}

void FlowerCritterDescriptor::Init() {
    KDPropDescriptor::Init();
}
