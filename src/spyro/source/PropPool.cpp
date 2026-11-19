#include "spyro/source/PropPool.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include <m2c_macros.h>

extern MKSceneManager *gMK;
#if 0 // DRAFT: illegal implicit conversion from 'signed char[527]' to
static s8 lit_stringBase0[0x20F] = {
    0x4C,
    0x61,
    0x76,
    0x61,
    0x42,
    0x61,
    0x6C,
    0x6C,
    0,
    0x46,
    0x69,
    0x72,
    0x65,
    0x44,
    0x79,
    0x6E,
    0x61,
    0x6D,
    0x69,
    0x74,
    0x65,
    0,
    0x45,
    0x6C,
    0x65,
    0x63,
    0x44,
    0x79,
    0x6E,
    0x61,
    0x6D,
    0x69,
    0x74,
    0x65,
    0,
    0x49,
    0x63,
    0x65,
    0x44,
    0x79,
    0x6E,
    0x61,
    0x6D,
    0x69,
    0x74,
    0x65,
    0,
    0x45,
    0x61,
    0x72,
    0x74,
    0x68,
    0x44,
    0x79,
    0x6E,
    0x61,
    0x6D,
    0x69,
    0x74,
    0x65,
    0,
    0x53,
    0x74,
    0x65,
    0x61,
    0x6D,
    0x46,
    0x69,
    0x72,
    0x65,
    0x42,
    0x61,
    0x6C,
    0x6C,
    0,
    0x47,
    0x65,
    0x6D,
    0,
    0x4D,
    0x61,
    0x67,
    0x6D,
    0x61,
    0x53,
    0x71,
    0x75,
    0x69,
    0x72,
    0x74,
    0,
    0x53,
    0x6C,
    0x75,
    0x64,
    0x67,
    0x65,
    0,
    0x4D,
    0x61,
    0x67,
    0x69,
    0x63,
    0x46,
    0x69,
    0x72,
    0x65,
    0x62,
    0x61,
    0x6C,
    0x6C,
    0,
    0x49,
    0x63,
    0x65,
    0x42,
    0x6F,
    0x73,
    0x73,
    0x53,
    0x74,
    0x6F,
    0x6D,
    0x70,
    0,
    0x48,
    0x6F,
    0x74,
    0x53,
    0x70,
    0x69,
    0x74,
    0,
    0x50,
    0x30,
    0x30,
    0x38,
    0x36,
    0x5F,
    0x44,
    0x72,
    0x6F,
    0x70,
    0x42,
    0x6F,
    0x78,
    0,
    0x50,
    0x33,
    0x30,
    0x32,
    0x30,
    0x5F,
    0x49,
    0x63,
    0x65,
    0x44,
    0x72,
    0x6F,
    0x70,
    0x42,
    0x6F,
    0x78,
    0,
    0x50,
    0x34,
    0x30,
    0x30,
    0x38,
    0x5F,
    0x45,
    0x61,
    0x72,
    0x74,
    0x68,
    0x44,
    0x72,
    0x6F,
    0x70,
    0x42,
    0x6F,
    0x78,
    0,
    0x50,
    0x35,
    0x30,
    0x30,
    0x33,
    0x5F,
    0x44,
    0x72,
    0x6F,
    0x70,
    0x42,
    0x6F,
    0x78,
    0,
    0x53,
    0x6F,
    0x6E,
    0x69,
    0x63,
    0x41,
    0x74,
    0x74,
    0x61,
    0x63,
    0x6B,
    0,
    0x53,
    0x6F,
    0x6C,
    0x69,
    0x64,
    0x53,
    0x6C,
    0x75,
    0x67,
    0,
    0x49,
    0x63,
    0x65,
    0x53,
    0x68,
    0x61,
    0x72,
    0x64,
    0,
    0x53,
    0x70,
    0x65,
    0x65,
    0x64,
    0x77,
    0x61,
    0x79,
    0x41,
    0x41,
    0,
    0x43,
    0x79,
    0x6E,
    0x64,
    0x65,
    0x72,
    0x45,
    0x6C,
    0x65,
    0x63,
    0x41,
    0x74,
    0x74,
    0x61,
    0x63,
    0x6B,
    0,
    0x49,
    0x63,
    0x65,
    0x53,
    0x71,
    0x75,
    0x69,
    0x72,
    0x74,
    0,
    0x50,
    0x6F,
    0x69,
    0x73,
    0x6F,
    0x6E,
    0x42,
    0x6F,
    0x6D,
    0x62,
    0,
    0x4D,
    0x61,
    0x67,
    0x69,
    0x63,
    0x44,
    0x72,
    0x61,
    0x69,
    0x6E,
    0,
    0x46,
    0x6C,
    0x79,
    0x69,
    0x6E,
    0x67,
    0x4D,
    0x6F,
    0x6E,
    0x6B,
    0x65,
    0x79,
    0,
    0x4C,
    0x61,
    0x76,
    0x61,
    0x42,
    0x61,
    0x6C,
    0x6C,
    0x73,
    0,
    0x47,
    0x65,
    0x6D,
    0x73,
    0,
    0x4D,
    0x61,
    0x67,
    0x6D,
    0x61,
    0x53,
    0x71,
    0x75,
    0x69,
    0x72,
    0x74,
    0x73,
    0,
    0x53,
    0x6C,
    0x75,
    0x64,
    0x67,
    0x65,
    0x73,
    0,
    0x4D,
    0x61,
    0x67,
    0x69,
    0x63,
    0x46,
    0x69,
    0x72,
    0x65,
    0x62,
    0x61,
    0x6C,
    0x6C,
    0x73,
    0,
    0x49,
    0x63,
    0x65,
    0x42,
    0x6F,
    0x73,
    0x73,
    0x53,
    0x74,
    0x6F,
    0x6D,
    0x70,
    0x73,
    0,
    0x48,
    0x6F,
    0x74,
    0x53,
    0x70,
    0x69,
    0x74,
    0x73,
    0,
    0x46,
    0x69,
    0x72,
    0x65,
    0x44,
    0x72,
    0x6F,
    0x70,
    0x42,
    0x6F,
    0x78,
    0x65,
    0x73,
    0,
    0x45,
    0x61,
    0x72,
    0x74,
    0x68,
    0x44,
    0x72,
    0x6F,
    0x70,
    0x42,
    0x6F,
    0x78,
    0x65,
    0x73,
    0,
    0x49,
    0x63,
    0x65,
    0x44,
    0x72,
    0x6F,
    0x70,
    0x42,
    0x6F,
    0x78,
    0x65,
    0x73,
    0,
    0x45,
    0x6C,
    0x65,
    0x63,
    0x44,
    0x72,
    0x6F,
    0x70,
    0x42,
    0x6F,
    0x78,
    0x65,
    0x73,
    0,
    0x53,
    0x6F,
    0x6E,
    0x69,
    0x63,
    0x41,
    0x74,
    0x74,
    0x61,
    0x63,
    0x6B,
    0x73,
    0,
    0x42,
    0x61,
    0x6D,
    0x62,
    0x6F,
    0x6F,
    0x53,
    0x68,
    0x61,
    0x72,
    0x64,
    0x73,
    0,
    0x49,
    0x63,
    0x65,
    0x53,
    0x68,
    0x61,
    0x72,
    0x64,
    0x73,
    0,
    0x43,
    0x79,
    0x6E,
    0x64,
    0x65,
    0x72,
    0x45,
    0x6C,
    0x65,
    0x63,
    0,
    0x49,
    0x63,
    0x65,
    0x53,
    0x71,
    0x75,
    0x69,
    0x72,
    0x74,
    0x73,
    0,
    0x50,
    0x6F,
    0x69,
    0x73,
    0x6F,
    0x6E,
    0x42,
    0x6F,
    0x6D,
    0x62,
    0x73,
    0,
    0x4D,
    0x61,
    0x67,
    0x69,
    0x63,
    0x44,
    0x72,
    0x61,
    0x69,
    0x6E,
    0x73,
    0,
    0x46,
    0x6C,
    0x79,
    0x69,
    0x6E,
    0x67,
    0x4D,
    0x6F,
    0x6E,
    0x6B,
    0x65,
    0x79,
    0x73,
    0,
}; /* const */

