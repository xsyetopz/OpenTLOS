#ifndef SPYRO_SOURCE_MENUITEM_H
#define SPYRO_SOURCE_MENUITEM_H

#include <dolphin/types.h>

class MenuItem;

class MenuItem {
public:
    u8 Enabled(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

inline u8 MenuItem::Enabled() {
    MenuItem *var_r24_139;
    s32 var_r3_165;
    s32 var_r3_196;
    s32 var_r3_227;
    s32 var_r3_258;
    u8 temp_r0_145;
    u8 var_r23_140;
    u8 var_r25_136;
    u8 var_r29_127;
    u8 var_r30_132;
    void *temp_r3_154;
    void *temp_r3_185;
    void *temp_r3_216;
    void *temp_r3_247;
    void *var_r26_135;
    void *var_r28_128;
    void *var_r31_131;
    void *var_r4_157;
    void *var_r4_188;
    void *var_r4_219;
    void *var_r4_250;

    var_r29_127 = 0;
    var_r28_128 = M2C_FIELD(this, void **, 0x34);
loop_38:
    if ((var_r28_128 != NULL) && (var_r29_127 == 0)) {
        var_r31_131 = M2C_FIELD(var_r28_128, void **, 0x34);
        var_r30_132 = 0;
loop_27:
        if ((var_r31_131 != NULL) && (var_r30_132 == 0)) {
            var_r26_135 = M2C_FIELD(var_r31_131, void **, 0x34);
            var_r25_136 = 0;
loop_16:
            if ((var_r26_135 != NULL) && (var_r25_136 == 0)) {
                var_r24_139 = M2C_FIELD(var_r26_135, MenuItem **, 0x34);
                var_r23_140 = 0;
loop_5:
                if ((var_r24_139 != NULL) && (var_r23_140 == 0)) {
                    temp_r0_145 = var_r23_140 | var_r24_139->Enabled();
                    var_r24_139 = M2C_FIELD(var_r24_139, MenuItem **, 0x30);
                    var_r23_140 = temp_r0_145;
                    goto loop_5;
                }
                temp_r3_154 = M2C_FIELD(var_r26_135, void **, 0x2C);
                if (temp_r3_154 != NULL) {
                    var_r4_157 = M2C_FIELD(temp_r3_154, void **, 4);
                } else {
                    var_r4_157 = M2C_FIELD(var_r26_135, void **, 0x28);
                }
                if (var_r4_157 != NULL) {
                    var_r3_165 = 0;
                    if (((u8) M2C_FIELD(var_r4_157, u8 *, 0x18) != 0) && ((u8) M2C_FIELD(var_r4_157, u8 *, 0x1A) == 0)) {
                        var_r3_165 = 1;
                    }
                    var_r23_140 |= var_r3_165;
                }
                var_r26_135 = M2C_FIELD(var_r26_135, void **, 0x30);
                var_r25_136 |= var_r23_140;
                goto loop_16;
            }
            temp_r3_185 = M2C_FIELD(var_r31_131, void **, 0x2C);
            if (temp_r3_185 != NULL) {
                var_r4_188 = M2C_FIELD(temp_r3_185, void **, 4);
            } else {
                var_r4_188 = M2C_FIELD(var_r31_131, void **, 0x28);
            }
            if (var_r4_188 != NULL) {
                var_r3_196 = 0;
                if (((u8) M2C_FIELD(var_r4_188, u8 *, 0x18) != 0) && ((u8) M2C_FIELD(var_r4_188, u8 *, 0x1A) == 0)) {
                    var_r3_196 = 1;
                }
                var_r25_136 |= var_r3_196;
            }
            var_r31_131 = M2C_FIELD(var_r31_131, void **, 0x30);
            var_r30_132 |= var_r25_136;
            goto loop_27;
        }
        temp_r3_216 = M2C_FIELD(var_r28_128, void **, 0x2C);
        if (temp_r3_216 != NULL) {
            var_r4_219 = M2C_FIELD(temp_r3_216, void **, 4);
        } else {
            var_r4_219 = M2C_FIELD(var_r28_128, void **, 0x28);
        }
        if (var_r4_219 != NULL) {
            var_r3_227 = 0;
            if (((u8) M2C_FIELD(var_r4_219, u8 *, 0x18) != 0) && ((u8) M2C_FIELD(var_r4_219, u8 *, 0x1A) == 0)) {
                var_r3_227 = 1;
            }
            var_r30_132 |= var_r3_227;
        }
        var_r28_128 = M2C_FIELD(var_r28_128, void **, 0x30);
        var_r29_127 |= var_r30_132;
        goto loop_38;
    }
    temp_r3_247 = M2C_FIELD(this, void **, 0x2C);
    if (temp_r3_247 != NULL) {
        var_r4_250 = M2C_FIELD(temp_r3_247, void **, 4);
    } else {
        var_r4_250 = M2C_FIELD(this, void **, 0x28);
    }
    if (var_r4_250 != NULL) {
        var_r3_258 = 0;
        if (((u8) M2C_FIELD(var_r4_250, u8 *, 0x18) != 0) && ((u8) M2C_FIELD(var_r4_250, u8 *, 0x1A) == 0)) {
            var_r3_258 = 1;
        }
        var_r29_127 |= var_r3_258;
    }
    return var_r29_127;
}

#endif  // SPYRO_SOURCE_MENUITEM_H
