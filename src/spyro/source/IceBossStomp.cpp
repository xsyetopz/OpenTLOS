#include "spyro/source/IceBossStomp.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/IceBitsPS.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDParticleSystem.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/ManagedLight.h"
#include "spyro/source/PooledShatterProp.h"
#include "spyro/source/Projectile.h"
#include "spyro/source/Shatterable.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKCollision.h"
#include "common/Source/StdMath.h"
#include "spyro/source/DataMap.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

M2C_UNK free(MKHeap *);                             /* extern */
MKHeap *malloc(M2C_UNK);                            /* extern */
extern DataMap ElementTypeDataMap;
extern s32 GS_ElecBossStrikeEnd;
extern s32 GS_IceBossAttack1;
extern s32 GS_SpyroSpikeBurn;
extern M2C_UNK gEmptyPtrListDL;
extern MKSceneManager *gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;
extern MKPropDescriptor *pElecBossStompDescriptor;
extern MKPropDescriptor *pIceBossStompDescriptor;

static s32 lit_642 = 0;
static u8 lit_643 = 1;

static u8 lit_845 = 1;
#if 0 // DRAFT: pointer/array required
static M2C_UNK lit_715;                                /* unable to generate initializer: unknown type; const */

void IceBossStomp::Deinit() {
    MKHeap *temp_r0_106;
    MKHeap *temp_r0_87;
    MKHeap *temp_r29_70;
    MKHeap *temp_r3_109;
    MKHeap *var_r28_53;
    MKHeap *var_r30_83;
    MKHeap *var_r3_84;
    MKHeap *var_r4_79;
    ManagedLight *temp_r4_45;
    s32 temp_r3_57;
    u32 temp_r0_92;

    Projectile::Deinit();
    temp_r4_45 = this->unk160;
    if (temp_r4_45 != NULL) {
        gb.unk80->FreeManagedLight(temp_r4_45);
    }
    var_r28_53 = this->unk164;
loop_6:
    if (var_r28_53 != NULL) {
        temp_r29_70 = var_r28_53->unk0;
        if (temp_r29_70 == NULL) {

        } else {
            temp_r3_57 = temp_r29_70->unk2C;
            if ((u32) temp_r3_57 != 0U) {
                M2C_FIELD(M2C_FIELD(temp_r3_57, void **, 0x44), M2C_UNK (**)(), 0x34)();
                temp_r29_70->unk2C = 0;
            }
            var_r28_53 += 4;
            goto loop_6;
        }
    }
loop_10:
    var_r4_79 = this->unk164;
    if ((MKHeap *) var_r4_79->unk0 != NULL) {
        this->unk164 = (MKHeap *) &this->unk164->unk4;
        goto loop_10;
    }
    var_r30_83 = var_r4_79;
    var_r3_84 = var_r4_79;
loop_14:
    temp_r0_92 = M2C_FIELD(var_r3_84, u32 *, -4);
    var_r3_84 -= 4;
    if (temp_r0_92 != 0U) {
        temp_r0_87 = var_r3_84->unk0;
        if (temp_r0_87 < var_r30_83) {
            var_r30_83 = temp_r0_87;
        }
        goto loop_14;
    }
    if (var_r3_84 != &gEmptyPtrListDL) {
loop_20:
        temp_r0_106 = var_r4_79->unk0;
        if (temp_r0_106 != NULL) {
            if (temp_r0_106 < var_r30_83) {
                var_r30_83 = temp_r0_106;
            }
            var_r4_79 += 4;
            goto loop_20;
        }
        temp_r3_109 = var_r3_84->Current();
        if (temp_r3_109 != NULL) {
            ((MKHeap *) (temp_r3_109->Current()))->Free(var_r30_83, NULL, 0);
        } else {
            free(var_r30_83);
        }
    }
    this->unk164 = NULL;
}
#endif

#if 0 // DRAFT: pointer/array required
void IceBossStomp::Activate() {
    ManagedLight *temp_r4_140;

    GameProp::Activate();
    temp_r4_140 = this->unk160;
    if (temp_r4_140 != NULL) {
        gb.unk80->EnableLight(temp_r4_140, 1U);
    }
}
#endif

void IceBossStomp::ShatterIceShards() {
    MKHeap *temp_r3_184;
    MKHeap *var_r31_163;
    s32 temp_r3_166;

    var_r31_163 = this->unk164;
loop_4:
    if (var_r31_163 != NULL) {
        temp_r3_184 = var_r31_163->unk0;
        if (temp_r3_184 != NULL) {
            temp_r3_166 = temp_r3_184->unk2C;
            if ((u32) temp_r3_166 != 0U) {
                M2C_FIELD(M2C_FIELD(temp_r3_166, void **, 0x44), M2C_UNK (**)(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK), 0x94)(0, 0, -1, 0, 1, 0);
            }
            var_r31_163 += 4;
            goto loop_4;
        }
    }
}

#if 0 // DRAFT: pointer/array required
void IceBossStomp::Disable() {
    MKHeap *temp_r31_241;
    MKHeap *var_r30_212;
    ManagedLight *temp_r4_203;
    s32 temp_cr0_eq_219;
    s32 temp_r3_215;
    s32 temp_r4_218;

    temp_r4_203 = this->unk160;
    if (temp_r4_203 != NULL) {
        gb.unk80->EnableLight(temp_r4_203, 0U);
    }
    var_r30_212 = this->unk164;
loop_9:
    if (var_r30_212 != NULL) {
        temp_r31_241 = var_r30_212->unk0;
        if (temp_r31_241 != NULL) {
            temp_r3_215 = temp_r31_241->unk2C;
            if (((u32) temp_r3_215 != 0U) && ((temp_r4_218 = M2C_FIELD(temp_r3_215, s32 *, 0x180), temp_cr0_eq_219 = temp_r4_218 == 0, (temp_cr0_eq_219 != 0)) || ((temp_cr0_eq_219 == 0) && ((s32) *(M2C_FIELD(temp_r3_215, s32 *, 0x168) + (((temp_r4_218 - 1) << 7) + 0x44)) != 1)))) {
                M2C_FIELD(M2C_FIELD(temp_r3_215, void **, 0x44), M2C_UNK (**)(), 0x34)();
                temp_r31_241->unk2C = 0;
            }
            var_r30_212 += 4;
            goto loop_9;
        }
    }
    Projectile::Disable();
}
#endif

#if 0 // DRAFT: pointer/array required
void IceBossStomp::Deactivate() {
    ManagedLight *temp_r4_262;

    temp_r4_262 = this->unk160;
    if (temp_r4_262 != NULL) {
        gb.unk80->EnableLight(temp_r4_262, 0U);
    }
    GameProp::Deactivate();
}
#endif

void IceBossStomp::Draw() {

}

