#include "spyro/source/SpawnPointObject.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/Matrix.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/SpawnPointData.h"
#include "spyro/source/SpawnerObject.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

#if 0 // DRAFT: illegal explicit conversion from 'void' to
void SpawnPointObject::Resolve() {
    SpawnerObject *sp10;
    s32 spC;
    s32 sp8;
    SpawnerObject *temp_r3_38;
    SpawnerObject *temp_r3_54;
    void *temp_r3_23;
    void *temp_r3_41;
    void *temp_r3_64;

    if (((u8) this->unk52 == 0) && ((u8) this->unk50 == 1)) {
        temp_r3_23 = ((MKSceneManager *) this->unk10)->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */));
        if (temp_r3_23 != NULL) {
            this->unk10 = M2C_FIELD(temp_r3_23, s32 *, 4);
            this->unk14 = (s32) Tools_GetMatchingRefPointIndex((MKModel *) this->unk10, "Spawn_00");
        }
    }
    if ((u8) this->unk52 == 0) {
        temp_r3_38 = this->unk0;
        if (temp_r3_38 != NULL) {
            temp_r3_41 = ((MKSceneManager *) temp_r3_38)->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */));
            spC = 0;
            sp8 = 0x34;
            sp10 = NULL;
            M2C_FIELD(M2C_FIELD(temp_r3_41, void **, 0x44), M2C_UNK (**)(s32 *, M2C_UNK), 0x2C)(&sp8, 0);
            this->unk0 = sp10;
            temp_r3_54 = this->unk0;
            if ((temp_r3_54 != NULL) && ((u32) M2C_FIELD(temp_r3_54->unk44, u32 *, -4) != 0U)) {
                temp_r3_54->AddSpawnPoint(this);
            }
        }
    }
    temp_r3_64 = this->unk4;
    if (temp_r3_64 != NULL) {
        M2C_FIELD(*temp_r3_64, M2C_UNK (**)(), 0x1C)();
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'void' to
void SpawnPointObject::LoadDone() {
    void *temp_r3_85;

    temp_r3_85 = this->unk4;
    if (temp_r3_85 != NULL) {
        M2C_FIELD(*temp_r3_85, M2C_UNK (**)(), 0x18)();
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'void' to
s32 SpawnPointObject::LoadLine(MKIniLine *arg0) {
    s32 sp8;
    void *temp_r3_108;

    temp_r3_108 = this->unk4;
    if (((temp_r3_108 != NULL) && (M2C_FIELD(*temp_r3_108, u8 (**)(), 0x14)() != 0)) || (arg0->LoadInt("spawnerID", (s32 *) this, 0) != 0)) {
        return 1;
    }
    if (arg0->LoadInt("attachPropID", (int *) &this->unk10, 0) != 0) {
        this->unk50 = 1;
        return 1;
    }
    sp8 = 0;
    if (arg0->LoadInt("attachIndex", (int *) &sp8, 0) != 0) {
        this->unk14 = 0xFFFF;
        this->unk18 = sp8;
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'void' to
void SpawnPointObject::Deinit() {
    SpawnerObject *temp_r3_197;
    void *temp_r3_181;
    void *temp_r3_188;

    temp_r3_181 = this->unk4;
    if (temp_r3_181 != NULL) {
        M2C_FIELD(*temp_r3_181, M2C_UNK (**)(), 0x10)();
        temp_r3_188 = this->unk4;
        if (temp_r3_188 != NULL) {
            M2C_FIELD(*temp_r3_188, M2C_UNK (**)(M2C_UNK), 8)(1);
        }
    }
    temp_r3_197 = this->unk0;
    if (temp_r3_197 != NULL) {
        temp_r3_197->RemoveSpawnPoint(this);
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'void' to
void SpawnPointObject::Init(SpawnPointData *arg0) {
    void *temp_r3_227;

    ((Matrix *) &this->unk10)->SetIdentity();
    this->unk50 = 0;
    this->unk51 = 0;
    this->unk52 = 0;
    this->unk0 = NULL;
    this->unk4 = arg0;
    temp_r3_227 = this->unk4;
    if (temp_r3_227 != NULL) {
        M2C_FIELD(*temp_r3_227, M2C_UNK (**)(), 0xC)();
    }
}
#endif
