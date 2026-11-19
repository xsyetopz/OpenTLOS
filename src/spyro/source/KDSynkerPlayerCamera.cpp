#include "spyro/source/KDSynkerPlayerCamera.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/KDBasicEnvelope.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/KDSynkerPlayerActor.h"
#include "spyro/source/KDSynkerPlayerActorList.h"
#include "spyro/source/KDSynkerPlayerTools.h"
#include "unplaced_templates.h"
#include "common/Source/FileSys.h"
#include "common/Source/StdMath.h"
#include "common/Source/Str.h"
#include "common/Source/system_extras.h"
#include "spyro/source/KDMath.h"
#include <m2c_macros.h>

M2C_UNK free(u32 *);                                /* extern */
f32 strcat(s8 *, s8 *);                             /* extern */
s32 strcmpi(s8 *, s8 *);                            /* extern */
s32 stricmp(s32, s8 *);                             /* extern */
extern f32 *KDSpline_PositionMixer;

#if 0 // DRAFT: function call 'stricmp(long, const char *)' does not match
void *KDSP_Camera::FindCameraPath(const char *arg0) {
    s32 var_r30_17;
    s32 var_r31_18;

    var_r30_17 = 0;
    var_r31_18 = 0;
loop_4:
    if (var_r30_17 >= (s32) this->unk74) {
        return NULL;
    }
    if (stricmp(*(this->unk78 + var_r31_18), arg0) == 0) {
        return this->unk78 + var_r31_18;
    }
    var_r30_17 += 1;
    var_r31_18 += 0x40;
    goto loop_4;
}
#endif

#if 0 // DRAFT: function call 'strcmpi(long, const char *)' does not match
void *KDSP_Camera::FindCAD(const char *arg0) {
    s32 var_r30_55;
    s32 var_r31_56;

    var_r30_55 = 0;
    var_r31_56 = 0;
loop_4:
    if (var_r30_55 >= (s32) this->unk7C) {
        return NULL;
    }
    if (strcmpi(*(this->unk84 + (var_r31_56 + 8)), arg0) == 0) {
        return this->unk84 + var_r31_56;
    }
    var_r30_55 += 1;
    var_r31_56 += 0xC;
    goto loop_4;
}
#endif

#if 0 // DRAFT: function call 'MKArchive_Load(const char *, long *, int, int)' does not
void KDSP_Camera::ParseMCDFile(const char *arg0) {
    u32 *var_r31_101;

    this->unk94 = MKArchive_Load(arg0, &this->unk90, NULL, -1);
    this->unk98 = NULL;
    var_r31_101 = this->unk94;
loop_5:
    if (var_r31_101 < (void *) (this->unk94 + this->unk90)) {
        if ((u32) (Endian<int unsigned>(*var_r31_101) + 0xBBB30000) == 0x4143U) {
            this->unk98 = var_r31_101 + 0xC;
        } else {
            Endian<int unsigned>(*var_r31_101);
        }
        var_r31_101 = var_r31_101 + Endian<int unsigned>(*(var_r31_101 + 4)) + 8;
        goto loop_5;
    }
}
#endif

#if 0 // DRAFT: function call 'strcmpi(const char[6])' does not match
void KDSP_Camera::ParseCAD(KDSynkerHeap *arg0, const char *arg1) {
    MKIniLine *temp_r3_159;
    MKIniLine *var_r28_175;
    MKIniLine *var_r30_165;
    s32 *var_r29_157;
    s32 temp_r7_149;
    void *temp_r8_148;

    if ((MKIni *) this->unk80 != NULL) {
        temp_r8_148 = arg0->unk18;
        temp_r7_149 = arg0->unk20 - 1;
        arg0->unk18 = ((u8 *) temp_r8_148) + (((this->unk7C * 0xC) + temp_r7_149) & ~temp_r7_149);
        this->unk84 = (s32 *) temp_r8_148;
        var_r29_157 = this->unk84;
        temp_r3_159 = this->unk80->GotoLine("Camera", NULL);
        if (temp_r3_159 != NULL) {
            var_r30_165 = temp_r3_159->unkC->GetSubLine(temp_r3_159);
loop_9:
            if (var_r30_165 != NULL) {
                M2C_FIELD(var_r29_157, s8 **, 8) = var_r30_165->GetFieldName();
                var_r28_175 = var_r30_165->unkC->GetSubLine(var_r30_165);
loop_7:
                if (var_r28_175 != NULL) {
                    var_r28_175->GetFieldName();
                    if (strcmpi("Range") == 0) {
                        M2C_FIELD(var_r29_157, s32 *, 0) = var_r28_175->GetInt(0);
                        M2C_FIELD(var_r29_157, s32 *, 4) = (s32) (var_r28_175->GetInt(1) - M2C_FIELD(var_r29_157, s32 *, 0));
                    }
                    var_r28_175 = var_r28_175->unkC->GetSubLine(var_r28_175);
                    goto loop_7;
                }
                var_r29_157 += 0xC;
                var_r30_165 = var_r30_165->unkC->GetNextLine(var_r30_165);
                goto loop_9;
            }
        }
    }
}
#endif