void PropPool::LoadDone() {
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
        M2C_FIELD(M2C_FIELD(gMK->CreateProp(lit_stringBase0), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_48 += 1;
        goto loop_2;
    }
    var_r29_65 = 0;
loop_5:
    if (var_r29_65 < (s32) this->unk50) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp(&lit_stringBase0[9]), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_65 += 1;
        goto loop_5;
    }
    var_r29_82 = 0;
loop_8:
    if (var_r29_82 < (s32) this->unk54) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp(&lit_stringBase0[0x16]), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_82 += 1;
        goto loop_8;
    }
    var_r29_99 = 0;
loop_11:
    if (var_r29_99 < (s32) this->unk58) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp(&lit_stringBase0[0x23]), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_99 += 1;
        goto loop_11;
    }
    var_r29_116 = 0;
loop_14:
    if (var_r29_116 < (s32) this->unk5C) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp(&lit_stringBase0[0x2F]), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_116 += 1;
        goto loop_14;
    }
    var_r29_133 = 0;
loop_17:
    if (var_r29_133 < (s32) this->unk60) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp(&lit_stringBase0[0x3D]), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_133 += 1;
        goto loop_17;
    }
    var_r29_150 = 0;
loop_20:
    if (var_r29_150 < (s32) this->unk64) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp(&lit_stringBase0[0x4B]), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_150 += 1;
        goto loop_20;
    }
    var_r29_167 = 0;
