#include "spyro/source/WhirlWindFX.h"
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

M2C_UNK free(MKHeap *);                             /* extern */
MKHeap *malloc(M2C_UNK);                            /* extern */
extern M2C_UNK gEmptyPtrListDL;
extern f32 gUpdateTimeDelta;

#if 0 // DRAFT: type mismatch
void WhirlWindFX::Deinit() {
    MKHeap *temp_r0_51;
    MKHeap *temp_r0_70;
    MKHeap *temp_r3_73;
    MKHeap *var_r31_47;
    MKHeap *var_r3_48;
    MKHeap *var_r4_46;
    u32 temp_r0_56;

    var_r4_46 = this->unk4C;
    var_r31_47 = var_r4_46;
    var_r3_48 = var_r4_46;
loop_3:
    temp_r0_56 = M2C_FIELD(var_r3_48, u32 *, -4);
    var_r3_48 -= 4;
    if (temp_r0_56 != 0U) {
        temp_r0_51 = var_r3_48->unk0;
        if (temp_r0_51 < var_r31_47) {
            var_r31_47 = temp_r0_51;
        }
        goto loop_3;
    }
    if (var_r3_48 != &gEmptyPtrListDL) {
loop_9:
        temp_r0_70 = var_r4_46->unk0;
        if (temp_r0_70 != NULL) {
            if (temp_r0_70 < var_r31_47) {
                var_r31_47 = temp_r0_70;
            }
            var_r4_46 += 4;
            goto loop_9;
        }
        temp_r3_73 = var_r3_48->Current();
        if (temp_r3_73 != NULL) {
            ((MKHeap *) (temp_r3_73->Current()))->Free(var_r31_47, NULL, 0);
        } else {
            free(var_r31_47);
        }
    }
    this->unk4C = NULL;
    MKProp::Deinit();
}
#endif

void WhirlWindFX::DrawWhirlWind(WhirlWindFX::WhirlWind *arg1) {

}

void WhirlWindFX::Draw() {
    MKHeap *temp_r4_120;
    MKHeap *var_r31_111;

    var_r31_111 = this->unk4C;
loop_2:
    if (var_r31_111 != NULL) {
        temp_r4_120 = var_r31_111->unk0;
        if (temp_r4_120 != NULL) {
            DrawWhirlWind((WhirlWindFX::WhirlWind *) temp_r4_120);
            var_r31_111 += 4;
            goto loop_2;
        }
    }
}

void *WhirlWindFX::Update() {
    MKHeap *temp_r4_146;
    MKHeap *temp_r4_158;
    MKHeap *temp_r5_149;
    MKHeap *var_r6_134;

    var_r6_134 = this->unk4C;
loop_4:
    if (var_r6_134 != NULL) {
        temp_r4_158 = var_r6_134->unk0;
        if (temp_r4_158 == NULL) {
            return;
        }
        temp_r4_158->unk40 = M2C_BITWISE(f32, temp_r4_158->unk40) - gUpdateTimeDelta;
        if (M2C_BITWISE(f32, temp_r4_158->unk40) <= 0.0f) {
            temp_r4_146 = this->unk4C;
            this->unk4C = (MKHeap *) &temp_r4_146->unk4;
            temp_r5_149 = temp_r4_146->unk0;
            temp_r4_146->unk0 = var_r6_134->unk0;
            var_r6_134->unk0 = temp_r5_149;
        }
        var_r6_134 += 4;
        goto loop_4;
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void WhirlWindFX::Init() {
    MKHeap *temp_r3_173;
    MKHeap *temp_r3_195;
    MKHeap *temp_r3_201;
    MKHeap *var_r3_180;
    MKHeap *var_r5_189;
    s32 var_ctr_193;

    MKProp::Init();
    temp_r3_173 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_173 != NULL) {
        var_r3_180 = ((MKHeap *) (temp_r3_173->Current()))->Alloc(0x350, NULL, 0);
    } else {
        var_r3_180 = malloc(0x350);
    }
    this->unk4C = var_r3_180;
    var_r5_189 = this->unk4C;
    this->unk4C = var_r5_189 + 0x320;
    M2C_FIELD(var_r5_189, s32 *, 0x320) = 0;
    var_ctr_193 = 0xA;
    do {
        temp_r3_195 = this->unk4C;
        this->unk4C = (MKHeap *) &temp_r3_195->unk4;
        temp_r3_195->unk4 = (s32) var_r5_189;
        var_r5_189 += 0x50;
        var_ctr_193 -= 1;
    } while (var_ctr_193 != 0);
    temp_r3_201 = this->unk4C;
    this->unk4C = (MKHeap *) &temp_r3_201->unk4;
    temp_r3_201->unk4 = 0;
}
#endif
