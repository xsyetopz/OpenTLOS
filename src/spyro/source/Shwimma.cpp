#include "spyro/source/Shwimma.h"
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
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(s32);                                  /* extern */
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;

#if 0 // DRAFT: illegal use of non-static member
void ShwimmaCritter::Deinit() {
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

void ShwimmaCritter::Draw() {
    Matrix sp10;
    M2C_UNK spC;
    s32 var_r30_92;
    s32 var_r31_93;
    void *temp_r29_97;

    var_r30_92 = 0;
    var_r31_93 = 0;
loop_4:
    if (var_r30_92 < (s32) this->unk90) {
        temp_r29_97 = ((u8 *) this->unk170) + var_r31_93;
        if ((s32) M2C_FIELD(temp_r29_97, s32 *, 0x60) != 0) {
            this->unk80->SetAnim(M2C_FIELD(temp_r29_97, MKAnim **, 0x50), 0.0f, 0.0f, 0, -1);
            this->unk80->JumpToPos(M2C_FIELD(temp_r29_97, f32 *, 0x54), -1);
            M2C_STRUCT_COPY((s32) &spC + 4, (s32) (((u8 *) temp_r29_97) - 4) + 4, 0x40);
            MKModel_SetWorldMatrix(this->unk4, sp10);
            MKModel_Draw(this->unk4, NULL);
        }
        var_r30_92 += 1;
        var_r31_93 += 0x90;
        goto loop_4;
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to
void ShwimmaCritter::Update() {
    s8 sp1B8;
    s32 sp1B4;
    s32 sp1B0;
    Volume sp128;
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
    f64 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    MKProp *temp_r0_174;
    MKProp *temp_r0_316;
    MKProp *temp_r27_352;
    MKProp *temp_r27_491;
    MKProp *temp_r27_529;
    Shwimma *temp_r30_165;
    f32 temp_f0_516;
    f32 temp_f1_377;
    f32 temp_f29_440;
    f32 temp_f31_386;
    f64 temp_f0_254;
    f64 temp_f0_388;
    f64 temp_f0_398;
    f64 temp_f0_410;
    f64 temp_f0_442;
    f64 temp_f0_452;
    f64 temp_f0_464;
    s32 var_r28_160;
    s32 var_r31_159;

    var_r31_159 = 0;
    var_r28_160 = 0;
loop_38:
    if (var_r31_159 < (s32) this->unk90) {
        temp_r30_165 = ((u8 *) this->unk170) + var_r28_160;
        temp_r30_165->unk30.unk34 -= gUpdateTimeDelta;
        temp_r30_165->unk30.unk24 += temp_r30_165->unk30.unk28 * gUpdateTimeDelta;
        temp_r0_174 = temp_r30_165->unk30.unk30;
        if (temp_r0_174 != (MKProp *)5) {
            if (temp_r0_174 < 5) {
                if (temp_r0_174 != NULL) {
                    if (temp_r0_174 >= 0) {
                        if (temp_r0_174 < 3) {
                            temp_f1_377 = temp_r30_165->unk30.unk24;
                            if (temp_f1_377 > 1.0f) {
                                temp_r30_165->unk30.unk24 = temp_f1_377 - 1.0f;
                            }
                            temp_f31_386 = M2C_FIELD(temp_r30_165, f32 *, 0x88);
                            temp_f0_388 = M2C_FIELD(temp_r30_165, f64 *, 0x78) * (f64) temp_f31_386;
                            sp58 = temp_f0_388;
                            spC8 = temp_f0_388;
                            sp60 = M2C_FIELD(temp_r30_165, f32 *, 0x80) * temp_f31_386;
                            spD0 = (f64) sp60;
                            temp_f0_398 = temp_f0_388 * (f64) gUpdateTimeDelta;
                            sp48 = temp_f0_398;
                            spD8 = temp_f0_398;
                            sp50 = (f32) spD0 * gUpdateTimeDelta;
                            spE0 = (f64) sp50;
                            temp_f0_410 = *(temp_r30_165 + 0x30) + temp_f0_398;
                            sp38 = temp_f0_410;
                            sp128.unk20 = temp_f0_410;
                            sp40 = temp_r30_165->unk30.unk8 + (f32) spE0;
                            temp_r30_165->unk30.unk0 = (f32) sp128.unk20;
                            sp128.unk28 = (f64) sp40;
                            temp_r30_165->unk30.unk4 = (*(f32 *) ((u8 *) &sp128 + 0x24));
                            temp_r30_165->unk30.unk8 = (f32) sp128.unk28;
                            temp_r30_165->unk30.unkC = 1.0f;
                            if (temp_r30_165->unk30.unk34 <= 0.0f) {
                                SetAlertState(temp_r30_165);
                            }
                        } else {
                            temp_f29_440 = M2C_FIELD(temp_r30_165, f32 *, 0x88);
                            temp_f0_442 = M2C_FIELD(temp_r30_165, f64 *, 0x78) * (f64) temp_f29_440;
                            sp28 = temp_f0_442;
                            spA8 = temp_f0_442;
                            sp30 = M2C_FIELD(temp_r30_165, f32 *, 0x80) * temp_f29_440;
                            spB0 = (f64) sp30;
                            temp_f0_452 = temp_f0_442 * (f64) gUpdateTimeDelta;
                            sp18 = temp_f0_452;
                            spB8 = temp_f0_452;
                            sp20 = (f32) spB0 * gUpdateTimeDelta;
                            spC0 = (f64) sp20;
                            temp_f0_464 = (f64) M2C_FIELD(temp_r30_165, f32 *, 0x30) + temp_f0_452;
                            sp8 = temp_f0_464;
                            sp128.unk10 = temp_f0_464;
                            sp10 = M2C_BITWISE(f32, temp_r30_165->unk30.unk8) + (f32) spC0;
                            temp_r30_165->unk30.unk0 = (f32) sp128.unk10;
                            sp128.unk18 = (f64) sp10;
                            temp_r30_165->unk30.unk4 = (*(f32 *) ((u8 *) &sp128 + 0x14));
                            temp_r30_165->unk30.unk8 = (f32) sp128.unk18;
                            temp_r30_165->unk30.unkC = 1.0f;
                            if ((MKProp *) temp_r30_165->unk30.unk30 == (MKProp *)3) {
                                if (temp_r30_165->unk30.unk24 >= 1.0f) {
                                    temp_r30_165->unk30.unk30 = (MKProp *)4;
                                    temp_r27_491 = temp_r30_165->unk30.unk30;
                                    temp_r30_165->unk30.unk20 = *(checked_cast<ShwimmaCritterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (((s32) temp_r27_491 * 4) + 0x70));
                                    temp_r30_165->unk30.unk28 = 30.0f / (30.0f * ((f32) M2C_FIELD(temp_r30_165->unk30.unk20, s16 *, 4) / 30.0f));
                                    temp_r30_165->unk30.unk24 = 0.0f;
                                }
                            } else {
                                temp_f0_516 = temp_r30_165->unk30.unk24;
                                if (temp_f0_516 > 1.0f) {
                                    temp_r30_165->unk30.unk24 = temp_f0_516 - 1.0f;
                                }
                                if (M2C_BITWISE(f32, temp_r30_165->unk30.unk34) <= 0.0f) {
                                    temp_r30_165->unk30.unk30 = (MKProp *)5;
                                    temp_r27_529 = temp_r30_165->unk30.unk30;
                                    temp_r30_165->unk30.unk20 = *(checked_cast<ShwimmaCritterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (((s32) temp_r27_529 * 4) + 0x70));
                                    temp_r30_165->unk30.unk28 = 30.0f / (30.0f * ((f32) M2C_FIELD(temp_r30_165->unk30.unk20, s16 *, 4) / 30.0f));
                                    temp_r30_165->unk30.unk24 = 0.0f;
                                }
                            }
                        }
                    }
                } else {
                    sp128.GetRandPos();
                    sp80 = 0.0f;
                    sp128.unk30 = M2C_BITWISE(f64, sp128);
                    sp78 = 0.0f;
                    sp7C = -500.0f;
                    (*(f32 *) ((u8 *) &sp128 + 0x34)) = M2C_FIELD(this->unk8, f32 *, 0x34);
                    spE8 = (f64) sp78;
                    sp128.unk38 = sp128.unk8;
                    sp128.unk40 = 0.0f;
                    sp128.unk40.unk4 = 0.0f;
                    sp128.unk40.unk8 = 0.0f;
                    sp128.unk40.unk10 = 0.0f;
                    sp128.unk40.unk14 = 0.0f;
                    sp128.unk40.unk18 = 0.0f;
                    sp128.unk40.unk20 = 0.0f;
                    sp128.unk40.unk24 = 0.0f;
                    sp128.unk40.unk28 = 0.0f;
                    sp128.unk40.unk2C = 1.0f;
                    sp128.unk40.unk30 = 0.0f;
                    sp128.unk40.unk34 = 0.0f;
                    sp128.unk40.unk38 = 0;
                    (*(u8 *) ((u8 *) &sp128 + 0x7a)) = 0;
                    (*(u8 *) ((u8 *) &sp128 + 0x7b)) = 0;
                    sp128.unk40.unk3C = 0.0f;
                    sp128.unk80 = 3.4028235e38f;
                    sp128.unk84 = 0.0f;
                    sp1B0 = 0;
                    sp1B4 = -1;
                    sp1B8 = 0;
                    spF0 = (f64) sp80;
                    sp68 = sp128.unk30 + spE8;
                    spA0 = 0.0f;
                    sp98 = 0.0f;
                    sp9C = 200.0f;
                    sp70 = (f32) sp128.unk38 + (f32) spF0;
                    sp108 = (f64) sp98;
                    spF8 = sp68;
                    sp100 = (f64) sp70;
                    sp110 = (f64) spA0;
                    temp_f0_254 = sp128.unk30 + sp108;
                    sp88 = temp_f0_254;
                    sp118 = temp_f0_254;
                    sp90 = (f32) sp128.unk38 + (f32) sp110;
                    sp120 = (f64) sp90;
                    if (MKCollision_RayCollide(*((MKVector3 *) &sp118), *((MKVector3 *) &spF8), (MKCollisionResult *) &sp128.unk40, (MKCollisionMode) 4, 0x0C000000) != 0) {
                        sp128.unk30 = M2C_BITWISE(f64, sp128.unk40);
                        sp128.unk38 = (f64) sp128.unk40.unk8;
                    }
                    M2C_STRUCT_COPY(temp_r30_165, &Matrix::identity, 0x40);
                    temp_r30_165->unk30.unk0 = (f32) sp128.unk30;
                    temp_r30_165->unk30.unk4 = (*(f32 *) ((u8 *) &sp128 + 0x34));
                    temp_r30_165->unk30.unk8 = (f32) sp128.unk38;
                    temp_r30_165->unk30.unkC = 1.0f;
                    SetAlertState(temp_r30_165);
                }
            } else if (temp_r0_174 < 0xB) {
                if (temp_r30_165->unk30.unk24 >= 1.0f) {
                    if (M2C_BITWISE(f32, temp_r30_165->unk30.unk34) < 0.0f) {
                        temp_r30_165->unk30.unk30 = MKRand_Int(&gViewSeed, 0, 3) + 1;
                        temp_r0_316 = temp_r30_165->unk30.unk30;
                        switch (temp_r0_316) {      /* irregular */
                        case 1:
                            FindNewMoveParameters(temp_r30_165, 200.0f);
                            /* fallthrough */
                        case 2:
                            FindNewMoveParameters(temp_r30_165, 350.0f);
                            /* fallthrough */
                        case 3:
                            FindNewMoveParameters(temp_r30_165, 450.0f);
                            temp_r30_165->unk30.unk34 = 4.0f;
                            break;
                        }
                    } else {
                        temp_r30_165->unk30.unk30 = MKRand_Int(&gViewSeed, 0, 5) + 6;
                        temp_r27_352 = temp_r30_165->unk30.unk30;
                        temp_r30_165->unk30.unk20 = *(checked_cast<ShwimmaCritterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (((s32) temp_r27_352 * 4) + 0x70));
                        temp_r30_165->unk30.unk28 = 30.0f / (30.0f * ((f32) M2C_FIELD(temp_r30_165->unk30.unk20, s16 *, 4) / 30.0f));
                        temp_r30_165->unk30.unk24 = 0.0f;
                    }
                }
            }
        } else if (temp_r30_165->unk30.unk24 >= 1.0f) {
            SetAlertState(temp_r30_165);
        }
        var_r31_159 += 1;
        var_r28_160 += 0x90;
        goto loop_38;
    }
}
#endif

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void ShwimmaCritter::SetAlertState(Shwimma *arg0) {
    MKProp *temp_r31_606;

    arg0->unk30.unk34 = 4.0f * MKRand_Float(&gViewSeed, 0.75f, 1.0f);
    arg0->unk30.unk30 = MKRand_Int(&gViewSeed, 0, 5) + 6;
    temp_r31_606 = arg0->unk30.unk30;
    arg0->unk30.unk20 = M2C_FIELD((checked_cast<ShwimmaCritterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + ((s32) temp_r31_606 * 4)), f32 *, 0x70);
    arg0->unk30.unk28 = 30.0f / (30.0f * ((f32) M2C_FIELD(arg0->unk30.unk20, s16 *, 4) / 30.0f));
    arg0->unk30.unk24 = 0.0f;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'float' to
void ShwimmaCritter::FindNewMoveParameters(Shwimma *arg0, float arg1) {
    s8 sp230;
    s32 sp22C;
    s32 sp228;
    s32 sp224;
    f32 sp220;
    s32 sp21C;
    s8 sp21B;
    s8 sp21A;
    s16 sp218;
    f32 sp214;
    f32 sp210;
    f32 sp20C;
    f32 sp208;
    f32 sp204;
    f32 sp200;
    f32 sp1F8;
    f32 sp1F4;
    f32 sp1F0;
    f32 sp1E8;
    f32 sp1E4;
    f32 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
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
    f64 sp140;
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
    f32 spD8;
    f32 spD4;
    f32 spD0;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spB8;
    f64 spB0;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp98;
    f64 sp90;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp78;
    f64 sp70;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp58;
    f64 sp50;
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
    f32 spC;
    f32 sp8;
    MKProp *temp_r30_658;
    f32 temp_f1_1000;
    f32 temp_f2_999;
    f32 temp_f3_1001;
    f32 var_f0_932;
    f32 var_f3_918;
    f32 var_f4_851;
    f32 var_f5_1006;
    f64 temp_f0_747;
    f64 temp_f0_810;
    f64 temp_f1_1011;
    f64 temp_f1_1017;
    f64 temp_f1_1021;
    f64 temp_f1_857;
    f64 temp_f1_863;
    f64 temp_f1_867;
    s32 temp_r3_1040;
    s32 temp_r3_886;
    s32 var_r0_1050;
    s32 var_r0_896;

    temp_r30_658 = arg0->unk30.unk30;
    arg0->unk30.unk20 = M2C_FIELD((checked_cast<ShwimmaCritterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + ((s32) temp_r30_658 * 4)), f32 *, 0x70);
    spD8 = 0.0f;
    spA8 = 0.0f;
    spA0 = 0.0f;
    spA4 = -500.0f;
    spD0 = 0.0f;
    spD4 = 1.0f;
    sp140 = (f64) spA0;
    sp1C0 = (f64) spD0;
    sp1C8 = (f64) spD8;
    sp148 = (f64) spA8;
    arg0->unk30.unk28 = 30.0f / (30.0f * ((f32) M2C_FIELD(arg0->unk30.unk20, s16 *, 4) / 30.0f));
    arg0->unk30.unk24 = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x88) = arg1;
    sp1D0 = M2C_FIELD(arg0, f64 *, 0x30);
    sp1D8 = M2C_FIELD(arg0, f64 *, 0x38);
    sp1E0 = 0.0f;
    sp1E4 = 0.0f;
    sp1E8 = 0.0f;
    sp1F0 = 0.0f;
    sp1F4 = 0.0f;
    sp1F8 = 0.0f;
    sp200 = 0.0f;
    sp204 = 0.0f;
    sp208 = 0.0f;
    sp20C = 1.0f;
    sp210 = 0.0f;
    sp214 = 0.0f;
    sp218 = 0;
    sp21A = 0;
    sp21B = 0;
    sp21C = 0;
    sp220 = 3.4028235e38f;
    sp224 = 0;
    sp228 = 0;
    sp22C = -1;
    sp230 = 0;
    sp90 = sp1D0 + sp140;
    sp98 = (f32) sp1D8 + (f32) sp148;
    spC8 = 0.0f;
    spC0 = 0.0f;
    spC4 = 200.0f;
    sp150 = sp90;
    sp160 = (f64) spC0;
    sp158 = (f64) sp98;
    sp168 = (f64) spC8;
    temp_f0_747 = sp1D0 + sp160;
    spB0 = temp_f0_747;
    sp170 = temp_f0_747;
    spB8 = (f32) sp1D8 + (f32) sp168;
    sp178 = (f64) spB8;
    if (MKCollision_RayCollide(*((MKVector3 *) &sp170), *((MKVector3 *) &sp150), (MKCollisionResult *) &sp1E0, (MKCollisionMode) 4, 0x0C000000) != 0) {
        sp1D0 = (f64) sp1E0;
        sp1D8 = (f64) sp1E8;
        sp1C0 = (f64) sp1F0;
        sp1C8 = (f64) sp1F8;
    }
    ((Volume *) &sp130)->GetRandPos();
    sp60 = 0.0f;
    sp64 = -500.0f;
    sp68 = 0.0f;
    sp1B0 = sp130;
    spF0 = (f64) sp60;
    sp1B8 = sp138;
    spF8 = (f64) sp68;
    sp50 = sp1B0 + spF0;
    sp88 = 0.0f;
    sp80 = 0.0f;
    sp84 = 200.0f;
    sp58 = (f32) sp1B8 + (f32) spF8;
    sp110 = (f64) sp80;
    sp100 = sp50;
    sp108 = (f64) sp58;
    sp118 = (f64) sp88;
    temp_f0_810 = sp1B0 + sp110;
    sp70 = temp_f0_810;
    sp120 = temp_f0_810;
    sp78 = (f32) sp1B8 + (f32) sp118;
    sp128 = (f64) sp78;
    if (MKCollision_RayCollide(*((MKVector3 *) &sp120), *((MKVector3 *) &sp100), (MKCollisionResult *) &sp1E0, (MKCollisionMode) 4, 0x0C000000) != 0) {
        sp1B0 = (f64) sp1E0;
        sp1B8 = (f64) sp1E8;
    }
    sp40 = sp1B0 - sp1D0;
    sp1A0 = sp40;
    sp48 = (f32) sp1B8 - (f32) sp1D8;
    sp1A8 = (f64) sp48;
    var_f4_851 = ((f32) sp1A8 * (f32) sp1A8) + (((f32) sp1A0 * (f32) sp1A0) + ((*(f32 *) ((u8 *) &sp1A0 + 0x4)) * (*(f32 *) ((u8 *) &sp1A0 + 0x4))));
    if (var_f4_851 > 1e-12f) {
        if (var_f4_851 > 0.0f) {
            temp_f1_857 = __frsqrte(var_f4_851);
            temp_f1_863 = 0.5 * temp_f1_857 * -(((f64) var_f4_851 * (temp_f1_857 * temp_f1_857)) - 3.0);
            temp_f1_867 = 0.5 * temp_f1_863 * -(((f64) var_f4_851 * (temp_f1_863 * temp_f1_863)) - 3.0);
            var_f4_851 = (f32) ((f64) var_f4_851 * (0.5 * temp_f1_867 * -(((f64) var_f4_851 * (temp_f1_867 * temp_f1_867)) - 3.0)));
        } else if (var_f4_851 < M2C_BITWISE(f32, 0.0)) {
            var_f4_851 = __float_nan;
        } else {
            spC = var_f4_851;
            temp_r3_886 = M2C_BITWISE(s32, spC) & 0x7F800000;
            switch (temp_r3_886) {                  /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_896 = 1;
                } else {
                    var_r0_896 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_896 = 5;
                } else {
                    var_r0_896 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_896 = 4;
                break;
            }
            if (var_r0_896 == 1) {
                var_f4_851 = __float_nan;
            }
        }
        var_f3_918 = 1.0f / var_f4_851;
    } else {
        var_f3_918 = 0.0f;
    }
    sp24 = (*(f32 *) ((u8 *) &sp1A0 + 0x4)) * var_f3_918;
    sp20 = (f32) sp1A0 * var_f3_918;
    var_f0_932 = 0.0f;
    sp28 = (f32) sp1A8 * var_f3_918;
    spE0 = (f64) sp20;
    spE8 = (f64) sp28;
    sp30 = -(f32) spE0;
    sp34 = -(*(f32 *) ((u8 *) &spE0 + 0x4));
    sp38 = -(f32) spE8;
    sp190 = (f64) sp30;
    sp198 = (f64) sp38;
    sp10 = ((*(f32 *) ((u8 *) &sp190 + 0x4)) * (f32) sp1C8) - ((f32) sp198 * (*(f32 *) ((u8 *) &sp1C0 + 0x4)));
    sp14 = ((f32) sp198 * (f32) sp1C0) - ((f32) sp190 * (f32) sp1C8);
    sp18 = ((f32) sp190 * (*(f32 *) ((u8 *) &sp1C0 + 0x4))) - ((*(f32 *) ((u8 *) &sp190 + 0x4)) * (f32) sp1C0);
    sp180 = (f64) sp10;
    sp188 = (f64) sp18;
    arg0->unk0 = (f32) sp180;
    arg0->unk4 = (*(f32 *) ((u8 *) &sp180 + 0x4));
    arg0->unk8 = (f32) sp188;
    arg0->unkC = 0.0f;
    arg0->unk10 = (f32) sp1C0;
    arg0->unk14 = (*(f32 *) ((u8 *) &sp1C0 + 0x4));
    arg0->unk18 = (f32) sp1C8;
    arg0->unk1C = 0.0f;
    arg0->unk20 = (f32) sp190;
    arg0->unk24 = (*(f32 *) ((u8 *) &sp190 + 0x4));
    arg0->unk28 = (f32) sp198;
    arg0->unk2C = 0.0f;
    arg0->unk30.unk0 = (f32) sp1D0;
    arg0->unk30.unk4 = (*(f32 *) ((u8 *) &sp1D0 + 0x4));
    arg0->unk30.unk8 = (f32) sp1D8;
    arg0->unk30.unkC = 1.0f;
    M2C_FIELD(arg0, f64 *, 0x68) = sp1D0;
    M2C_FIELD(arg0, f64 *, 0x70) = sp1D8;
    M2C_FIELD(arg0, f64 *, 0x78) = sp1A0;
    arg0->unk30.unk50 = sp1A8;
    temp_f2_999 = arg0->unk30.unk48;
    temp_f1_1000 = arg0->unk30.unk4C;
    temp_f3_1001 = (f32) M2C_FIELD(arg0, f64 *, 0x80);
    var_f5_1006 = (temp_f3_1001 * temp_f3_1001) + ((temp_f2_999 * temp_f2_999) + (temp_f1_1000 * temp_f1_1000));
    if (var_f5_1006 > 0.000001f) {
        if (var_f5_1006 > 0.0f) {
            temp_f1_1011 = __frsqrte(var_f5_1006);
            temp_f1_1017 = 0.5 * temp_f1_1011 * -(((f64) var_f5_1006 * (temp_f1_1011 * temp_f1_1011)) - 3.0);
            temp_f1_1021 = 0.5 * temp_f1_1017 * -(((f64) var_f5_1006 * (temp_f1_1017 * temp_f1_1017)) - 3.0);
            var_f5_1006 = (f32) ((f64) var_f5_1006 * (0.5 * temp_f1_1021 * -(((f64) var_f5_1006 * (temp_f1_1021 * temp_f1_1021)) - 3.0)));
        } else if (var_f5_1006 < M2C_BITWISE(f32, 0.0)) {
            var_f5_1006 = __float_nan;
        } else {
            sp8 = var_f5_1006;
            temp_r3_1040 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_1040) {                 /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_1050 = 1;
                } else {
                    var_r0_1050 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_1050 = 5;
                } else {
                    var_r0_1050 = 3;
                }
                break;
            default:                                /* switch 2 */
                var_r0_1050 = 4;
                break;
            }
            if (var_r0_1050 == 1) {
                var_f5_1006 = __float_nan;
            }
        }
        var_f0_932 = 1.0f / var_f5_1006;
    } else {
        var_f5_1006 = 0.0f;
    }
    arg0->unk30.unk48 *= var_f0_932;
    arg0->unk30.unk4C *= var_f0_932;
    M2C_FIELD(arg0, f64 *, 0x80) = (f32) ((f32) M2C_FIELD(arg0, f64 *, 0x80) * var_f0_932);
    arg0->unk30.unk34 = var_f5_1006 / M2C_FIELD(arg0, f32 *, 0x88);
}
#endif

#if 0 // DRAFT: illegal type
void ShwimmaCritter::Resolve() {
    s32 temp_r0_1123;
    s32 var_r3_1117;
    s32 var_r6_1118;

    MKProp::Resolve();
    var_r3_1117 = 0;
    var_r6_1118 = 0;
loop_2:
    if (var_r6_1118 < (s32) this->unk90) {
        temp_r0_1123 = var_r3_1117 + 0x60;
        var_r6_1118 += 1;
        var_r3_1117 += 0x90;
        *(this->unk170 + temp_r0_1123) = 0;
        goto loop_2;
    }
}
#endif

void ShwimmaCritter::LoadDone() {
    MKHeap *temp_r3_1149;
    s32 temp_r31_1148;
    void *var_r3_1156;

    Critters::LoadDone();
    temp_r31_1148 = this->unk90 * 0x90;
    temp_r3_1149 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_1149 != NULL) {
        var_r3_1156 = ((MKHeap *) (temp_r3_1149->Current()))->Alloc(temp_r31_1148, NULL, 0);
    } else {
        var_r3_1156 = malloc(temp_r31_1148);
    }
    this->unk170 = var_r3_1156;
}

