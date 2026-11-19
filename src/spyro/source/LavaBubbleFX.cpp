#include "spyro/source/LavaBubbleFX.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/Coronas.h"
#include "spyro/source/EmbersPS.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/Level.h"
#include "common/Source/MKMat_MK2_Standard.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKModel_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "unplaced_inlines.h"
#include <m2c_macros.h>

M2C_UNK free(MKHeap *);                             /* extern */
MKHeap *malloc(M2C_UNK);                            /* extern */
f64 pow(f64, f32);                                  /* extern */
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;

static s32 lit_550 = 0;
static u8 lit_551 = 0;

extern "C" void free(void *);
void LavaBubbleFX::Deinit() {
    MKHeap *temp_r29_62;
    s32 temp_r0_57;
    s32 var_r28_46;
    s32 var_r31_44;

    var_r31_44 = 0;
    var_r28_46 = 0;
    do {
        ((Coronas *) (M2C_FIELD(&gb, Coronas **, 0x64)))->Free(*(Corona **) ((u8 *) this->unkC8 + (var_r31_44 + 0x5C)));
        var_r28_46 += 1;
        temp_r0_57 = var_r31_44 + 0x5C;
        var_r31_44 += 0x78;
        *(Corona **) ((u8 *) this->unkC8 + temp_r0_57) = NULL;
    } while (var_r28_46 < 0x14);
    temp_r29_62 = this->unkC8;
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(temp_r29_62, NULL, 0);
    } else {
        free((void *) temp_r29_62);
    }
    MKMaterial_Destroy(this->unkD0);
    GameProp::Deinit();
}