#if 0 // DRAFT: illegal implicit conversion from 'float' to
void IceBossStomp::UpdateIceCrystals() {
    Matrix sp3C0;
    M2C_UNK sp3BC;
    f64 sp3B8;
    f64 sp3B0;
    f64 sp3A8;
    f64 sp3A0;
    f64 sp398;
    f64 sp390;
    f64 sp388;
    f64 sp380;
    MKVector3 sp370;
    f64 sp368;
    f64 sp360;
    f64 sp358;
    f64 sp350;
    f64 sp348;
    f64 sp340;
    f64 sp338;
    f64 sp330;
    f64 sp328;
    f64 sp320;
    f64 sp318;
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
    f64 sp290;
    f64 sp288;
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
    f64 sp200;
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f32 sp1D8;
    f32 sp1D4;
    f32 sp1D0;
    f32 sp1C8;
    f32 sp1C4;
    f32 sp1C0;
    f32 sp1B8;
    f32 sp1B4;
    f32 sp1B0;
    f32 sp1A8;
    f64 sp1A0;
    f32 sp198;
    f32 sp194;
    f32 sp190;
    f32 sp188;
    f64 sp180;
    f32 sp178;
    f64 sp170;
    f32 sp168;
    f32 sp164;
    f32 sp160;
    f32 sp158;
    f64 sp150;
    f32 sp148;
    f32 sp144;
    f32 sp140;
    f32 sp138;
    f64 sp130;
    f32 sp12C;
    f32 sp128;
    f32 sp124;
    f32 sp120;
    f32 sp118;
    f32 sp114;
    f32 sp110;
    f32 sp108;
    f64 sp100;
    f32 spF8;
    f64 spF0;
    f32 spE8;
    f32 spE4;
    f32 spE0;
    f32 spDC;
    f32 spD8;
    f32 spD4;
    f32 spD0;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spB8;
    f64 spB0;
    f32 spA8;
    f64 spA0;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp88;
    f64 sp80;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    MKHeap *temp_r30_917;
    MKHeap *var_r29_324;
    f32 temp_f0_348;
    f32 temp_f1_663;
    f32 temp_f1_770;
    f32 temp_f1_868;
    f32 temp_f28_608;
    f32 temp_f28_659;
    f32 temp_f28_715;
    f32 temp_f28_754;
    f32 temp_f28_813;
    f32 temp_f28_864;
    f32 temp_f29_603;
    f32 temp_f29_710;
    f32 temp_f29_808;
    f32 temp_f31_590;
    f32 temp_f31_795;
    f32 temp_f3_380;
    f32 temp_f3_431;
    f32 temp_f6_388;
    f32 temp_f6_437;
    f32 temp_f7_394;
    f32 temp_f7_443;
    f32 var_f0_332;
    f64 temp_f0_507;
    f64 temp_f0_622;
    f64 temp_f0_633;
    f64 temp_f0_645;
    f64 temp_f0_674;
    f64 temp_f0_729;
    f64 temp_f0_740;
    f64 temp_f0_827;
    f64 temp_f0_838;
    f64 temp_f0_850;
    f64 temp_f0_879;
    s32 temp_r0_469;
    s32 var_r26_480;
    void *temp_r26_536;
    void *temp_r3_430;
    void *temp_r3_485;
    void *temp_r3_529;
    void *temp_r3_533;
    void *temp_r3_545;
    void *temp_r6_378;

    var_r29_324 = this->unk164;
loop_20:
    if (var_r29_324 != NULL) {
        temp_r30_917 = var_r29_324->unk0;
        if (temp_r30_917 != NULL) {
            var_f0_332 = temp_r30_917->unk10 - gUpdateTimeDelta;
            if (var_f0_332 < 1.0f) {

            } else {
                var_f0_332 = 1.0f;
            }
            if (var_f0_332 > 0.0f) {

            } else {
                var_f0_332 = 0.0f;
            }
            temp_r30_917->unk10 = var_f0_332;
            temp_f0_348 = 1.0f - temp_r30_917->unk10;
            temp_r30_917->unk18 = temp_f0_348;
            temp_r30_917->unk1C = temp_f0_348;
            temp_r30_917->unk20 = temp_f0_348;
            if ((u32) temp_r30_917->unk2C != 0U) {
                M2C_STRUCT_COPY((s32) &sp3BC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
                M2C_STRUCT_COPY((s32) &sp3BC + 4, (s32) (this->unk8 - 4) + 4, 0x40);
                temp_r6_378 = this->unk8;
                temp_f3_380 = M2C_BITWISE(f32, temp_r30_917->unk4);
                temp_f6_388 = M2C_BITWISE(f32, temp_r30_917->unk0);
                temp_f7_394 = M2C_BITWISE(f32, temp_r30_917->unk8);
                sp1D0 = M2C_FIELD(temp_r6_378, f32 *, 0x30) + ((temp_f7_394 * M2C_FIELD(temp_r6_378, f32 *, 0x20)) + ((temp_f6_388 * M2C_FIELD(temp_r6_378, f32 *, 0)) + (temp_f3_380 * M2C_FIELD(temp_r6_378, f32 *, 0x10))));
                sp1D4 = M2C_FIELD(temp_r6_378, f32 *, 0x34) + ((temp_f7_394 * M2C_FIELD(temp_r6_378, f32 *, 0x24)) + ((temp_f6_388 * M2C_FIELD(temp_r6_378, f32 *, 4)) + (temp_f3_380 * M2C_FIELD(temp_r6_378, f32 *, 0x14))));
                sp1D8 = M2C_FIELD(temp_r6_378, f32 *, 0x38) + ((temp_f7_394 * M2C_FIELD(temp_r6_378, f32 *, 0x28)) + ((temp_f6_388 * M2C_FIELD(temp_r6_378, f32 *, 8)) + (temp_f3_380 * M2C_FIELD(temp_r6_378, f32 *, 0x18))));
                sp3B0 = (f64) sp1D0;
                sp3B8 = (f64) sp1D8;
                sp3C0.Scale3x3(&sp3C0, *((MKVector3 *) &temp_r30_917->unk18));
                sp3C0.unk30 = (f32) sp3B0;
                sp3C0.unk34 = unksp3B4;
                sp3C0.unk38 = (f32) sp3B8;
                sp3C0.unk3C = 1.0f;
                MKModel_SetWorldMatrix(M2C_FIELD(temp_r30_917->unk2C, MKModel **, 4), sp3C0);
            }
            temp_r3_430 = this->unk8;
            temp_f3_431 = M2C_BITWISE(f32, temp_r30_917->unk4);
            temp_f6_437 = M2C_BITWISE(f32, temp_r30_917->unk0);
            temp_f7_443 = M2C_BITWISE(f32, temp_r30_917->unk8);
            sp40 = M2C_FIELD(temp_r3_430, f32 *, 0x30) + ((temp_f7_443 * M2C_FIELD(temp_r3_430, f32 *, 0x20)) + ((temp_f6_437 * M2C_FIELD(temp_r3_430, f32 *, 0)) + (temp_f3_431 * M2C_FIELD(temp_r3_430, f32 *, 0x10))));
            sp44 = M2C_FIELD(temp_r3_430, f32 *, 0x34) + ((temp_f7_443 * M2C_FIELD(temp_r3_430, f32 *, 0x24)) + ((temp_f6_437 * M2C_FIELD(temp_r3_430, f32 *, 4)) + (temp_f3_431 * M2C_FIELD(temp_r3_430, f32 *, 0x14))));
            sp48 = M2C_FIELD(temp_r3_430, f32 *, 0x38) + ((temp_f7_443 * M2C_FIELD(temp_r3_430, f32 *, 0x28)) + ((temp_f6_437 * M2C_FIELD(temp_r3_430, f32 *, 8)) + (temp_f3_431 * M2C_FIELD(temp_r3_430, f32 *, 0x18))));
            sp3A0 = (f64) sp40;
            sp3A8 = (f64) sp48;
            sp390 = (f64) sp40;
            sp398 = (f64) sp48;
            temp_r0_469 = M2C_FIELD(checked_cast<IceBossStompDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xFC);
            switch (temp_r0_469) {                  /* irregular */
            case 2:
                var_r26_480 = 0;
                do {
                    temp_r3_485 = checked_cast<IceBossStompDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
                    sp1C8 = -1.0f;
                    sp1B8 = 1.0f;
                    sp1C0 = -1.0f;
                    sp1C4 = 0.5f;
                    sp1B0 = 1.0f;
                    sp1B4 = 2.0f;
                    sp360 = (f64) sp1C0;
                    sp368 = (f64) sp1C8;
                    sp350 = (f64) sp1B0;
                    sp358 = (f64) sp1B8;
                    KDRand_Vector(sp370, *((MKVector3 *) &sp360));
                    temp_f0_507 = sp370 * 5.64367472e-315;
                    sp1A0 = temp_f0_507;
                    sp380 = temp_f0_507;
                    sp1A8 = sp370.unk8 * 600.0f;
                    sp388 = (f64) sp1A8;
                    sp1C = MKRand_Float(&gViewSeed, 1.0f, 1.1f);
                    ((IceBitsPS *) (M2C_FIELD(temp_r3_485, IceBitsPS **, 0xF4)))->Emit(*((MKVector3 *) &sp3A0), *((MKVector3 *) &sp380), sp1C);
                    var_r26_480 += 1;
                } while (var_r26_480 < 5);
                temp_r3_529 = this->unk170;
                temp_r3_533 = M2C_FIELD(M2C_FIELD(temp_r3_529, void **, 0x44), void *(**)(void *), 0x3C)(temp_r3_529);
                if (temp_r3_533 != NULL) {
                    temp_r26_536 = M2C_FIELD(temp_r3_533, void **, 0x2C);
                    M2C_FIELD(temp_r3_533, f64 *, 0) = sp3A0;
                    M2C_FIELD(temp_r3_533, f64 *, 8) = sp3A8;
                    M2C_FIELD(temp_r3_533, f32 *, 0x20) = 0.0f;
                    M2C_FIELD(temp_r3_533, f32 *, 0x28) = 0.0f;
                    temp_r3_545 = this->unk8;
                    sp20 = -M2C_FIELD(temp_r3_545, f32 *, 0x20);
                    sp24 = -M2C_FIELD(temp_r3_545, f32 *, 0x24);
                    sp28 = -M2C_FIELD(temp_r3_545, f32 *, 0x28);
                    sp330 = (f64) sp20;
                    sp338 = (f64) sp28;
                    sp30 = sp330 * 5.634608575e-315;
                    M2C_FIELD(temp_r26_536, f64 *, 0) = sp30;
                    sp38 = (f32) sp338 * 500.0f;
                    sp340 = sp30;
                    sp348 = (f64) sp38;
                    M2C_FIELD(temp_r26_536, f64 *, 8) = (f64) sp38;
                    M2C_FIELD(temp_r26_536, f32 *, 0x18) = MKRand_Float(&gViewSeed, 0.5f, 1.0f);
                    M2C_FIELD(temp_r26_536, f32 *, 0x10) = MKRand_Float(&gViewSeed, -3.1415927f, 3.1415927f);
                    M2C_FIELD(temp_r26_536, f32 *, 0x14) = (f32) M2C_FIELD(this->unk170, f32 *, 0xF4);
                }
                temp_f31_590 = MKRand_Float(&gViewSeed, 0.1f, 1.0f);
                sp168 = 0.0f;
                sp160 = 0.0f;
                sp164 = 200.0f;
                sp2E8 = (f64) sp168;
                sp2E0 = (f64) sp160;
                temp_f29_603 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                temp_f28_608 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                sp190 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                sp194 = temp_f28_608;
                sp198 = temp_f29_603;
                sp2F0 = (f64) sp190;
                sp2F8 = (f64) sp198;
                temp_f0_622 = sp2F0 * 5.60222949e-315;
                sp180 = temp_f0_622;
                sp300 = temp_f0_622;
                sp188 = (f32) sp2F8 * 300.0f;
                sp308 = (f64) sp188;
                temp_f0_633 = sp3A0 + temp_f0_622;
                sp170 = temp_f0_633;
                sp310 = temp_f0_633;
                sp178 = (f32) sp3A8 + (f32) sp308;
                sp318 = (f64) sp178;
                temp_f0_645 = sp310 + sp2E0;
                sp150 = temp_f0_645;
                sp320 = temp_f0_645;
                sp158 = (f32) sp318 + (f32) sp2E8;
                sp328 = (f64) sp158;
                temp_f28_659 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                temp_f1_663 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                sp148 = temp_f28_659;
                sp140 = temp_f1_663;
                sp144 = 1.0f;
                sp2C8 = (f64) sp148;
                sp2C0 = (f64) sp140;
                temp_f0_674 = sp2C0 * 5.603848443e-315;
                sp130 = temp_f0_674;
                sp2D0 = temp_f0_674;
                sp138 = (f32) sp2C8 * 310.0f;
                sp2D8 = (f64) sp138;
                sp18 = MKRand_Float(&gViewSeed, 7.1f, 15.0f);
                sp120 = temp_f31_590;
                sp124 = temp_f31_590;
                sp128 = 1.0f;
                sp12C = 1.0f;
                sp2B0 = (f64) sp120;
                sp2B8 = (f64) sp128;
                gb.unk74->Emit(*((MKVector3 *) &sp320), *((MKVector3 *) &sp2D0), sp18, *((MKVector4 *) &sp2B0), 0.0f);
                break;
            case 1:
                temp_f29_710 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                temp_f28_715 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                sp110 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                sp114 = temp_f28_715;
                sp118 = temp_f29_710;
                sp280 = (f64) sp110;
                sp288 = (f64) sp118;
                temp_f0_729 = sp280 * 5.60222949e-315;
                sp100 = temp_f0_729;
                sp290 = temp_f0_729;
                sp108 = (f32) sp288 * 300.0f;
                sp298 = (f64) sp108;
                temp_f0_740 = sp3A0 + temp_f0_729;
                spF0 = temp_f0_740;
                sp2A0 = temp_f0_740;
                spF8 = (f32) sp3A8 + (f32) sp298;
                sp2A8 = (f64) spF8;
                temp_f28_754 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                spE0 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                spE4 = 1.0f;
                spE8 = temp_f28_754;
                sp270 = (f64) spE0;
                sp278 = (f64) spE8;
                temp_f1_770 = MKRand_Float(&gViewSeed, 1.0f, 2.0f);
                spD0 = 1.0f;
                spD4 = 0.0f;
                spD8 = 0.25f;
                spDC = 1.0f;
                sp14 = temp_f1_770;
                sp260 = (f64) spD0;
                sp268 = (f64) spD8;
                gb.unk94->Trigger(*((MKVector3 *) &sp2A0), *((MKVector3 *) &sp270), sp14, lit_845, (MKVector4) &sp260);
                temp_f31_795 = MKRand_Float(&gViewSeed, 0.1f, 1.0f);
                sp98 = 0.0f;
                sp90 = 0.0f;
                sp94 = 200.0f;
                sp218 = (f64) sp98;
                sp210 = (f64) sp90;
                temp_f29_808 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                temp_f28_813 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                spC0 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                spC4 = temp_f28_813;
                spC8 = temp_f29_808;
                sp220 = (f64) spC0;
                sp228 = (f64) spC8;
                temp_f0_827 = sp220 * 5.60222949e-315;
                spB0 = temp_f0_827;
                sp230 = temp_f0_827;
                spB8 = (f32) sp228 * 300.0f;
                sp238 = (f64) spB8;
                temp_f0_838 = sp3A0 + temp_f0_827;
                spA0 = temp_f0_838;
                sp240 = temp_f0_838;
                spA8 = (f32) sp3A8 + (f32) sp238;
                sp248 = (f64) spA8;
                temp_f0_850 = sp240 + sp210;
                sp80 = temp_f0_850;
                sp250 = temp_f0_850;
                sp88 = (f32) sp248 + (f32) sp218;
                sp258 = (f64) sp88;
                temp_f28_864 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                temp_f1_868 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                sp78 = temp_f28_864;
                sp70 = temp_f1_868;
                sp74 = 1.0f;
                sp1F8 = (f64) sp78;
                sp1F0 = (f64) sp70;
                temp_f0_879 = sp1F0 * 5.603848443e-315;
                sp60 = temp_f0_879;
                sp200 = temp_f0_879;
                sp68 = (f32) sp1F8 * 310.0f;
                sp208 = (f64) sp68;
                sp10 = MKRand_Float(&gViewSeed, 7.1f, 15.0f);
                sp50 = temp_f31_795;
                sp54 = 0.0f;
                sp58 = 0.5f * temp_f31_795;
                sp5C = 1.0f;
                sp1E0 = (f64) sp50;
                sp1E8 = (f64) sp58;
                gb.unk74->Emit(*((MKVector3 *) &sp250), *((MKVector3 *) &sp200), sp10, *((MKVector4 *) &sp1E0), 0.0f);
                break;
            }
            var_r29_324 += 4;
            goto loop_20;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'MKVector'
void IceBossStomp::EmitSnowRing() {
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    MKVector3 sp38;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f1_998;
    f32 temp_f25_993;
    f32 temp_f26_996;
    s32 var_r29_983;
    void *temp_r28_1017;
    void *temp_r3_1012;
    void *temp_r4_1015;

    var_r29_983 = 0;
    do {
        temp_f25_993 = 6.2831855f * ((f32) var_r29_983 / 19.0f);
        temp_f26_996 = -_table_sinf(1.5707964f + temp_f25_993);
        temp_f1_998 = _table_sinf(temp_f25_993);
        sp20 = temp_f26_996;
        sp18 = temp_f1_998;
        sp1C = 0.0f;
        sp70 = (f64) sp20;
        sp68 = (f64) sp18;
        sp58 = (f64) sp18;
        sp60 = (f64) sp20;
        temp_r3_1012 = M2C_FIELD(M2C_FIELD(gb.unk2A0, void **, 0x44), void *(**)(void *, f64), 0x3C)(gb.unk2A0, (f64) sp18);
        if (temp_r3_1012 != NULL) {
            temp_r4_1015 = this->unk8;
            temp_r28_1017 = M2C_FIELD(temp_r3_1012, void **, 0x2C);
            M2C_FIELD(temp_r3_1012, f64 *, 0) = (f64) M2C_FIELD(temp_r4_1015, f64 *, 0x30);
            M2C_FIELD(temp_r3_1012, f64 *, 8) = (f64) M2C_FIELD(temp_r4_1015, f64 *, 0x38);
            M2C_FIELD(temp_r3_1012, f32 *, 0x20) = 0.0f;
            M2C_FIELD(temp_r3_1012, f32 *, 0x28) = 0.0f;
            MKVector(0.0f, 300.0f, 0.0f);
            sp38.operator*(2000.0f);
            sp8 = sp38 + sp28;
            M2C_FIELD(temp_r28_1017, f64 *, 0) = sp8;
            sp10 = sp38.unk8 + sp30;
            sp48 = sp8;
            M2C_FIELD(temp_r28_1017, f64 *, 8) = (f64) sp10;
            sp50 = (f64) sp10;
            M2C_FIELD(temp_r28_1017, f32 *, 0x18) = 0.6f;
            M2C_FIELD(temp_r28_1017, f32 *, 0x10) = MKRand_Float(&gViewSeed, -3.1415927f, 3.1415927f);
            M2C_FIELD(temp_r28_1017, f32 *, 0x14) = (f32) M2C_FIELD(gb.unk2A0, f32 *, 0xF4);
        }
        var_r29_983 += 1;
    } while (var_r29_983 < 0x14);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'float' to
void IceBossStomp::SpawnIceCrystal(const MKVector3 &arg0) {
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
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    MKHeap *temp_r30_1108;
    MKHeap *temp_r3_1102;
    MKHeap *temp_r3_1106;
    f32 temp_f3_1148;
    f32 temp_f6_1154;
    f32 temp_f7_1160;
    f64 temp_f0_1222;
    s32 temp_r0_1186;
    s32 temp_r3_1134;
    s32 temp_r3_1141;
    s32 var_r29_1195;
    void *temp_r29_1251;
    void *temp_r3_1147;
    void *temp_r3_1200;
    void *temp_r3_1244;
    void *temp_r3_1248;
    void *temp_r3_1260;

    temp_r3_1102 = this->unk164;
    if (((u32) M2C_FIELD(temp_r3_1102, u32 *, -4) != 0U) && (temp_r3_1106 = temp_r3_1102 - 4, this->unk164 = temp_r3_1106, temp_r30_1108 = temp_r3_1106->unk0, ((temp_r30_1108 == NULL) == 0))) {
        M2C_FIELD(temp_r30_1108, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r30_1108, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
        temp_r30_1108->unk10 = 1.0f;
        temp_r30_1108->unk18 = 0.0f;
        temp_r30_1108->unk1C = 0.0f;
        temp_r30_1108->unk20 = 0.0f;
        temp_r30_1108->unk28 = -3.1415927f * MKRand_Float(&gViewSeed, 0.25f, 0.4f);
        temp_r30_1108->unk2C = checked_cast<PooledShatterProp *, MKProp>(((MKPropDescriptor *) (M2C_FIELD(checked_cast<IceBossStompDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKPropDescriptor **, 0xF0)))->CreateInstance());
        temp_r3_1134 = temp_r30_1108->unk2C;
        if ((u32) temp_r3_1134 != 0U) {
            M2C_FIELD(M2C_FIELD(temp_r3_1134, void **, 0x44), M2C_UNK (**)(), 0x20)();
            temp_r3_1141 = temp_r30_1108->unk2C;
            M2C_FIELD(M2C_FIELD(temp_r3_1141, void **, 0x44), M2C_UNK (**)(s32), 0x30)(temp_r3_1141);
        }
        temp_r3_1147 = this->unk8;
        temp_f3_1148 = M2C_BITWISE(f32, temp_r30_1108->unk4);
        temp_f6_1154 = M2C_BITWISE(f32, temp_r30_1108->unk0);
        temp_f7_1160 = M2C_BITWISE(f32, temp_r30_1108->unk8);
        sp30 = M2C_FIELD(temp_r3_1147, f32 *, 0x30) + ((temp_f7_1160 * M2C_FIELD(temp_r3_1147, f32 *, 0x20)) + ((temp_f6_1154 * M2C_FIELD(temp_r3_1147, f32 *, 0)) + (temp_f3_1148 * M2C_FIELD(temp_r3_1147, f32 *, 0x10))));
        sp34 = M2C_FIELD(temp_r3_1147, f32 *, 0x34) + ((temp_f7_1160 * M2C_FIELD(temp_r3_1147, f32 *, 0x24)) + ((temp_f6_1154 * M2C_FIELD(temp_r3_1147, f32 *, 4)) + (temp_f3_1148 * M2C_FIELD(temp_r3_1147, f32 *, 0x14))));
        sp38 = M2C_FIELD(temp_r3_1147, f32 *, 0x38) + ((temp_f7_1160 * M2C_FIELD(temp_r3_1147, f32 *, 0x28)) + ((temp_f6_1154 * M2C_FIELD(temp_r3_1147, f32 *, 8)) + (temp_f3_1148 * M2C_FIELD(temp_r3_1147, f32 *, 0x18))));
        spE0 = (f64) sp30;
        spE8 = (f64) sp38;
        spD0 = (f64) sp30;
        spD8 = (f64) sp38;
        temp_r0_1186 = M2C_FIELD(checked_cast<IceBossStompDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xFC);
        if (temp_r0_1186 != 2) {
            if (temp_r0_1186 < 2) {

            }
        } else {
            var_r29_1195 = 0;
            do {
                temp_r3_1200 = checked_cast<IceBossStompDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
                sp68 = -1.0f;
                sp58 = 1.0f;
                sp60 = -1.0f;
                sp64 = 0.5f;
                sp50 = 1.0f;
                sp54 = 2.0f;
                spA0 = (f64) sp60;
                spA8 = (f64) sp68;
                sp90 = (f64) sp50;
                sp98 = (f64) sp58;
                KDRand_Vector(spB0, *((MKVector3 *) &spA0));
                temp_f0_1222 = spB0 * 5.64367472e-315;
                sp40 = temp_f0_1222;
                spC0 = temp_f0_1222;
                sp48 = spB0.unk8 * 600.0f;
                spC8 = (f64) sp48;
                sp8 = MKRand_Float(&gViewSeed, 1.0f, 1.1f);
                ((IceBitsPS *) (M2C_FIELD(temp_r3_1200, IceBitsPS **, 0xF4)))->Emit(*((MKVector3 *) &spE0), *((MKVector3 *) &spC0), sp8);
                var_r29_1195 += 1;
            } while (var_r29_1195 < 5);
            temp_r3_1244 = this->unk170;
            temp_r3_1248 = M2C_FIELD(M2C_FIELD(temp_r3_1244, void **, 0x44), void *(**)(void *), 0x3C)(temp_r3_1244);
            if (temp_r3_1248 != NULL) {
                temp_r29_1251 = M2C_FIELD(temp_r3_1248, void **, 0x2C);
                M2C_FIELD(temp_r3_1248, f64 *, 0) = spE0;
                M2C_FIELD(temp_r3_1248, f64 *, 8) = spE8;
                M2C_FIELD(temp_r3_1248, f32 *, 0x20) = 0.0f;
                M2C_FIELD(temp_r3_1248, f32 *, 0x28) = 0.0f;
                temp_r3_1260 = this->unk8;
                sp10 = -M2C_FIELD(temp_r3_1260, f32 *, 0x20);
                sp14 = -M2C_FIELD(temp_r3_1260, f32 *, 0x24);
                sp18 = -M2C_FIELD(temp_r3_1260, f32 *, 0x28);
                sp70 = (f64) sp10;
                sp78 = (f64) sp18;
                sp20 = sp70 * 5.634608575e-315;
                M2C_FIELD(temp_r29_1251, f64 *, 0) = sp20;
                sp28 = (f32) sp78 * 500.0f;
                sp80 = sp20;
                sp88 = (f64) sp28;
                M2C_FIELD(temp_r29_1251, f64 *, 8) = (f64) sp28;
                M2C_FIELD(temp_r29_1251, f32 *, 0x18) = MKRand_Float(&gViewSeed, 0.5f, 1.0f);
                M2C_FIELD(temp_r29_1251, f32 *, 0x10) = MKRand_Float(&gViewSeed, -3.1415927f, 3.1415927f);
                M2C_FIELD(temp_r29_1251, f32 *, 0x14) = (f32) M2C_FIELD(this->unk170, f32 *, 0xF4);
            }
        }
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void IceBossStomp::Update() {
    f64 sp408;
    f64 sp400;
    f64 sp3F8;
    f64 sp3F0;
    f64 sp3E0;
    f64 sp3D8;
    f64 sp3D0;
    f64 sp3C8;
    f64 sp3B8;
    f64 sp3B0;
    f64 sp3A8;
    f64 sp3A0;
    M2C_UNK sp39C;
    u8 sp398;
    s32 sp394;
    void *sp390;
    s32 sp38C;
    f32 sp388;
    s32 sp384;
    s8 sp383;
    s8 sp382;
    s16 sp380;
    f32 sp37C;
    f32 sp378;
    f32 sp374;
    f32 sp370;
    f32 sp36C;
    f32 sp368;
    f32 sp360;
    f32 sp35C;
    f32 sp358;
    f32 sp350;
    f32 sp34C;
    f32 sp348;
    s8 sp340;
    f64 sp338;
    f64 sp330;
    s32 sp32C;
    s32 sp328;
    void *sp320;
    s32 sp31C;
    s32 sp318;
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
    f64 sp290;
    f64 sp288;
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
    f64 sp200;
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    MKVector3 sp198;
    M2C_UNK sp188;
    f32 sp180;
    f64 sp178;
    f32 sp170;
    f64 sp168;
    f32 sp160;
    f32 sp15C;
    f32 sp158;
    f32 sp150;
    f64 sp148;
    f32 sp140;
    f64 sp138;
    f32 sp130;
    f64 sp128;
    f32 sp120;
    f64 sp118;
    f32 sp110;
    f64 sp108;
    f32 sp100;
    f64 spF8;
    f32 spF0;
    f64 spE8;
    f32 spE0;
    f64 spD8;
    f32 spD0;
    f64 spC8;
    f32 spC0;
    f64 spB8;
    f32 spB0;
    f64 spA8;
    f32 spA0;
    f64 sp98;
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
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    u8 sp14;
    void *sp10;
    s32 sp8;
    MKProp *temp_r3_1364;
    MKVector3 *temp_r3_1636;
    ManagedLight *temp_r3_1822;
    ManagedLight *temp_r3_1840;
    f32 temp_f0_1443;
    f32 temp_f0_1841;
    f32 temp_f1_1892;
    f32 temp_f26_1909;
    f32 temp_f27_1901;
    f32 temp_f28_1914;
    f32 temp_f3_1698;
    f32 temp_f5_1554;
    f32 temp_f6_1574;
    f32 var_f0_1706;
    f64 temp_f0_1619;
    f64 temp_f0_1755;
    f64 temp_f1_1450;
    f64 temp_f1_1483;
    f64 temp_f1_1494;
    f64 temp_f1_1505;
    f64 temp_f1_1550;
    f64 temp_f1_1561;
    f64 temp_f1_1582;
    f64 temp_f1_1601;
    f64 temp_f3_1462;
    s32 var_r28_1621;
    s32 var_r30_1623;
    u32 var_r29_1673;
    u8 temp_r3_1425;
    void *temp_r3_1813;
    void *temp_r3_1828;
    void *temp_r3_1843;
    void *temp_r3_1868;
    void *temp_r4_1345;
    void *temp_r4_1430;
    void *temp_r4_1867;
    void *var_r4_1361;

    if ((s32 *) this->unk138 != NULL) {
        temp_r4_1345 = checked_cast<IceBossStompDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        sp8 = 1;
        this->unk138->Update(M2C_FIELD(temp_r4_1345, s32 *, 0xE8), 1U, ((u8) this->unk14C >> 6U) & 1, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    }
    sp31C = 0;
    var_r4_1361 = NULL;
    sp320 = NULL;
    sp318 = 0x27;
    temp_r3_1364 = this->unk130;
    if (temp_r3_1364 != NULL) {
        M2C_FIELD(temp_r3_1364->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp318);
        var_r4_1361 = sp320;
    }
    sp10 = var_r4_1361;
    if (var_r4_1361 != NULL) {
        sp14 = M2C_FIELD(var_r4_1361, u8 *, 4);
        M2C_FIELD(var_r4_1361, u8 *, 4) = 0U;
    }
    this->unk140 -= gUpdateTimeDelta;
    if (this->unk140 <= 0.0f) {
        this->unk140 = 0.0f;
        if ((s32) M2C_FIELD(checked_cast<IceBossStompDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xFC) == 2) {
            KDSound_Play3d(GS_IceBossAttack1, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
        } else {
            KDSound_Play3d(GS_ElecBossStrikeEnd, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
        }
        ShatterIceShards();
        Disable();
    } else {
        temp_r3_1425 = this->unk14C;
        if (((temp_r3_1425 >> 7U) & 1) && ((temp_r3_1425 >> 6U) & 1)) {
            temp_r4_1430 = this->unk8;
            sp308 = M2C_FIELD(temp_r4_1430, f64 *, 0x30);
            sp310 = M2C_FIELD(temp_r4_1430, f64 *, 0x38);
            sp178 = this->unkC8 * (f64) gUpdateTimeDelta;
            temp_f0_1443 = M2C_FIELD(this, f32 *, 0xD0) * gUpdateTimeDelta;
            sp2A8 = sp178;
            sp180 = temp_f0_1443;
            sp2B0 = (f64) sp180;
            temp_f1_1450 = sp308 + sp178;
            sp168 = temp_f1_1450;
            sp2F8 = temp_f1_1450;
            sp170 = (f32) sp310 + (f32) sp2B0;
            sp300 = (f64) sp170;
            temp_f3_1462 = -this->unk16C;
            sp138 = *(temp_r4_1430 + 0x20) * temp_f3_1462;
            sp160 = 0.0f;
            sp140 = M2C_FIELD(temp_r4_1430, f32 *, 0x28) * (f32) temp_f3_1462;
            sp158 = 0.0f;
            sp15C = 150.0f;
            sp278 = sp138;
            sp288 = (f64) sp158;
            sp280 = (f64) sp140;
            sp290 = (f64) sp160;
            temp_f1_1483 = sp308 + sp288;
            sp148 = temp_f1_1483;
            sp298 = temp_f1_1483;
            sp150 = (f32) sp310 + (f32) sp290;
            sp2A0 = (f64) sp150;
            temp_f1_1494 = sp298 + sp278;
            sp128 = temp_f1_1494;
            sp2E8 = temp_f1_1494;
            sp130 = (f32) sp2A0 + (f32) sp280;
            sp2F0 = (f64) sp130;
            temp_f1_1505 = this->unkC8 * (f64) gUpdateTimeDelta;
            sp118 = temp_f1_1505;
            sp120 = temp_f0_1443;
            sp268 = temp_f1_1505;
            sp270 = (f64) sp120;
            sp108 = temp_f1_1494 + sp268;
            sp2D8 = sp108;
            sp110 = (f32) sp2F0 + (f32) sp270;
            sp2E0 = (f64) sp110;
            sp2C8 = M2C_FIELD(temp_r4_1430, f64 *, 0);
            sp2D0 = M2C_FIELD(temp_r4_1430, f64 *, 8);
            M2C_STRUCT_COPY((s32) &sp39C + 4, (s32) (&lit_715 - 4) + 4, 0x78);
            sp3A0 = sp128;
            sp3A8 = (f64) sp130;
            sp3B0 = sp108;
            sp3B8 = (f64) sp110;
            temp_f1_1550 = sp2C8 * 5.56078426e-315;
            spF8 = temp_f1_1550;
            temp_f5_1554 = (f32) sp2D0 * 150.0f;
            sp258 = temp_f1_1550;
            sp100 = temp_f5_1554;
            sp260 = (f64) sp100;
            temp_f1_1561 = sp2E8 + temp_f1_1550;
            spE8 = temp_f1_1561;
            sp3C8 = temp_f1_1561;
            spF0 = (f32) sp2F0 + (f32) sp260;
            sp3D0 = (f64) spF0;
            spD8 = sp2C8 * 5.676053805e-315;
            temp_f6_1574 = (f32) sp2D0 * 1000.0f;
            spE0 = temp_f6_1574;
            sp248 = spD8;
            sp250 = (f64) spE0;
            temp_f1_1582 = sp2D8 + sp248;
            spC8 = temp_f1_1582;
            sp3D8 = temp_f1_1582;
            spD0 = (f32) sp2E0 + (f32) sp250;
            sp3E0 = (f64) spD0;
            spB8 = sp2C8 * 5.56078426e-315;
            spC0 = temp_f5_1554;
            sp238 = spB8;
            sp240 = (f64) spC0;
            temp_f1_1601 = sp2E8 - sp238;
            spA8 = temp_f1_1601;
            sp3F0 = temp_f1_1601;
            spB0 = (f32) sp2F0 - (f32) sp240;
            sp3F8 = (f64) spB0;
            sp98 = sp2C8 * 5.676053805e-315;
            spA0 = temp_f6_1574;
            sp228 = sp98;
            sp230 = (f64) spA0;
            temp_f0_1619 = sp2D8 - sp228;
            sp88 = temp_f0_1619;
            var_r28_1621 = 0;
            var_r30_1623 = 0;
            sp400 = temp_f0_1619;
            sp90 = (f32) sp2E0 - (f32) sp230;
            sp408 = (f64) sp90;
loop_14:
            temp_r3_1636 = &sp3A0 + var_r30_1623;
            sp348 = 0.0f;
            sp34C = 0.0f;
            sp350 = 0.0f;
            sp358 = 0.0f;
            sp35C = 0.0f;
            sp360 = 0.0f;
            sp368 = 0.0f;
            sp36C = 0.0f;
            sp370 = 0.0f;
            sp374 = 1.0f;
            sp378 = 0.0f;
            sp37C = 0.0f;
            sp380 = 0;
            sp382 = 0;
            sp383 = 0;
            sp384 = 0;
            sp388 = 3.4028235e38f;
            sp38C = 0;
            sp390 = NULL;
            sp394 = -1;
            sp398 = 0;
            if (MKCollision_SweepSphereCollide(*temp_r3_1636, *(temp_r3_1636 + 0x10), M2C_FIELD(temp_r3_1636, f32 *, 0x20), (MKCollisionResult *) &sp348, (MKCollisionMode) 2, 0) != 0) {
                if ((sp398 != 0) && (sp390 != NULL) && (var_r29_1673 = M2C_FIELD(sp390, u32 *, 8), ((var_r29_1673 == 0U) == 0))) {

                } else {
                    var_r29_1673 = 0U;
                }
                gb.GetSpyro();
                if (var_r29_1673 == (u32) M2C_ERROR(/* Read from unset register $r3 */)) {
                    Collided(sp348);
                } else {
                    goto block_22;
                }
            } else {
block_22:
                var_r28_1621 += 1;
                var_r30_1623 += 0x28;
                if (var_r28_1621 < 3) {
                    goto loop_14;
                }
            }
            temp_f3_1698 = this->unk16C;
            if (temp_f3_1698 < 400.0f) {
                var_f0_1706 = (10.0f * (400.0f * gUpdateTimeDelta)) + temp_f3_1698;
                if (var_f0_1706 < 400.0f) {

                } else {
                    var_f0_1706 = 400.0f;
                }
                if (var_f0_1706 > 0.0f) {

                } else {
                    var_f0_1706 = 0.0f;
                }
                this->unk16C = var_f0_1706;
            }
            MKModel_SetPosition(this->unk4, *((MKVector3 *) &sp2F8));
            sp58 = 0.0f;
            sp5C = -100.0f;
            sp60 = 0.0f;
            sp1E8 = (f64) sp58;
            sp1F0 = (f64) sp60;
            sp48 = sp2F8 + sp1E8;
            sp80 = 0.0f;
            sp78 = 0.0f;
            sp7C = 100.0f;
            sp50 = (f32) sp300 + (f32) sp1F0;
            sp208 = (f64) sp78;
            sp1F8 = sp48;
            sp200 = (f64) sp50;
            sp210 = (f64) sp80;
            temp_f0_1755 = sp2F8 + sp208;
            sp68 = temp_f0_1755;
            sp218 = temp_f0_1755;
            sp70 = (f32) sp300 + (f32) sp210;
            sp220 = (f64) sp70;
            if (MKCollision_RayCollide(*((MKVector3 *) &sp218), *((MKVector3 *) &sp1F8), (MKCollisionResult *) &sp348, (MKCollisionMode) 7, 0x0C000000) == 0) {
                if ((s32) M2C_FIELD(checked_cast<IceBossStompDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xFC) == 2) {
                    KDSound_Play3d(GS_IceBossAttack1, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
                } else {
                    KDSound_Play3d(GS_ElecBossStrikeEnd, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
                }
                ShatterIceShards();
                Disable();
            }
        }
    }
    if ((ManagedLight *) this->unk160 != NULL) {
        MKVector(0.0f, 500.0f, 0.0f);
        temp_r3_1813 = this->unk8 + 0x30;
        sp28 = M2C_FIELD(temp_r3_1813, f64 *, 0) + sp1C8;
        temp_r3_1822 = this->unk160;
        sp1D8 = sp28;
        sp30 = M2C_FIELD(temp_r3_1813, f32 *, 8) + sp1D0;
        temp_r3_1822->unk10 = sp28;
        temp_r3_1822->unk18 = (f64) sp30;
        temp_r3_1828 = temp_r3_1822->unk3C;
        sp1E0 = (f64) sp30;
        if (temp_r3_1828 != NULL) {
            M2C_FIELD(temp_r3_1828, f64 *, 0x10) = sp28;
            M2C_FIELD(temp_r3_1828, f64 *, 0x18) = (f64) sp30;
        }
        temp_r3_1840 = this->unk160;
        temp_f0_1841 = 1000.0f * MKRand_Float(&gViewSeed, 1.0f, 1.5f);
        temp_r3_1840->unk38 = temp_f0_1841;
        temp_r3_1843 = temp_r3_1840->unk3C;
        if (temp_r3_1843 != NULL) {
            M2C_FIELD(temp_r3_1843, f32 *, 0x20) = temp_f0_1841;
            M2C_FIELD(temp_r3_1843, f32 *, 0x24) = (f32) (temp_f0_1841 * temp_f0_1841);
            M2C_FIELD(temp_r3_1843, f32 *, 0x28) = (f32) (1.0f / temp_f0_1841);
            M2C_FIELD(temp_r3_1843, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_1843, f32 *, 0x24));
        }
    }
    UpdateIceCrystals();
    this->unk168 += 300.0f * gUpdateTimeDelta;
    temp_r4_1867 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
    temp_r3_1868 = this->unk8 + 0x30;
    sp2B8 = M2C_FIELD(temp_r4_1867, f64 *, 0x30);
    sp2C0 = M2C_FIELD(temp_r4_1867, f64 *, 0x38);
    sp38 = M2C_FIELD(temp_r3_1868, f64 *, 0) - sp2B8;
    sp1B8 = sp38;
    sp40 = M2C_FIELD(temp_r3_1868, f32 *, 8) - (f32) sp2C0;
    sp1C0 = (f64) sp40;
    temp_f1_1892 = ((f32) sp1C0 * (f32) sp1C0) + (((f32) sp1B8 * (f32) sp1B8) + (unksp1BC * unksp1BC));
    if ((temp_f1_1892 <= 4000000.0f) && ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL)) {
        temp_f27_1901 = 1.0f - (temp_f1_1892 / 4000000.0f);
        if (temp_f27_1901 > 0.0f) {
            sp32C = 0;
            temp_f26_1909 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            temp_f28_1914 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            MKVector(MKRand_Float(&gViewSeed, -1.0f, 1.0f), temp_f28_1914, temp_f26_1909);
            sp198.operator*(50.0f);
            sp18 = sp198 * (f64) temp_f27_1901;
            sp328 = 0x417;
            sp330 = sp18;
            sp20 = sp198.unk8 * temp_f27_1901;
            sp340 = 1;
            sp338 = (f64) sp20;
            sp1A8 = sp18;
            sp1B0 = (f64) sp20;
            M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp328, sp18);
        }
    }
    if (sp10 != NULL) {
        M2C_FIELD(sp10, u8 *, 4) = sp14;
    }
}
#endif

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void IceBossStomp::Collided(MKCollisionResult &arg0) {
    s8 spD1;
    s8 spD0;
    s32 spCC;
    f32 spC8;
    s32 spC4;
    s8 spC2;
    s8 spC1;
    s8 spC0;
    f64 spB8;                                       /* compiler-managed */
    f64 spB0;                                       /* compiler-managed */
    MKProp *spAC;
    s32 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    s32 sp84;
    s32 sp80;
    Matrix sp40;
    M2C_UNK sp3C;
    f64 sp38;
    f64 sp30;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    MKProp *temp_r4_2020;
    void *temp_r3_2068;
    void *var_r31_2071;

    this->unk14C &= ~0x10;
    if (MKModel_GetAttachment(this->unk4) != NULL) {
        MKModel_GetWorldMatrixWithAttachment(this->unk4, &sp40);
    } else {
        M2C_STRUCT_COPY((s32) &sp3C + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
    }
    sp84 = 0;
    temp_r4_2020 = this->unk130;
    sp18 = 0.0f;
    sp10 = 0.0f;
    sp14 = 0.0f;
    sp38 = (f64) sp18;
    sp30 = (f64) sp10;
    sp80 = 7;
    spA8 = 1;
    spAC = temp_r4_2020;
    sp88 = (f64) sp10;
    sp90 = (f64) sp18;
    spC0 = 0;
    spCC = 2;
    spC8 = 10.0f;
    spC1 = 0;
    spC2 = 1;
    spC4 = -1;
    sp98 = M2C_FIELD(&MKVector3::one, f64 *, 0);
    spA0 = M2C_FIELD(&MKVector3::one, f64 *, 8);
    spD0 = 0;
    if (temp_r4_2020 != NULL) {
        sp20.GetPos();
        spB0 = sp20;
        spB8 = sp28;
    } else {
        spB0 = 0.0f;
        unkspB4 = 0.0f;
        spB8 = 0.0f;
    }
    spD1 = 0;
    spC4 = GS_SpyroSpikeBurn;
    if (((u8) arg0.unk50 != 0) && (temp_r3_2068 = arg0.unk48, ((temp_r3_2068 == NULL) == 0)) && (var_r31_2071 = M2C_FIELD(temp_r3_2068, void **, 8), ((var_r31_2071 == NULL) == 0))) {

    } else {
        var_r31_2071 = NULL;
    }
    if (var_r31_2071 != NULL) {
        M2C_FIELD(M2C_FIELD(var_r31_2071, void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(var_r31_2071, &sp80);
    }
    if (var_r31_2071 == NULL) {
        ShatterIceShards();
        Disable();
    }
}
#endif

#if 0 // DRAFT: pointer/array required
void IceBossStomp::Fire(const MKVector3 &arg0, const MKVector3 &arg1, MKProp *arg2, int arg3, int arg4) {
    s8 sp1B0;
    s32 sp1AC;
    s32 sp1A8;
    s32 sp1A4;
    f32 sp1A0;
    s32 sp19C;
    s8 sp19B;
    s8 sp19A;
    s16 sp198;
    f32 sp194;
    f32 sp190;
    f32 sp18C;
    f32 sp188;
    f32 sp184;
    f32 sp180;
    f32 sp178;
    f32 sp174;
    f32 sp170;
    f32 sp168;
    f32 sp164;
    f32 sp160;
    Matrix sp120;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;                                       /* compiler-managed */
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
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    MKHeap *temp_r24_2146;
    MKHeap *var_r23_2130;
    ManagedLight *temp_r3_2167;
    ManagedLight *temp_r4_2159;
    f32 temp_f0_2276;
    f32 temp_f1_2275;
    f32 temp_f3_2278;
    f32 var_f4_2283;
    f32 var_f5_2350;
    f64 temp_f0_2246;
    f64 temp_f1_2289;
    f64 temp_f1_2295;
    f64 temp_f1_2299;
    s32 temp_r3_2133;
    s32 temp_r3_2318;
    s32 var_r0_2328;
    s32 var_r23_2410;
    void *temp_r3_2170;

    this->unk168 = 400.0f;
    this->unk16C = 0.0f;
    var_r23_2130 = this->unk164;
loop_4:
    if (var_r23_2130 != NULL) {
        temp_r24_2146 = var_r23_2130->unk0;
        if (temp_r24_2146 == NULL) {

        } else {
            temp_r3_2133 = temp_r24_2146->unk2C;
            if ((u32) temp_r3_2133 != 0U) {
                M2C_FIELD(M2C_FIELD(temp_r3_2133, void **, 0x44), M2C_UNK (**)(), 0x34)();
                temp_r24_2146->unk2C = 0;
            }
            var_r23_2130 += 4;
            goto loop_4;
        }
    }
loop_8:
    if ((MKHeap *) this->unk164->unk0 != NULL) {
        this->unk164 = (MKHeap *) &this->unk164->unk4;
        goto loop_8;
    }
    temp_r4_2159 = this->unk160;
    if (temp_r4_2159 != NULL) {
        gb.unk80->EnableLight(temp_r4_2159, 1U);
        temp_r3_2167 = this->unk160;
        temp_r3_2167->unk38 = 500.0f;
        temp_r3_2170 = temp_r3_2167->unk3C;
        if (temp_r3_2170 != NULL) {
            M2C_FIELD(temp_r3_2170, f32 *, 0x20) = 500.0f;
            M2C_FIELD(temp_r3_2170, f32 *, 0x24) = 250000.0f;
            M2C_FIELD(temp_r3_2170, f32 *, 0x28) = 0.002f;
            M2C_FIELD(temp_r3_2170, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_2170, f32 *, 0x24));
        }
    }
    sp160 = 0.0f;
    sp60 = 0.0f;
    sp164 = 0.0f;
    sp168 = 0.0f;
    sp170 = 0.0f;
    sp174 = 0.0f;
    sp178 = 0.0f;
    sp180 = 0.0f;
    sp184 = 0.0f;
    sp188 = 0.0f;
    sp18C = 1.0f;
    sp190 = 0.0f;
    sp194 = 0.0f;
    sp198 = 0;
    sp19A = 0;
    sp19B = 0;
    sp19C = 0;
    sp1A0 = 3.4028235e38f;
    sp1A4 = 0;
    sp1A8 = 0;
    sp1AC = -1;
    sp1B0 = 0;
    this->unkC8 = M2C_FIELD(&arg1, f64 *, 0);
    this->unkD0 = M2C_FIELD(&arg1, f64 *, 8);
    sp58 = 0.0f;
    sp5C = -100.0f;
    sp108 = M2C_FIELD(&arg0, f64 *, 0);
    sp98 = (f64) sp58;
    sp110 = M2C_FIELD(&arg0, f64 *, 8);
    spA0 = (f64) sp60;
    sp48 = sp108 + sp98;
    sp80 = 0.0f;
    sp78 = 0.0f;
    sp7C = 100.0f;
    sp50 = (f32) sp110 + (f32) spA0;
    spB8 = (f64) sp78;
    spA8 = sp48;
    spB0 = (f64) sp50;
    spC0 = (f64) sp80;
    temp_f0_2246 = sp108 + spB8;
    sp68 = temp_f0_2246;
    spC8 = temp_f0_2246;
    sp70 = (f32) sp110 + (f32) spC0;
    spD0 = (f64) sp70;
    if (MKCollision_RayCollide(*((MKVector3 *) &spC8), *((MKVector3 *) &spA8), (MKCollisionResult *) &sp160, (MKCollisionMode) 7, 0x0C000000) != 0) {
        sp108 = (f64) sp160;
        sp110 = (f64) sp168;
    }
    Projectile::Fire(*((MKVector3 *) &sp108), *((MKVector3 *) &this->unkC8), arg2, arg3, arg4);
    temp_f1_2275 = (f32) M2C_FIELD(this, f64 *, 0xC8);
    temp_f0_2276 = M2C_FIELD(this, f32 *, 0xCC);
    temp_f3_2278 = (f32) M2C_FIELD(this, f64 *, 0xD0);
    var_f4_2283 = (temp_f3_2278 * temp_f3_2278) + ((temp_f1_2275 * temp_f1_2275) + (temp_f0_2276 * temp_f0_2276));
    if (var_f4_2283 > 1e-12f) {
        if (var_f4_2283 > 0.0f) {
            temp_f1_2289 = __frsqrte(var_f4_2283);
            temp_f1_2295 = 0.5 * temp_f1_2289 * -(((f64) var_f4_2283 * (temp_f1_2289 * temp_f1_2289)) - 3.0);
            temp_f1_2299 = 0.5 * temp_f1_2295 * -(((f64) var_f4_2283 * (temp_f1_2295 * temp_f1_2295)) - 3.0);
            var_f4_2283 = (f32) ((f64) var_f4_2283 * (0.5 * temp_f1_2299 * -(((f64) var_f4_2283 * (temp_f1_2299 * temp_f1_2299)) - 3.0)));
        } else if (var_f4_2283 < M2C_BITWISE(f32, 0.0)) {
            var_f4_2283 = __float_nan;
        } else {
            sp10 = var_f4_2283;
            temp_r3_2318 = M2C_BITWISE(s32, sp10) & 0x7F800000;
            switch (temp_r3_2318) {                 /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_2328 = 1;
                } else {
                    var_r0_2328 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_2328 = 5;
                } else {
                    var_r0_2328 = 3;
                }
                break;
            default:
                var_r0_2328 = 4;
                break;
            }
            if (var_r0_2328 == 1) {
                var_f4_2283 = __float_nan;
            }
        }
        var_f5_2350 = 1.0f / var_f4_2283;
    } else {
        var_f5_2350 = 0.0f;
    }
    sp38 = (f32) M2C_FIELD(this, f64 *, 0xC8) * var_f5_2350;
    sp3C = M2C_FIELD(this, f32 *, 0xCC) * var_f5_2350;
    sp40 = (f32) M2C_FIELD(this, f64 *, 0xD0) * var_f5_2350;
    spF8 = (f64) sp38;
    sp100 = (f64) sp40;
    spE8 = M2C_FIELD(&MKVector3::up, f64 *, 0);
    spF0 = M2C_FIELD(&MKVector3::up, f64 *, 8);
    KDMath_BuildMatrixFromFwd(&sp120, *((MKVector3 *) &spF8), (MKVector3 *) &spE8);
    sp120.unk30 = (f32) sp108;
    sp120.unk34 = unksp10C;
    sp120.unk38 = (f32) sp110;
    sp120.unk3C = 1.0f;
    MKModel_SetWorldMatrix(this->unk4, sp120);
    this->unk140 = 2.0f;
    EmitSnowRing();
    ((KDInput *) (gb.unk0->GetInput()))->RumblePlay3D(0.8f, 0.8f, 0.04f, this->unk8 + 0x30, 50.0f, 0, 4.0f, 0U);
    var_r23_2410 = 0;
    sp30 = 0.0f;
    sp2C = 0.0f;
    sp28 = -500.0f * 2.0f;
    spE0 = (f64) sp30;
    spD8 = (f64) sp28;
    do {
        SpawnIceCrystal(*((MKVector3 *) &spD8));
        sp18 = 500.0f;
        sp1C = 0.0f;
        sp20 = 0.0f;
        sp88 = (f64) sp18;
        sp90 = (f64) sp20;
        spD8 += sp88;
        var_r23_2410 += 1;
        spE0 = (f32) spE0 + (f32) sp90;
    } while (var_r23_2410 < 5);
}
#endif

#if 0 // DRAFT: pointer/array required
void IceBossStomp::LoadDone() {
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
    MKHeap *temp_r3_2508;
    MKHeap *temp_r3_2530;
    MKHeap *temp_r5_2536;
    MKHeap *var_r3_2515;
    MKHeap *var_r5_2524;
    ManagedLight *temp_r4_2501;
    s32 var_ctr_2528;

    Projectile::LoadDone();
    sp20 = 0.0f;
    sp30 = 0.0f;
    sp8 = 0.2f;
    spC = 0.2f;
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
    this->unk160 = gb.unk80->AllocManagedLight(*((MKVector3 *) &sp58), *((MKVector3 *) &sp48), *((MKVector4 *) &sp38), 800.0f, lit_642, lit_643);
    temp_r4_2501 = this->unk160;
    if (temp_r4_2501 != NULL) {
        gb.unk80->EnableLight(temp_r4_2501, 0U);
    }
    temp_r3_2508 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_2508 != NULL) {
        var_r3_2515 = ((MKHeap *) (temp_r3_2508->Current()))->Alloc(0xA30, NULL, 0);
    } else {
        var_r3_2515 = malloc(0xA30);
    }
    this->unk164 = var_r3_2515;
    var_r5_2524 = this->unk164;
    this->unk164 = var_r5_2524 + 0x960;
    M2C_FIELD(var_r5_2524, s32 *, 0x960) = 0;
    var_ctr_2528 = 0x32;
    do {
        temp_r3_2530 = this->unk164;
        this->unk164 = (MKHeap *) &temp_r3_2530->unk4;
        temp_r3_2530->unk4 = (s32) var_r5_2524;
        var_r5_2524 += 0x30;
        var_ctr_2528 -= 1;
    } while (var_ctr_2528 != 0);
    temp_r5_2536 = this->unk164;
    this->unk164 = (MKHeap *) &temp_r5_2536->unk4;
    temp_r5_2536->unk4 = 0;
    this->unk170 = checked_cast<KDEnvParticleSystem *, MKProp>(gMK->CreateProp("SnowPuffPS"));
}
#endif

#if 0 // DRAFT: illegal operand 'IceBossStomp *'
MKProp *IceBossStomp::CreateInstance(int arg0) {
    MKProp *temp_r3_2569;
    MKProp *temp_r3_2580;

    switch (this) {                                 /* irregular */
    case 2:
        temp_r3_2569 = pIceBossStompDescriptor->CreateInstance();
        if (temp_r3_2569 != NULL) {
            M2C_FIELD(temp_r3_2569->__vptr, M2C_UNK (**)(), 0x20)();
            return temp_r3_2569;
        }
block_8:
    default:
        return NULL;
    case 1:
        temp_r3_2580 = pElecBossStompDescriptor->CreateInstance();
        if (temp_r3_2580 != NULL) {
            M2C_FIELD(temp_r3_2580->__vptr, M2C_UNK (**)(), 0x20)();
            return temp_r3_2580;
        }
        goto block_8;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
void IceBossStompDescriptor::Resolve() {
    MKPropDescriptor::Resolve();
    this->unkF0 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>(gMK->FindDescriptor(this->unkF8));
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void IceBossStompDescriptor::LoadDone() {
    s32 temp_r0_2656;
    s32 var_r31_2640;
    void *temp_r3_2645;

    GamePropDescriptor::LoadDone();
    pIceBossStompDescriptor = (MKPropDescriptor *) this;
    this->unkF4 = checked_cast<IceBitsPS *, MKProp>(gMK->CreateProp("IceBitsPS"));
    var_r31_2640 = 0;
    do {
        temp_r3_2645 = checked_cast<PooledShatterProp *, MKProp>(gMK->CreateProp(this->unkF8));
        if (temp_r3_2645 != NULL) {
            M2C_FIELD(M2C_FIELD(temp_r3_2645, void **, 0x44), M2C_UNK (**)(), 0x34)();
        }
        var_r31_2640 += 1;
    } while (var_r31_2640 < 5);
    temp_r0_2656 = this->unkFC;
    switch (temp_r0_2656) {                         /* irregular */
    case 1:
        pElecBossStompDescriptor = (MKPropDescriptor *) this;
        return;
    case 2:
        pIceBossStompDescriptor = (MKPropDescriptor *) this;
        return;
    }
}
#endif

#if 0 // DRAFT: illegal use of non-static member
s32 IceBossStompDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_2685;

    var_r31_2685 = 0;
    if ((ProjectileDescriptor::LoadLine(arg0) != 0) || (arg0->LoadString("CrystalName", &this->unkF8, 0) != 0) || (DataMap_LoadLine(arg0, "Element", &ElementTypeDataMap, (u32 *) &this->unkFC) != 0)) {
        var_r31_2685 = 1;
    }
    return var_r31_2685;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void IceBossStompDescriptor::Deinit() {
    pIceBossStompDescriptor = NULL;
    KDPropExDescriptor::Deinit();
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void IceBossStompDescriptor::Init() {
    ProjectileDescriptor::Init();
    this->unkF8 = "p3018_bossicecharge";
}
#endif
