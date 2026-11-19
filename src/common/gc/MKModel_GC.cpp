#include "common/gc/MKModel_GC.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKGrass_MP.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MeshChunkExplorer_GC.h"
#include "spyro/source/Level.h"
#include "unplaced_enums.h"
#include "dolphin/gx.h"
#include "common/Source/GPInit.h"
#include "common/Source/MKGrass.h"
#include "common/Source/MKShockWave_MP.h"
#include <m2c_macros.h>

extern M2C_UNK lit_676;
extern s8 MKMaterialGC_bForceSkinnedVertexFormat;
extern s32 MKModel_BlendShapeTargets;
extern void *MKModel_pBlendShapeWeights;
extern MKMaterial *gRenderState;
#if 0 // DRAFT: identifier 'gShockWaveData' redeclared
extern M2C_UNK gShockWaveData;
#endif
extern s32 gpMKcurrentMaterialEffectorMask;
static M2C_UNK explorer_784;

#if 0 // DRAFT: illegal implicit conversion from 'const MKModel_Blob *' to
static M2C_UNK lit_806;                                /* unable to generate initializer: unknown type; const */

void MKModel_BlobDraw(const MKModel *arg0, int arg1, const MKModel_Blob *arg2) {
    s32 spC;
    s32 sp8;
    MKModel_Blob *var_r30_17;
    MeshChunk *var_r3_42;
    s32 var_r29_16;
    u32 temp_r3_38;
    void *temp_r31_24;
    void *temp_r4_34;

    var_r29_16 = arg1;
    var_r30_17 = arg2;
    sp8 = M2C_FIELD(&lit_806, s32 *, 0);
    spC = M2C_FIELD(&lit_806, s32 *, 4);
    MKMaterial_SetGeometryTransformInfo((GeometryTransformationInfo *) &sp8);
    temp_r31_24 = arg0->unk0;
loop_11:
    if (MKMaterial_Begin() != 0) {
loop_10:
        if (MKMaterial_BeginInternal() != 0) {
loop_9:
            if (var_r29_16 > 0) {
                MKMaterial_SetLocalToWorld((Matrix *) var_r30_17, 1.0f);
                MKMaterial_SetGeometryColor(*((MKVector4 *) &var_r30_17->unk40));
                temp_r4_34 = M2C_FIELD(temp_r31_24, void **, 0x30);
                temp_r3_38 = *(M2C_FIELD(temp_r4_34, s32 *, 0x68) + (var_r30_17->unk50 * 4));
                if (temp_r3_38 != 0U) {
                    var_r3_42 = M2C_FIELD(temp_r4_34, s32 *, 0x6C) + temp_r3_38;
                } else {
                    var_r3_42 = NULL;
                }
                if (var_r3_42 != NULL) {
                    MKMaterial_RenderMeshChunk(var_r3_42);
                }
                var_r30_17 += 0x60;
                var_r29_16 -= 1;
                goto loop_9;
            }
            goto loop_10;
        }
        goto loop_11;
    }
}
#endif

void MKModel_BlobBegin(const MKModel *arg0) {
    MKMaterial_SetMaterial(MKModel_GetMaterial(arg0, 0, 0U));
}

void MKModel_BlobPreprocess(MKModel *arg0) {

}

void MKModel_ExploreEnd(MeshChunkExplorer *arg0) {

}

s32 MKModel_ExploreNextStrip(MeshChunkExplorer *arg0) {
    s32 temp_r3_108;
    u16 *temp_r3_125;
    u16 *temp_r3_132;
    u16 *temp_r3_136;

    temp_r3_108 = arg0->unk0 + 1;
    arg0->unk0 = temp_r3_108;
    if (temp_r3_108 >= (s32) arg0->unk4) {
        arg0->unk44 = 0;
        return 0;
    }
    arg0->unk3C += arg0->unk8 * 9;
    temp_r3_125 = arg0->unk3C + 1;
    arg0->unk3C = temp_r3_125;
    arg0->unk3C = temp_r3_125;
    arg0->unk8 = (s32) *arg0->unk3C;
    temp_r3_132 = arg0->unk3C + 2;
    arg0->unk3C = temp_r3_132;
    arg0->unk3C = temp_r3_132;
    arg0->unkC = 1;
    temp_r3_136 = arg0->unk3C;
    if (memcmp(temp_r3_136, temp_r3_136 + 9, 9U) == 0) {
        arg0->unk8 -= 1;
        arg0->unkC = 0;
        arg0->unk3C += 9;
    }
    return 1;
}