#if 0 // DRAFT: function call 'strcpy(signed char *, const char *)' does not match
void KDSP_Camera::HeapAddSizeCAD(KDSynkerHeap *arg0, const char *arg1) {
    s8 sp8;
    s32 temp_r3_292;
    s32 var_r3_240;

    this->unk80 = NULL;
    strcpy(&sp8, arg1);
    strcat(&sp8, ".cad");
    var_r3_240 = MKArchive_Exists(&sp8, NULL);
    if ((u8) var_r3_240 == 0) {
        strcat(&sp8, ".bni");
        var_r3_240 = MKArchive_Exists(&sp8, NULL);
    }
    if ((u8) var_r3_240 != 0) {
        strcpy(&sp8, arg1);
        ParseMCDFile(Str_Printf("%s.mcd", arg1, strcat(&sp8, ".cad")));
        operator new(0x50U, NULL, 0);
        this->unk80 = M2C_ERROR(/* Read from unset register $r3 */);
        this->unk80->Init(&sp8, 1, NULL);
        this->unk7C = ((MKIniLine *) (this->unk80->GotoLine("Camera", NULL)))->GetNmbrOfSubLines();
        temp_r3_292 = arg0->unk20 - 1;
        arg0->unk1C += ((this->unk7C * 0xC) + temp_r3_292) & ~temp_r3_292;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
void KDSP_Camera::Parse(KDSynkerHeap *arg0, const char *arg1, MKIni *arg2, int &arg3) {
    MKIniLine sp18;
    MKIniLine sp8;
    MKIniLine *temp_r3_331;
    MKIniLine *temp_r3_561;
    MKIniLine *var_r21_362;
    MKIniLine *var_r23_443;
    MKIniLine *var_r23_584;
    MKIniLine *var_r25_351;
    MKIniLine *var_r26_594;
    s32 *var_r22_579;
    s32 *var_r30_345;
    s32 temp_r3_392;
    s32 temp_r3_569;
    s32 temp_r4_675;
    s32 temp_r5_337;
    s32 temp_r6_412;
    s32 temp_r6_427;
    s32 var_r0_676;
    s32 var_r22_359;
    s32 var_r23_358;
    s32 var_r26_360;
    s8 *temp_r3_604;
    u8 var_r27_630;
    void *temp_r4_391;
    void *temp_r4_410;
    void *temp_r4_425;
    void *temp_r5_568;
    void *temp_r6_338;

    ParseCAD(arg0, arg1);
    if ((s32) this->unk74 > 0) {
        temp_r3_331 = arg2->GotoLine("CAMERA_NODES", NULL);
        if (temp_r3_331 != NULL) {
            temp_r5_337 = arg0->unk20 - 1;
            temp_r6_338 = arg0->unk18;
            arg0->unk18 = ((u8 *) temp_r6_338) + (((this->unk74 << 6) + temp_r5_337) & ~temp_r5_337);
            this->unk78 = (s32 *) temp_r6_338;
            var_r30_345 = this->unk78;
            var_r25_351 = temp_r3_331->unkC->GetSubLine(temp_r3_331);
loop_33:
            if (var_r25_351 != NULL) {
                var_r23_358 = 0;
                var_r22_359 = 0;
                var_r26_360 = 0;
                var_r21_362 = var_r25_351->unkC->GetSubLine(var_r25_351);
loop_9:
                if (var_r21_362 != NULL) {
                    if (var_r21_362->IsField("eye") != 0) {
                        var_r23_358 += 1;
                    } else if (var_r21_362->IsField("dst") != 0) {
                        var_r22_359 += 1;
                    }
                    var_r21_362 = var_r21_362->unkC->GetNextLine(var_r21_362);
                    goto loop_9;
                }
                if (var_r23_358 > 0) {
                    temp_r4_391 = arg0->unk18;
                    temp_r3_392 = arg0->unk20 - 1;
                    arg0->unk18 = ((u8 *) temp_r4_391) + (((var_r23_358 * 4) + temp_r3_392) & ~temp_r3_392);
                    M2C_FIELD(var_r30_345, void **, 0x14) = temp_r4_391;
                } else {
                    M2C_FIELD(var_r30_345, void **, 0x14) = NULL;
                }
                M2C_FIELD(var_r30_345, s32 *, 0) = var_r25_351->GetFieldName();
                if (var_r23_358 > 0) {
                    temp_r4_410 = arg0->unkC;
                    temp_r6_412 = arg0->unk14 - 1;
                    arg0->unkC = ((u8 *) temp_r4_410) + (((var_r23_358 << 5) + temp_r6_412) & ~temp_r6_412);
                    ((KDUniformSpline *) (var_r30_345 + 0x18))->Init(temp_r4_410, var_r23_358, 0U);
                }
                if (var_r22_359 > 0) {
                    temp_r4_425 = arg0->unkC;
                    temp_r6_427 = arg0->unk14 - 1;
                    arg0->unkC = ((u8 *) temp_r4_425) + (((var_r22_359 << 5) + temp_r6_427) & ~temp_r6_427);
                    ((KDUniformSpline *) (var_r30_345 + 0x2C))->Init(temp_r4_425, var_r22_359, 0U);
                }
                M2C_FIELD(var_r30_345, f32 *, 4) = 0.7853982f;
                M2C_FIELD(var_r30_345, f32 *, 8) = 0.7853982f;
                M2C_FIELD(var_r30_345, f32 *, 0xC) = 30.0f;
                M2C_FIELD(var_r30_345, f32 *, 0x10) = 30000.0f;
                var_r23_443 = var_r25_351->unkC->GetSubLine(var_r25_351);
loop_31:
                if (var_r23_443 != NULL) {
                    if (var_r23_443->IsField("FromFOV") != 0) {
                        M2C_FIELD(var_r30_345, f32 *, 4) = (f32) (0.017453292f * var_r23_443->GetFloat(0));
                    } else if (var_r23_443->IsField("ToFOV") != 0) {
                        M2C_FIELD(var_r30_345, f32 *, 8) = (f32) (0.017453292f * var_r23_443->GetFloat(0));
                    } else if (var_r23_443->IsField("NearPlane") != 0) {
                        M2C_FIELD(var_r30_345, f32 *, 0xC) = var_r23_443->GetFloat(0);
                    } else if (var_r23_443->IsField("FarPlane") != 0) {
                        M2C_FIELD(var_r30_345, f32 *, 0x10) = var_r23_443->GetFloat(0);
                    } else if (var_r23_443->IsField("eye") != 0) {
                        sp18.GetVector3((s32) var_r23_443);
                        ((KDUniformSpline *) (var_r30_345 + 0x18))->AddNode(*((MKVector3 *) &sp18));
                        *(M2C_FIELD(var_r30_345, void **, 0x14) + var_r26_360) = var_r23_443->GetFloat(3);
                        var_r26_360 += 4;
                    } else if (var_r23_443->IsField("dst") != 0) {
                        sp8.GetVector3((s32) var_r23_443);
                        ((KDUniformSpline *) (var_r30_345 + 0x2C))->AddNode(*((MKVector3 *) &sp8));
                    }
                    var_r23_443 = var_r23_443->unkC->GetNextLine(var_r23_443);
                    goto loop_31;
                }
                var_r30_345 += 0x40;
                var_r25_351 = var_r25_351->unkC->GetNextLine(var_r25_351);
                goto loop_33;
            }
        }
    }
    if ((s32) this->unk88 > 0) {
        temp_r3_561 = arg2->GotoLine("CAMERA", NULL);
        if (temp_r3_561 != NULL) {
            temp_r5_568 = arg0->unk18;
            temp_r3_569 = arg0->unk20 - 1;
            arg0->unk18 = ((u8 *) temp_r5_568) + (((this->unk88 * 0x18) + temp_r3_569) & ~temp_r3_569);
            this->unk8C = (s32 *) temp_r5_568;
            memset(this->unk8C, 0, this->unk88 * 0x18);
            var_r22_579 = this->unk8C;
            var_r23_584 = temp_r3_561->unkC->GetSubLine(temp_r3_561);
loop_53:
            if (var_r23_584 != NULL) {
                M2C_FIELD(var_r22_579, void **, 8) = NULL;
                M2C_FIELD(var_r22_579, void **, 0xC) = NULL;
                var_r26_594 = var_r23_584->unkC->GetSubLine(var_r23_584);
loop_49:
                if (var_r26_594 != NULL) {
                    if (var_r26_594->IsField("BarName") != 0) {
                        temp_r3_604 = var_r26_594->GetString(0);
                        if (strnicmp(temp_r3_604, "MAX:", 4) == 0) {
                            M2C_FIELD(var_r22_579, void **, 0xC) = FindCAD(temp_r3_604 + 4);
                        } else {
                            M2C_FIELD(var_r22_579, void **, 8) = FindCameraPath(temp_r3_604);
                        }
                    } else {
                        var_r27_630 = 0;
                        if ((var_r26_594->LoadInt("start", var_r22_579, 0) != 0) || (var_r26_594->LoadInt("length", var_r22_579 + 4, 0) != 0) || (var_r26_594->LoadInt("env", var_r22_579 + 0x10, 0) != 0)) {
                            var_r27_630 = 1;
                        }
                        if (var_r27_630 == 0) {
                            var_r26_594->LoadInt("freq", var_r22_579 + 0x14, 0);
                        }
                    }
                    var_r26_594 = var_r26_594->unkC->GetNextLine(var_r26_594);
                    goto loop_49;
                }
                temp_r4_675 = &arg3;
                var_r0_676 = M2C_FIELD(var_r22_579, s32 *, 0) + M2C_FIELD(var_r22_579, s32 *, 4);
                if (temp_r4_675 > var_r0_676) {
                    var_r0_676 = temp_r4_675;
                }
                &arg3 = var_r0_676;
                var_r22_579 += 0x18;
                var_r23_584 = var_r23_584->unkC->GetNextLine(var_r23_584);
                goto loop_53;
            }
        }
    }
}
#endif

void KDSP_Camera::HeapAddSize(KDSynkerHeap *arg0, const char *arg1, MKIni *arg2) {
    MKIniLine *temp_r3_723;
    MKIniLine *temp_r3_813;
    MKIniLine *var_r23_745;
    MKIniLine *var_r30_736;
    s32 temp_r0_819;
    s32 temp_r0_831;
    s32 temp_r3_783;
    s32 temp_r3_794;
    s32 temp_r3_825;
    s32 temp_r3_837;
    s32 temp_r4_776;
    s32 var_r24_742;
    s32 var_r29_743;

    this->unk74 = 0;
    this->unk88 = 0;
    temp_r3_723 = arg2->GotoLine("CAMERA_NODES", NULL);
    if (temp_r3_723 != NULL) {
        this->unk74 = temp_r3_723->GetNmbrOfSubLines();
    }
    if ((s32) this->unk74 > 0) {
        var_r30_736 = temp_r3_723->unkC->GetSubLine(temp_r3_723);
loop_16:
        if (var_r30_736 != NULL) {
            var_r24_742 = 0;
            var_r29_743 = 0;
            var_r23_745 = var_r30_736->unkC->GetSubLine(var_r30_736);
loop_10:
            if (var_r23_745 != NULL) {
                if (var_r23_745->IsField("eye") != 0) {
                    var_r24_742 += 1;
                } else if (var_r23_745->IsField("dst") != 0) {
                    var_r29_743 += 1;
                }
                var_r23_745 = var_r23_745->unkC->GetNextLine(var_r23_745);
                goto loop_10;
            }
            if (var_r24_742 > 0) {
                temp_r4_776 = arg0->unk20 - 1;
                arg0->unk1C += ((var_r24_742 * 4) + temp_r4_776) & ~temp_r4_776;
                temp_r3_783 = arg0->unk14 - 1;
                arg0->unk10 += ((var_r24_742 << 5) + temp_r3_783) & ~temp_r3_783;
            }
            if (var_r29_743 > 0) {
                temp_r3_794 = arg0->unk14 - 1;
                arg0->unk10 += ((var_r29_743 << 5) + temp_r3_794) & ~temp_r3_794;
            }
            var_r30_736 = var_r30_736->unkC->GetNextLine(var_r30_736);
            goto loop_16;
        }
    }
    temp_r3_813 = arg2->GotoLine("CAMERA", NULL);
    if (temp_r3_813 != NULL) {
        this->unk88 = temp_r3_813->GetNmbrOfSubLines();
    }
    temp_r0_819 = this->unk74;
    if (temp_r0_819 > 0) {
        temp_r3_825 = arg0->unk20 - 1;
        arg0->unk1C += ((temp_r0_819 << 6) + temp_r3_825) & ~temp_r3_825;
    }
    temp_r0_831 = this->unk88;
    if (temp_r0_831 > 0) {
        temp_r3_837 = arg0->unk20 - 1;
        arg0->unk1C += ((temp_r0_831 * 0x18) + temp_r3_837) & ~temp_r3_837;
    }
    HeapAddSizeCAD(arg0, arg1);
}

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void KDSP_Camera::Update(const char *arg0, float arg1, KDSP_EnvelopeList *arg2) {
    s32 sp2AC;
    s32 sp2A8;
    Matrix sp220;
    Matrix sp1E0;
    Matrix sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;                                      /* compiler-managed */
    f64 sp180;                                      /* compiler-managed */
    f64 sp178;                                      /* compiler-managed */
    f64 sp170;                                      /* compiler-managed */
    f64 sp168;                                      /* compiler-managed */
    f64 sp160;                                      /* compiler-managed */
    MKVector3 sp150;
    MKVector3 sp140;
    MKVector3 sp130;
    MKVector3 sp120;
    MKVector3 sp110;
    MKVector3 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    MKVector3 spC0;
    f64 spB8;
    f64 spB0;
    MKVector3 spA0;
    f64 sp90;
    f64 sp80;
    f32 sp78;
    f64 sp70;
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
    s32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    KDSP_Actor *temp_r5_954;
    KDSP_Bar *temp_r28_927;
    f32 *temp_r4_1897;
    f32 temp_f0_1301;
    f32 temp_f0_1709;
    f32 temp_f1_1171;
    f32 temp_f1_1753;
    f32 temp_f1_1761;
    f32 temp_f1_1769;
    f32 temp_f1_1900;
    f32 temp_f29_1139;
    f32 temp_f2_1901;
    f32 temp_f30_1751;
    f32 temp_f30_1759;
    f32 temp_f30_1767;
    f32 temp_f31_975;
    f32 temp_f5_1318;
    f32 var_f1_1152;
    f32 var_f29_1819;
    f32 var_f29_1906;
    f32 var_f31_1158;
    f32 var_f31_955;
    f32 var_f3_1698;
    f32 var_f3_940;
    f32 var_f5_1446;
    f32 var_f6_1520;
    f32 var_f6_1609;
    f32 var_f7_1538;
    f32 var_f7_1627;
    f64 temp_f1_1459;
    f64 temp_f1_1465;
    f64 temp_f1_1469;
    f64 temp_f1_1548;
    f64 temp_f1_1554;
    f64 temp_f1_1558;
    f64 temp_f1_1637;
    f64 temp_f1_1643;
    f64 temp_f1_1647;
    s32 *temp_r3_1802;
    s32 *temp_r3_1860;
    s32 *temp_r6_877;
    s32 temp_r0_1898;
    s32 temp_r0_893;
    s32 temp_r25_1128;
    s32 temp_r25_978;
    s32 temp_r27_980;
    s32 temp_r3_1131;
    s32 temp_r3_1133;
    s32 temp_r3_1488;
    s32 temp_r3_1577;
    s32 temp_r3_1666;
    s32 temp_r5_882;
    s32 temp_r7_902;
    s32 temp_r8_881;
    s32 var_ctr_896;
    s32 var_r0_1498;
    s32 var_r0_1587;
    s32 var_r0_1676;
    s32 var_r29_981;
    s32 var_r3_895;
    s32 var_r9_894;
    u32 *temp_r27_994;
    u32 *temp_r5_962;
    u32 *var_r28_966;
    u8 var_r4_870;
    u8 var_r4_901;
    void *temp_r29_1799;
    void *temp_r3_880;
    void *temp_r5_900;

    var_r4_870 = 0;
    this->unk6C = 0;
    temp_r6_877 = this->unk8C;
    temp_r3_880 = temp_r6_877 + (this->unk70 * 0x18);
    temp_r8_881 = (s32) arg1;
    temp_r5_882 = M2C_FIELD(temp_r3_880, s32 *, 0);
    if ((temp_r8_881 >= temp_r5_882) && (temp_r8_881 < (s32) (temp_r5_882 + M2C_FIELD(temp_r3_880, s32 *, 4)))) {
        var_r4_870 = 1;
    }
    if (var_r4_870 == 0) {
        temp_r0_893 = this->unk88;
        var_r9_894 = 0;
        var_r3_895 = 0;
        var_ctr_896 = temp_r0_893;
        if (temp_r0_893 > 0) {
loop_5:
            temp_r5_900 = temp_r6_877 + var_r3_895;
            var_r4_901 = 0;
            temp_r7_902 = M2C_FIELD(temp_r5_900, s32 *, 0);
            if ((temp_r8_881 >= temp_r7_902) && (temp_r8_881 < (s32) (temp_r7_902 + M2C_FIELD(temp_r5_900, s32 *, 4)))) {
                var_r4_901 = 1;
            }
            if (var_r4_901 != 0) {
                this->unk70 = var_r9_894;
            } else {
                var_r9_894 += 1;
                var_r3_895 += 0x18;
                var_ctr_896 -= 1;
                if (var_ctr_896 != 0) {
                    goto loop_5;
                }
            }
        }
    }
    temp_r28_927 = this->unk8C + (this->unk70 * 0x18);
    var_f3_940 = (arg1 - (f32) temp_r28_927->unk0) / (f32) temp_r28_927->unk4;
    if (var_f3_940 < 1.0f) {

    } else {
        var_f3_940 = 1.0f;
    }
    if (var_f3_940 > 0.0f) {

    } else {
        var_f3_940 = 0.0f;
    }
    temp_r5_954 = temp_r28_927->unkC;
    var_f31_955 = var_f3_940;
    if (temp_r5_954 != NULL) {
        temp_r5_962 = this->unk98;
        var_r28_966 = temp_r5_962 + 8;
        temp_f31_975 = ((f32) temp_r5_954->unk4 * var_f3_940) + (f32) temp_r5_954->unk0;
        temp_r25_978 = (s32) temp_f31_975;
        temp_r27_980 = Endian<int unsigned>(*(temp_r5_962 + 4)) - 1;
        var_r29_981 = 0;
loop_21:
        if (var_r29_981 < temp_r27_980) {
            if (temp_r25_978 >= Endian<int>(*(var_r28_966 + 0x30))) {
                var_r28_966 += 0x30;
                var_r29_981 += 1;
                goto loop_21;
            }
        }
        temp_r27_994 = var_r28_966 + 0x30;
        sp220.SetIdentity();
        sp220 = (f32) Endian<short>(*(s16 *) (var_r28_966 + 4)) / 16384.0f;
        sp220.unk4 = (f32) Endian<short>(*(var_r28_966 + 6)) / 16384.0f;
        sp220.unk8 = (f32) Endian<short>(*(s16 *) (var_r28_966 + 8)) / 16384.0f;
        sp220.unk10 = (f32) Endian<short>(*(var_r28_966 + 0xA)) / 16384.0f;
        sp220.unk14 = (f32) Endian<short>(*(s16 *) (var_r28_966 + 0xC)) / 16384.0f;
        sp220.unk18 = (f32) Endian<short>(*(var_r28_966 + 0xE)) / 16384.0f;
        sp220.unk20 = (f32) Endian<short>(*(s16 *) (var_r28_966 + 0x10)) / 16384.0f;
        sp220.unk24 = (f32) Endian<short>(*(var_r28_966 + 0x12)) / 16384.0f;
        sp220.unk28 = (f32) Endian<short>(*(s16 *) (var_r28_966 + 0x14)) / 16384.0f;
        sp220.unk30 = Endian<float>(*(f32 *) (var_r28_966 + 0x18));
        sp220.unk34 = Endian<float>(*(f32 *) (var_r28_966 + 0x1C));
        sp220.unk38 = Endian<float>(*(f32 *) (var_r28_966 + 0x20));
        temp_r25_1128 = Endian<int>(*temp_r27_994);
        temp_r3_1131 = temp_r25_1128 - Endian<int>(*var_r28_966);
        temp_r3_1133 = temp_r3_1131 ^ 0x80000000;
        sp2A8 = 0x43300000;
        sp2AC = temp_r3_1133;
        temp_f29_1139 = (f32) temp_r3_1131;
        if (temp_f29_1139 == 1.0f) {
            var_f1_1152 = (temp_f31_975 - (f32) Endian<int>(*var_r28_966)) / temp_f29_1139;
        } else {
            var_f1_1152 = 0.0f;
        }
        var_f31_1158 = var_f1_1152;
        if (temp_f29_1139 == 1.0f) {
            sp1E0.SetIdentity();
            sp1E0.unk30 = Endian<float>(*(f32 *) (temp_r27_994 + 0x18));
            sp1E0.unk34 = Endian<float>(*(f32 *) (temp_r27_994 + 0x1C));
            temp_f1_1171 = Endian<float>(*(f32 *) (temp_r27_994 + 0x20));
            sp1E0.unk38 = temp_f1_1171;
            sp70 = sp220.unk30 - sp1E0.unk30;
            sp190 = sp70;
            sp78 = sp220.unk38 - (f32) temp_f1_1171;
            sp198 = (f64) sp78;
            if ((((f32) sp198 * (f32) sp198) + (((f32) sp190 * (f32) sp190) + ((*(f32 *) ((u8 *) &sp190 + 0x4)) * (*(f32 *) ((u8 *) &sp190 + 0x4))))) > 6400.0f) {
                var_f31_1158 = 0.0f;
            } else {
                sp1E0 = (f32) Endian<short>(*(s16 *) (temp_r27_994 + 4)) / 16384.0f;
                sp1E0.unk4 = (f32) Endian<short>(*(temp_r27_994 + 6)) / 16384.0f;
                sp1E0.unk8 = (f32) Endian<short>(*(s16 *) (temp_r27_994 + 8)) / 16384.0f;
                sp1E0.unk10 = (f32) Endian<short>(*(temp_r27_994 + 0xA)) / 16384.0f;
                sp1E0.unk14 = (f32) Endian<short>(*(s16 *) (temp_r27_994 + 0xC)) / 16384.0f;
                sp1E0.unk18 = (f32) Endian<short>(*(temp_r27_994 + 0xE)) / 16384.0f;
                sp1E0.unk20 = (f32) Endian<short>(*(s16 *) (temp_r27_994 + 0x10)) / 16384.0f;
                temp_f0_1301 = (f32) Endian<short>(*(temp_r27_994 + 0x12)) / 16384.0f;
                sp1E0.unk24 = temp_f0_1301;
                temp_f5_1318 = (f32) Endian<short>(*(s16 *) (temp_r27_994 + 0x14)) / 16384.0f;
                sp1E0.unk28 = temp_f5_1318;
                if (((sp220.unk28 * temp_f5_1318) + ((sp220.unk20 * sp1E0.unk20) + (sp220.unk24 * temp_f0_1301))) < _table_sinf(1.9198623f)) {
                    var_f31_1158 = 0.0f;
                }
            }
        }
        if (var_f31_1158 == 0.0f) {
            this->unk6C = 1;
            Matrix::SetIdentity();
            M2C_STRUCT_COPY((s32) (this - 4) + 4, (s32) &sp1E0.unk3C + 4, 0x40);
            this->unk60 = Endian<float>(*(f32 *) (var_r28_966 + 0x24));
            this->unk64 = Endian<float>(*(f32 *) (var_r28_966 + 0x28));
            this->unk68 = Endian<float>(*(f32 *) (var_r28_966 + 0x2C));
        } else {
            InterpolateLinear(sp140, *((MKVector3 *) &sp220), var_f31_1158);
            Normalise(sp150);
            sp180 = M2C_BITWISE(f64, sp150);
            sp188 = (f64) sp150.unk8;
            InterpolateLinear(sp120, *((MKVector3 *) &sp220.unk10), var_f31_1158);
            Normalise(sp130);
            sp170 = M2C_BITWISE(f64, sp130);
            sp178 = (f64) sp130.unk8;
            InterpolateLinear(sp100, *((MKVector3 *) &sp220.unk20), var_f31_1158);
            Normalise(sp110);
            sp160 = M2C_BITWISE(f64, sp110);
            sp168 = (f64) sp110.unk8;
            sp64 = ((f32) sp168 * (f32) sp180) - ((f32) sp160 * (f32) sp188);
            sp68 = ((f32) sp160 * (*(f32 *) ((u8 *) &sp150 + 0x34))) - ((*(f32 *) ((u8 *) &sp150 + 0x14)) * (f32) sp180);
            sp60 = ((*(f32 *) ((u8 *) &sp150 + 0x14)) * (f32) sp188) - ((f32) sp168 * (*(f32 *) ((u8 *) &sp150 + 0x34)));
            sp178 = (f64) sp68;
            sp170 = (f64) sp60;
            spF0 = (f64) sp60;
            spF8 = (f64) sp68;
            sp50 = ((*(f32 *) ((u8 *) &sp150 + 0x24)) * (f32) sp168) - ((f32) sp178 * (*(f32 *) ((u8 *) &sp150 + 0x14)));
            sp54 = ((f32) sp178 * (f32) sp160) - ((f32) sp170 * (f32) sp168);
            sp58 = ((f32) sp170 * (*(f32 *) ((u8 *) &sp150 + 0x14))) - ((*(f32 *) ((u8 *) &sp150 + 0x24)) * (f32) sp160);
            sp180 = (f64) sp50;
            sp188 = (f64) sp58;
            spE0 = (f64) sp50;
            spE8 = (f64) sp58;
            sp48 = ((f32) sp180 * (*(f32 *) ((u8 *) &sp150 + 0x24))) - ((*(f32 *) ((u8 *) &sp150 + 0x34)) * (f32) sp170);
            var_f5_1446 = ((f32) sp188 * (f32) sp188) + (((f32) sp180 * (f32) sp180) + ((*(f32 *) ((u8 *) &sp150 + 0x34)) * (*(f32 *) ((u8 *) &sp150 + 0x34))));
            sp40 = ((*(f32 *) ((u8 *) &sp150 + 0x34)) * (f32) sp178) - ((f32) sp188 * (*(f32 *) ((u8 *) &sp150 + 0x24)));
            sp44 = ((f32) sp188 * (f32) sp170) - ((f32) sp180 * (f32) sp178);
            spD8 = (f64) sp48;
            spD0 = (f64) sp40;
            sp160 = (f64) sp40;
            sp168 = (f64) sp48;
            if (var_f5_1446 > 0.000001f) {
                if (var_f5_1446 > 0.0f) {
                    temp_f1_1459 = __frsqrte(var_f5_1446);
                    temp_f1_1465 = 0.5 * temp_f1_1459 * -(((f64) var_f5_1446 * (temp_f1_1459 * temp_f1_1459)) - 3.0);
                    temp_f1_1469 = 0.5 * temp_f1_1465 * -(((f64) var_f5_1446 * (temp_f1_1465 * temp_f1_1465)) - 3.0);
                    var_f5_1446 = (f32) ((f64) var_f5_1446 * (0.5 * temp_f1_1469 * -(((f64) var_f5_1446 * (temp_f1_1469 * temp_f1_1469)) - 3.0)));
                } else if (var_f5_1446 < M2C_BITWISE(f32, 0.0)) {
                    var_f5_1446 = __float_nan;
                } else {
                    sp18 = var_f5_1446;
                    temp_r3_1488 = M2C_BITWISE(s32, sp18) & 0x7F800000;
                    switch (temp_r3_1488) {         /* switch 1; irregular */
                    case 0x7F800000:                /* switch 1 */
                        if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                            var_r0_1498 = 1;
                        } else {
                            var_r0_1498 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 1 */
                        if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                            var_r0_1498 = 5;
                        } else {
                            var_r0_1498 = 3;
                        }
                        break;
                    default:                        /* switch 1 */
                        var_r0_1498 = 4;
                        break;
                    }
                    if (var_r0_1498 == 1) {
                        var_f5_1446 = __float_nan;
                    }
                }
                var_f6_1520 = 1.0f / var_f5_1446;
            } else {
                var_f6_1520 = 0.0f;
            }
            var_f7_1538 = ((f32) sp178 * (f32) sp178) + (((f32) sp170 * (f32) sp170) + ((*(f32 *) ((u8 *) &sp150 + 0x24)) * (*(f32 *) ((u8 *) &sp150 + 0x24))));
            sp180 = (f32) sp180 * var_f6_1520;
            (*(f32 *) ((u8 *) &sp150 + 0x34)) *= var_f6_1520;
            sp188 = (f32) sp188 * var_f6_1520;
            if (var_f7_1538 > 0.000001f) {
                if (var_f7_1538 > 0.0f) {
                    temp_f1_1548 = __frsqrte(var_f7_1538);
                    temp_f1_1554 = 0.5 * temp_f1_1548 * -(((f64) var_f7_1538 * (temp_f1_1548 * temp_f1_1548)) - 3.0);
                    temp_f1_1558 = 0.5 * temp_f1_1554 * -(((f64) var_f7_1538 * (temp_f1_1554 * temp_f1_1554)) - 3.0);
                    var_f7_1538 = (f32) ((f64) var_f7_1538 * (0.5 * temp_f1_1558 * -(((f64) var_f7_1538 * (temp_f1_1558 * temp_f1_1558)) - 3.0)));
                } else if (var_f7_1538 < M2C_BITWISE(f32, 0.0)) {
                    var_f7_1538 = __float_nan;
                } else {
                    sp14 = var_f7_1538;
                    temp_r3_1577 = M2C_BITWISE(s32, sp14) & 0x7F800000;
                    switch (temp_r3_1577) {         /* switch 2; irregular */
                    case 0x7F800000:                /* switch 2 */
                        if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                            var_r0_1587 = 1;
                        } else {
                            var_r0_1587 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 2 */
                        if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                            var_r0_1587 = 5;
                        } else {
                            var_r0_1587 = 3;
                        }
                        break;
                    default:                        /* switch 2 */
                        var_r0_1587 = 4;
                        break;
                    }
                    if (var_r0_1587 == 1) {
                        var_f7_1538 = __float_nan;
                    }
                }
                var_f6_1609 = 1.0f / var_f7_1538;
            } else {
                var_f6_1609 = 0.0f;
            }
            var_f7_1627 = ((f32) sp168 * (f32) sp168) + (((f32) sp160 * (f32) sp160) + ((*(f32 *) ((u8 *) &sp150 + 0x14)) * (*(f32 *) ((u8 *) &sp150 + 0x14))));
            sp170 = (f32) sp170 * var_f6_1609;
            (*(f32 *) ((u8 *) &sp150 + 0x24)) *= var_f6_1609;
            sp178 = (f32) sp178 * var_f6_1609;
            if (var_f7_1627 > 0.000001f) {
                if (var_f7_1627 > 0.0f) {
                    temp_f1_1637 = __frsqrte(var_f7_1627);
                    temp_f1_1643 = 0.5 * temp_f1_1637 * -(((f64) var_f7_1627 * (temp_f1_1637 * temp_f1_1637)) - 3.0);
                    temp_f1_1647 = 0.5 * temp_f1_1643 * -(((f64) var_f7_1627 * (temp_f1_1643 * temp_f1_1643)) - 3.0);
                    var_f7_1627 = (f32) ((f64) var_f7_1627 * (0.5 * temp_f1_1647 * -(((f64) var_f7_1627 * (temp_f1_1647 * temp_f1_1647)) - 3.0)));
                } else if (var_f7_1627 < M2C_BITWISE(f32, 0.0)) {
                    var_f7_1627 = __float_nan;
                } else {
                    sp10 = var_f7_1627;
                    temp_r3_1666 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                    switch (temp_r3_1666) {         /* switch 3; irregular */
                    case 0x7F800000:                /* switch 3 */
                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                            var_r0_1676 = 1;
                        } else {
                            var_r0_1676 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 3 */
                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                            var_r0_1676 = 5;
                        } else {
                            var_r0_1676 = 3;
                        }
                        break;
                    default:                        /* switch 3 */
                        var_r0_1676 = 4;
                        break;
                    }
                    if (var_r0_1676 == 1) {
                        var_f7_1627 = __float_nan;
                    }
                }
                var_f3_1698 = 1.0f / var_f7_1627;
            } else {
                var_f3_1698 = 0.0f;
            }
            temp_f0_1709 = (f32) sp168 * var_f3_1698;
            sp160 = (f32) sp160 * var_f3_1698;
            (*(f32 *) ((u8 *) &sp150 + 0x14)) *= var_f3_1698;
            sp168 = temp_f0_1709;
            Matrix::SetIdentity();
            this->unk0 = sp180;
            this->unk4 = (*(f32 *) ((u8 *) &sp150 + 0x34));
            this->unk8 = sp188;
            this->unkC = 0.0f;
            this->unk10 = sp170;
            this->unk14 = (*(f32 *) ((u8 *) &sp150 + 0x24));
            this->unk18 = sp178;
            this->unk1C = 0.0f;
            this->unk20 = sp160;
            this->unk24 = (*(f32 *) ((u8 *) &sp150 + 0x14));
            this->unk28 = temp_f0_1709;
            this->unk2C = 0.0f;
            InterpolateLinear(spC0, *((MKVector3 *) &sp220.unk30), var_f31_1158);
            this->unk30 = M2C_BITWISE(f32, spC0);
            this->unk34 = spC0.unk4;
            this->unk38 = spC0.unk8;
            this->unk3C = 1.0f;
            temp_f30_1751 = Endian<float>(*(f32 *) (temp_r27_994 + 0x24));
            temp_f1_1753 = Endian<float>(*(f32 *) (var_r28_966 + 0x24));
            this->unk60 = (var_f31_1158 * (temp_f30_1751 - temp_f1_1753)) + temp_f1_1753;
            temp_f30_1759 = Endian<float>(*(f32 *) (temp_r27_994 + 0x28));
            temp_f1_1761 = Endian<float>(*(f32 *) (var_r28_966 + 0x28));
            this->unk64 = (var_f31_1158 * (temp_f30_1759 - temp_f1_1761)) + temp_f1_1761;
            temp_f30_1767 = Endian<float>(*(f32 *) (temp_r27_994 + 0x2C));
            temp_f1_1769 = Endian<float>(*(f32 *) (var_r28_966 + 0x2C));
            this->unk68 = (var_f31_1158 * (temp_f30_1767 - temp_f1_1769)) + temp_f1_1769;
        }
        this->unk40 = (f64) M2C_FIELD(this, f32 *, 0x30);
        this->unk48 = (f64) M2C_FIELD(this, f32 *, 0x38);
        __ml(50.0f, spA0);
        sp30 = this->unk40 + M2C_BITWISE(f64, spA0);
        this->unk50 = sp30;
        sp38 = (f32) M2C_FIELD(this, f64 *, 0x48) + spA0.unk8;
        spB0 = sp30;
        spB8 = (f64) sp38;
        this->unk58 = (f64) sp38;
        return;
    }
    temp_r29_1799 = temp_r28_927->unk8;
    temp_r3_1802 = arg2->GetEnvelope(temp_r28_927->unk10);
    var_f29_1819 = (arg1 - (f32) temp_r28_927->unk0) / (f32) temp_r28_927->unk4;
    if (var_f29_1819 < 1.0f) {

    } else {
        var_f29_1819 = 1.0f;
    }
    if (var_f29_1819 > 0.0f) {

    } else {
        var_f29_1819 = 0.0f;
    }
    if (temp_r3_1802 != NULL) {
        var_f31_955 = ((KDBasicEnvelope *) temp_r3_1802)->GetValue(var_f29_1819);
    }
    sp20 = 0.0f;
    ((KDUniformSpline *) &sp90)->GetMeasure(var_f31_955, ((u8 *) temp_r29_1799) + 0x18, KDSpline_PositionMixer);
    this->unk40 = sp90;
    this->unk48 = sp98;
    this->unk60 = (M2C_FIELD(temp_r29_1799, f32 *, 8) * var_f31_955) + (M2C_FIELD(temp_r29_1799, f32 *, 4) * (1.0f - var_f31_955));
    temp_r3_1860 = arg2->GetEnvelope(temp_r28_927->unk14);
    if (temp_r3_1860 != NULL) {
        var_f31_955 = ((KDBasicEnvelope *) temp_r3_1860)->GetValue(var_f29_1819);
    }
    sp1C = 0.0f;
    ((KDUniformSpline *) &sp80)->GetMeasure(var_f31_955, ((u8 *) temp_r29_1799) + 0x2C, KDSpline_PositionMixer);
    this->unk50 = sp80;
    this->unk58 = sp88;
    this->unk64 = M2C_FIELD(temp_r29_1799, f32 *, 0xC);
    this->unk68 = M2C_FIELD(temp_r29_1799, f32 *, 0x10);
    sp28 = 0;
    sp24 = 0.0f;
    if (KDSP_ToolsGetSplinePercent(temp_r28_927, ((u8 *) temp_r29_1799) + 0x18, (KDBasicEnvelope *) temp_r3_1860, arg1, sp28, sp24) != 0) {
        temp_r4_1897 = M2C_FIELD(temp_r29_1799, f32 **, 0x14);
        temp_r0_1898 = sp28 * 4;
        temp_f1_1900 = *(temp_r4_1897 + temp_r0_1898);
        temp_f2_1901 = M2C_FIELD((temp_r4_1897 + temp_r0_1898), f32 *, 4);
        if (temp_f1_1900 != temp_f2_1901) {
            KDMath_SmoothToAngle(temp_f1_1900, temp_f2_1901, sp24);
            var_f29_1906 = M2C_ERROR(/* Read from unset register $f1 */);
        } else {
            var_f29_1906 = temp_f2_1901;
        }
    } else {
        var_f29_1906 = *M2C_FIELD(temp_r29_1799, f32 **, 0x14);
    }
    sp1A0.SetIdentity();
    sp1A0.RotateRoll(&sp1A0, var_f29_1906);
    Matrix::SetIdentity();
    Matrix::SetLookAt(*((MKVector3 *) &this->unk40), *((MKVector3 *) &this->unk50));
    this->unk30 = (f32) M2C_FIELD(this, f64 *, 0x40);
    this->unk34 = M2C_FIELD(this, f32 *, 0x44);
    this->unk38 = (f32) M2C_FIELD(this, f64 *, 0x48);
    this->unk3C = 1.0f;
    sp1A0.Multiply(&sp1A0, (Matrix *) this);
    M2C_STRUCT_COPY((s32) (this - 4) + 4, (s32) &unksp19C + 4, 0x40);
}
#endif

