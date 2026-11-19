void MKSceneManager::PropResolver_Add(MKProp *arg0, const char *arg1) {
    s32 temp_r5_847;
    s32 temp_r6_829;
    s32 var_r8_837;
    u32 temp_r0_834;
    u32 temp_r0_843;
    u32 temp_r5_833;
    u32 temp_r5_840;
    u32 temp_r5_842;
    s8 *table;

    temp_r6_829 = arg0->unk14;
    if (temp_r6_829 >= 1) {
        temp_r5_833 = (u32) temp_r6_829 >> 0x1FU;
        temp_r0_834 = (temp_r6_829 << 0x16) - temp_r5_833;
        var_r8_837 = ((temp_r0_834 << 0xA) | (temp_r0_834 >> 0x16U)) + temp_r5_833;
loop_3:
        temp_r5_847 = var_r8_837 * 0x28;
        if (*(s32 *) (*(s8 **) MKSceneManager::pPropMapping + temp_r5_847) != -1) {
            temp_r5_840 = var_r8_837 + 1;
            temp_r5_842 = temp_r5_840 >> 0x1FU;
            temp_r0_843 = (temp_r5_840 << 0x16) - temp_r5_842;
            var_r8_837 = ((temp_r0_843 << 0xA) | (temp_r0_843 >> 0x16U)) + temp_r5_842;
            goto loop_3;
        }
        table = *(s8 **) MKSceneManager::pPropMapping;
        *(s32 *) (table + temp_r5_847) = temp_r6_829;
        *(MKProp **) (table + temp_r5_847 + 4) = arg0;
        if ((arg1 != NULL) && ((s8) (u8) *arg1 != 0)) {
            strcpy((char *) (*(s8 **) MKSceneManager::pPropMapping + ((*(s32 *) MKSceneManager::nmbrOfMappings * 0x28) + 8)), arg1);
        } else {
            strcpy((char *) (*(s8 **) MKSceneManager::pPropMapping + ((*(s32 *) MKSceneManager::nmbrOfMappings * 0x28) + 8)), (const char *) ((MKPropDescriptor *) arg0->unk0)->unk0);
        }
        *(s32 *) MKSceneManager::nmbrOfMappings += 1;
    }
}
