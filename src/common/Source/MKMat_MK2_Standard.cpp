#include "common/Source/MKMat_MK2_Standard.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/Level.h"
#include "unplaced_enums.h"
#include "common/Source/FileSys.h"
#include "common/Source/MKMaterial_Util.h"
#include "common/Source/StdMath.h"
#include "common/Source/Str.h"
#include <m2c_macros.h>

f64 fmod(void *, f32, f64, f64, f32, f32, f32, f64, f64, f32); /* extern */
MKMaterial *malloc(M2C_UNK);                        /* extern */
extern f32 gUpdateTimeDelta;
#if 0 // DRAFT: identifier 'gbInitialiseMK2StandardGlow' redeclared
extern u8 gbInitialiseMK2StandardGlow;
#endif
#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKMaterialTypeInfo'
static M2C_UNK platformDataXB;                      /* unable to generate initializer: unknown type */
static M2C_UNK platformDataPC;                      /* unable to generate initializer: unknown type */
static MKMaterialTypeInfo typeInfoGC;               /* unable to generate initializer: confusing struct layout */
static f32 weight64 = 0.8f;
#endif
static f32 weight128 = 0.8f;

void MKMat_MK2_SetGlowWeights(float arg0, float arg1) {
    weight64 = arg0;
    weight128 = arg1;
}

void MKMaterial_LinkMaterial_MK2_Standard(bool arg0) {
    MKMaterial_LinkMaterialGC_MK2_Standard(arg0);
}

#if 0 // DRAFT: undefined identifier 'typeInfoGC'
void MKMaterial_LinkMaterialGC_MK2_Standard(bool arg0) {
    gbInitialiseMK2StandardGlow = arg0;
    MKMaterialInternal_AddTypeToList(&typeInfoGC);
}
#endif

#if 0 // DRAFT: illegal operand
void Updater_ColorPulse(MKMaterial *arg0, void *arg1) {
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    MKVector4 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f64 sp20;
    f64 sp18;
    f64 sp10;
    f64 sp8;
    f32 temp_f1_96;
    f32 temp_f4_65;
    f32 temp_f5_64;
    f32 temp_f6_62;
    f32 temp_f9_60;
    f64 temp_f0_103;
    f64 temp_f0_117;
    void *temp_r3_120;
    void *temp_r3_56;

    temp_r3_56 = arg0->unk24;
    temp_f9_60 = M2C_FIELD(temp_r3_56, f32 *, 0x178);
    temp_f6_62 = M2C_FIELD(temp_r3_56, f32 *, 0x180);
    temp_f5_64 = M2C_FIELD(temp_r3_56, f32 *, 0x188);
    temp_f4_65 = M2C_FIELD(temp_r3_56, f32 *, 0x18C);
    sp38 = M2C_FIELD(temp_r3_56, f32 *, 0x170);
    sp3C = M2C_FIELD(temp_r3_56, f32 *, 0x174);
    sp40 = temp_f9_60;
    sp44 = M2C_FIELD(temp_r3_56, f32 *, 0x17C);
    sp28 = temp_f6_62;
    sp2C = M2C_FIELD(temp_r3_56, f32 *, 0x184);
    sp30 = temp_f5_64;
    sp34 = temp_f4_65;
    sp88 = (f64) sp38;
    sp90 = (f64) sp40;
    sp78 = (f64) sp28;
    sp80 = (f64) sp30;
    *arg1 = (f32) fmod(temp_r3_56, (M2C_FIELD(temp_r3_56, f32 *, 0x190) * gUpdateTimeDelta) + *arg1, 1.0, (f64) sp28, temp_f4_65, temp_f5_64, temp_f6_62, (f64) sp40, (f64) sp38, temp_f9_60);
    temp_f1_96 = 0.5f * (1.0f + _table_sinf(6.2831855f * *arg1));
    sp8 = sp78 - sp88;
    temp_f0_103 = (f64) sp30 - sp90;
    sp10 = temp_f0_103;
    sp48 = sp8;
    sp50 = temp_f0_103;
    sp58.operator*(temp_f1_96);
    sp18 = sp88 + M2C_BITWISE(f64, sp58);
    temp_f0_117 = sp90 + (f64) sp58.unk8;
    sp20 = temp_f0_117;
    temp_r3_120 = arg0->unk24;
    M2C_FIELD(temp_r3_120, f64 *, 0x30) = sp18;
    sp68 = sp18;
    sp70 = temp_f0_117;
    M2C_FIELD(temp_r3_120, f64 *, 0x38) = temp_f0_117;
}
#endif

