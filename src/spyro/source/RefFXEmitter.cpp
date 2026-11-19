#include "spyro/source/RefFXEmitter.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/Steam.h"
#include "unplaced_templates.h"
#include "common/Source/MKModel.h"
#include "common/Source/StdMath.h"
#include "common/Source/Str.h"
#include <m2c_macros.h>

extern MKSceneManager *gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;

void RefFXEmitter::Message(MKMessage *arg0) {
    KDProp::Message(arg0);
}

#if 0 // DRAFT: ')' expected
void RefFXEmitter::Update() {
    f32 temp_f2_71;
    f32 temp_f31_137;
    u8 var_r0_70;
    void *temp_r31_132;
    KDProp::Update();
    var_r0_70 = 0;
    temp_f2_71 = this->unk90;
    if (temp_f2_71 == 0.0f) {
        this->unk94 = MKRand_Int(&gViewSeed, 0, M2C_FIELD(checked_cast<RefFXEmitterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x98));
        this->unk90 = MKRand_Float(&gViewSeed, 0.2f, 0.8f);
        var_r0_70 = 1;
    } else if (temp_f2_71 > 0.0f) {
        this->unk90 = temp_f2_71 - gUpdateTimeDelta;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (this->unk90 == 0.0f) {
            this->unk90 = MKRand_Float(&gViewSeed, -1.0f, -0.2f);
        }
        var_r0_70 = 1;
    } else {
        this->unk90 = temp_f2_71 + gUpdateTimeDelta;
        if (this->unk90 > 0.0f) {
            this->unk90 = 0.0f;
        }
    }
    if (var_r0_70 != 0) {
        MKModel_GetRefPointMatrix(this->unk4, M2C_FIELD((checked_cast<RefFXEmitterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (this->unk94 * 4)), s32 *, 0x70), (Matrix *) &arg_sp60, 1U);
        temp_r31_132 = checked_cast<RefFXEmitterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        temp_f31_137 = MKRand_Float(&gViewSeed, -700.0f, -300.0f);
        arg_sp28 = -arg_sp70;
        arg_sp2C = -arg_sp74;
        arg_sp30 = -arg_sp78;
        arg_sp38 = (f64) arg_sp28;
        arg_sp40 = (f64) arg_sp30;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        arg_sp48 = arg_sp18;
        arg_sp20 = (f32) arg_sp40 * temp_f31_137;
        arg_sp50 = (f64) arg_sp20;
        arg_sp10 = MKRand_Float(&gViewSeed, 2.0f, 5.0f);
        ((Steam *) (M2C_FIELD(temp_r31_132, Steam **, 0x9C)))->Emit(*((MKVector3 *) &arg_sp90), *((MKVector3 *) &arg_sp48), arg_sp10);
    }
}
#endif

void RefFXEmitter::LoadDone() {
    KDProp::LoadDone();
}

#if 0 // DRAFT: identifier 'RefFXEmitter::LoadLine(MKIniLine *)' redeclared
void RefFXEmitter::LoadLine(MKIniLine *arg0) {
    KDProp::LoadLine(arg0);
}
#endif

void RefFXEmitter::Deinit() {
    KDProp::Deinit();
}

void RefFXEmitter::Init() {
    KDProp::Init();
    this->unk90 = 0.0f;
    this->unk94 = 0;
}

#if 0 // DRAFT: function call 'MKModel_RefPointExists(MKModel *, signed char *, long *)'
void RefFXEmitterDescriptor::Resolve() {
    s32 sp8;
    s32 temp_r3_257;

    MKPropDescriptor::Resolve();
    sp8 = -1;
    this->unk98 = 0;
loop_2:
    if (MKModel_RefPointExists(this->unk2C, Str_Printf("r_fxemit%d", this->unk98), &sp8) != 0) {
        temp_r3_257 = this->unk98;
        this->unk98 = temp_r3_257 + 1;
        *(this + ((temp_r3_257 * 4) + 0x70)) = sp8;
        goto loop_2;
    }
    this->unk9C = checked_cast<Steam *, MKProp>(gMK->CreateProp("Steam"));
}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<RefFXEmitterDescriptor *, MKPropDescriptor>(MKPropDescriptor *arg0) {

}
#endif
