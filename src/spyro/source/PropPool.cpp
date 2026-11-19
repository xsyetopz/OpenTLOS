#include "spyro/source/PropPool.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include <m2c_macros.h>

extern MKSceneManager *gMK;

s32 PropPool::LoadDone() {
    s32 var_r29_116;
    s32 var_r29_133;
    s32 var_r29_150;
    s32 var_r29_167;
    s32 var_r29_184;
    s32 var_r29_201;
    s32 var_r29_218;
    s32 var_r29_235;
    s32 var_r29_252;
    s32 var_r29_269;
    s32 var_r29_286;
    s32 var_r29_303;
    s32 var_r29_320;
    s32 var_r29_337;
    s32 var_r29_354;
    s32 var_r29_371;
    s32 var_r29_388;
    s32 var_r29_405;
    s32 var_r29_422;
    s32 var_r29_439;
    s32 var_r29_456;
    s32 var_r29_48;
    s32 var_r29_65;
    s32 var_r29_82;
    s32 var_r29_99;

    MKProp::LoadDone();
    var_r29_48 = 0;
loop_2:
    if (var_r29_48 < (s32) this->unk4C) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp("LavaBall"), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_48 += 1;
        goto loop_2;
    }
    var_r29_65 = 0;
loop_5:
    if (var_r29_65 < (s32) this->unk50) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp("FireDynamite"), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_65 += 1;
        goto loop_5;
    }
    var_r29_82 = 0;
loop_8:
    if (var_r29_82 < (s32) this->unk54) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp("ElecDynamite"), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_82 += 1;
        goto loop_8;
    }
    var_r29_99 = 0;
loop_11:
    if (var_r29_99 < (s32) this->unk58) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp("IceDynamite"), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_99 += 1;
        goto loop_11;
    }
    var_r29_116 = 0;
loop_14:
    if (var_r29_116 < (s32) this->unk5C) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp("EarthDynamite"), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_116 += 1;
        goto loop_14;
    }
    var_r29_133 = 0;
loop_17:
    if (var_r29_133 < (s32) this->unk60) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp("SteamFireBall"), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_133 += 1;
        goto loop_17;
    }
    var_r29_150 = 0;
loop_20:
    if (var_r29_150 < (s32) this->unk64) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp("Gem"), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_150 += 1;
        goto loop_20;
    }
    var_r29_167 = 0;
loop_23:
    if (var_r29_167 < (s32) this->unk68) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp("MagmaSquirt"), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_167 += 1;
        goto loop_23;
    }
    var_r29_184 = 0;
loop_26:
    if (var_r29_184 < (s32) this->unk6C) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp("Sludge"), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_184 += 1;
        goto loop_26;
    }
    var_r29_201 = 0;
loop_29:
    if (var_r29_201 < (s32) this->unk70) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp("MagicFireball"), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_201 += 1;
        goto loop_29;
    }
    var_r29_218 = 0;
loop_32:
    if (var_r29_218 < (s32) this->unk74) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp("IceBossStomp"), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_218 += 1;
        goto loop_32;
    }
    var_r29_235 = 0;
loop_35:
    if (var_r29_235 < (s32) this->unk78) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp("HotSpit"), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_235 += 1;
        goto loop_35;
    }
    var_r29_252 = 0;
loop_38:
    if (var_r29_252 < (s32) this->unk7C) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp("P0086_DropBox"), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_252 += 1;
        goto loop_38;
    }
    var_r29_269 = 0;
loop_41:
    if (var_r29_269 < (s32) this->unk84) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp("P3020_IceDropBox"), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_269 += 1;
        goto loop_41;
    }
    var_r29_286 = 0;
loop_44:
    if (var_r29_286 < (s32) this->unk80) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp("P4008_EarthDropBox"), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_286 += 1;
        goto loop_44;
    }
    var_r29_303 = 0;
loop_47:
    if (var_r29_303 < (s32) this->unk88) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp("P5003_DropBox"), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_303 += 1;
        goto loop_47;
    }
    var_r29_320 = 0;
loop_50:
    if (var_r29_320 < (s32) this->unk8C) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp("SonicAttack"), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_320 += 1;
        goto loop_50;
    }
    var_r29_337 = 0;
loop_53:
    if (var_r29_337 < (s32) this->unk90) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp("SolidSlug"), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_337 += 1;
        goto loop_53;
    }
    var_r29_354 = 0;
loop_56:
    if (var_r29_354 < (s32) this->unk94) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp("IceShard"), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_354 += 1;
        goto loop_56;
    }
    var_r29_371 = 0;
