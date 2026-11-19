s32 EnemyDescriptor::LoadLine_Animation(MKIniLine *arg0, int arg1) {
    MKIniLine *var_r27_1209;
    s32 temp_r29_1185;
    s32 temp_r3_1173;
    s32 var_r26_1207;
    s32 var_r29_1208;
    void *temp_r28_1181;
    void *var_r3_1193;

    if (arg0->GetFieldName() != NULL) {
        temp_r3_1173 = DataMap_GetValue(&dataMapAnimSequence, (const char *) arg0->GetFieldName());
        if (temp_r3_1173 != 0) {
            temp_r28_1181 = (u8 *) this->unk1FC + ((arg1 * 0x98) + (temp_r3_1173 * 8));
            M2C_FIELD(temp_r28_1181, s32 *, 4) = arg0->GetNmbrOfSubLines();
            temp_r29_1185 = M2C_FIELD(temp_r28_1181, s32 *, 4) * 0x70;
            if (MKHeap::Current() != NULL) {
                var_r3_1193 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r29_1185, NULL, 0);
            } else {
                var_r3_1193 = (void *) (malloc(temp_r29_1185));
            }
            M2C_FIELD(temp_r28_1181, void **, 0) = var_r3_1193;
            memset(M2C_FIELD(temp_r28_1181, void **, 0), 0, (u32) temp_r29_1185);
            var_r26_1207 = 0;
            var_r29_1208 = 0;
            var_r27_1209 = arg0->unkC->GetSubLine(arg0);
            while ((var_r27_1209 != NULL) && (var_r26_1207 < (s32) M2C_FIELD(temp_r28_1181, s32 *, 4))) {
                ((AnimSequence *) ((u8 *) M2C_FIELD(temp_r28_1181, void **, 0) + var_r29_1208))->Init(temp_r3_1173);
                LoadLine_AnimSequence(var_r27_1209->unkC->GetSubLine(var_r27_1209), (AnimSequence *) ((u8 *) M2C_FIELD(temp_r28_1181, void **, 0) + var_r29_1208));
                var_r26_1207 += 1;
                var_r29_1208 += 0x70;
                var_r27_1209 = var_r27_1209->unkC->GetNextLine(var_r27_1209);
            }
            return 1;
        }
    }
    return 0;
}
