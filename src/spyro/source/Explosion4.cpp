#include "spyro/source/Explosion4.h"
#include "common/Source/Frustum.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Character.h"
#include "spyro/source/EmbersPS.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/ExplodeMsg.h"
#include "spyro/source/FlyingChunkPS.h"
#include "spyro/source/Game.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDParticleSystem.h"
#include "spyro/source/LightManager.h"
#include "spyro/source/ManagedLight.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKCollision.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

M2C_UNK free(u32 *);                                /* extern */
u32 *malloc(M2C_UNK);                               /* extern */
extern s32 GS_Explosion2;
extern s32 GS_Rumble1Soft;
extern M2C_UNK gEmptyPtrList;
extern void **gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;

static s32 lit_762 = 0;
static u8 lit_763 = 1;

#if 0 // DRAFT: undefined identifier 'MKVector'
void Explosion4::Trigger(const MKVector3 &arg0, float arg1, bool arg2, MKProp *arg3, int arg4, bool arg5, bool arg6, bool arg7, bool arg8) {
    f64 spF18;
    f64 spF10;
    f64 spF08;
    f32 spF04;
    f32 spF00;
    f32 spEFC;
    f32 spEF8;
    s32 spEF4;
    s32 spEF0;
    s32 spEEC;
    s32 spEE8;
    MKCollisionResult spE90;
    Frustum spE20;
    Matrix spDE0;
    M2C_UNK spDDC;
    s32 spDA4;
    ExplodeMsg spDA0;
    s8 spD98;
    f64 spD90;
    f64 spD88;
    s32 spD84;
    s32 spD80;
    f64 spD78;
    f64 spD70;
    f64 spD68;
    f64 spD60;
    f64 spD58;                                      /* compiler-managed */
    f64 spD50;
    f64 spD48;
    f64 spD40;
    f64 spD38;
    f64 spD30;
    f64 spD28;
    f64 spD20;
    f64 spD18;
    f64 spD10;
    f64 spD08;
    f64 spD00;
    f64 spCF8;
    f64 spCF0;
    f64 spCE8;
    f64 spCE0;
    f64 spCD8;
    f64 spCD0;
    f64 spCC8;
    f64 spCC0;
    f64 spCB8;
    f64 spCB0;
    f64 spCA8;
    f64 spCA0;
    MKVector3 spC90;
    MKVector3 spC80;
    M2C_UNK spC70;
    MKVector3 spC60;
    f64 spC58;
    f64 spC50;
    f64 spC48;
    f64 spC40;
    f64 spC38;
    f64 spC30;
    MKVector3 spC20;
    MKVector3 spC10;
    f64 spC00;
    f64 spBF8;
    f64 spBF0;
    f64 spBE8;
    f64 spBE0;
    MKVector3 spBD0;
    MKVector3 spBC0;
    f64 spBB8;
    f64 spBB0;
    f64 spBA8;
    f64 spBA0;
    f64 spB98;
    f64 spB90;
    MKVector3 spB80;
    MKVector3 spB70;
    f64 spB60;
    f64 spB58;
    f64 spB50;
    f64 spB48;
    f64 spB40;
    MKVector3 spB30;
    MKVector3 spB20;
    f64 spB18;
    f64 spB10;
    f64 spB08;
    f64 spB00;
    f64 spAF8;
    f64 spAF0;
    MKVector3 spAE0;
    MKVector3 spAD0;
    f64 spAC0;
    f64 spAB8;
    f64 spAB0;
    MKVector3 spAA0;
    MKVector3 spA90;
    f64 spA88;
    f64 spA80;
    f64 spA78;
    f64 spA70;
    f64 spA60;
    MKVector3 spA50;
    f64 spA48;
    f64 spA40;
    MKVector3 spA30;
    f64 spA28;
    f64 spA20;
    f64 spA18;
    f64 spA10;
    f64 spA08;
    f64 spA00;
    f64 sp9F8;
    f64 sp9F0;
    f64 sp9E8;
    f64 sp9E0;
    f64 sp9D8;
    f64 sp9D0;
    f64 sp9C8;
    f64 sp9C0;
    f64 sp9B8;
    f64 sp9B0;
    MKVector3 sp9A0;
    f64 sp998;
    f64 sp990;
    MKVector3 sp980;
    f64 sp978;
    f64 sp970;
    f64 sp968;
    f64 sp960;
    f64 sp958;
    f64 sp950;
    f64 sp948;
    f64 sp940;
    f64 sp938;
    f64 sp930;
    f64 sp928;
    f64 sp920;
    f64 sp918;
    f64 sp910;
    f64 sp908;
    f64 sp900;
    f64 sp8F8;
    f64 sp8F0;
    f64 sp8E8;
    f64 sp8E0;
    f64 sp8D8;
    f64 sp8D0;
    MKVector3 sp8C0;
    f64 sp8B8;
    f64 sp8B0;
    MKVector3 sp8A0;
    f64 sp898;
    f64 sp890;
    f64 sp888;
    f64 sp880;
    f64 sp878;
    f64 sp870;
    f64 sp868;
    f64 sp860;
    f64 sp858;
    f64 sp850;
    f64 sp848;
    f64 sp840;
    f64 sp838;
    f64 sp830;
    f64 sp828;
    f64 sp820;
    f64 sp818;
    f64 sp810;
    f64 sp808;
    f64 sp800;
    f64 sp7F8;
    f64 sp7F0;
    MKVector3 sp7E0;
    f64 sp7D8;
    f64 sp7D0;
    MKVector3 sp7C0;
    f64 sp7B8;
    f64 sp7B0;
    f64 sp7A8;
    f64 sp7A0;
    f64 sp798;
    f64 sp790;
    f64 sp788;
    f64 sp780;
    f64 sp778;
    f64 sp770;
    f64 sp768;
    f64 sp760;
    f64 sp758;
    f64 sp750;
    f64 sp748;
    f64 sp740;
    f64 sp738;
    f64 sp730;
    f64 sp728;
    f64 sp720;
    f64 sp718;
    f64 sp710;
    f64 sp708;
    f64 sp700;
    f64 sp6F8;
    f64 sp6F0;
    f64 sp6E8;
    f64 sp6E0;
    f64 sp6D8;
    f64 sp6D0;
    f64 sp6C8;
    f64 sp6C0;
    MKVector3 sp6B0;
    f64 sp6A8;
    f64 sp6A0;
    MKVector3 sp690;
    f64 sp688;
    f64 sp680;
    f64 sp678;
    f64 sp670;
    f64 sp668;
    f64 sp660;
    f64 sp658;
    f64 sp650;
    f64 sp648;
    f64 sp640;
    f64 sp638;
    f64 sp630;
    MKVector3 sp620;
    f64 sp618;
    f64 sp610;
    f64 sp608;
    f64 sp600;
    f64 sp5F8;
    f64 sp5F0;
    f64 sp5E8;
    f64 sp5E0;
    f64 sp5D8;
    f64 sp5D0;
    MKVector3 sp5C0;
    M2C_UNK sp5B0;
    f64 sp5A8;
    f64 sp5A0;
    MKVector3 sp590;
    MKVector3 sp580;
    f64 sp578;
    f64 sp570;
    f32 sp568;
    f64 sp560;
    f32 sp558;
    f32 sp554;
    f32 sp550;
    f32 sp548;
    f32 sp544;
    f32 sp540;
    f32 sp538;
    f64 sp530;
    f32 sp528;
    f64 sp520;
    f32 sp518;
    f64 sp510;
    f32 sp508;
    f64 sp500;
    f32 sp4F8;
    f64 sp4F0;
    f32 sp4E8;
    f64 sp4E0;
    f32 sp4DC;
    f32 sp4D8;
    f32 sp4D4;
    f32 sp4D0;
    f32 sp4C8;
    f32 sp4C4;
    f32 sp4C0;
    f32 sp4B8;
    f32 sp4B4;
    f32 sp4B0;
    f32 sp4A8;
    f64 sp4A0;
    f32 sp498;
    f64 sp490;
    f32 sp488;
    f64 sp480;
    f32 sp478;
    f64 sp470;
    f32 sp468;
    f64 sp460;
    f32 sp458;
    f64 sp450;
    f32 sp448;
    f32 sp444;
    f32 sp440;
    f32 sp438;
    f64 sp430;
    f32 sp428;
    f32 sp424;
    f32 sp420;
    f32 sp418;
    f64 sp410;
    f32 sp408;
    f32 sp404;
    f32 sp400;
    f32 sp3F8;
    f32 sp3F4;
    f32 sp3F0;
    f32 sp3E8;
    f64 sp3E0;
    f32 sp3D8;
    f64 sp3D0;
    f32 sp3C8;
    f64 sp3C0;
    f32 sp3B8;
    f64 sp3B0;
    f32 sp3A8;
    f64 sp3A0;
    f32 sp398;
    f64 sp390;
    f32 sp388;
    f32 sp384;
    f32 sp380;
    f32 sp378;
    f64 sp370;
    f32 sp368;
    f32 sp364;
    f32 sp360;
    f32 sp358;
    f64 sp350;
    f32 sp348;
    f32 sp344;
    f32 sp340;
    f32 sp338;
    f32 sp334;
    f32 sp330;
    f32 sp328;
    f64 sp320;
    f32 sp318;
    f64 sp310;
    f32 sp308;
    f64 sp300;
    f32 sp2F8;
    f64 sp2F0;
    f32 sp2E8;
    f64 sp2E0;
    f32 sp2D8;
    f64 sp2D0;
    f32 sp2C8;
    f32 sp2C4;
    f32 sp2C0;
    f32 sp2B8;
    f64 sp2B0;
    f32 sp2A8;
    f32 sp2A4;
    f32 sp2A0;
    f32 sp298;
    f64 sp290;
    f32 sp288;
    f32 sp284;
    f32 sp280;
    f32 sp278;
    f64 sp270;
    f32 sp268;
    f64 sp260;
    f32 sp258;
    f64 sp250;
    f32 sp248;
    f64 sp240;
    f32 sp238;
    f64 sp230;
    f32 sp228;
    f32 sp224;
    f32 sp220;
    f32 sp218;
    f32 sp214;
    f32 sp210;
    f32 sp208;
    f64 sp200;
    f32 sp1F8;
    f64 sp1F0;
    f32 sp1E8;
    f64 sp1E0;
    f32 sp1D8;
    f64 sp1D0;
    f32 sp1C8;
    f64 sp1C0;
    f32 sp1B8;
    f64 sp1B0;
    f32 sp1A8;
    f64 sp1A0;
    f32 sp19C;
    f32 sp198;
    f32 sp194;
    f32 sp190;
    f32 sp18C;
    f32 sp188;
    f32 sp184;
    f32 sp180;
    f32 sp178;
    f32 sp174;
    f32 sp170;
    f32 sp16C;
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
    f64 sp110;
    f32 sp108;
    f32 sp104;
    f32 sp100;
    f32 spF8;
    f64 spF0;
    f32 spEC;
    f32 spE8;
    f32 spE4;
    f32 spE0;
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
    f32 sp78;
    f64 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    ManagedLight *temp_r3_158;
    ManagedLight *temp_r3_208;
    f32 temp_f0_1695;
    f32 temp_f0_1802;
    f32 temp_f0_1836;
    f32 temp_f0_263;
    f32 temp_f0_417;
    f32 temp_f0_571;
    f32 temp_f14_1807;
    f32 temp_f14_2145;
    f32 temp_f1_714;
    f32 temp_f1_900;
    f32 temp_f20_655;
    f32 temp_f20_709;
    f32 temp_f21_1572;
    f32 temp_f21_516;
    f32 temp_f21_712;
    f32 temp_f21_841;
    f32 temp_f22_1071;
    f32 temp_f22_1103;
    f32 temp_f22_1273;
    f32 temp_f22_1305;
    f32 temp_f22_1469;
    f32 temp_f22_1501;
    f32 temp_f22_1569;
    f32 temp_f22_362;
    f32 temp_f23_1576;
    f32 temp_f24_1006;
    f32 temp_f24_1208;
    f32 temp_f24_1404;
    f32 temp_f25_1066;
    f32 temp_f25_1098;
    f32 temp_f25_1268;
    f32 temp_f25_1300;
    f32 temp_f25_1464;
    f32 temp_f25_1496;
    f32 temp_f25_842;
    f32 temp_f26_260;
    f32 temp_f26_414;
    f32 temp_f26_568;
    f32 temp_f27_1891;
    f32 temp_f2_1888;
    f32 temp_f4_349;
    f32 temp_f4_503;
    f64 temp_f0_1010;
    f64 temp_f0_1020;
    f64 temp_f0_1032;
    f64 temp_f0_1053;
    f64 temp_f0_1085;
    f64 temp_f0_1118;
    f64 temp_f0_1192;
    f64 temp_f0_1212;
    f64 temp_f0_121;
    f64 temp_f0_1222;
    f64 temp_f0_1234;
    f64 temp_f0_1255;
    f64 temp_f0_1287;
    f64 temp_f0_1320;
    f64 temp_f0_1388;
    f64 temp_f0_1408;
    f64 temp_f0_1418;
    f64 temp_f0_1430;
    f64 temp_f0_1451;
    f64 temp_f0_1483;
    f64 temp_f0_1515;
    f64 temp_f0_1585;
    f64 temp_f0_1595;
    f64 temp_f0_1607;
    f64 temp_f0_1678;
    f64 temp_f0_1700;
    f64 temp_f0_1723;
    f64 temp_f0_1765;
    f64 temp_f0_1786;
    f64 temp_f0_308;
    f64 temp_f0_462;
    f64 temp_f0_616;
    f64 temp_f0_659;
    f64 temp_f0_820;
    f64 temp_f0_888;
    f64 temp_f0_990;
    f64 temp_f1_1711;
    f64 temp_f1_855;
    f64 temp_f1_867;
    f64 temp_f1_879;
    s32 temp_r24_234;
    s32 temp_r3_2046;
    s32 temp_r3_2059;
    s32 var_r14_937;
    s32 var_r17_2047;
    s32 var_r18_2048;
    s32 var_r22_967;
    s32 var_r23_229;
    s32 var_r24_1556;
    s32 var_r24_1655;
    s32 var_r27_1365;
    s32 var_r27_796;
    s32 var_r30_1169;
    u8 temp_r21_87;
    u8 var_r14_2071;
    u8 var_r14_2126;
    void *temp_r23_705;
    void *temp_r26_256;
    void *temp_r26_410;
    void *temp_r26_564;
    void *temp_r3_114;
    void *temp_r3_172;
    void *temp_r3_1757;
    void *temp_r3_214;
    void *temp_r3_237;
    void *temp_r3_241;
    void *temp_r3_391;
    void *temp_r3_395;
    void *temp_r3_545;
    void *temp_r3_549;
    void *temp_r3_686;
    void *temp_r3_690;
    void *temp_r3_96;

    sp10 = arg1;
    temp_r21_87 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r12 */), u8 *, 0xB);
    temp_r3_96 = checked_cast<Explosion4Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    this->unk54 = 1;
    this->unk50 = 2.0f;
    this->unk58 = sp10;
    this->unk68 = M2C_FIELD(&arg0, f64 *, 0);
    this->unk70 = M2C_FIELD(&arg0, f64 *, 8);
    this->unk90 = 0.5f;
    temp_r3_114 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
    spD60 = M2C_FIELD(temp_r3_114, f64 *, 0x30);
    spD68 = M2C_FIELD(temp_r3_114, f64 *, 0x38);
    temp_f0_121 = spD60 - M2C_FIELD(&arg0, f64 *, 0);
    sp560 = temp_f0_121;
    spD50 = temp_f0_121;
    sp568 = (f32) spD68 - arg0.unk8;
    spD58 = (f64) sp568;
    ((MKVector3 *) &spD50)->Normalise();
    spD50 *= 5.304989477e-315;
    spD58 = (f32) spD58 * 2.0f;
    this->unkA4 = 0.0f;
    this->unkA0 = 0.0f;
