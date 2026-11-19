#include "spyro/source/PropGroupVolume.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/BoundingRegion.h"
#include "unplaced_templates.h"
#include "common/Source/system_extras.h"
#include <m2c_macros.h>

s32 stricmp(s8 *, s8 *);                            /* extern */
extern void **gMK;
extern M2C_UNK gb;
extern s32 zoneDisableMask;
PropGroupVolume overlay__15PropGroupVolume;
static s32 zoneEnableMask = 1;

#if 0 // DRAFT: function call 'strnicmp(signed char *, const char[8], int)' does not match
u8 PropGroupVolume::LoadOverlayName(MKIniLine *arg0) {
    s8 *sp8;
    s32 temp_r28_128;
    s32 var_ctr_118;
    s32 var_r29_76;
    s32 var_r31_116;
    s32 var_r31_72;
    s32 var_r3_117;
    void *temp_r4_93;

    if (strnicmp(arg0->GetFieldName(), "overlay", 7) == 0) {
        arg0->AsString(0, &sp8);
        if (stricmp(sp8, "none") == 0) {
            return 1U;
        }
        var_r31_72 = 0;
        var_r29_76 = 0;
        M2C_FIELD((this + (this->unk2A4 * 4)), s32 *, 0xA4) = -1;
loop_8:
        if (var_r31_72 < (s32) *PropGroupVolume::overlayCount) {
            if (((s32) M2C_FIELD((&PropGroupVolume::overlay + var_r29_76), s32 *, 0x24) > 0) && (stricmp(sp8) == 0)) {
                temp_r4_93 = &PropGroupVolume::overlay + var_r29_76;
                M2C_FIELD((this + (this->unk2A4 * 4)), s32 *, 0xA4) = var_r31_72;
                M2C_FIELD(temp_r4_93, s32 *, 0x24) = (s32) (M2C_FIELD(temp_r4_93, s32 *, 0x24) + 1);
            } else {
                var_r31_72 += 1;
                var_r29_76 += 0x28;
                goto loop_8;
            }
        }
        if ((s32) M2C_FIELD((this + (this->unk2A4 * 4)), s32 *, 0xA4) < 0) {
            var_r31_116 = 0;
            var_r3_117 = 0;
            var_ctr_118 = 0x80;
loop_11:
            if ((s32) M2C_FIELD((&PropGroupVolume::overlay + var_r3_117), s32 *, 0x24) != 0) {
                var_r31_116 += 1;
                var_r3_117 += 0x28;
                var_ctr_118 -= 1;
                if (var_ctr_118 != 0) {
                    goto loop_11;
                }
            }
            temp_r28_128 = var_r31_116 * 0x28;
            strcpy(&PropGroupVolume::overlay + temp_r28_128, sp8);
            M2C_FIELD((&PropGroupVolume::overlay + temp_r28_128), s32 *, 0x24) = 1;
            M2C_FIELD((this + (this->unk2A4 * 4)), s32 *, 0xA4) = var_r31_116;
            if (var_r31_116 == (s32) *PropGroupVolume::overlayCount) {
                *PropGroupVolume::overlayCount += 1;
            }
        }
        this->unk2A4 += 1;
        return 1U;
    }
    return 0U;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char' to
void PropGroupVolume::CullGroups(const MKVector3 &arg0) {
    f32 temp_f0_286;
    f32 temp_f1_241;
    f32 var_f31_187;
    s32 temp_r0_275;
    s32 var_ctr_208;
    s32 var_r26_322;
    s32 var_r27_324;
    s32 var_r30_218;
    s32 var_r3_204;
    s32 var_r3_270;
    s32 var_r7_269;
    u8 var_r26_242;
    u8 var_r31_186;
    void *temp_r4_212;
    void *temp_r4_278;
    void *temp_r4_328;
    void *var_r28_235;
    void *var_r29_230;
    void *var_r4_217;
    void *var_r4_301;

    if ((s32) M2C_FIELD(&gb, s32 *, 0x340) == 0) {
        zoneEnableMask = 1;
        zoneDisableMask = 0;
        var_r31_186 = 0;
        var_f31_187 = 1.0f;
        M2C_FIELD(*gMK, M2C_UNK (**)(void **, M2C_UNK, M2C_UNK, M2C_UNK), 0xA4)(gMK, 0x7FFFFFFF, 0, -1);
        M2C_FIELD(*gMK, M2C_UNK (**)(void **, M2C_UNK, M2C_UNK, M2C_UNK), 0xA8)(gMK, 0x7FFFFFFF, 0, -1);
        var_r3_204 = 0;
        var_ctr_208 = *PropGroupVolume::overlayCount;
        if ((s32) *PropGroupVolume::overlayCount > 0) {
            do {
                temp_r4_212 = &PropGroupVolume::overlay + var_r3_204;
                var_r3_204 += 0x28;
                M2C_FIELD(temp_r4_212, s8 *, 0x20) = 0;
                var_ctr_208 -= 1;
            } while (var_ctr_208 != 0);
        }
        var_r4_217 = *PropGroupVolumeDescriptor::pFirstDesc;
        var_r30_218 = 0;
loop_5:
        if ((var_r4_217 != NULL) && !(M2C_FIELD(M2C_FIELD(var_r4_217, void **, 0x60), s32 *, 0x138) & 2)) {
            var_r4_217 = M2C_FIELD(var_r4_217, void **, 0x68);
            goto loop_5;
        }
        var_r29_230 = var_r4_217;
loop_29:
        if (var_r29_230 != NULL) {
            var_r28_235 = checked_cast<PropGroupVolume *, MKProp>(M2C_FIELD(var_r29_230, MKProp **, 0x28));
loop_23:
            if (var_r28_235 != NULL) {
                if (!(M2C_FIELD(var_r28_235, s32 *, 0x18) & 0x80000000)) {
                    temp_f1_241 = M2C_BITWISE(f32, this->unk4);
                    var_r26_242 = 0;
                    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
                    var_r30_218 += 1;
                    if (temp_f1_241 == M2C_FIELD(var_r28_235, f32 *, 0x70)) {
                        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                        if ((temp_f1_241 == M2C_FIELD(var_r28_235, f32 *, 0x74)) && (((BoundingRegion *) (var_r28_235 + 0x54))->IsPointWithin(*((MKVector3 *) this)) != 0)) {
                            var_r26_242 = 1;
                        }
                    }
                    if (var_r26_242 != 0) {
                        zoneEnableMask |= M2C_FIELD(var_r28_235, s32 *, 0xA0);
                    }
                    var_r7_269 = 0;
                    var_r3_270 = 0;
loop_18:
                    if (var_r7_269 < (s32) M2C_FIELD(var_r28_235, s32 *, 0x2A4)) {
                        var_r7_269 += 1;
                        temp_r0_275 = *(var_r28_235 + (var_r3_270 + 0xA4));
                        var_r3_270 += 4;
                        temp_r4_278 = &PropGroupVolume::overlay + (temp_r0_275 * 0x28);
                        M2C_FIELD(temp_r4_278, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r4_278, u8 *, 0x20) | var_r26_242);
                        goto loop_18;
                    }
                    temp_f0_286 = M2C_FIELD(var_r28_235, f32 *, 0x2A8);
                    if (temp_f0_286 > var_f31_187) {
                        var_f31_187 = temp_f0_286;
                    }
                    var_r31_186 |= M2C_FIELD(var_r28_235, u8 *, 0x2AC);
                }
                var_r28_235 = checked_cast<PropGroupVolume *, MKProp>(M2C_FIELD(var_r28_235, MKProp **, 0x38));
                goto loop_23;
            }
            var_r4_301 = M2C_FIELD(var_r29_230, void **, 0x68);
loop_26:
            if ((var_r4_301 != NULL) && !(M2C_FIELD(M2C_FIELD(var_r4_301, void **, 0x60), s32 *, 0x138) & 2)) {
                var_r4_301 = M2C_FIELD(var_r4_301, void **, 0x68);
                goto loop_26;
            }
            var_r29_230 = var_r4_301;
            goto loop_29;
        }
        if (var_r30_218 == 0) {
            var_r31_186 = 1;
        }
        var_r26_322 = 0;
        var_r27_324 = 0;
loop_34:
        if (var_r26_322 < (s32) *PropGroupVolume::overlayCount) {
            temp_r4_328 = &PropGroupVolume::overlay + var_r27_324;
            M2C_FIELD(*gMK, M2C_UNK (**)(void **, void *, u8), 0x88)(gMK, temp_r4_328, M2C_FIELD(temp_r4_328, u8 *, 0x20));
            var_r26_322 += 1;
            var_r27_324 += 0x28;
            goto loop_34;
        }
        M2C_FIELD(*gMK, M2C_UNK (**)(void **, s32, M2C_UNK, M2C_UNK), 0xA4)(gMK, zoneEnableMask, 1, -1);
        M2C_FIELD(*gMK, M2C_UNK (**)(void **, s32, M2C_UNK, M2C_UNK), 0xA8)(gMK, zoneDisableMask, 1, -1);
        M2C_FIELD(M2C_FIELD(&gb, void **, 0x32C), f32 *, 0x2C) = var_f31_187;
        M2C_FIELD(M2C_FIELD(&gb, void **, 0x32C), u8 *, 0x28) = var_r31_186;
    }
}
#endif

