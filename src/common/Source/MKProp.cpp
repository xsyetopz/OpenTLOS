#include "common/Source/MKProp.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/Level.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_enums.h"
#include "common/Source/FileSys.h"
#include "common/Source/MKMat_MK2_Standard.h"
#include "common/Source/Str.h"
#include "common/Source/system_extras.h"
#include <m2c_macros.h>

M2C_UNK free(s8 *);                                 /* extern */
s32 stricmp(M2C_UNK *, Texture *);                  /* extern */
extern void *gMK;

#if 0 // DRAFT: identifier 'MKPropDescriptor::CreateInstance()' redeclared
void *MKPropDescriptor::CreateInstance() {
    void *var_r31_18;

    var_r31_18 = this->unk28;
loop_4:
    if (var_r31_18 == NULL) {
        return NULL;
    }
    if (M2C_FIELD(var_r31_18, s32 *, 0x18) & 0x80000000) {
        M2C_FIELD(M2C_FIELD(var_r31_18, void **, 0x44), M2C_UNK (**)(void *), 0x30)(var_r31_18);
        return var_r31_18;
    }
    var_r31_18 = M2C_FIELD(var_r31_18, void **, 0x38);
    goto loop_4;
}
#endif

#if 0 // DRAFT: function call 'stricmp(const char[6])' does not match
void MKPropDescriptor::ParseGMSection(MKIni *arg0, MKIniLine *arg1) {
    MKIniLine *temp_r3_58;
    MKIniLine *var_r31_54;

    var_r31_54 = arg1;
loop_1:
    temp_r3_58 = arg0->GetNextLine(var_r31_54);
    var_r31_54 = temp_r3_58;
    if ((var_r31_54 != NULL) && (temp_r3_58->GetFieldName() != NULL)) {
        var_r31_54->GetFieldName();
        if (stricmp("alias") != 0) {
            LoadLine(var_r31_54);
        }
    }
    if ((var_r31_54 != NULL) && (var_r31_54->GetSectionName() == NULL)) {
        goto loop_1;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const char[6]' to
void MKPropDescriptor::LoadDone() {
    f32 sp8;
    BoundingVolume *temp_r3_358;
    M2C_UNK *var_r4_110;
    MKIni *temp_r3_136;
    MKIni *var_r3_103;
    MKIniLine *temp_ret_114;
    MKMaterial *temp_r3_324;
    MKModel *temp_r3_194;
    f32 temp_f0_362;
    f32 temp_f1_209;
    f32 temp_f1_361;
    f32 temp_f2_364;
    f32 var_f1_153;
    f32 var_f4_368;
    f64 temp_f1_371;
    f64 temp_f1_377;
    f64 temp_f1_381;
    s32 temp_r3_400;
    s32 temp_ret_153;
    s32 temp_ret_158;
    s32 temp_ret_163;
    s32 temp_ret_209;
    s32 temp_ret_279;
    s32 var_r0_410;
    s32 var_r28_317;
    s8 *temp_r3_124;
    s8 *temp_r3_212;
    s8 *temp_r3_264;
    s8 *temp_r3_301;
    s8 *temp_ret_129;
    s8 *temp_ret_136;
    s8 *temp_ret_142;
    s8 *temp_ret_149;
    s8 *var_r31_117;
    void *temp_r3_337;

    if ((void *) gMK != NULL) {
        var_r3_103 = M2C_FIELD(gMK, MKIni **, 0x24);
    } else {
        var_r3_103 = NULL;
    }
    var_r4_110 = "alias";
    if ((var_r3_103 != NULL) && (temp_ret_114 = var_r3_103->GotoLine(this->unk0, "cacheWorldspace"), var_r4_110 = (M2C_UNK *) (u32) (u64) temp_ret_114, ((temp_ret_114 == NULL) == 0))) {
        var_r31_117 = (s8 *)1;
    } else {
        var_r31_117 = NULL;
    }
    ((MKCloth *)1)->DisableClothCreate((u8) var_r4_110);
    temp_r3_124 = this->unk34;
    if (temp_r3_124 != NULL) {
        temp_ret_129 = Str_Printf(temp_r3_124, this->unk0);
        temp_ret_136 = Str_Printf("%s%s", temp_ret_129, ".bad", M2C_BITWISE(f32, temp_ret_129));
        temp_r3_136 = temp_ret_136;
        temp_ret_142 = Str_Printf(this->unk34, this->unk0, M2C_BITWISE(f32, temp_ret_136));
        temp_ret_149 = Str_Printf("%s%s", temp_ret_142, ".bbi", M2C_BITWISE(f32, temp_ret_142));
        temp_ret_153 = temp_r3_136->Exists((s8 *) (u32) (u64) temp_ret_149);
        var_f1_153 = M2C_BITWISE(f32, temp_ret_153);
        if ((temp_ret_153 != 0) || (temp_ret_158 = MKArchive_Exists(&temp_r3_136->unk0, NULL), var_f1_153 = M2C_BITWISE(f32, temp_ret_158), ((temp_ret_158 == 0) == 0)) || (temp_ret_163 = MKArchive_Exists(temp_ret_149, NULL), var_f1_153 = M2C_BITWISE(f32, temp_ret_163), ((temp_ret_163 == 0) == 0))) {
            this->unk34 = ((MKAnimScript *) (Str_Printf(this->unk34, this->unk0, var_f1_153)))->Create(var_r31_117, M2C_ERROR(/* Read from unset register $r5 */));
            this->unk2C = M2C_FIELD(this->unk34, MKModel **, 8);
            this->unk30 = MKModel_GetAnimation(M2C_FIELD(this->unk34, MKModel **, 8));
            this->unk1C = MKModel_GetBoundingVolume(this->unk2C, (SubObjectType) 0, -1);
        } else {
            this->unk34 = NULL;
            this->unk2C = NULL;
            this->unk30 = NULL;
        }
    } else {
        temp_r3_194 = this->unk2C;
        if (temp_r3_194 != NULL) {
            RemStaticPrefix(Str_Printf((s8 *) temp_r3_194, this->unk0));
            temp_ret_209 = MKArchive_Exists(Str_Printf("%s%s", M2C_ERROR(/* Read from unset register $r3 */), ".mdl"), NULL);
            temp_f1_209 = M2C_BITWISE(f32, temp_ret_209);
            if (temp_ret_209 != 0) {
                temp_r3_212 = this->unk30;
                if (temp_r3_212 != NULL) {
                    RemStaticPrefix(Str_Printf(temp_r3_212, this->unk0, temp_f1_209));
                    RemStaticPrefix(Str_Printf((s8 *) this->unk2C, this->unk0));
                    this->unk2C = MKModel_Create(M2C_ERROR(/* Read from unset register $r3 */), M2C_ERROR(/* Read from unset register $r3 */), 2, NULL);
                    this->unk30 = MKModel_GetAnimation(this->unk2C);
                } else {
                    RemStaticPrefix(Str_Printf((s8 *) this->unk2C, this->unk0, temp_f1_209));
                    this->unk2C = MKModel_Create(M2C_ERROR(/* Read from unset register $r3 */), NULL, 2, NULL);
                }
                this->unk1C = MKModel_GetBoundingVolume(this->unk2C, (SubObjectType) 0, -1);
            } else {
                this->unk2C = NULL;
                this->unk30 = NULL;
                this->unk14 &= 0xFFFFFFFC;
                this->unk14 |= 2;
            }
        } else {
            temp_r3_264 = this->unk30;
            if (temp_r3_264 != NULL) {
                RemStaticPrefix(Str_Printf(temp_r3_264, this->unk0));
                temp_ret_279 = MKArchive_Exists(Str_Printf("%s%s", M2C_ERROR(/* Read from unset register $r3 */), ".anm"), NULL);
                if (temp_ret_279 != 0) {
                    RemStaticPrefix(Str_Printf(this->unk30, this->unk0, M2C_BITWISE(f32, temp_ret_279)));
                    this->unk30 = ((Animation *) (M2C_ERROR(/* Read from unset register $r3 */)))->Create(var_r31_117, M2C_ERROR(/* Read from unset register $r5 */));
                } else {
                    this->unk30 = NULL;
                    this->unk14 &= 0xFFFFFFFC;
                    this->unk14 |= 2;
                }
            }
        }
    }
    temp_r3_301 = this->unk38;
    if (temp_r3_301 != NULL) {
        RemStaticPrefix(Str_Printf(temp_r3_301, this->unk0));
        this->unk38 = MKMaterial_Create(M2C_ERROR(/* Read from unset register $r3 */));
    }
    NULL->DisableClothCreate(M2C_ERROR(/* Read from unset register $r4 */));
    if ((MKModel *) this->unk2C != NULL) {
        var_r28_317 = 0;
loop_34:
        if (var_r28_317 < MKModel_GetNmbrOfMaterials(this->unk2C)) {
            temp_r3_324 = MKModel_GetMaterial(this->unk2C, var_r28_317, 0U);
            if (stricmp("capture", MKMat_MK2_GetBaseTexture(temp_r3_324)) == 0) {
                this->unk14 |= 0x400;
            }
            temp_r3_337 = temp_r3_324->unk24;
            if (!(M2C_FIELD(temp_r3_337, s32 *, 0x1E0) & 4) && !(this->unk14 & 0x40)) {
                M2C_FIELD(temp_r3_337, s32 *, 0x28) = 0;
            }
            var_r28_317 += 1;
            goto loop_34;
        }
    }
    if (this->unk20 == 0.0f) {
        temp_r3_358 = this->unk1C;
        if (temp_r3_358 != NULL) {
            temp_f1_361 = temp_r3_358->unk10;
            temp_f0_362 = temp_r3_358->unk14;
            temp_f2_364 = temp_r3_358->unk18;
            var_f4_368 = (temp_f2_364 * temp_f2_364) + ((temp_f1_361 * temp_f1_361) + (temp_f0_362 * temp_f0_362));
            if (var_f4_368 > 0.0f) {
                temp_f1_371 = __frsqrte(var_f4_368);
                temp_f1_377 = 0.5 * temp_f1_371 * -(((f64) var_f4_368 * (temp_f1_371 * temp_f1_371)) - 3.0);
                temp_f1_381 = 0.5 * temp_f1_377 * -(((f64) var_f4_368 * (temp_f1_377 * temp_f1_377)) - 3.0);
                var_f4_368 = (f32) ((f64) var_f4_368 * (0.5 * temp_f1_381 * -(((f64) var_f4_368 * (temp_f1_381 * temp_f1_381)) - 3.0)));
            } else if (var_f4_368 < M2C_BITWISE(f32, 0.0)) {
                var_f4_368 = __float_nan;
            } else {
                sp8 = var_f4_368;
                temp_r3_400 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_400) {              /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_410 = 1;
                    } else {
                        var_r0_410 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_410 = 5;
                    } else {
                        var_r0_410 = 3;
                    }
                    break;
                default:
                    var_r0_410 = 4;
                    break;
                }
                if (var_r0_410 == 1) {
                    var_f4_368 = __float_nan;
                }
            }
            this->unk20 = 200.0f + var_f4_368;
        }
    }
}
#endif

