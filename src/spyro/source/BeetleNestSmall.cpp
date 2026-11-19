#include "spyro/source/BeetleNestSmall.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/EnemySpawner.h"
#include "spyro/source/GoopFX.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/KDSynkerPlayer3.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/SpawnPointObject.h"
#include "spyro/source/shatterwaypointspawn.h"
#include "unplaced_templates.h"
#include "common/Source/MKModel.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

extern MKSceneManager *gMK;
extern M2C_UNK gb;
#if 0 // DRAFT: undefined identifier 'FindInteractivePropMsg'
static s8 lit_stringBase0[0x12] = {
    0x73,
    0x70,
    0x61,
    0x77,
    0x6E,
    0,
    0x69,
    0x64,
    0x6C,
    0x65,
    0,
    0x47,
    0x6F,
    0x6F,
    0x70,
    0x46,
    0x58,
    0,
}; /* const */

void BeetleNestSmall::Message(MKMessage *arg0) {
    s32 temp_r0_47;
    void *temp_r3_60;

    temp_r0_47 = arg0->unk0;
    switch (temp_r0_47) {                           /* irregular */
    case 0x79:
        temp_r3_60 = checked_cast<FindInteractivePropMsg *, MKMessage>(arg0);
        if ((s32) M2C_FIELD(temp_r3_60, s32 *, 8) == 4) {
            M2C_FIELD(temp_r3_60, BeetleNestSmall **, 0xC) = this;
            return;
        }
        return;
    case 0xB5:
        this->unk198.FunctionOn();
    default:
block_10:
        Shatterable::Message(arg0);
        break;
    case 0xB4:
        this->unk198.FunctionOff();
        goto block_10;
    }
}
#endif