loop_2:
    if ((u32) *this->unk98 != 0) {
        this->unk98 += 4;
        goto loop_2;
    }
    this->unk94 = arg6;
    this->unkA8 = arg7;
    this->unk64 = this->unk58;
    temp_r3_158 = this->unk4C;
    if (temp_r3_158 != NULL) {
        sp160 = 1.0f;
        sp164 = 0.5f;
        sp168 = 0.0f;
        sp16C = 1.0f;
        temp_r3_158->unk20 = (f64) sp160;
        temp_r3_158->unk28 = (f64) sp168;
        temp_r3_172 = temp_r3_158->unk3C;
        spCB0 = (f64) sp160;
        spCB8 = (f64) sp168;
        if (temp_r3_172 != NULL) {
            M2C_FIELD(temp_r3_172, f64 *, 0) = (f64) sp160;
            M2C_FIELD(temp_r3_172, f64 *, 8) = (f64) sp168;
        }
        this->unk4C->SetRadius(10000.0f * this->unk58);
        MKVector(0.0f, 1.0f, 0.0f);
        spC80.operator*(1000.0f);
        spC90.operator*(this->unk58);
        sp150 = this->unk68 + spC90;
        temp_r3_208 = this->unk4C;
        spCA0 = sp150;
        sp158 = (f32) M2C_FIELD(this, f64 *, 0x70) + spC90.unk8;
        temp_r3_208->unk10 = sp150;
        temp_r3_208->unk18 = (f64) sp158;
        temp_r3_214 = temp_r3_208->unk3C;
        spCA8 = (f64) sp158;
        if (temp_r3_214 != NULL) {
            M2C_FIELD(temp_r3_214, f64 *, 0x10) = sp150;
            M2C_FIELD(temp_r3_214, f64 *, 0x18) = (f64) sp158;
        }
        ((LightManager *) gb.unk80)->EnableLight(this->unk4C, 1U);
    }
    var_r23_229 = 0;
    temp_r24_234 = (s32) (20.0f * this->unk58);