#if 0 // DRAFT: ')' expected
s32 MKPropDescriptor::LoadLine(MKIniLine *arg0) {
    s32 sp8;
    s32 temp_r30_548;
    s32 var_r0_1083;
    s32 var_r0_522;
    s32 var_r29_540;

    if (arg0->IsField("UpdatePriority") != 0) {
        arg0->AsInt(0, (int *) &this->unk18);
        return 1;
    }
    if (arg0->IsField("MaxDrawDist") != 0) {
        arg0->AsFloat(0, &this->unk8);
        return 1;
    }
    if (arg0->IsField("MaxUpdateDist") != 0) {
        arg0->AsFloat(0, &this->unk4);
        return 1;
    }
    if (arg0->IsField("maxScissorDist") != 0) {
        arg0->AsFloat(0, &this->unk20);
        return 1;
    }
    if (arg0->IsField("CanHandleMissingFiles") != 0) {
        arg0->AsFlag(0, (int *) &sp8);
        if (sp8 != 0) {
            var_r0_522 = this->unk14 | 0x20;
        } else {
            var_r0_522 = this->unk14 & 0xFFFFFFDF;
        }
        this->unk14 = var_r0_522;
        return 1;
    }
    if (arg0->IsField("Type") != 0) {
        var_r29_540 = 0;
loop_87:
        if (var_r29_540 < (s16) arg0->unk0) {
            temp_r30_548 = arg0->GetString(var_r29_540);
            if (stricmp"static" == 0) {
                this->unk14 &= 0xFFFFFFFC;
            } else if (stricmp((M2C_UNK *) temp_r30_548, "dynamic") == 0) {
                this->unk14 &= 0xFFFFFFFC;
                this->unk14 |= 1;
                this->unk14 &= 0xFFFFFFFB;
            } else if (stricmp((M2C_UNK *) temp_r30_548, "global") == 0) {
                this->unk14 &= 0xFFFFFFFC;
                this->unk14 |= 2;
                this->unk14 &= 0xFFFFFFFB;
            } else if ((stricmp((M2C_UNK *) temp_r30_548, "alpha") == 0) || (stricmp((M2C_UNK *) temp_r30_548, "alpha+") == 0)) {
                this->unk14 |= 0x80;
            } else if (stricmp((M2C_UNK *) temp_r30_548, "alpha-") == 0) {
                this->unk14 &= 0xFFFFFF7F;
            } else if ((stricmp((M2C_UNK *) temp_r30_548, "drawlast") == 0) || (stricmp((M2C_UNK *) temp_r30_548, "drawlast+") == 0)) {
                this->unk14 |= 0x100;
            } else if (stricmp((M2C_UNK *) temp_r30_548, "drawlast-") == 0) {
                this->unk14 &= 0xFFFFFEFF;
            } else if ((stricmp((M2C_UNK *) temp_r30_548, "update") == 0) || (stricmp((M2C_UNK *) temp_r30_548, "update+") == 0)) {
                this->unk14 &= 0xFFFFFFFB;
            } else if (stricmp((M2C_UNK *) temp_r30_548, "update-") == 0) {
                this->unk14 |= 4;
            } else if ((stricmp((M2C_UNK *) temp_r30_548, "draw") == 0) || (stricmp((M2C_UNK *) temp_r30_548, "draw+") == 0)) {
                this->unk14 &= 0xFFFFFFF7;
            } else if (stricmp((M2C_UNK *) temp_r30_548, "draw-") == 0) {
                this->unk14 |= 8;
            } else if (stricmp((M2C_UNK *) temp_r30_548, "belowwater-") == 0) {
                this->unk14 &= 0xFFFFFDFF;
            } else if ((stricmp((M2C_UNK *) temp_r30_548, "belowwater") == 0) || (stricmp((M2C_UNK *) temp_r30_548, "belowwater+") == 0)) {
                this->unk14 |= 0x200;
            } else if (stricmp((M2C_UNK *) temp_r30_548, "sortableGlobal-") == 0) {
                this->unk14 &= 0xFFFFF7FF;
            } else if ((stricmp((M2C_UNK *) temp_r30_548, "sortableGlobal") == 0) || (stricmp((M2C_UNK *) temp_r30_548, "sortableGlobal+") == 0)) {
                this->unk14 |= 0x800;
            } else if (stricmp((M2C_UNK *) temp_r30_548, "drawbeforewater-") == 0) {
                this->unk14 &= 0xFFFFEFFF;
            } else if ((stricmp((M2C_UNK *) temp_r30_548, "drawbeforewater") == 0) || (stricmp((M2C_UNK *) temp_r30_548, "drawbeforewater+") == 0)) {
                this->unk14 |= 0x1000;
            } else if (stricmp((M2C_UNK *) temp_r30_548, "prelit-") == 0) {
                this->unk14 &= 0xFFFFFFBF;
            } else if ((stricmp((M2C_UNK *) temp_r30_548, "prelit") == 0) || (stricmp((M2C_UNK *) temp_r30_548, "prelit+") == 0)) {
                this->unk14 |= 0x40;
            } else if (stricmp((M2C_UNK *) temp_r30_548, "capture-") == 0) {
                this->unk14 &= 0xFFFFFBFF;
            } else if ((stricmp((M2C_UNK *) temp_r30_548, "capture") == 0) || (stricmp((M2C_UNK *) temp_r30_548, "capture+") == 0)) {
                this->unk14 |= 0x400;
            } else if (stricmp((M2C_UNK *) temp_r30_548, "descCreateModelMatrices-") == 0) {
                this->unk14 |= 0x2000;
            } else if ((stricmp((M2C_UNK *) temp_r30_548, "descCreateModelMatrices") == 0) || (stricmp((M2C_UNK *) temp_r30_548, "descCreateModelMatrices+") == 0)) {
                this->unk14 &= 0xFFFFDFFF;
            } else if (stricmp((M2C_UNK *) temp_r30_548, "DontCreateDescModelMatrices-") == 0) {
                this->unk14 &= 0xFFFFDFFF;
            } else if ((stricmp((M2C_UNK *) temp_r30_548, "DontCreateDescModelMatrices") == 0) || (stricmp((M2C_UNK *) temp_r30_548, "DontCreateDescModelMatrices+") == 0)) {
                this->unk14 |= 0x2000;
            } else if (stricmp((M2C_UNK *) temp_r30_548, "CreateDescModelMatrices-") == 0) {
                this->unk14 |= 0x2000;
            } else if ((stricmp((M2C_UNK *) temp_r30_548, "CreateDescModelMatrices") == 0) || (stricmp((M2C_UNK *) temp_r30_548, "CreateDescModelMatrices+") == 0)) {
                this->unk14 &= 0xFFFFDFFF;
            } else if (stricmp((M2C_UNK *) temp_r30_548, "scissor-") == 0) {
                this->unk14 &= 0xFFFF7FFF;
            } else if ((stricmp((M2C_UNK *) temp_r30_548, "scissor") == 0) || (stricmp((M2C_UNK *) temp_r30_548, "scissor+") == 0)) {
                this->unk14 |= 0x8000;
            }
            var_r29_540 += 1;
            goto loop_87;
        }
        return 1;
    }
    if (arg0->IsField("BadFile") != 0) {
        arg0->AsString(0, &this->unk34);
        return 1;
    }
    if (arg0->IsField("Animation") != 0) {
        arg0->AsString(0, &this->unk30);
        return 1;
    }
    if (arg0->IsField("Model") != 0) {
        arg0->AsString(0, (s8 **) &this->unk2C);
    } else if (arg0->IsField("Material") != 0) {
        arg0->AsString(0, &this->unk38);
    } else if (arg0->IsField("Lit") != 0) {
        if (arg0->GetBool(0) != 0) {
            var_r0_1083 = this->unk14 & 0xFFFFFFBF;
        } else {
            var_r0_1083 = this->unk14 | 0x40;
        }
        this->unk14 = var_r0_1083;
    }
    return 0;
}
#endif

