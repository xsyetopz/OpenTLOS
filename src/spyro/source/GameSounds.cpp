#include "spyro/source/GameSounds.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/CustomMaterialUpdater.h"
#include "spyro/source/Level.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

extern s32 hint;
#if 0 // DRAFT: identifier 'soundIDs' redeclared
static M2C_UNK soundIDs;                            /* unable to generate initializer: unknown type */
static M2C_UNK *pCurrentID = &soundIDs;
#endif

#if 0 // DRAFT: function call 'KDSound_ResolveSound(signed char *, int *)' does not match
void GameSounds_Update() {
    s32 temp_cr0_eq_29;
    s32 var_r31_16;

    KDSound_Update();
    var_r31_16 = 0x64;
loop_2:
    temp_cr0_eq_29 = var_r31_16 == 0;
    var_r31_16 -= 1;
    if ((temp_cr0_eq_29 == 0) && ((s32 *) M2C_FIELD(pCurrentID, s32 **, 0) != NULL)) {
        *M2C_FIELD(pCurrentID, s32 **, 0) = KDSound_ResolveSound(M2C_FIELD(pCurrentID, s8 **, 4), (int *) &hint);
        pCurrentID += 8;
        goto loop_2;
    }
}
#endif

void GameSounds_InitModule() {
    Level::GetWorldInfo();
    KDSound_InitModule(0U, M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x68));
    Level::GetWorldInfo();
    Level::GetWorldInfo();
    KDSound_SetMasterVolume(M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 0x70), M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 0x6C));
}
