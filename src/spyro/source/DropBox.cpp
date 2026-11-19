#include "spyro/source/DropBox.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/Explosion4.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/SpawnPointData.h"
#include "spyro/source/SpawnPointObject.h"
#include "spyro/source/SpawnerObject.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKCollision.h"
#include "common/Source/Str.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/PropFlags.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

extern s32 GS_DBIceShake;
extern s32 GS_DreadwingScream1;
extern void **gMK;
extern f32 gUpdateTimeDelta;
extern M2C_UNK gb;

void DropBox::SetAnim(int arg0) {
    this->unk80->SetAnim(M2C_FIELD((this + (arg0 * 4)), MKAnim **, 0x1D0), 1.0f, 0.0f, 0, -1);
}

#if 0 // DRAFT: function call 'KDSound_Stop(long *)' does not match
void DropBox::SetDefaults() {
    Enable();
    Activate();
    this->unk1B8 = 0.0f;
    M2C_FIELD(this, s8 *, 0x1C0) = 0;
    this->unk1FC = 0;
    KDSound_Stop((s32 *) &this->unk200.unk8);
    this->unk198 = 0.0f;
    M2C_FIELD(this, f32 *, 0x1AC) = 0.0f;
    M2C_FIELD(this, f32 *, 0x1B0) = 0.0f;
    this->unk200.unk4 = 0.0f;
    Shatterable::Reset();
}
#endif

