#include "common/Source/MKIni.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/FileSys.h"
#include "common/Source/Str.h"
#include "common/Source/Utils.h"
#include "common/Source/system_extras.h"
#include <m2c_macros.h>

f64 atof(void *, s32, MKIni *);                     /* extern */
s32 atoi(s8 *, s32, MKIni *);                       /* extern */
M2C_UNK free(void *);                               /* extern */
s32 stricmp(s8 *, s8 *, void *, s32);               /* extern */
s32 strnicmp(s8 *, s32);                            /* extern */
extern MKIniLine *pIni_CurrentLineArray;

#if 0 // DRAFT: function call 'MKArchive_Exists(signed char *, int)' does not match
s32 MKIni::Exists(const char *arg0) {
    s8 *temp_r31_28;

    if (this == NULL) {
        return 0;
    }
    temp_r31_28 = Str_Printf("%s%s", this, ".bni");
    if ((MKArchive_Exists(&this->unk0, NULL) != 0) || (MKArchive_Exists(temp_r31_28, NULL) != 0)) {
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: function call 'strnicmp(signed char *, const char[3], int)' does not match
u8 MKIni::IsMaskedOut(MKIniLine *arg0) {
    s32 var_r25_79;
    s32 var_r27_75;
    s32 var_r28_74;
    s32 var_r29_73;
    u8 *temp_r3_60;
    u8 *var_r30_78;
    u8 *var_r31_72;
    u8 temp_r3_85;
    u8 var_r3_183;

    temp_r3_60 = arg0->GetMaskName();
    if (temp_r3_60 == NULL) {
        return 0U;
    }
    if (this->unk18 & 2) {
        return 0U;
    }
    var_r31_72 = temp_r3_60;
    var_r29_73 = 0;
    var_r28_74 = 0;
    var_r27_75 = 0;
loop_28:
    if ((s8) *var_r31_72 != 0) {
        var_r30_78 = var_r31_72;
        var_r25_79 = 0;
loop_7:
        temp_r3_85 = *var_r30_78;
        if (((s8) temp_r3_85 != 0) && ((s8) temp_r3_85 != 0x3A)) {
            var_r25_79 += 1;
            var_r30_78 += 1;
            goto loop_7;
        }
        if (((s8 *) this->unk44 != NULL) && (strnicmp((s8 *) var_r31_72, var_r25_79) == 0)) {
            var_r27_75 = 1;
        } else if (var_r25_79 == 2) {
            if (strnicmp((s8 *) var_r31_72, "ED", 2) == 0) {
                var_r29_73 |= 8;
            } else if (strnicmp((s8 *) var_r31_72, "P2", 2) == 0) {
                var_r29_73 |= 1;
            } else if (strnicmp((s8 *) var_r31_72, "XB", 2) == 0) {
                var_r29_73 |= 2;
            } else if (strnicmp((s8 *) var_r31_72, "GC", 2) == 0) {
                var_r29_73 |= 4;
            } else if (strnicmp((s8 *) var_r31_72, "PC", 2) == 0) {
                var_r29_73 |= 8;
            } else if (strnicmp((s8 *) var_r31_72, "PP", 2) == 0) {
                var_r29_73 |= 0x10;
            }
        } else {
            var_r28_74 = 1;
        }
        var_r31_72 = var_r30_78;
        if ((s8) *var_r30_78 != 0) {
            var_r31_72 = var_r30_78 + 1;
        }
        goto loop_28;
    }
    var_r3_183 = 0;
    if (((var_r29_73 != 0) && !(var_r29_73 & 4)) || ((var_r27_75 == 0) && (var_r28_74 == 1))) {
        var_r3_183 = 1;
    }
    return var_r3_183;
}
#endif

#if 0 // DRAFT: function call 'MKArchive_Load(const char *, long *, int, int)' does not
void MKIni::ReadBinary(const char *arg0) {
    MKIniLine *temp_r5_215;
    s32 temp_r0_241;
    s32 var_r4_218;
    s32 var_r6_216;
    s8 *temp_r3_214;

    temp_r3_214 = MKArchive_Load(arg0, &this->unk40, NULL, -1);
    temp_r5_215 = temp_r3_214 + 0x44;
    var_r6_216 = 0;
    this->unk10 = temp_r5_215;
    var_r4_218 = 0;
    M2C_FIELD(this, void **, 0) = (void *) (temp_r5_215 + M2C_FIELD(temp_r3_214, s32 *, 0x2C));
    this->unk4 = temp_r5_215 + M2C_FIELD(temp_r3_214, s32 *, 0x30);
    this->unk8 = temp_r5_215 + M2C_FIELD(temp_r3_214, s32 *, 0x34);
    this->unkC = M2C_FIELD(temp_r3_214, u32 *, 0x38);
    this->unk48 = temp_r5_215 + M2C_FIELD(temp_r3_214, s32 *, 0x3C);
    this->unk4C = M2C_FIELD(temp_r3_214, s32 *, 0x40);
    this->unk14 = temp_r3_214;
    this->unk3C = M2C_FIELD(temp_r3_214, s32 *, 0x24);
loop_2:
    if (var_r6_216 < (s32) this->unk3C) {
        temp_r0_241 = var_r4_218 + 0xC;
        var_r6_216 += 1;
        var_r4_218 += 0x10;
        *(this->unk10 + temp_r0_241) = this;
        goto loop_2;
    }
}
#endif

s32 MKIniLine::GetNmbrOfSubLines() {
    MKIniLine *var_r4_268;
    s32 var_r31_264;

    var_r31_264 = 0;
    var_r4_268 = this->unkC->GetSubLine(this);
loop_2:
    if (var_r4_268 != NULL) {
        var_r4_268 = this->unkC->GetNextLine(var_r4_268);
        var_r31_264 += 1;
        goto loop_2;
    }
    return var_r31_264;
}

MKIniLine *MKIni::GetSubLine(MKIniLine *arg0) {
    MKIniLine *var_r31_299;
    u16 temp_r0_295;

    if ((arg0 == NULL) || (temp_r0_295 = arg0->unk8, ((temp_r0_295 == -1U) != 0))) {
        var_r31_299 = NULL;
    } else {
        var_r31_299 = this->unk10 + ((temp_r0_295 * 0x10) & 0xFFFF0);
    }
    if ((var_r31_299 != NULL) && (IsMaskedOut(var_r31_299) != 0)) {
        var_r31_299 = var_r31_299->unkC->GetNextLine(var_r31_299);
    }
    return var_r31_299;
}

MKIniLine *MKIni::GetPrevLine(MKIniLine *arg0) {
    MKIniLine *var_r31_341;

    if ((arg0 == NULL) || (arg0 == (MKIniLine *) this->unk10) || ((s16) arg0->unk0 == -1)) {
        var_r31_341 = NULL;
    } else {
        var_r31_341 = arg0 - 0x10;
    }
    if ((var_r31_341 != NULL) && (IsMaskedOut(var_r31_341) != 0)) {
        var_r31_341 = var_r31_341->unkC->GetPrevLine(var_r31_341);
    }
    return var_r31_341;
}

MKIniLine *MKIni::GetNextLine(MKIniLine *arg0) {
    MKIniLine *var_r31_375;

    if ((arg0 == NULL) || (var_r31_375 = arg0 + 0x10, ((var_r31_375 == &this->unk10[this->unk3C]) != 0)) || ((s16) M2C_FIELD(arg0, s16 *, 0x10) == -1)) {
        var_r31_375 = NULL;
    }
    if ((var_r31_375 != NULL) && (IsMaskedOut(var_r31_375) != 0)) {
        var_r31_375 = var_r31_375->unkC->GetNextLine(var_r31_375);
    }
    return var_r31_375;
}

MKIniLine *MKIni::GetFirstLine() {
    MKIniLine *var_r31_413;

    var_r31_413 = this->unk10;
    if ((var_r31_413 == NULL) || ((s16) var_r31_413->unk0 == -1)) {
        return NULL;
    }
    if (IsMaskedOut(var_r31_413) != 0) {
        var_r31_413 = var_r31_413->unkC->GetNextLine(var_r31_413);
    }
    return var_r31_413;
}

#if 0 // DRAFT: illegal operand
s32 MKIniLine::IsSection(const char *arg0) {
    s32 var_r31_448;
    u16 temp_r0_449;

    var_r31_448 = 0;
    temp_r0_449 = this->unk2;
    if ((temp_r0_449 != -1U) && (stricmp(*this->unkC + ((temp_r0_449 * 4) & 0x3FFFC)) == 0)) {
        var_r31_448 = 1;
    }
    return var_r31_448;
}
#endif

#if 0 // DRAFT: illegal operand
s32 MKIniLine::IsField(const char *arg0) {
    s32 var_r31_476;
    u16 temp_r0_477;

    var_r31_476 = 0;
    temp_r0_477 = this->unk4;
    if ((temp_r0_477 != -1U) && (stricmp(*this->unkC + ((temp_r0_477 * 4) & 0x3FFFC)) == 0)) {
        var_r31_476 = 1;
    }
    return var_r31_476;
}
#endif

#if 0 // DRAFT: illegal operand
s32 MKIniLine::LoadVector4(const char *arg0, MKVector4 *arg1, int arg2) {
    u16 temp_r0_507;

    temp_r0_507 = this->unk4;
    if ((temp_r0_507 != -1U) && (stricmp(*this->unkC + ((temp_r0_507 * 4) & 0x3FFFC)) == 0)) {
        return AsVector4(arg2, arg1);
    }
    return 0;
}
#endif

#if 0 // DRAFT: illegal operand
s32 MKIniLine::LoadVector3(const char *arg0, MKVector3 *arg1, int arg2) {
    u16 temp_r0_542;

    temp_r0_542 = this->unk4;
    if ((temp_r0_542 != -1U) && (stricmp(*this->unkC + ((temp_r0_542 * 4) & 0x3FFFC)) == 0)) {
        return AsVector3(arg2, arg1);
    }
    return 0;
}
#endif

#if 0 // DRAFT: illegal operand
s32 MKIniLine::LoadString(const char *arg0, const char **arg1, int arg2) {
    u16 temp_r0_577;

    temp_r0_577 = this->unk4;
    if ((temp_r0_577 != -1U) && (stricmp(*this->unkC + ((temp_r0_577 * 4) & 0x3FFFC)) == 0)) {
        return AsString(arg2, arg1);
    }
    return 0;
}
#endif

#if 0 // DRAFT: illegal operand
s32 MKIniLine::LoadFloat(const char *arg0, float *arg1, int arg2) {
    u16 temp_r0_612;

    temp_r0_612 = this->unk4;
    if ((temp_r0_612 != -1U) && (stricmp(*this->unkC + ((temp_r0_612 * 4) & 0x3FFFC)) == 0)) {
        return AsFloat(arg2, arg1);
    }
    return 0;
}
#endif

#if 0 // DRAFT: illegal operand
s32 MKIniLine::LoadInt(const char *arg0, int *arg1, int arg2) {
    u16 temp_r0_647;

    temp_r0_647 = this->unk4;
    if ((temp_r0_647 != -1U) && (stricmp(*this->unkC + ((temp_r0_647 * 4) & 0x3FFFC)) == 0)) {
        return AsInt(arg2, arg1);
    }
    return 0;
}
#endif

#if 0 // DRAFT: illegal operand
s32 MKIniLine::LoadBool(const char *arg0, bool *arg1, int arg2) {
    u16 temp_r0_682;

    temp_r0_682 = this->unk4;
    if ((temp_r0_682 != -1U) && (stricmp(*this->unkC + ((temp_r0_682 * 4) & 0x3FFFC)) == 0)) {
        return AsBool(arg2, arg1);
    }
    return 0;
}
#endif

#if 0 // DRAFT: illegal type
s32 MKIniLine::AsVector4(int arg0, MKVector4 *arg1) {
    MKIni *temp_r4_724;
    MKIni *temp_r4_736;
    MKIni *temp_r4_749;
    MKIni *temp_r4_770;
    s32 temp_r4_728;
    s32 temp_r4_740;
    s32 temp_r4_753;
    s32 temp_r4_774;

    if ((s32) (arg0 + 2) >= (s16) this->unk0) {
        return 0;
    }
    temp_r4_724 = this->unkC;
    temp_r4_728 = M2C_FIELD(temp_r4_724, s32 *, 0);
    arg1->unk0 = (f32) atof(temp_r4_728 + (*(temp_r4_724->unk4 + ((this->unk6 + arg0) * 2)) * 4), temp_r4_728);
    temp_r4_736 = this->unkC;
    temp_r4_740 = M2C_FIELD(temp_r4_736, s32 *, 0);
    arg1->unk4 = (f32) atof(temp_r4_740 + (M2C_FIELD((temp_r4_736->unk4 + ((this->unk6 + arg0) * 2)), u16 *, 2) * 4), temp_r4_740);
    temp_r4_749 = this->unkC;
    temp_r4_753 = M2C_FIELD(temp_r4_749, s32 *, 0);
    arg1->unk8 = (f32) atof(temp_r4_753 + (M2C_FIELD((temp_r4_749->unk4 + ((this->unk6 + arg0) * 2)), u16 *, 4) * 4), temp_r4_753);
    if ((s32) (arg0 + 3) >= (s16) this->unk0) {
        arg1->unkC = 1.0f;
    } else {
        temp_r4_770 = this->unkC;
        temp_r4_774 = M2C_FIELD(temp_r4_770, s32 *, 0);
        arg1->unkC = (f32) atof(temp_r4_774 + (M2C_FIELD((temp_r4_770->unk4 + ((this->unk6 + arg0) * 2)), u16 *, 6) * 4), temp_r4_774);
    }
    return 1;
}
#endif

#if 0 // DRAFT: illegal type
s32 MKIniLine::AsVector3(int arg0, MKVector3 *arg1) {
    MKIni *temp_r4_810;
    MKIni *temp_r4_822;
    MKIni *temp_r4_835;
    s32 temp_r4_814;
    s32 temp_r4_826;
    s32 temp_r4_839;

    if ((s32) (arg0 + 2) >= (s16) this->unk0) {
        return 0;
    }
    temp_r4_810 = this->unkC;
    temp_r4_814 = M2C_FIELD(temp_r4_810, s32 *, 0);
    arg1->unk0 = (f32) atof(temp_r4_814 + (*(temp_r4_810->unk4 + ((this->unk6 + arg0) * 2)) * 4), temp_r4_814);
    temp_r4_822 = this->unkC;
    temp_r4_826 = M2C_FIELD(temp_r4_822, s32 *, 0);
    arg1->unk4 = (f32) atof(temp_r4_826 + (M2C_FIELD((temp_r4_822->unk4 + ((this->unk6 + arg0) * 2)), u16 *, 2) * 4), temp_r4_826);
    temp_r4_835 = this->unkC;
    temp_r4_839 = M2C_FIELD(temp_r4_835, s32 *, 0);
    arg1->unk8 = (f32) atof(temp_r4_839 + (M2C_FIELD((temp_r4_835->unk4 + ((this->unk6 + arg0) * 2)), u16 *, 4) * 4), temp_r4_839);
    arg1->unkC = 1.0f;
    return 1;
}
#endif

#if 0 // DRAFT: illegal type
s32 MKIniLine::AsString(int arg0, const char **arg1) {
    MKIni *temp_r7_868;

    if (arg0 >= (s16) this->unk0) {
        return 0;
    }
    temp_r7_868 = this->unkC;
    *arg1 = M2C_FIELD(temp_r7_868, s32 *, 0) + (*(temp_r7_868->unk4 + ((this->unk6 + arg0) * 2)) * 4);
    return 1;
}
#endif

#if 0 // DRAFT: illegal type
s32 MKIniLine::AsFloat(int arg0, float *arg1) {
    MKIni *temp_r5_896;
    s32 temp_r4_900;

    if (arg0 >= (s16) this->unk0) {
        return 0;
    }
    temp_r5_896 = this->unkC;
    temp_r4_900 = M2C_FIELD(temp_r5_896, s32 *, 0);
    *arg1 = (f32) atof(temp_r4_900 + (*(temp_r5_896->unk4 + ((this->unk6 + arg0) * 2)) * 4), temp_r4_900, temp_r5_896);
    return 1;
}
#endif

#if 0 // DRAFT: illegal type
s32 MKIniLine::AsInt(int arg0, int *arg1) {
    MKIni *temp_r5_931;
    s32 temp_r4_935;

    if (arg0 >= (s16) this->unk0) {
        return 0;
    }
    temp_r5_931 = this->unkC;
    temp_r4_935 = M2C_FIELD(temp_r5_931, s32 *, 0);
    *arg1 = atoi(temp_r4_935 + (*(temp_r5_931->unk4 + ((this->unk6 + arg0) * 2)) * 4), temp_r4_935, temp_r5_931);
    return 1;
}
#endif

s32 MKIniLine::AsBool(int arg0, bool *arg1) {
    if (arg0 >= (s16) this->unk0) {
        return 0;
    }
    *arg1 = GetFlag(arg0) != 0;
    return 1;
}

s32 MKIniLine::AsFlag(int arg0, int *arg1) {
    if (arg0 >= (s16) this->unk0) {
        return 0;
    }
    *arg1 = GetFlag(arg0);
    return 1;
}

void MKIniLine::GetVector3(int arg0) {
    f64 sp10;
    f64 sp8;

    sp8 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    sp10 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    ((MKIniLine *) arg0)->AsVector3(M2C_ERROR(/* Read from unset register $r5 */), (MKVector3 *) &sp8);
    M2C_FIELD(this, f64 *, 0) = sp8;
    M2C_FIELD(this, f64 *, 8) = sp10;
}

#if 0 // DRAFT: illegal type
f32 MKIniLine::GetFloat(int arg0) {
    MKIni *temp_r5_1043;
    u8 *temp_r3_1051;

    if (arg0 >= (s16) this->unk0) {
        return 0.0f;
    }
    temp_r5_1043 = this->unkC;
    temp_r3_1051 = M2C_FIELD(temp_r5_1043, s32 *, 0) + (*(temp_r5_1043->unk4 + ((this->unk6 + arg0) * 2)) * 4);
    if (temp_r3_1051 != NULL) {
        if ((s32) *temp_r3_1051 == 0x23) {
            return (f32) atof(temp_r3_1051 + 1) / 255.0f;
        }
        return (f32) atof();
    }
    return 0.0f;
}
#endif

#if 0 // DRAFT: illegal type
s32 MKIniLine::GetInt(int arg0) {
    MKIni *temp_r5_1087;
    s32 temp_r4_1091;

    if (arg0 >= (s16) this->unk0) {
        return 0;
    }
    temp_r5_1087 = this->unkC;
    temp_r4_1091 = M2C_FIELD(temp_r5_1087, s32 *, 0);
    return atoi(temp_r4_1091 + (*(temp_r5_1087->unk4 + ((this->unk6 + arg0) * 2)) * 4), temp_r4_1091, temp_r5_1087);
}
#endif

#if 0 // DRAFT: illegal type
s32 MKIniLine::GetFlag(int arg0) {
    MKIni *temp_r6_1117;
    s32 temp_r6_1123;
    s8 *temp_r31_1128;
    void *temp_r5_1121;

    if (arg0 >= (s16) this->unk0) {
        return 0;
    }
    temp_r6_1117 = this->unkC;
    temp_r5_1121 = temp_r6_1117->unk4;
    temp_r6_1123 = M2C_FIELD(temp_r6_1117, s32 *, 0);
    temp_r31_1128 = temp_r6_1123 + (*(temp_r5_1121 + ((this->unk6 + arg0) * 2)) * 4);
    if ((stricmp(temp_r31_1128, "true", temp_r5_1121, temp_r6_1123) == 0) || (stricmp(temp_r31_1128, "on") == 0)) {
        return 1;
    }
    if ((stricmp(temp_r31_1128, "false") == 0) || (stricmp(temp_r31_1128, "off") == 0)) {
        return 0;
    }
    return atoi(temp_r31_1128);
}
#endif

s32 MKIniLine::GetBool(int arg0) {
    return GetFlag(arg0) != 0;
}

#if 0 // DRAFT: illegal type
s32 MKIniLine::GetString(int arg0) {
    MKIni *temp_r5_1196;

    if (arg0 >= (s16) this->unk0) {
        return 0;
    }
    temp_r5_1196 = this->unkC;
    return M2C_FIELD(temp_r5_1196, s32 *, 0) + (*(temp_r5_1196->unk4 + ((this->unk6 + arg0) * 2)) * 4);
}
#endif

#if 0 // DRAFT: illegal operand
u8 *MKIniLine::GetMaskName() {
    u16 temp_r0_1211;

    temp_r0_1211 = this->unkA;
    if (temp_r0_1211 == -1U) {
        return NULL;
    }
    return *this->unkC + ((temp_r0_1211 * 4) & 0x3FFFC);
}
#endif

#if 0 // DRAFT: illegal operand
s8 *MKIniLine::GetFieldName() {
    u16 temp_r0_1227;

    temp_r0_1227 = this->unk4;
    if (temp_r0_1227 == -1U) {
        return NULL;
    }
    return *this->unkC + ((temp_r0_1227 * 4) & 0x3FFFC);
}
#endif

#if 0 // DRAFT: illegal operand
s8 *MKIniLine::GetSectionName() {
    u16 temp_r0_1243;

    temp_r0_1243 = this->unk2;
    if (temp_r0_1243 == -1U) {
        return NULL;
    }
    return *this->unkC + ((temp_r0_1243 * 4) & 0x3FFFC);
}
#endif

#if 0 // DRAFT: undefined identifier 'StringHash'
MKIniLine *MKIni::GotoLine(const char *arg0, const char *arg1) {
    MKIniLine *temp_r3_1266;
    MKIniLine *var_r28_1283;
    s32 temp_cr0_eq_1318;
    s32 temp_r28_1295;
    u16 *temp_r3_1316;
    u16 temp_r0_1296;
    u32 temp_r4_1286;
    u8 var_r3_1284;

    temp_r3_1266 = this->unk10;
    if ((temp_r3_1266 == NULL) || ((s16) temp_r3_1266->unk0 == -1)) {
        return NULL;
    }
    if ((arg0 == NULL) && (arg1 == NULL)) {
        return temp_r3_1266;
    }
    var_r28_1283 = temp_r3_1266;
    var_r3_1284 = 0;
    if (arg0 != NULL) {
        temp_r4_1286 = this->unkC;
        if ((temp_r4_1286 != 0) && ((s32) this->unk4C != 0)) {
            temp_r28_1295 = StringHash(arg0, (s32) temp_r4_1286) * 2;
            temp_r0_1296 = *(this->unk8 + temp_r28_1295);
            if ((temp_r0_1296 == -1U) || (((MKIniLine *) (this->unk10 + ((temp_r0_1296 * 0x10) & 0xFFFF0)))->GetSectionName(), ((stricmp(arg0) == 0) == 0))) {
                pIni_CurrentLineArray = this->unk10;
                temp_r3_1316 = Util_BinarySearch(arg0, this->unk48, this->unk4C, 2, (s32 (*)(void *, void *)) iniSectionCompare);
                temp_cr0_eq_1318 = temp_r3_1316 == NULL;
                pIni_CurrentLineArray = NULL;
                if (temp_cr0_eq_1318 != 0) {
                    return NULL;
                }
                var_r28_1283 = &this->unk10[*temp_r3_1316];
                goto block_15;
            }
            var_r28_1283 = &this->unk10[*(this->unk8 + temp_r28_1295)];
block_15:
            var_r3_1284 = 1;
            goto block_16;
        }
    }
block_16:
    if (arg1 != NULL) {
        if (arg0 == NULL) {
loop_20:
            if ((var_r28_1283 > (MKIniLine *) this->unk10) && (var_r28_1283->GetSectionName() == NULL)) {
                var_r28_1283 -= 0x10;
                goto loop_20;
            }
            if (var_r28_1283->GetSectionName() != NULL) {
                var_r28_1283 += 0x10;
            }
        } else if (var_r3_1284 != 0) {
            var_r28_1283 += 0x10;
        }
loop_31:
        if ((s16) var_r28_1283->unk0 == -1) {
            goto block_32;
        }
        if (var_r28_1283->GetSectionName() != NULL) {
            return NULL;
        }
        if ((var_r28_1283->GetFieldName() == NULL) || (stricmp(arg1, var_r28_1283->GetFieldName()) != 0)) {
            var_r28_1283 += 0x10;
            goto loop_31;
        }
block_32:
        if ((s16) var_r28_1283->unk0 == -1) {
            return NULL;
        }
        goto block_34;
    }
block_34:
    if ((s16) var_r28_1283->unk0 == -1) {
        return NULL;
    }
    return var_r28_1283;
}
#endif

void MKIni::Warning(const char *arg0) {

}

#if 0 // DRAFT: illegal use of non-static member
void MKIni::Deinit() {
    MKHeap *temp_r3_1429;
    void *temp_r31_1426;

    temp_r31_1426 = this->unk14;
    if (temp_r31_1426 != NULL) {
        temp_r3_1429 = MKHeap::Current();
        if (temp_r3_1429 != NULL) {
            ((MKHeap *) (temp_r3_1429->Current()))->Free(temp_r31_1426, NULL, 0);
        } else {
            free(temp_r31_1426);
        }
        this->unk14 = NULL;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const char *' to
s32 MKIni::Init(const char *arg0, int arg1, const char *arg2) {
    s32 sp8;
    s8 *temp_r31_1483;

    this->unk8 = NULL;
    this->unk10 = NULL;
    this->unk3C = 0;
    this->unk44 = arg2;
    this->unk14 = NULL;
    this->unk18 = arg1;
    if (arg0 == NULL) {
        strcpy(&this->unk1C, "(NULL).");
        return 0;
    }
    temp_r31_1483 = Str_Printf("%s%s", ".bni");
    strncpy(&this->unk1C, arg0, 0x1FU);
    if (MKArchive_Exists(temp_r31_1483, &sp8) != 0) {
        ReadBinary(temp_r31_1483);
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: illegal operand
void iniSectionCompare(const void *arg0, const void *arg1) {
    stricmp((s8 *) arg0, ((MKIniLine *) (&pIni_CurrentLineArray[*arg1]))->GetSectionName());
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const char *' to
s32 StringHash(const char *arg0, int arg1) {
    s8 *var_r4_1543;
    u32 temp_r3_1542;
    u32 var_ctr_1544;
    u32 var_r31_1541;
    u8 temp_r0_1548;

    var_r31_1541 = 0;
    temp_r3_1542 = strlen(arg0);
    var_r4_1543 = arg0;
    var_ctr_1544 = temp_r3_1542;
    if (temp_r3_1542 > 0U) {
        do {
            temp_r0_1548 = (u8) *var_r4_1543;
            var_r4_1543 += 1;
            var_r31_1541 = (var_r31_1541 * 0x11) + ((s8) temp_r0_1548 | 0x20);
            var_ctr_1544 -= 1;
        } while (var_ctr_1544 != 0);
    }
    return var_r31_1541 % arg1;
}
#endif
