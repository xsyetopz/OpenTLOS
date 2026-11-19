#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKChunkSceneManager.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKLevelChunk.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "dolphin/os.h"
#include "common/Source/Utils.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
s8 *malloc(M2C_UNK);                                /* extern */
MKHeap *qsort(M2C_UNK, void (*)(void *, void *));   /* extern */
s32 stricmp(s8 *, M2C_UNK *);                       /* extern */
extern void **gMK;
static s32 key_366;

#if 0 // DRAFT: function call 'stricmp(signed char *, const char[7])' does not match
s32 MKSceneManager::LoadChunk() {
    MKIniLine *temp_r3_220;
    MKIniLine *temp_r3_257;
    MKIniLine *temp_r3_57;
    MKIniLine *temp_r4_208;
    MKIniLine *temp_r4_215;
    MKIniLine *temp_r4_252;
    MKIniLine *temp_r4_350;
    MKIniLine *var_r3_354;
    MKPropCreationTable *temp_r4_176;
    MKPropCreationTable *temp_r4_230;
    s32 temp_r0_36;
    s32 temp_r3_171;
    s8 *temp_r4_114;
    s8 *temp_r4_300;
    s8 *var_r28_49;
    u32 temp_r0_138;
    u32 temp_r0_324;
    u32 temp_r30_30;
    u32 temp_r31_34;
    u32 temp_r3_135;
    u32 temp_r3_137;
    u32 temp_r3_321;
    u32 temp_r3_323;
    void *temp_r3_185;
    void *temp_r3_190;
    void *temp_r3_201;
    void *temp_r3_239;
    void *temp_r3_246;
    void *temp_r3_264;

    temp_r30_30 = OSGetTick();
    temp_r31_34 = (u32) (675000.0f * this->unkB0);
loop_1:
    temp_r0_36 = this->unkB4;
    switch (temp_r0_36) {                           /* irregular */
    case 0:
        var_r28_49 = NULL;
        this->unkCC = NULL;
        this->unkC4 = this->unkC0;
        this->unkB4 = 1;
        this->unkBC = 0;
        this->unkB8 = 0;
        temp_r3_57 = this->unkC0;
        if (temp_r3_57 != NULL) {
            var_r28_49 = temp_r3_57->GetSectionName();
        }
        if ((var_r28_49 != NULL) && (stricmp(var_r28_49, "HEADER") != 0) && (stricmp(var_r28_49, "BOUNDING_REGION") != 0) && (stricmp(var_r28_49, "SWAP_GROUP_INFO") != 0)) {
            this->unkC0->LoadInt("pool", &this->unkBC, 0);
            this->unkCC = CreateDescriptor(var_r28_49, &this->unkC8);
        }
        if (((u32) (OSGetTick() - temp_r30_30) <= temp_r31_34) || ((u8) MKChunkSceneManager::bChunksUseHeaps == 0)) {
        case 1:
            if ((MKPropCreationTable *) this->unkCC != NULL) {
loop_18:
                temp_r4_114 = *(this->unkC + ((this->unk14 * 8) + 4));
                if (temp_r4_114 != NULL) {
                    **(this->unkC + (this->unk14 * 8)) = CreateProp(temp_r4_114);
                    *(this->unkC + (this->unk14 * 8)) = 0;
                    *(this->unkC + ((this->unk14 * 8) + 4)) = 0;
                    temp_r3_135 = this->unk14 + 1;
                    temp_r3_137 = temp_r3_135 >> 0x1FU;
                    temp_r0_138 = (temp_r3_135 << 0x19) - temp_r3_137;
                    this->unk14 = ((temp_r0_138 << 7) | (temp_r0_138 >> 0x19U)) + temp_r3_137;
                    if (((u32) (OSGetTick() - temp_r30_30) < temp_r31_34) || ((u8) MKChunkSceneManager::bChunksUseHeaps == 0)) {
                        goto loop_18;
                    }
                }
            }
            if ((s32) this->unk10 == (s32) this->unk14) {
                this->unkB4 = 2;
            }
            if (((s32) this->unkB4 == 2) && (((u32) (OSGetTick() - temp_r30_30) <= temp_r31_34) || ((u8) MKChunkSceneManager::bChunksUseHeaps == 0))) {
            case 2:
                if ((MKPropCreationTable *) this->unkCC != NULL) {
                    temp_r3_171 = this->unkBC;
                    if (temp_r3_171 != 0) {
                        this->unkBC = temp_r3_171 - 1;
                        temp_r4_176 = this->unkC8;
                        this->unkD0 = M2C_FIELD(temp_r4_176, void *(**)(MKPropCreationTable *, MKPropCreationTable *), 8)(this->unkCC, temp_r4_176);
                        M2C_FIELD(this->unkD0, MKPropCreationTable **, 0) = (MKPropCreationTable *) this->unkCC;
                        temp_r3_185 = this->unkD0;
                        M2C_FIELD(M2C_FIELD(temp_r3_185, void **, 0x44), M2C_UNK (**)(void *), 0xC)(temp_r3_185);
                        temp_r3_190 = this->unkD0;
                        M2C_FIELD(M2C_FIELD(temp_r3_190, void **, 0x44), M2C_UNK (**)(void *), 0x14)(temp_r3_190);
                        AddProp(this->unkD0);
                        temp_r3_201 = this->unkD0;
                        M2C_FIELD(M2C_FIELD(temp_r3_201, void **, 0x44), M2C_UNK (**)(void *), 0x34)(temp_r3_201);
                    } else {
                        temp_r4_208 = this->unkC0;
                        this->unkC0 = temp_r4_208->unkC->GetSubLine(temp_r4_208);
loop_40:
                        if ((MKIniLine *) this->unkC0 != NULL) {
loop_32:
                            temp_r3_220 = this->unkC0;
                            if ((temp_r3_220 != NULL) && (temp_r3_220->GetFieldName() == NULL)) {
                                temp_r4_215 = this->unkC0;
                                this->unkC0 = temp_r4_215->unkC->GetNextLine(temp_r4_215);
                                goto loop_32;
                            }
                            if ((MKIniLine *) this->unkC0 != NULL) {
                                temp_r4_230 = this->unkC8;
                                this->unkD0 = M2C_FIELD(temp_r4_230, void *(**)(MKPropCreationTable *, MKPropCreationTable *), 8)(this->unkCC, temp_r4_230);
                                M2C_FIELD(this->unkD0, MKPropCreationTable **, 0) = (MKPropCreationTable *) this->unkCC;
                                temp_r3_239 = this->unkD0;
                                M2C_FIELD(M2C_FIELD(temp_r3_239, void **, 0x44), M2C_UNK (**)(void *), 0xC)(temp_r3_239);
loop_37:
                                temp_r3_257 = this->unkC0;
                                if ((temp_r3_257 != NULL) && (temp_r3_257->GetFieldName() != NULL)) {
                                    temp_r3_246 = this->unkD0;
                                    M2C_FIELD(M2C_FIELD(temp_r3_246, void **, 0x44), M2C_UNK (**)(void *, MKIniLine *), 0x10)(temp_r3_246, this->unkC0);
                                    temp_r4_252 = this->unkC0;
                                    this->unkC0 = temp_r4_252->unkC->GetNextLine(temp_r4_252);
                                    goto loop_37;
                                }
                                temp_r3_264 = this->unkD0;
                                M2C_FIELD(M2C_FIELD(temp_r3_264, void **, 0x44), M2C_UNK (**)(void *), 0x14)(temp_r3_264);
                                AddProp(this->unkD0);
                                goto loop_40;
                            }
                        }
                    }
                }
                this->unkB4 = 3;
                this->unkB8 = 0;
                if (((u32) (OSGetTick() - temp_r30_30) <= temp_r31_34) || ((u8) MKChunkSceneManager::bChunksUseHeaps == 0)) {
                case 3:
                    if ((MKPropCreationTable *) this->unkCC != NULL) {
loop_44:
                        temp_r4_300 = *(this->unkC + ((this->unk14 * 8) + 4));
                        if (temp_r4_300 != NULL) {
                            **(this->unkC + (this->unk14 * 8)) = CreateProp(temp_r4_300);
                            *(this->unkC + (this->unk14 * 8)) = 0;
                            *(this->unkC + ((this->unk14 * 8) + 4)) = 0;
                            temp_r3_321 = this->unk14 + 1;
                            temp_r3_323 = temp_r3_321 >> 0x1FU;
                            temp_r0_324 = (temp_r3_321 << 0x19) - temp_r3_323;
                            this->unk14 = ((temp_r0_324 << 7) | (temp_r0_324 >> 0x19U)) + temp_r3_323;
                            if (((u32) (OSGetTick() - temp_r30_30) < temp_r31_34) || ((u8) MKChunkSceneManager::bChunksUseHeaps == 0)) {
                                goto loop_44;
                            }
                        }
                    }
                    if ((s32) this->unk10 == (s32) this->unk14) {
                        if (((s32) this->unkBC != 0) && ((MKPropCreationTable *) this->unkCC != NULL)) {
                            this->unkB4 = 2;
                        } else {
                            temp_r4_350 = this->unkC4;
                            if (temp_r4_350 != NULL) {
                                var_r3_354 = temp_r4_350->unkC->GetNextLine(temp_r4_350);
                            } else {
                                var_r3_354 = NULL;
                            }
                            this->unkC0 = var_r3_354;
                            this->unkB4 = 0;
                        }
                    }
                }
            }
        }
        break;
    }
    if ((((u32) (OSGetTick() - temp_r30_30) < temp_r31_34) || ((u8) MKChunkSceneManager::bChunksUseHeaps == 0)) && ((MKIniLine *) this->unkC4 != NULL)) {
        goto loop_1;
    }
    return this->unkC4 == NULL;
}
#endif