void ShwimmaCritter::Init() {
    Critters::Init();
}

void ShwimmaCritterDescriptor::Deinit() {
    KDPropDescriptor::Deinit();
}

void ShwimmaCritterDescriptor::LoadDone() {
    s8 *temp_r30_1205;
    s8 *temp_r30_1223;
    s8 *temp_r30_1241;
    s8 *temp_r30_1259;
    s8 *temp_r30_1277;
    s8 *temp_r30_1295;
    s8 *temp_r30_1313;
    s8 *temp_r30_1331;
    s8 *temp_r30_1349;
    s8 *temp_r30_1367;
    void *var_r3_1215;
    void *var_r3_1233;
    void *var_r3_1251;
    void *var_r3_1269;
    void *var_r3_1287;
    void *var_r3_1305;
    void *var_r3_1323;
    void *var_r3_1341;
    void *var_r3_1359;
    void *var_r3_1377;

    KDPropDescriptor::LoadDone();
    temp_r30_1205 = this->unk34;
    if (((MKAnimScript *) temp_r30_1205)->Exists("Walk") != 0) {
        var_r3_1215 = ((MKAnimScript *) temp_r30_1205)->GetAnim("Walk");
    } else {
        var_r3_1215 = NULL;
    }
    this->unk74 = (s32) var_r3_1215;
    temp_r30_1223 = this->unk34;
    if (((MKAnimScript *) temp_r30_1223)->Exists("Run") != 0) {
        var_r3_1233 = ((MKAnimScript *) temp_r30_1223)->GetAnim("Run");
    } else {
        var_r3_1233 = NULL;
    }
    this->unk78 = (s32) var_r3_1233;
    temp_r30_1241 = this->unk34;
    if (((MKAnimScript *) temp_r30_1241)->Exists("Glide_Enter") != 0) {
        var_r3_1251 = ((MKAnimScript *) temp_r30_1241)->GetAnim("Glide_Enter");
    } else {
        var_r3_1251 = NULL;
    }
    this->unk7C = (s32) var_r3_1251;
    temp_r30_1259 = this->unk34;
    if (((MKAnimScript *) temp_r30_1259)->Exists("Glide_Cycle") != 0) {
        var_r3_1269 = ((MKAnimScript *) temp_r30_1259)->GetAnim("Glide_Cycle");
    } else {
        var_r3_1269 = NULL;
    }
    this->unk80 = (s32) var_r3_1269;
    temp_r30_1277 = this->unk34;
    if (((MKAnimScript *) temp_r30_1277)->Exists("Glide_Exit") != 0) {
        var_r3_1287 = ((MKAnimScript *) temp_r30_1277)->GetAnim("Glide_Exit");
    } else {
        var_r3_1287 = NULL;
    }
    this->unk84 = (s32) var_r3_1287;
    temp_r30_1295 = this->unk34;
    if (((MKAnimScript *) temp_r30_1295)->Exists("Alert") != 0) {
        var_r3_1305 = ((MKAnimScript *) temp_r30_1295)->GetAnim("Alert");
    } else {
        var_r3_1305 = NULL;
    }
    this->unk88 = (s32) var_r3_1305;
    temp_r30_1313 = this->unk34;
    if (((MKAnimScript *) temp_r30_1313)->Exists("Idle_01") != 0) {
        var_r3_1323 = ((MKAnimScript *) temp_r30_1313)->GetAnim("Idle_01");
    } else {
        var_r3_1323 = NULL;
    }
    this->unk8C = (s32) var_r3_1323;
    temp_r30_1331 = this->unk34;
    if (((MKAnimScript *) temp_r30_1331)->Exists("Idle_02") != 0) {
        var_r3_1341 = ((MKAnimScript *) temp_r30_1331)->GetAnim("Idle_02");
    } else {
        var_r3_1341 = NULL;
    }
    this->unk90 = (s32) var_r3_1341;
    temp_r30_1349 = this->unk34;
    if (((MKAnimScript *) temp_r30_1349)->Exists("Idle_03") != 0) {
        var_r3_1359 = ((MKAnimScript *) temp_r30_1349)->GetAnim("Idle_03");
    } else {
        var_r3_1359 = NULL;
    }
    this->unk94 = (s32) var_r3_1359;
    temp_r30_1367 = this->unk34;
    if (((MKAnimScript *) temp_r30_1367)->Exists("Idle_04") != 0) {
        var_r3_1377 = ((MKAnimScript *) temp_r30_1367)->GetAnim("Idle_04");
    } else {
        var_r3_1377 = NULL;
    }
    this->unk98 = (s32) var_r3_1377;
}

void ShwimmaCritterDescriptor::Init() {
    KDPropDescriptor::Init();
}
