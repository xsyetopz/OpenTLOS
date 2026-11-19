#include "spyro/source/EarthBreathWhirlWinds.h"
#include "common/Source/Animation.h"
#include "common/Source/Font.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKFont.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/AITargetData.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Character.h"
#include "spyro/source/CharacterGraph.h"
#include "spyro/source/CollisionObject.h"
#include "spyro/source/Crate.h"
#include "spyro/source/DialogBox.h"
#include "spyro/source/EnemyRegion.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FallingLeaves.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/KDFaderObject.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/Level.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/SB2.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/TargetManager.h"
#include "spyro/source/WindFX.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDRandom.h"
#include "unplaced_inlines.h"
#include <m2c_macros.h>

M2C_UNK free(MKHeap *);                             /* extern */
MKHeap *malloc(M2C_UNK);                            /* extern */
extern s32 GS_SpyroFuryEarthTornadoLP;
extern M2C_UNK gEmptyPtrListDL;
extern MKSceneManager *gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;

void EarthBreathWhirlWinds::SpawnWhirlWind(const MKVector3 &arg0, const MKVector3 &arg1, Upgrade arg2, bool arg3, float arg4) {
    u8 *list;
    KDSoundFader *fader;
    Matrix *mtx;
    MKVector3 vecA;
    MKVector3 vecB;
    MKVector3 rnd;
    MKVector3 fwd;
    MKVector3 up;
    f32 sum;
    f32 inv;
    f32 sp8;
    f32 sp10;
    f32 sp14;
    f32 sp18;
    f64 t1;
    f64 t2;
    f64 t3;
    s32 bits;
    s32 kind;

    list = (u8 *) this->unk4C;
    fader = M2C_FIELD(list, KDSoundFader **, -4);
    if (fader != NULL) {
        this->unk4C = (MKHeap *) (list - 4);

        vecA.unk0 = -1.0f;
        vecA.unk4 = 0.0f;
        vecA.unk8 = -1.0f;
        vecA.unkC = 0.0f;
        vecB.unk0 = 1.0f;
        vecB.unk4 = 0.0f;
        vecB.unk8 = 1.0f;
        vecB.unkC = 0.0f;
        rnd = KDRand_Vector(vecA, vecB);

        sum = (rnd.unk8 * rnd.unk8) + ((rnd.unk0 * rnd.unk0) + (rnd.unk4 * rnd.unk4));
        if (sum > 1e-12f) {
            if (sum > 0.0f) {
                t1 = __frsqrte(sum);
                t2 = 0.5 * t1 * -(((f64) sum * (t1 * t1)) - 3.0);
                t3 = 0.5 * t2 * -(((f64) sum * (t2 * t2)) - 3.0);
                sum = (f32) ((f64) sum * (0.5 * t3 * -(((f64) sum * (t3 * t3)) - 3.0)));
            } else if (sum < 0.0f) {
                sum = __float_nan;
            } else {
                sp8 = sum;
                bits = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (bits) {
                case 0x7F800000:
                    kind = (M2C_BITWISE(s32, sp8) & 0x7FFFFF) ? 1 : 2;
                    break;
                case 0x0:
                    kind = (M2C_BITWISE(s32, sp8) & 0x7FFFFF) ? 5 : 3;
                    break;
                default:
                    kind = 4;
                    break;
                }
                if (kind == 1) {
                    sum = __float_nan;
                }
            }
            inv = 1.0f / sum;
        } else {
            inv = 0.0f;
        }

        sp10 = rnd.unk0 * inv;
        sp14 = rnd.unk4 * inv;
        sp18 = rnd.unk8 * inv;
        fwd.unk0 = sp10;
        fwd.unk4 = sp14;
        fwd.unk8 = sp18;
        fwd.unkC = 0.0f;

        M2C_STRUCT_COPY((u8 *) fader + 0xA0, &Matrix::identity, 0x40);
        mtx = (Matrix *) ((u8 *) fader + 0xA0);
        up.unk0 = 0.0f;
        up.unk4 = 1.0f;
        up.unk8 = 0.0f;
        up.unkC = 0.0f;
        KDMath_BuildMatrixFromFwd(mtx, fwd, &up);
        mtx->Scale3x3(mtx, arg1);

        M2C_FIELD(fader, f32 *, 0xD0) = arg0.unk0;
        M2C_FIELD(fader, f32 *, 0xD4) = arg0.unk4;
        M2C_FIELD(fader, f32 *, 0xD8) = arg0.unk8;
        M2C_FIELD(fader, f32 *, 0xDC) = 1.0f;
        M2C_FIELD(fader, f32 *, 0xF4) = 0.5f;
        M2C_FIELD(fader, s32 *, 0x100) = 1;
        M2C_FIELD(fader, f32 *, 0xF8) = 1.0f;
        M2C_STRUCT_COPY((u8 *) fader + 0xE0, &fwd, 0x10);
        M2C_FIELD(fader, f32 *, 0xFC) = 0.0f;
        M2C_FIELD(fader, s32 *, 0x104) = (s32) arg2;
        fader->Init(1.0f, 1.0f);
        M2C_STRUCT_COPY((u8 *) fader + 0x50, &arg0, 0x10);
        M2C_FIELD(fader, f32 *, 0x48) = 50.0f * arg1.unk0;
        M2C_FIELD(fader, f32 *, 0x4C) = 50.0f * arg1.unk4;
        M2C_STRUCT_COPY((u8 *) fader + 0x60, &Matrix::identity, 0x40);
        mtx = (Matrix *) ((u8 *) fader + 0x60);
        mtx->RotateYaw(mtx, 0.3926991f);
        M2C_FIELD(fader, u8 *, 0x108) = arg3;
        M2C_FIELD(fader, f32 *, 0xF0) = arg4;
    }
}