void MKSceneManager::BeginChunkLoad(MKIni *arg0) {
    this->unkB4 = 0;
    this->unkB8 = 0;
    this->unkBC = 0;
    this->unkC0 = arg0->GetFirstLine();
    this->unkC4 = NULL;
    this->unkC8 = NULL;
    this->unkCC = NULL;
    this->unkD0 = NULL;
}

#if 0 // DRAFT: illegal implicit conversion from 'const char *' to
void MKSceneManager::CreatePropDeferred(const char *arg0, MKProp **arg1) {
    u32 temp_r0_430;
    u32 temp_r4_427;
    u32 temp_r4_429;

    *arg1 = NULL;
    M2C_FIELD((this->unkC + (this->unk10 * 8)), s8 **, 4) = arg0;
    *(this->unkC + (this->unk10 * 8)) = arg1;
    temp_r4_427 = this->unk10 + 1;
    temp_r4_429 = temp_r4_427 >> 0x1FU;
    temp_r0_430 = (temp_r4_427 << 0x19) - temp_r4_429;
    this->unk10 = ((temp_r0_430 << 7) | (temp_r0_430 >> 0x19U)) + temp_r4_429;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void *MKSceneManager::CreateProp(const char *arg0) {
    MKPropCreationTable *sp8;
    MKPropCreationTable *temp_r31_450;
    void *temp_r3_453;

    sp8 = NULL;
    temp_r31_450 = CreateDescriptor(arg0, &sp8);
    temp_r3_453 = M2C_FIELD(sp8, void *(**)(MKPropCreationTable *), 8)(sp8);
    M2C_FIELD(temp_r3_453, MKPropCreationTable **, 0) = temp_r31_450;
    M2C_FIELD(M2C_FIELD(temp_r3_453, void **, 0x44), M2C_UNK (**)(), 0xC)();
    M2C_FIELD(M2C_FIELD(temp_r3_453, void **, 0x44), M2C_UNK (**)(void *), 0x14)(temp_r3_453);
    AddProp(temp_r3_453);
    return temp_r3_453;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const char *' to
MKPropCreationTable *MKSceneManager::CreateDescriptor(const char *arg0, MKPropCreationTable **arg1) {
    MKIniLine *sp4C;
    s8 *spC;
    s8 *sp8;
    MKHeap *temp_r3_613;
    MKHeap *temp_r3_619;
    MKIni *temp_r30_491;
    MKIniLine *temp_r21_496;
    MKIniLine *temp_r3_541;
    MKIniLine *var_r22_494;
    MKPropCreationTable *var_r29_489;
    MKPropDescriptor *(*temp_r12_588)();
    MKPropDescriptor *var_r21_586;
    s32 var_r20_549;
    s32 var_r20_650;
    s32 var_r24_515;
    s32 var_r24_550;
    s32 var_r25_652;
    s32 var_r26_514;
    s8 *var_r24_627;
    s8 *var_r28_495;

    var_r29_489 = NULL;
    temp_r30_491 = this->unk24;
    var_r22_494 = temp_r30_491->GotoLine(arg0, NULL);
    var_r28_495 = NULL;
    temp_r21_496 = var_r22_494;
    if (temp_r21_496 == NULL) {
        var_r22_494 = temp_r30_491->GotoLine("*", NULL);
    }
    if (temp_r21_496 != NULL) {
        var_r28_495 = var_r22_494->GetSectionName();
    }
    sp4C = var_r22_494;
    var_r26_514 = 1;
    var_r24_515 = 4;
    spC = arg0;
    sp8 = var_r22_494->GetSectionName();
loop_6:
    temp_r3_541 = temp_r30_491->GotoLine(sp8, "alias");
    if (temp_r3_541 != NULL) {
        temp_r3_541->AsString(0, &sp8);
        var_r26_514 += 1;
        *(&sp4C + var_r24_515) = temp_r30_491->GotoLine(sp8, NULL);
        *(&spC + var_r24_515) = sp8;
        var_r24_515 += 4;
        goto loop_6;
    }
    var_r20_549 = 0;
    var_r24_550 = 0;
loop_9:
    if ((var_r20_549 < var_r26_514) && (var_r29_489 == NULL)) {
        key_366 = *(&spC + var_r24_550);
        var_r29_489 = Util_BinarySearch(&key_366, this->unk1C, this->unk20, 0xC, (s32 (*)(void *, void *)) ComparePropCreatorFunc);
        var_r24_550 += 4;
        var_r20_549 += 1;
        goto loop_9;
    }
    if (var_r29_489 == NULL) {
        if (arg1 != NULL) {
            *arg1 = NULL;
        }
        return NULL;
    }
    var_r21_586 = FindDescriptorInLocalChunk(arg0);
    if (var_r21_586 == NULL) {
        temp_r12_588 = M2C_FIELD(var_r29_489, MKPropDescriptor *(**)(), 4);
        if (temp_r12_588 != NULL) {
            var_r21_586 = temp_r12_588();
        } else {
            operator new(0x60U, NULL, 0);
            if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), M2C_UNK **, 0x40) = &__vt;
            }
            var_r21_586 = M2C_ERROR(/* Read from unset register $r3 */);
        }
        temp_r3_613 = AddPropDescriptor(var_r21_586);
        if (var_r28_495 != NULL) {
            var_r21_586->unk0 = var_r28_495;
        } else {
            temp_r3_619 = temp_r3_613->Current();
            if (temp_r3_619 != NULL) {
                var_r24_627 = ((MKHeap *) (temp_r3_619->Current()))->Alloc(0x20, NULL, 0);
            } else {
                var_r24_627 = malloc(0x20);
            }
            strcpy(var_r24_627, arg0);
            var_r21_586->unk0 = var_r24_627;
        }
        var_r21_586->Init();
        if (var_r28_495 == NULL) {
            var_r21_586->unk14 |= 0x10000;
        }
        var_r20_650 = var_r26_514 - 1;
        var_r25_652 = var_r20_650 * 4;
loop_31:
        if (var_r20_650 >= 0) {
            var_r21_586->ParseGMSection(temp_r30_491, *(&sp4C + var_r25_652));
            var_r20_650 -= 1;
            var_r25_652 -= 4;
            goto loop_31;
        }
        var_r21_586->LoadDone();
    }
    if (arg1 != NULL) {
        *arg1 = var_r29_489;
    }
    return (MKPropCreationTable *) var_r21_586;
}
#endif