void RemStaticPrefix(const char *arg0) {
    f32 temp_f1_1112;
    s32 temp_ret_1112;

    temp_ret_1112 = strnicmp(arg0, "prop_static", 0xB);
    temp_f1_1112 = M2C_BITWISE(f32, temp_ret_1112);
    if (temp_ret_1112 == 0) {
        Str_Printf("prop_%s", arg0 + 0xB, temp_f1_1112);
        return;
    }
    Str_Printf(arg0, (u32) (u64) temp_ret_1112, temp_f1_1112);
}

void MKPropDescriptor::Resolve() {

}

void MKPropDescriptor::Draw() {

}

void MKPropDescriptor::Update() {

}

void MKPropDescriptor::Deinit() {
    MKModel *temp_r3_1168;
    s8 *temp_r31_1184;
    s8 *temp_r3_1160;
    s8 *temp_r3_1174;
    s8 *temp_r3_1179;

    temp_r3_1160 = this->unk34;
    if (temp_r3_1160 != NULL) {
        ((MKAnimScript *) temp_r3_1160)->Destroy();
        this->unk34 = NULL;
    } else {
        temp_r3_1168 = this->unk2C;
        if (temp_r3_1168 != NULL) {
            MKModel_Destroy(temp_r3_1168);
        } else {
            temp_r3_1174 = this->unk30;
            if (temp_r3_1174 != NULL) {
                ((Animation *) temp_r3_1174)->Destroy();
            }
        }
    }
    temp_r3_1179 = this->unk38;
    if (temp_r3_1179 != NULL) {
        MKMaterial_Destroy((MKMaterial *) temp_r3_1179);
    }
    temp_r31_1184 = this->unk0;
    if ((temp_r31_1184 != NULL) && (this->unk14 & 0x10000)) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_1184, NULL, 0);
            return;
        }
        free(temp_r31_1184);
    }
}