#if 0 // DRAFT: illegal type
void Updater_Animate(MKMaterial *arg0, void *arg1) {
    f32 temp_f0_152;
    f32 temp_f1_150;
    f32 temp_f1_164;
    f32 temp_f1_171;
    void *temp_r3_145;

    temp_r3_145 = arg0->unk24;
    temp_f1_150 = M2C_FIELD(temp_r3_145, f32 *, 0x130);
    M2C_FIELD(arg1, f32 *, 8) = (f32) (M2C_FIELD(arg1, f32 *, 8) + gUpdateTimeDelta);
    temp_f0_152 = M2C_FIELD(arg1, f32 *, 8);
    if (temp_f0_152 > temp_f1_150) {
        M2C_FIELD(arg1, f32 *, 8) = (f32) (temp_f0_152 - temp_f1_150);
        M2C_FIELD(arg1, f32 *, 0) = (f32) (M2C_FIELD(arg1, f32 *, 0) + M2C_FIELD(temp_r3_145, f32 *, 0x128));
        M2C_FIELD(arg1, f32 *, 4) = (f32) (M2C_FIELD(arg1, f32 *, 4) + M2C_FIELD(temp_r3_145, f32 *, 0x12C));
        temp_f1_164 = M2C_FIELD(arg1, f32 *, 0);
        if (temp_f1_164 < 0.0f) {
            M2C_FIELD(arg1, f32 *, 0) = (f32) (temp_f1_164 + 1.0f);
        }
        temp_f1_171 = M2C_FIELD(arg1, f32 *, 4);
        if (temp_f1_171 < 0.0f) {
            M2C_FIELD(arg1, f32 *, 4) = (f32) (temp_f1_171 + 1.0f);
        }
        if (M2C_FIELD(arg1, f32 *, 0) > 0.99f) {
            M2C_FIELD(arg1, f32 *, 0) = 0.0f;
        }
        if (M2C_FIELD(arg1, f32 *, 4) > 0.99f) {
            M2C_FIELD(arg1, f32 *, 4) = 0.0f;
        }
    }
    ((Matrix *) (arg0->unk24 + 0x40))->SetIdentity();
    M2C_FIELD(arg0->unk24, f32 *, 0x70) = (f32) M2C_FIELD(arg1, f32 *, 0);
    M2C_FIELD(arg0->unk24, f32 *, 0x74) = (f32) M2C_FIELD(arg1, f32 *, 4);
}
#endif

