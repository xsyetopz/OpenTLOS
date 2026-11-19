#include "spyro/source/PolyRegion.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKVector3.h"
#include <m2c_macros.h>

#if 0 // DRAFT: pointer/array required
M2C_UNK free(MKVector3 *);                          /* extern */
MKVector3 *malloc(s32);                             /* extern */

s32 PolyRegion::LoadLine(char *arg0, MKIniLine *arg1) {
    MKHeap *temp_r3_24;
    MKIniLine *var_r27_42;
    MKVector3 *var_r3_31;
    f32 temp_f1_58;
    f32 temp_f1_66;
    s32 temp_r28_23;
    s32 temp_r3_22;
    s32 var_r29_44;

    if (arg1->IsField(arg0) != 0) {
        temp_r3_22 = arg1->GetNmbrOfSubLines();
        temp_r28_23 = temp_r3_22 * 0x10;
        temp_r3_24 = temp_r3_22->Current();
        if (temp_r3_24 != NULL) {
            var_r3_31 = ((MKHeap *) (temp_r3_24->Current()))->Alloc(temp_r28_23, NULL, 0);
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
        this->unk4.Init(this->unk0, arg1->GetNmbrOfSubLines());
        this->unk30 = M2C_FIELD(this, f32 *, 0x10);
        this->unk34 = this->unk4.unk10;
        this->unk40 = M2C_FIELD(this, f32 *, 0x14);
        this->unk44 = this->unk4.unk14;
        this->unk30 = this->unk4.unk18;
        this->unk40 = this->unk4.unk1C;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r3, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r30, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        M2C_ERROR(/* unknown instruction: psq_stx $f0, $r30, $r3, 0x0, qr0 */);
        this->unk44 -= this->unk34;
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void PolyRegion::Deinit() {
    MKHeap *temp_r3_131;
    MKVector3 *temp_r31_128;

    temp_r31_128 = this->unk0;
    if (temp_r31_128 != NULL) {
        temp_r3_131 = MKHeap::Current();
        if (temp_r3_131 != NULL) {
            ((MKHeap *) (temp_r3_131->Current()))->Free(temp_r31_128, NULL, 0);
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
