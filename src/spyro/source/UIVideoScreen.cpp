#include "spyro/source/UIVideoScreen.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/GameVideo.h"
#include "spyro/source/UIAttributes.h"
#include "spyro/source/UIContainer.h"
#include "spyro/source/UIMessage.h"
#include "spyro/source/UIObject.h"
#include "spyro/source/UIScreen.h"
#include "unplaced_enums.h"
#include "common/Source/MKInput.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/UIControls.h"
#include "spyro/source/UIStringTable.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;
extern M2C_UNK gb;

void UIVideoScreen::Draw(const RenderContext &arg0) {
    GameVideo_Draw(this->unkE4);
    UIContainer::Draw(arg0);
    if (this->unkEC > 0.0f) {
        MKMaterial_SetMaterial(M2C_FIELD(&gb, MKMaterial **, 0x328));
        MKSetBaseColorF(1.0f, 1.0f, 1.0f, 1.0f);
        MKPrimitive(0xC, 3);
        MKSetMatrix(Matrix::identity);
        MKBegin(4);
        MKSetColorF(0.0f, 0.0f, 0.0f, this->unkEC);
        MKSetPositionF(-108.0f, 0.0f, 0.0f);
        MKSetPositionF(748.0f, 0.0f, 0.0f);
        MKSetPositionF(-108.0f, 512.0f, 0.0f);
        MKSetPositionF(748.0f, 512.0f, 0.0f);
        MKEnd();
        MKEndPrimitive();
    }
}

