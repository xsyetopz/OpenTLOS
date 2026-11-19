#include "common/Source/MKStringCache.h"
#include "common/Source/MKHeap.h"
#include <m2c_macros.h>

#if 0 // DRAFT: function call 'strlen(signed char *)' does not match
M2C_UNK free(MKStringCache *);                      /* extern */
MKStringCache *malloc(MKStringCache *);             /* extern */
void *realloc(MKStringCache *, void *);             /* extern */
s32 strcmpi(s8 *, s8 *);                            /* extern */

MKHeap *MKStringCache::GetUsedLength() {
    s8 *var_r31_16;

    var_r31_16 = &this->unk1;
loop_2:
    if ((s8) (u8) *var_r31_16 != 0) {
        var_r31_16 = &var_r31_16[strlen(var_r31_16)] + 1;
        goto loop_2;
    }
    return (var_r31_16 - this) + 1;
}
#endif

#if 0 // DRAFT: function call 'strcpy(signed char *, const char *)' does not match
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
loop_7:
    if ((s8) (u8) *var_r29_51 == 0) {
        var_r3_75 = 0;
loop_10:
        if (((s8) M2C_FIELD(&var_r29_51[var_r3_75], u8 *, 1) != 0) && (var_r3_75 < (s32) temp_r30_53)) {
            var_r3_75 += 1;
            goto loop_10;
        }
        if (var_r3_75 < (s32) temp_r30_53) {
            return this;
        }
        strcpy(var_r29_51, arg0);
        M2C_FIELD(&var_r29_51[temp_r30_53], s8 *, 1) = 0;
        return (MKStringCache *) var_r29_51;
    }
    temp_r3_57 = strlen(var_r29_51);
    if ((temp_r3_57 == (s32) temp_r30_53) && (strcmpi(var_r29_51, arg0) == 0)) {
        return (MKStringCache *) var_r29_51;
    }
    var_r29_51 = &var_r29_51[temp_r3_57] + 1;
    goto loop_7;
}
#endif

#if 0 // DRAFT: function call 'strlen(signed char *)' does not match
MKStringCache *MKStringCache::Find(const char *arg0) {
    s32 temp_r3_127;
    s8 *var_r29_120;
    u32 temp_r30_123;

    if ((s8) (u8) *arg0 == 0) {
        return this;
    }
    var_r29_120 = &this->unk1;
    temp_r30_123 = strlen(arg0);
loop_7:
    if ((s8) (u8) *var_r29_120 == 0) {
        return NULL;
    }
    temp_r3_127 = strlen(var_r29_120);
    if ((temp_r3_127 == (s32) temp_r30_123) && (strcmpi(var_r29_120, arg0) == 0)) {
        return (MKStringCache *) var_r29_120;
    }
    var_r29_120 = &var_r29_120[temp_r3_127] + 1;
    goto loop_7;
}
#endif

#if 0 // DRAFT: illegal operand
void MKStringCache::Optimise() {
    MKHeap *temp_r3_162;
    MKHeap *temp_r3_164;
    void *var_r3_172;

    temp_r3_162 = GetUsedLength();
    temp_r3_164 = temp_r3_162->Current();
    if (temp_r3_164 != NULL) {
        var_r3_172 = ((MKHeap *) (temp_r3_164->Current()))->ReAlloc(this, (s32) (temp_r3_162 + 2), NULL, 0);
    } else {
        var_r3_172 = realloc(this, temp_r3_162 + 2);
    }
    M2C_FIELD((((u8 *) var_r3_172) + temp_r3_162), s8 *, 1) = 0;
}
#endif

void MKStringCache::Init(int arg0) {
    memset(this, 1, (u32) arg0);
    M2C_FIELD((this + arg0), s8 *, -1) = 0;
    this->unk1 = 0;
    this->unk0 = 0;
}

#if 0 // DRAFT: illegal use of non-static member
void MKStringCache::Destroy() {
    MKHeap *temp_r3_221;

    temp_r3_221 = MKHeap::Current();
    if (temp_r3_221 != NULL) {
        ((MKHeap *) (temp_r3_221->Current()))->Free(this, NULL, 0);
        return;
    }
    free(this);
}
#endif

#if 0 // DRAFT: illegal use of non-static member
MKStringCache *MKStringCache::Create(int arg0) {
    MKHeap *temp_r3_249;
    MKStringCache *var_r31_257;

    temp_r3_249 = MKHeap::Current();
    if (temp_r3_249 != NULL) {
        var_r31_257 = ((MKHeap *) (temp_r3_249->Current()))->Alloc((s32) this, NULL, 0);
    } else {
        var_r31_257 = malloc(this);
    }
    var_r31_257->Init((s32) this);
    return var_r31_257;
}
#endif