#if 0 // DRAFT: pointer/array required
void MKModel_ExploreCalculateVertex(MeshChunkExplorer *arg0, int arg1) {
    s32 temp_r6_178;
    s32 temp_r7_228;
    s32 var_r6_170;
    void *temp_r4_167;

    temp_r4_167 = arg0->unk3C + (arg1 * 9);
    if ((u8) arg0->unk50 != 0) {
        var_r6_170 = M2C_FIELD(temp_r4_167, u16 *, 0) * 5;
    } else {
        var_r6_170 = M2C_FIELD(temp_r4_167, u16 *, 0) * 3;
    }
    temp_r6_178 = var_r6_170 * 4;
    arg0->unk58 = *(arg0->unk90 + temp_r6_178);
    arg0->unk5C = M2C_FIELD((arg0->unk90 + temp_r6_178), f32 *, 4);
    arg0->unk60 = M2C_FIELD((arg0->unk90 + temp_r6_178), f32 *, 8);
    arg0->unk68 = 0.015625f * (f32) (s8) M2C_FIELD(temp_r4_167, u8 *, 2);
    arg0->unk6C = 0.015625f * (f32) (s8) M2C_FIELD(temp_r4_167, u8 *, 3);
    arg0->unk70 = 0.015625f * (f32) (s8) M2C_FIELD(temp_r4_167, u8 *, 4);
    temp_r7_228 = M2C_FIELD(temp_r4_167, u16 *, 5) * 4;
    arg0->unk78 = 0.003921569f * (f32) ((u32) *(arg0->unk94 + temp_r7_228) >> 0x18U);
    arg0->unk7C = 0.003921569f * (f32) (u8) ((u32) *(arg0->unk94 + temp_r7_228) >> 0x10U);
    arg0->unk80 = 0.003921569f * (f32) (u8) ((u32) *(arg0->unk94 + temp_r7_228) >> 8U);
    arg0->unk84 = 0.003921569f * (f32) (u8) *(arg0->unk94 + temp_r7_228);
    arg0->unk88 = 0.00024414062f * (f32) *(arg0->unk98 + (M2C_FIELD(temp_r4_167, u16 *, 7) * 4));
    arg0->unk8C = 0.00024414062f * (f32) M2C_FIELD((arg0->unk98 + (M2C_FIELD(temp_r4_167, u16 *, 7) * 4)), u16 *, 2);
}
#endif

void MKModel_ExploreMeshChunk(MeshChunkExplorer *arg0, int arg1, int arg2, int arg3) {
    ((MeshChunkExplorer_GC *) arg0)->SetMeshChunk(arg1, arg2, arg3);
}

