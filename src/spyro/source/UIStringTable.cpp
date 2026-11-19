#include "spyro/source/UIStringTable.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKStringCache.h"
#include "common/Source/MKVector4.h"
#include "spyro/source/Level.h"
#include <m2c_macros.h>

extern UIStringTable *pStringTable;

s32 UIStringTable::Remove(const char *arg0) {
    MKStringCache *temp_r3_18;
    u8 var_r31_19;

    if (arg0 != NULL) {
        temp_r3_18 = this->unk4;
        var_r31_19 = 0;
        if (((s32) arg0 >= (s32) temp_r3_18) && ((s32) arg0 < (s32) this->unk4 + (s32) temp_r3_18->GetUsedLength())) {
            var_r31_19 = 1;
        }
        if (var_r31_19 == 0) {
            return 0;
        }
        goto block_6;
    }
block_6:
    if (this->unk4->Find(arg0) == NULL) {
        return 0;
    }
    this->unk0 -= 1;
    return 1;
}

s32 UIStringTable::Add(const char *arg0) {
    if (arg0 == NULL) {
        return 0;
    }
    this->unk0 += 1;
    return (long) (this->unk4->Add(arg0));
}

void UIStringTable::Deinit() {
    this->unk4->Destroy();
    this->unk4 = NULL;
}

void UIStringTable::Init(int arg0) {
    this->unk4 = ((MKStringCache *) arg0)->Create(arg0);
    this->unk0 = 0;
}

UIStringTable::UIStringTable() {
    this->unk4 = NULL;
    this->unk0 = 0;
}

void UIStringTable_Remove(const char *arg0) {
    pStringTable->Remove(arg0);
}

void UIStringTable_Add(const char *arg0) {
    pStringTable->Add(arg0);
}

UIStringTable *UIStringTable_GetCurrent() {
    return pStringTable;
}

UIStringTable *UIStringTable_SetCurrent(UIStringTable *arg0) {
    UIStringTable *temp_r0_165;

    temp_r0_165 = pStringTable;
    pStringTable = arg0;
    return temp_r0_165;
}
