s32 Video_Update(Video *arg0) {
    s32 temp_r30_452;
    s32 temp_r3_387;

    if (arg0 == NULL) {
        return 0;
    }
    temp_r3_387 = THPPlayerGetState();
    switch (temp_r3_387) {
    case 4:
        Video_GetYUVData((void **) ((u8 *) M2C_FIELD(&currentVideo, u8 **, 0x30) + 0x3C), (void **) ((u8 *) M2C_FIELD(&currentVideo, u8 **, 0x30) + 0x40), (void **) ((u8 *) M2C_FIELD(&currentVideo, u8 **, 0x30) + 0x44));
        THPPlayerSetVolume(GetVideoVolume(), 0);
        return 1;
    case 0:
        if ((u8) M2C_FIELD(&currentVideo, u8 *, 0x34) != 0) {
            THPPlayerPrepare(0, 0, (s32) currentVideo.unk28);
            THPPlayerPlay();
            M2C_FIELD(&currentVideo, u8 *, 0x34) = 0U;
            return 1;
        }
        return 0;
    case 3:
        if ((u8) M2C_FIELD(&currentVideo, u8 *, 0x36) != 0) {
            THPPlayerStop();
            M2C_FIELD(&currentVideo, u8 *, 0x34) = 1U;
            return 1;
        }
        return 0;
    case 5:
        THPPlayerStop();
        THPPlayerClose();
        temp_r30_452 = currentVideo.unk4;
        if ((u32) temp_r30_452 != 0U) {
            if ((u8) M2C_FIELD(&currentVideo, u8 *, 0x24) != 0) {
                if (MKHeap::Current() != NULL) {
                    ((MKHeap *) (MKHeap::Current()))->Free((void *) temp_r30_452, NULL, 0);
                } else {
                    free((void *) temp_r30_452);
                }
            }
            currentVideo.unk4 = 0;
        }
        /* fallthrough */
    default:
        return 0;
    }
}
