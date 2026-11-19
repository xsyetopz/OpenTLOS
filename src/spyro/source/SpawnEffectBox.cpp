#include "spyro/source/SpawnEffectBox.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include "spyro/source/MessageMap.h"
#include <m2c_macros.h>

M2C_UNK free(f32);                                  /* extern */
void *malloc(s32);                                  /* extern */
s32 stricmp(M2C_UNK *);                             /* extern */
extern MKSceneManager *gMK;
extern s32 gViewSeed;
extern M2C_UNK gb;

#if 0 // DRAFT: undefined identifier 'unk6C'
void SpawnEffectBox::Update() {
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    M2C_UNK sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    s32 spC;
    s32 sp8;
    MKModel *temp_r3_118;
    f32 temp_f29_71;
    f32 temp_f30_77;
    f32 temp_f30_85;
    f32 temp_f31_74;
    f32 temp_f31_90;
    s32 temp_r5_126;
    void *temp_r31_117;

    if ((u8) M2C_FIELD(this, u8 *, 0xF0) != 0) {
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (M2C_FIELD(&gb, f32 *, 0x30C) == this->unk50.unk40.unk6C) {
            this->unk50.unk40.unk6C = M2C_FIELD(&gb, f32 *, 0x30C) + MKRand_Float(&gViewSeed, this->unk50.unk40.unk64, this->unk50.unk40.unk68);
            temp_f29_71 = this->unk50.GetWidth();
            temp_f31_74 = this->unk50.GetHeight();
            temp_f30_77 = this->unk50.GetDepth();
            sp30.GetCenterPos();
            temp_f30_85 = MKRand_Float(&gViewSeed, -temp_f30_77, temp_f30_77);
            temp_f31_90 = MKRand_Float(&gViewSeed, -temp_f31_74, temp_f31_74);
            sp20 = MKRand_Float(&gViewSeed, -temp_f29_71, temp_f29_71);
            sp24 = temp_f31_90;
            sp28 = temp_f30_85;
            sp40 = (f64) sp20;
            sp48 = (f64) sp28;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp50 = sp10;
            sp18 = (f32) sp48 + sp38;
            sp58 = (f64) sp18;
            temp_r31_117 = *(M2C_BITWISE(s32, this->unk50.unk40.unk54) + (this->unk50.unk40.unk5C * 4));
            temp_r3_118 = M2C_FIELD(temp_r31_117, MKModel **, 4);
            if (temp_r3_118 != NULL) {
                MKModel_SetPosition(temp_r3_118, *((MKVector3 *) &sp50));
            }
            temp_r5_126 = M2C_FIELD(checked_cast<SpawnEffectBoxDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x60);
            spC = 0;
            sp8 = temp_r5_126;
            M2C_FIELD(M2C_FIELD(temp_r31_117, void **, 0x44), M2C_UNK (**)(void *, s32 *, s32), 0x2C)(temp_r31_117, &sp8, temp_r5_126);
            this->unk50.unk40.unk5C += 1;
            if ((s32) this->unk50.unk40.unk5C == M2C_BITWISE(s32, this->unk50.unk40.unk58)) {
                this->unk50.unk40.unk5C = 0;
            }
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk6C'
void SpawnEffectBox::Message(MKMessage *arg0) {
    s32 temp_r0_411;

    temp_r0_411 = arg0->unk0;
    switch (temp_r0_411) {                          /* irregular */
    case 0xB5:
        M2C_FIELD(this, s8 *, 0xF0) = 1;
        this->unk50.unk40.unk6C = M2C_FIELD(&gb, f32 *, 0x30C) + MKRand_Float(&gViewSeed, this->unk50.unk40.unk64, this->unk50.unk40.unk68);
        break;
    case 0xB4:
        M2C_FIELD(this, s8 *, 0xF0) = 0;
        break;
    }
    MKProp::Message(arg0);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk50'
void SpawnEffectBox::LoadDone() {
    MKHeap *temp_r3_471;
    f32 var_r3_458;
    s32 temp_r30_470;
    s32 var_r29_485;
    s32 var_r30_486;
    void *var_r3_478;

    MKProp::LoadDone();
    this->unk50.Init(*((Matrix *) &loadInfo));
    var_r3_458 = this->unk50.unk40.unk50;
    if (M2C_BITWISE(u32, var_r3_458) != 0U) {
        var_r3_458 = M2C_BITWISE(f32, stricmp(""));
        if (M2C_BITWISE(s32, var_r3_458) == 0) {
            this->unk50.unk40.unk50 = 0.0f;
        }
    }
    temp_r30_470 = M2C_BITWISE(s32, this->unk50.unk40.unk58) * 4;
    temp_r3_471 = ((MKHeap *) (M2C_BITWISE(MKHeap *, var_r3_458)))->Current();
    if (temp_r3_471 != NULL) {
        var_r3_478 = ((MKHeap *) (temp_r3_471->Current()))->Alloc(temp_r30_470, NULL, 0);
    } else {
        var_r3_478 = malloc(temp_r30_470);
    }
    this->unk50.unk40.unk54 = M2C_BITWISE(f32, var_r3_478);
    var_r29_485 = 0;
    var_r30_486 = 0;
loop_8:
    if (var_r29_485 < M2C_BITWISE(s32, this->unk50.unk40.unk58)) {
        gMK->CreatePropDeferred(M2C_BITWISE(s8 *, this->unk50.unk40.unk50), M2C_BITWISE(s32, this->unk50.unk40.unk54) + var_r30_486);
        var_r29_485 += 1;
        var_r30_486 += 4;
        goto loop_8;
    }
    this->unk50.unk40.unk5C = 0;
    this->unk50.unk40.unk6C = 0.0f;
    this->unk50.unk40.unk6C = M2C_FIELD(&gb, f32 *, 0x30C) + MKRand_Float(&gViewSeed, this->unk50.unk40.unk64, this->unk50.unk40.unk68);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk50'
s32 SpawnEffectBox::LoadLine(MKIniLine *arg0) {
    MKIniLine *var_r26_592;
    u8 var_r30_604;

    if ((MKProp::LoadLine(arg0) != 0) || (arg0->LoadString("SpawnEffectName", (s8 **) &this->unk50.unk40.unk50, 0) != 0) || (arg0->LoadInt("createCount", (s32 *) &this->unk50.unk40.unk58, 0) != 0) || (arg0->LoadFloat("minSpawnEffectTime", &this->unk50.unk40.unk64, 0) != 0) || (arg0->LoadFloat("maxSpawnEffectTime", &this->unk50.unk40.unk68, 0) != 0) || (arg0->LoadBool("bInitiallyEnabled", (u8 *) &this->unk50.unk40.unk60, 0) != 0)) {
        return 1;
    }
    if (arg0->IsField("box") != 0) {
        var_r26_592 = arg0->unkC->GetSubLine(arg0);
loop_15:
        if (var_r26_592 != NULL) {
            var_r30_604 = 0;
            if ((var_r26_592->LoadVector3("pos", (MKVector3 *) &loadInfo.unk40, 0) != 0) || (var_r26_592->LoadVector3("rot", &loadInfo + 0x50, 0) != 0)) {
                var_r30_604 = 1;
            }
            if (var_r30_604 == 0) {
                var_r26_592->LoadVector3("scale", &loadInfo + 0x60, 0);
            }
            var_r26_592 = var_r26_592->unkC->GetNextLine(var_r26_592);
            goto loop_15;
        }
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk54'
void SpawnEffectBox::Deinit() {
    MKHeap *temp_r3_661;
    f32 temp_r31_658;

    temp_r31_658 = this->unk50.unk40.unk54;
    if (M2C_BITWISE(u32, temp_r31_658) != 0U) {
        temp_r3_661 = MKHeap::Current();
        if (temp_r3_661 != NULL) {
            ((MKHeap *) (temp_r3_661->Current()))->Free(M2C_BITWISE(void *, temp_r31_658), NULL, 0);
        } else {
            free(temp_r31_658);
        }
    }
    this->unk50.Deinit();
    MKProp::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'unk50'
void SpawnEffectBox::Init() {
    MKProp::Init();
    this->unk50.unk40.unk50 = 0.0f;
    this->unk50.unk40.unk54 = 0.0f;
    this->unk50.unk40.unk58 = 0.0f;
    this->unk50.unk40.unk5C = 0;
    M2C_FIELD(this, s8 *, 0xF0) = 0;
    this->unk50.unk40.unk64 = 0.4f;
    this->unk50.unk40.unk68 = 0.5f;
}
#endif

#if 0 // DRAFT: function call 'MessageMap_LoadLine(MKIniLine *, const char[18], long *)'
s32 SpawnEffectBoxDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_720;

    var_r31_720 = 0;
    if ((MKPropDescriptor::LoadLine(arg0) != 0) || (MessageMap_LoadLine(arg0, "effectOnMessageID", &this->unk60) != 0)) {
        var_r31_720 = 1;
    }
    return var_r31_720;
}
#endif