void KDSP_Camera::Deinit() {
    MKHeap *temp_r3_1990;
    MKIni *temp_r3_1978;
    u32 *temp_r31_1987;

    this->unk74 = 0;
    this->unk88 = 0;
    this->unk78 = NULL;
    this->unk8C = NULL;
    this->unk84 = NULL;
    temp_r3_1978 = this->unk80;
    if (temp_r3_1978 != NULL) {
        temp_r3_1978->Deinit();
        operator delete(this->unk80);
        this->unk80 = NULL;
    }
    temp_r31_1987 = this->unk94;
    if ((u32) temp_r31_1987 != 0U) {
        temp_r3_1990 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_1990 != NULL) {
            ((MKHeap *) (temp_r3_1990->Current()))->Free(temp_r31_1987, NULL, 0);
        } else {
            free(temp_r31_1987);
        }
        this->unk94 = NULL;
    }
}

void KDSP_Camera::Init() {
    this->unk94 = NULL;
    this->unk80 = NULL;
    this->unk84 = NULL;
    this->unk7C = 0;
    this->unk74 = 0;
    this->unk78 = NULL;
    this->unk88 = 0;
    this->unk8C = NULL;
    this->unk70 = 0;
    this->unk6C = 0;
    this->unk60 = 60.0f;
    this->unk64 = 30.0f;
    this->unk68 = 200000.0f;
    M2C_FIELD(this, f32 *, 0x40) = 0.0f;
    M2C_FIELD(this, f32 *, 0x44) = 0.0f;
    M2C_FIELD(this, f32 *, 0x48) = 0.0f;
    M2C_FIELD(this, f32 *, 0x50) = 0.0f;
    M2C_FIELD(this, f32 *, 0x54) = 0.0f;
    M2C_FIELD(this, f32 *, 0x58) = 0.0f;
}
