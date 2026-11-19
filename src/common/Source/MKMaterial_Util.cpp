#include "common/Source/MKMaterial_Util.h"
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

void *malloc(M2C_UNK);                              /* extern */
extern void *gpMKMaterialTypeInfoList;

void MKMaterialInternal_AddTypeToList(MKMaterialTypeInfo *arg0) {
    MKHeap *temp_r3_16;
    void *temp_r0_43;
    void *var_r3_23;
    void *var_r4_38;

    temp_r3_16 = ((MKHeap *) arg0)->Current();
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