loop_17:
    if (var_r23_229 < temp_r24_234) {
        temp_r3_237 = M2C_FIELD(temp_r3_96, void **, 0x60);
        temp_r3_241 = M2C_FIELD(M2C_FIELD(temp_r3_237, void **, 0x44), void *(**)(void *), 0x3C)(temp_r3_237);
        if (temp_r3_241 != NULL) {
            spEF4 = temp_r24_234 ^ 0x80000000;
            spEF0 = 0x43300000;
            temp_r26_256 = M2C_FIELD(temp_r3_241, void **, 0x2C);
            temp_f26_260 = 6.2831855f * ((f32) var_r23_229 / (f32) temp_r24_234);
            temp_f0_263 = -_table_sinf(1.5707964f + temp_f26_260);
            spF00 = temp_f0_263;
            sp140 = _table_sinf(temp_f26_260);
            sp148 = temp_f0_263;
            sp144 = 0.0f;
            spC58 = (f64) sp148;
            spC50 = (f64) sp140;
            Normalise(spC60);
            spD70 = M2C_BITWISE(f64, spC60);
            spD78 = (f64) spC60.unk8;
            MKVector(0.0f, this->unk58 * (200.0f * MKRand_Float(&gViewSeed, 0.0f, 1.0f)), 0.0f);
            spC10.operator*(100.0f);
            spC20.operator*(this->unk58);
            temp_f0_308 = this->unk68 + spC20;
            sp50 = temp_f0_308;
            spC30 = temp_f0_308;
            sp58 = (f32) M2C_FIELD(this, f64 *, 0x70) + spC20.unk8;
            spC38 = (f64) sp58;
            sp130 = spC30 + spC00;
            M2C_FIELD(temp_r3_241, f64 *, 0) = sp130;
            sp138 = (f32) spC38 + spC08;
            spC40 = sp130;
            M2C_FIELD(temp_r3_241, f64 *, 8) = (f64) sp138;
            spC48 = (f64) sp138;
            M2C_FIELD(temp_r3_241, f32 *, 0x20) = 0.0f;
            M2C_FIELD(temp_r3_241, f32 *, 0x24) = MKRand_Float(&gViewSeed, -6.2831855f, 6.2831855f);
            temp_f4_349 = this->unk58 * MKRand_Float(&gViewSeed, 5.0f, 8.0f);
            sp120 = 0.5f;
            sp124 = 0.5f;
            M2C_FIELD(temp_r3_241, f32 *, 0x28) = temp_f4_349;
            sp128 = 0.5f;
            sp12C = 1.0f;
            M2C_FIELD(temp_r3_241, f64 *, 0x10) = (f64) sp120;
            M2C_FIELD(temp_r3_241, f64 *, 0x18) = (f64) sp128;
            spBF0 = (f64) sp120;
            temp_f22_362 = this->unk58;
            spBF8 = (f64) sp128;
            spBD0.operator*(2000.0f);
            sp110 = spBD0 * (f64) temp_f22_362;
            M2C_FIELD(temp_r26_256, f64 *, 0) = sp110;
            sp118 = spBD0.unk8 * temp_f22_362;
            spBE0 = sp110;
            M2C_FIELD(temp_r26_256, f64 *, 8) = (f64) sp118;
            spBE8 = (f64) sp118;
            M2C_FIELD(temp_r26_256, f32 *, 0x18) = (f32) M2C_FIELD(temp_r3_241, f32 *, 0x28);
            M2C_FIELD(temp_r26_256, f32 *, 0x10) = 2.3561945f;
            M2C_FIELD(temp_r26_256, f32 *, 0x14) = (f32) (M2C_FIELD(M2C_FIELD(temp_r3_96, void **, 0x60), f32 *, 0xF4) - MKRand_Float(&gViewSeed, 0.0f, 0.2f));
        }
        temp_r3_391 = M2C_FIELD(temp_r3_96, void **, 0x60);
        temp_r3_395 = M2C_FIELD(M2C_FIELD(temp_r3_391, void **, 0x44), void *(**)(void *), 0x3C)(temp_r3_391);
        if (temp_r3_395 != NULL) {
            spEEC = temp_r24_234 ^ 0x80000000;
            spEE8 = 0x43300000;
            temp_r26_410 = M2C_FIELD(temp_r3_395, void **, 0x2C);
            temp_f26_414 = 6.2831855f * ((f32) var_r23_229 / (f32) temp_r24_234);
            temp_f0_417 = -_table_sinf(1.5707964f + temp_f26_414);
            spEFC = temp_f0_417;
            sp100 = _table_sinf(temp_f26_414);
            sp108 = temp_f0_417;
            sp104 = 0.0f;
            spBB8 = (f64) sp108;
            spBB0 = (f64) sp100;
            Normalise(spBC0);
            spD70 = M2C_BITWISE(f64, spBC0);
            spD78 = (f64) spBC0.unk8;
            MKVector(0.0f, this->unk58 * (200.0f * MKRand_Float(&gViewSeed, 0.0f, 1.0f)), 0.0f);
            spB70.operator*(100.0f);
            spB80.operator*(this->unk58);
            temp_f0_462 = this->unk68 + spB80;
            sp40 = temp_f0_462;
            spB90 = temp_f0_462;
            sp48 = (f32) M2C_FIELD(this, f64 *, 0x70) + spB80.unk8;
            spB98 = (f64) sp48;
            spF0 = spB90 + spB60;
            M2C_FIELD(temp_r3_395, f64 *, 0) = spF0;
            spF8 = (f32) spB98 + spB68;
            spBA0 = spF0;
            M2C_FIELD(temp_r3_395, f64 *, 8) = (f64) spF8;
            spBA8 = (f64) spF8;
            M2C_FIELD(temp_r3_395, f32 *, 0x20) = 0.0f;
            M2C_FIELD(temp_r3_395, f32 *, 0x24) = MKRand_Float(&gViewSeed, -6.2831855f, 6.2831855f);
            temp_f4_503 = this->unk58 * MKRand_Float(&gViewSeed, 5.0f, 8.0f);
            spE0 = 0.5f;
            spE4 = 0.5f;
            M2C_FIELD(temp_r3_395, f32 *, 0x28) = temp_f4_503;
            spE8 = 0.5f;
            spEC = 1.0f;
            M2C_FIELD(temp_r3_395, f64 *, 0x10) = (f64) spE0;
            M2C_FIELD(temp_r3_395, f64 *, 0x18) = (f64) spE8;
            spB50 = (f64) spE0;
            temp_f21_516 = this->unk58;
            spB58 = (f64) spE8;
            spB30.operator*(2000.0f);
            spD0 = spB30 * (f64) temp_f21_516;
            M2C_FIELD(temp_r26_410, f64 *, 0) = spD0;
            spD8 = spB30.unk8 * temp_f21_516;
            spB40 = spD0;
            M2C_FIELD(temp_r26_410, f64 *, 8) = (f64) spD8;
            spB48 = (f64) spD8;
            M2C_FIELD(temp_r26_410, f32 *, 0x18) = (f32) M2C_FIELD(temp_r3_395, f32 *, 0x28);
            M2C_FIELD(temp_r26_410, f32 *, 0x10) = -2.3561945f;
            M2C_FIELD(temp_r26_410, f32 *, 0x14) = (f32) (M2C_FIELD(M2C_FIELD(temp_r3_96, void **, 0x60), f32 *, 0xF4) - MKRand_Float(&gViewSeed, 0.0f, 0.2f));
        }
        temp_r3_545 = M2C_FIELD(temp_r3_96, void **, 0x64);
        temp_r3_549 = M2C_FIELD(M2C_FIELD(temp_r3_545, void **, 0x44), void *(**)(void *), 0x3C)(temp_r3_545);
        if (temp_r3_549 != NULL) {
            spEEC = temp_r24_234 ^ 0x80000000;
            spEE8 = 0x43300000;
            temp_r26_564 = M2C_FIELD(temp_r3_549, void **, 0x2C);
            temp_f26_568 = 6.2831855f * ((f32) var_r23_229 / (f32) temp_r24_234);
            temp_f0_571 = -_table_sinf(1.5707964f + temp_f26_568);
            spEF8 = temp_f0_571;
            spC0 = _table_sinf(temp_f26_568);
            spC8 = temp_f0_571;
            spC4 = 0.0f;
            spB18 = (f64) spC8;
            spB10 = (f64) spC0;
            Normalise(spB20);
            spD70 = M2C_BITWISE(f64, spB20);
            spD78 = (f64) spB20.unk8;
            MKVector(0.0f, this->unk58 * (200.0f * MKRand_Float(&gViewSeed, 0.0f, 1.0f)), 0.0f);
            spAD0.operator*(100.0f);
            spAE0.operator*(this->unk58);
            temp_f0_616 = this->unk68 + spAE0;
            sp30 = temp_f0_616;
            spAF0 = temp_f0_616;
            sp38 = (f32) M2C_FIELD(this, f64 *, 0x70) + spAE0.unk8;
            spAF8 = (f64) sp38;
            spB0 = spAF0 + spAC0;
            M2C_FIELD(temp_r3_549, f64 *, 0) = spB0;
            spB8 = (f32) spAF8 + spAC8;
            spB00 = spB0;
            M2C_FIELD(temp_r3_549, f64 *, 8) = (f64) spB8;
            M2C_FIELD(temp_r3_549, f32 *, 0x20) = 0.0f;
            spB08 = (f64) spB8;
            M2C_FIELD(temp_r3_549, f32 *, 0x24) = 0.0f;
            M2C_FIELD(temp_r3_549, f32 *, 0x28) = (f32) (this->unk58 * MKRand_Float(&gViewSeed, 5.0f, 8.0f));
            temp_f20_655 = this->unk58;
            spAA0.operator*(2000.0f);
            temp_f0_659 = spAA0 * (f64) temp_f20_655;
            spA0 = temp_f0_659;
            M2C_FIELD(temp_r26_564, f64 *, 0) = temp_f0_659;
            spA8 = spAA0.unk8 * temp_f20_655;
            spAB0 = temp_f0_659;
            M2C_FIELD(temp_r26_564, f64 *, 8) = (f64) spA8;
            spAB8 = (f64) spA8;
            M2C_FIELD(temp_r26_564, f32 *, 0x18) = (f32) M2C_FIELD(temp_r3_549, f32 *, 0x28);
            M2C_FIELD(temp_r26_564, f32 *, 0x10) = 0.0f;
            M2C_FIELD(temp_r26_564, f32 *, 0x14) = (f32) (M2C_FIELD(M2C_FIELD(temp_r3_96, void **, 0x64), f32 *, 0xF4) - MKRand_Float(&gViewSeed, 0.0f, 0.75f));
        }
        var_r23_229 += 1;
        goto loop_17;
    }
    temp_r3_686 = M2C_FIELD(temp_r3_96, void **, 0x60);
    temp_r3_690 = M2C_FIELD(M2C_FIELD(temp_r3_686, void **, 0x44), void *(**)(void *), 0x3C)(temp_r3_686);
    if (temp_r3_690 != NULL) {
        temp_r23_705 = M2C_FIELD(temp_r3_690, void **, 0x2C);
        temp_f20_709 = 6.2831855f * ((f32) var_r23_229 / (f32) temp_r24_234);
        temp_f21_712 = -_table_sinf(1.5707964f + temp_f20_709);
        temp_f1_714 = _table_sinf(temp_f20_709);
        sp98 = temp_f21_712;
        sp90 = temp_f1_714;
        sp94 = 0.0f;
        spA88 = (f64) sp98;
        spA80 = (f64) sp90;
        Normalise(spA90);
        spD70 = M2C_BITWISE(f64, spA90);
        spD78 = (f64) spA90.unk8;
        MKVector(0.0f, 400.0f * this->unk58, 0.0f);
        sp80 = this->unk68 + spA60;
        M2C_FIELD(temp_r3_690, f64 *, 0) = sp80;
        sp88 = (f32) M2C_FIELD(this, f64 *, 0x70) + spA68;
        spA70 = sp80;
        M2C_FIELD(temp_r3_690, f64 *, 8) = (f64) sp88;
        spA78 = (f64) sp88;
        M2C_FIELD(temp_r3_690, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r3_690, f32 *, 0x24) = MKRand_Float(&gViewSeed, -6.2831855f, 6.2831855f);
        M2C_FIELD(temp_r3_690, f32 *, 0x28) = (f32) (8.0f * this->unk58);
        M2C_FIELD(temp_r23_705, f32 *, 0) = 0.0f;
        M2C_FIELD(temp_r23_705, f32 *, 4) = 0.0f;
        M2C_FIELD(temp_r23_705, f32 *, 8) = 0.0f;
        M2C_FIELD(temp_r23_705, f32 *, 0x18) = (f32) M2C_FIELD(temp_r3_690, f32 *, 0x28);
        M2C_FIELD(temp_r23_705, f32 *, 0x10) = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        M2C_FIELD(temp_r23_705, f32 *, 0x14) = (f32) M2C_FIELD(M2C_FIELD(temp_r3_96, void **, 0x60), f32 *, 0xF4);
    }
    spF08 = 0.0;
    spF10 = 5.164075695e-315;
    spF18 = 5.465589745e-315;
    var_r27_796 = 0;
