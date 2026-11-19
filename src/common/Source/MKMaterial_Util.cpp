#include "common/Source/MKMaterial_Util.h"
#include "common/Source/MKHeap.h"
#include <m2c_macros.h>

void *malloc(M2C_UNK);                              /* extern */
extern void *gpMKMaterialTypeInfoList;

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKMaterialTypeInfo'
void MKMaterialInternal_AddTypeToList(MKMaterialTypeInfo *arg0) {
    MKHeap *temp_r3_16;
    void *temp_r0_43;
    void *var_r3_23;
    void *var_r4_38;

    temp_r3_16 = arg0->Current();
    if (temp_r3_16 != NULL) {
        var_r3_23 = ((MKHeap *) (temp_r3_16->Current()))->Alloc(8, NULL, 0);
    } else {
        var_r3_23 = malloc(8);
    }
    M2C_FIELD(var_r3_23, MKMaterialTypeInfo **, 0) = arg0;
    M2C_FIELD(var_r3_23, s32 *, 4) = 0;
    if ((void *) gpMKMaterialTypeInfoList == NULL) {
        gpMKMaterialTypeInfoList = var_r3_23;
        return;
    }
    var_r4_38 = gpMKMaterialTypeInfoList;
loop_7:
    temp_r0_43 = M2C_FIELD(var_r4_38, void **, 4);
    if (temp_r0_43 != NULL) {
        var_r4_38 = temp_r0_43;
        goto loop_7;
    }
    M2C_FIELD(var_r4_38, void **, 4) = var_r3_23;
}
#endif
