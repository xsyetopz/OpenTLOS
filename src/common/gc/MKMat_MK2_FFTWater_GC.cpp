#include "common/gc/MKMat_MK2_FFTWater_GC.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMat_MK2_Standard.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/Level.h"
#include "dolphin/gx.h"
#include "common/Source/FileSys.h"
#include "common/Source/Str.h"
#include <m2c_macros.h>

M2C_UNK free(MKMaterial *);                         /* extern */
void *malloc(M2C_UNK);                              /* extern */
static M2C_UNK wState;

s32 MKMat_MK2_FFTWater_BEGIN_INTERNAL() {
    if ((s32) M2C_FIELD(&wState, s32 *, 4) == 0) {
        M2C_FIELD(&wState, s32 *, 4) = (s32) (M2C_FIELD(&wState, s32 *, 4) + 1);
        return 1;
    }
    M2C_FIELD(&wState, s32 *, 4) = 0;
    return 0;
}

s32 MKMat_MK2_FFTWater_BEGIN(MKMaterial *arg0) {
    return 0;
}

void MKMat_MK2_FFTWater_DESTROY(MKMaterial *arg0) {
    arg0->unk38->Destroy();
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(arg0, NULL, 0);
        return;
    }
    free(arg0);
}

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to 'const char *'
void *MKMat_MK2_FFTWater_INIT(MatInfo *arg0) {
    MKHeap *temp_ret_96;
    Texture *temp_r30_92;
    s32 temp_ret_106;
    u32 var_r4_90;
    void *var_r31_80;

    if (MKHeap::Current() != NULL) {
        var_r31_80 = ((MKHeap *) (MKHeap::Current()))->Alloc(0x3C, NULL, 0);
    } else {
        var_r31_80 = malloc(0x3C);
    }
    var_r4_90 = (u32) (u64) memset(var_r31_80, 0, 0x3CU);
    M2C_FIELD(var_r31_80, MatInfo **, 0x24) = arg0;
    temp_r30_92 = &arg0->unkE8;
    if (((s8) (u8) arg0->unkE8.unk0 != 0) && ((temp_ret_96 = Texture::Find(&temp_r30_92->unk0), var_r4_90 = (u32) (u64) temp_ret_96, ((temp_ret_96 == NULL) == 0)) || (temp_ret_106 = MKArchive_Exists(Str_Printf("%s%s", temp_r30_92, ".tex", M2C_BITWISE(f32, temp_ret_96)), NULL), var_r4_90 = (u32) (u64) temp_ret_106, ((temp_ret_106 == 0) == 0)))) {
        M2C_FIELD(var_r31_80, s8 **, 0x38) = (const char *) (temp_r30_92->Create((s8 *) var_r4_90, 0.0f));
    } else {
        M2C_FIELD(var_r31_80, s8 **, 0x38) = (const char *) (((Texture *) "MKWhite")->Create((s8 *) var_r4_90, 0.0f));
    }
    return var_r31_80;
}
#endif

void MKMat_MK2_FFTWater_DEREGISTER() {
    ((Texture *) (M2C_FIELD(&wState, Texture **, 0x14)))->Destroy();
    ((Texture *) (M2C_FIELD(&wState, Texture **, 0x10)))->Destroy();
}

#if 0 // DRAFT: function call 'memcpy(_GXTexObj *, long, unsigned int)' does not match 'memcpy(void *, const void *, unsigned int)'
void MKMat_MK2_FFTWater_REGISTER(void *arg0) {
    GXTexObj *temp_r31_169;
    s32 temp_r6_166;

    Texture::CreateRenderTarget("capture", 0x100, 0x100, 0);
    temp_r6_166 = M2C_ERROR(/* Read from unset register $r3 */);
    temp_r31_169 = (_GXTexObj *) (&wState + 0x18);
    M2C_FIELD(&wState, s32 *, 0x10) = temp_r6_166;
    memcpy(temp_r31_169, temp_r6_166 + 0x60, 0x20U);
    GXInitTexObjWrapMode(temp_r31_169, GX_CLAMP, GX_CLAMP);
}
#endif