void UIVideoScreen::Update() {
    GameVideo *temp_r3_341;
    f32 temp_f1_276;
    f32 temp_f1_286;
    f32 temp_f1_308;
    f32 temp_f1_344;
    f32 temp_f2_277;
    f32 temp_f2_294;
    s32 var_r3_100;
    s32 var_r3_123;
    s32 var_r3_146;
    s32 var_r3_169;
    s32 var_r3_192;
    s32 var_r3_215;
    s32 var_r3_238;
    s32 var_r3_261;
    u8 var_r4_112;
    u8 var_r4_135;
    u8 var_r4_158;
    u8 var_r4_181;
    u8 var_r4_204;
    u8 var_r4_227;
    u8 var_r4_250;
    u8 var_r4_89;
    void *temp_r3_110;
    void *temp_r3_133;
    void *temp_r3_156;
    void *temp_r3_179;
    void *temp_r3_202;
    void *temp_r3_225;
    void *temp_r3_248;
    void *temp_r3_87;

    UIScreen::Update();
    if ((u8) this->unkFB == 0) {
        temp_r3_87 = UIInput(-1);
        var_r4_89 = 0;
        if (((u8) M2C_FIELD(temp_r3_87, u8 *, 5) != 0) || ((u8) M2C_FIELD(temp_r3_87, u8 *, 4) != 0)) {
            var_r4_89 = 1;
        }
        if (var_r4_89 != 0) {
            var_r3_100 = 0;
        } else {
            var_r3_100 = MKInput_Pressed(0xF, (MKInputDevices) M2C_FIELD(temp_r3_87, s32 *, 0));
        }
        if ((u8) var_r3_100 == 0) {
            temp_r3_110 = UIInput(-1);
            var_r4_112 = 0;
            if (((u8) M2C_FIELD(temp_r3_110, u8 *, 5) != 0) || ((u8) M2C_FIELD(temp_r3_110, u8 *, 4) != 0)) {
                var_r4_112 = 1;
            }
            if (var_r4_112 != 0) {
                var_r3_123 = 0;
            } else {
                var_r3_123 = MKInput_Pressed(0xE, (MKInputDevices) M2C_FIELD(temp_r3_110, s32 *, 0));
            }
            if ((u8) var_r3_123 == 0) {
                temp_r3_133 = UIInput(-1);
                var_r4_135 = 0;
                if (((u8) M2C_FIELD(temp_r3_133, u8 *, 5) != 0) || ((u8) M2C_FIELD(temp_r3_133, u8 *, 4) != 0)) {
                    var_r4_135 = 1;
                }
                if (var_r4_135 != 0) {
                    var_r3_146 = 0;
                } else {
                    var_r3_146 = MKInput_Pressed(0xC, (MKInputDevices) M2C_FIELD(temp_r3_133, s32 *, 0));
                }
                if ((u8) var_r3_146 == 0) {
                    temp_r3_156 = UIInput(-1);
                    var_r4_158 = 0;
                    if (((u8) M2C_FIELD(temp_r3_156, u8 *, 5) != 0) || ((u8) M2C_FIELD(temp_r3_156, u8 *, 4) != 0)) {
                        var_r4_158 = 1;
                    }
                    if (var_r4_158 != 0) {
                        var_r3_169 = 0;
                    } else {
                        var_r3_169 = MKInput_Pressed(0xD, (MKInputDevices) M2C_FIELD(temp_r3_156, s32 *, 0));
                    }
                    if ((u8) var_r3_169 == 0) {
                        temp_r3_179 = UIInput(-1);
                        var_r4_181 = 0;
                        if (((u8) M2C_FIELD(temp_r3_179, u8 *, 5) != 0) || ((u8) M2C_FIELD(temp_r3_179, u8 *, 4) != 0)) {
                            var_r4_181 = 1;
                        }
                        if (var_r4_181 != 0) {
                            var_r3_192 = 0;
                        } else {
                            var_r3_192 = MKInput_Pressed(3, (MKInputDevices) M2C_FIELD(temp_r3_179, s32 *, 0));
                        }
                        if ((u8) var_r3_192 == 0) {
                            temp_r3_202 = UIInput(-1);
                            var_r4_204 = 0;
                            if (((u8) M2C_FIELD(temp_r3_202, u8 *, 5) != 0) || ((u8) M2C_FIELD(temp_r3_202, u8 *, 4) != 0)) {
                                var_r4_204 = 1;
                            }
                            if (var_r4_204 != 0) {
                                var_r3_215 = 0;
                            } else {
                                var_r3_215 = MKInput_Pressed(0xA, (MKInputDevices) M2C_FIELD(temp_r3_202, s32 *, 0));
                            }
                            if ((u8) var_r3_215 == 0) {
                                temp_r3_225 = UIInput(-1);
                                var_r4_227 = 0;
                                if (((u8) M2C_FIELD(temp_r3_225, u8 *, 5) != 0) || ((u8) M2C_FIELD(temp_r3_225, u8 *, 4) != 0)) {
                                    var_r4_227 = 1;
                                }
                                if (var_r4_227 != 0) {
                                    var_r3_238 = 0;
                                } else {
                                    var_r3_238 = MKInput_Pressed(0xB, (MKInputDevices) M2C_FIELD(temp_r3_225, s32 *, 0));
                                }
                                if ((u8) var_r3_238 == 0) {
                                    temp_r3_248 = UIInput(-1);
                                    var_r4_250 = 0;
                                    if (((u8) M2C_FIELD(temp_r3_248, u8 *, 5) != 0) || ((u8) M2C_FIELD(temp_r3_248, u8 *, 4) != 0)) {
                                        var_r4_250 = 1;
                                    }
                                    if (var_r4_250 != 0) {
                                        var_r3_261 = 0;
                                    } else {
                                        var_r3_261 = MKInput_Pressed(9, (MKInputDevices) M2C_FIELD(temp_r3_248, s32 *, 0));
                                    }
                                    if ((u8) var_r3_261 != 0) {
                                        goto block_57;
                                    }
                                } else {
                                    goto block_57;
                                }
                            } else {
                                goto block_57;
                            }
                        } else {
                            goto block_57;
                        }
                    } else {
                        goto block_57;
                    }
                } else {
                    goto block_57;
                }
            } else {
                goto block_57;
            }
        } else {
block_57:
            this->unkFB = 1;
            ((UIEvent *) &this->unkD4)->Send();
        }
    }
    temp_f1_276 = this->unkE8;
    temp_f2_277 = this->unkEC;
    if (temp_f1_276 > temp_f2_277) {
        this->unkEC = temp_f2_277 + (gUpdateTimeDelta / 0.5f);
        temp_f1_286 = this->unkE8;
        if (this->unkEC > temp_f1_286) {
            this->unkEC = temp_f1_286;
        }
        temp_f2_294 = 1.0f - this->unkEC;
        KDSound_SetMasterVolume(temp_f2_294 * this->unk100, temp_f2_294 * this->unkFC);
        goto block_69;
    }
    if (temp_f1_276 < temp_f2_277) {
        this->unkEC = temp_f2_277 - (gUpdateTimeDelta / 0.5f);
        temp_f1_308 = this->unkE8;
        if (this->unkEC < temp_f1_308) {
            this->unkEC = temp_f1_308;
        }
        goto block_69;
    }
    if ((temp_f1_276 == 1.0f) && (temp_f2_277 == temp_f1_276)) {
        this->unkF0 += 1;
        if ((s32) this->unkF0 >= 3) {
            GameVideo_Destroy(this->unkE4);
            KDSound_SetMasterVolume(this->unk100, this->unkFC);
            this->unkE4 = NULL;
            UIScreen::OnExit();
            DoExit();
            return;
        }
    }
block_69:
    temp_r3_341 = this->unkE4;
    if (temp_r3_341 != NULL) {
        temp_f1_344 = GameVideo_GetRemainingTime(temp_r3_341);
        if (((u8) this->unkF5 != 0) && (this->unkE8 <= this->unkEC) && (temp_f1_344 >= 0.0f) && (temp_f1_344 <= 0.5f) && ((u8) this->unkFB == 0)) {
            ((UIEvent *) &this->unkC8)->Send();
        }
        if ((GameVideo_Update(this->unkE4) == 0) && (((u8) this->unkF5 == 0) || (this->unkE8 != 1.0f))) {
            ((UIEvent *) &this->unkC8)->Send();
        }
    } else if (((u8) this->unkF5 == 0) || (this->unkE8 != 1.0f)) {
        ((UIEvent *) &this->unkC8)->Send();
    }
}

