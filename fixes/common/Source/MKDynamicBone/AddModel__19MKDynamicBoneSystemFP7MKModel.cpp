void MKDynamicBoneSystem::AddModel(MKModel *arg0) {
    Animation *temp_r3_anim;
    MKDynamicBone *temp_r30;
    u16 *elem;
    u16 *var_r29;
    void *temp_r3;
    s32 temp_r28;
    s32 var_ctr;
    s32 var_r20;
    s32 var_r21;
    s32 var_r22;
    s32 var_r23;
    s32 var_r24;
    s32 var_r27;
    s32 var_r5;

    var_r5 = 0;
    temp_r3 = M2C_FIELD(arg0->unk0, void **, 0x30);
    var_ctr = M2C_FIELD(temp_r3, s16 *, 0xC);
    var_r29 = NULL;
    if (var_ctr > 0) {
        do {
            elem = (u16 *) (M2C_FIELD(temp_r3, s32 *, 0x60) + var_r5);
            if (*elem == 7) {
                var_r29 = elem;
                break;
            }
            var_r5 += 0x10;
            var_ctr -= 1;
        } while (var_ctr != 0);
    }

    temp_r3_anim = MKModel_GetAnimation(arg0);
    if ((var_r29 != NULL) && (temp_r3_anim != NULL)) {
        temp_r3_anim->EnableCustomMatrices(1U);
        temp_r28 = M2C_FIELD(var_r29, s32 *, 4);
        var_r27 = 0;
        var_r24 = 0;
        while (var_r27 < M2C_FIELD(var_r29, s32 *, 8)) {
            this->unk0 -= 1;
            temp_r30 = *this->unk0;
            temp_r30->unk24 = arg0;
            temp_r30->unk20 = (Matrix *) (temp_r28 + var_r24);
            temp_r30->unk2C = MKDynamicBone::DefaultUpdater;
            M2C_FIELD(temp_r30, void **, 0x28) = NULL;
            temp_r30->unk30 = 1;
            if (temp_r30->unk20->unk3C != 1.0f) {
                var_r21 = 0;
                var_r23 = 0;
                do {
                    var_r20 = 0;
                    var_r22 = 0;
                    do {
                        FlipEndian((f32 *) ((s8 *) temp_r30->unk20 + (var_r23 + var_r22)));
                        var_r20 += 1;
                        var_r22 += 4;
                    } while (var_r20 < 4);
                    var_r21 += 1;
                    var_r23 += 0x10;
                } while (var_r21 < 4);
                FlipEndian((f32 *) ((s8 *) temp_r30->unk20 + 0x40));
                FlipEndian((f32 *) ((s8 *) temp_r30->unk20 + 0x44));
                FlipEndian((f32 *) ((s8 *) temp_r30->unk20 + 0x48));
                FlipEndian((f32 *) ((s8 *) temp_r30->unk20 + 0x4C));
                FlipEndian(&temp_r30->unk0);
                FlipEndian(&temp_r30->unk4);
                FlipEndian(&temp_r30->unk8);
                FlipEndian(&temp_r30->unkC);
                FlipEndian(&temp_r30->unk10);
                FlipEndian(&temp_r30->unk14);
                FlipEndian(&temp_r30->unk18);
                FlipEndian(&temp_r30->unk1C);
                FlipEndian((s16 *) ((s8 *) temp_r30->unk20 + 0x70));
                FlipEndian((f32 *) ((s8 *) temp_r30->unk20 + 0x74));
                FlipEndian((f32 *) ((s8 *) temp_r30->unk20 + 0x78));
                FlipEndian((f32 *) ((s8 *) temp_r30->unk20 + 0x7C));
                FlipEndian((u16 *) ((s8 *) temp_r30->unk20 + 0x72));
                FlipEndian((f32 *) ((s8 *) temp_r30->unk20 + 0x50));
                FlipEndian((f32 *) ((s8 *) temp_r30->unk20 + 0x54));
                FlipEndian((f32 *) ((s8 *) temp_r30->unk20 + 0x58));
                FlipEndian((f32 *) ((s8 *) temp_r30->unk20 + 0x5C));
                FlipEndian((f32 *) ((s8 *) temp_r30->unk20 + 0x60));
                FlipEndian((f32 *) ((s8 *) temp_r30->unk20 + 0x64));
                FlipEndian((f32 *) ((s8 *) temp_r30->unk20 + 0x68));
                FlipEndian((f32 *) ((s8 *) temp_r30->unk20 + 0x6C));
            }
            temp_r30->Reset();
            var_r27 += 1;
            var_r24 += 0x80;
        }
    }
}