loop_22:
    if (var_r27_796 < (s32) ((f32) spF18 * this->unk58)) {
        sp548 = 1.0f;
        sp558 = -1.0f;
        sp540 = 1.0f;
        sp544 = 1.0f;
        sp550 = -1.0f;
        sp554 = (f32) spF08;
        spA10 = (f64) sp540;
        spA18 = (f64) sp548;
        spA20 = (f64) sp550;
        spA28 = (f64) sp558;
        KDRand_Vector(spA30, *((MKVector3 *) &spA20));
        temp_f0_820 = spA30 + spD50;
        sp530 = temp_f0_820;
        spA40 = temp_f0_820;
        sp538 = spA30.unk8 + spD58;
        spA48 = (f64) sp538;
        Normalise(spA50);
        spD40 = M2C_BITWISE(f64, spA50);
        spD48 = (f64) spA50.unk8;
        temp_f21_841 = MKRand_Float(&gViewSeed, 0.0f, 1.0f);
        temp_f25_842 = this->unk58;
        sp520 = spD40 * 5.53552857e-315;
        sp9E0 = sp520;
        sp528 = (f32) spD48 * 100.0f;
        sp9E8 = (f64) sp528;
        temp_f1_855 = sp9E0 * (f64) temp_f25_842;
        sp510 = temp_f1_855;
        sp9F0 = temp_f1_855;
        sp518 = (f32) sp9E8 * temp_f25_842;
        sp9F8 = (f64) sp518;
        temp_f1_867 = this->unk68 + sp9F0;
        sp500 = temp_f1_867;
        spA00 = temp_f1_867;
        sp508 = (f32) M2C_FIELD(this, f64 *, 0x70) + (f32) sp9F8;
        spA08 = (f64) sp508;
        temp_f1_879 = spD40 * 5.780152567e-315;
        sp4F0 = temp_f1_879;
        sp4F8 = (f32) spD48 * 6000.0f;
        sp9C0 = temp_f1_879;
        sp9C8 = (f64) sp4F8;
        temp_f0_888 = sp9C0 * (f64) temp_f25_842;
        sp4E0 = temp_f0_888;
        sp9D0 = temp_f0_888;
        sp4E8 = (f32) sp9C8 * temp_f25_842;
        sp9D8 = (f64) sp4E8;
        temp_f1_900 = MKRand_Float(&gViewSeed, 10.0f, 15.0f);
        sp4D0 = 1.0f;
        sp4D8 = 0.8f * temp_f21_841;
        sp4D4 = ((f32) spF10 * temp_f21_841) + 0.8f;
        sp4DC = 1.0f;
        sp18 = this->unk58 * temp_f1_900;
        sp9B0 = (f64) sp4D0;
        sp9B8 = (f64) sp4D8;
        ((EmbersPS *) gb.unk74)->Emit(*((MKVector3 *) &spA00), *((MKVector3 *) &sp9D0), sp18, *((MKVector4 *) &sp9B0), -1000.0f);
        var_r27_796 += 1;
        goto loop_22;
    }
    spE90.Init();
    var_r14_937 = 0;
    if (MKCollision_SphereCollide(arg0, 100.0f, &spE90, 1, (MKCollisionMode) 7, 0) != 0) {
        var_r14_937 = spE90.unk44;
    }
    if (arg5 != 0) {
        if ((var_r14_937 & 0x10000) || (var_r14_937 & 8)) {
            var_r22_967 = 0;
loop_30:
            if (var_r22_967 < (s32) (10.0f * this->unk58)) {
                sp4B8 = 1.0f;
                sp4C8 = -1.0f;
                sp4B0 = 1.0f;
                sp4B4 = 1.0f;
                sp4C0 = -1.0f;
                sp4C4 = 0.0f;
                sp960 = (f64) sp4B0;
                sp968 = (f64) sp4B8;
                sp970 = (f64) sp4C0;
                sp978 = (f64) sp4C8;
                KDRand_Vector(sp980, *((MKVector3 *) &sp970));
                temp_f0_990 = sp980 + spD50;
                sp4A0 = temp_f0_990;
                sp990 = temp_f0_990;
                sp4A8 = sp980.unk8 + spD58;
                sp998 = (f64) sp4A8;
                Normalise(sp9A0);
                spD30 = M2C_BITWISE(f64, sp9A0);
                temp_f24_1006 = this->unk58;
                spD38 = (f64) sp9A0.unk8;
                temp_f0_1010 = spD30 * 5.53552857e-315;
                sp490 = temp_f0_1010;
                sp930 = temp_f0_1010;
                sp498 = (f32) spD38 * 100.0f;
                sp938 = (f64) sp498;
                temp_f0_1020 = sp930 * (f64) temp_f24_1006;
                sp480 = temp_f0_1020;
                sp940 = temp_f0_1020;
                sp488 = (f32) sp938 * temp_f24_1006;
                sp948 = (f64) sp488;
                temp_f0_1032 = this->unk68 + sp940;
                sp470 = temp_f0_1032;
                sp950 = temp_f0_1032;
                sp478 = (f32) M2C_FIELD(this, f64 *, 0x70) + (f32) sp948;
                sp958 = (f64) sp478;
                sp460 = spD30 * 5.780152567e-315;
                sp468 = (f32) spD38 * 6000.0f;
                sp910 = sp460;
                sp918 = (f64) sp468;
                temp_f0_1053 = sp910 * (f64) temp_f24_1006;
                sp450 = temp_f0_1053;
                sp920 = temp_f0_1053;
                sp458 = (f32) sp918 * temp_f24_1006;
                sp928 = (f64) sp458;
                temp_f25_1066 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                temp_f22_1071 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                sp440 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                sp444 = temp_f22_1071;
                sp448 = temp_f25_1066;
                sp8F0 = (f64) sp440;
                sp8F8 = (f64) sp448;
                temp_f0_1085 = sp8F0 * 5.328646264e-315;
                sp430 = temp_f0_1085;
                sp900 = temp_f0_1085;
                sp438 = (f32) sp8F8 * 3.1415927f;
                sp908 = (f64) sp438;
                temp_f25_1098 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                temp_f22_1103 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                sp420 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                sp424 = temp_f22_1103;
                sp428 = temp_f25_1098;
                sp8D0 = (f64) sp420;
                sp8D8 = (f64) sp428;
                temp_f0_1118 = sp8D0 * 5.328646264e-315;
                sp410 = temp_f0_1118;
                sp8E0 = temp_f0_1118;
                sp418 = (f32) sp8D8 * 3.1415927f;
                sp8E8 = (f64) sp418;
                ((FlyingChunkPS *) gb.unkA8)->Emit(*((MKVector3 *) &sp950), *((MKVector3 *) &sp920), *((MKVector3 *) &sp900), *((MKVector3 *) &sp8E0), this->unk58 * MKRand_Float(&gViewSeed, 0.75f, 1.0f), *((MKVector4 *) &spE90.unk20), 2, NULL);
                var_r22_967 += 1;
                goto loop_30;
            }
        } else if (var_r14_937 & 0x8000) {
            var_r30_1169 = 0;
loop_35:
            if (var_r30_1169 < (s32) (10.0f * this->unk58)) {
                sp3F8 = 1.0f;
                sp408 = -1.0f;
                sp3F0 = 1.0f;
                sp3F4 = 1.0f;
                sp400 = -1.0f;
                sp404 = 0.0f;
                sp880 = (f64) sp3F0;
                sp888 = (f64) sp3F8;
                sp890 = (f64) sp400;
                sp898 = (f64) sp408;
                KDRand_Vector(sp8A0, *((MKVector3 *) &sp890));
                temp_f0_1192 = sp8A0 + spD50;
                sp3E0 = temp_f0_1192;
                sp8B0 = temp_f0_1192;
                sp3E8 = sp8A0.unk8 + spD58;
                sp8B8 = (f64) sp3E8;
                Normalise(sp8C0);
                spD20 = M2C_BITWISE(f64, sp8C0);
                temp_f24_1208 = this->unk58;
                spD28 = (f64) sp8C0.unk8;
                temp_f0_1212 = spD20 * 5.53552857e-315;
                sp3D0 = temp_f0_1212;
                sp850 = temp_f0_1212;
                sp3D8 = (f32) spD28 * 100.0f;
                sp858 = (f64) sp3D8;
                temp_f0_1222 = sp850 * (f64) temp_f24_1208;
                sp3C0 = temp_f0_1222;
                sp860 = temp_f0_1222;
                sp3C8 = (f32) sp858 * temp_f24_1208;
                sp868 = (f64) sp3C8;
                temp_f0_1234 = this->unk68 + sp860;
                sp3B0 = temp_f0_1234;
                sp870 = temp_f0_1234;
                sp3B8 = (f32) M2C_FIELD(this, f64 *, 0x70) + (f32) sp868;
                sp878 = (f64) sp3B8;
                sp3A0 = spD20 * 5.780152567e-315;
                sp3A8 = (f32) spD28 * 6000.0f;
                sp830 = sp3A0;
                sp838 = (f64) sp3A8;
                temp_f0_1255 = sp830 * (f64) temp_f24_1208;
                sp390 = temp_f0_1255;
                sp840 = temp_f0_1255;
                sp398 = (f32) sp838 * temp_f24_1208;
                sp848 = (f64) sp398;
                temp_f25_1268 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                temp_f22_1273 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                sp380 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                sp384 = temp_f22_1273;
                sp388 = temp_f25_1268;
                sp810 = (f64) sp380;
                sp818 = (f64) sp388;
                temp_f0_1287 = sp810 * 5.328646264e-315;
                sp370 = temp_f0_1287;
                sp820 = temp_f0_1287;
                sp378 = (f32) sp818 * 3.1415927f;
                sp828 = (f64) sp378;
                temp_f25_1300 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                temp_f22_1305 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                sp360 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                sp364 = temp_f22_1305;
                sp368 = temp_f25_1300;
                sp7F0 = (f64) sp360;
                sp7F8 = (f64) sp368;
                temp_f0_1320 = sp7F0 * 5.328646264e-315;
                sp350 = temp_f0_1320;
                sp800 = temp_f0_1320;
                sp358 = (f32) sp7F8 * 3.1415927f;
                sp808 = (f64) sp358;
                ((FlyingChunkPS *) gb.unkA0)->Emit(*((MKVector3 *) &sp870), *((MKVector3 *) &sp840), *((MKVector3 *) &sp820), *((MKVector3 *) &sp800), this->unk58 * MKRand_Float(&gViewSeed, 0.75f, 1.0f), *((MKVector4 *) &spE90.unk20), 0xA, NULL);
                var_r30_1169 += 1;
                goto loop_35;
            }
        } else {
            var_r27_1365 = 0;
loop_39:
            if (var_r27_1365 < (s32) (10.0f * this->unk58)) {
                sp338 = 1.0f;
                sp348 = -1.0f;
                sp330 = 1.0f;
                sp334 = 1.0f;
                sp340 = -1.0f;
                sp344 = 0.0f;
                sp7A0 = (f64) sp330;
                sp7A8 = (f64) sp338;
                sp7B0 = (f64) sp340;
                sp7B8 = (f64) sp348;
                KDRand_Vector(sp7C0, *((MKVector3 *) &sp7B0));
                temp_f0_1388 = sp7C0 + spD50;
                sp320 = temp_f0_1388;
                sp7D0 = temp_f0_1388;
                sp328 = sp7C0.unk8 + spD58;
                sp7D8 = (f64) sp328;
                Normalise(sp7E0);
                spD10 = M2C_BITWISE(f64, sp7E0);
                temp_f24_1404 = this->unk58;
                spD18 = (f64) sp7E0.unk8;
                temp_f0_1408 = spD10 * 5.53552857e-315;
                sp310 = temp_f0_1408;
                sp770 = temp_f0_1408;
                sp318 = (f32) spD18 * 100.0f;
                sp778 = (f64) sp318;
                temp_f0_1418 = temp_f0_1408 * (f64) temp_f24_1404;
                sp300 = temp_f0_1418;
                sp780 = temp_f0_1418;
                sp308 = (f32) sp778 * temp_f24_1404;
                sp788 = (f64) sp308;
                temp_f0_1430 = this->unk68 + temp_f0_1418;
                sp2F0 = temp_f0_1430;
                sp790 = temp_f0_1430;
                sp2F8 = (f32) M2C_FIELD(this, f64 *, 0x70) + (f32) sp788;
                sp798 = (f64) sp2F8;
                sp2E0 = spD10 * 5.780152567e-315;
                sp2E8 = (f32) spD18 * 6000.0f;
                sp750 = sp2E0;
                sp758 = (f64) sp2E8;
                temp_f0_1451 = sp750 * (f64) temp_f24_1404;
                sp2D0 = temp_f0_1451;
                sp760 = temp_f0_1451;
                sp2D8 = (f32) sp758 * temp_f24_1404;
                sp768 = (f64) sp2D8;
                temp_f25_1464 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                temp_f22_1469 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                sp2C0 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                sp2C4 = temp_f22_1469;
                sp2C8 = temp_f25_1464;
                sp730 = (f64) sp2C0;
                sp738 = (f64) sp2C8;
                temp_f0_1483 = sp730 * 5.328646264e-315;
                sp2B0 = temp_f0_1483;
                sp740 = temp_f0_1483;
                sp2B8 = (f32) sp738 * 3.1415927f;
                sp748 = (f64) sp2B8;
                temp_f25_1496 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                temp_f22_1501 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                sp2A0 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                sp2A4 = temp_f22_1501;
                sp2A8 = temp_f25_1496;
                sp710 = (f64) sp2A0;
                sp718 = (f64) sp2A8;
                temp_f0_1515 = sp710 * 5.328646264e-315;
                sp290 = temp_f0_1515;
                sp720 = temp_f0_1515;
                sp298 = (f32) sp718 * 3.1415927f;
                sp728 = (f64) sp298;
                ((FlyingChunkPS *) gb.unkA4)->Emit(*((MKVector3 *) &sp790), *((MKVector3 *) &sp760), *((MKVector3 *) &sp740), *((MKVector3 *) &sp720), this->unk58 * MKRand_Float(&gViewSeed, 0.75f, 1.0f), *((MKVector4 *) &spE90.unk20), 0xA, NULL);
                var_r27_1365 += 1;
                goto loop_39;
            }
        }
    }
    var_r24_1556 = 0;
    do {
        temp_f22_1569 = 2.0f * (3.1415927f * ((f32) var_r24_1556 / 20.0f));
        temp_f21_1572 = -_table_sinf(1.5707964f + temp_f22_1569);
        sp280 = _table_sinf(temp_f22_1569);
        temp_f23_1576 = this->unk58;
        sp284 = 0.0f;
        sp288 = temp_f21_1572;
        spD00 = (f64) sp280;
        spD08 = (f64) sp288;
        temp_f0_1585 = spD00 * 5.53552857e-315;
        sp270 = temp_f0_1585;
        sp6E0 = temp_f0_1585;
        sp278 = (f32) spD08 * 100.0f;
        sp6E8 = (f64) sp278;
        temp_f0_1595 = temp_f0_1585 * (f64) temp_f23_1576;
        sp260 = temp_f0_1595;
        sp6F0 = temp_f0_1595;
        sp268 = (f32) sp6E8 * temp_f23_1576;
        sp6F8 = (f64) sp268;
        temp_f0_1607 = this->unk68 + temp_f0_1595;
        sp250 = temp_f0_1607;
        sp700 = temp_f0_1607;
        sp258 = (f32) M2C_FIELD(this, f64 *, 0x70) + (f32) sp6F8;
        sp708 = (f64) sp258;
        sp240 = spD00 * 5.7488258e-315;
        sp248 = (f32) spD08 * 3500.0f;
        sp6C0 = sp240;
        sp6C8 = (f64) sp248;
        sp230 = sp6C0 * (f64) temp_f23_1576;
        sp6D0 = sp230;
        sp238 = (f32) sp6C8 * temp_f23_1576;
        sp14 = 2.5f * temp_f23_1576;
        sp6D8 = (f64) sp238;
        gb.EmitDust(*((MKVector3 *) &sp700), *((MKVector3 *) &sp6D0), sp14, 0.0f);
        var_r24_1556 += 1;
    } while (var_r24_1556 < 0x14);
    var_r24_1655 = 0;