loop_23:
    if (var_r29_167 < (s32) this->unk68) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp(&lit_stringBase0[0x4F]), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_167 += 1;
        goto loop_23;
    }
    var_r29_184 = 0;
loop_26:
    if (var_r29_184 < (s32) this->unk6C) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp(&lit_stringBase0[0x5B]), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_184 += 1;
        goto loop_26;
    }
    var_r29_201 = 0;
loop_29:
    if (var_r29_201 < (s32) this->unk70) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp(&lit_stringBase0[0x62]), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_201 += 1;
        goto loop_29;
    }
    var_r29_218 = 0;
loop_32:
    if (var_r29_218 < (s32) this->unk74) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp(&lit_stringBase0[0x70]), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_218 += 1;
        goto loop_32;
    }
    var_r29_235 = 0;
loop_35:
    if (var_r29_235 < (s32) this->unk78) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp(&lit_stringBase0[0x7D]), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_235 += 1;
        goto loop_35;
    }
    var_r29_252 = 0;
loop_38:
    if (var_r29_252 < (s32) this->unk7C) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp(&lit_stringBase0[0x85]), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_252 += 1;
        goto loop_38;
    }
    var_r29_269 = 0;
loop_41:
    if (var_r29_269 < (s32) this->unk84) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp(&lit_stringBase0[0x93]), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_269 += 1;
        goto loop_41;
    }
    var_r29_286 = 0;
loop_44:
    if (var_r29_286 < (s32) this->unk80) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp(&lit_stringBase0[0xA4]), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_286 += 1;
        goto loop_44;
    }
    var_r29_303 = 0;
loop_47:
    if (var_r29_303 < (s32) this->unk88) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp(&lit_stringBase0[0xB7]), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_303 += 1;
        goto loop_47;
    }
    var_r29_320 = 0;
loop_50:
    if (var_r29_320 < (s32) this->unk8C) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp(&lit_stringBase0[0xC5]), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_320 += 1;
        goto loop_50;
    }
    var_r29_337 = 0;
loop_53:
    if (var_r29_337 < (s32) this->unk90) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp(&lit_stringBase0[0xD1]), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_337 += 1;
        goto loop_53;
    }
    var_r29_354 = 0;
loop_56:
    if (var_r29_354 < (s32) this->unk94) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp(&lit_stringBase0[0xDB]), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_354 += 1;
        goto loop_56;
    }
    var_r29_371 = 0;