#if 0 // DRAFT: illegal type
void Updater_SinRotate(MKMaterial *arg0, void *arg1) {
    Matrix sp90;
    Matrix sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f1_242;
    f32 temp_f29_247;
    f32 temp_f30_236;
    f32 temp_f31_234;
    void *temp_r3_227;

    temp_r3_227 = arg0->unk24;
    temp_f31_234 = M2C_FIELD(temp_r3_227, f32 *, 0x150);
    temp_f30_236 = M2C_FIELD(temp_r3_227, f32 *, 0x154);
    M2C_FIELD(arg1, f32 *, 0) = (f32) ((3.1415927f * (2.0f * (gUpdateTimeDelta * M2C_FIELD(temp_r3_227, f32 *, 0x158)))) + M2C_FIELD(arg1, f32 *, 0));
    NormaliseAngle(M2C_FIELD(arg1, f32 *, 0));
    temp_f1_242 = _table_sinf(M2C_FIELD(arg1, f32 *, 0));
    sp28 = 0.0f;
    temp_f29_247 = M2C_FIELD(arg1, f32 *, 4) * temp_f1_242;
    sp20 = temp_f31_234;
    sp24 = temp_f30_236;
    sp48 = (f64) sp28;
    sp40 = (f64) sp20;
    sp90.SetRotationToNone();
    sp10 = -(f32) sp40;
    sp14 = -(*(f32 *) ((u8 *) &sp40 + 0x4));
    sp18 = -(f32) sp48;
    sp30 = (f64) sp10;
    sp38 = (f64) sp18;
    sp90.unk30 = (f32) sp30;
    sp90.unk34 = (*(f32 *) ((u8 *) &sp30 + 0x4));
    sp90.unk38 = (f32) sp38;
    sp90.unk3C = 1.0f;
    sp50.SetRotationRoll(temp_f29_247);
    sp50.unk30 = (f32) sp40;
    sp50.unk34 = (*(f32 *) ((u8 *) &sp40 + 0x4));
    sp50.unk38 = (f32) sp48;
    sp50.unk3C = 1.0f;
    ((Matrix *) (arg0->unk24 + 0x40))->Multiply(&sp90, &sp50);
}
#endif

#if 0 // DRAFT: illegal type
void Updater_Rotate(MKMaterial *arg0, void *arg1) {
    Matrix sp90;
    Matrix sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f30_328;
    f32 temp_f31_326;
    void *temp_r3_323;

    temp_r3_323 = arg0->unk24;
    temp_f31_326 = M2C_FIELD(temp_r3_323, f32 *, 0x134);
    temp_f30_328 = M2C_FIELD(temp_r3_323, f32 *, 0x138);
    M2C_FIELD(arg1, f32 *, 4) = (f32) ((gUpdateTimeDelta * M2C_FIELD(arg1, f32 *, 0)) + M2C_FIELD(arg1, f32 *, 4));
    NormaliseAngle(M2C_FIELD(arg1, f32 *, 4));
    sp20 = temp_f31_326;
    sp24 = temp_f30_328;
    sp28 = 0.0f;
    sp40 = (f64) sp20;
    sp48 = (f64) sp28;
    sp90.SetRotationToNone();
    sp10 = -(f32) sp40;
    sp14 = -(*(f32 *) ((u8 *) &sp40 + 0x4));
    sp18 = -(f32) sp48;
    sp30 = (f64) sp10;
    sp38 = (f64) sp18;
    sp90.unk30 = (f32) sp30;
    sp90.unk34 = (*(f32 *) ((u8 *) &sp30 + 0x4));
    sp90.unk38 = (f32) sp38;
    sp90.unk3C = 1.0f;
    sp50.SetRotationRoll(M2C_FIELD(arg1, f32 *, 4));
    sp50.unk30 = (f32) sp40;
    sp50.unk34 = (*(f32 *) ((u8 *) &sp40 + 0x4));
    sp50.unk38 = (f32) sp48;
    sp50.unk3C = 1.0f;
    ((Matrix *) (arg0->unk24 + 0x40))->Multiply(&sp90, &sp50);
}
#endif

