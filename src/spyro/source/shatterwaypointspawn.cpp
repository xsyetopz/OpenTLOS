#include "spyro/source/shatterwaypointspawn.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/SpawnPointData.h"
#include "spyro/source/SpawnPointObject.h"
#include "spyro/source/SpawnerObject.h"
#include "common/Source/MKModel.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

M2C_UNK free(s32);                                  /* extern */
s32 malloc(s32);                                    /* extern */

void ShatterWaypointSpawn::SetSpawnPos(int arg0, const MKVector3 &arg1) {
    SpawnPointObject *temp_r3_17;

    temp_r3_17 = ((SpawnerObject *) &this->unk198)->GetSpawnPoint(arg0);
    if (temp_r3_17 != NULL) {
        temp_r3_17->unk40 = arg1.unk0;
        temp_r3_17->unk44 = arg1.unk4;
        temp_r3_17->unk48 = arg1.unk8;
        temp_r3_17->unk4C = 1.0f;
    }
}

#if 0 // DRAFT: type mismatch
void ShatterWaypointSpawn::Resolve() {
    f64 sp10;
    f64 sp8;
    s32 var_r31_60;
    u16 temp_r3_52;
    void *temp_r5_46;

    temp_r5_46 = this->unk8;
    sp8 = M2C_FIELD(temp_r5_46, f64 *, 0x30);
    sp10 = M2C_FIELD(temp_r5_46, f64 *, 0x38);
    temp_r3_52 = Tools_GetMatchingRefPointIndex(this->unk4, "spawn");
    if (temp_r3_52 != -1U) {
        MKModel_CalculateRefPointWorldPosition(this->unk4, (s32) temp_r3_52, (MKVector3 *) &sp8);
    }
    var_r31_60 = 0;
loop_4:
    if (var_r31_60 < (u32 *) this->unk1A8.unk44) {
        SetSpawnPos(var_r31_60, *((MKVector3 *) &sp8));
        var_r31_60 += 1;
        goto loop_4;
    }
}
#endif

