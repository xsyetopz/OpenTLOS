#include "common/Source/MKWidgetsInternal.h"
#include "common/Source/MKCommonDialogs.h"
#include "common/Source/MKFont.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKMetadata.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/MKView.h"
#include "common/Source/MKWidgets.h"
#include "common/Source/Matrix.h"
#include "dolphin/gx.h"
#include "common/Source/MKInput.h"
#include "common/Source/Str.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "common/gc/MKView_GC.h"
#include <m2c_macros.h>

f64 atof(f32);                                      /* extern */
f64 fmod(f32, f64, f32);                            /* extern */
M2C_UNK free(s8 *);                                 /* extern */
s8 *malloc(u32);                                    /* extern */
M2C_UNK strcat(u32);                                /* extern */
s32 stricmp(s8 *, s32);                             /* extern */
u32 strrchr(s8 *, M2C_UNK);                         /* extern */
extern u8 cursorVisible;
extern f32 gApplicationTime;
extern u8 gClipboardBuffer;
extern ColorEditor gColorEditor;
extern MKWidgetContextMenu gContextMenu;
extern M2C_UNK gDisplay;
extern MaterialEditor gMaterialEditor;
extern s32 gWidgetCursor;
extern u8 gWidgetDebug;
extern f32 gWidgetOrthoHeight;
extern f32 gWidgetOrthoWidth;
extern s8 *gpDebugFont;
#if 0 // DRAFT: identifier 'pDescriptorList' redeclared
extern MKWidgetDescriptor *pDescriptorList;
#endif
extern void *pHookEntryRoot;
extern MKWidgetScissorRect *pScissorRectStack;
extern MKMaterial *pWidgetBlank;
extern f32 timestamp;
#if 0 // DRAFT: identifier 'gMKWidgetMetrics' redeclared
static M2C_UNK gMKWidgetMetrics;                    /* unable to generate initializer: unknown type */
static MKVector3 clickPos = { 0.0f, 0.0f, 0.0f, 0.0f };
#endif
static MKVector3 startPos;
#if 0 // DRAFT: identifier 'gShowCursor' redeclared
static u8 gShowCursor = 1;
#endif
#if 0 // DRAFT: identifier 'MKWidgetIdentityAttributes' redeclared
static M2C_UNK *MKWidgetIdentityAttributes = &gIdentityAttributes;
#endif

static s32 lit_2215 = 0;
static s32 lit_2336 = -1;
static s32 lit_2338 = 0;
static s32 lit_2350 = 1;
static s32 lit_2883 = 0;

static s32 lit_3214 = 0x10;
static s32 lit_3216 = 2;
#if 0 // DRAFT: declaration syntax error
static M2C_UNK gIdentityAttributes;                 /* unable to generate initializer: unknown type; const */

static s8 .L_8036F1BF[0x31] = {
    0x4D,
    0x4B,
    0x57,
    0x69,
    0x64,
    0x67,
    0x65,
    0x74,
    0x54,
    0x65,
    0x78,
    0x74,
    0x42,
    0x6F,
    0x78,
    0,
    0x4D,
    0x4B,
    0x57,
    0x69,
    0x64,
    0x67,
    0x65,
    0x74,
    0x56,
    0x65,
    0x63,
    0x74,
    0x6F,
    0x72,
    0,
    0x4D,
    0x4B,
    0x57,
    0x69,
    0x64,
    0x67,
    0x65,
    0x74,
    0x53,
    0x63,
    0x72,
    0x6F,
    0x6C,
    0x6C,
    0x42,
    0x61,
    0x72,
    0,
}; /* const */
static s8 .L_8036F296[0xE4] = {
    0x4D,
    0x4B,
    0x57,
    0x69,
    0x64,
    0x67,
    0x65,
    0x74,
    0x53,
    0x79,
    0x73,
    0x74,
    0x65,
    0x6D,
    0,
    0x25,
    0x67,
    0,
    0x2D,
    0,
    0x2B,
    0,
    0x43,
    0x6F,
    0x6D,
    0x62,
    0x6F,
    0x4C,
    0x69,
    0x73,
    0x74,
    0,
    0x56,
    0,
    0x43,
    0x3A,
    0x5C,
    0x62,
    0x6F,
    0x62,
    0,
    0x62,
    0x6F,
    0x62,
    0,
    0x53,
    0x61,
    0x76,
    0x65,
    0x20,
    0x48,
    0x65,
    0x69,
    0x72,
    0x61,
    0x72,
    0x63,
    0x68,
    0x79,
    0,
    0x49,
    0x6E,
    0x73,
    0x65,
    0x72,
    0x74,
    0x20,
    0x48,
    0x65,
    0x69,
    0x72,
    0x61,
    0x72,
    0x63,
    0x68,
    0x79,
    0,
    0x50,
    0x72,
    0x6F,
    0x70,
    0x65,
    0x72,
    0x74,
    0x69,
    0x65,
    0x73,
    0,
    0x46,
    0x72,
    0x61,
    0x6D,
    0x65,
    0,
    0x42,
    0x75,
    0x74,
    0x74,
    0x6F,
    0x6E,
    0,
    0x25,
    0x63,
    0x25,
    0x73,
    0,
    0x58,
    0,
    0x55,
    0x6E,
    0x6E,
    0x61,
    0x6D,
    0x65,
    0x64,
    0,
    0,
    0x4E,
    0x6F,
    0x6E,
    0x65,
    0,
    0x25,
    0x2E,
    0x32,
    0x66,
    0x2C,
    0x20,
    0x25,
    0x2E,
    0x32,
    0x66,
    0x2C,
    0x20,
    0x25,
    0x2E,
    0x32,
    0x66,
    0,
    0x25,
    0x2E,
    0x32,
    0x66,
    0x2C,
    0x20,
    0x25,
    0x2E,
    0x32,
    0x66,
    0,
    0x25,
    0x30,
    0x32,
    0x58,
    0x2C,
    0x20,
    0x25,
    0x30,
    0x32,
    0x58,
    0,
    0x25,
    0x73,
    0x25,
    0x73,
    0,
    0x48,
    0x69,
    0x65,
    0x72,
    0x61,
    0x72,
    0x63,
    0x68,
    0x79,
    0,
    0x44,
    0x61,
    0x74,
    0x61,
    0,
    0x25,
    0x73,
    0x2E,
    0x6D,
    0x64,
    0x62,
    0,
    0x25,
    0x73,
    0x2E,
    0x6D,
    0x64,
    0x64,
    0,
    0x25,
    0x64,
    0x2E,
    0x6D,
    0x64,
    0x62,
    0,
    0x4D,
    0x4B,
    0x57,
    0x69,
    0x64,
    0x67,
    0x65,
    0x74,
    0,
    0x4D,
    0x4B,
    0x57,
    0x69,
    0x64,
    0x67,
    0x65,
    0x74,
    0x45,
    0x64,
    0x69,
    0x74,
    0x61,
    0x62,
    0x6C,
    0x65,
    0,
}; /* const */
static s8 *MKWIDGETTYPE_TEXTBOX = .L_8036F1BF;      /* const */
static s8 *MKWidgetSystemName = .L_8036F296;        /* const */

void *MKWidget_FindMessageHook(const char *arg0) {
    void *var_r31_113;

    if (arg0 == NULL) {
        return NULL;
    }
    if ((void *) pHookEntryRoot == NULL) {
        return NULL;
    }
    var_r31_113 = pHookEntryRoot;
loop_8:
    if (var_r31_113 == NULL) {
        return NULL;
    }
    if (stricmp(arg0, M2C_FIELD(var_r31_113, s32 *, 0)) == 0) {
        return var_r31_113;
    }
    var_r31_113 = M2C_FIELD(var_r31_113, void **, 8);
    goto loop_8;
}
#endif

void MKWidgetEnvelope::BuildAggregateMetaData() {

}

void MKWidgetEnvelope::BuildMetaData(int arg0) {

}

#if 0 // DRAFT: identifier 'MKWidgetEnvelope::TestPoint(MKVector3 *)' redeclared
void MKWidgetEnvelope::TestPoint(MKVector3 *arg0) {
    MKWidget::TestPoint(arg0);
}
#endif

#if 0 // DRAFT: undefined identifier 'sp80'
void MKWidgetEnvelope::Render(MKWidgetRenderContext *arg0) {
    MKWidgetBoundingVolume sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    M2C_UNK sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKWidgetBoundingVolume *var_r31_222;
    MKWidgetBoundingVolume *var_r31_294;

    MKWidget::Render(arg0);
    MKWidget_GetBoundingVolume((MKWidget *) this, &sp68);
    MKMaterial_SetWhite();
    MKPrimitive(4, 0);
    MKSetBaseColorV(arg0->unk40);
    MKSetMatrix(*((Matrix *) arg0));
    MKBegin((M2C_FIELD(this->unk4, s32 *, 0xE8) * 6) + 4);
    MKSetColorF(1.0f, 1.0f, 1.0f, 1.0f);
    MKSetPositionF(0.0f, 0.0f, 0.0f);
    MKSetPositionF(0.0f, sp68.unk14, 0.0f);
    MKSetPositionF(sp68.unk10, 0.0f, 0.0f);
    MKSetPositionV(*((MKVector3 *) &sp68.unk10));
    sp58 = (f64) sp68.unk10;
    sp60 = sp80;
    MKSetColorF(0.0f, 0.0f, 0.0f, 1.0f);
    var_r31_222 = NULL;
loop_2:
    if (var_r31_222 < (s32) M2C_FIELD(this->unk4, s32 *, 0xE8)) {
        MKSetPositionV(*((MKVector3 *) &sp58));
        MKWidgetEnvelope_GetEnvelopePos((MKWidgetEnvelope *) &sp38, (s32) this, var_r31_222);
        sp48 = sp38;
        sp50 = sp40;
        MKSetPositionF((f32) sp48 - 4.0f, unksp4C, 0.0f);
        MKSetPositionF((f32) sp48 - 4.0f, unksp4C, 0.0f);
        MKSetPositionF((f32) sp48, 4.0f + unksp4C, 0.0f);
        MKSetPositionF((f32) sp48, unksp4C - 4.0f, 0.0f);
        sp10 = 0.0f;
        sp8 = 4.0f + (f32) sp48;
        spC = unksp4C;
        sp30 = (f64) sp10;
        sp28 = (f64) sp8;
        sp58 = (f64) sp8;
        sp60 = (f64) sp10;
        MKSetPositionV(*((MKVector3 *) &sp58));
        var_r31_222 += 1;
        goto loop_2;
    }
    MKEnd();
    MKEndPrimitive();
    MKPrimitive(2, 0);
    MKSetBaseColorV(arg0->unk40);
    MKSetMatrix(*((Matrix *) arg0));
    MKBegin(M2C_FIELD(this->unk4, s32 *, 0xE8));
    MKSetColorF(0.0f, 0.0f, 0.0f, 1.0f);
    var_r31_294 = NULL;
loop_5:
    if (var_r31_294 < (s32) M2C_FIELD(this->unk4, s32 *, 0xE8)) {
        MKWidgetEnvelope_GetEnvelopePos((MKWidgetEnvelope *) &sp18, (s32) this, var_r31_294);
        MKSetPositionV(*((MKVector3 *) &sp18));
        var_r31_294 += 1;
        goto loop_5;
    }
    MKEnd();
    MKEndPrimitive();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
s32 MKWidgetEnvelope::MessageHandler(unsigned int arg0, unsigned int arg1) {
    MKWidgetBoundingVolume sp110;
    MKWidgetBoundingVolume spF0;
    MKVector3 spE0;
    s32 spDC;
    s32 spD8;
    s16 spD6;
    s16 spD4;
    MKWidgetEnvelope *spD0;
    MKVector3 spC0;
    s32 spBC;
    s32 spB8;
    s16 spB6;
    s16 spB4;
    MKWidgetEnvelope *spB0;
    f64 spA8;
    f64 spA0;
    M2C_UNK sp90;
    f64 sp88;
    f64 sp80;
    M2C_UNK sp70;
    f64 sp68;
    f64 sp60;
    M2C_UNK sp50;
    f32 sp48;
    f32 sp38;
    f32 sp28;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKWidgetBoundingVolume *var_r30_372;
    MKWidgetBoundingVolume *var_r30_591;
    MKWidgetBoundingVolume *var_r31_371;
    MKWidgetBoundingVolume *var_r31_592;
    MKWidgetBoundingVolume *var_r7_701;
    f32 var_f0_777;
    f32 var_f1_786;
    f32 var_f2_791;
    f32 var_f31_368;
    f32 var_f31_588;
    f32 var_f4_399;
    f32 var_f4_619;
    f64 temp_f1_402;
    f64 temp_f1_408;
    f64 temp_f1_412;
    f64 temp_f1_622;
    f64 temp_f1_628;
    f64 temp_f1_632;
    s32 temp_r0_492;
    s32 temp_r3_431;
    s32 temp_r3_651;
    s32 temp_r3_693;
    s32 temp_r3_880;
    s32 temp_r4_473;
    s32 temp_r4_515;
    s32 temp_r4_708;
    s32 temp_r4_770;
    s32 temp_r4_866;
    s32 temp_r5_491;
    s32 temp_r9_527;
    s32 var_ctr_493;
    s32 var_ctr_507;
    s32 var_r0_441;
    s32 var_r0_661;
    s32 var_r0_853;
    s32 var_r3_489;
    s32 var_r3_506;
    s32 var_r3_703;
    s32 var_r3_847;
    s32 var_r6_488;
    s32 var_r7_505;
    s8 **temp_r0_514;
    s8 **temp_r3_472;
    s8 **temp_r4_487;
    s8 **temp_r4_692;
    s8 **temp_r4_879;
    s8 **temp_r5_769;
    s8 **temp_r5_865;
    s8 **temp_r6_719;
    s8 **temp_r8_547;
    void *temp_r3_874;
    void *temp_r4_517;
    void *temp_r4_712;
    void *temp_r4_870;
    void *temp_r5_518;
    void *temp_r5_711;

    switch ((s32) arg0) {                           /* switch 1; irregular */
    case 0x30:                                      /* switch 1 */
        MKWidget_GetBoundingVolume((MKWidget *) this, &sp110);
        MKWidget_GetLocalMousePos((MKWidget *) this, &spE0);
        if (arg1 == 1) {
            if ((s32) this->unk28 < 0) {
                var_f31_368 = 1e11f;
                var_r31_371 = NULL;
                var_r30_372 = (MKWidgetBoundingVolume *)-1;
loop_36:
                temp_r3_472 = this->unk4;
                temp_r4_473 = M2C_FIELD(temp_r3_472, s32 *, 0xE8);
                if (var_r31_371 < temp_r4_473) {
                    MKWidgetEnvelope_GetEnvelopePos((MKWidgetEnvelope *) &sp90, (s32) this, var_r31_371);
                    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r26, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                    spA0 = sp40;
                    sp48 = sp98 - spE0.unk8;
                    spA8 = (f64) sp48;
                    var_f4_399 = ((f32) spA8 * (f32) spA8) + (((f32) spA0 * (f32) spA0) + (unkspA4 * unkspA4));
                    if (var_f4_399 > 0.0f) {
                        temp_f1_402 = __frsqrte(var_f4_399);
                        temp_f1_408 = 0.5 * temp_f1_402 * -(((f64) var_f4_399 * (temp_f1_402 * temp_f1_402)) - 3.0);
                        temp_f1_412 = 0.5 * temp_f1_408 * -(((f64) var_f4_399 * (temp_f1_408 * temp_f1_408)) - 3.0);
                        var_f4_399 = (f32) ((f64) var_f4_399 * (0.5 * temp_f1_412 * -(((f64) var_f4_399 * (temp_f1_412 * temp_f1_412)) - 3.0)));
                    } else if (var_f4_399 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_399 = __float_nan;
                    } else {
                        spC = var_f4_399;
                        temp_r3_431 = M2C_BITWISE(s32, spC) & 0x7F800000;
                        switch (temp_r3_431) {      /* switch 2; irregular */
                        case 0x7F800000:            /* switch 2 */
                            if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                                var_r0_441 = 1;
                            } else {
                                var_r0_441 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 2 */
                            if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                                var_r0_441 = 5;
                            } else {
                                var_r0_441 = 3;
                            }
                            break;
                        default:                    /* switch 2 */
                            var_r0_441 = 4;
                            break;
                        }
                        if (var_r0_441 == 1) {
                            var_f4_399 = __float_nan;
                        }
                    }
                    if ((var_f4_399 < var_f31_368) || (var_r30_372 == (MKWidgetBoundingVolume *)-1)) {
                        var_f31_368 = var_f4_399;
                        var_r30_372 = var_r31_371;
                    }
                    var_r31_371 += 1;
                    goto loop_36;
                }
                if (var_f31_368 > 6.0f) {
                    if (temp_r4_473 < (s32) M2C_FIELD(temp_r3_472, s32 *, 0xEC)) {
                        MKWidgetEnvelope_GetEnvelopeValuesFromPoint(&sp110, &spE0, &sp1C, &sp18);
                        temp_r4_487 = this->unk4;
                        var_r6_488 = 0;
                        var_r3_489 = 0;
                        temp_r5_491 = M2C_FIELD(temp_r4_487, s32 *, 0xE8);
                        temp_r0_492 = temp_r5_491 - 1;
                        var_ctr_493 = temp_r0_492;
                        if (temp_r0_492 > 0) {
loop_40:
                            if (!(*(temp_r4_487 + (var_r3_489 + 0x6C)) > sp1C)) {
                                var_r6_488 += 1;
                                var_r3_489 += 8;
                                var_ctr_493 -= 1;
                                if (var_ctr_493 != 0) {
                                    goto loop_40;
                                }
                            }
                        }
                        var_r7_505 = temp_r5_491;
                        var_r3_506 = temp_r5_491 * 8;
                        var_ctr_507 = temp_r5_491 - var_r6_488;
                        if (temp_r5_491 > var_r6_488) {
                            do {
                                temp_r0_514 = this->unk4;
                                temp_r4_515 = ((var_r7_505 - 1) * 8) + 0x68;
                                var_r7_505 -= 1;
                                temp_r4_517 = temp_r0_514 + temp_r4_515;
                                temp_r5_518 = temp_r0_514 + (var_r3_506 + 0x68);
                                var_r3_506 -= 8;
                                M2C_FIELD(temp_r5_518, f32 *, 0) = (f32) M2C_FIELD(temp_r4_517, f32 *, 0);
                                M2C_FIELD(temp_r5_518, f32 *, 4) = (f32) M2C_FIELD(temp_r4_517, f32 *, 4);
                                var_ctr_507 -= 1;
                            } while (var_ctr_507 != 0);
                        }
                        temp_r9_527 = var_r6_488 * 8;
                        M2C_FIELD((this->unk4 + temp_r9_527), f32 *, 0x6C) = sp1C;
                        M2C_FIELD((this->unk4 + temp_r9_527), f32 *, 0x68) = sp18;
                        this->unk28 = var_r6_488;
                        this->unk30 = M2C_FIELD(&zero, f64 *, 0);
                        M2C_FIELD(this, f32 *, 0x38) = (f64) M2C_FIELD(&zero, f64 *, 8);
                        temp_r8_547 = this->unk4;
                        M2C_FIELD(temp_r8_547, s32 *, 0xE8) = (s32) (M2C_FIELD(temp_r8_547, s32 *, 0xE8) + 1);
                        spD0 = this;
                        spD4 = 1;
                        spD6 = 0;
                        spD8 = this->unk28;
                        spDC = 0;
                        MKWidget_SendMessage((MKWidget *) this, 0x39U, (u32) &spD0);
                    }
                } else {
                    this->unk28 = (s32) var_r30_372;
                    MKWidgetEnvelope_GetEnvelopePos((MKWidgetEnvelope *) &sp70, (s32) this, (MKWidgetBoundingVolume *) this->unk28);
                    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                    this->unk30 = sp20;
                    sp28 = sp78 - spE0.unk8;
                    sp80 = sp20;
                    sp88 = (f64) sp28;
                    M2C_FIELD(this, f32 *, 0x38) = (f64) sp28;
                }
                MKWidget_SetMouseFocus((MKWidget *) this);
            }
        } else if (arg1 == 2) {
            var_f31_588 = 1e11f;
            var_r30_591 = NULL;
            var_r31_592 = (MKWidgetBoundingVolume *)-1;
loop_70:
            temp_r4_692 = this->unk4;
            temp_r3_693 = M2C_FIELD(temp_r4_692, s32 *, 0xE8);
            if (var_r30_591 < temp_r3_693) {
                MKWidgetEnvelope_GetEnvelopePos((MKWidgetEnvelope *) &sp50, (s32) this, var_r30_591);
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r26, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                sp60 = sp30;
                sp38 = sp58 - spE0.unk8;
                sp68 = (f64) sp38;
                var_f4_619 = ((f32) sp68 * (f32) sp68) + (((f32) sp60 * (f32) sp60) + (unksp64 * unksp64));
                if (var_f4_619 > 0.0f) {
                    temp_f1_622 = __frsqrte(var_f4_619);
                    temp_f1_628 = 0.5 * temp_f1_622 * -(((f64) var_f4_619 * (temp_f1_622 * temp_f1_622)) - 3.0);
                    temp_f1_632 = 0.5 * temp_f1_628 * -(((f64) var_f4_619 * (temp_f1_628 * temp_f1_628)) - 3.0);
                    var_f4_619 = (f32) ((f64) var_f4_619 * (0.5 * temp_f1_632 * -(((f64) var_f4_619 * (temp_f1_632 * temp_f1_632)) - 3.0)));
                } else if (var_f4_619 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_619 = __float_nan;
                } else {
                    sp8 = var_f4_619;
                    temp_r3_651 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                    switch (temp_r3_651) {          /* switch 3; irregular */
                    case 0x7F800000:                /* switch 3 */
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_661 = 1;
                        } else {
                            var_r0_661 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 3 */
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_661 = 5;
                        } else {
                            var_r0_661 = 3;
                        }
                        break;
                    default:                        /* switch 3 */
                        var_r0_661 = 4;
                        break;
                    }
                    if (var_r0_661 == 1) {
                        var_f4_619 = __float_nan;
                    }
                }
                if ((var_f4_619 < var_f31_588) || (var_r31_592 == (MKWidgetBoundingVolume *)-1)) {
                    var_f31_588 = var_f4_619;
                    var_r31_592 = var_r30_591;
                }
                var_r30_591 += 1;
                goto loop_70;
            }
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (var_f31_588 == 6.0f) {
                var_r7_701 = var_r31_592;
                M2C_FIELD(temp_r4_692, s32 *, 0xE8) = (s32) (temp_r3_693 - 1);
                var_r3_703 = (s32) var_r31_592 * 8;
loop_74:
                temp_r6_719 = this->unk4;
                if (var_r7_701 < (s32) M2C_FIELD(temp_r6_719, s32 *, 0xE8)) {
                    temp_r4_708 = (s32) &var_r7_701->unk1 * 8;
                    var_r7_701 += 1;
                    temp_r5_711 = temp_r6_719 + (var_r3_703 + 0x68);
                    temp_r4_712 = temp_r6_719 + (temp_r4_708 + 0x68);
                    var_r3_703 += 8;
                    M2C_FIELD(temp_r5_711, f32 *, 0) = (f32) M2C_FIELD(temp_r4_712, f32 *, 0);
                    M2C_FIELD(temp_r5_711, f32 *, 4) = (f32) M2C_FIELD(temp_r4_712, f32 *, 4);
                    goto loop_74;
                }
            }
        }
block_110:
    default:                                        /* switch 1 */
        return MKWidget::MessageHandler(arg0, arg1);
    case 0x31:                                      /* switch 1 */
        if (arg1 == 1) {
            MKWidget_ReleaseMouseFocus();
            this->unk28 = -1;
        }
        goto block_110;
    case 0x2E:                                      /* switch 1 */
        if ((s32) this->unk28 > -1) {
            MKWidget_GetBoundingVolume((MKWidget *) this, &spF0);
            MKWidget_GetLocalMousePos((MKWidget *) this, &spC0);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $r27, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            spC0.unk8 += this->unk38;
            MKWidgetEnvelope_GetEnvelopeValuesFromPoint(&spF0, &spC0, &sp14, &sp10);
            if ((s32) this->unk28 == 0) {
                sp14 = 0.0f;
            }
            if ((s32) this->unk28 == (s32) (M2C_FIELD(this->unk4, s32 *, 0xE8) - 1)) {
                sp14 = 1.0f;
            }
            temp_r5_769 = this->unk4;
            temp_r4_770 = this->unk28;
            if (temp_r4_770 < (s32) (M2C_FIELD(temp_r5_769, s32 *, 0xE8) - 1)) {
                var_f0_777 = M2C_FIELD((temp_r5_769 + (temp_r4_770 * 8)), f32 *, 0x74);
            } else {
                var_f0_777 = 1.0f;
            }
            if (temp_r4_770 > 0) {
                var_f1_786 = M2C_FIELD((temp_r5_769 + (temp_r4_770 * 8)), f32 *, 0x64);
            } else {
                var_f1_786 = 0.0f;
            }
            var_f2_791 = sp14;
            if (var_f2_791 < var_f0_777) {

            } else {
                var_f2_791 = var_f0_777;
            }
            if (var_f2_791 > var_f1_786) {

            } else {
                var_f2_791 = var_f1_786;
            }
            M2C_FIELD((temp_r5_769 + (temp_r4_770 * 8)), f32 *, 0x6C) = var_f2_791;
            M2C_FIELD((this->unk4 + (this->unk28 * 8)), f32 *, 0x68) = sp10;
            spB0 = this;
            spB4 = 1;
            spB6 = 0;
            spB8 = this->unk28;
            spBC = 0;
            MKWidget_SendMessage((MKWidget *) this, 0x39U, (u32) &spB0);
        }
        goto block_110;
    case 0x64:                                      /* switch 1 */
        if (arg1 != 0) {
            *arg1 = (s32) M2C_FIELD(this->unk4, s32 *, 0xE8);
        }
        return M2C_FIELD(this->unk4, s32 *, 0xE8);
    case 0x65:                                      /* switch 1 */
        if (arg1 != 0) {
            *arg1 = (s32) (this->unk4 + 0x68);
        }
        return M2C_FIELD(this->unk4, s32 *, 0xE8);
    case 0x66:                                      /* switch 1 */
        var_r3_847 = lit_3214;
        if ((s32) arg1 < var_r3_847) {
            var_r3_847 = (s32) arg1;
        }
        var_r0_853 = lit_3216;
        if (var_r3_847 > var_r0_853) {
            var_r0_853 = var_r3_847;
        }
        M2C_FIELD(this->unk4, s32 *, 0xEC) = var_r0_853;
loop_108:
        temp_r4_879 = this->unk4;
        temp_r3_880 = M2C_FIELD(temp_r4_879, s32 *, 0xE8);
        if (temp_r3_880 > (s32) M2C_FIELD(temp_r4_879, s32 *, 0xEC)) {
            M2C_FIELD(temp_r4_879, s32 *, 0xE8) = (s32) (M2C_FIELD(temp_r4_879, s32 *, 0xE8) - 1);
            temp_r5_865 = this->unk4;
            temp_r4_866 = M2C_FIELD(temp_r5_865, s32 *, 0xE8);
            temp_r4_870 = temp_r5_865 + ((temp_r4_866 * 8) + 0x68);
            temp_r3_874 = temp_r5_865 + (((temp_r4_866 - 1) * 8) + 0x68);
            M2C_FIELD(temp_r3_874, f32 *, 0) = (f32) M2C_FIELD(temp_r4_870, f32 *, 0);
            M2C_FIELD(temp_r3_874, f32 *, 4) = (f32) M2C_FIELD(temp_r4_870, f32 *, 4);
            goto loop_108;
        }
        return temp_r3_880;
    }
}
#endif

void MKWidgetEnvelope_GetEnvelopeValuesFromPoint(MKWidgetBoundingVolume *arg0, MKVector3 *arg1, float *arg2, float *arg3) {
    f32 temp_f1_905;
    f32 temp_f1_927;
    f32 var_f0_906;
    f32 var_f0_926;
    f32 var_f1_932;

    temp_f1_905 = arg0->unk10;
    var_f0_906 = 0.0f;
    if (temp_f1_905 > 0.0f) {
        var_f0_906 = arg1->unk0 / temp_f1_905;
        if (var_f0_906 < 1.0f) {

        } else {
            var_f0_906 = 1.0f;
        }
        if (var_f0_906 > 0.0f) {

        } else {
            var_f0_906 = 0.0f;
        }
    }
    *arg2 = var_f0_906;
    var_f0_926 = 0.0f;
    temp_f1_927 = arg0->unk14;
    if (temp_f1_927 > 0.0f) {
        var_f1_932 = arg1->unk4 / temp_f1_927;
        if (var_f1_932 < 1.0f) {

        } else {
            var_f1_932 = 1.0f;
        }
        if (var_f1_932 > 0.0f) {

        } else {
            var_f1_932 = 0.0f;
        }
        var_f0_926 = 1.0f - var_f1_932;
    }
    *arg3 = var_f0_926;
}

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void MKWidgetEnvelope_GetEnvelopePos(MKWidgetEnvelope *arg0, int arg1, MKWidgetBoundingVolume *arg2) {
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f4_965;
    void *temp_r4_962;

    sp10 = 0.0f;
    temp_r4_962 = M2C_FIELD(arg1, s32 *, 4) + (((s32) arg2 * 8) + 0x68);
    temp_f4_965 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r6 */), f32 *, 0x14);
    sp8 = M2C_FIELD(temp_r4_962, f32 *, 4) * M2C_FIELD(M2C_ERROR(/* Read from unset register $r6 */), f32 *, 0x10);
    spC = -((M2C_FIELD(temp_r4_962, f32 *, 0) * temp_f4_965) - temp_f4_965);
    M2C_FIELD(arg0, f64 *, 0) = (f64) sp8;
    M2C_FIELD(arg0, f64 *, 8) = (f64) sp10;
}
#endif

#if 0 // DRAFT: undefined identifier 'zero'
MKWidgetEnvelope::MKWidgetEnvelope(MKWidgetDescriptor *arg0) {
    this->unk28 = -1;
    this->unk30 = M2C_FIELD(&zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x38) = (f64) M2C_FIELD(&zero, f64 *, 8);
    if ((u8) this->unk8 == 0) {
        memset(this->unk4 + 0x68, 0, 0x80U);
        M2C_FIELD(this->unk4, f32 *, 0x70) = 1.0f;
        M2C_FIELD(this->unk4, f32 *, 0x74) = 1.0f;
        M2C_FIELD(this->unk4, s32 *, 0xE8) = 2;
        M2C_FIELD(this->unk4, s32 *, 0xEC) = 8;
    }
    return this;
}
#endif

void MKWidgetVector::BuildAggregateMetaData() {

}

void MKWidgetVector::BuildMetaData(int arg0) {

}

#if 0 // DRAFT: illegal implicit conversion from 'double *' to
MKWidget *MKWidgetVector::TestPoint(MKVector3 *arg0) {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f64 sp10;
    f64 sp8;
    MKWidget *temp_r3_1059;
    MKWidget *temp_r3_1073;
    MKWidget *temp_r3_1087;
    MKWidget *temp_r3_1101;
    MKWidget *var_r31_1048;
    f64 temp_f1_1050;
    f64 temp_f1_1064;
    f64 temp_f1_1078;
    f64 temp_f1_1092;

    var_r31_1048 = MKWidget::TestPoint(arg0);
    if (var_r31_1048 != NULL) {
        temp_f1_1050 = M2C_FIELD(arg0, f64 *, 0);
        sp38 = temp_f1_1050;
        sp40 = M2C_FIELD(arg0, f64 *, 8);
        temp_r3_1059 = this->unk28.GetWidgetUnderPoint(&sp38, temp_f1_1050);
        if (temp_r3_1059 != NULL) {
            var_r31_1048 = temp_r3_1059;
        }
        temp_f1_1064 = M2C_FIELD(arg0, f64 *, 0);
        sp28 = temp_f1_1064;
        sp30 = M2C_FIELD(arg0, f64 *, 8);
        temp_r3_1073 = this->unk78.GetWidgetUnderPoint(&sp28, temp_f1_1064);
        if (temp_r3_1073 != NULL) {
            var_r31_1048 = temp_r3_1073;
        }
        temp_f1_1078 = M2C_FIELD(arg0, f64 *, 0);
        sp18 = temp_f1_1078;
        sp20 = M2C_FIELD(arg0, f64 *, 8);
        temp_r3_1087 = this->unkC8.GetWidgetUnderPoint(&sp18, temp_f1_1078);
        if (temp_r3_1087 != NULL) {
            var_r31_1048 = temp_r3_1087;
        }
        temp_f1_1092 = M2C_FIELD(arg0, f64 *, 0);
        sp8 = temp_f1_1092;
        sp10 = M2C_FIELD(arg0, f64 *, 8);
        temp_r3_1101 = this->unk118.GetWidgetUnderPoint(&sp8, temp_f1_1092);
        if (temp_r3_1101 != NULL) {
            var_r31_1048 = temp_r3_1101;
        }
    }
    return var_r31_1048;
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_spFC'
void MKWidgetVector::Render(MKWidgetRenderContext *arg0) {
    MKWidget::Render(arg0);
    M2C_STRUCT_COPY((s32) &arg_spFC + 4, (s32) (arg0 - 4) + 4, 0x50);
    this->unk28.Draw(&arg_sp100, &arg_spFC + 0x50);
    M2C_STRUCT_COPY((s32) &arg_spAC + 4, (s32) (arg0 - 4) + 4, 0x50);
    this->unk78.Draw(&arg_spB0, &arg_spAC + 0x50);
    M2C_STRUCT_COPY((s32) &arg_sp5C + 4, (s32) (arg0 - 4) + 4, 0x50);
    this->unkC8.Draw(&arg_sp60, &arg_sp5C + 0x50);
    M2C_STRUCT_COPY((s32) &arg_spC + 4, (s32) (arg0 - 4) + 4, 0x50);
    this->unk118.Draw(&arg_sp10, &arg_spC + 0x50);
}
#endif

#if 0 // DRAFT: undefined identifier 'zero'
s32 MKWidgetVector::MessageHandler(unsigned int arg0, unsigned int arg1) {
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;                                       /* compiler-managed */
    s32 sp44;
    s8 **sp40;
    s16 sp3E;
    s16 sp3C;
    MKWidgetVector *sp38;
    f64 sp30;
    f64 sp28;
    s32 sp24;
    s8 **sp20;
    s16 sp1E;
    s16 sp1C;
    MKWidgetVector *sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKWidget *temp_r3_1442;
    MKWidget *temp_r3_1475;
    f32 temp_f31_1267;
    f32 temp_f31_1278;
    f32 temp_r3_1515;
    s32 temp_r7_1241;
    s8 **temp_r30_1513;
    s8 **temp_r3_1308;
    s8 **temp_r3_1404;
    s8 **temp_r3_1554;
    s8 **temp_r4_1315;
    s8 **temp_r4_1346;
    s8 **temp_r7_1557;
    u8 var_r0_1316;
    u8 var_r0_1555;

    switch ((s32) arg0) {                           /* irregular */
    case 0x5:
        temp_r7_1241 = M2C_FIELD(this->unk4, s32 *, 0x78);
        sp10 = 0.0f;
        spC = M2C_FIELD(arg1, f32 *, 4);
        sp60 = (f64) sp10;
        temp_f31_1267 = -((2.0f * (f32) (temp_r7_1241 - 1)) - M2C_FIELD(arg1, f32 *, 0)) / (f32) temp_r7_1241;
        sp48 = M2C_FIELD(&zero, f64 *, 0);
        sp50 = M2C_FIELD(&zero, f64 *, 8);
        sp8 = temp_f31_1267;
        sp58 = (f64) sp8;
        MKWidget_Move(&this->unk28, *((MKVector3 *) &sp48));
        temp_f31_1278 = 2.0f + temp_f31_1267;
        sp48 = (f32) sp48 + temp_f31_1278;
        MKWidget_Move(&this->unk78, *((MKVector3 *) &sp48));
        sp48 += temp_f31_1278;
        MKWidget_Move(&this->unkC8, *((MKVector3 *) &sp48));
        sp48 += temp_f31_1278;
        MKWidget_Move(&this->unk118, *((MKVector3 *) &sp48));
        MKWidget_Resize(&this->unk28, *((MKVector3 *) &sp58));
        MKWidget_Resize(&this->unk78, *((MKVector3 *) &sp58));
        MKWidget_Resize(&this->unkC8, *((MKVector3 *) &sp58));
        MKWidget_Resize(&this->unk118, *((MKVector3 *) &sp58));
block_66:
    default:
        return MKWidget::MessageHandler(arg0, arg1);
    case 0x64:
        temp_r3_1308 = this->unk4;
        M2C_FIELD(arg1, f32 *, 0) = (f64) M2C_FIELD(temp_r3_1308, f64 *, 0x68);
        M2C_FIELD(arg1, f32 *, 8) = (f64) M2C_FIELD(temp_r3_1308, f64 *, 0x70);
        goto block_66;
    case 0x65:
        temp_r4_1315 = this->unk4;
        var_r0_1316 = 0;
        if (((f32) M2C_FIELD(temp_r4_1315, f64 *, 0x68) == M2C_FIELD(arg1, f32 *, 0)) && (M2C_FIELD(temp_r4_1315, f32 *, 0x6C) == M2C_FIELD(arg1, f32 *, 4)) && ((f32) M2C_FIELD(temp_r4_1315, f64 *, 0x70) == M2C_FIELD(arg1, f32 *, 8)) && (M2C_FIELD(temp_r4_1315, f32 *, 0x74) == M2C_FIELD(arg1, f32 *, 0xC))) {
            var_r0_1316 = 1;
        }
        if (var_r0_1316 == 0) {
            M2C_FIELD(temp_r4_1315, f64 *, 0x68) = (f64) M2C_FIELD(arg1, f32 *, 0);
            M2C_FIELD(temp_r4_1315, f64 *, 0x70) = (f64) M2C_FIELD(arg1, f32 *, 8);
            this->unk168 = 1;
            temp_r4_1346 = this->unk4;
            MKWidget_SendMessage(&this->unk28, 0x17U, Str_Printf("", temp_r4_1346, (f32) M2C_FIELD(temp_r4_1346, f64 *, 0x68)));
            MKWidget_SendMessage(&this->unk78, 0x17U, Str_Printf("", "MKWidgetContainer", M2C_FIELD(this->unk4, f32 *, 0x6C)));
            MKWidget_SendMessage(&this->unkC8, 0x17U, Str_Printf("", "MKWidgetContainer", (f32) M2C_FIELD(this->unk4, f64 *, 0x70)));
            MKWidget_SendMessage(&this->unk118, 0x17U, Str_Printf("", "MKWidgetContainer", M2C_FIELD(this->unk4, f32 *, 0x74)));
            this->unk168 = 0;
            sp38 = this;
            sp3C = 1;
            sp3E = 0;
            sp40 = this->unk4 + 0x68;
            sp44 = 0;
            MKWidget_SendMessage((MKWidget *) this, 0x39U, (u32) &sp38);
        }
        goto block_66;
    case 0x66:
        temp_r3_1404 = this->unk4;
        if ((s32) arg1 != (s32) M2C_FIELD(temp_r3_1404, s32 *, 0x78)) {
            M2C_FIELD(temp_r3_1404, s32 *, 0x78) = (s32) arg1;
            if (arg1 < 4U) {
                MKWidget_Show(&this->unk118, 0);
            } else {
                MKWidget_Show(&this->unk118, 1);
            }
            if (arg1 < 3U) {
                MKWidget_Show(&this->unkC8, 0);
            } else {
                MKWidget_Show(&this->unkC8, 1);
            }
            MKWidget_SendMessage((MKWidget *) this, 5U, (u32) (this->unk4 + 0x38));
        }
        goto block_66;
    case 0x40:
        temp_r3_1442 = MKWidget_GetFocus();
        if (temp_r3_1442 == &this->unk28) {
            MKWidget_SetFocus(&this->unk78);
            return 0;
        }
        if ((temp_r3_1442 == &this->unk78) && ((s32) M2C_FIELD(this->unk4, s32 *, 0x78) > 2)) {
            MKWidget_SetFocus(&this->unkC8);
            return 0;
        }
        if ((temp_r3_1442 == &this->unkC8) && ((s32) M2C_FIELD(this->unk4, s32 *, 0x78) > 3)) {
            MKWidget_SetFocus(&this->unk118);
            return 0;
        }
        goto block_66;
    case 0x41:
        temp_r3_1475 = MKWidget_GetFocus();
        if (temp_r3_1475 == &this->unk118) {
            MKWidget_SetFocus(&this->unkC8);
            return 0;
        }
        if (temp_r3_1475 == &this->unkC8) {
            MKWidget_SetFocus(&this->unk78);
            return 0;
        }
        if (temp_r3_1475 == &this->unk78) {
            MKWidget_SetFocus(&this->unk28);
            return 0;
        }
        goto block_66;
    case 0x39:
        if ((M2C_BITWISE(u16, M2C_FIELD(arg1, f32 *, 4)) == 1) && (strcmp(*M2C_FIELD(M2C_FIELD(arg1, f32 *, 0), s8 ***, 0xC), MKWIDGETTYPE_TEXTBOX) == 0)) {
            if ((u8) this->unk168 == 0) {
                temp_r30_1513 = this->unk4;
                temp_r3_1515 = M2C_FIELD(arg1, f32 *, 0);
                sp28 = M2C_FIELD(temp_r30_1513, f64 *, 0x68);
                sp30 = M2C_FIELD(temp_r30_1513, f64 *, 0x70);
                if (M2C_BITWISE(u32, temp_r3_1515) == &this->unk28) {
                    M2C_FIELD(temp_r30_1513, f64 *, 0x68) = (f32) atof(M2C_FIELD(arg1, f32 *, 8));
                } else if (M2C_BITWISE(u32, temp_r3_1515) == &this->unk78) {
                    M2C_FIELD(temp_r30_1513, f32 *, 0x6C) = (f32) atof(M2C_FIELD(arg1, f32 *, 8));
                } else if (M2C_BITWISE(u32, temp_r3_1515) == &this->unkC8) {
                    M2C_FIELD(temp_r30_1513, f64 *, 0x70) = (f32) atof(M2C_FIELD(arg1, f32 *, 8));
                } else if (M2C_BITWISE(u32, temp_r3_1515) == &this->unk118) {
                    M2C_FIELD(temp_r30_1513, f32 *, 0x74) = (f32) atof(M2C_FIELD(arg1, f32 *, 8));
                }
                temp_r3_1554 = this->unk4;
                var_r0_1555 = 0;
                temp_r7_1557 = temp_r3_1554 + 0x68;
                if (((f32) M2C_FIELD(temp_r3_1554, f64 *, 0x68) == (f32) sp28) && (M2C_FIELD(temp_r7_1557, f32 *, 4) == unksp2C) && (M2C_FIELD(temp_r7_1557, f32 *, 8) == (f32) sp30) && (M2C_FIELD(temp_r7_1557, f32 *, 0xC) == unksp34)) {
                    var_r0_1555 = 1;
                }
                if (var_r0_1555 == 0) {
                    sp18 = this;
                    sp1C = 1;
                    sp1E = 0;
                    sp20 = temp_r7_1557;
                    sp24 = 0;
                    MKWidget_SendMessage((MKWidget *) this, 0x39U, (u32) &sp18);
                }
            }
            return 0;
        }
        goto block_66;
    case 0x67:
        return M2C_FIELD(this->unk4, s32 *, 0x78);
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
MKWidgetVector::MKWidgetVector(MKWidgetDescriptor *arg0) {
    s8 **temp_r5_1645;

    this->unk28.unk18 = (MKWidget *) this;
    this->unk78.unk18 = (MKWidget *) this;
    this->unkC8.unk18 = (MKWidget *) this;
    this->unk118.unk18 = (MKWidget *) this;
    this->unk168 = 0;
    if ((u8) this->unk8 == 0) {
        temp_r5_1645 = this->unk4;
        M2C_FIELD(temp_r5_1645, f64 *, 0x68) = (f64) M2C_FIELD(&zero, f64 *, 0);
        M2C_FIELD(temp_r5_1645, f64 *, 0x70) = (f64) M2C_FIELD(&zero, f64 *, 8);
        M2C_FIELD(this->unk4, s32 *, 0x78) = 4;
        this->unk168 = 1;
        MKWidget_EnableFlag(&this->unk28, 0x100U);
        MKWidget_SendMessage(&this->unk28, 0x66U, 0x10U);
        MKWidget_SendMessage(&this->unk28, 0x17U, Str_Printf("", "MKWidgetContainer", (f32) M2C_FIELD(this->unk4, f64 *, 0x68)));
        MKWidget_EnableFlag(&this->unk28, 0x2000U);
        MKWidget_EnableFlag(&this->unk78, 0x100U);
        MKWidget_SendMessage(&this->unk78, 0x66U, 0x10U);
        MKWidget_SendMessage(&this->unk78, 0x17U, Str_Printf("", "MKWidgetContainer", M2C_FIELD(this->unk4, f32 *, 0x6C)));
        MKWidget_EnableFlag(&this->unk78, 0x2000U);
        MKWidget_EnableFlag(&this->unkC8, 0x100U);
        MKWidget_SendMessage(&this->unkC8, 0x66U, 0x10U);
        MKWidget_SendMessage(&this->unkC8, 0x17U, Str_Printf("", "MKWidgetContainer", (f32) M2C_FIELD(this->unk4, f64 *, 0x70)));
        MKWidget_EnableFlag(&this->unkC8, 0x2000U);
        MKWidget_EnableFlag(&this->unk118, 0x100U);
        MKWidget_SendMessage(&this->unk118, 0x66U, 0x10U);
        MKWidget_SendMessage(&this->unk118, 0x17U, Str_Printf("", "MKWidgetContainer", M2C_FIELD(this->unk4, f32 *, 0x74)));
        MKWidget_EnableFlag(&this->unk118, 0x2000U);
        this->unk168 = 0;
    }
    return this;
}
#endif

void MKWidgetFoldupFrame::BuildAggregateMetaData() {

}

void MKWidgetFoldupFrame::BuildMetaData(int arg0) {

}

#if 0 // DRAFT: illegal implicit conversion from 'double *' to
MKWidget *MKWidgetFoldupFrame::TestPoint(MKVector3 *arg0) {
    f64 sp20;
    f64 sp18;
    f64 sp10;
    f64 sp8;
    MKWidget *temp_r3_1783;
    MKWidget *temp_r3_1797;
    MKWidget *var_r31_1772;
    f64 temp_f1_1774;
    f64 temp_f1_1788;

    var_r31_1772 = MKWidget::TestPoint(arg0);
    if (var_r31_1772 != NULL) {
        temp_f1_1774 = M2C_FIELD(arg0, f64 *, 0);
        sp18 = temp_f1_1774;
        sp20 = M2C_FIELD(arg0, f64 *, 8);
        temp_r3_1783 = this->unk54.GetWidgetUnderPoint(&sp18, temp_f1_1774);
        if (temp_r3_1783 != NULL) {
            var_r31_1772 = temp_r3_1783;
        }
        temp_f1_1788 = M2C_FIELD(arg0, f64 *, 0);
        sp8 = temp_f1_1788;
        sp10 = M2C_FIELD(arg0, f64 *, 8);
        temp_r3_1797 = this->unkDC.GetWidgetUnderPoint(&sp8, temp_f1_1788);
        if (temp_r3_1797 != NULL) {
            var_r31_1772 = temp_r3_1797;
        }
    }
    return var_r31_1772;
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp28'
void MKWidgetFoldupFrame::Render(MKWidgetRenderContext *arg0) {
    arg_sp28 = 0.0f;
    arg_sp20 = 0.0f;
    arg_sp48 = (f64) arg_sp28;
    arg_sp24 = -M2C_FIELD(this->unk4, f32 *, 0x80);
    arg_sp40 = (f64) arg_sp20;
    arg0->Translate((Matrix *) arg0, *((MKVector3 *) &arg_sp40));
    MKWidgetFrame::Render(arg0);
    arg_sp18 = 0.0f;
    arg_sp10 = 0.0f;
    arg_sp14 = M2C_FIELD(this->unk4, f32 *, 0x80);
    arg_sp38 = (f64) arg_sp18;
    arg_sp30 = (f64) arg_sp10;
    arg0->Translate((Matrix *) arg0, *((MKVector3 *) &arg_sp30));
    M2C_STRUCT_COPY((s32) &arg_sp9C + 4, (s32) (arg0 - 4) + 4, 0x50);
    this->unk54.Draw(&arg_spA0, &arg_sp9C + 0x50);
    M2C_STRUCT_COPY((s32) &arg_sp4C + 4, (s32) (arg0 - 4) + 4, 0x50);
    this->unkDC.Draw(&arg_sp50, &arg_sp4C + 0x50);
}
#endif

#if 0 // DRAFT: identifier 'MKWidgetFoldupFrame::MessageHandler(unsigned int, unsigned
u32 MKWidgetFoldupFrame::MessageHandler(unsigned int arg0, unsigned int arg1) {
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKWidget *temp_r3_2092;
    f32 temp_f1_2031;
    f32 temp_f3_2015;
    f32 temp_f3_2044;
    u32 temp_r3_2078;

    if ((s32) arg0 != 0x39) {
        switch ((s32) arg0) {                       /* irregular */
        case 0x6A:
            if (arg1 != 0) {
                MKWidget_SendMessage(&this->unk54, 0x64U, 1U);
                this->unk50 = (s32) arg1;
                MKWidget_Resize((MKWidget *) this, *((MKVector3 *) &this->unk40));
                MKWidget_SendMessage(&this->unk54, 0x17U, (u32) "");
            } else {
                MKWidget_SendMessage((MKWidget *) this, 0xAU, (u32) &this->unk40);
                sp88 = this->unk40;
                sp8C = 4.0f + M2C_FIELD(this->unk4, f32 *, 0x80);
                sp90 = 0.0f;
                MKWidget_Resize((MKWidget *) this, *((MKVector3 *) &sp88));
                MKWidget_SendMessage(&this->unk54, 0x17U, (u32) "");
                MKWidget_SendMessage(&this->unk54, 0x64U, 0U);
                this->unk50 = (s32) arg1;
            }
            return 0U;
        case 0x5:
            if ((s32) this->unk50 == 0) {
                this->unk40 = M2C_FIELD(arg1, f32 *, 0);
            }
            sp40 = 0.0f;
            sp38 = 0.0f;
            sp3C = -M2C_FIELD(this->unk4, f32 *, 0x80);
            sp80 = (f64) sp40;
            sp78 = (f64) sp38;
            MKWidget_Move(&this->unk54, *((MKVector3 *) &sp78));
            temp_f3_2015 = M2C_FIELD(this->unk4, f32 *, 0x80);
            sp30 = 0.0f;
            sp2C = -temp_f3_2015;
            sp28 = 2.0f + temp_f3_2015;
            sp70 = (f64) sp30;
            sp68 = (f64) sp28;
            MKWidget_Move(&this->unkDC, *((MKVector3 *) &sp68));
            temp_f1_2031 = M2C_FIELD(this->unk4, f32 *, 0x80);
            sp20 = 0.0f;
            sp18 = temp_f1_2031;
            sp1C = temp_f1_2031;
            sp60 = (f64) sp20;
            sp58 = (f64) sp18;
            MKWidget_Resize(&this->unk54, *((MKVector3 *) &sp58));
            temp_f3_2044 = M2C_FIELD(this->unk4, f32 *, 0x80);
            sp10 = 0.0f;
            spC = temp_f3_2044;
            sp50 = (f64) sp10;
            sp8 = M2C_FIELD(arg1, f32 *, 0) - (2.0f + temp_f3_2044);
            sp48 = (f64) sp8;
            MKWidget_Resize(&this->unkDC, *((MKVector3 *) &sp48));
            goto block_36;
        case 0x42:
            MKWidget_SendMessage(&this->unk54, arg0, arg1);
            return MKWidget_SendMessage(&this->unkDC, arg0, arg1);
        case 0x12:
            temp_r3_2078 = MKWidgetFrame::MessageHandler(arg0, arg1);
            M2C_FIELD(arg1, f32 *, 4) = (f32) (M2C_FIELD(arg1, f32 *, 4) + M2C_FIELD(this->unk4, f32 *, 0x80));
            M2C_FIELD(arg1, f32 *, 0x14) = (f32) (M2C_FIELD(arg1, f32 *, 0x14) - M2C_FIELD(this->unk4, f32 *, 0x80));
            return temp_r3_2078;
        case 0x6B:
            return (u32) this->unk50;
        case 0x14:
            return MKWidget_SendMessage(&this->unkDC, 0x17U, arg1);
        default:
            return MKWidget_SendMessage(&this->unkDC, arg0, arg1);
        }
    } else {
        temp_r3_2092 = &this->unk54;
        if ((M2C_BITWISE(u32, M2C_FIELD(arg1, f32 *, 0)) == temp_r3_2092) && (M2C_BITWISE(u16, M2C_FIELD(arg1, f32 *, 4)) == 6)) {
            MKWidget_SendMessage((MKWidget *) this, 0x6AU, MKWidget_SendMessage(temp_r3_2092, 0x65U, 0U));
        }
    case 0x13:
block_36:
        return MKWidgetFrame::MessageHandler(arg0, arg1);
    }
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
MKWidgetFoldupFrame::MKWidgetFoldupFrame(MKWidgetDescriptor *arg0) {
    this->unkDC.unk18 = (MKWidget *) this;
    this->unk54.unk18 = (MKWidget *) this;
    M2C_FIELD(this->unk4, f32 *, 0x80) = 15.0f;
    M2C_FIELD(this->unk4, f32 *, 0x84) = 0.0f;
    MKWidget_EnableFlag(&this->unk54, 0x400U);
    MKWidget_SendMessage(&this->unk54, 0x64U, 1U);
    MKWidget_SendMessage(&this->unk54, 0x17U, (u32) "");
    this->unk50 = 1;
    MKWidget_EnableFlag(&this->unkDC, 0x100U);
    return this;
}
#endif

void MKWidgetComboBox::BuildAggregateMetaData() {

}

void MKWidgetComboBox::BuildMetaData(int arg0) {

}

#if 0 // DRAFT: illegal implicit conversion from 'double *' to
MKWidget *MKWidgetComboBox::TestPoint(MKVector3 *arg0) {
    f64 sp20;
    f64 sp18;
    f64 sp10;
    f64 sp8;
    MKWidget *temp_r3_2314;
    MKWidget *temp_r3_2328;
    MKWidget *var_r31_2303;
    f64 temp_f1_2305;
    f64 temp_f1_2319;

    var_r31_2303 = MKWidget::TestPoint(arg0);
    if (var_r31_2303 != NULL) {
        temp_f1_2305 = M2C_FIELD(arg0, f64 *, 0);
        sp18 = temp_f1_2305;
        sp20 = M2C_FIELD(arg0, f64 *, 8);
        temp_r3_2314 = this->unk28.GetWidgetUnderPoint(&sp18, temp_f1_2305);
        if (temp_r3_2314 != NULL) {
            var_r31_2303 = temp_r3_2314;
        }
        temp_f1_2319 = M2C_FIELD(arg0, f64 *, 0);
        sp8 = temp_f1_2319;
        sp10 = M2C_FIELD(arg0, f64 *, 8);
        temp_r3_2328 = this->unkB0.GetWidgetUnderPoint(&sp8, temp_f1_2319);
        if (temp_r3_2328 != NULL) {
            var_r31_2303 = temp_r3_2328;
        }
    }
    return var_r31_2303;
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp5C'
void MKWidgetComboBox::Render(MKWidgetRenderContext *arg0) {
    MKWidget::Render(arg0);
    M2C_STRUCT_COPY((s32) &arg_sp5C + 4, (s32) (arg0 - 4) + 4, 0x50);
    this->unk28.Draw(&arg_sp60, &arg_sp5C + 0x50);
    M2C_STRUCT_COPY((s32) &arg_spC + 4, (s32) (arg0 - 4) + 4, 0x50);
    this->unkB0.Draw(&arg_sp10, &arg_spC + 0x50);
}
#endif

#if 0 // DRAFT: illegal operand 'MKWidget *'
s32 MKWidgetComboBox::ListBoxHook(MKWidget *arg0, unsigned int arg1, unsigned int arg2, void *arg3) {
    switch (arg0) {                                 /* irregular */
    case 0x1F:
        if (arg1 == 0) {
            MKWidget_Show((MKWidget *) this, 0);
        }
        break;
    case 0x39:
        if (((u32) M2C_FIELD(arg1, u32 *, 0) == this) && ((u16) M2C_FIELD(arg1, u16 *, 4) == 2)) {
            MKWidget_SendMessage((MKWidget *) arg2, 0x64U, M2C_FIELD(arg1, u32 *, 8));
            MKWidget_SetFocus((MKWidget *) arg2);
        }
        break;
    }
    return 1;
}
#endif

#if 0 // DRAFT: identifier 'MKWidgetComboBox::MessageHandler(unsigned int, unsigned int)'
void MKWidgetComboBox::MessageHandler(unsigned int arg0, unsigned int arg1) {
    MKWidget *temp_r29_2450;
    MKWidget *temp_r3_2666;
    MKWidget *var_r29_2663;
    f32 temp_f0_2540;
    f32 temp_f0_2732;
    f32 temp_f0_2813;
    f32 temp_f1_2729;
    f32 temp_f1_2786;
    f32 temp_f2_2517;
    f32 temp_f3_2790;
    f32 temp_f4_2734;
    f32 temp_f4_2756;
    f32 temp_f5_2752;
    f32 temp_f6_2749;
    f32 var_f4_2789;
    f32 var_f4_2805;
    s32 temp_r0_2560;
    s32 temp_r31_2553;
    s32 var_r3_2558;
    s32 var_r5_2565;
    s8 **temp_r3_2719;
    s8 **temp_r3_2788;
    s8 **temp_r5_2513;
    u32 temp_r4_2699;
    temp_r29_2450 = this->unk100;
    switch ((s32) arg0) {                           /* irregular */
    case 0x1D:
    case 0x1B:
        if (arg1 & 0x100) {
            MKWidget_EnableFlag(&this->unkB0, 0x800U);
        }
    default:
block_70:
        MKWidget::MessageHandler(arg0, arg1);
        return;
    case 0x1E:
        if (arg1 & 0x100) {
            MKWidget_DisableFlag(&this->unkB0, 0x800U);
        }
        goto block_70;
    case 0x5:
        temp_r5_2513 = this->unk4;
        temp_f2_2517 = M2C_FIELD(temp_r5_2513, f32 *, 0x3C);
        arg_sp50 = 0.0f;
        arg_sp4C = temp_f2_2517;
        arg_sp48 = M2C_FIELD(temp_r5_2513, f32 *, 0x38) - temp_f2_2517;
        arg_spE0 = (f64) arg_sp50;
        arg_spD8 = (f64) arg_sp48;
        MKWidget_Move(&this->unkB0, zero);
        MKWidget_Resize(&this->unkB0, *((MKVector3 *) &arg_spD8));
        arg_spDC = 0.0f;
        MKWidget_Move(&this->unk28, *((MKVector3 *) &arg_spD8));
        temp_f0_2540 = M2C_FIELD(this->unk4, f32 *, 0x3C);
        arg_spDC = temp_f0_2540;
        arg_spD8 = temp_f0_2540;
        MKWidget_Resize(&this->unk28, *((MKVector3 *) &arg_spD8));
        goto block_70;
    case 0x35:
        temp_r31_2553 = -(s32) M2C_BITWISE(f32, M2C_FIELD(arg1, u32 *, 0));
        if ((s32) M2C_FIELD(this->unk4, u32 *, 0x68) != -1) {
            MKWidget_GetNumChildren(temp_r29_2450);
            var_r3_2558 = M2C_ERROR(/* Read from unset register $r3 */) - 1;
            temp_r0_2560 = temp_r31_2553 + M2C_FIELD(this->unk4, u32 *, 0x68);
            if (temp_r0_2560 < var_r3_2558) {
                var_r3_2558 = temp_r0_2560;
            }
            var_r5_2565 = lit_2883;
            if (var_r3_2558 > var_r5_2565) {
                var_r5_2565 = var_r3_2558;
            }
            MKWidget_SendMessage((MKWidget *) this, 0x64U, (u32) var_r5_2565);
        } else if (temp_r31_2553 > 0) {
            MKWidget_SendMessage((MKWidget *) this, 0x64U, 0U);
        }
        return;
    case 0x64:
        temp_r29_2450->GetChild((s32) arg1);
        M2C_FIELD(this->unk4, u32 *, 0x68) = arg1;
        MKWidget_SendMessage(M2C_ERROR(/* Read from unset register $r3 */), 0x13U, (u32) &arg_sp10);
        MKWidget_SendMessage(&this->unkB0, 0x17U, arg_sp10);
        arg_spC8 = this;
        arg_spCC = 2;
        arg_spCC = 0;
        arg_spD0 = arg1;
        arg_spD4 = arg_sp10;
        MKWidget_SendMessage((MKWidget *) this, 0x39U, (u32) &arg_spC8);
        return;
    case 0x66:
        MKWidget_GetNumChildren(temp_r29_2450);
        return;
    case 0x67:
        M2C_STRUCT_COPY((s32) &arg_sp12C + 4, (s32) (MKWidgetIdentityAttributes - 4) + 4, 0x58);
        arg_sp38 = 400.0f;
        arg_sp3C = 15.0f;
        arg_sp40 = 0.0f;
        arg_sp160 = (f64) arg_sp38;
        arg_sp168 = (f64) arg_sp40;
        arg_sp78 = (f64) arg_sp38;
        arg_sp80 = (f64) arg_sp40;
        MKWidget_DisableFlag(MKWidget_Create("", (s8 *) arg1, (MKWidgetAttributes *) &arg_sp130, this->unk100, NULL, NULL), 4U);
        return;
    case 0x68:
        temp_r29_2450->GetChild((s32) arg1);
        MKWidget_Destroy(M2C_ERROR(/* Read from unset register $r3 */));
        return;
    case 0x69:
        var_r29_2663 = M2C_FIELD(temp_r29_2450, MKWidget **, 0x28);
loop_49:
        if (var_r29_2663 != NULL) {
            temp_r3_2666 = var_r29_2663;
            var_r29_2663 = var_r29_2663->unk1C;
            MKWidget_Destroy(temp_r3_2666);
            goto loop_49;
        }
        return;
    case 0x17:
        if (IsFlagSet(0x100U) != 0) {
            MKWidget_SendMessage(&this->unkB0, 0x17U, arg1);
        }
        goto block_70;
    case 0x18:
        MKWidget_SendMessage(&this->unkB0, 0x18U, arg1);
        return;
    case 0x3:
        MKWidget_Destroy(temp_r29_2450);
        this->unk100 = NULL;
        goto block_70;
    case 0x39:
        temp_r4_2699 = M2C_FIELD(arg1, u32 *, 0);
        if (temp_r4_2699 == &this->unk28) {
            if ((u16) M2C_FIELD(arg1, u16 *, 4) == 6) {
                MKWidget_Show(temp_r29_2450, 1);
                MKWidget_BringToFront(this->unk100);
                MKWidget_SetFocus(this->unk100);
                GetLocalToWorldMatrix(&arg_spF0);
                temp_r3_2719 = this->unk4;
                arg_sp98 = (f64) M2C_FIELD(temp_r3_2719, f32 *, 0x38);
                arg_spA0 = M2C_FIELD(temp_r3_2719, f64 *, 0x40);
                temp_f1_2729 = arg_sp9C * arg_sp100;
                temp_f0_2732 = arg_sp9C * arg_sp104;
                temp_f4_2734 = arg_sp9C * arg_sp108;
                temp_f6_2749 = ((f32) arg_spA0 * arg_sp110) + (((f32) arg_sp98 * arg_spF0) + temp_f1_2729);
                temp_f5_2752 = ((f32) arg_spA0 * arg_sp114) + (((f32) arg_sp98 * arg_spF4) + temp_f0_2732);
                temp_f4_2756 = ((f32) arg_spA0 * arg_sp118) + (((f32) arg_sp98 * arg_spF8) + temp_f4_2734);
                arg_sp98 = 0.0f;
                arg_sp18 = arg_sp120 + (((f32) arg_spA0 * arg_sp110) + ((0.0f * arg_spF0) + temp_f1_2729));
                arg_sp1C = arg_sp124 + (((f32) arg_spA0 * arg_sp114) + ((0.0f * arg_spF4) + temp_f0_2732));
                arg_sp20 = arg_sp128 + (((f32) arg_spA0 * arg_sp118) + ((0.0f * arg_spF8) + temp_f4_2734));
                arg_sp30 = arg_sp128 + temp_f4_2756;
                arg_sp28 = arg_sp120 + temp_f6_2749;
                arg_sp2C = arg_sp124 + temp_f5_2752;
                arg_spA8 = (f64) arg_sp18;
                arg_spB0 = (f64) arg_sp20;
                arg_sp68 = (f64) arg_sp28;
                arg_sp70 = (f64) arg_sp30;
                arg_spB8 = (f64) arg_sp28;
                arg_spC0 = (f64) arg_sp30;
                arg_sp58 = (f64) arg_sp18;
                arg_sp60 = (f64) arg_sp20;
                MKWidget_Move(this->unk100, *((MKVector3 *) &arg_spA8));
                temp_f1_2786 = (f32) arg_spB8 - (f32) arg_spA8;
                temp_r3_2788 = this->unk100->unk4;
                var_f4_2789 = 150.0f;
                temp_f3_2790 = 0.75f * temp_f1_2786;
                arg_sp98 = M2C_FIELD(temp_r3_2788, f64 *, 0x38);
                arg_spA0 = M2C_FIELD(temp_r3_2788, f64 *, 0x40);
                arg_sp98 = temp_f1_2786;
                if (var_f4_2789 < temp_f3_2790) {

                } else {
                    var_f4_2789 = temp_f3_2790;
                }
                arg_sp9C = var_f4_2789;
                var_f4_2805 = (f32) var_f4_2789;
                temp_f0_2813 = (15.0f * (f32) M2C_FIELD(temp_r29_2450, u32 *, 0x2C)) + 4.0f;
                if (var_f4_2805 < temp_f0_2813) {

                } else {
                    var_f4_2805 = temp_f0_2813;
                }
                arg_sp9C = var_f4_2805;
                MKWidget_Resize(this->unk100, *((MKVector3 *) &arg_sp98));
            }
            return;
        }
        if (temp_r4_2699 == &this->unkB0) {
            if ((u16) M2C_FIELD(arg1, u16 *, 4) == 1) {
                arg_sp88 = this;
                arg_sp8C = 1;
                arg_sp8C = 0;
                arg_sp90 = M2C_FIELD(arg1, s32 *, 8);
                arg_sp94 = 0;
                MKWidget_SendMessage((MKWidget *) this, 0x39U, (u32) &arg_sp88);
            }
            return;
        }
        goto block_70;
    }
}
#endif

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
MKWidgetComboBox::MKWidgetComboBox(MKWidgetDescriptor *arg0) {
    f64 sp60;
    f64 sp58;
    f64 sp30;
    f64 sp28;
    M2C_UNK sp24;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;

    this->unkB0.unk18 = (MKWidget *) this;
    this->unk28.unk18 = (MKWidget *) this;
    M2C_STRUCT_COPY((s32) &sp24 + 4, (s32) (MKWidgetIdentityAttributes - 4) + 4, 0x58);
    sp8 = 200.0f;
    spC = 200.0f;
    sp10 = 0.0f;
    sp28 = M2C_FIELD(&zero, f64 *, 0);
    sp30 = M2C_FIELD(&zero, f64 *, 8);
    sp18 = (f64) sp8;
    sp20 = (f64) sp10;
    sp58 = (f64) sp8;
    sp60 = (f64) sp10;
    this->unk100 = MKWidget_Create("", "", (MKWidgetAttributes *) &sp28, NULL, (s32 (*)(MKWidget *, u32, u32, void *)) &MKWidgetComboBox::ListBoxHook, this);
    MKWidget_DisableFlag(this->unk100, 0x10000U);
    MKWidget_EnableFlag(this->unk100, 0x400000U);
    MKWidget_Show(this->unk100, 0);
    MKWidget_SendMessage(this->unk100, 0x64U, 1U);
    if ((u8) this->unk8 == 0) {
        MKWidget_SendMessage(&this->unkB0, 0x66U, 0x80U);
        MKWidget_DisableFlag(&this->unkB0, 0x800U);
        MKWidget_SendMessage(&this->unk28, 0x17U, (u32) "");
        M2C_FIELD(this->unk4, s32 *, 0x68) = -1;
    }
    return this;
}
#endif

#if 0 // DRAFT: illegal operand 'MKWidgetEditable *'
void MKWidgetEditable::ContextMenuProc(int arg0, void *arg1) {
    switch (this) {                                 /* irregular */
    case 0:
        MKWidget_SaveHierarchy("", (MKWidget *) arg0);
        return;
    case 1:
        if (M2C_FIELD(*arg0, u8 (**)(s32), 0x2C)(arg0) != 0) {
            MKWidget_LoadHierarchy("", (MKWidgetContainer *) arg0);
        }
        return;
    }
}
#endif

#if 0 // DRAFT: illegal operand 'MKWidget *'
u32 MKWidgetEditable::EditableMessageHook(MKWidget *arg0, unsigned int arg1, unsigned int arg2, void *arg3) {
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    MKVector3 spA8;                                 /* compiler-managed */
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f32 sp60;
    f32 sp50;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp20;
    f32 sp10;
    f32 temp_f3_3219;
    s32 (*temp_r12_3018)(s32);
    s32 var_r0_3011;
    s8 **temp_r3_3058;
    u32 temp_r31_3130;

    var_r0_3011 = 1;
    if (arg2 != 0) {
        temp_r12_3018 = M2C_FIELD(arg2, s32 (**)(s32), 0x60);
        if (temp_r12_3018 != NULL) {
            var_r0_3011 = temp_r12_3018(M2C_FIELD(arg2, s32 *, 0x64));
        }
    }
    if (var_r0_3011 == 0) {
        return 0U;
    }
    switch (arg0) {                                 /* switch 1; irregular */
    case 0x2A:                                      /* switch 1 */
        if ((arg1 == 0x2E) || (arg1 == 8)) {
            MKWidget_Destroy((MKWidget *) arg2);
            return 0U;
        }
    default:                                        /* switch 1 */
    case 0x34:                                      /* switch 1 */
block_20:
        temp_r31_3130 = MessageHandler(arg0, arg1);
        switch (arg0) {                             /* switch 2; irregular */
        case 48:                                    /* switch 2 */
            if (arg1 == 1) {
                M2C_FIELD(arg2, u8 *, 0x50) = 1U;
                MKWidget_GetLocalMousePos((MKWidget *) this, arg2 + 0x40);
                MKWidget_SetMouseFocus((MKWidget *) this);
            } else if (arg1 == 2) {
                gContextMenu.PurgeItems();
                gContextMenu.AddItem("");
                gContextMenu.AddItem("");
                gContextMenu.AddItem("");
                gContextMenu.Show((void (*)(s32, void *)) &MKWidgetEditable::ContextMenuProc, this);
            }
            break;
        case 49:                                    /* switch 2 */
            if (arg1 == 1) {
                M2C_FIELD(arg2, u8 *, 0x50) = 0U;
                MKWidget_ReleaseMouseFocus();
            }
            break;
        case 46:                                    /* switch 2 */
            if ((u8) M2C_FIELD(arg2, u8 *, 0x50) != 0) {
                MKWidget_GetLocalMousePos((MKWidget *) this, &spA8);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $r30, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                sp78 = sp8;
                sp10 = spA8.unk8 - M2C_FIELD(arg2, f32 *, 0x48);
                spA8 = sp8;
                sp80 = (f64) sp10;
                spA8.unk8 = (f64) sp10;
                if (arg2->IsFlagSet(0x100U) != 0) {
                    temp_f3_3219 = (f32) fmod(M2C_BITWISE(f32, spA8), 10.0);
                    spA8 = M2C_BITWISE(f32, spA8) - temp_f3_3219;
                    spA8.unk4 -= (f32) fmod(spA8.unk4, 10.0, temp_f3_3219);
                }
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                sp68 = sp18;
                sp20 = M2C_FIELD((M2C_FIELD(arg2, s32 *, 4) + 8), f32 *, 8) + spA8.unk8;
                sp70 = (f64) sp20;
                MKWidget_Move((MKWidget *) arg2, *((MKVector3 *) &sp68));
            }
            break;
        }
        return temp_r31_3130;
    case 0x4:                                       /* switch 1 */
        if ((u8) M2C_FIELD(arg2, u8 *, 0x51) == 0) {
            temp_r3_3058 = this->unk4;
            spD8 = M2C_FIELD(temp_r3_3058, f64 *, 8);
            spE0 = M2C_FIELD(temp_r3_3058, f64 *, 0x10);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r28, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            spC8 = sp58;
            sp60 = M2C_FIELD(arg1, f32 *, 8) - (f32) spE0;
            spD0 = (f64) sp60;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp98 = sp48;
            sp50 = M2C_FIELD((M2C_FIELD(arg2, s32 *, 4) + 8), f32 *, 8) + (f32) spD0;
            spA0 = (f64) sp50;
            MKWidget_Move((MKWidget *) arg2, *((MKVector3 *) &sp98));
        }
        goto block_20;
    case 0x5:                                       /* switch 1 */
        if ((u8) M2C_FIELD(arg2, u8 *, 0x51) == 0) {
            sp38 = 8.0f;
            sp3C = 8.0f;
            sp40 = 0.0f;
            sp88 = (f64) sp38;
            sp90 = (f64) sp40;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r28, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            spB8 = sp28;
            sp30 = M2C_FIELD(arg1, f32 *, 8) + (f32) sp90;
            spC0 = (f64) sp30;
            MKWidget_Resize((MKWidget *) arg2, *((MKVector3 *) &spB8));
        }
        goto block_20;
    }
}
#endif

#if 0 // DRAFT: illegal type
void MKWidgetEditable::Render(MKWidgetRenderContext *arg0) {
    f64 sp240;
    f64 sp238;
    f64 sp230;
    f64 sp228;
    f64 sp220;
    f64 sp218;
    f64 sp210;
    f64 sp208;
    f64 sp200;
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
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
    f64 sp128;
    f32 sp120;
    f32 sp11C;
    f32 sp118;
    f32 sp110;
    f32 sp10C;
    f32 sp108;
    f32 sp100;
    f32 spF4;
    f32 spF0;
    f32 spEC;
    f32 spE8;
    f32 spE0;
    f32 spDC;
    f32 spD8;
    f32 spD0;
    f32 spCC;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA0;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp80;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
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
    f32 temp_f1_3423;
    f32 temp_f2_3458;
    f32 temp_f4_3377;

    MKWidget::Render(arg0);
    MKMaterial_SetMaterial(pWidgetBlank);
    MKPrimitive(4, 0);
    MKSetBaseColorV(arg0->unk40);
    MKSetMatrix(*((Matrix *) arg0));
    spE8 = 0.0f;
    spEC = 0.0f;
    sp110 = 0.0f;
    spF0 = 1.0f;
    spF4 = 1.0f;
    sp108 = -6.0f;
    sp10C = -6.0f;
    sp208 = (f64) spE8;
    sp210 = (f64) spF0;
    sp218 = (f64) sp108;
    sp220 = (f64) sp110;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r6, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp120 = 0.0f;
    sp118 = -2.0f;
    sp100 = M2C_FIELD((this->unk4 + 0x38), f32 *, 8) + (f32) sp220;
    sp11C = -2.0f;
    sp228 = spF8;
    sp230 = (f64) sp100;
    sp238 = (f64) sp118;
    sp240 = (f64) sp120;
    WidgetDrawBox(*((MKVector3 *) &sp238), *((MKVector3 *) &sp228), *((MKVector4 *) &sp208));
    spD0 = 0.0f;
    spE0 = 0.0f;
    spB8 = 0.0f;
    spBC = 0.0f;
    spC0 = 1.0f;
    spC4 = 1.0f;
    spC8 = 4.0f;
    spCC = 4.0f;
    spD8 = -4.0f;
    spDC = -4.0f;
    sp1D8 = (f64) spB8;
    sp1E0 = (f64) spC0;
    sp1E8 = (f64) spC8;
    sp1F0 = (f64) spD0;
    sp1F8 = (f64) spD8;
    sp200 = (f64) spE0;
    WidgetDrawBox(*((MKVector3 *) &sp1F8), *((MKVector3 *) &sp1E8), *((MKVector4 *) &sp1D8));
    sp68 = 0.0f;
    sp6C = 0.0f;
    sp90 = 0.0f;
    sp70 = 1.0f;
    sp74 = 1.0f;
    sp88 = 4.0f;
    sp8C = 4.0f;
    sp188 = (f64) sp68;
    sp190 = (f64) sp70;
    sp198 = (f64) sp88;
    sp1A0 = (f64) sp90;
    M2C_ERROR(/* unknown instruction: psq_lx $f5, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f5, $f0 */);
    spB0 = 0.0f;
    temp_f4_3377 = M2C_FIELD((this->unk4 + 0x38), f32 *, 8);
    spA8 = 12.0f;
    spAC = 12.0f;
    sp80 = temp_f4_3377 - (f32) sp1A0;
    sp1B8 = (f64) spA8;
    sp1A8 = sp78;
    sp1B0 = (f64) sp80;
    sp1C0 = (f64) spB0;
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f5, $f0 */);
    sp1C8 = sp98;
    spA0 = temp_f4_3377 - (f32) sp1C0;
    sp1D0 = (f64) spA0;
    WidgetDrawBox(*((MKVector3 *) &sp1C8), *((MKVector3 *) &sp1A8), *((MKVector4 *) &sp188));
    sp38 = 0.0f;
    sp3C = 0.0f;
    sp40 = 1.0f;
    sp44 = 1.0f;
    sp158 = (f64) sp38;
    sp160 = (f64) sp40;
    sp50 = 0.0f;
    temp_f1_3423 = M2C_FIELD(this->unk4, f32 *, 0x3C);
    sp60 = 0.0f;
    sp48 = 4.0f;
    sp4C = temp_f1_3423 - 4.0f;
    sp58 = -4.0f;
    sp5C = temp_f1_3423 - 12.0f;
    sp168 = (f64) sp48;
    sp170 = (f64) sp50;
    sp178 = (f64) sp58;
    sp180 = (f64) sp60;
    WidgetDrawBox(*((MKVector3 *) &sp178), *((MKVector3 *) &sp168), *((MKVector4 *) &sp158));
    sp8 = 0.0f;
    spC = 0.0f;
    sp10 = 1.0f;
    sp14 = 1.0f;
    sp128 = (f64) sp8;
    sp130 = (f64) sp10;
    sp20 = 0.0f;
    temp_f2_3458 = M2C_FIELD(this->unk4, f32 *, 0x38);
    sp30 = 0.0f;
    sp1C = 4.0f;
    sp18 = temp_f2_3458 - 4.0f;
    sp28 = temp_f2_3458 - 12.0f;
    sp2C = -4.0f;
    sp138 = (f64) sp18;
    sp140 = (f64) sp20;
    sp148 = (f64) sp28;
    sp150 = (f64) sp30;
    WidgetDrawBox(*((MKVector3 *) &sp148), *((MKVector3 *) &sp138), *((MKVector4 *) &sp128));
    MKEndPrimitive();
}
#endif

#if 0 // DRAFT: identifier 'MKWidgetEditable::MessageHandler(unsigned int, unsigned int)'
u32 MKWidgetEditable::MessageHandler(unsigned int arg0, unsigned int arg1) {
    MKVector3 sp118;
    f64 sp110;
    f64 sp108;
    MKVector3 spF8;
    f64 spF0;
    f64 spE8;
    f32 spDC;
    f32 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    M2C_UNK spA8;
    f64 spA0;
    f64 sp98;
    M2C_UNK sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp20;
    f32 sp10;
    MKWidget *temp_r3_3503;
    MKWidget *temp_r3_3514;
    f32 temp_f3_3565;
    f32 temp_f3_3589;
    s32 temp_r0_3733;
    s32 temp_r0_3786;
    s32 temp_r0_3802;
    s8 **temp_r4_3532;
    u32 temp_r28_3620;

    switch (arg0) {                                 /* switch 1 */
    case 0x3D:                                      /* switch 1 */
    case 0x3E:                                      /* switch 1 */
        temp_r3_3503 = this->unk18;
        if (temp_r3_3503 != NULL) {
            return MKWidget_SendMessage(temp_r3_3503, arg0, (u32) this);
        }
        return 0U;
    case 0x20:                                      /* switch 1 */
        temp_r3_3514 = this->unk28;
        if (temp_r3_3514 != NULL) {
            return MKWidget_SendMessage(temp_r3_3514, arg0, arg1);
        }
    default:                                        /* switch 1 */
block_56:
        return MKWidgetContainer::MessageHandler(arg0, arg1);
    case 0x12:                                      /* switch 1 */
        sp38 = 4.0f;
        sp3C = 4.0f;
        sp40 = 0.0f;
        M2C_FIELD(arg1, f64 *, 0) = (f64) sp38;
        M2C_FIELD(arg1, f64 *, 8) = (f64) sp40;
        spC8 = (f64) sp38;
        temp_r4_3532 = this->unk28->unk4;
        spD0 = (f64) sp40;
        M2C_FIELD(arg1, f64 *, 0x10) = (f64) M2C_FIELD(temp_r4_3532, f64 *, 0x38);
        M2C_FIELD(arg1, f64 *, 0x18) = (f64) M2C_FIELD(temp_r4_3532, f64 *, 0x40);
        return 0U;
    case 0x30:                                      /* switch 1 */
        MKWidget_GetLocalMousePos((MKWidget *) this, &this->unk40);
        switch ((s32) arg1) {                       /* switch 2; irregular */
        case 3:                                     /* switch 2 */
            break;
        case 1:                                     /* switch 2 */
            this->unk54 = 1;
            break;
        case 2:                                     /* switch 2 */
            this->unk54 = 2;
            break;
        case 4:                                     /* switch 2 */
            this->unk54 = 3;
            break;
        }
        temp_f3_3565 = this->unk40.unk0;
        if (temp_f3_3565 < 6.0f) {
            this->unk58 = 0;
        } else {
            M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
            if (temp_f3_3565 == ((-4.0f + M2C_FIELD(this->unk4, f32 *, 0x38)) - 10.0f)) {
                this->unk58 = 2;
            } else {
                this->unk58 = 1;
            }
        }
        temp_f3_3589 = this->unk40.unk4;
        if (temp_f3_3589 < 6.0f) {
            this->unk5C = 0;
        } else {
            M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
            if (temp_f3_3589 == ((-4.0f + M2C_FIELD(this->unk4, f32 *, 0x3C)) - 10.0f)) {
                this->unk5C = 2;
            } else {
                this->unk5C = 1;
            }
        }
        MKWidget_SetMouseFocus((MKWidget *) this);
        goto block_56;
    case 0x3A:                                      /* switch 1 */
        temp_r28_3620 = MKWidgetContainer::MessageHandler(arg0, arg1);
        MKWidget_GetPos((MKWidget *) this, &sp118);
        MKVector(4.0f, 4.0f, 0.0f);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        M2C_FIELD(this, f64 *, 0x30) = sp28;
        sp30 = sp118.unk8 + spB0;
        spB8 = sp28;
        M2C_FIELD(this, f64 *, 0x38) = (f64) sp30;
        this->unk51 = 1;
        spC0 = (f64) sp30;
        MKWidget_SendMessage(this->unk28, 4U, (u32) &this->unk30);
        this->unk51 = 0;
        return temp_r28_3620;
    case 0x4:                                       /* switch 1 */
        if ((MKWidget *) this->unk28 != NULL) {
            MKVector(4.0f, 4.0f, 0.0f);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            M2C_FIELD(this, f64 *, 0x30) = sp18;
            sp20 = (f32) M2C_FIELD(arg1, f64 *, 8) + sp90;
            sp98 = sp18;
            M2C_FIELD(this, f64 *, 0x38) = (f64) sp20;
            this->unk51 = 1;
            spA0 = (f64) sp20;
            MKWidget_SendMessage(this->unk28, 4U, (u32) &this->unk30);
            this->unk51 = 0;
        }
        goto block_56;
    case 0x5:                                       /* switch 1 */
        if ((MKWidget *) this->unk28 != NULL) {
            sp58 = 8.0f;
            sp5C = 8.0f;
            sp60 = 0.0f;
            sp78 = (f64) sp58;
            sp80 = (f64) sp60;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            sp108 = sp48;
            sp50 = (f32) M2C_FIELD(arg1, f64 *, 8) - (f32) sp80;
            sp110 = (f64) sp50;
            this->unk51 = 1;
            MKWidget_SendMessage(this->unk28, 5U, (u32) &sp108);
            this->unk51 = 0;
        }
        goto block_56;
    case 0x2E:                                      /* switch 1 */
        if ((s32) this->unk54 != 0) {
            MKWidget_GetLocalMousePos((MKWidget *) this, &spF8);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $r29, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            temp_r0_3733 = this->unk54;
            sp68 = sp8;
            sp10 = spF8.unk8 - this->unk40.unk8;
            spE8 = sp8;
            sp70 = (f64) sp10;
            spF0 = (f64) sp10;
            if (((temp_r0_3733 == 1) || (temp_r0_3733 == 2)) && (((s32) this->unk58 == 0) || ((s32) this->unk5C == 0))) {
                MKWidget_SendMessage((MKWidget *) this, 9U, (u32) &spF8);
                if ((s32) this->unk58 == 0) {
                    spF8 = M2C_BITWISE(f32, spF8) + (f32) spE8;
                }
                if ((s32) this->unk5C == 0) {
                    spF8.unk4 += unkspEC;
                }
                MKWidget_SendMessage((MKWidget *) this, 4U, (u32) &spF8);
            }
            if ((s32) this->unk54 == 1) {
                MKWidget_SendMessage((MKWidget *) this, 0xAU, (u32) &spD8);
                temp_r0_3786 = this->unk58;
                if (temp_r0_3786 == 0) {
                    spD8 -= (f32) spE8;
                } else if (temp_r0_3786 == 2) {
                    spD8 += (f32) spE8;
                }
                temp_r0_3802 = this->unk5C;
                if (temp_r0_3802 == 0) {
                    spDC -= unkspEC;
                } else if (temp_r0_3802 == 2) {
                    spDC += unkspEC;
                }
                MKWidget_SendMessage((MKWidget *) this, 5U, (u32) &spD8);
                MKWidget_GetLocalMousePos((MKWidget *) this, &this->unk40);
            }
        }
        goto block_56;
    case 0x31:                                      /* switch 1 */
        if ((s32) this->unk54 != 0) {
            MKWidget_ReleaseMouseFocus();
            this->unk54 = 0;
        }
        goto block_56;
    }
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
MKWidgetEditable::MKWidgetEditable(MKWidgetDescriptor *arg0) {
    this->unk50 = 0;
    return this;
}
#endif

void MKWidgetColor::BuildAggregateMetaData() {

}

void MKWidgetColor::BuildMetaData(int arg0) {

}

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void MKWidgetColor::Render(MKWidgetRenderContext *arg0) {
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKVector4 *temp_r29_3963;
    MKVector4 *var_r5_4023;
    f32 temp_f25_4012;
    f32 temp_f26_4011;
    f32 temp_f27_4015;
    f32 temp_f4_3985;
    f32 temp_f4_4028;
    f32 temp_f5_3987;
    f32 var_f24_4016;
    f32 var_f30_3988;
    s32 temp_r27_4002;
    s32 temp_r28_4001;
    s32 var_r24_4018;
    s32 var_r31_3994;
    s8 **temp_r4_3943;
    s8 **temp_r4_3974;
    s8 **temp_r6_4066;
    u8 var_r25_4017;
    u8 var_r26_3990;

    MKWidget::Render(arg0);
    MKMaterial_SetMaterial(pWidgetBlank);
    MKPrimitive(0x10C, 0);
    MKSetBaseColorV(arg0->unk40);
    MKSetMatrix(*((Matrix *) arg0));
    temp_r4_3943 = this->unk4;
    sp50 = 0.0f;
    sp60 = 0.0f;
    sp48 = M2C_FIELD(temp_r4_3943, f32 *, 0x38);
    sp4C = M2C_FIELD(temp_r4_3943, f32 *, 0x3C);
    sp58 = 0.0f;
    sp5C = 0.0f;
    spA8 = (f64) sp48;
    spB0 = (f64) sp50;
    spB8 = (f64) sp58;
    spC0 = (f64) sp60;
    temp_r29_3963 = MKWidget_GetMetric(1);
    WidgetDrawBevel(*((MKVector3 *) &spB8), *((MKVector3 *) &spA8), 1.0f, *(MKWidget_GetMetric(0)), *temp_r29_3963, 1U, 0U);
    temp_r4_3974 = this->unk4;
    if (M2C_FIELD(temp_r4_3974, f32 *, 0x74) < 1.0f) {
        temp_f4_3985 = M2C_FIELD(temp_r4_3974, f32 *, 0x38) - 2.0f;
        temp_f5_3987 = M2C_FIELD(temp_r4_3974, f32 *, 0x3C) - 2.0f;
        var_f30_3988 = 0.0f;
        var_r26_3990 = 0;
        var_r31_3994 = 0;
        temp_r28_4001 = (s32) (temp_f4_3985 / 6.0f);
        temp_r27_4002 = (s32) (temp_f5_3987 / 6.0f);
        temp_f26_4011 = temp_f4_3985 / (f32) temp_r28_4001;
        temp_f25_4012 = temp_f5_3987 / (f32) temp_r27_4002;
loop_8:
        if (var_r31_3994 < temp_r27_4002) {
            temp_f27_4015 = 1.0f + var_f30_3988;
            var_f24_4016 = 0.0f;
            var_r25_4017 = var_r26_3990;
            var_r24_4018 = 0;
loop_6:
            if (var_r24_4018 < temp_r28_4001) {
                var_r5_4023 = &identity;
                if (var_r25_4017 != 0) {
                    var_r5_4023 = &one;
                }
                temp_f4_4028 = 1.0f + var_f24_4016;
                sp30 = 0.0f;
                sp40 = 0.0f;
                sp2C = temp_f27_4015 + temp_f25_4012;
                sp28 = temp_f4_4028 + temp_f26_4011;
                sp38 = temp_f4_4028;
                sp3C = temp_f27_4015;
                sp88 = (f64) sp28;
                sp90 = (f64) sp30;
                sp98 = (f64) sp38;
                spA0 = (f64) sp40;
                WidgetDrawBox(*((MKVector3 *) &sp98), *((MKVector3 *) &sp88), *var_r5_4023);
                var_f24_4016 += temp_f26_4011;
                var_r24_4018 += 1;
                var_r25_4017 = var_r25_4017 == 0;
                goto loop_6;
            }
            var_f30_3988 += temp_f25_4012;
            var_r31_3994 += 1;
            var_r26_3990 = var_r26_3990 == 0;
            goto loop_8;
        }
    }
    temp_r6_4066 = this->unk4;
    sp18 = 1.0f;
    sp10 = 0.0f;
    sp1C = 1.0f;
    sp20 = 0.0f;
    sp8 = M2C_FIELD(temp_r6_4066, f32 *, 0x38) - 1.0f;
    spC = M2C_FIELD(temp_r6_4066, f32 *, 0x3C) - 1.0f;
    sp70 = (f64) sp10;
    sp68 = (f64) sp8;
    sp78 = (f64) sp18;
    sp80 = (f64) sp20;
    WidgetDrawBox(*((MKVector3 *) &sp78), *((MKVector3 *) &sp68), *(MKVector4 *) (temp_r6_4066 + 0x68));
    MKEndPrimitive();
}
#endif

#if 0 // DRAFT: identifier 'MKWidgetColor::MessageHandler(unsigned int, unsigned int)'
void MKWidgetColor::MessageHandler(unsigned int arg0, unsigned int arg1) {
    s32 sp14;
    s8 **sp10;
    s16 spE;
    s16 spC;
    MKWidgetColor *sp8;
    s8 **temp_r3_4155;
    s8 **temp_r7_4136;

    switch ((s32) arg0) {                           /* irregular */
    case 0x64:
        temp_r7_4136 = this->unk4;
        M2C_FIELD(temp_r7_4136, f64 *, 0x68) = (f64) M2C_FIELD(arg1, f64 *, 0);
        M2C_FIELD(temp_r7_4136, f64 *, 0x70) = (f64) M2C_FIELD(arg1, f64 *, 8);
        sp8 = this;
        spC = 1;
        spE = 0;
        sp10 = this->unk4 + 0x68;
        sp14 = 0;
        MKWidget_SendMessage((MKWidget *) this, 0x39U, (u32) &sp8);
        break;
    case 0x65:
        temp_r3_4155 = this->unk4;
        M2C_FIELD(arg1, f64 *, 0) = (f64) M2C_FIELD(temp_r3_4155, f64 *, 0x68);
        M2C_FIELD(arg1, f64 *, 8) = (f64) M2C_FIELD(temp_r3_4155, f64 *, 0x70);
        break;
    case 0x33:
        if (IsFlagSet(0x100U) != 0) {
            gColorEditor.Show(*(MKVector4 *) (this->unk4 + 0x68), (MKWidget *) this);
        }
        break;
    }
    MKWidget::MessageHandler(arg0, arg1);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
MKWidgetColor::MKWidgetColor(MKWidgetDescriptor *arg0) {
    s8 **temp_r6_4200;

    if ((u8) this->unk8 == 0) {
        temp_r6_4200 = this->unk4;
        M2C_FIELD(temp_r6_4200, f64 *, 0x68) = (f64) M2C_FIELD(&one, f64 *, 0);
        M2C_FIELD(temp_r6_4200, f64 *, 0x70) = (f64) M2C_FIELD(&one, f64 *, 8);
        MKWidget_EnableFlag((MKWidget *) this, 0x100U);
    }
    return this;
}
#endif

void MKWidgetImage::BuildAggregateMetaData() {

}

void MKWidgetImage::BuildMetaData(int arg0) {

}

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void MKWidgetImage::Render(MKWidgetRenderContext *arg0) {
    MKMaterial *temp_r3_4240;
    s8 **temp_r3_4284;

    MKWidget::Render(arg0);
    temp_r3_4240 = this->unk28;
    if (temp_r3_4240 != NULL) {
        MKMaterial_SetMaterial(temp_r3_4240);
        MKPrimitive(0xC, 0);
        MKSetBaseColorV(arg0->unk40);
        MKSetMatrix(*((Matrix *) arg0));
        MKBegin(4);
        MKSetColorF(1.0f, 1.0f, 1.0f, 1.0f);
        MKSetTexCoord1F(0.0f, 0.0f);
        MKSetPositionF(0.0f, 0.0f, 0.0f);
        MKSetTexCoord1F(1.0f, 0.0f);
        MKSetPositionF(M2C_FIELD(this->unk4, f32 *, 0x38), 0.0f, 0.0f);
        MKSetTexCoord1F(0.0f, 1.0f);
        MKSetPositionF(0.0f, M2C_FIELD(this->unk4, f32 *, 0x3C), 0.0f);
        MKSetTexCoord1F(1.0f, 1.0f);
        temp_r3_4284 = this->unk4;
        MKSetPositionF(M2C_FIELD(temp_r3_4284, f32 *, 0x38), M2C_FIELD(temp_r3_4284, f32 *, 0x3C), 0.0f);
        MKEnd();
        MKEndPrimitive();
    }
}
#endif

#if 0 // DRAFT: identifier 'MKWidgetImage::MessageHandler(unsigned int, unsigned int)'
void MKWidgetImage::MessageHandler(unsigned int arg0, unsigned int arg1) {
    MKWidget *temp_r3_4332;

    switch (arg0) {
    case 0x46:
        this->unk28 = (MKMaterial *) arg1;
    default:
block_7:
        MKWidget::MessageHandler(arg0, arg1);
        return;
    case 0x33:
        if (IsFlagSet(0x100U) != 0) {
            gMaterialEditor.Show(this->unk28);
            goto block_7;
        }
    case 0x20:
    case 0x21:
    case 0x26:
    case 0x29:
    case 0x2A:
    case 0x2B:
    case 0x2E:
    case 0x2F:
    case 0x30:
    case 0x31:
    case 0x34:
    case 0x35:
    case 0x36:
    case 0x37:
    case 0x38:
        temp_r3_4332 = this->unk18;
        if (temp_r3_4332 != NULL) {
            MKWidget_SendMessage(temp_r3_4332, arg0, arg1);
            return;
        }
        goto block_7;
    }
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
MKWidgetImage::MKWidgetImage(MKWidgetDescriptor *arg0) {
    this->unk28 = NULL;
    return this;
}
#endif

void MKWidgetTabStrip::BuildAggregateMetaData() {

}

void MKWidgetTabStrip::BuildMetaData(int arg0) {

}

void MKWidgetTabStrip::FreeResources() {
    MKWidget *temp_r3_4398;

loop_2:
    temp_r3_4398 = this->unk28;
    if (temp_r3_4398 != NULL) {
        MKWidget_Destroy(temp_r3_4398);
        goto loop_2;
    }
}

#if 0 // DRAFT: pointer/array required
MKWidget *MKWidgetTabStrip::TestPoint(MKVector3 *arg0) {
    f64 sp20;
    f64 sp18;
    f64 sp10;
    f64 sp8;
    MKWidget *temp_r3_4439;
    MKWidget *temp_r3_4464;
    MKWidget *var_r30_4418;
    s32 var_r29_4424;
    s32 var_r31_4425;

    var_r30_4418 = MKWidget::TestPoint(arg0);
    if ((var_r30_4418 != NULL) && (((s32) this->unk2C / 2) > 0)) {
        var_r29_4424 = 0;
        var_r31_4425 = 0;
loop_6:
        if (var_r29_4424 < (s32) ((s32) this->unk2C / 2)) {
            sp18 = M2C_FIELD(arg0, f64 *, 0);
            sp20 = M2C_FIELD(arg0, f64 *, 8);
            GetChild(var_r31_4425 + 1);
            temp_r3_4439 = M2C_FIELD(*M2C_ERROR(/* Read from unset register $r3 */), MKWidget *(**)(), 0x24)();
            if (temp_r3_4439 != NULL) {
                var_r30_4418 = temp_r3_4439;
            }
            var_r29_4424 += 1;
            var_r31_4425 += 2;
            goto loop_6;
        }
        sp8 = M2C_FIELD(arg0, f64 *, 0);
        sp10 = M2C_FIELD(arg0, f64 *, 8);
        GetChild(this->unk40 * 2);
        temp_r3_4464 = M2C_FIELD(*M2C_ERROR(/* Read from unset register $r3 */), MKWidget *(**)(), 0x24)();
        if (temp_r3_4464 != NULL) {
            var_r30_4418 = temp_r3_4464;
        }
    }
    return var_r30_4418;
}
#endif

#if 0 // DRAFT: identifier 'MKWidgetTabStrip::MessageHandler(unsigned int, unsigned int)'
u32 MKWidgetTabStrip::MessageHandler(unsigned int arg0, unsigned int arg1) {
    s32 sp134;
    s32 sp130;
    f64 sp100;                                      /* compiler-managed */
    f64 spF8;                                       /* compiler-managed */
    f32 spD0;
    f32 spCC;
    f32 spC8;
    s32 spC4;
    s32 spC0;
    s16 spBE;
    s16 spBC;
    MKWidgetTabStrip *spB8;
    f64 spB0;
    f64 spA8;
    M2C_UNK sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    MKWidget *temp_r3_4596;
    MKWidget *temp_r3_4640;
    f32 temp_f2_4615;
    s32 temp_r0_4804;
    s32 temp_r0_4864;
    s32 temp_r26_4664;
    s32 temp_r27_4703;
    s32 temp_r3_4546;
    s32 temp_r4_4759;
    s32 temp_r5_4769;
    s32 var_r0_4547;
    s32 var_r24_4661;
    s32 var_r24_4851;
    s32 var_r29_4669;
    s32 var_r31_4557;
    s32 var_r31_4852;
    u32 temp_r25_4659;

    switch ((s32) arg0) {                           /* irregular */
    case 0x3:
        FreeResources();
block_49:
    default:
        return MKWidgetContainer::MessageHandler(arg0, arg1);
    case 0x64:
        M2C_STRUCT_COPY((s32) &spC4 + 4, (s32) (MKWidgetIdentityAttributes - 4) + 4, 0x58);
        FreeResources();
        temp_r3_4546 = this->unk40;
        var_r0_4547 = arg1 - 1;
        if (temp_r3_4546 < var_r0_4547) {
            var_r0_4547 = temp_r3_4546;
        }
        this->unk40 = var_r0_4547;
        var_r31_4557 = 0;
loop_22:
        if (var_r31_4557 < (s32) arg1) {
            spC8 = 0.0f;
            spCC = 26.0f;
            spD0 = 0.0f;
            MKVector(0.0f, 26.0f, 0.0f);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            spA8 = sp8;
            sp10 = M2C_FIELD((this->unk4 + 0x38), f32 *, 8) - spA0;
            spF8 = sp8;
            spB0 = (f64) sp10;
            sp100 = (f64) sp10;
            temp_r3_4596 = MKWidget_Create("", "", (MKWidgetAttributes *) &spC8, (MKWidget *) this, NULL, NULL);
            MKWidget_Show(temp_r3_4596, (s32) (u8) (var_r31_4557 == this->unk40));
            MKWidget_SetCustomMessageHook(temp_r3_4596, (s32 (*)(MKWidget *, u32, u32, void *)) this->unk10);
            MKWidget_SetUserData(temp_r3_4596, (void *) this->unk14);
            temp_f2_4615 = M2C_FIELD(this->unk4, f32 *, 0x38);
            spCC = 0.0f;
            spD0 = 0.0f;
            unkspFC = 24.0f;
            sp100 = 0.0f;
            spC8 = ((f32) var_r31_4557 * (temp_f2_4615 / (f32) arg1)) + 1.0f;
            spF8 = (temp_f2_4615 / (f32) arg1) - 2.0f;
            temp_r3_4640 = MKWidget_Create("", "", (MKWidgetAttributes *) &spC8, (MKWidget *) this, NULL, NULL);
            MKWidget_EnableFlag(temp_r3_4640, 0x400U);
            MKWidget_SendMessage(temp_r3_4640, 0x64U, var_r31_4557 == this->unk40);
            var_r31_4557 += 1;
            goto loop_22;
        }
        goto block_49;
    case 0x5:
        temp_r25_4659 = MKWidgetContainer::MessageHandler(arg0, arg1);
        var_r24_4661 = 0;
        temp_r26_4664 = (s32) this->unk2C / 2;
        var_r29_4669 = 0;
loop_26:
        if (var_r24_4661 < temp_r26_4664) {
            sp48 = 0.0f;
            sp4C = 26.0f;
            sp50 = 0.0f;
            sp78 = (f64) sp48;
            sp80 = (f64) sp50;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            sp88 = sp38;
            sp40 = M2C_FIELD((this->unk4 + 0x38), f32 *, 8) - (f32) sp80;
            sp90 = (f64) sp40;
            GetChild(var_r29_4669);
            MKWidget_Resize(M2C_ERROR(/* Read from unset register $r3 */), *((MKVector3 *) &sp88));
            temp_r27_4703 = var_r29_4669 + 1;
            sp30 = 0.0f;
            sp134 = var_r24_4661 ^ 0x80000000;
            sp130 = 0x43300000;
            sp2C = 0.0f;
            sp70 = (f64) sp30;
            sp28 = ((f32) var_r24_4661 * (M2C_FIELD(this->unk4, f32 *, 0x38) / (f32) temp_r26_4664)) + 1.0f;
            sp68 = (f64) sp28;
            GetChild(temp_r27_4703);
            MKWidget_Move(M2C_ERROR(/* Read from unset register $r3 */), *((MKVector3 *) &sp68));
            sp20 = 0.0f;
            sp1C = 24.0f;
            sp60 = (f64) sp20;
            sp18 = (M2C_FIELD(this->unk4, f32 *, 0x38) / (f32) temp_r26_4664) - 2.0f;
            sp58 = (f64) sp18;
            GetChild(temp_r27_4703);
            MKWidget_Resize(M2C_ERROR(/* Read from unset register $r3 */), *((MKVector3 *) &sp58));
            var_r24_4661 += 1;
            var_r29_4669 += 2;
            goto loop_26;
        }
        return temp_r25_4659;
    case 0x26:
        if (arg1 == 0xA) {
            temp_r4_4759 = this->unk40;
            if (temp_r4_4759 > 0) {
                MKWidget_SendMessage((MKWidget *) this, 0x68U, temp_r4_4759 - 1);
            }
        } else if (arg1 == 0xB) {
            temp_r5_4769 = this->unk40;
            if (temp_r5_4769 < (s32) (((s32) this->unk2C / 2) - 1)) {
                MKWidget_SendMessage((MKWidget *) this, 0x68U, temp_r5_4769 + 1);
            }
        }
        return 0U;
    case 0x65:
        GetChild(this->unk40 * 2);
        M2C_FIELD(arg1, u32 *, 0) = (u32) M2C_ERROR(/* Read from unset register $r3 */);
        goto block_49;
    case 0x66:
        GetChild((this->unk40 * 2) + 1);
        MKWidget_SendMessage(M2C_ERROR(/* Read from unset register $r3 */), 0x17U, arg1);
        goto block_49;
    case 0x67:
        GetChild((this->unk40 * 2) + 1);
        MKWidget_SendMessage(M2C_ERROR(/* Read from unset register $r3 */), 0x18U, arg1);
        goto block_49;
    case 0x68:
        temp_r0_4804 = this->unk40;
        if (temp_r0_4804 != (s32) arg1) {
            GetChild(temp_r0_4804 * 2);
            MKWidget_Show(M2C_ERROR(/* Read from unset register $r3 */), 0);
            GetChild((this->unk40 * 2) + 1);
            MKWidget_SendMessage(M2C_ERROR(/* Read from unset register $r3 */), 0x64U, 0U);
            this->unk40 = (s32) arg1;
            GetChild(this->unk40 * 2);
            MKWidget_Show(M2C_ERROR(/* Read from unset register $r3 */), 1);
            GetChild((this->unk40 * 2) + 1);
            MKWidget_SendMessage(M2C_ERROR(/* Read from unset register $r3 */), 0x64U, 1U);
            spB8 = this;
            spBC = 1;
            spBE = 0;
            spC0 = this->unk40;
            spC4 = 0;
            MKWidget_SendMessage((MKWidget *) this, 0x39U, (u32) &spB8);
        }
        goto block_49;
    case 0x69:
        return (u32) this->unk40;
    case 0x39:
        var_r24_4851 = 0;
        var_r31_4852 = 0;
loop_48:
        if (var_r24_4851 < (s32) ((s32) this->unk2C / 2)) {
            GetChild(var_r31_4852 + 1);
            if (((u32) M2C_FIELD(arg1, u32 *, 0) == (u32) M2C_ERROR(/* Read from unset register $r3 */)) && ((u16) M2C_FIELD(arg1, u16 *, 4) == 6)) {
                temp_r0_4864 = this->unk40;
                if (temp_r0_4864 != var_r24_4851) {
                    MKWidget_SendMessage((MKWidget *) this, 0x68U, (u32) var_r24_4851);
                } else {
                    GetChild((temp_r0_4864 * 2) + 1);
                    MKWidget_SendMessage(M2C_ERROR(/* Read from unset register $r3 */), 0x64U, 1U);
                }
            }
            var_r24_4851 += 1;
            var_r31_4852 += 2;
            goto loop_48;
        }
        goto block_49;
    }
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
MKWidgetTabStrip::MKWidgetTabStrip(MKWidgetDescriptor *arg0) {
    this->unk40 = 0;
    return this;
}
#endif

void MKWidgetTextBox::BuildAggregateMetaData() {

}

void MKWidgetTextBox::BuildMetaData(int arg0) {

}

#if 0 // DRAFT: illegal implicit conversion from 'MKHeap *' to
void MKWidgetTextBox::FindCaretPos() {
    f64 sp30;
    f64 sp28;                                       /* compiler-managed */
    MKFont sp18;
    MKFont sp8;
    f32 temp_f0_5102;
    f32 temp_f1_5082;
    f32 temp_f1_5101;
    f32 temp_f28_5035;
    f32 temp_f29_5029;
    f32 temp_f2_5092;
    f32 temp_f31_5034;
    f32 temp_f3_5091;
    f32 var_f2_5009;
    f32 var_f30_5021;
    f32 var_f31_4985;
    s32 temp_r0_4977;
    s32 temp_r0_5001;
    s8 **temp_r3_4966;
    s8 **temp_r3_5000;
    s8 **temp_r3_5028;
    s8 *var_r31_5030;

    temp_r3_4966 = this->unk4;
    if ((u32) M2C_FIELD(temp_r3_4966, u32 *, 0x68) == 0U) {
        this->unk40 = 0.0f;
        this->unk3C = 0.0f;
        this->unk30 = 0.0f;
        this->unk2C = 0.0f;
        return;
    }
    temp_r0_4977 = M2C_FIELD(temp_r3_4966, s32 *, 0x78);
    if (temp_r0_4977 != 0) {
        if (temp_r0_4977 > 2) {
            var_f31_4985 = (2.0f * M2C_FIELD(temp_r3_4966, f32 *, 0x80)) + 1.0f;
        } else {
            var_f31_4985 = 1.0f + M2C_FIELD(temp_r3_4966, f32 *, 0x80);
        }
    } else {
        var_f31_4985 = 0.0f;
    }
    if (IsFlagSet(0x100U) != 0) {
        temp_r3_5000 = this->unk4;
        temp_r0_5001 = M2C_FIELD(temp_r3_5000, s32 *, 0x78);
        if (temp_r0_5001 != 0) {
            if (temp_r0_5001 > 2) {
                var_f2_5009 = (2.0f * M2C_FIELD(temp_r3_5000, f32 *, 0x80)) + 1.0f;
            } else {
                var_f2_5009 = 1.0f + M2C_FIELD(temp_r3_5000, f32 *, 0x80);
            }
        } else {
            var_f2_5009 = 0.0f;
        }
        var_f30_5021 = -((2.0f * var_f2_5009) - M2C_FIELD(temp_r3_5000, f32 *, 0x3C));
    } else {
        var_f30_5021 = M2C_FIELD(this->unk4, f32 *, 0x6C);
    }
    temp_r3_5028 = this->unk4;
    temp_f29_5029 = 2.0f * var_f31_4985;
    var_r31_5030 = this->unk28;
    temp_f31_5034 = M2C_FIELD(temp_r3_5028, f32 *, 0x38) - temp_f29_5029;
    temp_f28_5035 = M2C_FIELD(temp_r3_5028, f32 *, 0x3C) - temp_f29_5029;
    if (var_r31_5030 != NULL) {

    } else {
        var_r31_5030 = gpDebugFont;
    }
    if (IsFlagSet(0x200U) != 0) {
        MKFont_GetCharPosJustified(&sp18, var_r31_5030, M2C_FIELD(this->unk4, s32 *, 0x68), temp_f31_5034, temp_f28_5035, (FontJustify) this->unk44, var_f30_5021);
        sp28 = M2C_BITWISE(f64, sp18);
        sp30 = M2C_BITWISE(f64, sp18.unk8);
        if ((f32) sp28 > temp_f31_5034) {
            sp28 = temp_f31_5034;
        }
    } else {
        MKFont_GetCharPos(&sp8, var_r31_5030, M2C_FIELD(this->unk4, s32 *, 0x68), var_f30_5021);
        sp28 = M2C_BITWISE(f64, sp8);
        sp30 = M2C_BITWISE(f64, sp8.unk8);
    }
    this->unk3C = (f32) sp28;
    this->unk40 = unksp2C;
    temp_f1_5082 = this->unk40;
    if (temp_f1_5082 < this->unk30) {
        this->unk30 = temp_f1_5082;
    }
    temp_f3_5091 = this->unk40;
    temp_f2_5092 = M2C_FIELD(this->unk4, f32 *, 0x3C) - temp_f29_5029;
    if (temp_f3_5091 > ((this->unk30 + temp_f2_5092) - var_f30_5021)) {
        this->unk30 = (temp_f3_5091 + var_f30_5021) - temp_f2_5092;
    }
    temp_f1_5101 = this->unk3C;
    temp_f0_5102 = this->unk2C;
    if (temp_f1_5101 < temp_f0_5102) {
        this->unk2C = temp_f1_5101;
        return;
    }
    if (temp_f1_5101 > (temp_f0_5102 + temp_f31_5034)) {
        this->unk2C = temp_f1_5101 - temp_f31_5034;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKHeap *' to
s32 MKWidgetTextBox::GetCharIndexFromPoint(const MKVector3 &arg0) {
    f32 temp_f1_5279;
    f32 temp_f28_5237;
    f32 var_f29_5218;
    f32 var_f29_5268;
    f32 var_f2_5192;
    f32 var_f30_5204;
    f32 var_f31_5168;
    s32 temp_r0_5160;
    s32 temp_r0_5184;
    s32 var_r27_5269;
    s32 var_r28_5226;
    s32 var_r29_5240;
    s32 var_r29_5261;
    s8 **temp_r3_5146;
    s8 **temp_r3_5183;
    s8 *var_r30_5235;
    s8 *var_r31_5153;

    temp_r3_5146 = this->unk4;
    if ((u32) M2C_FIELD(temp_r3_5146, u32 *, 0x68) == 0U) {
        return 0;
    }
    var_r31_5153 = this->unk28;
    if (var_r31_5153 != NULL) {

    } else {
        var_r31_5153 = gpDebugFont;
    }
    temp_r0_5160 = M2C_FIELD(temp_r3_5146, s32 *, 0x78);
    if (temp_r0_5160 != 0) {
        if (temp_r0_5160 > 2) {
            var_f31_5168 = (2.0f * M2C_FIELD(temp_r3_5146, f32 *, 0x80)) + 1.0f;
        } else {
            var_f31_5168 = 1.0f + M2C_FIELD(temp_r3_5146, f32 *, 0x80);
        }
    } else {
        var_f31_5168 = 0.0f;
    }
    if (IsFlagSet(0x100U) != 0) {
        temp_r3_5183 = this->unk4;
        temp_r0_5184 = M2C_FIELD(temp_r3_5183, s32 *, 0x78);
        if (temp_r0_5184 != 0) {
            if (temp_r0_5184 > 2) {
                var_f2_5192 = (2.0f * M2C_FIELD(temp_r3_5183, f32 *, 0x80)) + 1.0f;
            } else {
                var_f2_5192 = 1.0f + M2C_FIELD(temp_r3_5183, f32 *, 0x80);
            }
        } else {
            var_f2_5192 = 0.0f;
        }
        var_f30_5204 = -((2.0f * var_f2_5192) - M2C_FIELD(temp_r3_5183, f32 *, 0x3C));
    } else {
        var_f30_5204 = M2C_FIELD(this->unk4, f32 *, 0x6C);
    }
    if (IsFlagSet(0x200U) != 0) {
        var_f29_5218 = -((2.0f * var_f31_5168) - M2C_FIELD(this->unk4, f32 *, 0x38));
    } else {
        var_f29_5218 = 0.0f;
    }
    var_r28_5226 = 0;
    var_r30_5235 = M2C_FIELD(this->unk4, s8 **, 0x68);
    temp_f28_5237 = (this->unk2C + arg0.unk0) - var_f31_5168;
    var_r29_5240 = (s32) ((this->unk30 + arg0.unk4) - var_f31_5168) / (s32) var_f30_5204;
loop_23:
    if (var_r29_5240 != 0) {
        MKFont_GetNextWrapPoint((MKFont *) var_r31_5153, var_r30_5235, var_f29_5218, var_f30_5204, NULL);
        var_r28_5226 += M2C_ERROR(/* Read from unset register $r3 */);
        var_r30_5235 = &var_r30_5235[M2C_ERROR(/* Read from unset register $r3 */)];
        var_r29_5240 -= 1;
        goto loop_23;
    }
    MKFont_GetNextWrapPoint((MKFont *) var_r31_5153, var_r30_5235, var_f29_5218, var_f30_5204, NULL);
    var_r29_5261 = M2C_ERROR(/* Read from unset register $r3 */);
    if ((s32) M2C_FIELD(&var_r30_5235[var_r29_5261], u8 *, -1) == 0xA) {
        var_r29_5261 -= 1;
    }
    var_f29_5268 = 0.0f;
    var_r27_5269 = 0;
loop_29:
    if (var_r27_5269 < var_r29_5261) {
        temp_f1_5279 = MKFont_CalculateWidth((MKFont *) var_r31_5153, &var_r30_5235[var_r27_5269], var_f30_5204, 0.0f, 1, NULL);
        if (!(temp_f28_5237 < ((0.4f * temp_f1_5279) + var_f29_5268))) {
            var_f29_5268 += temp_f1_5279;
            var_r28_5226 += 1;
            var_r27_5269 += 1;
            goto loop_29;
        }
    }
    return var_r28_5226;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKHeap *' to
void MKWidgetTextBox::Render(MKWidgetRenderContext *arg0) {
    f64 sp260;
    f64 sp258;
    f64 sp250;
    f64 sp248;
    f64 sp240;
    f64 sp238;
    f64 sp230;
    f64 sp228;
    f64 sp220;
    f64 sp218;                                      /* compiler-managed */
    f64 sp210;
    f64 sp208;
    f64 sp200;
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    M2C_UNK sp1A8;
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    MKFont sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f32 sp100;
    f32 spFC;
    f32 spF8;
    f32 spF0;
    f32 spEC;
    f32 spE8;
    f32 spE0;
    f32 spDC;
    f32 spD8;
    f32 spD0;
    f32 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA0;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp80;
    f32 sp70;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp10;
    MKVector4 *temp_r31_5380;
    f32 temp_f1_5800;
    f32 temp_f27_5359;
    f32 temp_f27_5508;
    f32 temp_f28_5512;
    f32 temp_f4_5702;
    f32 temp_f4_5803;
    f32 var_f29_5501;
    f32 var_f2_5475;
    f32 var_f30_5487;
    f32 var_f31_5338;
    s32 temp_r0_5330;
    s32 temp_r0_5467;
    s32 temp_r26_5673;
    s32 temp_r27_5370;
    s32 temp_r3_5366;
    s32 temp_r3_5607;
    s32 var_r0_5606;
    s32 var_r27_5626;
    s32 var_r28_5611;
    s32 var_r5_5405;
    s32 var_r5_5681;
    s8 **temp_r28_5365;
    s8 **temp_r3_5329;
    s8 **temp_r3_5466;
    s8 *var_r28_5637;
    s8 *var_r31_5509;
    void *var_r3_5643;

    MKWidget::Render(arg0);
    MKMaterial_SetMaterial(pWidgetBlank);
    temp_r3_5329 = this->unk4;
    temp_r0_5330 = M2C_FIELD(temp_r3_5329, s32 *, 0x78);
    if (temp_r0_5330 != 0) {
        if (temp_r0_5330 > 2) {
            var_f31_5338 = (2.0f * M2C_FIELD(temp_r3_5329, f32 *, 0x80)) + 1.0f;
        } else {
            var_f31_5338 = 1.0f + M2C_FIELD(temp_r3_5329, f32 *, 0x80);
        }
    } else {
        var_f31_5338 = 0.0f;
    }
    if ((temp_r0_5330 != 0) || (IsFlagSet(0x4000U) != 0)) {
        temp_f27_5359 = var_f31_5338 - 1.0f;
        MKPrimitive(4, 0);
        MKSetBaseColorV(arg0->unk40);
        MKSetMatrix(*((Matrix *) arg0));
        temp_r28_5365 = this->unk4;
        temp_r3_5366 = M2C_FIELD(temp_r28_5365, s32 *, 0x78);
        if (temp_r3_5366 != 0) {
            temp_r27_5370 = temp_r3_5366 - 1;
            sp100 = 0.0f;
            spF8 = 0.0f;
            spFC = 0.0f;
            sp200 = (f64) sp100;
            sp1F8 = (f64) spF8;
            temp_r31_5380 = MKWidget_GetMetric(1);
            WidgetDrawBevel(*((MKVector3 *) &sp1F8), *(MKVector3 *) (temp_r28_5365 + 0x38), M2C_FIELD(temp_r28_5365, f32 *, 0x80), *(MKWidget_GetMetric(0)), *temp_r31_5380, temp_r27_5370 & 1, (temp_r27_5370 >> 1) != 0);
        }
        if (IsFlagSet(0x4000U) != 0) {
            if (IsFlagSet(1U) != 0) {
                var_r5_5405 = M2C_FIELD(this->unk4, s32 *, 0x7C);
            } else {
                var_r5_5405 = 0x22;
            }
            spD8 = temp_f27_5359;
            spDC = temp_f27_5359;
            spE0 = 0.0f;
            sp1C8 = (f64) spD8;
            sp1D0 = (f64) spE0;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            spF0 = 0.0f;
            spD0 = M2C_FIELD((this->unk4 + 0x38), f32 *, 8) - (f32) sp1D0;
            spE8 = temp_f27_5359;
            spEC = temp_f27_5359;
            sp1D8 = spC8;
            sp1E0 = (f64) spD0;
            sp1E8 = (f64) spE8;
            sp1F0 = (f64) spF0;
            WidgetDrawBox(*((MKVector3 *) &sp1E8), *((MKVector3 *) &sp1D8), var_r5_5405);
        }
        MKEndPrimitive();
    }
    if ((s8 *) M2C_FIELD(this->unk4, s8 **, 0x68) != NULL) {
        spC0 = 0.0f;
        spB8 = var_f31_5338 - this->unk2C;
        spBC = var_f31_5338 - this->unk30;
        sp240 = (f64) spC0;
        sp238 = (f64) spB8;
        if (IsFlagSet(0x100U) != 0) {
            temp_r3_5466 = this->unk4;
            temp_r0_5467 = M2C_FIELD(temp_r3_5466, s32 *, 0x78);
            if (temp_r0_5467 != 0) {
                if (temp_r0_5467 > 2) {
                    var_f2_5475 = (2.0f * M2C_FIELD(temp_r3_5466, f32 *, 0x80)) + 1.0f;
                } else {
                    var_f2_5475 = 1.0f + M2C_FIELD(temp_r3_5466, f32 *, 0x80);
                }
            } else {
                var_f2_5475 = 0.0f;
            }
            var_f30_5487 = -((2.0f * var_f2_5475) - M2C_FIELD(temp_r3_5466, f32 *, 0x3C));
        } else {
            var_f30_5487 = M2C_FIELD(this->unk4, f32 *, 0x6C);
        }
        if (IsFlagSet(0x200U) != 0) {
            var_f29_5501 = -((2.0f * var_f31_5338) - M2C_FIELD(this->unk4, f32 *, 0x38));
        } else {
            var_f29_5501 = 0.0f;
        }
        temp_f27_5508 = 2.0f * var_f31_5338;
        var_r31_5509 = this->unk28;
        temp_f28_5512 = M2C_FIELD(this->unk4, f32 *, 0x3C) - temp_f27_5508;
        if (var_r31_5509 != NULL) {

        } else {
            var_r31_5509 = gpDebugFont;
        }
        MKVector(var_f31_5338, var_f31_5338, 0.0f);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        spA8 = temp_f27_5508;
        sp20 = arg0->unk38 + sp1B0;
        spAC = temp_f27_5508;
        spB0 = 0.0f;
        sp248 = sp18;
        sp250 = (f64) sp20;
        sp188 = (f64) spA8;
        sp1B8 = sp18;
        sp1C0 = (f64) sp20;
        sp190 = (f64) spB0;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp198 = sp98;
        spA0 = M2C_FIELD((this->unk4 + 0x38), f32 *, 8) - (f32) sp190;
        sp1A0 = (f64) spA0;
        sp88 = ((f32) sp1A0 * arg0->unk20) + (((f32) sp198 * arg0->unk0) + (unksp19C * arg0->unk10));
        sp8C = ((f32) sp1A0 * arg0->unk24) + (((f32) sp198 * arg0->unk4) + (unksp19C * arg0->unk14));
        sp90 = ((f32) sp1A0 * arg0->unk28) + (((f32) sp198 * arg0->unk8) + (unksp19C * arg0->unk18));
        sp228 = (f64) sp88;
        sp230 = (f64) sp90;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp178 = sp8;
        sp258 = sp8;
        sp10 = (f32) sp250 + (f32) sp230;
        sp180 = (f64) sp10;
        sp260 = (f64) sp10;
        if (PushScissorRect((MKWidgetScissorRect *) &sp248) != 0) {
            var_r0_5606 = this->unk48;
            temp_r3_5607 = this->unk44;
            if (var_r0_5606 != temp_r3_5607) {
                var_r28_5611 = var_r0_5606;
                if (temp_r3_5607 < var_r0_5606) {
                    var_r28_5611 = temp_r3_5607;
                }
                if (temp_r3_5607 > var_r0_5606) {
                    var_r0_5606 = temp_r3_5607;
                }
                var_r27_5626 = var_r0_5606 - var_r28_5611;
                MKFont_GetCharPosJustified(&sp168, var_r31_5509, (s32) M2C_FIELD(this->unk4, s8 **, 0x68), var_f29_5501, temp_f28_5512, (FontJustify) var_r28_5611, var_f30_5487);
                sp218 = M2C_BITWISE(f64, sp168);
                var_r28_5637 = M2C_FIELD(this->unk4, s8 **, 0x68) + var_r28_5611;
                sp220 = M2C_BITWISE(f64, sp168.unk8);
                if (IsFlagSet(8U) != 0) {
                    var_r3_5643 = MKWidget_GetMetric(4);
                } else {
                    var_r3_5643 = MKWidget_GetMetric(5);
                }
                sp208 = M2C_FIELD(var_r3_5643, f64 *, 0);
                sp210 = M2C_FIELD(var_r3_5643, f64 *, 8);
                MKMaterial_SetMaterial(pWidgetBlank);
                MKPrimitive(4, 0);
                MKSetBaseColorV(arg0->unk40);
                MKSetMatrix(*((Matrix *) arg0));
loop_45:
                if (var_r27_5626 > 0) {
                    MKFont_GetNextWrapPoint((MKFont *) var_r31_5509, var_r28_5637, var_f29_5501 - (f32) sp218, var_f30_5487, NULL);
                    temp_r26_5673 = M2C_ERROR(/* Read from unset register $r3 */);
                    if ((s32) (u8) *var_r28_5637 != 0xA) {
                        var_r5_5681 = var_r27_5626;
                        if (temp_r26_5673 < var_r27_5626) {
                            var_r5_5681 = temp_r26_5673;
                        }
                        sp58 = MKFont_CalculateWidth((MKFont *) var_r31_5509, var_r28_5637, var_f30_5487, 0.0f, var_r5_5681, NULL);
                        sp5C = var_f30_5487;
                        sp60 = 0.0f;
                        sp128 = (f64) sp58;
                        sp130 = (f64) sp60;
                        M2C_ERROR(/* unknown instruction: ps_add $f0, $f5, $f3 */);
                        temp_f4_5702 = (f32) sp240 + (f32) sp220;
                        sp138 = sp68;
                        sp70 = temp_f4_5702;
                        sp140 = (f64) sp70;
                        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                        M2C_ERROR(/* unknown instruction: ps_add $f0, $f5, $f3 */);
                        sp148 = sp48;
                        sp50 = (f32) sp140 + (f32) sp130;
                        sp150 = (f64) sp50;
                        sp80 = temp_f4_5702;
                        sp158 = sp78;
                        sp160 = (f64) sp80;
                        WidgetDrawBox(*((MKVector3 *) &sp158), *((MKVector3 *) &sp148), *((MKVector4 *) &sp208));
                    }
                    var_r27_5626 -= temp_r26_5673;
                    sp218 = 0.0f;
                    var_r28_5637 = &var_r28_5637[temp_r26_5673];
                    unksp21C += var_f30_5487;
                    goto loop_45;
                }
                MKEndPrimitive();
            }
            if (IsFlagSet(0x200U) != 0) {
                MKFont_DrawStringJustified((MKFont *) var_r31_5509, M2C_FIELD(this->unk4, s8 **, 0x68), *((MKVector3 *) &sp238), var_f29_5501, temp_f28_5512, (FontJustify) 0, var_f30_5487, arg0->unk40, -1, *((Matrix *) arg0));
            } else {
                MKFont_DrawString((MKFont *) var_r31_5509, M2C_FIELD(this->unk4, s8 **, 0x68), *((MKVector3 *) &sp238), var_f30_5487, arg0->unk40, -1, *((Matrix *) arg0));
            }
            if ((MKWidget_GetFocus() == this) && (IsFlagSet(0x800U) != 0) && (IsFlagSet(0x1000U) == 0)) {
                MKMaterial_SetMaterial(pWidgetBlank);
                MKPrimitive(4, 0);
                MKSetBaseColorV(arg0->unk40);
                MKSetMatrix(*((Matrix *) arg0));
                temp_f1_5800 = (f32) sp238 + this->unk3C;
                temp_f4_5803 = unksp23C + this->unk40;
                sp30 = 0.0f;
                sp40 = 0.0f;
                sp28 = 1.0f + temp_f1_5800;
                sp2C = var_f30_5487 + temp_f4_5803;
                sp38 = temp_f1_5800 - 1.0f;
                sp3C = temp_f4_5803;
                sp108 = (f64) sp28;
                sp110 = (f64) sp30;
                sp118 = (f64) sp38;
                sp120 = (f64) sp40;
                WidgetDrawBox(*((MKVector3 *) &sp118), *((MKVector3 *) &sp108), identity);
                MKEndPrimitive();
            }
            PopScissorRect();
        }
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
s32 MKWidgetTextBox::MessageHandler(unsigned int arg0, unsigned int arg1) {
    s32 spD4;
    s8 *spD0;
    s16 spCE;
    s16 spCC;
    MKWidgetTextBox *spC8;
    s32 spC4;
    s8 *spC0;
    s16 spBE;
    s16 spBC;
    MKWidgetTextBox *spB8;
    MKVector3 spA8;
    MKVector3 sp98;
    s32 sp94;
    s8 *sp90;
    s16 sp8E;
    s16 sp8C;
    MKWidgetTextBox *sp88;
    s32 sp84;
    s8 *sp80;
    s16 sp7E;
    s16 sp7C;
    MKWidgetTextBox *sp78;
    s32 sp74;
    s8 *sp70;
    s16 sp6E;
    s16 sp6C;
    MKWidgetTextBox *sp68;
    s32 sp64;
    s8 *sp60;
    s16 sp5E;
    s16 sp5C;
    MKWidgetTextBox *sp58;
    MKVector3 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKHeap *temp_r3_5994;
    MKHeap *temp_r3_6014;
    f32 temp_f1_6743;
    f32 temp_f1_6989;
    f32 temp_ret_5927;
    f32 var_f1_5927;
    f32 var_f2_6900;
    f32 var_f31_6876;
    f32 var_f5_6912;
    s32 temp_r0_6369;
    s32 temp_r0_6456;
    s32 temp_r0_6565;
    s32 temp_r0_6663;
    s32 temp_r0_6728;
    s32 temp_r0_6746;
    s32 temp_r0_6868;
    s32 temp_r0_6892;
    s32 temp_r0_7036;
    s32 temp_r24_5937;
    s32 temp_r24_6140;
    s32 temp_r25_5909;
    s32 temp_r27_6384;
    s32 temp_r28_5882;
    s32 temp_r3_6292;
    s32 temp_r4_6177;
    s32 temp_r4_6285;
    s32 temp_r4_6564;
    s32 temp_r4_6605;
    s32 temp_r5_6562;
    s32 temp_r6_6237;
    s32 temp_r6_7002;
    s32 var_r0_5877;
    s32 var_r0_5904;
    s32 var_r0_5931;
    s32 var_r0_6657;
    s32 var_r25_6457;
    s32 var_r25_6719;
    s32 var_r25_6747;
    s32 var_r25_7038;
    s32 var_r26_5864;
    s32 var_r26_5891;
    s32 var_r26_5918;
    s32 var_r26_6370;
    s32 var_r26_6460;
    s32 var_r26_6613;
    s32 var_r26_6750;
    s32 var_r26_7041;
    s32 var_r27_6227;
    s32 var_r28_6373;
    s32 var_r3_6662;
    s32 var_r8_6176;
    s8 **temp_r25_6410;
    s8 **temp_r25_6786;
    s8 **temp_r25_6808;
    s8 **temp_r26_6013;
    s8 **temp_r26_6055;
    s8 **temp_r26_6101;
    s8 **temp_r26_7073;
    s8 **temp_r27_6330;
    s8 **temp_r27_6758;
    s8 **temp_r27_7049;
    s8 **temp_r3_5990;
    s8 **temp_r3_6475;
    s8 **temp_r3_6767;
    s8 **temp_r3_6891;
    s8 **temp_r4_6782;
    s8 **temp_r4_6802;
    s8 **temp_r4_7013;
    s8 **temp_r4_7062;
    s8 **temp_r4_7092;
    s8 **temp_r8_6419;
    s8 *temp_r26_5991;
    s8 *temp_r26_6488;
    s8 *temp_r27_6484;
    s8 *temp_r3_6096;
    s8 *temp_r3_6331;
    s8 *temp_r7_6179;
    s8 *temp_r7_6612;
    s8 *temp_ret_6383;
    s8 *var_r26_6225;
    s8 *var_r27_6673;
    s8 *var_r3_6021;
    s8 *var_r3_6383;
    s8 *var_r4_6387;
    u32 temp_r0_6107;
    u32 temp_r3_6545;
    u32 temp_r3_6803;
    u32 temp_r5_7015;
    u32 var_ctr_7016;
    u32 var_r0_6077;
    u32 var_r28_6561;
    u32 var_r30_5855;
    u32 var_r3_6080;
    u32 var_r3_6726;
    u32 var_r7_7014;
    u8 *var_r28_6448;
    u8 *var_r4_6446;
    u8 *var_r5_6396;
    u8 temp_r3_6496;
    u8 temp_r3_6536;
    u8 temp_r4_6403;
    u8 temp_r5_6240;
    u8 temp_r5_6686;
    u8 temp_r6_6187;
    u8 temp_r6_6624;
    u8 temp_ret_6743;
    u8 temp_ret_6989;
    u8 var_r0_6191;
    u8 var_r0_6203;
    u8 var_r0_6244;
    u8 var_r0_6256;
    u8 var_r0_6628;
    u8 var_r0_6640;
    u8 var_r0_6690;
    u8 var_r0_6702;
    u8 var_r5_6447;
    u8 var_r6_7037;

    var_r30_5855 = arg1;
    if (MKInput_GetState(0xA0, (MKInputDevices) 5, NULL, NULL) != 0.0f) {
        var_r26_5864 = 1;
    } else {
        var_r26_5864 = 0;
    }
    if (MKInput_GetState(0xA1, (MKInputDevices) 5, NULL, NULL) != 0.0f) {
        var_r0_5877 = 1;
    } else {
        var_r0_5877 = 0;
    }
    temp_r28_5882 = var_r26_5864 | var_r0_5877;
    if (MKInput_GetState(0xA4, (MKInputDevices) 5, NULL, NULL) != 0.0f) {
        var_r26_5891 = 1;
    } else {
        var_r26_5891 = 0;
    }
    if (MKInput_GetState(0xA5, (MKInputDevices) 5, NULL, NULL) != 0.0f) {
        var_r0_5904 = 1;
    } else {
        var_r0_5904 = 0;
    }
    temp_r25_5909 = var_r26_5891 | var_r0_5904;
    if (MKInput_GetState(0xA2, (MKInputDevices) 5, NULL, NULL) != 0.0f) {
        var_r26_5918 = 1;
    } else {
        var_r26_5918 = 0;
    }
    temp_ret_5927 = MKInput_GetState(0xA3, (MKInputDevices) 5, NULL, NULL);
    var_f1_5927 = temp_ret_5927;
    if (var_f1_5927 != 0.0f) {
        var_r0_5931 = 1;
    } else {
        var_r0_5931 = 0;
    }
    temp_r24_5937 = var_r26_5918 | var_r0_5931;
    switch ((s32) arg0) {                           /* switch 1; irregular */
    case 0x66:                                      /* switch 1 */
        temp_r3_5990 = this->unk4;
        temp_r26_5991 = M2C_FIELD(temp_r3_5990, s8 **, 0x68);
        if (temp_r26_5991 != NULL) {
            temp_r3_5994 = temp_r3_5990->Current();
            if (temp_r3_5994 != NULL) {
                ((MKHeap *) (temp_r3_5994->Current()))->Free(temp_r26_5991, NULL, 0);
            } else {
                free(temp_r26_5991);
            }
            M2C_FIELD(this->unk4, s8 **, 0x68) = NULL;
        }
        if (var_r30_5855 != 0) {
            temp_r26_6013 = this->unk4;
            temp_r3_6014 = this->unk4->Current();
            if (temp_r3_6014 != NULL) {
                var_r3_6021 = ((MKHeap *) (temp_r3_6014->Current()))->Alloc((s32) var_r30_5855, NULL, 0);
            } else {
                var_r3_6021 = malloc(var_r30_5855);
            }
            M2C_FIELD(temp_r26_6013, s8 **, 0x68) = var_r3_6021;
            *M2C_FIELD(this->unk4, s8 **, 0x68) = 0;
        }
        M2C_FIELD(this->unk4, u32 *, 0x70) = var_r30_5855;
        this->unk44 = 0;
        this->unk40 = 0.0f;
        this->unk3C = 0.0f;
        this->unk30 = 0.0f;
        this->unk2C = 0.0f;
block_293:
    default:                                        /* switch 1 */
        return MKWidget::MessageHandler(arg0, var_r30_5855);
    case 0x65:                                      /* switch 1 */
        M2C_FIELD(this->unk4, f32 *, 0x6C) = M2C_BITWISE(f32, *var_r30_5855);
        goto block_293;
    case 0x67:                                      /* switch 1 */
        if ((s8 *) M2C_FIELD(this->unk4, s8 **, 0x68) != NULL) {
            strcat(var_r30_5855);
            temp_r26_6055 = this->unk4;
            M2C_FIELD(temp_r26_6055, s32 *, 0x74) = (s32) (M2C_FIELD(temp_r26_6055, s32 *, 0x74) + strlen((s8 *) var_r30_5855));
            spC8 = this;
            spCC = 1;
            spCE = 0;
            spD0 = M2C_FIELD(this->unk4, s8 **, 0x68);
            spD4 = 0;
            MKWidget_SendMessage((MKWidget *) this, 0x39U, (u32) &spC8);
        }
        goto block_293;
    case 0x68:                                      /* switch 1 */
        var_r0_6077 = var_r30_5855;
        var_r3_6080 = M2C_FIELD(this->unk4, u32 *, 0x74);
        if ((s32) lit_2215 > (s32) var_r30_5855) {
            var_r0_6077 = (u32) lit_2215;
        }
        if ((s32) var_r0_6077 < (s32) var_r3_6080) {
            var_r3_6080 = var_r0_6077;
        }
        this->unk44 = (s32) var_r3_6080;
        this->unk48 = (s32) var_r3_6080;
        return (s32) var_r3_6080;
    case 0x17:                                      /* switch 1 */
        temp_r3_6096 = M2C_FIELD(this->unk4, s8 **, 0x68);
        if (temp_r3_6096 != NULL) {
            strcpy(temp_r3_6096, (s8 *) var_r30_5855);
            temp_r26_6101 = this->unk4;
            M2C_FIELD(temp_r26_6101, u32 *, 0x74) = strlen(M2C_FIELD(temp_r26_6101, s8 **, 0x68));
            temp_r0_6107 = M2C_FIELD(this->unk4, u32 *, 0x74);
            this->unk44 = (s32) temp_r0_6107;
            this->unk48 = (s32) temp_r0_6107;
            FindCaretPos();
            spB8 = this;
            spBC = 1;
            spBE = 0;
            spC0 = M2C_FIELD(this->unk4, s8 **, 0x68);
            spC4 = 0;
            MKWidget_SendMessage((MKWidget *) this, 0x39U, (u32) &spB8);
        }
        goto block_293;
    case 0x18:                                      /* switch 1 */
        *var_r30_5855 = (s8 *) M2C_FIELD(this->unk4, s8 **, 0x68);
        goto block_293;
    case 0x64:                                      /* switch 1 */
        this->unk28 = (s8 *) var_r30_5855;
        goto block_293;
    case 0x5:                                       /* switch 1 */
        temp_r24_6140 = MKWidget::MessageHandler(arg0, var_r30_5855);
        FindCaretPos();
        return temp_r24_6140;
    case 0x2F:                                      /* switch 1 */
        if (var_r30_5855 == 1) {
            gWidgetCursor = 1;
        } else {
            gWidgetCursor = 0;
        }
        goto block_293;
    case 0x30:                                      /* switch 1 */
        MKWidget_GetLocalMousePos((MKWidget *) this, &spA8);
        this->unk44 = GetCharIndexFromPoint(spA8);
        if (temp_r28_5882 == 0) {
            this->unk48 = this->unk44;
        }
        MKWidget_SetMouseFocus((MKWidget *) this);
        this->unk4C = 1;
        FindCaretPos();
        goto block_293;
    case 0x34:                                      /* switch 1 */
        var_r8_6176 = 0;
        temp_r4_6177 = this->unk44;
        temp_r7_6179 = &M2C_FIELD(this->unk4, s8 **, 0x68)[temp_r4_6177];
loop_81:
        if ((temp_r4_6177 + var_r8_6176) > 0) {
            temp_r6_6187 = M2C_FIELD(&temp_r7_6179[var_r8_6176], u8 *, -1);
            if ((s8) temp_r6_6187 == -1) {
                var_r0_6191 = -1U;
            } else {
                var_r0_6191 = *(&__lower_map + (u8) (s8) temp_r6_6187);
            }
            if ((s32) var_r0_6191 >= 0x61) {
                if ((s8) temp_r6_6187 == -1) {
                    var_r0_6203 = -1U;
                } else {
                    var_r0_6203 = *(&__lower_map + (u8) (s8) temp_r6_6187);
                }
                if ((s32) var_r0_6203 > 0x7A) {
                    goto block_90;
                }
                goto block_80;
            }
block_90:
            if ((((s8) temp_r6_6187 >= 0x30) && ((s8) temp_r6_6187 <= 0x39)) || ((s8) temp_r6_6187 == 0x2E)) {
block_80:
                var_r8_6176 -= 1;
                goto loop_81;
            }
        }
        var_r26_6225 = temp_r7_6179;
        this->unk48 = temp_r4_6177 + var_r8_6176;
        var_r27_6227 = 0;
loop_95:
        temp_r6_6237 = this->unk44 + var_r27_6227;
        if (temp_r6_6237 < strlen(M2C_FIELD(this->unk4, s8 **, 0x68))) {
            temp_r5_6240 = (u8) *var_r26_6225;
            if ((s8) temp_r5_6240 == -1) {
                var_r0_6244 = -1U;
            } else {
                var_r0_6244 = *(&__lower_map + (u8) (s8) temp_r5_6240);
            }
            if ((s32) var_r0_6244 >= 0x61) {
                if ((s8) temp_r5_6240 == -1) {
                    var_r0_6256 = -1U;
                } else {
                    var_r0_6256 = *(&__lower_map + (u8) (s8) temp_r5_6240);
                }
                if ((s32) var_r0_6256 > 0x7A) {
                    goto block_104;
                }
                goto block_94;
            }
block_104:
            if ((((s8) temp_r5_6240 >= 0x30) && ((s8) temp_r5_6240 <= 0x39)) || ((s8) temp_r5_6240 == 0x2E)) {
block_94:
                var_r27_6227 += 1;
                var_r26_6225 += 1;
                goto loop_95;
            }
        }
        this->unk44 = temp_r6_6237;
        if ((s32) this->unk48 == (s32) this->unk44) {
            temp_r4_6285 = this->unk44;
            if (temp_r4_6285 < strlen(M2C_FIELD(this->unk4, s8 **, 0x68))) {
                this->unk44 = temp_r4_6285 + 1;
            } else {
                temp_r3_6292 = this->unk48;
                if (temp_r3_6292 > 0) {
                    this->unk48 = temp_r3_6292 - 1;
                }
            }
        }
        FindCaretPos();
        goto block_293;
    case 0x31:                                      /* switch 1 */
        MKWidget_ReleaseMouseFocus();
        this->unk4C = 0;
        goto block_293;
    case 0x2E:                                      /* switch 1 */
        if ((u8) this->unk4C != 0) {
            MKWidget_GetLocalMousePos((MKWidget *) this, &sp98);
            Max(sp48, sp98);
            sp98 = M2C_BITWISE(f64, sp48);
            sp98.unk8 = (f64) sp48.unk8;
            this->unk44 = GetCharIndexFromPoint(sp98);
            FindCaretPos();
        } else {
        case 0x29:                                  /* switch 1 */
        case 0x2C:                                  /* switch 1 */
            temp_r27_6330 = this->unk4;
            temp_r3_6331 = M2C_FIELD(temp_r27_6330, s8 **, 0x68);
            if (temp_r3_6331 != NULL) {
                switch ((s32) var_r30_5855) {       /* switch 2; irregular */
                case 0x58:                          /* switch 2 */
                case 0x43:                          /* switch 2 */
                    if ((temp_r24_5937 != 0) && ((temp_r25_5909 | temp_r28_5882) == 0)) {
                        temp_r0_6369 = this->unk48;
                        var_r26_6370 = this->unk44;
                        if (temp_r0_6369 != var_r26_6370) {
                            var_r28_6373 = var_r26_6370;
                            if (temp_r0_6369 < var_r26_6370) {
                                var_r28_6373 = temp_r0_6369;
                            }
                            if (temp_r0_6369 > var_r26_6370) {
                                var_r26_6370 = temp_r0_6369;
                            }
                            temp_ret_6383 = Str_Printf(&temp_r3_6331[var_r28_6373], (u32) M2C_BITWISE(u64, temp_ret_5927), var_f1_5927);
                            var_r3_6383 = temp_ret_6383;
                            temp_r27_6384 = var_r26_6370 - var_r28_6373;
                            var_r3_6383[temp_r27_6384] = 0;
                            var_r4_6387 = var_r3_6383;
loop_144:
                            if ((s8) (u8) *var_r4_6387 != 0) {
                                var_r4_6387 += 1;
                                goto loop_144;
                            }
                            var_r5_6396 = &gClipboardBuffer;
loop_147:
                            temp_r4_6403 = (u8) *var_r3_6383;
                            if ((s8) temp_r4_6403 != 0) {
                                *var_r5_6396 = temp_r4_6403;
                                var_r3_6383 += 1;
                                var_r5_6396 += 1;
                                goto loop_147;
                            }
                            *var_r5_6396 = 0;
                            if (var_r30_5855 == 0x58) {
                                temp_r25_6410 = this->unk4;
                                strcpy(&M2C_FIELD(temp_r25_6410, s8 **, 0x68)[var_r28_6373], Str_Printf(&M2C_FIELD(temp_r25_6410, s8 **, 0x68)[var_r26_6370], temp_r4_6403, var_r5_6396, M2C_BITWISE(f32, temp_ret_6383)));
                                temp_r8_6419 = this->unk4;
                                M2C_FIELD(temp_r8_6419, u32 *, 0x74) = (u32) (M2C_FIELD(temp_r8_6419, u32 *, 0x74) - temp_r27_6384);
                                this->unk44 = var_r28_6373;
                                this->unk48 = this->unk44;
                                sp88 = this;
                                sp8C = 1;
                                sp8E = 0;
                                sp90 = M2C_FIELD(this->unk4, s8 **, 0x68);
                                sp94 = 0;
                                MKWidget_SendMessage((MKWidget *) this, 0x39U, (u32) &sp88);
                            }
                        }
                    } else {
                    case 0x56:                      /* switch 2 */
                        if ((temp_r24_5937 != 0) && ((temp_r25_5909 | temp_r28_5882) == 0)) {
                            var_r4_6446 = &gClipboardBuffer;
                            var_r5_6447 = 0;
                            var_r28_6448 = NULL;
                            if ((s8) gClipboardBuffer != 0) {
                                var_r5_6447 = 1;
                                var_r28_6448 = &gClipboardBuffer;
                            }
                            if (var_r5_6447 != 0) {
                                temp_r0_6456 = this->unk48;
                                var_r25_6457 = this->unk44;
                                if (temp_r0_6456 != var_r25_6457) {
                                    var_r26_6460 = var_r25_6457;
                                    if (temp_r0_6456 < var_r25_6457) {
                                        var_r26_6460 = temp_r0_6456;
                                    }
                                    if (temp_r0_6456 > var_r25_6457) {
                                        var_r25_6457 = temp_r0_6456;
                                    }
                                    var_f1_5927 = M2C_BITWISE(f32, strcpy(&M2C_FIELD(temp_r27_6330, s8 **, 0x68)[var_r26_6460], Str_Printf(&temp_r3_6331[var_r25_6457], &gClipboardBuffer, var_r5_6447, var_f1_5927)));
                                    temp_r3_6475 = this->unk4;
                                    var_r4_6446 = var_r25_6457 - var_r26_6460;
                                    M2C_FIELD(temp_r3_6475, u32 *, 0x74) = (u32) (M2C_FIELD(temp_r3_6475, u32 *, 0x74) - var_r4_6446);
                                    this->unk44 = var_r26_6460;
                                }
                                temp_r27_6484 = M2C_FIELD(this->unk4, s8 **, 0x68);
                                temp_r26_6488 = Str_Printf(&temp_r27_6484[this->unk44], var_r4_6446, var_f1_5927);
loop_176:
                                if ((s8) *var_r28_6448 != 0) {
                                    if ((IsFlagSet(0x2000U) != 0) && (((temp_r3_6496 = *var_r28_6448, (((s8) temp_r3_6496 < 0x30) != 0)) && ((s8) temp_r3_6496 > 0x39) && ((s8) temp_r3_6496 != 0x2D) && ((s8) temp_r3_6496 != 0x2E)) || (((s8) temp_r3_6496 == 0x2D) && ((s32) this->unk44 != 0)) || (((s8) temp_r3_6496 == 0x2E) && (strrchr(&temp_r27_6484[this->unk44], 0x2E) != 0U)) || (((s32) *var_r28_6448 == 0x2E) && (strchr(temp_r26_6488, 0x2E) != NULL)))) {
                                        var_r28_6448 += 1;
                                        goto loop_176;
                                    }
                                    temp_r3_6536 = *var_r28_6448;
                                    var_r28_6448 += 1;
                                    temp_r27_6484[this->unk44] = (s8) temp_r3_6536;
                                    this->unk44 += 1;
                                    temp_r3_6545 = M2C_FIELD(this->unk4, u32 *, 0x70);
                                    if ((s32) this->unk44 >= (s32) (temp_r3_6545 - 1)) {
                                        M2C_FIELD(&temp_r27_6484[temp_r3_6545], s8 *, -1) = 0;
                                    } else {
                                        goto loop_176;
                                    }
                                }
                                var_r28_6561 = strlen(temp_r26_6488);
                                temp_r5_6562 = this->unk44;
                                temp_r4_6564 = temp_r5_6562 + var_r28_6561;
                                temp_r0_6565 = M2C_FIELD(this->unk4, u32 *, 0x70) - 1;
                                if (temp_r4_6564 > temp_r0_6565) {
                                    var_r28_6561 -= temp_r4_6564 - temp_r0_6565;
                                    strncpy(&temp_r27_6484[temp_r5_6562], temp_r26_6488, var_r28_6561);
                                    M2C_FIELD(&temp_r27_6484[M2C_FIELD(this->unk4, u32 *, 0x70)], s8 *, -1) = 0;
                                } else {
                                    strcpy(&temp_r27_6484[temp_r5_6562], temp_r26_6488);
                                }
                                M2C_FIELD(this->unk4, u32 *, 0x74) = (u32) (this->unk44 + var_r28_6561);
                                this->unk48 = this->unk44;
                                sp78 = this;
                                sp7C = 1;
                                sp7E = 0;
                                sp80 = temp_r27_6484;
                                sp84 = 0;
                                MKWidget_SendMessage((MKWidget *) this, 0x39U, (u32) &sp78);
                            }
                        } else {
                        default:                    /* switch 2 */
                            temp_r4_6605 = this->unk44;
                            if (((s32) this->unk48 == temp_r4_6605) || (temp_r28_5882 != 0)) {
                                temp_r7_6612 = &temp_r3_6331[temp_r4_6605];
                                var_r26_6613 = 0;
                                if (var_r30_5855 == 0x25) {
                                    if (temp_r24_5937 != 0) {
loop_187:
                                        if ((temp_r4_6605 + var_r26_6613) > 0) {
                                            temp_r6_6624 = M2C_FIELD(&temp_r7_6612[var_r26_6613], u8 *, -1);
                                            if ((s8) temp_r6_6624 == -1) {
                                                var_r0_6628 = -1U;
                                            } else {
                                                var_r0_6628 = *(&__lower_map + (u8) (s8) temp_r6_6624);
                                            }
                                            if ((s32) var_r0_6628 >= 0x61) {
                                                if ((s8) temp_r6_6624 == -1) {
                                                    var_r0_6640 = -1U;
                                                } else {
                                                    var_r0_6640 = *(&__lower_map + (u8) (s8) temp_r6_6624);
                                                }
                                                if ((s32) var_r0_6640 > 0x7A) {
                                                    goto block_196;
                                                }
                                                goto block_186;
                                            }
block_196:
                                            if (((s8) temp_r6_6624 >= 0x30) && ((s8) temp_r6_6624 <= 0x39)) {
block_186:
                                                var_r26_6613 -= 1;
                                                goto loop_187;
                                            }
                                        }
                                    }
                                    var_r0_6657 = lit_2336;
                                    if (var_r26_6613 < var_r0_6657) {
                                        var_r0_6657 = var_r26_6613;
                                    }
                                    var_r3_6662 = lit_2338;
                                    temp_r0_6663 = temp_r4_6605 + var_r0_6657;
                                    if (temp_r0_6663 > var_r3_6662) {
                                        var_r3_6662 = temp_r0_6663;
                                    }
                                    this->unk44 = var_r3_6662;
                                } else {
                                    if (temp_r24_5937 != 0) {
                                        var_r27_6673 = temp_r7_6612;
loop_206:
                                        if ((s32) (this->unk44 + var_r26_6613) < strlen(M2C_FIELD(this->unk4, s8 **, 0x68))) {
                                            temp_r5_6686 = (u8) *var_r27_6673;
                                            if ((s8) temp_r5_6686 == -1) {
                                                var_r0_6690 = -1U;
                                            } else {
                                                var_r0_6690 = *(&__lower_map + (u8) (s8) temp_r5_6686);
                                            }
                                            if ((s32) var_r0_6690 >= 0x61) {
                                                if ((s8) temp_r5_6686 == -1) {
                                                    var_r0_6702 = -1U;
                                                } else {
                                                    var_r0_6702 = *(&__lower_map + (u8) (s8) temp_r5_6686);
                                                }
                                                if ((s32) var_r0_6702 > 0x7A) {
                                                    goto block_215;
                                                }
                                                goto block_205;
                                            }
block_215:
                                            if (((s8) temp_r5_6686 >= 0x30) && ((s8) temp_r5_6686 <= 0x39)) {
block_205:
                                                var_r26_6613 += 1;
                                                var_r27_6673 += 1;
                                                goto loop_206;
                                            }
                                        }
                                    }
                                    var_r25_6719 = lit_2350;
                                    if (var_r26_6613 > var_r25_6719) {
                                        var_r25_6719 = var_r26_6613;
                                    }
                                    var_r3_6726 = strlen(M2C_FIELD(this->unk4, s8 **, 0x68));
                                    temp_r0_6728 = this->unk44 + var_r25_6719;
                                    if (temp_r0_6728 < (s32) var_r3_6726) {
                                        var_r3_6726 = (u32) temp_r0_6728;
                                    }
                                    this->unk44 = (s32) var_r3_6726;
                                }
                            }
                            if (temp_r28_5882 == 0) {
                                this->unk48 = this->unk44;
                            }
                        }
                    }
                    break;
                case 0x2E:                          /* switch 2 */
                case 0x8:                           /* switch 2 */
                    temp_ret_6743 = IsFlagSet(0x800U);
                    temp_f1_6743 = M2C_BITWISE(f32, temp_ret_6743);
                    if (temp_ret_6743 != 0) {
                        temp_r0_6746 = this->unk48;
                        var_r25_6747 = this->unk44;
                        if (temp_r0_6746 != var_r25_6747) {
                            var_r26_6750 = var_r25_6747;
                            if (temp_r0_6746 < var_r25_6747) {
                                var_r26_6750 = temp_r0_6746;
                            }
                            if (temp_r0_6746 > var_r25_6747) {
                                var_r25_6747 = temp_r0_6746;
                            }
                            temp_r27_6758 = this->unk4;
                            strcpy(&M2C_FIELD(temp_r27_6758, s8 **, 0x68)[var_r26_6750], Str_Printf(&M2C_FIELD(temp_r27_6758, s8 **, 0x68)[var_r25_6747], (u32) (u64) temp_ret_6743, temp_f1_6743));
                            temp_r3_6767 = this->unk4;
                            M2C_FIELD(temp_r3_6767, u32 *, 0x74) = (u32) (M2C_FIELD(temp_r3_6767, u32 *, 0x74) - (var_r25_6747 - var_r26_6750));
                            this->unk44 = var_r26_6750;
                        } else if ((var_r30_5855 == 8) && (var_r25_6747 > 0)) {
                            this->unk44 = var_r25_6747 - 1;
                            temp_r4_6782 = this->unk4;
                            M2C_FIELD(temp_r4_6782, u32 *, 0x74) = (u32) (M2C_FIELD(temp_r4_6782, u32 *, 0x74) - 1);
                            temp_r25_6786 = this->unk4;
                            strcpy(&M2C_FIELD(temp_r25_6786, s8 **, 0x68)[this->unk44], Str_Printf(&M2C_FIELD(temp_r25_6786, s8 **, 0x68)[this->unk44] + 1, temp_r4_6782, temp_f1_6743));
                        } else if (var_r30_5855 == 0x2E) {
                            temp_r4_6802 = this->unk4;
                            temp_r3_6803 = M2C_FIELD(temp_r4_6802, u32 *, 0x74);
                            if (var_r25_6747 < (s32) temp_r3_6803) {
                                M2C_FIELD(temp_r4_6802, u32 *, 0x74) = (u32) (temp_r3_6803 - 1);
                                temp_r25_6808 = this->unk4;
                                strcpy(&M2C_FIELD(temp_r25_6808, s8 **, 0x68)[this->unk44], Str_Printf(&M2C_FIELD(temp_r25_6808, s8 **, 0x68)[this->unk44] + 1, temp_r4_6802, temp_f1_6743));
                            }
                        }
                        this->unk48 = this->unk44;
                        if (1 != 0) {
                            sp68 = this;
                            sp6C = 1;
                            sp6E = 0;
                            sp70 = M2C_FIELD(this->unk4, s8 **, 0x68);
                            sp74 = 0;
                            MKWidget_SendMessage((MKWidget *) this, 0x39U, (u32) &sp68);
                        }
                    }
                    break;
                case 0x26:                          /* switch 2 */
                    sp20 = 0.0f;
                    sp1C = (this->unk40 - this->unk30) - 1.0f;
                    sp18 = this->unk3C - this->unk2C;
                    sp40 = (f64) sp20;
                    sp38 = (f64) sp18;
                    this->unk44 = GetCharIndexFromPoint(*((MKVector3 *) &sp38));
                    if (temp_r28_5882 == 0) {
                        this->unk48 = this->unk44;
                    }
                    break;
                case 0x28:                          /* switch 2 */
                    temp_r0_6868 = M2C_FIELD(temp_r27_6330, s32 *, 0x78);
                    if (temp_r0_6868 != 0) {
                        if (temp_r0_6868 > 2) {
                            var_f31_6876 = (2.0f * M2C_FIELD(temp_r27_6330, f32 *, 0x80)) + 1.0f;
                        } else {
                            var_f31_6876 = 1.0f + M2C_FIELD(temp_r27_6330, f32 *, 0x80);
                        }
                    } else {
                        var_f31_6876 = 0.0f;
                    }
                    if (IsFlagSet(0x100U) != 0) {
                        temp_r3_6891 = this->unk4;
                        temp_r0_6892 = M2C_FIELD(temp_r3_6891, s32 *, 0x78);
                        if (temp_r0_6892 != 0) {
                            if (temp_r0_6892 > 2) {
                                var_f2_6900 = (2.0f * M2C_FIELD(temp_r3_6891, f32 *, 0x80)) + 1.0f;
                            } else {
                                var_f2_6900 = 1.0f + M2C_FIELD(temp_r3_6891, f32 *, 0x80);
                            }
                        } else {
                            var_f2_6900 = 0.0f;
                        }
                        var_f5_6912 = -((2.0f * var_f2_6900) - M2C_FIELD(temp_r3_6891, f32 *, 0x3C));
                    } else {
                        var_f5_6912 = M2C_FIELD(this->unk4, f32 *, 0x6C);
                    }
                    sp10 = 0.0f;
                    sp8 = (var_f31_6876 + this->unk3C) - this->unk2C;
                    sp30 = (f64) sp10;
                    spC = 1.0f + (var_f5_6912 + ((var_f31_6876 + this->unk40) - this->unk30));
                    sp28 = (f64) sp8;
                    this->unk44 = GetCharIndexFromPoint(*((MKVector3 *) &sp28));
                    if (temp_r28_5882 == 0) {
                        this->unk48 = this->unk44;
                    }
                    break;
                case 0x24:                          /* switch 2 */
                    this->unk44 = 0;
                    if (temp_r28_5882 == 0) {
                        this->unk48 = this->unk44;
                    }
                    break;
                case 0x23:                          /* switch 2 */
                    this->unk44 = strlen(temp_r3_6331);
                    if (temp_r28_5882 == 0) {
                        this->unk48 = this->unk44;
                    }
                    break;
                }
                FindCaretPos();
            }
        }
        goto block_293;
    case 0x2D:                                      /* switch 1 */
        if ((IsFlagSet(0x800U) != 0) && ((temp_r24_5937 | temp_r25_5909) == 0) && ((var_r30_5855 >= 0x20U) || ((var_r30_5855 == 0xD) && (IsFlagSet(0x400U) != 0)))) {
            if (var_r30_5855 == 0xD) {
                var_r30_5855 = 0xA;
            }
            temp_ret_6989 = IsFlagSet(0x2000U);
            temp_f1_6989 = M2C_BITWISE(f32, temp_ret_6989);
            if (temp_ret_6989 != 0) {
                if ((((var_r30_5855 >= 0x30U) && (var_r30_5855 <= 0x39U)) || (var_r30_5855 == 0x2E) || (var_r30_5855 == 0x2D)) && ((temp_r6_7002 = this->unk44, ((temp_r6_7002 == 0) == 0)) || ((s32) (u8) *M2C_FIELD(this->unk4, s8 **, 0x68) != 0x2D))) {
                    if (var_r30_5855 == 0x2E) {
                        temp_r4_7013 = this->unk4;
                        var_r7_7014 = 0U;
                        temp_r5_7015 = M2C_FIELD(temp_r4_7013, u32 *, 0x74);
                        var_ctr_7016 = temp_r5_7015;
                        if (temp_r5_7015 > 0U) {
loop_278:
                            if ((s8) (u8) M2C_FIELD(temp_r4_7013, s8 **, 0x68)[var_r7_7014] != 0x2E) {
                                var_r7_7014 += 1;
                                var_ctr_7016 -= 1;
                                if (var_ctr_7016 != 0) {
                                    goto loop_278;
                                }
                            }
                        }
                        if (var_r7_7014 >= temp_r5_7015) {
                            goto block_281;
                        }
                    } else {
block_281:
                        if ((var_r30_5855 != 0x2D) || (temp_r6_7002 == 0)) {
                            goto block_283;
                        }
                    }
                }
            } else {
block_283:
                temp_r0_7036 = this->unk48;
                var_r6_7037 = 0;
                var_r25_7038 = this->unk44;
                if (temp_r0_7036 != var_r25_7038) {
                    var_r26_7041 = var_r25_7038;
                    if (temp_r0_7036 < var_r25_7038) {
                        var_r26_7041 = temp_r0_7036;
                    }
                    if (temp_r0_7036 > var_r25_7038) {
                        var_r25_7038 = temp_r0_7036;
                    }
                    temp_r27_7049 = this->unk4;
                    strcpy(&M2C_FIELD(temp_r27_7049, s8 **, 0x68)[var_r26_7041], Str_Printf("", var_r30_5855, &M2C_FIELD(temp_r27_7049, s8 **, 0x68)[var_r25_7038], 0U, temp_f1_6989));
                    temp_r4_7062 = this->unk4;
                    var_r6_7037 = 1;
                    M2C_FIELD(temp_r4_7062, u32 *, 0x74) = (u32) (M2C_FIELD(temp_r4_7062, u32 *, 0x74) - ((var_r25_7038 - var_r26_7041) - 1));
                    this->unk44 = var_r26_7041 + 1;
                } else {
                    temp_r26_7073 = this->unk4;
                    if ((u32) M2C_FIELD(temp_r26_7073, u32 *, 0x74) < (u32) (M2C_FIELD(temp_r26_7073, u32 *, 0x70) - 1)) {
                        strcpy(&M2C_FIELD(temp_r26_7073, s8 **, 0x68)[this->unk44], Str_Printf("", var_r30_5855, &M2C_FIELD(temp_r26_7073, s8 **, 0x68)[var_r25_7038], 0U, temp_f1_6989));
                        temp_r4_7092 = this->unk4;
                        var_r6_7037 = 1;
                        M2C_FIELD(temp_r4_7092, u32 *, 0x74) = (u32) (M2C_FIELD(temp_r4_7092, u32 *, 0x74) + 1);
                        this->unk44 += 1;
                    }
                }
                if (var_r6_7037 != 0) {
                    this->unk48 = this->unk44;
                    FindCaretPos();
                    sp58 = this;
                    sp5C = 1;
                    sp5E = 0;
                    sp60 = M2C_FIELD(this->unk4, s8 **, 0x68);
                    sp64 = 0;
                    MKWidget_SendMessage((MKWidget *) this, 0x39U, (u32) &sp58);
                }
            }
        }
        goto block_293;
    case 0x69:                                      /* switch 1 */
        return this->unk44;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKHeap *' to
MKWidgetTextBox::~MKWidgetTextBox() {
    MKHeap *temp_r3_7152;
    s8 **temp_r3_7148;
    s8 *temp_r31_7149;

    if (this != NULL) {
        temp_r3_7148 = this->unk4;
        temp_r31_7149 = M2C_FIELD(temp_r3_7148, s8 **, 0x68);
        if (temp_r31_7149 != NULL) {
            temp_r3_7152 = temp_r3_7148->Current();
            if (temp_r3_7152 != NULL) {
                ((MKHeap *) (temp_r3_7152->Current()))->Free(temp_r31_7149, NULL, 0);
            } else {
                free(temp_r31_7149);
            }
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKHeap *' to
MKWidgetTextBox::MKWidgetTextBox(MKWidgetDescriptor *arg0) {
    MKHeap *temp_r3_7225;
    s8 **temp_r30_7220;
    s8 *temp_r28_7224;
    s8 *var_r3_7232;
    u32 temp_r29_7221;

    if ((u8) this->unk8 == 0) {
        MKWidget_EnableFlag((MKWidget *) this, 0x4900U);
        M2C_FIELD(this->unk4, s8 **, 0x68) = NULL;
        M2C_FIELD(this->unk4, s32 *, 0x74) = 0;
        M2C_FIELD(this->unk4, u32 *, 0x70) = 0U;
        M2C_FIELD(this->unk4, f32 *, 0x6C) = 16.0f;
        M2C_FIELD(this->unk4, s32 *, 0x78) = 2;
        M2C_FIELD(this->unk4, s32 *, 0x7C) = 0x1E;
        M2C_FIELD(this->unk4, f32 *, 0x80) = 2.0f;
    } else {
        temp_r30_7220 = this->unk4;
        temp_r29_7221 = M2C_FIELD(temp_r30_7220, u32 *, 0x70);
        if (temp_r29_7221 != 0) {
            temp_r28_7224 = M2C_FIELD(temp_r30_7220, s8 **, 0x68);
            temp_r3_7225 = __vt.Current();
            if (temp_r3_7225 != NULL) {
                var_r3_7232 = ((MKHeap *) (temp_r3_7225->Current()))->Alloc((s32) temp_r29_7221, NULL, 0);
            } else {
                var_r3_7232 = malloc(temp_r29_7221);
            }
            M2C_FIELD(temp_r30_7220, s8 **, 0x68) = var_r3_7232;
            strcpy(M2C_FIELD(this->unk4, s8 **, 0x68), temp_r28_7224);
        }
    }
    this->unk44 = 0;
    this->unk48 = 0;
    this->unk4C = 0;
    this->unk2C = 0.0f;
    this->unk30 = 0.0f;
    this->unk28 = NULL;
    return this;
}
#endif

void MKWidgetListItem::BuildAggregateMetaData() {

}

void MKWidgetListItem::BuildMetaData(int arg0) {

}

#if 0 // DRAFT: illegal implicit conversion from 'double *' to
MKWidget *MKWidgetListItem::TestPoint(MKVector3 *arg0) {
    f64 sp10;
    f64 sp8;
    MKWidget *temp_r3_7293;
    MKWidget *var_r31_7282;
    f64 temp_f1_7284;

    var_r31_7282 = MKWidget::TestPoint(arg0);
    if (var_r31_7282 != NULL) {
        temp_f1_7284 = M2C_FIELD(arg0, f64 *, 0);
        sp8 = temp_f1_7284;
        sp10 = M2C_FIELD(arg0, f64 *, 8);
        temp_r3_7293 = this->unk28.GetWidgetUnderPoint(&sp8, temp_f1_7284);
        if (temp_r3_7293 != NULL) {
            var_r31_7282 = temp_r3_7293;
        }
    }
    return var_r31_7282;
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_spC'
void MKWidgetListItem::Render(MKWidgetRenderContext *arg0) {
    MKWidget::Render(arg0);
    M2C_STRUCT_COPY((s32) &arg_spC + 4, (s32) (arg0 - 4) + 4, 0x50);
    this->unk28.Draw(&arg_sp10, &arg_spC + 0x50);
}
#endif

#if 0 // DRAFT: identifier 'MKWidgetListItem::MessageHandler(unsigned int, unsigned int)'
void MKWidgetListItem::MessageHandler(unsigned int arg0, unsigned int arg1) {
    s32 sp64;
    s32 sp60;
    s16 sp5E;
    s16 sp5C;
    MKWidgetListItem *sp58;
    s32 sp54;
    s32 sp50;
    s16 sp4E;
    s16 sp4C;
    MKWidgetListItem *sp48;
    s32 sp44;
    s32 sp40;
    s16 sp3E;
    s16 sp3C;
    MKWidgetListItem *sp38;
    s32 sp34;
    s32 sp30;
    s16 sp2E;
    s16 sp2C;
    MKWidgetListItem *sp28;
    s32 sp24;
    s32 sp20;
    s16 sp1E;
    s16 sp1C;
    MKWidgetListItem *sp18;
    s32 sp14;
    s32 sp10;
    s16 spE;
    s16 spC;
    MKWidgetListItem *sp8;

    switch ((s32) arg0) {                           /* irregular */
    case 0x2:
        MKWidget_SendMessage(&this->unk28, 0x17U, (u32) *this->unk4);
        break;
    case 0x5:
        MKWidget_Resize(&this->unk28, *((MKVector3 *) arg1));
        break;
    default:
        MKWidget_SendMessage(&this->unk28, arg0, arg1);
        break;
    case 0x2F:
        sp58 = this;
        sp5C = 8;
        sp5E = 0;
        sp60 = 0;
        sp64 = 0;
        MKWidget_SendMessage((MKWidget *) this, 0x39U, (u32) &sp58);
        break;
    case 0x30:
        sp48 = this;
        sp4C = 2;
        sp4E = 0;
        sp50 = 0;
        sp54 = 0;
        MKWidget_SendMessage((MKWidget *) this, 0x39U, (u32) &sp48);
        break;
    case 0x34:
        sp38 = this;
        sp3C = 7;
        sp3E = 0;
        sp40 = 0;
        sp44 = 0;
        MKWidget_SendMessage((MKWidget *) this, 0x39U, (u32) &sp38);
        break;
    case 0x2A:
        if ((s32) arg1 < 0x25) {
            if ((s32) arg1 != 0xD) {

            } else {
                sp8 = this;
                spC = 7;
                spE = 0;
                sp10 = 0;
                sp14 = 0;
                MKWidget_SendMessage((MKWidget *) this, 0x39U, (u32) &sp8);
            }
        } else if ((s32) arg1 < 0x29) {
            if ((s32) arg1 < 0x27) {
                sp28 = this;
                sp2C = 4;
                sp2E = 0;
                sp30 = 0;
                sp34 = 0;
                MKWidget_SendMessage((MKWidget *) this, 0x39U, (u32) &sp28);
            } else {
                sp18 = this;
                sp1C = 3;
                sp1E = 0;
                sp20 = 0;
                sp24 = 0;
                MKWidget_SendMessage((MKWidget *) this, 0x39U, (u32) &sp18);
            }
        }
        break;
    }
    MKWidget::MessageHandler(arg0, arg1);
}
#endif

#if 0 // DRAFT: undefined identifier 'zero'
MKWidgetListItem::MKWidgetListItem(MKWidgetDescriptor *arg0) {
    this->unk28.unk18 = (MKWidget *) this;
    if ((u8) this->unk8 == 0) {
        MKWidget_Move(&this->unk28, zero);
        MKWidget_EnableFlag(&this->unk28, 0x100U);
    }
    return this;
}
#endif

void MKWidgetListBox::BuildAggregateMetaData() {

}

void MKWidgetListBox::BuildMetaData(int arg0) {

}

#if 0 // DRAFT: illegal implicit conversion from 'MKWidgetRenderContext' to
void MKWidgetListBox::Draw(MKWidgetRenderContext arg0) {
    MKVector4 *var_r3_7654;
    MKWidget *var_r30_7678;
    if (IsFlagSet(2U) != 0) {
        Render(arg0);
        MKWidget_GetClientVolume((MKWidget *) this, (MKWidgetBoundingVolume *) &arg_spB0);
        arg_sp40 = (arg_spC8 * M2C_FIELD(arg0, f32 *, 0x20)) + ((arg_spC0 * M2C_FIELD(arg0, f32 *, 0)) + (arg_spC4 * M2C_FIELD(arg0, f32 *, 0x10)));
        arg_sp44 = (arg_spC8 * M2C_FIELD(arg0, f32 *, 0x24)) + ((arg_spC0 * M2C_FIELD(arg0, f32 *, 4)) + (arg_spC4 * M2C_FIELD(arg0, f32 *, 0x14)));
        arg_sp48 = (arg_spC8 * M2C_FIELD(arg0, f32 *, 0x28)) + ((arg_spC0 * M2C_FIELD(arg0, f32 *, 8)) + (arg_spC4 * M2C_FIELD(arg0, f32 *, 0x18)));
        arg_spD0 = M2C_FIELD(arg0, f64 *, 0x30);
        arg_sp80 = (f64) arg_sp40;
        arg_spD8 = M2C_FIELD(arg0, f64 *, 0x38);
        arg_sp88 = (f64) arg_sp48;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_spE0 = arg_sp20;
        arg_sp70 = arg_sp20;
        arg_sp28 = (f32) arg_spD8 + (f32) arg_sp88;
        arg_spE8 = (f64) arg_sp28;
        arg_sp78 = (f64) arg_sp28;
        arg_sp10 = -this->unk30;
        arg_sp14 = -this->unk34;
        arg_sp18 = -this->unk38;
        arg_sp60 = (f64) arg_sp10;
        arg_sp68 = (f64) arg_sp18;
        arg0->Translate((Matrix *) arg0, *((MKVector3 *) &arg_sp60));
        if (PushScissorRect((MKWidgetScissorRect *) &arg_spD0) != 0) {
            if (((s32) this->unk3A0 != -1) && (IsFlagSet(0x01000000U) != 0)) {
                GetChild(this->unk3A0);
                MKWidget_GetBoundingVolume(M2C_ERROR(/* Read from unset register $r3 */), (MKWidgetBoundingVolume *) &arg_sp90);
                MKPrimitive(4, 0);
                MKSetBaseColorV(*((s32) arg0 + 0x40));
                MKSetMatrix(*((Matrix *) arg0));
                if (IsFlagSet(8U) != 0) {
                    var_r3_7654 = MKWidget_GetMetric(4);
                } else {
                    var_r3_7654 = MKWidget_GetMetric(5);
                }
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp50 = arg_sp30;
                arg_sp38 = arg_sp98 + arg_spA8;
                arg_sp58 = (f64) arg_sp38;
                WidgetDrawBox(*((MKVector3 *) &arg_sp90), *((MKVector3 *) &arg_sp50), *var_r3_7654);
                MKEndPrimitive();
            }
            var_r30_7678 = this->unk28;
loop_10:
            if (var_r30_7678 != NULL) {
                M2C_STRUCT_COPY((s32) &arg_spFC + 4, (s32) arg0 - 4 + 4, 0x50);
                var_r30_7678->Draw(&arg_sp100, &arg_spFC + 0x50);
                var_r30_7678 = var_r30_7678->unk1C;
                goto loop_10;
            }
            PopScissorRect();
        }
    }
}
#endif

void MKWidgetListBox::ArrangeChildren() {
    if ((s32) M2C_FIELD(this->unk4, s32 *, 0x80) != 0) {
        MKWidgetFrame::ArrangeChildren();
    }
}

void MKWidgetListBox::SortChildren() {

}

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
s32 MKWidgetListBox::MessageHandler(unsigned int arg0, unsigned int arg1) {
    MKWidgetBoundingVolume spA8;
    MKWidgetBoundingVolume sp88;
    MKWidgetBoundingVolume sp68;
    MKVector3 sp58;
    f64 sp48;
    s32 sp44;
    s32 sp40;
    s16 sp3E;
    s16 sp3C;
    MKWidgetListBox *sp38;
    s32 sp34;
    s32 sp30;
    s16 sp2E;
    s16 sp2C;
    MKWidgetListBox *sp28;
    s32 sp24;
    s32 sp20;
    s16 sp1E;
    s16 sp1C;
    MKWidgetListBox *sp18;
    MKWidget *sp14;
    s32 sp10;
    s16 spE;
    s16 spC;
    MKWidgetListBox *sp8;
    MKWidget *var_r30_7790;
    f32 temp_f1_8009;
    s32 temp_r28_7785;
    s32 temp_r28_7903;
    s32 temp_r28_7947;
    s32 temp_r4_7816;
    s32 var_r28_7822;
    s32 var_r28_7844;
    s8 **temp_r4_8034;
    u16 temp_r0_8060;
    u32 temp_r0_7963;
    u32 temp_r5_7931;
    u32 var_r3_7962;

    switch ((s32) arg0) {                           /* switch 1; irregular */
    case 0x5:                                       /* switch 1 */
        temp_r28_7785 = MKWidgetScrollableFrame::MessageHandler(arg0, arg1);
        if (IsFlagSet(0x800000U) != 0) {
            var_r30_7790 = this->unk28;
            MKWidget_GetClientVolume((MKWidget *) this, &spA8);
loop_27:
            if (var_r30_7790 != NULL) {
                MKWidget_GetSize(var_r30_7790, &sp58);
                if (M2C_BITWISE(f32, sp58) != spA8.unk10) {
                    sp58 = spA8.unk10;
                    MKWidget_Resize(var_r30_7790, sp58);
                }
                var_r30_7790 = var_r30_7790->unk1C;
                goto loop_27;
            }
        }
        return temp_r28_7785;
    case 0x6C:                                      /* switch 1 */
        temp_r4_7816 = this->unk3A0;
        if ((temp_r4_7816 > -1) && ((u32) this->unk2C != 0)) {
            var_r28_7822 = temp_r4_7816;
            if ((IsFlagSet(0x80000U) != 0) || ((u32) var_r28_7822 < (u32) (this->unk2C - 1))) {
                var_r28_7822 = (var_r28_7822 + 1) % this->unk2C;
            }
            MKWidget_SendMessage((MKWidget *) this, 0x6AU, (u32) var_r28_7822);
        }
block_87:
    default:                                        /* switch 1 */
        return MKWidgetScrollableFrame::MessageHandler(arg0, arg1);
    case 0x6D:                                      /* switch 1 */
        var_r28_7844 = this->unk3A0;
        if ((var_r28_7844 > -1) && ((u32) this->unk2C != 0)) {
            if ((IsFlagSet(0x80000U) != 0) || (var_r28_7844 > 0)) {
                var_r28_7844 -= 1;
                if (var_r28_7844 < 0) {
                    var_r28_7844 += this->unk2C;
                }
            }
            MKWidget_SendMessage((MKWidget *) this, 0x6AU, (u32) var_r28_7844);
        }
        goto block_87;
    case 0x2A:                                      /* switch 1 */
    case 0x2C:                                      /* switch 1 */
        if (arg1 == 0x28) {
            MKWidget_SendMessage((MKWidget *) this, 0x6CU, 0U);
        }
        if (arg1 == 0x26) {
            MKWidget_SendMessage((MKWidget *) this, 0x6DU, 0U);
        }
        goto block_87;
    case 0x26:                                      /* switch 1 */
        if ((s16) (u16) arg1 == 6) {
            MKWidget_SendMessage((MKWidget *) this, 0x6CU, 0U);
        }
        if ((s16) (u16) arg1 == 4) {
            MKWidget_SendMessage((MKWidget *) this, 0x6DU, 0U);
        }
        goto block_87;
    case 0x3A:                                      /* switch 1 */
        temp_r28_7903 = MKWidgetScrollableFrame::MessageHandler(arg0, arg1);
        if (IsFlagSet(0x200000U) != 0) {
            SortChildren();
        }
        ArrangeChildren();
        MKWidget_Resize((MKWidget *) this, *(MKVector3 *) (this->unk4 + 0x38));
        if ((s32) this->unk3A0 == -1) {
            MKWidget_SendMessage((MKWidget *) this, 0x6AU, 0U);
        }
        return temp_r28_7903;
    case 0x3B:                                      /* switch 1 */
        temp_r5_7931 = this->unk2C;
        if ((s32) this->unk3A0 >= (s32) (temp_r5_7931 - 1)) {
            MKWidget_SendMessage((MKWidget *) this, 0x6AU, temp_r5_7931 - 2);
        }
        temp_r28_7947 = MKWidgetScrollableFrame::MessageHandler(arg0, arg1);
        ArrangeChildren();
        MKWidget_Resize((MKWidget *) this, *(MKVector3 *) (this->unk4 + 0x38));
        return temp_r28_7947;
    case 0x6A:                                      /* switch 1 */
        var_r3_7962 = arg1;
        temp_r0_7963 = this->unk2C - 1;
        if (temp_r0_7963 < arg1) {
            var_r3_7962 = temp_r0_7963;
        }
        if ((s32) this->unk3A0 != (s32) var_r3_7962) {
            this->unk3A0 = (s32) var_r3_7962;
            if (IsFlagSet(8U) != 0) {
                GetChild(this->unk3A0);
                MKWidget_SetFocus(M2C_ERROR(/* Read from unset register $r3 */));
                MKWidget_GetClientVolume((MKWidget *) this, &sp88);
                MKWidget_GetBoundingVolume(M2C_ERROR(/* Read from unset register $r3 */), &sp68);
                MKWidget_SendMessage((MKWidget *) this, 0x3FU, (u32) &sp48);
                sp88 = sp48;
                sp88.unk8 = sp50;
                if (sp68.unk4 < sp88.unk4) {
                    M2C_FIELD(this, f32 *, 0x64) = sp68.unk4;
                    MKWidget_SendMessage(&this->unk208, 0x64U, (u32) (this + 0x64));
                } else {
                    temp_f1_8009 = sp68.unk4 + sp68.unk14;
                    if (temp_f1_8009 > (sp88.unk4 + sp88.unk14)) {
                        M2C_FIELD(this, f32 *, 0x64) = (f32) (temp_f1_8009 - sp88.unk14);
                        MKWidget_SendMessage(&this->unk208, 0x64U, (u32) (this + 0x64));
                    }
                }
            }
            sp38 = this;
            sp3C = 5;
            sp3E = 0;
            sp40 = this->unk3A0;
            sp44 = 0;
            MKWidget_SendMessage((MKWidget *) this, 0x39U, (u32) &sp38);
        }
        goto block_87;
    case 0x6E:                                      /* switch 1 */
        temp_r4_8034 = this->unk4;
        M2C_FIELD(temp_r4_8034, u32 *, 0x80) = arg1;
        M2C_FIELD(this->__vptr, M2C_UNK (**)(s8 **), 0x3C)(temp_r4_8034);
        MKWidget_Resize((MKWidget *) this, *(MKVector3 *) (this->unk4 + 0x38));
        if (IsFlagSet(0x200000U) != 0) {
            SortChildren();
        }
        goto block_87;
    case 0x39:                                      /* switch 1 */
        if (IsChildWidget() != 0) {
            temp_r0_8060 = M2C_FIELD(arg1, u16 *, 4);
            switch ((s32) temp_r0_8060) {           /* switch 2; irregular */
            case 8:                                 /* switch 2 */
                if (IsFlagSet(0x400000U) != 0) {
                    GetChildIndex(M2C_FIELD(arg1, MKWidget **, 0));
                    this->unk3A0 = M2C_ERROR(/* Read from unset register $r3 */);
                    sp28 = this;
                    sp2C = 5;
                    sp2E = 0;
                    sp30 = this->unk3A0;
                    sp34 = 0;
                    MKWidget_SendMessage((MKWidget *) this, 0x39U, (u32) &sp28);
                }
                break;
            case 2:                                 /* switch 2 */
                GetChildIndex(M2C_FIELD(arg1, MKWidget **, 0));
                this->unk3A0 = M2C_ERROR(/* Read from unset register $r3 */);
                sp18 = this;
                sp1C = 5;
                sp1E = 0;
                sp20 = this->unk3A0;
                sp24 = 0;
                MKWidget_SendMessage((MKWidget *) this, 0x39U, (u32) &sp18);
                sp1C = 2;
                MKWidget_SendMessage((MKWidget *) this, 0x39U, (u32) &sp18);
                break;
            case 7:                                 /* switch 2 */
                sp8 = this;
                spC = 7;
                spE = 0;
                sp10 = this->unk3A0;
                sp14 = M2C_FIELD(arg1, MKWidget **, 0);
                MKWidget_SendMessage((MKWidget *) this, 0x39U, (u32) &sp8);
                break;
            case 3:                                 /* switch 2 */
                MKWidget_SendMessage((MKWidget *) this, 0x6CU, 0U);
                break;
            case 4:                                 /* switch 2 */
                MKWidget_SendMessage((MKWidget *) this, 0x6DU, 0U);
                break;
            }
            return 0;
        }
        goto block_87;
    case 0x6B:                                      /* switch 1 */
        return this->unk3A0;
    }
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
MKWidgetListBox::MKWidgetListBox(MKWidgetDescriptor *arg0) {
    if ((u8) this->unk8 == 0) {
        M2C_FIELD(this->unk4, s32 *, 0x80) = 3;
        MKWidget_EnableFlag((MKWidget *) this, 0x01002000U);
    }
    this->unk3A0 = -1;
    return this;
}
#endif

void MKWidgetScrollableFrame::BuildAggregateMetaData() {

}

void MKWidgetScrollableFrame::BuildMetaData(int arg0) {

}

#if 0 // DRAFT: undefined identifier 'sp20'
void MKWidgetScrollableFrame::CheckScrollBarRequirements() {
    MKWidgetBoundingVolume sp60;
    f64 sp58;
    f64 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_8609;
    f32 var_f1_8466;
    f32 var_f2_8415;
    f32 var_f2_8515;
    s32 temp_r0_8573;
    s32 temp_r0_8590;
    s32 var_r28_8414;
    s32 var_r29_8566;
    s32 var_r31_8416;
    s32 var_r31_8582;

    GetChildrenRange(&this->unk40, &this->unk50);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r30, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    sp50 = sp20;
    sp28 = this->unk50.unk8 - this->unk40.unk8;
    sp58 = (f64) sp28;
    MKWidget_GetClientVolume((MKWidget *) this, &sp60);
    var_r28_8414 = 0;
    var_f2_8415 = 0.0f;
    var_r31_8416 = 0;
    if (sp60.unk10 > var_f2_8415) {
        var_f2_8415 = sp60.unk10;
    }
    if ((f32) sp50 > var_f2_8415) {
        sp1C = sp60.unk10 / (f32) sp50;
        MKWidget_SendMessage(&this->unk70, 0x6BU, (u32) &sp1C);
        sp1C = 20.0f;
        MKWidget_SendMessage(&this->unk70, 0x6AU, (u32) &sp1C);
        sp1C = (f32) sp50 - sp60.unk10;
        MKWidget_SendMessage(&this->unk70, 0x67U, (u32) &sp1C);
        var_r28_8414 = 1;
    } else {
        sp18 = 1.0f;
        MKWidget_SendMessage(&this->unk70, 0x6BU, (u32) &sp18);
        sp18 = 0.0f;
        MKWidget_SendMessage(&this->unk70, 0x67U, (u32) &sp18);
    }
    MKWidget_GetClientVolume((MKWidget *) this, &sp60);
    var_f1_8466 = 0.0f;
    if (sp60.unk14 > var_f1_8466) {
        var_f1_8466 = sp60.unk14;
    }
    if (unksp54 > var_f1_8466) {
        sp14 = sp60.unk14 / unksp54;
        MKWidget_SendMessage(&this->unk208, 0x6BU, (u32) &sp14);
        sp14 = 20.0f;
        MKWidget_SendMessage(&this->unk208, 0x6AU, (u32) &sp14);
        sp14 = unksp54 - sp60.unk14;
        MKWidget_SendMessage(&this->unk208, 0x67U, (u32) &sp14);
        var_r31_8416 = 1;
    } else {
        sp10 = 1.0f;
        MKWidget_SendMessage(&this->unk208, 0x6BU, (u32) &sp10);
        sp10 = 0.0f;
        MKWidget_SendMessage(&this->unk208, 0x67U, (u32) &sp10);
    }
    MKWidget_GetClientVolume((MKWidget *) this, &sp60);
    var_f2_8515 = 0.0f;
    if (sp60.unk10 > var_f2_8515) {
        var_f2_8515 = sp60.unk10;
    }
    if ((f32) sp50 > var_f2_8515) {
        spC = sp60.unk10 / (f32) sp50;
        MKWidget_SendMessage(&this->unk70, 0x6BU, (u32) &spC);
        spC = 20.0f;
        MKWidget_SendMessage(&this->unk70, 0x6AU, (u32) &spC);
        spC = (f32) sp50 - sp60.unk10;
        MKWidget_SendMessage(&this->unk70, 0x67U, (u32) &spC);
        var_r28_8414 = 1;
    } else {
        sp8 = 1.0f;
        MKWidget_SendMessage(&this->unk70, 0x6BU, (u32) &sp8);
        sp8 = 0.0f;
        MKWidget_SendMessage(&this->unk70, 0x67U, (u32) &sp8);
    }
    if (IsFlagSet(0x40000U) != 0) {
        var_r29_8566 = 1;
    } else {
        temp_r0_8573 = 0 - IsFlagSet(0x10000U);
        var_r29_8566 = var_r28_8414 & ((temp_r0_8573 - temp_r0_8573) - !M2C_CARRY);
    }
    if (IsFlagSet(0x20000U) != 0) {
        var_r31_8582 = 1;
    } else {
        temp_r0_8590 = 0 - IsFlagSet(0x8000U);
        var_r31_8582 = var_r31_8416 & ((temp_r0_8590 - temp_r0_8590) - !M2C_CARRY);
    }
    MKWidget_Show(&this->unk70, var_r29_8566);
    MKWidget_Show(&this->unk208, var_r31_8582);
    MKWidget_GetClientVolume((MKWidget *) this, &sp60);
    sp40 = 0.0f;
    sp44 = sp60.unk14;
    sp48 = 0.0f;
    temp_f1_8609 = MKWidget_GetMetricF(0x15);
    sp30 = sp60.unk10;
    sp34 = temp_f1_8609;
    sp38 = 0.0f;
    MKWidget_Move(&this->unk70, *((MKVector3 *) &sp40));
    MKWidget_Resize(&this->unk70, *((MKVector3 *) &sp30));
    sp44 = 0.0f;
    sp40 = sp60.unk10;
    sp48 = 0.0f;
    sp30 = MKWidget_GetMetricF(0x15);
    sp34 = sp60.unk14;
    sp38 = 0.0f;
    MKWidget_Move(&this->unk208, *((MKVector3 *) &sp40));
    MKWidget_Resize(&this->unk208, *((MKVector3 *) &sp30));
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void MKWidgetScrollableFrame::GetChildrenRange(MKVector3 *arg0, MKVector3 *arg1) {
    MKVector3 sp38;
    MKVector3 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    MKWidget *temp_r6_8657;
    MKWidget *var_r31_8681;
    s8 **temp_r3_8693;
    s8 **temp_r4_8660;

    temp_r6_8657 = this->unk28;
    if (temp_r6_8657 != NULL) {
        temp_r4_8660 = temp_r6_8657->unk4;
        M2C_FIELD(arg0, f64 *, 0) = (f64) M2C_FIELD(temp_r4_8660, f64 *, 8);
        M2C_FIELD(arg0, f64 *, 8) = (f64) M2C_FIELD(temp_r4_8660, f64 *, 0x10);
        M2C_FIELD(arg1, f64 *, 0) = (f64) M2C_FIELD(arg0, f64 *, 0);
        M2C_FIELD(arg1, f64 *, 8) = (f64) M2C_FIELD(arg0, f64 *, 8);
    } else {
        M2C_FIELD(arg0, f64 *, 0) = (f64) M2C_FIELD(&zero, f64 *, 0);
        M2C_FIELD(arg0, f64 *, 8) = (f64) M2C_FIELD(&zero, f64 *, 8);
        M2C_FIELD(arg1, f64 *, 0) = (f64) M2C_FIELD(arg0, f64 *, 0);
        M2C_FIELD(arg1, f64 *, 8) = (f64) M2C_FIELD(arg0, f64 *, 8);
    }
    var_r31_8681 = this->unk28;
loop_5:
    if (var_r31_8681 != NULL) {
        Min(sp38, *arg0);
        M2C_FIELD(arg0, f64 *, 0) = M2C_BITWISE(f64, sp38);
        M2C_FIELD(arg0, f64 *, 8) = (f64) sp38.unk8;
        temp_r3_8693 = var_r31_8681->unk4;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r5, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp18 = sp8;
        sp10 = M2C_FIELD((temp_r3_8693 + 8), f32 *, 8) + M2C_FIELD((temp_r3_8693 + 0x38), f32 *, 8);
        sp20 = (f64) sp10;
        Max(sp28, *arg1);
        M2C_FIELD(arg1, f64 *, 0) = M2C_BITWISE(f64, sp28);
        M2C_FIELD(arg1, f64 *, 8) = (f64) sp28.unk8;
        var_r31_8681 = var_r31_8681->unk1C;
        goto loop_5;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'double *' to
MKWidget *MKWidgetScrollableFrame::TestPoint(MKVector3 *arg0) {
    f64 sp20;
    f64 sp18;
    f64 sp10;
    f64 sp8;
    MKWidget *temp_r3_8748;
    MKWidget *temp_r3_8762;
    MKWidget *var_r31_8737;
    f64 temp_f1_8739;
    f64 temp_f1_8753;

    var_r31_8737 = MKWidget::TestPoint(arg0);
    if (var_r31_8737 != NULL) {
        temp_f1_8739 = M2C_FIELD(arg0, f64 *, 0);
        sp18 = temp_f1_8739;
        sp20 = M2C_FIELD(arg0, f64 *, 8);
        temp_r3_8748 = this->unk70.GetWidgetUnderPoint(&sp18, temp_f1_8739);
        if (temp_r3_8748 != NULL) {
            var_r31_8737 = temp_r3_8748;
        }
        temp_f1_8753 = M2C_FIELD(arg0, f64 *, 0);
        sp8 = temp_f1_8753;
        sp10 = M2C_FIELD(arg0, f64 *, 8);
        temp_r3_8762 = this->unk208.GetWidgetUnderPoint(&sp8, temp_f1_8753);
        if (temp_r3_8762 != NULL) {
            var_r31_8737 = temp_r3_8762;
        }
    }
    return var_r31_8737;
}
#endif

#if 0 // DRAFT: undefined identifier 'sp38'
void MKWidgetScrollableFrame::UpdateState() {
    MKVector3 sp98;
    MKVector3 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f32 sp30;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 temp_f5_8800;

    MKWidget::UpdateState();
    if (IsFlagSet(0x4000U) != 0) {
        M2C_ERROR(/* unknown instruction: psq_lx $f4, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f3, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f4, $f3 */);
        temp_f5_8800 = this->unk68 - this->unk38;
        sp68 = sp38;
        sp40 = temp_f5_8800;
        sp70 = (f64) sp40;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f4, $f3 */);
        sp20 = 0.01f;
        sp18 = 0.01f;
        sp30 = (f32) sp70 * 0.1f;
        sp1C = 0.01f;
        sp78 = sp28;
        sp80 = (f64) sp30;
        sp58 = (f64) sp18;
        sp60 = (f64) sp20;
        sp10 = temp_f5_8800;
        sp48 = sp8;
        sp50 = (f64) sp10;
        Max(sp88, *((MKVector3 *) &sp78));
        Min(sp98, sp88);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        M2C_ERROR(/* unknown instruction: psq_stx $f0, $r31, $r0, 0x0, qr0 */);
        this->unk38 += sp98.unk8;
        return;
    }
    M2C_FIELD(this, f64 *, 0x30) = (f64) this->unk60;
    M2C_FIELD(this, f32 *, 0x38) = (f64) M2C_FIELD(this, f32 *, 0x68);
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp5C'
void MKWidgetScrollableFrame::Render(MKWidgetRenderContext *arg0) {
    MKWidgetFrame::Render(arg0);
    CheckScrollBarRequirements();
    M2C_STRUCT_COPY((s32) &arg_sp5C + 4, (s32) (arg0 - 4) + 4, 0x50);
    this->unk70.Draw(&arg_sp60, &arg_sp5C + 0x50);
    M2C_STRUCT_COPY((s32) &arg_spC + 4, (s32) (arg0 - 4) + 4, 0x50);
    this->unk208.Draw(&arg_sp10, &arg_spC + 0x50);
}
#endif

#if 0 // DRAFT: illegal operand
s32 MKWidgetScrollableFrame::MessageHandler(unsigned int arg0, unsigned int arg1) {
    MKWidget *temp_r3_9050;
    MKWidget *temp_r3_9059;
    u32 temp_r0_9049;
    u32 temp_r31_8957;
    u32 temp_r31_8985;
    u32 temp_r31_8995;
    u32 var_r4_9017;
    u32 var_r4_9039;

    if ((s32) arg0 != 0x1C) {
        switch ((s32) arg0) {                       /* irregular */
        case 0x12:
            temp_r31_8957 = MKWidgetFrame::MessageHandler(arg0, arg1);
            if (this->unk208.IsFlagSet(2U) != 0) {
                M2C_FIELD(arg1, f32 *, 0x10) = (f32) (M2C_FIELD(arg1, f32 *, 0x10) - MKWidget_GetMetricF(0x15));
            }
            if (this->unk70.IsFlagSet(2U) != 0) {
                M2C_FIELD(arg1, f32 *, 0x14) = (f32) (M2C_FIELD(arg1, f32 *, 0x14) - MKWidget_GetMetricF(0x15));
            }
            return (s32) temp_r31_8957;
        case 0x5:
            temp_r31_8985 = MKWidgetFrame::MessageHandler(arg0, arg1);
            CheckScrollBarRequirements();
            return (s32) temp_r31_8985;
        default:
            temp_r31_8995 = MKWidgetFrame::MessageHandler(arg0, arg1);
            if (arg1 & 0x78000) {
                MKWidget_Resize((MKWidget *) this, *(MKVector3 *) (this->unk4 + 0x38));
            }
            return (s32) temp_r31_8995;
        case 0x35:
            if (this->unk208.IsFlagSet(2U) != 0) {
                if ((3.0f * M2C_BITWISE(f32, M2C_FIELD(arg1, u32 *, 0))) > 0.0f) {
                    var_r4_9017 = 0x69;
                } else {
                    var_r4_9017 = 0x68;
                }
                MKWidget_SendMessage(&this->unk208, var_r4_9017, 0U);
                return 0;
            }
            if (this->unk70.IsFlagSet(2U) != 0) {
                if ((3.0f * M2C_BITWISE(f32, M2C_FIELD(arg1, u32 *, 0))) > 0.0f) {
                    var_r4_9039 = 0x69;
                } else {
                    var_r4_9039 = 0x68;
                }
                MKWidget_SendMessage(&this->unk70, var_r4_9039, 0U);
                return 0;
            }
            goto block_37;
        case 0x39:
            temp_r0_9049 = M2C_FIELD(arg1, u32 *, 0);
            temp_r3_9050 = &this->unk70;
            if (temp_r0_9049 == temp_r3_9050) {
                MKWidget_SendMessage(temp_r3_9050, 0x65U, (u32) &this->unk60);
                return 0;
            }
            temp_r3_9059 = &this->unk208;
            if (temp_r0_9049 == temp_r3_9059) {
                MKWidget_SendMessage(temp_r3_9059, 0x65U, (u32) (this + 0x64));
                return 0;
            }
            goto block_37;
        }
    } else {
block_37:
        return MKWidgetFrame::MessageHandler(arg0, arg1);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'zero'
MKWidgetScrollableFrame::MKWidgetScrollableFrame(MKWidgetDescriptor *arg0) {
    this->unk70.unk18 = (MKWidget *) this;
    this->unk208.unk18 = (MKWidget *) this;
    this->unk60 = M2C_FIELD(&zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x68) = (f64) M2C_FIELD(&zero, f64 *, 8);
    if ((u8) this->unk8 == 0) {
        MKWidget_EnableFlag((MKWidget *) this, 0x18004U);
        MKWidget_SendMessage((MKWidget *) this, 0x64U, 2U);
        MKWidget_Show(&this->unk70, 0);
        MKWidget_Show(&this->unk208, 0);
        MKWidget_DisableFlag(&this->unk70, 4U);
        MKWidget_DisableFlag(&this->unk208, 4U);
        MKWidget_EnableFlag(&this->unk70, 0x200U);
        MKWidget_EnableFlag(&this->unk208, 0x200U);
    }
    return this;
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
MKWidgetSlider::MKWidgetSlider(MKWidgetDescriptor *arg0) {
    if ((u8) this->unk8 == 0) {
        MKWidget_EnableFlag((MKWidget *) this, 0x400U);
        M2C_FIELD(this->unk4, f32 *, 0x68) = 0.0f;
        M2C_FIELD(this->unk4, f32 *, 0x6C) = 0.0f;
        M2C_FIELD(this->unk4, f32 *, 0x70) = 1.0f;
        M2C_FIELD(this->unk4, f32 *, 0x74) = 0.1f;
        M2C_FIELD(this->unk4, f32 *, 0x78) = 0.5f;
    }
    return this;
}
#endif

void MKWidgetScrollBar::BuildAggregateMetaData() {

}

void MKWidgetScrollBar::BuildMetaData(int arg0) {

}

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void MKWidgetScrollBar::GetThumbFromValue() {
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f0_9303;
    f32 temp_f1_9302;
    f32 temp_f1_9352;
    f32 temp_f2_9351;
    f32 var_f0_9321;
    f32 var_f0_9338;
    f32 var_f0_9371;
    f32 var_f31_9313;
    f32 var_f31_9327;
    f32 var_f31_9358;
    f64 *var_r4_9382;
    s8 **temp_r3_9301;
    s8 **temp_r3_9348;
    u8 var_r30_9306;

    if (this->unk138.IsFlagSet(2U) != 0) {
        temp_r3_9301 = this->unk4;
        temp_f1_9302 = M2C_FIELD(temp_r3_9301, f32 *, 0x38);
        temp_f0_9303 = M2C_FIELD(temp_r3_9301, f32 *, 0x3C);
        if (temp_f1_9302 > temp_f0_9303) {
            var_r30_9306 = 0;
        } else {
            var_r30_9306 = 1;
        }
        if (var_r30_9306 != 0) {
            var_f31_9313 = temp_f0_9303;
        } else {
            var_f31_9313 = temp_f1_9302;
        }
        if (var_r30_9306 != 0) {
            var_f0_9321 = M2C_FIELD(this->unk138.unk4, f32 *, 0x3C);
        } else {
            var_f0_9321 = M2C_FIELD(this->unk138.unk4, f32 *, 0x38);
        }
        var_f31_9327 = var_f31_9313 - var_f0_9321;
        if (IsFlagSet(0x400U) == 0) {
            if (var_r30_9306 != 0) {
                var_f0_9338 = 2.0f * M2C_FIELD(this->unk28.unk4, f32 *, 0x3C);
            } else {
                var_f0_9338 = 2.0f * M2C_FIELD(this->unk28.unk4, f32 *, 0x38);
            }
            var_f31_9327 -= var_f0_9338;
        }
        temp_r3_9348 = this->unk4;
        temp_f2_9351 = M2C_FIELD(temp_r3_9348, f32 *, 0x6C);
        temp_f1_9352 = M2C_FIELD(temp_r3_9348, f32 *, 0x70) - temp_f2_9351;
        if (temp_f1_9352 > 0.0f) {
            var_f31_9358 = var_f31_9327 * ((M2C_FIELD(temp_r3_9348, f32 *, 0x68) - temp_f2_9351) / temp_f1_9352);
        } else {
            var_f31_9358 = 0.0f;
        }
        if (IsFlagSet(0x400U) == 0) {
            if (var_r30_9306 != 0) {
                var_f0_9371 = M2C_FIELD(this->unk28.unk4, f32 *, 0x3C);
            } else {
                var_f0_9371 = M2C_FIELD(this->unk28.unk4, f32 *, 0x38);
            }
            var_f31_9358 += var_f0_9371;
        }
        if (var_r30_9306 != 0) {
            var_r4_9382 = &sp38;
            sp1C = var_f31_9358;
            sp18 = 0.0f;
            sp20 = 0.0f;
            sp38 = (f64) sp18;
            sp40 = (f64) sp20;
        } else {
            var_r4_9382 = &sp28;
            sp8 = var_f31_9358;
            spC = 0.0f;
            sp10 = 0.0f;
            sp28 = (f64) sp8;
            sp30 = (f64) sp10;
        }
        sp48 = M2C_FIELD(var_r4_9382, f64 *, 0);
        sp50 = M2C_FIELD(var_r4_9382, f64 *, 8);
        MKWidget_Move(&this->unk138, *((MKVector3 *) &sp48));
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void MKWidgetScrollBar::GetValueFromThumb() {
    f32 sp8;
    f32 temp_f0_9437;
    f32 temp_f1_9436;
    f32 temp_f2_9511;
    f32 var_f0_9455;
    f32 var_f0_9472;
    f32 var_f0_9499;
    f32 var_f30_9447;
    f32 var_f30_9461;
    f32 var_f31_9485;
    s8 **temp_r3_9435;
    s8 **temp_r6_9508;
    u8 var_r30_9440;

    if (IsFlagSet(2U) != 0) {
        temp_r3_9435 = this->unk4;
        temp_f1_9436 = M2C_FIELD(temp_r3_9435, f32 *, 0x38);
        temp_f0_9437 = M2C_FIELD(temp_r3_9435, f32 *, 0x3C);
        if (temp_f1_9436 > temp_f0_9437) {
            var_r30_9440 = 0;
        } else {
            var_r30_9440 = 1;
        }
        if (var_r30_9440 != 0) {
            var_f30_9447 = temp_f0_9437;
        } else {
            var_f30_9447 = temp_f1_9436;
        }
        if (var_r30_9440 != 0) {
            var_f0_9455 = M2C_FIELD(this->unk138.unk4, f32 *, 0x3C);
        } else {
            var_f0_9455 = M2C_FIELD(this->unk138.unk4, f32 *, 0x38);
        }
        var_f30_9461 = var_f30_9447 - var_f0_9455;
        if (IsFlagSet(0x400U) == 0) {
            if (var_r30_9440 != 0) {
                var_f0_9472 = 2.0f * M2C_FIELD(this->unk28.unk4, f32 *, 0x3C);
            } else {
                var_f0_9472 = 2.0f * M2C_FIELD(this->unk28.unk4, f32 *, 0x38);
            }
            var_f30_9461 -= var_f0_9472;
        }
        if (var_r30_9440 != 0) {
            var_f31_9485 = M2C_FIELD(this->unk138.unk4, f32 *, 0xC);
        } else {
            var_f31_9485 = M2C_FIELD(this->unk138.unk4, f32 *, 8);
        }
        if (IsFlagSet(0x400U) == 0) {
            if (var_r30_9440 != 0) {
                var_f0_9499 = M2C_FIELD(this->unk28.unk4, f32 *, 0x3C);
            } else {
                var_f0_9499 = M2C_FIELD(this->unk28.unk4, f32 *, 0x38);
            }
            var_f31_9485 -= var_f0_9499;
        }
        temp_r6_9508 = this->unk4;
        temp_f2_9511 = M2C_FIELD(temp_r6_9508, f32 *, 0x6C);
        sp8 = ((var_f31_9485 / var_f30_9461) * (M2C_FIELD(temp_r6_9508, f32 *, 0x70) - temp_f2_9511)) + temp_f2_9511;
        MKWidget_SendMessage((MKWidget *) this, 0x64U, (u32) &sp8);
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'double *' to
MKWidget *MKWidgetScrollBar::TestPoint(MKVector3 *arg0) {
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f64 sp10;
    f64 sp8;
    MKWidget *temp_r3_9551;
    MKWidget *temp_r3_9565;
    MKWidget *temp_r3_9579;
    MKWidget *var_r31_9540;
    f64 temp_f1_9542;
    f64 temp_f1_9556;
    f64 temp_f1_9570;

    var_r31_9540 = MKWidget::TestPoint(arg0);
    if (var_r31_9540 != NULL) {
        temp_f1_9542 = M2C_FIELD(arg0, f64 *, 0);
        sp28 = temp_f1_9542;
        sp30 = M2C_FIELD(arg0, f64 *, 8);
        temp_r3_9551 = this->unk28.GetWidgetUnderPoint(&sp28, temp_f1_9542);
        if (temp_r3_9551 != NULL) {
            var_r31_9540 = temp_r3_9551;
        }
        temp_f1_9556 = M2C_FIELD(arg0, f64 *, 0);
        sp18 = temp_f1_9556;
        sp20 = M2C_FIELD(arg0, f64 *, 8);
        temp_r3_9565 = this->unkB0.GetWidgetUnderPoint(&sp18, temp_f1_9556);
        if (temp_r3_9565 != NULL) {
            var_r31_9540 = temp_r3_9565;
        }
        temp_f1_9570 = M2C_FIELD(arg0, f64 *, 0);
        sp8 = temp_f1_9570;
        sp10 = M2C_FIELD(arg0, f64 *, 8);
        temp_r3_9579 = this->unk138.GetWidgetUnderPoint(&sp8, temp_f1_9570);
        if (temp_r3_9579 != NULL) {
            var_r31_9540 = temp_r3_9579;
        }
    }
    return var_r31_9540;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void MKWidgetScrollBar::Render(MKWidgetRenderContext *arg0) {
    MKVector4 *temp_r29_9658;
    MKVector4 *temp_r29_9698;
    f32 temp_f2_9620;
    f32 temp_f2_9649;
    f32 temp_f2_9689;
    f32 temp_f7_9621;
    s8 **temp_r3_9619;
    u8 var_r0_9624;
    MKWidget::Render(arg0);
    MKMaterial_SetMaterial(pWidgetBlank);
    MKPrimitive(4, 0);
    MKSetBaseColorV(arg0->unk40);
    MKSetMatrix(*((Matrix *) arg0));
    if (IsFlagSet(0x400U) != 0) {
        temp_r3_9619 = this->unk4;
        temp_f2_9620 = M2C_FIELD(temp_r3_9619, f32 *, 0x38);
        temp_f7_9621 = M2C_FIELD(temp_r3_9619, f32 *, 0x3C);
        if (temp_f2_9620 < temp_f7_9621) {
            var_r0_9624 = 1;
        } else {
            var_r0_9624 = 0;
        }
        if (var_r0_9624 != 0) {
            arg_sp48 = 0.0f;
            arg_sp58 = 0.0f;
            arg_sp40 = (0.5f * temp_f2_9620) + 2.0f;
            arg_sp44 = 2.0f + -((0.25f * temp_f2_9620) - temp_f7_9621);
            arg_sp98 = (f64) arg_sp48;
            arg_sp90 = (f64) arg_sp40;
            temp_f2_9649 = M2C_FIELD(this->unk4, f32 *, 0x38);
            arg_spA8 = (f64) arg_sp58;
            arg_sp50 = (0.5f * temp_f2_9649) - 2.0f;
            arg_sp54 = (0.25f * temp_f2_9649) - 2.0f;
            arg_spA0 = (f64) arg_sp50;
            temp_r29_9658 = MKWidget_GetMetric(1);
            WidgetDrawBevel(*((MKVector3 *) &arg_spA0), *((MKVector3 *) &arg_sp90), 2.0f, *(MKWidget_GetMetric(0)), *temp_r29_9658, 1U, 0U);
        } else {
            arg_sp28 = 0.0f;
            arg_sp38 = 0.0f;
            arg_sp20 = 2.0f + -((0.25f * temp_f7_9621) - temp_f2_9620);
            arg_sp24 = (0.5f * temp_f7_9621) + 2.0f;
            arg_sp78 = (f64) arg_sp28;
            arg_sp70 = (f64) arg_sp20;
            temp_f2_9689 = M2C_FIELD(this->unk4, f32 *, 0x3C);
            arg_sp88 = (f64) arg_sp38;
            arg_sp30 = (0.25f * temp_f2_9689) - 2.0f;
            arg_sp34 = (0.5f * temp_f2_9689) - 2.0f;
            arg_sp80 = (f64) arg_sp30;
            temp_r29_9698 = MKWidget_GetMetric(1);
            WidgetDrawBevel(*((MKVector3 *) &arg_sp80), *((MKVector3 *) &arg_sp70), 2.0f, *(MKWidget_GetMetric(0)), *temp_r29_9698, 1U, 0U);
        }
    } else {
        arg_sp10 = 0.0f;
        arg_sp14 = 0.0f;
        arg_sp18 = 1.0f;
        arg_sp1C = 1.0f;
        arg_sp60 = (f64) arg_sp10;
        arg_sp68 = (f64) arg_sp18;
        WidgetDrawBox(zero, *(MKVector3 *) (this->unk4 + 0x38), *((MKVector4 *) &arg_sp60));
    }
    MKEndPrimitive();
    M2C_STRUCT_COPY((s32) &arg_sp14C + 4, (s32) (arg0 - 4) + 4, 0x50);
    this->unk28.Draw(&arg_sp150, &arg_sp14C + 0x50);
    M2C_STRUCT_COPY((s32) &arg_spFC + 4, (s32) (arg0 - 4) + 4, 0x50);
    this->unkB0.Draw(&arg_sp100, &arg_spFC + 0x50);
    M2C_STRUCT_COPY((s32) &arg_spAC + 4, (s32) (arg0 - 4) + 4, 0x50);
    this->unk138.Draw(&arg_spB0, &arg_spAC + 0x50);
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
s32 MKWidgetScrollBar::MessageHandler(unsigned int arg0, unsigned int arg1) {
    f64 sp180;
    f64 sp178;
    s32 sp174;
    s8 **sp170;
    s16 sp16E;
    s16 sp16C;
    MKWidgetScrollBar *sp168;
    MKVector3 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f0_10124;
    f32 temp_f0_9939;
    f32 temp_f1_10195;
    f32 temp_f1_10206;
    f32 temp_f1_10447;
    f32 temp_f1_10468;
    f32 temp_f1_9870;
    f32 temp_f2_10033;
    f32 temp_f2_10055;
    f32 temp_f2_10123;
    f32 temp_f2_10460;
    f32 temp_f2_10491;
    f32 temp_f2_10512;
    f32 temp_f2_9848;
    f32 temp_f2_9868;
    f32 temp_f2_9938;
    f32 temp_f30_10148;
    f32 temp_f30_9963;
    f32 temp_f3_10053;
    f32 temp_f3_10437;
    f32 temp_f4_10431;
    f32 temp_r4_10574;
    f32 var_f0_10108;
    f32 var_f0_10221;
    f32 var_f0_10440;
    f32 var_f0_10461;
    f32 var_f0_10492;
    f32 var_f0_10513;
    f32 var_f0_9923;
    f32 var_f1_10034;
    f32 var_f1_10056;
    f32 var_f1_9849;
    f32 var_f2_9871;
    f32 var_f30_10115;
    f32 var_f30_10406;
    f32 var_f30_9930;
    f32 var_f31_10013;
    f32 var_f31_9828;
    s32 temp_r28_10342;
    s8 **temp_r3_10204;
    s8 **temp_r3_10392;
    s8 **temp_r3_10429;
    s8 **temp_r3_10457;
    s8 **temp_r3_10488;
    s8 **temp_r3_10509;
    s8 **temp_r3_10530;
    s8 **temp_r4_10194;
    s8 **temp_r4_10267;
    s8 **temp_r4_10295;
    u16 temp_r0_10578;
    u32 var_r4_10380;
    u8 var_r0_10535;
    u8 var_r28_10397;

    switch (arg0) {                                 /* switch 1 */
    case 0x47:                                      /* switch 1 */
        M2C_FIELD(this->__vptr, M2C_UNK (**)(M2C_UNK, s8 **), 0xC)(5, this->unk4 + 0x38);
        GetThumbFromValue();
    default:                                        /* switch 1 */
block_139:
        return MKWidget::MessageHandler(arg0, arg1);
    case 0x5:                                       /* switch 1 */
        if (M2C_FIELD(arg1, f32 *, 4) > M2C_FIELD(arg1, f32 *, 0)) {
            if (IsFlagSet(0x400U) != 0) {
                var_f31_9828 = 0.0f;
            } else {
                var_f31_9828 = M2C_FIELD(arg1, f32 *, 0);
            }
            if (IsFlagSet(0x400U) != 0) {
                MKWidget_Show(&this->unk28, 0);
                MKWidget_Show(&this->unkB0, 0);
            } else {
                temp_f2_9848 = M2C_FIELD(arg1, f32 *, 0);
                var_f1_9849 = 0.5f * M2C_FIELD(arg1, f32 *, 4);
                if (temp_f2_9848 < var_f1_9849) {
                    var_f1_9849 = temp_f2_9848;
                }
                sp68 = temp_f2_9848;
                sp6C = var_f1_9849;
                sp70 = 0.0f;
                sp148 = (f64) sp68;
                sp150 = (f64) sp70;
                sp178 = (f64) sp68;
                sp180 = (f64) sp70;
                MKWidget_Resize(&this->unk28, *((MKVector3 *) &sp178));
                temp_f2_9868 = M2C_FIELD(arg1, f32 *, 4);
                temp_f1_9870 = 0.5f * temp_f2_9868;
                var_f2_9871 = temp_f2_9868 - M2C_FIELD(arg1, f32 *, 0);
                if (var_f2_9871 > temp_f1_9870) {

                } else {
                    var_f2_9871 = temp_f1_9870;
                }
                spAC = var_f2_9871;
                spA8 = 0.0f;
                spB0 = 0.0f;
                sp138 = (f64) spA8;
                sp140 = (f64) spB0;
                MKWidget_Move(&this->unk28, *((MKVector3 *) &sp138));
                MKWidget_Show(&this->unk28, 1);
                MKWidget_Resize(&this->unkB0, *((MKVector3 *) &sp178));
                MKWidget_Show(&this->unkB0, 1);
            }
            if ((IsFlagSet(0x400U) != 0) || !(M2C_FIELD(arg1, f32 *, 4) < ((2.0f * M2C_FIELD(arg1, f32 *, 0)) + 4.0f))) {
                if (IsFlagSet(0x200U) != 0) {
                    var_f0_9923 = -((2.0f * var_f31_9828) - M2C_FIELD(arg1, f32 *, 4)) * M2C_FIELD(this->unk4, f32 *, 0x78);
                    if (var_f0_9923 > 4.0f) {

                    } else {
                        var_f0_9923 = 4.0f;
                    }
                    var_f30_9930 = var_f0_9923;
                } else {
                    temp_f2_9938 = M2C_FIELD(arg1, f32 *, 0) * M2C_FIELD(this->unk4, f32 *, 0x78);
                    temp_f0_9939 = -((2.0f * var_f31_9828) - M2C_FIELD(arg1, f32 *, 4));
                    if (temp_f0_9939 < temp_f2_9938) {
                        var_f30_9930 = temp_f0_9939;
                    } else {
                        var_f30_9930 = temp_f2_9938;
                    }
                }
                sp98 = M2C_FIELD(arg1, f32 *, 0);
                sp9C = var_f30_9930;
                spA0 = 0.0f;
                sp128 = (f64) sp98;
                sp130 = (f64) spA0;
                MKWidget_Resize(&this->unk138, *((MKVector3 *) &sp128));
                temp_f30_9963 = 0.5f * var_f30_9930;
                sp60 = 0.0f;
                sp58 = 0.5f * M2C_FIELD(arg1, f32 *, 0);
                sp5C = var_f31_9828 + temp_f30_9963;
                sp120 = (f64) sp60;
                sp118 = (f64) sp58;
                sp178 = (f64) sp58;
                sp180 = (f64) sp60;
                MKWidget_SendMessage(&this->unk138, 0x64U, (u32) &sp178);
                sp50 = 0.0f;
                sp48 = 0.5f * M2C_FIELD(arg1, f32 *, 0);
                sp4C = (M2C_FIELD(arg1, f32 *, 4) - var_f31_9828) - temp_f30_9963;
                sp110 = (f64) sp50;
                sp108 = (f64) sp48;
                sp178 = (f64) sp48;
                sp180 = (f64) sp50;
                MKWidget_SendMessage(&this->unk138, 0x65U, (u32) &sp178);
                MKWidget_Show(&this->unk138, 1);
            } else {
                MKWidget_Show(&this->unk138, 0);
            }
        } else {
            if (IsFlagSet(0x400U) != 0) {
                var_f31_10013 = 0.0f;
            } else {
                var_f31_10013 = M2C_FIELD(arg1, f32 *, 4);
            }
            if (IsFlagSet(0x400U) != 0) {
                MKWidget_Show(&this->unk28, 0);
                MKWidget_Show(&this->unkB0, 0);
            } else {
                temp_f2_10033 = M2C_FIELD(arg1, f32 *, 4);
                var_f1_10034 = 0.5f * M2C_FIELD(arg1, f32 *, 0);
                if (temp_f2_10033 < var_f1_10034) {
                    var_f1_10034 = temp_f2_10033;
                }
                sp38 = var_f1_10034;
                sp3C = temp_f2_10033;
                sp40 = 0.0f;
                spF8 = (f64) sp38;
                sp100 = (f64) sp40;
                sp178 = (f64) sp38;
                sp180 = (f64) sp40;
                MKWidget_Resize(&this->unk28, *((MKVector3 *) &sp178));
                temp_f3_10053 = M2C_FIELD(arg1, f32 *, 0);
                temp_f2_10055 = 0.5f * temp_f3_10053;
                var_f1_10056 = temp_f3_10053 - M2C_FIELD(arg1, f32 *, 4);
                if (var_f1_10056 > temp_f2_10055) {

                } else {
                    var_f1_10056 = temp_f2_10055;
                }
                sp88 = var_f1_10056;
                sp8C = 0.0f;
                sp90 = 0.0f;
                spE8 = (f64) sp88;
                spF0 = (f64) sp90;
                MKWidget_Move(&this->unk28, *((MKVector3 *) &spE8));
                MKWidget_Show(&this->unk28, 1);
                MKWidget_Resize(&this->unkB0, *((MKVector3 *) &sp178));
                MKWidget_Show(&this->unkB0, 1);
            }
            if ((IsFlagSet(0x400U) != 0) || !(M2C_FIELD(arg1, f32 *, 0) < ((2.0f * M2C_FIELD(arg1, f32 *, 4)) + 4.0f))) {
                if (IsFlagSet(0x200U) != 0) {
                    var_f0_10108 = -((2.0f * var_f31_10013) - M2C_FIELD(arg1, f32 *, 0)) * M2C_FIELD(this->unk4, f32 *, 0x78);
                    if (var_f0_10108 > 4.0f) {

                    } else {
                        var_f0_10108 = 4.0f;
                    }
                    var_f30_10115 = var_f0_10108;
                } else {
                    temp_f2_10123 = M2C_FIELD(arg1, f32 *, 4) * M2C_FIELD(this->unk4, f32 *, 0x78);
                    temp_f0_10124 = -((2.0f * var_f31_10013) - M2C_FIELD(arg1, f32 *, 0));
                    if (temp_f0_10124 < temp_f2_10123) {
                        var_f30_10115 = temp_f0_10124;
                    } else {
                        var_f30_10115 = temp_f2_10123;
                    }
                }
                sp78 = var_f30_10115;
                sp7C = M2C_FIELD(arg1, f32 *, 4);
                sp80 = 0.0f;
                spD8 = (f64) sp78;
                spE0 = (f64) sp80;
                MKWidget_Resize(&this->unk138, *((MKVector3 *) &spD8));
                temp_f30_10148 = 0.5f * var_f30_10115;
                sp30 = 0.0f;
                sp2C = 0.5f * M2C_FIELD(arg1, f32 *, 4);
                sp28 = var_f31_10013 + temp_f30_10148;
                spD0 = (f64) sp30;
                spC8 = (f64) sp28;
                sp178 = (f64) sp28;
                sp180 = (f64) sp30;
                MKWidget_SendMessage(&this->unk138, 0x64U, (u32) &sp178);
                sp20 = 0.0f;
                sp18 = (M2C_FIELD(arg1, f32 *, 0) - var_f31_10013) - temp_f30_10148;
                sp1C = 0.5f * M2C_FIELD(arg1, f32 *, 4);
                spC0 = (f64) sp20;
                spB8 = (f64) sp18;
                sp178 = (f64) sp18;
                sp180 = (f64) sp20;
                MKWidget_SendMessage(&this->unk138, 0x65U, (u32) &sp178);
                MKWidget_Show(&this->unk138, 1);
            } else {
                MKWidget_Show(&this->unk138, 0);
            }
        }
        goto block_139;
    case 0x64:                                      /* switch 1 */
        temp_r4_10194 = this->unk4;
        temp_f1_10195 = M2C_FIELD(arg1, f32 *, 0);
        if (temp_f1_10195 != M2C_FIELD(temp_r4_10194, f32 *, 0x68)) {
            M2C_FIELD(temp_r4_10194, f32 *, 0x68) = temp_f1_10195;
            if (IsFlagSet(0x100U) != 0) {
                temp_r3_10204 = this->unk4;
                temp_f1_10206 = M2C_FIELD(temp_r3_10204, f32 *, 0x68);
                M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
                if (temp_f1_10206 == 0.0f) {
                    var_f0_10221 = (f32) (s32) (0.5f + temp_f1_10206);
                } else {
                    var_f0_10221 = (f32) (s32) (temp_f1_10206 - 0.5f);
                }
                M2C_FIELD(temp_r3_10204, f32 *, 0x68) = var_f0_10221;
            }
            GetThumbFromValue();
            sp168 = this;
            sp16C = 1;
            sp16E = 0;
            sp170 = this->unk4 + 0x68;
            sp174 = 0;
            MKWidget_SendMessage((MKWidget *) this, 0x39U, (u32) &sp168);
        }
        return 0;
    case 0x65:                                      /* switch 1 */
        M2C_FIELD(arg1, f32 *, 0) = (f32) M2C_FIELD(this->unk4, f32 *, 0x68);
        return 0;
    case 0x66:                                      /* switch 1 */
        M2C_FIELD(this->unk4, f32 *, 0x6C) = (f32) M2C_FIELD(arg1, f32 *, 0);
        temp_r4_10267 = this->unk4;
        if (M2C_FIELD(temp_r4_10267, f32 *, 0x6C) > M2C_FIELD(temp_r4_10267, f32 *, 0x68)) {
            MKWidget_SendMessage((MKWidget *) this, 0x64U, (u32) (temp_r4_10267 + 0x6C));
        }
        if (IsFlagSet(0x200U) != 0) {
            MKWidget_SendMessage((MKWidget *) this, 5U, (u32) (this->unk4 + 0x38));
        }
        GetThumbFromValue();
        return 0;
    case 0x67:                                      /* switch 1 */
        M2C_FIELD(this->unk4, f32 *, 0x70) = (f32) M2C_FIELD(arg1, f32 *, 0);
        temp_r4_10295 = this->unk4;
        if (M2C_FIELD(temp_r4_10295, f32 *, 0x70) < M2C_FIELD(temp_r4_10295, f32 *, 0x68)) {
            MKWidget_SendMessage((MKWidget *) this, 0x64U, (u32) (temp_r4_10295 + 0x70));
        }
        if (IsFlagSet(0x200U) != 0) {
            MKWidget_SendMessage((MKWidget *) this, 5U, (u32) (this->unk4 + 0x38));
        }
        GetThumbFromValue();
        return 0;
    case 0x6A:                                      /* switch 1 */
        M2C_FIELD(this->unk4, f32 *, 0x74) = (f32) M2C_FIELD(arg1, f32 *, 0);
        return 0;
    case 0x6B:                                      /* switch 1 */
        M2C_FIELD(this->unk4, f32 *, 0x78) = (f32) M2C_FIELD(arg1, f32 *, 0);
        MKWidget_SendMessage((MKWidget *) this, 5U, (u32) (this->unk4 + 0x38));
        return 0;
    case 0x1B:                                      /* switch 1 */
    case 0x1D:                                      /* switch 1 */
    case 0x1E:                                      /* switch 1 */
        temp_r28_10342 = MKWidget::MessageHandler(arg0, arg1);
        if (IsFlagSet(4U) != 0) {
            MKWidget_EnableFlag(&this->unk28, 4U);
            MKWidget_EnableFlag(&this->unkB0, 4U);
            MKWidget_EnableFlag(&this->unk138, 4U);
        } else {
            MKWidget_DisableFlag(&this->unk28, 4U);
            MKWidget_DisableFlag(&this->unkB0, 4U);
            MKWidget_DisableFlag(&this->unk138, 4U);
        }
        MKWidget_SendMessage((MKWidget *) this, 5U, (u32) (this->unk4 + 0x38));
        return temp_r28_10342;
    case 0x35:                                      /* switch 1 */
        if (M2C_FIELD(arg1, f32 *, 0) > 0.0f) {
            var_r4_10380 = 0x69;
        } else {
            var_r4_10380 = 0x68;
        }
        MKWidget_SendMessage((MKWidget *) this, var_r4_10380, 0U);
        return 0;
    case 0x30:                                      /* switch 1 */
    case 0x32:                                      /* switch 1 */
        if (arg1 == 1) {
            temp_r3_10392 = this->unk4;
            if (M2C_FIELD(temp_r3_10392, f32 *, 0x3C) > M2C_FIELD(temp_r3_10392, f32 *, 0x38)) {
                var_r28_10397 = 1;
            } else {
                var_r28_10397 = 0;
            }
            MKWidget_GetLocalMousePos((MKWidget *) this, &sp158);
            var_f30_10406 = 1.0f;
            if (((var_r28_10397 != 0) && (sp158.unk4 < M2C_FIELD(this->unk138.unk4, f32 *, 0xC))) || ((var_r28_10397 == 0) && (M2C_BITWISE(f32, sp158) < M2C_FIELD(this->unk138.unk4, f32 *, 8)))) {
                var_f30_10406 = -1.0f;
            }
            if (IsFlagSet(0x200U) != 0) {
                temp_r3_10429 = this->unk4;
                temp_f4_10431 = M2C_FIELD(temp_r3_10429, f32 *, 0x78);
                temp_f3_10437 = M2C_FIELD(temp_r3_10429, f32 *, 0x6C);
                var_f0_10440 = (var_f30_10406 * (temp_f4_10431 * ((M2C_FIELD(temp_r3_10429, f32 *, 0x70) - M2C_FIELD(temp_r3_10429, f32 *, 0x6C)) / (1.0f - temp_f4_10431)))) + M2C_FIELD(temp_r3_10429, f32 *, 0x68);
                if (var_f0_10440 > temp_f3_10437) {

                } else {
                    var_f0_10440 = temp_f3_10437;
                }
                temp_f1_10447 = M2C_FIELD(temp_r3_10429, f32 *, 0x70);
                if (var_f0_10440 < temp_f1_10447) {

                } else {
                    var_f0_10440 = temp_f1_10447;
                }
                sp10 = var_f0_10440;
            } else {
                temp_r3_10457 = this->unk4;
                temp_f2_10460 = M2C_FIELD(temp_r3_10457, f32 *, 0x6C);
                var_f0_10461 = (var_f30_10406 * M2C_FIELD(temp_r3_10457, f32 *, 0x74)) + M2C_FIELD(temp_r3_10457, f32 *, 0x68);
                if (var_f0_10461 > temp_f2_10460) {

                } else {
                    var_f0_10461 = temp_f2_10460;
                }
                temp_f1_10468 = M2C_FIELD(temp_r3_10457, f32 *, 0x70);
                if (var_f0_10461 < temp_f1_10468) {

                } else {
                    var_f0_10461 = temp_f1_10468;
                }
                sp10 = var_f0_10461;
            }
            if (sp10 != M2C_FIELD(this->unk4, f32 *, 0x68)) {
                MKWidget_SendMessage((MKWidget *) this, 0x64U, (u32) &sp10);
            }
        }
        goto block_139;
    case 0x68:                                      /* switch 1 */
        temp_r3_10488 = this->unk4;
        temp_f2_10491 = M2C_FIELD(temp_r3_10488, f32 *, 0x70);
        var_f0_10492 = M2C_FIELD(temp_r3_10488, f32 *, 0x68) + M2C_FIELD(temp_r3_10488, f32 *, 0x74);
        if (var_f0_10492 < temp_f2_10491) {

        } else {
            var_f0_10492 = temp_f2_10491;
        }
        spC = var_f0_10492;
        MKWidget_SendMessage((MKWidget *) this, 0x64U, (u32) &spC);
        GetThumbFromValue();
        return 0;
    case 0x69:                                      /* switch 1 */
        temp_r3_10509 = this->unk4;
        temp_f2_10512 = M2C_FIELD(temp_r3_10509, f32 *, 0x6C);
        var_f0_10513 = M2C_FIELD(temp_r3_10509, f32 *, 0x68) - M2C_FIELD(temp_r3_10509, f32 *, 0x74);
        if (var_f0_10513 > temp_f2_10512) {

        } else {
            var_f0_10513 = temp_f2_10512;
        }
        sp8 = var_f0_10513;
        MKWidget_SendMessage((MKWidget *) this, 0x64U, (u32) &sp8);
        GetThumbFromValue();
        return 0;
    case 0x2A:                                      /* switch 1 */
    case 0x2C:                                      /* switch 1 */
        temp_r3_10530 = this->unk4;
        if (M2C_FIELD(temp_r3_10530, f32 *, 0x3C) > M2C_FIELD(temp_r3_10530, f32 *, 0x38)) {
            var_r0_10535 = 1;
        } else {
            var_r0_10535 = 0;
        }
        if (var_r0_10535 != 0) {
            if (arg1 == 0x26) {
                return MKWidget_SendMessage((MKWidget *) this, 0x69U, 0U);
            }
            if (arg1 == 0x28) {
                return MKWidget_SendMessage((MKWidget *) this, 0x68U, 0U);
            }
            goto block_139;
        }
        if (arg1 == 0x25) {
            return MKWidget_SendMessage((MKWidget *) this, 0x69U, 0U);
        }
        if (arg1 == 0x27) {
            return MKWidget_SendMessage((MKWidget *) this, 0x68U, 0U);
        }
        goto block_139;
    case 0x39:                                      /* switch 1 */
        temp_r4_10574 = M2C_FIELD(arg1, f32 *, 0);
        if (M2C_BITWISE(u32, temp_r4_10574) == &this->unk138) {
            temp_r0_10578 = M2C_BITWISE(u16, M2C_FIELD(arg1, f32 *, 4));
            switch ((s32) temp_r0_10578) {          /* switch 2; irregular */
            case 1:                                 /* switch 2 */
                GetValueFromThumb();
                break;
            case 12:                                /* switch 2 */
                GetThumbFromValue();
                break;
            }
            return 0;
        }
        if ((M2C_BITWISE(u32, temp_r4_10574) == &this->unk28) && (M2C_BITWISE(u16, M2C_FIELD(arg1, f32 *, 4)) == 6)) {
            return MKWidget_SendMessage((MKWidget *) this, 0x68U, 0U);
        }
        if ((M2C_BITWISE(u32, temp_r4_10574) == &this->unkB0) && (M2C_BITWISE(u16, M2C_FIELD(arg1, f32 *, 4)) == 6)) {
            return MKWidget_SendMessage((MKWidget *) this, 0x69U, 0U);
        }
        goto block_139;
    }
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
MKWidgetScrollBar::MKWidgetScrollBar(MKWidgetDescriptor *arg0) {
    this->unk28.unk18 = (MKWidget *) this;
    this->unkB0.unk18 = (MKWidget *) this;
    this->unk138.unk18 = (MKWidget *) this;
    MKWidget_DisableFlag(&this->unk28, 4U);
    MKWidget_EnableFlag(&this->unk28, 0x800U);
    MKWidget_DisableFlag(&this->unkB0, 4U);
    MKWidget_EnableFlag(&this->unkB0, 0x800U);
    MKWidget_DisableFlag(&this->unk138, 4U);
    if ((u8) this->unk8 == 0) {
        M2C_FIELD(this->unk4, f32 *, 0x68) = 0.0f;
        M2C_FIELD(this->unk4, f32 *, 0x6C) = 0.0f;
        M2C_FIELD(this->unk4, f32 *, 0x70) = 1.0f;
        M2C_FIELD(this->unk4, f32 *, 0x74) = 0.1f;
        M2C_FIELD(this->unk4, f32 *, 0x78) = 1.0f;
    }
    return this;
}
#endif

void MKWidgetThumb::BuildAggregateMetaData() {

}

void MKWidgetThumb::BuildMetaData(int arg0) {

}

#if 0 // DRAFT: undefined identifier 'zero'
void MKWidgetThumb::Render(MKWidgetRenderContext *arg0) {
    MKVector4 *temp_r31_10768;
    s8 **temp_r30_10765;

    MKWidget::Render(arg0);
    MKMaterial_SetMaterial(pWidgetBlank);
    MKPrimitive(4, 0);
    MKSetBaseColorV(arg0->unk40);
    MKSetMatrix(*((Matrix *) arg0));
    WidgetDrawBox(zero, *(MKVector3 *) (this->unk4 + 0x38), 0x1A);
    temp_r30_10765 = this->unk4;
    temp_r31_10768 = MKWidget_GetMetric(1);
    WidgetDrawBevel(zero, *(MKVector3 *) (temp_r30_10765 + 0x38), 1.0f, *(MKWidget_GetMetric(0)), *temp_r31_10768, 0U, 0U);
    MKEndPrimitive();
}
#endif

#if 0 // DRAFT: undefined identifier 'sp78'
s32 MKWidgetThumb::MessageHandler(unsigned int arg0, unsigned int arg1) {
    f64 sp1F0;                                      /* compiler-managed */
    f64 sp1E8;
    f64 sp1E0;                                      /* compiler-managed */
    f64 sp1D8;
    s32 sp1D4;
    s32 sp1D0;
    s16 sp1CE;
    s16 sp1CC;
    MKWidgetThumb *sp1C8;
    s32 sp1C4;
    s32 sp1C0;
    s16 sp1BE;
    s16 sp1BC;
    MKWidgetThumb *sp1B8;
    MKVector3 sp1A8;                                /* compiler-managed */
    f64 sp1A0;
    f64 sp198;
    s32 sp194;
    s32 sp190;
    s16 sp18E;
    s16 sp18C;
    MKWidgetThumb *sp188;
    f64 sp180;
    f64 sp178;
    MKVector3 sp168;
    MKVector3 sp158;
    MKVector3 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    MKVector3 sp118;
    MKVector3 sp108;
    MKVector3 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    MKVector3 spA8;
    MKVector3 sp98;
    f64 sp90;
    f64 sp88;
    f32 sp80;
    f32 sp70;
    f32 sp60;
    f32 sp50;
    f32 sp40;
    f32 sp30;
    f32 sp20;
    f32 sp10;
    f32 temp_f2_11074;
    s8 **temp_r3_10999;
    s8 **temp_r3_11054;
    u8 var_r0_11070;

    switch ((s32) arg0) {                           /* irregular */
    case 0x64:
        M2C_FIELD(this, f64 *, 0x28) = (f64) M2C_FIELD(arg1, f64 *, 0);
        this->unk30 = M2C_FIELD(arg1, f64 *, 8);
        sp168.operator*(0.5f);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp178 = sp78;
        sp80 = M2C_FIELD((this->unk4 + 8), f32 *, 8) + sp168.unk8;
        sp1E8 = sp78;
        sp180 = (f64) sp80;
        sp1F0 = (f64) sp80;
        Max(sp148, *((MKVector3 *) &sp1E8));
        Min(sp158, sp148);
        sp1E8 = M2C_BITWISE(f64, sp158);
        sp1F0 = (f64) sp158.unk8;
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
        sp138 = sp68;
        sp70 = M2C_FIELD((this->unk4 + 0x38), f32 *, 8) * 0.5f;
        sp140 = (f64) sp70;
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp1F0 = (f32) sp1F0 - (f32) sp140;
        MKWidget_Move((MKWidget *) this, *((MKVector3 *) &sp1E8));
        return 0;
    case 0x65:
        M2C_FIELD(this, f64 *, 0x38) = (f64) M2C_FIELD(arg1, f64 *, 0);
        this->unk40 = M2C_FIELD(arg1, f64 *, 8);
        sp118.operator*(0.5f);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp128 = sp58;
        sp60 = M2C_FIELD((this->unk4 + 8), f32 *, 8) + sp118.unk8;
        sp1D8 = sp58;
        sp130 = (f64) sp60;
        sp1E0 = (f64) sp60;
        Max(spF8, *((MKVector3 *) &sp1D8));
        Min(sp108, spF8);
        sp1D8 = M2C_BITWISE(f64, sp108);
        sp1E0 = (f64) sp108.unk8;
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
        spE8 = sp48;
        sp50 = M2C_FIELD((this->unk4 + 0x38), f32 *, 8) * 0.5f;
        spF0 = (f64) sp50;
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp1E0 = (f32) sp1E0 - (f32) spF0;
        MKWidget_Move((MKWidget *) this, *((MKVector3 *) &sp1D8));
        return 0;
    case 0x30:
        if (arg1 & 1) {
            MKWidget_GetLocalMousePos((MKWidget *) this, &this->unk48);
            MKWidget_SetMouseFocus((MKWidget *) this);
            this->unk58 = 1;
            sp1C8 = this;
            sp1CC = 0xB;
            sp1CE = 0;
            sp1D0 = 0;
            sp1D4 = 0;
            MKWidget_SendMessage((MKWidget *) this, 0x39U, (u32) &sp1C8);
        }
block_23:
    default:
        return MKWidget::MessageHandler(arg0, arg1);
    case 0x31:
        if (arg1 & 1) {
            MKWidget_ReleaseMouseFocus();
            this->unk58 = 0;
            sp1B8 = this;
            sp1BC = 0xC;
            sp1BE = 0;
            sp1C0 = 0;
            sp1C4 = 0;
            MKWidget_SendMessage((MKWidget *) this, 0x39U, (u32) &sp1B8);
        }
        goto block_23;
    case 0x2E:
        if ((u8) this->unk58 != 0) {
            MKWidget_GetLocalMousePos((MKWidget *) this, &sp1A8);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $r29, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            temp_r3_10999 = this->unk4;
            sp198 = sp38;
            sp40 = sp1A8.unk8 - this->unk48.unk8;
            spD8 = sp38;
            spE0 = (f64) sp40;
            sp1A0 = (f64) sp40;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp1A8 = sp28;
            spC8 = sp28;
            sp30 = M2C_FIELD((temp_r3_10999 + 8), f32 *, 8) + (f32) sp1A0;
            sp1A8.unk8 = (f64) sp30;
            spD0 = (f64) sp30;
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            spB8 = sp18;
            sp20 = M2C_FIELD((temp_r3_10999 + 0x38), f32 *, 8) * 0.5f;
            spC0 = (f64) sp20;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp1A8.unk8 += (f32) spC0;
            Max(sp98, sp1A8);
            Min(spA8, sp98);
            sp1A8 = M2C_BITWISE(f64, spA8);
            sp1A8.unk8 = (f64) spA8.unk8;
            temp_r3_11054 = this->unk4;
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
            sp88 = sp8;
            sp10 = M2C_FIELD(temp_r3_11054, f32 *, 0x40) * 0.5f;
            sp90 = (f64) sp10;
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            var_r0_11070 = 0;
            temp_f2_11074 = (f32) sp1A8.unk8 - (f32) sp90;
            sp1A8.unk8 = temp_f2_11074;
            if (((f32) sp1A8 == M2C_FIELD(temp_r3_11054, f32 *, 8)) && (sp1A8.unk4 == M2C_FIELD(temp_r3_11054, f32 *, 0xC)) && (temp_f2_11074 == M2C_FIELD(temp_r3_11054, f32 *, 0x10))) {
                var_r0_11070 = 1;
            }
            if (var_r0_11070 == 0) {
                MKWidget_SendMessage((MKWidget *) this, 4U, (u32) &sp1A8);
                sp188 = this;
                sp18C = 1;
                sp18E = 0;
                sp190 = 0;
                sp194 = 0;
                MKWidget_SendMessage((MKWidget *) this, 0x39U, (u32) &sp188);
            }
        }
        goto block_23;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'zero'
MKWidgetThumb::MKWidgetThumb(MKWidgetDescriptor *arg0) {
    M2C_FIELD(this, f64 *, 0x28) = (f64) M2C_FIELD(&zero, f64 *, 0);
    this->unk30 = M2C_FIELD(&zero, f64 *, 8);
    M2C_FIELD(this, f64 *, 0x38) = (f64) M2C_FIELD(&zero, f64 *, 0);
    this->unk40 = M2C_FIELD(&zero, f64 *, 8);
    this->unk58 = 0;
    return this;
}
#endif

void MKWidgetCheckBox::BuildAggregateMetaData() {

}

void MKWidgetCheckBox::BuildMetaData(int arg0) {

}

#if 0 // DRAFT: illegal implicit conversion from 'double *' to
MKWidget *MKWidgetCheckBox::TestPoint(MKVector3 *arg0) {
    f64 sp20;
    f64 sp18;
    f64 sp10;
    f64 sp8;
    MKWidget *temp_r3_11185;
    MKWidget *temp_r3_11199;
    MKWidget *var_r31_11174;
    f64 temp_f1_11176;
    f64 temp_f1_11190;

    var_r31_11174 = MKWidget::TestPoint(arg0);
    if (var_r31_11174 != NULL) {
        temp_f1_11176 = M2C_FIELD(arg0, f64 *, 0);
        sp18 = temp_f1_11176;
        sp20 = M2C_FIELD(arg0, f64 *, 8);
        temp_r3_11185 = this->unk54.GetWidgetUnderPoint(&sp18, temp_f1_11176);
        if (temp_r3_11185 != NULL) {
            var_r31_11174 = temp_r3_11185;
        }
        temp_f1_11190 = M2C_FIELD(arg0, f64 *, 0);
        sp8 = temp_f1_11190;
        sp10 = M2C_FIELD(arg0, f64 *, 8);
        temp_r3_11199 = this->unk28.GetWidgetUnderPoint(&sp8, temp_f1_11190);
        if (temp_r3_11199 != NULL) {
            var_r31_11174 = temp_r3_11199;
        }
    }
    return var_r31_11174;
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp5C'
void MKWidgetCheckBox::Render(MKWidgetRenderContext *arg0) {
    MKWidget::Render(arg0);
    M2C_STRUCT_COPY((s32) &arg_sp5C + 4, (s32) (arg0 - 4) + 4, 0x50);
    this->unk28.Draw(&arg_sp60, &arg_sp5C + 0x50);
    M2C_STRUCT_COPY((s32) &arg_spC + 4, (s32) (arg0 - 4) + 4, 0x50);
    this->unk54.Draw(&arg_sp10, &arg_spC + 0x50);
}
#endif

#if 0 // DRAFT: identifier 'MKWidgetCheckBox::MessageHandler(unsigned int, unsigned int)'
void MKWidgetCheckBox::MessageHandler(unsigned int arg0, unsigned int arg1) {
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
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_11340;
    f32 temp_f2_11361;

    if ((s32) arg0 < 0x17) {
        switch ((s32) arg0) {                       /* irregular */
        case 2:
            MKWidget_SendMessage(&this->unk54, 0x17U, (u32) *this->unk4);
            break;
        case 20:
            MKWidget_SendMessage(&this->unk28, arg0, arg1);
            break;
        case 5:
            temp_f1_11340 = M2C_FIELD(arg1, f32 *, 4) - 2.0f;
            sp30 = 0.0f;
            sp28 = temp_f1_11340;
            sp2C = temp_f1_11340;
            sp60 = (f64) sp30;
            sp58 = (f64) sp28;
            MKWidget_Resize(&this->unk28, *((MKVector3 *) &sp58));
            sp20 = 0.0f;
            sp18 = M2C_FIELD(arg1, f32 *, 4);
            sp1C = 0.0f;
            sp50 = (f64) sp20;
            sp48 = (f64) sp18;
            MKWidget_Move(&this->unk54, *((MKVector3 *) &sp48));
            temp_f2_11361 = M2C_FIELD(arg1, f32 *, 4);
            spC = temp_f2_11361;
            sp10 = 0.0f;
            sp8 = M2C_FIELD(arg1, f32 *, 0) - temp_f2_11361;
            sp40 = (f64) sp10;
            sp38 = (f64) sp8;
            MKWidget_Resize(&this->unk54, *((MKVector3 *) &sp38));
            break;
        default:
            MKWidget_SendMessage(&this->unk28, arg0, arg1);
            break;
        }
        goto block_30;
    }
    if ((s32) arg0 != 0x45) {
        if ((s32) arg0 < 0x45) {
            if ((s32) arg0 != 0x39) {
                if ((s32) arg0 < 0x39) {
                    if ((s32) arg0 < 0x19) {
                        goto block_22;
                    }
                    goto block_30;
                }
                if ((s32) arg0 < 0x42) {
                    goto block_30;
                }
block_22:
                MKWidget_SendMessage(&this->unk54, arg0, arg1);
                return;
            }
            if (M2C_BITWISE(u32, M2C_FIELD(arg1, f32 *, 0)) == &this->unk28) {
                M2C_FIELD(arg1, f32 *, 0) = M2C_BITWISE(f32, this);
            }
            goto block_30;
        }
        if ((s32) arg0 < 0x66) {
            if ((s32) arg0 < 0x64) {
                goto block_30;
            }
            MKWidget_SendMessage(&this->unk28, arg0, arg1);
            return;
        }
block_30:
        MKWidget::MessageHandler(arg0, arg1);
        return;
    }
    MKWidget_SendMessage(&this->unk54, 8U, arg1);
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
MKWidgetCheckBox::MKWidgetCheckBox(MKWidgetDescriptor *arg0) {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;

    this->unk54.unk18 = (MKWidget *) this;
    this->unk28.unk18 = (MKWidget *) this;
    if ((u8) this->unk8 == 0) {
        sp8 = 1.0f;
        spC = 1.0f;
        sp10 = 0.0f;
        sp18 = (f64) sp8;
        sp20 = (f64) sp10;
        MKWidget_Move(&this->unk28, *((MKVector3 *) &sp18));
        MKWidget_SendMessage(&this->unk54, 0x44U, 0U);
        MKWidget_EnableFlag(&this->unk54, 0x100U);
    }
    return this;
}
#endif

void MKWidgetCheckMark::BuildAggregateMetaData() {

}

void MKWidgetCheckMark::BuildMetaData(int arg0) {

}

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void MKWidgetCheckMark::Render(MKWidgetRenderContext *arg0) {
    f64 sp70;
    f64 sp68;
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
    f32 sp10;
    MKVector4 *temp_r30_11518;
    s8 **temp_r29_11515;
    s8 **temp_r3_11603;
    s8 **temp_r3_11614;
    void *temp_r3_11539;
    void *temp_r3_11547;

    MKWidget::Render(arg0);
    MKMaterial_SetMaterial(pWidgetBlank);
    MKPrimitive(4, 0);
    MKSetBaseColorV(arg0->unk40);
    MKSetMatrix(*((Matrix *) arg0));
    temp_r29_11515 = this->unk4;
    temp_r30_11518 = MKWidget_GetMetric(1);
    WidgetDrawBevel(zero, *(MKVector3 *) (temp_r29_11515 + 0x38), 1.0f, *(MKWidget_GetMetric(0)), *temp_r30_11518, 1U, 0U);
    if (((u8) this->unk29 != 0) || ((s32) M2C_FIELD(this->unk4, s32 *, 0x68) == 2)) {
        temp_r3_11539 = MKWidget_GetMetric(0x1A);
        sp68 = M2C_FIELD(temp_r3_11539, f64 *, 0);
        sp70 = M2C_FIELD(temp_r3_11539, f64 *, 8);
    } else {
        temp_r3_11547 = MKWidget_GetMetric(0x1E);
        sp68 = M2C_FIELD(temp_r3_11547, f64 *, 0);
        sp70 = M2C_FIELD(temp_r3_11547, f64 *, 8);
    }
    sp18 = 1.0f;
    sp1C = 1.0f;
    sp20 = 0.0f;
    sp38 = (f64) sp18;
    sp40 = (f64) sp20;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    sp30 = 0.0f;
    sp28 = 1.0f;
    sp10 = M2C_FIELD((this->unk4 + 0x38), f32 *, 8) - (f32) sp40;
    sp2C = 1.0f;
    sp48 = sp8;
    sp50 = (f64) sp10;
    sp58 = (f64) sp28;
    sp60 = (f64) sp30;
    WidgetDrawBox(*((MKVector3 *) &sp58), *((MKVector3 *) &sp48), *((MKVector4 *) &sp68));
    if ((s32) M2C_FIELD(this->unk4, s32 *, 0x68) != 0) {
        MKBegin(4);
        MKSetColorV(identity);
        MKSetPositionF(1.0f, 0.5f * M2C_FIELD(this->unk4, f32 *, 0x3C), 0.0f);
        temp_r3_11603 = this->unk4;
        MKSetPositionF(0.4f * M2C_FIELD(temp_r3_11603, f32 *, 0x38), 0.7f * (M2C_FIELD(temp_r3_11603, f32 *, 0x3C) - 1.0f), 0.0f);
        temp_r3_11614 = this->unk4;
        MKSetPositionF(0.4f * M2C_FIELD(temp_r3_11614, f32 *, 0x38), M2C_FIELD(temp_r3_11614, f32 *, 0x3C) - 1.0f, 0.0f);
        MKSetPositionF(M2C_FIELD(this->unk4, f32 *, 0x38) - 1.0f, 1.0f, 0.0f);
        MKEnd();
    }
    MKEndPrimitive();
}
#endif

#if 0 // DRAFT: identifier 'MKWidgetCheckMark::MessageHandler(unsigned int, unsigned int)'
u32 MKWidgetCheckMark::MessageHandler(unsigned int arg0, unsigned int arg1) {
    MKVector3 sp28;
    s32 sp24;
    u32 sp20;
    s16 sp1E;
    s16 sp1C;
    MKWidgetCheckMark *sp18;
    s32 sp14;
    u32 sp10;
    s16 spE;
    s16 spC;
    MKWidgetCheckMark *sp8;
    f32 temp_f1_11695;
    s8 **temp_r3_11702;
    s8 **temp_r8_11732;

    if ((s32) arg0 != 0x32) {
        switch ((s32) arg0) {                       /* irregular */
        case 0x30:
            if (arg1 == 1) {
                MKWidget_SetMouseFocus((MKWidget *) this);
                this->unk28 = 1;
                this->unk29 = 1;
            }
            goto block_29;
        case 0x31:
            if (arg1 == 1) {
                MKWidget_ReleaseMouseFocus();
                this->unk28 = 0;
                this->unk29 = 0;
            }
            goto block_29;
        case 0x2E:
            if ((u8) this->unk28 != 0) {
                MKWidget_GetLocalMousePos((MKWidget *) this, &sp28);
                temp_f1_11695 = M2C_BITWISE(f32, sp28);
                if ((temp_f1_11695 < 0.0f) || (sp28.unk4 < 0.0f) || (temp_r3_11702 = this->unk4, M2C_ERROR(/* unknown instruction: cror eq, gt, eq */), ((temp_f1_11695 == M2C_FIELD(temp_r3_11702, f32 *, 0x38)) != 0)) || (M2C_ERROR(/* unknown instruction: cror eq, gt, eq */), ((sp28.unk4 == M2C_FIELD(temp_r3_11702, f32 *, 0x3C)) != 0))) {
                    this->unk29 = 0;
                } else {
                    this->unk29 = 1;
                }
            }
            goto block_29;
        default:
            sp18 = this;
            sp1C = 6;
            sp1E = 0;
            sp20 = arg1;
            sp24 = 0;
            MKWidget_SendMessage((MKWidget *) this, 0x39U, (u32) &sp18);
            if (arg1 == 1) {
                temp_r8_11732 = this->unk4;
                M2C_FIELD(temp_r8_11732, u32 *, 0x68) = (u32) (u8) (M2C_FIELD(temp_r8_11732, u32 *, 0x68) == 0);
                sp8 = this;
                spC = 1;
                spE = 0;
                sp10 = M2C_FIELD(this->unk4, u32 *, 0x68);
                sp14 = 0;
                MKWidget_SendMessage((MKWidget *) this, 0x39U, (u32) &sp8);
            }
            goto block_29;
        case 0x64:
            M2C_FIELD(this->unk4, u32 *, 0x68) = arg1;
            return 0U;
        case 0x65:
            return M2C_FIELD(this->unk4, u32 *, 0x68);
        }
    } else {
    case 0x2F:
block_29:
        return MKWidget::MessageHandler(arg0, arg1);
    }
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
MKWidgetCheckMark::MKWidgetCheckMark(MKWidgetDescriptor *arg0) {
    if ((u8) this->unk8 == 0) {
        M2C_FIELD(this->unk4, s32 *, 0x68) = 0;
    }
    this->unk28 = 0;
    this->unk29 = 0;
    return this;
}
#endif

void MKWidgetButton::BuildAggregateMetaData() {

}

void MKWidgetButton::BuildMetaData(int arg0) {

}

#if 0 // DRAFT: illegal implicit conversion from 'double *' to
MKWidget *MKWidgetButton::TestPoint(MKVector3 *arg0) {
    f64 sp10;
    f64 sp8;
    MKWidget *temp_r3_11836;
    MKWidget *var_r31_11825;
    f64 temp_f1_11827;

    var_r31_11825 = MKWidget::TestPoint(arg0);
    if (var_r31_11825 != NULL) {
        temp_f1_11827 = M2C_FIELD(arg0, f64 *, 0);
        sp8 = temp_f1_11827;
        sp10 = M2C_FIELD(arg0, f64 *, 8);
        temp_r3_11836 = this->unk28.GetWidgetUnderPoint(&sp8, temp_f1_11827);
        if (temp_r3_11836 != NULL) {
            var_r31_11825 = temp_r3_11836;
        }
    }
    return var_r31_11825;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void MKWidgetButton::Render(MKWidgetRenderContext *arg0) {
    MKVector4 *temp_r29_11883;
    s32 var_r5_11897;
    u8 var_r28_11872;
    MKWidget::Render(arg0);
    MKMaterial_SetMaterial(pWidgetBlank);
    MKPrimitive(4, 0);
    MKSetBaseColorV(arg0->unk40);
    MKSetMatrix(*((Matrix *) arg0));
    var_r28_11872 = 0;
    if (((u8) this->unk85 != 0) || ((s32) this->unk80 > 0)) {
        var_r28_11872 = 1;
    }
    temp_r29_11883 = MKWidget_GetMetric(1);
    WidgetDrawBevel(zero, *(MKVector3 *) (this->unk4 + 0x38), 1.0f, *(MKWidget_GetMetric(0)), *temp_r29_11883, var_r28_11872, 0U);
    var_r5_11897 = 0x1A;
    if ((s32) this->unk80 > 1) {
        var_r5_11897 = 0x1E;
    }
    arg_sp30 = 1.0f;
    arg_sp34 = 1.0f;
    arg_sp38 = 0.0f;
    arg_sp60 = (f64) arg_sp30;
    arg_sp68 = (f64) arg_sp38;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    arg_sp48 = 0.0f;
    arg_sp28 = M2C_FIELD((this->unk4 + 0x38), f32 *, 8) - (f32) arg_sp68;
    arg_sp40 = 1.0f;
    arg_sp44 = 1.0f;
    arg_sp70 = arg_sp20;
    arg_sp78 = (f64) arg_sp28;
    arg_sp80 = (f64) arg_sp40;
    arg_sp88 = (f64) arg_sp48;
    WidgetDrawBox(*((MKVector3 *) &arg_sp80), *((MKVector3 *) &arg_sp70), var_r5_11897);
    MKEndPrimitive();
    if (IsFlagSet(0x2000U) != 0) {
        M2C_STRUCT_COPY((s32) &arg_sp12C + 4, (s32) (arg0 - 4) + 4, 0x50);
        this->unk54.Draw(&arg_sp130, &arg_sp12C + 0x50);
    }
    if ((u8) this->unk85 != 0) {
        arg_sp10 = 1.0f;
        arg_sp14 = 1.0f;
        arg_sp18 = 0.0f;
        arg_sp50 = (f64) arg_sp10;
        arg_sp58 = (f64) arg_sp18;
        arg0->Translate((Matrix *) arg0, *((MKVector3 *) &arg_sp50));
    }
    if (IsFlagSet(0x1000U) != 0) {
        M2C_STRUCT_COPY((s32) &arg_spDC + 4, (s32) (arg0 - 4) + 4, 0x50);
        this->unk54.Draw(&arg_spE0, &arg_spDC + 0x50);
    }
    if (IsFlagSet(0x2000U) == 0) {
        M2C_STRUCT_COPY((s32) &arg_sp8C + 4, (s32) (arg0 - 4) + 4, 0x50);
        this->unk28.Draw(&arg_sp90, &arg_sp8C + 0x50);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'sp88'
s32 MKWidgetButton::MessageHandler(unsigned int arg0, unsigned int arg1) {
    s32 sp1C4;
    u32 sp1C0;
    s16 sp1BE;
    s16 sp1BC;
    MKWidgetButton *sp1B8;
    MKVector3 sp1A8;
    s32 sp1A4;
    u32 sp1A0;
    s16 sp19E;
    s16 sp19C;
    MKWidgetButton *sp198;
    s32 sp194;
    s32 sp190;
    s16 sp18E;
    s16 sp18C;
    MKWidgetButton *sp188;
    s32 sp184;
    u32 sp180;
    s16 sp17E;
    s16 sp17C;
    MKWidgetButton *sp178;
    s32 sp174;
    s32 sp170;
    s16 sp16E;
    s16 sp16C;
    MKWidgetButton *sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp90;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 temp_f1_12338;
    f32 temp_f30_12166;
    f32 temp_f31_12169;
    s32 temp_r0_12389;
    s32 temp_r30_12109;
    s32 temp_r30_12292;
    s8 **temp_r3_12345;

    if ((s32) arg0 != 0x2F) {
        if ((s32) arg0 < 0x2F) {
            if ((s32) arg0 < 0x19) {
                switch ((s32) arg0) {               /* switch 1; irregular */
                case 2:                             /* switch 1 */
                    MKWidget_SendMessage(&this->unk28, 0x17U, (u32) M2C_FIELD(this->unk4, s8 **, 0));
                    goto block_71;
                default:                            /* switch 1 */
                    temp_r30_12109 = MKWidget::MessageHandler(arg0, arg1);
                    if (IsFlagSet(0x2000U) != 0) {
                        spA8 = 1.0f;
                        spAC = 1.0f;
                        spB0 = 0.0f;
                        sp158 = (f64) spA8;
                        sp160 = (f64) spB0;
                        MKWidget_Move(&this->unk54, *((MKVector3 *) &sp158));
                        sp98 = 2.0f;
                        sp9C = 2.0f;
                        spA0 = 0.0f;
                        sp138 = (f64) sp98;
                        sp140 = (f64) spA0;
                        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
                        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                        sp148 = sp88;
                        sp90 = M2C_FIELD((this->unk4 + 0x38), f32 *, 8) - (f32) sp140;
                        sp150 = (f64) sp90;
                        MKWidget_Resize(&this->unk54, *((MKVector3 *) &sp148));
                    } else if (IsFlagSet(0x1000U) != 0) {
                        temp_f30_12166 = M2C_FIELD(this->unk4, f32 *, 0x3C) - 6.0f;
                        sp80 = 0.0f;
                        temp_f31_12169 = 3.0f + temp_f30_12166;
                        sp7C = 3.0f;
                        sp130 = (f64) sp80;
                        sp78 = 2.0f + temp_f31_12169;
                        sp128 = (f64) sp78;
                        MKWidget_Move(&this->unk28, *((MKVector3 *) &sp128));
                        sp70 = 0.0f;
                        sp6C = 6.0f;
                        sp68 = 2.0f + (6.0f + temp_f30_12166);
                        sp110 = (f64) sp70;
                        sp108 = (f64) sp68;
                        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
                        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                        sp118 = sp58;
                        sp60 = M2C_FIELD((this->unk4 + 0x38), f32 *, 8) - (f32) sp110;
                        sp120 = (f64) sp60;
                        MKWidget_Resize(&this->unk28, *((MKVector3 *) &sp118));
                        sp48 = 3.0f;
                        sp4C = 3.0f;
                        sp50 = 0.0f;
                        spF8 = (f64) sp48;
                        sp100 = (f64) sp50;
                        MKWidget_Move(&this->unk54, *((MKVector3 *) &spF8));
                        sp38 = temp_f31_12169;
                        sp3C = temp_f31_12169;
                        sp40 = 0.0f;
                        spE8 = (f64) sp38;
                        spF0 = (f64) sp40;
                        MKWidget_Resize(&this->unk54, *((MKVector3 *) &spE8));
                    } else if (IsFlagSet(0x3000U) == 0) {
                        sp28 = 3.0f;
                        sp2C = 3.0f;
                        sp30 = 0.0f;
                        spD8 = (f64) sp28;
                        spE0 = (f64) sp30;
                        MKWidget_Move(&this->unk28, *((MKVector3 *) &spD8));
                        sp18 = 6.0f;
                        sp1C = 6.0f;
                        sp20 = 0.0f;
                        spB8 = (f64) sp18;
                        spC0 = (f64) sp20;
                        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
                        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                        spC8 = sp8;
                        sp10 = M2C_FIELD((this->unk4 + 0x38), f32 *, 8) - (f32) spC0;
                        spD0 = (f64) sp10;
                        MKWidget_Resize(&this->unk28, *((MKVector3 *) &spC8));
                    }
                    return temp_r30_12109;
                }
            } else {
                if ((s32) arg0 != 0x1C) {
                    if ((s32) arg0 < 0x1C) {
                        if ((s32) arg0 < 0x1B) {
                            goto block_71;
                        }
                        goto block_40;
                    }
                    if ((s32) arg0 < 0x2E) {
                        if ((s32) arg0 < 0x1F) {
block_40:
                            if (arg1 & 0x300) {
                                return MKWidget_SendMessage(&this->unk28, arg0, arg1);
                            }
                            temp_r30_12292 = MKWidget::MessageHandler(arg0, arg1);
                            MKWidget_Resize((MKWidget *) this, *(MKVector3 *) (this->unk4 + 0x38));
                            return temp_r30_12292;
                        }
                        goto block_71;
                    }
                    if ((u8) this->unk84 != 0) {
                        MKWidget_GetLocalMousePos((MKWidget *) this, &sp1A8);
                        temp_f1_12338 = M2C_BITWISE(f32, sp1A8);
                        if ((temp_f1_12338 < 0.0f) || (sp1A8.unk4 < 0.0f) || (temp_r3_12345 = this->unk4, M2C_ERROR(/* unknown instruction: cror eq, gt, eq */), ((temp_f1_12338 == M2C_FIELD(temp_r3_12345, f32 *, 0x38)) != 0)) || (M2C_ERROR(/* unknown instruction: cror eq, gt, eq */), ((sp1A8.unk4 == M2C_FIELD(temp_r3_12345, f32 *, 0x3C)) != 0))) {
                            this->unk85 = 0;
                        } else {
                            this->unk85 = 1;
                        }
                    }
                    goto block_71;
                }
                if (arg1 & 0x300) {
                    return MKWidget_SendMessage(&this->unk28, arg0, arg1);
                }
                goto block_71;
            }
        } else if ((s32) arg0 != 0x45) {
            if ((s32) arg0 < 0x45) {
                if ((s32) arg0 != 0x32) {
                    if ((s32) arg0 < 0x32) {
                        if ((s32) arg0 < 0x31) {
                            MKWidget_SetMouseFocus((MKWidget *) this);
                            this->unk84 = 1;
                            this->unk85 = 1;
                            if (IsFlagSet(0x800U) != 0) {
                                sp1B8 = this;
                                sp1BC = 6;
                                sp1BE = 0;
                                sp1C0 = arg1;
                                sp1C4 = 0;
                                MKWidget_SendMessage((MKWidget *) this, 0x39U, (u32) &sp1B8);
                            }
                        } else {
                            MKWidget_ReleaseMouseFocus();
                            this->unk84 = 0;
                            this->unk85 = 0;
                        }
                        goto block_71;
                    }
                    if ((s32) arg0 < 0x42) {
                        if ((s32) arg0 < 0x35) {
                            if (IsFlagSet(0x800U) == 0) {
                                if (IsFlagSet(0x400U) != 0) {
                                    temp_r0_12389 = this->unk80;
                                    if (temp_r0_12389 == 2) {
                                        this->unk80 = 1;
                                    } else {
                                        this->unk80 = 1 - temp_r0_12389;
                                    }
                                    sp188 = this;
                                    sp18C = 1;
                                    sp18E = 0;
                                    sp190 = this->unk80;
                                    sp194 = 0;
                                    MKWidget_SendMessage((MKWidget *) this, 0x39U, (u32) &sp188);
                                }
                                sp178 = this;
                                sp17C = 6;
                                sp17E = 0;
                                sp180 = arg1;
                                sp184 = 0;
                                MKWidget_SendMessage((MKWidget *) this, 0x39U, (u32) &sp178);
                            }
                        }
                        goto block_71;
                    }
                    return MKWidget_SendMessage(&this->unk28, arg0, arg1);
                }
                if (IsFlagSet(0x800U) != 0) {
                    sp198 = this;
                    sp19C = 6;
                    sp19E = 0;
                    sp1A0 = arg1;
                    sp1A4 = 0;
                    MKWidget_SendMessage((MKWidget *) this, 0x39U, (u32) &sp198);
                }
                goto block_71;
            }
            switch ((s32) arg0) {                   /* switch 2; irregular */
            case 0x64:                              /* switch 2 */
                if ((s32) this->unk80 != (s32) arg1) {
                    this->unk80 = (s32) arg1;
                    sp168 = this;
                    sp16C = 1;
                    sp16E = 0;
                    sp170 = this->unk80;
                    sp174 = 0;
                    MKWidget_SendMessage((MKWidget *) this, 0x39U, (u32) &sp168);
                }
                return 0;
            default:                                /* switch 2 */
                MKWidget_SendMessage(&this->unk54, arg0, arg1);
                goto block_71;
            case 0x65:                              /* switch 2 */
                return this->unk80;
            }
        } else {
            return MKWidget_SendMessage(&this->unk28, 8U, arg1);
        }
    } else {
    case 3:                                         /* switch 1 */
block_71:
        return MKWidget::MessageHandler(arg0, arg1);
    }
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
MKWidgetButton::MKWidgetButton(MKWidgetDescriptor *arg0) {
    this->unk84 = 0;
    this->unk85 = 0;
    this->unk80 = 0;
    this->unk28.unk18 = (MKWidget *) this;
    this->unk54.unk18 = (MKWidget *) this;
    if ((u8) this->unk8 == 0) {
        MKWidget_SendMessage(&this->unk28, 0x44U, 1U);
        MKWidget_EnableFlag(&this->unk28, 0x100U);
    }
    return this;
}
#endif

void MKWidgetString::BuildAggregateMetaData() {

}

void MKWidgetString::BuildMetaData(int arg0) {

}

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void MKWidgetString::Render(MKWidgetRenderContext *arg0) {
    MKFont *var_r31_12576;
    f32 temp_f1_12597;
    f32 temp_f2_12601;
    f32 var_f3_12589;
    s8 **temp_r6_12595;

    MKWidget::Render(arg0);
    if ((s8 *) M2C_FIELD(this->unk4, s8 **, 0x68) != NULL) {
        var_r31_12576 = this->unk28;
        if (var_r31_12576 != NULL) {

        } else {
            var_r31_12576 = (MKFont *) gpDebugFont;
        }
        if (IsFlagSet(0x100U) != 0) {
            var_f3_12589 = M2C_FIELD(this->unk4, f32 *, 0x3C);
        } else {
            var_f3_12589 = M2C_FIELD(this->unk4, f32 *, 0x6C);
        }
        temp_r6_12595 = this->unk4;
        temp_f1_12597 = M2C_FIELD(temp_r6_12595, f32 *, 0x38);
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (temp_f1_12597 == 1.0f) {
            temp_f2_12601 = M2C_FIELD(temp_r6_12595, f32 *, 0x3C);
            M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
            if (temp_f2_12601 == 1.0f) {
                MKFont_DrawStringJustified(var_r31_12576, M2C_FIELD(temp_r6_12595, s8 **, 0x68), zero, temp_f1_12597, temp_f2_12601, (FontJustify) M2C_FIELD(temp_r6_12595, s32 *, 0x70), var_f3_12589, arg0->unk40, -1, *((Matrix *) arg0));
            }
        }
    }
}
#endif

#if 0 // DRAFT: identifier 'MKWidgetString::MessageHandler(unsigned int, unsigned int)'
void MKWidgetString::MessageHandler(unsigned int arg0, unsigned int arg1) {
    MKWidget *temp_r3_12668;

    switch (arg0) {
    case 0x2:
        MKWidget_SendMessage((MKWidget *) this, 0x17U, (u32) M2C_FIELD(this->unk4, s8 **, 0));
    default:
block_10:
        MKWidget::MessageHandler(arg0, arg1);
        return;
    case 0x17:
        M2C_FIELD(this->unk4, u32 *, 0x68) = arg1;
        goto block_10;
    case 0x18:
        *arg1 = (u32) M2C_FIELD(this->unk4, u32 *, 0x68);
        goto block_10;
    case 0x42:
        this->unk28 = (MKFont *) arg1;
        goto block_10;
    case 0x44:
        M2C_FIELD(this->unk4, u32 *, 0x70) = arg1;
        goto block_10;
    case 0x43:
        M2C_FIELD(this->unk4, f32 *, 0x6C) = M2C_BITWISE(f32, *arg1);
        goto block_10;
    case 0x20:
    case 0x21:
    case 0x26:
    case 0x29:
    case 0x2A:
    case 0x2B:
    case 0x2E:
    case 0x2F:
    case 0x30:
    case 0x31:
    case 0x33:
    case 0x34:
    case 0x35:
    case 0x36:
    case 0x37:
    case 0x38:
        temp_r3_12668 = this->unk18;
        if (temp_r3_12668 != NULL) {
            MKWidget_SendMessage(temp_r3_12668, arg0, arg1);
            return;
        }
        goto block_10;
    }
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
MKWidgetString::MKWidgetString(MKWidgetDescriptor *arg0) {
    this->unk28 = NULL;
    if ((u8) this->unk8 == 0) {
        M2C_FIELD(this->unk4, s32 *, 0x68) = 0;
        M2C_FIELD(this->unk4, s32 *, 0x70) = 0;
        M2C_FIELD(this->unk4, f32 *, 0x6C) = 20.0f;
        MKWidget_EnableFlag((MKWidget *) this, 0x200U);
        MKWidget_DisableFlag((MKWidget *) this, 4U);
    }
    return this;
}
#endif

void MKWidgetWindowTitleBar::BuildAggregateMetaData() {

}

void MKWidgetWindowTitleBar::BuildMetaData(int arg0) {

}

#if 0 // DRAFT: illegal implicit conversion from 'double *' to
MKWidget *MKWidgetWindowTitleBar::TestPoint(MKVector3 *arg0) {
    f64 sp20;
    f64 sp18;
    f64 sp10;
    f64 sp8;
    MKWidget *temp_r3_12760;
    MKWidget *temp_r3_12774;
    MKWidget *var_r31_12749;
    f64 temp_f1_12751;
    f64 temp_f1_12765;

    var_r31_12749 = MKWidget::TestPoint(arg0);
    if (var_r31_12749 != NULL) {
        temp_f1_12751 = M2C_FIELD(arg0, f64 *, 0);
        sp18 = temp_f1_12751;
        sp20 = M2C_FIELD(arg0, f64 *, 8);
        temp_r3_12760 = this->unk38.GetWidgetUnderPoint(&sp18, temp_f1_12751);
        if (temp_r3_12760 != NULL) {
            var_r31_12749 = temp_r3_12760;
        }
        temp_f1_12765 = M2C_FIELD(arg0, f64 *, 0);
        sp8 = temp_f1_12765;
        sp10 = M2C_FIELD(arg0, f64 *, 8);
        temp_r3_12774 = this->unk64.GetWidgetUnderPoint(&sp8, temp_f1_12765);
        if (temp_r3_12774 != NULL) {
            var_r31_12749 = temp_r3_12774;
        }
    }
    return var_r31_12749;
}
#endif

#if 0 // DRAFT: undefined identifier 'zero'
void MKWidgetWindowTitleBar::Render(MKWidgetRenderContext *arg0) {
    s32 var_r5_12818;
    MKWidget::Render(arg0);
    MKMaterial_SetMaterial(pWidgetBlank);
    if (IsFlagSet(0x40000U) == 0) {
        MKPrimitive(4, 0);
        MKSetBaseColorV(arg0->unk40);
        MKSetMatrix(*((Matrix *) arg0));
        var_r5_12818 = 6;
        if (IsFlagSet(8U) != 0) {
            var_r5_12818 = 0xA;
        }
        WidgetDrawBox(zero, *(MKVector3 *) (this->unk4 + 0x38), var_r5_12818);
        MKEndPrimitive();
    }
    M2C_STRUCT_COPY((s32) &arg_sp5C + 4, (s32) (arg0 - 4) + 4, 0x50);
    this->unk38.Draw(&arg_sp60, &arg_sp5C + 0x50);
    M2C_STRUCT_COPY((s32) &arg_spC + 4, (s32) (arg0 - 4) + 4, 0x50);
    this->unk64.Draw(&arg_sp10, &arg_spC + 0x50);
}
#endif

#if 0 // DRAFT: identifier 'MKWidgetWindowTitleBar::MessageHandler(unsigned int, unsigned
u32 MKWidgetWindowTitleBar::MessageHandler(unsigned int arg0, unsigned int arg1) {
    MKVector3 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 temp_f2_12948;
    f32 temp_f3_12920;

    if ((s32) arg0 != 0x30) {
        if ((s32) arg0 < 0x30) {
            switch ((s32) arg0) {                   /* switch 1; irregular */
            case 5:                                 /* switch 1 */
                temp_f3_12920 = M2C_FIELD(arg1, f32 *, 4);
                sp40 = 0.0f;
                sp38 = (M2C_FIELD(arg1, f32 *, 0) - 6.0f) - temp_f3_12920;
                sp3C = temp_f3_12920 - 4.0f;
                sp80 = (f64) sp40;
                sp78 = (f64) sp38;
                MKWidget_Resize(&this->unk38, *((MKVector3 *) &sp78));
                sp2C = 2.0f;
                sp30 = 0.0f;
                sp28 = (M2C_FIELD(arg1, f32 *, 0) - M2C_FIELD(arg1, f32 *, 4)) - 2.0f;
                sp70 = (f64) sp30;
                sp68 = (f64) sp28;
                MKWidget_Move(&this->unk64, *((MKVector3 *) &sp68));
                temp_f2_12948 = M2C_FIELD(arg1, f32 *, 4);
                sp18 = temp_f2_12948;
                sp20 = 0.0f;
                sp1C = temp_f2_12948 - 4.0f;
                sp60 = (f64) sp20;
                sp58 = (f64) sp18;
                MKWidget_Resize(&this->unk64, *((MKVector3 *) &sp58));
                goto block_34;
            case 20:                                /* switch 1 */
                MKWidget_SendMessage(&this->unk38, 0x17U, arg1);
                goto block_34;
            case 46:                                /* switch 1 */
                if ((u8) this->unkEC != 0) {
                    MKWidget_GetLocalMousePos((MKWidget *) this, &sp98);
                    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                    sp48 = sp8;
                    sp10 = sp98.unk8 - this->unk28.unk8;
                    sp88 = sp8;
                    sp50 = (f64) sp10;
                    sp90 = (f64) sp10;
                    MKWidget_SendMessage(this->unk18, 9U, (u32) &sp98);
                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                    sp98.unk8 += (f32) sp90;
                    MKWidget_SendMessage(this->unk18, 4U, (u32) &sp98);
                }
                goto block_34;
            }
        } else {
            switch ((s32) arg0) {                   /* switch 2; irregular */
            case 0x47:                              /* switch 2 */
                MKWidget_Show(&this->unk64, IsFlagSet(0x100000U) != 0);
                MKWidget_Show(&this->unk38, IsFlagSet(0x02000000U) != 0);
                goto block_34;
            case 0x39:                              /* switch 2 */
                if ((M2C_BITWISE(u32, M2C_FIELD(arg1, f32 *, 0)) == &this->unk64) && (M2C_BITWISE(u16, M2C_FIELD(arg1, f32 *, 4)) == 6)) {
                    MKWidget_SendMessage(this->unk18, 0x6AU, 0U);
                }
                return 0U;
            default:                                /* switch 2 */
                if (arg1 & 1) {
                    MKWidget_ReleaseMouseFocus();
                    this->unkEC = 0;
                }
                goto block_34;
            }
        }
    } else {
        if (arg1 & 1) {
            MKWidget_GetLocalMousePos((MKWidget *) this, &this->unk28);
            MKWidget_SetMouseFocus((MKWidget *) this);
            this->unkEC = 1;
        }
block_34:
        return MKWidget::MessageHandler(arg0, arg1);
    }
    /* bug: did not emit code for node #23; contents below: */
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
MKWidgetWindowTitleBar::MKWidgetWindowTitleBar(MKWidgetDescriptor *arg0) {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;

    this->unk38.unk18 = (MKWidget *) this;
    this->unk64.unk18 = (MKWidget *) this;
    this->unkEC = 0;
    if ((u8) this->unk8 == 0) {
        MKWidget_EnableFlag((MKWidget *) this, 0x03100000U);
        MKWidget_DisableFlag((MKWidget *) this, 4U);
        sp8 = 2.0f;
        spC = 2.0f;
        sp10 = 0.0f;
        sp18 = (f64) sp8;
        sp20 = (f64) sp10;
        MKWidget_Move(&this->unk38, *((MKVector3 *) &sp18));
        MKWidget_SendMessage(&this->unk38, 0x44U, 4U);
        MKWidget_EnableFlag(&this->unk38, 0x100U);
        MKWidget_SendMessage(&this->unk64, 0x17U, (u32) "");
    }
    return this;
}
#endif

void MKWidgetWindow::BuildAggregateMetaData() {

}

void MKWidgetWindow::BuildMetaData(int arg0) {

}

#if 0 // DRAFT: illegal implicit conversion from 'double *' to
MKWidget *MKWidgetWindow::TestPoint(MKVector3 *arg0) {
    f64 sp10;
    f64 sp8;
    MKWidget *temp_r3_13174;
    MKWidget *var_r31_13167;
    f64 temp_f1_13163;

    temp_f1_13163 = M2C_FIELD(arg0, f64 *, 0);
    var_r31_13167 = MKWidget::TestPoint(arg0);
    sp8 = temp_f1_13163;
    sp10 = M2C_FIELD(arg0, f64 *, 8);
    temp_r3_13174 = this->unk40.GetWidgetUnderPoint(&sp8, temp_f1_13163);
    if (temp_r3_13174 != NULL) {
        var_r31_13167 = temp_r3_13174;
    }
    return var_r31_13167;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void MKWidgetWindow::Render(MKWidgetRenderContext *arg0) {
    s8 **temp_r3_13207;
    if (IsFlagSet(0x20000U) != 0) {
        temp_r3_13207 = this->unk4;
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        arg_sp40 = arg_sp20;
        arg_sp28 = arg0->unk18 * (-M2C_FIELD(temp_r3_13207, f32 *, 0x80) * M2C_FIELD(temp_r3_13207, f32 *, 0x1C));
        arg_sp48 = (f64) arg_sp28;
        arg0->Translate((Matrix *) arg0, *((MKVector3 *) &arg_sp40));
    }
    MKWidgetFrame::Render(arg0);
    if (IsFlagSet(0x20000U) != 0) {
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
        arg_sp30 = arg_sp10;
        arg_sp18 = arg0->unk18 * M2C_FIELD(this->unk4, f32 *, 0x80);
        arg_sp38 = (f64) arg_sp18;
        arg0->Translate((Matrix *) arg0, *((MKVector3 *) &arg_sp30));
    }
    if (IsFlagSet(0x20000U) != 0) {
        M2C_STRUCT_COPY((s32) &arg_sp6C + 4, (s32) (arg0 - 4) + 4, 0x50);
        this->unk40.Draw(&arg_sp70, &arg_sp6C + 0x50);
    }
    MKWidget_GetClientVolume((MKWidget *) this, (MKWidgetBoundingVolume *) &arg_sp50);
    if (IsFlagSet(0x80000U) == 0) {
        MKMaterial_SetMaterial(pWidgetBlank);
        MKPrimitive(4, 0);
        MKSetBaseColorV(arg0->unk40);
        MKSetMatrix(*((Matrix *) arg0));
        WidgetDrawBox(zero, *((MKVector3 *) &arg_sp60), M2C_FIELD(this->unk4, s32 *, 0x84));
        MKEndPrimitive();
    }
}
#endif

#if 0 // DRAFT: identifier 'MKWidgetWindow::MessageHandler(unsigned int, unsigned int)'
u32 MKWidgetWindow::MessageHandler(unsigned int arg0, unsigned int arg1) {
    MKVector3 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;                                       /* compiler-managed */
    f32 spBC;
    f32 spB8;                                       /* compiler-managed */
    f32 spB0;
    M2C_UNK spA8;
    f64 sp98;
    MKVector3 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp10;
    MKWidgetWindow *var_r3_0;
    f32 temp_f1_13621;
    f32 temp_f1_13624;
    f32 temp_f1_13940;
    f32 temp_f1_13943;
    f32 temp_f2_13623;
    f32 temp_f2_13942;
    f32 temp_f3_13559;
    f32 temp_f3_13622;
    f32 temp_f3_13941;
    f32 temp_f4_13658;
    f32 temp_f4_13974;
    f32 temp_f5_13682;
    f32 temp_f5_13997;
    f32 var_f1_13899;
    f32 var_f3_13580;
    f32 var_f3_13651;
    f32 var_f3_13922;
    f32 var_f3_13967;
    f32 var_f4_13675;
    f32 var_f4_13990;
    s32 temp_r0_13717;
    s32 temp_r0_13762;
    s32 temp_r0_13770;
    s32 temp_r0_13786;
    s32 temp_r0_13825;
    s32 temp_r0_13841;
    s32 var_r0_13981;
    s32 var_r28_13947;
    s8 **temp_r3_13566;
    s8 **temp_r3_13585;
    s8 **temp_r3_13619;
    s8 **temp_r3_13680;
    s8 **temp_r3_13907;
    s8 **temp_r3_13927;
    s8 **temp_r3_13938;
    s8 **temp_r3_13995;
    s8 **temp_r5_13529;
    u32 temp_r0_13338;
    u32 temp_r28_13351;

    var_r3_0 = this;
    switch (arg0) {                                 /* switch 1 */
    case 0x22:                                      /* switch 1 */
loop_4:
        temp_r0_13338 = var_r3_0->unk20;
        if (temp_r0_13338 != 0) {
            var_r3_0 = (MKWidgetWindow *) temp_r0_13338;
            goto loop_4;
        }
        M2C_FIELD(arg1, MKWidgetWindow **, 0) = var_r3_0;
        return 0U;
    case 0x1B:                                      /* switch 1 */
    case 0x1D:                                      /* switch 1 */
    case 0x1E:                                      /* switch 1 */
        temp_r28_13351 = var_r3_0->MKWidgetFrame::MessageHandler(arg0, arg1);
        MKWidget_SendMessage((MKWidget *) var_r3_0, 0x47U, 0U);
        return temp_r28_13351;
    case 0x6B:                                      /* switch 1 */
        M2C_FIELD(var_r3_0->unk4, f32 *, 0x80) = M2C_BITWISE(f32, M2C_FIELD(arg1, MKWidgetWindow **, 0));
        M2C_FIELD(var_r3_0->__vptr, M2C_UNK (**)(M2C_UNK, s8 **), 0xC)(5, var_r3_0->unk4 + 0x38);
        return 0U;
    case 0x6C:                                      /* switch 1 */
        M2C_FIELD(var_r3_0->unk4, u32 *, 0x84) = arg1;
        return 0U;
    case 0x12:                                      /* switch 1 */
        if (var_r3_0->IsFlagSet(0x20000U) != 0) {
            var_r3_0->MKWidgetFrame::MessageHandler(arg0, arg1);
            M2C_FIELD(arg1, f32 *, 4) = (f32) (M2C_FIELD(arg1, f32 *, 4) + M2C_FIELD(var_r3_0->unk4, f32 *, 0x80));
            M2C_FIELD(arg1, f32 *, 0x14) = (f32) (M2C_FIELD(arg1, f32 *, 0x14) - M2C_FIELD(var_r3_0->unk4, f32 *, 0x80));
        }
        return 0U;
    case 0x47:                                      /* switch 1 */
        M2C_FIELD(var_r3_0->__vptr, M2C_UNK (**)(M2C_UNK, s8 **), 0xC)(5, var_r3_0->unk4 + 0x38);
        MKWidget_Show(&var_r3_0->unk40, var_r3_0->IsFlagSet(0x20000U) != 0);
        if (var_r3_0->IsFlagSet(0x100000U) != 0) {
            MKWidget_EnableFlag(&var_r3_0->unk40, 0x100000U);
        } else {
            MKWidget_DisableFlag(&var_r3_0->unk40, 0x100000U);
        }
        if (var_r3_0->IsFlagSet(0x200000U) != 0) {
            MKWidget_EnableFlag(&var_r3_0->unk40, 0x200000U);
        } else {
            MKWidget_DisableFlag(&var_r3_0->unk40, 0x200000U);
        }
        if (var_r3_0->IsFlagSet(0x400000U) != 0) {
            MKWidget_EnableFlag(&var_r3_0->unk40, 0x400000U);
        } else {
            MKWidget_DisableFlag(&var_r3_0->unk40, 0x400000U);
        }
        if (var_r3_0->IsFlagSet(0x40000U) != 0) {
            MKWidget_EnableFlag(&var_r3_0->unk40, 0x40000U);
        } else {
            MKWidget_DisableFlag(&var_r3_0->unk40, 0x40000U);
        }
        if (var_r3_0->IsFlagSet(0x01000000U) != 0) {
            MKWidget_EnableFlag(&var_r3_0->unk40, 0x01000000U);
        } else {
            MKWidget_DisableFlag(&var_r3_0->unk40, 0x01000000U);
        }
        if (var_r3_0->IsFlagSet(0x02000000U) != 0) {
            MKWidget_EnableFlag(&var_r3_0->unk40, 0x02000000U);
        } else {
            MKWidget_DisableFlag(&var_r3_0->unk40, 0x02000000U);
        }
        MKWidget_SendMessage(&var_r3_0->unk40, 0x47U, 0U);
    default:                                        /* switch 1 */
block_158:
        return var_r3_0->MKWidgetFrame::MessageHandler(arg0, arg1);
    case 0x5:                                       /* switch 1 */
        if (M2C_BITWISE(f32, M2C_FIELD(arg1, MKWidgetWindow **, 0)) < 100.0f) {
            M2C_FIELD(arg1, MKWidgetWindow **, 0) = 100.0f;
        }
        if (M2C_FIELD(arg1, f32 *, 4) < 75.0f) {
            M2C_FIELD(arg1, f32 *, 4) = 75.0f;
        }
        sp40 = 0.0f;
        sp38 = 0.0f;
        sp3C = -M2C_FIELD(var_r3_0->unk4, f32 *, 0x80);
        sp80 = (f64) sp40;
        sp78 = (f64) sp38;
        MKWidget_Move(&var_r3_0->unk40, *((MKVector3 *) &sp78));
        temp_r5_13529 = var_r3_0->unk4;
        sp30 = 0.0f;
        sp2C = M2C_FIELD(temp_r5_13529, f32 *, 0x80);
        sp28 = -((2.0f * M2C_FIELD(temp_r5_13529, f32 *, 0x70)) - M2C_BITWISE(f32, M2C_FIELD(arg1, MKWidgetWindow **, 0)));
        sp70 = (f64) sp30;
        sp68 = (f64) sp28;
        MKWidget_Resize(&var_r3_0->unk40, *((MKVector3 *) &sp68));
        goto block_158;
    case 0x2F:                                      /* switch 1 */
        if (arg1 == 0) {
            gWidgetCursor = 0;
        }
        goto block_158;
    case 0x30:                                      /* switch 1 */
        MKWidget_GetLocalMousePos((MKWidget *) var_r3_0, &var_r3_0->unk140);
        if ((s32) var_r3_0->unk150 == 0) {
            temp_f3_13559 = var_r3_0->unk140.unk0;
            if (!(temp_f3_13559 < 0.0f) && !(var_r3_0->unk140.unk4 < 0.0f) && (temp_r3_13566 = var_r3_0->unk4, M2C_ERROR(/* unknown instruction: cror eq, gt, eq */), ((temp_f3_13559 == -((2.0f * M2C_FIELD(temp_r3_13566, f32 *, 0x70)) - M2C_FIELD(temp_r3_13566, f32 *, 0x38))) == 0))) {
                if (var_r3_0->IsFlagSet(0x20000U) != 0) {
                    var_f3_13580 = M2C_FIELD(var_r3_0->unk4, f32 *, 0x80);
                } else {
                    var_f3_13580 = 0.0f;
                }
                temp_r3_13585 = var_r3_0->unk4;
                M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
                if (var_r3_0->unk140.unk4 == -((2.0f * M2C_FIELD(temp_r3_13585, f32 *, 0x70)) - (M2C_FIELD(temp_r3_13585, f32 *, 0x3C) - var_f3_13580))) {
                    goto block_46;
                }
            } else {
block_46:
                switch ((s32) arg1) {               /* switch 2; irregular */
                case 3:                             /* switch 2 */
                    break;
                case 1:                             /* switch 2 */
                    var_r3_0->unk150 = 1;
                    break;
                case 2:                             /* switch 2 */
                    var_r3_0->unk150 = 2;
                    break;
                case 4:                             /* switch 2 */
                    var_r3_0->unk150 = 3;
                    break;
                }
                temp_r3_13619 = var_r3_0->unk4;
                temp_f1_13621 = M2C_FIELD(temp_r3_13619, f32 *, 0x70);
                temp_f3_13622 = var_r3_0->unk140.unk0;
                temp_f2_13623 = -temp_f1_13621;
                temp_f1_13624 = 3.0f * temp_f1_13621;
                if (temp_f3_13622 < (temp_f2_13623 + temp_f1_13624)) {
                    var_r3_0->unk154 = 0;
                } else {
                    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
                    if (temp_f3_13622 == ((temp_f2_13623 + M2C_FIELD(temp_r3_13619, f32 *, 0x38)) - temp_f1_13624)) {
                        var_r3_0->unk154 = 2;
                    } else {
                        var_r3_0->unk154 = 1;
                    }
                }
                if (var_r3_0->IsFlagSet(0x20000U) != 0) {
                    var_f3_13651 = M2C_FIELD(var_r3_0->unk4, f32 *, 0x80);
                } else {
                    var_f3_13651 = 0.0f;
                }
                temp_f4_13658 = M2C_FIELD(var_r3_0->unk4, f32 *, 0x70);
                if (var_r3_0->unk140.unk4 < ((3.0f * temp_f4_13658) + (-temp_f4_13658 - var_f3_13651))) {
                    var_r3_0->unk158 = 0;
                } else {
                    if (var_r3_0->IsFlagSet(0x20000U) != 0) {
                        var_f4_13675 = M2C_FIELD(var_r3_0->unk4, f32 *, 0x80);
                    } else {
                        var_f4_13675 = 0.0f;
                    }
                    temp_r3_13680 = var_r3_0->unk4;
                    temp_f5_13682 = M2C_FIELD(temp_r3_13680, f32 *, 0x70);
                    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
                    if (var_r3_0->unk140.unk4 == -((3.0f * temp_f5_13682) - (M2C_FIELD(temp_r3_13680, f32 *, 0x3C) + (-temp_f5_13682 - var_f4_13675)))) {
                        var_r3_0->unk158 = 2;
                    } else {
                        var_r3_0->unk158 = 1;
                    }
                }
                MKWidget_SetMouseFocus((MKWidget *) var_r3_0);
            }
        }
        goto block_158;
    case 0x2E:                                      /* switch 1 */
        if ((s32) var_r3_0->unk150 != 0) {
            MKWidget_GetLocalMousePos((MKWidget *) var_r3_0, &spD8);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $r29, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            temp_r0_13717 = var_r3_0->unk150;
            sp58 = sp18;
            sp20 = spD8.unk8 - var_r3_0->unk140.unk8;
            spC8 = sp18;
            sp60 = (f64) sp20;
            spD0 = (f64) sp20;
            if (((temp_r0_13717 == 1) || (temp_r0_13717 == 2)) && (((s32) var_r3_0->unk154 == 0) || ((s32) var_r3_0->unk158 == 0))) {
                MKWidget_SendMessage((MKWidget *) var_r3_0, 9U, (u32) &spD8);
                if ((s32) var_r3_0->unk154 == 0) {
                    spD8 = M2C_BITWISE(f32, spD8) + (f32) spC8;
                }
                if ((s32) var_r3_0->unk158 == 0) {
                    spD8.unk4 += unkspCC;
                }
                MKWidget_SendMessage((MKWidget *) var_r3_0, 4U, (u32) &spD8);
            }
            temp_r0_13762 = var_r3_0->unk150;
            if (temp_r0_13762 == 1) {
                MKWidget_SendMessage((MKWidget *) var_r3_0, 0xAU, (u32) &spB8);
                temp_r0_13770 = var_r3_0->unk154;
                if (temp_r0_13770 == 0) {
                    spB8 -= (f32) spC8;
                } else if (temp_r0_13770 == 2) {
                    spB8 += (f32) spC8;
                }
                temp_r0_13786 = var_r3_0->unk158;
                if (temp_r0_13786 == 0) {
                    spBC -= unkspCC;
                } else if (temp_r0_13786 == 2) {
                    spBC += unkspCC;
                }
                MKWidget_SendMessage((MKWidget *) var_r3_0, 5U, (u32) &spB8);
                MKWidget_GetLocalMousePos((MKWidget *) var_r3_0, &var_r3_0->unk140);
            } else if (temp_r0_13762 == 2) {
                MKWidget_SendMessage((MKWidget *) var_r3_0, 0xAU, (u32) &sp98);
                MKWidget_SendMessage((MKWidget *) var_r3_0, 0xBU, (u32) &spA8);
                spB8 = sp98;
                spC0 = spA0;
                temp_r0_13825 = var_r3_0->unk154;
                if (temp_r0_13825 == 0) {
                    spB8 = (f32) spB8 - (f32) spC8;
                } else if (temp_r0_13825 == 2) {
                    spB8 += (f32) spC8;
                }
                temp_r0_13841 = var_r3_0->unk158;
                if (temp_r0_13841 == 0) {
                    spBC -= unkspCC;
                } else if (temp_r0_13841 == 2) {
                    spBC += unkspCC;
                }
                M2C_ERROR(/* unknown instruction: ps_div $f0, $f1, $f0 */);
                spB8 = sp8;
                sp48 = sp8;
                sp10 = (f32) spC0 / (f32) spA0;
                spC0 = (f64) sp10;
                sp50 = (f64) sp10;
                spC0 = 1.0f;
                M2C_ERROR(/* unknown instruction: ps_mul $f0, $f1, $f0 */);
                spB0 *= 1.0f;
                MKWidget_SendMessage((MKWidget *) var_r3_0, 6U, (u32) &spB8);
            }
        } else {
            MKWidget_GetLocalMousePos((MKWidget *) var_r3_0, &sp88);
            if (!(M2C_BITWISE(f32, sp88) < 0.0f)) {
                if (var_r3_0->IsFlagSet(0x20000U) != 0) {
                    var_f1_13899 = -M2C_FIELD(var_r3_0->unk4, f32 *, 0x80);
                } else {
                    var_f1_13899 = 0.0f;
                }
                if (!(sp88.unk4 < var_f1_13899) && (temp_r3_13907 = var_r3_0->unk4, M2C_ERROR(/* unknown instruction: cror eq, gt, eq */), ((M2C_BITWISE(f32, sp88) == -((2.0f * M2C_FIELD(temp_r3_13907, f32 *, 0x70)) - M2C_FIELD(temp_r3_13907, f32 *, 0x38))) == 0))) {
                    if (var_r3_0->IsFlagSet(0x20000U) != 0) {
                        var_f3_13922 = M2C_FIELD(var_r3_0->unk4, f32 *, 0x80);
                    } else {
                        var_f3_13922 = 0.0f;
                    }
                    temp_r3_13927 = var_r3_0->unk4;
                    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
                    if (sp88.unk4 == -((2.0f * M2C_FIELD(temp_r3_13927, f32 *, 0x70)) - (M2C_FIELD(temp_r3_13927, f32 *, 0x3C) - var_f3_13922))) {
                        goto block_113;
                    }
                    gWidgetCursor = 0;
                } else {
                    goto block_113;
                }
            } else {
block_113:
                temp_r3_13938 = var_r3_0->unk4;
                temp_f1_13940 = M2C_FIELD(temp_r3_13938, f32 *, 0x70);
                temp_f3_13941 = M2C_BITWISE(f32, sp88);
                temp_f2_13942 = -temp_f1_13940;
                temp_f1_13943 = 3.0f * temp_f1_13940;
                if (temp_f3_13941 < (temp_f2_13942 + temp_f1_13943)) {
                    var_r28_13947 = 0;
                } else {
                    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
                    if (temp_f3_13941 == ((temp_f2_13942 + M2C_FIELD(temp_r3_13938, f32 *, 0x38)) - temp_f1_13943)) {
                        var_r28_13947 = 2;
                    } else {
                        var_r28_13947 = 1;
                    }
                }
                if (var_r3_0->IsFlagSet(0x20000U) != 0) {
                    var_f3_13967 = M2C_FIELD(var_r3_0->unk4, f32 *, 0x80);
                } else {
                    var_f3_13967 = 0.0f;
                }
                temp_f4_13974 = M2C_FIELD(var_r3_0->unk4, f32 *, 0x70);
                if (sp88.unk4 < ((3.0f * temp_f4_13974) + (-temp_f4_13974 - var_f3_13967))) {
                    var_r0_13981 = 0;
                } else {
                    if (var_r3_0->IsFlagSet(0x20000U) != 0) {
                        var_f4_13990 = M2C_FIELD(var_r3_0->unk4, f32 *, 0x80);
                    } else {
                        var_f4_13990 = 0.0f;
                    }
                    temp_r3_13995 = var_r3_0->unk4;
                    temp_f5_13997 = M2C_FIELD(temp_r3_13995, f32 *, 0x70);
                    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
                    if (sp88.unk4 == -((3.0f * temp_f5_13997) - (M2C_FIELD(temp_r3_13995, f32 *, 0x3C) + (-temp_f5_13997 - var_f4_13990)))) {
                        var_r0_13981 = 2;
                    } else {
                        var_r0_13981 = 1;
                    }
                }
                if (((var_r28_13947 == 0) && (var_r0_13981 == 0)) || ((var_r28_13947 == 2) && (var_r0_13981 == 2))) {
                    gWidgetCursor = 4;
                } else if (((var_r28_13947 == 1) && (var_r0_13981 == 0)) || ((var_r28_13947 == 1) && (var_r0_13981 == 2))) {
                    gWidgetCursor = 2;
                } else if (((var_r28_13947 == 0) && (var_r0_13981 == 1)) || ((var_r28_13947 == 2) && (var_r0_13981 == 1))) {
                    gWidgetCursor = 3;
                } else if (((var_r28_13947 == 0) && (var_r0_13981 == 2)) || ((var_r28_13947 == 2) && (var_r0_13981 == 0))) {
                    gWidgetCursor = 5;
                }
            }
        }
        goto block_158;
    case 0x31:                                      /* switch 1 */
        if ((s32) var_r3_0->unk150 != 0) {
            MKWidget_ReleaseMouseFocus();
            var_r3_0->unk150 = 0;
        }
        goto block_158;
    case 0x14:                                      /* switch 1 */
        MKWidget_SendMessage(&var_r3_0->unk40, 0x14U, arg1);
        goto block_158;
    case 0x17:                                      /* switch 1 */
    case 0x18:                                      /* switch 1 */
    case 0x42:                                      /* switch 1 */
    case 0x43:                                      /* switch 1 */
    case 0x44:                                      /* switch 1 */
        return MKWidget_SendMessage(&var_r3_0->unk40, arg0, arg1);
    case 0x1F:                                      /* switch 1 */
        if (arg1 != 0) {
            MKWidget_BringToFront((MKWidget *) var_r3_0);
            MKWidget_EnableFlag(&var_r3_0->unk40, 8U);
        } else {
            MKWidget_DisableFlag(&var_r3_0->unk40, 8U);
        }
        goto block_158;
    case 0x6A:                                      /* switch 1 */
        MKWidget_Show((MKWidget *) var_r3_0, 0);
        return 0U;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'zero'
MKWidgetWindow::MKWidgetWindow(MKWidgetDescriptor *arg0) {
    s8 **temp_r31_14155;
    s8 **temp_r31_14160;
    s8 **temp_r31_14164;

    this->unk150 = 0;
    this->unk130 = M2C_FIELD(&zero, f64 *, 0);
    this->unk138 = M2C_FIELD(&zero, f64 *, 8);
    this->unk40.unk18 = (MKWidget *) this;
    if ((u8) this->unk8 == 0) {
        MKWidget_EnableFlag((MKWidget *) this, 0x0313C000U);
        MKWidget_DisableFlag((MKWidget *) this, 0x102U);
        temp_r31_14155 = this->unk4;
        M2C_FIELD(temp_r31_14155, f32 *, 0x68) = MKWidget_GetMetricF(0x12);
        temp_r31_14160 = this->unk4;
        M2C_FIELD(temp_r31_14160, f32 *, 0x70) = MKWidget_GetMetricF(0x12);
        temp_r31_14164 = this->unk4;
        M2C_FIELD(temp_r31_14164, f32 *, 0x80) = MKWidget_GetMetricF(0x14);
        M2C_FIELD(this->unk4, s32 *, 0x84) = 6;
    }
    return this;
}
#endif

void MKWidgetFrame::BuildAggregateMetaData() {

}

void MKWidgetFrame::BuildMetaData(int arg0) {

}

void MKWidgetFrame::ArrangeChildren() {
    MKWidget *var_r31_14266;
    f32 var_f30_14265;
    s8 **temp_r3_14275;

    var_f30_14265 = 0.0f;
    var_r31_14266 = this->unk28;
loop_4:
    if (var_r31_14266 != NULL) {
        if (var_r31_14266->IsFlagSet(2U) != 0) {
            temp_r3_14275 = var_r31_14266->unk4;
            M2C_FIELD(temp_r3_14275, f32 *, 8) = 0.0f;
            M2C_FIELD(temp_r3_14275, f32 *, 0xC) = var_f30_14265;
            M2C_FIELD(temp_r3_14275, f32 *, 0x10) = 0.0f;
            var_f30_14265 += M2C_FIELD(var_r31_14266->unk4, f32 *, 0x3C);
        }
        var_r31_14266 = var_r31_14266->unk1C;
        goto loop_4;
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void MKWidgetFrame::Render(MKWidgetRenderContext *arg0) {
    f64 sp190;
    f64 sp188;
    f64 sp180;                                      /* compiler-managed */
    f64 sp178;                                      /* compiler-managed */
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f32 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA0;
    f32 sp90;
    f32 sp80;
    f32 sp70;
    f32 sp60;
    f32 sp50;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp20;
    f32 sp10;
    MKVector4 *temp_r30_14463;
    f32 temp_f1_14369;
    f32 temp_f3_14334;
    f32 temp_f3_14350;
    f32 var_f2_14360;
    f32 var_f31_14379;
    s32 temp_r27_14342;
    s32 temp_r5_14337;
    s8 **temp_r28_14427;
    s8 **temp_r29_14377;
    s8 **temp_r4_14331;
    s8 **temp_r5_14481;
    u32 temp_r29_14351;

    if (IsFlagSet(0x2000U) != 0) {
        ArrangeChildren();
    }
    MKWidget::Render(arg0);
    MKMaterial_SetMaterial(pWidgetBlank);
    MKPrimitive(0xC, 0);
    MKSetBaseColorV(arg0->unk40);
    MKSetMatrix(*((Matrix *) arg0));
    temp_r4_14331 = this->unk4;
    temp_f3_14334 = M2C_FIELD(temp_r4_14331, f32 *, 0x70);
    spB8 = temp_f3_14334;
    temp_r5_14337 = M2C_FIELD(temp_r4_14331, s32 *, 0x74);
    spC0 = 0.0f;
    spBC = temp_f3_14334;
    temp_r27_14342 = temp_r5_14337 - 1;
    sp190 = (f64) spC0;
    sp188 = (f64) spB8;
    sp178 = M2C_FIELD(&zero, f64 *, 0);
    sp180 = M2C_FIELD(&zero, f64 *, 8);
    if (temp_r5_14337 != 0) {
        temp_f3_14350 = M2C_FIELD(temp_r4_14331, f32 *, 0x6C);
        temp_r29_14351 = temp_r27_14342 & 2;
        spB0 = 0.0f;
        spA8 = temp_f3_14350;
        spAC = temp_f3_14350;
        sp170 = (f64) spB0;
        sp168 = (f64) spA8;
        if (temp_r29_14351 != 0) {
            var_f2_14360 = 2.0f;
        } else {
            var_f2_14360 = 1.0f;
        }
        temp_f1_14369 = (var_f2_14360 * M2C_FIELD(temp_r4_14331, f32 *, 0x68)) + temp_f3_14350;
        sp180 = 0.0f;
        sp178 = temp_f1_14369;
        unksp17C = temp_f1_14369;
        if (IsFlagSet(0x1000U) != 0) {
            temp_r29_14377 = this->unk4;
            if (temp_r29_14351 != 0) {
                var_f31_14379 = 2.0f;
            } else {
                var_f31_14379 = 1.0f;
            }
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f0, $f2 */);
            sp138 = sp88;
            sp90 = M2C_FIELD(temp_r29_14377, f32 *, 0x40) - (f32) sp170;
            sp140 = (f64) sp90;
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f0, $f1 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f2, $f1 */);
            sp148 = sp78;
            sp80 = (f32) sp140 - (f32) sp190;
            sp150 = (f64) sp80;
            spA0 = (f32) sp170 - (f32) sp190;
            sp158 = sp98;
            sp160 = (f64) spA0;
            WidgetDrawSquare(*((MKVector3 *) &sp158), *((MKVector3 *) &sp148), var_f31_14379 * M2C_FIELD(temp_r29_14377, f32 *, 0x68), *(MKWidget_GetMetric(0x16)));
        } else {
            temp_r28_14427 = this->unk4;
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f0, $f2 */);
            sp108 = sp58;
            sp60 = M2C_FIELD(temp_r28_14427, f32 *, 0x40) - (f32) sp170;
            sp110 = (f64) sp60;
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f0, $f1 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f2, $f1 */);
            sp118 = sp48;
            sp50 = (f32) sp110 - (f32) sp190;
            sp120 = (f64) sp50;
            sp70 = (f32) sp170 - (f32) sp190;
            sp128 = sp68;
            sp130 = (f64) sp70;
            temp_r30_14463 = MKWidget_GetMetric(1);
            WidgetDrawBevel(*((MKVector3 *) &sp128), *((MKVector3 *) &sp118), M2C_FIELD(temp_r28_14427, f32 *, 0x68), *(MKWidget_GetMetric(0)), *temp_r30_14463, temp_r27_14342 & 1, temp_r29_14351 != 0);
        }
    }
    if (IsFlagSet(0x100U) != 0) {
        temp_r5_14481 = this->unk4;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        spC8 = sp18;
        sp20 = M2C_FIELD(temp_r5_14481, f32 *, 0x40) - (f32) sp190;
        spD0 = (f64) sp20;
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f0, $f5 */);
        sp40 = -(f32) sp190;
        sp38 = -(f32) sp188;
        sp3C = -unksp18C;
        sp10 = (f32) spD0 - sp180;
        spE8 = (f64) sp38;
        spD8 = sp8;
        spE0 = (f64) sp10;
        spF0 = (f64) sp40;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f0, $f5 */);
        spF8 = sp28;
        sp30 = (f32) spF0 + sp180;
        sp100 = (f64) sp30;
        WidgetDrawBox(*((MKVector3 *) &spF8), *((MKVector3 *) &spD8), M2C_FIELD(temp_r5_14481, s32 *, 0x78));
    }
    MKEndPrimitive();
}
#endif

#if 0 // DRAFT: identifier 'MKWidgetFrame::MessageHandler(unsigned int, unsigned int)'
u32 MKWidgetFrame::MessageHandler(unsigned int arg0, unsigned int arg1) {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f2_14571;
    f32 temp_f3_14585;
    s8 **temp_r4_14581;
    s8 **temp_r4_14603;

    switch ((s32) arg0) {                           /* irregular */
    case 0x12:
        temp_f2_14571 = M2C_FIELD(this->unk4, f32 *, 0x70);
        sp20 = 0.0f;
        sp18 = temp_f2_14571;
        sp1C = temp_f2_14571;
        sp40 = (f64) sp20;
        M2C_FIELD(arg1, f64 *, 0) = (f64) sp18;
        M2C_FIELD(arg1, f64 *, 8) = (f64) sp20;
        temp_r4_14581 = this->unk4;
        sp38 = (f64) sp18;
        temp_f3_14585 = 2.0f * M2C_FIELD(temp_r4_14581, f32 *, 0x70);
        sp10 = M2C_FIELD(temp_r4_14581, f32 *, 0x40);
        sp8 = M2C_FIELD(temp_r4_14581, f32 *, 0x38) - temp_f3_14585;
        spC = M2C_FIELD(temp_r4_14581, f32 *, 0x3C) - temp_f3_14585;
        sp30 = (f64) sp10;
        M2C_FIELD(arg1, f64 *, 0x10) = (f64) sp8;
        sp28 = (f64) sp8;
        M2C_FIELD(arg1, f64 *, 0x18) = (f64) sp10;
        return 0U;
    case 0x64:
        M2C_FIELD(this->unk4, u32 *, 0x74) = arg1;
        temp_r4_14603 = this->unk4;
        if ((M2C_FIELD(temp_r4_14603, u32 *, 0x74) - 1) & 2) {
            M2C_FIELD(temp_r4_14603, f32 *, 0x70) = (f32) (M2C_FIELD(temp_r4_14603, f32 *, 0x70) + M2C_FIELD(temp_r4_14603, f32 *, 0x68));
        }
        return 0U;
    case 0x66:
        M2C_FIELD(this->unk4, f32 *, 0x68) = (f32) M2C_FIELD(arg1, f64 *, 0);
        return 0U;
    case 0x67:
        M2C_FIELD(this->unk4, f32 *, 0x6C) = (f32) M2C_FIELD(arg1, f64 *, 0);
        return 0U;
    case 0x68:
        M2C_FIELD(this->unk4, f32 *, 0x70) = (f32) M2C_FIELD(arg1, f64 *, 0);
        return 0U;
    case 0x69:
        M2C_FIELD(this->unk4, u32 *, 0x78) = arg1;
        return 0U;
    case 0x65:
        return M2C_FIELD(this->unk4, u32 *, 0x74);
    default:
        return MKWidgetContainer::MessageHandler(arg0, arg1);
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
MKWidgetFrame::MKWidgetFrame(MKWidgetDescriptor *arg0) {
    s8 **temp_r31_14671;
    s8 **temp_r31_14678;

    if ((u8) this->unk8 == 0) {
        M2C_FIELD(this->unk4, s32 *, 0x74) = 1;
        temp_r31_14671 = this->unk4;
        M2C_FIELD(temp_r31_14671, f32 *, 0x68) = MKWidget_GetMetricF(0x12);
        M2C_FIELD(this->unk4, f32 *, 0x6C) = 0.0f;
        temp_r31_14678 = this->unk4;
        M2C_FIELD(temp_r31_14678, f32 *, 0x70) = MKWidget_GetMetricF(0x12);
        M2C_FIELD(this->unk4, s32 *, 0x78) = 0x16;
        MKWidget_EnableFlag((MKWidget *) this, 0x100U);
    }
    return this;
}
#endif

#if 0 // DRAFT: function call 'MKInputReceiver_Create(unsigned char (*)(MKInputEvent *,
void MKWidgetSystem::CreateInputReceiver(bool arg0) {
    if (arg0 != 0) {
        this->unk78 = MKInputReceiver_Create((u8 (*)(MKInputEvent *, void *)) SystemReceiverCallback, -1, 4, this);
        return;
    }
    MKInputReceiver_Destroy(this->unk78);
}
#endif

#if 0 // DRAFT: expression syntax error
s32 SystemReceiverCallback(MKInputEvent *arg0, void *arg1) {
    MKWidgetBoundingVolume sp78;
    MKVector3 sp68;
    MKVector3 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    MKWidget *temp_r3_14819;
    MKWidget *temp_r3_14970;
    MKWidget *temp_r3_14980;
    f32 temp_f1_14827;
    f32 temp_f1_14956;
    f32 temp_f2_14942;
    f32 temp_f31_14848;
    f32 temp_f3_14933;
    f32 temp_f5_14931;
    f32 temp_f6_14932;
    s32 temp_r0_14740;
    s32 temp_r29_14862;
    s32 temp_r30_14864;
    u32 temp_r28_14863;
    u32 temp_r29_14865;
    u8 temp_r4_15026;

    if (arg1->AnyVisible() != 0) {
        temp_r0_14740 = arg0->unk0;
        switch (temp_r0_14740) {                    /* irregular */
        case 2:
            if ((u8) arg0->unkC != 0) {
                MKWidget_SendMessage(M2C_FIELD(arg1, MKWidget **, 0x4C), 0x27U, (arg0->unk4 << 0x10) | (s32) M2C_FIELD(arg0, u8 *, 8));
            }
            if ((u8) arg0->unkD != 0) {
                MKWidget_SendMessage(M2C_FIELD(arg1, MKWidget **, 0x4C), 0x28U, (arg0->unk4 << 0x10) | (s32) M2C_FIELD(arg0, u8 *, 8));
            }
            if (((u8) arg0->unkC != 0) || ((u8) arg0->unkD == 0)) {
                MKWidget_SendMessage(M2C_FIELD(arg1, MKWidget **, 0x4C), 0x26U, (arg0->unk4 << 0x10) | (s32) M2C_FIELD(arg0, u8 *, 8));
            }
block_51:
        case 1:
            return 0;
        case 3:
            if ((u8) arg0->unk8 != 0) {
                MKWidget_SendMessage(M2C_FIELD(arg1, MKWidget **, 0x50), 0x30U, 1 << arg0->unk4);
                M2C_FIELD(arg1, s32 *, 0x5C) = (s32) (M2C_FIELD(arg1, s32 *, 0x5C) | (1 << arg0->unk4));
            }
            if ((u8) arg0->unk9 != 0) {
                MKWidget_SendMessage(M2C_FIELD(arg1, MKWidget **, 0x50), 0x31U, 1 << arg0->unk4);
                temp_r3_14819 = M2C_FIELD(arg1, MKWidget **, 0x50);
                if (temp_r3_14819 != NULL) {
                    MKWidget_GetLocalMousePos(temp_r3_14819, &sp68);
                    MKWidget_GetBoundingVolume(M2C_FIELD(arg1, MKWidget **, 0x50), &sp78);
                    temp_f1_14827 = M2C_BITWISE(f32, sp68);
                    if ((temp_f1_14827 < 0.0f) || (sp68.unk4 < 0.0f) || (M2C_ERROR(/* unknown instruction: cror eq, gt, eq */), ((temp_f1_14827 == sp78.unk10) != 0)) || (M2C_ERROR(/* unknown instruction: cror eq, gt, eq */), ((sp68.unk4 == sp78.unk14) != 0))) {
                        M2C_FIELD(arg1, s32 *, 0x60) = 0;
                        M2C_FIELD(arg1, s32 *, 0x5C) = 0;
                    } else {
                        temp_f31_14848 = gApplicationTime;
                        if ((temp_f31_14848 - timestamp) > 0.4f) {
                            M2C_FIELD(arg1, s32 *, 0x60) = 0;
                        }
                        temp_r29_14862 = M2C_FIELD(arg1, s32 *, 0x5C) & (1 << arg0->unk4);
                        temp_r28_14863 = M2C_FIELD(arg1, s32 *, 0x60) & temp_r29_14862;
                        temp_r30_14864 = ~(temp_r28_14863 | temp_r28_14863);
                        temp_r29_14865 = temp_r29_14862 & temp_r30_14864;
                        if (temp_r29_14865 != 0) {
                            MKWidget_SendMessage(M2C_FIELD(arg1, MKWidget **, 0x50), 0x33U, temp_r29_14865);
                            M2C_FIELD(arg1, s32 *, 0x60) = (s32) (M2C_FIELD(arg1, s32 *, 0x60) | temp_r29_14865);
                            M2C_FIELD(arg1, s32 *, 0x5C) = (s32) (M2C_FIELD(arg1, s32 *, 0x5C) & ~temp_r29_14865);
                            MKWidget_GetMousePos(&clickPos);
                            timestamp = temp_f31_14848;
                        }
                        if (temp_r28_14863 != 0) {
                            MKWidget_GetMousePos(&sp58);
                            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
                            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                            sp18 = sp8;
                            sp10 = sp58.unk8 - clickPos.unk8;
                            sp20 = (f64) sp10;
                            sp28 = sp8;
                            sp30 = (f64) sp10;
                            if ((((f32) sp20 * (f32) sp20) + (((f32) sp18 * (f32) sp18) + (unksp1C * unksp1C))) < 100.0f) {
                                MKWidget_SendMessage(M2C_FIELD(arg1, MKWidget **, 0x50), 0x34U, temp_r28_14863);
                            }
                            M2C_FIELD(arg1, s32 *, 0x60) = (s32) (M2C_FIELD(arg1, s32 *, 0x60) & temp_r30_14864);
                        }
                    }
                }
            }
            goto block_51;
        case 4:
            temp_f5_14931 = gWidgetOrthoHeight / M2C_FIELD(&gDisplay, f32 *, 0x6C);
            temp_f6_14932 = M2C_BITWISE(f32, M2C_FIELD(arg0, u8 *, 8));
            temp_f3_14933 = M2C_BITWISE(f32, arg0->unk4);
            sp50 = 0.0f;
            sp40 = (f64) sp50;
            temp_f2_14942 = temp_f6_14932 * temp_f5_14931;
            temp_f1_14956 = (f32) (s32) temp_f2_14942;
            sp4C = temp_f1_14956;
            sp48 = (f32) (s32) (temp_f3_14933 * (gWidgetOrthoWidth / M2C_FIELD(&gDisplay, f32 *, 0x68)));
            sp38 = (f64) sp48;
            M2C_FIELD(arg1, MKWidget **, 0x58) = M2C_FIELD(M2C_FIELD(arg1, void **, 0), MKWidget *(**)(void *, f64 *, f32, f32, f32, f32, f32), 0x24)(arg1, &sp38, temp_f1_14956, temp_f2_14942, temp_f3_14933, temp_f5_14931, temp_f6_14932);
            if ((u32) M2C_FIELD(arg1, u32 *, 0x54) == 0U) {
                temp_r3_14970 = M2C_FIELD(arg1, MKWidget **, 0x50);
                if (temp_r3_14970 != (MKWidget *) M2C_FIELD(arg1, MKWidget **, 0x58)) {
                    if (temp_r3_14970 != NULL) {
                        MKWidget_SendMessage(temp_r3_14970, 0x2FU, 0U);
                    }
                    temp_r3_14980 = M2C_FIELD(arg1, MKWidget **, 0x58);
                    if (temp_r3_14980 != NULL) {
                        MKWidget_SendMessage(temp_r3_14980, 0x2FU, 1U);
                    }
                    M2C_FIELD(arg1, MKWidget **, 0x50) = (MKWidget *) M2C_FIELD(arg1, MKWidget **, 0x58);
                    M2C_FIELD(arg1, s32 *, 0x5C) = 0;
                    M2C_FIELD(arg1, s32 *, 0x60) = 0;
                }
            }
            MKWidget_SendMessage(M2C_FIELD(arg1, MKWidget **, 0x50), 0x2EU, (u32) &sp48);
            goto block_51;
        case 5:
            MKWidget_SendMessage(M2C_FIELD(arg1, MKWidget **, 0x4C), 0x35U, (u32) &arg0->unk4);
            goto block_51;
        case 6:
            if ((u8) arg0->unk9 != 0) {
                if ((u8) arg0->unkA == 0) {
                    MKWidget_SendMessage(M2C_FIELD(arg1, MKWidget **, 0x4C), 0x2AU, arg0->unk4);
                } else {
                    MKWidget_SendMessage(M2C_FIELD(arg1, MKWidget **, 0x4C), 0x2CU, arg0->unk4);
                }
                MKWidget_SendMessage(M2C_FIELD(arg1, MKWidget **, 0x4C), 0x29U, arg0->unk4);
                temp_r4_15026 = arg0->unk8;
                if ((s8) temp_r4_15026 != 0) {
                    MKWidget_SendMessage(M2C_FIELD(arg1, MKWidget **, 0x4C), 0x2DU, (u32) (s8) temp_r4_15026);
                }
            } else {
                MKWidget_SendMessage(M2C_FIELD(arg1, MKWidget **, 0x4C), 0x2BU, arg0->unk4);
            }
            goto block_51;
        default:
            return 1;
        }
    } else {
        return 1;
    }
}
#endif

u8 MKWidgetSystem::AnyVisible() {
    MKWidget *var_r31_15065;

    var_r31_15065 = this->unk28;
loop_4:
    if (var_r31_15065 == NULL) {
        return 0U;
    }
    if (var_r31_15065->IsFlagSet(2U) != 0) {
        return 1U;
    }
    var_r31_15065 = var_r31_15065->unk1C;
    goto loop_4;
}

MKWidget *MKWidgetSystem::ChangeMouseFocus(MKWidget *arg0) {
    MKWidget *temp_r0_15102;

    if ((arg0 != NULL) && ((MKWidget *) this->unk50 != arg0)) {
        this->unk50 = arg0;
        this->unk5C = 0;
        this->unk60 = 0;
    }
    temp_r0_15102 = this->unk54;
    this->unk54 = arg0;
    return temp_r0_15102;
}

MKWidget *MKWidgetSystem::ChangeFocus(MKWidget *arg0) {
    MKWidget *temp_r0_15111;

    temp_r0_15111 = this->unk4C;
    this->unk4C = arg0;
    return temp_r0_15111;
}

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void MKWidgetSystem::UpdateState() {
    MKVector3 sp18;
    f64 sp10;
    f64 sp8;
    MKWidget *temp_r31_15138;
    MKWidget *temp_r3_15141;
    f64 temp_f1_15127;

    MKWidget_GetMousePos(&sp18);
    temp_f1_15127 = M2C_BITWISE(f64, sp18);
    sp8 = temp_f1_15127;
    sp10 = (f64) sp18.unk8;
    temp_r31_15138 = GetWidgetUnderPoint(&sp8, temp_f1_15127);
    if ((MKWidget *) this->unk54 == NULL) {
        temp_r3_15141 = this->unk50;
        if (temp_r3_15141 != temp_r31_15138) {
            if (temp_r3_15141 != NULL) {
                MKWidget_SendMessage(temp_r3_15141, 0x2FU, 0U);
            }
            if (temp_r31_15138 != NULL) {
                MKWidget_SendMessage(temp_r31_15138, 0x2FU, 1U);
            }
            this->unk50 = temp_r31_15138;
            this->unk5C = 0;
            this->unk60 = 0;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_spB0'
void MKWidgetSystem::Draw(MKWidgetRenderContext arg0) {
    MKWidget *temp_r3_15377;
    MKWidget *temp_r3_15404;
    MKWidget *temp_r3_15431;
    MKWidget *var_r29_15183;
    f32 temp_f31_15356;
    f32 temp_f31_15379;
    f32 temp_f31_15405;
    f32 temp_f31_15436;
    f32 temp_f31_15465;
    f32 temp_f31_15481;
    s8 *var_r3_15338;
    s8 *var_r3_15358;
    s8 *var_r3_15382;
    s8 *var_r3_15409;
    u8 var_r0_15248;
    u8 var_r30_15184;
    var_r29_15183 = this->unk28;
    var_r30_15184 = 0;
loop_4:
    if (var_r29_15183 != NULL) {
        if (var_r29_15183->IsFlagSet(2U) != 0) {
            var_r30_15184 = 1;
        } else {
            var_r29_15183 = var_r29_15183->unk1C;
            goto loop_4;
        }
    }
    MKView_Push();
    arg_spB0 = 0.0f;
    arg_spB4 = 0.0f;
    arg_spB8 = gWidgetOrthoWidth;
    arg_spBC = gWidgetOrthoHeight;
    MKView_SetOrtho((MKRect *) &arg_spB0);
    if (var_r30_15184 != 0) {
        MKView_Clear(2, one, 0.0f, 1U);
        M2C_STRUCT_COPY((s32) &arg_spFC + 4, (s32) arg0 - 4 + 4, 0x50);
        MKWidgetContainer::Draw((MKWidgetRenderContext) &arg_sp100);
    }
    arg_spA0 = M2C_FIELD(&zero, f64 *, 0);
    arg_spA8 = M2C_FIELD(&zero, f64 *, 8);
    if ((u8) gShowCursor != 0) {
        MKWidget_GetMousePos((MKVector3 *) &arg_spA0);
        if ((u8) cursorVisible == 0) {
            var_r0_15248 = 0;
            if ((startPos.unk0 == (f32) arg_spA0) && (startPos.unk4 == arg_spA4) && (startPos.unk8 == (f32) arg_spA8)) {
                var_r0_15248 = 1;
            }
            if (var_r0_15248 == 0) {
                cursorVisible = 1;
            }
        } else {
            MKMaterial_SetMaterial(pWidgetBlank);
            MKPrimitive(3, 0);
            MKBegin(3);
            MKSetColorF(1.0f, 1.0f, 0.0f, 1.0f);
            MKSetPositionV(*((MKVector3 *) &arg_spA0));
            arg_sp40 = 20.0f;
            arg_sp44 = 10.0f;
            arg_sp48 = 0.0f;
            arg_sp70 = (f64) arg_sp40;
            arg_sp78 = (f64) arg_sp48;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp80 = arg_sp30;
            arg_sp38 = (f32) arg_spA8 + (f32) arg_sp78;
            arg_sp88 = (f64) arg_sp38;
            MKSetPositionV(*((MKVector3 *) &arg_sp80));
            arg_sp20 = 10.0f;
            arg_sp24 = 20.0f;
            arg_sp28 = 0.0f;
            arg_sp50 = (f64) arg_sp20;
            arg_sp58 = (f64) arg_sp28;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp60 = arg_sp10;
            arg_sp18 = (f32) arg_spA8 + (f32) arg_sp58;
            arg_sp68 = (f64) arg_sp18;
            MKSetPositionV(*((MKVector3 *) &arg_sp60));
            MKEnd();
            MKEndPrimitive();
        }
    }
    if ((u8) gWidgetDebug != 0) {
        var_r3_15338 = *this->unk50->unkC;
        if (var_r3_15338 != NULL) {

        } else {
            var_r3_15338 = "";
        }
        MKFont_DrawDebugStringF(var_r3_15338, 10.0f, 10.0f, 0.0f, one, -1, (MKFont *) gpDebugFont);
        temp_f31_15356 = 10.0f + M2C_ERROR(/* Read from unset register $f1 */);
        var_r3_15358 = *this->unk50->unk4;
        if (var_r3_15358 != NULL) {

        } else {
            var_r3_15358 = "";
        }
        MKFont_DrawDebugStringF(var_r3_15358, 10.0f, temp_f31_15356, 0.0f, one, -1, (MKFont *) gpDebugFont);
        temp_r3_15377 = this->unk4C;
        temp_f31_15379 = temp_f31_15356 + M2C_ERROR(/* Read from unset register $f1 */) + 10.0f;
        if (temp_r3_15377 != NULL) {
            var_r3_15382 = *temp_r3_15377->unkC;
            if (var_r3_15382 != NULL) {

            } else {
                var_r3_15382 = "";
            }
        } else {
            var_r3_15382 = "";
        }
        MKFont_DrawDebugStringF(var_r3_15382, 10.0f, temp_f31_15379, 0.0f, one, -1, (MKFont *) gpDebugFont);
        temp_r3_15404 = this->unk4C;
        temp_f31_15405 = temp_f31_15379 + M2C_ERROR(/* Read from unset register $f1 */);
        if (temp_r3_15404 != NULL) {
            var_r3_15409 = *temp_r3_15404->unk4;
            if (var_r3_15409 != NULL) {

            } else {
                var_r3_15409 = "";
            }
        } else {
            var_r3_15409 = "";
        }
        MKFont_DrawDebugStringF(var_r3_15409, 10.0f, temp_f31_15405, 0.0f, one, -1, (MKFont *) gpDebugFont);
        temp_r3_15431 = this->unk50;
        temp_f31_15436 = temp_f31_15405 + M2C_ERROR(/* Read from unset register $f1 */) + 10.0f;
        temp_r3_15431->GetLocalToWorldMatrix(&arg_spC0);
        MKFont_DrawDebugStringF(Str_Printf("", (u32) (u64) MKWidget_SendMessage(this->unk50, 9U, (u32) &arg_sp90), arg_sp90, arg_sp94, arg_sp98), 10.0f, temp_f31_15436, 0.0f, one, -1, (MKFont *) gpDebugFont);
        arg_sp90 = arg_spF0;
        temp_f31_15465 = temp_f31_15436 + M2C_ERROR(/* Read from unset register $f1 */);
        arg_sp98 = arg_spF8;
        MKFont_DrawDebugStringF(Str_Printf("", arg_sp90, arg_sp94, arg_sp98), 10.0f, temp_f31_15465, 0.0f, one, -1, (MKFont *) gpDebugFont);
        temp_f31_15481 = temp_f31_15465 + M2C_ERROR(/* Read from unset register $f1 */);
        MKFont_DrawDebugStringF(Str_Printf("", (u32) M2C_BITWISE(u64, MKWidget_GetLocalMousePos(this->unk50, (MKVector3 *) &arg_sp90)), arg_sp90, arg_sp94), 10.0f, temp_f31_15481, 0.0f, one, -1, (MKFont *) gpDebugFont);
        MKFont_DrawDebugStringF(Str_Printf("", this->unk5C, this->unk60, MKWidget_GetLocalMousePos(this->unk50, (MKVector3 *) &arg_sp90)), 10.0f, temp_f31_15481 + M2C_ERROR(/* Read from unset register $f1 */), 0.0f, one, -1, (MKFont *) gpDebugFont);
    }
    MKView_Pop();
}
#endif

#if 0 // DRAFT: undefined identifier 'MKWidgetSystemName'
MKWidgetSystem::MKWidgetSystem(MKWidgetDescriptor *arg0) {
    this->unk4C = (MKWidget *) this;
    this->unk58 = this;
    this->unk50 = (MKWidget *) this;
    *this->unk4 = MKWidgetSystemName;
    MKWidget_GetMousePos(&startPos);
    this->unk54 = NULL;
    this->unk5C = 0;
    this->unk60 = 0;
    this->unk40 = 0;
    this->unk48 = 0.0f;
    this->unk68 = M2C_FIELD(&zero, f64 *, 0);
    this->unk70 = M2C_FIELD(&zero, f64 *, 8);
    return this;
}
#endif

void MKWidgetContainer::BuildAggregateMetaData() {

}

void MKWidgetContainer::BuildMetaData(int arg0) {

}

void MKWidgetContainer::GetChild(int arg0) {
    MKWidget *var_r3_15588;
    s32 var_r5_15589;

    var_r3_15588 = this->unk28;
    var_r5_15589 = 0;
loop_2:
    if (var_r3_15588 != NULL) {
        if (var_r5_15589 >= arg0) {
            return;
        }
        var_r3_15588 = var_r3_15588->unk1C;
        var_r5_15589 += 1;
        goto loop_2;
    }
}

void MKWidgetContainer::GetChildIndex(MKWidget *arg0) {
    MKWidget *var_r5_15605;

    var_r5_15605 = this->unk28;
loop_3:
    if (var_r5_15605 == NULL) {
        return;
    }
    if (var_r5_15605 != arg0) {
        var_r5_15605 = var_r5_15605->unk1C;
        goto loop_3;
    }
}

u8 MKWidgetContainer::IsChildWidget(MKWidget *arg0) {
    MKWidget *var_r3_15622;

    var_r3_15622 = this->unk28;
loop_4:
    if (var_r3_15622 == NULL) {
        return 0U;
    }
    if (var_r3_15622 == arg0) {
        return 1U;
    }
    var_r3_15622 = var_r3_15622->unk1C;
    goto loop_4;
}

#if 0 // DRAFT: illegal implicit conversion from 'MKVector3' to
MKWidget *MKWidgetContainer::GetWidgetUnderPoint(MKVector3 arg0) {
    MKWidgetBoundingVolume sp18;
    f64 sp10;
    f64 sp8;
    MKWidget *temp_r3_15708;
    MKWidget *var_r30_15696;
    MKWidget *var_r31_15660;
    f32 temp_f1_15668;
    f32 temp_f2_15672;
    f64 temp_f1_15699;

    if (IsFlagSet(2U) == 0) {
        return NULL;
    }
    var_r31_15660 = TestPoint(arg0);
    if (var_r31_15660 == NULL) {
        return NULL;
    }
    MKWidget_GetClientVolume((MKWidget *) this, &sp18);
    temp_f1_15668 = M2C_FIELD(arg0, f32 *, 0);
    if ((temp_f1_15668 < 0.0f) || (temp_f2_15672 = M2C_FIELD(arg0, f32 *, 4), ((temp_f2_15672 < 0.0f) != 0)) || (M2C_ERROR(/* unknown instruction: cror eq, gt, eq */), ((temp_f1_15668 == sp18.unk10) != 0)) || (M2C_ERROR(/* unknown instruction: cror eq, gt, eq */), ((temp_f2_15672 == sp18.unk14) != 0))) {
        return var_r31_15660;
    }
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r29, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r30, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r29, 0x0, qr0 */);
    M2C_FIELD(arg0, f32 *, 8) = (f32) (M2C_FIELD(arg0, f32 *, 8) + this->unk38);
    var_r30_15696 = this->unk28;
loop_13:
    if (var_r30_15696 != NULL) {
        temp_f1_15699 = (f64) M2C_FIELD(arg0, f32 *, 0);
        sp8 = temp_f1_15699;
        sp10 = (f64) M2C_FIELD(arg0, f32 *, 8);
        temp_r3_15708 = var_r30_15696->GetWidgetUnderPoint(&sp8, temp_f1_15699);
        if (temp_r3_15708 != NULL) {
            var_r31_15660 = temp_r3_15708;
        }
        var_r30_15696 = var_r30_15696->unk1C;
        goto loop_13;
    }
    return var_r31_15660;
}
#endif

void MKWidgetContainer::Update() {
    MKWidget *var_r31_15738;

    UpdateState();
    var_r31_15738 = this->unk28;
loop_2:
    if (var_r31_15738 != NULL) {
        var_r31_15738->Update();
        var_r31_15738 = var_r31_15738->unk1C;
        goto loop_2;
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'MKWidgetRenderContext' to
void MKWidgetContainer::Draw(MKWidgetRenderContext arg0) {
    MKWidget *var_r30_15849;
    if (IsFlagSet(2U) != 0) {
        Render(arg0);
        MKWidget_GetClientVolume((MKWidget *) this, (MKWidgetBoundingVolume *) &arg_sp70);
        arg_sp30 = (arg_sp88 * M2C_FIELD(arg0, f32 *, 0x20)) + ((arg_sp80 * M2C_FIELD(arg0, f32 *, 0)) + (arg_sp84 * M2C_FIELD(arg0, f32 *, 0x10)));
        arg_sp34 = (arg_sp88 * M2C_FIELD(arg0, f32 *, 0x24)) + ((arg_sp80 * M2C_FIELD(arg0, f32 *, 4)) + (arg_sp84 * M2C_FIELD(arg0, f32 *, 0x14)));
        arg_sp38 = (arg_sp88 * M2C_FIELD(arg0, f32 *, 0x28)) + ((arg_sp80 * M2C_FIELD(arg0, f32 *, 8)) + (arg_sp84 * M2C_FIELD(arg0, f32 *, 0x18)));
        arg_sp90 = M2C_FIELD(arg0, f64 *, 0x30);
        arg_sp60 = (f64) arg_sp30;
        arg_sp98 = M2C_FIELD(arg0, f64 *, 0x38);
        arg_sp68 = (f64) arg_sp38;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_spA0 = arg_sp20;
        arg_sp50 = arg_sp20;
        arg_sp28 = (f32) arg_sp98 + (f32) arg_sp68;
        arg_spA8 = (f64) arg_sp28;
        arg_sp58 = (f64) arg_sp28;
        arg_sp10 = -this->unk30;
        arg_sp14 = -this->unk34;
        arg_sp18 = -this->unk38;
        arg_sp40 = (f64) arg_sp10;
        arg_sp48 = (f64) arg_sp18;
        arg0->Translate((Matrix *) arg0, *((MKVector3 *) &arg_sp40));
        if (PushScissorRect((MKWidgetScissorRect *) &arg_sp90) != 0) {
            var_r30_15849 = this->unk28;
loop_4:
            if (var_r30_15849 != NULL) {
                M2C_STRUCT_COPY((s32) &arg_spBC + 4, (s32) arg0 - 4 + 4, 0x50);
                var_r30_15849->Draw(&arg_spC0, &arg_spBC + 0x50);
                var_r30_15849 = var_r30_15849->unk1C;
                goto loop_4;
            }
            PopScissorRect();
        }
    }
}
#endif

#if 0 // DRAFT: identifier 'MKWidgetContainer::MessageHandler(unsigned int, unsigned int)'
u32 MKWidgetContainer::MessageHandler(unsigned int arg0, unsigned int arg1) {
    MKWidget *temp_r0_15927;
    MKWidget *temp_r0_15935;
    MKWidget *temp_r0_15958;
    MKWidget *temp_r0_15975;
    MKWidget *temp_r0_16012;
    MKWidget *temp_r0_16025;
    MKWidget *temp_r0_16042;
    MKWidget *temp_r26_16085;
    MKWidget *temp_r28_15916;
    MKWidget *var_r27_16106;
    MKWidget *var_r28_16059;
    MKWidget *var_r3_15913;
    MKWidget *var_r3_15930;
    MKWidget *var_r3_15997;
    MKWidget *var_r3_16007;
    MKWidget *var_r3_16037;
    MKWidget *var_r4_15970;
    s32 temp_r28_16077;
    s32 var_r26_16107;
    s32 var_r27_16060;

    if ((s32) arg0 != 0x3C) {
        if ((s32) arg0 < 0x3C) {
            if ((s32) arg0 != 0x3A) {
                if ((s32) arg0 < 0x3A) {
                    if ((s32) arg0 != 3) {

                    } else {
                        var_r3_15913 = this->unk28;
loop_14:
                        if (var_r3_15913 != NULL) {
                            temp_r28_15916 = var_r3_15913->unk1C;
                            MKWidget_Destroy(var_r3_15913);
                            var_r3_15913 = temp_r28_15916;
                            goto loop_14;
                        }
                    }
                    goto block_75;
                }
                if ((MKWidget *) this->unk28 != NULL) {
                    if ((u32) this->unk20 == arg1) {
                        this->unk20 = 0;
                    }
                    temp_r0_15958 = this->unk28;
                    if (temp_r0_15958 == arg1) {
                        this->unk28 = M2C_FIELD(arg1, MKWidget **, 0x1C);
                        M2C_FIELD(arg1, MKWidget **, 0x1C) = NULL;
                        this->unk2C -= 1;
                    } else {
                        var_r4_15970 = temp_r0_15958;
loop_30:
                        temp_r0_15975 = var_r4_15970->unk1C;
                        if ((temp_r0_15975 != NULL) && (temp_r0_15975 != arg1)) {
                            var_r4_15970 = temp_r0_15975;
                            goto loop_30;
                        }
                        if (temp_r0_15975 != NULL) {
                            var_r4_15970->unk1C = M2C_FIELD(arg1, MKWidget **, 0x1C);
                            M2C_FIELD(arg1, MKWidget **, 0x1C) = NULL;
                            this->unk2C -= 1;
                        }
                    }
                }
                return 0U;
            }
            M2C_FIELD(arg1, MKWidgetContainer **, 0x18) = this;
            M2C_FIELD(arg1, MKWidget **, 0x1C) = NULL;
            temp_r0_15927 = this->unk28;
            if (temp_r0_15927 != NULL) {
                var_r3_15930 = temp_r0_15927;
loop_19:
                temp_r0_15935 = var_r3_15930->unk1C;
                if (temp_r0_15935 != NULL) {
                    var_r3_15930 = temp_r0_15935;
                    goto loop_19;
                }
                var_r3_15930->unk1C = (MKWidget *) arg1;
            } else {
                this->unk28 = (MKWidget *) arg1;
            }
            this->unk2C += 1;
            return 0U;
        }
        switch ((s32) arg0) {                       /* irregular */
        default:
            var_r3_15997 = this->unk28;
            if (var_r3_15997 == arg1) {
                if ((arg0 == 0x3E) && ((MKWidget *) var_r3_15997->unk1C != NULL)) {
                    this->unk28 = M2C_FIELD(arg1, MKWidget **, 0x1C);
                    var_r3_16007 = this->unk28;
loop_41:
                    temp_r0_16012 = var_r3_16007->unk1C;
                    if (temp_r0_16012 != NULL) {
                        var_r3_16007 = temp_r0_16012;
                        goto loop_41;
                    }
                    var_r3_16007->unk1C = (MKWidget *) arg1;
                    M2C_FIELD(arg1, MKWidget **, 0x1C) = NULL;
                }
                return 0U;
            }
loop_46:
            temp_r0_16025 = var_r3_15997->unk1C;
            if (temp_r0_16025 != arg1) {
                var_r3_15997 = temp_r0_16025;
                goto loop_46;
            }
            var_r3_15997->unk1C = M2C_FIELD(arg1, MKWidget **, 0x1C);
            if (arg0 == 0x3D) {
                M2C_FIELD(arg1, MKWidget **, 0x1C) = (MKWidget *) this->unk28;
                this->unk28 = (MKWidget *) arg1;
            } else {
                var_r3_16037 = this->unk28;
loop_51:
                temp_r0_16042 = var_r3_16037->unk1C;
                if (temp_r0_16042 != NULL) {
                    var_r3_16037 = temp_r0_16042;
                    goto loop_51;
                }
                var_r3_16037->unk1C = (MKWidget *) arg1;
                M2C_FIELD(arg1, MKWidget **, 0x1C) = NULL;
            }
            return 0U;
        case 0x3F:
            M2C_FIELD(arg1, f64 *, 0) = (f64) M2C_FIELD(this, f64 *, 0x30);
            M2C_FIELD(arg1, f64 *, 8) = (f64) M2C_FIELD(this, f64 *, 0x38);
            return 0U;
        case 0x40:
            var_r28_16059 = this->unk28;
            var_r27_16060 = -1;
loop_58:
            if (var_r28_16059 != NULL) {
                var_r27_16060 += 1;
                if (var_r28_16059->IsFlagSet(8U) == 0) {
                    var_r28_16059 = var_r28_16059->unk1C;
                    goto loop_58;
                }
            }
            if (var_r27_16060 >= 0) {
                temp_r28_16077 = this->unk2C - 1;
loop_64:
                if (var_r27_16060 >= temp_r28_16077) {
                    goto block_75;
                }
                var_r27_16060 += 1;
                GetChild(var_r27_16060);
                temp_r26_16085 = M2C_ERROR(/* Read from unset register $r3 */);
                if ((M2C_FIELD(*M2C_ERROR(/* Read from unset register $r3 */), u8 (**)(), 0x2C)() != 0) || (temp_r26_16085->IsFlagSet(4U) != 0)) {
                    MKWidget_SetFocus(temp_r26_16085);
                    return 0U;
                }
                goto loop_64;
            }
block_75:
            return MKWidget::MessageHandler(arg0, arg1);
        case 0x41:
            var_r27_16106 = this->unk28;
            var_r26_16107 = -1;
loop_69:
            if (var_r27_16106 != NULL) {
                var_r26_16107 += 1;
                if (var_r27_16106->IsFlagSet(8U) == 0) {
                    var_r27_16106 = var_r27_16106->unk1C;
                    goto loop_69;
                }
            }
            if (var_r26_16107 >= 0) {
loop_74:
                if (var_r26_16107 <= 1) {
                    goto block_75;
                }
                var_r26_16107 -= 1;
                GetChild(var_r26_16107);
                if (((MKWidget *) (M2C_ERROR(/* Read from unset register $r3 */)))->IsFlagSet(4U) != 0) {
                    MKWidget_SetFocus(M2C_ERROR(/* Read from unset register $r3 */));
                    return 0U;
                }
                goto loop_74;
            }
            goto block_75;
        }
    } else {
        return this->unk2C;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'zero'
MKWidgetContainer::MKWidgetContainer(MKWidgetDescriptor *arg0) {
    this->unk28 = NULL;
    this->unk2C = 0;
    M2C_FIELD(this, f64 *, 0x30) = (f64) M2C_FIELD(&zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x38) = (f64) M2C_FIELD(&zero, f64 *, 8);
    MKWidget_DisableFlag((MKWidget *) this, 4U);
    return this;
}
#endif

void MKWidget::BuildAggregateMetaData() {

}

void MKWidget::BuildMetaData(int arg0) {

}

u8 MKWidget::IsChildWidget(MKWidget *arg0) {
    return 0U;
}

#if 0 // DRAFT: undefined identifier '__vptr'
void MKWidget::GetLocalToWorldMatrix(Matrix *arg0) {
    MKWidget *temp_r3_16218;
    MKWidget *temp_r3_16226;
    GetWidgetMatrix(arg0);
    temp_r3_16218 = this->unk18;
    if (temp_r3_16218 != NULL) {
        M2C_FIELD(temp_r3_16218->__vptr, M2C_UNK (**)(M2C_UNK *), 0x28)(&arg_sp40);
        temp_r3_16226 = this->unk18;
        if (temp_r3_16226->IsChildWidget(this) != 0) {
            MKWidget_SendMessage(this->unk18, 0x3FU, (u32) &arg_sp30);
            arg_sp10 = -arg_sp30;
            arg_sp14 = -arg_sp34;
            arg_sp18 = -arg_sp38;
            arg_sp20 = (f64) arg_sp10;
            arg_sp28 = (f64) arg_sp18;
            arg0->Translate(arg0, *((MKVector3 *) &arg_sp20));
        }
        arg0->Multiply4x4(arg0, (Matrix *) &arg_sp40);
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKVector3' to
MKWidget *MKWidget::GetWidgetUnderPoint(MKVector3 arg0) {
    if (IsFlagSet(2U) != 0) {
        return TestPoint(arg0);
    }
    return NULL;
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp30'
MKWidget *MKWidget::TestPoint(MKVector3 *arg0) {
    f32 temp_f1_16347;
    f32 temp_f2_16346;
    f32 temp_f3_16353;
    f32 temp_f4_16352;
    f32 temp_f5_16359;
    f32 temp_f6_16358;
    s8 **temp_r3_16363;
    GetWidgetMatrix((Matrix *) &arg_sp30);
    arg_sp30.Inverse((Matrix *) &arg_sp30);
    M2C_ERROR(/* unknown instruction: ps_madds0 $f31, $f30, $f28, $f31 */);
    M2C_ERROR(/* unknown instruction: ps_madds0 $f0, $f1, $f28, $f0 */);
    M2C_ERROR(/* unknown instruction: ps_madds1 $f31, $f29, $f2, $f31 */);
    M2C_ERROR(/* unknown instruction: ps_madds1 $f0, $f1, $f2, $f0 */);
    M2C_ERROR(/* unknown instruction: ps_madds0 $f0, $f1, $f2, $f0 */);
    arg0->unk8 = M2C_ERROR(/* unknown instruction: ps_madds0 $f31, $f30, $f2, $f31 */);
    MKWidget_GetClientVolume(this, (MKWidgetBoundingVolume *) &arg_sp10);
    temp_f2_16346 = arg0->unk0;
    temp_f1_16347 = -arg_sp10;
    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
    if (temp_f2_16346 == temp_f1_16347) {
        temp_f4_16352 = arg0->unk4;
        temp_f3_16353 = -arg_sp14;
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (temp_f4_16352 == temp_f3_16353) {
            temp_f6_16358 = arg0->unk8;
            temp_f5_16359 = -arg_sp18;
            M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
            if (temp_f6_16358 == temp_f5_16359) {
                temp_r3_16363 = this->unk4;
                if ((temp_f2_16346 < (temp_f1_16347 + M2C_FIELD(temp_r3_16363, f32 *, 0x38))) && (temp_f4_16352 < (temp_f3_16353 + M2C_FIELD(temp_r3_16363, f32 *, 0x3C)))) {
                    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                    if (temp_f6_16358 == (temp_f5_16359 + M2C_FIELD(temp_r3_16363, f32 *, 0x40))) {
                        return this;
                    }
                }
            }
        }
    }
    return NULL;
}
#endif

void MKWidget::Update() {
    UpdateState();
}

void MKWidget::UpdateState() {

}

#if 0 // DRAFT: illegal implicit conversion from 'MKWidgetRenderContext' to
void MKWidget::Draw(MKWidgetRenderContext arg0) {
    if (IsFlagSet(2U) != 0) {
        Render(arg0);
    }
}
#endif

#if 0 // DRAFT: identifier 'MKWidget::Render(MKWidgetRenderContext *)' redeclared
s32 MKWidget::Render(MKWidgetRenderContext *arg0) {
    GetWidgetMatrix((Matrix *) &arg_sp10);
    arg0->Multiply4x4((Matrix *) &arg_sp10, (Matrix *) arg0);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_mul $f0, $f1, $f0 */);
    M2C_ERROR(/* unknown instruction: psq_stx $f0, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r4, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_mul $f0, $f1, $f0 */);
    M2C_ERROR(/* unknown instruction: psq_stx $f0, $r31, $r3, 0x0, qr0 */);
    return 0x48;
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp10'
void MKWidget::GetWidgetMatrix(Matrix *arg0) {
    arg0->SetIdentity();
    MKWidget_GetClientVolume(this, (MKWidgetBoundingVolume *) &arg_sp10);
    arg0->Translate(arg0, *((MKVector3 *) &arg_sp10));
    arg_sp30.SetIdentity();
    arg_sp30.Scale3x3((Matrix *) &arg_sp30, *(MKVector3 *) (this->unk4 + 0x18));
    arg0->Multiply(arg0, (Matrix *) &arg_sp30);
    arg_sp30.SetRotationPYR(*(MKVector3 *) (this->unk4 + 0x28));
    arg0->Multiply(arg0, (Matrix *) &arg_sp30);
    arg0->Translate(arg0, *(MKVector3 *) (this->unk4 + 8));
}
#endif

#if 0 // DRAFT: function call 'MKWidget(int)' does not match
s32 MKWidget::MessageHandler(unsigned int arg0, unsigned int arg1) {
    MKWidget *temp_r3_16558;
    MKWidget *temp_r3_16774;
    MKWidget *temp_r3_16795;
    MKWidget *temp_r3_16837;
    MKWidget *temp_r3_16855;
    MKWidget *temp_r3_16936;
    s32 temp_r0_16718;
    s32 temp_r5_16782;
    s32 var_r3_16767;
    s8 **temp_r3_16581;
    s8 **temp_r3_16588;
    s8 **temp_r3_16595;
    s8 **temp_r3_16602;
    s8 **temp_r3_16609;
    s8 **temp_r3_16616;
    s8 **temp_r3_16623;
    s8 **temp_r3_16630;
    s8 **temp_r3_16637;
    s8 **temp_r3_16644;
    s8 **temp_r3_16661;
    s8 **temp_r3_16666;
    s8 **temp_r3_16678;
    s8 **temp_r3_16717;
    s8 **temp_r3_16727;
    s8 **temp_r3_16744;
    s8 **temp_r3_16750;
    u32 temp_r3_16803;
    u32 temp_r3_16811;
    void *var_r29_16699;

    switch (arg0) {
    case 0x3:
        temp_r3_16558 = this->unk18;
        if (temp_r3_16558 != NULL) {
            MKWidget_SendMessage(temp_r3_16558, 0x3BU, (u32) this);
        }
        if (MKWidget_GetFocus() == this) {
            MKWidget_SetFocus(this->unk18);
        }
        if (this != NULL) {
            ~MKWidget(1);
        }
    default:
block_82:
        return 0;
    case 0x4:
        temp_r3_16581 = this->unk4;
        M2C_FIELD(temp_r3_16581, f64 *, 8) = (f64) M2C_FIELD(arg1, f64 *, 0);
        M2C_FIELD(temp_r3_16581, f64 *, 0x10) = (f64) M2C_FIELD(arg1, f64 *, 8);
        goto block_82;
    case 0x5:
        temp_r3_16588 = this->unk4;
        M2C_FIELD(temp_r3_16588, f64 *, 0x38) = (f64) M2C_FIELD(arg1, f64 *, 0);
        M2C_FIELD(temp_r3_16588, f64 *, 0x40) = (f64) M2C_FIELD(arg1, f64 *, 8);
        goto block_82;
    case 0x6:
        temp_r3_16595 = this->unk4;
        M2C_FIELD(temp_r3_16595, f64 *, 0x18) = (f64) M2C_FIELD(arg1, f64 *, 0);
        M2C_FIELD(temp_r3_16595, f64 *, 0x20) = (f64) M2C_FIELD(arg1, f64 *, 8);
        goto block_82;
    case 0x7:
        temp_r3_16602 = this->unk4;
        M2C_FIELD(temp_r3_16602, f64 *, 0x28) = (f64) M2C_FIELD(arg1, f64 *, 0);
        M2C_FIELD(temp_r3_16602, f64 *, 0x30) = (f64) M2C_FIELD(arg1, f64 *, 8);
        goto block_82;
    case 0x8:
        temp_r3_16609 = this->unk4;
        M2C_FIELD(temp_r3_16609, f64 *, 0x48) = (f64) M2C_FIELD(arg1, f64 *, 0);
        M2C_FIELD(temp_r3_16609, f64 *, 0x50) = (f64) M2C_FIELD(arg1, f64 *, 8);
        goto block_82;
    case 0x9:
        temp_r3_16616 = this->unk4;
        M2C_FIELD(arg1, f64 *, 0) = (f64) M2C_FIELD(temp_r3_16616, f64 *, 8);
        M2C_FIELD(arg1, f64 *, 8) = (f64) M2C_FIELD(temp_r3_16616, f64 *, 0x10);
        goto block_82;
    case 0xA:
        temp_r3_16623 = this->unk4;
        M2C_FIELD(arg1, f64 *, 0) = (f64) M2C_FIELD(temp_r3_16623, f64 *, 0x38);
        M2C_FIELD(arg1, f64 *, 8) = (f64) M2C_FIELD(temp_r3_16623, f64 *, 0x40);
        goto block_82;
    case 0xB:
        temp_r3_16630 = this->unk4;
        M2C_FIELD(arg1, f64 *, 0) = (f64) M2C_FIELD(temp_r3_16630, f64 *, 0x18);
        M2C_FIELD(arg1, f64 *, 8) = (f64) M2C_FIELD(temp_r3_16630, f64 *, 0x20);
        goto block_82;
    case 0xC:
        temp_r3_16637 = this->unk4;
        M2C_FIELD(arg1, f64 *, 0) = (f64) M2C_FIELD(temp_r3_16637, f64 *, 0x28);
        M2C_FIELD(arg1, f64 *, 8) = (f64) M2C_FIELD(temp_r3_16637, f64 *, 0x30);
        goto block_82;
    case 0xD:
        temp_r3_16644 = this->unk4;
        M2C_FIELD(arg1, f64 *, 0) = (f64) M2C_FIELD(temp_r3_16644, f64 *, 0x48);
        M2C_FIELD(arg1, f64 *, 8) = (f64) M2C_FIELD(temp_r3_16644, f64 *, 0x50);
        goto block_82;
    case 0xE:
        this->unk10 = arg1;
        goto block_82;
    case 0xF:
        this->unk14 = (s32) arg1;
        goto block_82;
    case 0x10:
        M2C_FIELD(arg1, f64 *, 0) = (s32) this->unk14;
        goto block_82;
    case 0x11:
        temp_r3_16661 = this->unk4;
        M2C_FIELD(arg1, f64 *, 0) = (f64) M2C_FIELD(temp_r3_16661, f64 *, 8);
        M2C_FIELD(arg1, f64 *, 8) = (f64) M2C_FIELD(temp_r3_16661, f64 *, 0x10);
        temp_r3_16666 = this->unk4;
        M2C_FIELD(arg1, f64 *, 0x10) = (f64) M2C_FIELD(temp_r3_16666, f64 *, 0x38);
        M2C_FIELD(arg1, f64 *, 0x18) = (f64) M2C_FIELD(temp_r3_16666, f64 *, 0x40);
        goto block_82;
    case 0x12:
        M2C_FIELD(arg1, f64 *, 0) = (f64) M2C_FIELD(&zero, f64 *, 0);
        M2C_FIELD(arg1, f64 *, 8) = (f64) M2C_FIELD(&zero, f64 *, 8);
        temp_r3_16678 = this->unk4;
        M2C_FIELD(arg1, f64 *, 0x10) = (f64) M2C_FIELD(temp_r3_16678, f64 *, 0x38);
        M2C_FIELD(arg1, f64 *, 0x18) = (f64) M2C_FIELD(temp_r3_16678, f64 *, 0x40);
        goto block_82;
    case 0x13:
        M2C_FIELD(arg1, f64 *, 0) = (s8 *) M2C_FIELD(this->unk4, s8 **, 0);
        goto block_82;
    case 0x14:
        M2C_FIELD(this->unk4, s8 **, 0) = (s8 *) arg1;
        goto block_82;
    case 0x15:
        M2C_FIELD(arg1, f64 *, 0) = (s32) *this->unkC;
        goto block_82;
    case 0x16:
        var_r29_16699 = this->unkC;
loop_30:
        if (var_r29_16699 == NULL) {
            return 0;
        }
        if (strcmp((s8 *) arg1, M2C_FIELD(var_r29_16699, s8 **, 0)) == 0) {
            return 1;
        }
        var_r29_16699 = M2C_FIELD(var_r29_16699, void **, 8);
        goto loop_30;
    case 0x19:
        temp_r3_16717 = this->unk4;
        temp_r0_16718 = 0 - arg1;
        M2C_FIELD(temp_r3_16717, u32 *, 0x60) = (u32) ((2 & ((temp_r0_16718 - temp_r0_16718) - !M2C_CARRY) & ~0xFFFFFFFD) | (M2C_FIELD(temp_r3_16717, u32 *, 0x60) & 0xFFFFFFFD));
        goto block_82;
    case 0x1A:
        temp_r3_16727 = this->unk4;
        M2C_FIELD(temp_r3_16727, u32 *, 0x60) = (u32) ((M2C_FIELD(temp_r3_16727, u32 *, 0x60) & 0xFFFFFFFE) | (arg1 != 0));
        goto block_82;
    case 0x1B:
        M2C_FIELD(this->unk4, u32 *, 0x60) = arg1;
        goto block_82;
    case 0x1C:
        return (s32) M2C_FIELD(this->unk4, u32 *, 0x60);
    case 0x1D:
        temp_r3_16744 = this->unk4;
        M2C_FIELD(temp_r3_16744, u32 *, 0x60) = (u32) (M2C_FIELD(temp_r3_16744, u32 *, 0x60) | arg1);
        goto block_82;
    case 0x1E:
        temp_r3_16750 = this->unk4;
        M2C_FIELD(temp_r3_16750, u32 *, 0x60) = (u32) (M2C_FIELD(temp_r3_16750, u32 *, 0x60) & ~arg1);
        goto block_82;
    case 0x1F:
        if (arg1 != 0) {
            MKWidget_EnableFlag(this, 8U);
        } else {
            MKWidget_DisableFlag(this, 8U);
        }
        goto block_82;
    case 0x25:
        var_r3_16767 = -1;
        if (arg1 != 0) {
            var_r3_16767 = 1;
        }
        this->unk24 += var_r3_16767;
        temp_r3_16774 = this->unk18;
        if (temp_r3_16774 != NULL) {
            MKWidget_SendMessage(temp_r3_16774, arg0, arg1);
        }
        goto block_82;
    case 0x24:
        temp_r5_16782 = this->unk24;
        if (temp_r5_16782 != 0) {
            MKWidget_SendMessage(this, 0x1FU, temp_r5_16782 > 0);
            this->unk24 = 0;
        }
        if (arg1 == 0) {
            temp_r3_16795 = this->unk18;
            if (temp_r3_16795 != NULL) {
                MKWidget_SendMessage(temp_r3_16795, arg0, arg1);
            } else {
                temp_r3_16803 = this->unk20;
                if (temp_r3_16803 != 0) {
                    MKWidget_SendMessage((MKWidget *) temp_r3_16803, arg0, 1U);
                }
            }
        } else {
            temp_r3_16811 = this->unk20;
            if (temp_r3_16811 != 0) {
                MKWidget_SendMessage((MKWidget *) temp_r3_16811, arg0, arg1);
            }
        }
        goto block_82;
    case 0x22:
        if ((IsFlagSet(4U) != 0) && (IsFlagSet(1U) != 0) && (IsFlagSet(2U) != 0)) {
            M2C_FIELD(arg1, f64 *, 0) = this;
            return 0;
        }
        temp_r3_16837 = this->unk18;
        if ((temp_r3_16837 != NULL) && (temp_r3_16837->IsFlagSet(8U) == 0)) {
            return MKWidget_SendMessage(this->unk18, arg0, arg1);
        }
        M2C_FIELD(arg1, f64 *, 0) = 0;
        return 0;
    case 0x23:
        temp_r3_16855 = this->unk18;
        if (temp_r3_16855 != NULL) {
            temp_r3_16855->unk20 = (u32) this;
            MKWidget_SendMessage(this->unk18, arg0, (u32) this);
        }
        return 0;
    case 0x20:
        MKWidget_GetSystem(this);
        return ((MKWidgetSystem *) (M2C_ERROR(/* Read from unset register $r3 */)))->ChangeFocus(this);
    case 0x21:
        if (arg1 != 0) {
            MKWidget_GetSystem(this);
            ((MKWidgetSystem *) (M2C_ERROR(/* Read from unset register $r3 */)))->ChangeMouseFocus(this);
        } else {
            MKWidget_GetSystem(this);
            ((MKWidgetSystem *) (M2C_ERROR(/* Read from unset register $r3 */)))->ChangeMouseFocus(NULL);
        }
        return 1;
    case 0x30:
        MKWidget_SetFocus(this);
        goto block_82;
    case 0x3F:
        M2C_FIELD(arg1, f64 *, 0) = 0.0f;
        M2C_FIELD(arg1, f32 *, 4) = 0.0f;
        M2C_FIELD(arg1, f64 *, 8) = 0.0f;
        goto block_82;
    case 0x29:
        if (arg1 == 9) {
            if (MKInput_GetState(0x10, (MKInputDevices) 5, NULL, NULL) != 0.0f) {
                MKWidget_SendMessage(this, 0x41U, 0U);
                return 0;
            }
            MKWidget_SendMessage(this, 0x40U, 0U);
            return 0;
        }
        goto block_82;
    case 0x27:
        if ((s16) (u16) arg1 == 8) {
            MKWidget_SendMessage(this, 0x41U, 0U);
            return 0;
        }
        if ((s16) (u16) arg1 == 9) {
            MKWidget_SendMessage(this, 0x40U, 0U);
            return 0;
        }
    case 0x26:
    case 0x28:
    case 0x35:
    case 0x39:
    case 0x40:
    case 0x41:
        temp_r3_16936 = this->unk18;
        if (temp_r3_16936 != NULL) {
            MKWidget_SendMessage(temp_r3_16936, arg0, arg1);
        }
        goto block_82;
    }
}
#endif

u8 MKWidget::IsFlagSet(unsigned int arg0) const {
    return (M2C_FIELD(this->unk4, s32 *, 0x60) & arg0) != 0;
}

#if 0 // DRAFT: undefined identifier '__vt'
MKWidget::~MKWidget() {
    MKHeap *temp_r3_16980;
    s8 **temp_r31_16979;

    if (this != NULL) {
        if ((u8) this->unk8 == 0) {
            temp_r31_16979 = this->unk4;
            temp_r3_16980 = __vt.Current();
            if (temp_r3_16980 != NULL) {
                ((MKHeap *) (temp_r3_16980->Current()))->Free(temp_r31_16979, NULL, 0);
            } else {
                free((s8 *) temp_r31_16979);
            }
            this->unk4 = NULL;
        }
    }
}
#endif

#if 0 // DRAFT: expression syntax error
MKWidget::MKWidget(MKWidgetDescriptor *arg0) {
    s8 **temp_r5_17042;

    this->unkC = arg0;
    this->unk10 = 0;
    this->unk14 = 0;
    this->unk18 = NULL;
    this->unk1C = NULL;
    this->unk20 = 0;
    this->unk24 = 0;
    this->unk8 = this->unk4.GetMetaData(*(M2C_FIELD(this->unkC, MKWidgetMetaData ***, 4)), (u32) &__vt);
    if ((u8) this->unk8 == 0) {
        M2C_FIELD(this->unk4, s8 **, 0) = NULL;
        temp_r5_17042 = this->unk4;
        M2C_FIELD(temp_r5_17042, f64 *, 8) = (f64) M2C_FIELD(MKWidgetIdentityAttributes, f64 *, 0);
        M2C_FIELD(temp_r5_17042, f64 *, 0x10) = (f64) M2C_FIELD(MKWidgetIdentityAttributes, f64 *, 8);
        M2C_FIELD(temp_r5_17042, f64 *, 0x18) = (f64) M2C_FIELD(MKWidgetIdentityAttributes, f64 *, 0x10);
        M2C_FIELD(temp_r5_17042, f64 *, 0x20) = (f64) M2C_FIELD(MKWidgetIdentityAttributes, f64 *, 0x18);
        M2C_FIELD(temp_r5_17042, f64 *, 0x28) = (f64) M2C_FIELD(MKWidgetIdentityAttributes, f64 *, 0x20);
        M2C_FIELD(temp_r5_17042, f64 *, 0x30) = (f64) M2C_FIELD(MKWidgetIdentityAttributes, f64 *, 0x28);
        M2C_FIELD(temp_r5_17042, f64 *, 0x38) = (f64) M2C_FIELD(MKWidgetIdentityAttributes, f64 *, 0x30);
        M2C_FIELD(temp_r5_17042, f64 *, 0x40) = (f64) M2C_FIELD(MKWidgetIdentityAttributes, f64 *, 0x38);
        M2C_FIELD(temp_r5_17042, f64 *, 0x48) = (f64) M2C_FIELD(MKWidgetIdentityAttributes, f64 *, 0x40);
        M2C_FIELD(temp_r5_17042, f64 *, 0x50) = (f64) M2C_FIELD(MKWidgetIdentityAttributes, f64 *, 0x48);
        M2C_FIELD(temp_r5_17042, s32 *, 0x58) = (s32) M2C_FIELD(MKWidgetIdentityAttributes, s32 *, 0x50);
        MKWidget_SetFlags(this, 7U);
    }
    return this;
}
#endif

#if 0 // DRAFT: function call 'MKSetColorV(void)' does not match
void WidgetDrawBox(const MKVector3 &arg0, const MKVector3 &arg1, int arg2) {
    MKBegin(4);
    MKSetColorV(*(MKWidget_GetMetric(arg2)));
    MKSetPositionV(arg0);
    MKSetColorV(*(MKWidget_GetMetric(arg2 + 2)));
    MKSetPositionF(arg1.unk0, arg0.unk4, 0.0f);
    MKSetColorV(*(MKWidget_GetMetric(arg2 + 1)));
    MKSetPositionF(arg0.unk0, arg1.unk4, 0.0f);
    MKSetColorV(*(MKWidget_GetMetric(arg2 + 3)));
    MKSetPositionV(arg1);
    MKEnd();
}
#endif

void WidgetDrawBox(const MKVector3 &arg0, const MKVector3 &arg1, const MKVector4 &arg2) {
    MKBegin(4);
    MKSetColorV(arg2);
    MKSetPositionV(arg0);
    MKSetPositionF(arg1.unk0, arg0.unk4, 0.0f);
    MKSetPositionF(arg0.unk0, arg1.unk4, 0.0f);
    MKSetPositionV(arg1);
    MKEnd();
}

void WidgetDrawSquare(const MKVector3 &arg0, const MKVector3 &arg1, float arg2, const MKVector4 &arg3) {
    MKBegin(0xA);
    MKSetColorV(arg3);
    MKSetPositionF(arg0.unk0, arg1.unk4, 0.0f);
    MKSetPositionF(arg0.unk0 + arg2, arg1.unk4 - arg2, 0.0f);
    MKSetPositionF(arg0.unk0, arg0.unk4, 0.0f);
    MKSetPositionF(arg0.unk0 + arg2, arg0.unk4 + arg2, 0.0f);
    MKSetPositionF(arg1.unk0, arg0.unk4, 0.0f);
    MKSetPositionF(arg1.unk0 - arg2, arg0.unk4 + arg2, 0.0f);
    MKSetPositionF(arg1.unk0, arg1.unk4, 0.0f);
    MKSetPositionF(arg1.unk0 - arg2, arg1.unk4 - arg2, 0.0f);
    MKSetPositionF(arg0.unk0, arg1.unk4, 0.0f);
    MKSetPositionF(arg0.unk0 + arg2, arg1.unk4 - arg2, 0.0f);
    MKEnd();
}

#if 0 // DRAFT: illegal implicit conversion from 'const MKVector4 *' to
void WidgetDrawBevel(const MKVector3 &arg0, const MKVector3 &arg1, float arg2, const MKVector4 &arg3, const MKVector4 &arg4, bool arg5, bool arg6) {
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    MKVector4 *var_r3_17250;
    MKVector4 *var_r3_17296;
    f32 temp_f1_17335;

    MKBegin(0xE);
    if (arg5 != 0) {
        var_r3_17250 = &arg4;
    } else {
        var_r3_17250 = &arg3;
    }
    MKSetColorV(*var_r3_17250);
    MKSetPositionF(arg0.unk0 + arg2, arg1.unk4 - arg2, 0.0f);
    MKSetPositionF(arg0.unk0, arg1.unk4, 0.0f);
    MKSetPositionF(arg0.unk0 + arg2, arg0.unk4 + arg2, 0.0f);
    MKSetPositionF(arg0.unk0, arg0.unk4, 0.0f);
    MKSetPositionF(arg1.unk0 - arg2, arg0.unk4 + arg2, 0.0f);
    MKSetPositionF(arg1.unk0, arg0.unk4, 0.0f);
    MKSetPositionF(arg1.unk0, arg0.unk4, 0.0f);
    MKSetPositionF(arg0.unk0, arg1.unk4, 0.0f);
    if (arg5 != 0) {
        var_r3_17296 = &arg3;
    } else {
        var_r3_17296 = &arg4;
    }
    MKSetColorV(*var_r3_17296);
    MKSetPositionF(arg0.unk0, arg1.unk4, 0.0f);
    MKSetPositionF(arg0.unk0 + arg2, arg1.unk4 - arg2, 0.0f);
    MKSetPositionF(arg1.unk0, arg1.unk4, 0.0f);
    MKSetPositionF(arg1.unk0 - arg2, arg1.unk4 - arg2, 0.0f);
    MKSetPositionF(arg1.unk0, arg0.unk4, 0.0f);
    MKSetPositionF(arg1.unk0 - arg2, arg0.unk4 + arg2, 0.0f);
    MKEnd();
    if (arg6 != 0) {
        temp_f1_17335 = -arg2;
        sp20 = 0.0f;
        sp18 = temp_f1_17335;
        sp1C = temp_f1_17335;
        sp50 = (f64) sp20;
        sp48 = (f64) sp18;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r27, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp40 = 0.0f;
        sp10 = arg1.unk8 + (f32) sp50;
        sp38 = arg2;
        sp3C = arg2;
        sp58 = sp8;
        sp68 = (f64) sp38;
        sp60 = (f64) sp10;
        sp70 = (f64) sp40;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r26, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp78 = sp28;
        sp30 = arg0.unk8 + (f32) sp70;
        sp80 = (f64) sp30;
        WidgetDrawBevel(*((MKVector3 *) &sp78), *((MKVector3 *) &sp58), arg2, arg3, arg4, arg5 == 0, 0U);
    }
}
#endif

void PopScissorRect() {
    pScissorRectStack = pScissorRectStack->unk20;
    ApplyScissorRect();
}

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
u8 PushScissorRect(MKWidgetScissorRect *arg0) {
    f64 sp40;
    f64 sp38;
    MKVector3 sp28;
    MKVector3 sp18;
    f32 sp10;

    if ((MKWidgetScissorRect *) pScissorRectStack != NULL) {
        Max(sp28, *((MKVector3 *) arg0));
        arg0->unk0 = M2C_BITWISE(f64, sp28);
        arg0->unk8 = (f64) sp28.unk8;
        Min(sp18, arg0->unk10);
        M2C_FIELD(arg0, f64 *, 0x10) = M2C_BITWISE(f64, sp18);
        M2C_FIELD(arg0, f64 *, 0x18) = (f64) sp18.unk8;
    }
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r31, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    sp38 = sp8;
    sp10 = arg0->unk10.unk8 - (f32) M2C_FIELD(arg0, f64 *, 8);
    sp40 = (f64) sp10;
    if (((f32) sp38 > 0.0001f) && (unksp3C > 0.0001f)) {
        arg0->unk20 = pScissorRectStack;
        pScissorRectStack = arg0;
        ApplyScissorRect();
        return 1U;
    }
    return 0U;
}
#endif

void ApplyScissorRect() {
    f32 temp_f28_17510;
    f32 temp_f30_17495;

    if ((MKWidgetScissorRect *) pScissorRectStack != NULL) {
        temp_f30_17495 = M2C_FIELD(pScissorRectStack, f32 *, 4);
        temp_f28_17510 = M2C_FIELD(pScissorRectStack, f32 *, 0);
        GXSetScissor((u32) ((f32) M2C_FIELD(&gDisplay, s32 *, 0x10) * (temp_f28_17510 / gWidgetOrthoWidth)), (u32) ((f32) M2C_FIELD(&gDisplay, s32 *, 0x14) * (temp_f30_17495 / gWidgetOrthoHeight)), (u32) ((f32) M2C_FIELD(&gDisplay, s32 *, 0x10) * ((pScissorRectStack->unk10.unk0 - temp_f28_17510) / gWidgetOrthoWidth)), (u32) ((f32) M2C_FIELD(&gDisplay, s32 *, 0x14) * ((pScissorRectStack->unk10.unk4 - temp_f30_17495) / gWidgetOrthoHeight)));
        return;
    }
    GXSetScissor(0U, 0U, M2C_FIELD(&gDisplay, s32 *, 0x10) - 1, M2C_FIELD(&gDisplay, s32 *, 0x14) - 1);
}

#if 0 // DRAFT: undefined identifier 'sp'
void MKWidget_LoadHierarchy(const char *arg0, MKWidgetContainer *arg1) {
    MKMetadata sp8;
    MKWidgetContainer *var_r6_17670;
    f32 temp_f1_17605;
    s32 (*var_r7_17679)(MKWidget *, u32, u32, void *);
    s32 temp_r0_17667;
    s32 temp_r0_17690;
    s32 var_r27_17654;
    s32 var_r29_17655;
    s8 *temp_r3_17597;
    s8 *temp_r3_17605;
    s8 *temp_ret_17597;
    s8 *temp_ret_17605;
    s8 *temp_ret_17615;
    s8 *temp_ret_17632;
    void *temp_r1_17584;
    void *temp_r3_17663;
    void *temp_r3_17666;

    temp_r1_17584 = sp - 0x30;
    temp_ret_17597 = Str_Printf("", arg0, "");
    temp_r3_17597 = temp_ret_17597;
    temp_ret_17605 = Str_Printf("", arg0, "", M2C_BITWISE(f32, temp_ret_17597));
    temp_f1_17605 = M2C_BITWISE(f32, temp_ret_17605);
    temp_r3_17605 = temp_ret_17605;
    M2C_FIELD(temp_r1_17584, s32 *, 0xC) = 0;
    M2C_FIELD(temp_r1_17584, s32 *, 8) = 0;
    temp_ret_17615 = Str_Printf("", temp_r3_17597, "MKWidgetContainer", temp_f1_17605);
    MKMetadata_Open(Str_Printf("", temp_r3_17597, M2C_BITWISE(f32, temp_ret_17615)), temp_ret_17615, temp_r1_17584 + 0xC);
    pHierarchyFile.unk0 = M2C_ERROR(/* Read from unset register $r3 */);
    temp_ret_17632 = Str_Printf("", temp_r3_17605);
    MKMetadata_Open(Str_Printf("", temp_r3_17605, M2C_BITWISE(f32, temp_ret_17632)), temp_ret_17632, temp_r1_17584 + 8);
    pMetaDataFile.unk0 = M2C_ERROR(/* Read from unset register $r3 */);
    ((MKWidgetSerialise *) (M2C_ERROR(/* Read from unset register $r3 */)))->SerialiseVersion();
    metaDataResolveIndex.unk0 = (MKMetadata *)1U;
    *(temp_r1_17584 + (((M2C_FIELD(temp_r1_17584, s32 *, 0xC) - 1) * -4) & 0xFFFFFFF8)) = sp0;
    var_r27_17654 = 1;
    var_r29_17655 = 4;
    pIndexList.unk0 = &sp8;
loop_8:
    if (var_r27_17654 < (s32) M2C_FIELD(temp_r1_17584, s32 *, 0xC)) {
        temp_r3_17663 = MKMetadata_Resolve(pHierarchyFile.unk0, var_r27_17654, NULL);
        temp_r3_17666 = MKWidget_FindMessageHook(M2C_FIELD(temp_r3_17663, s8 **, 4));
        temp_r0_17667 = M2C_FIELD(temp_r3_17663, s32 *, 8);
        if (temp_r0_17667 == -1) {
            var_r6_17670 = arg1;
        } else {
            var_r6_17670 = *(pIndexList.unk0 + (temp_r0_17667 * 4));
        }
        if (temp_r3_17666 != NULL) {
            var_r7_17679 = M2C_FIELD(temp_r3_17666, s32 (**)(MKWidget *, u32, u32, void *), 4);
        } else {
            var_r7_17679 = NULL;
        }
        temp_r0_17690 = var_r29_17655 - 4;
        var_r27_17654 += 1;
        var_r29_17655 += 4;
        *(pIndexList.unk0 + temp_r0_17690) = MKWidget_Create(M2C_FIELD(temp_r3_17663, s8 **, 0), NULL, NULL, (MKWidget *) var_r6_17670, var_r7_17679, NULL);
        goto loop_8;
    }
    pIndexList.unk0 = NULL;
    MKMetadata_Close(pHierarchyFile.unk0);
    MKMetadata_Close(pMetaDataFile.unk0);
    pHierarchyFile.unk0 = NULL;
    pMetaDataFile.unk0 = NULL;
}
#endif

void MKWidget_SaveHierarchy(const char *arg0, MKWidget *arg1) {

}

void MKWidgetSerialise::SerialiseVersion() {

}

#if 0 // DRAFT: expression syntax error
u8 MKWidgetSerialise::GetMetaData(MKWidgetMetaData *&arg0, unsigned int arg1) {
    MKHeap *temp_r3_17751;
    s8 *var_r3_17758;

    if ((MKMetadata *) pMetaDataFile.unk0 != NULL) {
        this->unk0 = MKMetadata_Resolve(pMetaDataFile.unk0, (s32) metaDataResolveIndex.unk0, NULL);
        metaDataResolveIndex.unk0 += 1;
        return 1U;
    }
    temp_r3_17751 = MKHeap::Current();
    if (temp_r3_17751 != NULL) {
        var_r3_17758 = ((MKHeap *) (temp_r3_17751->Current()))->Alloc((s32) &arg0, NULL, 0);
    } else {
        var_r3_17758 = malloc((u32) &arg0);
    }
    this->unk0 = (MKMetadata *) var_r3_17758;
    return 0U;
}
#endif

#if 0 // DRAFT: identifier 'arg4' redeclared
MKWidgetDescriptor::MKWidgetDescriptor(const char *arg0, MKWidgetDescriptor *arg1, MKWidget *(*arg3)(void), unsigned int arg4, unsigned int arg4) {
    this->unk0 = arg0;
    this->unk4 = arg4;
    this->unk8 = arg1;
    this->unk10 = arg2;
    this->unk14 = arg3;
    MKWidget_AddToDescriptorList(this);
    return this;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void MKWidget_AddToDescriptorList(MKWidgetDescriptor *arg0) {
    arg0->unkC = pDescriptorList;
    pDescriptorList = arg0;
}
#endif

#if 0 // DRAFT: undefined identifier 'sMKWidgetDescriptor'
void MKWidgetsInternal_cpp::__sinit() {
    f32 sp2F4;
    f32 sp2F0;
    f32 sp2EC;
    f32 sp2E8;
    f32 sp2E4;
    f32 sp2E0;
    f32 sp2DC;
    f32 sp2D8;
    f32 sp2D4;
    f32 sp2D0;
    f32 sp2CC;
    f32 sp2C8;
    f32 sp2C4;
    f32 sp2C0;
    f32 sp2BC;
    f32 sp2B8;
    f32 sp2B4;
    f32 sp2B0;
    f32 sp2AC;
    f32 sp2A8;
    f32 sp2A4;
    f32 sp2A0;
    f32 sp29C;
    f32 sp298;
    f32 sp294;
    f32 sp290;
    f32 sp28C;
    f32 sp288;
    f32 sp284;
    f32 sp280;
    f32 sp27C;
    f32 sp278;
    f32 sp274;
    f32 sp270;
    f32 sp26C;
    f32 sp268;
    f32 sp264;
    f32 sp260;
    f32 sp25C;
    f32 sp258;
    f32 sp254;
    f32 sp250;
    f32 sp24C;
    f32 sp248;
    f32 sp244;
    f32 sp240;
    f32 sp23C;
    f32 sp238;
    f32 sp234;
    f32 sp230;
    f32 sp22C;
    f32 sp228;
    f32 sp224;
    f32 sp220;
    f32 sp21C;
    f32 sp218;
    f32 sp214;
    f32 sp210;
    f32 sp20C;
    f32 sp208;
    f32 sp204;
    f32 sp200;
    f32 sp1FC;
    f32 sp1F8;
    f32 sp1F4;
    f32 sp1F0;
    f32 sp1EC;
    f32 sp1E8;
    f32 sp1E4;
    f32 sp1E0;
    f32 sp1DC;
    f32 sp1D8;
    f32 sp1D4;
    f32 sp1D0;
    f32 sp1CC;
    f32 sp1C8;
    f32 sp1C4;
    f32 sp1C0;
    f32 sp1BC;
    f32 sp1B8;
    f32 sp1B4;
    f32 sp1B0;
    f32 sp1AC;
    f32 sp1A8;
    f32 sp1A4;
    f32 sp1A0;
    f32 sp19C;
    f32 sp198;
    f32 sp194;
    f32 sp190;
    f32 sp18C;
    f32 sp188;
    f32 sp184;
    f32 sp180;
    f32 sp17C;
    f32 sp178;
    f32 sp174;
    f32 sp170;
    f32 sp16C;
    f32 sp168;
    f32 sp164;
    f32 sp160;
    f32 sp15C;
    f32 sp158;
    f32 sp154;
    f32 sp150;
    f32 sp14C;
    f32 sp148;
    f32 sp144;
    f32 sp140;
    f32 sp13C;
    f32 sp138;
    f32 sp134;
    f32 sp130;
    f32 sp12C;
    f32 sp128;
    f32 sp124;
    f32 sp120;
    f32 sp11C;
    f32 sp118;
    f32 sp114;
    f32 sp110;
    f32 sp10C;
    f32 sp108;
    f32 sp104;
    f32 sp100;
    f32 spFC;
    f32 spF8;
    f32 spF4;
    f32 spF0;
    f32 spEC;
    f32 spE8;
    f32 spE4;
    f32 spE0;
    f32 spDC;
    f32 spD8;
    f32 spD4;
    f32 spD0;
    f32 spCC;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
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
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    void *temp_r9_18755;

    sp2E8 = 1.0f;
    sp2EC = 1.0f;
    sp2F0 = 1.0f;
    sp2F4 = 1.0f;
    sp2D8 = 0.0f;
    sp2DC = 0.0f;
    sp2E0 = 0.0f;
    sp2E4 = 1.0f;
    sp2C8 = 0.7f;
    sp2CC = 0.7f;
    sp2D0 = 0.7f;
    sp2D4 = 1.0f;
    sp2B8 = 0.3f;
    sp2BC = 0.3f;
    sp2C0 = 0.3f;
    sp2C4 = 1.0f;
    sp2A8 = 0.0f;
    sp2AC = 0.0f;
    sp2B0 = 1.0f;
    sp2B4 = 1.0f;
    sp298 = 0.7f;
    sp29C = 0.7f;
    sp2A0 = 0.7f;
    sp2A4 = 1.0f;
    sp288 = 0.8f;
    sp28C = 0.8f;
    sp290 = 0.8f;
    sp294 = 1.0f;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0) = (f64) sp2E8;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 8) = (f64) sp2F0;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x10) = (f64) sp2D8;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x18) = (f64) sp2E0;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x20) = (f64) sp2C8;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x28) = (f64) sp2D0;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x30) = (f64) sp2B8;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x38) = (f64) sp2C0;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x40) = (f64) sp2A8;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x48) = (f64) sp2B0;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x50) = (f64) sp298;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x58) = (f64) sp2A0;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x60) = (f64) sp288;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x68) = (f64) sp290;
    sp278 = 0.6f;
    sp27C = 0.6f;
    sp280 = 0.6f;
    sp284 = 1.0f;
    sp268 = 0.7f;
    sp26C = 0.7f;
    sp270 = 0.7f;
    sp274 = 1.0f;
    sp258 = 0.5f;
    sp25C = 0.5f;
    sp260 = 0.5f;
    sp264 = 1.0f;
    sp248 = 0.5f;
    sp24C = 0.75f;
    sp250 = 1.0f;
    sp254 = 1.0f;
    sp238 = 0.2f;
    sp23C = 0.6f;
    sp240 = 1.0f;
    sp244 = 1.0f;
    sp228 = 0.0f;
    sp22C = 0.4f;
    sp230 = 0.85f;
    sp234 = 1.0f;
    sp218 = 0.0f;
    sp21C = 0.2f;
    sp220 = 0.65f;
    sp224 = 1.0f;
    sp208 = 0.4f;
    sp20C = 0.4f;
    sp210 = 0.4f;
    sp214 = 1.0f;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x70) = (f64) sp278;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x78) = (f64) sp280;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x80) = (f64) sp268;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x88) = (f64) sp270;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x90) = (f64) sp258;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x98) = (f64) sp260;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0xA0) = (f64) sp248;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0xA8) = (f64) sp250;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0xB0) = (f64) sp238;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0xB8) = (f64) sp240;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0xC0) = (f64) sp228;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0xC8) = (f64) sp230;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0xD0) = (f64) sp218;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0xD8) = (f64) sp220;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0xE0) = (f64) sp208;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0xE8) = (f64) sp210;
    sp1F8 = 0.4f;
    sp1FC = 0.4f;
    sp200 = 0.4f;
    sp204 = 1.0f;
    sp1E8 = 0.4f;
    sp1EC = 0.4f;
    sp1F0 = 0.4f;
    sp1F4 = 1.0f;
    sp1D8 = 0.4f;
    sp1DC = 0.4f;
    sp1E0 = 0.4f;
    sp1E4 = 1.0f;
    sp1C8 = 2.0f;
    sp1CC = 0.0f;
    sp1D0 = 0.0f;
    sp1D4 = 0.0f;
    sp1B8 = 1.0f;
    sp1BC = 0.0f;
    sp1C0 = 0.0f;
    sp1C4 = 0.0f;
    sp1A8 = 20.0f;
    sp1AC = 0.0f;
    sp1B0 = 0.0f;
    sp1B4 = 0.0f;
    sp198 = 16.0f;
    sp19C = 0.0f;
    sp1A0 = 0.0f;
    sp1A4 = 0.0f;
    sp188 = 0.7f;
    sp18C = 0.7f;
    sp190 = 0.7f;
    sp194 = 1.0f;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0xF0) = (f64) sp1F8;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0xF8) = (f64) sp200;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x100) = (f64) sp1E8;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x108) = (f64) sp1F0;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x110) = (f64) sp1D8;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x118) = (f64) sp1E0;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x120) = (f64) sp1C8;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x128) = (f64) sp1D0;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x130) = (f64) sp1B8;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x138) = (f64) sp1C0;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x140) = (f64) sp1A8;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x148) = (f64) sp1B0;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x150) = (f64) sp198;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x158) = (f64) sp1A0;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x160) = (f64) sp188;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x168) = (f64) sp190;
    sp178 = 0.7f;
    sp17C = 0.7f;
    sp180 = 0.7f;
    sp184 = 1.0f;
    sp168 = 0.7f;
    sp16C = 0.7f;
    sp170 = 0.7f;
    sp174 = 1.0f;
    sp158 = 0.7f;
    sp15C = 0.7f;
    sp160 = 0.7f;
    sp164 = 1.0f;
    sp148 = 0.8f;
    sp14C = 0.8f;
    sp150 = 0.8f;
    sp154 = 1.0f;
    sp138 = 0.6f;
    sp13C = 0.6f;
    sp140 = 0.6f;
    sp144 = 1.0f;
    sp128 = 0.7f;
    sp12C = 0.7f;
    sp130 = 0.7f;
    sp134 = 1.0f;
    sp118 = 0.5f;
    sp11C = 0.5f;
    sp120 = 0.5f;
    sp124 = 1.0f;
    sp108 = 0.9f;
    sp10C = 0.9f;
    sp110 = 0.9f;
    sp114 = 1.0f;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x170) = (f64) sp178;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x178) = (f64) sp180;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x180) = (f64) sp168;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x188) = (f64) sp170;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x190) = (f64) sp158;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x198) = (f64) sp160;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x1A0) = (f64) sp148;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x1A8) = (f64) sp150;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x1B0) = (f64) sp138;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x1B8) = (f64) sp140;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x1C0) = (f64) sp128;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x1C8) = (f64) sp130;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x1D0) = (f64) sp118;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x1D8) = (f64) sp120;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x1E0) = (f64) sp108;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x1E8) = (f64) sp110;
    spF8 = 0.9f;
    spFC = 0.9f;
    sp100 = 0.9f;
    sp104 = 1.0f;
    spE8 = 0.9f;
    spEC = 0.9f;
    spF0 = 0.9f;
    spF4 = 1.0f;
    spD8 = 0.9f;
    spDC = 0.9f;
    spE0 = 0.9f;
    spE4 = 1.0f;
    spC8 = 0.7f;
    spCC = 0.7f;
    spD0 = 0.7f;
    spD4 = 1.0f;
    spB8 = 0.7f;
    spBC = 0.7f;
    spC0 = 0.7f;
    spC4 = 1.0f;
    spA8 = 0.7f;
    spAC = 0.7f;
    spB0 = 0.7f;
    spB4 = 1.0f;
    sp98 = 0.7f;
    sp9C = 0.7f;
    spA0 = 0.7f;
    spA4 = 1.0f;
    sp88 = 0.0f;
    sp8C = 1.0f;
    sp90 = 0.0f;
    sp94 = 0.6f;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x1F0) = (f64) spF8;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x1F8) = (f64) sp100;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x200) = (f64) spE8;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x208) = (f64) spF0;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x210) = (f64) spD8;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x218) = (f64) spE0;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x220) = (f64) spC8;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x228) = (f64) spD0;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x230) = (f64) spB8;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x238) = (f64) spC0;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x240) = (f64) spA8;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x248) = (f64) spB0;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x250) = (f64) sp98;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x258) = (f64) spA0;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x260) = (f64) sp88;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x268) = (f64) sp90;
    sp78 = 0.0f;
    sp7C = 0.8f;
    temp_r9_18755 = &gMKWidgetMetrics + 0x2E0;
    sp80 = 0.0f;
    sp84 = 0.7f;
    sp68 = 0.0f;
    sp6C = 0.4f;
    sp70 = 0.0f;
    sp74 = 0.9f;
    sp58 = 0.0f;
    sp5C = 0.2f;
    sp60 = 0.0f;
    sp64 = 1.0f;
    sp48 = 0.0f;
    sp4C = 0.0f;
    sp50 = 0.0f;
    sp54 = 0.7f;
    sp38 = 0.0f;
    sp3C = 0.0f;
    sp40 = 0.0f;
    sp44 = 0.7f;
    sp28 = 0.0f;
    sp2C = 0.0f;
    sp30 = 0.0f;
    sp34 = 0.7f;
    sp18 = 0.0f;
    sp1C = 0.0f;
    sp20 = 0.0f;
    sp24 = 0.7f;
    sp8 = 1.0f;
    spC = 1.0f;
    sp10 = 1.0f;
    sp14 = 1.0f;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x270) = (f64) sp78;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x278) = (f64) sp80;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x280) = (f64) sp68;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x288) = (f64) sp70;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x290) = (f64) sp58;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x298) = (f64) sp60;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x2A0) = (f64) sp48;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x2A8) = (f64) sp50;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x2B0) = (f64) sp38;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x2B8) = (f64) sp40;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x2C0) = (f64) sp28;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x2C8) = (f64) sp30;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x2D0) = (f64) sp18;
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x2D8) = (f64) sp20;
    M2C_FIELD(temp_r9_18755, f64 *, 0x40) = (f64) sp8;
    M2C_FIELD(temp_r9_18755, f64 *, 0x48) = (f64) sp10;
    sMKWidgetDescriptor.MKWidgetDescriptor("", NULL, (MKWidget *(*)()) &MKWidget::MKWidget_FactoryFunc, 1U, 0x68U);
    sMKWidgetContainerDescriptor.MKWidgetDescriptor("MKWidgetContainer", (MKWidgetDescriptor *) &sMKWidgetDescriptor, (MKWidget *(*)()) &MKWidgetContainer::MKWidgetContainer_FactoryFunc, 0U, 0x68U);
    sMKWidgetSystemDescriptor.MKWidgetDescriptor("", (MKWidgetDescriptor *) &sMKWidgetContainerDescriptor, (MKWidget *(*)()) &MKWidgetSystem::MKWidgetSystem_FactoryFunc, 1U, 0x68U);
    sMKWidgetFrameDescriptor.MKWidgetDescriptor("", (MKWidgetDescriptor *) &sMKWidgetContainerDescriptor, (MKWidget *(*)()) &MKWidgetFrame::MKWidgetFrame_FactoryFunc, 0U, 0x80U);
    sMKWidgetScrollableFrameDescriptor.MKWidgetDescriptor("", (MKWidgetDescriptor *) &sMKWidgetFrameDescriptor, (MKWidget *(*)()) &MKWidgetScrollableFrame::MKWidgetScrollableFrame_FactoryFunc, 0U, 0x80U);
    sMKWidgetListBoxDescriptor.MKWidgetDescriptor("", (MKWidgetDescriptor *) &sMKWidgetScrollableFrameDescriptor, (MKWidget *(*)()) &MKWidgetListBox::MKWidgetListBox_FactoryFunc, 0U, 0x88U);
    sMKWidgetWindowDescriptor.MKWidgetDescriptor("", (MKWidgetDescriptor *) &sMKWidgetFrameDescriptor, (MKWidget *(*)()) &MKWidgetWindow::MKWidgetWindow_FactoryFunc, 0U, 0x88U);
    sMKWidgetTabStripDescriptor.MKWidgetDescriptor("", (MKWidgetDescriptor *) &sMKWidgetContainerDescriptor, (MKWidget *(*)()) &MKWidgetTabStrip::MKWidgetTabStrip_FactoryFunc, 0U, 0x68U);
    sMKWidgetFoldupFrameDescriptor.MKWidgetDescriptor("", (MKWidgetDescriptor *) &sMKWidgetFrameDescriptor, (MKWidget *(*)()) &MKWidgetFoldupFrame::MKWidgetFoldupFrame_FactoryFunc, 0U, 0x88U);
    sMKWidgetStringDescriptor.MKWidgetDescriptor("", (MKWidgetDescriptor *) &sMKWidgetDescriptor, (MKWidget *(*)()) &MKWidgetString::MKWidgetString_FactoryFunc, 0U, 0x78U);
    sMKWidgetImageDescriptor.MKWidgetDescriptor("", (MKWidgetDescriptor *) &sMKWidgetDescriptor, (MKWidget *(*)()) &MKWidgetImage::MKWidgetImage_FactoryFunc, 0U, 0x68U);
    sMKWidgetButtonDescriptor.MKWidgetDescriptor("", (MKWidgetDescriptor *) &sMKWidgetDescriptor, (MKWidget *(*)()) &MKWidgetButton::MKWidgetButton_FactoryFunc, 0U, 0x68U);
    sMKWidgetCheckMarkDescriptor.MKWidgetDescriptor("", (MKWidgetDescriptor *) &sMKWidgetDescriptor, (MKWidget *(*)()) &MKWidgetCheckMark::MKWidgetCheckMark_FactoryFunc, 0U, 0x70U);
    sMKWidgetCheckBoxDescriptor.MKWidgetDescriptor("", (MKWidgetDescriptor *) &sMKWidgetDescriptor, (MKWidget *(*)()) &MKWidgetCheckBox::MKWidgetCheckBox_FactoryFunc, 0U, 0x80U);
    sMKWidgetScrollBarDescriptor.MKWidgetDescriptor("", (MKWidgetDescriptor *) &sMKWidgetDescriptor, (MKWidget *(*)()) &MKWidgetScrollBar::MKWidgetScrollBar_FactoryFunc, 0U, 0x80U);
    sMKWidgetTextBoxDescriptor.MKWidgetDescriptor("", (MKWidgetDescriptor *) &sMKWidgetDescriptor, (MKWidget *(*)()) &MKWidgetTextBox::MKWidgetTextBox_FactoryFunc, 0U, 0x88U);
    sMKWidgetVectorDescriptor.MKWidgetDescriptor("", (MKWidgetDescriptor *) &sMKWidgetDescriptor, (MKWidget *(*)()) &MKWidgetVector::MKWidgetVector_FactoryFunc, 0U, 0x80U);
    sMKWidgetEnvelopeDescriptor.MKWidgetDescriptor("", (MKWidgetDescriptor *) &sMKWidgetDescriptor, (MKWidget *(*)()) &MKWidgetEnvelope::MKWidgetEnvelope_FactoryFunc, 0U, 0xF0U);
    sMKWidgetListItemDescriptor.MKWidgetDescriptor("", (MKWidgetDescriptor *) &sMKWidgetDescriptor, (MKWidget *(*)()) &MKWidgetListItem::MKWidgetListItem_FactoryFunc, 0U, 0x68U);
    sMKWidgetSliderDescriptor.MKWidgetDescriptor("", (MKWidgetDescriptor *) &sMKWidgetScrollBarDescriptor, (MKWidget *(*)()) &MKWidgetSlider::MKWidgetSlider_FactoryFunc, 0U, 0x80U);
    sMKWidgetColorDescriptor.MKWidgetDescriptor("", (MKWidgetDescriptor *) &sMKWidgetDescriptor, (MKWidget *(*)()) &MKWidgetColor::MKWidgetColor_FactoryFunc, 0U, 0x78U);
    sMKWidgetComboBoxDescriptor.MKWidgetDescriptor("", (MKWidgetDescriptor *) &sMKWidgetDescriptor, (MKWidget *(*)()) &MKWidgetComboBox::MKWidgetComboBox_FactoryFunc, 0U, 0x70U);
    sMKWidgetThumbDescriptor.MKWidgetDescriptor("", (MKWidgetDescriptor *) &sMKWidgetDescriptor, (MKWidget *(*)()) &MKWidgetThumb::MKWidgetThumb_FactoryFunc, 2U, 0x80U);
    sMKWidgetWindowTitleBarDescriptor.MKWidgetDescriptor("", (MKWidgetDescriptor *) &sMKWidgetDescriptor, (MKWidget *(*)()) &MKWidgetWindowTitleBar::MKWidgetWindowTitleBar_FactoryFunc, 2U, 0x68U);
    sMKWidgetEditableDescriptor.MKWidgetDescriptor("", (MKWidgetDescriptor *) &sMKWidgetContainerDescriptor, (MKWidget *(*)()) &MKWidgetEditable::MKWidgetEditable_FactoryFunc, 1U, 0x68U);
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x330) = (f64) M2C_FIELD(&zero, f64 *, 0);
    M2C_FIELD(&gMKWidgetMetrics, f64 *, 0x338) = (f64) M2C_FIELD(&zero, f64 *, 8);
}
#endif
