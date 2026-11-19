#include "spyro/source/CutsceneEvent.h"
#include "common/Source/Animation.h"
#include "common/Source/MKDynamicBone.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Collectable.h"
#include "spyro/source/Explosion4.h"
#include "spyro/source/KDSynkerPlayer3.h"
#include "spyro/source/KDSynkerPlayerActorList.h"
#include "spyro/source/KDSynkerPlayerEvents.h"
#include "spyro/source/LavaBubbleFX.h"
#include "spyro/source/Level.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Tools.h"
#include "spyro/source/UIStringTable.h"
#include "spyro/source/ZapBreathFX.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "spyro/source/DataMap.h"
#include "spyro/source/GameConsole.h"
#include "spyro/source/Music.h"
#include <m2c_macros.h>

extern u8 bIgnoreEvent;
extern MKDynamicBoneSystem gDynamicBones;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern void **gb;
#if 0 // DRAFT: illegal use of incomplete struct/union/class 'DataMap'
static DataMap elementMap;                          /* unable to generate initializer: confusing struct layout */
static DataMap attackMap;                           /* unable to generate initializer: confusing struct layout */

void LavaBubbleCE::Update() {
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
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_70;
    f32 temp_f1_86;
    f32 temp_f2_79;
    f32 temp_f2_82;
    f32 temp_f30_83;
    f32 temp_f31_63;
    f32 temp_f3_56;
    f64 temp_f0_98;

    this->unk20 += gUpdateTimeDelta;
    temp_f3_56 = M2C_BITWISE(f32, KDSynkerPlayerEvent::updateData.__vptr);
    if (temp_f3_56 > 0.0f) {
        temp_f31_63 = (1.0f / this->unk1C) / temp_f3_56;
        if (this->unk20 >= temp_f31_63) {
            temp_f1_70 = MKRand_Float(&gViewSeed, 0.5f, 1.5f);
            sp10 = temp_f1_70;
            sp8 = temp_f1_70;
            spC = temp_f1_70;
            sp40 = (f64) sp10;
            sp38 = (f64) sp8;
            temp_f2_79 = this->unk18;
            temp_f2_82 = this->unk18;
            temp_f30_83 = MKRand_Float(&gViewSeed, -temp_f2_79, temp_f2_79);
            temp_f1_86 = MKRand_Float(&gViewSeed, -temp_f2_82, temp_f2_82);
            sp30 = temp_f30_83;
            sp28 = temp_f1_86;
            sp2C = 0.0f;
            sp50 = (f64) sp30;
            sp48 = (f64) sp28;
            temp_f0_98 = M2C_FIELD(this, f64 *, 8) + sp48;
            sp18 = temp_f0_98;
            sp58 = temp_f0_98;
            sp20 = this->unk8.unk8 + (f32) sp50;
            sp60 = (f64) sp20;
            ((LavaBubbleFX *) (M2C_FIELD(&gb, LavaBubbleFX **, 0x90)))->CreateBubble(*((MKVector3 *) &sp58), *((MKVector3 *) &sp38));
            this->unk20 -= temp_f31_63;
        }
    }
}
#endif

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void LavaBubbleCE::Enter() {
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
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_144;
    f32 temp_f1_160;
    f32 temp_f2_153;
    f32 temp_f2_156;
    f32 temp_f31_157;
    f64 temp_f0_172;

    this->unk20 = 0.0f;
    temp_f1_144 = MKRand_Float(&gViewSeed, 0.5f, 1.5f);
    sp10 = temp_f1_144;
    sp8 = temp_f1_144;
    spC = temp_f1_144;
    sp40 = (f64) sp10;
    sp38 = (f64) sp8;
    temp_f2_153 = this->unk18;
    temp_f2_156 = this->unk18;
    temp_f31_157 = MKRand_Float(&gViewSeed, -temp_f2_153, temp_f2_153);
    temp_f1_160 = MKRand_Float(&gViewSeed, -temp_f2_156, temp_f2_156);
    sp30 = temp_f31_157;
    sp28 = temp_f1_160;
    sp2C = 0.0f;
    sp50 = (f64) sp30;
    sp48 = (f64) sp28;
    temp_f0_172 = M2C_FIELD(this, f64 *, 8) + sp48;
    sp18 = temp_f0_172;
    sp58 = temp_f0_172;
    sp20 = this->unk8.unk8 + (f32) sp50;
    sp60 = (f64) sp20;
    ((LavaBubbleFX *) (M2C_FIELD(&gb, LavaBubbleFX **, 0x90)))->CreateBubble(*((MKVector3 *) &sp58), *((MKVector3 *) &sp38));
}
#endif

s32 LavaBubbleCE::LoadLine() {
    s32 var_r31_208;

    var_r31_208 = 0;
    if ((LoadVector3("pos", &this->unk8) != 0) || (LoadFloat("radius", &this->unk18) != 0) || (LoadFloat("ratePerSec", &this->unk1C) != 0)) {
        var_r31_208 = 1;
    }
    return var_r31_208;
}

#if 0 // DRAFT: undefined identifier '__vptr'
u8 ImageCE::LoadVector2(const char *arg0, MKVector2 *arg1) {
    u8 var_r31_248;

    var_r31_248 = 0;
    if ((((MKIniLine *) KDSynkerPlayerEvent::pLine.__vptr)->IsField(arg0) != 0) && (((MKIniLine *) KDSynkerPlayerEvent::pLine.__vptr)->AsFloat(0, &arg1->unk0) != 0) && (((MKIniLine *) KDSynkerPlayerEvent::pLine.__vptr)->AsFloat(1, &arg1->unk4) != 0)) {
        var_r31_248 = 1;
    }
    return var_r31_248;
}
#endif