#if 0 // DRAFT: illegal type
void Updater_SinScroll(MKMaterial *arg0, void *arg1) {
    f32 temp_f29_416;
    f32 temp_f30_415;
    f32 temp_f31_414;
    void *temp_r3_408;

    temp_r3_408 = arg0->unk24;
    temp_f31_414 = M2C_FIELD(temp_r3_408, f32 *, 0x160);
    temp_f30_415 = M2C_FIELD(temp_r3_408, f32 *, 0x164);
    temp_f29_416 = M2C_FIELD(temp_r3_408, f32 *, 0x16C);
    M2C_FIELD(arg1, f32 *, 0) = (f32) ((M2C_FIELD(temp_r3_408, f32 *, 0x168) * (2.0f * (3.1415927f * gUpdateTimeDelta))) + M2C_FIELD(arg1, f32 *, 0));
    NormaliseAngle(M2C_FIELD(arg1, f32 *, 0));
    M2C_FIELD(arg1, f32 *, 4) = (f32) ((temp_f29_416 * (2.0f * (3.1415927f * gUpdateTimeDelta))) + M2C_FIELD(arg1, f32 *, 4));
    NormaliseAngle(M2C_FIELD(arg1, f32 *, 4));
    ((Matrix *) (arg0->unk24 + 0x40))->SetIdentity();
    M2C_FIELD(arg0->unk24, f32 *, 0x70) = (f32) (temp_f31_414 * _table_sinf(M2C_FIELD(arg1, f32 *, 0)));
    M2C_FIELD(arg0->unk24, f32 *, 0x74) = (f32) (temp_f30_415 * _table_sinf(M2C_FIELD(arg1, f32 *, 4)));
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'float' to
void Updater_Scroll(MKMaterial *arg0, void *arg1) {
    f32 temp_f0_485;
    f32 temp_f1_474;
    f32 temp_f28_500;
    f32 temp_f29_498;
    f32 temp_f30_481;
    f32 temp_f31_480;
    f32 var_f2_484;
    void *temp_r3_475;

    temp_f1_474 = M2C_FIELD(arg1, f32 *, 8);
    temp_r3_475 = arg0->unk24;
    temp_f31_480 = M2C_FIELD(temp_r3_475, f32 *, 0x148);
    temp_f30_481 = M2C_FIELD(temp_r3_475, f32 *, 0x14C);
    if (temp_f1_474 > 0.0f) {
        var_f2_484 = 0.0f;
        temp_f0_485 = temp_f1_474 - gUpdateTimeDelta;
        if (var_f2_484 > temp_f0_485) {

        } else {
            var_f2_484 = temp_f0_485;
        }
        M2C_FIELD(arg1, f32 *, 8) = var_f2_484;
    } else {
        temp_f29_498 = (M2C_FIELD(temp_r3_475, f32 *, 0x140) * gUpdateTimeDelta) + M2C_FIELD(arg1, f32 *, 0);
        temp_f28_500 = (M2C_FIELD(temp_r3_475, f32 *, 0x144) * gUpdateTimeDelta) + M2C_FIELD(arg1, f32 *, 4);
        M2C_FIELD(arg1, f32 *, 0) = (f32) fmod(M2C_BITWISE(void *, temp_f29_498), M2C_BITWISE(f32, 1.0), M2C_BITWISE(f64, gUpdateTimeDelta));
        M2C_FIELD(arg1, f32 *, 4) = (f32) fmod(M2C_BITWISE(void *, temp_f28_500), M2C_BITWISE(f32, 1.0));
        if (temp_f29_498 != M2C_FIELD(arg1, f32 *, 0)) {
            M2C_FIELD(arg1, f32 *, 8) = temp_f31_480;
        } else if (temp_f28_500 != M2C_FIELD(arg1, f32 *, 4)) {
            M2C_FIELD(arg1, f32 *, 8) = temp_f30_481;
        }
    }
    ((Matrix *) (arg0->unk24 + 0x40))->SetIdentity();
    M2C_FIELD(arg0->unk24, f32 *, 0x70) = (f32) M2C_FIELD(arg1, f32 *, 0);
    M2C_FIELD(arg0->unk24, f32 *, 0x74) = (f32) M2C_FIELD(arg1, f32 *, 4);
}
#endif

void MKMat_MK2_Standard_DESTROY(MKMaterial *arg0) {
    MKMaterial *temp_r3_553;
    Texture *temp_r3_558;

    temp_r3_553 = arg0->unk3C;
    if (temp_r3_553 != NULL) {
        MKMaterial_Destroy(temp_r3_553);
    }
    temp_r3_558 = arg0->unk38;
    if (temp_r3_558 != NULL) {
        temp_r3_558->Destroy();
    }
    ((MKHeap *) arg0)->FreeFromAnyHeap(NULL, NULL, M2C_ERROR(/* Read from unset register $r6 */));
}

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
MKMaterial *MKMat_MK2_Standard_INIT(MatInfo *arg0) {
    MKHeap *temp_r3_582;
    MKHeap *temp_r3_608;
    MKHeap *temp_r3_651;
    MKHeap *temp_r3_691;
    MKHeap *temp_r3_719;
    MKHeap *temp_r3_752;
    MKHeap *temp_r3_791;
    MKHeap *temp_r3_819;
    MKHeap *temp_ret_608;
    MKMaterial *var_r30_590;
    MKMaterial *var_r5_659;
    MKMaterial *var_r5_699;
    MKMaterial *var_r5_727;
    MKMaterial *var_r5_760;
    MKMaterial *var_r5_799;
    MKMaterial *var_r5_827;
    Texture *temp_r29_602;
    f32 temp_f1_608;
    s32 temp_r0_841;
    s32 temp_ret_619;
    s8 *var_r3_625;
    u32 var_r4_600;
    void *temp_r3_849;

    temp_r3_582 = ((MKHeap *) arg0)->Current();
    if (temp_r3_582 != NULL) {
        var_r30_590 = ((MKHeap *) (temp_r3_582->Current()))->Alloc(0x40, NULL, 0);
    } else {
        var_r30_590 = malloc(0x40);
    }
    var_r4_600 = (u32) (u64) memset(var_r30_590, 0, 0x40U);
    var_r30_590->unk24 = arg0;
    temp_r29_602 = &arg0->unkE8;
    if (((s8) (u8) arg0->unkE8.unk0 != 0) && ((temp_ret_608 = temp_r29_602->Find((s8 *) var_r4_600), temp_f1_608 = M2C_BITWISE(f32, temp_ret_608), temp_r3_608 = temp_ret_608, var_r4_600 = (u32) (u64) temp_ret_608, ((temp_r3_608 == NULL) == 0)) || (temp_ret_619 = MKArchive_Exists(Str_Printf("%s%s", temp_r29_602, ".tex", temp_f1_608), NULL), var_r4_600 = (u32) (u64) temp_ret_619, ((temp_ret_619 == 0) == 0)))) {
        var_r3_625 = temp_r29_602->Create((s8 *) var_r4_600, 0.0f);
        var_r30_590->unk38 = (Texture *) var_r3_625;
    } else {
        var_r3_625 = ((Texture *) ("MKWhite"))->Create((s8 *) var_r4_600, 0.0f);
        var_r30_590->unk38 = (Texture *) var_r3_625;
    }
    if ((s8) (u8) arg0->unkE8.unk20 != 0) {
        var_r3_625 = MKMaterial_Create(&arg0->unkE8.unk20);
        var_r30_590->unk3C = (MKMaterial *) var_r3_625;
    }
    if ((arg0->unkE8.unk58 != 0.0f) || (arg0->unkE8.unk5C != 0.0f)) {
        temp_r3_651 = ((MKHeap *) var_r3_625)->Current();
        if (temp_r3_651 != NULL) {
            var_r5_659 = ((MKHeap *) (temp_r3_651->Current()))->Alloc(0xC, NULL, 0);
        } else {
            var_r5_659 = malloc(0xC);
        }
        var_r5_659->unk8 = 0.0f;
        var_r5_659->unk4 = 0.0f;
        var_r5_659->unk0 = 0.0f;
        MKMaterialInternal_AddUpdater(var_r30_590, Updater_Scroll, var_r5_659);
    } else if (((M2C_BITWISE(f32, arg0->unkE8.unk60.dummy[6]) != 0.0f) && (arg0->unkE8.unk80 != 0.0f)) || ((M2C_BITWISE(f32, arg0->unkE8.unk60.dummy[7]) != 0.0f) && (arg0->unkE8.unk84 != 0.0f))) {
        temp_r3_691 = ((MKHeap *) var_r3_625)->Current();
        if (temp_r3_691 != NULL) {
            var_r5_699 = ((MKHeap *) (temp_r3_691->Current()))->Alloc(8, NULL, 0);
        } else {
            var_r5_699 = malloc(8);
        }
        var_r5_699->unk4 = 0.0f;
        var_r5_699->unk0 = 0.0f;
        MKMaterialInternal_AddUpdater(var_r30_590, Updater_SinScroll, var_r5_699);
    } else if (arg0->unkE8.unk54 != 0.0f) {
        temp_r3_719 = ((MKHeap *) var_r3_625)->Current();
        if (temp_r3_719 != NULL) {
            var_r5_727 = ((MKHeap *) (temp_r3_719->Current()))->Alloc(8, NULL, 0);
        } else {
            var_r5_727 = malloc(8);
        }
        var_r5_727->unk4 = 0.0f;
        var_r5_727->unk0 = 0.017453292f * arg0->unkE8.unk54;
        MKMaterialInternal_AddUpdater(var_r30_590, Updater_Rotate, var_r5_727);
    } else if ((M2C_BITWISE(f32, arg0->unkE8.unk60.dummy[5]) != 0.0f) && (M2C_BITWISE(f32, arg0->unkE8.unk60.dummy[4]) != 0.0f)) {
        temp_r3_752 = ((MKHeap *) var_r3_625)->Current();
        if (temp_r3_752 != NULL) {
            var_r5_760 = ((MKHeap *) (temp_r3_752->Current()))->Alloc(8, NULL, 0);
        } else {
            var_r5_760 = malloc(8);
        }
        var_r5_760->unk0 = 0.0f;
        var_r5_760->unk4 = 0.017453292f * M2C_BITWISE(f32, arg0->unkE8.unk60.dummy[5]);
        MKMaterialInternal_AddUpdater(var_r30_590, Updater_SinRotate, var_r5_760);
    } else if (((M2C_BITWISE(f32, arg0->unkE8.unk40) != 0.0f) || (M2C_BITWISE(f32, arg0->unkE8.unk44) != 0.0f)) && (M2C_BITWISE(f32, arg0->unkE8.unk48) != 0.0f)) {
        temp_r3_791 = ((MKHeap *) var_r3_625)->Current();
        if (temp_r3_791 != NULL) {
            var_r5_799 = ((MKHeap *) (temp_r3_791->Current()))->Alloc(0xC, NULL, 0);
        } else {
            var_r5_799 = malloc(0xC);
        }
        var_r5_799->unk8 = 0.0f;
        var_r5_799->unk4 = 0.0f;
        var_r5_799->unk0 = 0.0f;
        MKMaterialInternal_AddUpdater(var_r30_590, Updater_Animate, var_r5_799);
    }
    if (arg0->unk170 != 0.0f) {
        temp_r3_819 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_819 != NULL) {
            var_r5_827 = ((MKHeap *) (temp_r3_819->Current()))->Alloc(4, NULL, 0);
        } else {
            var_r5_827 = malloc(4);
        }
        var_r5_827->unk0 = 0.0f;
        MKMaterialInternal_AddUpdater(var_r30_590, Updater_ColorPulse, var_r5_827);
    }
    temp_r0_841 = arg0->unk24;
    switch (temp_r0_841) {                          /* irregular */
    case 1:
        temp_r3_849 = var_r30_590->unk24;
        if ((s8) M2C_FIELD(temp_r3_849, u8 *, 0x1DC) == 0) {
            M2C_FIELD(temp_r3_849, s8 *, 0x1DD) = 1;
        }
        /* fallthrough */
    case 2:
        M2C_FIELD(var_r30_590->unk24, s8 *, 0xE4) = 0;
        break;
    }
    return var_r30_590;
}
#endif

