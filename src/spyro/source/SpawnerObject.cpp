#include "spyro/source/SpawnerObject.h"
#include "common/Source/Frustum.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/SpawnPointObject.h"
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

M2C_UNK free(u32 *);                                /* extern */
u32 *malloc(s32);                                   /* extern */
extern M2C_UNK gEmptyPtrList;
extern M2C_UNK gEmptyPtrListDL;
extern s32 gViewSeed;
extern M2C_UNK gb;

void SpawnerObject::AllDied() {
    this->unk4C |= 8;
    this->unk3C.Send(NULL);
}

#if 0 // DRAFT: pointer/array required
void SpawnerObject::AllChildrenDied(SpawnerObject *arg0) {
    s32 temp_cr0_eq_44;
    s32 var_r8_36;
    u8 var_r6_33;
    void *temp_r5_55;

    var_r6_33 = 1;
    var_r8_36 = this->unk8.unk0;
loop_7:
    temp_r5_55 = *var_r8_36;
    if (temp_r5_55 != NULL) {
        if ((u32) M2C_FIELD(temp_r5_55, u32 *, 0) == arg0) {
            M2C_FIELD(temp_r5_55, u8 *, 4) = 1U;
        }
        temp_cr0_eq_44 = var_r6_33 == 0;
        var_r6_33 = 0;
        if ((temp_cr0_eq_44 == 0) && ((u8) M2C_FIELD(*var_r8_36, u8 *, 4) != 0)) {
            var_r6_33 = 1;
        }
        var_r8_36 += 4;
        goto loop_7;
    }
    if (var_r6_33 != 0) {
        this->unk40.Send(NULL);
    }
}
#endif

#if 0 // DRAFT: pointer/array required
void SpawnerObject::RemoveChildSpawner(SpawnerObject *arg0) {
    s32 temp_r4_79;
    s32 var_r6_73;
    u32 *temp_r3_82;
    u32 *temp_r5_90;

    var_r6_73 = this->unk8.unk0;
loop_4:
    temp_r5_90 = *var_r6_73;
    if (temp_r5_90 == NULL) {
        return;
    }
    if ((u32) *temp_r5_90 == arg0) {
        temp_r4_79 = this->unk8.unk0;
        this->unk8.unk0 = temp_r4_79 + 4;
        temp_r3_82 = *temp_r4_79;
        *temp_r4_79 = (u32 *) *var_r6_73;
        *var_r6_73 = temp_r3_82;
        return;
    }
    var_r6_73 += 4;
    goto loop_4;
}
#endif

#if 0 // DRAFT: pointer/array required
void SpawnerObject::AddChildSpawner(SpawnerObject *arg0) {
    s32 temp_r5_114;
    s32 var_r6_102;
    u32 *temp_r5_110;
    void *temp_r3_116;

    var_r6_102 = this->unk8.unk0;
loop_3:
    temp_r5_110 = *var_r6_102;
    if (temp_r5_110 == NULL) {
        temp_r5_114 = this->unk8.unk0 - 4;
        this->unk8.unk0 = temp_r5_114;
        temp_r3_116 = *temp_r5_114;
        if (temp_r3_116 != NULL) {
            M2C_FIELD(temp_r3_116, SpawnerObject **, 0) = arg0;
            M2C_FIELD(temp_r3_116, s8 *, 4) = 0;
            return;
        }
        arg0->SetParentSpawner(NULL);
    } else if ((u32) *temp_r5_110 != arg0) {
        var_r6_102 += 4;
        goto loop_3;
    }
}
#endif

void SpawnerObject::SetParentSpawner(SpawnerObject *arg0) {
    SpawnerObject *temp_r3_143;
    SpawnerObject *temp_r3_150;

    temp_r3_143 = this->unk4;
    if (temp_r3_143 != NULL) {
        temp_r3_143->RemoveChildSpawner(this);
    }
    this->unk4 = arg0;
    temp_r3_150 = this->unk4;
    if (temp_r3_150 != NULL) {
        temp_r3_150->AddChildSpawner(this);
    }
}

SpawnPointObject *SpawnerObject::GetSpawnPoint(int arg0) {
    s32 var_r5_167;
    u32 *var_r6_166;
    u32 temp_r3_177;

    var_r6_166 = this->unk44;
    var_r5_167 = 0;
loop_3:
    if ((var_r6_166 == NULL) || (temp_r3_177 = *var_r6_166, ((temp_r3_177 == 0) != 0))) {
        return NULL;
    }
    if (var_r5_167 != arg0) {
        var_r5_167 += 1;
        var_r6_166 += 4;
        goto loop_3;
    }
    return (SpawnPointObject *) temp_r3_177;
}

s32 SpawnerObject::IsDying() {
    return this->unk10.unk0 == 1;
}

s32 SpawnerObject::IsSpawning() {
    return this->unk10.unk0 == 0;
}

