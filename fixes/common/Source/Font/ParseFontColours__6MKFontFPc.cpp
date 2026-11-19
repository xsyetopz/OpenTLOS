extern "C" s32 strnicmp(s8 *, const char *, s32);
extern "C" f64 atof(s8 *);
void MKFont::ParseFontColours(char *arg0) {
    s8 *base = (s8 *) arg0;
    s8 *var_r31_48;
    s8 *var_r31_59;
    s8 *var_r31_80;
    s32 temp_r7_89;
    s32 temp_r4_98;
    s32 temp_r6_153;
    s32 var_r3_155;
    s32 var_ctr_156;
    s32 temp_r4_159;
    s32 temp_r6_196;
    s32 temp_r3_199;
    u8 temp_r0;

    var_r31_48 = base;
    *(s32 *) MKFont::currentColour = 0;
loop_30:
    if ((s8) (u8) *var_r31_48 != 0) {
        if (IsToken(arg0, (u32) (var_r31_48 - base)) != 0) {
            var_r31_59 = var_r31_48 + 1;
            if (strnicmp(var_r31_59, *(char **) MKFont::pColourToken, *(s32 *) MKFont::colourTokenLen) == 0) {
loop_5:
                if ((s32) (u8) *var_r31_59 == 0x20) {
                    var_r31_59 += 1;
                    goto loop_5;
                }
loop_8:
                if ((s32) (u8) *var_r31_59 != 0x3D) {
                    var_r31_59 += 1;
                    goto loop_8;
                }
                var_r31_80 = var_r31_59 + 1;
loop_11:
                if ((s32) (u8) *var_r31_80 == 0x20) {
                    var_r31_80 += 1;
                    goto loop_11;
                }
                temp_r7_89 = (s32) (var_r31_48 - base);
                *(s32 *) (*(s8 **) MKFont::fontColours + (*(s32 *) MKFont::currentColour * 0x18 + 0x10)) = temp_r7_89;
                temp_r4_98 = *(s32 *) MKFont::currentColour * 0x18;
                *(s32 *) (*(s8 **) MKFont::fontColours + (temp_r4_98 + 0x14)) = -1;
                *(f32 *) (*(s8 **) MKFont::fontColours + (*(s32 *) MKFont::currentColour * 0x18)) = (f32) atof(var_r31_80);
                do {
                    temp_r0 = (u8) *var_r31_80;
                    var_r31_80 += 1;
                } while ((s32) temp_r0 != 0x2C);
                *(f32 *) (*(s8 **) MKFont::fontColours + (*(s32 *) MKFont::currentColour * 0x18 + 4)) = (f32) atof(var_r31_80);
                do {
                    temp_r0 = (u8) *var_r31_80;
                    var_r31_80 += 1;
                } while ((s32) temp_r0 != 0x2C);
                *(f32 *) (*(s8 **) MKFont::fontColours + (*(s32 *) MKFont::currentColour * 0x18 + 8)) = (f32) atof(var_r31_80);
                do {
                    temp_r0 = (u8) *var_r31_80;
                    var_r31_80 += 1;
                } while ((s32) temp_r0 != 0x2C);
                *(f32 *) (*(s8 **) MKFont::fontColours + (*(s32 *) MKFont::currentColour * 0x18 + 0xC)) = (f32) atof(var_r31_80);
                do {
                    temp_r0 = (u8) *var_r31_80;
                    var_r31_80 += 1;
                } while ((s32) temp_r0 != 0x3E);
                temp_r6_153 = *(s32 *) MKFont::currentFont - 1;
                var_r3_155 = temp_r6_153 * 0x18;
                var_ctr_156 = temp_r6_153 + 1;
                if (temp_r6_153 >= 0) {
loop_21:
                    temp_r4_159 = var_r3_155 + 0x14;
                    if (*(s32 *) (*(s8 **) MKFont::fontColours + temp_r4_159) == -1) {
                        *(s32 *) (*(s8 **) MKFont::fontColours + temp_r4_159) = *(s32 *) (*(s8 **) MKFont::fontColours + (*(s32 *) MKFont::currentColour * 0x18 + 0x10)) - 1;
                    } else {
                        var_r3_155 -= 0x18;
                        var_ctr_156 -= 1;
                        if (var_ctr_156 != 0) {
                            goto loop_21;
                        }
                    }
                }
                strcpy((char *) var_r31_48, (const char *) var_r31_80);
            } else if (strnicmp(var_r31_59, *(char **) MKFont::pEndColourToken, *(s32 *) MKFont::endColourTokenLen) == 0) {
                do {
                    temp_r0 = (u8) *var_r31_59;
                    var_r31_59 += 1;
                } while ((s32) temp_r0 != 0x3E);
                strcpy((char *) var_r31_48, (const char *) var_r31_59);
                temp_r6_196 = (s32) (var_r31_48 - base);
                temp_r3_199 = *(s32 *) MKFont::currentColour * 0x18;
                *(s32 *) MKFont::currentColour += 1;
                *(s32 *) (*(s8 **) MKFont::fontColours + (temp_r3_199 + 0x14)) = temp_r6_196;
            } else {
                var_r31_48 = var_r31_59 + 1;
            }
        } else {
            var_r31_48 += 1;
        }
        goto loop_30;
    }
}