#if 0 // DRAFT: illegal explicit conversion from 'MKHeap' to 'unsigned char'
void LavaBubbleFX::CreateBubble(const MKVector3 &arg0, const MKVector3 &arg1) {
    f64 sp80;
    f64 sp78;
    MKVector3 sp68;
    f64 sp60;
    f64 sp58;
    MKVector3 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKHeap *temp_r3_100;
    f64 temp_f4_116;
    f64 temp_f5_113;
    s32 var_ctr_98;
    s32 var_r29_97;
    void *temp_r3_154;
    void *temp_r3_187;
    void *temp_r3_196;
    void *temp_r3_210;
    void *temp_r3_219;
    void *temp_r4_133;
    void *temp_r4_137;
    void *temp_r4_170;
    void *temp_r4_181;
    void *temp_r5_129;

    var_r29_97 = 0;
    var_ctr_98 = 0x14;
loop_1:
    temp_r3_100 = this->unkC8;
    if ((u8) *(temp_r3_100 + (var_r29_97 + 0x3C)) == 0) {
        M2C_FIELD((temp_r3_100 + var_r29_97), s8 *, 0x3C) = 1;
        temp_f5_113 = M2C_FIELD(&arg1, f64 *, 0);
        temp_f4_116 = M2C_FIELD(&arg1, f64 *, 8);
        M2C_FIELD((this->unkC8 + var_r29_97), f32 *, 0x38) = 0.0f;
        M2C_FIELD((this->unkC8 + var_r29_97), f32 *, 0x30) = 0.0f;
        M2C_FIELD((this->unkC8 + var_r29_97), s32 *, 0x34) = 1;
        temp_r5_129 = this->unkC8 + var_r29_97;
        M2C_FIELD(temp_r5_129, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r5_129, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
        temp_r4_133 = this->unkC8 + (var_r29_97 + 0x10);
        M2C_FIELD(temp_r4_133, f64 *, 0) = temp_f5_113;
        M2C_FIELD(temp_r4_133, f64 *, 8) = temp_f4_116;
        temp_r4_137 = this->unkC8 + (var_r29_97 + 0x20);
        M2C_FIELD(temp_r4_137, f64 *, 0) = temp_f5_113;
        M2C_FIELD(temp_r4_137, f64 *, 8) = temp_f4_116;
        M2C_FIELD((this->unkC8 + var_r29_97), f32 *, 0x40) = -50.0f;
        sp68 = MKVector(0.0f, 5.0f, 0.0f);
        sp28 = M2C_FIELD(&arg0, f64 *, 0) + M2C_BITWISE(f64, sp68);
        temp_r3_154 = this->unkC8 + (var_r29_97 + 0x60);
        M2C_FIELD(temp_r3_154, f64 *, 0) = sp28;
        sp30 = arg0.unk8 + sp68.unk8;
        sp78 = sp28;
        M2C_FIELD(temp_r3_154, f64 *, 8) = (f64) sp30;
        sp80 = (f64) sp30;
        M2C_FIELD((this->unkC8 + var_r29_97), f32 *, 0x74) = 0.0f;
        M2C_FIELD((this->unkC8 + var_r29_97), f32 *, 0x70) = 0.0f;
        temp_r4_170 = M2C_FIELD((this->unkC8 + var_r29_97), void **, 0x5C);
        if (temp_r4_170 != NULL) {
            M2C_FIELD(temp_r4_170, u8 *, 0x31) = (u8) (M2C_FIELD(temp_r4_170, u8 *, 0x31) | 0x40);
            temp_r4_181 = this->unkC8 + var_r29_97;
            sp48 = MKVector(0.0f, (25.0f * M2C_FIELD(temp_r4_181, f32 *, 0x24)) + M2C_FIELD(temp_r4_181, f32 *, 0x40), 0.0f);
            temp_r3_187 = this->unkC8 + var_r29_97;
            sp18 = M2C_FIELD(temp_r3_187, f64 *, 0) + M2C_BITWISE(f64, sp48);
            temp_r3_196 = M2C_FIELD(temp_r3_187, void **, 0x5C);
            M2C_FIELD(temp_r3_196, f64 *, 0) = sp18;
            sp20 = M2C_FIELD(temp_r3_187, f32 *, 8) + sp48.unk8;
            M2C_FIELD(temp_r3_196, f64 *, 8) = (f64) sp20;
            sp8 = 0.75f;
            spC = 0.5f;
            temp_r3_210 = M2C_FIELD((this->unkC8 + var_r29_97), void **, 0x5C);
            sp10 = 0.25f;
            sp14 = 0.0f;
            M2C_FIELD(temp_r3_210, f64 *, 0x10) = (f64) sp8;
            M2C_FIELD(temp_r3_210, f64 *, 0x18) = (f64) sp10;
            sp58 = sp18;
            temp_r3_219 = this->unkC8 + var_r29_97;
            sp60 = (f64) sp20;
            sp38 = (f64) sp8;
            sp40 = (f64) sp10;
            M2C_FIELD(M2C_FIELD(temp_r3_219, void **, 0x5C), f32 *, 0x24) = (f32) (1.5f * M2C_FIELD(temp_r3_219, f32 *, 0x14));
        }
    } else {
        var_r29_97 += 0x78;
        var_ctr_98 -= 1;
        if (var_ctr_98 == 0) {
            return;
        }
        goto loop_1;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to 'double'
void LavaBubbleFX::DrawBubbleRings() {
    f64 sp278;
    f64 sp270;
    f64 sp268;
    f64 sp260;
    f64 sp258;
    f64 sp250;
    f64 sp248;
    f64 sp240;
    Matrix sp200;
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    MKVector3 sp1B0;
    MKVector3 sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    MKVector3 sp170;
    MKVector3 sp160;
    f64 sp158;
    f64 sp150;
    MKVector3 sp140;
    f64 sp138;
    f64 sp130;
    MKVector3 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    MKVector3 spF0;
    f64 spE8;
    f64 spE0;
    MKVector3 spD0;
    f64 spC8;
    f64 spC0;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp98;
    f64 sp90;
    f32 sp88;
    f64 sp80;
    f32 sp78;
    f64 sp70;
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
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f4_461;
    s32 var_r26_411;
    s32 var_r28_409;
    void *temp_r4_448;

    MKMaterial_SetMaterial(this->unkD0);
    MKPrimitive(0xC, 0);
    spA8 = 0.0f;
    spA0 = 1.0f;
    spA4 = 0.0f;
    sp1E8 = (f64) spA8;
    sp1E0 = (f64) spA0;
    spB8 = 1.0f;
    sp48 = -(f32) sp1E8;
    spB0 = 0.0f;
    spB4 = 0.0f;
    sp40 = -(f32) sp1E0;
    sp44 = -(*(f32 *) ((u8 *) &sp1E0 + 0x4));
    sp1F0 = (f64) spB0;
    sp1F8 = (f64) spB8;
    sp190 = (f64) sp40;
    sp198 = (f64) sp48;
    sp1A0 = ((MKVector3 *) &sp190)->operator*(10.0f);
    sp1B0 = ((MKVector3 *) &sp1F0)->operator*(10.0f);
    sp90 = sp1B0 + M2C_BITWISE(f64, sp1A0);
    sp1C0 = sp90;
    sp98 = sp1B0.unk8 + sp1A0.unk8;
    sp240 = sp90;
    sp1C8 = (f64) sp98;
    sp248 = (f64) sp98;
    sp160 = ((MKVector3 *) &sp1E0)->operator*(10.0f);
    sp170 = ((MKVector3 *) &sp1F0)->operator*(10.0f);
    sp80 = sp170 + M2C_BITWISE(f64, sp160);
    sp38 = -(f32) sp1E8;
    sp88 = sp170.unk8 + sp160.unk8;
    sp30 = -(f32) sp1E0;
    sp34 = -(*(f32 *) ((u8 *) &sp1E0 + 0x4));
    sp180 = sp80;
    sp188 = (f64) sp88;
    sp250 = sp80;
    sp258 = (f64) sp88;
    sp110 = (f64) sp30;
    sp118 = (f64) sp38;
    sp120 = ((MKVector3 *) &sp110)->operator*(10.0f);
    sp20 = -(f32) sp1F0;
    sp24 = -(*(f32 *) ((u8 *) &sp1F0 + 0x4));
    sp28 = -(f32) sp1F8;
    sp130 = (f64) sp20;
    sp138 = (f64) sp28;
    sp140 = ((MKVector3 *) &sp130)->operator*(10.0f);
    sp70 = sp140 + M2C_BITWISE(f64, sp120);
    sp150 = sp70;
    sp78 = sp140.unk8 + sp120.unk8;
    sp260 = sp70;
    sp158 = (f64) sp78;
    sp268 = (f64) sp78;
    spD0 = ((MKVector3 *) &sp1E0)->operator*(10.0f);
    sp10 = -(f32) sp1F0;
    sp14 = -(*(f32 *) ((u8 *) &sp1F0 + 0x4));
    sp18 = -(f32) sp1F8;
    spE0 = (f64) sp10;
    spE8 = (f64) sp18;
    spF0 = ((MKVector3 *) &spE0)->operator*(10.0f);
    sp60 = spF0 + M2C_BITWISE(f64, spD0);
    var_r28_409 = 0;
    var_r26_411 = 0;
    sp100 = sp60;
    sp68 = spF0.unk8 + spD0.unk8;
    sp270 = sp60;
    sp108 = (f64) sp68;
    sp278 = (f64) sp68;
    do {
        if ((u8) *(this->unkC8 + (var_r26_411 + 0x3C)) != 0) {
            M2C_STRUCT_COPY((s32) &unksp1FC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
            sp200.Scale3x3(&sp200, *(this->unkC8 + (var_r26_411 + 0x70)));
            temp_r4_448 = this->unkC8 + (var_r26_411 + 0x60);
            sp200.unk30 = M2C_FIELD(temp_r4_448, f32 *, 0);
            sp200.unk34 = M2C_FIELD(temp_r4_448, f32 *, 4);
            sp200.unk38 = M2C_FIELD(temp_r4_448, f32 *, 8);
            sp200.unk3C = 1.0f;
            MKSetMatrix(sp200);
            temp_f4_461 = *(this->unkC8 + (var_r26_411 + 0x74));
            sp50 = temp_f4_461;
            sp5C = 1.0f;
            sp54 = 0.75f * temp_f4_461;
            sp58 = 0.25f * temp_f4_461;
            spC0 = (f64) sp50;
            spC8 = (f64) sp58;
            sp1D0 = (f64) sp50;
            sp1D8 = (f64) sp58;
            MKBegin(4);
            MKSetColorV(*((MKVector4 *) &sp1D0));
            MKSetTexCoord1F(0.0f, 1.0f);
            MKSetPositionV(*((MKVector3 *) &sp240));
            MKSetColorV(*((MKVector4 *) &sp1D0));
            MKSetTexCoord1F(1.0f, 1.0f);
            MKSetPositionV(*((MKVector3 *) &sp250));
            MKSetColorV(*((MKVector4 *) &sp1D0));
            MKSetTexCoord1F(0.0f, 0.0f);
            MKSetPositionV(*((MKVector3 *) &sp260));
            MKSetColorV(*((MKVector4 *) &sp1D0));
            MKSetTexCoord1F(1.0f, 0.0f);
            MKSetPositionV(*((MKVector3 *) &sp270));
            MKEnd();
        }
        var_r28_409 += 1;
        var_r26_411 += 0x78;
    } while (var_r28_409 < 0x14);
    MKEndPrimitive();
}
#endif

#if 0 // DRAFT: function call 'Scale3x3(Matrix *, MKHeap)' does not match 'Matrix::Scale3x3(const Matrix *, const MKVector3 &)' 'Matrix::Scale3x3(const Matrix *, float)'
void LavaBubbleFX::Draw() {
    Matrix sp40;
    M2C_UNK sp3C;
    f64 sp38;
    f64 sp30;
    MKVector3 sp20;
    f32 sp18;
    f64 sp10;
    s32 var_r29_533;
    s32 var_r31_532;
    void *temp_r3_536;
    void *temp_r3_574;

    DrawBubbleRings();
    var_r31_532 = 0;
    var_r29_533 = 0;
    do {
        temp_r3_536 = this->unkC8 + var_r29_533;
        if (((u8) M2C_FIELD(temp_r3_536, u8 *, 0x3C) != 0) && (M2C_FIELD(temp_r3_536, f32 *, 0x38) < 1.0f) && (M2C_FIELD(temp_r3_536, f32 *, 0x40) > -150.0f)) {
            M2C_STRUCT_COPY((s32) &sp3C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
            sp40.Scale3x3(&sp40, *(this->unkC8 + (var_r29_533 + 0x10)));
            sp20 = MKVector(0.0f, *(this->unkC8 + (var_r29_533 + 0x40)), 0.0f);
            temp_r3_574 = this->unkC8 + var_r29_533;
            sp10 = M2C_FIELD(temp_r3_574, f64 *, 0) + M2C_BITWISE(f64, sp20);
            sp30 = sp10;
            sp18 = M2C_FIELD(temp_r3_574, f32 *, 8) + sp20.unk8;
            sp38 = (f64) sp18;
            sp40.unk30 = (f32) sp30;
            sp40.unk34 = (*(f32 *) ((u8 *) &sp30 + 0x4));
            sp40.unk38 = (f32) sp38;
            sp40.unk3C = 1.0f;
            MKModel_SetWorldMatrix(this->unk4, sp40);
            MKMat_MK2_SetAlphaRef(this->unkCC, *(this->unkC8 + (var_r29_533 + 0x38)));
            MKModel_Draw(this->unk4, NULL);
        }
        var_r31_532 += 1;
        var_r29_533 += 0x78;
    } while (var_r31_532 < 0x14);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to 'double'
void *LavaBubbleFX::Update() {
    f64 sp228;                                      /* compiler-managed */
    f64 sp220;                                      /* compiler-managed */
    f64 sp218;
    f64 sp210;
    MKVector3 sp200;
    MKVector3 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    MKVector3 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    MKVector4 sp190;
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
    f64 sp138;
    f64 sp130;
    MKVector3 sp120;
    MKVector3 sp110;
    f64 sp108;
    f64 sp100;
    MKVector3 spF0;
    MKVector3 spE0;
    f32 spD8;
    f64 spD0;
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
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    MKVector3 sp20;
    f32 sp18;
    f64 sp10;
    f32 spC;
    f32 sp8;
    MKHeap *temp_r3_1345;
    MKHeap *temp_r3_714;
    MKHeap *temp_r3_746;
    MKHeap *temp_r4_1149;
    MKHeap *temp_r4_1242;
    MKHeap *temp_r5_1238;
    MKHeap *temp_r5_1270;
    MKHeap *temp_r6_1233;
    MKHeap *temp_r7_1228;
    f32 temp_f1_1062;
    f32 temp_f1_1120;
    f32 temp_f1_1123;
    f32 temp_f1_1262;
    f32 temp_f1_1265;
    f32 temp_f1_1305;
    f32 temp_f1_872;
    f32 temp_f1_936;
    f32 temp_f1_939;
    f32 temp_f22_1031;
    f32 temp_f22_990;
    f32 temp_f23_1036;
    f32 temp_f23_985;
    f32 temp_f28_699;
    f32 temp_f29_650;
    f32 temp_f2_1312;
    f32 temp_f2_1314;
    f32 temp_f2_1336;
    f32 temp_f2_1341;
    f32 temp_f2_871;
    f32 temp_f3_1093;
    f32 temp_f4_1100;
    f32 temp_f4_1104;
    f32 temp_f4_698;
    f32 var_f0_1132;
    f32 var_f0_1153;
    f32 var_f0_675;
    f32 var_f2_1113;
    f32 var_f2_1255;
    f32 var_f2_929;
    f32 var_f3_1329;
    f32 var_f4_1303;
    f32 var_f4_792;
    f32 var_f5_1091;
    f32 var_f5_859;
    f64 temp_f0_1004;
    f64 temp_f0_1017;
    f64 temp_f0_1050;
    f64 temp_f0_1184;
    f64 temp_f0_750;
    f64 temp_f1_767;
    f64 temp_f1_798;
    f64 temp_f1_804;
    f64 temp_f1_808;
    s32 temp_r0_1147;
    s32 temp_r0_1271;
    s32 temp_r0_1337;
    s32 temp_r0_662;
    s32 temp_r0_752;
    s32 temp_r0_911;
    s32 temp_r3_1218;
    s32 temp_r3_827;
    s32 temp_r4_1216;
    s32 temp_r5_1214;
    s32 temp_r6_1210;
    s32 var_r0_837;
    s32 var_r26_966;
    s32 var_r27_655;
    s32 var_r29_654;
    void *temp_r3_1088;
    void *temp_r3_1112;
    void *temp_r3_1247;
    void *temp_r3_1288;
    void *temp_r3_1300;
    void *temp_r3_1320;
    void *temp_r3_658;
    void *temp_r3_723;
    void *temp_r3_757;
    void *temp_r3_765;
    void *temp_r3_914;
    void *temp_r3_920;
    void *temp_r3_946;
    void *temp_r3_954;
    void *temp_r4_1011;
    void *temp_r4_1181;
    void *temp_r4_716;
    void *temp_r4_734;
    void *temp_r4_747;
    void *temp_r4_766;
    void *temp_r4_885;
    void *temp_r5_695;
    void *temp_r5_968;
    void *temp_r7_1212;
    void *temp_r7_1223;

    temp_f29_650 = (f32) pow(0.25, gUpdateTimeDelta);
    var_r29_654 = 0;
    var_r27_655 = 0;
    do {
        temp_r3_658 = this->unkC8 + var_r27_655;
        if ((u8) M2C_FIELD(temp_r3_658, u8 *, 0x3C) != 0) {
            temp_r0_662 = M2C_FIELD(temp_r3_658, s32 *, 0x34);
            switch (temp_r0_662) {                  /* switch 1; irregular */
            case 1:                                 /* switch 1 */
                var_f0_675 = gUpdateTimeDelta + M2C_FIELD(temp_r3_658, f32 *, 0x30);
                if (var_f0_675 < 0.5f) {

                } else {
                    var_f0_675 = 0.5f;
                }
                if (var_f0_675 > 0.0f) {

                } else {
                    var_f0_675 = 0.0f;
                }
                M2C_FIELD(temp_r3_658, f32 *, 0x30) = var_f0_675;
                temp_r5_695 = this->unkC8 + var_r27_655;
                temp_f4_698 = M2C_FIELD(temp_r5_695, f32 *, 0x24);
                temp_f28_699 = M2C_FIELD(temp_r5_695, f32 *, 0x30) / 0.5f;
                M2C_FIELD(temp_r5_695, f32 *, 0x40) = (f32) (((1.0f - temp_f28_699) * -(60.000004f * temp_f4_698)) + (10.0f * temp_f4_698));
                sp1F0 = ((MKVector3 *) (this->unkC8 + (var_r27_655 + 0x20)))->operator*(0.5f);
                sp200 = sp1F0.operator*(temp_f28_699);
                temp_r3_714 = this->unkC8;
                temp_r4_716 = temp_r3_714 + (var_r27_655 + 0x20);
                sp60 = M2C_FIELD(temp_r4_716, f64 *, 0) + M2C_BITWISE(f64, sp200);
                temp_r3_723 = temp_r3_714 + (var_r27_655 + 0x10);
                M2C_FIELD(temp_r3_723, f64 *, 0) = sp60;
                sp68 = M2C_FIELD(temp_r4_716, f32 *, 8) + sp200.unk8;
                sp210 = sp60;
                M2C_FIELD(temp_r3_723, f64 *, 8) = (f64) sp68;
                sp218 = (f64) sp68;
                temp_r4_734 = this->unkC8 + var_r27_655;
                if ((u32) M2C_FIELD(temp_r4_734, u32 *, 0x5C) != 0U) {
                    sp1D0 = MKVector(0.0f, (25.0f * M2C_FIELD(temp_r4_734, f32 *, 0x24)) + M2C_FIELD(temp_r4_734, f32 *, 0x40), 0.0f);
                    temp_r3_746 = this->unkC8;
                    temp_r4_747 = temp_r3_746 + var_r27_655;
                    temp_f0_750 = M2C_FIELD(temp_r4_747, f64 *, 0) + M2C_BITWISE(f64, sp1D0);
                    sp50 = temp_f0_750;
                    temp_r0_752 = var_r27_655 + 0x5C;
                    temp_r3_757 = *(temp_r3_746 + temp_r0_752);
                    sp1E0 = temp_f0_750;
                    sp58 = M2C_FIELD(temp_r4_747, f32 *, 8) + sp1D0.unk8;
                    M2C_FIELD(temp_r3_757, f64 *, 0) = temp_f0_750;
                    M2C_FIELD(temp_r3_757, f64 *, 8) = (f64) sp58;
                    temp_r3_765 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
                    temp_r4_766 = *(this->unkC8 + temp_r0_752);
                    temp_f1_767 = M2C_FIELD(temp_r3_765, f64 *, 0x30);
                    sp1C0 = temp_f1_767;
                    sp1E8 = (f64) sp58;
                    sp1C8 = M2C_FIELD(temp_r3_765, f64 *, 0x38);
                    spD0 = temp_f1_767 - M2C_FIELD(temp_r4_766, f64 *, 0);
                    sp220 = spD0;
                    spD8 = (f32) sp1C8 - M2C_FIELD(temp_r4_766, f32 *, 8);
                    sp228 = (f64) spD8;
                    var_f4_792 = ((f32) sp228 * (f32) sp228) + (((f32) sp220 * (f32) sp220) + ((*(f32 *) ((u8 *) &sp218 + 0xc)) * (*(f32 *) ((u8 *) &sp218 + 0xc))));
                    if (var_f4_792 > 0.000001f) {
                        if (var_f4_792 > 0.0f) {
                            temp_f1_798 = __frsqrte(var_f4_792);
                            temp_f1_804 = 0.5 * temp_f1_798 * -(((f64) var_f4_792 * (temp_f1_798 * temp_f1_798)) - 3.0);
                            temp_f1_808 = 0.5 * temp_f1_804 * -(((f64) var_f4_792 * (temp_f1_804 * temp_f1_804)) - 3.0);
                            var_f4_792 = (f32) ((f64) var_f4_792 * (0.5 * temp_f1_808 * -(((f64) var_f4_792 * (temp_f1_808 * temp_f1_808)) - 3.0)));
                        } else if (var_f4_792 < M2C_BITWISE(f32, 0.0)) {
                            var_f4_792 = __float_nan;
                        } else {
                            sp8 = var_f4_792;
                            temp_r3_827 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                            switch (temp_r3_827) {  /* switch 2; irregular */
                            case 0x7F800000:        /* switch 2 */
                                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                    var_r0_837 = 1;
                                } else {
                                    var_r0_837 = 2;
                                }
                                break;
                            case 0x0:               /* switch 2 */
                                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                    var_r0_837 = 5;
                                } else {
                                    var_r0_837 = 3;
                                }
                                break;
                            default:                /* switch 2 */
                                var_r0_837 = 4;
                                break;
                            }
                            if (var_r0_837 == 1) {
                                var_f4_792 = __float_nan;
                            }
                        }
                        var_f5_859 = 1.0f / var_f4_792;
                    } else {
                        var_f5_859 = 0.0f;
                    }
                    temp_f2_871 = (f32) sp228 * var_f5_859;
                    temp_f1_872 = (75.0f * temp_f28_699) + 100.0f;
                    sp220 = (f32) sp220 * var_f5_859;
                    (*(f32 *) ((u8 *) &sp218 + 0xc)) *= var_f5_859;
                    sp228 = temp_f2_871;
                    sp40 = (f64) sp220 * (f64) temp_f1_872;
                    sp48 = temp_f2_871 * temp_f1_872;
                    temp_r4_885 = *(this->unkC8 + (var_r27_655 + 0x5C));
                    sp1B0 = sp40;
                    sp1B8 = (f64) sp48;
                    M2C_FIELD(temp_r4_885, f64 *, 0) = (f64) (M2C_FIELD(temp_r4_885, f64 *, 0) + sp1B0);
                    M2C_FIELD(temp_r4_885, f32 *, 8) = (f32) (M2C_FIELD(temp_r4_885, f32 *, 8) + (f32) sp1B8);
                    sp190 = MKVector(0.5f, 0.25f, 0.0f, 1.0f);
                    sp30 = M2C_FIELD(&sp190, f64 *, 0) * (f64) temp_f28_699;
                    sp38 = M2C_FIELD(&sp190, f64 *, 8) * (f64) temp_f28_699;
                    temp_r0_911 = var_r27_655 + 0x5C;
                    temp_r3_914 = *(this->unkC8 + temp_r0_911);
                    M2C_FIELD(temp_r3_914, f64 *, 0x10) = sp30;
                    M2C_FIELD(temp_r3_914, f64 *, 0x18) = sp38;
                    sp1A0 = sp30;
                    temp_r3_920 = *(this->unkC8 + temp_r0_911);
                    sp1A8 = sp38;
                    if (temp_r3_920 != NULL) {
                        var_f2_929 = 0.5f * (20.0f * gUpdateTimeDelta);
                        if (var_f2_929 < 1.0f) {

                        } else {
                            var_f2_929 = 1.0f;
                        }
                        temp_f1_936 = M2C_FIELD(temp_r3_920, f32 *, 0x1C);
                        temp_f1_939 = (var_f2_929 * (1.0f - temp_f1_936)) + temp_f1_936;
                        M2C_FIELD(temp_r3_920, f32 *, 0x1C) = (f32) ((var_f2_929 * (1.0f - temp_f1_939)) + temp_f1_939);
                    }
                    temp_r3_946 = this->unkC8 + var_r27_655;
                    M2C_FIELD(M2C_FIELD(temp_r3_946, void **, 0x5C), f32 *, 0x24) = (f32) (3.0f * M2C_FIELD(temp_r3_946, f32 *, 0x14));
                }
                temp_r3_954 = this->unkC8 + var_r27_655;
                if (M2C_FIELD(temp_r3_954, f32 *, 0x30) >= 0.5f) {
                    M2C_FIELD(temp_r3_954, s32 *, 0x34) = 2;
                    var_r26_966 = 0;
                    temp_r5_968 = this->unkC8 + (var_r27_655 + 0x48);
                    M2C_FIELD(temp_r5_968, f32 *, 0) = 7.0f;
                    M2C_FIELD(temp_r5_968, f32 *, 4) = 7.0f;
                    M2C_FIELD(temp_r5_968, f32 *, 8) = 7.0f;
                    *(this->unkC8 + (var_r27_655 + 0x58)) = 260.0f;
                    *(this->unkC8 + (var_r27_655 + 0x38)) = 0.25f;
                    do {
                        temp_f23_985 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
                        temp_f22_990 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
                        spC0 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
                        spC4 = temp_f22_990;
                        spC8 = temp_f23_985;
                        sp160 = (f64) spC0;
                        sp168 = (f64) spC8;
                        temp_f0_1004 = sp160 * 5.50703498e-315;
                        spB0 = temp_f0_1004;
                        sp170 = temp_f0_1004;
                        temp_r4_1011 = this->unkC8 + var_r27_655;
                        spB8 = (f32) sp168 * 60.000004f;
                        sp178 = (f64) spB8;
                        temp_f0_1017 = M2C_FIELD(temp_r4_1011, f64 *, 0) + temp_f0_1004;
                        spA0 = temp_f0_1017;
                        sp180 = temp_f0_1017;
                        spA8 = M2C_FIELD(temp_r4_1011, f32 *, 8) + (f32) sp178;
                        sp188 = (f64) spA8;
                        temp_f22_1031 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
                        temp_f23_1036 = MKRand_Float((int *) &gViewSeed, 2.0f, 3.0f);
                        sp90 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
                        sp94 = temp_f23_1036;
                        sp98 = temp_f22_1031;
                        sp140 = (f64) sp90;
                        sp148 = (f64) sp98;
                        temp_f0_1050 = sp140 * 5.61032426e-315;
                        sp80 = temp_f0_1050;
                        sp150 = temp_f0_1050;
                        sp88 = (f32) sp148 * 350.0f;
                        sp158 = (f64) sp88;
                        temp_f1_1062 = MKRand_Float((int *) &gViewSeed, 3.0f, 8.0f);
                        sp70 = 1.0f;
                        sp74 = 0.75f;
                        spC = temp_f1_1062;
                        sp78 = 0.0f;
                        sp7C = 1.0f;
                        sp130 = (f64) sp70;
                        sp138 = (f64) sp78;
                        ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(*((MKVector3 *) &sp180), *((MKVector3 *) &sp150), spC, *((MKVector4 *) &sp130), -1900.0f);
                        var_r26_966 += 1;
                    } while (var_r26_966 < 5);
                }
                temp_r3_1088 = this->unkC8 + var_r27_655;
                var_f5_1091 = 0.5f * (2.0f * gUpdateTimeDelta);
                temp_f3_1093 = 30.0f * M2C_FIELD(temp_r3_1088, f32 *, 0x24);
                if (var_f5_1091 < 1.0f) {

                } else {
                    var_f5_1091 = 1.0f;
                }
                temp_f4_1100 = M2C_FIELD(temp_r3_1088, f32 *, 0x70);
                temp_f4_1104 = (var_f5_1091 * (temp_f3_1093 - temp_f4_1100)) + temp_f4_1100;
                M2C_FIELD(temp_r3_1088, f32 *, 0x70) = (f32) ((var_f5_1091 * (temp_f3_1093 - temp_f4_1104)) + temp_f4_1104);
                temp_r3_1112 = this->unkC8 + var_r27_655;
                var_f2_1113 = 0.5f * (2.0f * gUpdateTimeDelta);
                if (var_f2_1113 < 1.0f) {

                } else {
                    var_f2_1113 = 1.0f;
                }
                temp_f1_1120 = M2C_FIELD(temp_r3_1112, f32 *, 0x74);
                temp_f1_1123 = (var_f2_1113 * (1.0f - temp_f1_1120)) + temp_f1_1120;
                M2C_FIELD(temp_r3_1112, f32 *, 0x74) = (f32) ((var_f2_1113 * (1.0f - temp_f1_1123)) + temp_f1_1123);
                break;
            case 2:                                 /* switch 1 */
                var_f0_1132 = gUpdateTimeDelta + M2C_FIELD(temp_r3_658, f32 *, 0x30);
                if (var_f0_1132 < 3.0f) {

                } else {
                    var_f0_1132 = 3.0f;
                }
                if (var_f0_1132 > 0.0f) {

                } else {
                    var_f0_1132 = 0.0f;
                }
                M2C_FIELD(temp_r3_658, f32 *, 0x30) = var_f0_1132;
                temp_r0_1147 = var_r27_655 + 0x38;
                temp_r4_1149 = this->unkC8;
                var_f0_1153 = (0.75f * gUpdateTimeDelta) + *(temp_r4_1149 + temp_r0_1147);
                if (var_f0_1153 < 1.0f) {

                } else {
                    var_f0_1153 = 1.0f;
                }
                if (var_f0_1153 > 0.0f) {

                } else {
                    var_f0_1153 = 0.0f;
                }
                *(temp_r4_1149 + temp_r0_1147) = var_f0_1153;
                spE0 = MKVector(100.0f, 100.0f, 100.0f);
                spF0 = ((MKVector3 *) (this->unkC8 + (var_r27_655 + 0x48)))->operator*(gUpdateTimeDelta);
                temp_r4_1181 = this->unkC8 + (var_r27_655 + 0x10);
                temp_f0_1184 = M2C_FIELD(temp_r4_1181, f64 *, 0) + M2C_BITWISE(f64, spF0);
                sp10 = temp_f0_1184;
                sp100 = temp_f0_1184;
                sp18 = M2C_FIELD(temp_r4_1181, f32 *, 8) + spF0.unk8;
                sp108 = (f64) sp18;
                sp110 = MKVector(0.0f, 0.0f, 0.0f);
                sp20 = Min(*((MKVector3 *) &sp100), spE0);
                sp120 = Max(sp20, sp110);
                temp_r6_1210 = var_r27_655 + 0x58;
                temp_r7_1212 = this->unkC8 + (var_r27_655 + 0x10);
                temp_r5_1214 = var_r27_655 + 0x4C;
                M2C_FIELD(temp_r7_1212, f64 *, 0) = M2C_BITWISE(f64, sp120);
                temp_r4_1216 = var_r27_655 + 0x48;
                temp_r3_1218 = var_r27_655 + 0x50;
                M2C_FIELD(temp_r7_1212, f64 *, 8) = (f64) sp120.unk8;
                temp_r7_1223 = this->unkC8 + var_r27_655;
                M2C_FIELD(temp_r7_1223, f32 *, 0x40) = (f32) ((gUpdateTimeDelta * M2C_FIELD(temp_r7_1223, f32 *, 0x58)) + M2C_FIELD(temp_r7_1223, f32 *, 0x40));
                temp_r7_1228 = this->unkC8;
                *(temp_r7_1228 + temp_r6_1210) = (-3080.0f * gUpdateTimeDelta) + *(temp_r7_1228 + temp_r6_1210);
                temp_r6_1233 = this->unkC8;
                *(temp_r6_1233 + temp_r5_1214) = (-10.0f * gUpdateTimeDelta) + *(temp_r6_1233 + temp_r5_1214);
                temp_r5_1238 = this->unkC8;
                *(temp_r5_1238 + temp_r4_1216) = *(temp_r5_1238 + temp_r4_1216) * temp_f29_650;
                temp_r4_1242 = this->unkC8;
                *(temp_r4_1242 + temp_r3_1218) = *(temp_r4_1242 + temp_r3_1218) * temp_f29_650;
                temp_r3_1247 = *(this->unkC8 + (var_r27_655 + 0x5C));
                if (temp_r3_1247 != NULL) {
                    var_f2_1255 = 0.5f * (2.0f * gUpdateTimeDelta);
                    if (var_f2_1255 < 1.0f) {

                    } else {
                        var_f2_1255 = 1.0f;
                    }
                    temp_f1_1262 = M2C_FIELD(temp_r3_1247, f32 *, 0x1C);
                    temp_f1_1265 = (var_f2_1255 * (0.0f - temp_f1_1262)) + temp_f1_1262;
                    M2C_FIELD(temp_r3_1247, f32 *, 0x1C) = (f32) ((var_f2_1255 * (0.0f - temp_f1_1265)) + temp_f1_1265);
                }
                temp_r5_1270 = this->unkC8;
                temp_r0_1271 = var_r27_655 + 0x30;
                if (*(temp_r5_1270 + temp_r0_1271) >= 3.0f) {
                    *(temp_r5_1270 + temp_r0_1271) = 0.0f;
                    *(this->unkC8 + (var_r27_655 + 0x3C)) = 0;
                    *(this->unkC8 + (var_r27_655 + 0x34)) = 0;
                    temp_r3_1288 = *(this->unkC8 + (var_r27_655 + 0x5C));
                    if (temp_r3_1288 != NULL) {
                        M2C_FIELD(temp_r3_1288, u8 *, 0x31) = (u8) (M2C_FIELD(temp_r3_1288, u8 *, 0x31) & ~0x40);
                    }
                }
                temp_r3_1300 = this->unkC8 + var_r27_655;
                var_f4_1303 = 0.5f * (2.0f * gUpdateTimeDelta);
                temp_f1_1305 = 30.0f * M2C_FIELD(temp_r3_1300, f32 *, 0x24);
                if (var_f4_1303 < 1.0f) {

                } else {
                    var_f4_1303 = 1.0f;
                }
                temp_f2_1312 = M2C_FIELD(temp_r3_1300, f32 *, 0x70);
                temp_f2_1314 = (var_f4_1303 * (temp_f1_1305 - temp_f2_1312)) + temp_f2_1312;
                M2C_FIELD(temp_r3_1300, f32 *, 0x70) = (f32) ((var_f4_1303 * (temp_f1_1305 - temp_f2_1314)) + temp_f2_1314);
                break;
            }
            temp_r3_1320 = this->unkC8 + var_r27_655;
            if ((s32) M2C_FIELD(temp_r3_1320, s32 *, 0x34) != 1) {
                var_f3_1329 = 0.5f * (1.0f * gUpdateTimeDelta);
                if (var_f3_1329 < 1.0f) {

                } else {
                    var_f3_1329 = 1.0f;
                }
                temp_f2_1336 = M2C_FIELD(temp_r3_1320, f32 *, 0x74);
                temp_r0_1337 = var_r27_655 + 0x74;
                temp_f2_1341 = (var_f3_1329 * (0.0f - temp_f2_1336)) + temp_f2_1336;
                M2C_FIELD(temp_r3_1320, f32 *, 0x74) = (f32) ((var_f3_1329 * (0.0f - temp_f2_1341)) + temp_f2_1341);
                temp_r3_1345 = this->unkC8;
                if (*(temp_r3_1345 + temp_r0_1337) <= 0.001f) {
                    *(temp_r3_1345 + temp_r0_1337) = 0.0f;
                }
            }
        }
        var_r29_654 += 1;
        var_r27_655 += 0x78;
    } while (var_r29_654 < 0x14);
}
#endif

f32 LavaBubbleFX::Resolve() {
    MKVector3 sp38;
    MKVector4 sp28;
    s32 temp_r0_1433;
    s32 var_r29_1406;
    s32 var_r31_1408;
    void *temp_r3_1440;

    KDPropEx::Resolve();
    var_r29_1406 = 0;
    var_r31_1408 = 0;
    do {
        sp38.unk0 = 0.0f;
        sp38.unk4 = 0.0f;
        sp38.unk8 = 0.0f;
        sp28.unk0 = 1.0f;
        sp28.unk4 = 0.75f;
        sp28.unk8 = 0.5f;
        sp28.unkC = 1.0f;
        temp_r0_1433 = var_r31_1408 + 0x5C;
        var_r29_1406 += 1;
        *(void **) ((u8 *) this->unkC8 + temp_r0_1433) = ((Coronas *) (M2C_FIELD(&gb, Coronas **, 0x64)))->Alloc(sp38, sp28, 8.0f, lit_550, lit_551);
        var_r31_1408 += 0x78;
        temp_r3_1440 = *(void **) ((u8 *) this->unkC8 + temp_r0_1433);
        M2C_FIELD(temp_r3_1440, u8 *, 0x31) = (u8) (M2C_FIELD(temp_r3_1440, u8 *, 0x31) & ~0x40);
    } while (var_r29_1406 < 0x14);
}

s32 LavaBubbleFX::LoadDone() {
    GameProp::LoadDone();
    this->unkCC = MKModel_GetMaterial(this->unk4, 0, 0U);
    this->unkD0 = (MKMaterial *) (MKMaterial_Create("FX_007"));
}

#if 0 // DRAFT: illegal operand
void LavaBubbleFX::Init() {
    MKHeap *var_r3_1501;
    s32 temp_r0_1526;
    s32 temp_r11_1522;
    s32 temp_r4_1525;
    s32 temp_r5_1524;
    s32 temp_r9_1528;
    s32 var_ctr_1513;
    s32 var_r3_1510;
    void *temp_r11_1540;
    void *temp_r6_1534;
    void *temp_r9_1551;

    GameProp::Init();
    if (MKHeap::Current() != NULL) {
        var_r3_1501 = (MKHeap *) (((MKHeap *) (MKHeap::Current()))->Alloc(0x960, NULL, 0));
    } else {
        var_r3_1501 = malloc(0x960);
    }
    this->unkC8 = var_r3_1501;
    var_r3_1510 = 0;
    var_ctr_1513 = 0x14;
    do {
        *(this->unkC8 + (var_r3_1510 + 0x3C)) = 0;
        temp_r11_1522 = var_r3_1510 + 0x10;
        temp_r5_1524 = var_r3_1510 + 0x40;
        temp_r4_1525 = var_r3_1510 + 0x74;
        temp_r0_1526 = var_r3_1510 + 0x70;
        *(this->unkC8 + (var_r3_1510 + 0x38)) = 0.0f;
        temp_r9_1528 = var_r3_1510 + 0x60;
        *(this->unkC8 + (var_r3_1510 + 0x30)) = 0.0f;
        *(this->unkC8 + (var_r3_1510 + 0x34)) = 0;
        temp_r6_1534 = this->unkC8 + var_r3_1510;
        var_r3_1510 += 0x78;
        M2C_FIELD(temp_r6_1534, f32 *, 0) = 0.0f;
        M2C_FIELD(temp_r6_1534, f32 *, 4) = 0.0f;
        M2C_FIELD(temp_r6_1534, f32 *, 8) = 0.0f;
        temp_r11_1540 = this->unkC8 + temp_r11_1522;
        M2C_FIELD(temp_r11_1540, f32 *, 0) = 1.0f;
        M2C_FIELD(temp_r11_1540, f32 *, 4) = 1.0f;
        M2C_FIELD(temp_r11_1540, f32 *, 8) = 1.0f;
        *(this->unkC8 + temp_r5_1524) = -50.0f;
        *(this->unkC8 + temp_r4_1525) = 0.0f;
        *(this->unkC8 + temp_r0_1526) = 0.0f;
        temp_r9_1551 = this->unkC8 + temp_r9_1528;
        M2C_FIELD(temp_r9_1551, f32 *, 0) = 0.0f;
        M2C_FIELD(temp_r9_1551, f32 *, 4) = 0.0f;
        M2C_FIELD(temp_r9_1551, f32 *, 8) = 0.0f;
        var_ctr_1513 -= 1;
    } while (var_ctr_1513 != 0);
    this->unkCC = NULL;
    this->unkD0 = NULL;
}
#endif
