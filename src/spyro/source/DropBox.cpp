#include "spyro/source/DropBox.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKBaseParticleSystem.h"
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
#include "unplaced_templates.h"
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

#if 0 // DRAFT: undefined identifier 'arg_sp58'
void DropBox::Drop() {
    f32 temp_f4_135;
    f32 var_f0_329;
    f32 var_f1_358;
    f32 var_f4_237;
    f64 temp_f1_240;
    f64 temp_f1_246;
    f64 temp_f1_250;
    s32 temp_r3_269;
    s32 var_r0_279;
    void *temp_r3_200;
    void *temp_r3_347;
    void *var_r0_188;
    void *var_r3_311;
    this->unk1B8 = 1e-45f;
    SetAnim(0);
    arg_sp58 = 0.0f;
    arg_sp5C = -8000.0f;
    arg_sp60 = 0.0f;
    arg_spC8 = (f64) arg_sp58;
    arg_spD0 = (f64) arg_sp60;
    M2C_ERROR(/* unknown instruction: psq_lx $f5, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f5, $f0 */);
    arg_sp80 = 0.0f;
    temp_f4_135 = M2C_FIELD((this->unk8 + 0x30), f32 *, 8);
    arg_sp78 = 0.0f;
    arg_sp7C = -100.0f;
    arg_sp50 = temp_f4_135 + (f32) arg_spD0;
    arg_spE8 = (f64) arg_sp78;
    arg_spD8 = arg_sp48;
    arg_spE0 = (f64) arg_sp50;
    arg_spF0 = (f64) arg_sp80;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f5, $f0 */);
    arg_spF8 = arg_sp68;
    arg_sp70 = temp_f4_135 + (f32) arg_spF0;
    arg_sp100 = (f64) arg_sp70;
    if (MKCollision_RayCollide(*((MKVector3 *) &arg_spF8), *((MKVector3 *) &arg_spD8), (MKCollisionResult *) &arg_sp170, (MKCollisionMode) 7, 0x0C000000) != 0) {
        this->unk1AC = arg_sp174;
        arg_sp30 = 0.0f;
        arg_sp28 = 0.0f;
        arg_sp2C = -3000.0f;
        this->unk1B8 = 1e-45f;
        M2C_FIELD(this, f64 *, 0x1A8) = (f64) arg_sp28;
        M2C_FIELD(this, f64 *, 0x1B0) = (f64) arg_sp30;
        arg_spB8 = (f64) arg_sp28;
        arg_spC0 = (f64) arg_sp30;
        if ((arg_sp1C0 != 0) && (arg_sp1B8 != NULL) && (var_r0_188 = M2C_FIELD(arg_sp1B8, void **, 8), ((var_r0_188 == NULL) == 0))) {

        } else {
            var_r0_188 = NULL;
        }
        if (var_r0_188 != NULL) {
            arg_sp10C = 0;
            temp_r3_200 = this->unk8;
            arg_spA8 = M2C_FIELD(temp_r3_200, f64 *, 0x30);
            arg_sp98 = M2C_FIELD(this, f64 *, 0x1A8);
            arg_spA0 = M2C_FIELD(this, f64 *, 0x1B0);
            arg_spB0 = M2C_FIELD(temp_r3_200, f64 *, 0x38);
            arg_sp108 = 0x91;
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            arg_sp38 = arg_sp18;
            arg_sp20 = (f32) arg_spB0 - arg_sp178;
            arg_sp40 = (f64) arg_sp20;
            var_f4_237 = (((f32) arg_sp40 * (f32) arg_sp40) + (((f32) arg_sp38 * (f32) arg_sp38) + (arg_sp3C * arg_sp3C))) / (((f32) arg_spA0 * (f32) arg_spA0) + (((f32) arg_sp98 * (f32) arg_sp98) + (arg_sp9C * arg_sp9C)));
            if (var_f4_237 > 0.0f) {
                temp_f1_240 = __frsqrte(var_f4_237);
                temp_f1_246 = 0.5 * temp_f1_240 * -(((f64) var_f4_237 * (temp_f1_240 * temp_f1_240)) - 3.0);
                temp_f1_250 = 0.5 * temp_f1_246 * -(((f64) var_f4_237 * (temp_f1_246 * temp_f1_246)) - 3.0);
                var_f4_237 = (f32) ((f64) var_f4_237 * (0.5 * temp_f1_250 * -(((f64) var_f4_237 * (temp_f1_250 * temp_f1_250)) - 3.0)));
            } else if (var_f4_237 < M2C_BITWISE(f32, 0.0)) {
                var_f4_237 = __float_nan;
            } else {
                arg_sp10 = var_f4_237;
                temp_r3_269 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
                switch (temp_r3_269) {              /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                        var_r0_279 = 1;
                    } else {
                        var_r0_279 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
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
            arg_sp120 = var_f4_237;
            arg_sp110 = arg_sp170;
            arg_sp118 = (f64) arg_sp178;
            if ((arg_sp1C0 != 0) && (arg_sp1B8 != NULL) && (var_r3_311 = M2C_FIELD(arg_sp1B8, void **, 8), ((var_r3_311 == NULL) == 0))) {

            } else {
                var_r3_311 = NULL;
            }
            M2C_FIELD(M2C_FIELD(var_r3_311, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&arg_sp108);
        }
    }
    if ((u8) M2C_FIELD(this, u8 *, 0x1C0) != 0) {
        var_f0_329 = 4500.0f + this->unk1AC;
    } else {
        var_f0_329 = this->unk204;
    }
    this->unk1A8 = var_f0_329;
    M2C_STRUCT_COPY((s32) &arg_sp12C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    temp_r3_347 = this->unk8;
    arg_sp88 = M2C_FIELD(temp_r3_347, f64 *, 0x30);
    arg_sp90 = M2C_FIELD(temp_r3_347, f64 *, 0x38);
    var_f1_358 = -((0.00022222222f * (arg_sp8C - this->unk1AC)) - 1.0f);
    if (var_f1_358 < 1.0f) {

    } else {
        var_f1_358 = 1.0f;
    }
    if (var_f1_358 > 0.1f) {

    } else {
        var_f1_358 = 0.1f;
    }
    arg_sp130.Scale3x3((Matrix *) &arg_sp130, var_f1_358);
    MKModel_SetWorldMatrix(this->unk1C4, *((Matrix *) &arg_sp130));
    MKModel_SetPosition(this->unk1C4, *((MKVector3 *) &arg_sp170));
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
    this->unk1C4->Deinit();
    temp_r31_414 = this->unk1C4;
    if (temp_r31_414 != NULL) {
        temp_r31_414->unk0 = &__vt;
        if (&temp_r31_414->unk10.unk30 != NULL) {
            temp_r31_414->unk10.unk30.Deinit();
        }
        if (&temp_r31_414->unk10.unk2C != NULL) {
            temp_r31_414->unk10.unk2C.Deinit();
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
    if ((this->unk1C8.LoadLine(arg0, "OnAllChildrenDead") != 0) && ((u32) this->unk1C8 != 0U)) {
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
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
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
                sp8.GetPos();
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

#if 0 // DRAFT: undefined identifier 'RemoveAllSpawnPoints'
void DropBox::SpawnEnemies() {
    MKModel *temp_r4_724;
    f32 temp_r0_747;
    f32 temp_r0_777;
    f32 temp_r0_807;
    f32 temp_r0_837;
    s32 temp_r0_734;
    s32 var_r29_670;
    s32 var_r31_668;
    void *temp_r27_683;
    this->unk1C4->RemoveAllSpawnPoints(0U);
    var_r31_668 = 0;
    this->unk1C4->unk10.unk8 = M2C_BITWISE(f32, this->unk18);
    var_r29_670 = 0;
loop_2:
    if ((var_r31_668 < 4) && (var_r31_668 < M2C_BITWISE(s32, this->unk200.unk0))) {
        M2C_STRUCT_COPY((s32) &arg_sp1C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
        temp_r27_683 = this + var_r29_670;
        MKModel_CalculateRefPointWorldPosition(this->unk4, M2C_FIELD(temp_r27_683, s32 *, 0x1E0), (MKVector3 *) &arg_sp10);
        arg_sp50 = arg_sp10;
        arg_sp54 = arg_sp14;
        arg_sp58 = arg_sp18;
        arg_sp5C = 1.0f;
        M2C_STRUCT_COPY(M2C_FIELD(temp_r27_683, SpawnPointObject **, 0x1DC) + 0xC + 4, (s32) &arg_sp1C + 4, 0x40);
        M2C_FIELD(M2C_FIELD(temp_r27_683, SpawnPointObject **, 0x1DC)->unk4, s32 *, 4) = 0x4000;
        this->unk1C4->AddSpawnPoint(M2C_FIELD(temp_r27_683, SpawnPointObject **, 0x1DC));
        var_r31_668 += 1;
        var_r29_670 += 8;
        goto loop_2;
    }
    this->unk1C4->AddSpawnPointEnd();
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
            this->unk1C4->TrySpawnItems(7, 1U);
            return;
        case 1:                                     /* switch 2 */
            this->unk1C4->TrySpawnItems(8, 1U);
            return;
        case 2:                                     /* switch 2 */
            this->unk1C4->TrySpawnItems(9, 1U);
            return;
        }
        break;
    case 1:                                         /* switch 1 */
        temp_r0_777 = this->unk200.unk4;
        switch (M2C_BITWISE(s32, temp_r0_777)) {    /* switch 3; irregular */
        case 0:                                     /* switch 3 */
            this->unk1C4->TrySpawnItems(0xA, 1U);
            return;
        case 1:                                     /* switch 3 */
            this->unk1C4->TrySpawnItems(0xB, 1U);
            return;
        case 2:                                     /* switch 3 */
            this->unk1C4->TrySpawnItems(0xC, 1U);
            return;
        }
        break;
    case 2:                                         /* switch 1 */
        temp_r0_807 = this->unk200.unk4;
        switch (M2C_BITWISE(s32, temp_r0_807)) {    /* switch 4; irregular */
        case 0:                                     /* switch 4 */
            this->unk1C4->TrySpawnItems(1, 1U);
            return;
        case 1:                                     /* switch 4 */
            this->unk1C4->TrySpawnItems(2, 1U);
            return;
        case 2:                                     /* switch 4 */
            this->unk1C4->TrySpawnItems(3, 1U);
            return;
        }
        break;
    case 3:                                         /* switch 1 */
        temp_r0_837 = this->unk200.unk4;
        switch (M2C_BITWISE(s32, temp_r0_837)) {    /* switch 5; irregular */
        case 0:                                     /* switch 5 */
            this->unk1C4->TrySpawnItems(4, 1U);
            return;
        case 1:                                     /* switch 5 */
            this->unk1C4->TrySpawnItems(5, 1U);
            return;
        case 2:                                     /* switch 5 */
            this->unk1C4->TrySpawnItems(6, 1U);
            break;
        }
        break;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'GetNumberActive'
void DropBox::Update() {
    f32 temp_f0_1019;
    f32 temp_f29_927;
    f32 temp_r0_913;
    f32 var_f1_1155;
    f32 var_f29_1248;
    f64 temp_f1_1217;
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
        this->unk1C4->GetNumberActive();
        if ((s32) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
            this->unk1FC = 0;
            this->unk1C8.Send((MKProp *) this);
        }
    }
    this->unk1BC -= gUpdateTimeDelta;
    temp_r0_913 = this->unk1B8;
    switch (M2C_BITWISE(s32, temp_r0_913)) {        /* switch 1; irregular */
    case 1:                                         /* switch 1 */
        temp_f29_927 = gUpdateTimeDelta;
        MKVector(0.0f, -3000.0f, 0.0f);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
        arg_sp140 = arg_sp40;
        arg_sp48 = arg_sp138 * temp_f29_927;
        arg_sp148 = (f64) arg_sp48;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        M2C_ERROR(/* unknown instruction: psq_stx $f0, $r31, $r0, 0x0, qr0 */);
        M2C_FIELD(this, f32 *, 0x1B0) = (f32) (M2C_FIELD(this, f32 *, 0x1B0) + (f32) arg_sp148);
        M2C_STRUCT_COPY((s32) &arg_sp1DC + 4, (s32) (this->unk8 - 4) + 4, 0x40);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
        arg_sp120 = arg_sp90;
        arg_sp98 = M2C_FIELD(this, f32 *, 0x1B0) * gUpdateTimeDelta;
        arg_sp128 = (f64) arg_sp98;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_sp170 = arg_sp80;
        arg_sp88 = arg_sp218 + (f32) arg_sp128;
        arg_sp178 = (f64) arg_sp88;
        if ((M2C_BITWISE(s32, this->unk200.unk8) == 0) && ((temp_cr0_eq_992 = (u8) M2C_FIELD(this, u8 *, 0x1C0) == 0, (temp_cr0_eq_992 != 0)) || ((temp_cr0_eq_992 == 0) && (temp_r3_995 = this->unk8, arg_sp110 = M2C_FIELD(temp_r3_995, f64 *, 0x30), arg_sp118 = M2C_FIELD(temp_r3_995, f64 *, 0x38), M2C_ERROR(/* unknown instruction: cror eq, lt, eq */), ((arg_sp114 == this->unk1A8) != 0))))) {
            this->unk200.unk8 = M2C_BITWISE(f32, KDSound_Play3d(GS_DreadwingScream1, this->unk8 + 0x30, 0U, -1, 0.0f, 0U));
        }
        temp_f0_1019 = this->unk1AC - 25.0f;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (arg_sp174 == temp_f0_1019) {
            arg_sp174 = temp_f0_1019;
            if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
                arg_sp184 = 0;
                MKVector(1.0f, 1.0f, 1.0f);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
                arg_sp180 = 0x417;
                arg_sp188 = arg_sp30;
                arg_sp38 = arg_spF8 * 250.0f;
                arg_sp198 = 1;
                arg_sp190 = (f64) arg_sp38;
                arg_sp100 = arg_sp30;
                arg_sp108 = (f64) arg_sp38;
                M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &arg_sp180, arg_sp30);
            }
            this->unk1B8 = 3e-45f;
            arg_sp18 = 0;
            arg_sp14 = 0xBA;
            Message(&arg_sp14, 0);
            temp_r3_1073 = this->unk8;
            arg_spE0 = M2C_FIELD(temp_r3_1073, f64 *, 0x30);
            arg_spE8 = M2C_FIELD(temp_r3_1073, f64 *, 0x38);
            temp_r3_1079 = checked_cast<DropBoxDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            arg_sp8 = 1;
            ((Explosion4 *) (M2C_FIELD(temp_r3_1079, Explosion4 **, 0x16C)))->Trigger(*((MKVector3 *) &arg_spE0), 0.66f, 1U, NULL, 0, 1U, 0U, 1U, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
            KDSound_Play3d(GS_DBIceShake, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
            KDSound_Stop((s32 *) &this->unk200.unk8);
            this->unkD0.Show(0U);
            arg_sp28 = 0;
            arg_sp24 = 0xE0;
            M2C_FIELD(*gMK, M2C_UNK (**)(void **, s32 *, M2C_UNK, M2C_UNK, f64 *, M2C_UNK, f32), 0x94)(gMK, &arg_sp24, 8, 0, &arg_sp170, 1, 250.0f);
        }
        arg_sp210 = (f32) arg_sp170;
        arg_sp214 = arg_sp174;
        arg_sp218 = (f32) arg_sp178;
        arg_sp21C = 1.0f;
        MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &arg_sp1E0));
        M2C_STRUCT_COPY((s32) &arg_sp19C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
        temp_r3_1144 = this->unk8;
        arg_spD0 = M2C_FIELD(temp_r3_1144, f64 *, 0x30);
        arg_spD8 = M2C_FIELD(temp_r3_1144, f64 *, 0x38);
        var_f1_1155 = -((0.00022222222f * (arg_spD4 - this->unk1AC)) - 1.0f);
        if (var_f1_1155 < 1.0f) {

        } else {
            var_f1_1155 = 1.0f;
        }
        if (var_f1_1155 > 0.1f) {

        } else {
            var_f1_1155 = 0.1f;
        }
        arg_sp1A0.Scale3x3((Matrix *) &arg_sp1A0, var_f1_1155);
        MKModel_SetWorldMatrix(this->unk1C4, *((Matrix *) &arg_sp1A0));
        arg_sp70 = (f32) arg_sp170;
        arg_sp74 = this->unk1AC;
        arg_sp78 = (f32) arg_sp178;
        arg_spC0 = (f64) arg_sp70;
        arg_spC8 = (f64) arg_sp78;
        MKModel_SetPosition(this->unk1C4, *((MKVector3 *) &arg_spC0));
        break;
    case 2:                                         /* switch 1 */
        temp_r5_1190 = this->unk8;
        temp_f2_1194 = M2C_FIELD(temp_r5_1190, f64 *, 0x30);
        arg_sp160 = temp_f2_1194;
        arg_sp168 = M2C_FIELD(temp_r5_1190, f64 *, 0x38);
        arg_sp20 = 0;
        arg_sp1C = 0xE0;
        M2C_FIELD(*gMK, M2C_UNK (**)(void **, s32 *, M2C_UNK, M2C_UNK, f64 *, M2C_UNK, M2C_UNK, f32, f64), 0x94)(gMK, &arg_sp1C, 8, 0, &arg_sp160, 1, 0, 350.0f, temp_f2_1194);
        if ((void **) M2C_FIELD(&gb, void ***, 0) != NULL) {
            temp_r4_1215 = this->unk8;
            temp_f1_1217 = M2C_FIELD(temp_r4_1215, f64 *, 0x30);
            arg_spA0 = temp_f1_1217;
            arg_spA8 = M2C_FIELD(temp_r4_1215, f64 *, 0x38);
            temp_r3_1224 = M2C_FIELD(M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), void *(**)(void *, f64), 0xC)(temp_r4_1215, temp_f1_1217), void **, 8);
            arg_spB0 = M2C_FIELD(temp_r3_1224, f64 *, 0x30);
            arg_spB8 = M2C_FIELD(temp_r3_1224, f64 *, 0x38);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            arg_sp150 = arg_sp60;
            arg_sp68 = (f32) arg_spB8 - (f32) arg_spA8;
            arg_sp158 = (f64) arg_sp68;
            var_f29_1248 = ((f32) arg_sp158 * (f32) arg_sp158) + (((f32) arg_sp150 * (f32) arg_sp150) + (arg_sp154 * arg_sp154));
            if (var_f29_1248 > 0.0f) {
                temp_f1_1251 = __frsqrte(var_f29_1248);
                temp_f1_1257 = 0.5 * temp_f1_1251 * -(((f64) var_f29_1248 * (temp_f1_1251 * temp_f1_1251)) - 3.0);
                temp_f1_1261 = 0.5 * temp_f1_1257 * -(((f64) var_f29_1248 * (temp_f1_1257 * temp_f1_1257)) - 3.0);
                var_f29_1248 = (f32) ((f64) var_f29_1248 * (0.5 * temp_f1_1261 * -(((f64) var_f29_1248 * (temp_f1_1261 * temp_f1_1261)) - 3.0)));
            } else if (var_f29_1248 < M2C_BITWISE(f32, 0.0)) {
                var_f29_1248 = __float_nan;
            } else {
                arg_sp10 = var_f29_1248;
                temp_r3_1280 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
                switch (temp_r3_1280) {             /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                        var_r0_1290 = 1;
                    } else {
                        var_r0_1290 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
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
                arg_sp224 = 0;
                arg_sp220 = 7;
                arg_sp248 = 2;
                arg_sp24C = this;
                arg_sp228 = arg_sp150;
                arg_sp230 = arg_sp158;
                arg_sp260 = 1;
                arg_sp26C = 2;
                arg_sp268 = 10.0f;
                arg_sp260 = 0;
                (s16) arg_sp260 = 1;
                arg_sp264 = -1;
                arg_sp238 = M2C_FIELD(&MKVector3::one, f64 *, 0);
                arg_sp240 = M2C_FIELD(&MKVector3::one, f64 *, 8);
                arg_sp270 = 0;
                if (this != NULL) {
                    arg_sp50.GetPos();
                    arg_sp250 = arg_sp50;
                    arg_sp258 = arg_sp58;
                } else {
                    arg_sp250 = 0.0f;
                    arg_sp254 = 0.0f;
                    arg_sp258 = 0.0f;
                }
                arg_sp270 = 0;
                M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), M2C_UNK (**)(void **, s32 *), 0x1C)(M2C_FIELD(&gb, void ***, 0), &arg_sp220);
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
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (this->unk1BC == 0.0f) {
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
    this->unk1C4->Init(EnemySpawnPool_Action, 0);
    this->unk1C4->LoadDone(6, 3, 0U, 1U);
    this->unk1C4->AddSpawnPointBegin(4);
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
        this->unk1C4->AddSpawnPoint(M2C_FIELD(temp_r27_1593, SpawnPointObject **, 0x1DC));
        var_r26_1581 += 1;
        var_r30_1583 += 8;
    } while (var_r26_1581 < 4);
    this->unk1C4->AddSpawnPointEnd();
}
#endif

#if 0 // DRAFT: expression syntax error
void DropBoxDescriptor::LoadDone() {
    this->unk16C = checked_cast<Explosion4 *, MKProp>(gMK->CreateProp("Explosion4"));
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
