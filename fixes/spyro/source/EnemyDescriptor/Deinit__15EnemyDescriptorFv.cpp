void EnemyDescriptor::Deinit() {
    CharacterBreathFXDescriptor *temp_r29_2578;
    EAPManagerDescriptor *temp_r3_2555;
    MKHeap *temp_r29_2562;
    MKHeap *temp_r29_2638;
    MKHeap *temp_r29_2668;
    s32 temp_r28_2692;
    s32 temp_r29_2594;
    s32 temp_r29_2652;
    s32 var_r27_2613;
    s32 var_r27_2688;
    s32 var_r30_2614;
    s32 var_r30_2689;
    void ***temp_r29_2618;

    temp_r3_2555 = this->unk230;
    if (temp_r3_2555 != NULL) {
        temp_r3_2555->Deinit();
        operator delete(this->unk230);
    }
    temp_r29_2562 = this->unk2AC;
    if (temp_r29_2562 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r29_2562, NULL, 0);
        } else {
            free((void ***) temp_r29_2562);
        }
    }
    temp_r29_2578 = this->unk258;
    if (temp_r29_2578 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r29_2578, NULL, 0);
        } else {
            free((void ***) temp_r29_2578);
        }
    }
    temp_r29_2594 = this->unk238;
    if ((u32) temp_r29_2594 != 0U) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free((void *) temp_r29_2594, NULL, 0);
        } else {
            free((void ***) temp_r29_2594);
        }
    }
    if ((MKHeap *) this->unk23C != NULL) {
        var_r27_2613 = 0;
        var_r30_2614 = 0;
loop_20:
        if (var_r27_2613 < (s32) this->unk234) {
            temp_r29_2618 = *(void ****) ((u8 *) this->unk23C + var_r30_2614);
            if (MKHeap::Current() != NULL) {
                ((MKHeap *) (MKHeap::Current()))->Free(temp_r29_2618, NULL, 0);
            } else {
                free(temp_r29_2618);
            }
            var_r27_2613 += 1;
            var_r30_2614 += 4;
            goto loop_20;
        }
        temp_r29_2638 = this->unk23C;
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r29_2638, NULL, 0);
        } else {
            free((void ***) temp_r29_2638);
        }
    }
    temp_r29_2652 = this->unk240;
    if ((u32) temp_r29_2652 != 0U) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free((void *) temp_r29_2652, NULL, 0);
        } else {
            free((void ***) temp_r29_2652);
        }
    }
    temp_r29_2668 = this->unk27C;
    if (temp_r29_2668 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r29_2668, NULL, 0);
        } else {
            free((void ***) temp_r29_2668);
        }
    }
    Deinit_Animation();
    Deinit_Attacks();
    var_r27_2688 = 0;
    var_r30_2689 = 0;
    do {
        temp_r28_2692 = var_r30_2689 + 0x29C;
        MKMaterial_Destroy(*(MKMaterial **) ((u8 *) this + temp_r28_2692));
        var_r27_2688 += 1;
        *(s32 *) ((u8 *) this + temp_r28_2692) = 0;
        var_r30_2689 += 4;
    } while (var_r27_2688 < 4);
    if ((u8) this->unk1D6 != 0) {
        EnemySettings_UnregisterSettings(&this->unk1D8);
    }
    MKPropDescriptor::Deinit();
}