#if 0 // DRAFT: illegal type
void DropBox::Drop() {
    MKCollisionResult sp170;
    Matrix sp130;
    M2C_UNK sp12C;
    f32 sp120;
    f64 sp118;
    f64 sp110;
    s32 sp10C;
    s32 sp108;
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
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f64 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f32 temp_f4_135;
    f32 var_f0_329;
    f32 var_f1_358;
    f32 var_f4_237;
    f64 temp_f0_150;
    f64 temp_f1_202;
    f64 temp_f1_240;
    f64 temp_f1_246;
    f64 temp_f1_250;
    f64 temp_f5_129;
    s32 temp_r3_269;
    s32 var_r0_279;
    void *temp_r3_123;
    void *temp_r3_200;
    void *temp_r3_347;
    void *var_r0_188;
    void *var_r3_311;

    this->unk1B8 = 1e-45f;
    SetAnim(0);
    sp58 = 0.0f;
    sp5C = -8000.0f;
    temp_r3_123 = this->unk8 + 0x30;
    sp60 = 0.0f;
    spC8 = (f64) sp58;
    spD0 = (f64) sp60;
    temp_f5_129 = M2C_FIELD(temp_r3_123, f64 *, 0);
    sp48 = temp_f5_129 + spC8;
    sp80 = 0.0f;
    temp_f4_135 = M2C_FIELD(temp_r3_123, f32 *, 8);
    sp78 = 0.0f;
    sp7C = -100.0f;
    sp50 = temp_f4_135 + (f32) spD0;
    spE8 = (f64) sp78;
    spD8 = sp48;
    spE0 = (f64) sp50;
    spF0 = (f64) sp80;
    temp_f0_150 = temp_f5_129 + spE8;
    sp68 = temp_f0_150;
    spF8 = temp_f0_150;
    sp70 = temp_f4_135 + (f32) spF0;
    sp100 = (f64) sp70;
    if (MKCollision_RayCollide(*((MKVector3 *) &spF8), *((MKVector3 *) &spD8), &sp170, (MKCollisionMode) 7, 0x0C000000) != 0) {
        this->unk1AC = sp170.unk4;
        sp30 = 0.0f;
        sp28 = 0.0f;
        sp2C = -3000.0f;
        this->unk1B8 = 1e-45f;
        M2C_FIELD(this, f64 *, 0x1A8) = (f64) sp28;
        M2C_FIELD(this, f64 *, 0x1B0) = (f64) sp30;
        spB8 = (f64) sp28;
        spC0 = (f64) sp30;
        if ((sp170.unk50 != 0) && (sp170.unk48 != NULL) && (var_r0_188 = M2C_FIELD(sp170.unk48, void **, 8), ((var_r0_188 == NULL) == 0))) {

        } else {
            var_r0_188 = NULL;
        }
        if (var_r0_188 != NULL) {
            sp10C = 0;
            temp_r3_200 = this->unk8;
            temp_f1_202 = M2C_FIELD(temp_r3_200, f64 *, 0x30);
            spA8 = temp_f1_202;
            sp98 = M2C_FIELD(this, f64 *, 0x1A8);
            spA0 = M2C_FIELD(this, f64 *, 0x1B0);
            spB0 = M2C_FIELD(temp_r3_200, f64 *, 0x38);
            sp108 = 0x91;
            sp18 = temp_f1_202 - M2C_BITWISE(f64, sp170);
            sp38 = sp18;
            sp20 = (f32) spB0 - sp170.unk8;
            sp40 = (f64) sp20;
            var_f4_237 = (((f32) sp40 * (f32) sp40) + (((f32) sp38 * (f32) sp38) + (unksp3C * unksp3C))) / (((f32) spA0 * (f32) spA0) + (((f32) sp98 * (f32) sp98) + (unksp9C * unksp9C)));
            if (var_f4_237 > 0.0f) {
                temp_f1_240 = __frsqrte(var_f4_237);
                temp_f1_246 = 0.5 * temp_f1_240 * -(((f64) var_f4_237 * (temp_f1_240 * temp_f1_240)) - 3.0);
                temp_f1_250 = 0.5 * temp_f1_246 * -(((f64) var_f4_237 * (temp_f1_246 * temp_f1_246)) - 3.0);
                var_f4_237 = (f32) ((f64) var_f4_237 * (0.5 * temp_f1_250 * -(((f64) var_f4_237 * (temp_f1_250 * temp_f1_250)) - 3.0)));
            } else if (var_f4_237 < M2C_BITWISE(f32, 0.0)) {
                var_f4_237 = __float_nan;
            } else {
                sp10 = var_f4_237;
                temp_r3_269 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_269) {              /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_279 = 1;
                    } else {
                        var_r0_279 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_279 = 5;
                    } else {
                        var_r0_279 = 3;
                    }
                    break;
                default:
                    var_r0_279 = 4;
                    break;
                }
                if (var_r0_279 == 1) {
                    var_f4_237 = __float_nan;
                }
            }
            sp120 = var_f4_237;
            sp110 = M2C_BITWISE(f64, sp170);
            sp118 = (f64) sp170.unk8;
            if ((sp170.unk50 != 0) && (sp170.unk48 != NULL) && (var_r3_311 = M2C_FIELD(sp170.unk48, void **, 8), ((var_r3_311 == NULL) == 0))) {

            } else {
                var_r3_311 = NULL;
            }
            M2C_FIELD(M2C_FIELD(var_r3_311, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp108);
        }
    }
    if ((u8) M2C_FIELD(this, u8 *, 0x1C0) != 0) {
        var_f0_329 = 4500.0f + this->unk1AC;
    } else {
        var_f0_329 = this->unk204;
    }
    this->unk1A8 = var_f0_329;
    M2C_STRUCT_COPY((s32) &sp12C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    temp_r3_347 = this->unk8;
    sp88 = M2C_FIELD(temp_r3_347, f64 *, 0x30);
    sp90 = M2C_FIELD(temp_r3_347, f64 *, 0x38);
    var_f1_358 = -((0.00022222222f * (unksp8C - this->unk1AC)) - 1.0f);
    if (var_f1_358 < 1.0f) {

    } else {
        var_f1_358 = 1.0f;
    }
    if (var_f1_358 > 0.1f) {

    } else {
        var_f1_358 = 0.1f;
    }
    sp130.Scale3x3(&sp130, var_f1_358);
    MKModel_SetWorldMatrix(this->unk1C4, sp130);
    MKModel_SetPosition(this->unk1C4, *((MKVector3 *) &sp170));
    this->unkD0.Show(1U);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'DropBox' to
void DropBox::Deinit() {
    MKModel *temp_r31_414;
    s32 temp_r30_403;
    s32 var_r29_400;
    s32 var_r31_401;

    var_r29_400 = 0;
    var_r31_401 = 0;
    do {
        temp_r30_403 = var_r31_401 + 0x1DC;
        ((SpawnPointObject *) (*(this + temp_r30_403)))->Deinit();
        operator delete(*(this + temp_r30_403));
        var_r29_400 += 1;
        var_r31_401 += 8;
    } while (var_r29_400 < 4);
    ((SpawnerObject *) this->unk1C4)->Deinit();
    temp_r31_414 = this->unk1C4;
    if (temp_r31_414 != NULL) {
        temp_r31_414->unk0 = &__vt;
        if (&temp_r31_414->unk10.unk30 != NULL) {
            ((EventMessage *) &temp_r31_414->unk10.unk30)->Deinit();
        }
        if (&temp_r31_414->unk10.unk2C != NULL) {
            ((EventMessage *) &temp_r31_414->unk10.unk2C)->Deinit();
        }
        operator delete(temp_r31_414);
    }
    MKModel_Destroy(this->unk1C4);
    KDSound_Stop((s32 *) &this->unk200.unk8);
    Shatterable::Deinit();
}
#endif

#if 0 // DRAFT: function call 'PropFlagsClear(unsigned long *, unsigned int)' does not
s32 DropBox::LoadLine(MKIniLine *arg0) {
    this->unk1FD = 0;
    PropFlagsClear((u32 *) &this->unk10, 0x40000U);
    if (Shatterable::LoadLine(arg0) != 0) {
        return 1U;
    }
    if ((((EventMessage *) &this->unk1C8)->LoadLine(arg0, "OnAllChildrenDead") != 0) && ((u32) this->unk1C8 != 0U)) {
        return 1U;
    }
    if (arg0->LoadInt("NumberToSpawn", (s32 *) &this->unk200, 0) != 0) {
        return 1U;
    }
    return (u8) (arg0->LoadInt("SpawnTier", (s32 *) &this->unk200.unk4, 0) != 0);
}
#endif

#if 0 // DRAFT: function call 'PropFlagsSet(unsigned long *, unsigned int)' does not match
void DropBox::Message(MKMessage *arg0) {
    s8 spA9;
    s8 spA8;
    s32 spA4;
    f32 spA0;
    s32 sp9C;
    s8 sp9A;
    s8 sp99;
    s8 sp98;
    f64 sp90;                                       /* compiler-managed */
    f64 sp88;                                       /* compiler-managed */
    DropBox *sp84;
    s32 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    s32 sp5C;
    s32 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f64 sp8;
    s32 temp_r0_521;
    void **temp_r3_553;
    void *temp_r3_557;
    void *temp_r3_565;
    void *temp_r4_564;

    temp_r0_521 = arg0->unk0;
    switch (temp_r0_521) {                          /* irregular */
    case 0xB5:
        if (M2C_BITWISE(s32, this->unk1B8) == 0) {
            SetAnim(0);
            SetPos(this->unk200);
            SetDefaults();
            PropFlagsSet((u32 *) &this->unk10, 0x40000U);
            M2C_FIELD(this, s8 *, 0x1C0) = 1;
            Drop();
        }
        break;
    case 0x12:
        temp_r3_553 = M2C_FIELD(checked_cast<CollisionObjectCollideMsg *, MKMessage>(arg0), void ***, 0xC);
        temp_r3_557 = M2C_FIELD(*temp_r3_553, void *(**)(void **), 0x2C)(temp_r3_553);
        if ((temp_r3_557 != NULL) && (M2C_FIELD(M2C_FIELD(temp_r3_557, void **, 0), s32 *, 0xC) & 0x40)) {
            temp_r4_564 = M2C_FIELD(temp_r3_557, void **, 8);
            temp_r3_565 = this->unk8;
            sp48 = M2C_FIELD(temp_r4_564, f64 *, 0x30);
            sp38 = M2C_FIELD(temp_r3_565, f64 *, 0x30);
            sp50 = M2C_FIELD(temp_r4_564, f64 *, 0x38);
            sp40 = M2C_FIELD(temp_r3_565, f64 *, 0x38);
            sp18 = sp48 - sp38;
            sp28 = sp18;
            sp5C = 0;
            sp20 = (f32) sp50 - (f32) sp40;
            unksp2C = 0.0f;
            sp30 = (f64) sp20;
            sp58 = 7;
            sp80 = 2;
            sp84 = this;
            sp60 = sp18;
            sp68 = (f64) sp20;
            sp98 = 1;
            spA4 = 2;
            spA0 = 10.0f;
            sp99 = 0;
            sp9A = 1;
            sp9C = -1;
            sp70 = M2C_FIELD(&MKVector3::one, f64 *, 0);
            sp78 = M2C_FIELD(&MKVector3::one, f64 *, 8);
            spA8 = 0;
            if (this != NULL) {
                ((MKProp *) &sp8)->GetPos();
                sp88 = sp8;
                sp90 = sp10;
            } else {
                sp88 = 0.0f;
                unksp8C = 0.0f;
                sp90 = 0.0f;
            }
            spA9 = 0;
            M2C_FIELD(M2C_FIELD(temp_r3_557, void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(temp_r3_557, &sp58);
        }
        break;
    }
    Shatterable::Message(arg0);
}
#endif

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void DropBox::SpawnEnemies() {
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    MKVector3 sp10;
    MKModel *temp_r4_724;
    f32 temp_r0_747;
    f32 temp_r0_777;
    f32 temp_r0_807;
    f32 temp_r0_837;
    s32 temp_r0_734;
    s32 var_r29_670;
    s32 var_r31_668;
    void *temp_r27_683;

    ((SpawnerObject *) this->unk1C4)->RemoveAllSpawnPoints(0U);
    var_r31_668 = 0;
    this->unk1C4->unk10.unk8 = M2C_BITWISE(f32, this->unk18);
    var_r29_670 = 0;
loop_2:
    if ((var_r31_668 < 4) && (var_r31_668 < M2C_BITWISE(s32, this->unk200.unk0))) {
        M2C_STRUCT_COPY((s32) &sp10.unkC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
        temp_r27_683 = this + var_r29_670;
        MKModel_CalculateRefPointWorldPosition(this->unk4, M2C_FIELD(temp_r27_683, s32 *, 0x1E0), &sp10);
        sp50 = M2C_BITWISE(f32, sp10);
        sp54 = sp10.unk4;
        sp58 = sp10.unk8;
        sp5C = 1.0f;
        M2C_STRUCT_COPY(M2C_FIELD(temp_r27_683, SpawnPointObject **, 0x1DC) + 0xC + 4, (s32) &sp10.unkC + 4, 0x40);
        M2C_FIELD(M2C_FIELD(temp_r27_683, SpawnPointObject **, 0x1DC)->unk4, s32 *, 4) = 0x4000;
        ((SpawnerObject *) this->unk1C4)->AddSpawnPoint(M2C_FIELD(temp_r27_683, SpawnPointObject **, 0x1DC));
        var_r31_668 += 1;
        var_r29_670 += 8;
        goto loop_2;
    }
    ((SpawnerObject *) this->unk1C4)->AddSpawnPointEnd();
    temp_r4_724 = this->unk1C4;
    if (M2C_BITWISE(s32, temp_r4_724->unk10.unk10) >= M2C_BITWISE(s32, temp_r4_724->unk10.unk14)) {
        temp_r4_724->unk10.unk10 = 0.0f;
    }
    temp_r0_734 = M2C_FIELD(checked_cast<DropBoxDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x170);
    switch (temp_r0_734) {                          /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        temp_r0_747 = this->unk200.unk4;
        switch (M2C_BITWISE(s32, temp_r0_747)) {    /* switch 2; irregular */
        case 0:                                     /* switch 2 */
            ((SpawnerObject *) this->unk1C4)->TrySpawnItems(7, 1U);
            return;
        case 1:                                     /* switch 2 */
            ((SpawnerObject *) this->unk1C4)->TrySpawnItems(8, 1U);
            return;
        case 2:                                     /* switch 2 */
            ((SpawnerObject *) this->unk1C4)->TrySpawnItems(9, 1U);
            return;
        }
        break;
    case 1:                                         /* switch 1 */
        temp_r0_777 = this->unk200.unk4;
        switch (M2C_BITWISE(s32, temp_r0_777)) {    /* switch 3; irregular */
        case 0:                                     /* switch 3 */
            ((SpawnerObject *) this->unk1C4)->TrySpawnItems(0xA, 1U);
            return;
        case 1:                                     /* switch 3 */
            ((SpawnerObject *) this->unk1C4)->TrySpawnItems(0xB, 1U);
            return;
        case 2:                                     /* switch 3 */
            ((SpawnerObject *) this->unk1C4)->TrySpawnItems(0xC, 1U);
            return;
        }
        break;
    case 2:                                         /* switch 1 */
        temp_r0_807 = this->unk200.unk4;
        switch (M2C_BITWISE(s32, temp_r0_807)) {    /* switch 4; irregular */
        case 0:                                     /* switch 4 */
            ((SpawnerObject *) this->unk1C4)->TrySpawnItems(1, 1U);
            return;
        case 1:                                     /* switch 4 */
            ((SpawnerObject *) this->unk1C4)->TrySpawnItems(2, 1U);
            return;
        case 2:                                     /* switch 4 */
            ((SpawnerObject *) this->unk1C4)->TrySpawnItems(3, 1U);
            return;
        }
        break;
    case 3:                                         /* switch 1 */
        temp_r0_837 = this->unk200.unk4;
        switch (M2C_BITWISE(s32, temp_r0_837)) {    /* switch 5; irregular */
        case 0:                                     /* switch 5 */
            ((SpawnerObject *) this->unk1C4)->TrySpawnItems(4, 1U);
            return;
        case 1:                                     /* switch 5 */
            ((SpawnerObject *) this->unk1C4)->TrySpawnItems(5, 1U);
            return;
        case 2:                                     /* switch 5 */
            ((SpawnerObject *) this->unk1C4)->TrySpawnItems(6, 1U);
            break;
        }
        break;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'MKVector'
void DropBox::Update() {
    s8 sp271;
    s8 sp270;
    s32 sp26C;
    f32 sp268;
    s32 sp264;
    s8 sp262;
    s8 sp261;
    s8 sp260;
    f64 sp258;                                      /* compiler-managed */
    f64 sp250;                                      /* compiler-managed */
    DropBox *sp24C;
    s32 sp248;
    f64 sp240;
    f64 sp238;
    f64 sp230;
    f64 sp228;
    s32 sp224;
    s32 sp220;
    Matrix sp1E0;
    Matrix sp1A0;
    M2C_UNK sp19C;
    s8 sp198;
    f64 sp190;
    f64 sp188;
    s32 sp184;
    s32 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f32 sp98;
    f64 sp90;
    f32 sp88;
    f64 sp80;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp68;
    f64 sp60;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    f32 sp10;
    s32 sp8;
    f32 temp_f0_1019;
    f32 temp_f29_927;
    f32 temp_r0_913;
    f32 var_f1_1155;
    f32 var_f29_1248;
    f64 temp_f0_933;
    f64 temp_f0_966;
    f64 temp_f0_978;
    f64 temp_f1_1217;
    f64 temp_f1_1225;
    f64 temp_f1_1251;
    f64 temp_f1_1257;
    f64 temp_f1_1261;
    f64 temp_f2_1194;
    s32 temp_cr0_eq_992;
    s32 temp_r3_1280;
    s32 var_r0_1290;
    void *temp_r3_1073;
    void *temp_r3_1079;
    void *temp_r3_1144;
    void *temp_r3_1224;
    void *temp_r3_995;
    void *temp_r4_1215;
    void *temp_r5_1190;

    if (((u8) this->unk1FD == 0) && ((u8) this->unk1FC != 0)) {
        ((SpawnerObject *) this->unk1C4)->GetNumberActive();
        if ((s32) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
            this->unk1FC = 0;
            ((EventMessage *) &this->unk1C8)->Send((MKProp *) this);
        }
    }
    this->unk1BC -= gUpdateTimeDelta;
    temp_r0_913 = this->unk1B8;
    switch (M2C_BITWISE(s32, temp_r0_913)) {        /* switch 1; irregular */
    case 1:                                         /* switch 1 */
        temp_f29_927 = gUpdateTimeDelta;
        MKVector(0.0f, -3000.0f, 0.0f);
        temp_f0_933 = sp130 * (f64) temp_f29_927;
        sp40 = temp_f0_933;
        sp140 = temp_f0_933;
        sp48 = sp138 * temp_f29_927;
        sp148 = (f64) sp48;
        M2C_FIELD(this, f64 *, 0x1A8) = (f64) (M2C_FIELD(this, f64 *, 0x1A8) + temp_f0_933);
        M2C_FIELD(this, f32 *, 0x1B0) = (f32) (M2C_FIELD(this, f32 *, 0x1B0) + (f32) sp148);
        M2C_STRUCT_COPY((s32) &sp1A0.unk3C + 4, (s32) (this->unk8 - 4) + 4, 0x40);
        temp_f0_966 = M2C_FIELD(this, f64 *, 0x1A8) * (f64) gUpdateTimeDelta;
        sp90 = temp_f0_966;
        sp120 = temp_f0_966;
        sp98 = M2C_FIELD(this, f32 *, 0x1B0) * gUpdateTimeDelta;
        sp128 = (f64) sp98;
        temp_f0_978 = sp1E0.unk30 + temp_f0_966;
        sp80 = temp_f0_978;
        sp170 = temp_f0_978;
        sp88 = sp1E0.unk38 + (f32) sp128;
        sp178 = (f64) sp88;
        if ((M2C_BITWISE(s32, this->unk200.unk8) == 0) && ((temp_cr0_eq_992 = (u8) M2C_FIELD(this, u8 *, 0x1C0) == 0, (temp_cr0_eq_992 != 0)) || ((temp_cr0_eq_992 == 0) && (temp_r3_995 = this->unk8, sp110 = M2C_FIELD(temp_r3_995, f64 *, 0x30), sp118 = M2C_FIELD(temp_r3_995, f64 *, 0x38), ((unksp114 <= this->unk1A8) != 0))))) {
            this->unk200.unk8 = M2C_BITWISE(f32, KDSound_Play3d(GS_DreadwingScream1, this->unk8 + 0x30, 0U, -1, 0.0f, 0U));
        }
        temp_f0_1019 = this->unk1AC - 25.0f;
        if (unksp174 <= temp_f0_1019) {
            unksp174 = temp_f0_1019;
            if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
                sp184 = 0;
                MKVector(1.0f, 1.0f, 1.0f);
                sp30 = spF0 * 5.593163344e-315;
                sp180 = 0x417;
                sp188 = sp30;
                sp38 = spF8 * 250.0f;
                sp198 = 1;
                sp190 = (f64) sp38;
                sp100 = sp30;
                sp108 = (f64) sp38;
                M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp180, sp30);
            }
            this->unk1B8 = 3e-45f;
            sp18 = 0;
            sp14 = 0xBA;
            Message(&sp14, 0);
            temp_r3_1073 = this->unk8;
            spE0 = M2C_FIELD(temp_r3_1073, f64 *, 0x30);
            spE8 = M2C_FIELD(temp_r3_1073, f64 *, 0x38);
            temp_r3_1079 = checked_cast<DropBoxDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            sp8 = 1;
            ((Explosion4 *) (M2C_FIELD(temp_r3_1079, Explosion4 **, 0x16C)))->Trigger(*((MKVector3 *) &spE0), 0.66f, 1U, NULL, 0, 1U, 0U, 1U, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
            KDSound_Play3d(GS_DBIceShake, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
            KDSound_Stop((s32 *) &this->unk200.unk8);
            this->unkD0.Show(0U);
            sp28 = 0;
            sp24 = 0xE0;
            M2C_FIELD(*gMK, M2C_UNK (**)(void **, s32 *, M2C_UNK, M2C_UNK, f64 *, M2C_UNK, f32), 0x94)(gMK, &sp24, 8, 0, &sp170, 1, 250.0f);
        }
        sp1E0.unk30 = (f32) sp170;
        sp1E0.unk34 = unksp174;
        sp1E0.unk38 = (f32) sp178;
        sp1E0.unk3C = 1.0f;
        MKModel_SetWorldMatrix(this->unk4, sp1E0);
        M2C_STRUCT_COPY((s32) &sp19C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
        temp_r3_1144 = this->unk8;
        spD0 = M2C_FIELD(temp_r3_1144, f64 *, 0x30);
        spD8 = M2C_FIELD(temp_r3_1144, f64 *, 0x38);
        var_f1_1155 = -((0.00022222222f * (unkspD4 - this->unk1AC)) - 1.0f);
        if (var_f1_1155 < 1.0f) {

        } else {
            var_f1_1155 = 1.0f;
        }
        if (var_f1_1155 > 0.1f) {

        } else {
            var_f1_1155 = 0.1f;
        }
        sp1A0.Scale3x3(&sp1A0, var_f1_1155);
        MKModel_SetWorldMatrix(this->unk1C4, sp1A0);
        sp70 = (f32) sp170;
        sp74 = this->unk1AC;
        sp78 = (f32) sp178;
        spC0 = (f64) sp70;
        spC8 = (f64) sp78;
        MKModel_SetPosition(this->unk1C4, *((MKVector3 *) &spC0));
        break;
    case 2:                                         /* switch 1 */
        temp_r5_1190 = this->unk8;
        temp_f2_1194 = M2C_FIELD(temp_r5_1190, f64 *, 0x30);
        sp160 = temp_f2_1194;
        sp168 = M2C_FIELD(temp_r5_1190, f64 *, 0x38);
        sp20 = 0;
        sp1C = 0xE0;
        M2C_FIELD(*gMK, M2C_UNK (**)(void **, s32 *, M2C_UNK, M2C_UNK, f64 *, M2C_UNK, M2C_UNK, f32, f64), 0x94)(gMK, &sp1C, 8, 0, &sp160, 1, 0, 350.0f, temp_f2_1194);
        if ((void **) M2C_FIELD(&gb, void ***, 0) != NULL) {
            temp_r4_1215 = this->unk8;
            temp_f1_1217 = M2C_FIELD(temp_r4_1215, f64 *, 0x30);
            spA0 = temp_f1_1217;
            spA8 = M2C_FIELD(temp_r4_1215, f64 *, 0x38);
            temp_r3_1224 = M2C_FIELD(M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), void *(**)(void *, f64), 0xC)(temp_r4_1215, temp_f1_1217), void **, 8);
            temp_f1_1225 = M2C_FIELD(temp_r3_1224, f64 *, 0x30);
            spB0 = temp_f1_1225;
            spB8 = M2C_FIELD(temp_r3_1224, f64 *, 0x38);
            sp60 = temp_f1_1225 - spA0;
            sp150 = sp60;
            sp68 = (f32) spB8 - (f32) spA8;
            sp158 = (f64) sp68;
            var_f29_1248 = ((f32) sp158 * (f32) sp158) + (((f32) sp150 * (f32) sp150) + (unksp154 * unksp154));
            if (var_f29_1248 > 0.0f) {
                temp_f1_1251 = __frsqrte(var_f29_1248);
                temp_f1_1257 = 0.5 * temp_f1_1251 * -(((f64) var_f29_1248 * (temp_f1_1251 * temp_f1_1251)) - 3.0);
                temp_f1_1261 = 0.5 * temp_f1_1257 * -(((f64) var_f29_1248 * (temp_f1_1257 * temp_f1_1257)) - 3.0);
                var_f29_1248 = (f32) ((f64) var_f29_1248 * (0.5 * temp_f1_1261 * -(((f64) var_f29_1248 * (temp_f1_1261 * temp_f1_1261)) - 3.0)));
            } else if (var_f29_1248 < M2C_BITWISE(f32, 0.0)) {
                var_f29_1248 = __float_nan;
            } else {
                sp10 = var_f29_1248;
                temp_r3_1280 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_1280) {             /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_1290 = 1;
                    } else {
                        var_r0_1290 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_1290 = 5;
                    } else {
                        var_r0_1290 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_1290 = 4;
                    break;
                }
                if (var_r0_1290 == 1) {
                    var_f29_1248 = __float_nan;
                }
            }
            if (var_f29_1248 < M2C_FIELD(MKModel_GetBoundingVolume(this->unk4, (SubObjectType) 0, -1), f32 *, 0xC)) {
                sp224 = 0;
                sp220 = 7;
                sp248 = 2;
                sp24C = this;
                sp228 = sp150;
                sp230 = sp158;
                sp260 = 1;
                sp26C = 2;
                sp268 = 10.0f;
                sp261 = 0;
                sp262 = 1;
                sp264 = -1;
                sp238 = M2C_FIELD(&MKVector3::one, f64 *, 0);
                sp240 = M2C_FIELD(&MKVector3::one, f64 *, 8);
                sp270 = 0;
                if (this != NULL) {
                    ((MKProp *) &sp50)->GetPos();
                    sp250 = sp50;
                    sp258 = sp58;
                } else {
                    sp250 = 0.0f;
                    unksp254 = 0.0f;
                    sp258 = 0.0f;
                }
                sp271 = 0;
                M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), M2C_UNK (**)(void **, s32 *), 0x1C)(M2C_FIELD(&gb, void ***, 0), &sp220);
            }
        }
        if (M2C_BITWISE(s32, this->unk200.unk0) != 0) {
            SpawnEnemies();
        }
        this->unk1FC = 1;
        this->unk1BC = 3.0f;
        this->unk1B8 = 4e-45f;
        break;
    case 3:                                         /* switch 1 */
        if (this->unk1BC <= 0.0f) {
            if ((u8) this->unk1FD != 0) {
                Deactivate();
                Disable();
            } else {
                SetPos(this->unk200);
                this->unk1B8 = 0.0f;
            }
        }
        break;
    }
    Shatterable::Update();
}
#endif

void DropBox::Resolve() {
    f64 sp10;
    f64 sp8;
    MKAnimScript *temp_r31_1439;
    f64 temp_f0_1463;
    f64 temp_f1_1462;
    void *temp_r5_1459;
    void *var_r3_1451;

    Shatterable::Resolve();
    temp_r31_1439 = this->unk80;
    if (temp_r31_1439->Exists("Idle") != 0) {
        var_r3_1451 = temp_r31_1439->GetAnim("Idle");
    } else {
        var_r3_1451 = NULL;
    }
    M2C_FIELD(this, void **, 0x1D0) = var_r3_1451;
    InitSpawnerObject();
    temp_r5_1459 = this->unk8;
    temp_f1_1462 = M2C_FIELD(temp_r5_1459, f64 *, 0x30);
    temp_f0_1463 = M2C_FIELD(temp_r5_1459, f64 *, 0x38);
    sp8 = temp_f1_1462;
    M2C_FIELD(this, f64 *, 0x200) = temp_f1_1462;
    sp10 = temp_f0_1463;
    M2C_FIELD(this, f64 *, 0x208) = temp_f0_1463;
    SetAnim(0);
    this->unkD0.Init(this->unk1C4, (MKProp *) this, 2000.0f, NULL, 1500.0f);
    this->unkD0.Show(0U);
}

void DropBox::LoadDone() {
    Shatterable::LoadDone();
    this->unk1C4 = MKModel_Create("P9022_DropBoxShadow", NULL, 2, NULL);
}

void DropBox::Init() {
    Shatterable::Init();
    this->unk1B8 = 0.0f;
    this->unk200.unk8 = 0.0f;
    this->unk1FD = 1;
    M2C_FIELD(this, s8 *, 0x1C0) = 0;
    this->unk1BC = 0.0f;
    this->unk1FC = 0;
    this->unk200.unk4 = 0.0f;
    this->unk200.unk0 = 6e-45f;
}

#if 0 // DRAFT: function call 'operator new(unsigned int, int, int)' does not match
void DropBox::InitSpawnerObject() {
    MKModel *temp_r29_1550;
    SpawnPointData *temp_r28_1604;
    s32 var_r26_1581;
    s32 var_r30_1583;
    void *temp_r27_1593;

    operator new(0x50U, NULL, 0);
    temp_r29_1550 = M2C_ERROR(/* Read from unset register $r3 */);
    if (temp_r29_1550 != NULL) {
        temp_r29_1550->unk0 = &__vt;
        temp_r29_1550->unk10.unk2C = 0.0f;
        ((EventMessage *) (temp_r29_1550 + 0x3C))->Init();
        temp_r29_1550->unk10.unk30 = 0.0f;
        ((EventMessage *) (temp_r29_1550 + 0x40))->Init();
    }
    this->unk1C4 = temp_r29_1550;
    ((SpawnerObject *) this->unk1C4)->Init(EnemySpawnPool_Action, 0);
    ((SpawnerObject *) this->unk1C4)->LoadDone(6, 3, 0U, 1U);
    ((SpawnerObject *) this->unk1C4)->AddSpawnPointBegin(4);
    var_r26_1581 = 0;
    var_r30_1583 = 0;
    do {
        temp_r27_1593 = this + var_r30_1583;
        M2C_FIELD(temp_r27_1593, s32 *, 0x1E0) = (s32) Tools_GetMatchingRefPointIndex(this->unk4, Str_Printf("r_fxemit%d", var_r26_1581));
        operator new(0x60U, NULL, 0);
        M2C_FIELD(temp_r27_1593, SpawnPointObject **, 0x1DC) = (SpawnPointObject *) M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x28U, NULL, 0);
        temp_r28_1604 = M2C_ERROR(/* Read from unset register $r3 */);
        if (temp_r28_1604 != NULL) {
            temp_r28_1604->__vptr = &__vt;
            temp_r28_1604->__vptr = &__vt;
            M2C_FIELD(temp_r28_1604, s32 *, 8) = 0;
            ((EventMessage *) (temp_r28_1604 + 8))->Init();
            M2C_FIELD(temp_r28_1604, s32 *, 0xC) = 0;
            ((EventMessage *) (temp_r28_1604 + 0xC))->Init();
            M2C_FIELD(temp_r28_1604, s32 *, 0x10) = 0;
            ((EventMessage *) (temp_r28_1604 + 0x10))->Init();
            M2C_FIELD(temp_r28_1604, s32 *, 0x14) = 0;
            ((EventMessage *) (temp_r28_1604 + 0x14))->Init();
        }
        ((SpawnPointObject *) (M2C_FIELD(temp_r27_1593, SpawnPointObject **, 0x1DC)))->Init(temp_r28_1604);
        ((SpawnPointObject *) (M2C_FIELD(temp_r27_1593, SpawnPointObject **, 0x1DC)))->LoadDone();
        ((SpawnerObject *) this->unk1C4)->AddSpawnPoint(M2C_FIELD(temp_r27_1593, SpawnPointObject **, 0x1DC));
        var_r26_1581 += 1;
        var_r30_1583 += 8;
    } while (var_r26_1581 < 4);
    ((SpawnerObject *) this->unk1C4)->AddSpawnPointEnd();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'Explosion4 *' to
void DropBoxDescriptor::LoadDone() {
    this->unk16C = checked_cast<Explosion4 *, MKProp>(((MKSceneManager *) gMK)->CreateProp("Explosion4"));
    ShatterableDescriptor::LoadDone();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
s32 DropBoxDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_1683;

    var_r31_1683 = 0;
    if ((ShatterableDescriptor::LoadLine(arg0) != 0) || (arg0->LoadInt("Element", &this->unk170, 0) != 0) || (KDSound_LoadLine(arg0, "sndDrop", &this->unk174) != 0)) {
        var_r31_1683 = 1;
    }
    return var_r31_1683;
}
#endif

void DropBoxDescriptor::Init() {
    ShatterableDescriptor::Init();
    this->unk174 = 0;
    this->unk16C = 0;
}