void MKPropDescriptor::Init() {
    this->unk10 = 0;
    this->unk3C = 0;
    this->unk28 = NULL;
    this->unk4 = 1000.0f;
    this->unk8 = 1000.0f;
    this->unkC = 0;
    this->unk14 = 0x8040;
    this->unk1C = NULL;
    this->unk20 = 0.0f;
    this->unk2C = NULL;
    this->unk30 = NULL;
    this->unk34 = NULL;
    this->unk38 = NULL;
    this->unk18 = 0;
}

void MKProp::Deinit() {
    MKModel *temp_r3_1248;

    if ((s32) this->unk14 > 0) {
        ((MKSceneManager *) this)->PropResolver_Remove(M2C_ERROR(/* Read from unset register $r4 */));
    }
    temp_r3_1248 = this->unk4;
    if (temp_r3_1248 != NULL) {
        MKModel_Destroy(temp_r3_1248);
    }
}

void MKProp::Message(MKMessage *arg0) {
    MKModel *temp_r3_1269;
    s32 temp_r0_1275;

    temp_r3_1269 = this->unk4;
    if ((temp_r3_1269 != NULL) && (MKModel_GetCloth(temp_r3_1269) != NULL)) {
        temp_r0_1275 = arg0->unk0;
        switch (temp_r0_1275) {                     /* irregular */
        case -3:
            MKModel_EnableClothUpdate(this->unk4, 1U);
            return;
        case -4:
            MKModel_EnableClothUpdate(this->unk4, 0U);
            break;
        }
    }
}