#if 0 // DRAFT: illegal implicit conversion from 'const MKModel *' to
void MKModel_ExploreBegin(const MKModel *arg0) {
    memset(&explorer_784, 0, 0xA0U);
    M2C_FIELD(&explorer_784, MKModel **, 0x40) = arg0;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const Matrix *' to
void MKModel_Draw(const MKModel *arg0, const unsigned short *arg1) {
    M2C_UNK *spDC;
    f64 *spD8;                                      /* compiler-managed */
    MKModel *spD4;
    s32 spD0;
    u8 spCC;
    void *spC8;
    void *spC4;
    s32 spC0;
    Matrix sp80;
    Matrix sp40;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    s32 sp14;
    s32 sp10;
    Animation *var_r26_538;
    MKAttachment *temp_r7_586;
    MKMaterial *temp_r23_588;
    MKMaterial *var_r19_790;
    Matrix *temp_r0_989;
    Matrix *temp_r3_976;
    Matrix *var_r14_519;
    Matrix *var_r22_689;
    Matrix *var_r27_526;
    Matrix *var_r30_675;
    MeshChunkGC *var_r28_832;
    ModelCloth *var_r24_581;
    s16 temp_r0_972;
    s32 temp_r0_592;
    s32 temp_r0_846;
    s32 var_r14_734;
    s32 var_r14_784;
    s32 var_r17_735;
    s32 var_r18_808;
    s32 var_r20_782;
    s32 var_r29_816;
    s32 var_r31_809;
    s32 var_r3_880;
    s32 var_r6_742;
    u16 var_r0_1037;
    u16 var_r0_760;
    u32 temp_r3_828;
    u32 temp_r4_510;
    u8 temp_r0_856;
    u8 temp_r0_949;
    u8 temp_r3_849;
    u8 var_r0_695;
    u8 var_r0_873;
    u8 var_r21_690;
    void *temp_r17_848;
    void *temp_r3_865;
    void *temp_r4_822;
    void *temp_r4_859;
    void *var_r25_556;

    temp_r4_510 = ((u8) arg0->unk4 >> 5U) & 7;
    gpMKcurrentMaterialEffectorMask = 3;
    spCC = 0;
    sp10 = M2C_FIELD(&lit_676, s32 *, 0);
    sp14 = M2C_FIELD(&lit_676, s32 *, 4);
    if (temp_r4_510 >= 1U) {
        var_r14_519 = &arg0->unk10;
    } else {
        var_r14_519 = &Matrix::identity;
    }
    var_r27_526 = var_r14_519;
    if (temp_r4_510 >= 1U) {
        spD8 = &arg0->unk50;
    } else {
        spD8 = &MKVector4::one;
    }
    if (temp_r4_510 >= 1U) {
        var_r26_538 = arg0->unk70;
    } else {
        var_r26_538 = NULL;
    }
    if (temp_r4_510 >= 2U) {
        spC8 = arg0->unk80;
    } else {
        spC8 = M2C_FIELD(M2C_FIELD(arg0->unk0, void **, 0x30), void **, 0x54);
    }
    if (temp_r4_510 >= 2U) {
        var_r25_556 = arg0->unk88;
    } else {
        var_r25_556 = NULL;
    }
    if (temp_r4_510 >= 2U) {
        spC4 = arg0->unk8C;
    } else {
        spC4 = NULL;
    }
    if (temp_r4_510 >= 2U) {
        spD4 = arg0 + 0x90;
    } else {
        spD4 = NULL;
    }
    if (temp_r4_510 >= 2U) {
        var_r24_581 = arg0->unk84;
    } else {
        var_r24_581 = NULL;
    }
    temp_r7_586 = arg0->unk8;
    temp_r23_588 = gRenderState;
    if (temp_r7_586 != NULL) {
        temp_r0_592 = ((u8) temp_r7_586->unk4 >> 4U) & 0xF;
        switch (temp_r0_592) {                      /* irregular */
        case 0:
            M2C_STRUCT_COPY((s32) &sp40.unk3C + 4, temp_r7_586->unk0 - 4 + 4, 0x40);
            /* fallthrough */
        case 1:
            M2C_STRUCT_COPY((s32) &sp40.unk3C + 4, MKModel_GetWorldMatrix((MKModel *) temp_r7_586->unk0) - 4 + 4, 0x40);
            break;
        case 2:
            MKModel_CalculateSubObjectLocalToWorldMatrix((MKModel *) temp_r7_586->unk0, (SubObjectType) 0, (s32) M2C_FIELD(temp_r7_586, u8 *, 4) & 0x0FFFFFFF, &sp80);
            break;
        case 3:
            MKModel_GetRefPointMatrix((MKModel *) temp_r7_586->unk0, (s32) M2C_FIELD(temp_r7_586, u8 *, 4) & 0x0FFFFFFF, &sp80, 1U);
            break;
        case 4:
            MKModel_CalculateNodeWorldMatrix((MKModel *) temp_r7_586->unk0, (s32) M2C_FIELD(temp_r7_586, u8 *, 4) & 0x0FFFFFFF, &sp80);
            break;
        }
        if ((var_r14_519 != NULL) && (var_r14_519 != &Matrix::identity)) {
            sp80.Multiply(var_r14_519, &sp80);
        }
        var_r27_526 = &sp80;
    }
    if (var_r26_538 != NULL) {
        var_r30_675 = var_r26_538->CalculateMatrices(NULL, -1, NULL, var_r27_526);
    } else {
        var_r30_675 = NULL;
    }
    if (var_r26_538 != NULL) {
        MKMaterial_SetAnimationMatrices(var_r30_675, var_r26_538->GetNmbrOfNodes());
    }
    var_r22_689 = (Matrix *)-1U;
    var_r21_690 = 0;
    if (var_r26_538 == NULL) {
        var_r0_695 = 0;
        if (((f32) M2C_FIELD(var_r27_526, f64 *, 0) == (f32) M2C_FIELD(&Matrix::identity, f64 *, 0)) && ((f32) M2C_FIELD(var_r27_526, f64 *, 8) == (f32) M2C_FIELD(&Matrix::identity, f64 *, 8)) && ((f32) M2C_FIELD(var_r27_526, f64 *, 0x10) == (f32) M2C_FIELD(&Matrix::identity, f64 *, 0x10)) && ((f32) M2C_FIELD(var_r27_526, f64 *, 0x18) == (f32) M2C_FIELD(&Matrix::identity, f64 *, 0x18)) && ((f32) M2C_FIELD(var_r27_526, f64 *, 0x20) == (f32) M2C_FIELD(&Matrix::identity, f64 *, 0x20)) && ((f32) M2C_FIELD(var_r27_526, f64 *, 0x28) == (f32) M2C_FIELD(&Matrix::identity, f64 *, 0x28)) && ((f32) M2C_FIELD(var_r27_526, f64 *, 0x30) == (f32) M2C_FIELD(&Matrix::identity, f64 *, 0x30)) && ((f32) M2C_FIELD(var_r27_526, f64 *, 0x38) == (f32) M2C_FIELD(&Matrix::identity, f64 *, 0x38))) {
            var_r0_695 = 1;
        }
        if (var_r0_695 != 0) {
            var_r21_690 = 1;
        }
    }
    if (var_r21_690 != 0) {
        var_r14_734 = 0;
        var_r17_735 = 0;
loop_65:
        if (arg1 != NULL) {
            var_r0_760 = *arg1;
        } else {
            var_r0_760 = (u16) M2C_FIELD(M2C_FIELD(arg0->unk0, void **, 0x30), s16 *, 4);
        }
        if (var_r14_734 < (s32) var_r0_760) {
            if (arg1 != NULL) {
                var_r6_742 = *(arg1 + (var_r17_735 + 2)) & 0x7FFF;
            } else {
                var_r6_742 = var_r14_734;
            }
            MKMaterial_SetLocalities(NULL, M2C_FIELD(M2C_FIELD(arg0->unk0, void **, 0x30), s32 *, 0x50) + (var_r6_742 << 6), 1, var_r6_742);
            var_r14_734 += 1;
            var_r17_735 += 2;
            goto loop_65;
        }
    } else {
        MKMaterial_SetLocalities(var_r27_526, M2C_FIELD(arg0->unk0, void **, 0x30) + 0x30, 1, 0);
        MKMaterial_UseLocality(0);
    }
    var_r20_782 = 0;
    var_r14_784 = 0;
    spDC = &gShockWaveData;
loop_137:
    if (var_r20_782 < (s16) M2C_FIELD(M2C_FIELD(arg0->unk0, void **, 0x30), s16 *, 6)) {
        var_r19_790 = *(spC8 + var_r14_784);
        if ((temp_r23_588 != NULL) && ((s32) var_r19_790->unk30 == (s32) temp_r23_588->unk30)) {
            var_r19_790 = temp_r23_588;
        }
        if ((s8) M2C_FIELD(var_r19_790->unk24, u8 *, 0xE1) == 0) {
            MKMaterial_SetMaterial(var_r19_790);
            MKMaterial_SetGeometryColor(*spD8);
loop_135:
            if (MKMaterial_Begin() != 0) {
                var_r18_808 = 0;
                var_r31_809 = 0;
loop_131:
                if (arg1 != NULL) {
                    var_r0_1037 = *arg1;
                } else {
                    var_r0_1037 = (u16) M2C_FIELD(M2C_FIELD(arg0->unk0, void **, 0x30), s16 *, 4);
                }
                if (var_r18_808 < (s32) var_r0_1037) {
                    if (arg1 != NULL) {
                        var_r29_816 = *(arg1 + (var_r31_809 + 2)) & 0x7FFF;
                    } else {
                        var_r29_816 = var_r18_808;
                    }
                    temp_r4_822 = M2C_FIELD(arg0->unk0, void **, 0x30);
                    temp_r3_828 = *(M2C_FIELD(temp_r4_822, s32 *, 0x68) + ((var_r29_816 + (var_r20_782 * M2C_FIELD(temp_r4_822, s16 *, 4))) * 4));
                    if (temp_r3_828 != 0U) {
                        var_r28_832 = M2C_FIELD(temp_r4_822, s32 *, 0x6C) + temp_r3_828;
                    } else {
                        var_r28_832 = NULL;
                    }
                    if ((var_r28_832 != NULL) && ((var_r25_556 == NULL) || !(*(var_r25_556 + var_r29_816) & 0x4F))) {
                        temp_r0_846 = var_r29_816 << 6;
                        spD0 = temp_r0_846;
                        temp_r17_848 = M2C_FIELD(temp_r4_822, s32 *, 0x50) + temp_r0_846;
                        temp_r3_849 = M2C_FIELD(temp_r17_848, u8 *, 0x38);
                        if ((temp_r3_849 == 5) || (temp_r3_849 == 4)) {
                            temp_r0_856 = *(spC4 + var_r29_816);
                            if (temp_r0_856 != 0xFF) {
                                temp_r4_859 = var_r26_538->unk1C;
                                if (temp_r4_859 != NULL) {
                                    spC0 = 3;
                                    temp_r3_865 = ((u8 *) temp_r4_859) + (temp_r0_856 * 0x48);
                                    MKModel_pBlendShapeWeights = ((u8 *) temp_r3_865) + 8;
                                    MKModel_BlendShapeTargets = M2C_FIELD(temp_r3_865, s32 *, 4);
                                }
                            }
                        } else {
                            var_r0_873 = 0;
                            if ((var_r26_538 != NULL) && (temp_r3_849 != 0)) {
                                var_r0_873 = 1;
                            }
                            var_r3_880 = 1;
                            if (var_r0_873 != 0) {
                                var_r3_880 = 2;
                            }
                            spC0 = var_r3_880;
                        }
                        if (spC0 != sp10) {
                            sp10 = spC0;
                            MKMaterial_SetGeometryTransformInfo((GeometryTransformationInfo *) &sp10);
                        }
                        if ((sp10 == 1) && ((u8) M2C_FIELD(temp_r17_848, u8 *, 0x38) != 0)) {
                            MKMaterialGC_bForceSkinnedVertexFormat = 1;
                        } else {
                            MKMaterialGC_bForceSkinnedVertexFormat = 0;
                        }
                        if (var_r21_690 != 0) {
                            MKMaterial_UseLocality(var_r29_816);
                            spCC = 0;
                            if (((u8) M2C_FIELD(spDC, u8 *, 0x60) != 0) && ((s32) M2C_FIELD(var_r19_790->unk24, s32 *, 0x28) == 3) && (sp10 == 1)) {
                                sp18 = (0.5f * M2C_FIELD(temp_r17_848, f32 *, 0x10)) + M2C_FIELD(temp_r17_848, f32 *, 0);
                                sp1C = (0.5f * M2C_FIELD(temp_r17_848, f32 *, 0x14)) + M2C_FIELD(temp_r17_848, f32 *, 4);
                                sp20 = (0.5f * M2C_FIELD(temp_r17_848, f32 *, 0x18)) + M2C_FIELD(temp_r17_848, f32 *, 8);
                                sp28 = (f64) sp18;
                                sp30 = (f64) sp20;
                                if (MKShockWave_IsWithin(*((MKVector3 *) &sp28), M2C_FIELD(temp_r17_848, f32 *, 0xC)) != 0) {
                                    spCC = 1;
                                }
                            }
                        }
                        temp_r0_949 = M2C_FIELD(temp_r17_848, u8 *, 0x38);
                        if ((temp_r0_949 == 5) || ((var_r26_538 != NULL) && (temp_r0_949 != 0))) {
                            if (var_r22_689 != NULL) {
                                var_r22_689 = NULL;
                                MKMaterial_SetLocalToWorld(NULL, 1.0f);
                            }
                        } else if ((var_r30_675 != NULL) && (temp_r0_972 = *(M2C_FIELD(M2C_FIELD(arg0->unk0, void **, 0x30), s32 *, 0x50) + (spD0 + 0x3A)), ((temp_r0_972 == -1) == 0))) {
                            temp_r3_976 = &var_r30_675[temp_r0_972];
                            if (temp_r3_976 != var_r22_689) {
                                var_r22_689 = temp_r3_976;
                                MKMaterial_SetLocalToWorld(temp_r3_976, 1.0f);
                            }
                        } else if ((spD4 != NULL) && (temp_r0_989 = *(spD4 + (var_r29_816 * 4)), ((temp_r0_989 == NULL) == 0))) {
                            if (temp_r0_989 != var_r22_689) {
                                sp40.SetIdentity();
                                sp40.Multiply(temp_r0_989, var_r27_526);
                                MKMaterial_SetLocalToWorld(&sp40, 1.0f);
                                var_r22_689 = temp_r0_989;
                            }
                        } else if (var_r27_526 != var_r22_689) {
                            var_r22_689 = var_r27_526;
                            MKMaterial_SetLocalToWorld(var_r27_526, 1.0f);
                        }
loop_129:
                        if (MKMaterial_BeginInternal() != 0) {
                            if (spCC != 0) {
                                Model_DrawShockwave(var_r28_832, 0xC, *((GeometryTransformationInfo *) &sp10));
                            } else {
                                MKMaterial_RenderMeshChunk((MeshChunk *) var_r28_832);
                            }
                            goto loop_129;
                        }
                    }
                    var_r18_808 += 1;
                    var_r31_809 += 2;
                    goto loop_131;
                }
                goto loop_135;
            }
        }
        var_r20_782 += 1;
        var_r14_784 += 4;
        goto loop_137;
    }
    MKMaterialGC_bForceSkinnedVertexFormat = 0;
    if (var_r24_581 != NULL) {
        var_r24_581->Draw();
    }
    MKMaterial_SetGeometryColor(MKVector4::one);
    gpMKcurrentMaterialEffectorMask = 0;
    if ((u8) M2C_FIELD(arg0->unk0, u8 *, 0x48) != 0) {
        MKGrass_QueueDraw(arg0, arg1);
    }
    if ((u32) M2C_FIELD(arg0->unk0, u32 *, 0x38) != 0U) {
        MKModel_DrawModelParticles(arg0, var_r30_675);
    }
}
#endif

void MKModel_UnpackTemplatePlatformSpecific(MKModelTemplate *arg0) {

}

void MKModel_InitModulePlatformSpecific() {

}

#if 0 // DRAFT: illegal type
void Model_DrawShockwave(MeshChunkGC *arg0, int arg1, GeometryTransformationInfo &arg2) {
    f32 temp_f28_1233;
    f32 temp_f29_1232;
    f32 temp_f29_1235;
    f32 temp_f30_1230;
    f32 temp_f31_1226;
    f32 temp_f6_1189;
    f32 temp_f6_1204;
    f32 temp_f7_1187;
    f32 temp_f8_1190;
    f32 var_f13_1193;
    f32 var_f4_1181;
    f32 var_f7_1207;
    s32 temp_r10_1158;
    s32 var_ctr_1201;
    s32 var_r3_1160;
    s32 var_r5_1170;
    s32 var_r7_1200;
    u16 temp_r0_1169;
    u16 temp_r11_1180;
    u16 temp_r6_1264;
    u8 var_r5_1135;
    void *temp_r12_1177;
    void *temp_r30_1129;
    void *temp_r30_1137;
    void *temp_r6_1184;
    void *temp_r6_1203;
    void *var_r4_1168;
    void *var_r5_1156;

    temp_r30_1129 = arg0 + (arg0->unk10 + 0x20);
    GXSetArray(GX_VA_CLR0, temp_r30_1129, 4U);
    var_r5_1135 = 0x14;
    temp_r30_1137 = ((u8 *) temp_r30_1129) + arg0->unk14;
    if ((s32) arg2.unk0 == 1) {
        var_r5_1135 = 0xC;
    }
    GXSetArray(GX_VA_POS, temp_r30_1137, var_r5_1135);
    GXSetArray(GX_VA_TEX0, ((u8 *) temp_r30_1137) + arg0->unk18, 4U);
    MK_SetVDMode((MK_VertexDescriptorMode) 7);
    GXFlush();
    var_r5_1156 = arg0 + 0x20;
    temp_r10_1158 = arg1 / 4;
    var_r3_1160 = 0;
loop_20:
    if (var_r3_1160 < (s32) arg0->unk6) {
        var_r4_1168 = ((u8 *) var_r5_1156) + 3;
        temp_r0_1169 = M2C_FIELD(var_r5_1156, u16 *, 1);
        var_r5_1170 = 0;
        *(u8 *)0xCC008000 = M2C_FIELD(var_r5_1156, u8 *, 0);
        *(u8 *)0xCC008000 = temp_r0_1169;
        temp_r12_1177 = arg0 + (arg0->unk10 + arg0->unk14 + 0x20);
loop_18:
        if (var_r5_1170 < (s32) temp_r0_1169) {
            temp_r11_1180 = M2C_FIELD(var_r4_1168, u16 *, 0);
            var_f4_1181 = 0.0f;
            temp_r6_1184 = ((u8 *) temp_r12_1177) + (temp_r11_1180 * temp_r10_1158 * 4);
            temp_f7_1187 = M2C_FIELD(temp_r6_1184, f32 *, 4) - M2C_FIELD(&gShockWaveData, f32 *, 0x54);
            temp_f6_1189 = M2C_FIELD(temp_r6_1184, f32 *, 0) - M2C_FIELD(&gShockWaveData, f32 *, 0x50);
            temp_f8_1190 = M2C_FIELD(temp_r6_1184, f32 *, 8) - M2C_FIELD(&gShockWaveData, f32 *, 0x58);
            var_f13_1193 = (temp_f8_1190 * temp_f8_1190) + ((temp_f6_1189 * temp_f6_1189) + (temp_f7_1187 * temp_f7_1187));
            if (var_f13_1193 > 0.000001f) {
                var_f13_1193 *= __frsqrte(var_f13_1193);
            }
            var_r7_1200 = 0;
            var_ctr_1201 = 4;
            do {
                temp_r6_1203 = &gShockWaveData + var_r7_1200;
                temp_f6_1204 = M2C_FIELD(temp_r6_1203, f32 *, 0x10);
                var_f7_1207 = var_f13_1193 - -((0.5f * temp_f6_1204) - M2C_FIELD(temp_r6_1203, f32 *, 0));
                if (var_f7_1207 < temp_f6_1204) {

                } else {
                    var_f7_1207 = temp_f6_1204;
                }
                if (var_f7_1207 > 0.0f) {

                } else {
                    var_f7_1207 = 0.0f;
                }
                if ((var_f7_1207 > 0.0f) && (var_f7_1207 < temp_f6_1204)) {
                    temp_f31_1226 = var_f7_1207 * M2C_FIELD(temp_r6_1203, f32 *, 0x30);
                    temp_f30_1230 = temp_f31_1226 * temp_f31_1226;
                    temp_f29_1232 = temp_f31_1226 * temp_f30_1230;
                    temp_f28_1233 = temp_f29_1232 * temp_f30_1230;
                    temp_f29_1235 = temp_f28_1233 * temp_f30_1230;
                    var_f4_1181 += ((temp_f29_1235 * temp_f30_1230 * 0.0000027557319f) + ((temp_f29_1235 * -0.0001984127f) + ((temp_f28_1233 * 0.008333334f) + ((temp_f29_1232 * -0.16666667f) + temp_f31_1226)))) * M2C_FIELD(temp_r6_1203, f32 *, 0x40);
                }
                var_r7_1200 += 4;
                var_ctr_1201 -= 1;
            } while (var_ctr_1201 != 0);
            var_r5_1170 += 1;
            *(u8 *)0xCC008000 = (f32) *(temp_r12_1177 + (temp_r11_1180 * temp_r10_1158 * 4));
            *(u8 *)0xCC008000 = (f32) (var_f4_1181 + *(temp_r12_1177 + ((M2C_FIELD(var_r4_1168, u16 *, 0) * temp_r10_1158 * 4) + 4)));
            *(u8 *)0xCC008000 = (f32) *(temp_r12_1177 + ((M2C_FIELD(var_r4_1168, u16 *, 0) * temp_r10_1158 * 4) + 8));
            *(u8 *)0xCC008000 = (u16) M2C_FIELD(var_r4_1168, u16 *, 5);
            temp_r6_1264 = M2C_FIELD(var_r4_1168, u16 *, 7);
            var_r4_1168 += 9;
            *(u8 *)0xCC008000 = temp_r6_1264;
            goto loop_18;
        }
        var_r5_1156 = var_r4_1168;
        var_r3_1160 += 1;
        goto loop_20;
    }
}
#endif

#if 0 // DRAFT: illegal type
void Model_DrawWeightedBlendShape(MeshChunkGC *arg0, float *arg1, unsigned long arg2, const Matrix *arg3, float *arg4) {
    Matrix *temp_r24_1355;
    Matrix *temp_r25_1395;
    f32 temp_f4_1389;
    f32 temp_f5_1358;
    f32 temp_f6_1339;
    f64 temp_f10_1343;
    f64 temp_f7_1429;
    f64 temp_f8_1430;
    f64 var_f10_1366;
    f64 var_f11_1370;
    f64 var_f12_1374;
    f64 var_f13_1378;
    f64 var_f29_1390;
    f64 var_f30_1386;
    f64 var_f31_1382;
    f64 var_f7_1327;
    f64 var_f8_1329;
    f64 var_f9_1362;
    s32 temp_cr0_eq_1443;
    s32 temp_cr0_eq_1447;
    s32 temp_r0_1439;
    s32 var_ctr_1335;
    s32 var_r9_1334;
    u16 temp_r0_1318;
    u16 temp_r9_1324;
    u16 var_r8_1321;
    u32 var_r5_0;
    void *temp_r25_1326;
    void *var_r28_1331;
    void *var_r3_1309;

    var_r5_0 = arg2;
    var_r3_1309 = arg0 + 0x20;
loop_8:
    temp_cr0_eq_1447 = var_r5_0 == 0;
    var_r5_0 -= 1;
    if (temp_cr0_eq_1447 == 0) {
        *(s8 *)0xCC008000 = 0x98;
        temp_r0_1318 = M2C_FIELD(var_r3_1309, u16 *, 1);
        var_r3_1309 += 3;
        *(s8 *)0xCC008000 = temp_r0_1318;
        var_r8_1321 = temp_r0_1318;
loop_7:
        temp_cr0_eq_1443 = var_r8_1321 == 0;
        var_r8_1321 -= 1;
        if (temp_cr0_eq_1443 == 0) {
            temp_r9_1324 = M2C_FIELD(var_r3_1309, u16 *, 0);
            temp_r25_1326 = arg1 + (temp_r9_1324 * 0x14);
            var_f7_1327 = M2C_FIELD(temp_r25_1326, f64 *, 0);
            var_f8_1329 = M2C_FIELD(temp_r25_1326, f64 *, 8);
            var_r28_1331 = arg4 + (temp_r9_1324 << 8);
            var_r9_1334 = 0;
            var_ctr_1335 = MKModel_BlendShapeTargets;
            if ((s32) MKModel_BlendShapeTargets > 0) {
                do {
                    temp_f6_1339 = *(MKModel_pBlendShapeWeights + var_r9_1334);
                    var_f7_1327 += M2C_FIELD(var_r28_1331, f64 *, 0) * (f64) temp_f6_1339;
                    temp_f10_1343 = M2C_FIELD(var_r28_1331, f64 *, 8);
                    var_r28_1331 += 0x10;
                    var_r9_1334 += 4;
                    var_f8_1329 += temp_f10_1343 * (f64) temp_f6_1339;
                    var_ctr_1335 -= 1;
                } while (var_ctr_1335 != 0);
            }
            temp_r24_1355 = &arg3[M2C_FIELD(temp_r25_1326, u8 *, 0xC)];
            temp_f5_1358 = (f32) M2C_FIELD(temp_r25_1326, u8 *, 0xE) * 0.003921569f;
            var_f9_1362 = M2C_FIELD(temp_r24_1355, f64 *, 0) * (f64) temp_f5_1358;
            var_f10_1366 = M2C_FIELD(temp_r24_1355, f64 *, 8) * (f64) temp_f5_1358;
            var_f11_1370 = M2C_FIELD(temp_r24_1355, f64 *, 0x10) * (f64) temp_f5_1358;
            var_f12_1374 = M2C_FIELD(temp_r24_1355, f64 *, 0x18) * (f64) temp_f5_1358;
            var_f13_1378 = M2C_FIELD(temp_r24_1355, f64 *, 0x20) * (f64) temp_f5_1358;
            var_f31_1382 = M2C_FIELD(temp_r24_1355, f64 *, 0x28) * (f64) temp_f5_1358;
            var_f30_1386 = M2C_FIELD(temp_r24_1355, f64 *, 0x30) * (f64) temp_f5_1358;
            temp_f4_1389 = 1.0f - temp_f5_1358;
            var_f29_1390 = M2C_FIELD(temp_r24_1355, f64 *, 0x38) * (f64) temp_f5_1358;
            if (temp_f4_1389 != 0.0f) {
                temp_r25_1395 = &arg3[M2C_FIELD(temp_r25_1326, u8 *, 0xD)];
                var_f9_1362 += M2C_FIELD(temp_r25_1395, f64 *, 0) * (f64) temp_f4_1389;
                var_f10_1366 += M2C_FIELD(temp_r25_1395, f64 *, 8) * (f64) temp_f4_1389;
                var_f11_1370 += M2C_FIELD(temp_r25_1395, f64 *, 0x10) * (f64) temp_f4_1389;
                var_f12_1374 += M2C_FIELD(temp_r25_1395, f64 *, 0x18) * (f64) temp_f4_1389;
                var_f13_1378 += M2C_FIELD(temp_r25_1395, f64 *, 0x20) * (f64) temp_f4_1389;
                var_f31_1382 += M2C_FIELD(temp_r25_1395, f64 *, 0x28) * (f64) temp_f4_1389;
                var_f30_1386 += M2C_FIELD(temp_r25_1395, f64 *, 0x30) * (f64) temp_f4_1389;
                var_f29_1390 += M2C_FIELD(temp_r25_1395, f64 *, 0x38) * (f64) temp_f4_1389;
            }
            *(0xCC008000 + 0) = (f64) ((var_f13_1378 * var_f8_1329) + ((var_f11_1370 * var_f7_1327) + ((var_f9_1362 * var_f7_1327) + var_f30_1386)));
            *(s8 *)0xCC008000 = (f32) ((var_f31_1382 * var_f8_1329) + ((var_f12_1374 * var_f7_1327) + ((var_f10_1366 * var_f7_1327) + var_f29_1390)));
            temp_f7_1429 = M2C_FIELD(var_r3_1309, f64 *, 2);
            temp_f8_1430 = M2C_FIELD(var_r3_1309, f64 *, 4);
            *(void *)0xCC008000 = (f64) ((var_f13_1378 * temp_f8_1430) + ((var_f11_1370 * temp_f7_1429) + (var_f9_1362 * temp_f7_1429)));
            *(void *)0xCC008000 = (f64) ((var_f31_1382 * temp_f8_1430) + ((var_f12_1374 * temp_f7_1429) + (var_f10_1366 * temp_f7_1429)));
            temp_r0_1439 = M2C_FIELD(var_r3_1309, s32 *, 5);
            var_r3_1309 += 9;
            *(s8 *)0xCC008000 = temp_r0_1439;
            goto loop_7;
        }
        goto loop_8;
    }
}
#endif