void UIVideoScreen::OnExit() {
    if ((u8) this->unkF5 != 0) {
        this->unk100 = KDSound_GetMasterSoundVolume();
        this->unkFC = KDSound_GetMasterMusicVolume();
        this->unkE8 = 1.0f;
        return;
    }
    GameVideo_Destroy(this->unkE4);
    M2C_FIELD(&gb, s8 *, 9) = 1;
    UIScreen::OnExit();
    DoExit();
}

#if 0 // DRAFT: function call 'GameVideo_Create(signed char *, long, long)' does not match
void UIVideoScreen::OnEnter() {
    f32 var_f0_480;
    s32 temp_r0_461;
    s32 temp_r3_457;
    u8 var_r3_469;

    UIScreen::OnEnter();
    M2C_FIELD(&gb, s8 *, 9) = 0;
    temp_r3_457 = 0 - this->unkFA;
    temp_r0_461 = 0 - this->unkF9;
    this->unkE4 = GameVideo_Create(this->unkE0, (this->unkF8 != 0) | (2 & ((temp_r0_461 - temp_r0_461) - !M2C_CARRY)), (temp_r3_457 - temp_r3_457) - !M2C_CARRY);
    var_r3_469 = 0;
    if (((u8) this->unkF4 != 0) && ((GameVideo *) this->unkE4 != NULL)) {
        var_r3_469 = 1;
    }
    if (var_r3_469 != 0) {
        var_f0_480 = 1.0f;
    } else {
        var_f0_480 = 0.0f;
    }
    this->unkEC = var_f0_480;
    this->unkE8 = 0.0f;
    this->unkF0 = 0;
    this->unkFB = 0;
}
#endif

s32 UIVideoScreen::Message(UIMessage *arg0) {
    UIScreen::Message(arg0);
}

void UIVideoScreen::Resolve() {
    UIScreen::Resolve();
    ((UIEvent *) &this->unkC8)->Resolve((UIObject *) this);
    ((UIEvent *) &this->unkD4)->Resolve((UIObject *) this);
}

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to
s32 UIVideoScreen::LoadLine(UIDataLine *arg0) {
    s8 *sp8;
    s32 var_r31_570;
    s8 *temp_r3_553;

    sp8 = NULL;
    if (((MKIniLine *) arg0)->LoadString("video", &sp8, 0) != 0) {
        temp_r3_553 = this->unkE0;
        if (temp_r3_553 != NULL) {
            UIStringTable_Remove(temp_r3_553);
        }
        UIStringTable_Add(sp8);
        this->unkE0 = M2C_ERROR(/* Read from unset register $r3 */);
        return 1;
    }
    var_r31_570 = 0;
    if ((((UIEvent *) &this->unkC8)->LoadLine("OnComplete", arg0) != 0) || (((UIEvent *) &this->unkD4)->LoadLine("OnButtonPressed", arg0) != 0) || (((MKIniLine *) arg0)->LoadBool("bFadeIn", &this->unkF4, 0) != 0) || (((MKIniLine *) arg0)->LoadBool("bFadeOut", &this->unkF5, 0) != 0) || (((MKIniLine *) arg0)->LoadBool("bWideScreen", &this->unkF8, 0) != 0) || (((MKIniLine *) arg0)->LoadBool("bZoom", &this->unkF9, 0) != 0) || (((MKIniLine *) arg0)->LoadBool("bLocalized", &this->unkFA, 0) != 0) || (UIScreen::LoadLine(arg0) != 0)) {
        var_r31_570 = 1;
    }
    return var_r31_570;
}
#endif

#if 0 // DRAFT: function call 'UIStringTable_Remove(signed char *)' does not match
void UIVideoScreen::Deinit() {
    s8 *temp_r3_656;

    GameVideo_Destroy(this->unkE4);
    this->unkE4 = NULL;
    temp_r3_656 = this->unkE0;
    if (temp_r3_656 != NULL) {
        UIStringTable_Remove(temp_r3_656);
    }
    UIStringTable_Add(NULL);
    this->unkE0 = M2C_ERROR(/* Read from unset register $r3 */);
    UIContainer::Deinit();
}
#endif

void UIVideoScreen::Init() {
    UIContainer::Init();
    this->unkE4 = NULL;
    this->unkE0 = NULL;
    this->unkF4 = 0;
    this->unkF5 = 0;
    this->unkF8 = 0;
    this->unkFA = 0;
    this->unkFB = 0;
    this->unkF9 = 0;
}
