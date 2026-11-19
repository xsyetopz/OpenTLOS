#include "spyro/source/Names.h"
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
#include "common/Source/FileSys.h"
#include "common/Source/StdMath.h"
#include "common/Source/Str.h"
#include "spyro/source/GameLanguage.h"
#include <m2c_macros.h>

M2C_UNK __construct_array(struct _struct_firstNames_0x8 *, Names *(*)(Names *), M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK free(u8 *);                                 /* extern */
extern u8 gNullStr;
extern s32 gViewSeed;
static M2C_UNK pFirstNames;                         /* unable to generate initializer: unknown type */
static M2C_UNK pLastNames;                          /* unable to generate initializer: unknown type */
#if 0 // DRAFT: illegal use of incomplete struct/union/class '_struct_firstNames_0x8'
static struct _struct_firstNames_0x8 firstNames[6];
#endif
#if 0 // DRAFT: illegal use of incomplete struct/union/class '_struct_lastNames_0x8'
static struct _struct_lastNames_0x8 lastNames[6];
#endif

u8 *Name::GetName() {
    u8 *temp_r4_14;
    u8 *temp_r5_17;

    temp_r4_14 = this->unk0;
    if (temp_r4_14 != NULL) {
        temp_r5_17 = this->unk4;
        if (temp_r5_17 != NULL) {
            return (unsigned char *) (Str_Printf("%s %s", temp_r4_14, temp_r5_17));
        }
        return temp_r4_14;
    }
    return &gNullStr;
}

#if 0 // DRAFT: undefined identifier 'firstNames'
void Name::Create(int arg0) {
    if (arg0 == -1) {
        this->unk4 = NULL;
        this->unk0 = NULL;
        return;
    }
    this->unk0 = ((Names *) &firstNames[arg0])->GetRandom();
    this->unk4 = ((Names *) &lastNames[arg0])->GetRandom();
}
#endif

u8 *Names::GetRandom() {
    u8 *temp_r5_90;
    u8 *var_r3_81;
    u8 *var_r6_107;
    u8 temp_r4_112;
    u8 temp_r4_136;
    u8 temp_r4_92;

    var_r3_81 = NULL;
    if ((u8 *) this->unk0 != NULL) {
        temp_r5_90 = this->unk0;
        var_r3_81 = &temp_r5_90[MKRand_Int((int *) &gViewSeed, 0, this->unk4 - 3)];
        temp_r4_92 = *var_r3_81;
        if (((s8) temp_r4_92 == 0) || ((s8) temp_r4_92 == 0xA) || ((s8) temp_r4_92 == 0xD)) {
            var_r3_81 -= 2;
        }
        if (var_r3_81 < temp_r5_90) {
            var_r3_81 = temp_r5_90;
        }
        var_r6_107 = var_r3_81;
loop_9:
        temp_r4_112 = *var_r3_81;
        if (((s8) temp_r4_112 != 0) && ((s8) temp_r4_112 != 0xA) && ((s8) temp_r4_112 != 0xD) && (var_r3_81 != temp_r5_90)) {
            var_r3_81 -= 1;
            goto loop_9;
        }
        if (((s8) temp_r4_112 == 0) || ((s8) temp_r4_112 == 0xA) || ((s8) temp_r4_112 == 0xD)) {
            var_r3_81 += 1;
        }
loop_18:
        temp_r4_136 = *var_r6_107;
        if (((s8) temp_r4_136 != 0) && ((s8) temp_r4_136 != 0xA) && ((s8) temp_r4_136 != 0xD)) {
            var_r6_107 += 1;
            goto loop_18;
        }
        *var_r6_107 = 0;
    }
    return var_r3_81;
}

void Names::Deinit() {
    u8 *temp_r31_163;

    temp_r31_163 = this->unk0;
    if (temp_r31_163 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_163, NULL, 0);
        } else {
            free(temp_r31_163);
        }
        this->unk0 = NULL;
        this->unk4 = 0;
    }
}

void Names::Init(const char *arg0) {
    if (MKArchive_Exists(arg0, NULL) != 0) {
        this->unk0 = (unsigned char *) (MKArchive_Load(arg0, (int *) &this->unk4, NULL, 0));
    }
}

#if 0 // DRAFT: undefined identifier 'lastNames'
void Names_DeinitModule() {
    s32 var_r28_228;
    s32 var_r31_230;

    var_r28_228 = 5;
    var_r31_230 = 0x28;
    do {
        ((Names *) (lastNames + var_r31_230))->Deinit();
        ((Names *) (firstNames + var_r31_230))->Deinit();
        var_r28_228 -= 1;
        var_r31_230 -= 8;
    } while (var_r28_228 >= 0);
}
#endif

#if 0 // DRAFT: function call 'Str_Printf(signed char *, long)' does not match 'Str_Printf(const char *, ...)'
void Names_InitModule() {
    M2C_UNK temp_r27_258;
    s32 var_r26_257;
    s32 var_r30_262;
    s32 var_r31_261;
    s8 *temp_r3_264;
    s8 *temp_r3_276;

    GameLanguage_GetCode(-1);
    var_r26_257 = 0;
    temp_r27_258 = M2C_ERROR(/* Read from unset register $r3 */);
    var_r31_261 = 0;
    var_r30_262 = 0;
    do {
        temp_r3_264 = (signed char *) (*(&pFirstNames + var_r30_262));
        if (temp_r3_264 != NULL) {
            ((Names *) (firstNames + var_r31_261))->Init(Str_Printf(temp_r3_264, temp_r27_258));
        }
        temp_r3_276 = (signed char *) (*(&pLastNames + var_r30_262));
        if (temp_r3_276 != NULL) {
            ((Names *) (lastNames + var_r31_261))->Init(Str_Printf(temp_r3_276, temp_r27_258));
        }
        var_r26_257 += 1;
        var_r30_262 += 4;
        var_r31_261 += 8;
    } while (var_r26_257 < 6);
}
#endif

#if 0 // DRAFT: '(' expected
void Names_cpp::__sinit() {
    __construct_array(firstNames, &Names::Names, 0, 8, 6);
    __construct_array((struct _struct_firstNames_0x8 *) lastNames, &Names::Names, 0, 8, 6);
}
#endif
