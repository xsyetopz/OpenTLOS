#include "spyro/source/ElecZapCrystal.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/EmbersPS.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/Level.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "common/Source/Str.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(M2C_UNK);                              /* extern */
extern s32 GS_LightningCrystal1;
extern s32 GS_LightningCrystal2;
extern M2C_UNK gEmptyPtrListDL;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;

void ElecZapCrystal::TriggerSubObjFader(int arg0, float arg1) {
    void **temp_r5_49;
    void *temp_r3_51;
    void *temp_r5_45;

    temp_r5_45 = this->unkB0;
    if ((u32) M2C_FIELD(temp_r5_45, u32 *, -4) != 0U) {
        temp_r5_49 = (void **) (((u8 *) temp_r5_45) - 4);
        this->unkB0 = temp_r5_49;
        temp_r3_51 = *temp_r5_49;
        if (temp_r3_51 != NULL) {
            M2C_FIELD(temp_r3_51, s32 *, 0) = arg0;
            M2C_FIELD(temp_r3_51, f32 *, 8) = arg1;
            M2C_FIELD(temp_r3_51, f32 *, 4) = arg1;
        }
    }
}

void ElecZapCrystal::Deinit() {
    void **cursor;
    void **scan;
    void *lowest;
    void *entry;

    cursor = (void **) this->unkB0;
    lowest = cursor;
    cursor -= 1;
    entry = *cursor;
    while (entry != NULL) {
        if ((u32) entry < (u32) lowest) {
            lowest = entry;
        }
        cursor -= 1;
        entry = *cursor;
    }
    if ((void *) cursor != (void *) &gEmptyPtrListDL) {
        scan = (void **) this->unkB0;
        entry = *scan;
        while (entry != NULL) {
            if ((u32) entry < (u32) lowest) {
                lowest = entry;
            }
            scan += 1;
            entry = *scan;
        }
        if (MKHeap::Current() != NULL) {
            MKHeap::Current()->Free(lowest, NULL, 0);
        } else {
            free(lowest);
        }
    }
    this->unkB0 = NULL;
    KDProp::Deinit();
}

void ElecZapCrystal::Draw() {
    MKVector4 color;
    f32 ratio;
    void **entry;
    void *fader;

    MKModel_SetColor(this->unk4, this->unkC8);
    MKModel_EnableOnlySubObject(this->unk4, (SubObjectType) 0, this->unk90, 1U, 1U);
    MKModel_Draw(this->unk4, NULL);
    entry = (void **) this->unkB0;
    while (entry != NULL) {
        fader = *entry;
        if (fader == NULL) {
            break;
        }
        ratio = M2C_FIELD(fader, f32 *, 8) / M2C_FIELD(fader, f32 *, 4);
        color.unk0 = ratio;
        color.unk4 = ratio;
        color.unk8 = ratio;
        color.unkC = 1.0f;
        MKModel_SetColor(this->unk4, color);
        MKModel_EnableOnlySubObject(this->unk4, (SubObjectType) 0, M2C_FIELD(fader, s32 *, 0), 1U, 1U);
        MKModel_Draw(this->unk4, NULL);
        entry += 1;
    }
}

