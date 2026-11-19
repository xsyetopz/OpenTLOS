#include "common/gc/MKModel_GC.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKGrass_MP.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/gc/MKMaterial_GC.h"
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

#if 0 // DRAFT: function call 'MKMaterial_SetMaterial(long)' does not match
void MKModel_BlobBegin(const MKModel *arg0) {
    MKMaterial_SetMaterial(MKModel_GetMaterial(arg0, 0, 0U));
}
#endif

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

#if 0 // DRAFT: undefined identifier 'SetMeshChunk'
void MKModel_ExploreMeshChunk(MeshChunkExplorer *arg0, int arg1, int arg2, int arg3) {
    arg0->SetMeshChunk(arg1, arg2, arg3);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const MKModel *' to
void MKModel_ExploreBegin(const MKModel *arg0) {
    memset(&explorer_784, 0, 0xA0U);
    M2C_FIELD(&explorer_784, MKModel **, 0x40) = arg0;
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_spCC'
void MKModel_Draw(const MKModel *arg0, const unsigned short *arg1) {
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
    f32 var_r24_581;
    f32 var_r25_556;
    s16 temp_r0_972;
    s32 temp_r0_592;
    s32 temp_r0_846;
    s32 var_r14_734;
    s32 var_r14_784;
    s32 var_r17_735;
    s32 var_r18_808;
    s32 var_r20_782;
    s32 var_r26_538;
    s32 var_r29_816;
    s32 var_r31_809;
    s32 var_r3_880;
    s32 var_r6_742;
    u16 var_r0_1037;
    u16 var_r0_760;
    u32 temp_r3_828;
    u32 temp_r4_510;
    u32 temp_r4_859;
    u8 temp_r0_856;
    u8 temp_r0_949;
    u8 temp_r3_849;
    u8 var_r0_695;
    u8 var_r0_873;
    u8 var_r21_690;
    void *temp_r17_848;
    void *temp_r3_865;
    void *temp_r4_822;
    temp_r4_510 = ((u8) arg0->unk4 >> 5U) & 7;
    gpMKcurrentMaterialEffectorMask = 3;
    arg_spCC = 0U;
    arg_sp10 = M2C_FIELD(&lit_676, s32 *, 0);
    arg_sp14 = M2C_FIELD(&lit_676, s32 *, 4);
    if (temp_r4_510 >= 1U) {
        var_r14_519 = &arg0->unk10;
    } else {
        var_r14_519 = &identity;
    }
    var_r27_526 = var_r14_519;
    if (temp_r4_510 >= 1U) {
        arg_spD8 = &arg0->unk10.unk40;
    } else {
        arg_spD8 = &one.unk0;
    }
    if (temp_r4_510 >= 1U) {
        var_r26_538 = arg0->unk10.unk60;
    } else {
        var_r26_538 = 0;
    }
    if (temp_r4_510 >= 2U) {
        arg_spC8 = arg0->unk10.unk70;
    } else {
        arg_spC8 = M2C_FIELD(M2C_FIELD(arg0->unk0, void **, 0x30), f32 *, 0x54);
    }
    if (temp_r4_510 >= 2U) {
        var_r25_556 = arg0->unk10.unk78;
    } else {
        var_r25_556 = 0.0f;
    }
    if (temp_r4_510 >= 2U) {
        arg_spC4 = arg0->unk10.unk7C;
    } else {
        arg_spC4 = 0;
    }
    if (temp_r4_510 >= 2U) {
        arg_spD4 = &arg0->unk10.unk80;
    } else {
        arg_spD4 = NULL;
    }
    if (temp_r4_510 >= 2U) {
        var_r24_581 = arg0->unk10.unk74;
    } else {
        var_r24_581 = 0.0f;
    }
    temp_r7_586 = arg0->unk8;
    temp_r23_588 = gRenderState;
    if (temp_r7_586 != NULL) {
        temp_r0_592 = ((u8) temp_r7_586->unk4 >> 4U) & 0xF;
        switch (temp_r0_592) {                      /* irregular */
        case 0:
            M2C_STRUCT_COPY((s32) &arg_sp7C + 4, temp_r7_586->unk0 - 4 + 4, 0x40);
            /* fallthrough */
        case 1:
            M2C_STRUCT_COPY((s32) &arg_sp7C + 4, MKModel_GetWorldMatrix((MKModel *) temp_r7_586->unk0) - 4 + 4, 0x40);
            break;
        case 2:
            MKModel_CalculateSubObjectLocalToWorldMatrix((MKModel *) temp_r7_586->unk0, (SubObjectType) 0, (s32) M2C_FIELD(temp_r7_586, u8 *, 4) & 0x0FFFFFFF, (Matrix *) &arg_sp80);
            break;
        case 3:
            MKModel_GetRefPointMatrix((MKModel *) temp_r7_586->unk0, (s32) M2C_FIELD(temp_r7_586, u8 *, 4) & 0x0FFFFFFF, (Matrix *) &arg_sp80, 1U);
            break;
        case 4:
            MKModel_CalculateNodeWorldMatrix((MKModel *) temp_r7_586->unk0, (s32) M2C_FIELD(temp_r7_586, u8 *, 4) & 0x0FFFFFFF, (Matrix *) &arg_sp80);
            break;
        }
        if ((var_r14_519 != NULL) && (var_r14_519 != &identity)) {
            arg_sp80.Multiply(var_r14_519, (Matrix *) &arg_sp80);
        }
        var_r27_526 = (Matrix *) &arg_sp80;
    }
    if ((u32) var_r26_538 != 0U) {
        var_r30_675 = var_r26_538->CalculateMatrices(NULL, -1, NULL, var_r27_526);
    } else {
        var_r30_675 = NULL;
    }
    if ((u32) var_r26_538 != 0U) {
        MKMaterial_SetAnimationMatrices(var_r30_675, var_r26_538->GetNmbrOfNodes());
    }
    var_r22_689 = (Matrix *)-1U;
    var_r21_690 = 0;
    if ((u32) var_r26_538 == 0U) {
        var_r0_695 = 0;
        if (((f32) M2C_FIELD(var_r27_526, f64 *, 0) == (f32) M2C_FIELD(&identity, f64 *, 0)) && ((f32) M2C_FIELD(var_r27_526, f64 *, 8) == (f32) M2C_FIELD(&identity, f64 *, 8)) && ((f32) M2C_FIELD(var_r27_526, f64 *, 0x10) == (f32) M2C_FIELD(&identity, f64 *, 0x10)) && ((f32) M2C_FIELD(var_r27_526, f64 *, 0x18) == (f32) M2C_FIELD(&identity, f64 *, 0x18)) && ((f32) M2C_FIELD(var_r27_526, f64 *, 0x20) == (f32) M2C_FIELD(&identity, f64 *, 0x20)) && ((f32) M2C_FIELD(var_r27_526, f64 *, 0x28) == (f32) M2C_FIELD(&identity, f64 *, 0x28)) && ((f32) M2C_FIELD(var_r27_526, f64 *, 0x30) == (f32) M2C_FIELD(&identity, f64 *, 0x30)) && ((f32) M2C_FIELD(var_r27_526, f64 *, 0x38) == (f32) M2C_FIELD(&identity, f64 *, 0x38))) {
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
    arg_spDC = &gShockWaveData;
loop_137:
    if (var_r20_782 < (s16) M2C_FIELD(M2C_FIELD(arg0->unk0, void **, 0x30), s16 *, 6)) {
        var_r19_790 = *(M2C_BITWISE(s32, arg_spC8) + var_r14_784);
        if ((temp_r23_588 != NULL) && ((s32) var_r19_790->unk30 == (s32) temp_r23_588->unk30)) {
            var_r19_790 = temp_r23_588;
        }
        if ((s8) M2C_FIELD(var_r19_790->unk24, u8 *, 0xE1) == 0) {
            MKMaterial_SetMaterial(var_r19_790);
            MKMaterial_SetGeometryColor(*((MKVector4 *) arg_spD8));
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
                    if ((var_r28_832 != NULL) && ((M2C_BITWISE(u32, var_r25_556) == 0U) || !(*(M2C_BITWISE(s32, var_r25_556) + var_r29_816) & 0x4F))) {
                        temp_r0_846 = var_r29_816 << 6;
                        arg_spD0 = temp_r0_846;
                        temp_r17_848 = M2C_FIELD(temp_r4_822, s32 *, 0x50) + temp_r0_846;
                        temp_r3_849 = M2C_FIELD(temp_r17_848, u8 *, 0x38);
                        if ((temp_r3_849 == 5) || (temp_r3_849 == 4)) {
                            temp_r0_856 = *(arg_spC4 + var_r29_816);
                            if (temp_r0_856 != 0xFF) {
                                temp_r4_859 = M2C_FIELD(var_r26_538, u32 *, 0x1C);
                                if (temp_r4_859 != 0U) {
                                    arg_spC0 = 3;
                                    temp_r3_865 = temp_r4_859 + (temp_r0_856 * 0x48);
                                    MKModel_pBlendShapeWeights = temp_r3_865 + 8;
                                    MKModel_BlendShapeTargets = M2C_FIELD(temp_r3_865, s32 *, 4);
                                }
                            }
                        } else {
                            var_r0_873 = 0;
                            if (((u32) var_r26_538 != 0U) && (temp_r3_849 != 0)) {
                                var_r0_873 = 1;
                            }
                            var_r3_880 = 1;
                            if (var_r0_873 != 0) {
                                var_r3_880 = 2;
                            }
                            arg_spC0 = var_r3_880;
                        }
                        if (arg_spC0 != arg_sp10) {
                            arg_sp10 = arg_spC0;
                            MKMaterial_SetGeometryTransformInfo((GeometryTransformationInfo *) &arg_sp10);
                        }
                        if ((arg_sp10 == 1) && ((u8) M2C_FIELD(temp_r17_848, u8 *, 0x38) != 0)) {
                            MKMaterialGC_bForceSkinnedVertexFormat = 1;
                        } else {
                            MKMaterialGC_bForceSkinnedVertexFormat = 0;
                        }
                        if (var_r21_690 != 0) {
                            MKMaterial_UseLocality(var_r29_816);
                            arg_spCC = 0U;
                            if (((u8) M2C_FIELD(arg_spDC, u8 *, 0x60) != 0) && ((s32) M2C_FIELD(var_r19_790->unk24, s32 *, 0x28) == 3) && (arg_sp10 == 1)) {
                                arg_sp18 = (0.5f * M2C_FIELD(temp_r17_848, f32 *, 0x10)) + M2C_FIELD(temp_r17_848, f32 *, 0);
                                arg_sp1C = (0.5f * M2C_FIELD(temp_r17_848, f32 *, 0x14)) + M2C_FIELD(temp_r17_848, f32 *, 4);
                                arg_sp20 = (0.5f * M2C_FIELD(temp_r17_848, f32 *, 0x18)) + M2C_FIELD(temp_r17_848, f32 *, 8);
                                arg_sp28 = (f64) arg_sp18;
                                arg_sp30 = (f64) arg_sp20;
                                if (MKShockWave_IsWithin(*((MKVector3 *) &arg_sp28), M2C_FIELD(temp_r17_848, f32 *, 0xC)) != 0) {
                                    arg_spCC = 1U;
                                }
                            }
                        }
                        temp_r0_949 = M2C_FIELD(temp_r17_848, u8 *, 0x38);
                        if ((temp_r0_949 == 5) || (((u32) var_r26_538 != 0U) && (temp_r0_949 != 0))) {
                            if (var_r22_689 != NULL) {
                                var_r22_689 = NULL;
                                MKMaterial_SetLocalToWorld(NULL, 1.0f);
                            }
                        } else if ((var_r30_675 != NULL) && (temp_r0_972 = *(M2C_FIELD(M2C_FIELD(arg0->unk0, void **, 0x30), s32 *, 0x50) + (arg_spD0 + 0x3A)), ((temp_r0_972 == -1) == 0))) {
                            temp_r3_976 = var_r30_675 + (temp_r0_972 << 6);
                            if (temp_r3_976 != var_r22_689) {
                                var_r22_689 = temp_r3_976;
                                MKMaterial_SetLocalToWorld(temp_r3_976, 1.0f);
                            }
                        } else if ((arg_spD4 != NULL) && (temp_r0_989 = *(arg_spD4 + (var_r29_816 * 4)), ((temp_r0_989 == NULL) == 0))) {
                            if (temp_r0_989 != var_r22_689) {
                                arg_sp40.SetIdentity();
                                arg_sp40.Multiply(temp_r0_989, var_r27_526);
                                MKMaterial_SetLocalToWorld((Matrix *) &arg_sp40, 1.0f);
                                var_r22_689 = temp_r0_989;
                            }
                        } else if (var_r27_526 != var_r22_689) {
                            var_r22_689 = var_r27_526;
                            MKMaterial_SetLocalToWorld(var_r27_526, 1.0f);
                        }
loop_129:
                        if (MKMaterial_BeginInternal() != 0) {
                            if (arg_spCC != 0) {
                                Model_DrawShockwave(var_r28_832, 0xC, *((GeometryTransformationInfo *) &arg_sp10));
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
    if (M2C_BITWISE(u32, var_r24_581) != 0U) {
        ((ModelCloth *) (M2C_BITWISE(ModelCloth *, var_r24_581)))->Draw();
    }
    MKMaterial_SetGeometryColor(one);
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
    temp_r30_1137 = temp_r30_1129 + arg0->unk14;
    if ((s32) arg2.unk0 == 1) {
        var_r5_1135 = 0xC;
    }
    GXSetArray(GX_VA_POS, temp_r30_1137, var_r5_1135);
    GXSetArray(GX_VA_TEX0, temp_r30_1137 + arg0->unk18, 4U);
    MK_SetVDMode((MK_VertexDescriptorMode) 7);
    GXFlush();
    var_r5_1156 = arg0 + 0x20;
    temp_r10_1158 = arg1 / 4;
    var_r3_1160 = 0;
loop_20:
    if (var_r3_1160 < (s32) arg0->unk6) {
        var_r4_1168 = var_r5_1156 + 3;
        temp_r0_1169 = M2C_FIELD(var_r5_1156, u16 *, 1);
        var_r5_1170 = 0;
        *(u8 *)0xCC008000 = M2C_FIELD(var_r5_1156, u8 *, 0);
        *(u8 *)0xCC008000 = temp_r0_1169;
        temp_r12_1177 = arg0 + (arg0->unk10 + arg0->unk14 + 0x20);
loop_18:
        if (var_r5_1170 < (s32) temp_r0_1169) {
            temp_r11_1180 = M2C_FIELD(var_r4_1168, u16 *, 0);
            var_f4_1181 = 0.0f;
            temp_r6_1184 = temp_r12_1177 + (temp_r11_1180 * temp_r10_1158 * 4);
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
    s32 temp_cr0_eq_1443;
    s32 temp_cr0_eq_1447;
    s32 temp_r0_1439;
    s32 var_ctr_1335;
    u16 temp_r0_1318;
    u16 var_r8_1321;
    u32 var_r5_0;
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
            M2C_ERROR(/* unknown instruction: psq_lx $f7, $zero, $r25, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f8, $r25, $r12, 0x0, qr0 */);
            var_ctr_1335 = MKModel_BlendShapeTargets;
            if ((s32) MKModel_BlendShapeTargets > 0) {
                do {
                    M2C_ERROR(/* unknown instruction: psq_lx $f10, $zero, $r28, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_merge00 $f9, $f6, $f6 */);
                    M2C_ERROR(/* unknown instruction: ps_madd $f7, $f10, $f9, $f7 */);
                    M2C_ERROR(/* unknown instruction: psq_lx $f10, $r28, $r12, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_merge00 $f9, $f6, $f6 */);
                    M2C_ERROR(/* unknown instruction: ps_madd $f8, $f10, $f9, $f8 */);
                    var_ctr_1335 -= 1;
                } while (var_ctr_1335 != 0);
            }
            M2C_ERROR(/* unknown instruction: psq_lx $f10, $zero, $r24, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_merge00 $f9, $f5, $f5 */);
            M2C_ERROR(/* unknown instruction: ps_mul $f9, $f10, $f9 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f11, $r24, $r27, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_merge00 $f10, $f5, $f5 */);
            M2C_ERROR(/* unknown instruction: ps_mul $f10, $f11, $f10 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f12, $r24, $r28, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_merge00 $f11, $f5, $f5 */);
            M2C_ERROR(/* unknown instruction: ps_mul $f11, $f12, $f11 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f13, $r24, $r29, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_merge00 $f12, $f5, $f5 */);
            M2C_ERROR(/* unknown instruction: ps_mul $f12, $f13, $f12 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f27, $r24, $r30, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_merge00 $f13, $f5, $f5 */);
            M2C_ERROR(/* unknown instruction: ps_mul $f13, $f27, $f13 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f28, $r24, $r31, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_merge00 $f27, $f5, $f5 */);
            M2C_ERROR(/* unknown instruction: ps_mul $f31, $f28, $f27 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f28, $r24, $r12, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_merge00 $f27, $f5, $f5 */);
            M2C_ERROR(/* unknown instruction: ps_mul $f30, $f28, $f27 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f28, $r24, $r9, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_merge00 $f27, $f5, $f5 */);
            M2C_ERROR(/* unknown instruction: ps_mul $f29, $f28, $f27 */);
            if ((1.0f - ((f32) M2C_FIELD((arg1 + (M2C_FIELD(var_r3_1309, u16 *, 0) * 0x14)), u8 *, 0xE) * 0.003921569f)) != 0.0f) {
                M2C_ERROR(/* unknown instruction: psq_lx $f28, $zero, $r25, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_merge00 $f27, $f4, $f4 */);
                M2C_ERROR(/* unknown instruction: ps_madd $f9, $f28, $f27, $f9 */);
                M2C_ERROR(/* unknown instruction: psq_lx $f28, $r25, $r27, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_merge00 $f27, $f4, $f4 */);
                M2C_ERROR(/* unknown instruction: ps_madd $f10, $f28, $f27, $f10 */);
                M2C_ERROR(/* unknown instruction: psq_lx $f28, $r25, $r28, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_merge00 $f27, $f4, $f4 */);
                M2C_ERROR(/* unknown instruction: ps_madd $f11, $f28, $f27, $f11 */);
                M2C_ERROR(/* unknown instruction: psq_lx $f28, $r25, $r29, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_merge00 $f27, $f4, $f4 */);
                M2C_ERROR(/* unknown instruction: ps_madd $f12, $f28, $f27, $f12 */);
                M2C_ERROR(/* unknown instruction: psq_lx $f28, $r25, $r30, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_merge00 $f27, $f4, $f4 */);
                M2C_ERROR(/* unknown instruction: ps_madd $f13, $f28, $f27, $f13 */);
                M2C_ERROR(/* unknown instruction: psq_lx $f28, $r25, $r31, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_merge00 $f27, $f4, $f4 */);
                M2C_ERROR(/* unknown instruction: ps_madd $f31, $f28, $f27, $f31 */);
                M2C_ERROR(/* unknown instruction: psq_lx $f28, $r25, $r12, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_merge00 $f27, $f4, $f4 */);
                M2C_ERROR(/* unknown instruction: ps_madd $f30, $f28, $f27, $f30 */);
                M2C_ERROR(/* unknown instruction: psq_lx $f27, $r25, $r9, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_merge00 $f28, $f4, $f4 */);
                M2C_ERROR(/* unknown instruction: ps_madd $f29, $f27, $f28, $f29 */);
            }
            M2C_ERROR(/* unknown instruction: ps_madds0 $f27, $f9, $f7, $f30 */);
            M2C_ERROR(/* unknown instruction: ps_madds0 $f28, $f10, $f7, $f29 */);
            M2C_ERROR(/* unknown instruction: ps_madds1 $f27, $f11, $f7, $f27 */);
            M2C_ERROR(/* unknown instruction: ps_madds1 $f7, $f12, $f7, $f28 */);
            M2C_ERROR(/* unknown instruction: ps_madds0 $f27, $f13, $f8, $f27 */);
            M2C_ERROR(/* unknown instruction: psq_stx $f27, $zero, $r10, 0x0, qr0 */);
            *(s8 *)0xCC008000 = (f32) M2C_ERROR(/* unknown instruction: ps_madds0 $f7, $f31, $f8, $f7 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f9, $f9, $f7 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f10, $f10, $f7 */);
            M2C_ERROR(/* unknown instruction: ps_madds1 $f9, $f11, $f7, $f9 */);
            M2C_ERROR(/* unknown instruction: ps_madds1 $f7, $f12, $f7, $f10 */);
            M2C_ERROR(/* unknown instruction: ps_madds0 $f9, $f13, $f8, $f9 */);
            M2C_ERROR(/* unknown instruction: ps_madds0 $f7, $f31, $f8, $f7 */);
            temp_r0_1439 = M2C_FIELD(var_r3_1309, s32 *, 5);
            var_r3_1309 += 9;
            *(s8 *)0xCC008000 = temp_r0_1439;
            goto loop_7;
        }
        goto loop_8;
    }
}
#endif