void PropGroupVolume::Reset() {
    MKProp::Reset();
    if ((u8) this->unk2AD != 0) {
        Enable();
        return;
    }
    Disable();
}

void PropGroupVolume::LoadDone() {
    MKProp::LoadDone();
    if ((u8) this->unk2AD != 0) {
        Enable();
        return;
    }
    Disable();
}

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
s32 PropGroupVolume::LoadLine(MKIniLine *arg0) {
    s32 var_r31_445;

    var_r31_445 = 0;
    if ((MKProp::LoadLine(arg0) != 0) || (arg0->LoadInt("enableZone", (s32 *) &this->unk50.unk48, 0) != 0) || (this->unk50.LoadLine("region", arg0) != 0) || (arg0->LoadFloat("distanceMultiplier", &this->unk2A8, 0) != 0) || (arg0->LoadBool("bShowEnvDome", &this->unk2AC, 0) != 0) || (arg0->LoadBool("bEnabled", &this->unk2AD, 0) != 0) || (LoadOverlayName(arg0) != 0)) {
        var_r31_445 = 1;
    }
    return var_r31_445;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'PropGroupVolume' to
void PropGroupVolume::Deinit() {
    s32 temp_r0_527;
    s32 var_r3_522;
    s32 var_r7_520;
    void *temp_r5_530;

    this->unk50.Deinit();
    var_r7_520 = 0;
    var_r3_522 = 0;
loop_2:
    if (var_r7_520 < (s32) this->unk2A4) {
        var_r7_520 += 1;
        temp_r0_527 = *(this + (var_r3_522 + 0xA4));
        var_r3_522 += 4;
        temp_r5_530 = &PropGroupVolume::overlay + (temp_r0_527 * 0x28);
        M2C_FIELD(temp_r5_530, s32 *, 0x24) = (s32) (M2C_FIELD(temp_r5_530, s32 *, 0x24) - 1);
        goto loop_2;
    }
    MKProp::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'nanf'
void PropGroupVolume::Init() {
    MKProp::Init();
    this->unk50.Init();
    this->unk2A4 = 0;
    this->unk2A8 = 1.0f;
    this->unk2AC = 1;
    this->unk2AD = 1;
    this->unk50.unk48 = nanf;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'PropGroupVolumeDescriptor *' to
void PropGroupVolumeDescriptor::Deinit() {
    PropGroupVolumeDescriptor *temp_r4_586;
    PropGroupVolumeDescriptor *temp_r4_592;

    if ((PropGroupVolumeDescriptor *) *PropGroupVolumeDescriptor::pFirstDesc == this) {
        *PropGroupVolumeDescriptor::pFirstDesc = this->unk68;
    }
    temp_r4_586 = this->unk64;
    if (temp_r4_586 != NULL) {
        temp_r4_586->unk68 = this->unk68;
    }
    temp_r4_592 = this->unk68;
    if (temp_r4_592 != NULL) {
        temp_r4_592->unk64 = this->unk64;
    }
    this->unk64 = NULL;
    this->unk68 = NULL;
    this->unk60 = NULL;
    MKPropDescriptor::Deinit();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char' to
void PropGroupVolumeDescriptor::Init() {
    MKPropDescriptor::Init();
    this->unk68 = *PropGroupVolumeDescriptor::pFirstDesc;
    this->unk64 = NULL;
    if ((PropGroupVolumeDescriptor *) *PropGroupVolumeDescriptor::pFirstDesc != NULL) {
        (*PropGroupVolumeDescriptor::pFirstDesc)->unk64 = this;
    }
    *PropGroupVolumeDescriptor::pFirstDesc = this;
    this->unk60 = M2C_FIELD(*gMK, void *(**)(void **), 0x7C)(gMK);
}
#endif