void *ElecZapCrystal::Update() {
    MKVector3 velRand;
    MKVector3 velMin;
    MKVector3 velMax;
    MKVector3 velocity;
    MKVector4 burstColor;
    MKVector4 sparkColor;
    f32 life;
    f32 lifeMax;
    f32 fader;
    f32 lifetime;
    f32 alpha;
    s32 index;
    s32 i;
    void **slot;
    void **head;
    void *entry;
    void *temp;

    slot = (void **) this->unkB0;
    while (slot != NULL) {
        entry = *slot;
        if (entry == NULL) {
            break;
        }
        life = M2C_FIELD(entry, f32 *, 8) - gUpdateTimeDelta;
        lifeMax = M2C_FIELD(entry, f32 *, 4);
        if (life < lifeMax) {
        } else {
            life = lifeMax;
        }
        if (life <= 0.0f) {
            life = 0.0f;
        }
        M2C_FIELD(entry, f32 *, 8) = life;
        if (M2C_FIELD(entry, f32 *, 8) <= 0.0f) {
            head = (void **) this->unkB0;
            this->unkB0 = (void *) ((u8 *) head + 4);
            temp = *head;
            *head = *slot;
            *slot = temp;
        }
        slot += 1;
    }
    this->unkBC = this->unkBC - gUpdateTimeDelta;
    switch (this->unkB4) {
    case 0:
        if (this->unkBC <= 0.0f) {
            fader = MKRand_Float((int *) &gViewSeed, 0.2f, 0.5f);
            index = MKRand_Int((int *) &gViewSeed, 0, 4);
            this->TriggerSubObjFader(((s32 *) ((u8 *) this + 0xA0))[index], fader);
            this->unkB4 = 1;
            this->unkBC = 0.5f;
            MKModel_CalculateRefPointWorldPosition(this->unk4, this->unkB8, &this->unkD8);
            KDSound_Play3d(GS_LightningCrystal1, &this->unkD8, 0U, -1, 0.0f, 0U);
            burstColor.unk0 = 1.0f;
            burstColor.unk4 = 0.8f;
            burstColor.unk8 = 0.9f;
            burstColor.unkC = 1.0f;
            ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(this->unkD8, MKVector3::zero, 60.0f, burstColor, 0.0f);
            i = 0;
            do {
                velMin.unk0 = -1.0f;
                velMin.unk4 = 0.0f;
                velMin.unk8 = -1.0f;
                velMax.unk0 = 1.0f;
                velMax.unk4 = 1.0f;
                velMax.unk8 = 1.0f;
                velRand = KDRand_Vector(velMin, velMax);
                velocity.unk0 = velRand.unk0 * 2000.0f;
                velocity.unk4 = velRand.unk4 * 2000.0f;
                velocity.unk8 = velRand.unk8 * 2000.0f;
                lifetime = MKRand_Float((int *) &gViewSeed, 10.0f, 20.0f);
                alpha = MKRand_Float((int *) &gViewSeed, 0.4f, 1.0f);
                sparkColor.unk0 = 1.0f;
                sparkColor.unk4 = 0.4f;
                sparkColor.unk8 = alpha;
                sparkColor.unkC = 1.0f;
                ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(this->unkD8, velocity, lifetime, sparkColor, -2000.0f);
                i += 1;
            } while (i < 0x14);
        }
        break;
    case 1:
        this->unkC0 = this->unkC0 - gUpdateTimeDelta;
        if (this->unkC0 <= 0.0f) {
            fader = MKRand_Float((int *) &gViewSeed, 0.1f, 0.4f);
            index = MKRand_Int((int *) &gViewSeed, 0, 3);
            this->TriggerSubObjFader(((s32 *) ((u8 *) this + 0x94))[index], fader);
            KDSound_Play3d(GS_LightningCrystal2, &this->unkD8, 0U, -1, 0.0f, 0U);
            this->unkC0 = MKRand_Float((int *) &gViewSeed, 0.1f, 0.2f);
        }
        if (this->unkBC <= 0.0f) {
            this->unkB4 = 0;
            this->unkBC = MKRand_Float((int *) &gViewSeed, 0.5f, 1.0f);
        }
        break;
    }
}

s32 ElecZapCrystal::LoadDone() {
    const char *name;
    s32 i;

    KDProp::LoadDone();
    M2C_FIELD(this, f64 *, 0xC8) = M2C_FIELD(&MKProp::loadInfo, f64 *, 0x70);
    M2C_FIELD(this, f64 *, 0xD0) = M2C_FIELD(&MKProp::loadInfo, f64 *, 0x78);
    this->unk90 = (s32) Tools_GetMatchingSubObjectIndex((SubObjectType) 0, this->unk4, "BlueCrystal");
    for (i = 0; i < 3; i++) {
        name = (const char *) Str_Printf("Elec%d", i + 1);
        ((s32 *) ((u8 *) this + 0x94))[i] = (s32) Tools_GetMatchingSubObjectIndex((SubObjectType) 0, this->unk4, name);
    }
    for (i = 0; i < 4; i++) {
        name = (const char *) Str_Printf("Strike%d", i + 1);
        ((s32 *) ((u8 *) this + 0xA0))[i] = (s32) Tools_GetMatchingSubObjectIndex((SubObjectType) 0, this->unk4, name);
    }
    this->unkB8 = (s32) Tools_GetMatchingRefPointIndex(this->unk4, "FX");
}

void ElecZapCrystal::Init() {
    s32 var_ctr;
    void *block;
    void *cursor;
    void *slot;

    KDProp::Init();
    if (MKHeap::Current() != NULL) {
        block = MKHeap::Current()->Alloc(0x88, NULL, 0);
    } else {
        block = malloc(0x88);
    }
    this->unkB0 = block;
    cursor = block;
    this->unkB0 = (void *) ((u8 *) cursor + 0x60);
    M2C_FIELD(cursor, void **, 0x60) = NULL;
    var_ctr = 8;
    do {
        slot = this->unkB0;
        this->unkB0 = (void *) ((u8 *) slot + 4);
        M2C_FIELD(slot, void **, 4) = cursor;
        cursor = (void *) ((u8 *) cursor + 0xC);
        var_ctr -= 1;
    } while (var_ctr != 0);
    slot = this->unkB0;
    this->unkB0 = (void *) ((u8 *) slot + 4);
    M2C_FIELD(slot, void **, 4) = NULL;
    this->unkBC = 0.0f;
    this->unkB4 = 0;
    this->unkC0 = 0.0f;
    this->unkD8.unk0 = 0.0f;
    this->unkD8.unk4 = 0.0f;
    this->unkD8.unk8 = 0.0f;
    this->unkC8.unk0 = 1.0f;
    this->unkC8.unk4 = 1.0f;
    this->unkC8.unk8 = 1.0f;
    this->unkC8.unkC = 1.0f;
}