extern "C" void free(void *);
void EarthBreathWhirlWinds::Deinit() {
    u32 *base;
    u32 *p;
    u32 *q;
    u32 val;
    u32 min;

    MKModel_Destroy(this->unk50);
    p = (u32 *) this->unk4C;
    while (p != NULL && *p != 0) {
        KDSound_Stop((int *) *p);
        p++;
    }
    base = (u32 *) this->unk4C;
    min = (u32) base;
    p = base - 1;
    val = *p;
    while (val != 0) {
        if (val < min) {
            min = val;
        }
        p--;
        val = *p;
    }
    if (p != (u32 *) &gEmptyPtrListDL) {
        q = base;
        val = *q;
        while (val != 0) {
            if (val < min) {
                min = val;
            }
            q++;
            val = *q;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free((void *) min, NULL, 0);
        } else {
            free((void *) min);
        }
    }
    this->unk4C = NULL;
    MKProp::Deinit();
}

#if 0 // DRAFT: function call 'Draw(MKProp *, MKModel **, unsigned char *, double)' does not match 'MKProp::Draw()'
void EarthBreathWhirlWinds::Draw() {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKHeap *temp_r31_401;
    MKHeap *var_r30_348;
    MKModel **temp_r4_371;
    MKProp *temp_r3_382;
    MKProp *temp_r3_390;
    void *temp_r5_372;

    var_r30_348 = this->unk4C;
loop_2:
    if (var_r30_348 != NULL) {
        temp_r31_401 = var_r30_348->unk0;
        if (temp_r31_401 != NULL) {
            MKModel_SetWorldMatrix(this->unk50, *((Matrix *) &temp_r31_401->unkA0));
            sp18 = 1.0f;
            sp1C = 1.0f;
            sp20 = 1.0f;
            sp24 = temp_r31_401->unkF8;
            sp38 = (f64) sp18;
            sp40 = (f64) sp20;
            MKModel_SetColor(this->unk50, *((MKVector4 *) &sp38));
            MKModel_Draw(this->unk50, NULL);
            temp_r4_371 = &temp_r31_401->unk9C;
            temp_r5_372 = this->unk54 + 0x5C;
            M2C_STRUCT_COPY((s32) ((u8 *) temp_r5_372) + 4, (s32) temp_r4_371 + 4, 0x40);
            sp8 = 1.0f;
            temp_r3_382 = this->unk54;
            spC = 1.0f;
            sp10 = 1.0f;
            sp14 = temp_r31_401->unkF8;
            M2C_FIELD(temp_r3_382, f64 *, 0x50) = (f64) sp8;
            M2C_FIELD(temp_r3_382, f64 *, 0x58) = (f64) sp10;
            temp_r3_390 = this->unk54;
            sp28 = (f64) sp8;
            sp30 = (f64) sp10;
            temp_r3_390->Draw(temp_r4_371 + 0x40, ((u8 *) temp_r5_372) + 0x40, (f64) sp8);
            var_r30_348 += 4;
            goto loop_2;
        }
    }
}
#endif