loop_44:
    if (var_r24_1655 < (s32) (10.0f * this->unk58)) {
        sp218 = 1.0f;
        sp228 = -1.0f;
        sp210 = 1.0f;
        sp214 = 1.0f;
        sp220 = -1.0f;
        sp224 = 0.0f;
        sp670 = (f64) sp210;
        sp678 = (f64) sp218;
        sp680 = (f64) sp220;
        sp688 = (f64) sp228;
        KDRand_Vector(sp690, *((MKVector3 *) &sp680));
        temp_f0_1678 = sp690 + spD50;
        sp200 = temp_f0_1678;
        sp6A0 = temp_f0_1678;
        sp208 = sp690.unk8 + spD58;
        sp6A8 = (f64) sp208;
        Normalise(sp6B0);
        spCF0 = M2C_BITWISE(f64, sp6B0);
        temp_f0_1695 = this->unk58;
        spCF8 = (f64) sp6B0.unk8;
        spF04 = temp_f0_1695;
        temp_f0_1700 = spCF0 * 5.53552857e-315;
        sp1F0 = temp_f0_1700;
        sp640 = temp_f0_1700;
        sp1F8 = (f32) spCF8 * 100.0f;
        sp648 = (f64) sp1F8;
        temp_f1_1711 = sp640 * (f64) temp_f0_1695;
        sp1E0 = temp_f1_1711;
        sp650 = temp_f1_1711;
        sp1E8 = (f32) sp648 * temp_f0_1695;
        sp658 = (f64) sp1E8;
        temp_f0_1723 = this->unk68 + sp650;
        sp1D0 = temp_f0_1723;
        sp660 = temp_f0_1723;
        sp1D8 = (f32) M2C_FIELD(this, f64 *, 0x70) + (f32) sp658;
        sp668 = (f64) sp1D8;
        sp1C0 = spCF0 * 5.758944265e-315;
        sp1C8 = (f32) spCF8 * 4000.0f;
        sp630 = sp1C0;
        sp638 = (f64) sp1C8;
        this->unk5C.Emit(*((MKVector3 *) &sp660), *((MKVector3 *) &sp630));
        var_r24_1655 += 1;
        goto loop_44;
    }
    temp_r3_1757 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
    spCE0 = M2C_FIELD(temp_r3_1757, f64 *, 0x30);
    spCE8 = M2C_FIELD(temp_r3_1757, f64 *, 0x38);
    temp_f0_1765 = M2C_FIELD(&arg0, f64 *, 0) - spCE0;
    sp1B0 = temp_f0_1765;
    sp610 = temp_f0_1765;
    sp1B8 = arg0.unk8 - (f32) spCE8;
    sp618 = (f64) sp1B8;
    Normalise(sp620);
    spCD0 = M2C_BITWISE(f64, sp620);
    spCD8 = (f64) sp620.unk8;
    temp_f0_1786 = spCE0 - this->unk68;
    sp1A0 = temp_f0_1786;
    sp600 = temp_f0_1786;
    sp1A8 = (f32) spCE8 - (f32) M2C_FIELD(this, f64 *, 0x70);
    sp608 = (f64) sp1A8;
    temp_f0_1802 = 100.0f * (112.0f * this->unk58);
    temp_f14_1807 = ((f32) sp608 * (f32) sp608) + (((f32) sp600 * (f32) sp600) + (unksp604 * unksp604));
    if (temp_f14_1807 <= (temp_f0_1802 * temp_f0_1802)) {
        M2C_STRUCT_COPY((s32) &spDE0.unk3C + 4, (s32) (M2C_FIELD(&gb, void **, 0x3B8) + 0xAC) + 4, 0x70);
        if (spE20.IsVisible(*((MKVector3 *) &this->unk68), 100.0f * (25.0f * this->unk58)) != 0) {
            temp_f0_1836 = 100.0f * (40.0f * this->unk58);
            if (temp_f14_1807 <= (temp_f0_1836 * temp_f0_1836)) {
                sp190 = 1.0f;
                sp194 = 0.8f;
                sp198 = 0.0f;
                sp19C = 1.0f;
                sp5F0 = (f64) sp190;
                sp5F8 = (f64) sp198;
                gb.unkB8.EnableScreenFlash(*((MKVector4 *) &sp5F0), 40.0f * gUpdateTimeDelta);
            } else {
                sp180 = 1.0f;
                sp184 = 1.0f;
                sp188 = 0.0f;
                sp18C = 1.0f;
                sp5E0 = (f64) sp180;
                sp5E8 = (f64) sp188;
                gb.unkB8.EnableScreenFlash(*((MKVector4 *) &sp5E0), 3.0f * gUpdateTimeDelta);
            }
        }
        if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
            temp_f2_1888 = 2000.0f * (1.0f + this->unk58);
            temp_f27_1891 = 1.0f - (temp_f14_1807 / (temp_f2_1888 * temp_f2_1888));
            if (temp_f27_1891 > 0.0f) {
                spD84 = 0;
                MKVector(1.0f, 1.0f, 1.0f);
                sp5C0.operator*(500.0f);
                sp70 = sp5C0 * (f64) temp_f27_1891;
                spD80 = 0x417;
                spD88 = sp70;
                sp78 = sp5C0.unk8 * temp_f27_1891;
                spD98 = 1;
                spD90 = (f64) sp78;
                sp5D0 = sp70;
                sp5D8 = (f64) sp78;
                M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &spD80, sp70);
            }
        }
    }
    if (arg5 != 0) {
        M2C_STRUCT_COPY((s32) &spDDC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
        sp178 = 0.0f;
        sp170 = 0.0f;
        sp174 = 1.0f;
        spCC8 = (f64) sp178;
        spCC0 = (f64) sp170;
        KDMath_BuildMatrixFromFwd(&spDE0, *((MKVector3 *) &spCD0), (MKVector3 *) &spCC0);
        spDE0.Scale3x3(&spDE0, 2.5f * this->unk58);
        sp20 = -(f32) spCD0;
        sp24 = -unkspCD4;
        sp28 = -(f32) spCD8;
        sp570 = (f64) sp20;
        sp578 = (f64) sp28;
        sp580.operator*(700.0f);
        sp590.operator*(this->unk58);
        sp60 = M2C_FIELD(&arg0, f64 *, 0) + M2C_BITWISE(f64, sp590);
        sp5A0 = sp60;
        sp68 = arg0.unk8 + sp590.unk8;
        sp5A8 = (f64) sp68;
        spDE0.unk30 = (f32) sp5A0;
        spDE0.unk34 = unksp5A4;
        spDE0.unk38 = (f32) sp5A8;
        spDE0.unk3C = 1.0f;
        gb.unk1C0.StartWarp(&spDE0);
    }
    this->unk78 = 0.0f;
    this->unk7C = 0.0f;
    this->unk80 = 0.0f;
    if (arg2 != 0) {
        spDA4 = 0;
        spDA0.Init(arg3, *((MKVector3 *) &this->unk68), this->unk9C * this->unk58, 0U, 1U, 0, (f32) arg4, 0);
        M2C_FIELD(*gMK, M2C_UNK (**)(void **, ExplodeMsg *, M2C_UNK, M2C_UNK, f64 *, M2C_UNK, f32), 0x94)(gMK, &spDA0, 0, 0, &this->unk68, 1, this->unk9C);
    }
    temp_r3_2046 = this->unk88;
    var_r17_2047 = 0;
    var_r18_2048 = 0;
    if (temp_r3_2046 != 0) {
        var_r17_2047 = KDSound_Play3d(temp_r3_2046, (MKVector3 *) &this->unk68, 0U, -1, 0.0f, 0U);
    }
    temp_r3_2059 = this->unk8C;
    if (temp_r3_2059 != 0) {
        var_r18_2048 = KDSound_Play3d(temp_r3_2059, (MKVector3 *) &this->unk68, 0U, -1, 0.0f, 0U);
    }
    var_r14_2071 = 0;
    if ((((u32) M2C_FIELD(gb.unkC, u32 *, 0x78) != 0U) || ((u32) M2C_FIELD(gb.unkC, u32 *, 0x84) != 0U)) && (((KDStateMachine<CutsceneSystem> *) (gb.unkC + 0x24))->GetState() != 0)) {
        var_r14_2071 = 1;
    }
    if (var_r14_2071 != 0) {
        if (var_r17_2047 != 0) {
            KDSound_SetVolume(var_r17_2047, 0.25f * ((f32) KDSound_GetSoundEventVol(this->unk88) / 255.0f));
        }
        if (var_r18_2048 != 0) {
            KDSound_SetVolume(var_r18_2048, 0.25f * ((f32) KDSound_GetSoundEventVol(this->unk8C) / 255.0f));
        }
    }
    var_r14_2126 = 0;
    if ((((u32) M2C_FIELD(gb.unkC, u32 *, 0x78) != 0U) || ((u32) M2C_FIELD(gb.unkC, u32 *, 0x84) != 0U)) && (((KDStateMachine<CutsceneSystem> *) (gb.unkC + 0x24))->GetState() != 0)) {
        var_r14_2126 = 1;
    }
    if ((var_r14_2126 == 0) && (temp_r21_87 != 0)) {
        temp_f14_2145 = this->unk58;
        ((KDInput *) (gb.unk0->GetInput()))->RumblePlay3D(temp_f14_2145, temp_f14_2145, 0.5f, (MKVector3 *) &this->unk68, 50.0f, 0, 4.0f, 0U);
    }
}
#endif