loop_59:
    if (var_r29_371 < (s32) this->unk98) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp(&lit_stringBase0[0xE4]), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_371 += 1;
        goto loop_59;
    }
    var_r29_388 = 0;
loop_62:
    if (var_r29_388 < (s32) this->unk9C) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp(&lit_stringBase0[0xEF]), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_388 += 1;
        goto loop_62;
    }
    var_r29_405 = 0;
loop_65:
    if (var_r29_405 < (s32) this->unkA0) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp(&lit_stringBase0[0x100]), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_405 += 1;
        goto loop_65;
    }
    var_r29_422 = 0;
loop_68:
    if (var_r29_422 < (s32) this->unkA4) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp(&lit_stringBase0[0x10A]), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_422 += 1;
        goto loop_68;
    }
    var_r29_439 = 0;
loop_71:
    if (var_r29_439 < (s32) this->unkA8) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp(&lit_stringBase0[0x115]), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_439 += 1;
        goto loop_71;
    }
    var_r29_456 = 0;
loop_74:
    if (var_r29_456 < (s32) this->unkAC) {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp(&lit_stringBase0[0x120]), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_456 += 1;
        goto loop_74;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
s32 PropPool::LoadLine(MKIniLine *arg0) {
    s32 var_r31_488;

    var_r31_488 = 0;
    if ((MKProp::LoadLine(arg0) != 0) || (arg0->LoadInt(&lit_stringBase0[0x12D], &this->unk4C, 0) != 0) || (arg0->LoadInt(&lit_stringBase0[9], &this->unk50, 0) != 0) || (arg0->LoadInt(&lit_stringBase0[0x16], &this->unk54, 0) != 0) || (arg0->LoadInt(&lit_stringBase0[0x23], &this->unk58, 0) != 0) || (arg0->LoadInt(&lit_stringBase0[0x2F], &this->unk5C, 0) != 0) || (arg0->LoadInt(&lit_stringBase0[0x3D], &this->unk60, 0) != 0) || (arg0->LoadInt(&lit_stringBase0[0x137], &this->unk64, 0) != 0) || (arg0->LoadInt(&lit_stringBase0[0x13C], &this->unk68, 0) != 0) || (arg0->LoadInt(&lit_stringBase0[0x149], &this->unk6C, 0) != 0) || (arg0->LoadInt(&lit_stringBase0[0x151], &this->unk70, 0) != 0) || (arg0->LoadInt(&lit_stringBase0[0x160], &this->unk74, 0) != 0) || (arg0->LoadInt(&lit_stringBase0[0x16E], &this->unk78, 0) != 0) || (arg0->LoadInt(&lit_stringBase0[0x177], &this->unk7C, 0) != 0) || (arg0->LoadInt(&lit_stringBase0[0x185], &this->unk80, 0) != 0) || (arg0->LoadInt(&lit_stringBase0[0x194], &this->unk84, 0) != 0) || (arg0->LoadInt(&lit_stringBase0[0x1A1], &this->unk88, 0) != 0) || (arg0->LoadInt(&lit_stringBase0[0x1AF], &this->unk8C, 0) != 0) || (arg0->LoadInt(&lit_stringBase0[0x1BC], &this->unk90, 0) != 0) || (arg0->LoadInt(&lit_stringBase0[0x1C9], &this->unk94, 0) != 0) || (arg0->LoadInt(&lit_stringBase0[0xE4], &this->unk98, 0) != 0) || (arg0->LoadInt(&lit_stringBase0[0x1D3], &this->unk9C, 0) != 0) || (arg0->LoadInt(&lit_stringBase0[0x1DE], &this->unkA0, 0) != 0) || (arg0->LoadInt(&lit_stringBase0[0x1E9], &this->unkA4, 0) != 0) || (arg0->LoadInt(&lit_stringBase0[0x1F5], &this->unkA8, 0) != 0) || (arg0->LoadInt(&lit_stringBase0[0x201], &this->unkAC, 0) != 0)) {
        var_r31_488 = 1;
    }
    return var_r31_488;
}
#endif

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