void EarthBreathWhirlWinds::Message(MKMessage *arg0) {
    MKHeap *temp_r3_432;
    MKHeap *var_r31_423;

    var_r31_423 = this->unk4C;
loop_2:
    if (var_r31_423 != NULL) {
        temp_r3_432 = var_r31_423->unk0;
        if (temp_r3_432 != NULL) {
            ((KDSoundPlayer *) temp_r3_432)->Message(arg0);
            var_r31_423 += 4;
            goto loop_2;
        }
    }
    MKProp::Message(arg0);
}

#if 0 // DRAFT: undefined identifier '__vptr'
void *EarthBreathWhirlWinds::Update() {
    f32 sp310;
    f64 sp308;
    f64 sp300;
    s32 sp2F8;
    s32 sp2F4;
    s32 sp2F0;
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
    MKVector3 sp290;
    f64 sp288;
    f64 sp280;
    f64 sp278;
    f64 sp270;
    f64 sp268;
    f64 sp260;
    MKVector3 sp250;
    f64 sp248;
    f64 sp240;
    f64 sp238;
    f64 sp230;
    f64 sp228;
    f64 sp220;
    MKVector3 sp210;
    MKVector3 sp200;
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
    MKVector3 sp190;
    MKVector3 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f32 sp138;
    f32 sp134;
    f32 sp130;
    f32 sp128;
    f32 sp124;
    f32 sp120;
    f32 sp118;
    f64 sp110;
    f32 sp108;
    f32 sp104;
    f32 sp100;
    f32 spF8;
    f32 spF4;
    f32 spF0;
    f32 spE8;
    f64 spE0;
    f32 spD8;
    f64 spD0;
    f32 spC8;
    f64 spC0;
    f32 spB8;
    f64 spB0;
    f32 spA8;
    f64 spA0;
    f32 sp98;
    f64 sp90;
    f32 sp88;
    f64 sp80;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp68;
    f32 sp64;
    f32 sp60;
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
    f32 sp18;
    f32 sp14;
    s32 sp10;
    s32 sp8;
    Character *temp_r22_876;
    MKHeap *temp_r29_962;
    MKHeap *temp_r3_781;
    MKHeap *temp_r4_784;
    MKHeap *var_r26_485;
    MKProp *temp_r3_968;
    TargetManager ***var_r23_865;
    TargetManager **temp_r24_954;
    f32 temp_f21_1013;
    f32 temp_r0_508;
    f32 temp_r0_522;
    f32 var_f0_536;
    f32 var_f0_751;
    f32 var_f28_838;
    f64 temp_f0_593;
    f64 temp_f0_637;
    f64 temp_f0_712;
    f64 temp_f0_793;
    f64 temp_f0_803;
    f64 temp_f0_909;
    f64 temp_f1_1041;
    f64 temp_f1_903;
    f64 temp_f1_939;
    s32 temp_cr0_eq_889;
    s32 temp_r0_837;
    s32 temp_r5_937;
    s32 var_r24_666;
    s8 *temp_r28_496;
    u8 var_r27_490;
    u8 var_r6_501;
    void *temp_r22_983;
    void *temp_r30_487;
    void *temp_r3_902;
    void *temp_r3_972;

    this->unk58 -= gUpdateTimeDelta;
    var_r26_485 = this->unk4C;
    temp_r30_487 = checked_cast<EarthBreathWhirlWindsDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    var_r27_490 = 0;
loop_59:
    if ((var_r26_485 == NULL) || (temp_r29_962 = var_r26_485->unk0, ((temp_r29_962 == NULL) != 0))) {
        if (var_r27_490 != 0) {
            temp_r3_968 = this->unk54;
            temp_r3_972 = M2C_FIELD(temp_r3_968->__vptr, void *(**)(MKProp *), 0x3C)(temp_r3_968);
            if (temp_r3_972 != NULL) {
                sp48 = 1.0f;
                temp_r22_983 = M2C_FIELD(temp_r3_972, void **, 0x2C);
                sp58 = -1.0f;
                sp40 = 1.0f;
                sp44 = 0.5f;
                sp50 = -1.0f;
                sp54 = 0.0f;
                sp160 = (f64) sp40;
                sp168 = (f64) sp48;
                sp170 = (f64) sp50;
                sp178 = (f64) sp58;
                sp180 = KDRand_Vector(*((MKVector3 *) &sp170), *((MKVector3 *) &sp160));
                sp190 = Normalise(sp180);
                M2C_FIELD(temp_r3_972, MKVector3 *, 0) = sp190;
                M2C_FIELD(temp_r3_972, f32 *, 0x20) = 0.0f;
                M2C_FIELD(temp_r3_972, f32 *, 0x28) = 0.0f;
                temp_f21_1013 = MKRand_Float((int *) &gViewSeed, 100.0f, 500.0f);
                sp20 = -(f32) M2C_FIELD(temp_r3_972, f64 *, 0);
                sp24 = -M2C_FIELD(temp_r3_972, f32 *, 4);
                sp28 = -(f32) M2C_FIELD(temp_r3_972, f64 *, 8);
                sp140 = (f64) sp20;
                sp148 = (f64) sp28;
                sp30 = sp140 * (f64) temp_f21_1013;
                M2C_FIELD(temp_r22_983, f64 *, 0) = sp30;
                sp38 = (f32) sp148 * temp_f21_1013;
                sp150 = sp30;
                sp158 = (f64) sp38;
                M2C_FIELD(temp_r22_983, f64 *, 8) = (f64) sp38;
                temp_f1_1041 = MKRand_Float((int *) &gViewSeed, 100.0f, 200.0f);
                M2C_FIELD(temp_r3_972, f64 *, 0) = (f64) (M2C_FIELD(temp_r3_972, f64 *, 0) * temp_f1_1041);
                M2C_FIELD(temp_r3_972, f64 *, 8) = (f32) ((f32) M2C_FIELD(temp_r3_972, f64 *, 8) * (f32) temp_f1_1041);
                M2C_FIELD(temp_r22_983, f32 *, 0x18) = MKRand_Float((int *) &gViewSeed, 2.5f, 3.5f);
                M2C_FIELD(temp_r22_983, f32 *, 0x10) = MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f);
                M2C_FIELD(temp_r22_983, f32 *, 0x14) = (f32) M2C_FIELD(this->unk54, f32 *, 0xF4);
            }
        }
        if (this->unk58 <= 0.0f) {
            this->unk58 = 0.1f;
        }
    } else {
        temp_r28_496 = &temp_r29_962->unkD0;
        var_r27_490 = 1;
        var_r6_501 = 0;
        temp_r29_962->unkF4 = M2C_BITWISE(f32, temp_r29_962->unkF4) - gUpdateTimeDelta;
        temp_r29_962->unkFC -= gUpdateTimeDelta;
        sp8 = 1;
        temp_r0_508 = temp_r29_962->unk100;
        if ((M2C_BITWISE(s32, temp_r0_508) == 1) || (M2C_BITWISE(s32, temp_r0_508) == 2)) {
            var_r6_501 = 1;
        }
        ((KDSoundFader *) temp_r29_962)->Update(GS_SpyroFuryEarthTornadoLP, 1U, var_r6_501, NULL, (MKVector3 *) temp_r28_496, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
        temp_r0_522 = temp_r29_962->unk100;
        switch (M2C_BITWISE(s32, temp_r0_522)) {    /* switch 1; irregular */
        case 0:                                     /* switch 1 */
            break;
        case 1:                                     /* switch 1 */
            var_f0_536 = M2C_BITWISE(f32, temp_r29_962->unkF4);
            if (var_f0_536 < 0.5f) {

            } else {
                var_f0_536 = 0.5f;
            }
            if (var_f0_536 > 0.0f) {

            } else {
                var_f0_536 = 0.0f;
            }
            temp_r29_962->unkF4 = var_f0_536;
            temp_r29_962->unkF8 = 1.0f - (M2C_BITWISE(f32, temp_r29_962->unkF4) / 1.5f);
            if (M2C_BITWISE(f32, temp_r29_962->unkF4) <= 0.0f) {
                temp_r29_962->unk100 = 3e-45f;
                temp_r29_962->unkF4 = temp_r29_962->unkF0;
            }
        default:                                    /* switch 1 */
block_34:
            temp_f0_793 = M2C_FIELD(temp_r29_962, f64 *, 0xE0) * 5.49408334e-315;
            spC0 = temp_f0_793;
            sp1B0 = temp_f0_793;
            spC8 = M2C_BITWISE(f32, temp_r29_962->unkE8) * 50.0f;
            sp1B8 = (f64) spC8;
            temp_f0_803 = temp_f0_793 * (f64) gUpdateTimeDelta;
            spB0 = temp_f0_803;
            sp1C0 = temp_f0_803;
            spB8 = (f32) sp1B8 * gUpdateTimeDelta;
            sp1C8 = (f64) spB8;
            spA0 = M2C_FIELD(temp_r29_962, f64 *, 0xD0) + temp_f0_803;
            sp2C0 = spA0;
            spA8 = temp_r29_962->unkD8 + (f32) sp1C8;
            M2C_FIELD(temp_r29_962, f64 *, 0xD0) = (f32) sp2C0;
            sp2C8 = (f64) spA8;
            temp_r29_962->unkD4 = (*(f32 *) ((u8 *) &sp2C0 + 0x4));
            temp_r29_962->unkD8 = (f32) sp2C8;
            temp_r29_962->unkDC = 1.0f;
            M2C_FIELD(temp_r29_962, f64 *, 0x50) = spA0;
            M2C_FIELD(temp_r29_962, f64 *, 0x58) = (f64) spA8;
            if (temp_r29_962->unkFC <= 0.0f) {
                temp_r0_837 = temp_r29_962->unk104;
                var_f28_838 = 500.0f;
                switch (temp_r0_837) {              /* switch 2; irregular */
                case 0:                             /* switch 2 */
                    break;
                case 1:                             /* switch 2 */
                    var_f28_838 = 700.0f;
                    break;
                case 2:                             /* switch 2 */
                    var_f28_838 = 1000.0f;
                    break;
                case 3:                             /* switch 2 */
                    var_f28_838 = 1500.0f;
                    break;
                }
                temp_r29_962->unkFC = 0.5f;
                var_r23_865 = gb.unk20->Begin();
loop_56:
                if (var_r23_865 != NULL) {
                    temp_r24_954 = *var_r23_865;
                    if (temp_r24_954 != NULL) {
                        temp_r22_876 = ((Character *(*)(TargetManager **)) (*temp_r24_954)->unk8.unk4)(temp_r24_954);
                        if (((*temp_r24_954)->unk8.unk0(temp_r24_954) != NULL) && (M2C_FIELD(*temp_r24_954, u8 (**)(TargetManager **), 0x18)(temp_r24_954) != 0) && ((temp_cr0_eq_889 = temp_r22_876 == NULL, (temp_cr0_eq_889 != 0)) || ((temp_cr0_eq_889 == 0) && (temp_r22_876->IsActive() != 0)))) {
                            temp_r3_902 = M2C_FIELD((*temp_r24_954)->unk8.unk0(temp_r24_954), void **, 8);
                            temp_f1_903 = M2C_FIELD(temp_r3_902, f64 *, 0x30);
                            sp1A0 = temp_f1_903;
                            sp1A8 = M2C_FIELD(temp_r3_902, f64 *, 0x38);
                            temp_f0_909 = temp_f1_903 - M2C_FIELD(temp_r29_962, f64 *, 0xD0);
                            sp90 = temp_f0_909;
                            sp2B0 = temp_f0_909;
                            sp98 = (f32) sp1A8 - temp_r29_962->unkD8;
                            sp2B8 = (f64) sp98;
                            if (((((f32) sp2B8 * (f32) sp2B8) + (((f32) sp2B0 * (f32) sp2B0) + ((*(f32 *) ((u8 *) &sp2B0 + 0x4)) * (*(f32 *) ((u8 *) &sp2B0 + 0x4))))) <= (var_f28_838 * var_f28_838)) && (temp_r22_876 != NULL)) {
                                sp2F4 = 0;
                                temp_r5_937 = temp_r29_962->unk104;
                                sp2F0 = 0xA4;
                                temp_f1_939 = M2C_FIELD(temp_r29_962, f64 *, 0xD0);
                                sp300 = temp_f1_939;
                                sp308 = (f64) M2C_FIELD(temp_r29_962, f32 *, 0xD8);
                                sp310 = var_f28_838;
                                sp2F8 = temp_r5_937;
                                temp_r22_876->Message(&sp2F0, temp_r5_937, temp_f1_939);
                            }
                        }
                        var_r23_865 += 4;
                        goto loop_56;
                    }
                }
            }
            var_r26_485 += 4;
            goto loop_59;
        case 2:                                     /* switch 1 */
            sp138 = -1.0f;
            sp128 = 1.0f;
            sp130 = -1.0f;
            sp134 = 1.0f;
            sp120 = 1.0f;
            sp124 = 2.0f;
            sp280 = (f64) sp130;
            sp288 = (f64) sp138;
            sp270 = (f64) sp120;
            sp278 = (f64) sp128;
            sp290 = KDRand_Vector(*((MKVector3 *) &sp280), *((MKVector3 *) &sp270));
            temp_f0_593 = sp290 * 5.5769738e-315;
            sp110 = temp_f0_593;
            sp2A0 = temp_f0_593;
            sp118 = sp290.unk8 * 200.0f;
            sp2A8 = (f64) sp118;
            sp18 = MKRand_Float((int *) &gViewSeed, 0.2f, 0.4f);
            gb.EmitCrud(*((MKVector3 *) temp_r28_496), *((MKVector3 *) &sp2A0), sp18);
            sp108 = -1.0f;
            spF8 = 1.0f;
            sp100 = -1.0f;
            sp104 = 1.0f;
            spF0 = 1.0f;
            spF4 = 2.0f;
            sp240 = (f64) sp100;
            sp248 = (f64) sp108;
            sp230 = (f64) spF0;
            sp238 = (f64) spF8;
            sp250 = KDRand_Vector(*((MKVector3 *) &sp240), *((MKVector3 *) &sp230));
            temp_f0_637 = sp250 * 5.5769738e-315;
            spE0 = temp_f0_637;
            sp260 = temp_f0_637;
            spE8 = sp250.unk8 * 200.0f;
            sp268 = (f64) spE8;
            sp14 = MKRand_Float((int *) &gViewSeed, 0.2f, 0.4f);
            gb.EmitSmallRocks(*((MKVector3 *) temp_r28_496), *((MKVector3 *) &sp260), sp14);
            if ((this->unk58 <= 0.0f) && ((u8) M2C_FIELD(temp_r29_962, u8 *, 0x108) != 0)) {
                var_r24_666 = 0;
                do {
                    sp210 = MKVector(0.0f, 25.0f, 0.0f);
                    sp80 = M2C_FIELD(temp_r29_962, f64 *, 0xD0) + M2C_BITWISE(f64, sp210);
                    sp68 = 1.0f;
                    sp78 = -1.0f;
                    sp88 = temp_r29_962->unkD8 + sp210.unk8;
                    sp60 = 1.0f;
                    sp64 = 1.0f;
                    sp70 = -1.0f;
                    sp74 = 0.0f;
                    sp220 = sp80;
                    sp228 = (f64) sp88;
                    sp2E0 = sp80;
                    sp2E8 = (f64) sp88;
                    sp1E0 = (f64) sp60;
                    sp1E8 = (f64) sp68;
                    sp1F0 = (f64) sp70;
                    sp1F8 = (f64) sp78;
                    sp200 = KDRand_Vector(*((MKVector3 *) &sp1F0), *((MKVector3 *) &sp1E0));
                    *(MKVector3 *) &sp2D0 = sp200;
                    temp_f0_712 = sp2D0 * 5.58344962e-315;
                    spD0 = temp_f0_712;
                    sp1D0 = temp_f0_712;
                    spD8 = (f32) sp2D8 * 220.0f;
                    sp1D8 = (f64) spD8;
                    sp10 = MKRand_Int((int *) &gViewSeed, 0, 3);
                    ((FallingLeaves *) (M2C_FIELD(temp_r30_487, FallingLeaves **, 0x60)))->Emit(*((MKVector3 *) &sp2E0), *((MKVector3 *) &sp1D0), 2.0f, sp10, 1U);
                    var_r24_666 += 1;
                } while (var_r24_666 < 5);
            }
            ((FallingLeaves *) (M2C_FIELD(temp_r30_487, FallingLeaves **, 0x60)))->ApplyWind((WindFX *) &temp_r29_962->unk30);
            if (M2C_BITWISE(f32, temp_r29_962->unkF4) <= 0.0f) {
                temp_r29_962->unk100 = 4e-45f;
                temp_r29_962->unkF4 = 1.5f;
            }
            goto block_34;
        case 3:                                     /* switch 1 */
            var_f0_751 = M2C_BITWISE(f32, temp_r29_962->unkF4);
            if (var_f0_751 < 1.5f) {

            } else {
                var_f0_751 = 1.5f;
            }
            if (var_f0_751 > 0.0f) {

            } else {
                var_f0_751 = 0.0f;
            }
            temp_r29_962->unkF4 = var_f0_751;
            temp_r29_962->unkF8 = M2C_BITWISE(f32, temp_r29_962->unkF4) / 1.5f;
            if (M2C_BITWISE(f32, temp_r29_962->unkF4) <= 0.0f) {
                temp_r29_962->unk100 = 0.0f;
                temp_r29_962->unkF4 = 0.0f;
                KDSound_Stop((s32 *) temp_r29_962);
                temp_r3_781 = this->unk4C;
                this->unk4C = (MKHeap *) &temp_r3_781->unk4;
                temp_r4_784 = temp_r3_781->unk0;
                temp_r3_781->unk0 = var_r26_485->unk0;
                var_r26_485->unk0 = temp_r4_784;
            }
            goto block_34;
        }
    }
}
#endif