#if 0 // DRAFT: expression syntax error
void MKSceneManager::PropResolver_Deinit() {
    MKHeap *temp_r3_691;
    void *temp_r31_690;

    temp_r31_690 = MKSceneManager::pPropMapping.__vptr;
    temp_r3_691 = MKHeap::Current();
    if (temp_r3_691 != NULL) {
        ((MKHeap *) (temp_r3_691->Current()))->Free(temp_r31_690, NULL, 0);
    } else {
        free(temp_r31_690);
    }
    MKSceneManager::pPropMapping.__vptr = NULL;
    MKSceneManager::nmbrOfMappings.__vptr = NULL;
}
#endif

#if 0 // DRAFT: type mismatch
void *MKSceneManager::PropResolver_Resolve(int arg0) {
    s32 temp_cr0_gt_736;
    s32 temp_r0_765;
    s32 temp_r31_747;
    s32 temp_r3_755;
    s32 temp_r5_760;
    s32 var_r4_732;
    s32 var_r6_731;
    u32 temp_r0_728;
    u32 temp_r0_740;
    u32 temp_r4_727;
    u32 temp_r4_735;
    u32 temp_r4_739;
    void *temp_r4_759;

    if (this <= 0) {
        return NULL;
    }
    temp_r4_727 = (u32) this >> 0x1FU;
    temp_r0_728 = ((s32) this << 0x16) - temp_r4_727;
    var_r6_731 = 0;
    var_r4_732 = ((temp_r0_728 << 0xA) | (temp_r0_728 >> 0x16U)) + temp_r4_727;
loop_5:
    temp_r31_747 = var_r4_732 * 0x28;
    if (this == (s32) *(MKSceneManager::pPropMapping.__vptr + temp_r31_747)) {
        temp_r3_755 = M2C_FIELD(*gMK, s32 (**)(void **), 0x2C)(gMK);
        temp_r4_759 = M2C_FIELD((MKSceneManager::pPropMapping.__vptr + temp_r31_747), void **, 4);
        temp_r5_760 = M2C_FIELD(temp_r4_759, s32 *, 0x48);
        if (temp_r5_760 != (s32) MKResource::sWorkingChunkIndex.unk0) {
            temp_r0_765 = M2C_FIELD(*(temp_r3_755 + (temp_r5_760 * 4)), s32 *, 0x90);
            if ((temp_r0_765 != 0xC) && (temp_r0_765 != 9)) {
                return NULL;
            }
        }
        return temp_r4_759;
    }
    temp_r4_735 = var_r4_732 + 1;
    temp_cr0_gt_736 = var_r6_731 > 0x400;
    var_r6_731 += 1;
    temp_r4_739 = temp_r4_735 >> 0x1FU;
    temp_r0_740 = (temp_r4_735 << 0x16) - temp_r4_739;
    var_r4_732 = ((temp_r0_740 << 0xA) | (temp_r0_740 >> 0x16U)) + temp_r4_739;
    if (temp_cr0_gt_736 != 0) {
        return NULL;
    }
    goto loop_5;
}
#endif