#if 0 // DRAFT: ')' expected
void ImageCE::Draw() {
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    Tools_Ortho sp8;
    f32 temp_f28_313;
    f32 temp_f29_312;
    f32 temp_f30_311;
    f32 temp_f31_310;
    f32 temp_f3_299;
    f32 temp_f3_308;
    f32 temp_f4_304;
    f32 temp_f5_301;
    f32 temp_f6_306;

    sp10 = 1.0f;
    sp14 = 1.0f;
    sp18 = 1.0f;
    sp1C = this->unk40;
    temp_f3_299 = this->unk4;
    temp_f5_301 = this->unk8;
    temp_f4_304 = this->unk44;
    temp_f6_306 = this->unk14;
    temp_f3_308 = this->unk18;
    temp_f31_310 = -((0.5f * temp_f6_306) - ((temp_f4_304 * (this->unkC - temp_f3_299)) + temp_f3_299));
    temp_f30_311 = -((0.5f * temp_f3_308) - ((temp_f4_304 * (this->unk10 - temp_f5_301)) + temp_f5_301));
    temp_f29_312 = temp_f31_310 + temp_f6_306;
    temp_f28_313 = temp_f30_311 + temp_f3_308;
    sp8.Tools_Ortho();
    MKMaterial_SetMaterial(this->unk3C);
    MKSetBaseColorV(MKVector4::one);
    MKPrimitive(0xC, 1);
    MKBegin(4);
    MKSetColorV(*((MKVector4 *) &sp10));
    MKSetTexCoord1F(0.0f, 0.0f);
    MKSetPositionF(temp_f31_310, temp_f30_311, 0.0f);
    MKSetTexCoord1F(1.0f, 0.0f);
    MKSetPositionF(temp_f29_312, temp_f30_311, 0.0f);
    MKSetTexCoord1F(0.0f, 1.0f);
    MKSetPositionF(temp_f31_310, temp_f28_313, 0.0f);
    MKSetTexCoord1F(1.0f, 1.0f);
    MKSetPositionF(temp_f29_312, temp_f28_313, 0.0f);
    MKEnd();
    MKEndPrimitive();
    sp8.~Tools_Ortho(-1);
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void ImageCE::Update() {
    this->unk40 = M2C_BITWISE(f32, KDSynkerPlayerEvent::updateData.__vptr);
    this->unk44 = (M2C_FIELD(&KDSynkerPlayerEvent::updateData, f32 *, 4) - (f32) M2C_FIELD(&KDSynkerPlayerEvent::updateData, s32 *, 8)) / (f32) M2C_FIELD(&KDSynkerPlayerEvent::updateData, s32 *, 0xC);
}
#endif

#if 0 // DRAFT: function call 'MKMaterial_Create(signed char *)' does not match
void ImageCE::LoadDone() {
    this->unk3C = MKMaterial_Create(&this->unk1C);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
s32 ImageCE::LoadLine() {
    s32 var_r31_434;

    var_r31_434 = 0;
    if ((LoadString("filename", &this->unk1C) != 0) || (LoadVector2("from", (MKVector2 *) &this->unk4) != 0) || (LoadVector2("to", (MKVector2 *) &this->unkC) != 0) || (LoadVector2("size", (MKVector2 *) &this->unk14) != 0)) {
        var_r31_434 = 1;
    }
    return var_r31_434;
}
#endif

void ImageCE::Deinit() {
    MKMaterial_Destroy(this->unk3C);
}

#if 0 // DRAFT: illegal implicit conversion from 'SpawnGemsCE' to
void SpawnGemsCE::Enter() {
    MKVector3 sp8;
    s32 temp_r5_506;
    s32 var_r29_501;
    s32 var_r31_503;

    MKModel_CalculateNodeWorldPosition(this->unk14, this->unk18, &sp8);
    var_r29_501 = 0;
    var_r31_503 = 0;
    do {
        temp_r5_506 = *(this + (var_r31_503 + 4));
        if (temp_r5_506 != 0) {
            ((CollectableSpawner *) (M2C_FIELD((&gb + var_r31_503), CollectableSpawner **, 0x10)))->Spawn(sp8, temp_r5_506, 200.0f, 500.0f, -1, NULL);
        }
        var_r29_501 += 1;
        var_r31_503 += 4;
    } while (var_r29_501 < 4);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
s32 SpawnGemsCE::LoadLine() {
    s32 var_r31_540;

    var_r31_540 = 0;
    LoadNode("node", &this->unk14, &this->unk18);
    if (((u8) M2C_ERROR(/* Read from unset register $r3 */) != 0) || (LoadInt("gemsHealth", &this->unk4) != 0) || (LoadInt("gemsMagic", &this->unkC) != 0) || (LoadInt("gemsSpirit", &this->unk8) != 0) || (LoadInt("gemsFury", &this->unk10) != 0)) {
        var_r31_540 = 1;
    }
    return var_r31_540;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void DisableShadowCE::Exit() {
    ((Shadow *) (M2C_FIELD(KDSynkerPlayerEvent::pSynker.__vptr, s32 *, 0x104) + (this->unk4 * 0x138)))->Show(1U);
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void DisableShadowCE::Enter() {
    ((Shadow *) (M2C_FIELD(KDSynkerPlayerEvent::pSynker.__vptr, s32 *, 0x104) + (this->unk4 * 0x138)))->Show(0U);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
s32 DisableShadowCE::LoadLine() {
    LoadActorID("actor", &this->unk4);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void BreathEffectCE::Update() {
    Matrix sp20;
    MKVector3 sp10;
    s32 temp_r0_673;

    MKModel_CalculateNodeWorldMatrix(this->unk48, this->unk58, &sp20);
    MKModel_CalculateRefPointWorldPosition(this->unk48, this->unk54, &sp10);
    sp20.unk30 = M2C_BITWISE(f32, sp10);
    sp20.unk34 = sp10.unk4;
    sp20.unk38 = sp10.unk8;
    sp20.unk3C = 1.0f;
    this->unk28 = &sp20;
    temp_r0_673 = this->unk4C;
    switch (temp_r0_673) {                          /* irregular */
    case 0:
        M2C_FIELD(*M2C_FIELD(*gb, void **(**)(void **), 0x3C)(gb), M2C_UNK (**)(u8 *), 8)(&this->unk8);
        return;
    case 2:
        M2C_FIELD(*M2C_FIELD(*gb, void **(**)(void **), 0x3C)(gb), M2C_UNK (**)(u8 *), 0xC)(&this->unk8);
        return;
    case 1:
        M2C_FIELD(*M2C_FIELD(*gb, void **(**)(void **), 0x3C)(gb), M2C_UNK (**)(u8 *), 0x10)(&this->unk8);
        return;
    case 3:
        M2C_FIELD(*M2C_FIELD(*gb, void **(**)(void **), 0x3C)(gb), M2C_UNK (**)(u8 *), 0x14)(&this->unk8);
        return;
    }
}
#endif

void BreathEffectCE::Exit() {
    s32 temp_r0_768;
    void *temp_r4_799;

    M2C_FIELD(*M2C_FIELD(*gb, void **(**)(void **, void ***), 0x3C)(gb, &gb), M2C_UNK (**)(), 0x20)();
    temp_r0_768 = this->unk4C;
    switch (temp_r0_768) {                          /* irregular */
    case 0:
        M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **), 0x3C)(gb), void **, 4), void **, 0x14), s8 *, 0xB4) = 0;
        return;
    case 1:
        temp_r4_799 = M2C_FIELD(M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **), 0x3C)(gb), void **, 4), void **, 0x18);
        M2C_FIELD(temp_r4_799, s8 *, 0x9E0) = 0;
        ((ZapBreathFX *) (M2C_FIELD(M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **, void *), 0x3C)(gb, temp_r4_799), void **, 4), ZapBreathFX **, 0x18)))->ButtonReleased();
        return;
    }
}

