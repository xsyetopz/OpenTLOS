#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKFFTWater.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKLevelChunk.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKOcean.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/Level.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_enums.h"
#include "dolphin/os.h"
#include "common/Source/MKView.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKModel_GC.h"
#include <m2c_macros.h>

M2C_UNK __destroy_arr(void *, MKProp *(*)(MKProp *, s16), M2C_UNK, M2C_UNK); /* extern */
f64 fmod(f32, f64);                                 /* extern */
M2C_UNK free(BoundingVolume *);                     /* extern */
BoundingVolume *malloc(s32);                        /* extern */
M2C_UNK qsort(M2C_UNK *, M2C_UNK, s32 (*)(void *, void *)); /* extern */
s32 stricmp(s8 *, s8 *);                            /* extern */
extern void *gMK;
static s32 lit_988 = 8;

#if 0 // DRAFT: undefined identifier 'unk58'
void MKDistanceLevelChunk::DL_Draw_DrawVeryLastLayer() {
    MKPropDescriptor *var_r30_90;
    void *var_r29_93;

    var_r30_90 = this->unk2D44;
loop_5:
    if (var_r30_90 != NULL) {
        var_r29_93 = var_r30_90->unk58;
loop_3:
        if (var_r29_93 != NULL) {
            M2C_FIELD(M2C_FIELD(var_r29_93, void **, 0x44), M2C_UNK (**)(void *), 0x28)(var_r29_93);
            var_r29_93 = M2C_FIELD(var_r29_93, void **, 0x3C);
            goto loop_3;
        }
        var_r30_90->unk58 = NULL;
        var_r30_90 = var_r30_90->unk4C;
        goto loop_5;
    }
    this->unk2D44 = NULL;
}
#endif

void MKDistanceLevelChunk::DL_Draw_DrawLastLayer() {
    void *var_r29_131;
    void *var_r30_128;

    var_r30_128 = this->unk2D48;
loop_5:
    if (var_r30_128 != NULL) {
        var_r29_131 = M2C_FIELD(var_r30_128, void **, 0x54);
loop_3:
        if (var_r29_131 != NULL) {
            M2C_FIELD(M2C_FIELD(var_r29_131, void **, 0x44), M2C_UNK (**)(void *), 0x28)(var_r29_131);
            var_r29_131 = M2C_FIELD(var_r29_131, void **, 0x3C);
            goto loop_3;
        }
        M2C_FIELD(var_r30_128, void **, 0x54) = NULL;
        var_r30_128 = M2C_FIELD(var_r30_128, void **, 0x48);
        goto loop_5;
    }
    this->unk2D48 = NULL;
}

