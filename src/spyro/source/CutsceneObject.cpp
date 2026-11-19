#include "spyro/source/CutsceneObject.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/Level.h"
#include "common/Source/Str.h"
#include <m2c_macros.h>

M2C_UNK free(s8 *);                                 /* extern */
s8 *malloc(s32);                                    /* extern */
extern M2C_UNK gb;

s32 CutsceneObject::Skippable() {
    return this->unk40.Send(NULL) != 0.0f;
}

void CutsceneObject::GetFileName(char *arg0) {
    MakeCutsceneFilename(this->GetNumber(), (const char *) this->unk54, arg0, this->unk59 != 0);
}

void CutsceneObject::StopEvent() {
    if ((u8) this->unk58 != 0) {
        this->unk3C.Send(NULL);
    }
}

void CutsceneObject::PlayEvent() {
    if ((u8) this->unk58 != 0) {
        this->unk38.Send(NULL);
    }
}

void CutsceneObject::End() {
    this->unk5A = 0;
    this->unk30.Send(NULL);
}

void CutsceneObject::ReturnToGame() {
    s8 sp62;
    s8 sp61;
    s8 sp60;
    s8 sp5C;
    f32 sp58;
    f64 sp50;
    f64 sp48;
    s32 sp44;
    s32 sp40;
    f64 sp38;
    f64 sp30;
    s32 sp2C;
    s32 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f2_121;
    f32 temp_f2_151;
    f64 temp_f1_125;

    if ((u8) this->unk5E != 0) {
        sp44 = 0;
        temp_f2_121 = this->unk44;
        sp40 = 0xE;
        temp_f1_125 = this->unk10;
        sp48 = temp_f1_125;
        sp50 = this->unk18;
        sp58 = temp_f2_121;
        sp5C = 0;
        sp60 = 0;
        sp61 = 1;
        sp62 = 1;
        M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), M2C_UNK (**)(void **, s32 *, M2C_UNK, M2C_UNK, f64, f32), 0x1C)(M2C_FIELD(&gb, void ***, 0), &sp40, 0xE, 0, temp_f1_125, temp_f2_121);
    }
    if ((u8) this->unk60 != 0) {
        sp2C = 0;
        sp8 = this->unk10 - M2C_FIELD(this, f64 *, 0x20);
        temp_f2_151 = (f32) M2C_FIELD(this, f64 *, 0x18);
        sp28 = 0x42E;
        sp30 = sp8;
        sp10 = temp_f2_151 - this->unk20.unk8;
        sp18 = sp8;
        sp38 = (f64) sp10;
        sp20 = (f64) sp10;
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64, f32), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp28, sp8, temp_f2_151);
        this->unk61 = 1;
    }
}

void CutsceneObject::Begin() {
    this->unk34.Send(NULL);
    this->unk5B = 1;
    this->unk5A = 1;
}

s32 CutsceneObject::GetNumber() {
    s32 temp_r0_207;

    if ((u8) this->unk5B != 0) {
        temp_r0_207 = this->unk4C;
        if (temp_r0_207 != -1) {
            return temp_r0_207;
        }
    }
    return this->unk48;
}

void CutsceneObject::Update() {
    s32 spC;
    s32 sp8;

    if ((u8) this->unk61 != 0) {
        spC = 0;
        sp8 = 0x430;
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp8);
        this->unk61 = 0;
    }
}

void CutsceneObject::Resolve() {

}

s32 CutsceneObject::LoadSubLine(MKIniLine *arg0) {
    MKIniLine *var_r31_275;
    s32 var_r31_344;
    s8 *var_r3_322;
    u32 temp_r3_312;

    if (arg0->IsField("camera") != 0) {
        var_r31_275 = arg0->unkC->GetSubLine(arg0);
        while (var_r31_275 != NULL) {
            if (var_r31_275->LoadVector3("cameraSource", &this->unk20, 0) == 0) {
                var_r31_275 = var_r31_275->unkC->GetNextLine(var_r31_275);
            } else {
                break;
            }
        }
        return 1;
    }
    if ((arg0->IsField("levelCode") != 0) && (arg0->GetString(0) != 0U)) {
        temp_r3_312 = strlen((const char *) arg0->GetString(0));
        if (temp_r3_312 != 0) {
            if (MKHeap::Current() != NULL) {
                var_r3_322 = (s8 *) (((MKHeap *) (MKHeap::Current()))->Alloc(temp_r3_312 + 1, NULL, 0));
            } else {
                var_r3_322 = malloc(temp_r3_312 + 1);
            }
            this->unk54 = var_r3_322;
            strcpy((char *) this->unk54, (const char *) arg0->GetString(0));
        }
        return 1;
    }
    var_r31_344 = 0;
    if ((arg0->LoadInt("disabledZone", (int *) &this->unk50, 0) != 0) || (arg0->LoadInt("cutscene1", (int *) &this->unk48, 0) != 0) || (arg0->LoadInt("altCutscene1", (int *) &this->unk4C, 0) != 0) || (arg0->LoadBool("bBlankScreenAfter", (bool *) &this->unk5C, 0) != 0) || (arg0->LoadBool("bBlankThroughLoadScreen", (bool *) &this->unk5D, 0) != 0) || (arg0->LoadBool("bSetHeroPos", (bool *) &this->unk5E, 0) != 0) || (arg0->LoadBool("bSetCameraPos", (bool *) &this->unk60, 0) != 0) || (arg0->LoadBool("bVideo", (bool *) &this->unk59, 0) != 0) || (arg0->LoadVector3("heroPos", (MKVector3 *) &this->unk10, 0) != 0) || (arg0->LoadFloat("heroLookYaw", &this->unk44, 0) != 0) || (arg0->LoadBool("bLeaveHeroVisible", (bool *) &this->unk5F, 0) != 0) || (arg0->LoadBool("bUseLoadingScreen", (bool *) &this->unk62, 0) != 0) || (arg0->LoadBool("bZoomVideo", (bool *) &this->unk63, 0) != 0) || (this->unk30.LoadLine(arg0, "onCompletion") != 0) || (this->unk34.LoadLine(arg0, "onActivation") != 0) || (this->unk38.LoadLine(arg0, "onPlay") != 0) || (this->unk3C.LoadLine(arg0, "onStop") != 0) || (this->unk40.LoadLine(arg0, "skipQuery") != 0) || (arg0->LoadVector4("BlankColour", (MKVector4 *) this, 0) != 0)) {
        var_r31_344 = 1;
    }
    return var_r31_344;
}