#if 0 // DRAFT: expression syntax error
void MKSceneManager::PropResolver_Remove(MKProp *arg0) {
    s32 temp_cr0_gt_798;
    s32 temp_r4_785;
    s32 temp_r5_807;
    s32 var_r3_794;
    s32 var_r7_793;
    u32 temp_r0_790;
    u32 temp_r0_802;
    u32 temp_r3_789;
    u32 temp_r3_797;
    u32 temp_r3_801;

    temp_r4_785 = this->unk14;
    if (temp_r4_785 >= 1) {
        temp_r3_789 = (u32) temp_r4_785 >> 0x1FU;
        temp_r0_790 = (temp_r4_785 << 0x16) - temp_r3_789;
        var_r7_793 = 0;
        var_r3_794 = ((temp_r0_790 << 0xA) | (temp_r0_790 >> 0x16U)) + temp_r3_789;
loop_3:
        temp_r5_807 = var_r3_794 * 0x28;
        if (temp_r4_785 == (s32) *(MKSceneManager::pPropMapping.__vptr + temp_r5_807)) {
            M2C_FIELD((MKSceneManager::pPropMapping.__vptr + temp_r5_807), s32 *, 4) = 0;
            *(MKSceneManager::pPropMapping.__vptr + temp_r5_807) = -1;
            MKSceneManager::nmbrOfMappings.__vptr -= 1;
            return;
        }
        temp_r3_797 = var_r3_794 + 1;
        temp_cr0_gt_798 = var_r7_793 > 0x400;
        var_r7_793 += 1;
        temp_r3_801 = temp_r3_797 >> 0x1FU;
        temp_r0_802 = (temp_r3_797 << 0x16) - temp_r3_801;
        var_r3_794 = ((temp_r0_802 << 0xA) | (temp_r0_802 >> 0x16U)) + temp_r3_801;
        if (temp_cr0_gt_798 == 0) {
            goto loop_3;
        }
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void MKSceneManager::PropResolver_Add(MKProp *arg0, const char *arg1) {
    s32 temp_r5_847;
    s32 temp_r6_829;
    s32 var_r8_837;
    u32 temp_r0_834;
    u32 temp_r0_843;
    u32 temp_r5_833;
    u32 temp_r5_840;
    u32 temp_r5_842;

    temp_r6_829 = this->unk14;
    if (temp_r6_829 >= 1) {
        temp_r5_833 = (u32) temp_r6_829 >> 0x1FU;
        temp_r0_834 = (temp_r6_829 << 0x16) - temp_r5_833;
        var_r8_837 = ((temp_r0_834 << 0xA) | (temp_r0_834 >> 0x16U)) + temp_r5_833;
loop_3:
        temp_r5_847 = var_r8_837 * 0x28;
        if ((s32) *(MKSceneManager::pPropMapping.__vptr + temp_r5_847) != -1) {
            temp_r5_840 = var_r8_837 + 1;
            temp_r5_842 = temp_r5_840 >> 0x1FU;
            temp_r0_843 = (temp_r5_840 << 0x16) - temp_r5_842;
            var_r8_837 = ((temp_r0_843 << 0xA) | (temp_r0_843 >> 0x16U)) + temp_r5_842;
            goto loop_3;
        }
        *(MKSceneManager::pPropMapping.__vptr + temp_r5_847) = temp_r6_829;
        M2C_FIELD((MKSceneManager::pPropMapping.__vptr + temp_r5_847), MKSceneManager **, 4) = this;
        if ((arg0 != NULL) && ((s8) *arg0 != 0)) {
            strcpy(MKSceneManager::pPropMapping.__vptr + (((s32) MKSceneManager::nmbrOfMappings.__vptr * 0x28) + 8), (s8 *) arg0);
        } else {
            strcpy(MKSceneManager::pPropMapping.__vptr + (((s32) MKSceneManager::nmbrOfMappings.__vptr * 0x28) + 8), *this->__vptr);
        }
        MKSceneManager::nmbrOfMappings.__vptr += 1;
    }
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void MKSceneManager::PropResolver_Init() {
    MKHeap *temp_r3_893;
    s32 var_ctr_914;
    s32 var_r4_910;
    s8 *var_r3_901;

    temp_r3_893 = MKHeap::Current();
    if (temp_r3_893 != NULL) {
        var_r3_901 = ((MKHeap *) (temp_r3_893->Current()))->Alloc(0xA000, NULL, 0);
    } else {
        var_r3_901 = malloc(0xA000);
    }
    var_r4_910 = 0;
    MKSceneManager::pPropMapping.__vptr = var_r3_901;
    MKSceneManager::nmbrOfMappings.__vptr = NULL;
    var_ctr_914 = 0x400;
    do {
        *(MKSceneManager::pPropMapping.__vptr + (var_r4_910 + 4)) = 0;
        *(MKSceneManager::pPropMapping.__vptr + var_r4_910) = -1;
        var_r4_910 += 0x28;
        var_ctr_914 -= 1;
    } while (var_ctr_914 != 0);
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void MKSceneManager::Deinit() {
    MKHeap *temp_r3_937;
    s8 **temp_r31_936;

    temp_r31_936 = this->unkC;
    temp_r3_937 = MKHeap::Current();
    if (temp_r3_937 != NULL) {
        ((MKHeap *) (temp_r3_937->Current()))->Free(temp_r31_936, NULL, 0);
        return;
    }
    free(temp_r31_936);
}
#endif

#if 0 // DRAFT: expression syntax error
void MKSceneManager::Init(MKSceneManagerInit *arg0) {
    MKHeap *temp_r3_1001;
    s8 *var_r3_1008;

    this->unk1C = arg0->unk30;
    this->unk24 = arg0->unk28;
    this->unk28 = arg0->unk2C;
    this->unk19 = 0;
    this->unk18 = 1;
    this->unk4 = arg0->unk20;
    this->unk8 = arg0->unk24;
    this->unkB0 = arg0->unk38;
    this->unkC0 = NULL;
    MKLevelChunk::pResolver.__vptr = (void *) arg0->unkD0;
    this->unk20 = 0;
loop_2:
    if ((u32) *(this->unk1C + (this->unk20 * 0xC)) != 0U) {
        this->unk20 += 1;
        goto loop_2;
    }
    temp_r3_1001 = ((MKHeap *) (qsort(0xC, ComparePropCreatorFunc)))->Current();
    if (temp_r3_1001 != NULL) {
        var_r3_1008 = ((MKHeap *) (temp_r3_1001->Current()))->Alloc(0x400, NULL, 0);
    } else {
        var_r3_1008 = malloc(0x400);
    }
    this->unkC = (s8 **) var_r3_1008;
    memset(this->unkC, 0, 0x400U);
    this->unk10 = 0;
    this->unk14 = 0;
}
#endif

#if 0 // DRAFT: function call 'stricmp(const void, const void)' does not match
void ComparePropCreatorFunc(const void *arg0, const void *arg1) {
    stricmp(*arg0, *arg1);
}
#endif