#if 0 // DRAFT: type mismatch
void ShatterWaypointSpawn::LoadDone() {
    f64 sp10;
    f64 sp8;
    SpawnPointData *temp_r30_115;
    SpawnPointObject *temp_r0_109;
    s32 var_r29_102;
    u32 *temp_r5_90;
    void *temp_r4_145;

    Shatterable::LoadDone();
    temp_r5_90 = this->unk1A8.unk44;
    if (temp_r5_90 > 0) {
        ((SpawnerObject *) &this->unk198)->LoadDone((s32) this->unk1A8.unk48, (s32) temp_r5_90, 0U, (u32) this->unk18);
        ((SpawnerObject *) &this->unk198)->AddSpawnPointBegin((s32) this->unk1A8.unk44);
        var_r29_102 = 0;
loop_5:
        if (var_r29_102 < (u32 *) this->unk1A8.unk44) {
            operator new(0x60U, NULL, 0);
            temp_r0_109 = M2C_ERROR(/* Read from unset register $r3 */);
            operator new(0x28U, NULL, 0);
            temp_r30_115 = M2C_ERROR(/* Read from unset register $r3 */);
            if (temp_r30_115 != NULL) {
                temp_r30_115->__vptr = &__vt;
                temp_r30_115->__vptr = &__vt;
                M2C_FIELD(temp_r30_115, s32 *, 8) = 0;
                ((EventMessage *) (temp_r30_115 + 8))->Init();
                M2C_FIELD(temp_r30_115, s32 *, 0xC) = 0;
                ((EventMessage *) (temp_r30_115 + 0xC))->Init();
                M2C_FIELD(temp_r30_115, s32 *, 0x10) = 0;
                ((EventMessage *) (temp_r30_115 + 0x10))->Init();
                M2C_FIELD(temp_r30_115, s32 *, 0x14) = 0;
                ((EventMessage *) (temp_r30_115 + 0x14))->Init();
            }
            temp_r0_109->Init(temp_r30_115);
            temp_r0_109->LoadDone();
            temp_r4_145 = this->unk8;
            sp8 = M2C_FIELD(temp_r4_145, f64 *, 0x30);
            sp10 = M2C_FIELD(temp_r4_145, f64 *, 0x38);
            ((Matrix *) &temp_r0_109->unk10)->SetIdentity();
            temp_r0_109->unk40 = (f32) sp8;
            temp_r0_109->unk44 = (*(f32 *) ((u8 *) &sp8 + 0x4));
            temp_r0_109->unk48 = (f32) sp10;
            temp_r0_109->unk4C = 1.0f;
            ((SpawnerObject *) &this->unk198)->AddSpawnPoint(temp_r0_109);
            var_r29_102 += 1;
            M2C_FIELD(temp_r30_115, s32 *, 4) = (s32) (M2C_FIELD(temp_r30_115, s32 *, 4) | 0x220);
            goto loop_5;
        }
        ((SpawnerObject *) &this->unk198)->AddSpawnPointEnd();
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
s32 ShatterWaypointSpawn::LoadWaypoints(MKIniLine *arg0, const char *arg1) {
    MKHeap *temp_r3_206;
    MKIniLine *var_r28_229;
    s32 temp_r29_205;
    s32 var_r30_231;
    u32 *temp_r0_199;
    u32 *temp_r3_197;
    void *var_r3_213;

    if (arg0->IsField(arg1) != 0) {
        temp_r3_197 = arg0->GetNmbrOfSubLines();
        this->unk1A8.unk44 = temp_r3_197;
        temp_r0_199 = this->unk1A8.unk44;
        if (temp_r0_199 == NULL) {
            return 1;
        }
        temp_r29_205 = (s32) temp_r0_199 * 0x10;
        temp_r3_206 = ((MKHeap *) temp_r3_197)->Current();
        if (temp_r3_206 != NULL) {
            var_r3_213 = ((MKHeap *) (temp_r3_206->Current()))->Alloc(temp_r29_205, NULL, 0);
        } else {
            var_r3_213 = malloc(temp_r29_205);
        }
        this->unk1A8.unk40.unk0 = (s32) var_r3_213;
        memset((void *) this->unk1A8.unk40.unk0, 0, (s32) this->unk1A8.unk44 * 0x10);
        var_r28_229 = arg0->unkC->GetSubLine(arg0);
        var_r30_231 = 0;
loop_8:
        if (var_r28_229 != NULL) {
            var_r28_229->LoadVector3("waypoint", this->unk1A8.unk40.unk0 + var_r30_231, 0);
            var_r28_229 = var_r28_229->unkC->GetNextLine(var_r28_229);
            var_r30_231 += 0x10;
            goto loop_8;
        }
        return 1;
    }
    return 0;
}
#endif

s32 ShatterWaypointSpawn::LoadLine(MKIniLine *arg0) {
    s32 var_r31_269;

    var_r31_269 = 0;
    if ((Shatterable::LoadLine(arg0) != 0) || (LoadWaypoints(arg0, "waypoints") != 0)) {
        var_r31_269 = 1;
    }
    return var_r31_269;
}

void ShatterWaypointSpawn::Deinit() {
    MKHeap *temp_r3_311;
    s32 temp_r31_308;

    ((SpawnerObject *) &this->unk198)->RemoveAllSpawnPoints(1U);
    ((SpawnerObject *) &this->unk198)->Deinit();
    temp_r31_308 = this->unk1A8.unk40.unk0;
    if ((u32) temp_r31_308 != 0U) {
        temp_r3_311 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_311 != NULL) {
            ((MKHeap *) (temp_r3_311->Current()))->Free((void *) temp_r31_308, NULL, 0);
        } else {
            free(temp_r31_308);
        }
        this->unk1A8.unk40.unk0 = 0;
    }
    Shatterable::Deinit();
}

#if 0 // DRAFT: undefined identifier 'EnemySpawnPool_Action'
void ShatterWaypointSpawn::Init() {
    Shatterable::Init();
    this->unk1A8.unk48 = NULL;
    ((SpawnerObject *) &this->unk198)->Init(EnemySpawnPool_Action, 0);
    this->unk1A8.unk20 = 0.0f;
    this->unk1A8.unk24 = 0.0f;
    this->unk1A8.unk44 = NULL;
    this->unk1A8.unk40.unk0 = 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk64'
void ShatterWaypointSpawnDescriptor::Init() {
    ShatterableDescriptor::Init();
    this->unk16C = GetSpawnEnemyType();
    this->unk64 |= 0x2000;
}
#endif