#if 0 // DRAFT: type mismatch
void Explosion4::Deinit() {
    MKHeap *temp_r3_2275;
    ManagedLight *temp_r4_2254;
    u32 *temp_r31_2271;
    u32 *temp_r3_2266;

    temp_r4_2254 = this->unk4C;
    if (temp_r4_2254 != NULL) {
        ((LightManager *) gb.unk80)->FreeManagedLight(temp_r4_2254);
    }
    this->unk5C.Deinit();
    do {
        temp_r3_2266 = this->unk98 - 4;
        this->unk98 = temp_r3_2266;
    } while ((u32) *temp_r3_2266 != 0);
    temp_r31_2271 = this->unk98;
    if (temp_r31_2271 != &gEmptyPtrList) {
        temp_r3_2275 = ((MKHeap *) temp_r3_2266)->Current();
        if (temp_r3_2275 != NULL) {
            ((MKHeap *) (temp_r3_2275->Current()))->Free(temp_r31_2271, NULL, 0);
        } else {
            free(temp_r31_2271);
        }
    }
    this->unk98 = NULL;
    MKProp::Deinit();
}
#endif

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void Explosion4::Draw() {
    Matrix spC0;
    Matrix sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f64 sp10;
    f32 temp_f30_2343;
    f32 temp_f31_2341;
    f32 temp_f3_2351;

    this->unk5C.Draw();
    if (((s32) this->unk54 == 1) && (this->unk90 > 0.0f) && ((u8) this->unkA8 != 0)) {
        M2C_STRUCT_COPY((s32) &sp80.unk3C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
        temp_f31_2341 = this->unk90 / 0.5f;
        temp_f30_2343 = this->unk64;
        temp_f3_2351 = 1.0f - _table_sinf((6.2831855f * temp_f31_2341) + 1.5707964f);
        sp28 = temp_f30_2343;
        sp20 = this->unk64;
        sp78 = (f64) sp28;
        sp24 = 20.0f * this->unk58 * temp_f3_2351;
        sp70 = (f64) sp20;
        spC0.Scale3x3(&spC0, *((MKVector3 *) &sp70));
        M2C_STRUCT_COPY((s32) &unksp7C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
        sp80.RotatePYR(&sp80, *((MKVector3 *) &this->unk78));
        MKVector(0.0f, 200.0f * this->unk58, 0.0f);
        sp10 = this->unk68 + sp50;
        sp60 = sp10;
        sp18 = M2C_FIELD(this, f32 *, 0x70) + sp58;
        sp68 = (f64) sp18;
        sp80.unk30 = (f32) sp60;
        sp80.unk34 = unksp64;
        sp80.unk38 = (f32) sp68;
        sp80.unk3C = 1.0f;
        spC0.Multiply4x4(&spC0, &sp80);
        MKModel_SetWorldMatrix(M2C_FIELD(checked_cast<Explosion4Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKModel **, 0x68), spC0);
        sp30 = temp_f31_2341;
        sp34 = temp_f31_2341;
        sp38 = temp_f31_2341;
        sp3C = 1.0f;
        sp40 = (f64) sp30;
        sp48 = (f64) sp38;
        MKModel_SetColor(M2C_FIELD(checked_cast<Explosion4Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKModel **, 0x68), *((MKVector4 *) &sp40));
        MKModel_Draw(M2C_FIELD(checked_cast<Explosion4Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKModel **, 0x68), NULL);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp3C4'
void Explosion4::Update() {
    s8 sp406;
    s8 sp405;
    s8 sp404;
    s32 sp400;
    u32 **sp3FC;
    s32 sp3F8;
    s32 sp3F4;
    s32 sp3F0;
    f32 sp3EC;
    f32 sp3E8;
    f64 sp3E0;
    f64 sp3D8;
    s32 sp3D0;
    s32 sp3CC;
    s32 sp3C8;
    f64 sp3C0;
    f64 sp3B8;
    f64 sp3B0;
    f64 sp3A8;
    f64 sp3A0;
    f64 sp398;
    f64 sp390;
    f64 sp388;
    f64 sp380;
    f64 sp378;
    f64 sp370;
    f64 sp368;
    f64 sp360;
    f64 sp358;
    f64 sp350;
    f64 sp348;
    f64 sp340;
    f64 sp338;
    f64 sp330;
    f64 sp328;
    MKVector3 sp318;
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
    MKVector3 sp288;
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
    MKVector3 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    f32 sp1B0;
    f64 sp1A8;
    f32 sp1A0;
    f32 sp19C;
    f32 sp198;
    f32 sp190;
    f64 sp188;
    f32 sp180;
    f32 sp17C;
    f32 sp178;
    f32 sp170;
    f32 sp16C;
    f32 sp168;
    f32 sp160;
    f64 sp158;
    f32 sp150;
    f64 sp148;
    f32 sp140;
    f64 sp138;
    f32 sp130;
    f32 sp12C;
    f32 sp128;
    f32 sp120;
    f64 sp118;
    f32 sp110;
    f32 sp10C;
    f32 sp108;
    f32 sp100;
    f32 spFC;
    f32 spF8;
    f32 spF0;
    f64 spE8;
    f32 spE0;
    f64 spD8;
    f32 spD0;
    f64 spC8;
    f32 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB0;
    f64 spA8;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp80;
    f64 sp78;
    f32 sp70;
    f64 sp68;
    f32 sp60;
    f64 sp58;
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
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Character *temp_r28_2596;
    ManagedLight *temp_r3_2515;
    ManagedLight *temp_r4_2504;
    ManagedLight *temp_r4_2537;
    TargetManager ***var_r30_2585;
    TargetManager **temp_r29_2699;
    f32 temp_f0_2522;
    f32 temp_f0_3095;
    f32 temp_f1_2498;
    f32 temp_f1_2645;
    f32 temp_f1_2831;
    f32 temp_f29_3015;
    f32 temp_f30_2881;
    f32 temp_f31_2747;
    f32 temp_f3_2516;
    f32 temp_f4_2563;
    f32 temp_f6_2965;
    f32 var_f0_2472;
    f64 temp_f0_2634;
    f64 temp_f0_2764;
    f64 temp_f0_2795;
    f64 temp_f0_2807;
    f64 temp_f0_2898;
    f64 temp_f0_2929;
    f64 temp_f0_2941;
    f64 temp_f0_3032;
    f64 temp_f0_3063;
    f64 temp_f0_3075;
    f64 temp_f1_2627;
    f64 temp_f2_2672;
    f64 temp_f3_2671;
    s32 temp_cr0_eq_2609;
    s32 temp_r0_2487;
    void *temp_r28_2745;
    void *temp_r28_2879;
    void *temp_r28_3013;
    void *temp_r3_2524;
    void *temp_r3_2555;
    void *temp_r3_2626;
    void *temp_r3_2729;
    void *temp_r3_2731;
    void *temp_r3_2735;
    void *temp_r3_2865;
    void *temp_r3_2869;
    void *temp_r3_2999;
    void *temp_r3_3003;

    var_f0_2472 = this->unk90 - gUpdateTimeDelta;
    if (var_f0_2472 < 0.5f) {

    } else {
        var_f0_2472 = 0.5f;
    }
    if (var_f0_2472 > 0.0f) {

    } else {
        var_f0_2472 = 0.0f;
    }
    this->unk90 = var_f0_2472;
    temp_r0_2487 = this->unk54;
    if (temp_r0_2487 != 1) {
        if (temp_r0_2487 < 1) {

        }
    } else {
        this->unk50 -= gUpdateTimeDelta;
        temp_f1_2498 = this->unk50;
        if (temp_f1_2498 <= 0.0f) {
            this->unk54 = 0;
            temp_r4_2504 = this->unk4C;
            if (temp_r4_2504 != NULL) {
                ((LightManager *) gb.unk80)->EnableLight(temp_r4_2504, 0U);
            }
        } else {
            temp_r3_2515 = this->unk4C;
            temp_f3_2516 = temp_f1_2498 * 0.5f;
            if (temp_r3_2515 != NULL) {
                temp_f0_2522 = temp_f3_2516 * (10000.0f * this->unk58);
                temp_r3_2515->unk38 = temp_f0_2522;
                temp_r3_2524 = temp_r3_2515->unk3C;
                if (temp_r3_2524 != NULL) {
                    M2C_FIELD(temp_r3_2524, f32 *, 0x20) = temp_f0_2522;
                    M2C_FIELD(temp_r3_2524, f32 *, 0x24) = (f32) (temp_f0_2522 * temp_f0_2522);
                    M2C_FIELD(temp_r3_2524, f32 *, 0x28) = (f32) (1.0f / temp_f0_2522);
                    M2C_FIELD(temp_r3_2524, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_2524, f32 *, 0x24));
                }
                temp_r4_2537 = this->unk4C;
                sp1B8 = temp_r4_2537->unk20 * (f64) temp_f3_2516;
                sp1C0 = temp_r4_2537->unk28 * (f64) temp_f3_2516;
                sp3C0 = sp1C0;
                unksp3C4 = 1.0f;
                temp_r4_2537->unk20 = sp1B8;
                sp3B8 = sp1B8;
                temp_r4_2537->unk28 = sp3C0;
                temp_r3_2555 = temp_r4_2537->unk3C;
                if (temp_r3_2555 != NULL) {
                    M2C_FIELD(temp_r3_2555, f64 *, 0) = sp1B8;
                    M2C_FIELD(temp_r3_2555, f64 *, 8) = sp3C0;
                }
            }
            temp_f4_2563 = this->unk58;
            this->unk64 = (100.0f * temp_f4_2563 * (1.0f - (this->unk90 / 0.5f))) + temp_f4_2563;
            if ((this->unk90 > 0.0f) && ((u8) this->unk94 != 0) && ((u8) this->unkA8 != 0)) {
                var_r30_2585 = gb.unk20->Begin();
loop_30:
                if (var_r30_2585 != NULL) {
                    temp_r29_2699 = *var_r30_2585;
                    if (temp_r29_2699 != NULL) {
                        temp_r28_2596 = ((Character *(*)(TargetManager **)) (*temp_r29_2699)->unk8.unk4)(temp_r29_2699);
                        if (((*temp_r29_2699)->unk8.unk0(temp_r29_2699) != NULL) && (M2C_FIELD(*temp_r29_2699, u8 (**)(TargetManager **), 0x18)(temp_r29_2699) != 0) && ((temp_cr0_eq_2609 = temp_r28_2596 == NULL, (temp_cr0_eq_2609 != 0)) || ((temp_cr0_eq_2609 == 0) && (temp_r28_2596->IsActive() != 0) && (((Enemy *) temp_r28_2596)->IsKnockedUp() == 0)))) {
                            temp_r3_2626 = M2C_FIELD((*temp_r29_2699)->unk8.unk0(temp_r29_2699), void **, 8);
                            temp_f1_2627 = M2C_FIELD(temp_r3_2626, f64 *, 0x30);
                            sp368 = temp_f1_2627;
                            sp370 = M2C_FIELD(temp_r3_2626, f64 *, 0x38);
                            temp_f0_2634 = temp_f1_2627 - this->unk68;
                            sp1A8 = temp_f0_2634;
                            sp3A8 = temp_f0_2634;
                            sp1B0 = (f32) sp370 - M2C_FIELD(this, f32 *, 0x70);
                            temp_f1_2645 = 25.0f * this->unk64;
                            sp3B0 = (f64) sp1B0;
                            if ((((f32) sp3B0 * (f32) sp3B0) + (((f32) sp3A8 * (f32) sp3A8) + (unksp3AC * unksp3AC))) <= (temp_f1_2645 * temp_f1_2645)) {
                                sp3CC = 0;
                                sp3C8 = 4;
                                sp3D0 = 0;
                                temp_f3_2671 = this->unk68;
                                temp_f2_2672 = this->unk70;
                                sp3D8 = temp_f3_2671;
                                sp3E0 = temp_f2_2672;
                                sp3E8 = 0.0f;
                                sp404 = 0;
                                sp3F0 = 8;
                                sp3F8 = 0x1001;
                                sp405 = 0;
                                sp406 = 0;
                                sp3F4 = -1;
                                sp3FC = &this->unk98;
                                sp400 = 0;
                                sp3EC = 1.0f;
                                M2C_FIELD(M2C_FIELD((*temp_r29_2699)->unk8.unk0(temp_r29_2699, -1, 0x1001, 8, 0, 0.0f, temp_f2_2672, temp_f3_2671), void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp3C8);
                            }
                        }
                        var_r30_2585 += 4;
                        goto loop_30;
                    }
                }
            }
            this->unkA4 -= gUpdateTimeDelta;
            this->unkA0 += 1500.0f * this->unk58 * gUpdateTimeDelta;
            if (((2.0f - this->unk50) <= 0.5f) && (this->unkA4 <= 0.0f)) {
                this->unkA4 = 0.1f;
                temp_r3_2729 = checked_cast<Explosion4Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
                temp_r3_2731 = M2C_FIELD(temp_r3_2729, void **, 0x60);
                temp_r3_2735 = M2C_FIELD(M2C_FIELD(temp_r3_2731, void **, 0x44), void *(**)(void *), 0x3C)(temp_r3_2731);
                if (temp_r3_2735 != NULL) {
                    sp180 = -1.0f;
                    temp_r28_2745 = M2C_FIELD(temp_r3_2735, void **, 0x2C);
                    sp170 = 1.0f;
                    temp_f31_2747 = this->unk58;
                    sp178 = -1.0f;
                    sp17C = 0.0f;
                    sp168 = 1.0f;
                    sp16C = 0.0f;
                    sp308 = (f64) sp178;
                    sp310 = (f64) sp180;
                    sp2F8 = (f64) sp168;
                    sp300 = (f64) sp170;
                    KDRand_Vector(sp318, *((MKVector3 *) &sp308));
                    temp_f0_2764 = sp318 * 5.5769738e-315;
                    sp158 = temp_f0_2764;
                    sp328 = temp_f0_2764;
                    sp160 = sp318.unk8 * 200.0f;
                    sp330 = (f64) sp160;
                    sp148 = temp_f0_2764 * (f64) temp_f31_2747;
                    sp1A0 = 0.0f;
                    sp150 = (f32) sp330 * temp_f31_2747;
                    sp198 = 0.0f;
                    sp19C = this->unkA0;
                    sp338 = sp148;
                    sp348 = (f64) sp198;
                    sp340 = (f64) sp150;
                    sp350 = (f64) sp1A0;
                    temp_f0_2795 = this->unk68 + sp348;
                    sp188 = temp_f0_2795;
                    sp358 = temp_f0_2795;
                    sp190 = M2C_FIELD(this, f32 *, 0x70) + (f32) sp350;
                    sp360 = (f64) sp190;
                    temp_f0_2807 = sp358 + sp338;
                    sp138 = temp_f0_2807;
                    M2C_FIELD(temp_r3_2735, f64 *, 0) = temp_f0_2807;
                    sp398 = temp_f0_2807;
                    sp140 = (f32) sp360 + (f32) sp340;
                    M2C_FIELD(temp_r3_2735, f64 *, 8) = (f64) sp140;
                    sp3A0 = (f64) sp140;
                    M2C_FIELD(temp_r3_2735, f32 *, 0x20) = 0.0f;
                    M2C_FIELD(temp_r3_2735, f32 *, 0x24) = MKRand_Float(&gViewSeed, -6.2831855f, 6.2831855f);
                    temp_f1_2831 = this->unk58 * MKRand_Float(&gViewSeed, 5.0f, 8.0f);
                    sp50 = 0.0f;
                    M2C_FIELD(temp_r3_2735, f32 *, 0x28) = temp_f1_2831;
                    sp48 = 0.0f;
                    sp38 = 0.5f;
                    sp4C = 1000.0f * this->unk58;
                    sp3C = 0.5f;
                    M2C_FIELD(temp_r28_2745, f64 *, 0) = (f64) sp48;
                    M2C_FIELD(temp_r28_2745, f64 *, 8) = (f64) sp50;
                    sp40 = 0.5f;
                    M2C_FIELD(temp_r28_2745, f32 *, 0x18) = (f32) M2C_FIELD(temp_r3_2735, f32 *, 0x28);
                    M2C_FIELD(temp_r28_2745, f32 *, 0x10) = 2.3561945f;
                    sp44 = 1.0f;
                    M2C_FIELD(temp_r28_2745, f32 *, 0x14) = (f32) M2C_FIELD(M2C_FIELD(temp_r3_2729, void **, 0x60), f32 *, 0xF4);
                    M2C_FIELD(temp_r3_2735, f64 *, 0x10) = (f64) sp38;
                    sp2E8 = (f64) sp48;
                    sp2F0 = (f64) sp50;
                    sp2D8 = (f64) sp38;
                    sp2E0 = (f64) sp40;
                    M2C_FIELD(temp_r3_2735, f64 *, 0x18) = (f64) sp40;
                }
                temp_r3_2865 = M2C_FIELD(temp_r3_2729, void **, 0x60);
                temp_r3_2869 = M2C_FIELD(M2C_FIELD(temp_r3_2865, void **, 0x44), void *(**)(void *), 0x3C)(temp_r3_2865);
                if (temp_r3_2869 != NULL) {
                    sp110 = -1.0f;
                    temp_r28_2879 = M2C_FIELD(temp_r3_2869, void **, 0x2C);
                    sp100 = 1.0f;
                    temp_f30_2881 = this->unk58;
                    sp108 = -1.0f;
                    sp10C = 0.0f;
                    spF8 = 1.0f;
                    spFC = 0.0f;
                    sp278 = (f64) sp108;
                    sp280 = (f64) sp110;
                    sp268 = (f64) spF8;
                    sp270 = (f64) sp100;
                    KDRand_Vector(sp288, *((MKVector3 *) &sp278));
                    temp_f0_2898 = sp288 * 5.5769738e-315;
                    spE8 = temp_f0_2898;
                    sp298 = temp_f0_2898;
                    spF0 = sp288.unk8 * 200.0f;
                    sp2A0 = (f64) spF0;
                    spD8 = temp_f0_2898 * (f64) temp_f30_2881;
                    sp130 = 0.0f;
                    spE0 = (f32) sp2A0 * temp_f30_2881;
                    sp128 = 0.0f;
                    sp12C = this->unkA0;
                    sp2A8 = spD8;
                    sp2B8 = (f64) sp128;
                    sp2B0 = (f64) spE0;
                    sp2C0 = (f64) sp130;
                    temp_f0_2929 = this->unk68 + sp2B8;
                    sp118 = temp_f0_2929;
                    sp2C8 = temp_f0_2929;
                    sp120 = M2C_FIELD(this, f32 *, 0x70) + (f32) sp2C0;
                    sp2D0 = (f64) sp120;
                    temp_f0_2941 = sp2C8 + sp2A8;
                    spC8 = temp_f0_2941;
                    M2C_FIELD(temp_r3_2869, f64 *, 0) = temp_f0_2941;
                    sp388 = temp_f0_2941;
                    spD0 = (f32) sp2D0 + (f32) sp2B0;
                    M2C_FIELD(temp_r3_2869, f64 *, 8) = (f64) spD0;
                    sp390 = (f64) spD0;
                    M2C_FIELD(temp_r3_2869, f32 *, 0x20) = 0.0f;
                    M2C_FIELD(temp_r3_2869, f32 *, 0x24) = MKRand_Float(&gViewSeed, -6.2831855f, 6.2831855f);
                    temp_f6_2965 = this->unk58 * MKRand_Float(&gViewSeed, 5.0f, 8.0f);
                    sp28 = 0.5f;
                    sp2C = 0.5f;
                    M2C_FIELD(temp_r3_2869, f32 *, 0x28) = temp_f6_2965;
                    sp30 = 0.5f;
                    sp34 = 1.0f;
                    M2C_FIELD(temp_r3_2869, f64 *, 0x10) = (f64) sp28;
                    M2C_FIELD(temp_r3_2869, f64 *, 0x18) = (f64) sp30;
                    sp20 = 0.0f;
                    sp18 = 0.0f;
                    sp1C = 1000.0f * this->unk58;
                    sp258 = (f64) sp28;
                    M2C_FIELD(temp_r28_2879, f64 *, 0) = (f64) sp18;
                    M2C_FIELD(temp_r28_2879, f64 *, 8) = (f64) sp20;
                    sp260 = (f64) sp30;
                    M2C_FIELD(temp_r28_2879, f32 *, 0x18) = (f32) M2C_FIELD(temp_r3_2869, f32 *, 0x28);
                    M2C_FIELD(temp_r28_2879, f32 *, 0x10) = -2.3561945f;
                    sp248 = (f64) sp18;
                    sp250 = (f64) sp20;
                    M2C_FIELD(temp_r28_2879, f32 *, 0x14) = (f32) M2C_FIELD(M2C_FIELD(temp_r3_2729, void **, 0x60), f32 *, 0xF4);
                }
                temp_r3_2999 = M2C_FIELD(temp_r3_2729, void **, 0x64);
                temp_r3_3003 = M2C_FIELD(M2C_FIELD(temp_r3_2999, void **, 0x44), void *(**)(void *), 0x3C)(temp_r3_2999);
                if (temp_r3_3003 != NULL) {
                    spA0 = -1.0f;
                    temp_r28_3013 = M2C_FIELD(temp_r3_3003, void **, 0x2C);
                    sp90 = 1.0f;
                    temp_f29_3015 = this->unk58;
                    sp98 = -1.0f;
                    sp9C = 0.0f;
                    sp88 = 1.0f;
                    sp8C = 0.0f;
                    sp1E8 = (f64) sp98;
                    sp1F0 = (f64) spA0;
                    sp1D8 = (f64) sp88;
                    sp1E0 = (f64) sp90;
                    KDRand_Vector(sp1F8, *((MKVector3 *) &sp1E8));
                    temp_f0_3032 = sp1F8 * 5.5769738e-315;
                    sp78 = temp_f0_3032;
                    sp208 = temp_f0_3032;
                    sp80 = sp1F8.unk8 * 200.0f;
                    sp210 = (f64) sp80;
                    sp68 = temp_f0_3032 * (f64) temp_f29_3015;
                    spC0 = 0.0f;
                    sp70 = (f32) sp210 * temp_f29_3015;
                    spB8 = 0.0f;
                    spBC = this->unkA0;
                    sp218 = sp68;
                    sp228 = (f64) spB8;
                    sp220 = (f64) sp70;
                    sp230 = (f64) spC0;
                    temp_f0_3063 = this->unk68 + sp228;
                    spA8 = temp_f0_3063;
                    sp238 = temp_f0_3063;
                    spB0 = M2C_FIELD(this, f32 *, 0x70) + (f32) sp230;
                    sp240 = (f64) spB0;
                    temp_f0_3075 = sp238 + sp218;
                    sp58 = temp_f0_3075;
                    M2C_FIELD(temp_r3_3003, f64 *, 0) = temp_f0_3075;
                    sp378 = temp_f0_3075;
                    sp60 = (f32) sp240 + (f32) sp220;
                    M2C_FIELD(temp_r3_3003, f64 *, 8) = (f64) sp60;
                    M2C_FIELD(temp_r3_3003, f32 *, 0x20) = 0.0f;
                    sp380 = (f64) sp60;
                    M2C_FIELD(temp_r3_3003, f32 *, 0x24) = 0.0f;
                    temp_f0_3095 = this->unk58 * MKRand_Float(&gViewSeed, 5.0f, 8.0f);
                    sp10 = 0.0f;
                    M2C_FIELD(temp_r3_3003, f32 *, 0x28) = temp_f0_3095;
                    sp8 = 0.0f;
                    sp1D0 = (f64) sp10;
                    spC = 1000.0f * this->unk58;
                    M2C_FIELD(temp_r28_3013, f64 *, 0) = (f64) sp8;
                    M2C_FIELD(temp_r28_3013, f64 *, 8) = (f64) sp10;
                    sp1C8 = (f64) sp8;
                    M2C_FIELD(temp_r28_3013, f32 *, 0x18) = (f32) M2C_FIELD(temp_r3_3003, f32 *, 0x28);
                    M2C_FIELD(temp_r28_3013, f32 *, 0x10) = 0.0f;
                    M2C_FIELD(temp_r28_3013, f32 *, 0x14) = (f32) M2C_FIELD(M2C_FIELD(temp_r3_2729, void **, 0x64), f32 *, 0xF4);
                }
            }
        }
    }
    this->unk5C.Update();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void Explosion4::Resolve() {
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
    ManagedLight *temp_r4_3181;

    MKProp::Resolve();
    sp20 = 0.0f;
    sp30 = 0.0f;
    sp8 = 1.0f;
    spC = 1.0f;
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
    this->unk4C = ((LightManager *) gb.unk80)->AllocManagedLight(*((MKVector3 *) &sp58), *((MKVector3 *) &sp48), *((MKVector4 *) &sp38), 1000.0f, lit_762, lit_763);
    temp_r4_3181 = this->unk4C;
    if (temp_r4_3181 != NULL) {
        ((LightManager *) gb.unk80)->EnableLight(temp_r4_3181, 0U);
    }
}
#endif

#if 0 // DRAFT: ')' expected
void Explosion4::LoadDone() {
    MKProp::LoadDone();
    this->unk88 = M2C_FIELD(checked_cast<Explosion4Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x6C);
    this->unk8C = M2C_FIELD(checked_cast<Explosion4Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x70);
}
#endif

#if 0 // DRAFT: pointer/array required
void Explosion4::Init() {
    MKHeap *temp_r3_3240;
    s32 var_ctr_3260;
    u32 *temp_r3_3262;
    u32 *temp_r3_3267;
    u32 *var_r3_3247;

    MKProp::Init();
    this->unk4C = NULL;
    this->unk54 = 0;
    this->unk5C.Init();
    this->unk88 = 0;
    this->unk8C = 0;
    this->unk94 = 1;
    this->unk9C = 1500.0f;
    temp_r3_3240 = NULL->Current();
    if (temp_r3_3240 != NULL) {
        var_r3_3247 = ((MKHeap *) (temp_r3_3240->Current()))->Alloc(0x30, NULL, 0);
    } else {
        var_r3_3247 = malloc(0x30);
    }
    this->unk98 = var_r3_3247;
    M2C_FIELD(this->unk98, u32 *, 0) = 0;
    var_ctr_3260 = 0xA;
    do {
        temp_r3_3262 = this->unk98;
        this->unk98 = temp_r3_3262 + 4;
        M2C_FIELD(temp_r3_3262, s32 *, 4) = 0xDEADBEEF;
        var_ctr_3260 -= 1;
    } while (var_ctr_3260 != 0);
    temp_r3_3267 = this->unk98;
    this->unk98 = temp_r3_3267 + 4;
    M2C_FIELD(temp_r3_3267, s32 *, 4) = 0;
}
#endif

void Explosion4Descriptor::Deinit() {
    MKModel_Destroy(this->unk68);
    MKPropDescriptor::Deinit();
}

#if 0 // DRAFT: function call 'KDSound_LoadLine(MKIniLine *, const char[11], long *)' does
s32 Explosion4Descriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_3307;

    var_r31_3307 = 0;
    if ((MKPropDescriptor::LoadLine(arg0) != 0) || (KDSound_LoadLine(arg0, "sndExplode", &this->unk6C) != 0) || (KDSound_LoadLine(arg0, "sndExplodeRumble", &this->unk70) != 0)) {
        var_r31_3307 = 1;
    }
    return var_r31_3307;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'KDEnvParticleSystem *' to
void Explosion4Descriptor::Init() {
    MKPropDescriptor::Init();
    this->unk6C = GS_Explosion2;
    this->unk70 = GS_Rumble1Soft;
    this->unk60 = checked_cast<KDEnvParticleSystem *, MKProp>(((MKSceneManager *) gMK)->CreateProp("Exp4FlamePS"));
    this->unk64 = checked_cast<KDEnvParticleSystem *, MKProp>(((MKSceneManager *) gMK)->CreateProp("Exp4SmokePS"));
    this->unk68 = MKModel_Create("FX0001_Exp2Shockwave", NULL, 2, NULL);
}
#endif
