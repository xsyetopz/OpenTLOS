s32 CreateAudioDecodeThread(long arg0, unsigned char *arg1) {
    if (arg1 != NULL) {
        if (OSCreateThread(&AudioDecodeThread, (void *(*)(void *)) AudioDecoderForOnMemory, arg1, (u8 *) &AudioDecodeThread + 0x318 + 0x1000, 0x1000U, arg0, 1U) == 0) {
            return 0;
        }
        goto block_5;
    }
    if (OSCreateThread(&AudioDecodeThread, (void *(*)(void *)) AudioDecoder, NULL, (u8 *) &AudioDecodeThread + 0x318 + 0x1000, 0x1000U, arg0, 1U) == 0) {
        return 0;
    }
block_5:
    OSInitMessageQueue((OSMessageQueue *) ((u8 *) &AudioDecodeThread + 0x1318), (u8 *) &AudioDecodeThread + 0x1358, 3);
    OSInitMessageQueue((OSMessageQueue *) ((u8 *) &AudioDecodeThread + 0x1338), (u8 *) &AudioDecodeThread + 0x1364, 3);
    AudioDecodeThreadCreated = 1;
    return 1;
}