loop_59:
    if (var_r29_371 < (s32) this->unk98) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp("SpeedwayAA"), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_371 += 1;
        goto loop_59;
    }
    var_r29_388 = 0;
loop_62:
    if (var_r29_388 < (s32) this->unk9C) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp("CynderElecAttack"), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_388 += 1;
        goto loop_62;
    }
    var_r29_405 = 0;
loop_65:
    if (var_r29_405 < (s32) this->unkA0) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp("IceSquirt"), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_405 += 1;
        goto loop_65;
    }
    var_r29_422 = 0;
loop_68:
    if (var_r29_422 < (s32) this->unkA4) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp("PoisonBomb"), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_422 += 1;
        goto loop_68;
    }
    var_r29_439 = 0;
loop_71:
    if (var_r29_439 < (s32) this->unkA8) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp("MagicDrain"), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_439 += 1;
        goto loop_71;
    }
    var_r29_456 = 0;
loop_74:
    if (var_r29_456 < (s32) this->unkAC) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp("FlyingMonkey"), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_456 += 1;
        goto loop_74;
    }
}

s32 PropPool::LoadLine(MKIniLine *arg0) {
    s32 var_r31_488;

    var_r31_488 = 0;
    if ((MKProp::LoadLine(arg0) != 0) || (arg0->LoadInt("LavaBalls", (int *) &this->unk4C, 0) != 0) || (arg0->LoadInt("FireDynamite", (int *) &this->unk50, 0) != 0) || (arg0->LoadInt("ElecDynamite", (int *) &this->unk54, 0) != 0) || (arg0->LoadInt("IceDynamite", (int *) &this->unk58, 0) != 0) || (arg0->LoadInt("EarthDynamite", (int *) &this->unk5C, 0) != 0) || (arg0->LoadInt("SteamFireBall", (int *) &this->unk60, 0) != 0) || (arg0->LoadInt("Gems", (int *) &this->unk64, 0) != 0) || (arg0->LoadInt("MagmaSquirts", (int *) &this->unk68, 0) != 0) || (arg0->LoadInt("Sludges", (int *) &this->unk6C, 0) != 0) || (arg0->LoadInt("MagicFireballs", (int *) &this->unk70, 0) != 0) || (arg0->LoadInt("IceBossStomps", (int *) &this->unk74, 0) != 0) || (arg0->LoadInt("HotSpits", (int *) &this->unk78, 0) != 0) || (arg0->LoadInt("FireDropBoxes", (int *) &this->unk7C, 0) != 0) || (arg0->LoadInt("EarthDropBoxes", (int *) &this->unk80, 0) != 0) || (arg0->LoadInt("IceDropBoxes", (int *) &this->unk84, 0) != 0) || (arg0->LoadInt("ElecDropBoxes", (int *) &this->unk88, 0) != 0) || (arg0->LoadInt("SonicAttacks", (int *) &this->unk8C, 0) != 0) || (arg0->LoadInt("BambooShards", (int *) &this->unk90, 0) != 0) || (arg0->LoadInt("IceShards", (int *) &this->unk94, 0) != 0) || (arg0->LoadInt("SpeedwayAA", (int *) &this->unk98, 0) != 0) || (arg0->LoadInt("CynderElec", (int *) &this->unk9C, 0) != 0) || (arg0->LoadInt("IceSquirts", (int *) &this->unkA0, 0) != 0) || (arg0->LoadInt("PoisonBombs", (int *) &this->unkA4, 0) != 0) || (arg0->LoadInt("MagicDrains", (int *) &this->unkA8, 0) != 0) || (arg0->LoadInt("FlyingMonkeys", (int *) &this->unkAC, 0) != 0)) {
        var_r31_488 = 1;
    }
    return var_r31_488;
}

void PropPool::Init() {
    MKProp::Init();
    this->unk4C = 0;
    this->unk50 = 0;
    this->unk54 = 0;
    this->unk58 = 0;
    this->unk5C = 0;
    this->unk64 = 0;
    this->unk68 = 0;
    this->unk6C = 0;
    this->unk70 = 0;
    this->unk74 = 0;
    this->unk78 = 0;
    this->unk7C = 0;
    this->unk80 = 0;
    this->unk84 = 0;
    this->unk88 = 0;
    this->unk8C = 0;
    this->unk90 = 0;
    this->unk94 = 0;
    this->unk98 = 0;
    this->unk9C = 0;
    this->unkA0 = 0;
    this->unkA4 = 0;
    this->unkA8 = 0;
    this->unkAC = 0;
}
