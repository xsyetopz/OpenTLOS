#include "common/Source/xFont.h"
#include <m2c_macros.h>

extern u32 XFontBitmap;
extern u32 XfbWidth;
extern u16 cc;
extern s16 cc2;
extern u32 m_fbSize;
extern s32 *m_xfb;
#if 0 // DRAFT: illegal use of incomplete struct/union/class '_struct_XFcolor_0xC'
static struct _struct_XFcolor_0xC XFcolor[8] = {
    { 0xB4, 0x80, 0x80 },
    { 0xA2, 0x2C, 0x8E },
    { 0x83, 0x9C, 0x2C },
    { 0x70, 0x48, 0x3A },
    { 0x54, 0xB8, 0xC6 },
    { 0x41, 0x64, 0xD4 },
    { 0x23, 0xD4, 0x72 },
    { 0x10, 0x80, 0x80 },
};
#endif

#if 0 // DRAFT: illegal type
void XFONTputString(short *arg0, short *arg1, char *arg2, unsigned long *arg3) {
    u32 *spC;
    s8 *sp8;
    s32 temp_r14_104;
    s32 temp_r14_110;
    s32 temp_r14_116;
    s32 temp_r14_80;
    s32 temp_r14_86;
    s32 temp_r14_92;
    s32 temp_r14_98;
    s32 temp_r7_30;
    s32 var_r16_72;
    s8 *var_r8_15;
    u8 var_r12_33;
    void *temp_r9_105;
    void *temp_r9_111;
    void *temp_r9_117;
    void *temp_r9_123;
    void *temp_r9_87;
    void *temp_r9_93;
    void *temp_r9_99;
    void *var_r10_78;
    void *var_r9_31;

    var_r8_15 = (signed char *) (arg2 - 1);
    spC = arg3;
    sp8 = (signed char *) (arg2);
    temp_r7_30 = (cc & ~0xFFFF0000) | (cc << 0x10);
    var_r9_31 = ((u16) *arg0 << 5) + (((u16) *arg1 << 5) * XfbWidth) + m_xfb;
loop_1:
    var_r12_33 = M2C_FIELD(var_r8_15, u8 *, 1);
    var_r8_15 += 1;
    switch ((s32) var_r12_33) {                     /* irregular */
    case 0xC9:
        var_r12_33 = 0x60;
    default:
block_16:
        var_r16_72 = 0xA;
        var_r10_78 = (((var_r12_33 - 0x20) * 0x28) + spC) - 4;
        do {
            temp_r14_80 = M2C_FIELD(var_r10_78, s32 *, 4);
            var_r10_78 += 4;
            if (temp_r14_80 < 0) {
                M2C_FIELD(var_r9_31, s32 *, 0) = temp_r7_30;
                M2C_FIELD(var_r9_31, s32 *, 0x500) = temp_r7_30;
            }
            temp_r14_86 = temp_r14_80 * 0x10;
            temp_r9_87 = ((u8 *) var_r9_31) + 4;
            if (temp_r14_86 < 0) {
                M2C_FIELD(var_r9_31, s32 *, 4) = temp_r7_30;
                M2C_FIELD(temp_r9_87, s32 *, 0x500) = temp_r7_30;
            }
            temp_r14_92 = temp_r14_86 * 0x10;
            temp_r9_93 = ((u8 *) temp_r9_87) + 4;
            if (temp_r14_92 < 0) {
                M2C_FIELD(temp_r9_87, s32 *, 4) = temp_r7_30;
                M2C_FIELD(temp_r9_93, s32 *, 0x500) = temp_r7_30;
            }
            temp_r14_98 = temp_r14_92 * 0x10;
            temp_r9_99 = ((u8 *) temp_r9_93) + 4;
            if (temp_r14_98 < 0) {
                M2C_FIELD(temp_r9_93, s32 *, 4) = temp_r7_30;
                M2C_FIELD(temp_r9_99, s32 *, 0x500) = temp_r7_30;
            }
            temp_r14_104 = temp_r14_98 * 0x10;
            temp_r9_105 = ((u8 *) temp_r9_99) + 4;
            if (temp_r14_104 < 0) {
                M2C_FIELD(temp_r9_99, s32 *, 4) = temp_r7_30;
                M2C_FIELD(temp_r9_105, s32 *, 0x500) = temp_r7_30;
            }
            temp_r14_110 = temp_r14_104 * 0x10;
            temp_r9_111 = ((u8 *) temp_r9_105) + 4;
            if (temp_r14_110 < 0) {
                M2C_FIELD(temp_r9_105, s32 *, 4) = temp_r7_30;
                M2C_FIELD(temp_r9_111, s32 *, 0x500) = temp_r7_30;
            }
            temp_r14_116 = temp_r14_110 * 0x10;
            temp_r9_117 = ((u8 *) temp_r9_111) + 4;
            if (temp_r14_116 < 0) {
                M2C_FIELD(temp_r9_111, s32 *, 4) = temp_r7_30;
                M2C_FIELD(temp_r9_117, s32 *, 0x500) = temp_r7_30;
            }
            temp_r9_123 = ((u8 *) temp_r9_117) + 4;
            if ((temp_r14_116 * 0x10) < 0) {
                M2C_FIELD(temp_r9_117, s32 *, 4) = temp_r7_30;
                M2C_FIELD(temp_r9_123, s32 *, 0x500) = temp_r7_30;
            }
            var_r16_72 -= 1;
            var_r9_31 = ((u8 *) temp_r9_123) + 0x9E4;
        } while (var_r16_72 != 0);
        var_r9_31 -= 0x63E0;
        goto loop_1;
    case 0xE0:
        var_r12_33 = 0x61;
        goto block_16;
    case 0xE1:
        var_r12_33 = 0x62;
        goto block_16;
    case 0xE9:
        var_r12_33 = 0x63;
        goto block_16;
    case 0xE8:
        var_r12_33 = 0x64;
        goto block_16;
    case 0xF3:
        var_r12_33 = 0x65;
        goto block_16;
    case 0xF6:
        var_r12_33 = 0x66;
        goto block_16;
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void XFONTClearScreen(unsigned long arg0) {
    s32 *var_r7_147;
    s32 temp_r6_150;
    struct _struct_XFcolor_0xC *temp_r3_149;

    var_r7_147 = m_xfb;
    temp_r3_149 = (_struct_XFcolor_0xC *) (&XFcolor[arg0]);
    temp_r6_150 = XFcolor[arg0].unk0;
loop_2:
    if (var_r7_147 < (void *) (m_xfb + m_fbSize)) {
        *var_r7_147 = (temp_r6_150 << 0x18) + ((temp_r3_149->unk4 << 0x10) + (temp_r6_150 << 8) + temp_r3_149->unk8);
        var_r7_147 += 4;
        goto loop_2;
    }
    DCFlushRange(m_xfb, m_fbSize);
}
#endif

#if 0 // DRAFT: expression syntax error
void XFONTSetFgColor(unsigned long arg0) {
    s32 temp_r5_185;
    struct _struct_XFcolor_0xC *temp_r4_182;

    temp_r4_182 = (_struct_XFcolor_0xC *) (&XFcolor[arg0]);
    temp_r5_185 = XFcolor[arg0].unk0 << 8;
    cc = temp_r5_185 + temp_r4_182->unk4;
    cc2 = temp_r5_185 + temp_r4_182->unk8;
}
#endif

void XFONTPrintf(short arg0, short arg1, char *arg2, ...) {
    va_list args;
    char buf[0x104];
    s16 x;
    s16 y;

    x = arg0;
    y = arg1;
    va_start(args, arg2);
    vsprintf(buf, arg2, args);
    va_end(args);
    XFONTputString(&x, &y, buf, &XFontBitmap);
}

void XFONTSetFrameBuffer(void *arg0) {
    m_xfb = (s32 *) arg0;
}

void XFONTInit(unsigned long arg0, unsigned long arg1) {
    XfbWidth = arg0;
    m_fbSize = arg1;
}