void SpawnerObject::UpdateUsedSpawnPointMask() {
    s32 var_r6_208;
    u32 *var_r7_211;
    u32 temp_r5_227;

    var_r6_208 = 0;
    this->unk1C = 0;
    var_r7_211 = this->unk44;
loop_4:
    if (var_r7_211 != NULL) {
        temp_r5_227 = *var_r7_211;
        if (temp_r5_227 == 0) {
            return;
        }
        if ((u8) M2C_FIELD(temp_r5_227, u8 *, 0x51) != 0) {
            this->unk1C |= 1 << var_r6_208;
        }
        var_r6_208 += 1;
        var_r7_211 += 4;
        goto loop_4;
    }
}

MKProp *SpawnerObject::GetActive(int arg0) {
    MKProp ***var_r6_236;
    MKProp **temp_r3_248;
    s32 var_r5_237;

    var_r6_236 = this->unk48;
    var_r5_237 = 0;
loop_4:
    temp_r3_248 = *var_r6_236;
    if (temp_r3_248 == NULL) {
        return NULL;
    }
    if (var_r5_237 == arg0) {
        return *temp_r3_248;
    }
    var_r5_237 += 1;
    var_r6_236 += 4;
    goto loop_4;
}

void SpawnerObject::GetNumberActive() {
    MKProp ***var_r4_258;

    var_r4_258 = this->unk48;
loop_2:
    if ((MKProp **) *var_r4_258 != NULL) {
        var_r4_258 += 4;
        goto loop_2;
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void *SpawnerObject::Spawn(MKProp *arg0) {
    u8 sp14;
    void *sp10;
    s32 spC;
    s32 sp8;
    s32 var_r29_292;
    u32 *temp_r4_282;
    u32 *var_r3_283;
    void *temp_r3_301;

    spC = 0;
    temp_r4_282 = this->unk44;
    var_r3_283 = temp_r4_282;
loop_2:
    if ((u32) *var_r3_283 != 0) {
        var_r3_283 += 4;
        goto loop_2;
    }
    var_r29_292 = 0;
loop_8:
    if (var_r29_292 >= (s32) ((s32) (var_r3_283 - temp_r4_282) / 4)) {
        goto block_9;
    }
    temp_r3_301 = GetSpawnPointObject();
    if (temp_r3_301 != NULL) {
        sp8 = 0x33;
        sp14 = 0;
        sp10 = temp_r3_301;
        arg0->Message(&sp8);
        if (sp14 != 0) {
            return temp_r3_301;
        }
        var_r29_292 += 1;
        goto loop_8;
    }
block_9:
    return NULL;
}
#endif

#if 0 // DRAFT: function call 'MKRand_Int(long *, int, long)' does not match
SpawnPointObject *SpawnerObject::GetSpawnPointObject() {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    SpawnPointObject *var_r28_360;
    s32 temp_r25_371;
    s32 temp_r30_356;
    s32 temp_r3_420;
    s32 temp_r4_421;
    s32 var_r27_362;
    s32 var_r29_361;
    u32 *temp_r4_343;
    u32 *var_r3_344;

    temp_r4_343 = this->unk44;
    var_r3_344 = temp_r4_343;
loop_2:
    if ((u32) *var_r3_344 != 0) {
        var_r3_344 += 4;
        goto loop_2;
    }
    temp_r30_356 = (s32) (var_r3_344 - temp_r4_343) / 4;
    var_r28_360 = NULL;
    var_r29_361 = MKRand_Int(&gViewSeed, 0, temp_r30_356);
    var_r27_362 = 0;
loop_9:
    if (var_r27_362 < temp_r30_356) {
        temp_r25_371 = 1 << var_r29_361;
        var_r28_360 = GetSpawnPoint(var_r29_361);
        if (!(temp_r25_371 & this->unk1C)) {
            if (((u8) this->unk4C >> 5U) & 1) {
                sp18 = 0.0f;
                sp1C = 100.0f;
                sp20 = 0.0f;
                sp28 = (f64) sp18;
                sp30 = (f64) sp20;
                M2C_ERROR(/* unknown instruction: psq_lx $f2, $zero, $r3, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
                sp38 = sp8;
                sp10 = var_r28_360->unk48 + (f32) sp30;
                sp40 = (f64) sp10;
                if (((Frustum *) (M2C_FIELD(&gb, s32 *, 0x3B8) + 0xB0))->IsVisible(*((MKVector3 *) &sp38), 100.0f) != 0) {
                    this->unk1C |= temp_r25_371;
                    goto block_8;
                }
            }
        } else {
block_8:
            var_r27_362 += 1;
            var_r29_361 = (var_r29_361 + 1) % temp_r30_356;
            goto loop_9;
        }
    }
    temp_r3_420 = this->unk1C;
    temp_r4_421 = 1 << var_r29_361;
    if (temp_r4_421 & temp_r3_420) {
        return NULL;
    }
    this->unk1C = temp_r3_420 | temp_r4_421;
    return var_r28_360;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void SpawnerObject::FreeSpawnItemObject(SpawnItemObject *arg0) {
    s32 spC;
    s32 sp8;
    MKProp ***temp_r3_470;
    MKProp ***var_r4_465;
    MKProp **temp_r0_481;
    MKProp **temp_r5_473;
    MKProp *temp_r3_452;

    if ((((u8) this->unk4C >> 6U) & 1) && (arg0 != NULL)) {
        temp_r3_452 = arg0->unk0;
        if (temp_r3_452 != NULL) {
            spC = 0;
            sp8 = 0x37;
            M2C_FIELD(temp_r3_452->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
        }
        var_r4_465 = this->unk48;
loop_8:
        temp_r0_481 = *var_r4_465;
        if (temp_r0_481 == NULL) {

        } else {
            if (temp_r0_481 == arg0) {
                temp_r3_470 = this->unk48;
                this->unk48 = temp_r3_470 + 4;
                temp_r5_473 = *temp_r3_470;
                *temp_r3_470 = *var_r4_465;
                *var_r4_465 = temp_r5_473;
                return;
            }
            var_r4_465 += 4;
            goto loop_8;
        }
    }
}
#endif

#if 0 // DRAFT: expression syntax error
MKProp **SpawnerObject::GetSpawnItemObject() {
    MKProp ***temp_r4_503;
    MKProp ***temp_r4_507;
    MKProp **temp_r3_509;
    MKProp **var_r31_499;

    var_r31_499 = NULL;
    if (((u8) this->unk4C >> 6U) & 1) {
        temp_r4_503 = this->unk48;
        if ((u32) M2C_FIELD(temp_r4_503, u32 *, -4) != 0U) {
            temp_r4_507 = temp_r4_503 - 4;
            this->unk48 = temp_r4_507;
            temp_r3_509 = *temp_r4_507;
            var_r31_499 = temp_r3_509;
            temp_r3_509->SetDefaults();
        }
    }
    return var_r31_499;
}
#endif

void SpawnerObject::ItemWasRecycled(MKProp *arg0) {
    RemoveItem(arg0);
}

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void SpawnerObject::KillAll() {
    s32 spC;
    s32 sp8;
    MKProp ***var_r29_548;
    MKProp **temp_r3_561;
    MKProp *temp_r3_551;

    if (((u8) this->unk4C >> 6U) & 1) {
        this->unk10.unk0 = 1;
        var_r29_548 = this->unk48;
loop_3:
        temp_r3_561 = *var_r29_548;
        if (temp_r3_561 != NULL) {
            temp_r3_551 = *temp_r3_561;
            spC = 0;
            sp8 = 0xE0;
            temp_r3_551->Message(&sp8);
            var_r29_548 += 4;
            goto loop_3;
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void SpawnerObject::DespawnAll() {
    s32 spC;
    s32 sp8;
    MKProp ***temp_r3_583;
    MKProp ***var_r29_587;
    MKProp **temp_r4_606;
    MKProp *temp_r28_592;

    if (((u8) this->unk4C >> 6U) & 1) {
        temp_r3_583 = this->unk48;
        if ((MKProp **) *temp_r3_583 != NULL) {
            var_r29_587 = temp_r3_583;
loop_4:
            temp_r4_606 = *var_r29_587;
            if (temp_r4_606 != NULL) {
                temp_r28_592 = *temp_r4_606;
                DespawnItem((SpawnItemObject *) temp_r4_606, 0U);
                spC = 0;
                sp8 = 0x37;
                temp_r28_592->Message(&sp8);
                var_r29_587 += 4;
                goto loop_4;
            }
loop_7:
            if ((MKProp **) *this->unk48 != NULL) {
                this->unk48 += 4;
                goto loop_7;
            }
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void SpawnerObject::DespawnItem(SpawnItemObject *arg0, bool arg1) {
    s32 spC;
    s32 sp8;
    MKProp ***temp_r4_669;
    MKProp ***var_r3_670;
    MKProp *temp_r6_639;
    SpawnerObject *temp_r3_685;

    temp_r6_639 = arg0->unk0;
    spC = 0;
    sp8 = 0x15F;
    temp_r6_639->Message(&sp8, temp_r6_639);
    ((M2C_UNK (*)(M2C_UNK, s32, SpawnItemObject *, M2C_UNK)) this->unkC.unk0)(2, arg0->unk8, arg0, 0);
    M2C_FIELD(arg0->unk4, s8 *, 0x51) = 0;
    if (arg1 == 0) {
        this->unk20 -= 1;
    } else if ((s32) this->unk20 == (s32) this->unk24) {
        temp_r4_669 = this->unk48;
        var_r3_670 = temp_r4_669;
loop_5:
        if ((MKProp **) *var_r3_670 != NULL) {
            var_r3_670 += 4;
            goto loop_5;
        }
        if ((s32) ((s32) (var_r3_670 - temp_r4_669) / 4) <= 1) {
            AllDied();
            temp_r3_685 = this->unk4;
            if (temp_r3_685 != NULL) {
                temp_r3_685->AllChildrenDied(this);
            }
        }
    }
    arg0->SetDefaults();
}
#endif

void SpawnerObject::SendMessageToActive(MKMessage *arg0) {
    MKProp ***var_r31_708;
    MKProp **temp_r3_719;
    MKProp *temp_r3_711;

    var_r31_708 = this->unk48;
loop_2:
    temp_r3_719 = *var_r31_708;
    if (temp_r3_719 != NULL) {
        temp_r3_711 = *temp_r3_719;
        temp_r3_711->Message(arg0);
        var_r31_708 += 4;
        goto loop_2;
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void SpawnerObject::DespawnItem(MKProp *arg0, bool arg1) {
    s32 spC;
    s32 sp8;
    MKProp ***temp_r3_756;
    MKProp ***var_r31_738;
    MKProp **temp_r4_759;
    MKProp **temp_r4_767;

    var_r31_738 = this->unk48;
loop_4:
    temp_r4_767 = *var_r31_738;
    if (temp_r4_767 == NULL) {
        return;
    }
    if ((MKProp *) *temp_r4_767 == arg0) {
        DespawnItem((SpawnItemObject *) temp_r4_767, arg1);
        spC = 0;
        sp8 = 0x37;
        arg0->Message(&sp8);
        temp_r3_756 = this->unk48;
        this->unk48 = temp_r3_756 + 4;
        temp_r4_759 = *temp_r3_756;
        *temp_r3_756 = *var_r31_738;
        *var_r31_738 = temp_r4_759;
        return;
    }
    var_r31_738 += 4;
    goto loop_4;
}
#endif

MKProp *SpawnerObject::TrySpawnItem(int arg0) {
    MKProp *sp8;
    MKProp **temp_r30_802;
    s32 temp_cr0_eq_802;
    void *temp_r3_827;

    if (((s32) this->unk10.unk0 != 0) || (this->unk38 > M2C_FIELD(&gb, f32 *, 0x30C))) {
        return NULL;
    }
    temp_r30_802 = GetSpawnItemObject();
    temp_cr0_eq_802 = temp_r30_802 == NULL;
    sp8 = NULL;
    if (temp_cr0_eq_802 == 0) {
        ((M2C_UNK (*)(M2C_UNK, s32, MKProp **, M2C_UNK)) this->unkC.unk0)(0, arg0, &sp8, 0);
        if (sp8 == NULL) {
            ((M2C_UNK (*)(M2C_UNK, s32, MKProp **, M2C_UNK)) this->unkC.unk0)(1, arg0, &sp8, 0);
        }
        if (sp8 != NULL) {
            temp_r3_827 = Spawn(sp8);
            if (temp_r3_827 != NULL) {
                if ((((u8) this->unk4C >> 4U) & 1) || ((u8) M2C_FIELD(temp_r3_827, u8 *, 0x50) == 1)) {
                    M2C_FIELD(temp_r3_827, s8 *, 0x51) = 1;
                }
                M2C_FIELD(temp_r30_802, s32 *, 8) = arg0;
                M2C_FIELD(temp_r30_802, MKProp **, 0) = sp8;
                M2C_FIELD(temp_r30_802, void **, 4) = temp_r3_827;
                this->unk38 = M2C_FIELD(&gb, f32 *, 0x30C) + this->unk34;
                this->unk20 += 1;
                return sp8;
            }
        }
        ((M2C_UNK (*)(M2C_UNK, s32, MKProp **, M2C_UNK)) this->unkC.unk0)(2, arg0, &sp8, 0);
        FreeSpawnItemObject((SpawnItemObject *) temp_r30_802);
        goto block_13;
    }
block_13:
    return NULL;
}

void SpawnerObject::TrySpawnItems(int arg0, bool arg1) {
    s32 temp_r3_887;
    s32 temp_r4_904;
    s32 var_r0_905;
    s32 var_r0_918;
    s32 var_r27_949;
    s32 var_r28_896;
    s32 var_r28_923;

    if ((s32) this->unk10.unk0 == 0) {
        temp_r3_887 = this->unk24;
        if ((temp_r3_887 > 0) && ((s32) this->unk20 >= temp_r3_887)) {
            return;
        }
        var_r28_896 = 1;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (this->unk34 == 0.000001f) {
            if (temp_r3_887 > 0) {
                temp_r4_904 = this->unk28;
                var_r0_905 = temp_r3_887 - this->unk20;
                if (temp_r4_904 < var_r0_905) {
                    var_r0_905 = temp_r4_904;
                }
                var_r28_896 = var_r0_905;
            } else {
                var_r28_896 = this->unk28;
            }
        }
        GetNumberActive();
        var_r0_918 = this->unk28 - M2C_ERROR(/* Read from unset register $r3 */);
        if (var_r28_896 < var_r0_918) {
            var_r0_918 = var_r28_896;
        }
        var_r28_923 = this->unk2C;
        if (var_r0_918 < var_r28_923) {
            var_r28_923 = var_r0_918;
        }
        if (var_r28_923 <= 0) {
            this->unk38 = M2C_FIELD(&gb, f32 *, 0x30C) + this->unk30;
            return;
        }
        if (this->unk38 < M2C_FIELD(&gb, f32 *, 0x30C)) {
            UpdateUsedSpawnPointMask();
            var_r27_949 = 0;
loop_19:
            if (var_r27_949 < var_r28_923) {
                TrySpawnItem(arg0);
                var_r27_949 += 1;
                goto loop_19;
            }
            if (arg1 != 0) {
                this->unk24 = this->unk20;
            }
        }
    }
}

void SpawnerObject::FunctionOff() {
    this->unk10.unk0 = 2;
}

void SpawnerObject::FunctionOn() {
    this->unk10.unk0 = 0;
    this->unk38 = M2C_FIELD(&gb, f32 *, 0x30C) + this->unk30;
}

void SpawnerObject::SetDefaults() {
    u32 *var_r5_1008;
    u32 temp_r3_1016;

    this->unk10.unk0 = 0;
    this->unk38 = 0.0f;
    this->unk1C = 0;
    this->unk20 = 0;
    this->unk4C &= ~8;
    if (((u8) this->unk4C >> 7U) & 1) {
        var_r5_1008 = this->unk44;
loop_3:
        if (var_r5_1008 != NULL) {
            temp_r3_1016 = *var_r5_1008;
            if (temp_r3_1016 == 0) {
                return;
            }
            M2C_FIELD(temp_r3_1016, s8 *, 0x51) = 0;
            var_r5_1008 += 4;
            goto loop_3;
        }
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void SpawnerObject::RemoveItem(MKProp *arg0) {
    s32 spC;
    s32 sp8;
    MKProp ***temp_r3_1049;
    MKProp ***var_r31_1033;
    MKProp **temp_r3_1060;
    MKProp **temp_r4_1052;

    if (((u8) this->unk4C >> 6U) & 1) {
        var_r31_1033 = this->unk48;
loop_5:
        temp_r3_1060 = *var_r31_1033;
        if (temp_r3_1060 == NULL) {

        } else {
            if ((MKProp *) *temp_r3_1060 == arg0) {
                spC = 0;
                sp8 = 0x37;
                arg0->Message(&sp8);
                temp_r3_1049 = this->unk48;
                this->unk48 = temp_r3_1049 + 4;
                temp_r4_1052 = *temp_r3_1049;
                *temp_r3_1049 = *var_r31_1033;
                *var_r31_1033 = temp_r4_1052;
                return;
            }
            var_r31_1033 += 4;
            goto loop_5;
        }
    }
}
#endif

#if 0 // DRAFT: pointer/array required
void SpawnerObject::RemoveAllSpawnPoints(bool arg0) {
    u32 *var_r31_1084;
    u32 *var_r31_1097;
    u32 temp_r3_1092;
    u32 temp_r4_1104;

    if (((u8) this->unk4C >> 7U) & 1) {
        if (arg0 != 0) {
            var_r31_1084 = this->unk44;
loop_4:
            temp_r3_1092 = *var_r31_1084;
            if (temp_r3_1092 != 0) {
                temp_r3_1092->Deinit();
                operator delete((void *) *var_r31_1084);
                var_r31_1084 += 4;
                goto loop_4;
            }
        } else {
            var_r31_1097 = this->unk44;
loop_8:
            temp_r4_1104 = *var_r31_1097;
            if (temp_r4_1104 != 0) {
                RemoveSpawnPoint((SpawnPointObject *) temp_r4_1104);
                var_r31_1097 += 4;
                goto loop_8;
            }
        }
    }
    this->unk1C = 0;
    SetDefaults();
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void SpawnerObject::RemoveSpawnPoint(SpawnPointObject *arg0) {
    u8 sp14;
    SpawnPointObject *sp10;
    s32 spC;
    s32 sp8;
    MKProp ***temp_r3_1156;
    MKProp ***var_r30_1141;
    MKProp **temp_r3_1167;
    MKProp **temp_r4_1159;
    MKProp *temp_r3_1144;
    u8 temp_r3_1129;

    if (arg0 != NULL) {
        temp_r3_1129 = this->unk4C;
        if ((temp_r3_1129 >> 7U) & 1) {
            if ((temp_r3_1129 >> 6U) & 1) {
                arg0->unk0 = NULL;
                spC = 0;
                sp8 = 0x36;
                sp10 = arg0;
                sp14 = 0;
                var_r30_1141 = this->unk48;
loop_9:
                temp_r3_1167 = *var_r30_1141;
                if (temp_r3_1167 != NULL) {
                    temp_r3_1144 = *temp_r3_1167;
                    if (temp_r3_1144 != NULL) {
                        M2C_FIELD(temp_r3_1144->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
                    }
                    if (sp14 != 0) {
                        temp_r3_1156 = this->unk48;
                        this->unk48 = temp_r3_1156 + 4;
                        temp_r4_1159 = *temp_r3_1156;
                        *temp_r3_1156 = *var_r30_1141;
                        *var_r30_1141 = temp_r4_1159;
                    }
                    sp14 = 0;
                    var_r30_1141 += 4;
                    goto loop_9;
                }
            }
            arg0->unk52 = 0;
            this->unk44.Destroy(arg0);
        }
    }
}
#endif

void SpawnerObject::AddSpawnPointEnd() {
    u32 *var_r5_1187;
    u32 temp_r4_1192;
    u32 temp_r4_1198;

    var_r5_1187 = this->unk44;
loop_2:
    if (var_r5_1187 != NULL) {
        temp_r4_1198 = *var_r5_1187;
        if (temp_r4_1198 == 0) {
            return;
        }
        M2C_FIELD(temp_r4_1198, s8 *, 0x51) = 0;
        temp_r4_1192 = *var_r5_1187;
        var_r5_1187 += 4;
        M2C_FIELD(temp_r4_1192, SpawnerObject **, 0) = this;
        goto loop_2;
    }
}

void SpawnerObject::AddSpawnPoint(SpawnPointObject *arg0) {
    u32 *temp_r5_1209;

    temp_r5_1209 = this->unk44 - 4;
    this->unk44 = temp_r5_1209;
    *temp_r5_1209 = (u32) arg0;
    arg0->unk52 = 1;
}

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void SpawnerObject::AddSpawnPointBegin(int arg0) {
    MKHeap *temp_r3_1235;
    s32 temp_r30_1227;
    s32 var_ctr_1256;
    u32 *temp_r3_1260;
    u32 *temp_r3_1266;
    u32 *var_r3_1243;

    if (arg0 != 0) {
        this->unk2C = arg0;
        temp_r30_1227 = this->unk2C;
        if (temp_r30_1227 == 0) {
            this->unk44 = &gEmptyPtrList + 4;
        } else {
            temp_r3_1235 = MKHeap::Current();
            if (temp_r3_1235 != NULL) {
                var_r3_1243 = ((MKHeap *) (temp_r3_1235->Current()))->Alloc((temp_r30_1227 + 2) * 4, NULL, 0);
            } else {
                var_r3_1243 = malloc((temp_r30_1227 + 2) * 4);
            }
            this->unk44 = var_r3_1243;
            M2C_FIELD(this->unk44, u32 *, 0) = 0;
            var_ctr_1256 = temp_r30_1227;
            if (temp_r30_1227 > 0) {
                do {
                    temp_r3_1260 = this->unk44;
                    this->unk44 = temp_r3_1260 + 4;
                    M2C_FIELD(temp_r3_1260, s32 *, 4) = 0xDEADBEEF;
                    var_ctr_1256 -= 1;
                } while (var_ctr_1256 != 0);
            }
            temp_r3_1266 = this->unk44;
            this->unk44 = temp_r3_1266 + 4;
            M2C_FIELD(temp_r3_1266, s32 *, 4) = 0;
        }
        this->unk4C |= 0x80;
    }
}
#endif

#if 0 // DRAFT: pointer/array required
void SpawnerObject::Deinit() {
    MKHeap *temp_r3_1332;
    MKHeap *temp_r3_1364;
    MKHeap *temp_r3_1410;
    MKProp ***var_r30_1384;
    MKProp ***var_r3_1385;
    MKProp ***var_r4_1383;
    MKProp **temp_r0_1388;
    MKProp **temp_r0_1407;
    SpawnerObject **temp_r3_1302;
    s32 var_r30_1294;
    s32 var_r30_1306;
    s32 var_r3_1307;
    s32 var_r4_1305;
    u32 *temp_r30_1360;
    u32 *temp_r3_1355;
    u32 temp_r0_1310;
    u32 temp_r0_1315;
    u32 temp_r0_1329;
    u32 temp_r0_1393;

    SetParentSpawner(NULL);
    var_r30_1294 = this->unk8.unk0;
loop_2:
    temp_r3_1302 = *var_r30_1294;
    if (temp_r3_1302 != NULL) {
        ((SpawnerObject *) (*temp_r3_1302))->SetParentSpawner(NULL);
        var_r30_1294 += 4;
        goto loop_2;
    }
    var_r4_1305 = this->unk8.unk0;
    var_r30_1306 = var_r4_1305;
    var_r3_1307 = var_r4_1305;
loop_6:
    temp_r0_1315 = M2C_FIELD(var_r3_1307, u32 *, -4);
    var_r3_1307 -= 4;
    if (temp_r0_1315 != 0U) {
        temp_r0_1310 = *var_r3_1307;
        if (temp_r0_1310 < (u32) var_r30_1306) {
            var_r30_1306 = (s32) temp_r0_1310;
        }
        goto loop_6;
    }
    if ((u32) var_r3_1307 != &gEmptyPtrListDL) {
loop_12:
        temp_r0_1329 = *var_r4_1305;
        if (temp_r0_1329 != 0U) {
            if (temp_r0_1329 < (u32) var_r30_1306) {
                var_r30_1306 = (s32) temp_r0_1329;
            }
            var_r4_1305 += 4;
            goto loop_12;
        }
        temp_r3_1332 = var_r3_1307->Current();
        if (temp_r3_1332 != NULL) {
            ((MKHeap *) (temp_r3_1332->Current()))->Free((void *) var_r30_1306, NULL, 0);
        } else {
            free((u32 *) var_r30_1306);
        }
    }
    this->unk8.unk0 = 0;
    RemoveAllSpawnPoints(0U);
    if (((u8) this->unk4C >> 7U) & 1) {
        do {
            temp_r3_1355 = this->unk44 - 4;
            this->unk44 = temp_r3_1355;
        } while ((u32) *temp_r3_1355 != 0);
        temp_r30_1360 = this->unk44;
        if (temp_r30_1360 != &gEmptyPtrList) {
            temp_r3_1364 = temp_r3_1355->Current();
            if (temp_r3_1364 != NULL) {
                ((MKHeap *) (temp_r3_1364->Current()))->Free(temp_r30_1360, NULL, 0);
            } else {
                free(temp_r30_1360);
            }
        }
        this->unk44 = NULL;
    }
    if (((u8) this->unk4C >> 6U) & 1) {
        var_r4_1383 = this->unk48;
        var_r30_1384 = var_r4_1383;
        var_r3_1385 = var_r4_1383;
loop_27:
        temp_r0_1393 = M2C_FIELD(var_r3_1385, u32 *, -4);
        var_r3_1385 -= 4;
        if (temp_r0_1393 != 0U) {
            temp_r0_1388 = *var_r3_1385;
            if (temp_r0_1388 < var_r30_1384) {
                var_r30_1384 = (MKProp ***) temp_r0_1388;
            }
            goto loop_27;
        }
        if (var_r3_1385 != &gEmptyPtrListDL) {
loop_33:
            temp_r0_1407 = *var_r4_1383;
            if (temp_r0_1407 != NULL) {
                if (temp_r0_1407 < var_r30_1384) {
                    var_r30_1384 = (MKProp ***) temp_r0_1407;
                }
                var_r4_1383 += 4;
                goto loop_33;
            }
            temp_r3_1410 = var_r3_1385->Current();
            if (temp_r3_1410 != NULL) {
                ((MKHeap *) (temp_r3_1410->Current()))->Free(var_r30_1384, NULL, 0);
            } else {
                free((u32 *) var_r30_1384);
            }
        }
        this->unk48 = NULL;
    }
    this->unk4C &= ~0x80;
    this->unk4C &= ~0x40;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void SpawnerObject::LoadDone(unsigned int arg0) {
    MKHeap *temp_r3_1461;
    MKProp ***temp_r3_1484;
    MKProp ***temp_r3_1491;
    MKProp ***temp_r3_1498;
    MKProp ***var_r5_1483;
    s32 temp_r30_1453;
    s32 var_ctr_1487;
    u32 *var_r3_1471;

    this->unk18 = (s32) arg0;
    this->unk4C |= 0x40;
    temp_r30_1453 = this->unk28;
    if (temp_r30_1453 == 0) {
        this->unk48 = &gEmptyPtrListDL + 4;
        return;
    }
    temp_r3_1461 = 1U->Current();
    if (temp_r3_1461 != NULL) {
        var_r3_1471 = ((MKHeap *) (temp_r3_1461->Current()))->Alloc(((temp_r30_1453 + 2) * 4) + (temp_r30_1453 * 0xC), NULL, 0);
    } else {
        var_r3_1471 = malloc(((temp_r30_1453 + 2) * 4) + (temp_r30_1453 * 0xC));
    }
    this->unk48 = (MKProp ***) var_r3_1471;
    var_r5_1483 = this->unk48;
    temp_r3_1484 = var_r5_1483 + (temp_r30_1453 * 0xC);
    this->unk48 = temp_r3_1484;
    *temp_r3_1484 = NULL;
    var_ctr_1487 = temp_r30_1453;
    if (temp_r30_1453 > 0) {
        do {
            temp_r3_1491 = this->unk48;
            this->unk48 = temp_r3_1491 + 4;
            M2C_FIELD(temp_r3_1491, MKProp ****, 4) = var_r5_1483;
            var_r5_1483 += 0xC;
            var_ctr_1487 -= 1;
        } while (var_ctr_1487 != 0);
    }
    temp_r3_1498 = this->unk48;
    this->unk48 = temp_r3_1498 + 4;
    M2C_FIELD(temp_r3_1498, MKProp ****, 4) = NULL;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void SpawnerObject::LoadDone(int arg0, int arg1, bool arg2, unsigned int arg3) {
    MKHeap *temp_r3_1537;
    MKProp ***temp_r3_1560;
    MKProp ***temp_r3_1567;
    MKProp ***temp_r3_1574;
    MKProp ***var_r5_1559;
    s32 temp_r30_1529;
    s32 var_ctr_1563;
    u32 *var_r3_1547;

    this->unk24 = arg0;
    this->unk28 = arg1;
    this->unk4C |= 0x40;
    this->unk4C = (this->unk4C & ~0x20) | ((arg2 << 5) & 0x20);
    this->unk18 = (s32) arg3;
    temp_r30_1529 = this->unk28;
    if (temp_r30_1529 == 0) {
        this->unk48 = &gEmptyPtrListDL + 4;
        return;
    }
    temp_r3_1537 = 1U->Current();
    if (temp_r3_1537 != NULL) {
        var_r3_1547 = ((MKHeap *) (temp_r3_1537->Current()))->Alloc(((temp_r30_1529 + 2) * 4) + (temp_r30_1529 * 0xC), NULL, 0);
    } else {
        var_r3_1547 = malloc(((temp_r30_1529 + 2) * 4) + (temp_r30_1529 * 0xC));
    }
    this->unk48 = (MKProp ***) var_r3_1547;
    var_r5_1559 = this->unk48;
    temp_r3_1560 = var_r5_1559 + (temp_r30_1529 * 0xC);
    this->unk48 = temp_r3_1560;
    *temp_r3_1560 = NULL;
    var_ctr_1563 = temp_r30_1529;
    if (temp_r30_1529 > 0) {
        do {
            temp_r3_1567 = this->unk48;
            this->unk48 = temp_r3_1567 + 4;
            M2C_FIELD(temp_r3_1567, MKProp ****, 4) = var_r5_1559;
            var_r5_1559 += 0xC;
            var_ctr_1563 -= 1;
        } while (var_ctr_1563 != 0);
    }
    temp_r3_1574 = this->unk48;
    this->unk48 = temp_r3_1574 + 4;
    M2C_FIELD(temp_r3_1574, MKProp ****, 4) = NULL;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
s32 SpawnerObject::LoadLine(MKIniLine *arg0) {
    s32 spC;
    u8 sp8;

    sp8 = 0;
    spC = 0;
    if ((arg0->LoadFloat("fSpawnDelay", &this->unk30, 0) != 0) || (arg0->LoadFloat("fDelayBetweenSpawns", &this->unk34, 0) != 0) || (arg0->LoadInt("iMaxSpawnItems", &this->unk28, 0) != 0) || (arg0->LoadInt("iMaxSpawnAmount", &this->unk24, 0) != 0) || (this->unk3C.LoadLine(arg0, "OnAllDead") != 0) || (this->unk40.LoadLine(arg0, "OnChildSpawnerAllDead") != 0)) {
        return 1;
    }
    if (arg0->LoadBool("bOnlySpawnOffscreen", &sp8, 0) != 0) {
        this->unk4C = (this->unk4C & ~0x20) | ((sp8 << 5) & 0x20);
        goto block_14;
    }
    if (arg0->LoadBool("bLockSpawnPoints", &sp8, 0) != 0) {
        this->unk4C = (this->unk4C & ~0x10) | ((sp8 << 4) & 0x10);
        goto block_14;
    }
    if (arg0->LoadInt("zone", &spC, 0) != 0) {
        this->unk18 = spC;
block_14:
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: identifier 'arg1' redeclared
void SpawnerObject::Init(void (*arg1)(SpawnAction, int, MKProp **, SpawnerObject *), int arg1) {
    MKHeap *temp_r3_1747;
    s32 temp_r3_1769;
    s32 temp_r4_1775;
    s32 var_ctr_1767;
    s32 var_r5_1763;
    u32 *var_r3_1754;

    this->unk14.unk0 = arg1;
    this->unkC.unk0 = (s32) arg0;
    this->unk24 = 0;
    this->unk28 = 0;
    this->unk2C = 0;
    this->unk30 = 0.0f;
    this->unk34 = 0.0f;
    this->unk38 = 0.0f;
    this->unk4C &= ~0x40;
    this->unk4C &= ~0x80;
    this->unk4C &= ~0x20;
    this->unk4C &= ~0x10;
    this->unk18 = 1;
    this->unk3C.Init();
    this->unk40.Init();
    this->unk4 = NULL;
    temp_r3_1747 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_1747 != NULL) {
        var_r3_1754 = ((MKHeap *) (temp_r3_1747->Current()))->Alloc(0x38, NULL, 0);
    } else {
        var_r3_1754 = malloc(0x38);
    }
    this->unk8.unk0 = (s32) var_r3_1754;
    var_r5_1763 = this->unk8.unk0;
    this->unk8.unk0 = var_r5_1763 + 0x20;
    M2C_FIELD(var_r5_1763, s32 *, 0x20) = 0;
    var_ctr_1767 = 4;
    do {
        temp_r3_1769 = this->unk8.unk0;
        this->unk8.unk0 = temp_r3_1769 + 4;
        M2C_FIELD(temp_r3_1769, s32 *, 4) = var_r5_1763;
        var_r5_1763 += 8;
        var_ctr_1767 -= 1;
    } while (var_ctr_1767 != 0);
    temp_r4_1775 = this->unk8.unk0;
    this->unk8.unk0 = temp_r4_1775 + 4;
    M2C_FIELD(temp_r4_1775, s32 *, 4) = 0;
    SetDefaults();
}
#endif

void SpawnItemObject::SetDefaults() {
    this->unk0 = NULL;
    this->unk4 = NULL;
    this->unk8 = 0;
}