void MKMat_MK2_SetAlphaRef(MKMaterial *arg0, float arg1) {
    M2C_FIELD(arg0->unk24, f32 *, 0x2C) = arg1;
}

s32 MKMat_MK2_SetMaterialType(MKMaterial *arg0, MKMat_MK2_Standard_MaterialType arg1) {
    s32 temp_r3_880;
    void *temp_r5_879;

    temp_r5_879 = arg0->unk24;
    temp_r3_880 = M2C_FIELD(temp_r5_879, s32 *, 0x28);
    M2C_FIELD(temp_r5_879, s32 *, 0x28) = (s32) arg1;
    return temp_r3_880;
}

Texture *MKMat_MK2_GetBaseTexture(MKMaterial *arg0) {
    return arg0->unk38;
}

#if 0 // DRAFT: undefined identifier 'platformDataXB'
void MKMat_MK2_Standard_cpp::__sinit() {
    f32 sp84;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
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
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;

    sp78 = 0.0f;
    sp7C = 0.0f;
    sp80 = 0.0f;
    sp84 = 0.0f;
    sp68 = 0.0f;
    sp6C = 0.0f;
    sp70 = 0.0f;
    sp74 = 0.0f;
    sp58 = 1.0f;
    sp5C = 1.0f;
    sp60 = 1.0f;
    sp64 = 1.0f;
    sp48 = 0.0f;
    sp4C = 0.0f;
    sp50 = 0.0f;
    sp54 = 0.0f;
    sp38 = 0.0f;
    sp3C = 0.0f;
    sp40 = 0.0f;
    sp44 = 0.0f;
    sp28 = 0.0f;
    sp2C = 0.0f;
    sp30 = 0.0f;
    sp34 = 0.0f;
    sp18 = 1.0f;
    sp1C = 1.0f;
    sp20 = 1.0f;
    sp24 = 1.0f;
    sp8 = 0.0f;
    spC = 0.0f;
    sp10 = 0.0f;
    sp14 = 0.0f;
    M2C_FIELD(&platformDataXB, f64 *, 0x18) = (f64) sp78;
    M2C_FIELD(&platformDataXB, f64 *, 0x20) = (f64) sp80;
    M2C_FIELD(&platformDataXB, f64 *, 0x38) = (f64) sp68;
    M2C_FIELD(&platformDataXB, f64 *, 0x40) = (f64) sp70;
    M2C_FIELD(&platformDataXB, f64 *, 0x58) = (f64) sp58;
    M2C_FIELD(&platformDataXB, f64 *, 0x60) = (f64) sp60;
    M2C_FIELD(&platformDataXB, f64 *, 0x78) = (f64) sp48;
    M2C_FIELD(&platformDataXB, f64 *, 0x80) = (f64) sp50;
    M2C_FIELD(&platformDataPC, f64 *, 0x18) = (f64) sp38;
    M2C_FIELD(&platformDataPC, f64 *, 0x20) = (f64) sp40;
    M2C_FIELD(&platformDataPC, f64 *, 0x38) = (f64) sp28;
    M2C_FIELD(&platformDataPC, f64 *, 0x40) = (f64) sp30;
    M2C_FIELD(&platformDataPC, f64 *, 0x58) = (f64) sp18;
    M2C_FIELD(&platformDataPC, f64 *, 0x60) = (f64) sp20;
    M2C_FIELD(&platformDataPC, f64 *, 0x78) = (f64) sp8;
    M2C_FIELD(&platformDataPC, f64 *, 0x80) = (f64) sp10;
}
#endif