#if 0 // DRAFT: pointer/array required
void BreathEffectCE::Enter() {
    f64 temp_f1_831;

    if ((s32) this->unk30 == 3) {
        MKModel_GetPosition(this->unk48);
        temp_f1_831 = *M2C_ERROR(/* Read from unset register $r3 */);
        this->unk18 = temp_f1_831;
        this->unk20 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f64 *, 8);
        M2C_FIELD(*M2C_FIELD(*gb, void **(**)(void **, void ***, f64), 0x3C)(gb, &gb, temp_f1_831), M2C_UNK (**)(u8 *), 0x18)(&this->unk8);
    }
}
#endif

#if 0 // DRAFT: function call 'strcpy(signed char *, signed char *)' does not match
void BreathEffectCE::LoadDone() {
    s8 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    s32 var_r0_893;

    sp8 = 0.0f;
    spC = 0.0f;
    sp10 = 0.0f;
    M2C_FIELD(this, f64 *, 8) = (f64) sp8;
    this->unk10 = (f64) sp10;
    this->unk3C = 1;
    this->unk34 = 0;
    this->unk44 = 0;
    this->unk45 = 0;
    sp18 = (f64) sp8;
    sp20 = (f64) sp10;
    this->unk46 = this->unk4C == 0x3E7;
    if ((u8) this->unk46 == 0) {
        this->unk2C = this->unk4C;
    }
    if ((u8) this->unk46 != 0) {
        var_r0_893 = 3;
    } else {
        var_r0_893 = this->unk50;
    }
    this->unk30 = var_r0_893;
    this->unk38 = 0;
    this->unk40 = 0;
    strcpy(&sp28, MKModel_GetRefPointName(this->unk48, 0));
    strcpy(strchr(strchr(&sp28, 0x5F) + 1, 0x5F) + 1, "nose");
    this->unk54 = MKModel_GetRefPointIndex(this->unk48, &sp28);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
s32 BreathEffectCE::LoadLine() {
    s8 sp8;

    if (LoadString("element", &sp8) != 0) {
        this->unk4C = DataMap_GetValue(&elementMap, &sp8);
        return;
    }
    if (LoadString("attack", &sp8) != 0) {
        this->unk50 = DataMap_GetValue(&attackMap, &sp8);
        return;
    }
    LoadNode("headNode", &this->unk48, &this->unk58);
}
#endif

void PlaySecondaryAnimCE::Update() {
    this->unk28.Animate(MKModel_GetAnimation(this->unk28.unk8), this->unk8C, NULL);
}

void PlaySecondaryAnimCE::Enter() {
    this->unk28.SetAnim(this->unk88, 1.0f, 0.1f, 0x10, this->unk8C);
}

#if 0 // DRAFT: function call 'GetAnim(signed char *)' does not match
void PlaySecondaryAnimCE::LoadDone() {
    this->unk28.Init(this->unk80, this->unk84);
    this->unk88 = this->unk28.GetAnim(&this->unk4);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
s32 PlaySecondaryAnimCE::LoadLine() {
    s32 var_r31_1080;

    if (LoadActorAnimScript("actor", &this->unk80) != 0) {
        LoadActorModel("actor", &this->unk84);
        return 1;
    }
    var_r31_1080 = 0;
    LoadNode("node", &this->unk84, &this->unk8C);
    if (((u8) M2C_ERROR(/* Read from unset register $r3 */) != 0) || (LoadString("anim", &this->unk4) != 0)) {
        var_r31_1080 = 1;
    }
    return var_r31_1080;
}
#endif

void PlaySecondaryAnimCE::Deinit() {
    this->unk28.Deinit();
}

void FadeCE::Exit() {
    M2C_FIELD(&gb, f64 *, 0x40) = (f64) M2C_FIELD(&MKVector4::zero, f64 *, 0);
    M2C_FIELD(&gb, f64 *, 0x48) = (f64) M2C_FIELD(&MKVector4::zero, f64 *, 8);
}

#if 0 // DRAFT: undefined identifier '__vptr'
void FadeCE::Update() {
    this->unk14 = M2C_BITWISE(f32, KDSynkerPlayerEvent::updateData.__vptr);
    M2C_FIELD(&gb, f64 *, 0x40) = (f64) this->unk8;
    M2C_FIELD(&gb, f64 *, 0x48) = (f64) M2C_FIELD(this, f64 *, 0x10);
}
#endif

s32 FadeCE::LoadLine() {
    LoadVector3("color", (MKVector3 *) &this->unk8);
}

void FadeCE::Deinit() {
    M2C_FIELD(&gb, f64 *, 0x40) = (f64) M2C_FIELD(&MKVector4::zero, f64 *, 0);
    M2C_FIELD(&gb, f64 *, 0x48) = (f64) M2C_FIELD(&MKVector4::zero, f64 *, 8);
}

void FadeCE::Init() {
    M2C_FIELD(this, f32 *, 8) = 0.0f;
    M2C_FIELD(this, f32 *, 0xC) = 0.0f;
    this->unk10 = 0.0f;
    this->unk14 = 0.0f;
}

void PlayMusicCE::Exit() {
    Music_Stop(-1.0f);
    if ((u8) this->unk24 != 0) {
        Music_Resume();
    }
}

#if 0 // DRAFT: function call 'Music_Play(signed char *, bool)' does not match
void PlayMusicCE::Enter() {
    Music_Play(&this->unk4, this->unk24 == 0);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to
s32 PlayMusicCE::LoadLine() {
    s32 var_r31_1237;

    var_r31_1237 = 0;
    if ((LoadBool("bPlayGameMusicAfterCutscene", &this->unk24) != 0) || (LoadString("musicName", &this->unk4) != 0)) {
        var_r31_1237 = 1;
    }
    return var_r31_1237;
}
#endif

void PlayMusicCE::Init() {
    this->unk4 = 0;
    this->unk24 = 0;
}

void ResetClothCE::Update() {
    s16 temp_r31_1281;
    s32 var_r30_1282;

    temp_r31_1281 = MKModel_GetNmbrOfSubObjects(this->unk4, (SubObjectType) 2);
    var_r30_1282 = 0;
loop_2:
    if (var_r30_1282 < temp_r31_1281) {
        ((MKCloth *) (MKModel_GetClothSubObject(this->unk4, var_r30_1282)))->Settle(5, NULL);
        var_r30_1282 += 1;
        goto loop_2;
    }
}

s32 ResetClothCE::LoadLine() {
    LoadActorModel("actor", &this->unk4);
}

void DisableWobbleTechCE::Exit() {
    gDynamicBones.Enable(this->unk4, 1U);
}

void DisableWobbleTechCE::Enter() {
    gDynamicBones.Enable(this->unk4, 0U);
}

s32 DisableWobbleTechCE::LoadLine() {
    LoadActorModel("actor", &this->unk4);
}

void ColorCE::Exit() {
    MKModel_SetColor(this->unk28, this->unk8);
}

void ColorCE::Enter() {
    f64 *temp_r3_1395;

    temp_r3_1395 = MKModel_GetColor(this->unk28);
    M2C_FIELD(this, f64 *, 8) = (f64) M2C_FIELD(temp_r3_1395, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x10) = (f64) M2C_FIELD(temp_r3_1395, f64 *, 8);
}

#if 0 // DRAFT: undefined identifier '__vptr'
void ColorCE::Update() {
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f64 sp10;
    f64 sp8;
    MKModel *temp_r5_1413;
    f32 temp_f3_1431;
    f32 temp_f4_1418;
    f64 temp_f0_1439;
    f64 temp_f0_1451;
    f64 temp_f1_1421;

    temp_r5_1413 = this->unk28;
    if (temp_r5_1413 != NULL) {
        temp_f4_1418 = M2C_BITWISE(f32, KDSynkerPlayerEvent::updateData.__vptr);
        temp_f1_1421 = M2C_FIELD(this, f64 *, 0x18) * (f64) temp_f4_1418;
        sp18 = temp_f1_1421;
        sp20 = M2C_FIELD(this, f64 *, 0x20) * (f64) temp_f4_1418;
        temp_f3_1431 = 1.0f - temp_f4_1418;
        sp38 = temp_f1_1421;
        sp40 = sp20;
        sp28 = M2C_FIELD(this, f64 *, 8) * (f64) temp_f3_1431;
        temp_f0_1439 = M2C_FIELD(this, f64 *, 0x10) * (f64) temp_f3_1431;
        sp30 = temp_f0_1439;
        sp48 = sp28;
        sp50 = temp_f0_1439;
        sp8 = sp28 + sp38;
        temp_f0_1451 = sp50 + sp20;
        sp10 = temp_f0_1451;
        sp58 = sp8;
        sp60 = temp_f0_1451;
        (*(f32 *) ((u8 *) &sp60 + 0x4)) = 1.0f;
        MKModel_SetColor(temp_r5_1413, *((MKVector4 *) &sp58));
    }
}
#endif

s32 ColorCE::LoadLine() {
    s32 var_r31_1479;

    var_r31_1479 = 0;
    if ((LoadActorModel("actor", &this->unk28) != 0) || (LoadVector3("color", &this->unk18) != 0)) {
        var_r31_1479 = 1;
    }
    return var_r31_1479;
}

void DepthOfFieldCE::Exit() {
    ((Level *) (M2C_FIELD(&gb, Level **, 0x32C)))->DOFSetPlanes(this->unk4, this->unk8, this->unkC, this->unk10);
}

void DepthOfFieldCE::Enter() {
    ((Level *) (M2C_FIELD(&gb, Level **, 0x32C)))->DOFGetPlanes(&this->unk4, &this->unk8, &this->unkC, &this->unk10);
}

void DepthOfFieldCE::Update() {
    ((Level *) (M2C_FIELD(&gb, Level **, 0x32C)))->DOFSetPlanes(this->unk14, this->unk18, this->unk1C, this->unk20);
}

s32 DepthOfFieldCE::LoadLine() {
    s32 var_r31_1577;

    var_r31_1577 = 0;
    if ((LoadFloat("nearBlur", &this->unk14) != 0) || (LoadFloat("nearClear", &this->unk18) != 0) || (LoadFloat("farClear", &this->unk1C) != 0) || (LoadFloat("farBlur", &this->unk20) != 0)) {
        var_r31_1577 = 1;
    }
    return var_r31_1577;
}

void DropShadowCE::Update() {

}

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
s32 DropShadowCE::LoadLine() {
    s32 var_r31_1634;

    var_r31_1634 = 0;
    LoadNode("node", &this->unk4, &this->unk8);
    if (((u8) M2C_ERROR(/* Read from unset register $r3 */) != 0) || (LoadFloat("scale", &this->unkC) != 0)) {
        var_r31_1634 = 1;
    }
    return var_r31_1634;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void TeleportCE::Update() {
    s8 sp25;
    s8 sp24;
    f32 sp20;
    f64 sp18;
    f64 sp10;
    s32 spC;
    s32 sp8;
    MKModel *temp_r3_1667;
    MKProp *temp_r3_1689;
    f64 temp_f1_1683;
    f64 temp_f2_1682;
    s32 temp_r3_1675;

    temp_r3_1667 = this->unk8;
    if ((temp_r3_1667 != NULL) && ((MKProp *) this->unk4 != NULL)) {
        spC = 0;
        temp_r3_1675 = MKModel_GetWorldMatrix(temp_r3_1667);
        sp8 = 0x38;
        temp_f2_1682 = M2C_FIELD(temp_r3_1675, f64 *, 0x30);
        temp_f1_1683 = M2C_FIELD(temp_r3_1675, f64 *, 0x38);
        sp10 = temp_f2_1682;
        sp18 = temp_f1_1683;
        sp20 = 0.0f;
        sp24 = 0;
        sp25 = 1;
        temp_r3_1689 = this->unk4;
        temp_r3_1689->Message(&sp8, 0, temp_f1_1683, temp_f2_1682);
    }
}
#endif

s32 TeleportCE::LoadLine() {
    s32 var_r31_1713;

    var_r31_1713 = 0;
    if ((LoadProp("prop", &this->unk4) != 0) || (LoadActorModel("pos", &this->unk8) != 0)) {
        var_r31_1713 = 1;
    }
    return var_r31_1713;
}

void TeleportCE::Init() {
    this->unk4 = NULL;
    this->unk8 = NULL;
}

#if 0 // DRAFT: function call 'Console_Execute(signed char *)' does not match
void ScriptCE::Enter() {
    s8 *temp_r3_1752;

    temp_r3_1752 = this->unk4;
    if (temp_r3_1752 != NULL) {
        Console_Execute(temp_r3_1752);
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
s32 ScriptCE::LoadLine() {
    s32 temp_r31_1782;
    s32 var_r31_1774;

    var_r31_1774 = 0;
    if (((MKIniLine *) KDSynkerPlayerEvent::pLine.__vptr)->IsField("ScriptCommand") != 0) {
        temp_r31_1782 = ((MKIniLine *) KDSynkerPlayerEvent::pLine.__vptr)->GetString(0);
        this->unk4 = ((UIStringTable *) (checked_cast<P16GameSynkerPlayer))->Add(15KDSynkerPlayer3>__FP15KDSynkerPlayer3((KDSynkerPlayer3 *) KDSynkerPlayerEvent::pSynker.__vptr) + 0x260, (s8 *) temp_r31_1782);
        var_r31_1774 = 1;
    }
    return var_r31_1774;
}
#endif

#if 0 // DRAFT: undefined identifier 'P16GameSynkerPlayer'
void ScriptCE::Deinit() {
    s8 *temp_r31_1806;

    temp_r31_1806 = this->unk4;
    if (temp_r31_1806 != NULL) {
        ((UIStringTable *) (checked_cast<P16GameSynkerPlayer))->Remove(15KDSynkerPlayer3>__FP15KDSynkerPlayer3((KDSynkerPlayer3 *) KDSynkerPlayerEvent::pSynker.__vptr) + 0x260, temp_r31_1806);
    }
}
#endif

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void ExplosionNodeCE::Update() {
    Matrix sp70;
    Matrix sp30;
    M2C_UNK sp2C;
    f64 sp20;
    f64 sp18;
    s16 sp10;
    s32 sp8;
    Animation *temp_r3_1852;
    MKModel *temp_r3_1833;
    s32 temp_r31_1850;

    temp_r3_1833 = this->unk4;
    if ((temp_r3_1833 != NULL) && ((u8) bIgnoreEvent == 0)) {
        M2C_STRUCT_COPY((s32) &sp2C + 4, MKModel_GetWorldMatrix(temp_r3_1833) - 4 + 4, 0x40);
        temp_r31_1850 = this->unk8;
        temp_r3_1852 = MKModel_GetAnimation(this->unk4);
        sp10 = (s16) temp_r31_1850;
        temp_r3_1852->CalculateMatrices(&sp70, 1, &sp10, &sp30);
        sp18 = (f64) sp70.unk30;
        sp20 = (f64) sp70.unk38;
        sp8 = 1;
        ((Explosion4 *) (M2C_FIELD(&gb, Explosion4 **, 0x2C0)))->Trigger(*((MKVector3 *) &sp18), this->unkC, 0U, NULL, 0, 1U, 1U, 1U, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
s32 ExplosionNodeCE::LoadLine() {
    s32 var_r31_1897;

    var_r31_1897 = 0;
    if ((LoadActorModel("actor", &this->unk4) != 0) || (LoadNode("node", &this->unk4, &this->unk8), (((u8) M2C_ERROR(/* Read from unset register $r3 */) == 0) == 0)) || (LoadFloat("scale", &this->unkC) != 0)) {
        var_r31_1897 = 1;
    }
    return var_r31_1897;
}
#endif

#if 0 // DRAFT: pointer/array required
void ExplosionCE::Update() {
    f64 sp18;
    f64 sp10;
    s32 sp8;
    MKModel *temp_r3_1938;

    temp_r3_1938 = this->unk4;
    if ((temp_r3_1938 != NULL) && ((u8) bIgnoreEvent == 0)) {
        MKModel_GetPosition(temp_r3_1938);
        sp10 = *M2C_ERROR(/* Read from unset register $r3 */);
        sp18 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f64 *, 8);
        sp8 = 1;
        ((Explosion4 *) (M2C_FIELD(&gb, Explosion4 **, 0x2C0)))->Trigger(*((MKVector3 *) &sp10), this->unk8, 0U, NULL, 0, 1U, 1U, 1U, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    }
}
#endif

s32 ExplosionCE::LoadLine() {
    s32 var_r31_1982;

    var_r31_1982 = 0;
    if ((LoadActorModel("pos", &this->unk4) != 0) || (LoadFloat("scale", &this->unk8) != 0)) {
        var_r31_1982 = 1;
    }
    return var_r31_1982;
}

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void AttachScaleOffsetCE::Update() {
    Matrix sp20;
    MKVector3 sp10;
    f32 temp_f31_2037;

    sp20.SetIdentity();
    MKModel_CalculateNodeWorldPosition(this->unk1C, this->unk20, &sp10);
    sp20.unk30 = M2C_BITWISE(f32, sp10);
    sp20.unk34 = sp10.unk4;
    sp20.unk38 = sp10.unk8;
    sp20.unk3C = 1.0f;
    sp20.Scale3x3(&sp20, this->unk8.unkC);
    temp_f31_2037 = this->unk8.unkC;
    this->unk8.unkC = 0.0f;
    sp20.Translate(&sp20, this->unk8);
    this->unk8.unkC = temp_f31_2037;
    MKModel_SetWorldMatrix(this->unk18, sp20);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
s32 AttachScaleOffsetCE::LoadLine() {
    s32 var_r31_2069;

    var_r31_2069 = 0;
    if ((LoadVector3("offset", &this->unk8) != 0) || (LoadActorModel("actor", &this->unk18) != 0) || (LoadFloat("scale", &this->unk8.unkC) != 0) || (LoadNode("node", &this->unk1C, &this->unk20), (((u8) M2C_ERROR(/* Read from unset register $r3 */) == 0) == 0))) {
        var_r31_2069 = 1;
    }
    return var_r31_2069;
}
#endif

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void ScaleCE::Update() {
    M2C_UNK sp40;
    M2C_UNK sp3C;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f64 temp_f0_2141;

    M2C_STRUCT_COPY((s32) &sp3C + 4, MKModel_GetWorldMatrix(this->unk18) - 4 + 4, 0x40);
    sp30 = sp70;
    sp38 = sp78;
    temp_f0_2141 = sp30 * 1.58735232e-314;
    sp10 = temp_f0_2141;
    sp20 = temp_f0_2141;
    sp18 = (f32) sp38 * -1.0f;
    sp28 = (f64) sp18;
    ((Matrix *) &sp40)->Translate((Matrix *) &sp40, *((MKVector3 *) &sp20));
    ((Matrix *) &sp40)->Scale3x3((Matrix *) &sp40, this->unk8);
    ((Matrix *) &sp40)->Translate((Matrix *) &sp40, *((MKVector3 *) &sp30));
    MKModel_SetWorldMatrix(this->unk18, *((Matrix *) &sp40));
}
#endif

s32 ScaleCE::LoadLine() {
    s32 var_r31_2186;

    var_r31_2186 = 0;
    if ((LoadActorModel("actor", &this->unk18) != 0) || (LoadVector3("scale", &this->unk8) != 0)) {
        var_r31_2186 = 1;
    }
    return var_r31_2186;
}

void CameraShakeCE::Update() {
    s8 sp20;
    f64 sp18;
    f64 sp10;
    s32 spC;
    s32 sp8;
    f64 temp_f1_2224;

    spC = 0;
    sp8 = 0x417;
    temp_f1_2224 = this->unk8;
    sp10 = temp_f1_2224;
    sp18 = this->unk10;
    sp20 = 1;
    M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, void ***, M2C_UNK, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp8, &gb, 0x417, temp_f1_2224);
}

s32 CameraShakeCE::LoadLine() {
    LoadVector3("offset", (MKVector3 *) &this->unk8);
}

void AlphaChangeCE::Update() {
    MKModel_GetAlpha(this->unk4);
    MKModel_SetAlpha(this->unk4, this->unk8 * gUpdateTimeDelta);
}

s32 AlphaChangeCE::LoadLine() {
    s32 var_r31_2290;

    var_r31_2290 = 0;
    if ((LoadActorModel("actor", &this->unk4) != 0) || (LoadFloat("alpha", &this->unk8) != 0)) {
        var_r31_2290 = 1;
    }
    return var_r31_2290;
}

void AlphaChangeCE::Init() {
    this->unk4 = NULL;
    this->unk8 = 1.0f;
}

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void AttachPropToRefPointCE::Update() {
    Matrix sp50;
    Matrix sp10;
    M2C_UNK spC;
    MKProp *temp_r3_2335;

    temp_r3_2335 = this->unk4;
    if ((void *) temp_r3_2335->unk8 != NULL) {
        MKModel_SetWorldMatrix(temp_r3_2335->unk4, Matrix::identity);
        MKModel_GetRefPointMatrix(this->unk8, this->unkC, &sp50, 1U);
        M2C_STRUCT_COPY((s32) &spC + 4, MKModel_GetWorldMatrix(this->unk4->unk4) - 4 + 4, 0x40);
        sp10.Multiply(&sp10, &sp50);
        MKModel_SetWorldMatrix(this->unk4->unk4, sp10);
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
s32 AttachPropToRefPointCE::LoadLine() {
    s32 temp_r3_2406;
    s8 *temp_r3_2395;
    s8 *temp_r3_2398;
    u8 temp_r29_2401;

    if (((MKIniLine *) KDSynkerPlayerEvent::pLine.__vptr)->IsField("refPoint") != 0) {
        temp_r3_2395 = ((MKIniLine *) KDSynkerPlayerEvent::pLine.__vptr)->GetString(0);
        temp_r3_2398 = strchr(temp_r3_2395, 0x3A);
        temp_r29_2401 = *temp_r3_2398;
        *temp_r3_2398 = 0;
        temp_r3_2406 = ((KDSP_ActorList *) (KDSynkerPlayerEvent::pSynker.__vptr + 0x100))->GetActorId(temp_r3_2395);
        *temp_r3_2398 = (s8) temp_r29_2401;
        ((KDSynkerPlayer3 *) KDSynkerPlayerEvent::pSynker.__vptr)->GetActorModel(temp_r3_2406);
        this->unk8 = M2C_ERROR(/* Read from unset register $r3 */);
        this->unkC = MKModel_GetRefPointIndex(this->unk8, temp_r3_2398 + 1);
        return 1U;
    }
    return LoadProp("prop", &this->unk4);
}
#endif

void AttachPropToRefPointCE::Init() {
    this->unk4 = NULL;
    this->unk8 = NULL;
    this->unkC = -1;
}

#if 0 // DRAFT: illegal implicit conversion from 'Animation *' to
void AttachPropCE::Update() {
    Matrix sp70;
    Animation sp18;
    s16 sp10;
    Animation *temp_r3_2474;
    s16 temp_r30_2473;
    s32 temp_r29_2471;

    if (((void *) this->unk4->unk8 != NULL) && (MKModel_GetAnimation(this->unk8) != NULL)) {
        MKModel_SetWorldMatrix(this->unk4->unk4, Matrix::identity);
        temp_r29_2471 = MKModel_GetWorldMatrix(this->unk8);
        temp_r30_2473 = (s16) this->unkC;
        temp_r3_2474 = MKModel_GetAnimation(this->unk8);
        sp10 = temp_r30_2473;
        temp_r3_2474->CalculateMatrices(&sp70, 1, &sp10, (Matrix *) temp_r29_2471);
        sp18.GetNodeOrigin(MKModel_GetAnimation(this->unk8));
        MKModel_SetPosition(this->unk4->unk4, *((MKVector3 *) &sp18));
        M2C_STRUCT_COPY((s32) &sp18.unk14 + 4, MKModel_GetWorldMatrix(this->unk4->unk4) - 4 + 4, 0x40);
        ((Matrix *) &sp18.unk18)->Multiply((Matrix *) &sp18.unk18, &sp70);
        MKModel_SetWorldMatrix(this->unk4->unk4, *((Matrix *) &sp18.unk18));
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
s32 AttachPropCE::LoadLine() {
    s32 var_r31_2532;

    var_r31_2532 = 0;
    if ((LoadProp("prop", &this->unk4) != 0) || (LoadNode("node", &this->unk8, &this->unkC), (((u8) M2C_ERROR(/* Read from unset register $r3 */) == 0) == 0))) {
        var_r31_2532 = 1;
    }
    return var_r31_2532;
}
#endif

void AttachPropCE::Init() {
    this->unk8 = NULL;
    this->unk4 = NULL;
}

void AttachActorToRefPointCE::Update() {
    Matrix sp10;

    MKModel_GetRefPointMatrix(this->unk8, this->unkC, &sp10, 1U);
    MKModel_SetWorldMatrix(this->unk4, sp10);
}

#if 0 // DRAFT: undefined identifier '__vptr'
s32 AttachActorToRefPointCE::LoadLine() {
    s32 temp_r3_2621;
    s8 *temp_r3_2610;
    s8 *temp_r3_2613;
    u8 temp_r29_2616;

    if (((MKIniLine *) KDSynkerPlayerEvent::pLine.__vptr)->IsField("refPoint") != 0) {
        temp_r3_2610 = ((MKIniLine *) KDSynkerPlayerEvent::pLine.__vptr)->GetString(0);
        temp_r3_2613 = strchr(temp_r3_2610, 0x3A);
        temp_r29_2616 = *temp_r3_2613;
        *temp_r3_2613 = 0;
        temp_r3_2621 = ((KDSP_ActorList *) (KDSynkerPlayerEvent::pSynker.__vptr + 0x100))->GetActorId(temp_r3_2610);
        *temp_r3_2613 = (s8) temp_r29_2616;
        ((KDSynkerPlayer3 *) KDSynkerPlayerEvent::pSynker.__vptr)->GetActorModel(temp_r3_2621);
        this->unk8 = M2C_ERROR(/* Read from unset register $r3 */);
        this->unkC = MKModel_GetRefPointIndex(this->unk8, temp_r3_2613 + 1);
        return 1U;
    }
    return LoadActorModel("actor", &this->unk4);
}
#endif

void AttachActorToRefPointCE::Init() {
    this->unk8 = NULL;
    this->unk4 = NULL;
    this->unkC = -1;
}

#if 0 // DRAFT: illegal implicit conversion from 'Animation *' to
void AttachCE::Update() {
    Matrix sp80;
    Animation sp18;
    s16 sp10;
    Animation *temp_r3_2682;
    s32 temp_r30_2679;
    s32 temp_r31_2680;

    if ((s32) this->unk24 != 0) {
        MKModel_SetWorldMatrix(this->unk18, Matrix::identity);
        temp_r30_2679 = MKModel_GetWorldMatrix(this->unk1C);
        temp_r31_2680 = this->unk20;
        temp_r3_2682 = MKModel_GetAnimation(this->unk1C);
        sp10 = (s16) temp_r31_2680;
        temp_r3_2682->CalculateMatrices(&sp80, 1, &sp10, (Matrix *) temp_r30_2679);
        sp18.GetNodeOrigin(MKModel_GetAnimation(this->unk1C));
        MKModel_SetPosition(this->unk18, *((MKVector3 *) &sp18));
        M2C_STRUCT_COPY((s32) &sp18.unk24 + 4, MKModel_GetWorldMatrix(this->unk18) - 4 + 4, 0x40);
        ((Matrix *) &sp18.unk28)->Multiply((Matrix *) &sp18.unk28, &sp80);
        ((Matrix *) &sp18.unk28)->Translate((Matrix *) &sp18.unk28, this->unk8);
        MKModel_SetWorldMatrix(this->unk18, *((Matrix *) &sp18.unk28));
        return;
    }
    MKModel_CalculateNodeWorldPosition(this->unk1C, this->unk20, (MKVector3 *) &sp18.unk10);
    sp80.SetIdentity();
    sp80.unk30 = M2C_BITWISE(f32, sp18.unk10);
    sp80.unk34 = M2C_BITWISE(f32, sp18.unk14);
    sp80.unk38 = M2C_BITWISE(f32, sp18.unk18);
    sp80.unk3C = 1.0f;
    sp80.Translate(&sp80, this->unk8);
    MKModel_SetWorldMatrix(this->unk18, sp80);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
s32 AttachCE::LoadLine() {
    s32 var_r31_2764;

    var_r31_2764 = 0;
    if ((LoadActorModel("actor", &this->unk18) != 0) || (LoadNode("node", &this->unk1C, &this->unk20), (((u8) M2C_ERROR(/* Read from unset register $r3 */) == 0) == 0)) || (LoadInt("bUseOrientation", &this->unk24) != 0) || (LoadVector3("offset", &this->unk8) != 0)) {
        var_r31_2764 = 1;
    }
    return var_r31_2764;
}
#endif

void AttachCE::Init() {
    this->unk1C = NULL;
    this->unk18 = NULL;
    this->unk8.unk0 = 0.0f;
    this->unk8.unk4 = 0.0f;
    this->unk8.unk8 = 0.0f;
}

/* KDSynkerPlayerEventCreationTableHelper<PlaySecondaryAnimCE>::Create (void) */