#if 0 // DRAFT: ')' expected
void BeetleNestSmall::Update() {
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
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    KDSynkerPlayer3 *temp_r3_137;
    SpawnPointObject *temp_r30_253;
    f32 temp_f3_194;
    s32 temp_r3_99;
    s32 temp_r4_252;
    s32 var_r28_246;
    u32 *temp_r29_242;
    u8 var_r30_134;
    void *temp_r29_136;
    void *temp_r3_187;
    void *temp_r3_236;

    Shatterable::Update();
    temp_r3_99 = this->unk80->unk2C;
    if ((temp_r3_99 & 1) && !(temp_r3_99 & 2)) {
        this->unk80->SetAnim(M2C_FIELD(checked_cast<BeetleNestSmallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKAnim **, 0x170), 1.0f, 0.0f, 0, -1);
    }
    if ((this->unk198.IsSpawning() != 0) && (IsDead() != 0)) {
        this->unk198.FunctionOff();
    }
    if (this->unk198.IsSpawning() != 0) {
        var_r30_134 = 0;
        temp_r29_136 = M2C_FIELD(&gb, void **, 0xC);
        temp_r3_137 = M2C_FIELD(temp_r29_136, KDSynkerPlayer3 **, 0x78);
        if (((temp_r3_137 != NULL) && (temp_r3_137->IsPlaying() != 0)) || (((s32) M2C_FIELD(temp_r29_136, s32 *, 0x74) == 2) && (((KDStateMachine<CutsceneSystem> *) (temp_r29_136 + 0x24))->GetState() == 2))) {
            var_r30_134 = 1;
        }
        if ((var_r30_134 == 0) && ((u32 *) this->unk1A8.unk44 > 0)) {
            M2C_FIELD(this->unk198, M2C_UNK (**)(f32 *), 0xC)(&this->unk198);
            if (this->unk198.TrySpawnItem(M2C_FIELD(checked_cast<BeetleNestSmallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x16C)) != NULL) {
                this->unk80->SetAnim(M2C_FIELD(checked_cast<BeetleNestSmallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKAnim **, 0x174), 1.0f, 0.0f, 0, -1);
                MKModel_CalculateRefPointWorldPosition(this->unk4, this->unk208, &sp98);
                temp_r3_187 = checked_cast<BeetleNestSmallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
                temp_f3_194 = M2C_FIELD((this->unk8 + 0x10), f32 *, 8);
                sp68 = sp38;
                sp40 = temp_f3_194 * 100.0f;
                sp70 = (f64) sp40;
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                sp78 = sp28;
                sp30 = sp98.unk8 + (f32) sp70;
                sp80 = (f64) sp30;
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
                sp20 = temp_f3_194 * 5000.0f;
                sp8 = 1.0f;
                spC = 1.0f;
                sp10 = 1.0f;
                sp14 = 1.0f;
                sp58 = sp18;
                sp60 = (f64) sp20;
                sp48 = (f64) sp8;
                sp50 = (f64) sp10;
                temp_r3_236 = M2C_FIELD(temp_r3_187, void **, 0x178);
                M2C_FIELD(M2C_FIELD(temp_r3_236, void **, 0x44), M2C_UNK (**)(void *, f64 *, f64 *, f64 *, f32, f64, f64, f64), 0x3C)(temp_r3_236, &sp78, &sp58, &sp48, 3.0f, (f64) sp8, (f64) sp20, sp18);
            }
        }
    }
    temp_r29_242 = this->unk1A8.unk44;
    if (temp_r29_242 != NULL) {
        var_r28_246 = 0;
loop_21:
        if (var_r28_246 < temp_r29_242) {
            temp_r4_252 = this->unk208;
            temp_r30_253 = this->unk198.GetSpawnPoint(var_r28_246);
            if ((u32) temp_r4_252 != -1U) {
                MKModel_CalculateRefPointWorldPosition(this->unk4, temp_r4_252, &sp88);
                temp_r30_253->unk40 = M2C_BITWISE(f32, sp88);
                temp_r30_253->unk44 = sp88.unk4;
                temp_r30_253->unk48 = sp88.unk8;
                temp_r30_253->unk4C = 1.0f;
            }
            var_r28_246 += 1;
            goto loop_21;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk208'
void BeetleNestSmall::LoadDone() {
    f64 sp20;
    f64 sp18;
    MKVector3 sp8;
    SpawnPointObject *temp_r3_316;
    s32 temp_r4_338;
    s32 var_r27_310;
    s32 var_r31_311;
    u32 *temp_r28_302;
    void *temp_r30_320;
    void *temp_r3_331;

    ShatterWaypointSpawn::LoadDone();
    this->unk208 = (s32) Tools_GetMatchingRefPointIndex(this->unk4, lit_stringBase0);
    temp_r28_302 = this->unk1A8.unk44;
    this->unk1A8.unk20 = 0.0f;
    this->unk1A8.unk24 = 5.0f;
    M2C_FIELD(this, u8 *, 0x1F4) = (u8) (M2C_FIELD(this, u8 *, 0x1F4) | 0x10);
    if (temp_r28_302 != NULL) {
        var_r27_310 = 0;
        var_r31_311 = 0;
loop_5:
        if (var_r27_310 < temp_r28_302) {
            temp_r3_316 = this->unk198.GetSpawnPoint(var_r27_310);
            temp_r30_320 = checked_cast<EnemySpawnPointData *, SpawnPointData>(temp_r3_316->unk4);
            operator new(0x30U, NULL, 0);
            M2C_FIELD(temp_r30_320, KDPathSegment **, 0x1C) = (KDPathSegment *) M2C_ERROR(/* Read from unset register $r3 */);
            ((KDPathSegment *) (M2C_FIELD(temp_r30_320, KDPathSegment **, 0x1C)))->Init();
            temp_r3_331 = this->unk1A8.unk40.unk0 + var_r31_311;
            sp18 = M2C_FIELD(temp_r3_331, f64 *, 0);
            sp20 = M2C_FIELD(temp_r3_331, f64 *, 8);
            ((KDPathSegment *) (M2C_FIELD(temp_r30_320, KDPathSegment **, 0x1C)))->CopyWaypointArray((MKVector3 *) &sp18, 1);
            temp_r4_338 = this->unk208;
            if ((u32) temp_r4_338 != -1U) {
                MKModel_CalculateRefPointWorldPosition(this->unk4, temp_r4_338, &sp8);
                temp_r3_316->unk40 = M2C_BITWISE(f32, sp8);
                temp_r3_316->unk44 = sp8.unk4;
                temp_r3_316->unk48 = sp8.unk8;
                temp_r3_316->unk4C = 1.0f;
            }
            var_r27_310 += 1;
            var_r31_311 += 0x10;
            goto loop_5;
        }
    }
}
#endif

void BeetleNestSmall::Init() {
    ShatterWaypointSpawn::Init();
}

#if 0 // DRAFT: expression syntax error
void BeetleNestSmallDescriptor::LoadDone() {
    ShatterableDescriptor::LoadDone();
    this->unk170 = this->unk34->GetAnim(&lit_stringBase0[6]);
    this->unk174 = this->unk34->GetAnim(lit_stringBase0);
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void BeetleNestSmallDescriptor::Init() {
    ShatterWaypointSpawnDescriptor::Init();
    this->unk174 = 0;
    this->unk170 = 0;
    this->unk178 = checked_cast<GoopFX *, MKProp>(gMK->CreateProp(&lit_stringBase0[0xB]));
}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<BeetleNestSmallDescriptor *, MKPropDescriptor>(MKPropDescriptor *arg0) {

}
#endif
