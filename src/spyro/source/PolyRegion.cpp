#include "spyro/source/PolyRegion.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/BoundingRegion.h"
#include "spyro/source/Level.h"
#include <m2c_macros.h>

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
M2C_UNK free(MKVector3 *);                          /* extern */
MKVector3 *malloc(s32);                             /* extern */

s32 PolyRegion::LoadLine(char *arg0, MKIniLine *arg1) {
    MKIniLine *var_r27_42;
    MKVector3 *var_r3_31;
    f32 temp_f1_58;
    f32 temp_f1_66;
    s32 temp_r28_23;
    s32 var_r29_44;

    if (arg1->IsField(arg0) != 0) {
        temp_r28_23 = arg1->GetNmbrOfSubLines() * 0x10;
        if (MKHeap::Current() != NULL) {
            var_r3_31 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r28_23, NULL, 0);
        } else {
            var_r3_31 = malloc(temp_r28_23);
        }
        this->unk0 = var_r3_31;
        var_r27_42 = arg1->unkC->GetSubLine(arg1);
        var_r29_44 = 0;
loop_12:
        if (var_r27_42 != NULL) {
            if (var_r27_42->LoadVector3("waypoint", this->unk0 + var_r29_44, 0) != 0) {
                temp_f1_58 = *(this->unk0 + (var_r29_44 + 4));
                if (temp_f1_58 < this->unk4.unk18) {
                    this->unk4.unk18 = temp_f1_58;
                }
                temp_f1_66 = *(this->unk0 + (var_r29_44 + 4));
                if (temp_f1_66 > this->unk4.unk1C) {
                    this->unk4.unk1C = temp_f1_66;
                }
                var_r29_44 += 0x10;
            }
            var_r27_42 = var_r27_42->unkC->GetNextLine(var_r27_42);
            goto loop_12;
        }
        ((BoundingRegion *) &this->unk4)->Init(this->unk0, arg1->GetNmbrOfSubLines());
        this->unk30 = M2C_FIELD(this, f32 *, 0x10);
        this->unk34 = this->unk4.unk10;
        this->unk40 = M2C_FIELD(this, f32 *, 0x14);
        this->unk44 = this->unk4.unk14;
        this->unk30 = this->unk4.unk18;
        this->unk40 = this->unk4.unk1C;
        M2C_FIELD(this, f32 *, 0x40) = (f64) ((f64) M2C_FIELD(this, f32 *, 0x40) - (f64) M2C_FIELD(this, f32 *, 0x30));
        this->unk44 -= this->unk34;
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'free'
void PolyRegion::Deinit() {
    MKVector3 *temp_r31_128;

    temp_r31_128 = this->unk0;
    if (temp_r31_128 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_128, NULL, 0);
        } else {
            free(temp_r31_128);
        }
        this->unk0 = NULL;
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__float_max'
void PolyRegion::Init() {
    this->unk0 = NULL;
    this->unk4.unk18 = __float_max;
    this->unk4.unk1C = __float_min;
}
#endif