s32 CutsceneObject::LoadLine(MKIniLine *arg0) {
    MKIniLine *var_r31_537;

    if (arg0->IsField("cutscene") != 0) {
        var_r31_537 = arg0->unkC->GetSubLine(arg0);
loop_3:
        if (var_r31_537 != NULL) {
            LoadSubLine(var_r31_537);
            var_r31_537 = var_r31_537->unkC->GetNextLine(var_r31_537);
            goto loop_3;
        }
        return 1;
    }
    return 0;
}

CutsceneObject::~CutsceneObject() {
    s8 *temp_r31_572;

    if (this != NULL) {
        temp_r31_572 = this->unk54;
        if (temp_r31_572 != NULL) {
            if (MKHeap::Current() != NULL) {
                ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_572, NULL, 0);
            } else {
                free(temp_r31_572);
            }
        }
        if (&this->unk40 != NULL) {
            this->unk40.Deinit();
        }
        if (&this->unk3C != NULL) {
            this->unk3C.Deinit();
        }
        if (&this->unk38 != NULL) {
            this->unk38.Deinit();
        }
        if (&this->unk34 != NULL) {
            this->unk34.Deinit();
        }
        if (&this->unk30 != NULL) {
            this->unk30.Deinit();
        }
    }
}

CutsceneObject::CutsceneObject() {
    this->unk0 = M2C_FIELD(&MKVector4::zero, f64 *, 0);
    this->unk8 = M2C_FIELD(&MKVector4::zero, f64 *, 8);
    this->unk30.unk0 = 0;
    this->unk30.Init();
    this->unk34.unk0 = 0;
    this->unk34.Init();
    this->unk38.unk0 = 0;
    this->unk38.Init();
    this->unk3C.unk0 = 0;
    this->unk3C.Init();
    this->unk40.unk0 = 0;
    this->unk40.Init();
    this->unk48 = -1;
    this->unk4C = -1;
    this->unk50 = 0;
    this->unk54 = NULL;
    this->unk58 = 1;
    this->unk59 = 0;
    this->unk5A = 0;
    this->unk5B = 0;
    this->unk5C = 0;
    this->unk5D = 0;
    this->unk5E = 0;
    this->unk5F = 0;
    this->unk60 = 0;
    this->unk61 = 0;
    this->unk62 = 0;
    this->unk63 = 0;
}

s8 *MakeCutsceneFilename(int arg0, const char *arg1, char *arg2, bool arg3) {
    const char *name;
    s8 *out;
    void *temp_r5_703;
    void *var_r4_706;

    name = arg1;
    if (arg3 != 0) {
        if (name == NULL) {
            temp_r5_703 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x32C), void **, 0x18);
            if (temp_r5_703 != NULL) {
                var_r4_706 = M2C_FIELD(temp_r5_703, void **, 4);
            } else {
                var_r4_706 = M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x32C), void **, 0x24), void **, 4);
            }
            name = (const char *) M2C_FIELD(var_r4_706, s8 **, 0xC);
        }
        out = Str_Printf("cs%s_%02d", name, arg0, "camera");
    } else {
        if (name == NULL) {
            temp_r5_703 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x32C), void **, 0x18);
            if (temp_r5_703 != NULL) {
                var_r4_706 = M2C_FIELD(temp_r5_703, void **, 4);
            } else {
                var_r4_706 = M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x32C), void **, 0x24), void **, 4);
            }
            name = (const char *) M2C_FIELD(var_r4_706, s8 **, 0xC);
        }
        out = Str_Printf("cs%s_%02dEN.sc2", name, arg0, "camera");
    }
    if (arg2 == NULL) {
        return out;
    }
    strcpy(arg2, (const char *) out);
    return (s8 *) arg2;
}
