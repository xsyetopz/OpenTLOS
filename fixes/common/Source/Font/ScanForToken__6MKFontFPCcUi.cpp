extern "C" s32 strnicmp(s8 *, const char *, s32);
extern "C" s32 atoi(s8 *);
s32 MKFont::ScanForToken(const char *arg0, unsigned int arg1) {
    s8 spB[0x20];
    s8 spA[2];
    s8 *temp_r5_230;
    s8 *temp_r30_284;
    s8 *temp_r4_267;
    s8 *var_r3_296;
    s8 *var_r3_306;
    s8 *temp_r5_445;
    s8 *temp_r4_448;
    s8 *temp_r7_364;
    s8 *temp_r8_368;
    s8 *temp_r3_395;
    s8 *temp_r3_504;
    s8 *temp_r7_473;
    s8 *temp_r8_477;
    u8 temp_r3_234;
    s32 temp_r0_255;
    s32 temp_r7_257;
    s32 temp_r3_258;
    s32 temp_r31_293;
    s32 var_r31_295;
    s32 var_r30_305;
    s32 temp_r28_333;
    s32 var_r4_349;
    s32 var_r0_369;
    s32 temp_r5_360;
    s32 temp_r9_361;
    s32 var_r3_363;
    s32 var_ctr_365;
    s32 temp_r5_432;
    s32 temp_r4_439;
    s32 var_r4_458;
    s32 temp_r5_469;
    s32 temp_r9_470;
    s32 var_r3_472;
    s32 var_ctr_474;
    s32 var_r0_478;
    s32 temp_r3_515;

    temp_r5_230 = (s8 *) arg0 + arg1;
    if ((s32) (u8) *temp_r5_230 == 0x3C) {
        temp_r3_234 = (u8) temp_r5_230[1];
        if (((s8) temp_r3_234 != 0) && ((s8) temp_r3_234 != 0x3C) && ((arg1 == 0) || ((s32) (u8) temp_r5_230[-1] != 0x3C))) {
            if (strnicmp(temp_r5_230 + 1, *(char **) MKFont::pEndToken, *(s32 *) MKFont::endTokenLen) == 0) {
                temp_r0_255 = *(s32 *) MKFont::currentFont + 1;
                temp_r7_257 = temp_r0_255 * 0x14;
                temp_r3_258 = *(s32 *) MKFont::endTokenLen + 2;
                *(s32 *) MKFont::currentFont = temp_r0_255;
                *(s32 *) (*(s8 **) MKFont::currentFontStack + temp_r7_257) = *(s32 *) (*(s8 **) MKFont::currentFontStack + temp_r7_257 - 0x28);
                temp_r4_267 = *(s8 **) MKFont::currentFontStack + *(s32 *) MKFont::currentFont * 0x14;
                *(s32 *) (temp_r4_267 + 4) = *(s32 *) (temp_r4_267 - 0x24);
                *(s32 *) (*(s8 **) MKFont::currentFontStack + *(s32 *) MKFont::currentFont * 0x14 - 8) = (s32) (arg1 - 1);
                *(s32 *) (*(s8 **) MKFont::currentFontStack + *(s32 *) MKFont::currentFont * 0x14 + 8) = (s32) (arg1 + temp_r3_258);
                return temp_r3_258;
            }
            temp_r30_284 = temp_r5_230 + 1;
            if (strnicmp(temp_r30_284, *(char **) MKFont::pStartToken, *(s32 *) MKFont::startTokenLen) == 0) {
                temp_r31_293 = arg1 + *(s32 *) MKFont::startTokenLen;
                *(s32 *) MKFont::currentFont += 1;
                var_r31_295 = temp_r31_293 + 1;
                var_r3_296 = (s8 *) arg0 + var_r31_295;
loop_10:
                if ((s32) (u8) *var_r3_296 != 0x3A) {
                    var_r31_295 += 1;
                    var_r3_296 += 1;
                    goto loop_10;
                }
                var_r30_305 = var_r31_295 + 1;
                var_r3_306 = (s8 *) arg0 + var_r30_305;
loop_13:
                if ((s32) (u8) *var_r3_306 != 0x3E) {
                    var_r30_305 += 1;
                    var_r3_306 += 1;
                    goto loop_13;
                }
                strncpy((char *) (spB + 1), (const char *) ((s8 *) arg0 + (arg1 + *(s32 *) MKFont::startTokenLen + 1)), (u32) (((var_r31_295 - *(s32 *) MKFont::startTokenLen) - arg1) - 1));
                spB[(var_r31_295 - *(s32 *) MKFont::startTokenLen) - arg1] = 0;
                temp_r28_333 = var_r30_305 - var_r31_295;
                *(void **) (*(s8 **) MKFont::currentFontStack + *(s32 *) MKFont::currentFont * 0x14) = ((MKFont *) (spB + 1))->Find((const char *) spB);
                strncpy((char *) (spB + 1), (const char *) ((s8 *) arg0 + var_r31_295 + 1), (u32) (temp_r28_333 - 1));
                spB[temp_r28_333] = 0;
                var_r4_349 = 0;
                *(s32 *) (*(s8 **) MKFont::currentFontStack + *(s32 *) MKFont::currentFont * 0x14 + 4) = atoi(spB + 1);
                *(s32 *) (*(s8 **) MKFont::currentFontStack + *(s32 *) MKFont::currentFont * 0x14 + 0x10) = -1;
                temp_r5_360 = *(s32 *) MKFont::currentFont - 1;
                temp_r9_361 = *(s32 *) MKFont::currentFont * 0x14;
                var_r3_363 = temp_r5_360 * 0x14;
                temp_r7_364 = *(s8 **) MKFont::currentFontStack + temp_r9_361;
                var_ctr_365 = temp_r5_360 + 1;
                if (temp_r5_360 >= 0) {
loop_15:
                    temp_r8_368 = *(s8 **) MKFont::currentFontStack + var_r3_363;
                    var_r0_369 = *(s32 *) (temp_r8_368 + 0x10);
                    if (var_r4_349 > var_r0_369) {
                        var_r0_369 = var_r4_349;
                    }
                    var_r4_349 = var_r0_369;
                    if ((*(u32 *) temp_r8_368 == *(u32 *) temp_r7_364) && (*(u32 *) (temp_r8_368 + 4) == *(u32 *) (temp_r7_364 + 4))) {
                        *(s32 *) (temp_r7_364 + 0x10) = *(s32 *) (*(s8 **) MKFont::currentFontStack + var_r3_363 + 0x10);
                    } else {
                        var_r3_363 -= 0x14;
                        var_ctr_365 -= 1;
                        if (var_ctr_365 != 0) {
                            goto loop_15;
                        }
                    }
                }
                temp_r3_395 = *(s8 **) MKFont::currentFontStack + *(s32 *) MKFont::currentFont * 0x14;
                if (*(s32 *) (temp_r3_395 + 0x10) == -1) {
                    *(s32 *) (temp_r3_395 + 0x10) = var_r4_349 + 1;
                }
                *(s32 *) (*(s8 **) MKFont::currentFontStack + *(s32 *) MKFont::currentFont * 0x14 - 8) = (s32) (arg1 != 0 ? arg1 - 1 : 0);
                *(s32 *) (*(s8 **) MKFont::currentFontStack + *(s32 *) MKFont::currentFont * 0x14 + 8) = var_r30_305 + 1;
                return (var_r30_305 - arg1) + 1;
            }
            if (strnicmp(temp_r30_284, *(char **) MKFont::pPageToken, *(s32 *) MKFont::pageTokenLen) == 0) {
                if (arg1 != 0) {
                    temp_r5_432 = *(s32 *) MKFont::currentFont + 1;
                    *(s32 *) MKFont::currentFont = temp_r5_432;
                    *(s32 *) (*(s8 **) MKFont::currentFontStack + temp_r5_432 * 0x14 - 8) = (s32) (arg1 - 1);
                    temp_r4_439 = *(s32 *) MKFont::currentFont * 0x14;
                    *(s32 *) (*(s8 **) MKFont::currentFontStack + temp_r4_439) = *(s32 *) (*(s8 **) MKFont::currentFontStack + temp_r4_439 - 0x14);
                }
                temp_r5_445 = temp_r5_230;
                temp_r4_448 = temp_r5_445 + *(s32 *) MKFont::pageTokenLen;
                spA[1] = 0;
                spA[0] = temp_r4_448[1];
                var_r4_458 = -1;
                *(s32 *) (*(s8 **) MKFont::currentFontStack + *(s32 *) MKFont::currentFont * 0x14 + 4) = atoi(spA);
                *(s32 *) (*(s8 **) MKFont::currentFontStack + *(s32 *) MKFont::currentFont * 0x14 + 0x10) = -1;
                if (arg1 != 0) {
                    temp_r5_469 = *(s32 *) MKFont::currentFont - 1;
                    temp_r9_470 = *(s32 *) MKFont::currentFont * 0x14;
                    var_r3_472 = temp_r5_469 * 0x14;
                    temp_r7_473 = *(s8 **) MKFont::currentFontStack + temp_r9_470;
                    var_ctr_474 = temp_r5_469 + 1;
                    if (temp_r5_469 >= 0) {
loop_29:
                        temp_r8_477 = *(s8 **) MKFont::currentFontStack + var_r3_472;
                        var_r0_478 = *(s32 *) (temp_r8_477 + 0x10);
                        if (var_r4_458 > var_r0_478) {
                            var_r0_478 = var_r4_458;
                        }
                        var_r4_458 = var_r0_478;
                        if ((*(u32 *) temp_r8_477 == *(u32 *) temp_r7_473) && (*(u32 *) (temp_r8_477 + 4) == *(u32 *) (temp_r7_473 + 4))) {
                            *(s32 *) (temp_r7_473 + 0x10) = *(s32 *) (*(s8 **) MKFont::currentFontStack + var_r3_472 + 0x10);
                        } else {
                            var_r3_472 -= 0x14;
                            var_ctr_474 -= 1;
                            if (var_ctr_474 != 0) {
                                goto loop_29;
                            }
                        }
                    }
                }
                temp_r3_504 = *(s8 **) MKFont::currentFontStack + *(s32 *) MKFont::currentFont * 0x14;
                if (*(s32 *) (temp_r3_504 + 0x10) == -1) {
                    *(s32 *) (temp_r3_504 + 0x10) = var_r4_458 + 1;
                }
                temp_r3_515 = *(s32 *) MKFont::pageTokenLen + 3;
                *(s32 *) (*(s8 **) MKFont::currentFontStack + *(s32 *) MKFont::currentFont * 0x14 + 8) = arg1 + temp_r3_515;
                return temp_r3_515;
            }
            return 1;
        }
    }
    return 1;
}