void MKProp::Draw() {

}

void *MKProp::Update() {

}

void MKProp::Reset() {

}

f32 MKProp::Resolve() {

}

#if 0 // DRAFT: illegal implicit conversion from 'long' to
s32 MKProp::LoadDone() {
    MKModel *temp_r3_1331;

    ((MKPropLoadInfo *) &MKProp::loadInfo)->LoadDone();
    temp_r3_1331 = this->unk4;
    if (temp_r3_1331 != NULL) {
        MKModel_SetWorldMatrix(temp_r3_1331, *((Matrix *) &MKProp::loadInfo));
        this->unk8 = MKModel_GetWorldMatrix(this->unk4);
        if (MKModel_GetCloth(this->unk4) != NULL) {
            this->unkC = MKModel_GetBoundingVolume(this->unk4, (SubObjectType) 0, -1);
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void' to
s32 MKProp::LoadLine(MKIniLine *arg0) {
    s32 var_r4_1383;

    if (arg0->LoadInt("ID", (int *) &this->unk14, 0) != 0) {
        if ((s32) this->unk14 != 0) {
            var_r4_1383 = arg0->GetString(1);
            if (var_r4_1383 != 0) {

            } else {
                var_r4_1383 = *this->unk0;
            }
            ((MKSceneManager *) this)->PropResolver_Add((MKProp *) var_r4_1383, M2C_ERROR(/* Read from unset register $r5 */));
        }
        return 1;
    }
    if (arg0->LoadInt("zone", (int *) &this->unk18, 0) != 0) {
        if ((u32) this->unk18 == 0U) {
            this->unk18 = 1;
        }
        return 1;
    }
    if (arg0->IsField("collide") != 0) {
        if (arg0->GetBool(0) != 0) {
            this->unk10 &= 0xFFFFFFEF;
        } else {
            this->unk10 |= 0x10;
        }
        goto block_17;
    }
    if (arg0->LoadInt("groupMask", (int *) &this->unk18, 0) != 0) {
        return 1;
    }
block_17:
    ((MKPropLoadInfo *) &MKProp::loadInfo)->LoadLine(arg0);
    return 0;
}
#endif

void MKProp::Init() {
    this->unk1E = 0;
    this->unk14 = 0;
    this->unk40 = 0;
    this->unk38 = NULL;
    this->unk48 = *MKResource::sWorkingChunkIndex;
    this->unk28 = NULL;
    this->unk2C = NULL;
    this->unk30 = NULL;
    this->unk34 = NULL;
    this->unk38 = NULL;
    this->unk3C = NULL;
    this->unk18 = 1;
    this->unk4 = NULL;
    this->unk8 = NULL;
    this->unk10 = M2C_FIELD(this->unk0, s32 *, 0x14);
    this->unk20 = 1.0f;
    this->unk24 = 0.0f;
    this->unkC = NULL;
    ((MKPropLoadInfo *) &MKProp::loadInfo)->Init();
}

void MKPropLoadInfo::LoadDone() {
    ((Matrix *) this)->SetRotationPYR(this->unk50);
    ((Matrix *) this)->Scale3x3((Matrix *) this, this->unk60);
    this->unk30 = this->unk40;
    this->unk34 = this->unk44;
    this->unk38 = this->unk48;
    this->unk3C = 1.0f;
}

s32 MKPropLoadInfo::LoadLine(MKIniLine *arg0) {
    s32 var_r31_1542;

    var_r31_1542 = 0;
    if ((arg0->LoadVector3("pos", (MKVector3 *) &this->unk40, 0) != 0) || (arg0->LoadVector3("rot", &this->unk50, 0) != 0) || (arg0->LoadVector3("scale", &this->unk60, 0) != 0) || (arg0->LoadVector4("color", &this->unk70, 0) != 0)) {
        var_r31_1542 = 1;
    }
    return var_r31_1542;
}

void MKPropLoadInfo::Init() {
    ((Matrix *) this)->SetIdentity();
    this->unk40 = 0.0f;
    this->unk44 = 0.0f;
    this->unk48 = 0.0f;
    this->unk50.unk0 = 0.0f;
    this->unk50.unk4 = 0.0f;
    this->unk50.unk8 = 0.0f;
    this->unk60.unk0 = 1.0f;
    this->unk60.unk4 = 1.0f;
    this->unk60.unk8 = 1.0f;
    this->unk70.unk0 = 1.0f;
    this->unk70.unk4 = 1.0f;
    this->unk70.unk8 = 1.0f;
    this->unk70.unkC = 1.0f;
}
