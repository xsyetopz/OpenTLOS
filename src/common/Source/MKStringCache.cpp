#include "common/Source/MKStringCache.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Level.h"
#include <m2c_macros.h>

M2C_UNK free(MKStringCache *);                      /* extern */
MKStringCache *malloc(MKStringCache *);             /* extern */
void *realloc(MKStringCache *, void *);             /* extern */
s32 strcmpi(s8 *, s8 *);                            /* extern */

MKHeap *MKStringCache::GetUsedLength() {
    s8 *var_r31_16;

    var_r31_16 = &this->unk1;
    while (*var_r31_16 != 0) {
        var_r31_16 = &var_r31_16[strlen((const char *) var_r31_16)] + 1;
    }
    return (MKHeap *) ((u32) ((s8 *) var_r31_16 - (s8 *) this) + 1);
}

MKStringCache *MKStringCache::Add(const char *arg0) {
    s32 temp_r3_57;
    s32 var_r3_75;
    s8 *var_r29_51;
    u32 temp_r30_53;

    if ((s8) (u8) *arg0 == 0) {
        return this;
    }
    var_r29_51 = &this->unk1;
    temp_r30_53 = strlen(arg0);
    while (*var_r29_51 != 0) {
        temp_r3_57 = strlen((const char *) var_r29_51);
        if ((temp_r3_57 == (s32) temp_r30_53) && (strcmpi(var_r29_51, (s8 *) arg0) == 0)) {
            return (MKStringCache *) var_r29_51;
        }
        var_r29_51 = &var_r29_51[temp_r3_57] + 1;
    }
    var_r3_75 = 0;
loop_10:
    if (((s8) M2C_FIELD(&var_r29_51[var_r3_75], u8 *, 1) != 0) && (var_r3_75 < (s32) temp_r30_53)) {
        var_r3_75 += 1;
        goto loop_10;
    }
    if (var_r3_75 < (s32) temp_r30_53) {
        return this;
    }
    strcpy((char *) var_r29_51, arg0);
    M2C_FIELD(&var_r29_51[temp_r30_53], s8 *, 1) = 0;
    return (MKStringCache *) var_r29_51;
}

MKStringCache *MKStringCache::Find(const char *arg0) {
    s32 temp_r3_127;
    s8 *var_r29_120;
    u32 temp_r30_123;

    if ((s8) (u8) *arg0 == 0) {
        return this;
    }
    var_r29_120 = &this->unk1;
    temp_r30_123 = strlen(arg0);
    while (*var_r29_120 != 0) {
        temp_r3_127 = strlen((const char *) var_r29_120);
        if ((temp_r3_127 == (s32) temp_r30_123) && (strcmpi(var_r29_120, (s8 *) arg0) == 0)) {
            return (MKStringCache *) var_r29_120;
        }
        var_r29_120 = &var_r29_120[temp_r3_127] + 1;
    }
    return NULL;
}

void MKStringCache::Optimise() {
    u32 temp_r31_163;
    void *var_r3_172;

    temp_r31_163 = (u32) GetUsedLength();
    if (MKHeap::Current() != NULL) {
        var_r3_172 = ((MKHeap *) (MKHeap::Current()))->ReAlloc(this, (s32) (temp_r31_163 + 2), NULL, 0);
    } else {
        var_r3_172 = realloc(this, (void *) (temp_r31_163 + 2));
    }
    M2C_FIELD((((u8 *) var_r3_172) + temp_r31_163), s8 *, 1) = 0;
}

void MKStringCache::Init(int arg0) {
    memset(this, 1, (u32) arg0);
    M2C_FIELD((this + arg0), s8 *, -1) = 0;
    this->unk1 = 0;
    this->unk0 = 0;
}

void MKStringCache::Destroy() {
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(this, NULL, 0);
        return;
    }
    free(this);
}

MKStringCache *MKStringCache::Create(int arg0) {
    MKStringCache *var_r31_257;

    if (MKHeap::Current() != NULL) {
        var_r31_257 = (MKStringCache *) (((MKHeap *) (MKHeap::Current()))->Alloc((s32) this, NULL, 0));
    } else {
        var_r31_257 = malloc(this);
    }
    var_r31_257->Init((s32) this);
    return var_r31_257;
}