#if 0 // DRAFT: illegal implicit conversion from 'MKDistanceLevelChunk' to
void MKDistanceLevelChunk::DL_Draw_AboveWaterLayer() {
    f32 var_r30_165;
    s32 temp_cr0_eq_176;
    s32 var_r31_166;
    void *temp_r3_170;

    var_r30_165 = this->unk258;
    var_r31_166 = M2C_BITWISE(s32, var_r30_165) * 8;
loop_2:
    temp_cr0_eq_176 = M2C_BITWISE(s32, var_r30_165) == 0;
    var_r30_165 = M2C_BITWISE(f32, (M2C_BITWISE(s32, var_r30_165) - 1));
    var_r31_166 -= 8;
    if (temp_cr0_eq_176 == 0) {
        temp_r3_170 = *(this + (var_r31_166 + 0xA68));
        M2C_FIELD(M2C_FIELD(temp_r3_170, void **, 0x44), M2C_UNK (**)(void *), 0x28)(temp_r3_170);
        goto loop_2;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKDistanceLevelChunk' to
void MKDistanceLevelChunk::DL_Draw_BelowWaterLayer() {
    s32 temp_cr0_eq_206;
    s32 var_r30_195;
    s32 var_r31_196;
    void *temp_r3_200;

    var_r30_195 = this->unk264;
    var_r31_196 = var_r30_195 * 8;
loop_2:
    temp_cr0_eq_206 = var_r30_195 == 0;
    var_r30_195 -= 1;
    var_r31_196 -= 8;
    if (temp_cr0_eq_206 == 0) {
        temp_r3_200 = *(this + (var_r31_196 + 0x1A08));
        M2C_FIELD(M2C_FIELD(temp_r3_200, void **, 0x44), M2C_UNK (**)(void *), 0x28)(temp_r3_200);
        goto loop_2;
    }
}
#endif

void MKDistanceLevelChunk::DL_Draw_SolidLayer() {
    void *var_r29_229;
    void *var_r30_226;

    var_r30_226 = this->unk2D44;
loop_5:
    if (var_r30_226 != NULL) {
        var_r29_229 = M2C_FIELD(var_r30_226, void **, 0x50);
loop_3:
        if (var_r29_229 != NULL) {
            M2C_FIELD(M2C_FIELD(var_r29_229, void **, 0x44), M2C_UNK (**)(void *), 0x28)(var_r29_229);
            var_r29_229 = M2C_FIELD(var_r29_229, void **, 0x3C);
            goto loop_3;
        }
        M2C_FIELD(var_r30_226, void **, 0x50) = NULL;
        var_r30_226 = M2C_FIELD(var_r30_226, void **, 0x44);
        goto loop_5;
    }
    this->unk2D44 = NULL;
}

void MKDistanceLevelChunk::DL_Begin() {
    this->unk2D44 = NULL;
    this->unk2D48 = NULL;
    this->unk2D44 = NULL;
    this->unk2D48 = NULL;
    this->unk2D4C = NULL;
}

#if 0 // DRAFT: undefined identifier 'unk44'
void MKDistanceLevelChunk::DL_Init(MKPropDescriptor *arg0) {
    arg0->unk44 = NULL;
    arg0->unk50 = NULL;
    arg0->unk48 = NULL;
    arg0->unk54 = NULL;
    arg0->unk4C = NULL;
    arg0->unk58 = NULL;
}
#endif

void MKDistanceLevelChunk::DrawProps(int arg0) {
    if (this->unk134 & 1) {
        switch (arg0) {                             /* irregular */
        case 0:
            DL_Draw_SolidLayer();
            return;
        case 1:
            DL_Draw_BelowWaterLayer();
            return;
        case 2:
            DL_Draw_AboveWaterLayer();
            return;
        case 3:
            DL_Draw_DrawLastLayer();
            return;
        case 4:
            DL_Draw_DrawVeryLastLayer();
            break;
        }
    }
}

#if 0 // DRAFT: undefined identifier '__vptr'
s32 MKDistanceLevelChunk::GetPropsInRange(MKProp **arg0, int arg1, const MKVector3 &arg2, float arg3, int arg4, bool arg5) {
    f32 temp_f2_349;
    f32 temp_f2_391;
    f32 temp_f3_346;
    f32 temp_f3_388;
    f32 temp_f4_344;
    f32 temp_f4_386;
    f32 temp_f5_325;
    f32 var_r11_326;
    f32 var_r9_367;
    s32 var_r10_328;
    s32 var_r3_369;
    s32 var_r8_329;
    void *temp_r8_379;
    void *temp_r9_339;

    temp_f5_325 = arg3 * arg3;
    var_r11_326 = this->unk2A2C.unk20;
    var_r10_328 = 0;
    var_r8_329 = 0;
loop_6:
    if ((M2C_BITWISE(u32, var_r11_326) != &this->unk29E0.__vptr) && (var_r10_328 < arg1)) {
        if ((arg4 == -1) || (M2C_FIELD(M2C_FIELD(var_r11_326, void **, 0), s32 *, 0xC) & arg4)) {
            temp_r9_339 = M2C_FIELD(var_r11_326, void **, 8);
            temp_f4_344 = M2C_FIELD(temp_r9_339, f32 *, 0x34) - arg2.unk4;
            temp_f3_346 = M2C_FIELD(temp_r9_339, f32 *, 0x30) - arg2.unk0;
            temp_f2_349 = M2C_FIELD(temp_r9_339, f32 *, 0x38) - arg2.unk8;
            if (((temp_f2_349 * temp_f2_349) + ((temp_f3_346 * temp_f3_346) + (temp_f4_344 * temp_f4_344))) < temp_f5_325) {
                *(arg0 + var_r8_329) = var_r11_326;
                var_r10_328 += 1;
                var_r8_329 += 4;
            }
        }
        var_r11_326 = M2C_FIELD(var_r11_326, f32 *, 0x28);
        goto loop_6;
    }
    var_r9_367 = this->unk2A78.unk20;
    var_r3_369 = var_r10_328 * 4;
loop_15:
    if ((M2C_BITWISE(u32, var_r9_367) != &this->unk2A2C.__vptr) && (var_r10_328 < arg1)) {
        if ((arg4 == -1) || (M2C_FIELD(M2C_FIELD(var_r9_367, void **, 0), s32 *, 0xC) & arg4)) {
            temp_r8_379 = M2C_FIELD(var_r9_367, void **, 8);
            if (temp_r8_379 != NULL) {
                temp_f4_386 = M2C_FIELD(temp_r8_379, f32 *, 0x34) - arg2.unk4;
                temp_f3_388 = M2C_FIELD(temp_r8_379, f32 *, 0x30) - arg2.unk0;
                temp_f2_391 = M2C_FIELD(temp_r8_379, f32 *, 0x38) - arg2.unk8;
                if (((temp_f2_391 * temp_f2_391) + ((temp_f3_388 * temp_f3_388) + (temp_f4_386 * temp_f4_386))) < temp_f5_325) {
                    *(arg0 + var_r3_369) = var_r9_367;
                    var_r10_328 += 1;
                    var_r3_369 += 4;
                }
            }
        }
        var_r9_367 = M2C_FIELD(var_r9_367, f32 *, 0x28);
        goto loop_15;
    }
    return var_r10_328;
}
#endif

f32 MKDistanceLevelChunk::GetDistanceFromPoint(const MKVector3 &arg0) {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKHeap **temp_r3_447;
    f32 temp_f0_474;
    f32 temp_f27_434;
    f32 temp_f28_436;
    f32 temp_f29_437;
    f32 temp_f2_466;
    f32 temp_f2_470;
    f32 temp_f3_467;
    f32 var_f30_430;
    s32 var_r29_433;
    s32 var_r31_435;
    void *temp_r3_439;
    void *var_r28_440;

    var_f30_430 = 3.4028235e38f;
    var_r29_433 = 0;
    temp_f27_434 = arg0.unk4;
    var_r31_435 = 0;
    temp_f28_436 = arg0.unk0;
    temp_f29_437 = arg0.unk8;
    do {
        temp_r3_439 = this + var_r31_435;
        var_r28_440 = M2C_FIELD(temp_r3_439, void **, 0x2AC4);
loop_5:
        if (var_r28_440 != (void *) (((u8 *) temp_r3_439) + 0x2AC4)) {
            temp_r3_447 = MKModel_GetBoundingVolume(M2C_FIELD(var_r28_440, MKModel **, 4), (SubObjectType) 0, -1);
            sp8 = (0.5f * M2C_FIELD(temp_r3_447, f32 *, 0x10)) + M2C_FIELD(temp_r3_447, f32 *, 0);
            spC = (0.5f * M2C_FIELD(temp_r3_447, f32 *, 0x14)) + M2C_FIELD(temp_r3_447, f32 *, 4);
            sp10 = (0.5f * M2C_FIELD(temp_r3_447, f32 *, 0x18)) + M2C_FIELD(temp_r3_447, f32 *, 8);
            sp18 = (f64) sp8;
            sp20 = (f64) sp10;
            temp_f2_466 = temp_f27_434 - (*(f32 *) ((u8 *) &sp18 + 0x4));
            temp_f3_467 = temp_f28_436 - (f32) sp18;
            temp_f2_470 = temp_f29_437 - (f32) sp20;
            temp_f0_474 = (temp_f2_470 * temp_f2_470) + ((temp_f3_467 * temp_f3_467) + (temp_f2_466 * temp_f2_466));
            if (temp_f0_474 < var_f30_430) {
                var_f30_430 = temp_f0_474;
            }
            var_r28_440 = M2C_FIELD(var_r28_440, void **, 0);
            goto loop_5;
        }
        var_r29_433 += 1;
        var_r31_435 += 0x50;
    } while (var_r29_433 < 8);
    return var_f30_430;
}

#if 0 // DRAFT: function call 'stricmp(const char *)' does not match
void MKDistanceLevelChunk::SetTerrainUserData(const char *arg0, void *arg1) {
    s32 var_r29_515;
    s32 var_r31_516;
    void *temp_r3_518;
    void *var_r28_519;

    var_r29_515 = 0;
    var_r31_516 = 0;
loop_1:
    temp_r3_518 = this + var_r31_516;
    var_r28_519 = M2C_FIELD(temp_r3_518, void **, 0x2AC4);
loop_5:
    if (var_r28_519 == (void *) (((u8 *) temp_r3_518) + 0x2AC4)) {
        var_r29_515 += 1;
        var_r31_516 += 0x50;
        if (var_r29_515 >= 8) {
            return;
        }
        goto loop_1;
    }
    MKModel_GetName(M2C_FIELD(var_r28_519, MKModel **, 4));
    if (stricmp(arg0) == 0) {
        M2C_FIELD(var_r28_519, void **, 0x4C) = arg1;
        return;
    }
    var_r28_519 = M2C_FIELD(var_r28_519, void **, 0);
    goto loop_5;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'void (*)(MKModel *, unsigned short *,
void MKDistanceLevelChunk::SetTerrainDrawCallback(void (*arg0)(MKModel *, unsigned short *, void *)) {
    this->unk144 = M2C_BITWISE(f32, arg0);
}
#endif

#if 0 // DRAFT: function call 'stricmp(const char *)' does not match
void MKDistanceLevelChunk::EnableTerrainModel(const char *arg0, bool arg1) {
    s32 var_r29_565;
    s32 var_r31_566;
    void *temp_r3_568;
    void *var_r28_569;

    var_r29_565 = 0;
    var_r31_566 = 0;
loop_1:
    temp_r3_568 = this + var_r31_566;
    var_r28_569 = M2C_FIELD(temp_r3_568, void **, 0x2AC4);
loop_7:
    if (var_r28_569 == (void *) (((u8 *) temp_r3_568) + 0x2AC4)) {
        var_r29_565 += 1;
        var_r31_566 += 0x50;
        if (var_r29_565 >= 8) {
            return;
        }
        goto loop_1;
    }
    MKModel_GetName(M2C_FIELD(var_r28_569, MKModel **, 4));
    if (stricmp(arg0) == 0) {
        if (arg1 != 0) {
            M2C_FIELD(var_r28_569, s32 *, 8) = (s32) (M2C_FIELD(var_r28_569, s32 *, 8) & 0x7FFFFFFF);
            return;
        }
        M2C_FIELD(var_r28_569, s32 *, 8) = (s32) (M2C_FIELD(var_r28_569, s32 *, 8) | 0x80000000);
        return;
    }
    var_r28_569 = M2C_FIELD(var_r28_569, void **, 0);
    goto loop_7;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk1C'
void MKDistanceLevelChunk::AddPropToDrawList(MKProp *arg0, int arg1, float arg2, float arg3) {
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
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    Matrix *temp_r3_711;
    Matrix *temp_r3_749;
    Matrix *temp_r3_799;
    Matrix *temp_r3_837;
    f32 temp_f0_624;
    f32 temp_f2_627;
    f32 temp_r3_704;
    f32 temp_r3_830;
    f32 var_f1_640;
    f32 var_f1_651;
    f64 *temp_r5_713;
    f64 *temp_r5_751;
    f64 *temp_r5_801;
    f64 *temp_r5_839;
    f64 temp_f1_648;
    f64 temp_f1_714;
    f64 temp_f1_752;
    f64 temp_f1_802;
    f64 temp_f1_840;
    s32 temp_r3_662;
    s32 temp_r3_742;
    s32 temp_r3_792;
    s32 var_r0_630;
    void *temp_r29_709;
    void *temp_r29_747;
    void *temp_r29_797;
    void *temp_r29_835;
    void *temp_r3_665;
    void *temp_r3_683;
    void *temp_r3_868;
    void *temp_r4_712;
    void *temp_r4_750;
    void *temp_r4_800;
    void *temp_r4_838;

    temp_f0_624 = 1.0f - (arg2 / arg3);
    temp_f2_627 = 8.0f * (1.0f - (temp_f0_624 * temp_f0_624));
    var_r0_630 = (s32) temp_f2_627;
    if ((s32) lit_988 < var_r0_630) {
        var_r0_630 = lit_988;
    }
    arg0->unk1C = (u16) (s8) var_r0_630;
    if ((u16) arg0->unk1C != 8) {
        var_f1_640 = 0.0f;
        if (var_f1_640 > temp_f2_627) {

        } else {
            var_f1_640 = temp_f2_627;
        }
        temp_f1_648 = fmod(var_f1_640, 1.0);
        arg0->unk24 = arg2;
        var_f1_651 = 1.0f;
        arg0->unk1E = (s16) arg1;
        if ((this->unk13C & 1) && ((u16) arg0->unk1C == 7)) {
            var_f1_651 = 1.0f - (f32) temp_f1_648;
        }
        arg0->unk20 = var_f1_651;
        temp_r3_662 = arg0->unk10;
        if (temp_r3_662 & 0x100) {
            temp_r3_665 = arg0->unk0;
            if ((MKProp *) M2C_FIELD(temp_r3_665, MKProp **, 0x54) == NULL) {
                M2C_FIELD(temp_r3_665, void **, 0x48) = (void *) this->unk2D48;
                this->unk2D48 = arg0->unk0;
            }
            arg0->unk3C = M2C_FIELD(arg0->unk0, MKProp **, 0x54);
            M2C_FIELD(arg0->unk0, MKProp **, 0x54) = arg0;
            return;
        }
        if (temp_r3_662 & 0x4000) {
            temp_r3_683 = arg0->unk0;
            if ((MKProp *) M2C_FIELD(temp_r3_683, MKProp **, 0x58) == NULL) {
                M2C_FIELD(temp_r3_683, MKPropDescriptor **, 0x4C) = (MKPropDescriptor *) this->unk2D44;
                this->unk2D44 = (MKPropDescriptor *) arg0->unk0;
            }
            arg0->unk3C = M2C_FIELD(arg0->unk0, MKProp **, 0x58);
            M2C_FIELD(arg0->unk0, MKProp **, 0x58) = arg0;
            return;
        }
        if (temp_r3_662 & 0x1000) {
            if ((u8) M2C_FIELD(this, u8 *, 0x150) != 0) {
                temp_r3_704 = this->unk258;
                this->unk258 = M2C_BITWISE(f32, (M2C_BITWISE(s32, temp_r3_704) + 1));
                temp_r29_709 = this + ((M2C_BITWISE(s32, temp_r3_704) * 8) + 0xA68);
                M2C_FIELD(temp_r29_709, MKProp **, 0) = arg0;
                temp_r3_711 = MKView_GetCameraMatrix();
                temp_r4_712 = arg0->unk8;
                temp_r5_713 = temp_r3_711 + 0x30;
                temp_f1_714 = M2C_FIELD(temp_r4_712, f64 *, 0x30);
                spB8 = temp_f1_714;
                spC0 = M2C_FIELD(temp_r4_712, f64 *, 0x38);
                sp38 = temp_f1_714 - *temp_r5_713;
                spA8 = sp38;
                sp40 = (f32) spC0 - temp_r3_711->unk38;
                spB0 = (f64) sp40;
                M2C_FIELD(temp_r29_709, f32 *, 4) = (f32) (((f32) spB0 * temp_r3_711->unk28) + (((f32) spA8 * temp_r3_711->unk20) + ((*(f32 *) ((u8 *) &spA8 + 0x4)) * temp_r3_711->unk24)));
                return;
            }
            temp_r3_742 = this->unk264;
            this->unk264 = temp_r3_742 + 1;
            temp_r29_747 = this + ((temp_r3_742 * 8) + 0x1A08);
            M2C_FIELD(temp_r29_747, MKProp **, 0) = arg0;
            temp_r3_749 = MKView_GetCameraMatrix();
            temp_r4_750 = arg0->unk8;
            temp_r5_751 = temp_r3_749 + 0x30;
            temp_f1_752 = M2C_FIELD(temp_r4_750, f64 *, 0x30);
            sp98 = temp_f1_752;
            spA0 = M2C_FIELD(temp_r4_750, f64 *, 0x38);
            sp28 = temp_f1_752 - *temp_r5_751;
            sp88 = sp28;
            sp30 = (f32) spA0 - temp_r3_749->unk38;
            sp90 = (f64) sp30;
            M2C_FIELD(temp_r29_747, f32 *, 4) = (f32) (((f32) sp90 * temp_r3_749->unk28) + (((f32) sp88 * temp_r3_749->unk20) + ((*(f32 *) ((u8 *) &sp88 + 0x4)) * temp_r3_749->unk24)));
            return;
        }
        if ((temp_r3_662 & 0x480) || ((this->unk13C & 2) && (arg0->unk20 != 1.0f))) {
            if (temp_r3_662 & 0x200) {
                temp_r3_792 = this->unk264;
                this->unk264 = temp_r3_792 + 1;
                temp_r29_797 = this + ((temp_r3_792 * 8) + 0x1A08);
                M2C_FIELD(temp_r29_797, MKProp **, 0) = arg0;
                temp_r3_799 = MKView_GetCameraMatrix();
                temp_r4_800 = arg0->unk8;
                temp_r5_801 = temp_r3_799 + 0x30;
                temp_f1_802 = M2C_FIELD(temp_r4_800, f64 *, 0x30);
                sp78 = temp_f1_802;
                sp80 = M2C_FIELD(temp_r4_800, f64 *, 0x38);
                sp18 = temp_f1_802 - *temp_r5_801;
                sp68 = sp18;
                sp20 = (f32) sp80 - temp_r3_799->unk38;
                sp70 = (f64) sp20;
                M2C_FIELD(temp_r29_797, f32 *, 4) = (f32) (((f32) sp70 * temp_r3_799->unk28) + (((f32) sp68 * temp_r3_799->unk20) + ((*(f32 *) ((u8 *) &sp68 + 0x4)) * temp_r3_799->unk24)));
                return;
            }
            temp_r3_830 = this->unk258;
            this->unk258 = M2C_BITWISE(f32, (M2C_BITWISE(s32, temp_r3_830) + 1));
            temp_r29_835 = this + ((M2C_BITWISE(s32, temp_r3_830) * 8) + 0xA68);
            M2C_FIELD(temp_r29_835, MKProp **, 0) = arg0;
            temp_r3_837 = MKView_GetCameraMatrix();
            temp_r4_838 = arg0->unk8;
            temp_r5_839 = temp_r3_837 + 0x30;
            temp_f1_840 = M2C_FIELD(temp_r4_838, f64 *, 0x30);
            sp58 = temp_f1_840;
            sp60 = M2C_FIELD(temp_r4_838, f64 *, 0x38);
            sp8 = temp_f1_840 - *temp_r5_839;
            sp48 = sp8;
            sp10 = (f32) sp60 - temp_r3_837->unk38;
            sp50 = (f64) sp10;
            M2C_FIELD(temp_r29_835, f32 *, 4) = (f32) (((f32) sp50 * temp_r3_837->unk28) + (((f32) sp48 * temp_r3_837->unk20) + ((*(f32 *) ((u8 *) &sp48 + 0x4)) * temp_r3_837->unk24)));
            return;
        }
        temp_r3_868 = arg0->unk0;
        if ((MKProp *) M2C_FIELD(temp_r3_868, MKProp **, 0x50) == NULL) {
            M2C_FIELD(temp_r3_868, void **, 0x44) = (void *) this->unk2D44;
            this->unk2D44 = arg0->unk0;
        }
        arg0->unk3C = M2C_FIELD(arg0->unk0, MKProp **, 0x50);
        M2C_FIELD(arg0->unk0, MKProp **, 0x50) = arg0;
    }
}
#endif

void MKDistanceLevelChunk::CheckPropVisRecursive(SMNode *arg0, int arg1) {
    f64 sp10;
    f64 sp8;
    MKProp *temp_r4_979;
    MKProp *temp_r6_905;
    SMNode *temp_r4_989;
    SMNode *temp_r4_996;
    f32 temp_f0_961;
    f32 temp_f2_939;
    f32 temp_f4_943;
    f32 temp_f4_951;
    f32 temp_f5_947;
    f32 var_f30_907;
    f32 var_f31_904;
    f32 var_f6_950;
    s16 temp_r3_972;
    s32 temp_r4_911;
    s32 var_r31_908;
    u8 var_r3_912;
    void *temp_r3_930;

    var_f31_904 = 0.0f;
    temp_r6_905 = arg0->unk28;
    var_f30_907 = 0.0f;
    var_r31_908 = arg1;
    if (temp_r6_905 != NULL) {
        temp_r4_911 = temp_r6_905->unk18;
        var_r3_912 = 0;
        if (!(temp_r4_911 & 0x80000000) && (temp_r4_911 & this->unk14.unk68 & 0x7FFFFFFF) && !(temp_r4_911 & M2C_BITWISE(s32, this->unk14.unk6C) & 0x7FFFFFFF)) {
            var_r3_912 = 1;
        }
        if ((var_r3_912 != 0) && !(temp_r6_905->unk10 & 8)) {
            temp_r3_930 = temp_r6_905->unk8;
            sp8 = M2C_FIELD(temp_r3_930, f64 *, 0x30);
            sp10 = M2C_FIELD(temp_r3_930, f64 *, 0x38);
            temp_f2_939 = (*(f32 *) ((u8 *) &sp8 + 0x4)) - this->unk254;
            temp_f4_943 = (f32) sp8 - this->unk250;
            temp_f5_947 = (f32) sp10 - this->unk250;
            var_f6_950 = M2C_FIELD(gMK, f32 *, 8);
            temp_f4_951 = M2C_FIELD(temp_r6_905->unk0, f32 *, 8) * M2C_FIELD(gMK, f32 *, 4);
            var_f31_904 = (temp_f5_947 * temp_f5_947) + ((temp_f4_943 * temp_f4_943) + (temp_f2_939 * temp_f2_939));
            if (var_f6_950 > temp_f4_951) {

            } else {
                var_f6_950 = temp_f4_951;
            }
            temp_f0_961 = var_f6_950 * var_f6_950;
            var_f30_907 = temp_f0_961;
            M2C_ERROR(/* unknown instruction: cror 0x2, 0x1, 0x2 */);
            if (var_f31_904 != temp_f0_961) {
                goto block_11;
            }
        }
    } else {
block_11:
        if (!(var_r31_908 & 1)) {
            temp_r3_972 = MKView_VisibilityTest(*((BoundingVolume *) arg0), Matrix::identity);
            if (temp_r3_972 != 0) {
                if (temp_r3_972 == 1) {
                    var_r31_908 |= 1;
                }
                goto block_15;
            }
        } else {
block_15:
            temp_r4_979 = arg0->unk28;
            if (temp_r4_979 != NULL) {
                AddPropToDrawList(temp_r4_979, var_r31_908, var_f31_904, var_f30_907);
                return;
            }
            temp_r4_989 = arg0->unk20;
            if (temp_r4_989 != NULL) {
                CheckPropVisRecursive(temp_r4_989, var_r31_908);
            }
            temp_r4_996 = arg0->unk24;
            if (temp_r4_996 != NULL) {
                CheckPropVisRecursive(temp_r4_996, var_r31_908);
            }
        }
    }
}

#if 0 // DRAFT: undefined identifier '__vptr'
void MKDistanceLevelChunk::CalcGlobalPropVis() {
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
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    MKPropDescriptor *temp_r3_1051;
    MKPropDescriptor *temp_r3_1069;
    MKPropDescriptor *temp_r3_1168;
    MKPropDescriptor *temp_r3_1264;
    Matrix *temp_r3_1097;
    Matrix *temp_r3_1135;
    Matrix *temp_r3_1195;
    Matrix *temp_r3_1233;
    f32 temp_r3_1090;
    f32 temp_r3_1226;
    f32 var_r31_1023;
    f64 *temp_r5_1099;
    f64 *temp_r5_1137;
    f64 *temp_r5_1197;
    f64 *temp_r5_1235;
    f64 temp_f1_1100;
    f64 temp_f1_1138;
    f64 temp_f1_1198;
    f64 temp_f1_1236;
    s32 temp_r3_1042;
    s32 temp_r3_1128;
    s32 temp_r3_1188;
    s32 temp_r4_1026;
    u8 var_r3_1027;
    void *temp_r28_1095;
    void *temp_r28_1133;
    void *temp_r28_1193;
    void *temp_r28_1231;
    void *temp_r4_1098;
    void *temp_r4_1136;
    void *temp_r4_1196;
    void *temp_r4_1234;

    var_r31_1023 = this->unk2A78.unk20;
loop_32:
    if (M2C_BITWISE(u32, var_r31_1023) != &this->unk2A2C.__vptr) {
        temp_r4_1026 = M2C_FIELD(var_r31_1023, s32 *, 0x18);
        var_r3_1027 = 0;
        if (!(temp_r4_1026 & 0x80000000) && (temp_r4_1026 & this->unk14.unk68 & 0x7FFFFFFF) && !(temp_r4_1026 & M2C_BITWISE(s32, this->unk14.unk6C) & 0x7FFFFFFF)) {
            var_r3_1027 = 1;
        }
        if ((var_r3_1027 == 0) || (temp_r3_1042 = M2C_FIELD(var_r31_1023, s32 *, 0x10), (((temp_r3_1042 & 8) == 0) == 0))) {
            var_r31_1023 = M2C_FIELD(var_r31_1023, f32 *, 0x28);
        } else {
            if (temp_r3_1042 & 0x100) {
                temp_r3_1051 = M2C_FIELD(var_r31_1023, MKPropDescriptor **, 0);
                if ((void *) temp_r3_1051->unk54 == NULL) {
                    temp_r3_1051->unk48 = this->unk2D48;
                    this->unk2D48 = M2C_FIELD(var_r31_1023, MKPropDescriptor **, 0);
                }
                M2C_FIELD(var_r31_1023, void **, 0x3C) = (void *) M2C_FIELD(var_r31_1023, MKPropDescriptor **, 0)->unk54;
                M2C_FIELD(var_r31_1023, MKPropDescriptor **, 0)->unk54 = M2C_BITWISE(void *, var_r31_1023);
            } else if (temp_r3_1042 & 0x4000) {
                temp_r3_1069 = M2C_FIELD(var_r31_1023, MKPropDescriptor **, 0);
                if ((void *) temp_r3_1069->unk58 == NULL) {
                    temp_r3_1069->unk4C = this->unk2D44;
                    this->unk2D44 = M2C_FIELD(var_r31_1023, MKPropDescriptor **, 0);
                }
                M2C_FIELD(var_r31_1023, void **, 0x3C) = (void *) M2C_FIELD(var_r31_1023, MKPropDescriptor **, 0)->unk58;
                M2C_FIELD(var_r31_1023, MKPropDescriptor **, 0)->unk58 = M2C_BITWISE(void *, var_r31_1023);
            } else if (temp_r3_1042 & 0x1000) {
                if ((u8) M2C_FIELD(this, u8 *, 0x150) != 0) {
                    temp_r3_1090 = this->unk258;
                    this->unk258 = M2C_BITWISE(f32, (M2C_BITWISE(s32, temp_r3_1090) + 1));
                    temp_r28_1095 = this + ((M2C_BITWISE(s32, temp_r3_1090) * 8) + 0xA68);
                    M2C_FIELD(temp_r28_1095, f32 *, 0) = var_r31_1023;
                    temp_r3_1097 = MKView_GetCameraMatrix();
                    temp_r4_1098 = M2C_FIELD(var_r31_1023, void **, 8);
                    temp_r5_1099 = temp_r3_1097 + 0x30;
                    temp_f1_1100 = M2C_FIELD(temp_r4_1098, f64 *, 0x30);
                    spB8 = temp_f1_1100;
                    spC0 = M2C_FIELD(temp_r4_1098, f64 *, 0x38);
                    sp38 = temp_f1_1100 - *temp_r5_1099;
                    spA8 = sp38;
                    sp40 = (f32) spC0 - temp_r3_1097->unk38;
                    spB0 = (f64) sp40;
                    M2C_FIELD(temp_r28_1095, f32 *, 4) = (f32) (((f32) spB0 * temp_r3_1097->unk28) + (((f32) spA8 * temp_r3_1097->unk20) + ((*(f32 *) ((u8 *) &spA8 + 0x4)) * temp_r3_1097->unk24)));
                } else {
                    temp_r3_1128 = this->unk264;
                    this->unk264 = temp_r3_1128 + 1;
                    temp_r28_1133 = this + ((temp_r3_1128 * 8) + 0x1A08);
                    M2C_FIELD(temp_r28_1133, f32 *, 0) = var_r31_1023;
                    temp_r3_1135 = MKView_GetCameraMatrix();
                    temp_r4_1136 = M2C_FIELD(var_r31_1023, void **, 8);
                    temp_r5_1137 = temp_r3_1135 + 0x30;
                    temp_f1_1138 = M2C_FIELD(temp_r4_1136, f64 *, 0x30);
                    sp98 = temp_f1_1138;
                    spA0 = M2C_FIELD(temp_r4_1136, f64 *, 0x38);
                    sp28 = temp_f1_1138 - *temp_r5_1137;
                    sp88 = sp28;
                    sp30 = (f32) spA0 - temp_r3_1135->unk38;
                    sp90 = (f64) sp30;
                    M2C_FIELD(temp_r28_1133, f32 *, 4) = (f32) (((f32) sp90 * temp_r3_1135->unk28) + (((f32) sp88 * temp_r3_1135->unk20) + ((*(f32 *) ((u8 *) &sp88 + 0x4)) * temp_r3_1135->unk24)));
                }
            } else if (!(temp_r3_1042 & 0x480)) {
                temp_r3_1168 = M2C_FIELD(var_r31_1023, MKPropDescriptor **, 0);
                if ((void *) temp_r3_1168->unk50 == NULL) {
                    temp_r3_1168->unk44 = this->unk2D44;
                    this->unk2D44 = M2C_FIELD(var_r31_1023, MKPropDescriptor **, 0);
                }
                M2C_FIELD(var_r31_1023, void **, 0x3C) = (void *) M2C_FIELD(var_r31_1023, MKPropDescriptor **, 0)->unk50;
                M2C_FIELD(var_r31_1023, MKPropDescriptor **, 0)->unk50 = M2C_BITWISE(void *, var_r31_1023);
            } else if (temp_r3_1042 & 0x800) {
                if (temp_r3_1042 & 0x200) {
                    temp_r3_1188 = this->unk264;
                    this->unk264 = temp_r3_1188 + 1;
                    temp_r28_1193 = this + ((temp_r3_1188 * 8) + 0x1A08);
                    M2C_FIELD(temp_r28_1193, f32 *, 0) = var_r31_1023;
                    temp_r3_1195 = MKView_GetCameraMatrix();
                    temp_r4_1196 = M2C_FIELD(var_r31_1023, void **, 8);
                    temp_r5_1197 = temp_r3_1195 + 0x30;
                    temp_f1_1198 = M2C_FIELD(temp_r4_1196, f64 *, 0x30);
                    sp78 = temp_f1_1198;
                    sp80 = M2C_FIELD(temp_r4_1196, f64 *, 0x38);
                    sp18 = temp_f1_1198 - *temp_r5_1197;
                    sp68 = sp18;
                    sp20 = (f32) sp80 - temp_r3_1195->unk38;
                    sp70 = (f64) sp20;
                    M2C_FIELD(temp_r28_1193, f32 *, 4) = (f32) (((f32) sp70 * temp_r3_1195->unk28) + (((f32) sp68 * temp_r3_1195->unk20) + ((*(f32 *) ((u8 *) &sp68 + 0x4)) * temp_r3_1195->unk24)));
                } else {
                    temp_r3_1226 = this->unk258;
                    this->unk258 = M2C_BITWISE(f32, (M2C_BITWISE(s32, temp_r3_1226) + 1));
                    temp_r28_1231 = this + ((M2C_BITWISE(s32, temp_r3_1226) * 8) + 0xA68);
                    M2C_FIELD(temp_r28_1231, f32 *, 0) = var_r31_1023;
                    temp_r3_1233 = MKView_GetCameraMatrix();
                    temp_r4_1234 = M2C_FIELD(var_r31_1023, void **, 8);
                    temp_r5_1235 = temp_r3_1233 + 0x30;
                    temp_f1_1236 = M2C_FIELD(temp_r4_1234, f64 *, 0x30);
                    sp58 = temp_f1_1236;
                    sp60 = M2C_FIELD(temp_r4_1234, f64 *, 0x38);
                    sp8 = temp_f1_1236 - *temp_r5_1235;
                    sp48 = sp8;
                    sp10 = (f32) sp60 - temp_r3_1233->unk38;
                    sp50 = (f64) sp10;
                    M2C_FIELD(temp_r28_1231, f32 *, 4) = (f32) (((f32) sp50 * temp_r3_1233->unk28) + (((f32) sp48 * temp_r3_1233->unk20) + ((*(f32 *) ((u8 *) &sp48 + 0x4)) * temp_r3_1233->unk24)));
                }
            } else {
                temp_r3_1264 = M2C_FIELD(var_r31_1023, MKPropDescriptor **, 0);
                if ((void *) temp_r3_1264->unk54 == NULL) {
                    temp_r3_1264->unk48 = this->unk2D48;
                    this->unk2D48 = M2C_FIELD(var_r31_1023, MKPropDescriptor **, 0);
                }
                M2C_FIELD(var_r31_1023, void **, 0x3C) = (void *) M2C_FIELD(var_r31_1023, MKPropDescriptor **, 0)->unk54;
                M2C_FIELD(var_r31_1023, MKPropDescriptor **, 0)->unk54 = M2C_BITWISE(void *, var_r31_1023);
            }
            var_r31_1023 = M2C_FIELD(var_r31_1023, f32 *, 0x28);
        }
        goto loop_32;
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void MKDistanceLevelChunk::CalcDynamicPropVis() {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    BoundingVolume *var_r28_1325;
    Matrix *temp_r3_1347;
    f32 temp_f1_1372;
    f32 temp_f2_1356;
    f32 temp_f2_1378;
    f32 temp_f4_1360;
    f32 temp_f4_1368;
    f32 temp_f5_1364;
    f32 var_f6_1367;
    f32 var_r31_1299;
    s16 temp_r5_1336;
    s32 temp_cr0_eq_1336;
    s32 temp_r4_1302;
    u8 var_r3_1303;

    var_r31_1299 = this->unk2A2C.unk20;
loop_18:
    if (M2C_BITWISE(u32, var_r31_1299) != &this->unk29E0.__vptr) {
        temp_r4_1302 = M2C_FIELD(var_r31_1299, s32 *, 0x18);
        var_r3_1303 = 0;
        if (!(temp_r4_1302 & 0x80000000) && (temp_r4_1302 & this->unk14.unk68 & 0x7FFFFFFF) && !(temp_r4_1302 & M2C_BITWISE(s32, this->unk14.unk6C) & 0x7FFFFFFF)) {
            var_r3_1303 = 1;
        }
        if ((var_r3_1303 == 0) || (M2C_FIELD(var_r31_1299, s32 *, 0x10) & 8)) {
            var_r31_1299 = M2C_FIELD(var_r31_1299, f32 *, 0x28);
        } else {
            var_r28_1325 = M2C_FIELD(var_r31_1299, BoundingVolume **, 0xC);
            if (var_r28_1325 != NULL) {

            } else {
                var_r28_1325 = M2C_FIELD(M2C_FIELD(var_r31_1299, void **, 0), BoundingVolume **, 0x1C);
            }
            temp_r5_1336 = MKView_VisibilityTest(*var_r28_1325, *(M2C_FIELD(var_r31_1299, Matrix **, 8)));
            temp_cr0_eq_1336 = temp_r5_1336 == 0;
            sp8 = M2C_FIELD(var_r28_1325, f64 *, 0) + M2C_FIELD(var_r28_1325, f64 *, 0x10);
            sp10 = var_r28_1325->unk8 + var_r28_1325->unk18;
            if (temp_cr0_eq_1336 == 0) {
                temp_r3_1347 = M2C_FIELD(var_r31_1299, Matrix **, 8);
                sp18 = M2C_FIELD(temp_r3_1347, f64 *, 0x30);
                sp20 = M2C_FIELD(temp_r3_1347, f64 *, 0x38);
                temp_f2_1356 = (*(f32 *) ((u8 *) &sp18 + 0x4)) - this->unk254;
                temp_f4_1360 = (f32) sp18 - this->unk250;
                temp_f5_1364 = (f32) sp20 - this->unk250;
                var_f6_1367 = M2C_FIELD(gMK, f32 *, 8);
                temp_f4_1368 = M2C_FIELD(M2C_FIELD(var_r31_1299, void **, 0), f32 *, 8) * M2C_FIELD(gMK, f32 *, 4);
                temp_f1_1372 = (temp_f5_1364 * temp_f5_1364) + ((temp_f4_1360 * temp_f4_1360) + (temp_f2_1356 * temp_f2_1356));
                if (var_f6_1367 > temp_f4_1368) {

                } else {
                    var_f6_1367 = temp_f4_1368;
                }
                temp_f2_1378 = var_f6_1367 * var_f6_1367;
                if (temp_f1_1372 < temp_f2_1378) {
                    AddPropToDrawList(M2C_BITWISE(MKProp *, var_r31_1299), (s32) temp_r5_1336, temp_f1_1372, temp_f2_1378);
                }
            }
            var_r31_1299 = M2C_FIELD(var_r31_1299, f32 *, 0x28);
        }
        goto loop_18;
    }
}
#endif

void MKDistanceLevelChunk::CalcStaticPropVis() {
    SMNode *temp_r4_1402;

    temp_r4_1402 = this->unk29AC;
    if (temp_r4_1402 != NULL) {
        CheckPropVisRecursive(temp_r4_1402, 0);
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'MKDistanceLevelChunk *' to
void MKDistanceLevelChunk::UpdateProp(MKProp *arg0, MKMessage *arg1) {
    MKProp *temp_r3_1423;
    MKProp *temp_r4_1444;
    MKProp *temp_r4_1450;

    temp_r3_1423 = arg0->unk34;
    if (temp_r3_1423 == NULL) {
        arg0->Message(arg1);
    } else {
        temp_r3_1423->unk30 = arg0->unk30;
        arg0->unk30->unk34 = arg0->unk34;
    }
    temp_r4_1444 = this + ((this->unk204 * 0x4C) + 0x16C);
    arg0->unk34 = temp_r4_1444->unk34;
    arg0->unk30 = temp_r4_1444;
    arg0->unk34->unk30 = arg0;
    temp_r4_1450 = arg0->unk30;
    temp_r4_1450->unk34 = arg0;
    arg0->Update(temp_r4_1450);
}
#endif

#if 0 // DRAFT: illegal type
void MKDistanceLevelChunk::SendMessage(MKMessage *arg0, unsigned int arg1, bool arg2, MKVector3 *arg3, float arg4, bool arg5) {
    MKProp *temp_r3_1483;
    f32 var_r24_1519;
    f32 var_r30_1556;
    s32 temp_r4_1526;
    s32 temp_r4_1563;
    s32 temp_r5_1489;
    s32 var_r31_1480;
    u8 var_r3_1527;
    u8 var_r3_1564;
    u8 var_r4_1490;
    void *var_r30_1479;

    if (arg2 != 0) {
        var_r30_1479 = this->unk29A8;
        var_r31_1480 = 0;
loop_11:
        if (var_r31_1480 < (s32) this->unk29B8) {
            temp_r3_1483 = M2C_FIELD(var_r30_1479, MKProp **, 0x28);
            var_r30_1479 += 0x30;
            if (temp_r3_1483 != NULL) {
                if (arg5 != 0) {
                    temp_r5_1489 = temp_r3_1483->unk18;
                    var_r4_1490 = 0;
                    if (!(temp_r5_1489 & 0x80000000) && (temp_r5_1489 & this->unk14.unk68 & 0x7FFFFFFF) && !(temp_r5_1489 & M2C_BITWISE(s32, this->unk14.unk6C) & 0x7FFFFFFF)) {
                        var_r4_1490 = 1;
                    }
                    if (var_r4_1490 != 0) {
                        goto block_9;
                    }
                } else {
block_9:
                    SendMessageToProp(temp_r3_1483, arg0, arg1, arg3, arg4, (MKVector3 *) &this->unk158);
                }
            }
            var_r31_1480 += 1;
            goto loop_11;
        }
    }
    var_r24_1519 = this->unk2A2C.unk20;
loop_21:
    if (M2C_BITWISE(u32, var_r24_1519) != &this->unk29E0.__vptr) {
        if (arg5 != 0) {
            temp_r4_1526 = M2C_FIELD(var_r24_1519, s32 *, 0x18);
            var_r3_1527 = 0;
            if (!(temp_r4_1526 & 0x80000000) && (temp_r4_1526 & this->unk14.unk68 & 0x7FFFFFFF) && !(temp_r4_1526 & M2C_BITWISE(s32, this->unk14.unk6C) & 0x7FFFFFFF)) {
                var_r3_1527 = 1;
            }
            if (var_r3_1527 == 0) {
                var_r24_1519 = M2C_FIELD(var_r24_1519, f32 *, 0x28);
            } else {
                goto block_20;
            }
        } else {
block_20:
            SendMessageToProp(M2C_BITWISE(MKProp *, var_r24_1519), arg0, arg1, arg3, arg4, (MKVector3 *) &this->unk158);
            var_r24_1519 = M2C_FIELD(var_r24_1519, f32 *, 0x28);
        }
        goto loop_21;
    }
    var_r30_1556 = this->unk2A78.unk20;
loop_31:
    if (M2C_BITWISE(u32, var_r30_1556) != &this->unk2A2C.__vptr) {
        if (arg5 != 0) {
            temp_r4_1563 = M2C_FIELD(var_r30_1556, s32 *, 0x18);
            var_r3_1564 = 0;
            if (!(temp_r4_1563 & 0x80000000) && (temp_r4_1563 & this->unk14.unk68 & 0x7FFFFFFF) && !(temp_r4_1563 & M2C_BITWISE(s32, this->unk14.unk6C) & 0x7FFFFFFF)) {
                var_r3_1564 = 1;
            }
            if (var_r3_1564 == 0) {
                var_r30_1556 = M2C_FIELD(var_r30_1556, f32 *, 0x28);
            } else {
                goto block_30;
            }
        } else {
block_30:
            SendMessageToProp(M2C_BITWISE(MKProp *, var_r30_1556), arg0, arg1, NULL, arg4, (MKVector3 *) &this->unk158);
            var_r30_1556 = M2C_FIELD(var_r30_1556, f32 *, 0x28);
        }
        goto loop_31;
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void SendMessageToProp(MKProp *arg0, MKMessage *arg1, unsigned int arg2, MKVector3 *arg3, float arg4, MKVector3 *arg5) {
    f32 temp_f3_1629;
    f32 temp_f4_1626;
    f32 temp_f5_1624;
    void *temp_r5_1616;

    if ((arg2 == 0) || (arg2 & M2C_FIELD(arg0->unk0, s32 *, 0xC))) {
        if ((arg3 != NULL) && (temp_r5_1616 = arg0->unk8, ((temp_r5_1616 == NULL) == 0))) {
            temp_f5_1624 = M2C_FIELD(temp_r5_1616, f32 *, 0x34) - arg3->unk4;
            temp_f4_1626 = M2C_FIELD(temp_r5_1616, f32 *, 0x30) - arg3->unk0;
            temp_f3_1629 = M2C_FIELD(temp_r5_1616, f32 *, 0x38) - arg3->unk8;
            if (((temp_f3_1629 * temp_f3_1629) + ((temp_f4_1626 * temp_f4_1626) + (temp_f5_1624 * temp_f5_1624))) < (arg4 * arg4)) {
                M2C_FIELD(arg0->__vptr, M2C_UNK (**)(), 0x2C)();
            }
        } else {
            M2C_FIELD(arg0->__vptr, M2C_UNK (**)(), 0x2C)();
        }
    }
}
#endif

void MKDistanceLevelChunk::DrawRecursiveTerrain(SMNode *arg0, int arg1) {
    SMNode *temp_r4_1697;
    SMNode *temp_r4_1704;
    s16 var_r3_1664;
    s32 temp_r4_1685;
    s32 var_r30_1662;
    u16 temp_r5_1682;

    var_r30_1662 = arg1;
    var_r3_1664 = 1;
    if (!(arg1 & 1)) {
        var_r3_1664 = MKView_VisibilityTest(*((BoundingVolume *) arg0), Matrix::identity);
        if (var_r3_1664 != 0) {
            if (var_r3_1664 == 1) {
                var_r30_1662 |= 1;
            }
            goto block_4;
        }
    } else {
block_4:
        if ((MKProp *) arg0->unk28 != NULL) {
            temp_r5_1682 = M2C_FIELD(this, u16 *, 0x268) + 1;
            M2C_FIELD(this, u16 *, 0x268) = temp_r5_1682;
            temp_r4_1685 = (var_r3_1664 - 1) - 1;
            M2C_FIELD((this + ((temp_r5_1682 * 2) & 0x1FFFE)), s16 *, 0x268) = (s16) ((s32) (arg0->unk28 - 1) | (0x8000 & ((temp_r4_1685 - temp_r4_1685) - !M2C_CARRY)));
            return;
        }
        temp_r4_1697 = arg0->unk20;
        if (temp_r4_1697 != NULL) {
            DrawRecursiveTerrain(temp_r4_1697, var_r30_1662);
        }
        temp_r4_1704 = arg0->unk24;
        if (temp_r4_1704 != NULL) {
            DrawRecursiveTerrain(temp_r4_1704, var_r30_1662);
        }
    }
}

u8 SMTree::LinkUp() {
    s32 temp_r0_1726;
    s32 temp_r3_1762;
    s32 temp_r5_1795;
    s32 temp_r5_1851;
    s32 temp_r5_1859;
    s32 temp_r6_1796;
    s32 temp_r6_1801;
    s32 temp_r6_1850;
    s32 temp_r6_1856;
    s32 temp_r6_1866;
    s32 var_r4_1750;
    u32 temp_r28_1781;
    u32 temp_r30_1776;
    u32 temp_r30_1824;
    u32 temp_r31_1829;

    temp_r0_1726 = this->unk1C;
    switch (temp_r0_1726) {                         /* irregular */
    case 0:
        if (((void *) this->unk4 == NULL) || ((s32) this->unk8 == 1)) {
            return 1U;
        }
        this->unk24 = -1;
        var_r4_1750 = this->unk8;
loop_11:
        if (var_r4_1750 != 0) {
            var_r4_1750 = var_r4_1750 >> 1;
            this->unk24 += 1;
            goto loop_11;
        }
        this->unk28 = 0;
        temp_r3_1762 = this->unk8;
        if (temp_r3_1762 & (temp_r3_1762 - 1)) {
            this->unk1C = 1;
        } else {
            this->unk1C = 2;
        }
block_32:
    default:
        return 0U;
    case 1:
        temp_r30_1776 = OSGetTick();
        temp_r28_1781 = (u32) (675000.0f * M2C_FIELD(gMK, f32 *, 0xB0));
loop_17:
        if ((u32) (OSGetTick() - temp_r30_1776) < temp_r28_1781) {
            temp_r5_1795 = this->unk8;
            temp_r6_1796 = this->unk28;
            if (temp_r6_1796 < (s32) (temp_r5_1795 - 1)) {
                PairUp(0, temp_r5_1795, temp_r6_1796);
                this->unk28 += 2;
                goto loop_17;
            }
        }
        temp_r6_1801 = this->unk8;
        if ((s32) this->unk28 >= (s32) (temp_r6_1801 - 1)) {
            LinkUpRow(0, this->unk10 - (((1 << this->unk24) * 2) - 1), temp_r6_1801);
            this->unk28 = 0;
            this->unk1C = 2;
        }
        goto block_32;
    case 2:
        temp_r30_1824 = OSGetTick();
        temp_r31_1829 = (u32) (675000.0f * M2C_FIELD(gMK, f32 *, 0xB0));
loop_28:
        if (((u32) (OSGetTick() - temp_r30_1824) < temp_r31_1829) && ((s32) this->unk24 != 0)) {
loop_24:
            if ((u32) (OSGetTick() - temp_r30_1824) < temp_r31_1829) {
                temp_r6_1850 = this->unk28;
                temp_r5_1851 = 1 << this->unk24;
                if (temp_r6_1850 < (s32) (temp_r5_1851 - 1)) {
                    PairUp(this->unk10 - ((temp_r5_1851 * 2) - 1), temp_r5_1851, temp_r6_1850);
                    this->unk28 += 2;
                    goto loop_24;
                }
            }
            temp_r6_1856 = this->unk24;
            temp_r5_1859 = 1 << temp_r6_1856;
            if ((s32) this->unk28 >= (s32) (temp_r5_1859 - 1)) {
                temp_r6_1866 = this->unk10;
                LinkUpRow(temp_r6_1866 - ((temp_r5_1859 * 2) - 1), temp_r5_1859, temp_r6_1866 - (((1 << (temp_r6_1856 - 1)) * 2) - 1));
                this->unk28 = 0;
                this->unk24 -= 1;
            }
            goto loop_28;
        }
        if ((s32) this->unk24 == 0) {
            return 1U;
        }
        goto block_32;
    }
}

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void SMTree::LinkUpRow(int arg0, int arg1, int arg2) {
    f64 sp90;
    f64 sp88;
    MKVector3 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    MKVector3 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    BoundingVolume *temp_r3_1914;
    BoundingVolume *var_r29_1916;
    BoundingVolume *var_r30_1915;
    f32 temp_f2_1979;
    f32 var_f1_1978;
    f64 temp_f0_1925;
    f64 temp_f0_1939;
    s32 var_r31_1913;

    var_r31_1913 = 0;
    temp_r3_1914 = this->unk0;
    var_r30_1915 = &temp_r3_1914[arg2];
    var_r29_1916 = &temp_r3_1914[arg0];
loop_5:
    if (var_r31_1913 < arg1) {
        var_r30_1915->unk20 = (s32) var_r29_1916;
        var_r30_1915->unk24 = (s32) (var_r29_1916 + 0x30);
        temp_f0_1925 = M2C_FIELD(var_r29_1916, f64 *, 0) + M2C_FIELD(var_r29_1916, f64 *, 0x10);
        sp18 = temp_f0_1925;
        sp68 = temp_f0_1925;
        sp20 = var_r29_1916->unk8 + var_r29_1916->unk18;
        sp70 = (f64) sp20;
        temp_f0_1939 = M2C_FIELD(var_r29_1916, f64 *, 0x30) + M2C_FIELD(var_r29_1916, f64 *, 0x40);
        sp28 = temp_f0_1939;
        sp58 = temp_f0_1939;
        sp30 = M2C_FIELD(var_r29_1916, f32 *, 0x38) + M2C_FIELD(var_r29_1916, f32 *, 0x48);
        sp60 = (f64) sp30;
        Max(sp48, *((MKVector3 *) &sp58));
        sp38 = M2C_BITWISE(f64, sp48);
        sp40 = (f64) sp48.unk8;
        Min(sp78, *(MKVector3 *) (var_r29_1916 + 0x30));
        M2C_FIELD(var_r30_1915, f64 *, 0) = M2C_BITWISE(f64, sp78);
        M2C_FIELD(var_r30_1915, f64 *, 8) = (f64) sp78.unk8;
        sp8 = sp38 - M2C_FIELD(var_r30_1915, f64 *, 0);
        M2C_FIELD(var_r30_1915, f64 *, 0x10) = sp8;
        sp10 = (f32) sp40 - var_r30_1915->unk8;
        sp88 = sp8;
        M2C_FIELD(var_r30_1915, f64 *, 0x18) = (f64) sp10;
        var_f1_1978 = var_r29_1916->unk2C;
        temp_f2_1979 = M2C_FIELD(var_r29_1916, f32 *, 0x5C);
        sp90 = (f64) sp10;
        if (var_f1_1978 > temp_f2_1979) {

        } else {
            var_f1_1978 = temp_f2_1979;
        }
        var_r30_1915->unk2C = var_f1_1978;
        var_r29_1916 += 0x60;
        var_r30_1915 += 0x30;
        var_r31_1913 += 2;
        goto loop_5;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp50'
void SMTree::PairUp(int arg0, int arg1, int arg2) {
    BoundingVolume *temp_r5_2155;
    BoundingVolume *temp_r7_2014;
    BoundingVolume *temp_r9_2042;
    BoundingVolume *var_r6_2121;
    BoundingVolume *var_r8_2016;
    f32 temp_f2_2192;
    f32 var_f1_2123;
    f32 var_f5_2032;
    s32 var_ctr_2035;
    s32 var_ctr_2148;
    s32 var_r10_2010;
    s32 var_r11_2117;
    var_r10_2010 = arg2 + 1;
    temp_r7_2014 = &this->unk0[arg0 + arg2];
    var_r8_2016 = temp_r7_2014;
    arg_sp50 = (0.5f * temp_r7_2014->unk10) + temp_r7_2014->unk0;
    arg_sp54 = (0.5f * temp_r7_2014->unk14) + temp_r7_2014->unk4;
    arg_sp58 = (0.5f * temp_r7_2014->unk18) + temp_r7_2014->unk8;
    arg_spD0 = (f64) arg_sp50;
    arg_spA0 = (f64) arg_sp50;
    var_f5_2032 = (f32) arg_spD0;
    arg_spA8 = (f64) arg_sp58;
    arg_spD8 = (f64) arg_sp58;
    var_ctr_2035 = arg1 - var_r10_2010;
    if (var_r10_2010 < arg1) {
        do {
            temp_r9_2042 = &this->unk0[arg0 + var_r10_2010];
            arg_sp40 = (0.5f * temp_r9_2042->unk10) + temp_r9_2042->unk0;
            arg_sp44 = (0.5f * temp_r9_2042->unk14) + temp_r9_2042->unk4;
            arg_sp48 = (0.5f * temp_r9_2042->unk18) + temp_r9_2042->unk8;
            arg_spC0 = (f64) arg_sp40;
            arg_sp90 = (f64) arg_sp40;
            arg_sp98 = (f64) arg_sp48;
            arg_spC8 = (f64) arg_sp48;
            if ((f32) arg_spC0 < var_f5_2032) {
                var_f5_2032 = (f32) arg_spC0;
                var_r8_2016 = temp_r9_2042;
            }
            var_r10_2010 += 1;
            var_ctr_2035 -= 1;
        } while (var_ctr_2035 != 0);
    }
    M2C_STRUCT_COPY((s32) &arg_spDC + 4, (s32) (temp_r7_2014 - 4) + 4, 0x20);
    arg_sp100 = temp_r7_2014->unk20;
    arg_sp104 = temp_r7_2014->unk24;
    arg_sp108 = temp_r7_2014->unk28;
    arg_sp10C = temp_r7_2014->unk2C;
    M2C_STRUCT_COPY(temp_r7_2014, var_r8_2016, 0x20);
    temp_r7_2014->unk20 = var_r8_2016->unk20;
    temp_r7_2014->unk24 = var_r8_2016->unk24;
    temp_r7_2014->unk28 = var_r8_2016->unk28;
    temp_r7_2014->unk2C = var_r8_2016->unk2C;
    M2C_STRUCT_COPY((s32) (var_r8_2016 - 4) + 4, (s32) &arg_spDC + 4, 0x20);
    var_r11_2117 = arg2 + 1;
    var_r6_2121 = NULL;
    var_r8_2016->unk20 = arg_sp100;
    var_f1_2123 = 1e14f;
    var_r8_2016->unk24 = arg_sp104;
    var_r8_2016->unk28 = arg_sp108;
    var_r8_2016->unk2C = arg_sp10C;
    arg_sp38 = (0.5f * temp_r7_2014->unk18) + temp_r7_2014->unk8;
    arg_sp30 = (0.5f * temp_r7_2014->unk10) + temp_r7_2014->unk0;
    arg_sp34 = (0.5f * temp_r7_2014->unk14) + temp_r7_2014->unk4;
    arg_sp18 = (f64) arg_sp38;
    arg_sp80 = (f64) arg_sp30;
    arg_sp88 = (f64) arg_sp38;
    arg_sp10 = (f64) arg_sp30;
    var_ctr_2148 = arg1 - var_r11_2117;
    if (var_r11_2117 < arg1) {
        do {
            temp_r5_2155 = &this->unk0[arg0 + var_r11_2117];
            arg_sp20 = (0.5f * temp_r5_2155->unk10) + temp_r5_2155->unk0;
            arg_sp24 = (0.5f * temp_r5_2155->unk14) + temp_r5_2155->unk4;
            arg_sp28 = (0.5f * temp_r5_2155->unk18) + temp_r5_2155->unk8;
            arg_spC0 = (f64) arg_sp20;
            arg_sp70 = (f64) arg_sp20;
            arg_sp78 = (f64) arg_sp28;
            arg_spC8 = (f64) arg_sp28;
            arg_sp60 = arg_sp10 - arg_spC0;
            arg_spB0 = arg_sp60;
            arg_sp68 = (f32) arg_sp18 - (f32) arg_spC8;
            arg_spB8 = (f64) arg_sp68;
            temp_f2_2192 = ((f32) arg_spB8 * (f32) arg_spB8) + (((f32) arg_spB0 * (f32) arg_spB0) + (arg_spB4 * arg_spB4));
            if (temp_f2_2192 < var_f1_2123) {
                var_f1_2123 = temp_f2_2192;
                var_r6_2121 = temp_r5_2155;
            }
            var_r11_2117 += 1;
            var_ctr_2148 -= 1;
        } while (var_ctr_2148 != 0);
    }
    M2C_STRUCT_COPY((s32) &arg_spDC + 4, (s32) &temp_r7_2014->unk2C + 4, 0x20);
    arg_sp100 = M2C_FIELD(temp_r7_2014, s32 *, 0x50);
    arg_sp104 = M2C_FIELD(temp_r7_2014, s32 *, 0x54);
    arg_sp108 = M2C_FIELD(temp_r7_2014, MKProp **, 0x58);
    arg_sp10C = M2C_FIELD(temp_r7_2014, f32 *, 0x5C);
    M2C_STRUCT_COPY((s32) &temp_r7_2014->unk2C + 4, (s32) (var_r6_2121 - 4) + 4, 0x20);
    M2C_FIELD(temp_r7_2014, s32 *, 0x50) = (s32) var_r6_2121->unk20;
    M2C_FIELD(temp_r7_2014, s32 *, 0x54) = (s32) var_r6_2121->unk24;
    M2C_FIELD(temp_r7_2014, MKProp **, 0x58) = (MKProp *) var_r6_2121->unk28;
    M2C_FIELD(temp_r7_2014, f32 *, 0x5C) = (f32) var_r6_2121->unk2C;
    M2C_STRUCT_COPY((s32) (var_r6_2121 - 4) + 4, (s32) &arg_spDC + 4, 0x20);
    var_r6_2121->unk20 = arg_sp100;
    var_r6_2121->unk24 = arg_sp104;
    var_r6_2121->unk28 = arg_sp108;
    var_r6_2121->unk2C = arg_sp10C;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void SMTree::Deinit() {
    BoundingVolume *temp_r31_2267;
    MKHeap *temp_r3_2270;

    temp_r31_2267 = this->unk0;
    if (temp_r31_2267 != NULL) {
        temp_r3_2270 = MKHeap::Current();
        if (temp_r3_2270 != NULL) {
            ((MKHeap *) (temp_r3_2270->Current()))->Free(temp_r31_2267, NULL, 0);
        } else {
            free(temp_r31_2267);
        }
        this->unk0 = NULL;
    }
    Reset();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void SMTree::Update() {
    BoundingVolume *var_r7_2320;
    MKProp *temp_r0_2328;
    MKProp *temp_r0_2402;
    MKProp *temp_r0_2408;
    MKProp *temp_r31_2365;
    MKProp *temp_r6_2318;
    s32 temp_r0_2303;
    s32 temp_r0_2315;
    s32 var_r3_2319;
    s32 var_r9_2321;
    u32 temp_r28_2368;
    u32 temp_r29_2373;
    void *temp_r4_2331;
    void *temp_r8_2324;

    temp_r0_2303 = this->unk14;
    switch (temp_r0_2303) {                         /* switch 1; irregular */
    case 1:                                         /* switch 1 */
        this->unk1C = 0;
        temp_r0_2315 = this->unk18;
        switch (temp_r0_2315) {                     /* switch 2; irregular */
        case 0:                                     /* switch 2 */
            temp_r6_2318 = this->unk2C;
            var_r3_2319 = 0;
            var_r7_2320 = this->unk0;
            var_r9_2321 = 0;
            temp_r8_2324 = M2C_FIELD(temp_r6_2318->unk4->unk0, void **, 0x30);
loop_9:
            if (var_r9_2321 < (s16) M2C_FIELD(temp_r8_2324, s16 *, 4)) {
                temp_r0_2328 = var_r9_2321 + 1;
                var_r9_2321 += 1;
                var_r7_2320->unk28 = temp_r0_2328;
                temp_r4_2331 = M2C_FIELD(temp_r8_2324, s32 *, 0x50) + var_r3_2319;
                var_r3_2319 += 0x40;
                M2C_FIELD(var_r7_2320, f64 *, 0) = (f64) M2C_FIELD(temp_r4_2331, f64 *, 0);
                M2C_FIELD(var_r7_2320, f64 *, 8) = (f64) M2C_FIELD(temp_r4_2331, f64 *, 8);
                M2C_FIELD(var_r7_2320, f64 *, 0x10) = (f64) M2C_FIELD(temp_r4_2331, f64 *, 0x10);
                M2C_FIELD(var_r7_2320, f64 *, 0x18) = (f64) M2C_FIELD(temp_r4_2331, f64 *, 0x18);
                var_r7_2320->unk20 = 0;
                var_r7_2320->unk24 = 0;
                var_r7_2320->unk2C = temp_r6_2318->unk48;
                var_r7_2320 += 0x30;
                goto loop_9;
            }
            this->unk14 = 3;
            return;
        case 1:                                     /* switch 2 */
            this->unk30 = this->unk2C->unk28;
            this->unk34 = this->unk0;
            this->unk14 = 2;
            return;
        }
        break;
    case 2:                                         /* switch 1 */
        temp_r31_2365 = this->unk2C;
        temp_r28_2368 = OSGetTick();
        temp_r29_2373 = (u32) (675000.0f * M2C_FIELD(gMK, f32 *, 0xB0));
loop_15:
        if ((u32) (OSGetTick() - temp_r28_2368) < temp_r29_2373) {
            temp_r0_2402 = this->unk30;
            if ((temp_r0_2402 != NULL) && (temp_r0_2402 != temp_r31_2365)) {
                this->unk34->unk28 = temp_r0_2402;
                CalcBoundingBox(this->unk30, this->unk34);
                this->unk34->unk20 = 0;
                this->unk34->unk24 = 0;
                this->unk34->unk2C = M2C_FIELD(this->unk30->unk0, f32 *, 8);
                this->unk34 += 0x30;
                this->unk30 = this->unk30->unk28;
                goto loop_15;
            }
        }
        temp_r0_2408 = this->unk30;
        if ((temp_r0_2408 == NULL) || (temp_r0_2408 == temp_r31_2365)) {
            this->unk14 = 3;
            return;
        }
        break;
    case 3:                                         /* switch 1 */
        if (LinkUp() != 0) {
            this->unk14 = 4;
        }
        break;
    }
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void SMTree::InternalInit(int arg0) {
    BoundingVolume *var_r3_2464;
    MKHeap *temp_r3_2457;
    s32 temp_r31_2456;

    if (arg0 == 0) {
        this->unk0 = NULL;
        this->unk4 = NULL;
        this->unk10 = 0;
        this->unkC = 0;
        this->unk8 = 0;
        return;
    }
    this->unk8 = arg0;
    this->unkC = arg0 - 1;
    this->unk10 = this->unkC + arg0;
    temp_r31_2456 = this->unk10 * 0x30;
    temp_r3_2457 = MKHeap::Current();
    if (temp_r3_2457 != NULL) {
        var_r3_2464 = ((MKHeap *) (temp_r3_2457->Current()))->Alloc(temp_r31_2456, NULL, 0);
    } else {
        var_r3_2464 = malloc(temp_r31_2456);
    }
    this->unk0 = var_r3_2464;
    this->unk4 = &this->unk0[this->unk10 - 1];
    memset(this->unk0, 0, this->unk10 * 0x30);
}
#endif

void SMTree::Init(int arg0, MKProp *arg1) {
    InternalInit(arg0);
    this->unk18 = 1;
    this->unk2C = arg1;
    this->unk14 = 1;
}

void SMTree::Init(TerrainModel *arg0) {
    s16 temp_r3_2522;

    temp_r3_2522 = MKModel_GetNmbrOfSubObjects(arg0->unk4, (SubObjectType) 0);
    if (temp_r3_2522 > 1) {
        InternalInit((s32) temp_r3_2522);
        this->unk14 = 1;
    } else {
        InternalInit(0);
        this->unk14 = 4;
    }
    this->unk18 = 0;
    this->unk2C = (MKProp *) arg0;
}

void SMTree::Reset() {
    this->unk14 = 0;
    this->unk4 = NULL;
    this->unk0 = NULL;
    this->unkC = 0;
    this->unk10 = 0;
    this->unk30 = NULL;
    this->unk34 = NULL;
}

void MKDistanceLevelChunk::CalculateUpdateDistances() {

}

#if 0 // DRAFT: undefined identifier 'SortPropCompare'
void MKDistanceLevelChunk::CalculateVisibility(bool arg0) {
    Matrix *temp_r3_2577;
    Matrix *temp_r3_2597;
    f32 temp_r0_2582;

    temp_r3_2577 = MKView_GetCameraMatrix();
    this->unk158 = M2C_FIELD(temp_r3_2577, f64 *, 0x30);
    this->unk158 = M2C_FIELD(temp_r3_2577, f64 *, 0x38);
    temp_r0_2582 = this->unk14.unk78;
    if (((M2C_BITWISE(s32, temp_r0_2582) == 9) || (M2C_BITWISE(s32, temp_r0_2582) == 0xC)) && (this->unk134 & 1)) {
        this->unk258 = 0.0f;
        this->unk264 = 0;
        M2C_FIELD(this, u8 *, 0x150) = arg0;
        DL_Begin();
        temp_r3_2597 = MKView_GetCameraMatrix();
        M2C_FIELD(this, f64 *, 0x250) = (f64) M2C_FIELD(temp_r3_2597, f64 *, 0x30);
        M2C_FIELD(this, f64 *, 0x258) = (f64) M2C_FIELD(temp_r3_2597, f64 *, 0x38);
        CalcStaticPropVis();
        CalcDynamicPropVis();
        CalcGlobalPropVis();
        if (M2C_BITWISE(s32, this->unk258) != 0) {
            qsort(&this->unkA68, 8, SortPropCompare);
        }
        if ((s32) this->unk264 != 0) {
            qsort(&this->unk1A08, 8, SortPropCompare);
        }
    }
}
#endif

s32 MKDistanceLevelChunk::FindTerrainModel(const char *arg0) {
    return 0;
}

#if 0 // DRAFT: undefined identifier '__vptr'
MKProp *MKDistanceLevelChunk::FindProp(const char *arg0) {
    f32 var_r30_2650;
    f32 var_r30_2666;
    f32 var_r30_2683;

    var_r30_2650 = this->unk2A78.unk20;
loop_4:
    if (M2C_BITWISE(u32, var_r30_2650) == &this->unk2A2C.__vptr) {
        var_r30_2666 = this->unk2A2C.unk20;
loop_9:
        if (M2C_BITWISE(u32, var_r30_2666) == &this->unk29E0.__vptr) {
            var_r30_2683 = this->unk29E0.unk20;
loop_14:
            if (M2C_BITWISE(u32, var_r30_2683) == &this->unk29E0) {
                return NULL;
            }
            if (stricmp(*M2C_FIELD(var_r30_2683, s8 ***, 0), arg0) == 0) {
                return M2C_BITWISE(MKProp *, var_r30_2683);
            }
            var_r30_2683 = M2C_FIELD(var_r30_2683, f32 *, 0x28);
            goto loop_14;
        }
        if (stricmp(*M2C_FIELD(var_r30_2666, s8 ***, 0), arg0) == 0) {
            return M2C_BITWISE(MKProp *, var_r30_2666);
        }
        var_r30_2666 = M2C_FIELD(var_r30_2666, f32 *, 0x28);
        goto loop_9;
    }
    if (stricmp(*M2C_FIELD(var_r30_2650, s8 ***, 0), arg0) == 0) {
        return M2C_BITWISE(MKProp *, var_r30_2650);
    }
    var_r30_2650 = M2C_FIELD(var_r30_2650, f32 *, 0x28);
    goto loop_4;
}
#endif

#if 0 // DRAFT: function call 'stricmp(signed char *, const char *)' does not match
MKPropDescriptor *MKDistanceLevelChunk::FindDescriptor(const char *arg0) {
    s32 var_r31_2717;

    var_r31_2717 = this->unk148;
loop_4:
    if ((u32) var_r31_2717 == 0U) {
        return NULL;
    }
    if (stricmp(M2C_FIELD(var_r31_2717, s8 **, 0), arg0) == 0) {
        return (MKPropDescriptor *) var_r31_2717;
    }
    var_r31_2717 = M2C_FIELD(var_r31_2717, s32 *, 0x24);
    goto loop_4;
}
#endif

#if 0 // DRAFT: pointer/array required
MKModel *MKDistanceLevelChunk::AddTerrainModel(const char *arg0, int arg1) {
    MKModel *temp_r3_2755;
    s32 temp_r7_2763;

    temp_r3_2755 = MKModel_Create(arg0, NULL, 0, NULL);
    MKModel_EnableScissoring(temp_r3_2755, 1U);
    operator new(0x50U, NULL, 0);
    temp_r7_2763 = arg1 * 0x50;
    M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = (s32) M2C_FIELD((this + temp_r7_2763), s32 *, 0x2AD0);
    *M2C_ERROR(/* Read from unset register $r3 */) = this + (temp_r7_2763 + 0x2AC4);
    M2C_FIELD(*M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = (s32) M2C_ERROR(/* Read from unset register $r3 */);
    *M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 **, 0xC) = M2C_ERROR(/* Read from unset register $r3 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x14) = 0;
    M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), MKModel **, 4) = temp_r3_2755;
    M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 8) = 1;
    M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 0x48) = M2C_BITWISE(f32, this->unk140);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x4C) = 0;
    return temp_r3_2755;
}
#endif

#if 0 // DRAFT: illegal function definition
void MKDistanceLevelChunk::AddProp(MKProp *arg0) {
    f32 sp8;
    f32 temp_f0_2808;
    f32 temp_f1_2807;
    f32 temp_f2_2810;
    f32 var_f4_2814;
    f32 var_r6_2891;
    f32 var_r6_2929;
    f32 var_r6_2965;
    f64 temp_f1_2817;
    f64 temp_f1_2823;
    f64 temp_f1_2827;
    s32 temp_r0_2883;
    s32 temp_r3_2846;
    s32 temp_r3_2884;
    s32 var_r0_2856;
    void *temp_r3_2804;
    void *temp_r4_2800;
    void *temp_r4_2882;

    temp_r4_2800 = arg0->unk0;
    if (M2C_FIELD(temp_r4_2800, f32 *, 0x20) == 0.0f) {
        temp_r3_2804 = M2C_FIELD(temp_r4_2800, void **, 0x1C);
        if (temp_r3_2804 != NULL) {
            temp_f1_2807 = M2C_FIELD(temp_r3_2804, f32 *, 0x10);
            temp_f0_2808 = M2C_FIELD(temp_r3_2804, f32 *, 0x14);
            temp_f2_2810 = M2C_FIELD(temp_r3_2804, f32 *, 0x18);
            var_f4_2814 = (temp_f2_2810 * temp_f2_2810) + ((temp_f1_2807 * temp_f1_2807) + (temp_f0_2808 * temp_f0_2808));
            if (var_f4_2814 > 0.0f) {
                temp_f1_2817 = __frsqrte(var_f4_2814);
                temp_f1_2823 = 0.5 * temp_f1_2817 * -(((f64) var_f4_2814 * (temp_f1_2817 * temp_f1_2817)) - 3.0);
                temp_f1_2827 = 0.5 * temp_f1_2823 * -(((f64) var_f4_2814 * (temp_f1_2823 * temp_f1_2823)) - 3.0);
                var_f4_2814 = (f32) ((f64) var_f4_2814 * (0.5 * temp_f1_2827 * -(((f64) var_f4_2814 * (temp_f1_2827 * temp_f1_2827)) - 3.0)));
            } else if (var_f4_2814 < M2C_BITWISE(f32, 0.0)) {
                var_f4_2814 = __float_nan;
            } else {
                sp8 = var_f4_2814;
                temp_r3_2846 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_2846) {             /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_2856 = 1;
                    } else {
                        var_r0_2856 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_2856 = 5;
                    } else {
                        var_r0_2856 = 3;
                    }
                    break;
                default:
                    var_r0_2856 = 4;
                    break;
                }
                if (var_r0_2856 == 1) {
                    var_f4_2814 = __float_nan;
                }
            }
            M2C_FIELD(arg0->unk0, f32 *, 0x20) = (f32) (200.0f + var_f4_2814);
        }
    }
    temp_r4_2882 = arg0->unk0;
    temp_r0_2883 = M2C_FIELD(temp_r4_2882, s32 *, 0x14);
    temp_r3_2884 = temp_r0_2883 & 3;
    if (temp_r3_2884 == 0) {
        M2C_FIELD(temp_r4_2882, s32 *, 0x14) = (s32) (temp_r0_2883 & 0xFFFFFFFC);
        DL_Init((MKPropDescriptor *) arg0->unk0);
        var_r6_2891 = this->unk29E0.unk20;
loop_23:
        if ((M2C_BITWISE(u32, var_r6_2891) != &this->unk29E0) && ((s32) M2C_FIELD(arg0->unk0, s32 *, 0x18) < (s32) M2C_FIELD(M2C_FIELD(var_r6_2891, void **, 0), s32 *, 0x18))) {
            var_r6_2891 = M2C_FIELD(var_r6_2891, f32 *, 0x28);
            goto loop_23;
        }
        arg0->unk28 = M2C_BITWISE(MKProp *, var_r6_2891);
        arg0->unk2C = M2C_FIELD(var_r6_2891, MKProp **, 0x2C);
        arg0->unk28->unk2C = arg0;
        arg0->unk2C->unk28 = arg0;
        arg0->unk30 = NULL;
        arg0->unk34 = NULL;
        this->unk29E0.unkC += 1;
    } else if (temp_r3_2884 == 1) {
        M2C_FIELD(temp_r4_2882, s32 *, 0x14) = (s32) ((temp_r0_2883 & 0xFFFFFFFC) | 1);
        DL_Init((MKPropDescriptor *) arg0->unk0);
        var_r6_2929 = this->unk2A2C.unk20;
loop_29:
        if ((M2C_BITWISE(u32, var_r6_2929) != &this->unk29E0.__vptr) && ((s32) M2C_FIELD(arg0->unk0, s32 *, 0x18) < (s32) M2C_FIELD(M2C_FIELD(var_r6_2929, void **, 0), s32 *, 0x18))) {
            var_r6_2929 = M2C_FIELD(var_r6_2929, f32 *, 0x28);
            goto loop_29;
        }
        arg0->unk28 = M2C_BITWISE(MKProp *, var_r6_2929);
        arg0->unk2C = M2C_FIELD(var_r6_2929, MKProp **, 0x2C);
        arg0->unk28->unk2C = arg0;
        arg0->unk2C->unk28 = arg0;
        arg0->unk30 = NULL;
        arg0->unk34 = NULL;
        this->unk2A2C.unkC += 1;
    } else {
        M2C_FIELD(temp_r4_2882, s32 *, 0x14) = (s32) ((temp_r0_2883 & 0xFFFFFFFC) | 2);
        DL_Init((MKPropDescriptor *) arg0->unk0);
        var_r6_2965 = this->unk2A78.unk20;
loop_34:
        if ((M2C_BITWISE(u32, var_r6_2965) != &this->unk2A2C.__vptr) && ((s32) M2C_FIELD(arg0->unk0, s32 *, 0x18) < (s32) M2C_FIELD(M2C_FIELD(var_r6_2965, void **, 0), s32 *, 0x18))) {
            var_r6_2965 = M2C_FIELD(var_r6_2965, f32 *, 0x28);
            goto loop_34;
        }
        arg0->unk28 = M2C_BITWISE(MKProp *, var_r6_2965);
        arg0->unk2C = M2C_FIELD(var_r6_2965, MKProp **, 0x2C);
        arg0->unk28->unk2C = arg0;
        arg0->unk2C->unk28 = arg0;
        arg0->unk30 = NULL;
        arg0->unk34 = NULL;
        this->unk2A78.unkC += 1;
    }
    arg0->unk38 = M2C_FIELD(arg0->unk0, MKProp **, 0x28);
    M2C_FIELD(arg0->unk0, MKProp **, 0x28) = arg0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk24'
void MKDistanceLevelChunk::AddDescriptor(MKPropDescriptor *arg0) {
    arg0->unk24 = this->unk148;
    this->unk148 = (s32) arg0;
}
#endif

#if 0 // DRAFT: illegal operand
void MKDistanceLevelChunk::DrawTerrain(int arg0) {
    f32 temp_r12_3069;
    f32 temp_r12_3084;
    s32 temp_r4_3031;
    s32 temp_r4_3038;
    u8 var_r3_3039;
    void *var_r30_3034;

    if (this->unk134 & 1) {
        MKMaterial_SetLocalToWorld(&Matrix::identity, 1.0f);
        temp_r4_3031 = arg0 * 0x50;
        var_r30_3034 = M2C_FIELD((this + temp_r4_3031), void **, 0x2AC4);
loop_15:
        if (var_r30_3034 != (void *) (this + (temp_r4_3031 + 0x2AC4))) {
            temp_r4_3038 = M2C_FIELD(var_r30_3034, s32 *, 8);
            var_r3_3039 = 0;
            if (!(temp_r4_3038 & 0x80000000) && (temp_r4_3038 & this->unk14.unk68 & 0x7FFFFFFF) && !(temp_r4_3038 & M2C_BITWISE(s32, this->unk14.unk6C) & 0x7FFFFFFF)) {
                var_r3_3039 = 1;
            }
            if (var_r3_3039 != 0) {
                if ((SMNode *) M2C_FIELD(var_r30_3034, SMNode **, 0x14) != NULL) {
                    M2C_FIELD(this, u16 *, 0x268) = 0U;
                    DrawRecursiveTerrain(M2C_FIELD(var_r30_3034, SMNode **, 0x14), 0);
                    *(this + ((M2C_FIELD(this, u16 *, 0x268) * 2) + 0x26A)) = 0xFFFF;
                    temp_r12_3069 = this->unk144;
                    if (M2C_BITWISE(u32, temp_r12_3069) != 0U) {
                        M2C_BITWISE(M2C_UNK (*)(MKModel *, s32 *, s32), temp_r12_3069)(M2C_FIELD(var_r30_3034, MKModel **, 4), &this->unk260, M2C_FIELD(var_r30_3034, s32 *, 0x4C));
                    } else {
                        MKModel_Draw(M2C_FIELD(var_r30_3034, MKModel **, 4), (u16 *) &this->unk260);
                    }
                } else {
                    temp_r12_3084 = this->unk144;
                    if (M2C_BITWISE(u32, temp_r12_3084) != 0U) {
                        M2C_BITWISE(M2C_UNK (*)(MKModel *, M2C_UNK, s32), temp_r12_3084)(M2C_FIELD(var_r30_3034, MKModel **, 4), 0, M2C_FIELD(var_r30_3034, s32 *, 0x4C));
                    } else {
                        MKModel_Draw(M2C_FIELD(var_r30_3034, MKModel **, 4), NULL);
                    }
                }
            }
            var_r30_3034 = M2C_FIELD(var_r30_3034, void **, 0);
            goto loop_15;
        }
    }
}
#endif

#if 0 // DRAFT: pointer/array required
void MKDistanceLevelChunk::PostDrawWater() {
    f32 temp_r4_3119;
    f32 temp_r5_3116;

    temp_r5_3116 = this->unk14.unk80;
    if (M2C_BITWISE(u32, temp_r5_3116) != 0U) {
        temp_r4_3119 = this->unk14.unk84;
        if ((u16) *temp_r4_3119 != 0) {
            ((MKFFTWater *) (M2C_BITWISE(MKFFTWater *, temp_r5_3116)))->PostDrawOcean(M2C_BITWISE(u16 *, temp_r4_3119));
        }
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'float' to
void MKDistanceLevelChunk::DrawWater(int arg0) {
    MKModel *temp_r28_3145;
    f32 temp_r4_3141;
    f32 temp_r4_3187;
    s32 temp_r0_3161;
    s32 temp_r3_3156;
    s32 temp_r3_3160;
    s32 var_r26_3148;
    u16 var_r27_3147;

    temp_r4_3141 = this->unk14.unk80;
    if (M2C_BITWISE(u32, temp_r4_3141) != 0U) {
        temp_r28_3145 = M2C_FIELD(temp_r4_3141, MKModel **, 4);
        var_r27_3147 = 0;
        var_r26_3148 = 0;
loop_5:
        if (var_r26_3148 < MKModel_GetNmbrOfSubObjects(temp_r28_3145, (SubObjectType) 0)) {
            temp_r3_3156 = MKView_VisibilityTest(*(MKModel_GetBoundingVolume(temp_r28_3145, (SubObjectType) 0, var_r26_3148)), Matrix::identity);
            if (temp_r3_3156 != 0) {
                temp_r3_3160 = (var_r27_3147 * 2) & 0x1FFFE;
                temp_r0_3161 = (temp_r3_3156 - 1) - 1;
                var_r27_3147 += 1;
                *(M2C_BITWISE(s32, this->unk14.unk84) + (temp_r3_3160 + 2)) = var_r26_3148 | (0x8000 & ((temp_r0_3161 - temp_r0_3161) - !M2C_CARRY));
            }
            var_r26_3148 += 1;
            goto loop_5;
        }
        *this->unk14.unk84 = var_r27_3147;
        M2C_FIELD((M2C_BITWISE(s32, this->unk14.unk84) + ((var_r27_3147 * 2) & 0x1FFFE)), s16 *, 2) = 0xFFFF;
        temp_r4_3187 = this->unk14.unk84;
        if ((u16) *temp_r4_3187 != 0) {
            if (arg0 < 3) {
                ((MKFFTWater *) (M2C_BITWISE(MKFFTWater *, this->unk14.unk80)))->Draw(M2C_BITWISE(u16 *, temp_r4_3187), arg0);
                return;
            }
            ((MKFFTWater *) (M2C_BITWISE(MKFFTWater *, this->unk14.unk80)))->PreDrawOcean(M2C_BITWISE(u16 *, temp_r4_3187));
        }
    }
}
#endif

#if 0 // DRAFT: illegal type
void MKDistanceLevelChunk::UpdateProps() {
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f64 sp10;
    s32 spC;
    s32 sp8;
    MKProp *temp_r4_3245;
    f32 temp_f0_3293;
    f32 temp_f0_3365;
    f32 temp_f2_3282;
    f32 temp_f2_3354;
    f32 temp_f3_3278;
    f32 temp_f3_3350;
    f32 temp_f4_3277;
    f32 temp_f4_3349;
    f32 temp_r0_3216;
    f32 var_f2_3292;
    f32 var_f2_3364;
    f32 var_r31_3314;
    f32 var_r31_3388;
    s32 temp_r4_3317;
    s32 temp_r4_3391;
    s32 temp_r5_3249;
    s32 var_r30_3229;
    s32 var_r31_3242;
    u8 var_r3_3250;
    u8 var_r3_3318;
    u8 var_r3_3392;
    void *temp_r31_3431;
    void *temp_r3_3268;
    void *temp_r3_3340;
    void *temp_r5_3435;
    void *temp_r5_3441;
    void *var_r30_3241;
    void *var_r3_3432;

    temp_r0_3216 = this->unk14.unk78;
    if (((M2C_BITWISE(s32, temp_r0_3216) == 9) || (M2C_BITWISE(s32, temp_r0_3216) == 0xC)) && (this->unk134 & 2)) {
        spC = 0;
        sp8 = -3;
        var_r30_3229 = this->unk148;
loop_5:
        if ((u32) var_r30_3229 != 0U) {
            M2C_FIELD(M2C_FIELD(var_r30_3229, void **, 0x40), M2C_UNK (**)(s32), 0x18)(var_r30_3229);
            var_r30_3229 = M2C_FIELD(var_r30_3229, s32 *, 0x24);
            goto loop_5;
        }
        var_r30_3241 = this->unk29A8;
        var_r31_3242 = 0;
loop_20:
        if (var_r31_3242 < (s32) this->unk29B8) {
            temp_r4_3245 = M2C_FIELD(var_r30_3241, MKProp **, 0x28);
            var_r30_3241 += 0x30;
            if (temp_r4_3245 != NULL) {
                temp_r5_3249 = temp_r4_3245->unk18;
                var_r3_3250 = 0;
                if (!(temp_r5_3249 & 0x80000000) && (temp_r5_3249 & this->unk14.unk68 & 0x7FFFFFFF) && !(temp_r5_3249 & M2C_BITWISE(s32, this->unk14.unk6C) & 0x7FFFFFFF)) {
                    var_r3_3250 = 1;
                }
                if ((var_r3_3250 != 0) && !(temp_r4_3245->unk10 & 4)) {
                    temp_r3_3268 = temp_r4_3245->unk8;
                    sp20 = M2C_FIELD(temp_r3_3268, f64 *, 0x30);
                    sp28 = M2C_FIELD(temp_r3_3268, f64 *, 0x38);
                    temp_f4_3277 = (*(f32 *) ((u8 *) &sp20 + 0x4)) - M2C_FIELD(this, f32 *, 0x15C);
                    temp_f3_3278 = (f32) sp20 - M2C_FIELD(this, f32 *, 0x158);
                    temp_f2_3282 = (f32) sp28 - M2C_FIELD(this, f32 *, 0x160);
                    temp_r4_3245->unk24 = (temp_f2_3282 * temp_f2_3282) + ((temp_f3_3278 * temp_f3_3278) + (temp_f4_3277 * temp_f4_3277));
                    var_f2_3292 = M2C_FIELD(gMK, f32 *, 8);
                    temp_f0_3293 = M2C_FIELD(temp_r4_3245->unk0, f32 *, 4) * M2C_FIELD(gMK, f32 *, 4);
                    if (var_f2_3292 > temp_f0_3293) {

                    } else {
                        var_f2_3292 = temp_f0_3293;
                    }
                    if (temp_r4_3245->unk24 < (var_f2_3292 * var_f2_3292)) {
                        UpdateProp(temp_r4_3245, (MKMessage *) &sp8);
                    }
                }
            }
            var_r31_3242 += 1;
            goto loop_20;
        }
        var_r31_3314 = this->unk2A2C.unk20;
loop_35:
        if (M2C_BITWISE(u32, var_r31_3314) != &this->unk29E0.__vptr) {
            temp_r4_3317 = M2C_FIELD(var_r31_3314, s32 *, 0x18);
            var_r3_3318 = 0;
            if (!(temp_r4_3317 & 0x80000000) && (temp_r4_3317 & this->unk14.unk68 & 0x7FFFFFFF) && !(temp_r4_3317 & M2C_BITWISE(s32, this->unk14.unk6C) & 0x7FFFFFFF)) {
                var_r3_3318 = 1;
            }
            if ((var_r3_3318 == 0) || (M2C_FIELD(var_r31_3314, s32 *, 0x10) & 4)) {
                var_r31_3314 = M2C_FIELD(var_r31_3314, f32 *, 0x28);
            } else {
                temp_r3_3340 = M2C_FIELD(var_r31_3314, void **, 8);
                sp10 = M2C_FIELD(temp_r3_3340, f64 *, 0x30);
                sp18 = M2C_FIELD(temp_r3_3340, f64 *, 0x38);
                temp_f4_3349 = (*(f32 *) ((u8 *) &sp10 + 0x4)) - M2C_FIELD(this, f32 *, 0x15C);
                temp_f3_3350 = (f32) sp10 - M2C_FIELD(this, f32 *, 0x158);
                temp_f2_3354 = (f32) sp18 - M2C_FIELD(this, f32 *, 0x160);
                M2C_FIELD(var_r31_3314, f32 *, 0x24) = (f32) ((temp_f2_3354 * temp_f2_3354) + ((temp_f3_3350 * temp_f3_3350) + (temp_f4_3349 * temp_f4_3349)));
                var_f2_3364 = M2C_FIELD(gMK, f32 *, 8);
                temp_f0_3365 = M2C_FIELD(M2C_FIELD(var_r31_3314, void **, 0), f32 *, 4) * M2C_FIELD(gMK, f32 *, 4);
                if (var_f2_3364 > temp_f0_3365) {

                } else {
                    var_f2_3364 = temp_f0_3365;
                }
                if (M2C_FIELD(var_r31_3314, f32 *, 0x24) < (var_f2_3364 * var_f2_3364)) {
                    UpdateProp(M2C_BITWISE(MKProp *, var_r31_3314), (MKMessage *) &sp8);
                    var_r31_3314 = M2C_FIELD(var_r31_3314, f32 *, 0x28);
                } else {
                    var_r31_3314 = M2C_FIELD(var_r31_3314, f32 *, 0x28);
                }
            }
            goto loop_35;
        }
        var_r31_3388 = this->unk2A78.unk20;
loop_45:
        if (M2C_BITWISE(u32, var_r31_3388) != &this->unk2A2C.__vptr) {
            temp_r4_3391 = M2C_FIELD(var_r31_3388, s32 *, 0x18);
            var_r3_3392 = 0;
            if (!(temp_r4_3391 & 0x80000000) && (temp_r4_3391 & this->unk14.unk68 & 0x7FFFFFFF) && !(temp_r4_3391 & M2C_BITWISE(s32, this->unk14.unk6C) & 0x7FFFFFFF)) {
                var_r3_3392 = 1;
            }
            if ((var_r3_3392 == 0) || (M2C_FIELD(var_r31_3388, s32 *, 0x10) & 4)) {
                var_r31_3388 = M2C_FIELD(var_r31_3388, f32 *, 0x28);
            } else {
                UpdateProp(M2C_BITWISE(MKProp *, var_r31_3388), (MKMessage *) &sp8);
                var_r31_3388 = M2C_FIELD(var_r31_3388, f32 *, 0x28);
            }
            goto loop_45;
        }
        this->unk204 = 1 - this->unk204;
        sp8 = -4;
        temp_r31_3431 = this + ((this->unk204 * 0x4C) + 0x16C);
        var_r3_3432 = M2C_FIELD(temp_r31_3431, void **, 0x34);
loop_48:
        if (var_r3_3432 != temp_r31_3431) {
            temp_r5_3435 = M2C_FIELD(var_r3_3432, void **, 0x34);
            M2C_FIELD(temp_r5_3435, void **, 0x30) = (void *) M2C_FIELD(var_r3_3432, void **, 0x30);
            temp_r5_3441 = M2C_FIELD(var_r3_3432, void **, 0x30);
            M2C_FIELD(temp_r5_3441, void **, 0x34) = (void *) M2C_FIELD(var_r3_3432, void **, 0x34);
            M2C_FIELD(var_r3_3432, void **, 0x34) = NULL;
            M2C_FIELD(var_r3_3432, void **, 0x30) = NULL;
            M2C_FIELD(M2C_FIELD(var_r3_3432, void **, 0x44), M2C_UNK (**)(s32 *, void *), 0x2C)(&sp8, temp_r5_3441);
            var_r3_3432 = temp_r5_3435;
            goto loop_48;
        }
    }
}
#endif

#if 0 // DRAFT: illegal operand
s32 MKDistanceLevelChunk::Optimise() {
    s32 temp_r0_3469;
    s32 temp_r0_3500;
    s32 temp_r3_3527;
    s32 temp_r4_3493;
    s32 temp_r4_3517;
    s32 temp_r5_3494;

    temp_r0_3469 = this->unk2D50;
    switch (temp_r0_3469) {                         /* irregular */
    case 1:
        this->unk2D54 = 0;
        this->unk2D58 = M2C_FIELD((this + (this->unk2D54 * 0x50)), s32 *, 0x2AC4);
        this->unk2D50 = 2;
        /* fallthrough */
    case 2:
        temp_r4_3493 = this->unk2D54;
        temp_r5_3494 = this->unk2D58;
        if ((u32) temp_r5_3494 == (void *) (this + ((temp_r4_3493 * 0x50) + 0x2AC4))) {
            temp_r0_3500 = temp_r4_3493 + 1;
            this->unk2D54 = temp_r0_3500;
            if (temp_r0_3500 == 8) {
                this->unk2D50 = 4;
            } else {
                this->unk2D58 = M2C_FIELD((this + (this->unk2D54 * 0x50)), s32 *, 0x2AC4);
            }
        } else {
            ((SMTree *) (temp_r5_3494 + 0x10))->Reset();
            temp_r4_3517 = this->unk2D58;
            ((SMTree *) (temp_r4_3517 + 0x10))->Init((TerrainModel *) temp_r4_3517);
            this->unk2D50 = 3;
        }
block_19:
    default:
        return 0;
    case 3:
        ((SMTree *) (this->unk2D58 + 0x10))->Update();
        temp_r3_3527 = this->unk2D58;
        if ((s32) M2C_FIELD(temp_r3_3527, s32 *, 0x24) == 4) {
            this->unk2D58 = M2C_FIELD(temp_r3_3527, s32 *, 0);
            this->unk2D50 = 2;
        }
        goto block_19;
    case 4:
        ((SMTree *) &this->unk29A8)->Reset();
        ((SMTree *) &this->unk29A8)->Init((s32) this->unk29E0.unkC, (MKProp *) &this->unk29E0);
        this->unk2D50 = 5;
        goto block_19;
    case 5:
        ((SMTree *) &this->unk29A8)->Update();
        if ((s32) this->unk29BC == 4) {
            this->unk2D50 = 0;
            M2C_FIELD(this, s8 *, 0x168) = 1;
            return 1;
        }
        goto block_19;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'float' to
s32 MKDistanceLevelChunk::ResolveAllProps() {
    MKProp *temp_r3_3576;
    MKProp *temp_r3_3658;
    u32 temp_r26_3612;
    u32 temp_r27_3618;
    void *temp_r3_3623;

    temp_r3_3576 = this->unk14.unk110;
    if ((temp_r3_3576 == NULL) && ((void *) this->unk14.unk114 == NULL)) {
        this->unk14.unk114 = (void *) this->unk148;
        goto block_9;
    }
    if (temp_r3_3576 == &this->unk29E0) {
        this->unk14.unk110 = M2C_BITWISE(MKProp *, this->unk2A2C.unk20);
        goto block_9;
    }
    if (temp_r3_3576 == &this->unk29E0.__vptr) {
        this->unk14.unk110 = M2C_BITWISE(MKProp *, this->unk2A78.unk20);
        goto block_9;
    }
    if (temp_r3_3576 == &this->unk2A2C.__vptr) {
        this->unk14.unk110 = NULL;
        this->unk2D50 = 1;
        return 1;
    }
block_9:
    temp_r26_3612 = OSGetTick();
    temp_r27_3618 = (u32) (675000.0f * M2C_FIELD(gMK, f32 *, 0xB0));
    if ((void *) this->unk14.unk114 != NULL) {
loop_13:
        if ((u32) (OSGetTick() - temp_r26_3612) >= temp_r27_3618) {
            goto block_24;
        }
        temp_r3_3623 = this->unk14.unk114;
        M2C_FIELD(M2C_FIELD(temp_r3_3623, void **, 0x40), M2C_UNK (**)(void *), 0x20)(temp_r3_3623);
        this->unk14.unk114 = M2C_FIELD(this->unk14.unk114, void **, 0x24);
        if ((void *) this->unk14.unk114 == NULL) {
            this->unk14.unk110 = M2C_BITWISE(MKProp *, this->unk29E0.unk20);
            return 0;
        }
        goto loop_13;
    }
    if ((MKProp *) this->unk14.unk110 == NULL) {
        this->unk2D50 = 1;
        return 1;
    }
loop_23:
    if ((u32) (OSGetTick() - temp_r26_3612) >= temp_r27_3618) {
block_24:
        return 0;
    }
    temp_r3_3658 = this->unk14.unk110;
    if ((temp_r3_3658 == &this->unk29E0) || (temp_r3_3658 == &this->unk29E0.__vptr) || (temp_r3_3658 == &this->unk2A2C.__vptr)) {
        return 0;
    }
    M2C_FIELD(temp_r3_3658->__vptr, M2C_UNK (**)(), 0x1C)();
    this->unk14.unk110 = this->unk14.unk110->unk28;
    goto loop_23;
}
#endif

#if 0 // DRAFT: undefined identifier 'temp_r3_3699'
s32 MKDistanceLevelChunk::ResetAllProps() {
    MKProp *temp_r3_3699;
    MKProp *temp_r3_3741;
    u32 temp_r26_3730;
    u32 temp_r27_3735;

    temp_r3_3699 = this->unk14.unk110;
    if (temp_r3_3699 == NULL) {
        this->unk14.unk110 = M2C_BITWISE(MKProp *, this->unk29E0.unk20);
        goto block_8;
    }
    if (temp_r3_3699 == &this->unk29E0) {
        this->unk14.unk110 = M2C_BITWISE(MKProp *, this->unk2A2C.unk20);
        goto block_8;
    }
    if (temp_r3_3699 == &this->unk29E0.__vptr) {
        this->unk14.unk110 = M2C_BITWISE(MKProp *, this->unk2A78.unk20);
        goto block_8;
    }
    if (temp_r3_3699 == &this->unk2A2C.__vptr) {
        this->unk14.unk110 = NULL;
        return 1;
    }
block_8:
    temp_r26_3730 = OSGetTick();
    temp_r27_3735 = (u32) (675000.0f * M2C_FIELD(gMK, f32 *, 0xB0));
loop_14:
    if ((u32) (OSGetTick() - temp_r26_3730) >= temp_r27_3735) {
        return 0;
    }
    temp_r3_3741 = this->unk14.unk110;
    if ((temp_r3_3741 == &this->unk29E0) || (temp_r3_3741 == &this->unk29E0.__vptr) || (temp_r3_3741 == &this->unk2A2C.__vptr)) {
        return 0;
    }
    M2C_FIELD(temp_r3_3741->__vptr, M2C_UNK (**)(), 0x20)();
    this->unk14.unk110 = this->unk14.unk110->unk28;
    goto loop_14;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKProp *' to
s32 MKDistanceLevelChunk::DeinitChunk() {
    M2C_UNK *temp_r6_3842;
    s32 temp_r28_3805;
    s32 var_r26_3886;
    s32 var_r27_3802;
    s32 var_r29_3887;
    s32 var_r31_3781;
    u32 temp_r0_3782;
    void **temp_r3_3846;
    void **temp_r4_3845;
    void *temp_r24_3902;
    void *temp_r26_3810;
    void *temp_r27_3890;
    void *temp_r28_3889;
    void *var_r25_3891;
    void *var_r29_3806;

    var_r31_3781 = 0;
    temp_r0_3782 = this->unk4;
    switch (temp_r0_3782) {
    case 0:
        if (MKLevelChunk::DeinitChunk() != 0) {
            this->unk4 = 1;
        }
        break;
    case 1:
        if (this->unk138 & 0x100000) {
            var_r27_3802 = this->unk148;
loop_12:
            if ((u32) var_r27_3802 != 0U) {
                temp_r28_3805 = M2C_FIELD(var_r27_3802, s32 *, 0x24);
                var_r29_3806 = M2C_FIELD(var_r27_3802, void **, 0x28);
loop_10:
                if (var_r29_3806 != NULL) {
                    temp_r26_3810 = M2C_FIELD(var_r29_3806, void **, 0x38);
                    M2C_FIELD(M2C_FIELD(var_r29_3806, void **, 0x44), M2C_UNK (**)(void *), 0x18)(var_r29_3806);
                    if (var_r29_3806 != NULL) {
                        M2C_FIELD(M2C_FIELD(var_r29_3806, void **, 0x44), M2C_UNK (**)(void *, M2C_UNK), 8)(var_r29_3806, 1);
                    }
                    var_r29_3806 = temp_r26_3810;
                    goto loop_10;
                }
                M2C_FIELD(M2C_FIELD(var_r27_3802, void **, 0x40), M2C_UNK (**)(s32), 0x14)(var_r27_3802);
                operator delete((void *) var_r27_3802);
                var_r27_3802 = temp_r28_3805;
                goto loop_12;
            }
            this->unk148 = 0;
        }
        temp_r6_3842 = &this->unk29E0;
        this->unk29E0.unk20 = M2C_BITWISE(f32, temp_r6_3842);
        temp_r4_3845 = &this->unk29E0.__vptr;
        temp_r3_3846 = &this->unk2A2C.__vptr;
        this->unk29E0.unk24 = M2C_BITWISE(f32, temp_r6_3842);
        this->unk29E0.unkC = NULL;
        this->unk2A2C.unk20 = M2C_BITWISE(f32, temp_r4_3845);
        this->unk2A2C.unk24 = M2C_BITWISE(f32, temp_r4_3845);
        this->unk2A2C.unkC = NULL;
        this->unk2A78.unk20 = M2C_BITWISE(f32, temp_r3_3846);
        this->unk2A78.unk24 = M2C_BITWISE(f32, temp_r3_3846);
        this->unk2A78.unkC = NULL;
        this->unk4 = 2;
        break;
    case 2:
        if (this->unk138 & 0x100000) {
            ((SMTree *) &this->unk29A8)->Deinit();
        }
        this->unk4 = 5;
        break;
    case 5:
        if (MKLevelChunk::DeinitChunk() != 0) {
            this->unk4 = 4;
        }
        break;
    case 4:
        if (MKLevelChunk::DeinitChunk() != 0) {
            this->unk4 = 6;
        }
        break;
    case 6:
        if (this->unk138 & 4) {
            var_r26_3886 = 0;
            var_r29_3887 = 0;
            do {
                temp_r28_3889 = this + var_r29_3887;
                temp_r27_3890 = ((u8 *) temp_r28_3889) + 0x2AC4;
                var_r25_3891 = M2C_FIELD(temp_r28_3889, void **, 0x2AC4);
loop_28:
                if (var_r25_3891 != temp_r27_3890) {
                    if (this->unk138 & 0x400000) {
                        ((SMTree *) (((u8 *) var_r25_3891) + 0x10))->Deinit();
                    }
                    MKModel_Destroy(M2C_FIELD(var_r25_3891, MKModel **, 4));
                    temp_r24_3902 = M2C_FIELD(var_r25_3891, void **, 0);
                    operator delete(var_r25_3891);
                    var_r25_3891 = temp_r24_3902;
                    goto loop_28;
                }
                M2C_FIELD(temp_r28_3889, void **, 0x2AC4) = temp_r27_3890;
                var_r26_3886 += 1;
                var_r29_3887 += 0x50;
                M2C_FIELD(temp_r28_3889, void **, 0x2AD0) = temp_r27_3890;
            } while (var_r26_3886 < 8);
        }
        this->unk4 = 7;
        break;
    case 7:
        if (MKLevelChunk::DeinitChunk() != 0) {
            this->unk4 = 8;
        }
        break;
    case 8:
        if (MKLevelChunk::DeinitChunk() != 0) {
            var_r31_3781 = 1;
        }
        break;
    }
    return var_r31_3781;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
s32 MKDistanceLevelChunk::InitChunk() {
    M2C_UNK *temp_r0_3976;
    M2C_UNK *temp_r5_3981;
    s32 var_ctr_3965;
    s32 var_r31_3948;
    s32 var_r3_3964;
    void **temp_r7_3978;
    void **temp_r8_3977;
    void *temp_r0_3949;
    void *temp_r0_3969;
    void *temp_r4_3967;
    void *temp_r6_3980;

    var_r31_3948 = 0;
    temp_r0_3949 = this->__vptr;
    switch (temp_r0_3949) {                         /* irregular */
    case 0:
        var_r3_3964 = 0;
        var_ctr_3965 = 8;
        do {
            temp_r4_3967 = this + var_r3_3964;
            var_r3_3964 += 0x50;
            temp_r0_3969 = ((u8 *) temp_r4_3967) + 0x2AC4;
            M2C_FIELD(temp_r4_3967, void **, 0x2AC4) = temp_r0_3969;
            M2C_FIELD(temp_r4_3967, void **, 0x2AD0) = temp_r0_3969;
            var_ctr_3965 -= 1;
        } while (var_ctr_3965 != 0);
        this->unk29AC = NULL;
        temp_r0_3976 = &this->unk29E0;
        temp_r8_3977 = &this->unk29E0.__vptr;
        temp_r7_3978 = &this->unk2A2C.__vptr;
        this->unk29E0.unk20 = M2C_BITWISE(f32, temp_r0_3976);
        temp_r6_3980 = this + 0x16C;
        temp_r5_3981 = &this->unk1B8;
        this->unk29E0.unk24 = M2C_BITWISE(f32, temp_r0_3976);
        this->unk29E0.unkC = NULL;
        this->unk2A2C.unk20 = M2C_BITWISE(f32, temp_r8_3977);
        this->unk2A2C.unk24 = M2C_BITWISE(f32, temp_r8_3977);
        this->unk2A2C.unkC = NULL;
        this->unk2A78.unk20 = M2C_BITWISE(f32, temp_r7_3978);
        this->unk2A78.unk24 = M2C_BITWISE(f32, temp_r7_3978);
        this->unk2A78.unkC = NULL;
        this->unk1A0 = temp_r6_3980;
        this->unk19C = temp_r6_3980;
        this->unk1EC = temp_r5_3981;
        this->unk1E8 = temp_r5_3981;
        this->unk204 = 0;
        M2C_FIELD(this, s8 *, 0x168) = 0;
        this->unk208 = 0xFFFFFF;
        this->unk204 = 0x80000000;
        this->__vptr = (void *)1;
        break;
    case 1:
        if (MKLevelChunk::InitChunk() != 0) {
            this->__vptr = (void *)2;
        }
        break;
    case 2:
        if (MKLevelChunk::InitChunk() != 0) {
            this->__vptr = (void *)3;
        }
        break;
    case 3:
        if (MKLevelChunk::InitChunk() != 0) {
            this->__vptr = (void *)4;
        }
        break;
    case 4:
        if (MKLevelChunk::InitChunk() != 0) {
            var_r31_3948 = 1;
        }
        break;
    }
    return var_r31_3948;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void MKDistanceLevelChunk::Deinit() {
    this->unk2A2C.unk20 = M2C_BITWISE(f32, &this->unk29E0.__vptr);
    this->unk29E0.unk20 = M2C_BITWISE(f32, &this->unk29E0);
    this->unk2A78.unk20 = M2C_BITWISE(f32, &this->unk2A2C.__vptr);
    MKLevelChunk::Deinit();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKProp *' to
void MKDistanceLevelChunk::Init(MKLevelChunk::MKLevelChunkInit *arg1) {
    M2C_UNK *temp_r0_4086;
    M2C_UNK *temp_r6_4080;
    s32 var_ctr_4071;
    s32 var_r3_4066;
    void **temp_r4_4083;
    void **temp_r5_4082;
    void *temp_r0_4075;
    void *temp_r3_4084;
    void *temp_r4_4073;

    MKLevelChunk::Init(arg1);
    var_r3_4066 = 0;
    this->unk148 = 0;
    this->unk258 = 0.0f;
    this->unk264 = 0;
    var_ctr_4071 = 8;
    do {
        temp_r4_4073 = this + var_r3_4066;
        var_r3_4066 += 0x50;
        temp_r0_4075 = ((u8 *) temp_r4_4073) + 0x2AC4;
        M2C_FIELD(temp_r4_4073, void **, 0x2AC4) = temp_r0_4075;
        M2C_FIELD(temp_r4_4073, void **, 0x2AD0) = temp_r0_4075;
        var_ctr_4071 -= 1;
    } while (var_ctr_4071 != 0);
    temp_r6_4080 = &this->unk29E0;
    this->unk29AC = NULL;
    temp_r5_4082 = &this->unk29E0.__vptr;
    temp_r4_4083 = &this->unk2A2C.__vptr;
    temp_r3_4084 = this + 0x16C;
    this->unk29E0.unk20 = M2C_BITWISE(f32, temp_r6_4080);
    temp_r0_4086 = &this->unk1B8;
    this->unk29E0.unk24 = M2C_BITWISE(f32, temp_r6_4080);
    this->unk29E0.unkC = NULL;
    this->unk2A2C.unk20 = M2C_BITWISE(f32, temp_r5_4082);
    this->unk2A2C.unk24 = M2C_BITWISE(f32, temp_r5_4082);
    this->unk2A2C.unkC = NULL;
    this->unk2A78.unk20 = M2C_BITWISE(f32, temp_r4_4083);
    this->unk2A78.unk24 = M2C_BITWISE(f32, temp_r4_4083);
    this->unk2A78.unkC = NULL;
    this->unk1A0 = temp_r3_4084;
    this->unk19C = temp_r3_4084;
    this->unk1EC = temp_r0_4086;
    this->unk1E8 = temp_r0_4086;
    this->unk204 = 0;
}
#endif

void CalcBoundingBox(MKProp *arg0, BoundingVolume *arg1) {
    f64 spD0;                                       /* compiler-managed */
    f64 spC8;
    f64 spC0;                                       /* compiler-managed */
    f64 spB8;
    f64 spB0;                                       /* compiler-managed */
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;                                       /* compiler-managed */
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;                                       /* compiler-managed */
    f64 sp60;
    f64 sp58;
    f64 sp50;                                       /* compiler-managed */
    f64 sp48;                                       /* compiler-managed */
    f64 sp40;                                       /* compiler-managed */
    f64 sp38;                                       /* compiler-managed */
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f64 sp10;
    f64 sp8;
    BoundingVolume *var_r6_4111;
    f32 temp_f1_4224;
    f32 temp_f1_4240;
    f32 temp_f2_4249;
    f32 temp_f2_4258;
    f32 temp_f2_4267;
    f32 temp_f3_4128;
    f32 temp_f3_4172;
    f32 temp_f6_4177;
    f32 temp_f7_4132;
    f32 temp_f7_4186;
    f32 var_f0_4222;
    f32 var_f0_4239;
    f32 var_f0_4257;
    f32 var_f1_4248;
    f32 var_f1_4266;
    f32 var_f2_4231;
    f64 temp_f8_4121;
    f64 temp_f9_4119;
    s32 var_ctr_4166;
    s32 var_ctr_4219;
    s32 var_r3_4212;
    s32 var_r5_4122;
    void *temp_r5_4223;
    void *temp_r6_4168;
    void *temp_r7_4170;

    var_r6_4111 = arg0->unkC;
    if (var_r6_4111 != NULL) {

    } else {
        var_r6_4111 = M2C_FIELD(arg0->unk0, BoundingVolume **, 0x1C);
    }
    temp_f9_4119 = M2C_FIELD(var_r6_4111, f64 *, 0);
    temp_f8_4121 = M2C_FIELD(var_r6_4111, f64 *, 8);
    var_r5_4122 = 0;
    sp68 = temp_f9_4119;
    sp78 = temp_f9_4119;
    temp_f3_4128 = var_r6_4111->unk14;
    sp90 = temp_f8_4121;
    temp_f7_4132 = var_r6_4111->unk18;
    sp68 = (f32) sp68 + var_r6_4111->unk10;
    spB0 = temp_f8_4121;
    sp98 = (f64) sp68;
    spC0 = temp_f8_4121;
    spD0 = temp_f8_4121;
    (*(f32 *) ((u8 *) &sp78 + 0x4)) += temp_f3_4128;
    (*(f32 *) ((u8 *) &sp98 + 0x4)) += temp_f3_4128;
    sp58 = temp_f9_4119;
    sp60 = temp_f8_4121;
    sp70 = temp_f8_4121;
    sp80 = temp_f8_4121;
    sp88 = temp_f9_4119;
    sp90 = (f32) sp90 + temp_f7_4132;
    spA0 = temp_f8_4121;
    spA8 = (f64) sp68;
    spB0 = (f32) spB0 + temp_f7_4132;
    spB8 = sp78;
    spC0 = (f32) spC0 + temp_f7_4132;
    spC8 = sp98;
    spD0 = (f32) spD0 + temp_f7_4132;
    var_ctr_4166 = 8;
    do {
        temp_r6_4168 = arg0->unk8;
        temp_r7_4170 = &sp58 + var_r5_4122;
        var_r5_4122 += 0x10;
        temp_f3_4172 = M2C_FIELD(temp_r7_4170, f32 *, 4);
        temp_f6_4177 = M2C_FIELD(temp_r7_4170, f32 *, 0);
        temp_f7_4186 = M2C_FIELD(temp_r7_4170, f32 *, 8);
        sp18 = M2C_FIELD(temp_r6_4168, f32 *, 0x30) + ((temp_f7_4186 * M2C_FIELD(temp_r6_4168, f32 *, 0x20)) + ((temp_f6_4177 * M2C_FIELD(temp_r6_4168, f32 *, 0)) + (temp_f3_4172 * M2C_FIELD(temp_r6_4168, f32 *, 0x10))));
        sp1C = M2C_FIELD(temp_r6_4168, f32 *, 0x34) + ((temp_f7_4186 * M2C_FIELD(temp_r6_4168, f32 *, 0x24)) + ((temp_f6_4177 * M2C_FIELD(temp_r6_4168, f32 *, 4)) + (temp_f3_4172 * M2C_FIELD(temp_r6_4168, f32 *, 0x14))));
        sp20 = M2C_FIELD(temp_r6_4168, f32 *, 0x38) + ((temp_f7_4186 * M2C_FIELD(temp_r6_4168, f32 *, 0x28)) + ((temp_f6_4177 * M2C_FIELD(temp_r6_4168, f32 *, 8)) + (temp_f3_4172 * M2C_FIELD(temp_r6_4168, f32 *, 0x18))));
        M2C_FIELD(temp_r7_4170, f32 *, 0) = (f64) sp18;
        sp28 = (f64) sp18;
        sp30 = (f64) sp20;
        M2C_FIELD(temp_r7_4170, f32 *, 8) = (f64) sp20;
        var_ctr_4166 -= 1;
    } while (var_ctr_4166 != 0);
    var_r3_4212 = 0x10;
    sp8 = sp58;
    sp10 = sp60;
    sp48 = sp58;
    sp50 = sp60;
    sp38 = sp58;
    sp40 = sp60;
    var_ctr_4219 = 7;
    do {
        var_f0_4222 = (f32) sp48;
        temp_r5_4223 = &sp58 + var_r3_4212;
        temp_f1_4224 = M2C_FIELD(temp_r5_4223, f32 *, 0);
        if (var_f0_4222 < temp_f1_4224) {

        } else {
            var_f0_4222 = temp_f1_4224;
        }
        var_f2_4231 = (f32) sp38;
        sp48 = var_f0_4222;
        if (var_f2_4231 > temp_f1_4224) {

        } else {
            var_f2_4231 = temp_f1_4224;
        }
        var_f0_4239 = (*(f32 *) ((u8 *) &sp30 + 0x1c));
        temp_f1_4240 = M2C_FIELD(temp_r5_4223, f32 *, 4);
        sp38 = var_f2_4231;
        if (var_f0_4239 < temp_f1_4240) {

        } else {
            var_f0_4239 = temp_f1_4240;
        }
        var_f1_4248 = (*(f32 *) ((u8 *) &sp30 + 0xc));
        temp_f2_4249 = M2C_FIELD(temp_r5_4223, f32 *, 4);
        (*(f32 *) ((u8 *) &sp30 + 0x1c)) = var_f0_4239;
        if (var_f1_4248 > temp_f2_4249) {

        } else {
            var_f1_4248 = temp_f2_4249;
        }
        var_f0_4257 = (f32) sp50;
        temp_f2_4258 = M2C_FIELD(temp_r5_4223, f32 *, 8);
        (*(f32 *) ((u8 *) &sp30 + 0xc)) = var_f1_4248;
        if (var_f0_4257 < temp_f2_4258) {

        } else {
            var_f0_4257 = temp_f2_4258;
        }
        var_f1_4266 = (f32) sp40;
        temp_f2_4267 = M2C_FIELD(temp_r5_4223, f32 *, 8);
        sp50 = var_f0_4257;
        if (var_f1_4266 > temp_f2_4267) {

        } else {
            var_f1_4266 = temp_f2_4267;
        }
        sp40 = var_f1_4266;
        var_r3_4212 += 0x10;
        var_ctr_4219 -= 1;
    } while (var_ctr_4219 != 0);
    arg1->unk0 = sp48;
    arg1->unk4 = (*(f32 *) ((u8 *) &sp30 + 0x1c));
    arg1->unk8 = sp50;
    arg1->unk10 = sp38 - sp48;
    arg1->unk14 = (*(f32 *) ((u8 *) &sp30 + 0xc)) - (*(f32 *) ((u8 *) &sp30 + 0x1c));
    arg1->unk18 = (f32) var_f1_4266 - sp50;
}

s32 SortPropCompare(const void *arg0, const void *arg1) {
    return (s32) (M2C_FIELD(arg0, f32 *, 4) - M2C_FIELD(arg1, f32 *, 4));
}