void EarthBreathWhirlWinds::Init() {
    MKVector3 sp38;
    MKVector3 sp28;
    u8 *base;
    u8 *block;
    u8 *elem;
    s32 var_ctr;

    MKProp::Init();
    if (MKHeap::Current() != NULL) {
        base = (u8 *) ((MKHeap *) (MKHeap::Current()))->Alloc(0xCF8, NULL, 0);
    } else {
        base = (u8 *) malloc(0xCF8);
    }
    this->unk4C = (MKHeap *) base;
    this->unk4C = (MKHeap *) (base + 0xCC0);
    M2C_FIELD(base, s32 *, 0xCC0) = 0;
    block = base;
    var_ctr = 0xC;
    do {
        elem = (u8 *) this->unk4C;
        this->unk4C = (MKHeap *) (elem + 4);
        M2C_FIELD(elem, s32 *, 4) = (s32) block;
        block += 0x110;
        var_ctr -= 1;
    } while (var_ctr != 0);
    elem = (u8 *) this->unk4C;
    this->unk4C = (MKHeap *) (elem + 4);
    M2C_FIELD(elem, s32 *, 4) = 0;
    ((MKSceneManager *) gMK)->CreatePropDeferred("WhirlWindDustPS", &this->unk54);
    this->unk50 = MKModel_Create("FX0043_Whirlwind", NULL, 2, NULL);
    while (M2C_FIELD(this->unk4C, u32 *, -4) != 0) {
        this->unk4C = (MKHeap *) ((u8 *) this->unk4C - 4);
        elem = (u8 *) this->unk4C->unk0;
        if (elem != NULL) {
            sp38.unk0 = 0.0f;
            sp38.unk4 = 0.0f;
            sp38.unk8 = 0.0f;
            sp28.unk0 = 0.0f;
            sp28.unk4 = 1.0f;
            sp28.unk8 = 0.0f;
            ((WindFX *) (elem + 0x30))->Init(1, 1.0f, sp38, sp28);
            M2C_FIELD(elem, f32 *, 0x48) = 400.0f;
            M2C_FIELD(elem, f32 *, 0x4C) = 800.0f;
            M2C_STRUCT_COPY(elem + 0x60, &Matrix::identity, 0x40);
            ((Matrix *) (elem + 0x60))->RotateYaw((Matrix *) (elem + 0x60), 1.5707964f);
            M2C_FIELD(elem, f32 *, 0x40) = 50.0f;
        }
    }
    while (M2C_FIELD(this->unk4C, u32 *, 0) != 0) {
        this->unk4C = (MKHeap *) ((u8 *) this->unk4C + 4);
    }
    this->unk58 = 0.0f;
}

void EarthBreathWhirlWindsDescriptor::Init() {
    MKPropDescriptor::Init();
    this->unk60 = (long) (checked_cast<FallingLeaves *, MKProp>(gMK->CreateProp("FallingGlowLeaves")));
}
